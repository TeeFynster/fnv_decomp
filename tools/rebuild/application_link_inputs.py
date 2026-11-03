"""Assemble a private partial application input set; never invoke native tools.

The only transform is one typed host undefined-name binding. Import aliases
remain proposals. Archive support members remain lazy candidates, not providers.
"""
from __future__ import annotations
import argparse
from collections import Counter, defaultdict
import hashlib
import json
from pathlib import Path
import struct
import tempfile

import coff_code_archive as coff
from coff_inventory import Coff
from game_startup_host import CANONICAL, IDENTITY

ROOT = Path(__file__).resolve().parents[2]
HELPER_PIN = '76244d2d4dca4c1f8aa72224be1ef5c92f68976b5cda7d31b5cfe23d3cc29e64'
SOURCE_PINS = {
    'tools/rebuild/coff_code_archive.py': HELPER_PIN,
    'tools/rebuild/coff_inventory.py': '3518c044738046e7cd9c8be37a3b1077af750fb2e7a19db793b09999a07ee0d2',
    'tools/rebuild/game_startup_host.py': 'ef32b867ea948c96f416d94dc26d0fef2010f0323cfa65560a0cad77c0998867',
    'tests/rebuild/test_application_link_inputs.py': '86407257e21acf11bb859079bc62d7af0b9d594180106df23708a5dd4933e692',
    'docs/rebuild/APPLICATION-LINK-INPUTS.md': '1c24e37c0ccb4fe816fd6c18eb4a6669e83608aca5a748fa8311ee6075f8f948',
}
TYPED = '_fnv_game_application_entry@16'
INPUTS = {
    'host_receipt': ('game-startup-host-native-v1/receipt.json', '5e8e9407f5c1ba995193a62d838c819d3261adfa681ffee08f2106d8c7dafde4'),
    'host': ('game-startup-host-native-v1/game_startup_host.obj', '3c54d5f91fb8076b1282cefcddf498181cc830370c1d2e398b6cea4a7c4910fe'),
    'entry_receipt': ('application-entry-projection-v1/receipt.json', 'b46ffd72903c4363f545884d3dbb5cbb3bcf355d1ef8e84171c8fae1861eeb6b'),
    'entry': ('application-entry-projection-v1/r0576-application-entry.obj', '5a409edc83262a5d48179d42283d46375b191ce2403541d7e3c92adab5d7113e'),
    'entry_archive': ('application-entry-projection-v1/application-entry.lib', '603c36b75a3e7ef24191df5000ece1c716f3b040e4bc5910dc2bb81fa66fe2eb'),
    'data_receipt': ('data-arena-alias-projection-v1/projection.json', 'b1a6554ad8170f06f7367a21d5b6ecd6b8b6c910e3fa3241ef8a3bde039db792'),
    'data_namespace': ('data-arena-alias-projection-v1/namespace-map.json', 'b045a065376852a2570ca277619d6f595a2589ba1772f3c74f6775cd72b48b85'),
    'data_0': ('data-arena-alias-projection-v1/cb8d58d939251b22cc7429f62751a51e83d1c6f11abeef2489d3b96a973b7c1a.obj', '2243cf180e35988042c930514b7b3ae54cdab4cafa951c179312537e4000e67e'),
    'data_1': ('data-arena-alias-projection-v1/a80a7435d3665b08022dc0a36be353e4ffafa56da5fd9b4337224164f96aedeb.obj', '1b786bd7a6fbef349327851bbc8ebc350b3deabb9ca190144bf7b33f2a26f686'),
    'import_receipt': ('import-native-main-v2/collection.json', '4e75e3a126b459914e6b6d9946a7d3154e8114860a8317496975ea67600f244b'),
    'import_preparation': ('import-projection-main-v2/preparation.json', 'b7f7c72ac71490b01610c97e7ef68da80a822b7877c9887e6b2e5ff53bd43e1c'),
    'import_0': ('import-native-main-v2/provider-000.lib', '2627bd866f27b6d867d85f305e1d0fd0a002c4dc14f5037189c1f645d0dfdd91'),
    'import_1': ('import-native-main-v2/provider-001.lib', '8b08ff0e8eb7a6ea48f7a84537c564560409d8353166c883214d15f50e18d5e7'),
    'import_2': ('import-native-main-v2/provider-002.lib', 'ed07b437804514dbd5f61888fb2051a83a694ab3563585183146547ec0045c9a'),
    'import_3': ('import-native-main-v2/provider-003.lib', 'd8e796986b100a743fb06429d2385b4975628f8d273f094088f619e40f0d046d'),
}


