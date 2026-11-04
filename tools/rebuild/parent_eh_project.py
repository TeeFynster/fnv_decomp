"""Parent-owned no-catch EH projection; no compiler/linker/executable API."""
from __future__ import annotations
import hashlib
from pathlib import Path
import struct
import tempfile
import parent_eh_adapter as adapter
import runtime_code_pool as pool
from coff_inventory import Coff as IndependentCoff

coff=adapter.coff
require=coff.require
POLICY='parent-owned-no-catch-EH-projection-v1'


def namespace_plan(result,contract):
    semantic=result['semantic'];root=semantic['parent']
    export=pool.canonical(dict(recipe_id=contract['recipe_id'],object_sha256=semantic['object_sha256'],symbol_index=root['symbol_index']))
    bindings=[(root['symbol_index'],export)];groups={}
    for external in semantic['external_obligations']:
        name=pool.unresolved('0x%08x'%external['base'],external['role'])
        groups.setdefault(name,[]).append(external['symbol_index']);bindings.append((external['symbol_index'],name))
    require(not any(len(indices)>1 for indices in groups.values()),'REFERENCE_GROUP_REQUIRES_NAMESPACE_EXTENSION')
    return sorted(bindings),export


def check_output(raw,output,result,maps,bindings,reference,highlow):
    before=coff.parse(raw);after=coff.parse(output);semantic=result['semantic'];sm=maps['section_map'];ym=maps['symbol_map'];names=dict(bindings)
    ps=semantic['parent']['section'];xs=semantic['code_section'];ds=semantic['state_section']
    # Physical values and all runtime payloads survive the frozen selection.
    for old in (ps,xs,ds):
        require(after['sections'][sm[old]]['payload']==before['sections'][old]['payload'],'runtime payload changed')
        require(after['sections'][sm[old]]['relocs']==[(off,ym[index],kind) for off,index,kind in before['sections'][old]['relocs']],'runtime relocation map changed')
    function=dict(address=semantic['parent']['original_address'],symbol=names[semantic['parent']['symbol_index']],size=semantic['parent']['size'])
    comparison=dict(functions=[function],symbols={names[e['symbol_index']]:hex(e['base']) for e in semantic['external_obligations']})
    for index,target in before['symbols'].items():
        if target['section'] not in (ps,xs,ds) or target['aux_count'] or index==semantic['parent']['symbol_index']:continue
        spans=[span for span in semantic['comparisons'] if span['section']==target['section'] and span['start']<=target['value']<span['end']]
        require(len(spans)==1,'LOCAL_COMPARISON_POINT_OUTSIDE_UNIQUE_OWNED_SPAN')
        span=spans[0];comparison['symbols'][after['symbols'][ym[index]]['name']]=hex(span['original_start']+target['value']-span['start'])
    with tempfile.TemporaryDirectory(prefix='parent-EH-output-reparse-') as folder:
        path=Path(folder)/'component.obj';path.write_bytes(output);core=adapter.oracle.Coff(path)
        ordinary=adapter.oracle.compare(core,reference,comparison,None)
        pieces,inferred,errors=adapter.oracle.eh_sections(core,reference,comparison,ordinary,{})
        independent=IndependentCoff(path)
        require(len(independent.sections)==len(after['sections']) and len(independent.symbols)==len(after['symbols']),'independent physical counts differ')
        for sn,s in after['sections'].items():
            require(all(independent.sections[sn][k]==s[k] for k in ('name','size','flags','relocs')) and independent.sections[sn]['payload_sha256']==adapter.sha(s['payload']),'independent section differs')
        for index,s in after['symbols'].items():
            require(all(independent.symbols[index][k]==s[k] for k in ('name','value','section','type','storage','aux_count')),'independent symbol differs')
            if s['aux_count']:
                length,nreloc,nline,checksum,assoc,selection,reserved,high=struct.unpack('<IHHIhBBH',s['aux'])
                require(independent.symbols[index]['section_aux']==dict(length=length,relocation_count=nreloc,checksum=checksum,association=(assoc&0xffff)|(high<<16),selection=selection),'independent auxiliary differs')
    require(len(ordinary)==1 and ordinary[0]['verdict']=='match' and ordinary[0]['compiled_extent']==function['size'],'projected ordinary oracle failed')
    require(not errors and all(p[2] is True for p in pieces) and [p[:4] for p in pieces]==[p[:4] for p in semantic['original_core']['eh_sections']],'projected EH oracle failed')
    spans=[];fields=[]
    for span in semantic['comparisons']:
        old=span['section'];section=after['sections'][sm[old]];a,b=span['start'],span['end'];native=section['payload'][a:b];original=reference.read(span['original_start'],b-a)
        relocations=[(offset-a,index,kind) for offset,index,kind in section['relocs'] if a<=offset<b]
        adapter.compare_span(native,original,relocations,highlow,span['original_start'])
        spans.append(dict(section=old,output_section=sm[old],start=a,end=b,original_start=span['original_start'],nonfield_differences=0,payload_sha256=adapter.sha(native)))
    for field in semantic['fields']:
        section=after['sections'][sm[field['section']]];off=field['offset'];kind=field['kind'];index=ym[field['target_index']]
        require((off,index,kind) in section['relocs'],'projected field absent')
        addend=adapter.i32(section['payload'],off) if kind==20 else adapter.u32(section['payload'],off)
        original=reference.read(field['original_field_va'],4)
        observed=(field['original_field_va']+4+adapter.i32(original,0))&0xffffffff if kind==20 else adapter.u32(original,0)
        require(addend==field['addend'] and observed==field['original_target']==(field['original_base']+addend)&0xffffffff,'projected original field changed')
        fields.append(dict(field,output_section=sm[field['section']],output_target_index=index))
    return dict(ordinary=ordinary,eh_sections=pieces,eh_errors=errors,inferred=inferred,comparisons=spans,fields=fields,independent_reparse=True)


