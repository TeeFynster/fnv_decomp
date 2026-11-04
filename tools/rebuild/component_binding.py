"""Physical-identity namespacing for exactly the closed scalar component.

No generic game linker, provider discovery, original-address fallback or execution.
"""
from __future__ import annotations
import argparse
import copy
import hashlib
import json
import os
from pathlib import Path
import re
import struct
import tempfile
import coff_literal_extract as extract
import game_scalar_component as scalar
import toolchain
from coff_rewrite import strict_object, hash_value
from data_plan import Pe

ROOT=Path(__file__).resolve().parents[2]
POLICY='physical-scalar-0703-v1'
CALLER_DIRECTIVES=['/DEFAULTLIB:"uuid.lib"','/DEFAULTLIB:"uuid.lib"']+extract.DEFAULTS
LIBRARIES=('uuid.lib','libcmt.lib','oldnames.lib','kernel32.lib')
CALLER_SHA256='cb29d1455d35acc69de650e34f4e82dbe852b3fa95090c9a9c7c03c5444aaf98'
sha,require,save=extract.sha,extract.require,extract.save
DEPENDENCIES=('component_binding.py','game_scalar_component.py','coff_literal_extract.py',
              'coff_rewrite.py','coff_inventory.py','data_plan.py','toolchain.py')


def _tool_inputs():
    return {str((ROOT/'tools/rebuild'/name).resolve()):sha(ROOT/'tools/rebuild'/name) for name in DEPENDENCIES}


def _stable_generated(path,expected):
    require(sha(path)==expected,'generated golden header changed during preparation')


def identity(recipe_id,object_sha256,symbol_index):
    require(isinstance(recipe_id,str) and recipe_id and hash_value(object_sha256) and type(symbol_index)is int and symbol_index>=0,'invalid physical identity')
    return dict(recipe_id=recipe_id,object_sha256=object_sha256,symbol_index=symbol_index)


def namespace_name(provider):
    require(provider==identity(**provider),'invalid provider identity')
    raw=json.dumps(provider,sort_keys=True,separators=(',',':')).encode('ascii')
    return '_fnv_component_'+hashlib.sha256(raw).hexdigest()


def _namespace(path,expected_sha256,rows,directive_contract=()):
    """Internal mechanical writer; supported game entry point is fixed prepare()."""
    coff,symptr,strptr,strlen=strict_object(path)
    require(hash_value(expected_sha256) and hashlib.sha256(coff.data).hexdigest()==expected_sha256,'stale object hash')
    require(list(coff.directives)==list(directive_contract),'exact directive contract differs')
    require(isinstance(rows,list) and 0<len(rows)<=64,'explicit bounded physical mappings required')
    result=bytearray(coff.data);additions=bytearray();seen=set();providers=set();edits=[]
    existing={s['name'] for s in coff.symbols.values()}
    for row in rows:
        index=row['symbol_index'];require(type(index)is int and index in coff.symbols and index not in seen,'missing/duplicate/conflicting physical symbol index')
        s=coff.symbols[index]
        ref=row['reference_identity'];require(ref==identity(ref['recipe_id'],expected_sha256,index),'stale physical input identity')
        require(s['name']==row['old_name'],'stale physical index/name')
        require(s['storage'] in (2,3) and s['section']>=0 and not s['aux_count'] and not(s['section']==0 and s['value']), 'unsupported symbol/aux/common/absolute binding')
        require(not s['name'].startswith(('__imp_','_imp__','@')),'IAT/compiler metadata cannot be bound')
        require(row['role'] in ('function','literal','local') and row['original_target'] is not None,'explicit role/original identity required')
        provider=row['provider'];name=namespace_name(provider)
        require(name not in existing and name not in providers,'target identity/name collision')
        require(all(row['old_name'] not in d and name not in d for d in coff.directives),'unsupported directive name reference')
        offset=symptr+index*18
        require(strlen+len(additions)<0xffffffff,'string offset overflow')
        struct.pack_into('<II',result,offset,0,strlen+len(additions));additions.extend(name.encode()+b'\0')
        seen.add(index);providers.add(name)
        edits.append(dict(row,new_name=name,name_field_offset=offset,storage=s['storage'],section=s['section'],value=s['value']))
    require(strlen+len(additions)<=0xffffffff,'string table overflow')
    struct.pack_into('<I',result,strptr,strlen+len(additions));result.extend(additions)
    _byte_check(coff.data,bytes(result),edits,strptr)
    return bytes(result),edits,strptr


