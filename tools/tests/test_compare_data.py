"""Authored synthetic COFF/data graphs and PE memory ranges; no game input or compiler required."""
import struct
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from compare import Pe, check_data, compare, data_definition, own_data


class Object:
    def __init__(self):
        self.sections = [None]
        self.symbols = {}

    def add(self, name, data=b'', flags=0x40000040, section=None, value=0, typ=0):
        if section is None:
            self.sections.append(dict(name='.data', data=data, flags=flags, relocs=[]))
            section = len(self.sections) - 1
        symbol = dict(name=name, section=section, value=value, type=typ, storage=2)
        self.symbols[len(self.symbols)] = symbol
        return symbol

    def named(self, name):
        return next(s for s in self.symbols.values() if s['name'] == name)

    def relocate(self, owner, offset, target, kind=0x06):
        index = next(i for i, s in self.symbols.items() if s is target)
        self.sections[owner['section']]['relocs'].append((owner['value'] + offset, index, kind))


class Image:
    base = 0x00400000

    def __init__(self, regions, tls=0x00500100):
        self.regions = regions
        self.tls = tls

    def read(self, address, size):
        for start, data in self.regions.items():
            if start <= address and address + size <= start + len(data):
                return data[address - start:address - start + size]
        raise ValueError('outside synthetic image')

    read_data = read

    def tls_start(self):
        return self.tls

    def secrel(self, address):
        if not self.tls <= address < self.tls + 0x100:
            raise ValueError('outside synthetic TLS')
        return address - self.tls


def word(value):
    return struct.pack('<I', value & 0xffffffff)


def function_result(obj, target, regions, bindings, kind=0x06, data_names=None):
    # Authored x86 load-and-return, never executed. Its address field is the sole relocation.
    code = obj.add('_read', b'\xa1' + word(0) + b'\xc3', flags=0x60000020, typ=0x20)
    obj.relocate(code, 1, target, kind)
    target_address = bindings[target['name']]
    observed = target_address - 0x00500100 if kind == 0x0B else target_address
    memory = dict(regions)
    memory[0x00401000] = b'\xa1' + word(observed) + b'\xc3'
    unit = dict(functions=[dict(symbol='_read', address='0x00401000', size=6)],
                symbols={name: hex(at) for name, at in bindings.items()})
    return compare(obj, Image(memory), unit, data_names=data_names)[0]


