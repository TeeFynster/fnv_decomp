"""Read-only per-field runtime binding evidence; never rewrite or select providers."""
from __future__ import annotations
import argparse
import bisect
from collections import Counter, defaultdict
import gzip
import hashlib
import json
import os
from pathlib import Path
import re
import struct
import tempfile
import time
from types import SimpleNamespace

from import_plan import ROOT, ImagePe, image_ok, parse_imports, require, unit_digest
from relocation_audit import (Intervals, WIDTHS, verified_functions, selected_for_unit,
    check_original_span, relocation_record, classify_field, validate_headers)
from coff_inventory import Coff
from data_plan import Pe, file_hash
from runtime_gaps import read_bound
from compare import same_literal

CRT_SYMBOLS={'__purecall','_atexit','_abort','___CxxFrameHandler3','__CxxThrowException@8',
             '___RTDynamicCast','@__security_check_cookie@4','__ftol2_sse','__CIsqrt'}


def va(value):return '0x%08x'%(value & 0xffffffff)


def section_payload(coff,index):
    sec=coff.sections[index]
    header=coff.unpack('<8sIIIIIIHHI',20+(index-1)*40)
    return coff.take(header[4],sec['size']) if header[4] else bytes(sec['size'])


def source_maps(coff,unit,functions):
    mappings={name:int(address,0) for name,address in unit['recipe'].get('symbols',{}).items()}
    defined=defaultdict(list)
    for s in coff.symbols.values():
        if s['section']>0:defined[s['name']].append(s)
    placements={}
    for f in unit['recipe']['functions']:
        for name in [f['symbol']]+f.get('fold_aliases',[]):
            address=int(f['address'],16)
            require(name not in mappings or mappings[name]==address,'conflicting own recipe function binding')
            mappings[name]=address
            symbols=defined[name];require(len(symbols)==1,'ambiguous native function alias')
            key=(symbols[0]['section'],symbols[0]['value']);value=(address,f['size'])
            require(key not in placements or placements[key]==value,'conflicting physical function placement')
            placements[key]=value
    return mappings,placements


def resolve_source(symbol,addend,mappings,placements):
    if symbol['name'] in mappings:
        return (mappings[symbol['name']]+addend)&0xffffffff,'OWN_RECIPE_BINDING'
    if symbol['section']>0:
        point=symbol['value']+addend
        hits=[(value,address) for (section,value),(address,size) in placements.items()
              if section==symbol['section'] and value<=point<value+size]
        if len(hits)==1:return (hits[0][1]+point-hits[0][0])&0xffffffff,'EXACT_LOCAL_FUNCTION_CONTAINMENT'
        return None,'AMBIGUOUS_OR_UNBOUND_LOCAL_SYMBOL'
    if symbol['section']==-1:return (symbol['value']+addend)&0xffffffff,'SOURCE_ABSOLUTE_SYMBOL'
    return None,'UNBOUND_SOURCE_SYMBOL'


def project(kind,original,field_va,raw_addend,tls_start=None):
    if kind==6:return dict(representation='ABSOLUTE_VA_DIR32',target=original,addend=raw_addend)
    if kind==20:
        displacement=original if original<0x80000000 else original-0x100000000
        addend=raw_addend if raw_addend<0x80000000 else raw_addend-0x100000000
        return dict(representation='REL32_DISPLACEMENT',target=(field_va+4+displacement)&0xffffffff,
                    addend=addend,signed_original_displacement=displacement)
    if kind==7:return dict(representation='IMAGE_RELATIVE_RVA_REQUIRES_OWNER',target=None,addend=raw_addend)
    if kind==11:return dict(representation='STATIC_TLS_SECREL_REQUIRES_OWNER',target=None,addend=raw_addend)
    if kind==10:return dict(representation='SECTION_INDEX_REQUIRES_OWNER',target=None,addend=raw_addend)
    return dict(representation='UNSUPPORTED_OR_PADDING_FIELD',target=None,addend=raw_addend)


