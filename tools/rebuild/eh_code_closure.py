"""Fixed parent-owned EH serialization policy; no compiler/link/native calls.

Actual IOTask emission is blocked until the separately versioned expanded-root
producer exists and is reviewed. Synthetic composition/serialization is testable.
"""
from __future__ import annotations
import copy
import hashlib
import json
from pathlib import Path
import struct
import tempfile
import argparse
import sys

ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'tools'))
import coff_code_archive as coff
from runtime_code_pool import canonical,unresolved

POLICY='iotask69-parent-eh-component-v1'
EXPANDED='root-code-closure-expanded-eh-v2'
FALSE=dict(runtime_eligible=False,provider_selected=False,ABI_verified=False,link_ready=False,namespace_approved=False)
NATIVE_OBJECT='4e7ad6d343e1abc45e1ef23eb96436174032d7cdd5a0c69b2f0748bd8b37607b'
DEFAULTS=b'/DEFAULTLIB:"LIBCMT" /DEFAULTLIB:"OLDNAMES"'

def require(ok,message):
    if not ok:raise ValueError(message)

def digest(value):return hashlib.sha256(json.dumps(value,sort_keys=True,separators=(',',':')).encode()).hexdigest()
def sha(data):return hashlib.sha256(data).hexdigest()
def file_sha(path):return sha(Path(path).read_bytes())

def validate_policy(p):
    require(p.get('schema_version')==1 and p.get('kind')=='fnv-iotask69-eh-policy' and p.get('policy_id')==POLICY,'unknown EH policy')
    require(p['recipe_index']==69 and p['recipe_id']=='0069-3b6fc41592bb705f' and p['selected']==dict(original_address='0x00440540',symbol='??0IOTask@@QAE@W4IO_TASK_PRIORITY@@@Z',symbol_index=8,section=3,value=0,size=101),'fixed parent differs')
    require(p['retained_sections']==[1,3,4,6,16] and p['eh']==dict(code_section=4,size=35,cleanup_index=12,handler_index=19,handler_offset=8,metadata_section=6,metadata_size=44,info_index=24,unwind_index=25,state_count=1),'EH graph policy differs')
    require(p['safeseh']==dict(section=16,ordinal=0,handler_index=19,record_count=1),'whole registry scope differs')
    require(p['data_boundary']==dict(symbol_index=16,section=5,value=4,symbol='??_7IOTask@@6B@',original_base='0x01016c10',role='data',semantic_domain='data',contract_kind='vtable-view',storage_defined=False),'DATA boundary differs')
    require(p['required_weak_omission']==dict(symbol_index=55,fallback_index=54,search=2),'weak omission scope differs')
    require(p['required_expanded_interface']==EXPANDED and all(p.get(k)is False for k in ('runtime_eligible','provider_selected','ABI_verified','link_ready')),'policy promotion forbidden')


def validate_external_identities(bindings,identities,shared,generated=None):
    """Shared base identity is required; semantic distinctions never enter its hash."""
    require(set(bindings)==set(identities),'external identity set differs')
    generated=[] if generated is None else generated
    seen={}
    def check(row):
        role=row.get('role');domain=row.get('semantic_domain');kind=row.get('contract_kind')
        allowed={'code':{'code'},'data':{'data'},'iat-cell':{'iat-cell'},'crt-contract':{'code','data'}}
        require(role in allowed and domain in allowed[role] and isinstance(kind,str) and bool(kind),'ambiguous canonical role/domain')
        require(type(row.get('base')) is int and 0<=row['base']<=0xffffffff,'invalid original base')
        identity=(role,domain,kind)
        require(seen.setdefault(row['base'],identity)==identity,'conflicting same-base canonical domain/subtype')
        return identity
    require(isinstance(shared,list) and bool(shared),'missing shared base identity proof')
    for row in shared:
        require(row.get('identity_consistency')=='EXACT_BASE_ROLE_RESOLUTION','unproved shared base identity')
        check(row)
    for index,b in bindings.items():
        declared=identities[index]
        require(set(declared)=={'role','semantic_domain','contract_kind'},'unknown identity policy fields')
        require(all(b.get(k)==v for k,v in declared.items()),'unproved external semantic identity')
        if generated and index==20:
            require(len(generated)==1 and generated[0]['family']=='EH_HANDLER_REL32_CRT_FIELD_V1' and generated[0]['symbol_index']==20 and generated[0]['base']==b['base'] and generated[0]['proof_consistency']==b.get('proof_consistency')=='EXACT_GENERATED_HANDLER_FIELD_RESOLUTION','generated handler cannot masquerade as own-source resolution')
        else:require(b.get('proof_consistency')=='EXACT_OWN_SOURCE_RESOLUTION','unproved ordinary external identity')
        require(b['base'] in seen and seen[b['base']]==(b['role'],b['semantic_domain'],b['contract_kind']),'missing compatible shared base identity')
        check(b)


