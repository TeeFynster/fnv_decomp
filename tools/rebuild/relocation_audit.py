"""Read-only exact selected-function PE HIGHLOW / COFF relocation audit.

No instruction decoding, numeric-address scanning, rewriting or provider adoption.
"""
from __future__ import annotations
import argparse
import bisect
from collections import Counter, defaultdict
import gzip
import hashlib
import json
import os
from pathlib import Path
import struct
import sys
import tempfile
import time
from import_plan import ROOT, ImagePe, image_ok, unit_digest, require
from coff_inventory import Coff, reconcile_recipes
from data_plan import Pe, file_hash
from runtime_gaps import read_bound

WIDTHS = {0:0,1:2,2:2,6:4,7:4,9:2,10:2,11:4,12:4,13:1,20:4}
METADATA = {'@feat.00', '@comp.id'}


class Intervals:
    """Exact overlapping intervals; no nearest-owner fallback."""
    def __init__(self, rows):
        self.rows = sorted(rows, key=lambda r:(r[0],r[1]))
        self.starts = [r[0] for r in self.rows]
        self.ends=[]; end=-1
        for _,hi,_ in self.rows:
            end=max(end,hi);self.ends.append(end)

    def overlap(self, lo, hi):
        i=bisect.bisect_left(self.starts,hi)-1
        found=[]
        while i>=0 and self.ends[i]>lo:
            a,b,value=self.rows[i]
            if a<hi and b>lo:found.append(value)
            i-=1
        return list(reversed(found))


def owner(f, selected=False):
    return dict(symbol=f['symbol'],address=f['address'],section=f['section'],value=f['value'],size=f['size'],selected_owner=selected)


def verified_functions(coff, unit, proof):
    expected={(f['symbol'],f['address'],f['size']) for f in unit['recipe']['functions']}
    rows=proof['verified_functions']
    require(len(expected)==len(unit['recipe']['functions']) and len(rows)==len(expected) and
            {(f['symbol'],f['address'],f['size']) for f in rows}==expected,'incomplete or duplicate proof functions')
    by_name=defaultdict(list)
    for s in coff.symbols.values():
        if s['section']>0:by_name[s['name']].append(s)
    for f in rows:
        symbols=by_name[f['symbol']]
        require(f['verdict']=='match' and len(symbols)==1 and
            symbols[0]['section']==f['section'] and symbols[0]['value']==f['value'] and
            f['section'] in coff.sections and f['size']>0 and
            0<=f['value']<=coff.sections[f['section']]['size']-f['size'] and
            coff.sections[f['section']]['flags'] & 0x20000020,'proof/native function identity conflict')
    return rows


def selected_for_unit(unit, functions, selections):
    result=[]
    for f in functions:
        key='0x%08x'%int(f['address'],16)
        require(key in selections,'proof address missing from selected ownership')
        choice=selections[key]
        if choice['recipe_id']!=unit['recipe_id']:continue
        require(choice==dict(recipe_id=unit['recipe_id'],recipe_index=unit['recipe_index'],symbol=f['symbol'],
            section=f['section'],value=f['value'],size=f['size'],selection_status='CODE_OWNERSHIP_SELECTED',
            runtime_eligible=False,link_ready=False),'selection/native/proof identity conflict')
        result.append(f)
    return result


def check_original_span(pe, f):
    rva=int(f['address'],16)-pe.base
    section=pe.section(rva,f['size'],required=True)
    require(section['executable'] and rva-section['rva']+f['size']<=section['raw_size'],
            'selected original function span is not executable/raw-backed')


def relocation_record(coff, sec, rel):
    offset,index,kind=rel
    require(kind in WIDTHS, 'unsupported unknown COFF relocation width')
    width=WIDTHS[kind]
    effective=width
    symbol=coff.symbols[index]
    addend=None
    if width in (1,2,4):
        header=coff.unpack('<8sIIIIIIHHI',20+(sec['index']-1)*40)
        require(header[4] and 0<=offset<=sec['size']-width,'COFF field outside section payload')
        addend=int.from_bytes(coff.take(header[4]+offset,width),'little')
    else:require(0<=offset<=sec['size'],'COFF relocation site outside section')
    return dict(offset=offset,symbol_index=index,kind=kind,width=width,conservative_extent=effective,
        symbol=symbol['name'],symbol_section=symbol['section'],symbol_value=symbol['value'],
        symbol_type=symbol['type'],symbol_storage=symbol['storage'],addend=addend)


