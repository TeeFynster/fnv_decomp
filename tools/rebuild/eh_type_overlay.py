"""Generate/compile two declaration-only member views; never link or execute."""
from __future__ import annotations
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import struct
import sys
import subprocess

ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'tools'))
import build_and_match as oracle
from coff_inventory import Coff as InventoryCoff, reconcile_recipes
from eh_ownership import native_pieces, physical_parent, unit_hash
from eh_parent_roles import (PINNED_MANIFEST,PINNED_RECIPE,PINNED_V3,PINNED_ORACLE,
                             parse_states,compare_content)
import toolchain

POLICY='constructor-0043fd40-two-views-v1'
SPEC=ROOT/'runtime/source-overlays/constructor-0043fd40.json'
FLAGS=['/MT','/Od','/Oy-','/GS','/EHsc','/Gy']
TOOLS=('tools/rebuild/eh_type_overlay.py','tools/rebuild/eh_parent_roles.py',
       'tools/rebuild/eh_ownership.py','tools/rebuild/coff_inventory.py',
       'tools/rebuild/toolchain.py','tools/build_and_match.py','tools/compare.py',
       'tools/function_spans.py','tools/rebuild/runtime_gaps.py')


def require(ok,message):
    if not ok:raise ValueError(message)

def sha(path):return hashlib.sha256(Path(path).read_bytes()).hexdigest()

def bound(path,expected):
    p=Path(path);require(p.stat().st_size<=64*1024*1024,'input too large')
    data=p.read_bytes();require(hashlib.sha256(data).hexdigest()==expected,'stale input fingerprint')
    return json.loads(data.decode('utf-8-sig'))

def write(path,data):
    with Path(path).open('x',encoding='utf-8') as stream:
        if isinstance(data,str):stream.write(data)
        else:json.dump(data,stream,indent=2);stream.write('\n')

def view_symbols(view):
    return ('??0'+view['type']+'@@QAE@H@Z','??1'+view['type']+'@@QAE@XZ')

def validate_spec(s):
    require(s.get('schema_version')==1 and s.get('kind')=='fnv-compile-only-eh-type-overlay' and s.get('policy')==POLICY,'unknown overlay schema')
    require((s.get('recipe_index'),s.get('recipe_id'),s.get('parent'),s.get('symbol'),s.get('size'))==(802,'0802-87f974b83dab6f45','0x0043fd40','??0FUN_0043fd40@@QAE@HH@Z',166),'fixed scope differs')
    require(s.get('source')=='src/fallout_shared/modelloader.cpp' and s.get('source_sha256')=='93fba6b335addd4607a7faff409958111f8ed989d405cb8b39f293c5275adf97','source identity differs')
    require(s.get('slice')==dict(first_line=11565,last_line=11610,normalized_sha256='8c9459e1aaf4c839b32d59c44717aa70cf8b6af369b82731a8b8377e42afb41d'),'slice differs')
    expected=[dict(member='m_30',type='Overlay0043fd40Member30',constructor_original='0x00633c90',destructor_original='0x0040c110'),dict(member='m_34',type='Overlay0043fd40Member34',constructor_original='0x00633c90',destructor_original='0x0045cec0')]
    require(s.get('views')==expected,'distinct views or targets merged/changed')
    require(all(s.get(k) is False for k in ('runtime_eligible','provider_selected','link_eligible')),'runtime promotion forbidden')
    require(set(s.get('compiler_inputs',{}))=={'VC/bin/cl.exe','VC/bin/c1xx.dll','VC/bin/c2.dll','VC/include/stddef.h','VC/include/crtdefs.h','VC/include/sal.h','VC/include/crtassem.h','VC/include/vadefs.h','VC/include/codeanalysis/sourceannotations.h'},'compiler/header scope differs')


def layouts(s,mode):
    result={'SpawnedBase':dict(size=40,align=4,members={f'unk{x:02X}':x for x in range(4,40,4)}),
            'SubObjA':dict(size=4,align=4,members={'unk00':0}),
            'SubObjB':dict(size=4,align=4,members={'unk00':0}),
            'FUN_0043fd40':dict(size=60,align=4,members={'unk04':4,'unk24':36,'m_28':40,'m_2c':44,'m_30':48,'m_34':52,'m_38':56})}
    # Preserve the source's exact mixed-case spellings.
    result['SpawnedBase']['members']={name:offset for name,offset in [('unk04',4),('unk08',8),('unk0C',12),('unk10',16),('unk14',20),('unk18',24),('unk1C',28),('unk20',32),('unk24',36)]}
    if mode=='overlay':
        for v in s['views']:result[v['type']]=dict(size=4,align=4,members={'unk00':0})
    return result


