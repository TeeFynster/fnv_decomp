"""Fixed original-source overlay guards; no compiler or game required."""
import copy
import json
from pathlib import Path
import struct
import sys
import tempfile
import unittest
sys.path.insert(0,str(Path(__file__).resolve().parents[2]/'tools/rebuild'))
import runtime_source_overlay as o
from coff_inventory import Coff


def synthetic_object(overlay=False, *, behavior_change=False,base_change=False,duplicate_carrier=False):
    code=bytearray(b'\x90'*25);struct.pack_into('<I',code,4,0);struct.pack_into('<I',code,10,0 if overlay else 0x10a2304)
    if behavior_change:code[15]^=1
    names=[o.EXPECTED['function']['symbol'],'??0NiObject@@QAE@XZ' if not base_change else '_wrong_base',o.EXPECTED['target_symbol']]
    if duplicate_carrier:names.append(o.EXPECTED['target_symbol'])
    records=bytearray();strings=bytearray(struct.pack('<I',4))
    for i,name in enumerate(names):
        off=len(strings);strings.extend(name.encode()+b'\0')
        records.extend(struct.pack('<IIIhHBB',0,off,0,1 if i in (0,3) else 0,32 if i==0 else 0,2,0))
    struct.pack_into('<I',strings,0,len(strings));rels=[(4,1,20)]+([(10,2,6)] if overlay else [])
    symptr=60+len(code)+len(rels)*10
    return (struct.pack('<HHIIIHH',0x14c,1,0,symptr,len(names),0,0)+
        struct.pack('<8sIIIIIIHHI',b'.text',0,0,len(code),60,85,0,len(rels),0,0x60000020)+
        code+b''.join(struct.pack('<IIH',*r) for r in rels)+records+strings)


