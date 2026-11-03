"""Staged nonexec storage planning and gated unresolved DATA-only projection.

No PE discovery, original-code extraction, compiler, linker or execution path.
Saved-ledger observation and fragment projection require separate review gates.
"""
from __future__ import annotations
import copy
import bisect
from collections import Counter
import gzip
import hashlib
import json
from pathlib import Path
import re
import struct
import tempfile

import runtime_code_pool as namespace
from coff_rewrite import strict_object
from data_plan import Pe, fingerprint

ROLES={'data','code','iat-cell','crt-contract'}
ORDINARY={'ORDINARY_UNCLASSIFIED'}
SECTIONS={'.rdata':False,'.data':True,'CONST':True}
FALSE=dict(runtime_eligible=False,provider_selected=False,materialization_approved=False,
           link_ready=False,game_fixups_approved=0)
FORMAT='unresolved-original-data-arena-v1'


def require(ok,message):
    if not ok:raise ValueError(message)


def canonical(value):return json.dumps(value,sort_keys=True,separators=(',',':'),ensure_ascii=True).encode('ascii')
def digest(value):return hashlib.sha256(canonical(value)).hexdigest()
def sha(path):return hashlib.sha256(Path(path).read_bytes()).hexdigest()
def hexva(value):return '0x%08x'%value


def integer(value,lo=0,hi=0xffffffff):
    require(type(value) is int and lo<=value<=hi,'integer outside supported bounds')
    return value


def hash_value(value):return isinstance(value,str) and re.fullmatch('[0-9a-f]{64}',value) is not None


def planning_hash(policy):
    # Selection is a later phase; it cannot participate in the IDs it selects.
    return digest({k:v for k,v in policy.items() if k not in
        ('selected_fragments','projection_enabled','normalized_evidence_sha256')})


def no_approval(value):
    for key,expected in FALSE.items():require(value.get(key)==expected,'runtime/provider approval forbidden')


def policy_contract(policy):
    require(policy.get('schema_version')==1 and policy.get('policy_id')==FORMAT,'unsupported projection policy')
    no_approval(policy)
    require(policy.get('allowed_sections')==SECTIONS and policy.get('roles')==sorted(ROLES), 'section/role policy differs')
    require(policy.get('exact_target_addend')==0 and policy.get('identity_bridges')==[] and
            policy.get('adjacency_contracts')==[],'identity bridge/adjacency unsupported')
    require(policy.get('anchors_only') is True,'typed/interior view definitions unsupported')
    require(isinstance(policy.get('input_pins'),dict) and policy['input_pins'] and
            all(hash_value(v) for v in policy['input_pins'].values()),'input hash pins required')
    require(type(policy.get('max_fragment_bytes')) is int and 0<policy['max_fragment_bytes']<=16*1024*1024,
            'invalid fragment resource bound')
    require(isinstance(policy.get('selected_fragments'),list) and len(set(policy['selected_fragments']))==len(policy['selected_fragments']),
            'duplicate/missing selected fragment policy')


