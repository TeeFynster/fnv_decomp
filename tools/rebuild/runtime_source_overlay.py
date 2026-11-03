"""One fixed source-only address-carrier overlay experiment; never link or run."""
from __future__ import annotations
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import struct
import subprocess
import tempfile
import toolchain
from coff_inventory import Coff
from data_plan import Pe, file_hash
from runtime_gaps import read_bound
from import_plan import ROOT, ImagePe, image_ok, require
from compare import Coff as CompareCoff, compare as plain_compare

SOURCE='src/gamebryo2.2/corelibs/nimain/nibacktofrontaccumulator.cpp'
HEADER='src/gamebryo2.2/corelibs/nimain/nibacktofrontaccumulator_decls.h'
OLD='#include "nibacktofrontaccumulator_decls.h"\r\n\r\n// @fnv 0x00aa0fc0\r\nNiBackToFrontAccumulator::NiBackToFrontAccumulator()\r\n{\r\n    *(volatile unsigned int*)this = 0x010a2304;\r\n'
NEW=OLD.replace('\r\n\r\n','\r\nextern int DAT_010a2304;\r\n',1).replace('= 0x010a2304;','= reinterpret_cast<unsigned int>(&DAT_010a2304);')
EXPECTED=dict(schema_version=1,kind='fnv-fixed-runtime-source-overlay',policy='niaccumulator-address-carrier-v1',source=SOURCE,
    source_sha256='36a0fde7e9010dca9552434cc5730d82657b2b37036ab57649ee523f842264e6',header=HEADER,
    header_sha256='623ec38f6cc3c7f25952ba20191ecccc0f9b8dad17b9b66d9e6d122c82b037ec',recipe_index=1401,
    recipe_id='1401-50cd6090ff456b83',compiler='sp1',flags=['/MT','/O2','/GS','/EHsc','/Gy'],
    function=dict(symbol='??0NiBackToFrontAccumulator@@QAE@XZ',address='0x00aa0fc0',size=25),field_offset=10,
    target='0x010a2304',target_symbol='?DAT_010a2304@@3HA',old_span=OLD,new_span=NEW,
    provider_selected=False,native_execution_authorized=False)
PINS=dict(recipes='62f2c8da5f0daa912abdf4576328706711c6561eef7f01c93a89cb71ad46fb6c',
    manifest='bc62a5fb2553431b1e0547d11f366e52efb73096ea8ceb206c556ae5740a53eb',
    retained='04d44b73e81982f846bfe8d81806db72ea669586b579ff22007dfd6f7d831297',
    selection='48ae62cdc5b1754b9c4af674ef4716d53afb554882e174a93acf860eaf1c6cb1',
    reference='df1788907c6e26ef4df0b448ead526825336356b5606650165a1ce0825097eb7')
DEFAULTS=dict(recipes=ROOT/'build/units.json',manifest=ROOT/'build/rebuild/objects-20261103T030230Z-7cfc935c.json',
    retained=ROOT/'build/rebuild/retained-verify-full-v3.json',selection=ROOT/'build/rebuild/function-selection-v2.json')
TOOLS=['tools/rebuild/runtime_source_overlay.py','tools/rebuild/toolchain.py','tools/rebuild/coff_inventory.py',
       'tools/rebuild/data_plan.py','tools/rebuild/runtime_gaps.py','tools/rebuild/import_plan.py',
       'tools/build_and_match.py','tools/compare.py','tools/function_spans.py','build/image_check.json']


def sha(data):return hashlib.sha256(data).hexdigest()


def apply_overlay(raw,policy):
    require(policy==EXPECTED,'unauthorized fixed overlay policy/recipe/target/change')
    old,new=policy['old_span'].encode(),policy['new_span'].encode()
    require(raw.count(old)==1,'missing, wrong or duplicate guarded source span')
    require(raw.count(b'*(volatile unsigned int*)this = 0x010a2304;')==1,'duplicate or comment-only statement occurrence')
    require(sha(raw)==policy['source_sha256'],'stale original source')
    result=raw.replace(old,new,1)
    require(result.count(b'\n')==raw.count(b'\n') and result.count(b'\r\n')==raw.count(b'\r\n'),'source line count/ending changed')
    require(result.replace(new,old,1)==raw,'source edits outside one guarded span')
    return result,dict(start=raw.index(old),old_length=len(old),new_length=len(new),old_sha256=sha(old),new_sha256=sha(new),line_count=raw.count(b'\n'))