def classify_field(start, end, field, overlaps):
    if field<start or field+4>end:return 'STRADDLING_FUNCTION_SPAN'
    if not overlaps:return 'MISSING_COFF_RELOCATION'
    if len(overlaps)!=1:return 'CONFLICTING_FIELD'
    r=overlaps[0]
    if r['offset']!=field:return 'CONFLICTING_FIELD'
    if r['kind']!=6:return 'UNSUPPORTED_KIND'
    return 'EXACT_DIR32'


def scan_unit(coff,unit,functions,selected,highlows,original_owners,image_base,image_size):
    selected_keys={(f['symbol'],f['section'],f['value'],f['size']) for f in selected}
    owners=defaultdict(list)
    for f in functions:
        owners[f['section']].append((f['value'],f['value']+f['size'],owner(f,(f['symbol'],f['section'],f['value'],f['size']) in selected_keys)))
    physical={i:Intervals(rows) for i,rows in owners.items()}
    relocations={}
    for sec in coff.sections.values():
        records=[relocation_record(coff,sec,r) for r in sec['relocs']]
        relocations[sec['index']]=(records,Intervals([(r['offset'],r['offset']+r['conservative_extent'],r) for r in records if r['width']]))
    identity=dict(recipe_id=unit['recipe_id'],recipe_index=unit['recipe_index'],object_sha256=unit['object_sha256'])
    for f in selected:
        va=int(f['address'],16); end=va+f['size']
        for site in highlows[bisect.bisect_left(highlows,va-3):bisect.bisect_left(highlows,end)]:
            field=f['value']+site-va
            overlaps=relocations[f['section']][1].overlap(field,field+4)
            po=physical[f['section']].overlap(field,field+4)
            oo=original_owners.overlap(site,site+4)
            yield dict(event='PE_HIGHLOW_CORRELATION',**identity,candidate=owner(f,True),
                original_field_va='0x%08x'%site,physical_field=dict(section=f['section'],offset=field,width=4),
                status=classify_field(f['value'],f['value']+f['size'],field,overlaps),coff_fields=overlaps,
                original_overlapping_owners=oo,physical_overlapping_owners=po,
                original_ownership_ambiguous=len(oo)>1,physical_ownership_ambiguous=len(po)>1,
                compatibility_scope='field geometry and relocation kind only; target semantics unresolved',safe_patch_approved=False)
    for sec in coff.sections.values():
        if not sec['flags'] & 0x20000020:continue
        for r in relocations[sec['index']][0]:
            if r['symbol_section']!=-1 or not r['width']:continue
            metadata=r['symbol'] in METADATA
            inside=image_base<=r['symbol_value']<image_base+image_size
            if not inside and not metadata:continue
            po=physical.get(sec['index'],Intervals([])).overlap(r['offset'],r['offset']+r['conservative_extent'])
            yield dict(event='ABSOLUTE_CODE_RELOCATION',**identity,section=sec['index'],field=r,
                status='LINKER_METADATA_NOT_RUNTIME_EDGE' if metadata else 'ABSOLUTE_SYMBOL_IN_ORIGINAL_IMAGE',
                symbol_value_within_original_image=inside,physical_overlapping_owners=po,
                selected_function_covered=any(o['selected_owner'] for o in po),semantics_resolved=False,safe_patch_approved=False)


def validate_headers(data,hashes,paths):
    manifest,receipt,selection=(data[n] for n in ('manifest','retained','selection'))
    require(manifest.get('kind')=='fnv-retained-objects' and manifest.get('schema_version')==1 and
            reconcile_recipes(manifest,paths['recipes'])['verified'],'manifest/recipe conflict')
    require(receipt.get('kind')=='fnv-retained-object-verification' and receipt.get('schema_version')==1 and
        receipt['inputs']['retained_manifest_sha256']==hashes['manifest'] and receipt['inputs']['recipe_sha256']==hashes['recipes'] and
        receipt['inputs']['image_sha256']==hashes['reference'] and receipt['scope']['full_authoritative'] is True and
        all(receipt.get(k) is True for k in ('retained_verification_pass','function_byte_verification_pass','global_listed_eh_coverage_pass','original_oracle_parity_pass','evidence_stable')),
        'stale or conflicting retained proof/image')
    require(selection.get('kind')=='fnv-function-code-ownership-selection' and selection.get('schema_version')==1 and
        selection['input_sha256']['recipe']==hashes['recipes'] and selection['input_sha256']['manifest']==hashes['manifest'] and
        selection['input_sha256']['receipt']==hashes['retained'] and selection.get('runtime_eligible') is False and
        selection.get('link_ready') is False and selection['function_addresses']==len(selection['selections']), 'selection identity or state conflict')
    require(selection['retained_verification']['local_eh_diagnostic_count']==receipt['summary']['eh_comparison_errors'], 'selection EH notes conflict')


