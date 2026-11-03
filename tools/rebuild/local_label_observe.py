"""Bounded original LABEL metadata proof; never invoke the LABEL writer."""
from __future__ import annotations
import argparse
import gzip
import hashlib
import json
import os
from pathlib import Path
import struct
import local_label_projection as labels

ROOT_ADDRESS='0x00706320'
RECIPE='0576-dd603b7071c482c6'
MAX_OBJECT=16*1024**2
MAX_DIRECTORY=4*1024**2
MAX_LANE=128*1024**2
SUPPLEMENT=(185,79,1146,6,'0x00a2350f')
require=labels.require


def file_hash(path):
    h=hashlib.sha256()
    with Path(path).open('rb') as f:
        for part in iter(lambda:f.read(1024*1024),b''):h.update(part)
    return h.hexdigest()


def publish_report(path,report,check):
    """Exclusive, fsynced local publication with postwrite stability checks."""
    created=None
    try:
        check()
        with Path(path).open('x',encoding='utf-8') as f:
            stat=os.fstat(f.fileno());created=(stat.st_dev,stat.st_ino)
            json.dump(report,f,indent=2);f.write('\n');f.flush();os.fsync(f.fileno())
            check()
            current=Path(path).stat()
            require((current.st_dev,current.st_ino)==created,'LABEL output identity changed')
    except BaseException:
        if created is not None and Path(path).exists():
            current=Path(path).stat()
            if (current.st_dev,current.st_ino)==created:Path(path).unlink()
        raise


def read_highlow_sites(path):
    """Seek/read PE headers and base-relocation directory only, not .text."""
    path=Path(path);size=path.stat().st_size
    with path.open('rb') as f:
        def take(offset,count):
            require(type(offset)is int and type(count)is int and 0<=offset<=size and 0<=count<=size-offset,'PE metadata bounds')
            f.seek(offset);raw=f.read(count);require(len(raw)==count,'truncated PE metadata');return raw
        dos=take(0,64);require(dos[:2]==b'MZ','PE DOS signature')
        pe=struct.unpack_from('<I',dos,60)[0];header=take(pe,24)
        require(header[:4]==b'PE\0\0','PE signature')
        machine,count,_,_,_,opt,_=struct.unpack_from('<HHIIIHH',header,4)
        require(machine==0x14c and 0<count<=96 and 144<=opt<=4096,'bounded PE32 header')
        optional=take(pe+24,opt);require(struct.unpack_from('<H',optional)[0]==0x10b,'PE32 required')
        base=struct.unpack_from('<I',optional,28)[0];directories=struct.unpack_from('<I',optional,92)[0]
        require(directories>=6 and 96+8*directories<=len(optional),'PE directory count')
        rva,extent=struct.unpack_from('<II',optional,96+5*8)
        require(0<extent<=MAX_DIRECTORY,'bounded base relocation directory required')
        table=take(pe+24+opt,count*40);matches=[]
        for i in range(count):
            name,virtual,va,rawsize,ptr=struct.unpack_from('<8sIIII',table,40*i)
            flags=struct.unpack_from('<I',table,40*i+36)[0]
            if va<=rva and rva+extent<=va+rawsize:
                require(name.rstrip(b'\0')==b'.reloc' and not flags&0x20000020,'base relocations outside noncode .reloc')
                matches.append((ptr+rva-va,va,rawsize,virtual))
        require(len(matches)==1,'ambiguous/unbacked relocation directory')
        directory=take(matches[0][0],extent);sites=[];pos=0;blocks=0
        while pos<len(directory):
            require(pos+8<=len(directory),'truncated relocation block')
            page,length=struct.unpack_from('<II',directory,pos)
            require(page%4096==0 and length>=8 and length%4==0 and pos+length<=len(directory),'invalid relocation block')
            for at in range(pos+8,pos+length,2):
                value=struct.unpack_from('<H',directory,at)[0];kind=value>>12
                require(kind in (0,3),'unsupported original base relocation type')
                if kind==3:
                    site=base+page+(value&4095);require(site<=0xffffffff-3,'original HIGHLOW address overflow');sites.append(site)
            blocks+=1;pos+=length
        require(len(sites)==len(set(sites)),'duplicate original HIGHLOW site')
        return set(sites),dict(image_base=f'0x{base:08x}',directory_rva=f'0x{rva:08x}',directory_extent=extent,
            directory_sha256=labels.sha(directory),blocks=blocks,highlow_sites=len(sites),original_text_payload_observed=False)


