"""Fixed private unresolved CODE pool experiment; never a runnable link.

Assessment is pure metadata/bytes. Publication requires a separate root-approved
review identity and unchanged comparator check, supplied to the bounded driver.
"""
from __future__ import annotations
import argparse
from collections import defaultdict
import gzip
import hashlib
import json
import os
from pathlib import Path
import re
import struct
import sys
import tempfile
import coff_code_archive as coff

ROOT=Path(__file__).resolve().parents[2]
POLICY_ID='unresolved-code-pool-v1'
DEFAULTS=['/DEFAULTLIB:"LIBCMT"','/DEFAULTLIB:"OLDNAMES"']
BATCH_STATUS={'0x00be0b90':(True,None),'0x00646d00':(True,None),'0x00a28740':(True,None),
              '0x00aa13e0':(False,'WEAK_OR_COMMON_RECORD'),'0x0043fd40':(False,'SAME_PARENT_EH_OR_UNKNOWN_ASSOCIATION'),
              '0x00aa0fc0':(False,'ORIGINAL_MISSING_RELOCATION')}
EXPECTED_COUNTS=dict(assessed=6,emitted=3,quarantined=3,checked_code_bytes=673,retained_literal_bytes=16)
# The deferred independent-reader wrapper is a producer too; its inventory
# dependency is separately pinned by the existing retained/EH tool receipts.
READER_DEPENDENCIES={'tools/rebuild/coff_rewrite.py':'48cea438b05a1c2de992eea4200b45a1eb14e49a27704a5c6fff98f941b1ae4c'}
require=coff.require
digest=coff.digest


def canonical(identity):
    require(set(identity)=={'recipe_id','object_sha256','symbol_index'} and isinstance(identity['recipe_id'],str)
            and re.fullmatch('[0-9a-f]{64}',identity['object_sha256']) and type(identity['symbol_index']) is int
            and identity['symbol_index']>=0,'invalid provider identity')
    return '_fnv_code_'+digest(json.dumps(identity,sort_keys=True,separators=(',',':')).encode())


def unresolved(base,role):
    require(isinstance(base,str) and re.fullmatch('0x[0-9a-f]{8}',base) and isinstance(role,str) and role,'invalid unresolved identity')
    return '_fnv_undefined_'+digest(json.dumps(dict(original_base=base,role=role),sort_keys=True,separators=(',',':')).encode())


def index_object(obj):
    """One per-recipe structural index, shared by all selected roots."""
    if '_pool_index' in obj:
        return obj['_pool_index']
    members=defaultdict(list); children=defaultdict(list); aux_by_section=defaultdict(list); problems=[]
    metadata=[]
    for i,s in obj['symbols'].items():
        members[s['section']].append(i)
        if s['name'] in ('@comp.id','@feat.00'):
            if (s['section'],s['type'],s['storage'],s['aux_count'])==(-1,0,3,0) and (s['name']=='@comp.id' or s['value']==1):metadata.append(i)
            else:problems.append(('UNSUPPORTED_COMPILER_METADATA',i))
        if s['storage']==105 or (s['section']==0 and s['value']):
            problems.append(('WEAK_OR_COMMON_RECORD',i))
        if s['aux']:
            if s['storage']==103 and s['section']==-2:
                continue # FILE auxiliaries explicitly omitted as compiler/debug provenance.
            if not(s['storage']==3 and s['section']>0 and s['type']==0 and s['value']==0 and s['aux_count']==1
                   and s['name']==obj['sections'][s['section']]['name']):
                problems.append(('UNSUPPORTED_AUXILIARY',i)); continue
            a=struct.unpack('<IHHIhBBH',s['aux']); sec=obj['sections'][s['section']]
            if a[0]!=sec['size'] or a[1]!=len(sec['relocs']) or a[2] or a[6] or a[7] or a[5] not in range(8):
                problems.append(('UNKNOWN_AUXILIARY_METADATA',i))
            if a[5]==5:
                if a[4] not in obj['sections']:
                    problems.append(('INVALID_ASSOCIATION',i))
                else:
                    children[a[4]].append(s['section'])
            elif a[4]: problems.append(('HIDDEN_AUXILIARY_INDEX',i))
            aux_by_section[s['section']].append((i,a))
    directives=[]; ds=[]
    for i,s in obj['sections'].items():
        if s['name']=='.drectve':
            ds.append(i)
            directives+=re.findall(r'(?:[^\s"\x00]+|"[^"]*")+',s['payload'].decode('ascii'))
        if s['name']=='.sxdata': problems.append(('SAFESEH_REQUIRES_CLOSURE',i))
    if directives!=DEFAULTS or len(ds)!=1:
        problems.append(('UNKNOWN_DIRECTIVE_CONTRACT',directives))
    elif obj['sections'][ds[0]]['relocs'] or obj['sections'][ds[0]]['flags']&0x1000:
        problems.append(('UNSUPPORTED_DIRECTIVE_SECTION',ds[0]))
    # Association cycles are global malformed metadata, even when not reached.
    state={}
    for root in obj['sections']:
        stack=[(root,False)]
        while stack:
            i,leave=stack.pop()
            if leave:state[i]=2;continue
            if state.get(i)==1:problems.append(('ASSOCIATION_CYCLE',i));continue
            if state.get(i)==2:continue
            state[i]=1;stack.append((i,True));stack.extend((child,False) for child in children[i])
    result=dict(members=members,children=children,aux=aux_by_section,problems=problems,directives=directives,directive_sections=ds,metadata=metadata)
    obj['_pool_index']=result
    return result


