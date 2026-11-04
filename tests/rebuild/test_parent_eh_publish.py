"""Authored publication/provenance guards, no original inputs/native programs."""
import gzip
import json
from pathlib import Path
import sys
import tempfile
import time
import unittest
from unittest.mock import patch
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'tools/rebuild'))
import parent_eh_publish as publisher


class ParentEHPublicationTests(unittest.TestCase):
    def test_exact_tool_set_unknown_and_missing_reject(self):
        values=[name+'='+'a'*64 for name in publisher.TOOLS]
        self.assertEqual(len(publisher.parse_pins(values)),21)
        for bad in (values[:-1],values+[values[0]],values+['unknown.py='+'a'*64]):
            with self.assertRaises(ValueError):publisher.parse_pins(bad)

    def test_saved_command_unknown_argument_rejects(self):
        with self.assertRaises(ValueError):publisher.saved_arguments(dict(argv=['python','wrong.py']))
        argv=['python',str(ROOT/'tools/rebuild/parent_eh_collect.py'),'--mystery','x']
        with self.assertRaises(ValueError):publisher.saved_arguments(dict(argv=argv))

    def test_detail_outcome_identity_is_mandatory(self):
        with tempfile.TemporaryDirectory() as directory:
            path=Path(directory)/'rows.gz';row=dict(root=dict(original_address='0x10000000'),result=dict(structural_projection_candidate=True))
            with gzip.open(path,'wt') as f:f.write(json.dumps(row)+'\n')
            receipt=dict(details_sha256=publisher.collector.file_hash(path),roots=1,outcomes=[dict(record_sha256=publisher.adapter.digest(row),root=row['root'])])
            self.assertEqual(publisher.load_record(path,receipt,'0x10000000'),row)
            receipt['outcomes'][0]['record_sha256']='0'*64
            with self.assertRaises(ValueError):publisher.load_record(path,receipt,'0x10000000')

    def setup_publication(self,directory):
        directory=Path(directory);data=b'authored publication payload'
        (directory/'component.staged.obj').write_bytes(data);(directory/'progress.jsonl').write_text('started\n')
        report=dict(output_sha256=publisher.adapter.sha(data))
        result=dict(projection=report,**publisher.adapter.FALSE)
        return directory,data,report,result

    def test_final_drift_removes_both_owned_success_outputs(self):
        with tempfile.TemporaryDirectory() as folder:
            directory,data,report,result=self.setup_publication(folder);notes=[]
            with patch.object(publisher.collector,'stable',side_effect=[None,ValueError('late drift')]):
                with self.assertRaisesRegex(ValueError,'late drift'):
                    publisher.publish_outputs(directory,data,report,time.monotonic(),{},lambda:result,notes.append)
            self.assertFalse((directory/'component.obj').exists());self.assertFalse((directory/'projection.json').exists())
            self.assertTrue((directory/'component.staged.obj').exists());self.assertEqual(notes,[])

    def test_exclusive_collision_preserves_existing_file(self):
        with tempfile.TemporaryDirectory() as folder:
            directory,data,report,result=self.setup_publication(folder);output=directory/'component.obj';output.write_bytes(b'owned elsewhere')
            with self.assertRaises(FileExistsError):publisher.publish_outputs(directory,data,report,time.monotonic(),{},lambda:result,lambda r:None)
            self.assertEqual(output.read_bytes(),b'owned elsewhere')

    def test_success_retains_false_runtime_flags_and_exact_hash(self):
        with tempfile.TemporaryDirectory() as folder:
            directory,data,report,result=self.setup_publication(folder);notes=[]
            with patch.object(publisher.collector,'stable'):
                observed=publisher.publish_outputs(directory,data,report,time.monotonic(),{},lambda:result,notes.append)
            self.assertEqual(observed,result);self.assertEqual((directory/'component.obj').read_bytes(),data)
            self.assertEqual(notes[0]['state'],'complete');self.assertFalse(observed['runtime_eligible'])


if __name__=='__main__':unittest.main()
