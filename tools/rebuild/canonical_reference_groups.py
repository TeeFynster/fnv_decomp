"""Certificate-only compatible undefined CODE references; no byte transforms.

V1 retains every physical symbol and plans the existing serializer's bijection.
It cannot emit COFF, bypass root closure, select a provider, or invoke native tools.
"""
from __future__ import annotations
import hashlib
import gzip
import importlib
import json
from pathlib import Path
import struct
import coff_code_archive as coff
from runtime_code_pool import canonical

MAIN_PINS = {
    'recipe': '62f2c8da5f0daa912abdf4576328706711c6561eef7f01c93a89cb71ad46fb6c',
    'manifest': 'bc62a5fb2553431b1e0547d11f366e52efb73096ea8ceb206c556ae5740a53eb',
    'selection': '48ae62cdc5b1754b9c4af674ef4716d53afb554882e174a93acf860eaf1c6cb1',
    'retained': '04d44b73e81982f846bfe8d81806db72ea669586b579ff22007dfd6f7d831297',
    'binding': '275714631903758efbf5a4f82e2428c6f51838f53b90d0c56d2e5dec5da1d804',
    'binding_details': '4dfc437064b16c1bb933008aebf7def8d279a903eef9cca24d0fedcc12d7d826',
    'object': 'a6c310961921f70eea2c70b9c18dba3d85ac19bffdfe3164922e9c3462ab425b',
    'source': '89d09f8b4ba6d9758fca0ac3ebd32e18c9cc82c68a739c044457ed5c005ae3c5',
}
MAIN_ROOT = dict(recipe_id='0576-dd603b7071c482c6', original_address='0x0086a850',
                 symbol_index=1215, section=199, value=0, size=4532)
MAIN_GROUP = dict(members=[289, 1392], original_base='0x0043d4d0', role='code', expected_fields=8)
MAIN_PINS.update(inventory='02a77cce3f43c1786cd027e72ffb17e76ffe6766c2823872254015b6e40549f6',
                 inventory_details='91cdc91af6530e6e80e2104cdfeb9bd6928e17fa0f75bcf066734985248f1031',
                 imports='e39b8db63ef73aea57b5dd4963ff29310524644ca36e137cd8b5461a3c90a23f')
PRODUCER_PINS = {'coff_code_archive.py': '76244d2d4dca4c1f8aa72224be1ef5c92f68976b5cda7d31b5cfe23d3cc29e64',
                 'runtime_code_pool.py': '729f189e2893c7f3a3e3cd97df7d7381ac115169e1d75cf664e6bbc1c587b277'}
ROOT_POLICY = 'root-code-closure-observation-v2'
ROOT_OBSERVER_PIN = '4bfdb5001380a3d7e5db7517033285d49ab211be68e2fcba15964f0ad5b03c53'
ROOT_DEPENDENCY_PINS = {
    'tools/rebuild/runtime_code_inventory.py': 'c2fdbd52b4b7f4b7c68f9d80ad03708ba57d42b29e5938dfcf9769366a1ffd0b',
    'tools/rebuild/runtime_gaps.py': '0399e0f91e94de781512a153ac598f4d5eb6210920bc58241542339c72904116',
    'tools/rebuild/data_plan.py': 'e013ed5f217f9beeeaf571d089a36df22b645559063e826554179cea506f5bf8',
    'tools/rebuild/import_plan.py': '6b9237ab5951e7d4a2ac2f9b0c3435f0a667a9fdebac02a4534ba0e30ba98d9c',
    'tools/rebuild/coff_inventory.py': '3518c044738046e7cd9c8be37a3b1077af750fb2e7a19db793b09999a07ee0d2',
    'tools/build_and_match.py': 'e4c5f0d8ef8546d1ff82f4f2092e5f65164495daa867c4ff25efd9e45a25d727',
    'tools/compare.py': 'cfcf5921b71b7a58b6f430d999a511fab9a68f037791bc60295a3083535544d1',
    'tools/function_spans.py': '8e1f9134d9f207dcc8b524b6bac63cf1319f64860903fef5d2a6996709444727',
    'tools/rebuild/verify_objects.py': 'b5bc673596a13c0281f35a2d085503a862623ceb3c4bd7a763f744b6924e6877',
}


