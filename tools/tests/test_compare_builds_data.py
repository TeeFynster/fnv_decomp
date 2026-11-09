"""Behavioral checks for data reached through code relocation fingerprints.

The fixtures represent small COFF objects, not game data. Only COFF loading is
replaced: fingerprinting and data-definition interpretation are the real tools.
"""

from pathlib import Path
import struct
import sys
import unittest
from unittest.mock import patch


sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
import compare_builds  # noqa: E402


CODE = 0x60000020
DATA = 0xC0000040
BSS = 0xC0000080
DIR32 = 0x06
SECREL = 0x0B
FUNCTION_ADDRESS = "0x00401000"
DATA_ADDRESS = 0x00500000


def words(*values):
    return struct.pack("<" + "I" * len(values), *values)


class SyntheticCoff:
    def __init__(self):
        self.sections = [None]
        self.symbols = {}
        self.by_name = {}
        self.indices = {}

    def section(self, name, data, flags=DATA):
        self.sections.append({"name": name, "data": bytes(data), "flags": flags, "relocs": []})
        return len(self.sections) - 1

    def symbol(self, name, section, value=0, typ=0):
        index = len(self.symbols)
        symbol = {"name": name, "section": section, "value": value, "type": typ, "storage": 2}
        self.symbols[index] = symbol
        self.by_name.setdefault(name, []).append(symbol)
        self.indices[name] = index
        return index

    def object(self, name, data, section_name=".data", flags=DATA):
        section = self.section(section_name, data, flags)
        self.symbol(name, section)
        return section

    def alias(self, name, original):
        symbol = self.symbols[self.indices[original]]
        self.symbol(name, symbol["section"], symbol["value"], symbol["type"])

    def relocate(self, section, offset, target, kind=DIR32):
        self.sections[section]["relocs"].append((offset, self.indices[target], kind))

    def named(self, name):
        candidates = [symbol for symbol in self.by_name.get(name, []) if symbol["section"] > 0]
        if len(candidates) != 1:
            raise ValueError("expected one defined symbol: " + name)
        return candidates[0]

    def fingerprint(self, target, bindings, kind=DIR32, addend=0):
        # A minimal caller whose only dependency is target + addend.
        code = self.section(".text", b"\xa1" + words(addend) + b"\xc3", CODE)
        self.symbol("_read", code, typ=0x20)
        self.relocate(code, 1, target, kind)
        unit = {
            "source": "src/synthetic.cpp",
            "functions": [{"address": FUNCTION_ADDRESS, "symbol": "_read", "size": 6}],
            "symbols": {name: hex(address) for name, address in bindings.items()},
        }
        with patch.object(compare_builds, "Coff", return_value=self):
            return compare_builds.fingerprint("unused-synthetic.obj", unit, {})[FUNCTION_ADDRESS]


def bound_scalar(value, name="_answer", section_name=".data", flags=DATA):
    coff = SyntheticCoff()
    coff.object(name, words(value), section_name, flags)
    return coff.fingerprint(name, {name: DATA_ADDRESS})


def pointer_to_equal_objects(selected):
    coff = SyntheticCoff()
    pointer = coff.object("_pointer", words(0))
    coff.object("_left", words(7))
    coff.object("_right", words(7))
    coff.relocate(pointer, 0, selected)
    return coff.fingerprint("_pointer", {
        "_pointer": DATA_ADDRESS,
        "_left": DATA_ADDRESS + 0x100,
        "_right": DATA_ADDRESS + 0x200,
    })


def nested_literal(text, label="$SG1"):
    coff = SyntheticCoff()
    root = coff.object("_root", words(0))
    record = coff.object("_record", words(0))
    coff.object(label, text, ".rdata")
    coff.relocate(root, 0, "_record")
    coff.relocate(record, 0, label)
    return coff.fingerprint("_root", {"_root": DATA_ADDRESS, "_record": DATA_ADDRESS + 0x100})


