"""Authenticate the fixed CODE68 normative field ledger; no native operations."""
import application_link_diagnostic as diagnostic

def require(ok,message):
    if not ok:raise ValueError(message)
def digest(value):return diagnostic.digest(diagnostic.canonical(value))

def verify_proof_ledger(wrappers,member_ledger,handoff):
    require(len(wrappers)==len(member_ledger)==len(handoff['records'])==68,'exact68member proof scope required')
    members={row['name']:row['projection'] for row in member_ledger}
    require(len(members)==68 and len({row['member'] for row in handoff['records']})==68,'duplicate member proof owner')
    ordinals=[row['field_proof_ordinal'] for row in handoff['records']]
    require(all(type(n) is int for n in ordinals) and sorted(ordinals)==list(range(1,69)),'complete unique original proof ordinals required')
    result={};locations=set();total=0
    for record in handoff['records']:
        require(record['member'] in members,'missing projected member proof')
        p=members[record['member']];w=wrappers[record['field_proof_ordinal']-1]
        require(type(w.get('schema_version')) is int and w['schema_version']==1 and w.get('source_evidence_enriched') is False and
            digest(w)==record['field_proof_record_sha256'],'original wrapper identity differs')
        require(w['member']==record['member'] and w['requested_root']==record['root'] and p['requested_roots']==[record['root']] and
            w['output_object_sha256']==p['output_sha256']==record['member_sha256'],'member/root/output proof differs')
        require(w['authority']==p['authority']==record['authority'] and
            all(w[key]==p[key]==record[key] for key in ('certificate_sha256','contract_identity_sha256')) and
            w['central_record_sha256']==p['central_record_sha256'],'authority/certificate/contract ancestry differs')
        fields=w['fields'];require(digest(fields)==w['fields_sha256']==record['original_fields_sha256'] and
            len(fields)==record['fields']==len(p['fields']),'original field collection identity differs')
        root=record['root']
        for full,compact in zip(fields,p['fields']):
            sha=digest(full);coff=full['coff_relocation']
            require(sha==compact['field_proof_sha256'] and full['function_va']==root['original_address'] and
                full['physical_section']==compact['section'] and full['physical_offset']==compact['offset'] and
                coff['offset']==compact['offset'] and coff['kind']==compact['kind'] and coff['symbol_index']==compact['symbol_index'],
                'original fullproof/compact physical field differs')
            location=(record['member'],compact['section'],compact['offset'])
            require(location not in locations and sha not in result,'duplicate original physical field/fullproof')
            locations.add(location);result[sha]=full;total+=1
    require(total==len(result)==629,'complete629fullproof census required')
    return result
