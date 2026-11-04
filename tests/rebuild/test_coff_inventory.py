"""Small original synthetic COFF fixtures: no game or toolchain is required."""
import importlib.util
import json
from pathlib import Path
import struct
import subprocess
import sys
import tempfile
import unittest

MODULE = Path(__file__).resolve().parents[2] / 'tools/rebuild/coff_inventory.py'
spec = importlib.util.spec_from_file_location('coff_inventory', MODULE)
coff_inventory = importlib.util.module_from_spec(spec)
spec.loader.exec_module(coff_inventory)


def fixture(symbols, *, comdat=0, relocs=(), name=b'.text', flags=0x60000020):
    """symbols are (name, value, section, storage, auxiliary byte records)."""
    strings = bytearray(b'\0' * 4)
    records = bytearray()
    count = 0
    if comdat:
        flags |= 0x1000
        symbols = [(name.decode(), 0, 1, 3,
                    [struct.pack('<IHHIhBBH', 4, len(relocs), 0, 0, 0, comdat, 0, 0)])] + symbols
    for symbol_name, value, section, storage, aux in symbols:
        encoded = symbol_name.encode()
        if len(encoded) > 8:
            encoded_name = struct.pack('<II', 0, len(strings))
            strings.extend(encoded + b'\0')
        else:
            encoded_name = encoded.ljust(8, b'\0')
        records.extend(struct.pack('<8sIhHBB', encoded_name, value, section, 0, storage, len(aux)))
        for record in aux:
            assert len(record) == 18
            records.extend(record)
        count += 1 + len(aux)
    struct.pack_into('<I', strings, 0, len(strings))
    rel_data = b''.join(struct.pack('<IIH', *r) for r in relocs)
    symptr = 64 + len(rel_data)
    return (struct.pack('<HHIIIHH', 0x14c, 1, 0, symptr, count, 0, 0) +
            struct.pack('<8sIIIIIIHHI', name.ljust(8, b'\0'), 0, 0, 4, 60,
                        64 if relocs else 0, 0, len(relocs), 0, flags) +
            b'\0' * 4 + rel_data + records + strings)


class InventoryTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)

    def inspect(self, data, identity='one'):
        path = self.root / (identity + '.obj')
        path.write_bytes(data)
        return coff_inventory.inspect_object(path, dict(recipe_id=identity,
            source='fixture.cpp', recipe=dict(symbols={'_external': '0x1234'})))

    def test_static_symbols_never_collide_globally(self):
        data = fixture([('$SG123', 0, 1, 3, []), ('.text', 0, 1, 3, [])])
        report = coff_inventory.summarize([self.inspect(data), self.inspect(data, 'two')])
        self.assertEqual(report['duplicates'], [])
        self.assertEqual(report['definition_names'], 0)

    def test_definitions_references_imports_and_data_origins(self):
        obj = self.inspect(fixture([('_own', 0, 1, 2, []),
            ('_external', 0, 0, 2, []), ('__imp__Api@0', 0, 0, 2, [])],
            relocs=[(0, 1, 6), (0, 2, 6)], name=b'.data', flags=0xc0000040))
        self.assertEqual(obj['relocations'][0]['origin_kind'], 'data_or_metadata')
        self.assertEqual(obj['relocations'][0]['original_address'], '0x00001234')
        self.assertTrue(obj['relocations'][1]['import_pointer'])
        report = coff_inventory.summarize([obj])
        self.assertEqual(report['unresolved'][0]['category'], 'import_library_provider_required')
        self.assertEqual(report['definition_names'], 1)

    def test_strong_duplicate_and_aliases(self):
        data = fixture([('_first', 0, 1, 2, []), ('_alias', 0, 1, 2, [])])
        obj = self.inspect(data)
        self.assertEqual(obj['defined_aliases'][0]['names'], ['_first', '_alias'])
        report = coff_inventory.summarize([obj, self.inspect(data, 'two')])
        self.assertEqual(report['duplicates'][0]['category'], 'multiple_strong_definitions')

    def test_comdat_aux_entries_are_not_symbol_records(self):
        data = fixture([('_func', 0, 1, 2, []), ('_external', 0, 0, 2, [])],
                       comdat=2, relocs=[(0, 3, 20)])
        obj = self.inspect(data)
        self.assertEqual(len(obj['symbols']), 3)
        self.assertEqual(obj['sections'][0]['selection'], 'any')
        self.assertEqual(obj['relocations'][0]['target'], '_external')
        self.assertEqual(coff_inventory.summarize([obj, self.inspect(data, 'two')])
                         ['duplicates'][0]['category'], 'comdat_policy_review_required')

    def test_associative_comdat(self):
        obj = self.inspect(fixture([('_eh', 0, 1, 2, [])], comdat=5))
        self.assertEqual(obj['sections'][0]['selection'], 'associative')
        self.assertEqual(obj['sections'][0]['association'], 0)

    def test_weak_fallback_common_absolute(self):
        weak_aux = struct.pack('<II', 2, 3) + bytes(10)
        obj = self.inspect(fixture([('_weak', 0, 0, 105, [weak_aux]),
             ('_fallback', 0, 0, 2, []), ('_common', 32, 0, 2, []),
             ('_absolute', 42, -1, 2, [])]))
        self.assertEqual(obj['symbols'][0]['weak']['fallback'], '_fallback')
        summary = coff_inventory.summarize([obj])
        self.assertEqual(summary['weak_externals'][0]['name'], '_weak')
        self.assertEqual(summary['definition_names'], 2)

    def test_invalid_relocation_to_aux_rejected(self):
        with self.assertRaisesRegex(coff_inventory.CoffError, 'auxiliary symbol'):
            self.inspect(fixture([('_func', 0, 1, 2, [])], comdat=2,
                                 relocs=[(0, 1, 20)]))

    def test_bounds_and_machine_rejected(self):
        data = fixture([('_func', 0, 1, 2, [])])
        with self.assertRaises(coff_inventory.CoffError):
            self.inspect(data[:-2])
        with self.assertRaises(coff_inventory.CoffError):
            self.inspect(b'\x64\x86' + data[2:])

    def test_manifest_hash_bound_and_partial(self):
        data = fixture([('_func', 0, 1, 2, [])])
        (self.root / 'unit.obj').write_bytes(data)
        manifest = dict(schema_version=1, kind='fnv-retained-objects', units=[
            dict(recipe_id='one', status='compiled', object='unit.obj', object_sha256='bad'),
            dict(recipe_id='two', status='toolchain-unavailable')])
        path = self.root / 'objects.json'
        path.write_text(json.dumps(manifest))
        report = coff_inventory.inventory(path)
        self.assertFalse(report['supplied_manifest_complete'])
        self.assertEqual(len(report['errors']), 1)
        self.assertEqual(len(report['omitted']), 1)
        manifest['units'][0]['object_sha256'] = coff_inventory.hashlib.sha256(data).hexdigest()
        path.write_text(json.dumps(manifest))
        report = coff_inventory.inventory(path)
        self.assertEqual(report['retained_object_count'], 1)
        self.assertEqual(report['errors'], [])

    def test_ambiguous_original_addresses_preserved(self):
        data = fixture([('_func', 0, 1, 2, [])])
        path = self.root / 'addresses.obj'
        path.write_bytes(data)
        obj = coff_inventory.inspect_object(path, dict(recipe_id='one', source='fixture.cpp',
            recipe=dict(functions=[dict(symbol='_func', address='0x1000'),
                                   dict(symbol='_func', address='0x2000')],
                        symbols={'_func': '0x3000'})))
        symbol = obj['symbols'][0]
        self.assertEqual(symbol['original_addresses'], ['0x00001000', '0x00002000', '0x00003000'])
        self.assertNotIn('original_address', symbol)

    def test_address_spelling_does_not_create_false_ambiguity(self):
        path = self.root / 'spelling.obj'
        path.write_bytes(fixture([('_func', 0, 1, 2, [])]))
        obj = coff_inventory.inspect_object(path, dict(recipe_id='one', source='fixture.cpp',
            recipe=dict(functions=[dict(symbol='_func', address='0x0000ABCD')],
                        symbols={'_func': '0xabcd'})))
        self.assertEqual(obj['symbols'][0]['original_addresses'], ['0x0000abcd'])
        self.assertEqual(obj['symbols'][0]['original_address'], '0x0000abcd')

    def test_extended_relocations_and_malformed_marker(self):
        data = bytearray(fixture([('_external', 0, 0, 2, [])], relocs=[(0, 0, 20)]))
        # Insert the overflow marker before the sole relocation, shift symbol table.
        struct.pack_into('<I', data, 8, 84)
        struct.pack_into('<H', data, 52, 0xffff)
        struct.pack_into('<I', data, 56, 0x61000020)
        data[64:64] = struct.pack('<IIH', 2, 0, 0)
        obj = self.inspect(data)
        self.assertEqual(len(obj['relocations']), 1)
        struct.pack_into('<I', data, 68, 1)
        with self.assertRaisesRegex(coff_inventory.CoffError, 'extended relocation marker'):
            self.inspect(data)

    def test_manifest_relative_object_root_and_empty_rejected(self):
        data = fixture([('_func', 0, 1, 2, [])])
        (self.root / 'unit.obj').write_bytes(data)
        sub = self.root / 'run'
        sub.mkdir()
        path = sub / 'objects.json'
        manifest = dict(schema_version=1, kind='fnv-retained-objects', object_root_relative='..',
            units=[dict(recipe_id='one', source='fixture.cpp', status='compiled', object='unit.obj',
                        object_sha256=coff_inventory.hashlib.sha256(data).hexdigest())])
        path.write_text(json.dumps(manifest))
        report = coff_inventory.inventory(path)
        self.assertTrue(report['supplied_manifest_complete'])
        self.assertFalse(report['full_recipe_coverage_declared'])
        manifest['units'] = []
        path.write_text(json.dumps(manifest))
        with self.assertRaisesRegex(ValueError, 'nonempty'):
            coff_inventory.inventory(path)

    def test_cli_partial_full_and_evidence_overwrite(self):
        data = fixture([('_func', 0, 1, 2, [])])
        obj = self.root / 'unit.obj'
        obj.write_bytes(data)
        manifest = self.root / 'objects.json'
        manifest.write_text(json.dumps(dict(schema_version=1, kind='fnv-retained-objects',
            selection=dict(total_recipes=2, selected_recipes=1, complete=False),
            units=[dict(recipe_id='one', source='fixture.cpp', status='compiled',
                        object='unit.obj', object_sha256=coff_inventory.hashlib.sha256(data).hexdigest())])))
        command = [sys.executable, str(MODULE), '--manifest', str(manifest)]
        output = self.root / 'inventory.json'
        self.assertEqual(subprocess.run(command + ['--out', str(output)], capture_output=True).returncode, 0)
        self.assertEqual(subprocess.run(command + ['--out', str(self.root / 'full.json'), '--require-full'], capture_output=True).returncode, 1)
        prior = output.read_bytes()
        self.assertEqual(subprocess.run(command + ['--out', str(output)], capture_output=True).returncode, 2)
        self.assertEqual(output.read_bytes(), prior)
        before = manifest.read_bytes()
        self.assertEqual(subprocess.run(command + ['--out', str(manifest)], capture_output=True).returncode, 2)
        self.assertEqual(manifest.read_bytes(), before)
        self.assertEqual(subprocess.run(command + ['--out', str(obj)], capture_output=True).returncode, 2)
        self.assertEqual(obj.read_bytes(), data)

    def test_authoritative_recipe_reconciliation(self):
        recipes = [dict(source='a.cpp', compiler='sp1', flags=['/O2']),
                   dict(source='a.cpp', compiler='sp1', flags=['/Od'])]
        path = self.root / 'recipes.json'
        path.write_text(json.dumps(dict(units=recipes)))
        def entry(index):
            recipe = recipes[index]
            canonical = json.dumps(recipe, sort_keys=True, separators=(',', ':'), ensure_ascii=True).encode('ascii')
            return dict(recipe_index=index, recipe_id='%04d-%s' % (index,
                coff_inventory.hashlib.sha256(canonical).hexdigest()[:16]),
                recipe=dict(recipe), source=recipe['source'], compiler=recipe['compiler'])
        manifest = dict(recipe_manifest_sha256=coff_inventory.hashlib.sha256(path.read_bytes()).hexdigest(),
                        units=[entry(0), entry(1)])
        self.assertTrue(coff_inventory.reconcile_recipes(manifest, path)['verified'])
        manifest['units'] = [entry(0)]
        self.assertEqual(coff_inventory.reconcile_recipes(manifest, path)['missing_recipe_indices'], [1])
        manifest['units'] = [entry(0), entry(0)]
        self.assertIn('duplicate recipe_index: 0', coff_inventory.reconcile_recipes(manifest, path)['errors'])
        manifest['units'] = [entry(0), entry(1)]
        manifest['units'][1]['recipe']['flags'] = ['/O2']
        # Even a plausible regenerated identity cannot redefine the authoritative variant.
        manifest['units'][1]['recipe_id'] = entry(0)['recipe_id'].replace('0000-', '0001-')
        self.assertFalse(coff_inventory.reconcile_recipes(manifest, path)['verified'])
        manifest['units'] = [entry(0), entry(1)]
        manifest['recipe_manifest_sha256'] = '0' * 64
        self.assertFalse(coff_inventory.reconcile_recipes(manifest, path)['verified'])

    def test_duplicate_object_path_rejected_but_identical_separate_objects_valid(self):
        data = fixture([('_func', 0, 1, 2, [])])
        (self.root / 'one.obj').write_bytes(data)
        (self.root / 'two.obj').write_bytes(data)
        digest = coff_inventory.hashlib.sha256(data).hexdigest()
        manifest = dict(schema_version=1, kind='fnv-retained-objects', units=[
            dict(recipe_id='one', source='fixture.cpp', status='compiled', object='one.obj', object_sha256=digest),
            dict(recipe_id='two', source='fixture.cpp', status='compiled', object='./one.obj', object_sha256=digest)])
        path = self.root / 'objects.json'
        path.write_text(json.dumps(manifest))
        report = coff_inventory.inventory(path)
        self.assertFalse(report['supplied_manifest_complete'])
        self.assertIn('reuse', report['errors'][0]['error'])
        manifest['units'][1]['object'] = 'two.obj'
        path.write_text(json.dumps(manifest))
        self.assertTrue(coff_inventory.inventory(path)['supplied_manifest_complete'])

    def test_compact_summary_agrees_with_full_categories(self):
        obj = self.inspect(fixture([('_func', 0, 1, 2, []), ('_undefined', 0, 0, 2, [])]))
        other = dict(obj, recipe_id='two')
        full = coff_inventory.summarize([obj, other])
        compact = coff_inventory.CompactSummary()
        compact.add(obj)
        compact.add(other)
        report = compact.result()
        self.assertEqual(report['duplicate_name_count'], len(full['duplicates']))
        self.assertEqual(report['unresolved_name_count'], len(full['unresolved']))
        self.assertEqual(report['duplicate_categories'], {'multiple_strong_definitions': 1})

    def test_failed_gzip_detail_does_not_survive(self):
        path = self.root / 'objects.json'
        path.write_text(json.dumps(dict(schema_version=1, kind='fnv-retained-objects',
            units=[dict(recipe_id='one', status='compiled', object='absent.obj', object_sha256='bad')])))
        output = self.root / 'failed.json'
        detail = self.root / 'failed.ndjson.gz'
        command = [sys.executable, str(MODULE), '--manifest', str(path),
                   '--out', str(output), '--detail-gzip', str(detail)]
        self.assertEqual(subprocess.run(command, capture_output=True).returncode, 1)
        self.assertTrue(output.exists())
        self.assertFalse(detail.exists())


if __name__ == '__main__':
    unittest.main()