def assess_member(data,contract):
    try:
        obj=coff.parse(data)
        require(digest(data)==contract['object_sha256'],'stale object hash')
        return assess_parsed(obj,contract)
    except (ValueError,KeyError,TypeError,IndexError,UnicodeError,struct.error) as e:
        return dict(schema_version=1,policy_id=POLICY_ID,candidate_eligible=False,
                    blockers=[dict(code='MALFORMED_OR_STALE_OBJECT',evidence=str(e))],obligations=[],observations={})


def assess_parsed(obj,contract):
    """Caller pins parsed bytes/hash and complete trusted evidence before/after.

    No size limit. This policy is shared with all-size metadata accounting.
    """
    ix=index_object(obj); secs=obj['sections']; syms=obj['symbols']; f=contract['selected']; blockers=[]; obligations=[]
    def block(code,evidence): blockers.append(dict(code=code,evidence=evidence))
    for code,evidence in ix['problems']: block(code,evidence)
    if contract.get('verified_match') is not True: block('MISSING_EXACT_V3_MATCH',f)
    if contract.get('fields_complete') is not True or contract.get('missing_fields_complete') is not True:
        block('INCOMPLETE_FIELD_ACCOUNTING',f['original_address'])
    if contract.get('missing_fields'): block('ORIGINAL_MISSING_RELOCATION',contract['missing_fields'])
    root=syms.get(f['symbol_index']); section=secs.get(f['section'])
    if root is None or section is None:
        block('MISSING_SELECTED_PHYSICAL_OWNER',f)
        return dict(schema_version=1,policy_id=POLICY_ID,candidate_eligible=False,blockers=blockers,obligations=[],observations={})
    if (root['name'],root['section'],root['value'],root['type'],root['storage'],root['aux_count'])!=(f['symbol'],f['section'],f['value'],32,2,0):
        block('UNSUPPORTED_SELECTED_OWNER',f)
    if f['value']!=0 or section['size']!=f['size'] or len(section['payload'])!=f['size']:
        block('SHARED_OR_UNVERIFIED_SECTION_EXTENT',dict(section_size=section['size'],selected_size=f['size'],value=f['value']))
    if section['name']!='.text' or not section['flags']&0x20 or not section['flags']&0x20000000 or not section['flags']&0x1000:
        block('UNSUPPORTED_CODE_SECTION',dict(name=section['name'],flags=section['flags']))
    a=ix['aux'].get(f['section'],[])
    if len(a)!=1 or a[0][1][5]!=1: block('UNSUPPORTED_ROOT_COMDAT',[(i,list(t)) for i,t in a])
    keep={f['section'],*ix['directive_sections']}; locals_=[]; drops=[]
    for i in ix['members'][f['section']]:
        s=syms[i]
        if i==f['symbol_index'] or s['aux']:continue
        if s['storage']==3 and s['type']==0 and 0<=s['value']<f['size'] and not s['name'].startswith(('__eh','__unwind','__catch')):
            locals_.append(i)
        else:block('UNPROVED_EXTRA_ENTRY_OR_ALIAS',dict(symbol_index=i,name=s['name'],value=s['value']))
    frontier=[f['section']]; visited=set()
    while frontier:
        parent=frontier.pop()
        for child in ix['children'][parent]:
            if child in visited:continue
            visited.add(child); cs=secs[child]
            if cs['name'].startswith('.debug') and not cs['flags']&(0x20|0x20000000):
                drops.append(dict(section=child,parent=parent,reason='explicit debug-only associative exclusion',size=cs['size'],relocations=len(cs['relocs'])))
                frontier.append(child)
            else:block('SAME_PARENT_EH_OR_UNKNOWN_ASSOCIATION',dict(section=child,name=cs['name'],parent=parent))
    literal_sections=contract.get('literal_sections',[])
    for secid in literal_sections:
        ls=secs.get(secid); aa=ix['aux'].get(secid,[])
        owners=[i for i in ix['members'][secid] if not syms[i]['aux']]
        proof=[r.get('literal') for r in contract.get('fields',[]) if r['coff_relocation']['symbol_section']==secid]
        valid=bool(ls and ls['name']=='.rdata' and ls['flags']==0x40401040 and not ls['relocs'] and len(aa)==1 and aa[0][1][5]==2
                   and len(owners)==1 and syms[owners[0]]['storage']==2 and syms[owners[0]]['value']==0 and syms[owners[0]]['type']==0
                   and proof and all(p and p['extent']==ls['size'] and p['payload_sha256']==digest(ls['payload']) and p['full_extent_equal'] is True
                     and p['source_and_original_readonly'] is True and p['no_source_relocations_or_original_HIGHLOW'] is True for p in proof)
                   and not ix['children'][secid])
        if not valid:block('UNPROVED_LITERAL_OWNER',secid)
        else:keep.add(secid)
    fields=contract.get('fields',[]); actual=section['relocs']; seen=[]; names={}; undef=set(); bases={}
    identity=dict(recipe_id=contract['recipe_id'],object_sha256=contract['object_sha256'],symbol_index=f['symbol_index'])
    names[f['symbol_index']]=canonical(identity)
    for row in fields:
        r=row['coff_relocation']; target=syms.get(r['symbol_index']); key=(r['offset'],r['symbol_index'],r['kind']); seen.append(key)
        if row.get('function_va')!=f['original_address'] or row.get('physical_section')!=f['section'] or row.get('recipe_id')!=contract['recipe_id'] or key not in actual or target is None:
            block('STALE_OR_EXTRA_FIELD',key);continue
        off,si,kind=key
        if kind not in (6,20):block('UNSUPPORTED_RUNTIME_RELOCATION',key);continue
        raw=int.from_bytes(section['payload'][off:off+4],'little'); add=raw if kind==6 or raw<0x80000000 else raw-0x100000000
        base=row.get('derived_source_symbol_base_va'); final=row.get('exact_original_target_va'); cls=row.get('classification','')
        if (r.get('symbol'),r.get('symbol_section'),r.get('symbol_value'),r.get('symbol_type'),r.get('symbol_storage'),r.get('addend'))!=(target['name'],target['section'],target['value'],target['type'],target['storage'],raw):
            block('CHANGED_PHYSICAL_FIELD_RECORD',key)
        if not base or not final or (int(base,16)+add)&0xffffffff!=int(final,16) or row.get('physical_field_overlap_count')!=1:
            block('UNPROVED_BASE_ADDEND_OR_OVERLAP',key);continue
        if row.get('proof_consistency')!='EXACT_OWN_SOURCE_RESOLUTION':
            block('NONEXACT_FIELD_PROOF',key)
        if any(word in cls for word in ('EH_','TLS','UNSUPPORTED','SECTION_INDEX','IMAGE_RELATIVE')) or target['section']==-1:
            block('SPECIAL_FRAME_OR_COMPILER_REFERENCE',dict(field=key,classification=cls))
        import_spelling=target['name'].startswith(('__imp_','_imp__'))
        authentic_iat=cls=='IAT_POINTER_CELL_NOT_FUNCTION_BODY' and row.get('import_id') is not None
        if row.get('import_pointer_source_conflict') is True or (import_spelling and not authentic_iat) or (cls=='IAT_POINTER_CELL_NOT_FUNCTION_BODY' and not authentic_iat):
            block('IAT_ROLE_CONFLICT_OR_UNPROVED_CELL',dict(field=key,classification=cls,import_id=row.get('import_id'),source_conflict=row.get('import_pointer_source_conflict')))
        role=('iat-cell' if authentic_iat else
              'crt-contract' if 'CRT' in cls else 'code' if 'CODE' in cls or 'EXECUTABLE' in cls else 'data')
        fact=(base,role)
        if si in bases and bases[si]!=fact:block('CONFLICTING_PHYSICAL_SYMBOL_BASE',dict(symbol_index=si,bases=[bases[si],fact]))
        bases[si]=fact
        if target['aux_count'] or target['storage'] not in (2,3) or (target['section']==0 and target['value']):
            block('UNSUPPORTED_REFERENCE_RECORD',si);continue
        if target['section'] in keep:
            if target['section']==f['section']:
                expected=(int(f['original_address'],16)+target['value'])&0xffffffff
                if int(base,16)!=expected:block('LOCAL_BASE_IDENTITY_CONFLICT',si)
                name=names.get(si) # root or exact static offset remains local.
            else:
                name=canonical(dict(recipe_id=contract['recipe_id'],object_sha256=contract['object_sha256'],symbol_index=si))
        else:
            if target['section']>0:
                ts=secs[target['section']]
                if ts['name'].startswith(('.text$x','.xdata','.pdata','.tls','.CRT')):
                    block('UNSUPPORTED_OMITTED_TARGET_CONVERSION',si)
                undef.add(si)
            provider=contract.get('provider_identities',{}).get(base)
            name=canonical(provider) if provider and role=='code' else unresolved(base,role)
            obligations.append(dict(symbol_index=si,original_base=base,original_target=final,role=role,classification=cls,
                                    kind=kind,field_offset=off,addend_bits=raw,canonical_name=name,import_id=row.get('import_id'),provider_selected=False))
        if name:
            if si in names and names[si]!=name:block('CONFLICTING_PHYSICAL_SYMBOL_NAME',si)
            names[si]=name
    if sorted(seen)!=sorted(actual):block('MISSING_OR_DUPLICATE_FIELD_COVERAGE',dict(expected=actual,observed=seen))
    # Only named bases are external; retained local labels keep original offsets.
    ky=set()
    for secid in keep:ky.update(ix['members'][secid])
    ky.update(r[1] for r in actual); ky.update(ix['metadata'])
    # Every external selected record needs its immutable definition/reference name.
    for i in ky:
        if syms[i]['storage']==2 and i not in names:block('UNNAMESPACED_EXTERNAL',i)
    if len(set(names.values()))!=len(names):block('CANONICAL_NAMESPACE_COLLISION',sorted(names.items()))
    plan=dict(sections=sorted(keep),symbols=sorted(ky),undefined=sorted(undef),bindings=sorted(names.items()))
    return dict(schema_version=1,policy_id=POLICY_ID,candidate_eligible=not blockers,blockers=blockers,obligations=obligations,
                observations=dict(whole_section_extent=section['size']==f['size'] and f['value']==0,flags=section['flags'],
                    COMDAT=[list(t) for _,t in a],local_symbols=locals_,associations=visited and sorted(visited) or [],
                    debug_exclusions=drops,directives=ix['directives'],selected=f),extraction_plan=plan)


