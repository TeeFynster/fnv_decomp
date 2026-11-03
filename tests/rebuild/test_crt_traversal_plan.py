"""Synthetic instruction/operand/geometry evidence; no original image input."""
import copy
from pathlib import Path
import sys
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[2] / 'tools' / 'rebuild'))
import crt_traversal_plan as plan


def geometry(flags=0x40000040):
    return dict(image=dict(base=0x400000), selected_sections=[dict(name='.rdata',
        rva=0x1000, extent=0x1000, raw_size=0x1000, flags=flags)])


class TraversalPlanTests(unittest.TestCase):
    def test_decoder_joins_symbolic_operand_without_image_bytes(self):
        # Source-authored x86 push-immediate fixture, not a copied function.
        decoded, joins = plan.decode_native(bytes([0x68, 0, 0, 0, 0]),
            [dict(offset=1, kind=6, symbol='fixture')])
        self.assertEqual(decoded[0], ('push', plan.sym('fixture')))
        self.assertEqual(joins[0]['operand_kind'], 'immediate')
        self.assertFalse(joins[0]['independent_target_identity_verified'])
        with self.assertRaises(ValueError):
            plan.decode_native(bytes([0x68, 0, 0, 0, 0]), [dict(offset=1, kind=20, symbol='fixture')])
        with self.assertRaises(ValueError):
            plan.decode_native(bytes([0x0f]), [])

    def test_leaf_model_covers_all_and_rejects_wrong_null_stride_or_error_branch(self):
        for name, offset, wrong in [('__initterm', 14, ('je', plan.imm(26))),
            ('__initterm', 18, ('add', plan.reg('esi'), plan.imm(-4))),
            ('__initterm_e', 15, ('je', plan.imm(33)))]:
            complete, expected = plan.models()[name]
            decoded = copy.deepcopy(expected)
            plan.validate_model(decoded, expected, complete)
            decoded[offset] = wrong
            with self.assertRaises(ValueError): plan.validate_model(decoded, expected, complete)
        complete, expected = plan.models()['__initterm']
        decoded = dict(expected, **{})
        decoded[99] = ('nop',)
        with self.assertRaises(ValueError): plan.validate_model(decoded, expected, complete)

    def test_caller_models_reject_swapped_range_and_wrong_short_circuit(self):
        complete, expected = plan.models()['__cinit']
        decoded = dict(expected)
        decoded[44], decoded[49] = decoded[49], decoded[44]
        with self.assertRaises(ValueError): plan.validate_model(decoded, expected, complete)
        decoded = dict(expected)
        decoded[63] = ('jne', plan.imm(65))
        with self.assertRaises(ValueError): plan.validate_model(decoded, expected, complete)
        complete, expected = plan.models()['_doexit']
        decoded = dict(expected)
        decoded[57] = ('jne', plan.imm(204))
        with self.assertRaises(ValueError): plan.validate_model(decoded, expected, complete)

    def test_interval_plan_exact_end_exclusive_and_unknowns_preserved(self):
        request = plan.table_request('fixture', 0x401004, 0x401014, geometry())
        self.assertEqual(request['traversed_cells'], 4)
        self.assertEqual(request['aggregate_requested_bytes'], 20)
        self.assertEqual(request['traversal_interval'], [0x401004, 0x401014])
        self.assertTrue(request['preserve_nulls_and_unknown_targets'])
        self.assertFalse(request['runtime_provider_approved'])

    def test_bad_raw_geometry_reverse_alignment_and_budget_rejected(self):
        for begin, end, g in [(0x401014, 0x401004, geometry()),
                (0x401005, 0x401014, geometry()), (0x401004, 0x402000, geometry()),
                (0x401004, 0x401014, geometry(0x60000020)),
                (0x401004, 0x601014, geometry())]:
            with self.assertRaises(ValueError): plan.table_request('fixture', begin, end, g)

    def test_named_operand_requires_complete_consistency_and_highlow(self):
        field = dict(symbol='fixture', original_symbol_base_candidate=0x401000,
            kind=6, addend=0, errors=[], field_highlow=True)
        self.assertEqual(plan.operand(dict(relocations=[field]), 'fixture', 6), 0x401000)
        for bad in [dict(field, addend=4), dict(field, field_highlow=False),
                    dict(field, errors=['unproved']), dict(field, original_symbol_base_candidate=0x402000)]:
            with self.assertRaises(ValueError):
                plan.operand(dict(relocations=[field, bad]), 'fixture', 6)


if __name__ == '__main__': unittest.main()