def generate(s,source,mode):
    validate_spec(s);require(mode in ('baseline','overlay'),'unknown source mode')
    require(hashlib.sha256(source.encode()).hexdigest()==s['source_sha256'] or
            hashlib.sha256(source.replace('\n','\r\n').encode()).hexdigest()==s['source_sha256'],
            'source text does not match pinned original')
    lines=source.splitlines();selected='\n'.join(lines[s['slice']['first_line']-1:s['slice']['last_line']])+'\n'
    require(hashlib.sha256(selected.encode()).hexdigest()==s['slice']['normalized_sha256'],'source anchors drifted')
    marker='// Constructs a SpawnedBase-derived object, storing a1 in m_28 and initializing the four sub-objects to 0.'
    require(selected.count(marker)==1,'constructor boundary ambiguous')
    declarations,body=selected.split(marker);body=marker+body
    require(body.count('FUN_0043fd40::FUN_0043fd40(')==1 and body.rstrip().endswith('{}'),'constructor body changed')
    if mode=='overlay':
        definitions=[]
        for view in s['views']:
            before='SubObjB '+view['member']+';';require(declarations.count(before)==1,'member anchor ambiguous')
            declarations=declarations.replace(before,view['type']+' '+view['member']+';')
            definitions.append('struct '+view['type']+' { int unk00; '+view['type']+'(int v); ~'+view['type']+'(); };\n')
        declarations=''.join(definitions)+declarations
    header='#ifndef FNV_EH_TYPE_EXPERIMENT_HPP\n#define FNV_EH_TYPE_EXPERIMENT_HPP\n'+declarations+'#endif\n'
    checks=['#include "view.hpp"','#include <stddef.h>']
    number=0
    for cls,contract in layouts(s,mode).items():
        expressions=[f'sizeof({cls}) == {contract["size"]}',f'__alignof({cls}) == {contract["align"]}']
        expressions += [f'offsetof({cls}, {member}) == {offset}' for member,offset in contract['members'].items()]
        for expr in expressions:
            checks.append(f'typedef char layout_check_{number}[({expr}) ? 1 : -1];');number+=1
    checks.append(body)
    return header,'\n'.join(checks)+'\n'


def private_output(out):
    require(not out.is_relative_to(ROOT) or out.is_relative_to(ROOT/'build/rebuild'),'generated outputs must stay private')


