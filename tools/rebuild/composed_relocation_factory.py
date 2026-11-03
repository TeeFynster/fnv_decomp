"""Explicit typed-composition factory. Original negative certificates stay negative."""
from __future__ import annotations
import argparse
from collections import Counter
import gzip
import json
import os
import re
from pathlib import Path
import struct
import sys
import time
import composed_relocation_projection as core
import prepared_code_exclusions as prepared
import ordinary_relocation_factory as prior
from data_plan import Pe as MetadataPe

base=prior.base
ROOT=base.ROOT
POLICY='typed-composed-relocation-factory-v1'
OWNED=('tools/rebuild/composed_relocation_factory.py','tests/rebuild/test_composed_relocation_factory.py',
       'docs/rebuild/COMPOSED-RELOCATION-FACTORY.md')
DATA_ADDRESSES={'0x0040f6e0','0x0049ff80','0x005e0830','0x00a819e0','0x00c3bb90','0x00c3bbe0',
    '0x00c3bc30','0x00c3bc80','0x00c3a6d0','0x00c3bd30','0x008026b0'}
LABEL_ADDRESS='0x00706320'
LABEL_EXTRAS={'central_receipt_sha256','central_record_sha256','input_stability','lane','lane_record_ordinal',
              'lane_sha256','optional_function_index_present','producer_sha256','typed_witnesses'}
PINS={**prior.PINS,'tools/rebuild/ordinary_relocation_factory.py':'f431d8599d7e91e2c67ed5570ccd067bdf80fbd8a92ee4c6daa3473cc26c928b',
    'tools/rebuild/prepared_code_exclusions.py':'c53cdc375872ec1cf58dbf2da1dc3823d8e6d00ec9822883b333b4b4e96e4774',
    'tools/rebuild/composed_relocation_projection.py':'ae434691badad5ad41eb6c2b65a7dad026c71b7f80512e8f2cc3dcdbcaff96bc',
    'tools/rebuild/root_certificate_composer.py':'9d24c9d522cd62618e4335dee10799c8bd1954822382ade548a4c2ea8fb76b7f',
    'tools/rebuild/local_label_projection.py':'57cecc88c2f2aaccdf87ca8605fe84461c31a4c391884d503240329636e5f826',
    'tools/rebuild/ordinary_initialized_data_omission.py':'1a0e8aa2271218f59c11497c1363b41f099bb259791e19adac7d80718e7a5d7b',
    'tools/rebuild/data_plan.py':'e013ed5f217f9beeeaf571d089a36df22b645559063e826554179cea506f5bf8'}
ARTIFACTS={
 'prepared_manifest':('prepared-code-exclusions-v1/manifest.json','5bca56fbe6ae3967c35b9984d01e8312547f2411127c75712d6bd4ae33f3f2de'),
 'prepared_receipt':('prepared-code-exclusions-v1/receipt.json','19bbdce2e07d82ec1a623444c7b45714c6a67535921fb01a6f2effbb0ddfacae'),
 'prepared_review':('code-lane-02/prepared-exclusions-outcome-review-v1.json','45f3e3f96bf061957193450c76cf571765e524119713f829ba9ac176daaa0d30'),
 'data_receipt':('initialized-data-omission-observation-v2/receipt.json','46a7c8b274f4247ea5f65648a5534b08b87849f5913ac50102860d0e4c638aa8'),
 'data_details':('initialized-data-omission-observation-v2/witnesses.jsonl.gz','4322a3a5770ee43ea92df02ab2b33de819cee24e1e082e391fd63977f06f5f0f'),
 'data_selection_review':('code-lane05-synthetic-projection-v1/actual-DATA11-selection-audit-v2.json','7bd3dd70b4576fb9f6365c9bad43330dbcfcc422b96f7220197036c50dfbc58c'),
 'data_composer_review':('initialized-data-omission-observation-v2/composer-outcome-review.json','48a7e197c4a56053823c1dd6e9cd553ff82795ccdad4dc4e00732abb61694d77'),
 'label_witness':('code-lane01-analysis-v1/typed-local-label-omission-witness-v3.json','e53955164685a9093740d270f8f7e065193e8309b81eb9a1555a4e10dd87154c'),
 'label_observation':('code-lane01-analysis-v1/original-label-observation-v3.json','44a37ecbeabc3f8af1c964a37efee24a82665f8fbeeae2fc53a3e4549665a269'),
 'label_review':('code-lane06-local-label-observation-v3-outcome-review-v2.json','6119a539338094690c063196be0b536a9312fbf158cce5fa4783ee0271704f71'),
 'label_source_review':('code-lane06-local-label-v3-request-v5-review.json','0185da9cd13f2be89d7592790f934189bb2f4c837994970d93315ee98989b28f'),
 'label_composition':('root-certificate-composer-label-v1/composed.json','ec4488ae7e53e772e5506764831da766cfe2771a085ed360b8043c77aac8d3c0')}