def require(ok, message):
    if not ok:
        raise ValueError(message)


def digest(data):
    return hashlib.sha256(data).hexdigest()


def standard_metadata(data):
    """Independent physical reader; temporary member bytes remain private."""
    with tempfile.TemporaryDirectory(prefix='fnv_link_metadata_') as temp:
        path = Path(temp) / 'input.obj'
        path.write_bytes(data)
        obj = Coff(path)
    return dict(symbols=obj.symbols, sections=obj.sections, directives=obj.directives)


def externals(metadata):
    rows = list(metadata['symbols'].values())
    require(not any(r['storage'] == 105 or (r['storage'] == 2 and r['section'] == 0 and r['value'])
                    for r in rows), 'weak/common provider requires separate contract')
    return ([r for r in rows if r['storage'] == 2 and r['section'] > 0],
            [r for r in rows if r['storage'] == 2 and r['section'] == 0])


def bind_host(data, entry_data):
    before, entry = standard_metadata(data), standard_metadata(entry_data)
    definitions, undefined = externals(before)
    entry_defs, _ = externals(entry)
    require([r['name'] for r in definitions] == ['_WinMain@16'] and
            len(undefined) == 1 and undefined[0]['name'] == TYPED and
            undefined[0]['type'] == 32 and undefined[0]['value'] == 0 and
            undefined[0]['aux_count'] == 0, 'host typed stdcall shape differs')
    require([r['name'] for r in entry_defs] == [CANONICAL], 'entry export differs')
    index = undefined[0]['index']
    fields = [(s['index'], off, target, kind) for s in before['sections'].values()
              for off, target, kind in s['relocs']]
    require(len(fields) == 1 and fields[0][2:] == (index, 20), 'host REL32 shape differs')
    output = coff.namespace(data, [(index, CANONICAL)])
    after = standard_metadata(output)
    expected = json.loads(json.dumps(before))
    # JSON normalizes tuple/list and integer dictionary keys only for comparison.
    expected['symbols'][str(index)]['name'] = CANONICAL
    require(json.loads(json.dumps(after)) == expected, 'independent name-only metadata mismatch')
    return output, dict(physical_symbol_index=index, source=TYPED, destination=CANONICAL,
        source_sha256=digest(data), output_sha256=digest(output), fields=fields,
        name_only_verified=True, ABI_conversion_performed=False)