def prepare(spec_path,doctor_path,manifest_path,retained_path,recipe_path,out):
    spec_path,doctor_path,manifest_path,retained_path,recipe_path,out=[Path(x).resolve() for x in (spec_path,doctor_path,manifest_path,retained_path,recipe_path,out)]
    private_output(out);require(not out.exists(),'new output directory required')
    s=json.loads(spec_path.read_text());validate_spec(s)
    m=bound(manifest_path,PINNED_MANIFEST);r=bound(retained_path,PINNED_V3);recipes=bound(recipe_path,PINNED_RECIPE)
    require(reconcile_recipes(m,recipe_path)['verified'],'recipe reconciliation failed')
    u=next(x for x in m['units'] if x['recipe_index']==802);row=next(x for x in r['units'] if x['recipe_index']==802)
    require(u['recipe_id']==s['recipe_id'] and row['object_sha256']==u['object_sha256'] and row['recipe_unit_sha256']==unit_hash(u['recipe']) and u['recipe']['compiler']=='sp1' and u['recipe']['flags']==FLAGS,'unit/recipe contract differs')
    require(r['inputs']['retained_manifest_sha256']==PINNED_MANIFEST and r['inputs']['recipe_sha256']==PINNED_RECIPE and r['scope']['full_authoritative'] and all(r.get(k) is True for k in ('retained_verification_pass','function_byte_verification_pass','global_listed_eh_coverage_pass','original_oracle_parity_pass','evidence_stable')),'retained gates missing')
    doctor=json.loads(doctor_path.read_text());tc=doctor['toolchains']['sp1'];root=Path(tc['root']).resolve()
    require(tc['ready'] and tc['version']=='15.00.30729.01' and tc['cl_sha256']==s['compiler_inputs']['VC/bin/cl.exe'],'doctor compiler differs')
    source=ROOT/s['source'];obj=(manifest_path.parent/m.get('object_root_relative','.')/u['object']).resolve()
    observations={str(p):sha(p) for p in [spec_path,doctor_path,manifest_path,retained_path,recipe_path,source,obj]}
    require(observations[str(source)]==s['source_sha256'] and observations[str(obj)]==u['object_sha256'],'source/object changed')
    for name,digest in s['compiler_inputs'].items():
        p=root/name;require(sha(p)==digest,'compiler/header/backend changed');observations[str(p)]=digest
    for name,digest in r['inputs']['tools_sha256'].items():
        p=ROOT/name;require(sha(p)==digest,'original producer changed');observations[str(p)]=digest
    for name in TOOLS:observations[str(ROOT/name)]=sha(ROOT/name)
    require(sha(ROOT/'tools/build_and_match.py')==PINNED_ORACLE,'original oracle changed')
    require(not (ROOT/'build/function_index.json').exists() and r['inputs']['function_index_present'] is False,'optional index differs')
    generated={};out.mkdir(parents=True)
    for mode in ('baseline','overlay'):
        folder=out/mode;folder.mkdir();header,cpp=generate(s,source.read_text(),mode)
        for name,data in [('view.hpp',header),('view.cpp',cpp)]:
            p=folder/name;write(p,data);generated[str(p)]=sha(p)
    comparison_bindings={}
    for v in s['views']:
        ctor,dtor=view_symbols(v);comparison_bindings[ctor]=v['constructor_original'];comparison_bindings[dtor]=v['destructor_original']
    stable(observations,generated)
    report=dict(schema_version=1,kind='fnv-eh-type-overlay-prepared',policy=POLICY,status='source-only-pending-review',inputs=observations,generated=generated,compiler_root=str(root),spec=str(spec_path),manifest=str(manifest_path),retained=str(retained_path),recipes=str(recipe_path),unit_object=str(obj),comparison_bindings=comparison_bindings,layout_contracts={mode:layouts(s,mode) for mode in ('baseline','overlay')},runtime_eligible=False,provider_selected=False,link_eligible=False,compile_performed=False,provenance_scope='hash-bound observed source slice; no cryptographic historical compiler causality proof')
    write(out/'prepare.json',report);return report


def stable(inputs,generated):
    require(not (ROOT/'build/function_index.json').exists(),'optional index appeared')
    require(all(sha(p)==h for p,h in {**inputs,**generated}.items()),'prepared input/generated output drift')


def validate_review(prepared,review,digest):
    require(prepared.get('schema_version')==1 and prepared.get('kind')=='fnv-eh-type-overlay-prepared' and prepared.get('policy')==POLICY and prepared.get('compile_performed') is False and prepared.get('status')=='source-only-pending-review' and all(prepared.get(k) is False for k in ('runtime_eligible','provider_selected','link_eligible')),'unknown preparation schema')
    require(review.get('schema_version')==1 and review.get('kind')=='fnv-eh-type-overlay-source-review' and review.get('prepare_sha256')==digest and review.get('approved') is True and bool(review.get('reviewer')),'source review missing/stale')
    require(review.get('generated')==prepared.get('generated'),'review source outputs differ')
    require(all(review.get('checks',{}).get(k) is True for k in ('source_slice','declaration_only_views','layout_checks','comparison_only_bindings','compile_only_runner')),'review checks incomplete')


