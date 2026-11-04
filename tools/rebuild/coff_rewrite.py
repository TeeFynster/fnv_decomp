"""Rename one external definition in a private copy of a standard i386 COFF object.

No provider selection, aliasing, section extraction, linking or ABI conversion.
"""
from __future__ import annotations

import argparse
import copy
import hashlib
import json
from pathlib import Path
import re
import struct
import tempfile

from coff_inventory import Coff, CoffError, symbol_kind


def digest(data):
    return hashlib.sha256(data).hexdigest()


def hash_value(value):
    return isinstance(value, str) and re.fullmatch('[0-9a-f]{64}', value) is not None


def strict_object(path):
    """Reject unsupported/overlapping layouts before permitting a byte edit."""
    coff = Coff(path)
    data = coff.data
    _, count, _, symptr, symcount, _, _ = struct.unpack_from('<HHIIIHH', data)
    if not count or not symptr or not symcount:
        raise CoffError('section and symbol tables are required')
    strptr = symptr + 18 * symcount
    strlen, = struct.unpack_from('<I', data, strptr)
    if strptr + strlen != len(data):
        raise CoffError('trailing data after string table is unsupported')
    regions = [(0, 20 + count * 40), (symptr, strptr), (strptr, len(data))]
    for i in range(count):
        row = struct.unpack_from('<8sIIIIIIHHI', data, 20 + i * 40)
        _, _, _, size, raw, relptr, lineptr, relcount, linecount, flags = row
        if flags & 0x1000000:
            raise CoffError('extended relocation tables are unsupported')
        if size and not raw and not flags & 0x80:
            raise CoffError('initialized section has no payload')
        for offset, length in [(raw, size if raw else 0),
                               (relptr, relcount * 10), (lineptr, linecount * 6)]:
            if length:
                if not offset:
                    raise CoffError('table has no file offset')
                coff.take(offset, length)
                regions.append((offset, offset + length))
        sec = coff.sections[i + 1]
        if sec['selection'] == 'associative' and not 1 <= sec['association'] <= count:
            raise CoffError('invalid associative COMDAT target')
        for offset, _, typ in sec['relocs']:
            # This writer supports known standard x86 relocation records only.
            widths = {0: 0, 1: 2, 2: 2, 6: 4, 7: 4, 9: 2, 10: 2,
                      11: 4, 12: 4, 13: 1, 20: 4}
            if typ not in widths or offset + widths[typ] > size:
                raise CoffError('unsupported or out-of-bounds relocation')
    regions.sort()
    if any(left[1] > right[0] for left, right in zip(regions, regions[1:])):
        raise CoffError('overlapping COFF tables or section payloads')
    for symbol in coff.symbols.values():
        aux = symbol['aux_count']
        if not aux:
            continue
        if 'section_aux' in symbol:
            if aux != 1 or symbol['name'] != coff.sections[symbol['section']]['name']:
                raise CoffError('malformed section auxiliary record')
            sec = coff.sections[symbol['section']]
            if sec['selection'].startswith('unknown_') or symbol['section_aux']['length'] != sec['size']:
                raise CoffError('malformed section auxiliary metadata')
        elif 'weak' in symbol:
            if symbol['weak']['search'] not in (1, 2, 3):
                raise CoffError('unsupported weak external search policy')
        elif symbol['storage'] == 103 and symbol['section'] == -2:
            pass  # Standard FILE auxiliary filename records, preserved verbatim.
        else:
            raise CoffError('unsupported auxiliary record layout')
    return coff, symptr, strptr, strlen


def rename_bytes(path, expected_sha256, old_name, new_name):
    if not hash_value(expected_sha256):
        raise ValueError('expected input SHA-256 must be lowercase hexadecimal')
    for name in (old_name, new_name):
        if not isinstance(name, str) or not name or any(ord(c) < 33 or ord(c) > 126 for c in name):
            raise ValueError('symbol names must be nonempty printable ASCII without whitespace')
        if name.startswith(('__imp_', '_imp__')):
            raise ValueError('import-pointer identities are outside this definition-only writer')
    if old_name == new_name:
        raise ValueError('old and new names must differ')
    coff, symptr, strptr, strlen = strict_object(path)
    if digest(coff.data) != expected_sha256:
        raise ValueError('input object fingerprint mismatch')
    matches = [s for s in coff.symbols.values() if s['name'] == old_name]
    if len(matches) != 1 or symbol_kind(matches[0]) != 'external_definition':
        raise ValueError('old name must identify exactly one section-defined external symbol')
    if any(s['name'] == new_name for s in coff.symbols.values()):
        raise ValueError('new name collides with an existing symbol')
    symbol = matches[0]
    addition = new_name.encode('ascii') + b'\0'
    if strlen + len(addition) > 0xffffffff:
        raise ValueError('string table would overflow')
    result = bytearray(coff.data)
    name_offset = symptr + symbol['index'] * 18
    result[name_offset:name_offset + 8] = struct.pack('<II', 0, strlen)
    struct.pack_into('<I', result, strptr, strlen + len(addition))
    result.extend(addition)
    return bytes(result), dict(symbol_index=symbol['index'], section=symbol['section'],
        value=symbol['value'], type=symbol['type'], storage=symbol['storage'],
        name_field_offset=name_offset, string_table_offset=strptr,
        original_string_table_size=strlen)


