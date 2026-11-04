"""Authored parent-final CODE aliases; no game inputs or native programs."""
import copy
import struct
import unittest
from test_parent_eh_adapter import valid_case
import parent_eh_adapter as adapter
import eh_reference_groups as groups
import parent_eh_groups_project as projector


def alias_case():
    inputs=valid_case();obj=adapter.coff.parse(inputs['raw']);name=obj['symbols'][17]['name']
    inputs['recipe']['symbols'][name]='0x10011000'
    inputs['unit_proof']['recipe_unit_sha256']=adapter.digest(inputs['recipe'])
    for row in inputs['contract']['fields']:
        if row['coff_relocation']['symbol_index'] in (13,17):
            row.update(derived_source_symbol_base_va='0x10011000',exact_original_target_va='0x10011000',code_owners=[dict(address='0x10011000',offset=0)],code_ownership_ambiguous=False)
    original=inputs['reference']
    class Reference:
        def read(self,address,size):
            result=bytearray(original.read(address,size));field=0x10000000+42
            if address<=field and field+4<=address+size:struct.pack_into('<I',result,field-address,(0x10011000-field-4)&0xffffffff)
            return bytes(result)
    inputs['reference']=Reference();return inputs


class EHReferenceGroupTests(unittest.TestCase):
    def test_shared_name_preserves_physical_symbols_and_all_fields(self):
        inputs=alias_case();result=adapter.observe_parent(**inputs);self.assertTrue(result['structural_projection_candidate'],result)
        certificate=groups.certify(inputs['raw'],result,inputs['contract'])
        self.assertEqual(certificate['groups'][0]['members'],[13,17]);self.assertEqual(certificate['physical_field_count'],11)
        named=groups.namespace(inputs['raw'],result,inputs['contract'],certificate);before=adapter.coff.parse(inputs['raw']);after=adapter.coff.parse(named)
        self.assertEqual(before['sections'],after['sections']);self.assertEqual(before['symbol_count'],after['symbol_count'])
        self.assertEqual(after['symbols'][13]['name'],after['symbols'][17]['name'])
        self.assertFalse(certificate['coalescing_allowed']);self.assertFalse(certificate['provider_selected'])

    def test_complete_projection_replays_original_core(self):
        inputs=alias_case();expected=adapter.observe_parent(**inputs);output,report=projector.project_parent(inputs,expected)
        self.assertEqual(len(report['after']['fields']),11);self.assertEqual(report['after']['ordinary'][0]['verdict'],'match')
        self.assertEqual(len(adapter.coff.parse(output)['symbols']),len(report['maps']['symbol_map']))

    def test_missing_or_duplicate_physical_field_rejects(self):
        inputs=alias_case();result=adapter.observe_parent(**inputs)
        for duplicate in (False,True):
            changed=copy.deepcopy(result)
            if duplicate:changed['semantic']['fields'].append(changed['semantic']['fields'][0])
            else:changed['semantic']['fields'].pop()
            with self.assertRaisesRegex(ValueError,'FIELD_UNIVERSE'):groups.certify(inputs['raw'],changed,inputs['contract'])

    def test_ambiguous_interior_unselected_owner_proof_rejects(self):
        for change in (dict(code_ownership_ambiguous=True),dict(code_owners=[dict(address='0x10011000',offset=1)]),dict(classification='UNSELECTED_EXECUTABLE_TARGET_UNCLASSIFIED')):
            inputs=alias_case();row=next(f for f in inputs['contract']['fields'] if f['coff_relocation']['symbol_index']==17);row.update(change)
            result=adapter.observe_parent(**inputs)
            with self.assertRaisesRegex(ValueError,'OWNER_NOT_PROVED'):groups.certify(inputs['raw'],result,inputs['contract'])

    def test_stale_certificate_cannot_change_one_group_member(self):
        inputs=alias_case();result=adapter.observe_parent(**inputs);certificate=groups.certify(inputs['raw'],result,inputs['contract'])
        certificate['groups'][0]['members']=[13]
        with self.assertRaisesRegex(ValueError,'STALE_OR_FORGED'):groups.namespace(inputs['raw'],result,inputs['contract'],certificate)


if __name__=='__main__':unittest.main()
