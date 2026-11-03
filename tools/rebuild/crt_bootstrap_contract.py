"""Prepare-only original GUI CRT bootstrap contract. No fixture execution API."""
from __future__ import annotations
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import struct
import time
import tempfile

import toolchain
from coff_inventory import Coff
from data_plan import Pe
from import_plan import parse_imports
from crt_provider import archive_member

ROOT=Path(__file__).resolve().parents[2]
PROBES=ROOT/'runtime/probes'
SOURCE_NAMES=('crt_bootstrap_contract.hpp','crt_bootstrap_host.cpp','crt_bootstrap_sp1.cpp',
              'crt_bootstrap_rtm.cpp','crt_bootstrap_vc8.cpp')
MAGIC=0x464e5643
EVENT=struct.Struct('<6I')
SOURCE_CHECKS=('original_fixture_only','normal_GUI_return','unprotected_early_observer',
               'bounded_pre_main_Win32_sink','consumer_GS_and_C_boundaries','single_experimental_CRT',
               'same_three_source_control','bound_linker_search_and_contributors',
               'explicit_named_API_policy','duplicate_map_provenance_rejected')
HOST_FLAGS=['/nologo','/c','/MT','/Od','/GS-','/EHsc','/Gy','/GF','/W4','/showIncludes']
CONSUMER_FLAGS=['/nologo','/c','/MT','/Od','/GS','/EHsc','/Gy','/GF','/W4','/showIncludes']
EARLY_EXTERNALS={'___security_cookie','___security_cookie_complement',
    '__imp__GetStdHandle@4','__imp__GetFileType@4','__imp__WriteFile@20',
    '__imp__SetErrorMode@4','__imp__GetModuleHandleA@4','__imp__GetProcAddress@8','__imp__GetCurrentProcess@0'}
CRT_REQUIRED=('_WinMainCRTStartup','___security_init_cookie','___security_cookie',
    '___security_cookie_complement','@__security_check_cookie@4','_atexit',
    '___onexitbegin','___onexitend','__encode_pointer','__decode_pointer',
    '__lockexit','__unlockexit','__initterm_e','__initterm')
# Actual named API baseline from the already hash-bound normal SP1 purecall
# fixture, plus the exact source APIs here. No DLL-wide permission.
ALLOWED_APIS=frozenset('''CloseHandle CreateFileA DeleteCriticalSection EnterCriticalSection
ExitProcess FlushFileBuffers FreeEnvironmentStringsA FreeEnvironmentStringsW GetACP GetCPInfo
GetCommandLineA GetConsoleCP GetConsoleMode GetConsoleOutputCP GetCurrentProcess GetCurrentProcessId
GetCurrentThreadId GetEnvironmentStrings GetEnvironmentStringsW GetFileType GetLastError GetLocaleInfoA
GetModuleFileNameA GetModuleHandleA GetModuleHandleW GetOEMCP GetProcAddress GetStartupInfoA GetStdHandle
GetStringTypeA GetStringTypeW GetSystemTimeAsFileTime GetTickCount HeapAlloc HeapCreate HeapFree
HeapReAlloc HeapSize InitializeCriticalSectionAndSpinCount InterlockedDecrement InterlockedIncrement
IsDebuggerPresent IsValidCodePage LCMapStringA LCMapStringW LeaveCriticalSection LoadLibraryA
MultiByteToWideChar QueryPerformanceCounter RtlUnwind SetErrorMode SetFilePointer SetHandleCount
SetLastError SetStdHandle SetUnhandledExceptionFilter Sleep TerminateProcess TlsAlloc TlsFree
TlsGetValue TlsSetValue UnhandledExceptionFilter VirtualAlloc VirtualFree WideCharToMultiByte
WriteConsoleA WriteConsoleW WriteFile'''.split())
REQUIRED_APIS=frozenset('GetStdHandle GetFileType WriteFile SetErrorMode GetModuleHandleA GetProcAddress GetCurrentProcess'.split())
LIBRARY_NAMES=('libcmt.lib','oldnames.lib','kernel32.lib','uuid.lib')
LAYOUT_OBJECTS={'control':['control-sp1','control-rtm','control-vc8'],
                'mixed':['control-sp1','mixed-rtm','mixed-vc8']}


def compile_jobs():
    jobs=[('host','sp1','host',PROBES/'crt_bootstrap_host.cpp',HOST_FLAGS)]
    jobs.extend(('control-'+role,'sp1',role,PROBES/('crt_bootstrap_'+role+'.cpp'),CONSUMER_FLAGS)
                for role in ('sp1','rtm','vc8'))
    jobs.extend(('mixed-'+role,role,role,PROBES/('crt_bootstrap_'+role+'.cpp'),CONSUMER_FLAGS)
                for role in ('rtm','vc8'))
    return jobs


def require(ok,message):
    if not ok:raise ValueError(message)


def sha(path):return toolchain.sha256(path)


