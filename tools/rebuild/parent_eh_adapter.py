"""Per-parent VC9 no-catch EH graphs; pure, bounded, no native execution."""
from __future__ import annotations
from collections import defaultdict,deque
import copy
import hashlib
import json
import re
from pathlib import Path
import struct
import sys
import tempfile
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'tools'))
import build_and_match as oracle
import coff_code_archive as coff
import root_code_closure as ordinary
from eh_ownership import native_pieces
from eh_code_closure import section_aux,digest
from runtime_code_inventory import public_metadata
from runtime_bind_plan import CRT_SYMBOLS
import parent_eh_omission as readonly_omission

POLICY='parent-owned-no-catch-EH3-v1'
ORDINARY_SHA='4bfdb5001380a3d7e5db7517033285d49ab211be68e2fcba15964f0ad5b03c53'
ORACLE_SHA='e4c5f0d8ef8546d1ff82f4f2092e5f65164495daa867c4ff25efd9e45a25d727'
FALSE=dict(runtime_eligible=False,provider_selected=False,ABI_verified=False,link_ready=False,namespace_approved=False,frame_contract_verified=False,source_member_layout_verified=False)
CRT={'___CxxFrameHandler3':'cxx-frame-handler','@__security_check_cookie@4':'security-cookie-check'}

class Blocked(ValueError):
    def __init__(self,code,evidence=None):self.code=code;self.evidence=evidence;super().__init__(code)
def guard(ok,code,evidence=None):
    if not ok:raise Blocked(code,evidence)
def sha(data):return hashlib.sha256(data).hexdigest()
def u32(data,at):return struct.unpack_from('<I',data,at)[0]
def i32(data,at):return struct.unpack_from('<i',data,at)[0]

class BoundedReference:
    def __init__(self,reference):self.reference=reference;self.bytes=0;self.calls=0
    def read(self,address,size):
        guard(type(address)is int and type(size)is int and 0<=address<=0xffffffff and 0<=size<=65536 and address+size<=0x100000000,'INVALID_REFERENCE_READ_BOUND')
        self.bytes+=size;self.calls+=1;guard(self.bytes<=1048576 and self.calls<=8192,'PARENT_REFERENCE_BUDGET_EXCEEDED')
        return self.reference.read(address,size)
    def __getattr__(self,name):return getattr(self.reference,name)


def owned_point(pieces,section,offset):
    found=[p for p in pieces if p['section']==section and p['start']<=offset<p['end']]
    guard(len(found)==1,'UNMAPPED_OR_AMBIGUOUS_LOCAL_CODE_POINT',dict(section=section,offset=offset))
    p=found[0];return p['original_start']+offset-p['start'],p

def compare_span(native,original,relocs,highlow,original_base):
    guard(len(native)==len(original),'INCOMPLETE_REFERENCE_SPAN');mask=set()
    for offset,index,kind in relocs:
        guard(kind in (6,20) and 0<=offset<=len(native)-4,'UNSUPPORTED_OR_STRADDLING_RUNTIME_FIELD')
        bits=set(range(offset,offset+4));guard(not mask&bits,'OVERLAPPING_RUNTIME_FIELDS');mask|=bits
    guard(all(a==b for n,(a,b) in enumerate(zip(native,original)) if n not in mask),'NONFIELD_MISMATCH')
    expected=[original_base+offset for offset,_,kind in relocs if kind==6]
    actual=[site for site in highlow if site<original_base+len(native) and site+4>original_base]
    guard(sorted(actual)==sorted(expected),'ASYMMETRIC_ORIGINAL_HIGHLOW',dict(expected=expected,observed=actual))