def extract_member(data,contract):
    assessment=assess_member(data,contract)
    require(assessment['candidate_eligible'],'blocked member: '+','.join(b['code'] for b in assessment['blockers']))
    plan=assessment['extraction_plan']; named=coff.namespace(data,plan['bindings'])
    out,mapping=coff.serialize(named,plan['sections'],plan['symbols'],plan['undefined'])
    before=coff.parse(data); after=coff.parse(out); sm=mapping['section_map']; ym=mapping['symbol_map']
    # The independent existing inventory reader is used by the disk driver too.
    dispositions=[]
    for i,s in before['symbols'].items():
        disposition=('converted undefined obligation' if i in plan['undefined'] else
                     'retained definition' if i in ym and s['section']>0 and s['storage']==2 else
                     'retained local record' if i in ym else 'explicitly omitted unselected definition/debug record')
        dispositions.append(dict(symbol_index=i,name=s['name'],section=s['section'],disposition=disposition,auxiliary_indices=list(range(i+1,i+1+s['aux_count']))))
    section_dispositions=[dict(section=i,name=s['name'],size=s['size'],flags=s['flags'],payload_sha256=digest(s['payload']),
        disposition='retained' if i in sm else 'explicitly omitted unselected/unverified content',
        association=[list(a) for _,a in index_object(before)['aux'].get(i,[])]) for i,s in before['sections'].items()]
    return out,dict(assessment=assessment,mapping=mapping,source_object_sha256=digest(data),output_sha256=digest(out),
        symbol_dispositions=dispositions,section_dispositions=section_dispositions,exports=coff.exports(out),
        undefined_symbols=[s['name'] for s in after['symbols'].values() if s['storage']==2 and s['section']==0],
        provider_selected=False,runtime_eligible=False,link_ready=False,materialization_approved=False)