def parse_layout(log,contracts):
    headers=list(re.finditer(r'(?m)^\s*(?:class|struct)\s+(\w+)\s+size\((\d+)\):',log));found={}
    for i,h in enumerate(headers):
        name=h[1]
        if name not in contracts:continue
        require(name not in found,'duplicate layout report')
        end=headers[i+1].start() if i+1<len(headers) else len(log);block=log[h.start():end]
        require(int(h[2])==contracts[name]['size'],'compiler class size differs')
        found[name]=dict(size=int(h[2]),layout_diagnostic_sha256=hashlib.sha256(block.encode()).hexdigest())
        if name=='SpawnedBase':require(re.search(r'(?m)^\s*0\s*\|.*\{vfptr\}',block),'base vptr prefix not observed')
        if name=='FUN_0043fd40':
            heading=re.search(r'(?m)^\s*(?:(\d+)\s*)?\|\s*\+--- \(base class SpawnedBase\)\s*$',block)
            require(heading is not None,'base heading not observed')
            if heading[1] is not None:require(int(heading[1])==0,'base displacement differs')
            else:
                tail=block[heading.end():];closing=re.search(r'(?m)^\s*\|\s*\+---\s*$',tail)
                require(closing is not None,'base subsection is incomplete')
                nested=tail[:closing.start()]
                require(re.search(r'(?m)^\s*0\s*\|\s*\|\s*\{vfptr\}\s*$',nested) and
                        re.search(r'(?m)^\s*4\s*\|\s*\|\s*unk04\s*$',nested) and
                        re.search(r'(?m)^\s*36\s*\|\s*\|\s*unk24\s*$',nested),
                        'unnumbered base subsection does not prove zero displacement')
    require(set(found)==set(contracts),'complete class layout diagnostics missing')
    return dict(types=found,compile_time_size_alignment_all_member_checks=True,
        storage_intervals=dict(base_vptr=[0,4],base_fields=[4,40],parent_base=[0,40],parent_fields=[[40,44],[44,48],[48,52],[52,56],[56,60]]),
        padding=dict(base_internal=0,base_tail=0,parent_internal=0,parent_tail=0,member_internal=0,member_tail=0),scope='compiler layout and compile-time assertions; no original C++ type identity')


def includes(log,prepared,folder):
    allowed={str(Path(p).resolve()).lower() for p in prepared['inputs'] if p.lower().endswith('.h')}
    allowed.add(str((folder/'view.hpp').resolve()).lower());seen=[]
    for line in log.splitlines():
        if 'including file:' not in line.lower():continue
        markers=list(re.finditer(r'Note: including file:',line,re.IGNORECASE))
        require(len(markers)==1,'malformed/multiple include markers')
        path=line[markers[0].end():].strip()
        require(path and Path(path).is_absolute() and str(Path(path).resolve()).lower() in allowed,'unreviewed include dependency')
        seen.append(str(Path(path).resolve()))
    require(str((folder/'view.hpp').resolve()).lower() in {p.lower() for p in seen},'include provenance missing')
    return sorted(set(seen))


