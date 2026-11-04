"""Source-only reviewed-stage bulk unresolved CODE producer.

No native command, compiler, executable link, runtime provider or game execution.
Operational emission is gated by an independently reviewed, root-approved phase
receipt. Pure core functions are exercised with authored synthetic objects.
"""
from __future__ import annotations
import argparse
import ast
from collections import Counter, defaultdict
import gzip
import hashlib
import json
import os
from pathlib import Path
import re
import struct
import sys
import coff_code_archive as coff
import runtime_code_pool as pool
import runtime_code_inventory as inventory

ROOT=Path(__file__).resolve().parents[2]
POLICY='bulk-unresolved-recipe-union-v1'
OWNED=('tools/rebuild/bulk_code_pool.py','tests/rebuild/test_bulk_code_pool.py',
       'docs/rebuild/BULK-CODE-POOL.md','runtime/code-pools/recipe-0000-pilot.json')
PINS=dict(inventory='02a77cce3f43c1786cd027e72ffb17e76ffe6766c2823872254015b6e40549f6',
 inventory_details='91cdc91af6530e6e80e2104cdfeb9bd6928e17fa0f75bcf066734985248f1031',
 historical_writer='06f373e8592571244b8e70c913a037812a73c856bc8e42b5b2c9b509b732ed81',
 writer='729f189e2893c7f3a3e3cd97df7d7381ac115169e1d75cf664e6bbc1c587b277',
 coff='76244d2d4dca4c1f8aa72224be1ef5c92f68976b5cda7d31b5cfe23d3cc29e64',
 proposal='c2b0d16b827a08eb4567fdc8b3c10b8197268328630d618c74e8faadab0bf2bb')
FALSE=dict(provider_selected=False,runtime_eligible=False,ABI_verified=False,link_ready=False,materialization_approved=False)
require=coff.require
sha=pool.file_hash


def canonical(value):return json.dumps(value,sort_keys=True,separators=(',',':'),ensure_ascii=True).encode('ascii')
def digest(value):return hashlib.sha256(canonical(value)).hexdigest()
def raw_digest(value):return hashlib.sha256(value).hexdigest()


def slot_maps(obj,sections,symbols):
    sm={old:new+1 for new,old in enumerate(sorted(sections))};ym={};am={};at=0
    for old in sorted(symbols):
        ym[old]=at
        for j in range(1,obj['symbols'][old]['aux_count']+1):am[old+j]=at+j
        at+=1+obj['symbols'][old]['aux_count']
    return sm,ym,am


