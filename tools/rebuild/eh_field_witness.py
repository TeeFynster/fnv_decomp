"""Exact generated-handler CRT field witness; metadata proof, never a provider."""
from __future__ import annotations
import hashlib
import json
import struct
from eh_code_closure import require,section_aux,digest

FAMILY='EH_HANDLER_REL32_CRT_FIELD_V1'
AUDIT_SHA256='de1a169ae78a18f7f8c84bb327dfcc98414eb1dbba41b1d7a8f79531380ed50a'
RESOLVERS=[dict(recipe_index=i,source=source,kind='explicit-symbol-map',original_base='0x00ec3d33') for i,source in
    ((130,'src/bsshader/bsshadermanager.cpp'),(141,'src/bsshader/bsshaderproperty.cpp'),(368,'src/fallout/ai/lowprocess.cpp'),(853,'src/fallout_shared/pathfinding/navmeshrender.cpp'))]
NAME='___CxxFrameHandler3'


def resolver_records(recipes):
    rows=[]
    for index,recipe in enumerate(recipes):
        if NAME in recipe.get('symbols',{}):rows.append(dict(recipe_index=index,source=recipe['source'],kind='explicit-symbol-map',original_base=recipe['symbols'][NAME]))
        for fn in recipe['functions']:
            require(NAME not in [fn['symbol']]+fn.get('fold_aliases',[]),'unexpected handler function/fold resolver')
    require(rows==RESOLVERS,'missing/changed/conflicting/additional exact handler resolver records')
    return rows


def match_range(native,original,relocs):
    require(len(native)==len(original),'incomplete original extent')
    covered=set()
    for offset,_,kind in relocs:
        require(kind in (6,20) and 0<=offset<=len(native)-4,'unsupported field extent/kind')
        field=set(range(offset,offset+4));require(not covered&field,'overlapping handler fields');covered|=field
    require(all(a==b for i,(a,b) in enumerate(zip(native,original)) if i not in covered),'handler/state nonfield mismatch')


def exact_highlows(original_sites,base,size,expected_offsets):
    touching=[site for site in original_sites if site<base+size and site+4>base]
    require(all(base<=site and site+4<=base+size for site in touching),'partial original HIGHLOW field')
    require(sorted(touching)==[base+off for off in expected_offsets],'missing/extra/asymmetric original HIGHLOW field')


