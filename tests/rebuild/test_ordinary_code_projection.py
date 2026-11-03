"""Authored synthetic COFF and operational lineage/publication checks."""
import copy
import hashlib
from pathlib import Path
import sys
import unittest
import json
import gzip
import tempfile
import time
from unittest.mock import patch
from types import SimpleNamespace
ROOT=Path(__file__).resolve().parents[2]
sys.path[:0]=[str(ROOT/'tools/rebuild'),str(ROOT/'tests/rebuild')]
import ordinary_code_projection as projection
import scalableordinary_root_collect as collector
import root_code_closure as ordinary
import coff_code_archive as coff
import runtime_code_pool as pool
from test_scalableordinary_root_collect import fixture


def inputs(*,field=False,all_roots=False):
    raw,unit,proof,requested,_,_,bindings=fixture(field=field)
    requested=requested if all_roots else requested[:1]
    contract=collector.build_contract(unit,proof,requested,bindings,{},dict(object_sha256=unit['object_sha256'],source_sha256=unit['source_sha256'],recipe_id=unit['recipe_id'],recipe_index=unit['recipe_index']))
    certificate=ordinary.assess_object(coff.parse(raw),contract)
    return raw,contract,certificate,requested


class OrdinaryNoRelocProjectionTests(unittest.TestCase):
    def test_only_requested_root_exported_with_original_physical_identity(self):
        raw,contract,cert,roots=inputs()
        self.assertTrue(cert['closure_observed'])
        projected,receipt=projection.project_member(raw,contract,cert,roots)
        parsed=coff.parse(projected)
        definitions=[s for s in parsed['symbols'].values() if s['storage']==2 and s['section']>0]
        expected=pool.canonical(dict(recipe_id='authored',object_sha256=hashlib.sha256(raw).hexdigest(),symbol_index=2))
        self.assertEqual([s['name'] for s in definitions],[expected])
        self.assertEqual([s['value'] for s in definitions],[0])
        self.assertEqual(parsed['sections'][definitions[0]['section']]['payload'],bytes(16))
        self.assertFalse(any(s['storage']==2 and s['section']==0 for s in parsed['symbols'].values()))
        self.assertFalse(any(s['name'] in ('_alpha','_beta') for s in parsed['symbols'].values()))
        self.assertIsInstance(receipt,dict)

    def test_no_retained_relocations(self):
        raw,c,cert,roots=inputs()
        projected,_=projection.project_member(raw,c,cert,roots)
        self.assertTrue(all(not s['relocs'] for s in coff.parse(projected)['sections'].values()))

    def test_union_has_exact_requested_export_set(self):
        raw,c,cert,roots=inputs(all_roots=True)
        projected,_=projection.project_member(raw,c,cert,roots)
        names={s['name'] for s in coff.parse(projected)['symbols'].values() if s['storage']==2 and s['section']>0}
        expected={pool.canonical(dict(recipe_id='authored',object_sha256=hashlib.sha256(raw).hexdigest(),symbol_index=r['symbol_index'])) for r in roots}
        self.assertEqual(names,expected)

    def test_positive_closure_does_not_authorize_relocations_or_crt_conversion(self):
        raw,c,cert,roots=inputs(field=True)
        self.assertTrue(cert['closure_observed'])
        self.assertTrue(c['fields'])
        with self.assertRaises(ValueError):projection.project_member(raw,c,cert,roots)

    def test_stale_object_byte_or_provenance_hash_blocks(self):
        raw,c,cert,roots=inputs()
        for bad in (raw+b'changed',bytes([raw[0]^1])+raw[1:]):
            with self.assertRaises(ValueError):projection.project_member(bad,c,cert,roots)
        changed=copy.deepcopy(c);changed['provenance']['object_sha256']='f'*64
        with self.assertRaises(ValueError):projection.project_member(raw,changed,cert,roots)

    def test_root_physical_index_cannot_use_post_namespace_or_other_owner(self):
        raw,c,cert,roots=inputs()
        for key,value in [('symbol_index',5),('section',2),('value',1),('size',8),('symbol','_beta'),('object_sha256','f'*64),('recipe_id','other')]:
            bad=copy.deepcopy(roots);bad[0][key]=value
            with self.subTest(key=key),self.assertRaises(ValueError):projection.project_member(raw,c,cert,bad)

    def test_subset_certificate_cannot_export_extra_root(self):
        raw,c,cert,roots=inputs();all_roots=fixture()[3]
        with self.assertRaises(ValueError):projection.project_member(raw,c,cert,all_roots)
        with self.assertRaises(ValueError):projection.project_member(raw,c,cert,[])
        with self.assertRaises(ValueError):projection.project_member(raw,c,cert,[roots[0],roots[0]])

    def test_unreplayed_certificate_mutation_blocks(self):
        raw,c,cert,roots=inputs()
        changed=copy.deepcopy(cert);changed['roots'][0]['symbol_index']=5
        with self.assertRaises(ValueError):projection.project_member(raw,c,changed,roots)
        changed=copy.deepcopy(cert);changed['closure_observed']=False
        with self.assertRaises(ValueError):projection.project_member(raw,c,changed,roots)

    def test_missing_field_or_unknown_role_not_hidden_by_old_positive_certificate(self):
        raw,c,cert,roots=inputs()
        changed=copy.deepcopy(c);changed['missing_fields']=[dict(original_field_va='0x00500004')]
        with self.assertRaises(ValueError):projection.project_member(raw,changed,cert,roots)
        changed=copy.deepcopy(c);changed['fields']=[dict(role='unknown-role')]
        with self.assertRaises(ValueError):projection.project_member(raw,changed,cert,roots)

    def test_request_strict_schema_and_full_provenance(self):
        raw,c,cert,roots=inputs()
        for key,value in [('recipe_index',True),('symbol_index',True),('section',True),('size',True),('source_sha256','f'*64),('recipe_index',1),('original_address','0x0050ffff'),('approved',True)]:
            bad=copy.deepcopy(roots);bad[0][key]=value
            with self.subTest(key=key,value=value),self.assertRaises(ValueError):projection.project_member(raw,c,cert,bad)

    def test_live_safeseh_union_remains_blocked(self):
        raw,unit,proof,roots,_,_,bindings=fixture(safeseh=True)
        c=collector.build_contract(unit,proof,roots,bindings,{},dict(object_sha256=unit['object_sha256'],source_sha256=unit['source_sha256'],recipe_id=unit['recipe_id'],recipe_index=unit['recipe_index']))
        cert=ordinary.assess_object(coff.parse(raw),c)
        self.assertFalse(cert['closure_observed'])
        with self.assertRaises(ValueError):projection.project_member(raw,c,cert,roots)

    def test_mutated_certificate_capability_or_blocker_state_rejected(self):
        raw,c,cert,roots=inputs()
        for key,value in [('blockers',[dict(code='REVIEW_REQUIRED',evidence=1)]),('root_closure_candidate',False),('graph_observation_complete',False),('runtime_eligible',True),('provider_selected',True)]:
            changed=copy.deepcopy(cert);changed[key]=value
            with self.subTest(key=key),self.assertRaises(ValueError):projection.project_member(raw,c,changed,roots)

