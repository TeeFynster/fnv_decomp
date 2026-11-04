"""Tests for tools/runtime-readiness/readiness_check.py.

Every fixture is synthetic: tiny placeholder files in a temporary directory.
No game installation, executable, Steam or user configuration is touched.
"""
import ast
import hashlib
import io
import json
import os
from pathlib import Path
import stat
import sys
import tempfile
import types
import unittest
from unittest import mock

TOOL_DIR = Path(__file__).resolve().parents[2] / 'tools' / 'runtime-readiness'
sys.path.insert(0, str(TOOL_DIR))
import readiness_check as rc  # noqa: E402

ALL_CONTRACTS = [c for c, _ in rc.CONTRACTS]


def provenance(**extra):
    return dict(dict(source='synthetic test fixture', basis='unit test'), **extra)


class Fixture:
    """A synthetic layout: installation, rebuilt exe, working dir, profile, provider."""

    def __init__(self, root):
        self.root = Path(root)
        self.install = self.root / 'owned-install'
        self.build = self.root / 'private-build'
        self.exe = self.build / 'rebuilt.exe'
        self.work = self.root / 'workdir'
        self.profile = self.root / 'isolated-profile'
        self.provider = self.root / 'providers'
        self.protected = self.root / 'existing-user-config'
        for d in (self.install / 'Data', self.install / 'Redists', self.build, self.work,
                  self.profile, self.provider, self.protected):
            d.mkdir(parents=True, exist_ok=True)
        for sub in ('Music', 'Shaders', 'Sound', 'Video'):
            (self.install / 'Data' / sub).mkdir()
        for name in ('FalloutNV.exe', 'steam_api.dll', 'binkw32.dll', 'Fallout_default.ini'):
            (self.install / name).write_bytes(b'synthetic placeholder\n')
        (self.install / 'Data' / 'FalloutNV.esm').write_bytes(b'synthetic\n')
        (self.exe).write_bytes(b'synthetic rebuilt placeholder, not an executable\n')
        for name in ('d3dx9_38.dll', 'binkw32.dll'):
            (self.provider / name).write_bytes(b'synthetic\n')

    def args(self, *extra):
        return ['--installation', str(self.install), '--executable', str(self.exe),
                '--working-dir', str(self.work), '--isolated-profile', str(self.profile),
                '--dll-provider', str(self.provider), '--format', 'json'] + list(extra)

    def write_json(self, name, value):
        path = self.root / name
        path.write_text(json.dumps(value), encoding='utf-8')
        return path

    def snapshot(self):
        state = {}
        for base, dirs, files in os.walk(self.root):
            for name in dirs + files:
                path = Path(base) / name
                st = path.stat()
                digest = hashlib.sha256(path.read_bytes()).hexdigest() if path.is_file() else None
                state[str(path)] = (stat.S_IFMT(st.st_mode), st.st_size, st.st_mtime_ns, digest)
        return state


def run(argv):
    out = io.StringIO()
    err = io.StringIO()
    with mock.patch('sys.stderr', err):
        code = rc.main(argv, stdout=out)
    return code, out.getvalue(), err.getvalue()


def run_json(argv):
    code, out, err = run(argv)
    return code, (json.loads(out) if out else None), err


def item(report, item_id):
    for entry in report['items']:
        if entry['id'] == item_id:
            return entry
    raise KeyError(item_id)


def full_requirements(fixture, attest=ALL_CONTRACTS, requirements=None):
    return fixture.write_json('requirements.json', dict(
        schema=rc.REQUIREMENTS_SCHEMA, schema_version=1, provenance=provenance(),
        requirements=requirements if requirements is not None else [
            dict(id='master', role='installation', path='Data/FalloutNV.esm', kind='file'),
            dict(id='bink', role='dll_provider', path='binkw32.dll', kind='file'),
            dict(id='profile-root-ok', role='executable_directory', path='rebuilt.exe', kind='file')],
        attestations=[dict(contract=c, statement='synthetic attestation', provenance=provenance())
                      for c in attest]))


class Base(unittest.TestCase):
    def setUp(self):
        self._tmp = tempfile.TemporaryDirectory(prefix='fnv_readiness_test_')
        self.f = Fixture(self._tmp.name)

    def tearDown(self):
        self._tmp.cleanup()