def plan_union(data,contracts,reference_certificates=()):
    """Fresh individual assessment plus recomputed whole-recipe dispositions.

    No old one-root drop/conversion list is unioned as authoritative. Returns
    metadata only; unsupported unions quarantine the complete requested group.
    """
    obj=coff.parse(data);ix=pool.index_object(obj);syms=obj['symbols'];secs=obj['sections'];blocks=[]
    def block(code,evidence):blocks.append(dict(code=code,evidence=evidence))
    if reference_certificates:block('CERTIFICATE_CONSUMPTION_FUTURE_SCOPE','v1 cannot consume reference certificates or waive individual candidate blockers')
    require(contracts and len({c['selected']['original_address'] for c in contracts})==len(contracts),'unique nonempty roots required')
    rid=contracts[0]['recipe_id'];source=contracts[0]['source_sha256'];object_hash=raw_digest(data)
    require(all(c['recipe_id']==rid and c['source_sha256']==source and c['object_sha256']==object_hash for c in contracts),'union source/object/recipe conflict')
    roots=[dict(c['selected']) for c in contracts];root_sections={f['section']:f for f in roots}
    require(len(root_sections)==len(roots),'shared selected section unsupported')
    keep=set(ix['directive_sections']);assessments=[];literal_sections=set()
    for c in contracts:
        a=pool.assess_parsed(obj,c);assessments.append(a)
        if not a['candidate_eligible']:block('FRESH_ROOT_BLOCKED',dict(address=c['selected']['original_address'],blockers=a['blockers']))
        keep.add(c['selected']['section']);literal_sections.update(c.get('literal_sections',[]))
    keep.update(literal_sections)
    require(len(keep)<=32767,'COFF signed section index limit')
    # Check associations over the complete retained set, not a union of drops.
    debug=[];frontier=list(keep);seen=set(keep)
    while frontier:
        parent=frontier.pop()
        for child in ix['children'][parent]:
            if child in keep:block('RETAINED_ASSOCIATIVE_SECTION_UNSUPPORTED',dict(parent=parent,child=child));continue
            if child in seen:continue
            seen.add(child);s=secs[child]
            if s['name'].startswith('.debug') and not s['flags']&(0x20|0x20000000):
                debug.append(dict(section=child,parent=parent,size=s['size'],relocation_count=len(s['relocs'])));frontier.append(child)
            else:block('UNION_ASSOCIATION_BLOCKED',dict(parent=parent,section=child,name=s['name']))
    symbols=set(ix['metadata'])
    for section in keep:symbols.update(ix['members'][section])
    fields=[];facts={};names={};conversions=set();obligations=[];base_view={};field_keys=set()
    # Retained real definitions and local labels have immutable physical names.
    for i in sorted(symbols):
        s=syms[i]
        if s['section'] in root_sections and not s['aux_count']:
            f=root_sections[s['section']]
            names[i]=pool.canonical(dict(recipe_id=rid,object_sha256=object_hash,symbol_index=i))
            base_view[names[i]]='0x%08x'%((int(f['original_address'],16)+s['value'])&0xffffffff)
        elif s['section'] in literal_sections and not s['aux_count']:
            names[i]=pool.canonical(dict(recipe_id=rid,object_sha256=object_hash,symbol_index=i))
    for c,a in zip(contracts,assessments):
        own=c['selected'];old_names=dict(a.get('extraction_plan',{}).get('bindings',[]))
        uses={(o['field_offset'],o['symbol_index']):o for o in a['obligations']}
        for row in c['fields']:
            r=row['coff_relocation'];si=r['symbol_index'];s=syms[si]
            key=(row['physical_section'],r['offset'],si,r['kind'])
            require(key not in field_keys,'duplicate physical field in union');field_keys.add(key);fields.append(row);symbols.add(si)
            base=row['derived_source_symbol_base_va'];use=uses.get((r['offset'],si));role=use['role'] if use else 'retained'
            if s['section'] in keep:
                if s['section'] in root_sections:
                    owner=root_sections[s['section']];expected=(int(owner['original_address'],16)+s['value'])&0xffffffff
                    if int(base,16)!=expected:block('RETAINED_LOCAL_BASE_CONFLICT',dict(symbol_index=si,base=base))
                elif s['section'] not in literal_sections:block('REFERENCE_TO_RETAINED_METADATA',si)
                if si not in names:block('RETAINED_SYMBOL_NAMESPACE_MISSING',si);continue
                name=names[si]
                if name in base_view and base_view[name]!=base:block('RETAINED_BASE_CONFLICT',si)
                base_view[name]=base
                fact=(base,'retained',name)
            else:
                name=old_names.get(si)
                if name is None:block('REFERENCE_NAMESPACE_MISSING',si);continue
                if s['section']>0:
                    if s['aux_count'] or s['storage'] not in (2,3):block('UNSUPPORTED_UNDEFINED_CONVERSION',si)
                    conversions.add(si)
                if si in names and names[si]!=name:block('UNION_PHYSICAL_NAME_CONFLICT',si)
                names[si]=name;fact=(base,role,name)
                if use is None:block('UNPROVED_UNDEFINED_OBLIGATION',si)
                else:obligations.append(dict(use,original_address=own['original_address'],physical_section=row['physical_section']))
                if name in base_view and base_view[name]!=base:block('CANONICAL_BASE_CONFLICT',name)
                base_view[name]=base
            if si in facts and facts[si]!=fact:block('UNION_PHYSICAL_IDENTITY_CONFLICT',dict(symbol_index=si,previous=facts[si],current=fact))
            facts[si]=fact
    actual={(section,off,i,k) for section in keep for off,i,k in secs[section]['relocs']}
    require(field_keys==actual,'union field coverage differs')
    for i in symbols:
        s=syms[i]
        if s['storage']==2 and i not in names:block('UNNAMESPACED_EXTERNAL',i)
        if s['section']>0 and s['section'] not in keep and i not in conversions:block('UNDISPOSED_DEFINITION',i)
    groups=defaultdict(list)
    for i,n in names.items():groups[n].append(i)
    existing={s['name'] for s in syms.values()}
    for n in names.values():
        if n in existing:block('PREEXISTING_CANONICAL_NAME',n)
    sm,ym,am=slot_maps(obj,keep,symbols)
    full_namespace=[dict(physical_index=i,serialized_index=ym[i],name=names.get(i,syms[i]['name'])) for i in sorted(symbols)]
    for n,indices in sorted(groups.items()):
        if len(indices)<2:continue
        records=[syms[i] for i in indices]
        if any(s['section'] in keep for s in records):block('MIXED_DEFINITION_REFERENCE_GROUP_UNSUPPORTED',dict(name=n,indices=sorted(indices)));continue
        if not all(s['storage']==2 and s['section']==s['value']==0 and not s['aux_count'] for s in records):
            block('REFERENCE_GROUP_ORIGINAL_SHAPE_UNSUPPORTED',dict(name=n,indices=sorted(indices)));continue
        block('REFERENCE_CERTIFICATE_REQUIRED',dict(name=n,indices=sorted(indices),dependency='No reviewed bulk-union consumer exists; future separate producer/consumer contract required'))
    return dict(schema_version=1,policy_id=POLICY,recipe_id=rid,object_sha256=object_hash,source_sha256=source,roots=roots,
        eligible=not blocks,blockers=blocks,sections=sorted(keep),symbols=sorted(symbols),undefined=sorted(conversions),
        bindings=sorted([i,n] for i,n in names.items()),section_map=sm,symbol_map=ym,auxiliary_map=am,
        namespace_plan=full_namespace,reference_certificates=[],obligations=obligations,comparison_base_view=base_view,
        debug_exclusions=debug,field_proof_sha256=digest(fields),assessments=assessments,
        counts=dict(roots=len(roots),code_bytes=sum(f['size'] for f in roots),literal_bytes=sum(secs[i]['size'] for i in literal_sections),
                    fields=len(fields),unique_undefined_records=len({o['symbol_index'] for o in obligations})),**FALSE)


