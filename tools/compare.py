#!/usr/bin/env python3
import re
"""Compare x86 COFF functions to the user's PE, including relocation targets.

Manifest: {"symbols": {"decorated": "0xaddress"}, "functions": [
 {"address": "0x004739b0", "symbol": "?name@@...", "size": 93,
  "fold_aliases": ["other decorated name"]}]}.
A folded alias may share a section/offset and original address; it never
licenses a call to a different original address. Reports may contain bytes
of your executable: keep them private and never commit them.
"""
import argparse
import json
import struct
from pathlib import Path
from function_spans import FunctionSpans, SIZE_BASIS


def number(value):
    return int(value, 0) if isinstance(value, str) else value


class Coff:
    def __init__(self, path):
        self.data = Path(path).read_bytes()
        machine, count, _, symptr, symcount, opts, _ = struct.unpack_from('<HHIIIHH', self.data)
        if machine != 0x14c or opts:
            raise ValueError('expected i386 COFF object, not an executable or bigobj')
        self.sections = [None]
        for i in range(count):
            row = struct.unpack_from('<8sIIIIIIHHI', self.data, 20 + i * 40)
            name, _, _, length, raw, relptr, _, relcount, _, flags = row
            if flags & 0x1000000:
                raise ValueError('extended COFF relocation counts are unsupported')
            self.sections.append(dict(name=name.rstrip(b'\0').decode(),
                data=bytes(length) if raw == 0 and flags & 0x80 else self.data[raw:raw + length], flags=flags,
                relocs=[struct.unpack_from('<IIH', self.data, relptr + n * 10)
                        for n in range(relcount)]))
        strptr = symptr + symcount * 18
        strlen, = struct.unpack_from('<I', self.data, strptr)
        strings = self.data[strptr:strptr + strlen]
        self.symbols = {}
        self.by_name = {}
        i = 0
        while i < symcount:
            rawname, value, section, typ, storage, aux = struct.unpack_from('<8sIhHBB', self.data, symptr + i * 18)
            if rawname[:4] == b'\0' * 4:
                offset, = struct.unpack_from('<I', rawname, 4)
                name = strings[offset:].split(b'\0', 1)[0].decode()
            else:
                name = rawname.rstrip(b'\0').decode()
            symbol = dict(name=name, value=value, section=section, type=typ, storage=storage)
            self.symbols[i] = symbol
            self.by_name.setdefault(name, []).append(symbol)
            i += 1 + aux

    def named(self, name):
        candidates = [s for s in self.by_name.get(name, []) if s['section'] > 0]
        if len(candidates) != 1:
            raise ValueError('expected one defined symbol: ' + name)
        return candidates[0]


