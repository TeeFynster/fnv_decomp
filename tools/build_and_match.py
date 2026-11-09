#!/usr/bin/env python3
"""Compile every unit of this source tree and compare each function with your own copy of the game.

usage: python3 tools/build_and_match.py --image <your FalloutNV executable> [--jobs N] [--only TEXT] [--every K]
                                        [--limit N] [--out results.json]

build/units.json lists every translation unit: its source file, the compiler and flags it is built with, and the
functions it must reproduce (original address, decorated symbol, size). Each unit is compiled with tools/msvc.py and
every listed function is compared byte for byte, relocations included, with the same function in the image you supply.
Data the unit defines itself and a function refers to is compared too: a floating-point or string literal must hold the
bytes the game holds where the original refers (literals are placed by their bytes, never by a binding in
build/units.json), and so must a global's initializer.

A unit's eh_tails are the exception-handling code its functions produce: the unwind funclets and the __ehhandler$ stub
that the compiler puts in a separate .text$x section and the linker places away from the function. Each such section
is located through the function that uses it (the handler address it pushes) and compared byte for byte, relocations
included; an EH tail matches when its parent matches and every byte of it, apart from trailing INT3 padding, lies in a
matching section. Unwinding may call a function the recipe names nowhere (the destructor of a helper type): that name
is bound to the address the original calls, and every other call through the same name, in any unit, must agree; the
summary counts the tails that needed such a binding.

The image must be the plain code of Fallout: New Vegas PC 1.4.0.525 from your own copy; it is checked first against a
few SHA-256 fingerprints (build/image_check.json) and nothing runs if it does not match. This tool never prints or
writes bytes of your image: results hold addresses, sizes and difference counts only. Keep your image, and any object
files you produce, private.

Exit code 0 when every listed function and EH tail matches, 1 when any does not, 3 when the image check fails.
"""
import argparse
from collections import Counter
from concurrent.futures import ThreadPoolExecutor
import hashlib
import json
import os
from pathlib import Path
import shutil
import struct
import subprocess
import sys
import tempfile

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / 'tools'))
from compare import Coff, LITERAL, Pe, compare, data_differs, own_data   # noqa: E402
from function_spans import FunctionSpans       # noqa: E402

NEED = 12   # reference functions that must match; leaves room for a few that differ between equivalent copies


def image_ok(pe):
    spec = json.loads((ROOT / 'build/image_check.json').read_text())
    ok = 0
    for address, size, digest in spec['probes']:
        try:
            ok += hashlib.sha256(pe.read(int(address, 16), size)).hexdigest() == digest
        except ValueError:
            pass
    return ok >= min(NEED, len(spec['probes'])), ok, len(spec['probes'])


