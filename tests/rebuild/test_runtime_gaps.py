import argparse
import gzip
import hashlib
import importlib.util
import json
from pathlib import Path
import tempfile
import unittest
from unittest import mock

ROOT = Path(__file__).resolve().parents[2]
spec = importlib.util.spec_from_file_location('runtime_gaps', ROOT / 'tools/rebuild/runtime_gaps.py')
gaps = importlib.util.module_from_spec(spec)
spec.loader.exec_module(gaps)


def sha(path): return hashlib.sha256(path.read_bytes()).hexdigest()


class RuntimeGapsTests(unittest.TestCase):
    def setUp(self):
        self.plan = {'kind': 'fnv-private-data-analysis', 'runtime_ready': False, 'status': 'analysis-only',
                     'detail_columns': gaps.COLUMNS, 'image': {'base': 0x400000, 'size': 0x10000},
                     'fixups': {'nonexec_data_sites': 4, 'by_target': {'other-code': 2, 'EH-interior-ambiguous': 1, 'data': 1}}}
        self.expect = {'sites': 4, 'other-code': 2, 'EH-interior-ambiguous': 1}
        self.rows = [[1, 0x100, 'other-code', None, 4, 'raw', []],
                     [5, 0x100, 'other-code', None, 4, 'raw', []],
                     [9, 0x200, 'EH-interior-ambiguous', None, 4, 'raw', []],
                     [13, 0x300, 'data', None, 4, 'raw', []]]
        self.recipes = {'units': [
            {'symbols': {'?one': '0x400100', '?near': '0x400101', '?same_name': '0x400200'},
             'functions': [{'address': '0x400100', 'symbol': '?one'}]},
            {'symbols': {'?one': '0x400999', '?another': '0x400100'}, 'functions': []}]}

    def test_exact_address_and_duplicate_sites_vs_unique_targets(self):
        report = gaps.summarize(self.plan, self.recipes, self.rows, self.expect)
        self.assertEqual(report['summary']['selected_occurrences'], 3)
        self.assertEqual(report['summary']['unique_target_vas'], 2)
        first, second = report['targets']
        self.assertEqual(first['target_va'], '0x00400100')
        self.assertEqual(first['occurrences'], 2)
        self.assertEqual({a['name'] for a in first['exact_recipe_aliases']}, {'?one', '?another'})
        self.assertEqual({a['name'] for a in second['exact_recipe_aliases']}, {'?same_name'})
        self.assertEqual(second['labels'], ['EH-ambiguous-from-input'])
        self.assertEqual(second['sampled_canonical_candidates'], [])

    def test_overlap_never_infers_nearest_provider(self):
        self.recipes['units'][0]['functions'].append({'address': '0x4001ff', 'symbol': '?near_eh'})
        target = gaps.summarize(self.plan, self.recipes, self.rows, self.expect)['targets'][1]
        self.assertNotIn('?near_eh', [r['name'] for r in target['exact_recipe_aliases']])

    def test_bad_counts_and_duplicate_site_rejected(self):
        for bad in (self.rows[:-1], self.rows + [self.rows[0]], self.rows[:1] + [self.rows[0]] + self.rows[2:]):
            with self.subTest(bad=bad), self.assertRaises(ValueError): gaps.summarize(self.plan, self.recipes, bad, self.expect)
        self.plan['fixups']['by_target']['other-code'] = 3
        with self.assertRaises(ValueError): gaps.summarize(self.plan, self.recipes, self.rows, self.expect)

    def test_candidates_are_sampled_unverified_and_exact_address(self):
        candidate = {'recipe_index': 0, 'symbol': '?x', 'kind': 'function_definition', 'selection_state': 'UNSELECTED', 'abi_verified': False}
        canonical = {'kind': 'fnv-canonical-address-plan', 'selection_state': 'UNSELECTED',
                     'candidate_group_examples': [{'address': '0x400100', 'candidates': [candidate]},
                                                  {'address': '0x400201', 'candidates': [candidate]}]}
        result = gaps.summarize(self.plan, self.recipes, self.rows, self.expect, canonical=canonical)
        self.assertEqual(result['targets'][0]['sampled_canonical_candidates'][0]['status'], 'UNVERIFIED_SAMPLED_EXAMPLE')
        self.assertEqual(result['targets'][1]['sampled_canonical_candidates'], [])

    def test_stale_input_hashes_and_overwrite_fail_closed(self):
        with tempfile.TemporaryDirectory() as tmp:
            d = Path(tmp); plan = d/'plan.json'; recipe = d/'recipe.json'; detail = d/'detail.gz'
            recipe.write_text(json.dumps(self.recipes), encoding='utf-8')
            with gzip.open(detail, 'wt', encoding='utf-8') as stream:
                for row in self.rows: stream.write(json.dumps(row)+'\n')
            self.plan.update(recipe_sha256=sha(recipe), detail_sha256=sha(detail))
            plan.write_text(json.dumps(self.plan), encoding='utf-8')
            args = argparse.Namespace(plan=plan, plan_sha256=sha(plan), recipes=recipe, detail=detail,
                                      canonical=None, canonical_sha256=None, retained=None, retained_sha256=None, out=d/'out')
            original_summarize = gaps.summarize
            with mock.patch.object(gaps, 'summarize', side_effect=lambda p, r, rows, **kw: original_summarize(p, r, rows, expected=self.expect, **kw)):
                report = gaps.run(args)
                self.assertEqual(report['summary']['unique_target_vas'], 2)
                with self.assertRaisesRegex(ValueError, 'already exists'): gaps.run(args)
            recipe.write_text('{}', encoding='utf-8')
            with self.assertRaisesRegex(ValueError, 'SHA-256'): gaps.run(args)
            recipe.write_text(json.dumps(self.recipes), encoding='utf-8')
            with detail.open('ab') as stream: stream.write(b'x')
            with self.assertRaisesRegex(ValueError, 'SHA-256'): gaps.run(args)
            plan.write_text('{}', encoding='utf-8')
            with self.assertRaisesRegex(ValueError, 'SHA-256'): gaps.run(args)


if __name__ == '__main__': unittest.main()
