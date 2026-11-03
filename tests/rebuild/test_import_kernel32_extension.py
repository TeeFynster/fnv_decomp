"""Synthetic extension metadata and archive negatives; no native processes."""
import copy
import json
from pathlib import Path
import struct
import sys
import tempfile
import unittest
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[2]/'tools/rebuild'))
import import_kernel32_extension as e
import normal_import_archive as reader


def fixture():
    rows = []
    for index in range(26):
        dll = 'KERNEL32.dll' if index < 7 or index == 25 else 'fixture.dll'
        va = e.NEW_CELL if index == 25 else '0x%08x' % (0x00402000+4*index)
        name = 'InterlockedDecrement' if index == 25 else 'Entry%d' % index
        exp = dict(kind='name', name=name)
        rows.append(dict(import_id=102 if index == 25 else index, original_IAT_va=va,
                         dll=dll, export=dict(exp, hint=100+index), lookup_source='OriginalFirstThunk',
                         representation='IAT_POINTER_CELL_NOT_FUNCTION_BODY',
                         required_provider_contract=dict(dll=dll, export=exp, runtime_provider_selected=False)))
    plan = dict(kind='fnv-static-import-plan', schema_version=1, runtime_closure_verified=False,
                game_fixups_approved=0, imports=rows, summary=dict(imports=26))
    cells = list(e.projection.catalog(plan).values())
    aliases = [dict(original_IAT_va=c['original_IAT_va'], canonical_IAT_symbol=c['canonical_IAT_symbol'],
                    dll=c['dll'], export=c['export'], proposed_pointer_symbol='__imp__'+c['export']['name'],
                    library='provider-001.lib' if i < 7 else 'provider-%03d.lib' % (0 if i < 8 else 2 if i < 10 else 3),
                    member_offset=1000+100*i, alias_applied=False, source_ABI_approved=False,
                    runtime_provider_adopted=False) for i, c in enumerate(cells[:25])]
    libraries = []
    for number in range(4):
        filename = 'provider-%03d.lib' % number
        libraries.append(dict(library=filename, archive_sha256=e.OLD_LIBRARY_SHA256 if number == 1 else str(number)*64,
                              imports=[a for a in aliases if a['library'] == filename]))
    previous = dict(kind='fnv-normal-import-projection-preparation', schema_version=2,
                    summary=dict(cells=25), selected_cells=cells[:25])
    native = dict(kind='fnv-main-normal-import-native-collection', schema_version=1,
                  native_library_generated=True, all_inputs_tools_sources_stable=True,
                  proposed_pointer_aliases=aliases, libraries=libraries, **e.FALSE_FLAGS)
    return plan, previous, native


def request_and_parse():
    request, definition = e.prepare(*fixture())
    request['inputs'] = dict(import_plan_sha256='a'*64)
    request['source_sha256'] = dict(tool='b'*64)
    imports = [dict(dll=c['dll'], export=c['export'], machine=0x14c, import_type=0,
                    symbol='_'+c['export']['name'], pointer_symbol='__imp__'+c['export']['name'],
                    member_offset=1000+120*i) for i, c in enumerate(request['cells'])]
    parsed = dict(both_indexes_agree=True, imports=imports, ordinary_members=[{}]*3,
                  archive_sha256='c'*64, archive_bytes=4096)
    return request, parsed


def archive_bytes(symbol='_Entry', dll='fixture.dll', info=8, machine=0x14c):
    names = [symbol, '__imp_'+symbol]
    strings = b''.join(n.encode()+b'\0' for n in names)
    first_size, second_size = 12+len(strings), 16+len(strings)
    offset = 8+60+first_size+(first_size & 1)+60+second_size+(second_size & 1)
    first = struct.pack('>III', 2, offset, offset)+strings
    second = struct.pack('<IIIHH', 1, offset, 2, 1, 1)+strings
    payload = symbol.encode()+b'\0'+dll.encode()+b'\0'
    short = struct.pack('<HHHHIIHH', 0, 0xffff, 0, machine, 0, len(payload), 7, info)+payload
    def member(name, raw):
        header = ('%-16s%-12d%-6d%-6d%-8d%-10d`\n' % (name, 0, 0, 0, 0, len(raw))).encode()
        return header+raw+(b'\n' if len(raw) & 1 else b'')
    return b'!<arch>\n'+member('/', first)+member('/', second)+member('fixture.dll/', short)