FALSE=dict(prior.FALSE,typed_root_witnesses_consumed=True,namespace_approved=False,full_serialization_eligible=False)
require=base.require
digest=base.digest


def join_data_rows(receipt,rows,central,requests):
    """Authenticate every saved DATA view against original central summary hashes.

    Full original contracts are opened once by the operational driver later.
    This metadata join is not a fresh object/composition observation.
    """
    require(isinstance(receipt,dict) and isinstance(rows,list) and isinstance(central,dict) and isinstance(requests,dict), 'DATA envelope schema')
    require(all(type(receipt.get(k)) is int for k in ('views','objects','passed_views','discharged_blockers')) and
            receipt['views']>0 and receipt['objects']>0 and 0<=receipt['passed_views']<=receipt['views'] and
            receipt['discharged_blockers']>=0, 'DATA receipt count schema')
    require(receipt['status']=='observed-typed-witnesses-only' and receipt['inputs_stable'] is True and
            receipt['original_certificates_unchanged'] is True and receipt['composer_used'] is True and
            receipt['central_receipt_sha256']==core.composer.CENTRAL_PIN and len(rows)==receipt['views'], 'DATA observation incomplete/unstable')
    require(all(receipt[k] is False for k in ('provider_selected','runtime_eligible','emission_performed','compiler_performed',
            'executable_link_performed','game_execution_performed','native_operations_performed','original_data_ownership_proved','ABI_verified')), 'DATA observation scope promoted')
    index={(r['lane'],r['lane_record_ordinal']):r for r in central['observations']}
    require(len(index)==len(central['observations']),'duplicate central locator')
    seen=set();recipes=set();selected={};passed=0;discharged=0
    row_keys={'lane','ordinal','event','recipe_id','requested_roots','central_record_sha256','contract_identity_sha256',
              'original_certificate_sha256','witness','witness_sha256','composition','composition_sha256'}
    for row in rows:
        require(isinstance(row,dict) and set(row)==row_keys and type(row['lane']) is int and type(row['ordinal']) is int and
                row['lane']>0 and row['ordinal']>0 and row['event'] in ('SINGLE_ROOT_OBSERVATION','RECIPE_ROOT_UNION_OBSERVATION'), 'exact DATA view schema required')
        key=(row['lane'],row['ordinal']);summary=index.get(key)
        require(key not in seen and summary and summary['record_sha256']==row['central_record_sha256'] and
                summary['event']==row['event'] and summary['recipe_id']==row['recipe_id'], 'borrowed/duplicate DATA view locator')
        seen.add(key);recipes.add(row['recipe_id']);roots=row['requested_roots']
        require(isinstance(roots,list) and roots and all(isinstance(r,dict) and set(r)==base.ROOT_KEYS for r in roots), 'DATA physical root schema')
        addresses=[r['original_address'] for r in roots]
        require(len(set(addresses))==len(addresses),'duplicate DATA root scope')
        require(addresses==summary['roots'] and all(requests.get(r['original_address'])==r for r in roots),'DATA root physical identity differs')
        composition=row['composition'];original=composition['base_certificate'];witness=row['witness']
        require(digest(original)==row['original_certificate_sha256']==summary['certificate_sha256']==composition['base_certificate_sha256'] and
                original['contract_identity_sha256']==row['contract_identity_sha256']==witness['contract_identity_sha256']==composition['contract_identity_sha256'] and
                original['closure_observed'] is False and original['blockers'] and composition['original_certificate_unchanged'] is True,
                'DATA changed original negative certificate/contract')
        require(digest(witness)==row['witness_sha256'] and digest(composition)==row['composition_sha256'] and
                witness['original_certificate_sha256']==digest(original) and witness['kind']=='typed-initialized-data-omission-witness' and
                witness['policy_id']==core.composer.initialized.POLICY and composition['policy_id']==core.composer.POLICY and
                composition['kind']=='composed-root-omission-observation', 'DATA witness/composition hash or policy differs')
        require(original['recipe_id']==row['recipe_id'] and original['roots']==[{k:r[k] for k in base.NATIVE_KEYS} for r in roots], 'DATA negative scope differs')
        require(witness['recipe_id']==composition['recipe_id']==row['recipe_id'] and
                all(r['recipe_id']==row['recipe_id'] and r['object_sha256']==witness['object_sha256']==composition['object_sha256'] and
                    r['source_sha256']==witness['source_sha256']==composition['source_sha256'] for r in roots), 'DATA witness source/object/recipe scope differs')
        require(all(witness[k] is False for k in core.composer.initialized.FALSE),'typed DATA witness scope promoted')
        require(all(composition[k] is False for k in core.composer.FALSE),'composed DATA scope promoted')
        require(all(composition[k]==original[k] for k in ('roots','retained_section_indices','retained_primary_indices','retained_physical_slots')) and
                composition['base_policy_id']==original['policy_id'] and composition['base_closure_observed']==original['closure_observed'] and
                composition['base_graph_observation_complete']==original['graph_observation_complete'], 'DATA composition changed original scope')
        require(composition['physical_graph_sha256']==digest(dict(sections=original['sections'],symbols=original['symbols'],edges=original['edges'])) and
                composition['provenance_sha256']==digest(original['provenance']), 'DATA original physical graph/provenance differs')
        require(type(witness['witness_complete']) is bool and isinstance(witness['rows'],list) and witness['rows'] and
                isinstance(witness['requested_sections'],list) and all(type(i) is int for i in witness['requested_sections']) and
                witness['requested_sections']==sorted(set(witness['requested_sections'])) and
                [r['section'] for r in witness['rows']]==witness['requested_sections'] and
                all(type(r['approved']) is bool and r['approved']==(not r['blockers']) for r in witness['rows']) and
                witness['witness_complete']==all(r['approved'] for r in witness['rows']), 'DATA requested witness rows incomplete/inconsistent')
        witness_ids=witness['discharge_blocker_ids']
        require(isinstance(witness_ids,list) and len(witness_ids)==len(set(witness_ids)) and
                witness_ids==[bid for r in witness['rows'] for bid in r['discharge_blocker_ids']] and
                all(r['approved'] or not r['discharge_blocker_ids'] for r in witness['rows']), 'DATA row discharge evidence differs')
        require(composition['witness_observations']==[dict(witness_sha256=row['witness_sha256'],policy_id=witness['policy_id'],
                    discharge_blocker_ids=witness_ids)], 'DATA composition borrowed witness observation')
        done=composition['discharged_blockers'];remaining=composition['remaining_blocker_occurrences']
        require(isinstance(done,list) and isinstance(remaining,list) and type(composition['base_blocker_occurrences']) is int and
                composition['base_blocker_occurrences']==len(original['blockers']), 'DATA blocker occurrence schema')
        done_ord=[];remaining_ord=[];done_ids=[]
        for item in done:
            require(isinstance(item,dict) and set(item)=={'base_blocker_ordinal','blocker','witness_sha256','witness_policy_id'} and
                    type(item['base_blocker_ordinal']) is int and 1<=item['base_blocker_ordinal']<=len(original['blockers']), 'DATA discharged occurrence schema')
            ordinal=item['base_blocker_ordinal'];blocker=original['blockers'][ordinal-1]
            require(item['blocker']==blocker and blocker['code']=='UNSUPPORTED_SECTION_SEMANTICS' and
                    item['witness_sha256']==row['witness_sha256'] and item['witness_policy_id']==witness['policy_id'], 'DATA discharged occurrence identity differs')
            done_ord.append(ordinal);done_ids.append(blocker['blocker_id'])
        for item in remaining:
            require(isinstance(item,dict) and set(item)=={'base_blocker_ordinal','blocker'} and type(item['base_blocker_ordinal']) is int and
                    1<=item['base_blocker_ordinal']<=len(original['blockers']) and
                    item['blocker']==original['blockers'][item['base_blocker_ordinal']-1], 'DATA remaining occurrence identity differs')
            remaining_ord.append(item['base_blocker_ordinal'])
        require(done_ord==sorted(set(done_ord)) and remaining_ord==sorted(set(remaining_ord)) and
                not(set(done_ord)&set(remaining_ord)) and sorted(done_ord+remaining_ord)==list(range(1,len(original['blockers'])+1)) and
                len(done_ids)==len(set(done_ids)) and set(done_ids)==set(witness_ids) and
                composition['remaining_blockers']==[r['blocker'] for r in remaining] and
                type(composition['composed_omission_complete']) is bool and composition['composed_omission_complete']==(not remaining), 'DATA blocker occurrence partition differs')
        passed+=int(witness['witness_complete']);discharged+=len(witness['discharge_blocker_ids'])
        if row['event']=='SINGLE_ROOT_OBSERVATION' and composition['composed_omission_complete'] is True:
            require(len(roots)==1 and witness['witness_complete'] is True and witness['rows'] and
                    all(r['approved'] is True for r in witness['rows']) and not composition['remaining_blockers'] and
                    not remaining and len(done_ord)==len(original['blockers']), 'partial DATA witness cannot authorize a root')
            address=addresses[0];require(address not in selected,'duplicate DATA singleton')
            selected[address]=dict(locator=key,central_record_sha256=row['central_record_sha256'],requested_root=roots[0],
                original_certificate_sha256=digest(original),contract_identity_sha256=row['contract_identity_sha256'],
                witnesses=[witness],saved_composition=composition,observation_record_sha256=digest(row))
    require(len(recipes)==receipt['objects'] and passed==receipt['passed_views'] and discharged==receipt['discharged_blockers'], 'complete DATA view census differs')
    return selected


