"""Authored metadata/COFF and fault injection only; no Game artifact reads."""
import argparse
import base64
import copy
import gzip
import json
from pathlib import Path
import stat
import sys
import tempfile
from types import SimpleNamespace
import unittest
from unittest.mock import patch

sys.path.insert(0,str(Path(__file__).resolve().parents[2]/'tools/rebuild'))
import union_reference_production_v3 as v3
from test_coff_code_archive import tiny


def marker(layout,image):
    return dict(layout=layout,arguments=[],executable_sha256=image,status='pass',state='finished',returncode=0,
        capture_prefix_incomplete=False,elapsed_seconds=0.03,observed=v3.EXPECTED,
        stdout_base64=base64.b64encode(json.dumps(v3.EXPECTED).encode()+b'\n').decode(),stderr_base64='')


def mechanism():
    pin=v3.BOX_PINS
    pp=pin['build/rebuild/box-union-component-continuation-v1/prepare.json'];np=pin['build/rebuild/box-union-component-continuation-v1/independent-native-artifact-review.json']
    ep=pin['build/rebuild/box-union-component-execution-v1/execution.json'];hp=pin['build/rebuild/box-union-component-execute-v1.py'];hr=pin['build/rebuild/box-union-component-execution-harness-review-v1.json']
    layouts={name:dict(executable_sha256=ch*64,map_sha256=mh*64) for name,ch,mh in [('normal','a','c'),('moved','b','d')]}
    prepared=dict(kind='real-source-box-two-layout-continued-preparation-v1',status='prepared-not-executed',input_stability_verified=True,
        cached_links=1,fresh_link_attempts=1,fresh_links_completed=1,normal_recompiled=False,normal_relinked=False,caller_recompiled=False,layouts=layouts)
    native=dict(kind='box-union-component-native-artifact-review-v1',status='accepted',reviewer='authored-test',prepare_sha256=pp,
        execution_authorized=False,runtime_provider_approved=False)
    harness=dict(kind='box-union-component-execution-harness-review-v1',status='accepted',harness_sha256=hp,prepare_sha256=pp,native_review_sha256=np)
    execution=dict(kind='real-source-box-union-component-execution-v1',status='pass',input_stability_verified=True,
        runtime_provider_approved=False,broader_Game_runtime_approved=False,all185_enabled=False,
        prepare_sha256=pp,native_review_sha256=np,harness_sha256=hp,harness_review_sha256=hr,
        children=[marker(name,row['executable_sha256']) for name,row in layouts.items()])
    outcome=dict(kind='box-union-component-execution-outcome-review-v1',status='accepted',reviewer='authored-test',execution_sha256=ep,
        prepare_sha256=pp,native_review_sha256=np,harness_sha256=hp,harness_review_sha256=hr,guard_checks_passed=True,
        native_link_mechanism_observed=True,all185_authorized=False,runtime_provider_approved=False,broader_game_runtime_approved=False)
    for name,row in layouts.items():
        native[name+'_executable_sha256']=outcome[name+'_executable_sha256']=row['executable_sha256']
        native[name+'_map_sha256']=row['map_sha256']
    record=dict(native_shape_verified=True,fresh_reference_match=True,certificate=dict(recipe_id=v3.projection.BOX,
        roots=[dict(size=n) for n in (50,72,60)],groups=[dict(members=[8,19],kind='one-selected-definition-and-undefined',native_shape_verified=True)],
        primary_bijection=[[8,6],[19,13]],runtime_eligible=False,provider_selected=False))
    return prepared,native,harness,execution,outcome,record


