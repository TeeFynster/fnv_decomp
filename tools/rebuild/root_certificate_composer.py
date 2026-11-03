"""Versioned metadata composition; never edits an ordinary certificate or COFF.

Typed omissions discharge exact physical blocker IDs only. A composed omission
decision is not namespace, serialization, provider, ABI or runtime approval.
"""
from __future__ import annotations
from collections import Counter, defaultdict
import gzip
import hashlib
import json
import os
from pathlib import Path
import re

import coff_code_archive as coff
import root_code_closure as ordinary
import ordinary_initialized_data_omission as initialized

ROOT = Path(__file__).resolve().parents[2]
POLICY = 'typed-root-certificate-composition-v1'
MAP_POLICY = 'selected-physical-provider-map-v1'
PINS = {'tools/rebuild/coff_code_archive.py': '76244d2d4dca4c1f8aa72224be1ef5c92f68976b5cda7d31b5cfe23d3cc29e64',
        'tools/rebuild/root_code_closure.py': '4bfdb5001380a3d7e5db7517033285d49ab211be68e2fcba15964f0ad5b03c53',
        'tools/rebuild/ordinary_initialized_data_omission.py': '1a0e8aa2271218f59c11497c1363b41f099bb259791e19adac7d80718e7a5d7b'}
# Successor independently reviewed in code-lane06-local-label-v2-request-v3-review.
LABEL_PIN = '57cecc88c2f2aaccdf87ca8605fe84461c31a4c391884d503240329636e5f826'
INPUT_PINS = {'owners': 'fac1496a2675e9a6b697d604c8d5b35a2e4b8bb6194e2ec823e5a37d1092f2e8',
              'owner_details': 'c54abfd434ac715a16d31711fa8afb498d4b41420bec3bfcc25347d0eab9bd08',
              'selection': '48ae62cdc5b1754b9c4af674ef4716d53afb554882e174a93acf860eaf1c6cb1',
              'manifest': 'bc62a5fb2553431b1e0547d11f366e52efb73096ea8ceb206c556ae5740a53eb',
              'retained': '04d44b73e81982f846bfe8d81806db72ea669586b579ff22007dfd6f7d831297'}
OWNER_SEQUENCE = '1f80ad052c78977bd0acfb03699aaa17c0dd3ae2fdcedca07ee6ea938b7b6cb0'
CENTRAL_PIN = '290ac0e8c1ffbfd89df7dd6cdbbdb8df363edca58111b7aa19fe842aa26cc8e4'
FALSE = dict(provider_selected=False, runtime_eligible=False, ABI_verified=False,
             namespace_approved=False, full_serialization_eligible=False,
             emission_performed=False, materialization_approved=False,
             link_ready=False, native_tools_run=False)
require = coff.require


def canonical(value):
    return json.dumps(value, sort_keys=True, separators=(',', ':'), ensure_ascii=True).encode()


def digest(value):
    return hashlib.sha256(canonical(value)).hexdigest()