def _byte_check(before,after,edits,strptr):
    allowed=set(range(strptr,strptr+4))
    for r in edits:allowed.update(range(r['name_field_offset'],r['name_field_offset']+8))
    require(len(after)>len(before) and all(a==b or i in allowed for i,(a,b) in enumerate(zip(before,after))),'payload/flag/association/relocation/addend byte changed')


def _publish(input_path,output,receipt,rows,directive_contract=()):
    inp,out,rp=[Path(p).resolve() for p in (input_path,output,receipt)]
    require(len({inp,out,rp})==3 and not out.exists() and not rp.exists(),'new distinct output paths required')
    before=extract.strict_object(inp)[0];expected=hashlib.sha256(before.data).hexdigest()
    data,edits,strptr=_namespace(inp,expected,rows,directive_contract);stage=None;created=[]
    try:
        out.parent.mkdir(parents=True,exist_ok=True)
        with tempfile.NamedTemporaryFile(dir=out.parent,suffix='.obj',delete=False) as f:stage=Path(f.name);f.write(data)
        after=extract.strict_object(stage)[0];symbols=copy.deepcopy(before.symbols)
        for r in edits:symbols[r['symbol_index']]['name']=r['new_name']
        require(after.symbols==symbols and after.sections==before.sections and after.directives==before.directives,'reparsed physical graph differs')
        require(sha(inp)==expected,'input changed during namespace operation')
        report=dict(schema_version=1,kind='physical-component-symbol-namespacing',status='pass',input_sha256=expected,
            output_sha256=hashlib.sha256(data).hexdigest(),edits=edits,
            verification=dict(non_name_original_bytes_equal=True,sections_payloads_flags_associations_equal=True,
                relocation_indices_fields_addends_equal=True,aux_records_equal=True,independent_reparse=True),execution_performed=False)
        for p,content in ((out,data),(rp,(json.dumps(report,indent=2)+'\n').encode())):
            with p.open('xb') as f:created.append(p);f.write(content)
        return report
    except BaseException:
        for p in created:p.unlink(missing_ok=True)
        raise
    finally:
        if stage:stage.unlink(missing_ok=True)

def _consistent_bindings(rows):
    observed={}
    for r in rows:
        key=namespace_name(r['provider']);fact=(r['original_target'],r['role'])
        require(key not in observed or observed[key]==fact,'conflicting physical-symbol original binding')
        observed[key]=fact


def _closed_component(coff,owners):
    require(coff.directives==extract.DEFAULTS and len(coff.sections)==4,'unowned section/directive')
    require({s['section'] for s in owners}=={2,3,4} and len(owners)==3,'incomplete component owners')
    expected_sections={1:('.drectve',47,0x00100a00,'none'),2:('.text',55,0x60501020,'no_duplicates'),
                       3:('.rdata',8,0x40401040,'any'),4:('.rdata',8,0x40401040,'any')}
    for index,sec in coff.sections.items():
        require(index in expected_sections and (sec['name'],sec['size'],sec['flags'],sec['selection'])==expected_sections[index]
                and sec['association']==0,'EH/TLS/CRT/unowned section or policy excluded')
    expected={(9,owners[2]['index'],6),(31,owners[2]['index'],6),(37,owners[1]['index'],6)}
    require(set(coff.sections[2]['relocs'])==expected and len(coff.sections[2]['relocs'])==3,'missing/conflicting scalar field')
    owned={s['index'] for s in owners}
    for s in coff.symbols.values():
        if s['index'] in owned:
            require(s['storage']==2 and s['section']>0 and not s['aux_count'] and s['value']==0,'unowned/undefined scalar owner')
        else:require('section_aux' in s or s['name'] in ('@feat.00','@comp.id'),'unowned/undefined component symbol')
    for sec in (3,4):require(coff.sections[sec]['size']==8 and not coff.sections[sec]['relocs'] and not coff.sections[sec]['flags']&0xa0000020,'unowned/pointer/mutable literal')
    require(coff.sections[2]['size']==55 and all(struct.unpack_from('<I',extract.payload(coff,2),off)[0]==0 for off in (9,31,37)),'scalar payload/addends changed')


