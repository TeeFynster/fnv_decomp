"""Expanded readonly omission attacks on authored objects only."""
import copy
import struct
import unittest
from test_parent_eh_adapter import valid_case
import parent_eh_adapter as adapter
import parent_eh_omission as omission


def case():
    def edit(obj):
        obj['sections'][8]['flags'] = 0x40300040
        obj['symbols'][71] = dict(name='.rdata', section=8, value=0, type=0,
            storage=3, aux_count=1, aux=struct.pack('<IHHIhBBH',4,0,0,0,0,0,0,0))
        obj['symbol_count'] = 73
    inputs = valid_case(object_edit=edit)
    expanded = adapter.observe_parent(**inputs)
    obj = adapter.coff.parse(inputs['raw'])
    base = adapter.ordinary.assess_object(obj, inputs['contract'])
    # Recreate the pre-readonly EH result from the same fresh semantic graph.
    expanded = adapter.expanded_omissions(obj,inputs['contract'],expanded['semantic'])
    return inputs, expanded, base


class ExpandedReadonlyOmissionTests(unittest.TestCase):
    def test_isolated_exact_readonly_section(self):
        inputs, expanded, base = case()
        proof = omission.observe(inputs['raw'],inputs['contract'],base,expanded)
        self.assertEqual(len(proof['discharge_occurrences']),1,proof)
        self.assertTrue(adapter.observe_parent(**inputs)['structural_projection_candidate'])
        self.assertTrue(proof['rows'][0]['approved'])
        self.assertFalse(proof['original_data_storage_adopted'])
        self.assertFalse(proof['emission_approved'])
        self.assertFalse(expanded['structural_projection_candidate'])

    def test_expanded_section_and_symbol_roots_block(self):
        inputs, expanded, base = case()
        for section_root in (True,False):
            mutated = copy.deepcopy(expanded)
            if section_root:mutated['retained_sections'].append(8);mutated['retained_sections'].sort()
            else:
                mutated['retained_primary_indices'].append(71);mutated['retained_primary_indices'].sort()
                mutated['retained_physical_slots'].extend([71,72]);mutated['retained_physical_slots'].sort()
            proof=omission.observe(inputs['raw'],inputs['contract'],base,mutated)
            self.assertEqual(proof['discharge_occurrences'],[])
            self.assertFalse(proof['rows'][0]['approved'])

    def test_stale_ordinary_and_semantic_identity_reject(self):
        inputs, expanded, base = case()
        for mutate_base in (True,False):
            b=copy.deepcopy(base);e=copy.deepcopy(expanded)
            if mutate_base:b['blockers']=[]
            else:e['semantic']['contract_sha256']='0'*64
            with self.assertRaises(ValueError):omission.observe(inputs['raw'],inputs['contract'],b,e)


if __name__=='__main__':unittest.main()
