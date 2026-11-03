"""Metadata-only section-arena, view and provider-obligation ledger.

Never emits original bytes, materializes storage, links or approves providers.
"""
from __future__ import annotations
import argparse
from collections import Counter,defaultdict
import gzip
import hashlib
import json
import os
import re
from pathlib import Path
import struct
import tempfile
import time
from import_plan import ROOT,require,unit_digest
from data_plan import Pe,file_hash
from runtime_gaps import read_bound
from relocation_audit import Intervals,validate_headers,verified_functions,selected_for_unit
from coff_inventory import Coff

DATA_PIN='127644b75ed0c2826a3c1d89e4718076f4617b5a0d1f949b5faa4d61f54e6e93'
BIND_PIN='275714631903758efbf5a4f82e2428c6f51838f53b90d0c56d2e5dec5da1d804'
COLUMNS=['site_rva','target_rva','target_class','target_offset','width','backing','blockers']
LEAD=0x011dee84
LEAD_FIELDS={(0x4dc5c0,113),(0x4dc560,4),(0x4dc560,23),(0x5bac60,4),(0xfa2380,6),(0xfd8e10,4)}
HEADER='include/original_global_object_initializers.h'
HEADER_PIN='c6584d01fe7cc11a2f929a8e7943fb70a1298587fd09f72dbb2c0220087fe361'
FALSE=dict(runtime_eligible=False,provider_selected=False,materialization_approved=False)


def canonical(value):return json.dumps(value,sort_keys=True,separators=(',',':'),ensure_ascii=True).encode('ascii')
def digest(value):return hashlib.sha256(canonical(value)).hexdigest()
def va(value):return '0x%08x'%value


def arenas_from_plan(plan):
    require(plan.get('kind')=='fnv-private-data-analysis' and plan.get('schema_version')==1 and
            plan.get('runtime_ready') is False and plan['fixups']['approved_semantic_fixups']==0,'data plan state/schema differs')
    base=plan['image']['base'];result=[]
    hashes={s['name']:s['sha256'] for s in plan['provenance']['nonexec_sections']}
    for s in plan['selected_sections']:
        start=base+s['rva'];end=start+s['extent'];raw=min(s['raw_size'],s['extent'])
        require(s['extent']>0 and end<=0x100000000 and not s['executable'] and not s['flags']&0x20000020,'invalid arena storage geometry')
        require(s['zero_fill']==s['extent']-raw and s['raw_padding']==max(0,s['raw_size']-s['extent']),'raw/zero/padding geometry conflict')
        result.append(dict(arena_id='section-'+str(s['index']),section=s['name'],original_start=start,original_end=end,
            logical_extent=s['extent'],raw_backed_extent=raw,virtual_zero_extent=s['zero_fill'],raw_padding_excluded=s['raw_padding'],
            raw_section_sha256=hashes[s['name']],flags=s['flags'],writable=bool(s['flags']&0x80000000),
            domain='STATIC_TLS_SECTION_NOT_ORDINARY' if s['name']=='.tls' else 'ORDINARY_ARENA_GEOMETRY_CANDIDATE',
            object_extent=None,object_type=None,alignment_approval=None,**FALSE))
    ordered=sorted(result,key=lambda a:a['original_start'])
    require(all(a['original_end']<=b['original_start'] for a,b in zip(ordered,ordered[1:])),'overlapping arena envelopes')
    return result


def partition_domains(arenas,ranges):
    """Disjoint coverage including ordinary gaps; competing evidence stays explicit."""
    index=Intervals([(r['start'],r['end'],r) for r in ranges])
    result=[]
    for a in arenas:
        cuts={a['original_start'],a['original_end'],a['original_start']+a['raw_backed_extent']}
        for r in index.overlap(a['original_start'],a['original_end']):
            cuts.add(max(a['original_start'],r['start']));cuts.add(min(a['original_end'],r['end']))
        points=sorted(cuts)
        for lo,hi in zip(points,points[1:]):
            if lo==hi:continue
            evidence=index.overlap(lo,hi);families={r['family'] for r in evidence}
            special={f for f in families if f!='SOURCE_PROJECTION_CANDIDATE'}
            result.append(dict(domain_id=digest([a['arena_id'],lo,hi,sorted(r['range_id'] for r in evidence)]),arena_id=a['arena_id'],start=lo,end=hi,arena_offset=lo-a['original_start'],
                backing='raw' if hi<=a['original_start']+a['raw_backed_extent'] else 'virtual-zero',
                evidence_ids=sorted(r['range_id'] for r in evidence),families=sorted(families) or ['ORDINARY_UNCLASSIFIED'],
                unresolved_domain_overlap=len({r['range_id'] for r in evidence})>1,
                source_projection_alternatives_unselected=sum(r['family']=='SOURCE_PROJECTION_CANDIDATE' for r in evidence),**FALSE))
    return result


