"""Prepare-only real three-method Box component mechanism test. No execute API."""
from __future__ import annotations
import argparse
import copy
import json
import os
from pathlib import Path
import re
import queue
import struct
import subprocess
import sys
import threading
import time

import bulk_code_pool as bulk
import coff_code_archive as coff
from coff_rewrite import strict_object
import crt_bootstrap_contract as boot
import tls_owner_fixture as tls
import toolchain
from data_plan import Pe
from import_plan import parse_imports

ROOT=Path(__file__).resolve().parents[2]
POLICY='real-source-box-union-component-v1'
OWNED=('tools/rebuild/box_union_component.py','tests/rebuild/test_box_union_component.py',
       'runtime/probes/box_union_probe.hpp','runtime/probes/box_union_probe.cpp',
       'runtime/code-pools/box-union-component.json','docs/rebuild/BOX-UNION-COMPONENT.md')
SOURCE=ROOT/'src/havok/physics/collide/boxbox/hkpboxboxmanifold.cpp'
PROJECT=ROOT/'build/rebuild/union-reference-box2089-projection-v1'
PROJECTION_SHA='c057095b727eced69ae5a45da3dc6498e189d64c47522f4ad1b5e1bbc1ea2d63'
DETAIL_SHA='9884b0ec82f6ab6f3f8fcc880ea8ded8a152fbd897b5b1d5086575a7c1d521eb'
MEMBER_SHA='84d4e7e09d93d0621301ddb9257194e64f9de3164d40826bd766f48537345600'
ARCHIVE_SHA='c812f534eee078b17cac7816cd38585290e683198ec53f8670e5e162119abc1c'
OUTCOME_REVIEW_SHA='2f9a2308e465c79282356e1019b2465e20445bebc8f19c17a092e673ec25c2f4'
RECIPE='2089-51b16ad19e044300'
ROOTS={'0x00db0920':'?FUN_00db0920@FUN_00db0920_cls@@QAEPAU1@XZ',
       '0x00db0960':'?FUN_00db0960@BoxPointInsertion@@QAEHIIPBE@Z',
       '0x00db09b0':'?ContainsKey@FUN_00db0920@@QAEPAEPAEPBE@Z'}
COMPILE=['/nologo','/c','/MT','/Od','/Oy-','/GS','/EHsc','/Gy','/W4','/showIncludes']
LINK=['/nologo','/machine:x86','/subsystem:console','/incremental:no','/opt:ref','/opt:noicf',
      '/safeseh','/dynamicbase:no','/fixed:no','/VERBOSE:LIB']
EXPECTED=dict(schema=1,rounds=128,reset_calls=128,insertion_calls=2176,lookup_calls=2432,guards_ok=True,capacity=8)
FALSE=dict(runtime_provider_approved=False,game_fixups_approved=0,general_Game_runtime_approved=False,
           fixture_execution=False,game_engine_executed=False)
sha,require=toolchain.sha256,coff.require


def read_json(path):return json.loads(Path(path).read_text(encoding='utf-8'))


def save(path,value):
    with Path(path).open('x',encoding='utf-8') as stream:
        json.dump(value,stream,indent=2);stream.write('\n');stream.flush();os.fsync(stream.fileno())


def stable(inputs):
    require(not (ROOT/'build/function_index.json').exists(),'optional index must remain absent')
    require(all(sha(path)==value for path,value in inputs.items()),'protected source/component/tool input changed')


def declarations(text):
    """Bounded brace extraction of the four original declarations, no bodies."""
    result={}
    for kind,name in (('struct','FUN_00db0920'),('struct','FUN_00db0920_cls'),
                      ('class','BoxPointLookup'),('class','BoxPointInsertion')):
        hits=list(re.finditer(r'\b'+kind+r'\s+'+name+r'\s*(?::[^\{;]+)?\{',text))
        require(len(hits)==1,'missing/duplicate original full type declaration: '+name)
        start=hits[0].start();at=hits[0].end();depth=1
        while depth and at<len(text):
            if text[at]=='{':depth+=1
            if text[at]=='}':depth-=1
            at+=1
        require(not depth and re.match(r'\s*;',text[at:]),'unterminated type declaration')
        end=at+re.match(r'\s*;',text[at:]).end()
        tokens=re.findall(r'[A-Za-z_]\w*|\d+|::|[^\s]',text[start:end])
        result[name]=tokens
    return result