def section_aux(obj,index):
    sec=obj['sections'][index]
    candidates=[(i,s) for i,s in obj['symbols'].items() if s['section']==index and s['name']==sec['name'] and s['storage']==3 and s['type']==0 and s['value']==0 and s['aux_count']==1]
    require(len(candidates)==1,'unique section auxiliary required')
    i,s=candidates[0];a=struct.unpack('<IHHIhBBH',s['aux'])
    require(a[0]==sec['size'] and a[1]==len(sec['relocs']) and not a[2] and not a[6] and not a[7],'unsupported section auxiliary fields')
    return i,a


def structural_identity(obj):
    return digest(dict(sections={i:{k:(sha(v) if k=='payload' else v) for k,v in s.items()} for i,s in obj['sections'].items()},symbols={i:{k:(sha(v) if k=='aux' else v) for k,v in s.items()} for i,s in obj['symbols'].items()},symbol_count=obj['symbol_count']))


def observe_component(raw,policy,context,reference):
    """Pure fixed-shape observation. Context must be externally hash-bound by caller.

    reference.read reads only exact parent/piece/table extents. It never executes.
    The unchanged original ordinary/EH core is also replayed on these inputs.
    A future production driver must bind the complete recipe/name context.
    """
    validate_policy(policy);obj=coff.parse(raw);require(sha(raw)==policy['object_sha256']==context['object_sha256'],'object identity differs')
    require(context['inputs']==policy['inputs'] and context['source_sha256']==policy['source_sha256'],'source/proof/selection identities differ')
    require(context['fields_complete']is True and context['missing_fields_complete']is True and context['missing_fields']==[],'incomplete field or original missing-field evidence')
    selected=policy['selected'];proof=context['parent_proof']
    require(all(proof.get(k)==v for k,v in dict(symbol=selected['symbol'],address=selected['original_address'],size=101,section=3,value=0,verdict='match').items()),'exact matched parent proof required')
    pieces=context['eh_pieces'];require(len(pieces)==2 and all(p[2]is True and p[3]==selected['original_address'] for p in pieces),'FAILED_LOCAL_EH_PIECE')
    require([p[1]-p[0] for p in pieces]==[8,27] and pieces[1][0]==pieces[0][0]+8,'piece identity/extent differs')
    sec=obj['sections'];sym=obj['symbols'];keep=policy['retained_sections'];expected={1:('.drectve',0x100a00),3:('.text',0x60501020),4:('.text$x',0x60501020),6:('.xdata$x',0x40301040),16:('.sxdata',0x300200)}
    for index,(name,flags) in expected.items():require(index in sec and (sec[index]['name'],sec[index]['flags'])==(name,flags),'runtime section identity differs')
    require(sec[3]['size']==101 and sec[4]['size']==35 and sec[6]['size']==44,'whole parent/EH spans required')
    require(sec[1]['payload'].strip()==DEFAULTS and not sec[1]['relocs'],'UNKNOWN_DIRECTIVE_CONTRACT')
    require(sec[16]['size']==4 and not sec[16]['relocs'] and sec[16]['payload']==struct.pack('<I',19),'MIXED_OR_INVALID_SAFESEH_TABLE')
    require((sym[8]['name'],sym[8]['section'],sym[8]['value'],sym[8]['storage'],sym[8]['type'],sym[8]['aux_count'])==(selected['symbol'],3,0,2,32,0),'parent physical record changed')
    local={12:(4,0,32),19:(4,8,32),24:(6,8,0),25:(6,0,0)}
    for index,(sn,value,typ) in local.items():
        s=sym[index];require((s['section'],s['value'],s['storage'],s['type'],s['aux_count'])==(sn,value,3,typ,0),'foreign parent/local symbol changed')
    required=set(local)|{8};associations=[]
    for sn in keep:
        index,a=section_aux(obj,sn);required.add(index)
        if sn in (4,6):require((a[4],a[5])==(3,5),'stale association');associations.append([sn,3])
        elif sn==3:require((a[4],a[5])==(0,1),'root COMDAT changed')
        else:require((a[4],a[5])==(0,0),'special section association changed')
        actual={i for i,s in sym.items() if s['section']==sn}
        require(actual==({index,8} if sn==3 else {index,12,19} if sn==4 else {index,24,25} if sn==6 else {index}),'extra/shared retained symbol')
    for i,s in sym.items():
        if s['name'] in ('@comp.id','@feat.00'):
            require((s['section'],s['type'],s['storage'],s['aux_count'])==(-1,0,3,0),'compiler metadata form differs')
            if s['name']=='@feat.00':require(s['value']==1,'unsupported SafeSEH feature value')
            required.add(i)
    boundary=policy['data_boundary'];v=sym[16]
    require((v['name'],v['section'],v['value'],v['storage'],v['type'],v['aux_count'])==(boundary['symbol'],5,4,2,0,0),'unproved vtable conversion')
    require(context['data_boundary_proof']==dict(symbol_index=16,original_base='0x01016c10',role='data',semantic_domain='data',contract_kind='vtable-view',exact=True,storage_defined=False),'missing explicit DATA boundary')
    bindings={int(k):v for k,v in context['external_bindings'].items()}
    identities={int(k):v for k,v in policy['external_identities'].items()}
    validate_external_identities(bindings,identities,context['shared_base_identities'],context.get('generated_eh_field_witnesses',[]))
    for i in bindings:
        if i!=16:require(sym[i]['section']==0 and sym[i]['value']==0 and sym[i]['storage']==2 and not sym[i]['aux_count'],'unsupported external source record')
    require(bindings[16]['base']==0x01016c10,'vtable original base differs')
    expected_relocs={3:[(6,19,6),(19,18,6),(42,17,20),(58,16,6),(70,13,20)],4:[(4,9,20),(21,21,20),(26,24,6),(31,20,20)],6:[(4,12,6),(16,25,6)]}
    for sn,rows in expected_relocs.items():require(sec[sn]['relocs']==rows,'missing/extra runtime edge')
    metadata_base=struct.unpack('<I',reference.read(pieces[1][0]+18,4))[0]-8
    locations={3:int(selected['original_address'],16),4:pieces[0][0],6:metadata_base}
    comparisons=[];fields=[]
    for sn in (3,4,6):
        native=sec[sn]['payload'];original=reference.read(locations[sn],len(native));require(len(original)==len(native),'reference extent missing');masked=set()
        for off,target,kind in sec[sn]['relocs']:
            require(off+4<=len(native) and kind in (6,20),'unsupported relocation');required.add(target)
            addend=struct.unpack_from('<i' if kind==20 else '<I',native,off)[0]
            if target in bindings:base=bindings[target]['base']
            else:base=locations[sym[target]['section']]+sym[target]['value']
            actual=(locations[sn]+off+4+struct.unpack_from('<i',original,off)[0])&0xffffffff if kind==20 else struct.unpack_from('<I',original,off)[0]
            expected_value=(base+addend)&0xffffffff;require(expected_value==actual,'reference relocation target mismatch')
            fields.append(dict(section=sn,offset=off,target_index=target,kind=kind,addend=addend,original_base=base,original_target=actual))
            masked.update(range(off,off+4))
        diff=sum(a!=b for i,(a,b) in enumerate(zip(native,original)) if i not in masked);require(not diff,'nonrelocation parent/piece/metadata mismatch')
        comparisons.append(dict(section=sn,size=len(native),payload_sha256=sha(native),nonrelocation_differences=diff))
    require(struct.unpack('<11I',sec[6]['payload'])==(0xffffffff,0,0x19930522,1,0,0,0,0,0,0,1),'missing/unsupported state transitions')
    require(len(fields)==11,'runtime relocation count differs')
    # Preserve the original comparison gate, independently of the fixed graph checks.
    import build_and_match as oracle
    require(file_sha(ROOT/'tools/build_and_match.py')==policy['comparison_tools']['tools/build_and_match.py'],'original oracle drift')
    for path,expected_hash in policy['comparison_tools'].items():require(file_sha(ROOT/path)==expected_hash,'comparison dependency drift')
    unit=context['core_unit'];names_context=context['core_names']
    require(unit['functions']==[dict(address=selected['original_address'],symbol=selected['symbol'],size=101)],'core recipe scope differs')
    with tempfile.TemporaryDirectory(prefix='eh-unchanged-core-') as folder:
        path=Path(folder)/'input.obj';path.write_bytes(raw);core_obj=oracle.Coff(path)
        ordinary=oracle.compare(core_obj,reference,unit,None)
        core_pieces,inferred,errors=oracle.eh_sections(core_obj,reference,unit,ordinary,names_context)
    require(len(ordinary)==1 and ordinary[0]['verdict']=='match' and ordinary[0]['compiled_extent']==101,'unchanged ordinary core failed')
    require(not errors and [p[:4] for p in core_pieces]==[p[:4] for p in pieces],'unchanged EH core failed or changed pieces')
    core_evidence=dict(ordinary=ordinary,eh_sections=core_pieces,inferred=inferred,eh_errors=errors,comparison_tools=policy['comparison_tools'])
    slots=sorted(j for i in required for j in range(i,i+1+sym[i]['aux_count']))
    names={8:canonical(dict(recipe_id=policy['recipe_id'],object_sha256=sha(raw),symbol_index=8))}
    names.update({i:unresolved('0x%08x'%b['base'],b['role']) for i,b in bindings.items()})
    require(names[8] not in [names[i] for i in bindings],'canonical physical namespace collision')
    plan=dict(schema_version=1,policy_id=POLICY,kind='fnv-parent-eh-retention-plan',status='eh-observed-composition-pending',recipe_id=policy['recipe_id'],object_sha256=sha(raw),source_sha256=policy['source_sha256'],inputs=policy['inputs'],selected=selected,retained_sections=keep,retained_primary_indices=sorted(required),retained_physical_slots=slots,undefined_conversions=[16],namespace=[[i,names[i]] for i in sorted(names)],external_obligations=[dict(symbol_index=i,**bindings[i]) for i in sorted(bindings)],shared_base_identities=copy.deepcopy(context['shared_base_identities']),generated_eh_field_witnesses=copy.deepcopy(context.get('generated_eh_field_witnesses',[])),comparisons=comparisons,fields=fields,unchanged_core=core_evidence,parent_EH=copy.deepcopy(pieces),reference_identity_sha256=context['reference_identity_sha256'],dependency_field_observations=dependency_observations(obj),state_transitions=[dict(state=0,to_state=-1,cleanup_index=12,native_offset=0,original_cleanup=pieces[0][0])],associations=associations,safeseh=dict(section=16,ordinal=0,input_handler_index=19),required_weak_omission=policy['required_weak_omission'],source_graph_sha256=structural_identity(obj),universe=dict(section_indices=sorted(sec),primary_indices=sorted(sym),physical_slots=list(range(obj['symbol_count']))),**FALSE)
    return plan


