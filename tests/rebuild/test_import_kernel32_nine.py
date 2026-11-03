"""Synthetic fixed nine-export metadata tests; no native process or Game input."""
import copy
import json
from pathlib import Path
import sys
import tempfile
import unittest
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[2]/'tools/rebuild'))
import import_kernel32_nine as n


def fixture():
    imports = []
    for index in range(27):
        va = n.CELL if index == 26 else '0x%08x' % (0x00402000+4*index)
        dll = n.DLL if index < 8 or index == 26 else 'fixture.dll'
        name = n.NAME if index == 26 else 'Entry%d' % index
        identity = dict(kind='name', name=name)
        imports.append(dict(import_id=13 if index == 26 else 1000+index, original_IAT_va=va,
            dll=dll, export=dict(identity, hint=614 if index == 26 else index), lookup_source='OriginalFirstThunk',
            representation='IAT_POINTER_CELL_NOT_FUNCTION_BODY',
            required_provider_contract=dict(dll=dll, export=identity, runtime_provider_selected=False)))
    plan = dict(kind='fnv-static-import-plan', schema_version=1, imports=imports, summary=dict(imports=27),
                runtime_closure_verified=False, game_fixups_approved=0)
    cells = list(n.projection.catalog(plan).values())
    aliases = [dict(original_IAT_va=c['original_IAT_va'], dll=c['dll'], export=c['export'],
                    canonical_IAT_symbol=c['canonical_IAT_symbol'], proposed_pointer_symbol='__imp__'+c['export']['name'],
                    library='kernel32-eight.lib' if i < 8 else 'other.lib', member_offset=1000+120*i,
                    alias_applied=False, source_ABI_approved=False, runtime_provider_adopted=False)
               for i, c in enumerate(cells[:26])]
    prior = dict(kind='fnv-kernel32-import-extension-request', schema_version=1, cells=cells[:8])
    native = dict(kind='fnv-kernel32-import-extension-native-collection', schema_version=1,
                  native_library_generated=True, all_inputs_tools_sources_stable=True,
                  library=dict(file='kernel32-eight.lib', sha256=n.OLD_LIBRARY_SHA256, bytes=3112),
                  proposed_pointer_aliases=aliases, unchanged_libraries=[{}, {}, {}], **n.FALSE_FLAGS)
    review = dict(kind='fnv-kernel32-extension-independent-native-outcome-review',
                  status='accepted_metadata_conformance_only', collection_sha256=n.PINS['prior_native'],
                  library_sha256=n.OLD_LIBRARY_SHA256)
    canonical = cells[-1]['canonical_IAT_symbol']
    uses = []
    for index, (recipe, root) in enumerate(sorted(n.EXPECTED_CALLERS)):
        uses.append(dict(recipe_id=recipe, root=root, canonical=canonical, undefined=True, kind=6,
            physical_symbol_index=9+index, offset=33+index,
            proof=dict(canonical_name=canonical, kind=6, addend_bits=0, role='iat-cell',
                classification='IAT_POINTER_CELL_NOT_FUNCTION_BODY', import_id=13, original_base=n.CELL,
                original_target=n.CELL, symbol_index=9+index, field_offset=33+index, original_address=root,
                provider_selected=False)))
    ledger = dict(groups=[dict(symbol=canonical, classification='IAT', observed_roles=['iat-cell'],
                  original_bases=[n.CELL], original_targets=[n.CELL], included_input_provenance=uses)])
    assessment = dict(kind='gettickcount-next-import-metadata-assessment', original_IAT_va=n.CELL,
                      canonical_IAT_symbol=canonical, included_use_records=copy.deepcopy(uses))
    return plan, prior, native, review, assessment, ledger


def request_and_parse():
    request, definition = n.prepare(*fixture())
    request.update(inputs=dict(plan_sha256='a'*64), source_sha256=dict(tool='b'*64))
    parsed = dict(both_indexes_agree=True, archive_sha256='c'*64, archive_bytes=4096, ordinary_members=[{}]*3,
        imports=[dict(dll=c['dll'], export=c['export'], machine=0x14c, import_type=0,
            symbol='_'+c['export']['name'], pointer_symbol='__imp__'+c['export']['name'], member_offset=1000+120*i)
            for i, c in enumerate(request['cells'])])
    return request, parsed


