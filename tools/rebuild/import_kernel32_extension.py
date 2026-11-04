"""Offline exact eight-import KERNEL32 replacement preparation and native reconciliation."""
from __future__ import annotations
import argparse
import json
from pathlib import Path
import re
import import_projection as projection
import normal_import_archive as archive

ROOT = Path(__file__).resolve().parents[2]
PLAN_PIN = projection.PLAN_PIN
PREVIOUS_PREPARATION_PIN = 'b7f7c72ac71490b01610c97e7ef68da80a822b7877c9887e6b2e5ff53bd43e1c'
PREVIOUS_NATIVE_PIN = '4e75e3a126b459914e6b6d9946a7d3154e8114860a8317496975ea67600f244b'
PROJECTION_PIN = 'b13a2e805950ff4dc79fdaa1a8d12b00bb8a9c171853d77180ddb069857df865'
PARSER_PIN = '42a0eff5852d89aaadb1f239baf3884e7a2dcd4216870407d7e8510a6d68bf28'
OLD_LIBRARY_SHA256 = '8b08ff0e8eb7a6ea48f7a84537c564560409d8353166c883214d15f50e18d5e7'
NEW_CELL = '0x00fdf1c4'
NEW_EXPORT = dict(kind='name', name='InterlockedDecrement')
FALSE_FLAGS = dict(alias_applied=False, source_ABI_verified=False, runtime_provider_adopted=False,
                   executable_link_performed=False, compiler_performed=False, DLL_load_performed=False,
                   imported_API_call_performed=False, runtime_eligible=False, provider_selected=False)
require = projection.require
sha = projection.file_hash


def canonical_digest(value):
    return projection.digest(json.dumps(value, sort_keys=True, separators=(',', ':')).encode())


def prepare(plan, previous, native):
    """Exact catalog join only; no source spelling, ABI inference or native call."""
    cells = projection.catalog(plan)
    require(previous.get('kind') == 'fnv-normal-import-projection-preparation' and
            previous.get('schema_version') == 2 and previous['summary']['cells'] == 25,
            'previous preparation differs')
    require(native.get('kind') == 'fnv-main-normal-import-native-collection' and
            native.get('schema_version') == 1 and native['native_library_generated'] is True and
            native['all_inputs_tools_sources_stable'] is True and
            all(native.get(k) is False for k in FALSE_FLAGS if k in native),
            'previous native identity/state differs')
    prior_aliases = native['proposed_pointer_aliases']
    require(len(prior_aliases) == 25 and len({a['original_IAT_va'] for a in prior_aliases}) == 25,
            'previous cell coverage differs')
    selected = {c['original_IAT_va']: c for c in previous['selected_cells']}
    require(len(selected) == 25, 'previous preparation duplicated cells')
    for alias in prior_aliases:
        va = alias['original_IAT_va']
        require(va in selected and va in cells and all(alias[k] == cells[va][k]
                for k in ('dll', 'export', 'canonical_IAT_symbol')) and
                all(selected[va][k] == cells[va][k] for k in cells[va]),
                'previous exact identity conflicts with catalog')
        require(alias['alias_applied'] is False and alias['source_ABI_approved'] is False and
                alias['runtime_provider_adopted'] is False, 'previous alias promotion')
    old = sorted((a for a in prior_aliases if a['dll'] == 'KERNEL32.dll'),
                 key=lambda a: a['original_IAT_va'])
    require(len(old) == 7 and all(a['library'] == 'provider-001.lib' for a in old),
            'old KERNEL32 selection differs')
    old_libraries = [lib for lib in native['libraries'] if lib['library'] == 'provider-001.lib']
    require(len(old_libraries) == 1 and old_libraries[0]['archive_sha256'] == OLD_LIBRARY_SHA256 and
            len(old_libraries[0]['imports']) == 7, 'old library identity differs')
    require(NEW_CELL not in selected and NEW_CELL in cells and cells[NEW_CELL]['import_id'] == 102 and
            cells[NEW_CELL]['dll'] == 'KERNEL32.dll' and cells[NEW_CELL]['export'] == NEW_EXPORT,
            'new exact IAT identity differs')
    chosen = sorted([cells[a['original_IAT_va']] for a in old]+[cells[NEW_CELL]],
                    key=lambda c: c['original_IAT_va'])
    metadata = {i['original_IAT_va']: i for i in plan['imports']}
    chosen = [dict(c, original_export_metadata=metadata[c['original_IAT_va']]['export'],
                   lookup_source=metadata[c['original_IAT_va']]['lookup_source']) for c in chosen]
    names = sorted(projection.simple_export_token(c['export']['name']) for c in chosen)
    require(len(set(names)) == 8, 'duplicate replacement export')
    definition = ('LIBRARY "KERNEL32.dll"\nEXPORTS\n'+''.join('    '+name+'\n' for name in names)).encode('ascii')
    unchanged = [dict(library=lib['library'], sha256=lib['archive_sha256'],
                      imports=lib['imports']) for lib in native['libraries'] if lib['library'] != 'provider-001.lib']
    require(len(unchanged) == 3, 'unchanged library count differs')
    request = dict(schema_version=1, kind='fnv-kernel32-import-extension-request', status='offline-prepared',
                   replacement=dict(old_library='provider-001.lib', old_library_sha256=OLD_LIBRARY_SHA256,
                                    new_library='kernel32-eight.lib', old_import_count=7, new_import_count=8),
                   cells=chosen, prior_kernel32_aliases=old, prior_other_aliases=[a for a in prior_aliases if a not in old],
                   unchanged_libraries=unchanged, definition=dict(file='kernel32-eight.def',
                   sha256=projection.digest(definition)), native_library_generated=False,
                   global_caller_census_verified=False, **FALSE_FLAGS)
    request['operation_plan'] = [dict(tool='lib.exe', arguments=['/NOLOGO', '/MACHINE:X86',
        '/DEF:<saved-kernel32-eight.def>', '/OUT:<new-exclusive-kernel32-eight.lib>']),
        dict(tool='dumpbin.exe', arguments=['/HEADERS', '<new-kernel32-eight.lib>']),
        dict(tool='dumpbin.exe', arguments=['/LINKERMEMBER:2', '<new-kernel32-eight.lib>'])]
    return request, definition


