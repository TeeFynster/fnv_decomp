"""Prepare an original EH fixture; require a hash-bound independent review to execute."""
from __future__ import annotations
import argparse
import json
import os
from pathlib import Path
import re
import struct
import subprocess
import sys
import coff_eh_extract as extract
import toolchain
from coff_rewrite import strict_object

ROOT=Path(__file__).resolve().parents[2]
SOURCES=[ROOT/'runtime/probes'/n for n in ('eh_fixture.hpp','eh_fixture_library.cpp','eh_fixture_dependencies.cpp','eh_fixture_main.cpp')]
TOOLS=[Path(__file__),ROOT/'tools/rebuild/coff_eh_extract.py',ROOT/'tools/rebuild/coff_rewrite.py',ROOT/'tools/rebuild/coff_inventory.py',ROOT/'tools/rebuild/toolchain.py',ROOT/'tools/compare.py']
COMPILE=['/nologo','/c','/MT','/Od','/Oy-','/GS','/EHsc','/Gy','/W4']
LINK=['/nologo','/machine:x86','/subsystem:console','/opt:ref','/opt:noicf','/safeseh','/dynamicbase:no','/fixed:no','/incremental:no']
EXPECTED=dict(schema=1,rounds=1024,caught=2048,resumed=3072,checks_ok=1)
sha=extract.sha

def parse_receipt(text,code):
    if code or len(text.splitlines())!=1:raise ValueError('fixture failed or receipt count differs')
    result=json.loads(text)
    if result!=EXPECTED or any(type(result[k]) is not type(v) for k,v in EXPECTED.items()):raise ValueError('fixture assertions differ')
    return result

def write(path,value):
    with Path(path).open('x',encoding='utf-8') as f:json.dump(value,f,indent=2);f.write('\n')

def map_rows(text):
    rows={}
    for line in text.splitlines():
        m=re.match(r'^\s+[0-9a-fA-F]{4}:[0-9a-fA-F]{8}\s+(\S+)\s+([0-9a-fA-F]{8})\s+(.+?)\s*$',line)
        if m:rows.setdefault(m[1],[]).append(dict(address=int(m[2],16),provider=m[3]))
    return rows

def inspect_link(exe,mapfile,selected):
    sys.path.insert(0,str(ROOT/'tools'));from compare import Pe
    pe=Pe(exe);rows=map_rows(mapfile.read_text())
    def mapped(name):
        matches=rows.get(name,[])
        if len(matches)!=1:raise ValueError('linked symbol missing or duplicate: '+name)
        return matches[0]
    root=mapped(extract.PARENT)['address']
    handler=struct.unpack('<I',pe.read(root+6,4))[0]
    info=struct.unpack('<I',pe.read(handler+18,4))[0]
    addresses={'.text':root,'.text$x':handler-8,'.xdata$x':info-8}
    c,_,_,_=strict_object(selected);checked=[]
    for sec in c.sections.values():
        if sec['name'] not in addresses:continue
        base=addresses[sec['name']];actual=pe.read(base,sec['size']);original=extract.payload(c,sec['index']);masked=set()
        for off,idx,typ in sec['relocs']:
            target=c.symbols[idx];addend=struct.unpack_from('<i' if typ==20 else '<I',original,off)[0]
            expected=(addresses[c.sections[target['section']]['name']]+target['value']) if target['section']>0 else mapped(target['name'])['address']
            observed=struct.unpack_from('<I',actual,off)[0]
            if typ==20:observed=(base+off+4+struct.unpack_from('<i',actual,off)[0])&0xffffffff
            if observed!=(expected+addend)&0xffffffff:raise ValueError('linked relocation target differs')
            masked.update(range(off,off+4))
        if any(a!=b for i,(a,b) in enumerate(zip(actual,original)) if i not in masked):raise ValueError('linked retained payload differs')
        checked.append(dict(name=sec['name'],address=base,size=sec['size'],normalized_equal=True))
    # Read real PE32 load-config SafeSEH table, independent of dumpbin prose.
    data=exe.read_bytes();ph=struct.unpack_from('<I',data,0x3c)[0];opt=ph+24
    rva,size=struct.unpack_from('<II',data,opt+96+10*8)
    if size<64:raise ValueError('SafeSEH load configuration missing')
    config=pe.read(pe.base+rva,72)
    if struct.unpack_from('<I',config)[0]!=72:raise ValueError('unrecognized VC9 load-config extent')
    table,count=struct.unpack_from('<II',config,64)
    if not table or not count or count>10000:raise ValueError('invalid SafeSEH table')
    handlers=struct.unpack('<'+'I'*count,pe.read(table,count*4))
    if handler-pe.base not in handlers:raise ValueError('extracted handler missing from SafeSEH')
    if any('FixtureUnrelated' in n or 'FixtureUnresolvedSentinel' in n for n in rows):raise ValueError('omitted sentinel survived link')
    providers={}
    for n,owner in extract.EXTERNALS.items():
        row=mapped(n);provider=row['provider'].lower()
        if owner=='fixture_dependencies' and 'dependencies.obj' not in provider:raise ValueError('wrong fixture provider')
        if owner=='LIBCMT' and 'libcmt:' not in provider:raise ValueError('wrong CRT provider')
        providers[n]=row
    return dict(image_base=pe.base,sections=checked,safe_seh=dict(handler=handler,table=table,count=count,registered=True),providers=providers,omitted_sentinel_absent=True)

