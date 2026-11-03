"""Fixed 446-byte private DATA projection with sixteen address-only aliases.

No compiler/linker/execution, arbitrary range, typed extent or runtime adoption.
Existing arena planner and original fixture remain unchanged.
"""
from __future__ import annotations
import copy
import hashlib
import json
from pathlib import Path
import struct
import tempfile

import data_arena_projection as arena
from coff_rewrite import strict_object
from data_plan import Pe
import runtime_code_pool as namespace

ROOT=Path(__file__).resolve().parents[2]
POLICY_ID='entry-raw-aliases-v1'
SELECTION_SHA='c35bdda25e5f797da6e0b088ca1b78a8b461779c7f088d0bac951fba674a3893'
OWNED_SHA='3a87f92f011e5dc9179ddf733cf08be2b39ea6e5b7a8a9e3a9a72dafcc1b104d'
REFERENCE_SHA='df1788907c6e26ef4df0b448ead526825336356b5606650165a1ce0825097eb7'
SCOPE=[dict(fragment_id='cb8d58d939251b22cc7429f62751a51e83d1c6f11abeef2489d3b96a973b7c1a',
    start=0x10828e9,size=219,payload_sha256='85075986c217c34e5e30b1db7ae066192496e1114d28afe108a34c150094cad6',
    bases=[0x10828ec,0x10828fc,0x1082910,0x1082924,0x108293c,0x108295c,0x1082978,0x1082990,0x10829b4]),
    dict(fragment_id='a80a7435d3665b08022dc0a36be353e4ffafa56da5fd9b4337224164f96aedeb',
    start=0x10829fd,size=227,payload_sha256='be434b05ac538cb305c1402ff6d341eddfb82c2db2fa60577898ad5e7e38bb84',
    bases=[0x1082a00,0x1082a10,0x1082a28,0x1082a38,0x1082a48,0x1082a7c,0x1082ab8])]
require=arena.require


def sha(path):
    h=hashlib.sha256()
    with Path(path).open('rb') as stream:
        while block:=stream.read(1048576):h.update(block)
    return h.hexdigest()


def stable(bindings):
    require(bindings and all(sha(p)==h for p,h in bindings.items()),'protected input changed')


def policy_contract(policy):
    require(policy.get('schema_version')==1 and policy.get('policy_id')==POLICY_ID and
        policy.get('selection_sha256')==SELECTION_SHA and policy.get('owned_sha256')==OWNED_SHA and
        policy.get('reference_sha256')==REFERENCE_SHA,'fixed selection/image policy differs')
    arena.no_approval(policy)
    require(policy.get('default_action')=='verify-only' and policy.get('private_projection_requires_exact_review') is True,
            'default emission or absent separate review forbidden')
    require(set(policy.get('implementation_pins',{}))=={'tools/rebuild/data_arena_projection.py','tools/rebuild/runtime_code_pool.py',
        'tools/rebuild/coff_code_archive.py','tools/rebuild/coff_rewrite.py','tools/rebuild/coff_inventory.py','tools/rebuild/data_plan.py'} and
        all(arena.hash_value(h) for h in policy['implementation_pins'].values()),'dependency pins incomplete')
    rows=policy.get('fragments',[]);require(len(rows)==2,'fixed two-fragment policy required')
    for f,expected in zip(rows,SCOPE):
        require(all(f.get(k)==expected[k] for k in ('fragment_id','start','size','payload_sha256')) and
            f.get('flags')==0x40000040 and f.get('alignment')==1,'fixed whole-fragment geometry differs')
        aliases=f.get('aliases',[]);require(len(aliases)==len(expected['bases']),'fixed alias count differs')
        require(sorted(int(a['original_base'],16) for a in aliases)==expected['bases'],'alias base identities differ')
        for a in aliases:
            base=int(a['original_base'],16)
            require(a['role']=='data' and a['canonical_symbol']==namespace.unresolved(a['original_base'],'data') and
                a['fragment_offset']==base-f['start'] and a['object_extent'] is None and a['object_type'] is None and
                a['lifetime_approved'] is False,'alias identity/offset/role or typed extent differs')


