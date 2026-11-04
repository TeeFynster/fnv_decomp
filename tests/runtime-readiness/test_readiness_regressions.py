"""Regression tests for defects found in independent review of readiness_check.py.

Synthetic fixtures only; see test_readiness_check.py for the fixture layout.
"""
import io
import json
import os
from pathlib import Path
import stat
import types
import unittest
from unittest import mock

from test_readiness_check import (ALL_CONTRACTS, Base, full_requirements, item, provenance, rc,  # noqa: F401
                                  run, run_json)


def requirements_doc(entries=(), attestations=()):
    return dict(schema=rc.REQUIREMENTS_SCHEMA, schema_version=1, provenance=provenance(),
                requirements=list(entries), attestations=list(attestations))


class EdgeInputTests(Base):
    def test_unhashable_attestation_contract_rejected_not_crash(self):
        path = self.f.write_json('r.json', requirements_doc(attestations=[
            dict(contract=[], statement='x', provenance=provenance()),
            dict(contract={}, statement='x', provenance=provenance()), 'not-an-object', 7]))
        code, report, err = run_json(self.f.args('--requirements', str(path)))
        self.assertEqual(code, 1, err)
        self.assertEqual(len(report['requirements']['rejected_attestations']), 4)

    def test_nul_in_paths(self):
        manifest = self.f.write_json('m.json', dict(schema=rc.MANIFEST_SCHEMA, schema_version=1,
                                                    paths=dict(installation='a\u0000b')))
        code, _, err = run(['--manifest', str(manifest)])
        self.assertEqual(code, 2)
        self.assertIn('NUL', err)
        path = self.f.write_json('r.json', requirements_doc(
            [dict(id='nul', role='installation', path='Data/a\u0000b', kind='file')]))
        code, report, _ = run_json(self.f.args('--requirements', str(path)))
        self.assertEqual(item(report, 'requirement.nul')['status'], 'unknown')
        self.assertEqual(rc.probe('a\x00b', 'file')[0], 'unknown')

    def test_deeply_nested_json(self):
        deep = self.f.root / 'deep.json'
        deep.write_text('[' * 100000 + ']' * 100000)
        code, _, err = run(['--manifest', str(deep)])
        self.assertEqual(code, 2)
        self.assertNotIn('Traceback', err)
        code, report, _ = run_json(self.f.args('--toolchain-report', str(deep)))
        self.assertEqual(report['toolchain_report']['status'], 'unknown')

    def test_bool_schema_versions_rejected(self):
        manifest = self.f.write_json('m.json', dict(schema=rc.MANIFEST_SCHEMA, schema_version=True))
        self.assertEqual(run(['--manifest', str(manifest)])[0], 2)
        req = self.f.write_json('r.json', dict(requirements_doc(), schema_version=True))
        self.assertEqual(run(self.f.args('--requirements', str(req)))[0], 2)
        doctor = self.f.write_json('d.json', dict(schema_version=True, toolchains={
            n: dict(ready=True) for n in rc.TOOLCHAIN_NAMES}))
        _, report, _ = run_json(self.f.args('--toolchain-report', str(doctor)))
        self.assertEqual(report['toolchain_report']['status'], 'unknown')

    def test_unknown_launch_keys_rejected(self):
        manifest = self.f.write_json('m.json', dict(schema=rc.MANIFEST_SCHEMA, schema_version=1,
                                                    launch=dict(arguments=[], env={'X': '1'})))
        self.assertEqual(run(['--manifest', str(manifest)])[0], 2)

    def test_unicode_digit_toolchain_version_not_reported(self):
        doctor = self.f.write_json('d.json', dict(schema_version=1, toolchains={
            n: dict(ready=True, version='15.\u00b2') for n in rc.TOOLCHAIN_NAMES}))
        _, report, _ = run_json(self.f.args('--toolchain-report', str(doctor)))
        self.assertIsNone(report['toolchain_report']['toolchains']['sp1']['reported_version'])

    def test_argparse_errors_do_not_echo_values(self):
        err = io.StringIO()
        with mock.patch('sys.stderr', err), self.assertRaises(SystemExit) as raised:
            rc.main(['--bogus', str(self.f.root / 'secret-marker')], stdout=io.StringIO())
        self.assertEqual(raised.exception.code, 2)
        self.assertNotIn('secret-marker', err.getvalue())

    def test_unexpected_exception_is_path_free(self):
        boom = PermissionError(13, 'denied', str(self.f.root / 'secret-marker'))
        with mock.patch.object(rc, 'check', side_effect=boom):
            code, out, err = run(self.f.args())
        self.assertEqual(code, 2)
        self.assertEqual(out, '')
        self.assertNotIn('secret-marker', err)
        self.assertIn('PermissionError', err)

    def test_text_output_survives_unencodable_characters(self):
        path = self.f.write_json('r.json', requirements_doc(
            [dict(id='\u4e2d\u6587', role='installation', path='Data', kind='directory', note='\ud800')]))
        stream = io.TextIOWrapper(io.BytesIO(), encoding='cp1252')
        with mock.patch('sys.stderr', io.StringIO()):
            code = rc.main(self.f.args('--requirements', str(path), '--format', 'text'), stdout=stream)
        stream.flush()
        self.assertEqual(code, 1)
        self.assertIn(b'\\u4e2d', stream.buffer.getvalue())