def eh_sections(coff, pe, unit, rows, names):
    """Locate and compare the .text$x sections of the unit's functions. A section is placed by a relocation in a listed
    function that targets it (the parent pushing its __ehhandler$ address): the original's value there, minus the
    target's offset, is the section's address. Unwind funclets call functions the unit's own bindings may not name:
    those resolve through names (every name the recipe binds to exactly one address). A function named nowhere in the
    recipe (typically the destructor of a helper type that only unwinding calls) is bound to what the original calls,
    once: every other reference to that name must agree, here and in every other unit (checked in eh_tails).
    Returns [start, end, ok, parent, inferred names] per located section, the inferred {name: address} and the errors."""
    mappings = dict(names)
    mappings.update({k: int(v, 0) for k, v in unit.get('symbols', {}).items()})
    placements, anchors, errors = {}, {}, []
    for fn in unit['functions']:
        for name in [fn['symbol']] + fn.get('fold_aliases', []):
            mappings[name] = int(fn['address'], 16)
            s = coff.named(name)
            placements[(s['section'], s['value'])] = (int(fn['address'], 16), fn['size'])
    matched = {r['address'] for r in rows if r['verdict'] == 'match'}

    def is_tail(index):
        return index > 0 and coff.sections[index]['name'].startswith('.text$x')

    for fn in unit['functions']:
        s = coff.named(fn['symbol']); sec = coff.sections[s['section']]; start = s['value']
        address, size = int(fn['address'], 16), fn['size']
        original = pe.read(address, size)
        for offset, index, kind in sec['relocs']:
            target = coff.symbols[index]
            if not start <= offset < start + size - 3 or not is_tail(target['section']):
                continue
            rel = offset - start
            if kind == 0x06:
                at = struct.unpack_from('<I', original, rel)[0] - struct.unpack_from('<I', sec['data'], offset)[0]
            elif kind == 0x14:
                at = (address + rel + 4 + struct.unpack_from('<i', original, rel)[0]
                      - struct.unpack_from('<i', sec['data'], offset)[0])
            else:
                continue
            base = (at - target['value']) & 0xffffffff
            if anchors.setdefault(target['section'], (base, fn['address']))[0] != base:
                errors.append('%s places %s at two addresses' % (fn['address'], target['name']))
    data_bases = {}

    def resolve(target, addend):
        if target['name'] in mappings:
            return mappings[target['name']] + addend
        if target['section'] in anchors:
            return anchors[target['section']][0] + target['value'] + addend
        for (section, value), (address, size) in placements.items():
            if section == target['section'] and value <= target['value'] + addend < value + size:
                return address + target['value'] + addend - value
        if target['section'] == -1:
            return target['value'] + addend
        return None

    out, inferred = [], {}
    xdata = {i for i in range(1, len(coff.sections)) if coff.sections[i]['name'].startswith('.xdata')}
    for index, (base, parent) in sorted(anchors.items()):
        sec = coff.sections[index]; data = sec['data']
        cuts = sorted({0, len(data)} | {x['value'] for x in coff.symbols.values() if x['section'] == index and 0 < x['value'] < len(data)})
        pieces = [(a, b) for a, b in zip(cuts, cuts[1:]) if b > a]
        # the EH tables: located by the anchor-placed pieces' references to them (the handler stub's __ehfuncinfo$)
        for offset, ti, kind in sec['relocs']:
            t = coff.symbols[ti]
            if kind != 0x06 or t['section'] not in xdata: continue
            try: observed, = struct.unpack_from('<I', pe.read(base + offset, 4))
            except ValueError: continue
            addend, = struct.unpack_from('<I', data, offset)
            data_bases.setdefault(t['section'], (observed - t['value'] - addend) & 0xffffffff)
        where = {}   # piece offset -> its address in the original, as the original's EH tables give it
        for xi in sorted(xdata):
            if xi not in data_bases: continue
            xd = coff.sections[xi]['data']
            for offset, ti, kind in coff.sections[xi]['relocs']:
                t = coff.symbols[ti]
                if t['section'] != index or kind != 0x06: continue
                addend, = struct.unpack_from('<I', xd, offset)
                try: at, = struct.unpack_from('<I', pe.read(data_bases[xi] + offset, 4))
                except ValueError: continue
                where.setdefault(t['value'] + addend, at)
        for s0, s1 in pieces:
            at = where.get(s0, base + s0)
            try:
                original = pe.read(at, s1 - s0)
            except ValueError:
                out.append([at, at + s1 - s0, False, parent, []]); errors.append('%s: tail outside the image' % parent)
                continue
            mask, ok, guessed = set(), parent in matched, set()
            for offset, ti, kind in sec['relocs']:
                if not s0 <= offset < s1: continue
                target = coff.symbols[ti]; rel = offset - s0; mask.update(range(rel, rel + 4))
                if kind == 0x06:
                    addend, = struct.unpack_from('<I', data, offset); observed, = struct.unpack_from('<I', original, rel)
                elif kind == 0x14:
                    addend, = struct.unpack_from('<i', data, offset)
                    observed = (at + rel + 4 + struct.unpack_from('<i', original, rel)[0]) & 0xffffffff
                else:
                    ok = False; errors.append('%s: relocation kind %d in a tail' % (parent, kind)); continue
                own = own_data(coff, target) if LITERAL.match(target['name']) else None
                if target['section'] == index:   # a jump to another piece of the same tail
                    tv = target['value'] + (addend if kind == 0x06 else 0)
                    expected = where.get(tv, base + tv) + (0 if kind == 0x06 else addend)
                elif own is not None:   # a literal: placed by its bytes, as in compare.py
                    expected = observed if data_differs(pe, own, (observed - addend) & 0xffffffff) == [] else None
                else:
                    expected = resolve(target, addend)
                if own is not None:
                    pass
                elif expected is None and target['section'] > 0:
                    at_ = (observed - target['value'] - addend) & 0xffffffff
                    expected = observed if data_bases.setdefault(target['section'], at_) == at_ else None
                elif expected is None and target['section'] == 0 and kind == 0x14:
                    expected = inferred.setdefault(target['name'], (observed - addend) & 0xffffffff) + addend
                    guessed.add(target['name'])
                if expected is None or expected & 0xffffffff != observed:
                    ok = False
                    errors.append('%s: tail relocation to %s differs' % (parent, target['name']))
            piece = data[s0:s1]
            if any(piece[i] != original[i] for i in range(len(piece)) if i not in mask):
                ok = False
            out.append([at, at + s1 - s0, ok, parent, sorted(guessed)])
    return out, inferred, errors


