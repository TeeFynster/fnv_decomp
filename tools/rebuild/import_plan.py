"""Hash-bound static PE import/IAT use plan; never generate or select providers."""
from __future__ import annotations
import argparse
from collections import Counter, defaultdict
import gzip
import hashlib
import json
from pathlib import Path
import struct
import sys
import tempfile
import time

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT/'tools'))
from compare import Pe as ImagePe
from build_and_match import image_ok
from coff_inventory import Coff, reconcile_recipes
from data_plan import Pe, file_hash
from runtime_gaps import read_bound

MAX_IMPORTS = 16384
SDK_NAMES = {'kernel32','user32','gdi32','advapi32','shell32','ole32','oleaut32',
             'comctl32','comdlg32','winmm','ws2_32','version'}


def require(ok, message):
    if not ok: raise ValueError(message)


def cstring(pe, rva, maximum=1024):
    result = bytearray()
    for i in range(maximum):
        value = pe.read_rva(rva+i, 1)
        if value == b'\0':
            require(bool(result), 'empty import string')
            return result.decode('ascii')
        require(32 <= value[0] <= 126, 'non-ASCII import identity')
        result.extend(value)
    raise ValueError('unterminated import string')


def parse_imports(pe):
    rva, size = pe.directories[1]
    require(rva and 20 <= size <= 1024*1024, 'missing or oversized import directory')
    imports, slots, terminated = [], set(), False
    for offset in range(0, size-19, 20):
        oft, stamp, chain, name_rva, first = struct.unpack('<IIIII', pe.read_rva(rva+offset, 20))
        if not any((oft, stamp, chain, name_rva, first)):
            terminated = True; break
        require(name_rva and first and first % 4 == 0, 'invalid import descriptor')
        dll = cstring(pe, name_rva, 260)
        require('/' not in dll and '\\' not in dll and ':' not in dll, 'DLL identity is not a base name')
        lookup = oft or first
        if not oft:
            require(stamp==0 and chain==0 and (len(pe.directories)<=11 or pe.directories[11]==(0,0)),
                    'bound or ambiguous FirstThunk-only lookup cannot establish export identity')
        require(lookup % 4 == 0, 'unaligned import lookup table')
        for i in range(MAX_IMPORTS+1):
            thunk, = struct.unpack('<I', pe.read_rva(lookup+4*i, 4))
            pe.read_rva(first+4*i, 4) # IAT cell must be wholly raw-backed too.
            if not thunk: break
            require(len(imports) < MAX_IMPORTS, 'import count exceeds bound')
            slot = pe.base+first+4*i
            require(slot not in slots, 'duplicate original IAT slot')
            slots.add(slot)
            if thunk & 0x80000000:
                require(thunk & 0x7fff0000 == 0, 'reserved ordinal bits set')
                identity = dict(kind='ordinal', ordinal=thunk & 0xffff)
            else:
                hint, = struct.unpack('<H', pe.read_rva(thunk, 2))
                identity = dict(kind='name', name=cstring(pe, thunk+2), hint=hint)
            stem = dll.lower().removesuffix('.dll')
            imports.append(dict(import_id=len(imports), descriptor_offset=offset, dll=dll,
                lookup_source='OriginalFirstThunk' if oft else 'FirstThunk-fallback-unbound-required',
                descriptor_timestamp=stamp, export=identity, original_IAT_va=f'0x{slot:08x}',
                representation='IAT_POINTER_CELL_NOT_FUNCTION_BODY',
                required_provider_contract=dict(dll=dll, export={k:v for k,v in identity.items() if k!='hint'},
                    normal_import_library_required=True, ordinal_export_check_required=identity['kind']=='ordinal',
                    sdk_library_proposal=stem+'.lib' if stem in SDK_NAMES else None,
                    proposal_verified=False, source_signature_verified=False, runtime_provider_selected=False)))
        else: raise ValueError('unterminated import lookup table')
    require(terminated, 'unterminated import descriptors')
    return imports