def bound(path,digest):
    require(isinstance(digest,str) and re.fullmatch('[0-9a-f]{64}',digest),'invalid trusted hash')
    require(Path(path).stat().st_size<=16*1024*1024 and sha(path)==digest,'stale or oversized metadata')
    return json.loads(Path(path).read_text(encoding='utf-8'))


def source_manifest():
    paths=[PROBES/n for n in SOURCE_NAMES]+[Path(__file__),ROOT/'tests/rebuild/test_crt_bootstrap_contract.py']
    return {p.relative_to(ROOT).as_posix():sha(p) for p in paths}


def source_review(path,digest):
    review=bound(path,digest)
    require(review.get('schema_version')==1 and review.get('kind')=='crt-bootstrap-source-review'
            and review.get('status')=='approved' and isinstance(review.get('reviewer'),str)
            and review['reviewer'].strip() and review.get('allow_prepare') is True
            and review.get('allow_execute') is False,'source review does not authorize prepare-only work')
    require(review.get('sources')==source_manifest(),'source review hashes differ')
    require(all(review.get('checks',{}).get(k) is True for k in SOURCE_CHECKS),'source review checks incomplete')
    return review


def symbols(coff,name):return [s for s in coff.symbols.values() if s['name']==name and s['section']>0]


def one(coff,name):
    rows=symbols(coff,name);require(len(rows)==1,'missing or duplicate native definition: '+name);return rows[0]


def payload(coff,index):
    sec=coff.sections[index];header=coff.unpack('<8sIIIIIIHHI',20+(index-1)*40)
    require(header[4] and len(coff.take(header[4],sec['size']))==sec['size'],'section is not raw-backed')
    return coff.take(header[4],sec['size'])


def validate_directives(coff,host=False):
    actual=[x.replace('"','').upper() for x in coff.directives]
    expected=['/DEFAULTLIB:LIBCMT','/DEFAULTLIB:OLDNAMES']
    # Exact SDK pragma requests evidenced in the saved Windows-header probe.
    # Repeated UUID requests are retained, never treated as duplicate owners.
    if host:expected=['/DEFAULTLIB:UUID.LIB','/DEFAULTLIB:UUID.LIB']+expected+['/INCLUDE:_FNV_BOOTSTRAP_EARLY_SLOT']
    from collections import Counter
    require(Counter(actual)==Counter(expected),'unexpected or duplicate object directives')
    return actual


def early_closure(coff):
    """Entire /Gy sections plus readonly data, never a nearest-symbol slice."""
    start=one(coff,'_fnv_bootstrap_early')['section'];todo=[start];seen=set();undefined=set()
    while todo:
        index=todo.pop()
        if index in seen:continue
        seen.add(index);sec=coff.sections[index]
        require(not sec['name'].startswith(('.text$x','.xdata','.sxdata')),'early observer has EH metadata')
        require(not any(s['selection']=='associative' and s['association']==index for s in coff.sections.values()),
                'early observer has unreviewed associative children')
        if not sec['flags']&0x20000000:
            require(sec['flags']&0x40000000 and not sec['flags']&0x80000000 and not sec['relocs'],
                    'early observer has mutable or pointer-bearing local data')
        payload(coff,index)
        for offset,target_index,kind in sec['relocs']:
            require(kind in (6,20),'unsupported early dependency relocation')
            target=coff.symbols[target_index]
            if target['section']>0:todo.append(target['section'])
            else:
                require(target['section']==0 and target['value']==0 and target['storage']==2
                        and target['name'] in EARLY_EXTERNALS,'early observer has a GS/EH/CRT/unknown dependency')
                undefined.add(target['name'])
    require({'___security_cookie','___security_cookie_complement','__imp__GetStdHandle@4',
             '__imp__GetFileType@4','__imp__WriteFile@20'}<=undefined,
            'early observer lacks cookie observation or the direct inherited pipe sink')
    slot=one(coff,'_fnv_bootstrap_early_slot');sec=coff.sections[slot['section']]
    require(sec['name']=='.CRT$XIAA' and sec['size']==4 and slot['value']==0
            and len(sec['relocs'])==1,'wrong early C-initializer slot')
    offset,index,kind=sec['relocs'][0]
    require(offset==0 and kind==6 and coff.symbols[index]['name']=='_fnv_bootstrap_early'
            and payload(coff,sec['index'])==bytes(4),'wrong C-initializer pointer contract')
    return dict(sections=sorted(seen),undefined_dependencies=sorted(undefined),
        slot_symbol='_fnv_bootstrap_early_slot',entry_symbol='_fnv_bootstrap_early',
        observer_flags='/GS-; no unreviewed native dependency',C_initializer_contract='int __cdecl(void), zero continues')