def prepare(doctor,out):
    doctor,out=Path(doctor).resolve(),Path(out).resolve()
    if os.name!='nt' or out.exists() or os.environ.get('LINK') or os.environ.get('_LINK_'):raise ValueError('new output and clean native environment required')
    d=json.loads(doctor.read_text());tc=d['toolchains']['sp1'];root,sdk=toolchain.layout(tc['root']);cl=root/'VC/bin/cl.exe';link=root/'VC/bin/link.exe';dump=root/'VC/bin/dumpbin.exe'
    if not tc['ready'] or sha(cl)!=tc['cl_sha256'] or sha(link)!=tc['link_sha256'] or tc['version']!=toolchain.VERSIONS['sp1']:raise ValueError('doctor compiler identity differs')
    trusted=[cl,link,dump,root/'VC/lib/libcmt.lib',root/'VC/lib/oldnames.lib',sdk/'Lib/kernel32.lib']
    inputs={str(p.resolve()):sha(p) for p in SOURCES+TOOLS+trusted+[doctor]}
    out.mkdir(parents=True)
    commands=[]
    def run(cmd,log):
        commands.append([str(x) for x in cmd]);code,text=toolchain.run(cmd,root,out,timeout=120);(out/log).write_text(text,encoding='utf-8')
        if code:raise ValueError('native build/inspection failed: '+log)
        return text
    _,banner=toolchain.run([cl],root,out,timeout=30)
    if not re.search(r'Version\s+15\.00\.30729\.01\b',banner):raise ValueError('wrong compiler banner')
    producer=out/'producer.obj';selected=out/'selected.obj';deps=out/'dependencies.obj';main=out/'main.obj'
    run([cl]+COMPILE+[SOURCES[1],'/Fo'+str(producer)],'producer-compile.log')
    proof=out/'provenance.json'
    write(proof,dict(schema_version=1,kind='original-eh-fixture-provenance',policy=extract.POLICY,providers=extract.EXTERNALS,object_sha256=sha(producer),sources={str(p.resolve()):sha(p) for p in SOURCES[:2]},compiler_inputs={str(p.resolve()):sha(p) for p in trusted},compile_command=commands[-1],provenance_scope='caller-declared execution; hashes do not prove compiler causality'))
    er=out/'extract-receipt.json';extract.extract(producer,selected,er,proof,sha(proof))
    run([cl]+COMPILE+[SOURCES[2],'/Fo'+str(deps)],'dependencies-compile.log')
    run([cl]+COMPILE+[SOURCES[3],'/Fo'+str(main)],'main-compile.log')
    # The only intentionally unresolved undefined belongs to the omitted COMDAT.
    variants=[]
    order=out/'moved-order.txt';order.write_text(extract.PARENT+'\n_main\n',encoding='ascii')
    for label,base in [('normal',0x400000),('moved',0x600000)]:
        exe=out/(label+'.exe');mp=out/(label+'.map')
        run([link]+LINK+(['/order:@'+str(order),'/filealign:1024'] if label=='moved' else [])+['/base:'+hex(base),'/out:'+str(exe),'/map:'+str(mp),main,deps,selected],'link-'+label+'.log')
        imports=run([dump,'/imports',exe],'imports-'+label+'.log')
        dlls=re.findall(r'(?im)^\s*([a-zA-Z0-9_.-]+\.dll)\s*$',imports)
        if {x.lower() for x in dlls}!={'kernel32.dll'}:raise ValueError('unexpected direct imports')
        run([dump,'/headers','/loadconfig',exe],'headers-'+label+'.log')
        inspection=inspect_link(exe,mp,selected)
        variants.append(dict(name=label,exe=str(exe),exe_sha256=sha(exe),map=str(mp),map_sha256=sha(mp),inspection=inspection,direct_imports=dlls))
    # No custom DLLs: CRT is statically linked. Bind direct 32-bit OS import files;
    # transitively loaded Windows components remain OS-managed, not reproduced.
    sysdir=Path(os.environ['SystemRoot'])/'SysWOW64'
    osdeps={str(sysdir/n):sha(sysdir/n) for n in ('kernel32.dll','KernelBase.dll','ntdll.dll')}
    artifacts={str(p):sha(p) for p in (producer,selected,deps,main,proof,er,order)}
    for label in ('normal','moved'):
        for prefix in ('link-','imports-','headers-'):p=out/(prefix+label+'.log');artifacts[str(p)]=sha(p)
    if any(sha(p)!=h for p,h in inputs.items()):raise ValueError('inputs changed during prepare')
    report=dict(schema_version=1,kind='original-eh-fixture-prepared',status='prepared_pending_independent_review',policy=extract.POLICY,inputs=inputs,artifacts=artifacts,os_dependencies=osdeps,os_dependency_scope='direct import and core 32-bit Windows files; transitive OS loader graph is not locked or execution-traced',variants=variants,commands=commands,execution_performed=False,provenance_scope='observed commands with hash-bound files, not cryptographic compiler execution proof')
    write(out/'prepare.json',report);return report

