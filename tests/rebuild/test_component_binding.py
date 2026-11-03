"""Original synthetic COFF graph fixtures only; no game or compiler input."""
import hashlib
import copy
from pathlib import Path
import struct
import sys
import tempfile
import unittest
sys.path.insert(0,str(Path(__file__).resolve().parents[2]/'tools/rebuild'))
import component_binding as b
from coff_inventory import Coff


def fixture(names=('_duplicate','_duplicate'),storages=(2,3),addend=-4,kind=20,gap=0):
    payload=struct.pack('<i',addend)+b'original'
    raw=60+gap;rel=raw+len(payload);symptr=rel+10
    records=bytearray();strings=bytearray(struct.pack('<I',4))
    for i,(name,storage) in enumerate(zip(names,storages)):
        pos=len(strings);strings.extend(name.encode()+b'\0')
        records.extend(struct.pack('<IIIhHBB',0,pos,0 if i==0 else 4,1,32 if i==0 else 0,storage,0))
    struct.pack_into('<I',strings,0,len(strings))
    return struct.pack('<HHIIIHH',0x14c,1,0,symptr,2,0,0)+struct.pack('<8sIIIIIIHHI',b'.text',0,0,len(payload),raw,rel,0,1,0,0x60000020)+bytes(gap)+payload+struct.pack('<IIH',0,1,kind)+records+strings


def directive_fixture(directives):
    original=fixture();text=original[60:72];relocations=original[72:82];tail=original[82:]
    directive_bytes=' '.join(directives).encode('ascii')
    symptr=122+len(directive_bytes)
    return (struct.pack('<HHIIIHH',0x14c,2,0,symptr,2,0,0)+
        struct.pack('<8sIIIIIIHHI',b'.text',0,0,len(text),100,112,0,1,0,0x60000020)+
        struct.pack('<8sIIIIIIHHI',b'.drectve',0,0,len(directive_bytes),122,0,0,0,0,0x00100a00)+
        text+relocations+directive_bytes+tail)