def require(ok, message):
    if not ok:
        raise ValueError(message)


def digest(value):
    return hashlib.sha256(json.dumps(value, sort_keys=True, separators=(',', ':'),
                                     ensure_ascii=True).encode()).hexdigest()


def hash_ok(value):
    return isinstance(value, str) and len(value) == 64 and all(c in '0123456789abcdef' for c in value)


def file_hash(path):
    result = hashlib.sha256()
    with Path(path).open('rb') as source:
        for block in iter(lambda: source.read(1024 * 1024), b''):
            result.update(block)
    return result.hexdigest()


def records(path):
    with gzip.open(path, 'rt', encoding='utf-8') as source:
        for ordinal, line in enumerate(source, 1):
            require(ordinal <= 1000000 and len(line) <= 8 * 1024 * 1024, 'detail stream bound')
            yield ordinal, json.loads(line)


def verify_stable(observations):
    require(all(file_hash(path) == value for path, value in observations.items()),
            'input/implementation changed during observation')


def require_index_absent(repository):
    require(not (Path(repository) / 'build/function_index.json').exists(),
            'current optional function index must remain absent')


def verify_root_recomputation(observer, obj, contract, closure):
    recomputed = observer.assess_object(obj, contract)
    require(digest(contract) == closure['contract_identity_sha256'] and digest(recomputed) == digest(closure),
            'full root closure recomputation differs')


def omission_inputs(unit_groups):
    """Match observer v2's function-insertion-order full-unit evidence census."""
    fields = [row for bucket in unit_groups.values() for row in bucket['fields']
              if row['coff_relocation']['symbol_storage'] == 6 or
              row['coff_relocation']['symbol'] == '__imp__GetForegroundWindow@0']
    identities = [row for bucket in unit_groups.values() for row in bucket['row_identities']]
    return fields, identities


