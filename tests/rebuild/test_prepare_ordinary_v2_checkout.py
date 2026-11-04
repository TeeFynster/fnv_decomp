import ast
import hashlib
import os
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest
from unittest.mock import patch

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tools' / 'rebuild'))
import prepare_ordinary_v2_checkout as prep


class CheckoutIdentityTests(unittest.TestCase):
    def setUp(self):
        self.lf = b'def f(x):\n    return x + 1\n'
        self.crlf = self.lf.replace(b'\n', b'\r\n')
        self.pairs = {'fixture-crlf': (hashlib.sha256(self.lf).hexdigest(), hashlib.sha256(self.crlf).hexdigest(), 'crlf'),
                      'fixture-lf': (hashlib.sha256(self.lf).hexdigest(), hashlib.sha256(self.crlf).hexdigest(), 'lf')}
        self.patches = patch.object(prep, 'PAIRS', self.pairs)
        self.patches.start()
        self.addCleanup(self.patches.stop)

    def test_both_reviewed_forms_and_both_target_forms(self):
        for data in (self.lf, self.crlf):
            self.assertEqual(prep.reviewed_bytes(data, 'fixture-crlf'), self.crlf)
            self.assertEqual(prep.reviewed_bytes(data, 'fixture-lf'), self.lf)
        self.assertEqual(ast.dump(ast.parse(self.lf), include_attributes=True), ast.dump(ast.parse(self.crlf), include_attributes=True))

    def test_reject_changed_comment_semantics_bom_mixed_and_unknown(self):
        for bad in (self.lf.replace(b'+ 1', b'+ 2'), self.lf + b'# comment\n', b'\xef\xbb\xbf' + self.lf,
                    self.lf.replace(b'\n', b'\r\n', 1), self.lf.rstrip(b'\n'), b''):
            with self.subTest(data=bad), self.assertRaises(ValueError):
                prep.reviewed_bytes(bad, 'fixture-crlf')

    def test_both_hashes_are_required(self):
        a, b, c = self.pairs['fixture-crlf']
        for entry, data in (((a, '0'*64, c), self.lf), (('0'*64, b, c), self.crlf)):
            with patch.dict(prep.PAIRS, {'bad': entry}), self.assertRaises(ValueError):
                prep.reviewed_bytes(data, 'bad')

    def test_root_containment_and_exclusive_creation(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp) / 'out'; root.mkdir()
            src = Path(tmp) / 'input'; src.write_bytes(self.lf)
            (root / 'existing.py').write_bytes(b'original')
            for target in ('../escape', str(Path(tmp) / 'absolute'), 'existing.py:shadow', 'NUL.txt', 'dir./file', 'dir /file', 'COM¹.txt', 'wild?.py'):
                with self.subTest(target=target), self.assertRaises(ValueError):
                    prep.materialize(src, root, target, 'fixture-crlf')
            self.assertEqual((root / 'existing.py').read_bytes(), b'original')
            prep.materialize(src, root, 'out.py', 'fixture-crlf')
            with self.assertRaises(FileExistsError):
                prep.materialize(src, root, 'out.py', 'fixture-crlf')
            self.assertEqual((root / 'out.py').read_bytes(), self.crlf)
            src.write_bytes(b'unknown')
            with self.assertRaises(ValueError):
                prep.materialize(src, root, 'bad.py', 'fixture-crlf')
            self.assertFalse((root / 'bad.py').exists())

    def test_junction_and_target_symlink_rejected(self):
        with tempfile.TemporaryDirectory() as tmp:
            base = Path(tmp); root = base/'root'; outside = base/'outside'
            root.mkdir(); outside.mkdir(); src=base/'input'; src.write_bytes(self.lf)
            junction = root/'junction'
            if os.name == 'nt':
                subprocess.run(['cmd', '/c', 'mklink', '/J', str(junction), str(outside)], check=True, capture_output=True)
            else:
                junction.symlink_to(outside, target_is_directory=True)
            with self.assertRaises(ValueError):
                prep.materialize(src, root, 'junction/escaped.py', 'fixture-crlf')
            self.assertFalse((outside/'escaped.py').exists())
            target = root/'target.py'
            try:
                target.symlink_to(outside/'missing.py')
            except OSError as e:
                self.skipTest('file symlink unavailable: ' + str(e))
            with self.assertRaises(FileExistsError):
                prep.materialize(src, root, 'target.py', 'fixture-crlf')
            self.assertFalse((outside/'missing.py').exists())


class PublishedPairTests(unittest.TestCase):
    def test_published_source_pairs(self):
        for name, identity in (('root_code_closure.py', 'ordinary-v2'), ('coff_code_archive.py', 'coff-archive-v1'), ('ordinary_initialized_data_omission.py', 'omission-v1')):
            with self.subTest(name=name):
                raw = (ROOT / 'tools/rebuild' / name).read_bytes()
                lf = raw.replace(b'\r\n', b'\n'); crlf = lf.replace(b'\n', b'\r\n')
                lf_hash, crlf_hash, target = prep.PAIRS[identity]
                self.assertEqual(hashlib.sha256(lf).hexdigest(), lf_hash)
                self.assertEqual(hashlib.sha256(crlf).hexdigest(), crlf_hash)
                self.assertEqual(prep.reviewed_bytes(raw, identity), {'lf': lf, 'crlf': crlf}[target])


if __name__ == '__main__':
    unittest.main()
