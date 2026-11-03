"""Finite ordinary CODE projection: original physical identities, no providers.

V1 deliberately accepts only zero-relocation retained CODE roots. Positive
omission evidence never authorizes EH, TLS, namespace groups or field repair.
Actual operation consumes a reviewed hash-bound central certificate bundle.
"""
from __future__ import annotations
import argparse
from collections import Counter
import gzip
import hashlib
import json
import os
from pathlib import Path
import re
import sys
import time
import coff_code_archive as coff
import runtime_code_pool as pool
import root_code_closure as ordinary
import scalableordinary_root_collect as collector
import bulk_code_pool as bulk
import runtime_code_inventory as inventory
from coff_inventory import peak_memory_bytes, reconcile_recipes

ROOT = Path(__file__).resolve().parents[2]
POLICY = 'finite-ordinary-zero-relocation-projection-v1'
ROOT_KEYS = collector.ROOT_KEYS
NATIVE_KEYS = ('original_address', 'symbol', 'symbol_index', 'section', 'value', 'size')
CONTRACT_KEYS = {'recipe_id','roots','export_policy','verified_match','fields_complete',
    'missing_fields_complete','unit_proofs_complete','fields','missing_fields','parent_eh',
    'omission_field_proofs','unit_verified_functions','iat_import_observation','provenance'}
PINS = {'tools/rebuild/coff_code_archive.py': collector.PARSER_PIN,
    'tools/rebuild/root_code_closure.py': collector.ORDINARY_PIN,
    'tools/rebuild/runtime_code_pool.py': '729f189e2893c7f3a3e3cd97df7d7381ac115169e1d75cf664e6bbc1c587b277',
    'tools/rebuild/scalableordinary_root_collect.py': 'e7e5b45df15af0a2bd5cb4a65b36d85ca21eb753656714c0a9a5d8dd919e58ad'}
PINS.update({'tools/rebuild/centralordinary_root_collect.py':'97c827795e46c6d1e6558f6e785266b4e908ddb4c5cf253ec61a71ef19d51409',
    'tools/rebuild/bulk_code_pool.py':'4e6d697c1881c56c4c3f6a84788df6e0e2617b284d8e0226805828829bce49ed',
    'tools/rebuild/runtime_code_inventory.py':collector.INVENTORY_PIN,
    'tools/rebuild/coff_inventory.py':'3518c044738046e7cd9c8be37a3b1077af750fb2e7a19db793b09999a07ee0d2',
    **pool.READER_DEPENDENCIES})
OWNED = ('tools/rebuild/ordinary_code_projection.py','tests/rebuild/test_ordinary_code_projection.py',
         'docs/rebuild/ORDINARY-CODE-PROJECTION.md')
BASELINE = {'coverage.jsonl.gz':'e29cef9c0169ea19ac39724d3acb33163b101d9f21e8eed970c8071253d4ec16',
    'members.jsonl':'a3232bd7c19dd41b67f0d4e85d8b3a9e8b4c18b8f95d065f2286dd75fe7da105',
    'receipt.json':'ad870815321b42485378b0f896340bfd0b70cd52aea0dd27ffc39725bd93ce14'}
FALSE = dict(provider_selected=False, runtime_eligible=False, ABI_verified=False,
    link_ready=False, native_tools_run=False, compiler_performed=False,
    executable_link_performed=False, game_execution_performed=False)
require = coff.require


def digest(value):
    return hashlib.sha256(json.dumps(value, sort_keys=True, separators=(',', ':'), ensure_ascii=True).encode()).hexdigest()