class ComponentBindingTests(unittest.TestCase):
    def setUp(self):
        self.tmp=tempfile.TemporaryDirectory();self.addCleanup(self.tmp.cleanup);self.root=Path(self.tmp.name)
        self.obj=self.root/'original.obj';self.obj.write_bytes(fixture());self.digest=b.sha(self.obj)
        self.rows=[dict(symbol_index=i,old_name='_duplicate',provider=b.identity('synthetic-original',self.digest,i),role='function' if i==0 else 'local',original_target='original-identity-'+str(i),reference_identity=b.identity('synthetic-input',self.digest,i)) for i in range(2)]

    def transform(self):
        for r in self.rows:r['reference_identity']=b.identity('synthetic-input',self.digest,r['symbol_index'])
        return b._namespace(self.obj,self.digest,self.rows)

    def publish(self):
        for r in self.rows:r['reference_identity']=b.identity('synthetic-input',self.digest,r['symbol_index'])
        return b._publish(self.obj,self.root/'bound.obj',self.root/'receipt.json',self.rows)

    def test_global_and_local_duplicate_spelling_is_physical(self):
        result=self.publish();after=Coff(self.root/'bound.obj')
        self.assertNotEqual(after.symbols[0]['name'],after.symbols[1]['name'])
        self.assertEqual(after.sections,Coff(self.obj).sections)
        self.assertTrue(result['verification']['non_name_original_bytes_equal'])

    def test_global_duplicate_spellings_across_objects_remain_distinct(self):
        other=b.identity('another-recipe',self.digest,0)
        self.assertNotEqual(b.namespace_name(other),b.namespace_name(self.rows[0]['provider']))

    def test_duplicate_local_spelling_inside_one_object(self):
        self.obj.write_bytes(fixture(storages=(3,3)));self.digest=b.sha(self.obj)
        self.rows=[dict(r,provider=b.identity('local-fixture',self.digest,i)) for i,r in enumerate(self.rows)]
        self.publish();self.assertEqual(Coff(self.root/'bound.obj').symbols[1]['storage'],3)

    def test_same_content_literals_preserve_separate_physical_sections(self):
        # Two authored identical eight-byte contents with separate native owners.
        payload=b'equal___';records=b''.join(struct.pack('<8sIhHBB',b'_same',0,i,0,2,0) for i in (1,2))
        headers=b''.join(struct.pack('<8sIIIIIIHHI',b'.rdata',0,0,8,100+8*i,0,0,0,0,0x40000040) for i in (0,1))
        self.obj.write_bytes(struct.pack('<HHIIIHH',0x14c,2,0,116,2,0,0)+headers+payload*2+records+struct.pack('<I',4))
        self.digest=b.sha(self.obj)
        self.rows=[dict(symbol_index=i,old_name='_same',provider=b.identity('same-content',self.digest,i),role='literal',
                        original_target='distinct-original-'+str(i),reference_identity=b.identity('same-content',self.digest,i)) for i in (0,1)]
        self.publish();after=Coff(self.root/'bound.obj')
        self.assertEqual(after.sections[1]['payload_sha256'],after.sections[2]['payload_sha256'])
        self.assertNotEqual(after.symbols[0]['name'],after.symbols[1]['name'])
        self.assertEqual([after.symbols[i]['section'] for i in (0,1)],[1,2])

    def test_same_content_literals_distinct_owner_identities(self):
        a=b.identity('a',self.digest,1);c=b.identity('a',self.digest,2)
        self.assertNotEqual(b.namespace_name(a),b.namespace_name(c))
        self.assertNotEqual(b.namespace_name(a),b.namespace_name(b.identity('b',self.digest,1)))

    def test_signed_rel32_addend_and_dir32_bitpattern_preserved(self):
        for kind in (6,20):
            self.obj.write_bytes(fixture(addend=-12,kind=kind));self.digest=b.sha(self.obj)
            data,edits,strptr=self.transform();target=self.root/('kind'+str(kind)+'.obj');target.write_bytes(data)
            self.assertEqual(Coff(target).sections[1]['relocs'],[(0,1,kind)])
            self.assertEqual(struct.unpack_from('<i',data,60)[0],-12)
            b._byte_check(self.obj.read_bytes(),data,edits,strptr)

    def test_layout_change_uses_actual_table_offsets(self):
        self.obj.write_bytes(fixture(gap=31));self.digest=b.sha(self.obj);self.publish()
        self.assertEqual(Coff(self.obj).sections,Coff(self.root/'bound.obj').sections)

    def test_conflicting_physical_symbol_rejected(self):
        self.rows.append(dict(self.rows[0],provider=b.identity('conflict',self.digest,99)))
        with self.assertRaisesRegex(ValueError,'conflicting'):self.transform()

    def test_duplicate_provider_identity_collision_rejected(self):
        self.rows[1]['provider']=self.rows[0]['provider']
        with self.assertRaisesRegex(ValueError,'collision'):self.transform()

    def test_stale_hash_index_name_and_unknown_symbol_rejected(self):
        for change in ('hash','index','name','absent'):
            rows=[dict(r) for r in self.rows];digest=self.digest
            if change=='hash':digest='0'*64
            elif change=='index':rows[0]['symbol_index']=1
            elif change=='name':rows[0]['old_name']='_absent'
            else:rows[0]['symbol_index']=99
            with self.assertRaises(ValueError):b._namespace(self.obj,digest,rows)

    def test_compiler_metadata_iat_and_aux_rejected(self):
        for name in ('@feat.00','__imp__Unowned'):
            self.obj.write_bytes(fixture(names=(name,'_duplicate')));self.digest=b.sha(self.obj)
            rows=[dict(r) for r in self.rows];rows[0]['old_name']=name
            with self.assertRaises(ValueError):b._namespace(self.obj,self.digest,rows)
        # Original synthetic symbol with an unsupported auxiliary follows index0.
        data=bytearray(fixture());symptr=struct.unpack_from('<I',data,8)[0];data[symptr+17]=1
        self.obj.write_bytes(data);self.digest=b.sha(self.obj)
        with self.assertRaises(ValueError):self.transform()

    def test_payload_or_relocation_mutation_fails(self):
        data,edits,strptr=self.transform()
        for off in (60,72):
            mutated=bytearray(data);mutated[off]^=1
            with self.assertRaisesRegex(ValueError,'byte changed'):b._byte_check(self.obj.read_bytes(),mutated,edits,strptr)

    def test_closed_policy_rejects_eh_tls_iat_unowned_and_missing_fields(self):
        # Reuse the existing original zero-filled COFF fixture; never game code.
        sys.path.insert(0,str(Path(__file__).parent))
        from test_coff_literal_extract import synthetic_object
        data,_,_=synthetic_object();source=self.root/'synthetic-full.obj';source.write_bytes(data)
        selected=self.root/'synthetic-selected.obj';selected.write_bytes(b.extract.transform(source)[0])
        coff=Coff(selected)
        owners=[next(s for s in coff.symbols.values() if s['name']==name) for name in
                (b.extract.PARENT,b.extract.LITERALS[25],b.extract.LITERALS[26])]
        b._closed_component(coff,owners)
        cases=[]
        for name in ('.xdata','.tls','.CRT$XCU'):
            changed=copy.deepcopy(coff);changed.sections[3]['name']=name;cases.append(changed)
        changed=copy.deepcopy(coff);changed.sections[2]['relocs']=changed.sections[2]['relocs'][:-1];cases.append(changed)
        changed=copy.deepcopy(coff);changed.symbols[99]=dict(index=99,name='__imp__Unowned',section=0,value=0,storage=2,aux_count=0);cases.append(changed)
        changed=copy.deepcopy(coff);changed.sections[3]['flags']|=0x80000000;cases.append(changed)
        for changed in cases:
            with self.assertRaises(ValueError):b._closed_component(changed,owners)

    def test_cross_input_original_binding_conflict_rejected(self):
        other=dict(self.rows[0],original_target='conflicting-original-target')
        with self.assertRaisesRegex(ValueError,'original binding'):b._consistent_bindings([self.rows[0],other])

    def test_complete_dependency_hash_set_contains_actual_pe_reader(self):
        inputs=b._tool_inputs()
        for name in ('component_binding.py','game_scalar_component.py','coff_literal_extract.py',
                     'coff_rewrite.py','coff_inventory.py','data_plan.py','toolchain.py'):
            path=(b.ROOT/'tools/rebuild'/name).resolve()
            self.assertEqual(inputs[str(path)],b.sha(path))

    def test_generated_golden_header_mutation_fails(self):
        header=self.root/'scalar_goldens.hpp';header.write_bytes(b'original authored expectations')
        initial=b.sha(header);b._stable_generated(header,initial)
        header.write_bytes(b'changed expectations')
        with self.assertRaisesRegex(ValueError,'golden header changed'):b._stable_generated(header,initial)

    def test_component_and_caller_directive_contracts_are_separate(self):
        self.assertEqual(b.CALLER_DIRECTIVES,['/DEFAULTLIB:"uuid.lib"','/DEFAULTLIB:"uuid.lib"']+b.extract.DEFAULTS)
        for number,contract in enumerate((b.extract.DEFAULTS,b.CALLER_DIRECTIVES)):
            self.obj.write_bytes(directive_fixture(contract));self.digest=b.sha(self.obj)
            rows=[dict(r,reference_identity=b.identity('directive-fixture',self.digest,r['symbol_index'])) for r in self.rows]
            data,_,_=b._namespace(self.obj,self.digest,rows,contract)
            after=self.root/('directive-'+str(number)+'.obj');after.write_bytes(data)
            before_coff,after_coff=Coff(self.obj),Coff(after)
            self.assertEqual(before_coff.directives,contract)
            self.assertEqual(after_coff.directives,contract)
            self.assertEqual(b.extract.payload(before_coff,2),b.extract.payload(after_coff,2))
            wrong=b.CALLER_DIRECTIVES if number==0 else b.extract.DEFAULTS
            with self.assertRaisesRegex(ValueError,'exact directive'):
                b._namespace(self.obj,self.digest,rows,wrong)

    def test_missing_reordered_or_extra_caller_directive_rejected(self):
        bad_lists=[b.CALLER_DIRECTIVES[1:],list(reversed(b.CALLER_DIRECTIVES)),
                   b.CALLER_DIRECTIVES+['/INCLUDE:_duplicate']]
        for contract in bad_lists:
            self.obj.write_bytes(directive_fixture(contract));self.digest=b.sha(self.obj)
            rows=[dict(r,reference_identity=b.identity('directive-fixture',self.digest,r['symbol_index'])) for r in self.rows]
            with self.assertRaisesRegex(ValueError,'exact directive'):
                b._namespace(self.obj,self.digest,rows,b.CALLER_DIRECTIVES)

    def test_exact_library_resolution_and_actual_search_are_hash_bound(self):
        root=self.root/'compiler';sdk=self.root/'sdk'
        (root/'VC/lib').mkdir(parents=True);(sdk/'Lib').mkdir(parents=True)
        for name in b.LIBRARIES:(sdk/'Lib'/name).write_bytes(b'original library fixture')
        # LIB precedence is explicit: prefer the existing VC directory candidate.
        first=root/'VC/lib/uuid.lib';first.write_bytes(b'first exact candidate')
        libraries=b._resolved_libraries(root,sdk)
        self.assertIn(str(first.resolve()),libraries)
        log='Searching '+str(first.resolve())+':\n'
        self.assertEqual(b._library_search(log,libraries),{str(first.resolve()):b.sha(first)})
        first.write_bytes(b'mutation')
        with self.assertRaisesRegex(ValueError,'unbound/changed'):b._library_search(log,libraries)
        unknown=self.root/'unknown.lib';unknown.write_bytes(b'unknown')
        with self.assertRaisesRegex(ValueError,'unbound/changed'):b._library_search('Searching '+str(unknown)+':\n',libraries)

    def test_no_overwrite_or_input_alias(self):
        with self.assertRaises(ValueError):b._publish(self.obj,self.obj,self.root/'r.json',self.rows)
        self.publish()
        with self.assertRaises(ValueError):self.publish()

if __name__=='__main__':unittest.main()