def dependency_observations(obj):
    rows=[]
    for sn in (4,6):
        for offset,index,kind in obj['sections'][sn]['relocs']:
            target=obj['symbols'][index]
            rows.append(dict(section=sn,offset=offset,target_index=index,kind=kind,
                addend_bits=struct.unpack_from('<I',obj['sections'][sn]['payload'],offset)[0],
                target_symbol={k:target[k] for k in ('name','section','value','type','storage','aux_count')},
                identity_status='pending-eh-adapter'))
    return rows


def expanded_contract(plan):
    """Derive the requested physical contract from our independently checked plan."""
    local=[dict(symbol_index=i,section=sn,value=value,type=typ,storage=3,aux_count=0,role=role)
           for i,sn,value,typ,role in ((12,4,0,32,'cleanup'),(19,4,8,32,'handler'),(24,6,8,0,'funcinfo'),(25,6,0,0,'unwind-map'))]
    sections=[dict(section=sn,role=role,parent=parent,extent=extent) for sn,role,parent,extent in
        ((1,'directives',None,'whole'),(3,'ordinary-parent',None,101),(4,'parent-eh-code',3,35),(6,'parent-eh-state',3,44),(16,'whole-safeseh-index',None,4))]
    return dict(interface=EXPANDED,requested_sections=sections,local_symbols=local,
        data_boundary=dict(symbol_index=16,section=5,value=4,symbol='??_7IOTask@@6B@',original_base='0x01016c10',role='data',semantic_domain='data',contract_kind='vtable-view',storage_defined=False),
        dependency_field_observations=copy.deepcopy(plan['dependency_field_observations']),
        external_reference_contracts=copy.deepcopy(plan['external_obligations']),
        shared_base_identities=copy.deepcopy(plan['shared_base_identities']))


