"""Authored finite collector and dynamic read-scope tests only."""
import copy
import gzip
import json
from pathlib import Path
import sys
import tempfile
import unittest
from unittest.mock import patch
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'tools/rebuild'))
import parent_eh_collect as collector
from test_parent_eh_adapter import valid_case

class Metadata:
    base=0
    def section(self,address,size,required=False):
        return dict(executable=any(a<address+size and b>address for a,b in ((0x10000000,0x10020000),(0x20000000,0x20002000))))

class ParentCollectorTests(unittest.TestCase):
    def test_derived_scope_uses_real_handler_piece_not_contiguous_anchor(self):
        case=valid_case();scope=collector.prepare_reference(case['raw'],case['recipe'],case['unit_proof'],case['contract'],case['reference'],Metadata())
        self.assertEqual(scope.reads,[dict(address=0x20001012,size=4,completed=True)])
        self.assertEqual(scope.data_spans,[(0x30000000,0x3000002c,'own-handler-FuncInfo-anchor')])
        self.assertEqual(len(scope.read(0x30000000,44)),44)
        with self.assertRaises(collector.adapter.Blocked):scope.read(0x20000008,1)
    def test_failed_piece_does_not_read_native_reference(self):
        case=valid_case();case['contract']['parent_eh'][0][2]=False
        scope=collector.prepare_reference(case['raw'],case['recipe'],case['unit_proof'],case['contract'],case['reference'],Metadata());self.assertEqual(scope.reads,[]);self.assertEqual(scope.data_spans,[])
    def test_data_scope_rejects_executable_and_oversized_ranges(self):
        case=valid_case();scope=collector.ScopedReference(case['reference'],Metadata(),[(0x10000000,0x10000065)])
        for address,size in ((0x10000000,4),(0x30000000,4097)):
            with self.assertRaises(collector.adapter.Blocked):scope.add_data(address,size,'authored-invalid')
        with self.assertRaises(collector.adapter.Blocked):scope.read(0x30000000,4)
    def test_only_exact_saved_contract_records_are_admitted(self):
        case=valid_case();root=dict(case['contract']['roots'][0],recipe_id='authored',recipe_index=777,object_sha256=collector.adapter.sha(case['raw']),source_sha256='a'*64)
        cert={'kind':'authored-negative'};row=dict(event='SINGLE_ROOT_OBSERVATION',requested_roots=[root],contract=case['contract'],contract_identity_sha256=collector.adapter.digest(case['contract']),certificate=cert,certificate_sha256=collector.adapter.digest(cert))
        target=dict(root=root,central_record_ordinal=1,central_record_sha256=collector.adapter.digest(row),central_certificate_sha256=collector.adapter.digest(cert));policy={'targets':[target]}
        with tempfile.TemporaryDirectory() as folder:
            path=Path(folder)/'lane.gz'
            with gzip.open(path,'wt') as stream:stream.write(json.dumps(row)+'\n')
            found=collector.selected_contracts(policy,{},path);self.assertEqual(found[root['original_address']]['contract'],case['contract'])
            stale=copy.deepcopy(policy);stale['targets'][0]['central_record_sha256']='0'*64
            with self.assertRaises(collector.adapter.Blocked):collector.selected_contracts(stale,{},path)
            missing=copy.deepcopy(policy);missing['targets'][0]['central_record_ordinal']=2
            with self.assertRaises(collector.adapter.Blocked):collector.selected_contracts(missing,{},path)
    def test_exact_tool_set_and_fresh_private_output(self):
        values=[name+'='+'a'*64 for name in collector.TOOLS];self.assertEqual(set(collector.tool_pins(values)),set(collector.TOOLS))
        with self.assertRaises(collector.adapter.Blocked):collector.tool_pins(values[:-1])
        with self.assertRaises(collector.adapter.Blocked):collector.tool_pins(values+[values[0]])
        with tempfile.TemporaryDirectory() as folder,patch.object(collector,'ROOT',Path(folder)):
            private=Path(folder)/'build/rebuild';private.mkdir(parents=True)
            self.assertEqual(collector.private_directory(private/'fresh'),private/'fresh')
            with self.assertRaises(collector.adapter.Blocked):collector.private_directory(Path(folder)/'public')
            (private/'existing').mkdir()
            with self.assertRaises(collector.adapter.Blocked):collector.private_directory(private/'existing')

    def test_failed_derived_scope_preserves_completed_anchor_read(self):
        case=valid_case();reads=[];data=[]
        class BadMetadata:
            base=0
            def section(self,*args,**kwargs):return dict(executable=True)
        with self.assertRaises(collector.adapter.Blocked):collector.prepare_reference(case['raw'],case['recipe'],case['unit_proof'],case['contract'],case['reference'],BadMetadata(),reads,data)
        self.assertEqual(reads,[dict(address=0x20001012,size=4,completed=True)]);self.assertEqual(data,[])

    def test_postwork_resource_budget_detects_final_overrun(self):
        with patch.object(collector.time,'monotonic',return_value=541),patch.object(collector,'peak_memory_bytes',return_value=0):
            with self.assertRaises(collector.adapter.Blocked):collector.check_budget(0)
        with patch.object(collector.time,'monotonic',return_value=1),patch.object(collector,'peak_memory_bytes',return_value=1073741825):
            with self.assertRaises(collector.adapter.Blocked):collector.check_budget(0)
    def test_exact_reviewed_code_scope_cannot_expand(self):
        case=valid_case()
        with self.assertRaises(collector.adapter.Blocked):collector.prepare_reference(case['raw'],case['recipe'],case['unit_proof'],case['contract'],case['reference'],Metadata(),approved_code_spans=[[0x10000000,0x20002000]])

    def test_hashing_does_not_materialize_native_input(self):
        import hashlib
        with tempfile.TemporaryDirectory() as folder:
            path=Path(folder)/'authored-input';payload=b'authored bounded streaming hash';path.write_bytes(payload)
            with patch.object(Path,'read_bytes',side_effect=AssertionError('unbounded whole-file allocation')):
                self.assertEqual(collector.file_hash(path),hashlib.sha256(payload).hexdigest())

if __name__=='__main__':unittest.main()