def external_domains(arenas,ranges):
    cuts=sorted({v for r in ranges for v in (r['start'],r['end'])}|{v for a in arenas for v in (a['original_start'],a['original_end'])})
    index=Intervals([(r['start'],r['end'],r) for r in ranges]);result=[]
    for lo,hi in zip(cuts,cuts[1:]):
        if any(lo<a['original_end'] and hi>a['original_start'] for a in arenas):continue
        hits=index.overlap(lo,hi)
        if not hits:continue
        families={r['family'] for r in hits}
        result.append(dict(domain_id=digest([None,lo,hi,sorted(r['range_id'] for r in hits)]),arena_id=None,start=lo,end=hi,families=sorted(families),evidence_ids=sorted(r['range_id'] for r in hits),
            unresolved_domain_overlap=len({r['range_id'] for r in hits})>1,**FALSE))
    return result


def domain_references(segments):
    return [{k:p[k] for k in ('domain_id','arena_id','start','end','families','unresolved_domain_overlap') if k in p} for p in segments]


def view_at(address,arenas,domains,code_index=None):
    owners=[a for a in arenas if a['original_start']<=address<a['original_end']]
    require(len(owners)<=1,'ambiguous arena geometry')
    result=dict(original_address=va(address),object_extent=None,object_type=None,interior_object_offset=None,**FALSE)
    if owners:
        a=owners[0];segments=domains.overlap(address,address+1)
        result.update(arena_id=a['arena_id'],arena_offset=address-a['original_start'],domain_evidence=domain_references(segments),
                      ownership_obligation='CANONICAL_ARENA_OR_SOURCE_OWNER_NOT_SELECTED')
    else:result.update(arena_id=None,arena_offset=None,domain_evidence=domain_references(domains.overlap(address,address+1)),ownership_obligation='EXTERNAL_CODE_RUNTIME_OR_UNOWNED_TARGET')
    candidates=code_index.overlap(address,address+1) if code_index else []
    result['code_provider_candidates']=[dict(provider_id=p['provider_id'],offset=address-p['original_start'],
        callable_or_frame_ABI_approved=False) for p in candidates]
    result['code_ownership_ambiguous']=len(candidates)>1
    return result


def data_field(values,arenas,domains,base,code_index=None):
    require(isinstance(values,list) and len(values)==len(COLUMNS),'malformed original data row')
    row=dict(zip(COLUMNS,values));site=base+row['site_rva'];target=base+row['target_rva']
    require(row['width']==4 and 0<=site<=0xfffffffc and 0<=target<=0xffffffff and isinstance(row['blockers'],list),'invalid original field identity')
    containers=[a for a in arenas if a['original_start']<=site and site+4<=a['original_end']]
    require(len(containers)==1,'data field outside exact arena or straddles envelope')
    a=containers[0];source_domains=domains.overlap(site,site+4)
    raw_end=a['original_start']+a['raw_backed_extent']
    require(not site<raw_end<site+4,'data field crosses raw/zero boundary')
    require(row['backing']==('raw' if site+4<=raw_end else 'virtual-zero-fill'),'original field backing conflicts')
    return dict(event='DATA_HIGHLOW_FIELD',site_identity=digest(values),original_record=values,
        original_site_va=va(site),original_target_va=va(target),original_symbol_base_identity=None,original_symbol_addend=None,
        representation='PE_HIGHLOW_OPAQUE_BASE_ADJUSTED_32BIT_ADDRESS_NOT_CPP_TYPE',
        source_arena=a['arena_id'],source_offset=site-a['original_start'],source_domains=domain_references(source_domains),
        crosses_domain_boundaries=len(source_domains)>1,target_view=view_at(target,arenas,domains,code_index),
        semantic_field_type_proved=False,canonical_owner_selected=False,**FALSE)


