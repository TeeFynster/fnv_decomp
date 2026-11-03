"""Finite selected ordinary-root metadata collector. No rewrite/emission/native API."""
from __future__ import annotations
import argparse
from collections import Counter,defaultdict
import gzip
import hashlib
import json
import os
from pathlib import Path
import struct
import tempfile
import time
import coff_code_archive as coff
import root_code_closure as ordinary
from runtime_code_inventory import EXPECTED,validate_headers,check_unit,selected_rows,BindingReader,owner_providers,canonical,digest,pin,stable,output_paths,public_metadata
from runtime_gaps import read_bound
from data_plan import file_hash
from coff_inventory import reconcile_recipes

ROOT=Path(__file__).resolve().parents[2]
POLICY='finite-ordinary-root-collection-v1'
ORDINARY_PIN='4bfdb5001380a3d7e5db7517033285d49ab211be68e2fcba15964f0ad5b03c53'
PARSER_PIN='76244d2d4dca4c1f8aa72224be1ef5c92f68976b5cda7d31b5cfe23d3cc29e64'
INVENTORY_PIN='c2fdbd52b4b7f4b7c68f9d80ad03708ba57d42b29e5938dfcf9769366a1ffd0b'
IMPORT_PIN='e39b8db63ef73aea57b5dd4963ff29310524644ca36e137cd8b5461a3c90a23f'
ROOT_KEYS={'original_address','recipe_id','recipe_index','object_sha256','source_sha256','symbol','symbol_index','section','value','size'}
FALSE=dict(emission_performed=False,runtime_eligible=False,provider_selected=False,ABI_verified=False,link_ready=False,namespace_approved=False,full_serialization_eligible=False)


def validate_request(request,selections,manifest,proof,providers):
    """Explicit physical identities, never spelling lookup or nearest owner."""
    ordinary.require(set(request)=={'schema_version','kind','roots'} and request['schema_version']==1 and
        type(request['schema_version'])is int and request['kind']=='fnv-finite-ordinary-root-request','unknown finite request schema')
    rows=request['roots'];ordinary.require(isinstance(rows,list) and 0<len(rows)<=len(selections),'empty/oversized request')
    units={u['recipe_index']:u for u in manifest['units']};proofs={u['recipe_index']:u for u in proof['units']}
    ordinary.require(len(units)==len(manifest['units']) and len(proofs)==len(proof['units']),'duplicate recipe identities')
    groups=defaultdict(list);seen=set();physical=set();native_proofs={}
    for row in rows:
        ordinary.require(isinstance(row,dict) and set(row)==ROOT_KEYS,'unknown request root fields')
        address=row['original_address'];ordinary.require(address not in seen and address in selections,'duplicate/unknown selected address');seen.add(address)
        selected=selections[address];unit=units[selected['recipe_index']];provider=providers.get(address)
        if unit['recipe_index'] not in native_proofs:
            check_unit(unit,proofs[unit['recipe_index']])
            native_proofs[unit['recipe_index']]={r['original_address']:r for r in selected_rows(unit,proofs[unit['recipe_index']],selections)}
        ordinary.require(address in native_proofs[unit['recipe_index']],'selected address lacks exact retained native proof')
        ordinary.require(provider is not None and provider['recipe_id']==unit['recipe_id'] and provider['object_sha256']==unit['object_sha256'],'selected provider provenance differs')
        expected=dict(original_address=address,recipe_id=unit['recipe_id'],recipe_index=unit['recipe_index'],object_sha256=unit['object_sha256'],
            source_sha256=unit['source_sha256'],symbol=selected['symbol'],symbol_index=provider['symbol_index'],section=selected['section'],value=selected['value'],size=selected['size'])
        ordinary.require(row==expected and all(type(row[k])is int for k in ('symbol_index','recipe_index','section','value','size')),'stale requested physical/source identity')
        key=(row['recipe_id'],row['symbol_index']);ordinary.require(key not in physical,'duplicate physical provider identity');physical.add(key)
        groups[row['recipe_index']].append(row)
    return {index:sorted(rows,key=lambda r:(r['section'],r['value'],r['symbol_index'],r['original_address'])) for index,rows in sorted(groups.items())}


