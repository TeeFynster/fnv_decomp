"""Fixed source and synthetic COFF checks; no compiler/image/native execution."""
import copy
from pathlib import Path
import struct
import sys
import tempfile
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[2]/'tools/rebuild'))
import entry_relocation_repair as repair
from coff_inventory import Coff


def fixture(spec, overlay=False, *, change=False, kind=6, addend=0, duplicate=False, defined=False):
    size = spec['selection']['size']
    code = bytearray(b'\x90'*size)
    off = spec['function_offset']
    struct.pack_into('<I', code, off, addend if overlay else int(spec['target_va'], 16))
    struct.pack_into('<I', code, 1, 0)
    if change: code[-1] ^= 1
    names = [spec['function'], '_base', spec['same_unit_target_names'][0]]
    if duplicate: names.append(names[-1])
    records = bytearray(); strings = bytearray(struct.pack('<I', 4))
    for idx, name in enumerate(names):
        ptr = len(strings); strings.extend(name.encode()+b'\0')
        records.extend(struct.pack('<IIIhHBB', 0, ptr, 0, 1 if idx == 0 or (idx >= 2 and defined) else 0, 32 if idx == 0 else 0, 2, 0))
    struct.pack_into('<I', strings, 0, len(strings))
    refs = [(1, 1, 20)] + ([(off, 2, kind)] if overlay else [])
    symptr = 60+size+len(refs)*10
    return (struct.pack('<HHIIIHH', 0x14c, 1, 0, symptr, len(names), 0, 0) +
            struct.pack('<8sIIIIIIHHI', b'.text', 0, 0, size, 60, 60+size, 0, len(refs), 0, 0x60000020) +
            code+b''.join(struct.pack('<IIH', *r) for r in refs)+records+strings)


class RepairTests(unittest.TestCase):
    def setUp(self):
        self.targets = repair.policy()['targets']

    def test_fixed_scope_has_two_actual_existing_carriers(self):
        self.assertEqual([s['function_va'] for s in self.targets], ['0x0084ba20', '0x00c033c0'])
        self.assertEqual([s['function_offset'] for s in self.targets], [12, 12])

    def test_every_other_source_byte_and_line_remains(self):
        for spec in self.targets:
            raw = (repair.ROOT/spec['source']).read_bytes()
            result = repair.transform(raw, spec)
            undone = result.replace(spec['new_statement'].encode(), spec['old_statement'].encode(), 1)
            if spec['function_va'] == '0x0084ba20':
                undone = undone.replace(repair.INCLUDE[:-2]+b'extern int DAT_0107f4e8;\r\n', repair.INCLUDE, 1)
                self.assertEqual(result.count(b'extern int DAT_0107f4e8;'), 2)
            self.assertEqual(undone, raw)
            self.assertEqual(result.count(b'\n'), raw.count(b'\n'))

    def test_stale_or_comment_only_source_rejects(self):
        for spec in self.targets:
            raw = (repair.ROOT/spec['source']).read_bytes()
            for altered in (raw+b'\n', raw.replace(spec['old_statement'].encode(), b'// '+spec['old_statement'].encode(), 1)):
                with self.assertRaises(ValueError): repair.transform(altered, spec)

    def test_policy_cannot_change_target_store_qualifiers_or_context(self):
        for key, value in [('target_va', '0x0107f4ec'), ('new_statement', 'm_vft = 0;'), ('source_sha256', '0'*64), ('function_offset', 13)]:
            spec = copy.deepcopy(self.targets[0]); spec[key] = value
            with self.assertRaisesRegex(ValueError, 'unauthorized'):
                repair.transform((repair.ROOT/self.targets[0]['source']).read_bytes(), spec)

    def test_exact_new_dir32_and_other_reference_preservation(self):
        with tempfile.TemporaryDirectory() as td:
            before, after = Path(td)/'before.obj', Path(td)/'after.obj'
            for spec in self.targets:
                before.write_bytes(fixture(spec)); after.write_bytes(fixture(spec, True))
                self.assertTrue(repair.geometry(Coff(before), Coff(after), spec)['non_field_bytes_equal'])

    def test_wrong_kind_addend_changed_behavior_or_defined_duplicate_carrier(self):
        with tempfile.TemporaryDirectory() as td:
            before, after = Path(td)/'before.obj', Path(td)/'after.obj'
            for spec in self.targets:
                before.write_bytes(fixture(spec))
                for kwargs in [dict(kind=20), dict(addend=4), dict(change=True), dict(duplicate=True), dict(defined=True)]:
                    after.write_bytes(fixture(spec, True, **kwargs))
                    with self.assertRaises(ValueError): repair.geometry(Coff(before), Coff(after), spec)

    def test_plain_comparison_requires_every_row_and_exact_extent(self):
        spec = self.targets[0]
        row = dict(address=spec['function_va'], symbol=spec['function'], size=43, compiled_extent=43, verdict='match')
        other = dict(address='0x00001000', symbol='other', size=12, compiled_extent=12, verdict='match')
        expected = [row, other]
        repair.matches([row, other], spec, expected)
        for rows in [[], [row], [row, row], [row, other, other], [row, other | dict(verdict='mismatch')],
                     [row | dict(compiled_extent=44), other], [row | dict(verdict='mismatch'), other],
                     [row, other | dict(address='0x00001004')], [row, other | dict(size=13)]]:
            with self.assertRaises(ValueError): repair.matches(rows, spec, expected)


if __name__ == '__main__': unittest.main()
