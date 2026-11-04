"""Whole-union CODE-reference certificates and a separate guarded name applier.

No disk object/archive emission, native process, provider approval or v1 edits.
Actual use requires independently pinned whole-union evidence and root approval.
"""
from __future__ import annotations
from collections import defaultdict
import hashlib
import gzip
import json
from pathlib import Path
import struct
import bulk_code_pool as bulk
import coff_code_archive as coff
import runtime_code_pool as pool

POLICY = 'whole-union-code-reference-groups-v2'
INPUT_PINS = dict(
    production='ad870815321b42485378b0f896340bfd0b70cd52aea0dd27ffc39725bd93ce14',
    unions='fd3b319cf25bea35c6523ebd7a734441804670943200547724d1d87c8a6a1b64',
    coverage='e29cef9c0169ea19ac39724d3acb33163b101d9f21e8eed970c8071253d4ec16',
    inventory='91cdc91af6530e6e80e2104cdfeb9bd6928e17fa0f75bcf066734985248f1031',
    binding='275714631903758efbf5a4f82e2428c6f51838f53b90d0c56d2e5dec5da1d804',
    binding_details='4dfc437064b16c1bb933008aebf7def8d279a903eef9cca24d0fedcc12d7d826',
    manifest='bc62a5fb2553431b1e0547d11f366e52efb73096ea8ceb206c556ae5740a53eb',
    selection='48ae62cdc5b1754b9c4af674ef4716d53afb554882e174a93acf860eaf1c6cb1',
    retained='04d44b73e81982f846bfe8d81806db72ea669586b579ff22007dfd6f7d831297',
    recipes='62f2c8da5f0daa912abdf4576328706711c6561eef7f01c93a89cb71ad46fb6c')
PRODUCER_PINS = {
    'bulk_code_pool.py': '4e6d697c1881c56c4c3f6a84788df6e0e2617b284d8e0226805828829bce49ed',
    'runtime_code_pool.py': '729f189e2893c7f3a3e3cd97df7d7381ac115169e1d75cf664e6bbc1c587b277',
    'coff_code_archive.py': '76244d2d4dca4c1f8aa72224be1ef5c92f68976b5cda7d31b5cfe23d3cc29e64',
    'runtime_code_inventory.py': 'c2fdbd52b4b7f4b7c68f9d80ad03708ba57d42b29e5938dfcf9769366a1ffd0b'}
GROUP_BLOCKERS = {'REFERENCE_CERTIFICATE_REQUIRED', 'MIXED_DEFINITION_REFERENCE_GROUP_UNSUPPORTED'}
FALSE = dict(emission_performed=False, provider_selected=False, runtime_eligible=False,
             ABI_verified=False, link_ready=False, materialization_approved=False,
             native_link_mechanism_verified=False)
require = coff.require


def normalized(value):
    """JSON maps have string keys; compare persisted and fresh plans identically."""
    if isinstance(value, dict):
        result = {}
        for key, item in value.items():
            require(isinstance(key, (str, int)) and not isinstance(key, bool), 'unsupported metadata key')
            key = str(key)
            require(key not in result, 'colliding normalized metadata keys')
            result[key] = normalized(item)
        return result
    if isinstance(value, (list, tuple)):
        return [normalized(item) for item in value]
    return value


def digest(value):
    return hashlib.sha256(json.dumps(normalized(value), sort_keys=True, separators=(',', ':'),
                                     ensure_ascii=True).encode()).hexdigest()


