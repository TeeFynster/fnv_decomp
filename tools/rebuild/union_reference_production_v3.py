"""Finite 185-recipe unresolved CODE production, actual Box lineage bound.

No subprocess, compiler, native tool, executable linker or runtime launch API.
The accepted Box-only driver and all older serializers remain unchanged.
"""
from __future__ import annotations
import argparse
import base64
from collections import Counter
import gzip
import importlib
import json
import os
from pathlib import Path
import sys
import time

import union_reference_projection_v2 as projection

ROOT=Path(__file__).resolve().parents[2]
POLICY='finite-union-reference-production-v3'
OWNED=('tools/rebuild/union_reference_production_v3.py','tests/rebuild/test_union_reference_production_v3.py',
       'runtime/code-pools/union-reference-production-v3.json','docs/rebuild/UNION-REFERENCE-PRODUCTION-V3.md')
groups=projection.groups
bulk=projection.bulk
coff=projection.coff
sha,require=projection.sha,projection.require
FALSE=dict(projection.FALSE,executable_link_performed=False,game_execution_performed=False,
           all_role_classes_approved=False,full_runtime_closure=False)
BOX_PINS={
 'build/rebuild/union-reference-box2089-projection-v1/receipt.json':'c057095b727eced69ae5a45da3dc6498e189d64c47522f4ad1b5e1bbc1ea2d63',
 'build/rebuild/union-reference-box2089-projection-v1/certificates.jsonl':'9884b0ec82f6ab6f3f8fcc880ea8ded8a152fbd897b5b1d5086575a7c1d521eb',
 'build/rebuild/union-reference-box2089-projection-v1/2089-51b16ad19e044300.obj.stage':'84d4e7e09d93d0621301ddb9257194e64f9de3164d40826bd766f48537345600',
 'build/rebuild/union-reference-box2089-projection-v1/union-reference-0000.lib':'c812f534eee078b17cac7816cd38585290e683198ec53f8670e5e162119abc1c',
 'build/rebuild/union-reference-box2089-projection-v1/independent-outcome-review.json':'2f9a2308e465c79282356e1019b2465e20445bebc8f19c17a092e673ec25c2f4',
 'build/rebuild/box-union-component-native-v1/prepare.json':'bd4e4e4fcc3f3d1126059b18a1609c64989f5c8b41d1f9d670e3614c633b9f6b',
 'build/rebuild/box-union-component-normal-reinspection-v1/inspection.json':'4b7c6e49f5ea5a58cb7fd8fff0540873eaf0cabcb4e9d4d8f121a201fab9d453',
 'build/rebuild/box-union-component-continuation-v1/prepare.json':'4ab9632d3ef795ae59b1172e9e79de4fb4ce6377cce1f4226af3e0650aa9cb47',
 'build/rebuild/box-union-component-continuation-v1/independent-native-artifact-review.json':'23d95e05619ab805f8a4ff74f8c4f4b7ab462b946d6b6de1c26110c0dd603a60',
 'build/rebuild/box-union-component-execute-v1.py':'1f6c57de4e3714a6822e82e2fc6a4da940caf8feda68918f0654b3eb7b33c6ca',
 'build/rebuild/box-union-component-execution-harness-review-v1.json':'08d1eaf3d00c0fa34ce996df75b586f79bd5f40eb6cf7517504a72f3dbdd5d3c',
 'build/rebuild/box-union-component-execution-v1/execution.json':'a6beff83458446e210048638ec28a92d82e4e375c17989dfaf171e222e86c449',
 'build/rebuild/box-union-component-execution-v1/independent-outcome-review.json':'db9ccf62e240c53fda8bbf2735281c7cb01bac0e212cb8e125519a3531958745',
}
BOX_OUTCOME='build/rebuild/box-union-component-execution-v1/independent-outcome-review.json'
EXPECTED=dict(schema=1,rounds=128,reset_calls=128,insertion_calls=2176,lookup_calls=2432,guards_ok=True,capacity=8)


