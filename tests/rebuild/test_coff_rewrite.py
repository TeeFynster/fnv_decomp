"""Original synthetic COFF fixtures; no game, compiler or binary inputs."""
import hashlib
import json
from pathlib import Path
import struct
import sys
import tempfile
import unittest
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[2] / 'tools/rebuild'))
import coff_rewrite
from coff_inventory import Coff


def fixture(symbols=None, *, aux=None, reloc_target=2):
    symbols = symbols or [('_old', 0, 1, 2, []), ('_use', 0, 0, 2, [])]
    section_aux = struct.pack('<IHHIhBBH', 4, 1, 0, 0, 0, 1, 0, 0)
    symbols = [('.text', 0, 1, 3, [section_aux] if aux is None else aux)] + symbols
    strings = bytearray(b'\0' * 4)
    records = bytearray()
    count = 0
    for name, value, section, storage, auxiliaries in symbols:
        raw = name.encode('ascii')
        if len(raw) > 8:
            raw = struct.pack('<II', 0, len(strings))
            strings.extend(name.encode('ascii') + b'\0')
        else:
            raw = raw.ljust(8, b'\0')
        records.extend(struct.pack('<8sIhHBB', raw, value, section, 0, storage, len(auxiliaries)))
        records.extend(b''.join(auxiliaries))
        count += 1 + len(auxiliaries)
    struct.pack_into('<I', strings, 0, len(strings))
    return (struct.pack('<HHIIIHH', 0x14c, 1, 0, 74, count, 0, 0) +
            struct.pack('<8sIIIIIIHHI', b'.text\0\0\0', 0, 0, 4, 60, 64, 0, 1, 0, 0x60001020) +
            b'\0' * 4 + struct.pack('<IIH', 0, reloc_target, 6) + records + strings)


class RenameTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        self.input = self.root / 'in.obj'
        self.output = self.root / 'out.obj'
        self.receipt = self.root / 'receipt.json'
        self.provenance = self.root / 'provenance.json'
        self.source = self.root / 'fixture.cpp'
        self.source.write_text('int original_fixture;\n', encoding='ascii')
        self.prepare(fixture())

    def prepare(self, data):
        self.input.write_bytes(data)
        self.hash = hashlib.sha256(data).hexdigest()
        self.provenance.write_text(json.dumps(dict(schema_version=1,
            kind='fnv-coff-rename-provenance', recipe_id='original-synthetic-fixture',
            source=str(self.source), source_sha256=hashlib.sha256(self.source.read_bytes()).hexdigest(),
            object_sha256=self.hash)), encoding='utf-8')

    def run_rewrite(self, **overrides):
        values = dict(input_path=self.input, output_path=self.output, receipt_path=self.receipt,
            provenance_path=self.provenance, expected_sha256=self.hash,
            old_name='_old', new_name='_canonical_definition')
        values.update(overrides)
        return coff_rewrite.rewrite(**values)

    def test_preserves_payload_relocations_auxiliary_and_symbol_indices(self):
        before = Coff(self.input)
        report = self.run_rewrite()
        after = Coff(self.output)
        self.assertEqual(after.sections, before.sections)
        self.assertEqual(set(after.symbols), set(before.symbols))
        self.assertEqual(after.symbols[2]['name'], '_canonical_definition')
        self.assertEqual(after.sections[1]['relocs'], [(0, 2, 6)])
        self.assertEqual(after.sections[1]['selection'], 'no_duplicates')
        self.assertEqual(self.input.read_bytes(), before.data)
        self.assertEqual(report['output_sha256'], hashlib.sha256(after.data).hexdigest())
        self.assertEqual(json.loads(self.receipt.read_text())['status'], 'pass')
        # All earlier bytes except the selected Name field and string length survive.
        allowed = set(range(74 + 2 * 18, 74 + 2 * 18 + 8))
        allowed.update(range(report['edit']['string_table_offset'], report['edit']['string_table_offset'] + 4))
        self.assertTrue(all(a == b or i in allowed for i, (a, b) in enumerate(zip(before.data, after.data))))

    def test_short_new_name_still_appends_string_table(self):
        self.run_rewrite(new_name='_x')
        self.assertEqual(Coff(self.output).symbols[2]['name'], '_x')

    def test_existing_weak_fallback_indices_survive(self):
        weak_aux = struct.pack('<II', 2, 3) + bytes(10)
        self.prepare(fixture([('_old', 0, 1, 2, []), ('_weak', 0, 0, 105, [weak_aux])]))
        self.run_rewrite()
        self.assertEqual(Coff(self.output).symbols[3]['weak']['fallback_index'], 2)
        self.assertEqual(Coff(self.output).symbols[3]['weak']['fallback'], '_canonical_definition')

    def test_hash_and_source_provenance_required(self):
        with self.assertRaisesRegex(ValueError, 'fingerprints'):
            self.run_rewrite(expected_sha256='0' * 64)
        self.source.write_text('changed', encoding='ascii')
        with self.assertRaisesRegex(ValueError, 'source fingerprint'):
            self.run_rewrite()
        self.assertFalse(self.output.exists())

    def test_no_overwrite_or_input_alias(self):
        with self.assertRaisesRegex(ValueError, 'distinct'):
            self.run_rewrite(output_path=self.input)
        with self.assertRaisesRegex(ValueError, 'source'):
            self.run_rewrite(receipt_path=self.source)
        self.output.write_bytes(b'existing')
        with self.assertRaisesRegex(ValueError, 'already exist'):
            self.run_rewrite()
        self.assertEqual(self.output.read_bytes(), b'existing')

    def test_unique_definition_and_new_collision_required(self):
        with self.assertRaisesRegex(ValueError, 'collides'):
            self.run_rewrite(new_name='_use')
        with self.assertRaisesRegex(ValueError, 'exactly one'):
            self.run_rewrite(old_name='_use')
        self.prepare(fixture([('_old', 0, 1, 2, []), ('_old', 0, 1, 2, [])]))
        with self.assertRaisesRegex(ValueError, 'exactly one'):
            self.run_rewrite()

    def test_name_validation_and_import_pointer_rejected(self):
        for name in ('', 'white space', '\x00bad', '__imp__Api@0', '_imp__Api@0', '_old'):
            with self.subTest(name=name), self.assertRaises(ValueError):
                self.run_rewrite(new_name=name)

    def test_malformed_or_unsupported_objects_rejected(self):
        good = fixture()
        overlap = bytearray(good)
        struct.pack_into('<I', overlap, 20 + 20, 74)  # Payload overlaps symbols.
        badaux = fixture(aux=[bytes(18), bytes(18)], reloc_target=3)
        unknownaux = fixture([('_old', 0, 1, 2, [bytes(18)])])
        for data in (good[:-1], b'\0\0\xff\xff' + good[4:], good + b'overlay',
                     bytes(overlap), badaux, unknownaux):
            with self.subTest(size=len(data)):
                self.prepare(data)
                with self.assertRaises((ValueError, struct.error)):
                    self.run_rewrite()
                self.assertFalse(self.output.exists())

    def test_receipt_failure_removes_only_new_artifacts(self):
        original_open = Path.open
        def failing_open(path, mode='r', *args, **kwargs):
            if path == self.receipt and mode == 'x':
                raise OSError('synthetic receipt failure')
            return original_open(path, mode, *args, **kwargs)
        with patch.object(Path, 'open', failing_open):
            with self.assertRaisesRegex(OSError, 'receipt failure'):
                self.run_rewrite()
        self.assertFalse(self.output.exists())
        self.assertFalse(self.receipt.exists())
        self.assertEqual(list(self.root.glob('.coff-rename-*')), [])


if __name__ == '__main__':
    unittest.main()
