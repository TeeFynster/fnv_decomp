"""Pure physical field adapters for reviewed frontier CODE components.

No native tools, object rewriting, provider adoption or application execution.
Callers bind exact producer receipts and native conformance separately.
"""
import struct

import application_link_cohort as cohort
import coff_code_archive as coff

require = cohort.require
digest = cohort.digest

def require_field_ancestry(witnesses, originals):
    require(len(originals) == len(witnesses) and all(
        all(key in witness and witness[key] == value for key, value in original.items())
        for witness, original in zip(witnesses, originals)), 'EH handoff original field witnesses differ')

def EH_external_identity(witness, records, target_name, target_index):
    identity = witness['external_identity']
    keys = {'base','contract_kind','proof_consistency','role','semantic_domain','symbol','symbol_index'}
    require(set(identity) == keys, 'EH source identity schema differs')
    hits = [row for row in records if row.get('symbol_index') == witness['target_index']]
    require(len(hits) == 1, 'EH external identity missing/ambiguous')
    record = hits[0]
    require(set(record) == keys | {'output_symbol','output_symbol_index'} and
        {key: record[key] for key in keys} == identity and
        record['output_symbol'] == target_name and record['output_symbol_index'] == target_index and
        identity['symbol_index'] == witness['target_index'] and identity['base'] == witness['original_base'],
        'EH external source/serialized identity differs')
    return identity

def mapped_fields(data, *, component, member, root, maps, fields, owned_sections, owned_ranges, exports):
    """Every retained relocation must have one exact source-field witness."""
    obj = coff.parse(data)
    sm, ym = maps['section_map'], maps['symbol_map']
    reverse = {new: int(old) for old, new in ym.items()}
    require(len(reverse) == len(ym) == len(obj['symbols']) and set(reverse) == set(obj['symbols']), 'primary map not bijective')
    require(len(set(sm.values())) == len(sm) and set(sm.values()) == set(obj['sections']), 'section map not bijective')
    actual_aux = {index + offset for index, symbol in obj['symbols'].items() for offset in range(1, symbol['aux_count'] + 1)}
    require(len(set(maps['auxiliary_map'].values())) == len(maps['auxiliary_map']) and
        set(maps['auxiliary_map'].values()) == actual_aux, 'auxiliary map not bijective')
    require(coff.exports(data) == exports and len(exports) == 1, 'one exact reviewed parent export required')
    index = ym[str(root['symbol_index'])]; definition = obj['symbols'][index]
    require(definition['name'] == exports[0] and definition['section'] == sm[str(root['section'])] and
        definition['value'] == root['value'] and definition['storage'] == 2 and definition['type'] == 32 and
        definition['value'] + root['size'] <= obj['sections'][definition['section']]['size'], 'parent physical definition differs')
    require(set(owned_sections).issubset(set(sm)) and str(root['section']) in owned_sections, 'explicit certified owned sections required')
    actual = cohort.actual_fields(obj)
    output = []
    for witness in fields:
        oldsection = str(witness['physical_section']); offset = witness['field_offset']
        require(oldsection in owned_sections, 'field outside certified parent sections')
        require(any(str(section) == oldsection and start <= offset and offset + 4 <= end
            for section, start, end in owned_ranges), 'whole field outside certified parent range')
        section = sm[oldsection]; targetindex = ym[str(witness['symbol_index'])]; target = obj['symbols'][targetindex]
        require(actual.pop((section, offset), None) == (targetindex, witness['kind']), 'missing/duplicate/changed physical field')
        require(witness['kind'] in (6, 20) and offset + 4 <= obj['sections'][section]['size'] and
            struct.unpack_from('<I', obj['sections'][section]['payload'], offset)[0] == witness['addend_bits'], 'physical relocation operand differs')
        require(target['name'] == witness['canonical_name'], 'physical target spelling differs')
        require(target['section'] >= 0, 'absolute/debug target unsupported')
        if target['section'] > 0:
            require(str(next(old for old, new in sm.items() if new == target['section'])) in owned_sections, 'retained target outside certified parent sections')
        proof = dict(witness)
        if target['section'] > 0: proof['role'] = 'retained'
        output.append(dict(component=component, member=member, member_sha256=digest(data),
            recipe_id=root['recipe_id'], object_sha256=root['object_sha256'], root=root['original_address'],
            caller=exports[0], section=section, offset=offset, symbol_index=targetindex,
            physical_symbol_index=reverse[targetindex], kind=witness['kind'], canonical=target['name'],
            undefined=target['section'] == 0, proof=proof))
    require(not actual, 'unvisited physical relocations')
    provider = dict(component=component, member=member, canonical=exports[0], original_address=root['original_address'],
        recipe_id=root['recipe_id'], object_sha256=root['object_sha256'], symbol_index=root['symbol_index'],
        serialized_symbol_index=index, serialized_section=definition['section'], value=root['value'], size=root['size'])
    return [provider], output