class Pe:
    def __init__(self, path):
        self.data = Path(path).read_bytes()
        pe, = struct.unpack_from('<I', self.data, 0x3c)
        if self.data[pe:pe+4] != b'PE\0\0':
            raise ValueError('expected PE executable')
        machine, count, _, _, _, opts, _ = struct.unpack_from('<HHIIIHH', self.data, pe+4)
        if machine != 0x14c:
            raise ValueError('expected i386 executable')
        optional = pe + 24
        magic, = struct.unpack_from('<H', self.data, optional)
        if magic != 0x10b:
            raise ValueError('expected PE32')
        self.base, = struct.unpack_from('<I', self.data, optional+28)
        self.sections = []
        self.names = []
        for i in range(count):
            name, virtual_size, rva, raw_size, raw, _, _, _, _, _ = struct.unpack_from('<8sIIIIIIHHI', self.data, optional+opts+i*40)
            self.sections.append((rva, virtual_size, raw_size, raw))
            self.names.append(name.rstrip(b'\0').decode(errors='replace'))

    def tls_start(self):
        """Virtual address of the .tls section (the TLS template), or None."""
        for (rva, _, _, _), name in zip(self.sections, self.names):
            if name == '.tls':
                return self.base + rva
        return None

    def secrel(self, address):
        """Section-relative offset of a thread-local variable (IMAGE_REL_I386_SECREL). Only .tls targets are accepted:
        in code, SECREL appears only in thread-local accesses (mov reg, [tls block + SECREL(var)])."""
        start = self.tls_start()
        for (rva, virtual_size, _, _), name in zip(self.sections, self.names):
            if self.base + rva <= address < self.base + rva + max(virtual_size, 1):
                if name != '.tls':
                    raise ValueError('SECREL target is not thread-local (section %s)' % name)
                return address - start
        raise ValueError('SECREL target outside the image')

    def read(self, address, size):
        rva = address - self.base
        for start, _, rawsize, offset in self.sections:
            if start <= rva and rva + size <= start + rawsize:
                return self.data[offset+rva-start:offset+rva-start+size]
        raise ValueError('original range not backed by PE file bytes')

    def read_data(self, address, size):
        """Initialized image data, including the loader's zero-filled part of a section.

        Code comparisons deliberately keep using read(): virtual zero-fill is not evidence for code bytes.
        """
        if size < 0:
            raise ValueError('negative data range')
        rva = address - self.base
        for start, virtual_size, rawsize, offset in self.sections:
            if start <= rva and rva + size <= start + max(virtual_size, rawsize):
                relative = rva - start
                backed = max(0, min(size, rawsize - relative))
                data = self.data[offset + relative:offset + relative + backed]
                if len(data) != backed:
                    raise ValueError('truncated original data range')
                return data + bytes(size - backed)
        raise ValueError('original data range outside image sections')


# Literals: floating-point constants (__real@, __xmm@: the name spells the bytes) and string literals (??_C@, $SG).
LITERAL = re.compile(r'^(\$SG\d+$|\?\?_C@|__real@[0-9a-f]+$|__xmm@[0-9a-f]+$)')
# RTTI type descriptors: a class written as a struct (or in another namespace) changes only their name
RTTI_NAME = re.compile(r'^\?\?_R0')


def data_definition(coff, symbol):
    """A data symbol's (raw bytes, relocations), or None for code or an external.

    Relocations are (offset within these bytes, kind, target symbol); their addends remain in the raw bytes.
    Generic data conservatively extends to the next symbol or section end. COFF does not record every variable's
    size, so those bytes can include alignment padding; discarding zeros would also discard real initializer bytes.
    BSS is a definition with zero bytes, not an external without an initializer. MSVC string symbols encode their
    byte length, including embedded NULs and the terminator. Older $SG labels use their complete symbol extent.
    """
    name = symbol['name']
    if name.startswith(('__real@', '__xmm@')):
        return bytes.fromhex(name.split('@', 1)[1])[::-1], []
    if symbol['section'] <= 0:
        return None
    sec = coff.sections[symbol['section']]
    if sec['flags'] & 0x20000020:   # code
        return None
    start = symbol['value']
    starts = coff.__dict__.setdefault('_starts', {})
    if symbol['section'] not in starts:
        starts[symbol['section']] = sorted({s['value'] for s in coff.symbols.values() if s['section'] == symbol['section']})
    later = [v for v in starts[symbol['section']] if v > start]
    end = later[0] if later else len(sec['data'])
    length = re.match(r'^\?\?_C@_[01]([0-9]|[A-P]+@)', name)
    if length:
        encoded = length[1]
        size = int(encoded) + 1 if encoded.isdigit() else int(''.join('%x' % (ord(c) - ord('A'))
                                                                                  for c in encoded[:-1]), 16)
        end = start + size
    if not 0 <= start <= end <= len(sec['data']):
        raise ValueError('data definition outside its object section: ' + name)
    relocs = []
    previous_end = 0
    for offset, index, kind in sorted(sec['relocs']):
        if offset < 0 or offset + 4 > len(sec['data']):
            raise ValueError('relocation outside data section: ' + name)
        if offset < end and offset + 4 > start:
            relative = offset - start
            if relative < 0 or relative + 4 > end - start:
                raise ValueError('relocation crosses data definition boundary: ' + name)
            if relative < previous_end:
                raise ValueError('overlapping data relocations: ' + name)
            if kind not in (0x06, 0x07, 0x0B, 0x14):
                raise ValueError('unsupported initializer relocation kind %d: %s' % (kind, name))
            previous_end = relative + 4
            relocs.append((relative, kind, coff.symbols[index]))
    if LITERAL.match(name) and relocs:
        raise ValueError('literal contains initializer relocations: ' + name)
    return sec['data'][start:end], relocs


