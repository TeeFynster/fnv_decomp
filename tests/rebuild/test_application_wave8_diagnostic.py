"""Authored V8 response/native-scope/proof-view joins; no native execution."""
import copy
from pathlib import Path
import sys
import unittest

sys.path.insert(0,str(Path(__file__).resolve().parents[2]/'tools/rebuild'))
import application_wave8_diagnostic as planner
from test_application_frontier_inputs import census27
from test_iat_field_annotations import fixture as annotation_fixture

def response():
    old=Path('old');out=Path('new');iat=['/ALTERNATENAME:iat%d=pointer%d'%(i,i) for i in range(27)]
    crt=['/ALTERNATENAME:crt%d=normal%d'%(i,i) for i in range(4)]
    tokens=['/NOLOGO','/OUT:'+str(old/'diagnostic.exe'),'/MAP:'+str(old/'diagnostic.map'),'retained.lib']+iat+crt
    return dict(text='\n'.join('"'+token+'"' for token in tokens),old_out=old,out=out,additions=['CODE59.lib','ModelLoader.obj'],
        prior_IAT=iat,prior_CRT=crt,new_IAT=list(iat),new_CRT=list(crt))

def native(archive=True):
    facts=dict(complete_native_linker_index=True,members=59,exports=59,
        objects=[dict(all_native_metadata_matches=True,relocations=723 if index==0 else 0) for index in range(59)]) if archive else dict(all_native_metadata_matches=True,sections=5,primary_records=40,auxiliary_records=5,relocations=52)
    return dict(schema_version=1,kind='fixture-conformance',status='pass',input_stability_verified=True,
        components=[dict(label='fixture',kind='archive' if archive else 'object',input_sha256='a'*64,native_metadata_matches=True,facts=facts)],
        **{key:False for key in planner.joins.FALSE_OPERATIONS})

class Wave8Tests(unittest.TestCase):
    def test_only_two_new_inputs_and_destinations_change(self):
        args=response();tokens=planner.response_tokens(**args)
        self.assertIn('retained.lib',tokens);self.assertIn('CODE59.lib',tokens);self.assertIn('ModelLoader.obj',tokens)
        self.assertEqual(tokens[1],'/OUT:'+str(Path('new')/'diagnostic.exe'))
        self.assertEqual(sum(token.startswith('/ALTERNATENAME:') for token in tokens),31)
    def test_disabled_subsets_remove_inherited_aliases(self):
        args=response();removed=args['new_IAT'].pop();args['new_CRT']=args['prior_CRT'][2:]
        tokens=planner.response_tokens(**args)
        self.assertNotIn(removed,tokens);self.assertFalse(set(args['prior_CRT'][:2]).intersection(tokens))
    def test_no_new_or_conflicting_alias_is_accepted(self):
        for mode in ('IAT','CRT'):
            args=response();args['new_'+mode].append('/ALTERNATENAME:new=unreviewed')
            with self.assertRaises(ValueError):planner.response_tokens(**args)
    def test_ignored_errors_or_unreviewed_inputs_rejected(self):
        for mode in ('force','duplicate'):
            args=response()
            if mode=='force':args['text']+='\n"/FORCE"'
            else:args['additions'][0]='retained.lib'
            with self.assertRaises(ValueError):planner.response_tokens(**args)
    def test_exact_native_archive_and_ModelLoader_scopes(self):
        planner.native_scope(native(),'fixture','fixture-conformance','a'*64,59,723)
        planner.native_scope(native(False),'fixture','fixture-conformance','a'*64,0,52)
    def test_native_wrong_kind_hash_members_or_relocations_rejected(self):
        for mode in ('hash','members','fields','promotion','extra'):
            receipt=native()
            if mode=='hash':receipt['components'][0]['input_sha256']='b'*64
            if mode=='members':receipt['components'][0]['facts']['members']=58
            if mode=='fields':receipt['components'][0]['facts']['objects'][0]['relocations']=722
            if mode=='promotion':receipt['ABI_verified']=True
            if mode=='extra':receipt['components']*=2
            with self.assertRaises(ValueError):planner.native_scope(receipt,'fixture','fixture-conformance','a'*64,59,723)
    def test_actual_27_proposal_census_uses_immutable_original_rows(self):
        args=census27();saved=copy.deepcopy(args)
        result=planner.wave8_alias_census(*args)
        self.assertTrue(all(row['enabled'] for row in result));self.assertEqual(args,saved)
        self.assertTrue(all(row['compact_proofs_preserved'] for row in result))
    def test_hydrated_proof_tags_enable_cell_without_mutating_compact_witness(self):
        proposals,fields,catalog,libraries=census27()
        rows,proofs,one_catalog,locations=annotation_fixture();full=next(iter(proofs.values()))
        full['import_id']=1000;one_catalog['imports'][0]['import_id']=1000
        sha=planner.iat_annotations.digest(full);rows[0]['proof']['field_proof_sha256']=sha
        annotated=planner.iat_annotations.annotate(rows,{sha:full},one_catalog,[planner.iat_annotations.location(rows[0])])[0]
        fields[0]=annotated;catalog['imports'][0]=one_catalog['imports'][0]
        proposals[0].update(dll='fixture.dll',export=dict(kind='name',name='RealExport'),proposed_pointer_symbol='__imp__RealExport')
        libraries['fixture.lib']['imports'][0].update(dll='fixture.dll',export=dict(kind='name',name='RealExport'),symbol='_RealExport',pointer_symbol='__imp__RealExport')
        libraries['fixture.lib']['index'][0]['symbol']='_RealExport';libraries['fixture.lib']['index'][1]['symbol']='__imp__RealExport'
        result=planner.wave8_alias_census(proposals,fields,catalog,libraries)
        self.assertTrue(all(row['enabled'] for row in result));self.assertNotIn('classification',fields[0]['proof'])
        self.assertEqual(result[0]['complete_actual_uses'],[annotated])

if __name__=='__main__':unittest.main()
