"""Invented COFF payloads only; no compiler, game image or native execution."""
import copy
import json
from pathlib import Path
import struct
import sys
import tempfile
import unittest
from unittest.mock import patch

sys.path.insert(0,str(Path(__file__).resolve().parents[2]/'tools/rebuild'))
import coff_tls_extract as extract
from test_tls_owner_fixture import original_objects


def getter_object():
    strings,records=bytearray(4),bytearray()
    def symbol(name,value,section,typ,storage,aux=b''):
        raw=name.encode()
        if len(raw)>8:field=struct.pack('<II',0,len(strings));strings.extend(raw+b'\0')
        else:field=raw.ljust(8,b'\0')
        records.extend(struct.pack('<8sIhHBB',field,value,section,typ,storage,bool(aux)));records.extend(aux)
    directives=(' '+' '.join(extract.DROP_ALIASES+extract.DEFAULTS)+' ').encode()
    code=bytes(26);tlsdata=bytearray(700);struct.pack_into('<i',tlsdata,696,59)
    symbol('@comp.id',8681481,-1,0,3);symbol('@feat.00',1,-1,0,3)
    symbol('.drectve',0,1,0,3,struct.pack('<IHHIhBBH',len(directives),0,0,0,0,0,0,0))
    symbol('.text',0,56,0,3,struct.pack('<IHHIhBBH',26,3,0,0,0,1,0,0))
    symbol(extract.PARENT,0,56,32,2);symbol('__tls_index',0,0,0,2);symbol('__tls_array',0,0,0,2)
    symbol('.tls$',0,4,0,3,struct.pack('<IHHIhBBH',700,0,0,0,0,0,0,0));symbol(extract.FIELD,696,4,0,2)
    cursor=20+56*40;headers,body=bytearray(),bytearray();positions={}
    for index in range(1,57):
        name,data,flags=('.drectve',directives,0x00100a00) if index==1 else ('.tls$',tlsdata,0xc0400040) if index==4 else ('.text',code,0x60501020) if index==56 else ('.dummy',b'\0',0x40000040)
        positions[index]=cursor;raw=cursor;body.extend(data);cursor+=len(data);relptr=0
        if index==56:
            relptr=cursor
            for offset,target,kind in ((4,7,6),(11,8,6),(20,11,11)):
                body.extend(struct.pack('<IIH',offset,target,kind));cursor+=10
        headers.extend(struct.pack('<8sIIIIIIHHI',name.encode(),0,0,len(data),raw,relptr,0,3 if index==56 else 0,0,flags))
    struct.pack_into('<I',strings,0,len(strings))
    return bytearray(struct.pack('<HHIIIHH',0x14c,56,0,cursor,12,0,0)+headers+body+records+strings),positions,cursor