def own_data(coff, symbol):
    """Compatibility view: (bytes with relocated fields zeroed, masked offsets).

    Consumers validating addresses or computing fingerprints must also account for data_definition's relocations.
    """
    definition = data_definition(coff, symbol)
    if definition is None:
        return None
    data, relocs = definition
    mask = {o + i for o, _, _ in relocs for i in range(4)}
    return bytes(0 if i in mask else b for i, b in enumerate(data)), mask


def data_differs(pe, own, at):
    """Bytes of `own` (from own_data) that the game does not hold at `at`; None when the range is not in the file."""
    data, mask = own
    try:
        original = getattr(pe, 'read_data', pe.read)(at, len(data))
    except ValueError:
        return None
    return [i for i in range(len(data)) if i not in mask and data[i] != original[i]]


def check_data(coff, pe, symbol, at, resolve, seen=None, depth=0):
    """Check owned data and its relocation graph; return (errors, RTTI-name warnings).

    resolve(target, addend) has the same contract as compare's relocation resolver. Only literals may be placed by
    their observed bytes: an unknown ordinary initializer target cannot silently become an inferred address.
    Cycles terminate after checking each (object definition, image address) once.
    """
    seen = set() if seen is None else seen
    key = (symbol['section'], symbol['value'], symbol['name'], at)
    if key in seen:
        return [], []
    if depth >= 128 or len(seen) >= 10000:
        return ['data relocation graph exceeds the verification limit'], []
    seen.add(key)
    definition = data_definition(coff, symbol)
    if definition is None:
        return [], []
    data, relocs = definition
    errors, warnings = [], []
    try:
        original = getattr(pe, 'read_data', pe.read)(at, len(data))
    except ValueError as error:
        return ['data %s at 0x%08x: %s' % (symbol['name'], at, error)], []
    mask = {offset + i for offset, _, _ in relocs for i in range(4)}
    if len(original) != len(data):
        return ['data %s at 0x%08x: truncated original data range' % (symbol['name'], at)], []
    bad = [i for i in range(len(data)) if i not in mask and data[i] != original[i]]
    if bad:
        message = 'data %s at 0x%08x: the game holds other bytes there (%d of %d bytes differ)' % (
            symbol['name'], at, len(bad), len(data))
        # Only the type-name payload has the existing warning exception; corrupt pointer/header fields are errors.
        (warnings if RTTI_NAME.match(symbol['name']) and all(i >= 8 for i in bad) else errors).append(message)
    for offset, kind, target in relocs:
        try:
            addend = struct.unpack_from('<i' if kind == 0x14 else '<I', data, offset)[0]
            observed = struct.unpack_from('<I', original, offset)[0]
            if kind == 0x14:
                observed = (at + offset + 4 + struct.unpack_from('<i', original, offset)[0]) & 0xffffffff
            elif kind == 0x07:
                observed = (observed + pe.base) & 0xffffffff
            elif kind not in (0x06, 0x0B):
                raise ValueError('unsupported initializer relocation kind %d' % kind)
            child = data_definition(coff, target)
            by_content = child is not None and LITERAL.match(target['name']) is not None
            if kind == 0x0B:
                target_at = resolve(target, 0)
                if target_at is None:
                    raise ValueError('unresolved initializer target: ' + target['name'])
                expected = pe.secrel(target_at + addend)
            elif by_content:
                expected = observed
                target_at = (observed - addend) & 0xffffffff
            else:
                expected = resolve(target, addend)
                if expected is None:
                    raise ValueError('unresolved initializer target: ' + target['name'])
                target_at = (expected - addend) & 0xffffffff
            if expected & 0xffffffff != observed:
                raise ValueError('initializer target %s differs: yours resolves to 0x%08x, original 0x%08x' % (
                    target['name'], expected & 0xffffffff, observed))
            if child is not None:
                more, notes = check_data(coff, pe, target, target_at, resolve, seen, depth + 1)
                errors.extend(more); warnings.extend(notes)
        except (ValueError, KeyError, struct.error) as error:
            errors.append('data %s at +0x%x: %s' % (symbol['name'], offset, error))
    return errors, warnings


