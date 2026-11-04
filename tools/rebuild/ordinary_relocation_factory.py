"""Bounded field-bearing ordinary CODE factory; no native or runtime API.

Only accepted bare ordinary singleton certificates are consumed. Planned
physical provider identities are not runtime providers or materialized exports.
"""
from __future__ import annotations
import argparse
from collections import Counter
import gzip
from itertools import zip_longest
import json
import os
from pathlib import Path
import re
import sys
import time

import ordinary_code_projection as base
import ordinary_relocation_projection as core

ROOT=base.ROOT
POLICY='ordinary-relocation-factory-v1'
OWNED=('tools/rebuild/ordinary_relocation_factory.py','tests/rebuild/test_ordinary_relocation_factory.py',
       'docs/rebuild/ORDINARY-RELOCATION-FACTORY.md')
CORE_PIN='30e149e02e4ba514cf5bf4ad6dce41625a46df19c2585874c90e97305ee3c732'
MAP_PRODUCER='0e2f3ec93515c6fbe5d7dcf0ae03f9668f8fd58da6930ac875214e5994e7c745'
MAP_PIN='6cd5bf884bb28d460cfc92f63b765c15413904f58355844243ddd6b59b97001c'
MAP_SNAPSHOT='build/rebuild/root-certificate-composer-v1/source-freeze-v1/root_certificate_composer.py'
MAP_REVIEW=('root-certificate-composer-v1/provider-map-review.json','ac44b36431da8b070c2dcd95452a6e3faed57efd8758e4b95aa275d8fa8c1baf')
MAP_INPUTS=dict(owners=base.inventory.EXPECTED['owners'],selection=base.inventory.EXPECTED['selection'],
    manifest=base.inventory.EXPECTED['manifest'],retained=base.inventory.EXPECTED['retained'],
    owner_details='c54abfd434ac715a16d31711fa8afb498d4b41420bec3bfcc25347d0eab9bd08')
OWNER_SEQUENCE='1f80ad052c78977bd0acfb03699aaa17c0dd3ae2fdcedca07ee6ea938b7b6cb0'
MAP_FALSE={'provider_selected','runtime_eligible','ABI_verified','namespace_approved','full_serialization_eligible',
           'emission_performed','materialization_approved','link_ready','native_tools_run'}
MAP_KEYS={'schema_version','policy_id','kind','providers','census','provider_identity_is_planned_namespace',
          'materialized_exports','inputs','producer_sha256','input_stability','optional_function_index_present'}|MAP_FALSE
ENTRY_KEYS={'recipe_id','object_sha256','symbol_index','source_sha256','section','value','size','symbol','planned_canonical_name'}
PINS={**base.PINS,'tools/rebuild/ordinary_code_projection.py':'e01437aed27549d8892035d3ea7f1500a5e15150bb14a8d56db95ff17c1dac8d',
      'tools/rebuild/ordinary_relocation_projection.py':CORE_PIN,MAP_SNAPSHOT:MAP_PRODUCER}
FALSE=dict(base.FALSE,typed_root_witnesses_consumed=False,materialization_approved=False)
require=base.require
digest=base.digest

