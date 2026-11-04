"""Name-only CODE reference groups within a complete parent-owned EH graph.

Adapts the reviewed union-v2 name writer, never its eligibility certificate.
The supported projector freshly replays the parent observer before calling it.
"""
from collections import defaultdict
from pathlib import Path
import struct
import parent_eh_adapter as adapter
import runtime_code_pool as pool

coff=adapter.coff
require=coff.require
POLICY='parent-owned-EH-CODE-reference-groups-v1'
UNION_SOURCE_SHA='2438480b1ba641b4714dfc10a739f27560f40a7536b5ee397805da72a9122f4f'


def certify(raw,result,contract):
    require(adapter.sha((adapter.ROOT/'tools/rebuild/union_reference_groups_v2.py').read_bytes())==UNION_SOURCE_SHA,'REFERENCE_GROUP_ALGORITHM_LINEAGE_DRIFT')
    require(result['structural_projection_candidate'] is True and result['semantic_graph_verified'] is True and result['blockers']==[],'INCOMPLETE_PARENT_EH_GRAPH')
    require(all(result[k] is False for k in adapter.FALSE),'RUNTIME_PROMOTION_FORBIDDEN')
    semantic=result['semantic'];root=semantic['parent'];obj=coff.parse(raw)
    require(semantic['object_sha256']==adapter.sha(raw) and semantic['contract_sha256']==adapter.digest(contract),'STALE_PARENT_GROUP_CONTEXT')
    runtime={root['section'],semantic['code_section'],semantic['state_section']}
    require(runtime<=set(result['retained_sections']),'MISSING_RUNTIME_GRAPH_SECTION')
    native=[(sn,off,index,kind) for sn in sorted(runtime) for off,index,kind in obj['sections'][sn]['relocs']]
    fields=semantic['fields'];keys=[(f['section'],f['offset'],f['target_index'],f['kind']) for f in fields]
    require(len(set(native))==len(native) and len(set(keys))==len(keys) and sorted(keys)==sorted(native),'INCOMPLETE_EXPANDED_FIELD_UNIVERSE')
    external={e['symbol_index']:e for e in semantic['external_obligations']}
    require(len(external)==len(semantic['external_obligations']) and set(external)=={i for _,_,i,_ in native if obj['symbols'][i]['section'] not in runtime},'INCOMPLETE_EXTERNAL_UNIVERSE')
    grouped=defaultdict(list);bindings=[];by_index=defaultdict(list)
    export=pool.canonical(dict(recipe_id=contract['recipe_id'],object_sha256=adapter.sha(raw),symbol_index=root['symbol_index']))
    bindings.append((root['symbol_index'],export))
    for field in fields:
        sn,off,index,kind=field['section'],field['offset'],field['target_index'],field['kind']
        require(kind in (6,20) and field['proof_family'] in ('PARENT_FINAL_BINDING','PARENT_OWNED_GENERATED_EH_FIELD'),'UNREVIEWED_FIELD_FAMILY')
        payload=obj['sections'][sn]['payload'];addend=adapter.i32(payload,off) if kind==20 else adapter.u32(payload,off)
        require(addend==field['addend'] and (field['original_base']+addend)&0xffffffff==field['original_target'],'CHANGED_FIELD_IDENTITY')
        if index in external:
            require(field['original_base']==external[index]['base'],'FIELD_EXTERNAL_BASE_CONFLICT')
            by_index[index].append(field)
    for index,e in sorted(external.items()):
        symbol=obj['symbols'][index]
        require(index in result['retained_primary_indices'] and symbol['name']==e['symbol'] and by_index[index],'UNBOUND_EXTERNAL_PHYSICAL_RECORD')
        name=pool.unresolved('0x%08x'%e['base'],e['role']);bindings.append((index,name));grouped[name].append(index)
    parent_fields={(r['physical_section'],r['coff_relocation']['offset'],r['coff_relocation']['symbol_index'],r['coff_relocation']['kind']):r for r in contract['fields']}
    require(len(parent_fields)==len(contract['fields']),'DUPLICATE_PARENT_FIELD_PROOF')
    groups=[]
    for name,members in sorted(grouped.items()):
        if len(members)<2:continue
        identities={tuple(external[i][k] for k in ('base','role','semantic_domain','contract_kind')) for i in members}
        require(len(identities)==1,'AMBIGUOUS_REFERENCE_GROUP_SEMANTICS')
        identity=next(iter(identities));require(identity[1:]==('code','code','function'),'ONLY_CODE_FUNCTION_REFERENCE_GROUPS_SUPPORTED')
        for index in members:
            s=obj['symbols'][index]
            require((s['section'],s['value'],s['type'],s['storage'],s['aux_count'])==(0,0,32,2,0) and not s['name'].startswith(('__imp_','_imp__')),'REFERENCE_GROUP_MEMBER_IS_NOT_UNDEFINED_FUNCTION')
            for field in by_index[index]:
                key=(field['section'],field['offset'],index,field['kind']);row=parent_fields.get(key)
                require(field['section']==root['section'] and field['proof_family']=='PARENT_FINAL_BINDING' and field['addend']==0 and field['original_target']==identity[0],'GROUP_USE_NOT_ZERO_ADDEND_PARENT_ENTRY')
                require(row is not None and row['classification']=='SELECTED_CODE_ENTRY' and row['proof_consistency']=='EXACT_OWN_SOURCE_RESOLUTION' and row['code_ownership_ambiguous'] is False and row['code_owners']==[dict(address='0x%08x'%identity[0],offset=0)] and int(row['derived_source_symbol_base_va'],16)==int(row['exact_original_target_va'],16)==identity[0],'GROUP_CODE_ENTRY_OWNER_NOT_PROVED')
        groups.append(dict(name=name,members=members,original_base=identity[0],role=identity[1],semantic_domain=identity[2],contract_kind=identity[3],
            fields=[f for i in members for f in by_index[i]],all_physical_uses=[dict(section=sn,offset=off,target_index=index,kind=kind,retained=sn in runtime) for sn,sec in sorted(obj['sections'].items()) for off,index,kind in sec['relocs'] if index in members],ABI_verified=False,provider_selected=False))
    require(groups,'NO_DUPLICATE_CODE_REFERENCE_GROUPS')
    require(len({i for i,_ in bindings})==len(bindings) and export not in grouped,'EXPORT_REFERENCE_NAMESPACE_COLLISION')
    associations=[dict(section=sn,aux=list(adapter.section_aux(obj,sn)[1])) for sn in sorted(runtime)]
    return dict(schema_version=1,policy_id=POLICY,object_sha256=adapter.sha(raw),contract_sha256=adapter.digest(contract),
        parent_observation_sha256=adapter.digest(result),semantic_graph_sha256=adapter.digest(semantic),complete_fields_sha256=adapter.digest(fields),
        physical_field_count=len(fields),retained_sections=result['retained_sections'],retained_primary_indices=result['retained_primary_indices'],
        retained_physical_slots=result['retained_physical_slots'],associations=associations,states_sha256=adapter.digest(semantic['states']),
        safeseh_sha256=adapter.digest(result['safeseh_records']),groups=groups,bindings=sorted(bindings),export=export,
        coalescing_allowed=False,relocation_retargeting_allowed=False,requires_fresh_parent_replay=True,**adapter.FALSE)


