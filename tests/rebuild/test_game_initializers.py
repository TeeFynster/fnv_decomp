"""Original metadata fixtures; no compiler, game input or execution."""
import sys
from pathlib import Path
from types import SimpleNamespace
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[2] / 'tools' / 'rebuild'))
from game_initializers import join_fields, object_slots


def fixture(bound=True, selected_recipe='fixture'):
    data = bytearray(68)
    data[40:44] = (64).to_bytes(4, 'little')
    coff = SimpleNamespace(data=data, sections={1: dict(index=1, name='.CRT$XCU',
        size=4, relocs=[(0, 2, 6)])}, symbols={2: dict(name='init', type=32,
        section=2, value=0, storage=3)})
    unit = dict(recipe_index=1, recipe_id='fixture', object_sha256='fixture-hash',
        recipe=dict(symbols={}, functions=[dict(symbol='init', address='0x00401000')] if bound else []))
    selected = {'0x00401000': dict(recipe_id=selected_recipe, symbol='init', section=2, value=0)}
    return coff, unit, selected


class InitializerMetadataTests(unittest.TestCase):
    def test_native_slot_is_function_and_selected_physical_owner(self):
        rows, sections = object_slots(*fixture())
        self.assertTrue(rows[0]['selected_same_physical_owner'])
        self.assertEqual(rows[0]['original_target'], 0x401000)
        self.assertEqual(sections[0]['unrelocated_slots'], 0)

    def test_other_selected_variant_is_not_physical_owner(self):
        rows, _ = object_slots(*fixture(selected_recipe='other'))
        self.assertFalse(rows[0]['selected_same_physical_owner'])

    def test_unbound_slot_is_preserved(self):
        rows, _ = object_slots(*fixture(bound=False))
        self.assertIsNone(rows[0]['original_target'])
        self.assertFalse(rows[0]['selected_same_physical_owner'])

    def test_termination_references_do_not_prove_callback_argument(self):
        coff, unit, selections = fixture()
        selections['0x00401000']['size'] = 20
        coff.sections[2] = dict(name='.text', relocs=[(4, 3, 6), (9, 4, 20)])
        coff.symbols[3] = dict(name='cleanup', type=32)
        coff.symbols[4] = dict(name='_atexit', type=32)
        unit['recipe']['symbols'] = {'cleanup': '0x00402000', '_atexit': '0x00403000'}
        rows, _ = object_slots(coff, unit, selections)
        self.assertEqual(rows[0]['native_atexit_reference_fields'][0]['offset'], 9)
        candidate = rows[0]['native_function_pointer_field_candidates'][0]
        self.assertEqual(candidate['original_target'], '0x00402000')
        self.assertFalse(candidate['callback_argument_relation_verified'])
        selections['0x00401000']['recipe_id'] = 'different'
        rows, _ = object_slots(coff, unit, selections)
        self.assertEqual(rows[0]['native_atexit_reference_fields'], [])

    def test_nonfunction_or_undefined_target_rejected(self):
        for key, value in [('type', 0), ('section', 0)]:
            args = fixture()
            args[0].symbols[2][key] = value
            with self.assertRaises(ValueError):
                object_slots(*args)

    def test_interior_target_rejected(self):
        args = fixture()
        args[0].data[64] = 1
        with self.assertRaises(ValueError):
            object_slots(*args)

    def test_bad_relocation_rejected(self):
        for relocs in [[(0, 2, 20)], [(1, 2, 6)], [(0, 2, 6), (0, 2, 6)]]:
            args = fixture()
            args[0].sections[1]['relocs'] = relocs
            with self.assertRaises(ValueError):
                object_slots(*args)

    def test_every_site_and_input_order_preserved_without_bounds(self):
        rows = [dict(original_target=0x401000), dict(original_target=0x401000),
                dict(original_target=None)]
        fields = [[0x3008, 0x1000, 'ordinary-entry', 0, 4, 'raw', ['unproved']],
                  [0x3000, 0x1000, 'ordinary-entry', 0, 4, 'raw', []]]
        join_fields(rows, fields, 0x400000)
        self.assertEqual([s['original_site'] for s in rows[0]['original_candidate_sites']],
                         [0x403008, 0x403000])
        self.assertEqual(rows[0]['original_candidate_sites'], rows[1]['original_candidate_sites'])
        self.assertEqual(rows[2]['original_candidate_sites'], [])
        self.assertNotIn('table_start', rows[0])

    def test_duplicate_or_nonraw_field_rejected(self):
        row = dict(original_target=0x401000)
        field = [0x3000, 0x1000, 'ordinary-entry', 0, 4, 'raw', []]
        with self.assertRaises(ValueError):
            join_fields([row], [field, field], 0x400000)
        field[5] = 'virtual-zero'
        with self.assertRaises(ValueError):
            join_fields([row], [field], 0x400000)


if __name__ == '__main__':
    unittest.main()
