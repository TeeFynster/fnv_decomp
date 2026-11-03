"""Versioned prepared CODE collision ledger, never application/provider selection."""
from __future__ import annotations
import argparse
from collections import Counter
import json
import os
from pathlib import Path
import re
import time
import ordinary_relocation_factory as prior

base=prior.base
ROOT=base.ROOT
POLICY='prepared-code-collision-exclusions-v1'
OWNED=('tools/rebuild/prepared_code_exclusions.py','tests/rebuild/test_prepared_code_exclusions.py',
       'docs/rebuild/PREPARED-CODE-EXCLUSIONS.md')
PINS={**prior.PINS,'tools/rebuild/ordinary_relocation_factory.py':'f431d8599d7e91e2c67ed5570ccd067bdf80fbd8a92ee4c6daa3473cc26c928b'}
FALSE=dict(provider_selected=False,runtime_eligible=False,ABI_verified=False,link_ready=False,
           application_manifest_adopted=False,executable_link_performed=False,game_execution_performed=False,
           native_tools_run=False,code_emission_performed=False)
require=base.require
digest=base.digest
COUNTS={'baseline':12946,'union-v3':1372,'ordinary-first8':8,'ordinary-relocation-first3':3}
EXTRA={
 'first3_receipt':('ordinary-relocation-first3-v1/receipt.json','c44d8860c34b0f58191396dc1efed467f32eba030594dd192da56b2a7ba987c2'),
 'first3_members':('ordinary-relocation-first3-v1/members.json','e562e0444af8e817b4212ab967f3c9591619e2aafd043027afc14c8cea56e8e3'),
 'first3_review':('ordinary-relocation-first3-v1/independent-outcome-review.json','f144d4960ac31b726395e4bc7682bd4fd0751f61f7b633f31553de09f29f04f1'),
 'first3_archive':('ordinary-relocation-first3-v1/ordinary-relocation.lib','04a10404134431f73d6ec0bce2b877d566a675b095d254b33d1241f76b8b53c0'),
 'baseline_native':('bulk-code-pool-all-current-native-v1/receipt.json','b78ab291de0298b0bfb53ce03f1f440eadad7822e256abc11a5b3bb9c1c55978'),
 'application_observation':('application-cohort-observation-v1/receipt.json','9848b08bfd51244412700d25cd9cc53136253e90117a4c3b67b03c347961586b'),
 'application_review':('application-cohort-observation-v1/independent-outcome-review.json','c660630f647eee895c660504f2c575cde4ba5055066311e5137768d18891f63d'),
 'entry_receipt':('application-entry-projection-v1/receipt.json','b46ffd72903c4363f545884d3dbb5cbb3bcf355d1ef8e84171c8fae1861eeb6b'),
 'entry_review':('application-entry-projection-v1/independent-outcome-review.json','77d8f43a7884d5720c7bdb714eb5b4a042b9e3eb0a65bbfd3e82e237d018d936'),
 'overlay_review':('overlay-code-project-v1/independent-outcome-review.json','e70bc48ed3441404f3535e95159a4e44155ceddb5c974cb03eab1d05dd742cd5')}
INPUTS={**{k:v for k,v in prior.ARTIFACTS.items() if not k.endswith('_coverage')},**EXTRA}


def identity(value):
    require(isinstance(value,dict) and set(value)=={'recipe_id','object_sha256','symbol_index'},'exact physical identity')
    base.pool.canonical(value)
    return dict(value)


def reverse_planned(providers):
    result={}
    for address,entry in providers.items():
        require(re.fullmatch('0x[0-9a-f]{8}',address),'exact selected address')
        physical=identity({k:entry[k] for k in ('recipe_id','object_sha256','symbol_index')})
        name=base.pool.canonical(physical)
        require(name==entry['planned_canonical_name'] and name not in result,'ambiguous planned physical namespace')
        result[name]=(address,physical)
    return result


