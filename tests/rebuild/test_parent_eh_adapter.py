"""Authored generic no-catch adapter cases. No original inputs or native tools."""
import copy
from pathlib import Path
import sys
import unittest
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'tools/rebuild'))
import parent_eh_adapter as adapter
from test_parent_eh_adapter_lane08 import authored_parent


def valid_case(*,noncontiguous=True,object_edit=None):
    case=authored_parent(noncontiguous=noncontiguous,object_edit=object_edit);obj=case['obj'];recipe=case['recipe'];fn=recipe['functions'][0];parent=fn['address'];symbol=fn['symbol'];raw=case['raw']
    root=dict(original_address=parent,symbol=symbol,symbol_index=8,section=3,value=0,size=101)
    fields=[]
    for offset,index,kind in obj['sections'][3]['relocs']:
        source=obj['symbols'][index]
        base=case['externals'].get(index)
        if base is None:base=case['expected_pieces'][1][0]
        classification='COMPILER_LOCAL_EH_METADATA_OR_HELPER_CANDIDATE' if index==19 else 'ORIGINAL_IMAGE_DATA_REQUIRES_CANONICAL_OWNER' if source['type']==0 else 'SELECTED_CODE_ENTRY'
        fields.append(dict(recipe_id='authored-second-parent',function_va=parent,physical_section=3,physical_offset=offset,source_field_offset=offset,
            coff_relocation=dict(offset=offset,symbol_index=index,kind=kind,symbol=source['name'],symbol_section=source['section'],symbol_value=source['value'],symbol_type=source['type'],symbol_storage=source['storage'],addend=0),
            derived_source_symbol_base_va=hex(base),exact_original_target_va=hex(base),physical_field_overlap_count=1,proof_consistency='EXACT_OWN_SOURCE_RESOLUTION',classification=classification))
    proof=dict(address=parent,symbol=symbol,size=101,section=3,value=0,verdict='match')
    unit=dict(status='ok',recipe_id='authored-second-parent',recipe_index=777,object_sha256=adapter.sha(raw),source_sha256_recorded='a'*64,source_sha256_current='a'*64,recipe_unit_sha256=adapter.digest(recipe),verified_functions=[proof],eh_sections=case['expected_pieces'],eh_inferred={},eh_errors=[])
    contract=dict(recipe_id=unit['recipe_id'],roots=[root],export_policy=adapter.ordinary.EXPORT_POLICY,verified_match=True,fields_complete=True,missing_fields_complete=True,unit_proofs_complete=True,
        fields=fields,missing_fields=[],parent_eh=case['expected_pieces'],omission_field_proofs=[],unit_verified_functions=[proof],iat_import_observation=None,
        provenance=dict(object_sha256=adapter.sha(raw),source_sha256='a'*64,recipe_id=unit['recipe_id'],recipe_index=777,optional_function_index_present=False))
    return dict(raw=raw,contract=contract,recipe=recipe,unit_proof=unit,recipes=[recipe],reference=case['reference'],original_highlow_sites=case['highlow'],executable_ranges=case['executable_ranges'])