def build_plan(evidence,policy):
    """Pure metadata phase; every normalized field is retained or quarantined.

    This does not authenticate normalization. The file API requires an exact
    reviewed evidence hash; adapt_saved has a separate source/observation gate.
    """
    policy_contract(policy)
    require(evidence.get('schema_version')==1 and evidence.get('kind')=='normalized-data-arena-evidence', 'unsupported evidence schema')
    require(evidence.get('provenance')==policy['input_pins'],'stale/missing provenance')
    require(evidence.get('optional_function_index_present') is False,'optional index state changed')
    require(evidence.get('fields_complete') is True and evidence.get('domains_complete') is True,
            'incomplete field/domain evidence')
    require(evidence.get('identity_bridges')==[],'automatic demand identity bridge unsupported')
    arenas=evidence.get('arenas');domains=evidence.get('domains');fields=evidence.get('fields')
    require(isinstance(arenas,list) and isinstance(domains,list) and isinstance(fields,list), 'missing evidence arrays')
    require(len(arenas)<=16 and len(domains)<=100000 and len(fields)<=1000000,'evidence resource limit')
    ids=set();ordered=[];arena_by_id={};fragments=[];domain_by_id={}
    for a in arenas:
        require(isinstance(a['arena_id'],str) and a['arena_id'] not in ids,'duplicate arena identity')
        ids.add(a['arena_id']);arena_by_id[a['arena_id']]=a
        start=integer(a['start']);size=integer(a['size'],1);raw=integer(a['raw_size']);extent=integer(a['raw_backed'])
        integer(start+size,1,0x100000000)
        require(a['section'] in SECTIONS and extent==min(raw,size) and a['virtual_zero']==size-extent and
                a['raw_padding']==max(0,raw-size),'raw/virtual-zero/padding geometry differs')
        flags=integer(a['flags']);alignment=integer(a['alignment'],1,8192)
        require(alignment & (alignment-1)==0 and start%alignment==0,'arena alignment differs')
        require(flags & 0x40000000 and not flags & 0x20000020 and
                bool(flags & 0x80000000)==SECTIONS[a['section']] and
                not flags & ~(0xc0000000|0xc0), 'nonexec protection/section policy differs')
        require(hash_value(a['raw_sha256']),'raw section hash required')
        ordered.append((start,start+size))
        pieces=sorted([d for d in domains if d['arena_id']==a['arena_id']],key=lambda d:d['start'])
        cursor=start
        for d in pieces:
            lo,hi=integer(d['start']),integer(d['end'],1,0x100000000)
            require(lo==cursor and lo<hi<=start+size,'domain gap/overlap/outside arena')
            cursor=hi
            require(d['domain_id'] not in domain_by_id,'duplicate domain identity')
            domain_by_id[d['domain_id']]=d
            require(not lo<start+extent<hi,'domain crosses raw/virtual-zero boundary')
            backing='raw' if hi<=start+extent else 'virtual-zero'
            require(d['backing']==backing and isinstance(d['families'],list) and d['families'] and
                    type(d['overlap']) is bool,'domain backing/classification missing')
            ordinary=set(d['families'])==ORDINARY and not d['overlap']
            f=dict(fragment_id=digest(dict(arena=a['arena_id'],start=lo,end=hi,policy=planning_hash(policy))),
                   domain_id=d['domain_id'],arena_id=a['arena_id'],start=lo,size=hi-lo,
                   arena_offset=lo-start,backing=backing,flags=flags,alignment=alignment,
                   admitted=ordinary,reason=None if ordinary else 'reserved/source-owned/ambiguous domain',
                   original_domain=copy.deepcopy(d),
                   object_extent=None,object_type=None,lifetime_approved=False,
                   adjacency_to_other_fragments_proved=False)
            # Original envelope alignment does not promise fragment alignment.
            while lo%f['alignment']:f['alignment']//=2
            f['anchor']='_fnv_arena_'+digest(dict(image=policy['input_pins']['reference'],
                arena=a['arena_id'],start=lo,size=hi-lo,policy=planning_hash(policy)))
            fragments.append(f)
        require(cursor==start+size,'incomplete arena domain coverage')
    require(len(domain_by_id)==len(domains),'domain references unknown arena')
    ordered.sort();require(all(x[1]<=y[0] for x,y in zip(ordered,ordered[1:])),'overlapping arena envelopes')
    field_records=[];sites=[];seen=set();sorted_fragments=sorted(fragments,key=lambda f:f['start'])
    starts=[f['start'] for f in sorted_fragments]
    for field in fields:
        identity=field['field_id'];require(isinstance(identity,str) and identity not in seen,'duplicate field identity')
        seen.add(identity);site=integer(field['site']);target=integer(field['target']);integer(site+4,4,0x100000000)
        sites.append((site,site+4));a=arena_by_id.get(field['arena_id'])
        require(a is not None and a['start']<=site and site+4<=a['start']+a['size'],'field outside arena')
        require(field.get('width')==4 and field.get('kind')=='HIGHLOW','unsupported field width/relocation')
        at=bisect.bisect_right(starts,site)-1
        require(at>=0 and site+4<=sorted_fragments[at]['start']+sorted_fragments[at]['size'], 'field crosses domain/backing boundary')
        f=sorted_fragments[at];reasons=[];roles=field.get('roles')
        require(isinstance(roles,list) and len(set(roles))==len(roles),'invalid target roles')
        if len(roles)!=1 or roles[0] not in ROLES:reasons.append('unknown/ambiguous exact target role')
        if not f['admitted']:reasons.append('reserved source domain')
        if f['backing']!='raw':reasons.append('virtual-zero HIGHLOW unexplained')
        if field.get('target_known') is not True:reasons.append('target identity/domain unproved')
        require(field.get('source_symbol_base') is None and field.get('source_addend') is None,
                'source-base-plus-addend migration requires separate reviewed bridge')
        require(field.get('base_basis')=='exact_highlow_target' and field.get('addend')==0,'exact-target addend/base differs')
        if field.get('representation')!='absolute32':reasons.append('RVA/encoded/relative representation unsupported')
        role=roles[0] if len(roles)==1 and roles[0] in ROLES else None
        field_records.append(dict(field_id=identity,site=site,target=target,fragment_id=f['fragment_id'],
            original=copy.deepcopy(field),
            offset=site-f['start'],role=role,base_basis='exact_highlow_target',source_symbol_base=None,
            addend=0,undefined=namespace.unresolved(hexva(target),role) if role else None,
            state='quarantined' if reasons else 'symbolic-unresolved',blockers=reasons,**FALSE))
    sites.sort();require(all(x[1]<=y[0] for x,y in zip(sites,sites[1:])),'overlapping HIGHLOW fields')
    relationships=copy.deepcopy(evidence.get('relationships',[]))
    require(isinstance(relationships,list),'missing relationship evidence')
    for r in relationships:
        require(r.get('proved') is False and r.get('kind') in ('cross-fragment','cross-domain','rva-format','lifetime','unknown-state'),
                'unsupported relationship approval/kind')
    plan=dict(schema_version=1,kind='unresolved-data-arena-plan',policy_id=FORMAT,policy_sha256=digest(policy),
        planning_policy_sha256=planning_hash(policy),
        evidence_sha256=digest(evidence),provenance=copy.deepcopy(policy['input_pins']),arenas=copy.deepcopy(arenas),
        fragments=fragments,fields=field_records,relationships=relationships,anchors_only=True,
        missing_fields=copy.deepcopy(evidence.get('missing_fields',[])),
        retained_event_provenance=copy.deepcopy(evidence.get('retained_event_provenance',{})),
        retained_obligations=copy.deepcopy(evidence.get('retained_obligations',[])),
        excluded_geometry=copy.deepcopy(evidence.get('excluded_geometry',[])),
        external_field_quarantines=copy.deepcopy(evidence.get('external_field_quarantines',[])),
        known_limitations=['normalization is hash-bound observation, not semantic/lifecycle proof',
                          'no typed/lifetime owner selection, adjacency, RVA grammar or runtime adoption'],**FALSE)
    require(sum(r['state'] in ('quarantined','symbolic-unresolved') for r in field_records)==len(fields),'field accounting differs')
    return plan