def classify(kind, addend, binding, fields, slots):
    """Exact evidence only. Per-recipe metadata alone never verifies a body."""
    if kind != 6: return dict(status='UNRESOLVED_UNSUPPORTED_RELOCATION', original_IAT_va=None)
    if addend != 0: return dict(status='UNRESOLVED_NONZERO_ADDEND', original_IAT_va=None)
    if binding is not None and binding not in slots:
        return dict(status='UNRESOLVED_BINDING_IS_NOT_IAT_CELL', original_IAT_va=None)
    observed = {f['observed_operand'] for f in fields}
    if len(observed) > 1 or (binding is not None and observed and binding not in observed):
        return dict(status='UNRESOLVED_RECIPE_OPERAND_CONFLICT', original_IAT_va=None)
    if observed:
        slot = next(iter(observed))
        if slot not in slots: return dict(status='UNRESOLVED_OPERAND_IS_NOT_IAT_CELL', original_IAT_va=None)
        return dict(status='VERIFIED_FUNCTION_EXACT_IAT_USE', original_IAT_va=f'0x{slot:08x}')
    if binding is not None:
        return dict(status='UNVERIFIED_BODY_RECIPE_IAT_BINDING', original_IAT_va=f'0x{binding:08x}')
    return dict(status='UNRESOLVED_UNVERIFIED_BODY_NO_BINDING', original_IAT_va=None)


def unit_digest(recipe):
    return hashlib.sha256(json.dumps(recipe, sort_keys=True, separators=(',', ':'), ensure_ascii=True).encode('ascii')).hexdigest()


def scan_unit(coff, unit, verified, pe, slots):
    recipe = unit['recipe']; by_section = defaultdict(list)
    defined_by_name=defaultdict(list)
    for symbol in coff.symbols.values():
        if symbol['section']>0:defined_by_name[symbol['name']].append(symbol)
    functions = {(f['symbol'], f['address'], f['size']) for f in recipe['functions']}
    receipt_functions=[(f['symbol'],f['address'],f['size']) for f in verified['verified_functions']]
    require(len(functions)==len(recipe['functions']) and len(set(receipt_functions))==len(receipt_functions)
            and set(receipt_functions)==functions,'receipt function coverage is incomplete or duplicated')
    for f in verified['verified_functions']:
        require(f['verdict']=='match' and (f['symbol'], f['address'], f['size']) in functions,
                'receipt function differs from recipe')
        named=defined_by_name[f['symbol']]
        require(len(named)==1 and named[0]['section']==f['section'] and named[0]['value']==f['value']
                and f['section'] in coff.sections and 0<=f['value']<=coff.sections[f['section']]['size']-f['size'],
                'verified function native identity conflict')
        by_section[f['section']].append(f)
    uses = Counter()
    undefined = {i:s for i,s in coff.symbols.items() if s['section']==0 and s['value']==0
                 and s['storage'] in (2,105) and s['name'].startswith(('__imp_', '_imp__'))}
    for section in coff.sections.values():
        header = coff.unpack('<8sIIIIIIHHI', 20+(section['index']-1)*40)
        raw = header[4]
        for offset, index, kind in section['relocs']:
            if index not in undefined: continue
            symbol = undefined[index]; uses[index] += 1
            addend=None
            if kind==6:
                require(0 <= offset <= section['size']-4 and raw, 'import relocation outside raw section')
                addend, = coff.unpack('<I', raw+offset)
            fields = []
            for f in by_section[section['index']]:
                if not f['value'] <= offset <= f['value']+f['size']-4: continue
                if kind==6 and addend==0:
                    field_rva = int(f['address'],16)-pe.base+offset-f['value']
                    require(pe.section(field_rva,4,True)['executable'], 'verified function field not executable')
                    operand, = struct.unpack('<I', pe.read_rva(field_rva,4,allow_code=True))
                    fields.append(dict(function_symbol=f['symbol'], function_va=f['address'],
                        function_section=f['section'], function_value=f['value'],
                        field_offset=offset-f['value'], original_field_va=f'0x{pe.base+field_rva:08x}',
                        observed_operand=operand))
            binding = recipe.get('symbols',{}).get(symbol['name'])
            binding = int(binding,0) if binding is not None else None
            result = classify(kind,addend,binding,fields,slots)
            if symbol['storage']==105:
                result=dict(status='UNRESOLVED_WEAK_EXTERNAL_CONTRACT',original_IAT_va=None)
            yield dict(recipe_index=unit['recipe_index'],recipe_id=unit['recipe_id'],source=unit['source'],
                source_sha256=unit['source_sha256'],object_sha256=unit['object_sha256'],
                symbol=symbol['name'],symbol_index=index,section=section['index'],relocation_offset=offset,
                relocation_kind=kind,addend=addend,recipe_binding_va=f'0x{binding:08x}' if binding is not None else None,
                verified_function_fields=fields,unit_local_EH_diagnostic_count=len(verified.get('eh_errors',[])),
                source_ABI_facts=dict(coff_machine='i386',undefined_import_pointer_spelling=symbol['name'],
                    relocation_field_width=4 if kind==6 else None,source_declaration_and_SDK_signature_verified=False,
                    calling_convention_verified=False),runtime_provider_selected=False,**result)
    for index,s in undefined.items():
        if index not in uses:
            yield dict(recipe_index=unit['recipe_index'],recipe_id=unit['recipe_id'],source=unit['source'],
                object_sha256=unit['object_sha256'],symbol=s['name'],symbol_index=index,
                status='UNRESOLVED_UNREFERENCED_UNDEFINED_SYMBOL',original_IAT_va=None,
                runtime_provider_selected=False)


