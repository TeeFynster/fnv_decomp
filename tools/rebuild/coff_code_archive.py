"""Strict bounded i386 COFF serializer and deterministic two-index COFF archive.

Pure byte transforms only. Callers own source/reference/selection authorization.
No link, native process, provider discovery or executable output.
"""
from __future__ import annotations
import hashlib
import struct


def require(ok, message):
    if not ok:
        raise ValueError(message)


def digest(data):
    return hashlib.sha256(data).hexdigest()


def parse(data):
    """Independent strict reader. Physical indices include auxiliary slots."""
    def take(off, size):
        require(0 <= off <= len(data) and 0 <= size <= len(data)-off, 'COFF bounds')
        return data[off:off+size]
    def unpack(fmt, off):
        return struct.unpack(fmt, take(off, struct.calcsize(fmt)))
    machine, count, stamp, sp, ns, opt, flags = unpack('<HHIIIHH', 0)
    require(machine == 0x14c and count and not opt and not flags and sp and ns, 'unsupported COFF header')
    take(20, count*40)
    strings_at = sp+18*ns
    length, = unpack('<I', strings_at)
    require(length >= 4 and strings_at+length == len(data), 'COFF string extent')
    strings = take(strings_at, length)
    def string(off):
        require(4 <= off < len(strings), 'COFF string offset')
        end = strings.find(b'\0', off)
        require(end >= off, 'COFF string terminator')
        return strings[off:end].decode('ascii')
    def name(raw, section=False):
        if section and raw.startswith(b'/'):
            return string(int(raw.rstrip(b'\0')[1:]))
        if not section and raw[:4] == bytes(4):
            return string(struct.unpack_from('<I', raw, 4)[0])
        return raw.rstrip(b'\0').decode('ascii')
    regions = [(0, 20+40*count), (sp, strings_at), (strings_at, len(data))]
    sections = {}
    for i in range(1, count+1):
        raw, va, vb, size, ptr, rp, lp, nr, nl, fl = unpack('<8sIIIIIIHHI', 20+(i-1)*40)
        require(not va and not vb and not lp and not nl and not fl & 0x1000000, 'unsupported section metadata')
        require(not nr or rp, 'missing relocation pointer')
        require(not size or ptr or fl & 0x80, 'missing section payload')
        payload = take(ptr, size) if ptr else b''
        if ptr and size:
            regions.append((ptr, ptr+size))
        if nr:
            take(rp, nr*10); regions.append((rp, rp+nr*10))
        relocs = [unpack('<IIH', rp+10*j) for j in range(nr)]
        sections[i] = dict(name=name(raw, True), size=size, flags=fl, payload=payload, relocs=relocs)
    symbols = {}
    i = 0
    while i < ns:
        raw, value, sec, typ, storage, aux = unpack('<8sIhHBB', sp+18*i)
        require(-2 <= sec <= count and i+aux < ns, 'invalid symbol/aux index')
        symbols[i] = dict(name=name(raw), value=value, section=sec, type=typ, storage=storage,
                          aux=take(sp+18*(i+1), 18*aux), aux_count=aux)
        i += 1+aux
    for sec in sections.values():
        for off, target, kind in sec['relocs']:
            require(target in symbols, 'relocation targets auxiliary/absent symbol')
            widths = {0:0, 1:2, 2:2, 6:4, 7:4, 9:2, 10:2, 11:4, 12:4, 13:1, 20:4}
            require(kind in widths and off+widths[kind] <= sec['size'], 'unsupported relocation/bounds')
    regions.sort()
    require(all(a[1] <= b[0] for a,b in zip(regions, regions[1:])), 'overlapping COFF regions')
    return dict(sections=sections, symbols=symbols, symbol_count=ns, symbol_pointer=sp,
                string_pointer=strings_at, string_length=length, timestamp=stamp)


