"""Extract ONLY the original constructor fixture's reviewed VC9 EH closure."""
from __future__ import annotations
import argparse
import hashlib
import json
from pathlib import Path
import struct
import tempfile
from coff_rewrite import strict_object

ROOT = Path(__file__).resolve().parents[2]
POLICY = 'original-nonpolymorphic-vc9-constructor-v1'
PARENT = '??0FixtureDerived@@QAE@H@Z'
BASE_CTOR = '??0FixtureBase@@QAE@H@Z'
BASE_DTOR = '??1FixtureBase@@QAE@XZ'
OPERATION = '?FixtureOperation@@YAXPAUFixtureBase@@H@Z'
EXTERNALS = {BASE_CTOR: 'fixture_dependencies', BASE_DTOR: 'fixture_dependencies',
 OPERATION: 'fixture_dependencies', '___security_cookie': 'LIBCMT',
 '@__security_check_cookie@4': 'LIBCMT', '___CxxFrameHandler3': 'LIBCMT'}
DEFAULTS = ['/DEFAULTLIB:"LIBCMT"', '/DEFAULTLIB:"OLDNAMES"']

def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()

def payload(c, index):
    row = struct.unpack_from('<8sIIIIIIHHI', c.data, 20+(index-1)*40)
    return c.data[row[4]:row[4]+row[3]]