def selected_plan(plan,policy,review):
    policy_contract(policy);no_approval(plan)
    require(plan.get('kind')=='unresolved-data-arena-plan' and plan.get('planning_policy_sha256')==planning_hash(policy),'stale plan/policy')
    require(policy.get('projection_enabled') is True,'private projection disabled')
    require(review.get('kind')=='data-arena-private-projection-review' and review.get('approved') is True and
            review.get('reviewer') and review.get('root_authorized') is True and
            review.get('plan_sha256')==digest(plan) and review.get('policy_sha256')==digest(policy), 'projection review missing/stale')
    selected=policy['selected_fragments'];require(selected and review.get('selected_fragments')==selected,'empty/different reviewed selection')
    by_id={f['fragment_id']:f for f in plan['fragments']}
    require(len(by_id)==len(plan['fragments']) and all(i in by_id for i in selected),'unknown/duplicate fragment')
    result=[by_id[i] for i in selected]
    require(len(result)<=64 and all(f['admitted'] and f['size']<=policy['max_fragment_bytes'] for f in result),'reserved/oversized projection fragment')
    # Unresolved obligations remain visible in partial artifacts. They forbid
    # runtime use, but do not erase mechanically projectable ordinary fragments.
    require(all(r['state']=='symbolic-unresolved' for r in plan['fields'] if r['fragment_id'] in selected),'selected quarantined field')
    return result


