"""Original synthetic relocation metadata; no game inputs or native execution."""
import argparse
import copy
import gzip
import hashlib
import json
from pathlib import Path
import struct
import sys
import tempfile
import unittest
from unittest.mock import patch
sys.path.insert(0,str(Path(__file__).resolve().parents[2]/'tools/rebuild'))
import relocation_audit as a


def coff_bytes(relocs=((2,1,6),), *, absolute=False, metadata=False):
    symbols=[('_entry',0,1),('@feat.00' if metadata else '_target',0x401080 if absolute else 0,-1 if absolute or metadata else 0)]
    strings=bytearray(struct.pack('<I',4));records=bytearray()
    for name,value,sec in symbols:
        ptr=len(strings);strings.extend(name.encode()+b'\0')
        records.extend(struct.pack('<IIIhHBB',0,ptr,value,sec,0x20 if sec>0 else 0,2,0))
    struct.pack_into('<I',strings,0,len(strings))
    raw=bytearray(16);struct.pack_into('<I',raw,2,0x401080)
    return (struct.pack('<HHIIIHH',0x14c,1,0,76+10*len(relocs),2,0,0)+
        struct.pack('<8sIIIIIIHHI',b'.text',0,0,16,60,76 if relocs else 0,0,len(relocs),0,0x60000020)+
        raw+b''.join(struct.pack('<IIH',*r) for r in relocs)+records+strings)


def pe_bytes():
    data=bytearray(1536);data[:2]=b'MZ';struct.pack_into('<I',data,60,128);data[128:132]=b'PE\0\0'
    struct.pack_into('<HHIIIHH',data,132,0x14c,2,0,0,0,224,0)
    opt=152;struct.pack_into('<H',data,opt,0x10b);struct.pack_into('<I',data,opt+28,0x400000)
    struct.pack_into('<II',data,opt+56,0x3000,512);struct.pack_into('<I',data,opt+92,16)
    struct.pack_into('<II',data,opt+96+5*8,0x2000,12)
    struct.pack_into('<8sIIIIIIHHI',data,opt+224,b'.text',256,0x1000,512,512,0,0,0,0,0x60000020)
    struct.pack_into('<8sIIIIIIHHI',data,opt+264,b'.reloc',256,0x2000,512,1024,0,0,0,0,0x40000040)
    struct.pack_into('<I',data,514,0x401080)
    struct.pack_into('<IIHH',data,1024,0x1000,12,0x3002,0)
    return data


