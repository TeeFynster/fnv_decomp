"""Reviewed conditional-range NONEXEC CRT cell classification, never adoption.

No code read, search, execution, table reconstruction or runtime provider.
The only original payload reads are four-byte cells in the exact saved local
operand-derived intervals plus their four named end cells. All cells, unknowns,
nulls and competing source candidates remain separate metadata observations.
"""
from __future__ import annotations
import argparse
import bisect
from collections import Counter, defaultdict
import gzip
import hashlib
import json
import os
from pathlib import Path
import struct

from data_plan import Pe, file_hash

ROOT = Path(__file__).resolve().parents[2]
PINS = dict(
    plan='15a2c8695f45c891e390e5d34b8320c43adbb588f35d0e0bf525782964235426',
    manifest='bc62a5fb2553431b1e0547d11f366e52efb73096ea8ceb206c556ae5740a53eb',
    selection='48ae62cdc5b1754b9c4af674ef4716d53afb554882e174a93acf860eaf1c6cb1',
    crt_report='ae4aa835090331446ec05d73330b6a9979d9e6a1b07393669817c28705cf0a3f',
    crt_details='1dd38beb7dc802c3ca5ab56f23862e24c83f0141c9dce6a733eb18105db75929',
    candidates='f268c8d3ebd5cd305b022c6b0bec3dc40d1709ec862e1a942ba71733c6d3df7c',
    helpers='46a32adedeed001defb64c68ef59a1df6ba4506c8ce0f5b85bb04d890ad005df',
    reference='df1788907c6e26ef4df0b448ead526825336356b5606650165a1ce0825097eb7')
EXACT_REQUESTS = [('xi', 0x010113c4, 0x010113e8), ('xc', 0x00fdf4a4, 0x010113c0),
                  ('xp', 0x010113f4, 0x01011400), ('xt', 0x01011404, 0x01011408)]
EXACT_BYTES = 204640
MAX_OUTPUT = 10 * 1024 * 1024


def require(value, reason):
    if not value:
        raise ValueError(reason)


def source_manifest():
    return {n: file_hash(ROOT / n) for n in ('tools/rebuild/crt_table_classify.py',
        'tests/rebuild/test_crt_table_classify.py', 'tools/rebuild/data_plan.py')}


class Owners:
    """All covering intervals, including overlaps; no nearest-address ownership."""
    def __init__(self, selections, manifest):
        self.rows = []
        for address, selected in selections.items():
            unit = manifest['units'][selected['recipe_index']]
            require(unit['recipe_id'] == selected['recipe_id'], 'selected recipe differs')
            start = int(address, 16)
            self.rows.append(dict(original_entry=start, original_end=start + selected['size'],
                recipe_id=selected['recipe_id'], object_sha256=unit['object_sha256'],
                source_sha256=unit['source_sha256'], symbol=selected['symbol'],
                native_section=selected['section'], native_value=selected['value']))
        self.rows.sort(key=lambda row: row['original_entry'])
        self.starts = [row['original_entry'] for row in self.rows]
        self.maximum = []
        top = 0
        for row in self.rows:
            top = max(top, row['original_end'])
            self.maximum.append(top)

    def at(self, address):
        index = bisect.bisect_right(self.starts, address) - 1
        result = []
        while index >= 0 and self.maximum[index] > address:
            row = self.rows[index]
            if address < row['original_end']:
                result.append(dict(row, offset=address - row['original_entry'],
                    callable_ABI_verified=False, runtime_provider_approved=False))
            index -= 1
        return result


def native_catalog(path):
    index, count, unbound, units = defaultdict(list), 0, 0, 0
    with gzip.open(path, 'rt') as stream:
        for ordinal, line in enumerate(stream):
            row = json.loads(line)
            require(row['recipe_index'] == ordinal, 'native ledger recipe coverage/order differs')
            units += 1
            for section in row['sections']:
                for slot in section['relocations']:
                    count += 1
                    target = slot['original_target_candidate']
                    record = dict(recipe_id=row['recipe_id'], object_sha256=row['object_sha256'],
                        source_sha256=row['source_sha256'], native_section=section['index'],
                        native_offset=slot['offset'], symbol_index=slot['symbol_index'], symbol=slot['symbol'],
                        selected_same_physical_location=slot['selected_same_physical_location'],
                        original_registration_participation_verified=False)
                    if target is None:
                        unbound += 1
                    else:
                        index[target].append(record)
    require(units == 2988 and count == 10526 and unbound == 4260, 'native ledger census differs')
    return index, dict(objects=units, relocated_slots=count, unbound_slots=unbound)


