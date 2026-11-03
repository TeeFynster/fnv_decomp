#!/usr/bin/env python3
"""Plan original-address provider candidates; never select, alias, rewrite or link."""
from __future__ import annotations

import argparse
from collections import Counter, defaultdict
import gzip
import hashlib
import json
from pathlib import Path
import time

from coff_inventory import inspect_object, reconcile_recipes, peak_memory_bytes

ROOT = Path(__file__).resolve().parents[2]
VERIFICATION_TOOLS = ('tools/build_and_match.py', 'tools/compare.py',
    'tools/function_spans.py', 'tools/rebuild/verify_objects.py', 'tools/rebuild/coff_inventory.py')


def sha256(path):
    digest = hashlib.sha256()
    with Path(path).open('rb') as stream:
        for chunk in iter(lambda: stream.read(1024 * 1024), b''):
            digest.update(chunk)
    return digest.hexdigest()


def inventory_header(path, limit=65536):
    """Read only generated top-level provenance before summary/objects, never the graph.

    Both legacy large JSON and compact JSON have this field order. A reordered or
    oversized header is rejected rather than loading an unbounded JSON value.
    """
    with Path(path).open('rb') as stream:
        prefix = stream.read(limit).decode('utf-8-sig')
    decoder = json.JSONDecoder()
    index = 0
    def whitespace():
        nonlocal index
        while index < len(prefix) and prefix[index].isspace():
            index += 1
    whitespace()
    if prefix[index:index + 1] != '{':
        raise ValueError('inventory is not a generated JSON object')
    index += 1
    result = {}
    while True:
        whitespace()
        key, index = decoder.raw_decode(prefix, index)
        if not isinstance(key, str) or key in result:
            raise ValueError('invalid/duplicate inventory provenance key')
        whitespace()
        if prefix[index:index + 1] != ':':
            raise ValueError('invalid inventory header separator')
        index += 1
        whitespace()
        if key in ('summary', 'objects'):
            break
        value, index = decoder.raw_decode(prefix, index)
        result[key] = value
        whitespace()
        if prefix[index:index + 1] != ',':
            raise ValueError('inventory provenance incomplete or exceeds bounded header')
        index += 1
    return result


def checked_inputs(recipes, manifest_path, inventory_path):
    manifest_path = Path(manifest_path)
    manifest = json.loads(manifest_path.read_text(encoding='utf-8-sig'))
    if manifest.get('schema_version') != 1 or manifest.get('kind') != 'fnv-retained-objects':
        raise ValueError('unsupported retained-object manifest')
    reconciliation = reconcile_recipes(manifest, recipes)
    if not reconciliation['verified']:
        raise ValueError('recipe reconciliation failed: ' + '; '.join(reconciliation['errors']))
    header = inventory_header(inventory_path)
    if header.get('kind') != 'fnv-coff-link-inventory' or header.get('schema_version') != 1:
        raise ValueError('unsupported inventory provenance')
    if header.get('retained_manifest_sha256') != sha256(manifest_path):
        raise ValueError('inventory retained-manifest fingerprint mismatch')
    if header.get('recipe_manifest_sha256') != sha256(recipes):
        raise ValueError('inventory recipe fingerprint mismatch')
    if not header.get('recipe_reconciliation', {}).get('verified'):
        raise ValueError('inventory does not carry independently reconciled full coverage')
    if not header.get('supplied_manifest_complete') or header.get('errors') or header.get('omitted'):
        raise ValueError('inventory provenance records incomplete objects')
    if header.get('retained_object_count') != len(manifest['units']):
        raise ValueError('inventory object count does not match authoritative recipes')
    base = manifest_path.parent / manifest.get('object_root_relative', '.')
    seen = set()
    for unit in manifest['units']:
        if unit.get('status') != 'compiled':
            raise ValueError('all authoritative recipes must have compiled objects')
        path = (base / unit['object']).resolve()
        if path in seen:
            raise ValueError('duplicate retained object path')
        seen.add(path)
        if sha256(path) != unit['object_sha256']:
            raise ValueError('retained object fingerprint mismatch for ' + unit['recipe_id'])
    return manifest, base, header


