"""Exact expanded diagnostic input ledger; source-only integration helpers.

No compiler/linker invocation or object rewrite. Existing diagnostic helpers
remain frozen. Component readiness and namespace resolution are separate facts.
"""
from __future__ import annotations
from collections import defaultdict
import copy
import gzip
import json
from pathlib import Path
import struct

import application_link_diagnostic as baseline
import coff_code_archive as coff

require = baseline.require
digest = baseline.digest
canonical = baseline.canonical

COMPONENT_PINS = {
    'reference_archive': ('union-reference-production-native-v1/union-reference-v3-0000.lib', 'ce953c9c924873d67c89cbce669f2253089711c12121a87da2aeaa87311a007a'),
    'reference_receipt': ('union-reference-production-native-v1/receipt.json', '261e083ba69d4158180a662e7aa278c8be23c4bf6c6a30a991ce9898c3a60361'),
    'reference_members': ('union-reference-production-native-v1/members.jsonl', 'bdf895fe66d336f5bf900f00a43af938a3696cc60df22fc483c73563343863f2'),
    'reference_certificates': ('union-reference-production-native-v1/certificates.jsonl.gz', 'c97bc70d3f0cf0357e7cd61d593d10d7efc48948513a931e4c88ea3dc00c0924'),
    'generic_archive': ('ordinary-code-projection-first8-v1/ordinary-code.lib', '1f2beeea01a4aef884e474dfbb3ac9eb89bef3cf70de021e77fdd7ee65c3430b'),
    'generic_receipt': ('ordinary-code-projection-first8-v1/receipt.json', '39f6ac1fabdeb0f4ebed433bbaf3dc86ef82472bd0c24fcb3af18f1aa5da1d80'),
    'generic_members': ('ordinary-code-projection-first8-v1/members.json', '1b2335171290d48b0a2453e65d4dcfca45ab46d8e5091d075bcc35897ba524fb'),
    'overlay_archive': ('overlay-code-project-v1/overlay-code.lib', '5484b792e696d91eb1cbf27f3d2985c7e63936ab6d784d6fb157bf8059ee9984'),
    'overlay_receipt': ('overlay-code-project-v1/receipt.json', '08eec3a2bdf7f79672a89bf7cf629e54776db29310b18383369d495372497484'),
    'EH_object': ('eh-iotask69-projection-v1/component.obj', 'ae6731831bed4907a85b26e30bdf82a2ba764f04d04add9e0e850ac28dc68c44'),
    'EH_receipt': ('eh-iotask69-projection-v1/projection.json', 'bd106bb8f7249d49047bad422df75dbe490b9aecc467cc222353821eb5ce244f'),
    'EH_metadata': ('eh-iotask69-integration-metadata-v1.json', 'a5f5ed834610ac43deeca3c0445169f562497c6ed15dd6a4ea594ddfa9b03971'),
    'DATA_receipt': ('data-arena-readonly-section-name-v1/projection.json', '137480a83a6869c0548d6d93b984a08515504f99aef44d72b0c7d000e936a0bd'),
    'DATA_0': ('data-arena-readonly-section-name-v1/cb8d58d939251b22cc7429f62751a51e83d1c6f11abeef2489d3b96a973b7c1a.obj', '4950eca30539f721ac44d63c32a46d36885da3214e0fe5b68be3f3d5cdfb1ed1'),
    'DATA_1': ('data-arena-readonly-section-name-v1/a80a7435d3665b08022dc0a36be353e4ffafa56da5fd9b4337224164f96aedeb.obj', 'a07b026b50e1f2969b24ab32b5268631512a8628907816bed4e160847e7df0de'),
}


