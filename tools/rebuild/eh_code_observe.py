"""Fixed IOTask metadata collector. No compiler, linker or object emission API."""
from __future__ import annotations
import argparse
import copy
import gzip
import hashlib
import json
import os
from pathlib import Path
import sys
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'tools'))
import build_and_match as oracle
import eh_code_closure as eh
from runtime_code_inventory import BindingReader,check_unit,public_metadata
from coff_inventory import reconcile_recipes
from runtime_gaps import read_bound

CURRENT_HEADERS={'src/bsmain/bstaskmanager.h':'fa46a5e973566bd9e5c5943b88d9c50f3140b17c7328b4640f9f0cbc2cfb0a9e',
                 'src/bsmain/bstaskmanager_types.h':'283383384aa6be21f29507f2e807e844473e6a505804f44cc87261b73d206507'}
TOOLS=('tools/rebuild/eh_code_observe.py','tools/rebuild/eh_field_witness.py','tools/rebuild/eh_code_closure.py','tools/rebuild/expanded_root_code_closure.py',
       'tools/rebuild/root_code_closure.py','tools/rebuild/coff_code_archive.py','tools/rebuild/coff_inventory.py',
       'tools/rebuild/runtime_code_inventory.py','tools/rebuild/runtime_gaps.py','tools/rebuild/data_plan.py',
       'tools/rebuild/import_plan.py','tools/rebuild/runtime_bind_plan.py','tools/rebuild/runtime_code_pool.py','tools/build_and_match.py','tools/compare.py','tools/function_spans.py')
require=eh.require


def parse_tools(values):
    result={}
    for value in values:
        name,sep,h=value.partition('=')
        require(sep and name in TOOLS and name not in result and len(h)==64 and all(c in '0123456789abcdef' for c in h),'invalid/duplicate tool pin')
        result[name]=h
    require(set(result)==set(TOOLS),'complete independently supplied source-review tool pins required')
    return result


def bind_image_gate(proof,observations):
    expected=proof['inputs']['image_check_sha256']
    require(isinstance(expected,str) and len(expected)==64 and all(c in '0123456789abcdef' for c in expected),'missing image gate identity')
    observations[ROOT/'build/image_check.json']=expected


def stable(observations,index):
    require(not index.exists(),'optional function index appeared')
    for path,h in observations.items():require(eh.file_sha(path)==h,'authenticated input/tool drift')


def external_base_candidates(obj,policy,reference,parent_address,pieces):
    """Address filter only; no binding proof or access to collector index state."""
    import struct
    candidates=set();locations={3:int(parent_address,16),4:pieces[0][0]}
    for section_index in (3,4):
        original=reference.read(locations[section_index],obj['sections'][section_index]['size'])
        for offset,symbol_index,kind in obj['sections'][section_index]['relocs']:
            if str(symbol_index) not in policy['external_identities']:continue
            addend=struct.unpack_from('<i' if kind==20 else '<I',obj['sections'][section_index]['payload'],offset)[0]
            target=locations[section_index]+offset+4+struct.unpack_from('<i',original,offset)[0] if kind==20 else struct.unpack_from('<I',original,offset)[0]
            candidates.add((target-addend)&0xffffffff)
    return candidates


