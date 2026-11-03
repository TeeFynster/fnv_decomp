"""Fixed-address metadata and invented raw bytes only; no Game projection."""
import copy
import json
from pathlib import Path
import struct
import sys
import tempfile
import unittest
from unittest.mock import patch

sys.path.insert(0,str(Path(__file__).resolve().parents[2]/'tools/rebuild'))
import data_arena_alias_projection as alias


def fixture():
    path=Path(__file__).resolve().parents[2]/'runtime/data-arenas/entry-raw-aliases-v1.json'
    p=json.loads(path.read_text());rows=[];ordinal=0
    for number,f in enumerate(p['fragments']):
        fragment=dict(fragment_id=f['fragment_id'],start=f['start'],size=f['size'],flags=f['flags'],alignment=1,
            admitted=True,backing='raw',adjacency_to_other_fragments_proved=False,object_extent=None,object_type=None,
            lifetime_approved=False,anchor='_original_synthetic_anchor_'+str(number),
            original_domain=dict(families=['ORDINARY_UNCLASSIFIED'],overlap=False,start=f['start'],end=f['start']+f['size']))
        aliases=copy.deepcopy(f['aliases']);refs=[]
        for a in aliases:a['source_symbol_records']=[]
        demands=aliases+([] if number==0 else aliases[:4])
        for index,a in enumerate(demands):
            ordinal+=1;offset=ordinal*4;symbol='source_data_'+str(ordinal)
            r=dict(function_va='0x0086a850',recipe_id='0576-dd603b7071c482c6',
                classification='ORIGINAL_IMAGE_DATA_REQUIRES_CANONICAL_OWNER',exact_original_target_va=a['original_base'],
                derived_source_symbol_base_va=a['original_base'],physical_section=199,physical_offset=offset,source_field_offset=offset,
                coff_relocation=dict(kind=6,addend=0,symbol_section=0,symbol_storage=2,symbol_index=ordinal,symbol=symbol))
            refs.append(dict(binding_ordinal=ordinal,record=r))
            a['source_symbol_records'].append(dict(binding_ordinal=ordinal,binding_sha256=alias.arena.digest(r),recipe_id=r['recipe_id'],
                original_symbol=symbol,original_symbol_index=ordinal,field_offset=offset,addend=0))
        rows.append(dict(fragment=fragment,aliases=aliases,payload_sha256=f['payload_sha256'],owned_reference_payload_equal=True,
            contained_HIGHLOW_fields=[],contained_field_sequence_sha256=alias.hashlib.sha256(b'').hexdigest(),
            conflicting_storage_evidence=[],related_entry_fields=refs))
    s=dict(kind='data-arena-pilot-selection',status='TWO_WHOLE_RAW_FRAGMENTS_PROPOSED_NO_EMISSION',
        original_owned_sha256=alias.OWNED_SHA,original_reference_sha256=alias.REFERENCE_SHA,
        selected_fragment_proposals=rows,alias_definitions_proposed=16,actual_entry_fields=20,total_raw_bytes=446,**alias.arena.FALSE)
    payloads=[bytes((i+number)%256 for i in range(row['fragment']['size'])) for number,row in enumerate(rows)]
    return p,s,rows,payloads


