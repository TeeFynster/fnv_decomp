"""Fixed eight-to-nine KERNEL32 metadata preparation and native identity join."""
from __future__ import annotations
import argparse
import json
from pathlib import Path
import re
import import_projection as projection
import import_kernel32_extension as previous_tool
import normal_import_archive as archive

ROOT = Path(__file__).resolve().parents[2]
PINS = dict(plan=projection.PLAN_PIN,
    prior_request='b351224f3cbfdf5cd82536eb2e8cab9815cf3044074e573384abf2c55d4e82d1',
    prior_native='e17300f3e24beadf2cb904ef9a8cfb28c66f9347bde48d3a1e2a9c9316ae6284',
    prior_review='4617c0da7a0fc5886638cd8ce55332c3a87b8bee3ec0d27557db34707e01e4d7',
    assessment='fb2b608b2f1002079f770e7d37ca007094475ec777169538d6a4fb24f676767c',
    ledger='a75d5295a3a01a24828928d0e412de830b5169559b0e4923b915d28446bfb510')
HELPER_PINS = {'tools/rebuild/import_projection.py': previous_tool.PROJECTION_PIN,
    'tools/rebuild/import_kernel32_extension.py': '15177c10e9b6469e0abab5c54e0ec6ef18afb9829cc275bef831795e9f358307',
    'tools/rebuild/normal_import_archive.py': previous_tool.PARSER_PIN,
    'tools/rebuild/runtime_code_pool.py': projection.NAMESPACE_HELPER_PIN}
OLD_LIBRARY_SHA256 = '7b24ff2544d9c3de3950a5ea5955204b2574293cce1f8c86b8d6ce7e3a56136b'
CELL, IMPORT_ID, DLL, NAME = '0x00fdf060', 13, 'KERNEL32.dll', 'GetTickCount'
EXPECTED_CALLERS = {('0035-e741388caa42d2bf', '0x00aa5040'), ('0107-45cf4d1906d848ed', '0x00aa50a0')}
FALSE_FLAGS = previous_tool.FALSE_FLAGS
require, sha = projection.require, projection.file_hash


