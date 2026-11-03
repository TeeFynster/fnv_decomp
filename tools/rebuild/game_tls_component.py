"""One selected game TLS getter with an original authored owner and caller.

Prepare never executes. Exact independent artifact approval is required to run.
"""
from __future__ import annotations
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import struct
import subprocess

import coff_tls_extract as extract
import tls_owner_fixture as tls
import toolchain

ROOT = Path(__file__).resolve().parents[2]
HEADER = ROOT/'runtime/probes/tls_owner_fixture.hpp'
SOURCES = [ROOT/'runtime/probes'/name for name in ('tls_owner_storage.cpp','tls_owner_callback.cpp','game_tls_probe.cpp')]
TOOLS = [Path(__file__),Path(extract.__file__),Path(tls.__file__),ROOT/'tools/rebuild/coff_rewrite.py']+tls.TOOLS
BASELINE = {
    'prepare': ('prepare.json','235b3572a0863456c747562c91dd1a21aba77112e78115345d08c1469ab9337e'),
    'review': ('independent-review.json','968c80feca21b7180c3a80640260aee4e586dd2e11ad6e16b046f6b68eb1de0a'),
    'execution': ('execution.json','3a53a9adc6b33557689c003d7013b991987e989607867c61b9c6057398780525')}
EXPECTED = dict(tls.EXPECTED,getter_calls=2304,getter_phases=9)
sha, require, save = tls.sha,tls.require,tls.save


def tls_mechanism_basis():
    records, protected = {}, {}
    for kind,(name,digest) in BASELINE.items():
        path=ROOT/'build/rebuild/tls-owner-fixture-v3'/name
        require(sha(path)==digest,'reviewed original TLS mechanism receipt changed')
        records[kind]=json.loads(path.read_text());protected[str(path.resolve())]=digest
    p,r,e=[records[key] for key in ('prepare','review','execution')]
    tls.validate_review(p,r,BASELINE['prepare'][1])
    require(e.get('kind')=='original-tls-owner-execution' and e.get('status')=='pass' and
            e['prepare_sha256']==BASELINE['prepare'][1] and e['review_sha256']==BASELINE['review'][1] and
            [v['name'] for v in e['variants']]==['normal','moved'] and all(v.get('status')=='pass' and v.get('observed')==[tls.EXPECTED,tls.DETACH] for v in e['variants']),
            'reviewed original TLS execution binding absent')
    protected.update(p['inputs']);protected.update(p['artifacts']);protected.update(p['os_dependencies'])
    tls.check_stable(protected)
    for name,digest in extract.OWNER_PINS.items():
        require(sha(ROOT/'runtime/probes'/name)==digest,'reviewed source-authored TLS owner changed')
    return protected


def ordinary_archive(data):
    require(data[:8]==b'!<arch>\n','alias exclusion requires ordinary COFF archive')
    offset=8;count=0
    while offset<len(data):
        require(offset+60<=len(data) and data[offset+58:offset+60]==b'`\n','invalid alias exclusion archive header')
        try:size=int(data[offset+48:offset+58]);name=data[offset:offset+16].decode('ascii').strip()
        except (ValueError,UnicodeError):raise ValueError('invalid alias exclusion archive metadata')
        start=offset+60;end=start+size
        require(size>=0 and end<=len(data),'truncated alias exclusion archive')
        if name not in ('/','//'):
            payload=data[start:end]
            require(len(payload)>=20,'opaque archive member')
            if payload[:4]==b'\0\0\xff\xff':
                _,_,version,machine,_,extent,_,info=struct.unpack_from('<HHHHIIHH',payload)
                require(version==0 and machine==0x14c and extent==len(payload)-20 and info & ~0x1f==0 and
                        info & 3<=2 and (info>>2)<=4 and payload[20:].endswith(b'\0') and
                        len(payload[20:].split(b'\0'))==(4 if info>>2==4 else 3),'opaque/nonstandard short import member')
            else:
                machine,sections,_,symptr,symbols,optional,_=struct.unpack_from('<HHIIIHH',payload)
                neutral_directives=(machine==0 and sections==1 and payload[20:28]==b'.drectve' and
                                    struct.unpack_from('<I',payload,56)[0]==0xa00)
                require((machine==0x14c or neutral_directives) and sections>0 and optional==0 and 20+40*sections<=len(payload) and
                        symptr>0 and symptr+18*symbols+4<=len(payload),'opaque/LTCG/nonstandard COFF member')
        count+=1;require(count<=100000,'archive metadata count exceeded')
        offset=end+(size%2)
    require(offset==len(data) and count>0,'invalid archive extent')
    return count


