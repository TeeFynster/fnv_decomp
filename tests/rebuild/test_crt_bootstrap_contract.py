"""Original metadata/protocol fixtures. Never invoke native tools or children."""
import argparse
import json
from pathlib import Path
import struct
import sys
import tempfile
import unittest
from unittest.mock import patch

sys.path.insert(0,str(Path(__file__).resolve().parents[2]/'tools/rebuild'))
import crt_bootstrap_contract as c


def wire(rows):return b''.join(c.EVENT.pack(c.MAGIC,1,*row) for row in rows)


def api_records():return [dict(dll='KERNEL32.dll',export=dict(kind='name',name=n)) for n in sorted(c.REQUIRED_APIS)]


def trace(order):
    lanes=sorted(order);rows=[(0,1,7,0)]+[(lane,2,32*lane+496,0) for lane in order]
    rows.append((0,3,len(lanes),15))
    for lane in lanes:rows.extend([(lane,4,64*lane+2016,0),(lane,5,0,0)])
    rows.append((0,6,0,0));rows.extend((lane,7,0,0) for lane in reversed(lanes))
    rows.extend((lane,8,32*(lane+1)+496,0) for lane in reversed(order))
    return rows


class EarlyCoff:
    def __init__(self):
        self.sections={i:dict(index=i,name='.text' if i!=3 else '.CRT$XIAA',size=16 if i!=3 else 4,
            flags=0x60001020 if i!=3 else 0x40000040,selection='any',association=0,relocs=[]) for i in (1,3,4)}
        names=[('_fnv_bootstrap_early',1),('___security_cookie',0),('___security_cookie_complement',0),
               ('_fnv_bootstrap_event',4),('__imp__GetStdHandle@4',0),('__imp__GetFileType@4',0),
               ('__imp__WriteFile@20',0),('_fnv_bootstrap_early_slot',3)]
        self.symbols={i:dict(index=i,name=name,section=sec,value=0,storage=2,type=32 if sec in(1,4) else 0)
                      for i,(name,sec) in enumerate(names)}
        self.sections[1]['relocs']=[(0,1,6),(4,2,6),(8,3,20)]
        self.sections[4]['relocs']=[(0,4,6),(4,5,6),(8,6,6)]
        self.sections[3]['relocs']=[(0,0,6)]
    def unpack(self,fmt,offset):
        index=(offset-20)//40+1;sec=self.sections[index]
        return (b'.text',0,0,sec['size'],index*100,0,0,0,0,sec['flags'])
    def take(self,offset,size):return bytes(size)


class LinkedPe:
    base=0x400000
    def __init__(self):
        self.words={0x2000:0,0x2004:0x401100,0x2100:0,0x2104:0x401050,0x2108:0x401200,0x210c:0}
    def unpack(self,fmt,offset):return (128,) if offset==60 else (0x1000,)
    def read_rva(self,rva,size,allow_code=False):
        return b''.join(struct.pack('<I',self.words[r]) for r in range(rva,rva+size,4))
    def section(self,*args):return dict(executable=False,flags=0xC0000040)


def mapping():
    result={n:dict(address=0x401000+i*16,owner='f LIBCMT:normal.obj') for i,n in enumerate(c.CRT_REQUIRED)}
    result.update({'_fnv_bootstrap_early':dict(address=0x401050,owner='f control-host.obj'),
        '_fnv_bootstrap_early_slot':dict(address=0x402104,owner='control-host.obj'),
        '___xi_a':dict(address=0x402100),'___xi_z':dict(address=0x402110),
        '___xc_a':dict(address=0x402000),'___xc_z':dict(address=0x402008),
        'ctor':dict(address=0x401100,owner='f sp1.obj')})
    result['___security_cookie']['address']=0x402200;result['___security_cookie_complement']['address']=0x402204
    return result


