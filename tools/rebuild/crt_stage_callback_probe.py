"""Finite named native CRT XI/XP callback comparisons at ten exact targets.

Requires peer-reviewed exact inputs/source/grid; no search or XC/entry/protection
route. Reads each declared .text window once, 1,754 bytes total. Every candidate
comparison/relocation failure survives. No original bytes or executable output.
"""
from __future__ import annotations
import argparse
from collections import Counter
import hashlib
import json
import os
from pathlib import Path
import struct

import crt_table_boundaries as base
import crt_boundary_helpers as helper
import crt_callback_roster as roster_tool
from crt_bootstrap_contract import ArchiveEvidence, file_identity
from data_plan import Pe, file_hash

PINS = dict(audit='4c3232a5cf35ec00055edfb4a35e383732a30a93aa4c5b5cf0138a49d60f89f9',
    roster='12e5fd6111af319026fe20b027d5ba016f9e929ea9b1f6990927c50cfd92e463',
    doctor=base.DOCTOR, reference=base.REFERENCE)
EXACT_BYTES = 1754
MAX_OUTPUT = 10 * 1024 * 1024


def require(value, message):
    if not value: raise ValueError(message)


def source_manifest():
    result = roster_tool.source_manifest()
    result.update(helper.source_manifest())
    for name in ('tools/rebuild/crt_stage_callback_probe.py', 'tests/rebuild/test_crt_stage_callback_probe.py'):
        result[name] = file_hash(base.ROOT / name)
    return result


def load_pattern(archive, candidate):
    definition = candidate['definition']
    require(not definition['errors'], 'unsupported native definition cannot be probed')
    coff, metadata = roster_tool.read_member(archive, definition['member_header_offset'])
    require(all(metadata[name] == definition[name] for name in metadata), 'native physical member differs')
    symbol = coff.symbols[definition['symbol_index']]
    require(symbol['name'] == candidate['symbol'] == definition['symbol'] and symbol['type'] == 32 and
        (symbol['section'], symbol['value']) == (definition['section'], definition['value']), 'native named definition differs')
    section = coff.sections[symbol['section']]
    require(section['flags'] & 0x20000000 and section['size'] == definition['section_size'], 'native code span differs')
    aliases = [dict(symbol=s['name'], value=s['value']) for s in coff.symbols.values()
               if s['section'] == symbol['section'] and s['type'] == 32]
    require(aliases == definition['section_function_symbols'], 'native intra-section symbol ownership differs')
    header = coff.unpack('<8sIIIIIIHHI', 20 + (section['index'] - 1) * 40)
    code = coff.take(header[4], section['size'])
    require(hashlib.sha256(code).hexdigest() == definition['complete_section_sha256'], 'native code hash differs')
    relocations = []
    for offset, index, kind in section['relocs']:
        target = coff.symbols[index]
        require(0 <= offset <= len(code) - 4, 'native relocation outside span')
        relocations.append(dict(offset=offset, kind=kind, addend=struct.unpack_from('<i', code, offset)[0],
            symbol_index=index, symbol=target['name'], symbol_type=target['type'],
            symbol_section=target['section'], symbol_value=target['value'], symbol_storage=target['storage']))
    require(relocations == definition['relocations'], 'native relocation metadata differs')
    mask = helper.field_mask(len(code), relocations)
    require(len(code) - len(mask) == definition['fixed_byte_count'], 'native fixed-byte count differs')
    return code


def compare_buffer(buffer, read_start, target, candidate, pattern, pe, highlow):
    definition = candidate['definition']
    start = target - definition['value']
    offset = start - read_start
    size = definition['section_size']
    require(0 <= offset <= len(buffer) - size and len(pattern) == size, 'candidate span outside exact read window')
    actual = buffer[offset:offset + size]
    mask = helper.field_mask(size, definition['relocations'])
    differences = [i for i in range(size) if i not in mask and actual[i] != pattern[i]]
    relocations = base.observe_relocations(definition, start, actual, start, pe, highlow)
    return dict(candidate_id=candidate['candidate_id'], family=candidate['family'], symbol=candidate['symbol'],
        complete_native_section_size=size, native_symbol_value=definition['value'], section_start_candidate=start,
        full_nonrelocation_span_equal=not differences, compared_fixed_bytes=size - len(mask),
        first_nonrelocation_difference_offset=differences[0] if differences else None,
        relocation_observations=relocations, all_field_geometry_checks_pass=not any(r['errors'] for r in relocations),
        original_identity_approved=False, callback_ABI_approved=False, runtime_provider_approved=False)


def review_gate(path, expected, sources, plan):
    require(file_hash(path) == expected, 'review hash differs')
    review = json.loads(Path(path).read_text())
    candidate_ids = sorted(c['candidate_id'] for values in plan['candidates'].values() for c in values)
    require(review.get('kind') == 'fnv-crt-stage-callback-probe-review' and review.get('status') == 'approved' and
        review.get('reviewer') and review.get('sources') == sources and review.get('inputs') == PINS and
        review.get('reads') == plan['reads'] and review.get('candidate_ids') == candidate_ids and
        review.get('aggregate_original_bytes') == EXACT_BYTES and review.get('allow_original_code_read') is True and
        review.get('allow_recursive_probes') is False and review.get('allow_execute') is False and
        review.get('XC_targets_in_probe_scope') == 0 and review.get('candidate_only') is True,
        'review does not authorize this exact finite standard-CRT grid')