def validate_declarations(original,header):
    require(declarations(original)==declarations(header),'typed caller declaration/layout differs from exact source')


def projection_basis(review_path,review_sha):
    """Exact accepted private lineage, not same-address success booleans."""
    require(review_sha==OUTCOME_REVIEW_SHA and Path(review_path).resolve()==PROJECT/'independent-outcome-review.json'
            and sha(review_path)==review_sha,'stale independent projection review identity/hash')
    review=read_json(review_path)
    expected=dict(projection_receipt_sha256=PROJECTION_SHA,projection_details_sha256=DETAIL_SHA,
                  member_sha256=MEMBER_SHA,archive_sha256=ARCHIVE_SHA)
    require(review.get('kind')=='box-union-projection-independent-review-v1' and review.get('status')=='accepted'
            and review.get('reviewer') and all(review.get(k)==v for k,v in expected.items())
            and review.get('native_tools_approved') is False and review.get('runtime_approved') is False,
            'independent projection review does not bind exact component artifacts/scope')
    paths={PROJECT/'receipt.json':PROJECTION_SHA,PROJECT/'certificates.jsonl':DETAIL_SHA,
           PROJECT/(RECIPE+'.obj.stage'):MEMBER_SHA,PROJECT/'union-reference-0000.lib':ARCHIVE_SHA,
           Path(review_path).resolve():review_sha}
    stable(paths);prepared=read_json(PROJECT/'receipt.json')
    details=(PROJECT/'certificates.jsonl').read_text().splitlines();require(len(details)==1,'one exact component record required')
    record=json.loads(details[0]);cert=record['certificate']
    require(prepared['status']=='complete' and prepared['profile']=='box2089' and prepared['operation']=='project'
            and prepared['input_stability_verified'] is True and prepared['projected_roots']==3
            and prepared['requested_recipe_ids']==[RECIPE] and cert['recipe_id']==RECIPE
            and {r['original_address'] for r in cert['roots']}==set(ROOTS)
            and record['fresh_reference_match'] is True and record['native_shape_verified'] is True
            and cert['runtime_eligible'] is False and cert['provider_selected'] is False,
            'exact source-built component projection is incomplete')
    require(len(cert['groups'])==1 and cert['groups'][0]['members']==[8,19]
            and cert['groups'][0]['kind']=='one-selected-definition-and-undefined'
            and cert['groups'][0]['native_shape_verified'] is True
            and dict(cert['primary_bijection'])[8]!=dict(cert['primary_bijection'])[19],
            'distinct definition/reference mechanism proof differs')
    for comparison in ('before_comparison','after_comparison'):
        rows=record[comparison]
        require(len(rows)==3 and {r['address'] for r in rows}==set(ROOTS)
                and sum(r['size'] for r in rows)==182 and all(r['verdict']=='match' for r in rows),
                'source-built original/projected full body proof differs')
    paths.update({Path(p):h for p,h in prepared['protected_inputs'].items()})
    require(len(prepared['protected_inputs'])==37,'projection protected scope differs')
    require(sha(SOURCE)==cert['source_sha256'],'original declaration source changed')
    paths[SOURCE]=cert['source_sha256'];stable(paths)
    names={root['original_address']:next(r['name'] for r in cert['namespace_plan']
        if r['physical_index']==root['symbol_index']) for root in cert['roots']}
    return record,names,paths


