"""Create an exact-address, analysis-only ledger from a hash-bound data plan."""
from __future__ import annotations
import argparse
from collections import Counter, defaultdict
import gzip
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
COLUMNS = ['site_rva', 'target_rva', 'target_class', 'target_offset', 'width', 'backing', 'blockers']
CLASSES = ('other-code', 'EH-interior-ambiguous')
EXPECTED = {'sites': 150165, 'other-code': 8056, 'EH-interior-ambiguous': 493}
MAX_DETAIL_LINES = 200000


def digest(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b''): h.update(block)
    return h.hexdigest()


def read_bound(path, expected):
    if not isinstance(expected, str) or len(expected) != 64 or any(c not in '0123456789abcdef' for c in expected):
        raise ValueError('explicit SHA-256 must be 64 lowercase hex characters')
    path = Path(path)
    if path.stat().st_size > 64 * 1024 * 1024: raise ValueError('JSON input exceeds 64 MiB')
    raw = path.read_bytes()
    actual = hashlib.sha256(raw).hexdigest()
    if actual != expected: raise ValueError('input SHA-256 mismatch')
    return json.loads(raw.decode('utf-8-sig'))


def va(value):
    if not isinstance(value, str): raise ValueError('invalid recipe address')
    number = int(value, 16)
    if number < 0 or number > 0xffffffff: raise ValueError('address outside x86 range')
    return number


def aliases_for_targets(recipes, targets):
    aliases = defaultdict(lambda: defaultdict(set))
    for index, unit in enumerate(recipes['units']):
        for name, addr in unit.get('symbols', {}).items():
            a = va(addr)
            if a in targets: aliases[a][('recipe_symbol_binding', name)].add(index)
        for item in unit.get('functions', []):
            a = va(item['address'])
            if a in targets: aliases[a][('recipe_function_entry', item['symbol'])].add(index)
    return aliases


def label_aliases(aliases, classes):
    """Name-derived labels are search hints, never verified classifications."""
    names = [item['name'].lower() for item in aliases]
    labels = set()
    if any(n.startswith('__imp_') for n in names): labels.add('import-name-heuristic')
    if any(any(part in n for part in ('security_check_cookie', 'atexit', 'cxxframehandler', 'crt', 'memcpy', 'memset')) for n in names): labels.add('CRT-name-heuristic')
    if 'EH-interior-ambiguous' in classes: labels.add('EH-ambiguous-from-input')
    if any(any(part in n for part in ('initializer', 'dynamic_initializer', 'dynamic_atexit_destructor')) for n in names): labels.add('generated-name-heuristic')
    if not labels: labels.add('unknown')
    return sorted(labels)


def summarize(plan, recipes, rows, expected=EXPECTED, canonical=None, retained=None):
    if plan.get('kind') != 'fnv-private-data-analysis' or plan.get('detail_columns') != COLUMNS:
        raise ValueError('unsupported data plan schema')
    if plan.get('runtime_ready') is not False or plan.get('status') != 'analysis-only': raise ValueError('unexpected data plan status')
    fixups = plan['fixups']; expected_counts = fixups['by_target']
    if fixups['nonexec_data_sites'] != expected['sites'] or any(expected_counts.get(k) != expected[k] for k in CLASSES):
        raise ValueError('data plan does not match the bounded expected scope')
    base = plan['image']['base']; image_size = plan['image']['size']
    if not isinstance(base, int) or not isinstance(image_size, int) or not 0 <= base < base + image_size <= 0x100000000:
        raise ValueError('invalid image bounds')
    counts, groups, sites = Counter(), defaultdict(Counter), set()
    for row in rows:
        if not isinstance(row, list) or len(row) != len(COLUMNS): raise ValueError('invalid detail row')
        site, target, category, offset, width, backing, blockers = row
        if type(site) is not int or type(target) is not int or not isinstance(category, str) or width != 4 or backing not in ('raw', 'virtual-zero-fill') or not isinstance(blockers, list): raise ValueError('invalid detail fields')
        if site < 0 or site + 4 > image_size or site in sites: raise ValueError('invalid or duplicate site')
        sites.add(site); counts[category] += 1
        if len(sites) > MAX_DETAIL_LINES: raise ValueError('detail exceeds bound')
        if category in CLASSES:
            address = base + target
            if not 0 <= target < image_size or address > 0xffffffff: raise ValueError('invalid target VA')
            groups[address][category] += 1
    if len(sites) != fixups['nonexec_data_sites'] or dict(counts) != expected_counts:
        raise ValueError('detail row counts disagree with bound data plan')
    aliases = aliases_for_targets(recipes, groups)
    examples = defaultdict(list)
    if canonical is not None:
        if canonical.get('kind') != 'fnv-canonical-address-plan' or canonical.get('selection_state') != 'UNSELECTED':
            raise ValueError('unsupported canonical plan or selection state')
        for group in canonical.get('candidate_group_examples', []):
            address = va(group['address'])
            if address in groups:
                for candidate in group.get('candidates', []):
                    examples[address].append({'recipe_index': candidate['recipe_index'], 'symbol': candidate['symbol'],
                                              'kind': candidate['kind'], 'selection_state': candidate.get('selection_state'),
                                              'abi_verified': candidate.get('abi_verified'), 'status': 'UNVERIFIED_SAMPLED_EXAMPLE'})
    matches = defaultdict(list)
    if retained is not None:
        if retained.get('kind') != 'fnv-retained-object-verification': raise ValueError('unsupported retained verification')
        for unit in retained.get('units', []):
            for function in unit.get('verified_functions', []):
                a = va(function['address'])
                if a in groups:
                    matches[a].append({'recipe_index': unit['recipe_index'], 'symbol': function['symbol'],
                                       'verdict': function['verdict'], 'status': 'REPORTED_BYTE_COMPARISON_NOT_RUNTIME_PROVIDER'})
    ledger = []
    for address, occurrences in groups.items():
        rows = [{'kind': kind, 'name': name, 'recipe_count': len(indices)}
                for (kind, name), indices in sorted(aliases[address].items())]
        ledger.append({'target_va': f'0x{address:08x}', 'occurrences': sum(occurrences.values()),
                       'class_occurrences': dict(sorted(occurrences.items())), 'exact_recipe_aliases': rows,
                       'labels': label_aliases(rows, occurrences),
                       'sampled_canonical_candidates': examples[address], 'retained_function_evidence': matches[address]})
    ledger.sort(key=lambda x: (-x['occurrences'], x['target_va']))
    return {'schema_version': 1, 'kind': 'fnv-runtime-gaps-ledger', 'status': 'analysis-only',
            'scope': 'Unique exact target VAs from two unresolved site classes; aliases are metadata references, not approved providers. No interior-range resolution.',
            'summary': {'inspected_sites': len(sites), 'selected_occurrences': sum(sum(c.values()) for c in groups.values()),
                        'unique_target_vas': len(groups), 'by_class_occurrences': {c: counts[c] for c in CLASSES},
                        'by_class_unique_targets': {c: sum(c in group for group in groups.values()) for c in CLASSES},
                        'unique_targets_with_exact_recipe_aliases': sum(bool(aliases[a]) for a in groups)},
            'limitations': ['Candidate lists are sampled, not exhaustive; no auto-selection or ABI approval.',
                            'EH ambiguity remains unresolved; no nearest-span inference.',
                            'Labels derived from names are heuristics; original fixup classes are observations.',
                            'Retained byte-comparison verdicts do not prove a runtime provider.'], 'targets': ledger}