def alias_library_absence(libraries,inputs):
    # Deliberately stronger than a map-selected member claim. These fixed long
    # COFF names must occur contiguously in symbol/string tables or directives,
    # including weak targets reached by symbol index. Reject even unused hits.
    require(set(libraries)=={'libcmt.lib','oldnames.lib','kernel32.lib','uuid.lib'},'alias exclusion library set differs')
    evidence=[]
    for name,path in sorted(libraries.items()):
        path=Path(path).resolve();digest=inputs.get(str(path))
        require(digest is not None and path.stat().st_size<=32*1024*1024,'unbound/oversized alias exclusion library')
        data=path.read_bytes()
        require(hashlib.sha256(data).hexdigest()==digest and sha(path)==digest,'alias exclusion library changed')
        members=ordinary_archive(data)
        require(all(endpoint.encode('ascii') not in data for endpoint in extract.ALIAS_ENDPOINTS),
                'dropped alias endpoint occurs in bound library (selected or unselected)')
        evidence.append(dict(library=name,path=str(path),sha256=digest,size=len(data),archive_metadata_members=members,
            absent_endpoints=sorted(extract.ALIAS_ENDPOINTS),scope='entire exact file, including unselected members; no selected-member completeness claim'))
    return evidence


def linked_caller(pe,rows,main_object,getter_address):
    coff,_,_,_=extract.strict_object(main_object);calls=[]
    for sec in coff.sections.values():
        for offset,index,kind in sec['relocs']:
            if coff.symbols[index]['name']!=extract.PARENT:continue
            anchors=[s for s in coff.symbols.values() if s['section']==sec['index'] and s['value']==0 and s['type'] & 0x20]
            require(len(anchors)==1 and kind==20 and sec['flags'] & 0x20 and 0<=offset<=sec['size']-4,
                    'caller getter relocation has unsupported anchor/extent/kind')
            require(struct.unpack_from('<i',tls.section_payload(coff,sec['index']),offset)[0]==0,'caller getter addend differs')
            mapped=rows.get(anchors[0]['name'],[])
            require(len(mapped)==1 and mapped[0]['provider'].split()[-1].lower()=='main.obj','caller map owner ambiguous')
            field=mapped[0]['address']+offset
            section=pe.section(field-pe.base,4,required=True)
            require(section['executable'] and not section['flags'] & 0x80000000,'caller field protection differs')
            displacement=struct.unpack('<i',pe.read_rva(field-pe.base,4,allow_code=True))[0]
            require((field+4+displacement)&0xffffffff==getter_address,'linked caller REL32 does not resolve to selected getter')
            require(not any(field-pe.base-3<=site<field-pe.base+4 for site in pe.relocations()),'caller REL32 has overlapping HIGHLOW')
            calls.append(dict(function=anchors[0]['name'],offset=offset,kind=20,field=field,target=getter_address,displacement=displacement))
    require(len(calls)==1,'linked caller requires exactly one selected getter relocation')
    return calls


