"""Fixed V8 four-cell import successor: KERNEL32 12 and USER32 16, metadata only."""
from __future__ import annotations
import argparse
import copy
import gzip
import json
from pathlib import Path
import re
import import_projection as projection
import import_kernel32_extension as prior_tool
import iat_field_annotations as annotations
import normal_import_archive as archive

ROOT = Path(__file__).resolve().parents[2]
PINS = dict(catalog=projection.PLAN_PIN,
    assessment='1d57a3ba7e73489e710479bf802d0df2292d0ef665c3cf5ed26099b835179d72',
    assessment_review='19db19944466d621ba379b3ab22bb19228d9721db294546f078c98a0297bd92d',
    prior_native='a80e16739a2393a068d0da8ed5d9e4a1d165ccbfc5495e9e41830add98d35e0b',
    prior_review='59f5cda6743dcffaa643a95e0d04b03cdf28fa771cfa75ccc526d8b65050e605',
    fields='2e5cb28f81cf5042c31ae80f7db49ef003df693cf428fb678d7f116a907425bf')
HELPER_PINS = {'tools/rebuild/import_projection.py': prior_tool.PROJECTION_PIN,
    'tools/rebuild/import_kernel32_extension.py': '15177c10e9b6469e0abab5c54e0ec6ef18afb9829cc275bef831795e9f358307',
    'tools/rebuild/normal_import_archive.py': prior_tool.PARSER_PIN,
    'tools/rebuild/iat_field_annotations.py': '5ce0b3ae5069cde206b334bddc94515b308e611ef1cc269783cbd386fd778ae6',
    'tools/rebuild/runtime_code_pool.py': projection.NAMESPACE_HELPER_PIN}
SPECS = {'0x00fdf0ec': (48, 'KERNEL32.dll', 'ExitProcess', 1),
         '0x00fdf1c0': (101, 'KERNEL32.dll', 'InterlockedIncrement', 87),
         '0x00fdf1c8': (103, 'KERNEL32.dll', 'WaitForSingleObject', 1),
         '0x00fdf308': (178, 'USER32.dll', 'GetAsyncKeyState', 2)}
DLL_SPECS = {'KERNEL32.dll': ('kernel32-nine.lib', 'kernel32-twelve.lib', 9, 12,
    'fe222155feda5664e45f41014ecc9f5e08b91f436b7f2114293b72d457a7043e'),
    'USER32.dll': ('provider-003.lib', 'user32-sixteen.lib', 15, 16,
    'd8e796986b100a743fb06429d2385b4975628f8d273f094088f619e40f0d046d')}
FALSE_FLAGS = prior_tool.FALSE_FLAGS
require, sha = projection.require, projection.file_hash


def validate_fields(assessment, fields, catalog):
    require(len(fields) == assessment['complete_normative_field_count'] == 45315,
            'exact frozen V8 full field scope differs')
    before = annotations.digest(fields)
    require(before == assessment['normative_field_canonical_sha256'], 'normative field fingerprint differs')
    view = annotations.census_view(fields, catalog)
    require(annotations.digest(fields) == before and annotations.digest(view) == assessment['census_view_canonical_sha256'],
            'temporary census fingerprint or normative immutability differs')
    entries = {r['original_IAT_va']: r for r in assessment['per_cell_censuses']}
    require(set(entries) == set(SPECS), 'exact four assessed cells required')
    for base, (iid, dll, name, count) in SPECS.items():
        entry = entries[base]; canonical = projection.unresolved(base, 'iat-cell')
        uses = [(i, row) for i, row in enumerate(view, 1) if row['canonical'] == canonical or
                row['proof'].get('original_base') == base or row['proof'].get('original_target') == base]
        require(len(uses) == entry['complete_V8_use_count'] == count and entry['all_V8_use_proofs_pass'] is True
                and not entry['blockers'] and len(entry['complete_use_records']) == count,
                'complete per-cell use count or proof state differs')
        for (ordinal, row), saved in zip(uses, entry['complete_use_records']):
            proof = row['proof']
            require(ordinal == saved['field_ordinal'] and saved['normative_row'] == fields[ordinal-1] and
                    saved['temporary_census_row'] == row and saved['normative_row_sha256'] == annotations.digest(fields[ordinal-1])
                    and saved['census_view_row_sha256'] == annotations.digest(row) and saved['use_gate_passed'] is True,
                    'original all-use evidence or ordinal differs')
            require(row['canonical'] == canonical and row['undefined'] is True and row['kind'] == 6 and
                    proof.get('role') == 'iat-cell' and proof.get('original_base') == proof.get('original_target') == base and
                    proof.get('addend_bits') == 0 and proof.get('classification') == 'IAT_POINTER_CELL_NOT_FUNCTION_BODY' and
                    (row['component'] == 'actual-entry' or proof.get('import_id') == iid) and
                    proof.get('import_pointer_source_conflict') is not True, 'unsafe included IAT use')
    return view


