"""Saved-evidence correspondence for all 547 callbacks; no image/native reads.

Named CRT source-body matches are distinguished from approved identities and
from the 537 XC gaps. Scoped relocation observations remain unproved roles.
"""
from __future__ import annotations
import argparse
from collections import Counter, defaultdict
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
PINS = dict(audit='4c3232a5cf35ec00055edfb4a35e383732a30a93aa4c5b5cf0138a49d60f89f9',
    c_probe='290c279d409029dec63dc4d8a6a4ccbb4a34afb7c7c3dcf3240f7543595c5525',
    cpp_probe='1af59369361c6dd4b9d508bb0dfcf564208b20ad556fc038b01b76d95b940e73',
    cpp_catalog='3e1b57b2407d422f157ebe2904c024bb7c3f1a501fe7c9aa10cded84d6e6fbf9')


def require(value, message):
    if not value: raise ValueError(message)


def sha(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as stream:
        for part in iter(lambda: stream.read(1024 * 1024), b''): h.update(part)
    return h.hexdigest()


def source_manifest():
    return {n: sha(ROOT / n) for n in ('tools/rebuild/callback_correspondence.py',
                                     'tests/rebuild/test_callback_correspondence.py')}


def linkage_key(candidate, relocation):
    """External names are consistency hypotheses; statics/literals stay physical."""
    definition = candidate['definition']
    name = relocation['symbol']
    if relocation['symbol_storage'] == 2 and not name.startswith(('??_C@', '__real@', '$SG')):
        return (candidate['family'], 'external-name-consistency-only', name)
    return (candidate['family'], 'physical-local-or-literal', definition['member_header_offset'],
            definition['member_sha256'], relocation['symbol_index'])


def classify_callback(callback, comparisons):
    positives = [r for r in comparisons if r['full_nonrelocation_span_equal']]
    names = sorted({r['symbol'] for r in positives})
    return dict(callback, native_source_symbols=names,
        classification='NAMED_NATIVE_BODY_CORRESPONDENCE' if len(names) == 1 else
            'AMBIGUOUS_NATIVE_BODY_CORRESPONDENCE' if names else 'NO_SAVED_SOURCE_BODY_CORRESPONDENCE',
        matching_profiles=positives, original_function_identity_approved=False,
        relocation_identities_closed=False, callback_ABI_approved=False,
        original_startup_membership_approved=False, runtime_provider_approved=False)


def run(args):
    paths = {n: Path(getattr(args, n)) for n in PINS}
    sources = source_manifest()
    for name, path in paths.items(): require(sha(path) == PINS[name], 'input differs: ' + name)
    audit, c_probe, cpp_probe, cpp_catalog = [json.loads(paths[n].read_text())
        for n in ('audit', 'c_probe', 'cpp_probe', 'cpp_catalog')]
    require(c_probe['runtime_provider_approved'] is False and cpp_probe['runtime_provider_approved'] is False,
            'probe adoption flags differ')
    candidate_catalog = {c['candidate_id']: c for values in audit['proposed_CRT_probe_plan']['candidates'].values() for c in values}
    candidate_catalog.update({c['candidate_id']: dict(c, native_origin_slots=[c['native_origin_slot']])
                             for c in cpp_catalog['candidates']})
    by_target = defaultdict(list)
    for row in c_probe['observations']: by_target[row['original_target']].extend(row['comparisons'])
    by_target[cpp_probe['original_target']].extend(cpp_probe['comparisons'])
    result_rows, bindings, category_order = [], defaultdict(list), defaultdict(list)
    counts = Counter()
    for callback in audit['callbacks']:
        target = callback['original_target_va']
        comparisons = by_target[target]
        row = classify_callback(callback, comparisons)
        counts[row['classification']] += 1
        categories = set()
        for positive in row['matching_profiles']:
            native = candidate_catalog[positive['candidate_id']]
            categories.update(slot['category'] for slot in native['native_origin_slots'])
            for relocation in positive['relocation_observations']:
                bindings[linkage_key(native, relocation)].append(dict(
                    callback_target=target, native_symbol=positive['symbol'],
                    candidate_id=positive['candidate_id'], relocation=relocation,
                    independent_symbol_identity_verified=False))
        row['native_contribution_categories'] = sorted(categories)
        if categories:
            category_order[callback['stage']].append(dict(index=callback['index'], target=target,
                symbols=row['native_source_symbols'], native_categories=sorted(categories)))
        result_rows.append(row)
    groups = []
    for key, records in bindings.items():
        values = sorted({r['relocation']['original_symbol_base_candidate'] for r in records})
        groups.append(dict(scoped_key=list(key), observed_original_targets=values,
            consistent_numeric_target=len(values) == 1, observations=records,
            role_or_provider_identity_approved=False))
    sequences = {}
    for stage, rows in category_order.items():
        ordered = sorted(rows, key=lambda row: row['index'])
        singleton = all(len(row['native_categories']) == 1 for row in ordered)
        labels = [row['native_categories'][0] for row in ordered] if singleton else []
        sequences[stage] = dict(rows=ordered, singleton_category_labels=singleton,
            observed_labels=labels, nondecreasing_native_category_labels=singleton and labels == sorted(labels),
            labels_do_not_derive_original_order=True, original_reachability_approved=False)
    require(len(result_rows) == 547 and Counter(r['stage'] for r in result_rows) == dict(xc=537, xi=8, xp=2),
            'callback coverage differs')
    for name, path in paths.items(): require(sha(path) == PINS[name], 'input changed: ' + name)
    require(source_manifest() == sources, 'source changed')
    require(not Path(args.out).exists(), 'output exists')
    result = dict(schema_version=1, kind='fnv-conditional-callback-correspondence', sources=sources,
        inputs=PINS, counts=dict(counts), callbacks=result_rows, scoped_binding_consistency=groups,
        stage_native_category_correspondence=sequences,
        remaining_XC_targets=[r['original_target_va'] for r in result_rows if r['stage'] == 'xc' and not r['native_source_symbols']],
        evidence_scope='Exact saved native-body/nonrelocation/field-geometry evidence only; no new original reads',
        original_image_read=False, original_code_search_performed=False, runtime_provider_approved=False,
        callback_function_identity_approved=False, original_startup_reachability_proven=False,
        original_table_bounds_approved=False, wrong_bounds_or_unused_path_hypothesis_excluded=False,
        source_or_registration_emitted=False)
    with Path(args.out).open('x') as output: json.dump(result, output, separators=(',', ':'))
    return dict(callbacks=547, classifications=dict(counts), scoped_binding_groups=len(groups),
                inconsistent_numeric_groups=sum(not r['consistent_numeric_target'] for r in groups),
                original_image_read=False, runtime_provider_approved=False)


def main():
    p = argparse.ArgumentParser(description=__doc__)
    for n in list(PINS) + ['out']: p.add_argument('--' + n.replace('_', '-'), required=True)
    print(json.dumps(run(p.parse_args()), sort_keys=True))


if __name__ == '__main__': main()
