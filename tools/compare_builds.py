#!/usr/bin/env python3
"""Check a change against the tree it starts from, without the game: the automatic check on pull requests.

main matches the game byte for byte (tools/build_and_match.py proves it with your own executable). A change keeps that
true when every function it can affect compiles to exactly what the unchanged tree compiles to, at its original
address: the same bytes once every relocation is resolved through build/units.json as build_and_match.py resolves it
(a global named in code and the same address written as a constant are the same bytes in the game), only padding
after it, and the same EH code in the units that list EH tails. Renaming a function, a parameter or a type therefore
passes, as long as build/units.json gets the new decorated names at the same addresses; changing what any function
compiles to fails.

  plan    BASE HEAD --out plan.json   what changed, whether the change keeps to what this check can vouch for, and the
                                      units to build (split into shards); BASE and HEAD are clean git checkouts, and
                                      the plan names their two commits
  shard   REPO BASE_SHA HEAD_SHA --plan plan.json --shard N --out result.json
                                      build the shard's units at both commits (the plan's) in the same folder (REPO, a
                                      git clone) and compare them
  report  --plan plan.json RESULT... [--summary FILE] [--only-shard N]
                                      the verdict (on one shard's units with --only-shard); exit 0 only when the
                                      rules hold and everything checked is identical
  eh      REPO BASE_SHA HEAD_SHA --out FILE
                                      for the owner: the EH digests of every unit whose EH code differs at HEAD_SHA,
                                      for tools/verified_eh.json, after a full build of HEAD_SHA against the game

The rules (plan): only src/, include/, build/units.json and *.md files may change. With --trusted (a push to main, or
a pull request opened by the repository owner) .github/ and tools/ may change as well: this check cannot vouch for
them, the owner verifies them with a full build_and_match.py run, and main is built against the game after every
change. In build/units.json units pair up by source (and their order among units with the same source): units may be
added, removed or reordered, change their compiler or their options (only those in FLAGS), bind names to addresses
and give functions to each other, because every unit whose entry changed is built at both commits and every compiled
copy of a function must match one of main's copies at the same address. What stays: every function's address and
size, each unit's EH tails and literals, and the totals (apart from the number of units). A function that uses EH code
(itself or through a fold alias) stays in its unit: build_and_match.py finds EH tails only through the functions of the
unit that lists them. EH code resolves names through the whole recipe, so when those names change in any way, every
unit with EH tails is built again. Two lists in tools/ (main's, never the change's) stand in for what only the game can
tell: unwind_names.json, the destructors only unwinding code calls (at addresses build/units.json lists), and
verified_eh.json, EH code the owner has built against the game (the game places EH code by its EH tables, which this
check does not follow). Each function is listed once per unit, and its fold aliases must compile to exactly its code. Anything else
(build/image_check.json, patches/, a symlink, a source outside src/ and third_party/) needs a maintainer.

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
import struct
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
        for f in filenames + [d for d in dirnames if Path(dirpath, d).is_symlink()]:
            if f in SKIP_DIRS:   # a worktree's .git is a file
                continue
            p = Path(dirpath, f)
            if p.is_symlink() or not p.is_file():   # a symlink or a special file: recorded, so the plan can refuse it
                out[p.relative_to(root).as_posix()] = 'not a regular file'
            else:
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


# The compiler options a unit may use: exactly the ones main's units use (none of them names a file). Anything else
# needs a maintainer: an option can make the compiler read or load files of the change's choosing.
FLAGS = frozenset(['/Dmemcpy=fnv_zlib_memcpy', '/Dmemset=fnv_zlib_memset', '/EHs', '/EHs-c-', '/EHsc', '/GF', '/GS',
                   '/GS-', '/Gy', '/MT', '/O1', '/O2', '/Ob0', '/Ob1', '/Od', '/Oy', '/Oy-', '/fp:fast'])
COMPILERS = ('sp1', 'rtm', 'vc8')
# a unit's source: a .c or .cpp file under src/ or third_party/, every part of the path starting with a letter, digit or _
# (never an option, an absolute path, . or ..)
UNIT_SOURCE = re.compile(r'^(?:src|third_party)/(?:[A-Za-z0-9_][A-Za-z0-9_ .+-]*/)*[A-Za-z0-9_][A-Za-z0-9_ .+-]*\.(?:c|cpp)$')
UNIT_FIELDS = {'source', 'compiler', 'flags', 'eh_tails', 'literal_symbols', 'functions', 'symbols'}
FUNCTION_FIELDS = {'address', 'size', 'symbol', 'fold_aliases'}


def unit_keys(units):
    """A unit's key: its source and how many units before it build the same source (a few sources are built twice, with
    different options). Units pair up by key at both commits, so they may be added, removed or reordered."""
    seen, keys = Counter(), []
    for u in units:
        keys.append((u['source'], seen[u['source']]))
        seen[u['source']] += 1
    return keys


def recipe_problems(a, b, head_files):
    """What build/units.json changes beyond what this check verifies by building, and the keys of the units whose entry
    changed. Units may be added, removed or reordered, change their compiler and options (from FLAGS) and give
    functions to each other: the functions they compile are built at both commits and compared address by address.
    What stays: every function's address and size, each unit's EH tails and literal list, and the totals."""
    problems = []
    try:
        ka, kb = unit_keys(a['units']), unit_keys(b['units'])
        fa = Counter((address_of(f['address']), f['size']) for u in a['units'] for f in u['functions'])
        fb = Counter((address_of(f['address']), f['size']) for u in b['units'] for f in u['functions'])
        ta, tb = dict(a.get('totals') or {}), dict(b.get('totals') or {})
    except (KeyError, TypeError, ValueError) as e:
        return problems + ['build/units.json: unreadable (%r)' % e], set()
    if tb.pop('units', None) != len(b['units']) or ta.pop('units', None) is None or ta != tb:
        problems.append('build/units.json: the totals changed (only "units" may change, to the number of units)')
    if fa != fb:
        problems.append('build/units.json: the functions changed: %d addresses or sizes added, %d removed (every '
                        'function keeps its address and size)' % (sum((fb - fa).values()), sum((fa - fb).values())))
    old, new = dict(zip(ka, a['units'])), dict(zip(kb, b['units']))
    for key, y in zip(kb, b['units']):
        where = 'build/units.json unit %s' % (key[0] if not key[1] else '%s (#%d)' % key)
        x = old.get(key)
        if set(y) - UNIT_FIELDS:
            problems.append('%s: new fields %s' % (where, sorted(set(y) - UNIT_FIELDS)))
        if not isinstance(y['source'], str) or not UNIT_SOURCE.match(y['source']) or y['source'] not in head_files:
            problems.append('%s: the source must be a .c or .cpp file in src/' % where)
        if y.get('compiler') not in COMPILERS:
            problems.append('%s: compiler %r' % (where, y.get('compiler')))
        flags = y.get('flags')
        if not isinstance(flags, list) or not all(isinstance(f, str) and f in FLAGS for f in flags):
            problems.append('%s: compiler options outside the ones this check knows (%s)'
                            % (where, ' '.join(sorted(FLAGS))))
        if not isinstance(y.get('functions'), list) or not y['functions']:
            problems.append('%s: no functions' % where)
        elif not all(isinstance(f, dict) and set(f) <= FUNCTION_FIELDS and isinstance(f.get('symbol'), str)
                     and all(isinstance(n, str) for n in f.get('fold_aliases', [])) for f in y['functions']):
            problems.append('%s: a function entry with other fields' % where)
        elif len({address_of(f['address']) for f in y['functions']}) != len(y['functions']):
            # each function is compared once per unit, by address: a second entry at the same address could hide a copy
            problems.append('%s: lists an address twice' % where)
        # a binding is checked through what it does: the unit is built again (its entry changed), every function in
        # it must come out with the same bytes at its address, and a change to the names the whole recipe binds
        # rebuilds every unit with EH tails
        if not isinstance(y.get('symbols', {}), dict) or \
                not all(isinstance(v, str) and re.fullmatch(r'0x[0-9a-fA-F]{1,8}', v) for v in y.get('symbols', {}).values()):
            problems.append('%s: symbols must map names to addresses written 0x...' % where)
        for field in ('eh_tails', 'literal_symbols'):
            if (x or {}).get(field) != y.get(field):
                problems.append('%s: %s changed' % (where, field))
    for key in set(ka) - set(kb):
        if old[key].get('eh_tails') or old[key].get('literal_symbols'):
            problems.append('build/units.json unit %s: removed with its EH tails or literals' % key[0])
    changed = {k for k in set(ka) | set(kb) if old.get(k) != new.get(k)}
    return problems, changed


def commit_of(root):
    """The commit a checkout is at. The plan is made only from clean checkouts, so it describes exactly two commits, and
    only results built from those two count for it."""
    def run(*args):
        r = subprocess.run(['git', '-C', str(root)] + list(args), capture_output=True, text=True)
        return r.stdout.strip() if r.returncode == 0 else None
    top, sha = run('rev-parse', '--show-toplevel'), run('rev-parse', '--verify', 'HEAD^{commit}')
    if top is None or sha is None or Path(top).resolve() != Path(root).resolve() or \
            run('status', '--porcelain', '--untracked-files=all', '--ignored') != '':
        raise SystemExit('%s: not a clean git checkout (the plan describes one commit on each side)' % root)
    return sha


def plan(base, head, shard_size, max_shards, trusted=False):
    commits = dict(base=commit_of(base), head=commit_of(head))
    fa, fb = tree_files(base), tree_files(head)
    changed = sorted(k for k in set(fa) | set(fb) if fa.get(k) != fb.get(k))
    problems = []
    for f in changed:
        if trusted and f.startswith(('.github/', 'tools/')):
            continue   # the owner's own change: verified against the game, not by this check
        if not (f.startswith(('src/', 'include/')) or f == RECIPE or (f.endswith('.md') and not f.startswith('.github/'))):
            problems.append('%s: outside what this check can vouch for (src/, include/, build/units.json, *.md)' % f)
    odd = sorted(f for f in fb if fb[f] == 'not a regular file')
    if odd:   # a symlink can make an include read a file the change does not show; nothing else is looked at
        return dict(commits=commits, changed_files=changed, code_changed=[], comment_only=[], renamed=[], units=[],
                    compilers=[], shards=[],
                    problems=['%s: a symlink or special file (only regular files may be in the tree)' % f for f in odd])
    ra = json.loads(Path(base, RECIPE).read_text())
    try:
        rb = json.loads(Path(head, RECIPE).read_text())
        if not isinstance(rb, dict) or not isinstance(rb.get('units'), list) or \
                not all(isinstance(u, dict) and isinstance(u.get('source'), str) for u in rb['units']):
            raise ValueError('not a list of units with sources')
    except (OSError, ValueError) as e:
        rb = None
        problems.append('build/units.json: unreadable (%r)' % e)
    recipe_changed = set()
    if rb is not None:
        more, recipe_changed = recipe_problems(ra, rb, fb)
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
    if problems:   # nothing is built
        return dict(commits=commits, changed_files=changed, code_changed=code_changed, comment_only=comment_only,
                    problems=problems, renamed=[], units=[], compilers=[], shards=[])
    ua, ub = ra['units'], rb['units']
    ia = {k: i for i, k in enumerate(unit_keys(ua))}
    ib = {k: i for i, k in enumerate(unit_keys(ub))}
    affected = set(recipe_changed)
    if recipe_names(ua) != recipe_names(ub):
        # EH code resolves names through the whole recipe (recipe_names): a binding added, removed or renamed in any
        # unit can change what it resolves to in units that did not change, so every unit with EH tails is built again
        affected |= {k for k, i in ia.items() if ua[i].get('eh_tails')} | {k for k, i in ib.items() if ub[i].get('eh_tails')}
    if code_changed:
        ga, gb = include_graph(base, fa), include_graph(head, fb)
        hit = set(code_changed)
        for k in set(ia) | set(ib):
            reach = (closure(ga, ua[ia[k]]['source']) if k in ia else set()) | \
                    (closure(gb, ub[ib[k]]['source']) if k in ib else set())
            if reach & hit:
                affected.add(k)
    # one entry per affected unit: its index at each commit (None where it does not exist)
    units = [dict(source=k[0], base=ia.get(k), head=ib.get(k)) for k in sorted(affected)]
    # units that share a function (one moved from one to the other, or the same function built twice) are compared
    # together, so they go into the same shard
    group = list(range(len(units)))

    def find(i):
        while group[i] != i:
            group[i] = group[group[i]]; i = group[i]
        return i
    first = {}
    for n, e in enumerate(units):
        for side, recipe in (('base', ua), ('head', ub)):
            if e[side] is not None:
                for f in recipe[e[side]]['functions']:
                    group[find(n)] = find(first.setdefault(address_of(f['address']), n))
    groups = {}
    for n in range(len(units)):
        groups.setdefault(find(n), []).append(n)
    count = min(max_shards, -(-len(units) // shard_size)) if units else 0
    shards = [[] for _ in range(count)]
    for g in sorted(groups.values(), key=lambda g: (-len(g), g[0])):
        min(shards, key=len).extend(g)
    shards = [sorted(s) for s in shards]
    return dict(commits=commits, changed_files=changed, code_changed=code_changed, comment_only=comment_only,
                problems=problems, renamed=sorted(k[0] for k in recipe_changed), units=units,
                compilers=sorted({r[e[s]]['compiler'] for e in units for s, r in (('base', ua), ('head', ub))
                                  if e[s] is not None}), shards=shards)


# -- shard -----------------------------------------------------------------------------------------------------------

def compile_unit(repo, unit, obj):
    r = subprocess.run([sys.executable, str(TOOLS / 'msvc.py'), '--compiler', unit['compiler'], '/c', '/nologo']
                       + unit['flags'] + ['/I' + str(repo / 'include'), str(repo / unit['source']), '/Fo' + str(obj)],
                       cwd=repo, capture_output=True, text=True, errors='replace')
    return None if r.returncode == 0 and obj.exists() else (r.stdout[-3000:] or 'exit code %d' % r.returncode)


IMAGE_BASE = 0x400000


def unwind_names():
    """tools/unwind_names.json: names that only unwinding code calls and no unit binds (destructors of helper types),
    with the address the game calls, as build_and_match.py infers them from the game (see its eh_sections). The owner
    updates the list from full builds; the check reads it from main's tools, never from the change."""
    path = TOOLS / 'unwind_names.json'
    return {k: int(v, 16) for k, v in json.loads(path.read_text())['names'].items()} if path.exists() else {}