class ConsumerCoff:
    def __init__(self):
        names=[('??0FnvBootstrapSp1Object@@QAE@XZ',1),('??1FnvBootstrapSp1Object@@QAE@XZ',2),
               ('_fnv_bootstrap_sp1_work',3),('init',4),('___security_cookie',0),
               ('@__security_check_cookie@4',0),('_atexit',0),('_fnv_bootstrap_sp1_register',5)]
        self.symbols={i:dict(name=n,section=s,value=0) for i,(n,s) in enumerate(names)}
        self.sections={i:dict(index=i,name='.text',size=16,relocs=[]) for i in range(1,7)}
        for i in (1,2,3):self.sections[i]['relocs']=[(0,4,6),(4,5,20)]
        self.sections[4]['relocs']=[(0,0,20),(4,6,20)]
        self.sections[5]['relocs']=[(0,6,20)]
        self.sections[6].update(name='.CRT$XCU',size=4,relocs=[(0,3,6)])
    def unpack(self,fmt,offset):
        i=(offset-20)//40+1;return (b'.text',0,0,self.sections[i]['size'],100*i,0,0,0,0,0)
    def take(self,offset,size):return bytes(size)


class BootstrapTests(unittest.TestCase):
    def test_control_and_mixed_accept_actual_ctor_order_not_TU_order(self):
        for variant in ('control','mixed'):
            for order in ([1,2,3],[3,1,2],[2,3,1]):
                result=c.validate_trace(wire(trace(order)),variant,0)
                self.assertEqual(result['observed_constructor_order'],list(order))
                self.assertTrue(result['normal_exit_sequence'])
        with self.assertRaises(ValueError):c.validate_trace(wire(trace([1])),'control',0)

    def test_missing_duplicate_or_late_early_event_fails(self):
        rows=trace([1,2,3])
        for bad in (rows[1:],rows[:1]+rows,rows[1:4]+rows[:1]+rows[4:]):
            with self.assertRaises(ValueError):c.validate_trace(wire(bad),'mixed',0)

    def test_cookie_flags_and_nonzero_C_initializer_failure_not_success(self):
        rows=trace([1,2,3]);rows[0]=(0,1,5,0)
        with self.assertRaisesRegex(ValueError,'cookie'):c.validate_trace(wire(rows),'control',0)
        with self.assertRaisesRegex(ValueError,'return normally'):c.validate_trace(wire(trace([1,2,3])),'control',255)

    def test_registration_callback_and_dtor_contracts(self):
        rows=trace([2,1,3])
        for index,value in ((6,(1,5,1,0)),(-1,(3,8,0,0)),(4,(0,3,3,7))):
            bad=list(rows);bad[index]=value
            with self.assertRaises(ValueError):c.validate_trace(wire(bad),'mixed',0)
        bad=rows[:-3]+list(reversed(rows[-3:]))
        with self.assertRaises(ValueError):c.validate_trace(wire(bad),'mixed',0)

    def test_bounded_fixed_records_and_stderr(self):
        for raw in (wire(trace([1]))+b'x',bytes(65*c.EVENT.size),c.EVENT.pack(0,1,0,1,7,0)):
            with self.assertRaises(ValueError):c.decode_events(raw)
        with self.assertRaises(ValueError):c.validate_trace(wire(trace([1,2,3])),'control',0,b'error')

    def test_unprotected_dependency_closure_and_C_initializer_slot(self):
        result=c.early_closure(EarlyCoff())
        self.assertEqual(result['sections'],[1,4]);self.assertIn('zero continues',result['C_initializer_contract'])

    def test_early_GS_EH_unknown_or_mutable_dependency_rejected(self):
        for bad in ('@__security_check_cookie@4','___CxxFrameHandler3','_memcpy'):
            coff=EarlyCoff();coff.symbols[4]['name']=bad
            with self.assertRaisesRegex(ValueError,'dependency'):c.early_closure(coff)
        coff=EarlyCoff();coff.sections[4]['name']='.text$x'
        with self.assertRaisesRegex(ValueError,'EH'):c.early_closure(coff)
        coff=EarlyCoff();coff.sections[4]['flags']=0xC0000040
        with self.assertRaisesRegex(ValueError,'mutable'):c.early_closure(coff)

    def test_wrong_C_initializer_shape_rejected(self):
        for change in ('name','size','kind'):
            coff=EarlyCoff()
            if change=='name':coff.sections[3]['name']='.CRT$XCU'
            elif change=='size':coff.sections[3]['size']=8
            else:coff.sections[3]['relocs']=[(0,0,20)]
            with self.assertRaises(ValueError):c.early_closure(coff)

    def test_native_table_identity_allows_physical_CXX_before_C(self):
        # Logical execution stage order must never be inferred from VA order.
        with patch.object(c,'parse_imports',return_value=api_records()):
            result=c.validate_link(LinkedPe(),mapping(),['ctor'],'control-host.obj')
        self.assertTrue(result['runtime_cookie_order_requires_early_event_trace'])
        self.assertLess(result['CXX_range'][0],result['C_range'][0])

    def test_preceding_nonnull_C_initializer_or_missing_CXX_root_rejected(self):
        with patch.object(c,'parse_imports',return_value=api_records()):
            pe=LinkedPe();pe.words[0x2100]=0x401300
            with self.assertRaisesRegex(ValueError,'precedes'):c.validate_link(pe,mapping(),['ctor'],'control-host.obj')
            pe=LinkedPe();pe.words[0x2004]=0
            with self.assertRaisesRegex(ValueError,r'C\+\+'):c.validate_link(pe,mapping(),['ctor'],'control-host.obj')

    def test_consumers_require_real_GS_and_compiler_exit_registration(self):
        coff=ConsumerCoff();shape=c.consumer_shape(coff,'sp1')
        self.assertEqual(len(shape['protected_functions']),3)
        coff.sections[2]['relocs']=[(0,4,6)]
        with self.assertRaisesRegex(ValueError,'GS protection'):c.consumer_shape(coff,'sp1')
        coff=ConsumerCoff();coff.sections[4]['relocs']=[(0,0,20)]
        with self.assertRaisesRegex(ValueError,'registration'):c.consumer_shape(coff,'sp1')

    def test_linked_state_fields_bind_the_exact_single_CRT_cell(self):
        coff=ConsumerCoff();shape=c.consumer_shape(coff,'sp1');m=mapping()
        for i,s in coff.symbols.items():
            if s['section']>0:m[s['name']]=dict(address=0x401300+s['section']*32,owner='sp1.obj')
        class FieldPe:
            base=0x400000
            def read_rva(self,rva,size,allow_code=False):return struct.pack('<i',self.fields[rva])
        pe=FieldPe();pe.fields={}
        for name in [r['symbol'] for r in shape['protected_functions']]+['init','_fnv_bootstrap_sp1_register']:
            s=c.one(coff,name)
            for offset,index,kind in coff.sections[s['section']]['relocs']:
                target=coff.symbols[index]['name']
                if target not in ('___security_cookie','@__security_check_cookie@4','_atexit'):continue
                field=m[name]['address']+offset
                pe.fields[field-pe.base]=m[target]['address']-(field+4) if kind==20 else m[target]['address']
        self.assertEqual(len(c.linked_consumer_fields(pe,m,coff,shape)),8)
        pe.fields[m[shape['protected_functions'][0]['symbol']]['address']-pe.base]+=4
        with self.assertRaisesRegex(ValueError,'canonical CRT state'):c.linked_consumer_fields(pe,m,coff,shape)

    def test_wrong_CRT_owner_duplicate_map_and_directives_rejected(self):
        m=mapping();m['_atexit']['owner']='f other-runtime:exit.obj'
        with self.assertRaisesRegex(ValueError,'provider'):c.validate_link(LinkedPe(),m,['ctor'],'control-host.obj')
        with self.assertRaisesRegex(ValueError,'duplicate'):c.map_symbols(' 0001:00000000 x 00401000 f a.obj\n 0001:00000001 x 00401001 f a.obj')
        with self.assertRaisesRegex(ValueError,'duplicate'):c.map_symbols(' 0001:00000000 x 00401000 f a.obj\n 0001:00000000 x 00401000 f b.obj')
        coff=EarlyCoff();coff.directives=['/DEFAULTLIB:"LIBCMT"','/DEFAULTLIB:"OLDNAMES"','/FORCE:MULTIPLE']
        with self.assertRaisesRegex(ValueError,'directives'):c.validate_directives(coff)

    def test_include_context_is_exact_and_bounded_to_roots(self):
        with tempfile.TemporaryDirectory() as tmp:
            path=Path(tmp)/'header.h';path.write_text('original fixture')
            self.assertEqual(c.includes('Note: including file: '+str(path),[Path(tmp)]),{path.resolve()})
            (Path(tmp)/'other').mkdir()
            with self.assertRaises(ValueError):c.includes('Note: including file: '+str(path),[Path(tmp)/'other'])
            with self.assertRaises(ValueError):c.includes('no include observations',[Path(tmp)])

    def test_explicit_include_root_is_canonicalized_consistently(self):
        with tempfile.TemporaryDirectory() as tmp:
            base=Path(tmp);(base/'anchor').mkdir();approved=base/'approved';approved.mkdir()
            header=approved/'header.h';header.write_text('original fixture')
            logical=base/'anchor'/'..'/'approved'
            snapshot=c.capture_include_roots([logical])
            self.assertEqual(c.includes('Note: including file: '+str(header),[logical],snapshot),{header.resolve()})

    def test_nested_junction_escape_and_root_repointing_are_rejected(self):
        with tempfile.TemporaryDirectory() as tmp:
            base=Path(tmp);approved=base/'approved';outside=base/'outside';alias=base/'alias'
            for p in (approved,outside,alias):p.mkdir()
            (approved/'header.h').write_text('approved');(outside/'header.h').write_text('outside')
            original_resolve=Path.resolve;target=[approved];escaped=approved/'nested'/'header.h'
            def resolve(path,*args,**kwargs):
                # Original synthetic junction semantics, without requiring
                # Windows symlink privileges or invoking a system utility.
                if path==alias:return original_resolve(target[0],*args,**kwargs)
                if path==alias/'header.h':return original_resolve(target[0]/'header.h',*args,**kwargs)
                if path==escaped:return original_resolve(outside/'header.h',*args,**kwargs)
                return original_resolve(path,*args,**kwargs)
            with patch.object(Path,'resolve',autospec=True,side_effect=resolve):
                snapshot=c.capture_include_roots([alias])
                self.assertEqual(c.includes('Note: including file: '+str(alias/'header.h'),[alias],snapshot),{approved/'header.h'})
                with self.assertRaisesRegex(ValueError,'unapproved'):c.includes('Note: including file: '+str(escaped),[alias],snapshot)
                target[0]=outside
                with self.assertRaisesRegex(ValueError,'repointed'):c.verify_include_roots(snapshot)

    def test_same_path_replaced_root_directory_changes_identity(self):
        with tempfile.TemporaryDirectory() as tmp:
            base=Path(tmp);approved=base/'approved';approved.mkdir();snapshot=c.capture_include_roots([approved])
            approved.rename(base/'previous');approved.mkdir()
            with self.assertRaisesRegex(ValueError,'identity changed'):c.verify_include_roots(snapshot)

    def test_control_uses_the_same_three_sources_under_SP1(self):
        jobs={row[0]:row for row in c.compile_jobs()}
        self.assertEqual([jobs[n][1] for n in c.LAYOUT_OBJECTS['control']],['sp1','sp1','sp1'])
        self.assertEqual([jobs[n][1] for n in c.LAYOUT_OBJECTS['mixed']],['sp1','rtm','vc8'])
        for control,mixed in zip(c.LAYOUT_OBJECTS['control'],c.LAYOUT_OBJECTS['mixed']):
            self.assertEqual(jobs[control][2:],jobs[mixed][2:])

    def test_explicit_named_API_policy_rejects_unknown_ordinal_and_missing(self):
        rows=api_records();self.assertEqual(set(c.validate_imports(rows)),c.REQUIRED_APIS)
        for bad in (rows[:-1],rows+[rows[0]],rows+[dict(dll='KERNEL32.dll',export=dict(kind='name',name='CreateRemoteThread'))],
                    rows+[dict(dll='KERNEL32.dll',export=dict(kind='ordinal',ordinal=1))],
                    rows+[dict(dll='msvcr90.dll',export=dict(kind='name',name='WriteFile'))]):
            with self.assertRaises(ValueError):c.validate_imports(bad)

    def test_library_search_shadows_and_actual_unbound_resolution_fail(self):
        with tempfile.TemporaryDirectory() as tmp:
            root=Path(tmp);work=root/'work';vc=root/'vc';sdk=root/'sdk'
            for p in (work,vc,sdk):p.mkdir()
            for p in (vc/'libcmt.lib',vc/'oldnames.lib',sdk/'kernel32.lib',sdk/'uuid.lib'):p.write_bytes(b'original fixture library')
            expected=c.controlled_libraries(work,vc,sdk)
            text='\n'.join('Searching '+v['path']+':\n Loaded '+name+'(fixture.obj)' for name,v in expected.items())
            self.assertEqual(set(c.verify_library_log(text,expected)['searches']),set(c.LIBRARY_NAMES))
            for shadow in (work/'libcmt.lib',vc/'uuid.lib'):
                shadow.write_bytes(b'shadow')
                with self.assertRaisesRegex(ValueError,'competing'):c.controlled_libraries(work,vc,sdk)
                shadow.unlink()
            unbound=work/'evil.lib';unbound.write_bytes(b'unbound')
            with self.assertRaisesRegex(ValueError,'unbound'):c.verify_library_log(text+'\nSearching '+str(unbound)+':',expected)
            with self.assertRaisesRegex(ValueError,'context'):c.verify_library_log('Loaded libcmt.lib(other.obj)\n'+text,expected)
            (vc/'libcmt.lib').write_bytes(b'changed')
            with self.assertRaisesRegex(ValueError,'changed'):c.verify_library_log(text,expected)

    def test_map_contributors_and_exact_UUID_request_count(self):
        with tempfile.TemporaryDirectory() as tmp:
            obj=Path(tmp)/'host.obj';obj.write_bytes(b'fixture')
            good={'a':dict(owner='f host.obj'),'b':dict(owner='f LIBCMT:normal.obj'),
                  'i':dict(owner='i KERNEL32:KERNEL32.dll')}
            archive=unittest.mock.Mock();archive.prove.return_value=dict(kind='archive-member',member_header_offset=1)
            libs={n:dict(sha256='0'*64,path='unused') for n in c.LIBRARY_NAMES}
            with patch.object(c,'bound_library'):
                self.assertEqual(len(c.validate_contributors(good,[obj],libs,{n:archive for n in libs})),3)
            for owner in ('f surprise.obj','f MSVCRT:foreign.obj','<linker-defined>'):
                with patch.object(c,'bound_library'):
                    with self.assertRaises(ValueError):c.validate_contributors(dict(good,bad=dict(owner=owner)),[obj],libs,{n:archive for n in libs})
        coff=EarlyCoff();coff.directives=['/DEFAULTLIB:"uuid.lib"','/DEFAULTLIB:"uuid.lib"',
            '/DEFAULTLIB:"LIBCMT"','/DEFAULTLIB:"OLDNAMES"','/include:_fnv_bootstrap_early_slot']
        c.validate_directives(coff,True)
        coff.directives.append('/DEFAULTLIB:"uuid.lib"')
        with self.assertRaises(ValueError):c.validate_directives(coff,True)

    def test_windows_case_alias_and_search_only_evidence(self):
        with tempfile.TemporaryDirectory() as tmp:
            root=Path(tmp);libs={}
            for name in c.LIBRARY_NAMES:
                path=root/name;path.write_bytes(b'original')
                libs[name]=c.file_identity(path)
            log='\n'.join('Searching '+row['path']+':' for row in libs.values())
            result=c.verify_library_log(log,libs)
            self.assertEqual(result['loaded_members'],[])
            self.assertFalse(result['selected_member_evidence_complete'])
            self.assertIn('search-only',result['log_mode'])
            if c.os.name=='nt':
                c.bound_library(root/'Uuid.Lib',libs['uuid.lib'])
            other=root/'else.lib';other.write_bytes(b'original')
            with self.assertRaises(ValueError):c.bound_library(other,libs['uuid.lib'])

    def test_missing_and_ambiguous_archive_provider_fail(self):
        archive=unittest.mock.Mock();archive.prove.return_value=None
        libs={'libcmt.lib':dict(sha256='0'*64,path='unused')}
        mapping={'x':dict(owner='f LIBCMT:member.obj',address=1)}
        with self.assertRaisesRegex(ValueError,'missing exact'):
            c.validate_contributors(mapping,[],libs,{'libcmt.lib':archive})
        archive.common.return_value=dict(kind='archive-common',unique_strong_owner_claimed=False)
        libs['oldnames.lib']=dict(sha256='1'*64,path='unused')
        with self.assertRaisesRegex(ValueError,'ambiguous common'):
            c.validate_contributors({'x':dict(owner='<common>',address=1)},[],libs,
                                   {n:archive for n in libs})

    def test_archive_index_member_and_common_definition_metadata(self):
        # Original minimal archive with one external tentative COFF symbol.
        payload=struct.pack('<HHIIIHH',0x14c,0,0,20,1,0,0)
        payload+=struct.pack('<8sIhHBB',b'x',4,0,0,2,0)+struct.pack('<I',4)
        def member(name,body):
            header=(name.ljust(16)+'0'.ljust(12)+'0'.ljust(6)+'0'.ljust(6)+'0'.ljust(8)+str(len(body)).ljust(10)+'`\n').encode()
            return header+body+(b'\n' if len(body)%2 else b'')
        index_size=10;offset=8+60+index_size
        data=b'!<arch>\n'+member('/',struct.pack('>II',1,offset)+b'x\0')+member('member.obj/',payload)
        with tempfile.TemporaryDirectory() as tmp:
            path=Path(tmp)/'libcmt.lib';path.write_bytes(data)
            archive=c.ArchiveEvidence(c.file_identity(path))
            proof=archive.prove('x',kind='archive-common')
            self.assertFalse(proof['unique_strong_owner_claimed'])
            self.assertTrue(proof['symbol_index_join'])
            self.assertIsNone(archive.prove('missing','member.obj'))
            self.assertIsNone(archive.prove('x',kind='archive-absolute',value=4))
            self.assertIsNone(archive.common('x',set()))
            self.assertEqual(archive.common('x',{offset})['declarations'][0]['size'],4)
            archive.names[offset+1]='member.obj';archive.members[offset+1]=archive.members[offset]
            # The second same-name member is deliberately NOT indexed.
            with self.assertRaisesRegex(ValueError,'ambiguous'):archive.prove('x','member.obj')
            archive.cache[offset+1]=None
            # A short-import member without an exact index entry is no proof.
            self.assertIsNotNone(archive.prove('x','member.obj'))
            archive.index['x'].append(offset+1)
            with self.assertRaisesRegex(ValueError,'ambiguous'):archive.prove('x','member.obj')

    def test_no_optin_no_review_stale_source_never_invokes_native_tools(self):
        with patch.object(c.toolchain,'run') as native:
            with self.assertRaisesRegex(ValueError,'opt-in'):c.prepare(argparse.Namespace(allow_native_prepare=False))
            native.assert_not_called()
        with tempfile.TemporaryDirectory() as tmp:
            path=Path(tmp)/'review.json'
            review=dict(schema_version=1,kind='crt-bootstrap-source-review',status='approved',reviewer='synthetic reviewer',
                allow_prepare=True,allow_execute=False,sources=c.source_manifest(),checks={k:True for k in c.SOURCE_CHECKS})
            path.write_text(json.dumps(review));digest=c.sha(path)
            self.assertEqual(c.source_review(path,digest)['reviewer'],'synthetic reviewer')
            review['sources']['runtime/probes/crt_bootstrap_host.cpp']='0'*64;path.write_text(json.dumps(review))
            args=argparse.Namespace(allow_native_prepare=True,source_review=path,source_review_sha256=c.sha(path))
            with patch.object(c.toolchain,'run') as native:
                with self.assertRaisesRegex(ValueError,'source review hashes'):c.prepare(args)
                native.assert_not_called()


if __name__=='__main__':unittest.main()