def ordinary_member(data, row, *, component):
    projection = row['projection']
    require(digest(data) == projection['output_sha256'] and len(projection['requested_roots']) == 1, 'reviewed ordinary member differs')
    require(all(projection[k] is False for k in ('compiler_performed', 'native_tools_run', 'executable_link_performed',
        'game_execution_performed', 'provider_selected', 'runtime_eligible', 'link_ready', 'ABI_verified')), 'producer metadata promoted unexpectedly')
    root = projection['requested_roots'][0]; obj = coff.parse(data); ym = projection['maps']['symbol_map']
    require(root['object_sha256'] == projection['original_object_sha256'], 'ordinary original root/object identity differs')
    bindings = dict(projection['namespace_bindings'])
    require(len(bindings) == len(projection['namespace_bindings']) and all(
        obj['symbols'][ym[str(old)]]['name'] == name for old, name in bindings.items()), 'ordinary physical namespace differs')
    if 'projected_namespace_bindings' in projection:
        require(projection['projected_namespace_bindings'] == [[ym[str(old)], name] for old, name in projection['namespace_bindings']], 'post-serialization namespace differs')
    fields = [dict(witness, physical_section=witness['section'], field_offset=witness['offset']) for witness in projection['fields']]
    return mapped_fields(data, component=component, member=row['name'], root=root, maps=projection['maps'],
        fields=fields, owned_sections={str(root['section'])},
        owned_ranges=[(root['section'], root['value'], root['value'] + root['size'])], exports=projection['exports'])

def EH_file(data, metadata, receipt, root):
    require(digest(data) == metadata['object_sha256'] == receipt['projection']['output_sha256'] and
        metadata['parent'] == root['original_address'] and metadata['source_object_sha256'] == root['object_sha256'], 'EH source/component identity differs')
    projection = receipt['projection']; obj = coff.parse(data)
    require(metadata['physical_maps'] == projection['maps'], 'EH serialized maps differ')
    for name in ('section_map', 'symbol_map', 'auxiliary_map'):
        require(all(int(old) == new for old, new in projection['repack_maps'][name].items()), 'EH second serialization not identity')
    require(not projection['repack_maps']['undefined_conversions'], 'EH second serialization converted definitions')
    semantic = projection['original_before']['semantic']
    require(all(semantic['parent'][key] == root[key] for key in ('original_address', 'section', 'size', 'symbol', 'symbol_index', 'value')) and
        projection['input_sha256'] == semantic['object_sha256'] == root['object_sha256'], 'EH original parent ancestry differs')
    require(set(map(str, projection['original_before']['retained_sections'])) == set(projection['maps']['section_map']), 'EH retained section ledger differs')
    require(all(obj['symbols'][projection['maps']['symbol_map'][str(old)]]['name'] == name for old, name in projection['namespace']), 'EH physical namespace differs')
    # Only source-certified ordinary/EH/state ranges may supply parent fields.
    comparisons = projection['after']['comparisons']
    owned = {str(row['section']) for row in comparisons}
    require(all(row['nonfield_differences'] == 0 and row['start'] < row['end'] for row in comparisons), 'EH owned payload comparison differs')
    safeseh = metadata['safeseh']; section = obj['sections'][safeseh['output_section']]
    require(section['name'] == '.sxdata' and not section['relocs'] and
        section['payload'] == struct.pack('<I', safeseh['output_handler_index']) and
        projection['maps']['symbol_map'][str(safeseh['retained_source_index'])] == safeseh['output_handler_index'], 'EH SafeSEH ordinal/registry differs')
    fields = []
    old_rows = projection['after']['fields']
    require_field_ancestry(metadata['fields'], old_rows)
    for witness in metadata['fields']:
        require(any(row['section'] == witness['section'] and row['start'] <= witness['offset'] and witness['offset'] + 4 <= row['end'] for row in comparisons), 'EH field lacks exact owned comparison range')
        target = obj['symbols'][witness['output_target_index']]
        require(projection['maps']['section_map'][str(witness['section'])] == witness['output_section'] and
            projection['maps']['symbol_map'][str(witness['target_index'])] == witness['output_target_index'], 'EH witness serialization differs')
        if target['section'] == 0:
            identity = EH_external_identity(witness, metadata['unresolved_external_identities'], target['name'], witness['output_target_index'])
            role = identity['role']
        else:
            require(witness['role'] == 'owned-parent-EH-local', 'EH local field lacks owned role')
            role = 'retained'
        fields.append(dict(physical_section=witness['section'], field_offset=witness['offset'], symbol_index=witness['target_index'],
            kind=witness['kind'], addend_bits=witness['addend'], canonical_name=target['name'], role=role,
            original_base=f"0x{witness['original_base']:08x}", original_target=f"0x{witness['original_target']:08x}",
            proof_family=witness['proof_family'], external_identity=witness.get('external_identity')))
    return mapped_fields(data, component='EHFile', member='component.obj', root=root, maps=projection['maps'],
        fields=fields, owned_sections=owned,
        owned_ranges=[(row['section'], row['start'], row['end']) for row in comparisons], exports=metadata['physical_exports'])