class VerdictTests(Base):
    def test_no_inputs_is_unknown_and_executable_absent(self):
        code, report, _ = run_json(['--format', 'json'])
        self.assertEqual(code, 1)
        self.assertEqual(report['overall']['verdict'], 'unknown')
        self.assertTrue(report['overall']['executable_absent'])
        self.assertFalse(report['overall']['launch_authorized'])
        self.assertEqual(item(report, 'input.executable')['status'], 'unknown')

    def test_complete_layout_without_evidence_stays_unknown(self):
        code, report, _ = run_json(self.f.args())
        self.assertEqual(code, 1)
        self.assertEqual(report['overall']['verdict'], 'unknown')
        for role in ('installation', 'executable', 'working_directory', 'isolated_profile'):
            self.assertEqual(item(report, 'input.' + role)['status'], 'present')
        for contract in ALL_CONTRACTS:
            self.assertEqual(item(report, 'contract.' + contract)['status'], 'unknown')
        self.assertEqual(report['missing_necessary'], [])

    def test_absent_executable_is_not_ready(self):
        self.f.exe.unlink()
        code, report, _ = run_json(self.f.args(*['--requirements', str(full_requirements(self.f, requirements=[]))]))
        self.assertEqual(code, 3)
        self.assertEqual(report['overall']['verdict'], 'not-ready')
        self.assertTrue(report['overall']['executable_absent'])
        self.assertEqual(item(report, 'input.executable')['status'], 'missing')

    def test_all_attested_is_only_pending_review(self):
        code, report, _ = run_json(self.f.args('--requirements', str(full_requirements(self.f))))
        self.assertEqual(code, 4, report['unknown_necessary'] + report['missing_necessary'])
        overall = report['overall']
        self.assertEqual(overall['verdict'], 'attested-pending-review')
        self.assertFalse(overall['launch_authorized'])
        self.assertNotIn(overall['verdict'], ('ready', 'pass'))
        self.assertIn('does not authorize a launch', overall['statement'])
        for contract in ALL_CONTRACTS:
            self.assertEqual(item(report, 'contract.' + contract)['basis'], 'user-attested')

    def test_one_missing_attestation_keeps_unknown(self):
        path = full_requirements(self.f, attest=ALL_CONTRACTS[1:])
        code, report, _ = run_json(self.f.args('--requirements', str(path)))
        self.assertEqual(code, 1)
        self.assertEqual(report['unknown_necessary'], ['contract.' + ALL_CONTRACTS[0]])

    def test_verdict_values_never_claim_ready(self):
        self.assertEqual(set(rc.EXIT_CODES), {'attested-pending-review', 'unknown', 'not-ready'})
        self.assertNotIn(0, rc.EXIT_CODES.values())


class EvidenceSeparationTests(Base):
    def test_observed_snapshot_is_not_a_requirement(self):
        code, report, _ = run_json(self.f.args())
        entries = report['observed_inventory']['entries']
        self.assertTrue(all(e['necessary'] is False and e['confirmed_requirement'] is False for e in entries))
        status = {e['id']: e['status'] for e in entries}
        self.assertEqual(status['observed.steam_api.dll'], 'present')
        self.assertEqual(status['observed.Data/Update.bsa'], 'missing')
        self.assertEqual(status['observed.Data/DeadMoney - Sounds.bsa'], 'missing')
        # Missing snapshot names never make the verdict not-ready.
        self.assertNotIn('observed.Data/Update.bsa', report['missing_necessary'])
        self.assertNotEqual(report['overall']['verdict'], 'not-ready')

    def test_snapshot_size_compared_but_not_required(self):
        _, report, _ = run_json(self.f.args())
        entry = next(e for e in report['observed_inventory']['entries'] if e['id'] == 'observed.steam_api.dll')
        self.assertIs(entry['size_matches_snapshot'], False)
        self.assertEqual(entry['status'], 'present')

    def test_dll_name_in_provider_is_not_proof(self):
        _, report, _ = run_json(self.f.args())
        leads = {e['id']: e for e in report['investigation_leads']['entries']}
        self.assertEqual(len(leads), 19)
        self.assertEqual(leads['lead.d3dx9_38.dll']['filename_seen_in_providers'], [0])
        self.assertTrue(all(e['status'] == 'unknown' and not e['necessary'] for e in leads.values()))
        self.assertEqual(leads['lead.atiadlxx.dll']['basis'], 'original-dynamic-load-evidence')
        self.assertEqual(item(report, 'contract.dll_versions_and_exports')['status'], 'unknown')

    def test_inventory_matches_documented_imports(self):
        inventory, _ = rc.load_inventory()
        dlls = inventory['original_normal_imports']['dlls']
        self.assertEqual(len(dlls), 17)
        self.assertEqual(sum(d['slots'] for d in dlls), 280)


