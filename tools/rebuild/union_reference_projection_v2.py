"""Explicitly gated native-COFF collection and unresolved V2 CODE projection.

Python readers/unchanged comparison only. No compiler, native tool, executable
link, child process, source edit, old-writer patch or automatic retry exists.
"""
from __future__ import annotations
import argparse
from collections import Counter
import gzip
import importlib
import json
import os
from pathlib import Path
import sys
import time
import application_entry_projection as entry
import bulk_code_pool as bulk
import coff_code_archive as coff
import union_reference_groups_v2 as groups

ROOT = Path(__file__).resolve().parents[2]
POLICY = 'operational-union-reference-projection-v2'
OWNED = ('tools/rebuild/union_reference_projection_v2.py', 'tests/rebuild/test_union_reference_projection_v2.py',
         'runtime/code-pools/union-reference-projection-v2.json', 'docs/rebuild/UNION-REFERENCE-PROJECTION-V2.md')
OBSERVATION_PIN = 'f4d1d9ef95f30d664b10ee478d19b4030375b1c5af53b7bb07b41f21116a75c5'
DETAIL_PIN = '20626863590bfe069731fac18affe05622ca2d0524d9d66facb820beeeecca94'
BOX = '2089-51b16ad19e044300'
FALSE = dict(provider_selected=False, runtime_eligible=False, ABI_verified=False, link_ready=False,
             materialization_approved=False, native_tools_run=False, compiler_performed=False,
             executable_linked=False, game_engine_executed=False)
sha = groups.pool.file_hash
require = coff.require


def load_json(path): return json.loads(Path(path).read_text(encoding='utf-8'))


def stable(observations, repository=ROOT):
    require(not (Path(repository) / 'build/function_index.json').exists(), 'current optional index must remain absent')
    require(all(sha(path) == value for path, value in observations.items()), 'protected input/producer/source changed')


def loaded_producers(policy):
    for relative in policy['producer_sha256']:
        module = sys.modules.get(Path(relative).stem)
        if module is not None:
            require(Path(module.__file__).resolve() == ROOT / relative, 'unexpected loaded producer dependency')


def save_json(path, value):
    with Path(path).open('x', encoding='utf-8') as target:
        json.dump(value, target, sort_keys=True, separators=(',', ':')); target.write('\n'); target.flush(); os.fsync(target.fileno())


def phase_gate(args, policy, sources, observation):
    require(args.authorize_coff_read, 'actual COFF collection requires explicit root opt-in')
    require(args.operation in ('collect', 'project') and args.profile == 'box2089',
            'only exact Box operational profile is reviewed; all185 requires later artifact-bound source delta')
    require(args.operation != 'project' or args.authorize_private_emission, 'private projection requires explicit root opt-in')
    require(sha(args.review) == args.review_sha256, 'stale phase/source review')
    review = load_json(args.review)
    operation = args.operation + '-' + args.profile
    require(review.get('schema_version') == 1 and review.get('kind') == 'union-reference-operational-phase-review-v2' and
            review.get('status') == 'approved' and review.get('reviewer') and review.get('root_authorized') is True and
            operation in review.get('allowed_operations', []) and review.get('sources') == sources and
            review.get('producer_sha256') == policy['producer_sha256'] and
            review.get('metadata_observation_sha256') == OBSERVATION_PIN and
            review.get('metadata_details_sha256') == DETAIL_PIN and review.get('allow_native_tools') is False and
            review.get('allow_executable_link') is False, 'unapproved operational source/profile/evidence')
    candidates = observation['candidate_recipe_ids']
    require(len(candidates) == len(set(candidates)) == 185 and BOX in candidates, 'finite candidate set differs')
    wanted = [BOX]
    require(review.get('recipe_ids') == wanted, 'phase does not authorize the exact whole recipe/root set')
    return wanted


