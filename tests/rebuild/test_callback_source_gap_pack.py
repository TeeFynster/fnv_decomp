"""Synthetic saved-section hypotheses; no code/object/image input."""
from pathlib import Path
import sys
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[2] / 'tools' / 'rebuild'))
import callback_source_gap_pack as pack


class SourceGapTests(unittest.TestCase):
    def test_complete_native_section_tail_is_only_unapproved_geometry(self):
        rows, consistent = pack.affine_leads(dict(index=1, extent=20), [(100, dict(value=0))], [110, 120])
        self.assertTrue(consistent)
        self.assertEqual(len(rows), 1)
        self.assertEqual(rows[0]['native_offset'], 10)
        self.assertFalse(rows[0]['source_ownership_approved'])
        self.assertFalse(rows[0]['function_symbol_at_offset_verified'])

    def test_no_nearest_anchor_or_end_inclusion(self):
        rows, consistent = pack.affine_leads(dict(index=1, extent=20), [(100, dict(value=0))], [99, 120, 121])
        self.assertTrue(consistent)
        self.assertEqual(rows, [])

    def test_disagreeing_anchor_bases_are_not_resolved(self):
        rows, consistent = pack.affine_leads(dict(index=1, extent=30),
            [(100, dict(value=0)), (110, dict(value=0))], [115])
        self.assertFalse(consistent)
        self.assertEqual(rows, [])

    def test_multiple_agreeing_anchors_preserve_model_limit(self):
        rows, consistent = pack.affine_leads(dict(index=1, extent=30),
            [(100, dict(value=0)), (110, dict(value=10))], [115])
        self.assertTrue(consistent)
        self.assertEqual(rows[0]['selected_anchor_count'], 2)
        self.assertFalse(rows[0]['affine_section_mapping_approved'])

    def test_negative_or_wrapping_geometry_rejected(self):
        with self.assertRaises(ValueError): pack.affine_leads(dict(index=1, extent=20), [(1, dict(value=2))], [])
        with self.assertRaises(ValueError): pack.affine_leads(dict(index=1, extent=20), [(0xfffffff0, dict(value=0))], [])


if __name__ == '__main__': unittest.main()