class FullDataComparisonTests(unittest.TestCase):
    def test_all_scalar_bytes_and_zero_initialization_are_checked(self):
        for value, original, bss, match in [(1, 1, False, True), (1, 257, False, False),
                                           (0, 1, True, False), (0, 0, True, True)]:
            with self.subTest(value=value, original=original, bss=bss):
                obj = Object()
                g = obj.add('_g', word(value), flags=0xC0000080 if bss else 0xC0000040)
                row = function_result(obj, g, {0x00500000: word(original)}, {'_g': 0x00500000})
                self.assertEqual(row['verdict'] == 'match', match, row['errors'])

    def test_pointer_target_and_its_pointee_are_checked(self):
        for target_name, original_a, match in [('_a', 1, True), ('_b', 1, False), ('_a', 257, False)]:
            with self.subTest(target=target_name, original_a=original_a):
                obj = Object()
                a = obj.add('_a', word(1)); b = obj.add('_b', word(2)); g = obj.add('_g', word(0))
                obj.relocate(g, 0, a if target_name == '_a' else b)
                row = function_result(obj, g, {0x00500000: word(0x00500010),
                                               0x00500010: word(original_a), 0x00500020: word(2)},
                                      {'_g': 0x00500000, '_a': 0x00500010, '_b': 0x00500020})
                self.assertEqual(row['verdict'] == 'match', match, row['errors'])

    def test_string_behind_a_global_pointer_is_placed_by_content(self):
        for text, match in [(b'before\0', True), (b'after!\0', False)]:
            with self.subTest(text=text):
                obj = Object()
                literal = obj.add('??_C@_06Fixture@', text)
                g = obj.add('_g', word(0)); obj.relocate(g, 0, literal)
                row = function_result(obj, g, {0x00500000: word(0x00500020), 0x00500020: b'before\0'},
                                      {'_g': 0x00500000})
                self.assertEqual(row['verdict'] == 'match', match, row['errors'])

    def test_initializer_addend_and_relocation_kinds(self):
        for kind in (0x06, 0x07, 0x14):
            with self.subTest(kind=kind):
                obj = Object(); a = obj.add('_a', word(1)); g = obj.add('_g', word(1))
                obj.relocate(g, 0, a, kind)
                value = 0x00500011
                if kind == 0x07:
                    value -= Image.base
                elif kind == 0x14:
                    value -= 0x00500000 + 4
                row = function_result(obj, g, {0x00500000: word(value), 0x00500010: word(1)},
                                      {'_g': 0x00500000, '_a': 0x00500010})
                self.assertEqual(row['verdict'], 'match', row['errors'])

    def test_function_callback_initializers_compare_the_function_address(self):
        for original, match in [(0x00402000, True), (0x00402010, False)]:
            obj = Object(); callback = obj.add('_callback', section=0)
            g = obj.add('_g', word(0)); obj.relocate(g, 0, callback)
            row = function_result(obj, g, {0x00500000: word(original)},
                                  {'_g': 0x00500000, '_callback': 0x00402000})
            self.assertEqual(row['verdict'] == 'match', match, row['errors'])

    def test_unresolved_initializer_is_not_inferred_from_the_image(self):
        obj = Object(); missing = obj.add('_missing', section=0)
        g = obj.add('_g', word(0)); obj.relocate(g, 0, missing)
        row = function_result(obj, g, {0x00500000: word(0x00500020)}, {'_g': 0x00500000})
        self.assertEqual(row['verdict'], 'wip')
        self.assertIn('unresolved', ' '.join(row['errors']))

    def test_only_initializer_edges_can_use_global_unambiguous_names(self):
        obj = Object(); callback = obj.add('_callback', section=0)
        g = obj.add('_g', word(0)); obj.relocate(g, 0, callback)
        row = function_result(obj, g, {0x00500000: word(0x00402000)}, {'_g': 0x00500000},
                              data_names={'_callback': 0x00402000, '_g': 0x00509999})
        self.assertEqual(row['verdict'], 'match', row['errors'])
        # Even a global name map cannot supply an absent binding for the function's own relocation.
        obj = Object(); callback = obj.add('_callback', section=0)
        code = obj.add('_read', b'\xa1' + word(0) + b'\xc3', flags=0x60000020, typ=0x20)
        obj.relocate(code, 1, callback)
        unit = dict(functions=[dict(symbol='_read', address='0x00401000', size=6)])
        row = compare(obj, Image({0x00401000: b'\xa1' + word(0x00402000) + b'\xc3'}), unit,
                      data_names={'_callback': 0x00402000})[0]
        self.assertEqual(row['verdict'], 'wip')

    def test_data_cycles_terminate_and_still_check_every_payload(self):
        for original, match in [(1, True), (2, False)]:
            obj = Object(); g = obj.add('_g', word(0) + word(1)); obj.relocate(g, 0, g)
            row = function_result(obj, g, {0x00500000: word(0x00500000) + word(original)}, {'_g': 0x00500000})
            self.assertEqual(row['verdict'] == 'match', match, row['errors'])

    def test_tls_initializers_use_the_tls_address_not_the_secrel_offset(self):
        for original, match in [(1, True), (2, False)]:
            obj = Object(); g = obj.add('_g', word(1))
            row = function_result(obj, g, {0x00500100: word(original)}, {'_g': 0x00500100}, kind=0x0B)
            self.assertEqual(row['verdict'] == 'match', match, row['errors'])

    def test_initializer_can_refer_to_a_tls_offset(self):
        obj = Object(); a = obj.add('_a', word(1)); g = obj.add('_g', word(0))
        obj.relocate(g, 0, a, 0x0B)
        row = function_result(obj, g, {0x00500000: word(0x10), 0x00500110: word(1)},
                              {'_g': 0x00500000, '_a': 0x00500110})
        self.assertEqual(row['verdict'], 'match', row['errors'])

    def test_rtti_name_warning_does_not_hide_pointer_or_header_changes(self):
        name = '??_R0Fixture'
        obj = Object(); g = obj.add(name, word(0) * 2 + b'Name\0')
        row = function_result(obj, g, {0x00500000: word(0) * 2 + b'Other'}, {name: 0x00500000})
        self.assertEqual(row['verdict'], 'match', row['errors'])
        self.assertTrue(row['warnings'])
        obj = Object(); g = obj.add(name, word(0) * 2 + b'Name\0')
        row = function_result(obj, g, {0x00500000: word(0) + word(1) + b'Name\0'}, {name: 0x00500000})
        self.assertEqual(row['verdict'], 'wip')
        obj = Object(); callback = obj.add('_callback', section=0)
        g = obj.add(name, word(0) * 2 + b'Name\0'); obj.relocate(g, 0, callback)
        row = function_result(obj, g, {0x00500000: word(0x00402010) + word(0) + b'Name\0'},
                              {name: 0x00500000, '_callback': 0x00402000})
        self.assertEqual(row['verdict'], 'wip')


