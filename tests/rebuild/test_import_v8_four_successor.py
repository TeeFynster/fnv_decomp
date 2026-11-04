"""Synthetic two-library successor and complete-field evidence gates; no native IO."""
import copy
import gzip
import json
from pathlib import Path
import sys
import tempfile
import unittest
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[2]/'tools/rebuild'))
import import_v8_four_successor as s


def fixture(with_fields=False):
    records = []
    for i in range(27):
        dll = 'GDI32.dll' if i == 0 else 'SHELL32.dll' if i < 3 else 'KERNEL32.dll' if i < 12 else 'USER32.dll'
        identity = dict(kind='name', name='OldImport%d' % i)
        records.append(dict(import_id=1000+i, original_IAT_va='0x%08x' % (0x00402000+4*i), dll=dll,
            export=dict(identity, hint=i), lookup_source='OriginalFirstThunk', representation='IAT_POINTER_CELL_NOT_FUNCTION_BODY',
            required_provider_contract=dict(dll=dll, export=identity, runtime_provider_selected=False)))
    for base, (iid, dll, name, count) in s.SPECS.items():
        identity = dict(kind='name', name=name)
        records.append(dict(import_id=iid, original_IAT_va=base, dll=dll, export=dict(identity, hint=7),
            lookup_source='OriginalFirstThunk', representation='IAT_POINTER_CELL_NOT_FUNCTION_BODY',
            required_provider_contract=dict(dll=dll, export=identity, runtime_provider_selected=False)))
    catalog = dict(kind='fnv-static-import-plan', schema_version=1, summary=dict(imports=31), imports=records,
                   runtime_closure_verified=False, game_fixups_approved=0)
    cells = s.projection.catalog(catalog)
    aliases = [dict(original_IAT_va=r['original_IAT_va'], canonical_IAT_symbol=cells[r['original_IAT_va']]['canonical_IAT_symbol'],
        dll=r['dll'], export=cells[r['original_IAT_va']]['export'], proposed_pointer_symbol='__imp__'+r['export']['name'],
        library='old.lib', member_offset=100+100*i, pointer_indirection_preserved=True, alias_applied=False,
        source_ABI_approved=False, runtime_provider_adopted=False) for i, r in enumerate(records[:27])]
    unchanged = [dict(library='provider-000.lib', sha256='a'*64), dict(library='provider-002.lib', sha256='b'*64)]
    native = dict(proposed_pointer_aliases=aliases, native_library_generated=True,
                  all_inputs_tools_sources_stable=True, unchanged_libraries=unchanged, **s.FALSE_FLAGS)
    replacements = []
    for dll, (old_name, new_name, old_count, new_count, old_hash) in s.DLL_SPECS.items():
        old = [p for p in aliases if p['dll'] == dll]
        names = sorted([p['export']['name'] for p in old]+[v[2] for v in s.SPECS.values() if v[1] == dll])
        definition = ('LIBRARY "'+dll+'"\nEXPORTS\n'+''.join('    '+n+'\n' for n in names)).encode()
        replacements.append(dict(dll=dll, old_library=old_name, old_library_sha256=old_hash,
            prior_native_pointer_identities=old, definition_sha256=s.projection.digest(definition)))
    uses, censuses = [], []
    for base, (iid, dll, name, count) in s.SPECS.items():
        selected = []
        for i in range(count):
            ordinal = len(uses)+1
            row = dict(component='synthetic', member='use-%03d.obj' % ordinal, root='0x00401000', section=1,
                offset=ordinal*4, symbol_index=ordinal, kind=6, undefined=True,
                canonical=cells[base]['canonical_IAT_symbol'], proof=dict(role='iat-cell', original_base=base,
                original_target=base, addend_bits=0, classification='IAT_POINTER_CELL_NOT_FUNCTION_BODY', import_id=iid))
            uses.append(row)
            selected.append(dict(field_ordinal=ordinal, normative_row=copy.deepcopy(row), temporary_census_row=copy.deepcopy(row),
                normative_row_sha256=s.annotations.digest(row), census_view_row_sha256=s.annotations.digest(row), use_gate_passed=True))
        censuses.append(dict(original_IAT_va=base, complete_V8_use_count=count, all_V8_use_proofs_pass=True,
                             blockers=[], complete_use_records=selected))
    assessment = dict(kind='V8-four-import-full-field-successor-assessment', schema_version=1,
        native_library_generated=False, alias_applied=False, proposed_cell_count=31,
        proposed_replacements=replacements, unchanged_libraries=unchanged, per_cell_censuses=censuses,
        complete_normative_field_count=45315, normative_field_canonical_sha256='d'*64, census_view_canonical_sha256='e'*64)
    fields = []
    if with_fields:
        padding = dict(component='padding', canonical='_padding', proof=dict(role='code'))
        fields = uses+[padding]*(45315-len(uses))
        assessment['normative_field_canonical_sha256'] = s.annotations.digest(fields)
        assessment['census_view_canonical_sha256'] = s.annotations.digest(fields)
    review = dict(kind='v8-four-import-assessment-independent-review', status='accepted_metadata_only',
                  assessment_sha256=s.PINS['assessment'])
    return catalog, assessment, review, native, fields


def request_and_parses():
    catalog, assessment, review, native, fields = fixture()
    request, definitions = s.prepare(catalog, assessment, review, native)
    request.update(inputs=dict(assessment_sha256='a'*64), source_sha256=dict(tool='b'*64))
    parsed = {}
    for replacement in request['replacements']:
        parsed[replacement['new_library']] = dict(both_indexes_agree=True, ordinary_members=[{}]*3,
            archive_sha256='c'*64, archive_bytes=4096, imports=[dict(dll=c['dll'], export=c['export'], machine=0x14c,
                import_type=0, symbol='_'+c['export']['name'], pointer_symbol='__imp__'+c['export']['name'],
                member_offset=1000+120*i) for i, c in enumerate(replacement['cells'])])
    return request, parsed


