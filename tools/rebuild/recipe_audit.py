"""Read-only inventory of reference recipes; it does not compile or select a runtime.

Recipe IDs are zero-based positions in the input manifest. Explicit selections are
inventory annotations only and do not establish linkability or modify the manifest.
"""
from __future__ import annotations

import argparse
import hashlib
import json
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
MAX_MANIFEST_BYTES = 64 * 1024 * 1024
MAX_RECIPES = 10000


def address(value):
    """Normalize address spelling so equivalent hexadecimal values share a node."""
    if not isinstance(value, str):
        raise ValueError("address must be a hexadecimal string")
    try:
        number = int(value, 16)
    except ValueError as exc:
        raise ValueError("invalid hexadecimal address") from exc
    if not 0 <= number <= 0xFFFFFFFF:
        raise ValueError("address outside 32-bit range")
    return f"0x{number:08x}"


def interval_union_bytes(entries):
    intervals = sorted((int(item['address'], 16), int(item['address'], 16) + item['size']) for item in entries)
    total = 0
    end = 0
    for start, stop in intervals:
        if stop > end:
            total += stop - max(start, end)
            end = stop
    return total


def audit(manifest, selections=None, manifest_sha256=None):
    units = manifest['units']
    if not isinstance(units, list) or len(units) > MAX_RECIPES:
        raise ValueError('invalid or excessive recipe count')
    recipes, functions, eh, symbols, paths = [], defaultdict(list), defaultdict(list), defaultdict(list), defaultdict(list)
    f_rows, eh_rows = [], []
    for index, unit in enumerate(units):
        source = unit['source']
        if not isinstance(source, str) or Path(source).is_absolute() or ':' in source or '..' in source.replace('\\', '/').split('/'):
            raise ValueError('source must be a relative repository path')
        recipe = {'id': index, 'source': source, 'compiler': unit['compiler'], 'flags': unit['flags'],
                  'functions': [], 'eh_tails': [], 'symbols': [], 'literal_symbols': unit.get('literal_symbols', [])}
        paths[source].append(index)
        for item in unit.get('functions', []):
            a = address(item['address']); size = item['size']; symbol = item['symbol']
            if not isinstance(size, int) or isinstance(size, bool) or size < 0 or int(a, 16) + size > 0x100000000:
                raise ValueError('invalid function size')
            row = {'recipe': index, 'address': a, 'size': size, 'symbol': symbol}
            functions[a].append(row); f_rows.append(row); recipe['functions'].append(a)
        for item in unit.get('eh_tails', []):
            a = address(item['address']); size = item['size']; parent = address(item['parent'])
            if not isinstance(size, int) or isinstance(size, bool) or size < 0 or int(a, 16) + size > 0x100000000:
                raise ValueError('invalid EH size')
            row = {'recipe': index, 'address': a, 'size': size, 'parent': parent}
            eh[a].append(row); eh_rows.append(row); recipe['eh_tails'].append(a)
        for name, value in unit.get('symbols', {}).items():
            a = address(value)
            symbols[name].append({'recipe': index, 'address': a})
            recipe['symbols'].append(name)
        recipes.append(recipe)
    definitions = defaultdict(lambda: defaultdict(list))
    for row in f_rows:
        definitions[row['symbol']][row['address']].append(row['recipe'])
    conflicting_definitions = {name: dict(addrs) for name, addrs in definitions.items() if len(addrs) > 1}
    conflicting_symbol_mappings = {name: rows for name, rows in symbols.items() if len({r['address'] for r in rows}) > 1}
    chosen = {}
    for raw_addr, recipe_id in (selections or {}).items():
        a = address(raw_addr)
        if not isinstance(recipe_id, int) or not any(row['recipe'] == recipe_id for row in functions.get(a, [])):
            raise ValueError(f'selection {a}={recipe_id} is not a function candidate')
        if a in chosen:
            raise ValueError(f'duplicate selection for {a}')
        chosen[a] = recipe_id
    return {
        'schema_version': 1,
        'provenance': {'manifest_sha256': manifest_sha256,
                       'source_content_hashed': False,
                       'note': 'Manifest digest binds raw input bytes only; source and object revisions require independent hashes.'},
        'scope': 'Manifest inventory only; potential collisions require runtime/linker investigation. Selections are unverified annotations.',
        'counts': {'recipes': len(recipes), 'source_paths': len(paths),
                   'function_rows': len(f_rows), 'unique_function_addresses': len(functions),
                   'function_aggregate_row_bytes': sum(r['size'] for r in f_rows),
                   'function_address_range_union_bytes': interval_union_bytes(f_rows),
                   'eh_rows': len(eh_rows), 'unique_eh_addresses': len(eh),
                   'eh_aggregate_row_bytes': sum(r['size'] for r in eh_rows),
                   'eh_address_range_union_bytes': interval_union_bytes(eh_rows),
                   'symbol_mapping_rows': sum(map(len, symbols.values())), 'distinct_mapped_symbols': len(symbols),
                   'function_symbols_at_multiple_addresses': len(conflicting_definitions)},
        'graph': {'recipes': recipes, 'source_paths': dict(paths), 'functions_by_address': dict(functions),
                  'eh_by_address': dict(eh), 'symbols_by_name': dict(symbols)},
        'potential_collisions': {'source_paths_in_multiple_recipes': {k:v for k,v in paths.items() if len(v)>1},
                                 'function_addresses_in_multiple_rows': {k:v for k,v in functions.items() if len(v)>1},
                                 'eh_addresses_in_multiple_rows': {k:v for k,v in eh.items() if len(v)>1},
                                 'function_symbols_at_multiple_addresses': conflicting_definitions,
                                 'symbol_mappings_at_multiple_addresses': conflicting_symbol_mappings},
        'explicit_selections': chosen,
    }


