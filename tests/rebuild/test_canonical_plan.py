"""Address-plan safety tests with original synthetic objects and explicit recipes."""
import hashlib
import importlib.util
import json
from pathlib import Path
import struct
import subprocess
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tools/rebuild'))
import canonical_plan
import coff_inventory

spec = importlib.util.spec_from_file_location('inventory_fixtures', Path(__file__).with_name('test_coff_inventory.py'))
fixtures = importlib.util.module_from_spec(spec)
spec.loader.exec_module(fixtures)


class CanonicalPlanTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        self.recipes = self.root / 'recipes.json'
        self.manifest = self.root / 'objects.json'
        self.inventory = self.root / 'inventory.json'

    def prepare(self, specs):
        recipes = [dict(source=f'unit{i}.cpp', compiler='sp1', flags=['/O2'],
                        functions=s.get('functions', []), symbols=s.get('bindings', {}))
                   for i, s in enumerate(specs)]
        self.recipes.write_text(json.dumps(dict(units=recipes)))
        units = []
        for index, (recipe, specification) in enumerate(zip(recipes, specs)):
            source = self.root / recipe['source']
            source.write_text('// original synthetic fixture source\n')
            data = bytearray(fixtures.fixture(specification['symbols'],
                                comdat=specification.get('comdat', 0),
                                flags=specification.get('flags', 0x60000020)))
            symptr = struct.unpack_from('<I', data, 8)[0]
            for symbol_index in specification.get('function_indices', []):
                struct.pack_into('<H', data, symptr + symbol_index * 18 + 14, 0x20)
            obj = self.root / f'{index}.obj'
            obj.write_bytes(data)
            canonical = json.dumps(recipe, sort_keys=True, separators=(',', ':'), ensure_ascii=True).encode('ascii')
            units.append(dict(recipe_index=index, recipe_id='%04d-%s' % (index,
                hashlib.sha256(canonical).hexdigest()[:16]), recipe=recipe,
                source=recipe['source'], source_sha256=canonical_plan.sha256(source),
                compiler='sp1', status='compiled', object=obj.name,
                object_sha256=hashlib.sha256(data).hexdigest()))
        self.manifest.write_text(json.dumps(dict(schema_version=1, kind='fnv-retained-objects', source_root=str(self.root),
            recipe_manifest_sha256=canonical_plan.sha256(self.recipes), units=units)))
        self.inventory.write_text(json.dumps(coff_inventory.inventory(self.manifest, self.recipes, compact=True)))

    def run_plan(self):
        return canonical_plan.plan(self.recipes, self.manifest, self.inventory)

    def receipt(self, *, local_notes=None):
        """Exact producer/consumer contract, from synthetic selected native entries."""
        manifest = json.loads(self.manifest.read_text())
        units = []
        local_notes = local_notes or []
        for unit in manifest['units']:
            obj = coff_inventory.inspect_object(self.root / unit['object'], unit)
            records = []
            for function in unit['recipe']['functions']:
                symbol = next(s for s in obj['symbols'] if s['name'] == function['symbol'])
                records.append(dict(symbol=function['symbol'], address=function['address'],
                    size=function['size'], section=symbol['section'], value=symbol['value'], verdict='match'))
            count = len(records)
            size = sum(r['size'] for r in records)
            units.append(dict(recipe_id=unit['recipe_id'], recipe_index=unit['recipe_index'],
                recipe_unit_sha256=canonical_plan.canonical_json_hash(unit['recipe']),
                object_sha256=unit['object_sha256'], source_sha256_recorded=unit['source_sha256'],
                source_sha256_current=unit['source_sha256'], status='ok', functions=count,
                matched_functions=count, bytes=size, matched_bytes=size, mismatches=[],
                verified_functions=records, eh_errors=local_notes if unit['recipe_index'] == 0 else []))
        count = sum(u['functions'] for u in units)
        size = sum(u['bytes'] for u in units)
        index = ROOT / 'build/function_index.json'
        return dict(schema_version=1, kind='fnv-retained-object-verification',
            status='pass_with_diagnostics' if local_notes else 'pass',
            retained_verification_pass=True, function_byte_verification_pass=True,
            global_listed_eh_coverage_pass=True, original_oracle_parity_pass=True,
            strict_local_eh_diagnostics_pass=not local_notes, runtime_closure_verified=False,
            evidence_stable=True, image_gate=dict(passed=True),
            scope=dict(authoritative_recipe_count=len(units), manifest_recipe_count=len(units),
                       selected_recipe_indices=list(range(len(units))), full_authoritative=True),
            inputs=dict(retained_manifest_sha256=canonical_plan.sha256(self.manifest),
                recipe_sha256=canonical_plan.sha256(self.recipes), image_sha256='1' * 64,
                function_index_present=index.is_file(), function_index_sha256=canonical_plan.sha256(index) if index.is_file() else None,
                image_check_sha256=canonical_plan.sha256(ROOT / 'build/image_check.json'),
                tools_sha256={p:canonical_plan.sha256(ROOT / p) for p in canonical_plan.VERIFICATION_TOOLS}),
            summary=dict(units=len(units), functions=count, matched_functions=count, bytes=size,
                matched_bytes=size, eh_tails=0, matched_eh_tails=0, eh_tail_mismatches=[],
                eh_inferred_conflicts=0, eh_comparison_errors=len(local_notes)), units=units)

    def run_verified(self, receipt):
        path = self.root / 'verification.json'
        path.write_text(json.dumps(receipt))
        return canonical_plan.plan(self.recipes, self.manifest, self.inventory,
            verification_path=path, verification_sha256=canonical_plan.sha256(path))

    def prepare_verified_body(self):
        self.prepare([dict(symbols=[('_selected', 0, 1, 2, []), ('_extra', 1, 1, 2, [])],
            functions=[dict(symbol='_selected', address='0x401000', size=4)],
            bindings={'_extra': '0x401000'})])

    def test_different_names_same_address_are_only_unselected_candidates(self):
        self.prepare([dict(symbols=[('_implementation', 0, 1, 2, [])], bindings={'_implementation': '0x401000'}),
                      dict(symbols=[('_view', 0, 0, 2, [])], function_indices=[0], bindings={'_view': '0x00401000'})])
        report = self.run_plan()
        self.assertEqual(report['raw_unresolved_name_count'], 1)
        self.assertEqual(report['raw_unresolved_categories'], {'all_own_bound_uses_have_address_provider_candidates': 1})
        use = report['use_candidate_examples'][0]
        self.assertIsNone(use['selected_provider'])
        self.assertFalse(use['abi_verified'])
        self.assertEqual(use['provider_examples'][0]['symbol'], '_implementation')
        self.assertEqual(use['provider_examples'][0]['reference_selection_basis'], 'METADATA_BOUND_UNVERIFIED_BODY')
        self.assertFalse(use['provider_examples'][0]['eligible_for_selection'])

    def test_never_borrows_another_recipe_binding(self):
        self.prepare([dict(symbols=[('_implementation', 0, 1, 2, [])],
                           bindings={'_implementation': '0x401000', '_view': '0x401000'}),
                      dict(symbols=[('_view', 0, 0, 2, [])], function_indices=[0])])
        report = self.run_plan()
        self.assertEqual(report['candidate_provider_use_occurrences'], 0)
        self.assertEqual(report['raw_unresolved_categories'], {'library_or_own_binding_absent': 1})

    def test_iat_is_pointer_and_tls_pseudobinding_is_not_code(self):
        self.prepare([dict(symbols=[('_implementation', 0, 1, 2, [])], bindings={'_implementation': '0x401000'}),
                      dict(symbols=[('__imp__Api@0', 0, 0, 2, []), ('__tls_array', 0, 0, 2, [])],
                           bindings={'__imp__Api@0': '0x401000', '__tls_array': '0x2c'})])
        report = self.run_plan()
        self.assertEqual(report['candidate_provider_use_occurrences'], 0)
        self.assertEqual(report['raw_unresolved_categories']['iat_import_provider_required'], 1)
        self.assertEqual(report['raw_unresolved_categories']['tls_mechanism_not_image_address'], 1)

    def test_data_type_code_address_is_explicit_abi_unknown(self):
        self.prepare([dict(symbols=[('_code', 0, 1, 2, [])], bindings={'_code': '0x401000'}),
                      dict(symbols=[('_data', 0, 0, 2, [])], bindings={'_data': '0x401000'})])
        report = self.run_plan()
        self.assertEqual(report['use_occurrences']['code_address_view_abi_unknown'], 1)
        self.assertFalse(report['use_candidate_examples'][0]['abi_verified'])

    def test_code_backed_import_name_is_not_iat_provider(self):
        self.prepare([dict(symbols=[('__imp__wrong', 0, 1, 2, [])], bindings={'__imp__wrong': '0x401000'}),
                      dict(symbols=[('__imp__view', 0, 0, 2, [])], bindings={'__imp__view': '0x401000'})])
        report = self.run_plan()
        self.assertEqual(report['candidate_provider_use_occurrences'], 0)
        self.assertEqual(report['definition_kinds']['invalid_code_backed_iat_definition'], 1)

    def test_variants_and_same_name_different_address_are_preserved(self):
        self.prepare([dict(symbols=[('_impl', 0, 1, 2, [])], bindings={'_impl': '0x401000'}, comdat=1),
                      dict(symbols=[('_impl', 0, 1, 2, [])], bindings={'_impl': '0x401000'}, comdat=2),
                      dict(symbols=[('_impl', 0, 1, 2, [])], bindings={'_impl': '0x402000'}, comdat=1)])
        report = self.run_plan()
        group = report['candidate_group_examples'][0]
        self.assertEqual(group['distinct_recipe_count'], 2)
        self.assertTrue(all(p['selection_state'] == 'UNSELECTED' for p in group['candidates']))
        self.assertTrue(all('closure-review-required' in p['closure'] for p in group['candidates']))
        self.assertEqual(report['same_definition_name_multiple_addresses'][0]['original_addresses'],
                         ['0x00401000', '0x00402000'])

    def test_stale_object_and_manifest_are_rejected(self):
        self.prepare([dict(symbols=[('_impl', 0, 1, 2, [])], bindings={'_impl': '0x401000'})])
        obj = self.root / '0.obj'
        obj.write_bytes(obj.read_bytes() + b'changed')
        with self.assertRaisesRegex(ValueError, 'object fingerprint'):
            self.run_plan()
        self.prepare([dict(symbols=[('_impl', 0, 1, 2, [])], bindings={'_impl': '0x401000'})])
        self.manifest.write_text(self.manifest.read_text() + '\n')
        with self.assertRaisesRegex(ValueError, 'retained-manifest fingerprint'):
            self.run_plan()

    def test_reordered_or_oversized_provenance_fails_bounded_read(self):
        self.prepare([dict(symbols=[('_impl', 0, 1, 2, [])])])
        self.inventory.write_text(json.dumps(dict(summary=['x' * 100000], kind='fnv-coff-link-inventory')))
        with self.assertRaisesRegex(ValueError, 'unsupported inventory provenance'):
            self.run_plan()

    def test_local_function_is_visible_candidate_but_requires_explicit_remap(self):
        self.prepare([dict(symbols=[('_static', 0, 1, 3, [])],
            functions=[dict(symbol='_static', address='0x401000')]),
            dict(symbols=[('_view', 0, 0, 2, [])], function_indices=[0], bindings={'_view': '0x401000'})])
        report = self.run_plan()
        self.assertEqual(report['function_address_provider_counts']['one'], 1)
        self.assertEqual(report['function_address_provider_counts']['none'], 0)
        self.assertEqual(report['candidate_provider_use_occurrences'], 1)
        self.assertEqual(report['use_candidate_examples'][0]['provider_examples'][0]['visibility'],
                         'object_local_requires_explicit_remap')

    def test_existing_name_with_wrong_address_is_not_silently_consistent(self):
        self.prepare([dict(symbols=[('_name', 0, 1, 2, [])], bindings={'_name': '0x401000'}),
                      dict(symbols=[('_name', 0, 0, 2, [])], function_indices=[0], bindings={'_name': '0x402000'})])
        report = self.run_plan()
        self.assertEqual(report['already_name_defined_binding_consistency']['own_address_not_in_named_provider_addresses'], 1)

    def test_selected_entry_alias_and_metadata_only_bodies_remain_distinct(self):
        self.prepare([dict(symbols=[('_checked_entry', 0, 1, 2, []), ('_same_entry', 0, 1, 2, []),
                                   ('_other_body', 1, 1, 2, [])],
            functions=[dict(symbol='_checked_entry', address='0x401000')],
            bindings={'_same_entry': '0x401000', '_other_body': '0x401000'})])
        providers = self.run_plan()['candidate_group_examples'][0]['candidates']
        bases = {p['symbol']: p['reference_selection_basis'] for p in providers}
        self.assertEqual(bases['_checked_entry'], 'SELECTED_RECIPE_FUNCTION')
        self.assertEqual(bases['_same_entry'], 'SAME_OBJECT_SELECTED_FUNCTION_ALIAS')
        self.assertEqual(bases['_other_body'], 'METADATA_BOUND_UNVERIFIED_BODY')
        self.assertTrue(all(not p['eligible_for_selection'] for p in providers))

    def test_missing_selected_symbol_fails_instead_of_using_same_address_name(self):
        self.prepare([dict(symbols=[('_wrong', 0, 1, 2, [])],
            functions=[dict(symbol='_missing', address='0x401000')], bindings={'_wrong': '0x401000'})])
        with self.assertRaisesRegex(ValueError, 'selected recipe function is absent'):
            self.run_plan()

    def test_cli_preserves_existing_evidence_and_removes_new_failed_partial(self):
        self.prepare([dict(symbols=[('_impl', 0, 1, 2, [])])])
        script = ROOT / 'tools/rebuild/canonical_plan.py'
        output = self.root / 'plan.json'
        candidate = self.root / 'candidates.gz'
        command = [sys.executable, str(script), '--recipes', str(self.recipes),
            '--manifest', str(self.manifest), '--inventory', str(self.inventory),
            '--out', str(output), '--candidate-gzip', str(candidate)]
        output.write_bytes(b'keep')
        self.assertEqual(subprocess.run(command, capture_output=True).returncode, 2)
        self.assertEqual(output.read_bytes(), b'keep')
        output.unlink()
        candidate.write_bytes(b'keep gzip')
        self.assertEqual(subprocess.run(command, capture_output=True).returncode, 2)
        self.assertEqual(candidate.read_bytes(), b'keep gzip')
        candidate.unlink()
        (self.root / '0.obj').write_bytes(b'stale')
        self.assertEqual(subprocess.run(command, capture_output=True).returncode, 2)
        self.assertFalse(output.exists())
        self.assertFalse(candidate.exists())

    def test_verified_function_scope_preserves_local_eh_diagnostics_and_unverified_extra(self):
        self.prepare_verified_body()
        report = self.run_verified(self.receipt(local_notes=['synthetic local diagnostic']))
        self.assertEqual(report['hash_bound_byte_checked_manifest_function_address_count'], 1)
        self.assertEqual(report['hash_bound_byte_checked_provider_basis_counts'], {'SELECTED_RECIPE_FUNCTION': 1})
        notes = report['retained_verification']
        self.assertFalse(notes['strict_local_eh_diagnostics_pass'])
        self.assertEqual(notes['local_eh_diagnostic_count'], 1)
        self.assertTrue(notes['global_listed_eh_coverage_pass'])
        self.assertFalse(notes['runtime_closure_verified'])
        providers = {p['symbol']:p for p in report['candidate_group_examples'][0]['candidates']}
        self.assertTrue(providers['_selected']['hash_bound_function_byte_verified'])
        self.assertFalse(providers['_extra']['hash_bound_function_byte_verified'])
        self.assertTrue(all(not p['eligible_for_selection'] and not p['abi_verified'] for p in providers.values()))

    def test_receipt_other_function_wrong_object_and_wrong_native_span_rejected(self):
        self.prepare_verified_body()
        for field, value, message in [('object_sha256', '0' * 64, 'recipe/object proof'),
                ('verified_functions', [dict(symbol='_extra', address='0x401000', size=4,
                    section=1, value=1, verdict='match')], 'exact selected symbol/address/size')]:
            receipt = self.receipt()
            receipt['units'][0][field] = value
            with self.subTest(field=field), self.assertRaisesRegex(ValueError, message):
                self.run_verified(receipt)
        receipt = self.receipt()
        receipt['units'][0]['verified_functions'][0]['value'] = 1
        with self.assertRaisesRegex(ValueError, 'native selected symbol/section/offset'):
            self.run_verified(receipt)

    def test_partial_or_count_only_receipts_never_promote_bodies(self):
        self.prepare_verified_body()
        receipt = self.receipt()
        receipt['scope']['selected_recipe_indices'] = []
        with self.assertRaisesRegex(ValueError, 'exact full authoritative'):
            self.run_verified(receipt)
        receipt = self.receipt()
        del receipt['units'][0]['verified_functions']
        with self.assertRaisesRegex(ValueError, 'specific selected-function'):
            self.run_verified(receipt)
        receipt = self.receipt()
        receipt['units'][0]['verified_functions'] = []
        with self.assertRaisesRegex(ValueError, 'exact selected symbol/address/size'):
            self.run_verified(receipt)

    def test_receipt_digest_and_current_core_hashes_are_required(self):
        self.prepare_verified_body()
        path = self.root / 'verification.json'
        receipt = self.receipt()
        path.write_text(json.dumps(receipt))
        with self.assertRaisesRegex(ValueError, 'receipt fingerprint'):
            canonical_plan.plan(self.recipes, self.manifest, self.inventory,
                verification_path=path, verification_sha256='0' * 64)
        receipt['inputs']['tools_sha256']['tools/compare.py'] = '0' * 64
        with self.assertRaisesRegex(ValueError, 'core/verifier tool'):
            self.run_verified(receipt)
        receipt = self.receipt()
        receipt['inputs']['retained_manifest_sha256'] = '0' * 64
        with self.assertRaisesRegex(ValueError, 'recipe/retained-manifest fingerprint'):
            self.run_verified(receipt)

    def test_exact_whole_section_alias_can_inherit_identity_but_never_runtime_eligibility(self):
        self.prepare([dict(symbols=[('_selected', 0, 1, 2, []), ('_alias', 0, 1, 2, [])],
            functions=[dict(symbol='_selected', address='0x401000', size=4)], bindings={'_alias': '0x401000'})])
        report = self.run_verified(self.receipt())
        providers = {p['symbol']:p for p in report['candidate_group_examples'][0]['candidates']}
        self.assertTrue(providers['_alias']['hash_bound_function_byte_verified'])
        self.assertTrue(providers['_alias']['verified_function_span']['identity_only_alias'])
        self.assertFalse(providers['_alias']['eligible_for_selection'])

    def test_alias_with_unverified_extra_section_bytes_does_not_inherit_span(self):
        self.prepare([dict(symbols=[('_selected', 0, 1, 2, []), ('_alias', 0, 1, 2, [])],
            functions=[dict(symbol='_selected', address='0x401000', size=2)], bindings={'_alias': '0x401000'})])
        report = self.run_verified(self.receipt())
        providers = {p['symbol']:p for p in report['candidate_group_examples'][0]['candidates']}
        self.assertTrue(providers['_selected']['hash_bound_function_byte_verified'])
        self.assertFalse(providers['_alias']['hash_bound_function_byte_verified'])


if __name__ == '__main__':
    unittest.main()