def collect_recipe(original_path, source_path, metadata, providers, observations, activity=None):
    """Only called after operational gate. Exactly one named source object read."""
    plan = metadata['plan']; provenance = metadata['provenance']
    activity = {} if activity is None else activity
    observations[Path(source_path)] = plan['source_sha256']; observations[Path(original_path)] = plan['object_sha256']
    activity['source_hash_attempted'] = True
    require(sha(source_path) == plan['source_sha256'], 'current source differs from lineage')
    activity['native_object_access_attempted'] = True
    require(Path(original_path).stat().st_size <= 16 * 1024 * 1024, 'native object exceeds bounded reader limit')
    require(sha(original_path) == plan['object_sha256'], 'native object differs from lineage')
    raw = Path(original_path).read_bytes()
    activity['native_object_bytes_read'] = len(raw)
    require(coff.digest(raw) == plan['object_sha256'], 'native object changed while reading')
    certificate = groups.certify_union(raw, metadata['contracts'], plan, providers, provenance)
    return raw, certificate


def project_recipe(raw, original_path, metadata, providers, certificate, stage_path, recovered_path):
    """No comparator bypass: this core only projects/reparses; driver compares."""
    output, projected = groups.serialize_union_v2(raw, metadata['contracts'], metadata['plan'], providers, certificate)
    require(len(output) <= 16 * 1024 * 1024, 'projected member exceeds bounded reader limit')
    with Path(stage_path).open('xb') as target:
        target.write(output); target.flush(); os.fsync(target.fileno())
    expected = dict(original_object_sha256=coff.digest(raw), member_sha256=coff.digest(output), mapping=projected['maps'])
    independent = entry.independent_projection(original_path, stage_path, certificate, expected)
    # Recovered bytes are filled from the actual spool/archive later, not this copy.
    require(not Path(recovered_path).exists(), 'exclusive recovered path required')
    return output, projected, independent, expected


def recover_and_verify_archive(path, members, source_by_name, certificate_by_name, expectation_by_name, output_dir):
    verified = bulk.verify_shard(path, members)
    layout = bulk.archive_layout(members)
    facts = []
    # The frozen verifier already walked both indices, headers and padding.
    # Recover one exact verified member at a time; never read a whole shard.
    with Path(path).open('rb') as archive:
        for offset, expected_member in zip(layout['offsets'], members):
            name = expected_member['name']; length = expected_member['length']
            require(length <= 16 * 1024 * 1024, 'recovered member exceeds bounded reader limit')
            archive.seek(offset + 60); payload = archive.read(length)
            require(len(payload) == length and coff.digest(payload) == expected_member['sha256'], 'archive recovered payload differs')
            target = Path(output_dir) / (name + '.recovered')
            with target.open('xb') as out: out.write(payload); out.flush(); os.fsync(out.fileno())
            facts.append(dict(member=name, **entry.independent_projection(source_by_name[name], target,
                certificate_by_name[name], expectation_by_name[name])))
    return dict(**verified, independent_recovered_members=facts)


def write_coverage(path, original_coverage, certificates, emitted):
    counts = Counter(); seen = set()
    with Path(path).open('xb') as target:
        with gzip.GzipFile(fileobj=target, mode='wb', mtime=0) as zipped:
            for ordinal, row in groups.saved_records(original_coverage):
                address = row['original_address']; require(address not in seen, 'duplicate original owner'); seen.add(address)
                require(row['status'] in ('EMITTED', 'HISTORICAL_BLOCKED', 'BLOCKED_UNION'), 'unexpected upstream coverage state')
                status = ('V2_NEWLY_PROJECTED' if address in emitted else 'V2_NATIVE_CERTIFICATE_OBSERVED' if address in certificates else
                          'UPSTREAM_EMITTED_UNCHANGED' if row['status'] == 'EMITTED' else
                          'UPSTREAM_HISTORICAL_BLOCKED' if row['status'] == 'HISTORICAL_BLOCKED' else 'UPSTREAM_UNION_BLOCKED_NOT_EMITTED')
                counts[status] += 1
                record = dict(original_address=address, status=status, original_status=row['status'],
                    original_coverage_row=dict(ordinal=ordinal, sha256=groups.digest(row)),
                    physical_identity=row['physical_identity'], original_missing_or_blocker_evidence_preserved=True, **FALSE)
                zipped.write(bulk.canonical(record) + b'\n')
        target.flush(); os.fsync(target.fileno())
    require(len(seen) == sum(counts.values()) == 68657, 'complete original coverage differs')
    return dict(counts)