def use_kind(symbol):
    addresses = symbol['original_addresses']
    if symbol['name'] == '__tls_array' and addresses == ['0x0000002c']:
        return 'tls_mechanism_not_image_address'
    if symbol['import_pointer']:
        return 'iat_pointer_use'
    if not addresses:
        return 'library_or_unmapped_external'
    if len(addresses) != 1:
        return 'ambiguous_own_recipe_binding'
    return 'function_use' if symbol['type'] & 0x20 else 'data_view_use'


def provider_kind(symbol, section):
    if symbol['import_pointer']:
        return 'invalid_code_backed_iat_definition' if section['flags'] & 0x20 else 'iat_pointer_definition'
    if section['name'].startswith('.tls'):
        return 'tls_data_definition'
    return 'function_definition' if section['flags'] & 0x20 else 'data_definition'


def compatible_candidates(kind, providers):
    # Equal addresses establish identity candidates, never calling-convention or
    # layout compatibility. An IAT slot is never replaced with its callee code.
    expected = {'function_use': 'function_definition', 'data_view_use': 'data_definition',
                'iat_pointer_use': 'iat_pointer_definition',
                'code_address_view_abi_unknown': 'function_definition',
                'tls_data_view_use': 'tls_data_definition'}.get(kind)
    return [p for p in providers if p['kind'] == expected] if expected else []


def selected_function_evidence(obj, unit):
    """Locate selected entries in this actual object; metadata is not byte proof."""
    result = []
    defined_by_name = defaultdict(list)
    sections = {s['index']: s for s in obj['sections']}
    for symbol in obj['symbols']:
        if symbol['section'] > 0:
            defined_by_name[symbol['name']].append(symbol)
    for function in unit['recipe'].get('functions', []):
        address = '0x%08x' % int(function['address'], 0)
        definitions = defined_by_name[function['symbol']]
        if len(definitions) != 1:
            raise ValueError('selected recipe function is absent/ambiguous in retained object: ' + function['symbol'])
        symbol = definitions[0]
        section = sections[symbol['section']]
        if not section['flags'] & 0x20 or symbol['original_addresses'] != [address]:
            raise ValueError('selected recipe function has incompatible code/address evidence: ' + function['symbol'])
        result.append(dict(name=symbol['name'], address=address,
                           section=symbol['section'], value=symbol['value']))
    return dict(names={(x['name'], x['address']) for x in result},
                locations={(x['section'], x['value'], x['address']) for x in result})


def body_basis(symbol, selected):
    address = symbol.get('original_address')
    if (symbol['name'], address) in selected['names']:
        return 'SELECTED_RECIPE_FUNCTION'
    if (symbol['section'], symbol['value'], address) in selected['locations']:
        return 'SAME_OBJECT_SELECTED_FUNCTION_ALIAS'
    return 'METADATA_BOUND_UNVERIFIED_BODY'


def canonical_json_hash(value):
    return hashlib.sha256(json.dumps(value, sort_keys=True, separators=(',', ':'),
                                    ensure_ascii=True).encode('ascii')).hexdigest()


