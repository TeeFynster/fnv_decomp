"""Original synthetic linkage/closure fixtures; never executes a game binary."""
import json
from pathlib import Path
import struct
import sys
import tempfile
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[2] / 'tools/rebuild'))
import game_leaf_probe as probe


def original_object():
    directives = b' /DEFAULTLIB:"LIBCMT" /DEFAULTLIB:"OLDNAMES" '
    start = 100
    code_start = start + len(directives)
    symptr = code_start + 4
    strings = b'\0' * 4 + probe.OLD.encode('ascii') + b'\0'
    strings = struct.pack('<I', len(strings)) + strings[4:]
    symbols = (struct.pack('<8sIhHBB', b'.text\0\0\0', 0, 2, 0, 3, 1) +
        struct.pack('<IHHIhBBH', 4, 0, 0, 0, 0, 1, 0, 0) +
        struct.pack('<8sIhHBB', struct.pack('<II', 0, 4), 0, 2, 0x20, 2, 0))
    return (struct.pack('<HHIIIHH', 0x14c, 2, 0, symptr, 3, 0, 0) +
        struct.pack('<8sIIIIIIHHI', b'.drectve', 0, 0, len(directives), start, 0, 0, 0, 0, 0x100a00) +
        struct.pack('<8sIIIIIIHHI', b'.text\0\0\0', 0, 0, 4, code_start, 0, 0, 0, 0, 0x60001020) +
        directives + bytes(4) + symbols + strings)


class LeafTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        self.obj = self.root / 'fixture.obj'
        self.obj.write_bytes(original_object())

    def test_whole_object_initializer_and_leaf_audit(self):
        result = probe.audit_object(self.obj)
        self.assertEqual(result['size'], 4)
        self.assertEqual(result['relocation_count'], 0)
        self.assertTrue(result['no_initializer_tls_eh_roots'])
        self.assertEqual(result['whole_object_sections'], ['.drectve', '.text'])

    def test_unreviewed_initializer_section_rejected(self):
        data = bytearray(self.obj.read_bytes())
        data[20:28] = b'.CRT$XCU'
        self.obj.write_bytes(data)
        with self.assertRaisesRegex(ValueError, 'unreviewed'):
            probe.audit_object(self.obj)

    def test_changed_leaf_body_size_rejected(self):
        data = bytearray(self.obj.read_bytes())
        struct.pack_into('<I', data, 60 + 16, 5)
        self.obj.write_bytes(data)
        with self.assertRaisesRegex(ValueError, 'contract'):
            probe.audit_object(self.obj)

    def test_map_rejects_unrelated_game_provider(self):
        line = ' 0001:00000010 ' + probe.NEW + ' 00401010 f leaf.obj\n'
        self.assertEqual(probe.map_leaf(line), 0x401010)
        with self.assertRaisesRegex(ValueError, 'unexpected'):
            probe.map_leaf(line + ' 0001:00000020 ?Other@@YAXXZ 00401020 f leaf.obj\n')
        with self.assertRaises(ValueError):
            probe.map_leaf('')

    def test_unresolved_symbols_reported_not_stubbed(self):
        text = ('leaf.obj : error LNK2019: unresolved external symbol "void function" (?Missing@@YAXXZ) referenced in function "other" (?Other@@YAXXZ)\n'
                'fatal error LNK1120: 1 unresolved externals\n')
        result = probe.link_blockers(text, {'?Missing@@YAXXZ': '0x00123456'})
        self.assertEqual(result[0]['symbol'], '?Missing@@YAXXZ')
        self.assertEqual(result[0]['original_binding'], '0x00123456')
        self.assertEqual(len(result), 1)

    def test_counts_only_receipt_cannot_authorize_leaf(self):
        receipt = self.root / 'basis.json'
        receipt.write_text('{}')
        unit = dict(recipe_index=0, recipe_id='one', object_sha256='hash')
        verification = dict(schema_version=1, kind='fnv-retained-object-verification',
            retained_verification_pass=True, function_byte_verification_pass=True,
            global_listed_eh_coverage_pass=True, original_oracle_parity_pass=True, evidence_stable=True,
            scope=dict(full_authoritative=True), units=[dict(unit, functions=1, matched_functions=1)])
        with self.assertRaisesRegex(ValueError, 'specific leaf proof'):
            probe.verify_basis(dict(units=[unit]), verification, probe.sha(receipt), receipt)
        verification['units'][0]['verified_functions'] = [dict(symbol=probe.OLD,
            address=probe.ADDRESS, size=4, section=13, value=0, verdict='match')]
        self.assertEqual(probe.verify_basis(dict(units=[unit]), verification, probe.sha(receipt), receipt), unit)
        verification['units'][0]['eh_errors'] = ['local note']
        with self.assertRaisesRegex(ValueError, 'local EH'):
            probe.verify_basis(dict(units=[unit]), verification, probe.sha(receipt), receipt)

    def test_receipt_hash_and_incomplete_basis_rejected(self):
        receipt = self.root / 'basis.json'
        receipt.write_text('{}')
        with self.assertRaisesRegex(ValueError, 'hash differs'):
            probe.verify_basis({}, {}, 'wrong', receipt)
        with self.assertRaisesRegex(ValueError, 'unsupported'):
            probe.verify_basis({}, {}, probe.sha(receipt), receipt)

    def test_execution_requires_successful_independently_reviewed_link(self):
        (self.root / 'link-receipt.json').write_text(json.dumps(dict(kind='source-built-game-leaf-link-probe', status='error')))
        with self.assertRaisesRegex(ValueError, 'reviewed map hash'):
            probe.execute_reviewed(self.root, 'unreviewed')
        self.assertFalse((self.root / 'execution-receipt.json').exists())


if __name__ == '__main__':
    unittest.main()