PINS=dict(recipes='62f2c8da5f0daa912abdf4576328706711c6561eef7f01c93a89cb71ad46fb6c',
    manifest='bc62a5fb2553431b1e0547d11f366e52efb73096ea8ceb206c556ae5740a53eb',
    retained='04d44b73e81982f846bfe8d81806db72ea669586b579ff22007dfd6f7d831297',
    selection='48ae62cdc5b1754b9c4af674ef4716d53afb554882e174a93acf860eaf1c6cb1',
    binding='275714631903758efbf5a4f82e2428c6f51838f53b90d0c56d2e5dec5da1d804',
    binding_details='4dfc437064b16c1bb933008aebf7def8d279a903eef9cca24d0fedcc12d7d826',
    data_owners='fac1496a2675e9a6b697d604c8d5b35a2e4b8bb6194e2ec823e5a37d1092f2e8',
    data_details='c54abfd434ac715a16d31711fa8afb498d4b41420bec3bfcc25347d0eab9bd08',
    eh_roles='1e08ae8a908dc0a9d7feba4e5fa3cbcfe3a5f9ed6be3004ed6ac8639497fd788',
    reference='df1788907c6e26ef4df0b448ead526825336356b5606650165a1ce0825097eb7',
    proposal='6cebda8327da0afafd6779682fef4c56b6cf90cd40060b0b23fc34f61f15250b')
