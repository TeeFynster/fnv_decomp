"""Hash-bound comparison of retained objects using unchanged reference functions.

Never compiles, rewrites, links, executes game code, or writes binary differences.
"""
from __future__ import annotations

import argparse
from collections import Counter
from concurrent.futures import ThreadPoolExecutor
import hashlib
import json
from pathlib import Path
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tools'))
import build_and_match as oracle
from coff_inventory import reconcile_recipes


def sha256(path):
    digest = hashlib.sha256()
    with Path(path).open('rb') as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b''):
            digest.update(block)
    return digest.hexdigest()


def unit_hash(unit):
    return hashlib.sha256(json.dumps(unit, sort_keys=True, separators=(',', ':'),
                                     ensure_ascii=True).encode('ascii')).hexdigest()


def check_retained(unit, path, pe, spans, names):
    recipe = unit['recipe']
    result = dict(recipe_id=unit['recipe_id'], recipe_index=unit['recipe_index'],
        recipe_unit_sha256=unit_hash(recipe), object_sha256=unit['object_sha256'],
        source_sha256_recorded=unit['source_sha256'], source_sha256_current=unit['source_sha256'],
        functions=len(recipe['functions']), bytes=sum(f['size'] for f in recipe['functions']))
    try:
        coff = oracle.Coff(path)
        if hashlib.sha256(coff.data).hexdigest() != unit['object_sha256']:
            raise ValueError('object changed before comparison')
        # Identical pure comparison and manifest fields to check_unit; the only
        # replaced step is compilation: the hash-checked retained input is used.
        manifest = dict(symbols=recipe.get('symbols', {}), functions=recipe['functions'],
                        literal_symbols=recipe.get('literal_symbols', []))
        rows = oracle.compare(coff, pe, manifest, spans)
        matched = [row for row in rows if row['verdict'] == 'match']
        bad = [dict(address=row['address'], size=row['size'],
                    differing_bytes=len(row['byte_differences']), errors=row['errors'][:2])
               for row in rows if row['verdict'] != 'match']
        result.update(status='ok' if not bad else 'mismatch', matched_functions=len(matched),
                      matched_bytes=sum(row['size'] for row in matched), mismatches=bad)
        result['verified_functions'] = [dict(symbol=row['symbol'], address=row['address'],
            size=row['size'], section=coff.named(row['symbol'])['section'],
            value=coff.named(row['symbol'])['value'], verdict='match') for row in matched]
        if recipe.get('eh_tails'):
            try:
                sections, inferred, errors = oracle.eh_sections(coff, pe, recipe, rows, names)
            except Exception as error:
                sections, inferred, errors = [], {}, ['EH comparison: ' + type(error).__name__]
            result.update(eh_sections=sections,
                          eh_inferred={k: '0x%08x' % v for k, v in inferred.items()}, eh_errors=errors)
    except Exception as error:
        # Do not serialize comparator byte-difference structures or unexpected
        # exception payloads. The object and tool hashes identify the input.
        result.update(status='compare-error', error_type=type(error).__name__)
    return result