def _component_rows(original,selected,extraction):
    source=extract.strict_object(original)[0];coff=extract.strict_object(selected)[0]
    extract.select(source)
    owners=[];rows=[]
    targets={extract.PARENT:extract.ADDRESS}
    for r in extraction['reference_comparison']['relocations']:
        require(r['match'] and r['expected']==r['observed'],'original scalar target mismatch')
        require(r['symbol'] not in targets or targets[r['symbol']]==r['expected'],'conflicting original literal identity')
        targets[r['symbol']]=r['expected']
    maps={int(k):int(v) for k,v in extraction['selection']['symbol_map'].items()}
    section_map={int(k):int(v) for k,v in extraction['selection']['section_map'].items()}
    for section,name in [(24,extract.PARENT)]+list(extract.LITERALS.items()):
        matches=[s for s in source.symbols.values() if s['section']==section and s['name']==name]
        require(len(matches)==1,'physical retained owner missing/duplicate')
        old=matches[0];index=maps[old['index']];s=coff.symbols.get(index)
        require(s and s['name']==old['name'] and s['section']==section_map[section],'stale extraction symbol map')
        owners.append(s)
        rows.append(dict(symbol_index=index,old_name=s['name'],provider=identity(extract.RECIPE_ID,extract.PINS['object'],old['index']),
            role='function' if section==24 else 'literal',original_target=targets[name],
            reference_identity=identity(POLICY+'-selected',extraction['output_sha256'],index)))
    _closed_component(coff,owners);_consistent_bindings(rows)
    return rows


def _inspect_link(exe,mapfile,component,rows,base):
    maps=scalar.map_rows(Path(mapfile).read_text());coff=extract.strict_object(component)[0]
    names={r['symbol_index']:namespace_name(r['provider']) for r in rows}
    addresses={}
    for name in names.values():
        found=maps.get(name,[])
        require(len(found)==1 and found[0]['provider'].split()[-1].lower()=='component.obj','wrong/missing physical component provider')
        addresses[name]=found[0]['address']
    require({n for n,rs in maps.items() if any(r['provider'].split()[-1].lower()=='component.obj' for r in rs)}==set(addresses),'unexpected game provider')
    pe=Pe(exe)
    try:
        require(pe.base==base and not pe.directories[9][0],'linked base/TLS differs')
        highlows=set(pe.relocations());checked=[]
        for index,name in names.items():
            sym=coff.symbols[index];sec=coff.sections[sym['section']];at=addresses[name];data=extract.payload(coff,sym['section'])
            dest=pe.section(at-base,sec['size'],required=True);code=sym['type']==32
            require(bool(dest['flags']&0x20000000)==code and bool(dest['flags']&0x20)==code and dest['flags']&0x40000000 and not dest['flags']&0x80000000,'linked component protections differ')
            require(at%(16 if code else 8)==0,'linked physical owner alignment differs')
            actual=pe.read_rva(at-base,len(data),allow_code=True);mask=set();edges=[]
            for off,target,kind in sec['relocs']:
                require(kind==6 and target in names and struct.unpack_from('<I',data,off)[0]==0,'edge escapes physical component')
                value=addresses[names[target]]
                require(struct.unpack_from('<I',actual,off)[0]==value and at-base+off in highlows,'linked field/physical target/HIGHLOW differs')
                mask.update(range(off,off+4));edges.append(dict(offset=off,target_symbol_index=target,target=names[target],linked_address=value,kind=kind,addend=0))
            require(all(a==b for i,(a,b) in enumerate(zip(data,actual)) if i not in mask),'linked payload changed')
            require(sorted(s for s in highlows if at-base-3<=s<at-base+len(data))==sorted(at-base+off for off,_,_ in sec['relocs']),'unexpected touching linked fixup')
            checked.append(dict(symbol=name,address=at,size=len(data),input_payload_sha256=sec['payload_sha256'],flags=dest['flags'],edges=edges,nonrelocated_bytes_equal=True))
        crt={}
        for name in ('_mainCRTStartup','_printf','_exit','__control87','___security_cookie','@__security_check_cookie@4'):
            rs=maps.get(name,[]);require(len(rs)==1 and 'libcmt:' in rs[0]['provider'].lower(),'normal CRT provider missing')
            crt[name]=rs[0]
        return dict(image_base=base,addresses=addresses,sections=checked,crt_providers=crt,no_tls=True,only_closed_game_component=True)
    finally:pe.close()


def _resolved_libraries(root,sdk):
    # Exact toolchain LIB search order; fresh output directory contains no libraries.
    result={}
    for name in LIBRARIES:
        candidates=[Path(root)/'VC/lib'/name,Path(sdk)/'Lib'/name]
        found=next((p.resolve() for p in candidates if p.is_file()),None)
        require(found is not None,'required exact library absent: '+name)
        result[str(found)]=sha(found)
    return result