def normalize_label_composition(saved,pure,central_record,witness,central):
    """Validate the exact documented envelope; never silently strip unknown keys."""
    require(set(saved)==set(pure)|LABEL_EXTRAS and not(set(pure)&LABEL_EXTRAS),'unknown/missing label composition envelope field')
    require(all(saved[k]==v for k,v in pure.items()),'saved label pure composition differs')
    require(saved['typed_witnesses']==[witness] and saved['central_receipt_sha256']==core.composer.CENTRAL_PIN and
            saved['central_record_sha256']==central_record['record_sha256'] and
            saved['lane']==central_record['lane'] and type(saved['lane']) is int and
            saved['lane_record_ordinal']==central_record['ordinal'] and type(saved['lane_record_ordinal']) is int and
            saved['lane_sha256']==central['lane_artifacts'][str(saved['lane'])]['sha256'] and
            saved['producer_sha256']==PINS['tools/rebuild/root_certificate_composer.py'] and
            saved['input_stability'] is True and saved['optional_function_index_present'] is False, 'label operational envelope identity differs')
    return pure


class SnapshotPe(MetadataPe):
    """Existing strict PE metadata parser reads the verified immutable buffer."""
    def __init__(self,path,loaded):
        self.verified_buffer=loaded.data
        super().__init__(path)
        require(self.length==len(self.verified_buffer),'reference metadata extent changed')
    def read(self,offset,size):
        require(type(offset) is int and type(size) is int and offset>=0 and size>=0 and offset+size<=len(self.verified_buffer),'verified PE buffer read bound')
        return self.verified_buffer[offset:offset+size]