def file_hash(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as stream:
        for part in iter(lambda: stream.read(1048576), b''): h.update(part)
    return h.hexdigest()


def tools(*, include_labels=False):
    pins = dict(PINS)
    if include_labels:
        require(LABEL_PIN is not None, 'label successor policy not yet reviewed/pinned')
        pins['tools/rebuild/local_label_projection.py'] = LABEL_PIN
    for path, expected in pins.items():
        require(file_hash(ROOT/path) == expected, 'composer dependency changed: '+path)
    return pins


def compose(raw, contract, base, witnesses, *, policy_id):
    """Replay every witness and preserve the exact original blocked result.

    The explicit policy argument prevents accidental consumption as ordinary4bf.
    Callers authenticate their collector envelope separately; Python/local hash
    consistency is an operational provenance guard, not authentication.
    """
    require(policy_id == POLICY, 'explicit composed-policy opt-in required')
    require(isinstance(raw, bytes) and 0 < len(raw) <= 16*1024**2, 'native object bound')
    require(type(witnesses) is list and len(witnesses) <= 32, 'finite witness list required')
    require(all(type(w) is dict for w in witnesses), 'typed witness dictionary required')
    uses_labels = any(w.get('kind') == 'typed-local-label-omission-witness' for w in witnesses)
    dependencies = tools(include_labels=uses_labels)
    require(contract['provenance']['object_sha256'] == coff.digest(raw), 'stale native object')
    require(ordinary.assess_object(coff.parse(raw), contract) == base and
            base['contract_identity_sha256'] == digest(contract), 'base replay differs')
    before = digest(dict(contract=contract, base=base, witnesses=witnesses))
    original = defaultdict(list)
    for ordinal, blocker in enumerate(base['blockers'], 1):
        original[blocker['blocker_id']].append((ordinal, blocker))
    discharged = {}; observations = []; witness_hashes = set()
    for witness in witnesses:
        wh = digest(witness)
        require(wh not in witness_hashes, 'duplicate witness')
        witness_hashes.add(wh)
        if witness.get('kind') == 'typed-initialized-data-omission-witness':
            expected = initialized.observe_omitted_initialized_data(raw, contract, base, witness['requested_sections'])
            require(witness == expected, 'initialized-data witness replay differs')
            ids = witness['discharge_blocker_ids']
            allowed = {'UNSUPPORTED_SECTION_SEMANTICS'}
            family = initialized.POLICY
        elif witness.get('kind') == 'typed-local-label-omission-witness':
            require(LABEL_PIN is not None, 'label successor policy not yet reviewed/pinned')
            import local_label_projection as labels
            require(set(witness) == {'kind','evidence_json','decision_json','decoded'}, 'unknown label witness schema')
            cert = labels.LabelCertificate(witness['evidence_json'], witness['decision_json'])
            expected = labels.decode_label_policy(raw, contract, base, cert)
            require(expected == witness['decoded'], 'local-label witness replay differs')
            ids = expected['discharged_blocker_ids']
            allowed = {'LABEL_OMISSION_NOT_PROVED','UNPROVED_RETAINED_ENTRY_OR_ALIAS','UNSUPPORTED_LIVE_REFERENCE_RECORD'}
            family = labels.POLICY
        else:
            raise ValueError('unsupported typed witness family')
        require(type(ids) is list and len(ids) == len(set(ids)), 'duplicate witness blocker ID')
        for bid in ids:
            matches = original.get(bid, [])
            require(len(matches) == 1, 'typed discharge requires one unambiguous original blocker occurrence')
            ordinal, blocker = matches[0]
            require(blocker['code'] in allowed, 'witness escaped exact supported blocker set')
            require(ordinal not in discharged, 'overlapping witness discharges')
            discharged[ordinal] = dict(base_blocker_ordinal=ordinal, blocker=blocker, witness_sha256=wh, witness_policy_id=family)
        observations.append(dict(witness_sha256=wh, policy_id=family, discharge_blocker_ids=ids))
    remaining_occurrences = [dict(base_blocker_ordinal=i, blocker=b)
                             for i,b in enumerate(base['blockers'],1) if i not in discharged]
    remaining = [row['blocker'] for row in remaining_occurrences]
    require(digest(dict(contract=contract, base=base, witnesses=witnesses)) == before, 'composition modified input')
    require(tools(include_labels=uses_labels) == dependencies, 'dependency drift during composition')
    return dict(schema_version=1, policy_id=POLICY, kind='composed-root-omission-observation',
                object_sha256=coff.digest(raw), recipe_id=contract['recipe_id'],
                source_sha256=contract['provenance']['source_sha256'],
                contract_identity_sha256=digest(contract), provenance_sha256=digest(contract['provenance']),
                base_certificate_sha256=digest(base), base_policy_id=base['policy_id'],
                base_closure_observed=base['closure_observed'], base_graph_observation_complete=base['graph_observation_complete'],
                original_certificate_unchanged=True, base_certificate=base,
                roots=base['roots'], retained_section_indices=base['retained_section_indices'],
                retained_primary_indices=base['retained_primary_indices'], retained_physical_slots=base['retained_physical_slots'],
                physical_graph_sha256=digest(dict(sections=base['sections'], symbols=base['symbols'], edges=base['edges'])),
                witness_observations=observations, discharged_blockers=[discharged[k] for k in sorted(discharged)],
                remaining_blockers=remaining, remaining_blocker_occurrences=remaining_occurrences,
                base_blocker_occurrences=len(base['blockers']), composed_omission_complete=not remaining,
                explicit_composed_policy_required=True, collector_envelope_authentication_required=True,
                dependency_tools_sha256=dependencies, **FALSE)


def provider_map(stream, report, selections, manifest, retained, *, expected_count, expected_sequence):
    """One complete owner stream; planned physical namespaces, no object reads."""
    units = {u['recipe_id']: u for u in manifest['units']}
    proofs = {u['recipe_id']: u for u in retained['units']}
    require(len(units) == len(manifest['units']) and len(proofs) == len(retained['units']), 'duplicate recipe')
    checked = {}; providers = {}; physical = set(); events = Counter(); sequence = hashlib.sha256()
    for ordinal, line in enumerate(stream, 1):
        require(ordinal <= 1000000 and len(line) <= 262144, 'owner stream bound')
        row = json.loads(line); events[row['event']] += 1
        sequence.update(canonical([ordinal, digest(row)]))
        require(all(row.get(k) is False for k in ('runtime_eligible','provider_selected','materialization_approved')), 'promoted owner record')
        if row['event'] != 'SOURCE_CODE_PROVIDER_OBLIGATION': continue
        va = '0x%08x' % row['original_start']; choice = selections.get(va); identity = row['identity']
        require(choice is not None and va not in providers, 'missing/duplicate selected owner')
        rid = identity['recipe_id']; unit = units[rid]; proof = proofs[rid]
        require(unit['status'] == 'compiled' and proof['status'] == 'ok' and
                choice['recipe_id'] == rid and choice['recipe_index'] == unit['recipe_index'] == proof['recipe_index'] and
                identity['object_sha256'] == unit['object_sha256'] == proof['object_sha256'] and
                row['source_sha256'] == unit['source_sha256'] == proof['source_sha256_current'] == proof['source_sha256_recorded'], 'owner source/object/recipe differs')
        require(proof['recipe_unit_sha256'] == digest(unit['recipe']), 'owner recipe proof differs')
        if rid not in checked:
            by_address = {}
            for f in proof['verified_functions']:
                by_address.setdefault(f['address'], []).append(f)
            checked[rid] = by_address
        fs = [f for f in checked[rid].get(va, []) if f['symbol'] == choice['symbol'] and
              (f['section'], f['value'], f['size'], f['verdict']) ==
              (choice['section'], choice['value'], choice['size'], 'match')]
        require(len(fs) == 1 and (row['native_section'], row['native_value'], row['verified_span']) ==
                (choice['section'], choice['value'], choice['size']) and
                row['original_end'] == row['original_start'] + choice['size'], 'owner checked physical span differs')
        require(set(identity) == {'recipe_id','object_sha256','symbol_index'} and
                type(identity['symbol_index']) is int and identity['symbol_index'] >= 0 and
                row['provider_id'] == digest(identity), 'physical provider identity differs')
        key = (rid, identity['object_sha256'], identity['symbol_index'])
        require(key not in physical, 'physical provider assigned multiple original owners')
        physical.add(key)
        providers[va] = dict(**identity, source_sha256=row['source_sha256'], section=choice['section'],
                             value=choice['value'], size=choice['size'], symbol=choice['symbol'],
                             planned_canonical_name='_fnv_code_'+digest(identity))
    require(dict(events) == report['summary']['events'] and sequence.hexdigest() == expected_sequence,
            'complete owner stream census/digest differs')
    require(set(providers) == set(selections) and len(providers) == expected_count, 'complete selected provider coverage differs')
    return dict(schema_version=1, policy_id=MAP_POLICY, kind='typed-provider-map',
                providers=providers, census=dict(events=dict(events), sequence_sha256=sequence.hexdigest(), selected_owners=len(providers)),
                provider_identity_is_planned_namespace=True, materialized_exports=0, **FALSE)


def publish(path, value, protected, *, require_index_absent=False):
    """Exclusive fsynced output, with post-publication input stability cleanup."""
    path = Path(path).resolve()
    require(path not in protected and not path.exists(), 'output/input collision or existing output')
    path.parent.mkdir(parents=True, exist_ok=True)
    created = False
    try:
        with path.open('xb') as stream:
            created = True
            stream.write(canonical(value)+b'\n'); stream.flush(); os.fsync(stream.fileno())
        require(all(file_hash(p) == h for p, h in protected.items()), 'input changed after publication')
        require(not require_index_absent or not (ROOT/'build/function_index.json').exists(), 'optional index appeared')
    except BaseException:
        if created and path.exists(): path.unlink()
        raise
    return file_hash(path)


def export_provider_map(paths, out):
    require(set(paths) == set(INPUT_PINS), 'exact provider-map inputs required')
    protected = {Path(p).resolve(): INPUT_PINS[k] for k, p in paths.items()}
    require(len(protected) == len(paths) and all(file_hash(p) == h for p,h in protected.items()), 'provider-map input pins differ')
    require(not (ROOT/'build/function_index.json').exists(), 'optional index appeared')
    require(Path(out).resolve() not in protected and not Path(out).exists(), 'existing/colliding provider-map output')
    source = Path(__file__).resolve(); protected[source] = file_hash(source)
    load = lambda k: json.loads(Path(paths[k]).read_text(encoding='utf-8'))
    selection = load('selection'); report = load('owners'); manifest = load('manifest'); retained = load('retained')
    require(report['details_sha256'] == INPUT_PINS['owner_details'], 'owner detail provenance differs')
    with gzip.open(paths['owner_details'], 'rt', encoding='utf-8') as stream:
        result = provider_map(stream, report, selection['selections'], manifest, retained,
                              expected_count=68657, expected_sequence=OWNER_SEQUENCE)
    result.update(inputs=INPUT_PINS, producer_sha256=protected[source],
                  input_stability=True, optional_function_index_present=False)
    require(all(file_hash(p) == h for p,h in protected.items()), 'provider-map input drift')
    return result, publish(out, result, protected, require_index_absent=True)


def demonstrate_cached_case(central_path, lane_path, manifest_path, ordinal, witness_factory, out, *, witness_inputs=None):
    """Bounded one-case metadata demonstration from the accepted central cache.

    The caller supplies a reviewed callable producing typed witnesses; arbitrary
    helper output cannot waive replay. This opens one exact manifest object and
    its known source for hashing, no image, directory or global detail stream.
    """
    require(type(ordinal) is int and 1 <= ordinal <= 64, 'bounded lane ordinal required')
    protected = {Path(central_path).resolve(): CENTRAL_PIN,
                 Path(manifest_path).resolve(): INPUT_PINS['manifest']}
    require(len(protected) == 2 and all(file_hash(p) == h for p,h in protected.items()), 'trusted central/manifest pins differ')
    central = json.loads(Path(central_path).read_text(encoding='utf-8'))
    require(central['input_stability'] is True and central['optional_function_index_present'] is False,
            'central input/index state differs')
    require(not (ROOT/'build/function_index.json').exists(), 'optional index appeared')
    lane_matches = [(int(k), v) for k,v in central['lane_artifacts'].items()
                    if v['path'] == Path(lane_path).name]
    require(len(lane_matches) == 1, 'unknown central lane')
    lane, artifact = lane_matches[0]; lane_path = Path(lane_path).resolve()
    require(lane_path not in protected and file_hash(lane_path) == artifact['sha256'], 'lane hash differs')
    protected[lane_path] = artifact['sha256']
    require(witness_inputs is None or type(witness_inputs) is dict, 'explicit witness input hashes required')
    for path, sha in (witness_inputs or {}).items():
        path = Path(path).resolve()
        require(path not in protected and re.fullmatch('[0-9a-f]{64}', sha) and file_hash(path) == sha,
                'witness input identity differs')
        protected[path] = sha
    rows = [r for r in central['observations'] if r['lane'] == lane and r['lane_record_ordinal'] == ordinal]
    require(len(rows) == 1, 'missing/duplicate central record index')
    with gzip.open(lane_path, 'rt', encoding='utf-8') as stream:
        record = None
        for i, line in enumerate(stream, 1):
            require(len(line) <= 32*1024**2, 'cached record bound')
            if i == ordinal: record = json.loads(line); break
    require(record is not None and digest(record) == rows[0]['record_sha256'], 'cached record hash differs')
    contract, base = record['contract'], record['certificate']
    require(record['contract_identity_sha256'] == digest(contract) and
            record['certificate_sha256'] == digest(base) == rows[0]['certificate_sha256'], 'cached contract/base identity differs')
    manifest = json.loads(Path(manifest_path).read_text(encoding='utf-8'))
    units = [u for u in manifest['units'] if u['recipe_id'] == record['recipe_id']]
    require(len(units) == 1, 'cached recipe missing/duplicate')
    unit = units[0]
    require(unit['object_sha256'] == contract['provenance']['object_sha256'] and
            unit['source_sha256'] == contract['provenance']['source_sha256'] and
            record['requested_roots'] == [dict(r, recipe_id=unit['recipe_id'], recipe_index=unit['recipe_index'],
                object_sha256=unit['object_sha256'], source_sha256=unit['source_sha256']) for r in contract['roots']],
            'manifest/cached physical root scope differs')
    native = (Path(manifest_path).parent/manifest.get('object_root_relative','.')/unit['object']).resolve()
    source = (ROOT/unit['source']).resolve()
    require(native not in protected and source not in protected and native != source, 'native/source identity collision')
    protected[native] = unit['object_sha256']; protected[source] = unit['source_sha256']
    dependencies = tools()
    protected.update({(ROOT/p).resolve(): h for p,h in dependencies.items()})
    protected[Path(__file__).resolve()] = file_hash(__file__)
    require(all(file_hash(p) == h for p,h in protected.items()), 'cached demonstration input drift')
    raw = native.read_bytes(); witnesses = witness_factory(raw, contract, base)
    result = compose(raw, contract, base, witnesses, policy_id=POLICY)
    protected.update({(ROOT/p).resolve(): h for p,h in result['dependency_tools_sha256'].items()})
    result.update(central_receipt_sha256=CENTRAL_PIN, lane_sha256=artifact['sha256'], lane=lane,
                  lane_record_ordinal=ordinal, central_record_sha256=digest(record),
                  typed_witnesses=witnesses, input_stability=True, optional_function_index_present=False,
                  producer_sha256=protected[Path(__file__).resolve()])
    require(not (ROOT/'build/function_index.json').exists(), 'optional index appeared')
    output_sha = publish(out, result, protected, require_index_absent=True)
    return result, output_sha