def observe_main(paths, closure_path, closure_sha256, closure_details_path=None, closure_details_sha256=None):
    """Read-only exact main collector, gated externally by independent review.

    It returns candidate metadata only. No CLI or automatic observation runs
    on import. The independently reviewed root certificate must already exist.
    """
    implementation_before = file_hash(__file__)
    repository = Path(__file__).resolve().parents[2]
    require_index_absent(repository)
    require(set(paths) == set(MAIN_PINS), 'exact main input set required')
    producers = {name: Path(__file__).with_name(name) for name in PRODUCER_PINS}
    require(all(file_hash(path) == PRODUCER_PINS[name] for name, path in producers.items()), 'stale producer')
    require(all(file_hash(paths[key]) == value for key, value in MAIN_PINS.items()), 'stale main evidence')
    require(hash_ok(closure_sha256) and file_hash(closure_path) == closure_sha256, 'stale root certificate')
    closure_receipt = json.loads(Path(closure_path).read_text(encoding='utf-8'))
    require(closure_receipt.get('schema_version') == 1 and
            closure_receipt.get('policy_id') == ROOT_POLICY and
            closure_receipt.get('status') == 'metadata-only' and closure_receipt.get('input_stability') is True and
            closure_receipt.get('optional_function_index_present') is False, 'root observer receipt state/schema')
    require(hash_ok(closure_details_sha256) and closure_receipt['details_sha256'] == closure_details_sha256 and
            file_hash(closure_details_path) == closure_details_sha256, 'root observer complete detail identity')
    for key, mapped in [('recipes', 'recipe'), ('manifest', 'manifest'), ('retained', 'retained'),
                        ('selection', 'selection'), ('binding', 'binding'), ('imports', 'imports')]:
        require(closure_receipt['inputs'][key] == MAIN_PINS[mapped], 'root observer input differs')
    require(closure_receipt['binding_details_sha256'] == MAIN_PINS['binding_details'], 'root field stream differs')
    protected = {}
    expected_tools = dict(ROOT_DEPENDENCY_PINS)
    expected_tools.update({'tools/rebuild/root_code_closure.py': ROOT_OBSERVER_PIN,
                           'tools/rebuild/coff_code_archive.py': PRODUCER_PINS['coff_code_archive.py']})
    require(closure_receipt['protected_tools_sha256'] == expected_tools,
            'root observer producer/dependency manifest differs')
    for relative, value in closure_receipt['protected_tools_sha256'].items():
        path = (repository / relative).resolve()
        require(path.is_relative_to(repository / 'tools') and hash_ok(value) and file_hash(path) == value,
                'root observer producer/dependency changed')
        protected[path] = value
    observer_path = Path(__file__).with_name('root_code_closure.py').resolve()
    require(protected.get(observer_path) == ROOT_OBSERVER_PIN and
            protected.get(Path(__file__).with_name('coff_code_archive.py').resolve()) == PRODUCER_PINS['coff_code_archive.py'],
            'unreviewed root observer/parser')
    certificates = []
    for _, value in records(closure_details_path):
        require(len(certificates) < 2, 'unexpected root observation count')
        certificates.append(value)
    listed = closure_receipt['certificates']
    require(len(certificates) == len(listed) == 2 and
            [digest(row) for row in certificates] == [row['certificate_sha256'] for row in listed],
            'incomplete/conflicting root observation details')
    matching = [row for row in certificates if row['recipe_id'] == MAIN_ROOT['recipe_id']]
    require(len(matching) == 1, 'exact single main certificate missing')
    closure = matching[0]
    recipe = json.loads(Path(paths['recipe']).read_text(encoding='utf-8'))
    manifest = json.loads(Path(paths['manifest']).read_text(encoding='utf-8'))
    selection = json.loads(Path(paths['selection']).read_text(encoding='utf-8'))
    retained = json.loads(Path(paths['retained']).read_text(encoding='utf-8'))
    binding = json.loads(Path(paths['binding']).read_text(encoding='utf-8'))
    inventory = json.loads(Path(paths['inventory']).read_text(encoding='utf-8'))
    imports = json.loads(Path(paths['imports']).read_text(encoding='utf-8'))
    require(imports['inputs']['reference'] == retained['inputs']['image_sha256'] and
            imports['inputs']['manifest'] == MAIN_PINS['manifest'] and
            imports['inputs']['retained'] == MAIN_PINS['retained'], 'import evidence provenance differs')
    import_records = [row for row in imports['imports'] if row['import_id'] == 175]
    require(len(import_records) == 1, 'exact original import observation missing/ambiguous')
    require(binding['details_sha256'] == MAIN_PINS['binding_details'] and
            inventory['details_sha256'] == MAIN_PINS['inventory_details'], 'detail receipt linkage differs')
    selected = selection['selections'][MAIN_ROOT['original_address']]
    require(all(selected[key] == MAIN_ROOT[key] for key in ('recipe_id', 'section', 'value', 'size')),
            'selected root differs')
    units = [row for row in manifest['units'] if row['recipe_id'] == MAIN_ROOT['recipe_id']]
    require(len(units) == 1 and units[0]['object_sha256'] == MAIN_PINS['object'] and
            units[0]['source_sha256'] == MAIN_PINS['source'], 'manifest identity differs')
    unit = recipe['units'][units[0]['recipe_index']]
    require(unit['source'] == units[0]['source'] and unit['symbols'][
        '?Int@GlobalObject2_0040c150@@QAEPAHXZ'] == MAIN_GROUP['original_base'] and
        unit['symbols']['?Int@Setting86@@QAEPAHXZ'] == MAIN_GROUP['original_base'], 'own recipe bindings differ')
    proofs = [row for row in retained['units'] if row['recipe_id'] == MAIN_ROOT['recipe_id']]
    require(len(proofs) == 1 and proofs[0]['object_sha256'] == MAIN_PINS['object'] and
            proofs[0]['source_sha256_current'] == MAIN_PINS['source'] and not proofs[0]['mismatches'],
            'retained proof identity differs')
    relevant = {}
    for _, row in records(paths['inventory_details']):
        address = row.get('original_address')
        if address in (MAIN_ROOT['original_address'], MAIN_GROUP['original_base']):
            require(address not in relevant, 'duplicate selected inventory identity')
            relevant[address] = row
    require(len(relevant) == 2, 'missing root/provider inventory identity')
    root_row = relevant[MAIN_ROOT['original_address']]; provider_row = relevant[MAIN_GROUP['original_base']]
    require(root_row['physical_identity'] == dict(recipe_id=MAIN_ROOT['recipe_id'],
            object_sha256=MAIN_PINS['object'], symbol_index=MAIN_ROOT['symbol_index']) and
            root_row['selected_native']['section'] == MAIN_ROOT['section'], 'root inventory identity differs')
    selected_provider = selection['selections'][MAIN_GROUP['original_base']]
    require(all(selected_provider[key] == provider_row['selected_native'][key]
                for key in ('section', 'value', 'size', 'symbol')) and
            selected_provider['recipe_id'] == provider_row['physical_identity']['recipe_id'], 'provider selection differs')
    identities = {r['ordinal']: r['sha256'] for r in root_row['binding_row_references']}
    require(len(identities) == root_row['binding_fields'] == 442, 'incomplete root binding coverage')
    field_proofs = []; field_ids = []; observed = set(); root_fields = []; unit_groups = {}
    for ordinal, row in records(paths['binding_details']):
        if row['recipe_id'] == MAIN_ROOT['recipe_id']:
            require(row['recipe_index'] == units[0]['recipe_index'], 'unit field recipe index differs')
            bucket = unit_groups.setdefault(row['function_va'], dict(fields=[], row_identities=[]))
            bucket['row_identities'].append(dict(ordinal=ordinal, sha256=digest(row)))
            if row['coff_relocation'] is not None:
                bucket['fields'].append(row)
        if ordinal in identities:
            require(digest(row) == identities[ordinal] and row['function_va'] == MAIN_ROOT['original_address'],
                    'stale binding row identity')
            observed.add(ordinal)
            root_fields.append(row)
            if row['coff_relocation']['symbol_index'] in MAIN_GROUP['members']:
                field_proofs.append(row); field_ids.append(dict(ordinal=ordinal, sha256=identities[ordinal]))
    require(observed == set(identities) and len(field_proofs) == 8, 'missing exact group/field coverage')
    data = Path(paths['object']).read_bytes(); obj = coff.parse(data)
    require(root_row['original_missing_fields'] == 0, 'root migration blockers remain')
    pv = proofs[0]; unit_row = units[0]
    omission_fields, omission_ids = omission_inputs(unit_groups)
    provenance = dict(binding_row_references=root_row['binding_row_references'],
        omission_binding_row_references=omission_ids, object_sha256=MAIN_PINS['object'],
        source_sha256=MAIN_PINS['source'], recipe_id=MAIN_ROOT['recipe_id'], recipe_index=unit_row['recipe_index'],
        recipe_unit_sha256=pv['recipe_unit_sha256'], recipe_manifest_sha256=MAIN_PINS['recipe'],
        producer_manifest_sha256=MAIN_PINS['manifest'], retained_proof_sha256=MAIN_PINS['retained'],
        selection_sha256=MAIN_PINS['selection'], imports_sha256=MAIN_PINS['imports'], binding_sha256=MAIN_PINS['binding'],
        binding_details_sha256=MAIN_PINS['binding_details'], reference_identity_sha256=retained['inputs']['image_sha256'],
        source_relative=unit_row['source'], producer_compiler_variant=unit_row['compiler'],
        parser_sha256=PRODUCER_PINS['coff_code_archive.py'], observer_sha256=ROOT_OBSERVER_PIN,
        optional_function_index_present=False, dependency_tools_sha256=dict(expected_tools))
    roots = [dict(original_address=MAIN_ROOT['original_address'], symbol=selected['symbol'],
        symbol_index=MAIN_ROOT['symbol_index'], section=MAIN_ROOT['section'], value=0, size=MAIN_ROOT['size'])]
    contract = dict(recipe_id=MAIN_ROOT['recipe_id'], roots=roots,
        export_policy='selected-code-only-no-source-initializers-v1', verified_match=True, fields_complete=True,
        missing_fields_complete=True, unit_proofs_complete=True, fields=root_fields, missing_fields=[],
        unit_verified_functions=pv['verified_functions'], omission_field_proofs=omission_fields,
        iat_import_observation=import_records[0],
        parent_eh=[row for row in pv.get('eh_sections', []) if row[3] == MAIN_ROOT['original_address']], provenance=provenance)
    observer = importlib.import_module('root_code_closure')
    require(Path(observer.__file__).resolve() == observer_path and file_hash(observer_path) == ROOT_OBSERVER_PIN,
            'unexpected root observer module')
    verify_root_recomputation(observer, obj, contract, closure)
    bindings = [b['evidence'] for b in root_row['blockers'] if b['code'] == 'CANONICAL_NAMESPACE_COLLISION']
    require(len(bindings) == 1, 'expected complete old-writer namespace diagnostic missing')
    names = dict(bindings[0]); keep = closure['retained_primary_indices']; cursor = 0; namespace = []
    for index in keep:
        namespace.append(dict(physical_index=index, serialized_index=cursor,
                              name=names.get(index, obj['symbols'][index]['name'])))
        cursor += 1 + obj['symbols'][index]['aux_count']
    request = dict(schema_version=1, kind='compatible-undefined-reference-request', object_sha256=MAIN_PINS['object'],
        input_sha256=dict(MAIN_PINS), root=dict(MAIN_ROOT), root_closure=closure, root_closure_sha256=digest(closure),
        retained_symbol_indices=keep, namespace_plan=namespace, field_proofs=field_proofs,
        field_proof_identities=field_ids, group=dict(members=MAIN_GROUP['members'], role='code',
            original_base=MAIN_GROUP['original_base'], original_target=MAIN_GROUP['original_base'],
            selected_provider_identity=provider_row['physical_identity'],
            selected_provider_original_address=MAIN_GROUP['original_base'],
            selected_provider_record=dict(address=MAIN_GROUP['original_base'], offset=0),
            selection_sha256=MAIN_PINS['selection'], binding_details_sha256=MAIN_PINS['binding_details']))
    result = certify(data, request)
    observations = {Path(paths[key]): value for key, value in MAIN_PINS.items()}
    observations.update(protected)
    observations.update({producers[key]: value for key, value in PRODUCER_PINS.items()})
    observations.update({Path(closure_path): closure_sha256, Path(closure_details_path): closure_details_sha256,
                         Path(__file__): implementation_before})
    verify_stable(observations)
    require_index_absent(repository)
    result.update(root_closure_file_sha256=closure_sha256, input_stability_verified=True,
                  root_closure_details_sha256=closure_details_sha256, full_root_closure_recomputed=True,
                  source_implementation_sha256=implementation_before, producer_sha256=dict(PRODUCER_PINS),
                  root_observer_protected_tools_sha256=closure_receipt['protected_tools_sha256'])
    return result


