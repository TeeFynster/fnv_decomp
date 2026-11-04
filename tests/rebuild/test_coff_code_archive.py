"""Authored synthetic COFF/archive conformance and corruption cases; no native tools."""
from pathlib import Path
import struct
import sys
import unittest
sys.path.insert(0,str(Path(__file__).resolve().parents[2]/'tools/rebuild'))
import coff_code_archive as c


def section(name,payload,flags=0x60501020,relocs=()):
    return dict(name=name,payload=payload,size=len(payload),flags=flags,relocs=list(relocs))


def aux(size,relocs=0,selection=1,association=0):
    return struct.pack('<IHHIhBBH',size,relocs,0,0,association,selection,0,0)


def symbol(name,sec,value=0,typ=0,storage=2,auxiliary=b''):
    return (name,value,sec,typ,storage,auxiliary)


def object_bytes(sections,symbols):
    """Independent authored test encoder; deliberately no production writer call."""
    strings=bytearray(4)
    def name(n,is_section=False):
        raw=n.encode()
        if len(raw)<=8:return raw.ljust(8,b'\0')
        at=len(strings);strings.extend(raw+b'\0')
        return ('/'+str(at)).encode().ljust(8,b'\0') if is_section else struct.pack('<II',0,at)
    pos=20+40*len(sections);headers=bytearray();body=bytearray()
    for sec in sections:
        raw=pos;body+=sec['payload'];pos+=len(sec['payload']);rp=pos if sec['relocs'] else 0
        for off,idx,kind in sec['relocs']:
            body+=struct.pack('<IIH',off,idx,kind);pos+=10
        headers+=struct.pack('<8sIIIIIIHHI',name(sec['name'],True),0,0,sec['size'],raw,rp,0,len(sec['relocs']),0,sec['flags'])
    records=bytearray();count=0
    for n,value,sec,typ,storage,a in symbols:
        records+=struct.pack('<8sIhHBB',name(n),value,sec,typ,storage,len(a)//18)+a;count+=1+len(a)//18
    struct.pack_into('<I',strings,0,len(strings))
    return struct.pack('<HHIIIHH',0x14c,len(sections),123,pos,count,0,0)+headers+body+records+strings


def tiny(name='_synthetic',payload=b'authored'):
    return object_bytes([section('.text',payload)],[symbol('.text',1,storage=3,auxiliary=aux(len(payload))),symbol(name,1,typ=32)])


class CoffTests(unittest.TestCase):
    def test_namespace_preserves_all_numeric_and_aux_slots(self):
        raw=object_bytes([section('.text',b'abcdefgh')],[symbol('.text',1,storage=3,auxiliary=aux(8)),symbol('_same',1,typ=32),symbol('_same',0)])
        out=c.namespace(raw,[(2,'_physical_definition_long'),(3,'_physical_reference_long')]);a,b=c.parse(raw),c.parse(out)
        self.assertEqual(a['sections'],b['sections']);self.assertEqual(list(a['symbols']),list(b['symbols']))
        self.assertEqual(b['symbols'][3]['section'],0);self.assertEqual(b['symbols'][2]['aux'],b'')
        with self.assertRaisesRegex(ValueError,'conflicting'):c.namespace(raw,[(2,'_a'),(2,'_b')])
        with self.assertRaisesRegex(ValueError,'collision'):c.namespace(raw,[(2,'_new'),(3,'_new')])

    def test_exact_section_symbol_aux_bijection_and_association(self):
        raw=object_bytes([section('.unused',b'xx'),section('.text',b'abcd'),section('.assoc',b'xyz',flags=0x40401040)],
            [symbol('.unused',1,storage=3,auxiliary=aux(2)),symbol('.text',2,storage=3,auxiliary=aux(4)),
             symbol('_long_function_export',2,typ=32),symbol('.assoc',3,storage=3,auxiliary=aux(3,selection=5,association=2))])
        out,r=c.serialize(raw,[2,3],[2,4,5]);b=c.parse(out)
        self.assertEqual(r['section_map'],{2:1,3:2});self.assertEqual(r['symbol_map'],{2:0,4:2,5:3});self.assertEqual(r['auxiliary_map'],{3:1,6:4})
        self.assertEqual(struct.unpack_from('<h',b['symbols'][3]['aux'],12)[0],1)
        with self.assertRaisesRegex(ValueError,'association'):c.serialize(raw,[3],[5])

    def test_addends_relocations_and_definition_to_undefined(self):
        payload=struct.pack('<II',0x102,0xfffffffc)
        raw=object_bytes([section('.unused',b'u'),section('.text',payload,relocs=[(0,7,6),(4,8,20)]),section('.data',b'storage',flags=0xc0300040)],
            [symbol('.unused',1,storage=3,auxiliary=aux(1)),symbol('.text',2,storage=3,auxiliary=aux(8,2)),symbol('_fn',2,typ=32),
             symbol('.data',3,storage=3,auxiliary=aux(7,selection=0)),symbol('_data',3,value=2),symbol('_callee',0,typ=32)])
        out,r=c.serialize(raw,[2],[2,4,7,8],undefined=[7]);b=c.parse(out)
        self.assertEqual(b['sections'][1]['payload'],payload)
        self.assertEqual(b['sections'][1]['relocs'],[(0,3,6),(4,4,20)])
        self.assertEqual((b['symbols'][3]['section'],b['symbols'][3]['value'],b['symbols'][3]['storage']),(0,0,2))
        self.assertEqual(r['undefined_conversions'],[7])
        with self.assertRaisesRegex(ValueError,'outside section'):c.serialize(raw,[2],[2,4,7,8])
        with self.assertRaisesRegex(ValueError,'conversion'):c.serialize(raw,[2],[2,4,5,7,8],undefined=[5,7])

    def test_long_section_names(self):
        raw=object_bytes([section('.longsection',b'abc')],[symbol('.longsection',1,storage=3,auxiliary=aux(3)),symbol('_root',1,typ=32)])
        out,_=c.serialize(raw,[1],[0,2]);self.assertEqual(c.parse(out)['sections'][1]['name'],'.longsection')

    def test_malformed_indices_bounds_aux_and_unknown_metadata(self):
        raw=tiny();obj=c.parse(raw)
        bad=bytearray(raw);bad[obj['symbol_pointer']+17]=255
        with self.assertRaises(ValueError):c.parse(bytes(bad))
        bad=bytearray(raw);struct.pack_into('<I',bad,20+20,len(raw)-1);struct.pack_into('<H',bad,20+32,1)
        with self.assertRaises(ValueError):c.parse(bytes(bad))
        for idx in (1,99):
            raw=object_bytes([section('.text',b'abcd',relocs=[(0,idx,6)])],[symbol('.text',1,storage=3,auxiliary=aux(4,1)),symbol('_root',1,typ=32)])
            with self.assertRaisesRegex(ValueError,'auxiliary/absent'):c.parse(raw)
        raw=object_bytes([section('.text',b'abcd')],[symbol('.text',1,storage=3,auxiliary=aux(4)[:16]+b'\x01\0'),symbol('_root',1,typ=32)])
        with self.assertRaisesRegex(ValueError,'auxiliary'):c.serialize(raw,[1],[0,2])

    def test_reparse_detects_payload_symbol_and_relocation_corruption(self):
        raw=object_bytes([section('.text',b'abcdefgh',relocs=[(0,3,6)])],[symbol('.text',1,storage=3,auxiliary=aux(8,1)),symbol('_root',1,typ=32),symbol('_external',0)])
        out,r=c.serialize(raw,[1],[0,2,3]);bad=bytearray(out);bad[60]^=1
        with self.assertRaisesRegex(ValueError,'section semantic'):c.verify_selection(raw,bytes(bad),r)
        bad=bytearray(out);struct.pack_into('<I',bad,c.parse(out)['symbol_pointer']+18*3+8,1)
        with self.assertRaisesRegex(ValueError,'symbol/auxiliary'):c.verify_selection(raw,bytes(bad),r)

    def test_forged_section_symbol_and_auxiliary_maps_reject(self):
        raw=object_bytes([section('.text',b'same'),section('.text',b'same')],
            [symbol('.text',1,storage=3,auxiliary=aux(4)),symbol('_x',1,typ=32),
             symbol('.text',2,storage=3,auxiliary=aux(4)),symbol('_x',2,typ=32)])
        out,r=c.serialize(raw,[1],[0,2])
        bad={k:dict(v) if isinstance(v,dict) else list(v) for k,v in r.items()};bad['section_map'][2]=1
        with self.assertRaisesRegex(ValueError,'noninjective'):c.verify_selection(raw,out,bad)
        bad={k:dict(v) if isinstance(v,dict) else list(v) for k,v in r.items()};bad['symbol_map'][5]=2
        with self.assertRaisesRegex(ValueError,'noninjective'):c.verify_selection(raw,out,bad)
        for mapping in ({},{1:2},{1:1,4:1},{1:1,4:3}):
            bad=dict(r,auxiliary_map=mapping)
            with self.assertRaisesRegex(ValueError,'bijection'):c.verify_selection(raw,out,bad)

    def test_forged_conversion_of_retained_section_and_omitted_section_alias(self):
        raw=tiny();out,r=c.serialize(raw,[1],[0,2]);bad=bytearray(out)
        offset=c.parse(out)['symbol_pointer']+18*2
        struct.pack_into('<Ih',bad,offset+8,0,0)
        with self.assertRaisesRegex(ValueError,'undefined conversion'):
            c.verify_selection(raw,bytes(bad),dict(r,undefined_conversions=[2]))
        # Omitted old section1 must not accidentally resolve to output section1,
        # which actually comes from retained old section2.
        raw=object_bytes([section('.text',b'same'),section('.text',b'same')],
            [symbol('_x',1,typ=32),symbol('.text',2,storage=3,auxiliary=aux(4)),symbol('_x',2,typ=32)])
        out,r=c.serialize(raw,[2],[1,3]);forged=dict(r,symbol_map={0:2,1:0})
        with self.assertRaisesRegex(ValueError,'retained definition outside'):
            c.verify_selection(raw,out,forged)


class ArchiveTests(unittest.TestCase):
    def test_both_indices_long_names_alignment_and_determinism(self):
        members=[('recipe_with_a_long_name.obj',tiny('_z',b'odd')),('second.obj',tiny('_a',b'even'))]
        raw=c.archive(members);self.assertEqual(raw,c.archive(members))
        result=c.read_archive(raw);self.assertEqual(result['members'],members)
        self.assertEqual(result['index'],[('_a','second.obj'),('_z','recipe_with_a_long_name.obj')])
        self.assertEqual(raw[:8],b'!<arch>\n')

    def test_undefined_dependencies_are_absent_from_export_lookup(self):
        obj=object_bytes([section('.text',b'abcd',relocs=[(0,3,6)])],[symbol('.text',1,storage=3,auxiliary=aux(4,1)),symbol('_root',1,typ=32),symbol('_unowned_data',0)])
        result=c.read_archive(c.archive([('one.obj',obj)]));self.assertEqual(result['index'],[('_root','one.obj')])
        self.assertEqual(c.parse(result['members'][0][1])['symbols'][3]['section'],0)

    def test_duplicate_exports_members_and_malformed_archive_index(self):
        with self.assertRaisesRegex(ValueError,'duplicate archive export'):c.archive([('one.obj',tiny()),('two.obj',tiny())])
        with self.assertRaisesRegex(ValueError,'duplicate archive member'):c.archive([('same.obj',tiny()),('same.obj',tiny('_other'))])
        raw=bytearray(c.archive([('one.obj',tiny())]));struct.pack_into('>I',raw,72,0)
        with self.assertRaisesRegex(ValueError,'member offset'):c.read_archive(bytes(raw))
        raw=c.archive([('one.obj',tiny())])
        with self.assertRaises(ValueError):c.read_archive(raw[:-1])


if __name__=='__main__':unittest.main()
