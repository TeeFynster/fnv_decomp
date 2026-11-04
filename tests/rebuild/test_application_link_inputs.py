"""Original synthetic metadata only; no native tools or actual projection."""
import copy
import json
from pathlib import Path
import struct
import sys
import tempfile
import unittest
from unittest import mock

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tools/rebuild'))
import application_link_inputs as link


def obj(symbols, relocations=(), executable=True):
    strings = bytearray(b'\0\0\0\0')
    table = bytearray()
    for name, section, typ, value in symbols:
        offset = len(strings); strings.extend(name.encode() + b'\0')
        table.extend(struct.pack('<IIIhHBB', 0, offset, value, section, typ, 2, 0))
    struct.pack_into('<I', strings, 0, len(strings))
    payload = bytes(128)
    relocs = b''.join(struct.pack('<IIH', *row) for row in relocations)
    header = struct.pack('<HHIIIHH', 0x14c, 1, 0, 60 + len(payload) + len(relocs), len(symbols), 0, 0)
    section = struct.pack('<8sIIIIIIHHI', b'.text' if executable else b'.rdata', 0, 0,
        len(payload), 60, 60 + len(payload) if relocs else 0, 0, len(relocations), 0,
        0x60500020 if executable else 0x40000040)
    return header + section + payload + relocs + table + strings


def host_fixture():
    return obj([('_WinMain@16', 1, 32, 0), (link.TYPED, 0, 32, 0)], [(4, 1, 20)])


def short_archive():
    name, dll = '_Example', 'EXAMPLE.dll'
    body_strings = (name + '\0' + dll + '\0').encode()
    body = struct.pack('<HHHHIIHH', 0, 0xffff, 0, 0x14c, 0, len(body_strings), 0, 8) + body_strings
    names = [name, '__imp_' + name]
    strings = b''.join(n.encode() + b'\0' for n in names)
    first_size, second_size = 12 + len(strings), 16 + len(strings)
    offset = 8 + 60 + first_size + first_size % 2 + 60 + second_size + second_size % 2
    first = struct.pack('>III', 2, offset, offset) + strings
    second = struct.pack('<IIIHH', 1, offset, 2, 1, 1) + strings
    def member(n, payload):
        header = f'{n:<16}{0:<12}{0:<6}{0:<6}{0:<8}{len(payload):<10}`\n'.encode()
        return header + payload + (b'\n' if len(payload) % 2 else b'')
    return b'!<arch>\n' + member('/', first) + member('/', second) + member('EXAMPLE.dll/', body)


