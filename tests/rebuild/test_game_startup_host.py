"""Offline startup-plan gates; no compiler, linker or game execution."""
import copy
import json
from pathlib import Path
import sys
import tempfile
import unittest
from unittest import mock

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tools/rebuild'))
import game_startup_host as host


class GameStartupHostTests(unittest.TestCase):
    def fixture(self, root):
        for relative in [host.HOST, 'tools/rebuild/game_startup_host.py',
                'tests/rebuild/test_game_startup_host.py', 'docs/rebuild/GAME-STARTUP-HOST.md',
                'build/units.json', host.SOURCE]:
            target = root / relative
            target.parent.mkdir(parents=True, exist_ok=True)
            target.write_bytes((ROOT / relative).read_bytes())
        compiler = root / 'private-compiler'
        for relative in ['VC/bin/cl.exe', 'VC/bin/link.exe']:
            target = compiler / relative
            target.parent.mkdir(parents=True, exist_ok=True)
            target.write_bytes(b'original synthetic non-executable test input')
        (compiler / 'VC/include').mkdir()
        (compiler / 'SDK/Include').mkdir(parents=True)
        sp1 = dict(compiler='sp1', ready=True, version='15.00.30729.01',
            expected_version='15.00.30729.01', root=str(compiler), sdk=str(compiler / 'SDK'),
            cl_sha256=host.sha256(compiler / 'VC/bin/cl.exe'),
            link_sha256=host.sha256(compiler / 'VC/bin/link.exe'))
        doctor = root / 'doctor.json'
        doctor.write_text(json.dumps(dict(schema_version=1, toolchains=dict(sp1=sp1))))
        return doctor, compiler

    def test_plan_keeps_all_runtime_and_native_gates_false(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            doctor, _ = self.fixture(root)
            plan = host.build_plan(doctor, host.sha256(doctor), root)
            self.assertFalse(any(plan['approvals'].values()))
            self.assertFalse(any(plan['closure_gates'].values()))
            self.assertEqual(plan['compile_plan']['flags'], host.FLAGS)
            self.assertIn('/c', plan['compile_plan']['flags'])
            self.assertIsNone(plan['eventual_link_policy']['entry_override'])
            self.assertEqual(plan['host']['undefined_typed_symbol'], '_fnv_game_application_entry@16')
            self.assertEqual(plan['host']['proposed_identity_only_binding'], host.CANONICAL)
            self.assertFalse(plan['entry']['original_caller_verified'])

    def test_wrong_doctor_hash_rejected_before_parsing(self):
        with tempfile.TemporaryDirectory() as temp:
            doctor = Path(temp) / 'doctor.json'
            doctor.write_text('invalid JSON')
            with self.assertRaisesRegex(ValueError, 'doctor hash'):
                host.build_plan(doctor, '0' * 64)

    def test_wrong_version_schema_and_false_readiness_rejected(self):
        for field, value in [('version', '15.00.21022.08'), ('ready', 1),
                             ('expected_version', '14.00.50727.762')]:
            with self.subTest(field=field), tempfile.TemporaryDirectory() as temp:
                root = Path(temp)
                doctor, _ = self.fixture(root)
                data = json.loads(doctor.read_text())
                data['toolchains']['sp1'][field] = value
                doctor.write_text(json.dumps(data))
                with self.assertRaisesRegex(ValueError, 'SP1 doctor'):
                    host.build_plan(doctor, host.sha256(doctor), root)
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            doctor, _ = self.fixture(root)
            data = json.loads(doctor.read_text())
            data['schema_version'] = 2
            doctor.write_text(json.dumps(data))
            with self.assertRaisesRegex(ValueError, 'schema'):
                host.build_plan(doctor, host.sha256(doctor), root)

    def test_changed_native_tool_and_missing_sdk_rejected(self):
        for relative in ['VC/bin/cl.exe', 'VC/bin/link.exe', 'SDK/Include']:
            with self.subTest(path=relative), tempfile.TemporaryDirectory() as temp:
                root = Path(temp)
                doctor, compiler = self.fixture(root)
                target = compiler / relative
                if target.is_dir():
                    target.rmdir()
                else:
                    target.write_bytes(b'changed')
                with self.assertRaises(ValueError):
                    host.build_plan(doctor, host.sha256(doctor), root)

    def test_entry_source_and_recipe_drift_rejected(self):
        for relative in [host.SOURCE, 'build/units.json']:
            with self.subTest(path=relative), tempfile.TemporaryDirectory() as temp:
                root = Path(temp)
                doctor, _ = self.fixture(root)
                (root / relative).write_text('changed')
                with self.assertRaises(ValueError):
                    host.build_plan(doctor, host.sha256(doctor), root)

    def test_canonical_contract_mismatch_rejected(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            doctor, _ = self.fixture(root)
            with mock.patch.object(host, 'CANONICAL', '_other'), \
                    self.assertRaisesRegex(ValueError, 'canonical'):
                host.build_plan(doctor, host.sha256(doctor), root)

    def test_sources_are_bound_and_drift_during_plan_rejected(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            doctor, _ = self.fixture(root)
            sources = host.source_manifest(root)
            changed = copy.deepcopy(sources)
            changed[host.HOST] = 'f' * 64
            with mock.patch.object(host, 'source_manifest', side_effect=[sources, changed]), \
                    self.assertRaisesRegex(ValueError, 'source drift'):
                host.build_plan(doctor, host.sha256(doctor), root)

    def test_output_is_new_and_private(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            target = root / 'build/rebuild/plan.json'
            host.write_plan({'approvals': {'compile': False}}, target, root)
            with self.assertRaises(FileExistsError):
                host.write_plan({}, target, root)
            with self.assertRaisesRegex(ValueError, 'private'):
                host.write_plan({}, root / 'public.json', root)
            self.assertFalse((root / 'public.json').exists())


if __name__ == '__main__':
    unittest.main()