def namespace(data, bindings):
    """Only Name fields/string length change. Duplicate source names are valid."""
    obj = parse(data); result = bytearray(data); extra = bytearray(); seen = set()
    existing = {s['name'] for s in obj['symbols'].values()}; targets = set()
    for index, new in bindings:
        require(type(index) is int and index in obj['symbols'] and index not in seen, 'conflicting physical binding')
        s = obj['symbols'][index]
        require(s['storage'] in (2,3) and s['section'] >= 0 and not s['aux_count'], 'unsupported namespace symbol')
        require(isinstance(new,str) and new and all(33 <= ord(c) <=126 for c in new), 'invalid namespace')
        require(new not in existing and new not in targets, 'namespace collision')
        struct.pack_into('<II',result,obj['symbol_pointer']+18*index,0,obj['string_length']+len(extra))
        extra += new.encode('ascii')+b'\0'; seen.add(index); targets.add(new)
    struct.pack_into('<I',result,obj['string_pointer'],obj['string_length']+len(extra)); result += extra
    after = parse(bytes(result))
    expected = {i:dict(s) for i,s in obj['symbols'].items()}
    for i,n in bindings:
        expected[i]['name']=n
    require(after['symbols']==expected and after['sections']==obj['sections'], 'name-only invariant')
    allowed = set(range(obj['string_pointer'],obj['string_pointer']+4))
    for i in seen:
        allowed.update(range(obj['symbol_pointer']+18*i,obj['symbol_pointer']+18*i+8))
    require(all(a==b or i in allowed for i,(a,b) in enumerate(zip(data,result))), 'non-name byte changed')
    return bytes(result)


def serialize(data, keep_sections, keep_symbols, undefined=()):
    """Selection phase; explicit old/new bijections, supported section aux only.

    undefined lists omitted section definitions converted to EXTERNAL/zero value.
    Namespace is a separate prior operation. All retained field bytes survive.
    """
    obj = parse(data); secs=obj['sections']; syms=obj['symbols']
    ks=list(keep_sections); ky=list(keep_symbols); undef=set(undefined)
    require(ks==sorted(set(ks)) and ky==sorted(set(ky)) and set(ks)<=secs.keys() and set(ky)<=syms.keys(), 'invalid selection')
    require(undef<=set(ky), 'undefined outside symbol selection')
    sm={i:j+1 for j,i in enumerate(ks)}; ym={}; am={}; cursor=0
    for i in ky:
        ym[i]=cursor
        for j in range(syms[i]['aux_count']):
            am[i+1+j]=cursor+1+j
        cursor+=1+syms[i]['aux_count']
    records=bytearray(); strings=bytearray(4)
    def encoded(name, section=False):
        n=name.encode('ascii')
        if len(n)<=8:
            return n.ljust(8,b'\0')
        off=len(strings); strings.extend(n+b'\0')
        if section:
            raw=('/'+str(off)).encode(); require(len(raw)<=8,'long section offset'); return raw.ljust(8,b'\0')
        return struct.pack('<II',0,off)
    # Section names may themselves allocate string entries.
    sn={i:encoded(secs[i]['name'],True) for i in ks}
    for i in ky:
        s=syms[i]; value,sec,storage=s['value'],s['section'],s['storage']; aux=s['aux']
        require(storage in (2,3), 'weak/file/unknown retained record')
        if i in undef:
            require(sec>0 and sec not in sm and not aux and storage in (2,3), 'unsupported undefined conversion')
            value,sec,storage=0,0,2
        else:
            require(sec<=0 or sec in sm, 'retained definition outside section selection')
            metadata=(s['storage']==3 and s['type']==0 and not s['aux_count'] and
                      (s['name']=='@comp.id' or (s['name']=='@feat.00' and value==1)))
            require(not(sec==0 and value) and (sec!=-1 or metadata), 'common/absolute runtime binding')
            sec=sm.get(sec,sec)
        if aux:
            require(s['aux_count']==1 and s['storage']==3 and s['type']==0 and s['value']==0 and s['section'] in sm and s['name']==secs[s['section']]['name'], 'unsupported auxiliary form')
            length,nr,nl,checksum,assoc,selection,reserved,high=struct.unpack('<IHHIhBBH',aux)
            source=secs[s['section']]
            require(length==source['size'] and nr==len(source['relocs']) and not nl and not reserved and not high and selection in (0,1,2,3,4,5,6,7), 'unsupported auxiliary metadata')
            if selection==5:
                require(assoc in sm, 'association escapes selection')
                aux=struct.pack('<IHHIhBBH',length,nr,nl,checksum,sm[assoc],selection,0,0)
            else:
                require(not assoc, 'hidden auxiliary index')
        records+=struct.pack('<8sIhHBB',encoded(s['name']),value,sec,s['type'],storage,s['aux_count'])+aux
    body=bytearray(); headers=bytearray(); pos=20+40*len(ks)
    for i in ks:
        s=secs[i]; payload=s['payload']; require(len(payload)==s['size'], 'unbacked selected section')
        raw=pos if payload else 0; body+=payload; pos+=len(payload); rp=pos if s['relocs'] else 0
        for off,target,kind in s['relocs']:
            require(target in ym and kind in (6,20), 'unsupported/escaping runtime relocation')
            body+=struct.pack('<IIH',off,ym[target],kind); pos+=10
        headers+=struct.pack('<8sIIIIIIHHI',sn[i],0,0,len(payload),raw,rp,0,len(s['relocs']),0,s['flags'])
    struct.pack_into('<I',strings,0,len(strings))
    out=struct.pack('<HHIIIHH',0x14c,len(ks),0,pos,cursor,0,0)+headers+body+records+strings
    receipt=dict(section_map=sm,symbol_map=ym,auxiliary_map=am,undefined_conversions=sorted(undef))
    verify_selection(data,out,receipt)
    return out,receipt