class RequirementTests(Base):
    def requirements(self, entries, **top):
        doc = dict(schema=rc.REQUIREMENTS_SCHEMA, schema_version=1, provenance=provenance(),
                   requirements=entries, attestations=[])
        doc.update(top)
        return str(self.f.write_json('req.json', doc))

    def test_present_and_missing_user_requirements(self):
        path = self.requirements([
            dict(id='esm', role='installation', path='Data/FalloutNV.esm', kind='file',
                 provenance=provenance(author='tester')),
            dict(id='absent', role='installation', path='Data/NotThere.bsa', kind='file'),
            dict(id='saves', role='isolated_profile', path='Saves', kind='directory')])
        code, report, _ = run_json(self.f.args('--requirements', path))
        self.assertEqual(code, 3)
        self.assertEqual(item(report, 'requirement.esm')['status'], 'present')
        self.assertEqual(item(report, 'requirement.esm')['provenance']['author'], 'tester')
        self.assertEqual(item(report, 'requirement.absent')['status'], 'missing')
        self.assertEqual(item(report, 'requirement.saves')['status'], 'missing')
        self.assertEqual(item(report, 'requirement.absent')['basis'], 'user-supplied')

    def test_wrong_kind_is_missing(self):
        path = self.requirements([dict(id='d', role='installation', path='Data', kind='file')])
        _, report, _ = run_json(self.f.args('--requirements', path))
        self.assertEqual(item(report, 'requirement.d')['status'], 'missing')
        self.assertIn('directory', item(report, 'requirement.d')['reason'])

    def test_size_constraints(self):
        size = (self.f.install / 'Data' / 'FalloutNV.esm').stat().st_size
        path = self.requirements([
            dict(id='ok', role='installation', path='Data/FalloutNV.esm', kind='file', expected_size_bytes=size),
            dict(id='small', role='installation', path='Data/FalloutNV.esm', kind='file', min_size_bytes=size + 1)])
        _, report, _ = run_json(self.f.args('--requirements', path))
        self.assertEqual(item(report, 'requirement.ok')['status'], 'present')
        self.assertEqual(item(report, 'requirement.small')['status'], 'missing')

    def test_unsafe_or_unbounded_paths_rejected_as_unknown(self):
        bad = ['../outside', str(self.f.root / 'abs'), 'C:/x', 'Data/Sound/deeper/x', 'Data/*.bsa', '', './x']
        entries = [dict(id='bad%d' % i, role='installation', path=p, kind='file') for i, p in enumerate(bad)]
        path = self.requirements(entries)
        code, report, _ = run_json(self.f.args('--requirements', path))
        for i in range(len(bad)):
            entry = item(report, 'requirement.bad%d' % i)
            self.assertEqual(entry['status'], 'unknown', bad[i])
            self.assertIn('rejected as untrusted', entry['reason'])
        self.assertEqual(code, 1)

    def test_invented_fields_and_bad_provenance_rejected(self):
        path = self.requirements([
            dict(id='ver', role='installation', path='Data', kind='directory', version='1.4.0.525'),
            dict(id='prov', role='installation', path='Data', kind='directory', provenance=dict(source='x')),
            dict(id='role', role='system32', path='d3d9.dll', kind='file')])
        _, report, _ = run_json(self.f.args('--requirements', path))
        for name in ('ver', 'prov', 'role'):
            self.assertEqual(item(report, 'requirement.' + name)['status'], 'unknown')

    def test_free_text_is_scrubbed_of_local_paths(self):
        secret = r'C:\Users\markerone\x'
        path = self.requirements(
            [dict(id='n', role='installation', path='Data', kind='directory', note='see %s now' % secret,
                  provenance=provenance(reference='/home/markertwo/notes.txt'))],
            attestations=[dict(contract='resource_identity', statement=r'checked in \\markerthree\share\x',
                               provenance=provenance(source='D:/markerfour/log.txt'))])
        _, out, _ = run(self.f.args('--requirements', path))
        for leaked in ('markerone', 'markertwo', 'markerthree', 'markerfour'):
            self.assertNotIn(leaked, out)
        self.assertIn('<redacted-path>', out)

    def test_requirements_without_top_level_provenance_refused(self):
        path = self.requirements([], provenance={'source': 'only'})
        code, _, err = run(self.f.args('--requirements', path))
        self.assertEqual(code, 2)
        self.assertIn('provenance', err)

    def test_attestation_needs_provenance_and_known_contract(self):
        path = self.requirements([], attestations=[
            dict(contract='platform_x86_windows_gui', statement='trust me'),
            dict(contract='made_up_contract', statement='x', provenance=provenance())])
        _, report, _ = run_json(self.f.args('--requirements', path))
        self.assertEqual(item(report, 'contract.platform_x86_windows_gui')['status'], 'unknown')
        self.assertEqual(len(report['requirements']['rejected_attestations']), 2)

    def test_checker_observed_items_cannot_be_attested(self):
        self.f.exe.unlink()
        path = self.requirements([], attestations=[
            dict(contract='rebuilt_executable_present', statement='x', provenance=provenance())])
        code, report, _ = run_json(self.f.args('--requirements', path))
        self.assertEqual(code, 3)
        self.assertEqual(item(report, 'input.executable')['status'], 'missing')

    def test_requirement_role_root_absent_is_unknown(self):
        path = self.requirements([dict(id='x', role='installation', path='Data', kind='directory')])
        _, report, _ = run_json(['--format', 'json', '--requirements', path])
        self.assertEqual(item(report, 'requirement.x')['status'], 'unknown')


