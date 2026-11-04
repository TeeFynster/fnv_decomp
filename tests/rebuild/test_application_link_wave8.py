"""Authored duplicate-record metadata cases; no native tools or Game input."""
import copy
from pathlib import Path
import sys
import unittest

sys.path.insert(0,str(Path(__file__).resolve().parents[2]/'tools/rebuild'))
import application_link_wave8 as wave

def fixture():
    obj=dict(symbols={});maps=dict(section_map={'7':1},symbol_map={});groups=[];entries=[];fields=[]
    for groupid in range(2):
        old=[100+3*groupid+i for i in range(3)];new=[1+3*groupid+i for i in range(3)];name='canonical%d'%groupid;base=0x401000+groupid*16;uses=[];declared=[]
        for before,after in zip(old,new):
            maps['symbol_map'][str(before)]=after;obj['symbols'][after]=dict(name=name,section=0,storage=2,aux_count=0)
            offset=after*4;use=dict(section=7,offset=offset,target_index=before,kind=20,retained=True);uses.append(use)
            fields.append(dict(section=1,offset=offset,physical_symbol_index=before,symbol_index=after,undefined=True,
                kind=20,canonical=name,proof=dict(addend_bits=0,original_base=hex(base),original_target=hex(base))))
            declared.append(dict(section=7,offset=offset,target_index=before,kind=20,addend=0))
            entries.append(dict(physical_section=7,physical_offset=offset,coff_relocation=dict(symbol_index=before,kind=20,addend=0,width=4),
                classification='SELECTED_CODE_ENTRY',proof_consistency='EXACT_OWN_SOURCE_RESOLUTION',exact_original_target_va=hex(base),
                function_va='0x400000',recipe_id='fixture',code_ownership_ambiguous=False,physical_field_overlap_count=1,selected_address=hex(base),
                provider_selected=False,abi_verified=False,runtime_eligible=False,game_fixup_approved=False))
        groups.append(dict(members=old,output_members=new,name=name,original_base=base,role='code',semantic_domain='code',
            contract_kind='function',ABI_verified=False,provider_selected=False,all_physical_uses=uses,fields=declared))
    return obj,dict(parent='0x400000',original_root=dict(recipe_id='fixture'),physical_maps=maps,no_symbol_coalescing=True,reference_groups=groups,reference_group_entry_proofs=entries),fields

class WaveTests(unittest.TestCase):
    def test_six_distinct_physical_records_and_fields_retained(self):
        obj,metadata,fields=fixture();self.assertEqual(len(wave.reference_groups(obj,metadata,fields)),6)
        self.assertEqual(len({row['symbol_index'] for row in fields}),6)
    def test_coalesced_output_index_rejected(self):
        args=fixture();args[1]['reference_groups'][0]['output_members'][1]=1
        with self.assertRaises(ValueError):wave.reference_groups(*args)
    def test_missing_or_ambiguous_entry_proof_rejected(self):
        for duplicate in (True,False):
            args=fixture()
            if duplicate:args[1]['reference_group_entry_proofs'].append(copy.deepcopy(args[1]['reference_group_entry_proofs'][0]))
            else:args[1]['reference_group_entry_proofs'].pop()
            with self.assertRaises(ValueError):wave.reference_groups(*args)
    def test_changed_target_or_source_class_rejected(self):
        for key,value in [('exact_original_target_va','0x1234'),('proof_consistency','GUESSED')]:
            args=fixture();args[1]['reference_group_entry_proofs'][0][key]=value
            with self.assertRaises(ValueError):wave.reference_groups(*args)
    def test_hidden_or_unretained_use_rejected(self):
        for mode in ('missing','unretained'):
            args=fixture()
            if mode=='missing':args[2].pop()
            else:args[1]['reference_groups'][0]['all_physical_uses'][0]['retained']=False
            with self.assertRaises(ValueError):wave.reference_groups(*args)
    def test_same_offset_collision_rejected(self):
        args=fixture();args[2][-1]['offset']=args[2][0]['offset']
        with self.assertRaises(ValueError):wave.reference_groups(*args)
    def test_hidden_same_name_record_or_extra_group_use_rejected(self):
        for mode in ('record','use'):
            args=fixture()
            if mode=='record':args[0]['symbols'][7]=copy.deepcopy(args[0]['symbols'][1])
            else:
                extra=copy.deepcopy(args[2][0]);extra['offset']=100;args[2].append(extra)
            with self.assertRaises(ValueError):wave.reference_groups(*args)
    def test_unrelated_parent_or_ambiguous_entry_owner_rejected(self):
        for key,value in [('function_va','0x499999'),('recipe_id','other'),('code_ownership_ambiguous',True)]:
            args=fixture();args[1]['reference_group_entry_proofs'][0][key]=value
            with self.assertRaises(ValueError):wave.reference_groups(*args)

if __name__=='__main__':unittest.main()