def native_archive(data):
    """Read both actual library indices, every static member and short import."""
    require(len(data) <= 32 * 1024 * 1024 and data[:8] == b'!<arch>\n', 'native archive size/magic')
    rows, pos = [], 8
    while pos < len(data):
        require(len(rows) < 10000 and pos + 60 <= len(data), 'archive member bound')
        header = data[pos:pos + 60]
        require(header[58:] == b'`\n', 'archive header')
        size = int(header[48:58]); end = pos + 60 + size
        require(end <= len(data), 'archive extent')
        rows.append((pos, header[:16].decode('ascii').strip(), data[pos + 60:end]))
        if size % 2:
            require(data[end:end + 1] == b'\n', 'archive padding')
        pos = end + size % 2
    require(pos == len(data) and len(rows) >= 3 and rows[0][1] == rows[1][1] == '/', 'archive index pair')
    members = {off: body for off, name, body in rows[2:] if name != '//'}
    first, second = rows[0][2], rows[1][2]
    require(len(first) >= 4 and len(second) >= 4, 'short archive index')
    n = struct.unpack_from('>I', first)[0]
    require(n <= 100000 and 4 + 4 * n <= len(first), 'first index count')
    offsets = struct.unpack_from('>' + str(n) + 'I', first, 4)
    names = first[4 + 4 * n:].split(b'\0')
    require(len(names) == n + 1 and not names[-1], 'first index strings')
    one = [(name.decode('ascii'), off) for name, off in zip(names[:-1], offsets)]
    m = struct.unpack_from('<I', second)[0]
    require(m == len(members) and 8 + 4 * m <= len(second), 'second member count')
    member_offsets = struct.unpack_from('<' + str(m) + 'I', second, 4)
    require(list(member_offsets) == list(members), 'second physical member table')
    k = struct.unpack_from('<I', second, 4 + 4 * m)[0]; at = 8 + 4 * m
    require(k == n and at + 2 * k <= len(second), 'second index count')
    numbers = struct.unpack_from('<' + str(k) + 'H', second, at)
    names = second[at + 2 * k:].split(b'\0')
    require(len(names) == k + 1 and not names[-1] and all(1 <= v <= m for v in numbers), 'second index strings/ordinals')
    two = [(name.decode('ascii'), member_offsets[number - 1]) for name, number in zip(names[:-1], numbers)]
    require(sorted(one) == two and len({name for name, _ in two}) == n and
            all(off in members for _, off in two), 'native indices conflict')
    imports, support, claimed = [], [], []
    for off, body in members.items():
        require(len(body) >= 20, 'short member')
        if body[:4] == b'\0\0\xff\xff':
            sig1, sig2, version, machine, stamp, size, hint, types = struct.unpack_from('<HHHHIIHH', body)
            require(version == 0 and machine == 0x14c and size == len(body) - 20 and
                    types & 3 == 0 and types >> 2 == 2, 'unreviewed short-import encoding')
            strings = body[20:].split(b'\0')
            require(len(strings) == 3 and not strings[-1], 'short-import strings')
            symbol, dll = [s.decode('ascii') for s in strings[:2]]
            require(symbol.startswith('_') and len(symbol) > 1, 'short-import name type')
            export, pointer = symbol[1:], '__imp_' + symbol
            require(sorted(name for name, offset in two if offset == off) == sorted([symbol, pointer]), 'short-import index join')
            imports.append(dict(member_offset=off, member_sha256=digest(body), symbol=symbol,
                pointer_symbol=pointer, dll=dll, export=dict(kind='name', name=export),
                machine=machine, import_type=0, name_type=2, hint_or_ordinal=hint))
            claimed += [(symbol, off), (pointer, off)]
        else:
            meta = standard_metadata(body)
            defined, undefined = externals(meta)
            require(sorted(r['name'] for r in defined) == sorted(name for name, offset in two if offset == off), 'static import support index differs')
            support.append(dict(member_offset=off, member_sha256=digest(body),
                definitions=defined, undefined=undefined, sections=meta['sections']))
            claimed += [(r['name'], off) for r in defined]
    require(sorted(claimed) == two, 'native member/export coverage')
    return dict(index=[dict(symbol=n, member_offset=o) for n, o in two],
                first_index=[dict(symbol=n, member_offset=o) for n, o in one], imports=imports,
                support_members=support, member_count=len(members), both_indexes_agree=True)


def index_multiset(rows):
    """Normalize order only; preserve every symbol/member occurrence."""
    require(isinstance(rows, list) and all(isinstance(row, dict) and
        set(row) == {'symbol', 'member_offset'} and isinstance(row['symbol'], str) and
        type(row['member_offset']) is int and row['member_offset'] >= 8 for row in rows),
        'invalid physical archive index rows')
    return sorted((row['symbol'], row['member_offset']) for row in rows)


def unique_definitions(components):
    definitions, undefined = {}, []
    for component, metadata in components:
        defs, undefs = externals(metadata)
        for row in defs:
            require(row['name'] not in definitions, 'duplicate/conflicting selected definition: ' + row['name'])
            definitions[row['name']] = dict(component=component, **row)
        undefined.extend(dict(component=component, **row) for row in undefs)
    return definitions, undefined


def join_fields(entry, projection):
    actual = {(section, offset): (target, kind) for section, sec in entry['sections'].items()
              for offset, target, kind in sec['relocs']}
    require(len(actual) == len(projection['fields']) == len(projection['original_field_obligations']), 'entry field coverage')
    obligations = {r['offset']: r for r in projection['original_field_obligations']}
    require(len(obligations) == len(actual), 'duplicate entry obligations')
    rows = []
    for field in projection['fields']:
        original_section, offset = field['original_section'], field['offset']
        section = projection['mapping']['section_map'][str(original_section)]
        index = field['serialized_symbol_index']
        obligation = obligations[offset]
        require(actual[(section, offset)] == (index, field['kind']) and
            projection['mapping']['symbol_map'][str(field['physical_symbol_index'])] == index and
            obligation['symbol_index'] == field['physical_symbol_index'] and
            obligation['kind'] == field['kind'] and obligation['addend_bits'] == field['addend_bits'] == 0,
            'entry field/physical obligation conflict')
        rows.append(dict(obligation, section=section, offset=offset,
            physical_symbol_index=field['physical_symbol_index'], symbol_index=index,
            symbol=entry['symbols'][index]['name']))
    require(len({(r['section'], r['offset']) for r in rows}) == len(actual) and
        {(r['section'], r['offset']) for r in rows} == set(actual), 'incomplete actual field bijection')
    return rows