def validate_review(prepared,review,prepare_sha256):
    if prepared.get('schema_version')!=1 or prepared.get('kind')!='original-eh-fixture-prepared' or prepared.get('status')!='prepared_pending_independent_review' or prepared.get('policy')!=extract.POLICY or prepared.get('execution_performed') is not False:raise ValueError('unrecognized prepared receipt')
    if review.get('schema_version')!=1 or review.get('kind')!='original-eh-fixture-review' or review.get('approved') is not True or review.get('prepare_sha256')!=prepare_sha256 or not review.get('reviewer'):raise ValueError('independent approval missing or stale')
    expected=[{k:v[k] for k in ('name','exe_sha256','map_sha256')} for v in prepared['variants']]
    if len(expected)!=2 or [v['name'] for v in expected]!=['normal','moved'] or review.get('variants')!=expected:raise ValueError('approval variants differ')
    checks=('closure','linked_eh_metadata','safe_seh','crt_providers','map_and_imports')
    if any(review.get('checks',{}).get(k) is not True for k in checks):raise ValueError('independent inspected checks incomplete')

def execute(prepare_path,review_path,review_sha256,receipt_path):
    pp,rp,out=[Path(x).resolve() for x in (prepare_path,review_path,receipt_path)]
    if len({pp,rp,out})!=3 or out.exists() or sha(rp)!=review_sha256:raise ValueError('new execution receipt and exact review required')
    ph=sha(pp);p=json.loads(pp.read_text());r=json.loads(rp.read_text());validate_review(p,r,ph)
    protected={**p['inputs'],**p['artifacts'],**p['os_dependencies']}
    for v in p['variants']:protected[v['exe']]=v['exe_sha256'];protected[v['map']]=v['map_sha256']
    if str(out) in protected:raise ValueError('execution receipt collides with input')
    report=dict(schema_version=1,kind='original-eh-fixture-execution',status='error',prepare_sha256=ph,review_sha256=review_sha256,variants=[])
    try:
        for v in p['variants']:
            if sha(pp)!=ph or sha(rp)!=review_sha256 or any(sha(x)!=h for x,h in protected.items()):raise ValueError('reviewed artifact changed')
            try:
                proc=subprocess.run([v['exe']],cwd=pp.parent,stdin=subprocess.DEVNULL,stdout=subprocess.PIPE,stderr=subprocess.PIPE,text=True,errors='replace',timeout=20,creationflags=getattr(subprocess,'CREATE_NO_WINDOW',0))
            except subprocess.TimeoutExpired:
                report['variants'].append(dict(name=v['name'],status='timeout'));raise ValueError('fixture timed out; child terminated')
            result=dict(name=v['name'],returncode=proc.returncode,stdout=proc.stdout,stderr=proc.stderr);report['variants'].append(result)
            if proc.stderr:raise ValueError('fixture emitted stderr')
            result['observed']=parse_receipt(proc.stdout,proc.returncode);result['status']='pass'
        report['status']='pass'
    except (ValueError,OSError) as exc:
        report['error']=str(exc)
    write(out,report);return report

if __name__=='__main__':
    ap=argparse.ArgumentParser(description=__doc__);sub=ap.add_subparsers(dest='action',required=True)
    a=sub.add_parser('prepare');a.add_argument('--doctor',type=Path,required=True);a.add_argument('--out',type=Path,required=True)
    a=sub.add_parser('execute')
    for n in ('prepare','review','review-sha256','receipt'):a.add_argument('--'+n,required=True)
    a=ap.parse_args()
    report=prepare(a.doctor,a.out) if a.action=='prepare' else execute(a.prepare,a.review,a.review_sha256,a.receipt)
    print(report['status']);sys.exit(0 if report['status'] in ('pass','prepared_pending_independent_review') else 1)