class DataDefinitionTests(unittest.TestCase):
    def test_preserves_embedded_and_trailing_literal_nuls(self):
        for name, data in [('??_C@_04Fixture@', b'a\0b\0\0'),
                           ('??_C@_19Fixture@', b'a\0\0\0b\0\0\0\0\0'),
                           ('??_C@_0BB@Fixture@', b'0123456789ABCDEF\0'),
                           ('$SG1', b'a\0b\0\0')]:
            with self.subTest(name=name):
                obj = Object(); literal = obj.add(name, data)
                self.assertEqual(data_definition(obj, literal), (data, []))

    def test_real_literal_has_exact_named_bytes(self):
        obj = Object(); literal = obj.add('__real@3f847ae147ae147b', section=0)
        self.assertEqual(data_definition(obj, literal), (bytes.fromhex('7b14ae47e17a843f'), []))

    def test_symbol_boundaries_and_compatibility_mask_preserve_zeros(self):
        obj = Object(); g = obj.add('_g', word(0) + word(257))
        a = obj.add('_a', section=g['section'], value=4)
        obj.relocate(g, 0, a)
        self.assertEqual(data_definition(obj, g)[0], word(0))
        self.assertEqual(own_data(obj, g), (word(0), set(range(4))))
        self.assertEqual(data_definition(obj, a), (word(257), []))

    def test_rejects_ambiguous_or_unsupported_relocation_geometry(self):
        for offsets, kind in [([0, 2], 0x06), ([2], 0x06), ([8], 0x06), ([0], 0x1234)]:
            with self.subTest(offsets=offsets, kind=kind):
                obj = Object(); target = obj.add('_target', section=0); g = obj.add('_g', word(0))
                for offset in offsets:
                    obj.relocate(g, offset, target, kind)
                with self.assertRaises(ValueError):
                    data_definition(obj, g)
        obj = Object(); target = obj.add('_target', section=0)
        g = obj.add('_g', word(0) * 2); alias = obj.add('_inside', section=g['section'], value=2)
        obj.relocate(g, 0, target)
        with self.assertRaises(ValueError):
            data_definition(obj, alias)

    def test_literal_cannot_hide_a_pointer_initializer(self):
        obj = Object(); target = obj.add('_target', section=0)
        literal = obj.add('$SG1', word(0)); obj.relocate(literal, 0, target)
        with self.assertRaisesRegex(ValueError, 'literal contains initializer relocations'):
            data_definition(obj, literal)

    def test_graph_depth_limit_fails_closed(self):
        obj = Object()
        nodes = [obj.add('_g%d' % i, word(0)) for i in range(130)]
        bindings = {node['name']: 0x00500000 + i * 4 for i, node in enumerate(nodes)}
        regions = {}
        for i, node in enumerate(nodes):
            target = nodes[min(i + 1, len(nodes) - 1)]
            obj.relocate(node, 0, target)
            regions[bindings[node['name']]] = word(bindings[target['name']])
        errors, _ = check_data(obj, Image(regions), nodes[0], bindings[nodes[0]['name']],
                               lambda target, addend: bindings[target['name']] + addend)
        self.assertIn('verification limit', ' '.join(errors))


class PeDataReadTests(unittest.TestCase):
    def test_zero_fill_is_available_only_to_data_reads_inside_a_section(self):
        image = Pe.__new__(Pe)
        image.base = 0x00400000
        image.data = b'AB'
        image.sections = [(0x1000, 6, 2, 0), (0x2000, 4, 0, 2)]
        self.assertEqual(image.read_data(0x00401000, 6), b'AB' + bytes(4))
        self.assertEqual(image.read_data(0x00402000, 4), bytes(4))
        for at, size in [(0x00401002, 1), (0x00402000, 1)]:
            with self.assertRaises(ValueError):
                image.read(at, size)
        for at, size in [(0x00401005, 2), (0x00403000, 1), (0x00401000, -1)]:
            with self.assertRaises(ValueError):
                image.read_data(at, size)


if __name__ == '__main__':
    unittest.main()