def audit_original_fields(pe,highlow,rows):
    facts={}
    for row in rows:
        relocation=row['coff_relocation'];kind=relocation['kind'];field=int(row['original_field_va'],16)
        require(kind in (6,20) and type(row['original_operand']) is int and 0<=row['original_operand']<=0xffffffff, 'original field metadata type')
        rva=field-pe.base;section=pe.section(rva,4,required=True)
        require(section['executable'] and int.from_bytes(pe.read_rva(rva,4,allow_code=True),'little')==row['original_operand'], 'fresh original operand/code scope differs')
        require((field in highlow) if kind==6 else (field not in highlow),'fresh original HIGHLOW correlation differs')
        target=row['original_operand'] if kind==6 else (row['original_operand']+field+4)&0xffffffff
        require(target==int(row['exact_original_target_va'],16),'fresh original target differs')
        fact=(kind,row['original_operand'],target)
        require(field not in facts or facts[field]==fact,'inconsistent duplicate original field facts');facts[field]=fact
    return facts


def highlow_sites(values):
    require(isinstance(values,list) and all(isinstance(v,str) and re.fullmatch('0x[0-9a-f]{8}',v) for v in values),
        'exact canonical original HIGHLOW address schema')
    result={int(v,16) for v in values};require(len(result)==len(values),'duplicate original HIGHLOW sites')
    return result


def verify_member(raw,contract,negative,witnesses,composed,roots,providers,exports,original_path,stage_path,pe,recipe):
    require(len(roots)==1,'singleton original comparison scope')
    contracts=[dict(selected={k:roots[0][k] for k in base.NATIVE_KEYS})]
    before=base.bulk.compare_functions(original_path,pe,contracts,recipe)
    output,projection=core.project_member(raw,contract,negative,witnesses,composed,roots,providers,
        existing_exports=exports,policy_id=core.POLICY)
    base.pool.fsynced(Path(stage_path),output);base.bulk.strict_reparse(Path(stage_path),output)
    after=base.bulk.compare_functions(stage_path,pe,contracts,recipe,
        dict(bindings=projection['namespace_bindings'],comparison_base_view=projection['comparison_base_view']))
    projection.update(before_comparison=before,after_comparison=after)
    return output,projection