def merge_pins(target,source):
    for raw,value in source.items():
        path=Path(raw).resolve()
        require(path not in target or target[path]==value,'conflicting protected file identity')
        target[path]=value


def exact_marker(child):
    require(child['state']=='finished' and child['status']=='pass' and child['returncode']==0 and
            child['capture_prefix_incomplete'] is False,'Box child did not complete normally')
    stdout=base64.b64decode(child['stdout_base64'],validate=True);stderr=base64.b64decode(child['stderr_base64'],validate=True)
    require(not stderr and len(stdout)<=4096 and len(stdout.splitlines())==1,'Box output is not the bounded exact marker')
    marker=json.loads(stdout)
    require(marker==EXPECTED and child['observed']==EXPECTED and all(type(marker[k]) is type(v) for k,v in EXPECTED.items()),
            'Box exact marker/typed state differs')
    require(type(child['elapsed_seconds']) in (int,float) and 0<=child['elapsed_seconds']<=15,'Box elapsed bound differs')
    return marker


def validate_mechanism(prepared,native,harness_review,execution,outcome,box_record):
    """Actual full linked/executed lineage, never an all185 authority claim."""
    pp=BOX_PINS['build/rebuild/box-union-component-continuation-v1/prepare.json']
    np=BOX_PINS['build/rebuild/box-union-component-continuation-v1/independent-native-artifact-review.json']
    ep=BOX_PINS['build/rebuild/box-union-component-execution-v1/execution.json']
    hp=BOX_PINS['build/rebuild/box-union-component-execute-v1.py']
    hr=BOX_PINS['build/rebuild/box-union-component-execution-harness-review-v1.json']
    require(prepared['kind']=='real-source-box-two-layout-continued-preparation-v1' and
            prepared['status']=='prepared-not-executed' and prepared['input_stability_verified'] is True and
            prepared['cached_links']==prepared['fresh_link_attempts']==prepared['fresh_links_completed']==1 and
            prepared['normal_recompiled'] is False and prepared['normal_relinked'] is False and prepared['caller_recompiled'] is False,
            'actual one-cached/one-fresh Box preparation is absent')
    require(native['kind']=='box-union-component-native-artifact-review-v1' and native['status']=='accepted' and native['reviewer'] and
            native['prepare_sha256']==pp and native['execution_authorized'] is False and native['runtime_provider_approved'] is False,
            'actual independently accepted native Box lineage is absent')
    require(harness_review['kind']=='box-union-component-execution-harness-review-v1' and harness_review['status']=='accepted' and
            harness_review['harness_sha256']==hp and harness_review['prepare_sha256']==pp and harness_review['native_review_sha256']==np,
            'exact independently reviewed Box harness differs')
    require(execution['kind']=='real-source-box-union-component-execution-v1' and
            execution['status']=='pass' and execution['input_stability_verified'] is True and
            execution['runtime_provider_approved'] is False and execution['broader_Game_runtime_approved'] is False and execution['all185_enabled'] is False and
            execution['prepare_sha256']==pp and execution['native_review_sha256']==np and
            execution['harness_sha256']==hp and execution['harness_review_sha256']==hr and len(execution['children'])==2,
            'actual successful Box execution lineage differs')
    require(outcome['kind']=='box-union-component-execution-outcome-review-v1' and outcome['status']=='accepted' and outcome['reviewer'] and
            outcome['execution_sha256']==ep and outcome['prepare_sha256']==pp and outcome['native_review_sha256']==np and
            outcome['harness_sha256']==hp and outcome['harness_review_sha256']==hr and outcome['guard_checks_passed'] is True and
            outcome['native_link_mechanism_observed'] is True and outcome['all185_authorized'] is False and
            outcome['runtime_provider_approved'] is False and outcome['broader_game_runtime_approved'] is False,
            'actual independent finite Box outcome missing or overpromoted')
    for child,layout in zip(execution['children'],('normal','moved')):
        require(child['layout']==layout and child['arguments']==[] and child['executable_sha256']==prepared['layouts'][layout]['executable_sha256']
                ==native[layout+'_executable_sha256']==outcome[layout+'_executable_sha256'],'Box actual image/order differs')
        require(prepared['layouts'][layout]['map_sha256']==native[layout+'_map_sha256'],'Box exact reviewed map differs')
        exact_marker(child)
    cert=box_record['certificate']
    require(box_record['native_shape_verified'] is True and box_record['fresh_reference_match'] is True and
            cert['recipe_id']==projection.BOX and len(cert['roots'])==3 and sum(r['size'] for r in cert['roots'])==182 and
            len(cert['groups'])==1 and cert['groups'][0]['members']==[8,19] and
            cert['groups'][0]['kind']=='one-selected-definition-and-undefined' and cert['groups'][0]['native_shape_verified'] is True and
            dict(cert['primary_bijection'])[8]!=dict(cert['primary_bijection'])[19] and
            cert['runtime_eligible'] is False and cert['provider_selected'] is False,'exact tested physical Box group differs')