def namespace_union(data,plan):
    """Name-only bytes with no distinct-record duplicate-name support in v1."""
    require(plan['eligible'] and raw_digest(data)==plan['object_sha256'],'blocked/stale union')
    obj=coff.parse(data);bindings=plan['bindings'];targets=defaultdict(list)
    for i,n in bindings:targets[n].append(i)
    require(not plan['reference_certificates'] and all(len(v)==1 for v in targets.values()),'v1 duplicate namespace/certificate unsupported')
    result=bytearray(data);extra=bytearray();allowed=set(range(obj['string_pointer'],obj['string_pointer']+4));seen=set()
    for i,n in bindings:
        require(i in obj['symbols'] and i not in seen and re.fullmatch(r'_fnv_code_[0-9a-f]{64}|_fnv_undefined_[0-9a-f]{64}',n),'invalid physical namespace')
        s=obj['symbols'][i];require(s['storage'] in (2,3) and s['section']>=0 and not s['aux_count'],'unsupported namespace record')
        at=obj['symbol_pointer']+18*i;offset=obj['string_length']+len(extra);require(offset<=0xffffffff,'namespace string overflow')
        struct.pack_into('<II',result,at,0,offset);extra+=n.encode()+b'\0';allowed.update(range(at,at+8));seen.add(i)
    require(obj['string_length']+len(extra)<=0xffffffff,'namespace size overflow')
    struct.pack_into('<I',result,obj['string_pointer'],obj['string_length']+len(extra));result+=extra
    require(all(a==b or i in allowed for i,(a,b) in enumerate(zip(data,result))),'name-only byte invariant')
    parsed=coff.parse(bytes(result));expected={i:dict(s) for i,s in obj['symbols'].items()}
    for i,n in bindings:expected[i]['name']=n
    require(parsed['symbols']==expected and parsed['sections']==obj['sections'],'independent name-only reparse')
    return bytes(result)


def serialize_union(data,contracts,plan=None,reference_certificates=()):
    expected=plan_union(data,contracts,reference_certificates)
    if plan is not None:require(digest(plan)==digest(expected),'union plan does not recompute')
    plan=expected
    named=namespace_union(data,plan)
    out,maps=coff.serialize(named,plan['sections'],plan['symbols'],plan['undefined'])
    require(maps['section_map']==plan['section_map'] and maps['symbol_map']==plan['symbol_map'] and maps['auxiliary_map']==plan['auxiliary_map'],'union map changed')
    before=coff.parse(data);after=coff.parse(out)
    definitions=coff.exports(out);require(len(definitions)==len(set(definitions)),'duplicate union export')
    expected_defs=sorted(dict(plan['bindings'])[i] for i in plan['symbols'] if before['symbols'][i]['storage']==2 and before['symbols'][i]['section'] in plan['sections'])
    require(definitions==expected_defs,'hidden/missing union definition')
    receipt=dict(plan=plan,maps=maps,output_sha256=raw_digest(out),exports=definitions,
        undefined=[s['name'] for s in after['symbols'].values() if s['storage']==2 and s['section']==0],
        section_dispositions=[dict(original_section=i,name=s['name'],size=s['size'],flags=s['flags'],payload_sha256=raw_digest(s['payload']),
            disposition='retained' if i in plan['sections'] else 'omitted unselected/unverified or explicit debug content') for i,s in before['sections'].items()],
        symbol_dispositions=[dict(original_symbol=i,section=s['section'],name=s['name'],auxiliary_slots=list(range(i+1,i+1+s['aux_count'])),
            disposition='converted undefined' if i in plan['undefined'] else 'retained' if i in plan['symbols'] else 'omitted unselected/unverified or debug record') for i,s in before['symbols'].items()],**FALSE)
    return out,receipt


def span(size):return 60+size+size%2


def archive_layout(members):
    require(0<len(members)<=65535,'archive member ordinal limit')
    require(len({m['name'] for m in members})==len(members),'duplicate member name')
    long=bytearray();names=[];first=[]
    for j,m in enumerate(members):
        require(re.fullmatch(r'[A-Za-z0-9_.-]+',m['name']) and 0<=m['length']<=0xffffffff,'invalid member name/length')
        require(m['exports']==sorted(set(m['exports'])),'duplicate/unsorted member export')
        require(all(isinstance(s,str) and s and all(33<=ord(ch)<=126 for ch in s) for s in m['exports']),'invalid export spelling')
        names.append('/'+str(len(long)));long+=m['name'].encode()+b'\0'
        first.extend((s,j) for s in m['exports'])
    require(len({s for s,_ in first})==len(first),'duplicate archive exports')
    require(len(first)<=0xffffffff,'archive symbol count limit');second=sorted(first)
    strings_size=sum(len(s.encode('ascii'))+1 for s,_ in first)
    l1=4+4*len(first)+strings_size;l2=8+4*len(members)+2*len(first)+strings_size
    at=8+span(l1)+span(l2)+span(len(long));offsets=[]
    for m in members:offsets.append(at);at+=span(m['length'])
    require(at<=0xffffffff and all(o<=0xffffffff for o in offsets),'archive 32-bit offset limit')
    one=struct.pack('>I',len(first))+b''.join(struct.pack('>I',offsets[j]) for _,j in first)+b''.join(s.encode()+b'\0' for s,_ in first)
    two=struct.pack('<I',len(members))+b''.join(struct.pack('<I',o) for o in offsets)+struct.pack('<I',len(second))+b''.join(struct.pack('<H',j+1) for _,j in second)+b''.join(s.encode()+b'\0' for s,_ in second)
    return dict(size=at,names=names,offsets=offsets,longnames=bytes(long),first=one,second=two,index=[(s,members[j]['name']) for s,j in second])


