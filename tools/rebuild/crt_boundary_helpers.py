"""Finite exact-address standard CRT helper observations, no identity adoption.

Contracts mode reads pinned library metadata and the saved candidate receipt.
Probe mode additionally requires independent review of that exact contract and
source bundle. It reads only complete native-section spans at eleven helpers'
receipt-derived addresses, wholly inside the pinned original .text geometry.
No search, execution, original payload output or recursive probing is available.
"""
from __future__ import annotations
import argparse
import hashlib
import json
from pathlib import Path
import struct
import tempfile

import crt_table_boundaries as base
from coff_inventory import Coff
from crt_provider import archive_member
from data_plan import Pe, file_hash

CANDIDATES = 'f268c8d3ebd5cd305b022c6b0bec3dc40d1709ec862e1a942ba71733c6d3df7c'
HELPERS = ('__IsNonwritableInCurrentImage', '__initp_misc_cfltcvt_tab', '__RTC_Terminate',
           '_atexit', '__SEH_prolog4', '__SEH_epilog4', '__lock', '__unlock',
           '__decode_pointer', '__encoded_null', '___crtExitProcess')
MAX_REQUESTED = 64 * 1024


def require(value, message):
    if not value:
        raise ValueError(message)


def source_manifest():
    sources = base.source_manifest()
    for name in ('tools/rebuild/crt_boundary_helpers.py', 'tests/rebuild/test_crt_boundary_helpers.py'):
        sources[name] = file_hash(base.ROOT / name)
    return sources


def field_mask(size, relocations):
    """No anchor-length rule: this driver never searches for a signature."""
    masked = set()
    for row in relocations:
        offset = row['offset']
        require(row['kind'] in (6, 20) and 0 <= offset <= size - 4, 'unsupported/outside relocation')
        field = set(range(offset, offset + 4))
        require(not masked.intersection(field), 'overlapping relocation fields')
        masked.update(field)
    require(len(masked) < size, 'no fixed bytes')
    return masked


def derived_targets(candidate_report):
    result = {name: [] for name in HELPERS}
    for observation in candidate_report['observations']:
        if not observation['identity'].startswith('sp1:'):
            continue
        require(observation['identity'][4:] in base.FUNCTIONS, 'unexpected primary function')
        for candidate in observation['candidates']:
            for relocation in candidate['relocations']:
                name = relocation['symbol']
                if name in result:
                    result[name].append(dict(caller=observation['identity'],
                        caller_address=candidate['address'], field_va=relocation['field_va'],
                        relocation_kind=relocation['kind'],
                        target=relocation['original_symbol_base_candidate'],
                        parent_relocation_errors=relocation['errors']))
    return result


def span_base(target, symbol_value, size, text_start, text_end):
    start = target - symbol_value
    require(0 < size <= 4096 and text_start <= start <= text_end - size,
            'complete native section is outside allowed text geometry')
    return start


def load_contracts(doctor_path, candidates_path):
    require(file_hash(doctor_path) == base.DOCTOR, 'doctor differs')
    require(file_hash(candidates_path) == CANDIDATES, 'candidate receipt differs')
    doctor = json.loads(Path(doctor_path).read_text())
    saved = json.loads(Path(candidates_path).read_text())
    require(saved['candidate_only'] is True and saved['original_table_bounds_verified'] is False and
            saved['original_runtime_order_verified'] is False and saved['runtime_provider_approved'] is False,
            'candidate receipt scope differs')
    derived = derived_targets(saved)
    path = Path(doctor['toolchains']['sp1']['root']) / 'VC/lib/libcmt.lib'
    require(file_hash(path) == base.LIBRARIES['sp1'], 'SP1 library differs')
    contracts, patterns = [], {}
    for name in HELPERS:
        require(derived[name], 'helper has no receipt-derived target')
        payload, metadata = archive_member(path, name)
        with tempfile.TemporaryDirectory(prefix='fnv_crt_helper_metadata_') as folder:
            temporary = Path(folder) / 'member.obj'
            temporary.write_bytes(payload)
            coff = Coff(temporary)
        definitions = [s for s in coff.symbols.values() if s['name'] == name and
                       s['section'] > 0 and s['type'] == 32]
        require(len(definitions) == 1, 'helper definition absent/ambiguous')
        definition = definitions[0]
        section = coff.sections[definition['section']]
        require(section['flags'] & 0x20000000 and 0 < section['size'] <= 4096 and
                0 <= definition['value'] < section['size'], 'not a bounded native executable section')
        raw = struct.unpack_from('<I', coff.data, 20 + (section['index'] - 1) * 40 + 20)[0]
        pattern = coff.take(raw, section['size'])
        relocations = []
        for offset, index, kind in section['relocs']:
            require(0 <= offset <= len(pattern) - 4, 'relocation outside complete native section')
            symbol = coff.symbols[index]
            relocations.append(dict(offset=offset, kind=kind,
                addend=struct.unpack_from('<i', pattern, offset)[0], symbol_index=index,
                symbol=symbol['name'], symbol_type=symbol['type'], symbol_section=symbol['section'],
                symbol_value=symbol['value'], symbol_storage=symbol['storage']))
        masked = field_mask(len(pattern), relocations)
        targets = sorted({row['target'] for row in derived[name]})
        contracts.append(dict(symbol=name, family='sp1-witness-not-original-version-proof',
            member=metadata, symbol_index=definition['index'], symbol_value=definition['value'],
            section=section['index'], size=section['size'],
            section_function_symbols=[dict(symbol=s['name'], value=s['value']) for s in coff.symbols.values()
                if s['type'] == 32 and s['section'] == definition['section']],
            native_section_sha256=hashlib.sha256(pattern).hexdigest(),
            nonrelocation_sha256=hashlib.sha256(bytes(v for i, v in enumerate(pattern) if i not in masked)).hexdigest(),
            relocations=relocations, receipt_fields=derived[name],
            target_candidates=targets, target_ambiguity=len(targets) != 1))
        patterns[name] = pattern
    return contracts, patterns, path