def literal_evidence(coff,symbol,observed,addend,pe,highlows):
    """Full compiler-literal extent, immutable ranges and no pointer fixup evidence.

    Equality is projection evidence only. It never merges original addresses or
    proves arbitrary source globals own runtime storage.
    """
    name=symbol['name'];payload=None;kind=None
    if symbol['section']<=0:return None
    sec=coff.sections[symbol['section']]
    header=coff.unpack('<8sIIIIIIHHI',20+(symbol['section']-1)*40)
    if not header[4] or not sec['flags']&0x40000000:return None
    if re.fullmatch(r'__(?:real|xmm)@[0-9a-f]+',name):
        bits=name.split('@',1)[1]
        if len(bits) in (8,16,20,32):payload=bytes.fromhex(bits)[::-1];kind='compiler-floating-or-vector-bits'
    elif name.startswith(('??_C@_0','??_C@_1')) and symbol['section']>0 and symbol['value']==0:
        sec=coff.sections[symbol['section']]
        if sec['comdat'] and sec['size']<=65536:
            data=section_payload(coff,symbol['section'])
            if name.startswith('??_C@_0') and data.endswith(b'\0') and b'\0' not in data[:-1]:
                payload=data;kind='compiler-narrow-string-COMDAT'
            elif name.startswith('??_C@_1') and len(data)%2==0 and data.endswith(b'\0\0') and all(data[i:i+2]!=b'\0\0' for i in range(0,len(data)-2,2)):
                payload=data;kind='compiler-wide-string-COMDAT'
    if payload is None or not 0<=addend<len(payload):return None
    if symbol['section']>0:
        sec=coff.sections[symbol['section']]
        if sec['flags'] & (0x80000000|0x20000000|0x20):return None
        if symbol['value']+len(payload)>sec['size'] or sec['relocs']:return None
        if section_payload(coff,symbol['section'])[symbol['value']:symbol['value']+len(payload)]!=payload:return None
    start=(observed-addend)&0xffffffff;rva=start-pe.base
    sec=pe.section(rva,len(payload))
    if sec is None or sec['flags'] & (0x80000000|0x20000000|0x20) or not sec['flags']&0x40000000:return None
    i=bisect.bisect_left(highlows,start-3)
    if i<len(highlows) and highlows[i]<start+len(payload):return None
    try:equal=pe.read_rva(rva,len(payload))==payload
    except ValueError:return None
    if not equal:return None
    return dict(kind=kind,original_literal_start=va(start),target_offset=addend,extent=len(payload),
        payload_sha256=hashlib.sha256(payload).hexdigest(),full_extent_equal=True,
        source_and_original_readonly=True,no_source_relocations_or_original_HIGHLOW=True,
        runtime_storage_owner_approved=False,original_identity_preserved=True)


