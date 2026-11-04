"""Synthetic relocation preservation failures; no native tools or game bytes."""
import copy
from pathlib import Path
import sys
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[2] / 'tools/rebuild'))
import application_link_frontier as frontier
from test_application_link_cohort import obj

def fixture():
    return dict(component='fixture', member='authored.obj',
        root=dict(recipe_id='fixture', object_sha256='a'*64, original_address='0x00401000',
            symbol_index=10, section=7, value=0, size=128),
        maps=dict(section_map={'7':1}, symbol_map={'10':0,'11':1}, auxiliary_map={}),
        fields=[dict(physical_section=7,field_offset=4,symbol_index=11,kind=6,addend_bits=0,
            canonical_name='target',role='data',original_base='0x02000000',original_target='0x02000000')],
        owned_sections={'7'}, owned_ranges=[(7,0,128)], exports=['root'])

class FrontierTests(unittest.TestCase):
    def test_exact_one_field_preserves_both_symbol_indices(self):
        providers, fields = frontier.mapped_fields(obj(), **fixture())
        self.assertEqual(providers[0]['symbol_index'],10)
        self.assertEqual((fields[0]['physical_symbol_index'],fields[0]['symbol_index']),(11,1))
        self.assertEqual(fields[0]['proof']['original_target'],'0x02000000')
    def test_duplicate_field_is_not_silently_coalesced(self):
        args=fixture();args['fields']*=2
        with self.assertRaises(ValueError):frontier.mapped_fields(obj(),**args)
    def test_unvisited_relocation_is_rejected(self):
        args=fixture();args['fields']=[]
        with self.assertRaises(ValueError):frontier.mapped_fields(obj(),**args)
    def test_unrelated_companion_section_not_attributed_to_parent(self):
        args=fixture();args['owned_sections']={'9'}
        with self.assertRaises(ValueError):frontier.mapped_fields(obj(),**args)
    def test_operand_or_name_or_target_index_drift_rejected(self):
        for change in ({'addend_bits':4},{'canonical_name':'different'},{'symbol_index':10}):
            args=fixture();args['fields'][0].update(change)
            with self.assertRaises(ValueError):frontier.mapped_fields(obj(),**args)
    def test_primary_or_auxiliary_mapping_collision_rejected(self):
        for key,value in [('symbol_map',{'10':0,'11':0}),('auxiliary_map',{'12':2})]:
            args=fixture();args['maps'][key]=value
            with self.assertRaises(ValueError):frontier.mapped_fields(obj(),**args)
    def test_extra_provider_rejected(self):
        args=fixture();args['exports']=['root','target']
        with self.assertRaises(ValueError):frontier.mapped_fields(obj(),**args)
    def test_whole_four_byte_field_must_fit_certified_range(self):
        args=fixture();args['owned_ranges']=[(7,0,7)]
        with self.assertRaisesRegex(ValueError,'whole field'):frontier.mapped_fields(obj(),**args)
    def test_unrelated_same_section_field_not_attributed_to_root(self):
        args=fixture();args['root'].update(value=8,size=120);args['owned_ranges']=[(7,8,128)]
        # Keep the physical definition at zero: first verify the root mismatch.
        with self.assertRaises(ValueError):frontier.mapped_fields(obj(),**args)
        args=fixture();args['root']['size']=4;args['owned_ranges']=[(7,0,4)]
        with self.assertRaisesRegex(ValueError,'whole field'):frontier.mapped_fields(obj(),**args)
    def test_ordinary_original_object_mismatch_rejected(self):
        args=fixture()
        projection=dict(output_sha256=frontier.digest(obj()),requested_roots=[args['root']],
            original_object_sha256='b'*64,maps=args['maps'])
        projection.update({k:False for k in ('compiler_performed','native_tools_run','executable_link_performed',
            'game_execution_performed','provider_selected','runtime_eligible','link_ready','ABI_verified')})
        with self.assertRaisesRegex(ValueError,'original root/object'):
            frontier.ordinary_member(obj(),dict(name='authored.obj',projection=projection),component='fixture')
    def test_EH_annotation_extension_retains_original_fields(self):
        original=[dict(section=7,offset=4,kind=6),dict(section=7,offset=8,kind=20)]
        annotated=[dict(x,role='annotation') for x in original]
        frontier.require_field_ancestry(annotated,original)
    def test_EH_changed_missing_reordered_and_removed_field_rejected(self):
        original=[dict(section=7,offset=4,kind=6),dict(section=7,offset=8,kind=20)]
        for change in ('changed','missing','reordered','removed'):
            actual=copy.deepcopy(original)
            if change=='changed':actual[0]['offset']=5
            if change=='missing':del actual[0]['kind']
            if change=='reordered':actual.reverse()
            if change=='removed':actual.pop()
            with self.assertRaisesRegex(ValueError,'original field'):frontier.require_field_ancestry(actual,original)
    def EH_identity(self):
        identity=dict(base=1234,contract_kind='security-cookie',proof_consistency='EXACT_OWN_SOURCE_RESOLUTION',
            role='data',semantic_domain='data',symbol='___security_cookie',symbol_index=11)
        return dict(external_identity=identity,target_index=11,original_base=1234),[dict(identity,output_symbol='canonical',output_symbol_index=1)]
    def test_EH_seven_key_source_joins_exact_nine_key_serialized_record(self):
        witness, records=self.EH_identity()
        self.assertEqual(frontier.EH_external_identity(witness,records,'canonical',1),witness['external_identity'])
    def test_EH_identity_extension_or_changed_source_or_output_rejected(self):
        for change in ('source','new_key','output','index','duplicate'):
            witness,records=self.EH_identity()
            if change=='source':records[0]['symbol']='other'
            if change=='new_key':records[0]['unexpected']=True
            if change=='output':records[0]['output_symbol']='other'
            if change=='index':records[0]['output_symbol_index']=2
            if change=='duplicate':records*=2
            with self.assertRaises(ValueError):frontier.EH_external_identity(witness,records,'canonical',1)

if __name__=='__main__':unittest.main()
