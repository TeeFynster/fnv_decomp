"""All-size metadata accounting using the exact bounded CODE writer policy.

No object/archive/data emission, compiler, linker or native execution.
"""
from __future__ import annotations
import argparse
from collections import Counter,defaultdict
import gzip
import hashlib
import importlib
import json
import os
from pathlib import Path
import re
import struct
import tempfile
import time
from import_plan import ROOT,require,unit_digest
from runtime_gaps import read_bound
from data_plan import file_hash
from coff_inventory import reconcile_recipes

EXPECTED=dict(selection='48ae62cdc5b1754b9c4af674ef4716d53afb554882e174a93acf860eaf1c6cb1',
 manifest='bc62a5fb2553431b1e0547d11f366e52efb73096ea8ceb206c556ae5740a53eb',
 retained='04d44b73e81982f846bfe8d81806db72ea669586b579ff22007dfd6f7d831297',
 recipes='62f2c8da5f0daa912abdf4576328706711c6561eef7f01c93a89cb71ad46fb6c',
 binding='275714631903758efbf5a4f82e2428c6f51838f53b90d0c56d2e5dec5da1d804',
 owners='fac1496a2675e9a6b697d604c8d5b35a2e4b8bb6194e2ec823e5a37d1092f2e8',
 eh='1e08ae8a908dc0a9d7feba4e5fa3cbcfe3a5f9ed6be3004ed6ac8639497fd788')
FALSE=dict(emission_performed=False,runtime_eligible=False,provider_selected=False,ABI_verified=False,link_ready=False)


def canonical(value):return json.dumps(value,sort_keys=True,separators=(',',':'),ensure_ascii=True).encode('ascii')
def digest(value):return hashlib.sha256(canonical(value)).hexdigest()


def size_band(size):
    require(type(size)is int and size>0,'invalid selected size')
    return '1-255' if size<=255 else '256-511' if size<=511 else '512+'


def public_metadata(value):
    if isinstance(value,dict):return {str(k):public_metadata(v) for k,v in value.items()}
    if isinstance(value,(list,tuple)):return [public_metadata(v) for v in value]
    if isinstance(value,str):
        if re.search(r'(?i)(?:[a-z]:[\\/]|\\\\|/(?:Users|home|tmp)/)',value):
            return dict(private_text_omitted_sha256=hashlib.sha256(value.encode()).hexdigest())
        return value
    require(value is None or type(value)in(bool,int,float),'non-metadata payload leaked from policy')
    return value


def category(blockers,obligations):
    codes={b['code'] for b in blockers}
    if not codes:return 'CANDIDATE_WITH_CANONICAL_UNDEFINED' if obligations else 'CANDIDATE_OWNED_FIELDS_ONLY'
    if codes & {'ORIGINAL_MISSING_RELOCATION','INVENTORY_MISSING_SOURCE_RELOCATION'}:return 'BLOCKED_MISSING_SOURCE_RELOCATION'
    if codes & {'SAME_PARENT_EH_OR_UNKNOWN_ASSOCIATION','INVENTORY_FAILED_PARENT_EH'}:return 'BLOCKED_PARENT_EH_OR_ASSOCIATION'
    if codes & {'WRITER_UNSUPPORTED_OBJECT_FORMAT'}:return 'BLOCKED_OBJECT_FORMAT'
    if codes & {'WEAK_OR_COMMON_RECORD','UNSUPPORTED_AUXILIARY','UNKNOWN_AUXILIARY_METADATA','SAFESEH_REQUIRES_CLOSURE',
                'HIDDEN_AUXILIARY_INDEX','INVALID_ASSOCIATION','ASSOCIATION_CYCLE','UNKNOWN_DIRECTIVE_CONTRACT','UNSUPPORTED_DIRECTIVE_SECTION'}:
        return 'BLOCKED_RECIPE_WIDE_POLICY'
    if codes & {'SHARED_OR_UNVERIFIED_SECTION_EXTENT','UNSUPPORTED_SELECTED_OWNER','UNSUPPORTED_CODE_SECTION','UNSUPPORTED_ROOT_COMDAT',
                'UNPROVED_EXTRA_ENTRY_OR_ALIAS','MISSING_SELECTED_PHYSICAL_OWNER','INVENTORY_UNOWNED_RETAINED_SECTION'}:return 'BLOCKED_SECTION_OR_SYMBOL'
    return 'BLOCKED_FIELD_OR_POLICY'


