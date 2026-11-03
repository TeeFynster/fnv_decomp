"""Independent authored parent-EH fixtures; no game inputs or native processes."""
from pathlib import Path
import struct
import sys
import unittest

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tools/rebuild'))
sys.path.insert(0, str(ROOT / 'tools'))
from test_eh_code_closure import fixture as original_fixture, encode
import build_and_match as oracle


PARENT = '0x10000000'
SYMBOL = '?Construct@AuthoredSecondParent@@QAEXXZ'


def authored_parent(*, noncontiguous=True, object_edit=None):
    """Return a second parent whose cleanup need not adjoin its handler.

    All payloads derive from an original synthetic fixture. This helper does
    not call an adapter and does not assert any actual-game proof or approval.
    """
    obj, _, _, _, _ = original_fixture()
    for sn in range(7, 16):
        obj['sections'][sn]['flags'] = 0x40400040
    code = bytearray(obj['sections'][4]['payload'])
    for offset, opcode in ((3, 0xe8), (20, 0xe8), (25, 0xb8), (30, 0xe9)):
        code[offset] = opcode
    obj['sections'][4]['payload'] = bytes(code)
    syms = obj['symbols']
    syms[8]['name'] = SYMBOL
    for index, prefix in ((12, '__unwindfunclet$'), (19, '__ehhandler$'),
                          (24, '__ehfuncinfo$'), (25, '__unwindtable$')):
        syms[index]['name'] = prefix + SYMBOL + ('$0' if index == 12 else '')
    externals = {9: 0x10010000, 13: 0x10011000, 16: 0x30010000,
                 17: 0x10012000, 18: 0x30011000, 20: 0x10013000,
                 21: 0x10014000}
    for index in (9, 13, 16, 17):
        syms[index]['name'] = '_authored_external_' + str(index)
    if object_edit is not None:
        object_edit(obj)
    cleanup = 0x20000000
    handler = 0x20001000 if noncontiguous else cleanup + 8
    metadata = 0x30000000
    intervals = [(3, 0, 101, int(PARENT, 16)),
                 (4, 0, 8, cleanup), (4, 8, 35, handler),
                 (6, 0, len(obj['sections'][6]['payload']), metadata)]

    def original_address(section, value):
        found = [at + value - start for sn, start, end, at in intervals
                 if sn == section and start <= value < end]
        if len(found) != 1:
            raise ValueError('authored native address outside unique piece')
        return found[0]

    chunks = {}
    highlow = set()
    for sn, start, end, at in intervals:
        payload = bytearray(obj['sections'][sn]['payload'][start:end])
        for offset, index, kind in obj['sections'][sn]['relocs']:
            if not start <= offset < end:
                continue
            if offset + 4 > end:
                raise ValueError('authored relocation crosses piece')
            target = syms[index]
            base = externals.get(index)
            if base is None:
                base = original_address(target['section'], target['value'])
            local = offset - start
            addend = struct.unpack_from('<i' if kind == 20 else '<I', payload, local)[0]
            actual = base + addend
            if kind == 20:
                actual -= at + local + 4
            elif kind == 6:
                highlow.add(at + local)
            else:
                raise ValueError('unsupported authored relocation')
            struct.pack_into('<I', payload, local, actual & 0xffffffff)
        chunks[at] = bytes(payload)

    class Reference:
        def read(self, address, size):
            if type(address) is not int or type(size) is not int or size < 0:
                raise ValueError('invalid authored reference extent')
            found = [data[address-base:address-base+size]
                     for base, data in chunks.items()
                     if base <= address and address + size <= base + len(data)]
            if len(found) != 1:
                raise ValueError('authored reference outside unique finite span')
            return found[0]

    recipe = dict(functions=[dict(address=PARENT, symbol=SYMBOL, size=101)],
                  symbols={syms[i]['name']: hex(at) for i, at in externals.items()})
    recipe['symbols'][syms[19]['name']] = hex(handler)
    expected_pieces = [[cleanup, cleanup + 8, True, PARENT, []],
                       [handler, handler + 27, True, PARENT, []]]
    return dict(obj=obj, raw=encode(obj), reference=Reference(), recipe=recipe,
                expected_pieces=expected_pieces, highlow=sorted(highlow),
                native_intervals=intervals,
                executable_ranges=[(0x10000000, 0x10020000),
                                   (0x20000000, 0x20002000)],
                externals=externals)


