"""Synthetic process/resource tests; never launch the real producer or native tools."""
import copy
import json
from pathlib import Path
import sys
import tempfile
import unittest
from unittest.mock import patch
sys.path.insert(0,str(Path(__file__).resolve().parents[2]/'tools/rebuild'))
import bulk_code_supervisor as s


class Clock:
    def __init__(self):self.now=0
    def clock(self):return self.now
    def sleep(self,n):self.now+=n


class Process:
    pid=424242
    def __init__(self,states=(None,0)):
        self.states=list(states);self.kills=0;self.waits=0;self.terminated=False
    def poll(self):
        if self.terminated:return -9
        if len(self.states)>1:return self.states.pop(0)
        return self.states[0]
    def kill(self):self.kills+=1;self.terminated=True
    def wait(self,timeout):self.waits+=1;return -9 if self.terminated else self.states[-1]


ZERO_MEMORY=lambda p:dict(working=0,private=0,peak_working=0)
ZERO_USAGE=lambda p:dict(total=0,spool=0,log=0)
FREE=lambda p:10*1024**3


def authorize(root):
    for name in {*s.CHILD_SOURCES,*s.OWNED}:
        path=root/name;path.parent.mkdir(parents=True,exist_ok=True);path.write_text('authored synthetic source '+name+'\n')
    paths={name:root/(name+'.input') for name in s.INPUTS}
    for p in paths.values():p.write_text('authored input\n')
    r=dict(phase='bulk-code-pool-all-current-emission',mode='all-current',approved=True,
        independent_source_schema_review_pass=True,root_authorized=True,supervisor_source_review_pass=True,
        source_sha256={n:s.sha(root/n) for n in s.CHILD_SOURCES},supervisor_source_sha256={n:s.sha(root/n) for n in s.OWNED},
        python_executable_sha256=s.sha(sys.executable),supervision_limits=dict(s.LIMITS),reference_certificates=[])
    path=root/'review.json';path.write_text(json.dumps(r));return paths,path,s.sha(path)


def child_result(child,review,review_hash,status='complete',mode='all-current'):
    child.mkdir();artifacts={}
    for name,key in [('members.spool','spool_sha256'),('members.jsonl','member_ledger_sha256'),('coverage.jsonl.gz','coverage_sha256'),('unions.jsonl.gz','unions_sha256')]:
        p=child/name;p.write_bytes(b'authored fake-child artifact');artifacts[key]=s.sha(p)
    r=dict(kind='private-bulk-unresolved-code-pool',mode=mode,status=status,inputs_stable=True,
        inputs={str(review.resolve()):review_hash},requested=16859,emitted=16859 if status=='complete' else 100,shards=[],**artifacts)
    (child/'receipt.json').write_text(json.dumps(r))


class MonitorTests(unittest.TestCase):
    def test_each_resource_threshold_and_operator_stop(self):
        cases=[('working-set-threshold',dict(memory=lambda p:dict(working=s.LIMITS['working_set_bytes']+1,private=0,peak_working=0))),
            ('private-memory-threshold',dict(memory=lambda p:dict(working=0,private=s.LIMITS['private_bytes']+1,peak_working=0))),
            ('spool-threshold',dict(usage=lambda p:dict(total=0,spool=s.LIMITS['spool_bytes']+1,log=0))),
            ('output-threshold',dict(usage=lambda p:dict(total=s.LIMITS['output_bytes']+1,spool=0,log=0))),
            ('log-threshold',dict(usage=lambda p:dict(total=0,spool=0,log=s.LIMITS['log_bytes']+1))),
            ('free-space-threshold',dict(free=lambda p:s.LIMITS['free_floor_bytes']-1))]
        with tempfile.TemporaryDirectory() as d:
            root=Path(d)
            for expected,changes in cases:
                with self.subTest(expected=expected):
                    c=Clock();kwargs=dict(clock=c.clock,sleep=c.sleep,memory=ZERO_MEMORY,usage=ZERO_USAGE,free=FREE);kwargs.update(changes)
                    r=s.monitor(Process((None,)),root,lambda r:None,**kwargs);self.assertEqual(r['reason'],expected)
            (root/'stop.request').touch();c=Clock()
            r=s.monitor(Process((None,)),root,lambda r:None,clock=c.clock,sleep=c.sleep,memory=ZERO_MEMORY,usage=ZERO_USAGE,free=FREE)
            self.assertEqual(r['reason'],'operator-stop')

    def test_wall_threshold_is_sampled_and_peak_working_is_used(self):
        with tempfile.TemporaryDirectory() as d:
            c=Clock();samples=[]
            r=s.monitor(Process((None,)),Path(d),samples.append,clock=c.clock,sleep=c.sleep,memory=ZERO_MEMORY,usage=ZERO_USAGE,free=FREE)
            self.assertEqual(r['reason'],'wall-threshold');self.assertEqual(r['elapsed_seconds'],1800)
            self.assertLessEqual(max(x['elapsed_seconds'] for x in samples),1800)
            r=s.monitor(Process((None,)),Path(d),lambda r:None,clock=c.clock,sleep=c.sleep,
                memory=lambda p:dict(working=1,private=1,peak_working=s.LIMITS['working_set_bytes']+1),usage=ZERO_USAGE,free=FREE)
            self.assertEqual(r['reason'],'working-set-threshold')

    def test_exit_code_and_missing_memory_query_after_exit(self):
        with tempfile.TemporaryDirectory() as d:
            c=Clock();r=s.monitor(Process((7,)),Path(d),lambda r:None,clock=c.clock,sleep=c.sleep,
                memory=lambda p:(_ for _ in ()).throw(AssertionError('must not query exited process')),usage=ZERO_USAGE,free=FREE)
            self.assertEqual(r['returncode'],7);self.assertIsNone(r['reason'])

    def test_output_walk_is_only_owned_shallow_and_exact_snapshot_paths(self):
        with tempfile.TemporaryDirectory() as d:
            root=Path(d);child=root/'production';child.mkdir();(child/'members.spool').write_bytes(b'1234')
            (root/'child-output.log').write_bytes(b'12');self.assertEqual(s.output_usage(root),dict(total=6,spool=4,log=2))
            (child/'unexpected-directory').mkdir()
            with self.assertRaisesRegex(ValueError,'nonregular'):s.output_usage(root)
            outside=root/'outside';outside.write_bytes(b'data');owned=root/'owned';owned.mkdir()
            with self.assertRaisesRegex(ValueError,'escapes'):s.regular_size(outside,owned)