class SafetyTests(Base):
    def findings(self, report):
        return {s['id']: s['severity'] for s in report['safety_findings']}

    def test_original_executable_is_blocked(self):
        code, report, _ = run_json(self.f.args('--executable', str(self.f.install / 'FalloutNV.exe')))
        self.assertEqual(code, 3)
        self.assertEqual(self.findings(report)['executable-is-original'], 'block')

    def test_executable_inside_installation_blocked(self):
        exe = self.f.install / 'rebuilt.exe'
        exe.write_bytes(b'synthetic')
        _, report, _ = run_json(self.f.args('--executable', str(exe)))
        self.assertEqual(self.findings(report)['executable-inside-installation'], 'block')

    def test_profile_overlapping_installation_blocked(self):
        for profile in (self.f.install / 'Data', self.f.root):
            _, report, _ = run_json(self.f.args('--isolated-profile', str(profile)))
            self.assertEqual(self.findings(report).get('profile-overlaps-installation'), 'block', profile)
            self.assertEqual(report['overall']['verdict'], 'not-ready')

    def test_profile_overlapping_protected_path_blocked(self):
        inner = self.f.protected / 'Saves'
        _, report, _ = run_json(self.f.args('--isolated-profile', str(self.f.protected),
                                            '--protected-path', str(inner)))
        self.assertEqual(self.findings(report)['profile-overlaps-protected[0]'], 'block')

    def test_protected_path_is_compared_not_opened(self):
        ghost = self.f.root / 'never-created'
        real_lstat = os.lstat
        seen = []

        def spy(path, *a, **k):
            seen.append(Path(path))
            return real_lstat(path, *a, **k)
        with mock.patch.object(rc.os, 'lstat', spy):
            code, report, _ = run_json(self.f.args('--protected-path', str(ghost)))
        self.assertNotIn(ghost, seen)
        self.assertFalse(ghost.exists())
        self.assertEqual(code, 1)

    def test_non_empty_profile_and_provider_warnings(self):
        (self.f.profile / 'leftover.txt').write_text('x')
        _, report, _ = run_json(self.f.args('--dll-provider', str(self.f.install)))
        found = self.findings(report)
        self.assertEqual(found['profile-not-empty'], 'warn')
        # The fixture supplies its own provider first, so the installation is provider 1.
        self.assertEqual(found['provider-in-installation[1]'], 'warn')
        self.assertEqual(item(report, 'input.isolated_profile')['evidence']['top_level_entries'], 1)

    def test_working_directory_inside_installation_warns(self):
        _, report, _ = run_json(self.f.args('--working-dir', str(self.f.install)))
        self.assertEqual(self.findings(report)['working-directory-inside-installation'], 'warn')

    def test_links_are_not_followed(self):
        fake = types.SimpleNamespace(st_mode=stat.S_IFREG, st_file_attributes=0x400, st_size=1)
        with mock.patch.object(rc.os, 'lstat', return_value=fake):
            status, reason, _ = rc.probe('anything', 'file')
        self.assertEqual(status, 'unknown')
        self.assertIn('not followed', reason)
        fake = types.SimpleNamespace(st_mode=stat.S_IFLNK | 0o777, st_size=1)
        with mock.patch.object(rc.os, 'lstat', return_value=fake):
            self.assertEqual(rc.probe('anything', 'file')[0], 'unknown')

    def test_permission_error_is_unknown_without_path(self):
        error = PermissionError(13, 'denied', str(self.f.root / 'secret'))
        with mock.patch.object(rc.os, 'lstat', side_effect=error):
            status, reason, _ = rc.probe(self.f.root / 'secret', 'file')
        self.assertEqual(status, 'unknown')
        self.assertNotIn(str(self.f.root), reason)