def rewrite(input_path, output_path, receipt_path, provenance_path, expected_sha256, old_name, new_name):
    paths = [Path(p).resolve() for p in (input_path, output_path, receipt_path, provenance_path)]
    source_input, output, receipt, provenance_file = paths
    if len(set(paths)) != len(paths):
        raise ValueError('input, output, receipt and provenance paths must be distinct')
    provenance_data = provenance_file.read_bytes()
    provenance = json.loads(provenance_data.decode('utf-8-sig'))
    if not isinstance(provenance, dict) or provenance.get('schema_version') != 1 or provenance.get('kind') != 'fnv-coff-rename-provenance':
        raise ValueError('unsupported explicit source provenance')
    if not isinstance(provenance.get('recipe_id'), str) or not provenance['recipe_id'].strip():
        raise ValueError('provenance recipe identity is required')
    if provenance.get('object_sha256') != expected_sha256 or not hash_value(provenance.get('source_sha256')):
        raise ValueError('provenance fingerprints are missing or inconsistent')
    if not isinstance(provenance.get('source'), str) or not provenance['source']:
        raise ValueError('provenance source path is required')
    source = Path(provenance['source'])
    if not source.is_absolute():
        source = provenance_file.parent / source
    source = source.resolve()
    if source in (output, receipt):
        raise ValueError('outputs must not overwrite provenance source')
    if digest(source.read_bytes()) != provenance['source_sha256']:
        raise ValueError('provenance source fingerprint mismatch')
    if output.exists() or receipt.exists():
        raise ValueError('output and receipt must not already exist')
    transformed, edit = rename_bytes(source_input, expected_sha256, old_name, new_name)
    # Verify a private staging file before exposing a named output. Publication
    # uses exclusive creation; a later failure removes only files we created.
    output.parent.mkdir(parents=True, exist_ok=True)
    staging = None
    try:
        with tempfile.NamedTemporaryFile(dir=output.parent, prefix='.coff-rename-', suffix='.obj', delete=False) as stream:
            staging = Path(stream.name)
            stream.write(transformed)
        return publish_verified(staging, source_input, output, receipt, provenance,
                                provenance_data, expected_sha256, old_name, new_name,
                                transformed, edit)
    finally:
        if staging is not None:
            staging.unlink(missing_ok=True)


def publish_verified(staging, source_input, output, receipt, provenance,
                     provenance_data, expected_sha256, old_name, new_name, transformed, edit):
    after, _, _, _ = strict_object(staging)
    before = Coff(source_input)
    if digest(before.data) != expected_sha256:
        raise ValueError('input changed during rewrite')
    expected_symbols = copy.deepcopy(before.symbols)
    expected_symbols[edit['symbol_index']]['name'] = new_name
    for symbol in expected_symbols.values():
        if symbol.get('weak', {}).get('fallback_index') == edit['symbol_index']:
            symbol['weak']['fallback'] = new_name
    if after.symbols != expected_symbols or after.sections != before.sections or after.directives != before.directives:
        raise ValueError('independent reparse did not preserve COFF structure')
    # Stronger than payload equality: every original byte except these two fields
    # must remain identical. All auxiliary/relocation/header bytes are covered.
    allowed = set(range(edit['name_field_offset'], edit['name_field_offset'] + 8))
    allowed.update(range(edit['string_table_offset'], edit['string_table_offset'] + 4))
    if any(a != b and i not in allowed for i, (a, b) in enumerate(zip(before.data, transformed))):
        raise ValueError('unexpected original-byte mutation')
    report = dict(schema_version=1, kind='fnv-coff-definition-rename', status='pass',
        scope='one definition identity only; no ABI, provider-selection, link or runtime verdict',
        recipe_id=provenance['recipe_id'], source_sha256=provenance['source_sha256'],
        provenance_scope='caller-declared recipe/source association; source and object hashes verified independently, not compiler causality',
        provenance_sha256=digest(provenance_data), input_sha256=expected_sha256,
        output_sha256=digest(transformed), old_name=old_name, new_name=new_name, edit=edit,
        verification=dict(original_bytes_unchanged_except_name_and_string_length=True,
            section_payloads_relocations_auxiliaries_directives_preserved=True,
            symbol_indices_preserved=True, independent_reparse=True))
    receipt.parent.mkdir(parents=True, exist_ok=True)
    output_created = receipt_created = False
    try:
        with output.open('xb') as stream:
            output_created = True
            stream.write(transformed)
        with receipt.open('x', encoding='utf-8') as stream:
            receipt_created = True
            json.dump(report, stream, indent=2)
            stream.write('\n')
    except BaseException:
        if receipt_created:
            receipt.unlink(missing_ok=True)
        if output_created:
            output.unlink(missing_ok=True)
        raise
    return report


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('input', 'output', 'receipt', 'provenance'):
        parser.add_argument('--' + name, required=True, type=Path)
    parser.add_argument('--expected-sha256', required=True)
    parser.add_argument('--old-name', required=True)
    parser.add_argument('--new-name', required=True)
    args = parser.parse_args()
    try:
        report = rewrite(args.input, args.output, args.receipt, args.provenance,
                         args.expected_sha256, args.old_name, args.new_name)
    except (OSError, ValueError, KeyError, TypeError, struct.error) as error:
        parser.exit(1, 'COFF rename rejected: ' + str(error) + '\n')
    print(json.dumps(dict(status=report['status'], output_sha256=report['output_sha256'])))


if __name__ == '__main__':
    main()