def object_bytes(fragment,fields,payload):
    """One DATA-only fragment, independent allocation, one anchor; no views."""
    size=fragment['size'];zero=fragment['backing']=='virtual-zero'
    require(len(payload)==(0 if zero else size) and (not zero or not fields),'fragment payload/zero fields differ')
    require(fragment['admitted'] and fragment['flags'] & 0x40000000 and not fragment['flags'] & 0x20000020,'executable/reserved fragment')
    alignment=fragment['alignment'];require(alignment in [1<<n for n in range(14)],'unsupported COFF alignment')
    normalized=bytearray(payload);names=sorted({r['undefined'] for r in fields})
    require(all(isinstance(n,str) and n.startswith('_fnv_undefined_') for n in names),'invalid undefined identity')
    symbols=[(fragment['anchor'],0,1,2)]+[(n,0,0,2) for n in names]+[('@feat.00',1,-1,3)]
    raw=60 if not zero else 0;relptr=60+len(normalized) if fields else 0
    reloc=bytearray();seen=[]
    for r in fields:
        off=r['offset'];require(r['fragment_id']==fragment['fragment_id'] and r['state']=='symbolic-unresolved' and
            r['addend']==0 and r['undefined']==namespace.unresolved(hexva(r['target']),r['role']) and
            0<=off<=size-4,'field identity/addend/bounds differs')
        require(struct.unpack_from('<I',normalized,off)[0]==r['target'],'owned HIGHLOW word differs')
        seen.append((off,off+4));struct.pack_into('<I',normalized,off,0)
        reloc+=struct.pack('<IIH',off,names.index(r['undefined'])+1,6)
    seen.sort();require(all(a[1]<=b[0] for a,b in zip(seen,seen[1:])) and len(fields)<65535,'overlapping/too many COFF relocations')
    strings=bytearray(bytes(4));symbytes=bytearray()
    for name,value,section,storage in symbols:
        enc=name.encode('ascii');require(b'\0' not in enc,'invalid symbol name')
        n=struct.pack('<II',0,len(strings)) if len(enc)>8 else enc.ljust(8,b'\0')
        if len(enc)>8:strings+=enc+b'\0'
        symbytes+=struct.pack('<8sIhHBB',n,value,section,0,storage,0)
    struct.pack_into('<I',strings,0,len(strings));ptr=60+len(normalized)+len(reloc)
    flags=(0xc0000000 if fragment['flags'] & 0x80000000 else 0x40000000)|((alignment.bit_length())<<20)|(0x80 if zero else 0x40)
    section=struct.pack('<8sIIIIIIHHI',b'.bss' if zero else b'.data',0,0,size,raw,relptr,0,len(fields),0,flags)
    return struct.pack('<HHIIIHH',0x14c,1,0,ptr,len(symbols),0,0)+section+normalized+reloc+symbytes+strings


def validate_object(path,fragment,fields,payload):
    """Independent strict COFF reparse and content/identity check, no serializer maps."""
    coff,_,_,_=strict_object(path);require(len(coff.sections)==1,'unexpected output sections')
    sec=coff.sections[1];zero=fragment['backing']=='virtual-zero'
    flags=(0xc0000000 if fragment['flags'] & 0x80000000 else 0x40000000)|(fragment['alignment'].bit_length()<<20)|(0x80 if zero else 0x40)
    require(sec['name']==('.bss' if zero else '.data') and sec['size']==fragment['size'] and sec['flags']==flags,'output geometry/protection differs')
    require(not sec['flags'] & 0x20000020 and not coff.directives,'executable/directive output forbidden')
    expected={fragment['anchor']:(1,0,2),'@feat.00':(-1,1,3)}
    expected.update({r['undefined']:(0,0,2) for r in fields})
    require(len(coff.symbols)==len(expected) and {s['name']:(s['section'],s['value'],s['storage']) for s in coff.symbols.values()}==expected and
            all(s['aux_count']==0 and s['type']==0 for s in coff.symbols.values()),'extra/malformed output symbol/aux')
    raw_offset=struct.unpack_from('<I',coff.data,40)[0]
    observed=[];actual=bytearray(coff.data[raw_offset:raw_offset+sec['size']]) if not zero else bytearray()
    if zero:require(raw_offset==0 and not sec['relocs'] and not payload,'zero storage acquired raw payload/relocations')
    for offset,index,kind in sec['relocs']:
        require(kind==6 and offset+4<=len(actual),'unknown/crossing output relocation')
        target=coff.symbols[index];require(target['section']==0,'relocation target was defined locally')
        observed.append((offset,target['name'],struct.unpack_from('<I',actual,offset)[0]))
    require(sorted(observed)==sorted((r['offset'],r['undefined'],r['addend']) for r in fields),'missing/extra/retargeted DIR32/addend')
    for r in fields:struct.pack_into('<I',actual,r['offset'],r['target'])
    require(bytes(actual)==payload,'nonrelocated payload differs')
    return dict(object_sha256=sha(path),fragment_id=fragment['fragment_id'],anchor=fragment['anchor'],
        size=fragment['size'],backing=fragment['backing'],raw_payload_sha256=hashlib.sha256(payload).hexdigest(),
        fields=copy.deepcopy(fields),undefined=sorted(n for n,v in expected.items() if v[0]==0),**FALSE)