def build(obj,reference,context):
    """Caller authenticates object/reference/recipe/audit identities before/after."""
    proof=context['parent_proof'];parent='0x00440540'
    require(all(proof.get(k)==v for k,v in dict(address=parent,symbol='??0IOTask@@QAE@W4IO_TASK_PRIORITY@@@Z',size=101,section=3,value=0,verdict='match').items()),'wrong/unmatched witness parent')
    pieces=context['pieces'];require(len(pieces)==2 and all(p[2]is True and p[3]==parent for p in pieces),'false/missing/foreign handler pieces')
    require([(p[0],p[1]) for p in pieces]==[(0xeec240,0xeec248),(0xeec248,0xeec263)],'handler piece extent differs')
    s=obj['symbols'];sections=obj['sections']
    for sn in (4,6):
        _,aux=section_aux(obj,sn);require(aux[4:6]==(3,5),'foreign handler/state association')
    require(s[19]['name']=='__ehhandler$'+proof['symbol'] and (s[19]['section'],s[19]['value'],s[19]['type'],s[19]['storage'],s[19]['aux_count'])==(4,8,32,3,0),'wrong handler physical record')
    target=s[20];require((target['name'],target['section'],target['value'],target['type'],target['storage'],target['aux_count'])==(NAME,0,0,32,2,0),'wrong/nonfunction/auxiliary CRT target')
    require(sections[4]['size']==35 and sections[4]['relocs']==[(4,9,20),(21,21,20),(26,24,6),(31,20,20)],'changed/additional handler fields')
    require(sections[6]['size']==44 and sections[6]['relocs']==[(4,12,6),(16,25,6)],'changed/additional state fields')
    require(struct.unpack('<11I',sections[6]['payload'])==(0xffffffff,0,0x19930522,1,0,0,0,0,0,0,1),'changed state transitions')
    require(context['recipe'].get('symbols',{}).get(NAME) is None,'unexpected fabricated own recipe resolver')
    records=resolver_records(context['recipes'])
    native=sections[4]['payload'][8:35];base=pieces[1][0];original=reference.read(base,27)
    relocs=[(offset-8,index,kind) for offset,index,kind in sections[4]['relocs'] if offset>=8]
    match_range(native,original,relocs)
    highlows=context['original_highlow_sites'];exact_highlows(highlows,base,27,[18])
    bindings=dict(context['names']);bindings.update({name:int(value,0) for name,value in context['recipe'].get('symbols',{}).items()});bindings.update(context['inferred'])
    require(bindings.get(NAME)==0xec3d33,'unique recipe handler identity differs')
    fields=[];metadata_base=None
    for offset,index,kind in relocs:
        target=s[index];addend=struct.unpack_from('<i' if kind==20 else '<I',native,offset)[0]
        actual=(base+offset+4+struct.unpack_from('<i',original,offset)[0])&0xffffffff if kind==20 else struct.unpack_from('<I',original,offset)[0]
        if index==24:
            require((target['section'],target['value'],target['type'],target['storage'],target['aux_count'])==(6,8,0,3,0),'wrong FuncInfo record')
            metadata_base=(actual-addend-8)&0xffffffff;resolved=metadata_base+8
        else:
            if index==21:require((target['name'],target['section'],target['value'],target['type'],target['storage'],target['aux_count'])==('@__security_check_cookie@4',0,0,32,2,0),'wrong cookie-check target')
            require(target['name'] in bindings,'unresolved additional handler field')
            resolved=bindings[target['name']]
        require((resolved+addend)&0xffffffff==actual,'handler original relocation mismatch')
        fields.append(dict(section=4,offset=offset+8,piece_offset=offset,target_index=index,kind=kind,source_addend=addend,original_field_va=base+offset,original_target=actual,original_base=resolved))
    require(native[22]==original[22]==0xe9,'handler field is not the exact tail-jump form')
    audit=context['audit'];require(audit['inputs']['object_sha256']==context['object_sha256'] and audit['inputs']['reference_sha256']==context['reference_sha256'] and audit['inputs']['recipes_sha256']==context['recipes_sha256'],'audit input identities differ')
    require(audit['resolver']['records']==records and audit['resolver']['own_recipe_explicit_mapping']is None,'audit resolver mismatch')
    own=next(field for field in fields if field['target_index']==20)
    require(own['original_base']==audit['field']['resolved_original_symbol_base']==0xec3d33 and own['source_addend']==audit['field']['source_addend']==0,'handler/audit target or addend differs')
    require(reference.read(own['original_target'],1)[0]==audit['field']['original_target_first_byte'],'changed target-entry observation')
    executable=context['target_section']
    require(executable['executable']is True and executable['original_base']<=own['original_target']<executable['original_end'],'handler target outside executable mapped extent')
    metadata=sections[6]['payload'];original_metadata=reference.read(metadata_base,44)
    match_range(metadata,original_metadata,sections[6]['relocs']);exact_highlows(highlows,metadata_base,44,[4,16])
    require((s[12]['section'],s[12]['value'],s[12]['storage'],s[12]['type'],s[12]['aux_count'])==(4,0,3,32,0),'wrong cleanup symbol')
    require((s[25]['section'],s[25]['value'],s[25]['storage'],s[25]['type'],s[25]['aux_count'])==(6,0,3,0,0),'wrong unwind-map symbol')
    for offset,index,kind in sections[6]['relocs']:
        addend=struct.unpack_from('<I',metadata,offset)[0];actual=struct.unpack_from('<I',original_metadata,offset)[0]
        expected=(pieces[0][0] if index==12 else metadata_base)+addend
        require(actual==expected,'state relocation target mismatch')
    return dict(family=FAMILY,parent=parent,object_sha256=context['object_sha256'],reference_sha256=context['reference_sha256'],recipes_sha256=context['recipes_sha256'],audit_sha256=AUDIT_SHA256,
        handler=dict(section=4,symbol_index=19,value=8,size=27,original_start=base,original_end=base+27,nonfield_differences=0),fields=fields,
        original_highlow_offsets=[18],metadata=dict(section=6,size=44,original_base=metadata_base,nonfield_differences=0,original_highlow_offsets=[4,16]),
        resolver_records=records,symbol_index=20,symbol=NAME,base=0xec3d33,role='crt-contract',semantic_domain='code',contract_kind='cxx-frame-handler',
        proof_consistency='EXACT_GENERATED_HANDLER_FIELD_RESOLUTION',identity_consistency='EXACT_BASE_ROLE_RESOLUTION',
        target_executable=True,function_boundary_verified=False,runtime_eligible=False,provider_selected=False,ABI_verified=False,link_ready=False)
