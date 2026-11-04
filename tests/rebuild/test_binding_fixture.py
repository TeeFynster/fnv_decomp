"""Offline execution-gate tests; never launch a process."""
import copy
from pathlib import Path
import sys
import json
import tempfile
from unittest.mock import patch
import unittest
sys.path.insert(0,str(Path(__file__).resolve().parents[2]/'tools/rebuild'))
import binding_fixture as b

class FixtureGateTests(unittest.TestCase):
    def setUp(self):
        self.p=dict(schema_version=1,kind='original-binding-fixture-prepared',policy=b.POLICY,execution_performed=False,status='prepared_pending_independent_review',exe_sha256='e'*64,map_sha256='a'*64)
        self.r=dict(schema_version=1,kind='original-binding-fixture-review',approved=True,reviewer='independent',prepare_sha256='p'*64,exe_sha256='e'*64,map_sha256='a'*64,checks={k:True for k in b.CHECKS})
    def test_complete_gate(self): b.validate_review(self.p,self.r,'p'*64)
    def test_missing_check_rejected(self):
        for k in b.CHECKS:
            r=copy.deepcopy(self.r); r['checks'][k]=False
            with self.assertRaisesRegex(ValueError,'incomplete'): b.validate_review(self.p,r,'p'*64)
    def test_stale_review_and_artifacts(self):
        for k in ('prepare_sha256','exe_sha256','map_sha256'):
            r=copy.deepcopy(self.r); r[k]='0'*64
            with self.assertRaises(ValueError): b.validate_review(self.p,r,'p'*64)
    def test_changed_protected_artifact_never_launches(self):
        with tempfile.TemporaryDirectory() as td:
            d=Path(td); artifact=d/'fixture.exe'; artifact.write_bytes(b'original')
            mp=d/'fixture.map'; mp.write_bytes(b'map')
            p=copy.deepcopy(self.p)
            p.update(exe=str(artifact),map=str(mp),exe_sha256=b.sha(artifact),map_sha256=b.sha(mp),inputs={},os_dependencies={},artifacts={str(artifact):b.sha(artifact),str(mp):b.sha(mp)})
            pp=d/'prepare.json'; pp.write_text(json.dumps(p))
            r=copy.deepcopy(self.r); r.update(prepare_sha256=b.sha(pp),exe_sha256=p['exe_sha256'],map_sha256=p['map_sha256'])
            rp=d/'review.json'; rp.write_text(json.dumps(r))
            artifact.write_bytes(b'changed')
            with patch.object(b.subprocess,'run') as run:
                result=b.execute(pp,rp,b.sha(rp),d/'execution.json')
                self.assertEqual(result['status'],'error'); run.assert_not_called()
            self.assertIn('changed',result['error'])

    def test_unreviewed_or_already_executed(self):
        self.r['approved']=False
        with self.assertRaises(ValueError): b.validate_review(self.p,self.r,'p'*64)
        self.r['approved']=True; self.p['execution_performed']=True
        with self.assertRaises(ValueError): b.validate_review(self.p,self.r,'p'*64)
if __name__=='__main__': unittest.main()