OWNED=('tools/rebuild/coff_code_archive.py','tools/rebuild/runtime_code_pool.py',
       'tests/rebuild/test_coff_code_archive.py','tests/rebuild/test_runtime_code_pool.py',
       'runtime/code-pools/initial-unresolved.json','docs/rebuild/RUNTIME-CODE-POOL.md')


def file_hash(path):
    h=hashlib.sha256()
    with Path(path).open('rb') as f:
        for part in iter(lambda:f.read(1024*1024),b''):h.update(part)
    return h.hexdigest()


def observe(path,expected,observed):
    path=Path(path).resolve(); require(file_hash(path)==expected,'stale pinned input: '+path.name)
    observed[path]=expected
    return path


def stable(observed,index_path):
    require(not index_path.exists(),'optional index state changed')
    require(all(file_hash(p)==h for p,h in observed.items()),'pinned input changed during operation')


def approved_review(path,expected_sha256,observed):
    """Explicit phase receipt supplied after independent source/schema review."""
    path=observe(path,expected_sha256,observed); review=json.loads(path.read_text())
    require(review.get('phase')=='bounded-three-member-emission' and review.get('approved') is True and
            review.get('independent_source_schema_review_pass') is True and review.get('root_authorized') is True,
            'independent review and root emission authorization required')
    require(set(review.get('source_sha256',{}))==set(OWNED),'incomplete reviewed source set')
    for relative in OWNED:observe(ROOT/relative,review['source_sha256'][relative],observed)
    return review