def reconcile(request, parsed, request_sha256):
    """Pure native identity join; caller supplies actual bounded archive parse."""
    require(request.get('kind') == 'fnv-kernel32-import-extension-request' and
            request.get('schema_version') == 1 and request.get('native_library_generated') is False and
            all(request.get(k) is False for k in FALSE_FLAGS) and
            request.get('global_caller_census_verified') is False and
            isinstance(request_sha256, str) and re.fullmatch('[0-9a-f]{64}', request_sha256),
            'request identity/state differs')
    require(request['replacement'] == dict(old_library='provider-001.lib',
            old_library_sha256=OLD_LIBRARY_SHA256, new_library='kernel32-eight.lib',
            old_import_count=7, new_import_count=8), 'replacement contract differs')
    require(parsed['both_indexes_agree'] is True and len(parsed['imports']) == 8 and
            len(parsed['ordinary_members']) == 3 and all(i['machine'] == 0x14c for i in parsed['imports']),
            'native import/descriptor count or machine differs')
    aliases = []
    old = {a['original_IAT_va']: a for a in request['prior_kernel32_aliases']}
    require(len(request['cells']) == 8 and len(old) == 7 and NEW_CELL not in old, 'request cell set differs')
    for cell in request['cells']:
        found = [i for i in parsed['imports'] if i['dll'] == cell['dll'] and i['export'] == cell['export']]
        require(len(found) == 1, 'actual DLL/export identity differs')
        item = found[0]
        require(item['import_type'] == 0 and item['pointer_symbol'] == '__imp_'+item['symbol'],
                'not an actual import-pointer symbol')
        va = cell['original_IAT_va']
        require(cell['canonical_IAT_symbol'] == projection.unresolved(va, 'iat-cell'), 'canonical cell role differs')
        if va in old:
            require(item['pointer_symbol'] == old[va]['proposed_pointer_symbol'] and
                    cell['export'] == old[va]['export'] and cell['dll'] == old[va]['dll'],
                    'old seven native pointer identities changed')
        else:
            require(va == NEW_CELL and cell['import_id'] == 102 and cell['dll'] == 'KERNEL32.dll' and
                    cell['export'] == NEW_EXPORT, 'extra or wrong new cell')
        aliases.append(dict(original_IAT_va=va, canonical_IAT_symbol=cell['canonical_IAT_symbol'],
                            proposed_pointer_symbol=item['pointer_symbol'], dll=item['dll'], export=item['export'],
                            library=request['replacement']['new_library'], member_offset=item['member_offset'],
                            pointer_indirection_preserved=True, alias_applied=False,
                            source_ABI_approved=False, runtime_provider_adopted=False))
    combined = request['prior_other_aliases']+aliases
    require(len(combined) == 26 and len({a['original_IAT_va'] for a in combined}) == 26 and
            len({a['canonical_IAT_symbol'] for a in combined}) == 26 and
            len({a['proposed_pointer_symbol'] for a in combined}) == 26, 'combined pointer identity collision')
    require(all(a['alias_applied'] is False and a['source_ABI_approved'] is False and
                a['runtime_provider_adopted'] is False for a in combined), 'combined alias promotion')
    return dict(schema_version=1, kind='fnv-kernel32-import-extension-native-collection',
                status='collected-awaiting-independent-conformance', request_sha256=request_sha256,
                inputs=request['inputs'], source_sha256=request['source_sha256'],
                library=dict(file='kernel32-eight.lib', sha256=parsed['archive_sha256'], bytes=parsed['archive_bytes']),
                parsed_archive=parsed, proposed_pointer_aliases=sorted(combined, key=lambda a: a['original_IAT_va']),
                unchanged_libraries=request['unchanged_libraries'], replacement=request['replacement'],
                replacement_identity_verified=True, old_seven_pointer_identities_preserved=True,
                native_library_generated=True, global_caller_census_verified=False, **FALSE_FLAGS)