class ReadOnlyAndBoundedTests(Base):
    def test_fixture_tree_unchanged(self):
        requirements = str(full_requirements(self.f))
        before = self.f.snapshot()
        run(self.f.args('--requirements', requirements))
        run(self.f.args('--format', 'text'))
        after = self.f.snapshot()
        self.assertEqual(before, after)

    def test_no_recursive_scan_or_content_reads(self):
        game_roots = [self.f.install, self.f.exe, self.f.provider]
        real_open = open

        def guarded_open(path, *a, **k):
            if any(rc._within(path, root) for root in game_roots):
                raise AssertionError('opened a game/build/provider file')
            return real_open(path, *a, **k)
        boom = mock.Mock(side_effect=AssertionError('recursive or listing call'))
        real_scandir = os.scandir

        def guarded_scandir(path='.'):
            if rc._norm(path) != rc._norm(self.f.profile):
                raise AssertionError('listed a directory other than the isolated profile')
            return real_scandir(path)
        with mock.patch.object(rc.os, 'walk', boom), mock.patch.object(rc.os, 'listdir', boom), \
                mock.patch.object(rc.os, 'scandir', guarded_scandir), \
                mock.patch('builtins.open', guarded_open):
            code, _, err = run(self.f.args('--requirements', str(full_requirements(self.f))))
        self.assertEqual(code, 4, err)

    def test_stat_count_is_bounded(self):
        calls = []
        real = os.lstat
        with mock.patch.object(rc.os, 'lstat', lambda p, *a, **k: calls.append(p) or real(p, *a, **k)):
            run(self.f.args())
        # 5 roots + 66 snapshot names (+ one parent check for each Data/ entry)
        # + 19 leads x 1 provider + 2 identity checks: about 140 metadata reads.
        self.assertLessEqual(len(calls), 2000)

    def test_source_has_no_process_network_or_loader_imports(self):
        tree = ast.parse((TOOL_DIR / 'readiness_check.py').read_text(encoding='utf-8'))
        imported = set()
        for node in ast.walk(tree):
            if isinstance(node, ast.Import):
                imported |= {a.name.split('.')[0] for a in node.names}
            elif isinstance(node, ast.ImportFrom):
                imported.add((node.module or '').split('.')[0])
        forbidden = {'subprocess', 'socket', 'urllib', 'http', 'ctypes', 'winreg', 'shutil', 'requests', 'ssl'}
        self.assertEqual(imported & forbidden, set())
        source = (TOOL_DIR / 'readiness_check.py').read_text(encoding='utf-8')
        for call in ('os.system', 'os.startfile', 'os.popen', 'os.spawn', 'os.exec', 'LoadLibrary',
                     'toolchain.py', 'recipe_audit', 'build_and_match'):
            if call == 'toolchain.py':
                continue  # named in docs/comments as the report source only
            self.assertNotIn(call, source)


