"""Original synthetic evidence and mocked native boundaries only."""
import copy
from pathlib import Path
import struct
import sys
import tempfile
from types import SimpleNamespace
import unittest
from unittest import mock

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tools/rebuild'))
import application_link_diagnostic as diagnostic


def object_fixture(target_undefined=True):
    names = ['root', 'target']; strings = bytearray(bytes(4)); table = bytearray()
    for index, name in enumerate(names):
        at = len(strings); strings += name.encode() + b'\0'
        table += struct.pack('<IIIhHBB', 0, at, 0, 0 if index and target_undefined else 1, 32, 2, 0)
    struct.pack_into('<I', strings, 0, len(strings))
    payload = bytes(128); relocs = struct.pack('<IIH', 4, 1, 6)
    return struct.pack('<HHIIIHH', 0x14c, 1, 0, 198, 2, 0, 0) + \
        struct.pack('<8sIIIIIIHHI', b'.text', 0, 0, 128, 60, 188, 0, 1, 0, 0x60500020) + payload + relocs + table + strings


def union_fixture(target_undefined=True):
    data = object_fixture(target_undefined)
    obligation = dict(original_address='0x00401000', physical_section=7, field_offset=4,
        symbol_index=11, kind=6, canonical_name='target', role='iat-cell', import_id=1,
        original_base='0x02000000', original_target='0x02000000', addend_bits=0,
        classification='IAT_POINTER_CELL_NOT_FUNCTION_BODY')
    plan = dict(eligible=True, recipe_id='synthetic', object_sha256='a' * 64,
        namespace_plan=[dict(serialized_index=0, physical_index=10, name='root'),
                        dict(serialized_index=1, physical_index=11, name='target')],
        roots=[dict(original_address='0x00401000', section=7, symbol_index=10, value=0, size=128)],
        obligations=[obligation] if target_undefined else [], counts=dict(fields=1),
        comparison_base_view={'target': '0x00401000'})
    row = dict(member=dict(name='synthetic.obj', sha256=diagnostic.digest(data)),
        receipt=dict(plan=plan, maps=dict(section_map={'7': 1}, symbol_map={'10': 0, '11': 1}),
            output_sha256=diagnostic.digest(data), exports=['root'], binding_row_references={'0x00401000': []},
            original_binding_details_sha256='4dfc437064b16c1bb933008aebf7def8d279a903eef9cca24d0fedcc12d7d826'))
    return data, row