def verified_eh():
    """tools/verified_eh.json: {unit source: [EH digests]}, the EH code of units the owner has built against the game
    (build_and_match.py: every function and EH tail matching) at a commit where it differs from main, as the `eh`
    command reports it. The check accepts these as they are: it cannot follow how the game places EH code (by the EH
    tables, not by the order the compiler writes it in). Read from main's tools, never from the change."""
    path = TOOLS / 'verified_eh.json'
    return {k: set(v) for k, v in json.loads(path.read_text())['units'].items()} if path.exists() else {}


def linked(data, relocs, resolve, at=None):
    """The bytes as the linker leaves them, as far as this check knows the targets: a relocation whose target resolves
    to an original address gets its final value written in (relative to `at`, the code's original address, for a call
    or jump), so code that names a global and code that writes the same address as a constant compare equal, as they
    do in the game. Any other target is kept as a description, its 4 bytes cleared. relocs: (offset, kind, symbol)."""
    data, rest = bytearray(data), []
    for o, k, sym in relocs:
        if o + 4 > len(data):
            rest.append((o, k, sym['name'])); continue
        addend = struct.unpack_from('<i' if k == 0x14 else '<I', data, o)[0]
        t = resolve(sym, addend)
        if t[0] == 'address' and (k in (0x06, 0x07) or (k == 0x14 and at is not None)):
            value = t[1] - (IMAGE_BASE if k == 0x07 else 0) - (at + o + 4 if k == 0x14 else 0)
            struct.pack_into('<I', data, o, value & 0xffffffff)
        else:
            struct.pack_into('<I', data, o, 0)
            rest.append((o, k, t))
    return bytes(data), rest