def external_context(obj,policy,parent_fields,recipe,names,inferred,shared_rows,eh_field_context=None,generated_witnesses=None):
    mappings=dict(names);mappings.update({k:int(v,0) for k,v in recipe.get('symbols',{}).items()});mappings.update(inferred)
    result={};evidence=[]
    for text,identity in sorted(policy['external_identities'].items(),key=lambda kv:int(kv[0])):
        index=int(text);name=obj['symbols'][index]['name'];bases=set()
        for row in parent_fields:
            if row['coff_relocation']['symbol_index']==index:
                require(row['proof_consistency']=='EXACT_OWN_SOURCE_RESOLUTION','unproved own parent external')
                bases.add(int(row['derived_source_symbol_base_va'],16))
        if name in mappings:bases.add(mappings[name])
        require(len(bases)==1,'missing or conflicting exact source/recipe/EH name identity')
        base=bases.pop();result[text]=dict(base=base,**identity,proof_consistency='EXACT_OWN_SOURCE_RESOLUTION')
        # Shared observations must not contradict the canonical domain. Unknown
        # classifications remain unresolved, never inferred from nearest addresses.
        witnesses=[]
        for row in shared_rows.get(base,[]):
            cls=row['classification'];cr=row['coff_relocation'];name=cr['symbol']
            if cls=='SELECTED_CODE_ENTRY' and cr['symbol_type']==32:
                observed=('code','code','ordinary-function')
            elif cls=='ORIGINAL_IMAGE_DATA_REQUIRES_CANONICAL_OWNER' and cr['symbol_type']==0:
                kind='security-cookie' if name=='___security_cookie' else 'vtable-view' if name.startswith('??_7') else None
                require(kind is not None,'unknown shared data subtype')
                observed=('data','data',kind)
            elif cls=='EXPLICIT_NORMAL_CRT_CONTRACT_CANDIDATE' and cr['symbol_type']==32:
                kinds={'___CxxFrameHandler3':'cxx-frame-handler','@__security_check_cookie@4':'security-cookie-check'}
                require(name in kinds,'unknown shared CRT subtype')
                observed=('crt-contract','code',kinds[name])
            else:raise ValueError('unsupported or ambiguous exact shared witness classification: '+hex(base)+' '+name+' '+cls)
            require(row['proof_consistency']=='EXACT_OWN_SOURCE_RESOLUTION' and observed==(identity['role'],identity['semantic_domain'],identity['contract_kind']),'conflicting shared canonical domain/subtype')
            witnesses.append(eh.digest(row))
        # Recipe-only/inferred EH names have bounded native replay evidence, but
        # are not allowed to masquerade as a separately observed shared binding.
        if not witnesses and index==20 and eh_field_context is not None:
            from eh_field_witness import build
            proof=build(obj,eh_field_context['reference'],eh_field_context)
            require((proof['base'],proof['role'],proof['semantic_domain'],proof['contract_kind'])==(base,identity['role'],identity['semantic_domain'],identity['contract_kind']),'generated handler witness identity conflicts')
            witnesses.append(eh.digest(proof));result[text]['proof_consistency']=proof['proof_consistency']
            require(generated_witnesses is not None,'generated witness provenance sink required');generated_witnesses.append(proof)
        require(witnesses,'shared base identity lacks independent binding witness: '+hex(base)+' '+name)
        evidence.append(dict(base=base,**identity,identity_consistency='EXACT_BASE_ROLE_RESOLUTION'))
    return result,evidence


def private_outputs(output):
    private=(ROOT/'build/rebuild').resolve()
    out=Path(output).resolve();journal=out.with_suffix(out.suffix+'.progress.jsonl').resolve()
    require(out.is_relative_to(private) and journal.is_relative_to(private),'observation outputs must remain in private build/rebuild tree')
    return out,journal


def publish_metadata(out,result,observations,function_index_path):
    """Exclusive publication; failed final stability leaves only failure journal."""
    owned=None
    try:
        with out.open('x',encoding='utf-8') as target:
            identity=os.fstat(target.fileno());owned=(identity.st_dev,identity.st_ino)
            json.dump(result,target,sort_keys=True);target.write('\n');target.flush();os.fsync(target.fileno())
        stable(observations,function_index_path)
    except BaseException:
        if owned is not None and out.exists():
            current=out.stat()
            if (current.st_dev,current.st_ino)==owned:out.unlink()
        raise