class ExtensionTests(unittest.TestCase):
    def test_exact_eight_def_preserves_hints_and_unmodified_prior_evidence(self):
        data = fixture(); saved = copy.deepcopy(data)
        request, definition = e.prepare(*data)
        self.assertEqual(data, saved)
        self.assertEqual(len(request['cells']), 8)
        self.assertEqual(len(request['prior_kernel32_aliases']), 7)
        self.assertEqual(len(request['unchanged_libraries']), 3)
        self.assertIn(b'    InterlockedDecrement\n', definition)
        self.assertNotIn(b'"InterlockedDecrement"', definition)
        new = next(c for c in request['cells'] if c['original_IAT_va'] == e.NEW_CELL)
        self.assertEqual(new['original_export_metadata']['hint'], 125)
        self.assertFalse(request['global_caller_census_verified'])

    def test_wrong_original_new_export_and_promoted_alias_rejected(self):
        plan, previous, native = fixture()
        plan['imports'][-1]['export']['name'] = 'Wrong'
        plan['imports'][-1]['required_provider_contract']['export']['name'] = 'Wrong'
        with self.assertRaisesRegex(ValueError, 'new exact IAT'):
            e.prepare(plan, previous, native)
        plan, previous, native = fixture()
        native['proposed_pointer_aliases'][0]['alias_applied'] = True
        with self.assertRaisesRegex(ValueError, 'promotion'):
            e.prepare(plan, previous, native)

    def test_native_exact_pointer_join_and_false_promotion(self):
        request, parsed = request_and_parse()
        result = e.reconcile(request, parsed, 'd'*64)
        self.assertEqual(result['library']['sha256'], parsed['archive_sha256'])
        self.assertEqual(result['source_sha256'], request['source_sha256'])
        self.assertEqual(len(result['proposed_pointer_aliases']), 26)
        self.assertTrue(result['old_seven_pointer_identities_preserved'])
        self.assertTrue(result['native_library_generated'])
        for key in e.FALSE_FLAGS:
            self.assertIs(result[key], False)

    def test_old_pointer_drift_rejected_even_with_same_export(self):
        request, parsed = request_and_parse()
        old = request['prior_kernel32_aliases'][0]
        imp = next(i for i in parsed['imports'] if i['export'] == old['export'])
        imp.update(symbol='_Different', pointer_symbol='__imp__Different')
        with self.assertRaisesRegex(ValueError, 'old seven'):
            e.reconcile(request, parsed, 'd'*64)

    def test_quoted_or_wrong_dll_and_missing_import_rejected(self):
        for change in ('quote', 'dll', 'missing', 'machine', 'index'):
            request, parsed = request_and_parse()
            if change == 'quote': parsed['imports'][0]['export'] = dict(kind='name', name='"Entry"')
            if change == 'dll': parsed['imports'][0]['dll'] = 'other.dll'
            if change == 'missing': parsed['imports'].pop()
            if change == 'machine': parsed['imports'][0]['machine'] = 0x8664
            if change == 'index': parsed['both_indexes_agree'] = False
            with self.subTest(change=change), self.assertRaises(ValueError):
                e.reconcile(request, parsed, 'd'*64)

    def test_wrong_replacement_and_promoted_request_or_other_alias_rejected(self):
        for change in ('replacement', 'request', 'alias', 'hash'):
            request, parsed = request_and_parse()
            receipt_hash = 'd'*64
            if change == 'replacement': request['replacement']['old_import_count'] = 8
            if change == 'request': request['global_caller_census_verified'] = True
            if change == 'alias': request['prior_other_aliases'][0]['runtime_provider_adopted'] = True
            if change == 'hash': receipt_hash = 'not-a-sha'
            with self.subTest(change=change), self.assertRaises(ValueError):
                e.reconcile(request, parsed, receipt_hash)

    def test_public_output_rejected_before_reading_inputs(self):
        args = type('Args', (), dict(out=e.ROOT/'src'/'private-import-extension'))()
        with self.assertRaisesRegex(ValueError, 'not private'):
            e.run(args)

    def test_external_output_rejected_before_reading_inputs(self):
        with tempfile.TemporaryDirectory() as directory:
            args = type('Args', (), dict(out=Path(directory)/'output'))()
            with self.assertRaisesRegex(ValueError, 'not private'):
                e.run(args)

    def test_final_report_write_input_drift_removes_only_owned_outputs(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            files = {name: root/(name+'.json') for name in ('plan', 'previous', 'native')}
            for name, path in files.items():
                path.write_text(json.dumps(dict(libraries=[])) if name == 'native' else '{}')
            marker = root/'existing-evidence.txt'; marker.write_text('preserve')
            args = type('Args', (), dict(**files, out=root/'build/rebuild/new-output',
                                        source_sha256=e.sha(e.__file__)))()
            original_dump = json.dump
            def mutate_after_report_write(value, stream, **kwargs):
                original_dump(value, stream, **kwargs)
                files['plan'].write_text('changed after final report write')
            with patch.object(e, 'ROOT', root), patch.object(e, 'PLAN_PIN', e.sha(files['plan'])), \
                    patch.object(e, 'PREVIOUS_PREPARATION_PIN', e.sha(files['previous'])), \
                    patch.object(e, 'PREVIOUS_NATIVE_PIN', e.sha(files['native'])), \
                    patch.object(e, 'prepare', return_value=({}, b'LIBRARY fixture.dll\nEXPORTS\n')), \
                    patch.object(e.json, 'dump', side_effect=mutate_after_report_write):
                with self.assertRaisesRegex(ValueError, 'source/input drift'):
                    e.run(args)
            self.assertFalse(Path(args.out).exists())
            self.assertEqual(marker.read_text(), 'preserve')


class ArchiveReaderTests(unittest.TestCase):
    def read(self, raw):
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory)/'fixture.lib'; path.write_bytes(raw)
            return reader.read_archive(path)

    def test_actual_short_symbol_and_unquoted_export(self):
        parsed = self.read(archive_bytes())
        self.assertEqual(parsed['imports'][0]['pointer_symbol'], '__imp__Entry')
        self.assertEqual(parsed['imports'][0]['export'], dict(kind='name', name='Entry'))
        self.assertTrue(parsed['both_indexes_agree'])

    def test_quote_regression_is_observed_without_normalization(self):
        parsed = self.read(archive_bytes(symbol='_"Entry"'))
        self.assertEqual(parsed['imports'][0]['export']['name'], '"Entry"')

    def test_named_and_ordinal_modes(self):
        self.assertEqual(self.read(archive_bytes(info=0))['imports'][0]['export'], dict(kind='ordinal', ordinal=7))
        self.assertEqual(self.read(archive_bytes(symbol='_Entry@4', info=12))['imports'][0]['export']['name'], 'Entry')

    def test_machine_encoding_and_index_corruption_rejected(self):
        cases = [archive_bytes(machine=0x8664), archive_bytes(info=20), archive_bytes(dll='../bad.dll')]
        raw = bytearray(archive_bytes()); struct.pack_into('>I', raw, 8+60+4, 9); cases.append(raw)
        for raw in cases:
            with self.assertRaises(ValueError): self.read(raw)


if __name__ == '__main__':
    unittest.main()
