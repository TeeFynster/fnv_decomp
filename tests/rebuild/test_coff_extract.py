"""Synthetic zero-relocation COMDAT fixtures and hash-bound scope failures."""
import copy
import json
from pathlib import Path
import struct
import sys
import tempfile
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[2] / 'tools/rebuild'))
import coff_extract as extractor
from coff_inventory import Coff
from coff_rewrite import strict_object
from build_objects import recipe_id
from test_game_leaf_probe import original_object
import game_leaf_probe


class ExtractTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        self.obj = self.root / 'input.obj'
        self.obj.write_bytes(original_object())
        self.proof = dict(symbol=game_leaf_probe.OLD, address='0x00401000', size=4,
                          section=2, value=0, verdict='match')
        self.output = self.root / 'output.obj'

    def layout(self, coff=None):
        return extractor.select_layout(coff or Coff(self.obj), self.proof)

    def test_preserves_code_flags_policy_and_default_directives(self):
        data, ledger = self.layout()
        self.output.write_bytes(data)
        after, _, _, _ = strict_object(self.output)
        before = Coff(self.obj)
        self.assertEqual(after.sections[2]['payload_sha256'], before.sections[2]['payload_sha256'])
        self.assertEqual(after.sections[2]['flags'], before.sections[2]['flags'])
        self.assertEqual(after.sections[2]['selection'], 'no_duplicates')
        self.assertEqual(after.directives, before.directives)
        self.assertEqual(after.symbols[2]['name'], self.proof['symbol'])
        self.assertEqual(ledger['runtime_relocations'], 0)

    def test_runtime_relocation_and_shared_section_rejected(self):
        coff = Coff(self.obj)
        coff.sections[2]['relocs'] = [(0, 2, 6)]
        with self.assertRaisesRegex(ValueError, 'runtime-relocated'):
            self.layout(coff)
        coff = Coff(self.obj)
        coff.symbols[3] = dict(coff.symbols[2], index=3, name='_second')
        with self.assertRaisesRegex(ValueError, 'shared section'):
            self.layout(coff)

    def test_non_debug_associative_eh_child_rejected(self):
        coff = Coff(self.obj)
        coff.sections[3] = dict(coff.sections[2], index=3, name='.text$x', selection='associative', association=2)
        with self.assertRaisesRegex(ValueError, 'non-debug associative'):
            self.layout(coff)

    def test_debug_child_drop_is_explicit(self):
        coff = Coff(self.obj)
        coff.sections[3] = dict(coff.sections[2], index=3, name='.debug$F', flags=0x42100,
            selection='associative', association=2, relocs=[(0, 2, 7)])
        _, ledger = self.layout(coff)
        self.assertEqual(ledger['debug_associative_children_dropped'], [3])
        self.assertIn('debug-only', ledger['dropped_sections'][0]['reason'])

    def test_unknown_directives_and_tls_sections_rejected(self):
        coff = Coff(self.obj)
        coff.directives.append('/INCLUDE:_unreviewed')
        with self.assertRaisesRegex(ValueError, 'linker directives'):
            self.layout(coff)
        coff = Coff(self.obj)
        coff.sections[3] = dict(coff.sections[2], index=3, name='.tls', flags=0xC0000040, comdat=False)
        with self.assertRaisesRegex(ValueError, 'TLS'):
            self.layout(coff)

    def make_basis(self):
        source = self.root / 'fixture.cpp'
        source.write_text('int original_fixture;\n')
        recipe = dict(source='fixture.cpp', compiler='sp1', flags=[], functions=[
            {k: self.proof[k] for k in ('symbol', 'address', 'size')}], symbols={})
        recipes = self.root / 'recipes.json'
        recipes.write_text(json.dumps(dict(units=[recipe])))
        unit = dict(recipe_index=0, recipe_id=recipe_id(0, recipe), recipe=recipe, source='fixture.cpp',
            compiler='sp1', object='input.obj', object_sha256=extractor.sha(self.obj), source_sha256=extractor.sha(source), status='compiled')
        manifest = self.root / 'manifest.json'
        manifest.write_text(json.dumps(dict(schema_version=1, kind='fnv-retained-objects', source_root=str(self.root),
            recipe_manifest_sha256=extractor.sha(recipes), units=[unit])))
        checked = dict(unit, verified_functions=[self.proof], status='ok')
        verification = self.root / 'verification.json'
        verification.write_text(json.dumps(dict(kind='fnv-retained-object-verification', schema_version=1,
            retained_verification_pass=True, function_byte_verification_pass=True, original_oracle_parity_pass=True,
            global_listed_eh_coverage_pass=True, evidence_stable=True, scope=dict(full_authoritative=True),
            inputs=dict(retained_manifest_sha256=extractor.sha(manifest), recipe_sha256=extractor.sha(recipes)), units=[checked])))
        return manifest, recipes, verification, unit

    def test_hash_bound_end_to_end_and_no_overwrite(self):
        manifest, recipes, verification, unit = self.make_basis()
        receipt = self.root / 'receipt.json'
        args = (self.obj, self.output, receipt, manifest, recipes, verification,
                extractor.sha(verification), unit['recipe_id'], self.proof['symbol'])
        result = extractor.extract(*args)
        self.assertEqual(result['status'], 'pass')
        self.assertEqual(result['output_sha256'], extractor.sha(self.output))
        with self.assertRaisesRegex(ValueError, 'new distinct'):
            extractor.extract(*args)

    def test_bad_receipt_hash_and_input_output_collision_rejected(self):
        manifest, recipes, verification, unit = self.make_basis()
        args = (self.obj, self.output, self.root / 'receipt.json', manifest, recipes,
                verification, 'wrong', unit['recipe_id'], self.proof['symbol'])
        with self.assertRaisesRegex(ValueError, 'hash-bound'):
            extractor.extract(*args)
        with self.assertRaisesRegex(ValueError, 'new distinct'):
            extractor.extract(self.obj, self.obj, *args[2:])

    def test_malformed_unknown_aux_and_invalid_symbol_reference_rejected(self):
        good = self.obj.read_bytes()
        # Both are real malformed binary fixtures checked by the input parser.
        for data in (good[:-1], b'\0\0\xff\xff' + good[4:]):
            self.obj.write_bytes(data)
            with self.assertRaises(ValueError):
                strict_object(self.obj)
        self.obj.write_bytes(good)
        coff = Coff(self.obj)
        coff.symbols[0]['section_aux']['association'] = 1
        with self.assertRaisesRegex(ValueError, 'auxiliary'):
            self.layout(coff)
        # A relocation target absent from the symbol table is rejected upstream.
        changed = bytearray(good)
        struct.pack_into('<I', changed, 60 + 24, len(good))
        struct.pack_into('<H', changed, 60 + 32, 1)
        changed.extend(struct.pack('<IIH', 0, 999, 6))
        self.obj.write_bytes(changed)
        with self.assertRaises(ValueError):
            strict_object(self.obj)


if __name__ == '__main__':
    unittest.main()