def run(args):
    started=time.monotonic()
    root=Path(args.root).resolve(); out=Path(args.out).resolve(); details=Path(args.details_gz).resolve()
    require(not out.exists() and not details.exists() and out!=details,'output exists or output paths coincide')
    paths={n:Path(getattr(args,n)).resolve() for n in ('recipes','manifest','retained','reference')}
    hashes={n:getattr(args,n+'_sha256') for n in paths}
    data={n:read_bound(paths[n],hashes[n]) for n in ('recipes','manifest','retained')}
    recipes,manifest,receipt=(data[n] for n in ('recipes','manifest','retained'))
    require(file_hash(paths['reference'])==hashes['reference'],'reference SHA-256 mismatch')
    require(manifest.get('kind')=='fnv-retained-objects' and manifest.get('schema_version')==1
            and reconcile_recipes(manifest,paths['recipes'])['verified'],'manifest schema/recipe identity conflict')
    require(receipt.get('kind')=='fnv-retained-object-verification' and receipt.get('schema_version')==1
            and receipt['inputs']['retained_manifest_sha256']==hashes['manifest']
            and receipt['inputs']['recipe_sha256']==hashes['recipes']
            and receipt['inputs']['image_sha256']==hashes['reference']
            and receipt['scope']['full_authoritative'] is True
            and all(receipt.get(k) is True for k in ('retained_verification_pass','function_byte_verification_pass',
                'global_listed_eh_coverage_pass','original_oracle_parity_pass','evidence_stable')),
            'retained proof identity or parity conflict')
    observations={paths[n]:hashes[n] for n in paths}
    require(all(name in receipt['inputs']['tools_sha256'] for name in
                ('tools/build_and_match.py','tools/compare.py','tools/rebuild/verify_objects.py')),
            'receipt lacks producer/comparison tool identities')
    for name,expected in receipt['inputs']['tools_sha256'].items():
        path=(ROOT/name).resolve(); require(path.is_relative_to(ROOT) and file_hash(path)==expected,'stale verification tool')
        observations[path]=expected
    for name in ('tools/rebuild/import_plan.py','tools/rebuild/data_plan.py'):
        observations[(ROOT/name).resolve()]=file_hash(ROOT/name)
    index=root/'build/function_index.json'; present=receipt['inputs']['function_index_present']
    require(type(present)is bool and index.exists()==present,'optional index presence conflict')
    if present:
        require(file_hash(index)==receipt['inputs']['function_index_sha256'],'stale optional index')
        observations[index]=receipt['inputs']['function_index_sha256']
    else: require(receipt['inputs']['function_index_sha256'] is None,'absent index hash conflict')
    proof_units={u['recipe_index']:u for u in receipt['units']}
    require(len(proof_units)==len(receipt['units'])==len(manifest['units']),'receipt scope conflict')
    image=ImagePe(paths['reference']); require(hashlib.sha256(image.data).hexdigest()==hashes['reference'],'reference changed')
    passed,hits,probes=image_ok(image); del image
    require(passed,'reference image probes rejected')
    temp=None; created=[]
    try:
        with tempfile.TemporaryFile() as temp:
            counts=Counter(); aliases=defaultdict(Counter); symbol_slots=defaultdict(set); object_paths=set()
            with gzip.GzipFile(fileobj=temp,mode='wb',mtime=0) as stream:
                pe=Pe(paths['reference'])
                try:
                    delay_imports=bool(len(pe.directories)>13 and pe.directories[13]!=(0,0))
                    imports=parse_imports(pe); slots={int(i['original_IAT_va'],16) for i in imports}
                    for unit in manifest['units']:
                        proof=proof_units[unit['recipe_index']]
                        require(unit.get('status')=='compiled' and proof.get('status')=='ok'
                            and proof['recipe_id']==unit['recipe_id']
                            and proof['recipe_unit_sha256']==unit_digest(unit['recipe'])
                            and proof['object_sha256']==unit['object_sha256']
                            and proof['source_sha256_recorded']==proof['source_sha256_current']==unit['source_sha256'],
                            'unit/object/source proof identity conflict')
                        obj=(paths['manifest'].parent/manifest.get('object_root_relative','.')/unit['object']).resolve()
                        source=(root/unit['source']).resolve()
                        require(source.is_relative_to(root) and obj not in object_paths,'invalid source or duplicate object path')
                        object_paths.add(obj)
                        require(file_hash(obj)==unit['object_sha256'] and file_hash(source)==unit['source_sha256'],
                                'stale object or source')
                        observations[obj]=unit['object_sha256']; observations[source]=unit['source_sha256']
                        coff=Coff(obj); require(hashlib.sha256(coff.data).hexdigest()==unit['object_sha256'],'object changed while parsing')
                        for use in scan_unit(coff,unit,proof,pe,slots):
                            counts[use['status']]+=1
                            if use['original_IAT_va']:
                                aliases[use['original_IAT_va']][(use['symbol'],use['status'])]+=1
                                symbol_slots[use['symbol']].add(use['original_IAT_va'])
                            stream.write((json.dumps(use,separators=(',',':'))+'\n').encode())
                            require(sum(counts.values())<=100000,'import use count exceeds bound')
                finally: pe.close()
            require(index.exists()==present,'optional index presence changed')
            for p,h in observations.items(): require(file_hash(p)==h,'input changed during analysis')
            require(out not in observations and details not in observations,'output aliases input')
            for item in imports:
                item['source_aliases']=[dict(symbol=s,status=status,use_count=count)
                    for (s,status),count in sorted(aliases[item['original_IAT_va']].items())]
            details.parent.mkdir(parents=True,exist_ok=True)
            temp.seek(0)
            with details.open('xb') as dest:
                created.append(details)
                while chunk:=temp.read(1024*1024): dest.write(chunk)
            report=dict(schema_version=1,kind='fnv-static-import-plan',status='analysis-only',inputs=hashes,
                implementation_sha256=file_hash(__file__),details_sha256=file_hash(details),
                detail_format='gzip-jsonl-per-relocation-or-unreferenced-symbol',
                summary=dict(imports=len(imports),retained_objects=len(manifest['units']),use_records=sum(counts.values()),
                    use_statuses=dict(counts),source_names_with_multiple_IAT_slots=sum(len(v)>1 for v in symbol_slots.values())),
                image_gate=dict(hits=hits,probes=probes),optional_function_index_present=present,
                delay_import_directory_present=delay_imports,
                original_local_EH_diagnostic_count=receipt['summary']['eh_comparison_errors'],
                strict_local_EH_diagnostics_pass=receipt['strict_local_eh_diagnostics_pass'],
                function_providers_selected=False,runtime_closure_verified=False,game_fixups_approved=0,
                imports=imports,duplicate_source_name_slot_sets=[dict(symbol=s,original_IAT_vas=sorted(v))
                    for s,v in sorted(symbol_slots.items()) if len(v)>1],elapsed_seconds=round(time.monotonic()-started,3),
                limitations=['Exact original IAT identity does not prove a source/SDK function signature or provider ABI.',
                    'Ordinals remain DLL+ordinal identities; exports have not been loaded or checked.',
                    'Per-recipe metadata for unverified bodies remains separate from verified-function operand evidence.',
                    'Prior standalone alias probe also called direct SDK APIs; alias-only import-library extraction was not independently proved.'])
            out.parent.mkdir(parents=True,exist_ok=True)
            with out.open('x',encoding='utf-8') as f:
                created.append(out);json.dump(report,f,separators=(',',':'));f.write('\n')
            return report
    except BaseException:
        for path in created:path.unlink(missing_ok=True)
        raise


def main(argv=None):
    p=argparse.ArgumentParser(description=__doc__)
    for name in ('recipes','manifest','retained','reference'):
        p.add_argument('--'+name,type=Path,required=True);p.add_argument('--'+name+'-sha256',required=True)
    p.add_argument('--root',type=Path,default=ROOT);p.add_argument('--out',type=Path,required=True)
    p.add_argument('--details-gz',type=Path,required=True)
    try:report=run(p.parse_args(argv))
    except (OSError,ValueError,KeyError,TypeError,struct.error) as e:p.exit(2,'import plan failed: '+str(e)+'\n')
    print(json.dumps(report['summary']));return 0


if __name__=='__main__':raise SystemExit(main())