def verify_selection(selection,policy):
    """Pure schema check; the file entry additionally pins the exact receipt."""
    policy_contract(policy);arena.no_approval(selection)
    require(selection.get('kind')=='data-arena-pilot-selection' and
        selection.get('status')=='TWO_WHOLE_RAW_FRAGMENTS_PROPOSED_NO_EMISSION' and
        selection.get('original_owned_sha256')==OWNED_SHA and selection.get('original_reference_sha256')==REFERENCE_SHA,
        'unsupported selection state/inputs')
    rows=selection.get('selected_fragment_proposals',[]);require(len(rows)==2,'selection scope differs')
    total=0;all_names=set();field_ids=set()
    for row,p in zip(rows,policy['fragments']):
        f=row['fragment'];require(all(f[k]==p[k] for k in ('fragment_id','start','size','flags','alignment')) and
            f['admitted'] is True and f['backing']=='raw' and not f['adjacency_to_other_fragments_proved'] and
            f['object_extent'] is None and f['object_type'] is None and not f['lifetime_approved'], 'non-raw/reserved/changed fragment')
        domain=f['original_domain'];require(domain['families']==['ORDINARY_UNCLASSIFIED'] and domain['overlap'] is False and
            domain['start']==f['start'] and domain['end']==f['start']+f['size'],'fragment domain differs')
        require(row['payload_sha256']==p['payload_sha256'] and row['owned_reference_payload_equal'] is True and
            row['contained_HIGHLOW_fields']==[] and row['contained_field_sequence_sha256']==hashlib.sha256(b'').hexdigest() and
            row['conflicting_storage_evidence']==[],'HIGHLOW/conflicting/payload evidence differs')
        aliases=row['aliases'];require(len(aliases)==len(p['aliases']),'selection alias count differs')
        indexed={a['canonical_symbol']:a for a in aliases}
        require(len(indexed)==len(aliases),'duplicate alias identity')
        for a in p['aliases']:
            found=indexed.get(a['canonical_symbol']);require(found and all(found.get(k)==v for k,v in a.items()),'selection alias differs')
            require(a['canonical_symbol'] not in all_names,'duplicate cross-fragment alias');all_names.add(a['canonical_symbol'])
        expected=[]
        for e in row['related_entry_fields']:
            r=e['record'];c=r['coff_relocation'];base=r['derived_source_symbol_base_va']
            require(r['function_va']=='0x0086a850' and r['recipe_id']=='0576-dd603b7071c482c6' and
                r['classification']=='ORIGINAL_IMAGE_DATA_REQUIRES_CANONICAL_OWNER' and
                r['exact_original_target_va']==base and c['kind']==6 and c['addend']==0 and
                c['symbol_section']==0 and c['symbol_storage']==2,'entry field base/addend/kind/source role differs')
            name=namespace.unresolved(base,'data');require(name in indexed,'entry demand alias absent')
            identity=(r['function_va'],r['physical_section'],r['physical_offset'],c['symbol_index'])
            require(identity not in field_ids,'duplicate entry field');field_ids.add(identity)
            expected.append((e['binding_ordinal'],arena.digest(r),name,r['source_field_offset'],c['symbol_index'],c['symbol']))
        observed=[]
        for name,a in indexed.items():
            require(a['source_symbol_records'],'alias has no actual entry demand')
            for r in a['source_symbol_records']:
                require(r['addend']==0 and r['recipe_id']=='0576-dd603b7071c482c6','alias demand proof differs')
                observed.append((r['binding_ordinal'],r['binding_sha256'],name,r['field_offset'],r['original_symbol_index'],r['original_symbol']))
        require(sorted(expected)==sorted(observed),'alias/entry field bijection differs');total+=len(expected)
    require(len(all_names)==16 and total==20 and selection['alias_definitions_proposed']==16 and
        selection['actual_entry_fields']==20 and selection['total_raw_bytes']==446,'complete fixed counts differ')
    return rows