def check_unit(unit,proof):
    require(unit.get('status')=='compiled' and proof.get('status')=='ok' and proof['recipe_id']==unit['recipe_id'] and
        proof['recipe_index']==unit['recipe_index'] and proof['object_sha256']==unit['object_sha256'] and
        proof['recipe_unit_sha256']==unit_digest(unit['recipe']) and
        proof['source_sha256_recorded']==proof['source_sha256_current']==unit['source_sha256'],'stale unit/source/object proof')
    expected={(f['symbol'],f['address'],f['size']) for f in unit['recipe']['functions']}
    actual={(f['symbol'],f['address'],f['size']) for f in proof['verified_functions']}
    require(len(expected)==len(unit['recipe']['functions']) and len(actual)==len(proof['verified_functions']) and expected==actual and
            all(f['verdict']=='match' for f in proof['verified_functions']),'complete proof coverage differs')


def selected_rows(unit,proof,selections):
    result=[]
    for f in proof['verified_functions']:
        address='0x%08x'%int(f['address'],16);choice=selections.get(address)
        require(choice,'proof address missing from selection')
        if choice['recipe_id']!=unit['recipe_id']:continue
        expected=dict(recipe_id=unit['recipe_id'],recipe_index=unit['recipe_index'],symbol=f['symbol'],section=f['section'],value=f['value'],
                      size=f['size'],selection_status='CODE_OWNERSHIP_SELECTED',runtime_eligible=False,link_ready=False)
        require(choice==expected,'stale selected native identity')
        result.append(dict(choice,original_address=address))
    return result


class BindingReader:
    """One streaming pass; per-recipe complete fields feed the shared assessor."""
    def __init__(self,stream,summary,selections):
        self.stream=iter(stream);self.summary=summary;self.selections=selections;self.next=None;self.events=Counter();self.classes=Counter()
        self.kinds=Counter();self.consistency=Counter();self.ordinal=0;self.last_index=-1;self.missing=0;self.missing_functions=set();self.seq=hashlib.sha256()
        self._advance()
    def _advance(self):
        line=next(self.stream,None)
        if line is None:self.next=None;return
        self.ordinal+=1;require(self.ordinal<=1000000 and len(line)<=262144,'binding bounds')
        e=json.loads(line);index=e['recipe_index'];require(index>=self.last_index,'binding recipe order differs');self.last_index=index
        choice=self.selections.get(e['function_va']);r=e['coff_relocation'];width=4 if r is None else r['conservative_extent']
        require(choice and choice['recipe_index']==index and choice['recipe_id']==e['recipe_id'] and choice['symbol']==e['function_symbol'] and
            choice['section']==e['physical_section'] and choice['value']+e['source_field_offset']==e['physical_offset'] and
            0<=e['source_field_offset']<=choice['size']-width and int(e['original_field_va'],16)==int(e['function_va'],16)+e['source_field_offset'],
            'stale binding physical/function join')
        require(e.get('runtime_eligible')is False and e.get('provider_selected')is False,'binding promoted to runtime')
        self.events[e['event']]+=1;self.classes[e['classification']]+=1;self.seq.update(canonical([self.ordinal,digest(e)]))
        if r is None:
            require(e['event']=='MISSING_ORIGINAL_HIGHLOW_SOURCE_MIGRATION_BLOCKER','unknown missing event')
            self.missing+=1;self.missing_functions.add((e['recipe_id'],e['function_va']))
        else:
            require(e['event']=='SELECTED_FUNCTION_COFF_RELOCATION','unknown field event')
            self.kinds[str(r['kind'])]+=1;self.consistency[e['proof_consistency']]+=1
        self.next=e
    def take(self,index):
        require(self.next is None or self.next['recipe_index']>=index,'unconsumed binding unit')
        grouped=defaultdict(lambda:dict(fields=[],missing_fields=[],row_identities=[]));seen=set();count=0
        while self.next is not None and self.next['recipe_index']==index:
            e=self.next;r=e['coff_relocation'];key=(e['event'],e['function_va'],e['physical_section'],e['physical_offset'],
                None if r is None else r['symbol_index'],None if r is None else r['kind'])
            require(key not in seen,'duplicate exact binding row');seen.add(key);count+=1;require(count<=150000,'per-recipe binding bound')
            bucket=grouped[e['function_va']];bucket['missing_fields' if r is None else 'fields'].append(e)
            bucket['row_identities'].append(dict(ordinal=self.ordinal,sha256=digest(e)))
            self._advance()
        return grouped
    def finish(self,required_missing=88,required_functions=59):
        require(self.next is None,'unprocessed binding rows')
        require(dict(self.events)==self.summary['events'] and dict(self.classes)==self.summary['target_classes'] and
            dict(self.kinds)==self.summary['relocation_kinds'] and dict(self.consistency)==self.summary['proof_consistency'],'complete binding counts differ')
        require(self.missing==required_missing and len(self.missing_functions)==required_functions,'missing field/function census differs')
        return dict(events=dict(self.events),missing_fields=self.missing,missing_functions=len(self.missing_functions),sequence_sha256=self.seq.hexdigest())


