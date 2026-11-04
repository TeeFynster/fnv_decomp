"""Additional independent review regressions, synthetic inputs only."""
import json
import os
from pathlib import Path
import stat
import types
import unittest
from unittest import mock
from test_readiness_check import Base, rc, run, run_json, item, provenance
import smoke_template


class ReviewRegressions(Base):
    def test_ancestor_reparse_fails_closed_for_probe_and_output(self):
        parent = self.f.root / 'indirect'; parent.mkdir()
        real = os.lstat
        def fake(path, *a, **k):
            if Path(path) == parent:
                return types.SimpleNamespace(st_mode=stat.S_IFDIR, st_file_attributes=0x400)
            return real(path, *a, **k)
        with mock.patch.object(rc.os, 'lstat', fake):
            self.assertEqual(rc.probe(parent / 'child', 'file')[0], 'unknown')
            code, _, _ = run(self.f.args('--out', str(parent / 'report.json')))
            self.assertEqual(code, 2)
            with self.assertRaises(rc.InputError): rc._read_json(parent / 'input.json', 'input')
        self.assertFalse((parent / 'report.json').exists())

    def test_actual_symlink_ancestor_when_supported(self):
        link = self.f.root / 'link'
        try: link.symlink_to(self.f.install, target_is_directory=True)
        except OSError: self.skipTest('symlink creation not permitted')
        self.assertEqual(rc.probe(link / 'Data', 'directory')[0], 'unknown')
        code, _, _ = run(self.f.args('--out', str(link / 'report.json')))
        self.assertEqual(code, 2)
        self.assertFalse((self.f.install / 'report.json').exists())

    def test_unknown_provider_candidate_stays_unknown(self):
        req = self.f.write_json('provider-req.json', dict(schema=rc.REQUIREMENTS_SCHEMA, schema_version=1,
            provenance=provenance(), requirements=[dict(id='unknown-dll', role='dll_provider', path='unknown.dll', kind='file')]))
        original = rc.probe_under
        def probe(root, relative, kind):
            if relative == 'unknown.dll': return ('unknown', 'metadata denied', {})
            return original(root, relative, kind)
        with mock.patch.object(rc, 'probe_under', side_effect=probe):
            _, report, _ = run_json(self.f.args('--requirements', str(req)))
        self.assertEqual(item(report, 'requirement.unknown-dll')['status'], 'unknown')

    def test_private_object_key_not_echoed_in_errors(self):
        secret = r'C:\Users\secret\private'
        manifest = self.f.write_json('bad-manifest.json', dict(schema=rc.MANIFEST_SCHEMA, schema_version=1,
            paths={}, **{secret: 1}))
        code, out, err = run(['--manifest', str(manifest)])
        self.assertEqual(code, 2); self.assertNotIn(secret, out + err)
        problems = []
        smoke_template._lint_privacy({secret: {'child': secret}}, '', problems)
        self.assertTrue(problems); self.assertNotIn(secret, ' '.join(problems))

    def test_smoke_rejects_unc_and_reparse_ancestor(self):
        with self.assertRaises(ValueError): smoke_template.read_json_file(r"\\server\share\record.json")
        parent = self.f.root / 'smoke-link'; parent.mkdir()
        real = os.lstat
        def fake(path, *a, **k):
            if Path(path) == parent:
                return types.SimpleNamespace(st_mode=stat.S_IFDIR, st_file_attributes=0x400)
            return real(path, *a, **k)
        with mock.patch.object(rc.os, 'lstat', fake):
            with self.assertRaises(ValueError): smoke_template.read_json_file(parent / 'record.json')

    def test_smoke_step_identifiers_never_echoed(self):
        data = smoke_template.load_template()
        secret = r"C:\Users\secret\private"
        data['steps'][0]['id'] = secret
        data['steps'][0][secret] = 'value'
        data['steps'][1]['depends_on'] = [secret + 'other']
        data['steps'][1]['result'] = 'pass'
        self.assertNotIn(secret, ' '.join(smoke_template.validate_record(data)))