def extension_obligations(plan):
    rows=[]
    for sn,role,size in ((4,'parent-eh-code',35),(6,'parent-eh-state',44)):
        observations=[r for r in plan['dependency_field_observations'] if r['section']==sn]
        rows.append(dict(code='RETAINED_PARENT_EH_OR_UNKNOWN_CHILD',evidence=dict(parent=3,child=sn,
            requested_role=role,full_extent=size,
            field_keys=[[r['section'],r['offset'],r['target_index'],r['kind']] for r in observations],
            field_observation_sha256=digest(observations))))
    rows.append(dict(code='LIVE_SAFESEH_HANDLER_REQUIRES_ADAPTER',evidence=dict(section=16,offset=0,
        symbol_index=19,target_section=4,target_value=8,record_count=1,retention_mode='whole-table')))
    for row in rows:row['blocker_id']=digest(dict(code=row['code'],evidence=row['evidence']))
    return rows


def check_contract(plan,contract):
    require(isinstance(contract,dict),'full expanded contract required')
    require(contract['recipe_id']==plan['recipe_id'] and contract['roots']==[plan['selected']],'expanded selected root differs')
    require(contract['expanded_retention_contract']==expanded_contract(plan),'expanded physical/role contract differs')
    require(contract['parent_eh']==plan['parent_EH'] and contract['missing_fields']==[],'parent EH or original missing fields differ')
    require(all(contract[k]is True for k in ('verified_match','fields_complete','missing_fields_complete','unit_proofs_complete')),'incomplete original proof contract')
    parent_fields=[r for r in plan['fields'] if r['section']==3]
    rows=contract['fields']
    require(len(rows)==5,'five original parent binding rows required')
    observed={}
    for row in rows:
        cr=row['coff_relocation'];key=(row['physical_section'],cr['offset'],cr['symbol_index'],cr['kind'])
        require(key not in observed,'duplicate original parent field')
        observed[key]=row
    for field in parent_fields:
        key=(3,field['offset'],field['target_index'],field['kind']);require(key in observed,'missing original parent field')
        row=observed[key]
        require(row['function_va']==plan['selected']['original_address'] and row['proof_consistency']=='EXACT_OWN_SOURCE_RESOLUTION' and
            int(row['derived_source_symbol_base_va'],16)==field['original_base'] and int(row['exact_original_target_va'],16)==field['original_target'] and
            row['coff_relocation']['addend']==field['addend']&0xffffffff,'parent field semantic proof differs')
    provenance=contract['provenance']
    witnesses=plan.get('generated_eh_field_witnesses',[])
    require(contract.get('generated_eh_field_witnesses',[])==witnesses,'full generated witness container differs')
    if witnesses:
        require(len(witnesses)==1 and witnesses[0]['family']=='EH_HANDLER_REL32_CRT_FIELD_V1' and witnesses[0]['symbol_index']==20 and witnesses[0]['parent']==plan['selected']['original_address'],'unknown generated witness family/scope')
        witness=witnesses[0]
        external=next(row for row in plan['external_obligations'] if row['symbol_index']==20)
        require(witness['proof_consistency']==external['proof_consistency']=='EXACT_GENERATED_HANDLER_FIELD_RESOLUTION','generated proof cannot claim ordinary own-source resolution')
        require(witness['object_sha256']==plan['object_sha256'] and witness['reference_sha256']==plan['reference_identity_sha256'] and witness['recipes_sha256']==plan['inputs']['recipes'],'generated witness provenance differs')
        from eh_field_witness import AUDIT_SHA256
        require(witness['audit_sha256']==AUDIT_SHA256 and witness['symbol']=='___CxxFrameHandler3' and (witness['base'],witness['role'],witness['semantic_domain'],witness['contract_kind'])==(0xec3d33,'crt-contract','code','cxx-frame-handler'),'wrong handler contract/audit identity')
        require(all(witness[k]is False for k in ('function_boundary_verified','runtime_eligible','provider_selected','ABI_verified','link_ready')),'handler witness runtime promotion')
        require(witness['handler']==dict(section=4,symbol_index=19,value=8,size=27,original_start=0xeec248,original_end=0xeec263,nonfield_differences=0) and witness['original_highlow_offsets']==[18],'handler proof extent/asymmetric fields differ')
        expected_fields=[f for f in plan['fields'] if f['section']==4 and f['offset']>=8]
        require(len(witness['fields'])==len(expected_fields)==3,'incomplete generated handler field graph')
        for own,proved in zip(expected_fields,witness['fields']):
            require(all(proved[k]==own[k] for k in ('section','offset','target_index','kind','original_base','original_target')) and proved['source_addend']==own['addend'],'generated handler field semantics differ')
        info=next(f for f in expected_fields if f['target_index']==24)
        require(witness['metadata']==dict(section=6,size=44,original_base=info['original_base']-8,nonfield_differences=0,original_highlow_offsets=[4,16]),'handler state proof differs')
        require(provenance.get('generated_eh_field_witnesses_sha256')==digest(witnesses),'missing generated witness identity')
    expected=dict(object_sha256=plan['object_sha256'],source_sha256=plan['source_sha256'],recipe_id=plan['recipe_id'],recipe_index=69,
        producer_manifest_sha256=plan['inputs']['manifest'],retained_proof_sha256=plan['inputs']['retained'],recipe_manifest_sha256=plan['inputs']['recipes'],
        selection_sha256=plan['inputs']['selection'],binding_sha256=plan['inputs']['binding'],reference_identity_sha256=plan['reference_identity_sha256'],optional_function_index_present=False)
    require(all(provenance.get(k)==v for k,v in expected.items()),'expanded source/proof/reference/index provenance differs')
    def valid_hash(h):return isinstance(h,str) and len(h)==64 and all(c in '0123456789abcdef' for c in h)
    require(valid_hash(provenance['reference_identity_sha256']) and valid_hash(provenance['observer_sha256']),'missing reference/producer identity')
    tools=provenance['dependency_tools_sha256'];require(isinstance(tools,dict) and tools and all(valid_hash(v) for v in tools.values()),'missing dependency tool identities')
    require(valid_hash(provenance['recipe_unit_sha256']) and valid_hash(provenance['binding_details_sha256']),'missing recipe/binding detail provenance')