def ordered_fields(plan, fields):
    roots = plan['roots']; by_address = {r['original_address']: [] for r in roots}; seen = set()
    require(len(by_address) == len(roots), 'duplicate union roots')
    root_index = {r['original_address']: r for r in roots}
    for row in fields:
        require(row['function_va'] in root_index and row['recipe_id'] == plan['recipe_id'], 'field outside exact root set')
        root = root_index[row['function_va']]; relocation = row['coff_relocation']
        require(relocation is not None and row['physical_section'] == root['section'] and
                row['physical_offset'] == relocation['offset'] == root['value'] + row['source_field_offset'] and
                0 <= row['source_field_offset'] <= root['size'] - relocation['width'], 'wrong physical field geometry')
        key = (row['physical_section'], row['physical_offset'], relocation['symbol_index'], relocation['kind'])
        require(key not in seen, 'duplicate whole-union field'); seen.add(key)
        by_address[row['function_va']].append(row)
    result = [row for root in roots for row in by_address[root['original_address']]]
    require(len(result) == plan['counts']['fields'] and pool.digest(bulk.canonical(result)) == plan['field_proof_sha256'],
            'whole-union complete field proof differs')
    return result


def assess_saved_union(plan, fields, providers):
    """Saved metadata classification only; native auxiliary shape is deferred."""
    fields = ordered_fields(plan, fields)
    require(plan['policy_id'] == bulk.POLICY and len(plan['assessments']) == len(plan['roots']) and
            all(a['candidate_eligible'] for a in plan['assessments']), 'individual root blocker cannot be waived')
    names = dict(plan['bindings']); require(len(names) == len(plan['bindings']), 'duplicate binding index')
    namespace = plan['namespace_plan']; symbols = plan['symbols']
    require(len(namespace) == len(symbols) and {r['physical_index'] for r in namespace} == set(symbols),
            'incomplete whole-union namespace')
    require(all(r['name'] == names.get(r['physical_index'], r['name']) for r in namespace), 'namespace/binding disagreement')
    source_groups = defaultdict(list)
    for index, name in names.items(): source_groups[name].append(index)
    duplicates = {name: sorted(indices) for name, indices in source_groups.items() if len(indices) > 1}
    advertised = {}
    for block in plan['blockers']:
        if block['code'] in GROUP_BLOCKERS | {'REFERENCE_GROUP_ORIGINAL_SHAPE_UNSUPPORTED'}:
            evidence = block['evidence']; name = evidence['name']
            require(name not in advertised, 'repeated original group blocker')
            advertised[name] = sorted(evidence['indices'])
    require(duplicates == advertised and duplicates, 'hidden/missing duplicate group scope')
    reasons = []
    if any(b['code'] not in GROUP_BLOCKERS for b in plan['blockers']):
        reasons.append('UNSUPPORTED_ORIGINAL_UNION_BLOCKER')
    groups = []
    for name, members in sorted(duplicates.items()):
        why = []; observations = defaultdict(set); uses = []
        choices = providers.get(name, [])
        provider = choices[0] if len(choices) == 1 else None
        if provider is None: why.append('MISSING_OR_AMBIGUOUS_SELECTED_PROVIDER')
        if provider is not None and pool.canonical(provider['identity']) != name:
            why.append('CANONICAL_PROVIDER_IDENTITY_MISMATCH')
        definitions = [r for r in plan['roots'] if r['symbol_index'] in members]
        if len(definitions) > 1: why.append('MULTIPLE_RETAINED_STRONG_DEFINITIONS')
        kind = ('all-original-undefined' if not definitions else 'one-selected-definition-and-undefined'
                if len(definitions) == 1 else 'unsupported-multiple-definitions')
        if definitions and provider is not None:
            definition = definitions[0]
            if (provider['identity'] != dict(recipe_id=plan['recipe_id'], object_sha256=plan['object_sha256'],
                                             symbol_index=definition['symbol_index']) or
                    provider['original_address'] != definition['original_address'] or definition['value'] != 0):
                why.append('RETAINED_DEFINITION_IS_NOT_EXACT_PROVIDER_ENTRY')
        definition_indices = {r['symbol_index'] for r in definitions}
        for row in fields:
            relocation = row['coff_relocation']; index = relocation['symbol_index']
            if index not in members: continue
            uses.append(row)
            observations[index].add((relocation['symbol'], relocation['symbol_section'], relocation['symbol_value'],
                                     relocation['symbol_type'], relocation['symbol_storage']))
            if (relocation['kind'] not in (6, 20) or relocation['width'] != 4 or relocation['addend'] != 0 or
                    row['proof_consistency'] != 'EXACT_OWN_SOURCE_RESOLUTION' or row['physical_field_overlap_count'] != 1):
                why.append('NONZERO_SPECIAL_OR_NONEXACT_FIELD')
            if (row['classification'] != 'SELECTED_CODE_ENTRY' or relocation['symbol_storage'] != 2 or
                    relocation['symbol_type'] != 32 or relocation['symbol'].startswith(('__imp_', '_imp__'))):
                why.append('NONPLAIN_CODE_FUNCTION_REFERENCE')
            if provider is not None:
                base = provider['original_address']
                if (row['exact_original_target_va'] != base or row['derived_source_symbol_base_va'] != base or
                        row['expected_original_target_va'] != base or row['code_ownership_ambiguous'] or
                        row['code_owners'] != [dict(address=base, offset=0)]):
                    why.append('DIFFERENT_BASE_TARGET_INTERIOR_OR_PROVIDER')
                address = int(row['original_field_va'], 16)
                target = (row['original_operand'] + (address + 4 if relocation['kind'] == 20 else 0)) & 0xffffffff
                if target != int(base, 16): why.append('ORIGINAL_OPERAND_TARGET_DIFFERS')
        for index in members:
            observed = observations.get(index, set())
            if len(observed) > 1: why.append('CONFLICTING_PHYSICAL_SYMBOL_STATUS')
            if index not in definition_indices:
                if not observed: why.append('UNDEFINED_MEMBER_WITHOUT_RETAINED_FIELD')
                elif any(section != 0 or value != 0 for _, section, value, _, _ in observed):
                    why.append('ORIGINAL_DEFINED_CONVERSION_REQUIRES_OTHER_VERSION')
            elif observed:
                definition = next(r for r in definitions if r['symbol_index'] == index)
                if any(section != definition['section'] or value != 0 for _, section, value, _, _ in observed):
                    why.append('DEFINITION_STATUS_DIFFERS')
        if not uses: why.append('GROUP_WITHOUT_COMPLETE_FIELDS')
        group = dict(name=name, members=members, kind=kind, provider=provider,
            fields=[dict(section=r['physical_section'], offset=r['physical_offset'], symbol_index=r['coff_relocation']['symbol_index'],
                         kind=r['coff_relocation']['kind'], addend=0, proof_sha256=digest(r)) for r in uses],
            reasons=sorted(set(why)), metadata_candidate=not why, native_shape_verified=False)
        groups.append(group)
    return dict(schema_version=1, policy_id=POLICY, recipe_id=plan['recipe_id'], roots=plan['roots'],
        union_plan_sha256=digest(plan), complete_field_proof_sha256=plan['field_proof_sha256'],
        groups=groups, reasons=sorted(set(reasons)), metadata_candidate=not reasons and all(g['metadata_candidate'] for g in groups),
        namespace_plan=namespace, **FALSE)


