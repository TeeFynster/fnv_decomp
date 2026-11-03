"""Selected-root COFF omission observer. No rewrite, emission or native process."""
from __future__ import annotations
import argparse
from collections import Counter,defaultdict,deque
import gzip
import hashlib
import importlib
import json
import os
from pathlib import Path
import re
import struct
import time
from runtime_code_inventory import EXPECTED,BindingReader,check_unit,selected_rows,canonical,digest,public_metadata
from runtime_gaps import read_bound
from data_plan import file_hash
from import_plan import ROOT,require
from coff_inventory import reconcile_recipes

POLICY='root-code-closure-observation-v2'
IMPORT_PIN='e39b8db63ef73aea57b5dd4963ff29310524644ca36e137cd8b5461a3c90a23f'
IAT_SOURCE_NAME='__imp__GetForegroundWindow@0'
EXPORT_POLICY='selected-code-only-no-source-initializers-v1'
TARGETS={'0x0086a850':('0576-dd603b7071c482c6',1215,199,4532),'0x00aa13e0':('2734-15835374a1b91660',141,41,62)}
PARSER_PIN='76244d2d4dca4c1f8aa72224be1ef5c92f68976b5cda7d31b5cfe23d3cc29e64'
INVENTORY_TOOL_PIN='c2fdbd52b4b7f4b7c68f9d80ad03708ba57d42b29e5938dfcf9769366a1ffd0b'
FALSE=dict(emission_performed=False,runtime_eligible=False,provider_selected=False,ABI_verified=False,link_ready=False,namespace_approved=False)
DEFAULTS=['/DEFAULTLIB:"LIBCMT"','/DEFAULTLIB:"OLDNAMES"']


def refine_omissions(obj,contract,required,runtime,weak,directive_roots,block,edge):
    """Only reviewed omitted LABEL and original import175 undefined-record forms."""
    syms=obj['symbols'];secs=obj['sections'];labels=set();redundant=set();facts=[]
    incoming=defaultdict(list);same_name=defaultdict(list);sx=set()
    for i,s in syms.items():same_name[s['name']].append(i)
    for secid,sec in secs.items():
        for off,si,kind in sec['relocs']:incoming[si].append((secid,off,si,kind))
        if sec['name']=='.sxdata' and len(sec['payload'])%4==0:
            sx.update(struct.unpack_from('<I',sec['payload'],off)[0] for off in range(0,len(sec['payload']),4))
    proof_rows=contract['omission_field_proofs'];row_map={};duplicate=set()
    for row in proof_rows:
        cr=row['coff_relocation'];key=(row['physical_section'],cr['offset'],cr['symbol_index'],cr['kind'])
        if key in row_map:duplicate.add(key)
        row_map[key]=row
    functions=contract['unit_verified_functions']
    def prove_use(key,target,mode):
        secid,off,si,kind=key;sec=secs[secid];row=row_map.get(key)
        if key in duplicate or not row or kind!=6 or off<0 or off+4>len(sec['payload']):return None
        owners=[f for f in functions if f['section']==secid and f['value']==0 and f['size']==sec['size'] and f['verdict']=='match']
        if len(owners)!=1:return None
        owner=owners[0];cr=row['coff_relocation'];raw=int.from_bytes(sec['payload'][off:off+4],'little')
        if raw!=0 or (row['recipe_id'],row['function_va'],row['physical_offset'],row['source_field_offset'],row['original_field_va'])!=(contract['recipe_id'],owner['address'],off,off,'0x%08x'%(int(owner['address'],16)+off)):return None
        if (cr['symbol'],cr['symbol_section'],cr['symbol_value'],cr['symbol_type'],cr['symbol_storage'],cr['addend'])!=(target['name'],target['section'],target['value'],target['type'],target['storage'],0):return None
        if row['proof_consistency']!='EXACT_OWN_SOURCE_RESOLUTION' or row['physical_field_overlap_count']!=1:return None
        expected=('0x%08x'%(int(owner['address'],16)+target['value'])) if mode=='label' else '0x00fdf2fc'
        if row.get('derived_source_symbol_base_va')!=expected or row.get('exact_original_target_va')!=expected:return None
        if mode=='label' and row['classification']!='UNIQUE_CODE_INTERIOR_OR_LOCAL_LABEL_NOT_CALLABLE_APPROVAL':return None
        if mode=='iat' and (row['classification']!='IAT_POINTER_CELL_NOT_FUNCTION_BODY' or row.get('import_id')!=175 or row.get('import_pointer_source_conflict')is True):return None
        return dict(section=secid,offset=off,symbol_index=si,kind=kind,owner_original_address=owner['address'],
            original_base=expected,original_target=expected,addend_bits=0,binding_row_sha256=digest(row))
    def complete_uses(indices,mode):
        keys=[key for i in indices for key in incoming[i]]
        if any(not incoming[i] for i in indices):return None
        provided=[key for key in row_map if key[2] in indices]
        if set(keys)!=set(provided) or len(keys)!=len(set(keys)):return None
        observed=[prove_use(key,syms[key[2]],mode) for key in keys]
        return observed if all(o is not None for o in observed) else None
    for i,s in syms.items():
        if s['storage']!=6:continue
        sec=secs.get(s['section']);uses=incoming[i]
        known=bool(sec and s['type']==0 and not s['aux_count'] and re.fullmatch(r'\$LN[0-9]+',s['name']) and
            sec['name']=='.text' and sec['flags']==0x60501020 and 0<=s['value']<sec['size'])
        relations=[syms[j] for j in same_name[s['name']]]
        safe_names=all(t['storage'] in (3,6) and t['type']==0 and not t['aux_count'] and t['section']>0 and
            t['section'] not in runtime and secs[t['section']]['name']=='.text' and secs[t['section']]['flags']==0x60501020 and
            0<=t['value']<secs[t['section']]['size'] for t in relations)
        unreachable=(i not in required and s['section'] not in runtime and i not in weak.values() and i not in sx and
            i not in directive_roots and uses and all(key[0]==s['section'] and key[0] not in runtime for key in uses))
        proof=complete_uses([i],'label') if known and safe_names and unreachable else None
        if proof is None:block('LABEL_OMISSION_NOT_PROVED',i)
        else:
            labels.add(i);facts.append(dict(kind='PROVED_OMITTED_LOCAL_LABEL',symbol_index=i,section=s['section'],value=s['value'],
                same_name_physical_indices=same_name[s['name']],uses=proof))
    group=same_name.get(IAT_SOURCE_NAME,[])
    if len(group)>1 and set(group)&required:
        candidates=[i for i in group if i not in required]
        if candidates:
            ordinary=all((syms[i]['section'],syms[i]['value'],syms[i]['type'],syms[i]['storage'],syms[i]['aux_count'])==(0,0,0,2,0) for i in group)
            imported=contract.get('iat_import_observation') or {}
            authentic=(imported.get('import_id')==175 and imported.get('original_IAT_va')=='0x00fdf2fc' and imported.get('dll')=='USER32.dll' and
                imported.get('export')==dict(kind='name',name='GetActiveWindow',hint=249) and
                imported.get('representation')=='IAT_POINTER_CELL_NOT_FUNCTION_BODY' and
                imported.get('required_provider_contract',{}).get('runtime_provider_selected')is False)
            proof=complete_uses(group,'iat') if ordinary and authentic else None
            safe=(proof is not None and len(set(group)&required)==1 and all(i not in weak.values() and i not in sx and i not in directive_roots and
                all(key[0] not in runtime for key in incoming[i]) for i in candidates))
            if safe:
                redundant.update(candidates);facts.append(dict(kind='PROVED_REDUNDANT_UNDEFINED_IAT_REFERENCE',omitted_indices=candidates,
                    retained_indices=sorted(set(group)&required),all_group_indices=group,original_IAT_va='0x00fdf2fc',import_id=175,
                    actual_dll='USER32.dll',actual_export='GetActiveWindow',uses=proof,provider_selected=False))
            else:block('REDUNDANT_IAT_OMISSION_NOT_PROVED',dict(indices=group))
        else:block('REQUIRED_IAT_DUPLICATE_REQUIRES_NAMESPACE_POLICY',dict(indices=group))
    return labels,redundant,facts