def shard_plan(members,max_members=60000,max_bytes=1<<30):
    require(1<=max_members<=65535 and 8<max_bytes<=0xffffffff,'invalid shard ceiling')
    require([m['recipe_index'] for m in members]==sorted(set(m['recipe_index'] for m in members)),'recipe ordering/duplicates')
    all_exports=[s for m in members for s in m['exports']];require(len(set(all_exports))==len(all_exports),'cross-shard export collision')
    shards=[];current=[];metrics=(0,0,0,0,0)
    def add(state,m):
        nm,ns,long,strings,body=state
        return (nm+1,ns+len(m['exports']),long+len(m['name'].encode())+1,
                strings+sum(len(s.encode())+1 for s in m['exports']),body+span(m['length']))
    def size(state):
        nm,ns,long,strings,body=state
        return 8+span(4+4*ns+strings)+span(8+4*nm+2*ns+strings)+span(long)+body
    for m in members:
        require(archive_layout([m])['size']<=max_bytes,'indivisible member exceeds shard ceiling')
        proposed=add(metrics,m);fits=proposed[0]<=max_members and proposed[1]<=0xffffffff and size(proposed)<=max_bytes
        if not fits:
            require(current,'empty shard');shards.append(current);current=[];metrics=(0,0,0,0,0)
        current.append(m);metrics=add(metrics,m)
    if current:shards.append(current)
    return shards


class Spool:
    """Exclusive append-only private byte spool; no automatic resume/replay."""
    def __init__(self,path,ledger):
        self.path=Path(path);self.ledger_path=Path(ledger)
        require(self.path.resolve()!=self.ledger_path.resolve() and not self.path.exists() and not self.ledger_path.exists(),'exclusive spool paths required')
        self.file=self.path.open('xb+');self.ledger=self.ledger_path.open('x',encoding='utf-8');self.members=[]
    def append(self,name,data,recipe_index,metadata):
        require(name not in {m['name'] for m in self.members},'duplicate spool member')
        start=self.file.tell();self.file.write(data);self.file.flush();os.fsync(self.file.fileno())
        row=dict(name=name,offset=start,length=len(data),sha256=raw_digest(data),recipe_index=recipe_index,exports=coff.exports(data),metadata_sha256=digest(metadata))
        self.ledger.write(canonical(row).decode()+'\n');self.ledger.flush();os.fsync(self.ledger.fileno());self.members.append(row)
        return row
    def close(self):self.file.close();self.ledger.close()


def inspect_spool(path,rows):
    at=0
    with Path(path).open('rb') as f:
        for row in rows:
            require(row['offset']==at,'spool gap/overlap');f.seek(at);remaining=row['length'];h=hashlib.sha256()
            while remaining:
                block=f.read(min(1048576,remaining));require(block,'truncated spool');h.update(block);remaining-=len(block)
            require(h.hexdigest()==row['sha256'],'spool hash differs');at+=row['length']
        require(f.read(1)==b'','uncommitted spool tail')


def ar_header(name,size):
    raw=(name.ljust(16)+'0'.ljust(12)+'0'.ljust(6)+'0'.ljust(6)+'100666'.ljust(8)+str(size).ljust(10)+'`\n').encode()
    require(len(raw)==60,'archive header overflow');return raw


def write_shard(spool,members,path):
    layout=archive_layout(members);require(not Path(path).exists(),'exclusive archive required')
    with Path(path).open('xb') as out,Path(spool).open('rb') as source:
        out.write(b'!<arch>\n')
        for name,data in [('/',layout['first']),('/',layout['second']),('//',layout['longnames'])]:
            out.write(ar_header(name,len(data)));out.write(data)
            if len(data)%2:out.write(b'\n')
        for name,m in zip(layout['names'],members):
            out.write(ar_header(name,m['length']));source.seek(m['offset']);remaining=m['length'];h=hashlib.sha256()
            while remaining:
                block=source.read(min(1048576,remaining));require(block,'truncated spool while copying');out.write(block);h.update(block);remaining-=len(block)
            require(h.hexdigest()==m['sha256'],'member changed during archive copy')
            if m['length']%2:out.write(b'\n')
        require(out.tell()==layout['size'],'archive size differs');out.flush();os.fsync(out.fileno())
    return verify_shard(path,members)


def verify_shard(path,members):
    """Independent streaming archive walk; at most one object payload in memory."""
    with Path(path).open('rb') as f:
        require(f.read(8)==b'!<arch>\n','archive magic');metadata=[];actual=[];offset_names={}
        def read_member():
            offset=f.tell();h=f.read(60);require(len(h)==60 and h[58:]==b'`\n','archive header')
            size=int(h[48:58]);require(0<=size<=0xffffffff and f.tell()+size<=Path(path).stat().st_size,'archive member size/bounds');body=f.read(size);require(len(body)==size,'archive truncated')
            if size%2:require(f.read(1)==b'\n','archive padding')
            return offset,h[:16].decode().strip(),body
        for expected in ('/','/','//'):
            row=read_member();require(row[1]==expected,'archive metadata order');metadata.append(row[2])
        long=metadata[2]
        for expected in members:
            offset,name,data=read_member();require(name.startswith('/') and name[1:].isdigit(),'longname reference')
            at=int(name[1:]);require(0<=at<len(long) and (at==0 or long[at-1]==0),'longname boundary');end=long.find(b'\0',at);require(end>=at,'longname terminator')
            name=long[at:end].decode();require(name==expected['name'] and len(data)==expected['length'] and raw_digest(data)==expected['sha256'],'recovered member differs')
            actual.extend((s,name) for s in coff.exports(data));offset_names[offset]=name
        require(not f.read(1),'extra archive member/trailing bytes')
    def strings(raw,n):
        rows=raw.split(b'\0');require(len(rows)==n+1 and rows[-1]==b'','index strings');return [r.decode() for r in rows[:-1]]
    first,second=metadata[:2];require(len(first)>=4 and len(second)>=8,'index extent')
    n=struct.unpack_from('>I',first)[0];require(4+4*n<=len(first),'first index bound')
    offsets=struct.unpack_from('>'+str(n)+'I',first,4);names=strings(first[4+4*n:],n)
    require(all(o in offset_names for o in offsets),'first member offsets');require(sorted(zip(names,[offset_names[o] for o in offsets]))==sorted(actual),'first export index')
    count=struct.unpack_from('<I',second)[0];require(count==len(members) and 8+4*count<=len(second),'second member count')
    offsets=struct.unpack_from('<'+str(count)+'I',second,4);require(list(offsets)==list(offset_names),'second member offsets')
    n=struct.unpack_from('<I',second,4+4*count)[0];at=8+4*count;require(at+2*n<=len(second),'second index bound')
    ordinals=struct.unpack_from('<'+str(n)+'H',second,at);require(all(1<=o<=count for o in ordinals),'second member ordinal')
    names=strings(second[at+2*n:],n);index=list(zip(names,[members[o-1]['name'] for o in ordinals]))
    require(index==sorted(actual) and len({s for s,_ in actual})==len(actual),'second index/duplicate exports')
    return dict(sha256=sha(path),size=Path(path).stat().st_size,members=len(members),exports=index,independent_stream_reparse=True,native_conformance_verified=False)