def certify_union(data, contracts, saved_plan, providers, provenance):
    """Recompute complete v1 selection, then prove both narrow CODE group kinds."""
    fresh = bulk.plan_union(data, contracts)
    require(digest(fresh) == digest(saved_plan), 'whole-union plan does not recompute')
    fields = [r for contract in contracts for r in contract['fields']]
    assessment = assess_saved_union(fresh, fields, providers)
    require(assessment['metadata_candidate'], 'unsupported union reference group or original blocker')
    obj = coff.parse(data); symbols = obj['symbols']
    roots = {r['symbol_index']: r for r in fresh['roots']}
    for group in assessment['groups']:
        strong = []
        for index in group['members']:
            symbol = symbols[index]
            require(symbol['storage'] == 2 and symbol['type'] == 32 and symbol['aux_count'] == 0 and
                    symbol['value'] == 0 and not symbol['name'].startswith(('__imp_', '_imp__')),
                    'weak/common/IAT/aux/type group is outside v2')
            if symbol['section'] > 0:
                require(index in roots and symbol['section'] == roots[index]['section'] and
                        symbol['section'] in fresh['sections'] and index not in fresh['undefined'],
                        'unselected/local/converted definition is outside v2')
                strong.append(index)
            else: require(symbol['section'] == 0, 'absolute group is outside v2')
        require(len(strong) == (1 if group['kind'] == 'one-selected-definition-and-undefined' else 0),
                'duplicate strong definition or missing exact provider')
        group['native_shape_verified'] = True
    primary = [[i, j] for i, j in sorted(fresh['symbol_map'].items())]
    aux = [[i, j] for i, j in sorted(fresh['auxiliary_map'].items())]
    require(len({r[1] for r in primary}) == len(primary) and not set(r[1] for r in primary).intersection(r[1] for r in aux),
            'physical index bijection collision')
    return dict(schema_version=1, kind='whole-union-code-reference-certificate-v2', policy_id=POLICY,
        recipe_id=fresh['recipe_id'], object_sha256=coff.digest(data), source_sha256=fresh['source_sha256'],
        roots=fresh['roots'], sections=fresh['sections'], symbols=fresh['symbols'], undefined_conversions=fresh['undefined'],
        original_union_plan_sha256=digest(fresh), complete_field_proof_sha256=fresh['field_proof_sha256'],
        groups=assessment['groups'], namespace_plan=fresh['namespace_plan'], bindings=fresh['bindings'],
        primary_bijection=primary, auxiliary_bijection=aux, section_map=fresh['section_map'],
        provenance=provenance, group_scope='all-whole-union-duplicates',
        coalescing_allowed=False, relocation_retargeting_allowed=False, **FALSE)