def target_class(target,symbol,coff,code,entries,iat,pe,literal,expected_equal):
    result=dict(classification='UNSUPPORTED_OR_UNMAPPED',runtime_eligible=False,provider_selected=False,
                abi_verified=False,lifetime_verified=False)
    if target is None:return result
    hits=code.overlap(target,target+1)
    result['code_owners']=[dict(address=x['address'],offset=target-int(x['address'],16)) for x in hits]
    result['code_ownership_ambiguous']=len(hits)>1
    if target in iat:
        result.update(classification='IAT_POINTER_CELL_NOT_FUNCTION_BODY',import_id=iat[target]['import_id'])
    elif target in entries:result.update(classification='SELECTED_CODE_ENTRY',selected_address=va(target))
    elif len(hits)==1:result['classification']='UNIQUE_CODE_INTERIOR_OR_LOCAL_LABEL_NOT_CALLABLE_APPROVAL'
    elif len(hits)>1:result['classification']='AMBIGUOUS_CODE_INTERIOR'
    else:
        tls_rva,tls_size=pe.directories[9]
        tls_index=None
        if tls_rva:
            tls_index=struct.unpack('<IIIIII',pe.read_rva(tls_rva,24))[2]
        section=pe.section(target-pe.base)
        if tls_index==target:result['classification']='STATIC_TLS_INDEX_REQUIRES_CANONICAL_OWNER'
        elif section and section['name']=='.tls':result['classification']='STATIC_TLS_TEMPLATE_REQUIRES_CANONICAL_OWNER'
        elif literal:
            result.update(classification='COMPILER_LITERAL_FULL_READONLY_NONPOINTER_EQUALITY',literal=literal)
        elif symbol['name'] in CRT_SYMBOLS and expected_equal:
            result.update(classification='EXPLICIT_NORMAL_CRT_CONTRACT_CANDIDATE',
                          candidate_basis='own exact source binding and explicit CRT symbol set; ABI/state unverified')
        elif symbol['section']>0 and coff.sections[symbol['section']]['name'].startswith(('.text$x','.xdata')):
            result.update(classification='COMPILER_LOCAL_EH_METADATA_OR_HELPER_CANDIDATE',
                          native_target_section=symbol['section'],frame_contract_verified=False)
        elif section and not section['executable']:
            result.update(classification='ORIGINAL_IMAGE_DATA_REQUIRES_CANONICAL_OWNER',
                          original_section=section['name'],object_extent_known=False)
        elif section:result['classification']='UNSELECTED_EXECUTABLE_TARGET_UNCLASSIFIED'
    if symbol['name'].startswith(('__imp_','_imp__')) and target not in iat:
        result['import_pointer_source_conflict']=True
    if symbol['section']==-1:
        result['source_absolute_symbol_migration_blocker']=True
    return result


def field_record(coff,unit,f,r,pe,highlows,mappings,placements,code,entries,iat):
    symbol=coff.symbols[r['symbol_index']];field_va=int(f['address'],16)+r['offset']-f['value']
    base=dict(event='SELECTED_FUNCTION_COFF_RELOCATION',recipe_id=unit['recipe_id'],recipe_index=unit['recipe_index'],
        function_va=f['address'],function_symbol=f['symbol'],source_field_offset=r['offset']-f['value'],
        physical_section=f['section'],physical_offset=r['offset'],original_field_va=va(field_va),
        coff_relocation=r,runtime_eligible=False,provider_selected=False,game_fixup_approved=False)
    if r['width']==0 or r['offset']<f['value'] or r['offset']+r['width']>f['value']+f['size']:
        return dict(base,classification='UNSUPPORTED_PADDING_OR_STRADDLING_FIELD',proof_consistency='NO_CONTAINED_FIELD')
    original=int.from_bytes(pe.read_rva(field_va-pe.base,r['width'],allow_code=True),'little')
    projection=project(r['kind'],original,field_va,r['addend'])
    addend=projection['addend'];expected,basis=resolve_source(symbol,addend,mappings,placements)
    target=projection['target'];literal=None;consistency='SPECIAL_OR_UNSUPPORTED_SEMANTICS'
    if r['kind'] in (6,20):
        literal=literal_evidence(coff,symbol,target,addend,pe,highlows)
        require(expected is not None,'selected proof has unresolved original source target')
        if target==expected:consistency='EXACT_OWN_SOURCE_RESOLUTION'
        else:
            adapter=SimpleNamespace(sections={})
            if symbol['section']>0:adapter.sections[symbol['section']]=dict(data=section_payload(coff,symbol['section']))
            image_adapter=SimpleNamespace(read=lambda address,size:pe.read_rva(address-pe.base,size,allow_code=True))
            require(same_literal(adapter,image_adapter,symbol,expected,target),'original field conflicts with retained source-resolution proof')
            consistency='ORIGINAL_ORACLE_LITERAL_POOL_TOLERANCE_ADDRESS_NOT_MERGED'
    elif r['kind']==7:
        projection['original_image_projection_va']=va(pe.base+original)
        require(expected is not None and expected==(pe.base+original)&0xffffffff,'DIR32NB proof projection conflict')
        consistency='IMAGE_RELATIVE_PROJECTION_ONLY'
    elif r['kind']==11:
        tls=next((s for s in pe.sections if s['name']=='.tls'),None)
        require(tls is not None and expected is not None and pe.base+tls['rva']<=expected<pe.base+tls['rva']+tls['extent']
                and original==expected-(pe.base+tls['rva']),'SECREL TLS proof projection conflict')
        projection['original_TLS_projection_va']=va(expected);consistency='STATIC_TLS_OFFSET_PROJECTION_ONLY'
    result=target_class(target,symbol,coff,code,entries,iat,pe,literal,target==expected)
    if r['kind'] in (7,10,11):result['classification']=projection['representation']
    ordinary_target=target
    if r['kind']==6 and symbol['name']=='__tls_array' and target==expected==0x2c and basis=='OWN_RECIPE_BINDING':
        # A compiler mechanism lead, not proof that numeric 0x2c is a process VA
        # or that an instruction's segment/addressing semantics were decoded.
        result['classification']='COMPILER_TLS_ARRAY_OFFSET_CANDIDATE_NOT_PROCESS_VA'
        result['addressing_mode_verified']=False
        projection=dict(representation='COMPILER_TLS_ARRAY_DIR32_NUMERIC_OFFSET_CANDIDATE',target=None,
                        addend=addend,observed_numeric_offset_candidate=target)
        ordinary_target=None
    return dict(base,original_operand=original,representation=projection,
        exact_original_target_va=va(ordinary_target) if ordinary_target is not None else None,
        derived_source_symbol_base_va=va(ordinary_target-addend) if ordinary_target is not None else None,
        expected_original_target_va=va(expected) if expected is not None and ordinary_target is not None else None,
        source_resolution_basis=basis,proof_consistency=consistency,**result)