def _library_search(text,expected):
    seen={str(Path(p).resolve()) for p in re.findall(r'(?im)^\s*Searching\s+(.+?\.lib):?\s*$',text)}
    require(seen and all(p in expected and sha(p)==expected[p] for p in seen),'unbound/changed actual linker library')
    require(any(Path(p).name.lower()=='uuid.lib' for p in seen),'actual uuid.lib search not observed')
    return {p:expected[p] for p in sorted(seen)}


def prepare(doctor,manifest,selection,verification,image,out):
    require(os.name=='nt','native preparation requires Windows')
    require(not os.environ.get('LINK') and not os.environ.get('_LINK_'),'implicit linker options forbidden')
    basis=extract.verify_basis(manifest,selection,verification,image)
    doctor,out=Path(doctor).resolve(),Path(out).resolve();tc=json.loads(doctor.read_text())['toolchains']['sp1']
    root,sdk=toolchain.layout(tc['root']);cl,link,dump=[root/'VC/bin'/n for n in ('cl.exe','link.exe','dumpbin.exe')]
    require(tc['ready'] and tc['version']=='15.00.30729.01' and sha(cl)==tc['cl_sha256'] and sha(link)==tc['link_sha256'],'SP1 tool identity differs')
    require(sha(scalar.SOURCE)==CALLER_SHA256,'original scalar caller source changed')
    inputs=dict(basis['inputs'])
    inputs.update(_tool_inputs())
    library_inputs=_resolved_libraries(root,sdk);inputs.update(library_inputs)
    paths=[scalar.SOURCE,
        doctor,cl,link,dump,root/'VC/bin/c1xx.dll',root/'VC/bin/c2.dll',root/'VC/lib/libcmt.lib',root/'VC/lib/oldnames.lib',sdk/'Lib/kernel32.lib',root/'VC/include/float.h']
    inputs.update({str(p.resolve()):sha(p) for p in paths})
    require(not out.exists() and all(out!=Path(p) and out not in Path(p).parents for p in inputs),'new private output/input collision')
    out.mkdir(parents=True)
    def note(value):
        with (out/'progress.jsonl').open('a',encoding='utf-8') as f:f.write(json.dumps(value)+'\n');f.flush();os.fsync(f.fileno())
    note(dict(state='started',policy=POLICY));commands=[]
    def run(command,log):
        commands.append([str(x) for x in command]);note(dict(state='command_started',log=log))
        code,text=toolchain.run(command,root,out,timeout=120)
        with (out/log).open('x',encoding='utf-8') as f:f.write(text)
        require(code==0,'native preparation failed: '+log);note(dict(state='command_finished',log=log));return text
    try:
        selected,erpath=out/'selected.obj',out/'extraction.json'
        er=extract.extract(manifest,selection,verification,image,selected,erpath)
        rows=_component_rows(basis['object'],selected,er)
        component=out/'component.obj';bound=_publish(selected,component,out/'component-binding.json',rows,extract.DEFAULTS)
        cases=scalar.golden_cases();header=out/'scalar_goldens.hpp'
        golden_bytes=scalar.golden_header(cases).encode('ascii')
        with header.open('xb') as f:f.write(golden_bytes)
        golden_sha256=hashlib.sha256(golden_bytes).hexdigest()
        _stable_generated(header,golden_sha256)
        caller=out/'caller-original.obj';run([cl]+scalar.COMPILE+['/I'+str(out),scalar.SOURCE,'/Fo'+str(caller)],'caller-compile.log')
        _stable_generated(header,golden_sha256)
        original_caller_hash=sha(caller);c=extract.strict_object(caller)[0]
        found=[s for s in c.symbols.values() if s['name']==extract.PARENT]
        require(len(found)==1 and found[0]['section']==0 and found[0]['value']==0 and found[0]['storage']==2 and not found[0]['aux_count'] and found[0]['type']==32,'caller intended undefined symbol differs')
        ref=found[0];caller_rows=[dict(symbol_index=ref['index'],old_name=ref['name'],provider=rows[0]['provider'],role='function',original_target=extract.ADDRESS,
            reference_identity=identity('original-game-scalar-probe',original_caller_hash,ref['index']))]
        _consistent_bindings(rows+caller_rows)
        bound_caller=out/'caller.obj';caller_bound=_publish(caller,bound_caller,out/'caller-binding.json',caller_rows,CALLER_DIRECTIVES)
        # Use unchanged oracle with explicit new symbolic identities and old original targets.
        names={r['old_name']:namespace_name(r['provider']) for r in rows}
        comparison=extract.oracle.compare(extract.oracle.Coff(component),extract.oracle.Pe(image),
            dict(functions=[dict(extract.SPEC,symbol=names[extract.PARENT])],symbols={names[r['old_name']]:r['original_target'] for r in rows}))[0]
        require(comparison['verdict']=='match' and comparison['compiled_extent']==55 and not comparison['errors'] and not comparison['byte_differences'],'namespaced unchanged reference comparison failed')
        save(out/'comparison.json',{k:v for k,v in comparison.items() if k!='byte_differences'})
        run([dump,'/headers','/symbols','/relocations',component],'component-dump.log')
        variants=[]
        for label,base,objs in [('normal',0x500000,[bound_caller,component]),('moved',0x700000,[component,bound_caller])]:
            exe,mp=out/(label+'.exe'),out/(label+'.map');extra=['/filealign:1024'] if label=='moved' else []
            link_log=run([link]+scalar.LINK+['/VERBOSE:LIB']+extra+['/base:'+hex(base),'/out:'+str(exe),'/map:'+str(mp)]+objs,label+'-link.log')
            actual_libraries=_library_search(link_log,library_inputs)
            inspection=_inspect_link(exe,mp,component,rows,base)
            imports=run([dump,'/imports',exe],label+'-imports.log');dlls=re.findall(r'(?im)^\s*([a-zA-Z0-9_.-]+\.dll)\s*$',imports)
            require({n.lower() for n in dlls}=={'kernel32.dll'},'unexpected direct imports')
            variants.append(dict(name=label,exe=str(exe),exe_sha256=sha(exe),map=str(mp),map_sha256=sha(mp),inspection=inspection,direct_imports=dlls,actual_linker_libraries=actual_libraries))
        a,b=[v['inspection'] for v in variants]
        require(all(a['addresses'][n]!=b['addresses'][n] for n in a['addresses']) and any(a['addresses'][n]-a['image_base']!=b['addresses'][n]-b['image_base'] for n in a['addresses']),'linked physical layout did not change')
        require(sha(selected)==er['output_sha256'] and sha(component)==bound['output_sha256'] and sha(caller)==original_caller_hash and sha(bound_caller)==caller_bound['output_sha256'] and
            all(sha(v[k])==v[k+'_sha256'] for v in variants for k in ('exe','map')) and
            all(sha(p)==h for p,h in inputs.items()) and not (ROOT/'build/function_index.json').exists(),'input/generated evidence changed during preparation')
        _stable_generated(header,golden_sha256)
        sysdir=Path(os.environ['SystemRoot'])/'SysWOW64';osdeps={str(sysdir/n):sha(sysdir/n) for n in ('kernel32.dll','KernelBase.dll','ntdll.dll')}
        artifacts={str(p):sha(p) for p in out.iterdir() if p.is_file() and p.name!='progress.jsonl'}
        note(dict(state='prepared_pending_review'))
        result=dict(schema_version=1,kind='physical-scalar-component-prepared',policy=POLICY,status='prepared_pending_independent_review',
            execution_performed=False,execution_authorized=False,inputs=inputs,artifacts=artifacts,os_dependencies=osdeps,commands=commands,
            physical_bindings=rows,caller_binding=caller_rows,variants=variants,expected_result=scalar.EXPECTED,golden_cases=cases,
            generated_golden_sha256=golden_sha256,
            source_proof=er,namespace_verification=bound['verification'],reference_comparison={k:v for k,v in comparison.items() if k!='byte_differences'},
            runtime_scope='one closed scalar function and its two exact source literal owners only',general_game_relink_approved=False,
            original_missing_field_count_unchanged=88,provenance='Observed hashes and commands; not compiler causality or full transitive OS loader proof.')
        save(out/'prepare.json',result);return result
    except BaseException as error:
        note(dict(state='failed',error_type=type(error).__name__));raise


def main():
    p=argparse.ArgumentParser(description=__doc__)
    for n in ('doctor','manifest','selection','verification','image','out'):p.add_argument('--'+n,required=True,type=Path)
    a=p.parse_args();r=prepare(a.doctor,a.manifest,a.selection,a.verification,a.image,a.out);print(r['status'])

if __name__=='__main__':main()