class ApplicationLinkDiagnosticTests(unittest.TestCase):
    def test_exact_saved_union_row_fits_bounded_metadata_limit(self):
        diagnostic.union_stream_bound(687, 36594669)
        diagnostic.union_stream_bound(10000, 64 * 1024 * 1024)
        for ordinal, size in [(0, 1), (10001, 1), (1, 0), (1, 64 * 1024 * 1024 + 1)]:
            with self.assertRaisesRegex(ValueError, 'union stream bound'):
                diagnostic.union_stream_bound(ordinal, size)

    def test_actual_fields_join_complete_physical_owner_metadata(self):
        data, row = union_fixture()
        roots, fields, obj = diagnostic.roots_and_fields(data, row)
        self.assertEqual(fields[0]['physical_symbol_index'], 11)
        self.assertEqual(fields[0]['root'], '0x00401000')
        self.assertEqual(fields[0]['proof']['original_target'], '0x02000000')
        self.assertEqual(len(fields), 1)

    def test_undefined_field_missing_conflicting_or_extra_witness_fails(self):
        for mutate in [lambda r: r['receipt']['plan']['obligations'].clear(),
            lambda r: r['receipt']['plan']['obligations'][0].update(symbol_index=10),
            lambda r: r['receipt']['plan']['obligations'][0].update(addend_bits=4),
            lambda r: r['receipt']['plan']['obligations'].append(copy.deepcopy(r['receipt']['plan']['obligations'][0]))]:
            data, row = union_fixture(); mutate(row)
            with self.assertRaises(ValueError):
                diagnostic.roots_and_fields(data, row)

    def test_defined_local_fields_are_censused_without_inventing_undefineds(self):
        data, row = union_fixture(False)
        roots, fields, obj = diagnostic.roots_and_fields(data, row)
        self.assertEqual(fields[0]['proof']['role'], 'retained')
        self.assertFalse(fields[0]['undefined'])

    def proposals(self):
        proposals, fields, imports = [], [], []
        for index in range(25):
            va = f'0x{0x2000000 + index * 4:08x}'
            name = '_fnv_undefined_' + diagnostic.digest(diagnostic.canonical(dict(original_base=va, role='iat-cell')))
            export = dict(kind='name', name='Api' + str(index))
            proposals.append(dict(canonical_IAT_symbol=name, original_IAT_va=va, dll='EXAMPLE.dll',
                export=export, proposed_pointer_symbol='__imp__Api' + str(index),
                pointer_indirection_preserved=True, alias_applied=False, runtime_provider_adopted=False,
                library='provider-000.lib', member_offset=100 + index))
            fields.append(dict(canonical=name, component='current-CODE', member='original.obj', offset=index * 4,
                undefined=True, kind=6, proof=dict(role='iat-cell', original_base=va, original_target=va,
                    addend_bits=0, import_id=index, classification='IAT_POINTER_CELL_NOT_FUNCTION_BODY')))
            imports.append(dict(original_IAT_va=va, dll='EXAMPLE.dll', export=export, import_id=index))
        return proposals, fields, dict(imports=imports)

    def native_libraries(self, proposals):
        rows = [dict(member_offset=row['member_offset'], member_sha256='b' * 64,
            machine=0x14c, import_type=0, name_type=2, dll='EXAMPLE.dll', export=row['export'],
            symbol='_' + row['export']['name'], pointer_symbol='__imp__' + row['export']['name']) for row in proposals]
        index = [dict(symbol=row[key], member_offset=row['member_offset']) for row in rows
                 for key in ['symbol', 'pointer_symbol']]
        return {'provider-000.lib': dict(imports=rows, index=index)}

    def test_each_alias_requires_all_uses_of_that_cell_only(self):
        proposals, fields, imports = self.proposals()
        extra = copy.deepcopy(fields[0]); extra['offset'] = 1000; fields.append(extra)
        result = diagnostic.alias_census(proposals, fields, imports, self.native_libraries(proposals))
        self.assertEqual(sum(r['enabled'] for r in result), 25)
        self.assertEqual(result[0]['use_count'], 2)
        fields[-1]['kind'] = 20
        result = diagnostic.alias_census(proposals, fields, imports, self.native_libraries(proposals))
        self.assertFalse(result[0]['enabled'])
        self.assertEqual(sum(r['enabled'] for r in result), 24)

    def test_missing_use_wrong_catalog_id_and_pointer_conflict_block_only_cell(self):
        for change in [lambda p, f, i: f.pop(0),
            lambda p, f, i: i['imports'][0].update(dll='OTHER.dll'),
            lambda p, f, i: f[0]['proof'].update(import_id=100),
            lambda p, f, i: p[0].update(proposed_pointer_symbol='_Api0'),
            lambda p, f, i: f[0]['proof'].update(addend_bits=4)]:
            args = self.proposals(); change(*args)
            result = diagnostic.alias_census(*args, self.native_libraries(args[0]))
            self.assertFalse(result[0]['enabled'])
            self.assertEqual(sum(row['enabled'] for row in result), 24)
            self.assertTrue(all(row['ABI_approved'] is False for row in result))

    def test_named_hint_is_retained_metadata_outside_positive_identity(self):
        proposals, fields, imports = self.proposals()
        imports['imports'][0]['export'] = dict(kind='name', name='Api0', hint=513)
        rows = diagnostic.alias_census(proposals, fields, imports, self.native_libraries(proposals))
        self.assertTrue(all(row['enabled'] for row in rows))
        self.assertEqual(rows[0]['documented_catalog_hint'], 513)
        self.assertEqual(rows[0]['catalog_export_observation']['hint'], 513)
        self.assertEqual(rows[0]['positive_import_identity'], ('EXAMPLE.dll', 'name', 'Api0'))
        self.assertNotIn('hint', rows[0]['proposal_export_observation'])

    def test_positive_identity_rejects_changed_case_name_kind_and_unknown_keys(self):
        self.assertNotEqual(diagnostic.import_identity('EXAMPLE.dll', dict(kind='name', name='Api')),
                            diagnostic.import_identity('example.dll', dict(kind='name', name='Api')))
        self.assertEqual(diagnostic.import_identity('EXAMPLE.dll', dict(kind='ordinal', ordinal=17)),
                         ('EXAMPLE.dll', 'ordinal', 17))
        for export in [dict(kind='name', name='Api', undocumented=1), dict(kind='name', name='Api', hint=True),
            dict(kind='name', name='Api', hint=65536), dict(kind='ordinal', ordinal=17, hint=1),
            dict(kind='ordinal', ordinal=True), dict(kind='ordinal', name='Api'), dict(kind='other', name='Api')]:
            with self.assertRaises(ValueError):
                diagnostic.import_identity('EXAMPLE.dll', export)
        for change in [lambda c: c.update(dll='example.dll'),
                       lambda c: c.update(export=dict(kind='name', name='Changed')),
                       lambda c: c.update(export=dict(kind='ordinal', ordinal=17)),
                       lambda c: c.update(export=dict(kind='name', name='Api0', unknown=3))]:
            proposals, fields, imports = self.proposals(); change(imports['imports'][0])
            rows = diagnostic.alias_census(proposals, fields, imports, self.native_libraries(proposals))
            self.assertFalse(rows[0]['enabled'])
            self.assertEqual(sum(row['enabled'] for row in rows), 24)

    def test_native_pointer_member_conflict_blocks_cell_even_with_matching_catalog(self):
        for change in [lambda n: n['imports'][0].update(pointer_symbol='_Api0'),
            lambda n: n['imports'][0].update(dll='OTHER.dll'),
            lambda n: n['imports'][0].update(import_type=1),
            lambda n: n['index'].pop(0),
            lambda n: n['imports'].append(copy.deepcopy(n['imports'][0]))]:
            proposals, fields, imports = self.proposals()
            native = self.native_libraries(proposals); change(native['provider-000.lib'])
            rows = diagnostic.alias_census(proposals, fields, imports, native)
            self.assertFalse(rows[0]['enabled'])
            self.assertEqual(sum(row['enabled'] for row in rows), 24)

    def test_actual_unresolved_groups_separate_targets_callers_and_candidate_provenance(self):
        target, caller = '_fnv_undefined_' + 'a' * 64, '_fnv_code_' + 'b' * 64
        text = f'member.obj : error LNK2019: unresolved external symbol {target} referenced in function {caller}'
        errors = diagnostic.diagnostic_errors(text + '\n' + text, {})
        receipt = dict(errors=errors, provenance={target: [
            dict(component='current-CODE', caller=caller, proof=dict(role='data', original_base='0x02000000', original_target='0x02000000')),
            dict(component='current-CODE', caller='unselected-caller', proof=dict(role='data', original_base='0x02000000', original_target='0x02000004'))]})
        groups = diagnostic.unresolved_groups(receipt)
        self.assertEqual(groups['unique_unresolved_symbols'], 1)
        self.assertEqual(groups['error_occurrences'], 2)
        self.assertEqual(groups['classifications'], {'DATA': 1})
        self.assertEqual(groups['groups'][0]['reported_reference_callers'], [caller])
        self.assertEqual(len(groups['groups'][0]['reported_caller_provenance']), 1)
        self.assertEqual(len(groups['groups'][0]['included_input_provenance']), 2)
        receipt['provenance'][target][1]['proof']['role'] = 'code'
        self.assertEqual(diagnostic.unresolved_groups(receipt)['groups'][0]['classification'], 'CONFLICT_OR_UNKNOWN')

    def test_normal_command_rejects_all_waivers_and_custom_entry(self):
        self.assertIn('/SUBSYSTEM:WINDOWS', diagnostic.FLAGS)
        for flag in ['/ENTRY:fake', '/FORCE:MULTIPLE', '/IGNORE:4006', '/NODEFAULTLIB', '/WHOLEARCHIVE:all.lib']:
            with self.assertRaises(ValueError):
                diagnostic.response_text(diagnostic.FLAGS + [flag])
        for arg in ['broken"quote', 'line\nbreak']:
            with self.assertRaises(ValueError):
                diagnostic.response_text([arg])
        text = diagnostic.response_text(['/OUT:C:\\Private Path\\diagnostic.exe'])
        self.assertEqual(text, '"/OUT:C:\\Private Path\\diagnostic.exe"\n')

    def test_errors_preserve_duplicate_lines_and_unknown_native_symbols(self):
        name = '_fnv_undefined_' + 'a' * 64
        line = 'unit.obj : error LNK2001: unresolved external symbol ' + name
        text = line + '\n' + line + '\nLIBCMT.lib : error LNK2019: unresolved external symbol _unknown referenced in function _crt'
        rows = diagnostic.diagnostic_errors(text, {name: [dict(original_target='0x02000000')]})
        self.assertEqual(len(rows), 3)
        self.assertEqual(rows[0]['canonical_records'][name]['provenance_key'], name)
        self.assertEqual(rows[0]['canonical_records'][name]['observations'], 1)
        self.assertIn('_unknown', rows[2]['text'])
        self.assertEqual(rows[2]['canonical_records'], {})

    def test_success_never_implies_runtime_ready_and_other_errors_survive(self):
        self.assertEqual(diagnostic.classify(0, []), 'unexpected-link-success-not-runtime-approved')
        self.assertEqual(diagnostic.classify(1, [dict(code='LNK2001')]), 'expected-unresolved-link-diagnostic')
        self.assertEqual(diagnostic.classify(1, [dict(code='LNK1104')]), 'other-link-failure-requires-review')
        mixed = diagnostic.diagnostic_errors('x : error LNK2001: unresolved\nx : fatal error LNK1104: cannot open file', {})
        self.assertEqual(diagnostic.classify(1, mixed), 'other-link-failure-requires-review')
        warnings = diagnostic.diagnostic_errors('x : error LNK2001: unresolved\nx : warning LNK4099: symbols missing', {})
        self.assertEqual(diagnostic.classify(1, warnings), 'expected-unresolved-link-diagnostic')
        self.assertEqual(warnings[1]['severity'], 'warning')

    def test_file_binding_retains_requested_path_and_rejects_same_path_replacement(self):
        with tempfile.TemporaryDirectory() as temp:
            path = Path(temp) / 'tool.bin'; path.write_bytes(b'original synthetic bytes')
            row = diagnostic.identity(path)
            self.assertEqual(row['requested_path'], str(path.absolute()))
            diagnostic.stable([row])
            path.replace(path.with_suffix('.old'))
            path.write_bytes(b'original synthetic bytes')
            with self.assertRaisesRegex(ValueError, 'identity drift'):
                diagnostic.stable([row])

    def test_actual_local_dependency_candidates_do_not_invent_msobj_requirement(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            for relative in ['VC/bin/mspdb80.dll', 'VC/bin/mspdbcore.dll', 'VC/bin/mspdbsrv.exe',
                'VC/bin/Microsoft.VC90.CRT/msvcr90.dll', 'VC/redist/x86/Microsoft.VC90.CRT/msvcr90.dll']:
                path = root / relative; path.parent.mkdir(parents=True, exist_ok=True)
                path.write_bytes(b'original synthetic non-executable dependency metadata fixture')
            candidates = diagnostic.native_dependency_candidates(root)
            self.assertEqual(len(candidates), 5)
            self.assertFalse((root / 'VC/bin/msobj80.dll').exists())
            (root / 'VC/bin/mspdb80.dll').unlink()
            with self.assertRaises(FileNotFoundError):
                diagnostic.native_dependency_candidates(root)

    def test_stale_sources_block_before_native_tools_or_output(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp); (root / 'tools/rebuild').mkdir(parents=True)
            (root / 'tools/rebuild/application_link_inputs.py').write_text('changed')
            with mock.patch.object(diagnostic.subprocess, 'run') as native, self.assertRaises(ValueError):
                diagnostic.prepare(root, root / 'build/rebuild/out', '0' * 64)
            native.assert_not_called()
            self.assertFalse((root / 'build/rebuild/out').exists())

    def test_linking_cannot_repeat_or_launch_output(self):
        with mock.patch.object(diagnostic.os, 'name', 'nt'), \
            mock.patch.object(diagnostic.subprocess, 'run') as native, self.assertRaises(ValueError):
            diagnostic.link_once(dict(native_LINK_performed=True), Path('unused'))
        native.assert_not_called()

    def test_default_cli_never_invokes_native_link(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            report = dict(status='prepared-no-native-LINK', native_LINK_performed=False)
            with mock.patch.object(sys, 'argv', ['diagnostic', '--source-sha256', 'a' * 64, '--out', str(root)]), \
                mock.patch.object(diagnostic, 'prepare', return_value=report), \
                mock.patch.object(diagnostic, 'link_once') as native:
                diagnostic.main()
            native.assert_not_called()
            self.assertTrue((root / 'receipt.json').is_file())

    def test_saved_analysis_cli_cannot_request_link_or_change_historical_aliases(self):
        with mock.patch.object(sys, 'argv', ['diagnostic', '--source-sha256', 'a' * 64,
            '--out', 'unused', '--analyze-v3', '--link-once']), \
            mock.patch.object(diagnostic, 'prepare') as prepare, \
            mock.patch.object(diagnostic, 'analyze_saved_v3') as analyze, self.assertRaises(ValueError):
            diagnostic.main()
        prepare.assert_not_called(); analyze.assert_not_called()

    def test_native_boundary_is_exactly_one_link_and_retains_all_error_lines(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp); path_type = type(root)
            (root / 'link.rsp').write_text('original synthetic response')
            report = dict(native_LINK_performed=False, input_bindings=[], compiler_root=str(root),
                sdk_root=str(root), default_libraries={}, response_sha256=diagnostic.file_hash(root / 'link.rsp'),
                command=['reviewed-link.exe', '@' + str(root / 'link.rsp')], provenance={})
            def fake_link(command, **kw):
                kw['stdout'].write(b'fixture.obj : error LNK2001: unresolved external symbol _unknown\n')
                kw['stderr'].write(b'diagnostic.exe : fatal error LNK1120: 1 unresolved externals\n')
                self.assertNotIn('LINK', kw['env'])
                self.assertNotIn('_LINK_', kw['env'])
                return SimpleNamespace(returncode=1120)
            with mock.patch.object(diagnostic.os, 'name', 'nt'), mock.patch.object(diagnostic, 'Path', path_type), \
                mock.patch.object(diagnostic.subprocess, 'CREATE_NO_WINDOW', 0, create=True), \
                mock.patch.object(diagnostic, 'stable'), mock.patch.object(diagnostic, 'select_libraries', return_value={}), \
                mock.patch.object(diagnostic.toolchain, 'environment', return_value={'LINK': 'bad', '_LINK_': 'bad'}), \
                mock.patch.object(diagnostic.subprocess, 'run', side_effect=fake_link) as native:
                diagnostic.link_once(report, root)
            self.assertEqual(native.call_count, 1)
            self.assertEqual(native.call_args.args[0][0], 'reviewed-link.exe')
            self.assertEqual(report['status'], 'expected-unresolved-link-diagnostic')
            self.assertEqual(len(report['errors']), 2)
            self.assertTrue((root / 'progress.jsonl').is_file())
            self.assertNotIn('diagnostic.exe', native.call_args.args[0][0])


if __name__ == '__main__':
    unittest.main()
