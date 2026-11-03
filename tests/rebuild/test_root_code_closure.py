"""Authored COFF metadata; no original objects, compiler or native calls."""
import copy
from pathlib import Path
import struct
import sys
import unittest
sys.path.insert(0,str(Path(__file__).resolve().parents[2]/'tools/rebuild'))
import root_code_closure as c


def sym(obj,name,section,value=0,typ=0,storage=2,aux=b''):
    i=obj['symbol_count'];obj['symbol_count']+=1+len(aux)//18
    obj['symbols'][i]=dict(name=name,section=section,value=value,type=typ,storage=storage,aux=aux,aux_count=len(aux)//18);return i


def section(obj,name,payload,flags,relocs=(),selection=0,parent=0):
    i=len(obj['sections'])+1;obj['sections'][i]=dict(name=name,size=len(payload),flags=flags,payload=payload,relocs=list(relocs))
    aux=struct.pack('<IHHIhBBH',len(payload),len(relocs),0,0,parent,selection,0,0)
    sym(obj,name,i,storage=3,aux=aux);return i


def fixture():
    obj=dict(sections={},symbols={},symbol_count=0)
    root=section(obj,'.text',bytes(16),0x60501020,selection=1)
    ri=sym(obj,'_authored_root',root,typ=32);target=sym(obj,'_authored_data',0)
    obj['sections'][root]['relocs']=[(4,target,6)]
    obj['symbols'][0]['aux']=struct.pack('<IHHIhBBH',16,1,0,0,0,1,0,0)
    section(obj,'.drectve',b'   /DEFAULTLIB:"LIBCMT" /DEFAULTLIB:"OLDNAMES" ',0x100a00)
    sym(obj,'@feat.00',-1,value=1,storage=3)
    s=obj['symbols'][target]
    row=dict(recipe_id='authored',function_va='0x00500000',physical_section=1,physical_offset=4,source_field_offset=4,
        coff_relocation=dict(offset=4,symbol_index=target,kind=6,symbol=s['name'],symbol_section=0,symbol_value=0,symbol_type=0,symbol_storage=2,addend=0),
        derived_source_symbol_base_va='0x00600000',exact_original_target_va='0x00600000',classification='ORIGINAL_IMAGE_DATA_REQUIRES_CANONICAL_OWNER',
        physical_field_overlap_count=1,proof_consistency='EXACT_OWN_SOURCE_RESOLUTION')
    contract=dict(recipe_id='authored',roots=[dict(original_address='0x00500000',symbol='_authored_root',symbol_index=ri,section=1,value=0,size=16)],
        provenance=dict(object_sha256='a'*64,source_sha256='b'*64),export_policy=c.EXPORT_POLICY,fields_complete=True,missing_fields_complete=True,
        verified_match=True,fields=[row],missing_fields=[],parent_eh=[],unit_proofs_complete=True,omission_field_proofs=[],
        unit_verified_functions=[dict(symbol='_authored_root',address='0x00500000',size=16,section=1,value=0,verdict='match')],iat_import_observation={})
    return obj,contract


def retarget(obj,contract,idx):
    obj['sections'][1]['relocs']=[(4,idx,6)];s=obj['symbols'][idx];r=contract['fields'][0]['coff_relocation']
    r.update(symbol_index=idx,symbol=s['name'],symbol_section=s['section'],symbol_value=s['value'],symbol_type=s['type'],symbol_storage=s['storage'])


def weak(obj,name='_unused_weak',fallback=None,search=2):
    if fallback is None:fallback=sym(obj,'_unused_fallback',0,typ=32)
    return sym(obj,name,0,typ=32,storage=105,aux=struct.pack('<II10s',fallback,search,bytes(10)))



def omitted_function(obj,contract,address='0x00500100'):
    si=obj['symbol_count'];sec=section(obj,'.text',bytes(16),0x60501020,selection=1)
    fn=sym(obj,'_omitted_owner'+str(sec),sec,typ=32)
    contract['unit_verified_functions'].append(dict(symbol=obj['symbols'][fn]['name'],address=address,size=16,section=sec,value=0,verdict='match'))
    return sec,si,fn


def omission_field(obj,contract,sec,section_symbol,idx,mode):
    obj['sections'][sec]['relocs'].append((8,idx,6));s=obj['symbols'][idx]
    obj['symbols'][section_symbol]['aux']=struct.pack('<IHHIhBBH',16,len(obj['sections'][sec]['relocs']),0,0,0,1,0,0)
    owner=next(f for f in contract['unit_verified_functions'] if f['section']==sec)
    base='0x%08x'%(int(owner['address'],16)+s['value']) if mode=='label' else '0x00fdf2fc'
    row=dict(recipe_id='authored',function_va=owner['address'],physical_section=sec,physical_offset=8,source_field_offset=8,
        original_field_va='0x%08x'%(int(owner['address'],16)+8),
        coff_relocation=dict(offset=8,symbol_index=idx,kind=6,symbol=s['name'],symbol_section=s['section'],symbol_value=s['value'],symbol_type=s['type'],symbol_storage=s['storage'],addend=0),
        derived_source_symbol_base_va=base,exact_original_target_va=base,physical_field_overlap_count=1,proof_consistency='EXACT_OWN_SOURCE_RESOLUTION',
        classification='UNIQUE_CODE_INTERIOR_OR_LOCAL_LABEL_NOT_CALLABLE_APPROVAL' if mode=='label' else 'IAT_POINTER_CELL_NOT_FUNCTION_BODY')
    if mode=='iat':row['import_id']=175
    contract['omission_field_proofs'].append(row);return row


def label_fixture():
    obj,contract=fixture();sec,ss,fn=omitted_function(obj,contract);label=sym(obj,'$LN1',sec,value=4,storage=6)
    omission_field(obj,contract,sec,ss,label,'label');return obj,contract,label


def iat_fixture():
    obj,contract=fixture();obj['symbols'][3]['name']=c.IAT_SOURCE_NAME;r=contract['fields'][0]
    r.update(original_field_va='0x00500004',import_id=175,derived_source_symbol_base_va='0x00fdf2fc',exact_original_target_va='0x00fdf2fc',classification='IAT_POINTER_CELL_NOT_FUNCTION_BODY')
    r['coff_relocation']['symbol']=c.IAT_SOURCE_NAME
    contract['omission_field_proofs'].append(copy.deepcopy(r))
    sec,ss,fn=omitted_function(obj,contract);duplicate=sym(obj,c.IAT_SOURCE_NAME,0)
    omission_field(obj,contract,sec,ss,duplicate,'iat')
    contract['iat_import_observation']=dict(import_id=175,original_IAT_va='0x00fdf2fc',dll='USER32.dll',
        export=dict(kind='name',name='GetActiveWindow',hint=249),representation='IAT_POINTER_CELL_NOT_FUNCTION_BODY',
        required_provider_contract=dict(runtime_provider_selected=False))
    return obj,contract,duplicate

def codes(result):return {b['code'] for b in result['blockers']}


class RootClosureTests(unittest.TestCase):
    def test_complete_positive_certificate_retains_all_required_indices(self):
        o,k=fixture();r=c.assess_object(o,k)
        self.assertTrue(r['closure_observed']);self.assertEqual(r['retained_primary_indices'],[0,2,3,4,6])
        self.assertEqual(r['retained_physical_slots'],list(range(7)));self.assertEqual(r['exported_primary_indices'],[2])
        self.assertEqual(len(r['symbols']),len(o['symbols']));self.assertFalse(r['namespace_approved'])

    def test_unused_known_weak_omitted_with_aux(self):
        o,k=fixture();wi=weak(o);r=c.assess_object(o,k)
        self.assertTrue(r['closure_observed']);self.assertNotIn(wi,r['retained_primary_indices'])
        self.assertEqual(next(s for s in r['symbols'] if s['index']==wi)['decoded_auxiliary']['kind'],'WEAK_EXTERNAL')

    def test_direct_weak_and_fallback_chain_remain_blocked(self):
        o,k=fixture();inner=weak(o,'_inner');outer=weak(o,'_outer',inner);retarget(o,k,outer);r=c.assess_object(o,k)
        self.assertIn('REACHABLE_WEAK_REQUIRES_POLICY',codes(r));self.assertGreaterEqual(r['summary']['edges']['LIVE_WEAK_FALLBACK'],2)

    def test_same_name_physical_record_cannot_hide_live_weak(self):
        o,k=fixture();weak(o,'_authored_data');r=c.assess_object(o,k)
        self.assertIn('REACHABLE_WEAK_REQUIRES_POLICY',codes(r));self.assertIn('LIVE_NAME_RESOLUTION',r['summary']['edges'])

    def test_opaque_unused_auxiliary_still_blocks(self):
        o,k=fixture();sym(o,'_unknown',0,aux=bytes(18));self.assertIn('UNKNOWN_HIDDEN_AUXILIARY_INDICES',codes(c.assess_object(o,k)))

    def test_invalid_weak_index_or_search_or_reserved(self):
        for mode in ('index','search','reserved'):
            o,k=fixture();wi=weak(o);s=o['symbols'][wi]
            if mode=='index':s['aux']=struct.pack('<II10s',999,2,bytes(10))
            if mode=='search':s['aux']=struct.pack('<II10s',3,4,bytes(10))
            if mode=='reserved':s['aux']=struct.pack('<II10s',3,2,b'x'+bytes(9))
            self.assertIn('UNSUPPORTED_WEAK_AUXILIARY',codes(c.assess_object(o,k)))

    def test_weak_fallback_cycle_even_unreferenced_is_not_dropped(self):
        o,k=fixture();wi=weak(o);o['symbols'][wi]['aux']=struct.pack('<II10s',wi,2,bytes(10))
        self.assertIn('WEAK_FALLBACK_CYCLE',codes(c.assess_object(o,k)))

    def test_common_unrelated_vs_same_name_live(self):
        o,k=fixture();sym(o,'_unused_common',0,value=64);self.assertTrue(c.assess_object(o,k)['closure_observed'])
        sym(o,'_authored_data',0,value=4);r=c.assess_object(o,k)
        self.assertIn('REACHABLE_COMMON_REQUIRES_STORAGE_OWNER',codes(r))

    def test_root_alias_is_not_silently_dropped(self):
        o,k=fixture();alias=sym(o,'_other_entry',1,typ=32);section(o,'.sxdata',struct.pack('<I',alias),0x300200)
        r=c.assess_object(o,k);self.assertIn('UNPROVED_RETAINED_ENTRY_OR_ALIAS',codes(r));self.assertIn('LIVE_SAFESEH_HANDLER_REQUIRES_ADAPTER',codes(r))

    def test_unrelated_safeseh_whole_table_omission_positive(self):
        o,k=fixture();sec=section(o,'.text',bytes(8),0x60501020,selection=1);handler=sym(o,'_omitted_handler',sec,typ=32,storage=3)
        sx=section(o,'.sxdata',struct.pack('<I',handler),0x300200);r=c.assess_object(o,k)
        self.assertTrue(r['closure_observed']);self.assertEqual(r['safeseh'][0]['symbol_index'],handler);self.assertNotIn(sx,r['retained_section_indices'])

    def test_registered_root_and_mixed_table_block(self):
        o,k=fixture();sec=section(o,'.text',bytes(4),0x60501020,selection=1);h=sym(o,'_other',sec,typ=32)
        section(o,'.sxdata',struct.pack('<II',2,h),0x300200);self.assertIn('LIVE_SAFESEH_HANDLER_REQUIRES_ADAPTER',codes(c.assess_object(o,k)))

    def test_same_name_handler_dependency_not_hidden(self):
        o,k=fixture();sec=section(o,'.text',bytes(4),0x60501020,selection=1);h=sym(o,'_authored_data',sec,typ=32)
        section(o,'.sxdata',struct.pack('<I',h),0x300200);self.assertIn('LIVE_SAFESEH_HANDLER_REQUIRES_ADAPTER',codes(c.assess_object(o,k)))

    def test_graph_completeness_is_separate_from_extension_acceptance(self):
        o,k=fixture();section(o,'.sxdata',struct.pack('<I',2),0x300200)
        r=c.assess_object(o,k);self.assertTrue(r['graph_observation_complete']);self.assertFalse(r['root_closure_candidate'])
        sub=r['omission_subcertificate'];self.assertFalse(sub['omission_approved']);self.assertEqual(len(sub['exact_EH_SafeSEH_extension_obligation_ids']),1)
        o,k=fixture();sym(o,'_opaque',0,aux=bytes(18));self.assertFalse(c.assess_object(o,k)['graph_observation_complete'])

    def test_invalid_safeseh_aux_index_and_holey_table(self):
        for payload in (struct.pack('<I',1),b'bad'):
            o,k=fixture();section(o,'.sxdata',payload,0x300200);r=c.assess_object(o,k)
            self.assertTrue(codes(r)&{'INVALID_SAFESEH_INDEX','UNSUPPORTED_SAFESEH_TABLE'})

    def test_debug_child_positive_and_eh_child_blocked(self):
        o,k=fixture();section(o,'.debug$F',bytes(16),0x42101040,[(0,2,7)],selection=5,parent=1)
        r=c.assess_object(o,k);self.assertTrue(r['closure_observed']);self.assertEqual(r['sections'][-1]['disposition'],'OMIT_PROVED_DEBUG_ASSOCIATION')
        section(o,'.text$x',bytes(4),0x60501020,selection=5,parent=1)
        self.assertIn('RETAINED_PARENT_EH_OR_UNKNOWN_CHILD',codes(c.assess_object(o,k)))

    def test_association_cycle_anywhere_blocks(self):
        o,k=fixture();i=section(o,'.data',bytes(4),0xc0300040,selection=5,parent=3)
        self.assertEqual(i,3);self.assertIn('ASSOCIATION_CYCLE',codes(c.assess_object(o,k)))

    def test_directive_implicit_roots_and_reordering_block(self):
        for payload in (b'/INCLUDE:_authored_data',b'/alternatename:_authored_data=_fallback',b'/DEFAULTLIB:"OLDNAMES" /DEFAULTLIB:"LIBCMT"'):
            o,k=fixture();o['sections'][2]['payload']=payload;o['sections'][2]['size']=len(payload)
            o['symbols'][4]['aux']=struct.pack('<IHHIhBBH',len(payload),0,0,0,0,0,0,0)
            self.assertIn('DIRECTIVE_CONTRACT_DIFFERS',codes(c.assess_object(o,k)))

    def test_feat_metadata_cannot_be_changed(self):
        o,k=fixture();o['symbols'][6]['value']=0;self.assertIn('UNSUPPORTED_COMPILER_METADATA',codes(c.assess_object(o,k)))

    def test_missing_fields_and_parent_eh_are_independent_blockers(self):
        o,k=fixture();k['missing_fields']=[dict(original_field_va='0x00500008')];k['parent_eh']=[[1,4,False,'0x00500000',[]]]
        self.assertTrue({'ORIGINAL_MISSING_FIELDS','PARENT_EH_REQUIRES_CLOSURE_ADAPTER'}<=codes(c.assess_object(o,k)))

    def test_rootset_union_changes_registration_liveness(self):
        o,k=fixture();sec=section(o,'.text',bytes(8),0x60501020,selection=1);h=sym(o,'_second',sec,typ=32)
        section(o,'.sxdata',struct.pack('<I',h),0x300200);first=c.assess_object(o,k);self.assertTrue(first['closure_observed'])
        k['roots'].append(dict(original_address='0x00500100',symbol='_second',symbol_index=h,section=sec,value=0,size=8))
        self.assertIn('LIVE_SAFESEH_HANDLER_REQUIRES_ADAPTER',codes(c.assess_object(o,k)))

    def test_field_payload_addend_and_completeness_guards(self):
        o,k=fixture();o['sections'][1]['payload']=b'x'+bytes(15);self.assertTrue(c.assess_object(o,k)['closure_observed'])
        o['sections'][1]['payload']=bytes(4)+b'xxxx'+bytes(8);self.assertIn('CHANGED_FIELD_OR_SYMBOL',codes(c.assess_object(o,k)))
        o,k=fixture();k['fields']=[];self.assertIn('INCOMPLETE_OR_EXTRA_FIELD_PROOF',codes(c.assess_object(o,k)))

    def test_source_placeholder_definition_is_only_conversion_obligation(self):
        o,k=fixture();sec=section(o,'.bss',bytes(4),0xc0300080);o['symbols'][3]['section']=sec;k['fields'][0]['coff_relocation']['symbol_section']=sec
        r=c.assess_object(o,k);self.assertTrue(r['closure_observed']);self.assertNotIn(sec,r['retained_section_indices'])
        self.assertEqual(r['omitted_definition_conversions'][0]['symbol_index'],3);self.assertFalse(r['provider_selected'])

    def test_omitted_section_relocations_are_complete_but_not_live(self):
        o,k=fixture();fallback=sym(o,'_fallback_omitted',0);wi=weak(o,fallback=fallback)
        section(o,'.text',bytes(8),0x60501020,[(0,wi,6)],selection=1)
        r=c.assess_object(o,k);self.assertTrue(r['closure_observed']);self.assertEqual(r['summary']['edges']['PHYSICAL_SECTION_RELOCATION'],2)
        edge=next(e for e in r['edges'] if e['kind']=='PHYSICAL_SECTION_RELOCATION' and e['target']==wi)
        self.assertNotIn(wi,r['retained_primary_indices']);self.assertEqual(edge['source']['section'],3)

    def test_subcertificate_scope_binds_full_provenance_and_policy(self):
        o,k=fixture();a=c.assess_object(o,k);k['provenance']['source_sha256']='c'*64;b=c.assess_object(o,k)
        self.assertNotEqual(a['omission_subcertificate']['scope_sha256'],b['omission_subcertificate']['scope_sha256'])
        self.assertEqual(b['omission_subcertificate']['scope']['export_policy'],c.EXPORT_POLICY)
        self.assertFalse(b['full_serialization_eligible'])

    def test_unknown_section_and_symbol_semantics_fail_closed(self):
        for name,flags in [('.unknown',0x40300040),('.text',0x60501220),('.CRT$XCU',0x40300040),('.tls',0xc0300040)]:
            o,k=fixture();section(o,name,bytes(4),flags)
            r=c.assess_object(o,k);self.assertIn('UNSUPPORTED_SECTION_SEMANTICS',codes(r));self.assertFalse(r['graph_observation_complete'])
        o,k=fixture();sym(o,'_unrecognized_class',0,storage=100)
        self.assertIn('UNSUPPORTED_SYMBOL_SEMANTICS',codes(c.assess_object(o,k)))

    def test_known_omitted_label_with_complete_actual_uses(self):
        o,k,i=label_fixture();r=c.assess_object(o,k);self.assertTrue(r['closure_observed'])
        self.assertNotIn(i,r['retained_primary_indices']);self.assertEqual(r['omission_refinements'][0]['kind'],'PROVED_OMITTED_LOCAL_LABEL')
        self.assertEqual(next(s for s in r['symbols'] if s['index']==i)['disposition'],'OMIT_PROVED_UNREACHABLE_LOCAL_LABEL')

    def test_label_wrong_bounds_type_name_and_proof(self):
        for change in ({'value':16},{'value':-1},{'type':32},{'name':'_not_a_known_label'}):
            o,k,i=label_fixture();o['symbols'][i].update(change)
            self.assertIn('LABEL_OMISSION_NOT_PROVED',codes(c.assess_object(o,k)))
        o,k,i=label_fixture();k['omission_field_proofs']=[]
        self.assertIn('LABEL_OMISSION_NOT_PROVED',codes(c.assess_object(o,k)))

    def test_label_unknown_storage_aux_or_unproved_owner_remains_blocked(self):
        o,k,i=label_fixture();o['symbols'][i]['storage']=7
        self.assertIn('UNSUPPORTED_SYMBOL_SEMANTICS',codes(c.assess_object(o,k)))
        o,k,i=label_fixture();o['symbols'][i]['aux_count']=1;o['symbols'][i]['aux']=bytes(18);o['symbol_count']+=1
        self.assertIn('LABEL_OMISSION_NOT_PROVED',codes(c.assess_object(o,k)))
        o,k,i=label_fixture();k['unit_verified_functions'][-1]['size']=4
        self.assertIn('LABEL_OMISSION_NOT_PROVED',codes(c.assess_object(o,k)))

    def test_reachable_label_fallback_safeseh_and_directive_are_not_omitted(self):
        for mode in ('retained','fallback','safeseh','directive'):
            o,k,i=label_fixture()
            if mode=='retained':retarget(o,k,i)
            if mode=='fallback':weak(o,fallback=i)
            if mode=='safeseh':section(o,'.sxdata',struct.pack('<I',i),0x300200)
            if mode=='directive':o['sections'][2]['payload']=b'/INCLUDE:$LN1'
            self.assertIn('LABEL_OMISSION_NOT_PROVED',codes(c.assess_object(o,k)))

    def test_label_same_spelling_local_distinct_and_external_ambiguity(self):
        o,k,i=label_fixture();sec,ss,fn=omitted_function(o,k,'0x00500200');sym(o,'$LN1',sec,value=4,storage=3)
        self.assertTrue(c.assess_object(o,k)['closure_observed'])
        sym(o,'$LN1',0);self.assertIn('LABEL_OMISSION_NOT_PROVED',codes(c.assess_object(o,k)))

    def test_label_cross_section_use_or_nonzero_addend_blocks(self):
        o,k,i=label_fixture();o['sections'][2]['relocs'].append((0,i,6))
        self.assertIn('LABEL_OMISSION_NOT_PROVED',codes(c.assess_object(o,k)))
        o,k,i=label_fixture();sec=o['symbols'][i]['section'];o['sections'][sec]['payload']=bytes(8)+b'\x01'+bytes(7)
        self.assertIn('LABEL_OMISSION_NOT_PROVED',codes(c.assess_object(o,k)))

    def test_unused_plain_iat_duplicate_omission_preserves_actual_cell(self):
        o,k,i=iat_fixture();r=c.assess_object(o,k);self.assertTrue(r['closure_observed']);self.assertNotIn(i,r['retained_primary_indices'])
        f=r['omission_refinements'][0];self.assertEqual(f['actual_export'],'GetActiveWindow');self.assertEqual(f['original_IAT_va'],'0x00fdf2fc')
        self.assertFalse(f['provider_selected']);self.assertFalse(r['canonical_namespace_collisions_resolved'])

    def test_iat_wrong_cell_role_import_id_or_missing_use_proof(self):
        for mode in ('cell','role','id','missing','addend'):
            o,k,i=iat_fixture();row=k['omission_field_proofs'][-1]
            if mode=='cell':row.update(derived_source_symbol_base_va='0x00fdf300',exact_original_target_va='0x00fdf300')
            if mode=='role':row['classification']='SELECTED_CODE_ENTRY'
            if mode=='id':row['import_id']=176
            if mode=='missing':k['omission_field_proofs'].pop()
            if mode=='addend':row['coff_relocation']['addend']=4
            self.assertIn('REDUNDANT_IAT_OMISSION_NOT_PROVED',codes(c.assess_object(o,k)))

    def test_iat_definition_common_type_weak_or_aux_member_blocks(self):
        for mode in ('defined','common','type','weak','aux'):
            o,k,i=iat_fixture();s=o['symbols'][i]
            if mode=='defined':s['section']=3
            if mode=='common':s['value']=4
            if mode=='type':s['type']=32
            if mode in ('weak','aux'):
                s['aux_count']=1;s['aux']=struct.pack('<II10s',3,2,bytes(10));o['symbol_count']+=1
                if mode=='weak':s['storage']=105
            self.assertIn('REDUNDANT_IAT_OMISSION_NOT_PROVED',codes(c.assess_object(o,k)))

    def test_iat_actual_descriptor_cannot_follow_source_spelling(self):
        o,k,i=iat_fixture();k['iat_import_observation']['export']['name']='GetForegroundWindow'
        self.assertIn('REDUNDANT_IAT_OMISSION_NOT_PROVED',codes(c.assess_object(o,k)))

    def test_iat_rootset_expansion_cannot_reuse_omission(self):
        o,k,i=iat_fixture();fn=next(s for s in k['unit_verified_functions'] if s['section']==3)
        fnidx=next(j for j,s in o['symbols'].items() if s['name']==fn['symbol'])
        k['roots'].append(dict(original_address=fn['address'],symbol=fn['symbol'],symbol_index=fnidx,section=3,value=0,size=16))
        k['fields'].append(copy.deepcopy(k['omission_field_proofs'][-1]));r=c.assess_object(o,k)
        self.assertIn('REQUIRED_IAT_DUPLICATE_REQUIRES_NAMESPACE_POLICY',codes(r));self.assertIn(i,r['retained_primary_indices'])
        self.assertFalse(any(f['kind']=='PROVED_REDUNDANT_UNDEFINED_IAT_REFERENCE' for f in r['omission_refinements']))

    def test_unknown_contract_span_identity_and_slot_holes(self):
        o,k=fixture();k['fields_complete']=False
        with self.assertRaises(ValueError):c.assess_object(o,k)
        o,k=fixture();k['roots'][0]['size']=4;self.assertIn('UNSUPPORTED_OR_PARTIAL_ROOT_SECTION',codes(c.assess_object(o,k)))
        o,k=fixture();o['symbol_count']+=1
        with self.assertRaisesRegex(ValueError,'holes'):c.assess_object(o,k)


if __name__=='__main__':unittest.main()