def inspect_getter(image,mapfile,getter,storage_alias,tls_inspection,main_object):
    rows=tls.map_rows(Path(mapfile).read_text())
    def at(name,owner):
        found=rows.get(name,[])
        require(len(found)==1 and found[0]['provider'].split()[-1].lower()==owner,'missing/duplicate/wrong component map provider: '+name)
        return found[0]['address']
    address=at(extract.PARENT,'getter.obj');field=at(extract.FIELD,'storage.obj');owner=at(tls.OWNER,'storage.obj')
    require({name for name,values in rows.items() if any(v['provider'].split()[-1].lower()=='getter.obj' for v in values)}=={extract.PARENT},'other game provider survived extraction/link')
    require(not extract.ALIAS_ENDPOINTS.intersection(rows),'dropped unrelated game alias endpoint survived link')
    require(field==owner+extract.VIEW['offset']==tls_inspection['template_start']+0x2b4,'symbolic interior view did not bind to module context field')
    alias,_,_,_=extract.strict_object(storage_alias);symbol=tls.named(alias,extract.FIELD)
    require(symbol['section']>0 and symbol['value']==0x2b0 and alias.sections[symbol['section']]['name']=='.tls$', 'field was replaced by absolute/process-VA alias')
    coff,_,_,_=extract.strict_object(getter);body=tls.section_payload(coff,2)
    pe=tls.Pe(image)
    try:
        sec=pe.section(address-pe.base,26,required=True)
        require(sec['executable'] and sec['flags'] & 0x40000000 and not sec['flags'] & 0x80000000 and address%16==0,'getter code protection/alignment differs')
        actual=pe.read_rva(address-pe.base,26,allow_code=True);sites=set(pe.relocations());mask=set();operands=[]
        expected={4:tls_inspection['index'],11:44,20:0x2b4}
        for offset,target,kind in extract.EDGES:
            value=struct.unpack_from('<I',actual,offset)[0]
            require(value==expected[offset] and (address-pe.base+offset in sites)==(offset==4),'getter DIR32/index/constant/SECREL representation differs')
            require(struct.unpack_from('<I',body,offset)[0]==0,'getter addend changed')
            mask.update(range(offset,offset+4));operands.append(dict(offset=offset,target=target,kind=kind,observed=value))
        require(all(a==b for i,(a,b) in enumerate(zip(body,actual)) if i not in mask),'linked getter nonrelocated payload changed')
        require(sorted(s for s in sites if address-pe.base-3<=s<address-pe.base+26)==[address-pe.base+4],'getter has unexpected/crossing HIGHLOW')
        require(struct.unpack('<i',pe.read_rva(field-pe.base,4))[0]==37,'authored field initializer was replaced by game initialization')
        calls=linked_caller(pe,rows,main_object,address)
        return dict(symbol=extract.PARENT,address=address,size=26,operands=operands,normalized_payload_equal=True,linked_caller=calls,
            field_template_address=field,field_module_offset=0x2b4,field_source_owner_offset=0x2b0,
            original_native_field_offset_not_retained=0x2b8,authored_initial_value=37,only_one_game_function=True,
            source_storage_alias_role='symbolic interior of one authored allocation, not process VA')
    finally:pe.close()