def stable_inputs(bindings):
    require(bindings and all(hash_value(v) and sha(k)==v for k,v in bindings.items()),'stale protected input')


def json_bound(path,expected):
    require(sha(path)==expected,'stale bound JSON input')
    return json.loads(Path(path).read_text(encoding='utf-8'))


def publish_json(path,value,bindings):
    """Stage complete metadata before exclusive publication; clean own failure."""
    path=Path(path).resolve();require(not path.exists() and str(path) not in bindings,'output/input collision')
    with tempfile.TemporaryFile() as staged:
        staged.write(canonical(value)+b'\n');staged.seek(0);stable_inputs(bindings)
        created=False
        try:
            with path.open('xb') as stream:
                created=True
                while block:=staged.read(1048576):stream.write(block)
            stable_inputs(bindings)
        except Exception:
            if created:path.unlink()
            raise


def target_role(row):
    """Exact special roles win only when unambiguous; TLS/unknown quarantine."""
    view=row['target_view'];domains=view.get('domain_evidence',[])
    if any(d.get('unresolved_domain_overlap') for d in domains) or view.get('code_ownership_ambiguous'):return []
    families={family for d in domains for family in d['families']}
    if families=={'FRESH_IAT_CELL'}:return ['iat-cell']
    if families=={'FRESH_NORMAL_CRT_STATE'}:return ['crt-contract']
    classification=row['original_record'][2]
    if families-{'ORDINARY_UNCLASSIFIED','SOURCE_PROJECTION_CANDIDATE'}:return []
    if classification=='data':return ['data']
    if classification in {'ordinary-entry','ordinary-interior','EH-entry','EH-interior'}:
        return ['code'] if len(view.get('code_provider_candidates',[]))==1 else []
    return []