class OverlayTests(unittest.TestCase):
    def setUp(self):
        self.raw=(o.ROOT/o.SOURCE).read_bytes();self.policy=copy.deepcopy(o.EXPECTED)

    def test_one_guarded_span_preserves_every_other_source_byte_and_lines(self):
        new,edit=o.apply_overlay(self.raw,self.policy)
        self.assertEqual(new.replace(o.NEW.encode(),o.OLD.encode(),1),self.raw)
        self.assertEqual(new.count(b'\n'),self.raw.count(b'\n'))
        self.assertIn(b'*(volatile unsigned int*)this = reinterpret_cast<unsigned int>(&DAT_010a2304);',new)
        self.assertEqual(new.count(b'extern int DAT_010a2304;'),2)
        self.assertEqual(edit['start'],self.raw.index(o.OLD.encode()))

    def test_stale_source(self):
        with self.assertRaisesRegex(ValueError,'stale'):o.apply_overlay(self.raw+b'\n',self.policy)

    def test_wrong_span_and_comment_only_occurrence(self):
        for raw in (self.raw.replace(b'    *(volatile',b'     *(volatile',1),self.raw.replace(b'    *(volatile',b'    // *(volatile',1)):
            with self.assertRaisesRegex(ValueError,'guarded'):o.apply_overlay(raw,self.policy)

    def test_duplicate_occurrence(self):
        for raw in (self.raw+o.OLD.encode(),self.raw+b'\n    *(volatile unsigned int*)this = 0x010a2304;\n'):
            with self.assertRaisesRegex(ValueError,'duplicate'):o.apply_overlay(raw,self.policy)

    def test_wrong_target_recipe_and_unauthorized_changes(self):
        for key,value in (('target','0x010a2308'),('recipe_index',1402),('flags',['/Od']),('new_span',o.NEW.replace('volatile ','')),('source','unapproved.cpp')):
            p=copy.deepcopy(self.policy);p[key]=value
            with self.assertRaisesRegex(ValueError,'unauthorized'):o.apply_overlay(self.raw,p)

    def test_fixed_public_policy_equals_supported_contract(self):
        policy=json.loads((o.ROOT/'runtime/source-overlays/niaccumulator-address.json').read_text())
        self.assertEqual(policy,o.EXPECTED)

    def test_include_and_macro_context(self):
        header=(o.ROOT/o.HEADER).read_bytes();o.include_context(self.raw,header)
        for raw,h in ((self.raw+b'\n#include "unapproved.h"\n',header),(self.raw+b'\nint x=__LINE__;\n',header),(self.raw,header+b'\n#include <stdio.h>\n')):
            with self.assertRaises(ValueError):o.include_context(raw,h)

    def test_geometry_accepts_only_one_new_zero_addend_reference(self):
        with tempfile.TemporaryDirectory() as td:
            root=Path(td);before=root/'before.obj';after=root/'after.obj';before.write_bytes(synthetic_object());after.write_bytes(synthetic_object(True))
            proof=o.verify_geometry(Coff(before),Coff(after))
            self.assertTrue(proof['non_field_function_bytes_equal']);self.assertEqual(proof['new_DIR32_field_count'],1)

    def test_changed_volatile_or_member_code_and_base_target_rejected(self):
        with tempfile.TemporaryDirectory() as td:
            root=Path(td);before=root/'before.obj';after=root/'after.obj';before.write_bytes(synthetic_object())
            for data in (synthetic_object(True,behavior_change=True),synthetic_object(True,base_change=True)):
                after.write_bytes(data)
                with self.assertRaises(ValueError):o.verify_geometry(Coff(before),Coff(after))

    def test_wrong_target_and_nonzero_addend_rejected(self):
        with tempfile.TemporaryDirectory() as td:
            root=Path(td);before=root/'before.obj';after=root/'after.obj';before.write_bytes(synthetic_object())
            for mutate in ('target','addend'):
                data=bytearray(synthetic_object(True))
                if mutate=='target':data=data.replace(b'?DAT_010a2304',b'?DAT_010a2308')
                else:struct.pack_into('<I',data,60+10,4)
                after.write_bytes(data)
                with self.assertRaises(ValueError):o.verify_geometry(Coff(before),Coff(after))

    def test_additional_carrier_definition_rejected(self):
        with tempfile.TemporaryDirectory() as td:
            root=Path(td);before=root/'before.obj';after=root/'after.obj'
            before.write_bytes(synthetic_object());after.write_bytes(synthetic_object(True,duplicate_carrier=True))
            with self.assertRaisesRegex(ValueError,'exactly one undefined'):o.verify_geometry(Coff(before),Coff(after))

    def test_generated_source_and_object_drift_rejected(self):
        with tempfile.TemporaryDirectory() as td:
            source,obj=[Path(td)/n for n in ('overlay.cpp','overlay.obj')]
            for changed in (source,obj):
                source.write_bytes(b'source');obj.write_bytes(b'object')
                hs,ho=o.file_hash(source),o.file_hash(obj)
                o.generated_stability(source,obj,hs,ho)
                changed.write_bytes(b'drift')
                with self.assertRaisesRegex(ValueError,'changed during verification'):
                    o.generated_stability(source,obj,hs,ho)

    def test_input_output_collision(self):
        with tempfile.TemporaryDirectory() as td:
            root=Path(td);source=root/'source.cpp';source.write_bytes(b'original')
            for out in (source,root):
                with self.assertRaisesRegex(ValueError,'collision'):o.new_output(out,[source])
            self.assertEqual(o.new_output(root/'new',[source]),root/'new')

    def test_failed_comparison_and_changed_extent_rejected(self):
        row=dict(symbol=o.EXPECTED['function']['symbol'],size=25,compiled_extent=25,verdict='match')
        o.require_match([row])
        for key,value in (('verdict','wip'),('compiled_extent',26),('size',24)):
            bad=dict(row);bad[key]=value
            with self.assertRaisesRegex(ValueError,'comparison/extent'):o.require_match([bad])
        with self.assertRaisesRegex(ValueError,'same-TU'):o.require_match([row,dict(symbol='other',verdict='wip')])

if __name__=='__main__':unittest.main()