def verify_basis(paths,policy,observed):
    """Pin exact approved inputs/producers and six source-built physical owners."""
    for name,expected in PINS.items():observe(paths[name],expected,observed)
    for relative,expected in READER_DEPENDENCIES.items():observe(ROOT/relative,expected,observed)
    loaded={name:json.loads(Path(paths[name]).read_text(encoding='utf-8-sig')) for name in
            ('recipes','manifest','retained','selection','binding','data_owners','eh_roles')}
    m,v,s=loaded['manifest'],loaded['retained'],loaded['selection']
    require(m['kind']=='fnv-retained-objects' and m['recipe_manifest_sha256']==PINS['recipes'],'manifest recipe gate')
    require(v['scope']['full_authoritative'] is True and all(v[k] is True for k in
        ('retained_verification_pass','function_byte_verification_pass','global_listed_eh_coverage_pass','original_oracle_parity_pass','evidence_stable')),'retained gates')
    require(v['inputs']['retained_manifest_sha256']==PINS['manifest'] and v['inputs']['recipe_sha256']==PINS['recipes'] and
            v['inputs']['image_sha256']==PINS['reference'],'retained input bindings')
    require(not v['inputs']['function_index_present'] and v['inputs']['function_index_sha256'] is None and not s['function_index_present'] and
            s['runtime_eligible'] is False and s['link_ready'] is False,'optional index/selection state')
    require(s['input_sha256']['recipe']==PINS['recipes'] and s['input_sha256']['manifest']==PINS['manifest'] and s['input_sha256']['receipt']==PINS['retained'],'selection inputs')
    for name,h in v['inputs']['tools_sha256'].items():
        p=(ROOT/name).resolve();require(p.is_relative_to(ROOT),'producer tool escapes checkout');observe(p,h,observed)
    observe(ROOT/'build/image_check.json',v['inputs']['image_check_sha256'],observed)
    for name,relative in [('binding','tools/rebuild/runtime_bind_plan.py'),('data_owners','tools/rebuild/runtime_data_owners.py')]:
        report=loaded[name]
        observe(ROOT/relative,report['implementation_sha256'],observed)
    for name,h in loaded['eh_roles']['inputs']['tools_sha256'].items():
        p=(ROOT/name).resolve();require(p.is_relative_to(ROOT),'EH producer escape');observe(p,h,observed)
    require(loaded['binding']['details_sha256']==PINS['binding_details'] and loaded['data_owners']['details_sha256']==PINS['data_details'], 'detail/report binding')
    require(loaded['binding']['inputs']['retained']==PINS['retained'] and loaded['binding']['inputs']['selection']==PINS['selection'] and
            loaded['data_owners']['inputs']['binding']==PINS['binding'],'binding/owner proof joins')
    require(policy['proposal_sha256']==PINS['proposal'] and policy['policy_id']==POLICY_ID and len(policy['members'])==6,'fixed policy identity')
    addresses={x['selected']['original_address'] for x in policy['members']}
    require(addresses=={'0x00be0b90','0x00646d00','0x00aa13e0','0x00a28740','0x0043fd40','0x00aa0fc0'},'fixed batch identities')
    require(policy['expected_counts']==EXPECTED_COUNTS and all((r['expected_eligible'],r['required_blocker'])==BATCH_STATUS[r['selected']['original_address']] for r in policy['members']),'fixed quarantine/status contract')
    fields=defaultdict(list);missing=defaultdict(list)
    with gzip.open(paths['binding_details'],'rt',encoding='utf-8') as stream:
        for line in stream:
            row=json.loads(line); a=row.get('function_va')
            if a in addresses:
                if row['event']=='SELECTED_FUNCTION_COFF_RELOCATION':fields[a].append(row)
                elif row['event']=='MISSING_ORIGINAL_HIGHLOW_SOURCE_MIGRATION_BLOCKER':missing[a].append(row)
                else:raise ValueError('unknown selected binding detail event')
    result=[]
    for member in policy['members']:
        a=member['selected']['original_address'];f=member['selected'];ri=member['recipe_index'];selected=s['selections'][a]
        require(all(selected[k]==f[k] for k in ('symbol','section','value','size')) and selected['recipe_id']==member['recipe_id'] and selected['recipe_index']==ri,'selected proof identity')
        mus=[u for u in m['units'] if u['recipe_index']==ri];vus=[u for u in v['units'] if u['recipe_index']==ri]
        require(len(mus)==len(vus)==1,'duplicate/missing recipe proof');mu,vu=mus[0],vus[0]
        require(mu['recipe']==loaded['recipes']['units'][ri] and mu['status']=='compiled' and vu['status']=='ok' and
                mu['recipe_id']==vu['recipe_id']==member['recipe_id'],'authoritative recipe mismatch')
        require(mu['object_sha256']==vu['object_sha256']==member['object_sha256'] and mu['source_sha256']==vu['source_sha256_recorded']==vu['source_sha256_current']==member['source_sha256'],'exact source/object proof mismatch')
        require(mu['source']==member['source'],'source identity mismatch')
        source=(ROOT/member['source']).resolve();require(source.is_relative_to(ROOT),'source escape');observe(source,member['source_sha256'],observed)
        obj=(Path(paths['manifest']).resolve().parent/mu['object']).resolve()
        require(obj.is_relative_to(Path(paths['manifest']).resolve().parent),'object manifest escape');observe(obj,member['object_sha256'],observed)
        proof=dict(symbol=f['symbol'],address=a,size=f['size'],section=f['section'],value=f['value'],verdict='match')
        require(vu['verified_functions'].count(proof)==1,'exact v3 function span missing')
        expected=[dict(offset=r['physical_offset'],symbol_index=r['coff_relocation']['symbol_index'],kind=r['coff_relocation']['kind'],base=r['derived_source_symbol_base_va'],original_target=r['exact_original_target_va'],addend=r['coff_relocation']['addend']) for r in fields[a]]
        require(expected==member['expected_fields'],'fixed field contract changed')
        contract=dict(member,verified_match=True,fields_complete=True,missing_fields_complete=True,fields=fields[a],missing_fields=missing[a])
        result.append((obj,contract,mu['recipe']))
    return result