def adapt_saved(paths,policy,owned_sha256,root,review):
    """Read-only adapter for exact saved ledger/v4; no payload emission.

    Retain every ledger event either normalized with original record/ordinal or
    as an unchanged obligation. Rejoin all original v4 rows in sequence.
    """
    policy_contract(policy);root=Path(root).resolve();pins=policy['input_pins']
    require(review.get('kind')=='data-arena-observation-review' and review.get('approved') is True and
        review.get('root_authorized') is True and review.get('reviewer') and review.get('policy_sha256')==digest(policy) and
        review.get('source_sha256')==sha(__file__) and review.get('owned_image_sha256')==owned_sha256,
        'read-only observation review missing/stale')
    required=set(pins)|{'owned_image'}
    require(set(paths)==required and hash_value(owned_sha256),'exact input paths and owned image pin required')
    paths={n:Path(p).resolve() for n,p in paths.items()}
    require(len(set(paths.values()))==len(paths),'input aliases forbidden')
    bindings={str(paths[n]):h for n,h in pins.items()};bindings[str(paths['owned_image'])]=owned_sha256
    for relative,digest_value in policy['implementation_pins'].items():
        p=(root/relative).resolve();require(p.is_relative_to(root),'implementation path escapes root')
        bindings[str(p)]=digest_value
    bindings[str(Path(__file__).resolve())]=review['source_sha256'];stable_inputs(bindings)
    ledger,data,binding,manifest,retained,selection,imports=[json_bound(paths[n],pins[n]) for n in
        ('ledger','data_plan','binding','manifest','retained','selection','imports')]
    require(ledger.get('kind')=='fnv-runtime-data-owner-ledger' and ledger.get('schema_version')==1 and
        ledger.get('status')=='analysis-only','unsupported owner ledger')
    no_approval(ledger)
    require(all(ledger['inputs'][n]==pins[n] for n in ('data_plan','binding','recipes','manifest','retained','selection','imports','reference')),
            'ledger/provenance join differs')
    require(ledger['details_sha256']==pins['ledger_details'] and data['detail_sha256']==pins['data_details'] and
        binding['details_sha256']==pins['binding_details'] and ledger['data_detail_sha256']==pins['data_details'] and
        ledger['binding_detail_sha256']==pins['binding_details'],'detail hash joins differ')
    require(ledger['optional_function_index_present'] is False and not (root/'build/function_index.json').exists() and
        retained['inputs']['function_index_present'] is False and selection['function_index_present'] is False,
        'optional index state changed')
    # Rehash exact manifest-listed sources/objects and original comparator tools;
    # no object scan, no corpus search and no compiler invocation.
    for unit in manifest['units']:
        obj=(paths['manifest'].parent/manifest.get('object_root_relative','.')/unit['object']).resolve()
        source=(root/unit['source']).resolve();require(source.is_relative_to(root),'producer source escapes root')
        for p,h in ((obj,unit['object_sha256']),(source,unit['source_sha256'])):
            require(str(p) not in bindings or bindings[str(p)]==h,'producer identity conflict');bindings[str(p)]=h
    for relative,h in retained['inputs']['tools_sha256'].items():
        p=(root/relative).resolve();require(p.is_relative_to(root),'comparator tool escapes root');bindings[str(p)]=h
    for compiler in manifest.get('toolchains',{}).values():
        if compiler.get('ready'):
            cl=(Path(compiler['root'])/'VC/bin/cl.exe').resolve()
            bindings[str(cl)]=compiler['cl_sha256']
    stable_inputs(bindings)
    pe=Pe(paths['owned_image']);reference=Pe(paths['reference'])
    try:
        require(pe.base==reference.base==data['image']['base'] and pe.image_size==reference.image_size==data['image']['size'] and
            pe.section_headers==reference.section_headers,'owned/reference geometry differs')
        identities,nonexec=pe.nonexec_identity();other,other_digest=reference.nonexec_identity()
        require(identities==other==data['provenance']['nonexec_sections'] and nonexec==other_digest==data['provenance']['nonexec_digest'],
                'owned/reference nonexec identity differs')
        probe=fingerprint(reference,paths['image_check'])
        require(probe==data['provenance']['reference_fingerprint'],'reference fingerprint changed')
        alignment=pe.unpack('<II',pe.unpack('<I',0x3c)[0]+24+32)[0]
        pe_sections={s['name']:s for s in pe.sections}
    finally:pe.close();reference.close()
    normalized=dict(schema_version=1,kind='normalized-data-arena-evidence',provenance=copy.deepcopy(pins),
        optional_function_index_present=False,fields_complete=True,domains_complete=True,identity_bridges=[],
        arenas=[],domains=[],fields=[],relationships=[],missing_fields=[],retained_obligations=[],excluded_geometry=[],external_field_quarantines=[])
    events=Counter();sequence=hashlib.sha256();data_sequence=hashlib.sha256();arenas={};raw_fields=[];all_domains=[]
    total=0
    with gzip.open(paths['ledger_details'],'rt',encoding='utf-8') as stream:
        for ordinal,line in enumerate(stream,1):
            total+=len(line);require(total<=1024*1024*1024,'ledger uncompressed resource bound')
            require(ordinal<=1000000 and len(line)<=16*1024*1024,'ledger stream resource bound')
            row=json.loads(line);event=row.get('event');require(event in ledger['summary']['events'],'unknown ledger event')
            events[event]+=1;sequence.update(canonical(row)+b'\n')
            original=dict(ordinal=ordinal,record=row)
            if event=='ARENA_GEOMETRY':
                if row['section'] not in SECTIONS:normalized['excluded_geometry'].append(original);continue
                s=pe_sections[row['section']];require(not s['executable'] and row['original_start']==data['image']['base']+s['rva'] and
                    row['logical_extent']==s['extent'] and row['raw_backed_extent']==min(s['raw_size'],s['extent']) and
                    row['virtual_zero_extent']==max(0,s['extent']-s['raw_size']) and row['flags']==s['flags'] and
                    row['PE_section_alignment_observed']==alignment,'ledger/PE arena geometry differs')
                a=dict(arena_id=row['arena_id'],section=row['section'],start=row['original_start'],size=row['logical_extent'],
                    raw_size=s['raw_size'],raw_backed=row['raw_backed_extent'],virtual_zero=row['virtual_zero_extent'],
                    raw_padding=row['raw_padding_excluded'],flags=row['flags'],alignment=alignment,
                    raw_sha256=row['raw_section_sha256'],original=original)
                require(a['arena_id'] not in arenas,'duplicate ledger arena');arenas[a['arena_id']]=a;normalized['arenas'].append(a)
            elif event=='DISJOINT_ARENA_DOMAIN':all_domains.append(original)
            elif event=='DATA_HIGHLOW_FIELD':raw_fields.append(original)
            else:
                normalized['retained_obligations'].append(original)
                if event=='MISSING_FIELD_BLOCKER':normalized['missing_fields'].append(original)
    require(dict(events)==ledger['summary']['events'] and events['DATA_HIGHLOW_FIELD']==ledger['summary']['data_fields'], 'incomplete ledger event coverage')
    for original in all_domains:
        d=original['record']
        if d['arena_id'] not in arenas:normalized['excluded_geometry'].append(original);continue
        normalized['domains'].append(dict(arena_id=d['arena_id'],domain_id=d['domain_id'],start=d['start'],end=d['end'],
            backing=d['backing'],families=d['families'],overlap=d['unresolved_domain_overlap'],original=original))
    i=-1
    with gzip.open(paths['data_details'],'rt',encoding='utf-8') as stream:
        for i,line in enumerate(stream):
            require(i<len(raw_fields) and len(line)<=65536,'extra/oversized original v4 row')
            vals=json.loads(line);row=raw_fields[i]['record'];data_sequence.update(canonical(vals))
            require(vals==row['original_record'] and digest(vals)==row['site_identity'],'original v4 field join differs')
        require(len(raw_fields)>0 and i+1==len(raw_fields),'missing original v4 rows')
    require(data_sequence.hexdigest()==ledger['summary']['data_identity_sequence_sha256'],'original field sequence differs')
    for original in raw_fields:
        row=original['record'];roles=target_role(row)
        if row['source_arena'] not in arenas:
            normalized['external_field_quarantines'].append(dict(original=original,reason='source outside ordinary arena'));continue
        normalized['fields'].append(dict(field_id=row['site_identity'],arena_id=row['source_arena'],site=int(row['original_site_va'],16),
            target=int(row['original_target_va'],16),width=4,kind='HIGHLOW',roles=roles,target_known=len(roles)==1,
            source_symbol_base=None,source_addend=None,base_basis='exact_highlow_target',addend=0,representation='absolute32',original=original))
    normalized['relationships']=[dict(kind=k,proved=False) for k in ('cross-fragment','cross-domain','rva-format','lifetime','unknown-state')]
    normalized['retained_event_provenance']=dict(ledger_details_sha256=pins['ledger_details'],events=dict(events),
        complete_sequence_sha256=sequence.hexdigest(),fields_accounted=len(normalized['fields'])+len(normalized['external_field_quarantines']),
        owned_image_sha256=owned_sha256,reference_fingerprint=probe,protected_input_count=len(bindings))
    require(normalized['retained_event_provenance']['fields_accounted']==ledger['summary']['data_fields'],'dropped field')
    stable_inputs(bindings);require(not (root/'build/function_index.json').exists(),'optional index appeared')
    return normalized,bindings