def prepare(doctor,manifest,selection,verification,image,out):
    doctor,out=Path(doctor).resolve(),Path(out).resolve()
    require(os.name=='nt' and not out.exists(),'new native private output directory required')
    require(not os.environ.get('LINK') and not os.environ.get('_LINK_'),'implicit linker options forbidden')
    mechanism=tls_mechanism_basis()
    basis=extract.verify_basis(manifest,selection,verification,image)
    tc=json.loads(doctor.read_text())['toolchains']['sp1'];root,sdk=toolchain.layout(tc['root'])
    cl,link,dump=[root/'VC/bin'/name for name in ('cl.exe','link.exe','dumpbin.exe')]
    require(tc['ready'] and tc['version']=='15.00.30729.01' and sha(cl)==tc['cl_sha256']==extract.CL_SHA and sha(link)==tc['link_sha256'],'fresh compiler identity differs')
    trusted=[cl,link,dump,root/'VC/bin/c1xx.dll',root/'VC/bin/c2.dll',root/'VC/lib/libcmt.lib',root/'VC/lib/oldnames.lib',sdk/'Lib/kernel32.lib',sdk/'Lib/uuid.lib',root/'VC/include/intrin.h']
    trusted += [path for path in [root/'Common7/IDE/mspdb80.dll',root/'Common7/IDE/msobj80.dll',root/'VC/bin/1033/clui.dll',
        root/'VC/redist/x86/Microsoft.VC90.CRT/msvcr90.dll',root/'VC/redist/x86/Microsoft.VC90.CRT/msvcp90.dll'] if path.is_file()]
    inputs={**mechanism,**basis['inputs'],**{str(path.resolve()):sha(path) for path in [HEADER]+SOURCES+TOOLS+trusted+[doctor]}}
    require(all(out!=path and out not in path.parents for path in map(Path,inputs)),'component output/input collision')
    crt=tls.crt_contract(root/'VC/lib/libcmt.lib');libraries=tls.controlled_libraries(out,root/'VC/lib',sdk/'Lib')
    alias_libraries=alias_library_absence(libraries,inputs)
    out.mkdir(parents=True);commands=[]
    def run(command,log):
        tls.check_stable(inputs);commands.append([str(v) for v in command])
        code,text=toolchain.run(command,root,out,timeout=120);(out/log).write_text(text,encoding='utf-8')
        require(code==0,'component build/inspection failed: '+log);tls.check_stable(inputs);return text
    tls.check_stable(inputs);_,banner=toolchain.run([cl],root,out,timeout=30);tls.check_stable(inputs)
    require(re.search(r'Version\s+15\.00\.30729\.01\b',banner),'fresh compiler version differs')
    objects,included={},{};allowed=[HEADER.parent.resolve(),(root/'VC/include').resolve(),(sdk/'Include').resolve()]
    for role,source in zip(('storage','callback','main'),SOURCES):
        objects[role]=out/('raw-storage.obj' if role=='storage' else role+'.obj')
        discovered=run([cl]+tls.COMPILE+['/Zs','/showIncludes',source],role+'-includes.log')
        headers=tls.include_paths(discovered,allowed);require(HEADER.resolve() in headers,'reviewed TLS header absent')
        snapshot={str(path):sha(path) for path in headers}
        require(all(path not in inputs or inputs[path]==digest for path,digest in snapshot.items()),'header changed during discovery')
        inputs.update(snapshot)
        compiled=run([cl]+tls.COMPILE+['/showIncludes',source,'/Fo'+str(objects[role])],role+'-compile.log')
        require(tls.include_paths(compiled,allowed)==headers,'actual included header set changed');tls.check_stable(inputs);included[role]=snapshot
        run([dump,'/headers','/symbols','/relocations',objects[role]],role+'-raw-dump.log')
    contracts=tls.source_contract(objects)
    context=out/'fresh-source-context.json'
    save(context,dict(schema_version=1,kind='game-tls-fresh-source-context',policy=extract.POLICY,view=extract.VIEW,
        compiler_version=tc['version'],compiler_sha256=sha(cl),fresh_compile_observed=True,
        sources={str(path.resolve()):sha(path) for path in [HEADER]+SOURCES},compiler_inputs=inputs,
        objects={role:dict(path=str(path),sha256=sha(path)) for role,path in objects.items()},
        scope='Observed fresh compiler commands and hashed source/headers/objects; not cryptographic compiler-causality proof.'))
    getter,alias=out/'getter.obj',out/'storage.obj';er,ar=out/'extract.json',out/'storage-view.json'
    extracted=extract.extract(manifest,selection,verification,image,context,sha(context),getter,er)
    viewed=extract.alias_storage(context,sha(context),alias,ar)
    run([dump,'/headers','/symbols','/relocations',getter],'getter-dump.log')
    run([dump,'/headers','/symbols','/relocations',alias],'storage-alias-dump.log')
    variants,all_apis=[],set()
    for name,base,order in [('normal',0x400000,[objects['main'],alias,objects['callback'],getter]),
                            ('moved',0x600000,[getter,objects['callback'],alias,objects['main']])]:
        exe,mp=out/(name+'.exe'),out/(name+'.map');extra=['/filealign:1024'] if name=='moved' else []
        require(tls.controlled_libraries(out,root/'VC/lib',sdk/'Lib')==libraries,'library search changed before link')
        require(alias_library_absence(libraries,inputs)==alias_libraries,'alias exclusion library evidence changed before link')
        linked=run([link]+tls.LINK+extra+['/base:'+hex(base),'/out:'+str(exe),'/map:'+str(mp)]+order,name+'-link.log')
        resolved=tls.verify_library_log(linked,libraries)
        require(tls.controlled_libraries(out,root/'VC/lib',sdk/'Lib')==libraries,'library search changed during link')
        require(alias_library_absence(libraries,inputs)==alias_libraries,'alias exclusion library evidence changed during link')
        inspection=tls.inspect_link(exe,mp,contracts,base)
        getter_inspection=inspect_getter(exe,mp,getter,alias,inspection,objects['main'])
        imported=run([dump,'/imports',exe],name+'-imports.log');pe=tls.Pe(exe)
        try:apis=tls.validate_imports(tls.parse_imports(pe))
        finally:pe.close()
        dlls=re.findall(r'(?im)^\s*([a-zA-Z0-9_.-]+\.dll)\s*$',imported)
        require({s.lower() for s in dlls}=={'kernel32.dll'},'unexpected component direct imports')
        provenance=tls.reviewed_crt_import_members(apis,tls.map_rows(mp.read_text()));all_apis.update(apis)
        run([dump,'/headers','/loadconfig',exe],name+'-headers.log')
        variants.append(dict(name=name,exe=str(exe),exe_sha256=sha(exe),map=str(mp),map_sha256=sha(mp),inspection=inspection,
            getter=getter_inspection,direct_imports=dlls,named_api_imports=apis,resolved_libraries=resolved,alias_library_absence=alias_libraries,reviewed_crt_api_members=provenance))
    require(variants[0]['getter']['address']!=variants[1]['getter']['address'] and
            variants[0]['inspection']['template_start']!=variants[1]['inspection']['template_start'],'getter/owner addresses did not move')
    osdeps,os_exports=tls.os_export_identities(Path(os.environ['SystemRoot'])/'SysWOW64',sorted(all_apis))
    artifacts={str(path):sha(path) for path in out.iterdir() if path.is_file()};tls.check_stable(inputs)
    require(not (ROOT/'build/function_index.json').exists(),'optional index state changed')
    report=dict(schema_version=1,kind='game-tls-component-prepared',policy=extract.POLICY,status='prepared_pending_independent_review',
        execution_performed=False,inputs=inputs,artifacts=artifacts,os_dependencies=osdeps,os_export_evidence=os_exports,
        commands=commands,included_headers=included,normal_crt=crt,source_contract=contracts,variants=variants,
        source_storage_context_sha256=sha(context),original_getter_basis=basis['comparison'],directive_policy=basis['directives'],
        extraction_sha256=sha(er),storage_view_sha256=sha(ar),extracted_reference_comparison=extracted['reference_comparison'],
        storage_view=viewed['view'],expected_main=EXPECTED,expected_detach=tls.DETACH,
        limits='One game getter with an authored synthetic TLS field, not original Game initialization, general TLS/provider adoption or startup. On-disk OS/command evidence does not prove in-memory loader state or compiler causality.')
    save(out/'prepare.json',report);return report