def run(args):
    paths = {name: Path(getattr(args, name)) for name in PINS}
    sources = source_manifest()
    for name, path in paths.items(): require(file_hash(path) == PINS[name], 'input differs: ' + name)
    audit = json.loads(paths['audit'].read_text())
    roster = json.loads(paths['roster'].read_text())
    doctor = json.loads(paths['doctor'].read_text())
    plan = audit['proposed_CRT_probe_plan']
    require(plan['aggregate_original_bytes'] == EXACT_BYTES and plan['XC_targets_in_probe_scope'] == 0 and
        plan['allow_original_read'] is False and plan['allow_recursive_probes'] is False and
        len(plan['reads']) == 10, 'finite saved plan differs')
    review_gate(args.review, args.review_sha256, sources, plan)
    require(roster['original_image_read'] is False and roster['runtime_provider_approved'] is False, 'roster state differs')
    libraries, archives = {}, {}
    for family, expected in base.LIBRARIES.items():
        path = Path(doctor['toolchains'][family]['root']) / 'VC/lib/libcmt.lib'
        require(file_hash(path) == expected, 'native library differs')
        libraries[family] = (path, expected)
        archives[family] = ArchiveEvidence(file_identity(path))
    candidates = {c['candidate_id']: c for values in plan['candidates'].values() for c in values}
    patterns = {key: load_pattern(archives[c['family']], c) for key, c in candidates.items()}
    require(len(candidates) == 33, 'named native callback candidate population differs')
    destination = Path(args.out_dir)
    require(not destination.exists(), 'output directory exists')
    destination.mkdir()
    def journal(state, **details):
        with (destination / 'progress.jsonl').open('a') as output:
            output.write(json.dumps(dict(state=state, **details), separators=(',', ':')) + '\n')
            output.flush()
            os.fsync(output.fileno())
    journal('started', bytes=EXACT_BYTES, targets=10, XC_targets=0, allow_execute=False)
    pe = None
    requested, observations = 0, []
    try:
        pe = Pe(paths['reference'])
        require(pe.base == 0x400000 and [s for s in pe.sections if s['name'] == '.text'] == [base.TEXT], 'pinned text geometry differs')
        highlow = set(pe.relocations())
        lo, hi = pe.base + base.TEXT['rva'], pe.base + base.TEXT['rva'] + base.TEXT['extent']
        for read in plan['reads']:
            require(read['stage'] in ('xi', 'xp') and lo <= read['start'] < read['end'] <= hi and
                read['bytes'] == read['end'] - read['start'], 'read is outside exact allowed text scope')
            requested += read['bytes']
            require(requested <= EXACT_BYTES, 'original byte budget exceeded')
            buffer = pe.read_rva(read['start'] - pe.base, read['bytes'], allow_code=True)
            compared = [compare_buffer(buffer, read['start'], read['original_target'], candidates[key],
                patterns[key], pe, highlow) for key in read['candidate_ids']]
            observations.append(dict(read, original_window_sha256=hashlib.sha256(buffer).hexdigest(), comparisons=compared,
                positive_source_patterns=[r['candidate_id'] for r in compared if r['full_nonrelocation_span_equal']],
                original_identity_approved=False, runtime_provider_approved=False))
            journal('target-complete', stage=read['stage'], target=read['original_target'], bytes=requested)
        require(requested == EXACT_BYTES, 'incomplete exact original byte coverage')
        for name, path in paths.items(): require(file_hash(path) == PINS[name], 'protected input changed: ' + name)
        for path, expected in libraries.values(): require(file_hash(path) == expected, 'native library changed')
        require(source_manifest() == sources and file_hash(args.review) == args.review_sha256, 'source/review changed')
        counts = Counter()
        for row in observations:
            counts['targets'] += 1
            counts['candidate_comparisons'] += len(row['comparisons'])
            counts['targets_with_fixed_span_match'] += bool(row['positive_source_patterns'])
            for comparison in row['comparisons']:
                counts['fixed_span_matches'] += comparison['full_nonrelocation_span_equal']
                counts['failed_fixed_span_comparisons'] += not comparison['full_nonrelocation_span_equal']
                counts['relocation_fields'] += len(comparison['relocation_observations'])
        result = dict(schema_version=1, kind='fnv-crt-stage-callback-observation', inputs=PINS,
            sources=sources, review_sha256=args.review_sha256, read_bytes=requested,
            counts=dict(counts), observations=observations, original_identity_approved=False,
            original_startup_reachability_proven=False, original_table_bounds_approved=False,
            callback_ABI_approved=False, runtime_provider_approved=False, executed=False)
        encoded = json.dumps(result, separators=(',', ':'))
        require(len(encoded.encode()) + (destination / 'progress.jsonl').stat().st_size + 1024 <= MAX_OUTPUT,
                'complete output exceeds finite cap')
        with (destination / 'report.json').open('x') as output: output.write(encoded)
        journal('completed', report_sha256=file_hash(destination / 'report.json'), bytes=requested)
        return dict(counts=dict(counts), bytes=requested, runtime_provider_approved=False)
    except Exception:
        journal('failed-or-unknown', bytes=requested, complete=False)
        raise
    finally:
        if pe is not None: pe.close()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    for name in list(PINS) + ['review', 'review_sha256', 'out_dir']:
        parser.add_argument('--' + name.replace('_', '-'), required=True)
    print(json.dumps(run(parser.parse_args()), sort_keys=True))


if __name__ == '__main__': main()
