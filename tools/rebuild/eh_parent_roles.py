"""Fixed-scope, read-only EH state/role observations; never select providers."""
from __future__ import annotations
import argparse
from collections import Counter
import hashlib
import json
from pathlib import Path
import struct
import sys

ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'tools'))
import build_and_match as oracle
from coff_inventory import Coff as InventoryCoff, reconcile_recipes
from eh_ownership import native_pieces, physical_parent, unit_hash

POLICY='two-parent-state-role-evidence-v1'
SCOPES=((802,'0x0043fd40','??0FUN_0043fd40@@QAE@HH@Z'),
        (2761,'0x00bd6570','??1FUN_00bd6570@@QAE@XZ'))
PINNED_V3='04d44b73e81982f846bfe8d81806db72ea669586b579ff22007dfd6f7d831297'
PINNED_MANIFEST='bc62a5fb2553431b1e0547d11f366e52efb73096ea8ceb206c556ae5740a53eb'
PINNED_RECIPE='62f2c8da5f0daa912abdf4576328706711c6561eef7f01c93a89cb71ad46fb6c'
PINNED_ORACLE='e4c5f0d8ef8546d1ff82f4f2092e5f65164495daa867c4ff25efd9e45a25d727'
TOOLS=('tools/rebuild/eh_parent_roles.py','tools/rebuild/eh_ownership.py',
       'tools/rebuild/coff_inventory.py','tools/rebuild/verify_objects.py',
       'tools/build_and_match.py','tools/compare.py','tools/function_spans.py')

def require(condition,message):
    if not condition:raise ValueError(message)

def sha(path):return hashlib.sha256(Path(path).read_bytes()).hexdigest()

def load_bound(path,expected):
    path=Path(path);require(path.stat().st_size<=64*1024*1024,'bounded JSON input exceeded')
    data=path.read_bytes();require(hashlib.sha256(data).hexdigest()==expected,'input fingerprint mismatch')
    return json.loads(data.decode('utf-8-sig'))

def u32(data,offset):
    require(0<=offset<=len(data)-4,'metadata field outside section')
    return struct.unpack_from('<I',data,offset)[0]

def signed(value):return value if value<0x80000000 else value-0x100000000

def compare_content(native,original,relocations):
    require(len(native)==len(original),'comparison extent differs')
    mask=set()
    for offset,_,kind in relocations:
        require(kind in (6,20) and 0<=offset<=len(native)-4,'unsupported bounded relocation')
        mask.update(range(offset,offset+4))
    differences=sum(a!=b for i,(a,b) in enumerate(zip(native,original)) if i not in mask)
    return dict(size=len(native),relocation_count=len(relocations),nonrelocation_differences=differences,
                nonrelocation_match=differences==0)

def frame_observation(piece,relocations):
    """Recognize only complete local tail-jump forms; no arbitrary byte search.

    This proves a cleanup's EBP slot/ECX adjustment, not the parent's saved-this
    provenance. Unknown shapes remain unknown, and no instruction bytes escape.
    """
    answer=dict(status='unknown-shape',parent_this_origin_verified=False,
                source_member_role_verified=False,frame_contract_verified=False)
    if len(piece) not in (8,11) or len(relocations)!=1:return answer
    offset,_,kind=relocations[0]
    if kind!=20 or offset!=len(piece)-4 or piece[:2]!=bytes((0x8b,0x4d)) or piece[-5]!=0xe9:return answer
    adjustment=0
    if len(piece)==11:
        if piece[3:5]!=bytes((0x83,0xc1)):return answer
        adjustment=struct.unpack_from('<b',piece,5)[0]
    answer.update(status='complete-local-ebp-to-ecx-tail-jump',
                  ebp_slot=struct.unpack_from('<b',piece,2)[0],ecx_adjustment=adjustment)
    return answer

