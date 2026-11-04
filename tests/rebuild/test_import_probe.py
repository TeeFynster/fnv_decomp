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
spec = importlib.util.spec_from_file_location('import_probe', ROOT / 'tools/rebuild/import_probe.py')
probe = importlib.util.module_from_spec(spec)
spec.loader.exec_module(probe)


class ImportProbeTests(unittest.TestCase):
    def test_mapping_rejects_function_bodies_and_unknown_mapping(self):
        flags = probe.validate_aliases(dict(probe.ALIASES))
        self.assertEqual(len(flags), 2)
        altered = dict(probe.ALIASES)
        altered[next(iter(altered))] = '_GetCommandLineW@0'
        with self.assertRaises(ValueError): probe.validate_aliases(altered)
        with self.assertRaises(ValueError): probe.validate_aliases({})

    def test_pointer_relocations_required_for_each_side(self):
        lines = '\n'.join('0008 DIR32 0000 1 ' + name for name in list(probe.ALIASES) + list(probe.ALIASES.values()))
        probe.check_relocations(lines, probe.ALIASES)
        with self.assertRaises(ValueError): probe.check_relocations(lines.replace('DIR32', 'REL32'), probe.ALIASES)
        with self.assertRaises(ValueError): probe.check_relocations('\n'.join(lines.splitlines()[:-1]), probe.ALIASES)

    def test_imports_need_correct_dll_canonical_names_and_no_aliases(self):
        valid = '  KERNEL32.dll\n   170 GetCommandLineW\n   1AA GetCurrentProcessId\n  Summary\n'
        probe.check_imports(valid)
        for invalid in (valid.replace('KERNEL32.dll', 'OTHER.dll'), valid.replace('GetCommandLineW', 'FetchCommandLineW'),
                        valid.replace('GetCurrentProcessId', 'WrongName'), valid + '\n  1 FetchCommandLineW\n'):
            with self.subTest(invalid=invalid), self.assertRaises(ValueError): probe.check_imports(invalid)

    def test_runtime_receipt_is_strict(self):
        text = json.dumps(probe.EXPECTED)
        self.assertEqual(probe.parse_receipt(text, '', 0), probe.EXPECTED)
        for stdout, stderr, code in [(text, '', 1), (text, 'error', 0), ('{}', '', 0),
                                      (json.dumps(dict(probe.EXPECTED, process_id_valid=0)), '', 0),
                                      (json.dumps(dict(probe.EXPECTED, schema=True)), '', 0)]:
            with self.subTest(stdout=stdout, code=code), self.assertRaises(ValueError):
                probe.parse_receipt(stdout, stderr, code)

    def test_environment_and_output_are_fail_closed(self):
        with tempfile.TemporaryDirectory() as tmp:
            out = Path(tmp) / 'out'
            with mock.patch.object(probe.os, 'name', 'nt'), mock.patch.dict(probe.os.environ, {'_LINK_': '/FORCE'}), \
                 mock.patch.object(probe.toolchain, 'run') as execute:
                result = probe.run_probe('private', out)
            self.assertEqual(result['status'], 'error')
            execute.assert_not_called()
            with self.assertRaises(ValueError): probe.run_probe('private', out)

    @unittest.skipUnless(os.environ.get('FNV_RUNTIME_PROBE_TEST_ROOT'), 'native proof requires explicitly enabled toolchain and compiler slot')
    def test_native_when_enabled(self):
        with tempfile.TemporaryDirectory() as tmp:
            result = probe.run_probe(os.environ['FNV_RUNTIME_PROBE_TEST_ROOT'], Path(tmp) / 'out')
            self.assertEqual(result['status'], 'pass', result.get('error'))
            self.assertEqual(result['observed'], probe.EXPECTED)


if __name__ == '__main__': unittest.main()
