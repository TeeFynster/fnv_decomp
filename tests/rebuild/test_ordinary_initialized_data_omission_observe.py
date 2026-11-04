"""Authored finite-wrapper lineage, scope and publication tests only."""
import copy
import gzip
import json
from pathlib import Path
import sys
import tempfile
import time
import unittest
from unittest.mock import patch

ROOT=Path(__file__).resolve().parents[2]
sys.path[:0]=[str(ROOT/'tools/rebuild'),str(ROOT/'tests/rebuild')]
import ordinary_initialized_data_omission_observe as driver
from test_ordinary_initialized_data_omission import context


def group():
    raw,contract,certificate,sections=context(incoming=True)
    row=dict(event='SINGLE_ROOT_OBSERVATION',recipe_id='authored',requested_roots=contract['roots'],
             contract=contract,certificate=certificate)
    return raw,[dict(lane=1,ordinal=2,row=row,sections=sections)]


def review():
    return dict(schema_version=1,kind='ordinary-initialized-data-omission-observation-review-v1',approved=True,
        independent_source_schema_review_pass=True,root_authorized=True,reviewer='authored independent reviewer',
        central_observation_independently_accepted=True,typed_witness_independently_accepted=True,
        witness_source_review_sha256=driver.WITNESS_REVIEW_SHA,central_receipt_sha256=driver.CENTRAL_SHA,
        census_sha256=driver.CENSUS_SHA,allow_native_tools=False,allow_emission=False,
        source_sha256={name:'a'*64 for name in driver.OWNED},producer_sha256=driver.PINS)


def central_fixture(directory):
    raw,contexts=group(); template=contexts[0]['row']; rows=[];selected=[];summaries=[]
    for i in range(303):
        row=copy.deepcopy(template);row['recipe_id']='authored-%02d'%(i%26)
        rows.append(row); identity=driver.digest(row)
        summaries.append(dict(lane=1,lane_record_ordinal=i+1,record_sha256=identity))
        if i<79:
            selected.append(dict(lane=1,ordinal=i+1,event=row['event'],recipe_id=row['recipe_id'],
                requested_roots=row['requested_roots'],record_sha256=identity,
                certificate_sha256=driver.digest(row['certificate']),contract_identity_sha256=driver.digest(row['contract']),
                candidates=[dict(section=4)]))
        row['certificate_sha256']=driver.digest(row['certificate'])
        row['contract_identity_sha256']=driver.digest(row['contract']);row['provenance']=row['contract']['provenance']
    # Bind final rows, including their declared hashes, after constructing them.
    for i,row in enumerate(rows):
        summaries[i]['record_sha256']=driver.digest(row)
        if i<79:selected[i]['record_sha256']=driver.digest(row)
    base=Path(directory);(base/'lanes').mkdir();path=base/'lanes/code-lane-01.jsonl.gz'
    with gzip.open(path,'wt') as out:
        for row in rows:out.write(json.dumps(row)+'\n')
    central=dict(policy_id='central-ordinary-root-views-v1',status='metadata-only',input_stability=True,
        optional_function_index_present=False,inputs=dict(driver.inventory.EXPECTED,imports=driver.finite.IMPORT_PIN),
        collector_sha256=driver.PINS['tools/rebuild/centralordinary_root_collect.py'],
        finite_helper_sha256=driver.PINS['tools/rebuild/scalableordinary_root_collect.py'],
        ordinary_observer_sha256=driver.omission.ORDINARY_PIN,parser_sha256=driver.omission.PARSER_PIN,
        observations=summaries,lane_artifacts={'1':dict(path=path.name,sha256=driver.file_hash(path),bytes=path.stat().st_size,records=303)})
    census=dict(records_read=303,selected_records=79,singleton_records=53,union_records=26,
                actual_omission_witness_performed=False,rows=selected)
    return base,central,census