def compose(plan,generic,recomputed,contract=None):
    """A separate EH decision; ordinary and expanded generic acceptance stay false."""
    blocked=lambda code:dict(schema_version=1,policy_id=POLICY,kind='fnv-composed-eh-serialization-decision',serialization_plan_ready=False,blockers=[dict(code=code)],**FALSE)
    if not generic or generic.get('expanded_interface')!=EXPANDED or recomputed is None:return blocked('MISSING_EXPANDED_ROOT_CERTIFICATE')
    check_contract(plan,contract)
    require(digest(generic)==digest(recomputed),'expanded graph was not identically recomputed')
    require(generic.get('schema_version')==1 and generic.get('policy_id')==EXPANDED,'wrong expanded producer schema/policy')
    sub=generic['omission_subcertificate'];scope=sub['scope']
    expected=dict(policy_id=EXPANDED,export_policy=contract['export_policy'],roots=[plan['selected']],
        requested_dependency_retention=plan['retained_sections'],retained_section_indices=plan['retained_sections'],
        retained_primary_indices=plan['retained_primary_indices'],retained_physical_slots=plan['retained_physical_slots'],object_sha256=plan['object_sha256'],
        provenance_sha256=digest(contract['provenance']),contract_identity_sha256=digest(contract),
        expanded_retention_contract_sha256=digest(contract['expanded_retention_contract']),physical_universe_sha256=digest(plan['universe']),generated_eh_field_witnesses_sha256=digest(plan.get('generated_eh_field_witnesses',[])))
    require(all(scope.get(k)==v for k,v in expected.items()),'expanded retained/root/provenance scope differs')
    require(generic['contract_identity_sha256']==digest(contract) and generic['provenance']==contract['provenance'],'expanded full contract/provenance differs')
    require(generic['generated_eh_field_witnesses']==plan.get('generated_eh_field_witnesses',[]) and generic['external_reference_contracts']==plan['external_obligations'] and generic['shared_base_identities']==plan['shared_base_identities'],'expanded typed witness/external identity output differs')
    require(generic['roots']==[plan['selected']] and generic['physical_universe']==plan['universe'],'expanded root/universe differs')
    require(generic['retained_section_indices']==plan['retained_sections'] and generic['retained_runtime_section_indices']==[3,4,6] and generic['retained_primary_indices']==plan['retained_primary_indices'] and generic['retained_physical_slots']==plan['retained_physical_slots'],'expanded retained maps differ')
    require(generic['dependency_field_observations']==plan['dependency_field_observations'] and generic['parent_EH']==plan['parent_EH'],'expanded dependency or parent evidence differs')
    require(generic['requested_dependency_retention']==plan['retained_sections'] and scope['edges_sha256']==digest(generic['edges']) and sub['scope_sha256']==digest(scope),'expanded edge/scope identity differs')
    require(all(generic[k]is False for k in ('closure_observed','root_closure_candidate','serialization_candidate','full_serialization_eligible','emission_performed')) and sub['omission_approved']is False and generic['graph_observation_complete']is True and sub['graph_observation_complete']is True,'generic result was improperly waived')
    require(sub['policy_id']==EXPANDED and sub['disposition_sha256']==digest(dict(sections=generic['sections'],symbols=generic['symbols'])),'incomplete disposition digest')
    require(sorted(r['index'] for r in generic['sections'])==plan['universe']['section_indices'] and sorted(r['index'] for r in generic['symbols'])==plan['universe']['primary_indices'],'incomplete metadata universe')
    weak=next(r for r in generic['symbols'] if r['index']==55)
    require(weak['disposition']=='OMIT_UNREACHABLE_WEAK_CANDIDATE' and weak['decoded_auxiliary']==dict(kind='WEAK_EXTERNAL',fallback=54,search=2),'weak omission not proved for expanded graph')
    actual=generic['blockers'];allowed=extension_obligations(plan)
    for row in actual:require(row['blocker_id']==digest(dict(code=row['code'],evidence=row['evidence'])),'blocker identity differs')
    require(actual==allowed,'non-EH blocker/unknown child or incomplete exact discharge')
    ids=[r['blocker_id'] for r in actual]
    require(sub['unresolved_blocker_ids']==ids and sub['exact_EH_SafeSEH_extension_obligation_ids']==ids,'blocker/discharge set differs')
    require(all(generic.get(k)is False for k in FALSE),'generic runtime/ABI promotion')
    return dict(schema_version=1,policy_id=POLICY,kind='fnv-composed-eh-serialization-decision',serialization_plan_ready=False,synthetic_serialization_plan_ready=True,structural_composition_complete=True,live_driver_approved=False,plan_sha256=digest(plan),generic_observation_sha256=digest(generic),recomputed_observation_sha256=digest(recomputed),contract_identity_sha256=digest(contract),discharges=copy.deepcopy(actual),blockers=[dict(code='PRODUCER_FILES_NOT_VERIFIED')],proof=dict(generic=copy.deepcopy(generic),recomputed=copy.deepcopy(recomputed),contract=copy.deepcopy(contract)),original_generic_status_unchanged=True,**FALSE)


