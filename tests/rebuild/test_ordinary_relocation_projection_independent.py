"""Independent authored COFF adversarial tests; no game inputs or native tools."""
import copy
import hashlib
from pathlib import Path
import struct
import sys
import unittest
from unittest.mock import patch

ROOT = Path(__file__).resolve().parents[2]
sys.path[:0] = [str(ROOT / 'tools/rebuild'), str(ROOT / 'tests/rebuild')]
import coff_code_archive as coff
import scalableordinary_root_collect as collector
import root_code_closure as ordinary
import runtime_code_pool as pool
import ordinary_relocation_projection as projection
import ordinary_code_projection as no_relocation
from test_coff_code_archive import section, symbol, aux, object_bytes


def authored(*, classes=('SELECTED_CODE_ENTRY',), kinds=None, addends=None,
             target_types=None, safeseh=False, weak=False, parent_eh=False,
             selection=1, directive=None, duplicate_names=False, repeated_target=False):
    """Independent encoder; fields are declarations of invented addresses only."""
    count = len(classes)
    kinds = kinds or (20,) * count
    addends = addends or (0,) * count
    target_types = target_types or tuple(32 if ('CODE' in c or 'CRT' in c) else 0 for c in classes)
    payload = bytearray(16)
    relocations = []
    for n, (kind, addend) in enumerate(zip(kinds, addends)):
        struct.pack_into('<I', payload, 4 + n * 4, addend & 0xffffffff)
        relocations.append((4 + n * 4, 9 if repeated_target else 9 + n, kind))
    directives = directive or b' /DEFAULTLIB:"LIBCMT" /DEFAULTLIB:"OLDNAMES" '
    sections = [section('.text', bytes(payload), relocs=relocations),
                section('.text', bytes(8)), section('.drectve', directives, 0x100a00)]
    symbols = [symbol('.text', 1, storage=3, auxiliary=aux(16, count, selection)),
               symbol('_alpha', 1, typ=32),
               symbol('.text', 2, storage=3, auxiliary=aux(8)), symbol('_beta', 2, typ=32),
               symbol('.drectve', 3, storage=3, auxiliary=aux(len(directives), selection=0)),
               symbol('@feat.00', -1, value=1, storage=3)]
    names = []
    for n, cls in enumerate(classes):
        name = '__imp__authored_cell' if cls == 'IAT_POINTER_CELL_NOT_FUNCTION_BODY' else '_external%d' % (0 if duplicate_names else n)
        names.append(name)
        symbols.append(symbol(name, 0, typ=target_types[n]))
    if safeseh:
        sections.append(section('.sxdata', struct.pack('<I', 5), 0x300200))
        symbols.append(symbol('.sxdata', len(sections), storage=3, auxiliary=aux(4, selection=0)))
    if weak:
        symbols.append(symbol('_unrelated_weak', 0, storage=105,
                              auxiliary=struct.pack('<II', 5, 2) + bytes(10)))
    raw = object_bytes(sections, symbols)
    sha = hashlib.sha256(raw).hexdigest()
    functions = [dict(symbol='_alpha', address='0x00500000', size=16),
                 dict(symbol='_beta', address='0x00500100', size=8)]
    unit = dict(recipe_id='independent-authored', recipe_index=0,
                object_sha256=sha, source_sha256='b' * 64)
    verified = [dict(f, section=n + 1, value=0, verdict='match') for n, f in enumerate(functions)]
    root = dict(original_address='0x00500000', recipe_id=unit['recipe_id'], recipe_index=0,
                object_sha256=sha, source_sha256='b' * 64, symbol='_alpha',
                symbol_index=2, section=1, value=0, size=16)
    fields = []
    providers = {root['original_address']: {k: root[k] for k in ('recipe_id', 'object_sha256', 'symbol_index')}}
    for n, cls in enumerate(classes):
        base = 0x00600000  # Duplicate canonical records are intentional when count > 1.
        final = (base + addends[n]) & 0xffffffff
        kind = kinds[n]
        off = 4 + n * 4
        original_field = 0x00500000 + off
        row = dict(recipe_id=unit['recipe_id'], recipe_index=0, function_va=root['original_address'],
                   function_symbol='_alpha', physical_section=1, physical_offset=off,
                   source_field_offset=off, original_field_va='0x%08x' % original_field,
                   coff_relocation=dict(offset=off, symbol_index=9 + n, kind=kind,
                       symbol=names[0] if repeated_target else names[n], symbol_section=0, symbol_value=0,
                       symbol_type=target_types[n], symbol_storage=2,
                       addend=addends[n] & 0xffffffff, width=4, conservative_extent=4),
                   derived_source_symbol_base_va='0x%08x' % base,
                   exact_original_target_va='0x%08x' % final,
                   expected_original_target_va='0x%08x' % final,
                   classification=cls, proof_consistency='EXACT_OWN_SOURCE_RESOLUTION',
                   physical_field_overlap_count=1, code_ownership_ambiguous=False,
                   code_owners=[dict(address='0x%08x' % base, offset=0)] if cls == 'SELECTED_CODE_ENTRY' else [],
                   original_operand=(final - (original_field + 4 if kind == 20 else 0)) & 0xffffffff,
                   source_resolution_basis='OWN_RECIPE_BINDING')
        if cls == 'IAT_POINTER_CELL_NOT_FUNCTION_BODY':
            row['import_id'] = 123
        if repeated_target:
            row['coff_relocation']['symbol_index'] = 9
        fields.append(row)
        if cls == 'SELECTED_CODE_ENTRY':
            providers['0x%08x' % base] = dict(recipe_id='selected-external', object_sha256='d' * 64, symbol_index=77)
    bindings = {root['original_address']: dict(fields=fields, missing_fields=[],
                 row_identities=[dict(ordinal=n + 1, sha256=collector.digest(f)) for n, f in enumerate(fields)])}
    proof = dict(verified_functions=verified,
                 eh_sections=[[1, 4, False, root['original_address'], []]] if parent_eh else [])
    provenance = dict(object_sha256=sha, source_sha256='b' * 64,
                      recipe_id=unit['recipe_id'], recipe_index=0)
    contract = collector.build_contract(unit, proof, [root], bindings, {}, provenance)
    certificate = ordinary.assess_object(coff.parse(raw), contract)
    return raw, contract, certificate, [root], providers