def mapped_member(data, *, component, member, recipe_id, object_sha256,
                  roots, maps, namespace, obligations, retained_bases,
                  expected_exports):
    """Read a projected member without changing historical eligibility flags."""
    obj = coff.parse(data)
    require(coff.exports(data) == sorted(expected_exports), 'component export ledger differs')
    sm, ym = maps['section_map'], maps['symbol_map']
    reverse = {new: int(old) for old, new in ym.items()}
    require(len(reverse) == len(ym) == len(obj['symbols']), 'component primary map not bijective')
    names = {row['serialized_index']: row for row in namespace}
    require(len(names) == len(namespace) and set(names) == set(obj['symbols']) and
        all(names[index]['name'] == row['name'] and names[index]['physical_index'] == reverse[index]
            for index, row in obj['symbols'].items()), 'component physical namespace differs')
    providers = []
    for root in roots:
        index = ym[str(root['symbol_index'])]
        symbol = obj['symbols'][index]
        require(symbol['name'] in expected_exports and symbol['section'] == sm[str(root['section'])] and
            symbol['value'] == root['value'] and symbol['storage'] == 2 and symbol['type'] == 32 and
            symbol['value'] + root['size'] <= obj['sections'][symbol['section']]['size'], 'component root definition differs')
        providers.append(dict(component=component, member=member, canonical=symbol['name'],
            original_address=root['original_address'], recipe_id=recipe_id,
            object_sha256=object_sha256, symbol_index=root['symbol_index'],
            serialized_symbol_index=index, serialized_section=symbol['section'],
            value=root['value'], size=root['size']))
    require(len(providers) == len(expected_exports), 'hidden component provider export')
    uses = {}
    for obligation in obligations:
        key = (sm[str(obligation['physical_section'])], obligation['field_offset'])
        require(key not in uses, 'duplicate component physical field proof')
        uses[key] = obligation
    fields = []
    for section, sec in obj['sections'].items():
        for offset, index, kind in sec['relocs']:
            target = obj['symbols'][index]
            owner = [root for root in providers if root['serialized_section'] == section and
                     root['value'] <= offset < root['value'] + root['size']]
            require(len(owner) == 1, 'component field lacks exact source root/companion owner')
            row = dict(component=component, member=member, member_sha256=digest(data),
                recipe_id=recipe_id, object_sha256=object_sha256,
                root=owner[0]['original_address'], caller=owner[0]['canonical'],
                section=section, offset=offset, symbol_index=index,
                physical_symbol_index=reverse[index], kind=kind,
                canonical=target['name'], undefined=target['section'] == 0)
            proof = uses.pop((section, offset), None)
            if target['section'] == 0:
                require(proof is not None and ym[str(proof['symbol_index'])] == index and
                    proof['kind'] == kind and proof['canonical_name'] == target['name'],
                    'component undefined field/physical proof differs')
                require(kind in (6, 20) and struct.unpack_from('<I', sec['payload'], offset)[0] == proof['addend_bits'],
                    'component relocation operand differs')
                row['proof'] = proof
            else:
                require(proof is None and target['name'] in retained_bases, 'component retained field lacks source identity')
                row['proof'] = dict(role='retained', original_base=retained_bases[target['name']])
            fields.append(row)
    require(not uses, 'unvisited component field proof')
    return providers, fields


def disjoint_providers(component_providers, baseline_providers=(), existing_noncode_definitions=()):
    """Neither equal bytes nor an archive's lazy nature excuses duplicate owners."""
    existing_definitions = list(existing_noncode_definitions)
    require(len(existing_definitions) == len(set(existing_definitions)), 'duplicate existing selected export')
    require(not any(name.startswith('_fnv_code_') for name in existing_definitions),
        'baseline CODE requires full provider records')
    symbols = {name: 'existing-noncode' for name in existing_definitions}
    physical, addresses = {}, {}
    for providers in [list(baseline_providers)] + list(component_providers):
        for root in providers:
            require(isinstance(root, dict), 'full baseline/component provider records required')
            name = root['canonical']
            identity = (root['recipe_id'], root.get('logical_object_sha256', root['object_sha256']),
                        root.get('logical_symbol_index', root['symbol_index']))
            require(name not in symbols, 'duplicate selected export: ' + name)
            require(identity not in physical, 'duplicate selected logical physical owner')
            require(root['original_address'] not in addresses, 'competing selected original function address')
            symbols[name] = root['component']; physical[identity] = name; addresses[root['original_address']] = name
    return dict(symbols=symbols, physical_owners=len(physical), original_addresses=len(addresses))