def lines(path):
    with gzip.open(path, 'rt', encoding='utf-8') as stream:
        for line in stream:
            if len(line) > 8192: raise ValueError('detail row too large')
            yield json.loads(line)


def run(args):
    plan = read_bound(args.plan, args.plan_sha256)
    recipes = read_bound(args.recipes, plan['recipe_sha256'])
    if digest(args.detail) != plan['detail_sha256']: raise ValueError('detail SHA-256 mismatch')
    canonical = retained = None
    if bool(args.canonical) != bool(args.canonical_sha256) or bool(args.retained) != bool(args.retained_sha256):
        raise ValueError('optional input and explicit SHA-256 must be supplied together')
    if args.canonical:
        canonical = read_bound(args.canonical, args.canonical_sha256)
        if canonical['inputs']['recipe_sha256'] != plan['recipe_sha256']: raise ValueError('canonical recipe digest mismatch')
    if args.retained:
        retained = read_bound(args.retained, args.retained_sha256)
        if retained['inputs']['recipe_sha256'] != plan['recipe_sha256']: raise ValueError('retained recipe digest mismatch')
    if canonical and retained and canonical['inputs']['retained_manifest_sha256'] != retained['inputs']['retained_manifest_sha256']:
        raise ValueError('canonical and retained manifest digests differ')
    report = summarize(plan, recipes, lines(args.detail), canonical=canonical, retained=retained)
    if digest(args.detail) != plan['detail_sha256']: raise ValueError('detail changed while reading')
    report['inputs'] = {'data_plan_sha256': args.plan_sha256, 'detail_sha256': plan['detail_sha256'],
                        'recipe_sha256': plan['recipe_sha256'], 'canonical_sha256': args.canonical_sha256,
                        'retained_sha256': args.retained_sha256}
    out = args.out.resolve()
    if out.exists(): raise ValueError('output directory already exists')
    for path in (args.plan, args.detail, args.recipes, args.canonical, args.retained):
        if path and (Path(path).resolve() == out or out in Path(path).resolve().parents):
            raise ValueError('output may not contain an input')
    out.mkdir(parents=True)
    with (out / 'runtime-gaps.json').open('x', encoding='utf-8') as stream: json.dump(report, stream, indent=2); stream.write('\n')
    s = report['summary']
    text = '# Runtime target gaps\n\n' + report['scope'] + '\n\n' + '\n'.join('- %s: %s' % (k, v) for k, v in s.items()) + '\n\nSee JSON for prioritized target records and input digests. Labels are heuristic; unresolved EH overlap is not resolved.\n'
    with (out / 'runtime-gaps.md').open('x', encoding='utf-8') as stream: stream.write(text)
    return report


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--plan', required=True, type=Path); parser.add_argument('--plan-sha256', required=True)
    parser.add_argument('--detail', required=True, type=Path); parser.add_argument('--recipes', type=Path, default=ROOT/'build/units.json')
    parser.add_argument('--canonical', type=Path); parser.add_argument('--canonical-sha256')
    parser.add_argument('--retained', type=Path); parser.add_argument('--retained-sha256')
    parser.add_argument('--out', type=Path, default=ROOT/'build/rebuild/runtime-gaps')
    try: report = run(parser.parse_args(argv))
    except (OSError, ValueError, KeyError, TypeError, json.JSONDecodeError) as exc: parser.exit(2, 'ledger failed: %s\n' % str(exc))
    print('Wrote ledger with %d unique targets' % report['summary']['unique_target_vas'])
    return 0


if __name__ == '__main__': raise SystemExit(main())
