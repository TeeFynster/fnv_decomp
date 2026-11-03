"""Synthetic cell/owner/permission cases; no original image or native inputs."""
import copy
import hashlib
import json
from pathlib import Path
import sys
import tempfile
from types import SimpleNamespace
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[2] / 'tools' / 'rebuild'))
import crt_table_classify as classify


def image():
    return SimpleNamespace(base=0x400000, image_size=0x10000,
        section=lambda rva, size: None if rva < 0x1000 else dict(executable=rva < 0x8000))


def cells(value, highlow=True, owners=None, native=None, standard=None, is_end=False):
    return classify.classify(value, 0x409000, highlow, image(),
        SimpleNamespace(at=lambda target: owners or []), native or {}, standard or {}, is_end)


class CellClassificationTests(unittest.TestCase):
    def test_owner_intervals_preserve_overlaps_and_no_nearest_guess(self):
        manifest = dict(units=[dict(recipe_id='a', object_sha256='a', source_sha256='a'),
                               dict(recipe_id='b', object_sha256='b', source_sha256='b')])
        selections = {'0x00401000': dict(recipe_index=0, recipe_id='a', size=40,
            symbol='a', section=1, value=0), '0x00401010': dict(recipe_index=1,
            recipe_id='b', size=4, symbol='b', section=1, value=0)}
        owners = classify.Owners(selections, manifest)
        self.assertEqual(len(owners.at(0x401011)), 2)
        self.assertEqual(len(owners.at(0x401018)), 1)
        self.assertEqual(owners.at(0x401028), [])
        self.assertEqual(owners.at(0x400fff), [])

    def test_null_and_arbitrary_nonaddress_preserved_without_raw_word(self):
        null = cells(0, highlow=False)
        self.assertTrue(null['is_null'])
        self.assertEqual(null['issues'], [])
        self.assertIn('null cell has a HIGHLOW relocation', cells(0)['issues'])
        unknown = cells(0xdeadbeef)
        self.assertEqual(unknown['domain'], 'uninterpreted-nonzero')
        self.assertIsNone(unknown['original_target_va'])
        self.assertIn('word_sha256', unknown)
        self.assertNotIn('value', unknown)

    def test_all_source_and_native_candidates_remain_separate(self):
        owner = dict(offset=0, symbol='source')
        native = {0x401000: [dict(identity='native-a'), dict(identity='native-b')]}
        standard = {0x401000: [dict(identity='CRT-candidate')]}
        row = cells(0x401000, owners=[owner], native=native, standard=standard)
        self.assertEqual(len(row['native_CRT_slot_candidates']), 2)
        self.assertEqual(len(row['selected_code_owners']), 1)
        self.assertEqual(len(row['standard_CRT_candidates']), 1)
        self.assertFalse(row['callback_ABI_verified'])
        self.assertFalse(row['runtime_provider_approved'])

    def test_interiors_nonexec_unknowns_and_end_conflicts_retained(self):
        row = cells(0x401002, owners=[dict(offset=2)], highlow=False, is_end=True)
        self.assertIn('source-code interior requires separate callback contract', row['issues'])
        self.assertIn('nonzero cell lacks HIGHLOW provenance', row['issues'])
        self.assertIn('non-null named end-cell candidate', row['issues'])
        self.assertEqual(cells(0x409000)['domain'], 'non-executable-target')
        self.assertEqual(cells(0x400100)['domain'], 'image-header-or-gap')
        self.assertIn('no selected source owner or observed standard-CRT candidate', cells(0x401000)['issues'])

    def test_exact_budget_and_source_stage_order_not_address_order(self):
        self.assertEqual(sum(end - begin + 4 for _, begin, end in classify.EXACT_REQUESTS), classify.EXACT_BYTES)
        self.assertEqual([stage for stage, _, _ in classify.EXACT_REQUESTS], ['xi', 'xc', 'xp', 'xt'])
        self.assertGreater(classify.EXACT_REQUESTS[0][1], classify.EXACT_REQUESTS[1][1])

    def test_review_requires_exact_ranges_no_code_and_conditional_only(self):
        review = dict(kind='fnv-crt-table-classifier-source-review', status='approved',
            reviewer='independent-test', sources={'fixture': 'hash'}, inputs=classify.PINS,
            ranges=[list(row) for row in classify.EXACT_REQUESTS], aggregate_bytes=classify.EXACT_BYTES,
            allow_nonexec_cell_read=True, allow_code_read=False, allow_execute=False,
            conditional_classification_only=True)
        with tempfile.TemporaryDirectory() as folder:
            path = Path(folder) / 'review.json'
            def check(value):
                path.write_text(json.dumps(value))
                classify.review_gate(path, hashlib.sha256(path.read_bytes()).hexdigest(), {'fixture': 'hash'})
            check(review)
            for key, bad in [('ranges', []), ('aggregate_bytes', classify.EXACT_BYTES + 4),
                    ('allow_code_read', True), ('allow_execute', True), ('conditional_classification_only', False)]:
                changed = copy.deepcopy(review)
                changed[key] = bad
                with self.assertRaises(ValueError): check(changed)


if __name__ == '__main__': unittest.main()