def read_bound(path, expected):
    path = Path(path)
    require(path.stat().st_size <= 64*1024*1024 and sha(path) == expected, 'input hash/size differs')
    return json.loads(path.read_text(encoding='utf-8'))


def run(args):
    out = Path(args.out).resolve()
    require(out.is_relative_to(ROOT/'build/rebuild'), 'output is not private')
    paths = dict(plan=Path(args.plan).resolve(), previous=Path(args.previous).resolve(), native=Path(args.native).resolve())
    pins = dict(plan=PLAN_PIN, previous=PREVIOUS_PREPARATION_PIN, native=PREVIOUS_NATIVE_PIN)
    observed = {paths[k]: h for k, h in pins.items()}
    observed.update({Path(__file__).resolve(): args.source_sha256, Path(projection.__file__).resolve(): PROJECTION_PIN,
                     Path(archive.__file__).resolve(): PARSER_PIN,
                     projection.NAMESPACE_HELPER.resolve(): projection.NAMESPACE_HELPER_PIN})
    def stable():
        require(all(sha(p) == h for p, h in observed.items()), 'source/input drift')
    stable()
    data = {k: read_bound(paths[k], pins[k]) for k in paths}
    request, definition = prepare(data['plan'], data['previous'], data['native'])
    request['inputs'] = dict(import_plan_sha256=PLAN_PIN, previous_preparation_sha256=PREVIOUS_PREPARATION_PIN,
                             previous_native_collection_sha256=PREVIOUS_NATIVE_PIN)
    request['source_sha256'] = {str(p.relative_to(ROOT)).replace('\\', '/'): h
                                for p, h in observed.items() if p.is_relative_to(ROOT/'tools')}
    # Reparse all four exact accepted libraries before promising unchanged inputs.
    for lib in data['native']['libraries']:
        path = paths['native'].parent/lib['library']
        require(sha(path) == lib['archive_sha256'], 'previous library drift')
        parsed = archive.read_archive(path)
        require(parsed['imports'] == lib['imports'] and parsed['index'] == lib['index'], 'previous native parse differs')
        observed[path] = lib['archive_sha256']
    stable(); out.mkdir(parents=True, exist_ok=False); created = []
    try:
        with (out/'kernel32-eight.def').open('xb') as stream:
            created.append(out/'kernel32-eight.def'); stream.write(definition)
        stable()
        with (out/'preparation.json').open('x', encoding='utf-8') as stream:
            created.append(out/'preparation.json'); json.dump(request, stream, indent=2, sort_keys=True); stream.write('\n')
        stable()
    except BaseException:
        for path in reversed(created): path.unlink()
        out.rmdir(); raise
    return request


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    for option in ('plan', 'previous', 'native', 'out', 'source-sha256'):
        parser.add_argument('--'+option, required=True)
    result = run(parser.parse_args())
    print(json.dumps(dict(status=result['status'], cells=len(result['cells']), new_cell=NEW_CELL)))