def special_ranges(pe,imports):
    ranges=[]
    def add(name,start,end,family,evidence):
        require(0<=start<end<=0x100000000,'invalid special range')
        ranges.append(dict(range_id=name,start=start,end=end,family=family,evidence=evidence,**FALSE))
    for i,(rva,size) in enumerate(pe.directories):
        if rva and i!=4:add('PE-directory-'+str(i),pe.base+rva,pe.base+rva+size,'LOADER_METADATA',dict(directory_index=i))
    for item in imports['imports']:
        start=int(item['original_IAT_va'],16)
        add('IAT-cell-'+str(item['import_id']),start,start+4,'FRESH_IAT_CELL',dict(dll=item['dll'],export=item['export']))
    for s in pe.sections:
        if s['name'] in ('.tls','.rsrc','.reloc'):
            add('special-section-'+s['name'],pe.base+s['rva'],pe.base+s['rva']+s['extent'],
                'STATIC_TLS' if s['name']=='.tls' else 'RESOURCE_FORMAT' if s['name']=='.rsrc' else 'REGENERATED_RELOCATION_METADATA',dict(section=s['name']))
    trva,tsize=pe.directories[9]
    if trva:
        require(tsize==24,'unexpected TLS directory size')
        start,end,index,callbacks,zero,flags=struct.unpack('<6I',pe.read_rva(trva,24))
        add('loader-static-TLS-index',index,index+4,'FRESH_STATIC_TLS_INDEX',dict(template_start=va(start),template_end=va(end),loader_zero_fill=zero,callbacks=va(callbacks)))
    add('Havok-dynamic-TLS-slot-observed-view',0x126835c,0x1268360,'FRESH_DYNAMIC_TLS_SLOT',dict(source='TLS-OWNER-PROPOSAL',object_extent=None,view_width=4))
    add('CRT-cookie-observed-cell',0x11c16bc,0x11c16c0,'FRESH_NORMAL_CRT_STATE',dict(source='CRT-INTEGRATION-PROPOSAL',extent_scope='one observed cell; complement/other state unresolved'))
    return ranges


