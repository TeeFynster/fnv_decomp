"""Central batching tests use authored COFF only; no original metadata streams."""
from pathlib import Path
import copy
import sys
import unittest
from unittest.mock import patch
ROOT=Path(__file__).resolve().parents[2];sys.path.insert(0,str(ROOT/'tools/rebuild'))
import centralordinary_root_collect as c
from test_scalableordinary_root_collect import fixture


def records(fx):
    raw,u,p,roots,_,_,b=fx
    return list(c.observe_recipe(raw,u,p,roots,b,{},dict(object_sha256=u['object_sha256'],source_sha256=u['source_sha256'],request_sha256='a'*64)))


class CentralCollectorTests(unittest.TestCase):
    def test_one_parse_for_union_and_every_singleton(self):
        fx=fixture();parse=c.coff.parse
        with patch.object(c.coff,'parse',wraps=parse) as reader:rows=records(fx)
        self.assertEqual(reader.call_count,1);self.assertEqual([r['event'] for r in rows],['RECIPE_ROOT_UNION_OBSERVATION','SINGLE_ROOT_OBSERVATION','SINGLE_ROOT_OBSERVATION'])
        self.assertEqual([len(r['requested_roots']) for r in rows],[2,1,1])
        self.assertTrue(all(r['closure_observed'] for r in rows))

    def test_union_EH_registry_block_does_not_poison_safe_singleton(self):
        rows=records(fixture(safeseh=True))
        self.assertFalse(rows[0]['closure_observed']);self.assertTrue(rows[1]['closure_observed']);self.assertFalse(rows[2]['closure_observed'])
        self.assertNotEqual(rows[0]['contract_identity_sha256'],rows[1]['contract_identity_sha256'])

    def test_complete_contract_recomputes_frozen_producer_certificate(self):
        fx=fixture(field=True)
        for row in records(fx):
            self.assertEqual(c.digest(row['contract']),row['contract_identity_sha256'])
            self.assertEqual(c.ordinary.assess_object(c.coff.parse(fx[0]),row['contract']),row['certificate'])
            self.assertEqual(c.digest(row['certificate']),row['certificate_sha256'])
            for key in c.FALSE:self.assertIs(row[key],False)

    def test_dispatch_exact_root_and_recipe_lane_binding(self):
        roots=fixture()[3];request=dict(roots=roots)
        dispatch=dict(schema_version=1,kind='aggregate-selected-CODE-root-requests',roots=roots,lane_by_recipe={'authored':1},
            baseline_CODE_changed=False,native_operation_authorized=False,provider_selected=False,runtime_eligible=False,source_bodies_included=False)
        self.assertEqual(c.bind_dispatch(dispatch,request),{'authored':1})
        for change in ({'lane_by_recipe':{}},{'lane_by_recipe':{'authored':9}},{'provider_selected':True},{'roots':roots[:1]},{'schema_version':True}):
            with self.assertRaises(ValueError):c.bind_dispatch(dict(dispatch,**change),request)

    def test_unknown_format_accounts_union_and_all_singletons(self):
        fx=list(fixture());fx[0]=b'authored unknown format';fx[1]['object_sha256']=c.hashlib.sha256(fx[0]).hexdigest()
        for root in fx[3]:root['object_sha256']=fx[1]['object_sha256']
        rows=records(fx);self.assertEqual(len(rows),3);self.assertTrue(all(not r['closure_observed'] for r in rows))
        self.assertTrue(all(r['blockers'][0]['code']=='UNSUPPORTED_ORIGINAL_COFF_FORMAT' for r in rows))

    def test_stale_native_or_hash_never_produces_partial_success(self):
        fx=list(fixture());fx[0]+=b'changed'
        with self.assertRaises(ValueError):records(fx)
        fx=fixture();fx[3][1]['symbol_index']=2
        with self.assertRaises(ValueError):records(fx)

    def test_budgets_are_finite(self):
        with patch.object(c.time,'monotonic',return_value=100),patch.object(c,'peak_memory_bytes',return_value=1000):self.assertEqual(c.check_budget(0),1000)
        with patch.object(c.time,'monotonic',return_value=901),patch.object(c,'peak_memory_bytes',return_value=1000):
            with self.assertRaises(ValueError):c.check_budget(0)
        with patch.object(c.time,'monotonic',return_value=100),patch.object(c,'peak_memory_bytes',return_value=c.MAX_MEMORY+1):
            with self.assertRaises(ValueError):c.check_budget(0)

    def test_old_producer_and_helper_are_immutable_dependencies(self):
        self.assertEqual(c.file_hash(ROOT/'tools/rebuild/root_code_closure.py'),c.ORDINARY_PIN)
        self.assertEqual(c.file_hash(ROOT/'tools/rebuild/scalableordinary_root_collect.py'),c.FINITE_PIN)


if __name__=='__main__':unittest.main()