def markdown(report):
    counts = report['counts']; collisions = report['potential_collisions']
    lines = ['# Recipe inventory', '', report['scope'], '',
             'Manifest SHA-256: ' + (report['provenance']['manifest_sha256'] or 'not supplied'),
             'Source contents and object revisions are not hashed by this audit.', '', '## Counts', '']
    lines.extend(f'- {k.replace("_", " ")}: {v:,}' for k,v in counts.items())
    lines += ['', '## Review inventory', '',
              f'- Source paths used by multiple recipes: {len(collisions["source_paths_in_multiple_recipes"]):,}',
              f'- Function addresses in multiple rows: {len(collisions["function_addresses_in_multiple_rows"]):,}',
              f'- EH addresses in multiple rows: {len(collisions["eh_addresses_in_multiple_rows"]):,}',
              f'- Function names at multiple addresses: {len(collisions["function_symbols_at_multiple_addresses"]):,}',
              f'- Symbol-map names at multiple addresses: {len(collisions["symbol_mappings_at_multiple_addresses"]):,}',
              '', 'Aggregate bytes count each row; address-range unions count each covered byte once. Symbol maps include references and are not definition lists.',
              'Duplicate recipe paths, addresses, or names are review candidates, not proven linker errors.',
              'The JSON graph provides candidate recipe IDs, compiler flags, EH parent edges, and symbol mappings.',
              '', '## Explicit selections', '']
    if report['explicit_selections']:
        for a, recipe in sorted(report['explicit_selections'].items()):
            lines.append(f'- {a}: recipe {recipe} (unverified inventory annotation)')
    else:
        lines.append('None. No implementation was selected automatically.')
    return '\n'.join(lines) + '\n'


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--manifest', type=Path, default=ROOT / 'build' / 'units.json')
    parser.add_argument('--out', type=Path, default=ROOT / 'build' / 'rebuild', help='private output directory')
    parser.add_argument('--select', action='append', default=[], metavar='ADDRESS=RECIPE_ID', help='annotate an explicitly chosen candidate; repeatable')
    parser.add_argument('--force', action='store_true', help='replace existing audit reports in the output directory')
    args = parser.parse_args(argv)
    selections = {}
    try:
        if args.manifest.stat().st_size > MAX_MANIFEST_BYTES:
            raise ValueError('manifest exceeds size limit')
        for raw in args.select:
            raw_addr, raw_id = raw.split('=', 1)
            a = address(raw_addr)
            if a in selections:
                raise ValueError(f'duplicate selection for {a}')
            selections[a] = int(raw_id)
        raw_manifest = args.manifest.read_bytes()
        if len(raw_manifest) > MAX_MANIFEST_BYTES:
            raise ValueError('manifest exceeds size limit')
        report = audit(json.loads(raw_manifest.decode('utf-8-sig')), selections,
                       hashlib.sha256(raw_manifest).hexdigest())
        args.out.mkdir(parents=True, exist_ok=True)
        output_json = args.out / 'recipe-audit.json'
        output_md = args.out / 'recipe-audit.md'
        if not args.force and (output_json.exists() or output_md.exists()):
            raise ValueError('audit report already exists; choose another output directory or pass --force')
        mode = 'w' if args.force else 'x'
        with output_json.open(mode, encoding='utf-8') as stream:
            json.dump(report, stream, indent=2)
            stream.write('\n')
        with output_md.open(mode, encoding='utf-8') as stream:
            stream.write(markdown(report))
    except (OSError, ValueError, KeyError, TypeError) as exc:
        parser.exit(2, f'audit failed: {exc}\n')
    print('Wrote recipe-audit.json and recipe-audit.md')
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