def owner_providers(stream,report,selections):
    providers={};counts=Counter();sequence=hashlib.sha256()
    for ordinal,line in enumerate(stream,1):
        require(ordinal<=1000000 and len(line)<=262144,'owner detail bound')
        e=json.loads(line);counts[e['event']]+=1;sequence.update(canonical([ordinal,digest(e)]))
        require(e.get('runtime_eligible')is False and e.get('provider_selected')is False and e.get('materialization_approved')is False,'owner node promoted')
        if e['event']=='SOURCE_CODE_PROVIDER_OBLIGATION':
            address='0x%08x'%e['original_start'];choice=selections.get(address)
            require(choice and address not in providers and choice['recipe_id']==e['identity']['recipe_id'] and
                choice['section']==e['native_section'] and choice['value']==e['native_value'] and choice['size']==e['verified_span'],'stale owner physical join')
            providers[address]=e['identity']
    require(dict(counts)==report['summary']['events'] and set(providers)==set(selections),'complete owner provider coverage differs')
    return providers,dict(events=dict(counts),sequence_sha256=sequence.hexdigest())


def assess_unit(data,unit,proof,choices,bindings,providers,writer,emit_metadata=None):
    """One parse and one structural index per object; no producer emission API."""
    require(hashlib.sha256(data).hexdigest()==unit['object_sha256'],'stale input object bytes')
    try:obj=writer.coff.parse(data)
    except (ValueError,UnicodeError,struct.error) as e:
        obj=None;parse_error=str(e)
    if emit_metadata:
        if obj is None:
            emit_metadata(dict(event='RECIPE_COFF_METADATA',recipe_id=unit['recipe_id'],object_sha256=unit['object_sha256'],
                parse_supported=False,parse_blocker=public_metadata(parse_error),**FALSE))
        else:
            # Exact object hash anchors omitted table bytes; no raw auxiliary bytes or payload escape.
            symbols=[dict(index=i,name=s['name'],section=s['section'],value=s['value'],type=s['type'],storage=s['storage'],
                aux_count=s['aux_count'],aux_sha256=hashlib.sha256(s['aux']).hexdigest()) for i,s in obj['symbols'].items()]
            sections=[dict(index=i,name=s['name'],extent=s['size'],flags=s['flags'],relocation_count=len(s['relocs']),
                relocation_metadata_sha256=digest(s['relocs'])) for i,s in obj['sections'].items()]
            try:
                ix=writer.index_object(obj)
                policy_index=public_metadata(dict(section_auxiliaries=dict(ix['aux']),association_children=dict(ix['children']),
                    global_problems=ix['problems'],directives=ix['directives'],metadata_symbol_indices=ix['metadata']))
            except (ValueError,UnicodeError,struct.error) as e:
                policy_index=dict(unsupported_metadata=public_metadata(str(e)))
            emit_metadata(dict(event='RECIPE_COFF_METADATA',recipe_id=unit['recipe_id'],object_sha256=unit['object_sha256'],
                parse_supported=True,policy_index=policy_index,sections=sections,physical_symbol_count=obj['symbol_count'],
                symbol_metadata_sha256=digest(symbols),symbol_and_aux_provenance='Exact hash-bound original object; no hidden record assumed droppable',**FALSE))
    rows=[]
    for f in choices:
        address=f['original_address'];identity=providers[address]
        require(identity['recipe_id']==unit['recipe_id'] and identity['object_sha256']==unit['object_sha256'],'stale physical owner')
        b=bindings.get(address,dict(fields=[],missing_fields=[],row_identities=[]));parent_pieces=[r for r in proof.get('eh_sections',[]) if r[3]==address]
        failed=[r for r in parent_pieces if r[2]is False];extra=[]
        selected=dict(original_address=address,symbol=f['symbol'],symbol_index=identity['symbol_index'],section=f['section'],value=f['value'],size=f['size'])
        literals=[25,26] if unit['recipe_id']=='0703-3a582158246b390e' and address=='0x00646d00' else []
        contract=dict(recipe_id=unit['recipe_id'],object_sha256=unit['object_sha256'],source_sha256=unit['source_sha256'],selected=selected,
            verified_match=True,fields_complete=True,missing_fields_complete=True,fields=b['fields'],missing_fields=b['missing_fields'],
            literal_sections=literals,provider_identities=providers)
        if obj is None:assessment=dict(schema_version=1,policy_id=writer.POLICY_ID,candidate_eligible=False,
            blockers=[dict(code='WRITER_UNSUPPORTED_OBJECT_FORMAT',evidence=parse_error)],obligations=[],observations={})
        else:
            native=obj['symbols'].get(identity['symbol_index'])
            require(native and native['name']==f['symbol'] and native['section']==f['section'] and native['value']==f['value'],
                'current physical/native proof differs')
            try:assessment=writer.assess_parsed(obj,contract)
            except (ValueError,UnicodeError,struct.error) as e:
                assessment=dict(schema_version=1,policy_id=writer.POLICY_ID,candidate_eligible=False,
                    blockers=[dict(code='WRITER_UNSUPPORTED_OBJECT_FORMAT',evidence=str(e))],obligations=[],observations={})
            require(assessment['schema_version']==1 and assessment['policy_id']==writer.POLICY_ID,'shared policy schema changed')
            plan=assessment.get('extraction_plan',{})
            if assessment['candidate_eligible']:
                allowed={f['section'],*literals,*[i for i,s in obj['sections'].items() if s['name']=='.drectve']}
                if f['section'] not in plan.get('sections',[]) or any(i not in allowed for i in plan.get('sections',[])):
                    extra.append(dict(code='INVENTORY_UNOWNED_RETAINED_SECTION',evidence=plan.get('sections')))
        if b['missing_fields']:extra.append(dict(code='INVENTORY_MISSING_SOURCE_RELOCATION',evidence=len(b['missing_fields'])))
        if failed:extra.append(dict(code='INVENTORY_FAILED_PARENT_EH',evidence=failed))
        blockers=assessment['blockers']+extra;eligible=assessment['candidate_eligible'] and not blockers
        require(eligible == (not bool(blockers)),'candidate/blocker state inconsistent')
        rows.append(dict(event='SELECTED_CODE_SERIALIZATION_ASSESSMENT',original_address=address,physical_identity=identity,
            source_sha256=unit['source_sha256'],size=f['size'],size_band=size_band(f['size']),selected_native=selected,
            writer_policy_id=writer.POLICY_ID,writer_candidate_eligible=assessment['candidate_eligible'],serialization_candidate=eligible,
            category=category(blockers,assessment['obligations']),blockers=public_metadata(blockers),
            obligations=public_metadata(assessment['obligations']),observations=public_metadata(assessment['observations']),
            binding_row_references=b['row_identities'],binding_fields=len(b['fields']),original_missing_fields=len(b['missing_fields']),
            same_parent_piece_observations=len(parent_pieces),same_parent_false_piece_observations=len(failed),unit_EH_diagnostics=len(proof.get('eh_errors',[])),
            recipe_wide_policy_blocker_scope='May be conservative unrelated records; not game semantic invalidity',**FALSE))
    return rows