def fingerprint(obj, unit, names, unwind=None):
    """address -> [digest of what the function is at its original address (its bytes with every relocation resolved
    through build/units.json, as build_and_match.py resolves them, and whether only padding follows it), digest of its
    bytes alone, the names it refers to that build/units.json does not bind, whether it uses EH code (.text$x)], plus
    one digest for the unit's EH sections (names resolved through the whole recipe, then `unwind`)."""
    coff = Coff(obj)
    local = {k: int(v, 0) for k, v in unit.get('symbols', {}).items()}
    placements, out = {}, {}
    for fn in unit['functions']:
        address = int(fn['address'], 16)
        for n in [fn['symbol']] + fn.get('fold_aliases', []):
            # as compare.py does in the full build: every name must be in the object, bound to one address
            if local.get(n, address) != address:
                raise ValueError('%s is bound to two addresses' % n)
            local[n] = address
            s = coff.named(n)
            if placements.setdefault((s['section'], s['value']), (address, fn['size'])) != (address, fn['size']):
                raise ValueError('%s: one object entry stands for two functions' % n)
    eh_names = dict(names); eh_names.update(local)
    unwind = unwind or {}
    memo = {}

    def target(sym, mappings, addend=0):
        """What a relocation to sym + addend resolves to, in the order compare.py and build_and_match.py resolve it:
        ('address', the original address including the addend) or a description."""
        if sym['name'] in mappings:
            return ('address', mappings[sym['name']] + addend)
        sec = sym['section']
        if sec > 0:
            point = sym['value'] + addend
            inside = [(v, address) for (s, v), (address, size) in placements.items() if s == sec and v <= point < v + size]
            if len(inside) == 1:
                return ('address', inside[0][1] + point - inside[0][0])
            return ('section', section_digest(sec, mappings), sym['value'], addend)
        if sec == -1:
            return ('address', sym['value'] + addend)
        if mappings is eh_names and sym['name'] in unwind:   # a call only unwinding code makes (build_and_match.py
            return ('address', unwind[sym['name']] + addend)  # binds these from the game)
        return ('unbound', sym['name'], addend)

    def section_digest(i, mappings):
        key = (i, id(mappings))
        if key not in memo:
            memo[key] = 'cycle'
            sec = coff.sections[i]
            data, rest = linked(sec['data'], [(o, k, coff.symbols[ix]) for o, ix, k in sec['relocs']],
                                lambda sym, addend: target(sym, mappings, addend))
            memo[key] = digest(sec['name'], data, rest)
        return memo[key]

    def body(name, address, size):
        """The code at a symbol, as it ends up at the original address: [digest of the linked bytes, digest of the bytes
        alone, the names that do not resolve to an address, whether it uses EH code]."""
        s = coff.named(name)
        sec = coff.sections[s['section']]; start = s['value']
        later = [x['value'] for x in coff.symbols.values() if x['section'] == s['section'] and x['type'] & 0x20
                 and x['value'] > start and not x['name'].startswith('__catch$')]
        end = min(later) if later else len(sec['data'])
        relocs = [(o - start, k, coff.symbols[ix]) for o, ix, k in sec['relocs'] if start <= o < end]
        code, rest = linked(sec['data'][start:start + size], [r for r in relocs if r[0] < size],
                            lambda sym, addend: target(sym, local, addend), address)
        # as compare.py: the compiled function is at least as long as the original, and only padding follows
        padded = end - start >= size and all(b in (0xcc, 0x90) for b in sec['data'][start + size:end])
        unbound = sorted({sym['name'] for o, k, sym in relocs if target(sym, local)[0] != 'address'})
        eh = any(sym['section'] > 0 and coff.sections[sym['section']]['name'].startswith('.text$x') for o, k, sym in relocs)
        return [digest(code, size, rest, padded, [(o, k, r['name']) for o, k, r in relocs if o >= size]),
                digest(sec['data'][start:end]), unbound, eh]

    for fn in unit['functions']:
        out[fn['address']] = body(fn['symbol'], int(fn['address'], 16), fn['size'])
        # a fold alias is the same code under another name (the linker keeps one copy): each must compile to exactly
        # the function's code, or the copy the game has is not the one compared. An alias that uses EH code makes the
        # function count as using it, even when the bytes are the same (moved functions must not use it)
        for n in fn.get('fold_aliases', []):
            alias = body(n, int(fn['address'], 16), fn['size'])
            out[fn['address']][3] = out[fn['address']][3] or alias[3]
            if alias[0] != out[fn['address']][0]:
                out[fn['address']] = [digest('fold alias %s differs' % n, alias[0]), alias[1], alias[2] + [n],
                                      out[fn['address']][3]]
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
    names, unwind = recipe_names(recipe['units']), unwind_names()

    def one(i):
        unit = recipe['units'][i]
        obj = scratch / ('%s_%d.obj' % (sha[:12], i))
        error = compile_unit(repo, unit, obj)
        if error:
            return i, dict(error=error)
        try:
            return i, dict(functions=fingerprint(obj, unit, names, unwind))
        except Exception as e:   # an object the comparison cannot read: report it
            return i, dict(error='cannot read the object: %s' % e)
        finally:
            obj.unlink(missing_ok=True)

    with ThreadPoolExecutor(jobs) as pool:
        return dict(pool.map(one, indices)), recipe


