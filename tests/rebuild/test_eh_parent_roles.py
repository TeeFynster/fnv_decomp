"""Original metadata containers only; no native tool, image or game input."""
import copy
import hashlib
import json
from pathlib import Path
import struct
import sys
import tempfile
from types import SimpleNamespace
import unittest
from unittest.mock import patch

ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'tools/rebuild'))
import eh_parent_roles as roles

PARENT='0x00400100'

def state_fixture():
    # Two independently identified unwind actions; both eventually leave the frame.
    data=struct.pack('<4I',0xffffffff,0,0,0)+struct.pack('<9I',0x19930522,2,0,0,0,0,0,0,1)
    original=bytearray(data)
    struct.pack_into('<I',original,4,0x400200)
    struct.pack_into('<I',original,12,0x400300)
    struct.pack_into('<I',original,24,0x401000)
    symbols={0:dict(name='_cleanup0',section=2,value=0),1:dict(name='_cleanup1',section=2,value=8),2:dict(name='_unwind',section=3,value=0)}
    section=dict(data=data,relocs=[(4,0,6),(12,1,6),(24,2,6)])
    coff=SimpleNamespace(sections=[None,{}, {},section],symbols=symbols)
    info=dict(value=16);unwind=dict(value=0,name='_unwind')
    pieces=[dict(section=2,native_start=0,parent=PARENT,original_start=0x400200),dict(section=2,native_start=8,parent=PARENT,original_start=0x400300)]
    return coff,info,unwind,bytes(original),pieces

def component_fixture():
    coff,info,unwind,original,pieces=state_fixture()
    states=roles.parse_states(coff,3,info,unwind,original,0x401000,pieces,PARENT)
    actions=[]
    for n,piece in enumerate(pieces):
        action=dict(kind=20,target_symbol='_same_helper',original_destination=0x405000+n*0x100,original_expected=0x405000,original_relocation_match=n==0)
        piece.update(receipt_match=n==0,all_local_comparisons_match=n==0,comparison=dict(nonrelocation_match=True),relocations=[action])
        actions.append(action)
    result=dict(parent=PARENT,runtime_eligible=False,provider_selected=False,frame_contract_verified=False,state_machine=states,pieces=pieces,
        roles=[dict(t,action=actions[n],piece_match=n==0,runtime_eligible=False) for n,t in enumerate(states['transitions'])])
    return result