def prepare(catalog, assessment, review, native):
    cells = projection.catalog(catalog)
    require(assessment.get('kind') == 'V8-four-import-full-field-successor-assessment' and
            assessment.get('schema_version') == 1 and assessment.get('native_library_generated') is False and
            assessment.get('alias_applied') is False and assessment['proposed_cell_count'] == 31 and
            review.get('kind') == 'v8-four-import-assessment-independent-review' and
            review.get('status') == 'accepted_metadata_only' and review['assessment_sha256'] == PINS['assessment'],
            'accepted assessment scope differs')
    old_aliases = native['proposed_pointer_aliases']
    require(len(old_aliases) == 27 and len({p['original_IAT_va'] for p in old_aliases}) == 27 and
            native['native_library_generated'] is True and native['all_inputs_tools_sources_stable'] is True and
            all(native.get(k) is False for k in FALSE_FLAGS), 'prior native mapping/state differs')
    for p in old_aliases:
        cell = cells[p['original_IAT_va']]
        require(all(p[k] == cell[k] for k in ('canonical_IAT_symbol', 'dll', 'export')) and
                p['alias_applied'] is False and p['source_ABI_approved'] is False and p['runtime_provider_adopted'] is False,
                'old pointer identity or promotion differs')
    require(not set(SPECS) & {p['original_IAT_va'] for p in old_aliases}, 'new delta overlaps prior cells')
    for base, (iid, dll, name, count) in SPECS.items():
        require(cells[base]['import_id'] == iid and cells[base]['dll'] == dll and
                cells[base]['export'] == dict(kind='name', name=name), 'new catalog identity differs')
    metadata = {c['original_IAT_va']: c for c in catalog['imports']}
    replacements, definitions = [], {}
    assessed = {r['dll']: r for r in assessment['proposed_replacements']}
    for dll, (old_name, new_name, old_count, new_count, old_hash) in DLL_SPECS.items():
        old = sorted([p for p in old_aliases if p['dll'] == dll], key=lambda p: p['original_IAT_va'])
        chosen = [cells[p['original_IAT_va']] for p in old]+[cells[b] for b in SPECS if cells[b]['dll'] == dll]
        require(len(old) == old_count and len(chosen) == new_count and
                assessed[dll]['old_library'] == old_name and assessed[dll]['old_library_sha256'] == old_hash and
                assessed[dll]['prior_native_pointer_identities'] == old, 'old library/pointer ancestry differs')
        chosen = [dict(c, original_export_metadata=metadata[c['original_IAT_va']]['export'],
                       lookup_source=metadata[c['original_IAT_va']]['lookup_source'])
                  for c in sorted(chosen, key=lambda c: c['original_IAT_va'])]
        names = sorted(projection.simple_export_token(c['export']['name']) for c in chosen)
        require(len(set(names)) == new_count, 'export identity collision')
        definition = ('LIBRARY "'+dll+'"\nEXPORTS\n'+''.join('    '+n+'\n' for n in names)).encode('ascii')
        filename = new_name.replace('.lib', '.def')
        require(projection.digest(definition) == assessed[dll]['definition_sha256'], 'reviewed DEF superset differs')
        definitions[filename] = definition
        replacements.append(dict(dll=dll, old_library=old_name, old_library_sha256=old_hash,
            new_library=new_name, old_import_count=old_count, new_import_count=new_count,
            cells=chosen, definition=dict(file=filename, sha256=projection.digest(definition)),
            prior_pointer_identities=old, descriptor_sharing_with_old_library_authorized=False))
    unchanged = [p for p in native['unchanged_libraries'] if p['library'] != 'provider-003.lib']
    require(len(unchanged) == 2 and unchanged == assessment['unchanged_libraries'], 'unchanged two-library set differs')
    chosen = sorted([cells[p['original_IAT_va']] for p in old_aliases]+[cells[b] for b in SPECS],
                    key=lambda c: c['original_IAT_va'])
    return dict(schema_version=1, kind='fnv-v8-four-import-successor-request', status='offline-prepared',
        replacements=replacements, cells=chosen, prior_pointer_aliases=copy.deepcopy(old_aliases),
        new_cell_all_use_censuses=copy.deepcopy(assessment['per_cell_censuses']),
        unchanged_libraries=copy.deepcopy(unchanged), complete_V8_field_count=45315, new_cell_complete_use_count=91,
        normative_field_canonical_sha256=assessment['normative_field_canonical_sha256'],
        census_view_canonical_sha256=assessment['census_view_canonical_sha256'],
        V8_source_use_evidence_preserved=True, global_caller_census_verified=False,
        native_library_generated=False, **FALSE_FLAGS), definitions


