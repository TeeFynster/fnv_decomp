"""Original authored metadata/COFF only; no live inputs or native tools."""
import copy
from pathlib import Path
import hashlib
import struct
import sys
import tempfile
import unittest
from unittest.mock import patch
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'tools/rebuild'))
import scalableordinary_root_collect as c
from import_plan import unit_digest
from test_coff_code_archive import section,symbol,aux,object_bytes


def fixture(field=False,safeseh=False):
    text1=bytes(16);text2=bytes(8);directives=b'   /DEFAULTLIB:"LIBCMT" /DEFAULTLIB:"OLDNAMES" '
    secs=[section('.text',text1,0x60501020,[(4,9,20)] if field else []),section('.text',text2,0x60501020),section('.drectve',directives,0x100a00)]
    symbols=[symbol('.text',1,storage=3,auxiliary=aux(16,1 if field else 0,1)),symbol('_alpha',1,typ=32),
        symbol('.text',2,storage=3,auxiliary=aux(8,selection=1)),symbol('_beta',2,typ=32),
        symbol('.drectve',3,storage=3,auxiliary=aux(len(directives),selection=0)),symbol('@feat.00',-1,value=1,storage=3)]
    if field:symbols.append(symbol('_fread',0,typ=32))
    if safeseh:
        secs.append(section('.sxdata',struct.pack('<I',5),0x300200));symbols.append(symbol('.sxdata',4,storage=3,auxiliary=aux(4,selection=0)))
    raw=object_bytes(secs,symbols);h=hashlib.sha256(raw).hexdigest()
    fns=[dict(symbol='_alpha',address='0x00500000',size=16),dict(symbol='_beta',address='0x00500100',size=8)]
    recipe=dict(source='authored.cpp',compiler='sp1',functions=fns)
    unit=dict(recipe_id='authored',recipe_index=0,status='compiled',source='authored.cpp',compiler='sp1',recipe=recipe,source_sha256='b'*64,object_sha256=h)
    pv=dict(recipe_id='authored',recipe_index=0,status='ok',recipe_unit_sha256=unit_digest(recipe),object_sha256=h,source_sha256_recorded='b'*64,
        source_sha256_current='b'*64,verified_functions=[dict(f,section=i+1,value=0,verdict='match') for i,f in enumerate(fns)],eh_sections=[],eh_errors=[])
    selections={};providers={};request=[]
    for i,f in enumerate(fns):
        si=2 if i==0 else 5
        selections[f['address']]=dict(recipe_id='authored',recipe_index=0,symbol=f['symbol'],section=i+1,value=0,size=f['size'],selection_status='CODE_OWNERSHIP_SELECTED',runtime_eligible=False,link_ready=False)
        providers[f['address']]=dict(recipe_id='authored',object_sha256=h,symbol_index=si)
        request.append(dict(original_address=f['address'],recipe_id='authored',recipe_index=0,object_sha256=h,source_sha256='b'*64,symbol=f['symbol'],symbol_index=si,section=i+1,value=0,size=f['size']))
    buckets={}
    if field:
        row=dict(recipe_id='authored',function_va='0x00500000',function_symbol='_alpha',physical_section=1,physical_offset=4,source_field_offset=4,
            original_field_va='0x00500004',coff_relocation=dict(offset=4,symbol_index=9,kind=20,symbol='_fread',symbol_section=0,symbol_value=0,symbol_type=32,symbol_storage=2,addend=0),
            derived_source_symbol_base_va='0x00600000',exact_original_target_va='0x00600000',classification='EXPLICIT_NORMAL_CRT_CONTRACT_CANDIDATE',
            proof_consistency='EXACT_OWN_SOURCE_RESOLUTION',physical_field_overlap_count=1)
        buckets['0x00500000']=dict(fields=[row],missing_fields=[],row_identities=[dict(ordinal=1,sha256=c.digest(row))])
    return raw,unit,pv,request,selections,providers,buckets


def run_group(fx,requested=None,buckets=None):
    raw,unit,pv,req,_,_,bindings=fx
    return c.collect_group(raw,unit,pv,requested or req,bindings if buckets is None else buckets,{},dict(request_sha256='a'*64,object_sha256=unit['object_sha256'],source_sha256=unit['source_sha256']))