def file_hash(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as f:
        for part in iter(lambda: f.read(1048576), b''): h.update(part)
    return h.hexdigest()


def project_member(raw, contract, certificate, requested_roots):
    """Pure projection; the operational caller authenticates collector lineage.

    Replays the complete frozen omission observation on fresh native bytes.
    This is independent of historical all-size candidate status. No reference
    certificate, alias or omitted-definition conversion is accepted by v1.
    """
    require(isinstance(raw, bytes) and 0 < len(raw) <= 16*1024**2, 'native object bound')
    require(isinstance(contract, dict) and set(contract) == CONTRACT_KEYS, 'unknown ordinary contract schema')
    require(isinstance(requested_roots, list) and 0 < len(requested_roots) <= 205, 'finite requested root bound')
    require(all(isinstance(r, dict) and set(r) == ROOT_KEYS for r in requested_roots), 'exact physical root schema required')
    require(len({r['original_address'] for r in requested_roots}) == len(requested_roots) and
            len({r['symbol_index'] for r in requested_roots}) == len(requested_roots), 'duplicate requested identity')
    provenance = contract['provenance']; original_hash = coff.digest(raw)
    require(provenance.get('object_sha256') == original_hash, 'native object identity differs')
    for r in requested_roots:
        require(all(type(r[k]) is int for k in ('recipe_index','symbol_index','section','value','size')) and
                r['recipe_index'] >= 0 and r['symbol_index'] >= 0 and
                isinstance(r['source_sha256'],str) and re.fullmatch('[0-9a-f]{64}',r['source_sha256']) and
                r['object_sha256'] == original_hash and r['source_sha256'] == provenance.get('source_sha256') and
                r['recipe_index'] == provenance.get('recipe_index') and
                r['recipe_id'] == contract['recipe_id'] == provenance.get('recipe_id'), 'requested provenance differs')
        require(re.fullmatch('0x[0-9a-f]{8}', r['original_address']) and r['value'] == 0 and r['size'] > 0,
                'unsupported requested native extent')
    roots = [{k:r[k] for k in NATIVE_KEYS} for r in requested_roots]
    require(roots == contract['roots'] == certificate.get('roots'), 'exact ordered root scope differs')
    require(contract['fields'] == [] and contract['missing_fields'] == [] and contract['parent_eh'] == [],
            'v1 requires zero fields and no missing fields/EH')
    obj = coff.parse(raw)
    replay = ordinary.assess_object(obj, contract)
    require(replay == certificate and replay['contract_identity_sha256'] == digest(contract), 'stale/forged omission certificate')
    require(replay['closure_observed'] is True and replay['graph_observation_complete'] is True and
            not replay['blockers'] and replay['policy_id'] == ordinary.POLICY, 'ordinary omission blocked')
    require(not contract['fields'] and not contract['missing_fields'] and not contract['parent_eh'] and
            not replay['references'] and not replay['omitted_definition_conversions'], 'v1 requires zero fields and no conversions/EH')
    sections = replay['retained_section_indices']; symbols = replay['retained_primary_indices']
    require(sections == sorted(set(sections)) and symbols == sorted(set(symbols)), 'non-bijective retained identity sets')
    runtime = replay['retained_runtime_section_indices']
    require(sorted(r['section'] for r in roots) == runtime and len(set(runtime)) == len(roots), 'runtime/root section scope differs')
    require(all(not obj['sections'][s]['relocs'] for s in sections), 'retained relocation requires later reviewed field consumer')
    directive = [s for s in sections if obj['sections'][s]['name'] == '.drectve']
    require(len(directive) == 1 and set(sections) == set(runtime) | set(directive), 'exact directives and CODE only')
    require(re.findall(r'/\S+', obj['sections'][directive[0]]['payload'].decode('ascii')) == ordinary.DEFAULTS,
            'exact directive policy differs')
    bindings = []
    for r in requested_roots:
        s = obj['symbols'].get(r['symbol_index']); sec = obj['sections'][r['section']]
        require(s and (s['name'],s['section'],s['value'],s['type'],s['storage'],s['aux_count']) ==
                (r['symbol'],r['section'],0,32,2,0) and sec['name'] == '.text' and
                sec['flags'] == 0x60501020 and sec['size'] == r['size'], 'native requested owner differs')
        identity = {k:r[k] for k in ('recipe_id','object_sha256','symbol_index')}
        bindings.append((r['symbol_index'], pool.canonical(identity)))
    expected_slots = sorted(k for i in symbols for k in range(i, i+1+obj['symbols'][i]['aux_count']))
    require(expected_slots == replay['retained_physical_slots'] and len(expected_slots) == len(set(expected_slots)),
            'retained primary/auxiliary universe differs')
    require(sorted(i for i in symbols if obj['symbols'][i]['storage'] == 2) == sorted(r['symbol_index'] for r in roots),
            'unexpected retained external definition/reference')
    named = coff.namespace(raw, bindings)  # Frozen numeric-index-preserving phase.
    output, maps = coff.serialize(named, sections, symbols, ())
    coff.verify_selection(named, output, maps)
    after = coff.parse(output)
    expected_exports = sorted(n for _,n in bindings)
    require(coff.exports(output) == expected_exports and len(expected_exports) == len(set(expected_exports)),
            'missing/extra/duplicate canonical export')
    require(not any(s['storage'] == 2 and s['section'] <= 0 for s in after['symbols'].values()) and
            not any(s['relocs'] for s in after['sections'].values()), 'unexpected unresolved field/reference')
    require(len(after['sections']) == len(sections) and after['symbol_count'] == len(expected_slots),
            'serialized table identity coverage differs')
    return output, dict(schema_version=1, policy_id=POLICY, original_object_sha256=original_hash,
        output_sha256=coff.digest(output), contract_identity_sha256=digest(contract),
        certificate_sha256=digest(certificate), requested_roots=requested_roots,
        maps=maps, namespace_bindings=bindings, exports=expected_exports, undefined=[],
        code_bytes=sum(r['size'] for r in roots), relocation_count=0,
        independent_closure_replay=True, namespace_numeric_indices_preserved=True,
        section_symbol_auxiliary_bijections_verified=True, **FALSE)


def load_json(path):
    require(Path(path).stat().st_size <= 128*1024**2, 'JSON metadata bound')
    return json.loads(Path(path).read_text(encoding='utf-8-sig'))


def save_json(path, value):
    data=(json.dumps(value,sort_keys=True,separators=(',',':'))+'\n').encode()
    with Path(path).open('xb') as f: f.write(data);f.flush();os.fsync(f.fileno())


def observe(path, expected, inputs):
    path=Path(path).resolve();require(file_hash(path)==expected,'input hash differs: '+path.name)
    require(path not in inputs or inputs[path]==expected,'conflicting input identity');inputs[path]=expected
    return path


def stable(inputs):
    require(not (ROOT/'build/function_index.json').exists(), 'optional index appeared')
    require(all(file_hash(p)==h for p,h in inputs.items()), 'protected input/source changed')


def publish_receipt(output, result, inputs, start):
    """No successful terminal receipt survives a failed post-publication gate."""
    path=Path(output)/'receipt.json';pending=Path(output)/'receipt.pending.json';linked=False
    stable(inputs);budget(start,output)
    try:
        save_json(pending,result)
        stable(inputs);budget(start,output)
        os.link(pending,path);linked=True  # Exclusive atomic name publication.
        stable(inputs);budget(start,output)
    except BaseException:
        if linked and path.exists() and os.path.samefile(path,pending):path.unlink()
        raise


def finalize_success(output, result, inputs, start, journal, note):
    # The terminal journal must be durable and closed BEFORE success becomes
    # visible. No subsequent journal write/close may invalidate publication.
    note('verified_awaiting_terminal_receipt',emitted=result['emitted'],blocked=result['blocked'])
    journal.close()
    publish_receipt(output,result,inputs,start)
    return result


def budget(start, output):
    require(time.monotonic()-start <= 900, '15-minute sampled time budget')
    memory=peak_memory_bytes();require(memory is not None and memory <= 1024**3, '1-GiB sampled peak memory budget')
    # Only this exclusive owned directory, never the wider repository.
    total=0
    for parent,dirs,files in os.walk(output,followlinks=False):
        for name in dirs+files: require(not (Path(parent)/name).is_symlink(), 'output symlink')
        for name in files: total+=(Path(parent)/name).stat().st_size
    require(total <= 128*1024**2, '128-MiB private output budget')
    return dict(peak_memory_bytes=memory,output_bytes=total,elapsed_seconds=round(time.monotonic()-start,3))


def review_gate(path, expected, request_hash, central_hash, inputs):
    review=load_json(observe(path,expected,inputs))
    require(review.get('schema_version')==1 and review.get('kind')=='ordinary-code-projection-review-v1' and
            review.get('approved') is True and review.get('independent_source_schema_review_pass') is True and
            review.get('root_authorized') is True and review.get('reviewer') and
            review.get('request_sha256')==request_hash and review.get('central_receipt_sha256')==central_hash and
            review.get('central_observation_independently_accepted') is True and
            review.get('allow_native_tools') is False and review.get('allow_executable_link') is False,
            'independent exact source/central evidence review and delegated root authorization required')
    require(set(review.get('source_sha256',{}))==set(OWNED) and review.get('producer_sha256')==PINS,
            'reviewed source/producer set differs')
    for name,h in {**review['source_sha256'],**PINS}.items(): observe(ROOT/name,h,inputs)
    for module in (coff,pool,ordinary,collector,bulk,inventory):
        require(Path(module.__file__).resolve()==ROOT/'tools/rebuild'/Path(module.__file__).name,'unexpected loaded producer')
    return review


def central_records(central, lanes_dir, inputs, wanted=None, start=None):
    """One pass over each hash-bound central metadata lane, no old archive read."""
    require(central.get('schema_version')==1 and central.get('policy_id')=='central-ordinary-root-views-v1' and
            central.get('status')=='metadata-only' and central.get('input_stability') is True and
            central.get('optional_function_index_present') is False and central.get('inputs')==dict(inventory.EXPECTED,imports=collector.IMPORT_PIN) and
            central.get('collector_sha256')==PINS['tools/rebuild/centralordinary_root_collect.py'] and
            central.get('ordinary_observer_sha256')==collector.ORDINARY_PIN and
            central.get('finite_helper_sha256')==PINS['tools/rebuild/scalableordinary_root_collect.py'] and
            central.get('parser_sha256')==collector.PARSER_PIN, 'unaccepted central provenance/schema')
    summaries={(r['lane'],r['lane_record_ordinal']):r for r in central['observations']}
    require(len(summaries)==len(central['observations']), 'duplicate central record locator')
    result={};seen=set();addresses=set();total=0
    for lane,artifact in sorted(central['lane_artifacts'].items(),key=lambda p:int(p[0])):
        require(re.fullmatch(r'code-lane-\d\d.jsonl.gz',artifact['path']), 'foreign central lane path')
        path=observe(Path(lanes_dir)/artifact['path'],artifact['sha256'],inputs)
        require(path.stat().st_size==artifact['bytes'], 'central artifact extent differs')
        count=0
        with gzip.open(path,'rt',encoding='utf-8') as stream:
            for line in stream:
                count+=1;total+=len(line);require(len(line)<=64*1024**2 and total<=4*1024**3 and count<=1000,'central record bounds')
                if start is not None:
                    require(time.monotonic()-start<=900,'central metadata read time budget')
                    memory=peak_memory_bytes();require(memory is not None and memory<=1024**3,'central metadata peak memory budget')
                row=json.loads(line);key=(int(lane),count);summary=summaries.get(key)
                require(summary and digest(row)==summary['record_sha256'] and
                        summary['event']==row['event'] and summary['roots']==[r['original_address'] for r in row['requested_roots']],
                        'central record/summary identity differs');seen.add(key)
                if row['event']!='SINGLE_ROOT_OBSERVATION':continue
                roots=row['requested_roots'];require(len(roots)==1,'non-singleton operational scope')
                a=roots[0]['original_address'];require(a not in addresses,'duplicate central singleton');addresses.add(a)
                require(row['contract_identity_sha256']==digest(row['contract']) and
                        row['provenance']==row['contract']['provenance'], 'central contract hash/provenance differs')
                if 'certificate' in row:
                    require(row['certificate_sha256']==digest(row['certificate']) and
                            row['certificate']['contract_identity_sha256']==row['contract_identity_sha256'], 'central certificate identity differs')
                if wanted is None or a in wanted:result[a]=dict(row=row,record_sha256=summary['record_sha256'],lane=int(lane),ordinal=count)
        require(count==artifact['records'], 'central lane coverage differs')
    require(seen==set(summaries) and len(addresses)==central['summary']['roots'] and
            (wanted is None or set(wanted)<=addresses), 'complete central singleton accounting')
    return result


def baseline_membership(members_path):
    rows=[json.loads(line) for line in Path(members_path).read_text().splitlines()]
    exports=[s for r in rows for s in r['exports']]
    require(len(rows)==1019 and len(exports)==len(set(exports))==12946,'accepted baseline export census')
    return set(exports)


def checked_reference(path, oracle, image_ok):
    pe=oracle.Pe(path)
    require(coff.digest(pe.data)==pool.PINS['reference'], 'loaded owned reference digest differs')
    require(image_ok(pe)[0], 'unchanged owned image probe gate')
    return pe


def require_historical_scope(original, requested):
    """V1 cannot duplicate a root from either historical candidate archive.

    The accepted 1,372-export supplemental pool is a subset of BLOCKED_UNION
    candidates. Restricting this initial adapter to HISTORICAL_BLOCKED roots
    keeps both existing candidate lanes disjoint without provider selection.
    """
    seen=set();counts=Counter();joined={}
    with gzip.open(original,'rt') as stream:
        for line in stream:
            require(len(line)<=4*1024**2,'baseline coverage row bound');row=json.loads(line);a=row['original_address']
            require(a not in seen,'duplicate baseline owner');seen.add(a);counts[row['status']]+=1
            if a not in requested:continue
            r=requested[a]
            require(row['status']=='HISTORICAL_BLOCKED','v1 requires upstream HISTORICAL_BLOCKED, never prior candidate roots')
            require(row['physical_identity']=={k:r[k] for k in ('recipe_id','object_sha256','symbol_index')} and
                    all(row['selected_native'][k]==r[k] for k in NATIVE_KEYS),'baseline requested physical identity differs')
            joined[a]=dict(status=row['status'],baseline_row_sha256=digest(row))
    require(len(seen)==68657 and dict(counts)==dict(EMITTED=12946,HISTORICAL_BLOCKED=51798,BLOCKED_UNION=3913) and
            set(joined)==set(requested),'complete upstream baseline/request scope differs')
    return joined


def write_coverage(path, original, requested, emitted):
    counts=Counter();seen=set()
    with Path(path).open('xb') as target:
        with gzip.GzipFile(fileobj=target,mode='wb',mtime=0) as out,gzip.open(original,'rt') as stream:
            for line in stream:
                require(len(line)<=4*1024**2,'coverage row bound');r=json.loads(line);a=r['original_address']
                require(a not in seen,'duplicate historical coverage');seen.add(a)
                require(a not in emitted or r['status']!='EMITTED','baseline owner replacement forbidden')
                require(a not in requested or r['status']=='HISTORICAL_BLOCKED','requested prior candidate identity cannot be projected by v1')
                status='EMITTED_ORDINARY_NO_RELOCATION' if a in emitted else 'BLOCKED_REQUESTED_ORDINARY' if a in requested else 'NOT_REQUESTED'
                counts[status]+=1;r=dict(r,ordinary_projection_status=status,baseline_status_preserved=True)
                out.write((json.dumps(r,sort_keys=True,separators=(',',':'))+'\n').encode())
        target.flush();os.fsync(target.fileno())
    require(len(seen)==68657 and requested<=seen,'full baseline owner accounting differs')
    return dict(counts)


def run(args):
    start=time.monotonic();inputs={}
    request=load_json(observe(args.request,args.request_sha256,inputs))
    require(set(request)=={'schema_version','kind','roots'} and type(request['schema_version']) is int and
            request['schema_version']==1 and request['kind']=='fnv-finite-ordinary-root-request' and
            isinstance(request['roots'],list) and 0<len(request['roots'])<=205,'finite request schema')
    roots=request['roots'];require(all(set(r)==ROOT_KEYS for r in roots),'physical root schema')
    wanted={r['original_address']:r for r in roots};require(len(wanted)==len(roots),'duplicate requested address')
    central=load_json(observe(args.central_receipt,args.central_receipt_sha256,inputs))
    review=review_gate(args.review,args.review_sha256,args.request_sha256,args.central_receipt_sha256,inputs)
    records=central_records(central,args.lanes_dir,inputs,set(wanted),start)
    require(set(wanted)<=set(records) and all(records[a]['row']['requested_roots']==[r] for a,r in wanted.items()),'request/accepted physical singleton differs')
    # Reopen authoritative manifests and complete v3 native MATCH proofs, not body caches.
    basis={}
    filenames={'selection':'function-selection-v2.json','manifest':'objects-20261103T030230Z-7cfc935c.json',
               'retained':'retained-verify-full-v3.json'}
    for name,rel in filenames.items():basis[name]=load_json(observe(ROOT/'build/rebuild'/rel,inventory.EXPECTED[name],inputs))
    recipes=observe(ROOT/'build/units.json',inventory.EXPECTED['recipes'],inputs)
    require(reconcile_recipes(basis['manifest'],recipes)['verified'],'authoritative recipe reconciliation')
    units={u['recipe_id']:u for u in basis['manifest']['units']};proofs={u['recipe_id']:u for u in basis['retained']['units']}
    baseline=ROOT/'build/rebuild/bulk-code-pool-all-current-v1/production'
    for rel,h in BASELINE.items():observe(baseline/rel,h,inputs)
    baseline_exports=baseline_membership(baseline/'members.jsonl')
    upstream_scope=require_historical_scope(baseline/'coverage.jsonl.gz',wanted)
    for name,h in basis['retained']['inputs']['tools_sha256'].items():observe(ROOT/name,h,inputs)
    observe(ROOT/'build/image_check.json',basis['retained']['inputs']['image_check_sha256'],inputs)
    reference=observe(args.reference,pool.PINS['reference'],inputs)
    out=Path(args.out).resolve();private=(ROOT/'build/rebuild').resolve()
    require(out.is_relative_to(private) and out!=private and not out.exists() and not any(p.is_relative_to(out) for p in inputs), 'new exclusive private output required')
    # Reserve every exact input path up front, without opening unrequested objects.
    eligible=[];blocked=[];physical=set()
    for a,r in sorted(wanted.items()):
        record=records[a];row=record['row'];u=units.get(r['recipe_id']);pv=proofs.get(r['recipe_id'])
        require(u and pv,'unknown requested recipe');inventory.check_unit(u,pv)
        choices={f['original_address']:f for f in inventory.selected_rows(u,pv,basis['selection']['selections'])}
        require(a in choices and all(r[k]==choices[a][k] for k in ('recipe_id','recipe_index','symbol','section','value','size')) and
                r['object_sha256']==u['object_sha256'] and r['source_sha256']==u['source_sha256'],'requested v3/selection identity differs')
        require((r['recipe_id'],r['symbol_index']) not in physical,'duplicate physical root');physical.add((r['recipe_id'],r['symbol_index']))
        name=pool.canonical({k:r[k] for k in ('recipe_id','object_sha256','symbol_index')})
        require(name not in baseline_exports,'competing baseline logical CODE export')
        contract=row['contract'];cert=row.get('certificate')
        for relative,h in contract['provenance']['dependency_tools_sha256'].items():
            p=(ROOT/relative).resolve();require(p.is_relative_to(ROOT/'tools'),'foreign producer dependency')
            if p in inputs:require(inputs[p]==h,'conflicting central dependency identity')
            else:observe(p,h,inputs)
        reasons=[]
        if row['closure_observed'] is not True or not cert:reasons.append('ORDINARY_CLOSURE_BLOCKED')
        if contract['fields'] or contract['missing_fields'] or contract['parent_eh']:reasons.append('V1_REQUIRES_NO_RELOCATION_OR_EH')
        if cert and (cert['references'] or cert['omitted_definition_conversions']):reasons.append('V1_REFERENCE_OR_CONVERSION_UNSUPPORTED')
        if reasons:blocked.append(dict(root=r,reasons=reasons,central_record_sha256=record['record_sha256'],fresh_body_compared=False));continue
        source=(ROOT/u['source']).resolve();obj=(ROOT/'build/rebuild'/basis['manifest'].get('object_root_relative','.')/u['object']).resolve()
        require(source.is_relative_to(ROOT) and obj!=out and not obj.is_relative_to(out),'source/object output overlap')
        require(obj.stat().st_size<=16*1024**2,'native object read bound')
        observe(source,r['source_sha256'],inputs);observe(obj,r['object_sha256'],inputs)
        eligible.append((r,row,u,obj))
    stable(inputs);out.mkdir();journal=(out/'progress.jsonl').open('x',encoding='utf-8')
    def note(state,**facts):journal.write(json.dumps(dict(state=state,elapsed_seconds=round(time.monotonic()-start,3),**facts))+'\n');journal.flush();os.fsync(journal.fileno())
    note('started',request_sha256=args.request_sha256,central_receipt_sha256=args.central_receipt_sha256,requested=len(roots),eligible_for_fresh_projection=len(eligible))
    emitted=[];members=[];member_receipts=[]
    try:
        for relative,h in review['source_sha256'].items():
            p=out/'source-snapshots'/relative;p.parent.mkdir(parents=True,exist_ok=True);raw=(ROOT/relative).read_bytes();require(coff.digest(raw)==h,'source snapshot drift');pool.fsynced(p,raw)
        sys.path.insert(0,str(ROOT/'tools'));import compare as oracle
        from build_and_match import image_ok
        pe=checked_reference(reference,oracle,image_ok)
        for sequence,(r,row,u,objpath) in enumerate(eligible):
            budget(start,out);raw=objpath.read_bytes();contract=row['contract'];cert=row['certificate']
            output,projection=project_member(raw,contract,cert,[r])
            compare_contracts=[dict(selected={k:r[k] for k in NATIVE_KEYS})]
            before=bulk.compare_functions(objpath,pe,compare_contracts,u['recipe'])
            name='ordinary-%03d-%s.obj'%(sequence,r['original_address'][2:]);path=out/name;pool.fsynced(path,output)
            bulk.strict_reparse(path,output)
            plan=dict(bindings=projection['namespace_bindings'],comparison_base_view={n:r['original_address'] for _,n in projection['namespace_bindings']})
            after=bulk.compare_functions(path,pe,compare_contracts,u['recipe'],plan)
            projection.update(before_comparison=before,after_comparison=after,central_record_sha256=digest(row))
            members.append((name,output));member_receipts.append(dict(name=name,projection=projection));emitted.append(r['original_address'])
            note('member_verified',original_address=r['original_address'],member=name,member_sha256=coff.digest(output),maps=projection['maps'])
        if members:
            archive=coff.archive(members);pool.fsynced(out/'ordinary-code.lib',archive);recovered=coff.read_archive(archive)
            require(recovered['members']==members and len(recovered['index'])==len(emitted),'archive membership/export indices differ')
            for name,data in recovered['members']:
                path=out/('recovered-'+name);pool.fsynced(path,data);bulk.strict_reparse(path,data)
            archive_hash=coff.digest(archive)
        else:archive_hash=None
        coverage=write_coverage(out/'coverage.jsonl.gz',baseline/'coverage.jsonl.gz',set(wanted),set(emitted))
        save_json(out/'members.json',member_receipts);save_json(out/'blocked.json',blocked)
        stable(inputs);usage=budget(start,out)
        result=dict(schema_version=1,policy_id=POLICY,status='completed' if len(emitted)==len(roots) else 'completed-incomplete',
            request_sha256=args.request_sha256,central_receipt_sha256=args.central_receipt_sha256,review_sha256=args.review_sha256,
            requested=len(roots),emitted=len(emitted),blocked=len(blocked),emitted_addresses=emitted,archive_sha256=archive_hash,
            members_sha256=file_hash(out/'members.json'),blocked_sha256=file_hash(out/'blocked.json'),coverage_sha256=file_hash(out/'coverage.jsonl.gz'),
            historical_owners=68657,baseline_CODE_exports=12946,coverage_counts=coverage,inputs={str(p):h for p,h in inputs.items()},
            upstream_historical_scope=upstream_scope,
            inputs_stable=True,optional_function_index_present=False,native_archive_conformance_verified=False,
            resource_observations=usage,resource_limits=dict(sampled_peak_memory_bytes=1024**3,sampled_seconds=900,output_bytes=128*1024**2),**FALSE)
        return finalize_success(out,result,inputs,start,journal,note)
    except BaseException as error:
        try:
            if not journal.closed:note('failed',error_type=type(error).__name__,message=str(error),completed_members=len(emitted))
        except OSError:pass  # Abort evidence must not depend on journal health.
        save_json(out/'abort.json',dict(schema_version=1,status='aborted-no-retry',error_type=type(error).__name__,message=str(error),completed_members=emitted,successful_projection=False,**FALSE))
        raise
    finally:
        if not journal.closed:journal.close()


def main(argv=None):
    p=argparse.ArgumentParser(description=__doc__)
    for name in ('request','central-receipt','lanes-dir','review','reference','out'):p.add_argument('--'+name,required=True,type=Path,dest=name.replace('-','_'))
    for name in ('request','central-receipt','review'):p.add_argument('--'+name+'-sha256',required=True,dest=name.replace('-','_')+'_sha256')
    args=p.parse_args(argv)
    try:r=run(args)
    except (ValueError,OSError,KeyError,TypeError) as e:p.exit(2,'ordinary projection rejected: '+str(e)+'\n')
    print(json.dumps({k:r[k] for k in ('status','requested','emitted','blocked','archive_sha256')}))
    return 0 if r['status']=='completed' else 3


if __name__=='__main__':raise SystemExit(main())
