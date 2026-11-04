"""Exact immutable-proof hydration and temporary IAT census views; no native IO."""
import copy
from pathlib import Path
import sys
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[2]/'tools/rebuild'))
import iat_field_annotations as a


def fixture():
    base, root = '0x00402000', '0x00401000'
    identity = dict(kind='name', name='RealExport')
    plan = dict(kind='fnv-static-import-plan', schema_version=1, summary=dict(imports=1),
        runtime_closure_verified=False, game_fixups_approved=0, imports=[dict(import_id=13,
            original_IAT_va=base, dll='fixture.dll', export=identity,
            representation=a.CLASSIFICATION, required_provider_contract=dict(dll='fixture.dll',
                export=identity, runtime_provider_selected=False))])
    full = dict(event='SELECTED_FUNCTION_COFF_RELOCATION', classification=a.CLASSIFICATION, import_id=13,
        coff_relocation=dict(kind=6, addend=0, width=4, offset=4, symbol_index=115, symbol='misleading_name'),
        physical_section=24, physical_offset=4, function_va=root, recipe_id='fixture',
        original_field_va='0x00401004', source_field_offset=4, physical_field_overlap_count=1,
        proof_consistency='EXACT_OWN_SOURCE_RESOLUTION', source_resolution_basis='OWN_RECIPE_BINDING',
        derived_source_symbol_base_va=base, exact_original_target_va=base, expected_original_target_va=base,
        original_operand=int(base, 16), representation=dict(addend=0, representation='ABSOLUTE_VA_DIR32', target=int(base, 16)),
        abi_verified=False, provider_selected=False, runtime_eligible=False, game_fixup_approved=False)
    h = a.digest(full); canonical = a.imports.unresolved(base, 'iat-cell')
    row = dict(component='CODE59', member='fixture.obj', root=root, recipe_id='fixture', section=2, offset=4,
        symbol_index=10, physical_symbol_index=115, kind=6, canonical=canonical, undefined=True,
        proof=dict(role='iat-cell', section=24, physical_section=24, offset=4, field_offset=4,
            symbol_index=115, kind=6, addend_bits=0, canonical_name=canonical, original_base=base,
            original_target=base, field_proof_sha256=h))
    other = dict(component='baseline', proof=dict(role='code'), arbitrary_metadata=dict(value=7))
    return [row, other], {h: full}, plan, [a.location(row)]


class AnnotationTests(unittest.TestCase):
    def test_original_proof_compact_witness_and_other_rows_are_immutable(self):
        args = fixture(); saved = copy.deepcopy(args)
        annotated = a.annotate(*args)
        self.assertEqual(args, saved)
        self.assertEqual(annotated[0]['proof'], args[0][0]['proof'])
        self.assertEqual(a.digest(annotated[0]['original_field_proof']), annotated[0]['proof']['field_proof_sha256'])
        self.assertEqual(annotated[1], args[0][1])
        self.assertEqual(annotated[0]['import_id'], 13)
        self.assertEqual(annotated[0]['IAT_annotation']['export']['name'], 'RealExport')
        self.assertNotIn('misleading_name', str(annotated[0]['IAT_annotation']))

    def test_census_copy_adds_tags_without_mutating_normative_ledger(self):
        args = fixture(); annotated = a.annotate(*args); saved = copy.deepcopy(annotated)
        view = a.census_view(annotated, args[2])
        self.assertEqual(annotated, saved)
        self.assertNotIn('classification', annotated[0]['proof'])
        self.assertEqual(view[0]['proof']['classification'], a.CLASSIFICATION)
        self.assertEqual(view[0]['proof']['import_id'], 13)
        self.assertEqual(view[0]['original_field_proof'], annotated[0]['original_field_proof'])
        self.assertEqual(view[1], annotated[1])

    def test_missing_extra_duplicate_fields_or_proofs_rejected(self):
        for change in ('missing', 'extra', 'duplicate', 'proofmissing', 'proofextra'):
            rows, proofs, plan, expected = fixture()
            if change == 'missing': rows.pop(0)
            if change in ('extra', 'duplicate'):
                extra = copy.deepcopy(rows[0])
                if change == 'extra': extra['member'] = 'other.obj'
                rows.append(extra)
            if change == 'proofmissing': proofs.clear()
            if change == 'proofextra': proofs['e'*64] = {}
            with self.subTest(change=change), self.assertRaises(ValueError):
                a.annotate(rows, proofs, plan, expected)

    def test_changed_full_payload_hash_rejected(self):
        args = fixture(); next(iter(args[1].values()))['extra'] = 'changed'
        with self.assertRaisesRegex(ValueError, 'proof hash'): a.annotate(*args)

    def test_conflicting_physical_coordinates_rejected(self):
        for key, value in [('physical_symbol_index', 116), ('offset', 8), ('kind', 20)]:
            args = fixture(); args[0][0][key] = value
            with self.subTest(key=key), self.assertRaises(ValueError): a.annotate(*args)

    def test_original_import_conflict_and_wrong_catalog_id_rejected(self):
        args = fixture(); args[2]['imports'][0]['import_id'] = 14
        with self.assertRaisesRegex(ValueError, 'catalog import identity'): a.annotate(*args)
        args = fixture(); args[0][0]['undefined'] = False
        with self.assertRaisesRegex(ValueError, 'role/base'): a.annotate(*args)

    def test_annotation_dll_export_id_or_promotion_tampering_rejected(self):
        for key, value in [('dll', 'wrong.dll'), ('export', dict(kind='name', name='Wrong')),
                           ('import_id', 99), ('ABI_verified', True), ('provider_selected', True)]:
            args = fixture(); rows = a.annotate(*args); rows[0]['IAT_annotation'][key] = value
            with self.subTest(key=key), self.assertRaises(ValueError): a.census_view(rows, args[2])

    def test_original_proof_or_annotation_cannot_be_dropped_or_rewritten(self):
        args = fixture(); rows = a.annotate(*args); rows[0]['original_field_proof']['import_id'] = 99
        with self.assertRaisesRegex(ValueError, 'proof hash'): a.census_view(rows, args[2])
        rows = a.annotate(*args); del rows[0]['IAT_annotation']
        with self.assertRaisesRegex(ValueError, 'missing reviewed annotation'): a.census_view(rows, args[2])

    def test_conflicting_preexisting_annotation_rejected(self):
        args = fixture(); args[0][0]['classification'] = 'CODE'
        with self.assertRaisesRegex(ValueError, 'existing annotation conflicts'): a.annotate(*args)

    def test_even_rehashed_unverified_nonpointer_or_promoted_proof_rejected(self):
        for change in ('addend', 'width', 'class', 'consistency', 'source', 'conflict', 'promotion'):
            rows, proofs, plan, expected = fixture(); full = next(iter(proofs.values()))
            if change == 'addend': full['coff_relocation']['addend'] = 4
            if change == 'width': full['coff_relocation']['width'] = 8
            if change == 'class': full['classification'] = 'SELECTED_CODE_ENTRY'
            if change == 'consistency': full['proof_consistency'] = 'UNKNOWN'
            if change == 'source': full['source_resolution_basis'] = 'GLOBAL_NAME_GUESS'
            if change == 'conflict': full['import_pointer_source_conflict'] = True
            if change == 'promotion': full['provider_selected'] = True
            h = a.digest(full); rows[0]['proof']['field_proof_sha256'] = h
            with self.subTest(change=change), self.assertRaises(ValueError):
                a.annotate(rows, {h: full}, plan, [a.location(rows[0])])


if __name__ == '__main__': unittest.main()
