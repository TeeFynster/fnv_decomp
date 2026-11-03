"""Synthetic TLS operand and immutable component execution gates only."""
import copy
import json
from pathlib import Path
import struct
import subprocess
import sys
import tempfile
import unittest
from unittest.mock import patch

sys.path.insert(0,str(Path(__file__).resolve().parents[2]/'tools/rebuild'))
import game_tls_component as component
import coff_tls_extract as extract
from test_coff_tls_extract import getter_object
from test_tls_owner_fixture import original_objects,image_file


class GameTlsComponentTests(unittest.TestCase):
    def setUp(self):
        self.temp=tempfile.TemporaryDirectory();self.addCleanup(self.temp.cleanup);self.root=Path(self.temp.name)

    def linked(self,*,operand=None,code_change=False,extra_provider=False,absolute_alias=False,game_init=False,redirect=False):
        raw=self.root/'source.obj';data,_,_=getter_object();raw.write_bytes(data)
        getter=self.root/'getter.obj';getter.write_bytes(extract.getter_bytes(raw)[0])
        original=original_objects(self.root)['storage'];alias=self.root/'storage-view.obj';alias.write_bytes(extract.alias_bytes(original,extract.VIEW)[0])
        if absolute_alias:
            coff,symptr,_,_=extract.strict_object(alias);s=extract.tls.named(coff,extract.FIELD);data=bytearray(alias.read_bytes())
            struct.pack_into('<Ih',data,symptr+s['index']*18+8,0x4042b4,-1);alias.write_bytes(data)
        image,mp=self.root/'fixture.exe',self.root/'fixture.map';image_file(image,mp)
        data=bytearray(image.read_bytes());address=0x401090;rawcode=0x490
        data[rawcode:rawcode+26]=bytes(26)
        struct.pack_into('<I',data,rawcode+4,0x403200);struct.pack_into('<I',data,rawcode+11,44);struct.pack_into('<I',data,rawcode+20,0x2b4)
        struct.pack_into('<H',data,0xe14+10,0x3094)
        if operand:struct.pack_into('<I',data,rawcode+operand[0],operand[1])
        if code_change:data[rawcode]=1
        if game_init:struct.pack_into('<i',data,0xcb4,59)
        struct.pack_into('<i',data,0x4b4,(address+1 if redirect else address)-(0x4010b4+4))
        image.write_bytes(data)
        main=self.root/'main.obj';strings=extract.PARENT.encode()+b'\0';symbol_table=bytearray()
        symbol_table+=struct.pack('<8sIhHBB',b'_Caller\0',0,1,32,2,0)
        symbol_table+=struct.pack('<IIIhHBB',0,4,0,0,32,2,0)
        main.write_bytes(struct.pack('<HHIIIHH',0x14c,1,0,102,2,0,0)+
            struct.pack('<8sIIIIIIHHI',b'.text\0\0\0',0,0,32,60,92,0,1,0,0x60500020)+bytes(32)+
            struct.pack('<IIH',4,1,20)+symbol_table+struct.pack('<I',4+len(strings))+strings)
        with mp.open('a') as stream:
            stream.write('\n 0001:00000090 '+extract.PARENT+' 00401090 getter.obj\n')
            stream.write(' 0004:000002b4 '+extract.FIELD+' 004042b4 storage.obj\n')
            stream.write(' 0001:000000b0 _Caller 004010b0 main.obj\n')
            if extra_provider:stream.write(' 0001:00000000 _OtherGameFunction 00401000 getter.obj\n')
        return component.inspect_getter(image,mp,getter,alias,dict(template_start=0x404000,index=0x403200),main)

    def test_linked_getter_has_only_symbolic_module_relative_view(self):
        result=self.linked()
        self.assertEqual([row['observed'] for row in result['operands']],[0x403200,44,0x2b4])
        self.assertEqual(result['field_source_owner_offset'],0x2b0)
        self.assertEqual(result['original_native_field_offset_not_retained'],0x2b8)
        self.assertEqual(result['authored_initial_value'],37)
        self.assertEqual(result['linked_caller'][0]['target'],result['address'])

    def test_redirected_actual_caller_operand_rejected(self):
        with self.assertRaisesRegex(ValueError,'REL32 does not resolve'):self.linked(redirect=True)

    def libraries(self,payload):
        header=b'member.obj/'.ljust(16)+b'0'.ljust(12)+b'0'.ljust(6)+b'0'.ljust(6)+b'0'.ljust(8)+str(len(payload)).encode().ljust(10)+b'`\n'
        data=b'!<arch>\n'+header+payload+(b'\n' if len(payload)%2 else b'')
        paths={name:str(self.root/name) for name in ('libcmt.lib','oldnames.lib','kernel32.lib','uuid.lib')}
        for path in paths.values():Path(path).write_bytes(data)
        return paths,{path:component.sha(path) for path in paths.values()}

    def library_object(self,name='_Clean',storage=2,directive=b''):
        strings=name.encode()+b'\0';pointer=60+len(directive)
        symbol=struct.pack('<IIIhHBB',0,4,0,0,0,storage,0)
        return (struct.pack('<HHIIIHH',0x14c,1,0,pointer,1,0,0)+
                struct.pack('<8sIIIIIIHHI',b'.drectve',0,0,len(directive),60,0,0,0,0,0xa00)+
                directive+symbol+struct.pack('<I',len(strings)+4)+strings)

    def test_exact_full_library_endpoint_absence_and_hidden_occurrences(self):
        libraries,inputs=self.libraries(self.library_object())
        evidence=component.alias_library_absence(libraries,inputs)
        self.assertEqual(len(evidence),4)
        for endpoint in extract.ALIAS_ENDPOINTS:
            # Undefined external, weak-external name, and a directive-only name
            # all reject even though none has a linked-map public definition.
            for payload in (self.library_object(endpoint),self.library_object(endpoint,105),
                            self.library_object(directive=('/include:'+endpoint).encode())):
                libraries,inputs=self.libraries(payload)
                with self.assertRaisesRegex(ValueError,'endpoint occurs'):component.alias_library_absence(libraries,inputs)

    def test_library_identity_set_and_opaque_format_fail_closed(self):
        libraries,inputs=self.libraries(self.library_object())
        Path(libraries['uuid.lib']).write_bytes(b'changed')
        with self.assertRaisesRegex(ValueError,'library changed'):component.alias_library_absence(libraries,inputs)
        libraries,inputs=self.libraries(bytes(32))
        with self.assertRaisesRegex(ValueError,'opaque'):component.alias_library_absence(libraries,inputs)
        del libraries['uuid.lib']
        with self.assertRaisesRegex(ValueError,'set differs'):component.alias_library_absence(libraries,inputs)

    def test_old_native_offset_source_offset_va_and_tls_array_va_rejected(self):
        for operand in ((20,0x2b8),(20,0x2b0),(20,0x4042b4),(11,0x40002c),(4,0x126fd98)):
            with self.subTest(operand=operand):
                with self.assertRaises(ValueError):self.linked(operand=operand)

    def test_absolute_field_extra_game_provider_changed_code_game_init_rejected(self):
        for options in ({'absolute_alias':True},{'extra_provider':True},{'code_change':True},{'game_init':True}):
            with self.subTest(options=options):
                with self.assertRaises(ValueError):self.linked(**options)

    def test_exact_getter_phases_main_workers_and_final_detach_required(self):
        text=json.dumps(component.EXPECTED)+'\n'+json.dumps(component.tls.DETACH)+'\n'
        component.parse_result(text,'',0)
        for key,value in [('getter_calls',2303),('getter_phases',8),('threads',1),('main_preserved',False),('blocks_distinct',False),('checks_ok',1)]:
            bad=dict(component.EXPECTED);bad[key]=value
            with self.assertRaises(ValueError):component.parse_result(json.dumps(bad)+'\n'+json.dumps(component.tls.DETACH)+'\n','',0)
        with self.assertRaises(ValueError):component.parse_result(json.dumps(component.EXPECTED)+'\n','',0)
        with self.assertRaises(ValueError):component.parse_result(text,'stderr',0)
        with self.assertRaises(ValueError):component.parse_result(text,'',33)

    def pair(self):
        variants,artifacts=[],{}
        for name in ('normal','moved'):
            exe,mp=self.root/(name+'.exe'),self.root/(name+'.map');exe.write_text('never execute');mp.write_text('map')
            variants.append(dict(name=name,exe=str(exe),map=str(mp),exe_sha256=component.sha(exe),map_sha256=component.sha(mp)))
            artifacts.update({str(exe):component.sha(exe),str(mp):component.sha(mp)})
        p=dict(schema_version=1,kind='game-tls-component-prepared',policy=extract.POLICY,status='prepared_pending_independent_review',execution_performed=False,
            expected_main=component.EXPECTED,expected_detach=component.tls.DETACH,variants=variants,inputs={},artifacts=artifacts,os_dependencies={})
        r=dict(schema_version=1,kind='game-tls-component-review',approved=True,reviewer='independent',prepare_sha256='b'*64,
            variants=[{k:v[k] for k in ('name','exe_sha256','map_sha256')} for v in variants],
            checks={key:True for key in ('getter_source_proof','exact_directive_drop','symbolic_storage_view','linked_tls_operands',
                                       'caller_and_callbacks','safe_seh_crt_imports','os_export_identities','protected_artifacts')})
        return p,r

    def saved_pair(self):
        p,r=self.pair();pp,rp=self.root/'prepare.json',self.root/'review.json';component.save(pp,p);r['prepare_sha256']=component.sha(pp);component.save(rp,r)
        return p,pp,rp

    def test_exact_per_variant_independent_review_required(self):
        p,r=self.pair();component.validate_review(p,r,'b'*64)
        for key,value in [('checks',{}),('approved',False),('prepare_sha256','c'*64),('variants',r['variants'][:1])]:
            bad=copy.deepcopy(r);bad[key]=value
            with self.assertRaises(ValueError):component.validate_review(p,bad,'b'*64)
        del p['artifacts'][p['variants'][0]['exe']]
        with self.assertRaises(ValueError):component.validate_review(p,r,'b'*64)

    def test_stale_original_tls_mechanism_receipt_never_compiles(self):
        root=self.root/'repo';folder=root/'build/rebuild/tls-owner-fixture-v3';folder.mkdir(parents=True)
        (folder/'prepare.json').write_text('{}')
        with patch.object(component,'ROOT',root),patch.object(component.toolchain,'run') as native:
            with self.assertRaisesRegex(ValueError,'mechanism receipt'):component.tls_mechanism_basis()
            native.assert_not_called()

    def test_stale_approval_collision_and_changed_input_never_run(self):
        p,pp,rp=self.saved_pair();out=self.root/'execution.json'
        with patch.object(component.subprocess,'run') as native:
            with self.assertRaises(ValueError):component.execute(pp,rp,'c'*64,out)
            with self.assertRaises(ValueError):component.execute(pp,rp,component.sha(rp),pp)
            Path(p['variants'][0]['exe']).write_text('changed')
            result=component.execute(pp,rp,component.sha(rp),out);self.assertEqual(result['status'],'error');native.assert_not_called()

    def test_drift_during_final_child_never_publishes_pass(self):
        p,pp,rp=self.saved_pair();calls=[]
        def native(*args,**kwargs):
            calls.append(args)
            if len(calls)==2:Path(p['variants'][1]['map']).write_text('changed during child')
            text=json.dumps(component.EXPECTED)+'\n'+json.dumps(component.tls.DETACH)+'\n'
            return subprocess.CompletedProcess(args,0,text,'')
        with patch.object(component.subprocess,'run',side_effect=native):result=component.execute(pp,rp,component.sha(rp),self.root/'execution.json')
        self.assertEqual(len(calls),2);self.assertEqual(result['status'],'error');self.assertIn('during child',result['error'])

    def test_child_timeout_is_terminal_own_child_failure(self):
        p,pp,rp=self.saved_pair()
        with patch.object(component.subprocess,'run',side_effect=subprocess.TimeoutExpired('own child',45)):
            result=component.execute(pp,rp,component.sha(rp),self.root/'execution.json')
        self.assertEqual(result['status'],'error');self.assertEqual(result['variants'],[dict(name='normal',status='timeout')])


if __name__=='__main__':unittest.main()