def include_context(raw,header):
    text=raw.decode('utf-8');h=header.decode('utf-8')
    require(re.findall(r'(?m)^\s*#\s*include\s+(.+?)\s*$',text)==['"nibacktofrontaccumulator_decls.h"'],'source include context differs')
    require(not re.search(r'(?m)^\s*#\s*(include|define|if|pragma)',text.replace('#include "nibacktofrontaccumulator_decls.h"','')),'unexpected source preprocessor context')
    require(not re.search(r'(?m)^\s*#\s*include\b',h),'unexpected transitive include')
    require(not re.search(r'\b(__FILE__|__LINE__|__DATE__|__TIME__|__COUNTER__|__TIMESTAMP__)\b',text+h),'path/time-sensitive source macro')
    return dict(quoted_include='nibacktofrontaccumulator_decls.h',transitive_includes=0,path_time_macros_observed=False,
        observation='Exact pinned source/header; only header guard macro, no nested includes or path/time-sensitive macros.')


def selected_bytes(coff):
    matches=[s for s in coff.symbols.values() if s['name']==EXPECTED['function']['symbol'] and s['section']>0]
    require(len(matches)==1,'constructor symbol missing/ambiguous')
    s=matches[0];sec=coff.sections[s['section']]
    require(sec['flags']&0x20000020 and 0<=s['value']<=sec['size']-25,'constructor native extent invalid')
    hdr=coff.unpack('<8sIIIIIIHHI',20+(s['section']-1)*40)
    raw=coff.take(hdr[4]+s['value'],25)
    rels=[]
    for off,idx,kind in sec['relocs']:
        if s['value']<=off<s['value']+25:
            require(off+4<=s['value']+25,'straddling constructor relocation')
            t=coff.symbols[idx]
            rels.append(dict(offset=off-s['value'],kind=kind,symbol=t['name'],target_section=t['section'],target_value=t['value'],
                             storage=t['storage'],aux_count=t['aux_count'],addend=struct.unpack_from('<I',raw,off-s['value'])[0]))
    return raw,rels,dict(section=s['section'],value=s['value'],symbol_index=s['index'],section_size=sec['size'])


def verify_geometry(before,after):
    carrier=[s for s in after.symbols.values() if s['name']==EXPECTED['target_symbol']]
    require(len(carrier)==1 and carrier[0]['section']==0 and carrier[0]['value']==0 and
            carrier[0]['storage']==2 and carrier[0]['aux_count']==0 and carrier[0]['type']==0,
            'carrier must be exactly one undefined EXTERNAL; no definition or alternate record')
    old,oldrels,oldid=selected_bytes(before);new,newrels,newid=selected_bytes(after)
    require(struct.unpack_from('<I',old,10)[0]==0x10a2304,'original operand differs')
    require(oldrels==[dict(offset=4,kind=20,symbol='??0NiObject@@QAE@XZ',target_section=0,target_value=0,storage=2,aux_count=0,addend=0)],'original base relocation differs')
    require(len(newrels)==2 and newrels[0]==oldrels[0],'base behavior/relocation changed or extra fields')
    r=newrels[1]
    require(r==dict(offset=10,kind=6,symbol=EXPECTED['target_symbol'],target_section=0,target_value=0,storage=2,aux_count=0,addend=0),'new target reference is not exact undefined zero-addend DIR32')
    require(all(a==b for i,(a,b) in enumerate(zip(old,new)) if i not in range(10,14)),'volatile/base/member code bytes changed')
    return dict(before=oldid,after=newid,original_relocations=oldrels,overlay_relocations=newrels,
        original_operand='0x010a2304',non_field_function_bytes_equal=True,new_DIR32_field_count=1,
        compatibility='one function geometry only; undefined carrier has no runtime provider')


def require_match(rows):
    target=[r for r in rows if r['symbol']==EXPECTED['function']['symbol']]
    require(len(target)==1 and target[0]['size']==25 and target[0]['compiled_extent']==25 and target[0]['verdict']=='match','constructor plain comparison/extent failed')
    require(all(r['verdict']=='match' for r in rows),'same-TU plain comparison failed')


def generated_stability(source,obj,source_sha256,object_sha256):
    require(file_hash(source)==source_sha256 and file_hash(obj)==object_sha256,
            'generated source or compiled object changed during verification')