def namespace(raw,result,contract,certificate):
    fresh=certify(raw,result,contract);require(adapter.digest(fresh)==adapter.digest(certificate),'STALE_OR_FORGED_EH_GROUP_CERTIFICATE')
    obj=coff.parse(raw);output=bytearray(raw);extra=bytearray();expected={i:dict(s) for i,s in obj['symbols'].items()}
    allowed=set(range(obj['string_pointer'],obj['string_pointer']+4));seen=set();targets=defaultdict(list)
    for index,name in certificate['bindings']:targets[name].append(index)
    require({name:sorted(indices) for name,indices in targets.items() if len(indices)>1}=={g['name']:g['members'] for g in certificate['groups']},'HIDDEN_REFERENCE_GROUP')
    existing={s['name'] for s in obj['symbols'].values()}
    for index,name in certificate['bindings']:
        require(index in obj['symbols'] and index not in seen and name not in existing and isinstance(name,str) and all(33<=ord(c)<=126 for c in name),'NAMESPACE_INDEX_OR_NAME_COLLISION')
        s=obj['symbols'][index];require(s['storage'] in (2,3) and s['section']>=0 and not s['aux_count'],'UNSUPPORTED_NAMESPACE_RECORD')
        offset=obj['symbol_pointer']+18*index;require(obj['string_length']+len(extra)<=0xffffffff,'STRING_EXTENT_OVERFLOW')
        struct.pack_into('<II',output,offset,0,obj['string_length']+len(extra));extra+=name.encode('ascii')+b'\0';expected[index]['name']=name;seen.add(index);allowed.update(range(offset,offset+8))
    require(obj['string_length']+len(extra)<=0xffffffff,'STRING_EXTENT_OVERFLOW')
    struct.pack_into('<I',output,obj['string_pointer'],obj['string_length']+len(extra));output+=extra
    after=coff.parse(bytes(output))
    require(after['symbols']==expected and after['sections']==obj['sections'] and all(a==b or i in allowed for i,(a,b) in enumerate(zip(raw,output))),'NAME_ONLY_INVARIANT_FAILED')
    return bytes(output)
