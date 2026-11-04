"""Metadata-only ordered registration proposals; no C++, provider or execution.

Joins every saved conditional cell to the complete PLANNED physical namespace.
Nulls, unknowns and repeated targets retain their original slots. The output
cannot authorize generation or runtime registration, even for a matching name.
"""
from __future__ import annotations
import argparse
from collections import Counter, defaultdict
import gzip
import hashlib
import json
from pathlib import Path
import re

ROOT = Path(__file__).resolve().parents[2]
PINS = dict(report='1b55e12d7183c9ecba055bffac0f6b422b90dd07a978604edf2f56d200188dc5',
    cells='a64baec56c7d9ce887ef8b74971390e490c680cb95ed0a4b5dc42225c985ef12',
    providers='6cd5bf884bb28d460cfc92f63b765c15413904f58355844243ddd6b59b97001c')
RANGES = [('xi', 0x010113c4, 0x010113e8), ('xc', 0x00fdf4a4, 0x010113c0),
          ('xp', 0x010113f4, 0x01011400), ('xt', 0x01011404, 0x01011408)]


def require(value, reason):
    if not value: raise ValueError(reason)


def file_hash(path):
    digest = hashlib.sha256()
    with Path(path).open('rb') as stream:
        for part in iter(lambda: stream.read(1024 * 1024), b''): digest.update(part)
    return digest.hexdigest()


def source_manifest():
    return {name: file_hash(ROOT / name) for name in ('tools/rebuild/game_crt_registration_plan.py',
        'tests/rebuild/test_game_crt_registration_plan.py', 'tools/rebuild/runtime_code_pool.py')}


def canonical(identity):
    require(set(identity) == {'recipe_id', 'object_sha256', 'symbol_index'} and
        isinstance(identity['recipe_id'], str) and re.fullmatch('[0-9a-f]{64}', identity['object_sha256']) and
        type(identity['symbol_index']) is int and identity['symbol_index'] >= 0, 'invalid physical identity')
    return '_fnv_code_' + hashlib.sha256(json.dumps(identity, sort_keys=True, separators=(',', ':')).encode()).hexdigest()


def provider_proposal(owner, provider):
    require(owner['offset'] == 0, 'source-code interior is not a registration entry')
    for key in ('recipe_id', 'object_sha256', 'source_sha256', 'symbol'):
        require(owner[key] == provider[key], 'physical provider join differs: ' + key)
    require(owner['native_section'] == provider['section'] and owner['native_value'] == provider['value'] and
        owner['original_end'] - owner['original_entry'] == provider['size'], 'native span join differs')
    identity = {key: provider[key] for key in ('recipe_id', 'object_sha256', 'symbol_index')}
    name = canonical(identity)
    require(name == provider['planned_canonical_name'], 'canonical identity/name mismatch')
    return dict(physical_identity=identity, planned_COFF_name=name, proposed_C_identifier=name[1:],
        source_signature_spelling_void_cdecl_noargs=owner['symbol'].endswith('@@YAXXZ'),
        callback_ABI_approved=False, materialized_export_verified=False,
        runtime_provider_approved=False)


def plan_cell(cell, providers):
    stage = cell['stage']
    row = dict(stage=stage, index=cell['index'], original_site=cell['original_site'],
        original_target_va=cell['original_target_va'], is_null=cell['is_null'],
        is_named_end_cell=cell['is_named_end_cell'], classification_issues=cell['issues'],
        ordered_invocation_conditional=True, namespace_proposal=None,
        allow_source_emission=False, allow_registration=False, runtime_provider_approved=False)
    if cell['is_named_end_cell']:
        row['action'] = 'BOUNDARY_OBSERVATION_NOT_DISPATCHED'
    elif cell['is_null']:
        row['action'] = 'SKIP_NULL_IF_LOCAL_WALKER_PATH_IS_REACHED'
    else:
        row['expected_callback_signature_from_local_stage'] = 'int __cdecl(void)' if stage == 'xi' else 'void __cdecl(void)'
        owners = cell['selected_code_owners']
        if stage == 'xc' and len(owners) == 1 and owners[0]['offset'] == 0:
            owner = owners[0]
            key = '0x%08x' % cell['original_target_va']
            require(key in providers, 'selected entry absent from planned physical namespace')
            proposal = provider_proposal(owner, providers[key])
            row['namespace_proposal'] = proposal
            row['action'] = 'PROPOSE_EXACT_SOURCE_ENTRY_PENDING_ALL_RUNTIME_GATES'
            row['requires_explicit_registration_beyond_native_XCU'] = not bool(cell['native_CRT_slot_candidates'])
            row['unresolved_gates'] = ['callable ABI', 'actual export/closure', 'DATA extent and lifetime',
                'EH/CRT compatibility', 'original runtime-owned interleaving', 'fresh CRT placement',
                'single root and native-XCU duplicate suppression']
        else:
            row['action'] = 'UNRESOLVED_CALLBACK_NO_ALIAS_OR_STUB'
            row['source_candidates'] = owners
            row['standard_CRT_candidates'] = cell['standard_CRT_candidates']
    return row