def parse_states(coff,xdata_index,info_symbol,unwind_symbol,original,base,cleanup_pieces,parent):
    section=coff.sections[xdata_index];data=section['data'];at=info_symbol['value']
    require(at+36<=len(data),'incomplete FuncInfo')
    fields=struct.unpack_from('<9I',data,at)
    require(fields[0]==0x19930522 and 0<fields[1]<=64,'unsupported FuncInfo version/state bound')
    count=fields[1]
    require(fields[3:8]==(0,0,0,0,0),'try/IP/exception-spec tables outside fixed scope')
    require(fields[8]==1,'unsupported EH flags')
    start=unwind_symbol['value']
    require(start==0 and at==count*8 and at+36==len(data),'unmodeled metadata extent')
    expected={(at+8,unwind_symbol['name'],6)}
    transition_rows=[]
    for state in range(count):
        off=start+state*8;to=signed(u32(data,off));action=u32(data,off+4)
        require(-1<=to<state,'invalid/cyclic or missing unwind state transition')
        refs=[(o,coff.symbols[i],k) for o,i,k in section['relocs'] if o==off+4]
        require(len(refs)==1 and refs[0][2]==6 and action==0,'missing/unsupported state action')
        _,symbol,_=refs[0]
        matches=[p for p in cleanup_pieces if p['section']==symbol['section'] and p['native_start']==symbol['value']]
        require(len(matches)==1,'unwind action borrows foreign-parent cleanup')
        piece=matches[0]
        require(piece['parent']==parent,'cross-parent state action')
        expected.add((off+4,symbol['name'],6))
        observed_to=signed(u32(original,off));observed_action=u32(original,off+4)
        require(observed_action==piece['original_start'],'unwind action placement disagrees with receipt')
        transition_rows.append(dict(state=state,to_state=to,original_to_state=observed_to,
            transition_matches=to==observed_to,cleanup_symbol=symbol['name'],native_section=symbol['section'],
            native_offset=symbol['value'],original_cleanup=observed_action,
            original_pointer_field=dict(table_base=base,offset=off+4),
            role_id=parent+':state:'+str(state)+':cleanup:'+str(symbol['value']),
            source_member_role='unknown',source_member_role_verified=False))
    actual={(o,coff.symbols[i]['name'],k) for o,i,k in section['relocs']}
    require(len(actual)==len(section['relocs']) and len({o for o,_,_ in section['relocs']})==len(section['relocs']),
            'duplicate or overlapping metadata relocation')
    require(actual==expected,'missing or unmodeled metadata relocation/state')
    return dict(magic='VC9-EH3',state_count=count,flags=fields[8],try_block_count=0,
        funcinfo_offset=at,unwind_map_offset=start,transitions=transition_rows)

def trace_original(coff,pe,recipe,receipt,names,wanted_parent):
    """Observe the hash-pinned original producer; do not replace its verdicts."""
    require(sha(ROOT/'tools/build_and_match.py')==PINNED_ORACLE,'original producer changed')
    observations=[];context={}
    require(sys.gettrace() is None,'existing tracing session must not be overwritten')
    def trace(frame,event,arg):
        if frame.f_code is not oracle.eh_sections.__code__:return trace
        v=frame.f_locals
        if event=='line' and frame.f_lineno==166 and v.get('parent')==wanted_parent:
            target=v['target'];offset=v['offset'];kind=v['kind']
            require(kind in (6,20),'unreviewed code relocation')
            own=recipe.get('symbols',{}).get(target['name']);global_binding=names.get(target['name'])
            observations.append(dict(section=v['index'],piece_start=v['s0'],offset=offset,kind=kind,
                target_symbol=target['name'],target_section=target['section'],target_offset=target['value'],
                own_binding=None if own is None else int(own,0),global_binding=global_binding,
                original_destination=v['observed'],original_expected=v['expected'],
                original_relocation_match=v['expected'] is not None and v['expected']&0xffffffff==v['observed'],
                inferred_name_used=target['name'] in v['inferred'],provider_selected=False))
        elif event=='return':context.update(data_bases=dict(v.get('data_bases',{})))
        return trace
    sys.settrace(trace)
    try:pieces,inferred,errors=oracle.eh_sections(coff,pe,recipe,receipt['verified_functions'],names)
    finally:sys.settrace(None)
    require(pieces==receipt.get('eh_sections') and errors==receipt.get('eh_errors',[]) and
            {k:'0x%08x'%v for k,v in inferred.items()}==receipt.get('eh_inferred',{}),
            'original producer replay differs from pinned retained observations')
    return observations,context

