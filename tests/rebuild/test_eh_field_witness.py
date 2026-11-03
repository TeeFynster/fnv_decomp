"""Authored field fixtures; no native collector/retry or code execution."""
import copy
from pathlib import Path
import struct
import sys
import unittest
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'tools/rebuild'))
import eh_field_witness as witness
import test_eh_code_closure as authored
import test_eh_code_observe as collector_tests
import eh_code_observe as collector


def fixture():
    obj,raw,p,c,original=authored.fixture();data=bytearray(obj['sections'][4]['payload']);data[30]=0xe9;obj['sections'][4]['payload']=bytes(data)
    raw=authored.encode(obj);base=0xeec248;target=0xec3d33
    class Reference:
        patches={0xeec240+30:0xe9,**{0xeec240+31+i:b for i,b in enumerate(struct.pack('<i',target-(0xeec240+31+4)))}}
        def read(self,address,size):
            if (address,size)==(target,1):return bytes([0x90])
            data=bytearray(original.read(address,size))
            for pos,value in self.patches.items():
                if address<=pos<address+size:data[pos-address]=value
            return bytes(data)
    recipes=[dict(source='authored-placeholder.cpp',symbols={},functions=[]) for _ in range(854)]
    for record in witness.RESOLVERS:
        recipes[record['recipe_index']].update(source=record['source'],symbols={witness.NAME:record['original_base']})
    audit=dict(inputs=dict(object_sha256=authored.eh.sha(raw),reference_sha256='b'*64,recipes_sha256='c'*64),
        resolver=dict(records=copy.deepcopy(witness.RESOLVERS),own_recipe_explicit_mapping=None),
        field=dict(resolved_original_symbol_base=target,source_addend=0,original_target_first_byte=0x90))
    context=dict(parent_proof=c['parent_proof'],pieces=c['eh_pieces'],recipe=dict(symbols={}),recipes=recipes,
        names={witness.NAME:target,'@__security_check_cookie@4':0x501100},inferred={},object_sha256=authored.eh.sha(raw),reference_sha256='b'*64,recipes_sha256='c'*64,audit=audit,
        original_highlow_sites=[base+18,0x11401cc+4,0x11401cc+16],target_section=dict(executable=True,original_base=0xec0000,original_end=0xed0000))
    return obj,Reference(),context


