"""Synthetic PE/COFF import identity joins; no game, DLLs or compilers."""
import argparse
import json
from pathlib import Path
import struct
import sys
import tempfile
import unittest
from unittest.mock import patch

sys.path.insert(0,str(Path(__file__).resolve().parents[2]/'tools/rebuild'))
import import_plan as plan


def image_bytes(operand=0x402070):
    data=bytearray(1536);data[:2]=b'MZ';struct.pack_into('<I',data,60,128);data[128:132]=b'PE\0\0'
    struct.pack_into('<HHIIIHH',data,132,0x14c,2,0,0,0,224,0)
    opt=152;struct.pack_into('<H',data,opt,0x10b);struct.pack_into('<I',data,opt+28,0x400000)
    struct.pack_into('<II',data,opt+56,0x3000,512);struct.pack_into('<I',data,opt+92,16)
    struct.pack_into('<II',data,opt+104,0x2000,40)
    struct.pack_into('<8sIIIIIIHHI',data,opt+224,b'.text',256,0x1000,512,512,0,0,0,0,0x60000020)
    struct.pack_into('<8sIIIIIIHHI',data,opt+264,b'.rdata',512,0x2000,512,1024,0,0,0,0,0x40000040)
    struct.pack_into('<I',data,512,operand)
    struct.pack_into('<IIIII',data,1024,0x2050,0,0,0x2090,0x2070)
    struct.pack_into('<III',data,1104,0x20a0,0x80000005,0)
    struct.pack_into('<III',data,1136,0x20a0,0x80000005,0)
    data[1168:1181]=b'fixture.dll\0\0';struct.pack_into('<H',data,1184,0)
    data[1186:1192]=b'Entry\0'
    return data


def coff_bytes(addend=0,kind=6):
    names=['_entry','__imp_?SameSource@@YAXXZ'];strings=bytearray(struct.pack('<I',4));symbols=[]
    for i,name in enumerate(names):
        offset=len(strings);strings.extend(name.encode()+b'\0')
        symbols.append(struct.pack('<IIIhHBB',0,offset,0,1 if i==0 else 0,0x20,2,0))
    struct.pack_into('<I',strings,0,len(strings))
    return (struct.pack('<HHIIIHH',0x14c,1,0,74,2,0,0)+
        struct.pack('<8sIIIIIIHHI',b'.text',0,0,4,60,64,0,1,0,0x60000020)+
        struct.pack('<I',addend)+struct.pack('<IIH',0,1,kind)+b''.join(symbols)+strings)