def namespace_union_v2(data, contracts, saved_plan, providers, certificate):
    """Guarded name-only applier; no v1 eligibility override or record merging."""
    recomputed = certify_union(data, contracts, saved_plan, providers, certificate['provenance'])
    require(digest(recomputed) == digest(certificate), 'certificate does not recompute for this exact union')
    obj = coff.parse(data); result = bytearray(data); extra = bytearray(); expected = {i: dict(s) for i, s in obj['symbols'].items()}
    allowed = set(range(obj['string_pointer'], obj['string_pointer'] + 4)); seen = set()
    targets = defaultdict(list)
    for index, name in certificate['bindings']: targets[name].append(index)
    groups = {g['name']: g['members'] for g in certificate['groups']}
    require({n: sorted(v) for n, v in targets.items() if len(v) > 1} == groups, 'hidden/omitted duplicate certificate')
    existing = {s['name'] for s in obj['symbols'].values()}
    for index, name in certificate['bindings']:
        require(index in obj['symbols'] and index not in seen and name not in existing and
                isinstance(name, str) and all(33 <= ord(c) <= 126 for c in name), 'namespace index/name collision')
        symbol = obj['symbols'][index]
        require(symbol['storage'] in (2, 3) and symbol['section'] >= 0 and not symbol['aux_count'], 'unsupported namespace record')
        offset = obj['symbol_pointer'] + 18 * index
        require(obj['string_length'] + len(extra) <= 0xffffffff, 'string extent overflow')
        struct.pack_into('<II', result, offset, 0, obj['string_length'] + len(extra))
        extra += name.encode('ascii') + b'\0'; expected[index]['name'] = name; seen.add(index); allowed.update(range(offset, offset + 8))
    require(obj['string_length'] + len(extra) <= 0xffffffff, 'string extent overflow')
    struct.pack_into('<I', result, obj['string_pointer'], obj['string_length'] + len(extra)); result += extra
    after = coff.parse(bytes(result))
    require(after['symbols'] == expected and after['sections'] == obj['sections'] and
            all(a == b or i in allowed for i, (a, b) in enumerate(zip(data, result))), 'name-only invariant failed')
    return bytes(result)