def read_fixed_operand(path,field_va):
    """Only the separately reviewed four-byte relocation operand, no body read."""
    require(field_va==SUPPLEMENT[4],'unreviewed original operand address')
    with Path(path).open('rb') as f:
        def take(off,n):
            require(0<=off and 0<=n<=4096,'bounded operand metadata read');f.seek(off);b=f.read(n)
            require(len(b)==n,'truncated operand metadata');return b
        dos=take(0,64);require(dos[:2]==b'MZ','operand DOS signature');pe=struct.unpack_from('<I',dos,60)[0]
        header=take(pe,24);require(header[:4]==b'PE\0\0','operand PE signature')
        machine,count,_,_,_,opt,_=struct.unpack_from('<HHIIIHH',header,4)
        require(machine==0x14c and 0<count<=96 and 32<=opt<=4096,'operand PE bounds')
        optional=take(pe+24,opt);require(struct.unpack_from('<H',optional)[0]==0x10b,'operand PE32')
        base=struct.unpack_from('<I',optional,28)[0];rva=int(field_va,16)-base;table=take(pe+24+opt,count*40);matches=[]
        for i in range(count):
            name,_,va,size,ptr=struct.unpack_from('<8sIIII',table,i*40);flags=struct.unpack_from('<I',table,i*40+36)[0]
            if va<=rva and rva+4<=va+size:
                require(name.rstrip(b'\0')==b'.text' and flags&0x20 and flags&0x20000000,'operand outside original CODE')
                matches.append(ptr+rva-va)
        require(len(matches)==1,'ambiguous/unbacked original operand')
        return struct.unpack('<I',take(matches[0],4))[0]


