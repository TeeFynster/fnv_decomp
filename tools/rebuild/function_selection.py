#!/usr/bin/env python3
"""Select hash-bound recipe function ownership; never link or certify runtime ABI."""
import argparse
from collections import Counter, defaultdict
import gzip
import json
from pathlib import Path

from canonical_plan import (sha256, checked_inputs, checked_verification,
                            verified_spans_for_object, selected_function_evidence)
from coff_inventory import inspect_object


def address(value):
    return '0x%08x' % int(value, 0)


def choose(groups, expected, overrides):
    """Match each recipe row exactly; no metadata-only substitute can own code."""
    selected = {}
    seen = set()
    used = set()
    for group in groups:
        key = address(group['address'])
        if key in seen:
            raise ValueError('duplicate candidate address: ' + key)
        seen.add(key)
        candidates = [c for c in group['candidates']
                      if c.get('reference_selection_basis') == 'SELECTED_RECIPE_FUNCTION']
        if key not in expected:
            if candidates:
                raise ValueError('unexpected selected function address: ' + key)
            continue
        actual = {}
        for c in candidates:
            ident = (c.get('recipe_id'), c.get('symbol'))
            if ident in actual:
                raise ValueError('duplicate selected candidate: ' + key)
            actual[ident] = c
        if set(actual) != set(expected[key]):
            raise ValueError('missing or conflicting selected candidate: ' + key)
        for ident, fields in expected[key].items():
            c = actual[ident]
            if any(c.get(k) != v for k, v in fields.items()):
                raise ValueError('selected candidate evidence mismatch: ' + key)
        if len(actual) == 1:
            if key in overrides:
                raise ValueError('override for unambiguous address: ' + key)
            ident = next(iter(actual))
        else:
            choice = overrides.get(key)
            if choice is None:
                raise ValueError('missing ambiguous address override: ' + key)
            matches = [ident for ident in actual if ident[0] == choice['recipe_id']]
            if len(matches) != 1:
                raise ValueError('override does not identify exactly one candidate: ' + key)
            ident = matches[0]
            used.add(key)
        c = actual[ident]
        selected[key] = {'recipe_id': ident[0], 'recipe_index': c['recipe_index'],
                         'symbol': ident[1], 'section': c['section'], 'value': c['value'],
                         'size': c['verified_function_span']['size'],
                         'selection_status': 'CODE_OWNERSHIP_SELECTED',
                         'runtime_eligible': False, 'link_ready': False}
    if set(selected) != set(expected):
        raise ValueError('missing function address groups')
    if used != set(overrides):
        raise ValueError('unused or unknown override')
    return selected


def load_overrides(path):
    data = json.loads(Path(path).read_text(encoding='utf-8-sig'))
    if data.get('schema_version') != 1 or data.get('kind') != 'fnv-function-provider-overrides':
        raise ValueError('unsupported overrides')
    result = {}
    for row in data['overrides']:
        key = address(row['address'])
        if key in result or not isinstance(row.get('recipe_id'), str) or not isinstance(row.get('reason'), str) or not row['reason'].strip():
            raise ValueError('invalid or duplicate override')
        result[key] = row
    return result


