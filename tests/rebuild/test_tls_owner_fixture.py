"""Original synthetic TLS metadata and receipt tests; never compile or execute."""
import copy
import json
from pathlib import Path
import struct
import subprocess
import sys
import tempfile
import unittest
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[2]/'tools/rebuild'))
import tls_owner_fixture as tls


def coff_file(path, sections, symbols, relocations):
    sections = list(sections)+[('.drectve', (' '+' '.join(tls.SOURCE_DIRECTIVES)+' ').encode(), 0x00100a00)]
    strings, records = bytearray(4), bytearray()
    for name, value, section, typ, storage in symbols:
        encoded = name.encode()
        if len(encoded) > 8:
            field = struct.pack('<II', 0, len(strings)); strings += encoded+b'\0'
        else:
            field = encoded.ljust(8, b'\0')
        records += struct.pack('<8sIhHBB', field, value, section, typ, storage, 0)
    headers, body, cursor = bytearray(), bytearray(), 20+40*len(sections)
    for index, (name, data, flags) in enumerate(sections, 1):
        raw = cursor; body += data; cursor += len(data)
        relptr = cursor if relocations.get(index) else 0
        for offset, target, kind in relocations.get(index, []):
            body += struct.pack('<IIH', offset, target, kind); cursor += 10
        headers += struct.pack('<8sIIIIIIHHI', name.encode(), 0, 0, len(data), raw, relptr, 0, len(relocations.get(index, [])), 0, flags)
    struct.pack_into('<I', strings, 0, len(strings))
    path.write_bytes(struct.pack('<HHIIIHH', 0x14c, len(sections), 0, cursor, len(symbols), 0, 0)+headers+body+records+strings)


def original_objects(root, *, owner_size=704, owner_flags=0xc0300040, kind=11, duplicate=False, callback_target=None):
    feature = ('@feat.00', 1, -1, 0, 3)
    data = bytearray(12); struct.pack_into('<I', data, 8, 0x264)
    paths = {name: root/(name+'.obj') for name in ('storage', 'callback', 'main')}
    coff_file(paths['storage'], [('.tls$', tls.authored_owner()[:owner_size], owner_flags), ('.text', data, 0x60300020)],
        [feature, (tls.OWNER, 0, 1, 0, 2), ('_probe', 0, 2, 32, 2),
         ('__tls_index', 0, 1 if duplicate else 0, 0, 2), ('__tls_array', 0, 0, 0, 2)],
        {2: [(0, 3, 6), (4, 4, 6), (8, 1, kind)]})
    coff_file(paths['callback'], [('.CRT$XLB', bytes(4), 0x40300040), ('.text', bytes(4), 0x60300020)],
        [feature, (tls.ENTRY, 0, 1, 0, 2), (callback_target or tls.CALLBACK, 0, 2, 32, 2)], {1: [(0, 2, 6)]})
    coff_file(paths['main'], [('.text', bytes(1), 0x60300020)], [feature, ('_main', 0, 1, 32, 2)], {})
    return paths


