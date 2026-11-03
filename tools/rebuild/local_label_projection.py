"""Typed local COFF LABEL proof and preserving serializer; no native/disk work.

Authority receipts and original-image observations are supplied by a separately
reviewed caller. A self-consistent authored witness is not runtime authorization.
"""
from __future__ import annotations
from dataclasses import dataclass
import hashlib
import json
from pathlib import Path
import re
import struct
import coff_code_archive as coff

POLICY = 'physical-code-local-label-v3'
FROZEN_PARSER = '76244d2d4dca4c1f8aa72224be1ef5c92f68976b5cda7d31b5cfe23d3cc29e64'
FROZEN_OBSERVER = '4bfdb5001380a3d7e5db7517033285d49ab211be68e2fcba15964f0ad5b03c53'
require = coff.require


def canonical(value):
    return json.dumps(value, sort_keys=True, separators=(',', ':'))


def sha(value):
    return hashlib.sha256(value).hexdigest()


def integer(value):
    require(type(value) is int, 'noninteger physical identity')
    return value


def address(value):
    require(isinstance(value, str) and re.fullmatch('0x[0-9a-f]{8}', value), 'invalid original address')
    return int(value, 16)


@dataclass(frozen=True)
class LabelCertificate:
    """Immutable evidence serialization, always revalidated by the writer."""
    evidence_json: str
    decision_json: str


def label_records(obj, keep_sections):
    """Candidate scope only; every returned physical record needs full proof.

    Include same-spelling STATIC records to prove that they are local too,
    rather than treating an omitted local name as an implicit external lookup.
    Equal names never combine records, references or owner identities.
    """
    is_name=lambda s: re.fullmatch(r'\$LN[0-9]+',s['name']) is not None
    result={i:s for i,s in obj['symbols'].items() if s['storage']==6 or
            (s['storage']==3 and s['section'] in keep_sections and is_name(s) and not s['aux_count'])}
    names={s['name'] for s in result.values()}
    result.update({i:s for i,s in obj['symbols'].items() if s['storage']==3 and s['name'] in names})
    return result