def project_parent(inputs,expected):
    """Recompute the full observer before transforming; caller dict is no token.

    Actual publication must additionally authenticate the private input envelope,
    source pins and reviewed finite scope immediately before and after writing.
    """
    current=adapter.observe_parent(**inputs)
    require(adapter.digest(current)==adapter.digest(expected),'STALE_OR_FORGED_PARENT_OBSERVATION')
    require(current['structural_projection_candidate'] is True and current['semantic_graph_verified'] is True and not current['blockers'],'PARENT_GRAPH_NOT_SERIALIZABLE')
    require(all(current[k] is False for k in adapter.FALSE),'runtime approval forbidden')
    raw=inputs['raw'];obj=coff.parse(raw);semantic=current['semantic'];bindings,export=namespace_plan(current,inputs['contract'])
    named=coff.namespace(raw,bindings)
    intermediate,maps=coff.serialize(named,current['retained_sections'],current['retained_primary_indices'],current['undefined_conversions'])
    retained=[r for r in current['safeseh_records'] if r['retain']]
    require(len(retained)==1,'ONE_OWNED_SAFESEH_HANDLER_REQUIRED');registration=retained[0]
    old_sx=registration['section'];sx=maps['section_map'][old_sx];mapped=coff.parse(intermediate)
    source_records=[adapter.u32(obj['sections'][old_sx]['payload'],off) for off in range(0,obj['sections'][old_sx]['size'],4)]
    require(source_records==[r['symbol_index'] for r in current['safeseh_records']],'SAFESEH_DISPOSITION_UNIVERSE_DIFFERS')
    require(all(r['retain'] or (r['target_section'] not in (semantic['parent']['section'],semantic['code_section'],semantic['state_section'])) for r in current['safeseh_records']),'LIVE_SAFESEH_RECORD_DROPPED')
    handler=semantic['handler_index'];new_handler=maps['symbol_map'][handler]
    section_header=20+(sx-1)*40;payload_offset=struct.unpack_from('<I',intermediate,section_header+20)[0]
    source_sx_symbol=[i for i,s in obj['symbols'].items() if s['section']==old_sx and s['name']=='.sxdata' and s['storage']==3 and s['aux_count']==1]
    require(len(source_sx_symbol)==1,'SAFESEH_SECTION_AUXILIARY_UNIVERSE')
    sx_primary={i for i,s in obj['symbols'].items() if s['section']==old_sx}
    require(sx_primary==set(source_sx_symbol),'SAFESEH_ALIASES_REQUIRE_EXPLICIT_TYPED_POLICY')
    require(not any(index in sx_primary for section in obj['sections'].values() for _,index,_ in section['relocs']),'SAFESEH_INCOMING_REFERENCE_UNSUPPORTED')
    require(not any(s['storage']==105 and s['aux_count']==1 and struct.unpack_from('<I',s['aux'])[0] in sx_primary for s in obj['symbols'].values()),'SAFESEH_WEAK_FALLBACK_REFERENCE_UNSUPPORTED')
    auxiliary=maps['auxiliary_map'][source_sx_symbol[0]+1];aux_offset=mapped['symbol_pointer']+18*auxiliary
    trimmed=bytearray(intermediate);struct.pack_into('<I',trimmed,section_header+16,4);struct.pack_into('<I',trimmed,payload_offset,new_handler)
    trimmed[payload_offset+4:payload_offset+len(source_records)*4]=bytes((len(source_records)-1)*4)
    struct.pack_into('<I',trimmed,aux_offset,4);struct.pack_into('<I',trimmed,aux_offset+8,0)
    allowed=set(range(section_header+16,section_header+20))|set(range(payload_offset,payload_offset+len(source_records)*4))|set(range(aux_offset,aux_offset+4))|set(range(aux_offset+8,aux_offset+12))
    require(len(trimmed)==len(intermediate) and all(a==b or i in allowed for i,(a,b) in enumerate(zip(intermediate,trimmed))),'UNDOCUMENTED_METADATA_MUTATION')
    # Restore the complete original selection metadata and verify against the
    # frozen writer, then compact the documented trimmed table with that writer.
    restored=bytearray(trimmed)
    for i in allowed:restored[i]=intermediate[i]
    coff.verify_selection(named,bytes(restored),maps)
    parsed=coff.parse(bytes(trimmed));output,repack=coff.serialize(bytes(trimmed),sorted(parsed['sections']),sorted(parsed['symbols']))
    require(all(k==v for mapping in (repack['section_map'],repack['symbol_map'],repack['auxiliary_map']) for k,v in mapping.items()) and repack['undefined_conversions']==[],'REPACK_CHANGED_PHYSICAL_IDENTITIES')
    final=coff.parse(output);require(final['sections'][sx]['payload']==struct.pack('<I',new_handler),'WRONG_REBASED_SAFESEH_INDEX')
    target=final['symbols'][new_handler]
    require((target['section'],target['value'],target['type'],target['storage'],target['aux_count'])==(maps['section_map'][semantic['code_section']],obj['symbols'][handler]['value'],32,3,0),'SAFESEH_HANDLER_NO_LONGER_OWNED_LOCAL')
    require(coff.exports(output)==[export],'HELPER_OR_DATA_EXPORTED')
    check=check_output(raw,output,current,maps,bindings,inputs['reference'],inputs['original_highlow_sites'])
    report=dict(schema_version=1,policy_id=POLICY,input_sha256=adapter.sha(raw),output_sha256=adapter.sha(output),output_bytes=len(output),observation_sha256=adapter.digest(current),namespace=bindings,export=export,maps=maps,repack_maps=repack,safeseh=dict(source_section=old_sx,output_section=sx,source_records=current['safeseh_records'],retained_source_index=handler,output_handler_index=new_handler,ordinal_reserialization_only=True),after=check,unresolved_obligations=semantic['external_obligations'],original_before=current,**adapter.FALSE)
    return output,report