def validate_review(prepared,review,prepare_sha256):
    require(prepared.get('schema_version')==1 and prepared.get('kind')=='game-tls-component-prepared' and prepared.get('policy')==extract.POLICY and
        prepared.get('status')=='prepared_pending_independent_review' and prepared.get('execution_performed') is False and
        prepared.get('expected_main')==EXPECTED and prepared.get('expected_detach')==tls.DETACH,'unrecognized game TLS preparation')
    require(review.get('schema_version')==1 and review.get('kind')=='game-tls-component-review' and review.get('approved') is True and
        review.get('reviewer') and review.get('prepare_sha256')==prepare_sha256,'independent game TLS approval missing/stale')
    variants=[{k:v[k] for k in ('name','exe_sha256','map_sha256')} for v in prepared['variants']]
    require([v['name'] for v in variants]==['normal','moved'] and review.get('variants')==variants,'game TLS reviewed variants differ')
    require(len({str(Path(v[k]).resolve()) for v in prepared['variants'] for k in ('exe','map')})==4 and
        all(prepared['artifacts'].get(v[k])==v[k+'_sha256'] for v in prepared['variants'] for k in ('exe','map')),'game TLS artifact binding missing')
    require(all(review.get('checks',{}).get(k) is True for k in ('getter_source_proof','exact_directive_drop','symbolic_storage_view',
        'linked_tls_operands','caller_and_callbacks','safe_seh_crt_imports','os_export_identities','protected_artifacts')),'game TLS review checks incomplete')