def standard_candidates(saved, helpers):
    index = defaultdict(list)
    for observation in saved['observations']:
        for candidate in observation['candidates']:
            index[candidate['address']].append(dict(identity=observation['identity'],
                fixed_span_observed_equal=candidate['full_nonrelocation_span_equal'],
                independent_identity_verified=False, runtime_provider_approved=False))
    for candidate in helpers['observations']:
        index[candidate['target_candidate']].append(dict(identity='helper:' + candidate['symbol'],
            fixed_span_observed_equal=candidate['full_nonrelocation_span_equal'],
            independent_identity_verified=False, runtime_provider_approved=False))
    return index


def classify(value, site, has_highlow, pe, owners, native, standard, is_end):
    row = dict(original_site=site, has_HIGHLOW=has_highlow, is_null=value == 0,
        is_named_end_cell=is_end, original_target_va=None, domain='null',
        selected_code_owners=[], native_CRT_slot_candidates=[], standard_CRT_candidates=[],
        issues=[], callback_ABI_verified=False, original_runtime_invocation_verified=False,
        runtime_provider_approved=False)
    if value == 0:
        if has_highlow: row['issues'].append('null cell has a HIGHLOW relocation')
        return row
    if not has_highlow: row['issues'].append('nonzero cell lacks HIGHLOW provenance')
    if is_end: row['issues'].append('non-null named end-cell candidate')
    if not pe.base <= value < pe.base + pe.image_size:
        row.update(domain='uninterpreted-nonzero', word_sha256=hashlib.sha256(struct.pack('<I', value)).hexdigest())
        row['issues'].append('nonzero value is outside the original image; raw word omitted')
        return row
    row['original_target_va'] = value
    section = pe.section(value - pe.base, 1)
    if section is None:
        row['domain'] = 'image-header-or-gap'
        row['issues'].append('target has no logical PE section')
    elif section['executable']:
        row['domain'] = 'executable-target'
        row['selected_code_owners'] = owners.at(value)
        row['native_CRT_slot_candidates'] = native.get(value, [])
        row['standard_CRT_candidates'] = standard.get(value, [])
        if not row['selected_code_owners'] and not row['standard_CRT_candidates']:
            row['issues'].append('no selected source owner or observed standard-CRT candidate')
        if any(owner['offset'] for owner in row['selected_code_owners']):
            row['issues'].append('source-code interior requires separate callback contract')
    else:
        row['domain'] = 'non-executable-target'
        row['issues'].append('non-executable target in conditional callback range')
    return row


def review_gate(path, expected, sources):
    require(file_hash(path) == expected, 'review hash differs')
    review = json.loads(Path(path).read_text())
    require(review.get('kind') == 'fnv-crt-table-classifier-source-review' and
        review.get('status') == 'approved' and review.get('reviewer') and
        review.get('sources') == sources and review.get('inputs') == PINS and
        review.get('ranges') == [list(row) for row in EXACT_REQUESTS] and
        review.get('aggregate_bytes') == EXACT_BYTES and
        review.get('allow_nonexec_cell_read') is True and review.get('allow_code_read') is False and
        review.get('allow_execute') is False and review.get('conditional_classification_only') is True,
        'review does not authorize this exact conditional metadata classification')


