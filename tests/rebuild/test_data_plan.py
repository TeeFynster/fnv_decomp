"""Only original, tiny synthetic PE fixtures; no compiler or game input required."""
import io
import json
from pathlib import Path
import struct
import sys
import tempfile
import unittest
from contextlib import redirect_stdout
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[2]/'tools/rebuild'))
import data_plan as plan


BASE = 0x400000


def fixture():
    data = bytearray(0xc00)
    data[:2] = b'MZ'
    struct.pack_into('<I', data, 0x3c, 0x80)
    data[0x80:0x84] = b'PE\0\0'
    struct.pack_into('<HHIIIHH', data, 0x84, 0x14c, 4, 0, 0, 0, 224, 0x102)
    optional = 0x98
    struct.pack_into('<H', data, optional, 0x10b)
    struct.pack_into('<I', data, optional+28, BASE)
    struct.pack_into('<II', data, optional+32, 0x1000, 0x200)
    struct.pack_into('<II', data, optional+56, 0x5000, 0x400)
    struct.pack_into('<I', data, optional+92, 16)
    struct.pack_into('<II', data, optional+96+5*8, 0x4000, 36)
    struct.pack_into('<II', data, optional+96+12*8, 0x2040, 8)
    sections = [(b'.text',0x100,0x1000,0x200,0x400,0x60000020),
                (b'.rdata',0x200,0x2000,0x200,0x600,0x40000040),
                (b'.data',0x300,0x3000,0x200,0x800,0xc0000040),
                (b'.reloc',0x200,0x4000,0x200,0xa00,0x42000040)]
    for i,(name,vs,rva,rs,raw,flags) in enumerate(sections):
        struct.pack_into('<8sIIIIIIHHI',data,optional+224+i*40,name,vs,rva,rs,raw,0,0,0,0,flags)
    for i, value in enumerate([BASE+0x1000,BASE+0x1004,BASE+0x2040]):
        struct.pack_into('<I',data,0x600+4*i,value)
    for i, value in enumerate([BASE+0x5000,BASE+0x4010,BASE+0x1080,BASE+0x1082,BASE+0x1060]):
        struct.pack_into('<I',data,0x800+4*i,value)
    struct.pack_into('<II4H',data,0xa00,0x2000,16,0x3000,0x3004,0x3008,0)
    struct.pack_into('<II6H',data,0xa10,0x3000,20,0x3000,0x3004,0x3008,0x300c,0x3010,0)
    return data