def build_contract(unit,proof,requested,bindings,imported,provenance):
    addresses={r['original_address'] for r in requested}
    ordinary.require(all(r['recipe_id']==unit['recipe_id'] for r in requested),'mixed recipe root group')
    roots=[{k:r[k] for k in ('original_address','symbol','symbol_index','section','value','size')} for r in requested]
    fields=[];missing=[];refs=[]
    for r in requested:
        b=bindings.get(r['original_address'],dict(fields=[],missing_fields=[],row_identities=[]))
        fields+=b['fields'];missing+=b['missing_fields'];refs+=b['row_identities']
    p=dict(provenance,binding_row_references=refs,omission_binding_row_references=[r for b in bindings.values() for r in b['row_identities']])
    return dict(recipe_id=unit['recipe_id'],roots=roots,export_policy=ordinary.EXPORT_POLICY,verified_match=True,fields_complete=True,missing_fields_complete=True,
        unit_proofs_complete=True,fields=fields,missing_fields=missing,parent_eh=[r for r in proof.get('eh_sections',[]) if r[3] in addresses],
        omission_field_proofs=[r for b in bindings.values() for r in b['fields'] if r['coff_relocation']['symbol_storage']==6 or r['coff_relocation']['symbol']==ordinary.IAT_SOURCE_NAME],
        unit_verified_functions=proof['verified_functions'],iat_import_observation=imported,provenance=p)


def collect_group(raw,unit,proof,requested,bindings,imported,provenance):
    ordinary.require(hashlib.sha256(raw).hexdigest()==unit['object_sha256'],'stale original object')
    ordinary.require(all(r['object_sha256']==unit['object_sha256'] and r['source_sha256']==unit['source_sha256'] and r['recipe_id']==unit['recipe_id'] for r in requested),'requested group provenance differs')
    contract=build_contract(unit,proof,requested,bindings,imported,provenance)
    # Exactly one parse per requested recipe, including multiple selected roots.
    try:obj=coff.parse(raw)
    except (ValueError,UnicodeError,struct.error) as e:
        return dict(schema_version=1,policy_id=POLICY,status='blocked-object-format',requested_roots=requested,contract_identity_sha256=digest(contract),
            provenance=contract['provenance'],graph_observation_complete=False,closure_observed=False,root_closure_candidate=False,
            blockers=[dict(code='UNSUPPORTED_ORIGINAL_COFF_FORMAT',evidence=public_metadata(str(e)))],**FALSE)
    for r in requested:
        s=obj['symbols'].get(r['symbol_index'])
        ordinary.require(s and (s['name'],s['section'],s['value'])==(r['symbol'],r['section'],r['value']),'requested current physical owner differs')
    cert=ordinary.assess_object(obj,contract)
    ordinary.require(cert['policy_id']==ordinary.POLICY and cert['full_serialization_eligible']is False,'frozen ordinary schema changed')
    return dict(schema_version=1,policy_id=POLICY,status='ordinary-root-observed',requested_roots=requested,contract_identity_sha256=digest(contract),
        provenance=contract['provenance'],graph_observation_complete=cert['graph_observation_complete'],closure_observed=cert['closure_observed'],
        root_closure_candidate=cert['root_closure_candidate'],blockers=cert['blockers'],certificate_sha256=digest(cert),certificate=cert,
        unit_EH_evidence=dict(pieces=public_metadata(proof.get('eh_sections',[])),diagnostics=public_metadata(proof.get('eh_errors',[]))),**FALSE)


def publish_summary(out,result,observations,index_path,published):
    """Post-write input gate; drift removes only this attempt's created outputs."""
    try:
        out.parent.mkdir(parents=True,exist_ok=True)
        with out.open('x',encoding='utf-8') as target:
            published.append(out);json.dump(result,target,separators=(',',':'));target.write('\n');target.flush();os.fsync(target.fileno())
        stable(observations);ordinary.require(not index_path.exists(),'optional index appeared after summary publication')
    except BaseException:
        for path in published:path.unlink(missing_ok=True)
        raise