def binding_stream(path,plan,manifest,selection,emit,required_missing=88):
    events=Counter();classes=Counter();kinds=Counter();consistency=Counter();keys=set();groups={};literals={};missing=[];lead=[];root_edges=[]
    rows_digest=hashlib.sha256()
    with gzip.open(path,'rt',encoding='utf-8') as stream:
        for ordinal,line in enumerate(stream,1):
            require(ordinal<=1000000 and len(line)<=262144,'binding stream bound exceeded')
            e=json.loads(line);events[e['event']]+=1;classes[e['classification']]+=1;rows_digest.update(canonical([ordinal,digest(e)]))
            u=manifest['units'][e['recipe_index']]
            require(e['recipe_id']==u['recipe_id'],'stale binding recipe join')
            choice=selection['selections'].get(e['function_va'])
            width=4 if e['coff_relocation'] is None else e['coff_relocation']['conservative_extent']
            require(choice and choice['recipe_id']==u['recipe_id'] and choice['symbol']==e['function_symbol'] and
                choice['section']==e['physical_section'] and choice['value']+e['source_field_offset']==e['physical_offset'] and
                0<=e['source_field_offset']<=choice['size']-width and
                e['original_field_va']==va(int(e['function_va'],16)+e['source_field_offset']),'stale selected physical field join')
            if e['event']=='MISSING_ORIGINAL_HIGHLOW_SOURCE_MIGRATION_BLOCKER':
                key=(e['recipe_id'],e['function_va'],e['physical_section'],e['physical_offset'],e['original_field_va'])
                require(key not in keys,'duplicate missing-field identity');keys.add(key);missing.append(e)
                emit(dict(event='MISSING_FIELD_BLOCKER',binding_row_ordinal=ordinal,binding_row_sha256=digest(e),source_observation=e,**FALSE));continue
            require(e['event']=='SELECTED_FUNCTION_COFF_RELOCATION','unknown binding event')
            key=(e['recipe_id'],e['function_va'],e['physical_section'],e['physical_offset'],e['coff_relocation']['symbol_index'],e['coff_relocation']['kind'])
            require(key not in keys,'duplicate exact code field');keys.add(key)
            kinds[str(e['coff_relocation']['kind'])]+=1;consistency[e['proof_consistency']]+=1
            target=e.get('exact_original_target_va');groupkey=target or 'special:'+e['classification']
            if groupkey not in groups:groups[groupkey]=dict(target=target,ordinals=[],row_digest=hashlib.sha256(),classes=Counter())
            g=groups[groupkey];g['ordinals'].append(ordinal);g['row_digest'].update(canonical([ordinal,digest(e)]));g['classes'][e['classification']]+=1
            if int(e['function_va'],16) in (0x633c90,0xfa2380,0xfd8e10):root_edges.append(e)
            if target and (int(target,16) in range(LEAD,LEAD+4) or e.get('derived_source_symbol_base_va')==va(LEAD)):lead.append(e)
            if 'literal' in e and e['classification']=='COMPILER_LITERAL_FULL_READONLY_NONPOINTER_EQUALITY':
                lit=e['literal'];r=e['coff_relocation'];require(lit['full_extent_equal'] and lit['source_and_original_readonly'] and lit['no_source_relocations_or_original_HIGHLOW'],'unproved literal projection')
                ident=dict(recipe_id=u['recipe_id'],object_sha256=u['object_sha256'],symbol_index=r['symbol_index'],original_start=lit['original_literal_start'],extent=lit['extent'])
                identid=digest(ident)
                candidate=dict(range_id='source-literal-'+identid,start=int(lit['original_literal_start'],16),end=int(lit['original_literal_start'],16)+lit['extent'],
                    family='SOURCE_PROJECTION_CANDIDATE',evidence=dict(provider_identity=ident,source_sha256=u['source_sha256'],payload_sha256=lit['payload_sha256'],projection_kind=lit['kind']),**FALSE)
                require(identid not in literals or literals[identid]==candidate,'conflicting physical literal projection')
                literals[identid]=candidate
    require(dict(events)==plan['summary']['events'] and dict(classes)==plan['summary']['target_classes'] and
            dict(kinds)==plan['summary']['relocation_kinds'] and dict(consistency)==plan['summary']['proof_consistency'],'complete binding stream counts disagree')
    require(len(missing)==plan['summary']['exact_baseline_missing_field_identities']==required_missing,'original missing field set/count differs')
    require(sum(len(g['ordinals']) for g in groups.values())==events['SELECTED_FUNCTION_COFF_RELOCATION'],'code rows lost from target groups')
    return groups,list(literals.values()),dict(storage_rows=lead,root_edges=root_edges),dict(events= dict(events),row_sequence_sha256=rows_digest.hexdigest(),records=sum(events.values()))


ROOT_EDGE_CONTRACT={(0x633c90,29,20,0x40f6e0),(0xfa2380,6,6,LEAD),(0xfa2380,11,20,0x633c90),
    (0xfa2380,16,6,0xfd8e10),(0xfa2380,21,20,0xec658f),(0xfd8e10,4,6,LEAD),(0xfd8e10,9,20,0x45cec0)}
LEAD_SOURCE_CONTRACTS=(
 ('src/generated/global_object_initializers.cpp','GlobalObject_00633c90 g_011dee84(0);','null-argument generated declaration'),
 ('src/fallout/misc/main.cpp','g_011dee84 = reinterpret_cast<NiNode*>(new SceneGraph("Menu", true, 0));','real menu SceneGraph assignment'),
 ('src/fallout/ai/actor.cpp','m_p->FUN_0040f6e0();','conditional constructor callee remains open'),
 ('src/fallout/ai/movement/actormover.cpp','((SeqObj*)*(void**)this)->FUN_00401970();','non-null cleanup callee remains open'))


def source_statement(relative,raw,expected_hash,needle,role):
    require(hashlib.sha256(raw).hexdigest()==expected_hash,'wrong lifecycle source hash')
    lines=raw.decode('utf-8-sig').splitlines();hits=[i+1 for i,line in enumerate(lines) if line.strip()==needle]
    require(hits,'actual lifecycle source statement missing/comment-only')
    return dict(source=relative,source_sha256=expected_hash,line_numbers=hits,statement_sha256=hashlib.sha256(needle.encode()).hexdigest(),
                observed_role=role,extent_or_lifetime_proof=False)


