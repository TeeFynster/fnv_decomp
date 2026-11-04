"""Retained gate tests with original synthetic PE/COFF and mocked image probes."""
import hashlib
import json
from pathlib import Path
import struct
import sys
import tempfile
import unittest
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[2] / 'tools/rebuild'))
import verify_objects as verifier
from build_objects import recipe_id


def sha(data):
    return hashlib.sha256(data).hexdigest()


def object_bytes(payload=b'\0' * 4):
    return (struct.pack('<HHIIIHH', 0x14c, 1, 0, 64, 1, 0, 0) +
        struct.pack('<8sIIIIIIHHI', b'.text\0\0\0', 0, 0, 4, 60, 0, 0, 0, 0, 0x60000020) +
        payload + struct.pack('<8sIhHBB', b'_entry\0\0', 0, 1, 0x20, 2, 0) + struct.pack('<I', 4))


def image_bytes():
    data = bytearray(516)
    data[:2] = b'MZ'
    struct.pack_into('<I', data, 60, 128)
    data[128:132] = b'PE\0\0'
    struct.pack_into('<HHIIIHH', data, 132, 0x14c, 1, 0, 0, 0, 224, 0)
    struct.pack_into('<H', data, 152, 0x10b)
    struct.pack_into('<I', data, 152 + 28, 0x400000)
    struct.pack_into('<8sIIIIIIHHI', data, 152 + 224, b'.text\0\0\0', 4, 0x1000, 4, 512, 0, 0, 0, 0, 0x60000020)
    return bytes(data)


class RetainedTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        (self.root / 'build').mkdir()
        self.image = self.root / 'synthetic.exe'
        self.image.write_bytes(image_bytes())
        self.image_hash = sha(self.image.read_bytes())
        self.object = self.root / 'one.obj'
        self.object.write_bytes(object_bytes())
        self.source = self.root / 'fixture.cpp'
        self.source.write_text('void original_synthetic_fixture() {}\n', encoding='ascii')
        self.recipe = dict(source='fixture.cpp', compiler='sp1', flags=[],
            functions=[dict(address='0x00401000', symbol='_entry', size=4)], symbols={})
        self.recipes = self.root / 'recipes.json'
        self.recipes.write_text(json.dumps(dict(units=[self.recipe])), encoding='utf-8')
        (self.root / 'build/function_index.json').write_text('[{"address":"0x00401000"}]', encoding='ascii')
        self.unit = dict(recipe_index=0, recipe_id=recipe_id(0, self.recipe), recipe=self.recipe,
            source='fixture.cpp', compiler='sp1', source_sha256=sha(self.source.read_bytes()),
            status='compiled', object='one.obj', object_sha256=sha(self.object.read_bytes()))
        self.manifest = self.root / 'objects.json'
        self.save_manifest()
        self.output = self.root / 'receipt.json'

    def save_manifest(self):
        self.manifest.write_text(json.dumps(dict(schema_version=1, kind='fnv-retained-objects',
            source_root=str(self.root), recipe_manifest_sha256=sha(self.recipes.read_bytes()),
            selection=dict(complete=True), units=[self.unit])), encoding='utf-8')

    def run_gate(self, **kwargs):
        with patch.object(verifier.oracle, 'image_ok', return_value=(True, 1, 1)):
            return verifier.verify(self.manifest, self.recipes, self.image, self.output,
                self.image_hash, root=self.root, **kwargs)

    def test_actual_retained_payload_compared_and_hash_bound(self):
        report = self.run_gate(require_full=True)
        self.assertEqual(report['status'], 'pass')
        self.assertEqual(report['summary']['matched_functions'], 1)
        self.assertTrue(report['scope']['full_authoritative'])
        self.assertEqual(report['units'][0]['object_sha256'], sha(self.object.read_bytes()))
        self.assertEqual(report['units'][0]['verified_functions'], [dict(symbol='_entry',
            address='0x00401000', size=4, section=1, value=0, verdict='match')])
        self.assertEqual(report['inputs']['image_sha256'], self.image_hash)
        self.assertIn('tools/compare.py', report['inputs']['tools_sha256'])
        self.assertNotIn('byte_differences', self.output.read_text())
        with self.assertRaisesRegex(ValueError, 'already exists'):
            self.run_gate()

    def test_corrupted_object_hash_rejected_before_comparison(self):
        self.object.write_bytes(object_bytes(b'\1' * 4))
        with self.assertRaisesRegex(ValueError, 'object fingerprint'):
            self.run_gate()
        self.assertFalse(self.output.exists())

    def test_updated_object_hash_cannot_hide_byte_mismatch(self):
        self.object.write_bytes(object_bytes(b'\1' * 4))
        self.unit['object_sha256'] = sha(self.object.read_bytes())
        self.save_manifest()
        report = self.run_gate()
        self.assertEqual(report['status'], 'fail')
        self.assertEqual(report['summary']['matched_functions'], 0)
        self.assertEqual(report['units'][0]['mismatches'][0]['differing_bytes'], 4)

    def test_stale_image_hash_and_original_image_gate_rejected(self):
        self.image.write_bytes(self.image.read_bytes() + b'stale')
        with self.assertRaisesRegex(ValueError, 'expected SHA-256'):
            self.run_gate()
        self.image_hash = sha(self.image.read_bytes())
        with patch.object(verifier.oracle, 'image_ok', return_value=(False, 0, 16)):
            with self.assertRaisesRegex(ValueError, 'reference image gate'):
                verifier.verify(self.manifest, self.recipes, self.image, self.output,
                    self.image_hash, root=self.root)

    def test_recipe_change_and_source_change_rejected(self):
        self.source.write_text('changed', encoding='ascii')
        with self.assertRaisesRegex(ValueError, 'source observation'):
            self.run_gate()
        self.unit['source_sha256'] = sha(self.source.read_bytes())
        self.save_manifest()
        self.recipe['flags'] = ['/unexpected']
        self.recipes.write_text(json.dumps(dict(units=[self.recipe])))
        with self.assertRaisesRegex(ValueError, 'recipe reconciliation'):
            self.run_gate()

    def test_partial_scope_is_labeled_and_require_full_rejects(self):
        other = dict(self.recipe, source='other.cpp')
        self.recipes.write_text(json.dumps(dict(units=[self.recipe, other])))
        self.save_manifest()
        with self.assertRaisesRegex(ValueError, 'full authoritative'):
            self.run_gate(require_full=True)
        report = self.run_gate()
        self.assertEqual(report['status'], 'pass')
        self.assertFalse(report['scope']['full_authoritative'])
        self.assertEqual(report['scope']['selected_recipe_indices'], [0])

    def test_inferred_eh_conflict_fails_overall_receipt(self):
        with patch.object(verifier.oracle, 'eh_tails', return_value=({}, {}, {}, 1, 1)):
            report = self.run_gate()
        self.assertEqual(report['status'], 'fail')
        self.assertEqual(report['summary']['eh_inferred_conflicts'], 1)

    def test_canonical_span_enforcement_not_skipped(self):
        self.recipe['functions'][0]['size'] = 3
        self.unit['recipe_id'] = recipe_id(0, self.recipe)
        self.recipes.write_text(json.dumps(dict(units=[self.recipe])))
        self.save_manifest()
        report = self.run_gate()
        self.assertEqual(report['status'], 'fail')
        self.assertEqual(report['units'][0]['status'], 'compare-error')

    def test_worker_cap_and_manifest_pin_rejected(self):
        with self.assertRaisesRegex(ValueError, 'two concurrent'):
            self.run_gate(jobs=3)
        with self.assertRaisesRegex(ValueError, 'manifest fingerprint'):
            self.run_gate(expected_manifest_sha256='0' * 64)

    def test_zero_function_compare_error_cannot_pass(self):
        self.recipe['functions'] = []
        self.unit['recipe_id'] = recipe_id(0, self.recipe)
        self.recipes.write_text(json.dumps(dict(units=[self.recipe])))
        self.save_manifest()
        with patch.object(verifier.oracle, 'compare', side_effect=ValueError('synthetic comparison failure')):
            report = self.run_gate()
        self.assertEqual(report['status'], 'fail')
        self.assertEqual(report['summary']['matched_functions'], 0)
        self.assertEqual(report['units'][0]['status'], 'compare-error')

    def test_absent_optional_index_is_honestly_recorded(self):
        (self.root / 'build/function_index.json').unlink()
        report = self.run_gate()
        self.assertEqual(report['status'], 'pass')
        self.assertFalse(report['inputs']['function_index_present'])
        self.assertIsNone(report['inputs']['function_index_sha256'])

    def test_global_eh_parity_and_local_diagnostics_remain_separate(self):
        self.recipe['eh_tails'] = [dict(address='0x00401000', size=4)]
        self.unit['recipe_id'] = recipe_id(0, self.recipe)
        self.recipes.write_text(json.dumps(dict(units=[self.recipe])))
        self.save_manifest()
        placement = [[0x401000, 0x401004, True, '0x00401000', []]]
        with patch.object(verifier.oracle, 'eh_sections', return_value=(placement, {}, ['synthetic local diagnostic'])):
            report = self.run_gate()
        self.assertEqual(report['status'], 'pass_with_diagnostics')
        self.assertTrue(report['function_byte_verification_pass'])
        self.assertTrue(report['global_listed_eh_coverage_pass'])
        self.assertTrue(report['original_oracle_parity_pass'])
        self.assertFalse(report['strict_local_eh_diagnostics_pass'])
        self.assertFalse(report['runtime_closure_verified'])
        self.assertEqual(report['summary']['eh_comparison_errors'], 1)


if __name__ == '__main__':
    unittest.main()