class HandlerWitnessTests(unittest.TestCase):
    def test_exact_three_fields_state_and_four_resolvers(self):
        obj,reference,context=fixture();proof=witness.build(obj,reference,context)
        self.assertEqual(proof['family'],witness.FAMILY);self.assertEqual(len(proof['fields']),3);self.assertEqual(len(proof['resolver_records']),4)
        self.assertEqual((proof['symbol_index'],proof['base'],proof['contract_kind']),(20,0xec3d33,'cxx-frame-handler'))
        self.assertEqual(proof['proof_consistency'],'EXACT_GENERATED_HANDLER_FIELD_RESOLUTION');self.assertNotEqual(proof['proof_consistency'],'EXACT_OWN_SOURCE_RESOLUTION')
        self.assertFalse(proof['function_boundary_verified']);self.assertFalse(proof['provider_selected'])
    def test_false_foreign_or_wrong_handler_piece(self):
        for mode in ('false','foreign','extent','parent','handler-name','association'):
            obj,reference,c=fixture()
            if mode=='false':c['pieces'][1][2]=False
            elif mode=='foreign':c['pieces'][1][3]='0x0043fd40'
            elif mode=='extent':c['pieces'][1][1]+=1
            elif mode=='parent':c['parent_proof']['verdict']='different'
            elif mode=='handler-name':obj['symbols'][19]['name']='__ehhandler$foreign'
            else:
                aux=bytearray(obj['symbols'][10]['aux']);struct.pack_into('<h',aux,12,5);obj['symbols'][10]['aux']=bytes(aux)
            with self.assertRaises(ValueError):witness.build(obj,reference,c)
    def test_complete_asymmetric_relocation_inventory(self):
        for mode in ('extra-handler','missing-handler','extra-state','extra-original','missing-original','partial-original'):
            obj,reference,c=fixture()
            if mode=='extra-handler':obj['sections'][4]['relocs'].append((12,18,6))
            elif mode=='missing-handler':obj['sections'][4]['relocs'].pop()
            elif mode=='extra-state':obj['sections'][6]['relocs'].append((28,12,6))
            elif mode=='extra-original':c['original_highlow_sites'].append(0xeec248)
            elif mode=='missing-original':c['original_highlow_sites'].remove(0xeec248+18)
            else:c['original_highlow_sites'].append(0xeec248-2)
            with self.assertRaises(ValueError):witness.build(obj,reference,c)
    def test_unknown_symbol_nonfunction_aux_or_changed_native_field(self):
        for mode in ('name','type','aux','offset','addend','nonfield','opcode','destination','state'):
            obj,reference,c=fixture()
            if mode=='name':obj['symbols'][20]['name']='___unknown_handler'
            elif mode=='type':obj['symbols'][20]['type']=0
            elif mode=='aux':obj['symbols'][20]['aux_count']=1
            elif mode=='offset':obj['sections'][4]['relocs'][-1]=(30,20,20)
            elif mode=='addend':
                data=bytearray(obj['sections'][4]['payload']);struct.pack_into('<i',data,31,1);obj['sections'][4]['payload']=bytes(data)
            elif mode=='nonfield':reference.patches[0xeec248+3]=1
            elif mode=='opcode':
                data=bytearray(obj['sections'][4]['payload']);data[30]=0xe8;obj['sections'][4]['payload']=bytes(data)
            elif mode=='destination':reference.patches[0xeec240+31]^=1
            else:
                data=bytearray(obj['sections'][6]['payload']);struct.pack_into('<I',data,12,2);obj['sections'][6]['payload']=bytes(data)
            with self.assertRaises(ValueError):witness.build(obj,reference,c)
    def test_resolver_and_audit_and_target_constraints(self):
        for mode in ('absent','conflict','additional','own-fabrication','audit-hash','audit-target','nonexec','outside'):
            obj,reference,c=fixture()
            if mode=='absent':c['recipes'][130]['symbols']={}
            elif mode=='conflict':c['recipes'][130]['symbols'][witness.NAME]='0x00123456'
            elif mode=='additional':c['recipes'][1]['symbols'][witness.NAME]='0x00ec3d33'
            elif mode=='own-fabrication':c['recipe']['symbols'][witness.NAME]='0x00ec3d33'
            elif mode=='audit-hash':c['audit']['inputs']['object_sha256']='a'*64
            elif mode=='audit-target':c['audit']['field']['resolved_original_symbol_base']+=1
            elif mode=='nonexec':c['target_section']['executable']=False
            else:c['target_section']['original_end']=0xec3d33
            with self.assertRaises(ValueError):witness.build(obj,reference,c)

    def test_collector_bridge_only_for_exact_missing_physical20(self):
        obj,reference,bridge=fixture();_,p,names,parent_fields,shared=collector_tests.CollectorBoundaryTests().context()
        names[witness.NAME]=0xec3d33;shared.pop(0x501200);proofs=[];bridge['reference']=reference
        bindings,ledger=collector.external_context(obj,p,parent_fields,{},names,{},shared,bridge,proofs)
        self.assertEqual(len(proofs),1);self.assertEqual(bindings['20']['base'],0xec3d33)
        self.assertEqual(proofs[0]['family'],witness.FAMILY)
        shared.pop(0x501100)
        with self.assertRaises(ValueError):collector.external_context(obj,p,parent_fields,{},names,{},shared,bridge,[])
    def test_consumer_preserves_bridge_identity_and_rejects_changed_fields(self):
        obj,reference,bridge=fixture();_,_,p,c,_=authored.fixture();raw=authored.encode(obj)
        p['object_sha256']=c['object_sha256']=authored.eh.sha(raw);c['reference_identity_sha256']=bridge['reference_sha256']
        c['external_bindings']['20']['base']=0xec3d33
        for row in c['shared_base_identities']:
            if row['contract_kind']=='cxx-frame-handler':row['base']=0xec3d33
        c['core_unit']['symbols'][witness.NAME]='0x00ec3d33'
        bridge['recipes_sha256']=p['inputs']['recipes'];bridge['audit']['inputs']['recipes_sha256']=p['inputs']['recipes']
        proof=witness.build(obj,reference,bridge)
        c['generated_eh_field_witnesses']=[proof];c['external_bindings']['20']['proof_consistency']=proof['proof_consistency']
        plan=authored.eh.observe_component(raw,p,c,reference)
        contract=authored.contract_for(plan);authored.eh.check_contract(plan,contract)
        for mode in ('missing-sha','missing-container','wrong-field','unknown-family','own-source-mask'):
            changed=copy.deepcopy(plan);changed_contract=copy.deepcopy(contract)
            if mode=='missing-sha':changed_contract['provenance'].pop('generated_eh_field_witnesses_sha256')
            elif mode=='missing-container':changed_contract.pop('generated_eh_field_witnesses')
            elif mode=='wrong-field':changed['generated_eh_field_witnesses'][0]['fields'][2]['original_target']+=1
            elif mode=='unknown-family':changed['generated_eh_field_witnesses'][0]['family']='unknown'
            else:
                changed['generated_eh_field_witnesses'][0]['proof_consistency']='EXACT_OWN_SOURCE_RESOLUTION'
                changed_contract['generated_eh_field_witnesses']=copy.deepcopy(changed['generated_eh_field_witnesses'])
                changed_contract['provenance']['generated_eh_field_witnesses_sha256']=authored.eh.digest(changed['generated_eh_field_witnesses'])
            with self.assertRaises(ValueError):authored.eh.check_contract(changed,changed_contract)

if __name__=='__main__':unittest.main()