def observe_parent(coff,inventory,pe,recipe,receipt,parent,symbol,names):
    proof=[f for f in receipt['verified_functions'] if f['address']==parent and f['symbol']==symbol and f['verdict']=='match']
    require(len(proof)==1,'exact same-object matched parent required')
    proof=proof[0];root=coff.named(symbol)
    require((root['section'],root['value'])==(proof['section'],proof['value']),'parent native identity changed')
    rows=[]
    for sn,a,b,p in native_pieces(coff,recipe,receipt):
        if p[3]!=parent:continue
        ownership=physical_parent(inventory,sn,receipt['verified_functions'])
        require(ownership['section']==root['section'] and ownership['exact_body_verified_same_object'],
                'stale association or cross-parent borrowing')
        rows.append(dict(section=sn,native_start=a,native_end=b,parent=parent,
            original_start=p[0],original_end=p[1],receipt_match=p[2],ownership=ownership))
    require(rows,'parent has no EH observations')
    xs={p['section'] for p in rows};require(len(xs)==1,'multiple EH code sections outside fixed scope')
    code_section=next(iter(xs))
    handler=coff.named('__ehhandler$'+symbol);info=coff.named('__ehfuncinfo$'+symbol);unwind=coff.named('__unwindtable$'+symbol)
    require(handler['section']==code_section and info['section']==unwind['section'],'foreign-parent local metadata')
    xdata=info['section'];association=physical_parent(inventory,xdata,receipt['verified_functions'])
    require(coff.sections[xdata]['name']=='.xdata$x' and association['section']==root['section'] and association['exact_body_verified_same_object'],
            'metadata association differs from parent')
    comparison_bindings=dict(recipe.get('symbols',{}))
    for function in recipe['functions']:
        for name in [function['symbol']]+function.get('fold_aliases',[]):comparison_bindings[name]=function['address']
    parent_spec=next(f for f in recipe['functions'] if f['address']==parent and f['symbol']==symbol)
    ordinary=oracle.compare(coff,pe,dict(symbols=comparison_bindings,functions=[parent_spec],literal_symbols=recipe.get('literal_symbols',[])),None)
    require(len(ordinary)==1 and ordinary[0]['verdict']=='match','fresh ordinary parent comparison failed')
    parent_comparison={k:ordinary[0][k] for k in ('address','symbol','size','compiled_extent','verdict','relocations')}
    parent_comparison['nonrelocation_differences']=len(ordinary[0]['byte_differences'])
    relocs,context=trace_original(coff,pe,recipe,receipt,names,parent)
    for p in rows:
        sn=p['section'];a,b=p['native_start'],p['native_end'];section=coff.sections[sn]
        rr=[(off-a,i,k) for off,i,k in section['relocs'] if a<=off<b]
        data=section['data'][a:b];original=pe.read(p['original_start'],b-a)
        p['comparison']=compare_content(data,original,rr)
        p['relocations']=[x for x in relocs if x['section']==sn and x['piece_start']==a]
        require(len(rr)==len(p['relocations']),'missing code relocation observation')
        p['local_symbols']=[s['name'] for s in coff.symbols.values() if s['section']==sn and s['value']==a and s['storage']==3 and s['type']&32]
        p['frame']=frame_observation(data,rr)
        p['all_local_comparisons_match']=p['comparison']['nonrelocation_match'] and all(x['original_relocation_match'] for x in p['relocations'])
        require(p['all_local_comparisons_match']==p['receipt_match'],'failed local piece silently changed verdict')
        p['runtime_eligible']=False
    require(xdata in context['data_bases'],'unlocated FuncInfo table')
    table_base=context['data_bases'][xdata];table=coff.sections[xdata];original=pe.read(table_base,len(table['data']))
    metadata_comparison=compare_content(table['data'],original,table['relocs'])
    metadata_comparison['original_base']=table_base
    metadata_comparison['association']=association
    cleanup=[p for p in rows if p['native_start']!=handler['value']]
    states=parse_states(coff,xdata,info,unwind,original,table_base,cleanup,parent)
    # Establish handler->FuncInfo and FuncInfo->unwind-map pointers independently.
    handler_piece=[p for p in rows if p['native_start']==handler['value']]
    require(len(handler_piece)==1,'handler piece missing')
    anchor=[r for r in handler_piece[0]['relocations'] if r['target_symbol']=='__ehfuncinfo$'+symbol]
    require(len(anchor)==1 and anchor[0]['original_destination']==table_base+info['value'],
            'handler/FuncInfo anchor conflict')
    require(u32(original,info['value']+8)==table_base+unwind['value'],'FuncInfo/unwind pointer conflict')
    metadata_relocations=[]
    for off,index,kind in table['relocs']:
        target=coff.symbols[index];addend=u32(table['data'],off)
        if target['section']==xdata:expected=table_base+target['value']+addend
        else:
            candidate=[p for p in rows if p['section']==target['section'] and p['native_start']==target['value']+addend]
            require(len(candidate)==1,'metadata target lacks exact local cleanup')
            expected=candidate[0]['original_start']
        observed=u32(original,off)
        metadata_relocations.append(dict(offset=off,target_symbol=target['name'],kind=kind,expected=expected,observed=observed,match=expected==observed))
    require({t['native_offset'] for t in states['transitions']}=={p['native_start'] for p in cleanup},'cleanup without complete state ownership')
    roles=[]
    for t in states['transitions']:
        p=next(p for p in cleanup if p['native_start']==t['native_offset'])
        actions=[x for x in p['relocations'] if x['kind']==20]
        require(len(actions)==1,'cleanup has unmodeled action references')
        roles.append(dict(t,action=actions[0],frame=p['frame'],piece_match=p['receipt_match'],runtime_eligible=False))
    result=dict(parent=parent,symbol=symbol,parent_proof=proof,parent_comparison=parent_comparison,handler=dict(section=handler['section'],offset=handler['value'],original=handler_piece[0]['original_start']),
        funcinfo=dict(section=xdata,offset=info['value'],original=table_base+info['value']),
        metadata=metadata_comparison,metadata_relocations=metadata_relocations,state_machine=states,
        pieces=rows,roles=roles,source_role_status='unknown-member-role; local ECX adjustment is not parent saved-this proof',
        runtime_eligible=False,provider_selected=False,frame_contract_verified=False)
    validate_roles(result)
    return result