class AuthoredParentReferenceTests(unittest.TestCase):
    def compare_fixture(self, noncontiguous):
        from tempfile import TemporaryDirectory
        fixture = authored_parent(noncontiguous=noncontiguous)
        with TemporaryDirectory(prefix='authored-second-parent-') as folder:
            path = Path(folder) / 'authored.obj'
            path.write_bytes(fixture['raw'])
            coff = oracle.Coff(path)
            rows = oracle.compare(coff, fixture['reference'], fixture['recipe'], None)
            self.assertEqual([row['verdict'] for row in rows], ['match'])
            pieces, inferred, errors = oracle.eh_sections(
                coff, fixture['reference'], fixture['recipe'], rows, {})
        self.assertEqual(pieces, fixture['expected_pieces'])
        self.assertEqual(inferred, {})
        self.assertEqual(errors, [])
        self.assertEqual(len(fixture['highlow']), 6)
        return fixture

    def test_second_parent_contiguous_fixture_matches_unchanged_oracle(self):
        self.compare_fixture(False)

    def test_second_parent_noncontiguous_fixture_matches_unchanged_oracle(self):
        fixture = self.compare_fixture(True)
        a, b = fixture['expected_pieces']
        self.assertGreater(b[0], a[1])

    def test_reference_rejects_the_unmapped_gap_between_pieces(self):
        fixture = authored_parent(noncontiguous=True)
        with self.assertRaises(ValueError):
            fixture['reference'].read(0x20000008, 1)

    def test_failed_piece_can_have_no_textual_error(self):
        from tempfile import TemporaryDirectory
        fixture = authored_parent(noncontiguous=True)
        clean = fixture['reference']

        class ChangedCleanup:
            def read(self, address, size):
                data = bytearray(clean.read(address, size))
                if address <= 0x20000000 < address + size:
                    data[0x20000000 - address] ^= 1
                return bytes(data)

        reference = ChangedCleanup()
        with TemporaryDirectory(prefix='authored-failed-cleanup-') as folder:
            path = Path(folder) / 'authored.obj'
            path.write_bytes(fixture['raw'])
            coff = oracle.Coff(path)
            rows = oracle.compare(coff, reference, fixture['recipe'], None)
            self.assertEqual([row['verdict'] for row in rows], ['match'])
            pieces, _, errors = oracle.eh_sections(
                coff, reference, fixture['recipe'], rows, {})
        self.assertEqual([piece[2] for piece in pieces], [False, True])
        self.assertEqual(errors, [])