def scan_unit(coff,unit,functions,selected,pe,highlows,code,entries,iat,highlow_counts):
    mappings,placements=source_maps(coff,unit,functions)
    records={};overlaps={}
    for sec in coff.sections.values():
        records[sec['index']]=[relocation_record(coff,sec,r) for r in sec['relocs']]
        overlaps[sec['index']]=Intervals([(r['offset'],r['offset']+r['width'],r) for r in records[sec['index']] if r['width']])
    for f in selected:
        start=int(f['address'],16);end=start+f['size']
        for r in records[f['section']]:
            if r['offset']<f['value']+f['size'] and r['offset']+max(1,r['width'])>f['value']:
                record=field_record(coff,unit,f,r,pe,highlows,mappings,placements,code,entries,iat)
                competing=overlaps[f['section']].overlap(r['offset'],r['offset']+r['width']) if r['width'] else []
                record['physical_field_overlap_count']=len(competing)
                if len(competing)>1:
                    record['target_projection_classification']=record['classification']
                    record['classification']='AMBIGUOUS_PHYSICAL_RELOCATION_FIELD'
                yield record
        for site in highlows[bisect.bisect_left(highlows,start-3):bisect.bisect_left(highlows,end)]:
            physical=f['value']+site-start;matches=overlaps[f['section']].overlap(physical,physical+4)
            status=classify_field(f['value'],f['value']+f['size'],physical,matches);highlow_counts[status]+=1
            if status=='MISSING_COFF_RELOCATION':
                operand=struct.unpack('<I',pe.read_rva(site-pe.base,4,allow_code=True))[0]
                yield dict(event='MISSING_ORIGINAL_HIGHLOW_SOURCE_MIGRATION_BLOCKER',recipe_id=unit['recipe_id'],
                    recipe_index=unit['recipe_index'],function_va=f['address'],function_symbol=f['symbol'],
                    source_field_offset=site-start,original_field_va=va(site),observed_original_operand=operand,
                    physical_section=f['section'],physical_offset=physical,
                    coff_relocation=None,classification='MISSING_SOURCE_RELOCATION_NO_SYNTHESIS',
                    runtime_eligible=False,provider_selected=False,game_fixup_approved=False)