class InventoryStream:
    """Exact saved inventory, buffered one recipe at a time, never object scans."""
    def __init__(self,stream):
        self.stream=iter(stream);self.next=None;self.ordinal=0;self.events=Counter();self.seen=set();self.candidates=0;self._advance()
    def _advance(self):
        line=next(self.stream,None)
        if line is None:self.next=None;return
        require(len(line)<=8*1024*1024,'inventory row bound');self.ordinal+=1
        row=json.loads(line);require(row['event'] in ('RECIPE_COFF_METADATA','SELECTED_CODE_SERIALIZATION_ASSESSMENT','RECIPE_EH_EVIDENCE'),'inventory event')
        self.events[row['event']]+=1;self.next=(self.ordinal,row)
    def take(self,recipe_id):
        rows=[]
        while self.next is not None:
            ordinal,row=self.next;rid=row.get('recipe_id',row.get('physical_identity',{}).get('recipe_id'))
            if rid!=recipe_id:break
            rows.append((ordinal,row));self._advance()
        require(rows and rows[0][1]['event']=='RECIPE_COFF_METADATA' and rows[-1][1]['event']=='RECIPE_EH_EVIDENCE','missing/reordered recipe inventory')
        owners={}
        for ordinal,row in rows[1:-1]:
            require(row['event']=='SELECTED_CODE_SERIALIZATION_ASSESSMENT','interleaved inventory event')
            a=row['original_address'];require(a not in self.seen,'duplicate inventory owner');self.seen.add(a)
            require(type(row['serialization_candidate']) is bool and row['serialization_candidate']==(not bool(row['blockers'])),'inventory candidate/blocker inconsistency')
            owners[a]=(ordinal,row)
            if row['serialization_candidate']:self.candidates+=1
        return owners
    def finish(self,selections,summary):
        require(self.next is None and self.seen==set(selections) and self.candidates==16859,'complete historical candidate/owner scope')
        require(dict(self.events)==summary['summary']['events'],'inventory event census')


def compatibility(old_path,current_path):
    require(sha(old_path)==PINS['historical_writer'] and sha(current_path)==PINS['writer'],'assessor version identity')
    old,new=[ast.parse(Path(p).read_text()) for p in (old_path,current_path)]
    for name in ('canonical','unresolved','index_object','assess_member','assess_parsed'):
        a=[n for n in old.body if isinstance(n,ast.FunctionDef) and n.name==name]
        b=[n for n in new.body if isinstance(n,ast.FunctionDef) and n.name==name]
        require(len(a)==len(b)==1 and ast.dump(a[0])==ast.dump(b[0]),'historical/current shared assessment changed')
    return dict(historical_sha256=PINS['historical_writer'],current_sha256=PINS['writer'],shared_assessment_AST_equal=True)


def pin(path,expected,observed):return pool.observe(path,expected,observed)


def review_gate(path,expected,mode,observed):
    path=pin(path,expected,observed);r=json.loads(path.read_text())
    require(mode in ('pilot','all-current') and r.get('phase')=='bulk-code-pool-'+mode+'-emission' and r.get('mode')==mode and
            r.get('approved') is True and r.get('independent_source_schema_review_pass') is True and r.get('root_authorized') is True,'bulk source review/root phase required')
    require(set(r.get('source_sha256',{}))==set(OWNED),'complete reviewed bulk source set')
    require(not r.get('reference_certificates'),'v1 reference certificate consumption unsupported')
    for name,h in r['source_sha256'].items():pin(ROOT/name,h,observed)
    require(r.get('proposal_sha256')==PINS['proposal'],'reviewed proposal differs')
    return r


