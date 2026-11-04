"""Original synthetic policy, unresolved identity and publication failure tests."""
import copy
import json
from pathlib import Path
import struct
import sys
import tempfile
import unittest
from unittest.mock import patch
sys.path.insert(0,str(Path(__file__).resolve().parents[2]/'tools/rebuild'))
import coff_code_archive as c
import runtime_code_pool as p
from test_coff_code_archive import section,symbol,aux,object_bytes


def fixture(*,defined=False,addend=0,kind=6,local=False):
    payload=struct.pack('<I',addend)+b'AUTHORED'
    sections=[section('.drectve',b' /DEFAULTLIB:"LIBCMT" /DEFAULTLIB:"OLDNAMES"',flags=0x00100a00),
              section('.text',payload,relocs=[(0,5,kind)])]
    symbols=[symbol('.drectve',1,storage=3,auxiliary=aux(len(sections[0]['payload']),selection=0)),
             symbol('.text',2,storage=3,auxiliary=aux(len(payload),1)),symbol('_authored_root',2,typ=32)]
    if local:symbols.append(symbol('$inside',2,value=4,storage=3))
    elif defined:
        sections.append(section('.bss',b'UNOWNED',flags=0xc0300080));symbols.append(symbol('_placeholder',3,value=2))
    else:symbols.append(symbol('_unowned',0))
    raw=object_bytes(sections,symbols);target=c.parse(raw)['symbols'][5]
    base='0x00401004' if local else '0x01002000'
    signed=addend if kind==6 or addend<0x80000000 else addend-0x100000000
    row=dict(event='SELECTED_FUNCTION_COFF_RELOCATION',recipe_id='synthetic-0',function_va='0x00401000',physical_section=2,
        physical_offset=0,source_field_offset=0,coff_relocation=dict(offset=0,symbol_index=5,kind=kind,symbol=target['name'],
        symbol_section=target['section'],symbol_value=target['value'],symbol_type=target['type'],symbol_storage=target['storage'],addend=addend),
        derived_source_symbol_base_va=base,exact_original_target_va='0x%08x'%((int(base,16)+signed)&0xffffffff),
        physical_field_overlap_count=1,proof_consistency='EXACT_OWN_SOURCE_RESOLUTION',classification='ORIGINAL_IMAGE_DATA_REQUIRES_CANONICAL_OWNER')
    contract=dict(recipe_id='synthetic-0',object_sha256=c.digest(raw),source_sha256='a'*64,
        selected=dict(original_address='0x00401000',symbol='_authored_root',symbol_index=4,section=2,value=0,size=len(payload)),
        verified_match=True,fields_complete=True,missing_fields_complete=True,fields=[row],missing_fields=[],literal_sections=[])
    return raw,contract