def analyze(path,s,original_unit,pe,all_recipes,mode):
    c=oracle.Coff(path);inventory=InventoryCoff(path);recipe=json.loads(json.dumps(original_unit))
    recipe['functions']=[f for f in recipe['functions'] if f['address']==s['parent'] and f['symbol']==s['symbol']]
    require(len(recipe['functions'])==1,'parent missing')
    if mode=='overlay':
        for v in s['views']:
            ctor,dtor=view_symbols(v);recipe['symbols'][ctor]=v['constructor_original'];recipe['symbols'][dtor]=v['destructor_original']
    names=oracle.recipe_names(all_recipes)
    ordinary=oracle.compare(c,pe,recipe,None);require(len(ordinary)==1 and ordinary[0]['verdict']=='match','ordinary166-byte comparison failed')
    pieces,inferred,errors=oracle.eh_sections(c,pe,recipe,ordinary,names)
    rr=dict(eh_sections=pieces)
    mapped=list(native_pieces(c,recipe,rr));root=c.named(s['symbol']);proof=[dict(symbol=s['symbol'],address=s['parent'],size=166,section=root['section'],value=root['value'],verdict='match')]
    require(len(mapped)==5,'extra/missing EH piece')
    info=c.named('__ehfuncinfo$'+s['symbol']);unwind=c.named('__unwindtable$'+s['symbol']);handler=c.named('__ehhandler$'+s['symbol']);xs=handler['section'];ds=info['section']
    for sn in (xs,ds):require(physical_parent(inventory,sn,proof)['section']==root['section'],'wrong parent association')
    local=[]
    for sn,a,b,piece in mapped:
        require(sn==xs and piece[3]==s['parent'],'foreign parent cleanup')
        local.append(dict(section=sn,native_start=a,native_end=b,parent=s['parent'],original_start=piece[0],original_end=piece[1],receipt_match=piece[2]))
    hp=next(p for p in local if p['native_start']==handler['value'])
    anchors=[(off,i,k) for off,i,k in c.sections[xs]['relocs'] if c.symbols[i]['name']==info['name']]
    require(len(anchors)==1 and anchors[0][2]==6,'handler anchor differs')
    off,index,_=anchors[0];observed=struct.unpack('<I',pe.read(hp['original_start']+off-handler['value'],4))[0];addend=struct.unpack_from('<I',c.sections[xs]['data'],off)[0];base=observed-info['value']-addend
    metadata=c.sections[ds];original=pe.read(base,len(metadata['data']));table=compare_content(metadata['data'],original,metadata['relocs']);require(table['nonrelocation_match'],'metadata content differs')
    states=parse_states(c,ds,info,unwind,original,base,[p for p in local if p['native_start']!=handler['value']],s['parent'])
    bindings=dict(names);bindings.update({k:int(v,0) for k,v in recipe['symbols'].items()});bindings[s['symbol']]=int(s['parent'],16)
    # Accept original inference only where a fully matching local piece supplies it.
    inferred_ok={name for p in pieces if p[2] for name in p[4]}
    for name,value in inferred.items():require(name in inferred_ok,'failed-piece inference forbidden');bindings.setdefault(name,value)
    signatures=[]
    for sn in (root['section'],xs,ds):
        sec=c.sections[sn];data=sec['data'];rows=[]
        for offset,index,kind in sec['relocs']:
            require(kind in (6,20),'unreviewed relocation')
            target=c.symbols[index];add=struct.unpack_from('<i' if kind==20 else '<I',data,offset)[0]
            if sn==root['section']:at=int(s['parent'],16);localoff=offset-root['value']
            elif sn==ds:at=base;localoff=offset
            else:
                p=next(p for p in local if p['native_start']<=offset<p['native_end']);at=p['original_start'];localoff=offset-p['native_start']
            raw=pe.read(at+localoff,4);actual=(at+localoff+4+struct.unpack('<i',raw)[0])&0xffffffff if kind==20 else struct.unpack('<I',raw)[0]
            if target['name'] in bindings:expected=(bindings[target['name']]+add)&0xffffffff
            elif target['section']==ds:expected=base+target['value']+add
            else:
                choices=[p for p in local if p['section']==target['section'] and p['native_start']<=target['value']+add<p['native_end']]
                require(len(choices)==1,'unresolved local target');p=choices[0];expected=p['original_start']+target['value']+add-p['native_start']
            rows.append(dict(offset=offset,kind=kind,symbol=target['name'],expected=expected,observed=actual,match=expected==actual))
        signatures.append(dict(role='parent' if sn==root['section'] else 'eh_code' if sn==xs else 'metadata',size=len(data),flags=sec['flags'],selection=inventory.sections[sn]['selection'],payload_sha256=hashlib.sha256(data).hexdigest(),relocations=rows))
    sx=[sec for sec in inventory.sections.values() if sec['name']=='.sxdata'];require(len(sx)==1 and sx[0]['size']==4,'unexpected handler registry')
    raw=c.sections[sx[0]['index']]['data'];require(struct.unpack('<I',raw)[0]==next(i for i,x in c.symbols.items() if x==handler),'wrong handler index')
    require(inventory.directives==['/DEFAULTLIB:"LIBCMT"','/DEFAULTLIB:"OLDNAMES"'],'unknown compiler directives')
    runtime_sections=[]
    for number,sec in inventory.sections.items():
        if sec['name'].startswith('.debug'):
            require(not sec['flags']&0x20000000,'executable debug section');continue
        require(not sec['name'].startswith(('.tls','.CRT$')),'unexpected TLS/initializer')
        content=c.sections[number]['data'];record=dict(index=number,name=sec['name'],size=sec['size'],flags=sec['flags'],selection=sec['selection'],association=sec['association'],relocations=[])
        if sec['name']=='.sxdata':record['handler_symbols']=[c.symbols[struct.unpack_from('<I',content,n)[0]]['name'] for n in range(0,len(content),4)]
        else:record['payload_sha256']=hashlib.sha256(content).hexdigest()
        for offset,index,kind in sec['relocs']:
            target=c.symbols[index];record['relocations'].append(dict(offset=offset,kind=kind,symbol=target['name'],target_section=target['section'],target_offset=target['value']))
        runtime_sections.append(record)
    definitions=sorted(x['name'] for x in c.symbols.values() if x['section']>0 and x['type']&32 and x['storage']==2)
    undef=sorted(x['name'] for x in c.symbols.values() if x['section']==0 and x['storage']==2)
    return dict(ordinary={k:ordinary[0][k] for k in ('verdict','size','compiled_extent','relocations')},pieces=pieces,diagnostics=errors,states=states,sections=signatures,runtime_sections=runtime_sections,definitions=definitions,undefined=undef,handler_offset=handler['value'],runtime_eligible=False,provider_selected=False,link_eligible=False)


