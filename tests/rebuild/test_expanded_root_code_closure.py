"""Authored metadata and an existing authored EH fixture; no game/native inputs."""
from pathlib import Path
import copy
import hashlib
import struct
import sys
import unittest
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'tools/rebuild'))
import expanded_root_code_closure as x
import eh_code_closure as eh
from test_eh_code_closure import fixture as authored_fixture,encode


def fixture():
    obj,raw,policy,context,reference=authored_fixture()
    # These synthetic omitted data sections use a known non-COMDAT data form.
    # No original object is read and no retained payload is changed.
    for i in range(7,16):obj['sections'][i]['flags']=0x40400040
    raw=encode(obj);policy['object_sha256']=eh.sha(raw);context['object_sha256']=eh.sha(raw)
    plan=eh.observe_component(raw,policy,context,reference)
    rows=[]
    for field in plan['fields']:
        if field['section']!=3:continue
        i=field['target_index'];target=obj['symbols'][i];off=field['offset']
        cls='COMPILER_LOCAL_EH_METADATA_OR_HELPER_CANDIDATE' if i==19 else 'ORIGINAL_IMAGE_DATA_REQUIRES_CANONICAL_OWNER' if i==16 else 'ORIGINAL_IMAGE_DATA_REQUIRES_CANONICAL_OWNER' if i==18 else 'SELECTED_CODE_ENTRY'
        rows.append(dict(recipe_id=policy['recipe_id'],function_va='0x00440540',physical_section=3,physical_offset=off,source_field_offset=off,
            original_field_va='0x%08x'%(0x440540+off),coff_relocation=dict(offset=off,symbol_index=i,kind=field['kind'],symbol=target['name'],
                symbol_section=target['section'],symbol_value=target['value'],symbol_type=target['type'],symbol_storage=target['storage'],addend=field['addend']&0xffffffff),
            derived_source_symbol_base_va='0x%08x'%field['original_base'],exact_original_target_va='0x%08x'%field['original_target'],
            proof_consistency='EXACT_OWN_SOURCE_RESOLUTION',physical_field_overlap_count=1,classification=cls))
    provenance=dict(object_sha256=policy['object_sha256'],source_sha256=policy['source_sha256'],recipe_id=policy['recipe_id'],recipe_index=69,
        producer_manifest_sha256=policy['inputs']['manifest'],retained_proof_sha256=policy['inputs']['retained'],recipe_manifest_sha256=policy['inputs']['recipes'],
        selection_sha256=policy['inputs']['selection'],binding_sha256=policy['inputs']['binding'],reference_identity_sha256=context['reference_identity_sha256'],
        optional_function_index_present=False,observer_sha256=hashlib.sha256(Path(x.__file__).read_bytes()).hexdigest(),
        recipe_unit_sha256='a'*64,binding_details_sha256='d'*64,
        dependency_tools_sha256={'tools/rebuild/root_code_closure.py':x.ORDINARY_PIN,'tools/rebuild/coff_code_archive.py':x.PARSER_PIN,
            'tools/rebuild/expanded_root_code_closure.py':hashlib.sha256(Path(x.__file__).read_bytes()).hexdigest()})
    contract=dict(recipe_id=policy['recipe_id'],roots=[policy['selected']],export_policy=x.ordinary.EXPORT_POLICY,verified_match=True,fields_complete=True,
        missing_fields_complete=True,unit_proofs_complete=True,fields=rows,missing_fields=[],parent_eh=context['eh_pieces'],provenance=provenance,
        omission_field_proofs=[],unit_verified_functions=[context['parent_proof']],iat_import_observation={},expanded_retention_contract=eh.expanded_contract(plan))
    return obj,contract,plan


def observe(obj,contract):return x.observe_requested_dependency_retention(obj,contract,requested_dependency_retention=[1,3,4,6,16])


