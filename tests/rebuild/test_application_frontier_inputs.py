"""Synthetic input joins only; no native command or original game input."""
import copy
from pathlib import Path
import sys
import unittest

sys.path.insert(0,str(Path(__file__).resolve().parents[2]/'tools/rebuild'))
import application_frontier_inputs as inputs
from test_import_kernel32_nine import request_and_parse, fixture as import_fixture

def conformance():
    rows=[]
    for label,(sha,members,exports,relocs) in inputs.COMPONENTS.items():
        if label=='eh-file':facts=dict(all_native_metadata_matches=True,relocations=relocs)
        else:facts=dict(complete_native_linker_index=True,members=members,exports=exports,
            objects=[dict(all_native_metadata_matches=True,relocations=relocs if index==0 else 0) for index in range(members)])
        rows.append(dict(label=label,kind='object' if label=='eh-file' else 'archive',input_sha256=sha,native_metadata_matches=True,facts=facts))
    return dict(schema_version=1,kind='application-additional-code-native-conformance-v1',status='pass',
        input_stability_verified=True,components=rows,**{key:False for key in inputs.FALSE_OPERATIONS})

def native():
    request,parsed=request_and_parse()
    request['inputs']={key+'_sha256':value for key,value in inputs.nine.PINS.items()}
    request['source_sha256']=dict(inputs.nine.HELPER_PINS,**{'tools/rebuild/import_kernel32_nine.py':inputs.NINE_SOURCE})
    sha='a'*64
    receipt=inputs.nine.reconcile(request,parsed,sha)
    receipt['all_inputs_tools_sources_stable']=True
    return receipt,request,sha,parsed

def census27():
    catalog=import_fixture()[0];proposals=[];fields=[];imports=[];index=[]
    for number,cell in enumerate(catalog['imports']):
        name=cell['export']['name'];symbol='_'+name;pointer='__imp_'+symbol;offset=100+number*100
        canonical=inputs.nine.projection.unresolved(cell['original_IAT_va'],'iat-cell')
        proposals.append(dict(canonical_IAT_symbol=canonical,original_IAT_va=cell['original_IAT_va'],
            dll=cell['dll'],export=dict(kind='name',name=name),library='fixture.lib',member_offset=offset,
            proposed_pointer_symbol=pointer,pointer_indirection_preserved=True,alias_applied=False,
            runtime_provider_adopted=False,source_ABI_approved=False))
        fields.append(dict(component='fixture',member='body%d.obj'%number,offset=4,canonical=canonical,undefined=True,kind=6,
            proof=dict(role='iat-cell',original_base=cell['original_IAT_va'],original_target=cell['original_IAT_va'],
                addend_bits=0,classification='IAT_POINTER_CELL_NOT_FUNCTION_BODY',import_id=cell['import_id'])))
        imports.append(dict(dll=cell['dll'],export=dict(kind='name',name=name),machine=0x14c,import_type=0,name_type=2,
            symbol=symbol,pointer_symbol=pointer,member_offset=offset))
        index.extend([dict(symbol=symbol,member_offset=offset),dict(symbol=pointer,member_offset=offset)])
    return proposals,fields,catalog,{'fixture.lib':dict(imports=imports,index=index)}

class InputTests(unittest.TestCase):
    def test_exact_three_components(self):
        self.assertEqual(set(inputs.native_component_scope(conformance())),set(inputs.COMPONENTS))
    def test_duplicate_or_missing_native_component_rejected(self):
        for duplicate in (True,False):
            receipt=conformance()
            if duplicate:receipt['components'][2]=copy.deepcopy(receipt['components'][0])
            else:receipt['components'].pop()
            with self.assertRaises(ValueError):inputs.native_component_scope(receipt)
    def test_failed_or_unmatched_or_promoted_conformance_rejected(self):
        for kind in ('failed','hash','promotion'):
            receipt=conformance()
            if kind=='failed':receipt['status']='failed'
            if kind=='hash':receipt['components'][0]['input_sha256']='0'*64
            if kind=='promotion':receipt['provider_selected']=True
            with self.assertRaises(ValueError):inputs.native_component_scope(receipt)
    def test_nine_receipt_replays_fresh_parser_evidence(self):
        args=native();self.assertEqual(len(inputs.native_nine_evidence(*args)['proposed_pointer_aliases']),27)
    def test_unrelated_stale_library_or_failed_receipt_rejected(self):
        for kind in ('request','library','stability','status','pointer'):
            args=list(native());receipt=args[0]
            if kind=='request':receipt['request_sha256']='b'*64
            if kind=='library':receipt['library']['sha256']='b'*64
            if kind=='stability':receipt['all_inputs_tools_sources_stable']=False
            if kind=='status':receipt['status']='failed'
            if kind=='pointer':receipt['old_eight_pointer_identities_preserved']=False
            with self.assertRaises(ValueError):inputs.native_nine_evidence(*args)
    def test_changed_original_evidence_or_source_rejected(self):
        for key in ('inputs','source_sha256'):
            args=list(native());args[1][key]={}
            with self.assertRaises(ValueError):inputs.native_nine_evidence(*args)
    def test_different_actual_member_or_export_not_adopted(self):
        args=list(native());args[3]['imports'][0]['pointer_symbol']='__imp__other'
        with self.assertRaises(ValueError):inputs.native_nine_evidence(*args)
    def test_native_member_or_field_count_drift_rejected(self):
        for key,value in [('members',4),('exports',4)]:
            receipt=conformance();receipt['components'][0]['facts'][key]=value
            with self.assertRaises(ValueError):inputs.native_component_scope(receipt)
        receipt=conformance();receipt['components'][2]['facts']['relocations']=11
        with self.assertRaises(ValueError):inputs.native_component_scope(receipt)
    def test_actual_twenty_seven_proposal_integration_includes_last_cell(self):
        rows=inputs.frontier_alias_census(*census27())
        self.assertEqual(len(rows),27);self.assertTrue(all(row['enabled'] for row in rows))
        self.assertEqual(rows[-1]['positive_import_identity'],('KERNEL32.dll','name','GetTickCount'))
    def test_one_unproved_cell_disables_only_its_global_alias(self):
        args=list(census27());args[1][11]['proof']['addend_bits']=4
        rows=inputs.frontier_alias_census(*args)
        self.assertFalse(rows[11]['enabled']);self.assertEqual(sum(row['enabled'] for row in rows),26)
    def test_missing_or_duplicate_twenty_seventh_proposal_rejected(self):
        for duplicate in (True,False):
            args=list(census27())
            if duplicate:args[0][-1]=copy.deepcopy(args[0][0])
            else:args[0].pop()
            with self.assertRaises(ValueError):inputs.frontier_alias_census(*args)

if __name__=='__main__':unittest.main()