def validate_headers(data):
    selection,manifest,proof,binding,owners,eh=[data[n] for n in ('selection','manifest','retained','binding','owners','eh')]
    require(selection['function_addresses']==len(selection['selections'])==68657 and selection['selected_recipe_rows']==68667,
            'complete selected scope differs')
    require(len(manifest['units'])==len(proof['units'])==2988,'complete recipe scope differs')
    require(all(proof.get(k)is True for k in ('retained_verification_pass','function_byte_verification_pass',
        'global_listed_eh_coverage_pass','original_oracle_parity_pass','evidence_stable')),'retained gates differ')
    require(proof['runtime_closure_verified']is False and proof['strict_local_eh_diagnostics_pass']is False,'EH/runtime state differs')
    require(selection['input_sha256']['manifest']==EXPECTED['manifest'] and selection['input_sha256']['receipt']==EXPECTED['retained'] and
            selection['input_sha256']['recipe']==EXPECTED['recipes'],'selection provenance differs')
    for report in (binding,owners):
        require(all(report['inputs'][n]==EXPECTED[n] for n in ('selection','manifest','retained','recipes')),'stale ledger join')
        require(all(report.get(k)is False for k in ('runtime_eligible','provider_selected','link_ready')) and report['game_fixups_approved']==0,
                'ledger promoted to runtime')
    require(owners['inputs']['binding']==EXPECTED['binding'] and owners['binding_detail_sha256']==binding['details_sha256'],'stale owner binding')
    image=proof['inputs']['image_sha256']
    require(binding['inputs']['reference']==owners['inputs']['reference']==eh['inputs']['image_sha256']==image,'reference identities differ')
    require(eh['inputs']['manifest_sha256']==EXPECTED['manifest'] and eh['inputs']['retained_sha256']==EXPECTED['retained'] and
        eh['inputs']['recipe_sha256']==EXPECTED['recipes'],'EH evidence joins differ')
    require(proof['inputs']['retained_manifest_sha256']==EXPECTED['manifest'] and proof['inputs']['recipe_sha256']==EXPECTED['recipes'],'proof input differs')
    require(all(r.get('optional_function_index_present')is False for r in (binding,owners)) and
            proof['inputs']['function_index_present']is False and proof['inputs']['function_index_sha256']is None and
            selection['function_index_present']is False,'optional-index status differs')