def recompute_and_compose(plan,generic,obj,contract):
    try:import expanded_root_code_closure as producer_module
    except ModuleNotFoundError as error:
        if error.name!='expanded_root_code_closure':raise
        return compose(plan,None,None)
    producer=getattr(producer_module,'observe_requested_dependency_retention',None)
    if producer is None:return compose(plan,None,None)
    require(getattr(producer_module,'EXPANDED_EH_INTERFACE',None)==EXPANDED,'unreviewed expanded producer interface')
    check_contract(plan,contract)
    expected_module=ROOT/'tools/rebuild/expanded_root_code_closure.py'
    require(Path(producer_module.__file__).resolve()==expected_module.resolve(),'swapped expanded producer module')
    require(file_sha(expected_module)==contract['provenance']['observer_sha256'],'stale expanded producer identity')
    dependencies=contract['provenance']['dependency_tools_sha256']
    required={'tools/rebuild/expanded_root_code_closure.py','tools/rebuild/root_code_closure.py','tools/rebuild/coff_code_archive.py'}
    require(required<=set(dependencies),'missing expanded producer dependencies')
    for relative,expected in dependencies.items():
        path=(ROOT/relative).resolve();require(path.is_relative_to(ROOT/'tools'),'foreign producer dependency path')
        require(file_sha(path)==expected,'stale expanded dependency identity')
    decision=compose(plan,generic,producer(obj,contract,requested_dependency_retention=plan['retained_sections']),contract)
    if decision.get('structural_composition_complete')is True:
        decision.update(serialization_plan_ready=True,source_files_verified=True,live_driver_approved=False,blockers=[])
    return decision


