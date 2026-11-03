"""Offline operational-bridge tests using authored synthetic COFF only."""
import argparse
import copy
import json
from pathlib import Path
import sys
import tempfile
import unittest
from types import SimpleNamespace
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[2] / 'tools/rebuild'))
import union_reference_projection_v2 as op
from test_union_reference_groups_v2 import fixture


class OperationalUnionTests(unittest.TestCase):
    def gate_fixture(self, directory, profile='box2089', operation='collect'):
        source = {'authored-source': 'a' * 64}
        policy = dict(producer_sha256={}, box2089=dict(original_addresses=['0x00db0920', '0x00db0960', '0x00db09b0']))
        candidates = [op.BOX] + ['authored-%04d' % i for i in range(184)]
        review = dict(schema_version=1, kind='union-reference-operational-phase-review-v2', status='approved',
            reviewer='authored-test-only', root_authorized=True, allowed_operations=[operation + '-' + profile],
            sources=source, producer_sha256={}, metadata_observation_sha256=op.OBSERVATION_PIN,
            metadata_details_sha256=op.DETAIL_PIN, allow_native_tools=False, allow_executable_link=False,
            recipe_ids=[op.BOX] if profile == 'box2089' else sorted(candidates))
        path = Path(directory) / 'review.json'; path.write_text(json.dumps(review))
        args = argparse.Namespace(review=path, review_sha256=op.sha(path), operation=operation, profile=profile,
            authorize_coff_read=True, authorize_private_emission=operation == 'project',
            mechanism_review=None, mechanism_review_sha256=None)
        return args, policy, source, dict(candidate_recipe_ids=candidates), review

    def synthetic(self, directory, mixed=True):
        raw, contracts, plan, providers = fixture(mixed=mixed)
        original = Path(directory) / 'authored.obj'; original.write_bytes(raw)
        source = Path(directory) / 'authored.cpp'; source.write_text('// Original synthetic test input.\n')
        plan['source_sha256'] = op.sha(source)
        # Source identity is not a COFF payload fact; update the authored contract.
        for contract in contracts: contract['source_sha256'] = plan['source_sha256']
        return raw, original, source, dict(plan=plan, contracts=contracts, provenance=dict(kind='authored-test')), providers

    def test_no_read_opt_in_rejects_before_policy_or_object_access(self):
        with patch.object(op, 'sha', side_effect=AssertionError('file accessed')):
            with self.assertRaisesRegex(ValueError, 'explicit root'):
                op.run(argparse.Namespace(authorize_coff_read=False))

    def test_gate_accepts_exact_box_only(self):
        with tempfile.TemporaryDirectory() as d:
            args, policy, sources, observation, _ = self.gate_fixture(d)
            self.assertEqual(op.phase_gate(args, policy, sources, observation), [op.BOX])

    def test_projection_requires_separate_emission_opt_in(self):
        with tempfile.TemporaryDirectory() as d:
            args, policy, sources, observation, _ = self.gate_fixture(d, operation='project')
            args.authorize_private_emission = False
            with self.assertRaisesRegex(ValueError, 'private projection'):
                op.phase_gate(args, policy, sources, observation)

    def test_stale_review_rejected(self):
        with tempfile.TemporaryDirectory() as d:
            args, policy, sources, observation, _ = self.gate_fixture(d)
            args.review.write_text('{}')
            with self.assertRaisesRegex(ValueError, 'stale'):
                op.phase_gate(args, policy, sources, observation)

    def test_wrong_profile_root_scope_and_source_rejected(self):
        with tempfile.TemporaryDirectory() as d:
            args, policy, sources, observation, review = self.gate_fixture(d)
            review['recipe_ids'].append('unrelated'); args.review.write_text(json.dumps(review)); args.review_sha256=op.sha(args.review)
            with self.assertRaisesRegex(ValueError, 'exact whole'):
                op.phase_gate(args, policy, sources, observation)
            review['recipe_ids']=[op.BOX]; review['sources']={}; args.review.write_text(json.dumps(review)); args.review_sha256=op.sha(args.review)
            with self.assertRaisesRegex(ValueError, 'unapproved'):
                op.phase_gate(args, policy, sources, observation)

    def test_all185_is_excluded_until_actual_artifact_bound_source_delta(self):
        with tempfile.TemporaryDirectory() as d:
            args, policy, sources, observation, review = self.gate_fixture(d, profile='all185')
            with self.assertRaisesRegex(ValueError, 'artifact-bound source delta'):
                op.phase_gate(args, policy, sources, observation)
            # No review booleans can bypass an unsupported operation.
            args.mechanism_review = Path(d)/'nonexistent.json'
            args.mechanism_review_sha256 = 'a'*64
            with self.assertRaisesRegex(ValueError, 'artifact-bound source delta'):
                op.phase_gate(args, policy, sources, observation)

    def test_current_optional_index_absence_and_mutation(self):
        with tempfile.TemporaryDirectory() as d:
            root=Path(d); (root/'build').mkdir(); protected=root/'producer.py'; protected.write_text('original')
            observations={protected:op.sha(protected)}; op.stable(observations,root)
            (root/'build/function_index.json').write_text('{}')
            with self.assertRaisesRegex(ValueError,'index'): op.stable(observations,root)
            (root/'build/function_index.json').unlink(); protected.write_text('changed')
            with self.assertRaisesRegex(ValueError,'changed'): op.stable(observations,root)

    def test_loaded_dependency_cannot_hide_behind_correct_expected_file(self):
        policy=dict(producer_sha256={'tools/rebuild/coff_rewrite.py':'authored-hash'})
        with patch.dict(sys.modules,coff_rewrite=SimpleNamespace(__file__='unbound/coff_rewrite.py')):
            with self.assertRaisesRegex(ValueError,'loaded producer'): op.loaded_producers(policy)

    def test_exact_native_collection_has_no_emission_or_pe(self):
        with tempfile.TemporaryDirectory() as d:
            raw, original, source, metadata, providers=self.synthetic(d)
            activity={}; observations={}
            with patch.object(op.groups,'serialize_union_v2',side_effect=AssertionError('emission')):
                actual,cert=op.collect_recipe(original,source,metadata,providers,observations,activity)
            self.assertEqual(actual,raw); self.assertEqual(activity['native_object_bytes_read'],len(raw))
            self.assertTrue(activity['source_hash_attempted']); self.assertTrue(activity['native_object_access_attempted'])
            self.assertFalse(cert['runtime_eligible'])

    def test_collection_failure_keeps_read_attempt_and_bytes(self):
        with tempfile.TemporaryDirectory() as d:
            raw, original, source, metadata, providers=self.synthetic(d); activity={}
            with patch.object(op.groups,'certify_union',side_effect=ValueError('authored rejection')):
                with self.assertRaisesRegex(ValueError,'authored rejection'):
                    op.collect_recipe(original,source,metadata,providers,{},activity)
            self.assertEqual(activity['native_object_bytes_read'],len(raw))
            self.assertTrue(activity['native_object_access_attempted'])

    def test_stale_source_or_object_rejected_before_certification(self):
        with tempfile.TemporaryDirectory() as d:
            raw, original, source, metadata, providers=self.synthetic(d); source.write_text('changed'); activity={}
            with self.assertRaisesRegex(ValueError,'source differs'):
                op.collect_recipe(original,source,metadata,providers,{},activity)
            self.assertTrue(activity['source_hash_attempted']); self.assertNotIn('native_object_access_attempted',activity)
            metadata['plan']['source_sha256']=op.sha(source); original.write_bytes(raw+b'changed'); activity={}
            with self.assertRaisesRegex(ValueError,'native object differs'):
                op.collect_recipe(original,source,metadata,providers,{},activity)
            self.assertTrue(activity['native_object_access_attempted']); self.assertNotIn('native_object_bytes_read',activity)

    def test_object_resource_ceiling_before_payload_read(self):
        with tempfile.TemporaryDirectory() as d:
            raw, original, source, metadata, providers=self.synthetic(d)
            with original.open('wb') as target: target.truncate(16*1024*1024+1)
            with self.assertRaisesRegex(ValueError,'bounded reader'):
                op.collect_recipe(original,source,metadata,providers,{})

    def test_projection_independent_stage_and_streamed_recovery(self):
        with tempfile.TemporaryDirectory() as d:
            root=Path(d); raw,original,source,metadata,providers=self.synthetic(d)
            _,cert=op.collect_recipe(original,source,metadata,providers,{})
            stage=root/'member.stage'; recovered=root/'member.obj.recovered'
            output,projection,independent,expected=op.project_recipe(raw,original,metadata,providers,cert,stage,recovered)
            self.assertTrue(independent['complete_metadata_and_mapping_match'])
            spool=op.bulk.Spool(root/'spool',root/'members')
            member=spool.append('member.obj',output,0,projection); spool.close()
            archive=root/'authored.lib'; op.bulk.write_shard(root/'spool',[member],archive)
            read_bytes=Path.read_bytes
            def bounded_read(path):
                if path == archive: raise AssertionError('whole-shard read')
                return read_bytes(path)  # Only bounded synthetic COFF objects.
            with patch.object(Path,'read_bytes',bounded_read):
                result=op.recover_and_verify_archive(archive,[member],{'member.obj':original},
                    {'member.obj':cert},{'member.obj':expected},root)
            self.assertEqual(result['members'],1); self.assertEqual(recovered.read_bytes(),output)
            self.assertTrue(result['independent_recovered_members'][0]['complete_metadata_and_mapping_match'])

    def test_independent_stage_map_or_payload_drift_rejected(self):
        with tempfile.TemporaryDirectory() as d:
            root=Path(d);raw,original,source,metadata,providers=self.synthetic(d)
            _,cert=op.collect_recipe(original,source,metadata,providers,{})
            output,projection,_,expected=op.project_recipe(raw,original,metadata,providers,cert,root/'stage',root/'recover')
            altered=copy.deepcopy(expected); altered['mapping']['symbol_map'][0]=999
            with self.assertRaises((ValueError,KeyError)):
                op.entry.independent_projection(original,root/'stage',cert,altered)
            bad=bytearray(output); bad[-1]^=1; (root/'stage').write_bytes(bad)
            with self.assertRaises(ValueError): op.entry.independent_projection(original,root/'stage',cert,expected)

    def test_exclusive_stage_rejects_overwrite(self):
        with tempfile.TemporaryDirectory() as d:
            root=Path(d);raw,original,source,metadata,providers=self.synthetic(d)
            _,cert=op.collect_recipe(original,source,metadata,providers,{})
            stage=root/'stage'; stage.write_bytes(b'preserve')
            with self.assertRaises(FileExistsError): op.project_recipe(raw,original,metadata,providers,cert,stage,root/'recover')
            self.assertEqual(stage.read_bytes(),b'preserve')

    def test_full_coverage_preserves_all_baseline_states(self):
        with tempfile.TemporaryDirectory() as d:
            root=Path(d); rows=[(i,dict(original_address='0x%08x'%i,status='EMITTED' if i<12946 else 'HISTORICAL_BLOCKED' if i<64744 else 'BLOCKED_UNION',physical_identity={})) for i in range(68657)]
            with patch.object(op.groups,'saved_records',return_value=iter(rows)):
                counts=op.write_coverage(root/'coverage.gz',None,{'0x000100e8'},{'0x000100e8'})
            self.assertEqual(sum(counts.values()),68657); self.assertEqual(counts['UPSTREAM_EMITTED_UNCHANGED'],12946)
            self.assertEqual(counts['UPSTREAM_HISTORICAL_BLOCKED'],51798);self.assertEqual(counts['V2_NEWLY_PROJECTED'],1)


if __name__=='__main__': unittest.main()