def run(args):
    require(args.authorize_coff_read, 'actual COFF collection requires explicit root opt-in')
    require(sha(args.policy) == args.policy_sha256, 'stale policy')
    policy = load_json(args.policy); require(policy['policy_id'] == POLICY, 'wrong operational policy')
    sources = {relative: sha(ROOT / relative) for relative in OWNED}
    require(args.policy_sha256 == sources[OWNED[2]], 'policy is not reviewed owned policy')
    paths = {key: Path(value).resolve() for key, value in load_json(args.inputs).items()}
    require(set(paths) == set(groups.INPUT_PINS) | {'metadata_observation', 'metadata_details'}, 'exact operational input set required')
    observations = {ROOT / relative: value for relative, value in sources.items()}
    observations.update({args.policy.resolve(): args.policy_sha256, args.inputs.resolve(): sha(args.inputs),
                         args.review.resolve(): args.review_sha256})
    for relative, value in policy['producer_sha256'].items():
        path = ROOT / relative; require(sha(path) == value, 'stale operational producer ' + relative); observations[path] = value
    for module in (entry, entry.references, bulk, coff, groups, groups.pool, groups.bulk.inventory):
        relative = 'tools/rebuild/' + Path(module.__file__).name
        require(Path(module.__file__).resolve() == ROOT / relative and relative in policy['producer_sha256'],
                'unexpected imported operational dependency')
    loaded_producers(policy)
    # Small control files are rehashed per recipe; the complete large historical
    # ledgers and all native inputs are hashed at the whole-operation boundaries.
    controls = dict(observations)
    require(sha(paths['metadata_observation']) == OBSERVATION_PIN and sha(paths['metadata_details']) == DETAIL_PIN,
            'wrong saved metadata observation')
    observations[paths['metadata_observation']] = OBSERVATION_PIN; observations[paths['metadata_details']] = DETAIL_PIN
    observation = load_json(paths['metadata_observation'])
    require(observation['status'] == 'saved-metadata-candidates-observed' and observation['metadata_candidate_roots'] == 1372,
            'incomplete metadata observation')
    wanted = phase_gate(args, policy, sources, observation)
    require((args.reference is None) == (args.operation == 'collect'), 'only projection may consume the owned reference')
    if args.operation == 'project':
        require(sha(args.reference) == policy['reference_sha256'], 'owned reference identity differs')
        observations[args.reference.resolve()] = policy['reference_sha256']
    for key, value in groups.INPUT_PINS.items(): observations[paths[key]] = value
    stable(observations)
    # Saved metadata only; no actual object/source-body/PE access in this loader.
    metadata, providers, metadata_summary = groups.load_saved_metadata({key: paths[key] for key in groups.INPUT_PINS}, wanted)
    require(set(metadata) == set(wanted) and all(row['assessment']['metadata_candidate'] for row in metadata.values()),
            'requested native case is not a complete metadata candidate')
    requested_roots = {root['original_address'] for item in metadata.values() for root in item['plan']['roots']}
    require(sorted(requested_roots) == policy['box2089']['original_addresses'] and
            metadata[BOX]['plan']['counts']['code_bytes'] == 182 and metadata[BOX]['plan']['counts']['fields'] == 1,
            'fixed Box source component differs')
    manifest = load_json(paths['manifest']); units = {u['recipe_id']: u for u in manifest['units']}
    out = args.out.resolve(); private = (ROOT / 'build/rebuild').resolve()
    require(out != private and out.is_relative_to(private) and not out.exists(), 'exclusive private output required')
    out.mkdir(parents=True)
    for relative in OWNED:
        with (out / Path(relative).name).open('xb') as target: target.write((ROOT / relative).read_bytes())
    receipt = dict(schema_version=1, kind='operational-union-reference-projection-v2', policy_id=POLICY,
        status='error', operation=args.operation, profile=args.profile, source_sha256=sources, requested_recipe_ids=wanted,
        requested_root_ids=sorted(requested_roots), metadata_summary=metadata_summary, emission_performed=False,
        native_coff_collection_performed=False, **FALSE)
    opened = []; activities = {}; emitted = set(); certified = set(); members = []; source_by_name = {}; cert_by_name = {}; expect_by_name = {}
    spool = None; start = time.monotonic()
    with (out / 'progress.jsonl').open('x', encoding='utf-8') as journal, (out / 'certificates.jsonl').open('x', encoding='utf-8') as cert_output:
        def note(value): journal.write(json.dumps(value) + '\n'); journal.flush(); os.fsync(journal.fileno())
        note(dict(state='started', operation=args.operation, profile=args.profile))
        try:
            pe = None
            if args.operation == 'project':
                sys.path.insert(0, str(ROOT / 'tools'))
                oracle = importlib.import_module('compare'); image = importlib.import_module('build_and_match')
                loaded_producers(policy)
                require(Path(oracle.__file__).resolve() == ROOT / 'tools/compare.py' and
                        Path(image.__file__).resolve() == ROOT / 'tools/build_and_match.py', 'unexpected oracle module')
                pe = oracle.Pe(args.reference); require(image.image_ok(pe)[0], 'unchanged image fingerprint gate')
                spool = bulk.Spool(out / 'members.spool', out / 'members.jsonl')
            for rid in sorted(wanted, key=lambda r: units[r]['recipe_index']):
                stable(controls); unit = units[rid]; item = metadata[rid]
                source = (ROOT / unit['source']).resolve()
                original = (paths['manifest'].parent / manifest.get('object_root_relative', '.') / unit['object']).resolve()
                require(source.is_relative_to(ROOT) and original.is_relative_to(paths['manifest'].parent), 'source/object path escapes owned lineage')
                note(dict(state='opening-authorized-native-object', recipe_id=rid, object_sha256=unit['object_sha256']))
                activity = activities[rid] = dict(source_hash_attempted=False, native_object_access_attempted=False,
                    native_object_bytes_read=None, projection_attempted=False, projection_completed=False)
                raw, certificate = collect_recipe(original, source, item, providers, observations, activity); opened.append(rid)
                record = dict(recipe_id=rid, certificate=certificate, native_shape_verified=True, fresh_reference_match=False, **FALSE)
                if args.operation == 'project':
                    before = bulk.compare_functions(original, pe, item['contracts'], unit['recipe'])
                    name = rid + '.obj'; stage = out / (name + '.stage')
                    activity['projection_attempted'] = True
                    output, projected, independent, expected = project_recipe(raw, original, item, providers, certificate, stage, out / (name + '.recovered'))
                    after = bulk.compare_functions(stage, pe, item['contracts'], unit['recipe'], item['plan'])
                    record.update(projection=projected, before_comparison=before, after_comparison=after,
                                  independent_stage=independent, fresh_reference_match=True)
                    member = spool.append(name, output, unit['recipe_index'], record); members.append(member)
                    source_by_name[name] = original; cert_by_name[name] = certificate; expect_by_name[name] = expected
                    emitted.update(root['original_address'] for root in item['plan']['roots'])
                    activity['projection_completed'] = True
                certified.update(root['original_address'] for root in item['plan']['roots'])
                cert_output.write(bulk.canonical(record).decode() + '\n'); cert_output.flush(); os.fsync(cert_output.fileno())
                stable(controls); stable({source: unit['source_sha256'], original: unit['object_sha256']})
                note(dict(state='recipe-complete', recipe_id=rid, certificate_sha256=groups.digest(certificate), projected=args.operation == 'project'))
            if spool is not None:
                spool.close(); spool = None; bulk.inspect_spool(out / 'members.spool', members)
                shards = []
                for number, selected in enumerate(bulk.shard_plan(members)):
                    target = out / ('union-reference-%04d.lib' % number)
                    bulk.write_shard(out / 'members.spool', selected, target)
                    shards.append(dict(name=target.name, **recover_and_verify_archive(target, selected, source_by_name, cert_by_name, expect_by_name, out)))
                receipt['shards'] = shards
            receipt['coverage_counts'] = write_coverage(out / 'coverage.jsonl.gz', paths['coverage'], certified, emitted)
            require(certified == requested_roots and (args.operation != 'project' or emitted == requested_roots), 'finite root completion differs')
            receipt.update(status='complete', native_coff_collection_performed=True, actual_recipe_ids=opened,
                certified_roots=len(certified), projected_roots=len(emitted), emission_performed=bool(emitted),
                input_stability_verified=True, optional_function_index_present=False,
                protected_inputs={str(path): value for path, value in observations.items()},
                certificates_sha256=sha(out / 'certificates.jsonl'), coverage_sha256=sha(out / 'coverage.jsonl.gz'),
                native_conformance_verified=False)
            note(dict(state='complete', certified_roots=len(certified), projected_roots=len(emitted)))
        except Exception as error:
            receipt.update(error=type(error).__name__ + ': ' + str(error), actual_recipe_ids=opened,
                           certified_roots=len(certified), projected_roots=len(emitted))
            note(dict(state='failed', error=receipt['error']))
        finally:
            if spool is not None: spool.close()
            if pe is not None and hasattr(pe, 'close'): pe.close()
            try:
                stable(observations)
                receipt['input_stability_verified'] = True
            except Exception as stability_error:
                receipt.update(status='error', input_stability_verified=False,
                    final_stability_error=type(stability_error).__name__ + ': ' + str(stability_error))
            receipt['protected_inputs'] = {str(path): value for path, value in observations.items()}
        receipt.update(recipe_activity=activities,
            native_coff_collection_performed=any(a['native_object_bytes_read'] is not None for a in activities.values()),
            native_access_attempted=any(a['native_object_access_attempted'] for a in activities.values()),
            source_access_attempted=any(a['source_hash_attempted'] for a in activities.values()),
            emission_attempted=any(a['projection_attempted'] for a in activities.values()),
            emission_may_have_partial_outputs=any(a['projection_attempted'] and
                (not a['projection_completed'] or receipt['status'] != 'complete') for a in activities.values()),
            emission_performed=bool(emitted))
        receipt['elapsed_seconds'] = time.monotonic() - start
        note(dict(state='final-status', status=receipt['status'],
            input_stability_verified=receipt.get('input_stability_verified',False), recipe_activity=activities))
        save_json(out / 'receipt.json', receipt)
    return receipt


def main():
    parser = argparse.ArgumentParser(__doc__)
    for name in ('policy', 'inputs', 'review', 'out'): parser.add_argument('--' + name, type=Path, required=True)
    for name in ('policy-sha256', 'review-sha256'): parser.add_argument('--' + name, required=True)
    parser.add_argument('--operation', choices=('collect', 'project'), required=True)
    parser.add_argument('--profile', choices=('box2089',), required=True)
    parser.add_argument('--authorize-coff-read', action='store_true')
    parser.add_argument('--authorize-private-emission', action='store_true')
    parser.add_argument('--reference', type=Path)
    result = run(parser.parse_args()); print(result['status'])
    if result['status'] != 'complete': raise SystemExit(1)


if __name__ == '__main__': main()