class AliasProjectionTests(unittest.TestCase):
    def setUp(self):
        self.temp=tempfile.TemporaryDirectory();self.addCleanup(self.temp.cleanup);self.root=Path(self.temp.name)

    def test_fixed_policy_and_twenty_field_sixteen_alias_bijection(self):
        p,s,rows,_=fixture();self.assertEqual(alias.verify_selection(s,p),rows)
        self.assertEqual(sum(len(r['aliases']) for r in rows),16)
        self.assertEqual(sum(len(r['related_entry_fields']) for r in rows),20)

    def test_policy_scope_bytes_geometry_alias_role_and_extent_reject(self):
        for field,value in (('size',220),('alignment',4),('flags',0xc0000040),('payload_sha256','f'*64)):
            p,_,_,_=fixture();p['fragments'][0][field]=value
            with self.assertRaises(ValueError):alias.policy_contract(p)
        for key,value in (('role','code'),('object_extent',4),('fragment_offset',4),('canonical_symbol','_wrong')):
            p,_,_,_=fixture();p['fragments'][0]['aliases'][0][key]=value
            with self.assertRaises(ValueError):alias.policy_contract(p)
        p,_,_,_=fixture();p['default_action']='project'
        with self.assertRaises(ValueError):alias.policy_contract(p)

    def test_source_owned_conflict_zero_highlow_and_typed_state_reject(self):
        for key,value in (('conflicting_storage_evidence',[{}]),('contained_HIGHLOW_fields',[{}]),('owned_reference_payload_equal',False)):
            p,s,rows,_=fixture();rows[0][key]=value
            with self.assertRaises(ValueError):alias.verify_selection(s,p)
        for key,value in (('backing','virtual-zero'),('object_extent',4),('admitted',False),('adjacency_to_other_fragments_proved',True)):
            p,s,rows,_=fixture();rows[0]['fragment'][key]=value
            with self.assertRaises(ValueError):alias.verify_selection(s,p)
        p,s,rows,_=fixture();rows[0]['fragment']['original_domain']['families']=['SOURCE_PROJECTION_CANDIDATE']
        with self.assertRaises(ValueError):alias.verify_selection(s,p)

    def test_field_addend_identity_kind_symbol_or_missing_proof_reject(self):
        for key,value in (('addend',4),('kind',11),('symbol_section',1),('symbol_storage',3)):
            p,s,rows,_=fixture();rows[0]['related_entry_fields'][0]['record']['coff_relocation'][key]=value
            with self.assertRaises(ValueError):alias.verify_selection(s,p)
        p,s,rows,_=fixture();rows[0]['related_entry_fields'][0]['record']['derived_source_symbol_base_va']='0x010828e8'
        with self.assertRaises(ValueError):alias.verify_selection(s,p)
        p,s,rows,_=fixture();rows[0]['aliases'][0]['source_symbol_records']=[]
        with self.assertRaises(ValueError):alias.verify_selection(s,p)

    def test_same_section_aliases_preserve_exact_initialized_payload_and_feature(self):
        _,_,rows,payloads=fixture()
        for row,payload in zip(rows,payloads):
            f=row['fragment'];path=self.root/(f['fragment_id']+'.obj');path.write_bytes(alias.alias_object(f,row['aliases'],payload))
            proof=alias.validate_object(path,f,row['aliases'],payload)
            self.assertEqual(len(proof['aliases']),len(row['aliases']));self.assertEqual(proof['relocations'],0)
            self.assertEqual(proof['initialized_bytes'],len(payload));alias.arena.no_approval(proof)
            coff,_,_,_=alias.strict_object(path)
            for a in row['aliases']:
                symbol=next(s for s in coff.symbols.values() if s['name']==a['canonical_symbol'])
                self.assertEqual((symbol['section'],symbol['value'],symbol['storage'],symbol['type']),(1,a['fragment_offset'],2,0))

    def test_duplicate_or_original_process_va_alias_rejected(self):
        _,_,rows,payloads=fixture();r=rows[0];a=copy.deepcopy(r['aliases'])
        with self.assertRaises(ValueError):alias.alias_object(r['fragment'],a+[a[0]],payloads[0])
        a[0]['fragment_offset']=int(a[0]['original_base'],16)
        with self.assertRaises(ValueError):alias.alias_object(r['fragment'],a,payloads[0])

    def test_independent_reparse_rejects_section_offset_payload_feature_and_extra_reloc(self):
        _,_,rows,payloads=fixture();r=rows[0];f=r['fragment'];data=alias.alias_object(f,r['aliases'],payloads[0]);path=self.root/'bad.obj'
        _,_,_,symptr,count,_,_=struct.unpack_from('<HHIIIHH',data)
        variants=[]
        bad=bytearray(data);struct.pack_into('<h',bad,symptr+2*18+12,-1);variants.append(bad)
        bad=bytearray(data);struct.pack_into('<I',bad,symptr+2*18+8,int(r['aliases'][0]['original_base'],16));variants.append(bad)
        bad=bytearray(data);bad[61]^=1;variants.append(bad)
        bad=bytearray(data);struct.pack_into('<I',bad,symptr+18+8,0);variants.append(bad)
        bad=bytearray(data);struct.pack_into('<I',bad,56,0xc0100040);variants.append(bad)
        bad=bytearray(data);struct.pack_into('<H',bad,52,1);variants.append(bad)
        for bad in variants:
            path.write_bytes(bad)
            with self.assertRaises(ValueError):alias.validate_object(path,f,r['aliases'],payloads[0])

    def test_separate_root_review_gate_before_reading_owned_image(self):
        p,_,_,_=fixture();pp=self.root/'policy.json';rp=self.root/'review.json';pp.write_text(json.dumps(p));rp.write_text('{}')
        with patch.object(alias,'load_verified') as reader:
            with self.assertRaises(ValueError):alias.project('selection',pp,'owned','reference',self.root,rp,self.root/'out')
            reader.assert_not_called()

    def publication(self):
        p,s,rows,payloads=fixture();pp=self.root/'policy.json';pp.write_text(json.dumps(p));rp=self.root/'review.json'
        review=dict(kind='entry-raw-alias-projection-review',phase='private-446B-projection',approved=True,root_authorized=True,
            reviewer='independent',selection_sha256=alias.SELECTION_SHA,policy_file_sha256=alias.sha(pp),source_sha256=alias.sha(alias.__file__))
        rp.write_text(json.dumps(review));protected=self.root/'protected';protected.write_bytes(b'owned synthetic input')
        bindings={str(protected):alias.sha(protected),str(pp):alias.sha(pp)}
        return pp,rp,(s,p,rows,payloads,bindings),protected

    def test_exclusive_synthetic_publication_and_complete_fixed_counts(self):
        pp,rp,verified,_=self.publication();out=self.root/'out'
        with patch.object(alias,'load_verified',return_value=verified):
            r=alias.project('selection',pp,'owned','reference',self.root,rp,out)
            self.assertEqual((r['initialized_bytes'],r['aliases'],r['entry_fields'],r['relocations']),(446,16,20,0))
            self.assertEqual(len(list(out.glob('*.obj'))),2);alias.arena.no_approval(r)
            with self.assertRaises(ValueError):alias.project('selection',pp,'owned','reference',self.root,rp,out)

    def test_drift_after_final_publication_removes_only_owned_new_outputs(self):
        pp,rp,verified,protected=self.publication();out=self.root/'out';original=alias.validate_object;calls=[]
        def validate(*args):
            result=original(*args);calls.append(1)
            if len(calls)==2:protected.write_bytes(b'drift')
            return result
        with patch.object(alias,'load_verified',return_value=verified),patch.object(alias,'validate_object',side_effect=validate):
            with self.assertRaises(ValueError):alias.project('selection',pp,'owned','reference',self.root,rp,out)
        self.assertFalse(out.exists());self.assertTrue(protected.exists())

    def test_source_input_collision_stale_image_never_opens_pe(self):
        with patch.object(alias,'Pe') as reader:
            path=self.root/'changed';path.write_bytes(b'changed')
            with self.assertRaises(ValueError):alias.load_verified(path,path,path,path,self.root)
            reader.assert_not_called()

    def test_owned_highlow_in_or_crossing_fixed_raw_range_is_rejected(self):
        p,s,rows,_=fixture();pp=self.root/'policy.json';sp=self.root/'selection.json'
        pp.write_text(json.dumps(p));sp.write_text(json.dumps(s));owned=self.root/'owned';reference=self.root/'reference'
        real_sha=alias.sha
        def hashes(path):
            return {str(sp):alias.SELECTION_SHA,str(owned):alias.OWNED_SHA,str(reference):alias.REFERENCE_SHA}.get(str(path),
                real_sha(path) if Path(path).exists() else 'f'*64)
        for delta in (0,-3):
            class Reader:
                base=0x1000000
                def __init__(self,path):pass
                def relocations(self):return iter([rows[0]['fragment']['start']-self.base+delta])
                def close(self):pass
            with patch.object(alias,'sha',side_effect=hashes),patch.object(alias,'protected_inputs',return_value={str(pp):real_sha(pp)}),patch.object(alias,'Pe',Reader):
                with self.assertRaisesRegex(ValueError,'HIGHLOW'):alias.load_verified(sp,pp,owned,reference,self.root)

    def test_dependency_source_hash_is_not_dynamically_trusted(self):
        p,s,_,_=fixture();p['implementation_pins']['tools/rebuild/data_arena_projection.py']='f'*64
        protected=self.root/'protected';protected.write_bytes(b'synthetic')
        for relative in p['implementation_pins']:
            target=self.root/relative;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes(b'synthetic dependency')
        s['inputs']={}
        # Fixed implementation contract must reject local helper replacement,
        # before any PE read or output creation.
        with self.assertRaisesRegex(ValueError,'implementation source hash differs'):
            alias.protected_inputs(s,p,protected,protected,protected,protected,self.root)


if __name__=='__main__':unittest.main()
