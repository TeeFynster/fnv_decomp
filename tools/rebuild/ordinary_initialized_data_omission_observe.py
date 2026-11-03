"""Finite authenticated observation of 79 saved views / 26 original objects.

No image, compiler, linker, native process, rewrite, archive or runtime provider.
The accepted original certificate and each typed witness remain distinct.
"""
from __future__ import annotations
import argparse
from collections import defaultdict
import gzip
import hashlib
import importlib
import json
import os
from pathlib import Path
import sys
import time

import ordinary_initialized_data_omission as omission
import runtime_code_inventory as inventory
import scalableordinary_root_collect as finite
from coff_inventory import peak_memory_bytes, reconcile_recipes

ROOT = Path(__file__).resolve().parents[2]
POLICY = 'finite-initialized-data-omission-observation-v1'
CENTRAL_SHA = '290ac0e8c1ffbfd89df7dd6cdbbdb8df363edca58111b7aa19fe842aa26cc8e4'
CENSUS_SHA = '1a17db6186a3d63a44b8ee886e7e676cd58726b6e1b400afc7cd303fd63f5123'
WITNESS_REVIEW_SHA = '9a4a6d410031b3f2410cd9cd1eef0bb841200f7e8f9310fe7f5bb449f1081cfc'
WITNESS_SHA = '1a0e8aa2271218f59c11497c1363b41f099bb259791e19adac7d80718e7a5d7b'
REFERENCE_SHA = 'df1788907c6e26ef4df0b448ead526825336356b5606650165a1ce0825097eb7'
PINS = {'tools/rebuild/ordinary_initialized_data_omission.py': WITNESS_SHA,
        'tools/rebuild/root_code_closure.py': omission.ORDINARY_PIN,
        'tools/rebuild/coff_code_archive.py': omission.PARSER_PIN,
        'tools/rebuild/scalableordinary_root_collect.py': 'e7e5b45df15af0a2bd5cb4a65b36d85ca21eb753656714c0a9a5d8dd919e58ad',
        'tools/rebuild/centralordinary_root_collect.py': '97c827795e46c6d1e6558f6e785266b4e908ddb4c5cf253ec61a71ef19d51409',
        'tools/rebuild/runtime_code_inventory.py': finite.INVENTORY_PIN,
        'tools/rebuild/coff_inventory.py': '3518c044738046e7cd9c8be37a3b1077af750fb2e7a19db793b09999a07ee0d2'}
OWNED = ('tools/rebuild/ordinary_initialized_data_omission_observe.py',
         'tests/rebuild/test_ordinary_initialized_data_omission_observe.py',
         'docs/rebuild/ORDINARY-INITIALIZED-DATA-OMISSION-OBSERVE.md')
FALSE = dict(provider_selected=False, runtime_eligible=False, ABI_verified=False,
             emission_performed=False, native_operations_performed=False,
             compiler_performed=False, executable_link_performed=False,
             game_execution_performed=False, original_data_ownership_proved=False)
require = omission.require
digest = omission.digest