# These are disjoint prepared archives, not a selected application manifest.
ARTIFACTS={
 'baseline_receipt':('bulk-code-pool-all-current-v1/production/receipt.json','ad870815321b42485378b0f896340bfd0b70cd52aea0dd27ffc39725bd93ce14'),
 'baseline_members':('bulk-code-pool-all-current-v1/production/members.jsonl','a3232bd7c19dd41b67f0d4e85d8b3a9e8b4c18b8f95d065f2286dd75fe7da105'),
 'baseline_coverage':('bulk-code-pool-all-current-v1/production/coverage.jsonl.gz','e29cef9c0169ea19ac39724d3acb33163b101d9f21e8eed970c8071253d4ec16'),
 'baseline_archive':('bulk-code-pool-all-current-v1/production/code-pool-0000.lib','1d5d9ae7ba169f2389a3e9928a46fcbeb8f25b829bcdaee627db3f43e9d89aa5'),
 'union_receipt':('union-reference-production-native-v1/receipt.json','261e083ba69d4158180a662e7aa278c8be23c4bf6c6a30a991ce9898c3a60361'),
 'union_review':('union-reference-production-native-v1/independent-outcome-review.json','229fc56e1578d1d73c7f7b85e446823ed41418525be422e28453c4582f092af6'),
 'union_members':('union-reference-production-native-v1/members.jsonl','bdf895fe66d336f5bf900f00a43af938a3696cc60df22fc483c73563343863f2'),
 'union_coverage':('union-reference-production-native-v1/coverage.jsonl.gz','f7eb7da6b6f7b467a2659ef5d0a102b5f33cb2193ce7f8893a73a2f115d527d6'),
 'union_archive':('union-reference-production-native-v1/union-reference-v3-0000.lib','ce953c9c924873d67c89cbce669f2253089711c12121a87da2aeaa87311a007a'),
 'first8_receipt':('ordinary-code-projection-first8-v1/receipt.json','39f6ac1fabdeb0f4ebed433bbaf3dc86ef82472bd0c24fcb3af18f1aa5da1d80'),
 'first8_review':('ordinary-code-projection-first8-v1/independent-outcome-review.json','d6731769187021a4f02b98f0a1c9492571914cab2a77cd2475a25b3f474bd449'),
 'first8_members':('ordinary-code-projection-first8-v1/members.json','1b2335171290d48b0a2453e65d4dcfca45ab46d8e5091d075bcc35897ba524fb'),
 'first8_coverage':('ordinary-code-projection-first8-v1/coverage.jsonl.gz','1db1206578e647c53e273e80611f325bd5eaa171285b9cb8469c237b1dba3979'),
 'first8_archive':('ordinary-code-projection-first8-v1/ordinary-code.lib','1f2beeea01a4aef884e474dfbb3ac9eb89bef3cf70de021e77fdd7ee65c3430b')}


def validate_provider_map(data,selections,units,proofs,owner_summary):
    """Authenticate expanded planned identities; return only strict three-key IDs.

    The operational caller first pins the independently accepted complete map,
    historical producer snapshot and all authoritative input artifacts. This
    routine performs no object/source reads and approves no provider adoption.
    """
    require(set(data)==MAP_KEYS and type(data['schema_version']) is int and data['schema_version']==1 and
            data['policy_id']=='selected-physical-provider-map-v1' and data['kind']=='typed-provider-map', 'provider map schema')
    require(data['inputs']==MAP_INPUTS and data['producer_sha256']==MAP_PRODUCER and
            data['input_stability'] is True and data['optional_function_index_present'] is False and
            data['provider_identity_is_planned_namespace'] is True and type(data['materialized_exports']) is int and
            data['materialized_exports']==0 and all(data[k] is False for k in MAP_FALSE), 'provider map authority/promoted state')
    census=data['census'];providers=data['providers']
    require(set(census)=={'events','sequence_sha256','selected_owners'} and census['events']==owner_summary['summary']['events'] and
            census['sequence_sha256']==OWNER_SEQUENCE and type(census['selected_owners']) is int and
            census['selected_owners']==len(selections)==len(providers) and set(providers)==set(selections), 'complete provider census differs')
    result={};physical=set();checked={}
    for address,entry in providers.items():
        require(isinstance(entry,dict) and set(entry)==ENTRY_KEYS and re.fullmatch('0x[0-9a-f]{8}',address),'provider entry schema')
        choice=selections[address];rid=choice['recipe_id'];unit=units[rid];proof=proofs[rid]
        if rid not in checked:
            base.inventory.check_unit(unit,proof)
            checked[rid]={r['original_address']:r for r in base.inventory.selected_rows(unit,proof,selections)}
        require(address in checked[rid] and entry['recipe_id']==rid and entry['object_sha256']==unit['object_sha256'] and
                entry['source_sha256']==unit['source_sha256'] and
                all(entry[k]==choice[k] and type(entry[k]) is type(choice[k]) for k in ('section','value','size','symbol')),
                'provider native/source/selected join differs')
        identity={k:entry[k] for k in ('recipe_id','object_sha256','symbol_index')}
        name=base.pool.canonical(identity);key=(rid,entry['object_sha256'],entry['symbol_index'])
        require(key not in physical and entry['planned_canonical_name']==name,'duplicate physical owner or guessed planned name')
        physical.add(key);result[address]=identity
    return result