def run(args):
    root=Path(args.root).resolve();names=tuple(EXPECTED)+('imports',);pins=dict(EXPECTED,imports=IMPORT_PIN)
    paths={n:Path(getattr(args,n)).resolve() for n in names};data={n:read_bound(paths[n],pins[n]) for n in names}
    validate_headers(data)
    manifest,proof,selection,binding,owners,imports=[data[n] for n in ('manifest','retained','selection','binding','owners','imports')]
    ordinary.require(reconcile_recipes(manifest,paths['recipes'])['verified'],'authoritative recipe reconciliation failed')
    ordinary.require(imports['inputs']['manifest']==pins['manifest'] and imports['inputs']['retained']==pins['retained'] and
        imports['inputs']['reference']==proof['inputs']['image_sha256'],'import provenance differs')
    request_path=Path(args.request).resolve();request=read_bound(request_path,args.request_sha256)
    observations={paths[n]:pins[n] for n in names};pin(request_path,args.request_sha256,observations)
    details_in=Path(args.binding_details).resolve();owners_in=Path(args.owner_details).resolve()
    pin(details_in,binding['details_sha256'],observations);pin(owners_in,owners['details_sha256'],observations)
    for name,h in [('root_code_closure.py',ORDINARY_PIN),('coff_code_archive.py',PARSER_PIN),('runtime_code_inventory.py',INVENTORY_PIN)]:pin(ROOT/'tools/rebuild'/name,h,observations)
    for name in ('scalableordinary_root_collect.py','runtime_gaps.py','data_plan.py','import_plan.py','coff_inventory.py'):
        path=ROOT/'tools/rebuild'/name;pin(path,file_hash(path),observations)
    for name,h in proof['inputs']['tools_sha256'].items():
        path=(ROOT/name).resolve();ordinary.require(path.is_relative_to(ROOT),'foreign retained tool path');pin(path,h,observations)
    ordinary.require(Path(ordinary.__file__).resolve()==ROOT/'tools/rebuild/root_code_closure.py' and Path(coff.__file__).resolve()==ROOT/'tools/rebuild/coff_code_archive.py','swapped frozen producer/parser module')
    with gzip.open(owners_in,'rt',encoding='utf-8') as stream:providers,owner_census=owner_providers(stream,owners,selection['selections'])
    groups=validate_request(request,selection['selections'],manifest,proof,providers)
    units={u['recipe_index']:u for u in manifest['units']};proofs={u['recipe_index']:u for u in proof['units']};objects={}
    for index,requested in groups.items():
        unit=units[index];src=(root/unit['source']).resolve();obj=(paths['manifest'].parent/manifest.get('object_root_relative','.')/unit['object']).resolve()
        ordinary.require(src.is_relative_to(root) and obj not in objects,'invalid requested source/object identity')
        pin(src,unit['source_sha256'],observations);observations[obj]=unit['object_sha256'];objects[obj]=index
    reserved=set(observations)
    # Reserve all manifest-listed native/source paths without statting or opening
    # unrequested objects. A missing original must not become a metadata output.
    for unit in manifest['units']:
        reserved.add((paths['manifest'].parent/manifest.get('object_root_relative','.')/unit['object']).resolve())
        reserved.add((root/unit['source']).resolve())
    out,details,progress=output_paths(args.out,args.details_gz,reserved);progress.parent.mkdir(parents=True,exist_ok=True)
    index_path=root/'build/function_index.json';ordinary.require(not index_path.exists(),'optional index appeared')
    start=time.monotonic();published=[];imported=next((r for r in imports['imports'] if r['import_id']==175),None)
    with progress.open('x',encoding='utf-8') as journal:
        def note(value):journal.write(json.dumps(dict(elapsed_seconds=round(time.monotonic()-start,3),**value))+'\n');journal.flush();os.fsync(journal.fileno())
        note(dict(state='started',request_sha256=args.request_sha256,requested_roots=len(request['roots']),recipes=len(groups)))
        try:
            seen=set();summaries=[];baseline_counts=None
            with tempfile.TemporaryFile() as stage:
                with gzip.GzipFile(fileobj=stage,mode='wb',mtime=0) as gz,gzip.open(details_in,'rt',encoding='utf-8') as stream:
                    reader=BindingReader(stream,binding['summary'],selection['selections'])
                    for unit in manifest['units']:
                        bucket=reader.take(unit['recipe_index']);index=unit['recipe_index']
                        if index not in groups:continue
                        pv=proofs[index];requested=groups[index]
                        provenance=dict(object_sha256=unit['object_sha256'],source_sha256=unit['source_sha256'],recipe_id=unit['recipe_id'],recipe_index=index,
                            recipe_unit_sha256=pv['recipe_unit_sha256'],recipe_manifest_sha256=pins['recipes'],producer_manifest_sha256=pins['manifest'],
                            retained_proof_sha256=pins['retained'],selection_sha256=pins['selection'],binding_sha256=pins['binding'],binding_details_sha256=binding['details_sha256'],
                            owner_ledger_sha256=pins['owners'],owner_details_sha256=owners['details_sha256'],imports_sha256=IMPORT_PIN,reference_identity_sha256=proof['inputs']['image_sha256'],
                            request_sha256=args.request_sha256,source_relative=unit['source'],producer_compiler_variant=unit['compiler'],optional_function_index_present=False,
                            collector_sha256=file_hash(__file__),observer_sha256=ORDINARY_PIN,parser_sha256=PARSER_PIN,
                            dependency_tools_sha256={p.relative_to(ROOT).as_posix():h for p,h in observations.items() if p.is_relative_to(ROOT/'tools')})
                        obj=(paths['manifest'].parent/manifest.get('object_root_relative','.')/unit['object']).resolve()
                        record=collect_group(obj.read_bytes(),unit,pv,requested,bucket,imported,provenance)
                        record_hash=digest(record);gz.write(canonical(record)+b'\n')
                        for r in requested:ordinary.require(r['original_address'] not in seen,'duplicate accounted root');seen.add(r['original_address'])
                        summaries.append(dict(recipe_id=unit['recipe_id'],roots=[r['original_address'] for r in requested],record_sha256=record_hash,
                            certificate_sha256=record.get('certificate_sha256'),graph_observation_complete=record['graph_observation_complete'],closure_observed=record['closure_observed'],
                            blocker_codes=dict(Counter(b['code'] for b in record['blockers']))))
                        note(dict(state='observed_requested_recipe',recipe_id=unit['recipe_id'],roots=len(requested),record_sha256=record_hash,closure_observed=record['closure_observed']))
                    baseline_counts=reader.finish()
                ordinary.require(seen=={r['original_address'] for r in request['roots']} and len(summaries)==len(groups),'finite request accounting differs')
                stable(observations);ordinary.require(not index_path.exists(),'optional index appeared')
                details.parent.mkdir(parents=True,exist_ok=True);stage.seek(0)
                with details.open('xb') as target:
                    published.append(details)
                    while chunk:=stage.read(1048576):target.write(chunk)
                    target.flush();os.fsync(target.fileno())
            stable(observations);ordinary.require(not index_path.exists(),'optional index appeared')
            result=dict(schema_version=1,policy_id=POLICY,status='metadata-only',inputs={n:pins[n] for n in names},request_sha256=args.request_sha256,
                binding_details_sha256=binding['details_sha256'],owner_details_sha256=owners['details_sha256'],details_sha256=file_hash(details),
                collector_sha256=file_hash(__file__),ordinary_observer_sha256=ORDINARY_PIN,parser_sha256=PARSER_PIN,
                tools_sha256={p.relative_to(ROOT).as_posix():h for p,h in observations.items() if p.is_relative_to(ROOT/'tools')},
                summary=dict(requested_roots=len(seen),requested_recipes=len(groups),root_closure_groups=sum(s['closure_observed'] for s in summaries),
                    blocked_groups=sum(not s['closure_observed'] for s in summaries)),groups=summaries,owner_census=owner_census,baseline_binding_census=baseline_counts,
                input_stability=True,optional_function_index_present=False,game_fixups_approved=0,
                limitations=['Per-recipe root-set closure is not emission success or per-function standalone eligibility.',
                    'Every finite requested address is accounted; no all-size or reachable-set upgrade is implied.',
                    'Original missing/EH/data/CRT/TLS/IAT obligations remain unchanged; no original-address fallback.'],**FALSE)
            publish_summary(out,result,observations,index_path,published)
            note(dict(state='complete',report_sha256=file_hash(out),details_sha256=file_hash(details)));return result
        except BaseException as error:
            for path in published:path.unlink(missing_ok=True)
            note(dict(state='failed',error_type=type(error).__name__));raise


def main(argv=None):
    p=argparse.ArgumentParser(description=__doc__)
    for n in tuple(EXPECTED)+('imports','request','binding-details','owner-details','out','details-gz'):p.add_argument('--'+n.replace('_','-'),required=True,type=Path,dest=n.replace('-','_'))
    p.add_argument('--request-sha256',required=True);p.add_argument('--root',type=Path,default=ROOT)
    try:result=run(p.parse_args(argv))
    except (ValueError,OSError,KeyError,TypeError,struct.error) as e:p.exit(2,'ordinary-root collection rejected: '+str(e)+'\n')
    print(json.dumps(result['summary']));return 0


if __name__=='__main__':raise SystemExit(main())