def serialize_authored_component(raw,plan,decision):
    require(sha(raw)!=NATIVE_OBJECT,'authored-only helper rejects real IOTask object')
    return _serialize_verified_component(raw,plan,decision)


def _serialize_verified_component(raw,plan,decision):
    require(sha(raw)==plan['object_sha256'] and decision.get('serialization_plan_ready')is False and decision.get('synthetic_serialization_plan_ready')is True and decision.get('plan_sha256')==digest(plan),'synthetic composed selection missing/stale')
    proof=decision.get('proof');require(isinstance(proof,dict),'complete composition proof missing')
    verified=compose(plan,proof['generic'],proof['recomputed'],proof['contract'])
    require(decision==verified and decision.get('live_driver_approved')is False,'forged/stale synthetic decision')
    require(all(plan.get(k)is False and decision.get(k)is False for k in FALSE),'runtime/provider approval forbidden')
    named=coff.namespace(raw,[tuple(x) for x in plan['namespace']])
    intermediate,maps=coff.serialize(named,plan['retained_sections'],plan['retained_primary_indices'],plan['undefined_conversions'])
    obj=coff.parse(intermediate);sx=maps['section_map'][16];row=struct.unpack_from('<8sIIIIIIHHI',intermediate,20+(sx-1)*40);payload_offset=row[4]
    original_index=struct.unpack_from('<I',intermediate,payload_offset)[0];require(original_index==19,'SafeSEH source record changed')
    output_index=maps['symbol_map'][19];section_symbol=next(i for i,s in coff.parse(named)['symbols'].items() if s['section']==16 and s['storage']==3 and s['aux_count']==1)
    aux_index=maps['auxiliary_map'][section_symbol+1];checksum_offset=obj['symbol_pointer']+aux_index*18+8
    out=bytearray(intermediate);struct.pack_into('<I',out,payload_offset,output_index);struct.pack_into('<I',out,checksum_offset,0);out=bytes(out)
    permitted=set(range(payload_offset,payload_offset+4))|set(range(checksum_offset,checksum_offset+4))
    require(len(out)==len(intermediate) and all(a==b or i in permitted for i,(a,b) in enumerate(zip(intermediate,out))),'undocumented byte mutation')
    final=coff.parse(out);require(final['sections'][sx]['payload']==struct.pack('<I',output_index),'wrong rebased registry')
    require(final['symbols'][output_index]['name']==coff.parse(named)['symbols'][19]['name'] and final['symbols'][output_index]['section']==maps['section_map'][4] and final['symbols'][output_index]['value']==8 and final['symbols'][output_index]['storage']==3,'registry no longer targets owned local handler')
    # Restore only the two documented metadata fields and use the frozen verifier.
    restored=bytearray(out);restored[payload_offset:payload_offset+4]=intermediate[payload_offset:payload_offset+4];restored[checksum_offset:checksum_offset+4]=intermediate[checksum_offset:checksum_offset+4]
    coff.verify_selection(named,bytes(restored),maps)
    with tempfile.TemporaryDirectory(prefix='eh-independent-reparse-') as folder:
        path=Path(folder)/'component.obj';path.write_bytes(out)
        from coff_inventory import Coff as IndependentCoff
        independent=IndependentCoff(path)
        require(len(independent.sections)==len(final['sections']) and len(independent.symbols)==len(final['symbols']),'independent reparse count differs')
        for old,new in maps['section_map'].items():require(independent.sections[new]['flags']==final['sections'][new]['flags'] and independent.sections[new]['payload_sha256']==sha(final['sections'][new]['payload']),'independent section reparse differs')
    root_name=next(n for i,n in plan['namespace'] if i==8);require(coff.exports(out)==[root_name],'frame helpers or storage exported')
    report=dict(schema_version=1,kind='fnv-parent-eh-component-serialization',policy_id=POLICY,input_sha256=sha(raw),named_sha256=sha(named),intermediate_sha256=sha(intermediate),output_sha256=sha(out),plan_sha256=digest(plan),decision_sha256=digest(decision),maps=maps,safeseh=dict(source_section=16,output_section=sx,old_index=19,new_index=output_index,checksum_policy='zero only rewritten registry section checksum',payload_field_offset=payload_offset,checksum_field_offset=checksum_offset),independent_reparse=True,exported_symbols=[root_name],unresolved_obligations=plan['external_obligations'],**FALSE)
    return out,report