class OutGuardTests(Base):
    def test_out_never_replaces_an_input(self):
        manifest = self.f.write_json('m.json', dict(schema=rc.MANIFEST_SCHEMA, schema_version=1))
        req = full_requirements(self.f)
        doctor = self.f.write_json('d.json', dict(schema_version=1, toolchains={}))
        inventory_before = rc.INVENTORY_PATH.read_bytes()
        for target in (manifest, req, doctor, rc.INVENTORY_PATH):
            before = Path(target).read_bytes()
            code, _, err = run(self.f.args('--manifest', str(manifest), '--requirements', str(req),
                                           '--toolchain-report', str(doctor), '--out', str(target), '--overwrite'))
            self.assertEqual(code, 2, target)
            self.assertEqual(Path(target).read_bytes(), before)
        self.assertEqual(rc.INVENTORY_PATH.read_bytes(), inventory_before)

    def test_out_refused_in_every_owned_or_protected_location(self):
        targets = [self.f.work / 'r.json', self.f.provider / 'r.json', self.f.build / 'r.json',
                   self.f.protected / 'r.json']
        for target in targets:
            code, _, _ = run(self.f.args('--protected-path', str(self.f.protected), '--out', str(target)))
            self.assertEqual(code, 2, target)
            self.assertFalse(target.exists())

    def test_out_directory_with_overwrite_is_clean_error(self):
        target = self.f.root / 'adir'
        target.mkdir()
        code, _, err = run(self.f.args('--out', str(target), '--overwrite'))
        self.assertEqual(code, 2)
        self.assertNotIn(str(self.f.root), err)

    def test_out_link_refused(self):
        target = self.f.root / 'link.json'
        target.write_text('x')
        real = os.lstat

        def fake(path, *a, **k):
            if Path(path) == target:
                return types.SimpleNamespace(st_mode=stat.S_IFLNK | 0o777, st_size=1, st_ino=1, st_dev=1)
            return real(path, *a, **k)
        with mock.patch.object(rc.os, 'lstat', fake):
            code, _, err = run(self.f.args('--out', str(target), '--overwrite'))
        self.assertEqual(code, 2)
        self.assertIn('disabled', err)
        self.assertEqual(target.read_text(), 'x')


class PathSafetyTests(Base):
    def test_unc_and_device_paths_rejected_before_any_access(self):
        calls = []
        with mock.patch.object(rc.os, 'lstat', side_effect=lambda *a, **k: calls.append(a)):
            for argv in (['--installation', r'\\server\share\game'], ['--executable', r'\\?\C:\x.exe'],
                         ['--dll-provider', r'\\.\pipe\x'], ['--isolated-profile', '//server/share'],
                         ['--out', 'NUL'], ['--working-dir', r'C:\work\COM1'], ['--installation', 'con.txt']):
                code, _, err = run(argv)
                self.assertEqual(code, 2, argv)
        self.assertEqual(calls, [])
        manifest = self.f.write_json('m.json', dict(schema=rc.MANIFEST_SCHEMA, schema_version=1,
                                                    paths=dict(installation=r'\\server\share')))
        self.assertEqual(run(['--manifest', str(manifest)])[0], 2)
        req = self.f.write_json('r.json', requirements_doc(
            [dict(id='dev', role='installation', path='Data/AUX', kind='file')]))
        _, report, _ = run_json(self.f.args('--requirements', str(req)))
        self.assertEqual(item(report, 'requirement.dev')['status'], 'unknown')

    def test_link_at_intermediate_level_not_followed(self):
        real = os.lstat
        data = self.f.install / 'Data'

        def fake(path, *a, **k):
            if Path(path) == data:
                return types.SimpleNamespace(st_mode=stat.S_IFDIR, st_file_attributes=0x400, st_size=0)
            if data in Path(path).parents:
                raise AssertionError('followed a link to a child entry')
            return real(path, *a, **k)
        with mock.patch.object(rc.os, 'lstat', fake):
            code, report, _ = run_json(self.f.args())
        entry = next(e for e in report['observed_inventory']['entries'] if e['id'] == 'observed.Data/FalloutNV.esm')
        self.assertEqual(entry['status'], 'unknown')
        self.assertIn('not followed', entry['reason'])

    def test_overlap_checks_are_lexical(self):
        with mock.patch.object(Path, 'resolve', side_effect=AssertionError('resolved a path')):
            code, _, err = run(self.f.args('--protected-path', str(self.f.protected)))
        self.assertEqual(code, 1, err)