def image_file(path, mp, *, shifted=False, wrong_callback=False, bad_secrel=False, wrong_extent=False, code_change=False, extra_tls_fixup=False,
               config_size=72, structure_size=72, handler_rva=0x1000, table_rva=0x20d0):
    base = 0x400000
    data = bytearray(0x1000); data[:2] = b'MZ'; struct.pack_into('<I', data, 0x3c, 0x80)
    data[0x80:0x84] = b'PE\0\0'; struct.pack_into('<HHIIIHH', data, 0x84, 0x14c, 5, 0, 0, 0, 224, 0x102)
    opt = 0x98
    struct.pack_into('<H', data, opt, 0x10b); struct.pack_into('<I', data, opt+28, base)
    struct.pack_into('<II', data, opt+32, 0x1000, 0x200); struct.pack_into('<II', data, opt+56, 0x6000, 0x400)
    struct.pack_into('<I', data, opt+92, 16)
    for index, rva, size in [(9, 0x2000, 24), (10, 0x2080, config_size), (5, 0x5000, 44 if extra_tls_fixup else 32)]:
        struct.pack_into('<II', data, opt+96+index*8, rva, size)
    rows = [(b'.text',0x100,0x1000,0x200,0x400,0x60000020), (b'.rdata',0x200,0x2000,0x200,0x600,0x40000040),
            (b'.data',0x300,0x3000,0x200,0x800,0xc0000040), (b'.tls',709,0x4000,0x400,0xa00,0xc0000040),
            (b'.reloc',0x200,0x5000,0x200,0xe00,0x42000040)]
    for i, (name, size, rva, rawsize, raw, flags) in enumerate(rows):
        struct.pack_into('<8sIIIIIIHHI', data, opt+224+i*40, name,size,rva,rawsize,raw,0,0,0,0,flags)
    struct.pack_into('<6I', data, 0x600, base+0x4000, base+0x42c0 if wrong_extent else base+0x42c4, base+0x3200, base+0x2044, 0, 0)
    struct.pack_into('<3I', data, 0x640, 0, base+(0x1004 if wrong_callback else 0x1000), 0)
    struct.pack_into('<I', data, 0x680, structure_size); struct.pack_into('<II', data, 0x6c0, base+table_rva, 1); struct.pack_into('<I', data, 0x6d0, handler_rva)
    data[0xa00:0xcc4] = bytes(4)+tls.authored_owner()
    struct.pack_into('<3I', data, 0x410, base+0x3200, 44, 0x26c if bad_secrel else 0x268)
    if code_change: data[0x480] = 1
    struct.pack_into('<II6H', data, 0xe00, 0x2000, 20, 0x3000,0x3004,0x3008,0x300c,0x3044,0x30c0)
    struct.pack_into('<II2H', data, 0xe14, 0x1000, 12, 0x3010,0)
    if extra_tls_fixup: struct.pack_into('<II2H', data, 0xe20, 0x4000, 12, 0x3000,0)
    mapped = {
        '__tls_start': (base+0x4000,'LIBCMT:tlssup.obj'), '__tls_end': (base+0x42c4,'LIBCMT:tlssup.obj'),
        '__tls_index': (base+0x3200,'LIBCMT:tlssup.obj'), '__tls_used': (base+0x2000,'LIBCMT:tlssup.obj'),
        '___xl_a': (base+0x2040,'LIBCMT:tlssup.obj'), '___xl_z': (base+0x2048,'LIBCMT:tlssup.obj'),
        '__tls_array': (44,'<absolute>'), tls.OWNER: (base+(0x4008 if shifted else 0x4004),'storage.obj'),
        tls.CALLBACK: (base+0x1000,'callback.obj'), tls.ENTRY: (base+0x2044,'callback.obj'),
        '_probe': (base+0x1010,'storage.obj'), '_main': (base+0x1080,'main.obj')}
    for i, name in enumerate(('_mainCRTStartup','_printf','_exit','___security_cookie','@__security_check_cookie@4')):
        mapped[name] = (base+0x1030+i*4,'LIBCMT:normal.obj')
    path.write_bytes(data)
    mp.write_text('\n'.join(' 0001:00000000 %s %08x %s' % (name, address, provider) for name,(address,provider) in mapped.items()))


def os_export_file(path, mapfile, *, forwarder=None, data_export=False, bad_ordinal=False):
    image_file(path,mapfile)
    data=bytearray(path.read_bytes())
    struct.pack_into('<II',data,0x98+96,0x2100,0x100)
    struct.pack_into('<IIHHIIIIIII',data,0x700,0,0,0,0,0,1,1,1,0x2140,0x2144,0x2148)
    struct.pack_into('<I',data,0x740,0x2180 if forwarder else 0x3000 if data_export else 0x1000)
    struct.pack_into('<I',data,0x744,0x2150);struct.pack_into('<H',data,0x748,1 if bad_ordinal else 0)
    data[0x750:0x756]=b'Probe\0'
    if forwarder:
        value=forwarder.encode()+b'\0';data[0x780:0x780+len(value)]=value
    path.write_bytes(data)


class TlsOwnerTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory(); self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)

    def test_authored_owner_extent_alignment_and_aliases(self):
        contract = tls.source_contract(original_objects(self.root))
        self.assertEqual(len(tls.authored_owner()), 704)
        self.assertEqual(tls.authored_owner()[0x264], 1)
        self.assertEqual(struct.unpack_from('<i', tls.authored_owner(), 0x2b0)[0], 37)
        self.assertEqual(contract[0]['tls_fields'][-1]['addend'], 0x264)

    def test_source_rejects_extent_v1_alignment8_and_wrong_secrel(self):
        for options in ({'owner_size':700}, {'owner_flags':0xc0400040}, {'kind':6}):
            with self.subTest(options=options):
                with self.assertRaises(ValueError): tls.source_contract(original_objects(self.root, **options))

    def test_duplicate_infrastructure_and_wrong_callback_rejected(self):
        for options in ({'duplicate':True}, {'callback_target':'_UnapprovedCallback@12'}):
            with self.subTest(options=options):
                with self.assertRaises(ValueError): tls.source_contract(original_objects(self.root, **options))

    def test_unknown_source_directive_rejected(self):
        objects = original_objects(self.root)
        data = objects['main'].read_bytes().replace(b'LIBCMT', b'LIBXXX')
        objects['main'].write_bytes(data)
        with self.assertRaisesRegex(ValueError, 'directive'): tls.source_contract(objects)

    def inspect(self, **options):
        objects = original_objects(self.root)
        contract = tls.source_contract(objects)
        image, mp = self.root/'fixture.exe', self.root/'fixture.map'
        image_file(image, mp, **options)
        return tls.inspect_link(image, mp, contract, 0x400000)

    def test_actual_module_template_marker_and_secrel_proof(self):
        report = self.inspect()
        self.assertEqual(report['template_size'], 708)
        self.assertEqual(report['markers'], dict(start_bytes=1, alignment_padding=3, end_bytes=1))
        self.assertEqual((report['owner_offset'],report['flag_offset'],report['context_offset']), (4,0x268,0x2b4))
        self.assertEqual(report['tls_array_absolute_constant'], 44)

    def test_shifted_owner_wrong_secrel_extent_callback_and_code_fail(self):
        for options in ({'shifted':True},{'bad_secrel':True},{'wrong_extent':True},{'wrong_callback':True},{'code_change':True},{'extra_tls_fixup':True}):
            with self.subTest(options=options):
                with self.assertRaises(ValueError): self.inspect(**options)

    def test_vc9_advertised64_requires_raw_backed_self_sized72(self):
        report = self.inspect(config_size=64)
        self.assertEqual(report['safe_seh_advertised_size'],64)
        self.assertEqual(report['safe_seh_structure_size'],72)
        for options in ({'config_size':60},{'structure_size':64},{'handler_rva':0x3000},{'table_rva':0x20d1},{'table_rva':0x21ff}):
            with self.subTest(options=options):
                with self.assertRaises(ValueError):self.inspect(**options)
        objects=original_objects(self.root);contract=tls.source_contract(objects)
        image,mp=self.root/'truncated.exe',self.root/'truncated.map';image_file(image,mp,config_size=64)
        data=bytearray(image.read_bytes())
        # Header declaration is 64, but logical .rdata stops before all 72 bytes.
        struct.pack_into('<I',data,0x98+224+40+8,0xc0)
        image.write_bytes(data)
        with self.assertRaises(ValueError):tls.inspect_link(image,mp,contract,0x400000)

    def test_actual_header_trace_is_bounded_and_header_backend_drift_fails(self):
        allowed=self.root/'include';allowed.mkdir();header=allowed/'fixture.hpp';header.write_text('original header')
        trace='Note: including file: '+str(header)+'\n'
        self.assertEqual(tls.include_paths(trace,[allowed]),[header.resolve()])
        expected={str(header):tls.sha(header)};tls.check_stable(expected)
        header.write_text('changed');
        with self.assertRaisesRegex(ValueError,'changed'):tls.check_stable(expected)
        backend=self.root/'c2.dll';backend.write_text('original backend');expected={str(backend):tls.sha(backend)};backend.write_text('changed backend')
        with self.assertRaises(ValueError):tls.check_stable(expected)
        outside=self.root/'outside.h';outside.write_text('outside')
        with self.assertRaises(ValueError):tls.include_paths('Note: including file: '+str(outside),[allowed])
        with self.assertRaises(ValueError):tls.include_paths('no actual include trace',[allowed])

    def test_named_api_gate_rejects_other_api_ordinal_dll_and_missing_required(self):
        records=[dict(dll='KERNEL32.dll',export=dict(kind='name',name=name)) for name in sorted(tls.REQUIRED_APIS)]
        tls.validate_imports(records)
        for extra in (dict(dll='KERNEL32.dll',export=dict(kind='name',name='LoadLibraryExW')),
                      dict(dll='KERNEL32.dll',export=dict(kind='ordinal',ordinal=1)),
                      dict(dll='USER32.dll',export=dict(kind='name',name='WriteFile'))):
            with self.assertRaises(ValueError):tls.validate_imports(records+[extra])
        with self.assertRaises(ValueError):tls.validate_imports(records[1:])

    def test_exact_reviewed_crt_api_members_have_positive_and_missing_member_gate(self):
        apis=tls.REQUIRED_APIS | tls.REVIEWED_CRT_API_MEMBERS.keys()
        records=[dict(dll='KERNEL32.dll',export=dict(kind='name',name=name)) for name in sorted(apis)]
        self.assertEqual(set(tls.validate_imports(records)),set(apis))
        rows={name:[dict(provider='f LIBCMT:'+name)] for members in tls.REVIEWED_CRT_API_MEMBERS.values() for name in members}
        self.assertEqual(set(tls.reviewed_crt_import_members(apis,rows)),set(tls.REVIEWED_CRT_API_MEMBERS))
        del rows['tidtable.obj']
        with self.assertRaisesRegex(ValueError,'member absent'):tls.reviewed_crt_import_members(apis,rows)

    def test_changed_whole_crt_archive_rejects_before_member_parse(self):
        path=self.root/'unreviewed.lib';path.write_text('not the reviewed normal CRT')
        with patch.object(tls,'archive_member') as member:
            with self.assertRaisesRegex(ValueError,'whole CRT'):tls.crt_contract(path)
            member.assert_not_called()

    def test_actual_os_export_forwarding_files_are_read_only_and_hash_bound(self):
        sysdir=self.root/'syswow64';sysdir.mkdir()
        for name,forwarder in [('kernel32.dll','kernelbase.Probe'),('kernelbase.dll',None),('ntdll.dll',None)]:
            os_export_file(sysdir/name,self.root/(name+'.map'),forwarder=forwarder)
        dependencies,evidence=tls.os_export_identities(sysdir,['Probe'])
        self.assertEqual(len(dependencies),3)
        self.assertEqual(len(evidence['named_forwarding_chains']['Probe']),2)
        self.assertTrue(all(tls.sha(path)==digest for path,digest in dependencies.items()))
        self.assertEqual(evidence['named_forwarding_chains']['Probe'][-1]['rva'],0x1000)

    def test_os_export_cycles_unresolved_modules_and_data_targets_reject(self):
        sysdir=self.root/'syswow64';sysdir.mkdir()
        for name in ('kernelbase.dll','ntdll.dll'):
            os_export_file(sysdir/name,self.root/(name+'.map'))
        for options in ({'forwarder':'missing.Probe'},{'forwarder':'../bad.Probe'},{'data_export':True},{'bad_ordinal':True}):
            os_export_file(sysdir/'kernel32.dll',self.root/'kernel32.map',**options)
            with self.subTest(options=options):
                with self.assertRaises(ValueError):tls.os_export_identities(sysdir,['Probe'])
        os_export_file(sysdir/'kernel32.dll',self.root/'kernel32.map',forwarder='kernelbase.Probe')
        os_export_file(sysdir/'kernelbase.dll',self.root/'kernelbase.map',forwarder='kernel32.Probe')
        with self.assertRaisesRegex(ValueError,'cycle'):tls.os_export_identities(sysdir,['Probe'])

    def library_fixture(self):
        work,vc,sdk=[self.root/name for name in ('work','vc','sdk')]
        for path in (work,vc,sdk):path.mkdir()
        for parent,name in ((vc,'libcmt.lib'),(vc,'oldnames.lib'),(sdk,'kernel32.lib'),(sdk,'uuid.lib')):
            (parent/name).write_text('original named library')
        return work,vc,sdk

    def test_earlier_competing_library_and_search_hash_drift_fail(self):
        work,vc,sdk=self.library_fixture()
        expected=tls.controlled_libraries(work,vc,sdk)
        snapshot={path:tls.sha(path) for path in expected.values()}
        for earlier in (work,vc):
            (earlier/'uuid.lib').write_text('competing earlier library')
            with self.assertRaisesRegex(ValueError,'competing'):tls.controlled_libraries(work,vc,sdk)
            (earlier/'uuid.lib').unlink()
        (sdk/'uuid.lib').write_text('changed actual provider')
        with self.assertRaises(ValueError):tls.check_stable(snapshot)

    def test_verbose_library_evidence_must_name_exact_bound_paths(self):
        work,vc,sdk=self.library_fixture();expected=tls.controlled_libraries(work,vc,sdk)
        log='\n'.join('    Searching '+path+':' for path in expected.values())
        self.assertEqual(tls.verify_library_log(log,expected),expected)
        for bad in (log.replace(expected['uuid.lib'],str(vc/'uuid.lib')),
                    log.replace(expected['uuid.lib'],'uuid.lib'),
                    '\n'.join(log.splitlines()[:-1]), log+'\n Searching '+str(sdk/'other.lib')+':'):
            with self.assertRaises(ValueError):tls.verify_library_log(bad,expected)

    def test_no_game_input_or_image_emitter_interface(self):
        self.assertNotIn('game', tls.POLICY)
        self.assertTrue(all(p.name.startswith('tls_owner_') for p in tls.SOURCES))
        self.assertEqual({p.suffix for p in tls.SOURCES}, {'.hpp','.cpp'})

    def test_two_thread_state_and_process_detach_receipts_required(self):
        text = json.dumps(tls.EXPECTED)+'\n'+json.dumps(tls.DETACH)+'\n'
        tls.parse_result(text, '', 0)
        for key, value in [('threads',1),('initial_checks',2),('main_preserved',False),('callbacks',4),('blocks_distinct',False)]:
            bad = dict(tls.EXPECTED); bad[key] = value
            with self.assertRaises(ValueError): tls.parse_result(json.dumps(bad)+'\n'+json.dumps(tls.DETACH)+'\n','',0)
        with self.assertRaises(ValueError): tls.parse_result(json.dumps(tls.EXPECTED)+'\n','',0)
        with self.assertRaises(ValueError): tls.parse_result(text,'diagnostic',0)
        with self.assertRaises(ValueError): tls.parse_result(text,'',33)

    def pair(self):
        variants, artifacts = [], {}
        for name in ('normal','moved'):
            exe, mp = self.root/(name+'.exe'), self.root/(name+'.map')
            exe.write_text('never run'); mp.write_text('map')
            variants.append(dict(name=name,exe=str(exe),map=str(mp),exe_sha256=tls.sha(exe),map_sha256=tls.sha(mp)))
            artifacts.update({str(exe):tls.sha(exe),str(mp):tls.sha(mp)})
        p = dict(schema_version=1,kind='original-tls-owner-prepared',policy=tls.POLICY,status='prepared_pending_independent_review',
            execution_performed=False,expected_main=tls.EXPECTED,expected_detach=tls.DETACH,variants=variants,inputs={},artifacts=artifacts,os_dependencies={})
        r = dict(schema_version=1,kind='original-tls-owner-review',approved=True,reviewer='independent',prepare_sha256='b'*64,
            variants=[{k:v[k] for k in ('name','exe_sha256','map_sha256')} for v in variants],
            checks={k:True for k in ('source_and_crt','template_layout','secrel_and_module_offsets','callback_identity_and_safety','safe_seh','map_imports','os_export_identities','protected_artifacts')})
        return p,r

    def saved_pair(self):
        p,r = self.pair(); pp,rp = self.root/'prepare.json',self.root/'review.json'
        tls.save(pp,p);r['prepare_sha256']=tls.sha(pp);tls.save(rp,r)
        return p,pp,rp

    def test_review_requires_exact_two_artifacts_and_complete_checks(self):
        p,r = self.pair(); tls.validate_review(p,r,'b'*64)
        for key,value in [('checks',{}),('approved',False),('prepare_sha256','c'*64),('variants',r['variants'][:1])]:
            bad=copy.deepcopy(r);bad[key]=value
            with self.assertRaises(ValueError):tls.validate_review(p,bad,'b'*64)
        del p['artifacts'][p['variants'][0]['exe']]
        with self.assertRaises(ValueError):tls.validate_review(p,r,'b'*64)

    def test_stale_review_existing_receipt_and_collision_never_launch(self):
        p,pp,rp=self.saved_pair()
        with patch.object(tls.subprocess,'run') as run:
            with self.assertRaises(ValueError):tls.execute(pp,rp,'c'*64,self.root/'result.json')
            with self.assertRaises(ValueError):tls.execute(pp,rp,tls.sha(rp),pp)
            run.assert_not_called()

    def test_changed_pe_before_or_during_final_child_fails(self):
        p,pp,rp=self.saved_pair(); calls=[]
        text=json.dumps(tls.EXPECTED)+'\n'+json.dumps(tls.DETACH)+'\n'
        def child(*args,**kwargs):
            calls.append(args)
            if len(calls)==2:Path(p['variants'][1]['exe']).write_text('changed while child ran')
            return subprocess.CompletedProcess(args,0,text,'')
        with patch.object(tls.subprocess,'run',side_effect=child):
            result=tls.execute(pp,rp,tls.sha(rp),self.root/'result.json')
        self.assertEqual(len(calls),2);self.assertEqual(result['status'],'error')
        self.assertIn('during child',result['error'])

    def test_timeout_is_bounded_terminal_failure_receipt(self):
        p,pp,rp=self.saved_pair()
        with patch.object(tls.subprocess,'run',side_effect=subprocess.TimeoutExpired('own fixture',45)):
            result=tls.execute(pp,rp,tls.sha(rp),self.root/'result.json')
        self.assertEqual(result['status'],'error');self.assertEqual(result['variants'],[dict(name='normal',status='timeout')])


if __name__ == '__main__':unittest.main()