def validate_prepared(manifest,expanded):
    records=manifest['records']
    pure=prepared.build_manifest([r for r in records if r['category']=='ordinary'],
        [r for r in records if r['category']=='application-candidate'],expanded,manifest['source_bindings'])
    extras={'provider_map_sha256','provider_map_review_sha256','source_epoch_artifacts','authority_state'}
    require(set(manifest)==set(pure)|extras and all(manifest[k]==v for k,v in pure.items()),'prepared manifest reconstruction differs')
    require(manifest['provider_map_sha256']==prior.MAP_PIN and manifest['provider_map_review_sha256']==prior.MAP_REVIEW[1] and
        manifest['source_epoch_artifacts']=={k:h for k,(_,h) in prepared.INPUTS.items()} and
        manifest['authority_state']=='requires-successful-producer-receipt-and-independent-outcome-review','prepared epoch authority differs')
    return set(pure['exclusion_names'])


def write_coverage(path,original_path,planned,prepared_manifest,wanted,emitted):
    names=set(prepared_manifest['exclusion_names']);counts=Counter();seen=set()
    with gzip.open(original_path,'rt') as original,Path(path).open('xb') as file:
        with gzip.GzipFile(fileobj=file,mode='wb',mtime=0) as out:
            for ordinal,line in enumerate(original,1):
                require(ordinal<=68657 and len(line)<=4*1024**2,'coverage bound')
                row=json.loads(line);a=row['original_address'];require(a not in seen,'duplicate historical owner');seen.add(a)
                identity={k:planned[a][k] for k in ('recipe_id','object_sha256','symbol_index')}
                require(row['physical_identity']==identity,'historical coverage/planned owner differs')
                prepared_name=base.pool.canonical(identity) in names
                require(a not in wanted or not prepared_name,'requested prepared logical owner cannot be replaced')
                state='NEW_TYPED_COMPOSED_PROJECTED' if a in emitted else 'REQUEST_BLOCKED' if a in wanted else 'NOT_REQUESTED'
                counts[state]+=1
                record=dict(original_address=a,physical_identity=identity,original_status=row['status'],
                    original_coverage_row=dict(ordinal=ordinal,sha256=digest(row)),prepared_namespace_present=prepared_name,
                    typed_projection_status=state,**FALSE)
                out.write((json.dumps(record,sort_keys=True,separators=(',',':'))+'\n').encode())
        file.flush();os.fsync(file.fileno())
    require(len(seen)==68657 and set(wanted)<=seen,'complete historical coverage differs')
    return dict(counts)


def review_gate(args,inputs):
    review=base.load_json(base.observe(args.review,args.review_sha256,inputs))
    require(review.get('kind')=='typed-composed-relocation-factory-review-v1' and review.get('schema_version')==1 and
        review.get('approved') is True and review.get('independent_source_schema_review_pass') is True and
        review.get('root_authorized') is True and review.get('reviewer') and
        review.get('request_sha256')==args.request_sha256 and review.get('central_receipt_sha256')==core.composer.CENTRAL_PIN and
        review.get('provider_map_sha256')==prior.MAP_PIN and review.get('prepared_collision_count')==14333 and
        review.get('artifact_sha256')=={k:h for k,(_,h) in ARTIFACTS.items()} and
        review.get('producer_sha256')==PINS and set(review.get('source_sha256',{}))==set(OWNED) and
        review.get('allow_native_tools') is False and review.get('allow_game_execution') is False,
        'exact source/input review and delegated finite authorization required')
    for rel,h in {**review['source_sha256'],**PINS}.items():base.observe(ROOT/rel,h,inputs)
    return review