def verify_selection(before, after, receipt):
    a,b=parse(before),parse(after); sm,ym=receipt['section_map'],receipt['symbol_map']; am=receipt['auxiliary_map']; conversions=receipt['undefined_conversions']; undef=set(conversions)
    require(all(type(k) is int and type(v) is int for mapping in (sm,ym,am) for k,v in mapping.items()),'noninteger bijection')
    require(set(sm)<=set(a['sections']) and set(ym)<=set(a['symbols']),'absent original provenance index')
    require(len(set(sm.values()))==len(sm) and len(set(ym.values()))==len(ym) and len(set(am.values()))==len(am),'noninjective bijection')
    require(len(conversions)==len(undef) and undef<=set(ym),'invalid conversion index set')
    require(set(b['sections'])==set(sm.values()) and set(b['symbols'])==set(ym.values()), 'output bijection')
    expected_aux={old+j:new+j for old,new in ym.items() for j in range(1,a['symbols'][old]['aux_count']+1)}
    require(am==expected_aux and not(set(am.values())&set(ym.values())) and not(set(am)&set(ym)), 'auxiliary bijection differs')
    require(set(ym.values())|set(am.values())==set(range(b['symbol_count'])),'incomplete output slot bijection')
    for old,new in sm.items():
        x,y=a['sections'][old],b['sections'][new]
        require(all(x[k]==y[k] for k in ('name','size','flags','payload')), 'section semantic change')
        require([(o,ym[t],k) for o,t,k in x['relocs']]==y['relocs'], 'relocation semantic change')
    for old,new in ym.items():
        original=a['symbols'][old];x=dict(original)
        require(original['storage'] in (2,3),'unsupported verified storage')
        if old in undef:
            require(original['section']>0 and original['section'] not in sm and not original['aux_count'] and original['storage'] in (2,3),'invalid verified undefined conversion')
            x.update(section=0,value=0,storage=2)
        else:
            require(original['section']<=0 or original['section'] in sm,'verified retained definition outside section selection')
            metadata=(original['storage']==3 and original['type']==0 and not original['aux_count'] and
                      (original['name']=='@comp.id' or (original['name']=='@feat.00' and original['value']==1)))
            require(not(original['section']==0 and original['value']) and (original['section']!=-1 or metadata),'verified common/absolute runtime binding')
            x['section']=sm.get(original['section'],original['section'])
        if x['aux']:
            require(original['aux_count']==1 and original['storage']==3 and original['type']==0 and original['value']==0
                    and original['section'] in sm and original['name']==a['sections'][original['section']]['name'],'unsupported verified auxiliary form')
            aux=bytearray(x['aux'])
            length,nr,nl,checksum,assoc,selection,reserved,high=struct.unpack('<IHHIhBBH',aux)
            source=a['sections'][original['section']]
            require(length==source['size'] and nr==len(source['relocs']) and not nl and not reserved and not high and selection in range(8),'unsupported verified auxiliary metadata')
            if selection==5:
                require(assoc in sm,'verified association escapes selection')
                struct.pack_into('<h',aux,12,sm[assoc])
            else:require(not assoc,'verified hidden auxiliary index')
            x['aux']=bytes(aux)
        require(x==b['symbols'][new], 'symbol/auxiliary semantic change')


def exports(data):
    return sorted(s['name'] for s in parse(data)['symbols'].values() if s['storage']==2 and s['section']>0)