def alias_object(fragment,aliases,payload):
    """Append same-section external names; no new storage or field relocation."""
    require(fragment['backing']=='raw' and fragment['admitted'] and fragment['flags']==0x40000040 and
        fragment['alignment']==1 and len(payload)==fragment['size'],'unsupported raw object geometry')
    data=arena.object_bytes(fragment,[],payload);machine,count,stamp,symptr,symcount,opt,flags=struct.unpack_from('<HHIIIHH',data)
    require((machine,count,symcount,opt,flags)==(0x14c,1,2,0,0),'unexpected base DATA serializer')
    strings=bytearray(data[symptr+18*symcount:]);extra=bytearray();seen={fragment['anchor'],'@feat.00'}
    for alias in aliases:
        name=alias['canonical_symbol'];offset=alias['fragment_offset'];base=int(alias['original_base'],16)
        require(name==namespace.unresolved(alias['original_base'],'data') and alias['role']=='data' and name not in seen and
            offset==base-fragment['start'] and 0<=offset<fragment['size'] and
            alias['object_extent'] is None and alias['object_type'] is None and alias['lifetime_approved'] is False,
            'invalid duplicate/typed/offset alias')
        seen.add(name);extra+=struct.pack('<IIIhHBB',0,len(strings),offset,1,0,2,0);strings+=name.encode('ascii')+b'\0'
    struct.pack_into('<I',strings,0,len(strings));out=bytearray(data[:symptr+18*symcount]+extra+strings)
    struct.pack_into('<I',out,12,symcount+len(aliases));return bytes(out)


def validate_object(path,fragment,aliases,payload):
    coff,_,_,_=strict_object(path)
    require(len(coff.sections)==1 and not coff.directives,'hidden section/directive')
    sec=coff.sections[1];require((sec['name'],sec['size'],sec['flags'],sec['relocs'])==
        ('.data',fragment['size'],0x40100040,[]),'output geometry/flags/relocations differ')
    raw=struct.unpack_from('<I',coff.data,40)[0]
    require(raw>0 and coff.data[raw:raw+sec['size']]==payload,'raw initialized payload changed')
    expected={fragment['anchor']:(1,0,2),'@feat.00':(-1,1,3)}
    for a in aliases:
        require(a['canonical_symbol'] not in expected,'duplicate output alias')
        expected[a['canonical_symbol']]=(1,a['fragment_offset'],2)
    actual={s['name']:(s['section'],s['value'],s['storage']) for s in coff.symbols.values()}
    require(len(coff.symbols)==len(expected) and actual==expected and all(s['type']==0 and s['aux_count']==0 for s in coff.symbols.values()),
            'output alias section/value/type/aux/feature differs')
    return dict(fragment_id=fragment['fragment_id'],object_sha256=sha(path),payload_sha256=hashlib.sha256(payload).hexdigest(),
        aliases=[dict(symbol=a['canonical_symbol'],section=1,value=a['fragment_offset'],original_base=a['original_base'],role='data',
            object_extent=None,object_type=None) for a in aliases],relocations=0,initialized_bytes=len(payload),**arena.FALSE)


def protected_inputs(selection,policy,selection_path,policy_path,owned,reference,root):
    root=Path(root).resolve();bindings={str(Path(p).resolve()):sha(p) for p in
        (selection_path,policy_path,owned,reference,Path(__file__),Path(arena.__file__),Path(namespace.__file__),
         root/'tools/rebuild/coff_rewrite.py',root/'tools/rebuild/coff_inventory.py',root/'tools/rebuild/coff_code_archive.py',root/'tools/rebuild/data_plan.py')}
    for relative,h in selection['inputs'].items():
        path=(root/relative).resolve();require(path.is_relative_to(root),'selection input escapes root')
        require(str(path) not in bindings or bindings[str(path)]==h,'selection input conflict');bindings[str(path)]=h
    for relative,h in policy['implementation_pins'].items():
        path=(root/relative).resolve();require(path.is_relative_to(root),'implementation input escapes root')
        require(str(path) not in bindings or bindings[str(path)]==h,'implementation source hash differs');bindings[str(path)]=h
    stable(bindings);return bindings