class ExpandedRootTests(unittest.TestCase):
    def test_full_expanded_graph_stays_three_semantic_obligations(self):
        obj,contract,plan=fixture();before=copy.deepcopy(obj);r=observe(obj,contract)
        self.assertEqual(obj,before);self.assertTrue(r['graph_observation_complete']);self.assertFalse(r['closure_observed'])
        self.assertEqual(r['summary']['retained_relocations'],11);self.assertEqual(r['summary']['dependency_relocations'],6)
        self.assertEqual(r['blockers'],eh.extension_obligations(plan));self.assertEqual(r['retained_primary_indices'],plan['retained_primary_indices'])
        self.assertEqual(r['retained_physical_slots'],plan['retained_physical_slots']);self.assertEqual(r['retained_section_indices'],[1,3,4,6,16])
        self.assertEqual(r['retained_runtime_section_indices'],[3,4,6]);self.assertEqual(r['physical_universe'],plan['universe'])
        self.assertEqual(r['omission_subcertificate']['scope']['physical_universe_sha256'],x.digest(plan['universe']))
        for key in x.FALSE:self.assertIs(r[key],False)
        self.assertFalse(r['omission_subcertificate']['omission_approved'])

    def test_independent_EH_composition_does_not_promote_generic(self):
        obj,contract,plan=fixture();r=observe(obj,contract);d=eh.recompute_and_compose(plan,r,obj,contract)
        self.assertTrue(d['serialization_plan_ready']);self.assertFalse(r['serialization_candidate']);self.assertFalse(r['runtime_eligible'])
        self.assertEqual(d['generic_observation_sha256'],x.digest(r))

    def test_smaller_or_expanded_unknown_set_cannot_reuse_scope(self):
        obj,contract,plan=fixture()
        for sections in ([1,3],[1,3,4,6],[1,3,4,5,6,16]):
            with self.assertRaises(ValueError):x.observe_requested_dependency_retention(obj,contract,requested_dependency_retention=sections)

    def test_dependency_field_missing_changed_kind_addend_or_target_metadata(self):
        for mode in ('missing','kind','bits','target'):
            obj,c,plan=fixture();fields=c['expanded_retention_contract']['dependency_field_observations']
            if mode=='missing':fields.pop()
            if mode=='kind':fields[0]['kind']=6
            if mode=='bits':fields[0]['addend_bits']=42
            if mode=='target':fields[0]['target_symbol']['storage']=105
            with self.assertRaises(ValueError):observe(obj,c)

    def test_parent_missing_or_wrong_original_base_is_not_an_EH_waiver(self):
        obj,c,plan=fixture();c['fields'].pop()
        with self.assertRaises(ValueError):observe(obj,c)
        obj,c,plan=fixture();c['fields'][0]['derived_source_symbol_base_va']='0x00500000'
        with self.assertRaises(ValueError):observe(obj,c)

    def test_false_or_unowned_piece_cannot_be_discharged(self):
        for mode in ('false','parent','size'):
            obj,c,plan=fixture()
            if mode=='false':c['parent_eh'][0][2]=False
            if mode=='parent':c['parent_eh'][0][3]='0x0043fd40'
            if mode=='size':c['parent_eh'][0][1]+=1
            with self.assertRaises(ValueError):observe(obj,c)

    def test_original_missing_field_stays_fatal(self):
        obj,c,plan=fixture();c['missing_fields']=[dict(original_field_va='0x00440580')]
        with self.assertRaises(ValueError):observe(obj,c)

    def test_expanded_dependency_name_now_reaches_weak_fallback(self):
        obj,c,plan=fixture();obj['symbols'][55]['name']=obj['symbols'][9]['name'];r=observe(obj,c)
        self.assertFalse(r['graph_observation_complete']);codes={b['code'] for b in r['blockers']}
        self.assertIn('REACHABLE_EXPANDED_WEAK_REQUIRES_POLICY',codes);self.assertIn('REQUIRED_WEAK_OMISSION_NOT_PROVED',codes)
        self.assertIn('LIVE_WEAK_FALLBACK',r['summary']['graph_edges'])
        with self.assertRaises(ValueError):eh.compose(plan,r,r,c)

    def test_expanded_same_name_reference_cannot_hide_second_primary(self):
        obj,c,plan=fixture();obj['symbols'][54]['name']=obj['symbols'][9]['name'];r=observe(obj,c)
        self.assertFalse(r['graph_observation_complete']);self.assertIn('UNPROVED_EXPANDED_NAME_ALIAS',{b['code'] for b in r['blockers']})

    def test_unknown_association_under_EH_child_fails_closure(self):
        obj,c,plan=fixture();idx=obj['symbol_count'];obj['symbol_count']+=2
        obj['sections'][18]=dict(name='.rdata',size=4,flags=0x40301040,payload=bytes(4),relocs=[])
        obj['symbols'][idx]=dict(name='.rdata',section=18,value=0,type=0,storage=3,aux_count=1,aux=struct.pack('<IHHIhBBH',4,0,0,0,4,5,0,0))
        r=observe(obj,c);self.assertFalse(r['graph_observation_complete']);self.assertIn('UNKNOWN_EXPANDED_ASSOCIATIVE_DEPENDENCY',{b['code'] for b in r['blockers']})

    def test_extra_alias_and_partial_child_cannot_pass(self):
        obj,c,plan=fixture();obj['symbols'][27]['section']=4
        with self.assertRaises(ValueError):observe(obj,c)
        obj,c,plan=fixture();obj['sections'][4]['size']=34
        with self.assertRaises(ValueError):observe(obj,c)

    def test_data_view_does_not_pull_omitted_vtable_weak_graph(self):
        obj,c,plan=fixture();obj['sections'][5]['relocs']=[(0,55,6)]
        obj['symbols'][14]['aux']=struct.pack('<IHHIhBBH',36,1,0,0,0,6,0,0)
        r=observe(obj,c);self.assertTrue(r['graph_observation_complete']);self.assertNotIn(5,r['retained_section_indices'])
        weak=next(s for s in r['symbols'] if s['index']==55);self.assertEqual(weak['decoded_auxiliary'],dict(kind='WEAK_EXTERNAL',fallback=54,search=2))
        self.assertEqual(weak['disposition'],'OMIT_UNREACHABLE_WEAK_CANDIDATE')
        self.assertTrue(any(e['kind']=='PHYSICAL_SECTION_RELOCATION' and e['source']['section']==5 and e['target']==55 for e in r['edges']))

    def test_wrong_DATA_boundary_or_shared_semantic_domain_rejected(self):
        obj,c,plan=fixture();c['expanded_retention_contract']['data_boundary']['original_base']='0x01016c14'
        with self.assertRaises(ValueError):observe(obj,c)
        obj,c,plan=fixture();rows=c['expanded_retention_contract']['external_reference_contracts'];next(r for r in rows if r['symbol_index']==18)['semantic_domain']='code'
        with self.assertRaises(ValueError):observe(obj,c)
        obj,c,plan=fixture();shared=c['expanded_retention_contract']['shared_base_identities'];shared.append(dict(shared[0],semantic_domain='data'))
        with self.assertRaises(ValueError):observe(obj,c)

    def test_unreferenced_shared_identity_cannot_use_incompatible_domain(self):
        obj,c,plan=fixture();c['expanded_retention_contract']['shared_base_identities'].append(dict(base=0x12345678,role='code',semantic_domain='data',contract_kind='ordinary-function',identity_consistency='EXACT_BASE_ROLE_RESOLUTION'))
        with self.assertRaises(ValueError):observe(obj,c)

    def test_cookie_old_crt_contract_role_conflicts_with_canonical_DATA(self):
        obj,c,plan=fixture();next(r for r in c['expanded_retention_contract']['external_reference_contracts'] if r['symbol_index']==18)['role']='crt-contract'
        with self.assertRaises(ValueError):observe(obj,c)

    def test_registry_mixed_or_wrong_handler_never_filtered(self):
        for payload in (struct.pack('<II',19,12),struct.pack('<I',12)):
            obj,c,plan=fixture();obj['sections'][16]['payload']=payload;obj['sections'][16]['size']=len(payload)
            with self.assertRaises(ValueError):observe(obj,c)

    def test_unknown_metadata_or_directives_are_not_EH_discharge(self):
        obj,c,plan=fixture();obj['symbols'][27]['storage']=100;r=observe(obj,c)
        self.assertFalse(r['graph_observation_complete']);self.assertIn('UNSUPPORTED_SYMBOL_SEMANTICS',{b['code'] for b in r['blockers']})
        obj,c,plan=fixture();obj['sections'][1]['payload']+=b' /INCLUDE:_unknown';obj['sections'][1]['size']=len(obj['sections'][1]['payload'])
        obj['symbols'][2]['aux']=struct.pack('<IHHIhBBH',obj['sections'][1]['size'],0,0,0,0,0,0,0)
        r=observe(obj,c);self.assertFalse(r['graph_observation_complete']);self.assertIn('UNSUPPORTED_IMPLICIT_LINKER_DIRECTIVE',{b['code'] for b in r['blockers']})

    def test_full_provenance_and_ordinary_source_pin_required(self):
        for key in ('source_sha256','reference_identity_sha256','observer_sha256'):
            obj,c,plan=fixture();c['provenance'].pop(key)
            with self.assertRaises(ValueError):observe(obj,c)
        obj,c,plan=fixture();c['provenance']['optional_function_index_present']=True
        with self.assertRaises(ValueError):observe(obj,c)
        obj,c,plan=fixture();c['provenance']['dependency_tools_sha256']['tools/rebuild/root_code_closure.py']='f'*64
        with self.assertRaises(ValueError):observe(obj,c)
        self.assertEqual(hashlib.sha256((ROOT/'tools/rebuild/root_code_closure.py').read_bytes()).hexdigest(),x.ORDINARY_PIN)

    def test_scope_provenance_and_all_physical_sets_are_hash_bound(self):
        obj,c,plan=fixture();a=observe(obj,c);c['provenance']['source_sha256']='f'*64;b=observe(obj,c)
        self.assertNotEqual(a['omission_subcertificate']['scope_sha256'],b['omission_subcertificate']['scope_sha256'])
        with self.assertRaises(ValueError):eh.compose(plan,b,b,c)
        self.assertEqual(a['omission_subcertificate']['scope']['edges_sha256'],x.digest(a['edges']))
        self.assertEqual(a['omission_subcertificate']['disposition_sha256'],x.digest(dict(sections=a['sections'],symbols=a['symbols'])))

    def test_EH_state_semantics_are_not_faked_by_metadata_completion(self):
        obj,c,plan=fixture();payload=bytearray(obj['sections'][6]['payload']);struct.pack_into('<I',payload,8,0);obj['sections'][6]['payload']=bytes(payload)
        r=observe(obj,c);self.assertTrue(r['graph_observation_complete']);self.assertFalse(r['full_serialization_eligible']);self.assertEqual(len(r['blockers']),3)


if __name__=='__main__':unittest.main()