def observe(args):
    tools={Path(__file__).resolve():file_hash(__file__),Path(labels.__file__).resolve():file_hash(labels.__file__)}
    paths={k:Path(getattr(args,k)).resolve() for k in ('lane','manifest','reference','source')}
    expected={k:getattr(args,k+'_sha256') for k in paths}
    for k,path in paths.items():require(file_hash(path)==expected[k],'stale pinned '+k)
    out=Path(args.output).resolve();private=(Path(__file__).resolve().parents[2]/'build/rebuild').resolve()
    require(out.is_relative_to(private) and out!=private and not out.exists(),'new private output required')
    manifest=json.loads(paths['manifest'].read_text(encoding='utf-8-sig'))
    units=[u for u in manifest['units'] if u['recipe_id']==RECIPE];require(len(units)==1,'exact LABEL recipe missing')
    unit=units[0];require(unit['source_sha256']==expected['source'],'LABEL source manifest differs')
    repo=Path(__file__).resolve().parents[2]
    require(paths['source']==(repo/unit['source']).resolve(),'exact manifest source path required')
    obj=(paths['manifest'].parent/manifest.get('object_root_relative','.')/unit['object']).resolve()
    require(obj.is_relative_to(paths['manifest'].parent) and obj.stat().st_size<=MAX_OBJECT and out!=obj,'bounded manifest-selected object required')
    raw=obj.read_bytes();require(labels.sha(raw)==unit['object_sha256'],'stale original LABEL object')
    records=[];uncompressed=0;record_count=0
    with gzip.open(paths['lane'],'rt',encoding='utf-8') as f:
        for line in f:
            uncompressed+=len(line.encode());require(uncompressed<=MAX_LANE,'bounded own lane required')
            row=json.loads(line);record_count+=1
            require(record_count<=37 and row['recipe_id']==RECIPE and row['event'] in ('SINGLE_ROOT_OBSERVATION','RECIPE_ROOT_UNION_OBSERVATION'),'foreign lane record')
            if row['event']=='SINGLE_ROOT_OBSERVATION' and [r['original_address'] for r in row['requested_roots']]==[ROOT_ADDRESS]:records.append(row)
    require(len(records)==1,'exact singleton LABEL record missing')
    record=records[0];contract=record['contract'];frozen=record['certificate']
    require(labels.sha(labels.canonical(contract).encode())==record['contract_identity_sha256'] and
            labels.sha(labels.canonical(frozen).encode())==record['certificate_sha256'],'central LABEL hashes differ')
    require(record['recipe_id']==RECIPE and contract['provenance']['object_sha256']==unit['object_sha256'] and
            contract['provenance']['source_sha256']==expected['source'],'central original LABEL provenance differs')
    sites,pe=read_highlow_sites(paths['reference']);parsed=labels.coff.parse(raw)
    keep=frozen['retained_section_indices'];label_indices=set(labels.label_records(parsed,keep))
    fields={labels.canonical(r):r for r in contract['fields']+contract['omission_field_proofs'] if r['coff_relocation']['symbol_index'] in label_indices}
    existing_keys={(r['physical_section'],r['coff_relocation']['offset'],r['coff_relocation']['symbol_index'],r['coff_relocation']['kind']) for r in fields.values()}
    supplements=[]
    if SUPPLEMENT[:4] not in existing_keys:
        si,off,target,kind,field_va=SUPPLEMENT;s=parsed['symbols'][target];sec=parsed['sections'][si]
        require(target in label_indices and s['storage']==3 and s['section']==si and si not in keep and (off,target,kind) in sec['relocs'],'fixed supplemental native identity differs')
        owners=[v for v in contract['unit_verified_functions'] if v['section']==si and v['value']==0 and v['size']==sec['size'] and v['verdict']=='match']
        require(len(owners)==1 and int(owners[0]['address'],16)+off==int(field_va,16),'fixed original source span differs')
        bits=int.from_bytes(sec['payload'][off:off+4],'little');base=int(owners[0]['address'],16)+s['value']
        operand=read_fixed_operand(paths['reference'],field_va)
        row=dict(recipe_id=RECIPE,function_va=owners[0]['address'],physical_section=si,physical_offset=off,
            source_field_offset=off,original_field_va=field_va,original_operand=operand,
            coff_relocation=dict(offset=off,symbol_index=target,kind=kind,width=4,symbol=s['name'],symbol_section=si,
                symbol_value=s['value'],symbol_type=s['type'],symbol_storage=s['storage'],addend=bits),
            derived_source_symbol_base_va=f'0x{base:08x}',exact_original_target_va=f'0x{(base+bits)&0xffffffff:08x}',
            classification='UNIQUE_CODE_INTERIOR_OR_LOCAL_LABEL_NOT_CALLABLE_APPROVAL',physical_field_overlap_count=1,
            proof_consistency='EXACT_OWN_SOURCE_RESOLUTION',source_resolution_basis='BOUND_ORIGINAL_LOCAL_LABEL_OPERAND',
            supplemental_authority=dict(kind='source-bound-original-code-relocation-operand',width=4,
                original_reference_sha256=expected['reference'],original_object_sha256=unit['object_sha256'],
                original_field_va=field_va,original_operand=operand,native_field=[si,off,target,kind]))
        supplements.append(row);fields[labels.canonical(row)]=row
    authority=dict(reference_sha256=expected['reference'],original_highlow_metadata=pe,central_lane_sha256=expected['lane'],central_record_sha256=labels.sha(labels.canonical(record).encode()))
    evidence=dict(object_sha256=unit['object_sha256'],source_sha256=expected['source'],authority_sha256=labels.sha(labels.canonical(authority).encode()),
        contract_sha256=record['contract_identity_sha256'],keep_sections=keep,keep_symbols=frozen['retained_primary_indices'],unit_functions=contract['unit_verified_functions'],
        fields=[fields[k] for k in sorted(fields)],original_highlow_sites=[f'0x{site:08x}' for site in sorted(sites)],supplemental_fields=supplements)
    cert=labels.prove_labels(raw,evidence);decision=labels.decode_label_policy(raw,contract,frozen,cert)
    def stable():
        for k,path in paths.items():require(file_hash(path)==expected[k],'pinned LABEL input changed')
        for path,h in tools.items():require(file_hash(path)==h,'LABEL observation tool changed')
        require(file_hash(obj)==unit['object_sha256'],'original LABEL object changed')
    stable()
    require(out not in set(paths.values())|{obj},'output/input collision')
    report=dict(kind='bounded-original-local-label-observation',policy_id=labels.POLICY,root=ROOT_ADDRESS,recipe_id=RECIPE,
        inputs=expected,original_object_sha256=unit['object_sha256'],authority=authority,evidence=evidence,
        label_certificate=dict(evidence_json=cert.evidence_json,decision_json=cert.decision_json),decision=decision,
        original_objects_read=1,whole_reference_hashed=True,original_text_body_observed=False,
        original_text_relocation_operand_bytes_read=4*len(supplements),source_bodies_included=False,object_emission_performed=False,
        native_operation_performed=False,provider_selected=False,runtime_eligible=False,
        producer_sha256=tools[Path(__file__).resolve()],label_tool_sha256=tools[Path(labels.__file__).resolve()],independent_output_review_pending=True)
    publish_report(out,report,stable)
    return report


def main():
    p=argparse.ArgumentParser(description=__doc__)
    for k in ('lane','manifest','reference','source'):
        p.add_argument('--'+k,type=Path,required=True);p.add_argument('--'+k+'-sha256',required=True)
    p.add_argument('--output',type=Path,required=True);a=p.parse_args();r=observe(a)
    print(json.dumps(dict(root=r['root'],discharged=len(r['decision']['discharged_blocker_ids']),remaining=len(r['decision']['remaining_blockers']),emission=False)))


if __name__=='__main__':main()