def file_hash(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as stream:
        for part in iter(lambda: stream.read(1024*1024), b''): h.update(part)
    return h.hexdigest()


def observe(path, expected, observations):
    path = Path(path).resolve()
    require(file_hash(path) == expected, 'input fingerprint differs: '+path.name)
    require(path not in observations or observations[path] == expected, 'conflicting input identity')
    observations[path] = expected
    return path


def load(path):
    require(Path(path).stat().st_size <= 128*1024**2, 'bounded JSON input')
    return json.loads(Path(path).read_text(encoding='utf-8-sig'))


def save(path, value):
    with Path(path).open('xb') as stream:
        stream.write((json.dumps(value, sort_keys=True, separators=(',', ':'))+'\n').encode())
        stream.flush(); os.fsync(stream.fileno())


def stable(observations):
    require(not (ROOT/'build/function_index.json').exists(), 'optional index appeared')
    require(all(file_hash(p) == h for p,h in observations.items()), 'protected source/input drift')


def review_gate(path, expected, observations):
    review = load(observe(path, expected, observations))
    require(review.get('schema_version') == 1 and review.get('kind') == 'ordinary-initialized-data-omission-observation-review-v1'
            and review.get('approved') is True and review.get('independent_source_schema_review_pass') is True
            and review.get('root_authorized') is True and review.get('reviewer')
            and review.get('central_observation_independently_accepted') is True
            and review.get('typed_witness_independently_accepted') is True
            and review.get('witness_source_review_sha256') == WITNESS_REVIEW_SHA
            and review.get('central_receipt_sha256') == CENTRAL_SHA and review.get('census_sha256') == CENSUS_SHA
            and review.get('allow_native_tools') is False and review.get('allow_emission') is False,
            'exact independent operational source/schema review and delegated root authority required')
    require(set(review.get('source_sha256', {})) == set(OWNED) and review.get('producer_sha256') == PINS,
            'review source/producer set differs')
    for name,h in {**review['source_sha256'], **PINS}.items(): observe(ROOT/name, h, observations)
    witness_review=load(observe(ROOT/'build/rebuild/code-lane05-synthetic-projection-v1/initialized-omission-source-review-v2.json',
                                WITNESS_REVIEW_SHA,observations))
    require(witness_review.get('status')=='accepted-typed-witness-only'
            and witness_review['source_sha256']['tools/rebuild/ordinary_initialized_data_omission.py']==WITNESS_SHA,
            'accepted typed witness source review differs')
    for module in (omission, inventory, finite):
        require(Path(module.__file__).resolve() == ROOT/'tools/rebuild'/Path(module.__file__).name,
                'unexpected loaded producer module')
    composer_sha = review.get('composer_sha256')
    if composer_sha is not None:
        require(isinstance(composer_sha, str) and len(composer_sha) == 64
                and review.get('composer_independently_accepted') is True,
                'composer exact source review required')
        observe(ROOT/'tools/rebuild/root_certificate_composer.py', composer_sha, observations)
    return review


def cached_contexts(central, census, base, observations, start=None):
    """Consume only the eight exact existing central lane artifacts once."""
    require(central.get('policy_id') == 'central-ordinary-root-views-v1' and central.get('status') == 'metadata-only'
            and central.get('input_stability') is True and central.get('optional_function_index_present') is False
            and central.get('inputs') == dict(inventory.EXPECTED, imports=finite.IMPORT_PIN)
            and central.get('collector_sha256') == PINS['tools/rebuild/centralordinary_root_collect.py']
            and central.get('finite_helper_sha256') == PINS['tools/rebuild/scalableordinary_root_collect.py']
            and central.get('ordinary_observer_sha256') == omission.ORDINARY_PIN
            and central.get('parser_sha256') == omission.PARSER_PIN, 'accepted central envelope differs')
    require(census.get('records_read') == 303 and census.get('selected_records') == 79
            and census.get('singleton_records') == 53 and census.get('union_records') == 26
            and census.get('actual_omission_witness_performed') is False, 'exact finite census differs')
    wanted = {(r['lane'],r['ordinal']):r for r in census['rows']}
    require(len(wanted) == 79, 'duplicate census locator')
    summaries = {(r['lane'],r['lane_record_ordinal']):r for r in central['observations']}
    require(len(summaries) == len(central['observations']) == 303, 'central locator universe differs')
    result = defaultdict(list); seen = set(); selected = set()
    total = 0
    for lane, artifact in sorted(central['lane_artifacts'].items(), key=lambda item:int(item[0])):
        require(artifact['path'] == 'code-lane-%02d.jsonl.gz'%int(lane), 'foreign lane artifact path')
        path = observe(Path(base)/'lanes'/artifact['path'], artifact['sha256'], observations)
        require(path.stat().st_size == artifact['bytes'], 'central compressed extent differs')
        count = 0
        with gzip.open(path, 'rt', encoding='utf-8') as stream:
            for ordinal,line in enumerate(stream,1):
                if start is not None: budget(start)
                count += 1; total += len(line)
                require(len(line) <= 64*1024**2 and total <= 4*1024**3 and count <= 1000, 'central metadata bound')
                key = (int(lane),ordinal); summary = summaries.get(key); row = json.loads(line)
                require(summary and digest(row) == summary['record_sha256'], 'central record identity differs')
                seen.add(key)
                if key not in wanted: continue
                expected = wanted[key]; selected.add(key)
                require(row['event'] == expected['event'] and row['recipe_id'] == expected['recipe_id']
                        and row['requested_roots'] == expected['requested_roots']
                        and digest(row) == expected['record_sha256']
                        and digest(row['certificate']) == row['certificate_sha256'] == expected['certificate_sha256']
                        and digest(row['contract']) == row['contract_identity_sha256'] == expected['contract_identity_sha256']
                        and row['certificate']['contract_identity_sha256'] == row['contract_identity_sha256']
                        and row['provenance'] == row['contract']['provenance'], 'selected view/census identity differs')
                result[row['recipe_id']].append(dict(lane=int(lane), ordinal=ordinal, row=row,
                    sections=sorted(c['section'] for c in expected['candidates'])))
        require(count == artifact['records'], 'central artifact record coverage differs')
    require(seen == set(summaries) and selected == set(wanted) and len(result) == 26, 'finite central coverage differs')
    return result


def observe_group(raw, contexts, composer=None):
    """Raw bytes materialized once by the caller, reused for each scoped view."""
    results = []
    for context in contexts:
        row = context['row']; contract = row['contract']; base = row['certificate']
        typed = omission.observe_omitted_initialized_data(raw, contract, base, context['sections'])
        result = dict(lane=context['lane'], ordinal=context['ordinal'], event=row['event'],
            recipe_id=row['recipe_id'], requested_roots=row['requested_roots'],
            central_record_sha256=digest(row), contract_identity_sha256=digest(contract),
            original_certificate_sha256=digest(base), witness=typed, witness_sha256=digest(typed))
        if composer is not None:
            composed = composer(raw, contract, base, [typed])
            result.update(composition=composed, composition_sha256=digest(composed))
        results.append(result)
    return results


def budget(start, output=None):
    require(time.monotonic()-start <= 900, 'sampled 15-minute budget')
    peak = peak_memory_bytes(); require(peak is not None and peak <= 1024**3, 'sampled 1-GiB peak memory budget')
    size = 0
    if output is not None:
        for parent,dirs,files in os.walk(output, followlinks=False):
            require(all(not (Path(parent)/name).is_symlink() for name in dirs+files), 'output symlink')
            for name in files: size += (Path(parent)/name).stat().st_size
        require(size <= 128*1024**2, 'private 128-MiB output budget')
    return dict(elapsed_seconds=round(time.monotonic()-start,3), peak_memory_bytes=peak, output_bytes=size)


def publish_receipt(output, value, observations, start):
    path=Path(output)/'receipt.json'; pending=Path(output)/'receipt.pending.json'; linked=False
    stable(observations); budget(start,output)
    try:
        save(pending,value); stable(observations); budget(start,output)
        os.link(pending,path); linked=True
        stable(observations); budget(start,output)
    except BaseException:
        if linked and path.exists() and os.path.samefile(path,pending): path.unlink()
        raise


def run(args):
    start=time.monotonic(); observations={}
    review=review_gate(args.review,args.review_sha256,observations)
    base=ROOT/'build/rebuild/central-code-root-observation-v1'
    central=load(observe(base/'receipt.json',CENTRAL_SHA,observations))
    census=load(observe(ROOT/'build/rebuild/code-lane03-data-omission-v1/metadata-census.json',CENSUS_SHA,observations))
    contexts=cached_contexts(central,census,base,observations,start); budget(start)
    manifest=load(observe(ROOT/'build/rebuild/objects-20261103T030230Z-7cfc935c.json',inventory.EXPECTED['manifest'],observations))
    retained=load(observe(ROOT/'build/rebuild/retained-verify-full-v3.json',inventory.EXPECTED['retained'],observations))
    selection=load(observe(ROOT/'build/rebuild/function-selection-v2.json',inventory.EXPECTED['selection'],observations))
    recipes=observe(ROOT/'build/units.json',inventory.EXPECTED['recipes'],observations)
    require(reconcile_recipes(manifest,recipes)['verified'], 'original authoritative recipes differ')
    require(retained['scope']['full_authoritative'] is True and all(retained[k] is True for k in
                ('retained_verification_pass','function_byte_verification_pass','global_listed_eh_coverage_pass',
                 'original_oracle_parity_pass','evidence_stable')), 'original full MATCH gates differ')
    require(retained['inputs']['retained_manifest_sha256'] == inventory.EXPECTED['manifest']
            and retained['inputs']['recipe_sha256'] == inventory.EXPECTED['recipes']
            and retained['inputs']['image_sha256'] == REFERENCE_SHA
            and retained['inputs']['function_index_present'] is False
            and retained['inputs']['function_index_sha256'] is None, 'original oracle lineage differs')
    require(selection['function_index_present'] is False and selection['runtime_eligible'] is False
            and selection['link_ready'] is False
            and selection['input_sha256']['recipe'] == inventory.EXPECTED['recipes']
            and selection['input_sha256']['manifest'] == inventory.EXPECTED['manifest']
            and selection['input_sha256']['receipt'] == inventory.EXPECTED['retained'], 'selection lineage differs')
    for name,h in retained['inputs']['tools_sha256'].items():
        path=(ROOT/name).resolve(); require(path.is_relative_to(ROOT/'tools'), 'foreign retained comparison dependency')
        observe(path,h,observations)
    observe(ROOT/'build/image_check.json',retained['inputs']['image_check_sha256'],observations)
    units={u['recipe_id']:u for u in manifest['units']}; proofs={u['recipe_id']:u for u in retained['units']}
    native={}
    for rid,views in contexts.items():
        unit=units[rid]; proof=proofs[rid]; inventory.check_unit(unit,proof)
        selected={r['original_address']:r for r in inventory.selected_rows(unit,proof,selection['selections'])}
        for context in views:
            row=context['row']; provenance=row['contract']['provenance']
            require(provenance['object_sha256'] == unit['object_sha256'] and provenance['source_sha256'] == unit['source_sha256']
                    and provenance['recipe_id'] == rid and provenance['recipe_index'] == unit['recipe_index']
                    and provenance['reference_identity_sha256'] == REFERENCE_SHA, 'view original source/object lineage differs')
            for root in row['requested_roots']:
                require(root['original_address'] in selected and root['object_sha256'] == unit['object_sha256']
                        and root['source_sha256'] == unit['source_sha256']
                        and all(root[k] == selected[root['original_address']][k] for k in ('recipe_id','recipe_index','symbol','section','value','size')),
                        'view original selected physical owner differs')
            for relative,h in provenance['dependency_tools_sha256'].items():
                path=(ROOT/relative).resolve(); require(path.is_relative_to(ROOT/'tools'), 'foreign original producer dependency')
                observe(path,h,observations)
        source=(ROOT/unit['source']).resolve(); require(source.is_relative_to(ROOT), 'foreign source path')
        observe(source,unit['source_sha256'],observations)
        obj=(ROOT/'build/rebuild'/manifest.get('object_root_relative','.')/unit['object']).resolve()
        require(obj.is_relative_to(ROOT/'build/rebuild') and obj.stat().st_size <= 16*1024**2, 'bounded exact private object path')
        require(obj not in native.values(), 'repeated native object path');native[rid]=obj
        observations[obj]=unit['object_sha256']  # Actual content is materialized and hashed once below.
    out=Path(args.out).resolve(); private=(ROOT/'build/rebuild').resolve()
    require(out.is_relative_to(private) and out!=private and not out.exists()
            and not any(path.is_relative_to(out) for path in observations), 'exclusive new private output required')
    # Preflight stability deliberately excludes native objects: their first body
    # read is the materialization below; terminal stability rehashes those files.
    stable({p:h for p,h in observations.items() if p not in set(native.values())})
    out.mkdir(); journal=(out/'progress.jsonl').open('x',encoding='utf-8')
    def note(state,**facts):
        journal.write(json.dumps(dict(state=state,elapsed_seconds=round(time.monotonic()-start,3),**facts))+'\n')
        journal.flush();os.fsync(journal.fileno())
    complete=[]
    try:
        note('started',views=79,objects=26,review_sha256=args.review_sha256)
        snapshots={**review['source_sha256'], 'tools/rebuild/ordinary_initialized_data_omission.py':WITNESS_SHA}
        if review.get('composer_sha256') is not None:
            snapshots['tools/rebuild/root_certificate_composer.py']=review['composer_sha256']
        for relative,h in snapshots.items():
            target=out/'source-snapshots'/relative;target.parent.mkdir(parents=True,exist_ok=True)
            raw=(ROOT/relative).read_bytes();require(hashlib.sha256(raw).hexdigest()==h,'source snapshot drift')
            with target.open('xb') as stream:stream.write(raw);stream.flush();os.fsync(stream.fileno())
        composer=None
        if review.get('composer_sha256') is not None:
            module=importlib.import_module('root_certificate_composer')
            require(Path(module.__file__).resolve()==ROOT/'tools/rebuild/root_certificate_composer.py', 'foreign composer module')
            composer=lambda raw,contract,base,witnesses: module.compose(raw,contract,base,witnesses,policy_id=module.POLICY)
        path=out/'witnesses.jsonl.gz'
        with path.open('xb') as target:
            with gzip.GzipFile(fileobj=target,mode='wb',mtime=0) as compressed:
                for rid in sorted(contexts):
                    budget(start,out); raw=native[rid].read_bytes()
                    require(hashlib.sha256(raw).hexdigest()==units[rid]['object_sha256'], 'exact original object changed')
                    results=observe_group(raw,contexts[rid],composer)
                    for result in results:
                        compressed.write((json.dumps(result,sort_keys=True,separators=(',',':'))+'\n').encode());complete.append(result)
                    del raw
                    note('recipe_observed',recipe_id=rid,views=len(results),complete_views=len(complete))
            target.flush();os.fsync(target.fileno())
        require(len(complete)==79, 'finite view outcome coverage differs')
        usage=budget(start,out); stable(observations)
        result=dict(schema_version=1,policy_id=POLICY,status='observed-typed-witnesses-only',
            central_receipt_sha256=CENTRAL_SHA,census_sha256=CENSUS_SHA,review_sha256=args.review_sha256,
            source_sha256=review['source_sha256'],producer_sha256=PINS,witnesses_sha256=file_hash(path),
            views=79,objects=26,passed_views=sum(r['witness']['witness_complete'] for r in complete),
            discharged_blockers=sum(len(r['witness']['discharge_blocker_ids']) for r in complete),
            original_certificates_unchanged=True,composer_used=composer is not None,
            inputs={str(p):h for p,h in observations.items()},inputs_stable=True,
            resource_observations=usage,**FALSE)
        note('verified_awaiting_terminal_receipt',views=79);journal.close()
        publish_receipt(out,result,observations,start);return result
    except BaseException as error:
        try:
            if not journal.closed:note('aborted',error_type=type(error).__name__,complete_views=len(complete))
        except OSError:pass
        save(out/'abort.json',dict(schema_version=1,status='aborted-no-retry',error_type=type(error).__name__,
            complete_views=len(complete),successful_observation=False,**FALSE))
        raise
    finally:
        if not journal.closed:journal.close()


def main(argv=None):
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--review',type=Path,required=True);parser.add_argument('--review-sha256',required=True)
    parser.add_argument('--out',type=Path,required=True)
    args=parser.parse_args(argv);result=run(args)
    print(json.dumps({k:v for k,v in result.items() if k not in ('inputs',)},sort_keys=True));return 0


if __name__=='__main__':raise SystemExit(main())