def infer_role(symbol,base,classification,executable_ranges,*,generated=False):
    executable=any(begin<=base<end for begin,end in executable_ranges)
    name=symbol['name'];typ=symbol['type']
    if name in CRT:
        guard((symbol['section'],symbol['value'],symbol['storage'],symbol['aux_count'])==(0,0,2,0),'NONCANONICAL_CRT_FUNCTION_RECORD',name)
        guard(typ==32 and executable,'WRONG_CRT_FUNCTION_DOMAIN',name)
        return dict(role='crt-contract',semantic_domain='code',contract_kind=CRT[name])
    if name=='___security_cookie':
        guard((symbol['section'],symbol['value'],symbol['storage'],symbol['aux_count'])==(0,0,2,0),'NONCANONICAL_COOKIE_DATA_RECORD')
        guard(typ==0 and not executable,'WRONG_COOKIE_DATA_DOMAIN')
        return dict(role='data',semantic_domain='data',contract_kind='security-cookie')
    if classification=='EXPLICIT_NORMAL_CRT_CONTRACT_CANDIDATE':
        guard(name in CRT_SYMBOLS and (symbol['section'],symbol['value'],typ,symbol['storage'],symbol['aux_count'])==(0,0,32,2,0) and executable,'UNKNOWN_OR_NONCANONICAL_PARENT_CRT')
        return dict(role='crt-contract',semantic_domain='code',contract_kind='crt-function:'+name)
    if generated:
        guard(typ==32 and executable,'UNCLASSIFIED_GENERATED_TARGET',name)
        return dict(role='code',semantic_domain='code',contract_kind='function')
    if classification in ('SELECTED_CODE_ENTRY','UNSELECTED_EXECUTABLE_TARGET_UNCLASSIFIED'):
        guard(typ==32 and executable,'CODE_FIELD_DOMAIN_CONFLICT')
        return dict(role='code',semantic_domain='code',contract_kind='function')
    if classification in ('ORIGINAL_IMAGE_DATA_REQUIRES_CANONICAL_OWNER','COMPILER_LITERAL_FULL_READONLY_NONPOINTER_EQUALITY'):
        guard(typ==0 and not executable,'DATA_FIELD_DOMAIN_CONFLICT')
        return dict(role='data',semantic_domain='data',contract_kind='vtable-view' if name.startswith('??_7') else 'opaque-data-view')
    guard(False,'UNSUPPORTED_EXTERNAL_ROLE_CLASS',dict(symbol=name,classification=classification))

