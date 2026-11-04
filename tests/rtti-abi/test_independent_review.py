"""Synthetic review regressions; no native tools or game inputs."""
import os
from pathlib import Path
import stat
import sys
import tempfile
import types
import unittest
from unittest import mock
sys.path.insert(0,str(Path(__file__).resolve().parents[2]/'tools/rtti-abi'))
import rtti_abi as ra

class ReviewTests(unittest.TestCase):
    def test_ancestor_reparse_rejected_before_input_open(self):
        with tempfile.TemporaryDirectory() as tmp:
            parent=Path(tmp)/'parent';parent.mkdir();target=parent/'x.json';target.write_text('{}')
            real=os.lstat
            def fake(path,*args,**kwargs):
                if Path(path)==parent:return types.SimpleNamespace(st_mode=stat.S_IFDIR,st_file_attributes=0x400)
                return real(path,*args,**kwargs)
            with mock.patch.object(ra.os,'lstat',side_effect=fake), mock.patch('builtins.open') as opened:
                with self.assertRaises(ra.UsageError):ra.read_input(str(target))
                opened.assert_not_called()
    def test_unc_and_reserved_ancestor_rejected_before_metadata(self):
        with mock.patch.object(ra.os,'lstat') as probe:
            for path in (r'\\server\share\a.json',r'C:\NUL\a.json'):
                with self.assertRaises(ra.UsageError):ra.read_input(path)
            probe.assert_not_called()
    def test_lifetime_and_buffer_preconditions_are_explicit(self):
        source=(Path(__file__).resolve().parents[2]/'tools/rtti-abi/fixture/rtti_abi_fixture.h').read_text()
        self.assertIn('owns no live objects',source)
        self.assertIn('array with at least capacity CaseResult elements',source)
