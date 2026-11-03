"""Bounded, metadata-only initializer audit; never establishes CRT table bounds.

Only nine named generated-initializer recipes are inspected. Original pointer
fields are read exclusively at sites joined through the pinned HIGHLOW ledger.
No code, runtime provider, source registration or inferred table is emitted.
"""
from __future__ import annotations
import argparse
from collections import Counter, defaultdict
import gzip
import json
from pathlib import Path
import struct

from coff_inventory import Coff
from data_plan import Pe, file_hash

RECIPES = (1671, 1677, 1678, 1679, 1680, 1681, 1682, 1683, 1684)
PINS = {
    'manifest': 'bc62a5fb2553431b1e0547d11f366e52efb73096ea8ceb206c556ae5740a53eb',
    'selection': '48ae62cdc5b1754b9c4af674ef4716d53afb554882e174a93acf860eaf1c6cb1',
    'owners': 'fac1496a2675e9a6b697d604c8d5b35a2e4b8bb6194e2ec823e5a37d1092f2e8',
    'data_plan': '127644b75ed0c2826a3c1d89e4718076f4617b5a0d1f949b5faa4d61f54e6e93',
    'data_details': '92c4058fa8ce0a74dd05d8919cc664ebf8326e9d76303d2e67338969880e5fc6',
    'recipes': '62f2c8da5f0daa912abdf4576328706711c6561eef7f01c93a89cb71ad46fb6c',
    'reference': 'df1788907c6e26ef4df0b448ead526825336356b5606650165a1ce0825097eb7',
}
BOUNDARY_NAMES = ('___xc_a', '___xc_z', '___xi_a', '___xi_z',
                  '___xp_a', '___xp_z', '___xt_a', '___xt_z',
                  '__initterm', '__initterm_e')


def require(condition, reason):
    if not condition:
        raise ValueError(reason)


def join_fields(rows, fields, base):
    """Retain every candidate site. Never choose bounds or merge equal targets."""
    targets = defaultdict(list)
    for row in rows:
        row['original_candidate_sites'] = []
        if row['original_target'] is not None:
            targets[row['original_target']].append(row)
    seen = set()
    for ordinal, field in enumerate(fields):
        require(isinstance(field, list) and len(field) == 7, 'wrong HIGHLOW columns')
        site, target, kind, offset, width, backing, blockers = field
        require(isinstance(site, int) and isinstance(target, int) and width == 4,
                'invalid HIGHLOW identity')
        require(site not in seen, 'duplicate HIGHLOW site')
        seen.add(site)
        for row in targets.get(base + target, ()):
            require(backing == 'raw', 'candidate site is not raw backed')
            row['original_candidate_sites'].append(dict(
                ordinal=ordinal, original_site=base + site, target_class=kind,
                target_offset=offset, backing=backing, blockers=blockers))