def bind_caller(data,names):
    """Three naturally typed undefined methods; name fields only, no adapter."""
    require(set(names)==set(ROOTS) and len(set(names.values()))==3,'wrong exact component namespace')
    obj=coff.parse(data);bindings=[];calls=[]
    for address,old in ROOTS.items():
        matches=[(i,s) for i,s in obj['symbols'].items() if s['name']==old]
        require(len(matches)==1,'caller method is absent or has duplicate physical records')
        index,symbol=matches[0]
        require(symbol['section']==symbol['value']==0 and symbol['type']==32 and symbol['storage']==2
                and symbol['aux_count']==0,'caller method must be plain typed undefined CODE')
        uses=[]
        for section,sec in obj['sections'].items():
            for offset,target,kind in sec['relocs']:
                if target!=index:continue
                require(kind==20 and sec['flags']&0x20000000 and 0<offset<=len(sec['payload'])-4
                        and sec['payload'][offset-1]==0xe8 and struct.unpack_from('<I',sec['payload'],offset)[0]==0,
                        'caller method use is not an exact zero-addend direct REL32 call')
                anchors=[s for s in obj['symbols'].values() if s['section']==section and s['storage']==2
                         and s['type']==32 and s['value']==0 and not s['aux_count']]
                require(len(anchors)==1,'caller call section lacks unique external source function anchor')
                uses.append(dict(section=section,offset=offset,kind=kind,symbol_index=index,anchor=anchors[0]['name']))
        require(uses,'caller method has no actual direct call use')
        bindings.append([index,names[address]]);calls.append(dict(original_address=address,old_name=old,
            canonical_name=names[address],physical_index=index,uses=uses))
    require(all(not s['name'].startswith('_fnv_code_') for s in obj['symbols'].values()),'caller already contains canonical provider aliases')
    result=bulk.namespace_union(data,dict(eligible=True,object_sha256=coff.digest(data),bindings=bindings,reference_certificates=[]))
    after=coff.parse(result);expected=copy.deepcopy(obj['symbols'])
    for index,name in bindings:expected[index]['name']=name
    require(after['symbols']==expected and after['sections']==obj['sections'],'caller changed beyond exact names')
    return result,dict(calls=calls,input_sha256=coff.digest(data),output_sha256=coff.digest(result),
                       physical_indices_preserved=True,relocations_unchanged=True,abi_adapter_emitted=False)


def independent_caller(before_path,after_path,contract):
    before,bp,_,_=strict_object(before_path);after,ap,_,_=strict_object(after_path)
    require(sha(before_path)==contract['input_sha256'] and sha(after_path)==contract['output_sha256'],'caller rewrite identity differs')
    expected=copy.deepcopy(before.symbols)
    for row in contract['calls']:expected[row['physical_index']]['name']=row['canonical_name']
    require(expected==after.symbols and before.sections==after.sections,'strict independent caller facts changed')
    for index,symbol in before.symbols.items():
        require(before.take(bp+(index+1)*18,symbol['aux_count']*18)==after.take(ap+(index+1)*18,symbol['aux_count']*18),
                'caller auxiliary bytes changed')
    return dict(all_sections_symbols_auxiliary_and_relocations_equal=True)


