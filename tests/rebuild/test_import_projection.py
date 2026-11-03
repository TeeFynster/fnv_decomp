"""Offline identity preparation; no native libraries, executable or DLL access."""
import copy
import json
from pathlib import Path
import sys
import tempfile
import unittest
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[2] / 'tools/rebuild'))
import import_projection as p

# Metadata-only observation from the preserved failed native GDI32 inspection.
# No member bytes, executable data or game source are included.
VC9_QUOTED_EXPORT_OBSERVATION = dict(dll='GDI32.dll', export_name='"GetStockObject"',
                                    pointer_symbol='__imp__"GetStockObject"')


def fixture():
    va = '0x00402000'
    root = dict(recipe_id='fixture', function_va='0x00401000', object_sha256='a'*64,
                source_sha256='b'*64)
    identity = dict(kind='name', name='GetActiveWindow')
    cell = dict(import_id=0, original_IAT_va=va, dll='USER32.dll', export=identity,
                representation='IAT_POINTER_CELL_NOT_FUNCTION_BODY',
                required_provider_contract=dict(dll='USER32.dll', export=identity,
                                                runtime_provider_selected=False))
    plan = dict(kind='fnv-static-import-plan', schema_version=1,
                runtime_closure_verified=False, game_fixups_approved=0,
                summary=dict(imports=1), imports=[cell])
    row = dict(recipe_id='fixture', object_sha256='a'*64, source_sha256='b'*64,
               original_IAT_va=va, recipe_binding_va=va, status='VERIFIED_FUNCTION_EXACT_IAT_USE',
               relocation_kind=6, addend=0, section=1, relocation_offset=4,
               symbol_index=7, symbol='__imp__GetForegroundWindow@0',
               verified_function_fields=[dict(function_va='0x00401000', function_section=1,
                   function_value=0, field_offset=4, original_field_va='0x00401004',
                   observed_operand=int(va, 16))])
    return plan, [(1, row)], root


