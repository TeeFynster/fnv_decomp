"""ModelLoader adapter retaining all physical duplicate-undefined records.

CODE59 uses the unchanged ordinary-member adapter. This module adds no native
operation, object rewrite, namespace alias or provider/runtime approval.
"""
import application_link_frontier as previous
import coff_code_archive as coff

require = previous.require

def reference_groups(obj, metadata, fields):
    maps=metadata['physical_maps'];groups=metadata['reference_groups'];entries=metadata['reference_group_entry_proofs']
    require(metadata['no_symbol_coalescing'] is True and len(groups)==2 and len(entries)==6,'exact two uncoalesced reference groups required')
    require(len({group['name'] for group in groups})==2,'distinct reference group identities required')
    actual={(row['section'],row['offset']):row for row in fields}
    require(len(actual)==len(fields),'duplicate actual ModelLoader field location')
    seen=set();proofs=[]
    for group in groups:
        old=group['members'];new=group['output_members']
        require(len(old)==len(set(old))==len(new)==len(set(new))==3 and
            [maps['symbol_map'][str(index)] for index in old]==new,'three physical reference records must remain distinct')
        require(group['role']=='code' and group['semantic_domain']=='code' and group['contract_kind']=='function' and
            group['ABI_verified'] is False and group['provider_selected'] is False,'reference group promotion or role differs')
        for index in new:
            symbol=obj['symbols'][index]
            require(symbol['name']==group['name'] and symbol['section']==0 and symbol['storage']==2 and
                not symbol['aux_count'],'reference group physical record differs')
        require({index for index,symbol in obj['symbols'].items() if symbol['name']==group['name']}==set(new),
            'hidden or coalesced same-name physical records')
        declared=group['all_physical_uses']
        require(len(declared)==len(group['fields'])==3 and {row['target_index'] for row in declared}==set(old),
            'reference group complete use census differs')
        actual_group={(row['section'],row['offset'],row['physical_symbol_index'],row['kind']) for row in fields if
            row['physical_symbol_index'] in old or row['canonical']==group['name']}
        require(actual_group=={(maps['section_map'][str(row['section'])],row['offset'],row['target_index'],row['kind']) for row in declared},
            'unlisted actual reference-group use')
        for use in declared:
            require(use['retained'] is True and use['kind']==20,'reference group use not retained REL32')
            section=maps['section_map'][str(use['section'])];offset=use['offset']
            key=(section,offset);require(key not in seen,'reference group field counted twice');seen.add(key)
            row=actual.get(key)
            require(row is not None and row['physical_symbol_index']==use['target_index'] and
                row['symbol_index']==maps['symbol_map'][str(use['target_index'])] and row['undefined'] is True and
                row['kind']==20 and row['canonical']==group['name'] and row['proof']['addend_bits']==0 and
                int(row['proof']['original_base'],0)==int(row['proof']['original_target'],0)==group['original_base'],
                'reference group actual field differs')
            hits=[entry for entry in entries if entry['physical_section']==use['section'] and
                entry['physical_offset']==offset and entry['coff_relocation']['symbol_index']==use['target_index']]
            require(len(hits)==1,'reference group selected-entry proof missing/ambiguous')
            entry=hits[0]
            require(entry['classification']=='SELECTED_CODE_ENTRY' and entry['proof_consistency']=='EXACT_OWN_SOURCE_RESOLUTION' and
                int(entry['exact_original_target_va'],0)==group['original_base'] and
                entry['coff_relocation']['kind']==20 and entry['coff_relocation']['addend']==0 and
                entry['function_va']==metadata['parent'] and entry['recipe_id']==metadata['original_root']['recipe_id'] and
                entry['code_ownership_ambiguous'] is False and entry['physical_field_overlap_count']==1 and
                int(entry['selected_address'],0)==group['original_base'] and entry['coff_relocation']['width']==4 and
                entry['provider_selected'] is False and entry['abi_verified'] is False and
                entry['runtime_eligible'] is False and entry['game_fixup_approved'] is False,'reference group source-entry identity differs')
            row['proof']['reference_group_entry_proof']=entry
            row['proof']['reference_group_original_members']=list(old)
            proofs.append(entry)
    require(len(seen)==len(proofs)==6,'all six reference-group fields required')
    return proofs

def model_loader(data,metadata,receipt):
    root=metadata['original_root']
    require(root['original_address']=='0x00448420' and len(metadata['fields'])==52 and
        metadata['all_parent_EH_fields_preserved'] is True,'fixed ModelLoader parent/field scope required')
    providers,fields=previous.EH_file(data,metadata,receipt,root)
    require(len(providers)==1 and len(fields)==52,'complete ModelLoader physical census differs')
    for row in providers+fields:row['component']='ModelLoader-EH'
    reference_groups(coff.parse(data),metadata,fields)
    return providers,fields