def pin(path,expected,observations):
    path=Path(path).resolve();require(file_hash(path)==expected,'input fingerprint differs');
    require(path not in observations or observations[path]==expected,'conflicting input hash')
    observations[path]=expected


def stable(observations):
    for path,expected in observations.items():require(file_hash(path)==expected,'input changed during inventory')


def output_paths(out,details,inputs):
    paths=[Path(out).resolve(),Path(details).resolve(),Path(str(out)+'.progress.jsonl').resolve()]
    require(len(set(paths))==3 and not set(paths)&set(inputs),'input/output collision')
    require(not any(p.exists() for p in paths),'exclusive outputs already exist')
    return paths


def unit_eh_evidence(unit,proof):
    pieces=proof.get('eh_sections',[]);errors=proof.get('eh_errors',[])
    return dict(event='RECIPE_EH_EVIDENCE',recipe_id=unit['recipe_id'],recipe_index=unit['recipe_index'],
        object_sha256=unit['object_sha256'],source_sha256=unit['source_sha256'],
        pieces=public_metadata(pieces),diagnostics=public_metadata(errors),false_pieces=sum(r[2]is False for r in pieces),
        diagnostics_imply_complete_frame_closure=False,**FALSE)


def run(args):
    started=time.monotonic();root=Path(args.root).resolve()
    paths={n:Path(getattr(args,n)).resolve() for n in EXPECTED}
    data={n:read_bound(paths[n],h) for n,h in EXPECTED.items()};validate_headers(data)
    manifest,proof,selection,bp,owners=[data[n] for n in ('manifest','retained','selection','binding','owners')]
    require(reconcile_recipes(manifest,paths['recipes'])['verified'],'authoritative recipes differ')
    observations=dict(zip(paths.values(),EXPECTED.values()))
    bdetail=Path(args.binding_details).resolve();odetail=Path(args.owner_details).resolve()
    pin(bdetail,bp['details_sha256'],observations);pin(odetail,owners['details_sha256'],observations)
    # These are dependency pins, not policy authentication. No emission APIs invoked.
    for name,expected in [('runtime_code_pool.py',args.writer_sha256),('coff_code_archive.py',args.coff_sha256)]:
        pin(ROOT/'tools/rebuild'/name,expected,observations)
    for name in ('runtime_code_inventory.py','runtime_gaps.py','data_plan.py','coff_inventory.py','import_plan.py'):
        path=ROOT/'tools/rebuild'/name;pin(path,file_hash(path),observations)
    for name,h in proof['inputs']['tools_sha256'].items():
        path=(ROOT/name).resolve();require(path.is_relative_to(ROOT),'invalid proof tool path');pin(path,h,observations)
    writer=importlib.import_module('runtime_code_pool')
    require(Path(writer.__file__).resolve()==ROOT/'tools/rebuild/runtime_code_pool.py' and
            Path(writer.coff.__file__).resolve()==ROOT/'tools/rebuild/coff_code_archive.py','unexpected shared writer module')
    stable(observations)
    units={u['recipe_index']:u for u in proof['units']}
    require(len(units)==len(proof['units']),'duplicate proof recipe')
    object_paths={};source_paths={}
    for unit in manifest['units']:
        check_unit(unit,units[unit['recipe_index']])
        obj=(paths['manifest'].parent/manifest.get('object_root_relative','.')/unit['object']).resolve()
        src=(root/unit['source']).resolve()
        require(src.is_relative_to(root) and obj not in object_paths,'invalid named object/source')
        object_paths[obj]=unit['object_sha256']
        require(src not in source_paths or source_paths[src]==unit['source_sha256'],'conflicting source hashes')
        source_paths[src]=unit['source_sha256']
    observations.update(object_paths)
    for src,h in source_paths.items():pin(src,h,observations)
    index=root/'build/function_index.json';require(not index.exists(),'optional index appeared')
    out,details,progress=output_paths(args.out,args.details_gz,observations)
    progress.parent.mkdir(parents=True,exist_ok=True);published=[]
    with progress.open('x',encoding='utf-8') as journal:
        def note(value):
            journal.write(json.dumps(dict(elapsed_seconds=round(time.monotonic()-started,3),**value))+'\n');journal.flush();os.fsync(journal.fileno())
        note(dict(state='started',inputs=EXPECTED,writer_sha256=args.writer_sha256,coff_sha256=args.coff_sha256))
        try:
            with gzip.open(odetail,'rt',encoding='utf-8') as stream:
                providers,owner_provenance=owner_providers(stream,owners,selection['selections'])
            counts=Counter();bands=Counter();cross=Counter();reasons=Counter();events=Counter();seen=set();checked=0;notes=0;false_pieces=0
            with tempfile.TemporaryFile() as stage:
                with gzip.GzipFile(fileobj=stage,mode='wb',mtime=0) as gz,gzip.open(bdetail,'rt',encoding='utf-8') as stream:
                    reader=BindingReader(stream,bp['summary'],selection['selections'])
                    def emit(row):events[row['event']]+=1;gz.write(canonical(row)+b'\n')
                    for number,unit in enumerate(manifest['units'],1):
                        pv=units[unit['recipe_index']];chosen=selected_rows(unit,pv,selection['selections']);checked+=len(pv['verified_functions'])
                        bindings=reader.take(unit['recipe_index'])
                        require(set(bindings)<=set(f['original_address'] for f in chosen),'binding owner omitted by current unit')
                        obj=(paths['manifest'].parent/manifest.get('object_root_relative','.')/unit['object']).resolve()
                        # Object bytes parsed exactly once in this loop, strictly manifest ordered.
                        for row in assess_unit(obj.read_bytes(),unit,pv,chosen,bindings,providers,writer,emit):
                            address=row['original_address'];require(address not in seen,'duplicate selected owner');seen.add(address)
                            counts[row['category']]+=1;bands[row['size_band']]+=1;cross[(row['size_band'],row['category'])]+=1
                            reasons.update({b['code'] for b in row['blockers']});emit(row)
                        evidence=unit_eh_evidence(unit,pv);notes+=len(evidence['diagnostics']);false_pieces+=evidence['false_pieces'];emit(evidence)
                        if number%100==0:note(dict(state='assessed_manifest_objects',objects=number,selected=len(seen)))
                    provenance=reader.finish()
                    require(seen==set(selection['selections']) and checked==68667,'complete all-size accounting differs')
                    require(dict(bands)=={'1-255':59634,'256-511':4604,'512+':4419} and notes==95,'size/EH census differs')
                require(not index.exists(),'optional index appeared')
                details.parent.mkdir(parents=True,exist_ok=True);stage.seek(0)
                with details.open('xb') as target:
                    published.append(details)
                    while block:=stage.read(1048576):target.write(block)
                    target.flush();os.fsync(target.fileno())
            stable(observations);require(not index.exists(),'optional index appeared')
            result=dict(schema_version=1,kind='fnv-all-size-code-serialization-inventory',status='metadata-only',inputs=EXPECTED,
                input_detail_sha256=dict(binding=bp['details_sha256'],owners=owners['details_sha256']),
                tools_sha256={p.relative_to(ROOT).as_posix():h for p,h in observations.items() if p.is_relative_to(ROOT/'tools')},
                details_sha256=file_hash(details),detail_format='gzip-jsonl-assessments-and-EH-metadata-no-payloads',
                summary=dict(objects=len(manifest['units']),selected=len(seen),checked_recipe_rows=checked,size_bands=dict(bands),
                    categories=dict(counts),size_category_counts=[dict(size_band=k[0],category=k[1],count=v) for k,v in sorted(cross.items())],
                    blocker_codes_nonexclusive=dict(reasons),events=dict(events),retained_EH_diagnostics=notes,retained_false_EH_pieces=false_pieces),
                binding_provenance=provenance,owner_provenance=owner_provenance,optional_function_index_present=False,
                unchanged_inputs=True,producer_compilers=dict(Counter(u['compiler'] for u in manifest['units'])),
                source_producer_manifest_sha256=EXPECTED['manifest'],policy_id=writer.POLICY_ID,all_original_missing_fields_retained=True,
                limitations=['Candidate eligibility is not emission success, ABI closure, provider selection or executable readiness.',
                    'Recipe-wide weak/aux/directive conservatism may block unrelated selected sections.',
                    'Undefined identities retain unresolved data/CRT/TLS/IAT/EH obligations; no original-address fallback.',
                    'Source placeholder definitions are excluded; only fixed scalar literal ownership may be retained.',
                    'Physical provenance indices are immutable; no serialization or index remapping occurs in this inventory.'],**FALSE)
            out.parent.mkdir(parents=True,exist_ok=True)
            with out.open('x',encoding='utf-8') as target:published.append(out);json.dump(result,target,separators=(',',':'));target.write('\n')
            note(dict(state='complete',report_sha256=file_hash(out),details_sha256=file_hash(details),summary=result['summary']))
            return result
        except BaseException as error:
            for path in published:path.unlink(missing_ok=True)
            note(dict(state='failed',error_type=type(error).__name__));raise


def main(argv=None):
    p=argparse.ArgumentParser(description=__doc__)
    for n in EXPECTED:p.add_argument('--'+n,required=True,type=Path)
    for n in ('binding-details','owner-details','out','details-gz'):p.add_argument('--'+n,required=True,type=Path)
    p.add_argument('--writer-sha256',required=True);p.add_argument('--coff-sha256',required=True);p.add_argument('--root',type=Path,default=ROOT)
    try:result=run(p.parse_args(argv))
    except (ValueError,OSError,KeyError,TypeError,struct.error) as e:p.exit(2,'inventory rejected: '+str(e)+'\n')
    print(json.dumps(result['summary']));return 0


if __name__=='__main__':raise SystemExit(main())
