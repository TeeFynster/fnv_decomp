import hashlib
import json
from pathlib import Path
import struct
import sys
import tempfile
import unittest

ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'tools/rebuild'))
import coff_eh_extract as eh
from coff_rewrite import strict_object

# Synthetic COFF containers, not machine-code fixtures and never executable.
def fixture():
    specs=[('.text',bytes(100),0x60501020,1,0),('.text$x',bytes(35),0x60501020,5,1),('.xdata$x',struct.pack('<11I',0xffffffff,0,0x19930522,1,0,0,0,0,0,0,1),0x40301040,5,1),('.sxdata',bytes(4),0x00300200,0,0),('.drectve',b' /DEFAULTLIB:"LIBCMT" /DEFAULTLIB:"OLDNAMES"',0x00100a00,0,0),('.debug$S',b'debug',0x42100040,0,0),('.text',bytes(10),0x60501020,1,0)]
    syms=[]
    def symbol(name,section,value=0,typ=0,storage=3,aux=None):
        index=sum(1+(1 if s[5] is not None else 0) for s in syms);syms.append([name,value,section,typ,storage,aux]);return index
    symbol('@comp.id',-1,8681481);symbol('@feat.00',-1,1)
    section_indices={}
    for n,(name,data,flags,sel,assoc) in enumerate(specs,1):section_indices[n]=symbol(name,n,aux=(len(data),0,0,assoc,sel))
    root=symbol(eh.PARENT,1,typ=32,storage=2)
    cleanup=symbol('__unwindfunclet$'+eh.PARENT+'$0',2,typ=32)
    handler=symbol('__ehhandler$'+eh.PARENT,2,8,32)
    info=symbol('__ehfuncinfo$'+eh.PARENT,3,8)
    unwind=symbol('__unwindtable$'+eh.PARENT,3)
    ext={name:symbol(name,0,typ=0 if name=='___security_cookie' else 32,storage=2) for name in eh.EXTERNALS}
    symbol('?FixtureUnrelated@@YAXXZ',7,typ=32,storage=2)
    sentinel=symbol('?FixtureUnresolvedSentinel@@YAXXZ',0,typ=32,storage=2)
    rels={1:[(6,handler,6),(19,ext['___security_cookie'],6),(46,ext[eh.BASE_CTOR],20),(66,ext[eh.OPERATION],20)],2:[(4,ext[eh.BASE_DTOR],20),(21,ext['@__security_check_cookie@4'],20),(26,info,6),(31,ext['___CxxFrameHandler3'],20)],3:[(4,cleanup,6),(16,unwind,6)],7:[(4,sentinel,20)]}
    specs[3]=(specs[3][0],struct.pack('<I',handler),*specs[3][2:])
    for n in range(1,8):
        entry=next(s for s in syms if s[2]==n and s[5] is not None);a=list(entry[5]);a[1]=len(rels.get(n,[]));entry[5]=tuple(a)
    return specs,syms,rels

