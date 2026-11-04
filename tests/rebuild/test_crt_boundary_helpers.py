"""Original metadata fixtures; no library, image or native execution."""
import copy
import hashlib
import json
from pathlib import Path
import sys
import tempfile
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[2] / 'tools' / 'rebuild'))
import crt_boundary_helpers as helpers


class HelperProbeTests(unittest.TestCase):
    def test_short_fixed_span_allowed_only_for_address_probe(self):
        masked = helpers.field_mask(9, [dict(offset=3, kind=20)])
        self.assertEqual(masked, {3, 4, 5, 6})

    def test_invalid_field_masks_rejected(self):
        for rows in [[dict(offset=0, kind=7)], [dict(offset=7, kind=6)],
                     [dict(offset=0, kind=6), dict(offset=3, kind=20)]]:
            with self.assertRaises(ValueError):
                helpers.field_mask(10, rows)

    def test_named_interior_symbol_maps_to_entire_native_section(self):
        self.assertEqual(helpers.span_base(0x2045, 69, 89, 0x1000, 0x3000), 0x2000)
        for target, value, size in [(0x1000, 69, 89), (0x2fff, 0, 89),
                                    (0x2000, 0, 4097)]:
            with self.assertRaises(ValueError):
                helpers.span_base(target, value, size, 0x1000, 0x3000)

    def test_receipt_fields_preserved_without_selecting_target(self):
        report = dict(observations=[dict(identity='sp1:_doexit', candidates=[
            dict(address=0x1000, relocations=[
                dict(symbol='__lock', field_va=0x1010, kind=20,
                     original_symbol_base_candidate=0x2000, errors=[]),
                dict(symbol='__lock', field_va=0x1020, kind=20,
                     original_symbol_base_candidate=0x3000, errors=['unverified'])])]),
            dict(identity='vc8:_doexit', candidates=[])])
        targets = helpers.derived_targets(report)
        self.assertEqual([row['target'] for row in targets['__lock']], [0x2000, 0x3000])
        self.assertEqual(targets['__lock'][1]['parent_relocation_errors'], ['unverified'])
        self.assertEqual(targets['_atexit'], [])

    def test_review_pins_contracts_and_no_execution(self):
        review = dict(kind='fnv-crt-helper-probe-source-review', status='approved',
            reviewer='independent-test', sources={'fixture': 'hash'}, contracts_sha256='contract',
            candidate_receipt_sha256=helpers.CANDIDATES, functions=list(helpers.HELPERS),
            reference_sha256=helpers.base.REFERENCE, allow_reference_probe=True,
            allow_execute=False, candidate_only=True)
        with tempfile.TemporaryDirectory() as folder:
            path = Path(folder) / 'review.json'
            def check(value):
                path.write_text(json.dumps(value))
                helpers.review_gate(path, hashlib.sha256(path.read_bytes()).hexdigest(),
                                    {'fixture': 'hash'}, 'contract')
            check(review)
            for key, bad in [('contracts_sha256', 'wrong'), ('functions', ['other']),
                             ('allow_execute', True), ('sources', {}), ('candidate_only', False)]:
                changed = copy.deepcopy(review)
                changed[key] = bad
                with self.assertRaises(ValueError):
                    check(changed)


if __name__ == '__main__':
    unittest.main()