def assess_object(obj,contract):
    """Pure metadata certificate. Parser is separately pinned by the driver."""
    require(contract['export_policy']==EXPORT_POLICY and contract['fields_complete']is True and
            contract['missing_fields_complete']is True and contract['verified_match']is True and contract['unit_proofs_complete']is True,'incomplete closure contract')
    secs=obj['sections'];syms=obj['symbols'];roots=contract['roots'];require(roots,'empty selected root set')
    blockers=[];edges=[];aux={};children=defaultdict(list);section_aux=defaultdict(list);weak={};names=defaultdict(list)
    def block(code,evidence):blockers.append(dict(code=code,evidence=public_metadata(evidence)))
    def edge(kind,source,target):edges.append(dict(kind=kind,source=source,target=target))
    def primary(i):return i in syms
    section_forms={
        '.text':{0x60501020},'.text$yd':{0x60501020},'.text$x':{0x60501020},
        '.xdata$x':{0x40301040},'.rdata':{0x40301040,0x40401040,0x40400040},'.rdata$r':{0x40301040},
        '.data':{0xc0301040,0xc0300040},'.bss':{0xc0300080,0xc0301080},
        '.debug$S':{0x42100040},'.debug$F':{0x42101040},'.drectve':{0x100a00},'.sxdata':{0x300200}}
    for i,sec in secs.items():
        if sec['flags'] not in section_forms.get(sec['name'],set()):block('UNSUPPORTED_SECTION_SEMANTICS',dict(section=i,name=sec['name'],flags=sec['flags']))
        for off,si,kind in sec['relocs']:
            width={0:0,1:2,2:2,6:4,7:4,9:2,10:2,11:4,12:4,13:1,20:4}.get(kind)
            if si not in syms or width is None or off<0 or off+width>sec['size']:block('INVALID_PHYSICAL_RELOCATION',dict(section=i,offset=off,symbol_index=si,kind=kind))
            edge('PHYSICAL_SECTION_RELOCATION',dict(section=i,offset=off,kind=kind,width=width),si)
    def is_section_symbol(s):return s['storage']==3 and s['section']>0 and s['name']==secs[s['section']]['name'] and s['type']==0 and s['value']==0
    for i,s in syms.items():
        known=(s['type'] in (0,32) and ((s['storage'] in (2,3,6) and s['section']>=0) or
            (s['storage']==105 and s['section']==0) or
            (s['storage']==103 and s['section']==-2 and s['type']==0 and s['value']==0 and s['aux_count']>0) or
            (s['name'] in ('@feat.00','@comp.id') and s['section']==-1 and s['storage']==3 and s['type']==0)))
        if not known:block('UNSUPPORTED_SYMBOL_SEMANTICS',dict(symbol_index=i,storage=s['storage'],section=s['section'],type=s['type']))
        if s['section']>0 and not 0<=s['value']<=secs[s['section']]['size']:block('SYMBOL_VALUE_OUTSIDE_SECTION',i)
        if not is_section_symbol(s) and s['storage']!=103 and s['name'] not in ('@feat.00','@comp.id'):
            if s['storage'] in (2,105) or s['type']==32:names[s['name']].append(i)
        if s['section']>0:edge('SYMBOL_SECTION',i,s['section'])
        if s['aux_count']:edge('PRIMARY_AUXILIARY_SLOTS',i,list(range(i+1,i+1+s['aux_count'])))
        n=s['aux_count'];raw=s['aux'];require(len(raw)==18*n,'auxiliary span differs')
        if s['storage']==105 and not n:block('UNSUPPORTED_WEAK_AUXILIARY',i)
        if s['section']==0 and s['value'] and (s['storage']!=2 or n or s['type']!=0):block('UNSUPPORTED_COMMON_RECORD',i)
        if not n:continue
        if s['storage']==103 and s['section']==-2:
            aux[i]=dict(kind='FILE_DEBUG_PROVENANCE',count=n);continue
        if is_section_symbol(s) and n==1:
            a=struct.unpack('<IHHIhBBH',raw);aux[i]=dict(kind='SECTION_DEFINITION',decoded=list(a));section_aux[s['section']].append((i,a))
            sec=secs[s['section']]
            if a[0]!=sec['size'] or a[1]!=len(sec['relocs']) or a[2] or a[6] or a[7] or a[5] not in range(8):block('UNKNOWN_SECTION_AUXILIARY',i)
            if a[5] and not sec['flags']&0x1000:block('AUXILIARY_COMDAT_FLAG_CONFLICT',i)
            if a[5]==5:
                if a[4] not in secs:block('INVALID_ASSOCIATION_PARENT',i)
                else:children[a[4]].append(s['section']);edge('ASSOCIATION_PARENT',s['section'],a[4]);edge('ASSOCIATION_CHILD',a[4],s['section'])
            elif a[4]:block('HIDDEN_SECTION_AUXILIARY_INDEX',i)
        elif s['storage']==105 and n==1 and s['section']==0 and s['value']==0 and s['type'] in (0,32):
            fallback,search=struct.unpack_from('<II',raw)
            aux[i]=dict(kind='WEAK_EXTERNAL',fallback=fallback,search=search)
            if not primary(fallback) or search!=2 or any(raw[8:]):block('UNSUPPORTED_WEAK_AUXILIARY',i)
            else:weak[i]=fallback;edge('WEAK_FALLBACK',i,fallback)
        else:aux[i]=dict(kind='UNKNOWN',count=n);block('UNKNOWN_HIDDEN_AUXILIARY_INDICES',i)
    for spelling,indices in names.items():
        if len(indices)>1:edge('NAME_EQUIVALENCE_GROUP',spelling,indices)
    for i,sec in secs.items():
        if sec['flags']&0x1000 and len(section_aux[i])!=1:block('MISSING_OR_DUPLICATE_COMDAT_AUXILIARY',i)
    # The full association graph must be acyclic, including omitted sections.
    state={}
    for start in secs:
        stack=[(start,False)]
        while stack:
            node,done=stack.pop()
            if done:state[node]=2;continue
            if state.get(node)==1:block('ASSOCIATION_CYCLE',node);continue
            if state.get(node)==2:continue
            state[node]=1;stack.append((node,True));stack.extend((c,False) for c in children[node])
    for start in weak:
        seen=set();node=start
        while node in weak:
            if node in seen:block('WEAK_FALLBACK_CYCLE',start);break
            seen.add(node);node=weak[node]
    metadata=[]
    for i,s in syms.items():
        if s['name'] in ('@feat.00','@comp.id'):
            if (s['section'],s['type'],s['storage'],s['aux_count'])!=(-1,0,3,0) or (s['name']=='@feat.00' and s['value']!=1):block('UNSUPPORTED_COMPILER_METADATA',i)
            else:metadata.append(i)
    runtime=set();root_indices=set();root_by_section={};seen_addresses=set()
    for r in roots:
        sec=secs.get(r['section']);s=syms.get(r['symbol_index'])
        require(r['original_address'] not in seen_addresses and r['symbol_index'] not in root_indices,'duplicate selected root')
        seen_addresses.add(r['original_address']);root_indices.add(r['symbol_index'])
        if r['section'] in root_by_section:block('SHARED_SELECTED_ROOT_SECTION',r['section'])
        root_by_section[r['section']]=r
        if not sec or not s or (s['name'],s['section'],s['value'],s['type'],s['storage'],s['aux_count'])!=(r['symbol'],r['section'],r['value'],32,2,0):
            block('STALE_ROOT_PHYSICAL_IDENTITY',r);continue
        runtime.add(r['section']);a=section_aux[r['section']]
        if r['value']!=0 or r['size']!=sec['size'] or sec['name']!='.text' or sec['flags']!=0x60501020 or len(a)!=1 or a[0][1][5]!=1:
            block('UNSUPPORTED_OR_PARTIAL_ROOT_SECTION',r)
    debug=set();frontier=list(runtime)
    while frontier:
        parent=frontier.pop()
        for child in children[parent]:
            if child in debug:continue
            s=secs[child];a=section_aux[child]
            valid=(s['name']=='.debug$F' and s['flags']==0x42101040 and s['size']==16 and len(s['relocs'])==1 and
                s['relocs'][0][0]==0 and s['relocs'][0][2]==7 and syms[s['relocs'][0][1]]['section']==parent and
                len(a)==1 and a[0][1][5]==5 and a[0][1][4]==parent)
            if valid:debug.add(child);frontier.append(child)
            else:block('RETAINED_PARENT_EH_OR_UNKNOWN_CHILD',dict(parent=parent,child=child))
    for secid in runtime:
        a=section_aux[secid]
        if any(x[1][5]==5 for x in a):block('RETAINED_CHILD_REQUIRES_PARENT',secid)
    directives=[];directive_sections=[];directive_roots=[]
    for i,sec in secs.items():
        if sec['name']!='.drectve':continue
        directive_sections.append(i)
        try:tokens=re.findall(r'(?:[^\s"\x00]+|"[^"]*")+',sec['payload'].decode('ascii'))
        except UnicodeError:tokens=[];block('NONASCII_DIRECTIVE',i)
        directives+=tokens
        if sec['flags']!=0x100a00 or sec['relocs']:block('UNSUPPORTED_DIRECTIVE_SECTION',i)
        for token in tokens:
            if token in DEFAULTS:edge('DIRECTIVE_LIBRARY_DEPENDENCY',i,token)
            if token not in DEFAULTS:
                block('UNSUPPORTED_IMPLICIT_LINKER_DIRECTIVE',token)
                found=re.match(r'(?i)/(?:include|export|entry|alternatename):(.+)',token)
                if found:
                    for spelling in re.split('[=,]',found.group(1)):
                        matches=[j for j,t in syms.items() if t['name']==spelling];directive_roots+=matches
                        edge('DIRECTIVE_NAME_RESOLUTION',token,dict(name=spelling,symbol_indices=matches))
    if directives!=DEFAULTS or len(directive_sections)!=1:block('DIRECTIVE_CONTRACT_DIFFERS',directives)
    keep_sections=runtime|set(directive_sections)
    required={i for i,s in syms.items() if s['section'] in keep_sections}|set(metadata)
    for i in list(required):
        s=syms[i]
        if s['section'] in runtime and i not in root_indices and not is_section_symbol(s):
            if not(s['storage']==3 and s['type']==0 and not s['aux_count'] and 0<=s['value']<secs[s['section']]['size'] and not s['name'].startswith(('__eh','__unwind','__catch'))):
                block('UNPROVED_RETAINED_ENTRY_OR_ALIAS',i)
    field_map={};rows=contract['fields'];by_symbol=defaultdict(list)
    for row in rows:
        cr=row['coff_relocation'];key=(row['physical_section'],cr['offset'],cr['symbol_index'],cr['kind'])
        if key in field_map:block('DUPLICATE_FIELD_PROOF',key)
        field_map[key]=row
    actual=set();references=[]
    for secid in runtime:
        sec=secs[secid];r=root_by_section[secid]
        for off,si,kind in sec['relocs']:
            key=(secid,off,si,kind);actual.add(key);required.add(si);edge('RETAINED_RELOCATION',dict(section=secid,offset=off,kind=kind),si)
            target=syms[si];row=field_map.get(key)
            if not row:block('MISSING_PHYSICAL_FIELD_PROOF',key);continue
            cr=row['coff_relocation'];raw=int.from_bytes(sec['payload'][off:off+4],'little');add=raw if kind==6 or raw<0x80000000 else raw-0x100000000
            if kind not in (6,20) or off+4>sec['size']:block('UNSUPPORTED_RUNTIME_RELOCATION',key)
            if (row['recipe_id'],row['function_va'],row['physical_offset'],row['source_field_offset'])!=(contract['recipe_id'],r['original_address'],off,off):block('STALE_FIELD_PARENT',key)
            if (cr['symbol'],cr['symbol_section'],cr['symbol_value'],cr['symbol_type'],cr['symbol_storage'],cr['addend'])!=(target['name'],target['section'],target['value'],target['type'],target['storage'],raw):block('CHANGED_FIELD_OR_SYMBOL',key)
            base=row.get('derived_source_symbol_base_va');final=row.get('exact_original_target_va');cls=row.get('classification','')
            if not base or not final or (int(base,16)+add)&0xffffffff!=int(final,16) or row.get('physical_field_overlap_count')!=1 or row.get('proof_consistency')!='EXACT_OWN_SOURCE_RESOLUTION':block('UNPROVED_FIELD_BASE_ADDEND',key)
            if any(word in cls for word in ('EH_','TLS','UNSUPPORTED','SECTION_INDEX','IMAGE_RELATIVE')) or target['section']==-1:block('SPECIAL_RUNTIME_REFERENCE',key)
            authentic=cls=='IAT_POINTER_CELL_NOT_FUNCTION_BODY' and row.get('import_id') is not None
            if row.get('import_pointer_source_conflict')is True or (target['name'].startswith(('__imp_','_imp__')) and not authentic) or (cls=='IAT_POINTER_CELL_NOT_FUNCTION_BODY' and not authentic):block('UNPROVED_IAT_ROLE',key)
            if target['aux_count'] or target['storage'] not in (2,3) or (target['section']==0 and target['value']):block('UNSUPPORTED_LIVE_REFERENCE_RECORD',si)
            if target['section']>0 and target['section'] not in runtime and secs[target['section']]['name'].startswith(('.text$x','.xdata','.pdata','.tls','.CRT')):block('SPECIAL_OMITTED_TARGET_CONVERSION',si)
            role='iat-cell' if authentic else 'crt-contract' if 'CRT' in cls else 'code' if 'CODE' in cls or 'EXECUTABLE' in cls else 'data'
            if target['section'] in runtime and base:
                owner=root_by_section[target['section']]
                if int(base,16)!=(int(owner['original_address'],16)+target['value'])&0xffffffff:block('CONFLICTING_RETAINED_LOCAL_BASE',si)
            by_symbol[si].append((base,role));references.append(dict(section=secid,offset=off,symbol_index=si,kind=kind,addend_bits=raw,
                original_base=base,original_target=final,role=role,binding_row_sha256=digest(row)))
    if set(field_map)!=actual:block('INCOMPLETE_OR_EXTRA_FIELD_PROOF',dict(actual=len(actual),proof=len(field_map)))
    for si,identities in by_symbol.items():
        if len(set(identities))!=1:block('CONFLICTING_PHYSICAL_SYMBOL_IDENTITY',si)
    proved_labels,redundant_iat,refinements=refine_omissions(obj,contract,required,runtime,weak,directive_roots,block,edge)
    # Name equivalence only adds conservative dependencies; it never aliases providers.
    live=set(required)|set(directive_roots);queue=deque(sorted(live))
    while queue:
        i=queue.popleft();s=syms[i]
        adjacent=list(names.get(s['name'],[]))
        if i in weak:adjacent.append(weak[i])
        for j in adjacent:
            if j in redundant_iat:
                edge('PROVED_REDUNDANT_UNDEFINED_IAT_NAME_RELATIONSHIP',i,j);continue
            edge('LIVE_WEAK_FALLBACK' if i in weak and j==weak[i] else 'LIVE_NAME_RESOLUTION',i,j)
            if j not in live:live.add(j);queue.append(j)
    for i in live:
        s=syms[i]
        if s['storage']==105:block('REACHABLE_WEAK_REQUIRES_POLICY',i)
        if s['section']==0 and s['value']:block('REACHABLE_COMMON_REQUIRES_STORAGE_OWNER',i)
        if i not in required and i not in metadata and s['storage']!=105:block('UNPROVED_LIVE_NAME_ALIAS',i)
    safeseh=[];sx_sections=[]
    for i,sec in secs.items():
        if sec['name']!='.sxdata':continue
        sx_sections.append(i)
        if sec['flags']!=0x300200 or sec['relocs'] or sec['size']!=len(sec['payload']) or sec['size']%4:block('UNSUPPORTED_SAFESEH_TABLE',i);continue
        if i in keep_sections:block('RETAINED_SAFESEH_TABLE_REQUIRES_ADAPTER',i)
        for off in range(0,sec['size'],4):
            si=struct.unpack_from('<I',sec['payload'],off)[0];target=syms.get(si)
            if not target or target['section']<=0 or target['type']!=32 or target['aux_count'] or not 0<=target['value']<secs[target['section']]['size']:block('INVALID_SAFESEH_INDEX',dict(section=i,offset=off,symbol_index=si));continue
            edge('SAFESEH_INDEX',dict(section=i,offset=off),si)
            entry=dict(section=i,offset=off,symbol_index=si,target_section=target['section'],target_value=target['value'],omission_reason='handler outside retained and name-resolution closure')
            safeseh.append(entry)
            if target['section'] in runtime or si in live:block('LIVE_SAFESEH_HANDLER_REQUIRES_ADAPTER',entry)
    if contract['missing_fields']:block('ORIGINAL_MISSING_FIELDS',len(contract['missing_fields']))
    if contract['parent_eh']:block('PARENT_EH_REQUIRES_CLOSURE_ADAPTER',contract['parent_eh'])
    # Full universe disposition; an unknown record never becomes an approved omission.
    section_rows=[]
    for i,s in secs.items():
        reason=('RETAIN_RUNTIME_CODE' if i in runtime else 'RETAIN_EXACT_DIRECTIVES' if i in directive_sections else
                'OMIT_PROVED_DEBUG_ASSOCIATION' if i in debug else 'OMIT_WHOLE_SAFESEH_CANDIDATE' if i in sx_sections else
                'EXCLUDE_SOURCE_INITIALIZER_OR_SPECIAL_DOMAIN' if s['name'].startswith(('.CRT','.tls','.idata')) else 'EXCLUDE_NONEXPORTED_SECTION')
        section_rows.append(dict(index=i,name=s['name'],extent=s['size'],flags=s['flags'],relocations=len(s['relocs']),relocation_metadata_sha256=digest(s['relocs']),disposition=reason))
    symbol_rows=[];slots=[];conversions=[]
    for i,s in syms.items():
        if i in required:
            reason='RETAIN_SECTION_SYMBOL' if s['section'] in keep_sections else 'RETAIN_ABSOLUTE_METADATA' if i in metadata else 'RETAIN_EXACT_UNDEFINED_REFERENCE'
            if s['section']>0 and s['section'] not in keep_sections:
                reason='CONVERT_EXACT_REFERENCE_TO_UNDEFINED';conversions.append(dict(symbol_index=i,original_section=s['section'],original_value=s['value'],field_indices=[k for k,r in enumerate(references) if r['symbol_index']==i]))
        elif i in proved_labels:reason='OMIT_PROVED_UNREACHABLE_LOCAL_LABEL'
        elif s['storage']==6:reason='BLOCKED_LABEL_WITHOUT_OMISSION_PROOF'
        elif i in redundant_iat:reason='OMIT_PROVED_REDUNDANT_UNDEFINED_IAT_REFERENCE'
        elif s['storage']==105:reason='OMIT_UNREACHABLE_WEAK_CANDIDATE'
        elif s['section']==0 and s['value']:reason='OMIT_UNREACHABLE_COMMON_CANDIDATE'
        elif s['storage']==103:reason='OMIT_FILE_DEBUG_PROVENANCE'
        else:reason='EXCLUDE_NONEXPORTED_SYMBOL'
        row=dict(index=i,name=s['name'],section=s['section'],value=s['value'],type=s['type'],storage=s['storage'],aux_count=s['aux_count'],
            aux_sha256=hashlib.sha256(s['aux']).hexdigest(),decoded_auxiliary=aux.get(i),disposition=reason)
        symbol_rows.append(row);slots.extend(range(i,i+1+s['aux_count']))
    require(sorted(slots)==list(range(obj['symbol_count'])),'physical primary/aux universe has holes')
    retained_slots=sorted(k for i in required for k in range(i,i+1+syms[i]['aux_count']))
    for b in blockers:b['blocker_id']=digest(dict(code=b['code'],evidence=b['evidence']))
    supported_observation_blockers={'REACHABLE_WEAK_REQUIRES_POLICY','REACHABLE_COMMON_REQUIRES_STORAGE_OWNER',
        'ORIGINAL_MISSING_FIELDS','PARENT_EH_REQUIRES_CLOSURE_ADAPTER','LIVE_SAFESEH_HANDLER_REQUIRES_ADAPTER'}
    graph_complete=all(b['code'] in supported_observation_blockers for b in blockers)
    scope=dict(policy_id=POLICY,export_policy=EXPORT_POLICY,provenance_sha256=digest(contract['provenance']),
        contract_identity_sha256=digest(contract),roots=roots,retained_section_indices=sorted(keep_sections),retained_primary_indices=sorted(required),
        retained_physical_slots=retained_slots,edges_sha256=digest(edges),object_sha256=contract['provenance']['object_sha256'])
    extension=[b['blocker_id'] for b in blockers if b['code'] in {'PARENT_EH_REQUIRES_CLOSURE_ADAPTER','LIVE_SAFESEH_HANDLER_REQUIRES_ADAPTER'}]
    subcertificate=dict(policy_id=POLICY,scope=scope,scope_sha256=digest(scope),graph_observation_complete=graph_complete,
        disposition_sha256=digest(dict(sections=section_rows,symbols=symbol_rows)),unresolved_blocker_ids=[b['blocker_id'] for b in blockers],
        exact_EH_SafeSEH_extension_obligation_ids=extension,omission_approved=False,
        limitations=['Observation completeness is not omission or serialization approval.',
                    'Expanded retained scope requires recomputation; unknown children/indices/directives cannot be discharged as EH.'])
    return public_metadata(dict(schema_version=1,policy_id=POLICY,status='observed' if not blockers else 'blocked',closure_observed=not blockers,
        graph_observation_complete=graph_complete,root_closure_candidate=not blockers,full_serialization_eligible=False,omission_subcertificate=subcertificate,
        contract_identity_sha256=digest(contract),provenance=contract['provenance'],recipe_id=contract['recipe_id'],roots=roots,export_policy=EXPORT_POLICY,
        exported_primary_indices=sorted(root_indices),retained_runtime_section_indices=sorted(runtime),retained_section_indices=sorted(keep_sections),retained_primary_indices=sorted(required),retained_physical_slots=retained_slots,
        omission_refinements=refinements,omitted_definition_conversions=conversions,sections=section_rows,symbols=symbol_rows,edges=edges,references=references,
        safeseh=safeseh,missing_field_identities=contract['missing_fields'],parent_EH=contract['parent_eh'],blockers=blockers,
        summary=dict(sections=len(secs),primary_symbols=len(syms),physical_slots=obj['symbol_count'],retained_primary_symbols=len(required),
            edges=dict(Counter(e['kind'] for e in edges)),weak_records=sum(s['storage']==105 for s in syms.values()),safeseh_entries=len(safeseh)),
        initializers_adopted=False,excluded_definitions_exported=False,whole_translation_unit_semantics_preserved=False,
        canonical_namespace_collisions_resolved=False,**FALSE))