def ordinary_records(ledgers,providers,bindings):
    """No binary parser: accepted exports join the complete planned identity map."""
    reverse=reverse_planned(providers);records=[]
    require(set(ledgers)==set(COUNTS) and set(bindings)>=set(COUNTS),'complete ordinary cohort ledger set')
    for cohort in COUNTS:
        rows=ledgers[cohort];count=0
        for ordinal,row in enumerate(rows,1):
            projected=cohort in ('ordinary-first8','ordinary-relocation-first3')
            proof=row['projection'] if projected else row
            exports=proof['exports'];member=row['name'];member_hash=proof['output_sha256'] if projected else row['sha256']
            require(isinstance(exports,list) and exports==sorted(set(exports)) and re.fullmatch('[0-9a-f]{64}',member_hash),'accepted member export/hash shape')
            for canonical in exports:
                require(canonical in reverse,'ordinary export has no exact original selected physical namespace')
                address,physical=reverse[canonical]
                if projected:
                    roots=proof['requested_roots'];require(len(roots)==1 and roots[0]['original_address']==address and
                        {k:roots[0][k] for k in physical}==physical,'projected logical root identity differs')
                records.append(dict(canonical=canonical,original_address=address,cohort=cohort,category='ordinary',
                    identity_mode='original-selected-physical',namespace_identity=physical,origin_identity=physical,
                    member=member,member_sha256=member_hash,source_ledger_sha256=bindings[cohort],
                    source_record_ordinal=ordinal,source_record_sha256=digest(row),logical_binding_applied=True))
                count+=1
        require(count==COUNTS[cohort],'exact ordinary cohort count differs')
    return records


def application_records(observation,entry_receipt,providers,bindings):
    """Broader prepared candidates retain physical-vs-logical identity distinctions."""
    require(observation['total_game_function_providers']==14330 and observation['baseline_provider_count']==12947 and
            observation['EH_logical_binding_applied'] is False,'accepted application observation epoch differs')
    reverse=reverse_planned(providers);projection=entry_receipt['projection'];names=projection['exported_symbols']
    require(len(names)==1 and names[0] in reverse,'exact selected entry namespace required')
    name=names[0];address,physical=reverse[name]
    require(address=='0x0086a850' and projection['original_object_sha256']==physical['object_sha256'],'entry original source identity differs')
    records=[dict(canonical=name,original_address=address,cohort='application-entry',category='application-candidate',
        identity_mode='original-selected-physical',namespace_identity=physical,origin_identity=physical,
        member='application-entry',member_sha256=projection['member_sha256'],source_ledger_sha256=bindings['entry_receipt'],
        source_record_ordinal=1,source_record_sha256=digest(projection),logical_binding_applied=True)]
    overlays=0;eh=0
    for ordinal,row in enumerate(observation['supplementary_providers'],1):
        if row['component'] not in ('overlay2','IOTask-EH'):continue
        physical=identity({k:row[k] for k in ('recipe_id','object_sha256','symbol_index')})
        canonical=row['canonical'];address=row['original_address']
        if row['component']=='overlay2':
            namespace=identity(dict(recipe_id=row['recipe_id'],object_sha256=row['logical_object_sha256'],symbol_index=row['logical_symbol_index']))
            require(canonical==base.pool.canonical(namespace) and canonical in reverse and reverse[canonical]==(address,namespace),
                    'overlay alternate must bind its explicit original logical identity')
            mode='original-selected-logical-alternate-object';cohort='overlay-alternate';extra=dict(logical_binding_applied=True)
            overlays+=1
        else:
            require(canonical==base.pool.canonical(physical) and row['logical_binding_applied'] is False and
                    row['prospective_logical_demand']==observation['EH_logical_demand'],'EH physical candidate logical scope differs')
            namespace=physical;mode='physical-only-unbound-logical-demand';cohort='EH-physical-candidate'
            extra=dict(logical_binding_applied=False,prospective_logical_demand=row['prospective_logical_demand']);eh+=1
        records.append(dict(canonical=canonical,original_address=address,cohort=cohort,category='application-candidate',
            identity_mode=mode,namespace_identity=namespace,origin_identity=physical,member=row['member'],
            member_sha256=None,source_ledger_sha256=bindings['application_observation'],source_record_ordinal=ordinal,
            source_record_sha256=digest(row),**extra))
    require(overlays==2 and eh==1,'complete broader candidate cohort scope differs')
    return records


