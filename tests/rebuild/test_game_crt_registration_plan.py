"""Synthetic physical namespaces/slots; no game, object or native inputs."""
import copy
from pathlib import Path
import sys
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[2] / 'tools' / 'rebuild'))
import game_crt_registration_plan as plan


def fixture():
    owner = dict(offset=0, original_entry=0x401000, original_end=0x40100f,
        recipe_id='fixture', object_sha256='a' * 64, source_sha256='b' * 64,
        symbol='?fixture@@YAXXZ', native_section=3, native_value=0)
    provider = {k: owner[k] for k in ('recipe_id', 'object_sha256', 'source_sha256', 'symbol')}
    provider.update(symbol_index=7, section=3, value=0, size=15)
    provider['planned_canonical_name'] = plan.canonical({k: provider[k] for k in
        ('recipe_id', 'object_sha256', 'symbol_index')})
    cell = dict(stage='xc', index=3, original_site=0x40900c, original_target_va=0x401000,
        is_null=False, is_named_end_cell=False, issues=[], selected_code_owners=[owner],
        native_CRT_slot_candidates=[], standard_CRT_candidates=[])
    return owner, provider, cell


class RegistrationPlanTests(unittest.TestCase):
    def test_physical_name_proposal_does_not_become_export_or_ABI(self):
        owner, provider, cell = fixture()
        row = plan.plan_cell(cell, {'0x00401000': provider})
        proposal = row['namespace_proposal']
        self.assertEqual(proposal['planned_COFF_name'], provider['planned_canonical_name'])
        self.assertEqual(proposal['proposed_C_identifier'], provider['planned_canonical_name'][1:])
        self.assertFalse(proposal['materialized_export_verified'])
        self.assertFalse(proposal['callback_ABI_approved'])
        self.assertFalse(row['allow_source_emission'])
        self.assertTrue(row['requires_explicit_registration_beyond_native_XCU'])

    def test_wrong_physical_join_span_or_index_name_rejected(self):
        owner, provider, _ = fixture()
        for key, wrong in [('source_sha256', 'c' * 64), ('size', 16), ('symbol_index', 8),
                           ('section', 4), ('symbol', 'other')]:
            bad = dict(provider, **{key: wrong})
            with self.assertRaises(ValueError): plan.provider_proposal(owner, bad)
        with self.assertRaises(ValueError): plan.provider_proposal(dict(owner, offset=1), provider)

    def test_null_end_and_unknown_callback_are_not_aliases(self):
        _, _, cell = fixture()
        unknown = dict(cell, stage='xi', selected_code_owners=[])
        row = plan.plan_cell(unknown, {})
        self.assertEqual(row['action'], 'UNRESOLVED_CALLBACK_NO_ALIAS_OR_STUB')
        self.assertEqual(row['expected_callback_signature_from_local_stage'], 'int __cdecl(void)')
        self.assertIsNone(row['namespace_proposal'])
        self.assertEqual(plan.plan_cell(dict(cell, is_null=True), {})['action'],
                         'SKIP_NULL_IF_LOCAL_WALKER_PATH_IS_REACHED')
        self.assertEqual(plan.plan_cell(dict(cell, is_named_end_cell=True), {})['action'],
                         'BOUNDARY_OBSERVATION_NOT_DISPATCHED')

    def test_repeated_targets_keep_original_slots_and_native_contribution(self):
        _, provider, cell = fixture()
        a = plan.plan_cell(cell, {'0x00401000': provider})
        b = plan.plan_cell(dict(cell, index=4, native_CRT_slot_candidates=[{}]), {'0x00401000': provider})
        self.assertNotEqual(a['index'], b['index'])
        self.assertEqual(a['namespace_proposal'], b['namespace_proposal'])
        self.assertFalse(b['requires_explicit_registration_beyond_native_XCU'])

    def test_planned_namespace_cannot_claim_materialization_or_adoption(self):
        document = dict(provider_identity_is_planned_namespace=True, materialized_exports=0,
            provider_selected=False, runtime_eligible=False, ABI_verified=False,
            materialization_approved=False, link_ready=False, namespace_approved=False)
        plan.check_provider_map(document)
        for key, wrong in [('materialized_exports', 1), ('provider_selected', True),
                           ('namespace_approved', True)]:
            with self.assertRaises(ValueError): plan.check_provider_map(dict(document, **{key: wrong}))


if __name__ == '__main__': unittest.main()
