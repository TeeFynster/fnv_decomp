"""Original synthetic data/format/review tests; no native process or game input."""
import copy
import json
from pathlib import Path
import struct
import sys
import tempfile
import unittest
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[2]/'tools/rebuild'))
import data_fixture as fixture
from test_data_plan import fixture as pe_template


class DataFixtureTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        self.pe = self.root/'original.exe'
        self.mp = self.root/'original.map'
        data = pe_template()
        # Fixed source fixture ownership: payload at .data+0 and zero at +64.
        struct.pack_into('<I', data, 0x98+56, 0x7000)
        struct.pack_into('<I', data, 0x98+224+2*40+8, 0x2400)
        struct.pack_into('<I', data, 0x98+224+3*40+12, 0x6000)
        struct.pack_into('<II', data, 0x98+96+5*8, 0x6000, 36)
        data[0x800:0x820] = fixture.expected_payload(0x40300a, 0x401000)
        struct.pack_into('<II6H', data, 0xa10, 0x3000, 20, 0x3010, 0x3014, 0, 0, 0, 0)
        self.data = data
        self.pe.write_bytes(data)
        self.mp.write_text('\n'.join(' 0003:%08x %s %08x producer.obj' % (off, name, address)
            for off, name, address in [(0, fixture.PAYLOAD, 0x403000), (64, fixture.ZERO, 0x403040), (0, fixture.CALLBACK, 0x401000)]))

    def inspect(self):
        return fixture.inspect_data(self.pe, self.mp, 'producer.obj', 0x400000)

    def test_data_coff_has_symbolic_addends_and_no_code(self):
        payload, evidence = self.inspect()
        self.assertEqual(evidence['owned_ranges'][1]['virtual_zero_bytes'], 7744)
        path = self.root/'data.obj'
        path.write_bytes(fixture.coff_bytes(payload))
        self.assertEqual(fixture.validate_object(path)['undefined_symbols'], [fixture.CALLBACK])
        coff, _, _, _ = fixture.strict_object(path)
        self.assertEqual(struct.unpack_from('<III', coff.data, 100+16), (10, 0, 0x00401234))
        self.assertEqual(coff.sections[2]['size'], 8192)
        self.assertEqual(coff.sections[2]['relocs'], [])

    def test_unknown_pointer_target_rejected(self):
        struct.pack_into('<I', self.data, 0x814, 0x401004)
        self.pe.write_bytes(self.data)
        with self.assertRaisesRegex(ValueError, 'values differ'): self.inspect()

    def test_nonrelocated_address_shaped_numeric_preserved(self):
        payload, _ = self.inspect()
        self.assertEqual(struct.unpack_from('<I', fixture.coff_bytes(payload), 124)[0], 0x00401234)

    def test_missing_or_extra_pointer_site_rejected(self):
        for position, entry in [(0xa18, 0), (0xa1c, 0x3018)]:
            with self.subTest(position=position):
                data = bytearray(self.data)
                struct.pack_into('<H', data, position, entry)
                self.pe.write_bytes(data)
                with self.assertRaisesRegex(ValueError, 'pointer relocation'): self.inspect()

    def test_boundary_crossing_rejected(self):
        data = bytearray(self.data)
        struct.pack_into('<H', data, 0xa1c, 0x301e)
        self.pe.write_bytes(data)
        with self.assertRaisesRegex(ValueError, 'boundary-crossing'): self.inspect()

    def test_unsupported_relocation_rejected(self):
        struct.pack_into('<H', self.data, 0xa18, 0x7010)
        self.pe.write_bytes(self.data)
        with self.assertRaisesRegex(ValueError, 'unsupported'): self.inspect()

    def test_executable_or_mixed_data_rejected(self):
        for flags in (0xe0000040, 0xc0000060):
            struct.pack_into('<I', self.data, 0x98+224+2*40+36, flags)
            self.pe.write_bytes(self.data)
            with self.assertRaisesRegex(ValueError, 'non-executable'): self.inspect()

    def test_tls_and_iat_rejected(self):
        for index, rva, size in [(9, 0x2000, 24), (12, 0x3000, 8)]:
            data = bytearray(self.data)
            struct.pack_into('<II', data, 0x98+96+index*8, rva, size)
            self.pe.write_bytes(data)
            with self.assertRaises(ValueError): self.inspect()

    def test_overlapping_owned_ranges_rejected(self):
        self.mp.write_text(self.mp.read_text().replace('00403040', '00403010'))
        with self.assertRaisesRegex(ValueError, 'overlapping'): self.inspect()

    def test_source_zero_initialization_rejected_if_nonzero(self):
        self.data[0x850] = 1
        self.pe.write_bytes(self.data)
        with self.assertRaisesRegex(ValueError, 'loader-zero'): self.inspect()

    def test_map_owner_and_duplicate_rejected(self):
        original = self.mp.read_text()
        for text in (original.replace('producer.obj', 'foreign.obj'), original+'\n'+original):
            self.mp.write_text(text)
            with self.assertRaises(ValueError): self.inspect()

    def test_requires_actual_virtual_zero(self):
        # A wholly raw-backed short range is not accepted as virtual-zero proof.
        with patch.object(fixture, 'ZERO_SIZE', 64):
            with self.assertRaisesRegex(ValueError, 'no actual PE virtual-zero'): self.inspect()

    def test_invalid_payload_length_rejected(self):
        with self.assertRaises(ValueError): fixture.coff_bytes(bytes(31))

    def review_pair(self):
        prepared = dict(schema_version=1, kind='original-data-fixture-prepared', policy=fixture.POLICY,
            execution_performed=False, status='prepared_pending_independent_review', exe_sha256='e'*64, map_sha256='a'*64)
        review = dict(schema_version=1, kind='original-data-fixture-review', approved=True,
            prepare_sha256='b'*64, reviewer='independent', exe_sha256='e'*64, map_sha256='a'*64,
            checks={k: True for k in ('data_ownership', 'linked_fixups', 'virtual_zero', 'normal_crt', 'map_and_imports')})
        return prepared, review

    def test_exact_review_required(self):
        p, r = self.review_pair()
        fixture.validate_review(p, r, 'b'*64)
        for key, value in [('approved', False), ('prepare_sha256', 'c'*64), ('exe_sha256', 'd'*64), ('checks', {})]:
            bad = copy.deepcopy(r)
            bad[key] = value
            with self.assertRaises(ValueError): fixture.validate_review(p, bad, 'b'*64)

    def test_changed_inputs_and_collisions_never_execute(self):
        p, r = self.review_pair()
        exe = self.root/'consumer.exe'
        exe.write_text('never run')
        pp, rp, out = [self.root/n for n in ('prepare.json', 'review.json', 'execute.json')]
        p.update(inputs={str(exe): '0'*64}, artifacts={}, os_dependencies={}, exe=str(exe))
        fixture.save(pp, p)
        r['prepare_sha256'] = fixture.sha(pp)
        fixture.save(rp, r)
        with patch.object(fixture.subprocess, 'run') as run:
            result = fixture.execute(pp, rp, fixture.sha(rp), out)
            self.assertEqual(result['status'], 'error')
            run.assert_not_called()
            with self.assertRaises(ValueError): fixture.execute(pp, rp, fixture.sha(rp), pp)
            with self.assertRaises(ValueError): fixture.execute(pp, rp, fixture.sha(rp), out)


if __name__ == '__main__':
    unittest.main()
