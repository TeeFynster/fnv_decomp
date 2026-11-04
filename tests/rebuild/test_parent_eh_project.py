"""Authored projection only; no original objects/images or native programs."""
import copy
import struct
import unittest
from test_parent_eh_adapter import valid_case
import parent_eh_adapter as adapter
import parent_eh_project as projector


class ParentEHProjectionTests(unittest.TestCase):
    def test_piecewise_graph_payloads_and_original_oracle(self):
        inputs=valid_case();expected=adapter.observe_parent(**inputs)
        output,report=projector.project_parent(inputs,expected)
        self.assertEqual(len(report['after']['fields']),11)
        self.assertEqual(len(report['after']['eh_sections']),2)
        self.assertEqual(report['after']['ordinary'][0]['compiled_extent'],101)
        self.assertTrue(report['after']['independent_reparse'])
        self.assertEqual(projector.coff.exports(output),[report['export']])
        self.assertFalse(report['runtime_eligible']);self.assertFalse(report['provider_selected'])

    def test_mixed_safeseh_owned_handler_not_first_is_projected_exactly(self):
        def edit(obj):
            obj['sections'][16].update(size=8,payload=struct.pack('<II',68,19))
            aux=bytearray(obj['symbols'][64]['aux']);struct.pack_into('<I',aux,0,8);obj['symbols'][64]['aux']=bytes(aux)
        inputs=valid_case(object_edit=edit);expected=adapter.observe_parent(**inputs)
        self.assertTrue(expected['structural_projection_candidate'],expected)
        output,report=projector.project_parent(inputs,expected);sx=report['safeseh']
        self.assertEqual([r['retain'] for r in sx['source_records']],[False,True])
        section=projector.coff.parse(output)['sections'][sx['output_section']]
        self.assertEqual(section['payload'],struct.pack('<I',sx['output_handler_index']))
        self.assertEqual(section['size'],4)

    def test_forged_or_stale_caller_decision_never_emits(self):
        inputs=valid_case();expected=adapter.observe_parent(**inputs)
        expected['semantic']['states'][0]['to_state']=0
        with self.assertRaisesRegex(ValueError,'STALE_OR_FORGED'):
            projector.project_parent(inputs,expected)

    def test_failed_piece_cannot_be_overridden_by_ready_claim(self):
        inputs=valid_case();inputs['contract']['parent_eh'][0][2]=False
        expected=adapter.observe_parent(**inputs)
        with self.assertRaisesRegex(ValueError,'PARENT_GRAPH_NOT_SERIALIZABLE'):
            projector.project_parent(inputs,expected)

    def test_same_base_distinct_physical_imports_remain_blocked(self):
        inputs=valid_case();recipe=inputs['recipe'];name=projector.coff.parse(inputs['raw'])['symbols'][13]['name']
        recipe['symbols'][name]='0x10010000';inputs['unit_proof']['recipe_unit_sha256']=adapter.digest(recipe)
        row=next(f for f in inputs['contract']['fields'] if f['coff_relocation']['symbol_index']==13)
        row['derived_source_symbol_base_va']=row['exact_original_target_va']='0x10010000'
        original=inputs['reference']
        class Reference:
            def read(self,address,size):
                result=bytearray(original.read(address,size));field=0x10000000+70
                if address<=field and field+4<=address+size:struct.pack_into('<I',result,field-address,(0x10010000-field-4)&0xffffffff)
                return bytes(result)
        inputs['reference']=Reference();expected=adapter.observe_parent(**inputs)
        self.assertTrue(expected['structural_projection_candidate'],expected)
        with self.assertRaisesRegex(ValueError,'REFERENCE_GROUP_REQUIRES_NAMESPACE_EXTENSION'):
            projector.project_parent(inputs,expected)


if __name__=='__main__':unittest.main()
