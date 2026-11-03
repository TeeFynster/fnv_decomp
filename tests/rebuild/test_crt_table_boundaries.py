"""Original synthetic signature/relocation metadata; no native/game inputs."""
import copy
import hashlib
import json
from pathlib import Path
import struct
import sys
import tempfile
import unittest
from types import SimpleNamespace

sys.path.insert(0, str(Path(__file__).resolve().parents[2] / 'tools' / 'rebuild'))
import crt_table_boundaries as scan


class SignatureTests(unittest.TestCase):
    def test_exact_complete_span_and_ambiguity(self):
        pattern = b'abcdefgh' + bytes(4) + b'uvwxyz'
        relocation = [dict(offset=8, kind=6)]
        variant = b'abcdefgh' + b'WXYZ' + b'uvwxyz'
        self.assertEqual(scan.exact_candidates(b'!' + variant + b'?' + variant,
                                              pattern, relocation), [1, 20])
        self.assertEqual(scan.exact_candidates(variant[:-1] + b'!', pattern, relocation), [])

    def test_overlapping_matches_are_retained(self):
        self.assertEqual(scan.exact_candidates(b'aaaaaaaa', b'aaaaaa', []), [0, 1, 2])

    def test_invalid_masks_fail_closed(self):
        for relocations in [[dict(offset=0, kind=7)], [dict(offset=-1, kind=6)],
                            [dict(offset=13, kind=6)],
                            [dict(offset=0, kind=6), dict(offset=3, kind=20)]]:
            with self.assertRaises(ValueError):
                scan.fixed_segments(16, relocations)

    def test_rel32_uses_field_end_and_signed_addend(self):
        self.assertEqual(scan.target_from_field(-20, -4, 20, 0x401000), 0x400ff4)
        self.assertEqual(scan.target_from_field(0x404004, 4, 6, 0x401000), 0x404000)
        self.assertEqual(scan.target_from_field(-4, 0, 6, 0), 0xfffffffc)

    def test_every_relocation_and_failed_provenance_preserved(self):
        text = bytearray(24)
        struct.pack_into('<I', text, 4, 0x405000)
        struct.pack_into('<i', text, 12, -8)
        relocations = [dict(offset=4, kind=6, addend=0, symbol='___xc_a'),
                       dict(offset=12, kind=20, addend=0, symbol='helper')]
        pe = SimpleNamespace(base=0x400000,
            section=lambda rva, size: dict(name='.rdata', rva=0x5000,
                                          raw_size=0x1000, executable=False))
        rows = scan.observe_relocations(dict(relocations=relocations), 0x401000,
                                         text, 0x401000, pe, {0x100c})
        self.assertEqual(len(rows), 2)
        self.assertIn('absolute field lacks original HIGHLOW relocation', rows[0]['errors'])
        self.assertIn('REL32 field unexpectedly has original HIGHLOW relocation', rows[1]['errors'])
        self.assertFalse(rows[0]['boundary_payload_read'])
        self.assertFalse(rows[0]['independent_symbol_identity_verified'])

    def test_executable_boundary_remains_failed_candidate_without_payload_read(self):
        pe = SimpleNamespace(base=0x400000, section=lambda *args:
                             dict(name='.text', rva=0x1000, raw_size=0x1000, executable=True))
        text = struct.pack('<I', 0x401000)
        contract = dict(relocations=[dict(offset=0, kind=6, addend=0, symbol='___xc_z')])
        rows = scan.observe_relocations(contract, 0x401000, text, 0x401000, pe, {0x1000})
        self.assertIn('boundary target metadata is not raw non-executable storage', rows[0]['errors'])
        self.assertFalse(rows[0]['boundary_payload_read'])

    def test_outside_image_target_is_preserved_with_failure(self):
        pe = SimpleNamespace(base=0x400000, section=lambda *args: None)
        text = struct.pack('<I', 0x1234)
        contract = dict(relocations=[dict(offset=0, kind=6, addend=0, symbol='___xi_a')])
        rows = scan.observe_relocations(contract, 0x401000, text, 0x401000, pe, {0x1000})
        self.assertEqual(rows[0]['original_symbol_base_candidate'], 0x1234)
        self.assertIn('target outside image logical sections', rows[0]['errors'])

    def test_review_is_exact_and_candidate_only(self):
        review = dict(kind='fnv-crt-boundary-scan-review', status='approved',
            reviewer='independent-test-reviewer', allow_reference_scan=True,
            allow_execute=False, sources={'fixture': 'hash'}, functions=list(scan.FUNCTIONS),
            reference_sha256=scan.REFERENCE, text_geometry=scan.TEXT,
            libraries=scan.LIBRARIES, members=scan.MEMBERS, candidate_only=True)
        with tempfile.TemporaryDirectory() as folder:
            path = Path(folder) / 'review.json'
            def check(value):
                path.write_text(json.dumps(value))
                scan.review_gate(path, hashlib.sha256(path.read_bytes()).hexdigest(), {'fixture': 'hash'})
            check(review)
            for key, bad in [('allow_execute', True), ('candidate_only', False),
                             ('functions', ['different']), ('text_geometry', {}),
                             ('members', {}), ('sources', {})]:
                changed = copy.deepcopy(review)
                changed[key] = bad
                with self.assertRaises(ValueError):
                    check(changed)


if __name__ == '__main__':
    unittest.main()