def contract_document(contracts, sources):
    return dict(schema_version=1, kind='fnv-crt-helper-probe-contracts', sources=sources,
        doctor_sha256=base.DOCTOR, candidate_receipt_sha256=CANDIDATES,
        library_sha256=base.LIBRARIES['sp1'], functions=list(HELPERS),
        contracts=contracts, text_geometry=base.TEXT, max_requested_bytes=MAX_REQUESTED,
        candidate_only=True, allow_recursive_probe=False, runtime_provider_approved=False)


def review_gate(path, expected, sources, contract_hash):
    require(file_hash(path) == expected, 'review hash differs')
    review = json.loads(Path(path).read_text())
    require(review.get('kind') == 'fnv-crt-helper-probe-source-review' and
            review.get('status') == 'approved' and review.get('reviewer') and
            review.get('sources') == sources and review.get('contracts_sha256') == contract_hash and
            review.get('candidate_receipt_sha256') == CANDIDATES and
            review.get('functions') == list(HELPERS) and review.get('reference_sha256') == base.REFERENCE and
            review.get('allow_reference_probe') is True and review.get('allow_execute') is False and
            review.get('candidate_only') is True, 'review does not authorize exact finite helper probes')


def run(args):
    out = Path(args.out)
    require(not out.exists(), 'output exists')
    sources = source_manifest()
    contracts, patterns, library = load_contracts(args.doctor, args.candidates)
    bundle = contract_document(contracts, sources)
    result = dict(kind='fnv-crt-helper-observation', schema_version=1, mode=args.mode,
                  contract=bundle, candidate_only=True, original_table_bounds_verified=False,
                  original_runtime_order_verified=False, runtime_provider_approved=False, executed=False)
    protected = [(Path(args.doctor), base.DOCTOR), (Path(args.candidates), CANDIDATES),
                 (library, base.LIBRARIES['sp1'])]
    if args.mode == 'contracts':
        result = bundle
    else:
        require(args.contracts and args.contracts_sha256 and args.review and args.review_sha256 and args.reference,
                'probe requires exact contracts, source review and reference')
        require(file_hash(args.contracts) == args.contracts_sha256, 'contracts hash differs')
        require(json.loads(Path(args.contracts).read_text()) == bundle, 'contract metadata differs')
        review_gate(args.review, args.review_sha256, sources, args.contracts_sha256)
        require(file_hash(args.reference) == base.REFERENCE, 'reference differs')
        protected.extend(((Path(args.contracts), args.contracts_sha256), (Path(args.review), args.review_sha256),
                          (Path(args.reference), base.REFERENCE)))
        pe = Pe(args.reference)
        observations, requested = [], 0
        try:
            require(pe.base == 0x400000 and [s for s in pe.sections if s['name'] == '.text'] == [base.TEXT],
                    'allowed original text geometry differs')
            highlow = set(pe.relocations())
            text_start = pe.base + base.TEXT['rva']
            text_end = text_start + base.TEXT['extent']
            for contract in contracts:
                for target in contract['target_candidates']:
                    start = span_base(target, contract['symbol_value'], contract['size'], text_start, text_end)
                    requested += contract['size']
                    require(requested <= MAX_REQUESTED, 'finite helper byte budget exceeded')
                    actual = pe.read_rva(start - pe.base, contract['size'], allow_code=True)
                    masked = field_mask(len(actual), contract['relocations'])
                    pattern = patterns[contract['symbol']]
                    equal = all(actual[i] == pattern[i] for i in range(len(actual)) if i not in masked)
                    observations.append(dict(symbol=contract['symbol'], target_candidate=target,
                        native_symbol_value=contract['symbol_value'], section_start_candidate=start,
                        size=len(actual), original_span_sha256=hashlib.sha256(actual).hexdigest(),
                        full_nonrelocation_span_equal=equal,
                        relocations=base.observe_relocations(contract, start, actual, start, pe, highlow),
                        independent_symbol_identity_verified=False, relocation_semantics_complete=False))
            result.update(observations=observations, executable_bytes_requested=requested,
                          reference_sha256=base.REFERENCE, review_sha256=args.review_sha256)
        finally:
            pe.close()
    require(source_manifest() == sources, 'implementation changed')
    for path, expected in protected:
        require(file_hash(path) == expected, 'protected input changed')
    require(out.resolve() not in {path.resolve() for path, _ in protected}, 'output aliases input')
    with out.open('x', encoding='utf-8') as stream:
        json.dump(result, stream, separators=(',', ':'))
    return dict(mode=args.mode, helper_contracts=len(contracts), candidate_only=True,
                probes=len(result.get('observations', [])))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--mode', choices=('contracts', 'probes'), required=True)
    for name in ('doctor', 'candidates', 'out'):
        parser.add_argument('--' + name, required=True)
    for name in ('reference', 'contracts', 'contracts_sha256', 'review', 'review_sha256'):
        parser.add_argument('--' + name.replace('_', '-'))
    print(json.dumps(run(parser.parse_args()), sort_keys=True))


if __name__ == '__main__':
    main()