def validate_improvement(before,after,s):
    require(before['ordinary']['verdict']==after['ordinary']['verdict']=='match' and before['ordinary']['size']==after['ordinary']['size']==166 and before['ordinary']['compiled_extent']==after['ordinary']['compiled_extent']==166,'ordinary size/extent drift')
    normalize=lambda p:[(x[0],x[1],x[3]) for x in p]
    require(normalize(before['pieces'])==normalize(after['pieces']),'EH placement/extent changed')
    require(before['states']==after['states'] and before['handler_offset']==after['handler_offset']==41,'state/handler graph changed')
    require(before['states']['state_count']==4,'state count changed')
    require([p[2] for p in before['pieces']]==[True,False,False,False,True] and [p[2] for p in after['pieces']]==[True,False,True,True,True],'targeted failure set differs')
    require(len(before['diagnostics'])==3 and len(after['diagnostics'])==1 and 'SubObjA' in after['diagnostics'][0] and after['diagnostics'][0] in before['diagnostics'],'SubObjA failure changed/hidden')
    renames={'??0SubObjB@@QAE@H@Z':{view_symbols(v)[0] for v in s['views']},'??1SubObjB@@QAE@XZ':{view_symbols(v)[1] for v in s['views']}}
    def canonical(name):return next((old for old,new in renames.items() if name in new),name)
    require(before['definitions']==after['definitions'],'extra code definition/adapter')
    runtime_after=json.loads(json.dumps(after['runtime_sections']))
    for section in runtime_after:
        for relocation in section['relocations']:relocation['symbol']=canonical(relocation['symbol'])
    require(before['runtime_sections']==runtime_after,'extra runtime section/reference or payload changed')
    require(set(before['undefined'])=={canonical(n) for n in after['undefined']},'extra undefined references')
    require(len(before['sections'])==len(after['sections'])==3,'missing/extra selected section')
    changed=[];ctor_symbols=[]
    for a,b in zip(before['sections'],after['sections']):
        require(all(a[k]==b[k] for k in ('role','size','flags','selection','payload_sha256')),'native section payload/policy drift')
        require(len(a['relocations'])==len(b['relocations']),'extra relocation')
        for x,y in zip(a['relocations'],b['relocations']):
            require((x['offset'],x['kind'],x['observed'],x['symbol'])==(y['offset'],y['kind'],y['observed'],canonical(y['symbol'])),'reference shape changed')
            if x['symbol']=='??0SubObjB@@QAE@H@Z':ctor_symbols.append(y['symbol'])
            if x['symbol']=='??1SubObjB@@QAE@XZ':
                wanted=next((view_symbols(v)[1] for n,v in enumerate(s['views']) if y['offset']==[26,37][n]),None)
                require(y['symbol']==wanted,'distinct destructor role identity merged')
            if x['expected']!=y['expected']:
                require(a['role']=='eh_code' and x['symbol']=='??1SubObjB@@QAE@XZ' and not x['match'] and y['match'],'unapproved comparison target change')
                changed.append(y['offset'])
            else:require(x['match']==y['match'],'unapproved verdict change')
    require(changed==[26,37] and ctor_symbols==[view_symbols(v)[0] for v in s['views']],'two precise constructor/cleanup identities not preserved')