def load_verified(selection_path,policy_path,owned,reference,root):
    require(sha(selection_path)==SELECTION_SHA and sha(owned)==OWNED_SHA and sha(reference)==REFERENCE_SHA,'fixed receipt/image changed')
    selection=json.loads(Path(selection_path).read_text());policy=json.loads(Path(policy_path).read_text());rows=verify_selection(selection,policy)
    bindings=protected_inputs(selection,policy,selection_path,policy_path,owned,reference,root)
    pe,ref=Pe(owned),Pe(reference);payloads=[]
    try:
        intervals=[(r['fragment']['start'],r['fragment']['start']+r['fragment']['size']) for r in rows]
        # Metadata only outside the exact446 raw bytes: never inspect code.
        for site in pe.relocations():
            for lo,hi in intervals:require(not (site+pe.base<hi and site+pe.base+4>lo),'unexpected/crossing HIGHLOW in fixed raw fragment')
        for row in rows:
            f=row['fragment'];geometry=row['original_input_geometry']
            require(pe.base==ref.base==geometry['image_base'] and pe.image_size==ref.image_size==geometry['image_size'],'image geometry changed')
            s=pe.section(f['start']-pe.base,f['size'],required=True);other=ref.section(f['start']-ref.base,f['size'],required=True)
            require(s==other==geometry['section'] and s['name']=='.rdata' and not s['executable'] and s['flags']==0x40000040 and
                s['raw_offset']+f['start']-pe.base-s['rva']==geometry['fragment_file_offset'] and
                f['start']-pe.base-s['rva']+f['size']<=s['raw_size'],'raw section/file extent changed')
            raw=pe.read_rva(f['start']-pe.base,f['size']);original=ref.read_rva(f['start']-ref.base,f['size'])
            require(raw==original and hashlib.sha256(raw).hexdigest()==row['payload_sha256'],'raw fragment identity changed')
            payloads.append(raw)
    finally:pe.close();ref.close()
    stable(bindings);return selection,policy,rows,payloads,bindings


def project(selection_path,policy_path,owned,reference,root,review_path,out):
    """Requires separate exact source review plus explicit root projection go."""
    out=Path(out).resolve();review_path=Path(review_path).resolve();review_sha=sha(review_path);review=json.loads(review_path.read_text())
    policy=json.loads(Path(policy_path).read_text());policy_contract(policy)
    require(review.get('kind')=='entry-raw-alias-projection-review' and review.get('phase')=='private-446B-projection' and
        review.get('approved') is True and review.get('root_authorized') is True and review.get('reviewer') and
        review.get('selection_sha256')==SELECTION_SHA and review.get('policy_file_sha256')==sha(policy_path) and
        review.get('source_sha256')==sha(__file__),'separate private projection authorization absent/stale')
    selection,policy,rows,payloads,bindings=load_verified(selection_path,policy_path,owned,reference,root)
    bindings[str(review_path)]=review_sha
    require(not out.exists() and all(out!=Path(p) and out not in Path(p).parents for p in bindings),'output/input collision')
    staged=[]
    with tempfile.TemporaryDirectory(prefix='fnv_raw_aliases_') as tmp:
        for row,payload in zip(rows,payloads):
            f=row['fragment'];path=Path(tmp)/(f['fragment_id']+'.obj');path.write_bytes(alias_object(f,row['aliases'],payload))
            staged.append((path,validate_object(path,f,row['aliases'],payload)))
        stable(bindings);out.mkdir();created=[]
        try:
            for path,record in staged:
                dest=out/path.name
                with dest.open('xb') as stream:created.append(dest);stream.write(path.read_bytes())
                require(sha(dest)==record['object_sha256'],'published object differs')
            report=dict(schema_version=1,kind='private-entry-raw-alias-projection',selection_sha256=SELECTION_SHA,
                review_sha256=review_sha,protected_inputs=bindings,objects=[r for _,r in staged],initialized_bytes=446,
                aliases=16,entry_fields=20,relocations=0,typed_extent_proved=False,**arena.FALSE)
            stable(bindings);receipt=out/'projection.json'
            with receipt.open('x') as stream:created.append(receipt);json.dump(report,stream,indent=2);stream.write('\n')
            stable(bindings);return report
        except Exception:
            for path in created:path.unlink()
            out.rmdir();raise