class SuccessorTests(unittest.TestCase):
    def test_exact_two_supersets_and_old_27_preserved_without_input_mutation(self):
        args = fixture(); saved = copy.deepcopy(args)
        request, definitions = s.prepare(*args[:4])
        self.assertEqual(args, saved)
        self.assertEqual(len(request['cells']), 31)
        self.assertEqual([len(r['cells']) for r in request['replacements']], [12, 16])
        self.assertEqual(len(request['unchanged_libraries']), 2)
        self.assertEqual(len(request['prior_pointer_aliases']), 27)
        self.assertIn(b'    ExitProcess\n', definitions['kernel32-twelve.def'])
        self.assertIn(b'    GetAsyncKeyState\n', definitions['user32-sixteen.def'])
        self.assertNotIn(b'"GetAsyncKeyState"', definitions['user32-sixteen.def'])

    def test_whole_45315_field_and_91_use_evidence(self):
        catalog, assessment, review, native, fields = fixture(True); before = s.annotations.digest(fields)
        view = s.validate_fields(assessment, fields, catalog)
        self.assertEqual(len(view), 45315); self.assertEqual(s.annotations.digest(fields), before)
        self.assertEqual(sum(c['complete_V8_use_count'] for c in assessment['per_cell_censuses']), 91)
        assessment['per_cell_censuses'][1]['complete_use_records'].pop()
        with self.assertRaisesRegex(ValueError, 'per-cell use count'): s.validate_fields(assessment, fields, catalog)

    def test_changed_prior_pointer_delta_review_and_definition_rejected(self):
        for change in ('review', 'pointer', 'definition', 'delta'):
            catalog, assessment, review, native, fields = fixture()
            if change == 'review': review['status'] = 'pending'
            if change == 'pointer': native['proposed_pointer_aliases'][0]['runtime_provider_adopted'] = True
            if change == 'definition': assessment['proposed_replacements'][0]['definition_sha256'] = '0'*64
            if change == 'delta': catalog['imports'][-1]['import_id'] = 999
            with self.subTest(change=change), self.assertRaises(ValueError): s.prepare(catalog, assessment, review, native)

    def test_native_two_archive_join_returns_exact_31_and_false_promotion(self):
        request, parsed = request_and_parses(); result = s.reconcile(request, parsed, 'd'*64)
        self.assertEqual(len(result['libraries']), 2)
        self.assertEqual(len(result['proposed_pointer_aliases']), 31)
        self.assertTrue(result['old_27_pointer_identities_preserved'])
        self.assertTrue(result['replacement_identities_verified'])
        self.assertEqual(result['source_sha256'], request['source_sha256'])
        for key in s.FALSE_FLAGS: self.assertIs(result[key], False)

    def test_native_changed_pointer_wrong_dll_incomplete_or_promoted_rejected(self):
        for change in ('pointer', 'dll', 'missing', 'machine', 'promotion'):
            request, parsed = request_and_parses(); item = parsed['kernel32-twelve.lib']['imports'][0]
            if change == 'pointer': item.update(symbol='_Other', pointer_symbol='__imp__Other')
            if change == 'dll': item['dll'] = 'other.dll'
            if change == 'missing': parsed['user32-sixteen.lib']['imports'].pop()
            if change == 'machine': item['machine'] = 0x8664
            if change == 'promotion': request['prior_pointer_aliases'][0]['alias_applied'] = True
            with self.subTest(change=change), self.assertRaises(ValueError): s.reconcile(request, parsed, 'd'*64)

    def test_private_output_gate_precedes_input_reads(self):
        args = type('Args', (), dict(out=s.ROOT/'src'/'import-successor-evidence'))()
        with self.assertRaisesRegex(ValueError, 'private output'): s.run(args)

    def test_exact_two_native_library_keys_and_dlls_required(self):
        request, parsed = request_and_parses()
        parsed['unlisted.lib'] = parsed.pop('user32-sixteen.lib')
        with self.assertRaisesRegex(ValueError, 'exact two DLL'): s.reconcile(request, parsed, 'd'*64)

    def test_final_write_drift_removes_only_new_owned_outputs(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory); paths = {k: root/(k+'.json') for k in s.PINS}
            for name, path in paths.items():
                if name != 'fields': path.write_text(json.dumps(dict(inputs={})))
            with gzip.open(paths['fields'], 'wb') as stream: stream.write(b'[]')
            paths['prior_review'].write_text(json.dumps(dict(status='accepted_metadata_conformance_only',
                collection_sha256=s.sha(paths['prior_native']))))
            args = type('Args', (), dict(**paths, out=root/'build/rebuild/new-output', source_sha256=s.sha(s.__file__)))()
            marker = root/'existing.txt'; marker.write_text('preserve')
            original = json.dump
            def drift(value, stream, **kwargs):
                original(value, stream, **kwargs); paths['assessment'].write_text('changed after final write')
            with patch.object(s, 'ROOT', root), patch.object(s, 'HELPER_PINS', {}), \
                    patch.object(s, 'PINS', {k:s.sha(p) for k,p in paths.items()}), \
                    patch.object(s, 'validate_fields'), \
                    patch.object(s, 'prepare', return_value=(dict(replacements=[], unchanged_libraries=[]), {'f.def':b'EXPORTS\n'})), \
                    patch.object(s.json, 'dump', side_effect=drift):
                with self.assertRaisesRegex(ValueError, 'source/input drift'): s.run(args)
            self.assertFalse(Path(args.out).exists()); self.assertEqual(marker.read_text(), 'preserve')


if __name__ == '__main__': unittest.main()
