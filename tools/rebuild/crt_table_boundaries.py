"""Finite standard-CRT signature observations, never boundary/provider approval.

The contracts mode reads only three pinned normal CRT archives. Candidates mode
requires independent hash-bound source review before reading the one pinned
reference .text section. It never reads packaging sections or executes code.
All output is private metadata; no instruction bytes or disassembly are emitted.
"""
from __future__ import annotations
import argparse
import hashlib
import json
from pathlib import Path
import struct
import tempfile

from coff_inventory import Coff
from crt_provider import archive_member
from data_plan import Pe, file_hash

ROOT = Path(__file__).resolve().parents[2]
DOCTOR = '9b24d10209fe0361a5e6b16b11a072e8e0ebc6505cd4b5e1bd782fe23854f29f'
REFERENCE = 'df1788907c6e26ef4df0b448ead526825336356b5606650165a1ce0825097eb7'
LIBRARIES = {
    'sp1': 'bd9700d126d378f31f32736abc0c88cb08a8e0f0914acb6e2c8cbfd1ab99f411',
    'rtm': 'bd8fe9fa475deb84014af41870182b447bb969c91661d7012ae8d1b26bb6a86c',
    'vc8': '3bc6c5b90f8507964839fd0264d8565c3b766d01f9efcad336532a11e8f06ac3',
}
MEMBERS = {
    'sp1': '656423f58dc1d164d4764639cd82a940aaf039a8d822be45b2a151ddd28ac326',
    'rtm': '4c1e1601cfbdebdbd4a9cd6b2f18d38bc6705f4e8c074ddb54c38478ea1d975a',
    'vc8': '72a9f77fb45c08985c23679d0ee1fb4ab4793cfa81d4149902e7c58eacfade14',
}
FUNCTIONS = ('__initterm', '__initterm_e', '__cinit', '_doexit',
             '_exit', '__exit', '__cexit', '__c_exit')
BOUNDARIES = tuple('___%s_%s' % (stage, end) for stage in ('xi', 'xc', 'xp', 'xt')
                   for end in ('a', 'z'))
TEXT = dict(index=0, name='.text', rva=4096, virtual_size=12440971,
            extent=12440971, raw_size=12441088, raw_offset=1024,
            flags=1610612768, executable=True)
SOURCES = ('tools/rebuild/crt_table_boundaries.py', 'tests/rebuild/test_crt_table_boundaries.py',
           'tools/rebuild/coff_inventory.py', 'tools/rebuild/crt_provider.py',
           'tools/rebuild/data_plan.py', 'tools/compare.py', 'tools/rebuild/toolchain.py')


def require(value, message):
    if not value:
        raise ValueError(message)


def canonical(value):
    return json.dumps(value, sort_keys=True, separators=(',', ':')).encode('ascii')


def source_manifest():
    return {name: file_hash(ROOT / name) for name in SOURCES}


def fixed_segments(size, relocations):
    """Precisely mask supported four-byte COFF fields; no wildcard expansion."""
    occupied = set()
    for row in relocations:
        offset = row['offset']
        require(row['kind'] in (6, 20) and 0 <= offset <= size - 4,
                'unsupported/outside relocation')
        span = set(range(offset, offset + 4))
        require(not occupied.intersection(span), 'overlapping relocation fields')
        occupied.update(span)
    spans, start = [], None
    for position in range(size + 1):
        fixed = position < size and position not in occupied
        if fixed and start is None:
            start = position
        if not fixed and start is not None:
            spans.append((start, position))
            start = None
    require(spans and sum(b - a for a, b in spans) >= 6, 'insufficient fixed signature')
    return spans


def exact_candidates(text, pattern, relocations):
    """Return all full-span nonrelocation matches, including overlapping ones."""
    spans = fixed_segments(len(pattern), relocations)
    anchor_start, anchor_end = max(spans, key=lambda ab: ab[1] - ab[0])
    anchor = pattern[anchor_start:anchor_end]
    position, found = 0, []
    while True:
        position = text.find(anchor, position)
        if position < 0:
            break
        start = position - anchor_start
        if 0 <= start <= len(text) - len(pattern) and all(
                text[start + a:start + b] == pattern[a:b] for a, b in spans):
            found.append(start)
        position += 1
    return found


def target_from_field(actual, addend, kind, field_va):
    require(kind in (6, 20), 'unknown relocation kind')
    return (actual - addend + (field_va + 4 if kind == 20 else 0)) & 0xffffffff