def serialize_union_v2(data, contracts, saved_plan, providers, certificate):
    """Pure test/consumer API. No disk/native driver or implicit authorization."""
    named = namespace_union_v2(data, contracts, saved_plan, providers, certificate)
    out, maps = coff.serialize(named, certificate['sections'], certificate['symbols'], certificate['undefined_conversions'])
    require([[i, j] for i, j in sorted(maps['symbol_map'].items())] == certificate['primary_bijection'] and
            [[i, j] for i, j in sorted(maps['auxiliary_map'].items())] == certificate['auxiliary_bijection'] and
            normalized(maps['section_map']) == normalized(certificate['section_map']), 'serialized whole-union bijection differs')
    before = coff.parse(data); after = coff.parse(out)
    for old, new in maps['section_map'].items():
        a, b = before['sections'][old], after['sections'][new]
        require(a['payload'] == b['payload'] and a['flags'] == b['flags'] and
                b['relocs'] == [(off, maps['symbol_map'][index], kind) for off, index, kind in a['relocs']],
                'payload/addend or original-symbol relocation retargeting')
    exports = coff.exports(out)
    names = dict(certificate['bindings'])
    expected_exports = sorted(names[i] for i in certificate['symbols'] if before['symbols'][i]['storage'] == 2
                              and before['symbols'][i]['section'] in certificate['sections'])
    require(exports == expected_exports and len(exports) == len(set(exports)), 'duplicate/extra/missing strong export')
    return out, dict(certificate_sha256=digest(certificate), maps=maps, output_sha256=coff.digest(out),
                     exports=exports, coalescing_performed=False, relocation_retargeting_performed=False, **FALSE)


def saved_records(path, unions=False):
    """Bounded records; irrelevant emitted-union lines can be large and are skipped."""
    with gzip.open(path, 'rt', encoding='utf-8') as source:
        ordinal = 0
        while True:
            line = source.readline(65536)
            if not line: return
            ordinal += 1
            require(ordinal <= 1000000, 'saved record count bound')
            skip = unions and line.startswith('{"event":"EMITTED_RECIPE_UNION"')
            if skip:
                while not line.endswith('\n'):
                    line = source.readline(65536); require(bool(line), 'truncated skipped union')
                continue
            while not line.endswith('\n'):
                chunk = source.readline(65536); require(bool(chunk), 'truncated saved record')
                line += chunk; require(len(line) <= 64 * 1024 * 1024, 'saved record bound')
            yield ordinal, json.loads(line)