def box_basis(repository=ROOT):
    repository=Path(repository);observed={repository/p:h for p,h in BOX_PINS.items()}
    projection.stable(observed,repository)
    def load(p):return projection.load_json(repository/p)
    prepared=load('build/rebuild/box-union-component-continuation-v1/prepare.json')
    native=load('build/rebuild/box-union-component-continuation-v1/independent-native-artifact-review.json')
    harness=load('build/rebuild/box-union-component-execution-harness-review-v1.json')
    execution=load('build/rebuild/box-union-component-execution-v1/execution.json');outcome=load(BOX_OUTCOME)
    lines=(repository/'build/rebuild/union-reference-box2089-projection-v1/certificates.jsonl').read_text().splitlines()
    require(len(lines)==1,'exact single Box certificate stream required');box_record=json.loads(lines[0])
    validate_mechanism(prepared,native,harness,execution,outcome,box_record)
    require(len(execution['inputs'])==175,'actual tested protected Box input scope differs')
    # The actual execution already names the reviewed inspector source epochs.
    # Do not union obsolete pre-correction source hashes from the failed receipt.
    merge_pins(observed,execution['inputs'])
    for item in prepared['layouts'].values():
        require(observed[Path(item['executable']).resolve()]==item['executable_sha256'] and
                observed[Path(item['map']).resolve()]==item['map_sha256'],'Box image/map outside exact tested input closure')
    projection.stable(observed,repository)
    return box_record,observed


def phase_gate(args,policy,sources,observation):
    require(args.allow_production is True,'finite production requires explicit delegated root opt-in')
    require(sha(args.review)==args.review_sha256,'stale production phase/source review')
    review=projection.load_json(args.review)
    wanted=sorted(observation['candidate_recipe_ids'])
    require(len(wanted)==len(set(wanted))==185 and projection.BOX in wanted and observation['metadata_candidate_roots']==1372,
            'exact saved finite185 candidate scope differs')
    require(review.get('kind')=='union-reference-production-phase-v3' and review.get('schema_version')==1 and
            review.get('status')=='approved' and review.get('reviewer') and review.get('root_authorized') is True and
            review.get('source_sha256')==sources and review.get('producer_sha256')==policy['producer_sha256'] and
            review.get('box_outcome_review_sha256')==BOX_PINS[BOX_OUTCOME] and review.get('recipe_ids')==wanted and
            review.get('root_count')==1372 and review.get('native_tools_allowed') is False and review.get('execution_allowed') is False,
            'exact source-reviewed finite production phase missing')
    return wanted


