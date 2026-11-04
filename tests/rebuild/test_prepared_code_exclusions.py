"""Authored epoch records; no original images, objects or native commands."""
import copy
from pathlib import Path
import sys
import tempfile
import time
import unittest
from unittest.mock import patch
ROOT=Path(__file__).resolve().parents[2]
sys.path[:0]=[str(ROOT/'tools/rebuild'),str(ROOT/'tests/rebuild')]
import prepared_code_exclusions as prepared
from test_prepared_code_exclusions_independent import epoch_fixture


class PreparedEpochTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):cls.fixture=epoch_fixture()

    def test_full_epoch_has_no_selected_application_count(self):
        manifest=prepared.build_manifest(*self.fixture)
        self.assertEqual(manifest['ordinary_prepared_count'],14329)
        self.assertEqual(manifest['collision_exclusion_count'],14333)
        self.assertIsNone(manifest['application_selected_code_count'])
        self.assertFalse(manifest['application_manifest_adopted'])

    def test_same_count_never_equates_different_sets(self):
        manifest=prepared.build_manifest(*self.fixture)
        self.assertEqual(len(manifest['ordinary_names']),14329)
        self.assertEqual(len(set(manifest['exclusion_names'])-set(manifest['ordinary_names'])),4)
        self.assertTrue(manifest['prior_application_observation_excludes_new_first3'])

    def test_application_physical_candidate_cannot_gain_logical_binding(self):
        ordinary,app,providers,bindings=self.fixture
        changed=copy.deepcopy(app);changed[-1]['logical_binding_applied']=True
        with self.assertRaises(ValueError):prepared.build_manifest(ordinary,changed,providers,bindings)

    def test_wrong_original_address_or_replacement_of_alternate_origin_fails(self):
        ordinary,app,providers,bindings=self.fixture
        changed=copy.deepcopy(app);changed[-1]['original_address']='not-an-original-address'
        with self.assertRaises(ValueError):prepared.build_manifest(ordinary,changed,providers,bindings)
        changed=copy.deepcopy(app);changed[1]['origin_identity']=changed[1]['namespace_identity']
        with self.assertRaises(ValueError):prepared.build_manifest(ordinary,changed,providers,bindings)

    def test_immutable_prepared_epoch_does_not_authorize_code_or_runtime(self):
        manifest=prepared.build_manifest(*self.fixture)
        for flag in prepared.FALSE:self.assertIs(manifest[flag],False)
        self.assertTrue(manifest['prepared_namespace_only'])

    def test_terminal_metadata_publisher_retains_no_success_on_drift(self):
        with tempfile.TemporaryDirectory() as td:
            p=Path(td);checks=[]
            def stable(_):
                checks.append(1)
                if len(checks)==3:raise ValueError('authored post-publication drift')
            with patch.object(prepared.base,'stable',side_effect=stable),patch.object(prepared.base,'budget',return_value={}):
                with self.assertRaises(ValueError):prepared.base.publish_receipt(p,dict(status='completed'),{},time.monotonic())
            self.assertFalse((p/'receipt.json').exists());self.assertTrue((p/'receipt.pending.json').exists())


if __name__=='__main__':unittest.main()