def inspect_link(exe,mapfile,member_path,record,names,caller_contract,contributors):
    mapping=boot.map_symbols(Path(mapfile).read_text());obj=coff.parse(Path(member_path).read_bytes())
    cert=record['certificate'];maps=record['projection']['maps'];sm={int(k):v for k,v in maps['section_map'].items()}
    ym={int(k):v for k,v in maps['symbol_map'].items()}
    expected_names=set(names.values())
    actual={name for name,proof in contributors.items() if proof.get('library')=='union-reference-0000.lib'}
    require(actual==expected_names,'linked archive contributed extra/missing Game definitions')
    for name in expected_names:
        require(name in mapping and contributors[name]['member_sha256']==MEMBER_SHA,'selected Game member provider differs')
    pe=Pe(exe)
    try:
        entry=pe.unpack('<I',pe.unpack('<I',0x3c)[0]+24+16)[0]+pe.base
        require('_mainCRTStartup' in mapping and entry==mapping['_mainCRTStartup']['address'] and
                contributors['_mainCRTStartup'].get('library')=='libcmt.lib','normal console CRT startup absent')
        require(not pe.directories[9][0],'fixture unexpectedly contains static TLS')
        bodies=[];ranges=[];fields=[]
        for root in cert['roots']:
            name=names[root['original_address']];address=mapping[name]['address'];ranges.append((address,address+root['size']))
            sec=obj['sections'][sm[root['section']]];payload=sec['payload'][root['value']:root['value']+root['size']]
            # Only the new owned linked image, exact mapped selected body.
            actual_bytes=pe.read_rva(address-pe.base,root['size'],allow_code=True);relocated=set()
            for offset,index,kind in sec['relocs']:
                require(root['value']<=offset and offset+4<=root['value']+root['size'],'Game relocation outside root extent')
                local=offset-root['value'];target=obj['symbols'][index]['name']
                require(kind==20 and struct.unpack_from('<I',payload,local)[0]==0 and target in expected_names,
                        'unsupported Game component relocation')
                resolved=address+local+4+struct.unpack_from('<i',actual_bytes,local)[0]
                require(resolved==mapping[target]['address'],'intra-union relocation did not resolve to exact selected definition')
                relocated.update(range(local,local+4));fields.append(dict(root=name,offset=local,target=target,
                    physical_symbol_index=next(k for k,v in ym.items() if v==index),serialized_symbol_index=index,resolved=resolved))
            require(len(payload)==root['size'] and all(a==b or i in relocated for i,(a,b) in enumerate(zip(payload,actual_bytes))),
                    'linked Game body differs outside exact relocation fields')
            bodies.append(dict(original_address=root['original_address'],canonical_name=name,address=address,size=root['size'],
                linked_payload_equal_except_exact_relocations=True))
        ordered=sorted(ranges);require(all(a[1]<=b[0] for a,b in zip(ordered,ordered[1:])) and len(fields)==1,'Game root ranges/field count differ')
        caller_fields=[]
        for call in caller_contract['calls']:
            for use in call['uses']:
                require(use['anchor'] in mapping and contributors[use['anchor']].get('kind')=='fixture-object',
                        'typed caller anchor not supplied by original authored caller')
                address=mapping[use['anchor']]['address']+use['offset']
                # Exact four-byte naturally typed caller relocation operand.
                actual=address+4+struct.unpack('<i',pe.read_rva(address-pe.base,4,allow_code=True))[0]
                require(actual==mapping[call['canonical_name']]['address'],'typed caller did not reach exact selected Game root')
                caller_fields.append(dict(anchor=use['anchor'],field=address,target=call['canonical_name'],resolved=actual))
        apis=[]
        for item in parse_imports(pe):
            identity=item['export'];require(item['dll'].lower()=='kernel32.dll' and identity['kind']=='name'
                and identity['name'] in boot.ALLOWED_APIS,'unreviewed direct DLL/API/ordinal')
            apis.append(identity['name'])
        require(len(apis)==len(set(apis)) and {'GetStdHandle','WriteFile','SetErrorMode'}<=set(apis),'missing/duplicate source-required imports')
        return dict(normal_console_CRT_entry=entry,Game_bodies=bodies,intra_union_fields=fields,
                    naturally_typed_caller_fields=caller_fields,named_imports=sorted(apis),**FALSE)
    finally:pe.close()


def parse_result(stdout,stderr,returncode):
    require(returncode==0 and stderr==b'' and len(stdout)<=4096 and len(stdout.splitlines())==1,'Box caller failed/extra output')
    record=json.loads(stdout)
    require(record==EXPECTED and all(type(record[k]) is type(v) for k,v in EXPECTED.items()),'Box caller result differs')
    return record