def consumer_shape(coff,lane):
    title={'sp1':'Sp1','rtm':'Rtm','vc8':'Vc8'}[lane]
    protected=['??0FnvBootstrap'+title+'Object@@QAE@XZ','??1FnvBootstrap'+title+'Object@@QAE@XZ',
               '_fnv_bootstrap_'+lane+'_work']
    observations=[]
    for name in protected:
        s=one(coff,name);sec=coff.sections[s['section']]
        targets=[coff.symbols[i]['name'] for _,i,_ in sec['relocs']]
        require('___security_cookie' in targets and '@__security_check_cookie@4' in targets,
                'consumer lacks actual compiler GS protection: '+name)
        observations.append(dict(symbol=name,section=s['section'],value=s['value']))
    slots=[s for s in coff.sections.values() if s['name']=='.CRT$XCU']
    require(len(slots)==1 and slots[0]['size']==4 and len(slots[0]['relocs'])==1,'consumer has unexpected initializer slots')
    offset,index,kind=slots[0]['relocs'][0];init=coff.symbols[index]
    require(offset==0 and kind==6 and payload(coff,slots[0]['index'])==bytes(4) and init['section']>0,
            'consumer initializer is not a direct source function pointer')
    targets=[coff.symbols[i]['name'] for _,i,_ in coff.sections[init['section']]['relocs']]
    require('_atexit' in targets and protected[0] in targets,'generated initializer lacks constructor/exit registration')
    return dict(protected_functions=observations,initializer_symbol=init['name'],
                initializer_section=init['section'],slot_section=slots[0]['index'])


def map_symbols(text):
    result={}
    for line in text.splitlines():
        match=re.match(r'^\s*[0-9A-Fa-f]{4}:[0-9A-Fa-f]{8}\s+(\S+)\s+([0-9A-Fa-f]{8})\s+(.+?)\s*$',line)
        if not match:continue
        name,address,owner=match.groups();address=int(address,16)
        require(name not in result,'map has duplicate symbol/provenance records')
        result[name]=dict(address=address,owner=owner)
    return result