def validate_roles(component):
    require(component.get('runtime_eligible') is False and component.get('provider_selected') is False and component.get('frame_contract_verified') is False,'analysis cannot adopt provider/frame contract')
    transitions=component['state_machine']['transitions'];roles=component['roles'];count=component['state_machine']['state_count']
    require(len(transitions)==count and {t['state'] for t in transitions}==set(range(count)),'missing state transitions')
    require(len(roles)==count and len({r['role_id'] for r in roles})==count,'merged distinct roles')
    require({r['role_id'] for r in roles}=={t['role_id'] for t in transitions},'state/role identities differ')
    for role in roles:
        transition=next(t for t in transitions if t['role_id']==role['role_id'])
        require(all(role[k]==transition[k] for k in transition),'state/role evidence merged or changed')
        require(role['runtime_eligible'] is False and role['source_member_role_verified'] is False,'unproved role promoted')
        match=[p for p in component['pieces'] if p['native_start']==role['native_offset'] and p['section']==role['native_section']]
        require(len(match)==1 and match[0]['parent']==component['parent'],'cross-parent role borrowing')
        piece=match[0]
        computed=piece['comparison']['nonrelocation_match'] and all(x['original_relocation_match'] for x in piece['relocations'])
        require(role['piece_match']==piece['receipt_match']==piece['all_local_comparisons_match']==computed,'failed piece silently accepted')
        actions=[x for x in piece['relocations'] if x['kind']==20]
        require(len(actions)==1 and role['action']==actions[0] and role['original_cleanup']==piece['original_start'],'role action merged or changed')

def check_stability(observations,index,index_present,index_sha256):
    require(index.is_file()==index_present,'optional index presence changed during observation')
    if index_present:require(sha(index)==index_sha256,'optional index changed during observation')
    require(all(sha(p)==h for p,h in observations.items()),'input changed during observation')