def observe_saved(paths,policy_path,owned_sha256,root,review_path,out):
    """Exclusive metadata-only observation; requires exact independent source gate."""
    policy_path,review_path,out=[Path(p).resolve() for p in (policy_path,review_path,out)]
    ph,rh=sha(policy_path),sha(review_path);policy=json.loads(policy_path.read_text());review=json.loads(review_path.read_text())
    normalized,bindings=adapt_saved(paths,policy,owned_sha256,root,review)
    bindings.update({str(policy_path):ph,str(review_path):rh});stable_inputs(bindings)
    require(not out.exists() and str(out) not in bindings,'output/input collision')
    plan=build_plan(normalized,policy)
    # Preserve complete normalized original records alongside the candidate plan;
    # the original ledger stream remains hash/ordinal-bound, never rewritten.
    report=dict(schema_version=1,kind='data-arena-read-only-observation',plan=plan,normalized_evidence=normalized,
        protected_inputs=bindings,source_review_sha256=rh,owned_image_sha256=owned_sha256,**FALSE)
    stable_inputs(bindings)
    publish_json(out,report,bindings)
    return report


def project_owned(observation_path,policy_path,review_path,out):
    """Production file gate; retains private paths only in private receipts."""
    op,pp,rp=[Path(p).resolve() for p in (observation_path,policy_path,review_path)]
    observation=json.loads(op.read_text());policy=json.loads(pp.read_text());review=json.loads(rp.read_text())
    require(observation.get('kind')=='data-arena-read-only-observation','unsupported observation receipt')
    no_approval(observation);plan=observation['plan']
    selected_plan(plan,policy,review)  # Disabled policy rejects before PE data reads.
    bindings=dict(observation['protected_inputs'])
    bindings.update({str(op):sha(op),str(pp):sha(pp),str(rp):sha(rp)})
    require(review.get('observation_sha256')==bindings[str(op)],'projection observation review stale')
    stable_inputs(bindings)
    candidates=[Path(p) for p,h in bindings.items() if h==observation['owned_image_sha256']]
    require(len(candidates)==1,'owned image identity ambiguous');pe=Pe(candidates[0])
    try:
        def read_fragment(f):
            a=next(a for a in plan['arenas'] if a['arena_id']==f['arena_id'])
            require(f['start']>=a['start'] and f['start']+f['size']<=a['start']+a['raw_backed'],'raw read exceeds admitted backing')
            sec=pe.section(f['start']-pe.base,f['size'],required=True)
            require(not sec['executable'] and sec['name']==a['section'] and sec['flags']==a['flags'],'owned fragment section identity changed')
            return pe.read_rva(f['start']-pe.base,f['size'])
        return project(plan,policy,review,bindings,read_fragment,out)
    finally:pe.close()