def audit_missing_identities(path,audit):
    require(file_hash(path)==audit['details_sha256'],'stale relocation audit details')
    counts=Counter();missing=set();total=0
    with gzip.open(path,'rt',encoding='utf-8') as stream:
        for line in stream:
            require(len(line)<=65536,'audit detail row exceeds bound');row=json.loads(line);total+=1
            require(total<=2000000,'audit detail count exceeds bound')
            counts[row['event']+':'+row['status']]+=1
            if row['event']=='PE_HIGHLOW_CORRELATION' and row['status']=='MISSING_COFF_RELOCATION':
                require(row['coff_fields']==[],'missing audit field unexpectedly has a COFF relocation')
                key=(row['recipe_id'],row['candidate']['address'],row['candidate']['symbol'],row['original_field_va'],
                     row['physical_field']['section'],row['physical_field']['offset'])
                require(key not in missing,'duplicate missing baseline field');missing.add(key)
    require(dict(counts)==audit['summary']['event_statuses'],'audit detail event counts conflict')
    return missing


def optional_evidence(args,hashes,observations):
    result={}
    for name in ('eh','overlay'):
        path=getattr(args,name,None);pin=getattr(args,name+'_sha256',None)
        require(bool(path)==bool(pin),'optional evidence path/hash must be paired')
        if not path:continue
        path=Path(path).resolve();data=read_bound(path,pin);observations[path]=pin
        if name=='eh':
            require(data.get('kind')=='fnv-eh-ownership-observations'
                    and all(data['inputs'][k]==hashes[k] for k in ('retained','manifest','recipes'))
                    and data.get('runtime_eligible') is False and data.get('provider_selection') is False,'EH candidate identity/state conflict')
            result[name]=dict(sha256=pin,candidate_only=True,adopted=False,summary=data['summary'])
        else:
            require(data.get('kind')=='fnv-fixed-runtime-source-overlay-result' and data.get('generated_inputs_stability_verified') is True
                    and data.get('input_stability_verified') is True and data.get('provider_selected') is False
                    and data.get('runtime_eligible') is False and data.get('game_fixups_approved')==0
                    and all(h in data['inputs'].values() for h in (hashes['recipes'],hashes['manifest'],hashes['retained'],hashes['selection'],hashes['reference'])),
                    'overlay candidate identity/state conflict')
            # Supplied report paths are hash-checked evidence, never adopted objects.
            artifacts=data.get('artifacts',{})
            require(data['generated_source_sha256'] in artifacts.values() and data['overlay_object_sha256'] in artifacts.values(),
                    'overlay candidate artifacts missing')
            for artifact,h in artifacts.items():
                candidate=Path(artifact).resolve();require(file_hash(candidate)==h,'stale overlay candidate artifact')
                observations[candidate]=h
            result[name]=dict(sha256=pin,candidate_only=True,adopted=False,
                observed_single_candidate_reaudit=data['selected_function_reaudit'],baseline_missing_relocation_count_unchanged=True)
    return result


