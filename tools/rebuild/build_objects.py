"""Retain one private COFF object per build recipe; never link or change matching.

Cache reuse is deliberately disabled until transitive compiler/header inputs have
a complete dependency key. Each invocation uses a fresh run directory.
"""
import argparse
from collections import Counter
from concurrent.futures import ThreadPoolExecutor
from datetime import datetime, timezone
import hashlib
import json
from pathlib import Path
import subprocess
import sys
import uuid

sys.path.insert(0, str(Path(__file__).resolve().parent))
import toolchain

ROOT = Path(__file__).resolve().parents[2]


def canonical(value):
    return json.dumps(value, sort_keys=True, separators=(',', ':'), ensure_ascii=True).encode('ascii')


def recipe_id(index, unit):
    return '%04d-%s' % (index, hashlib.sha256(canonical(unit)).hexdigest()[:16])


def load_recipes(manifest, root):
    units = json.loads(Path(manifest).read_text(encoding='utf-8'))['units']
    for unit in units:
        source = (root / unit['source']).resolve()
        if not source.is_relative_to(root.resolve()) or not source.is_file():
            raise ValueError('source must be an existing file inside repository: %s' % unit['source'])
        if unit['compiler'] not in toolchain.ROOT_VARS:
            raise ValueError('unknown compiler: %s' % unit['compiler'])
        if not isinstance(unit['flags'], list) or not all(isinstance(x, str) for x in unit['flags']):
            raise ValueError('flags must be a list of strings')
    return list(enumerate(units))


def build_one(item, root, output, run_dir, compilers):
    index, unit = item
    identity = recipe_id(index, unit)
    directory = run_dir / identity
    directory.mkdir(parents=True)
    obj, log = directory / 'unit.obj', directory / 'compile.log'
    result = dict(recipe_index=index, recipe_id=identity, recipe=unit,
                  source=unit['source'], compiler=unit['compiler'],
                  source_sha256=toolchain.sha256(root / unit['source']),
                  log=log.relative_to(output).as_posix(), reusable=False)
    compiler = compilers[unit['compiler']]
    if not compiler['ready']:
        result.update(status='toolchain-unavailable', error=compiler.get('error'))
        log.write_text(compiler.get('error', 'toolchain unavailable') + '\n', encoding='utf-8')
        return result
    compiler_root = Path(compiler['root'])
    command = [str(compiler_root / 'VC/bin/cl.exe'), '/c', '/nologo'] + unit['flags'] + [
        '/I' + str(root / 'include'), str(root / unit['source']), '/Fo' + str(obj)]
    result['command'] = command
    try:
        code, text = toolchain.run(command, compiler_root, root)
        log.write_text(text, encoding='utf-8')
        result['returncode'] = code
        if code or not obj.exists():
            result.update(status='compile-failed', error=text[-2000:])
        else:
            result.update(status='compiled', object=obj.relative_to(output).as_posix(),
                          object_sha256=toolchain.sha256(obj), object_size=obj.stat().st_size)
    except (OSError, subprocess.TimeoutExpired) as error:
        log.write_text(str(error) + '\n', encoding='utf-8')
        result.update(status='compile-failed', error=str(error))
    return result


def write_report(path, report):
    temporary = path.with_suffix('.tmp')
    temporary.write_text(json.dumps(report, indent=2) + '\n', encoding='utf-8')
    temporary.replace(path)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--root', type=Path, default=ROOT, help='source repository')
    parser.add_argument('--manifest', type=Path, help='recipe JSON; default ROOT/build/units.json')
    parser.add_argument('--output', type=Path, default=ROOT / 'build/rebuild', help='private artifact directory')
    parser.add_argument('--jobs', type=int, default=2, choices=range(1, 17), metavar='1..16')
    parser.add_argument('--only', help='source substring filter, retaining every matching variant')
    parser.add_argument('--limit', type=int)
    toolchain.add_arguments(parser)
    args = parser.parse_args()
    if args.limit is not None and args.limit < 1:
        parser.error('--limit must be positive')
    root, output = args.root.resolve(), args.output.resolve()
    manifest = (args.manifest or root / 'build/units.json').resolve()
    try:
        recipes = load_recipes(manifest, root)
    except (OSError, ValueError, KeyError, TypeError) as error:
        parser.error(str(error))
    total_recipes = len(recipes)
    if args.only:
        recipes = [x for x in recipes if args.only in x[1]['source']]
    if args.limit:
        recipes = recipes[:args.limit]
    if not recipes:
        parser.error('no recipes selected')
    output.mkdir(parents=True, exist_ok=True)
    run_id = datetime.now(timezone.utc).strftime('%Y%m%dT%H%M%SZ') + '-' + uuid.uuid4().hex[:8]
    run_dir = output / 'objects' / run_id
    run_dir.mkdir(parents=True)
    compilers = toolchain.doctor({n: getattr(args, n + '_root') for n in toolchain.ROOT_VARS})
    report = dict(schema_version=1, kind='fnv-retained-objects', run_id=run_id,
                  source_root=str(root), recipe_manifest_sha256=toolchain.sha256(manifest),
                  selection=dict(total_recipes=total_recipes, selected_recipes=len(recipes),
                                 complete=len(recipes) == total_recipes, only=args.only, limit=args.limit),
                  jobs=args.jobs, toolchains=compilers, units=[],
                  cache=dict(reuse=False, reason='transitive dependency key not implemented'),
                  verification='compile only; no byte-match or runnable-game claim')
    report_path = output / 'objects.json'
    run_report_path = output / ('objects-' + run_id + '.json')
    with ThreadPoolExecutor(max_workers=args.jobs) as pool:
        for result in pool.map(lambda item: build_one(item, root, output, run_dir, compilers), recipes):
            report['units'].append(result)
            if len(report['units']) % 100 == 0:
                write_report(run_report_path, report)
                print('%d/%d recipes' % (len(report['units']), len(recipes)), flush=True)
    report['summary'] = dict(recipes=len(recipes), statuses=dict(Counter(x['status'] for x in report['units'])))
    # Both the immutable run report and latest report resolve paths from output.
    write_report(run_report_path, report)
    write_report(report_path, report)
    print(json.dumps(dict(manifest=str(report_path), summary=report['summary'])))
    return 0 if all(x['status'] == 'compiled' for x in report['units']) else 1


if __name__ == '__main__':
    raise SystemExit(main())