def publish_plan(evidence_path,policy_path,out,bindings):
    """File API requires a separately reviewed exact normalized evidence pin."""
    ep,pp,out=[Path(p).resolve() for p in (evidence_path,policy_path,out)]
    stable_inputs(bindings);require(str(ep) in bindings and str(pp) in bindings,'unbound evidence/policy')
    require(not out.exists() and str(out) not in bindings,'output/input collision')
    policy=json.loads(pp.read_text());require(policy.get('normalized_evidence_sha256')==sha(ep),'normalization not independently bound')
    result=build_plan(json.loads(ep.read_text()),policy);stable_inputs(bindings)
    publish_json(out,result,bindings)
    return result


def project(plan,policy,review,bindings,read_fragment,out):
    """Private projection API. Reader must return exact owned raw bytes only.

    Caller must pin the reader and all inputs. No real emission is authorized by
    implementation alone; the shipped policy has no enabled selection.
    """
    stable_inputs(bindings);selected=selected_plan(plan,policy,review);out=Path(out).resolve()
    require(not out.exists() and all(out!=Path(p).resolve() and out not in Path(p).resolve().parents for p in bindings),'output/input collision')
    staged=[]
    with tempfile.TemporaryDirectory(prefix='fnv_data_arena_') as tmp:
        for f in selected:
            fields=[r for r in plan['fields'] if r['fragment_id']==f['fragment_id']]
            payload=read_fragment(copy.deepcopy(f)) if f['backing']=='raw' else b''
            require(isinstance(payload,bytes),'raw reader must return bytes')
            path=Path(tmp)/(f['fragment_id']+'.obj');path.write_bytes(object_bytes(f,fields,payload))
            info=validate_object(path,f,fields,payload);staged.append((path,info))
        stable_inputs(bindings)
        # Publish exclusively only after every independent reparse and stability
        # check; remove only our own new outputs if a final check fails.
        out.mkdir();published=[]
        try:
            for path,info in staged:
                dest=out/path.name
                with dest.open('xb') as stream:stream.write(path.read_bytes())
                published.append(dest);require(sha(dest)==info['object_sha256'],'publication content differs')
            report=dict(schema_version=1,kind='private-unresolved-data-arena-projection',plan_sha256=digest(plan),
                policy_sha256=digest(policy),review_sha256=digest(review),partial=True,
                selected_fragments=policy['selected_fragments'],selected_fragment_records=selected,
                protected_inputs=copy.deepcopy(bindings),objects=[i for _,i in staged],
                quarantined_fields=sum(f['state']=='quarantined' for f in plan['fields']),**FALSE)
            stable_inputs(bindings)
            receipt=out/'projection.json'
            with receipt.open('x',encoding='utf-8') as stream:json.dump(report,stream,indent=2);stream.write('\n')
            published.append(receipt);stable_inputs(bindings);return report
        except Exception:
            for path in published:path.unlink()
            out.rmdir();raise