def run(args):
    started=time.monotonic();root=Path(args.root).resolve()
    names=('recipes','manifest','retained','selection','reference','imports','audit')
    paths={n:Path(getattr(args,n)).resolve() for n in names};hashes={n:getattr(args,n+'_sha256') for n in names}
    data={n:read_bound(paths[n],hashes[n]) for n in names if n!='reference'}
    require(file_hash(paths['reference'])==hashes['reference'],'stale reference')
    validate_headers(data,hashes,paths)
    manifest,receipt,selection,imports,audit=(data[n] for n in ('manifest','retained','selection','imports','audit'))
    for name,kind in (('imports','fnv-static-import-plan'),('audit','fnv-selected-code-relocation-audit')):
        d=data[name];require(d.get('kind')==kind and d.get('schema_version')==1 and d.get('status')=='analysis-only'
            and all(d['inputs'][k]==hashes[k] for k in ('recipes','manifest','retained','reference'))
            and d.get('runtime_closure_verified') is False and d.get('game_fixups_approved')==0,
            name+' input identity/state conflict')
    require(audit['inputs']['selection']==hashes['selection'],'audit selection identity conflict')
    require(imports.get('function_providers_selected') is False and audit.get('runtime_eligible') is False
            and audit.get('link_ready') is False and receipt.get('runtime_closure_verified') is False,
            'input provider/runtime approval state conflict')
    observations={paths[n]:hashes[n] for n in names}
    audit_details=Path(args.audit_details).resolve()
    baseline_missing=audit_missing_identities(audit_details,audit)
    hashes['audit_details']=audit['details_sha256'];observations[audit_details]=audit['details_sha256']
    candidates=optional_evidence(args,hashes,observations)
    require(all(n in receipt['inputs']['tools_sha256'] for n in
                ('tools/build_and_match.py','tools/compare.py','tools/rebuild/verify_objects.py')),
            'proof lacks original producer/comparison identities')
    for n,h in receipt['inputs']['tools_sha256'].items():
        path=(ROOT/n).resolve();require(path.is_relative_to(ROOT) and file_hash(path)==h,'stale original verifier tool');observations[path]=h
    for n in ('runtime_bind_plan.py','relocation_audit.py','import_plan.py','data_plan.py','coff_inventory.py','runtime_gaps.py'):
        path=ROOT/'tools/rebuild'/n;observations[path]=file_hash(path)
    index=root/'build/function_index.json';present=receipt['inputs']['function_index_present']
    require(type(present)is bool and index.exists()==present and selection['function_index_present']==present,'optional index presence conflict')
    if present:
        require(file_hash(index)==receipt['inputs']['function_index_sha256'],'stale index');observations[index]=receipt['inputs']['function_index_sha256']
    else:require(receipt['inputs']['function_index_sha256'] is None,'absent index hash conflict')
    proof_units={u['recipe_index']:u for u in receipt['units']}
    require(len(proof_units)==len(receipt['units'])==len(manifest['units']),'proof scope conflict')
    object_paths=set()
    for unit in manifest['units']:
        obj=(paths['manifest'].parent/manifest.get('object_root_relative','.')/unit['object']).resolve();source=(root/unit['source']).resolve()
        require(source.is_relative_to(root) and obj not in object_paths,'source/object path conflict')
        object_paths.add(obj);observations[obj]=unit['object_sha256'];observations[source]=unit['source_sha256']
    out=Path(args.out).resolve();details=Path(args.details_gz).resolve();progress=Path(str(out)+'.progress.jsonl')
    require(len({out,details,progress})==3 and all(not p.exists() and p not in observations for p in (out,details,progress)),'output collision')
    image=ImagePe(paths['reference']);require(hashlib.sha256(image.data).hexdigest()==hashes['reference'],'image drift')
    passed,hits,probes=image_ok(image);del image;require(passed,'image fingerprint rejection')
    entries={int(a,16):s for a,s in selection['selections'].items()}
    code=Intervals([(a,a+s['size'],dict(address=va(a),**s)) for a,s in entries.items()])
    counts=Counter();events=Counter();consistency=Counter();kinds=Counter();unique_targets=set();name_bases=defaultdict(set);unit_name_bases=defaultdict(set)
    physical_symbol_bases=defaultdict(set)
    class_targets=defaultdict(set)
    highlow_counts=Counter();seen=set();rows=0;created=[];missing_identities=set()
    progress.parent.mkdir(parents=True,exist_ok=True)
    with progress.open('x',encoding='utf-8') as journal:
        def note(value):journal.write(json.dumps(value,separators=(',',':'))+'\n');journal.flush();os.fsync(journal.fileno())
        note(dict(state='started',inputs=hashes))
        try:
            with tempfile.TemporaryFile() as tmp:
                pe=Pe(paths['reference'])
                try:
                    actual_imports=parse_imports(pe)
                    def identities(items):return [(i['dll'],i['export'],i['original_IAT_va']) for i in items]
                    require(identities(actual_imports)==identities(imports['imports']),'actual PE/import-plan identities conflict')
                    iat={int(i['original_IAT_va'],16):i for i in imports['imports']}
                    highlows=sorted(pe.base+r for r in pe.relocations())
                    with gzip.GzipFile(fileobj=tmp,mode='wb',mtime=0) as stream:
                        for number,unit in enumerate(manifest['units']):
                            proof=proof_units[unit['recipe_index']]
                            require(unit.get('status')=='compiled' and proof.get('status')=='ok' and proof['recipe_id']==unit['recipe_id']
                                and proof['recipe_unit_sha256']==unit_digest(unit['recipe']) and proof['object_sha256']==unit['object_sha256']
                                and proof['source_sha256_recorded']==proof['source_sha256_current']==unit['source_sha256'],'unit proof conflict')
                            obj=(paths['manifest'].parent/manifest.get('object_root_relative','.')/unit['object']).resolve()
                            require(file_hash(root/unit['source'])==unit['source_sha256'],'stale source')
                            coff=Coff(obj);require(hashlib.sha256(coff.data).hexdigest()==unit['object_sha256'],'stale object')
                            functions=verified_functions(coff,unit,proof);rows+=len(functions)
                            selected=selected_for_unit(unit,functions,selection['selections'])
                            for f in selected:
                                check_original_span(pe,f);address=va(int(f['address'],16));require(address not in seen,'duplicate selected function');seen.add(address)
                            for record in scan_unit(coff,unit,functions,selected,pe,highlows,code,entries,iat,highlow_counts):
                                events[record['event']]+=1;counts[record['classification']]+=1
                                if record['event']=='MISSING_ORIGINAL_HIGHLOW_SOURCE_MIGRATION_BLOCKER':
                                    key=(record['recipe_id'],record['function_va'],record['function_symbol'],record['original_field_va'],
                                         record['physical_section'],record['physical_offset'])
                                    require(key not in missing_identities,'duplicate derived missing field');missing_identities.add(key)
                                if record['event']=='SELECTED_FUNCTION_COFF_RELOCATION':
                                    consistency[record['proof_consistency']]+=1;kinds[str(record['coff_relocation']['kind'])]+=1
                                    if record.get('exact_original_target_va'):
                                        unique_targets.add(record['exact_original_target_va'])
                                        class_targets[record['classification']].add(record['exact_original_target_va'])
                                        symbol=record['coff_relocation']['symbol'];base=record['derived_source_symbol_base_va']
                                        name_bases[symbol].add(base);unit_name_bases[(unit['recipe_index'],symbol)].add(base)
                                        physical_symbol_bases[(unit['recipe_index'],record['coff_relocation']['symbol_index'])].add(base)
                                require(sum(events.values())<=1000000,'binding record bound exceeded')
                                stream.write((json.dumps(record,separators=(',',':'))+'\n').encode())
                            if (number+1)%100==0:note(dict(state='scanning',objects=number+1,records=sum(events.values())))
                finally:pe.close()
                require(seen==set(selection['selections']) and rows==selection['selected_recipe_rows'],'selected function coverage conflict')
                expected_highlow={k.split(':',1)[1]:v for k,v in audit['summary']['event_statuses'].items() if k.startswith('PE_HIGHLOW_CORRELATION:')}
                require(dict(highlow_counts)==expected_highlow,'original HIGHLOW baseline partition changed')
                require(missing_identities==baseline_missing,'exact original missing-field baseline identities changed')
                require(index.exists()==present,'index changed')
                for p,h in observations.items():require(file_hash(p)==h,'input drift during runtime binding scan')
                details.parent.mkdir(parents=True,exist_ok=True);tmp.seek(0)
                with details.open('xb') as dest:
                    created.append(details)
                    while chunk:=tmp.read(1024*1024):dest.write(chunk)
                result=dict(schema_version=1,kind='fnv-runtime-binding-observations',status='analysis-only',inputs=hashes,
                    implementation_sha256=file_hash(__file__),details_sha256=file_hash(details),detail_format='gzip-jsonl-complete-selected-field-and-migration-records',
                    summary=dict(objects=len(manifest['units']),selected_functions=len(seen),checked_recipe_rows=rows,
                        events=dict(events),target_classes=dict(counts),relocation_kinds=dict(kinds),proof_consistency=dict(consistency),
                        unique_exact_original_targets=len(unique_targets),original_HIGHLOW_partition=dict(highlow_counts),
                        unique_original_targets_by_class={k:len(v) for k,v in sorted(class_targets.items())},
                        exact_baseline_missing_field_identities=len(missing_identities),
                        global_source_names_with_multiple_base_identities=sum(len(v)>1 for v in name_bases.values()),
                        unit_source_names_with_multiple_symbol_base_identities=sum(len(v)>1 for v in unit_name_bases.values()),
                        physical_COFF_symbols_with_multiple_original_base_identities=sum(len(v)>1 for v in physical_symbol_bases.values())),
                    source_name_disagreement_examples=[dict(symbol=s,base_identities=sorted(v)[:16],complete_count=len(v)) for s,v in sorted(name_bases.items()) if len(v)>1][:20],
                    same_unit_disagreement_examples=[dict(recipe_index=i,symbol=s,base_identities=sorted(v)[:16],complete_count=len(v)) for (i,s),v in sorted(unit_name_bases.items()) if len(v)>1][:20],
                    optional_candidate_evidence=candidates,retained_EH_notes=selection['retained_verification'],optional_function_index_present=present,
                    image_gate=dict(hits=hits,probes=probes),runtime_eligible=False,link_ready=False,runtime_closure_verified=False,
                    provider_selected=False,game_fixups_approved=0,elapsed_seconds=round(time.monotonic()-started,3),
                    limitations=['Per-field exact original identities are not a runtime ABI, storage, EH-frame or lifetime approval.',
                        'Literal projection equality preserves each original address; oracle literal pooling tolerance is recorded separately.',
                        'Special TLS/SECTION/RVA fields are not ordinary absolute VA bindings.',
                        'Missing original HIGHLOW source fields remain migration blockers; optional overlay never replaces baseline objects.'])
                out.parent.mkdir(parents=True,exist_ok=True)
                with out.open('x',encoding='utf-8') as f:created.append(out);json.dump(result,f,separators=(',',':'));f.write('\n')
                note(dict(state='complete',report_sha256=file_hash(out),details_sha256=file_hash(details)))
                return result
        except BaseException as error:
            for p in created:p.unlink(missing_ok=True)
            note(dict(state='failed',error_type=type(error).__name__))
            raise


def main(argv=None):
    p=argparse.ArgumentParser(description=__doc__)
    for n in ('recipes','manifest','retained','selection','reference','imports','audit'):
        p.add_argument('--'+n,type=Path,required=True);p.add_argument('--'+n+'-sha256',required=True)
    for n in ('eh','overlay'):
        p.add_argument('--'+n,type=Path);p.add_argument('--'+n+'-sha256')
    p.add_argument('--audit-details',type=Path,required=True)
    p.add_argument('--root',type=Path,default=ROOT);p.add_argument('--out',type=Path,required=True);p.add_argument('--details-gz',type=Path,required=True)
    try:result=run(p.parse_args(argv))
    except (ValueError,OSError,KeyError,TypeError,struct.error) as error:p.exit(2,'runtime binding plan rejected: '+str(error)+'\n')
    print(json.dumps(result['summary']));return 0


if __name__=='__main__':raise SystemExit(main())