class PrivacyAndOutputTests(Base):
    def test_default_report_has_no_local_paths(self):
        report_path = self.f.root / 'out' / 'report.json'
        report_path.parent.mkdir()
        code, out, _ = run(self.f.args('--out', str(report_path)))
        written = report_path.read_text(encoding='utf-8')
        for text in (out, written):
            self.assertNotIn(str(self.f.root), text)
            self.assertNotIn(json.dumps(str(self.f.root))[1:-1], text)
            self.assertNotIn(self.f.root.name, text)
        self.assertFalse(json.loads(written)['privacy']['local_paths_included'])

    def test_text_report_has_no_local_paths(self):
        _, out, _ = run(self.f.args('--format', 'text'))
        self.assertNotIn(str(self.f.root), out)
        self.assertIn('launch authorized: no', out)
        self.assertIn('not requirements', out)

    def test_opt_in_local_detail_goes_only_to_out(self):
        code, _, err = run(self.f.args('--include-local-paths'))
        self.assertEqual(code, 2)
        self.assertIn('needs --out', err)
        target = self.f.root / 'private.json'
        code, out, _ = run(self.f.args('--include-local-paths', '--out', str(target)))
        self.assertEqual(code, 1)
        self.assertNotIn(str(self.f.root), out)
        self.assertFalse(json.loads(out)['privacy']['local_paths_included'])
        saved = json.loads(target.read_text(encoding='utf-8'))
        self.assertTrue(saved['privacy']['local_paths_included'])
        self.assertIn('PRIVATE', saved['privacy']['statement'])
        self.assertEqual(saved['local_detail']['installation'], os.path.abspath(str(self.f.install)))

    def test_leak_guard_raises(self):
        report = dict(privacy={}, leaked=os.path.abspath(str(self.f.install)))
        with self.assertRaises(RuntimeError):
            rc.finalize(report, dict(installation=self.f.install), False)

    def test_out_refuses_overwrite_and_protected_locations(self):
        existing = self.f.root / 'existing.json'
        existing.write_text('keep')
        code, _, err = run(self.f.args('--out', str(existing)))
        self.assertEqual(code, 2)
        self.assertEqual(existing.read_text(), 'keep')
        for target in (self.f.install / 'r.json', self.f.profile / 'r.json'):
            code, _, err = run(self.f.args('--out', str(target)))
            self.assertEqual(code, 2)
            self.assertFalse(target.exists())
        code, _, _ = run(self.f.args('--out', str(self.f.root / 'nodir' / 'r.json')))
        self.assertEqual(code, 2)
        self.assertFalse((self.f.root / 'nodir').exists())

    def test_overwrite_flag(self):
        target = self.f.root / 'r.json'
        target.write_text('old')
        code, _, _ = run(self.f.args('--out', str(target), '--overwrite'))
        self.assertEqual(code, 2)
        self.assertEqual(target.read_text(), 'old')

    def test_launch_arguments_redacted(self):
        manifest = self.f.write_json('m.json', dict(
            schema=rc.MANIFEST_SCHEMA, schema_version=1, paths={},
            launch=dict(arguments=['-windowed', 'C:\\Users\\someone\\x.ini', '/home/someone/y'])))
        _, report, _ = run_json(['--format', 'json', '--manifest', str(manifest)])
        self.assertEqual(report['launch']['arguments'], ['-windowed', '<redacted-path>', '<redacted-path>'])


