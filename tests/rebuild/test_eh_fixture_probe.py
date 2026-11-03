import copy
import json
from pathlib import Path
import sys
import tempfile
import unittest
from unittest.mock import patch
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'tools/rebuild'))
import eh_fixture_probe as probe

class ProbeTests(unittest.TestCase):
    def basis(self):
        p=dict(schema_version=1,kind='original-eh-fixture-prepared',status='prepared_pending_independent_review',policy=probe.extract.POLICY,execution_performed=False,variants=[dict(name=n,exe_sha256=n+'exe',map_sha256=n+'map') for n in ('normal','moved')])
        r=dict(schema_version=1,kind='original-eh-fixture-review',approved=True,reviewer='independent reviewer',prepare_sha256='hash',variants=copy.deepcopy(p['variants']),checks={k:True for k in ('closure','linked_eh_metadata','safe_seh','crt_providers','map_and_imports')})
        return p,r
    def test_behavior_receipt(self):
        self.assertEqual(probe.parse_receipt(json.dumps(probe.EXPECTED),0),probe.EXPECTED)
        for text,code in [(json.dumps(probe.EXPECTED),1),('{}',0),(json.dumps(probe.EXPECTED)+'\n{}',0),(json.dumps(dict(probe.EXPECTED,checks_ok=True)),0)]:
            with self.assertRaises(ValueError):probe.parse_receipt(text,code)
    def test_review_requires_every_variant_and_check(self):
        p,r=self.basis();probe.validate_review(p,r,'hash')
        for field in ('closure','linked_eh_metadata','safe_seh','crt_providers','map_and_imports'):
            changed=copy.deepcopy(r);changed['checks'][field]=False
            with self.assertRaises(ValueError):probe.validate_review(p,changed,'hash')
        r['variants'].pop()
        with self.assertRaises(ValueError):probe.validate_review(p,r,'hash')
    def test_unknown_schema_stale_hash_and_not_approved(self):
        for field,value in [('schema_version',2),('approved',False),('reviewer',''),('prepare_sha256','stale')]:
            p,r=self.basis();r[field]=value
            with self.assertRaises(ValueError):probe.validate_review(p,r,'hash')
    def test_execution_collision_no_launch(self):
        with tempfile.TemporaryDirectory() as d:
            p=Path(d)/'prepare.json';p.write_text('{}')
            with self.assertRaises(ValueError):probe.execute(p,p,'hash',p)
    def test_stale_execution_artifact_saves_failure_without_launch(self):
        with tempfile.TemporaryDirectory() as d:
            folder=Path(d);p,r=self.basis();p['inputs']={};p['artifacts']={};p['os_dependencies']={}
            for variant in p['variants']:
                for key in ('exe','map'):
                    f=folder/(variant['name']+'.'+key);f.write_text('fixture')
                    variant[key]=str(f);variant[key+'_sha256']=probe.sha(f)
            pp=folder/'prepare.json';rp=folder/'review.json';out=folder/'execute.json'
            pp.write_text(json.dumps(p));r['prepare_sha256']=probe.sha(pp)
            r['variants']=[{k:v[k] for k in ('name','exe_sha256','map_sha256')} for v in p['variants']]
            rp.write_text(json.dumps(r));Path(p['variants'][0]['exe']).write_text('changed')
            with patch.object(probe.subprocess,'run') as run:
                result=probe.execute(pp,rp,probe.sha(rp),out)
                run.assert_not_called()
            self.assertEqual(result['status'],'error');self.assertIn('changed',result['error']);self.assertTrue(out.exists())
    def test_map_parser(self):
        rows=probe.map_rows(' 0001:00000000 ?Ctor@@QAE@XZ 00401000 f selected.obj\n')
        self.assertEqual(rows['?Ctor@@QAE@XZ'][0]['address'],0x401000)

if __name__=='__main__':unittest.main()
