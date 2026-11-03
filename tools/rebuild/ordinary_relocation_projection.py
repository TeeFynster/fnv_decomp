"""Pure singleton ordinary CODE field consumer. No disk, native or runtime API.

The frozen root observer discharges only its independently proved omission
layer. The frozen unresolved-pool classifier still validates every field;
neither its global recipe policy nor the reference matcher is modified.
"""
from __future__ import annotations

from collections import defaultdict
import re

import coff_code_archive as coff
import runtime_code_pool as pool
import root_code_closure as ordinary
import ordinary_code_projection as no_relocation
import bulk_code_pool as bulk

POLICY = 'ordinary-singleton-relocation-projection-v1'
require = coff.require
digest = no_relocation.digest
ROOT_KEYS = no_relocation.ROOT_KEYS
NATIVE_KEYS = no_relocation.NATIVE_KEYS
# These are old recipe-wide screening observations, never field waivers.
# A fresh positive full ordinary graph is required before inspecting this set.
OMISSION_ONLY = frozenset(('SAFESEH_REQUIRES_CLOSURE',
                          'WEAK_OR_COMMON_RECORD', 'UNSUPPORTED_AUXILIARY'))
FALSE = dict(provider_selected=False, runtime_eligible=False, ABI_verified=False,
             link_ready=False, native_tools_run=False, compiler_performed=False,
             executable_link_performed=False, game_execution_performed=False)


class UnsupportedRoot(ValueError):
    """Expected finite policy boundary; never an integrity/serializer failure."""
    def __init__(self, code, evidence=None):
        self.code = code
        self.evidence = evidence
        super().__init__(code)


def support(condition, code, evidence=None):
    if not condition:
        raise UnsupportedRoot(code, evidence)


def address(value):
    require(isinstance(value, str) and re.fullmatch(r'0x[0-9a-f]{8}', value),
            'exact original address required')
    return int(value, 16)