def compare_member(path,reference,contract,unit,receipt=None):
    """Fresh unchanged oracle comparison with explicit names-to-original bases."""
    sys.path.insert(0,str(ROOT/'tools'))
    import compare as oracle
    from build_and_match import image_ok
    pe=oracle.Pe(reference); require(image_ok(pe)[0],'unchanged reference fingerprint gate')
    f=contract['selected']; spec=dict(symbol=f['symbol'],address=f['original_address'],size=f['size'])
    symbols=dict(unit.get('symbols',{}))
    if receipt is not None:
        names=dict(receipt['assessment']['extraction_plan']['bindings']);spec['symbol']=names[f['symbol_index']]
        symbols[spec['symbol']]=f['original_address']
        for row in contract['fields']:
            index=row['coff_relocation']['symbol_index']
            if index in names:symbols[names[index]]=row['derived_source_symbol_base_va']
    report=oracle.compare(oracle.Coff(path),pe,dict(functions=[spec],symbols=symbols,literal_symbols=[]))[0]
    require(report['verdict']=='match' and report['compiled_extent']==f['size'] and not report['errors'] and not report['byte_differences'],'fresh unchanged comparison failed')
    require(all(r['match'] for r in report['relocations']),'fresh relocation comparison failed')
    return {k:v for k,v in report.items() if k!='byte_differences'}


def fsynced(path,data):
    with Path(path).open('xb') as f:f.write(data);f.flush();os.fsync(f.fileno())