def collect(args):
    policy_path=ROOT/'runtime/code-pools/iotask69-eh.json'
    require(eh.file_sha(policy_path)==args.policy_sha256,'policy drift')
    policy=json.loads(policy_path.read_text());eh.validate_policy(policy)
    expected=policy['inputs'];paths={k:Path(getattr(args,k)).resolve() for k in expected}
    data={k:read_bound(paths[k],h) for k,h in expected.items()}
    manifest,pv,recipes,selection,binding=[data[k] for k in ('manifest','retained','recipes','selection','binding')]
    require(reconcile_recipes(manifest,paths['recipes'])['verified'],'recipe reconciliation differs')
    require(all(pv[k]is True for k in ('retained_verification_pass','function_byte_verification_pass','global_listed_eh_coverage_pass','original_oracle_parity_pass','evidence_stable')),'retained gate differs')
    require(pv['inputs']['retained_manifest_sha256']==expected['manifest'] and pv['inputs']['recipe_sha256']==expected['recipes'],'retained provenance differs')
    require(all(binding['inputs'][k]==expected[k] for k in ('manifest','retained','selection','recipes')) and binding['inputs']['reference']==pv['inputs']['image_sha256'],'binding provenance differs')
    require(pv['inputs']['function_index_present']is False and selection['function_index_present']is False,'optional index state differs')
    out,journal=private_outputs(args.out);image=Path(args.image).resolve();detail=Path(args.binding_details).resolve()
    observations={paths[k]:h for k,h in expected.items()};observations[policy_path]=args.policy_sha256
    observations.update({image:pv['inputs']['image_sha256'],detail:binding['details_sha256']})
    from eh_field_witness import AUDIT_SHA256
    audit_path=Path(args.handler_field_evidence).resolve();audit=read_bound(audit_path,AUDIT_SHA256);observations[audit_path]=AUDIT_SHA256
    bind_image_gate(pv,observations)
    for name,h in CURRENT_HEADERS.items():observations[ROOT/name]=h
    tools=parse_tools(args.expected_tool)
    for name,h in tools.items():observations[ROOT/name]=h
    require(tools['tools/rebuild/runtime_bind_plan.py']==binding['implementation_sha256'],'binding producer source identity differs')
    for name,h in pv['inputs']['tools_sha256'].items():
        path=(ROOT/name).resolve();require(path.is_relative_to(ROOT/'tools'),'foreign retained tool path')
        require(path not in observations or observations[path]==h,'conflicting producer pin');observations[path]=h
    units=[u for u in manifest['units'] if u['recipe_index']==69];rows=[r for r in pv['units'] if r['recipe_index']==69]
    require(len(units)==len(rows)==1,'fixed native unit absent or duplicate');unit,row=units[0],rows[0];check_unit(unit,row)
    require(unit['recipe_id']==policy['recipe_id'] and unit['object_sha256']==policy['object_sha256'] and unit['source_sha256']==policy['source_sha256'],'fixed native identities differ')
    obj_path=(paths['manifest'].parent/manifest.get('object_root_relative','.')/unit['object']).resolve();source=(ROOT/unit['source']).resolve()
    require(source.is_relative_to(ROOT),'foreign source path');observations.update({obj_path:unit['object_sha256'],source:unit['source_sha256']})
    require(out!=journal and not out.exists() and not journal.exists() and out not in observations and journal not in observations,'exclusive non-input metadata outputs required')
    function_index_path=ROOT/'build/function_index.json';stable(observations,function_index_path)
    out.parent.mkdir(parents=True,exist_ok=True)
    with journal.open('x',encoding='utf-8') as progress:
        def note(value):progress.write(json.dumps(public_metadata(value),sort_keys=True)+'\n');progress.flush();os.fsync(progress.fileno())
        note(dict(state='authenticated-inputs',object_sha256=unit['object_sha256']))
        try:
            raw=obj_path.read_bytes();obj=eh.coff.parse(raw);pe=oracle.Pe(image)
            require(eh.sha(raw)==unit['object_sha256'] and eh.sha(pe.data)==pv['inputs']['image_sha256'] and oracle.image_ok(pe)[0],'loaded native/reference identity differs')
            parent=policy['selected']['original_address'];full_recipe=unit['recipe'];names=oracle.recipe_names(recipes['units'])
            core_recipe=copy.deepcopy(full_recipe);core_recipe['functions']=[f for f in full_recipe['functions'] if f['address']==parent and f['symbol']==policy['selected']['symbol']]
            proofs=[p for p in row['verified_functions'] if p['address']==parent and p['symbol']==policy['selected']['symbol']]
            require(len(proofs)==1,'unique verified parent missing')
            parent_pieces=[p for p in row['eh_sections'] if p[3]==parent]
            pieces,inferred,errors=oracle.eh_sections(oracle.Coff(obj_path),pe,core_recipe,proofs,names)
            inferred_names={name for p in parent_pieces for name in p[4]}
            require(pieces==parent_pieces and not errors and {k:'0x%08x'%v for k,v in inferred.items()}=={k:v for k,v in row['eh_inferred'].items() if k in inferred_names},'original bounded parent EH replay differs')
            # Keep only the seven requested bases while streaming full saved rows.
            # These are candidate-filter addresses, not adopted identity evidence.
            candidates=external_base_candidates(obj,policy,pe,parent,parent_pieces)
            shared={};bucket=None
            with gzip.open(detail,'rt',encoding='utf-8') as stream:
                reader=BindingReader(stream,binding['summary'],selection['selections'])
                for u in manifest['units']:
                    group=reader.take(u['recipe_index'])
                    if u['recipe_index']==69:bucket=group.get(parent)
                    for b in group.values():
                        for field in b['fields']:
                            base=field.get('derived_source_symbol_base_va')
                            if base and int(base,16) in candidates:shared.setdefault(int(base,16),[]).append(field)
                census=reader.finish()
            require(bucket is not None and len(bucket['fields'])==5 and bucket['missing_fields']==[],'complete parent field evidence unavailable')
            generated_witnesses=[];field_context=None
            # Only the exact missing physical20 field may use this family. Read
            # bounded PE loader-relocation metadata, never scan target code.
            from data_plan import Pe as MetadataPe
            metadata_reader=MetadataPe(image)
            try:
                section=metadata_reader.section(0xec3d33-metadata_reader.base,1,required=True)
                field_context=dict(parent_proof=proofs[0],pieces=parent_pieces,recipe=full_recipe,recipes=recipes['units'],names=names,inferred=inferred,
                    object_sha256=unit['object_sha256'],reference_sha256=pv['inputs']['image_sha256'],recipes_sha256=expected['recipes'],audit=audit,reference=pe,
                    original_highlow_sites=[metadata_reader.base+site for site in metadata_reader.relocations()],
                    target_section=dict(executable=section['executable'],original_base=metadata_reader.base+section['rva'],original_end=metadata_reader.base+section['rva']+section['extent']))
            finally:metadata_reader.close()
            bindings,ledger=external_context(obj,policy,bucket['fields'],full_recipe,names,inferred,shared,field_context,generated_witnesses)
            # Private comparison bindings preserve the proved original destinations.
            core_recipe.setdefault('symbols',{}).update({obj['symbols'][int(i)]['name']:hex(b['base']) for i,b in bindings.items()})
            handler=next(p for p in parent_pieces if p[1]-p[0]==27);core_recipe['symbols'][obj['symbols'][19]['name']]=hex(handler[0])
            context=dict(object_sha256=unit['object_sha256'],source_sha256=unit['source_sha256'],inputs=expected,fields_complete=True,missing_fields_complete=True,missing_fields=[],parent_proof=proofs[0],eh_pieces=parent_pieces,
                data_boundary_proof=dict(symbol_index=16,original_base='0x01016c10',role='data',semantic_domain='data',contract_kind='vtable-view',exact=True,storage_defined=False),
                external_bindings=bindings,shared_base_identities=ledger,core_unit=core_recipe,core_names=names,generated_eh_field_witnesses=generated_witnesses,reference_identity_sha256=pv['inputs']['image_sha256'])
            plan=eh.observe_component(raw,policy,context,pe)
            plan['generated_eh_field_witnesses']=generated_witnesses
            contract=dict(recipe_id=unit['recipe_id'],roots=[policy['selected']],export_policy='selected-code-only-no-source-initializers-v1',verified_match=True,fields_complete=True,missing_fields_complete=True,unit_proofs_complete=True,
                fields=bucket['fields'],missing_fields=[],generated_eh_field_witnesses=copy.deepcopy(generated_witnesses),parent_eh=parent_pieces,unit_verified_functions=row['verified_functions'],omission_field_proofs=[],
                expanded_retention_contract=eh.expanded_contract(plan),provenance=dict(object_sha256=unit['object_sha256'],source_sha256=unit['source_sha256'],recipe_id=unit['recipe_id'],recipe_index=69,
                    recipe_unit_sha256=row['recipe_unit_sha256'],recipe_manifest_sha256=expected['recipes'],producer_manifest_sha256=expected['manifest'],retained_proof_sha256=expected['retained'],selection_sha256=expected['selection'],
                    binding_sha256=expected['binding'],binding_details_sha256=binding['details_sha256'],reference_identity_sha256=pv['inputs']['image_sha256'],observer_sha256=tools['tools/rebuild/expanded_root_code_closure.py'],
                    optional_function_index_present=False,dependency_tools_sha256=tools,generated_eh_field_witnesses_sha256=eh.digest(generated_witnesses),current_header_context_sha256=CURRENT_HEADERS,historical_header_compile_inputs_verified=False,binding_row_references=bucket['row_identities']))
            import expanded_root_code_closure as producer
            generic=producer.observe_requested_dependency_retention(obj,contract,requested_dependency_retention=plan['retained_sections'])
            decision=eh.recompute_and_compose(plan,generic,obj,contract)
            stable(observations,function_index_path)
            result=public_metadata(dict(schema_version=1,kind='fnv-iotask-eh-metadata-observation',status='metadata-only',inputs=dict(policy_sha256=args.policy_sha256,**expected),tools_sha256=tools,binding_census=census,
                plan=plan,expanded_observation=generic,composition=decision,input_stability=True,optional_function_index_present=False,emission_performed=False,**eh.FALSE))
            publish_metadata(out,result,observations,function_index_path)
            note(dict(state='complete',output_sha256=eh.file_sha(out)));return result
        except BaseException as error:
            note(dict(state='failed',error_type=type(error).__name__,reason=public_metadata(str(error)),error_message_sha256=eh.sha(str(error).encode()),output_published=out.exists()));raise


def main(argv=None):
    parser=argparse.ArgumentParser(description=__doc__)
    for name in ('manifest','retained','recipes','selection','binding','binding-details','handler-field-evidence','image','out'):parser.add_argument('--'+name,type=Path,required=True)
    parser.add_argument('--policy-sha256',required=True);parser.add_argument('--expected-tool',action='append',required=True)
    result=collect(parser.parse_args(argv));print(json.dumps(dict(status=result['status'],emission_performed=False)));return 0

if __name__=='__main__':raise SystemExit(main())