def check_provider_map(document):
    require(document['provider_identity_is_planned_namespace'] is True and document['materialized_exports'] == 0,
            'map is not the original planned-only namespace')
    require(all(document[name] is False for name in ('provider_selected', 'runtime_eligible',
        'ABI_verified', 'materialization_approved', 'link_ready', 'namespace_approved')),
        'planned namespace input carries unexpected adoption')


def run(args):
    paths = {name: Path(getattr(args, name)) for name in PINS}
    sources = source_manifest()
    for name, path in paths.items(): require(file_hash(path) == PINS[name], 'input differs: ' + name)
    report, namespace = [json.loads(paths[name].read_text()) for name in ('report', 'providers')]
    check_provider_map(namespace)
    require(report['details_sha256'] == PINS['cells'] and report['original_code_read'] is False and
            report['runtime_provider_approved'] is False and report['original_table_bounds_approved'] is False,
            'conditional classifier state differs')
    destination = Path(args.out_dir)
    require(not destination.exists(), 'output directory exists')
    destination.mkdir()
    counts, per_stage, callback_targets = Counter(), defaultdict(Counter), set()
    try:
        with gzip.open(paths['cells'], 'rt') as original, gzip.open(destination / 'entries.jsonl.gz', 'xt') as output:
            for stage, begin, end in RANGES:
                for index, site in enumerate(range(begin, end + 4, 4)):
                    cell = json.loads(next(original))
                    require((cell['stage'], cell['index'], cell['original_site'], cell['is_named_end_cell']) ==
                        (stage, index, site, site == end), 'conditional cell stage/slot order differs')
                    row = plan_cell(cell, namespace['providers'])
                    output.write(json.dumps(row, separators=(',', ':')) + '\n')
                    counts[row['action']] += 1
                    per_stage[stage][row['action']] += 1
                    if row['namespace_proposal']:
                        counts['planned_canonical_source_entries'] += 1
                        counts['without_native_XCU_contribution'] += row['requires_explicit_registration_beyond_native_XCU']
                        counts['void_cdecl_noargs_spelling'] += row['namespace_proposal']['source_signature_spelling_void_cdecl_noargs']
                    if not cell['is_null'] and not cell['is_named_end_cell']:
                        if cell['original_target_va'] in callback_targets: counts['repeated_nonnull_target_slots'] += 1
                        callback_targets.add(cell['original_target_va'])
            require(next(original, None) is None, 'extra conditional cell records')
        for name, path in paths.items(): require(file_hash(path) == PINS[name], 'input changed: ' + name)
        require(source_manifest() == sources, 'source changed')
        result = dict(schema_version=1, kind='fnv-fresh-crt-registration-plan', status='proposal-only',
            sources=sources, inputs=PINS, counts=dict(counts), per_stage={k: dict(v) for k, v in per_stage.items()},
            details_sha256=file_hash(destination / 'entries.jsonl.gz'),
            native_bound_targets_not_observed_in_candidate_intervals=report['native_bound_targets_not_observed'],
            non_observation_does_not_exclude_registration_or_delete_code=True,
            architecture=['One independently reviewed fresh normal CRT owns security/TLS/C state and exit registry',
                'Do not copy original XI/XP/XT state or replay normal CRT callbacks by old addresses',
                'Resolve every unknown XC and XI/XP callback into source/runtime-owned roles before choosing placement',
                'Review runtime-owned interleaving against actual fresh linked tables before selecting one or multiple game dispatcher roots',
                'Source-authored CRT roots reference exact canonical source entries in preserved original slot order, never numeric original addresses',
                'Require reviewed duplicate-root/native-XCU plans; candidate-range absence does not authorize a general startup exclusion',
                'Do not adopt unbound variants, omit unknown callbacks or create no-op stubs',
                'Game initializer bodies retain their own registrations to the same fresh atexit registry; never synthesize a reversed destructor list'],
            actual_initializer_execution=False, source_or_COFF_emitted=False, allow_registration=False,
            original_startup_order_approved=False, runtime_provider_approved=False)
        with (destination / 'report.json').open('x') as output: json.dump(result, output, separators=(',', ':'))
        return dict(counts=dict(counts), runtime_provider_approved=False, emitted=False)
    except Exception:
        with (destination / 'failed.json').open('x') as output:
            json.dump(dict(status='failed', counts=dict(counts), allow_registration=False), output)
        raise


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    for name in list(PINS) + ['out_dir']: parser.add_argument('--' + name.replace('_', '-'), required=True)
    print(json.dumps(run(parser.parse_args()), sort_keys=True))


if __name__ == '__main__': main()