def run(args):
    from runtime_code_inventory import pin,stable,output_paths
    root=Path(args.root).resolve();names=('manifest','retained','selection','recipes','binding','imports');pins=dict(EXPECTED,imports=IMPORT_PIN)
    paths={n:Path(getattr(args,n)).resolve() for n in names};data={n:read_bound(paths[n],pins[n]) for n in names}
    manifest,proof,selection,binding=[data[n] for n in ('manifest','retained','selection','binding')]
    require(reconcile_recipes(manifest,paths['recipes'])['verified'],'recipe reconciliation differs')
    require(proof['inputs']['retained_manifest_sha256']==EXPECTED['manifest'] and proof['inputs']['recipe_sha256']==EXPECTED['recipes'] and
        all(proof[k]is True for k in ('retained_verification_pass','function_byte_verification_pass','original_oracle_parity_pass','evidence_stable')),'retained gates differ')
    require(all(binding['inputs'][n]==EXPECTED[n] for n in ('manifest','retained','selection','recipes')) and
        binding['inputs']['reference']==proof['inputs']['image_sha256'],'binding provenance differs')
    require(selection['function_index_present']is False and proof['inputs']['function_index_present']is False,'optional index state differs')
    observations={paths[n]:pins[n] for n in names};detail=Path(args.binding_details).resolve();pin(detail,binding['details_sha256'],observations)
    require(args.parser_sha256==PARSER_PIN,'unreviewed parser hash')
    pin(ROOT/'tools/rebuild/coff_code_archive.py',PARSER_PIN,observations)
    pin(ROOT/'tools/rebuild/runtime_code_inventory.py',INVENTORY_TOOL_PIN,observations)
    for name in ('root_code_closure.py','runtime_gaps.py','data_plan.py','import_plan.py','coff_inventory.py'):
        path=ROOT/'tools/rebuild'/name;pin(path,file_hash(path),observations)
    for name,h in proof['inputs']['tools_sha256'].items():
        path=(ROOT/name).resolve();require(path.is_relative_to(ROOT),'invalid proof tool');pin(path,h,observations)
    coff=importlib.import_module('coff_code_archive');require(Path(coff.__file__).resolve()==ROOT/'tools/rebuild/coff_code_archive.py','unexpected parser module')
    imports=data['imports'];imported=next((i for i in imports['imports'] if i['import_id']==175),None)
    require(imports['inputs']['reference']==proof['inputs']['image_sha256'] and imports['inputs']['manifest']==EXPECTED['manifest'] and imports['inputs']['retained']==EXPECTED['retained'],'import evidence joins differ')
    selected_units={};contracts={};pvmap={p['recipe_index']:p for p in proof['units']}
    for address,(rid,idx,section,size) in TARGETS.items():
        ch=selection['selections'][address];unit=manifest['units'][ch['recipe_index']];pv=pvmap[ch['recipe_index']];check_unit(unit,pv)
        require(unit['recipe_id']==rid and (ch['section'],ch['size'],ch['value'])==(section,size,0),'fixed pilot target differs')
        src=(root/unit['source']).resolve();obj=(paths['manifest'].parent/manifest.get('object_root_relative','.')/unit['object']).resolve()
        require(src.is_relative_to(root),'invalid source path');pin(src,unit['source_sha256'],observations)
        observations[obj]=unit['object_sha256'];selected_units[unit['recipe_index']]=(unit,pv,obj)
        roots=[dict(original_address=address,symbol=ch['symbol'],symbol_index=idx,section=section,value=0,size=size)]
        contracts[unit['recipe_index']]=dict(recipe_id=rid,roots=roots,export_policy=EXPORT_POLICY,verified_match=True,
            fields_complete=True,missing_fields_complete=True,unit_proofs_complete=True,fields=[],missing_fields=[],
            omission_field_proofs=[],unit_verified_functions=pv['verified_functions'],iat_import_observation=imported,
            parent_eh=[p for p in pv.get('eh_sections',[]) if p[3]==address],provenance={})
    index=root/'build/function_index.json';require(not index.exists(),'optional index appeared')
    out,details,progress=output_paths(args.out,args.details_gz,observations);progress.parent.mkdir(parents=True,exist_ok=True)
    created=[];start=time.monotonic()
    with progress.open('x',encoding='utf-8') as journal:
        def note(value):journal.write(json.dumps(dict(elapsed_seconds=round(time.monotonic()-start,3),**value))+'\n');journal.flush();os.fsync(journal.fileno())
        note(dict(state='started',policy_id=POLICY,parser_sha256=PARSER_PIN))
        try:
            # Complete saved metadata stream consumed; only the two named objects are opened later.
            with gzip.open(detail,'rt',encoding='utf-8') as stream:
                reader=BindingReader(stream,binding['summary'],selection['selections'])
                for unit in manifest['units']:
                    group=reader.take(unit['recipe_index'])
                    if unit['recipe_index'] in contracts:
                        contract=contracts[unit['recipe_index']];addr=contract['roots'][0]['original_address']
                        bucket=group.get(addr,dict(fields=[],missing_fields=[],row_identities=[]))
                        contract.update(fields=bucket['fields'],missing_fields=bucket['missing_fields'])
                        contract['omission_field_proofs']=[r for b in group.values() for r in b['fields'] if r['coff_relocation']['symbol_storage']==6 or r['coff_relocation']['symbol']==IAT_SOURCE_NAME]
                        contract['provenance']['omission_binding_row_references']=[r for b in group.values() for r in b['row_identities']]

                        contract['provenance']['binding_row_references']=bucket['row_identities']
                stream_provenance=reader.finish()
            certificates=[]
            for recipe_index,(unit,pv,path) in sorted(selected_units.items()):
                raw=path.read_bytes();require(hashlib.sha256(raw).hexdigest()==unit['object_sha256'],'stale named object')
                contract=contracts[recipe_index]
                contract['provenance'].update(object_sha256=unit['object_sha256'],source_sha256=unit['source_sha256'],recipe_id=unit['recipe_id'],
                    recipe_index=recipe_index,recipe_unit_sha256=pv['recipe_unit_sha256'],recipe_manifest_sha256=EXPECTED['recipes'],
                    producer_manifest_sha256=EXPECTED['manifest'],retained_proof_sha256=EXPECTED['retained'],selection_sha256=EXPECTED['selection'],
                    imports_sha256=IMPORT_PIN,binding_sha256=EXPECTED['binding'],binding_details_sha256=binding['details_sha256'],reference_identity_sha256=proof['inputs']['image_sha256'],
                    source_relative=unit['source'],producer_compiler_variant=unit['compiler'],parser_sha256=PARSER_PIN,
                    observer_sha256=file_hash(__file__),optional_function_index_present=False,
                    dependency_tools_sha256={p.relative_to(ROOT).as_posix():h for p,h in observations.items() if p.is_relative_to(ROOT/'tools')})
                cert=assess_object(coff.parse(raw),contract);certificates.append(cert)
                note(dict(state='observed_named_object',recipe_id=unit['recipe_id'],closure_observed=cert['closure_observed'],certificate_sha256=digest(cert)))
            stable(observations);require(not index.exists(),'optional index appeared')
            details.parent.mkdir(parents=True,exist_ok=True)
            # Exclusive gzip publication; complete certificates contain only metadata.
            with details.open('xb') as target:
                created.append(details)
                with gzip.GzipFile(fileobj=target,mode='wb',mtime=0) as gz:
                    for cert in certificates:gz.write(canonical(cert)+b'\n')
                target.flush();os.fsync(target.fileno())
            stable(observations);require(not index.exists(),'optional index appeared')
            result=dict(schema_version=1,policy_id=POLICY,status='metadata-only',inputs={n:pins[n] for n in names},
                binding_details_sha256=binding['details_sha256'],details_sha256=file_hash(details),
                protected_tools_sha256={p.relative_to(ROOT).as_posix():h for p,h in observations.items() if p.is_relative_to(ROOT/'tools')},
                certificates=[dict(recipe_id=c['recipe_id'],roots=c['roots'],certificate_sha256=digest(c),closure_observed=c['closure_observed'],
                    blocker_codes=dict(Counter(b['code'] for b in c['blockers'])),summary=c['summary']) for c in certificates],
                original_binding_census=stream_provenance,input_stability=True,optional_function_index_present=False,**FALSE)
            out.parent.mkdir(parents=True,exist_ok=True)
            with out.open('x',encoding='utf-8') as target:created.append(out);json.dump(result,target,separators=(',',':'));target.write('\n')
            note(dict(state='complete',report_sha256=file_hash(out),details_sha256=file_hash(details)));return result
        except BaseException as e:
            for p in created:p.unlink(missing_ok=True)
            note(dict(state='failed',error_type=type(e).__name__));raise


def main(argv=None):
    p=argparse.ArgumentParser(description=__doc__)
    for n in ('manifest','retained','selection','recipes','binding','imports','binding-details','out','details-gz'):p.add_argument('--'+n,required=True,type=Path)
    p.add_argument('--parser-sha256',required=True);p.add_argument('--root',type=Path,default=ROOT)
    try:r=run(p.parse_args(argv))
    except (ValueError,OSError,KeyError,TypeError,struct.error) as e:p.exit(2,'root closure rejected: '+str(e)+'\n')
    print(json.dumps(r['certificates']));return 0


if __name__=='__main__':raise SystemExit(main())
