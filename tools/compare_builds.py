#!/usr/bin/env python3
"""Check a change against the tree it starts from, without the game: the automatic check on pull requests.

main matches the game byte for byte (tools/build_and_match.py proves it with your own executable). A change keeps that
true when every function it can affect compiles to exactly what the unchanged tree compiles to: the same code bytes,
the same padding to the next function, and every relocation resolving to the same original address through
build/units.json, exactly as build_and_match.py resolves them (and the EH tails of the units that list them, through
the names the whole recipe binds). Renaming a function, a parameter or a type therefore passes, as long as
build/units.json gets the new decorated names at the same addresses; changing what any function compiles to fails.

  plan    BASE HEAD --out plan.json   what changed, whether the change keeps to what this check can vouch for, and the
                                      units to build (split into shards)
  shard   REPO BASE_SHA HEAD_SHA --plan plan.json --shard N --out result.json
                                      build the shard's units at both commits in the same folder (REPO, a git clone)
                                      and compare them
  report  --plan plan.json RESULT... [--summary FILE] [--only-shard N]
                                      the verdict (on one shard's units with --only-shard); exit 0 only when the
                                      rules hold and everything checked is identical

The rules (plan): only src/, include/, build/units.json and *.md files may change. With --trusted (a push to main, or
a pull request opened by the repository owner) .github/ and tools/ may change as well: this check cannot vouch for
them, the owner verifies them with a full build_and_match.py run, and main is built against the game after every
change. In build/units.json only decorated names may change: every unit keeps its source, compiler, flags, function
addresses and sizes, EH tails and every address its symbols bind. A unit may also bind a further name to an address
the recipe already has (identical code the linker folded has one address and several names). EH code resolves names
through the whole recipe, so when those names change in any way, every unit with EH tails is built again. Anything
else (build/image_check.json, third_party/, patches/, a new unit, an address the recipe does not have) needs a
maintainer.

A file whose change is only in comments and whitespace inside lines (nothing else moves) cannot change any function,
so its includers are not rebuilt; __LINE__ is used only to name static-assert typedefs, and a change that adds a new
__LINE__ use is rebuilt in full. The compilers come from FNV_MSVC9_ROOT etc. as for build_and_match.py. Object files
stay in a temporary folder and are deleted; results hold addresses and counts only.
"""
import argparse
from collections import Counter
from concurrent.futures import ThreadPoolExecutor
import hashlib
import json
import os
from pathlib import Path
import re
import shutil
import subprocess
import sys
import tempfile

TOOLS = Path(__file__).resolve().parent
sys.path.insert(0, str(TOOLS))
from compare import Coff                       # noqa: E402
from build_and_match import recipe_names       # noqa: E402

RECIPE = 'build/units.json'
SKIP_DIRS = {'.git', '__pycache__'}
SOURCE_EXT = ('.c', '.cpp', '.cc', '.cxx', '.h', '.hpp', '.hxx', '.inl', '.inc')


# -- plan ------------------------------------------------------------------------------------------------------------

def tree_files(root):
    root = Path(root)
    out = {}
    for dirpath, dirnames, filenames in os.walk(root):
        dirnames[:] = [d for d in dirnames if d not in SKIP_DIRS]
        for f in filenames:
            if f in SKIP_DIRS:   # a worktree's .git is a file
                continue
            p = Path(dirpath, f)
            if p.is_file() and not p.is_symlink():
                out[p.relative_to(root).as_posix()] = hashlib.sha256(p.read_bytes()).hexdigest()
    return out


def code_only(text):
    """The text with comments removed and runs of whitespace between tokens collapsed (never inside a string or
    character literal); lines that end up empty are dropped. Two files with the same result differ only in comments,
    spacing and blank lines."""
    text = text.replace('\\\r\n', '').replace('\\\n', '')
    out, i, n = [], 0, len(text)
    while i < n:
        c = text[i]
        if c in '"\'':
            j = i + 1
            while j < n and text[j] != c and text[j] != '\n':
                j += 2 if text[j] == '\\' else 1
            out.append(text[i:j + 1]); i = j + 1
        elif text.startswith('//', i):
            j = text.find('\n', i)
            i = n if j < 0 else j
        elif text.startswith('/*', i):
            j = text.find('*/', i + 2)
            if not out or out[-1] != ' ':
                out.append(' ')
            i = n if j < 0 else j + 2
        elif c in ' \t\f\v\r':
            if not out or out[-1] != ' ':
                out.append(' ')
            i += 1
        else:
            out.append(c); i += 1
    lines = (line.strip(' ') for line in ''.join(out).split('\n'))
    return '\n'.join(line for line in lines if line)


