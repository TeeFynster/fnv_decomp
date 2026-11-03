"""Original per-field relocation/role fixtures; no compiler or native calls."""
import argparse
from collections import Counter
import gzip
import json
from pathlib import Path
import struct
import sys
import tempfile
from types import SimpleNamespace
import unittest
from unittest.mock import patch

sys.path.insert(0,str(Path(__file__).resolve().parents[2]/'tools/rebuild'))
import runtime_bind_plan as b
from test_relocation_audit import coff_bytes, pe_bytes
from test_import_plan import image_bytes as imported_image


class BindingTests(unittest.TestCase):
    def setUp(self):
        self.tmp=tempfile.TemporaryDirectory();self.addCleanup(self.tmp.cleanup);self.root=Path(self.tmp.name)
        self.image=self.root/'fixture.exe';self.image.write_bytes(pe_bytes())
        self.pe=b.Pe(self.image);self.addCleanup(self.pe.close)
        self.obj=self.root/'fixture.obj';raw=bytearray(coff_bytes());struct.pack_into('<I',raw,62,0);self.obj.write_bytes(raw)
        self.coff=b.Coff(self.obj)
        self.f=dict(symbol='_entry',address='0x00401000',section=1,value=0,size=16,verdict='match')
        self.unit=dict(recipe_id='fixture',recipe_index=0,recipe=dict(functions=[dict(symbol='_entry',address='0x00401000',size=16)],symbols={'_target':'0x00401080'}))
        self.entries={0x401080:dict(size=8)}
        self.code=b.Intervals([(0x401080,0x401088,dict(address='0x00401080'))])

    def record(self):
        r=b.relocation_record(self.coff,self.coff.sections[1],self.coff.sections[1]['relocs'][0])
        maps,places=b.source_maps(self.coff,self.unit,[self.f])
        return b.field_record(self.coff,self.unit,self.f,r,self.pe,[0x401002],maps,places,self.code,self.entries,{})

    def test_per_unit_same_name_preserves_different_exact_targets(self):
        first=self.record()
        self.pe.close();data=pe_bytes();struct.pack_into('<I',data,514,0x401084);self.image.write_bytes(data)
        self.pe=b.Pe(self.image);self.addCleanup(self.pe.close)
        self.unit['recipe']['symbols']['_target']='0x00401084'
        second=self.record()
        self.assertEqual(first['coff_relocation']['symbol'],second['coff_relocation']['symbol'])
        self.assertNotEqual(first['derived_source_symbol_base_va'],second['derived_source_symbol_base_va'])
        self.assertEqual(second['classification'],'UNIQUE_CODE_INTERIOR_OR_LOCAL_LABEL_NOT_CALLABLE_APPROVAL')
        self.assertFalse(second['runtime_eligible'])

    def test_REL32_signed_displacement_and_signed_addend(self):
        p=b.project(20,0xffffffec,0x401010,0xfffffffc)
        self.assertEqual(p['target'],0x401000)
        self.assertEqual(p['signed_original_displacement'],-20)
        self.assertEqual(p['addend'],-4)
        expected,basis=b.resolve_source(dict(name='_target',section=0,value=0),-4,{'_target':0x401004},{})
        self.assertEqual(expected,p['target'])

    def test_IAT_is_pointer_cell_not_selected_function_body(self):
        symbol=dict(name='__imp__Fixture',section=0,value=0)
        result=b.target_class(0x401080,symbol,self.coff,self.code,self.entries,{0x401080:dict(import_id=7)},self.pe,None,True)
        self.assertEqual(result['classification'],'IAT_POINTER_CELL_NOT_FUNCTION_BODY')
        self.assertEqual(result['import_id'],7)
        result=b.target_class(0x401080,symbol,self.coff,self.code,self.entries,{},self.pe,None,True)
        self.assertEqual(result['classification'],'SELECTED_CODE_ENTRY')
        self.assertTrue(result['import_pointer_source_conflict'])

    def test_code_interior_ambiguity_stays_explicit(self):
        code=b.Intervals([(0x401080,0x401088,dict(address='0x00401080')),
                          (0x401082,0x401089,dict(address='0x00401082'))])
        symbol=dict(name='_local',section=0,value=0)
        r=b.target_class(0x401084,symbol,self.coff,code,{}, {},self.pe,None,True)
        self.assertEqual(r['classification'],'AMBIGUOUS_CODE_INTERIOR')
        self.assertEqual(len(r['code_owners']),2)

    def test_source_absolute_symbol_stays_migration_evidence(self):
        target,basis=b.resolve_source(dict(name='_abs',section=-1,value=0x401080),0,{}, {})
        self.assertEqual((target,basis),(0x401080,'SOURCE_ABSOLUTE_SYMBOL'))
        r=b.target_class(target,dict(name='_abs',section=-1,value=target),self.coff,self.code,self.entries,{},self.pe,None,True)
        self.assertTrue(r['source_absolute_symbol_migration_blocker'])
        self.assertFalse(r['provider_selected'])

    def test_TLS_SECTION_and_RVA_are_special_not_absolute_bindings(self):
        for kind,expected in ((11,'STATIC_TLS_SECREL_REQUIRES_OWNER'),(10,'SECTION_INDEX_REQUIRES_OWNER'),(7,'IMAGE_RELATIVE_RVA_REQUIRES_OWNER')):
            r=b.project(kind,4,0x401000,0)
            self.assertIsNone(r['target']);self.assertEqual(r['representation'],expected)

    def test_compiler_TLS_array_offset_is_not_reported_as_process_VA(self):
        self.pe.close();data=pe_bytes();struct.pack_into('<I',data,514,0x2c);self.image.write_bytes(data)
        self.pe=b.Pe(self.image);self.addCleanup(self.pe.close)
        self.coff.symbols[1]['name']='__tls_array'
        self.unit['recipe']['symbols']={'__tls_array':'0x2c'}
        record=self.record()
        self.assertEqual(record['classification'],'COMPILER_TLS_ARRAY_OFFSET_CANDIDATE_NOT_PROCESS_VA')
        self.assertIsNone(record['exact_original_target_va'])
        self.assertEqual(record['representation']['observed_numeric_offset_candidate'],44)
        self.assertFalse(record['addressing_mode_verified'])

    def test_full_literal_equality_is_not_mutable_global_ownership(self):
        self.pe.close();data=imported_image();data[1248:1252]=b'abc\0';self.image.write_bytes(data)
        self.pe=b.Pe(self.image);self.addCleanup(self.pe.close)
        # A literal alone occupying a readonly COMDAT has a complete native extent.
        class LiteralCoff:
            sections={1:dict(index=1,comdat=True,size=4,flags=0x40001040,relocs=[])}
            def unpack(self,fmt,offset):return (b'.rdata',0,0,4,60,0,0,0,0,0x40001040)
            def take(self,offset,size):return b'abc\0'[offset-60:offset-60+size]
        coff=LiteralCoff();symbol=dict(name='??_C@_03FIXTURE@abc?$AA@',section=1,value=0)
        proof=b.literal_evidence(coff,symbol,0x4020e0,0,self.pe,[])
        self.assertTrue(proof['full_extent_equal']);self.assertFalse(proof['runtime_storage_owner_approved'])
        self.assertIsNone(b.literal_evidence(coff,dict(symbol,name='_ordinary_global'),0x4020e0,0,self.pe,[]))
        self.assertIsNone(b.literal_evidence(coff,symbol,0x4020e0,0,self.pe,[0x4020e0]))
        coff.sections[1]['flags']|=0x80000000
        self.assertIsNone(b.literal_evidence(coff,symbol,0x4020e0,0,self.pe,[]))

    def test_literal_requires_defined_readable_raw_backed_source(self):
        for section in (0,-1):
            self.assertIsNone(b.literal_evidence(self.coff,dict(name='__real@00000000',section=section,value=0),
                                                0x402020,0,self.pe,[]))
        class LiteralCoff:
            sections={1:dict(index=1,comdat=True,size=4,flags=0x40,relocs=[])}
            raw=60
            def unpack(self,fmt,offset):return (b'.rdata',0,0,4,self.raw,0,0,0,0,0x40001040)
            def take(self,offset,size):return bytes(size)
        coff=LiteralCoff();symbol=dict(name='__real@00000000',section=1,value=0)
        self.assertIsNone(b.literal_evidence(coff,symbol,0x402020,0,self.pe,[]))
        coff.sections[1]['flags']=0x40000040;coff.raw=0
        self.assertIsNone(b.literal_evidence(coff,symbol,0x402020,0,self.pe,[]))

    def test_missing_original_HIGHLOW_is_separate_and_not_synthesized(self):
        self.obj.write_bytes(coff_bytes(()));coff=b.Coff(self.obj)
        counts=Counter();rows=list(b.scan_unit(coff,self.unit,[self.f],[self.f],self.pe,[0x401002],self.code,self.entries,{},counts))
        self.assertEqual(counts,{'MISSING_COFF_RELOCATION':1})
        self.assertEqual(rows[0]['event'],'MISSING_ORIGINAL_HIGHLOW_SOURCE_MIGRATION_BLOCKER')
        self.assertIsNone(rows[0]['coff_relocation']);self.assertFalse(rows[0]['game_fixup_approved'])

    def test_wrong_original_operand_does_not_gain_receipt_consistency(self):
        self.unit['recipe']['symbols']['_target']='0x00401084'
        with self.assertRaisesRegex(ValueError,'conflicts'):self.record()

    def test_source_maps_do_not_use_global_name_or_nearest_function(self):
        target,basis=b.resolve_source(dict(name='_unbound',section=0,value=0),0,{}, {})
        self.assertIsNone(target)
        target,basis=b.resolve_source(dict(name='_local',section=1,value=31),0,{}, {(1,0):(0x401000,16)})
        self.assertIsNone(target)

    def test_stale_metadata_rejected_before_object_scan(self):
        names=('recipes','manifest','retained','selection','reference','imports','audit')
        args=argparse.Namespace(root=self.root,out=self.root/'out.json',details_gz=self.root/'detail.gz')
        for n in names:
            path=self.root/(n+'.json');path.write_text('{}');setattr(args,n,path);setattr(args,n+'_sha256',b.file_hash(path))
        args.selection.write_text('{"changed":true}')
        with patch.object(b,'Coff') as parse:
            with self.assertRaisesRegex(ValueError,'SHA-256'):b.run(args)
            parse.assert_not_called()

    def test_optional_overlay_cannot_silently_change_missing_baseline(self):
        args=argparse.Namespace(eh=None,eh_sha256=None,overlay=None,overlay_sha256=None)
        self.assertEqual(b.optional_evidence(args,{},{}),{})
        args.overlay=self.root/'overlay.json'
        with self.assertRaisesRegex(ValueError,'paired'):b.optional_evidence(args,{}, {})

    def pipeline_inputs(self):
        (self.root/'original.cpp').write_text('int original_runtime_binding_fixture;')
        recipe=dict(self.unit['recipe'],source='original.cpp',compiler='synthetic')
        def save(name,data):
            p=self.root/(name+'.json');p.write_text(json.dumps(data));return p
        recipes=save('recipes',dict(units=[recipe]));identity='0000-'+b.unit_digest(recipe)[:16]
        unit=dict(recipe_index=0,recipe_id=identity,recipe=recipe,source='original.cpp',compiler='synthetic',
            status='compiled',object='fixture.obj',object_sha256=b.file_hash(self.obj),source_sha256=b.file_hash(self.root/'original.cpp'))
        manifest=save('manifest',dict(kind='fnv-retained-objects',schema_version=1,recipe_manifest_sha256=b.file_hash(recipes),units=[unit]))
        pu=dict(recipe_index=0,recipe_id=identity,recipe_unit_sha256=b.unit_digest(recipe),object_sha256=unit['object_sha256'],
            source_sha256_recorded=unit['source_sha256'],source_sha256_current=unit['source_sha256'],status='ok',verified_functions=[self.f])
        proof=dict(kind='fnv-retained-object-verification',schema_version=1,inputs=dict(retained_manifest_sha256=b.file_hash(manifest),
            recipe_sha256=b.file_hash(recipes),image_sha256=b.file_hash(self.image),function_index_present=False,function_index_sha256=None,
            tools_sha256={n:b.file_hash(b.ROOT/n) for n in ('tools/build_and_match.py','tools/compare.py','tools/rebuild/verify_objects.py')}),
            scope=dict(full_authoritative=True),summary=dict(eh_comparison_errors=95),strict_local_eh_diagnostics_pass=False,units=[pu],runtime_closure_verified=False,
            **{k:True for k in ('retained_verification_pass','function_byte_verification_pass','global_listed_eh_coverage_pass','original_oracle_parity_pass','evidence_stable')})
        retained=save('retained',proof)
        choice=dict(recipe_id=identity,recipe_index=0,symbol='_entry',section=1,value=0,size=16,
                    selection_status='CODE_OWNERSHIP_SELECTED',runtime_eligible=False,link_ready=False)
        selection=save('selection',dict(kind='fnv-function-code-ownership-selection',schema_version=1,
            input_sha256=dict(recipe=b.file_hash(recipes),manifest=b.file_hash(manifest),receipt=b.file_hash(retained)),
            function_addresses=1,selected_recipe_rows=1,function_index_present=False,runtime_eligible=False,link_ready=False,
            retained_verification=dict(local_eh_diagnostic_count=95),selections={'0x00401000':choice}))
        paths=dict(recipes=recipes,manifest=manifest,retained=retained,selection=selection,reference=self.image)
        hashes={n:b.file_hash(p) for n,p in paths.items()}
        common=dict(schema_version=1,status='analysis-only',inputs=hashes,runtime_closure_verified=False,game_fixups_approved=0,
                    runtime_eligible=False,link_ready=False,function_providers_selected=False)
        paths['imports']=save('imports',dict(common,kind='fnv-static-import-plan',imports=[]))
        audit_details=self.root/'audit-details.gz'
        with gzip.open(audit_details,'wt') as stream:stream.write(json.dumps(dict(event='PE_HIGHLOW_CORRELATION',status='EXACT_DIR32'))+'\n')
        paths['audit']=save('audit',dict(common,kind='fnv-selected-code-relocation-audit',
            details_sha256=b.file_hash(audit_details),summary=dict(event_statuses={'PE_HIGHLOW_CORRELATION:EXACT_DIR32':1})))
        args=argparse.Namespace(root=self.root,out=self.root/'result.json',details_gz=self.root/'result.gz',audit_details=audit_details,**paths)
        for n,p in paths.items():setattr(args,n+'_sha256',b.file_hash(p))
        return args

    def test_complete_synthetic_pipeline_and_collision_safe_publication(self):
        args=self.pipeline_inputs()
        # Unrelated real-game fingerprint probes and a zero-import fixture are
        # replaced; physical COFF fields and original operands are real fixtures.
        with patch.object(b,'image_ok',return_value=(True,1,1)),patch.object(b,'parse_imports',return_value=[]):
            report=b.run(args)
        self.assertEqual(report['summary']['events'],{'SELECTED_FUNCTION_COFF_RELOCATION':1})
        self.assertEqual(report['summary']['original_HIGHLOW_partition'],{'EXACT_DIR32':1})
        self.assertFalse(report['runtime_eligible']);self.assertFalse(report['optional_function_index_present'])
        with gzip.open(args.details_gz,'rt') as f:record=json.loads(next(f))
        self.assertEqual(record['exact_original_target_va'],'0x00401080')
        self.assertEqual(record['proof_consistency'],'EXACT_OWN_SOURCE_RESOLUTION')
        with self.assertRaisesRegex(ValueError,'collision'):b.run(args)

    def test_late_input_drift_and_changed_missing_baseline_rejected(self):
        args=self.pipeline_inputs();scan=b.scan_unit
        def drift(*a,**kw):
            yield from scan(*a,**kw)
            self.obj.write_bytes(b'changed')
        with patch.object(b,'image_ok',return_value=(True,1,1)),patch.object(b,'parse_imports',return_value=[]),patch.object(b,'scan_unit',side_effect=drift):
            with self.assertRaisesRegex(ValueError,'drift'):b.run(args)
        self.assertFalse(args.out.exists());self.assertFalse(args.details_gz.exists())

    def test_changed_HIGHLOW_baseline_is_not_silently_adopted(self):
        args=self.pipeline_inputs();data=json.loads(args.audit.read_text())
        data['summary']['event_statuses']={'PE_HIGHLOW_CORRELATION:MISSING_COFF_RELOCATION':1}
        args.audit.write_text(json.dumps(data));args.audit_sha256=b.file_hash(args.audit)
        with patch.object(b,'image_ok',return_value=(True,1,1)),patch.object(b,'parse_imports',return_value=[]):
            with self.assertRaisesRegex(ValueError,'audit detail|baseline'):b.run(args)
        self.assertFalse(args.out.exists());self.assertFalse(args.details_gz.exists())

    def test_same_missing_count_different_identity_is_rejected(self):
        self.obj.write_bytes(coff_bytes(()));args=self.pipeline_inputs()
        unit=json.loads(args.manifest.read_text())['units'][0]
        event=dict(event='PE_HIGHLOW_CORRELATION',status='MISSING_COFF_RELOCATION',recipe_id=unit['recipe_id'],
            candidate=dict(address=self.f['address'],symbol=self.f['symbol']),original_field_va='0x00401003',
            physical_field=dict(section=1,offset=3),coff_fields=[])
        with gzip.open(args.audit_details,'wt') as stream:stream.write(json.dumps(event)+'\n')
        audit=json.loads(args.audit.read_text());audit['details_sha256']=b.file_hash(args.audit_details)
        audit['summary']['event_statuses']={'PE_HIGHLOW_CORRELATION:MISSING_COFF_RELOCATION':1}
        args.audit.write_text(json.dumps(audit));args.audit_sha256=b.file_hash(args.audit)
        with patch.object(b,'image_ok',return_value=(True,1,1)),patch.object(b,'parse_imports',return_value=[]):
            with self.assertRaisesRegex(ValueError,'missing-field baseline identities'):b.run(args)


if __name__=='__main__':unittest.main()