def combine_exports(old_rows,union_rows,first8_rows):
    require(len(old_rows)==1019 and len(union_rows)==185 and len(first8_rows)==8,'prepared member census differs')
    sets=[]
    for rows,expected,nested in ((old_rows,12946,False),(union_rows,1372,False),(first8_rows,8,True)):
        names=[name for row in rows for name in (row['projection']['exports'] if nested else row['exports'])]
        require(len(names)==len(set(names))==expected and all(re.fullmatch('_fnv_code_[0-9a-f]{64}',n) for n in names),
                'prepared CODE export census/identity differs')
        sets.append(set(names))
    require(sum(map(len,sets))==len(set.union(*sets))==14326,'overlapping prepared CODE identities')
    return set.union(*sets)


def check_coverage_triplet(original,union,first8,ordinal):
    a=original['original_address'];status=original['status']
    require(status in ('EMITTED','BLOCKED_UNION','HISTORICAL_BLOCKED') and
            a==union['original_address']==first8['original_address'] and
            original['physical_identity']==union['physical_identity']==first8['physical_identity'], 'upstream coverage physical scope differs')
    require(union['original_status']==status and union['original_coverage_row']==dict(ordinal=ordinal,sha256=digest(original)), 'supplemental original coverage proof differs')
    require(first8.get('baseline_status_preserved') is True and
            {k:v for k,v in first8.items() if k not in ('ordinary_projection_status','baseline_status_preserved')}==original,
            'first8 altered original coverage')
    expected={'EMITTED':'UPSTREAM_EMITTED_UNCHANGED','BLOCKED_UNION':'STILL_UNION_BLOCKED','HISTORICAL_BLOCKED':'UPSTREAM_HISTORICAL_BLOCKED'}[status]
    union_prepared=union['status']=='NEW_UNION_V3_PROJECTED';leaf_prepared=first8['ordinary_projection_status']=='EMITTED_ORDINARY_NO_RELOCATION'
    require(union['status'] in (expected,'NEW_UNION_V3_PROJECTED') and
            first8['ordinary_projection_status'] in ('NOT_REQUESTED','EMITTED_ORDINARY_NO_RELOCATION'), 'unknown prepared coverage status')
    require(not union_prepared or status=='BLOCKED_UNION','supplemental replaced noncandidate owner')
    require(not leaf_prepared or status=='HISTORICAL_BLOCKED','first8 replaced candidate owner')
    require(sum((status=='EMITTED',union_prepared,leaf_prepared))<=1,'multiple prepared providers for one original owner')
    return 'BASELINE_PREPARED' if status=='EMITTED' else 'UNION_V3_PREPARED' if union_prepared else 'FIRST8_PREPARED' if leaf_prepared else 'UNPREPARED'


def coverage_rows(paths):
    with gzip.open(paths['baseline_coverage'],'rt') as old,gzip.open(paths['union_coverage'],'rt') as union,gzip.open(paths['first8_coverage'],'rt') as first8:
        seen=set();counts=Counter()
        for ordinal,lines in enumerate(zip_longest(old,union,first8),1):
            require(ordinal<=68657 and all(line is not None and len(line)<=4*1024**2 for line in lines),'coverage length/bound differs')
            rows=[json.loads(line) for line in lines];a=rows[0]['original_address'];require(a not in seen,'duplicate upstream owner');seen.add(a)
            state=check_coverage_triplet(*rows,ordinal);counts[state]+=1
            yield ordinal,rows[0],state
        require(len(seen)==68657 and counts['BASELINE_PREPARED']==12946 and counts['UNION_V3_PREPARED']==1372 and
                counts['FIRST8_PREPARED']==8,'complete prepared coverage census differs')


