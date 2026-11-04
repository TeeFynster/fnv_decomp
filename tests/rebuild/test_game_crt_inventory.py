"""Synthetic native metadata; no archive, image or compiler inputs."""
import sys
from pathlib import Path
from types import SimpleNamespace
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[2] / 'tools' / 'rebuild'))
from game_crt_inventory import observe_object


def fixture():
    data = bytearray(72)
    data[40:44] = (64).to_bytes(4, 'little')
    section = dict(index=1, name='.CRT$XCU', size=8, flags=0x40000040,
                   comdat=False, selection=None, association=None,
                   payload_sha256='fixture', relocs=[(0, 2, 6)])
    symbol = dict(name='init', type=32, section=2, value=0, storage=3)
    coff = SimpleNamespace(data=data, sections={1: section}, symbols={2: symbol},
                           take=lambda at, count: bytes(data[at:at + count]))
    unit = dict(recipe_index=0, recipe_id='fixture', object_sha256='fixture',
                source_sha256='fixture', recipe=dict(symbols={}, functions=[
                    dict(symbol='init', address='0x00401000')]))
    selected = {'0x00401000': dict(recipe_id='fixture', section=2, value=0, symbol='init')}
    return coff, unit, selected


class InventoryTests(unittest.TestCase):
    def test_physical_owner_and_unrelocated_null_kept(self):
        row = observe_object(*fixture())
        section = row['sections'][0]
        self.assertTrue(section['relocations'][0]['selected_same_physical_location'])
        self.assertEqual(section['unrelocated_slots'], [dict(offset=4, native_zero=True,
                                                           native_raw_backed=True)])
        self.assertFalse(row['runtime_provider_approved'])

    def test_unbound_variant_and_symbol_alias_not_promoted(self):
        coff, unit, selected = fixture()
        unit['recipe']['functions'] = []
        row = observe_object(coff, unit, selected)['sections'][0]['relocations'][0]
        self.assertIsNone(row['original_target_candidate'])
        self.assertFalse(row['selected_same_physical_location'])
        coff, unit, selected = fixture()
        selected['0x00401000']['symbol'] = 'alias'
        row = observe_object(coff, unit, selected)['sections'][0]['relocations'][0]
        self.assertTrue(row['selected_same_physical_location'])
        self.assertFalse(row['selected_same_symbol'])
        self.assertFalse(row['registration_approved'])

    def test_malformed_and_duplicate_relocations_are_retained(self):
        coff, unit, selected = fixture()
        coff.sections[1]['relocs'] = [(0, 2, 20), (0, 2, 6), (1, 2, 6), (7, 2, 6)]
        rows = observe_object(coff, unit, selected)['sections'][0]['relocations']
        self.assertEqual(len(rows), 4)
        self.assertTrue(all(row['errors'] for row in rows))
        self.assertIn('not a DIR32 pointer relocation', rows[0]['errors'])
        self.assertIn('duplicate relocation at slot', rows[1]['errors'])
        self.assertIn('not one aligned complete pointer slot', rows[3]['errors'])

    def test_nonzero_addend_remains_uncertain(self):
        coff, unit, selected = fixture()
        coff.data[64] = 1
        row = observe_object(coff, unit, selected)['sections'][0]['relocations'][0]
        self.assertEqual(row['original_target_candidate'], 0x401001)
        self.assertIn('nonzero/interior addend needs separate proof', row['errors'])

    def test_only_explicit_crt_sections_collected(self):
        coff, unit, selected = fixture()
        coff.sections[1]['name'] = '.text'
        self.assertEqual(observe_object(coff, unit, selected)['sections'], [])
        coff.sections[1]['name'] = '.CRT'
        self.assertEqual(len(observe_object(coff, unit, selected)['sections']), 1)


if __name__ == '__main__':
    unittest.main()