def recipe_names(units):
    """Every symbol name the recipe binds to exactly one address, across all units."""
    seen = {}
    for u in units:
        pairs = [(k, int(v, 0)) for k, v in u.get('symbols', {}).items()]
        pairs += [(n, int(fn['address'], 16)) for fn in u['functions'] for n in [fn['symbol']] + fn.get('fold_aliases', [])]
        for k, v in pairs:
            seen.setdefault(k, set()).add(v)
    return {k: next(iter(v)) for k, v in seen.items() if len(v) == 1}


def check_unit(unit, pe, spans, scratch, names):
    work = Path(tempfile.mkdtemp(dir=scratch))
    obj = work / 'unit.obj'
    try:
        r = subprocess.run([sys.executable, str(ROOT / 'tools/msvc.py'), '--compiler', unit['compiler'], '/c', '/nologo']
                           + unit['flags'] + ['/I' + str(ROOT / 'include'), str(ROOT / unit['source']), '/Fo' + str(obj)],
                           cwd=ROOT, capture_output=True, text=True, errors='replace')
        size = sum(f['size'] for f in unit['functions'])
        base = dict(source=unit['source'], functions=len(unit['functions']), bytes=size)
        if r.returncode or not obj.exists():
            return dict(base, status='compile-failed', error=r.stdout[-400:])
        manifest = dict(symbols=unit.get('symbols', {}), functions=unit['functions'],
                        literal_symbols=unit.get('literal_symbols', []))
        try:
            coff = Coff(obj)
            rows = compare(coff, pe, manifest, spans, data_names=names)
        except Exception as e:   # a missing symbol, a span that disagrees: report it, keep going
            return dict(base, status='compare-error', error=str(e)[:300])
        bad = [dict(address=x['address'], size=x['size'], differing_bytes=len(x['byte_differences']),
                    errors=x['errors'][:2]) for x in rows if x['verdict'] != 'match']
        matched = [x for x in rows if x['verdict'] == 'match']
        result = dict(base, status='ok' if not bad else 'mismatch', matched_functions=len(matched),
                      matched_bytes=sum(x['size'] for x in matched), mismatches=bad,
                      data_warnings=sorted({w for x in rows for w in x.get('warnings', [])}))
        if unit.get('eh_tails'):
            try:
                sections, inferred, errors = eh_sections(coff, pe, unit, rows, names)
            except Exception as e:
                sections, inferred, errors = [], {}, ['EH tails: %s' % str(e)[:200]]
            result.update(eh_sections=sections, eh_inferred={k: '0x%08x' % v for k, v in inferred.items()},
                          eh_errors=errors[:5])
        return result
    finally:
        shutil.rmtree(work, ignore_errors=True)


def eh_tails(units, done, pe):
    """Every listed EH tail ({address: size}), those that do not match, and those that match only through a binding
    inferred from the original. A tail matches when each of its bytes, apart from INT3 padding outside every section,
    lies in a located .text$x section that matched (in any unit). An inferred name bound to two addresses (in two
    units) fails every section that used it."""
    tails = {}
    for u in units:
        for x in u.get('eh_tails', []):
            tails[int(x['address'], 16)] = x['size']
    seen = {}
    for r in done:
        for k, v in r.get('eh_inferred', {}).items():
            seen.setdefault(k, set()).add(v)
    conflict = {k for k, v in seen.items() if len(v) > 1}
    good, failed, guessed = set(), set(), set()   # addresses inside located sections: matched / not / matched by inference
    for r in done:
        for start, end, ok, _, names in r.get('eh_sections', []):
            ok = ok and not conflict & set(names)
            (good if ok else failed).update(range(start, end))
            if ok and names:
                guessed.update(range(start, end))
    bad, inferred = {}, {}
    for t, n in tails.items():
        original = pe.read(t, n)
        if t not in good or any(t + i not in good and (original[i] != 0xcc or t + i in failed) for i in range(n)):
            bad['0x%08x' % t] = n
        elif any(t + i in guessed for i in range(n)):
            inferred['0x%08x' % t] = n
    return tails, bad, inferred, len(seen), len(conflict)


