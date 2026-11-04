"""Bounded native CRT contribution roster; no original-image access.

Enumerates only three pinned libcmt archives, reads section-name metadata first,
then parses CRT-containing members and exact named function definitions. Reports
every unsupported/ambiguous case; exports no code bytes or runtime providers.
"""
from __future__ import annotations
import argparse
from collections import Counter
import hashlib
import json
from pathlib import Path
import struct
import tempfile

from coff_inventory import Coff
from crt_bootstrap_contract import ArchiveEvidence, file_identity
from data_plan import file_hash
import crt_table_boundaries as base


def require(value, message):
    if not value: raise ValueError(message)


def source_manifest():
    result = base.source_manifest()
    for name in ('tools/rebuild/crt_callback_roster.py', 'tests/rebuild/test_crt_callback_roster.py',
                 'tools/rebuild/crt_bootstrap_contract.py'):
        result[name] = file_hash(base.ROOT / name)
    return result


def section_names(payload):
    """Header-only standard COFF metadata, independent of auxiliary-symbol use."""
    require(len(payload) >= 20, 'short COFF member')
    machine, count, _, symbols, symbol_count, optional, _ = struct.unpack_from('<HHIIIHH', payload)
    require(machine == 0x14c and optional == 0 and count <= 65535 and 20 + count * 40 <= len(payload),
            'not bounded standard i386 COFF headers')
    strings = b''
    if symbols:
        at = symbols + symbol_count * 18
        require(at + 4 <= len(payload), 'short symbol/string table')
        length = struct.unpack_from('<I', payload, at)[0]
        require(length >= 4 and at + length <= len(payload), 'bad string table')
        strings = payload[at:at + length]
    names = []
    for index in range(count):
        raw = payload[20 + index * 40:28 + index * 40].rstrip(b'\0')
        if raw.startswith(b'/'):
            require(raw[1:].isdigit(), 'invalid long section name')
            at = int(raw[1:])
            require(4 <= at < len(strings), 'section name outside string table')
            end = strings.find(b'\0', at)
            require(end >= 0, 'unterminated long section name')
            raw = strings[at:end]
        names.append(raw.decode('ascii'))
    return names


def read_member(archive, offset):
    _, start, end = archive.members[offset]
    payload = archive.data[start:end]
    require(len(payload) <= 1024 * 1024, 'native member exceeds one MiB')
    with tempfile.TemporaryDirectory(prefix='fnv_crt_roster_') as folder:
        path = Path(folder) / 'member.obj'
        path.write_bytes(payload)
        coff = Coff(path)
    return coff, dict(member_header_offset=offset, member_name=archive.names[offset],
                      member_sha256=hashlib.sha256(payload).hexdigest())


def definition_candidates(archive, origin, origin_meta, symbol):
    unsupported = []
    if symbol['section'] > 0:
        choices = [(origin, origin_meta, symbol)]
    else:
        choices = []
        for offset in archive.index.get(symbol['name'], []):
            try:
                target, meta = read_member(archive, offset)
            except ValueError:
                unsupported.append(dict(member_header_offset=offset, member_name=archive.names[offset],
                    symbol=symbol['name'], errors=['named definition COFF metadata unsupported'],
                    independent_original_identity_verified=False))
                continue
            choices.extend((target, meta, row) for row in target.symbols.values()
                           if row['name'] == symbol['name'] and row['section'] > 0)
    result = unsupported
    for coff, meta, row in choices:
        section = coff.sections[row['section']]
        errors = []
        if row['type'] != 32 or not section['flags'] & 0x20000000:
            errors.append('named target is not a native executable function')
        if not 0 < section['size'] <= 4096:
            errors.append('complete native section outside finite-probe size band')
        header = coff.unpack('<8sIIIIIIHHI', 20 + (section['index'] - 1) * 40)
        code = coff.take(header[4], header[3]) if header[4] else b''
        relocations, covered = [], set()
        for offset, index, kind in section['relocs']:
            target = coff.symbols[index]
            addend = None
            if kind not in (6, 20) or not 0 <= offset <= len(code) - 4:
                errors.append('unsupported native code relocation')
            else:
                field = set(range(offset, offset + 4))
                if field.intersection(covered): errors.append('overlapping native code relocation')
                covered.update(field)
                addend = struct.unpack_from('<i', code, offset)[0]
            relocations.append(dict(offset=offset, kind=kind, addend=addend,
                symbol_index=index, symbol=target['name'], symbol_type=target['type'],
                symbol_section=target['section'], symbol_value=target['value'], symbol_storage=target['storage']))
        result.append(dict(meta, symbol=row['name'], symbol_index=row['index'],
            section=row['section'], value=row['value'], section_size=section['size'],
            complete_section_sha256=hashlib.sha256(code).hexdigest(),
            fixed_byte_count=len(code) - len(covered),
            section_function_symbols=[dict(symbol=s['name'], value=s['value']) for s in coff.symbols.values()
                if s['section'] == row['section'] and s['type'] == 32],
            relocations=relocations, errors=errors, independent_original_identity_verified=False))
    return result