class ParentEHAdapterTests(unittest.TestCase):
    def test_second_parent_piecewise_noncontiguous_graph(self):
        result=adapter.observe_parent(**valid_case());self.assertTrue(result['semantic_graph_verified'],result)
        self.assertTrue(result['structural_projection_candidate'],result);semantic=result['semantic']
        self.assertEqual(len(semantic['fields']),11);self.assertEqual(len(semantic['states']),1)
        self.assertEqual(semantic['fields'][5]['original_field_va'],0x20000004)
        self.assertEqual([r['retain'] for r in result['safeseh_records']],[True])
        self.assertFalse(result['runtime_eligible']);self.assertFalse(result['omission_approved'])
    def test_all_failed_pieces_block_even_without_diagnostics(self):
        case=valid_case();case['contract']['parent_eh'][0][2]=False
        result=adapter.observe_parent(**case);self.assertFalse(result['structural_projection_candidate']);self.assertEqual(result['blockers'][0]['code'],'FAILED_OR_FOREIGN_EH_PIECE')
    def test_catch_flags_and_state_cycle_fail_before_projection(self):
        import struct
        for offset,value in ((20,1),(40,0),(0,0)):
            def edit(obj):
                data=bytearray(obj['sections'][6]['payload']);struct.pack_into('<I',data,offset,value);obj['sections'][6]['payload']=bytes(data)
            result=adapter.observe_parent(**valid_case(object_edit=edit));self.assertFalse(result['structural_projection_candidate'])
    def test_original_highlow_asymmetry_rejects(self):
        case=valid_case();case['original_highlow_sites'].append(0x20001000)
        result=adapter.observe_parent(**case);self.assertFalse(result['structural_projection_candidate']);self.assertEqual(result['blockers'][0]['code'],'ASYMMETRIC_ORIGINAL_HIGHLOW')
    def test_ordinary_missing_fields_not_discharged_by_eh(self):
        case=valid_case();case['contract']['missing_fields']=[{'source_field_offset':1}]
        result=adapter.observe_parent(**case);self.assertFalse(result['structural_projection_candidate']);self.assertEqual(result['blockers'][0]['code'],'INCOMPLETE_OR_MISSING_PARENT_FIELDS')

    def test_scoped_other_parent_diagnostic_preserved_without_promotion(self):
        case=valid_case();other=dict(address='0x10000100',symbol='_omitted_deleting_destructor',size=44)
        case['recipe']['functions'].append(other);case['unit_proof']['recipe_unit_sha256']=adapter.digest(case['recipe'])
        verified=dict(other,section=17,value=0,verdict='match');case['unit_proof']['verified_functions'].append(verified);case['contract']['unit_verified_functions'].append(verified)
        diagnostic='0x10000100: tail relocation to otherhelper differs';case['unit_proof']['eh_errors']=[diagnostic]
        result=adapter.observe_parent(**case);self.assertTrue(result['structural_projection_candidate'],result)
        self.assertEqual(result['semantic']['original_core']['unit_diagnostics_preserved'],[diagnostic]);self.assertFalse(result['semantic']['original_core']['strict_unit_local_diagnostics_pass'])
        for text in ('unscoped error','0x12345678: foreign error','0x10000000: selected error'):
            changed=copy.deepcopy(case);changed['unit_proof']['eh_errors']=[text]
            self.assertFalse(adapter.observe_parent(**changed)['structural_projection_candidate'])
    def test_parent_reference_budget_is_explicit(self):
        case=valid_case();bounded=adapter.BoundedReference(case['reference'])
        with self.assertRaises(adapter.Blocked):bounded.read(0x10000000,65537)
        bounded.calls=8192
        with self.assertRaises(adapter.Blocked):bounded.read(0x10000000,1)

    def test_tls_reason_is_not_waived_as_eh(self):
        case=valid_case();field=next(r for r in case['contract']['fields'] if r['coff_relocation']['symbol_index']==19);field['classification']='STATIC_TLS_INDEX_REQUIRES_CANONICAL_OWNER'
        result=adapter.observe_parent(**case);self.assertFalse(result['structural_projection_candidate']);self.assertTrue(any(b['code']=='SPECIAL_RUNTIME_REFERENCE' for b in result['blockers']))
    def test_declared_bss_cannot_exhaust_unchanged_oracle(self):
        import struct
        case=valid_case();raw=bytearray(case['raw']);header=20+6*40;struct.pack_into('<I',raw,header+16,268435457);struct.pack_into('<I',raw,header+20,0);struct.pack_into('<I',raw,header+36,0xc0300080)
        case['raw']=bytes(raw);case['unit_proof']['object_sha256']=case['contract']['provenance']['object_sha256']=adapter.sha(case['raw'])
        result=adapter.observe_parent(**case);self.assertEqual(result['blockers'][0]['code'],'DECLARED_ORACLE_SECTION_BUDGET_EXCEEDED')
    def test_explicit_known_parent_crt_is_candidate_unknown_stays_blocked(self):
        for name,expected in (('_atexit',True),('_mystery_CRT',False)):
            def edit(obj):obj['symbols'][13]['name']=name
            case=valid_case(object_edit=edit);next(r for r in case['contract']['fields'] if r['coff_relocation']['symbol_index']==13)['classification']='EXPLICIT_NORMAL_CRT_CONTRACT_CANDIDATE'
            result=adapter.observe_parent(**case);self.assertEqual(result['structural_projection_candidate'],expected,result)

    def test_funcinfo_first_exact_descriptor_partition(self):
        import struct
        def edit(obj):
            data=obj['sections'][6]['payload'];obj['sections'][6]['payload']=data[8:]+data[:8]
            obj['symbols'][24]['value']=0;obj['symbols'][25]['value']=36
            obj['sections'][6]['relocs']=[(8,25,6),(40,12,6)]
        result=adapter.observe_parent(**valid_case(object_edit=edit));self.assertTrue(result['structural_projection_candidate'],result)
        self.assertEqual(result['semantic']['metadata_descriptors'],dict(funcinfo=[0,36],unwind=[36,44]))
    def test_overlapping_metadata_descriptors_reject(self):
        def edit(obj):obj['symbols'][25]['value']=4
        result=adapter.observe_parent(**valid_case(object_edit=edit));self.assertFalse(result['structural_projection_candidate'])
    def test_generated_data_needs_same_physical_parent_witness(self):
        def edit(obj):
            obj['sections'][4]['relocs']=[(off,16 if off==4 else index,6 if off==4 else kind) for off,index,kind in obj['sections'][4]['relocs']]
        case=valid_case(object_edit=edit);result=adapter.observe_parent(**case)
        self.assertTrue(result['structural_projection_candidate'],result)
        self.assertEqual(next(e for e in result['semantic']['external_obligations'] if e['symbol_index']==16)['role'],'data')
        def missing(obj):
            edit(obj);obj['sections'][3]['relocs']=[(off,13 if index==16 else index,kind) for off,index,kind in obj['sections'][3]['relocs']]
        result=adapter.observe_parent(**valid_case(object_edit=missing));self.assertFalse(result['structural_projection_candidate'])
        self.assertEqual(result['blockers'][0]['code'],'MISSING_GENERATED_DATA_PARENT_WITNESS')

    def test_unlisted_pieces_are_unknown_not_false_or_promoted(self):
        case=valid_case();case['contract']['parent_eh']=[]
        result=adapter.observe_parent(**case);self.assertFalse(result['structural_projection_candidate']);self.assertEqual(result['blockers'][0]['code'],'MISSING_MATCHED_EH_PIECE_PROOF')

if __name__=='__main__':unittest.main()