class ProjectionTests(unittest.TestCase):
    def test_native_quoted_export_regression_and_malformed_names_rejected(self):
        plan, rows, root = fixture()
        cell = plan['imports'][0]
        cell['dll'] = cell['required_provider_contract']['dll'] = 'GDI32.dll'
        identity = dict(kind='name', name='GetStockObject')
        cell['export'] = cell['required_provider_contract']['export'] = identity
        report = p.prepare(plan, rows, root)
        text = next(iter(p.definitions(report).values())).decode()
        self.assertIn('    GetStockObject\n', text)
        self.assertNotIn(VC9_QUOTED_EXPORT_OBSERVATION['export_name'], text)
        for malformed in [VC9_QUOTED_EXPORT_OBSERVATION['export_name'], 'Get StockObject',
                          'GetStockObject\nOther', 'GetStockObject=Other', 'GetStockObject;Other']:
            with self.subTest(malformed=malformed):
                identity['name'] = malformed
                with self.assertRaisesRegex(ValueError, 'represented safely'):
                    p.prepare(plan, rows, root)

    def test_actual_identity_overrides_misleading_source_name(self):
        report = p.prepare(*fixture())
        defs = p.definitions(report)
        text = next(iter(defs.values())).decode()
        self.assertIn('    GetActiveWindow\n', text)
        self.assertNotIn('"GetActiveWindow"', text)
        self.assertEqual(report['definition_syntax'], 'vc9-unquoted-safe-export-tokens-v2')
        self.assertNotIn('GetForegroundWindow', text)
        self.assertEqual(report['selected_cells'][0]['canonical_IAT_symbol'],
                         p.unresolved('0x00402000', 'iat-cell'))
        self.assertEqual(report['canonical_link_aliases'], [])
        self.assertFalse(report['source_ABI_verified'])

    def test_unusual_export_identity_retained_but_def_generation_gated(self):
        for name in ['_BinkClose@4', '?Mangled@@YAXXZ', '@Decorated', '-entry', 'entry.name']:
            plan, rows, root = fixture()
            identity = dict(kind='name', name=name)
            plan['imports'][0]['export'] = identity
            plan['imports'][0]['required_provider_contract']['export'] = identity
            report = p.prepare(plan, rows, root)
            self.assertEqual(report['selected_cells'][0]['export']['name'], name)
            with self.assertRaisesRegex(ValueError, 'separate DEF syntax conformance'):
                p.definitions(report)

    def test_ordinal_stays_dll_plus_ordinal(self):
        plan, rows, root = fixture()
        identity = dict(kind='ordinal', ordinal=5)
        plan['imports'][0]['export'] = identity
        plan['imports'][0]['required_provider_contract']['export'] = identity
        report = p.prepare(plan, rows, root)
        text = next(iter(p.definitions(report).values())).decode()
        self.assertIn('fnv_ordinal_00005 @5 NONAME', text)
        self.assertEqual(report['selected_cells'][0]['export'], identity)

    def test_two_cells_same_export_stay_distinct(self):
        plan, rows, root = fixture()
        extra = copy.deepcopy(plan['imports'][0])
        extra.update(import_id=1, original_IAT_va='0x00402004')
        plan['imports'].append(extra)
        plan['summary']['imports'] = 2
        other = copy.deepcopy(rows[0][1])
        other.update(original_IAT_va='0x00402004', recipe_binding_va='0x00402004',
                     symbol_index=8, relocation_offset=8)
        other['verified_function_fields'][0].update(field_offset=8, original_field_va='0x00401008',
                                                    observed_operand=0x00402004)
        rows.append((2, other))
        report = p.prepare(plan, rows, root)
        self.assertEqual(len(report['selected_cells']), 2)
        self.assertNotEqual(*[c['canonical_IAT_symbol'] for c in report['selected_cells']])
        self.assertEqual(next(iter(p.definitions(report).values())).count(b'GetActiveWindow'), 1)

    def test_metadata_may_cover_unused_cells(self):
        plan, rows, root = fixture()
        extra = copy.deepcopy(plan['imports'][0])
        extra.update(import_id=1, original_IAT_va='0x00402004')
        plan['imports'].append(extra)
        plan['summary']['imports'] = 2
        report = p.prepare(plan, rows, root)
        self.assertEqual(report['catalog_cell_count'], 2)
        self.assertEqual(report['summary']['cells'], 1)

    def test_wrong_pointer_observation_rejected(self):
        plan, rows, root = fixture()
        rows[0][1]['verified_function_fields'][0]['observed_operand'] += 4
        with self.assertRaisesRegex(ValueError, 'unproved exact'):
            p.prepare(plan, rows, root)

    def test_direct_code_and_nonzero_addend_rejected(self):
        for key, value in [('relocation_kind', 20), ('addend', 4),
                           ('status', 'UNVERIFIED_BODY_RECIPE_IAT_BINDING')]:
            with self.subTest(key=key):
                plan, rows, root = fixture()
                rows[0][1][key] = value
                with self.assertRaises(ValueError):
                    p.prepare(plan, rows, root)

    def test_duplicate_field_rejected(self):
        plan, rows, root = fixture()
        rows.append((2, copy.deepcopy(rows[0][1])))
        with self.assertRaisesRegex(ValueError, 'duplicate physical field'):
            p.prepare(plan, rows, root)

    def test_stale_object_or_coordinates_rejected(self):
        for key, value in [('object_sha256', 'c'*64), ('relocation_offset', 9)]:
            plan, rows, root = fixture()
            rows[0][1][key] = value
            with self.assertRaises(ValueError):
                p.prepare(plan, rows, root)

    def test_duplicate_cell_and_conflicting_contract_rejected(self):
        plan, rows, root = fixture()
        plan['imports'].append(copy.deepcopy(plan['imports'][0]))
        with self.assertRaisesRegex(ValueError, 'duplicate IAT'):
            p.prepare(plan, rows, root)
        plan, rows, root = fixture()
        plan['imports'][0]['required_provider_contract']['dll'] = 'KERNEL32.dll'
        with self.assertRaisesRegex(ValueError, 'contract conflict'):
            p.prepare(plan, rows, root)

    def test_def_injection_and_paths_rejected(self):
        for name in ['bad.dll\nEXPORTS', '../bad.dll', 'bad".dll', 'C:bad.dll']:
            plan, rows, root = fixture()
            plan['imports'][0]['dll'] = name
            with self.assertRaises(ValueError):
                p.prepare(plan, rows, root)

    def test_absent_selected_fields_rejected(self):
        plan, rows, root = fixture()
        root['function_va'] = '0x00401100'
        with self.assertRaisesRegex(ValueError, 'no selected'):
            p.prepare(plan, rows, root)

    def test_namespace_requires_exact_index_label_and_input_identity(self):
        plan, rows, root = fixture()
        report = p.prepare(plan, rows, root)
        certificate = dict(kind='compatible-undefined-reference-certificate-candidate', schema_version=1,
                           root=dict(recipe_id=root['recipe_id'], original_address=root['function_va']),
                           object_sha256=root['object_sha256'],
                           input_sha256=dict(imports=p.PLAN_PIN, source=root['source_sha256']),
                           primary_bijection=[[7, 2]],
                           namespace_plan=[dict(physical_index=7, serialized_index=2,
                                                name=report['fields'][0]['canonical_IAT_symbol'])])
        with patch.object(p, 'MAIN', root):
            p.join_namespace(report, certificate)
            self.assertEqual(report['fields'][0]['planned_serialized_symbol_index'], 2)
            for change in ['label', 'index', 'input', 'serialized', 'duplicate_serialized']:
                altered = copy.deepcopy(certificate)
                if change == 'label':
                    altered['namespace_plan'][0]['name'] = '_fnv_code_wrong_role'
                elif change == 'index':
                    altered['namespace_plan'][0]['physical_index'] = 8
                elif change == 'input':
                    altered['input_sha256']['imports'] = '0'*64
                elif change == 'serialized':
                    altered['namespace_plan'][0]['serialized_index'] = 3
                else:
                    altered['namespace_plan'].append(dict(physical_index=8, serialized_index=2,
                                                         name='_other'))
                with self.assertRaises(ValueError):
                    p.join_namespace(report, altered)

    def test_hash_mismatch_creates_no_output(self):
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory)
            (path / 'plan.json').write_text('{}')
            args = type('Args', (), dict(plan=path/'plan.json', details=path/'absent.gz',
                                        namespace=path/'absent.json', out=path/'output'))()
            with self.assertRaisesRegex(ValueError, 'SHA-256 differs'):
                p.run(args)
            self.assertFalse((path/'output').exists())

    def test_public_output_rejected_before_any_input_read(self):
        args = type('Args', (), dict(plan='absent', details='absent', namespace='absent',
                                    out=p.ROOT/'src'/'private-import-evidence'))()
        with self.assertRaisesRegex(ValueError, 'private output'):
            p.run(args)

    def test_namespace_helper_drift_rejected(self):
        with tempfile.TemporaryDirectory() as directory:
            helper = Path(directory)/'helper.py'
            helper.write_text('changed helper')
            with patch.object(p, 'NAMESPACE_HELPER', helper):
                with self.assertRaisesRegex(ValueError, 'namespace helper changed'):
                    p.check_helper()

    def test_late_input_drift_removes_only_new_output_files(self):
        with tempfile.TemporaryDirectory() as directory:
            base = Path(directory)
            plan_path, details, namespace = base/'plan.json', base/'details.gz', base/'namespace.json'
            details.write_bytes(b'offline detail stand-in')
            namespace.write_text('{}')
            plan_path.write_text(json.dumps(dict(details_sha256=p.file_hash(details))))
            hashes = (p.file_hash(plan_path), p.file_hash(namespace))
            marker = base/'existing-evidence.txt'
            marker.write_text('preserve')
            class DriftingDefinitions(dict):
                def items(self):
                    yield 'provider-000.def', b'LIBRARY "fixture.dll"\nEXPORTS\n'
                    plan_path.write_text('changed after DEF write')
            args = type('Args', (), dict(plan=plan_path, details=details, namespace=namespace,
                                        out=base/'new-output'))()
            report = dict(summary=dict(cells=25, physical_symbols=25, fields=30))
            with patch.object(p, 'PLAN_PIN', hashes[0]), patch.object(p, 'NAMESPACE_PIN', hashes[1]), \
                    patch.object(p, 'prepare', return_value=report), \
                    patch.object(p, 'join_namespace'), \
                    patch.object(p, 'definitions', return_value=DriftingDefinitions()):
                with self.assertRaisesRegex(ValueError, 'input changed during preparation'):
                    p.run(args)
            self.assertFalse((base/'new-output').exists())
            self.assertEqual(marker.read_text(), 'preserve')


if __name__ == '__main__':
    unittest.main()