class DataPlanTests(unittest.TestCase):
    def setUp(self):
        self.temporary = tempfile.TemporaryDirectory()
        self.addCleanup(self.temporary.cleanup)
        self.root = Path(self.temporary.name)
        self.image = self.root/'owned.exe'
        self.recipes = self.root/'units.json'
        self.recipes.write_text(json.dumps(dict(units=[dict(source='original_fixture.cpp',
            compiler='sp1', flags=[], functions=[dict(address=hex(BASE+0x1000),size=16,symbol='_fixture')],
            eh_tails=[dict(address=hex(BASE+0x1080),size=8)])])))
        self.write(fixture())

    def write(self, data):
        self.image.write_bytes(data)

    def analyze(self, **kwargs):
        return plan.analyze(self.image,self.recipes,**kwargs)

    def test_classes_widths_zero_fill_and_no_approval(self):
        detail = io.StringIO()
        report = self.analyze(details=detail)
        expected = {'ordinary-entry':1,'ordinary-interior':1,'import-IAT':1,'outside-image':1,
                    'unmapped-metadata':1,'EH-entry':1,'EH-interior':1,'other-code':1}
        self.assertEqual(report['fixups']['by_target'],expected)
        self.assertEqual(report['fixups']['approved_semantic_fixups'],0)
        self.assertEqual(report['fixups']['unapproved_semantic_fixups'],8)
        self.assertFalse(report['runtime_ready'])
        self.assertEqual(next(s for s in report['selected_sections'] if s['name']=='.data')['zero_fill'],256)
        rows = [json.loads(x) for x in detail.getvalue().splitlines()]
        self.assertTrue(all(row[4]==4 for row in rows))
        self.assertIn('preserve-IAT-indirection',next(r for r in rows if r[2]=='import-IAT')[6])
        self.assertIn('target-unresolved',next(r for r in rows if r[2]=='outside-image')[6])

    def test_wrong_machine(self):
        data = fixture(); struct.pack_into('<H',data,0x84,0x8664); self.write(data)
        with self.assertRaises(plan.PlanError): self.analyze()

    def test_truncated_file(self):
        self.write(fixture()[:-1])
        with self.assertRaises(plan.PlanError): self.analyze()

    def test_malformed_relocation_block(self):
        for length in (0,7,9,1000):
            with self.subTest(length=length):
                data = fixture(); struct.pack_into('<I',data,0xa04,length); self.write(data)
                with self.assertRaises(plan.PlanError): self.analyze()

    def test_unknown_relocation_rejected(self):
        data = fixture(); struct.pack_into('<H',data,0xa08,0x7000); self.write(data)
        with self.assertRaises(plan.PlanError): self.analyze()

    def test_overlapping_fixup_fields_rejected(self):
        data = fixture(); struct.pack_into('<H',data,0xa0a,0x3002); self.write(data)
        with self.assertRaises(plan.PlanError): self.analyze()

    def test_fixup_crossing_virtual_bounds_rejected(self):
        data = fixture(); struct.pack_into('<H',data,0xa08,0x31ff); self.write(data)
        with self.assertRaises(plan.PlanError): self.analyze()

    def test_virtual_zero_fill_fixup_is_unknown(self):
        data = fixture(); struct.pack_into('<H',data,0xa18,0x3200); self.write(data)
        report = self.analyze()
        self.assertEqual(report['fixups']['blockers']['zero-fill-fixup-unapproved'],1)
        self.assertFalse(report['runtime_ready'])

    def test_mixed_code_data_section_excluded(self):
        data = fixture(); header=0x98+224+40; struct.pack_into('<I',data,header+36,0x40000060); self.write(data)
        report = self.analyze()
        self.assertNotIn('.rdata',[s['name'] for s in report['selected_sections']])
        self.assertTrue(next(s for s in report['excluded_sections'] if s['name']=='.rdata')['executable'])
        self.assertEqual(report['fixups']['nonexec_data_sites'],5)

    def test_section_overlap_rejected(self):
        data = fixture(); struct.pack_into('<I',data,0x98+224+2*40+12,0x2080); self.write(data)
        with self.assertRaises(plan.PlanError): self.analyze()

    def test_nonexec_identity_reference_mismatch(self):
        reference=self.root/'reference.exe'; data=fixture(); data[0x850]=1; reference.write_bytes(data)
        with self.assertRaisesRegex(plan.PlanError,'identities differ'): self.analyze(reference=reference)

    def test_matching_nonexec_provenance_without_reading_code(self):
        reference=self.root/'reference.exe'; data=fixture(); data[0x450]=1; reference.write_bytes(data)
        report=self.analyze(reference=reference)
        self.assertTrue(report['provenance']['reference_nonexec_equal'])
        self.assertFalse(report['provenance']['owned_image_executable_payloads_read'])

    def test_reference_code_section_header_mismatch_rejected(self):
        reference=self.root/'reference.exe'; data=fixture()
        struct.pack_into('<I',data,0x98+224+8,0x101)
        reference.write_bytes(data)
        with self.assertRaisesRegex(plan.PlanError,'headers differ'): self.analyze(reference=reference)

    def test_reference_complete_section_header_compared(self):
        reference=self.root/'reference.exe'; data=fixture()
        struct.pack_into('<I',data,0x98+224+24,0x1234)
        reference.write_bytes(data)
        with self.assertRaisesRegex(plan.PlanError,'headers differ'): self.analyze(reference=reference)

    def test_size_of_headers_must_cover_actual_headers(self):
        for size in (0x200,0x5001):
            data=fixture(); struct.pack_into('<I',data,0x98+60,size); self.write(data)
            with self.assertRaisesRegex(plan.PlanError,'SizeOfHeaders'): self.analyze()

    def test_failed_analysis_does_not_publish_detail(self):
        data=fixture(); struct.pack_into('<H',data,0xa08,0x7000); self.write(data)
        output,detail=self.root/'new.json',self.root/'new.jsonl.gz'
        args=['data_plan.py','--image',str(self.image),'--recipes',str(self.recipes),
              '--out',str(output),'--details-gz',str(detail)]
        with patch.object(sys,'argv',args),redirect_stdout(io.StringIO()):
            self.assertEqual(plan.main(),1)
        self.assertFalse(output.exists())
        self.assertFalse(detail.exists())

    def test_never_overwrites_inputs_or_existing_reports(self):
        for output in (self.image,self.recipes):
            with self.assertRaises(plan.PlanError): plan.distinct_outputs([self.image,self.recipes],[output])
        with self.assertRaises(plan.PlanError): plan.distinct_outputs([],[self.root/'new.json',self.root/'new.json'])

    def test_overlapping_EH_interiors_are_explicitly_ambiguous(self):
        recipe=json.loads(self.recipes.read_text())
        recipe['units'][0]['eh_tails'].append(dict(address=hex(BASE+0x107e),size=8))
        self.recipes.write_text(json.dumps(recipe))
        report=self.analyze()
        self.assertEqual(report['fixups']['by_target']['EH-entry'],1)
        self.assertEqual(report['fixups']['by_target']['EH-interior-ambiguous'],1)
        self.assertFalse(report['runtime_ready'])


if __name__=='__main__': unittest.main()