def _observe(raw,contract,recipe,unit_proof,recipes,reference,original_highlow_sites,executable_ranges):
    guard(sha(Path(ordinary.__file__).read_bytes())==ORDINARY_SHA and sha(Path(oracle.__file__).read_bytes())==ORACLE_SHA,'FROZEN_PRODUCER_DRIFT')
    guard(len(raw)<=64*1024*1024 and len(recipes)<=10000 and len(original_highlow_sites)<=1000000,'INPUT_SCOPE_BUDGET_EXCEEDED')
    reference=BoundedReference(reference)
    guard(len(contract['roots'])==1,'SINGLE_PARENT_SCOPE_REQUIRED');root=contract['roots'][0];parent=root['original_address'];symbol=root['symbol'];provenance=contract['provenance']
    guard(sha(raw)==provenance['object_sha256']==unit_proof['object_sha256'],'STALE_NATIVE_OBJECT')
    guard(unit_proof.get('status')=='ok' and provenance.get('recipe_id')==contract['recipe_id'] and provenance.get('recipe_index')==unit_proof['recipe_index'],'STALE_UNIT_PROOF_IDENTITY')
    expected_parent={k:root[k] for k in ('symbol','size','section','value')};expected_parent.update(address=parent,verdict='match')
    parents=[f for f in unit_proof['verified_functions'] if f.get('symbol')==symbol and f.get('address')==parent]
    guard(len(parents)==1 and parents[0]==expected_parent and contract['unit_verified_functions']==unit_proof['verified_functions'],'MISSING_OR_CHANGED_VERIFIED_PARENT')
    diagnostics=unit_proof.get('eh_errors',[]);guard(isinstance(diagnostics,list),'MALFORMED_EH_DIAGNOSTICS')
    for diagnostic in diagnostics:
        match=re.match(r'^(0x[0-9a-f]{8}):',diagnostic) if isinstance(diagnostic,str) else None
        guard(match is not None and match.group(1)!=parent and match.group(1) in {f['address'] for f in recipe['functions']} and match.group(1) in {f['address'] for f in unit_proof['verified_functions']},'SELECTED_FOREIGN_OR_UNSCOPED_EH_DIAGNOSTIC',diagnostic)
    guard(contract['recipe_id']==unit_proof['recipe_id'] and digest(recipe)==unit_proof['recipe_unit_sha256'],'STALE_RECIPE_PROOF')
    guard(unit_proof['source_sha256_recorded']==unit_proof['source_sha256_current']==provenance['source_sha256'],'STALE_SOURCE_PROOF')
    guard(all(contract.get(key)is True for key in ('verified_match','fields_complete','missing_fields_complete','unit_proofs_complete')) and contract['missing_fields']==[],'INCOMPLETE_OR_MISSING_PARENT_FIELDS')
    original_pieces=contract['parent_eh'];guard(original_pieces,'MISSING_MATCHED_EH_PIECE_PROOF')
    guard(all(p[2]is True and p[3]==parent for p in original_pieces),'FAILED_OR_FOREIGN_EH_PIECE',original_pieces)
    obj=coff.parse(raw);sections=obj['sections'];symbols=obj['symbols'];guard(sum(s['size'] for s in sections.values())<=256*1024*1024,'DECLARED_ORACLE_SECTION_BUDGET_EXCEEDED');r= symbols.get(root['symbol_index']);ps=root['section']
    guard(r and (r['name'],r['section'],r['value'],r['type'],r['storage'],r['aux_count'])==(symbol,ps,0,32,2,0) and root['value']==0,'STALE_PARENT_PHYSICAL')
    guard(0<root['size']<=65536,'PARENT_CODE_BUDGET_EXCEEDED')
    guard(sections[ps]['size']==root['size'] and sections[ps]['name']=='.text' and sections[ps]['flags']==0x60501020,'PARTIAL_SHARED_OR_UNKNOWN_PARENT')
    _,parent_aux=section_aux(obj,ps);guard(parent_aux[4:6]==(0,1),'UNSUPPORTED_PARENT_COMDAT')
    def named(name):
        rows=[(i,s) for i,s in symbols.items() if s['name']==name and s['section']>0];guard(len(rows)==1,'MISSING_OR_SHARED_PARENT_LOCAL',name);return rows[0]
    handler_index,handler=named('__ehhandler$'+symbol);info_index,info=named('__ehfuncinfo$'+symbol);unwind_index,unwind=named('__unwindtable$'+symbol)
    xs,ds=handler['section'],info['section'];guard(xs!=ps and ds not in (ps,xs) and unwind['section']==ds,'FOREIGN_PARENT_METADATA')
    guard(sections[xs]['name']=='.text$x' and sections[xs]['flags']==0x60501020 and sections[ds]['name']=='.xdata$x' and sections[ds]['flags']==0x40301040,'UNKNOWN_EH_SECTION_FAMILY')
    guard(0<sections[xs]['size']<=65536 and 0<sections[ds]['size']<=548,'EH_SECTION_BUDGET_EXCEEDED')
    for sn in (ps,xs,ds):
        guard(len(sections[sn]['relocs'])<=4096 and all(kind in (6,20) and 0<=offset<=sections[sn]['size']-4 for offset,_,kind in sections[sn]['relocs']),'UNKNOWN_OR_UNBOUNDED_RUNTIME_FIELDS')
    for sn in (xs,ds):
        _,aux=section_aux(obj,sn);guard(aux[4:6]==(ps,5),'FOREIGN_OR_REPARENTED_EH_CHILD')
    guard(all(s['storage']==3 and s['aux_count']==0 and s['type']==typ for s,typ in ((handler,32),(info,0),(unwind,0))),'BAD_HANDLER_METADATA_RECORD')
    for i,s in symbols.items():
        if s['section'] in (ps,xs,ds):
            is_section=s['name']==sections[s['section']]['name'] and s['value']==0 and s['type']==0 and s['storage']==3 and s['aux_count']==1
            if is_section or i==root['symbol_index']:continue
            guard(s['storage']==3 and not s['aux_count'] and s['type'] in (0,32),'SHARED_OR_UNKNOWN_RETAINED_RECORD',i)
            if s['section']==xs:guard(s['type']==32 and (i==handler_index or s['name'].startswith('__unwindfunclet$'+symbol+'$')),'CATCH_OR_FOREIGN_FUNCLET',i)
            elif s['section']==ds:guard(i in (info_index,unwind_index),'UNKNOWN_METADATA_MEMBER',i)
            else:guard(s['type']==0,'SHARED_PARENT_CODE_ENTRY',i)
    with tempfile.TemporaryDirectory(prefix='no-catch-source-core-') as temporary:
        path=Path(temporary)/'native.obj';path.write_bytes(raw);core=oracle.Coff(path)
        mapped=list(native_pieces(core,recipe,unit_proof));pieces=[dict(section=sn,start=a,end=b,original_start=p[0],original_end=p[1],receipt=p) for sn,a,b,p in mapped if p[3]==parent]
        guard([p['receipt'] for p in pieces]==original_pieces and all(p['section']==xs for p in pieces),'INCOMPLETE_NATIVE_PIECE_MAP')
        guard(pieces[0]['start']==0 and pieces[-1]['end']==sections[xs]['size'] and all(a['end']==b['start'] for a,b in zip(pieces,pieces[1:])),'UNCLAIMED_EH_CODE_BYTES')
        intervals=sorted((p['original_start'],p['original_end']) for p in pieces);guard(all(a[1]<=b[0] for a,b in zip(intervals,intervals[1:])),'OVERLAPPING_OR_ICF_ORIGINAL_PIECES')
        for begin,end in [(int(parent,16),int(parent,16)+root['size'])]+intervals:
            guard(any(lo<=begin and end<=hi for lo,hi in executable_ranges),'NONEXECUTABLE_OR_STRADDLING_CODE_SPAN')
        h=[p for p in pieces if p['start']==handler['value']];guard(len(h)==1,'HANDLER_NOT_COMPLETE_PIECE');h=h[0]
        comparison_symbols=dict(recipe.get('symbols',{}));comparison_symbols.update(unit_proof.get('eh_inferred',{}))
        for f in recipe['functions']:
            for name in [f['symbol']]+f.get('fold_aliases',[]):comparison_symbols[name]=f['address']
        parent_spec=[f for f in recipe['functions'] if f['symbol']==symbol and f['address']==parent];guard(len(parent_spec)==1,'PARENT_RECIPE_MISSING')
        comparison=dict(functions=parent_spec,symbols=comparison_symbols,literal_symbols=recipe.get('literal_symbols',[]));ordinary_rows=oracle.compare(core,reference,comparison,None)
        guard(len(ordinary_rows)==1 and ordinary_rows[0]['verdict']=='match' and ordinary_rows[0]['compiled_extent']==root['size'],'UNCHANGED_PARENT_CORE_FAILED')
        names=oracle.recipe_names(recipes);eh_rows,inferred,errors=oracle.eh_sections(core,reference,comparison,ordinary_rows,names)
        guard(not errors and [p[:4] for p in eh_rows]==[p[:4] for p in original_pieces] and all(p[2]is True for p in eh_rows),'UNCHANGED_EH_CORE_FAILED')
    data=sections[ds]['payload'];at=info['value'];guard(at+36<=len(data),'TRUNCATED_FUNCINFO');values=struct.unpack_from('<9I',data,at);count=values[1]
    guard(values[0]==0x19930522 and 0<count<=64 and values[3:8]==(0,0,0,0,0) and values[8]==1,'CATCH_IP_SPEC_OR_UNKNOWN_FUNCINFO',dict(fields=list(values)))
    unwind_at=unwind['value'];descriptor_ranges=sorted([(at,at+36),(unwind_at,unwind_at+8*count)])
    guard(descriptor_ranges[0][0]==0 and descriptor_ranges[0][1]==descriptor_ranges[1][0] and descriptor_ranges[1][1]==len(data),'UNKNOWN_WHOLE_STATE_EXTENT')
    code=sections[xs];handler_refs=[row for row in code['relocs'] if h['start']<=row[0]<h['end']]
    info_refs=[row for row in handler_refs if row[1]==info_index and row[2]==6];crt_refs=[row for row in handler_refs if symbols[row[1]]['name']=='___CxxFrameHandler3' and row[2]==20]
    guard(len(info_refs)==len(crt_refs)==1,'MISSING_OR_UNKNOWN_HANDLER_ANCHORS');io=info_refs[0][0];co=crt_refs[0][0]
    guard(io>h['start'] and co==io+5 and co+4==h['end'] and code['payload'][io-1]==0xb8 and code['payload'][co-1]==0xe9,'UNKNOWN_HANDLER_TAIL_FORM')
    for off,index,kind in handler_refs:
        if index==info_index or symbols[index]['name']=='___CxxFrameHandler3':continue
        guard(symbols[index]['name']=='@__security_check_cookie@4' and kind==20 and off>h['start'] and code['payload'][off-1]==0xe8,'UNKNOWN_HANDLER_EXTRA_FIELD')
    original_info_field=h['original_start']+io-h['start'];metadata_base=(u32(reference.read(original_info_field,4),0)-u32(code['payload'],io)-info['value'])&0xffffffff
    guard(not any(lo<metadata_base+len(data) and hi>metadata_base for lo,hi in executable_ranges),'EXECUTABLE_OR_STRADDLING_METADATA')
    original_data=reference.read(metadata_base,len(data));locations={ps:int(parent,16),ds:metadata_base}
    expected_state_fields=[(at+8,unwind_index,6)];states=[];used_cleanup=set()
    for state in range(count):
        offset=unwind_at+8*state;to=i32(data,offset);action=u32(data,offset+4);refs=[r for r in sections[ds]['relocs'] if r[0]==offset+4]
        guard(-1<=to<state and i32(original_data,offset)==to,'INVALID_OR_CHANGED_STATE_TRANSITION')
        if refs:
            guard(len(refs)==1 and refs[0][2]==6,'UNKNOWN_STATE_ACTION_FIELD');_,index,kind=refs[0];target=symbols[index]
            guard(target['section']==xs and target['storage']==3 and target['type']==32 and target['aux_count']==0 and index!=handler_index,'FOREIGN_STATE_CLEANUP')
            original_target,piece=owned_point(pieces,xs,target['value']+action);guard(piece['start']==target['value']+action and piece is not h,'STATE_POINTS_INTO_FUNCLET')
            guard(u32(original_data,offset+4)==original_target,'CHANGED_ORIGINAL_STATE_ACTION');used_cleanup.add(piece['start']);expected_state_fields.append(refs[0]);cleanup=index
        else:guard(action==u32(original_data,offset+4)==0,'MISSING_STATE_ACTION_RELOCATION');cleanup=None
        states.append(dict(state=state,to_state=to,cleanup_index=cleanup,role_id=parent+':state:'+str(state),source_member_role_verified=False))
    guard(sorted(sections[ds]['relocs'])==sorted(expected_state_fields),'EXTRA_MISSING_OR_DUPLICATE_STATE_FIELD')
    guard(used_cleanup=={p['start'] for p in pieces if p is not h},'UNOWNED_EXTRA_FUNCLET')
    spans=[dict(section=ps,start=0,end=root['size'],original_start=int(parent,16),original_end=int(parent,16)+root['size'])]+pieces
    field_map={};parent_actual=[]
    for row in contract['fields']:
        cr=row['coff_relocation'];key=(row['physical_section'],cr['offset'],cr['symbol_index'],cr['kind']);guard(key not in field_map,'DUPLICATE_PARENT_BINDING');field_map[key]=row
    externals={};fields=[];comparisons=[];bindings=dict(names);bindings.update({k:int(v,0) for k,v in comparison_symbols.items()});bindings.update(inferred)
    def point(section,offset):
        if section==ds:return metadata_base+offset,None
        return owned_point(spans,section,offset)
    all_spans=spans+[dict(section=ds,start=0,end=len(data),original_start=metadata_base,original_end=metadata_base+len(data))]
    for span in all_spans:
        sn=span['section'];a,b=span['start'],span['end'];native=sections[sn]['payload'][a:b];original=reference.read(span['original_start'],b-a)
        relocs=[(off-a,index,kind) for off,index,kind in sections[sn]['relocs'] if a<=off<b]
        compare_span(native,original,relocs,original_highlow_sites,span['original_start']);comparisons.append(dict(section=sn,start=a,end=b,original_start=span['original_start'],nonfield_differences=0,payload_sha256=sha(native)))
        for local,index,kind in relocs:
            off=a+local;target=symbols[index];addend=i32(native,local) if kind==20 else u32(native,local);observed=(span['original_start']+local+4+i32(original,local))&0xffffffff if kind==20 else u32(original,local)
            key=(sn,off,index,kind);row=field_map.get(key)
            if sn==ps:
                parent_actual.append(key);guard(row is not None and row['proof_consistency']=='EXACT_OWN_SOURCE_RESOLUTION' and row['physical_field_overlap_count']==1,'MISSING_PARENT_FINAL_BINDING')
                cr=row['coff_relocation'];guard((cr['symbol'],cr['symbol_section'],cr['symbol_value'],cr['symbol_type'],cr['symbol_storage'],cr['addend'])==(target['name'],target['section'],target['value'],target['type'],target['storage'],u32(native,local)),'CHANGED_PARENT_SOURCE_FIELD')
                guard(row['function_va']==parent and row['source_field_offset']==off and row['physical_offset']==off and row['recipe_id']==contract['recipe_id'],'FOREIGN_PARENT_BINDING')
            if target['section'] in (ps,xs,ds):
                base,piece=point(target['section'],target['value']);destination,_=point(target['section'],target['value']+addend)
                guard(destination==(base+addend)&0xffffffff,'CROSS_PIECE_LOCAL_ADDEND')
            else:
                guard(target['storage'] in (2,3) and not target['aux_count'] and not(target['section']==0 and target['value']),'WEAK_COMMON_OR_OPAQUE_EXTERNAL')
                if row:base=int(row['derived_source_symbol_base_va'],16)
                else:
                    guard(target['name'] in bindings,'UNRESOLVED_GENERATED_SYMBOL',target['name']);base=bindings[target['name']]
                destination=(base+addend)&0xffffffff
                if row is None and target['type']==0 and target['name']!='___security_cookie':
                    # A generated field may share an independently authenticated parent DATA identity.
                    # This establishes the same physical symbol/base/domain, never its storage/lifetime.
                    witness=externals.get(index)
                    guard(kind==6 and witness is not None and witness['proof_consistency']=='EXACT_OWN_SOURCE_RESOLUTION' and witness['base']==base and witness['role']=='data' and witness['semantic_domain']=='data','MISSING_GENERATED_DATA_PARENT_WITNESS',target['name'])
                    role={k:witness[k] for k in ('role','semantic_domain','contract_kind')}
                else:role=infer_role(target,base,None if row is None else row['classification'],executable_ranges,generated=row is None)
                label='EXACT_OWN_SOURCE_RESOLUTION' if row else 'EXACT_GENERATED_EH_FIELD_RESOLUTION'
                identity=dict(symbol_index=index,base=base,symbol=target['name'],proof_consistency=label,**role)
                if index in externals:guard(all(externals[index][k]==identity[k] for k in ('base','role','semantic_domain','contract_kind')),'CONFLICTING_PHYSICAL_EXTERNAL_IDENTITY')
                else:externals[index]=identity
            guard(destination==observed,'ORIGINAL_FIELD_TARGET_MISMATCH')
            if row:guard(int(row['exact_original_target_va'],16)==observed and int(row['derived_source_symbol_base_va'],16)==base,'PARENT_BINDING_DESTINATION_MISMATCH')
            field=dict(section=sn,offset=off,target_index=index,kind=kind,addend=addend,original_field_va=span['original_start']+local,original_base=base,original_target=observed,proof_family='PARENT_FINAL_BINDING' if row else 'PARENT_OWNED_GENERATED_EH_FIELD')
            if row is None and target['section'] not in (ps,xs,ds) and target['type']==0 and target['name']!='___security_cookie':
                field['generated_data_identity_basis']=dict(kind='SAME_PHYSICAL_PARENT_DATA_IDENTITY',parent_field_sha256=[digest(f) for f in contract['fields'] if f['coff_relocation']['symbol_index']==index],original_storage_adopted=False,type_extent_verified=False)
            fields.append(field)
    guard(set(field_map)==set(parent_actual),'EXTRA_OR_MISSING_PARENT_FIELD_PROOF')
    # Shared physical addresses cannot acquire inconsistent domains or subtypes.
    by_base={}
    for external in externals.values():
        identity=tuple(external[k] for k in ('role','semantic_domain','contract_kind'));guard(by_base.setdefault(external['base'],identity)==identity,'CONFLICTING_SHARED_BASE_IDENTITY')
    semantic=dict(parent=root,pieces=pieces,handler_index=handler_index,info_index=info_index,unwind_index=unwind_index,code_section=xs,state_section=ds,metadata_original_base=metadata_base,metadata_descriptors=dict(funcinfo=[at,at+36],unwind=[unwind_at,unwind_at+8*count]),states=states,fields=fields,external_obligations=list(externals.values()),comparisons=comparisons,original_core=dict(ordinary=[{k:row[k] for k in ('address','symbol','size','compiled_extent','verdict')} for row in ordinary_rows],eh_sections=eh_rows,eh_errors=errors,baseline_pieces=original_pieces,baseline_inferred=unit_proof.get('eh_inferred',{}),unit_diagnostics_preserved=diagnostics,strict_unit_local_diagnostics_pass=not diagnostics),reference_reads=dict(calls=reference.calls,bytes=reference.bytes),object_sha256=sha(raw),contract_sha256=digest(contract))
    result=expanded_omissions(obj,contract,semantic)
    # A separate typed adapter replays the frozen ordinary witness and expands
    # its physical protection roots. Its exact discharges never edit that base.
    base=ordinary.assess_object(obj,contract)
    witness=readonly_omission.observe(raw,contract,base,result)
    result['expanded_readonly_omission']=witness
    for occurrence in witness['discharge_occurrences']:
        blocker=base['blockers'][occurrence['ordinal']]
        guard(blocker['blocker_id']==occurrence['blocker_id'] and digest(blocker)==occurrence['blocker_sha256'],'READONLY_OMISSION_OCCURRENCE_DRIFT')
        guard(result['blockers'].count(blocker)==1,'READONLY_OMISSION_NOT_EXACT_REMAINING_BLOCKER')
        result['blockers'].remove(blocker)
    result['structural_projection_candidate']=not result['blockers']
    result['status']='candidate' if not result['blockers'] else 'blocked-ordinary-obligations'
    return result