def run(args):
    sources = source_manifest()
    paths = {name: Path(getattr(args, name)) for name in PINS}
    for name, path in paths.items(): require(file_hash(path) == PINS[name], 'input differs: ' + name)
    review_gate(args.review, args.review_sha256, sources)
    plan, manifest, selection, report, saved, helper_report = [json.loads(paths[n].read_text())
        for n in ('plan', 'manifest', 'selection', 'crt_report', 'candidates', 'helpers')]
    require(plan['original_image_read'] is False and plan['allow_table_read'] is False and
            plan['original_table_bounds_approved'] is False and plan['runtime_provider_approved'] is False,
            'input is not the unadopted conditional plan')
    requests = [(r['stage'], r['begin_operand'], r['end_operand']) for r in plan['proposed_table_reads']]
    require(requests == EXACT_REQUESTS and plan['aggregate_proposed_bytes'] == EXACT_BYTES,
            'proposed range identity differs')
    require(report['detail_sha256'] == PINS['crt_details'], 'native ledger hash linkage differs')
    native, native_counts = native_catalog(paths['crt_details'])
    owners = Owners(selection['selections'], manifest)
    standard = standard_candidates(saved, helper_report)
    destination = Path(args.out_dir)
    require(not destination.exists(), 'output directory exists')
    destination.mkdir()
    def journal(state, **details):
        with (destination / 'progress.jsonl').open('a', encoding='utf-8') as stream:
            stream.write(json.dumps(dict(state=state, **details), separators=(',', ':')) + '\n')
            stream.flush()
            os.fsync(stream.fileno())
    requested, cells, summary, participation = 0, 0, {}, defaultdict(list)
    journal('started', expected_bytes=EXACT_BYTES, allow_execute=False)
    pe = None
    try:
        pe = Pe(paths['reference'])
        require(pe.base == 0x400000, 'image base differs')
        highlow = set(pe.relocations())
        with gzip.open(destination / 'cells.jsonl.gz', 'xt', encoding='utf-8') as stream:
            for stage, begin, end in EXACT_REQUESTS:
                counts = Counter()
                section = pe.section(begin - pe.base, end - begin + 4, required=True)
                require(not section['executable'], 'conditional interval enters executable section')
                for index, site in enumerate(range(begin, end + 4, 4)):
                    value = struct.unpack('<I', pe.read_rva(site - pe.base, 4))[0]
                    requested += 4
                    require(requested <= EXACT_BYTES, 'cell byte budget exceeded')
                    row = classify(value, site, site - pe.base in highlow,
                                   pe, owners, native, standard, site == end)
                    row.update(stage=stage, index=index, traversed_by_local_walker=site < end,
                        conditional_on_original_control_reaching_witness=True)
                    stream.write(json.dumps(row, separators=(',', ':')) + '\n')
                    cells += 1
                    counts['cells_including_end'] += 1
                    counts['traversed_cells'] += site < end
                    counts['null_cells'] += row['is_null']
                    counts['cells_with_issues'] += bool(row['issues'])
                    counts[row['domain']] += 1
                    counts['with_selected_source_candidates'] += bool(row['selected_code_owners'])
                    counts['with_native_CRT_candidates'] += bool(row['native_CRT_slot_candidates'])
                    counts['with_standard_CRT_candidates'] += bool(row['standard_CRT_candidates'])
                    if row['native_CRT_slot_candidates']:
                        participation[value].append(dict(stage=stage, index=index, original_site=site,
                                                         traversed=site < end))
                summary[stage] = dict(counts)
                journal('stage-complete', stage=stage, cells=cells, bytes=requested)
                require((destination / 'cells.jsonl.gz').stat().st_size <= MAX_OUTPUT, 'compressed output exceeds cap')
        require(requested == EXACT_BYTES, 'incomplete requested-byte coverage')
        for name, path in paths.items(): require(file_hash(path) == PINS[name], 'protected input changed: ' + name)
        require(source_manifest() == sources and file_hash(args.review) == args.review_sha256,
                'source or review changed')
        require((destination / 'cells.jsonl.gz').stat().st_size <= MAX_OUTPUT, 'compressed output exceeds cap')
        result = dict(schema_version=1, kind='fnv-conditional-crt-cell-classification', inputs=PINS,
            sources=sources, review_sha256=args.review_sha256, summary=summary,
            read_bytes=requested, cell_records=cells, native_census=native_counts,
            native_bound_targets_not_observed=[dict(original_target=target, native_slots=rows)
                for target, rows in native.items() if target not in participation],
            native_target_participation=[dict(original_target=target, cells=rows) for target, rows in participation.items()],
            details_sha256=file_hash(destination / 'cells.jsonl.gz'),
            original_code_read=False, executed=False, original_table_bounds_approved=False,
            original_startup_order_approved=False, whole_program_registration_approved=False,
            runtime_provider_approved=False,
            limits='Conditional operand-derived cell evidence only; nulls do not establish identity, stages or lifetime')
        encoded = json.dumps(result, separators=(',', ':'))
        require(len(encoded.encode('utf-8')) + (destination / 'cells.jsonl.gz').stat().st_size +
                (destination / 'progress.jsonl').stat().st_size + 1024 <= MAX_OUTPUT,
                'complete metadata output exceeds cap')
        with (destination / 'report.json').open('x', encoding='utf-8') as stream:
            stream.write(encoded)
        journal('completed', report_sha256=file_hash(destination / 'report.json'), cells=cells, bytes=requested)
        return dict(cells=cells, bytes=requested, original_code_read=False, runtime_provider_approved=False)
    except Exception:
        journal('failed-or-unknown', cells=cells, bytes=requested, complete=False)
        raise
    finally:
        if pe is not None: pe.close()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    for name in list(PINS) + ['review', 'review_sha256', 'out_dir']:
        parser.add_argument('--' + name.replace('_', '-'), required=True)
    print(json.dumps(run(parser.parse_args()), sort_keys=True))


if __name__ == '__main__': main()