def data_coverage(data_objects, namespace, entry, fields):
    aliases = namespace['aliases']
    require(len(aliases) == 16 and len({a['symbol'] for a in aliases}) == 16, 'sixteen DATA aliases required')
    objects = {digest(data): standard_metadata(data) for data in data_objects}
    require(len(objects) == 2, 'two DATA objects required')
    covered = []
    field_map = {row['offset']: row for row in fields}
    for alias in aliases:
        meta = objects[alias['object_sha256']]
        row = meta['symbols'][alias['physical_symbol_index']]
        require(row['storage'] == 2 and row['name'] == alias['symbol'] and
                row['section'] == alias['section'] and row['value'] == alias['section_offset'], 'physical DATA alias differs')
        require(not any(s['relocs'] for s in meta['sections'].values()), 'DATA object has fixups')
        for source in alias['entry_source_records']:
            field = field_map[source['field_offset']]
            require(source['recipe_id'] == IDENTITY['recipe_id'] and source['addend'] == 0 and
                field['physical_symbol_index'] == source['original_symbol_index'] and
                field['symbol'] == alias['symbol'] and field['role'] == 'data' and
                field['kind'] == 6 and field['original_base'] == alias['original_base'] and
                entry['symbols'][field['symbol_index']]['section'] == 0, 'DATA alias/entry field conflict')
            covered.append(field['offset'])
    require(len(covered) == len(set(covered)) == 20, 'twenty unique DATA fields required')
    return sorted(covered)


def import_proposals(collection, preparation, libraries, fields):
    proposals = collection['proposed_pointer_aliases']
    require(len(proposals) == len(preparation['selected_cells']) == 25, '25 IAT proposals required')
    prepared = {row['canonical_IAT_symbol']: row for row in preparation['selected_cells']}
    require(len(prepared) == 25 and len({p['canonical_IAT_symbol'] for p in proposals}) == 25, 'duplicate IAT identities')
    result, covered = [], []
    for proposal in proposals:
        cell = prepared[proposal['canonical_IAT_symbol']]
        native = libraries[proposal['library']]
        matches = [r for r in native['imports'] if r['member_offset'] == proposal['member_offset']]
        require(len(matches) == 1, 'IAT native member absent/ambiguous')
        row = matches[0]
        require(proposal['alias_applied'] is False and proposal['runtime_provider_adopted'] is False and
            proposal['source_ABI_approved'] is False and proposal['pointer_indirection_preserved'] is True and
            cell['original_IAT_va'] == proposal['original_IAT_va'] and
            cell['dll'] == proposal['dll'] == row['dll'] and
            cell['export'] == proposal['export'] == row['export'] and
            proposal['proposed_pointer_symbol'] == row['pointer_symbol'] and
            row['pointer_symbol'].startswith('__imp_'), 'IAT-to-native pointer identity conflict')
        uses = [f for f in fields if f['symbol'] == proposal['canonical_IAT_symbol']]
        require(uses and all(f['role'] == 'iat-cell' and f['kind'] == 6 and
            f['original_target'] == proposal['original_IAT_va'] for f in uses), 'IAT entry fields differ')
        covered += [f['offset'] for f in uses]
        result.append(dict(proposal, entry_fields=[f['offset'] for f in uses], applied=False))
    require(len(covered) == len(set(covered)) == 30, '30 IAT field coverage required')
    return result


def namespace_intersection(definitions, import_exports, lazy_definitions):
    require(not (set(definitions) & set(import_exports)) and
        not (set(definitions) & set(lazy_definitions)) and
        not (set(import_exports) & set(lazy_definitions)),
        'selected/import/support namespace conflict')