def expanded_omissions(obj,contract,semantic):
    """Recompute retained dependencies; never reuse smaller-scope omissions."""
    root=semantic['parent'];ps=root['section'];xs=semantic['code_section'];ds=semantic['state_section'];handler=semantic['handler_index'];sec=obj['sections'];sym=obj['symbols'];runtime={ps,xs,ds}
    model=ordinary.assess_object(obj,contract);directives=[i for i,s in sec.items() if s['name']=='.drectve'];guard(len(directives)==1,'DIRECTIVE_SECTION_SCOPE');sx=[i for i,s in sec.items() if s['name']=='.sxdata'];guard(len(sx)==1,'MISSING_OR_MULTIPLE_SAFESEH_TABLE');sx=sx[0]
    guard(sec[sx]['flags']==0x300200 and not sec[sx]['relocs'] and sec[sx]['size']==len(sec[sx]['payload']) and 0<sec[sx]['size']<=4096*4 and sec[sx]['size']%4==0,'UNKNOWN_SAFESEH_TABLE')
    keep=runtime|{sx,directives[0]};required={i for i,s in sym.items() if s['section'] in keep or s['name'] in ('@comp.id','@feat.00')};conversions=[]
    for field in semantic['fields']:required.add(field['target_index'])
    for external in semantic['external_obligations']:
        i=external['symbol_index']
        if sym[i]['section']>0 and sym[i]['section'] not in keep:conversions.append(i)
    registrations=[];seen=set()
    for offset in range(0,sec[sx]['size'],4):
        index=u32(sec[sx]['payload'],offset);target=sym.get(index)
        guard(target is not None and index not in seen and target['section']>0 and target['type']==32 and not target['aux_count'] and 0<=target['value']<sec[target['section']]['size'],'INVALID_OR_DUPLICATE_SAFESEH_RECORD');seen.add(index)
        registrations.append(dict(section=sx,offset=offset,symbol_index=index,target_section=target['section'],target_value=target['value'],retain=index==handler))
    guard(sum(r['retain'] for r in registrations)==1,'UNREGISTERED_OR_DUPLICATE_RETAINED_HANDLER')
    names=defaultdict(list);weak={};children=[]
    for i,s in sym.items():
        section_symbol=s['section']>0 and s['name']==sec[s['section']]['name'] and s['storage']==3 and s['type']==0 and s['value']==0
        if not section_symbol and s['storage']!=103 and (s['storage'] in (2,105) or s['type']==32):names[s['name']].append(i)
        if s['storage']==105 and s['aux_count']==1:weak[i]=struct.unpack_from('<I',s['aux'])[0]
        if section_symbol and s['aux_count']==1:
            _,a=section_aux(obj,s['section'])
            if a[5]==5:children.append((s['section'],a[4]))
    for child,parent in children:guard(not(parent in keep and child not in keep),'UNKNOWN_RETAINED_ASSOCIATIVE_CHILD',dict(child=child,parent=parent))
    edges=[copy.deepcopy(e) for e in model['edges'] if e['kind'] not in ('RETAINED_RELOCATION','LIVE_NAME_RESOLUTION','LIVE_WEAK_FALLBACK')]
    live=set(required);queue=deque(sorted(live))
    for edge in edges:
        if edge['kind']=='DIRECTIVE_NAME_RESOLUTION':live.update(edge['target']['symbol_indices']);queue.extend(edge['target']['symbol_indices'])
    for field in semantic['fields']:edges.append(dict(kind='EXPANDED_RUNTIME_FIELD',source=[field['section'],field['offset'],field['kind']],target=field['target_index']))
    while queue:
        i=queue.popleft();guard(i in sym,'UNKNOWN_LIVE_PRIMARY');adjacent=list(names.get(sym[i]['name'],[]))
        if i in weak:adjacent.append(weak[i])
        for j in adjacent:
            edges.append(dict(kind='EXPANDED_NAME_OR_WEAK',source=i,target=j))
            if j not in live:live.add(j);queue.append(j)
    for i in live:
        guard(sym[i]['storage']!=105 and not(sym[i]['section']==0 and sym[i]['value']),'LIVE_WEAK_OR_COMMON')
        guard(i in required,'UNPROVED_EXPANDED_NAME_ALIAS',i)
    for registration in registrations:
        if not registration['retain']:guard(registration['target_section'] not in runtime and registration['symbol_index'] not in live,'OMITTED_SAFESEH_HANDLER_IS_LIVE')
    parent_fields={(row['physical_section'],row['coff_relocation']['offset'],row['coff_relocation']['symbol_index'],row['coff_relocation']['kind']):row for row in contract['fields']}
    explained=[];fatal=[]
    for blocker in model['blockers']:
        code=blocker['code'];e=blocker['evidence']
        scoped=(code=='RETAINED_PARENT_EH_OR_UNKNOWN_CHILD' and e in ({'parent':ps,'child':xs},{'parent':ps,'child':ds}))
        scoped|=code=='SPECIAL_RUNTIME_REFERENCE' and isinstance(e,list) and len(e)==4 and e[0]==ps and sym[e[2]]['section'] in (xs,ds) and tuple(e) in parent_fields and parent_fields[tuple(e)]['classification']=='COMPILER_LOCAL_EH_METADATA_OR_HELPER_CANDIDATE'
        scoped|=code=='SPECIAL_OMITTED_TARGET_CONVERSION' and type(e)is int and sym[e]['section'] in runtime
        scoped|=code=='PARENT_EH_REQUIRES_CLOSURE_ADAPTER' and e==contract['parent_eh']
        scoped|=code=='LIVE_SAFESEH_HANDLER_REQUIRES_ADAPTER' and isinstance(e,dict) and any(all(e.get(k)==r[k] for k in ('section','offset','symbol_index','target_section','target_value')) and r['retain'] for r in registrations)
        (explained if scoped else fatal).append(copy.deepcopy(blocker))
    slots=sorted(j for i in required for j in range(i,i+1+sym[i]['aux_count']))
    return dict(schema_version=1,policy_id=POLICY,status='candidate' if not fatal else 'blocked-ordinary-obligations',structural_projection_candidate=not fatal,semantic_graph_verified=True,semantic=semantic,retained_sections=sorted(keep),retained_primary_indices=sorted(required),retained_physical_slots=slots,undefined_conversions=sorted(conversions),safeseh_records=registrations,edges=edges,edges_sha256=digest(edges),ordinary_observation_sha256=digest(model),ordinary_result_unchanged=True,explained_exact_EH_obligations=explained,blockers=fatal,omission_approved=False,**FALSE)


def observe_parent(raw,contract,recipe,unit_proof,recipes,reference,original_highlow_sites,executable_ranges):
    try:return _observe(raw,contract,recipe,unit_proof,recipes,reference,original_highlow_sites,executable_ranges)
    except Blocked as error:return dict(schema_version=1,policy_id=POLICY,status='blocked',structural_projection_candidate=False,semantic_graph_verified=False,blockers=[dict(code=error.code,evidence=public_metadata(error.evidence))],**FALSE)
    except (ValueError,KeyError,IndexError,TypeError,struct.error) as error:return dict(schema_version=1,policy_id=POLICY,status='blocked',structural_projection_candidate=False,semantic_graph_verified=False,blockers=[dict(code='UNSUPPORTED_OR_INCOMPLETE_EH_INPUT',evidence=dict(error_type=type(error).__name__))],**FALSE)