class ManifestTests(Base):
    def manifest(self, **doc):
        base = dict(schema=rc.MANIFEST_SCHEMA, schema_version=1)
        base.update(doc)
        return str(self.f.write_json('manifest.json', base))

    def test_relative_paths_resolve_against_manifest(self):
        path = self.manifest(paths=dict(installation='owned-install', executable='private-build/rebuilt.exe',
                                        working_directory='workdir', isolated_profile='isolated-profile',
                                        dll_providers=['providers']),
                             protected_paths=['existing-user-config'])
        code, report, _ = run_json(['--format', 'json', '--manifest', path])
        self.assertEqual(code, 1)
        for role in ('installation', 'executable', 'working_directory', 'isolated_profile'):
            self.assertEqual(item(report, 'input.' + role)['status'], 'present')
        self.assertTrue(report['manifest']['supplied'])
        self.assertEqual(len(report['manifest']['sha256']), 64)

    def test_cli_overrides_manifest(self):
        path = self.manifest(paths=dict(executable='does-not-exist.exe'))
        _, report, _ = run_json(['--format', 'json', '--manifest', path, '--executable', str(self.f.exe)])
        self.assertEqual(item(report, 'input.executable')['status'], 'present')

    def test_bad_manifests_refused(self):
        cases = [dict(schema='other', schema_version=1),
                 dict(schema=rc.MANIFEST_SCHEMA, schema_version=2),
                 dict(schema=rc.MANIFEST_SCHEMA, schema_version=1, paths=dict(steam='x')),
                 dict(schema=rc.MANIFEST_SCHEMA, schema_version=1, credentials='x'),
                 dict(schema=rc.MANIFEST_SCHEMA, schema_version=1, launch=dict(arguments='-x'))]
        for case in cases:
            path = self.f.write_json('bad.json', case)
            code, out, err = run(['--manifest', str(path)])
            self.assertEqual(code, 2, case)
            self.assertNotIn(str(self.f.root), err)

    def test_invalid_and_oversized_json_refused(self):
        bad = self.f.root / 'bad.json'
        bad.write_text('{not json')
        self.assertEqual(run(['--manifest', str(bad)])[0], 2)
        big = self.f.root / 'big.json'
        big.write_bytes(b' ' * (rc.MAX_JSON_BYTES + 1))
        code, _, err = run(['--manifest', str(big)])
        self.assertEqual(code, 2)
        self.assertIn('larger than', err)

    def test_example_files_are_valid_schemas(self):
        manifest = json.loads((TOOL_DIR / 'examples' / 'manifest.example.json').read_text(encoding='utf-8'))
        self.assertEqual((manifest['schema'], manifest['schema_version']), (rc.MANIFEST_SCHEMA, 1))
        requirements = json.loads((TOOL_DIR / 'examples' / 'requirements.example.json').read_text(encoding='utf-8'))
        self.assertEqual((requirements['schema'], requirements['schema_version']), (rc.REQUIREMENTS_SCHEMA, 1))
        self.assertTrue(set(a['contract'] for a in requirements['attestations']) <= set(ALL_CONTRACTS))


class ToolchainReportTests(Base):
    def report(self, value):
        return str(self.f.write_json('doctor.json', value))

    def doctor(self, ready=True):
        entry = lambda n: dict(compiler=n, ready=ready, version='15.00.30729.01', root=str(self.f.root / 'msvc'),
                               banner='Microsoft (R) secret banner', cl_sha256='0' * 64)
        return dict(schema_version=1, toolchains={n: entry(n) for n in rc.TOOLCHAIN_NAMES})

    def test_valid_report_consumed_as_data_only(self):
        _, report, _ = run_json(self.f.args('--toolchain-report', self.report(self.doctor())))
        toolchain = report['toolchain_report']
        self.assertEqual(toolchain['status'], 'present')
        self.assertFalse(toolchain['necessary'])
        rendered = json.dumps(report)
        self.assertNotIn('secret banner', rendered)
        self.assertNotIn('msvc', rendered)
        self.assertEqual(report['overall']['verdict'], 'unknown')

    def test_not_ready_report(self):
        _, report, _ = run_json(self.f.args('--toolchain-report', self.report(self.doctor(ready=False))))
        self.assertEqual(report['toolchain_report']['status'], 'missing')

    def test_unrecognized_schema_is_unknown(self):
        for value in (dict(schema_version=2, toolchains={}), dict(toolchains={}), [1, 2],
                      dict(schema_version=1, toolchains=dict(sp1=dict(ready='yes')))):
            _, report, _ = run_json(self.f.args('--toolchain-report', self.report(value)))
            self.assertEqual(report['toolchain_report']['status'], 'unknown', value)

    def test_missing_report_is_unknown_not_crash(self):
        code, report, _ = run_json(self.f.args('--toolchain-report', str(self.f.root / 'absent.json')))
        self.assertEqual(report['toolchain_report']['status'], 'unknown')
        self.assertEqual(code, 1)


if __name__ == '__main__':
    unittest.main()
