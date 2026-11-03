"""Original label proof fixtures, no reference image or native compiler."""
from pathlib import Path
import copy
import hashlib
import struct
import sys
import unittest
sys.path.insert(0, str(Path(__file__).resolve().parents[2]/'tools/rebuild'))
import local_label_projection as p
from test_coff_code_archive import object_bytes, section, symbol, aux


def fixture():
    raw = object_bytes([
        section('.text', bytes(16), relocs=[(0,3,6)]),
        section('.text', bytes(32), relocs=[(0,7,6),(4,8,6),(8,9,6)]),
        section('.drectve', b' /DEFAULTLIB:"LIBCMT" /DEFAULTLIB:"OLDNAMES"',flags=0x100a00)], [
        symbol('.text',1,storage=3,auxiliary=aux(16,1)),symbol('_omitted',1,typ=32),symbol('$LN1',1,value=8,storage=6),
        symbol('.text',2,storage=3,auxiliary=aux(32,3)),symbol('_root',2,typ=32),
        symbol('$LN1',2,value=20,storage=6),symbol('$LN2',2,value=24,storage=6),symbol('$LN3',2,value=28,storage=3),
        symbol('.drectve',3,storage=3,auxiliary=aux(40,selection=0))])
    obj = p.coff.parse(raw)
    # Use the actual authored directive extent, not a hard-coded aux claim.
    directive_size = obj['sections'][3]['size']
    if directive_size != 40:
        b = bytearray(raw); struct.pack_into('<I', b, obj['symbol_pointer']+18*11, directive_size); raw=bytes(b)
    owners = [dict(address='0x01001000',section=1,size=16,symbol='_omitted',value=0,verdict='match'),
              dict(address='0x01002000',section=2,size=32,symbol='_root',value=0,verdict='match')]
    obj=p.coff.parse(raw); fields=[];highlow=[]
    for si,off,target in [(1,0,3),(2,0,7),(2,4,8),(2,8,9)]:
        s=obj['symbols'][target];base=int(owners[s['section']-1]['address'],16)+s['value'];field=int(owners[si-1]['address'],16)+off
        fields.append(dict(physical_section=si,physical_offset=off,physical_field_overlap_count=1,
            proof_consistency='EXACT_OWN_SOURCE_RESOLUTION',function_va=owners[si-1]['address'],original_field_va=f'0x{field:08x}',
            derived_source_symbol_base_va=f'0x{base:08x}',exact_original_target_va=f'0x{base:08x}',original_operand=base,
            coff_relocation=dict(offset=off,symbol_index=target,kind=6,symbol=s['name'],symbol_section=s['section'],
                symbol_value=s['value'],symbol_type=0,symbol_storage=s['storage'],addend=0,width=4)))
        highlow.append(f'0x{field:08x}')
    e=dict(object_sha256=p.sha(raw),source_sha256='a'*64,authority_sha256='b'*64,contract_sha256='c'*64,
           keep_sections=[2,3],keep_symbols=[4,6,7,8,9,10],unit_functions=owners,fields=fields,original_highlow_sites=highlow)
    return raw,e


def decoder_fixture(missing=False):
    import root_code_closure as observer
    raw,e=fixture()
    for row in e['fields']:
        row.update(recipe_id='authored',source_field_offset=row['physical_offset'],classification='UNIQUE_CODE_INTERIOR_OR_LOCAL_LABEL_NOT_CALLABLE_APPROVAL')
    contract=dict(recipe_id='authored',roots=[dict(original_address='0x01002000',symbol='_root',symbol_index=6,section=2,value=0,size=32)],
        provenance=dict(object_sha256=e['object_sha256'],source_sha256=e['source_sha256']),export_policy=observer.EXPORT_POLICY,
        fields_complete=True,missing_fields_complete=True,verified_match=True,fields=[r for r in e['fields'] if r['physical_section']==2],
        missing_fields=[{'authored_missing':True}] if missing else [],parent_eh=[],unit_proofs_complete=True,
        omission_field_proofs=e['fields'],unit_verified_functions=e['unit_functions'],iat_import_observation={})
    frozen=observer.assess_object(p.coff.parse(raw),contract)
    e['contract_sha256']=p.sha(p.canonical(contract).encode())
    return raw,e,contract,frozen