class ParentRoleTests(unittest.TestCase):
    def test_complete_state_machine_preserves_distinct_roles(self):
        component=component_fixture();roles.validate_roles(component)
        self.assertEqual([t['to_state'] for t in component['state_machine']['transitions']],[-1,0])
        self.assertEqual(len({r['role_id'] for r in component['roles']}),2)
        self.assertFalse(component['roles'][1]['piece_match'])
    def test_missing_state_transition(self):
        c=component_fixture();c['state_machine']['transitions'].pop()
        with self.assertRaises(ValueError):roles.validate_roles(c)
        args=list(state_fixture());args[0].sections[3]['relocs'].pop(1)
        with self.assertRaises(ValueError):roles.parse_states(args[0],3,args[1],args[2],args[3],0x401000,args[4],PARENT)
    def test_cross_parent_cleanup_is_rejected(self):
        args=list(state_fixture());args[4][1]['parent']='0x00400200'
        with self.assertRaises(ValueError):roles.parse_states(args[0],3,args[1],args[2],args[3],0x401000,args[4],PARENT)
        c=component_fixture();c['pieces'][1]['parent']='0x00400200'
        with self.assertRaises(ValueError):roles.validate_roles(c)
    def test_merged_distinct_roles_rejected(self):
        c=component_fixture();c['roles'][1]['role_id']=c['roles'][0]['role_id']
        with self.assertRaises(ValueError):roles.validate_roles(c)
        c=component_fixture();c['roles'][1]['action']=copy.deepcopy(c['roles'][0]['action'])
        with self.assertRaises(ValueError):roles.validate_roles(c)
    def test_failed_piece_cannot_be_silently_accepted(self):
        c=component_fixture();c['roles'][1]['piece_match']=True;c['pieces'][1]['receipt_match']=True;c['pieces'][1]['all_local_comparisons_match']=True
        with self.assertRaises(ValueError):roles.validate_roles(c)
    def test_provider_and_frame_promotions_rejected(self):
        for field in ('runtime_eligible','provider_selected','frame_contract_verified'):
            c=component_fixture();c[field]=True
            with self.assertRaises(ValueError):roles.validate_roles(c)
    def test_invalid_state_target_and_unmodeled_metadata(self):
        for mode in ('cycle','extra','kind','scalar'):
            args=list(state_fixture());section=args[0].sections[3]
            if mode=='cycle':section['data']=struct.pack('<I',0)+section['data'][4:]
            elif mode=='extra':section['relocs'].append((0,0,6))
            elif mode=='kind':section['relocs'][0]=(4,0,20)
            else:section['data']=section['data'][:28]+struct.pack('<I',1)+section['data'][32:]
            with self.assertRaises(ValueError):roles.parse_states(args[0],3,args[1],args[2],args[3],0x401000,args[4],PARENT)
    def test_duplicate_funcinfo_unwind_relocation_rejected(self):
        args=list(state_fixture());args[0].sections[3]['relocs'].append((24,2,6))
        with self.assertRaises(ValueError):roles.parse_states(args[0],3,args[1],args[2],args[3],0x401000,args[4],PARENT)
    def test_final_stability_tracks_producers_and_index_presence(self):
        with tempfile.TemporaryDirectory() as d:
            root=Path(d);producer=root/'producer.py';producer.write_text('original')
            index=root/'index.json';observations={producer:roles.sha(producer)}
            roles.check_stability(observations,index,False,None)
            producer.write_text('changed')
            with self.assertRaises(ValueError):roles.check_stability(observations,index,False,None)
            producer.write_text('original');index.write_text('{}')
            with self.assertRaises(ValueError):roles.check_stability(observations,index,False,None)
            digest=roles.sha(index);roles.check_stability(observations,index,True,digest)
            index.write_text('{"changed":true}')
            with self.assertRaises(ValueError):roles.check_stability(observations,index,True,digest)
            index.unlink()
            with self.assertRaises(ValueError):roles.check_stability(observations,index,True,digest)
    def test_wrong_original_cleanup_pointer_rejected(self):
        args=list(state_fixture());original=bytearray(args[3]);struct.pack_into('<I',original,12,0x400999)
        with self.assertRaises(ValueError):roles.parse_states(args[0],3,args[1],args[2],bytes(original),0x401000,args[4],PARENT)
    def test_stale_association_rejected_before_observation(self):
        proof=dict(address=PARENT,symbol='_parent',verdict='match',section=1,value=0)
        coff=SimpleNamespace(named=lambda _:dict(section=1,value=0))
        receipt=dict(verified_functions=[proof])
        with patch.object(roles,'native_pieces',return_value=[(2,0,8,[0x400200,0x400208,True,PARENT,[]])]),patch.object(roles,'physical_parent',return_value=dict(section=99,exact_body_verified_same_object=True)):
            with self.assertRaises(ValueError):roles.observe_parent(coff,None,None,{},receipt,PARENT,'_parent',{})
    def test_frame_recognizer_does_not_guess_this_or_source_role(self):
        # Authored generic x86 instruction patterns, never executed.
        short=bytes((0x8b,0x4d,0xf0,0xe9,0,0,0,0))
        long=bytes((0x8b,0x4d,0xf0,0x83,0xc1,0x34,0xe9,0,0,0,0))
        a=roles.frame_observation(short,[(4,0,20)]);b=roles.frame_observation(long,[(7,0,20)])
        self.assertEqual(a['ebp_slot'],-16);self.assertEqual(b['ecx_adjustment'],0x34)
        self.assertFalse(b['parent_this_origin_verified']);self.assertFalse(b['source_member_role_verified'])
        self.assertEqual(roles.frame_observation(b'prefix'+short,[(10,0,20)])['status'],'unknown-shape')
    def test_nonrelocation_failure_is_retained(self):
        r=roles.compare_content(bytes(8),bytes((1,0,0,0,0,0,0,0)),[(4,0,20)])
        self.assertFalse(r['nonrelocation_match']);self.assertEqual(r['nonrelocation_differences'],1)
        with self.assertRaises(ValueError):roles.compare_content(bytes(8),bytes(8),[(4,0,7)])
    def test_stale_bound_input_and_existing_output_rejected(self):
        with tempfile.TemporaryDirectory() as d:
            folder=Path(d);paths=[]
            for n in range(5):p=folder/str(n);p.write_text('{}');paths.append(p)
            with self.assertRaises(ValueError):roles.load_bound(paths[0],'0'*64)
            with self.assertRaises(ValueError):roles.observe(*paths)

if __name__=='__main__':unittest.main()