def archive(members):
    """Microsoft COFF archive with both linker members and longnames table.

    Format conformance still requires separately authorized native inspection.
    """
    require(members and len(members)<=65535, 'archive member count')
    require(len({n for n,_ in members})==len(members), 'duplicate archive member')
    long=bytearray(); names=[]; index=[]
    for j,(name,data) in enumerate(members):
        require(name and all(33<=ord(c)<=126 for c in name) and '/' not in name and '\\' not in name, 'archive member name')
        off=len(long); long+=name.encode()+b'\0'; names.append('/'+str(off))
        for symbol in exports(data): index.append((symbol,j))
    require(len({n for n,_ in index})==len(index),'duplicate archive export')
    first=index; second=sorted(index)
    n=len(index); total=len(members)
    l1=4+4*n+sum(len(s.encode())+1 for s,_ in first)
    l2=4+4*total+4+2*n+sum(len(s.encode())+1 for s,_ in second)
    def span(length): return 60+length+(length%2)
    pos=8+span(l1)+span(l2)+span(len(long)); offsets=[]
    for _,data in members: offsets.append(pos); pos+=span(len(data))
    one=struct.pack('>I',n)+b''.join(struct.pack('>I',offsets[j]) for _,j in first)+b''.join(s.encode()+b'\0' for s,_ in first)
    two=struct.pack('<I',total)+b''.join(struct.pack('<I',o) for o in offsets)+struct.pack('<I',n)+b''.join(struct.pack('<H',j+1) for _,j in second)+b''.join(s.encode()+b'\0' for s,_ in second)
    def member(name,data):
        header=(name.ljust(16)+'0'.ljust(12)+'0'.ljust(6)+'0'.ljust(6)+'100666'.ljust(8)+str(len(data)).ljust(10)+'`\n').encode('ascii')
        require(len(header)==60,'archive header overflow')
        return header+data+(b'\n' if len(data)%2 else b'')
    result=b'!<arch>\n'+member('/',one)+member('/',two)+member('//',bytes(long))+b''.join(member(n,d) for n,(_,d) in zip(names,members))
    recovered=read_archive(result)
    require(recovered['members']==members and recovered['index']==[(s,members[j][0]) for s,j in second], 'archive independent recovery')
    return result


def read_archive(data):
    require(data[:8]==b'!<arch>\n','archive magic'); rows=[]; pos=8
    while pos<len(data):
        start=pos; h=data[pos:pos+60]; require(len(h)==60 and h[58:]==b'`\n','archive header')
        size=int(h[48:58]); require(size>=0 and pos+60+size<=len(data),'archive bounds')
        name=h[:16].decode('ascii').strip(); body=data[pos+60:pos+60+size]; pos+=60+size
        if size%2:
            require(data[pos:pos+1]==b'\n','archive padding'); pos+=1
        rows.append((start,name,body))
    require(pos==len(data) and len(rows)>=4 and [r[1] for r in rows[:3]]==['/','/','//'],'archive required members')
    long=rows[2][2]; members=[]; byoff={}
    for off,name,body in rows[3:]:
        require(name.startswith('/') and name[1:].isdigit(),'archive longname reference')
        at=int(name[1:]); end=long.find(b'\0',at)
        require(0<=at<len(long) and (at==0 or long[at-1]==0) and end>=at,'archive longname offset')
        resolved=long[at:end].decode('ascii'); members.append((resolved,body)); byoff[off]=resolved
    def strings(raw,count):
        pieces=raw.split(b'\0'); require(len(pieces)==count+1 and pieces[-1]==b'','archive symbol strings')
        return [p.decode('ascii') for p in pieces[:-1]]
    one=rows[0][2]; require(len(one)>=4,'archive first index'); n=struct.unpack_from('>I',one)[0]
    require(4+4*n<=len(one),'archive first count'); offs=struct.unpack_from('>'+str(n)+'I',one,4)
    syms=strings(one[4+4*n:],n); require(all(o in byoff for o in offs),'archive member offset')
    first=list(zip(syms,[byoff[o] for o in offs]))
    two=rows[1][2]; require(len(two)>=4,'archive second index'); m=struct.unpack_from('<I',two)[0]
    require(m==len(members) and 8+4*m<=len(two),'archive member table')
    offsets=struct.unpack_from('<'+str(m)+'I',two,4); require(list(offsets)==list(byoff),'archive second offsets')
    k=struct.unpack_from('<I',two,4+4*m)[0]; at=8+4*m
    require(k==n and at+2*k<=len(two),'archive second count'); nums=struct.unpack_from('<'+str(k)+'H',two,at)
    require(all(1<=v<=m for v in nums),'archive second ordinal')
    syms=strings(two[at+2*k:],k); second=list(zip(syms,[members[v-1][0] for v in nums]))
    expected=sorted((s,name) for name,obj in members for s in exports(obj))
    require(second==expected and sorted(first)==expected and len(set(syms))==len(syms),'archive export index differs')
    return dict(members=members,index=second)
