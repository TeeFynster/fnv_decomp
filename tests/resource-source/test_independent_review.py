"""Independent path-isolation regressions using synthetic files."""
import json
import os
from pathlib import Path
import stat
import sys
import tempfile
import types
import unittest
from unittest import mock

sys.path.insert(0, str(Path(__file__).resolve().parents[2] / 'tools/resource-source'))
import resource_source as rs


class ReviewTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory(); self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        self.parent = self.root / 'indirect'; self.parent.mkdir()
        self.input = self.parent / 'm.json'
        self.input.write_text(json.dumps({'schema_version': 1, 'resources': []}))

    def test_mock_reparse_parent_rejected_on_input_and_output(self):
        real = os.lstat
        def fake(path, *args, **kwargs):
            if Path(path) == self.parent:
                return types.SimpleNamespace(st_mode=stat.S_IFDIR, st_file_attributes=0x400)
            return real(path, *args, **kwargs)
        with mock.patch.object(rs.os, 'lstat', fake):
            with self.assertRaisesRegex(rs.UsageError, 'ancestor'): rs.read_manifest(str(self.input))
            with self.assertRaisesRegex(rs.UsageError, 'ancestor'):
                rs.write_output(str(self.parent / 'out.rc'), b'test', str(self.input))
        self.assertFalse((self.parent / 'out.rc').exists())

    def test_existing_hardlink_never_overwritten(self):
        victim = self.root / 'private.txt'; victim.write_bytes(b'preserve')
        target = self.root / 'output.rc'
        try: os.link(victim, target)
        except OSError: self.skipTest('hardlinks unavailable')
        rs.write_output(str(target), b'overwrite', str(self.input), True)
        self.assertEqual(victim.read_bytes(), b'preserve')
        self.assertEqual(target.read_bytes(), b'overwrite')
        self.assertFalse(os.path.samefile(target, victim))

    def test_reserved_ancestor_and_unc_rejected_before_access(self):
        with mock.patch.object(rs.os, 'lstat') as probe:
            for path in (r'C:\NUL\thing.json', r'\\server\share\thing.json'):
                with self.assertRaises(rs.UsageError): rs.read_manifest(path)
            probe.assert_not_called()

    def test_actual_symlink_parent_when_available(self):
        link = self.root / 'link'
        try: link.symlink_to(self.parent, target_is_directory=True)
        except OSError: self.skipTest('symlink creation not permitted')
        with self.assertRaises(rs.UsageError): rs.read_manifest(str(link / 'm.json'))
        with self.assertRaises(rs.UsageError): rs.write_output(str(link / 'new.rc'), b'x', str(self.input))

    def test_failed_atomic_replace_cleans_own_temp(self):
        target = self.root / 'existing.rc'; target.write_bytes(b'old')
        before = set(self.root.iterdir())
        with mock.patch.object(rs.os, 'replace', side_effect=OSError(5, 'synthetic')):
            with self.assertRaises(rs.UsageError): rs.write_output(str(target), b'new', str(self.input), True)
        self.assertEqual(target.read_bytes(), b'old')
        self.assertEqual(set(self.root.iterdir()), before)

    def test_failed_cleanup_is_redacted_and_reported(self):
        target = self.root / 'existing.rc'; target.write_bytes(b'old')
        with mock.patch.object(rs.os, 'replace', side_effect=OSError(5, 'replace')):
            with mock.patch.object(rs.os, 'unlink', side_effect=PermissionError(13, str(self.root))):
                with self.assertRaises(rs.UsageError) as raised:
                    rs.write_output(str(target), b'new', str(self.input), True)
        self.assertIn('temporary file may remain', str(raised.exception))
        self.assertNotIn(str(self.root), str(raised.exception))
        self.assertEqual(target.read_bytes(), b'old')