def run_native(command,root,work,log,timeout=60,cap=4*1024*1024):
    """Only own child, bounded pipe memory/output, hidden and without a shell."""
    require(timeout>0 and cap>0,'invalid native capture bounds')
    require(command and Path(command[0]).resolve() in {(Path(root)/'VC/bin/cl.exe').resolve(),
        (Path(root)/'VC/bin/link.exe').resolve()},'only pinned compiler/linker commands are permitted')
    require(not Path(log).exists(),'exclusive native log required before launch')
    stop=threading.Event();blocks=queue.Queue(maxsize=2)
    child=subprocess.Popen([str(c) for c in command],cwd=work,env=toolchain.environment(root),
        stdin=subprocess.DEVNULL,stdout=subprocess.PIPE,stderr=subprocess.STDOUT,shell=False,
        creationflags=getattr(subprocess,'CREATE_NO_WINDOW',0))
    def consume():
        try:
            while not stop.is_set():
                data=child.stdout.read1(4096)
                while not stop.is_set():
                    try:blocks.put(data,timeout=0.05);break
                    except queue.Full:pass
                if not data:break
        except Exception as error:
            while not stop.is_set():
                try:blocks.put(error,timeout=0.05);break
                except queue.Full:pass
    reader=threading.Thread(target=consume,daemon=True);reader.start();deadline=time.monotonic()+timeout;size=0
    try:
        with Path(log).open('xb') as target:
            while True:
                require(time.monotonic()<deadline,'native call timed out')
                try:data=blocks.get(timeout=min(0.1,max(0.001,deadline-time.monotonic())))
                except queue.Empty:continue
                if isinstance(data,Exception):raise data
                if not data:break
                # Keep at most one byte beyond policy limit as failure evidence.
                chunk=data[:max(0,cap+1-size)];target.write(chunk);size+=len(chunk)
                require(size<=cap,'native output cap exceeded; captured prefix is incomplete')
            target.flush();os.fsync(target.fileno())
        returncode=child.wait(timeout=max(0.001,deadline-time.monotonic()))
        return returncode,Path(log).read_text(encoding='utf-8',errors='replace')
    finally:
        stop.set()
        if child.poll() is None:child.kill()
        child.wait(timeout=5);reader.join(timeout=1);child.stdout.close()