def select(c):
    def fail(message): raise ValueError(message)
    if c.directives != DEFAULTS: fail('unknown linker directives')
    syms = list(c.symbols.values())
    if any(s.get('weak') or (s['section']==0 and s['value']) for s in syms): fail('weak/common symbols unsupported')
    def unique(name):
        rows = [s for s in syms if s['name']==name]
        if len(rows)!=1: fail('missing or duplicate required symbol: '+name)
        return rows[0]
    root=unique(PARENT); rs=root['section']
    if rs<=0 or root['value'] or root['storage']!=2 or root['type']!=32: fail('invalid fixture parent')
    if c.sections[rs]['name']!='.text' or c.sections[rs]['selection']!='no_duplicates': fail('shared code unsupported')
    handlers=[s for s in syms if s['name']=='__ehhandler$'+PARENT]
    cleanup=unique('__unwindfunclet$'+PARENT+'$0'); handler=unique('__ehhandler$'+PARENT)
    info=unique('__ehfuncinfo$'+PARENT); unwind=unique('__unwindtable$'+PARENT)
    xs,ds=handler['section'],info['section']
    if (cleanup['section'],cleanup['value'],handler['value'],unwind['section'],unwind['value'],info['value'])!=(xs,0,8,ds,0,8): fail('foreign-parent or invalid local metadata')
    if any(s['storage']!=3 or s['aux_count'] for s in (cleanup,handler,info,unwind)): fail('local metadata visibility changed')
    children=[s['index'] for s in c.sections.values() if s['association']==rs and s['selection']=='associative']
    if set(children)!={xs,ds} or xs==ds: fail('missing or extra associative runtime child')
    if (c.sections[xs]['name'],c.sections[xs]['size'],c.sections[ds]['name'],c.sections[ds]['size'])!=('.text$x',35,'.xdata$x',44): fail('unsupported EH layout')
    for s in c.sections.values():
        if s['selection']=='associative' and s['index'] not in children: fail('foreign association or cycle')
    sx=[s for s in c.sections.values() if s['name']=='.sxdata']
    dr=[s for s in c.sections.values() if s['name']=='.drectve']
    if len(sx)!=1 or len(dr)!=1: fail('one handler record and directive section required')
    sx,dr=sx[0],dr[0]
    if sx['size']!=4 or sx['relocs'] or sx['comdat'] or struct.unpack('<I',payload(c,sx['index']))[0]!=handler['index']: fail('wrong handler index')
    if dr['relocs'] or dr['comdat']: fail('invalid directives')
    keep=sorted({rs,xs,ds,sx['index'],dr['index']})
    allowed_local={rs:{PARENT},xs:{cleanup['name'],handler['name']},ds:{info['name'],unwind['name']},sx['index']:set(),dr['index']:set()}
    expected_flags={rs:0x60501020,xs:0x60501020,ds:0x40301040,sx['index']:0x00300200,dr['index']:0x00100a00}
    for sn in keep:
        sec=c.sections[sn]
        if sec['flags']!=expected_flags[sn]:fail('unsupported runtime section characteristics')
        members=[s for s in syms if s['section']==sn]
        section_symbols=[s for s in members if 'section_aux' in s]
        if len(section_symbols)!=1: fail('required ordinary section symbol missing')
        st=section_symbols[0];aux=st['section_aux']
        if st['name']!=sec['name'] or st['value'] or st['storage']!=3 or st['type'] or st['aux_count']!=1: fail('unsupported section auxiliary layout')
        if aux['relocation_count']!=len(sec['relocs']): fail('auxiliary relocation count mismatch')
        if {s['name'] for s in members if s is not st}!=allowed_local[sn]: fail('shared section or extra local symbol')
        if any(s['aux_count'] for s in members if s is not st): fail('unexpected auxiliary record')
    def edges(sn): return [(off,c.symbols[idx]['name'],typ) for off,idx,typ in c.sections[sn]['relocs']]
    if edges(rs)!=[(6,handler['name'],6),(19,'___security_cookie',6),(46,BASE_CTOR,20),(66,OPERATION,20)]: fail('unsupported parent shape')
    if c.sections[rs]['size']!=100: fail('parent span differs from reviewed fixture')
    if edges(xs)!=[(4,BASE_DTOR,20),(21,'@__security_check_cookie@4',20),(26,info['name'],6),(31,'___CxxFrameHandler3',20)]: fail('unsupported cleanup/handler shape')
    if edges(ds)!=[(4,cleanup['name'],6),(16,unwind['name'],6)]: fail('unsupported metadata relocation')
    words=struct.unpack('<11I',payload(c,ds))
    if words!=(0xffffffff,0,0x19930522,1,0,0,0,0,0,0,1): fail('unsupported FuncInfo/unwind map')
    retained=set()
    for s in syms:
        if s['section'] in keep or (s['section']==-1 and s['name'] in ('@comp.id','@feat.00')): retained.add(s['index'])
    if unique('@feat.00')['value']!=1: fail('SafeSEH feature declaration missing')
    external=set()
    for sn in keep:
        for off,idx,typ in c.sections[sn]['relocs']:
            if typ not in (6,20): fail('unsupported runtime relocation')
            s=c.symbols[idx]
            if s['section']==0:
                if s['name'] not in EXTERNALS or s['storage']!=2 or s['aux_count'] or s['value']: fail('unapproved external provider')
                external.add(s['name']);retained.add(idx)
            elif s['section'] not in keep: fail('relocation outside retained closure')
    if external!=set(EXTERNALS): fail('explicit provider set incomplete')
    dropped=[]
    for sn,sec in c.sections.items():
        if sn in keep: continue
        if sec['name']=='.debug$S' and not sec['relocs'] and not sec['comdat'] and not sec['flags']&0x20000000:
            reason='debug metadata'
        elif sec['name']=='.text' and sec['selection']=='no_duplicates' and sec['size']==10:
            names={s['name'] for s in syms if s['section']==sn and not s.get('section_aux')}
            if names!={'?FixtureUnrelated@@YAXXZ'} or edges(sn)!=[(4,'?FixtureUnresolvedSentinel@@YAXXZ',20)]: fail('unknown omitted code')
            reason='independent unrelated fixture function with unresolved sentinel'
        else: fail('unknown TLS/initializer/data/runtime section')
        dropped.append(dict(section=sn,name=sec['name'],reason=reason))
    if len(dropped)!=2: fail('unexpected producer scope')
    omitted_sections={x['section'] for x in dropped}
    for symbol in syms:
        if symbol['index'] in retained or symbol['section'] in omitted_sections:continue
        if symbol['name']=='?FixtureUnresolvedSentinel@@YAXXZ' and symbol['section']==0 and not symbol['value'] and symbol['storage']==2 and not symbol['aux_count']:continue
        fail('unknown unretained symbol')
    return keep,sorted(retained),handler,dropped