def checked_verification(path, expected_sha256, manifest, manifest_path, recipes):
    """Consume observed verifier evidence, not a signature or proof of execution."""
    if not expected_sha256 or sha256(path) != expected_sha256:
        raise ValueError('verification receipt fingerprint mismatch or expected digest absent')
    receipt = json.loads(Path(path).read_text(encoding='utf-8-sig'))
    if receipt.get('schema_version') != 1 or receipt.get('kind') != 'fnv-retained-object-verification':
        raise ValueError('unsupported retained verification receipt')
    for flag in ('retained_verification_pass', 'function_byte_verification_pass',
                 'global_listed_eh_coverage_pass', 'original_oracle_parity_pass', 'evidence_stable'):
        if receipt.get(flag) is not True:
            raise ValueError('verification receipt lacks required function/reference evidence: ' + flag)
    if receipt.get('image_gate', {}).get('passed') is not True:
        raise ValueError('verification receipt image gate did not pass')
    if receipt.get('status') not in ('pass', 'pass_with_diagnostics'):
        raise ValueError('verification receipt status is not passing')
    inputs = receipt.get('inputs', {})
    if inputs.get('recipe_sha256') != sha256(recipes) or inputs.get('retained_manifest_sha256') != sha256(manifest_path):
        raise ValueError('verification recipe/retained-manifest fingerprint mismatch')
    if not isinstance(inputs.get('image_sha256'), str) or len(inputs['image_sha256']) != 64:
        raise ValueError('verification image observation fingerprint absent')
    tools = inputs.get('tools_sha256', {})
    if set(tools) != set(VERIFICATION_TOOLS):
        raise ValueError('verification tool fingerprint set differs from known producer contract')
    observations = {ROOT / name: digest for name, digest in tools.items()}
    observations[ROOT / 'build/image_check.json'] = inputs.get('image_check_sha256')
    index = ROOT / 'build/function_index.json'
    if inputs.get('function_index_present') is not index.is_file():
        raise ValueError('verification function-index presence changed')
    if index.is_file():
        observations[index] = inputs.get('function_index_sha256')
    elif inputs.get('function_index_sha256') is not None:
        raise ValueError('verification fingerprint for absent function index')
    if any(sha256(file) != digest for file, digest in observations.items()):
        raise ValueError('verification original core/verifier tool or index fingerprint changed')
    expected_indices = {unit['recipe_index'] for unit in manifest['units']}
    scope = receipt.get('scope', {})
    indices = scope.get('selected_recipe_indices', [])
    if (scope.get('full_authoritative') is not True or
            scope.get('authoritative_recipe_count') != len(expected_indices) or
            scope.get('manifest_recipe_count') != len(expected_indices) or
            any(type(i) is not int for i in indices) or len(indices) != len(set(indices)) or
            set(indices) != expected_indices):
        raise ValueError('verification receipt does not cover exact full authoritative recipe scope')
    proof_units = receipt.get('units', [])
    if not isinstance(proof_units, list) or len(proof_units) != len(expected_indices):
        raise ValueError('verification unit coverage incomplete')
    by_index = {}
    for proof in proof_units:
        index_value = proof.get('recipe_index')
        if type(index_value) is not int or index_value in by_index:
            raise ValueError('duplicate/invalid verification recipe index')
        by_index[index_value] = proof
    if set(by_index) != expected_indices:
        raise ValueError('verification unit indices differ from authoritative recipes')
    expected_functions = expected_bytes = 0
    for unit in manifest['units']:
        proof = by_index[unit['recipe_index']]
        recipe = unit['recipe']
        if (proof.get('recipe_id') != unit['recipe_id'] or
                proof.get('recipe_unit_sha256') != canonical_json_hash(recipe) or
                proof.get('object_sha256') != unit['object_sha256']):
            raise ValueError('verification unit recipe/object proof mismatch: ' + unit['recipe_id'])
        source_hash = unit.get('source_sha256')
        if not source_hash or proof.get('source_sha256_recorded') != source_hash or proof.get('source_sha256_current') != source_hash:
            raise ValueError('verification source observation mismatch: ' + unit['recipe_id'])
        source = Path(manifest['source_root']) / unit['source']
        if sha256(source) != source_hash:
            raise ValueError('verification source observation is stale: ' + unit['recipe_id'])
        observations[source] = source_hash
        functions = recipe.get('functions', [])
        byte_count = sum(f['size'] for f in functions)
        if (proof.get('status') != 'ok' or proof.get('functions') != len(functions) or
                proof.get('matched_functions') != len(functions) or proof.get('bytes') != byte_count or
                proof.get('matched_bytes') != byte_count or proof.get('mismatches') != []):
            raise ValueError('verification unit function result incomplete: ' + unit['recipe_id'])
        records = proof.get('verified_functions')
        if not isinstance(records, list):
            raise ValueError('verification receipt lacks specific selected-function records')
        def key(row):
            return row['symbol'], '0x%08x' % int(row['address'], 0), row['size']
        if Counter(key(row) for row in records) != Counter(key(row) for row in functions):
            raise ValueError('verification function records do not cover exact selected symbol/address/size')
        if any(row.get('verdict') != 'match' or type(row.get('section')) is not int or row['section'] <= 0
               or type(row.get('value')) is not int or row['value'] < 0 for row in records):
            raise ValueError('verification selected-function native span proof invalid')
        expected_functions += len(functions)
        expected_bytes += byte_count
    summary = receipt.get('summary', {})
    if (summary.get('units') != len(by_index) or summary.get('functions') != expected_functions or
            summary.get('matched_functions') != expected_functions or summary.get('bytes') != expected_bytes or
            summary.get('matched_bytes') != expected_bytes or summary.get('eh_inferred_conflicts') != 0 or
            summary.get('eh_tail_mismatches') != [] or summary.get('matched_eh_tails') != summary.get('eh_tails')):
        raise ValueError('verification aggregate function/global-EH evidence inconsistent')
    note_count = sum(len(unit.get('eh_errors', [])) for unit in proof_units)
    if summary.get('eh_comparison_errors') != note_count:
        raise ValueError('verification local EH diagnostic count inconsistent')
    if receipt.get('strict_local_eh_diagnostics_pass') is not (note_count == 0):
        raise ValueError('verification strict-local-EH flag contradicts diagnostics')
    observations[Path(path)] = expected_sha256
    return dict(path=Path(path), sha256=expected_sha256, units=by_index, observations=observations,
        notes=dict(retained_verification_pass=True, function_byte_verification_pass=True,
            global_listed_eh_coverage_pass=True, original_oracle_parity_pass=True,
            strict_local_eh_diagnostics_pass=receipt.get('strict_local_eh_diagnostics_pass'),
            runtime_closure_verified=False,
            local_eh_diagnostic_count=note_count,
            local_eh_diagnostic_unit_count=sum(bool(u.get('eh_errors')) for u in proof_units),
            local_eh_diagnostic_examples=[dict(recipe_id=u['recipe_id'], errors=u['eh_errors'])
                                          for u in proof_units if u.get('eh_errors')][:16],
            image_sha256_observed_by_verifier=inputs['image_sha256'],
            proof_character='Observed unchanged-comparator receipt and hash-linked inputs; not cryptographic proof of execution.'))