def build_manifest(ordinary,application,providers,source_bindings):
    reverse=reverse_planned(providers);all_records=ordinary+application;names=set();ordinary_names=set();counts=Counter()
    require(len(ordinary)==14329 and len(application)==4,'current ordinary/broader epoch differs')
    cohort_source={**{name:name for name in COUNTS},'application-entry':'entry_receipt',
                   'overlay-alternate':'application_observation','EH-physical-candidate':'application_observation'}
    for record in all_records:
        name=record['canonical'];namespace=identity(record['namespace_identity']);origin=identity(record['origin_identity'])
        require(isinstance(record['original_address'],str) and re.fullmatch('0x[0-9a-f]{8}',record['original_address']),'exact observed original address required')
        require(name==base.pool.canonical(namespace) and name not in names,'duplicate or invented prepared canonical namespace')
        require(record['cohort'] in cohort_source and record['source_ledger_sha256']==source_bindings[cohort_source[record['cohort']]] and
                type(record['source_record_ordinal']) is int and
                record['source_record_ordinal']>0 and re.fullmatch('[0-9a-f]{64}',record['source_record_sha256']), 'record lacks exact accepted source binding')
        names.add(name);counts[record['cohort']]+=1
        if record['category']=='ordinary':
            require(record['identity_mode']=='original-selected-physical' and namespace==origin and name in reverse and
                    reverse[name]==(record['original_address'],namespace) and record['logical_binding_applied'] is True,'ordinary physical namespace scope differs')
            ordinary_names.add(name)
        else:
            require(record['category']=='application-candidate' and record['cohort'] in ('application-entry','overlay-alternate','EH-physical-candidate'),
                    'unknown broader application cohort')
            if record['identity_mode']=='physical-only-unbound-logical-demand':
                require(record['cohort']=='EH-physical-candidate' and record['logical_binding_applied'] is False and namespace==origin,
                        'unbound EH candidate cannot become a selected logical provider')
            elif record['cohort']=='application-entry':
                require(record['identity_mode']=='original-selected-physical' and namespace==origin and
                        record['original_address']=='0x0086a850' and record['logical_binding_applied'] is True and
                        name in reverse and reverse[name]==(record['original_address'],namespace),'application entry namespace differs')
            elif record['cohort']=='overlay-alternate':
                require(record['identity_mode']=='original-selected-logical-alternate-object' and namespace!=origin and
                        record['logical_binding_applied'] is True and name in reverse and
                        reverse[name]==(record['original_address'],namespace),'alternate logical/physical identity differs')
            else:require(False,'unknown application identity mode')
    require(dict(counts)==dict(COUNTS,**{'application-entry':1,'overlay-alternate':2,'EH-physical-candidate':1}) and
            len(names)==14333 and len(ordinary_names)==14329,'complete disjoint cohort census differs')
    return dict(schema_version=1,policy_id=POLICY,kind='prepared-CODE-collision-exclusions',
        ordinary_prepared_count=14329,broader_application_candidate_count=4,collision_exclusion_count=14333,
        ordinary_names=sorted(ordinary_names),exclusion_names=sorted(names),records=sorted(all_records,key=lambda r:r['canonical']),
        source_bindings=source_bindings,cohort_counts=dict(counts),
        application_selected_code_count=None,prior_application_observation_count=14330,
        prior_application_observation_excludes_new_first3=True,application_selection_inferred_from_counts=False,
        prepared_namespace_only=True,**FALSE)