def main():
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument('--image', default=os.environ.get('FNV_IMAGE'), help='your executable image (or set FNV_IMAGE)')
    p.add_argument('--jobs', type=int, default=max(1, (os.cpu_count() or 2) // 2))
    p.add_argument('--only', help='only units whose source path contains this text')
    p.add_argument('--limit', type=int, help='only the first N units (after --only)')
    p.add_argument('--every', type=int, help='a quick spot check: only every K-th unit')
    p.add_argument('--out', help='write the per-unit results here (JSON; addresses and counts only)')
    a = p.parse_args()
    if not a.image:
        p.error('--image is required (or set FNV_IMAGE)')
    pe = Pe(Path(a.image))
    ok, hits, total = image_ok(pe)
    if not ok:
        print('IMAGE CHECK FAILED: %s is not the plain code of Fallout: New Vegas PC 1.4.0.525 (%d of %d reference '
              'functions match). See README.md, "What you need".' % (a.image, hits, total))
        return 3
    index = ROOT / 'build/function_index.json'
    spans = FunctionSpans.from_index(pe, index) if index.exists() else None
    units = json.loads((ROOT / 'build/units.json').read_text())['units']
    names = recipe_names(units)
    if a.only:
        units = [u for u in units if a.only in u['source']]
    if a.every:
        units = units[::a.every]
    if a.limit:
        units = units[:a.limit]
    scratch = tempfile.mkdtemp(prefix='fnv_build_')
    try:
        done = []
        with ThreadPoolExecutor(a.jobs) as pool:
            for n, result in enumerate(pool.map(lambda u: check_unit(u, pe, spans, scratch, names), units), 1):
                done.append(result)
                if result['status'] != 'ok':
                    print('%-15s %s' % (result['status'].upper(), result['source']), flush=True)
                if n % 100 == 0:
                    print('... %d of %d units' % (n, len(units)), flush=True)
    finally:
        shutil.rmtree(scratch, ignore_errors=True)
    functions = sum(r['functions'] for r in done)
    size = sum(r['bytes'] for r in done)
    matched_f = sum(r.get('matched_functions', 0) for r in done)
    matched_b = sum(r.get('matched_bytes', 0) for r in done)
    tails, tail_bad, tail_inferred, n_inferred, n_conflict = eh_tails(units, done, pe)
    summary = dict(units=len(done), status=dict(Counter(r['status'] for r in done)),
                   functions=functions, matched_functions=matched_f, bytes=size, matched_bytes=matched_b,
                   eh_tails=len(tails), matched_eh_tails=len(tails) - len(tail_bad),
                   eh_tail_bytes=sum(tails.values()), matched_eh_tail_bytes=sum(tails.values()) - sum(tail_bad.values()),
                   eh_tail_mismatches=sorted(tail_bad), eh_tails_by_inferred_binding=len(tail_inferred),
                   eh_inferred_names=n_inferred, eh_inferred_conflicts=n_conflict,
                   data_warnings=sum(len(r.get('data_warnings', [])) for r in done))
    if a.out:
        Path(a.out).write_text(json.dumps(dict(summary=summary, units=done), indent=1) + '\n')
    print('%d units: %s' % (len(done), ', '.join('%s %d' % kv for kv in sorted(summary['status'].items()))))
    print('functions matched: %d of %d; bytes matched: %d of %d' % (matched_f, functions, matched_b, size))
    if tails:
        print('EH tails matched: %d of %d; bytes %d of %d (%d through %d names bound from the original, %d conflicting)'
              % (summary['matched_eh_tails'], len(tails), summary['matched_eh_tail_bytes'], sum(tails.values()),
                 len(tail_inferred), n_inferred, n_conflict))
    if summary['data_warnings']:
        print('RTTI type descriptors whose name differs from the game (a class written as a struct, or another '
              'namespace; not counted as mismatches yet): %d' % summary['data_warnings'])
    return 0 if matched_f == functions and not tail_bad else 1


if __name__ == '__main__':
    raise SystemExit(main())
