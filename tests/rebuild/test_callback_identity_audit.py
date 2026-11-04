"""Synthetic interval/CRT-source-role cases; no image or native compiler inputs."""
import copy
from pathlib import Path
import sys
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[2] / 'tools' / 'rebuild'))
import callback_identity_audit as audit


def fixture():
    definition = dict(member_header_offset=100, symbol_index=4, section=2, value=0,
        section_size=13, errors=[], symbol='init')
    slot = dict(category='.CRT$XIC', kind=6, addend=0, target_symbol='init',
        native_definition_candidates=[definition], member_header_offset=200,
        member_name='origin.obj', member_sha256='hash', section=3, offset=0)
    xp = copy.deepcopy(slot)
    xp.update(category='.CRT$XPX', target_symbol='term')
    xp['native_definition_candidates'][0].update(member_header_offset=101, symbol='term', section_size=30)
    return dict(families={'fixture-family': dict(records=[slot, xp])})


class IdentityAuditTests(unittest.TestCase):
    def test_all_interval_overlaps_and_half_open_boundaries(self):
        spans = audit.Intervals([(10, 30, dict(identity='a')), (15, 20, dict(identity='b', match=False))])
        self.assertEqual(len(spans.at(16)), 2)
        self.assertEqual(spans.at(20)[0]['identity'], 'a')
        self.assertEqual(spans.at(30), [])
        self.assertEqual(spans.at(9), [])
        self.assertFalse(spans.at(16)[1]['callable_identity_approved'])

    def test_native_definition_dedup_retains_all_distinct_origin_slots(self):
        roster = fixture()
        extra = copy.deepcopy(roster['families']['fixture-family']['records'][0])
        extra['member_header_offset'] = 201
        roster['families']['fixture-family']['records'].append(extra)
        result = audit.probe_candidates(roster, 'xi')
        self.assertEqual(len(result), 1)
        self.assertEqual(len(result[0]['native_origin_slots']), 2)
        self.assertFalse(result[0]['original_identity_verified'])

    def test_XCU_and_unsupported_sources_do_not_expand_CRT_probe_scope(self):
        roster = fixture()
        roster['families']['fixture-family']['records'][0]['category'] = '.CRT$XCU'
        self.assertEqual(audit.probe_candidates(roster, 'xi'), [])
        roster = fixture()
        roster['families']['fixture-family']['records'][0]['native_definition_candidates'][0]['errors'] = ['unsupported']
        self.assertEqual(audit.probe_candidates(roster, 'xi'), [])

    def test_exact_ten_target_budget_excludes_all_XC_targets(self):
        callbacks = [dict(stage='xi', original_target_va=0x410000 + i * 0x100) for i in range(8)]
        callbacks += [dict(stage='xp', original_target_va=0x420000 + i * 0x100) for i in range(2)]
        callbacks += [dict(stage='xc', original_target_va=0x430000)]
        plan = audit.make_probe_plan(callbacks, fixture())
        self.assertEqual(plan['aggregate_original_bytes'], 8 * 13 + 2 * 30)
        self.assertEqual(len(plan['reads']), 10)
        self.assertEqual(plan['XC_targets_in_probe_scope'], 0)
        self.assertFalse(plan['allow_original_read'])

    def test_outside_text_and_missing_population_rejected(self):
        callbacks = [dict(stage='xi', original_target_va=0x400000)]
        with self.assertRaises(ValueError): audit.make_probe_plan(callbacks, fixture())
        with self.assertRaises(ValueError): audit.make_probe_plan([], fixture())


if __name__ == '__main__': unittest.main()