def classify_contract(raw, contract, certificate, requested_roots, providers, existing_exports):
    """Fresh full omission replay and frozen per-field classification.

    providers is the independently authenticated selected physical-owner map,
    not a spelling lookup. The operational factory must authenticate that map
    and both existing export ledgers before calling this pure core.
    """
    require(isinstance(raw, bytes) and 0 < len(raw) <= 16 * 1024**2, 'object bound')
    require(isinstance(contract, dict) and set(contract) == no_relocation.CONTRACT_KEYS,
            'unknown ordinary contract schema')
    require(isinstance(certificate, dict) and isinstance(providers, dict), 'proof/provider schema')
    require(isinstance(requested_roots, list) and len(requested_roots) == 1,
            'v1 requires one independently observed singleton')
    root = requested_roots[0]
    require(isinstance(root, dict) and set(root) == ROOT_KEYS, 'exact root schema')
    require(all(type(root[k]) is int for k in ('recipe_index', 'symbol_index', 'section', 'value', 'size')),
            'integer physical identity required')
    original_hash = coff.digest(raw); provenance = contract['provenance']
    require(isinstance(provenance, dict) and provenance.get('object_sha256') == original_hash and
            root['object_sha256'] == original_hash and root['source_sha256'] == provenance.get('source_sha256') and
            re.fullmatch(r'[0-9a-f]{64}', root['source_sha256']) and
            root['recipe_id'] == contract['recipe_id'] == provenance.get('recipe_id') and
            root['recipe_index'] == provenance.get('recipe_index'), 'root source/object/recipe provenance differs')
    address(root['original_address'])
    require(root['value'] == 0 and root['size'] > 0, 'whole selected entry required')
    native = {k: root[k] for k in NATIVE_KEYS}
    require(contract['roots'] == certificate.get('roots') == [native], 'singleton root scope differs')
    require(not contract['missing_fields'] and not contract['parent_eh'],
            'relocation consumer requires no missing fields/EH')
    obj = coff.parse(raw)
    fresh = ordinary.assess_object(obj, contract)
    require(fresh == certificate and fresh['contract_identity_sha256'] == digest(contract),
            'full ordinary certificate does not replay')
    require(fresh['closure_observed'] is True and fresh['root_closure_candidate'] is True and
            fresh['graph_observation_complete'] is True and not fresh['blockers'],
            'root omission is not independently proved')
    require(all(fresh[k] is False for k in ('provider_selected', 'runtime_eligible', 'namespace_approved',
                                          'full_serialization_eligible')), 'observation capability state differs')
    require(isinstance(existing_exports, (set, frozenset, list, tuple)) and
            all(isinstance(n, str) and n for n in existing_exports) and
            len(existing_exports) == len(set(existing_exports)), 'complete collision-free export census required')
    identity = {k: root[k] for k in ('recipe_id', 'object_sha256', 'symbol_index')}
    export = pool.canonical(identity)
    require(export not in existing_exports, 'existing logical CODE export cannot be replaced')
    require(providers.get(root['original_address']) == identity,
            'selected root original physical provider differs')
    support(bool(contract['fields']), 'NO_RELOCATION_FIELDS_USE_SEPARATE_CONSUMER')

    references = {(r['section'], r['offset'], r['symbol_index'], r['kind']): r for r in fresh['references']}
    require(len(references) == len(fresh['references']) == len(contract['fields']), 'complete unique field proof required')
    provider_identities = {}; evidence = []; by_symbol = {}; bases = {}; checked = []
    for row in contract['fields']:
        cr = row['coff_relocation']; si = cr['symbol_index']; target = obj['symbols'].get(si)
        require(all(type(cr.get(k)) is int for k in ('symbol_index', 'offset', 'kind', 'width', 'addend',
                    'symbol_section', 'symbol_value', 'symbol_type', 'symbol_storage')) and
                all(type(row.get(k)) is int for k in ('recipe_index', 'physical_section', 'physical_offset',
                    'source_field_offset', 'physical_field_overlap_count')), 'integer physical field metadata required')
        require(target is not None and cr['kind'] in (6, 20) and type(cr.get('width')) is int and cr['width'] == 4,
                'only exact DIR32/REL32 fields')
        require(row.get('source_resolution_basis') == 'OWN_RECIPE_BINDING' and
                row.get('proof_consistency') == 'EXACT_OWN_SOURCE_RESOLUTION' and
                row.get('function_symbol') == root['symbol'] and row.get('recipe_index') == root['recipe_index'],
                'field lacks exact own-recipe native parent proof')
        key = (row['physical_section'], cr['offset'], si, cr['kind']); ref = references.get(key)
        require(ref is not None and ref['binding_row_sha256'] == digest(row), 'field/certificate identity differs')
        base, final, role = ref['original_base'], ref['original_target'], ref['role']
        base_int, final_int = address(base), address(final)
        require(row.get('expected_original_target_va') == final and
                row['original_field_va'] == '0x%08x' % (address(root['original_address']) + row['source_field_offset']) and
                type(row['original_operand']) is int and 0 <= row['original_operand'] <= 0xffffffff,
                'original field/target geometry differs')
        operand_target = (row['original_operand'] + (address(row['original_field_va']) + 4 if cr['kind'] == 20 else 0)) & 0xffffffff
        require(operand_target == final_int, 'original operand does not resolve to proved target')
        require(role in ('code', 'data', 'iat-cell', 'crt-contract') and target['storage'] in (2, 3) and
                not target['aux_count'] and target['section'] >= 0, 'unsupported field record or role')
        require(isinstance(row.get('code_owners'), list), 'complete code-owner observation required')
        if role != 'code':
            require(row.get('code_ownership_ambiguous') is False and not row['code_owners'] and
                    base not in providers and final not in providers,
                    'non-CODE role contradicts authenticated selected provider evidence')
        elif row['classification'] == 'SELECTED_CODE_ENTRY':
            require(providers.get(base) is not None, 'selected original CODE provider missing')
            pool.canonical(providers[base])
            owners = row['code_owners']
            require(len(owners) == 1 and isinstance(owners[0], dict) and
                    set(owners[0]) == {'address', 'offset'} and type(owners[0]['offset']) is int,
                    'selected CODE owner schema differs')
        elif row['classification'] == 'UNSELECTED_EXECUTABLE_TARGET_UNCLASSIFIED':
            require(base not in providers and final not in providers,
                    'unselected CODE role contradicts authenticated provider map')
        checked.append((row, cr, si, target, ref, base, final, role, key))
    # Every source/proof/operand/provider integrity check precedes quarantine.
    # An unsupported first field cannot conceal a corrupt later field.
    for row, cr, si, target, ref, base, final, role, key in checked:
        cls = row['classification']
        if role == 'code':
            support(target['type'] == 32 and row.get('code_ownership_ambiguous') is False,
                    'UNSUPPORTED_CODE_TYPE_OR_AMBIGUOUS_OWNER', dict(symbol_index=si, classification=cls))
            if cls == 'SELECTED_CODE_ENTRY':
                owners = row.get('code_owners')
                require(isinstance(owners, list) and len(owners) == 1 and isinstance(owners[0], dict) and
                        set(owners[0]) == {'address', 'offset'} and type(owners[0]['offset']) is int,
                        'selected CODE owner schema differs')
                support(final == base and owners == [dict(address=base, offset=0)],
                        'CODE_INTERIOR_OR_NONEXACT_ENTRY_UNSUPPORTED', dict(symbol_index=si, base=base, final=final))
                provider = providers.get(base)
                require(provider is not None, 'selected original CODE provider missing')
                pool.canonical(provider)  # Strict original physical identity schema.
                provider_identities[base] = provider
                name = pool.canonical(provider)
            else:
                support(cls == 'UNSELECTED_EXECUTABLE_TARGET_UNCLASSIFIED' and not row.get('code_owners'),
                        'UNSUPPORTED_CODE_CLASS_OR_INTERIOR', dict(symbol_index=si, classification=cls))
                name = pool.unresolved(base, role)
        else:
            require(row.get('code_ownership_ambiguous') is False and not row.get('code_owners'),
                    'non-CODE role overlaps selected code ownership')
            require(base not in providers and final not in providers,
                    'non-CODE role contradicts authenticated selected provider map')
            if role == 'iat-cell':
                support(cls == 'IAT_POINTER_CELL_NOT_FUNCTION_BODY' and type(row.get('import_id')) is int and
                        row['import_id'] >= 0 and target['type'] == 0 and
                        row.get('import_pointer_source_conflict') is not True,
                        'UNSUPPORTED_IAT_TYPE_OR_CELL_CONTRACT', dict(symbol_index=si, classification=cls))
            elif role == 'crt-contract':
                support(cls == 'EXPLICIT_NORMAL_CRT_CONTRACT_CANDIDATE' and target['type'] == 32,
                        'UNSUPPORTED_CRT_TYPE_OR_CONTRACT', dict(symbol_index=si, classification=cls))
            else:
                support(target['type'] == 0 and cls in (
                    'ORIGINAL_IMAGE_DATA_REQUIRES_CANONICAL_OWNER',
                    'COMPILER_LITERAL_FULL_READONLY_NONPOINTER_EQUALITY'),
                    'UNSUPPORTED_DATA_TYPE_OR_CLASS', dict(symbol_index=si, classification=cls))
            name = pool.unresolved(base, role)
        fact = (base, role, name)
        require(si not in by_symbol or by_symbol[si] == fact, 'one physical symbol has conflicting roles/bases')
        by_symbol[si] = fact
        require(name not in bases or bases[name] == base, 'canonical name has conflicting original base')
        bases[name] = base
        evidence.append(dict(section=key[0], offset=key[1], symbol_index=si, kind=key[3],
            field_proof_sha256=digest(row), original_base=base, original_target=final,
            addend_bits=ref['addend_bits'], role=role, canonical_name=name))

    legacy = dict(recipe_id=root['recipe_id'], source_sha256=root['source_sha256'], object_sha256=original_hash,
        selected=native, verified_match=True, fields_complete=True, missing_fields_complete=True,
        fields=contract['fields'], missing_fields=[], provider_identities=provider_identities)
    assessment = pool.assess_parsed(obj, legacy)
    remaining = [b for b in assessment['blockers'] if b['code'] not in OMISSION_ONLY]
    namespace = [b for b in remaining if b['code'] == 'CANONICAL_NAMESPACE_COLLISION']
    support(not namespace, 'CANONICAL_REFERENCE_GROUP_REQUIRES_REVIEWED_V2', namespace)
    require(not remaining, 'field/namespace policy blocked: ' + ','.join(b['code'] for b in remaining))
    plan = assessment['extraction_plan']
    require(plan['sections'] == fresh['retained_section_indices'] and
            plan['symbols'] == fresh['retained_primary_indices'] and
            plan['undefined'] == sorted(c['symbol_index'] for c in fresh['omitted_definition_conversions']),
            'classifier and proved root disposition scopes differ')
    expected_names = dict(plan['bindings'])
    require(expected_names.get(root['symbol_index']) == export, 'root logical identity changed')
    for si, (base, role, name) in by_symbol.items():
        target = obj['symbols'][si]
        if target['section'] not in fresh['retained_runtime_section_indices']:
            require(expected_names.get(si) == name, 'frozen classifier namespace differs')
    groups = defaultdict(list)
    for si, name in plan['bindings']: groups[name].append(si)
    support(all(len(indices) == 1 for indices in groups.values()),
            'CANONICAL_REFERENCE_GROUP_REQUIRES_REVIEWED_V2',
            {name: indices for name, indices in groups.items() if len(indices) > 1})
    return obj, fresh, assessment, plan, evidence, bases, export