def shard(repo, base_sha, head_sha, plan_data, n, jobs):
    if plan_data['problems']:
        raise SystemExit('the plan has problems: nothing to build')
    repo = Path(repo).resolve()
    base_sha, head_sha = (subprocess.run(['git', '-C', str(repo), 'rev-parse', '--verify', x + '^{commit}'], check=True,
                                         capture_output=True, text=True).stdout.strip() for x in (base_sha, head_sha))
    if dict(base=base_sha, head=head_sha) != plan_data.get('commits'):
        raise SystemExit('the plan was made for other commits (%s)' % plan_data.get('commits'))
    ids = plan_data['shards'][n]
    entries = [plan_data['units'][i] for i in ids]
    scratch = Path(tempfile.mkdtemp(prefix='fnv-compare-'))
    try:
        base, ra = build_side(repo, base_sha, [e['base'] for e in entries if e['base'] is not None], jobs, scratch)
        head, rb = build_side(repo, head_sha, [e['head'] for e in entries if e['head'] is not None], jobs, scratch)
    finally:
        shutil.rmtree(scratch, ignore_errors=True)
    # every compiled copy of each function, by address: at main it matches the game (main is built against it after
    # every change), so each copy in the change must compile exactly like one of main's
    copies, verified = {'base': {}, 'head': {}}, verified_eh()
    for i, e in zip(ids, entries):
        for side, built in (('base', base), ('head', head)):
            for address, fp in built.get(e[side], {}).get('functions', {}).items():
                if address != 'eh':
                    copies[side].setdefault(address, {})[i] = fp
    rows = []
    for i, e in zip(ids, entries):
        a, b = base.get(e['base'], {}), head.get(e['head'], {})
        recipe_unit = rb['units'][e['head']] if e['head'] is not None else ra['units'][e['base']]
        row = dict(unit=i, source=e['source'], functions=len(recipe_unit['functions']))
        if 'error' in a:
            row.update(status='base-failed', error=a['error'])
        elif 'error' in b:
            row.update(status='does-not-compile', error=b['error'])
        else:
            fa, fb = a.get('functions', {}), b.get('functions', {})
            differ, moved_eh = [], []
            for k in sorted((set(fa) | set(fb)) - {'eh'}):
                if k in fb:
                    if fb[k][0] not in {fp[0] for fp in copies['base'].get(k, {}).values()}:
                        differ.append(k)
                elif k not in copies['head']:
                    differ.append(k)   # compiled at main in this unit, and in no unit of the change that lists it
                # a function given to another unit must not use EH code: build_and_match.py finds EH tails only
                # through the functions of the unit that lists them
                if set(copies['base'].get(k, {})) != set(copies['head'].get(k, {})) and \
                        any(fp[3] for side in copies.values() for fp in side.get(k, {}).values()):
                    moved_eh.append(k)
            # EH code the owner built against the game (tools/verified_eh.json) is accepted as it is
            eh_differs = e['base'] is not None and e['head'] is not None and fa.get('eh') != fb.get('eh') and \
                fb.get('eh') not in verified.get(e['source'], ())
            row.update(status='identical' if not differ and not moved_eh and not eh_differs else 'differs',
                       differ=differ, eh_differs=eh_differs, moved_eh=moved_eh,
                       same_bytes=[k for k in differ if k in fb and fb[k][1] in
                                   {fp[1] for fp in copies['base'].get(k, {}).values()}],
                       unbound=sorted({n for k in differ for n in fb.get(k, [0, 0, []])[2]})[:20])
        rows.append(row)
    return dict(shard=n, base=base_sha, head=head_sha, plan=plan_id(plan_data), units=rows)