def roster_for_archive(archive):
    records, member_issues, counts = [], [], Counter()
    for offset, name in archive.names.items():
        _, start, end = archive.members[offset]
        payload = archive.data[start:end]
        counts['physical_members'] += 1
        if payload[:4] == b'\0\0\xff\xff':
            counts['short_import_members'] += 1
            continue
        try:
            names = section_names(payload)
        except (ValueError, UnicodeError, struct.error) as exc:
            member_issues.append(dict(member_header_offset=offset, member_name=name,
                                      reason=type(exc).__name__, CRT_header_coverage_verified=False))
            counts['header_unsupported'] += 1
            continue
        counts['header_supported'] += 1
        if not any(name == '.CRT' or name.startswith('.CRT$') for name in names):
            counts['no_CRT_sections_by_header'] += 1
            continue
        counts['CRT_containing_members'] += 1
        try:
            coff, meta = read_member(archive, offset)
        except ValueError as exc:
            member_issues.append(dict(member_header_offset=offset, member_name=name,
                reason=type(exc).__name__, CRT_header_coverage_verified=True, CRT_member_parse_verified=False))
            counts['CRT_member_unsupported'] += 1
            continue
        for section in coff.sections.values():
            if section['name'] != '.CRT' and not section['name'].startswith('.CRT$'): continue
            counts['CRT_sections'] += 1
            for slot, index, kind in section['relocs']:
                symbol = coff.symbols[index]
                header = coff.unpack('<8sIIIIIIHHI', 20 + (section['index'] - 1) * 40)
                addend = struct.unpack('<i', coff.take(header[4] + slot, 4))[0] if header[4] and slot + 4 <= section['size'] else None
                definitions = definition_candidates(archive, coff, meta, symbol)
                records.append(dict(meta, category=section['name'], section=section['index'],
                    offset=slot, kind=kind, addend=addend, target_symbol=symbol['name'],
                    target_symbol_index=index, target_type=symbol['type'],
                    native_definition_candidates=definitions,
                    ambiguous_definition=len(definitions) != 1,
                    source_role_only=True, original_address_known=False, runtime_provider_approved=False))
                counts['CRT_relocated_slots'] += 1
    return dict(summary=dict(counts), member_issues=member_issues, records=records)


def run(args):
    require(file_hash(args.doctor) == base.DOCTOR, 'doctor differs')
    require(not Path(args.out).exists(), 'output exists')
    doctor = json.loads(Path(args.doctor).read_text())
    sources, families, protected = source_manifest(), {}, []
    for family, expected in base.LIBRARIES.items():
        path = Path(doctor['toolchains'][family]['root']) / 'VC/lib/libcmt.lib'
        require(file_hash(path) == expected, 'pinned native library differs')
        binding = file_identity(path)
        archive = ArchiveEvidence(binding)
        families[family] = dict(archive_sha256=expected, **roster_for_archive(archive))
        protected.append((path, expected))
    require(source_manifest() == sources and file_hash(args.doctor) == base.DOCTOR, 'source/doctor changed')
    for path, expected in protected: require(file_hash(path) == expected, 'library changed')
    result = dict(schema_version=1, kind='fnv-native-crt-callback-roster', sources=sources,
        doctor_sha256=base.DOCTOR, families=families, original_image_read=False,
        source_role_only=True, original_table_identity_verified=False, runtime_provider_approved=False)
    with Path(args.out).open('x') as output: json.dump(result, output, separators=(',', ':'))
    return {family: row['summary'] for family, row in families.items()}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--doctor', required=True)
    parser.add_argument('--out', required=True)
    print(json.dumps(run(parser.parse_args()), sort_keys=True))


if __name__ == '__main__': main()