def load_saved_metadata(paths, wanted_recipes=None, repository=None):
    """Pin/join complete saved evidence; never open an object, image or source body.

    Returns bounded requested recipe contracts plus the shared provider index.
    This is planning/consumer evidence, not a disk emission authorization.
    """
    repository = Path(repository or Path(__file__).resolve().parents[2])
    observations = {Path(__file__).resolve(): pool.file_hash(__file__)}
    require(set(paths) == set(INPUT_PINS), 'exact saved-input set required')
    for key, expected in INPUT_PINS.items():
        path = Path(paths[key]).resolve(); require(pool.file_hash(path) == expected, 'stale saved input: ' + key)
        observations[path] = expected
    for name, expected in PRODUCER_PINS.items():
        path = Path(__file__).with_name(name).resolve(); require(pool.file_hash(path) == expected, 'stale producer: ' + name)
        observations[path] = expected
    for module, name in ((bulk, 'bulk_code_pool.py'), (pool, 'runtime_code_pool.py'), (coff, 'coff_code_archive.py')):
        require(Path(module.__file__).resolve() == Path(__file__).with_name(name).resolve(), 'unexpected loaded producer module')
    index_path = repository / 'build/function_index.json'
    require(not index_path.exists(), 'current optional index must be absent')
    production = json.loads(Path(paths['production']).read_text(encoding='utf-8'))
    require(production['unions_sha256'] == INPUT_PINS['unions'] and production['coverage_sha256'] == INPUT_PINS['coverage']
            and production['coverage_counts'] == dict(EMITTED=12946, HISTORICAL_BLOCKED=51798, BLOCKED_UNION=3913),
            'original production partition/linkage differs')
    manifest = json.loads(Path(paths['manifest']).read_text(encoding='utf-8'))
    selection = json.loads(Path(paths['selection']).read_text(encoding='utf-8'))
    retained = json.loads(Path(paths['retained']).read_text(encoding='utf-8'))
    binding = json.loads(Path(paths['binding']).read_text(encoding='utf-8'))
    recipes = json.loads(Path(paths['recipes']).read_text(encoding='utf-8'))
    require(selection['function_index_present'] is False and retained['inputs']['function_index_present'] is False,
            'historical optional-index state differs')
    require(binding['details_sha256'] == INPUT_PINS['binding_details'] and
            binding['summary']['exact_baseline_missing_field_identities'] == 88 and
            retained['summary']['eh_comparison_errors'] == 95 and retained['strict_local_eh_diagnostics_pass'] is False and
            retained['retained_verification_pass'] is True and retained['function_byte_verification_pass'] is True,
            'retained/missing-field evidence state differs')
    units = {u['recipe_id']: u for u in manifest['units']}; proof_units = {u['recipe_id']: u for u in retained['units']}
    plans = {}; all_root_ids = set(); all_recipe_ids = set(); group_names = set()
    requested = None if wanted_recipes is None else set(wanted_recipes)
    for ordinal, row in saved_records(paths['unions'], unions=True):
        require(row['event'] == 'BLOCKED_RECIPE_UNION', 'unexpected union event')
        plan = row['plan']; rid = plan['recipe_id']; require(rid not in all_recipe_ids, 'duplicate blocked union'); all_recipe_ids.add(rid)
        unit = units[rid]
        require(plan['object_sha256'] == unit['object_sha256'] and plan['source_sha256'] == unit['source_sha256'],
                'union native/source ancestry differs')
        for root in plan['roots']:
            require(root['original_address'] not in all_root_ids, 'repeated blocked owner')
            all_root_ids.add(root['original_address'])
        if requested is None or rid in requested:
            plans[rid] = dict(plan=plan, original_union_row=dict(ordinal=ordinal, sha256=digest(row)), fields_by_root={})
            group_names.update(b['evidence']['name'] for b in plan['blockers']
                               if b['code'] in GROUP_BLOCKERS | {'REFERENCE_GROUP_ORIGINAL_SHAPE_UNSUPPORTED'})
    require(len(all_recipe_ids) == 410 and len(all_root_ids) == 3913 and
            (requested is None or set(plans) == requested), 'requested/full blocked root set differs')
    coverage = {}; coverage_counts = defaultdict(int)
    for ordinal, row in saved_records(paths['coverage']):
        coverage_counts[row['status']] += 1
        if row['status'] == 'BLOCKED_UNION':
            address = row['original_address']; require(address in all_root_ids and address not in coverage, 'coverage owner conflict')
            coverage[address] = dict(ordinal=ordinal, sha256=digest(row), inventory_row=row['historical_inventory_row'])
    require(dict(coverage_counts) == production['coverage_counts'] and set(coverage) == all_root_ids,
            'complete original coverage differs')
    provider_identities = {}; providers = defaultdict(list); root_inventory = {}
    wanted_addresses = {root['original_address'] for p in plans.values() for root in p['plan']['roots']}
    for ordinal, row in saved_records(paths['inventory']):
        if 'original_address' not in row or 'physical_identity' not in row: continue
        address = row['original_address']; identity = row['physical_identity']
        require(address not in provider_identities, 'ambiguous selected inventory provider')
        provider_identities[address] = identity
        name = pool.canonical(identity)
        if name in group_names:
            providers[name].append(dict(original_address=address, identity=identity,
                inventory_row=dict(ordinal=ordinal, sha256=digest(row))))
        if address in wanted_addresses:
            expected = coverage[address]['inventory_row']
            require(expected == dict(ordinal=ordinal, sha256=digest(row)) and row['serialization_candidate'] is True,
                    'root was not the exact historical candidate')
            root_inventory[address] = row
    require(len(provider_identities) == 68657 and set(root_inventory) == wanted_addresses, 'selected/root inventory completeness')
    for _, row in saved_records(paths['binding_details']):
        rid = row['recipe_id']
        if rid in plans and row['function_va'] in wanted_addresses:
            require(row['recipe_index'] == units[rid]['recipe_index'], 'binding unit index differs')
            require(row['coff_relocation'] is not None, 'missing original field cannot be waived')
            plans[rid]['fields_by_root'].setdefault(row['function_va'], []).append(row)
    result = {}
    for rid, bucket in plans.items():
        plan = bucket['plan']; unit = units[rid]; proof = proof_units[rid]; contracts = []
        require(proof['object_sha256'] == unit['object_sha256'] and proof['source_sha256_current'] == unit['source_sha256']
                and not proof['mismatches'], 'retained unit proof differs')
        require(recipes['units'][unit['recipe_index']] == unit['recipe'], 'exact recipe ancestry differs')
        for root in plan['roots']:
            address = root['original_address']; chosen = selection['selections'][address]
            require(chosen['recipe_id'] == rid and all(chosen[key] == root[key] for key in ('symbol', 'section', 'value', 'size'))
                    and provider_identities[address] == dict(recipe_id=rid, object_sha256=plan['object_sha256'], symbol_index=root['symbol_index']),
                    'root/provider physical selection differs')
            contracts.append(dict(recipe_id=rid, object_sha256=unit['object_sha256'], source_sha256=unit['source_sha256'], selected=root,
                verified_match=True, fields_complete=True, missing_fields_complete=True, missing_fields=[],
                fields=bucket['fields_by_root'].get(address, []), provider_identities=provider_identities,
                literal_sections=[25, 26] if rid == '0703-3a582158246b390e' and address == '0x00646d00' else []))
        fields = [row for contract in contracts for row in contract['fields']]
        assessment = assess_saved_union(plan, fields, providers)
        result[rid] = dict(plan=plan, contracts=contracts, assessment=assessment,
            provenance=dict(policy_id=POLICY, input_sha256=INPUT_PINS, producer_sha256=PRODUCER_PINS,
                implementation_sha256=observations[Path(__file__).resolve()], original_union_row=bucket['original_union_row'],
                coverage_rows={root['original_address']: coverage[root['original_address']] for root in plan['roots']}))
    require(not index_path.exists() and all(pool.file_hash(path) == value for path, value in observations.items()),
            'saved input/producer/implementation/index changed during metadata join')
    candidate_roots = sum(len(row['plan']['roots']) for row in result.values() if row['assessment']['metadata_candidate'])
    assessed_roots = sum(len(row['plan']['roots']) for row in result.values())
    return result, dict(providers), dict(selected=68657, existing_emitted=12946, historical_blocked=51798,
        original_union_blocked=3913, requested_recipes=len(plans), native_objects_opened=0,
        requested_roots=assessed_roots, metadata_candidate_roots=candidate_roots,
        assessed_still_blocked_roots=assessed_roots-candidate_roots, unassessed_union_roots=3913-assessed_roots,
        preserved_missing_field_identities=88, preserved_local_EH_notes=95, strict_local_EH_pass=False,
        input_stability_verified=True, optional_index_present=False, **FALSE)
