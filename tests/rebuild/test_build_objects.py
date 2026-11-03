"""Recipe identity, failure isolation and retained-object integrity checks."""
import json
from pathlib import Path
import sys
import tempfile
import unittest
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[2] / 'tools/rebuild'))
import build_objects
import toolchain


class RetainedObjectsTests(unittest.TestCase):
    def test_variants_and_duplicate_recipes_have_distinct_identity(self):
        a = dict(source='src/example.cpp', compiler='sp1', flags=['/O2'], functions=[])
        b = dict(a, flags=['/O1'])
        self.assertNotEqual(build_objects.recipe_id(0, a), build_objects.recipe_id(1, a))
        self.assertNotEqual(build_objects.recipe_id(0, a), build_objects.recipe_id(0, b))
        reordered = dict(reversed(list(a.items())))
        self.assertEqual(build_objects.recipe_id(0, a), build_objects.recipe_id(0, reordered))

    def test_reject_source_outside_repository(self):
        with tempfile.TemporaryDirectory() as temporary:
            base = Path(temporary)
            root = base / 'root'
            root.mkdir()
            (base / 'outside.cpp').write_text('int outside;')
            manifest = root / 'units.json'
            manifest.write_text(json.dumps(dict(units=[dict(source='../outside.cpp', compiler='sp1', flags=[])])))
            with self.assertRaises(ValueError):
                build_objects.load_recipes(manifest, root)

    def test_compile_retains_object_and_hash_for_each_variant(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            (root / 'src').mkdir()
            (root / 'src/example.cpp').write_text('int example;')
            output = root / 'private'
            output.mkdir()
            unit = dict(source='src/example.cpp', compiler='sp1', flags=['/O2'], functions=[])
            compilers = dict(sp1=dict(ready=True, root=str(root)))
            def compile_object(command, *args):
                Path(next(x[3:] for x in command if x.startswith('/Fo'))).write_bytes(b'fake-coff-for-control-test')
                return 0, 'compiled'
            with patch.object(toolchain, 'run', side_effect=compile_object):
                a = build_objects.build_one((0, unit), root, output, output / 'run', compilers)
                b = build_objects.build_one((1, unit), root, output, output / 'run', compilers)
            self.assertEqual(a['status'], 'compiled')
            self.assertNotEqual(a['object'], b['object'])
            self.assertEqual(a['object_sha256'], toolchain.sha256(output / a['object']))
            self.assertFalse(a['reusable'])

    def test_unavailable_compiler_does_not_compile(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            (root / 'example.cpp').write_text('int example;')
            unit = dict(source='example.cpp', compiler='rtm', flags=[], functions=[])
            with patch.object(toolchain, 'run') as run:
                result = build_objects.build_one((0, unit), root, root, root / 'run',
                                                 dict(rtm=dict(ready=False, error='missing')))
            run.assert_not_called()
            self.assertEqual(result['status'], 'toolchain-unavailable')
            self.assertNotIn('object', result)

    def test_implicit_cl_flags_are_removed(self):
        with patch.dict(toolchain.os.environ, {'CL': '/O1', '_CL_': '/Od'}):
            env = toolchain.environment(Path('private-toolchain'))
        self.assertNotIn('CL', env)
        self.assertNotIn('_CL_', env)


if __name__ == '__main__':
    unittest.main()