def prepare(plan, prior, native, review, assessment, ledger):
    catalog = projection.catalog(plan)
    require(prior.get('kind') == 'fnv-kernel32-import-extension-request' and prior.get('schema_version') == 1
            and len(prior['cells']) == 8, 'accepted eight-cell request differs')
    require(native.get('kind') == 'fnv-kernel32-import-extension-native-collection' and
            native.get('schema_version') == 1 and native.get('native_library_generated') is True and
            native.get('all_inputs_tools_sources_stable') is True and
            native['library'] == dict(file='kernel32-eight.lib', sha256=OLD_LIBRARY_SHA256, bytes=3112) and
            all(native.get(k) is False for k in FALSE_FLAGS), 'prior native generation/state differs')
    require(review.get('kind') == 'fnv-kernel32-extension-independent-native-outcome-review' and
            review.get('status') == 'accepted_metadata_conformance_only' and
            review['collection_sha256'] == PINS['prior_native'] and review['library_sha256'] == OLD_LIBRARY_SHA256,
            'prior independent outcome differs')
    require(catalog[CELL]['import_id'] == IMPORT_ID and catalog[CELL]['dll'] == DLL and
            catalog[CELL]['export'] == dict(kind='name', name=NAME), 'new original import identity differs')
    canonical = catalog[CELL]['canonical_IAT_symbol']
    rows = [g for g in ledger['groups'] if g['symbol'] == canonical]
    require(len(rows) == 1, 'new exact unresolved group missing or ambiguous')
    group = rows[0]; uses = group['included_input_provenance']
    require(group['classification'] == 'IAT' and group['observed_roles'] == ['iat-cell'] and
            group['original_bases'] == group['original_targets'] == [CELL] and len(uses) == 2 and
            {(u['recipe_id'], u['root']) for u in uses} == EXPECTED_CALLERS, 'bounded new caller set differs')
    for use in uses:
        proof = use['proof']
        require(use['canonical'] == proof['canonical_name'] == canonical and use['undefined'] is True and
                use['kind'] == proof['kind'] == 6 and proof['addend_bits'] == 0 and
                proof['role'] == 'iat-cell' and proof['classification'] == 'IAT_POINTER_CELL_NOT_FUNCTION_BODY' and
                proof['import_id'] == IMPORT_ID and proof['original_base'] == proof['original_target'] == CELL and
                proof['symbol_index'] == use['physical_symbol_index'] and proof['field_offset'] == use['offset'] and
                proof['original_address'] == use['root'] and proof['provider_selected'] is False,
                'new included field metadata conflicts')
    require(assessment.get('kind') == 'gettickcount-next-import-metadata-assessment' and
            assessment['original_IAT_va'] == CELL and assessment['canonical_IAT_symbol'] == canonical and
            assessment['included_use_records'] == uses, 'accepted assessment/use join differs')
    aliases = native['proposed_pointer_aliases']
    require(len(aliases) == 26 and len({a['original_IAT_va'] for a in aliases}) == 26, 'prior alias coverage differs')
    old = sorted([a for a in aliases if a['dll'] == DLL], key=lambda a: a['original_IAT_va'])
    require(len(old) == 8 and {a['original_IAT_va'] for a in old} == {c['original_IAT_va'] for c in prior['cells']}
            and CELL not in {a['original_IAT_va'] for a in aliases}, 'old eight/new one delta differs')
    for a in aliases:
        cell = catalog[a['original_IAT_va']]
        require(all(a[k] == cell[k] for k in ('dll', 'export', 'canonical_IAT_symbol')) and
                a['alias_applied'] is False and a['source_ABI_approved'] is False and
                a['runtime_provider_adopted'] is False, 'prior alias identity/promotion differs')
    chosen = [catalog[a['original_IAT_va']] for a in old]+[catalog[CELL]]
    metadata = {c['original_IAT_va']: c for c in plan['imports']}
    chosen = [dict(c, original_export_metadata=metadata[c['original_IAT_va']]['export'],
                   lookup_source=metadata[c['original_IAT_va']]['lookup_source'])
              for c in sorted(chosen, key=lambda c: c['original_IAT_va'])]
    names = sorted(projection.simple_export_token(c['export']['name']) for c in chosen)
    require(len(names) == len(set(names)) == 9, 'nine-export identity collision')
    definition = ('LIBRARY "KERNEL32.dll"\nEXPORTS\n'+''.join('    '+n+'\n' for n in names)).encode('ascii')
    request = dict(schema_version=1, kind='fnv-kernel32-nine-import-extension-request', status='offline-prepared',
        replacement=dict(old_library='kernel32-eight.lib', old_library_sha256=OLD_LIBRARY_SHA256,
                         new_library='kernel32-nine.lib', old_import_count=8, new_import_count=9),
        cells=chosen, prior_kernel32_aliases=old, prior_other_aliases=[a for a in aliases if a['dll'] != DLL],
        unchanged_libraries=native['unchanged_libraries'], new_cell_included_use_records=uses,
        new_cell_use_metadata_consistent=True, included_provenance_is_extraction_proof=False,
        global_caller_census_verified=False, definition=dict(file='kernel32-nine.def', sha256=projection.digest(definition)),
        native_library_generated=False, **FALSE_FLAGS)
    request['operation_plan'] = [dict(tool='lib.exe', arguments=['/NOLOGO', '/MACHINE:X86',
        '/DEF:<saved-kernel32-nine.def>', '/OUT:<new-exclusive-kernel32-nine.lib>']),
        dict(tool='dumpbin.exe', arguments=['/HEADERS', '<new-kernel32-nine.lib>']),
        dict(tool='dumpbin.exe', arguments=['/LINKERMEMBER:2', '<new-kernel32-nine.lib>'])]
    return request, definition


