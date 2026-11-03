"""Original synthetic component metadata; no native tools or original image."""
import copy
from pathlib import Path
import struct
import sys
import unittest

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tools/rebuild'))
import application_link_cohort as cohort


def obj(undefined=True, relocs=True, section_name=b'.text'):
    names = ['root', 'target']; strings = bytearray(bytes(4)); table = bytearray()
    for index, name in enumerate(names):
        at = len(strings); strings += name.encode() + b'\0'
        table += struct.pack('<IIIhHBB', 0, at, 0, 0 if index and undefined else 1, 32, 2, 0)
    struct.pack_into('<I', strings, 0, len(strings))
    relocation = struct.pack('<IIH', 4, 1, 6) if relocs else b''
    return struct.pack('<HHIIIHH', 0x14c, 1, 0, 188 + len(relocation), 2, 0, 0) + \
        struct.pack('<8sIIIIIIHHI', section_name, 0, 0, 128, 60, 188 if relocs else 0, 0,
            int(relocs), 0, 0x60500020 if section_name == b'.text' else 0x40000040) + bytes(128) + relocation + table + strings


def mapped_args(undefined=True):
    return dict(component='synthetic', member='original.obj', recipe_id='fixture', object_sha256='a' * 64,
        roots=[dict(symbol_index=10, section=7, value=0, size=128, original_address='0x00401000')],
        maps=dict(section_map={'7': 1}, symbol_map={'10': 0, '11': 1}),
        namespace=[dict(physical_index=10, serialized_index=0, name='root'),
                   dict(physical_index=11, serialized_index=1, name='target')],
        obligations=[dict(physical_section=7, field_offset=4, symbol_index=11, kind=6,
            canonical_name='target', addend_bits=0, role='data', original_base='0x02000000',
            original_target='0x02000000')] if undefined else [],
        retained_bases={'target': '0x00401000'} if not undefined else {},
        expected_exports=['root'] if undefined else ['root', 'target'])