def verified_spans_for_object(verification, unit, obj):
    if verification is None:
        return []
    records = verification['units'][unit['recipe_index']]['verified_functions']
    by_name = defaultdict(list)
    for symbol in obj['symbols']:
        if symbol['section'] > 0:
            by_name[symbol['name']].append(symbol)
    for row in records:
        definitions = by_name[row['symbol']]
        if len(definitions) != 1 or definitions[0]['section'] != row['section'] or definitions[0]['value'] != row['value']:
            raise ValueError('verification native selected symbol/section/offset mismatch: ' + row['symbol'])
        section = next(s for s in obj['sections'] if s['index'] == row['section'])
        if row['value'] + row['size'] > section['size']:
            raise ValueError('verification selected function extends beyond its native section')
    return records


def function_byte_proof(symbol, section, basis, spans, obj):
    address = symbol.get('original_address')
    for row in spans:
        if ('0x%08x' % int(row['address'], 0) != address or row['section'] != symbol['section']
                or row['value'] != symbol['value']):
            continue
        if basis == 'SELECTED_RECIPE_FUNCTION' and row['symbol'] == symbol['name']:
            return dict(section=row['section'], value=row['value'], size=row['size'],
                        verified_symbol=row['symbol'], identity_only_alias=False)
        if (basis == 'SAME_OBJECT_SELECTED_FUNCTION_ALIAS' and row['value'] == 0 and
                section['size'] == row['size'] and not any(s['section'] == row['section'] and
                    s['type'] & 0x20 and s['value'] != 0 for s in obj['symbols'])):
            return dict(section=row['section'], value=row['value'], size=row['size'],
                        verified_symbol=row['symbol'], identity_only_alias=True)
    return None