def prepare(args):
    require(args.allow_native_prepare is True,'native preparation requires separate explicit root go')
    require(sha(args.policy)==args.policy_sha256,'stale Box policy')
    policy=read_json(args.policy);require(policy['policy_id']==POLICY,'wrong Box policy')
    require(policy['compile_flags']==COMPILE and policy['link_flags']==LINK and policy['expected_result']==EXPECTED
            and policy['original_addresses']==sorted(ROOTS) and policy['projection_review_sha256']==OUTCOME_REVIEW_SHA,
            'policy source/flags/result contract differs')
    sources={p:sha(ROOT/p) for p in OWNED}
    require(sha(args.source_review)==args.source_review_sha256,'stale Box source review')
    reviewed=read_json(args.source_review)
    require(reviewed.get('kind')=='box-union-component-source-review-v1' and reviewed.get('status')=='accepted'
        and reviewed.get('reviewer') and reviewed.get('source_sha256')==sources
        and reviewed.get('producer_sha256')==policy['producer_sha256'] and reviewed.get('prepare_only') is True,
        'exact Box source/producer review required before any native call')
    require(os.name=='nt' and not any(os.environ.get(k) for k in ('CL','_CL_','LINK','_LINK_','LIBPATH')),
            'Windows without implicit compiler/linker/search flags required')
    protected={ROOT/p:h for p,h in sources.items()}
    controls=dict(protected)
    for p,h in policy['producer_sha256'].items():
        path=ROOT/p;require(sha(path)==h,'stale helper');protected[path]=h;controls[path]=h
        module=sys.modules.get(Path(p).stem)
        require(module is None or Path(module.__file__).resolve()==path,'unexpected loaded helper')
    record,names,lineage=projection_basis(args.projection_review,args.projection_review_sha256);protected.update(lineage)
    for path,value in ((args.doctor,args.doctor_sha256),(args.source_review,args.source_review_sha256),
                       (args.projection_review,args.projection_review_sha256)):
        require(sha(path)==value,'stale review/doctor');protected[Path(path).resolve()]=value;controls[Path(path).resolve()]=value
    validate_declarations(SOURCE.read_text(),(ROOT/OWNED[2]).read_text())
    tc=read_json(args.doctor)['toolchains']['sp1'];root,sdk=toolchain.layout(tc['root'])
    require(tc.get('ready') is True and tc.get('version')==toolchain.VERSIONS['sp1'] and
            sha(root/'VC/bin/cl.exe')==tc['cl_sha256'] and sha(root/'VC/bin/link.exe')==tc['link_sha256'],'SP1 compiler/linker differs')
    trusted=[root/'VC/bin'/n for n in ('cl.exe','link.exe','c1xx.dll','c2.dll')]
    trusted += [p for p in (root/'Common7/IDE/mspdb80.dll',root/'Common7/IDE/msobj80.dll',root/'VC/bin/1033/clui.dll',
                root/'VC/redist/x86/Microsoft.VC90.CRT/msvcr90.dll',root/'VC/redist/x86/Microsoft.VC90.CRT/msvcp90.dll') if p.is_file()]
    out=Path(args.out).resolve();private=(ROOT/'build/rebuild').resolve()
    require(out!=private and out.is_relative_to(private) and not out.exists(),'new exclusive private preparation directory required')
    include_roots=boot.capture_include_roots([root/'VC/include',sdk/'Include',(ROOT/OWNED[2]).parent])
    libraries=boot.controlled_libraries(out,root/'VC/lib',sdk/'Lib')
    for path in trusted+[Path(v['path']) for v in libraries.values()]:protected[path]=controls[path]=sha(path)
    for name in ('kernel32.dll','kernelbase.dll','ntdll.dll'):
        path=Path(os.environ['SystemRoot'])/'SysWOW64'/name;protected[path]=controls[path]=sha(path)
    stable(protected);out.mkdir(parents=True);commands=[];start=time.monotonic()
    report=dict(schema_version=1,kind='real-source-box-union-component-prepared',policy_id=POLICY,status='error',
        source_review_sha256=args.source_review_sha256,projection_review_sha256=args.projection_review_sha256,
        expected_result=EXPECTED,commands=commands,native_compile_attempted=False,native_link_attempted=False,**FALSE)
    generated={}
    with (out/'progress.jsonl').open('x') as journal:
        def note(state,**values):journal.write(json.dumps(dict(state=state,**values))+'\n');journal.flush();os.fsync(journal.fileno())
        def check():
            boot.verify_include_roots(include_roots);stable(controls);stable(generated)
            require(time.monotonic()-start<600,'bounded prepare time exceeded')
            require(sum(p.stat().st_size for p in out.iterdir() if p.is_file())<=100*1024*1024,'private preparation output cap exceeded')
        def run(command,log,allow_version_failure=False):
            check();commands.append([str(c) for c in command])
            path=out/log
            try:code,text=run_native(command,root,out,path)
            finally:
                if path.is_file():generated[path]=sha(path)
            check();require(code==0 or allow_version_failure,'native preparation failed: '+log);return text
        try:
            note('started',native_execution=False)
            banner=run([root/'VC/bin/cl.exe'],'compiler-version.log',True)
            require(re.search(r'Version\s+15\.00\.30729\.01\b',banner),'fresh compiler version differs')
            prefix=[root/'VC/bin/cl.exe']+COMPILE
            report['native_compile_attempted']=True
            text=run(prefix+['/Zs',ROOT/OWNED[3]],'caller-includes.log')
            headers=boot.includes(text,[root/'VC/include',sdk/'Include',(ROOT/OWNED[2]).parent],include_roots)
            require((ROOT/OWNED[2]).resolve() in headers,'exact typed caller header not included')
            for path in headers:protected[path]=controls[path]=sha(path)
            raw=out/'caller-raw.obj';text=run(prefix+[ROOT/OWNED[3],'/Fo'+str(raw)],'caller-compile.log')
            require(boot.includes(text,[root/'VC/include',sdk/'Include',(ROOT/OWNED[2]).parent],include_roots)==headers,'actual include closure changed')
            generated[raw]=sha(raw);caller_obj,_,_,_=strict_object(raw)
            require(list(caller_obj.directives)==policy['caller_directives'],'caller directive contract differs')
            data,caller=bind_caller(caller_obj.data,names);bound=out/'caller.obj'
            with bound.open('xb') as target:target.write(data);target.flush();os.fsync(target.fileno())
            generated[bound]=sha(bound);independent=independent_caller(raw,bound,caller)
            member=PROJECT/(RECIPE+'.obj.stage');archive=PROJECT/'union-reference-0000.lib'
            # No default library can satisfy one of the exact canonical Game names.
            for name,binding in libraries.items():
                library=Path(binding['path']);require(library.stat().st_size<=32*1024*1024,'bounded library exceeded')
                payload=library.read_bytes();require(all(n.encode() not in payload for n in names.values()),'Game alias occurs in a normal CRT/SDK library')
            all_libraries=dict(libraries);all_libraries[archive.name]=boot.file_identity(archive)
            evidence={n:boot.ArchiveEvidence(b) for n,b in all_libraries.items()}
            layouts={};all_apis=set()
            for variant,base,order in [('normal',0x400000,[bound,archive]),('moved',0x680000,[archive,bound])]:
                check();require(boot.controlled_libraries(out,root/'VC/lib',sdk/'Lib')==libraries,'library search shadow changed')
                report['native_link_attempted']=True
                exe=out/(variant+'.exe');mp=out/(variant+'.map')
                linked=run([root/'VC/bin/link.exe']+LINK+['/base:'+hex(base),'/out:'+str(exe),'/map:'+str(mp)]+order,variant+'-link.log')
                generated[exe]=sha(exe);generated[mp]=sha(mp)
                searches=boot.verify_library_log(linked,all_libraries)
                require(boot.controlled_libraries(out,root/'VC/lib',sdk/'Lib')==libraries,'library search changed during link')
                table=boot.map_symbols(mp.read_text());contributors=boot.validate_contributors(table,[bound],all_libraries,evidence)
                inspection=inspect_link(exe,mp,member,record,names,caller,contributors)
                all_apis.update(inspection['named_imports'])
                layouts[variant]=dict(executable_sha256=generated[exe],map_sha256=generated[mp],base=base,
                    library_searches=searches,map_contributors=contributors,inspection=inspection)
                note('linked',variant=variant,execution=False)
            require(all(layouts['normal']['inspection']['Game_bodies'][i]['address']!=layouts['moved']['inspection']['Game_bodies'][i]['address']
                        for i in range(3)),'selected Game roots did not move')
            osdeps,osexports=tls.os_export_identities(Path(os.environ['SystemRoot'])/'SysWOW64',sorted(all_apis))
            protected.update({Path(p):h for p,h in osdeps.items()});check()
            report.update(status='prepared-not-executed',layouts=layouts,caller_namespace=caller,independent_caller=independent,
                included_headers={str(p):sha(p) for p in headers},normal_libraries=libraries,os_export_evidence=osexports,
                original_component_recipe='SP1 /MT /O2 /GS /EHsc /Gy; exact three bodies retained without recompilation')
        except Exception as error:
            report['error']=type(error).__name__+': '+str(error);note('failed',error=report['error'])
        finally:
            try:stable(protected);stable(generated);boot.verify_include_roots(include_roots);report['input_stability_verified']=True
            except Exception as error:report.update(status='error',input_stability_verified=False,final_stability_error=str(error))
            report.update(inputs={str(p):h for p,h in protected.items()},artifacts={str(p):h for p,h in generated.items()},
                elapsed_seconds=time.monotonic()-start,include_root_identities=include_roots)
            report['partial_outputs_may_exist']=report['status']!='prepared-not-executed' and bool(commands)
            report['unverified_partial_artifacts']={p.name:sha(p) for p in out.iterdir() if p.is_file()
                and p not in generated and p.name!='progress.jsonl'}
            note('final-status',status=report['status']);report['progress_sha256']=sha(out/'progress.jsonl');save(out/'prepare.json',report)
    return report


def main():
    parser=argparse.ArgumentParser(__doc__)
    for key in ('policy','source-review','projection-review','doctor','out'):parser.add_argument('--'+key,type=Path,required=True)
    for key in ('policy','source-review','projection-review','doctor'):parser.add_argument('--'+key+'-sha256',required=True)
    parser.add_argument('--allow-native-prepare',action='store_true')
    result=prepare(parser.parse_args());print(result['status']);raise SystemExit(result['status']!='prepared-not-executed')


if __name__=='__main__':main()