def load_contracts(doctor_path):
    require(file_hash(doctor_path) == DOCTOR, 'doctor identity differs')
    doctor = json.loads(Path(doctor_path).read_text())
    contracts, patterns, protected = [], {}, [(Path(doctor_path), DOCTOR)]
    for family, library_hash in LIBRARIES.items():
        path = Path(doctor['toolchains'][family]['root']) / 'VC/lib/libcmt.lib'
        require(file_hash(path) == library_hash, 'CRT library identity differs')
        protected.append((path, library_hash))
        payload, member = archive_member(path, '__initterm_e')
        require(member['member_sha256'] == MEMBERS[family], 'CRT member identity differs')
        with tempfile.TemporaryDirectory(prefix='fnv_crt_table_metadata_') as folder:
            temporary = Path(folder) / 'member.obj'
            temporary.write_bytes(payload)
            coff = Coff(temporary)
        for name in FUNCTIONS:
            symbols = [s for s in coff.symbols.values() if s['name'] == name and
                       s['section'] > 0 and s['type'] == 32]
            require(len(symbols) == 1, 'absent/ambiguous named CRT function')
            symbol = symbols[0]
            section = coff.sections[symbol['section']]
            same_section = [s for s in coff.symbols.values() if
                            s['section'] == symbol['section'] and s['type'] == 32]
            require(len(same_section) == 1 and symbol['value'] == 0 and
                    6 <= section['size'] <= 4096 and section['flags'] & 0x20000000,
                    'named function does not own one bounded executable section')
            raw = struct.unpack_from('<I', coff.data, 20 + (section['index'] - 1) * 40 + 20)[0]
            pattern = coff.take(raw, section['size'])
            relocations = []
            for offset, index, kind in section['relocs']:
                target = coff.symbols[index]
                require(0 <= offset <= len(pattern) - 4, 'relocation outside span')
                addend = struct.unpack_from('<i', pattern, offset)[0]
                relocations.append(dict(offset=offset, kind=kind, addend=addend,
                    symbol_index=index, symbol=target['name'], symbol_type=target['type'],
                    symbol_section=target['section'], symbol_value=target['value'],
                    symbol_storage=target['storage']))
            spans = fixed_segments(len(pattern), relocations)
            identity = family + ':' + name
            contracts.append(dict(identity=identity, family=family, symbol=name,
                archive_sha256=library_hash, member=member, section=section['index'],
                symbol_index=symbol['index'], size=len(pattern),
                span_kind='complete uniquely named native function section including local funclets',
                span_sha256=hashlib.sha256(pattern).hexdigest(),
                nonrelocation_sha256=hashlib.sha256(b''.join(pattern[a:b] for a, b in spans)).hexdigest(),
                fixed_spans=spans, relocations=relocations))
            patterns[identity] = pattern
    return contracts, patterns, protected


def review_gate(path, expected, sources):
    require(file_hash(path) == expected, 'source review identity differs')
    review = json.loads(Path(path).read_text())
    require(review.get('kind') == 'fnv-crt-boundary-scan-review' and
            review.get('status') == 'approved' and review.get('reviewer') and
            review.get('allow_reference_scan') is True and review.get('allow_execute') is False and
            review.get('sources') == sources and review.get('functions') == list(FUNCTIONS) and
            review.get('reference_sha256') == REFERENCE and review.get('text_geometry') == TEXT and
            review.get('libraries') == LIBRARIES and review.get('members') == MEMBERS and
            review.get('candidate_only') is True, 'source review does not authorize this exact finite scan')


def observe_relocations(contract, address, text, text_va, pe, highlow):
    rows = []
    for relocation in contract['relocations']:
        offset = relocation['offset']
        position = address - text_va + offset
        actual = struct.unpack_from('<i', text, position)[0]
        field = address + offset
        target = target_from_field(actual, relocation['addend'], relocation['kind'], field)
        section = pe.section(target - pe.base, 1)
        errors = []
        if relocation['kind'] == 6 and field - pe.base not in highlow:
            errors.append('absolute field lacks original HIGHLOW relocation')
        if relocation['kind'] == 20 and field - pe.base in highlow:
            errors.append('REL32 field unexpectedly has original HIGHLOW relocation')
        if section is None:
            errors.append('target outside image logical sections')
        boundary = relocation['symbol'] in BOUNDARIES
        if boundary:
            if relocation['kind'] != 6 or relocation['addend'] != 0:
                errors.append('boundary is not an exact DIR32 symbol reference')
            if section is not None:
                within = target - pe.base - section['rva']
                if section['executable'] or within + 4 > section['raw_size']:
                    errors.append('boundary target metadata is not raw non-executable storage')
        rows.append(dict(relocation, field_va=field, original_symbol_base_candidate=target,
            field_highlow=field - pe.base in highlow,
            target_section=section['name'] if section else None,
            boundary_candidate=boundary, boundary_payload_read=False,
            errors=errors, independent_symbol_identity_verified=False,
            runtime_provider_approved=False))
    return rows