def certify(data, request):
    """Validate a complete proposed namespace and one all-undefined CODE group.

    request is candidate evidence, not trusted authorization. A consumer must
    independently bind/recompute its separate root closure and field producers.
    No requested rename or index plan is applied to the input object.
    """
    require(request.get('schema_version') == 1 and
            request.get('kind') == 'compatible-undefined-reference-request', 'request schema')
    require(hashlib.sha256(data).hexdigest() == request['object_sha256'], 'stale object')
    inputs = request['input_sha256']
    require(set(MAIN_PINS) <= set(inputs) and all(hash_ok(v) for v in inputs.values()),
            'complete hash-bound evidence identities required')
    require(inputs['object'] == request['object_sha256'], 'object evidence identity differs')
    obj = coff.parse(data)
    root = request['root']; section = obj['sections'][root['section']]
    if root['recipe_id'] == MAIN_ROOT['recipe_id']:
        require(root == MAIN_ROOT and all(inputs[key] == value for key, value in MAIN_PINS.items()),
                'exact main scope/pins differ')
        require(all(request['group'][key] == value for key, value in MAIN_GROUP.items() if key != 'expected_fields')
                and len(request['field_proofs']) == MAIN_GROUP['expected_fields'], 'exact main group differs')
    owner = obj['symbols'][root['symbol_index']]
    require(owner['section'] == root['section'] and owner['value'] == root['value'] == 0
            and section['size'] == root['size'], 'root physical identity/extent')
    closure = request['root_closure']
    require(hash_ok(request['root_closure_sha256']) and digest(closure) == request['root_closure_sha256']
            and closure.get('schema_version') == 1 and closure.get('policy_id') == ROOT_POLICY
            and closure.get('closure_observed') is True and closure.get('status') == 'observed'
            and closure.get('graph_observation_complete') is True and closure.get('root_closure_candidate') is True
            and closure.get('full_serialization_eligible') is False
            and closure.get('canonical_namespace_collisions_resolved') is False
            and closure.get('blockers') == [] and closure.get('recipe_id') == root['recipe_id'],
            'separate exact root closure binding required')
    require(len(closure['roots']) == 1 and all(closure['roots'][0][key] == value for key, value in root.items()
                                           if key != 'recipe_id')
            and closure['retained_runtime_section_indices'] == [root['section']], 'wrong root-set closure')
    sections = {root['section']} | {i for i, row in obj['sections'].items() if row['name'] == '.drectve'}
    require(closure['retained_section_indices'] == sorted(sections), 'directive/section closure differs')
    keep = request['retained_symbol_indices']
    require(keep == sorted(set(keep)) and set(keep) <= obj['symbols'].keys(), 'retained symbol indices')
    require(keep == closure['retained_primary_indices'], 'retained indices differ from separate closure')
    required = {i for i, row in obj['symbols'].items() if row['section'] in sections or
                row['name'] in ('@comp.id', '@feat.00')}
    required.update(index for sid in sections for _, index, _ in obj['sections'][sid]['relocs'])
    require(set(keep) == required, 'dropped/extra section, metadata or field symbol')
    slots = sorted(slot for index in keep for slot in range(index, index + 1 + obj['symbols'][index]['aux_count']))
    require(closure['retained_physical_slots'] == slots, 'dropped/extra retained auxiliary slots')
    require(root['symbol_index'] in keep and
            {i for _, i, _ in section['relocs']} <= set(keep), 'hidden/missing retained field index')
    planned = {}; auxiliaries = {}; cursor = 0
    for index in keep:
        planned[index] = cursor
        for offset in range(obj['symbols'][index]['aux_count']):
            auxiliaries[index + 1 + offset] = cursor + 1 + offset
        cursor += 1 + obj['symbols'][index]['aux_count']
    namespace = request['namespace_plan']
    require(len(namespace) == len(keep) and {r['physical_index'] for r in namespace} == set(keep),
            'namespace is not complete/unique')
    for row in namespace:
        require(row['serialized_index'] == planned[row['physical_index']], 'serialized index bijection differs')
        require(isinstance(row['name'], str) and row['name'] and
                all(33 <= ord(c) <= 126 for c in row['name']), 'invalid namespace name')
    group = request['group']; members = group['members']
    require(members == sorted(set(members)) and len(members) >= 2 and set(members) <= set(keep),
            'group members invalid')
    require(group['role'] == 'code', 'v1 is CODE-only, not data or IAT')
    require(group['original_base'] == group['original_target'], 'different base/target')
    provider = group['selected_provider_identity']; name = canonical(provider)
    require(group['selected_provider_original_address'] == group['original_base'], 'provider target mismatch')
    require(group['selected_provider_record'] == dict(address=group['original_base'], offset=0),
            'provider must be the exact entry, not interior or another owner')
    require(hash_ok(group['selection_sha256']) and hash_ok(group['binding_details_sha256']),
            'selection/field proof identities required')
    require(group['selection_sha256'] == inputs['selection'] and
            group['binding_details_sha256'] == inputs['binding_details'], 'stale producer identities')
    types = set()
    for index in members:
        symbol = obj['symbols'][index]
        require(symbol['storage'] == 2 and symbol['section'] == symbol['value'] == 0
                and symbol['aux_count'] == 0, 'v1 requires ordinary undefined, not definition/common/weak/aux')
        require(not symbol['name'].startswith(('__imp_', '_imp__')), 'IAT/function domain confusion')
        require(symbol['type'] in (0, 32), 'unsupported reference type')
        types.add(symbol['type'])
    require(len(types) == 1, 'incompatible reference type status')
    renamed = [r for r in namespace if r['name'] == name]
    require({r['physical_index'] for r in renamed} == set(members), 'hidden/absent duplicate namespace index')
    by_name = {}
    for row in namespace:
        by_name.setdefault(row['name'], []).append(row['physical_index'])
    require(all(len(indices) == 1 or (n == name and set(indices) == set(members))
                for n, indices in by_name.items()), 'unreviewed other duplicate namespace')
    require(not any(s['name'] == name for s in obj['symbols'].values()), 'preexisting canonical name collision')
    expected = sorted((offset, index, kind) for offset, index, kind in section['relocs'] if index in members)
    proofs = request['field_proofs']
    identities = request['field_proof_identities']
    require(len(identities) == len(proofs) and
            len({row['ordinal'] for row in identities}) == len(identities) and
            all(type(row['ordinal']) is int and row['ordinal'] > 0 and row['sha256'] == digest(proof)
                for row, proof in zip(identities, proofs)), 'stale/repeated field proof identity')
    observed = []
    require(len(proofs) == len(expected) and expected, 'complete exact group fields required')
    touched = set()
    for row in proofs:
        offset = row['source_field_offset']; rel = row['coff_relocation']; index = rel['symbol_index']
        observed.append((offset, index, rel['kind']))
        require(index in members and row['function_va'] == root['original_address']
                and row['recipe_id'] == root['recipe_id'] and row['physical_section'] == root['section']
                and row['physical_offset'] == offset and rel['offset'] == offset,
                'wrong source/physical field identity')
        require(rel['symbol'] == obj['symbols'][index]['name'] and rel['symbol_section'] == 0
                and rel['symbol_value'] == 0 and rel['symbol_storage'] == 2
                and rel['symbol_type'] == obj['symbols'][index]['type'], 'symbol proof identity mismatch')
        require(rel['kind'] == 20 and rel['width'] == 4 and rel['addend'] == 0
                and struct.unpack_from('<i', section['payload'], offset)[0] == 0,
                'only zero-addend REL32 group fields supported')
        require(not touched.intersection(range(offset, offset + 4)), 'overlapping group fields')
        touched.update(range(offset, offset + 4))
        require(row['classification'] == 'SELECTED_CODE_ENTRY'
                and row['source_resolution_basis'] == 'OWN_RECIPE_BINDING'
                and row['proof_consistency'] == 'EXACT_OWN_SOURCE_RESOLUTION'
                and row['exact_original_target_va'] == row['derived_source_symbol_base_va'] ==
                    row['expected_original_target_va'] == group['original_base']
                and row['physical_field_overlap_count'] == 1, 'wrong role/base/target/field proof')
        field = int(root['original_address'], 16) + offset
        require(row['original_field_va'] == '0x%08x' % field and
                (field + 4 + row['original_operand']) & 0xffffffff == int(group['original_base'], 16),
                'original REL32 operand does not establish exact target')
        owners = row['code_owners']
        require(row['code_ownership_ambiguous'] is False and len(owners) == 1
                and owners[0] == group['selected_provider_record'], 'ambiguous/different provider observation')
    require(sorted(observed) == expected, 'missing/repeated/hidden physical relocation')
    require({index for _, index, _ in expected} == set(members), 'unused group member')
    return dict(schema_version=1, kind='compatible-undefined-reference-certificate-candidate',
        object_sha256=request['object_sha256'], request_sha256=digest(request), root=root,
        input_sha256=inputs, field_proof_identities=identities,
        root_closure_sha256=request['root_closure_sha256'], group=group,
        field_proof_sha256=digest(proofs), exact_fields=[list(row) for row in expected],
        namespace_plan=namespace, primary_bijection=[[i, planned[i]] for i in keep],
        auxiliary_bijection=sorted([list(row) for row in auxiliaries.items()]),
        duplicate_undefined_records_retained=True, relocation_retargeting_allowed=False,
        coalescing_allowed=False, emission_performed=False, runtime_eligible=False,
        provider_selected=False, ABI_verified=False, link_ready=False,
        limitations=['Candidate requires independent root-closure and producer/receipt validation.',
                    'Old namespace writer still rejects this duplicate; no byte transform is supplied.',
                    'Native COFF/archive/link conformance remains separately required.'])