def assemble(inputs):
    """Pure in-memory assembly, including host name-only projection."""
    docs = {k: json.loads(v) for k, v in inputs.items() if k.endswith('_receipt') or k in ['data_namespace', 'import_preparation']}
    require(docs['host_receipt']['status'] == 'pass' and docs['host_receipt']['object_sha256'] == digest(inputs['host']), 'host receipt differs')
    projection = docs['entry_receipt']['projection']
    require(docs['entry_receipt']['status'] == 'unresolved-source-entry-projected' and
        projection['member_sha256'] == digest(inputs['entry']) and
        projection['archive_sha256'] == digest(inputs['entry_archive']), 'entry receipt differs')
    recovered = coff.read_archive(inputs['entry_archive'])
    require(len(recovered['members']) == 1 and recovered['members'][0][1] == inputs['entry'] and
        recovered['index'] == [(CANONICAL, recovered['members'][0][0])], 'entry archive/member differs')
    data_receipt = docs['data_receipt']
    require(data_receipt['aliases'] == 16 and data_receipt['entry_fields'] == 20 and
        data_receipt['initialized_bytes'] == 446 and data_receipt['relocations'] == 0 and
        {r['object_sha256'] for r in data_receipt['objects']} == {digest(inputs['data_0']), digest(inputs['data_1'])}, 'DATA receipt differs')
    require(docs['data_namespace']['projection_sha256'] == digest(inputs['data_receipt']), 'DATA namespace/receipt differs')
    bound_host, binding = bind_host(inputs['host'], inputs['entry'])
    components = [('host', standard_metadata(bound_host)), ('entry', standard_metadata(inputs['entry']))] + [
        (key, standard_metadata(inputs[key])) for key in ['data_0', 'data_1']]
    definitions, undefined = unique_definitions(components)
    entry = components[1][1]
    fields = join_fields(entry, projection)
    covered = data_coverage([inputs['data_0'], inputs['data_1']], docs['data_namespace'], entry, fields)
    collection = docs['import_receipt']
    require(collection['kind'] == 'fnv-main-normal-import-native-collection' and
        collection['native_library_generated'] is True and collection['alias_applied'] is False and
        collection['runtime_provider_adopted'] is False, 'import collection state differs')
    libraries, lazy_definitions = {}, defaultdict(list)
    import_exports = set()
    for number, observed in enumerate(collection['libraries']):
        key, name = 'import_' + str(number), observed['library']
        require(name == f'provider-{number:03d}.lib' and observed['archive_sha256'] == digest(inputs[key]), 'native library/hash differs')
        native = native_archive(inputs[key])
        require(native['imports'] == observed['imports'] and
            index_multiset(native['index']) == index_multiset(observed['index']) and
            native['member_count'] == observed['member_count'] and observed['both_indexes_agree'] is True, 'native collection/member differs')
        native['collection_index_order'] = observed['index']
        libraries[name] = native
        for row in native['imports']:
            for symbol in [row['symbol'], row['pointer_symbol']]:
                require(symbol not in definitions and symbol not in import_exports, 'duplicate/conflicting import export: ' + symbol)
                import_exports.add(symbol)
        for member in native['support_members']:
            for row in member['definitions']:
                require(row['name'] not in definitions and row['name'] not in import_exports, 'selected/support namespace conflict')
                lazy_definitions[row['name']].append(dict(library=name, member_offset=member['member_offset'], **row))
    require(len(libraries) == 4, 'four native import libraries required')
    namespace_intersection(definitions, import_exports, lazy_definitions)
    proposals = import_proposals(collection, docs['import_preparation'], libraries, fields)
    resolved = [r for r in undefined if r['name'] in definitions]
    unresolved = [r for r in undefined if r['name'] not in definitions]
    remaining = {role: [] for role in ['CODE', 'DATA', 'CRT', 'IAT']}
    for field in fields:
        if field['symbol'] not in definitions:
            role = {'code': 'CODE', 'data': 'DATA', 'crt-contract': 'CRT', 'iat-cell': 'IAT'}[field['role']]
            remaining[role].append(field)
    report = dict(schema_version=1, kind='partial-game-application-link-inputs',
        status='partial-inputs-with-unresolved-obligations', host_binding=binding,
        definitions=definitions, undefined_records=undefined, resolved_records=resolved,
        unresolved_records=unresolved, remaining_fields=remaining, DATA_fields_covered=covered,
        import_pointer_proposals=proposals, native_import_libraries=libraries,
        lazy_archive_support_definitions=dict(lazy_definitions),
        lazy_archive_support_duplicates={k: v for k, v in lazy_definitions.items() if len(v) > 1},
        lazy_support_selection_performed=False, import_aliases_applied=False,
        definition_resolution_is_runtime_approval=False,
        summary=dict(selected_definitions=len(definitions), undefined_records=len(undefined),
            undefined_names=len({r['name'] for r in undefined}), resolved_records=len(resolved),
            unresolved_names=len({r['name'] for r in unresolved}), data_fields_covered=len(covered),
            proposed_IAT_names=len(proposals), remaining_fields={k: len(v) for k, v in remaining.items()}),
        eventual_link_plan=dict(executable='exact doctor SP1 link.exe; not invoked',
            arguments=['/nologo', '/MACHINE:X86', '/SUBSYSTEM:WINDOWS', '/OUT:private-game.exe',
                'host-bound.obj', 'application-entry.lib', 'data-0.obj', 'data-1.obj'] +
                [f'provider-{n:03d}.lib' for n in range(4)],
            normal_CRT_default_libraries=['LIBCMT', 'OLDNAMES'],
            search_paths_bound=False, command_ready=False,
            missing_contracts=['transitive CODE/DATA/CRT providers', 'actual IAT pointer bindings and ABI',
                'lazy import support extraction', 'normal CRT/initializer/TLS/resource ownership']),
        link_ready=False, executable_linked=False, execution_performed=False,
        provider_adoption=False, runtime_eligible=False)
    return bound_host, report