class PoolTests(unittest.TestCase):
    def codes(self,result):return {x['code'] for x in result['blockers']}

    def test_unowned_stays_undefined_code_bytes_and_flags_preserved(self):
        raw,contract=fixture();out,r=p.extract_member(raw,contract);a,b=c.parse(raw),c.parse(out)
        self.assertEqual(a['sections'][2],b['sections'][2])
        self.assertEqual(r['undefined_symbols'],[p.unresolved('0x01002000','data')])
        self.assertFalse(r['provider_selected']);self.assertFalse(r['link_ready'])
        self.assertEqual(r['exports'],[p.canonical(dict(recipe_id='synthetic-0',object_sha256=c.digest(raw),symbol_index=4))])

    def test_definition_conversion_removes_placeholder_storage(self):
        raw,contract=fixture(defined=True);out,r=p.extract_member(raw,contract);obj=c.parse(out)
        self.assertNotIn('.bss',[s['name'] for s in obj['sections'].values()])
        target=obj['symbols'][r['mapping']['symbol_map'][5]]
        self.assertEqual((target['section'],target['value'],target['storage']),(0,0,2));self.assertEqual(r['mapping']['undefined_conversions'],[5])

    def test_signed_rel32_and_unsigned_dir32_addends_not_applied_twice(self):
        for kind,add in [(20,0xfffffffc),(6,0x100)]:
            raw,contract=fixture(kind=kind,addend=add);out,r=p.extract_member(raw,contract)
            self.assertEqual(c.parse(raw)['sections'][2]['payload'],c.parse(out)['sections'][2]['payload'])
            self.assertEqual(r['assessment']['obligations'][0]['original_base'],'0x01002000')
            self.assertEqual(r['assessment']['obligations'][0]['addend_bits'],add)

    def test_interior_static_label_keeps_offset_and_physical_identity(self):
        raw,contract=fixture(local=True);out,r=p.extract_member(raw,contract);target=c.parse(out)['symbols'][r['mapping']['symbol_map'][5]]
        self.assertEqual((target['name'],target['value'],target['storage']),('$inside',4,3));self.assertEqual(r['undefined_symbols'],[])
        contract['fields'][0]['derived_source_symbol_base_va']='0x00402000';contract['fields'][0]['exact_original_target_va']='0x00402000'
        self.assertIn('LOCAL_BASE_IDENTITY_CONFLICT',self.codes(p.assess_member(raw,contract)))

    def test_missing_duplicate_extra_or_changed_fields_and_stale_hash_block(self):
        raw,contract=fixture()
        for rows in ([],contract['fields']*2):
            bad=copy.deepcopy(contract);bad['fields']=rows
            self.assertIn('MISSING_OR_DUPLICATE_FIELD_COVERAGE',self.codes(p.assess_member(raw,bad)))
        bad=copy.deepcopy(contract);bad['object_sha256']='b'*64
        self.assertIn('MALFORMED_OR_STALE_OBJECT',self.codes(p.assess_member(raw,bad)))
        bad=copy.deepcopy(contract);bad['fields'][0]['coff_relocation']['symbol']='#wrong'
        self.assertIn('CHANGED_PHYSICAL_FIELD_RECORD',self.codes(p.assess_member(raw,bad)))
        for key in ('fields_complete','missing_fields_complete','verified_match'):
            bad=copy.deepcopy(contract);bad[key]=False;self.assertFalse(p.assess_member(raw,bad)['candidate_eligible'])

    def test_missing_highlow_and_nonexact_original_oracle_tolerance_block(self):
        raw,contract=fixture();contract['missing_fields']=[dict(source_field_offset=8)]
        self.assertIn('ORIGINAL_MISSING_RELOCATION',self.codes(p.assess_member(raw,contract)))
        with self.assertRaisesRegex(ValueError,'blocked'):p.extract_member(raw,contract)
        contract['missing_fields']=[];contract['fields'][0]['proof_consistency']='ORIGINAL_ORACLE_LITERAL_POOL_TOLERANCE_ADDRESS_NOT_MERGED'
        self.assertIn('NONEXACT_FIELD_PROOF',self.codes(p.assess_member(raw,contract)))

    def test_shared_section_alias_unknown_directive_weak_and_aux_block(self):
        raw,contract=fixture();obj=c.parse(raw)
        for mutate,code in [
            (lambda x:x['sections'][2].update(size=99),'SHARED_OR_UNVERIFIED_SECTION_EXTENT'),
            (lambda x:x['symbols'].update({6:dict(x['symbols'][4],name='_extra')}),'UNPROVED_EXTRA_ENTRY_OR_ALIAS'),
            (lambda x:x['sections'][1].update(payload=b' /INCLUDE:_authored_root'),'UNKNOWN_DIRECTIVE_CONTRACT'),
            (lambda x:x['symbols'][5].update(storage=105),'WEAK_OR_COMMON_RECORD'),
            (lambda x:x['symbols'][5].update(aux=b'\0'*18,aux_count=1),'UNSUPPORTED_AUXILIARY')]:
            altered=copy.deepcopy(obj);mutate(altered);self.assertIn(code,self.codes(p.assess_parsed(altered,contract)))

    def test_parent_eh_unknown_children_and_safeseh_block_debug_drop_explicit(self):
        raw,contract=fixture()
        for name,flags,expected in [('.text$x',0x60501020,'SAME_PARENT_EH_OR_UNKNOWN_ASSOCIATION'),('.xdata$x',0x40301040,'SAME_PARENT_EH_OR_UNKNOWN_ASSOCIATION'),('.debug$F',0x42100,None)]:
            obj=c.parse(raw);obj['sections'][3]=section(name,b'metadata',flags=flags)
            obj['symbols'][6]=dict(name=name,value=0,section=3,type=0,storage=3,aux_count=1,aux=aux(8,selection=5,association=2))
            result=p.assess_parsed(obj,contract)
            if expected:self.assertIn(expected,self.codes(result))
            else:
                self.assertTrue(result['candidate_eligible'],result['blockers']);self.assertEqual(result['observations']['debug_exclusions'][0]['section'],3)
        obj=c.parse(raw);obj['sections'][3]=section('.sxdata',b'\0'*4,flags=0x300200)
        self.assertIn('SAFESEH_REQUIRES_CLOSURE',self.codes(p.assess_parsed(obj,contract)))

    def test_numeric_tls_and_unsupported_relocation_rejected(self):
        raw,contract=fixture(kind=11)
        self.assertIn('UNSUPPORTED_RUNTIME_RELOCATION',self.codes(p.assess_member(raw,contract)))
        raw,contract=fixture();contract['fields'][0]['classification']='COMPILER_TLS_ARRAY_OFFSET_CANDIDATE_NOT_PROCESS_VA'
        self.assertIn('SPECIAL_FRAME_OR_COMPILER_REFERENCE',self.codes(p.assess_member(raw,contract)))

    def test_import_spelling_never_establishes_authentic_iat_cell(self):
        raw,contract=fixture();obj=c.parse(raw);obj['symbols'][5]['name']='__imp_not_a_cell'
        contract['fields'][0]['coff_relocation']['symbol']='__imp_not_a_cell'
        for flag in (False,True):
            contract['fields'][0]['import_pointer_source_conflict']=flag
            self.assertIn('IAT_ROLE_CONFLICT_OR_UNPROVED_CELL',self.codes(p.assess_parsed(obj,contract)))
        row=contract['fields'][0];row.update(classification='IAT_POINTER_CELL_NOT_FUNCTION_BODY',import_id='synthetic-import',import_pointer_source_conflict=False)
        result=p.assess_parsed(obj,contract);self.assertTrue(result['candidate_eligible'],result['blockers'])
        self.assertEqual(result['obligations'][0]['role'],'iat-cell')
        row['import_pointer_source_conflict']=True
        self.assertIn('IAT_ROLE_CONFLICT_OR_UNPROVED_CELL',self.codes(p.assess_parsed(obj,contract)))

    def test_equal_name_equal_content_do_not_merge_physical_providers(self):
        first=dict(recipe_id='a',object_sha256='a'*64,symbol_index=5)
        second=dict(recipe_id='a',object_sha256='a'*64,symbol_index=6)
        self.assertNotEqual(p.canonical(first),p.canonical(second))
        self.assertNotEqual(p.unresolved('0x01002000','data'),p.unresolved('0x01002008','data'))
        self.assertNotEqual(p.unresolved('0x01002000','data'),p.unresolved('0x01002000','iat-cell'))

    def test_full_literal_owners_retain_distinct_equal_content_identities(self):
        raw,contract=fixture();directive=c.parse(raw)['sections'][1]
        payload=struct.pack('<III',0,0,0);literal=b'AUTHORED'
        sections=[directive,section('.text',payload,relocs=[(0,7,6),(4,10,6),(8,7,6)]),
                  section('.rdata',literal,flags=0x40401040),section('.rdata',literal,flags=0x40401040)]
        symbols=[symbol('.drectve',1,storage=3,auxiliary=aux(directive['size'],selection=0)),
            symbol('.text',2,storage=3,auxiliary=aux(12,3)),symbol('_authored_root',2,typ=32),
            symbol('.rdata',3,storage=3,auxiliary=aux(8,selection=2)),symbol('_equal_name',3),
            symbol('.rdata',4,storage=3,auxiliary=aux(8,selection=2)),symbol('_equal_name',4)]
        raw=object_bytes(sections,symbols);contract.update(object_sha256=c.digest(raw),literal_sections=[3,4]);contract['fields']=[]
        obj=c.parse(raw)
        for off,index,kind in obj['sections'][2]['relocs']:
            target=obj['symbols'][index];base='0x01002000' if index==7 else '0x01003000'
            contract['fields'].append(dict(recipe_id='synthetic-0',function_va='0x00401000',physical_section=2,physical_offset=off,
                coff_relocation=dict(offset=off,symbol_index=index,kind=6,symbol=target['name'],symbol_section=target['section'],
                    symbol_value=0,symbol_type=0,symbol_storage=2,addend=0),derived_source_symbol_base_va=base,
                exact_original_target_va=base,proof_consistency='EXACT_OWN_SOURCE_RESOLUTION',physical_field_overlap_count=1,
                classification='COMPILER_LITERAL_FULL_READONLY_NONPOINTER_EQUALITY',literal=dict(extent=8,payload_sha256=c.digest(literal),
                    full_extent_equal=True,source_and_original_readonly=True,no_source_relocations_or_original_HIGHLOW=True)))
        out,r=p.extract_member(raw,contract);self.assertEqual(len(c.parse(out)['sections']),4)
        self.assertEqual(len(r['exports']),3);self.assertEqual(len(set(r['exports'])),3)
        self.assertEqual(r['undefined_symbols'],[])
        bad=copy.deepcopy(contract);bad['fields'][0]['literal']['payload_sha256']='a'*64
        self.assertIn('UNPROVED_LITERAL_OWNER',self.codes(p.assess_member(raw,bad)))
        contract['literal_sections']=[];out,r=p.extract_member(raw,contract)
        self.assertEqual(len(c.parse(out)['sections']),2);self.assertEqual(len(r['undefined_symbols']),2)
        contract['fields'][1].update(derived_source_symbol_base_va='0x01002000',exact_original_target_va='0x01002000')
        self.assertIn('CANONICAL_NAMESPACE_COLLISION',self.codes(p.assess_member(raw,contract)))

    def test_fixed_batch_quarantines_allocator_without_dropping_it(self):
        policy=json.loads((p.ROOT/'runtime/code-pools/initial-unresolved.json').read_text())
        self.assertEqual(policy['expected_counts'],p.EXPECTED_COUNTS)
        states={r['selected']['original_address']:(r['expected_eligible'],r['required_blocker']) for r in policy['members']}
        self.assertEqual(states,p.BATCH_STATUS)
        self.assertEqual(states['0x00aa13e0'],(False,'WEAK_OR_COMMON_RECORD'))
        self.assertEqual(sum(r['selected']['size'] for r in policy['members'] if r['expected_eligible']),673)

    def test_compiler_id_value_preserved_and_unknown_feature_bits_block(self):
        raw,contract=fixture();obj=c.parse(raw)
        obj['symbols'][6]=dict(name='@comp.id',value=123456,section=-1,type=0,storage=3,aux_count=0,aux=b'')
        result=p.assess_parsed(obj,contract);self.assertTrue(result['candidate_eligible'],result['blockers'])
        self.assertIn(6,result['extraction_plan']['symbols'])
        # Re-encode the authored fixture with a distinct compiler ID.
        syms=[symbol(s['name'],s['section'],s['value'],s['type'],s['storage'],s['aux']) for s in obj['symbols'].values()]
        raw=object_bytes(list(obj['sections'].values()),syms);contract['object_sha256']=c.digest(raw)
        out,r=p.extract_member(raw,contract);self.assertEqual(c.parse(out)['symbols'][r['mapping']['symbol_map'][6]]['value'],123456)
        obj=c.parse(raw);obj['symbols'][6].update(name='@feat.00',value=8)
        self.assertIn('UNSUPPORTED_COMPILER_METADATA',self.codes(p.assess_parsed(obj,contract)))

    def test_conflicting_physical_symbol_base_is_not_cloned(self):
        raw,contract=fixture();obj=c.parse(raw);obj['sections'][2]['relocs'].append((4,5,6))
        obj['symbols'][2]['aux']=aux(12,2)
        second=copy.deepcopy(contract['fields'][0]);second.update(physical_offset=4,source_field_offset=4,
            derived_source_symbol_base_va='0x01003000',exact_original_target_va='0x01003000')
        second['coff_relocation']['offset']=4
        # Synthetic second field addend is the authored text's first word.
        bits=int.from_bytes(obj['sections'][2]['payload'][4:8],'little');second['coff_relocation']['addend']=bits
        second['exact_original_target_va']='0x%08x'%((0x01003000+bits)&0xffffffff)
        contract['fields'].append(second)
        self.assertIn('CONFLICTING_PHYSICAL_SYMBOL_BASE',self.codes(p.assess_parsed(obj,contract)))

    def test_review_requires_exact_source_set_and_phase(self):
        with tempfile.TemporaryDirectory() as d:
            path=Path(d)/'review.json';path.write_text(json.dumps(dict(approved=True)))
            with self.assertRaisesRegex(ValueError,'authorization'):p.approved_review(path,p.file_hash(path),{})
            path.write_text(json.dumps(dict(phase='bounded-three-member-emission',approved=True,independent_source_schema_review_pass=True,root_authorized=True,source_sha256={})))
            with self.assertRaisesRegex(ValueError,'source set'):p.approved_review(path,p.file_hash(path),{})

    def test_exclusive_output_and_stability_observation(self):
        with tempfile.TemporaryDirectory() as d:
            f=Path(d)/'artifact';p.fsynced(f,b'authored')
            with self.assertRaises(FileExistsError):p.fsynced(f,b'replacement')
            self.assertEqual(f.read_bytes(),b'authored')
            p.stable({f:p.file_hash(f)},Path(d)/'absent')
            with self.assertRaisesRegex(ValueError,'changed'):p.stable({f:'a'*64},Path(d)/'absent')
            index=Path(d)/'index';index.touch()
            with self.assertRaisesRegex(ValueError,'optional index'):p.stable({},index)

    def test_deferred_reader_dependency_is_pinned_before_and_after(self):
        with tempfile.TemporaryDirectory() as d:
            root=Path(d);reader=root/'reader.py';reader.write_bytes(b'authored reader')
            expected=p.file_hash(reader);observed={}
            with patch.object(p,'ROOT',root),patch.object(p,'PINS',{}),patch.object(p,'READER_DEPENDENCIES',{'reader.py':expected}):
                # Missing subsequent proof input stops before any publication,
                # but the independent-reader hash must already be observed.
                with self.assertRaises(KeyError):p.verify_basis({}, {}, observed)
                self.assertEqual(observed,{reader.resolve():expected})
                reader.write_bytes(b'changed reader')
                with self.assertRaisesRegex(ValueError,'stale pinned'):p.verify_basis({}, {}, {})
            with self.assertRaisesRegex(ValueError,'changed'):p.stable(observed,root/'absent-index')

    def test_interrupted_archive_keeps_progress_and_never_has_valid_receipt(self):
        raw,contract=fixture()
        contract.update(expected_eligible=True,selected=dict(contract['selected']))
        with tempfile.TemporaryDirectory() as d:
            original_root=p.ROOT;root=Path(d);private=root/'build/rebuild';private.mkdir(parents=True)
            policy=root/'runtime/code-pools/initial-unresolved.json';policy.parent.mkdir(parents=True);policy.write_text('{}')
            obj=root/'source.obj';obj.write_bytes(raw);out=private/'interrupted'
            with patch.object(p,'ROOT',root),patch.object(p,'approved_review'),patch.object(p,'verify_basis',return_value=[(obj,contract,{})]),patch.object(p,'compare_member',return_value={}),patch.object(p,'extract_member',side_effect=OSError('authored interruption')):
                with self.assertRaisesRegex(OSError,'authored interruption'):p.emit_bounded({'reference':root/'reference'},policy,root/'review','a'*64,out)
            self.assertTrue((out/'progress.jsonl').exists());self.assertFalse((out/'receipt.json').exists())
            self.assertIn('failed',(out/'progress.jsonl').read_text())


if __name__=='__main__':unittest.main()