class GetterExtractTests(unittest.TestCase):
    def setUp(self):
        self.temp=tempfile.TemporaryDirectory();self.addCleanup(self.temp.cleanup);self.root=Path(self.temp.name)
        self.path=self.root/'invented.obj';self.data,self.positions,self.symptr=getter_object();self.path.write_bytes(self.data)

    def test_exact_code_kept_tls_removed_field_externalized_directives_accounted(self):
        data,ledger=extract.getter_bytes(self.path);out=self.root/'getter.obj';out.write_bytes(data)
        extract.reparse_getter(self.path,out);coff,_,_,_=extract.strict_object(out)
        self.assertEqual([s['name'] for s in coff.sections.values()],['.drectve','.text'])
        self.assertEqual(extract.tls.named(coff,extract.FIELD)['section'],0)
        self.assertEqual(coff.directives,extract.DEFAULTS)
        self.assertEqual(ledger['dropped_unrelated_directives'],extract.DROP_ALIASES)
        self.assertEqual(ledger['original_native_field_offset'],0x2b8)
        self.assertEqual(extract.tls.section_payload(coff,2),bytes(26))

    def test_unknown_or_changed_directive_rejects(self):
        start=self.positions[1]
        self.data[start+2]=ord('x');self.path.write_bytes(self.data)
        with self.assertRaisesRegex(ValueError,'directive'):extract.getter_bytes(self.path)

    def test_nonzero_addend_wrong_kind_and_boundary_reject(self):
        for mutation in ('addend','kind','boundary'):
            data=bytearray(self.data)
            if mutation=='addend':struct.pack_into('<I',data,self.positions[56]+20,4)
            elif mutation=='kind':struct.pack_into('<H',data,self.positions[56]+26+2*10+8,6)
            else:struct.pack_into('<I',data,self.positions[56]+26+2*10,24)
            self.path.write_bytes(data)
            with self.subTest(mutation=mutation):
                with self.assertRaises(ValueError):extract.getter_bytes(self.path)

    def test_old_field_offset_initializer_or_section_policy_reject(self):
        for mutation in ('offset','initial','flags'):
            data=bytearray(self.data)
            if mutation=='offset':struct.pack_into('<I',data,self.symptr+11*18+8,692)
            elif mutation=='initial':struct.pack_into('<i',data,self.positions[4]+696,37)
            else:struct.pack_into('<I',data,20+55*40+36,0x60502020)
            self.path.write_bytes(data)
            with self.assertRaises(ValueError):extract.getter_bytes(self.path)

    def test_hidden_getter_child_and_producer_feature_reject(self):
        coff,_,_,_=extract.strict_object(self.path);coff.sections[2]['association']=56
        with self.assertRaisesRegex(ValueError,'child'):extract.select(coff)
        struct.pack_into('<I',self.data,self.symptr+18+8,0);self.path.write_bytes(self.data)
        with self.assertRaisesRegex(ValueError,'feature'):extract.getter_bytes(self.path)

    def test_unknown_getter_auxiliary_and_line_records_reject(self):
        for mutation in ('aux','line'):
            data=bytearray(self.data)
            if mutation=='aux':data[self.symptr+5*18+15]=1
            else:struct.pack_into('<I',data,20+55*40+28,1)
            self.path.write_bytes(data)
            with self.assertRaises(ValueError):extract.getter_bytes(self.path)

    def test_getter_reparse_rejects_payload_change(self):
        data,_=extract.getter_bytes(self.path);out=self.root/'getter.obj';out.write_bytes(data)
        coff,_,_,_=extract.strict_object(out);raw=coff.unpack('<8sIIIIIIHHI',60)[4]
        data=bytearray(data);data[raw]=1;out.write_bytes(data)
        with self.assertRaisesRegex(ValueError,'code'):extract.reparse_getter(self.path,out)

    def test_symbolic_storage_view_preserves_every_original_region(self):
        original=original_objects(self.root)['storage'];before=original.read_bytes()
        data,view=extract.alias_bytes(original,extract.VIEW);out=self.root/'storage-view.obj';out.write_bytes(data)
        extract.reparse_alias(original,out,extract.VIEW)
        after,_,_,_=extract.strict_object(out);field=extract.tls.named(after,extract.FIELD)
        self.assertEqual((field['section'],field['value']),(1,688))
        self.assertEqual(view['size'],4);self.assertEqual(view['alignment'],4)
        self.assertEqual(original.read_bytes(),before)
        self.assertEqual(extract.tls.section_payload(after,1),extract.tls.authored_owner())

    def test_wrong_view_is_not_absolute_or_guessed_native_offset(self):
        original=original_objects(self.root)['storage']
        for key,value in [('offset',0x2b8),('offset',0x2b4),('size',8),('alignment',8),('symbol','other')]:
            view=dict(extract.VIEW);view[key]=value
            with self.assertRaisesRegex(ValueError,'view'):extract.alias_bytes(original,view)

    def test_changed_authored_storage_or_alias_collision_rejects(self):
        original=original_objects(self.root,owner_flags=0xc0400040)['storage']
        with self.assertRaises(ValueError):extract.alias_bytes(original,extract.VIEW)
        original=original_objects(self.root)['storage'];data,_=extract.alias_bytes(original,extract.VIEW)
        out=self.root/'already-aliased.obj';out.write_bytes(data)
        with self.assertRaisesRegex(ValueError,'already'):extract.alias_bytes(out,extract.VIEW)

    def test_alias_reparse_rejects_non_symbol_edit(self):
        original=original_objects(self.root)['storage'];data,_=extract.alias_bytes(original,extract.VIEW)
        data=bytearray(data);raw=struct.unpack_from('<I',data,20+20)[0];data[raw]=1
        out=self.root/'bad.obj';out.write_bytes(data)
        with self.assertRaises(ValueError):extract.reparse_alias(original,out,extract.VIEW)

    def test_extraction_requires_actual_fixed_proof_before_transform(self):
        out,rp=self.root/'out.obj',self.root/'out.json'
        with patch.object(extract,'verify_basis',side_effect=ValueError('stale proof')),patch.object(extract,'getter_bytes') as transform:
            with self.assertRaisesRegex(ValueError,'stale proof'):extract.extract('m','s','v','i','c','h',out,rp)
            transform.assert_not_called()
        self.assertFalse(out.exists());self.assertFalse(rp.exists())

    def test_context_hash_and_output_collisions_fail_closed(self):
        context=self.root/'context.json';context.write_text('{}')
        with self.assertRaisesRegex(ValueError,'context changed'):extract.caller_context(context,'0'*64)
        with self.assertRaises(ValueError):extract.alias_storage(context,extract.sha(context),self.path,self.root/'receipt.json')
        with self.assertRaises(ValueError):extract.extract('m','s','v','i','c','h',self.path,self.root/'receipt.json')

    def test_late_input_drift_publishes_no_getter(self):
        fake=dict(inputs={str(self.path):'0'*64},object=str(self.path),image='unused',unit={})
        with patch.object(extract,'verify_basis',return_value=fake),patch.object(extract,'caller_context',return_value=({},{})),patch.object(extract,'comparison',return_value={}):
            with self.assertRaisesRegex(ValueError,'changed'):extract.extract('m','s','v','i','c','h',self.root/'out.obj',self.root/'out.json')
        self.assertFalse((self.root/'out.obj').exists());self.assertFalse((self.root/'out.json').exists())


if __name__=='__main__':unittest.main()