def reviewed_sources(repository, source_sha256):
    expected = dict(SOURCE_PINS,
        **{'tools/rebuild/application_link_inputs.py': source_sha256})
    require(isinstance(source_sha256, str) and len(source_sha256) == 64 and
        all(c in '0123456789abcdef' for c in source_sha256), 'expected reviewed source hash required')
    require(all(digest((repository / name).read_bytes()) == pin for name, pin in expected.items()),
        'reviewed source/dependency hash differs')
    return expected


def run(out, source_sha256, repository=ROOT):
    repository, out = Path(repository).resolve(), Path(out).resolve()
    require(not out.exists(), 'new private output directory required')
    require(not out.is_relative_to(repository) or out.is_relative_to(repository / 'build/rebuild'), 'output must be private')
    sources = reviewed_sources(repository, source_sha256)
    paths = {key: repository / 'build/rebuild' / relative for key, (relative, pin) in INPUTS.items()}
    inputs = {}
    for key, path in paths.items():
        inputs[key] = path.read_bytes()
        require(digest(inputs[key]) == INPUTS[key][1], 'accepted input hash differs: ' + key)
    bound, report = assemble(inputs)
    require(all(digest(path.read_bytes()) == INPUTS[key][1] for key, path in paths.items()) and
        all(digest((repository / name).read_bytes()) == pin for name, pin in sources.items()),
        'input/source drift before publication')
    out.mkdir(parents=True)
    report['input_sha256'] = {key: pin for key, (relative, pin) in INPUTS.items()}
    report['source_sha256'] = sources
    (out / 'host-bound.obj').write_bytes(bound)
    outputs = {'host-bound.obj': digest(bound)}
    for key, name in [('entry_archive', 'application-entry.lib'), ('entry', 'entry-evidence.obj'),
            ('data_0', 'data-0.obj'), ('data_1', 'data-1.obj')] + [
            ('import_' + str(n), f'provider-{n:03d}.lib') for n in range(4)]:
        (out / name).write_bytes(inputs[key]); outputs[name] = digest(inputs[key])
    report['outputs'] = outputs
    require(all(digest(path.read_bytes()) == INPUTS[key][1] for key, path in paths.items()) and
            all(digest((repository / name).read_bytes()) == pin for name, pin in sources.items()) and
            all(digest((out / name).read_bytes()) == pin for name, pin in outputs.items()), 'input/source/output drift at publication')
    with (out / 'manifest.json').open('x', encoding='utf-8') as stream:
        json.dump(report, stream, indent=2, sort_keys=True); stream.write('\n')
    return report


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--out', type=Path, required=True)
    parser.add_argument('--source-sha256', required=True, help='trusted reviewed assembler SHA-256')
    args = parser.parse_args()
    report = run(args.out, args.source_sha256)
    print(json.dumps(report['summary'], sort_keys=True))


if __name__ == '__main__':
    main()