def line_uses(root, files):
    """Every line that uses __LINE__, by content (not position)."""
    uses = []
    for f in files:
        if f.endswith(SOURCE_EXT):
            uses += [line.strip() for line in Path(root, f).read_text(errors='replace').splitlines() if '__LINE__' in line]
    return sorted(uses)


INCLUDE = re.compile(r'^\s*#\s*include\s*[<"]([^>"]+)[>"]', re.M)


def include_graph(root, files):
    """file -> the files it may include. An include names every file whose path ends with it (case-insensitively, as
    on Windows): more than the compiler picks, never less."""
    by_tail = {}
    for f in files:
        parts = f.lower().split('/')
        for k in range(1, len(parts) + 1):
            by_tail.setdefault('/'.join(parts[-k:]), []).append(f)
    graph = {}
    for f in files:
        if not f.endswith(SOURCE_EXT):
            continue
        deps = set()
        for name in INCLUDE.findall(Path(root, f).read_text(errors='replace')):
            key = '/'.join(p for p in name.replace('\\', '/').lower().split('/') if p not in ('', '.'))
            while key.startswith('../'):
                key = key[3:]
            deps.update(by_tail.get(key, []))
        graph[f] = deps
    return graph


def closure(graph, start):
    seen, todo = {start}, [start]
    while todo:
        for d in graph.get(todo.pop(), ()):
            if d not in seen:
                seen.add(d); todo.append(d)
    return seen


def address_of(value):
    return int(value, 16) if isinstance(value, str) else int(value)


def recipe_problems(a, b):
    """What build/units.json changes beyond decorated names, and the units whose entry changed."""
    problems, changed = [], set()
    # every address the base recipe already names: a function's start, or a symbol some unit binds
    known = {address_of(f['address']) for u in a['units'] for f in u['functions']}
    known |= {address_of(v) for u in a['units'] for v in u.get('symbols', {}).values()}
    if a.get('totals') != b.get('totals'):
        problems.append('build/units.json: the totals changed')
    ua, ub = a['units'], b['units']
    if len(ua) != len(ub):
        return problems + ['build/units.json: %d units instead of %d' % (len(ub), len(ua))], changed
    for i, (x, y) in enumerate(zip(ua, ub)):
        where = 'build/units.json unit %d (%s)' % (i, x['source'])
        for key in ('source', 'compiler', 'flags', 'eh_tails', 'literal_symbols'):
            if x.get(key) != y.get(key):
                problems.append('%s: %s changed' % (where, key))
        if set(y) - {'source', 'compiler', 'flags', 'eh_tails', 'literal_symbols', 'functions', 'symbols'}:
            problems.append('%s: new fields %s' % (where, sorted(set(y) - set(x))))
        fa, fb = x['functions'], y['functions']
        if len(fa) != len(fb):
            problems.append('%s: %d functions instead of %d' % (where, len(fb), len(fa)))
        else:
            for f, g in zip(fa, fb):
                if (f['address'], f['size'], len(f.get('fold_aliases', []))) != \
                        (g['address'], g['size'], len(g.get('fold_aliases', []))) or set(g) - {'address', 'size', 'symbol', 'fold_aliases'}:
                    problems.append('%s: function %s changed beyond its name' % (where, f['address']))
        bound_a, bound_b = Counter(map(address_of, x.get('symbols', {}).values())), Counter(map(address_of, y.get('symbols', {}).values()))
        # a name added for an address the recipe already has (one address with several decorated names: identical code
        # the linker folded, such as one template instantiated for several types) points nothing anywhere new
        added = {v for v in bound_b - bound_a if v not in known}
        if bound_a - bound_b or added:
            problems.append('%s: its symbols bind different addresses' % where)
        if x != y:
            changed.add(i)
    return problems, changed