def eh_changes(repo, base_sha, head_sha, jobs):
    """{source: EH digest} of every unit with EH tails whose EH code at head_sha differs from base_sha (or that is new),
    for tools/verified_eh.json. Only for a head_sha whose full build against the game matched every function and EH
    tail (build_and_match.py)."""
    repo = Path(repo).resolve()
    recipes = {sha: json.loads(subprocess.run(['git', '-C', str(repo), 'show', sha + ':' + RECIPE], check=True,
                                              capture_output=True, text=True).stdout)['units'] for sha in (base_sha, head_sha)}
    scratch = Path(tempfile.mkdtemp(prefix='fnv-compare-'))
    try:
        built = {sha: build_side(repo, sha, [i for i, u in enumerate(recipes[sha]) if u.get('eh_tails')], jobs, scratch)[0]
                 for sha in (base_sha, head_sha)}
    finally:
        shutil.rmtree(scratch, ignore_errors=True)
    digests = {}
    for sha in (base_sha, head_sha):
        for i, r in built[sha].items():
            if 'error' in r:
                raise SystemExit('%s does not build at %s' % (recipes[sha][i]['source'], sha))
            digests.setdefault(sha, {}).setdefault(recipes[sha][i]['source'], set()).add(r['functions']['eh'])
    return {s: sorted(d - digests[base_sha].get(s, set())) for s, d in digests[head_sha].items()
            if d - digests[base_sha].get(s, set())}