class FiniteOmissionWrapperTests(unittest.TestCase):
    def test_cached_raw_group_produces_real_typed_witness_without_composer(self):
        raw,contexts=group();result=driver.observe_group(raw,contexts)
        self.assertEqual(len(result),1);self.assertTrue(result[0]['witness']['witness_complete'])
        self.assertEqual(result[0]['witness_sha256'],driver.digest(result[0]['witness']))
        self.assertNotIn('composition',result[0])

    def test_optional_composer_receives_same_raw_and_original_identity(self):
        raw,contexts=group();calls=[]
        def compose(seen,contract,base,witnesses):
            calls.append((seen,contract,base,witnesses));return dict(status='authored-no-provider',provider_selected=False)
        result=driver.observe_group(raw,contexts,compose)
        self.assertIs(calls[0][0],raw);self.assertIs(calls[0][1],contexts[0]['row']['contract'])
        self.assertIs(calls[0][2],contexts[0]['row']['certificate']);self.assertEqual(len(calls[0][3]),1)
        self.assertEqual(result[0]['composition_sha256'],driver.digest(result[0]['composition']))

    def test_bad_object_or_certificate_aborts_group(self):
        raw,contexts=group()
        with self.assertRaises(ValueError):driver.observe_group(raw+b'changed',contexts)
        contexts[0]['row']['certificate']['blockers']=[]
        with self.assertRaises(ValueError):driver.observe_group(raw,contexts)

    def test_exact_operational_review_and_typed_source_acceptance(self):
        accepted=review();typed=dict(status='accepted-typed-witness-only',source_sha256={'tools/rebuild/ordinary_initialized_data_omission.py':driver.WITNESS_SHA})
        with patch.object(driver,'observe',side_effect=lambda p,h,o:Path(p)),patch.object(driver,'load',side_effect=[accepted,typed]):
            self.assertEqual(driver.review_gate(Path('authored'),'b'*64,{}),accepted)
        for field,value in [('root_authorized',False),('allow_emission',True),('allow_native_tools',True),
                            ('census_sha256','f'*64),('typed_witness_independently_accepted',False)]:
            bad=copy.deepcopy(accepted);bad[field]=value
            with self.subTest(field=field),patch.object(driver,'observe',side_effect=lambda p,h,o:Path(p)),patch.object(driver,'load',return_value=bad):
                with self.assertRaises(ValueError):driver.review_gate(Path('authored'),'b'*64,{})

    def test_unaccepted_optional_composer_is_not_operational_fallback(self):
        bad=review();bad['composer_sha256']='c'*64
        typed=dict(status='accepted-typed-witness-only',source_sha256={'tools/rebuild/ordinary_initialized_data_omission.py':driver.WITNESS_SHA})
        with patch.object(driver,'observe',side_effect=lambda p,h,o:Path(p)),patch.object(driver,'load',side_effect=[bad,typed]):
            with self.assertRaises(ValueError):driver.review_gate(Path('authored'),'b'*64,{})

    def test_303_metadata_records_are_bounded_and_79_exact_views_selected(self):
        with tempfile.TemporaryDirectory() as td:
            base,central,census=central_fixture(td)
            result=driver.cached_contexts(central,census,base,{})
            self.assertEqual(len(result),26);self.assertEqual(sum(map(len,result.values())),79)

    def test_missing_or_changed_census_record_cannot_borrow_other_view(self):
        with tempfile.TemporaryDirectory() as td:
            base,central,census=central_fixture(td);census['rows'][0]['certificate_sha256']='f'*64
            with self.assertRaises(ValueError):driver.cached_contexts(central,census,base,{})

    def test_foreign_lane_path_is_not_opened(self):
        with tempfile.TemporaryDirectory() as td:
            base,central,census=central_fixture(td);central['lane_artifacts']['1']['path']='../foreign.gz'
            with self.assertRaises(ValueError):driver.cached_contexts(central,census,base,{})

    def test_terminal_receipt_is_exclusive_and_postpublication_drift_retracts_it(self):
        with tempfile.TemporaryDirectory() as td:
            out=Path(td)
            with patch.object(driver,'stable'),patch.object(driver,'budget'):
                driver.publish_receipt(out,dict(status='authored'),{},time.monotonic())
            self.assertTrue((out/'receipt.json').exists())
        with tempfile.TemporaryDirectory() as td:
            out=Path(td);calls=[]
            def stability(_):
                calls.append(1)
                if len(calls)==3:raise ValueError('authored postpublication drift')
            with patch.object(driver,'stable',side_effect=stability),patch.object(driver,'budget'):
                with self.assertRaises(ValueError):driver.publish_receipt(out,dict(status='authored'),{},time.monotonic())
            self.assertFalse((out/'receipt.json').exists());self.assertTrue((out/'receipt.pending.json').exists())

    def test_repeated_terminal_name_is_not_overwritten(self):
        with tempfile.TemporaryDirectory() as td:
            out=Path(td);(out/'receipt.json').write_text('original terminal identity')
            with patch.object(driver,'stable'),patch.object(driver,'budget'):
                with self.assertRaises(FileExistsError):driver.publish_receipt(out,dict(status='new'),{},time.monotonic())
            self.assertEqual((out/'receipt.json').read_text(),'original terminal identity')

    def test_before_and_after_source_stability_is_required(self):
        with tempfile.TemporaryDirectory() as td:
            path=Path(td)/'authored';path.write_text('original');observations={}
            driver.observe(path,driver.file_hash(path),observations);path.write_text('changed')
            with self.assertRaises(ValueError):driver.stable(observations)


if __name__=='__main__':unittest.main()
