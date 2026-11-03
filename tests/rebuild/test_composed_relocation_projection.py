"""Owned composed-consumer regressions using authored inputs only."""
import copy
from pathlib import Path
import struct
import sys
import tempfile
import unittest

ROOT=Path(__file__).resolve().parents[2]
sys.path[:0]=[str(ROOT/'tools/rebuild'),str(ROOT/'tools'),str(ROOT/'tests/rebuild')]
import composed_relocation_projection as projection
import coff_code_archive as coff
import compare as oracle
import root_certificate_composer as composer
import runtime_code_pool as pool
from test_root_certificate_composer import data_case
from test_composed_relocation_projection_independent import typed_label_context,project
from test_composed_relocation_projection_data_independent import authored_data


class ComposedProjectionTests(unittest.TestCase):
    def test_nonzero_local_label_values_resolve_once_in_unchanged_oracle(self):
        values=typed_label_context();output,receipt=project(values)
        root=values[5][0];original=coff.parse(values[0]);native=original['sections'][root['section']]
        image=bytearray(native['payload'])
        for row in values[1]['fields']:
            self.assertGreater(original['symbols'][row['coff_relocation']['symbol_index']]['value'],0)
            struct.pack_into('<I',image,row['source_field_offset'],row['original_operand'])
        class AuthoredImage:
            def read(self,address,size):
                start=address-int(root['original_address'],16)
                if start<0 or start+size>len(image):raise ValueError('authored span escape')
                return bytes(image[start:start+size])
        self.assertFalse(receipt['comparison_base_view'])
        self.assertFalse(receipt['local_label_names_added_to_base_view'])
        with tempfile.TemporaryDirectory() as td:
            path=Path(td)/'authored.obj';path.write_bytes(output)
            rows=oracle.compare(oracle.Coff(path),AuthoredImage(),dict(
                functions=[dict(address=root['original_address'],size=root['size'],symbol=receipt['exports'][0])],
                symbols=receipt['comparison_base_view']))
        self.assertEqual(rows[0]['verdict'],'match')
        self.assertEqual(len(rows[0]['relocations']),3)
        self.assertTrue(all(r['match'] for r in rows[0]['relocations']))

    def test_namespace_records_both_original_and_projected_physical_slots(self):
        values=authored_data();output,receipt=projection.project_member(*values,existing_exports=(),policy_id=projection.POLICY)
        self.assertTrue(receipt['namespace_after_selection'])
        self.assertEqual(receipt['original_physical_namespace_plan'],receipt['namespace_bindings'])
        expected=[(receipt['maps']['symbol_map'][old],name) for old,name in receipt['namespace_bindings']]
        self.assertEqual(receipt['projected_namespace_bindings'],expected)
        parsed=coff.parse(output)
        for new,name in expected:self.assertEqual(parsed['symbols'][new]['name'],name)
        self.assertFalse(values[2]['closure_observed'])
        self.assertTrue(receipt['original_negative_certificate_preserved'])

    def test_hash_and_composition_errors_are_not_structured_quarantine(self):
        for target in ('raw','base','composition','witness'):
            values=copy.deepcopy(authored_data())
            if target=='raw':values[0]+=b'changed'
            elif target=='base':values[2]['blockers']=[]
            elif target=='composition':values[4]['composed_omission_complete']=False
            else:values[3][0]['discharge_blocker_ids']=[]
            with self.subTest(target=target),self.assertRaises(ValueError):
                projection.assess_member(*values,existing_exports=(),policy_id=projection.POLICY)

    def test_typed_data_only_zero_field_leaf_uses_same_composed_policy(self):
        raw,contract,base,witnesses=data_case()
        composed=composer.compose(raw,contract,base,witnesses,policy_id=composer.POLICY)
        root=dict(contract['roots'][0],recipe_id=contract['recipe_id'],recipe_index=contract['provenance']['recipe_index'],
                  object_sha256=coff.digest(raw),source_sha256=contract['provenance']['source_sha256'])
        providers={root['original_address']:{k:root[k] for k in ('recipe_id','object_sha256','symbol_index')}}
        output,receipt=projection.project_member(raw,contract,base,witnesses,composed,[root],providers,
                                                existing_exports=(),policy_id=projection.POLICY)
        self.assertFalse(receipt['fields']);self.assertFalse(receipt['undefined'])
        self.assertEqual(coff.exports(output),[pool.canonical(providers[root['original_address']])])
        self.assertFalse(base['closure_observed'])


if __name__=='__main__':unittest.main()