# -- report ----------------------------------------------------------------------------------------------------------

def plan_id(plan_data):
    return hashlib.sha256(json.dumps(plan_data, sort_keys=True).encode()).hexdigest()


def report(plan_data, results, shard=None):
    """The verdict on the results (of one shard, with shard=N). Results built for another plan, or from other commits,
    are not counted."""
    def own(res):
        return res.get('plan') == plan_id(plan_data) and \
            dict(base=res.get('base'), head=res.get('head')) == plan_data['commits']
    foreign = [res for res in results if not own(res)]
    rows = [r for res in results if own(res) for r in res['units']]
    expected = range(len(plan_data['units'])) if shard is None else plan_data['shards'][shard]
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
        lines.append('- Units whose entry changed in build/units.json: %d' % len(plan_data['renamed']))
    lines.append('- Units built and compared at both commits: %d of %d affected%s (%s)' % (
        len(built), len(expected), '' if shard is None else ' in shard %d of %d' % (shard + 1, len(plan_data['shards'])),
        ', '.join('%s %d' % (k, len(v)) for k, v in sorted(by.items())) or 'none'))
    lines.append('- Functions in those units: %d' % sum(r['functions'] for r in rows))
    if plan_data['problems']:
        lines += ['', '### Needs a maintainer', '',
                  'This check only vouches for changes to src/, include/, build/units.json within its rules (see '
                  'README.md, "Contributing") and Markdown files. Nothing was built:', '']
        lines += ['- %s' % p for p in plan_data['problems'][:50]]
    if missing:
        lines += ['', '### Not built', '', '%d affected units have no result (a build job failed).' % len(missing)]
    if foreign:
        lines += ['', '%d result files were built for another plan or other commits and are not counted.' % len(foreign)]
    for status, title in (('differs', 'Functions that compile differently'), ('does-not-compile', 'Does not compile'),
                          ('base-failed', 'main itself failed to build (a problem with the check, not the change)')):
        if by.get(status):
            lines += ['', '### %s' % title, '']
            for r in by[status][:40]:
                if status == 'differs':
                    what = ', '.join(r['differ'][:12]) + (' and %d more' % (len(r['differ']) - 12) if len(r['differ']) > 12 else '')
                    if r['eh_differs']:
                        what = (what + ', ' if what else '') + 'its EH tails'
                    if r.get('moved_eh'):
                        lines.append('- `%s`: these functions use EH code and moved to another unit; they have to stay in '
                                     'the unit that lists their EH tails: %s' % (r['source'], ', '.join(r['moved_eh'][:12])))
                        if not r['differ'] and not r['eh_differs']:
                            continue
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
    e = sub.add_parser('eh'); e.add_argument('repo'); e.add_argument('base_sha'); e.add_argument('head_sha')
    e.add_argument('--out', required=True); e.add_argument('--jobs', type=int, default=os.cpu_count() or 2)
    a = ap.parse_args()
    if a.command == 'eh':
        data = eh_changes(a.repo, a.base_sha, a.head_sha, a.jobs)
        Path(a.out).write_text(json.dumps(data, indent=1, sort_keys=True) + '\n')
        print('%d units whose EH code differs from the base' % len(data))
        return 0
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
