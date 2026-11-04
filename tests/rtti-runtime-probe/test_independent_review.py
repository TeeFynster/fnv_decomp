"""Independent regressions, synthetic metadata and paths only."""
import copy
import json
import os
from pathlib import Path
import stat
import sys
import tempfile
import types
import unittest
from unittest import mock
sys.path.insert(0,str(Path(__file__).resolve().parents[2]/'tools/rtti-runtime-probe'))
import rtti_probe_check as chk

class ReviewTests(unittest.TestCase):
    def test_reparse_ancestor_and_devices_rejected(self):
        with tempfile.TemporaryDirectory() as tmp:
            parent=Path(tmp)/'parent';parent.mkdir();p=parent/'x.json';p.write_text('{}');real=os.lstat
            def fake(path,*a,**k):
                if Path(path)==parent:return types.SimpleNamespace(st_mode=stat.S_IFDIR,st_file_attributes=0x400)
                return real(path,*a,**k)
            with mock.patch.object(chk.os,'lstat',side_effect=fake), mock.patch('builtins.open') as opened:
                with self.assertRaises(chk.UsageError):chk.read_input(str(p),1024)
                opened.assert_not_called()
        with mock.patch.object(chk.os,'lstat') as probe:
            for path in (chr(92)*2+'server'+chr(92)+'share'+chr(92)+'file.json','C:'+chr(92)+'NUL'+chr(92)+'file.json'):
                with self.assertRaises(chk.UsageError):chk.read_input(path,1024)
            probe.assert_not_called()
    def test_metadata_target_source_object_changes_not_pass(self):
        p=Path(__file__).resolve().parents[2]/'tools/rtti-abi/fixture/fixture-metadata.json';base=json.loads(p.read_text())
        for key,value in [('target','FakeTarget'),('input',{'object':'fake','path':['Fake']}),('form','reference')]:
            changed=copy.deepcopy(base);changed['casts'][0][key]=value
            self.assertNotEqual(chk.compare_metadata(changed)['verdict'],'PASS')
    def test_untrusted_plan_key_not_echoed(self):
        p=Path(__file__).resolve().parents[2]/'tools/rtti-runtime-probe/run-plan.json';plan=json.loads(p.read_text())
        secret='C:'+chr(92)+'Users'+chr(92)+'secret'+chr(92)+'private';plan[secret]=secret
        with self.assertRaises(chk.InputError) as err:chk.validate_plan(plan)
        self.assertNotIn(secret,str(err.exception.errors))