def save(path,value):
    with Path(path).open('x',encoding='utf-8') as f:json.dump(value,f,indent=2);f.write('\n')


def new_output(out,protected):
    out=Path(out).resolve()
    require(not out.exists() and all(out!=p and out not in p.parents for p in map(Path,protected)),'input/output collision or existing output')
    return out


def run(args):
    require(os.name=='nt','native VC9 compilation requires Windows')
    policy_path=Path(args.policy).resolve();policy=json.loads(policy_path.read_text(encoding='utf-8-sig'))
    require(policy==EXPECTED,'unsupported public policy')
    paths={n:Path(getattr(args,n)).resolve() for n in PINS}
    data={n:read_bound(paths[n],PINS[n]) for n in PINS if n!='reference'}
    require(file_hash(paths['reference'])==PINS['reference'],'reference identity differs')
    manifest,receipt,selection=(data[n] for n in ('manifest','retained','selection'))
    unit=manifest['units'][1401];recipe=data['recipes']['units'][1401]
    require(unit['recipe_id']==EXPECTED['recipe_id'] and unit['recipe']==recipe and recipe['source']==SOURCE and recipe['compiler']=='sp1' and recipe['flags']==EXPECTED['flags'],'wrong recipe/compiler/profile')
    choice=selection['selections']['0x00aa0fc0']
    require(choice==dict(recipe_id=unit['recipe_id'],recipe_index=1401,symbol=EXPECTED['function']['symbol'],section=3,value=0,size=25,selection_status='CODE_OWNERSHIP_SELECTED',runtime_eligible=False,link_ready=False),'selected owner differs')
    proof=receipt['units'][1401]
    require(proof['recipe_id']==unit['recipe_id'] and proof['object_sha256']==unit['object_sha256'] and
        dict(EXPECTED['function'],section=3,value=0,verdict='match') in proof['verified_functions'],'original matched row differs')
    obj=(paths['manifest'].parent/manifest.get('object_root_relative','.')/unit['object']).resolve()
    source,header=ROOT/SOURCE,ROOT/HEADER
    observations={paths[n]:PINS[n] for n in paths}
    observations.update({source:EXPECTED['source_sha256'],header:EXPECTED['header_sha256'],obj:unit['object_sha256'],policy_path:file_hash(policy_path)})
    for name in TOOLS:
        p=ROOT/name;observations[p]=file_hash(p)
    for name,h in receipt['inputs']['tools_sha256'].items():
        p=ROOT/name;require(file_hash(p)==h,'stale original proof tool');observations[p]=h
    require(all(file_hash(p)==h for p,h in observations.items()),'stale protected input')
    index=ROOT/'build/function_index.json';require(not index.exists() and receipt['inputs']['function_index_present'] is False,'optional index state changed')
    raw=source.read_bytes();generated,edit=apply_overlay(raw,policy);context=include_context(raw,header.read_bytes())
    doctor=Path(args.doctor).resolve();tc=json.loads(doctor.read_text())['toolchains']['sp1'];compiler_root,_=toolchain.layout(tc['root'])
    cl=compiler_root/'VC/bin/cl.exe';require(tc['ready'] and tc['version']=='15.00.30729.01' and tc['cl_sha256']==manifest['toolchains']['sp1']['cl_sha256']==file_hash(cl),'compiler identity differs')
    for p in (doctor,cl,compiler_root/'VC/bin/c1xx.dll',compiler_root/'VC/bin/c2.dll'):observations[p]=file_hash(p)
    out=new_output(args.out,observations);out.mkdir(parents=True)
    progress=out/'progress.jsonl'
    def note(event):
        with progress.open('a',encoding='utf-8') as f:f.write(json.dumps(event)+'\n');f.flush();os.fsync(f.fileno())
    note(dict(state='started',policy_sha256=observations[policy_path]))
    report=dict(schema_version=1,kind='fnv-fixed-runtime-source-overlay-result',status='error',policy_sha256=observations[policy_path],
        inputs={str(p):h for p,h in observations.items()},input_stability_verified=False,game_execution=False,link_performed=False,
        provider_selected=False,runtime_eligible=False,runtime_closure_verified=False,game_fixups_approved=0)
    try:
        src=out/source.name;target=out/'overlay.obj';log=out/'compile.log'
        with tempfile.NamedTemporaryFile(dir=out,delete=False,suffix='.cpp') as f:stage=Path(f.name);f.write(generated)
        try:
            require(stage.read_bytes()==generated,'staged source changed')
            with src.open('xb') as f:f.write(generated)
        finally:stage.unlink(missing_ok=True)
        command=[cl,'/c','/nologo']+recipe['flags']+['/I'+str(source.parent),'/I'+str(ROOT/'include'),'/showIncludes',src,'/Fo'+str(target)]
        report.update(edit=edit,generated_source_sha256=sha(generated),original_recipe_flags=recipe['flags'],
            context_adaptation_flags=['/I'+str(source.parent),'/showIncludes'],include_context=context,command=[str(x) for x in command])
        require(file_hash(src)==sha(generated),'generated source changed before compilation')
        note(dict(state='compile_started'))
        code,text=toolchain.run(command,compiler_root,ROOT,timeout=120)
        with log.open('x',encoding='utf-8') as f:f.write(text)
        report['compile_returncode']=code;require(code==0 and target.is_file(),'overlay compilation failed')
        object_sha256=file_hash(target)
        note(dict(state='compile_finished',object_sha256=object_sha256))
        includes=[Path(x.strip()).resolve() for x in re.findall(r'(?im)^Note: including file:\s*(.+)$',text)]
        require(includes==[header.resolve()],'actual compiler include origin differs')
        report['actual_includes']=[dict(source=HEADER,sha256=file_hash(p)) for p in includes]
        before,after=Coff(obj),Coff(target)
        require(sha(after.data)==object_sha256,'compiled object changed while geometry parsed')
        report['geometry']=verify_geometry(before,after)
        pe=Pe(paths['reference'])
        try:
            require(0xaa0fca-pe.base in set(pe.relocations()),'original field lost PE HIGHLOW')
            require(struct.unpack('<I',pe.read_rva(0xaa0fca-pe.base,4,allow_code=True))[0]==0x10a2304,'original field target differs')
            report['original_PE_HIGHLOW']=dict(function='0x00aa0fc0',field='0x00aa0fca',target='0x010a2304')
        finally:pe.close()
        image=ImagePe(paths['reference']);ok,hits,probes=image_ok(image);require(ok,'original image probes failed')
        comparable=CompareCoff(target);require(sha(comparable.data)==object_sha256,'compiled object changed before plain comparison')
        rows=plain_compare(comparable,image,recipe);del image
        sanitized=[{k:v for k,v in r.items() if k!='byte_differences'}|dict(byte_difference_offsets=[d['offset'] for d in r['byte_differences']]) for r in rows]
        save(out/'comparison.json',dict(kind='unchanged-plain-comparator-observation',rows=sanitized));require_match(rows)
        report.update(status='pass_pending_independent_review',overlay_object_sha256=file_hash(target),plain_comparison_rows=len(rows),
            selected_function_reaudit=dict(original_status='MISSING_COFF_RELOCATION',overlay_status='EXACT_DIR32',field_offset=10,
                symbol=EXPECTED['target_symbol'],addend=0,scope='one candidate only; original global88missing count unchanged'),image_gate=dict(hits=hits,probes=probes))
        require(not index.exists() and all(file_hash(p)==h for p,h in observations.items()),'protected input changed during overlay')
        generated_stability(src,target,sha(generated),object_sha256)
        report.update(input_stability_verified=True,original_source_unchanged=True,generated_inputs_stability_verified=True)
        report['artifacts']={str(p):file_hash(p) for p in (src,target,log,out/'comparison.json')}
        note(dict(state='verified_pending_review'))
    except (ValueError,OSError,KeyError,TypeError,struct.error,subprocess.TimeoutExpired) as error:
        report['status']='error';report['error']=str(error);note(dict(state='failed',error_type=type(error).__name__))
    save(out/'result.json',report)
    return report


def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--policy',type=Path,default=ROOT/'runtime/source-overlays/niaccumulator-address.json')
    for n,d in DEFAULTS.items():p.add_argument('--'+n,type=Path,default=d)
    for n in ('reference','doctor','out'):p.add_argument('--'+n,required=True,type=Path)
    a=p.parse_args()
    try:r=run(a)
    except (ValueError,OSError,KeyError,TypeError,struct.error,subprocess.TimeoutExpired) as error:p.exit(2,'overlay rejected: '+str(error)+'\n')
    print(r['status']);return 0 if r['status']=='pass_pending_independent_review' else 1

if __name__=='__main__':raise SystemExit(main())