def verify(manifest_path, recipe_path, image_path, output_path, expected_image_sha256,
           *, root=ROOT, jobs=2, only=None, limit=None, require_full=False,
           expected_manifest_sha256=None):
    if jobs not in (1, 2):
        raise ValueError('at most two concurrent object parsers are permitted')
    if limit is not None and limit < 1:
        raise ValueError('limit must be positive')
    root = Path(root).resolve()
    manifest_path, recipe_path, image_path, output = [Path(p).resolve() for p in
        (manifest_path, recipe_path, image_path, output_path)]
    if output.exists():
        raise ValueError('verification receipt already exists')
    manifest_hash, recipe_hash, image_hash = map(sha256, (manifest_path, recipe_path, image_path))
    if expected_manifest_sha256 is not None and manifest_hash != expected_manifest_sha256:
        raise ValueError('retained manifest fingerprint mismatch')
    if image_hash != expected_image_sha256:
        raise ValueError('image fingerprint differs from explicitly expected SHA-256')
    manifest = json.loads(manifest_path.read_text(encoding='utf-8-sig'))
    recipes = json.loads(recipe_path.read_text(encoding='utf-8-sig'))['units']
    if manifest.get('schema_version') != 1 or manifest.get('kind') != 'fnv-retained-objects':
        raise ValueError('unsupported retained manifest')
    if Path(manifest['source_root']).resolve() != root:
        raise ValueError('retained source root differs from explicit source root')
    reconciliation = reconcile_recipes(manifest, recipe_path)
    if reconciliation['errors'] and reconciliation['errors'] != ['missing recipe indices']:
        raise ValueError('authoritative recipe reconciliation failed')
    if not manifest['units']:
        raise ValueError('empty retained scope')
    index = root / 'build/function_index.json'
    image_check = oracle.ROOT / 'build/image_check.json'
    # Preserve original main's exact conditional index behavior, and record it.
    # An absent optional index must never be represented as span-index proof.
    index_present = index.is_file()
    index_hash = sha256(index) if index_present else None
    image_check_hash = sha256(image_check)
    tools = [Path(oracle.__file__), ROOT / 'tools/compare.py', ROOT / 'tools/function_spans.py',
             Path(__file__), ROOT / 'tools/rebuild/coff_inventory.py']
    tool_hashes = {p.relative_to(ROOT).as_posix(): sha256(p) for p in tools}
    protected = {manifest_path, recipe_path, image_path, index.resolve(), image_check.resolve()}
    protected.update(p.resolve() for p in tools)
    observations = []
    seen_paths = set()
    base = manifest_path.parent / manifest.get('object_root_relative', '.')
    for unit in manifest['units']:
        if unit.get('status') != 'compiled':
            raise ValueError('retained manifest contains an uncompiled recipe')
        path = (base / unit['object']).resolve()
        source = (root / unit['source']).resolve()
        if not source.is_relative_to(root) or path in seen_paths:
            raise ValueError('invalid source or repeated object path')
        seen_paths.add(path)
        if sha256(path) != unit['object_sha256']:
            raise ValueError('retained object fingerprint mismatch: ' + unit['recipe_id'])
        if sha256(source) != unit['source_sha256']:
            raise ValueError('source observation differs from retained record: ' + unit['recipe_id'])
        protected.update((path, source))
        observations.append((path, unit['object_sha256']))
        observations.append((source, unit['source_sha256']))
    if output in protected:
        raise ValueError('receipt must not overwrite evidence')
    selected = [u for u in manifest['units'] if only is None or only in u['source']]
    if limit is not None:
        selected = selected[:limit]
    if not selected:
        raise ValueError('no retained recipes selected')
    full = reconciliation['verified'] and len(selected) == len(recipes)
    if require_full and not full:
        raise ValueError('full authoritative recipe scope is required')
    pe = oracle.Pe(image_path)
    if hashlib.sha256(pe.data).hexdigest() != image_hash:
        raise ValueError('image changed while loading')
    image_pass, hits, probes = oracle.image_ok(pe)
    if not image_pass:
        raise ValueError('unchanged reference image gate rejected image')
    spans = oracle.FunctionSpans.from_index(pe, index) if index_present else None
    names = oracle.recipe_names(recipes)  # Full authoritative recipe, as original main.
    with ThreadPoolExecutor(max_workers=jobs) as pool:
        results = list(pool.map(lambda u: check_retained(u, base / u['object'], pe, spans, names), selected))
    selected_recipes = [u['recipe'] for u in selected]
    tails, bad, inferred, n_inferred, n_conflict = oracle.eh_tails(selected_recipes, results, pe)
    functions = sum(r['functions'] for r in results)
    matched = sum(r.get('matched_functions', 0) for r in results)
    eh_errors = sum(len(r.get('eh_errors', [])) for r in results)
    summary = dict(units=len(results), status=dict(Counter(r['status'] for r in results)),
        functions=functions, matched_functions=matched, bytes=sum(r['bytes'] for r in results),
        matched_bytes=sum(r.get('matched_bytes', 0) for r in results), eh_tails=len(tails),
        matched_eh_tails=len(tails) - len(bad), eh_tail_bytes=sum(tails.values()),
        matched_eh_tail_bytes=sum(tails.values()) - sum(bad.values()), eh_tail_mismatches=sorted(bad),
        eh_tails_by_inferred_binding=len(inferred), eh_inferred_names=n_inferred,
        eh_inferred_conflicts=n_conflict, eh_comparison_errors=eh_errors)
    # Rehash every observed evidence file before issuing an immutable receipt.
    observations += [(manifest_path, manifest_hash), (recipe_path, recipe_hash), (image_path, image_hash),
                     (image_check, image_check_hash)]
    if index_present:
        observations.append((index, index_hash))
    observations += [(ROOT / name, value) for name, value in tool_hashes.items()]
    stable = all(sha256(path) == value for path, value in observations) and index.is_file() == index_present
    function_pass = (all(r['status'] == 'ok' for r in results) and matched == functions and
                     summary['matched_bytes'] == summary['bytes'])
    listed_eh_pass = not bad
    original_parity = matched == functions and not bad  # Original main's exact final comparison gate.
    retained_pass = function_pass and listed_eh_pass and not n_conflict and stable
    report = dict(schema_version=1, kind='fnv-retained-object-verification',
        verification_kind='existing retained object bytes; unchanged reference comparison functions; no compilation',
        status=('pass_with_diagnostics' if eh_errors else 'pass') if retained_pass else 'fail',
        retained_verification_pass=retained_pass,
        function_byte_verification_pass=function_pass, global_listed_eh_coverage_pass=listed_eh_pass,
        original_oracle_parity_pass=original_parity,
        strict_local_eh_diagnostics_pass=not eh_errors, runtime_closure_verified=False,
        scope=dict(authoritative_recipe_count=len(recipes), manifest_recipe_count=len(manifest['units']),
                   selected_recipe_indices=[u['recipe_index'] for u in selected], full_authoritative=full),
        inputs=dict(retained_manifest_sha256=manifest_hash, recipe_sha256=recipe_hash,
                    image_sha256=image_hash, function_index_sha256=index_hash,
                    function_index_present=index_present,
                    image_check_sha256=image_check_hash, tools_sha256=tool_hashes),
        image_gate=dict(passed=image_pass, hits=hits, probes=probes),
        evidence_stable=stable, summary=summary, units=results,
        limitations=['Current source-file hashes are observations, not proof of compiler causality or transitive header identity.',
                     'Canonical index spans apply only if function_index_present; absent index follows original main, with normal compiled extents/recipe spans still compared.',
                     'Partial scope cannot establish full retained coverage or global inference consistency outside that scope.',
                     'Globally covered listed EH tails do not establish that a locally diagnostic provider or selected section has valid runtime EH closure.',
                     'This is additional private evidence, not a service submission or standalone runtime verdict.'])
    output.parent.mkdir(parents=True, exist_ok=True)
    try:
        with output.open('x', encoding='utf-8') as stream:
            json.dump(report, stream, separators=(',', ':'))
            stream.write('\n')
    except BaseException:
        # Do not remove a path another caller created before our exclusive open.
        if 'stream' in locals():
            output.unlink(missing_ok=True)
        raise
    return report


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--manifest', required=True, type=Path)
    parser.add_argument('--recipes', type=Path, default=ROOT / 'build/units.json')
    parser.add_argument('--root', type=Path, default=ROOT)
    parser.add_argument('--image', required=True, type=Path)
    parser.add_argument('--image-sha256', required=True)
    parser.add_argument('--manifest-sha256')
    parser.add_argument('--out', required=True, type=Path)
    parser.add_argument('--jobs', type=int, choices=(1, 2), default=2)
    parser.add_argument('--only')
    parser.add_argument('--limit', type=int)
    parser.add_argument('--require-full', action='store_true')
    args = parser.parse_args()
    try:
        result = verify(args.manifest, args.recipes, args.image, args.out, args.image_sha256,
            root=args.root, jobs=args.jobs, only=args.only, limit=args.limit,
            require_full=args.require_full, expected_manifest_sha256=args.manifest_sha256)
    except (OSError, ValueError, KeyError, TypeError) as error:
        parser.exit(1, 'retained verification rejected: ' + type(error).__name__ + ': ' + str(error) + '\n')
    print(json.dumps(dict(status=result['status'], full_authoritative=result['scope']['full_authoritative'],
                          selected_recipes=len(result['units']), summary=result['summary'])))
    return 0 if result['retained_verification_pass'] else 1


if __name__ == '__main__':
    raise SystemExit(main())