def assess_member(raw, contract, certificate, requested_roots, providers, *, existing_exports, reference_groups=None):
    """Report supported policy boundaries; integrity failures still propagate.

    The result authorizes no serialization and is never accepted as an input to
    project_member. That operation independently repeats every proof and plan.
    """
    require(reference_groups is None, 'reference-group integration is not approved by this consumer')
    binding = dict(original_object_sha256=coff.digest(raw), contract_identity_sha256=digest(contract),
                   certificate_sha256=digest(certificate), requested_roots=requested_roots)
    try:
        _, _, assessment, plan, evidence, bases, export = classify_contract(
            raw, contract, certificate, requested_roots, providers, existing_exports)
    except UnsupportedRoot as unsupported:
        return dict(schema_version=1, policy_id=POLICY, eligible=False,
            blockers=[dict(code=unsupported.code, evidence=unsupported.evidence)],
            serialization_performed=False, **binding, **FALSE)
    return dict(schema_version=1, policy_id=POLICY, eligible=True, blockers=[],
        plan=plan, fields=evidence, comparison_base_view=bases, exports=[export],
        discharged_recipe_screening_observations=[b for b in assessment['blockers'] if b['code'] in OMISSION_ONLY],
        serialization_performed=False, **binding, **FALSE)


def project_member(raw, contract, certificate, requested_roots, providers, *, existing_exports, reference_groups=None):
    """Pure field-bearing singleton projection; all live inputs stay caller-owned.

    Duplicate groups remain blocked in v1. A supplied certificate is never a
    blanket alias waiver; a later compatible V2 integration requires review.
    """
    require(reference_groups is None, 'reference-group integration is not approved by this consumer')
    obj, fresh, assessment, plan, evidence, bases, export = classify_contract(
        raw, contract, certificate, requested_roots, providers, existing_exports)
    named = coff.namespace(raw, plan['bindings'])
    output, maps = coff.serialize(named, plan['sections'], plan['symbols'], plan['undefined'])
    coff.verify_selection(named, output, maps)
    sm, ym, am = bulk.slot_maps(obj, plan['sections'], plan['symbols'])
    require(maps['section_map'] == sm and maps['symbol_map'] == ym and maps['auxiliary_map'] == am,
            'physical primary/auxiliary bijection differs')
    require(coff.exports(output) == [export], 'only selected CODE root may be exported')
    after = coff.parse(output)
    expected_slots = sorted(k for i in plan['symbols'] for k in range(i, i + 1 + obj['symbols'][i]['aux_count']))
    require(expected_slots == fresh['retained_physical_slots'], 'retained physical slot coverage differs')
    for old, new in sm.items():
        before, final = obj['sections'][old], after['sections'][new]
        require(before['payload'] == final['payload'] and before['flags'] == final['flags'] and
                final['relocs'] == [(off, ym[si], kind) for off, si, kind in before['relocs']],
                'field/addend bytes or original physical relocation target changed')
    names = dict(plan['bindings'])
    undefined = [dict(original_symbol_index=i, serialized_symbol_index=ym[i], name=names[i],
                      original_base=next(e['original_base'] for e in evidence if e['symbol_index'] == i))
                 for i in plan['symbols'] if after['symbols'][ym[i]]['section'] == 0]
    require(all(after['symbols'][u['serialized_symbol_index']]['storage'] == 2 and
                after['symbols'][u['serialized_symbol_index']]['value'] == 0 for u in undefined),
            'unresolved record status differs')
    return output, dict(schema_version=1, policy_id=POLICY, original_object_sha256=coff.digest(raw),
        output_sha256=coff.digest(output), contract_identity_sha256=digest(contract), certificate_sha256=digest(certificate),
        requested_roots=requested_roots, maps=maps, exports=[export], namespace_bindings=plan['bindings'],
        comparison_base_view=bases, undefined=undefined, fields=evidence,
        discharged_recipe_screening_observations=[b for b in assessment['blockers'] if b['code'] in OMISSION_ONLY],
        complete_frozen_root_replay=True, complete_frozen_field_classification=True,
        omission_scope_only=True, reference_groups_waived=False, **FALSE)