class ApplicationLinkInputTests(unittest.TestCase):
    def test_host_binding_is_one_physical_name_change(self):
        source = host_fixture()
        target = obj([(link.CANONICAL, 1, 32, 0)])
        output, proof = link.bind_host(source, target)
        before, after = link.standard_metadata(source), link.standard_metadata(output)
        self.assertEqual(before['sections'], after['sections'])
        self.assertEqual(after['symbols'][1]['name'], link.CANONICAL)
        self.assertEqual(proof['physical_symbol_index'], 1)
        self.assertFalse(proof['ABI_conversion_performed'])
        self.assertEqual(source, host_fixture())

    def test_host_wrong_type_extra_reference_and_non_REL32_fail(self):
        target = obj([(link.CANONICAL, 1, 32, 0)])
        cases = [obj([('_WinMain@16', 1, 32, 0), (link.TYPED, 0, 0, 0)], [(4, 1, 20)]),
            obj([('_WinMain@16', 1, 32, 0), (link.TYPED, 0, 32, 0)], [(4, 1, 6)]),
            obj([('_WinMain@16', 1, 32, 0), (link.TYPED, 0, 32, 0)], [(4, 1, 20), (8, 1, 20)]),
            obj([('_WinMain@16', 1, 32, 0), (link.TYPED, 0, 32, 0), ('extra', 0, 0, 0)], [(4, 1, 20)])]
        for case in cases:
            with self.subTest(case=link.digest(case)), self.assertRaises(ValueError):
                link.bind_host(case, target)

    def test_wrong_entry_export_fails(self):
        with self.assertRaisesRegex(ValueError, 'entry export'):
            link.bind_host(host_fixture(), obj([('other', 1, 32, 0)]))

    def test_selected_duplicate_definitions_fail_even_equal_payloads(self):
        meta = link.standard_metadata(obj([('same', 1, 32, 0)]))
        with self.assertRaisesRegex(ValueError, 'duplicate/conflicting'):
            link.unique_definitions([('one', meta), ('two', meta)])

    def test_namespace_intersection_is_independent_of_library_order(self):
        for definitions, imports, support in [({'same': {}}, {'same'}, {}),
            ({}, {'same'}, {'same': [{}]}), ({'same': {}}, set(), {'same': [{}]})]:
            with self.assertRaisesRegex(ValueError, 'namespace conflict'):
                link.namespace_intersection(definitions, imports, support)
        link.namespace_intersection({}, set(), {'__NULL_IMPORT_DESCRIPTOR': [{}, {}, {}, {}]})

    def test_weak_or_common_provider_not_silently_selected(self):
        meta = link.standard_metadata(obj([('common', 0, 0, 4)]))
        with self.assertRaisesRegex(ValueError, 'weak/common'):
            link.externals(meta)

    def test_native_short_import_requires_both_indices_and_pointer_identity(self):
        data = short_archive()
        native = link.native_archive(data)
        self.assertTrue(native['both_indexes_agree'])
        self.assertEqual(native['imports'][0]['pointer_symbol'], '__imp__Example')
        self.assertEqual(native['imports'][0]['export'], dict(kind='name', name='Example'))
        self.assertEqual(native['support_members'], [])
        changed = data.replace(b'__imp__Example', b'__bad__Example', 1)
        with self.assertRaises(ValueError):
            link.native_archive(changed)

    def test_native_bad_member_extent_and_unsupported_name_type_fail(self):
        data = short_archive()
        native = link.native_archive(data)
        off = native['imports'][0]['member_offset']
        for changed in [data[:-1], data[:off + 60 + 18] + b'\x04\0' + data[off + 60 + 20:]]:
            with self.assertRaises(ValueError):
                link.native_archive(changed)

    def test_collection_index_order_normalization_preserves_cardinality_and_members(self):
        native = link.native_archive(short_archive())
        rows = native['first_index']
        self.assertEqual(link.index_multiset(rows), link.index_multiset(list(reversed(rows))))
        self.assertEqual(link.index_multiset(rows), link.index_multiset(native['index']))
        self.assertNotEqual(link.index_multiset(rows), link.index_multiset(rows + [rows[0]]))
        changed = copy.deepcopy(rows); changed[0]['member_offset'] += 2
        self.assertNotEqual(link.index_multiset(rows), link.index_multiset(changed))
        self.assertEqual(len(native['first_index']), len(native['index']))
        with self.assertRaises(ValueError):
            link.index_multiset([dict(symbol='x', member_offset=True)])

    def field_fixture(self):
        entry = link.standard_metadata(obj([('target', 0, 0, 0)], [(4, 0, 6)]))
        projection = dict(mapping=dict(section_map={'199': 1}, symbol_map={'28': 0}),
            fields=[dict(original_section=199, offset=4, physical_symbol_index=28,
                         serialized_symbol_index=0, kind=6, addend_bits=0)],
            original_field_obligations=[dict(section=199, offset=4, symbol_index=28,
                kind=6, addend_bits=0, original_base='0x01000000', original_target='0x01000000', role='data')])
        return entry, projection

    def test_field_join_preserves_physical_and_serialized_indices(self):
        entry, projection = self.field_fixture()
        fields = link.join_fields(entry, projection)
        self.assertEqual(fields[0]['physical_symbol_index'], 28)
        self.assertEqual(fields[0]['symbol_index'], 0)
        self.assertEqual(fields[0]['symbol'], 'target')
        self.assertEqual(fields[0]['section'], 1)

    def test_field_join_rejects_missing_changed_index_and_addend(self):
        for mutate in [lambda p: p['fields'].clear(),
            lambda p: p['mapping']['symbol_map'].update({'28': 1}),
            lambda p: p['original_field_obligations'][0].update(addend_bits=4)]:
            entry, projection = self.field_fixture(); mutate(projection)
            with self.assertRaises(ValueError):
                link.join_fields(entry, projection)

    def test_duplicate_fields_cannot_hide_an_unvisited_actual_relocation(self):
        entry, projection = self.field_fixture()
        entry['sections'][1]['relocs'].append((8, 0, 6))
        projection['fields'].append(copy.deepcopy(projection['fields'][0]))
        second = copy.deepcopy(projection['original_field_obligations'][0]); second['offset'] = 8
        projection['original_field_obligations'].append(second)
        with self.assertRaisesRegex(ValueError, 'bijection'):
            link.join_fields(entry, projection)

    def data_fixture(self):
        objects, aliases, fields, entry_symbols = [], [], [], {}
        for number in range(2):
            names = ['data' + str(number * 8 + n) for n in range(8)]
            data = obj([(name, 1, 0, n) for n, name in enumerate(names)], executable=False)
            objects.append(data)
            for n, name in enumerate(names):
                index = number * 8 + n
                offsets = [index * 4] + ([64 + index * 4] if index < 4 else [])
                alias = dict(symbol=name, object_sha256=link.digest(data), physical_symbol_index=n,
                    section=1, section_offset=n, original_base=f'0x{0x1000000 + index:08x}', entry_source_records=[])
                entry_symbols[index] = dict(section=0)
                for offset in offsets:
                    alias['entry_source_records'].append(dict(recipe_id=link.IDENTITY['recipe_id'],
                        addend=0, original_symbol_index=index + 100, field_offset=offset))
                    fields.append(dict(offset=offset, physical_symbol_index=index + 100,
                        symbol_index=index, symbol=name, role='data', kind=6, original_base=alias['original_base']))
                aliases.append(alias)
        return objects, dict(aliases=aliases), dict(symbols=entry_symbols), fields

    def test_sixteen_data_aliases_cover_exact_twenty_entry_fields(self):
        args = self.data_fixture()
        self.assertEqual(len(link.data_coverage(*args)), 20)
        changed = copy.deepcopy(args)
        changed[1]['aliases'][0]['entry_source_records'][0]['addend'] = 4
        with self.assertRaises(ValueError):
            link.data_coverage(*changed)

    def test_data_alias_missing_or_shifted_physical_definition_fails(self):
        args = self.data_fixture()
        args[1]['aliases'][0]['section_offset'] += 1
        with self.assertRaises(ValueError):
            link.data_coverage(*args)

    def import_fixture(self):
        proposals, cells, imports, fields = [], [], [], []
        for number in range(25):
            canonical, pointer = 'iat' + str(number), '__imp__Example' + str(number)
            va, export = f'0x{0x2000000 + number * 4:08x}', dict(kind='name', name='Example' + str(number))
            cells.append(dict(canonical_IAT_symbol=canonical, original_IAT_va=va, dll='EXAMPLE.dll', export=export))
            proposals.append(dict(canonical_IAT_symbol=canonical, proposed_pointer_symbol=pointer,
                original_IAT_va=va, dll='EXAMPLE.dll', export=export, library='provider.lib',
                member_offset=number, alias_applied=False, runtime_provider_adopted=False,
                source_ABI_approved=False, pointer_indirection_preserved=True))
            imports.append(dict(member_offset=number, pointer_symbol=pointer, dll='EXAMPLE.dll', export=export))
            for offset in [number * 4] + ([100 + number * 4] if number < 5 else []):
                fields.append(dict(offset=offset, symbol=canonical, role='iat-cell', kind=6, original_target=va))
        return dict(proposed_pointer_aliases=proposals), dict(selected_cells=cells), \
            {'provider.lib': dict(imports=imports)}, fields

    def test_actual_export_identity_keeps_twenty_five_proposals_unapplied(self):
        result = link.import_proposals(*self.import_fixture())
        self.assertEqual(len(result), 25)
        self.assertEqual(sum(len(r['entry_fields']) for r in result), 30)
        self.assertTrue(all(r['applied'] is False and r['source_ABI_approved'] is False for r in result))

    def test_import_code_pointer_export_and_field_identity_mismatches_fail(self):
        for mutate in [lambda a: a[0]['proposed_pointer_aliases'][0].update(proposed_pointer_symbol='_Example0'),
            lambda a: a[0]['proposed_pointer_aliases'][0].update(alias_applied=True),
            lambda a: a[2]['provider.lib']['imports'][0].update(dll='OTHER.dll'),
            lambda a: a[3][0].update(kind=20),
            lambda a: a[0]['proposed_pointer_aliases'].pop()]:
            args = self.import_fixture(); mutate(args)
            with self.assertRaises(ValueError):
                link.import_proposals(*args)
        args = self.data_fixture(); args[1]['aliases'].pop()
        with self.assertRaises(ValueError):
            link.data_coverage(*args)

    def test_no_output_on_stale_input_or_public_destination(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            with self.assertRaisesRegex(ValueError, 'private'):
                link.run(root / 'public', '0' * 64, root)
            self.assertFalse((root / 'public').exists())
            (root / 'tools/rebuild').mkdir(parents=True)
            (root / 'tools/rebuild/coff_code_archive.py').write_text('changed')
            with self.assertRaisesRegex(ValueError, 'source/dependency'):
                link.run(root / 'build/rebuild/out', '0' * 64, root)
            self.assertFalse((root / 'build/rebuild/out').exists())

    def test_source_and_all_imported_dependencies_bound_before_assembly(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            for name in list(link.SOURCE_PINS) + ['tools/rebuild/application_link_inputs.py']:
                path = root / name; path.parent.mkdir(parents=True, exist_ok=True)
                path.write_bytes((ROOT / name).read_bytes())
            expected = link.digest((ROOT / 'tools/rebuild/application_link_inputs.py').read_bytes())
            self.assertEqual(link.reviewed_sources(root, expected)['tools/rebuild/game_startup_host.py'],
                link.SOURCE_PINS['tools/rebuild/game_startup_host.py'])
            for name in list(link.SOURCE_PINS) + ['tools/rebuild/application_link_inputs.py']:
                path = root / name; original = path.read_bytes(); path.write_bytes(b'changed')
                with mock.patch.object(link, 'assemble') as assemble, \
                        self.assertRaisesRegex(ValueError, 'source/dependency'):
                    link.run(root / 'build/rebuild/out', expected, root)
                assemble.assert_not_called(); path.write_bytes(original)


if __name__ == '__main__':
    unittest.main()