def preflight_scope(paths,requested,exports):
    found={}
    for ordinal,row,state in coverage_rows(paths):
        a=row['original_address']
        if a not in requested:continue
        root=requested[a]
        require(row['physical_identity']=={k:root[k] for k in ('recipe_id','object_sha256','symbol_index')} and
                all(row['selected_native'][k]==root[k] for k in base.NATIVE_KEYS),'request/upstream physical identity differs')
        require(state=='UNPREPARED' and base.pool.canonical(row['physical_identity']) not in exports,'existing prepared logical CODE cannot be replaced')
        found[a]=dict(original_status=row['status'],original_row_ordinal=ordinal,original_row_sha256=digest(row))
    require(set(found)==set(requested),'requested owner missing upstream coverage')
    return found


def write_coverage(path,paths,requested,emitted):
    counts=Counter()
    with Path(path).open('xb') as file:
        with gzip.GzipFile(fileobj=file,mode='wb',mtime=0) as out:
            for ordinal,row,state in coverage_rows(paths):
                a=row['original_address'];require(a not in emitted or state=='UNPREPARED','new CODE duplicates prepared owner')
                status='NEW_RELOCATION_PROJECTED' if a in emitted else 'REQUEST_BLOCKED' if a in requested else 'NOT_REQUESTED';counts[status]+=1
                value=dict(original_address=a,physical_identity=row['physical_identity'],original_status=row['status'],
                    original_coverage_row=dict(ordinal=ordinal,sha256=digest(row)),prepared_upstream_status=state,
                    ordinary_relocation_status=status,**FALSE)
                out.write((json.dumps(value,sort_keys=True,separators=(',',':'))+'\n').encode())
        file.flush();os.fsync(file.fileno())
    require(sum(counts.values())==68657,'complete successor coverage differs')
    return dict(counts)


def project_and_verify(raw,contract,certificate,requested_roots,providers,exports,stage_path):
    """No cached eligibility authorizes serialization; the core replays again."""
    output,receipt=core.project_member(raw,contract,certificate,requested_roots,providers,existing_exports=exports)
    require(len(output)<=16*1024**2,'projected member bound')
    base.pool.fsynced(Path(stage_path),output)
    base.bulk.strict_reparse(Path(stage_path),output)
    return output,receipt


def verify_member(raw,contract,certificate,requested_roots,providers,exports,original_path,stage_path,pe,recipe):
    """Unchanged ordinary comparison surrounds independent replay/serialization."""
    require(len(requested_roots)==1,'singleton comparison scope required')
    root=requested_roots[0];contracts=[dict(selected={k:root[k] for k in base.NATIVE_KEYS})]
    before=base.bulk.compare_functions(original_path,pe,contracts,recipe)
    output,projection=project_and_verify(raw,contract,certificate,requested_roots,providers,exports,stage_path)
    plan=dict(bindings=projection['namespace_bindings'],comparison_base_view=projection['comparison_base_view'])
    after=base.bulk.compare_functions(stage_path,pe,contracts,recipe,plan)
    projection.update(before_comparison=before,after_comparison=after)
    return output,projection


def review_gate(args,inputs):
    review=base.load_json(base.observe(args.review,args.review_sha256,inputs))
    require(review.get('schema_version')==1 and review.get('kind')=='ordinary-relocation-factory-review-v1' and
            review.get('approved') is True and review.get('independent_source_schema_review_pass') is True and
            review.get('root_authorized') is True and review.get('reviewer') and
            review.get('request_sha256')==args.request_sha256 and review.get('central_receipt_sha256')==args.central_receipt_sha256 and
            review.get('central_observation_independently_accepted') is True and review.get('provider_map_independently_accepted') is True and
            review.get('provider_map_sha256')==MAP_PIN==args.provider_map_sha256 and
            review.get('provider_map_review_sha256')==MAP_REVIEW[1] and
            review.get('prepared_export_census')==14326 and review.get('prepared_artifacts')=={k:h for k,(_,h) in ARTIFACTS.items()} and
            review.get('allow_native_tools') is False and review.get('allow_executable_link') is False,
            'exact independent source/artifact acceptance and delegated root authorization required')
    require(set(review.get('source_sha256',{}))==set(OWNED) and review.get('producer_sha256')==PINS,
            'reviewed factory/source producer set differs')
    for relative,h in {**review['source_sha256'],**PINS}.items():base.observe(ROOT/relative,h,inputs)
    for module in (core,base):require(Path(module.__file__).resolve()==ROOT/'tools/rebuild'/Path(module.__file__).name,'unexpected loaded factory dependency')
    return review


