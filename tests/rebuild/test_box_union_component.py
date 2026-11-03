"""Authored synthetic caller COFF and source-policy tests; no native processes."""
import argparse
import copy
import json
import io
import struct
from pathlib import Path
import sys
import tempfile
import unittest
from unittest.mock import patch

sys.path.insert(0,str(Path(__file__).resolve().parents[2]/'tools/rebuild'))
import box_union_component as box
from test_coff_code_archive import object_bytes,section,symbol,aux


def fixture(change=None):
    sections=[section('.text',b'\xe8\0\0\0\0'*3+b'\xc3',relocs=[(1,3,20),(6,4,20),(11,5,20)])]
    symbols=[symbol('.text',1,storage=3,auxiliary=aux(16,3)),symbol('_authored_caller',1,typ=32)]
    symbols.extend(symbol(name,0,typ=32) for name in box.ROOTS.values())
    if change:change(sections,symbols)
    data=object_bytes(sections,symbols)
    names={address:'_fnv_code_'+str(i)*64 for i,address in enumerate(box.ROOTS,1)}
    return data,names


class BoxUnionTests(unittest.TestCase):
    def test_no_native_opt_in_fails_before_any_file_or_tool(self):
        with patch.object(box,'sha',side_effect=AssertionError('file accessed')),patch.object(box.toolchain,'run',side_effect=AssertionError('native call')):
            with self.assertRaisesRegex(ValueError,'separate explicit root'):
                box.prepare(argparse.Namespace(allow_native_prepare=False))

    def test_original_full_declarations_and_real_types(self):
        header=(box.ROOT/'runtime/probes/box_union_probe.hpp').read_text()
        box.validate_declarations(header,header.replace('public:','public :'))
        self.assertEqual(set(box.declarations(header)),{'FUN_00db0920','FUN_00db0920_cls','BoxPointLookup','BoxPointInsertion'})
        for old,new in [('Entry entries[8]','Entry entries[9]'),('unsigned short value','unsigned int value'),
                        ('public FUN_00db0920','public BoxPointLookup'),('unsigned int a','unsigned short a')]:
            with self.assertRaisesRegex(ValueError,'declaration/layout'):
                box.validate_declarations(header,header.replace(old,new))

    def test_declaration_missing_or_duplicate_rejected(self):
        header=(box.ROOT/'runtime/probes/box_union_probe.hpp').read_text()
        with self.assertRaisesRegex(ValueError,'missing/duplicate'):
            box.declarations(header+ '\nstruct FUN_00db0920 { int fake; };')
        with self.assertRaisesRegex(ValueError,'missing/duplicate'):
            box.declarations(header.replace('class BoxPointLookup','class NotTheOriginalLookup'))

    def test_three_natural_undefined_calls_name_only(self):
        raw,names=fixture();result,contract=box.bind_caller(raw,names)
        before,after=box.coff.parse(raw),box.coff.parse(result)
        self.assertEqual(before['sections'],after['sections'])
        self.assertEqual(list(before['symbols']),list(after['symbols']))
        self.assertEqual({c['canonical_name'] for c in contract['calls']},set(names.values()))
        self.assertEqual([c['physical_index'] for c in contract['calls']],[3,4,5])
        self.assertEqual(sum(len(c['uses']) for c in contract['calls']),3)
        self.assertFalse(contract['abi_adapter_emitted'])

    def test_wrong_provider_set_or_duplicate_target_rejected(self):
        raw,names=fixture();names.pop(next(iter(names)))
        with self.assertRaisesRegex(ValueError,'namespace'):box.bind_caller(raw,names)
        raw,names=fixture();values=list(names);names[values[1]]=names[values[0]]
        with self.assertRaisesRegex(ValueError,'namespace'):box.bind_caller(raw,names)

    def test_defined_common_wrong_type_and_weak_are_rejected(self):
        for replacement in (symbol(next(iter(box.ROOTS.values())),1,typ=32),
                            symbol(next(iter(box.ROOTS.values())),0,value=4,typ=32),
                            symbol(next(iter(box.ROOTS.values())),0,typ=0),
                            symbol(next(iter(box.ROOTS.values())),0,typ=32,storage=105)):
            raw,names=fixture(lambda ss,sy:sy.__setitem__(2,replacement))
            with self.assertRaisesRegex(ValueError,'plain typed undefined'):box.bind_caller(raw,names)

    def test_missing_and_hidden_physical_method_records_rejected(self):
        raw,names=fixture(lambda ss,sy:sy.append(symbol(next(iter(box.ROOTS.values())),0,typ=32)))
        with self.assertRaisesRegex(ValueError,'duplicate physical'):box.bind_caller(raw,names)
        raw,names=fixture(lambda ss,sy:sy.__setitem__(2,symbol('_unrelated',0,typ=32)))
        with self.assertRaisesRegex(ValueError,'absent'):box.bind_caller(raw,names)

    def test_nonzero_addend_noncall_and_DIR32_rejected(self):
        def addend(ss,sy):ss[0]['payload']=b'\xe8\x01'+ss[0]['payload'][2:]
        def noncall(ss,sy):ss[0]['payload']=b'\x90'+ss[0]['payload'][1:]
        def dir32(ss,sy):ss[0]['relocs'][0]=(1,3,6)
        for mutate in (addend,noncall,dir32):
            raw,names=fixture(mutate)
            with self.assertRaisesRegex(ValueError,'zero-addend direct REL32'):box.bind_caller(raw,names)

    def test_absent_call_and_unproved_anchor_rejected(self):
        raw,names=fixture(lambda ss,sy:ss[0].update(relocs=[(6,4,20),(11,5,20)]))
        with self.assertRaisesRegex(ValueError,'no actual direct'):box.bind_caller(raw,names)
        raw,names=fixture(lambda ss,sy:sy.__setitem__(1,symbol('_authored_caller',1,typ=32,storage=3)))
        with self.assertRaisesRegex(ValueError,'source function anchor'):box.bind_caller(raw,names)

    def test_existing_canonical_alias_rejected(self):
        raw,names=fixture(lambda ss,sy:sy.append(symbol('_fnv_code_'+'d'*64,0,typ=32)))
        with self.assertRaisesRegex(ValueError,'already contains'):box.bind_caller(raw,names)

    def test_independent_full_caller_symbols_sections_and_aux(self):
        raw,names=fixture();result,contract=box.bind_caller(raw,names)
        with tempfile.TemporaryDirectory() as d:
            source,target=Path(d)/'source.obj',Path(d)/'target.obj';source.write_bytes(raw);target.write_bytes(result)
            self.assertTrue(box.independent_caller(source,target,contract)['all_sections_symbols_auxiliary_and_relocations_equal'])
            broken=copy.deepcopy(contract);broken['calls'][0]['canonical_name']='_wrong'
            with self.assertRaisesRegex(ValueError,'independent caller facts'):box.independent_caller(source,target,broken)
            target.write_bytes(result+b'changed')
            with self.assertRaises(ValueError):box.independent_caller(source,target,contract)

    def test_exact_bounded_result_and_normal_return(self):
        data=json.dumps(box.EXPECTED).encode()+b'\n'
        self.assertEqual(box.parse_result(data,b'',0),box.EXPECTED)
        for stdout,stderr,code in ((data,b'',1),(data,b'failure',0),(data+data,b'',0),(b'x'*4097,b'',0)):
            with self.assertRaises(ValueError):box.parse_result(stdout,stderr,code)
        altered=dict(box.EXPECTED);altered['guards_ok']=1
        with self.assertRaisesRegex(ValueError,'differs'):box.parse_result(json.dumps(altered).encode(),b'',0)

    def test_exact_original_component_review_hash_before_artifact_access(self):
        with patch.object(box,'sha',return_value='changed'),patch.object(box,'read_json',side_effect=AssertionError('read stale review')):
            with self.assertRaisesRegex(ValueError,'stale independent'):box.projection_basis(Path('unread-review'),'expected')

    def test_native_capture_accepts_only_compiler_linker_and_new_log(self):
        with tempfile.TemporaryDirectory() as d,patch.object(box.subprocess,'Popen',side_effect=AssertionError('launched')):
            root=Path(d);log=root/'log'
            with self.assertRaisesRegex(ValueError,'only pinned compiler/linker'):
                box.run_native([root/'probe.exe'],root,root,log)
            log.write_text('preserve')
            with self.assertRaisesRegex(ValueError,'exclusive native log'):
                box.run_native([root/'VC/bin/cl.exe'],root,root,log)

    def test_mocked_native_capture_bounds_without_a_process(self):
        class Child:
            def __init__(self,data):self.stdout=io.BytesIO(data);self.returncode=None;self.killed=False
            def poll(self):return self.returncode
            def kill(self):self.returncode=-9;self.killed=True
            def wait(self,timeout=None):
                if self.returncode is None:self.returncode=0
                return self.returncode
        with tempfile.TemporaryDirectory() as d:
            root=Path(d);child=Child(b'bounded compiler output')
            with patch.object(box.subprocess,'Popen',return_value=child) as launch:
                code,text=box.run_native([root/'VC/bin/cl.exe'],root,root,root/'good.log',cap=64)
            self.assertEqual((code,text),(0,'bounded compiler output'))
            self.assertFalse(launch.call_args.kwargs['shell']);self.assertEqual(launch.call_args.kwargs['stdin'],box.subprocess.DEVNULL)
            child=Child(b'x'*4096)
            with patch.object(box.subprocess,'Popen',return_value=child):
                with self.assertRaisesRegex(ValueError,'output cap'):
                    box.run_native([root/'VC/bin/cl.exe'],root,root,root/'cap.log',cap=16)
            self.assertTrue(child.killed);self.assertEqual((root/'cap.log').stat().st_size,17)

    def test_owned_linked_code_inspection_uses_explicit_mode_but_data_default_stays_closed(self):
        # Entirely authored COFF + an in-memory PE reader, no existing image.
        names={a:'_fnv_code_'+str(i)*64 for i,a in enumerate(box.ROOTS,1)}
        addresses={a:0x401000+i*0x20 for i,a in enumerate(box.ROOTS)}
        symbols=[symbol('.text',1,storage=3,auxiliary=aux(1)),symbol(names['0x00db0920'],1,typ=32),
            symbol('.text',2,storage=3,auxiliary=aux(6,1)),symbol(names['0x00db0960'],2,typ=32),
            symbol('.text',3,storage=3,auxiliary=aux(1)),symbol(names['0x00db09b0'],3,typ=32),symbol(names['0x00db09b0'],0,typ=32)]
        raw=object_bytes([section('.text',b'\xc3'),section('.text',b'\xe8\0\0\0\0\xc3',relocs=[(1,9,20)]),section('.text',b'\xc3')],symbols)
        roots=[dict(original_address=a,section=i+1,value=0,size=(6 if i==1 else 1)) for i,a in enumerate(box.ROOTS)]
        record=dict(certificate=dict(roots=roots),projection=dict(maps=dict(section_map={1:1,2:2,3:3},symbol_map={i:i for i in (0,2,3,5,6,8,9)})))
        table={names[a]:dict(address=addresses[a],owner='union-reference-0000:authored.obj') for a in box.ROOTS}
        table.update(_mainCRTStartup=dict(address=0x401100,owner='libcmt:crt0.obj'),_authored_caller=dict(address=0x401080,owner='caller.obj'))
        contributors={names[a]:dict(library='union-reference-0000.lib',member_sha256=box.MEMBER_SHA) for a in box.ROOTS}
        contributors.update(_mainCRTStartup=dict(library='libcmt.lib'),_authored_caller=dict(kind='fixture-object'))
        caller=dict(calls=[dict(canonical_name=names[a],uses=[dict(anchor='_authored_caller',offset=1+5*i)]) for i,a in enumerate(box.ROOTS)])
        data=bytearray(0x400);struct.pack_into('<I',data,0x3c,0x80);struct.pack_into('<I',data,0xa8,0x1100)
        data[0x200]=0xc3;data[0x220:0x226]=b'\xe8\0\0\0\0\xc3';data[0x240]=0xc3
        struct.pack_into('<i',data,0x221,0x401040-(0x401020+5))
        for i,a in enumerate(box.ROOTS):
            data[0x280+5*i]=0xe8;struct.pack_into('<i',data,0x281+5*i,addresses[a]-(0x401080+5*i+5))
        pe_class=box.Pe
        def reader():
            pe=pe_class.__new__(pe_class);pe.base=0x400000;pe.length=len(data);pe.stream=io.BytesIO(data)
            pe.directories=[(0,0)]*16;pe.sections=[dict(rva=0x1000,extent=0x200,raw_size=0x200,raw_offset=0x200,executable=True)]
            return pe
        pe=reader()
        with self.assertRaisesRegex(ValueError,'executable payload'):pe.read_rva(0x1000,1)
        self.assertEqual(pe.read_rva(0x1000,1,allow_code=True),b'\xc3');pe.close()
        imports=[dict(dll='KERNEL32.dll',export=dict(kind='name',name=name)) for name in ('GetStdHandle','WriteFile','SetErrorMode')]
        with tempfile.TemporaryDirectory() as d:
            member,mp=Path(d)/'authored.obj',Path(d)/'authored.map';member.write_bytes(raw);mp.write_text('authored map')
            with patch.object(box,'Pe',side_effect=lambda _:reader()),patch.object(box.boot,'map_symbols',return_value=table),patch.object(box,'parse_imports',return_value=imports):
                result=box.inspect_link(Path(d)/'never-opened.exe',mp,member,record,names,caller,contributors)
            self.assertEqual(len(result['Game_bodies']),3);self.assertEqual(len(result['intra_union_fields']),1)
            self.assertEqual(len(result['naturally_typed_caller_fields']),3)


if __name__=='__main__':unittest.main()