class ProductionV3Tests(unittest.TestCase):
    def test_no_delegated_opt_in_before_any_read(self):
        with patch.object(v3,'sha',side_effect=AssertionError('read')):
            with self.assertRaisesRegex(ValueError,'explicit delegated'):v3.run(argparse.Namespace(allow_production=False))

    def test_merge_rejects_conflicting_identity_and_accepts_same_path_alias(self):
        with tempfile.TemporaryDirectory() as d:
            path=Path(d)/'input';pins={};v3.merge_pins(pins,{path:'a'*64});v3.merge_pins(pins,{str(path):'a'*64})
            self.assertEqual(len(pins),1)
            with self.assertRaisesRegex(ValueError,'conflicting protected'):v3.merge_pins(pins,{path:'b'*64})

    def test_actual_box_cross_artifact_mechanism(self):v3.validate_mechanism(*mechanism())

    def test_same_addresses_do_not_replace_image_map_or_execution_lineage(self):
        for mutate in (lambda x:x[3]['children'][0].update(executable_sha256='f'*64),
                       lambda x:x[1].update(normal_map_sha256='f'*64),
                       lambda x:x[4].update(execution_sha256='f'*64),
                       lambda x:x[2].update(harness_sha256='f'*64)):
            evidence=mechanism();mutate(evidence)
            with self.assertRaises(ValueError):v3.validate_mechanism(*evidence)

    def test_tested_outcome_is_not_provider_or_all185_authority(self):
        for mutate in (lambda x:x[4].update(all185_authorized=True),lambda x:x[4].update(runtime_provider_approved=True),
                       lambda x:x[4].update(broader_game_runtime_approved=True),lambda x:x[3].update(all185_enabled=True)):
            evidence=mechanism();mutate(evidence)
            with self.assertRaises(ValueError):v3.validate_mechanism(*evidence)

    def test_two_ordered_successful_children_required(self):
        for mutate in (lambda x:x[3]['children'].reverse(),lambda x:x[3]['children'].pop(),
                       lambda x:x[3]['children'][0].update(returncode=21),lambda x:x[3]['children'][1].update(capture_prefix_incomplete=True)):
            evidence=mechanism();mutate(evidence)
            with self.assertRaises(ValueError):v3.validate_mechanism(*evidence)

    def test_exact_marker_typed_guards_and_empty_stderr(self):
        child=marker('normal','a'*64);self.assertEqual(v3.exact_marker(child),v3.EXPECTED)
        for key,value in [('stderr_base64',base64.b64encode(b'failure').decode()),('elapsed_seconds',16),('stdout_base64','not base64')]:
            bad=dict(child);bad[key]=value
            with self.assertRaises(ValueError):v3.exact_marker(bad)
        bad=dict(child);wrong=dict(v3.EXPECTED);wrong['guards_ok']=1;bad['stdout_base64']=base64.b64encode(json.dumps(wrong).encode()).decode()
        with self.assertRaises(ValueError):v3.exact_marker(bad)

    def test_distinct_native_definition_and_undefined_must_survive(self):
        evidence=mechanism();evidence[-1]['certificate']['primary_bijection']=[[8,6],[19,6]]
        with self.assertRaisesRegex(ValueError,'physical Box group'):v3.validate_mechanism(*evidence)

    def test_stale_box_files_fail_before_untrusted_receipt_read(self):
        with patch.object(v3.projection,'stable',side_effect=ValueError('stale artifact')),patch.object(v3.projection,'load_json',side_effect=AssertionError('read')):
            with self.assertRaisesRegex(ValueError,'stale artifact'):v3.box_basis()

    def test_recomputed_box_certificate_or_payload_must_equal_actual_tested_one(self):
        tested=dict(certificate=dict(authored='old'));certificate=dict(authored='new')
        with self.assertRaisesRegex(ValueError,'certificate differs'):v3.tested_box_equal(v3.projection.BOX,certificate,None,tested)
        with self.assertRaisesRegex(ValueError,'emitted member differs'):v3.tested_box_equal(v3.projection.BOX,tested['certificate'],b'authored',tested)
        v3.tested_box_equal('other',certificate,b'authored',tested)

    def phase(self,d):
        path=Path(d)/'review.json';sources=dict(authored='s');policy=dict(producer_sha256={})
        candidates=[v3.projection.BOX]+['authored-%03d'%i for i in range(184)];observation=dict(candidate_recipe_ids=candidates,metadata_candidate_roots=1372)
        review=dict(kind='union-reference-production-phase-v3',schema_version=1,status='approved',reviewer='authored-test',root_authorized=True,
            source_sha256=sources,producer_sha256={},box_outcome_review_sha256=v3.BOX_PINS[v3.BOX_OUTCOME],recipe_ids=sorted(candidates),root_count=1372,
            native_tools_allowed=False,execution_allowed=False)
        path.write_text(json.dumps(review));args=argparse.Namespace(allow_production=True,review=path,review_sha256=v3.sha(path))
        return args,policy,sources,observation,review

    def test_exact_new_source_phase_is_required_independently(self):
        with tempfile.TemporaryDirectory() as d:
            args,policy,sources,observation,_=self.phase(d)
            self.assertEqual(len(v3.phase_gate(args,policy,sources,observation)),185)
            args.review.write_text('{}')
            with self.assertRaisesRegex(ValueError,'stale'):v3.phase_gate(args,policy,sources,observation)

    def test_wrong_candidate_scope_role_permission_or_source_rejected(self):
        with tempfile.TemporaryDirectory() as d:
            args,policy,sources,observation,review=self.phase(d)
            for key,value in [('root_count',1373),('native_tools_allowed',True),('execution_allowed',True),('source_sha256',{}),('box_outcome_review_sha256','f'*64)]:
                altered=dict(review);altered[key]=value;args.review.write_text(json.dumps(altered));args.review_sha256=v3.sha(args.review)
                with self.assertRaises(ValueError):v3.phase_gate(args,policy,sources,observation)
            args.review.write_text(json.dumps(review));args.review_sha256=v3.sha(args.review);observation['candidate_recipe_ids'].append('extra')
            with self.assertRaisesRegex(ValueError,'finite185'):v3.phase_gate(args,policy,sources,observation)

    def test_full_coverage_has_no_box_double_count_or_legacy_overwrite(self):
        rows=[(i,dict(original_address='0x%08x'%i,status='EMITTED' if i<12946 else 'HISTORICAL_BLOCKED' if i<64744 else 'BLOCKED_UNION',physical_identity={})) for i in range(68657)]
        emitted={'0x%08x'%i for i in range(64744,66116)}
        with tempfile.TemporaryDirectory() as d,patch.object(v3.groups,'saved_records',return_value=iter(rows)):
            counts=v3.write_coverage(Path(d)/'coverage.gz',None,emitted)
        self.assertEqual(counts,dict(UPSTREAM_EMITTED_UNCHANGED=12946,UPSTREAM_HISTORICAL_BLOCKED=51798,NEW_UNION_V3_PROJECTED=1372,STILL_UNION_BLOCKED=2541))
        with tempfile.TemporaryDirectory() as d,patch.object(v3.groups,'saved_records',return_value=iter(rows)):
            with self.assertRaisesRegex(ValueError,'overwrite old'):v3.write_coverage(Path(d)/'coverage.gz',None,{'0x00000000'})

    def test_time_and_output_budgets(self):
        with tempfile.TemporaryDirectory() as d:
            with patch.object(v3.time,'monotonic',return_value=901):
                with self.assertRaisesRegex(ValueError,'15-minute'):v3.budget(d,0)
            (Path(d)/'dummy').write_text('authored')
            with patch.object(Path,'stat',return_value=SimpleNamespace(st_mode=stat.S_IFREG,st_size=128*1024*1024)):
                with self.assertRaisesRegex(ValueError,'budget'):v3.budget(d,v3.time.monotonic())

    def orchestration_failure(self,d,recovery=False,late_mutation=False):
        """Mock proofs ONLY to exercise failure plumbing, not eligibility.

        All source data and emitted COFF are authored synthetic fixtures. The
        actual producer never substitutes these mocks or accepts this evidence.
        """
        root=Path(d);(root/'build/rebuild').mkdir(parents=True)
        for owned in v3.OWNED:
            path=root/owned;path.parent.mkdir(parents=True,exist_ok=True);path.write_text('authored source fixture')
        policy=dict(policy_id=v3.POLICY,box_artifact_sha256=v3.BOX_PINS,producer_sha256={},reference_sha256='r'*64)
        (root/v3.OWNED[2]).write_text(json.dumps(policy))
        wanted=[v3.projection.BOX]+['authored-%03d'%i for i in range(184)];metadata={};units=[];address=0
        for i,rid in enumerate(wanted):
            roots=[dict(original_address='0x%08x'%(address+j),size=1) for j in range(8 if i<77 else 7)];address+=len(roots)
            metadata[rid]=dict(plan=dict(roots=roots,counts=dict(code_bytes=219493 if i==0 else 0,fields=7065 if i==0 else 0)),assessment=dict(metadata_candidate=True),contracts=[])
            units.append(dict(recipe_id=rid,recipe_index=i,source='authored-%03d.cpp'%i,object='authored-%03d.obj'%i,source_sha256='s',object_sha256='o',recipe={}))
        paths={k:str(root/(k+'.json')) for k in set(v3.groups.INPUT_PINS)|{'metadata_observation','metadata_details'}}
        Path(paths['manifest']).write_text(json.dumps(dict(units=units)))
        Path(paths['metadata_observation']).write_text(json.dumps(dict(candidate_recipe_ids=wanted,metadata_candidate_roots=1372)))
        inputs=root/'inputs.json';inputs.write_text(json.dumps(paths));review=root/'review.json';review.write_text('{}')
        args=argparse.Namespace(allow_production=True,policy=root/v3.OWNED[2],policy_sha256='c'*64,review=review,review_sha256='c'*64,
            inputs=inputs,reference=root/'never-read-reference',out=root/'build/rebuild/output')
        def collect(original,source,item,providers,observed,activity):
            activity.update(source_hash_attempted=True,native_object_access_attempted=True,native_object_bytes_read=1)
            observed[original]='o';cert=dict(roots=item['plan']['roots'],groups=[])
            return b'authored',cert
        def project(raw,original,item,providers,cert,stage,recovered):
            payload=tiny('_authored_'+original.stem,payload=b'\xc3');stage.write_bytes(payload)
            return payload,{},dict(authored=True),{}
        def stable(observed,*unused):
            if late_mutation and len(observed)>190:raise ValueError('late source mutation')
        failure=ValueError('recovery fault' if recovery else 'archive fault')
        with patch.object(v3,'ROOT',root),patch.object(v3,'sha',return_value='c'*64),patch.object(v3.projection,'stable',side_effect=stable),\
             patch.object(v3.projection,'loaded_producers'),patch.object(v3,'phase_gate',return_value=sorted(wanted)),\
             patch.object(v3,'box_basis',return_value=({},{})),patch.object(v3.groups,'load_saved_metadata',return_value=(metadata,{},{})),\
             patch.object(v3,'tested_box_equal'),patch.object(v3.projection,'collect_recipe',side_effect=collect),\
             patch.object(v3.projection,'project_recipe',side_effect=project),patch.object(v3.bulk,'compare_functions',return_value=[]),\
             patch('compare.Pe',return_value=SimpleNamespace()),patch('build_and_match.image_ok',return_value=(True,{})),\
             patch.object(v3.projection,'recover_and_verify_archive',side_effect=failure):
            if recovery:receipt=v3.run(args)
            else:
                with patch.object(v3.bulk,'write_shard',side_effect=failure):receipt=v3.run(args)
        with gzip.open(args.out/'certificates.jsonl.gz','rt') as stream:detail=[json.loads(line) for line in stream]
        self.assertEqual(len(detail),185);self.assertEqual(sum(len(row['certificate']['roots']) for row in detail),1372)
        self.assertEqual(receipt['status'],'error');self.assertTrue(receipt['emission_may_have_partial_outputs'])
        self.assertEqual(receipt['completed_roots'],1372);self.assertIn(str(failure),receipt['error'])
        self.assertIn('certificates.jsonl.gz',receipt['artifacts']);self.assertFalse(receipt['native_conformance_verified'])
        return receipt

    def test_archive_failure_preserves_completed_gzip_and_partial_state(self):
        with tempfile.TemporaryDirectory() as d:receipt=self.orchestration_failure(d)
        self.assertTrue(receipt['input_stability_verified'])

    def test_recovery_failure_and_final_stale_input_are_both_preserved(self):
        with tempfile.TemporaryDirectory() as d:receipt=self.orchestration_failure(d,recovery=True,late_mutation=True)
        self.assertFalse(receipt['input_stability_verified']);self.assertIn('late source mutation',receipt['final_stability_error'])


if __name__=='__main__':unittest.main()
