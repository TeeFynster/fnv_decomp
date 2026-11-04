"""Authored PE metadata only; never an original executable or native process."""
from pathlib import Path
import struct
import sys
import tempfile
import unittest
from unittest.mock import patch
sys.path.insert(0,str(Path(__file__).resolve().parents[2]/'tools/rebuild'))
import local_label_observe as o


def pe_fixture(entries=(0x3010,0x3020)):
    raw=bytearray(1024);raw[:2]=b'MZ';struct.pack_into('<I',raw,60,64)
    raw[64:68]=b'PE\0\0';struct.pack_into('<HHIIIHH',raw,68,0x14c,1,0,0,0,224,0)
    struct.pack_into('<H',raw,88,0x10b);struct.pack_into('<I',raw,88+28,0x01000000)
    struct.pack_into('<I',raw,88+92,16);extent=8+2*len(entries)
    struct.pack_into('<II',raw,88+136,0x3000,extent)
    struct.pack_into('<8sIIIIIIHHI',raw,312,b'.reloc\0\0',512,0x3000,512,512,0,0,0,0,0x42000040)
    struct.pack_into('<II',raw,512,0x1000,extent)
    for i,e in enumerate(entries):struct.pack_into('<H',raw,520+i*2,e)
    return raw


class ReadOnlyMetadataTests(unittest.TestCase):
    def test_fixed_operand_scope_reads_exactly_one_reviewed_field(self):
        raw=pe_fixture();raw.extend(bytes(8192-len(raw)));old=bytes(raw[312:352]);raw[352:392]=old
        struct.pack_into('<H',raw,70,2);struct.pack_into('<I',raw,88+28,0x00400000)
        struct.pack_into('<8sIIIIIIHHI',raw,312,b'.text\0\0\0',4096,0x623000,4096,1024,0,0,0,0,0x60000020)
        struct.pack_into('<I',raw,1024+0x50f,0x11223344)
        with tempfile.TemporaryDirectory() as td:
            path=Path(td)/'authored-pe.bin';path.write_bytes(raw)
            self.assertEqual(o.read_fixed_operand(path,'0x00a2350f'),0x11223344)
            with self.assertRaises(ValueError):o.read_fixed_operand(path,'0x00a23510')
            raw[312:320]=b'.data\0\0\0';path.write_bytes(raw)
            with self.assertRaises(ValueError):o.read_fixed_operand(path,'0x00a2350f')

    def read(self,raw):
        with tempfile.TemporaryDirectory() as td:
            p=Path(td)/'authored-pe.bin';p.write_bytes(raw);return o.read_highlow_sites(p)

    def test_exact_highlow_metadata_and_absolute_padding(self):
        sites,r=self.read(pe_fixture((0x3010,0)))
        self.assertEqual(sites,{0x01001010});self.assertEqual(r['blocks'],1)
        self.assertFalse(r['original_text_payload_observed'])

    def test_unknown_type_duplicate_and_bad_extent_rejected(self):
        for entries in ((0x3010,0x3010),(0x5010,0),(0x3010,)):
            with self.subTest(entries=entries),self.assertRaises(ValueError):self.read(pe_fixture(entries))

    def test_code_section_or_directory_in_code_rejected(self):
        for mutate in ('name','flags'):
            raw=pe_fixture()
            if mutate=='name':raw[312:320]=b'.text\0\0\0'
            else:struct.pack_into('<I',raw,312+36,0x62000040)
            with self.subTest(mutate=mutate),self.assertRaises(ValueError):self.read(raw)

    def test_publication_flush_stability_and_input_drift_cleanup(self):
        with tempfile.TemporaryDirectory() as td:
            p=Path(td)/'receipt.json';calls=[]
            o.publish_report(p,{'authored':True},lambda:calls.append('checked'))
            self.assertEqual(calls,['checked','checked']);self.assertTrue(p.exists());p.unlink()
            count=[0]
            def drift():
                count[0]+=1
                if count[0]==2:raise ValueError('authored drift')
            with self.assertRaisesRegex(ValueError,'drift'):o.publish_report(p,{},drift)
            self.assertFalse(p.exists())

    def test_publication_fsync_failure_cleans_only_owned_output(self):
        with tempfile.TemporaryDirectory() as td:
            p=Path(td)/'receipt.json'
            with patch.object(o.os,'fsync',side_effect=OSError('authored fsync failure')):
                with self.assertRaises(OSError):o.publish_report(p,{},lambda:None)
            self.assertFalse(p.exists());p.write_text('preexisting')
            with self.assertRaises(FileExistsError):o.publish_report(p,{},lambda:None)
            self.assertEqual(p.read_text(),'preexisting')

    def test_unbacked_truncated_and_oversized_metadata_rejected(self):
        for mutate in ('backing','directory','header','signature'):
            raw=pe_fixture()
            if mutate=='backing':struct.pack_into('<I',raw,312+20,1020)
            elif mutate=='directory':struct.pack_into('<I',raw,88+140,o.MAX_DIRECTORY+1)
            elif mutate=='header':struct.pack_into('<I',raw,60,1010)
            else:raw[64]=0
            with self.subTest(mutate=mutate),self.assertRaises(ValueError):self.read(raw)


if __name__=='__main__':unittest.main()