def array_pointer(index, array_name="_array", values=(11, 22, 33)):
    coff = SyntheticCoff()
    pointer = coff.object("_pointer", words(index * 4))
    coff.object(array_name, words(*values))
    coff.relocate(pointer, 0, array_name)
    return coff.fingerprint("_pointer", {"_pointer": DATA_ADDRESS, array_name: DATA_ADDRESS + 0x100})


def cycle(length, last_value=9, renamed=False, extra_section=False, self_alias=False):
    coff = SyntheticCoff()
    if extra_section:
        coff.object("_unreferenced", words(123))
    names = [("_renamed_node_" if renamed else "_node_") + str(index) for index in range(length)]
    sections = [coff.object(name, words(0, last_value if index == length - 1 else 3))
                for index, name in enumerate(names)]
    bindings = {name: DATA_ADDRESS + index * 0x100 for index, name in enumerate(names)}
    for index, section in enumerate(sections):
        target = names[(index + 1) % length]
        if self_alias:
            alias = target + "_alias"
            coff.alias(alias, target)
            bindings[alias] = bindings[target]
            target = alias
        coff.relocate(section, 0, target)
    return coff.fingerprint(names[0], bindings)


class DataGraphFingerprintTests(unittest.TestCase):
    def assertSameMeaning(self, before, after):
        self.assertEqual(before[0], after[0], "equivalent linked code/data must have the same fingerprint")

    def assertDifferentMeaning(self, before, after):
        self.assertNotEqual(before[0], after[0], "a changed initializer dependency must affect the fingerprint")

    def test_bound_pointer_retarget_cannot_hide_behind_equal_pointee_bytes(self):
        self.assertDifferentMeaning(pointer_to_equal_objects("_left"), pointer_to_equal_objects("_right"))

    def test_nested_string_change_reaches_the_callers_fingerprint(self):
        self.assertDifferentMeaning(nested_literal(b"first\0"), nested_literal(b"other\0"))

    def test_equal_nested_literal_keeps_its_meaning_when_its_label_changes(self):
        self.assertSameMeaning(nested_literal(b"first\0", "$SG1"), nested_literal(b"first\0", "$SG42"))

    def test_array_element_pointer_addend_is_part_of_the_meaning(self):
        self.assertDifferentMeaning(array_pointer(1), array_pointer(2))

    def test_array_pointer_rename_preserves_the_addend(self):
        self.assertSameMeaning(array_pointer(1), array_pointer(1, "_renamed_array"))

    def test_array_initializer_change_is_seen_through_an_interior_pointer(self):
        self.assertDifferentMeaning(array_pointer(1), array_pointer(1, values=(11, 99, 33)))

    def test_self_referencing_data_detects_a_payload_change(self):
        self.assertDifferentMeaning(cycle(1, 9), cycle(1, 10))

    def test_self_reference_survives_rename_and_section_reordering(self):
        self.assertSameMeaning(cycle(1), cycle(1, renamed=True, extra_section=True))

    def test_two_node_cycle_detects_a_change_in_the_second_node(self):
        self.assertDifferentMeaning(cycle(2, 9), cycle(2, 10))

    def test_two_node_cycle_survives_rename_and_section_reordering(self):
        self.assertSameMeaning(cycle(2), cycle(2, renamed=True, extra_section=True))

    def test_self_reference_through_a_bound_coff_alias_is_the_same_object(self):
        self.assertSameMeaning(cycle(1), cycle(1, self_alias=True))

    def test_bss_zero_and_explicit_initialized_zero_are_equivalent(self):
        self.assertSameMeaning(bound_scalar(0, section_name=".bss", flags=BSS), bound_scalar(0))

    def test_changing_zero_filled_storage_to_one_is_detected(self):
        self.assertDifferentMeaning(bound_scalar(0, section_name=".bss", flags=BSS), bound_scalar(1))

    def test_bound_global_rename_does_not_change_its_meaning(self):
        self.assertSameMeaning(bound_scalar(23), bound_scalar(23, "_renamed_answer"))

    def test_bound_alias_for_the_same_storage_does_not_change_its_meaning(self):
        baseline = bound_scalar(23)
        coff = SyntheticCoff()
        coff.object("_answer", words(23))
        coff.alias("_alias", "_answer")
        actual = coff.fingerprint("_alias", {"_answer": DATA_ADDRESS, "_alias": DATA_ADDRESS})
        self.assertSameMeaning(baseline, actual)

    def test_secrel_access_includes_the_tls_initializer(self):
        def tls(value, name):
            coff = SyntheticCoff()
            coff.object(name, words(value), ".tls$AAA")
            return coff.fingerprint(name, {name: 0x01272000}, SECREL, addend=0)

        self.assertDifferentMeaning(tls(7, "_tls_value"), tls(8, "_tls_value"))
        self.assertSameMeaning(tls(7, "_tls_value"), tls(7, "_renamed_tls"))

    def test_unbound_nonliteral_objects_with_equal_bytes_are_not_interchangeable(self):
        def reference(name):
            coff = SyntheticCoff()
            coff.object("_left", words(7))
            coff.object("_right", words(7))
            return coff.fingerprint(name, {})

        before, after = reference("_left"), reference("_right")
        self.assertDifferentMeaning(before, after)
        self.assertIn("_left", before[2])
        self.assertIn("_right", after[2])

    def test_malformed_data_relocations_are_rejected(self):
        cases = [
            ("unknown kind", 8, [(0, 0x99)]),
            ("crossing the start", 8, [(-1, DIR32)]),
            ("crossing the end", 4, [(1, DIR32)]),
            ("entirely past the section", 4, [(8, DIR32)]),
            ("overlapping pointer fields", 8, [(0, DIR32), (2, DIR32)]),
        ]
        for label, size, relocations in cases:
            with self.subTest(label=label):
                coff = SyntheticCoff()
                section = coff.object("_root", bytes(size))
                coff.symbol("_external", 0)
                for offset, kind in relocations:
                    coff.relocate(section, offset, "_external", kind)
                with self.assertRaises(ValueError):
                    coff.fingerprint("_root", {"_root": DATA_ADDRESS, "_external": DATA_ADDRESS + 0x100})

    def test_a_nested_literal_cannot_silently_contain_pointer_relocations(self):
        coff = SyntheticCoff()
        pointer = coff.object("_root", words(0))
        literal = coff.object("$SG1", bytes(8), ".rdata")
        coff.symbol("_external", 0)
        coff.relocate(pointer, 0, "$SG1")
        coff.relocate(literal, 0, "_external")
        with self.assertRaises(ValueError):
            coff.fingerprint("_root", {"_root": DATA_ADDRESS, "_external": DATA_ADDRESS + 0x100})

    def test_deep_initializer_graph_fails_closed(self):
        with self.assertRaisesRegex(ValueError, "depth limit"):
            cycle(130)

    def test_shared_diamond_graph_has_a_bounded_verification_cost(self):
        # Only 32 objects, but exponentially many distinct traversal paths.
        coff = SyntheticCoff()
        levels = [[f"_level_{depth}_{side}" for side in range(2)] for depth in range(16)]
        sections = {}
        bindings = {}
        for depth, names in enumerate(levels):
            for side, name in enumerate(names):
                sections[name] = coff.object(name, words(0, 0))
                bindings[name] = DATA_ADDRESS + (depth * 2 + side) * 0x100
        for depth, names in enumerate(levels[:-1]):
            for name in names:
                coff.relocate(sections[name], 0, levels[depth + 1][0])
                coff.relocate(sections[name], 4, levels[depth + 1][1])
        with self.assertRaisesRegex(ValueError, "node limit"):
            coff.fingerprint(levels[0][0], bindings)


if __name__ == "__main__":
    unittest.main()