def load_basis(paths,observed):
    for n,h in inventory.EXPECTED.items():pin(paths[n],h,observed)
    for n in ('inventory','inventory_details','historical_writer'):pin(paths[n],PINS[n],observed)
    pin(ROOT/'tools/rebuild/runtime_code_pool.py',PINS['writer'],observed);pin(ROOT/'tools/rebuild/coff_code_archive.py',PINS['coff'],observed)
    pin(ROOT/'docs/rebuild/BULK-CODE-POOL-PROPOSAL.md',PINS['proposal'],observed)
    require(Path(pool.__file__).resolve()==ROOT/'tools/rebuild/runtime_code_pool.py' and Path(coff.__file__).resolve()==ROOT/'tools/rebuild/coff_code_archive.py','unexpected producer module')
    data={n:json.loads(Path(paths[n]).read_text(encoding='utf-8-sig')) for n in inventory.EXPECTED}
    inventory.validate_headers(data);require(inventory.reconcile_recipes(data['manifest'],paths['recipes'])['verified'],'authoritative recipe reconciliation')
    saved=json.loads(Path(paths['inventory']).read_text());require(saved['details_sha256']==PINS['inventory_details'] and saved['inputs']==inventory.EXPECTED and saved['policy_id']==pool.POLICY_ID,'saved inventory joins')
    require(saved['summary']['selected']==68657 and sum(saved['summary']['categories'].get(k,0) for k in ('CANDIDATE_WITH_CANONICAL_UNDEFINED','CANDIDATE_OWNED_FIELDS_ONLY'))==16859,'saved full candidate count')
    for relative,h in saved['tools_sha256'].items():
        if relative=='tools/rebuild/runtime_code_pool.py':require(h==PINS['historical_writer'],'historical writer pin');continue
        pin(ROOT/relative,h,observed)
    for n,h in pool.READER_DEPENDENCIES.items():pin(ROOT/n,h,observed)
    for report,relative in [('binding','tools/rebuild/runtime_bind_plan.py'),('owners','tools/rebuild/runtime_data_owners.py')]:pin(ROOT/relative,data[report]['implementation_sha256'],observed)
    for relative,h in data['eh']['inputs']['tools_sha256'].items():pin(ROOT/relative,h,observed)
    for relative,h in data['retained']['inputs']['tools_sha256'].items():pin(ROOT/relative,h,observed)
    pin(ROOT/'build/image_check.json',data['retained']['inputs']['image_check_sha256'],observed)
    pin(paths['binding_details'],data['binding']['details_sha256'],observed);pin(paths['owner_details'],data['owners']['details_sha256'],observed)
    require(data['binding']['details_sha256']==saved['input_detail_sha256']['binding'] and data['owners']['details_sha256']==saved['input_detail_sha256']['owners'],'detail inventory joins')
    pin(paths['reference'],pool.PINS['reference'],observed)
    version=compatibility(paths['historical_writer'],ROOT/'tools/rebuild/runtime_code_pool.py')
    return data,saved,version


def contracts_for(unit,proof,choices,bindings,providers):
    result=[]
    for f in choices:
        a=f['original_address'];identity=providers[a];b=bindings.get(a,dict(fields=[],missing_fields=[],row_identities=[]))
        require(identity['recipe_id']==unit['recipe_id'] and identity['object_sha256']==unit['object_sha256'],'provider physical proof differs')
        require(not b['missing_fields'] and not any(r[2] is False and r[3]==a for r in proof.get('eh_sections',[])),'baseline missing/frame owner cannot enter bulk')
        selected={k:f[k] for k in ('original_address','symbol','section','value','size')};selected['symbol_index']=identity['symbol_index']
        result.append(dict(recipe_id=unit['recipe_id'],object_sha256=unit['object_sha256'],source_sha256=unit['source_sha256'],selected=selected,
            verified_match=True,fields_complete=True,missing_fields_complete=True,fields=b['fields'],missing_fields=[],provider_identities=providers,
            literal_sections=[25,26] if unit['recipe_id']=='0703-3a582158246b390e' and a=='0x00646d00' else []))
    return result


def compare_functions(path,pe,contracts,unit,plan=None):
    import compare as oracle
    symbols=dict(unit.get('symbols',{}));specs=[]
    names=dict(plan['bindings']) if plan else {}
    if plan:symbols.update(plan['comparison_base_view'])
    for c in contracts:
        f=c['selected'];name=names[f['symbol_index']] if plan else f['symbol']
        specs.append(dict(address=f['original_address'],symbol=name,size=f['size']));symbols[name]=f['original_address']
    rows=oracle.compare(oracle.Coff(path),pe,dict(functions=specs,symbols=symbols,literal_symbols=[]))
    require(len(rows)==len(contracts),'fresh comparison row coverage')
    for row,c,spec in zip(rows,contracts,specs):
        require((row['address'],row['symbol'],row['size'])==(spec['address'],spec['symbol'],spec['size']) and
                row['verdict']=='match' and row['compiled_extent']==c['selected']['size'] and not row['errors'] and not row['byte_differences'] and
                all(r['match'] for r in row['relocations']),'fresh unchanged body/field comparison failed')
    return [{k:v for k,v in row.items() if k!='byte_differences'} for row in rows]


def strict_reparse(path,data):
    from coff_rewrite import strict_object
    other=strict_object(path)[0];own=coff.parse(data)
    require(set(other.sections)==set(own['sections']) and set(other.symbols)==set(own['symbols']),'independent COFF coverage')
    for i,s in other.sections.items():
        t=own['sections'][i];require(all(s[k]==t[k] for k in ('name','size','flags','relocs')) and s['payload_sha256']==raw_digest(t['payload']),'independent COFF section')
    for i,s in other.symbols.items():
        t=own['symbols'][i];require(all(s[k]==t[k] for k in ('name','value','section','type','storage','aux_count')),'independent COFF symbol')
        if t['aux']:
            length,nr,nl,checksum,assoc,selection,reserved,high=struct.unpack('<IHHIhBBH',t['aux'])
            require(not nl and not reserved and not high and s.get('section_aux')==dict(length=length,relocation_count=nr,checksum=checksum,association=assoc,selection=selection),'independent COFF auxiliary')


