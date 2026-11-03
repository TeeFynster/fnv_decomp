"""Synthetic expanded linker-input identity contracts; no native execution."""
import copy
from pathlib import Path
import sys
import tempfile
import unittest
from unittest import mock

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tools/rebuild'))
import application_link_cohort_runner as runner


def fixture():
    kernel, other, proposals, catalog, fields = [], [], [], [], []
    for number in range(26):
        extra = number == 25
        va = runner.INTERLOCKED_CELL if extra else f'0x{0x2000000 + number * 4:08x}'
        dll = 'KERNEL32.dll' if number < 7 or extra else 'USER32.dll'
        name = 'InterlockedDecrement' if extra else 'Api' + str(number)
        export = dict(kind='name', name=name)
        native = dict(member_offset=100 + number * 100, member_sha256='a' * 64,
            dll=dll, export=export, machine=0x14c, import_type=0, name_type=2,
            symbol='_' + name, pointer_symbol='__imp__' + name)
        if number < 7: kernel.append(native)
        elif not extra: other.append(native)
        canonical = '_fnv_undefined_' + runner.digest(runner.diagnostic.canonical(dict(original_base=va, role='iat-cell')))
        identifier = 102 if extra else number
        catalog.append(dict(original_IAT_va=va, import_id=identifier, dll=dll, export=dict(export, hint=number)))
        fields.append(dict(component='reference-1372', member='fixture.obj', offset=number * 4,
            canonical=canonical, undefined=True, kind=6, proof=dict(role='iat-cell', original_base=va,
                original_target=va, addend_bits=0, classification='IAT_POINTER_CELL_NOT_FUNCTION_BODY', import_id=identifier)))
        if not extra:
            proposals.append(dict(canonical_IAT_symbol=canonical, original_IAT_va=va,
                dll=dll, export=export, library='provider-001.lib' if number < 7 else 'provider-000.lib',
                member_offset=native['member_offset'], proposed_pointer_symbol=native['pointer_symbol'],
                alias_applied=False, runtime_provider_adopted=False, source_ABI_approved=False,
                pointer_indirection_preserved=True))
        else: additional = native
    def library(rows):
        return dict(imports=rows, index=[dict(member_offset=row['member_offset'], symbol=row[key])
            for row in rows for key in ['symbol', 'pointer_symbol']])
    manifest = dict(native_import_libraries={'provider-001.lib': library(kernel), 'provider-000.lib': library(other)},
        import_pointer_proposals=proposals)
    replacement = copy.deepcopy(kernel) + [additional]
    for row in replacement: row['member_offset'] += 9000
    return manifest, dict(imports=catalog), fields, library(replacement)