class LabelTests(unittest.TestCase):
    def test_supplemental_omitted_STATIC_needs_exact_original_authority(self):
        import root_code_closure as observer
        raw,e,k,_=decoder_fixture();obj=p.coff.parse(raw);b=bytearray(raw)
        b[obj['symbol_pointer']+18*3+16]=3;raw=bytes(b);e['object_sha256']=p.sha(raw)
        row=e['fields'][0];row['coff_relocation']['symbol_storage']=3
        row['supplemental_authority']=dict(kind='source-bound-original-code-relocation-operand',width=4,
            original_reference_sha256='f'*64,original_object_sha256=e['object_sha256'],
            original_field_va=row['original_field_va'],original_operand=row['original_operand'],native_field=[1,0,3,6])
        k['provenance'].update(object_sha256=e['object_sha256'],reference_identity_sha256='f'*64)
        k['omission_field_proofs']=e['fields'][1:];e['supplemental_fields']=[row]
        e['contract_sha256']=p.sha(p.canonical(k).encode());frozen=observer.assess_object(p.coff.parse(raw),k)
        result=p.decode_label_policy(raw,k,frozen,p.prove_labels(raw,e))
        self.assertEqual(result['remaining_blockers'],[]);self.assertFalse(result['emission_approved'])
        bad=copy.deepcopy(e);bad['fields'][0]['supplemental_authority']['original_reference_sha256']='0'*64
        with self.assertRaises(ValueError):p.decode_label_policy(raw,k,frozen,p.prove_labels(raw,bad))
        bad=copy.deepcopy(e);bad.pop('supplemental_fields')
        with self.assertRaises(ValueError):p.decode_label_policy(raw,k,frozen,p.prove_labels(raw,bad))

    def test_decoder_recomputes_frozen_certificate_and_only_discharges_labels(self):
        raw,e,k,f=decoder_fixture();before=copy.deepcopy(f)
        result=p.decode_label_policy(raw,k,f,p.prove_labels(raw,e))
        self.assertEqual(len(result['discharged_blocker_ids']),7)
        self.assertEqual(result['remaining_blockers'],[]);self.assertEqual(f,before)
        self.assertFalse(result['original_highlow_authority_authenticated']);self.assertFalse(result['emission_approved'])
        raw,e,k,f=decoder_fixture(missing=True)
        result=p.decode_label_policy(raw,k,f,p.prove_labels(raw,e))
        self.assertEqual([b['code'] for b in result['remaining_blockers']],['ORIGINAL_MISSING_FIELDS'])
        self.assertFalse(result['typed_label_blockers_only'])

    def test_decoder_rejects_forged_old_certificate_and_contract(self):
        raw,e,k,f=decoder_fixture();cert=p.prove_labels(raw,e)
        bad=copy.deepcopy(f);bad['blockers']=[]
        with self.assertRaises(ValueError):p.decode_label_policy(raw,k,bad,cert)
        e['contract_sha256']='d'*64
        with self.assertRaises(ValueError):p.decode_label_policy(raw,k,f,p.prove_labels(raw,e))
    def test_physical_same_spelling_retained_and_omitted(self):
        raw,e=fixture();cert=p.prove_labels(raw,e);out,m,r=p.serialize_labels(raw,e['keep_sections'],e['keep_symbols'],[],cert)
        before,after=p.coff.parse(raw),p.coff.parse(out)
        self.assertEqual(m['section_map'],{2:1,3:2})
        self.assertEqual(m['auxiliary_map'],{5:1,11:7})
        for old in (7,8,9):
            x=dict(before['symbols'][old]);x['section']=1
            self.assertEqual(after['symbols'][m['symbol_map'][old]],x)
        self.assertEqual(p.coff.exports(out),['_root'])
        self.assertFalse(r['emission_approved']);self.assertFalse(r['runtime_eligible'])

    def test_omitted_same_spelling_STATIC_is_proved_as_distinct_local(self):
        raw,e=fixture();obj=p.coff.parse(raw);b=bytearray(raw)
        b[obj['symbol_pointer']+18*3+16]=3;raw=bytes(b);e['object_sha256']=p.sha(raw)
        e['fields'][0]['coff_relocation']['symbol_storage']=3
        cert=p.prove_labels(raw,e)
        self.assertIn(3,p.label_records(p.coff.parse(raw),e['keep_sections']))
        out,m,_=p.serialize_labels(raw,e['keep_sections'],e['keep_symbols'],[],cert)
        self.assertNotIn(3,m['symbol_map']);self.assertEqual(p.coff.exports(out),['_root'])
        bad=copy.deepcopy(e);bad['fields']=bad['fields'][1:]
        with self.assertRaises(ValueError):p.prove_labels(raw,bad)

    def test_frozen_writer_still_rejects_LABEL(self):
        raw,e=fixture()
        with self.assertRaises(ValueError):p.coff.serialize(raw,e['keep_sections'],e['keep_symbols'])

    def test_missing_extra_duplicate_field_reject(self):
        raw,e=fixture()
        for fields in (e['fields'][1:], e['fields']+[e['fields'][0]]):
            bad=copy.deepcopy(e);bad['fields']=fields
            with self.assertRaises(ValueError):p.prove_labels(raw,bad)

    def test_original_operand_highlow_and_base_reject(self):
        raw,e=fixture()
        for key,value in [('original_operand',0),('derived_source_symbol_base_va','0x01002000'),('original_field_va','0x01002001')]:
            bad=copy.deepcopy(e);bad['fields'][1][key]=value
            with self.assertRaises(ValueError):p.prove_labels(raw,bad)
        bad=copy.deepcopy(e);bad['original_highlow_sites']=[]
        with self.assertRaises(ValueError):p.prove_labels(raw,bad)

    def test_match_source_span_and_owner_identity_reject(self):
        raw,e=fixture()
        for key,value in [('verdict','mismatch'),('size',31),('symbol','_invented')]:
            bad=copy.deepcopy(e);bad['unit_functions'][1][key]=value
            with self.assertRaises(ValueError):p.prove_labels(raw,bad)

    def test_no_LABEL_undefined_conversion_or_dropped_live_label(self):
        raw,e=fixture();cert=p.prove_labels(raw,e)
        with self.assertRaises(ValueError):p.serialize_labels(raw,e['keep_sections'],e['keep_symbols'],[7],cert)
        bad=copy.deepcopy(e);bad['keep_symbols'].remove(7)
        with self.assertRaises(ValueError):p.prove_labels(raw,bad)
        with self.assertRaises(ValueError):p.serialize_labels(raw,e['keep_sections'],e['keep_symbols'],[True],cert)
        out,m,_=p.serialize_labels(raw,e['keep_sections'],e['keep_symbols'],[],cert)
        with self.assertRaises(ValueError):p.verify_label_selection(raw,out,dict(m,undefined_conversions=[True]),cert)

    def test_stale_and_forged_typed_certificate_reject(self):
        raw,e=fixture();cert=p.prove_labels(raw,e)
        with self.assertRaises(ValueError):p.serialize_labels(raw,e['keep_sections'],e['keep_symbols'],[],p.LabelCertificate(cert.evidence_json,'{}'))
        with self.assertRaises(ValueError):p.prove_labels(raw+b'x',e)
        with self.assertRaises(ValueError):p.serialize_labels(raw,e['keep_sections'],e['keep_symbols'],[],{})

    def test_class6_boundary_type_aux_and_external_spelling_reject(self):
        raw,e=fixture();obj=p.coff.parse(raw)
        for field,fmt,value in [(8,'<I',32),(14,'<H',32),(16,'<B',2)]:
            b=bytearray(raw);struct.pack_into(fmt,b,obj['symbol_pointer']+18*7+field,value);bad=copy.deepcopy(e);bad['object_sha256']=p.sha(bytes(b))
            with self.assertRaises(ValueError):p.prove_labels(bytes(b),bad)

    def test_independent_reparse_rejects_forged_maps_and_storage(self):
        raw,e=fixture();cert=p.prove_labels(raw,e);out,m,_=p.serialize_labels(raw,e['keep_sections'],e['keep_symbols'],[],cert)
        for key,value in [('section_map',{2:1,3:1}),('auxiliary_map',{}),('symbol_map',{4:0,6:2,7:3,8:3,9:5,10:6})]:
            bad=copy.deepcopy(m);bad[key]=value
            with self.assertRaises(ValueError):p.verify_label_selection(raw,out,bad,cert)
        b=bytearray(out);obj=p.coff.parse(out);b[obj['symbol_pointer']+18*m['symbol_map'][7]+16]=3
        with self.assertRaises(ValueError):p.verify_label_selection(raw,bytes(b),m,cert)

    def test_nonzero_addend_retained_interior_and_REL32(self):
        raw,e=fixture();obj=p.coff.parse(raw)
        # Change one physical relocation from DIR32 to REL32 with a signed
        # addend -4; the target remains inside its exact checked CODE owner.
        b=bytearray(raw);section2=20+40
        ptr=struct.unpack_from('<I',raw,section2+20)[0];rp=struct.unpack_from('<I',raw,section2+24)[0]
        struct.pack_into('<I',b,ptr,0xfffffffc);struct.pack_into('<H',b,rp+8,20);raw=bytes(b)
        e['object_sha256']=p.sha(raw);r=e['fields'][1];r['coff_relocation']['kind']=20;r['coff_relocation']['addend']=0xfffffffc
        r['exact_original_target_va']='0x01002010';r['original_operand']=12;e['original_highlow_sites'].remove('0x01002000')
        cert=p.prove_labels(raw,e);out,m,_=p.serialize_labels(raw,e['keep_sections'],e['keep_symbols'],[],cert)
        self.assertEqual(p.coff.parse(out)['sections'][1]['payload'][:4],b'\xfc\xff\xff\xff')


if __name__=='__main__':unittest.main()
