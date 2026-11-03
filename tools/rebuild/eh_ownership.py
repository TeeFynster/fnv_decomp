"""Persist exact EH-piece ownership observations; never select runtime providers."""
from __future__ import annotations

import argparse
from bisect import bisect_left
from collections import Counter
import gzip
import hashlib
import json
from pathlib import Path
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tools'))
sys.path.insert(0, str(ROOT / 'tools/rebuild'))
from compare import Coff
from coff_inventory import reconcile_recipes, Coff as InventoryCoff
from runtime_gaps import read_bound, digest, lines, COLUMNS, CLASSES


def require(condition, message):
    if not condition:
        raise ValueError(message)


def unit_hash(recipe):
    return hashlib.sha256(json.dumps(recipe, sort_keys=True, separators=(',', ':'),
                                     ensure_ascii=True).encode('ascii')).hexdigest()


def groups_from_detail(plan, detail):
    require(plan.get('kind') == 'fnv-private-data-analysis' and plan.get('runtime_ready') is False
            and plan.get('detail_columns') == COLUMNS, 'unsupported data plan')
    groups, sites, counts = {}, set(), Counter()
    base, size = plan['image']['base'], plan['image']['size']
    for row in lines(detail):
        require(isinstance(row, list) and len(row) == len(COLUMNS), 'invalid detail row')
        site, target, category, offset, width, backing, blockers = row
        require(type(site) is int and 0 <= site <= size - 4 and site not in sites
                and width == 4 and type(target) is int and isinstance(category, str)
                and backing in ('raw', 'virtual-zero-fill') and isinstance(blockers, list),
                'invalid or duplicate detail site')
        sites.add(site); counts[category] += 1
        require(len(sites) <= 200000, 'detail exceeds bounded scope')
        if category in CLASSES:
            require(0 <= target < size, 'target outside image')
            groups.setdefault(base + target, Counter())[category] += 1
    require(len(sites) == plan['fixups']['nonexec_data_sites']
            and dict(counts) == plan['fixups']['by_target'], 'detail counts disagree with plan')
    return groups


def native_pieces(coff, recipe, receipt):
    """Recover native indices by the oracle's deterministic anchor/cut order.

    No original addresses or bytes are recomputed: receipt remains the authority
    for original placement and comparison. COFF relocations identify anchor
    sections/parents; sorted symbol cuts identify native offsets.
    """
    anchors = {}
    for fn in recipe['functions']:
        symbol = coff.named(fn['symbol'])
        for offset, index, kind in coff.sections[symbol['section']]['relocs']:
            target = coff.symbols[index]
            if (symbol['value'] <= offset < symbol['value'] + fn['size'] - 3
                    and kind in (0x06, 0x14) and target['section'] > 0
                    and coff.sections[target['section']]['name'].startswith('.text$x')):
                anchors.setdefault(target['section'], fn['address'])
    native = []
    for index, parent in sorted(anchors.items()):
        section = coff.sections[index]
        length = len(section['data'])
        cuts = sorted({0, length} | {s['value'] for s in coff.symbols.values()
                       if s['section'] == index and 0 < s['value'] < length})
        native.extend((index, start, end, parent) for start, end in zip(cuts, cuts[1:]) if end > start)
    observed = receipt.get('eh_sections', [])
    require(len(native) == len(observed), 'receipt/native EH piece count differs')
    for (section, start, end, parent), piece in zip(native, observed):
        require(isinstance(piece, list) and len(piece) == 5
                and type(piece[0]) is int and type(piece[1]) is int
                and type(piece[2]) is bool and isinstance(piece[4], list)
                and piece[1] - piece[0] == end - start and piece[3] == parent,
                'receipt/native EH piece identity differs')
        yield section, start, end, piece


def physical_parent(inventory, section, verified_functions):
    """Report physical associative ownership separately from oracle anchors."""
    chain, seen = [], set()
    current = section
    while inventory.sections[current]['selection'] == 'associative':
        require(current not in seen, 'cyclic COFF association')
        seen.add(current)
        parent = inventory.sections[current]['association']
        require(parent in inventory.sections and parent != current, 'invalid COFF association')
        chain.append([current, parent]); current = parent
    if not chain:
        return dict(status='unknown-no-associative-parent', association_chain=[],
                    section=None, function_symbols=[], exact_body_verified_same_object=False)
    symbols = []
    for symbol in inventory.symbols.values():
        if symbol['section'] != current or not symbol['type'] & 0x20:
            continue
        matches = [f for f in verified_functions if f['verdict'] == 'match'
                   and f['section'] == current and f['value'] == symbol['value']]
        symbols.append(dict(symbol=symbol['name'], value=symbol['value'],
            exact_native_body_verified_same_object=bool(matches), verified_body_records=matches))
    values = {s['value'] for s in symbols}
    verified = bool(symbols) and len(values) == 1 and all(s['exact_native_body_verified_same_object'] for s in symbols)
    return dict(status='association-root-function-observed' if symbols else 'unknown-no-function-at-association-root',
        association_chain=chain, section=current, function_symbols=symbols,
        exact_body_verified_same_object=verified,
        frame_contract_verified=False)