class SupervisorTests(unittest.TestCase):
    def scenario(self,root,*,status='complete',mode='all-current',states=(None,0),memory=ZERO_MEMORY,change_source=False,initial_free=FREE):
        paths,review,h=authorize(root);run=root/'build/rebuild/fresh';run.parent.mkdir(parents=True)
        process=Process(states);calls=[]
        def launch(command,**kwargs):
            calls.append(command);child_result(run/'production',review,h,status,mode)
            kwargs['stdout'].write(b'authored child output\n');kwargs['stdout'].flush()
            if change_source:(root/s.CHILD_SOURCES[1]).write_text('changed after launch')
            return process
        c=Clock()
        with patch.object(s,'ROOT',root),patch.object(s,'PRODUCER_SHA256',s.sha(root/s.PRODUCER)):
            r=s.run(paths,review,h,run,popen=launch,clock=c.clock,sleep=c.sleep,memory=memory,free=initial_free)
        return r,process,calls,run

    def test_one_python_child_complete_and_hash_bound_artifacts(self):
        with tempfile.TemporaryDirectory() as d:
            r,p,calls,run=self.scenario(Path(d))
            self.assertEqual(r['status'],'completed');self.assertEqual(len(calls),1);self.assertEqual(p.kills,0)
            self.assertEqual(calls[0][1:4],['-E','-s','-B']);self.assertIn('--mode',calls[0]);self.assertEqual(calls[0][calls[0].index('--mode')+1],'all-current')
            self.assertEqual(r['child_receipt']['sha256'],s.sha(run/'production/receipt.json'))
            self.assertEqual(len(r['child_receipt']['artifacts']),4);self.assertTrue(r['inputs_stable']);self.assertFalse(r['retry_performed'])
            self.assertTrue(r['thresholds_are_sampled']);self.assertFalse(r['hard_OS_memory_or_disk_quota'])
            self.assertFalse(r['supervisor_namespace_or_selection_performed'])
            self.assertTrue((run/'supervisor-receipt.json').exists())

    def test_child_incomplete_is_distinct_and_not_retried(self):
        with tempfile.TemporaryDirectory() as d:
            r,p,calls,run=self.scenario(Path(d),status='incomplete')
            self.assertEqual(r['status'],'completed-incomplete');self.assertEqual(r['child_receipt']['status'],'incomplete');self.assertEqual(len(calls),1)

    def test_resource_abort_kills_only_owned_child_and_rejects_late_receipt(self):
        with tempfile.TemporaryDirectory() as d:
            r,p,calls,run=self.scenario(Path(d),states=(None,),memory=lambda p:dict(working=s.LIMITS['working_set_bytes']+1,private=0,peak_working=0))
            self.assertEqual(r['status'],'aborted');self.assertEqual(r['abort_reason'],'working-set-threshold');self.assertEqual(p.kills,1)
            self.assertIsNone(r['child_receipt']);self.assertEqual(r['unaccepted_child_receipt_sha256'],s.sha(run/'production/receipt.json'));self.assertEqual(len(calls),1)

    def test_monitor_error_stops_owned_child_and_records_error(self):
        with tempfile.TemporaryDirectory() as d:
            def broken(p):raise OSError('authored memory adapter failure')
            r,p,calls,run=self.scenario(Path(d),states=(None,),memory=broken)
            self.assertEqual(r['status'],'aborted');self.assertEqual(p.kills,1);self.assertEqual(r['error']['type'],'OSError')
            self.assertTrue((run/'supervisor-receipt.json').exists())

    def test_child_nonzero_or_wrong_terminal_mode_is_abort(self):
        for kwargs in (dict(states=(7,)),dict(mode='pilot')):
            with tempfile.TemporaryDirectory() as d:
                r,p,calls,run=self.scenario(Path(d),**kwargs)
                self.assertEqual(r['status'],'aborted');self.assertIsNone(r['child_receipt']);self.assertEqual(len(calls),1)

    def test_changed_source_after_child_completion_invalidates_supervision(self):
        with tempfile.TemporaryDirectory() as d:
            r,p,calls,run=self.scenario(Path(d),change_source=True)
            self.assertEqual(r['status'],'aborted');self.assertFalse(r['inputs_stable']);self.assertIsNone(r['child_receipt'])
            self.assertEqual(r['abort_reason'],'source-or-review-changed')

    def test_low_initial_free_space_never_launches(self):
        with tempfile.TemporaryDirectory() as d:
            r,p,calls,run=self.scenario(Path(d),initial_free=lambda p:s.LIMITS['free_start_bytes']-1)
            self.assertEqual(r['status'],'aborted');self.assertEqual(calls,[]);self.assertFalse(r['child_python_producer_launched'])
            self.assertIn('initial free',r['error']['message'])

    def test_gate_rejects_pilot_certificate_unknown_argument_or_changed_pin(self):
        with tempfile.TemporaryDirectory() as d:
            root=Path(d);paths,review,h=authorize(root)
            with patch.object(s,'ROOT',root),patch.object(s,'PRODUCER_SHA256',s.sha(root/s.PRODUCER)):
                for key,value in [('mode','pilot'),('reference_certificates',[{}]),('supervision_limits',dict(s.LIMITS,wall_seconds=1801)),('root_authorized',False)]:
                    r=json.loads(review.read_text());r[key]=value;other=root/(key+'.json');other.write_text(json.dumps(r))
                    with self.assertRaises(ValueError):s.preflight(paths,other,s.sha(other),root/'future')
                with self.assertRaisesRegex(ValueError,'argument set'):s.preflight(dict(paths,unknown='not-read'),review,h,root/'future')
                (root/s.PRODUCER).write_text('changed producer')
                with self.assertRaisesRegex(ValueError,'fingerprint'):s.preflight(paths,review,h,root/'future')

    def test_preflight_failure_has_abort_receipt_and_existing_directory_untouched(self):
        with tempfile.TemporaryDirectory() as d:
            root=Path(d);paths,review,h=authorize(root);run=root/'build/rebuild/fresh';run.parent.mkdir(parents=True)
            r=json.loads(review.read_text());r['root_authorized']=False;review.write_text(json.dumps(r))
            with patch.object(s,'ROOT',root):
                result=s.run(paths,review,s.sha(review),run,popen=lambda *a,**k:(_ for _ in ()).throw(AssertionError('no launch')))
                self.assertEqual(result['status'],'aborted');self.assertEqual(result['review_expected_sha256'],s.sha(review))
                before=(run/'supervisor-receipt.json').read_bytes()
                with self.assertRaisesRegex(ValueError,'exclusive'):s.run(paths,review,s.sha(review),run)
                self.assertEqual(before,(run/'supervisor-receipt.json').read_bytes())

    def test_child_artifact_hash_and_shard_path_are_verified(self):
        with tempfile.TemporaryDirectory() as d:
            root=Path(d);child=root/'production';review=root/'review';review.write_text('review');h=s.sha(review);child_result(child,review,h)
            (child/'members.spool').write_bytes(b'changed')
            with self.assertRaisesRegex(ValueError,'artifact hash'):s.bind_child_receipt(root,review,h)
            p=child/'receipt.json';r=json.loads(p.read_text());r['spool_sha256']=s.sha(child/'members.spool');r['shards']=[dict(name='../outside.lib',sha256='a'*64)];p.write_text(json.dumps(r))
            with self.assertRaisesRegex(ValueError,'shard path'):s.bind_child_receipt(root,review,h)


if __name__=='__main__':unittest.main()