def write_coverage(path,original,emitted):
    counts=Counter();seen=set()
    with Path(path).open('xb') as file:
        with gzip.GzipFile(fileobj=file,mode='wb',mtime=0) as zipped:
            for ordinal,row in groups.saved_records(original):
                address=row['original_address'];require(address not in seen,'duplicate source coverage owner');seen.add(address)
                require(row['status'] in ('EMITTED','HISTORICAL_BLOCKED','BLOCKED_UNION'),'unknown original coverage status')
                if address in emitted:
                    require(row['status']=='BLOCKED_UNION','production may not overwrite old emitted/historical owners')
                    status='NEW_UNION_V3_PROJECTED'
                else:status={'EMITTED':'UPSTREAM_EMITTED_UNCHANGED','HISTORICAL_BLOCKED':'UPSTREAM_HISTORICAL_BLOCKED','BLOCKED_UNION':'STILL_UNION_BLOCKED'}[row['status']]
                counts[status]+=1
                zipped.write(bulk.canonical(dict(original_address=address,status=status,original_status=row['status'],
                    physical_identity=row['physical_identity'],original_coverage_row=dict(ordinal=ordinal,sha256=groups.digest(row)),**FALSE))+b'\n')
        file.flush();os.fsync(file.fileno())
    require(len(seen)==68657 and set(emitted)<=seen,'complete original coverage owner set differs')
    return dict(counts)


def budget(out,start):
    require(time.monotonic()-start<=900,'finite production 15-minute bound exceeded')
    total=sum(p.stat().st_size for p in Path(out).iterdir() if p.is_file())
    # Reserve one MiB for the final compact receipt, within the 128 MiB phase cap.
    require(total<=127*1024*1024,'finite production private output exceeds reserved128MiB budget')
    return total


def tested_box_equal(rid,certificate,output,tested):
    if rid!=projection.BOX:return
    require(groups.digest(certificate)==groups.digest(tested['certificate']),'actual finite Box certificate differs from linked/executed mechanism')
    if output is not None:
        require(coff.digest(output)==BOX_PINS['build/rebuild/union-reference-box2089-projection-v1/2089-51b16ad19e044300.obj.stage'],
                'finite Box emitted member differs from tested actual source component')