def run(args):
    out = Path(args.out)
    require(not out.exists(), 'output already exists')
    sources = source_manifest()
    contracts, patterns, protected = load_contracts(args.doctor)
    result = dict(schema_version=1, kind='fnv-standard-crt-boundary-candidates',
        mode=args.mode, functions=list(FUNCTIONS), sources=sources, libraries=LIBRARIES,
        members=MEMBERS, contracts=contracts, candidate_only=True,
        original_table_bounds_verified=False, original_runtime_order_verified=False,
        runtime_provider_approved=False, executed=False)
    if args.mode == 'candidates':
        require(args.review and args.review_sha256 and args.reference,
                'candidate scan requires exact source review and reference')
        review_gate(args.review, args.review_sha256, sources)
        protected.append((Path(args.review), args.review_sha256))
        require(file_hash(args.reference) == REFERENCE, 'reference identity differs')
        protected.append((Path(args.reference), REFERENCE))
        pe = Pe(args.reference)
        try:
            require(pe.base == 0x400000, 'reference image base differs')
            sections = [s for s in pe.sections if s['name'] == '.text']
            require(sections == [TEXT], 'exact allowed .text geometry differs')
            # The only executable read. No other section is a search surface.
            text = pe.read_rva(TEXT['rva'], TEXT['extent'], allow_code=True)
            text_va = pe.base + TEXT['rva']
            highlow = set(pe.relocations())
            observations, matches = [], {}
            for contract in contracts:
                identity = contract['identity']
                offsets = exact_candidates(text, patterns[identity], contract['relocations'])
                matches[identity] = [text_va + offset for offset in offsets]
            for contract in contracts:
                candidates = []
                for address in matches[contract['identity']]:
                    relocations = observe_relocations(contract, address, text, text_va, pe, highlow)
                    for relocation in relocations:
                        identities = []
                        for target_contract in contracts:
                            if target_contract['family'] == contract['family'] and \
                                    target_contract['symbol'] == relocation['symbol']:
                                identities.extend(matches[target_contract['identity']])
                        relocation['same_family_named_function_candidates'] = identities
                        relocation['matches_named_function_candidate'] = (
                            relocation['original_symbol_base_candidate'] in identities)
                    candidates.append(dict(address=address, full_nonrelocation_span_equal=True,
                        relocations=relocations, relocation_semantics_complete=False,
                        boundary_order_proved=False))
                observations.append(dict(identity=contract['identity'], match_count=len(candidates),
                    unique_candidate=len(candidates) == 1, candidates=candidates))
            result.update(reference_sha256=REFERENCE, text_geometry=TEXT,
                text_sha256=hashlib.sha256(text).hexdigest(),
                review_sha256=args.review_sha256, observations=observations,
                unresolved='All candidates require independent helper/data identity and variant call-flow proof; no table adoption')
        finally:
            pe.close()
    require(source_manifest() == sources, 'implementation sources changed')
    for path, expected in protected:
        require(file_hash(path) == expected, 'protected input changed')
    require(out.resolve() not in {p.resolve() for p, _ in protected}, 'output aliases input')
    with out.open('x', encoding='utf-8') as stream:
        json.dump(result, stream, separators=(',', ':'))
    return dict(mode=args.mode, contracts=len(contracts), candidate_only=True,
                observations=[dict(identity=x['identity'], matches=x['match_count'])
                              for x in result.get('observations', [])])


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--mode', choices=('contracts', 'candidates'), required=True)
    parser.add_argument('--doctor', required=True)
    parser.add_argument('--out', required=True)
    parser.add_argument('--reference')
    parser.add_argument('--review')
    parser.add_argument('--review-sha256')
    print(json.dumps(run(parser.parse_args()), sort_keys=True))


if __name__ == '__main__':
    main()