def lead_source_evidence(root,source_hashes):
    result=[]
    for relative,needle,role in LEAD_SOURCE_CONTRACTS:
        path=(root/relative).resolve()
        require(path in source_hashes,'lifecycle source outside proof')
        result.append(source_statement(relative,path.read_bytes(),source_hashes[path],needle,role))
    return result


def lead_lifecycle(lead,coff,source,header,source_observations):
    rows=lead['storage_rows'];edges=lead['root_edges']
    observed={(int(e['function_va'],16),e['source_field_offset'],e['coff_relocation']['kind'],int(e['exact_original_target_va'],16)) for e in edges}
    require(len(edges)==7 and observed==ROOT_EDGE_CONTRACT,'actual seven lifecycle field-edge contract changed')
    require(len(source_observations)==4 and all(e['extent_or_lifetime_proof'] is False for e in source_observations),'lifecycle source observations missing')
    require({(int(e['function_va'],16),e['source_field_offset']) for e in rows}==LEAD_FIELDS and len(rows)==6,'lead six-field identities changed')
    require(all(e['exact_original_target_va']==va(LEAD) and e['coff_relocation']['addend']==0 for e in rows),'lead target/addend changed')
    require(re.search(r'(?m)^GlobalObject_00633c90 g_011dee84\(0\);$',source) and
        re.search(r'class GlobalObject_00633c90\s*\{[^}]*char storage\[4\];[^}]*\};',header),'lead source/placeholder observation changed')
    name='?g_011dee84@@3VGlobalObject_00633c90@@A';found=[s for s in coff.symbols.values() if s['name']==name]
    require(len(found)==1,'lead storage symbol missing')
    s=found[0];require((s['index'],s['section'],s['value'])==(27506,6424,120) and coff.sections[6424]['size']==13460,'lead shared BSS identity changed')
    init=next(s for s in coff.symbols.values() if s['name']=='??__Eg_011dee84@@YAXXZ')
    slots=[(sec['index'],off,k) for sec in coff.sections.values() for off,i,k in sec['relocs'] if i==init['index']]
    require(slots==[(6425,11828,6)] and coff.sections[6425]['name']=='.CRT$XCU','lead CRT slot changed')
    return dict(event='STARTUP_LIFECYCLE_OBLIGATION',original_address=va(LEAD),object_extent=None,object_type=None,
        generated_placeholder_bytes_observed=4,placeholder_is_extent_proof=False,source_reference_count=6,selected_functions=5,
        root_field_edges=edges,root_field_edge_count=7,source_observations=source_observations,
        evidence_scope='Pinned selected-field observations and current hash-bound source statements; not ABI/lifetime proof',
        generated_storage=dict(symbol_index=s['index'],section=s['section'],value=s['value'],shared_section_extent=13460),
        initializer=dict(address='0x00fa2380',size=30,section=3115),cleanup=dict(address='0x00fd8e10',size=15,section=6170),
        CRT_slot=dict(section=6425,offset=11828,kind=6),
        blockers=['arena/view extent and alias decision','real SceneGraph mutation/allocation ownership','non-null destruction/0x00401970 closure',
                  'constructor/0x0040f6e0 machine ABI','fresh CRT atexit ordering and paired cleanup','duplicate generated BSS suppression'],**FALSE)