def compare(coff, pe, manifest, spans=None, data_names=None):
    if spans is not None:
        for spec in manifest['functions']:
            canonical = spans.size(number(spec['address']))
            if number(spec['size']) != canonical:
                raise ValueError('Manifest span differs from canonical span at %s: %s vs %s' %
                                 (spec['address'], spec['size'], canonical))
    mappings = {k: number(v) for k, v in manifest.get('symbols', {}).items()}
    placements = {}
    functions = manifest['functions']
    for spec in functions:
        address = number(spec['address'])
        for name in [spec['symbol']] + spec.get('fold_aliases', []):
            if name in mappings and mappings[name] != address:
                raise ValueError('conflicting fold address for ' + name)
            mappings[name] = address
            symbol = coff.named(name)
            key = (symbol['section'], symbol['value'])
            if key in placements and placements[key] != (address, number(spec['size'])):
                raise ValueError('one object entry mapped to different original addresses')
            placements[key] = (address, number(spec['size']))

    def resolve(symbol, addend):
        if symbol['name'] in mappings:
            return mappings[symbol['name']] + addend
        if symbol['section'] > 0:
            # Section/local-label relocations resolve only inside a known
            # annotated function extent, never by unbounded nearest entry.
            point = symbol['value'] + addend
            candidates = [(value, address) for (section, value), (address, size) in placements.items()
                          if section == symbol['section'] and value <= point < value + size]
            if len(candidates) == 1:
                value, address = candidates[0]
                return address + point - value
        if symbol['section'] == -1:
            return symbol['value'] + addend
        raise ValueError('unresolved original symbol: ' + symbol['name'])

    def resolve_data(symbol, addend):
        # Initializer graphs can refer to a canonical symbol bound by another unit. These names must come from
        # the recipe's globally unambiguous bindings; local bindings and annotated placements retain precedence.
        try:
            return resolve(symbol, addend)
        except ValueError:
            if data_names is not None and symbol['name'] in data_names:
                return number(data_names[symbol['name']]) + addend
            raise

    reports = []
    for spec in functions:
        address, size = number(spec['address']), number(spec['size'])
        symbol = coff.named(spec['symbol'])
        section = coff.sections[symbol['section']]
        start = symbol['value']
        compiled = section['data'][start:start+size]
        original = pe.read(address, size)
        errors, relocation_reports, mask, warnings = [], [], set(), []
        # /Gy gives each function its own code COMDAT. For other objects, bound
        # it by the next function or section end, so trailing bytes cannot pass.
        # Catch funclets (__catch$...) sit inside the original function's span: they do not end the function.
        next_entries = [s['value'] for s in coff.symbols.values()
                        if s['section'] == symbol['section'] and s['type'] & 0x20
                        and s['value'] > start and not s['name'].startswith('__catch$')]
        end = min(next_entries) if next_entries else len(section['data'])
        actual_size = end - start
        # Compiler/linker INT3 padding is outside the annotated function.
        tail = section['data'][start+size:end]
        if actual_size < size or any(b not in (0xcc, 0x90) for b in tail):
            errors.append('compiled function extent differs: %d vs %d' % (actual_size, size))
        for offset, index, kind in section['relocs']:
            if not start <= offset < start+size:
                continue
            relative = offset-start
            record = dict(offset=relative, kind=kind)
            relocation_reports.append(record)
            try:
                if relative+4 > size:
                    raise ValueError('relocation crosses function end')
                target_symbol = coff.symbols[index]
                name = target_symbol['name']
                record['symbol'] = name
                own = own_data(coff, target_symbol)
                # A literal is placed by its bytes, never by a binding: the game keeps a copy of each value somewhere,
                # and which copy is the linker's choice. Its bytes must be what the game holds where the original
                # refers, so a literal written with another value never matches, whatever build/units.json says.
                by_content = own is not None and LITERAL.match(name) is not None
                addend, = struct.unpack_from('<I', compiled, relative)
                if kind == 0x14: # IMAGE_REL_I386_REL32
                    used, = struct.unpack_from('<i', compiled, relative)
                    displacement, = struct.unpack_from('<i', original, relative)
                    observed = (address + relative + 4 + displacement) & 0xffffffff
                elif kind == 0x06: # IMAGE_REL_I386_DIR32
                    used = addend
                    observed, = struct.unpack_from('<I', original, relative)
                elif kind == 0x07: # IMAGE_REL_I386_DIR32NB
                    used = addend
                    observed = (struct.unpack_from('<I', original, relative)[0] + pe.base) & 0xffffffff
                elif kind == 0x0B: # IMAGE_REL_I386_SECREL: thread-local variable offset inside .tls
                    used = addend
                    observed, = struct.unpack_from('<I', original, relative)
                else:
                    raise ValueError('unsupported relocation kind %d' % kind)
                if kind == 0x0B:
                    expected = pe.secrel(resolve(target_symbol, addend)) & 0xffffffff
                elif by_content:
                    expected = observed
                    record['by_content'] = True
                else:
                    expected = resolve(target_symbol, used) & 0xffffffff
                record.update(expected='0x%08x' % expected, observed='0x%08x' % observed)
                if expected != observed:
                    raise ValueError('original relocation target differs at +0x%x (%s): yours resolves to 0x%08x, original 0x%08x'
                                     % (relative, target_symbol['name'], expected, observed))
                if own is not None:
                    # data the unit defines itself (a literal, a global's initializer, an RTTI descriptor): the game
                    # must hold the same bytes where the original refers
                    at = ((pe.tls_start() if kind == 0x0B else 0) + observed - used) & 0xffffffff
                    bad, notes = check_data(coff, pe, target_symbol, at, resolve_data)
                    warnings.extend(notes)
                    if bad:
                        raise ValueError('; '.join(bad))
                mask.update(range(relative, relative+4))
                record['match'] = True
            except (ValueError, KeyError, struct.error) as error:
                record['match'] = False
                record['error'] = str(error)
                errors.append(str(error))
        diffs = [dict(offset=i, compiled=compiled[i], original=original[i])
                 for i in range(min(len(compiled), size))
                 if i not in mask and compiled[i] != original[i]]
        if len(compiled) != size:
            errors.append('compiled section shorter than original function')
        reports.append(dict(address='0x%08x' % address, symbol=spec['symbol'],
            size=size, compiled_extent=actual_size, verdict='match' if not errors and not diffs else 'wip',
            errors=errors, byte_differences=diffs, relocations=relocation_reports,
            fold_aliases=spec.get('fold_aliases', []), warnings=warnings))
    return reports


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--obj', required=True)
    parser.add_argument('--exe', required=True)
    parser.add_argument('--manifest', required=True)
    parser.add_argument('--report')
    parser.add_argument('--function-index', default=None,
                        help='address-sorted original entries used to enforce charter 3.2 spans')
    parser.add_argument('--summary', action='store_true', help='omit byte values; safe to retain in git')
    args = parser.parse_args()
    pe = Pe(args.exe)
    spans = FunctionSpans.from_index(pe, args.function_index) if args.function_index else None
    reports = compare(Coff(args.obj), pe, json.loads(Path(args.manifest).read_text()), spans)
    if args.summary:
        for report in reports:
            report['mismatch_offsets'] = [d['offset'] for d in report.pop('byte_differences')]
    output = json.dumps({'size_basis': SIZE_BASIS, 'functions': reports}, indent=2) + '\n'
    if args.report:
        Path(args.report).write_text(output)
    print(output, end='')
    return 0 if all(r['verdict'] == 'match' for r in reports) else 1


if __name__ == '__main__':
    raise SystemExit(main())