def reconcile(request, parsed_libraries, request_sha256):
    require(request.get('kind') == 'fnv-v8-four-import-successor-request' and request.get('schema_version') == 1 and
            request.get('native_library_generated') is False and request.get('global_caller_census_verified') is False and
            all(request.get(k) is False for k in FALSE_FLAGS) and isinstance(request_sha256, str) and
            re.fullmatch('[0-9a-f]{64}', request_sha256), 'successor request state differs')
    require(len(request['replacements']) == len(parsed_libraries) == 2 and len(request['cells']) == 31 and
            len(request['prior_pointer_aliases']) == 27, 'fixed two-library/31-cell scope differs')
    require({r['dll'] for r in request['replacements']} == set(DLL_SPECS) and
            set(parsed_libraries) == {v[1] for v in DLL_SPECS.values()}, 'exact two DLL/library identities required')
    old = {p['original_IAT_va']: p for p in request['prior_pointer_aliases']}
    require(len(old) == 27 and not set(old) & set(SPECS), 'prior/new cell coverage differs')
    aliases = [copy.deepcopy(p) for p in old.values() if p['dll'] not in DLL_SPECS]
    produced = []
    for replacement in request['replacements']:
        dll = replacement['dll']; require(dll in DLL_SPECS, 'unexpected replacement DLL')
        old_name, new_name, old_count, new_count, old_hash = DLL_SPECS[dll]
        require(all(replacement[k] == v for k, v in dict(old_library=old_name, old_library_sha256=old_hash,
            new_library=new_name, old_import_count=old_count, new_import_count=new_count).items()),
            'replacement scope differs')
        parsed = parsed_libraries[new_name]
        require(parsed['both_indexes_agree'] is True and len(parsed['imports']) == new_count and
                len(parsed['ordinary_members']) == 3 and all(i['machine'] == 0x14c for i in parsed['imports']),
                'native import archive shape differs')
        require(len(replacement['cells']) == new_count, 'replacement cells missing')
        for cell in replacement['cells']:
            hits = [i for i in parsed['imports'] if i['dll'] == cell['dll'] == dll and i['export'] == cell['export']]
            require(len(hits) == 1, 'actual DLL/export identity differs')
            item = hits[0]; base = cell['original_IAT_va']
            require(item['import_type'] == 0 and item['pointer_symbol'] == '__imp_'+item['symbol'] and
                    cell['canonical_IAT_symbol'] == projection.unresolved(base, 'iat-cell'), 'native pointer/cell role differs')
            if base in old:
                require(item['pointer_symbol'] == old[base]['proposed_pointer_symbol'] and cell['dll'] == old[base]['dll']
                        and cell['export'] == old[base]['export'], 'old native pointer identity changed')
            else:
                require(base in SPECS and (cell['import_id'], dll, cell['export']['name']) == SPECS[base][:3],
                        'unexpected new original cell')
            aliases.append(dict(original_IAT_va=base, canonical_IAT_symbol=cell['canonical_IAT_symbol'],
                proposed_pointer_symbol=item['pointer_symbol'], dll=dll, export=item['export'], library=new_name,
                member_offset=item['member_offset'], pointer_indirection_preserved=True, alias_applied=False,
                source_ABI_approved=False, runtime_provider_adopted=False))
        produced.append(dict(file=new_name, sha256=parsed['archive_sha256'], bytes=parsed['archive_bytes'], parsed_archive=parsed))
    require(len(aliases) == 31 and all(len({p[k] for p in aliases}) == 31 for k in
            ('original_IAT_va', 'canonical_IAT_symbol', 'proposed_pointer_symbol')) and
            all(p['alias_applied'] is False and p['source_ABI_approved'] is False and p['runtime_provider_adopted'] is False for p in aliases),
            'combined pointer collision or promotion')
    return dict(schema_version=1, kind='fnv-v8-four-import-successor-native-collection',
        status='collected-awaiting-independent-conformance', request_sha256=request_sha256,
        inputs=request['inputs'], source_sha256=request['source_sha256'], replacements=request['replacements'],
        libraries=produced, unchanged_libraries=request['unchanged_libraries'],
        proposed_pointer_aliases=sorted(aliases, key=lambda p: p['original_IAT_va']),
        old_27_pointer_identities_preserved=True, replacement_identities_verified=True,
        V8_source_use_evidence_preserved=True, native_library_generated=True, global_caller_census_verified=False, **FALSE_FLAGS)