class OperationalEvidenceTests(unittest.TestCase):
    def central_fixture(self, folder):
        raw,unit,proof,roots,_,_,bindings=fixture()
        import centralordinary_root_collect as central
        record=list(central.observe_recipe(raw,unit,proof,roots[:1],bindings,{},
            dict(object_sha256=unit['object_sha256'],source_sha256=unit['source_sha256'],recipe_id=unit['recipe_id'],recipe_index=0)))[-1]
        path=folder/'code-lane-01.jsonl.gz'
        with gzip.open(path,'wt') as f:f.write(json.dumps(record)+'\n')
        summary=dict(lane=1,lane_record_ordinal=1,record_sha256=projection.digest(record),
            event=record['event'],roots=[r['original_address'] for r in record['requested_roots']])
        receipt=dict(schema_version=1,policy_id='central-ordinary-root-views-v1',status='metadata-only',input_stability=True,
            optional_function_index_present=False,inputs=dict(projection.inventory.EXPECTED,imports=collector.IMPORT_PIN),
            collector_sha256=projection.PINS['tools/rebuild/centralordinary_root_collect.py'],ordinary_observer_sha256=collector.ORDINARY_PIN,
            finite_helper_sha256=projection.PINS['tools/rebuild/scalableordinary_root_collect.py'],parser_sha256=collector.PARSER_PIN,
            lane_artifacts={'1':dict(path=path.name,sha256=projection.file_hash(path),bytes=path.stat().st_size,records=1)},
            observations=[summary],summary=dict(roots=1))
        return receipt,record,path

    def test_real_central_schema_fixture_and_exact_record_authentication(self):
        with tempfile.TemporaryDirectory() as td:
            p=Path(td);receipt,row,_=self.central_fixture(p)
            records=projection.central_records(receipt,p,{})
            self.assertEqual(records['0x00500000']['row'],row)
            bad=copy.deepcopy(receipt);bad['observations'][0]['record_sha256']='f'*64
            with self.assertRaises(ValueError):projection.central_records(bad,p,{})
            bad=copy.deepcopy(receipt);bad['summary']['roots']=2
            with self.assertRaises(ValueError):projection.central_records(bad,p,{})

    def test_central_lane_hash_path_and_duplicate_locator_cannot_be_guessed(self):
        with tempfile.TemporaryDirectory() as td:
            p=Path(td);receipt,row,path=self.central_fixture(p)
            for mutate in ('hash','path','duplicate'):
                bad=copy.deepcopy(receipt)
                if mutate=='hash':bad['lane_artifacts']['1']['sha256']='f'*64
                elif mutate=='path':bad['lane_artifacts']['1']['path']='../elsewhere.gz'
                else:bad['observations'].append(bad['observations'][0])
                with self.subTest(mutate=mutate),self.assertRaises(ValueError):projection.central_records(bad,p,{})

    def test_atomic_receipt_postwrite_drift_cannot_leave_success(self):
        with tempfile.TemporaryDirectory() as td:
            p=Path(td);calls=[]
            def check(_):
                calls.append(1)
                if len(calls)==3:raise ValueError('injected post-publication drift')
            with patch.object(projection,'stable',side_effect=check),patch.object(projection,'budget',return_value={}):
                with self.assertRaises(ValueError):projection.publish_receipt(p,dict(status='completed'),{},time.monotonic())
            self.assertFalse((p/'receipt.json').exists());self.assertTrue((p/'receipt.pending.json').exists())

    def test_exclusive_publication_never_replaces_or_deletes_existing_receipt(self):
        with tempfile.TemporaryDirectory() as td:
            p=Path(td);old=p/'receipt.json';old.write_text('preexisting')
            with patch.object(projection,'stable'),patch.object(projection,'budget',return_value={}):
                with self.assertRaises(FileExistsError):projection.publish_receipt(p,dict(status='completed'),{},time.monotonic())
            self.assertEqual(old.read_text(),'preexisting')

    def test_terminal_journal_failure_prevents_receipt_publication(self):
        with tempfile.TemporaryDirectory() as td:
            p=Path(td);journal=p/'progress.jsonl'
            with journal.open('w') as stream,patch.object(projection,'publish_receipt') as publish:
                def broken(*args,**kwargs):raise OSError('injected journal fsync failure')
                with self.assertRaises(OSError):projection.finalize_success(p,dict(emitted=1,blocked=0),{},time.monotonic(),stream,broken)
                publish.assert_not_called()
            self.assertFalse((p/'receipt.json').exists())

    def test_incomplete_baseline_and_competing_old_owner_are_not_hidden(self):
        with tempfile.TemporaryDirectory() as td:
            p=Path(td);src=p/'old.gz'
            with gzip.open(src,'wt') as f:f.write(json.dumps(dict(original_address='0x00500000',status='EMITTED'))+'\n')
            with self.assertRaises(ValueError):projection.write_coverage(p/'out1.gz',src,{'0x00500000'},{'0x00500000'})
            with self.assertRaises(ValueError):projection.write_coverage(p/'out2.gz',src,set(),set())

    def test_prior_union_candidate_cannot_duplicate_supplemental_export(self):
        with tempfile.TemporaryDirectory() as td:
            p=Path(td);src=p/'old.gz';root=fixture()[3][0]
            row=dict(original_address=root['original_address'],status='BLOCKED_UNION',
                physical_identity={k:root[k] for k in ('recipe_id','object_sha256','symbol_index')},
                selected_native={k:root[k] for k in projection.NATIVE_KEYS})
            with gzip.open(src,'wt') as f:f.write(json.dumps(row)+'\n')
            with self.assertRaisesRegex(ValueError,'HISTORICAL_BLOCKED'):projection.require_historical_scope(src,{root['original_address']:root})
            with self.assertRaisesRegex(ValueError,'prior candidate'):projection.write_coverage(p/'out.gz',src,{root['original_address']},{root['original_address']})

    def test_complete_authored_historical_partition_preserves_original_status(self):
        with tempfile.TemporaryDirectory() as td:
            p=Path(td);src=p/'old.gz';root=fixture()[3][0];address=root['original_address']
            with gzip.open(src,'wt') as f:
                for i in range(68657):
                    status='EMITTED' if i<12946 else 'BLOCKED_UNION' if i<16859 else 'HISTORICAL_BLOCKED'
                    row=dict(original_address=address if i==16859 else '0x%08x'%(0x02000000+i),status=status)
                    if i==16859:row.update(physical_identity={k:root[k] for k in ('recipe_id','object_sha256','symbol_index')},selected_native={k:root[k] for k in projection.NATIVE_KEYS})
                    f.write(json.dumps(row)+'\n')
            joined=projection.require_historical_scope(src,{address:root})
            self.assertEqual(joined[address]['status'],'HISTORICAL_BLOCKED')
            counts=projection.write_coverage(p/'out.gz',src,{address},{address})
            self.assertEqual(counts,dict(EMITTED_ORDINARY_NO_RELOCATION=1,NOT_REQUESTED=68656))
            with gzip.open(p/'out.gz','rt') as f:
                row=next(json.loads(line) for line in f if json.loads(line)['original_address']==address)
            self.assertEqual(row['status'],'HISTORICAL_BLOCKED');self.assertTrue(row['baseline_status_preserved'])

    def test_gate_requires_actual_review_and_delegated_authorization_before_inputs(self):
        with tempfile.TemporaryDirectory() as td:
            path=Path(td)/'review.json';projection.save_json(path,dict(schema_version=1,kind='ordinary-code-projection-review-v1',approved=True))
            with self.assertRaises(ValueError):projection.review_gate(path,projection.file_hash(path),'a'*64,'b'*64,{})

    def test_loaded_reference_digest_precedes_probe_success(self):
        raw=b'authored reference fixture';oracle=SimpleNamespace(Pe=lambda path:SimpleNamespace(data=raw))
        with patch.dict(pool.PINS,reference=coff.digest(raw)):
            probe=SimpleNamespace(calls=0)
            def image_ok(pe):probe.calls+=1;return True,[],[]
            self.assertEqual(projection.checked_reference('authored',oracle,image_ok).data,raw)
            self.assertEqual(probe.calls,1)
        with patch.dict(pool.PINS,reference='f'*64),patch.object(projection,'require',wraps=projection.require):
            def forbidden_probe(pe):self.fail('digest mismatch reached weak probe gate')
            with self.assertRaises(ValueError):projection.checked_reference('authored',oracle,forbidden_probe)


if __name__=='__main__':unittest.main()