class ApplicationLinkCohortTests(unittest.TestCase):
    def test_mapped_input_retains_exact_physical_target_and_original_obligation(self):
        providers, fields = cohort.mapped_member(obj(), **mapped_args())
        self.assertEqual(providers[0]['original_address'], '0x00401000')
        self.assertEqual(fields[0]['physical_symbol_index'], 11)
        self.assertEqual(fields[0]['symbol_index'], 1)
        self.assertEqual(fields[0]['proof']['original_target'], '0x02000000')

    def test_missing_changed_duplicate_or_unvisited_field_proof_fails(self):
        for mutate in [lambda a: a['obligations'].clear(),
            lambda a: a['obligations'][0].update(kind=20),
            lambda a: a['obligations'][0].update(addend_bits=4),
            lambda a: a['obligations'].append(copy.deepcopy(a['obligations'][0])),
            lambda a: a['namespace'][1].update(physical_index=99),
            lambda a: a['maps']['symbol_map'].update({'11': 0})]:
            args = mapped_args(); mutate(args)
            with self.assertRaises(ValueError):
                cohort.mapped_member(obj(), **args)

    def providers(self):
        return [dict(component='one', member='original.obj', canonical='first', recipe_id='recipe-a',
            object_sha256='a' * 64, symbol_index=10, original_address='0x00401000')]

    def test_export_physical_identity_and_original_address_are_independent_collisions(self):
        one = self.providers()
        two = copy.deepcopy(one)
        for change in [dict(canonical='first', recipe_id='other', original_address='0x00402000'),
                       dict(canonical='other', original_address='0x00402000'),
                       dict(canonical='other', recipe_id='other')]:
            two[0].update(change)
            with self.assertRaises(ValueError):
                cohort.disjoint_providers([one, two])
            two = copy.deepcopy(one)
        two[0].update(canonical='other', recipe_id='other', original_address='0x00402000')
        self.assertEqual(cohort.disjoint_providers([one, two])['physical_owners'], 2)

    def test_overlay_logical_owner_cannot_duplicate_original_provider(self):
        original = self.providers(); overlay = copy.deepcopy(original)
        overlay[0].update(canonical='overlay', object_sha256='b' * 64,
            logical_object_sha256='a' * 64, logical_symbol_index=10, original_address='0x00403000')
        with self.assertRaisesRegex(ValueError, 'logical physical owner'):
            cohort.disjoint_providers([original, overlay])

    def test_existing_duplicate_and_new_selected_symbol_conflicts_fail(self):
        with self.assertRaisesRegex(ValueError, 'existing'):
            cohort.disjoint_providers([], existing_noncode_definitions=['same', 'same'])
        with self.assertRaisesRegex(ValueError, 'selected export'):
            cohort.disjoint_providers([self.providers()], existing_noncode_definitions=['first'])

    def test_full_baseline_identity_and_address_collisions_cannot_hide_behind_new_name(self):
        baseline = self.providers(); new = copy.deepcopy(baseline)
        new[0].update(canonical='renamed', original_address='0x00402000')
        with self.assertRaisesRegex(ValueError, 'logical physical owner'):
            cohort.disjoint_providers([new], baseline_providers=baseline)
        new[0].update(recipe_id='different', original_address='0x00401000')
        with self.assertRaisesRegex(ValueError, 'original function address'):
            cohort.disjoint_providers([new], baseline_providers=baseline)
        with self.assertRaisesRegex(ValueError, 'full provider'):
            cohort.disjoint_providers([], existing_noncode_definitions=['_fnv_code_' + 'a' * 64])

    def test_unrelated_relocated_section_cannot_be_attributed_to_selected_root(self):
        original = obj()
        table_and_strings = bytearray(original[198:])
        struct.pack_into('<h', table_and_strings, 12, 2)
        headers = struct.pack('<HHIIIHH', 0x14c, 2, 0, 366, 2, 0, 0)
        headers += struct.pack('<8sIIIIIIHHI', b'.extra', 0, 0, 128, 100, 228, 0, 1, 0, 0x60500020)
        headers += struct.pack('<8sIIIIIIHHI', b'.text', 0, 0, 128, 238, 0, 0, 0, 0, 0x60500020)
        data = headers + bytes(128) + struct.pack('<IIH', 4, 1, 6) + bytes(128) + table_and_strings
        args = mapped_args(); args['maps']['section_map'] = {'7': 2, '8': 1}
        args['obligations'][0]['physical_section'] = 8
        with self.assertRaisesRegex(ValueError, 'lacks exact source'):
            cohort.mapped_member(bytes(data), **args)

    def test_duplicate_EH_field_geometry_is_rejected_before_dictionary_coalescing(self):
        data = bytearray(obj())
        data = data[:198] + data[188:198] + data[198:]
        struct.pack_into('<I', data, 8, 208)
        struct.pack_into('<H', data, 52, 2)
        with self.assertRaisesRegex(ValueError, 'duplicate physical'):
            cohort.actual_fields(cohort.coff.parse(bytes(data)))

    def test_readonly_DATA_successor_is_only_the_exact_name_field(self):
        old = obj(False, False, b'.data')
        new = old[:20] + b'.rdata\0\0' + old[28:]
        row = dict(input_sha256=cohort.digest(old), output_sha256=cohort.digest(new), section_name_offset=20)
        cohort.data_section_successor(old, new, row)
        changed = bytearray(new); changed[60] = 1
        row['output_sha256'] = cohort.digest(changed)
        with self.assertRaisesRegex(ValueError, 'section-name'):
            cohort.data_section_successor(old, bytes(changed), row)

    def test_reference_certificate_cannot_borrow_another_original_field_ledger(self):
        row = dict(certificate=dict(original_union_plan_sha256='b' * 64,
            provenance=dict(original_union_row=dict(sha256='c' * 64))))
        with self.assertRaisesRegex(ValueError, 'original field ledger'):
            cohort.reference_component(obj(), row, dict(plan={}))

    def test_accepted_reference_certificate_does_not_promote_historical_eligibility(self):
        data, args = obj(), mapped_args()
        plan = dict(eligible=False, blockers=[dict(code='REFERENCE_CERTIFICATE_REQUIRED')],
            obligations=args['obligations'], comparison_base_view={}, counts=dict(fields=1))
        original = dict(event='BLOCKED_RECIPE_UNION', plan=plan)
        certificate = dict(recipe_id=args['recipe_id'], object_sha256=args['object_sha256'],
            roots=args['roots'], namespace_plan=args['namespace'],
            original_union_plan_sha256=cohort.digest(cohort.canonical(plan)),
            provenance=dict(original_union_row=dict(sha256=cohort.digest(cohort.canonical(original)))))
        row = dict(certificate=certificate, projection=dict(output_sha256=cohort.digest(data),
            coalescing_performed=False, relocation_retargeting_performed=False,
            maps=args['maps'], exports=['root']))
        providers, fields = cohort.reference_component(data, row, original)
        self.assertEqual(len(providers), 1); self.assertEqual(len(fields), 1)
        self.assertFalse(original['plan']['eligible'])
        self.assertEqual(original['plan']['blockers'][0]['code'], 'REFERENCE_CERTIFICATE_REQUIRED')

    def test_generic_zero_relocation_member_rejects_hidden_undefined_record(self):
        data = obj(relocs=False)
        projection = dict(output_sha256=cohort.digest(data), relocation_count=0, exports=['root'])
        with self.assertRaisesRegex(ValueError, 'generic hidden'):
            cohort.generic_component(data, dict(name='zero.obj', projection=projection))


if __name__ == '__main__':
    unittest.main()