def run(args):
    inputs={};start=time.monotonic()
    review=base.load_json(base.observe(args.review,args.review_sha256,inputs))
    require(review.get('schema_version')==1 and review.get('kind')=='prepared-code-exclusions-review-v1' and
            review.get('approved') is True and review.get('independent_source_schema_review_pass') is True and
            review.get('root_authorized') is True and review.get('reviewer') and
            review.get('source_sha256') and set(review['source_sha256'])==set(OWNED) and
            review.get('producer_sha256')==PINS and review.get('artifact_sha256')=={k:h for k,(_,h) in INPUTS.items()} and
            review.get('provider_map_sha256')==prior.MAP_PIN and review.get('provider_map_independently_accepted') is True and
            review.get('allow_native_tools') is False,'independent exact source/input acceptance and delegated root authorization required')
    for relative,h in {**review['source_sha256'],**PINS}.items():base.observe(ROOT/relative,h,inputs)
    for module in (prior,base):require(Path(module.__file__).resolve()==ROOT/'tools/rebuild'/Path(module.__file__).name,'unexpected loaded metadata producer')
    provider_path=base.observe(args.provider_map,prior.MAP_PIN,inputs)
    base.observe(ROOT/'build/rebuild'/prior.MAP_REVIEW[0],prior.MAP_REVIEW[1],inputs)
    data=base.load_json(provider_path)
    sources={key:base.observe(ROOT/'build/rebuild'/rel,h,inputs) for key,(rel,h) in INPUTS.items()}
    reports={name:base.load_json(base.observe(ROOT/'build/rebuild'/filename,base.inventory.EXPECTED[name],inputs)) for name,filename in
        [('selection','function-selection-v2.json'),('manifest','objects-20261103T030230Z-7cfc935c.json'),
         ('retained','retained-verify-full-v3.json'),('owners','runtime-data-owners-native-v1.json')]}
    units={u['recipe_id']:u for u in reports['manifest']['units']};proofs={p['recipe_id']:p for p in reports['retained']['units']}
    require(len(reports['selection']['selections'])==68657 and len(units)==len(proofs)==2988,'complete provider source scope differs')
    prior.validate_provider_map(data,reports['selection']['selections'],units,proofs,reports['owners'])
    providers=data['providers'];read_rows=lambda path:[json.loads(line) for line in Path(path).read_text().splitlines()]
    ledgers={'baseline':read_rows(sources['baseline_members']),'union-v3':read_rows(sources['union_members']),
             'ordinary-first8':base.load_json(sources['first8_members']),'ordinary-relocation-first3':base.load_json(sources['first3_members'])}
    bindings={name:base.file_hash(sources[key]) for name,key in [('baseline','baseline_members'),('union-v3','union_members'),
        ('ordinary-first8','first8_members'),('ordinary-relocation-first3','first3_members'),
        ('entry_receipt','entry_receipt'),('application_observation','application_observation')]}
    ordinary=ordinary_records(ledgers,providers,bindings)
    app=application_records(base.load_json(sources['application_observation']),base.load_json(sources['entry_receipt']),providers,bindings)
    manifest=build_manifest(ordinary,app,providers,bindings)
    manifest.update(provider_map_sha256=prior.MAP_PIN,provider_map_review_sha256=prior.MAP_REVIEW[1],
        source_epoch_artifacts={k:h for k,(_,h) in INPUTS.items()},authority_state='requires-successful-producer-receipt-and-independent-outcome-review')
    out=Path(args.out).resolve();private=(ROOT/'build/rebuild').resolve()
    require(out.is_relative_to(private) and out!=private and not out.exists() and not any(p.is_relative_to(out) for p in inputs),'new exclusive private metadata output required')
    base.stable(inputs);out.mkdir();journal=(out/'progress.jsonl').open('x',encoding='utf-8')
    def note(state,**facts):journal.write(json.dumps(dict(state=state,elapsed_seconds=round(time.monotonic()-start,3),**facts))+'\n');journal.flush();os.fsync(journal.fileno())
    note('started',ordinary_count=14329,application_candidate_count=4,collision_count=14333)
    try:
        for relative,h in review['source_sha256'].items():
            raw=(ROOT/relative).read_bytes();require(base.coff.digest(raw)==h,'reviewed metadata producer changed')
            snapshot=out/'source-snapshots'/relative;snapshot.parent.mkdir(parents=True,exist_ok=True);base.pool.fsynced(snapshot,raw)
        base.budget(start,out);base.save_json(out/'manifest.json',manifest);base.stable(inputs)
        result=dict(schema_version=1,policy_id=POLICY,status='completed',emitted=0,blocked=0,
            manifest_sha256=base.file_hash(out/'manifest.json'),ordinary_prepared_count=14329,broader_application_candidate_count=4,
            collision_exclusion_count=14333,provider_map_sha256=prior.MAP_PIN,review_sha256=args.review_sha256,
            inputs={str(p):h for p,h in inputs.items()},input_stability=True,optional_function_index_present=False,
            source_epoch_artifacts=manifest['source_epoch_artifacts'],resource_observations=base.budget(start,out),**FALSE)
        return base.finalize_success(out,result,inputs,start,journal,note)
    except BaseException as error:
        try:
            if not journal.closed:note('failed',error_type=type(error).__name__,message=str(error))
        except OSError:pass
        base.save_json(out/'abort.json',dict(status='aborted-no-retry',error_type=type(error).__name__,message=str(error),successful_manifest=False,**FALSE));raise
    finally:
        if not journal.closed:journal.close()


def main(argv=None):
    parser=argparse.ArgumentParser(description=__doc__)
    for name in ('provider-map','review','out'):parser.add_argument('--'+name,required=True,type=Path,dest=name.replace('-','_'))
    parser.add_argument('--review-sha256',required=True)
    args=parser.parse_args(argv)
    try:result=run(args)
    except (ValueError,OSError,KeyError,TypeError) as error:parser.exit(2,'prepared CODE manifest rejected: '+str(error)+'\n')
    print(json.dumps({k:result[k] for k in ('status','manifest_sha256','ordinary_prepared_count','collision_exclusion_count')}));return 0


if __name__=='__main__':raise SystemExit(main())