def plan(base, head, shard_size, max_shards, trusted=False):
    fa, fb = tree_files(base), tree_files(head)
    changed = sorted(k for k in set(fa) | set(fb) if fa.get(k) != fb.get(k))
    problems = []
    for f in changed:
        if trusted and f.startswith(('.github/', 'tools/')):
            continue   # the owner's own change: verified against the game, not by this check
        if not (f.startswith(('src/', 'include/')) or f == RECIPE or (f.endswith('.md') and not f.startswith('.github/'))):
            problems.append('%s: outside what this check can vouch for (src/, include/, build/units.json, *.md)' % f)
    ra = json.loads(Path(base, RECIPE).read_text())
    try:
        rb = json.loads(Path(head, RECIPE).read_text())
    except (OSError, ValueError) as e:
        rb = None
        problems.append('build/units.json: unreadable (%s)' % e)
    recipe_changed = set()
    if rb is not None:
        more, recipe_changed = recipe_problems(ra, rb)
        problems += more
    code_changed, comment_only = [], []
    for f in changed:
        if not f.startswith(('src/', 'include/')):
            continue
        if f in fa and f in fb and f.endswith(SOURCE_EXT) and code_only(Path(base, f).read_text(errors='replace')) == \
                code_only(Path(head, f).read_text(errors='replace')):
            comment_only.append(f)
        else:
            code_changed.append(f)
    if comment_only and line_uses(base, fa) != line_uses(head, fb):
        code_changed += comment_only; comment_only = []   # a new __LINE__ use: line positions may matter
    units = ra['units']
    affected = set(recipe_changed)
    if rb is not None and recipe_names(ra['units']) != recipe_names(rb['units']):
        # EH code resolves names through the whole recipe (recipe_names): a binding added, removed or renamed in any
        # unit can change what it resolves to in units that did not change, so every unit with EH tails is built again
        affected |= {i for i, u in enumerate(units) if u.get('eh_tails')}
    if code_changed:
        ga, gb = include_graph(base, fa), include_graph(head, fb)
        hit = set(code_changed)
        for i, u in enumerate(units):
            if (closure(ga, u['source']) | closure(gb, u['source'])) & hit:
                affected.add(i)
    affected = sorted(affected)
    n = min(max_shards, -(-len(affected) // shard_size)) if affected else 0
    shards = [affected[k::n] for k in range(n)]
    return dict(changed_files=changed, code_changed=code_changed, comment_only=comment_only,
                problems=problems, renamed=sorted(recipe_changed), units=affected,
                compilers=sorted({units[i]['compiler'] for i in affected}), shards=shards)


# -- shard -----------------------------------------------------------------------------------------------------------

def compile_unit(repo, unit, obj):
    r = subprocess.run([sys.executable, str(TOOLS / 'msvc.py'), '--compiler', unit['compiler'], '/c', '/nologo']
                       + unit['flags'] + ['/I' + str(repo / 'include'), str(repo / unit['source']), '/Fo' + str(obj)],
                       cwd=repo, capture_output=True, text=True, errors='replace')
    return None if r.returncode == 0 and obj.exists() else (r.stdout[-3000:] or 'exit code %d' % r.returncode)


def fingerprint(obj, unit, names):
    """address -> [digest of what the function compiles to, digest of its bytes alone, the names it refers to that
    build/units.json does not bind], plus one digest for the unit's EH sections."""
    coff = Coff(obj)
    local = {k: int(v, 0) for k, v in unit.get('symbols', {}).items()}
    placements, out = {}, {}
    for fn in unit['functions']:
        for n in [fn['symbol']] + fn.get('fold_aliases', []):
            local[n] = int(fn['address'], 16)
            try:
                s = coff.named(n)
            except ValueError:
                continue
            placements[(s['section'], s['value'])] = (int(fn['address'], 16), fn['size'])
    eh_names = dict(names); eh_names.update(local)
    memo = {}

    def target(sym, mappings):
        if sym['name'] in mappings:
            return ('address', mappings[sym['name']])
        sec = sym['section']
        if sec > 0:
            for (s, v), (address, size) in placements.items():
                if s == sec and v <= sym['value'] < v + size:
                    return ('address', address + sym['value'] - v)
            return ('section', section_digest(sec, mappings), sym['value'])
        if sec == -1:
            return ('absolute', sym['value'])
        return ('unbound', sym['name'])

    def section_digest(i, mappings):
        key = (i, id(mappings))
        if key not in memo:
            memo[key] = 'cycle'
            sec = coff.sections[i]
            relocs = [(o, k, target(coff.symbols[ix], mappings)) for o, ix, k in sec['relocs']]
            memo[key] = digest(sec['name'], sec['data'], relocs)
        return memo[key]

    for fn in unit['functions']:
        address = fn['address']
        try:
            s = coff.named(fn['symbol'])
        except ValueError as e:
            out[address] = ['missing', None, [fn['symbol']]]
            continue
        sec = coff.sections[s['section']]; start = s['value']
        later = [x['value'] for x in coff.symbols.values() if x['section'] == s['section'] and x['type'] & 0x20
                 and x['value'] > start and not x['name'].startswith('__catch$')]
        end = min(later) if later else len(sec['data'])
        relocs = [(o - start, k, target(coff.symbols[ix], local)) for o, ix, k in sec['relocs'] if start <= o < end]
        unbound = sorted({coff.symbols[ix]['name'] for o, ix, k in sec['relocs'] if start <= o < end
                          and target(coff.symbols[ix], local)[0] in ('section', 'unbound')})
        out[address] = [digest(sec['data'][start:end], fn['size'], relocs), digest(sec['data'][start:end]), unbound]
    if unit.get('eh_tails'):
        out['eh'] = digest([section_digest(i, eh_names) for i in range(1, len(coff.sections))
                            if coff.sections[i]['name'].startswith(('.text$x', '.xdata'))])
    return out


def digest(*parts):
    return hashlib.sha256(repr(parts).encode()).hexdigest()


def git(repo, *args):
    subprocess.run(['git', '-C', str(repo)] + list(args), check=True, capture_output=True)


def build_side(repo, sha, indices, jobs, scratch):
    git(repo, 'checkout', '--quiet', '--force', '--detach', sha)
    git(repo, 'clean', '-qfdx')
    recipe = json.loads((repo / RECIPE).read_text())
    names = recipe_names(recipe['units'])

    def one(i):
        unit = recipe['units'][i]
        obj = scratch / ('%s_%d.obj' % (sha[:12], i))
        error = compile_unit(repo, unit, obj)
        if error:
            return i, dict(error=error)
        try:
            return i, dict(functions=fingerprint(obj, unit, names))
        except Exception as e:   # an object the comparison cannot read: report it
            return i, dict(error='cannot read the object: %s' % e)
        finally:
            obj.unlink(missing_ok=True)

    with ThreadPoolExecutor(jobs) as pool:
        return dict(pool.map(one, indices)), recipe


def shard(repo, base_sha, head_sha, plan_data, n, jobs):
    indices = plan_data['shards'][n]
    repo = Path(repo).resolve()
    scratch = Path(tempfile.mkdtemp(prefix='fnv-compare-'))
    try:
        base, recipe = build_side(repo, base_sha, indices, jobs, scratch)
        head, _ = build_side(repo, head_sha, indices, jobs, scratch)
    finally:
        shutil.rmtree(scratch, ignore_errors=True)
    rows = []
    for i in indices:
        a, b = base[i], head[i]
        row = dict(unit=i, source=recipe['units'][i]['source'], functions=len(recipe['units'][i]['functions']))
        if 'error' in a:
            row.update(status='base-failed', error=a['error'])
        elif 'error' in b:
            row.update(status='does-not-compile', error=b['error'])
        else:
            fa, fb = a['functions'], b['functions']
            differ = sorted(k for k in set(fa) | set(fb) if k != 'eh' and fa.get(k, [None])[0] != fb.get(k, [None])[0])
            row.update(status='identical' if not differ and fa.get('eh') == fb.get('eh') else 'differs',
                       differ=differ, eh_differs=fa.get('eh') != fb.get('eh'),
                       same_bytes=[k for k in differ if fa.get(k, [0, 1])[1] == fb.get(k, [0, 2])[1]],
                       unbound=sorted({n for k in differ for n in fb.get(k, [0, 0, []])[2]})[:20])
        rows.append(row)
    return dict(shard=n, base=base_sha, head=head_sha, units=rows)


# -- report ----------------------------------------------------------------------------------------------------------

def report(plan_data, results, shard=None):
    """The verdict on the results (of one shard, with shard=N)."""
    rows = [r for res in results for r in res['units']]
    expected = plan_data['units'] if shard is None else plan_data['shards'][shard]
    by = {}
    for r in rows:
        by.setdefault(r['status'], []).append(r)
    built = {r['unit'] for r in rows}
    missing = sorted(set(expected) - built)
    ok = not plan_data['problems'] and not missing and all(r['status'] == 'identical' for r in rows)
    lines = ['## %s' % ('Identical to main: this change keeps every function matching' if ok else
                        'Not verified: see below')]
    lines.append('')
    lines.append('- Files changed: %d (%d with code changes, %d only in comments or spacing)' % (
        len(plan_data['changed_files']), len(plan_data['code_changed']), len(plan_data['comment_only'])))
    if plan_data['renamed']:
        lines.append('- Units whose names changed in build/units.json: %d' % len(plan_data['renamed']))
    lines.append('- Units built and compared at both commits: %d of %d affected%s (%s)' % (
        len(built), len(expected), '' if shard is None else ' in shard %d of %d' % (shard + 1, len(plan_data['shards'])),
        ', '.join('%s %d' % (k, len(v)) for k, v in sorted(by.items())) or 'none'))
    lines.append('- Functions in those units: %d' % sum(r['functions'] for r in rows))
    if plan_data['problems']:
        lines += ['', '### Needs a maintainer', '',
                  'This check only vouches for changes to src/, include/, the names in build/units.json and Markdown '
                  'files. A maintainer has to run the full build against the game for this one:', '']
        lines += ['- %s' % p for p in plan_data['problems'][:50]]
    if missing:
        lines += ['', '### Not built', '', '%d affected units have no result (a build job failed).' % len(missing)]
    for status, title in (('differs', 'Functions that compile differently'), ('does-not-compile', 'Does not compile'),
                          ('base-failed', 'main itself failed to build (a problem with the check, not the change)')):
        if by.get(status):
            lines += ['', '### %s' % title, '']
            for r in by[status][:40]:
                if status == 'differs':
                    what = ', '.join(r['differ'][:12]) + (' and %d more' % (len(r['differ']) - 12) if len(r['differ']) > 12 else '')
                    if r['eh_differs']:
                        what = (what + ', ' if what else '') + 'its EH tails'
                    lines.append('- `%s`: %s' % (r['source'], what))
                    if r.get('same_bytes'):
                        lines.append('  - the code bytes are the same in %d of these; only what they refer to changed'
                                     % len(r['same_bytes']))
                    if r.get('unbound'):
                        lines.append('  - names build/units.json does not bind for this unit: %s (string literals '
                                     '`$SG...` are numbered in order, so a new or removed literal renumbers the rest)'
                                     % ', '.join('`%s`' % n for n in r['unbound']))
                else:
                    lines += ['- `%s`' % r['source'], '', '```', r['error'].strip()[-1500:], '```', '']
    if by.get('differs'):
        lines += ['', 'Run `python3 tools/build_and_match.py --image <your FalloutNV.exe> --only <unit>` to see the '
                  'differences against the game.']
    return ok, '\n'.join(lines) + '\n'


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest='command', required=True)
    p = sub.add_parser('plan'); p.add_argument('base'); p.add_argument('head'); p.add_argument('--out', required=True)
    p.add_argument('--shard-size', type=int, default=300); p.add_argument('--max-shards', type=int, default=10)
    p.add_argument('--trusted', action='store_true', help='a push to main or the owner\'s pull request: .github/ and tools/ may change')
    s = sub.add_parser('shard'); s.add_argument('repo'); s.add_argument('base_sha'); s.add_argument('head_sha')
    s.add_argument('--plan', required=True); s.add_argument('--shard', type=int, required=True)
    s.add_argument('--out', required=True); s.add_argument('--jobs', type=int, default=os.cpu_count() or 2)
    r = sub.add_parser('report'); r.add_argument('--plan', required=True); r.add_argument('results', nargs='*')
    r.add_argument('--summary'); r.add_argument('--only-shard', type=int, help='judge one shard\'s units only')
    a = ap.parse_args()
    if a.command == 'plan':
        data = plan(a.base, a.head, a.shard_size, a.max_shards, a.trusted)
        Path(a.out).write_text(json.dumps(data, indent=1) + '\n')
        print('%d files changed, %d units to build in %d shards, %d problems' % (
            len(data['changed_files']), len(data['units']), len(data['shards']), len(data['problems'])))
        print(json.dumps(dict(shards=list(range(len(data['shards']))), compilers=data['compilers'])))
        return 0
    if a.command == 'shard':
        data = shard(a.repo, a.base_sha, a.head_sha, json.loads(Path(a.plan).read_text()), a.shard, a.jobs)
        Path(a.out).write_text(json.dumps(data, indent=1) + '\n')
        print(', '.join('%s %d' % (k, sum(r['status'] == k for r in data['units']))
                        for k in sorted({r['status'] for r in data['units']})))
        return 0
    ok, text = report(json.loads(Path(a.plan).read_text()), [json.loads(Path(f).read_text()) for f in a.results],
                      a.only_shard)
    if a.summary:
        Path(a.summary).write_text(text)
    print(text, end='')
    return 0 if ok else 1


if __name__ == '__main__':
    raise SystemExit(main())
