"""One central original-root observation, with recipe-union and singleton views."""
from __future__ import annotations
import argparse
from collections import Counter,defaultdict
from contextlib import ExitStack
import gzip
import hashlib
import json
import os
from pathlib import Path
import struct
import tempfile
import time
import scalableordinary_root_collect as finite
from scalableordinary_root_collect import ROOT,EXPECTED,IMPORT_PIN,ORDINARY_PIN,PARSER_PIN,INVENTORY_PIN,FALSE,ordinary,coff,canonical,digest,read_bound,file_hash,pin,stable,output_paths,public_metadata,validate_headers,reconcile_recipes,owner_providers,BindingReader
from coff_inventory import peak_memory_bytes

POLICY='central-ordinary-root-views-v1'
FINITE_PIN='e7e5b45df15af0a2bd5cb4a65b36d85ca21eb753656714c0a9a5d8dd919e58ad'
MAX_ROOTS=207
MAX_SECONDS=900
MAX_MEMORY=1024**3
MAX_OUTPUT=128*1024**2


def check_budget(start):
    ordinary.require(time.monotonic()-start<=MAX_SECONDS,'central observation time budget exceeded')
    peak=peak_memory_bytes()
    ordinary.require(peak is None or peak<=MAX_MEMORY,'central observation practical memory budget exceeded')
    return peak


def bind_dispatch(dispatch,request):
    ordinary.require(isinstance(dispatch,dict) and type(dispatch['schema_version'])is int and dispatch['schema_version']==1 and dispatch['kind']=='aggregate-selected-CODE-root-requests' and 0<len(request['roots'])<=MAX_ROOTS,'invalid central scope')
    ordinary.require(dispatch['roots']==request['roots'] and all(dispatch[k]is False for k in ('baseline_CODE_changed','native_operation_authorized','provider_selected','runtime_eligible','source_bodies_included')),'dispatch scope/promotion differs')
    lane_map=dispatch['lane_by_recipe'];recipes={r['recipe_id'] for r in request['roots']}
    ordinary.require(set(lane_map)==recipes and all(type(l)is int and 1<=l<=8 for l in lane_map.values()),'incomplete/disjoint lane map')
    return lane_map


def observe_recipe(raw,unit,proof,requested,bindings,imported,provenance,start=None):
    """One parse; immutable parsed graph feeds separate union/singleton contracts."""
    ordinary.require(hashlib.sha256(raw).hexdigest()==unit['object_sha256'],'stale original object')
    ordinary.require(all(r['object_sha256']==unit['object_sha256'] and r['source_sha256']==unit['source_sha256'] and r['recipe_id']==unit['recipe_id'] for r in requested),'requested recipe provenance differs')
    try:obj=coff.parse(raw);parse_error=None
    except (ValueError,UnicodeError,struct.error) as error:obj=None;parse_error=public_metadata(str(error))
    if obj is not None:
        for r in requested:
            s=obj['symbols'].get(r['symbol_index'])
            ordinary.require(s and (s['name'],s['section'],s['value'])==(r['symbol'],r['section'],r['value']),'current physical provider differs')
    for event,subset in [('RECIPE_ROOT_UNION_OBSERVATION',requested)]+[('SINGLE_ROOT_OBSERVATION',[r]) for r in requested]:
        if start is not None:check_budget(start)
        p=dict(provenance,scope_mode='recipe-union' if event.startswith('RECIPE') else 'singleton')
        contract=finite.build_contract(unit,proof,subset,bindings,imported,p)
        if obj is None:
            yield dict(schema_version=1,policy_id=POLICY,event=event,recipe_id=unit['recipe_id'],requested_roots=subset,provenance=contract['provenance'],
                contract=contract,contract_identity_sha256=digest(contract),closure_observed=False,graph_observation_complete=False,root_closure_candidate=False,
                blockers=[dict(code='UNSUPPORTED_ORIGINAL_COFF_FORMAT',evidence=parse_error)],**FALSE)
            continue
        cert=ordinary.assess_object(obj,contract)
        ordinary.require(cert['policy_id']==ordinary.POLICY and cert['full_serialization_eligible']is False,'ordinary observer changed')
        yield dict(schema_version=1,policy_id=POLICY,event=event,recipe_id=unit['recipe_id'],requested_roots=subset,provenance=contract['provenance'],
            contract=contract,contract_identity_sha256=digest(contract),certificate_sha256=digest(cert),certificate=cert,closure_observed=cert['closure_observed'],
            graph_observation_complete=cert['graph_observation_complete'],root_closure_candidate=cert['root_closure_candidate'],blockers=cert['blockers'],
            unit_EH_evidence=dict(pieces=public_metadata(proof.get('eh_sections',[])),diagnostics=public_metadata(proof.get('eh_errors',[]))),**FALSE)