def compile_only(prepared_path,review_path,review_sha256,image_path,out):
    prepared_path,review_path,image_path,out=[Path(p).resolve() for p in (prepared_path,review_path,image_path,out)]
    private_output(out);require(os.name=='nt' and not out.exists(),'new native compile output required')
    require(sha(review_path)==review_sha256,'review fingerprint differs')
    p=json.loads(prepared_path.read_text());review=json.loads(review_path.read_text());validate_review(p,review,sha(prepared_path));stable(p['inputs'],p['generated'])
    spec=json.loads(Path(p['spec']).read_text());validate_spec(spec)
    require(p['layout_contracts']=={mode:layouts(spec,mode) for mode in ('baseline','overlay')},'prepared layout contract drift')
    receipt=bound(p['retained'],PINNED_V3)
    require(sha(image_path)==receipt['inputs']['image_sha256'],'reference fingerprint differs')
    require(str(image_path) not in {str(out)},'input/output collision')
    pe=oracle.Pe(image_path);require(hashlib.sha256(pe.data).hexdigest()==receipt['inputs']['image_sha256'] and oracle.image_ok(pe)[0],'image gate failed')
    expected_generated={str((prepared_path.parent/mode/name).resolve()) for mode in ('baseline','overlay') for name in ('view.cpp','view.hpp')}
    require(set(p['generated'])==expected_generated,'generated source identity/context differs')
    root=Path(p['compiler_root']);cl=root/'VC/bin/cl.exe'
    require(all(sha(root/name)==digest for name,digest in spec['compiler_inputs'].items()),'compiler/header/backend drift')
    m=bound(p['manifest'],PINNED_MANIFEST);recipes=bound(p['recipes'],PINNED_RECIPE)['units'];unit=next(u['recipe'] for u in m['units'] if u['recipe_index']==802)
    out.mkdir(parents=True);report=dict(schema_version=1,kind='fnv-eh-type-overlay-compile',policy=POLICY,status='error',prepare_sha256=sha(prepared_path),review_sha256=review_sha256,image_sha256=sha(image_path),modes={},runtime_eligible=False,provider_selected=False,link_eligible=False,link_performed=False,native_execution_performed=False)
    try:
        for mode in ('baseline','overlay'):
            stable(p['inputs'],p['generated']);folder=out/mode;folder.mkdir();source=prepared_path.parent/mode/'view.cpp';obj=folder/'view.obj'
            command=[cl,'/nologo','/c']+FLAGS+['/showIncludes','/d1reportAllClassLayout',source,'/Fo'+str(obj)]
            code,log=toolchain.run(command,root,folder,timeout=120);write(folder/'compile.log',log)
            report['modes'][mode]=dict(returncode=code,command=[str(x) for x in command])
            require(code==0 and obj.is_file(),'compile failed; private log preserved')
            include_set=includes(log,p,source.parent);layout=parse_layout(log,p['layout_contracts'][mode])
            observed=analyze(obj,spec,unit,pe,recipes,mode)
            report['modes'][mode].update(object_sha256=sha(obj),compile_log_sha256=sha(folder/'compile.log'),includes=include_set,layout=layout,comparison=observed)
        validate_improvement(report['modes']['baseline']['comparison'],report['modes']['overlay']['comparison'],spec)
        stable(p['inputs'],p['generated']);require(sha(image_path)==report['image_sha256'] and sha(review_path)==review_sha256 and sha(prepared_path)==report['prepare_sha256'],'review/image changed')
        for mode in ('baseline','overlay'):
            require(sha(out/mode/'view.obj')==report['modes'][mode]['object_sha256'] and sha(out/mode/'compile.log')==report['modes'][mode]['compile_log_sha256'],'object/log drift')
        report['status']='targeted-compile-comparison-pass-with-preserved-failure';report['strict_local_eh_pass']=False
    except (ValueError,OSError,subprocess.TimeoutExpired) as error:
        report['error']=str(error) if isinstance(error,ValueError) else type(error).__name__
    write(out/'compile.json',report);return report


if __name__=='__main__':
    ap=argparse.ArgumentParser(description=__doc__);sub=ap.add_subparsers(dest='action',required=True)
    a=sub.add_parser('prepare')
    for n in ('spec','doctor','manifest','retained','recipes','out'):a.add_argument('--'+n,type=Path,required=True)
    a=sub.add_parser('compile')
    for n in ('prepared','review','review-sha256','image','out'):a.add_argument('--'+n,required=True)
    a=ap.parse_args()
    result=prepare(a.spec,a.doctor,a.manifest,a.retained,a.recipes,a.out) if a.action=='prepare' else compile_only(a.prepared,a.review,a.review_sha256,a.image,a.out)
    print(result['status']);sys.exit(1 if result['status']=='error' else 0)