def run(args):
    out = Path(args.out).resolve(); require(out.is_relative_to(ROOT/'build/rebuild'), 'private output required')
    paths = {k: Path(getattr(args, k)).resolve() for k in PINS}
    observed = {paths[k]: h for k, h in PINS.items()}; observed.update({ROOT/p: h for p, h in HELPER_PINS.items()})
    observed[Path(__file__).resolve()] = args.source_sha256
    def stable(): require(all(sha(p) == h for p, h in observed.items()), 'source/input drift')
    stable(); data = {k: prior_tool.read_bound(paths[k], PINS[k]) for k in PINS if k != 'fields'}
    for relative, value in data['assessment']['inputs'].items():
        path = ROOT/relative
        require(path not in observed or observed[path] == value, 'assessment ancestry pin conflicts')
        observed[path] = value
    stable()
    with gzip.open(paths['fields'], 'rb') as stream:
        raw = stream.read(256*1024*1024+1); require(len(raw) <= 256*1024*1024 and stream.read(1) == b'', 'field decompression bound')
    fields = json.loads(raw); del raw
    validate_fields(data['assessment'], fields, data['catalog'])
    require(data['prior_review']['status'] == 'accepted_metadata_conformance_only' and
            data['prior_review']['collection_sha256'] == PINS['prior_native'], 'prior native review differs')
    request, definitions = prepare(data['catalog'], data['assessment'], data['assessment_review'], data['prior_native'])
    for replacement in request['replacements']:
        path = paths['prior_native'].parent/'kernel32-nine.lib' if replacement['dll'] == 'KERNEL32.dll' else ROOT/'build/rebuild/import-native-main-v2/provider-003.lib'
        require(sha(path) == replacement['old_library_sha256'], 'old native library changed')
        parsed = archive.read_archive(path)
        require(len(parsed['imports']) == replacement['old_import_count'], 'old archive member count differs')
        for p in replacement['prior_pointer_identities']:
            require(sum(i['dll'] == p['dll'] and i['export'] == p['export'] and i['pointer_symbol'] == p['proposed_pointer_symbol']
                        for i in parsed['imports']) == 1, 'old actual pointer identity differs')
        observed[path] = replacement['old_library_sha256']
    for item in request['unchanged_libraries']:
        path = ROOT/'build/rebuild/import-native-main-v2'/item['library']; require(sha(path) == item['sha256'], 'unchanged library drift')
        observed[path] = item['sha256']
    request['inputs'] = {k+'_sha256': h for k, h in PINS.items()}
    request['source_sha256'] = {str(p.relative_to(ROOT)).replace('\\', '/'): h for p, h in observed.items() if p.is_relative_to(ROOT/'tools')}
    stable(); out.mkdir(parents=True, exist_ok=False); created = []
    try:
        for name, raw in definitions.items():
            path = out/name
            with path.open('xb') as stream: created.append(path); stream.write(raw)
        stable(); path = out/'preparation.json'
        with path.open('x') as stream: created.append(path); json.dump(request, stream, indent=2, sort_keys=True); stream.write('\n')
        stable()
    except BaseException:
        for p in reversed(created): p.unlink()
        out.rmdir(); raise
    return request


if __name__ == '__main__':
    parser = argparse.ArgumentParser(__doc__)
    for option in list(PINS)+['out', 'source_sha256']: parser.add_argument('--'+option.replace('_', '-'), required=True)
    result = run(parser.parse_args()); print(json.dumps(dict(status=result['status'], replacements=2, cells=len(result['cells']))))