def run(args):
    require(args.allow_production is True,'finite production requires explicit delegated root opt-in')
    start=time.monotonic();require(sha(args.policy)==args.policy_sha256,'stale finite policy')
    policy=projection.load_json(args.policy);require(policy['policy_id']==POLICY and policy['box_artifact_sha256']==BOX_PINS,'wrong actual-artifact production policy')
    sources={p:sha(ROOT/p) for p in OWNED};require(args.policy_sha256==sources[OWNED[2]],'owned reviewed policy required')
    observed={ROOT/p:h for p,h in sources.items()}
    merge_pins(observed,{args.policy:args.policy_sha256,args.review:args.review_sha256,args.inputs:sha(args.inputs)})
    for p,h in policy['producer_sha256'].items():require(sha(ROOT/p)==h,'stale finite producer');merge_pins(observed,{ROOT/p:h})
    projection.loaded_producers(policy);controls=dict(observed)
    paths={k:Path(v).resolve() for k,v in projection.load_json(args.inputs).items()}
    require(set(paths)==set(groups.INPUT_PINS)|{'metadata_observation','metadata_details'},'exact complete finite input set required')
    merge_pins(observed,{paths['metadata_observation']:projection.OBSERVATION_PIN,paths['metadata_details']:projection.DETAIL_PIN})
    projection.stable(observed)
    observation=projection.load_json(paths['metadata_observation']);wanted=phase_gate(args,policy,sources,observation)
    merge_pins(observed,{paths[k]:v for k,v in groups.INPUT_PINS.items()})
    merge_pins(observed,{args.reference:policy['reference_sha256']});projection.stable(observed)
    tested_box,mechanism=box_basis();merge_pins(observed,mechanism)
    metadata,providers,summary=groups.load_saved_metadata({k:paths[k] for k in groups.INPUT_PINS},wanted)
    require(set(metadata)==set(wanted) and all(x['assessment']['metadata_candidate'] for x in metadata.values()),'finite metadata candidate set not complete')
    requested=[r['original_address'] for x in metadata.values() for r in x['plan']['roots']]
    require(len(requested)==len(set(requested))==1372 and sum(x['plan']['counts']['code_bytes'] for x in metadata.values())==219493 and
            sum(x['plan']['counts']['fields'] for x in metadata.values())==7065,'exact finite root/byte/field scope differs')
    manifest=projection.load_json(paths['manifest']);units={u['recipe_id']:u for u in manifest['units']}
    out=args.out.resolve();private=(ROOT/'build/rebuild').resolve()
    require(out!=private and out.is_relative_to(private) and not out.exists(),'exclusive private finite output required');out.mkdir(parents=True)
    for p in OWNED:
        with (out/Path(p).name).open('xb') as file:file.write((ROOT/p).read_bytes())
    receipt=dict(schema_version=1,kind=POLICY,status='error',source_sha256=sources,metadata_summary=summary,
        requested_recipe_ids=wanted,requested_root_ids=sorted(requested),box_outcome_review_sha256=BOX_PINS[BOX_OUTCOME],
        emission_performed=False,native_coff_collection_performed=False,**FALSE)
    activities={};emitted=set();members=[];originals={};certificates={};expectations={};spool=None;pe=None;groups_count=Counter()
    with (out/'progress.jsonl').open('x') as journal,(out/'certificates.jsonl.gz').open('xb') as detail_file:
        def note(state,**values):journal.write(json.dumps(dict(state=state,**values))+'\n');journal.flush();os.fsync(journal.fileno())
        note('started',recipes=185,roots=1372)
        try:
            sys.path.insert(0,str(ROOT/'tools'));oracle=importlib.import_module('compare');image=importlib.import_module('build_and_match')
            projection.loaded_producers(policy);pe=oracle.Pe(args.reference);require(image.image_ok(pe)[0],'unchanged owned image fingerprint gate')
            spool=bulk.Spool(out/'members.spool',out/'members.jsonl')
            with gzip.GzipFile(fileobj=detail_file,mode='wb',mtime=0) as details:
                for rid in sorted(wanted,key=lambda r:units[r]['recipe_index']):
                    projection.stable(controls);budget(out,start);unit=units[rid];item=metadata[rid]
                    source=(ROOT/unit['source']).resolve();original=(paths['manifest'].parent/manifest.get('object_root_relative','.')/unit['object']).resolve()
                    require(source.is_relative_to(ROOT) and original.is_relative_to(paths['manifest'].parent),'finite source/object path escapes lineage')
                    activity=activities[rid]=dict(source_hash_attempted=False,native_object_access_attempted=False,native_object_bytes_read=None,
                        projection_attempted=False,projection_completed=False)
                    note('recipe-starting',recipe_id=rid)
                    raw,cert=projection.collect_recipe(original,source,item,providers,observed,activity)
                    tested_box_equal(rid,cert,None,tested_box)
                    before=bulk.compare_functions(original,pe,item['contracts'],unit['recipe'])
                    name=rid+'.obj';stage=out/(name+'.stage');activity['projection_attempted']=True
                    output,projected,independent,expected=projection.project_recipe(raw,original,item,providers,cert,stage,out/(name+'.recovered'))
                    tested_box_equal(rid,cert,output,tested_box)
                    after=bulk.compare_functions(stage,pe,item['contracts'],unit['recipe'],item['plan'])
                    record=dict(recipe_id=rid,certificate=cert,projection=projected,before_comparison=before,after_comparison=after,
                        independent_stage=independent,native_shape_verified=True,fresh_reference_match=True,**FALSE)
                    members.append(spool.append(name,output,unit['recipe_index'],record));originals[name]=original;certificates[name]=cert;expectations[name]=expected
                    for group in cert['groups']:groups_count[group['kind']]+=1
                    require(not emitted.intersection(r['original_address'] for r in cert['roots']),'repeated finite owner')
                    emitted.update(r['original_address'] for r in cert['roots']);activity['projection_completed']=True
                    details.write(bulk.canonical(record)+b'\n');details.flush();detail_file.flush();os.fsync(detail_file.fileno())
                    projection.stable(controls);projection.stable({source:unit['source_sha256'],original:unit['object_sha256']})
                    note('recipe-complete',recipe_id=rid,roots=len(cert['roots']),certificate_sha256=groups.digest(cert),member_sha256=coff.digest(output))
            detail_file.flush();os.fsync(detail_file.fileno())
            spool.close();spool=None;bulk.inspect_spool(out/'members.spool',members);shards=[]
            for number,selected in enumerate(bulk.shard_plan(members,max_members=512,max_bytes=64*1024*1024)):
                budget(out,start);target=out/('union-reference-v3-%04d.lib'%number);bulk.write_shard(out/'members.spool',selected,target)
                shards.append(dict(name=target.name,**projection.recover_and_verify_archive(target,selected,originals,certificates,expectations,out)))
            require(len(activities)==185 and emitted==set(requested),'finite whole185 completion differs')
            coverage=write_coverage(out/'coverage.jsonl.gz',paths['coverage'],emitted)
            require(coverage==dict(NEW_UNION_V3_PROJECTED=1372,UPSTREAM_EMITTED_UNCHANGED=12946,UPSTREAM_HISTORICAL_BLOCKED=51798,STILL_UNION_BLOCKED=2541),
                    'finite full original partition differs')
            receipt.update(status='complete',projected_roots=len(emitted),projected_recipes=len(members),code_bytes=219493,fields=7065,
                coverage_counts=coverage,shards=shards,reference_groups=dict(groups_count),member_ledger_sha256=sha(out/'members.jsonl'),
                certificates_sha256=sha(out/'certificates.jsonl.gz'),coverage_sha256=sha(out/'coverage.jsonl.gz'),spool_sha256=sha(out/'members.spool'))
        except Exception as error:receipt['error']=type(error).__name__+': '+str(error);note('failed',error=receipt['error'])
        finally:
            if spool is not None:spool.close()
            if pe is not None and hasattr(pe,'close'):pe.close()
            detail_file.flush();os.fsync(detail_file.fileno())
            try:projection.stable(observed);receipt['output_bytes_before_receipt']=budget(out,start);receipt['input_stability_verified']=True
            except Exception as error:receipt.update(status='error',input_stability_verified=False,final_stability_error=str(error))
        receipt.update(protected_inputs={str(p):h for p,h in observed.items()},recipe_activity=activities,completed_roots=len(emitted),
            native_coff_collection_performed=any(a['native_object_bytes_read'] is not None for a in activities.values()),
            source_access_attempted=any(a['source_hash_attempted'] for a in activities.values()),
            native_access_attempted=any(a['native_object_access_attempted'] for a in activities.values()),
            emission_attempted=any(a['projection_attempted'] for a in activities.values()),emission_performed=bool(emitted),
            emission_may_have_partial_outputs=receipt['status']!='complete' and any(a['projection_attempted'] for a in activities.values()),
            elapsed_seconds=time.monotonic()-start,optional_function_index_present=False,native_conformance_verified=False)
        note('final-status',status=receipt['status'],completed_roots=len(emitted))
        receipt['artifacts']={p.name:dict(sha256=sha(p),size=p.stat().st_size) for p in out.iterdir() if p.is_file()}
        projection.save_json(out/'receipt.json',receipt)
    return receipt


def main():
    parser=argparse.ArgumentParser(__doc__)
    for key in ('policy','inputs','review','reference','out'):parser.add_argument('--'+key,type=Path,required=True)
    for key in ('policy-sha256','review-sha256'):parser.add_argument('--'+key,required=True)
    parser.add_argument('--allow-production',action='store_true')
    result=run(parser.parse_args());print(result['status']);raise SystemExit(result['status']!='complete')


if __name__=='__main__':main()