class ParentEHAdapterAdversarialTests(unittest.TestCase):
    def case(self, **kwargs):
        from test_parent_eh_adapter import valid_case
        return valid_case(**kwargs)

    def observe(self, case):
        import parent_eh_adapter
        return parent_eh_adapter.observe_parent(**case)

    def blocked(self, case):
        result = self.observe(case)
        self.assertFalse(result['structural_projection_candidate'], result)
        for key in ('runtime_eligible', 'provider_selected', 'ABI_verified', 'link_ready'):
            self.assertIs(result[key], False)
        return result

    def test_saved_unit_failure_and_errors_are_not_fresh_proof(self):
        for mutation in ('status', 'errors', 'parent_missing', 'parent_mismatch'):
            with self.subTest(mutation=mutation):
                case = self.case()
                proof = case['unit_proof']
                if mutation == 'status':
                    proof['status'] = 'mismatch'
                elif mutation == 'errors':
                    proof['eh_errors'] = ['saved independent EH mismatch']
                elif mutation == 'parent_missing':
                    proof['verified_functions'] = []
                else:
                    proof['verified_functions'][0]['verdict'] = 'mismatch'
                self.blocked(case)

    def test_recipe_provenance_cannot_name_another_unit(self):
        for mutation in ('recipe_id', 'recipe_index'):
            with self.subTest(mutation=mutation):
                case = self.case()
                if mutation == 'recipe_id':
                    case['contract']['provenance']['recipe_id'] = 'foreign-unit'
                else:
                    case['unit_proof']['recipe_index'] += 1
                self.blocked(case)

    def test_all_owned_code_spans_and_metadata_have_distinct_domains(self):
        for mutation in ('parent_not_executable', 'EH_not_executable', 'metadata_executable'):
            with self.subTest(mutation=mutation):
                case = self.case()
                if mutation == 'parent_not_executable':
                    case['executable_ranges'] = [(0x10010000, 0x10020000),
                                                 (0x20000000, 0x20002000)]
                elif mutation == 'EH_not_executable':
                    case['executable_ranges'] = [(0x10000000, 0x10020000)]
                else:
                    case['executable_ranges'].append((0x30000000, 0x3000002c))
                self.blocked(case)

    def test_foreign_association_and_handler_storage_fail_closed(self):
        for mutation in ('association', 'storage', 'offset'):
            with self.subTest(mutation=mutation):
                def edit(obj):
                    if mutation == 'association':
                        aux = bytearray(obj['symbols'][10]['aux'])
                        struct.pack_into('<h', aux, 12, 17)
                        obj['symbols'][10]['aux'] = bytes(aux)
                    elif mutation == 'storage':
                        obj['symbols'][19]['storage'] = 2
                    else:
                        obj['symbols'][19]['value'] = 9
                self.blocked(self.case(object_edit=edit))

    def test_CRT_function_records_cannot_be_static_undefined(self):
        for index in (20, 21):
            with self.subTest(index=index):
                def edit(obj):
                    obj['symbols'][index]['storage'] = 3
                self.blocked(self.case(object_edit=edit))

    def test_cookie_type_and_handler_tail_opcodes_are_mandatory(self):
        for mutation in ('cookie_type', 'call', 'mov', 'jmp'):
            with self.subTest(mutation=mutation):
                def edit(obj):
                    if mutation == 'cookie_type':
                        obj['symbols'][18]['type'] = 32
                    else:
                        data = bytearray(obj['sections'][4]['payload'])
                        data[{'call': 20, 'mov': 25, 'jmp': 30}[mutation]] = 0x90
                        obj['sections'][4]['payload'] = bytes(data)
                self.blocked(self.case(object_edit=edit))

    @staticmethod
    def sx_edit(obj, entries):
        payload = struct.pack('<' + 'I' * len(entries), *entries)
        obj['sections'][16].update(size=len(payload), payload=payload)
        aux = bytearray(obj['symbols'][64]['aux'])
        struct.pack_into('<I', aux, 0, len(payload))
        obj['symbols'][64]['aux'] = bytes(aux)

    def test_complete_safeSEH_census_allows_only_unreachable_other_records(self):
        def edit(obj):
            self.sx_edit(obj, [19, 68])
        result = self.observe(self.case(object_edit=edit))
        self.assertTrue(result['structural_projection_candidate'], result)
        self.assertEqual([row['retain'] for row in result['safeseh_records']], [True, False])
        self.assertFalse(result['omission_approved'])

    def test_safeSEH_missing_duplicate_aux_and_retained_section_indices_block(self):
        for entries in ([68], [19, 19], [19, 11], [19, 12], [19, 99999]):
            with self.subTest(entries=entries):
                def edit(obj):
                    self.sx_edit(obj, entries)
                self.blocked(self.case(object_edit=edit))

    def test_safeSEH_omitted_name_alias_cannot_become_live(self):
        def edit(obj):
            self.sx_edit(obj, [19, 68])
            obj['symbols'][68]['name'] = obj['symbols'][9]['name']
        self.blocked(self.case(object_edit=edit))

    def test_catch_IP_exception_spec_and_state_metadata_are_exhaustive(self):
        for offset, value in ((8, 0x19930521), (12, 65), (20, 1), (24, 1),
                              (28, 1), (32, 1), (36, 1), (40, 0), (0, 0)):
            with self.subTest(offset=offset, value=value):
                def edit(obj):
                    data = bytearray(obj['sections'][6]['payload'])
                    struct.pack_into('<I', data, offset, value)
                    obj['sections'][6]['payload'] = bytes(data)
                self.blocked(self.case(object_edit=edit))

    def test_native_piece_census_rejects_missing_duplicate_foreign_and_overlap(self):
        for mutation in ('missing', 'duplicate', 'foreign', 'overlap'):
            with self.subTest(mutation=mutation):
                case = self.case()
                pieces = case['contract']['parent_eh']
                if mutation == 'missing':
                    pieces.pop()
                elif mutation == 'duplicate':
                    pieces.append(list(pieces[0]))
                elif mutation == 'foreign':
                    pieces[0][3] = '0x12345678'
                else:
                    pieces[1][0] = pieces[0][0] + 4
                    pieces[1][1] = pieces[1][0] + 27
                self.blocked(case)

    def test_fresh_false_piece_without_errors_blocks_semantics(self):
        case = self.case()
        clean = case['reference']

        class ChangedCleanup:
            def read(self, address, size):
                data = bytearray(clean.read(address, size))
                if address <= 0x20000000 < address + size:
                    data[0x20000000 - address] ^= 1
                return bytes(data)

        case['reference'] = ChangedCleanup()
        result = self.blocked(case)
        self.assertEqual(result['blockers'][0]['code'], 'UNCHANGED_EH_CORE_FAILED')

    def test_other_special_parent_classes_do_not_receive_an_EH_waiver(self):
        for classification in ('TLS_LOCAL_CODE_REFERENCE', 'UNSUPPORTED_LOCAL_REFERENCE',
                               'SECTION_INDEX_LOCAL_REFERENCE', 'IMAGE_RELATIVE_LOCAL_REFERENCE'):
            with self.subTest(classification=classification):
                case = self.case()
                handler_field = next(row for row in case['contract']['fields']
                                     if row['coff_relocation']['symbol_index'] == 19)
                handler_field['classification'] = classification
                self.blocked(case)

    def test_huge_omitted_BSS_is_rejected_before_oracle_allocation(self):
        from unittest.mock import patch
        import parent_eh_adapter
        case = self.case()
        raw = bytearray(case['raw'])
        header = 20 + (7 - 1) * 40
        raw[header:header+8] = b'.bss\0\0\0\0'
        struct.pack_into('<I', raw, header + 16, 0x7fffffff)
        struct.pack_into('<I', raw, header + 20, 0)
        struct.pack_into('<I', raw, header + 36, 0xc0300080)
        case['raw'] = bytes(raw)
        digest = parent_eh_adapter.sha(case['raw'])
        case['unit_proof']['object_sha256'] = digest
        case['contract']['provenance']['object_sha256'] = digest
        with patch('parent_eh_adapter.oracle.Coff',
                   side_effect=AssertionError('unsafe oracle allocation reached')) as mocked:
            self.blocked(case)
        mocked.assert_not_called()


if __name__ == '__main__':
    unittest.main()