def build_candidates(groups, manifest, receipt, root, manifest_dir, observations):
    require(receipt.get('kind') == 'fnv-retained-object-verification'
            and receipt.get('schema_version') == 1
            and all(receipt.get(k) is True for k in ('retained_verification_pass',
                'function_byte_verification_pass', 'global_listed_eh_coverage_pass',
                'original_oracle_parity_pass', 'evidence_stable'))
            and receipt['scope']['full_authoritative'] is True,
            'retained receipt does not establish full original parity')
    units = {u['recipe_index']: u for u in manifest['units']}
    require(len(units) == len(manifest['units']) and all(u.get('status') == 'compiled' for u in units.values()),
            'duplicate or uncompiled manifest unit')
    object_paths = [(manifest_dir / manifest.get('object_root_relative', '.') / u['object']).resolve()
                    for u in units.values()]
    require(len(set(object_paths)) == len(object_paths), 'repeated retained object path')
    checked = set()
    require(len(receipt['units']) == len(units), 'receipt scope differs from manifest')
    for row in receipt['units']:
        i = row['recipe_index']
        require(i in units and i not in checked, 'duplicate or unknown receipt unit')
        checked.add(i); unit = units[i]
        require(row['recipe_id'] == unit['recipe_id']
                and row['recipe_unit_sha256'] == unit_hash(unit['recipe'])
                and row['object_sha256'] == unit['object_sha256']
                and row['source_sha256_recorded'] == unit['source_sha256']
                and row['source_sha256_current'] == unit['source_sha256']
                and row.get('status') == 'ok', 'receipt/manifest identity conflict')
    addresses = sorted(groups)
    candidates = {a: [] for a in addresses}
    base = manifest_dir / manifest.get('object_root_relative', '.')
    selected_units = 0
    for row in receipt['units']:
        relevant = False
        for p in row.get('eh_sections', []):
            require(isinstance(p, list) and len(p) == 5 and type(p[0]) is int
                    and type(p[1]) is int and 0 <= p[0] < p[1] <= 0x100000000
                    and type(p[2]) is bool, 'invalid EH piece')
            at = bisect_left(addresses, p[0])
            if p[2] and at < len(addresses) and addresses[at] < p[1]: relevant = True
        if not relevant:
            continue
        unit = units[row['recipe_index']]
        obj = (base / unit['object']).resolve()
        source = (root / unit['source']).resolve()
        require(source.is_relative_to(root), 'source escapes root')
        require(digest(obj) == unit['object_sha256'], 'retained object hash mismatch')
        require(digest(source) == unit['source_sha256'], 'source record hash mismatch')
        observations[obj] = unit['object_sha256']; observations[source] = unit['source_sha256']
        coff = Coff(obj)
        inventory = InventoryCoff(obj)
        require(hashlib.sha256(coff.data).hexdigest() == unit['object_sha256'], 'object changed while loading')
        require(hashlib.sha256(inventory.data).hexdigest() == unit['object_sha256'], 'object changed during association parsing')
        parent_rows = {f['address']: f for f in row['verified_functions']}
        recipe_parents = {f['address']: f for f in unit['recipe']['functions']}
        for piece_index, (section, start, end, piece) in enumerate(native_pieces(coff, unit['recipe'], row)):
            if not piece[2]: continue
            parent = parent_rows.get(piece[3]); expected = recipe_parents.get(piece[3])
            require(parent is not None and expected is not None and parent['verdict'] == 'match'
                    and all(parent[k] == expected[k] for k in ('symbol', 'address', 'size')),
                    'EH parent lacks exact matched function record')
            named = coff.named(parent['symbol'])
            require(named['section'] == parent['section'] and named['value'] == parent['value'],
                    'parent native identity differs')
            at = bisect_left(addresses, piece[0])
            while at < len(addresses) and addresses[at] < piece[1]:
                address = addresses[at]
                candidates[address].append(dict(recipe_index=unit['recipe_index'], recipe_id=unit['recipe_id'],
                    source=unit['source'], source_sha256=unit['source_sha256'], object_sha256=unit['object_sha256'],
                    receipt_anchor_parent=dict(parent),
                    tail_declared_parents=[dict(t) for t in unit['recipe'].get('eh_tails', [])
                        if int(t['address'], 16) <= address < int(t['address'], 16) + t['size']],
                    physical_associative_parent=physical_parent(inventory, section, row['verified_functions']),
                    receipt_piece_index=piece_index,
                    original_interval=[piece[0], piece[1]], section=section,
                    section_name=coff.sections[section]['name'], native_piece_interval=[start, end],
                    target_native_offset=start + address - piece[0],
                    target_position='entry' if address == piece[0] else 'interior',
                    byte_coverage='HASH_BOUND_RETAINED_MATCHING_EH_PIECE',
                    native_mapping='STRUCTURAL_ORACLE_SECTION_CUT_ORDER',
                    native_mapping_assumption='trusted-receipt-producer-preserved-row-order',
                    inferred_names=piece[4], unit_local_eh_diagnostic_count=len(row.get('eh_errors', [])),
                    abi_verified=False, lifetime_verified=False, runtime_eligible=False, selected_provider=False))
                at += 1
        selected_units += 1
    return candidates, selected_units


