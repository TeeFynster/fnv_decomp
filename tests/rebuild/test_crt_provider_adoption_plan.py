import sys
from pathlib import Path
import unittest
sys.path.insert(0,str(Path(__file__).resolve().parents[2]/'tools/rebuild'))
import crt_provider_adoption_plan as plan

class AdoptionPlanTests(unittest.TestCase):
    def field(self,base='0x00ecc071',role='code',kind=20):
        return dict(component='actual-entry',member='entry.obj',caller='root',section=2,offset=768,
            canonical=plan.undefined(base,role),physical_symbol_index=1420,kind=kind,undefined=True,
            proof=dict(original_base=base,original_target=base,role=role,kind=kind,addend_bits=0,symbol_index=1420))
    def test_canonical_identity_matches_saved_main(self):
        self.assertEqual(plan.undefined('0x00ecc071','code'),
            '_fnv_undefined_e83f47cc3a9a6d02b803a2ca3ada0cb544088aa09de20158c973fc0d10e12c30')
        self.assertNotEqual(plan.undefined('0x00ec408c','code'),plan.undefined('0x00ec408c','crt-contract'))
    def test_all_fields_and_unknowns_are_not_filtered_by_initial_subset(self):
        a=self.field();b=self.field();b['offset']=900
        self.assertEqual(len(plan.census([a,b],'0x00ecc071','code',20)),2)
    def test_wrong_role_and_nonzero_addend_block(self):
        a=self.field();a['proof']['role']='data'
        with self.assertRaises(ValueError):plan.census([a],'0x00ecc071','code',20)
        a=self.field();a['proof']['addend_bits']=4
        with self.assertRaises(ValueError):plan.census([a],'0x00ecc071','code',20)
    def test_duplicate_field_blocks(self):
        a=self.field()
        with self.assertRaises(ValueError):plan.census([a,a],'0x00ecc071','code',20)
    def test_main_projection_keeps_physical_and_serialized_symbols_distinct(self):
        a=self.field();a['symbol_index']=231
        a['proof'].update(physical_symbol_index=1420,symbol_index=231)
        self.assertEqual(plan.census([a],'0x00ecc071','code',20)[0]['physical_symbol_index'],1420)
    def test_data_and_code_kinds_cannot_be_interchanged(self):
        a=self.field('0x011c16bc','data',6)
        self.assertEqual(len(plan.census([a],'0x011c16bc','data',6)),1)
        with self.assertRaises(ValueError):plan.census([a],'0x011c16bc','data',20)
    def test_cookie_recipe_requires_exact_symbol_binding(self):
        a=self.field('0x011c16bc','data',6);a.update(recipe_id='0000-test',root='0x1234')
        unit=dict(source='example.cpp',symbols={'___security_cookie':'0x11c16bc'})
        self.assertEqual(len(plan.cookie_recipe_proofs([a],[unit])),1)
        unit['symbols']['ambiguous']='0x011c16bc'
        with self.assertRaises(ValueError):plan.cookie_recipe_proofs([a],[unit])
    def test_response_is_exact_and_rejects_injected_options(self):
        row=dict(canonical_undefined='_canonical',normal_export='@__security_check_cookie@4')
        self.assertEqual(plan.response([row]),'/ALTERNATENAME:_canonical=@__security_check_cookie@4\n')
        row['normal_export']='_fopen /FORCE'
        with self.assertRaises(ValueError):plan.response([row])
    def test_response_rejects_duplicate_and_conflicting_global_aliases(self):
        row=dict(canonical_undefined='_canonical',normal_export='_fopen')
        with self.assertRaises(ValueError):plan.response([row,row])
        other=dict(canonical_undefined='_canonical',normal_export='_fclose')
        with self.assertRaises(ValueError):plan.response([row,other])

if __name__=='__main__':unittest.main()