def observe(manifest_path,retained_path,recipes_path,image_path,out,*,root=ROOT):
    root=Path(root).resolve();out=Path(out).resolve()
    paths=[Path(x).resolve() for x in (manifest_path,retained_path,recipes_path,image_path)]
    require(len(set(paths))==4 and out not in paths and not out.exists(),'new distinct output required')
    manifest=load_bound(paths[0],PINNED_MANIFEST);receipt=load_bound(paths[1],PINNED_V3);recipes=load_bound(paths[2],PINNED_RECIPE)
    require(receipt.get('kind')=='fnv-retained-object-verification' and receipt.get('scope',{}).get('full_authoritative') is True and
            all(receipt.get(k) is True for k in ('retained_verification_pass','function_byte_verification_pass','global_listed_eh_coverage_pass','original_oracle_parity_pass','evidence_stable')),'retained gates missing')
    require(receipt['inputs']['retained_manifest_sha256']==PINNED_MANIFEST and receipt['inputs']['recipe_sha256']==PINNED_RECIPE,'receipt identities disagree')
    require(reconcile_recipes(manifest,paths[2])['verified'],'authoritative recipe reconciliation failed')
    observations={p:sha(p) for p in paths}
    require(observations[paths[3]]==receipt['inputs']['image_sha256'],'reference image fingerprint differs')
    for name,digest in receipt['inputs']['tools_sha256'].items():
        producer=(root/name).resolve()
        require(producer.is_relative_to(root) and sha(producer)==digest,'pinned producer changed')
        observations[producer]=digest
    index=root/'build/function_index.json'
    require(index.is_file()==receipt['inputs']['function_index_present'],'optional index presence changed')
    if index.is_file():require(sha(index)==receipt['inputs']['function_index_sha256'],'optional index changed');observations[index]=sha(index)
    tool_hashes={name:sha(root/name) for name in TOOLS}
    observations.update({root/name:digest for name,digest in tool_hashes.items()})
    pe=oracle.Pe(paths[3]);require(hashlib.sha256(pe.data).hexdigest()==receipt['inputs']['image_sha256'] and oracle.image_ok(pe)[0],'loaded image/gate differs')
    names=oracle.recipe_names(recipes['units']);results=[]
    base=paths[0].parent/manifest.get('object_root_relative','.')
    for unit_index,parent,symbol in SCOPES:
        uu=[u for u in manifest['units'] if u['recipe_index']==unit_index];rr=[r for r in receipt['units'] if r['recipe_index']==unit_index]
        require(len(uu)==len(rr)==1,'fixed unit absent or duplicate')
        unit,row=uu[0],rr[0]
        require(row['recipe_id']==unit['recipe_id'] and row['recipe_unit_sha256']==unit_hash(unit['recipe']) and row['object_sha256']==unit['object_sha256'] and
                row['source_sha256_current']==row['source_sha256_recorded']==unit['source_sha256'] and row['status']=='ok','fixed unit proof differs')
        obj=(base/unit['object']).resolve();source=(root/unit['source']).resolve()
        require(source.is_relative_to(root) and out not in (obj,source),'unsafe source/output identity')
        require(sha(obj)==unit['object_sha256'] and sha(source)==unit['source_sha256'],'fixed object/source changed')
        observations[obj]=unit['object_sha256'];observations[source]=unit['source_sha256']
        coff=oracle.Coff(obj);inventory=InventoryCoff(obj)
        require(hashlib.sha256(coff.data).hexdigest()==hashlib.sha256(inventory.data).hexdigest()==unit['object_sha256'],'loaded object changed')
        result=observe_parent(coff,inventory,pe,unit['recipe'],row,parent,symbol,names)
        required_name='??1SubObjB@@QAE@XZ' if unit_index==802 else '??1ObjectReference@@QAE@XZ'
        scoped_roles=[role for role in result['roles'] if role['action']['target_symbol']==required_name]
        require(len(scoped_roles)==(2 if unit_index==802 else 3),'fixed helper-role scope changed')
        destinations={role['action']['original_destination'] for role in scoped_roles}
        require(len(destinations)==2,'distinct original helper roles were merged')
        result['required_distinct_helper_roles']=dict(symbol=required_name,role_ids=[role['role_id'] for role in scoped_roles],
            original_destinations=sorted(destinations),unification_allowed=False)
        source_text=source.read_text(encoding='utf-8')
        declarations=('SubObjB m_30;','SubObjB m_34;') if unit_index==802 else ('ObjectReference owner;','ObjectReference other;','ObjectReference additional;')
        declared=[]
        for declaration in declarations:
            matches=[i for i,line in enumerate(source_text.splitlines(),1) if line.strip()==declaration]
            require(len(matches)==1,'source member declaration not uniquely observed')
            declared.append(dict(declaration=declaration,line=matches[0],native_member_role_verified=False))
        result['source_declaration_observations']=declared
        result.update(recipe_id=unit['recipe_id'],recipe_index=unit_index,source=unit['source'],source_sha256=unit['source_sha256'],object_sha256=unit['object_sha256'])
        results.append(result)
    check_stability(observations,index,receipt['inputs']['function_index_present'],receipt['inputs']['function_index_sha256'])
    report=dict(schema_version=1,kind='fnv-two-parent-eh-role-observations',policy=POLICY,status='analysis-only',runtime_eligible=False,provider_selected=False,
        inputs=dict(manifest_sha256=PINNED_MANIFEST,retained_sha256=PINNED_V3,recipe_sha256=PINNED_RECIPE,image_sha256=receipt['inputs']['image_sha256'],tools_sha256=tool_hashes),
        mapping_basis='hash-pinned original producer replay plus structural oracle section-cut order; trusted receipt ordering required',
        components=results,summary=dict(parents=len(results),roles=sum(len(c['roles']) for c in results),failed_roles=sum(not r['piece_match'] for c in results for r in c['roles'])))
    out.parent.mkdir(parents=True,exist_ok=True)
    created=False
    try:
        with out.open('x',encoding='utf-8') as stream:
            created=True;json.dump(report,stream,indent=2);stream.write('\n')
    except BaseException:
        if created:out.unlink(missing_ok=True)
        raise
    return report

if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    for name in ('manifest','retained','recipes','image','out'):parser.add_argument('--'+name,type=Path,required=True)
    args=parser.parse_args();report=observe(args.manifest,args.retained,args.recipes,args.image,args.out)
    print(json.dumps(dict(status=report['status'],summary=report['summary'])))