class AuditTests(unittest.TestCase):
    def setUp(self):
        self.tmp=tempfile.TemporaryDirectory();self.addCleanup(self.tmp.cleanup);self.root=Path(self.tmp.name)
        self.obj=self.root/'fixture.obj';self.obj.write_bytes(coff_bytes())
        self.f=dict(symbol='_entry',address='0x00401000',section=1,value=0,size=16,verdict='match')
        self.unit=dict(recipe_id='fixture',recipe_index=0,object_sha256='synthetic')

    def scan(self,sites=None,functions=None):
        functions=functions or [self.f]
        original=a.Intervals([(int(f['address'],16),int(f['address'],16)+f['size'],a.owner(f,True)) for f in functions])
        return list(a.scan_unit(a.Coff(self.obj),self.unit,functions,[self.f],
            [0x401002] if sites is None else sites,original,0x400000,0x3000))

    def test_complete_dir32_matches_exact_field(self):
        event=self.scan()[0]
        self.assertEqual(event['status'],'EXACT_DIR32')
        self.assertEqual(event['physical_field'],dict(section=1,offset=2,width=4))
        self.assertEqual(event['coff_fields'][0]['symbol_index'],1)
        self.assertFalse(event['safe_patch_approved'])

    def test_missing_coff_reference(self):
        self.obj.write_bytes(coff_bytes(()))
        self.assertEqual(self.scan()[0]['status'],'MISSING_COFF_RELOCATION')

    def test_conflicting_duplicate_and_partial_fields(self):
        for relocs in (((2,1,6),(2,1,6)),((1,1,6),),((4,1,6),(2,1,6))):
            self.obj.write_bytes(coff_bytes(relocs))
            self.assertEqual(self.scan()[0]['status'],'CONFLICTING_FIELD')

    def test_rel32_absence_is_not_a_defect(self):
        self.obj.write_bytes(coff_bytes(((2,1,20),)))
        self.assertEqual(self.scan(sites=[]),[])
        self.assertEqual(self.scan()[0]['status'],'UNSUPPORTED_KIND')

    def test_unsupported_kind(self):
        self.obj.write_bytes(coff_bytes(((2,1,7),)))
        self.assertEqual(self.scan()[0]['status'],'UNSUPPORTED_KIND')

    def test_unknown_width_rejected_and_absolute_padding_ignored(self):
        self.obj.write_bytes(coff_bytes(((2,1,99),)))
        with self.assertRaisesRegex(ValueError,'unknown COFF'):self.scan()
        self.obj.write_bytes(coff_bytes(((2,1,0),)))
        self.assertEqual(self.scan()[0]['status'],'MISSING_COFF_RELOCATION')
        self.assertEqual(self.scan(sites=[]),[])

    def test_original_full_span_must_be_executable_and_raw_backed(self):
        path=self.root/'original.exe'
        for flags,rawsize in ((0x40000040,512),(0x60000020,8)):
            data=pe_bytes();struct.pack_into('<I',data,152+224+36,flags);struct.pack_into('<I',data,152+224+16,rawsize)
            path.write_bytes(data);pe=a.Pe(path)
            try:
                with self.assertRaisesRegex(ValueError,'executable/raw'):a.check_original_span(pe,self.f)
            finally:pe.close()

    def test_straddling_start_and_end(self):
        self.f.update(value=2,address='0x00401002',size=4)
        for site in (0x401000,0x401004):
            self.assertEqual(self.scan([site])[0]['status'],'STRADDLING_FUNCTION_SPAN')

    def test_competing_physical_and_original_owners_stay_visible(self):
        other=dict(self.f,symbol='_overlap',address='0x00401001',value=1,size=12)
        event=self.scan(functions=[self.f,other])[0]
        self.assertTrue(event['physical_ownership_ambiguous']);self.assertTrue(event['original_ownership_ambiguous'])
        self.assertEqual(len(event['physical_overlapping_owners']),2)

    def test_absolute_target_vs_standard_metadata(self):
        self.obj.write_bytes(coff_bytes(absolute=True))
        events=self.scan();self.assertEqual(events[-1]['status'],'ABSOLUTE_SYMBOL_IN_ORIGINAL_IMAGE')
        self.assertEqual(events[-1]['field']['symbol_value'],0x401080)
        self.obj.write_bytes(coff_bytes(absolute=True,metadata=True))
        self.assertEqual(self.scan()[-1]['status'],'LINKER_METADATA_NOT_RUNTIME_EDGE')

    def test_address_shaped_constant_without_highlow_is_not_scanned(self):
        self.obj.write_bytes(coff_bytes(()))
        self.assertEqual(self.scan(sites=[]),[])

    def test_native_span_and_selected_candidate_identity(self):
        self.unit['recipe']=dict(functions=[{k:self.f[k] for k in ('symbol','address','size')}])
        proof=dict(verified_functions=[self.f])
        a.verified_functions(a.Coff(self.obj),self.unit,proof)
        choice=dict(recipe_id='fixture',recipe_index=0,symbol='_entry',section=1,value=0,size=16,
            selection_status='CODE_OWNERSHIP_SELECTED',runtime_eligible=False,link_ready=False)
        a.selected_for_unit(self.unit,[self.f],{'0x00401000':choice})
        choice['value']=1
        with self.assertRaisesRegex(ValueError,'selection/native'):a.selected_for_unit(self.unit,[self.f],{'0x00401000':choice})
        self.f['value']=1
        with self.assertRaisesRegex(ValueError,'native'):a.verified_functions(a.Coff(self.obj),self.unit,proof)

    def inputs(self):
        source=self.root/'original.cpp';source.write_text('int original_fixture;')
        image=self.root/'original.exe';image.write_bytes(pe_bytes())
        recipe=dict(source='original.cpp',compiler='synthetic',functions=[{k:self.f[k] for k in ('symbol','address','size')}])
        recipes=self.root/'recipes.json';recipes.write_text(json.dumps(dict(units=[recipe])))
        identity='0000-'+a.unit_digest(recipe)[:16]
        unit=dict(self.unit,recipe_id=identity,source='original.cpp',compiler='synthetic',recipe=recipe,status='compiled',
            object='fixture.obj',object_sha256=a.file_hash(self.obj),source_sha256=a.file_hash(source))
        manifest=self.root/'manifest.json';manifest.write_text(json.dumps(dict(kind='fnv-retained-objects',schema_version=1,recipe_manifest_sha256=a.file_hash(recipes),units=[unit])))
        proofunit=dict(recipe_id=identity,recipe_index=0,recipe_unit_sha256=a.unit_digest(recipe),object_sha256=unit['object_sha256'],
            source_sha256_recorded=unit['source_sha256'],source_sha256_current=unit['source_sha256'],status='ok',verified_functions=[self.f])
        proof=dict(kind='fnv-retained-object-verification',schema_version=1,inputs=dict(retained_manifest_sha256=a.file_hash(manifest),recipe_sha256=a.file_hash(recipes),
            image_sha256=a.file_hash(image),function_index_present=False,function_index_sha256=None,
            tools_sha256={n:a.file_hash(a.ROOT/n) for n in ('tools/build_and_match.py','tools/compare.py','tools/rebuild/verify_objects.py')}),
            scope=dict(full_authoritative=True),summary=dict(eh_comparison_errors=95),strict_local_eh_diagnostics_pass=False,units=[proofunit],
            **{k:True for k in ('retained_verification_pass','function_byte_verification_pass','global_listed_eh_coverage_pass','original_oracle_parity_pass','evidence_stable')})
        retained=self.root/'retained.json';retained.write_text(json.dumps(proof))
        choice=dict(recipe_id=identity,recipe_index=0,symbol='_entry',section=1,value=0,size=16,selection_status='CODE_OWNERSHIP_SELECTED',runtime_eligible=False,link_ready=False)
        selection=self.root/'selection.json';selection.write_text(json.dumps(dict(kind='fnv-function-code-ownership-selection',schema_version=1,
            input_sha256=dict(recipe=a.file_hash(recipes),manifest=a.file_hash(manifest),receipt=a.file_hash(retained)),function_addresses=1,selected_recipe_rows=1,
            retained_verification=dict(local_eh_diagnostic_count=95),function_index_present=False,runtime_eligible=False,link_ready=False,selections={'0x00401000':choice})))
        args=argparse.Namespace(root=self.root,out=self.root/'audit.json',details_gz=self.root/'details.gz',recipes=recipes,manifest=manifest,retained=retained,selection=selection,reference=image)
        for n in ('recipes','manifest','retained','selection','reference'):setattr(args,n+'_sha256',a.file_hash(getattr(args,n)))
        return args

    def test_full_pipeline_synthetic_pe_and_coff(self):
        args=self.inputs()
        with patch.object(a,'image_ok',return_value=(True,1,1)):
            report=a.run(args)
        self.assertEqual(report['summary']['event_statuses'],{'PE_HIGHLOW_CORRELATION:EXACT_DIR32':1})
        self.assertEqual(report['original_local_EH_diagnostic_count'],95)
        self.assertFalse(report['optional_function_index_present']);self.assertFalse(report['runtime_eligible'])
        with gzip.open(args.details_gz,'rt') as f:self.assertEqual(json.loads(next(f))['status'],'EXACT_DIR32')

    def test_stale_proof_and_image_fail_before_analysis(self):
        for name in ('retained','reference'):
            args=self.inputs();getattr(args,name).write_bytes(b'changed')
            with patch.object(a,'Coff') as parse:
                with self.assertRaises(ValueError):a.run(args)
                parse.assert_not_called()

    def test_output_collision_and_late_input_drift(self):
        args=self.inputs();args.out=args.selection
        with self.assertRaisesRegex(ValueError,'collision'):a.run(args)
        args=self.inputs();original=a.scan_unit
        def drift(*x,**kw):
            yield from original(*x,**kw)
            self.obj.write_bytes(b'changed')
        with patch.object(a,'image_ok',return_value=(True,1,1)),patch.object(a,'scan_unit',drift):
            with self.assertRaisesRegex(ValueError,'changed'):a.run(args)
        self.assertFalse(args.out.exists());self.assertFalse(args.details_gz.exists())
        self.assertIn('failed',Path(str(args.out)+'.progress.jsonl').read_text())

if __name__=='__main__':unittest.main()
