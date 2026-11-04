import hashlib
import importlib.util
import json
from pathlib import Path
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[2]
spec = importlib.util.spec_from_file_location('recipe_audit', ROOT / 'tools/rebuild/recipe_audit.py')
audit = importlib.util.module_from_spec(spec)
spec.loader.exec_module(audit)


def unit(source, functions, symbols=None, eh=None):
    return {'source': source, 'compiler': 'sp1', 'flags': ['/O2'], 'functions': functions,
            'symbols': symbols or {}, 'eh_tails': eh or []}


def fun(addr, name, size):
    return {'address': addr, 'symbol': name, 'size': size}


class RecipeAuditTests(unittest.TestCase):
    def setUp(self):
        self.manifest = {'units': [
            unit('src/a.cpp', [fun('0x10', '?same', 8), fun('0x14', '?other', 8)],
                 {'?ref': '0x20'}, [{'address': '0x30', 'size': 4, 'parent': '0x10'}]),
            unit('src/a.cpp', [fun('0x00000010', '?same', 8), fun('0x20', '?same', 4)],
                 {'?ref': '0x21'})]}

    def test_graph_collisions_union_and_selection(self):
        result = audit.audit(self.manifest, {'0x10': 1})
        c = result['counts']
        self.assertEqual((c['recipes'], c['source_paths'], c['function_rows'], c['unique_function_addresses']), (2, 1, 4, 3))
        self.assertEqual((c['function_aggregate_row_bytes'], c['function_address_range_union_bytes']), (28, 16))
        self.assertEqual(c['function_symbols_at_multiple_addresses'], 1)
        self.assertEqual(result['explicit_selections'], {'0x00000010': 1})
        self.assertEqual(result['graph']['eh_by_address']['0x00000030'][0]['parent'], '0x00000010')
        self.assertEqual(len(result['potential_collisions']['symbol_mappings_at_multiple_addresses']), 1)
        self.assertEqual(len(result['potential_collisions']['function_addresses_in_multiple_rows']), 1)

    def test_selection_must_be_explicit_candidate(self):
        with self.assertRaises(ValueError):
            audit.audit(self.manifest, {'0x10': 7})
        self.assertEqual(audit.audit(self.manifest)['explicit_selections'], {})

    def test_cli_writes_to_explicit_directory_without_manifest_change(self):
        with tempfile.TemporaryDirectory() as tmp:
            directory = Path(tmp); path = directory / 'manifest.json'
            original = json.dumps(self.manifest); path.write_text(original, encoding='utf-8')
            self.assertEqual(audit.main(['--manifest', str(path), '--out', str(directory / 'out'), '--select', '0x10=0']), 0)
            with self.assertRaises(SystemExit):
                audit.main(['--manifest', str(path), '--out', str(directory / 'out')])
            self.assertEqual(audit.main(['--manifest', str(path), '--out', str(directory / 'out'), '--force', '--select', '0x10=0']), 0)
            self.assertEqual(path.read_text(encoding='utf-8'), original)
            self.assertTrue((directory / 'out/recipe-audit.md').is_file())
            report = json.loads((directory / 'out/recipe-audit.json').read_text(encoding='utf-8'))
            self.assertEqual(report['provenance']['manifest_sha256'], hashlib.sha256(path.read_bytes()).hexdigest())
            self.assertFalse(report['provenance']['source_content_hashed'])
            self.assertIn(report['provenance']['manifest_sha256'], (directory / 'out/recipe-audit.md').read_text(encoding='utf-8'))
            self.assertEqual(json.loads((directory / 'out/recipe-audit.json').read_text(encoding='utf-8'))['explicit_selections'], {'0x00000010': 0})

    def test_rejects_invalid_path_and_size(self):
        self.manifest['units'][0]['source'] = '../private.cpp'
        with self.assertRaises(ValueError): audit.audit(self.manifest)
        self.manifest['units'][0]['source'] = 'src/a.cpp'
        self.manifest['units'][0]['functions'][0]['size'] = -1
        with self.assertRaises(ValueError): audit.audit(self.manifest)

    def test_actual_manifest_read_only(self):
        path = ROOT / 'build/units.json'
        before = path.stat().st_mtime_ns
        with path.open(encoding='utf-8') as stream:
            result = audit.audit(json.load(stream))
        self.assertEqual(path.stat().st_mtime_ns, before)
        c = result['counts']
        self.assertEqual((c['recipes'], c['source_paths'], c['function_rows'], c['unique_function_addresses'], c['eh_rows']), (2988, 2978, 68667, 68657, 1954))
        self.assertEqual(c['function_symbols_at_multiple_addresses'], 19)
        self.assertEqual(result['explicit_selections'], {})


if __name__ == '__main__': unittest.main()