def prove_labels(raw, evidence):
    """Check native physical uses and exact original operand/target equations.

    Evidence keys: object_sha256, source_sha256, authority_sha256,
    contract_sha256, keep_sections, keep_symbols, unit_functions, fields,
    original_highlow_sites. Fields use existing binding-ledger row spellings.
    All rows and HIGHLOW sites must come from independently bound observations.
    """
    require(sha(Path(coff.__file__).read_bytes()) == FROZEN_PARSER, 'frozen parser source changed')
    required = {'object_sha256', 'source_sha256', 'authority_sha256', 'contract_sha256',
                'keep_sections', 'keep_symbols', 'unit_functions', 'fields', 'original_highlow_sites'}
    require(set(evidence) in (required,required|{'supplemental_fields'}), 'label evidence schema differs')
    for key in ('object_sha256', 'source_sha256', 'authority_sha256', 'contract_sha256'):
        require(isinstance(evidence[key], str) and re.fullmatch('[0-9a-f]{64}', evidence[key]), 'invalid evidence digest')
    require(sha(raw) == evidence['object_sha256'], 'stale label object')
    obj = coff.parse(raw); sections = obj['sections']; symbols = obj['symbols']
    ks, ky = evidence['keep_sections'], evidence['keep_symbols']
    require(type(ks) is list and type(ky) is list, 'selection lists required')
    require(all(type(i) is int for i in ks + ky) and ks == sorted(set(ks)) and ky == sorted(set(ky)), 'invalid physical selection')
    require(set(ks) <= sections.keys() and set(ky) <= symbols.keys(), 'absent selected identity')
    require(all(sections[i]['name'] in ('.text', '.drectve') for i in ks), 'special retained section outside LABEL writer scope')
    for f in evidence['unit_functions']:
        require(all(type(f[k]) is int for k in ('section','value','size')) and f['section'] in sections
                and f['value'] >= 0 and f['size'] > 0 and f['value']+f['size'] <= sections[f['section']]['size']
                and address(f['address'])+f['size'] <= 0x100000000, 'invalid checked physical CODE span')
    label_name = lambda s: re.fullmatch(r'\$LN[0-9]+', s['name']) is not None
    require(not any(label_name(s) and s['storage'] not in (3,6) for s in symbols.values()), 'unsupported local LABEL spelling/storage')
    labels = label_records(obj,ks)
    require(labels, 'no typed local labels')
    owners = {}
    for i, s in labels.items():
        sec = sections.get(s['section'])
        require(s['storage'] in (3, 6) and s['type'] == 0 and s['aux_count'] == 0 and label_name(s), 'unsupported LABEL record')
        require(sec and sec['name'] == '.text' and sec['flags'] == 0x60501020
                and 0 <= s['value'] < sec['size'] and len(sec['payload']) == sec['size'], 'LABEL outside backed CODE')
        matches = [f for f in evidence['unit_functions'] if f['section'] == s['section'] and f['value'] == 0
                   and f['size'] == sec['size'] and f['verdict'] == 'match']
        require(len(matches) == 1, 'LABEL needs unique full checked CODE owner')
        f = matches[0]; address(f['address'])
        native = [v for v in symbols.values() if (v['name'], v['section'], v['value'], v['type'], v['storage'], v['aux_count'])
                  == (f['symbol'], f['section'], 0, 32, 2, 0)]
        require(len(native) == 1, 'checked owner native identity differs')
        owners[i] = f
        require((i in ky) == (s['section'] in ks), 'LABEL retention differs from physical section')
    names = {s['name'] for s in labels.values()}
    require(not any(s['name'] in names and i not in labels for i, s in symbols.items()), 'ambiguous implicit LABEL name lookup')
    for s in symbols.values():
        require(s['storage'] != 105 and not (s['section'] == 0 and s['value']), 'weak/common lookup unsupported')
        if s['aux_count']:
            if s['storage'] == 103 and s['section'] == -2:
                continue
            require(s['storage'] == 3 and s['type'] == 0 and s['value'] == 0 and s['aux_count'] == 1
                    and s['section'] in sections and s['name'] == sections[s['section']]['name'], 'unknown auxiliary index context')
            a = struct.unpack('<IHHIhBBH', s['aux']); sec = sections[s['section']]
            require(a[0] == sec['size'] and a[1] == len(sec['relocs']) and not a[2] and not a[6] and not a[7]
                    and a[5] in range(8) and (a[4] in sections if a[5] == 5 else a[4] == 0), 'unknown section auxiliary context')
    for sec in sections.values():
        if sec['name'] == '.sxdata':
            require(not sec['relocs'] and len(sec['payload']) % 4 == 0, 'unsupported SafeSEH context')
            indices = struct.unpack('<' + 'I' * (len(sec['payload']) // 4), sec['payload'])
            require(set(indices) <= symbols.keys(), 'absent SafeSEH index')
            require(not set(indices) & labels.keys(), 'LABEL used as SafeSEH handler')
        if sec['name'] == '.drectve':
            require(not sec['relocs'] and not any(n.encode() in sec['payload'] for n in names), 'directive LABEL lookup unsupported')
            directives=re.findall(r'(?:[^\s"\x00]+|"[^"]*")+',sec['payload'].decode('ascii'))
            require(sec['flags']==0x100a00 and directives == ['/DEFAULTLIB:"LIBCMT"','/DEFAULTLIB:"OLDNAMES"'], 'unknown LABEL directive contract')
    use_list = [(si, off, target, kind) for si, sec in sections.items() for off, target, kind in sec['relocs'] if target in labels]
    uses = set(use_list)
    require(len(uses) == len(use_list), 'duplicate native LABEL field')
    witnesses = {}
    for row in evidence['fields']:
        r = row['coff_relocation']; key = (row['physical_section'], r['offset'], r['symbol_index'], r['kind'])
        require(all(type(v) is int for v in key) and all(type(r[k]) is int for k in ('symbol_section','symbol_value','symbol_type','symbol_storage','addend','width'))
                and type(row['physical_offset']) is int and type(row['physical_field_overlap_count']) is int, 'noninteger LABEL field identity')
        require(key not in witnesses, 'duplicate LABEL field witness')
        require(key in uses, 'extra LABEL field witness')
        witnesses[key] = row
    require(set(witnesses) == uses, 'incomplete full physical LABEL uses')
    highlow = evidence['original_highlow_sites']
    require(isinstance(highlow, list) and len(highlow) == len(set(highlow)), 'duplicate HIGHLOW evidence')
    highlow = {address(v) for v in highlow}
    for (si, off, target, kind), row in witnesses.items():
        sec, label = sections[si], labels[target]
        require(kind in (6, 20) and off + 4 <= sec['size'], 'unsupported LABEL field geometry')
        r = row['coff_relocation']; bits = int.from_bytes(sec['payload'][off:off+4], 'little')
        require((r['symbol'], r['symbol_section'], r['symbol_value'], r['symbol_type'], r['symbol_storage'], r['addend'], r['width'])
                == (label['name'], label['section'], label['value'], 0, label['storage'], bits, 4), 'changed native LABEL field')
        sources = [f for f in evidence['unit_functions'] if f['section'] == si and f['verdict'] == 'match'
                   and f['value'] <= off and off + 4 <= f['value'] + f['size']]
        require(len(sources) == 1, 'LABEL use source span unproved')
        f = sources[0]; field_va = address(f['address']) + off - f['value']
        require(len([s for s in symbols.values() if (s['name'],s['section'],s['value'],s['type'],s['storage'],s['aux_count'])
                    == (f['symbol'],f['section'],f['value'],32,2,0)]) == 1, 'LABEL source native owner differs')
        widths = {0:0,1:2,2:2,6:4,7:4,9:2,10:2,11:4,12:4,13:1,20:4}
        require(sum(pos < off+4 and off < pos+widths[k] for pos,t,k in sec['relocs']) == 1, 'overlapping native LABEL field')
        base = address(owners[target]['address']) + label['value']
        add = bits if kind == 6 or bits < 0x80000000 else bits - 0x100000000
        final = (base + add) & 0xffffffff
        require(address(owners[target]['address']) <= final < address(owners[target]['address']) + owners[target]['size'],
                'LABEL target escapes checked CODE interior')
        require(row['proof_consistency'] == 'EXACT_OWN_SOURCE_RESOLUTION' and row['physical_field_overlap_count'] == 1
                and row['physical_offset'] == off and address(row['function_va']) == address(f['address'])
                and address(row['original_field_va']) == field_va and address(row['derived_source_symbol_base_va']) == base
                and address(row['exact_original_target_va']) == final, 'nonexact LABEL source/target witness')
        operand = integer(row['original_operand']) & 0xffffffff
        observed = operand if kind == 6 else (field_va + 4 + operand) & 0xffffffff
        require(observed == final and ((field_va in highlow) if kind == 6 else field_va not in highlow), 'original operand/HIGHLOW mismatch')
        if si in ks:
            require(label['section'] in ks and target in ky, 'retained LABEL use escapes selection')
    decision = dict(policy_id=POLICY, object_sha256=sha(raw), evidence_sha256=sha(canonical(evidence).encode()),
                    labels=sorted(labels), retained_labels=sorted(set(labels) & set(ky)), physical_uses=len(uses),
                    label_records_preserved=True, provider_selected=False, runtime_eligible=False, emission_approved=False)
    return LabelCertificate(canonical(evidence), canonical(decision))


def decode_label_policy(raw, contract, frozen_certificate, label_certificate):
    """Discharge only exact typed label blocker IDs after frozen recomputation.

    This is a separate decision, never an edited or newly eligible 4bf result.
    Caller must independently authenticate original HIGHLOW observations and
    trusted receipt/contract/producer hashes before any private disk emission.
    """
    import root_code_closure as observer
    require(sha(Path(observer.__file__).read_bytes()) == FROZEN_OBSERVER, 'frozen observer source changed')
    require(observer.assess_object(coff.parse(raw), contract) == frozen_certificate, 'frozen certificate recomputation differs')
    require(type(label_certificate) is LabelCertificate, 'typed LABEL certificate required')
    e = json.loads(label_certificate.evidence_json)
    require(prove_labels(raw,e) == label_certificate, 'stale typed LABEL proof')
    require(e['contract_sha256'] == sha(canonical(contract).encode()), 'LABEL contract binding differs')
    require(e['source_sha256'] == contract['provenance']['source_sha256'] and
            e['object_sha256'] == contract['provenance']['object_sha256'], 'LABEL source/object provenance differs')
    require(e['keep_sections'] == frozen_certificate['retained_section_indices'] and
            e['keep_symbols'] == frozen_certificate['retained_primary_indices'], 'LABEL scope differs from frozen certificate')
    require(e['unit_functions'] == contract['unit_verified_functions'], 'LABEL checked owner ledger differs')
    labels = set(json.loads(label_certificate.decision_json)['labels'])
    expected = {canonical(r) for r in contract['fields'] + contract['omission_field_proofs']
                if r['coff_relocation']['symbol_index'] in labels}
    obj = coff.parse(raw); discharged=[]; remaining=[]
    supplements=e.get('supplemental_fields',[])
    require(type(supplements)is list and len({canonical(r) for r in supplements})==len(supplements),'duplicate supplemental LABEL witness')
    for row in supplements:
        rel=row['coff_relocation'];s=obj['symbols'][rel['symbol_index']];authority=row['supplemental_authority']
        require(isinstance(contract['provenance'].get('reference_identity_sha256'),str) and
                re.fullmatch('[0-9a-f]{64}',contract['provenance']['reference_identity_sha256']), 'supplement needs exact original reference identity')
        require(rel['symbol_index'] in labels and s['storage']==3 and s['section'] not in e['keep_sections']
                and row['physical_section']==s['section'] and rel['kind']==6,'supplement outside omitted local STATIC CODE scope')
        require(authority == dict(kind='source-bound-original-code-relocation-operand',width=4,
                original_reference_sha256=contract['provenance']['reference_identity_sha256'],
                original_object_sha256=e['object_sha256'],original_field_va=row['original_field_va'],
                original_operand=row['original_operand'],native_field=[row['physical_section'],rel['offset'],rel['symbol_index'],6]),
                'supplemental original/native authority binding differs')
        require(canonical(row) not in expected,'supplement duplicates original LABEL ledger')
    require({canonical(r) for r in e['fields']} == expected|{canonical(r) for r in supplements}, 'LABEL original field proof ledger differs')
    for b in frozen_certificate['blockers']:
        i = b['evidence']; code = b['code']
        known = type(i) is int and i in labels and (
            code == 'LABEL_OMISSION_NOT_PROVED' or
            (code in ('UNPROVED_RETAINED_ENTRY_OR_ALIAS','UNSUPPORTED_LIVE_REFERENCE_RECORD') and
             i in e['keep_symbols'] and obj['symbols'][i]['storage'] == 6))
        (discharged if known else remaining).append(b)
    return dict(policy_id=POLICY, frozen_certificate_sha256=sha(canonical(frozen_certificate).encode()),
                label_certificate_sha256=sha(label_certificate.decision_json.encode()),
                discharged_blocker_ids=[b['blocker_id'] for b in discharged], remaining_blockers=remaining,
                typed_label_blockers_only=not remaining, frozen_certificate_changed=False,
                namespace_approved=False, provider_selected=False, runtime_eligible=False,
                original_highlow_authority_authenticated=False, emission_approved=False)


def serialize_labels(raw, keep_sections, keep_symbols, undefined, label_certificate):
    """Preserve LABEL storage6 directly; never stage labels as another class."""
    require(type(label_certificate) is LabelCertificate, 'typed LABEL certificate required')
    evidence = json.loads(label_certificate.evidence_json)
    require(prove_labels(raw, evidence) == label_certificate, 'stale or altered LABEL certificate')
    require(keep_sections == evidence['keep_sections'] and keep_symbols == evidence['keep_symbols'], 'LABEL certificate selection differs')
    obj = coff.parse(raw); secs, syms = obj['sections'], obj['symbols']; ks, ky = keep_sections, keep_symbols
    undef = set(undefined)
    require(all(type(i) is int for i in undefined) and len(undefined) == len(undef) and undef <= set(ky), 'invalid undefined set')
    require(not any(syms[i]['storage'] == 6 or syms[i]['name'].startswith('$LN') for i in undef), 'LABEL conversion forbidden')
    sm = {i: j+1 for j, i in enumerate(ks)}; ym = {}; am = {}; cursor = 0
    for i in ky:
        ym[i] = cursor
        for j in range(syms[i]['aux_count']): am[i+1+j] = cursor+1+j
        cursor += 1 + syms[i]['aux_count']
    strings = bytearray(4)
    def encoded(name, section=False):
        n = name.encode('ascii')
        if len(n) <= 8: return n.ljust(8, b'\0')
        off = len(strings); strings.extend(n+b'\0')
        if section:
            b = ('/'+str(off)).encode(); require(len(b) <= 8, 'long section offset'); return b.ljust(8, b'\0')
        return struct.pack('<II', 0, off)
    sn = {i: encoded(secs[i]['name'], True) for i in ks}; records = bytearray(); expected = {}
    for i in ky:
        s = syms[i]; x = dict(s)
        require(s['storage'] in (2, 3, 6), 'unsupported retained storage')
        if i in undef:
            require(s['section'] > 0 and s['section'] not in sm and not s['aux_count'] and s['storage'] in (2,3), 'unsupported conversion')
            x.update(section=0, value=0, storage=2)
        else:
            require(s['section'] <= 0 or s['section'] in sm, 'definition escapes selected sections')
            metadata = s['storage'] == 3 and s['type'] == 0 and not s['aux_count'] and (s['name'] == '@comp.id' or (s['name'] == '@feat.00' and s['value'] == 1))
            require(not (s['section'] == 0 and s['value']) and (s['section'] != -1 or metadata), 'common/absolute runtime binding')
            x['section'] = sm.get(s['section'], s['section'])
        if s['aux_count']:
            require(s['storage'] == 3 and s['type'] == 0 and s['value'] == 0 and s['aux_count'] == 1
                    and s['section'] in sm and s['name'] == secs[s['section']]['name'], 'unsupported retained auxiliary')
            a = list(struct.unpack('<IHHIhBBH', s['aux']))
            if a[5] == 5:
                require(a[4] in sm, 'association escapes selection'); a[4] = sm[a[4]]
            x['aux'] = struct.pack('<IHHIhBBH', *a)
        expected[ym[i]] = x
        records += struct.pack('<8sIhHBB', encoded(x['name']), x['value'], x['section'], x['type'], x['storage'], x['aux_count']) + x['aux']
    pos = 20+40*len(ks); body = bytearray(); headers = bytearray()
    for i in ks:
        s = secs[i]; payload = s['payload']; require(len(payload) == s['size'], 'unbacked selected section')
        ptr = pos if payload else 0; body += payload; pos += len(payload); rp = pos if s['relocs'] else 0
        for off, target, kind in s['relocs']:
            require(target in ym and kind in (6,20), 'unsupported/escaping relocation')
            body += struct.pack('<IIH', off, ym[target], kind); pos += 10
        headers += struct.pack('<8sIIIIIIHHI', sn[i],0,0,len(payload),ptr,rp,0,len(s['relocs']),0,s['flags'])
    struct.pack_into('<I', strings, 0, len(strings))
    out = struct.pack('<HHIIIHH',0x14c,len(ks),0,pos,cursor,0,0)+headers+body+records+strings
    parsed = coff.parse(out)
    require(parsed['symbols'] == expected, 'LABEL symbol/aux preservation failure')
    for old, new in sm.items():
        x, y = secs[old], parsed['sections'][new]
        require(all(x[k] == y[k] for k in ('name','size','flags','payload')) and
                [(o,ym[t],k) for o,t,k in x['relocs']] == y['relocs'], 'LABEL section/field preservation failure')
    maps = dict(section_map=sm, symbol_map=ym, auxiliary_map=am, undefined_conversions=sorted(undef))
    verify_label_selection(raw, out, maps, label_certificate)
    receipt = dict(policy_id=POLICY, source_object_sha256=sha(raw), output_sha256=sha(out),
                   label_certificate_sha256=sha(label_certificate.decision_json.encode()), labels=json.loads(label_certificate.decision_json),
                   symbol_auxiliary_bijection_verified=True, payload_relocation_geometry_preserved=True,
                   provider_selected=False, runtime_eligible=False, emission_approved=False)
    return out, maps, receipt


def verify_label_selection(before, after, maps, label_certificate):
    """Independent map-driven reparse; accepts no implicit LABEL conversion."""
    require(type(label_certificate) is LabelCertificate, 'typed LABEL certificate required')
    e = json.loads(label_certificate.evidence_json)
    require(prove_labels(before, e) == label_certificate, 'stale LABEL verifier certificate')
    a, b = coff.parse(before), coff.parse(after)
    require(set(maps) == {'section_map','symbol_map','auxiliary_map','undefined_conversions'}, 'unknown selection map')
    sm, ym, am = [maps[k] for k in ('section_map','symbol_map','auxiliary_map')]
    require(all(type(k) is int and type(v) is int for m in (sm,ym,am) for k,v in m.items()), 'noninteger map')
    require(set(sm) == set(e['keep_sections']) and set(ym) == set(e['keep_symbols']), 'map scope differs')
    require(all(len(set(m.values())) == len(m) for m in (sm,ym,am)), 'noninjective map')
    require(set(sm.values()) == set(b['sections']) and set(ym.values()) == set(b['symbols']), 'incomplete map')
    expected_aux = {old+j:new+j for old,new in ym.items() for j in range(1,a['symbols'][old]['aux_count']+1)}
    require(am == expected_aux and not (set(am.values()) & set(ym.values()))
            and set(am.values()) | set(ym.values()) == set(range(b['symbol_count'])), 'auxiliary map differs')
    conv = maps['undefined_conversions']; undef = set(conv)
    require(all(type(i) is int for i in conv) and len(conv) == len(undef) and undef <= set(ym), 'invalid conversion set')
    for old,new in sm.items():
        x,y = a['sections'][old],b['sections'][new]
        require(all(x[k] == y[k] for k in ('name','size','flags','payload')) and
                [(off,ym[target],kind) for off,target,kind in x['relocs']] == y['relocs'], 'verified LABEL section/field differs')
    for old,new in ym.items():
        s=a['symbols'][old];x=dict(s)
        require(s['storage'] in (2,3,6), 'unsupported verified retained storage')
        if old in undef:
            require(s['storage'] in (2,3) and not s['name'].startswith('$LN') and not s['aux_count']
                    and s['section'] > 0 and s['section'] not in sm, 'verified LABEL/unsupported conversion')
            x.update(section=0,value=0,storage=2)
        else:
            require(s['section'] <= 0 or s['section'] in sm, 'verified definition outside selection')
            metadata=s['storage']==3 and s['type']==0 and not s['aux_count'] and (s['name']=='@comp.id' or (s['name']=='@feat.00' and s['value']==1))
            require(not (s['section']==0 and s['value']) and (s['section']!=-1 or metadata), 'verified common/absolute runtime binding')
            x['section']=sm.get(s['section'],s['section'])
        if s['aux_count']:
            aux=bytearray(s['aux']);selection=aux[14]
            if selection == 5:
                assoc=struct.unpack_from('<h',aux,12)[0];require(assoc in sm,'verified association escapes')
                struct.pack_into('<h',aux,12,sm[assoc])
            x['aux']=bytes(aux)
        require(x == b['symbols'][new], 'verified LABEL symbol/aux differs')
    return True