def object_slots(coff, unit, selections):
    bindings = dict(unit['recipe']['symbols'])
    bindings.update({f['symbol']: f['address'] for f in unit['recipe']['functions']})
    rows, sections = [], []
    for section in coff.sections.values():
        if not section['name'].startswith('.CRT$'):
            continue
        require(section['size'] % 4 == 0, 'unaligned CRT pointer section')
        raw = struct.unpack_from('<I', coff.data, 20 + (section['index'] - 1) * 40 + 20)[0]
        offsets = [r[0] for r in section['relocs']]
        require(len(offsets) == len(set(offsets)), 'overlapping CRT relocations')
        require(all(o % 4 == 0 and o + 4 <= section['size'] for o in offsets),
                'CRT relocation outside aligned slot')
        sections.append(dict(section=section['index'], category=section['name'],
                             size=section['size'], relocated_slots=len(offsets),
                             unrelocated_slots=section['size'] // 4 - len(offsets)))
        for offset, index, kind in section['relocs']:
            require(kind == 6, 'CRT pointer is not DIR32')
            symbol = coff.symbols[index]
            require(symbol['type'] == 32 and symbol['section'] > 0,
                    'CRT target is not a defined native function')
            addend = struct.unpack_from('<I', coff.data, raw + offset)[0]
            require(addend == 0, 'interior CRT function target requires separate proof')
            bound = bindings.get(symbol['name'])
            target = int(bound, 16) if bound else None
            selected = selections.get('0x%08x' % target) if target is not None else None
            same_owner = bool(selected and selected['recipe_id'] == unit['recipe_id'] and
                selected['symbol'] == symbol['name'] and
                selected['section'] == symbol['section'] and selected['value'] == symbol['value'])
            function_section = coff.sections.get(symbol['section'])
            registration_fields, pointer_candidates = [], []
            if function_section is not None and same_owner:
                start, end = symbol['value'], symbol['value'] + selected['size']
                for field, target_index, field_kind in function_section['relocs']:
                    if not start <= field < end:
                        continue
                    referenced = coff.symbols[target_index]
                    if referenced['name'] == '_atexit':
                        require(field_kind == 20, 'atexit reference is not REL32')
                        registration_fields.append(dict(offset=field - start,
                            symbol_index=target_index, binding=bindings.get('_atexit')))
                    if field_kind == 6 and referenced['type'] == 32:
                        address = bindings.get(referenced['name'])
                        pointer_candidates.append(dict(offset=field - start,
                            symbol_index=target_index, symbol=referenced['name'],
                            original_target=address,
                            selected_owner=selections.get(address) if address else None,
                            callback_argument_relation_verified=False))
            rows.append(dict(recipe_index=unit['recipe_index'], recipe_id=unit['recipe_id'],
                object_sha256=unit['object_sha256'], section=section['index'],
                category=section['name'], offset=offset, symbol_index=index,
                symbol=symbol['name'], symbol_type=symbol['type'],
                symbol_storage=symbol['storage'], relocation_kind=kind, addend=addend,
                original_target=target, selected_owner=selected,
                native_atexit_reference_fields=registration_fields,
                native_function_pointer_field_candidates=pointer_candidates,
                selected_same_physical_owner=same_owner))
    return rows, sections


def audit(args):
    paths = {name: Path(getattr(args, name)) for name in PINS}
    out = Path(args.out)
    require(not out.exists(), 'output already exists')
    require(out.resolve() not in {p.resolve() for p in paths.values()}, 'output aliases input')
    for name, path in paths.items():
        require(file_hash(path) == PINS[name], 'input hash differs: ' + name)
    manifest, selection, owners, plan, recipes = [json.loads(paths[n].read_text())
        for n in ('manifest', 'selection', 'owners', 'data_plan', 'recipes')]
    require(owners['inputs']['manifest'] == PINS['manifest'] and
            owners['inputs']['selection'] == PINS['selection'] and
            owners['inputs']['reference'] == PINS['reference'] and
            owners['data_detail_sha256'] == PINS['data_details'] and
            plan['detail_sha256'] == PINS['data_details'], 'ledger anchors differ')
    rows, objects, protected = [], [], []
    for index in RECIPES:
        unit = manifest['units'][index]
        require(unit['recipe_index'] == index and unit['recipe'] == recipes['units'][index],
                'recipe identity differs')
        obj = paths['manifest'].parent / unit['object']
        source = Path(args.source_root) / unit['source']
        for path, expected in ((obj, unit['object_sha256']), (source, unit['source_sha256'])):
            require(file_hash(path) == expected, 'object/source hash differs')
            protected.append((path, expected))
        native_rows, sections = object_slots(Coff(obj), unit, selection['selections'])
        rows.extend(native_rows)
        objects.append(dict(recipe_index=index, recipe_id=unit['recipe_id'],
            source_sha256=unit['source_sha256'], object_sha256=unit['object_sha256'],
            sections=sections))
    pe = Pe(paths['reference'])
    try:
        with gzip.open(paths['data_details'], 'rt') as stream:
            join_fields(rows, (json.loads(line) for line in stream), pe.base)
        relocations = set(pe.relocations())
        for row in rows:
            for site in row['original_candidate_sites']:
                rva = site['original_site'] - pe.base
                require(rva in relocations, 'candidate lacks original HIGHLOW metadata')
                require(struct.unpack('<I', pe.read_rva(rva, 4))[0] == row['original_target'],
                        'candidate pointer differs from ledger')
    finally:
        pe.close()
    boundary_bindings = []
    for index, unit in enumerate(recipes['units']):
        for name, address in unit.get('symbols', {}).items():
            if name in BOUNDARY_NAMES:
                boundary_bindings.append(dict(recipe_index=index, symbol=name, address=address))
    result = dict(schema_version=1, kind='fnv-game-initializer-bounded-audit',
        status='analysis-only', inputs=PINS, implementation_sha256=file_hash(__file__),
        scope='nine exact generated-initializer recipes; not all game CRT contributions',
        objects=objects, rows=rows, boundary_name_bindings=boundary_bindings,
        summary=dict(native_slots=len(rows), bound_slots=sum(r['original_target'] is not None for r in rows),
            same_physical_selected_owner=sum(r['selected_same_physical_owner'] for r in rows),
            native_atexit_reference_fields=sum(len(r['native_atexit_reference_fields']) for r in rows),
            original_candidate_site_counts=dict(Counter(len(r['original_candidate_sites']) for r in rows))),
        original_table_bounds_verified=False, original_runtime_order_verified=False,
        provider_approved=False, registration_emitted=False, runtime_ready=False)
    for name, path in paths.items():
        require(file_hash(path) == PINS[name], 'input changed: ' + name)
    for path, expected in protected:
        require(file_hash(path) == expected, 'object/source changed')
    with out.open('x', encoding='utf-8') as stream:
        json.dump(result, stream, separators=(',', ':'))
    return result['summary']


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    for name in PINS:
        parser.add_argument('--' + name.replace('_', '-'), required=True)
    parser.add_argument('--source-root', required=True)
    parser.add_argument('--out', required=True)
    print(json.dumps(audit(parser.parse_args()), sort_keys=True))


if __name__ == '__main__':
    main()
