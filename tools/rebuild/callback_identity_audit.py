"""Exact saved-metadata joins for 547 conditional callbacks; no image access.

Preserves every ordinary/EH/native/model overlap and unresolved role. Builds a
finite *proposed* XI/XP named-library probe grid; there is no original-code
reader or execution route in this module.
"""
from __future__ import annotations
import argparse
import bisect
from collections import Counter, defaultdict
import gzip
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
PINS = dict(cells='a64baec56c7d9ce887ef8b74971390e490c680cb95ed0a4b5dc42225c985ef12',
    selection='48ae62cdc5b1754b9c4af674ef4716d53afb554882e174a93acf860eaf1c6cb1',
    recipes='62f2c8da5f0daa912abdf4576328706711c6561eef7f01c93a89cb71ad46fb6c',
    manifest='bc62a5fb2553431b1e0547d11f366e52efb73096ea8ceb206c556ae5740a53eb',
    retained='04d44b73e81982f846bfe8d81806db72ea669586b579ff22007dfd6f7d831297',
    native='1dd38beb7dc802c3ca5ab56f23862e24c83f0141c9dce6a733eb18105db75929',
    core='f268c8d3ebd5cd305b022c6b0bec3dc40d1709ec862e1a942ba71733c6d3df7c',
    helpers='46a32adedeed001defb64c68ef59a1df6ba4506c8ce0f5b85bb04d890ad005df',
    binding='4dfc437064b16c1bb933008aebf7def8d279a903eef9cca24d0fedcc12d7d826',
    roster='12e5fd6111af319026fe20b027d5ba016f9e929ea9b1f6990927c50cfd92e463')


def require(value, message):
    if not value: raise ValueError(message)