def transform(path, expected_sha256):
    c,symptr,_,_=strict_object(path)
    if hashlib.sha256(c.data).hexdigest()!=expected_sha256: raise ValueError('stale object proof')
    keep,indices,handler,dropped=select(c)
    sm={old:new+1 for new,old in enumerate(keep)}; im={};count=0
    for i in indices:im[i]=count;count+=1+c.symbols[i]['aux_count']
    strings=bytearray(b'\0'*4)
    def namefield(name):
        b=name.encode('ascii')
        if len(b)<=8:return b.ljust(8,b'\0')
        off=len(strings);strings.extend(b+b'\0');return struct.pack('<II',0,off)
    records=bytearray()
    for i in indices:
        s=c.symbols[i];section=sm.get(s['section'],s['section'])
        records.extend(struct.pack('<8sIhHBB',namefield(s['name']),s['value'],section,s['type'],s['storage'],s['aux_count']))
        if s['aux_count']:
            aux=bytearray(c.data[symptr+(i+1)*18:symptr+(i+2)*18])
            if struct.unpack_from('<H',aux,6)[0] or aux[15:]!=b'\0'*3: raise ValueError('unsupported auxiliary line/reserved fields')
            assoc=s['section_aux']['association'];struct.pack_into('<H',aux,12,sm[assoc] if assoc else 0)
            if s['section']==next(sn for sn in keep if c.sections[sn]['name']=='.sxdata'):
                # COFF section checksum is advisory but stale checksum must not survive rewritten payload.
                struct.pack_into('<I',aux,8,0)
            records.extend(aux)
    body=bytearray();headers=bytearray();cursor=20+40*len(keep);selection=[]
    for sn in keep:
        sec=c.sections[sn];data=payload(c,sn)
        if sec['name']=='.sxdata':data=struct.pack('<I',im[handler['index']])
        raw=cursor;body.extend(data);cursor+=len(data)
        relptr=cursor if sec['relocs'] else 0
        for off,idx,typ in sec['relocs']:body.extend(struct.pack('<IIH',off,im[idx],typ));cursor+=10
        headers.extend(struct.pack('<8sIIIIIIHHI',sec['name'].encode().ljust(8,b'\0'),0,0,len(data),raw,relptr,0,len(sec['relocs']),0,sec['flags']))
        selection.append(dict(input_section=sn,output_section=sm[sn],name=sec['name'],size=sec['size'],payload_sha256=hashlib.sha256(data).hexdigest(),relocations=[dict(offset=o,symbol=c.symbols[i]['name'],kind=t) for o,i,t in sec['relocs']]))
    struct.pack_into('<I',strings,0,len(strings))
    result=struct.pack('<HHIIIHH',0x14c,len(keep),0,cursor,count,0,0)+headers+body+records+strings
    return result,dict(policy=POLICY,section_map=sm,symbol_map=im,sections=selection,dropped=dropped,providers=EXTERNALS,sxdata=dict(input_handler_index=handler['index'],output_handler_index=im[handler['index']],handler=handler['name']))