class FiniteCollectorTests(unittest.TestCase):
    def test_request_exact_complete_selected_provider_identity(self):
        raw,u,p,rows,sels,providers,b=fixture()
        result=c.validate_request(dict(schema_version=1,kind='fnv-finite-ordinary-root-request',roots=rows),sels,dict(units=[u]),dict(units=[p]),providers)
        self.assertEqual(result,{0:rows})
        for key,value in [('symbol_index',7),('object_sha256','f'*64),('source_sha256','f'*64),('section',2),('size',4),('symbol','_wrong')]:
            bad=copy.deepcopy(rows);bad[0][key]=value
            with self.assertRaises(ValueError):c.validate_request(dict(schema_version=1,kind='fnv-finite-ordinary-root-request',roots=bad),sels,dict(units=[u]),dict(units=[p]),providers)

    def test_request_duplicates_unknown_and_extra_fields_rejected(self):
        _,u,p,rows,sels,providers,_=fixture()
        for bad in ([rows[0],rows[0]],[],[dict(rows[0],original_address='0x0050ffff')],[dict(rows[0],approved=True)],[dict(rows[0],section=True)]):
            with self.assertRaises(ValueError):c.validate_request(dict(schema_version=1,kind='fnv-finite-ordinary-root-request',roots=bad),sels,dict(units=[u]),dict(units=[p]),providers)
        with self.assertRaises(ValueError):c.validate_request(dict(schema_version=True,kind='fnv-finite-ordinary-root-request',roots=rows),sels,dict(units=[u]),dict(units=[p]),providers)

    def test_stale_selected_provider_or_source_proof_not_guessed(self):
        _,u,p,rows,sels,providers,_=fixture();providers['0x00500000']['symbol_index']=5
        with self.assertRaises(ValueError):c.validate_request(dict(schema_version=1,kind='fnv-finite-ordinary-root-request',roots=rows),sels,dict(units=[u]),dict(units=[p]),providers)
        _,u,p,rows,sels,providers,_=fixture();p['source_sha256_current']='f'*64
        with self.assertRaises(ValueError):c.validate_request(dict(schema_version=1,kind='fnv-finite-ordinary-root-request',roots=rows),sels,dict(units=[u]),dict(units=[p]),providers)

    def test_selected_request_provider_agreement_cannot_replace_native_proof(self):
        for key,value in [('section',2),('value',4)]:
            _,u,p,rows,sels,providers,_=fixture();p['verified_functions'][0][key]=value
            with self.assertRaises(ValueError):c.validate_request(dict(schema_version=1,kind='fnv-finite-ordinary-root-request',roots=rows),sels,dict(units=[u]),dict(units=[p]),providers)

    def test_multiple_roots_one_parse_and_one_union_certificate(self):
        fx=fixture();real=c.coff.parse
        with patch.object(c.coff,'parse',wraps=real) as reader:r=run_group(fx)
        self.assertEqual(reader.call_count,1);self.assertTrue(r['closure_observed']);self.assertEqual(len(r['certificate']['roots']),2)
        self.assertEqual(r['certificate']['retained_runtime_section_indices'],[1,2]);self.assertFalse(r['full_serialization_eligible'])

    def test_scope_union_recomputed_not_union_of_drops(self):
        fx=fixture(safeseh=True);one=run_group(fx,fx[3][:1]);union=run_group(fx)
        self.assertTrue(one['closure_observed']);self.assertFalse(union['closure_observed'])
        self.assertIn('LIVE_SAFESEH_HANDLER_REQUIRES_ADAPTER',{b['code'] for b in union['blockers']})
        self.assertNotEqual(one['contract_identity_sha256'],union['contract_identity_sha256'])

    def test_field_identity_addend_and_unresolved_CRT_obligation(self):
        fx=fixture(field=True);r=run_group(fx,fx[3][:1]);self.assertTrue(r['closure_observed'])
        field=r['certificate']['references'][0];self.assertEqual((field['symbol_index'],field['kind'],field['addend_bits']),(9,20,0))
        self.assertEqual(field['role'],'crt-contract');self.assertFalse(r['provider_selected']);self.assertFalse(r['certificate']['namespace_approved'])
        self.assertEqual(r['provenance']['binding_row_references'],fx[6]['0x00500000']['row_identities'])

    def test_missing_fields_and_parent_EH_remain_explicit_blockers(self):
        fx=fixture();fx[6]['0x00500000']=dict(fields=[],missing_fields=[dict(original_field_va='0x00500008')],row_identities=[])
        r=run_group(fx,fx[3][:1]);self.assertIn('ORIGINAL_MISSING_FIELDS',{b['code'] for b in r['blockers']})
        fx=fixture();fx[2]['eh_sections']=[[1,4,False,'0x00500000',[]]];fx[2]['eh_errors']=['unchanged exact diagnostic']
        r=run_group(fx,fx[3][:1]);self.assertIn('PARENT_EH_REQUIRES_CLOSURE_ADAPTER',{b['code'] for b in r['blockers']})
        self.assertEqual(r['unit_EH_evidence']['diagnostics'],['unchanged exact diagnostic'])

    def test_unrelated_EH_notes_are_observations_not_frame_approval(self):
        fx=fixture();fx[2]['eh_sections']=[[1,4,False,'0x00600000',[]]];fx[2]['eh_errors']=['unselected diagnostic']
        r=run_group(fx,fx[3][:1]);self.assertTrue(r['closure_observed']);self.assertEqual(r['unit_EH_evidence']['pieces'],fx[2]['eh_sections'])
        self.assertFalse(r['ABI_verified']);self.assertFalse(r['runtime_eligible'])

    def test_parser_failure_accounts_entire_requested_group(self):
        fx=list(fixture());fx[0]=b'authored unsupported object';fx[1]['object_sha256']=hashlib.sha256(fx[0]).hexdigest()
        for row in fx[3]:row['object_sha256']=fx[1]['object_sha256']
        r=run_group(fx);self.assertEqual(r['status'],'blocked-object-format');self.assertEqual(r['requested_roots'],fx[3]);self.assertFalse(r['closure_observed'])

    def test_changed_object_and_wrong_native_index_fail(self):
        fx=list(fixture());fx[0]+=b'changed'
        with self.assertRaises(ValueError):run_group(fx)
        fx=fixture();bad=copy.deepcopy(fx[3]);bad[0]['symbol_index']=5
        with self.assertRaises(ValueError):run_group(fx,bad)

    def test_omission_fields_all_unit_roots_not_just_selected_bucket(self):
        fx=fixture(field=True);row=copy.deepcopy(fx[6]['0x00500000']['fields'][0]);row['coff_relocation']['symbol_storage']=6
        fx[6]['0x00500100']=dict(fields=[row],missing_fields=[],row_identities=[dict(ordinal=2,sha256=c.digest(row))])
        contract=c.build_contract(fx[1],fx[2],fx[3][:1],fx[6],{},dict(object_sha256=fx[1]['object_sha256']))
        self.assertEqual(contract['omission_field_proofs'],[row]);self.assertEqual(len(contract['provenance']['omission_binding_row_references']),2)

    def test_frozen_producer_hash_and_false_scope_flags(self):
        self.assertEqual(c.file_hash(ROOT/'tools/rebuild/root_code_closure.py'),c.ORDINARY_PIN)
        self.assertEqual(c.file_hash(ROOT/'tools/rebuild/coff_code_archive.py'),c.PARSER_PIN)
        r=run_group(fixture())
        for k in c.FALSE:self.assertIs(r[k],False)
        self.assertNotIn('payload',r['certificate']);self.assertEqual(r['certificate_sha256'],c.digest(r['certificate']))

    def test_post_summary_write_drift_cleans_both_outputs(self):
        for mode in ('input','index'):
            with tempfile.TemporaryDirectory() as td:
                p=Path(td);src=p/'source';src.write_text('authored');out=p/'summary.json';details=p/'details.gz';details.write_bytes(b'authored metadata')
                keep=p/'preexisting';keep.write_text('keep');index=p/'function_index.json';published=[details];obs={src:c.file_hash(src)}
                dump=c.json.dump
                def mutate_after_write(value,target,**kwargs):
                    dump(value,target,**kwargs)
                    if mode=='input':src.write_text('changed during summary publication')
                    else:index.write_text('{}')
                with patch.object(c.json,'dump',side_effect=mutate_after_write):
                    with self.assertRaises(ValueError):c.publish_summary(out,dict(input_stability=True),obs,index,published)
                self.assertFalse(out.exists());self.assertFalse(details.exists());self.assertEqual(keep.read_text(),'keep');self.assertTrue(src.exists())
                if mode=='index':self.assertTrue(index.exists())

    def test_output_paths_and_dependency_drift_fail_closed(self):
        with tempfile.TemporaryDirectory() as td:
            p=Path(td);src=p/'source';src.write_text('authored');h=c.file_hash(src);obs={};c.pin(src,h,obs)
            with self.assertRaises(ValueError):c.output_paths(src,p/'details',obs)
            src.write_text('changed')
            with self.assertRaises(ValueError):c.stable(obs)


if __name__=='__main__':unittest.main()