def serialize_component(raw,plan,decision):
    """Future supported emission path: revalidate the complete current composition.

    No CLI/collector calls this function. Actual emission needs separate root go.
    """
    proof=decision.get('proof');require(isinstance(proof,dict),'complete composition proof missing')
    current=recompute_and_compose(plan,proof['generic'],coff.parse(raw),proof['contract'])
    require(current==decision and current.get('source_files_verified')is True and current.get('serialization_plan_ready')is True,'forged/stale source-verified decision')
    # Reuse the authored mechanics only after full source-bound recomputation.
    structural=compose(plan,proof['generic'],proof['recomputed'],proof['contract'])
    return _serialize_verified_component(raw,plan,structural)


def main(argv=None):
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('--policy',type=Path,default=ROOT/'runtime/code-pools/iotask69-eh.json');ap.add_argument('--policy-sha256',required=True)
    args=ap.parse_args(argv);require(file_sha(args.policy)==args.policy_sha256,'policy hash changed');p=json.loads(args.policy.read_text());validate_policy(p)
    # There is intentionally no production emission switch while the actual expanded
    # observer is unavailable. This status is not a real IOTask graph observation.
    require(p.get('actual_expanded_producer_available')is False,'new producer requires a separate source/policy review')
    result=compose({},None,None);result['actual_native_observation_performed']=False;result['serialization_performed']=False
    print(json.dumps(result,sort_keys=True));return 2

if __name__=='__main__':raise SystemExit(main())