def extract(input_path,output_path,receipt_path,proof_path,proof_sha256):
    inp,out,receipt,proof=[Path(x).resolve() for x in (input_path,output_path,receipt_path,proof_path)]
    if len({inp,out,receipt,proof})!=4 or out.exists() or receipt.exists(): raise ValueError('new distinct output paths required')
    if sha(proof)!=proof_sha256: raise ValueError('stale proof hash')
    p=json.loads(proof.read_text())
    if p.get('schema_version')!=1 or p.get('kind')!='original-eh-fixture-provenance' or p.get('policy')!=POLICY or p.get('providers')!=EXTERNALS: raise ValueError('unrecognized fixture proof')
    expected_sources={str((ROOT/'runtime/probes'/n).resolve()) for n in ('eh_fixture.hpp','eh_fixture_library.cpp')}
    if set(p.get('sources',{}))!=expected_sources: raise ValueError('only original fixture sources allowed')
    observations={Path(x):h for x,h in p['sources'].items()}
    observations.update({Path(x):h for x,h in p.get('compiler_inputs',{}).items()})
    if not p.get('compiler_inputs') or any(sha(x)!=h for x,h in observations.items()): raise ValueError('source/compiler fingerprint changed')
    if out in observations or receipt in observations: raise ValueError('output collides with proof input')
    data,selection=transform(inp,p['object_sha256'])
    out.parent.mkdir(parents=True,exist_ok=True);stage=None;created=[]
    try:
        with tempfile.NamedTemporaryFile(dir=out.parent,suffix='.obj',delete=False) as f:stage=Path(f.name);f.write(data)
        after,_,_,_=strict_object(stage)
        if after.directives!=DEFAULTS:raise ValueError('reparse directive mismatch')
        before,_,_,_=strict_object(inp)
        for old,new in selection['section_map'].items():
            a,b=before.sections[old],after.sections[new]
            if (a['flags'],a['selection'],selection['section_map'].get(a['association'],0))!=(b['flags'],b['selection'],b['association']): raise ValueError('reparse section policy mismatch')
            if a['name']!='.sxdata' and payload(before,old)!=payload(after,new): raise ValueError('reparse payload mismatch')
            want=[(o,selection['symbol_map'][i],t) for o,i,t in a['relocs']]
            if want!=b['relocs']: raise ValueError('reparse relocation mismatch')
        for old,new in selection['symbol_map'].items():
            a,b=before.symbols[old],after.symbols[new]
            for key in ('name','value','type','storage','aux_count'):
                if a[key]!=b[key]:raise ValueError('reparse symbol mismatch')
            if selection['section_map'].get(a['section'],a['section'])!=b['section']:raise ValueError('reparse symbol section mismatch')
        sx=next(s for s in after.sections.values() if s['name']=='.sxdata')
        if struct.unpack('<I',payload(after,sx['index']))[0]!=selection['sxdata']['output_handler_index']:raise ValueError('reparse handler index mismatch')
        if sha(inp)!=p['object_sha256'] or sha(proof)!=proof_sha256 or any(sha(x)!=h for x,h in observations.items()):raise ValueError('evidence changed during extraction')
        report=dict(schema_version=1,kind='original-eh-fixture-extraction',status='pass',policy=POLICY,input_sha256=p['object_sha256'],output_sha256=hashlib.sha256(data).hexdigest(),proof_sha256=proof_sha256,tool_sha256=sha(__file__),selection=selection,independent_reparse=True,provenance_scope='caller-declared compiler execution; independently hashed inputs are not cryptographic execution proof')
        receipt.parent.mkdir(parents=True,exist_ok=True)
        for path,content in ((out,data),(receipt,(json.dumps(report,indent=2)+'\n').encode())):
            with path.open('xb') as f:created.append(path);f.write(content)
        return report
    except BaseException:
        for path in reversed(created):path.unlink(missing_ok=True)
        raise
    finally:
        if stage:stage.unlink(missing_ok=True)

if __name__=='__main__':
    ap=argparse.ArgumentParser(description=__doc__)
    for key in ('input','output','receipt','proof','proof-sha256'):ap.add_argument('--'+key,required=True)
    a=ap.parse_args();extract(a.input,a.output,a.receipt,a.proof,a.proof_sha256)