def actual_fields(obj):
    result = {}
    for section, sec in obj['sections'].items():
        for offset, index, kind in sec['relocs']:
            require((section, offset) not in result, 'duplicate physical component relocation field')
            result[(section, offset)] = (index, kind)
    return result


def data_section_successor(old, new, receipt_row):
    require(digest(old) == receipt_row['input_sha256'] and digest(new) == receipt_row['output_sha256'], 'DATA successor hash differs')
    offset = receipt_row['section_name_offset']
    require(offset == 20 and len(old) == len(new) and old[offset:offset + 8] == b'.data\0\0\0' and
        new[offset:offset + 8] == b'.rdata\0\0' and old[:offset] == new[:offset] and old[offset + 8:] == new[offset + 8:],
        'DATA change exceeds exact section-name field')
    before, after = coff.parse(old), coff.parse(new)
    require(before['symbols'] == after['symbols'] and len(before['sections']) == len(after['sections']) == 1,
        'DATA successor symbols/geometry differ')
    before['sections'][1]['name'] = '.rdata'
    require(before['sections'] == after['sections'] and not after['sections'][1]['relocs'], 'DATA successor payload/fixups differ')


def reference_component(data, certificate_row, original_union):
    certificate = certificate_row['certificate']
    plan = original_union['plan'] if 'plan' in original_union else original_union['receipt']['plan']
    require(digest(canonical(plan)) == certificate['original_union_plan_sha256'] and
        digest(canonical(original_union)) == certificate['provenance']['original_union_row']['sha256'],
        'reference certificate original field ledger differs')
    projection = certificate_row['projection']
    require(digest(data) == projection['output_sha256'] and projection['coalescing_performed'] is False and
        projection['relocation_retargeting_performed'] is False, 'reference component/physical preservation differs')
    providers, fields = mapped_member(data, component='reference-1372', member=certificate['recipe_id'] + '.obj',
        recipe_id=certificate['recipe_id'], object_sha256=certificate['object_sha256'],
        roots=certificate['roots'], maps=projection['maps'], namespace=certificate['namespace_plan'],
        obligations=plan['obligations'], retained_bases=plan['comparison_base_view'],
        expected_exports=projection['exports'])
    require(len(fields) == plan['counts']['fields'], 'reference full field count differs')
    return providers, fields


def generic_component(data, member_row):
    projection = member_row['projection']
    require(digest(data) == projection['output_sha256'] and projection['relocation_count'] == 0,
        'generic zero-field member differs')
    obj = coff.parse(data)
    require(not any(sec['relocs'] for sec in obj['sections'].values()) and
        not any(s['storage'] == 2 and s['section'] == 0 for s in obj['symbols'].values()) and
        coff.exports(data) == projection['exports'], 'generic hidden fields/exports')
    roots = projection['requested_roots']; maps = projection['maps']
    providers = []
    for root in roots:
        index = maps['symbol_map'][str(root['symbol_index'])]
        symbol = obj['symbols'][index]
        require(symbol['name'] in projection['exports'] and symbol['section'] == maps['section_map'][str(root['section'])] and
            symbol['storage'] == 2 and symbol['type'] == 32 and symbol['value'] == root['value'] and
            symbol['value'] + root['size'] <= obj['sections'][symbol['section']]['size'],
            'generic root physical identity differs')
        providers.append(dict(component='generic-first8', member=member_row['name'], canonical=symbol['name'],
            original_address=root['original_address'], recipe_id=root['recipe_id'],
            object_sha256=root['object_sha256'], symbol_index=root['symbol_index']))
    require(len(providers) == len(projection['exports']), 'generic hidden provider')
    return providers, []