def run(args):
    started=time.monotonic();root=Path(args.root).resolve()
    names=('data_plan','binding','recipes','manifest','retained','selection','imports','reference')
    paths={n:Path(getattr(args,n)).resolve() for n in names};hashes={n:getattr(args,n+'_sha256') for n in names}
    require(hashes['data_plan']==DATA_PIN and hashes['binding']==BIND_PIN,'supported exact data/binding plans required')
    data={n:read_bound(paths[n],hashes[n]) for n in names if n!='reference'}
    dp,bp,manifest,proof,selection,imports=[data[n] for n in ('data_plan','binding','manifest','retained','selection','imports')]
    require(file_hash(paths['reference'])==hashes['reference'],'stale reference image')
    validate_headers(data,hashes,paths)
    require(bp['kind']=='fnv-runtime-binding-observations' and bp['schema_version']==1 and bp['status']=='analysis-only' and
        all(bp.get(k)is False for k in ('runtime_eligible','link_ready','runtime_closure_verified','provider_selected')) and bp['game_fixups_approved']==0,'binding plan state differs')
    require(all(bp['inputs'][n]==hashes[n] for n in ('recipes','manifest','retained','selection','reference','imports')) and dp['recipe_sha256']==hashes['recipes'],'stale plan/source joins')
    require(imports['kind']=='fnv-static-import-plan' and imports['inputs']['reference']==hashes['reference'] and
        imports['inputs']['manifest']==hashes['manifest'] and imports['inputs']['retained']==hashes['retained'],'stale imports')
    details_in=Path(args.data_details).resolve();binding_in=Path(args.binding_details).resolve()
    observations={paths[n]:hashes[n] for n in names}
    observations.update({details_in:dp['detail_sha256'],binding_in:bp['details_sha256']})
    require(dp['detail_columns']==COLUMNS,'original data columns changed')
    for p,h in observations.items():require(file_hash(p)==h,'input fingerprint differs')
    for name,h in proof['inputs']['tools_sha256'].items():
        p=(ROOT/name).resolve();require(p.is_relative_to(ROOT) and file_hash(p)==h,'stale proof tool');observations[p]=h
    for name in ('runtime_data_owners.py','relocation_audit.py','import_plan.py','coff_inventory.py','data_plan.py','runtime_gaps.py'):
        p=ROOT/'tools/rebuild'/name;observations[p]=file_hash(p)
    header=root/HEADER;require(file_hash(header)==HEADER_PIN,'wrong generated-placeholder source');observations[header]=HEADER_PIN
    index=root/'build/function_index.json';require(not index.exists() and proof['inputs']['function_index_present'] is False and
        selection['function_index_present'] is False and bp['optional_function_index_present'] is False,'optional index absence changed')
    units={u['recipe_index']:u for u in proof['units']}
    require(len(units)==len(proof['units'])==len(manifest['units']),'proof scope conflict')
    objects={};sources={}
    for unit in manifest['units']:
        obj=(paths['manifest'].parent/manifest.get('object_root_relative','.')/unit['object']).resolve();src=(root/unit['source']).resolve()
        require(src.is_relative_to(root) and obj not in objects,'invalid source/object identity')
        objects[obj]=unit['object_sha256'];sources[src]=unit['source_sha256']
    observations.update(objects);observations.update(sources)
    out,details=Path(args.out).resolve(),Path(args.details_gz).resolve();progress=Path(str(out)+'.progress.jsonl')
    require(len({out,details,progress})==3 and all(not p.exists() and p not in observations for p in (out,details,progress)),'output/input collision')
    arenas=arenas_from_plan(dp);providers={};seen=set();checked_rows=0;leadcoff=None
    progress.parent.mkdir(parents=True,exist_ok=True)
    with progress.open('x',encoding='utf-8') as journal:
        def note(value):journal.write(json.dumps(value)+'\n');journal.flush();os.fsync(journal.fileno())
        note(dict(state='started',input_sha256=hashes));created=[]
        try:
            with tempfile.TemporaryFile() as temp:
                with gzip.GzipFile(fileobj=temp,mode='wb',mtime=0) as gz:
                    event_counts=Counter()
                    def emit(value):event_counts[value['event']]+=1;gz.write(canonical(value)+b'\n')

                    for number,unit in enumerate(manifest['units']):
                        pv=units[unit['recipe_index']]
                        require(unit['status']=='compiled' and pv['status']=='ok' and pv['recipe_id']==unit['recipe_id'] and
                            pv['object_sha256']==unit['object_sha256'] and pv['recipe_unit_sha256']==unit_digest(unit['recipe']) and
                            pv['source_sha256_recorded']==pv['source_sha256_current']==unit['source_sha256'],'stale unit proof')
                        obj=(paths['manifest'].parent/manifest.get('object_root_relative','.')/unit['object']).resolve()
                        coff=Coff(obj);require(hashlib.sha256(coff.data).hexdigest()==unit['object_sha256'],'object changed')
                        require(file_hash(root/unit['source'])==unit['source_sha256'],'source changed')
                        functions=verified_functions(coff,unit,pv);chosen=selected_for_unit(unit,functions,selection['selections']);checked_rows+=len(functions)
                        for f in chosen:
                            address=va(int(f['address'],16));require(address not in seen,'duplicate provider owner');seen.add(address)
                            symbols=[s for s in coff.symbols.values() if s['name']==f['symbol'] and s['section']==f['section'] and s['value']==f['value']]
                            require(len(symbols)==1,'physical provider ambiguous');s=symbols[0]
                            ident=dict(recipe_id=unit['recipe_id'],object_sha256=unit['object_sha256'],symbol_index=s['index'])
                            rec=dict(provider_id=digest(ident),identity=ident,source_sha256=unit['source_sha256'],original_start=int(f['address'],16),
                                original_end=int(f['address'],16)+f['size'],native_section=f['section'],native_value=f['value'],verified_span=f['size'],
                                ABI_and_frame_closure_approved=False,**FALSE)
                            providers[address]=rec;emit(dict(event='SOURCE_CODE_PROVIDER_OBLIGATION',**rec))
                        if unit['recipe_index']==1678:leadcoff=coff
                        if (number+1)%200==0:note(dict(state='verified_named_objects',objects=number+1))
                    require(seen==set(selection['selections']) and checked_rows==selection['selected_recipe_rows'],'complete source owner coverage differs')
                    groups,literal_ranges,lead,provenance=binding_stream(binding_in,bp,manifest,selection,emit)
                    pe=Pe(paths['reference'])
                    try:
                        require(pe.base==dp['image']['base'] and pe.image_size==dp['image']['size'],'image geometry changed')
                        ranges=special_ranges(pe,imports)
                        pe_offset=pe.unpack('<I',0x3c)[0]
                        section_alignment,file_alignment=pe.unpack('<II',pe_offset+24+32)
                        require(section_alignment and section_alignment&(section_alignment-1)==0,'invalid PE section alignment')
                        for arena in arenas:
                            arena['PE_section_alignment_observed']=section_alignment
                            arena['PE_file_alignment_observed']=file_alignment
                            emit(dict(event='ARENA_GEOMETRY',**arena))
                    finally:pe.close()
                    ranges+=literal_ranges
                    for r in ranges:emit(dict(event='STORAGE_DOMAIN_EVIDENCE',**r))
                    partitions=partition_domains(arenas,ranges)
                    for p in partitions:emit(dict(event='DISJOINT_ARENA_DOMAIN',**p))
                    # External resource/metadata ranges remain obligations even without an arena.
                    outside=external_domains(arenas,ranges)
                    for p in outside:emit(dict(event='DISJOINT_EXTERNAL_DOMAIN',**p))
                    domains=Intervals([(p['start'],p['end'],p) for p in partitions+outside])
                    code=Intervals([(p['original_start'],p['original_end'],p) for p in providers.values()])
                    for key,g in sorted(groups.items()):
                        emit(dict(event='CODE_TARGET_OBLIGATION',group_identity=key,original_target=g['target'],
                            target_view=view_at(int(g['target'],16),arenas,domains,code) if g['target'] else None,
                            code_binding_provenance=dict(binding_details_sha256=bp['details_sha256'],row_ordinals=g['ordinals'],
                                row_sequence_sha256=g['row_digest'].hexdigest()),per_use_classes=dict(g['classes']),**FALSE))
                    data_counts=Counter();backing=Counter();sites=set();data_digest=hashlib.sha256();views=set();lead_window=[]
                    with gzip.open(details_in,'rt',encoding='utf-8') as stream:
                        for number,line in enumerate(stream,1):
                            require(number<=1000000 and len(line)<=65536,'data stream bound exceeded')
                            vals=json.loads(line);record=data_field(vals,arenas,domains,dp['image']['base'],code)
                            site=vals[0];require(not any(site+i in sites for i in range(-3,4)),'duplicate/overlapping original data site');sites.add(site)
                            data_digest.update(canonical(vals));data_counts[vals[2]]+=1;backing[vals[5]]+=1
                            target=dp['image']['base']+vals[1]
                            record['code_target_obligation_group']=va(target) if va(target) in groups else None
                            emit(record)
                            if target not in views:views.add(target);emit(dict(event='ORIGINAL_TARGET_VIEW',**record['target_view']))
                            if LEAD<=target<LEAD+4 or LEAD-3<=dp['image']['base']+site<LEAD+4:lead_window.append(record['site_identity'])
                    require(len(sites)==dp['fixups']['nonexec_data_sites'] and dict(data_counts)==dp['fixups']['by_target'],'complete original per-site coverage differs')
                    require(not lead_window,'lead window gained data pointer/site')
                    lifecycle=lead_lifecycle(lead,leadcoff,(root/'src/generated/global_object_initializers.cpp').read_text(),header.read_text(),lead_source_evidence(root,sources))
                    emit(lifecycle)
                    emit(dict(event='UNRESOLVED_DOMAIN_OBLIGATIONS',obligations=['CRT complement/onexit/runtime object extents not supplied',
                        'resource/RVA/encoded-pointer grammar not proved by HIGHLOW','cross-arena arithmetic and one-past aliases not proved',
                        'SceneGraph non-null lifecycle remains open','unknown EH/code/helper targets cannot use numeric fallback'],**FALSE))
                require(not index.exists(),'optional index appeared')
                for p,h in observations.items():require(file_hash(p)==h,'input changed during owner ledger')
                details.parent.mkdir(parents=True,exist_ok=True);temp.seek(0)
                with details.open('xb') as f:
                    created.append(details)
                    while block:=temp.read(1048576):f.write(block)
                result=dict(schema_version=1,kind='fnv-runtime-data-owner-ledger',status='analysis-only',inputs=hashes,
                    data_detail_sha256=dp['detail_sha256'],binding_detail_sha256=bp['details_sha256'],details_sha256=file_hash(details),
                    implementation_sha256=file_hash(__file__),detail_format='gzip-jsonl-owner-geometry-views-obligations-no-bytes',
                    summary=dict(arenas=len(arenas),selected_source_providers=len(providers),data_fields=len(sites),data_by_target=dict(data_counts),
                        data_backing=dict(backing),data_identity_sequence_sha256=data_digest.hexdigest(),unique_data_target_views=len(views),
                        source_literal_candidates=len(literal_ranges),domain_partitions=len(partitions),unresolved_domain_overlap_segments=sum(p['unresolved_domain_overlap'] for p in partitions),
                        code_target_groups=len(groups),code_binding_provenance=provenance,events=dict(event_counts)),
                    lead=lifecycle,retained_EH_notes=selection['retained_verification'],original_missing_fields=88,optional_function_index_present=False,
                    optional_binding_candidates_unadopted=bp['optional_candidate_evidence'],runtime_eligible=False,provider_selected=False,
                    materialization_approved=False,link_ready=False,game_fixups_approved=0,elapsed_seconds=round(time.monotonic()-started,3),
                    limitations=['Arena storage geometry is not per-object extent/type/lifetime proof.',
                        'Source projections and code ownership remain provider candidates, never selected runtime owners.',
                        'Data HIGHLOW rows lack source-symbol/addend proof; null is preserved rather than inventing an addend.',
                        'All original code rows remain exact hash/ordinal-linked; no overlay replaces missing baseline fields.',
                        'Resource/RVA/cross-domain arithmetic and unknown runtime-state extents remain obligations.'])
                out.parent.mkdir(parents=True,exist_ok=True)
                with out.open('x',encoding='utf-8') as f:created.append(out);json.dump(result,f,separators=(',',':'));f.write('\n')
                note(dict(state='complete',report_sha256=file_hash(out),details_sha256=file_hash(details)));return result
        except BaseException as error:
            for p in created:p.unlink(missing_ok=True)
            note(dict(state='failed',error_type=type(error).__name__));raise


def main(argv=None):
    p=argparse.ArgumentParser(description=__doc__)
    for n in ('data_plan','binding','recipes','manifest','retained','selection','imports','reference'):
        p.add_argument('--'+n.replace('_','-'),required=True,type=Path,dest=n);p.add_argument('--'+n.replace('_','-')+'-sha256',required=True,dest=n+'_sha256')
    p.add_argument('--data-details',required=True,type=Path);p.add_argument('--binding-details',required=True,type=Path)
    p.add_argument('--root',type=Path,default=ROOT);p.add_argument('--out',required=True,type=Path);p.add_argument('--details-gz',required=True,type=Path)
    try:r=run(p.parse_args(argv))
    except (ValueError,OSError,KeyError,TypeError,struct.error) as e:p.exit(2,'owner ledger rejected: '+str(e)+'\n')
    print(json.dumps(r['summary']));return 0

if __name__=='__main__':raise SystemExit(main())
