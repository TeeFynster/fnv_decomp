"""Exact rounding and immutable review/own-child gates; no native launch."""
import copy
from fractions import Fraction
import json
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[2]/'tools/rebuild'))
import game_scalar_component as scalar


class ScalarComponentTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)

    def test_exact_binary32_decode_and_neighbors(self):
        self.assertEqual(scalar.binary32_fraction(0x3f400000), Fraction(3, 4))
        self.assertEqual(scalar.binary32_fraction(0x3f3fffff), Fraction(3, 4)-Fraction(1, 1 << 24))
        self.assertEqual(scalar.binary32_fraction(0x3f400001), Fraction(3, 4)+Fraction(1, 1 << 24))
        self.assertEqual(scalar.binary32_fraction(0xbe800000), Fraction(-1, 4))
        with self.assertRaises(ValueError): scalar.binary32_fraction(0x7fc00000)

    def test_nearest_even_ties_on_both_sides(self):
        self.assertEqual(scalar.round_binary32(Fraction(1)+Fraction(1, 1 << 24)), 0x3f800000)
        self.assertEqual(scalar.round_binary32(Fraction(1)+Fraction(3, 1 << 24)), 0x3f800002)
        self.assertEqual(scalar.round_binary32(-Fraction(1)-Fraction(3, 1 << 24)), 0xbf800002)
        self.assertEqual(scalar.round_binary32(Fraction(1, 1 << 150)), 0)
        self.assertEqual(scalar.round_binary32(Fraction(3, 1 << 150)), 2)

    def test_exact_round_trips_and_finite_overflow_rejection(self):
        for bits in (1, 2, 0x7fffff, 0x800000, 0x3eaaaaab, 0x3f800000, 0xbf800000, 0x7f7fffff):
            self.assertEqual(scalar.round_binary32(scalar.binary32_fraction(bits)), bits)
        with self.assertRaises(ValueError): scalar.round_binary32(Fraction(1 << 129))

    def test_audited_golden_cases_and_negative_no_extra_clamp(self):
        rows = scalar.golden_cases()
        self.assertEqual([r['expected_bits'] for r in rows],
            [0x3efeb852, 0x3f2a3d70, 0x3f551eb8, 0x3f800000, 0x3f800000, 0x3f800000,
             0x3f7fffff, 0x3f800000, 0x3ea8f5c2])
        self.assertLess(scalar.binary32_fraction(rows[-1]['expected_bits']), scalar.binary32_fraction(rows[0]['expected_bits']))
        self.assertEqual(len({r['input_bits'] for r in rows}), 9)
        self.assertIn('0xbe800000u', scalar.golden_header(rows))

    def pair(self):
        variants, artifacts = [], {}
        for name in ('normal', 'moved'):
            exe, mp = self.root/(name+'.exe'), self.root/(name+'.map')
            exe.write_text('never execute')
            mp.write_text('original map')
            variants.append(dict(name=name, exe=str(exe), map=str(mp), exe_sha256=scalar.sha(exe), map_sha256=scalar.sha(mp)))
            artifacts.update({str(exe): scalar.sha(exe), str(mp): scalar.sha(mp)})
        p = dict(schema_version=1, kind='game-scalar-component-prepared', policy=scalar.extract.POLICY,
            execution_performed=False, status='prepared_pending_independent_review', expected_result=scalar.EXPECTED,
            golden_cases=scalar.golden_cases(), variants=variants, inputs={}, artifacts=artifacts, os_dependencies={})
        r = dict(schema_version=1, kind='game-scalar-component-review', approved=True, prepare_sha256='b'*64,
            reviewer='independent', variants=[{k: v[k] for k in ('name', 'exe_sha256', 'map_sha256')} for v in variants],
            checks={k: True for k in ('strict_coff', 'literal_ownership', 'linked_relocations', 'map_crt_imports',
                                    'golden_rounding', 'x87_policy', 'protected_artifacts')})
        return p, r

    def prepared_pair(self):
        p, r = self.pair()
        pp, rp = self.root/'prepare.json', self.root/'review.json'
        scalar.save(pp, p)
        r['prepare_sha256'] = scalar.sha(pp)
        scalar.save(rp, r)
        return p, pp, rp

    def test_independent_per_layout_review_required(self):
        p, r = self.pair()
        scalar.validate_review(p, r, 'b'*64)
        for key, value in [('approved', False), ('prepare_sha256', 'c'*64), ('checks', {}), ('variants', r['variants'][:1])]:
            bad = copy.deepcopy(r)
            bad[key] = value
            with self.assertRaises(ValueError): scalar.validate_review(p, bad, 'b'*64)

    def test_review_rejects_unbound_executable_and_changed_goldens(self):
        p, r = self.pair()
        del p['artifacts'][p['variants'][0]['exe']]
        with self.assertRaisesRegex(ValueError, 'binding'): scalar.validate_review(p, r, 'b'*64)
        p, r = self.pair()
        p['golden_cases'][0]['expected_bits'] += 1
        with self.assertRaises(ValueError): scalar.validate_review(p, r, 'b'*64)

    def test_supported_control_and_exact_receipt_required(self):
        scalar.parse_result(json.dumps(scalar.EXPECTED)+'\n', '', 0)
        for key, value in [('x87_before', 0), ('x87_after', scalar.CW_DEFAULT+0x100), ('calls', 1), ('sentinels_ok', 1)]:
            result = dict(scalar.EXPECTED)
            result[key] = value
            with self.assertRaises(ValueError): scalar.parse_result(json.dumps(result)+'\n', '', 0)
        with self.assertRaises(ValueError): scalar.parse_result(json.dumps(scalar.EXPECTED), 'diagnostic', 0)
        with self.assertRaises(ValueError): scalar.parse_result(json.dumps(scalar.EXPECTED), '', 20)

    def test_stale_review_or_existing_receipt_prevents_child(self):
        p, pp, rp = self.prepared_pair()
        receipt = self.root/'result.json'
        with patch.object(scalar.subprocess, 'run') as run:
            with self.assertRaises(ValueError): scalar.execute(pp, rp, 'a'*64, receipt)
            with self.assertRaises(ValueError): scalar.execute(pp, rp, scalar.sha(rp), pp)
            run.assert_not_called()

    def test_changed_input_prevents_child_and_records_error(self):
        p, pp, rp = self.prepared_pair()
        Path(p['variants'][0]['exe']).write_text('changed')
        with patch.object(scalar.subprocess, 'run') as run:
            result = scalar.execute(pp, rp, scalar.sha(rp), self.root/'result.json')
            run.assert_not_called()
        self.assertEqual(result['status'], 'error')

    def test_input_change_during_last_child_cannot_pass(self):
        p, pp, rp = self.prepared_pair()
        calls = []
        def child(*args, **kwargs):
            calls.append(args)
            if len(calls) == 2:
                Path(p['variants'][1]['map']).write_text('changed during child')
            return subprocess.CompletedProcess(args, 0, json.dumps(scalar.EXPECTED)+'\n', '')
        with patch.object(scalar.subprocess, 'run', side_effect=child):
            result = scalar.execute(pp, rp, scalar.sha(rp), self.root/'result.json')
        self.assertEqual(len(calls), 2)
        self.assertEqual(result['status'], 'error')
        self.assertIn('during child', result['error'])

    def test_own_child_timeout_is_terminal_error_receipt(self):
        p, pp, rp = self.prepared_pair()
        with patch.object(scalar.subprocess, 'run', side_effect=subprocess.TimeoutExpired('own child', 20)):
            result = scalar.execute(pp, rp, scalar.sha(rp), self.root/'result.json')
        self.assertEqual(result['status'], 'error')
        self.assertEqual(result['variants'], [dict(name='normal', status='timeout')])


if __name__ == '__main__':
    unittest.main()