def run(args):
    paths = {name: Path(getattr(args, name)).resolve() for name in
             ('ledger', 'plan', 'detail', 'retained', 'manifest', 'recipes')}
    root = Path(args.root).resolve()
    hashes = {name: getattr(args, name + '_sha256') for name in ('ledger', 'plan', 'retained', 'manifest')}
    data = {name: read_bound(paths[name], hashes[name]) for name in hashes}
    ledger, plan, retained, manifest = (data[n] for n in ('ledger', 'plan', 'retained', 'manifest'))
    hashes['detail'] = plan['detail_sha256']; hashes['recipes'] = plan['recipe_sha256']
    recipes = read_bound(paths['recipes'], hashes['recipes'])
    require(digest(paths['detail']) == hashes['detail'], 'detail SHA-256 mismatch')
    require(ledger.get('kind') == 'fnv-runtime-gaps-ledger' and ledger.get('status') == 'analysis-only',
            'unsupported gaps ledger')
    for key, name in (('data_plan_sha256', 'plan'), ('detail_sha256', 'detail'),
                      ('recipe_sha256', 'recipes'), ('retained_sha256', 'retained')):
        require(ledger['inputs'][key] == hashes[name], 'ledger input identity differs')
    require(manifest.get('kind') == 'fnv-retained-objects' and manifest.get('schema_version') == 1,
            'unsupported retained manifest')
    require(reconcile_recipes(manifest, paths['recipes'])['verified'], 'manifest recipe reconciliation failed')
    require(retained['inputs']['retained_manifest_sha256'] == hashes['manifest']
            and retained['inputs']['recipe_sha256'] == hashes['recipes'], 'receipt input identity differs')
    groups = groups_from_detail(plan, paths['detail'])
    expected = {}
    for target in ledger['targets']:
        a = int(target['target_va'], 16)
        require(a not in expected and target['occurrences'] == sum(target['class_occurrences'].values()),
                'duplicate or invalid ledger target')
        expected[a] = target['class_occurrences']
    require(groups == expected, 'ledger/detail target groups differ')
    observations = {paths[n]: hashes[n] for n in paths}
    for name in ('tools/build_and_match.py', 'tools/compare.py', 'tools/rebuild/verify_objects.py'):
        recorded = retained['inputs'].get('tools_sha256', {}).get(name)
        require(recorded is not None and digest(ROOT / name) == recorded,
                'receipt producer/comparison tool identity differs')
        observations[(ROOT / name).resolve()] = recorded
    observations[Path(__file__).resolve()] = digest(__file__)
    index = root / 'build/function_index.json'
    index_present = retained['inputs']['function_index_present']
    require(type(index_present) is bool and index.exists() == index_present, 'optional index presence changed')
    if index_present:
        require(digest(index) == retained['inputs']['function_index_sha256'], 'optional index hash mismatch')
        observations[index.resolve()] = retained['inputs']['function_index_sha256']
    else:
        require(retained['inputs']['function_index_sha256'] is None, 'absent index has a hash')
    candidates, selected_units = build_candidates(groups, manifest, retained, root, paths['manifest'].parent, observations)
    summary = dict(unique_targets=len(groups), occurrences=sum(sum(c.values()) for c in groups.values()),
                   units_reparsed=selected_units, candidate_observations=sum(map(len, candidates.values())),
                   by_class={}, multiple_observation_targets=0, diagnostic_bearing_targets=0)
    targets = []
    for a, classes in sorted(groups.items()):
        cs = candidates[a]
        for category, count in classes.items():
            stats = summary['by_class'].setdefault(category, dict(covered_targets=0, uncovered_targets=0,
                                                                 covered_occurrences=0, uncovered_occurrences=0))
            prefix = 'covered' if cs else 'uncovered'
            stats[prefix + '_targets'] += 1; stats[prefix + '_occurrences'] += count
        multiple = len(cs) > 1
        diagnostic = any(c['unit_local_eh_diagnostic_count'] for c in cs)
        summary['multiple_observation_targets'] += multiple
        summary['diagnostic_bearing_targets'] += diagnostic
        targets.append(dict(target_va=f'0x{a:08x}', class_occurrences=dict(classes), candidate_count=len(cs),
            piece_coverage=bool(cs), multiple_observations=multiple,
            input_EH_ambiguity='EH-interior-ambiguous' in classes,
            diagnostic_bearing=diagnostic, provider_selected=False, runtime_eligible=False))
    report = dict(schema_version=1, kind='fnv-eh-ownership-observations', status='analysis-only',
        inputs=hashes, implementation_sha256=observations[Path(__file__).resolve()],
        summary=summary, optional_index_present=index_present,
        optional_index_status='present-hash-bound' if index_present else 'absent-original-oracle-limitation',
        runtime_eligible=False, provider_selection=False, targets=targets,
        limitations=['Matching-piece byte coverage is not provider ABI, lifetime or EH graph closure.',
            'Multiple observations and input EH ambiguity remain unresolved; all alternatives are retained.',
            'Native section offsets are structurally mapped in oracle order, not a new image comparison.',
            'Objects and source observations are rehashed only for units with relevant matching pieces.'])
    out = Path(args.out).resolve(); detail_out = Path(args.details_gz).resolve() if args.details_gz else None
    outputs = [out] + ([detail_out] if detail_out else [])
    require(len(set(outputs)) == len(outputs) and not any(p.exists() or p in observations for p in outputs),
            'output exists or would overwrite input evidence')
    for path, expected_hash in observations.items():
        require(digest(path) == expected_hash, 'input changed during ownership analysis')
    require(index.exists() == index_present, 'optional index changed during analysis')
    # Exclusive creation, with rollback only for files newly created here.
    created = []
    try:
        if detail_out:
            detail_out.parent.mkdir(parents=True, exist_ok=True)
            with detail_out.open('xb') as raw:
                created.append(detail_out)
                with gzip.GzipFile(fileobj=raw, mode='wb', mtime=0) as zipped:
                    for a in sorted(candidates):
                        for c in candidates[a]:
                            zipped.write((json.dumps(dict(target_va=f'0x{a:08x}', **c), separators=(',', ':'))+'\n').encode())
            report['candidate_details_sha256'] = digest(detail_out)
            report['candidate_details_format'] = 'gzip-jsonl-one-observation-per-row'
        else:
            report['candidate_details'] = [{'target_va': f'0x{a:08x}', 'candidates': cs}
                                           for a, cs in sorted(candidates.items()) if cs]
        out.parent.mkdir(parents=True, exist_ok=True)
        with out.open('x', encoding='utf-8') as stream:
            created.append(out); json.dump(report, stream, separators=(',', ':')); stream.write('\n')
    except BaseException:
        for path in created: path.unlink(missing_ok=True)
        raise
    return report


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('ledger', 'plan', 'retained', 'manifest'):
        parser.add_argument('--' + name, type=Path, required=True)
        parser.add_argument('--' + name + '-sha256', required=True)
    parser.add_argument('--detail', type=Path, required=True)
    parser.add_argument('--recipes', type=Path, default=ROOT/'build/units.json')
    parser.add_argument('--root', type=Path, default=ROOT)
    parser.add_argument('--out', type=Path, required=True)
    parser.add_argument('--details-gz', type=Path)
    try: report = run(parser.parse_args(argv))
    except (OSError, ValueError, KeyError, TypeError) as exc: parser.exit(2, 'ownership analysis failed: %s\n' % exc)
    print(json.dumps(report['summary']))
    return 0


if __name__ == '__main__': raise SystemExit(main())