class ExpandedCohortRunnerTests(unittest.TestCase):
    def test_Kernel32_replacement_is_exact_seven_plus_one_not_a_second_provider(self):
        manifest, catalog, fields, native = fixture()
        before = copy.deepcopy(manifest)
        with mock.patch.object(runner.diagnostic.partial, 'native_archive', return_value=native):
            proposals, libraries = runner.replacement_imports(manifest, catalog, b'original fixture metadata')
        self.assertEqual(len(proposals), 26)
        self.assertNotIn('provider-001.lib', libraries)
        self.assertIn('KERNEL32-eight-export', libraries)
        self.assertEqual(manifest, before)
        self.assertTrue(all(row['member_offset'] >= 9000 for row in proposals if row['library'] == 'KERNEL32-eight-export'))
        aliases = runner.expanded_alias_census(proposals, fields, catalog, libraries)
        self.assertEqual(sum(row['enabled'] for row in aliases), 26)

    def test_extra_missing_changed_or_duplicate_export_rejected(self):
        for change in [lambda n: n['imports'].pop(),
            lambda n: n['imports'][0].update(export=dict(kind='name', name='Wrong')),
            lambda n: n['imports'].append(copy.deepcopy(n['imports'][0]))]:
            manifest, catalog, fields, native = fixture(); change(native)
            with mock.patch.object(runner.diagnostic.partial, 'native_archive', return_value=native), self.assertRaises(ValueError):
                runner.replacement_imports(manifest, catalog, b'fixture')

    def test_any_changed_use_disables_only_affected_cell(self):
        manifest, catalog, fields, native = fixture()
        with mock.patch.object(runner.diagnostic.partial, 'native_archive', return_value=native):
            proposals, libraries = runner.replacement_imports(manifest, catalog, b'fixture')
        extra = copy.deepcopy(fields[-1]); extra['kind'] = 20; fields.append(extra)
        aliases = runner.expanded_alias_census(proposals, fields, catalog, libraries)
        self.assertFalse(aliases[-1]['enabled'])
        self.assertEqual(sum(row['enabled'] for row in aliases), 25)
        self.assertTrue(all(row['ABI_approved'] is False for row in aliases))

    def test_conformance_receipt_cannot_omit_or_substitute_a_component(self):
        hashes = [runner.cohort.COMPONENT_PINS[key][1] for key in
            ['reference_archive', 'generic_archive', 'overlay_archive', 'EH_object', 'DATA_0', 'DATA_1']]
        receipt = dict(schema_version=1, kind='application-supplement-native-conformance-v1', status='pass',
            input_stability_verified=True, components=[dict(input_sha256=pin, native_metadata_matches=True) for pin in hashes])
        receipt.update({key: False for key in ['compiler_performed', 'archive_generated', 'object_rewritten',
            'executable_linked', 'Game_execution', 'provider_selected', 'runtime_eligible', 'ABI_verified']})
        self.assertEqual(len(runner.conformance_scope(receipt)), 6)
        for mutate in [lambda r: r['components'].pop(), lambda r: r['components'][0].update(input_sha256='b' * 64),
            lambda r: r['components'][0].update(native_metadata_matches=False)]:
            changed = copy.deepcopy(receipt); mutate(changed)
            with self.assertRaises(ValueError): runner.conformance_scope(changed)

    def native_receipt_fixture(self):
        data = b'original synthetic import library fixture'
        unchanged = [dict(file='library' + str(number), sha256='a' * 64) for number in range(3)]
        sources = {'original-generation-source.py': 'c' * 64}
        preparation = dict(schema_version=1, kind='fnv-kernel32-import-extension-request', source_sha256=sources,
            replacement=dict(old_library='provider-001.lib', old_library_sha256=runner.diagnostic.partial.INPUTS['import_1'][1],
                new_library='kernel32-eight.lib', old_import_count=7, new_import_count=8),
            unchanged_libraries=unchanged, inputs=dict(import_plan_sha256=runner.diagnostic.PINS['imports'][1],
                previous_preparation_sha256=runner.diagnostic.partial.INPUTS['import_preparation'][1],
                previous_native_collection_sha256=runner.diagnostic.partial.INPUTS['import_receipt'][1]))
        native_archive = fixture()[3]
        native_archive.update(archive_sha256=runner.digest(data), archive_bytes=len(data), member_count=11,
            ordinary_members=[dict(member_offset=i, member_sha256='d' * 64) for i in range(3)])
        native = dict(schema_version=1, kind='fnv-kernel32-import-extension-native-collection',
            status='collected-awaiting-independent-conformance', request_sha256='b' * 64,
            source_sha256=sources, library=dict(file='kernel32-eight.lib', sha256=runner.digest(data), bytes=len(data)),
            native_library_generated=True, replacement_identity_verified=True,
            old_seven_pointer_identities_preserved=True, all_inputs_tools_sources_stable=True,
            unchanged_libraries=unchanged, parsed_archive=native_archive,
            inputs=preparation['inputs'], replacement=preparation['replacement'], global_caller_census_verified=False)
        flags = ['alias_applied', 'source_ABI_verified', 'runtime_provider_adopted', 'executable_link_performed',
            'compiler_performed', 'DLL_load_performed', 'imported_API_call_performed', 'runtime_eligible', 'provider_selected']
        native.update({key: False for key in flags}); preparation.update({key: False for key in flags})
        preparation.update(native_library_generated=False, global_caller_census_verified=False)
        return native, preparation, data

    def test_native_collection_is_joined_to_exact_successful_generation_request_and_library(self):
        native, preparation, data = self.native_receipt_fixture()
        actual = copy.deepcopy(native['parsed_archive'])
        actual['support_members'] = actual['ordinary_members']
        with mock.patch.object(runner.diagnostic.partial, 'native_archive', return_value=actual):
            runner.kernel32_native_evidence(native, preparation, 'b' * 64, data)
        for mutate in [lambda r: r.clear(), lambda r: r.update(status='failed'),
            lambda r: r.update(request_sha256='d' * 64),
            lambda r: r['library'].update(sha256='d' * 64),
            lambda r: r.update(source_sha256={'unrelated-source.py': 'c' * 64}),
            lambda r: r.update(native_library_generated=False),
            lambda r: r.update(runtime_provider_adopted=True)]:
            changed = copy.deepcopy(native); mutate(changed)
            with self.assertRaises(ValueError):
                runner.kernel32_native_evidence(changed, preparation, 'b' * 64, data)

    def test_declared_native_member_facts_cannot_borrow_unrelated_actual_library(self):
        native, preparation, data = self.native_receipt_fixture()
        actual = dict(imports=[dict(member_offset=100)], index=[])
        with mock.patch.object(runner.diagnostic.partial, 'native_archive', return_value=actual), self.assertRaises(ValueError):
            runner.kernel32_native_evidence(native, preparation, 'b' * 64, data)

    def test_response_replaces_DATA_and_kernel32_without_modifying_saved_plan(self):
        old_args = runner.diagnostic.FLAGS + ['/OUT:old.exe', '/MAP:old.map', 'old-data.obj', 'old-kernel.lib',
            '/ALTERNATENAME:old=pointer']
        old = runner.diagnostic.response_text(old_args)
        aliases = [dict(canonical='new', native_pointer='__imp__Api', enabled=True)]
        args = runner.response_arguments(old, {'old-data.obj': 'readonly-data.obj', 'old-kernel.lib': 'kernel-eight.lib'},
            ['supplement.lib'], Path('private'), aliases)
        self.assertNotIn('old-kernel.lib', args); self.assertNotIn('old-data.obj', args)
        self.assertNotIn('/ALTERNATENAME:old=pointer', args)
        self.assertIn('/ALTERNATENAME:new=__imp__Api', args)
        self.assertEqual(old, runner.diagnostic.response_text(old_args))
        with self.assertRaises(ValueError):
            runner.response_arguments(old, {'missing': 'new'}, [], Path('private'), aliases)
        with self.assertRaises(ValueError):
            runner.response_arguments(old, {}, ['/FORCE:MULTIPLE'], Path('private'), aliases)

    def test_unused_EH_candidate_is_not_silently_forced_or_bound(self):
        observation = dict(status='metadata-observed-native-conformance-pending',
            total_game_function_providers=14330, complete_field_count=44364,
            EH_logical_demand_uses=[], EH_logical_binding_applied=False,
            supplementary_providers=[dict(component='ordinary')] * 1382 + [dict(component='IOTask-EH')],
            supplementary_fields=[dict(component='ordinary')] * 7071 + [dict(component='IOTask-EH')] * 11)
        providers, fields, excluded = runner.selected_observation(observation)
        self.assertEqual(len(providers), 1382); self.assertEqual(len(fields), 7071)
        self.assertFalse(excluded['selected'])
        observation['EH_logical_demand_uses'] = [dict(caller='new')]
        with self.assertRaises(ValueError): runner.selected_observation(observation)

    def test_scoped_inputs_are_hash_bound_and_cannot_escape_private_output_root(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp); target = root / 'build/rebuild/native.lib'
            target.parent.mkdir(parents=True); target.write_bytes(b'original non-executable metadata fixture')
            record = dict(path='build/rebuild/native.lib', sha256=runner.diagnostic.file_hash(target))
            self.assertEqual(runner.bound_relative_input(root, record)[0], target.resolve())
            for changed in [dict(record, sha256='a' * 64), dict(record, path=str(target)),
                            dict(record, extra=True)]:
                with self.assertRaises(ValueError): runner.bound_relative_input(root, changed)
            public = root / 'public.lib'; public.write_bytes(target.read_bytes())
            with self.assertRaises(ValueError):
                runner.bound_relative_input(root, dict(path='public.lib', sha256=record['sha256']))

    def test_stale_sources_stop_before_request_or_native_LINK(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp); path = root / next(iter(runner.SOURCE_PINS))
            path.parent.mkdir(parents=True); path.write_text('changed')
            with mock.patch.object(runner.diagnostic, 'link_once') as link, self.assertRaisesRegex(ValueError, 'source/dependency'):
                runner.prepare(root, root / 'build/rebuild/out', 'a' * 64, root / 'missing.json', 'b' * 64)
            link.assert_not_called(); self.assertFalse((root / 'build/rebuild/out').exists())

    def test_default_command_never_launches_native_LINK(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            report = dict(status='prepared-no-native-LINK', native_LINK_performed=False,
                          input_bindings=[], aliases=[])
            with mock.patch.object(sys, 'argv', ['cohort', '--source-sha256', 'a' * 64,
                '--inputs', 'fixture.json', '--inputs-sha256', 'b' * 64, '--out', str(root)]), \
                mock.patch.object(runner, 'prepare', return_value=report), \
                mock.patch.object(runner.diagnostic, 'link_once') as link:
                runner.main()
            link.assert_not_called(); self.assertTrue((root / 'receipt.json').is_file())


if __name__ == '__main__': unittest.main()