def run(args):
    start=time.monotonic();inputs={};review=review_gate(args,inputs)
    request=base.load_json(base.observe(args.request,args.request_sha256,inputs))
    require(set(request)=={'schema_version','kind','roots'} and type(request['schema_version']) is int and
        request['schema_version']==1 and request['kind']=='fnv-finite-ordinary-root-request' and len(request['roots'])==12,
        'exact finite twelve-root request required')
    roots=request['roots'];require(all(set(r)==base.ROOT_KEYS for r in roots),'strict physical root schema')
    wanted={r['original_address']:r for r in roots}
    require(set(wanted)==DATA_ADDRESSES|{LABEL_ADDRESS},'only accepted eleven DATA roots and label root permitted')
    artifacts={name:base.observe(ROOT/'build/rebuild'/rel,h,inputs) for name,(rel,h) in ARTIFACTS.items()}
    central=base.load_json(base.observe(args.central_receipt,core.composer.CENTRAL_PIN,inputs))
    records=base.central_records(central,args.lanes_dir,inputs,set(wanted),start)
    require(set(records)==set(wanted) and all(records[a]['row']['requested_roots']==[r] for a,r in wanted.items()),'accepted central scope differs')
    reports={name:base.load_json(base.observe(ROOT/'build/rebuild'/filename,base.inventory.EXPECTED[name],inputs)) for name,filename in
        [('selection','function-selection-v2.json'),('manifest','objects-20261103T030230Z-7cfc935c.json'),
         ('retained','retained-verify-full-v3.json'),('owners','runtime-data-owners-native-v1.json')]}
    units={u['recipe_id']:u for u in reports['manifest']['units']};proofs={p['recipe_id']:p for p in reports['retained']['units']}
    require(len(units)==len(proofs)==2988 and len(reports['selection']['selections'])==68657,'complete authoritative context differs')
    recipes=base.observe(ROOT/'build/units.json',base.inventory.EXPECTED['recipes'],inputs)
    require(base.reconcile_recipes(reports['manifest'],recipes)['verified'],'original source recipes differ')
    expanded=base.load_json(base.observe(args.provider_map,prior.MAP_PIN,inputs))
    base.observe(ROOT/'build/rebuild'/prior.MAP_REVIEW[0],prior.MAP_REVIEW[1],inputs)
    base.observe(ROOT/prior.MAP_SNAPSHOT,prior.MAP_PRODUCER,inputs)
    providers=prior.validate_provider_map(expanded,reports['selection']['selections'],units,proofs,reports['owners'])
    base.collector.validate_request(request,reports['selection']['selections'],reports['manifest'],reports['retained'],providers)
    manifest=base.load_json(artifacts['prepared_manifest']);exports=validate_prepared(manifest,expanded['providers'])
    require(all(base.pool.canonical(providers[a]) not in exports for a in wanted),'prepared logical CODE collision')
    for key,(rel,h) in prepared.INPUTS.items():base.observe(ROOT/'build/rebuild'/rel,h,inputs)
    # Only saved metadata streams; neither original owner nor binding global stream is reopened.
    aggregate=base.load_json(base.observe(ROOT/'build/rebuild/application-frontier-dispatch-v1/central-root-requests.json',
        '61ec8851e2bd2e2208b265fba6554eabcfa81291c1e2e6738faefbafec9fe1ce',inputs))
    request_index={r['original_address']:r for r in aggregate['roots']}
    with gzip.open(artifacts['data_details'],'rt') as stream:
        rows=[]
        for line in stream:
            require(len(rows)<79 and len(line)<=16*1024**2,'DATA saved view bound');rows.append(json.loads(line))
    data_receipt=base.load_json(artifacts['data_receipt']);contexts=join_data_rows(data_receipt,rows,central,request_index)
    require(set(contexts)==DATA_ADDRESSES and data_receipt['views']==79 and data_receipt['objects']==26 and
        data_receipt['passed_views']==29 and data_receipt['discharged_blockers']==29,'accepted DATA batch profile differs')
    witness=base.load_json(artifacts['label_witness']);saved_label=base.load_json(artifacts['label_composition'])
    label_record=records[LABEL_ADDRESS]
    require(label_record['lane']==1 and label_record['ordinal']==29,'accepted label locator differs')
    contexts[LABEL_ADDRESS]=dict(locator=(1,29),central_record_sha256=label_record['record_sha256'],
        requested_root=wanted[LABEL_ADDRESS],original_certificate_sha256=digest(label_record['row']['certificate']),
        contract_identity_sha256=digest(label_record['row']['contract']),witnesses=[witness],saved_composition=saved_label)
    for a,context in contexts.items():
        record=records[a];row=record['row']
        require(context['requested_root']==wanted[a] and context['locator']==(record['lane'],record['ordinal']) and
            context['central_record_sha256']==record['record_sha256'] and
            context['original_certificate_sha256']==digest(row['certificate']) and
            context['contract_identity_sha256']==digest(row['contract']) and not row['closure_observed'],
            'typed observation borrowed from different original contract/root')
        for rel,h in row['contract']['provenance']['dependency_tools_sha256'].items():
            p=(ROOT/rel).resolve();require(p.is_relative_to(ROOT/'tools'),'foreign observer dependency');base.observe(p,h,inputs)
    for rel,h in reports['retained']['inputs']['tools_sha256'].items():base.observe(ROOT/rel,h,inputs)
    base.observe(ROOT/'build/image_check.json',reports['retained']['inputs']['image_check_sha256'],inputs)
    reference=base.observe(args.reference,base.pool.PINS['reference'],inputs)
    object_paths={}
    for a,r in wanted.items():
        unit=units[r['recipe_id']];source=(ROOT/unit['source']).resolve()
        obj=(ROOT/'build/rebuild'/reports['manifest'].get('object_root_relative','.')/unit['object']).resolve()
        require(source.is_relative_to(ROOT) and obj.stat().st_size<=16*1024**2,'bounded authoritative source/object required')
        base.observe(source,r['source_sha256'],inputs);base.observe(obj,r['object_sha256'],inputs);object_paths[a]=obj
    coverage_path=base.observe(ROOT/'build/rebuild'/prior.ARTIFACTS['baseline_coverage'][0],prior.ARTIFACTS['baseline_coverage'][1],inputs)
    out=Path(args.out).resolve();private=(ROOT/'build/rebuild').resolve()
    require(out.is_relative_to(private) and out!=private and not out.exists() and not any(p.is_relative_to(out) for p in inputs),'exclusive private output required')
    base.stable(inputs);out.mkdir();journal=(out/'progress.jsonl').open('x',encoding='utf-8')
    def note(state,**facts):
        journal.write(json.dumps(dict(state=state,elapsed_seconds=round(time.monotonic()-start,3),**facts))+'\n');journal.flush();os.fsync(journal.fileno())
    note('started',requested=12,prepared_collision_count=len(exports),original_negative_certificates_preserved=True)
    members=[];receipts=[];blocked=[];assessments=[];emitted=[]
    try:
        for rel,h in review['source_sha256'].items():
            raw=(ROOT/rel).read_bytes();require(base.coff.digest(raw)==h,'reviewed source drift')
            snapshot=out/'source-snapshots'/rel;snapshot.parent.mkdir(parents=True,exist_ok=True);base.pool.fsynced(snapshot,raw)
        sys.path.insert(0,str(ROOT/'tools'));import compare as oracle
        from build_and_match import image_ok
        loaded=base.checked_reference(reference,oracle,image_ok)
        metadata=SnapshotPe(reference,loaded)
        try:
            highlow={metadata.base+rva for rva in metadata.relocations()}
            evidence=json.loads(witness['evidence_json']);saved_sites=evidence['original_highlow_sites']
            require(len(saved_sites)==351931 and highlow_sites(saved_sites)==highlow,'fresh full HIGHLOW authority differs')
            label_facts=audit_original_fields(metadata,highlow,evidence['fields'])
            require(len(label_facts)==26,'complete label authority field scope differs')
            retained_facts={}
            for a,record in records.items():
                for site,fact in audit_original_fields(metadata,highlow,record['row']['contract']['fields']).items():
                    require(site not in retained_facts or retained_facts[site]==fact,'retained original field contradiction');retained_facts[site]=fact
            require(len(retained_facts)==146 and len(set(retained_facts)&set(label_facts))==7,'retained/label field audit profile differs')
            audit=dict(highlow_sites=len(highlow),retained_fields=len(retained_facts),label_authority_fields=len(label_facts),
                shared_fields=7,unique_fields=len(set(retained_facts)|set(label_facts)),loaded_reference_sha256=base.coff.digest(loaded.data),
                original_highlow_authority_authenticated=True,original_witness_flags_unchanged=True)
            base.save_json(out/'original-field-audit.json',audit);note('fresh_original_fields_verified',**audit)
        finally:metadata.close()
        for a,r in sorted(wanted.items()):
            base.budget(start,out);record=records[a];row=record['row'];context=contexts[a]
            raw=object_paths[a].read_bytes();contract=row['contract'];negative=row['certificate'];typed=context['witnesses']
            composed=core.composer.compose(raw,contract,negative,typed,policy_id=core.composer.POLICY)
            if a==LABEL_ADDRESS:normalize_label_composition(context['saved_composition'],composed,record,witness,central)
            else:require(composed==context['saved_composition'],'fresh DATA composition differs from accepted saved evidence')
            assessment=core.assess_member(raw,contract,negative,typed,composed,[r],providers,existing_exports=exports,policy_id=core.POLICY)
            assessments.append(dict(original_address=a,assessment=assessment))
            if assessment['eligible'] is not True:
                require(assessment['blockers'],'unsupported policy lacks blocker');blocked.append(dict(root=r,blockers=assessment['blockers'],fresh_body_compared=False))
                note('root_quarantined',original_address=a,blockers=assessment['blockers']);continue
            name='typed-composed-%03d-%s.obj'%(len(members),a[2:]);path=out/name
            output,projection=verify_member(raw,contract,negative,typed,composed,[r],providers,exports,object_paths[a],path,loaded,units[r['recipe_id']]['recipe'])
            require(projection['exports']==assessment['exports'] and projection['fields']==assessment['fields'] and
                projection['comparison_base_view']==assessment['comparison_base_view'],'assessment/fresh projection differs')
            projection.update(central_record_sha256=record['record_sha256'],typed_witness_sha256=[digest(w) for w in typed])
            members.append((name,output));receipts.append(dict(name=name,projection=projection));emitted.append(a)
            note('member_verified',original_address=a,member_sha256=base.coff.digest(output),fields=len(projection['fields']))
        archive_hash=None
        if members:
            archive=base.coff.archive(members);base.pool.fsynced(out/'typed-composed.lib',archive);recovered=base.coff.read_archive(archive)
            require(recovered['members']==members and len(recovered['index'])==len(emitted),'archive physical members/defined exports differ')
            for name,data in recovered['members']:
                path=out/('recovered-'+name);base.pool.fsynced(path,data);base.bulk.strict_reparse(path,data)
            archive_hash=base.coff.digest(archive)
        coverage=write_coverage(out/'coverage.jsonl.gz',coverage_path,expanded['providers'],manifest,set(wanted),set(emitted))
        for name,value in [('members',receipts),('blocked',blocked),('assessments',assessments)]:base.save_json(out/(name+'.json'),value)
        base.stable(inputs)
        result=dict(schema_version=1,policy_id=POLICY,status='completed' if len(emitted)==12 else 'completed-incomplete',
            request_sha256=args.request_sha256,review_sha256=args.review_sha256,requested=12,emitted=len(emitted),blocked=len(blocked),
            emitted_addresses=emitted,archive_sha256=archive_hash,prepared_manifest_sha256=ARTIFACTS['prepared_manifest'][1],
            prepared_collision_count=14333,ordinary_prepared_upstream_count=14329,application_cohort_adoption=False,
            central_receipt_sha256=core.composer.CENTRAL_PIN,provider_map_sha256=prior.MAP_PIN,
            fields=sum(len(m['projection']['fields']) for m in receipts),code_bytes=sum(m['projection']['requested_roots'][0]['size'] for m in receipts),
            members_sha256=base.file_hash(out/'members.json'),blocked_sha256=base.file_hash(out/'blocked.json'),
            assessments_sha256=base.file_hash(out/'assessments.json'),original_field_audit_sha256=base.file_hash(out/'original-field-audit.json'),
            coverage_sha256=base.file_hash(out/'coverage.jsonl.gz'),historical_owners=68657,coverage_counts=coverage,
            inputs={str(p):h for p,h in inputs.items()},inputs_stable=True,optional_function_index_present=False,
            native_archive_conformance_verified=False,resource_observations=base.budget(start,out),
            resource_limits=dict(sampled_peak_memory_bytes=1024**3,sampled_seconds=900,output_bytes=128*1024**2),**FALSE)
        return base.finalize_success(out,result,inputs,start,journal,note)
    except BaseException as error:
        try:
            if not journal.closed:note('failed',error_type=type(error).__name__,message=str(error),completed_members=len(emitted))
        except OSError:pass
        base.save_json(out/'abort.json',dict(status='aborted-no-retry',error_type=type(error).__name__,message=str(error),completed_members=emitted,successful_projection=False,**FALSE));raise
    finally:
        if not journal.closed:journal.close()


def main(argv=None):
    parser=argparse.ArgumentParser(description=__doc__)
    for name in ('request','central-receipt','lanes-dir','provider-map','review','reference','out'):
        parser.add_argument('--'+name,required=True,type=Path,dest=name.replace('-','_'))
    for name in ('request','review'):parser.add_argument('--'+name+'-sha256',required=True,dest=name.replace('-','_')+'_sha256')
    args=parser.parse_args(argv)
    try:result=run(args)
    except (ValueError,OSError,KeyError,TypeError) as error:parser.exit(2,'typed composed factory rejected: '+str(error)+'\n')
    print(json.dumps({k:result[k] for k in ('status','requested','emitted','blocked','fields','archive_sha256')}))
    return 0 if result['status']=='completed' else 3


if __name__=='__main__':raise SystemExit(main())
