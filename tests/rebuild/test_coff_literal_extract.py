"""Synthetic COFF/proof failures only; no game payload or native execution."""
import copy
import hashlib
import json
from pathlib import Path
import struct
import sys
import tempfile
import unittest
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[2]/'tools/rebuild'))
import coff_literal_extract as extract


def synthetic_object():
    """Invented zero-filled parent; real format/metadata, never executable."""
    strings, records = bytearray(4), bytearray()
    def symbol(name, value, section, typ, storage, aux=b''):
        encoded = name.encode()
        if len(encoded) > 8:
            rawname = struct.pack('<II', 0, len(strings))
            strings.extend(encoded+b'\0')
        else:
            rawname = encoded.ljust(8, b'\0')
        records.extend(struct.pack('<8sIhHBB', rawname, value, section, typ, storage, bool(aux)))
        records.extend(aux)
    symbol('@comp.id', 8681481, -1, 0, 3)
    symbol('@feat.00', 1, -1, 0, 3)
    data = {1: (' '.join(extract.DEFAULTS)).encode().ljust(47, b' '), 24: bytes(55),
            25: bytes.fromhex('3fe570a3e0000000')[::-1], 26: bytes.fromhex('3fe8000000000000')[::-1]}
    relocs = {24: [(9, 12, 6), (31, 12, 6), (37, 9, 6)]}
    names = {1: '.drectve', 24: '.text', 25: '.rdata', 26: '.rdata'}
    flags = {1: 0x00100a00, 24: 0x60501020, 25: 0x40401040, 26: 0x40401040}
    for index in (1, 24, 25, 26):
        selection = 0 if index == 1 else 1 if index == 24 else 2
        aux = struct.pack('<IHHIhBBH', len(data[index]), len(relocs.get(index, [])), 0, 0, 0, selection, 0, 0)
        symbol(names[index], 0, index, 0, 3, aux)
        if index != 1:
            symbol(extract.PARENT if index == 24 else extract.LITERALS[index], 0, index, 32 if index == 24 else 0, 2)
    headers, body, cursor = bytearray(), bytearray(), 20+26*40
    offsets = {}
    for index in range(1, 27):
        content = data.get(index, b'\0')
        offsets[index] = cursor
        raw = cursor
        body.extend(content)
        cursor += len(content)
        relptr = cursor if relocs.get(index) else 0
        for off, target, kind in relocs.get(index, []):
            body.extend(struct.pack('<IIH', off, target, kind))
            cursor += 10
        headers.extend(struct.pack('<8sIIIIIIHHI', names.get(index, '.dummy').encode(), 0, 0, len(content), raw,
                                   relptr, 0, len(relocs.get(index, [])), 0, flags.get(index, 0x40000040)))
    struct.pack_into('<I', strings, 0, len(strings))
    return bytearray(struct.pack('<HHIIIHH', 0x14c, 26, 0, cursor, 13, 0, 0)+headers+body+records+strings), offsets, cursor


class LiteralExtractTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        self.path = self.root/'invented.obj'
        self.data, self.offsets, self.symptr = synthetic_object()
        self.path.write_bytes(self.data)

    def transform(self):
        return extract.transform(self.path)

    def test_exact_data_and_symbol_remapping_strict_reparse(self):
        data, ledger = self.transform()
        out = self.root/'selected.obj'
        out.write_bytes(data)
        extract.reparse(self.path, out, ledger)
        coff, _, _, _ = extract.strict_object(out)
        self.assertEqual([s['name'] for s in coff.sections.values()], ['.drectve', '.text', '.rdata', '.rdata'])
        self.assertEqual([(off, coff.symbols[idx]['name'], kind) for off, idx, kind in coff.sections[2]['relocs']], extract.EDGES)
        self.assertFalse([s for s in coff.symbols.values() if s['section'] == 0])

    def test_changed_or_missing_literal_rejected(self):
        for offset, value in ((self.offsets[25], 1), (self.symptr+9*18+12, 0)):
            data = bytearray(self.data)
            data[offset] = value
            self.path.write_bytes(data)
            with self.assertRaises(ValueError): self.transform()

    def test_literal_protection_or_shared_code_rejected(self):
        for index, flags in ((25, 0xc0401040), (26, 0x60401040), (24, 0x60500020)):
            data = bytearray(self.data)
            struct.pack_into('<I', data, 20+(index-1)*40+36, flags)
            self.path.write_bytes(data)
            with self.assertRaises(ValueError): self.transform()

    def test_nonzero_addend_rejected(self):
        struct.pack_into('<I', self.data, self.offsets[24]+9, 4)
        self.path.write_bytes(self.data)
        with self.assertRaisesRegex(ValueError, 'addend'): self.transform()

    def test_unknown_relocation_rejected(self):
        struct.pack_into('<H', self.data, self.offsets[24]+55+8, 7)
        self.path.write_bytes(self.data)
        with self.assertRaisesRegex(ValueError, 'runtime edge'): self.transform()

    def test_crossing_relocation_rejected(self):
        struct.pack_into('<I', self.data, self.offsets[24]+55, 53)
        self.path.write_bytes(self.data)
        with self.assertRaises(ValueError): self.transform()

    def test_changed_feature_metadata_rejected(self):
        for index, value in ((0, 8681482), (1, 0), (1, 3)):
            data = bytearray(self.data)
            struct.pack_into('<I', data, self.symptr+index*18+8, value)
            self.path.write_bytes(data)
            with self.assertRaisesRegex(ValueError, 'metadata'): self.transform()

    def test_hidden_child_or_tls_rejected(self):
        for kind in ('child', 'tls'):
            data = bytearray(self.data)
            if kind == 'tls':
                data[20+40:20+40+8] = b'.tls\0\0\0\0'
                self.path.write_bytes(data)
                with self.assertRaisesRegex(ValueError, 'TLS'): self.transform()
            else:
                coff, _, _, _ = extract.strict_object(self.path)
                coff.sections[2].update(association=24, selection='associative')
                with patch.object(extract, 'strict_object', return_value=(coff, self.symptr, None, None)):
                    with self.assertRaisesRegex(ValueError, 'child'): self.transform()

    def test_unknown_directive_or_aux_record_rejected(self):
        self.data[self.offsets[1]] = ord('!')
        self.path.write_bytes(self.data)
        with self.assertRaisesRegex(ValueError, 'directive'): self.transform()
        self.data, _, _ = synthetic_object()
        struct.pack_into('<H', self.data, self.symptr+5*18+6, 1)
        self.path.write_bytes(self.data)
        with self.assertRaisesRegex(ValueError, 'auxiliary'): self.transform()

    def test_reparse_detects_payload_change(self):
        data, ledger = self.transform()
        out = self.root/'out.obj'
        changed = bytearray(data)
        coff_header_size = 20+4*40
        changed[coff_header_size+47] = 1
        out.write_bytes(changed)
        with self.assertRaisesRegex(ValueError, 'payload'): extract.reparse(self.path, out, ledger)

    def test_unapproved_input_hash_rejected_before_oracle(self):
        paths = [self.root/name for name in ('manifest.json', 'selection.json', 'verification.json', 'image.exe')]
        for path in paths:
            path.write_text('unapproved')
        with patch.object(extract, 'compare_component') as compare:
            with self.assertRaisesRegex(ValueError, 'stale approved'): extract.verify_basis(*paths)
            compare.assert_not_called()

    def test_extraction_requires_direct_proof_and_new_outputs(self):
        out, receipt = self.root/'out.obj', self.root/'receipt.json'
        with patch.object(extract, 'verify_basis', side_effect=ValueError('stale proof')):
            with self.assertRaisesRegex(ValueError, 'stale proof'): extract.extract('m', 's', 'v', 'i', out, receipt)
        self.assertFalse(out.exists())
        self.assertFalse(receipt.exists())
        out.write_text('preserve')
        with patch.object(extract, 'verify_basis') as verify:
            with self.assertRaises(ValueError): extract.extract('m', 's', 'v', 'i', out, receipt)
            verify.assert_not_called()

    def test_stale_evidence_after_transform_publishes_nothing(self):
        protected = self.root/'protected.txt'
        protected.write_text('original')
        basis = dict(inputs={str(protected): '0'*64}, object=str(self.path), image='not-run', unit={})
        with patch.object(extract, 'verify_basis', return_value=basis), patch.object(extract, 'compare_component', return_value={}):
            with self.assertRaisesRegex(ValueError, 'changed during'): extract.extract('m','s','v','i',self.root/'out.obj',self.root/'out.json')
        self.assertFalse((self.root/'out.obj').exists())
        self.assertFalse((self.root/'out.json').exists())


if __name__ == '__main__':
    unittest.main()