class ImportPlanTests(unittest.TestCase):
    def setUp(self):
        self.tmp=tempfile.TemporaryDirectory();self.addCleanup(self.tmp.cleanup);self.root=Path(self.tmp.name)
        self.image=self.root/'fixture.exe';self.image.write_bytes(image_bytes())
        self.obj=self.root/'fixture.obj';self.obj.write_bytes(coff_bytes())
        self.pe=plan.Pe(self.image);self.addCleanup(self.pe.close)
        self.imports=plan.parse_imports(self.pe);self.slots={int(i['original_IAT_va'],16) for i in self.imports}
        self.fn=dict(symbol='_entry',address='0x00401000',size=4,section=1,value=0,verdict='match')
        self.unit=dict(recipe_index=0,recipe_id='fixture',source='fixture.cpp',source_sha256='synthetic',
            object_sha256='synthetic',recipe=dict(functions=[{k:self.fn[k] for k in ('symbol','address','size')}],symbols={}))
        self.proof=dict(verified_functions=[self.fn],eh_errors=[])

    def scan(self):return list(plan.scan_unit(plan.Coff(self.obj),self.unit,self.proof,self.pe,self.slots))

    def test_actual_import_directory_named_ordinal_and_iat_identity(self):
        self.assertEqual([i['original_IAT_va'] for i in self.imports],['0x00402070','0x00402074'])
        self.assertEqual(self.imports[0]['export']['name'],'Entry')
        self.assertEqual(self.imports[1]['export'],dict(kind='ordinal',ordinal=5))
        self.assertTrue(self.imports[1]['required_provider_contract']['ordinal_export_check_required'])
        self.assertFalse(self.imports[1]['required_provider_contract']['runtime_provider_selected'])

    def test_verified_function_operand_proves_exact_slot_not_signature(self):
        use=self.scan()[0]
        self.assertEqual(use['status'],'VERIFIED_FUNCTION_EXACT_IAT_USE')
        self.assertEqual(use['original_IAT_va'],'0x00402070')
        self.assertFalse(use['source_ABI_facts']['source_declaration_and_SDK_signature_verified'])
        self.assertFalse(use['runtime_provider_selected'])

    def test_wrong_iat_recipe_binding_is_unresolved_conflict(self):
        self.unit['recipe']['symbols']['__imp_?SameSource@@YAXXZ']='0x00402074'
        use=self.scan()[0]
        self.assertEqual(use['status'],'UNRESOLVED_RECIPE_OPERAND_CONFLICT')
        self.assertIsNone(use['original_IAT_va'])

    def test_same_source_name_maps_to_distinct_slots_per_compilation(self):
        first=self.scan()[0]
        self.pe.close();self.image.write_bytes(image_bytes(0x402074));self.pe=plan.Pe(self.image)
        self.addCleanup(self.pe.close)
        second=self.scan()[0]
        self.assertEqual(first['symbol'],second['symbol'])
        self.assertNotEqual(first['original_IAT_va'],second['original_IAT_va'])

    def test_nonzero_addend_and_unsupported_kind_remain_unresolved(self):
        self.obj.write_bytes(coff_bytes(addend=4))
        self.assertEqual(self.scan()[0]['status'],'UNRESOLVED_NONZERO_ADDEND')
        self.obj.write_bytes(coff_bytes(kind=20))
        self.assertEqual(self.scan()[0]['status'],'UNRESOLVED_UNSUPPORTED_RELOCATION')

    def test_direct_body_is_never_used_as_iat_pointer(self):
        self.unit['recipe']['symbols']['__imp_?SameSource@@YAXXZ']='0x00401000'
        self.assertEqual(self.scan()[0]['status'],'UNRESOLVED_BINDING_IS_NOT_IAT_CELL')
        self.unit['recipe']['symbols']={};self.pe.close()
        self.image.write_bytes(image_bytes(0x401000));self.pe=plan.Pe(self.image);self.addCleanup(self.pe.close)
        self.assertEqual(self.scan()[0]['status'],'UNRESOLVED_OPERAND_IS_NOT_IAT_CELL')

    def test_unverified_body_is_only_metadata_evidence(self):
        self.proof['verified_functions']=[]
        self.unit['recipe']['functions']=[]
        self.assertEqual(self.scan()[0]['status'],'UNRESOLVED_UNVERIFIED_BODY_NO_BINDING')
        self.unit['recipe']['symbols']['__imp_?SameSource@@YAXXZ']='0x00402070'
        use=self.scan()[0]
        self.assertEqual(use['status'],'UNVERIFIED_BODY_RECIPE_IAT_BINDING')
        self.assertEqual(use['verified_function_fields'],[])

    def test_changed_receipt_native_function_identity_fails(self):
        self.fn['value']=1
        with self.assertRaisesRegex(ValueError,'native identity'):self.scan()
        self.fn['value']=0;self.fn['symbol']='_wrong'
        with self.assertRaisesRegex(ValueError,'coverage'):self.scan()

    def test_stale_hash_rejects_before_object_or_image_analysis(self):
        paths={n:self.root/(n+'.json') for n in ('recipes','manifest','retained','reference')}
        for p in paths.values():p.write_text('{}')
        args=argparse.Namespace(root=self.root,out=self.root/'out.json',details_gz=self.root/'details.gz',**paths)
        for n,p in paths.items():setattr(args,n+'_sha256',plan.file_hash(p))
        paths['manifest'].write_text('{"changed":true}')
        with patch.object(plan,'Pe') as reader:
            with self.assertRaisesRegex(ValueError,'SHA-256'):plan.run(args)
            reader.assert_not_called()

    def test_invalid_ordinal_and_unterminated_descriptors_rejected(self):
        self.pe.close();data=image_bytes();struct.pack_into('<I',data,1104,0x80010005)
        self.image.write_bytes(data);pe=plan.Pe(self.image)
        try:
            with self.assertRaisesRegex(ValueError,'ordinal'):plan.parse_imports(pe)
        finally:pe.close()
        data=image_bytes();struct.pack_into('<II',data,152+104,0x2000,20);self.image.write_bytes(data);pe=plan.Pe(self.image)
        try:
            with self.assertRaisesRegex(ValueError,'descriptors'):plan.parse_imports(pe)
        finally:pe.close()

    def test_conflicting_verified_fields_are_not_resolved_by_name(self):
        result=plan.classify(6,0,None,[dict(observed_operand=0x402070),dict(observed_operand=0x402074)],self.slots)
        self.assertEqual(result['status'],'UNRESOLVED_RECIPE_OPERAND_CONFLICT')

    def test_bound_first_thunk_fallback_is_rejected(self):
        for timestamp,bound in ((1,False),(0xffffffff,False),(0,True)):
            with self.subTest(timestamp=timestamp,bound=bound):
                data=image_bytes();struct.pack_into('<II',data,1024,0,timestamp)
                if bound:struct.pack_into('<II',data,152+96+11*8,0x20c0,8)
                self.pe.close();self.image.write_bytes(data);pe=plan.Pe(self.image)
                try:
                    with self.assertRaisesRegex(ValueError,'ambiguous'):plan.parse_imports(pe)
                finally:pe.close()
        data=image_bytes();struct.pack_into('<I',data,1024,0);self.image.write_bytes(data);pe=plan.Pe(self.image)
        try:self.assertEqual(len(plan.parse_imports(pe)),2)
        finally:pe.close()

    def test_incomplete_or_duplicate_function_proof_is_rejected(self):
        self.proof['verified_functions']=[]
        with self.assertRaisesRegex(ValueError,'coverage'):self.scan()
        self.proof['verified_functions']=[self.fn,self.fn]
        with self.assertRaisesRegex(ValueError,'coverage'):self.scan()


if __name__=='__main__':unittest.main()