def overlay_component(data, recipe_plan, projection, member):
    chosen = recipe_plan['chosen']; contract = chosen['contract']; maps = projection['receipt']['maps']
    require(chosen['candidate'] is True and contract['verified_match'] is True, 'overlay selection differs')
    namespace = chosen['namespace']; obj = coff.parse(data)
    bindings = dict(namespace['bindings'])
    records = [dict(physical_index=int(old), serialized_index=new,
        name=bindings.get(int(old), obj['symbols'][new]['name'])) for old, new in maps['symbol_map'].items()]
    obligations = [dict(symbol_index=o['symbol_index'], physical_section=o['field'][0],
        field_offset=o['field'][1], kind=o['field'][3], canonical_name=o['logical_name'],
        original_base=o['original_base'], original_target=o['original_target'],
        role=o['role'], addend_bits=o['addend_bits']) for o in namespace['obligations']]
    providers, fields = mapped_member(data, component='overlay2', member=member,
        recipe_id=recipe_plan['recipe_id'], object_sha256=contract['fields'][0]['actual_object_sha256'],
        roots=contract['roots'], maps=maps, namespace=records, obligations=obligations,
        retained_bases={}, expected_exports=projection['receipt']['exports'])
    require(len(providers) == len(projection['receipt']['old_logical_identities']), 'overlay logical ancestry count differs')
    for root, logical in zip(providers, projection['receipt']['old_logical_identities']):
        require(logical['recipe_id'] == root['recipe_id'], 'overlay logical source ancestry differs')
        root['logical_object_sha256'] = logical['object_sha256']; root['logical_symbol_index'] = logical['symbol_index']
    return providers, fields


def EH_component(data, metadata):
    obj = coff.parse(data); parent = metadata['parent']; exports = metadata['physical_defined_exports']
    require(digest(data) == metadata['component']['sha256'] and coff.exports(data) == exports,
        'EH physical component differs')
    safeseh = metadata['safeseh']; registry = obj['sections'][safeseh['output_section']]
    require(registry['name'] == '.sxdata' and registry['payload'] == struct.pack('<I', safeseh['new_index']) and
        not registry['relocs'] and obj['symbols'][safeseh['new_index']]['section'] > 0,
        'EH SafeSEH physical registry differs')
    unresolved = {r['canonical_unresolved']: r for r in metadata['unresolved']}
    fields = []
    actual = actual_fields(obj)
    for witness in metadata['fields']:
        section, offset, index, kind = witness['output_section'], witness['offset'], witness['output_target_index'], witness['kind']
        require(actual.pop((section, offset), None) == (index, kind), 'EH field physical mapping differs')
        symbol = obj['symbols'][index]
        if symbol['section'] == 0:
            obligation = unresolved[symbol['name']]
            require(obligation['base'] == witness['original_base'], 'EH unresolved original identity differs')
            proof = dict(role=obligation['role'], original_base=f"0x{witness['original_base']:08x}",
                original_target=f"0x{witness['original_target']:08x}", addend_bits=witness['addend'],
                contract_kind=obligation['contract_kind'], proof_consistency=obligation['proof_consistency'])
        else:
            proof = dict(role='retained', original_base=f"0x{witness['original_base']:08x}")
        require(kind in (6, 20) and struct.unpack_from('<I', obj['sections'][section]['payload'], offset)[0] == witness['addend'],
            'EH field addend differs')
        fields.append(dict(component='IOTask-EH', member='component.obj', member_sha256=digest(data),
            recipe_id=parent['recipe_id'], object_sha256=parent['native_object_sha256'], root=parent['original_address'],
            caller=exports[0], section=section, offset=offset, kind=kind, symbol_index=index,
            physical_symbol_index=witness['target_index'], canonical=symbol['name'],
            undefined=symbol['section'] == 0, proof=proof))
    require(not actual and len(fields) == 11 and len(exports) == 1, 'EH complete field census differs')
    providers = [dict(component='IOTask-EH', member='component.obj', canonical=exports[0],
        original_address=parent['original_address'], recipe_id=parent['recipe_id'],
        object_sha256=parent['native_object_sha256'], symbol_index=parent['original_primary_index'],
        prospective_logical_demand=metadata['logical_code_demand'], logical_binding_applied=False)]
    return providers, fields