def reconcile(request, parsed, request_sha256):
    require(request.get('kind') == 'fnv-kernel32-nine-import-extension-request' and request.get('schema_version') == 1
            and request.get('native_library_generated') is False and request.get('global_caller_census_verified') is False
            and all(request.get(k) is False for k in FALSE_FLAGS) and isinstance(request_sha256, str)
            and re.fullmatch('[0-9a-f]{64}', request_sha256), 'nine-export request state differs')
    require(request['replacement'] == dict(old_library='kernel32-eight.lib', old_library_sha256=OLD_LIBRARY_SHA256,
            new_library='kernel32-nine.lib', old_import_count=8, new_import_count=9), 'replacement contract differs')
    require(parsed['both_indexes_agree'] is True and len(parsed['imports']) == 9 and
            len(parsed['ordinary_members']) == 3 and all(i['machine'] == 0x14c for i in parsed['imports']),
            'native archive shape differs')
    old = {a['original_IAT_va']: a for a in request['prior_kernel32_aliases']}
    require(len(old) == 8 and len(request['cells']) == 9 and CELL not in old, 'nine-cell request coverage differs')
    aliases = []
    for cell in request['cells']:
        hits = [i for i in parsed['imports'] if i['dll'] == cell['dll'] and i['export'] == cell['export']]
        require(len(hits) == 1, 'observed DLL/export differs')
        item = hits[0]; va = cell['original_IAT_va']
        require(item['import_type'] == 0 and item['pointer_symbol'] == '__imp_'+item['symbol'] and
                cell['canonical_IAT_symbol'] == projection.unresolved(va, 'iat-cell'), 'pointer/canonical role differs')
        if va in old:
            require(item['pointer_symbol'] == old[va]['proposed_pointer_symbol'] and
                    cell['export'] == old[va]['export'] and cell['dll'] == old[va]['dll'], 'old eight pointer identities changed')
        else:
            require(va == CELL and cell['import_id'] == IMPORT_ID and cell['dll'] == DLL and
                    cell['export'] == dict(kind='name', name=NAME), 'new cell differs')
        aliases.append(dict(original_IAT_va=va, canonical_IAT_symbol=cell['canonical_IAT_symbol'],
            proposed_pointer_symbol=item['pointer_symbol'], dll=item['dll'], export=item['export'], library='kernel32-nine.lib',
            member_offset=item['member_offset'], pointer_indirection_preserved=True, alias_applied=False,
            source_ABI_approved=False, runtime_provider_adopted=False))
    combined = request['prior_other_aliases']+aliases
    require(len(combined) == 27 and all(len({a[k] for a in combined}) == 27 for k in
            ('original_IAT_va', 'canonical_IAT_symbol', 'proposed_pointer_symbol')), 'combined cell/pointer collision')
    require(all(a['alias_applied'] is False and a['source_ABI_approved'] is False and
                a['runtime_provider_adopted'] is False for a in combined), 'combined alias promotion')
    return dict(schema_version=1, kind='fnv-kernel32-nine-import-extension-native-collection',
        status='collected-awaiting-independent-conformance', request_sha256=request_sha256,
        inputs=request['inputs'], source_sha256=request['source_sha256'], replacement=request['replacement'],
        library=dict(file='kernel32-nine.lib', sha256=parsed['archive_sha256'], bytes=parsed['archive_bytes']),
        parsed_archive=parsed, proposed_pointer_aliases=sorted(combined, key=lambda a: a['original_IAT_va']),
        unchanged_libraries=request['unchanged_libraries'], replacement_identity_verified=True,
        old_eight_pointer_identities_preserved=True, native_library_generated=True,
        global_caller_census_verified=False, **FALSE_FLAGS)


def run(args):
    out = Path(args.out).resolve()
    require(out.is_relative_to(ROOT/'build/rebuild'), 'private build/rebuild output required')
    paths = {k: Path(getattr(args, k)).resolve() for k in PINS}
    observed = {paths[k]: h for k, h in PINS.items()}
    observed.update({ROOT/p: h for p, h in HELPER_PINS.items()}); observed[Path(__file__).resolve()] = args.source_sha256
    def stable(): require(all(sha(p) == h for p, h in observed.items()), 'source/input changed')
    stable()
    data = {k: previous_tool.read_bound(paths[k], PINS[k]) for k in paths}
    request, definition = prepare(data['plan'], data['prior_request'], data['prior_native'],
                                  data['prior_review'], data['assessment'], data['ledger'])
    oldlib = paths['prior_native'].parent/'kernel32-eight.lib'
    require(sha(oldlib) == OLD_LIBRARY_SHA256, 'prior eight library changed')
    parsed = archive.read_archive(oldlib)
    require(parsed['imports'] == data['prior_native']['parsed_archive']['imports'] and
            parsed['index'] == data['prior_native']['parsed_archive']['index'], 'prior eight actual parse changed')
    observed[oldlib] = OLD_LIBRARY_SHA256
    for item in request['unchanged_libraries']:
        path = ROOT/'build/rebuild/import-native-main-v2'/item['library']
        require(sha(path) == item['sha256'], 'unchanged prior library changed'); observed[path] = item['sha256']
    request['inputs'] = {k+'_sha256': h for k, h in PINS.items()}
    request['source_sha256'] = {str(p.relative_to(ROOT)).replace('\\', '/'): h
        for p, h in observed.items() if p.is_relative_to(ROOT/'tools')}
    stable(); out.mkdir(parents=True, exist_ok=False); created = []
    try:
        with (out/'kernel32-nine.def').open('xb') as stream:
            created.append(out/'kernel32-nine.def'); stream.write(definition)
        stable()
        with (out/'preparation.json').open('x') as stream:
            created.append(out/'preparation.json'); json.dump(request, stream, indent=2, sort_keys=True); stream.write('\n')
        stable()
    except BaseException:
        for p in reversed(created): p.unlink()
        out.rmdir(); raise
    return request


if __name__ == '__main__':
    parser = argparse.ArgumentParser(__doc__)
    for option in list(PINS)+['out', 'source_sha256']:
        parser.add_argument('--'+option.replace('_', '-'), required=True)
    result = run(parser.parse_args())
    print(json.dumps(dict(status=result['status'], cells=len(result['cells']), import_id=IMPORT_ID)))