def plan(recipes, manifest_path, inventory_path, *, candidate_stream=None,
         verification_path=None, verification_sha256=None):
    start = time.perf_counter()
    manifest, base, header = checked_inputs(recipes, manifest_path, inventory_path)
    verification = (checked_verification(verification_path, verification_sha256,
        manifest, manifest_path, recipes) if verification_path is not None else None)
    if verification_path is None and verification_sha256 is not None:
        raise ValueError('verification digest requires a verification receipt')
    providers = defaultdict(list)
    global_definitions = set()
    definition_kinds = Counter()
    definition_name_addresses = defaultdict(set)
    expected_function_addresses = set()
    expected_function_entries = 0
    object_roots = Counter()
    # First pass holds only a compact provider index; object payloads and their
    # relocation lists become unreachable before the next object is inspected.
    for unit in manifest['units']:
        for function in unit['recipe'].get('functions', []):
            expected_function_addresses.add('0x%08x' % int(function['address'], 0))
            expected_function_entries += 1
        obj = inspect_object(base / unit['object'], unit)
        selected = selected_function_evidence(obj, unit)
        spans = verified_spans_for_object(verification, unit, obj)
        sections = {s['index']: s for s in obj['sections']}
        associative_children = Counter(s['association'] for s in obj['sections']
                                       if s['selection'] == 'associative')
        object_roots.update(s['name'] for s in obj['sections'] if s['name'].startswith(('.CRT$', '.tls', '.sxdata')))
        actual_defs = [s for s in obj['symbols'] if s['kind'] in
                       ('external_definition', 'absolute_definition', 'common_definition') or
                       (s['storage'] == 3 and s['section'] > 0 and s['original_addresses']
                        and s['name'] != sections[s['section']]['name'])]
        for symbol in actual_defs:
            local = symbol['storage'] == 3
            if not local:
                global_definitions.add(symbol['name'])
                definition_name_addresses[symbol['name']].update(symbol['original_addresses'])
            if symbol['section'] <= 0 or len(symbol['original_addresses']) != 1:
                definition_kinds['unmapped_or_nonsection_definition'] += 1
                continue
            section = sections[symbol['section']]
            kind = provider_kind(symbol, section)
            basis = body_basis(symbol, selected) if kind == 'function_definition' else 'METADATA_BOUND_DATA_VIEW_UNVERIFIED'
            byte_proof = function_byte_proof(symbol, section, basis, spans, obj) if kind == 'function_definition' else None
            definition_kinds[kind] += 1
            providers[symbol['original_address']].append(dict(
                recipe_id=unit['recipe_id'], recipe_index=unit['recipe_index'], source=unit['source'],
                symbol=symbol['name'], symbol_index=symbol['index'], kind=kind,
                visibility='object_local_requires_explicit_remap' if local else 'external',
                reference_selection_basis=basis,
                byte_comparison_status='HASH_BOUND_SELECTED_FUNCTION_MATCH' if byte_proof else
                    ('UNVERIFIED_BODY_OR_DATA_VIEW' if verification else 'NO_HASH_BOUND_ORACLE_RECEIPT_FOR_THIS_OBJECT'),
                hash_bound_function_byte_verified=byte_proof is not None,
                verified_function_span=byte_proof,
                abi_verified=False,
                runtime_closure_verified=False,
                own_unit_local_eh_diagnostic_count=len(verification['units'][unit['recipe_index']].get('eh_errors', []))
                    if verification else None,
                eligible_for_selection=False,
                section=symbol['section'], value=symbol['value'],
                section_name=section['name'], section_flags=section['flags'],
                comdat=section['comdat'], selection=section['selection'],
                associative_children=associative_children[symbol['section']],
                selection_state='UNSELECTED',
                closure='whole-object-selection-required' if not section['comdat']
                    else 'COMDAT-and-EH-and-initializer-closure-review-required'))
    raw_names = {}
    use_counts = Counter()
    relocation_use_counts = Counter()
    resolved_by_name = Counter()
    name_binding_consistency = Counter()
    name_binding_examples = []
    weak_uses = Counter()
    use_examples = []
    address_use_counts = Counter()
    raw_use_counts = Counter()
    raw_candidate_use_counts = Counter()
    # Second pass classifies each undefined symbol using only its own recipe
    # bindings; no cross-unit name map is ever used to supply an address.
    for unit in manifest['units']:
        path = base / unit['object']
        if sha256(path) != unit['object_sha256']:
            raise ValueError('retained object changed during analysis: ' + unit['recipe_id'])
        obj = inspect_object(path, unit)
        relocation_counts = Counter(r['target_index'] for r in obj['relocations'])
        for symbol in obj['symbols']:
            if symbol['kind'] == 'weak_external':
                weak_uses[str(symbol['weak']['search'])] += 1
                continue
            if symbol['kind'] != 'undefined_external':
                continue
            kind = use_kind(symbol)
            address = symbol.get('original_address')
            at_address = providers.get(address, [])
            if kind == 'data_view_use' and at_address:
                kinds = {p['kind'] for p in at_address}
                if kinds == {'function_definition'}:
                    kind = 'code_address_view_abi_unknown'
                elif kinds == {'tls_data_definition'}:
                    kind = 'tls_data_view_use'
            use_counts[kind] += 1
            relocation_use_counts[kind] += relocation_counts[symbol['index']]
            if symbol['name'] in global_definitions:
                resolved_by_name[kind] += 1
                definition_addresses = definition_name_addresses[symbol['name']]
                if not symbol['original_addresses']:
                    consistency = 'own_binding_absent'
                elif not definition_addresses:
                    consistency = 'provider_binding_absent'
                elif not set(symbol['original_addresses']) <= definition_addresses:
                    consistency = 'own_address_not_in_named_provider_addresses'
                elif len(definition_addresses) > 1:
                    consistency = 'named_provider_has_multiple_original_addresses'
                else:
                    consistency = 'own_and_named_provider_address_agree_abi_unverified'
                name_binding_consistency[consistency] += 1
                if consistency in ('own_address_not_in_named_provider_addresses',
                                    'named_provider_has_multiple_original_addresses') and len(name_binding_examples) < 50:
                    name_binding_examples.append(dict(recipe_id=unit['recipe_id'], symbol=symbol['name'],
                        own_addresses=symbol['original_addresses'], provider_addresses=sorted(definition_addresses),
                        category=consistency))
                continue
            record = raw_names.setdefault(symbol['name'], dict(occurrences=0, with_candidates=0,
                without_candidates=0, kinds=set(), addresses=set(), relocation_count=0))
            record['occurrences'] += 1
            raw_use_counts[kind] += 1
            record['kinds'].add(kind)
            record['addresses'].update(symbol['original_addresses'])
            record['relocation_count'] += relocation_counts[symbol['index']]
            candidates = compatible_candidates(kind, at_address)
            if candidates:
                record['with_candidates'] += 1
                raw_candidate_use_counts[kind] += 1
            else:
                record['without_candidates'] += 1
            if address:
                address_use_counts[address] += 1
            if len(use_examples) < 50 and candidates:
                use_examples.append(dict(recipe_id=unit['recipe_id'], symbol=symbol['name'],
                    kind=kind, original_addresses=symbol['original_addresses'],
                    candidate_count=len(candidates), provider_examples=candidates[:3],
                    selected_provider=None, abi_verified=False))
    categories = Counter()
    missing_examples = []
    for name, record in raw_names.items():
        if record['with_candidates'] == record['occurrences']:
            category = 'all_own_bound_uses_have_address_provider_candidates'
        elif record['with_candidates']:
            category = 'some_own_bound_uses_have_address_provider_candidates'
        elif record['kinds'] == {'iat_pointer_use'}:
            category = 'iat_import_provider_required'
        elif record['kinds'] == {'tls_mechanism_not_image_address'}:
            category = 'tls_mechanism_not_image_address'
        elif 'tls_mechanism_not_image_address' in record['kinds'] and record['kinds'] <= {'tls_mechanism_not_image_address', 'library_or_unmapped_external'}:
            category = 'tls_mechanism_or_unmapped_own_binding'
        elif record['kinds'] == {'library_or_unmapped_external'}:
            category = 'library_or_own_binding_absent'
        else:
            category = 'no_compatible_address_provider_in_retained_objects'
        record['category'] = category
        categories[category] += 1
        if category == 'no_compatible_address_provider_in_retained_objects':
            missing_examples.append(dict(name=name, occurrences=record['occurrences'],
                relocation_count=record['relocation_count'], kinds=sorted(record['kinds']),
                original_addresses=sorted(record['addresses'])))
    candidates = []
    variant_groups = 0
    for address, entries in providers.items():
        recipe_count = len({p['recipe_id'] for p in entries})
        variant_groups += recipe_count > 1
        group = dict(address=address, candidate_count=len(entries), distinct_recipe_count=recipe_count,
            external_use_occurrences=address_use_counts[address], selected_provider=None,
            selection_state='UNSELECTED', abi_verified=False, candidates=entries)
        if candidate_stream is not None:
            candidate_stream.write(json.dumps(group, separators=(',', ':')) + '\n')
        candidates.append(group)
    candidates.sort(key=lambda g: (-g['distinct_recipe_count'], -g['candidate_count'], g['address']))
    def bounded_group(group):
        return dict(group, candidates=group['candidates'][:10],
                    examples_truncated=len(group['candidates']) > 10)
    collisions = [dict(name=name, original_addresses=sorted(addresses))
                  for name, addresses in definition_name_addresses.items() if len(addresses) > 1]
    function_coverage = Counter(dict(none=0, one=0, multiple_unselected=0))
    recipe_coverage = Counter(dict(none=0, one_recipe=0, multiple_recipes_unselected=0))
    selected_coverage = Counter(dict(none=0, one=0, multiple_unselected=0))
    provider_basis_counts = Counter()
    checked_addresses = set()
    checked_basis_counts = Counter()
    for entries in providers.values():
        provider_basis_counts.update(p['reference_selection_basis'] for p in entries)
    for address, entries in providers.items():
        for provider in entries:
            if provider['hash_bound_function_byte_verified']:
                checked_addresses.add(address)
                checked_basis_counts[provider['reference_selection_basis']] += 1
    for address in expected_function_addresses:
        options = [p for p in providers.get(address, []) if p['kind'] == 'function_definition']
        function_coverage['none' if not options else 'one' if len(options) == 1 else 'multiple_unselected'] += 1
        count = len({p['recipe_id'] for p in options})
        recipe_coverage['none' if not count else 'one_recipe' if count == 1 else 'multiple_recipes_unselected'] += 1
        selected_options = [p for p in options if p['reference_selection_basis'] in
                            ('SELECTED_RECIPE_FUNCTION', 'SAME_OBJECT_SELECTED_FUNCTION_ALIAS')]
        selected_coverage['none' if not selected_options else 'one' if len(selected_options) == 1 else 'multiple_unselected'] += 1
    if verification and any(sha256(path) != digest for path, digest in verification['observations'].items()):
        raise ValueError('verification evidence changed during canonical analysis')
    return dict(schema_version=1, kind='fnv-canonical-address-plan',
        evidence='candidate identities only; no ABI, linkability, byte-match or runtime verdict',
        selection_state='UNSELECTED',
        inputs=dict(recipe_sha256=sha256(recipes), retained_manifest_sha256=sha256(manifest_path),
                    inventory_sha256=sha256(inventory_path),
                    inventory_header_verified=True, retained_objects_independently_reparsed=True),
        retained_verification=dict(consumed=True, receipt_sha256=verification['sha256'], **verification['notes'])
            if verification else dict(consumed=False),
        recipe_count=len(manifest['units']), definition_kinds=dict(definition_kinds),
        expected_function_entries=expected_function_entries,
        expected_function_address_count=len(expected_function_addresses),
        function_address_provider_counts=dict(function_coverage),
        function_address_recipe_counts=dict(recipe_coverage),
        selected_recipe_basis_function_address_counts=dict(selected_coverage),
        provider_reference_selection_basis_counts=dict(provider_basis_counts),
        hash_bound_byte_checked_provider_address_count=len(checked_addresses),
        hash_bound_byte_checked_manifest_function_address_count=len(checked_addresses & expected_function_addresses),
        hash_bound_byte_checked_provider_basis_counts=dict(checked_basis_counts),
        oracle_association='Observed retained-object receipt consumed; byte status is separate from ABI/EH closure/runtime eligibility.'
            if verification else 'Reference recipe selection only. Separate oracle rebuild results are not hash-bound to these retained objects.',
        binding_policy=dict(only_own_original_recipe_bindings=True,
            inferred_eh_bindings_consumed=False,
            missing_binding_is_missing_code=False,
            inferred_eh_note='Reference-check inferred EH names are not imported into this plan.'),
        use_occurrences=dict(use_counts), use_relocations=dict(relocation_use_counts),
        already_name_defined_occurrences=dict(resolved_by_name),
        already_name_defined_binding_consistency=dict(name_binding_consistency),
        already_name_defined_binding_conflict_examples=name_binding_examples,
        raw_unresolved_name_count=len(raw_names), raw_unresolved_categories=dict(categories),
        raw_unresolved_occurrences=sum(x['occurrences'] for x in raw_names.values()),
        raw_unresolved_use_occurrences=dict(raw_use_counts),
        raw_unresolved_candidate_use_occurrences=dict(raw_candidate_use_counts),
        raw_names_with_any_own_binding_absence=sum('library_or_unmapped_external' in x['kinds']
                                                  for x in raw_names.values()),
        candidate_provider_use_occurrences=sum(x['with_candidates'] for x in raw_names.values()),
        canonical_provider_address_count=len(providers), multi_recipe_provider_address_count=variant_groups,
        weak_external_search_occurrences=dict(weak_uses), object_root_sections=dict(object_roots),
        same_definition_name_multiple_addresses=sorted(collisions, key=lambda x: x['name']),
        candidate_group_examples=[bounded_group(g) for g in candidates[:50]],
        function_variant_examples=[bounded_group(g) for g in candidates
            if g['distinct_recipe_count'] > 1 and any(p['kind'] == 'function_definition'
                                                     for p in g['candidates'])][:20],
        use_candidate_examples=use_examples,
        absent_candidate_examples=sorted(missing_examples, key=lambda x: (-x['relocation_count'], x['name']))[:50],
        absent_candidate_examples_by_kind={kind: sorted(
            (x for x in missing_examples if kind in x['kinds']),
            key=lambda x: (-x['relocation_count'], x['name']))[:10]
            for kind in sorted(raw_use_counts)},
        closure_requirements=['Choose no recipe variant implicitly.',
            'Review COMDAT selection, associative EH/debug closure and shared sections.',
            'Preserve whole-object initializers, .CRT roots and TLS mechanisms.',
            'Equal image addresses do not establish compatible calling conventions or data layouts.',
            'IAT pointers require authentic import providers, not callee addresses.',
            'Names already present may still have duplicate or incompatible definitions.'],
        elapsed_seconds=round(time.perf_counter() - start, 3),
        peak_process_memory_bytes=peak_memory_bytes())


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--recipes', type=Path, required=True)
    parser.add_argument('--manifest', type=Path, required=True)
    parser.add_argument('--inventory', type=Path, required=True)
    parser.add_argument('--out', type=Path, required=True)
    parser.add_argument('--candidate-gzip', type=Path)
    parser.add_argument('--verification', type=Path,
                        help='optional full retained-object verification receipt')
    parser.add_argument('--verification-sha256',
                        help='explicit expected SHA-256 of the optional verification receipt')
    args = parser.parse_args()
    protected = {p.resolve() for p in (args.recipes, args.manifest, args.inventory)}
    if args.verification:
        protected.add(args.verification.resolve())
    document = json.loads(args.manifest.read_text(encoding='utf-8-sig'))
    base = args.manifest.parent / document.get('object_root_relative', '.')
    protected.update((base / u['object']).resolve() for u in document.get('units', []) if 'object' in u)
    del document
    outputs = [args.out] + ([args.candidate_gzip] if args.candidate_gzip else [])
    if any(p.resolve() in protected for p in outputs) or len({p.resolve() for p in outputs}) != len(outputs):
        parser.error('outputs must be distinct from evidence inputs and retained objects')
    if any(p.exists() for p in outputs):
        parser.error('outputs must be new paths; existing evidence will not be overwritten')
    created_candidate = False
    try:
        if args.candidate_gzip:
            args.candidate_gzip.parent.mkdir(parents=True, exist_ok=True)
            with gzip.open(args.candidate_gzip, 'xt', encoding='utf-8') as stream:
                created_candidate = True
                report = plan(args.recipes, args.manifest, args.inventory, candidate_stream=stream,
                              verification_path=args.verification, verification_sha256=args.verification_sha256)
        else:
            report = plan(args.recipes, args.manifest, args.inventory,
                          verification_path=args.verification, verification_sha256=args.verification_sha256)
    except (OSError, ValueError, KeyError, TypeError) as error:
        if created_candidate:
            args.candidate_gzip.unlink(missing_ok=True)
        parser.error(str(error))
    args.out.parent.mkdir(parents=True, exist_ok=True)
    with args.out.open('x', encoding='utf-8') as stream:
        stream.write(json.dumps(report, indent=2) + '\n')
    print(json.dumps({k: report[k] for k in ('recipe_count', 'raw_unresolved_name_count',
        'raw_unresolved_categories', 'candidate_provider_use_occurrences', 'elapsed_seconds')}))


if __name__ == '__main__':
    main()
