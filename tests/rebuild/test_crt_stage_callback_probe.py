"""Synthetic finite-buffer/native-field cases; no image/library/native inputs."""
import copy
import hashlib
import json
from pathlib import Path
import struct
import sys
import tempfile
from types import SimpleNamespace
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[2] / 'tools' / 'rebuild'))
import crt_stage_callback_probe as probe


def fixture():
    pattern = b'abcd' + bytes(4) + b'wxyz'
    relocation = dict(offset=4, kind=6, addend=0, symbol='global')
    candidate = dict(candidate_id='id', family='fixture', symbol='initializer',
        definition=dict(value=0, section_size=12, relocations=[relocation]))
    actual = bytearray(pattern)
    struct.pack_into('<I', actual, 4, 0x405000)
    pe = SimpleNamespace(base=0x400000, section=lambda *args:
        dict(name='.data', rva=0x5000, raw_size=0x1000, executable=False))
    return bytes(actual), candidate, pattern, pe


class StageCallbackProbeTests(unittest.TestCase):
    def test_complete_buffer_match_preserves_unverified_targets(self):
        actual, candidate, pattern, pe = fixture()
        result = probe.compare_buffer(actual, 0x401000, 0x401000, candidate, pattern, pe, {0x1004})
        self.assertTrue(result['full_nonrelocation_span_equal'])
        self.assertTrue(result['all_field_geometry_checks_pass'])
        self.assertFalse(result['original_identity_approved'])
        self.assertFalse(result['relocation_observations'][0]['independent_symbol_identity_verified'])

    def test_failed_pattern_and_relocation_provenance_both_retained(self):
        actual, candidate, pattern, pe = fixture()
        actual = b'!' + actual[1:]
        result = probe.compare_buffer(actual, 0x401000, 0x401000, candidate, pattern, pe, set())
        self.assertFalse(result['full_nonrelocation_span_equal'])
        self.assertEqual(result['first_nonrelocation_difference_offset'], 0)
        self.assertFalse(result['all_field_geometry_checks_pass'])
        self.assertEqual(len(result['relocation_observations']), 1)

    def test_whole_section_interior_symbol_and_exact_window_bounds(self):
        actual, candidate, pattern, pe = fixture()
        candidate['definition']['value'] = 3
        result = probe.compare_buffer(actual, 0x401000, 0x401003, candidate, pattern, pe, {0x1004})
        self.assertEqual(result['section_start_candidate'], 0x401000)
        with self.assertRaises(ValueError):
            probe.compare_buffer(actual[:-1], 0x401000, 0x401003, candidate, pattern, pe, set())

    def test_multiple_candidate_patterns_remain_distinct(self):
        actual, candidate, pattern, pe = fixture()
        second = copy.deepcopy(candidate)
        second.update(candidate_id='second', symbol='other-name', family='other-family')
        results = [probe.compare_buffer(actual, 0x401000, 0x401000, c, pattern, pe, {0x1004})
                   for c in [candidate, second]]
        self.assertEqual([r['candidate_id'] for r in results], ['id', 'second'])
        self.assertTrue(all(r['full_nonrelocation_span_equal'] for r in results))

    def test_review_pins_grid_and_disallows_XC_recursion_execution(self):
        plan = dict(reads=[dict(target='fixture')], candidates={'xi': [dict(candidate_id='id')], 'xp': []})
        review = dict(kind='fnv-crt-stage-callback-probe-review', status='approved', reviewer='test',
            sources={'fixture': 'hash'}, inputs=probe.PINS, reads=plan['reads'], candidate_ids=['id'],
            aggregate_original_bytes=probe.EXACT_BYTES, allow_original_code_read=True,
            allow_recursive_probes=False, allow_execute=False, XC_targets_in_probe_scope=0, candidate_only=True)
        with tempfile.TemporaryDirectory() as folder:
            path = Path(folder) / 'review.json'
            def check(value):
                path.write_text(json.dumps(value))
                probe.review_gate(path, hashlib.sha256(path.read_bytes()).hexdigest(), {'fixture': 'hash'}, plan)
            check(review)
            for key, wrong in [('reads', []), ('allow_recursive_probes', True), ('allow_execute', True),
                                ('XC_targets_in_probe_scope', 1), ('aggregate_original_bytes', 1755)]:
                changed = dict(review, **{key: wrong})
                with self.assertRaises(ValueError): check(changed)


if __name__ == '__main__': unittest.main()
