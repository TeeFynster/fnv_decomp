import importlib.util
import json
import os
from pathlib import Path
import sys
import tempfile
import unittest
from unittest import mock

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tools/rebuild'))
spec = importlib.util.spec_from_file_location('runtime_probe', ROOT / 'tools/rebuild/runtime_probe.py')
probe = importlib.util.module_from_spec(spec)
spec.loader.exec_module(probe)


class RuntimeProbeTests(unittest.TestCase):
    def test_parse_requires_complete_destructor_and_thread_evidence(self):
        valid = json.dumps(probe.EXPECTED)
        self.assertEqual(probe.parse_receipt(valid + '\n', 0), probe.EXPECTED)
        for output, code in [(valid, 1), ('garbage', 0), (valid + '\n' + valid, 0),
                             (json.dumps(dict(probe.EXPECTED, destructor=0)), 0),
                             (json.dumps(dict(probe.EXPECTED, thread_final=[101, 101])), 0),
                             (json.dumps(dict(probe.EXPECTED, schema=True)), 0)]:
            with self.subTest(output=output, code=code), self.assertRaises(ValueError):
                probe.parse_receipt(output, code)

    def test_existing_output_is_not_overwritten(self):
        with tempfile.TemporaryDirectory() as tmp:
            with self.assertRaises(ValueError):
                probe.run_probe(None, Path(tmp))

    def test_error_produces_receipt_and_no_pass(self):
        with tempfile.TemporaryDirectory() as tmp:
            out = Path(tmp) / 'run'
            with mock.patch.object(probe.os, 'name', 'nt'):
                report = probe.run_probe(None, out)
            self.assertEqual(report['status'], 'error')
            self.assertIn('sp1-root', report['error'])
            self.assertEqual(json.loads((out / 'receipt.json').read_text())['status'], 'error')

    def test_implicit_linker_flags_are_rejected(self):
        with tempfile.TemporaryDirectory() as tmp:
            out = Path(tmp) / 'run'
            with mock.patch.object(probe.os, 'name', 'nt'), \
                 mock.patch.dict(probe.os.environ, {'LINK': '/FORCE:MULTIPLE'}), \
                 mock.patch.object(probe.toolchain, 'run') as execute:
                report = probe.run_probe('private-root', out)
            self.assertEqual(report['status'], 'error')
            self.assertIn('LINK', report['error'])
            execute.assert_not_called()

    def test_compile_failure_is_recorded_without_link_or_execution(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            out = root / 'run'
            with mock.patch.object(probe.os, 'name', 'nt'), \
                 mock.patch.object(probe.toolchain, 'layout', return_value=(root, root)), \
                 mock.patch.object(probe.toolchain, 'sha256', return_value='abc'), \
                 mock.patch.object(probe.toolchain, 'run', side_effect=[(0, 'Version 15.00.30729.01'), (2, 'compiler error')]) as execute, \
                 mock.patch.object(probe.subprocess, 'run') as launch:
                report = probe.run_probe(root, out)
            self.assertEqual(report['status'], 'error')
            self.assertIn('compile failed', report['error'])
            self.assertEqual(report['stages']['compile']['returncode'], 2)
            self.assertNotIn('link', report['stages'])
            self.assertEqual(execute.call_count, 2)
            launch.assert_not_called()

    def test_pe_machine_rejects_unrelated_input(self):
        with tempfile.TemporaryDirectory() as tmp:
            path = Path(tmp) / 'bad.exe'
            path.write_bytes(b'not a PE')
            with self.assertRaises(ValueError):
                probe.pe_machine(path)

    @unittest.skipUnless(os.environ.get('FNV_RUNTIME_PROBE_TEST_ROOT'), 'native probe requires an explicitly enabled toolchain and free compiler slot')
    def test_native_probe_when_explicitly_enabled(self):
        with tempfile.TemporaryDirectory() as tmp:
            report = probe.run_probe(os.environ['FNV_RUNTIME_PROBE_TEST_ROOT'], Path(tmp) / 'run')
            self.assertEqual(report['status'], 'pass', report.get('error'))
            self.assertEqual(report['observed'], probe.EXPECTED)


if __name__ == '__main__':
    unittest.main()