def run(recipes, manifest_path, inventory, receipt, receipt_hash, plan_path, plan_hash,
        candidates, candidates_hash, overrides_path, output):
    paths = [recipes, manifest_path, inventory, receipt, plan_path, candidates, overrides_path]
    if Path(output).exists() or Path(output).resolve() in {Path(p).resolve() for p in paths}:
        raise ValueError('output must be a new distinct path')
    hashes = {str(p): sha256(p) for p in paths}
    if hashes[str(plan_path)] != plan_hash or hashes[str(candidates)] != candidates_hash:
        raise ValueError('plan or candidate fingerprint mismatch')
    if hashes[str(receipt)] != receipt_hash:
        raise ValueError('receipt fingerprint mismatch')
    manifest, base, _ = checked_inputs(recipes, manifest_path, inventory)
    proof = checked_verification(receipt, receipt_hash, manifest, manifest_path, recipes)
    plan = json.loads(Path(plan_path).read_text(encoding='utf-8-sig'))
    if (plan.get('kind') != 'fnv-canonical-address-plan' or
        plan.get('inputs', {}).get('recipe_sha256') != sha256(recipes) or
        plan['inputs'].get('retained_manifest_sha256') != sha256(manifest_path) or
        plan['inputs'].get('inventory_sha256') != sha256(inventory) or
        plan.get('retained_verification', {}).get('receipt_sha256') != receipt_hash):
        raise ValueError('plan provenance mismatch')
    expected = defaultdict(dict)
    for unit in manifest['units']:
        obj = inspect_object(base / unit['object'], unit)
        selected_function_evidence(obj, unit)
        records = verified_spans_for_object(proof, unit, obj)
        sections = {s['index']: s for s in obj['sections']}
        children = Counter(s['association'] for s in obj['sections'] if s['selection'] == 'associative')
        symbols = {s['name']: s for s in obj['symbols'] if s['section'] > 0}
        for row in records:
            key = address(row['address']); ident = (unit['recipe_id'], row['symbol'])
            if ident in expected[key]:
                raise ValueError('duplicate recipe function identity')
            sym = symbols[row['symbol']]; sec = sections[row['section']]
            expected[key][ident] = dict(recipe_index=unit['recipe_index'], source=unit['source'],
                symbol_index=sym['index'], kind='function_definition', section=row['section'], value=row['value'],
                section_name=sec['name'], section_flags=sec['flags'], comdat=sec['comdat'],
                selection=sec['selection'], associative_children=children[row['section']],
                own_unit_local_eh_diagnostic_count=len(proof['units'][unit['recipe_index']].get('eh_errors', [])),
                byte_comparison_status='HASH_BOUND_SELECTED_FUNCTION_MATCH', hash_bound_function_byte_verified=True,
                abi_verified=False, runtime_closure_verified=False, eligible_for_selection=False, selection_state='UNSELECTED',
                verified_function_span=dict(section=row['section'], value=row['value'], size=row['size'],
                                            verified_symbol=row['symbol'], identity_only_alias=False))
    index_path = Path(__file__).resolve().parents[2] / 'build/function_index.json'
    index_present = index_path.is_file()
    if index_present is not json.loads(Path(receipt).read_text(encoding='utf-8-sig'))['inputs']['function_index_present']:
        raise ValueError('function index presence changed')
    overrides = load_overrides(overrides_path)
    with gzip.open(candidates, 'rt', encoding='utf-8') as stream:
        selected = choose((json.loads(line) for line in stream), expected, overrides)
    if (index_path.is_file() != index_present or
        any(sha256(p) != h for p, h in hashes.items()) or
        any(sha256(p) != h for p, h in proof['observations'].items())):
        raise ValueError('input changed during selection')
    for unit in manifest['units']:
        if sha256(base / unit['object']) != unit['object_sha256']:
            raise ValueError('object changed during selection')
    notes = dict(proof['notes'])
    notes['local_eh_diagnostics'] = [dict(recipe_id=u['recipe_id'], errors=u['eh_errors'])
                                     for u in proof['units'].values() if u.get('eh_errors')]
    result = dict(schema_version=1, kind='fnv-function-code-ownership-selection',
                  input_sha256=dict(recipe=hashes[str(recipes)], manifest=hashes[str(manifest_path)],
                                    inventory=hashes[str(inventory)], receipt=receipt_hash, plan=plan_hash,
                                    candidates=candidates_hash, overrides=hashes[str(overrides_path)]),
                  function_addresses=len(selected), selected_recipe_rows=sum(map(len, expected.values())),
                  ambiguity_count=len(overrides), retained_verification=notes,
                  function_index_present=index_present,
                  runtime_eligible=False, link_ready=False,
                  selections={k: selected[k] for k in sorted(selected)})
    created = False
    try:
        with Path(output).open('x', encoding='utf-8') as stream:
            created = True
            json.dump(result, stream, separators=(',', ':'), sort_keys=True)
    except Exception:
        if created:
            Path(output).unlink(missing_ok=True)
        raise


def main():
    p = argparse.ArgumentParser(description=__doc__)
    for name in ('recipes', 'manifest', 'inventory', 'receipt', 'plan', 'candidates', 'overrides', 'output'):
        p.add_argument('--'+name, required=True, type=Path)
    for name in ('receipt-sha256', 'plan-sha256', 'candidates-sha256'):
        p.add_argument('--'+name, required=True)
    a = p.parse_args()
    run(a.recipes, a.manifest, a.inventory, a.receipt, a.receipt_sha256, a.plan, a.plan_sha256,
        a.candidates, a.candidates_sha256, a.overrides, a.output)

if __name__ == '__main__':
    main()