class IsolationTests(Base):
    def findings(self, report):
        return {s['id']: s['severity'] for s in report['safety_findings']}

    def test_working_directory_in_protected_path_blocked(self):
        _, report, _ = run_json(self.f.args('--working-dir', str(self.f.protected),
                                            '--protected-path', str(self.f.protected)))
        self.assertEqual(self.findings(report)['working-directory-overlaps-protected[0]'], 'block')
        self.assertEqual(report['overall']['verdict'], 'not-ready')

    def test_executable_and_provider_in_protected_path_warn(self):
        _, report, _ = run_json(self.f.args('--protected-path', str(self.f.root)))
        found = self.findings(report)
        self.assertEqual(found['executable-inside-protected[0]'], 'warn')
        self.assertEqual(found['provider-inside-protected[0]'], 'warn')

    def test_missing_protected_paths_warns(self):
        _, report, _ = run_json(self.f.args())
        self.assertEqual(self.findings(report)['protected-paths-not-supplied'], 'warn')
        _, report, _ = run_json(self.f.args('--protected-path', str(self.f.protected)))
        self.assertNotIn('protected-paths-not-supplied', self.findings(report))

    def test_provider_requirement_unknown_when_a_provider_is_absent(self):
        req = self.f.write_json('r.json', requirements_doc(
            [dict(id='x', role='dll_provider', path='notthere.dll', kind='file')]))
        _, report, _ = run_json(self.f.args('--dll-provider', str(self.f.root / 'absent'),
                                            '--requirements', str(req)))
        self.assertEqual(item(report, 'requirement.x')['status'], 'unknown')
        _, report, _ = run_json(self.f.args('--requirements', str(req)))
        self.assertEqual(item(report, 'requirement.x')['status'], 'missing')


class AttestationVisibilityTests(Base):
    def test_attested_counts_are_separate_and_exit_non_zero(self):
        code, report, _ = run_json(self.f.args('--requirements', str(full_requirements(self.f))))
        self.assertEqual(code, 4)
        counts = report['overall']['counts']
        self.assertEqual(counts['present_user_attested_only'], len(ALL_CONTRACTS))
        self.assertEqual(counts['present'], counts['present_checker_observed'] + counts['present_user_supplied']
                         + counts['present_user_attested_only'])
        self.assertIn('not inspected', item(report, 'input.executable')['caveat'])

    def test_placeholders_align_with_smoke_template(self):
        template = json.loads((rc.HERE / 'smoke-test-template.json').read_text(encoding='utf-8'))
        rendered = json.dumps(template)
        for placeholder in ('<application-directory>', '<working-directory>', '<private-built-exe>',
                            '<owned-game-data>', '<isolated-config-and-saves>', '<verified-dll-providers>'):
            self.assertIn(placeholder, rendered)
            self.assertIn(placeholder, rc.PLACEHOLDERS.values())


class SmokeValidatorRegressionTests(Base):
    def setUp(self):
        super().setUp()
        import smoke_template
        self.st = smoke_template

    def call(self, argv):
        err, out = io.StringIO(), io.StringIO()
        with mock.patch('sys.stderr', err), mock.patch('sys.stdout', out):
            code = self.st.main(argv)
        return code, out.getvalue(), err.getvalue()

    def test_read_errors_are_path_free(self):
        for target in (self.f.root / 'secret-marker.json', self.f.root):
            code, _, err = self.call(['validate', str(target)])
            self.assertEqual(code, 2)
            self.assertNotIn('secret-marker', err)
            self.assertNotIn(str(self.f.root), err)

    def test_deep_nesting_is_clean_error(self):
        deep = self.f.root / 'deep.json'
        deep.write_text('[' * 100000 + ']' * 100000)
        code, _, err = self.call(['validate', str(deep)])
        self.assertEqual(code, 2)
        self.assertIn('nested too deeply', err)

    def test_msys_style_paths_flagged(self):
        self.assertTrue(self.st.looks_like_private_path('see /c/Users/someone/x'))
        self.assertFalse(self.st.looks_like_private_path('<private-built-exe>'))


if __name__ == '__main__':
    unittest.main()