def parse_result(stdout,stderr,returncode):
    require(returncode==0 and not stderr and len(stdout.splitlines())==2,'game TLS own child failed/receipt sequence differs')
    records=[json.loads(line) for line in stdout.splitlines()]
    for actual,expected in zip(records,(EXPECTED,tls.DETACH)):
        require(actual==expected and all(type(actual[k]) is type(v) for k,v in expected.items()),'game getter/TLS/caller/callback assertions failed')
    return records


def execute(prepared,review,review_sha256,receipt):
    pp,rp,out=[Path(path).resolve() for path in (prepared,review,receipt)]
    require(len({pp,rp,out})==3 and not out.exists() and sha(rp)==review_sha256,'new execution receipt and exact game TLS approval required')
    ph=sha(pp);p,r=[json.loads(path.read_text()) for path in (pp,rp)];validate_review(p,r,ph)
    protected={**p['inputs'],**p['artifacts'],**p['os_dependencies']};require(str(out) not in protected,'game TLS receipt/input collision')
    report=dict(schema_version=1,kind='game-tls-component-execution',status='error',prepare_sha256=ph,review_sha256=review_sha256,variants=[])
    def stable():return sha(pp)==ph and sha(rp)==review_sha256 and all(sha(path)==digest for path,digest in protected.items()) and not (ROOT/'build/function_index.json').exists()
    try:
        for variant in p['variants']:
            require(stable(),'reviewed game TLS input changed')
            try:child=subprocess.run([variant['exe']],cwd=pp.parent,stdin=subprocess.DEVNULL,stdout=subprocess.PIPE,stderr=subprocess.PIPE,
                    text=True,errors='replace',timeout=45,creationflags=getattr(subprocess,'CREATE_NO_WINDOW',0))
            except subprocess.TimeoutExpired:
                report['variants'].append(dict(name=variant['name'],status='timeout'));raise
            result=dict(name=variant['name'],returncode=child.returncode,stdout=child.stdout,stderr=child.stderr);report['variants'].append(result)
            require(stable(),'reviewed game TLS input changed during child');result['observed']=parse_result(child.stdout,child.stderr,child.returncode);result['status']='pass'
        report['status']='pass'
    except (ValueError,OSError,subprocess.TimeoutExpired) as error:report['error']=str(error)
    save(out,report);return report


if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__);commands=parser.add_subparsers(dest='action',required=True)
    prep=commands.add_parser('prepare')
    for name in ('doctor','manifest','selection','verification','image','out'):prep.add_argument('--'+name,type=Path,required=True)
    run=commands.add_parser('execute')
    for name in ('prepare','review','review-sha256','receipt'):run.add_argument('--'+name,required=True)
    args=parser.parse_args()
    result=prepare(args.doctor,args.manifest,args.selection,args.verification,args.image,args.out) if args.action=='prepare' else execute(args.prepare,args.review,args.review_sha256,args.receipt)
    print(result['status']);raise SystemExit(0 if result['status'] in ('pass','prepared_pending_independent_review') else 1)