def run(args):
    start=time.monotonic();root=Path(args.root).resolve();names=tuple(EXPECTED)+('imports',);pins=dict(EXPECTED,imports=IMPORT_PIN)
    paths={n:Path(getattr(args,n)).resolve() for n in names};data={n:read_bound(paths[n],pins[n]) for n in names};validate_headers(data)
    manifest,proof,selection,binding,owners,imports=[data[n] for n in ('manifest','retained','selection','binding','owners','imports')]
    ordinary.require(reconcile_recipes(manifest,paths['recipes'])['verified'],'authoritative recipes differ')
    ordinary.require(imports['inputs']['manifest']==pins['manifest'] and imports['inputs']['retained']==pins['retained'] and imports['inputs']['reference']==proof['inputs']['image_sha256'],'import joins differ')
    request_path=Path(args.request).resolve();dispatch_path=Path(args.dispatch).resolve()
    request=read_bound(request_path,args.request_sha256);dispatch=read_bound(dispatch_path,args.dispatch_sha256);lane_map=bind_dispatch(dispatch,request)
    observations={paths[n]:pins[n] for n in names};pin(request_path,args.request_sha256,observations);pin(dispatch_path,args.dispatch_sha256,observations)
    binding_in=Path(args.binding_details).resolve();owner_in=Path(args.owner_details).resolve();pin(binding_in,binding['details_sha256'],observations);pin(owner_in,owners['details_sha256'],observations)
    for name,h in [('root_code_closure.py',ORDINARY_PIN),('coff_code_archive.py',PARSER_PIN),('runtime_code_inventory.py',INVENTORY_PIN),('scalableordinary_root_collect.py',FINITE_PIN)]:pin(ROOT/'tools/rebuild'/name,h,observations)
    for name in ('centralordinary_root_collect.py','runtime_gaps.py','data_plan.py','import_plan.py','coff_inventory.py'):
        p=ROOT/'tools/rebuild'/name;pin(p,file_hash(p),observations)
    for name,h in proof['inputs']['tools_sha256'].items():
        p=(ROOT/name).resolve();ordinary.require(p.is_relative_to(ROOT),'foreign proof tool');pin(p,h,observations)
    ordinary.require(Path(ordinary.__file__).resolve()==ROOT/'tools/rebuild/root_code_closure.py' and Path(coff.__file__).resolve()==ROOT/'tools/rebuild/coff_code_archive.py' and Path(finite.__file__).resolve()==ROOT/'tools/rebuild/scalableordinary_root_collect.py','swapped producer modules')
    with gzip.open(owner_in,'rt',encoding='utf-8') as stream:providers,owner_census=owner_providers(stream,owners,selection['selections'])
    groups=finite.validate_request(request,selection['selections'],manifest,proof,providers);check_budget(start)
    units={u['recipe_index']:u for u in manifest['units']};proofs={u['recipe_index']:u for u in proof['units']};reserved=set(observations)
    for unit in manifest['units']:
        obj=(paths['manifest'].parent/manifest.get('object_root_relative','.')/unit['object']).resolve();src=(root/unit['source']).resolve();reserved.update((obj,src))
        if unit['recipe_index'] in groups:
            ordinary.require(src.is_relative_to(root),'foreign source');pin(src,unit['source_sha256'],observations);observations[obj]=unit['object_sha256']
    out,lanedir,progress=output_paths(args.out,args.lanes_dir,reserved|set(observations));lane_ids=sorted(set(lane_map.values()))
    lane_paths={lane:lanedir/('code-lane-%02d.jsonl.gz'%lane) for lane in lane_ids}
    ordinary.require(not set(lane_paths.values())&(reserved|set(observations)),'lane output/input collision')
    index=root/'build/function_index.json';ordinary.require(not index.exists(),'optional index appeared');published=[]
    progress.parent.mkdir(parents=True,exist_ok=True);imported=next((r for r in imports['imports'] if r['import_id']==175),None)
    with progress.open('x',encoding='utf-8') as journal:
        def note(v):journal.write(json.dumps(dict(elapsed_seconds=round(time.monotonic()-start,3),**v))+'\n');journal.flush();os.fsync(journal.fileno())
        note(dict(state='started',request_sha256=args.request_sha256,dispatch_sha256=args.dispatch_sha256,roots=len(request['roots']),recipes=len(groups)))
        try:
            rows=[];seen=set();events=Counter();per_lane=Counter();peak=None
            with ExitStack() as stack:
                stages={l:stack.enter_context(tempfile.TemporaryFile()) for l in lane_ids};writers={l:gzip.GzipFile(fileobj=stages[l],mode='wb',mtime=0) for l in lane_ids}
                try:
                    with gzip.open(binding_in,'rt',encoding='utf-8') as stream:
                        reader=BindingReader(stream,binding['summary'],selection['selections'])
                        for unit in manifest['units']:
                            bucket=reader.take(unit['recipe_index']);ri=unit['recipe_index']
                            if ri not in groups:continue
                            check_budget(start);pv=proofs[ri];requested=groups[ri];lane=lane_map[unit['recipe_id']]
                            provenance=dict(object_sha256=unit['object_sha256'],source_sha256=unit['source_sha256'],recipe_id=unit['recipe_id'],recipe_index=ri,
                                recipe_unit_sha256=pv['recipe_unit_sha256'],recipe_manifest_sha256=pins['recipes'],producer_manifest_sha256=pins['manifest'],retained_proof_sha256=pins['retained'],
                                selection_sha256=pins['selection'],binding_sha256=pins['binding'],binding_details_sha256=binding['details_sha256'],owner_ledger_sha256=pins['owners'],owner_details_sha256=owners['details_sha256'],
                                imports_sha256=IMPORT_PIN,reference_identity_sha256=proof['inputs']['image_sha256'],request_sha256=args.request_sha256,dispatch_sha256=args.dispatch_sha256,lane=lane,
                                source_relative=unit['source'],producer_compiler_variant=unit['compiler'],optional_function_index_present=False,collector_sha256=file_hash(__file__),observer_sha256=ORDINARY_PIN,parser_sha256=PARSER_PIN,
                                dependency_tools_sha256={p.relative_to(ROOT).as_posix():h for p,h in observations.items() if p.is_relative_to(ROOT/'tools')})
                            obj=(paths['manifest'].parent/manifest.get('object_root_relative','.')/unit['object']).resolve()
                            for record in observe_recipe(obj.read_bytes(),unit,pv,requested,bucket,imported,provenance,start):
                                writers[lane].write(canonical(record)+b'\n');events[record['event']]+=1;per_lane[lane]+=1
                                summary=dict(event=record['event'],recipe_id=unit['recipe_id'],roots=[r['original_address'] for r in record['requested_roots']],lane=lane,lane_record_ordinal=per_lane[lane],record_sha256=digest(record),
                                    certificate_sha256=record.get('certificate_sha256'),closure_observed=record['closure_observed'],graph_observation_complete=record['graph_observation_complete'],blocker_codes=dict(Counter(b['code'] for b in record['blockers'])))
                                rows.append(summary)
                                if record['event']=='SINGLE_ROOT_OBSERVATION':
                                    address=summary['roots'][0];ordinary.require(address not in seen,'duplicate singleton');seen.add(address)
                            peak=check_budget(start);note(dict(state='observed_recipe_once',recipe_id=unit['recipe_id'],lane=lane,roots=len(requested),peak_memory_bytes=peak))
                        census=reader.finish()
                finally:
                    for writer in writers.values():writer.close()
                ordinary.require(seen=={r['original_address'] for r in request['roots']} and events['RECIPE_ROOT_UNION_OBSERVATION']==len(groups),'complete central accounting differs')
                sizes={l:stages[l].seek(0,2) for l in lane_ids};ordinary.require(sum(sizes.values())<=MAX_OUTPUT,'central metadata output budget exceeded')
                stable(observations);ordinary.require(not index.exists(),'optional index appeared');lanedir.mkdir(parents=True,exist_ok=False)
                for lane in lane_ids:
                    stages[lane].seek(0)
                    with lane_paths[lane].open('xb') as target:
                        published.append(lane_paths[lane])
                        while block:=stages[lane].read(1048576):target.write(block)
                        target.flush();os.fsync(target.fileno())
            lane_artifacts={str(l):dict(path=lane_paths[l].name,sha256=file_hash(lane_paths[l]),records=per_lane[l],bytes=sizes[l]) for l in lane_ids}
            result=dict(schema_version=1,policy_id=POLICY,status='metadata-only',inputs={n:pins[n] for n in names},request_sha256=args.request_sha256,dispatch_sha256=args.dispatch_sha256,
                lane_artifacts=lane_artifacts,observations=rows,summary=dict(roots=len(seen),recipes=len(groups),events=dict(events),singleton_closure=sum(r['closure_observed'] for r in rows if r['event']=='SINGLE_ROOT_OBSERVATION'),
                    singleton_blocked=sum(not r['closure_observed'] for r in rows if r['event']=='SINGLE_ROOT_OBSERVATION'),union_closure=sum(r['closure_observed'] for r in rows if r['event']=='RECIPE_ROOT_UNION_OBSERVATION')),
                baseline_binding_census=census,owner_census=owner_census,collector_sha256=file_hash(__file__),ordinary_observer_sha256=ORDINARY_PIN,finite_helper_sha256=FINITE_PIN,parser_sha256=PARSER_PIN,
                peak_memory_bytes=peak,metadata_bytes=sum(sizes.values()),input_stability=True,optional_function_index_present=False,game_fixups_approved=0,**FALSE)
            finite.publish_summary(out,result,observations,index,published);check_budget(start)
            ordinary.require(out.stat().st_size+sum(sizes.values())<=MAX_OUTPUT,'final central output budget exceeded')
            note(dict(state='complete',summary_sha256=file_hash(out),summary=result['summary'],lane_artifacts=lane_artifacts));return result
        except BaseException as error:
            for p in published:p.unlink(missing_ok=True)
            note(dict(state='failed',error_type=type(error).__name__));raise


def main(argv=None):
    p=argparse.ArgumentParser(description=__doc__)
    for n in tuple(EXPECTED)+('imports','request','dispatch','binding-details','owner-details','out','lanes-dir'):p.add_argument('--'+n.replace('_','-'),required=True,type=Path,dest=n.replace('-','_'))
    p.add_argument('--request-sha256',required=True);p.add_argument('--dispatch-sha256',required=True);p.add_argument('--root',type=Path,default=ROOT)
    try:r=run(p.parse_args(argv))
    except (ValueError,OSError,KeyError,TypeError,struct.error) as e:p.exit(2,'central collection rejected: '+str(e)+'\n')
    print(json.dumps(r['summary']));return 0


if __name__=='__main__':raise SystemExit(main())