class NineTests(unittest.TestCase):
    def test_exact_nine_names_and_two_uses_preserve_old_evidence(self):
        data = fixture(); saved = copy.deepcopy(data)
        request, definition = n.prepare(*data)
        self.assertEqual(data, saved)
        self.assertEqual(len(request['cells']), 9)
        self.assertEqual(len(request['prior_kernel32_aliases']), 8)
        self.assertEqual(len(request['new_cell_included_use_records']), 2)
        self.assertIn(b'    GetTickCount\n', definition)
        self.assertNotIn(b'"GetTickCount"', definition)
        new = next(c for c in request['cells'] if c['import_id'] == 13)
        self.assertEqual(new['original_export_metadata']['hint'], 614)
        self.assertFalse(request['global_caller_census_verified'])
        self.assertFalse(request['included_provenance_is_extraction_proof'])

    def test_wrong_cell_or_dll_identity_rejected(self):
        for key, value in [('import_id', 14), ('dll', 'other.dll')]:
            data = fixture(); data[0]['imports'][-1][key] = value
            with self.assertRaises(ValueError): n.prepare(*data)

    def test_missing_extra_or_nonexact_use_rejected(self):
        for change in ('missing', 'extra', 'addend', 'role', 'index'):
            data = fixture(); group = data[-1]['groups'][0]
            if change == 'missing': group['included_input_provenance'].pop()
            if change == 'extra': group['included_input_provenance'].append(copy.deepcopy(group['included_input_provenance'][0]))
            if change == 'addend': group['included_input_provenance'][0]['proof']['addend_bits'] = 4
            if change == 'role': group['included_input_provenance'][0]['proof']['role'] = 'code'
            if change == 'index': group['included_input_provenance'][0]['physical_symbol_index'] += 1
            with self.subTest(change=change), self.assertRaises(ValueError): n.prepare(*data)

    def test_missing_prior_review_and_pointer_promotion_rejected(self):
        data = fixture(); data[3]['status'] = 'pending'
        with self.assertRaises(ValueError): n.prepare(*data)
        data = fixture(); data[2]['proposed_pointer_aliases'][0]['alias_applied'] = True
        with self.assertRaises(ValueError): n.prepare(*data)

    def test_actual_native_reconcile_preserves_eight_and_binds_27(self):
        request, parsed = request_and_parse()
        result = n.reconcile(request, parsed, 'd'*64)
        self.assertEqual(len(result['proposed_pointer_aliases']), 27)
        self.assertEqual(result['source_sha256'], request['source_sha256'])
        self.assertEqual(result['library']['sha256'], parsed['archive_sha256'])
        self.assertTrue(result['old_eight_pointer_identities_preserved'])
        for key in n.FALSE_FLAGS: self.assertIs(result[key], False)

    def test_changed_prior_pointer_wrong_export_or_bad_archive_rejected(self):
        for change in ('pointer', 'quote', 'machine', 'index', 'missing', 'replacement', 'promotion'):
            request, parsed = request_and_parse()
            if change == 'pointer': parsed['imports'][0].update(symbol='_Wrong', pointer_symbol='__imp__Wrong')
            if change == 'quote': parsed['imports'][0]['export'] = dict(kind='name', name='"GetTickCount"')
            if change == 'machine': parsed['imports'][0]['machine'] = 0x8664
            if change == 'index': parsed['both_indexes_agree'] = False
            if change == 'missing': parsed['imports'].pop()
            if change == 'replacement': request['replacement']['old_import_count'] = 7
            if change == 'promotion': request['prior_other_aliases'][0]['runtime_provider_adopted'] = True
            with self.subTest(change=change), self.assertRaises(ValueError): n.reconcile(request, parsed, 'd'*64)

    def test_outside_private_tree_rejected_before_input_reads(self):
        with tempfile.TemporaryDirectory() as directory:
            args = type('Args', (), dict(out=Path(directory)/'output'))()
            with self.assertRaisesRegex(ValueError, 'private build/rebuild'): n.run(args)

    def test_final_write_drift_removes_only_new_owned_outputs(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory); paths = {k: root/(k+'.json') for k in n.PINS}
            for k, p in paths.items(): p.write_text(json.dumps(dict(parsed_archive=dict(imports=[], index=[]))))
            oldlib = root/'kernel32-eight.lib'; oldlib.write_bytes(b'synthetic library stand-in')
            args = type('Args', (), dict(**paths, out=root/'build/rebuild/new-output', source_sha256=n.sha(n.__file__)))()
            marker = root/'earlier.txt'; marker.write_text('preserve')
            original = json.dump
            def drift(value, stream, **kwargs):
                original(value, stream, **kwargs); paths['plan'].write_text('changed after final write')
            with patch.object(n, 'ROOT', root), patch.object(n, 'HELPER_PINS', {}), \
                    patch.object(n, 'PINS', {k: n.sha(p) for k, p in paths.items()}), \
                    patch.object(n, 'OLD_LIBRARY_SHA256', n.sha(oldlib)), \
                    patch.object(n, 'prepare', return_value=(dict(unchanged_libraries=[]), b'LIBRARY fixture.dll\nEXPORTS\n')), \
                    patch.object(n.archive, 'read_archive', return_value=dict(imports=[], index=[])), \
                    patch.object(n.json, 'dump', side_effect=drift):
                with self.assertRaisesRegex(ValueError, 'source/input changed'): n.run(args)
            self.assertFalse(Path(args.out).exists()); self.assertEqual(marker.read_text(), 'preserve')


if __name__ == '__main__': unittest.main()