def encode(specs,syms,rels):
    strings=bytearray(b'\0'*4);records=bytearray()
    for name,value,section,typ,storage,aux in syms:
        name=name.encode()
        if len(name)>8:off=len(strings);strings.extend(name+b'\0');name=struct.pack('<II',0,off)
        records.extend(struct.pack('<8sIhHBB',name.ljust(8,b'\0'),value,section,typ,storage,int(aux is not None)))
        if aux is not None:
            length,rc,checksum,association,selection=aux
            records.extend(struct.pack('<IHHIHBBH',length,rc,0,checksum,association,selection,0,0))
    struct.pack_into('<I',strings,0,len(strings));cursor=20+40*len(specs);headers=bytearray();body=bytearray()
    for n,(name,data,flags,_,_) in enumerate(specs,1):
        raw=cursor;body.extend(data);cursor+=len(data);r=rels.get(n,[]);rp=cursor if r else 0
        for row in r:body.extend(struct.pack('<IIH',*row));cursor+=10
        headers.extend(struct.pack('<8sIIIIIIHHI',name.encode().ljust(8,b'\0'),0,0,len(data),raw,rp,0,len(r),0,flags))
    return struct.pack('<HHIIIHH',0x14c,len(specs),0,cursor,len(records)//18,0,0)+headers+body+records+strings

class ExtractTests(unittest.TestCase):
    def setUp(self):
        self.temp=tempfile.TemporaryDirectory();self.addCleanup(self.temp.cleanup);self.folder=Path(self.temp.name)
    def transform(self,parts=None):
        data=encode(*(parts or fixture()));p=self.folder/'in.obj';p.write_bytes(data);return eh.transform(p,hashlib.sha256(data).hexdigest())
    def test_roundtrip_and_sxdata_remap(self):
        data,ledger=self.transform();p=self.folder/'out.obj';p.write_bytes(data);c,_,_,_=strict_object(p)
        self.assertEqual(len(c.sections),5);self.assertEqual(len(ledger['dropped']),2)
        sx=next(s for s in c.sections.values() if s['name']=='.sxdata')
        index=struct.unpack('<I',eh.payload(c,sx['index']))[0]
        self.assertEqual(c.symbols[index]['name'],'__ehhandler$'+eh.PARENT)
        self.assertNotIn('?FixtureUnresolvedSentinel@@YAXXZ',{s['name'] for s in c.symbols.values()})
        self.assertNotEqual(ledger['sxdata']['input_handler_index'],index)
    def test_missing_child_and_cycle(self):
        for assoc in (0,2):
            parts=fixture();symbol=next(s for s in parts[1] if s[0]=='.xdata$x');a=list(symbol[5]);a[3]=assoc;symbol[5]=tuple(a)
            with self.assertRaises(ValueError):self.transform(parts)
    def test_wrong_handler_index(self):
        parts=fixture();row=list(parts[0][3]);row[1]=struct.pack('<I',0);parts[0][3]=tuple(row)
        with self.assertRaises(ValueError):self.transform(parts)
    def test_foreign_parent_funclet(self):
        parts=fixture();next(s for s in parts[1] if s[0].startswith('__unwindfunclet$'))[0]='__unwindfunclet$Foreign$0'
        with self.assertRaises(ValueError):self.transform(parts)
    def test_unsupported_relocation_and_external(self):
        for case in ('kind','provider'):
            parts=fixture()
            if case=='kind':parts[2][1][0]=(6,parts[2][1][0][1],7)
            else:next(s for s in parts[1] if s[0]==eh.OPERATION)[0]='Unapproved'
            with self.assertRaises(ValueError):self.transform(parts)
    def test_bad_metadata_and_shared_section(self):
        for case in ('metadata','shared'):
            parts=fixture()
            if case=='metadata':row=list(parts[0][2]);row[1]=bytes(44);parts[0][2]=tuple(row)
            else:parts[1].append(['Extra',0,1,32,2,None])
            with self.assertRaises(ValueError):self.transform(parts)
    def test_unknown_directive_tls_common_and_aux(self):
        for case in ('directive','tls','common','aux'):
            parts=fixture()
            if case=='directive':
                row=list(parts[0][4]);row[1]=b' /DEFAULTLIB:"EVIL"';parts[0][4]=tuple(row)
                sec=next(s for s in parts[1] if s[0]=='.drectve');a=list(sec[5]);a[0]=len(row[1]);sec[5]=tuple(a)
            elif case=='tls':
                row=list(parts[0][5]);row[0]='.tls';parts[0][5]=tuple(row);next(s for s in parts[1] if s[0]=='.debug$S')[0]='.tls'
            elif case=='common':next(s for s in parts[1] if s[0]==eh.OPERATION)[1]=4
            else:
                sym=next(s for s in parts[1] if s[0]=='.xdata$x');a=list(sym[5]);a[1]=0;sym[5]=tuple(a)
            with self.assertRaises(ValueError):self.transform(parts)
    def test_stale_object_proof(self):
        p=self.folder/'in.obj';p.write_bytes(encode(*fixture()))
        with self.assertRaises(ValueError):eh.transform(p,'0'*64)
    def test_exclusive_publication_and_proof(self):
        p=self.folder/'in.obj';p.write_bytes(encode(*fixture()));proof=self.folder/'proof.json'
        proof.write_text(json.dumps(dict(schema_version=1,kind='original-eh-fixture-provenance',policy=eh.POLICY,providers=eh.EXTERNALS,object_sha256=eh.sha(p),sources={str(x.resolve()):eh.sha(x) for x in [ROOT/'runtime/probes/eh_fixture.hpp',ROOT/'runtime/probes/eh_fixture_library.cpp']},compiler_inputs={str(Path(__file__).resolve()):eh.sha(__file__)})))
        out=self.folder/'out.obj';receipt=self.folder/'receipt.json'
        with self.assertRaises(ValueError):eh.extract(p,out,receipt,proof,'0'*64)
        result=eh.extract(p,out,receipt,proof,eh.sha(proof));self.assertTrue(result['independent_reparse'])
        with self.assertRaises(ValueError):eh.extract(p,out,receipt,proof,eh.sha(proof))
        with self.assertRaises(ValueError):eh.extract(p,p,receipt,proof,eh.sha(proof))

if __name__=='__main__':unittest.main()