def run(args):
    start=time.monotonic();inputs={};review=review_gate(args,inputs)
    request=base.load_json(base.observe(args.request,args.request_sha256,inputs))
    require(set(request)=={'schema_version','kind','roots'} and type(request['schema_version']) is int and request['schema_version']==1 and
            request['kind']=='fnv-finite-ordinary-root-request' and isinstance(request['roots'],list) and 0<len(request['roots'])<=205,'finite physical request schema')
    roots=request['roots'];require(all(isinstance(r,dict) and set(r)==base.ROOT_KEYS for r in roots),'exact requested root schema')
    wanted={r['original_address']:r for r in roots};require(len(wanted)==len(roots),'duplicate requested owner')
    central=base.load_json(base.observe(args.central_receipt,args.central_receipt_sha256,inputs))
    records=base.central_records(central,args.lanes_dir,inputs,set(wanted),start)
    require(set(wanted)<=set(records) and all(records[a]['row']['requested_roots']==[r] for a,r in wanted.items()),'request/accepted central singleton differs')
    # No original global owner/binding streams are opened by this factory.
    report_names=dict(selection='function-selection-v2.json',manifest='objects-20261103T030230Z-7cfc935c.json',
        retained='retained-verify-full-v3.json',owners='runtime-data-owners-native-v1.json')
    basis={name:base.load_json(base.observe(ROOT/'build/rebuild'/rel,base.inventory.EXPECTED[name],inputs)) for name,rel in report_names.items()}
    require(basis['selection']['function_addresses']==len(basis['selection']['selections'])==68657,'complete selected universe differs')
    recipes=base.observe(ROOT/'build/units.json',base.inventory.EXPECTED['recipes'],inputs)
    require(base.reconcile_recipes(basis['manifest'],recipes)['verified'],'authoritative original recipes differ')
    units={u['recipe_id']:u for u in basis['manifest']['units']};proofs={u['recipe_id']:u for u in basis['retained']['units']}
    require(len(units)==len(basis['manifest']['units'])==len(proofs)==len(basis['retained']['units'])==2988,'complete unique manifest/proof scope differs')
    planned=base.load_json(base.observe(args.provider_map,MAP_PIN,inputs))
    base.observe(ROOT/'build/rebuild'/MAP_REVIEW[0],MAP_REVIEW[1],inputs)
    base.observe(ROOT/MAP_SNAPSHOT,MAP_PRODUCER,inputs)
    providers=validate_provider_map(planned,basis['selection']['selections'],units,proofs,basis['owners'])
    require(len(providers)==68657,'complete planned physical namespace required')
    base.collector.validate_request(request,basis['selection']['selections'],basis['manifest'],basis['retained'],providers)
    artifacts={name:base.observe(ROOT/'build/rebuild'/rel,h,inputs) for name,(rel,h) in ARTIFACTS.items()}
    read_rows=lambda p:[json.loads(line) for line in Path(p).read_text().splitlines()]
    exports=combine_exports(read_rows(artifacts['baseline_members']),read_rows(artifacts['union_members']),base.load_json(artifacts['first8_members']))
    upstream=preflight_scope(artifacts,wanted,exports)
    for name,h in basis['retained']['inputs']['tools_sha256'].items():base.observe(ROOT/name,h,inputs)
    base.observe(ROOT/'build/image_check.json',basis['retained']['inputs']['image_check_sha256'],inputs)
    reference=base.observe(args.reference,base.pool.PINS['reference'],inputs)
    out=Path(args.out).resolve();private=(ROOT/'build/rebuild').resolve()
    require(out.is_relative_to(private) and out!=private and not out.exists() and not any(p.is_relative_to(out) for p in inputs),'new exclusive private factory output required')
    candidates=[];blocked=[]
    for a,r in sorted(wanted.items()):
        record=records[a];row=record['row'];contract=row['contract'];cert=row.get('certificate');u=units[r['recipe_id']]
        require(providers[a]=={k:r[k] for k in ('recipe_id','object_sha256','symbol_index')},'request/planned physical provider differs')
        for relative,h in contract['provenance']['dependency_tools_sha256'].items():
            p=(ROOT/relative).resolve();require(p.is_relative_to(ROOT/'tools'),'foreign original observer dependency')
            if p in inputs:require(inputs[p]==h,'conflicting central dependency')
            else:base.observe(p,h,inputs)
        reasons=[]
        if row['closure_observed'] is not True or not cert:reasons.append('BARE_ORDINARY_OMISSION_BLOCKED')
        if not contract['fields']:reasons.append('FIELD_FACTORY_REQUIRES_NONEMPTY_FIELDS')
        if contract['missing_fields'] or contract['parent_eh']:reasons.append('MISSING_OR_EH_REQUIRES_SEPARATE_ADAPTER')
        if reasons:
            blocked.append(dict(root=r,reasons=reasons,central_record_sha256=record['record_sha256'],fresh_body_compared=False));continue
        require(cert['policy_id']==base.ordinary.POLICY and cert['contract_identity_sha256']==digest(contract), 'typed/composed root certificate not accepted by v1')
        source=(ROOT/u['source']).resolve();obj=(ROOT/'build/rebuild'/basis['manifest'].get('object_root_relative','.')/u['object']).resolve()
        require(source.is_relative_to(ROOT) and not source.is_relative_to(out) and not obj.is_relative_to(out),'input/output path collision')
        require(obj.stat().st_size<=16*1024**2,'original native object read bound')
        base.observe(source,r['source_sha256'],inputs);base.observe(obj,r['object_sha256'],inputs)
        candidates.append((r,row,u,obj))
    base.stable(inputs);out.mkdir();journal=(out/'progress.jsonl').open('x',encoding='utf-8')
    def note(state,**facts):journal.write(json.dumps(dict(state=state,elapsed_seconds=round(time.monotonic()-start,3),**facts))+'\n');journal.flush();os.fsync(journal.fileno())
    note('started',request_sha256=args.request_sha256,central_receipt_sha256=args.central_receipt_sha256,provider_map_sha256=MAP_PIN,
         requested=len(roots),fresh_candidate_roots=len(candidates),prepared_exclusions=len(exports))
    emitted=[];members=[];member_receipts=[];assessments=[]
    try:
        for relative,h in review['source_sha256'].items():
            snapshot=out/'source-snapshots'/relative;snapshot.parent.mkdir(parents=True,exist_ok=True)
            raw=(ROOT/relative).read_bytes();require(base.coff.digest(raw)==h,'source snapshot drift');base.pool.fsynced(snapshot,raw)
        sys.path.insert(0,str(ROOT/'tools'));import compare as oracle
        from build_and_match import image_ok
        pe=base.checked_reference(reference,oracle,image_ok)
        for r,row,u,objpath in candidates:
            base.budget(start,out);raw=objpath.read_bytes();contract=row['contract'];certificate=row['certificate']
            assessment=core.assess_member(raw,contract,certificate,[r],providers,existing_exports=exports)
            require(assessment['contract_identity_sha256']==digest(contract) and assessment['certificate_sha256']==digest(certificate) and
                    assessment['original_object_sha256']==r['object_sha256'] and assessment['requested_roots']==[r] and
                    assessment['serialization_performed'] is False,'assessment source/root identity differs')
            assessments.append(dict(original_address=r['original_address'],assessment=assessment))
            if assessment['eligible'] is not True:
                require(assessment['blockers'],'unsupported root lacks explicit blockers')
                blocked.append(dict(root=r,reasons=assessment['blockers'],central_record_sha256=digest(row),fresh_body_compared=False))
                note('root_quarantined',original_address=r['original_address'],blockers=assessment['blockers']);continue
            name='ordinary-relocation-%03d-%s.obj'%(len(members),r['original_address'][2:]);path=out/name
            output,projection=verify_member(raw,contract,certificate,[r],providers,exports,objpath,path,pe,u['recipe'])
            require(projection['exports']==assessment['exports'] and projection['comparison_base_view']==assessment['comparison_base_view'] and
                    projection['namespace_bindings']==assessment['plan']['bindings'],'fresh projection/assessment plan changed')
            projection.update(central_record_sha256=digest(row))
            members.append((name,output));member_receipts.append(dict(name=name,projection=projection));emitted.append(r['original_address'])
            note('member_verified',original_address=r['original_address'],member=name,member_sha256=base.coff.digest(output),maps=projection['maps'],fields=len(projection['fields']))
        if members:
            archive=base.coff.archive(members);base.pool.fsynced(out/'ordinary-relocation.lib',archive);recovered=base.coff.read_archive(archive)
            require(recovered['members']==members and len(recovered['index'])==len(emitted),'archive member/export indices differ')
            for name,data in recovered['members']:
                recovered_path=out/('recovered-'+name);base.pool.fsynced(recovered_path,data);base.bulk.strict_reparse(recovered_path,data)
            archive_hash=base.coff.digest(archive)
        else:archive_hash=None
        coverage=write_coverage(out/'coverage.jsonl.gz',artifacts,set(wanted),set(emitted))
        base.save_json(out/'members.json',member_receipts);base.save_json(out/'blocked.json',blocked);base.save_json(out/'assessments.json',assessments)
        base.stable(inputs);usage=base.budget(start,out)
        result=dict(schema_version=1,policy_id=POLICY,status='completed' if len(emitted)==len(roots) else 'completed-incomplete',
            request_sha256=args.request_sha256,central_receipt_sha256=args.central_receipt_sha256,provider_map_sha256=MAP_PIN,
            provider_map_review_sha256=MAP_REVIEW[1],review_sha256=args.review_sha256,requested=len(roots),emitted=len(emitted),blocked=len(blocked),
            emitted_addresses=emitted,archive_sha256=archive_hash,prepared_exclusion_exports=14326,planned_selected_physical_identities=len(providers),
            fields=sum(len(m['projection']['fields']) for m in member_receipts),code_bytes=sum(m['projection']['requested_roots'][0]['size'] for m in member_receipts),
            members_sha256=base.file_hash(out/'members.json'),blocked_sha256=base.file_hash(out/'blocked.json'),assessments_sha256=base.file_hash(out/'assessments.json'),
            coverage_sha256=base.file_hash(out/'coverage.jsonl.gz'),historical_owners=68657,coverage_counts=coverage,requested_upstream_scope=upstream,
            inputs={str(p):h for p,h in inputs.items()},inputs_stable=True,optional_function_index_present=False,native_archive_conformance_verified=False,
            resource_observations=usage,resource_limits=dict(sampled_peak_memory_bytes=1024**3,sampled_seconds=900,output_bytes=128*1024**2),**FALSE)
        return base.finalize_success(out,result,inputs,start,journal,note)
    except BaseException as error:
        try:
            if not journal.closed:note('failed',error_type=type(error).__name__,message=str(error),completed_members=len(emitted))
        except OSError:pass
        base.save_json(out/'abort.json',dict(schema_version=1,status='aborted-no-retry',error_type=type(error).__name__,message=str(error),
            completed_members=emitted,successful_projection=False,**FALSE));raise
    finally:
        if not journal.closed:journal.close()


def main(argv=None):
    parser=argparse.ArgumentParser(description=__doc__)
    for name in ('request','central-receipt','lanes-dir','provider-map','review','reference','out'):
        parser.add_argument('--'+name,required=True,type=Path,dest=name.replace('-','_'))
    for name in ('request','central-receipt','provider-map','review'):
        parser.add_argument('--'+name+'-sha256',required=True,dest=name.replace('-','_')+'_sha256')
    args=parser.parse_args(argv)
    try:result=run(args)
    except (ValueError,OSError,KeyError,TypeError) as error:parser.exit(2,'ordinary relocation factory rejected: '+str(error)+'\n')
    print(json.dumps({k:result[k] for k in ('status','requested','emitted','blocked','fields','archive_sha256')}))
    return 0 if result['status']=='completed' else 3


if __name__=='__main__':raise SystemExit(main())