def run(args):
    started=time.monotonic();root=Path(args.root).resolve()
    paths={n:Path(getattr(args,n)).resolve() for n in ('recipes','manifest','retained','selection','reference')}
    hashes={n:getattr(args,n+'_sha256') for n in paths}
    data={n:read_bound(paths[n],hashes[n]) for n in paths if n!='reference'}
    require(file_hash(paths['reference'])==hashes['reference'],'stale reference image')
    validate_headers(data,hashes,paths)
    manifest,receipt,selection=(data[n] for n in ('manifest','retained','selection'))
    observations={paths[n]:hashes[n] for n in paths}
    require(all(n in receipt['inputs']['tools_sha256'] for n in ('tools/build_and_match.py','tools/compare.py','tools/rebuild/verify_objects.py')),'proof lacks comparison tools')
    for n,h in receipt['inputs']['tools_sha256'].items():
        p=(ROOT/n).resolve();require(p.is_relative_to(ROOT) and file_hash(p)==h,'stale proof tool');observations[p]=h
    for n in ('relocation_audit.py','import_plan.py','data_plan.py','coff_inventory.py','runtime_gaps.py'):
        p=ROOT/'tools/rebuild'/n;observations[p]=file_hash(p)
    index=root/'build/function_index.json';present=receipt['inputs']['function_index_present']
    require(type(present)is bool and index.exists()==present and selection['function_index_present']==present,'optional index presence conflict')
    if present:
        require(file_hash(index)==receipt['inputs']['function_index_sha256'],'stale optional index');observations[index]=receipt['inputs']['function_index_sha256']
    else:require(receipt['inputs']['function_index_sha256'] is None,'absent index hash conflict')
    proof_units={u['recipe_index']:u for u in receipt['units']}
    require(len(proof_units)==len(receipt['units'])==len(manifest['units']),'proof unit scope conflict')
    object_paths=set()
    for unit in manifest['units']:
        obj=(paths['manifest'].parent/manifest.get('object_root_relative','.')/unit['object']).resolve()
        source=(root/unit['source']).resolve()
        require(source.is_relative_to(root) and obj not in object_paths,'invalid source/duplicate object')
        object_paths.add(obj);observations[obj]=unit['object_sha256'];observations[source]=unit['source_sha256']
    out,details=Path(args.out).resolve(),Path(args.details_gz).resolve();progress=Path(str(out)+'.progress.jsonl')
    require(len({out,details,progress})==3 and all(not p.exists() and p not in observations for p in (out,details,progress)),'output collision')
    image=ImagePe(paths['reference']);require(hashlib.sha256(image.data).hexdigest()==hashes['reference'],'image changed while parsing')
    passed,hits,probes=image_ok(image);del image;require(passed,'reference image probes failed')
    original=Intervals([(int(a,16),int(a,16)+s['size'],dict(address=a,**s)) for a,s in selection['selections'].items()])
    counts=Counter();ambiguity=Counter();seen_selected=set();recipe_rows=0;metadata_symbols=0
    progress.parent.mkdir(parents=True,exist_ok=True)
    with progress.open('x',encoding='utf-8') as journal:
        def note(value):journal.write(json.dumps(value,separators=(',',':'))+'\n');journal.flush();os.fsync(journal.fileno())
        note(dict(state='started',input_sha256=hashes))
        created=[]
        try:
            with tempfile.TemporaryFile() as tmp:
                pe=Pe(paths['reference'])
                try:
                    highlows=sorted(pe.base+r for r in pe.relocations())
                    with gzip.GzipFile(fileobj=tmp,mode='wb',mtime=0) as stream:
                        for unit in manifest['units']:
                            proof=proof_units[unit['recipe_index']]
                            require(unit.get('status')=='compiled' and proof.get('status')=='ok' and proof['recipe_id']==unit['recipe_id'] and
                                proof['recipe_unit_sha256']==unit_digest(unit['recipe']) and proof['object_sha256']==unit['object_sha256'] and
                                proof['source_sha256_recorded']==proof['source_sha256_current']==unit['source_sha256'],'unit/object/source proof conflict')
                            obj=(paths['manifest'].parent/manifest.get('object_root_relative','.')/unit['object']).resolve();source=root/unit['source']
                            require(file_hash(source)==unit['source_sha256'],'stale source')
                            coff=Coff(obj);require(hashlib.sha256(coff.data).hexdigest()==unit['object_sha256'],'stale object')
                            functions=verified_functions(coff,unit,proof);recipe_rows+=len(functions)
                            selected=selected_for_unit(unit,functions,selection['selections'])
                            for f in selected:
                                check_original_span(pe,f)
                                a='0x%08x'%int(f['address'],16);require(a not in seen_selected,'duplicate selected owner');seen_selected.add(a)
                            metadata_symbols+=sum(s['section']==-1 and s['name'] in METADATA for s in coff.symbols.values())
                            for event in scan_unit(coff,unit,functions,selected,highlows,original,pe.base,pe.image_size):
                                counts[event['event']+':'+event['status']]+=1
                                if event.get('original_ownership_ambiguous'):ambiguity['original_field_events']+=1
                                if event.get('physical_ownership_ambiguous'):ambiguity['physical_field_events']+=1
                                require(sum(counts.values())<=2000000,'detail event bound exceeded')
                                stream.write((json.dumps(event,separators=(',',':'))+'\n').encode())
                            if (unit['recipe_index']+1)%100==0:note(dict(state='scanning',completed_objects=unit['recipe_index']+1,events=sum(counts.values())))
                finally:pe.close()
                require(seen_selected==set(selection['selections']) and recipe_rows==selection['selected_recipe_rows'],'selected owner coverage conflict')
                require(index.exists()==present,'optional index presence changed')
                for p,h in observations.items():require(file_hash(p)==h,'input changed during audit')
                details.parent.mkdir(parents=True,exist_ok=True);tmp.seek(0)
                with details.open('xb') as dest:
                    created.append(details)
                    while block:=tmp.read(1024*1024):dest.write(block)
                report=dict(schema_version=1,kind='fnv-selected-code-relocation-audit',status='analysis-only',inputs=hashes,
                    implementation_sha256=file_hash(__file__),details_sha256=file_hash(details),detail_format='gzip-jsonl-exact-field-events',
                    summary=dict(retained_objects=len(manifest['units']),selected_functions=len(seen_selected),checked_recipe_rows=recipe_rows,
                        original_HIGHLOW_sites=len(highlows),event_statuses=dict(counts),ambiguous_events=dict(ambiguity),standard_linker_metadata_symbols=metadata_symbols),
                    image_gate=dict(hits=hits,probes=probes),optional_function_index_present=present,
                    original_local_EH_diagnostic_count=receipt['summary']['eh_comparison_errors'],
                    strict_local_EH_diagnostics_pass=receipt['strict_local_eh_diagnostics_pass'],
                    retained_EH_notes=selection['retained_verification'],runtime_eligible=False,link_ready=False,runtime_closure_verified=False,
                    game_fixups_approved=0,elapsed_seconds=round(time.monotonic()-started,3),
                    limitations=['Exact DIR32 means compatible field geometry/kind only; target/provider semantics unresolved.',
                        'A missing COFF field is a migration concern, not a bad-submission verdict or a safe patch location.',
                        'REL32 absence from PE HIGHLOW is expected; address-shaped numeric constants are not scanned.',
                        'Competing original/physical owners remain explicit; no nearest-owner assignment.'])
                out.parent.mkdir(parents=True,exist_ok=True)
                with out.open('x',encoding='utf-8') as dest:created.append(out);json.dump(report,dest,separators=(',',':'));dest.write('\n')
                note(dict(state='complete',report_sha256=file_hash(out),details_sha256=file_hash(details)))
                return report
        except BaseException as error:
            for p in created:p.unlink(missing_ok=True)
            note(dict(state='failed',error_type=type(error).__name__))
            raise


def main(argv=None):
    p=argparse.ArgumentParser(description=__doc__)
    for n in ('recipes','manifest','retained','selection','reference'):
        p.add_argument('--'+n,required=True,type=Path);p.add_argument('--'+n+'-sha256',required=True)
    p.add_argument('--root',type=Path,default=ROOT);p.add_argument('--out',type=Path,required=True);p.add_argument('--details-gz',type=Path,required=True)
    try:report=run(p.parse_args(argv))
    except (ValueError,OSError,KeyError,TypeError,struct.error) as error:p.exit(2,'relocation audit rejected: '+str(error)+'\n')
    print(json.dumps(report['summary']));return 0

if __name__=='__main__':raise SystemExit(main())
