import sys
import unittest
import tempfile
import json
from pathlib import Path
sys.path.insert(0, str(Path(__file__).resolve().parents[2] / 'tools/rebuild'))
from function_selection import choose, run, load_overrides


def candidate(recipe, symbol='f'):
    return dict(recipe_id=recipe, symbol=symbol, recipe_index=1, section=2, value=0,
                reference_selection_basis='SELECTED_RECIPE_FUNCTION',
                verified_function_span={'size': 4}, hash_bound_function_byte_verified=True)


def fixture(two=False):
    first = candidate('a')
    second = candidate('b')
    rows = [first, second] if two else [first]
    group = {'address': '0x00000001', 'candidates': rows}
    expected = {'0x00000001': {(c['recipe_id'], c['symbol']):
                {'hash_bound_function_byte_verified': True} for c in rows}}
    return group, expected

class SelectionTests(unittest.TestCase):
    def test_single_candidate_is_ownership_only(self):
        group, expected = fixture()
        row = choose([group], expected, {})['0x00000001']
        self.assertFalse(row['runtime_eligible']); self.assertFalse(row['link_ready'])

    def test_ambiguity_requires_exact_override(self):
        group, expected = fixture(True)
        with self.assertRaises(ValueError): choose([group], expected, {})
        with self.assertRaises(ValueError): choose([group], expected, {'0x00000001': {'recipe_id': 'z'}})
        self.assertEqual(choose([group], expected, {'0x00000001': {'recipe_id': 'b'}})['0x00000001']['recipe_id'], 'b')

    def test_metadata_only_substitution_rejected(self):
        group, expected = fixture()
        group['candidates'][0]['reference_selection_basis'] = 'METADATA_BOUND_UNVERIFIED_BODY'
        with self.assertRaises(ValueError): choose([group], expected, {})

    def test_duplicate_and_missing_groups_rejected(self):
        group, expected = fixture()
        with self.assertRaises(ValueError): choose([group, group], expected, {})
        with self.assertRaises(ValueError): choose([], expected, {})

    def test_conflicting_candidate_and_forged_proof_rejected(self):
        group, expected = fixture()
        group['candidates'][0]['hash_bound_function_byte_verified'] = False
        with self.assertRaises(ValueError): choose([group], expected, {})
        group, expected = fixture()
        group['candidates'].append(candidate('z'))
        with self.assertRaises(ValueError): choose([group], expected, {})

    def test_pinned_plan_rejects_stale_bytes_before_parsing(self):
        with tempfile.TemporaryDirectory() as d:
            root = Path(d)
            plan = root / 'plan'; plan.write_text('{}')
            candidates = root / 'candidates'; candidates.write_text('unchanged')
            missing = root / 'missing'; missing.write_text('fixture')
            with self.assertRaisesRegex(ValueError, 'fingerprint'):
                run(missing, missing, missing, missing, 'a' * 64, plan, '0' * 64,
                    candidates, '0' * 64, missing, root / 'out')
            self.assertFalse((root / 'out').exists())

    def test_duplicate_override_address_rejected(self):
        with tempfile.TemporaryDirectory() as d:
            path = Path(d) / 'overrides.json'
            path.write_text(json.dumps({'schema_version': 1, 'kind': 'fnv-function-provider-overrides',
                'overrides': [{'address': '0x1', 'recipe_id': 'a', 'reason': 'reviewed'},
                              {'address': '0x00000001', 'recipe_id': 'b', 'reason': 'reviewed'}]}))
            with self.assertRaises(ValueError): load_overrides(path)

    def test_extra_override_rejected(self):
        group, expected = fixture()
        with self.assertRaises(ValueError): choose([group], expected, {'0x00000001': {'recipe_id':'a'}})
        with self.assertRaises(ValueError): choose([group], expected, {'0x00000002': {'recipe_id':'a'}})

if __name__ == '__main__': unittest.main()