def validate_link(pe,mapping,initializers,host_object,provider_evidence=None):
    for symbol in CRT_REQUIRED:
        require(symbol in mapping and ('libcmt:' in mapping[symbol]['owner'].lower() or
                (symbol in ('___onexitbegin','___onexitend') and provider_evidence is not None and
                 provider_evidence.get(symbol,{}).get('kind')=='archive-common' and
                 provider_evidence[symbol]['library']=='libcmt.lib')), 'wrong normal CRT provider: '+symbol)
    require('_fnv_bootstrap_early' in mapping and host_object.lower() in mapping['_fnv_bootstrap_early']['owner'].lower(),
            'observer provider is not the original host object')
    entry=pe.unpack('<I',pe.unpack('<I',0x3c)[0]+24+16)[0]+pe.base
    require(entry==mapping['_WinMainCRTStartup']['address'],'PE entry bypasses normal GUI startup')
    slot=mapping['_fnv_bootstrap_early_slot']['address'];observer=mapping['_fnv_bootstrap_early']['address']
    xa,xz,ca,cz=[mapping[n]['address'] for n in ('___xi_a','___xi_z','___xc_a','___xc_z')]
    require(xa<slot<xz and ca<cz and (xz<=ca or cz<=xa) and all(x%4==0 for x in (xa,xz,ca,cz,slot))
            and xz-xa<=4096 and cz-ca<=4096,'C/C++ initializer table ordering is not proved')
    def words(lo,hi):return list(struct.unpack('<'+'I'*((hi-lo)//4),pe.read_rva(lo-pe.base,hi-lo)))
    require(all(x==0 for x in words(xa,slot)) and words(slot,slot+4)==[observer],
            'a nonnull C initializer precedes the unprotected observer')
    cxx=[x for x in words(ca,cz) if x]
    expected=[mapping[name]['address'] for name in initializers]
    require(len(set(expected))==len(expected) and len(cxx)==len(expected) and set(cxx)==set(expected),
            'linked C++ initialization differs from the original consumers')
    require(mapping['___security_cookie']['address']!=mapping['___security_cookie_complement']['address'],
            'cookie and complement cells alias')
    for name in ('___security_cookie','___security_cookie_complement'):
        section=pe.section(mapping[name]['address']-pe.base,4,True)
        require(not section['executable'] and section['flags']&0x80000000,'cookie state is not fresh writable image storage')
    imports=parse_imports(pe);validate_imports(imports)
    return dict(PE_entry=entry,normal_GUI_entry=True,early_slot=slot,early_observer=observer,
                C_range=[xa,xz],CXX_range=[ca,cz],CXX_initializer_order=cxx,
                no_nonnull_C_initializer_before_observer=True,
                runtime_cookie_order_requires_early_event_trace=True,imports=imports)


def validate_imports(records):
    names=[]
    for item in records:
        identity=item['export']
        require(item['dll'].lower()=='kernel32.dll' and identity['kind']=='name'
                and identity['name'] in ALLOWED_APIS,'unexpected DLL/API/ordinal import')
        names.append(identity['name'])
    require(len(names)==len(set(names)) and REQUIRED_APIS<=set(names),'missing or duplicate required named API')
    return sorted(names)


def controlled_libraries(work,vc,sdk):
    roots=[Path(p).resolve() for p in (work,vc,sdk)]
    targets={'libcmt.lib':roots[1]/'libcmt.lib','oldnames.lib':roots[1]/'oldnames.lib',
             'kernel32.lib':roots[2]/'kernel32.lib','uuid.lib':roots[2]/'uuid.lib'}
    for name,target in targets.items():
        candidates=[(p/name).resolve() for p in roots if (p/name).is_file()]
        require(candidates and candidates[0]==target,'earlier competing/missing default library: '+name)
    return {name:file_identity(path) for name,path in targets.items()}


def file_identity(path):
    path=Path(path).resolve();stat=path.stat()
    require(path.is_file(),'library is not a file')
    return dict(path=str(path),device=stat.st_dev,inode=stat.st_ino,size=stat.st_size,sha256=sha(path))


def bound_library(path,binding):
    actual=file_identity(path)
    require(Path(actual['path'])==Path(binding['path']) and
            all(actual[k]==binding[k] for k in ('device','inode','size','sha256')),
            'linker searched an unbound or changed library')
    return actual


def verify_library_log(text,expected):
    searches={};loaded=[];current=None
    for line in text.splitlines():
        match=re.match(r'^\s*Searching\s+(.+?\.lib):?\s*$',line,re.I)
        if match:
            path=Path(match[1]);require(path.is_absolute(),'linker search lacks absolute path')
            path=path.resolve();name=path.name.lower()
            require(name in expected,'linker searched an unbound library')
            bound_library(path,expected[name])
            searches[name]=str(path);current=path
        match=re.match(r'^\s*Loaded\s+(.+?\.lib)\(([^)]+)\)\s*$',line,re.I)
        if match:
            raw,member=match.groups();path=Path(raw);name=path.name.lower()
            require(name in expected and current is not None and current.name.lower()==name,
                    'loaded member lacks exact search context')
            if path.is_absolute():require(path.resolve()==current,'loaded member used another library path')
            else:require(raw.lower()==name,'relative library path is not an exact basename')
            bound_library(current,expected[name])
            loaded.append(dict(library=name,path=str(current),member=member))
    require(set(searches)==set(expected),'actual library search evidence incomplete')
    return dict(searches=searches,loaded_members=loaded,
                log_mode='search-and-loaded' if loaded else 'search-only-requires-map-archive-proof',
                selected_member_evidence_complete=False)


class ArchiveEvidence:
    """Bounded metadata of one exact archive; never export payload bytes."""
    def __init__(self,binding):
        bound_library(binding['path'],binding)
        self.binding=binding;data=Path(binding['path']).read_bytes()
        require(len(data)<=32*1024*1024 and data[:8]==b'!<arch>\n' and
                hashlib.sha256(data).hexdigest()==binding['sha256'],'invalid/big/changed archive')
        self.data=data;self.members={};offset=8
        while offset<len(data):
            require(offset+60<=len(data) and data[offset+58:offset+60]==b'`\n','bad archive header')
            size=int(data[offset+48:offset+58]);end=offset+60+size
            require(end<=len(data),'truncated archive member')
            self.members[offset]=(data[offset:offset+16].decode('ascii').strip(),offset+60,end)
            require(len(self.members)<=100000,'archive member limit')
            offset=end+(size%2)
        require(offset==len(data) and self.members[8][0]=='/','invalid archive directory')
        longnames=next((data[a:b] for name,a,b in self.members.values() if name=='//'),b'')
        self.names={}
        for offset,(name,a,b) in self.members.items():
            if name.startswith('/') and name[1:].isdigit():
                at=int(name[1:]);require(at<len(longnames),'invalid long archive name')
                name=longnames[at:].split(b'\0',1)[0].decode('ascii').rstrip('/')
            if name not in ('/','//'):
                self.names[offset]=Path(name.replace('\\','/')).name.lower().rstrip('/')
        _,a,b=self.members[8];table=data[a:b];require(len(table)>=4,'short archive index')
        count=struct.unpack_from('>I',table)[0]
        require(count<=100000 and 4+4*count<=len(table),'invalid archive symbol count')
        names=table[4+4*count:].split(b'\0');require(len(names)>count,'truncated archive names')
        self.index={}
        for i in range(count):
            member=struct.unpack_from('>I',table,4+4*i)[0]
            require(member in self.names,'index references missing member')
            self.index.setdefault(names[i].decode('ascii'),[]).append(member)
        self.cache={}

    def symbols(self,offset):
        if offset not in self.cache:
            _,a,b=self.members[offset];payload=self.data[a:b]
            require(len(payload)<=1024*1024,'archive member limit')
            # Standard static COFF members only. Import members are proved by
            # their exact archive linker index, never decoded as static code.
            if payload[:4]==b'\0\0\xff\xff':self.cache[offset]=None
            else:
                with tempfile.TemporaryDirectory(prefix='fnv_crt_metadata_') as tmp:
                    path=Path(tmp)/'member.obj';path.write_bytes(payload)
                    self.cache[offset]=list(Coff(path).symbols.values())
        return self.cache[offset]

    def prove(self,symbol,member=None,kind='archive-member',value=None):
        # VC9 maps octal-escape nonprintable COFF symbol characters.
        symbol=re.sub(r'\\([0-7]{3})',lambda m:chr(int(m[1],8)),symbol)
        indexed=self.index.get(symbol,[])
        named=[o for o,n in self.names.items() if member is not None and n==member.lower()]
        # A public index may omit a second static definition. Inspect every
        # same-name physical member; short imports still require index proof.
        offsets=indexed if member is None else named
        matches=[]
        for offset in offsets:
            symbols=self.symbols(offset)
            if symbols is None:
                valid=kind=='archive-member' and offset in self.index.get(symbol,[])
            else:
                defs=[s for s in symbols if s['name']==symbol and
                      (s['section']>0 or s['section']==-1 or (s['section']==0 and s['value']>0))]
                valid=len(defs)==1
                if valid and kind=='archive-common':valid=defs[0]['section']==0 and defs[0]['value']>0
                if valid and kind=='archive-absolute':valid=defs[0]['section']==-1 and defs[0]['value']==value
            if valid:matches.append(offset)
        require(len(matches)<=1,'ambiguous archive symbol/member provenance: '+symbol)
        if not matches:return None
        offset=matches[0];_,a,b=self.members[offset]
        return dict(kind=kind,member=self.names[offset],member_header_offset=offset,
                    member_sha256=hashlib.sha256(self.data[a:b]).hexdigest(),
                    symbol_index_join=offset in self.index.get(symbol,[]),
                    unique_strong_owner_claimed=False,
                    provenance_scope='exact map-visible symbol/member; not provider ABI or full loaded closure')

    def common(self,symbol,selected):
        declarations=[]
        for offset in selected:
            for row in self.symbols(offset) or []:
                if row['name']==symbol and row['section']==0 and row['value']>0:
                    _,a,b=self.members[offset]
                    declarations.append(dict(member=self.names[offset],member_header_offset=offset,
                        member_sha256=hashlib.sha256(self.data[a:b]).hexdigest(),size=row['value']))
        require(len({d['size'] for d in declarations})<=1,'ambiguous common declaration sizes: '+symbol)
        if not declarations:return None
        return dict(kind='archive-common',declarations=declarations,unique_strong_owner_claimed=False,
                    provenance_scope='linker common allocation with selected tentative declarations; no strong owner')


def validate_contributors(mapping,objects,libraries,archives=None):
    expected_objects={Path(p).name.lower():Path(p).resolve() for p in objects}
    archives=archives if archives is not None else {n:ArchiveEvidence(b) for n,b in libraries.items()}
    evidence={};selected={n:set() for n in archives}
    # Prove map-labelled members first; common declarations must originate in
    # this selected set, never a global index's unselected strong definition.
    for symbol,row in mapping.items():
        provider=row['owner'].split()[-1]
        if ':' in provider and not Path(provider).is_absolute():
            library,member=provider.split(':',1);name=library.lower().removesuffix('.lib')+'.lib'
            require(name in archives and member,'unexpected additional library contributor')
            proof=archives[name].prove(symbol,member)
            require(proof is not None,'missing exact archive member provider: '+symbol)
            selected[name].add(proof['member_header_offset'])
    for symbol,row in mapping.items():
        provider=row['owner'].split()[-1];proof=None
        if provider.lower()=='<linker-defined>':
            require(symbol in {'___ImageBase','___safe_se_handler_table'},'unreviewed linker-defined symbol')
            proof=dict(kind='linker-defined',unique_strong_owner_claimed=False)
        elif provider.lower() in ('<common>','<absolute>'):
            kind='archive-common' if provider.lower()=='<common>' else 'archive-absolute'
            if provider.lower()=='<absolute>' and symbol=='___safe_se_handler_count':
                proof=dict(kind='linker-SEH-count',unique_strong_owner_claimed=False)
            else:
                matches=[]
                for name,archive in archives.items():
                    found=archive.common(symbol,selected[name]) if kind=='archive-common' else archive.prove(symbol,kind=kind,value=row['address'])
                    if found:matches.append(dict(found,library=name,archive_sha256=libraries[name]['sha256']))
                require(len(matches)==1,'missing/ambiguous common or absolute provider: '+symbol)
                proof=matches[0]
        elif ':' in provider and not Path(provider).is_absolute():
            library,member=provider.split(':',1);name=library.lower().removesuffix('.lib')+'.lib'
            require(name in archives and member,'unexpected additional library contributor')
            proof=archives[name].prove(symbol,member)
            require(proof is not None,'missing exact archive member provider: '+symbol)
            proof=dict(proof,library=name,archive_sha256=libraries[name]['sha256'])
        else:
            path=Path(provider);name=path.name.lower()
            require(name in expected_objects and (not path.is_absolute() or path.resolve()==expected_objects[name]),
                    'unexpected additional object contributor')
            proof=dict(kind='fixture-object',object_sha256=sha(expected_objects[name]))
        evidence[symbol]=dict(proof,map_provider=provider)
    for name,binding in libraries.items():bound_library(binding['path'],binding)
    return evidence


def linked_consumer_fields(pe,mapping,coff,shape):
    checks=[]
    names=[r['symbol'] for r in shape['protected_functions']]+[shape['initializer_symbol']]
    register=[s['name'] for s in coff.symbols.values() if s['section']>0 and
              re.fullmatch(r'_fnv_bootstrap_(sp1|rtm|vc8)_register',s['name'])]
    require(len(register)==1,'consumer registration definition missing');names+=register
    for name in names:
        require(name in mapping,'linked consumer function absent');symbol=one(coff,name)
        sec=coff.sections[symbol['section']];data=payload(coff,symbol['section'])
        for offset,index,kind in sec['relocs']:
            target=coff.symbols[index]['name']
            if target not in ('___security_cookie','@__security_check_cookie@4','_atexit'):continue
            require(kind in (6,20) and symbol['value']<=offset<=len(data)-4,'bad consumer state field')
            addend=struct.unpack_from('<i' if kind==20 else '<I',data,offset)[0]
            field=mapping[name]['address']+offset-symbol['value']
            original=struct.unpack('<i' if kind==20 else '<I',pe.read_rva(field-pe.base,4,allow_code=True))[0]
            observed=(field+4+original)&0xffffffff if kind==20 else original
            require(observed==(mapping[target]['address']+addend)&0xffffffff,'consumer field does not bind canonical CRT state')
            checks.append(dict(function=name,offset=offset-symbol['value'],kind=kind,target=target,
                               target_va=mapping[target]['address'],addend=addend))
    require(any(r['target']=='_atexit' for r in checks),'actual consumer exit registration not linked')
    return checks


def decode_events(data):
    require(len(data)<=64*EVENT.size and len(data)%EVENT.size==0,'event capture is oversized or truncated')
    rows=[]
    for offset in range(0,len(data),EVENT.size):
        magic,schema,lane,kind,value,aux=EVENT.unpack_from(data,offset)
        require(magic==MAGIC and schema==1 and lane in (0,1,2,3) and 1<=kind<=8,'invalid event record')
        rows.append((lane,kind,value,aux))
    return rows


def validate_trace(data,variant,returncode,stderr=b''):
    require(returncode==0 and not stderr,'child did not return normally without stderr')
    require(variant in ('control','mixed'),'unknown consumer/compiler variant')
    rows=decode_events(data);lanes=[1,2,3]
    require(rows and rows[0]==(0,1,7,0),'cookie observation missing, late or not initialized')
    require(len(rows)>=1+len(lanes),'constructor events missing')
    ctors=rows[1:1+len(lanes)];order=[r[0] for r in ctors]
    require(sorted(order)==lanes and all(r==(r[0],2,32*r[0]+496,0) for r in ctors),'constructor events invalid')
    expected=[(0,3,len(lanes),15)]
    for lane in lanes:expected.extend([(lane,4,64*lane+2016,0),(lane,5,0,0)])
    expected.append((0,6,0,0))
    expected.extend((lane,7,0,0) for lane in reversed(lanes))
    expected.extend((lane,8,32*(lane+1)+496,0) for lane in reversed(order))
    require(rows[1+len(lanes):]==expected,'normal return/callback/destructor sequence differs')
    return dict(consumer_source_roles=lanes,observed_constructor_order=order,events=len(rows),
                initialized_cookie_before_protected_consumers=True,normal_exit_sequence=True)


def capture_include_roots(allowed):
    snapshot=[]
    for base in allowed:
        original=Path(base).absolute();canonical=original.resolve(strict=True)
        require(canonical.is_dir(),'approved include root is not a directory')
        stat=canonical.stat()
        snapshot.append(dict(root=str(original),canonical=str(canonical),device=stat.st_dev,inode=stat.st_ino))
    return snapshot


def verify_include_roots(snapshot):
    for row in snapshot:
        canonical=Path(row['root']).resolve(strict=True)
        require(canonical==Path(row['canonical']) and canonical.is_dir(),'approved include root was repointed')
        stat=canonical.stat()
        require((stat.st_dev,stat.st_ino)==(row['device'],row['inode']),'approved include root identity changed')


def includes(text,allowed,root_snapshot=None):
    snapshot=capture_include_roots(allowed) if root_snapshot is None else root_snapshot
    verify_include_roots(snapshot)
    roots=[Path(row['canonical']) for row in snapshot]
    paths=set()
    for line in text.splitlines():
        match=re.match(r'^Note: including file:\s*(.+?)\s*$',line)
        if match:
            path=Path(match.group(1)).resolve(strict=True)
            require(path.is_file() and any(path.is_relative_to(base) for base in roots),'compiler included an unapproved path')
            paths.add(path)
    require(paths,'compiler did not report include context')
    verify_include_roots(snapshot)
    return paths


def cookie_default(lib):
    data,meta=archive_member(lib,'___security_cookie')
    import tempfile
    with tempfile.TemporaryDirectory(prefix='fnv_bootstrap_cookie_') as tmp:
        path=Path(tmp)/'cookie.obj';path.write_bytes(data);coff=Coff(path)
    cookie=one(coff,'___security_cookie');comp=one(coff,'___security_cookie_complement')
    values=[]
    for s in (cookie,comp):
        sec=coff.sections[s['section']]
        require(sec['size']==4 and s['value']==0 and not sec['relocs'],'cookie definition is not the bounded x86 cell')
        values.append(struct.unpack('<I',payload(coff,s['section']))[0])
    require(values[0]!=0 and values[1]==(~values[0]&0xffffffff),'normal library default/complement disagree')
    return values[0],meta


def prepare(args):
    require(args.allow_native_prepare is True,'native preparation requires explicit opt-in')
    source_review(args.source_review,args.source_review_sha256) # Must precede every native call.
    doctor=bound(args.doctor,args.doctor_sha256)
    require(os.name=='nt','native Windows preparation required')
    require(not any(os.environ.get(n) for n in ('LINK','_LINK_','LIBPATH')),'implicit linker/search options rejected')
    out=Path(args.out).resolve();require(not out.exists(),'new output directory required')
    roots={k:toolchain.layout(doctor['toolchains'][k]['root'])[0] for k in ('sp1','rtm','vc8')}
    include_root_snapshots={}
    for lane,root in roots.items():
        _,lane_sdk=toolchain.layout(root)
        include_root_snapshots[lane]=capture_include_roots([root/'VC/include',lane_sdk/'Include',PROBES])
    observed={Path(args.source_review).resolve():args.source_review_sha256,Path(args.doctor).resolve():args.doctor_sha256}
    for relative,h in source_manifest().items():observed[ROOT/relative]=h
    for module in ('toolchain.py','coff_inventory.py','data_plan.py','import_plan.py','crt_provider.py'):
        path=ROOT/'tools/rebuild'/module;observed[path]=sha(path)
    for path in (ROOT/'tools/compare.py',ROOT/'tools/build_and_match.py',ROOT/'tools/function_spans.py'):
        observed[path]=sha(path)
    for lane,root in roots.items():
        row=doctor['toolchains'][lane]
        require(row.get('ready') is True and row.get('version')==toolchain.VERSIONS[lane]
                and sha(root/'VC/bin/cl.exe')==row['cl_sha256'],'compiler differs from approved doctor')
        for file in ('cl.exe','c1xx.dll','c2.dll'):
            path=root/'VC/bin'/file;observed[path]=sha(path)
    sp1=roots['sp1'];_,sdk=toolchain.layout(sp1)
    require(sha(sp1/'VC/bin/link.exe')==doctor['toolchains']['sp1']['link_sha256'],'SP1 linker differs')
    for path in (sp1/'VC/bin/link.exe',sp1/'VC/lib/libcmt.lib',sp1/'VC/lib/oldnames.lib',sdk/'Lib/kernel32.lib',sdk/'Lib/uuid.lib'):
        observed[path]=sha(path)
    for name in ('kernel32.dll','kernelbase.dll','ntdll.dll'):
        path=Path(os.environ['SystemRoot'])/'SysWOW64'/name;observed[path]=sha(path)
    default,member=cookie_default(sp1/'VC/lib/libcmt.lib')
    out.mkdir(parents=True);progress=out/'progress.jsonl';objects={};shapes={};commands=[]
    report=dict(schema_version=1,kind='original-crt-bootstrap-preparation',status='error',
        source_review_sha256=args.source_review_sha256,game_execution=False,fixture_execution=False,
        runtime_provider_approved=False,game_fixups_approved=0,experimental_CRT='normal SP1 static CRT only',
        include_root_identities=include_root_snapshots,include_root_identity_stable=False,input_stability_verified=False,
        host_flags=HOST_FLAGS,consumer_flags=CONSUMER_FLAGS,commands=commands)
    with progress.open('x',encoding='utf-8') as journal:
        def note(state,**data):journal.write(json.dumps(dict(state=state,**data))+'\n');journal.flush();os.fsync(journal.fileno())
        def stable():
            for snapshot in include_root_snapshots.values():verify_include_roots(snapshot)
            for path,h in observed.items():require(sha(path)==h,'prepared input changed: '+path.name)
        def run(command,root,log):
            stable();commands.append([str(c) for c in command]);code,text=toolchain.run(command,root,out,timeout=90)
            path=out/log;path.write_text(text,encoding='utf-8');observed[path]=sha(path)
            stable()
            require(code==0,'native preparation failed; inspect '+log);return text
        try:
            note('started',sources=source_manifest())
            jobs=compile_jobs()
            layouts={};object_roles={}
            libraries=controlled_libraries(out,sp1/'VC/lib',sdk/'Lib')
            def link_layout(name,roles):
                stable();require(controlled_libraries(out,sp1/'VC/lib',sdk/'Lib')==libraries,'library search changed before link')
                exe=out/(name+'.exe');mapping=out/(name+'.map');host=objects['host']
                used=[host]+[objects[key] for key in roles]
                log=run([sp1/'VC/bin/link.exe','/nologo','/machine:x86','/subsystem:windows','/incremental:no','/opt:ref','/VERBOSE:LIB',
                         '/out:'+str(exe),'/map:'+str(mapping)]+used,sp1,name+'-link.log')
                resolved=verify_library_log(log,libraries)
                require(controlled_libraries(out,sp1/'VC/lib',sdk/'Lib')==libraries,'library search changed during link')
                observed[exe]=sha(exe);observed[mapping]=sha(mapping);table=map_symbols(mapping.read_text())
                contributors=validate_contributors(table,used,libraries)
                resolved['selected_member_evidence_complete']=True
                resolved['selected_member_scope']='map-visible definitions joined to exact bound archive metadata; not a full Loaded log'
                pe=Pe(exe)
                try:
                    linked=validate_link(pe,table,[shapes[key]['initializer_symbol'] for key in roles],host.name,contributors)
                    linked['consumer_CRT_fields']={key:linked_consumer_fields(pe,table,Coff(objects[key]),shapes[key]) for key in roles}
                finally:pe.close()
                layouts[name]=dict(executable_sha256=observed[exe],map_sha256=observed[mapping],
                    source_roles_and_actual_compilers=[object_roles[key] for key in roles],linked=linked,
                    actual_linker_libraries=resolved,map_contributors=contributors,CRT_providers={n:table[n] for n in CRT_REQUIRED})
                note('linked',layout=name,executable_sha256=observed[exe])
            for name,lane,role,source,flags in jobs:
                root=roots[lane];_,lane_sdk=toolchain.layout(root)
                definitions=['/DFNV_CRT_COOKIE_DEFAULT=0x%08xu'%default] if role=='host' else []
                prefix=[root/'VC/bin/cl.exe']+flags+['/I'+str(PROBES)]+definitions
                text=run(prefix+['/Zs',source],root,name+'-syntax.log')
                headers=includes(text,[root/'VC/include',lane_sdk/'Include',PROBES],include_root_snapshots[lane])
                for path in headers:observed[path]=sha(path)
                obj=out/(name+'.obj')
                text=run(prefix+[source,'/Fo'+str(obj)],root,name+'-compile.log')
                require(includes(text,[root/'VC/include',lane_sdk/'Include',PROBES],include_root_snapshots[lane])==headers,
                        'compile include set changed after syntax discovery')
                observed[obj]=sha(obj);coff=Coff(obj);validate_directives(coff,role=='host')
                shapes[name]=early_closure(coff) if role=='host' else consumer_shape(coff,role)
                object_roles[name]=dict(source_role=role,actual_compiler=lane,compiler_version=toolchain.VERSIONS[lane],object=name+'.obj')
                objects[name]=obj;note('compiled',object=name,object_sha256=observed[obj])
                if name=='control-vc8':link_layout('control',LAYOUT_OBJECTS['control'])
            link_layout('mixed',LAYOUT_OBJECTS['mixed'])
            stable()
            report.update(status='prepared-not-executed',inputs={str(p):h for p,h in observed.items()},
                include_root_identity_stable=True,input_stability_verified=True,
                normal_cookie_member=member,object_shapes=shapes,layouts=layouts,
                observer_order_evidence='unprotected C-initializer callback and exact C/C++ tables; runtime ordering awaits independently approved early-event trace',
                OS_dependency_scope='x86 direct kernel32 plus core kernelbase/ntdll snapshots; not full transitive loader proof')
            note('complete',fixture_execution=False)
        except (OSError,ValueError,KeyError,struct.error) as error:
            report['error']=str(error);note('failed',error_type=type(error).__name__)
    with (out/'prepare.json').open('x',encoding='utf-8') as f:json.dump(report,f,indent=2);f.write('\n')
    return report


def main(argv=None):
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--doctor',required=True,type=Path);p.add_argument('--doctor-sha256',required=True)
    p.add_argument('--source-review',required=True,type=Path);p.add_argument('--source-review-sha256',required=True)
    p.add_argument('--allow-native-prepare',action='store_true');p.add_argument('--out',required=True,type=Path)
    try:report=prepare(p.parse_args(argv))
    except (OSError,ValueError,KeyError,struct.error) as error:p.exit(2,'bootstrap preparation rejected: '+str(error)+'\n')
    print(report['status']);return 0 if report['status']=='prepared-not-executed' else 1


if __name__=='__main__':raise SystemExit(main())