def sha(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as stream:
        for part in iter(lambda: stream.read(1024 * 1024), b''): h.update(part)
    return h.hexdigest()


def source_manifest():
    return {n: sha(ROOT / n) for n in ('tools/rebuild/callback_identity_audit.py',
                                     'tests/rebuild/test_callback_identity_audit.py')}


class Intervals:
    def __init__(self, rows):
        self.rows = sorted(rows, key=lambda row: (row[0], row[1]))
        self.starts = [row[0] for row in self.rows]
        self.ends, top = [], -1
        for lo, hi, _ in self.rows:
            require(0 <= lo < hi <= 0x100000000, 'invalid saved interval')
            top = max(top, hi)
            self.ends.append(top)

    def at(self, target):
        index = bisect.bisect_right(self.starts, target) - 1
        result = []
        while index >= 0 and self.ends[index] > target:
            lo, hi, record = self.rows[index]
            if lo <= target < hi:
                result.append(dict(record, original_start=lo, original_end=hi,
                    offset=target - lo, relation='entry' if target == lo else 'interior',
                    callable_identity_approved=False, runtime_provider_approved=False))
            index -= 1
        return list(reversed(result))


def probe_candidates(roster, stage):
    """Keep every native origin; deduplicate only exact physical definitions."""
    result = {}
    prefix = '.CRT$XI' if stage == 'xi' else '.CRT$XP'
    for family, data in roster['families'].items():
        for slot in data['records']:
            if not slot['category'].startswith(prefix) or slot['kind'] != 6 or slot['addend'] != 0:
                continue
            for definition in slot['native_definition_candidates']:
                if definition['errors']: continue
                key = (family, definition['member_header_offset'], definition['symbol_index'],
                       definition['section'], definition['value'], definition['section_size'])
                identity = hashlib.sha256(json.dumps(key, separators=(',', ':')).encode()).hexdigest()
                if key not in result:
                    result[key] = dict(candidate_id=identity, family=family,
                        symbol=slot['target_symbol'], definition=definition, native_origin_slots=[],
                        original_identity_verified=False, runtime_provider_approved=False)
                result[key]['native_origin_slots'].append({k: slot[k] for k in
                    ('member_header_offset', 'member_name', 'member_sha256', 'category', 'section', 'offset')})
    return list(result.values())


def make_probe_plan(callbacks, roster):
    candidates = {stage: probe_candidates(roster, stage) for stage in ('xi', 'xp')}
    reads, budget = [], 0
    for callback in callbacks:
        stage = callback['stage']
        if stage not in candidates: continue
        definitions = candidates[stage]
        require(definitions, 'no legitimate named native CRT contribution candidates')
        target = callback['original_target_va']
        starts = [target - d['definition']['value'] for d in definitions]
        ends = [start + d['definition']['section_size'] for start, d in zip(starts, definitions)]
        lo, hi = min(starts), max(ends)
        require(0x00401000 <= lo < hi <= 0x00401000 + 12440971, 'finite candidate window outside pinned text')
        budget += hi - lo
        reads.append(dict(stage=stage, original_target=target, start=lo, end=hi, bytes=hi - lo,
            candidate_ids=[d['candidate_id'] for d in definitions], source_role_only=True))
    require(len(reads) == 10 and budget <= 64 * 1024, 'finite candidate-read budget differs')
    return dict(candidates=candidates, reads=reads, aggregate_original_bytes=budget,
        original_callback_targets=10, allow_original_read=False, allow_recursive_probes=False,
        candidate_only=True, XC_targets_in_probe_scope=0, runtime_provider_approved=False)


def run(args):
    paths = {name: Path(getattr(args, name)) for name in PINS}
    sources = source_manifest()
    for name, path in paths.items(): require(sha(path) == PINS[name], 'input differs: ' + name)
    require(not Path(args.out).exists(), 'output exists')
    recipes, manifest, selections, retained, core, helpers, roster = [json.loads(paths[name].read_text())
        for name in ('recipes', 'manifest', 'selection', 'retained', 'core', 'helpers', 'roster')]
    callbacks = []
    with gzip.open(paths['cells'], 'rt') as stream:
        for ordinal, line in enumerate(stream):
            row = json.loads(line)
            if not row['is_null'] and not row['selected_code_owners']:
                callbacks.append(dict(row, original_cell_ordinal=ordinal))
    require(Counter(row['stage'] for row in callbacks) == dict(xc=537, xi=8, xp=2), '547 population differs')
    targets = {row['original_target_va'] for row in callbacks}
    ordinary, tails, pieces, models, recipe_names = [], [], [], [], defaultdict(list)
    for address, row in selections['selections'].items():
        unit = manifest['units'][row['recipe_index']]
        require(row['recipe_id'] == unit['recipe_id'], 'selected recipe identity differs')
        lo = int(address, 16)
        ordinary.append((lo, lo + row['size'], dict(kind='selected-ordinary', **row,
            object_sha256=unit['object_sha256'], source_sha256=unit['source_sha256'])))
    for index, unit in enumerate(recipes['units']):
        for ordinal, tail in enumerate(unit.get('eh_tails', [])):
            lo = int(tail['address'], 16)
            tails.append((lo, lo + tail['size'], dict(kind='listed-EH-span', recipe_index=index,
                tail_ordinal=ordinal, recipe_id=manifest['units'][index]['recipe_id'], tail=tail)))
        for name, address in unit['symbols'].items():
            if int(address, 16) in targets: recipe_names[int(address, 16)].append(dict(recipe_index=index, symbol=name))
        for function in unit['functions']:
            if int(function['address'], 16) in targets:
                recipe_names[int(function['address'], 16)].append(dict(recipe_index=index, function=function))
    for unit in retained['units']:
        for ordinal, piece in enumerate(unit.get('eh_sections', [])):
            pieces.append((piece[0], piece[1], dict(kind='retained-EH-piece', recipe_id=unit['recipe_id'],
                piece_ordinal=ordinal, match=piece[2], parent=piece[3], diagnostics=piece[4])))
    require(len(ordinary) == 68657 and len(tails) == 1954 and len(pieces) == 12429, 'saved span population differs')
    for observation in core['observations']:
        contract = next(c for c in core['contracts'] if c['identity'] == observation['identity'])
        for candidate in observation['candidates']:
            models.append((candidate['address'], candidate['address'] + contract['size'],
                dict(kind='standard-CRT-source-model', identity=observation['identity'], named_target=candidate['address'],
                    fixed_span_equal=candidate['full_nonrelocation_span_equal'])))
    for candidate in helpers['observations']:
        lo = candidate['section_start_candidate']
        models.append((lo, lo + candidate['size'], dict(kind='standard-CRT-helper-model', identity=candidate['symbol'],
            named_target=candidate['target_candidate'], fixed_span_equal=candidate['full_nonrelocation_span_equal'])))
    indexes = {name: Intervals(rows) for name, rows in [('ordinary', ordinary), ('listed_EH', tails),
        ('retained_EH_piece', pieces), ('standard_CRT_model', models)]}
    native, unbound_native = defaultdict(list), 0
    with gzip.open(paths['native'], 'rt') as stream:
        for ordinal, line in enumerate(stream):
            unit = json.loads(line)
            require(unit['recipe_index'] == ordinal, 'native ledger coverage differs')
            for section in unit['sections']:
                for slot in section['relocations']:
                    if slot['original_target_candidate'] is None: unbound_native += 1
                    elif slot['original_target_candidate'] in targets:
                        native[slot['original_target_candidate']].append(dict(recipe_id=unit['recipe_id'],
                            section=section['index'], offset=slot['offset'], slot=slot))
    require(unbound_native == 4260, 'unbound native population differs')
    field_refs, incoming, field_rows = defaultdict(list), defaultdict(list), 0
    startup_targets = {0x00eccd14: '__cinit-candidate', 0x00eccd99: '_doexit-candidate',
                       0x0086a850: 'application-entry-candidate'}
    for role in startup_targets.values(): incoming[role] = []
    with gzip.open(paths['binding'], 'rt') as stream:
        for ordinal, line in enumerate(stream):
            row = json.loads(line)
            field_rows += 1
            value = row.get('exact_original_target_va')
            if value is None: continue
            value = int(value, 16)
            if value in targets: field_refs[value].append(dict(binding_row_ordinal=ordinal, record=row))
            if value in startup_targets: incoming[startup_targets[value]].append(dict(binding_row_ordinal=ordinal, record=row))
    require(field_rows == 490801, 'complete binding-field ledger coverage differs')
    counts, records = Counter(), []
    for callback in callbacks:
        target = callback['original_target_va']
        joins = {name: index.at(target) for name, index in indexes.items()}
        record = dict(stage=callback['stage'], index=callback['index'], original_site=callback['original_site'],
            original_cell_ordinal=callback['original_cell_ordinal'], original_target_va=target,
            maps=joins, exact_recipe_names=recipe_names[target], native_bound_slot_candidates=native[target],
            selected_field_references=field_refs[target], role='UNRESOLVED_CONDITIONAL_CALLBACK',
            callback_ABI_approved=False, startup_membership_approved=False, runtime_provider_approved=False)
        for name, rows in joins.items(): counts[name + '_joined_targets'] += bool(rows)
        records.append(record)
    proposed = make_probe_plan(callbacks, roster)
    for name, path in paths.items(): require(sha(path) == PINS[name], 'input changed: ' + name)
    require(source_manifest() == sources, 'source changed')
    result = dict(schema_version=1, kind='fnv-conditional-callback-identity-audit', sources=sources,
        inputs=PINS, summary=dict(callbacks=547, stages=dict(Counter(r['stage'] for r in callbacks)),
            unique_targets=len(targets), matched_EH_pieces=sum(piece[2]['match'] for piece in pieces),
            unbound_native_slots_without_addresses=unbound_native, binding_records=field_rows, **dict(counts)),
        callbacks=records, incoming_selected_field_evidence=dict(incoming),
        retained_EH_diagnostic_notes=[dict(recipe_id=u['recipe_id'], diagnostics=u['eh_errors'])
            for u in retained['units'] if u.get('eh_errors')], proposed_CRT_probe_plan=proposed,
        startup_hypothesis=dict(local_named_native_traversal_models_match=True,
            original_caller_reachability_proven=False, whole_original_startup_path_proven=False,
            candidate_wrong_bounds_or_unused_path_hypothesis_excluded=False,
            basis='Conditional typed native call/leaf-walker operand evidence; never pointer shape or source-name agreement',
            fresh_source_normal_CRT_fixture_is_separate=True),
        original_image_read=False, callback_identity_closed=False, original_table_bounds_approved=False,
        source_or_provider_emitted=False, runtime_provider_approved=False)
    with Path(args.out).open('x') as output: json.dump(result, output, separators=(',', ':'))
    return dict(summary=result['summary'], proposed_original_bytes=proposed['aggregate_original_bytes'], original_image_read=False)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    for name in list(PINS) + ['out']: parser.add_argument('--' + name, required=True)
    print(json.dumps(run(parser.parse_args()), sort_keys=True))


if __name__ == '__main__': main()