def emit(paths,mode,review_path,review_sha256,output_dir):
    """Real emission is forbidden until this exact source/schema gets review/go."""
    observed={};review=review_gate(review_path,review_sha256,mode,observed);data,saved,version=load_basis(paths,observed)
    policy_path=ROOT/'runtime/code-pools/recipe-0000-pilot.json';policy=json.loads(policy_path.read_text())
    require(policy['kind']=='bulk-code-pool-recipe-pilot' and policy['policy_id']==POLICY and policy['proposal_sha256']==PINS['proposal'],'pilot policy identity')
    pilot_set={f['original_address'] for f in policy['roots']};require(len(pilot_set)==6,'fixed pilot root count')
    certificates=();index=ROOT/'build/function_index.json';pool.stable(observed,index)
    out=Path(output_dir).resolve();private=(ROOT/'build/rebuild').resolve()
    require(out.is_relative_to(private) and out!=private and not out.exists() and not any(p.is_relative_to(out) for p in observed),'exclusive private bulk output required')
    out.mkdir();journal=(out/'progress.jsonl').open('x',encoding='utf-8')
    def note(row):journal.write(canonical(row).decode()+'\n');journal.flush();os.fsync(journal.fileno())
    note(dict(state='started',mode=mode,inputs={str(p):h for p,h in observed.items()},review_sha256=review_sha256))
    spool=None
    try:
        # Preserve exact reviewed versions before any later documentation update.
        for relative,h in review['source_sha256'].items():
            raw=(ROOT/relative).read_bytes();require(raw_digest(raw)==h,'reviewed source changed');snapshot=out/'source-snapshots'/relative
            snapshot.parent.mkdir(parents=True,exist_ok=True);pool.fsynced(snapshot,raw)
        sys.path.insert(0,str(ROOT/'tools'))
        import compare as oracle
        from build_and_match import image_ok
        pe=oracle.Pe(paths['reference']);require(image_ok(pe)[0],'unchanged owned image probe gate')
        with gzip.open(paths['owner_details'],'rt',encoding='utf-8') as stream:providers,owner_provenance=inventory.owner_providers(stream,data['owners'],data['selection']['selections'])
        proofs={u['recipe_index']:u for u in data['retained']['units']};require(len(proofs)==2988,'proof recipe count')
        spool=Spool(out/'members.spool',out/'members.jsonl');coverage_counts=Counter();requested=set();emitted=set();bands=Counter();recipe_results=[]
        with (out/'coverage.jsonl.gz').open('xb') as coverage_file,(out/'unions.jsonl.gz').open('xb') as union_file:
            with gzip.GzipFile(fileobj=coverage_file,mode='wb',mtime=0) as coverage,gzip.GzipFile(fileobj=union_file,mode='wb',mtime=0) as unions,gzip.open(paths['inventory_details'],'rt',encoding='utf-8') as old_stream,gzip.open(paths['binding_details'],'rt',encoding='utf-8') as binding_stream:
                old=InventoryStream(old_stream);bindings=inventory.BindingReader(binding_stream,data['binding']['summary'],data['selection']['selections'])
                for unit in data['manifest']['units']:
                    ri=unit['recipe_index'];pv=proofs[ri];inventory.check_unit(unit,pv);choices=inventory.selected_rows(unit,pv,data['selection']['selections'])
                    historical=old.take(unit['recipe_id']);require(set(historical)=={f['original_address'] for f in choices},'inventory selected recipe owner coverage')
                    bucket=bindings.take(ri);require(set(bucket)<=set(historical),'binding owner coverage')
                    selected=[f for f in choices if historical[f['original_address']][1]['serialization_candidate'] and (mode=='all-current' or f['original_address'] in pilot_set)]
                    selected_set={f['original_address'] for f in selected};requested.update(selected_set);result=None;member=None
                    if selected:
                        obj=(Path(paths['manifest']).resolve().parent/data['manifest'].get('object_root_relative','.')/unit['object']).resolve()
                        require(obj.is_relative_to(Path(paths['manifest']).resolve().parent),'manifest object escape')
                        source=(ROOT/unit['source']).resolve();require(source.is_relative_to(ROOT),'source escape')
                        pin(obj,unit['object_sha256'],observed);pin(source,unit['source_sha256'],observed);raw=obj.read_bytes()
                        fresh=inventory.assess_unit(raw,unit,pv,selected,bucket,providers,pool)
                        for row in fresh:require(inventory.canonical(row)==inventory.canonical(historical[row['original_address']][1]),'fresh root eligibility/provenance differs from saved inventory')
                        contracts=contracts_for(unit,pv,selected,bucket,providers)
                        if mode=='pilot':
                            require(unit['recipe_id']==policy['recipe_id'] and unit['source_sha256']==policy['source_sha256'] and unit['object_sha256']==policy['object_sha256'] and
                                    sorted([c['selected'] for c in contracts],key=lambda f:f['original_address'])==sorted(policy['roots'],key=lambda f:f['original_address']),'fixed six-root physical pilot identity')
                        result=plan_union(raw,contracts,certificates)
                        if result['eligible']:
                            before=compare_functions(obj,pe,contracts,unit['recipe'])
                            produced,receipt=serialize_union(raw,contracts,result,certificates);stage=out/(unit['recipe_id']+'.stage')
                            pool.fsynced(stage,produced);strict_reparse(stage,produced)
                            after=compare_functions(stage,pe,contracts,unit['recipe'],result)
                            receipt.update(before_comparison=before,after_comparison=after,independent_COFF_reparse=True,
                                original_binding_details_sha256=data['binding']['details_sha256'],
                                binding_row_references={c['selected']['original_address']:bucket.get(c['selected']['original_address'],dict(row_identities=[]))['row_identities'] for c in contracts},
                                source_group=dict(source=unit['source'],source_sha256=unit['source_sha256'],compiler=unit['compiler'],flags=unit['recipe']['flags'],recipe_index=ri,recipe_id=unit['recipe_id']))
                            if mode=='pilot':require(result['counts']==policy['expected_counts'] and len(receipt['exports'])==6,'fixed pilot count/field/obligation accounting')
                            member=spool.append(unit['recipe_id']+'.obj',produced,ri,receipt);emitted.update(selected_set);stage.unlink()
                            unions.write(canonical(dict(event='EMITTED_RECIPE_UNION',member=member,receipt=receipt))+b'\n')
                        else:unions.write(canonical(dict(event='BLOCKED_RECIPE_UNION',plan=result))+b'\n')
                        recipe_results.append(dict(recipe_id=unit['recipe_id'],requested=len(selected),emitted=bool(member),blockers=result['blockers']))
                        note(dict(state='recipe-complete',recipe_id=unit['recipe_id'],requested=len(selected),emitted=bool(member),member_sha256=None if member is None else member['sha256']))
                    for address,(ordinal,row) in historical.items():
                        status=('EMITTED' if address in emitted else 'BLOCKED_UNION' if address in selected_set else
                                'CANDIDATE_NOT_REQUESTED' if row['serialization_candidate'] else 'HISTORICAL_BLOCKED')
                        coverage_counts[status]+=1;bands[(row['size_band'],status)]+=1
                        coverage.write(canonical(dict(original_address=address,status=status,historical_only=address not in selected_set,
                            historical_inventory_row=dict(ordinal=ordinal,sha256=inventory.digest(row)),baseline_candidate=row['serialization_candidate'],
                            baseline_category=row['category'],baseline_blockers=row['blockers'],physical_identity=row['physical_identity'],
                            selected_native=row['selected_native'],union_blockers=result['blockers'] if address in selected_set and not member else [],
                            member=None if address not in emitted else member['name'],fresh_reference_match=address in emitted,**FALSE))+b'\n')
                old.finish(data['selection']['selections'],saved);binding_provenance=bindings.finish()
                require(sum(coverage_counts.values())==68657,'all-owner coverage total')
                require(len(requested)==(6 if mode=='pilot' else 16859) and (mode!='pilot' or requested==pilot_set),'complete requested key set')
            coverage_file.flush();os.fsync(coverage_file.fileno());union_file.flush();os.fsync(union_file.fileno())
        spool.close();spool=None
        members=[]
        with (out/'members.jsonl').open() as f:
            for line in f:members.append(json.loads(line))
        inspect_spool(out/'members.spool',members);shards=[]
        for number,group in enumerate(shard_plan(members)):
            path=out/('code-pool-%04d.lib'%number);verified=write_shard(out/'members.spool',group,path);shards.append(dict(name=path.name,**verified))
            note(dict(state='shard-verified',name=path.name,sha256=verified['sha256']))
        pool.stable(observed,index)
        complete=requested==emitted
        if complete:require(sum(len(s['exports']) for s in shards)==(6 if mode=='pilot' else 16861),'complete global code/literal export census')
        report=dict(schema_version=1,kind='private-bulk-unresolved-code-pool',policy_id=POLICY,mode=mode,status='complete' if complete else 'incomplete',
            requested=len(requested),emitted=len(emitted),historical_selected=68657,historical_candidates=16859,historical_blocked=51798,
            coverage_counts=dict(coverage_counts),size_status_counts=[dict(size_band=k[0],status=k[1],count=v) for k,v in sorted(bands.items())],
            shards=shards,recipe_results=recipe_results,coverage_sha256=sha(out/'coverage.jsonl.gz'),unions_sha256=sha(out/'unions.jsonl.gz'),
            spool_sha256=sha(out/'members.spool'),member_ledger_sha256=sha(out/'members.jsonl'),inputs={str(p):h for p,h in observed.items()},
            assessor_compatibility=version,binding_provenance=binding_provenance,owner_provenance=owner_provenance,
            inputs_stable=True,optional_function_index_present=False,native_conformance_verified=False,emission_performed=True,
            blocked_roots_freshly_compared=False,compiler_performed=False,executable_link_performed=False,game_execution_performed=False,**FALSE)
        pool.fsynced(out/'receipt.json',(json.dumps(report,indent=2)+'\n').encode());note(dict(state='complete' if complete else 'incomplete',receipt_sha256=sha(out/'receipt.json')))
        return report
    except BaseException as e:
        note(dict(state='failed',error_type=type(e).__name__,message=str(e)));raise
    finally:
        if spool is not None:spool.close()
        journal.close()


def main():
    p=argparse.ArgumentParser(description=__doc__)
    for n in (*inventory.EXPECTED,'inventory','inventory_details','historical_writer','binding_details','owner_details','reference'):p.add_argument('--'+n.replace('_','-'),required=True,type=Path)
    p.add_argument('--mode',choices=('pilot','all-current'),required=True);p.add_argument('--review',required=True,type=Path);p.add_argument('--review-sha256',required=True)
    p.add_argument('--output-dir',required=True,type=Path);a=p.parse_args()
    paths={n:getattr(a,n) for n in (*inventory.EXPECTED,'inventory','inventory_details','historical_writer','binding_details','owner_details','reference')}
    result=emit(paths,a.mode,a.review,a.review_sha256,a.output_dir);print(json.dumps(dict(status=result['status'],requested=result['requested'],emitted=result['emitted'])))


if __name__=='__main__':main()