def emit_bounded(paths,policy_path,review_path,review_hash,output_dir):
    """Exclusive private run directory; partial crash artifacts retained, never replayed."""
    observed={};approved_review(review_path,review_hash,observed)
    policy_path=Path(policy_path).resolve()
    require(policy_path==ROOT/'runtime/code-pools/initial-unresolved.json','fixed public policy required')
    policy=json.loads(policy_path.read_text()); index=ROOT/'build/function_index.json';require(not index.exists(),'optional index unexpectedly present')
    basis=verify_basis(paths,policy,observed); stable(observed,index)
    out=Path(output_dir).resolve();private=(ROOT/'build/rebuild').resolve()
    require(out.is_relative_to(private) and out!=private and not out.exists() and not any(p.is_relative_to(out) for p in observed),'new exclusive private output directory required')
    out.mkdir(); progress=(out/'progress.jsonl').open('x',encoding='utf-8')
    def note(row):progress.write(json.dumps(row,sort_keys=True)+'\n');progress.flush();os.fsync(progress.fileno())
    note(dict(state='started',policy_sha256=file_hash(policy_path),review_sha256=review_hash,inputs={str(p):h for p,h in observed.items()},optional_index_present=False))
    members=[];receipts=[]
    try:
        from coff_rewrite import strict_object
        preflight=[]
        for obj,contract,unit in basis:
            raw=obj.read_bytes();assessment=assess_member(raw,contract);a=contract['selected']['original_address'];preflight.append((obj,contract,unit,assessment))
            note(dict(state='assessed',address=a,eligible=assessment['candidate_eligible'],reasons=[b['code'] for b in assessment['blockers']]))
        require(all(r['candidate_eligible']==c['expected_eligible'] for _,c,_,r in preflight),'unexpected positive/negative assessment; no member emitted')
        for obj,contract,unit,assessment in preflight:
            raw=obj.read_bytes();a=contract['selected']['original_address']
            require(digest(raw)==contract['object_sha256'],'object changed after preflight')
            if not contract['expected_eligible']:
                require(contract['required_blocker'] in {b['code'] for b in assessment['blockers']},'negative regression blocker absent')
                receipts.append(dict(original_address=a,assessment=assessment,emitted=False));note(dict(state='blocked',address=a,reasons=[b['code'] for b in assessment['blockers']]))
                continue
            before=compare_member(obj,paths['reference'],contract,unit)
            data,receipt=extract_member(raw,contract); name=contract['recipe_id']+'.obj'
            stage=out/(name+'.stage');fsynced(stage,data)
            # Reparse by the separately authored inventory parser, not writer reader alone.
            parsed=strict_object(stage)[0]; own=coff.parse(data)
            require(len(parsed.sections)==len(own['sections']) and len(parsed.symbols)==len(own['symbols']),'independent COFF reader count')
            for i,s in parsed.sections.items():
                expected=own['sections'][i]
                require(s['name']==expected['name'] and s['flags']==expected['flags'] and s['size']==expected['size'] and s['relocs']==expected['relocs'] and s['payload_sha256']==digest(expected['payload']),'independent COFF section difference')
            for i,s in parsed.symbols.items():
                require(all(s[k]==own['symbols'][i][k] for k in ('name','value','section','type','storage','aux_count')),'independent COFF symbol difference')
            receipt.update(original_address=a,emitted=True,comparison_before=before,comparison_after=compare_member(stage,paths['reference'],contract,unit,receipt),independent_inventory_reparse=True)
            members.append((name,data));receipts.append(receipt);note(dict(state='member-verified',address=a,member=name,sha256=digest(data)))
        counts=dict(assessed=len(receipts),emitted=len(members),quarantined=sum(not r['emitted'] for r in receipts),
            checked_code_bytes=sum(c['selected']['size'] for _,c,_,_ in preflight if c['expected_eligible']),
            retained_literal_bytes=sum(coff.parse(data)['sections'][i]['size'] for _,data in members
                for i,s in coff.parse(data)['sections'].items() if s['name']=='.rdata'))
        require(counts==EXPECTED_COUNTS,'fixed member/byte accounting differs')
        archive=coff.archive(members);recovered=coff.read_archive(archive)
        require(recovered['members']==members,'archive extraction differs')
        # Archive extraction is independently reparsed from staged recovered files too.
        for name,data in recovered['members']:
            recovered_path=out/(name+'.recovered');fsynced(recovered_path,data);strict_object(recovered_path)
        stable(observed,index)
        artifact=out/'code-pool.lib';fsynced(artifact,archive)
        report=dict(schema_version=1,kind='fnv-private-unresolved-code-pool',policy_id=POLICY_ID,status='pass',
            archive_sha256=digest(archive),members=[dict(name=n,sha256=digest(d)) for n,d in members],export_index=recovered['index'],
            assessments=receipts,inputs={str(p):h for p,h in observed.items()},optional_index_present=False,
            native_archive_conformance_verified=False,reference_comparison_pass=True,independent_reparse=True,
            provider_selected=False,runtime_eligible=False,link_ready=False,materialization_approved=False,execution_performed=False,
            all_size_accounting_performed=False,scope='Six assessed identities: three emitted, allocator weak-aux quarantine, EH parent and missing-field constructor blocked; unresolved archive, not executable.',
            counts=counts)
        stable(observed,index);fsynced(out/'receipt.json',(json.dumps(report,indent=2)+'\n').encode())
        note(dict(state='complete',archive_sha256=digest(archive),receipt_sha256=file_hash(out/'receipt.json')))
        return report
    except BaseException as e:
        note(dict(state='failed',error_type=type(e).__name__,message=str(e)));raise
    finally:progress.close()


def main():
    p=argparse.ArgumentParser(description=__doc__)
    for name in PINS:p.add_argument('--'+name.replace('_','-'),required=True,type=Path)
    p.add_argument('--policy',type=Path,default=ROOT/'runtime/code-pools/initial-unresolved.json')
    p.add_argument('--review',required=True,type=Path);p.add_argument('--review-sha256',required=True)
    p.add_argument('--output-dir',required=True,type=Path)
    a=p.parse_args();result=emit_bounded({n:getattr(a,n) for n in PINS},a.policy,a.review,a.review_sha256,a.output_dir)
    print(json.dumps(dict(status=result['status'],archive_sha256=result['archive_sha256'],native_conformance=False)))


if __name__=='__main__':main()