def replay(values):
    raw, contract, _, roots, providers = values
    return raw, contract, ordinary.assess_object(coff.parse(raw), contract), roots, providers


def project(values, **kwargs):
    raw, contract, certificate, roots, providers = values
    return projection.project_member(raw, contract, certificate, roots, providers,
                                     existing_exports=kwargs.pop('existing_exports', set()), **kwargs)


def assess(values, **kwargs):
    raw, contract, certificate, roots, providers = values
    return projection.assess_member(raw, contract, certificate, roots, providers,
                                    existing_exports=kwargs.pop('existing_exports', set()), **kwargs)


class IndependentOrdinaryRelocationTests(unittest.TestCase):
    def assert_rejected(self, values, **kwargs):
        with self.assertRaises((ValueError, KeyError, TypeError)):
            project(values, **kwargs)

    def test_zero_relocation_singleton(self):
        values = authored(classes=())
        self.assertTrue(values[2]['closure_observed'])
        self.assert_rejected(values)  # Field-bearing core deliberately delegates this separate policy.
        output, receipt = no_relocation.project_member(*values[:4])
        obj = coff.parse(output)
        expected = pool.canonical({k: values[3][0][k] for k in ('recipe_id', 'object_sha256', 'symbol_index')})
        self.assertEqual(coff.exports(output), [expected])
        self.assertTrue(all(not s['relocs'] for s in obj['sections'].values()))
        self.assertFalse(receipt['runtime_eligible'])

    def test_dir32_data_nonzero_addend_preserved_as_unresolved_data(self):
        values = authored(classes=('ORIGINAL_IMAGE_DATA_REQUIRES_CANONICAL_OWNER',), kinds=(6,), addends=(4,))
        self.assertTrue(values[2]['closure_observed'])
        output, _ = project(values)
        obj = coff.parse(output)
        sec = next(s for s in obj['sections'].values() if s['name'] == '.text')
        off, target, kind = sec['relocs'][0]
        self.assertEqual((off, kind), (4, 6))
        self.assertEqual(sec['payload'], coff.parse(values[0])['sections'][1]['payload'])
        self.assertEqual(obj['symbols'][target]['name'], pool.unresolved('0x00600000', 'data'))
        self.assertEqual(obj['symbols'][target]['section'], 0)

    def test_rel32_selected_code_uses_old_physical_provider_identity(self):
        values = authored()
        output, _ = project(values)
        obj = coff.parse(output)
        sec = next(s for s in obj['sections'].values() if s['name'] == '.text')
        target = sec['relocs'][0][1]
        self.assertEqual(obj['symbols'][target]['name'], pool.canonical(values[4]['0x00600000']))
        self.assertNotEqual(obj['symbols'][target]['name'], pool.canonical(dict(recipe_id='independent-authored',
                             object_sha256=hashlib.sha256(output).hexdigest(), symbol_index=target)))
        self.assertEqual((obj['symbols'][target]['section'], obj['symbols'][target]['value']), (0, 0))

    def test_negative_rel32_crt_addend_preserved(self):
        values = authored(classes=('EXPLICIT_NORMAL_CRT_CONTRACT_CANDIDATE',), addends=(-4,))
        self.assertTrue(values[2]['closure_observed'])
        output, _ = project(values)
        obj = coff.parse(output)
        sec = next(s for s in obj['sections'].values() if s['name'] == '.text')
        self.assertEqual(struct.unpack_from('<I', sec['payload'], 4)[0], 0xfffffffc)
        self.assertEqual(obj['symbols'][sec['relocs'][0][1]]['name'], pool.unresolved('0x00600000', 'crt-contract'))

    def test_iat_pointer_cell_retains_data_role(self):
        values = authored(classes=('IAT_POINTER_CELL_NOT_FUNCTION_BODY',), kinds=(6,))
        output, _ = project(values)
        obj = coff.parse(output)
        target = next(s for s in obj['sections'].values() if s['name'] == '.text')['relocs'][0][1]
        self.assertEqual(obj['symbols'][target]['name'], pool.unresolved('0x00600000', 'iat-cell'))

    def test_unrelated_safeseh_and_weak_are_omission_evidence_only(self):
        values = authored(safeseh=True, weak=True)
        self.assertTrue(values[2]['closure_observed'])
        output, receipt = project(values)
        self.assertFalse(any(s['name'] == '.sxdata' for s in coff.parse(output)['sections'].values()))
        self.assertFalse(any(s['storage'] == 105 for s in coff.parse(output)['symbols'].values()))
        self.assertFalse(receipt['runtime_eligible'])

    def test_parent_eh_comdat2_and_unknown_directive_remain_blocked(self):
        for options in (dict(parent_eh=True), dict(selection=2),
                        dict(directive=b' /DEFAULTLIB:"LIBCMT" /DEFAULTLIB:"OLDNAMES" /UNKNOWN:authored ')):
            with self.subTest(options=options):
                values = authored(**options)
                self.assertFalse(values[2]['closure_observed'])
                self.assert_rejected(values)

    def test_unknown_special_roles_and_target_type_are_not_data_fallback(self):
        for cls in ('UNKNOWN_FUTURE_ROLE', 'STATIC_TLS_INDEX_REQUIRES_CANONICAL_OWNER',
                    'COMPILER_LOCAL_EH_METADATA_OR_HELPER_CANDIDATE'):
            with self.subTest(cls=cls):
                self.assert_rejected(authored(classes=(cls,)))
        self.assert_rejected(authored(target_types=(0,)))
        self.assert_rejected(authored(classes=('ORIGINAL_IMAGE_DATA_REQUIRES_CANONICAL_OWNER',),
                                      kinds=(6,), target_types=(32,)))

    def test_same_canonical_name_distinct_physical_refs_require_exact_v2(self):
        values = authored(classes=('SELECTED_CODE_ENTRY', 'SELECTED_CODE_ENTRY'))
        self.assertTrue(values[2]['closure_observed'])
        self.assert_rejected(values)
        self.assert_rejected(values, reference_groups={'approved': True, 'indices': [9, 10]})

    def test_repeated_reference_to_one_original_index_preserves_target_index(self):
        values = authored(classes=('SELECTED_CODE_ENTRY', 'SELECTED_CODE_ENTRY'), repeated_target=True)
        self.assertTrue(values[2]['closure_observed'])
        output, receipt = project(values)
        obj = coff.parse(output)
        refs = next(s for s in obj['sections'].values() if s['name'] == '.text')['relocs']
        self.assertEqual(len(refs), 2)
        self.assertEqual(refs[0][1], refs[1][1])
        self.assertEqual(refs[0][1], receipt['maps']['symbol_map'][9])
        self.assertNotIn(10, receipt['maps']['symbol_map'])

    def test_provider_missing_ambiguous_interior_or_malformed_cannot_be_guessed(self):
        values = authored()
        for how in ('missing', 'ambiguous', 'interior', 'bad-index', 'bad-hash', 'extra-field'):
            changed = copy.deepcopy(values)
            if how == 'missing': changed[4].clear()
            elif how == 'ambiguous': changed[1]['fields'][0]['code_ownership_ambiguous'] = True
            elif how == 'interior': changed[1]['fields'][0]['code_owners'][0]['offset'] = 1
            elif how == 'bad-index': changed[4]['0x00600000']['symbol_index'] = True
            elif how == 'bad-hash': changed[4]['0x00600000']['object_sha256'] = 'not-a-hash'
            else: changed[4]['0x00600000']['approval'] = True
            with self.subTest(how=how): self.assert_rejected(replay(changed))

    def test_non_code_role_cannot_hide_selected_code_owner(self):
        for cls, kind in (('ORIGINAL_IMAGE_DATA_REQUIRES_CANONICAL_OWNER', 6),
                          ('IAT_POINTER_CELL_NOT_FUNCTION_BODY', 6),
                          ('EXPLICIT_NORMAL_CRT_CONTRACT_CANDIDATE', 20)):
            for owned in ('0x00600000', '0x00600004'):
                values = authored(classes=(cls,), kinds=(kind,), addends=(4,))
                values[4][owned] = dict(recipe_id='contradictory-code-owner',
                                       object_sha256='e' * 64, symbol_index=88)
                with self.subTest(cls=cls, owned=owned): self.assert_rejected(values)

    def test_role_and_addend_proof_geometry_must_replay_exactly(self):
        values = authored()
        for key, value in (('physical_offset', 8), ('source_field_offset', 8),
                           ('exact_original_target_va', '0x00600004'),
                           ('derived_source_symbol_base_va', '0x00600004'),
                           ('physical_field_overlap_count', 2), ('original_operand', 123)):
            changed = copy.deepcopy(values)
            changed[1]['fields'][0][key] = value
            with self.subTest(key=key): self.assert_rejected(replay(changed))
        for key, value in (('symbol_index', 5), ('symbol_type', 0), ('symbol_storage', 3), ('addend', 4)):
            changed = copy.deepcopy(values)
            changed[1]['fields'][0]['coff_relocation'][key] = value
            with self.subTest(relocation_key=key): self.assert_rejected(replay(changed))

    def test_bool_cannot_stand_in_for_exact_field_recipe_or_owner_offset(self):
        values = authored()
        for change in ('recipe_index', 'owner_offset'):
            changed = copy.deepcopy(values)
            if change == 'recipe_index': changed[1]['fields'][0]['recipe_index'] = False
            else: changed[1]['fields'][0]['code_owners'][0]['offset'] = False
            with self.subTest(change=change): self.assert_rejected(replay(changed))

    def test_stale_contract_certificate_raw_and_root_identity_fail(self):
        values = authored()
        changed = list(copy.deepcopy(values)); changed[0] += b'changed'; self.assert_rejected(changed)
        changed = copy.deepcopy(values); changed[1]['provenance']['object_sha256'] = 'f' * 64; self.assert_rejected(changed)
        changed = copy.deepcopy(values); changed[2]['provider_selected'] = True; self.assert_rejected(changed)
        for key, value in (('symbol_index', 5), ('section', 2), ('source_sha256', 'f' * 64),
                           ('recipe_id', 'other'), ('recipe_index', True), ('size', 8)):
            changed = copy.deepcopy(values); changed[3][0][key] = value
            with self.subTest(key=key): self.assert_rejected(changed)

    def test_existing_export_collision_and_unknown_v2_certificate_fail_closed(self):
        values = authored()
        root_name = pool.canonical({k: values[3][0][k] for k in ('recipe_id', 'object_sha256', 'symbol_index')})
        self.assert_rejected(values, existing_exports={root_name})
        self.assert_rejected(values, reference_groups={'policy_id': 'invented-v2', 'approved': True})

    def test_structured_assessment_is_bound_and_never_serializes(self):
        values = authored()
        with patch.object(coff, 'serialize', side_effect=AssertionError('assessment serialized')):
            result = assess(values)
        self.assertTrue(result['eligible'])
        self.assertEqual(result['blockers'], [])
        self.assertEqual(result['original_object_sha256'], hashlib.sha256(values[0]).hexdigest())
        self.assertEqual(result['contract_identity_sha256'], collector.digest(values[1]))
        self.assertEqual(result['certificate_sha256'], collector.digest(values[2]))
        self.assertEqual(result['requested_roots'], values[3])
        self.assertFalse(result['serialization_performed'])
        self.assertFalse(result['runtime_eligible'])

    def test_expected_policy_boundary_is_structured_only_after_fresh_proof(self):
        scenarios = [authored(classes=()), authored(target_types=(0,)),
                     authored(classes=('UNKNOWN_FUTURE_ROLE',)),
                     authored(classes=('SELECTED_CODE_ENTRY', 'SELECTED_CODE_ENTRY'))]
        for values in scenarios:
            with self.subTest(classes=[r['classification'] for r in values[1]['fields']]):
                self.assertTrue(values[2]['closure_observed'])
                with patch.object(coff, 'serialize', side_effect=AssertionError('assessment serialized')):
                    result = assess(values)
                self.assertFalse(result['eligible'])
                self.assertTrue(result['blockers'])
                self.assertFalse(result['serialization_performed'])
                self.assertFalse(result['runtime_eligible'])
                with self.assertRaises(projection.UnsupportedRoot): project(values)

    def test_structured_assessment_does_not_quarantine_integrity_failures(self):
        for change in ('raw', 'contract', 'certificate', 'operand', 'provider-role'):
            values = list(authored(classes=('ORIGINAL_IMAGE_DATA_REQUIRES_CANONICAL_OWNER',), kinds=(6,)))
            if change == 'raw': values[0] += b'changed'
            elif change == 'contract': values[1]['provenance']['object_sha256'] = 'f' * 64
            elif change == 'certificate': values[2]['runtime_eligible'] = True
            elif change == 'operand':
                values[1]['fields'][0]['original_operand'] = 123
                values = replay(values)
            else:
                values[4]['0x00600000'] = dict(recipe_id='contradictory-code-owner',
                                             object_sha256='e' * 64, symbol_index=88)
            with self.subTest(change=change):
                try:
                    assess(values)
                except ValueError as error:
                    self.assertNotIsInstance(error, projection.UnsupportedRoot)
                else:
                    self.fail('integrity error was converted to a normal blocked assessment')

    def test_unsupported_first_field_cannot_hide_later_corrupt_operand(self):
        values = authored(classes=('UNKNOWN_FUTURE_ROLE', 'EXPLICIT_NORMAL_CRT_CONTRACT_CANDIDATE'))
        self.assertTrue(values[2]['closure_observed'])
        self.assertFalse(assess(values)['eligible'])
        values[1]['fields'][1]['original_operand'] = 123
        values = replay(values)
        self.assertTrue(values[2]['closure_observed'])  # Ordinary graph does not validate original operands.
        try:
            assess(values)
        except ValueError as error:
            self.assertNotIsInstance(error, projection.UnsupportedRoot)
        else:
            self.fail('an unsupported earlier field concealed later corrupted original evidence')

    def test_cached_assessment_is_never_projection_authority(self):
        values = authored()
        cached = assess(values)
        cached['eligible'] = True
        cached['plan']['symbols'] = []
        output, _ = project(values)
        self.assertEqual(len(coff.exports(output)), 1)
        with self.assertRaises(TypeError): project(values, assessment=cached)
        values[1]['fields'][0]['original_operand'] = 123
        with self.assertRaises(ValueError): project(replay(values))


if __name__ == '__main__':
    unittest.main()
