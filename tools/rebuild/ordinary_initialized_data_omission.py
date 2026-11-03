"""Typed, negative-first omission witnesses for unused initialized COFF data.

This module does not rewrite objects or replace frozen ordinary certificates.
Its caller authenticates the original collector envelope and source/oracle proof.
V1 accepts readonly initialized sections isolated from the projected root graph.
"""
from __future__ import annotations
from collections import defaultdict, deque
import hashlib
import json
from pathlib import Path
import re
import struct

import coff_code_archive as coff
import root_code_closure as ordinary

POLICY = 'unused-ordinary-initialized-data-omission-v1'
PARSER_PIN = '76244d2d4dca4c1f8aa72224be1ef5c92f68976b5cda7d31b5cfe23d3cc29e64'
ORDINARY_PIN = '4bfdb5001380a3d7e5db7517033285d49ab211be68e2fcba15964f0ad5b03c53'
# Exact observed forms, not a mask that silently approves new characteristics.
FORMS = {('.rdata', 0x40300040): ('readonly-initialized', 4, False),
         ('.rdata', 0x40101040): ('readonly-initialized', 1, True)}
FALSE = dict(provider_selected=False, runtime_eligible=False, ABI_verified=False,
             link_ready=False, emission_performed=False, namespace_approved=False,
             full_serialization_eligible=False, original_data_ownership_proved=False)
require = coff.require


def special_symbol(name):
    return bool(name.startswith('@') or re.match(
        r'(?i)(?:_+(?:eh|unwind|catch|tls|Cxx|security|SEH|RTC|load_config|xi_|xc_|xp_|xt_)|\?\?_[78R])', name)
        or re.search(r'(?i)(?:^|\$)(?:tls|CRT|SAFESEH)', name))


def section_symbol(symbol, sections):
    return (symbol['storage'] == 3 and symbol['section'] > 0 and
            symbol['name'] == sections[symbol['section']]['name'] and
            symbol['type'] == 0 and symbol['value'] == 0)


def protected_graph(obj, certificate):
    """Complete directed physical graph, with explicit conservative roots.

    Reverse ordinary relocations are not edges: omitted callers of a retained
    entry do not become runtime roots. Association parent/child relationships
    are both followed because retaining either requires a scope decision.
    """
    sections, symbols = obj['sections'], obj['symbols']
    graph = defaultdict(set); seeds = set(); names = defaultdict(list)
    weak = []; associations = []; incoming = defaultdict(list)
    for i, symbol in symbols.items():
        node = ('symbol', i)
        if symbol['section'] > 0:
            graph[node].add(('section', symbol['section']))
            graph[('section', symbol['section'])].add(node)
        if not section_symbol(symbol, sections) and symbol['storage'] != 103:
            if symbol['storage'] in (2, 105) or symbol['type'] == 32:
                names[symbol['name']].append(i)
        if special_symbol(symbol['name']): seeds.add(node)
        if symbol['storage'] == 105 and symbol['aux_count'] == 1:
            fallback = struct.unpack_from('<I', symbol['aux'])[0]
            graph[node].add(('symbol', fallback)); weak.append((i, fallback))
            seeds.update((node, ('symbol', fallback)))
        if symbol['aux_count'] == 1 and section_symbol(symbol, sections):
            auxiliary = struct.unpack('<IHHIhBBH', symbol['aux'])
            if auxiliary[5] == 5:
                child, parent = symbol['section'], auxiliary[4]
                graph[('section', child)].add(('section', parent))
                graph[('section', parent)].add(('section', child))
                associations.append((child, parent, i))
    for group in names.values():
        for i in group:
            graph[('symbol', i)].update(('symbol', j) for j in group)
    ordinary_names = {'.text', '.text$yd', '.rdata', '.rdata$r', '.data', '.bss', '.debug$S', '.debug$F', '.drectve'}
    for i, section in sections.items():
        node = ('section', i)
        if section['name'] not in ordinary_names: seeds.add(node)
        for off, target, kind in section['relocs']:
            graph[node].add(('symbol', target))
            incoming[target].append(dict(section=i, offset=off, symbol_index=target, kind=kind))
        if section['name'] == '.sxdata' and len(section['payload']) % 4 == 0:
            seeds.update(('symbol', struct.unpack_from('<I', section['payload'], off)[0])
                         for off in range(0, len(section['payload']), 4))
    seeds.update(('section', i) for i in certificate['retained_section_indices'])
    seeds.update(('symbol', i) for i in certificate['retained_primary_indices'])
    seeds.update(('symbol', r['symbol_index']) for r in certificate['omitted_definition_conversions'])
    for edge in certificate['edges']:
        if edge['kind'] == 'DIRECTIVE_NAME_RESOLUTION':
            seeds.update(('symbol', i) for i in edge['target']['symbol_indices'])
        if edge['kind'] in ('LIVE_NAME_RESOLUTION', 'LIVE_WEAK_FALLBACK'):
            if type(edge['source']) is int: seeds.add(('symbol', edge['source']))
            if type(edge['target']) is int: seeds.add(('symbol', edge['target']))
    live = set(seeds); queue = deque(seeds)
    while queue:
        for target in graph[queue.popleft()]:
            if target not in live: live.add(target); queue.append(target)
    serialized = [dict(source=list(node), targets=[list(n) for n in sorted(targets)])
                  for node, targets in sorted(graph.items())]
    return dict(live=live, seeds=seeds, incoming=incoming, names=names, weak=weak,
                associations=associations, graph_sha256=digest(serialized),
                graph_nodes=len(graph), graph_edges=sum(map(len, graph.values())))


def digest(value):
    return hashlib.sha256(json.dumps(value, sort_keys=True, separators=(',', ':'),
                                    ensure_ascii=True).encode()).hexdigest()


def _producer_gate():
    for module, pin in ((coff, PARSER_PIN), (ordinary, ORDINARY_PIN)):
        require(hashlib.sha256(Path(module.__file__).read_bytes()).hexdigest() == pin,
                'frozen parser/ordinary producer differs')


def observe_omitted_initialized_data(raw, contract, certificate, requested_sections):
    """Return an exact blocker-discharge witness, with every failure preserved.

    The original certificate is replayed unchanged, including all blockers. This
    is not a new positive root certificate. An independent, reviewed adapter must
    later bind and consume the witness; this function emits no COFF or files.
    Incoming fields are permitted only from ordinary CODE sections outside the
    complete protected directed closure. Such omitted-to-omitted physical edges
    prove local isolation, not an original source DATA type/base/provider binding.
    """
    _producer_gate()
    require(isinstance(raw, bytes) and 0 < len(raw) <= 16*1024**2, 'object bound')
    require(isinstance(contract, dict) and isinstance(certificate, dict), 'contract/certificate required')
    require(isinstance(requested_sections, list) and requested_sections and
            all(type(i) is int for i in requested_sections) and
            requested_sections == sorted(set(requested_sections)), 'exact nonempty section set')
    require(contract.get('provenance', {}).get('object_sha256') == coff.digest(raw),
            'object identity differs')
    provenance = contract['provenance']
    require(isinstance(provenance.get('source_sha256'), str) and
            re.fullmatch('[0-9a-f]{64}', provenance['source_sha256']) and
            provenance.get('recipe_id') == contract.get('recipe_id') and
            type(provenance.get('recipe_index')) is int, 'source/recipe lineage required')
    obj = coff.parse(raw)
    replay = ordinary.assess_object(obj, contract)
    require(replay == certificate and replay['contract_identity_sha256'] == digest(contract),
            'stale/forged original certificate')
    require(set(requested_sections) <= obj['sections'].keys(), 'absent candidate section')
    secs, syms = obj['sections'], obj['symbols']
    retained = set(replay['retained_section_indices'])
    required = set(replay['retained_primary_indices'])
    converted = {r['symbol_index'] for r in replay['omitted_definition_conversions']}
    graph = protected_graph(obj, replay)
    structural_codes = {'INVALID_PHYSICAL_RELOCATION', 'UNSUPPORTED_SYMBOL_SEMANTICS',
        'SYMBOL_VALUE_OUTSIDE_SECTION', 'UNSUPPORTED_WEAK_AUXILIARY', 'UNSUPPORTED_COMMON_RECORD',
        'UNKNOWN_SECTION_AUXILIARY', 'AUXILIARY_COMDAT_FLAG_CONFLICT', 'INVALID_ASSOCIATION_PARENT',
        'HIDDEN_SECTION_AUXILIARY_INDEX', 'UNKNOWN_HIDDEN_AUXILIARY_INDICES',
        'MISSING_OR_DUPLICATE_COMDAT_AUXILIARY', 'ASSOCIATION_CYCLE', 'WEAK_FALLBACK_CYCLE',
        'UNSUPPORTED_COMPILER_METADATA', 'INVALID_SAFESEH_INDEX', 'UNSUPPORTED_SAFESEH_TABLE',
        'NONASCII_DIRECTIVE', 'UNSUPPORTED_DIRECTIVE_SECTION', 'UNSUPPORTED_IMPLICIT_LINKER_DIRECTIVE'}
    structural = [b['blocker_id'] for b in replay['blockers'] if b['code'] in structural_codes]
    rows = []
    for sn in requested_sections:
        sec = secs[sn]
        indices = sorted(i for i, s in syms.items() if s['section'] == sn)
        blockers = []
        def block(code, evidence):
            blockers.append(dict(code=code, evidence=evidence))
        form = FORMS.get((sec['name'], sec['flags']))
        if form is None: block('UNREVIEWED_INITIALIZED_DATA_FORM', dict(name=sec['name'], flags=sec['flags']))
        if sn in retained: block('CANDIDATE_SECTION_RETAINED', sn)
        if sec['size'] != len(sec['payload']): block('INITIALIZED_DATA_EXTENT_DIFFERS', sn)
        if sec['relocs']: block('CANDIDATE_OUTGOING_FIELDS_UNSUPPORTED', sec['relocs'])
        if structural: block('PHYSICAL_GRAPH_OR_DIRECTIVE_CONTRACT_UNMODELED', structural)
        if ('section', sn) in graph['live']: block('CANDIDATE_PROTECTED_DIRECTED_CLOSURE', sn)
        affected = sorted(i for i in indices if i in required | converted or ('symbol', i) in graph['live'])
        if affected: block('CANDIDATE_LIVE_OR_SPECIAL_SYMBOL_DEPENDENCY', affected)
        related = [list(a) for a in graph['associations'] if sn in a[:2]]
        if related: block('CANDIDATE_ASSOCIATION_DEPENDENCY', related)
        uses = [use for i in indices for use in graph['incoming'][i]]
        for use in uses:
            source = secs[use['section']]
            if source['name'] != '.text' or source['flags'] != 0x60501020:
                block('INCOMING_USE_NOT_ORDINARY_CODE', use)
            source_aux = [struct.unpack('<IHHIhBBH', s['aux']) for s in syms.values()
                          if s['section'] == use['section'] and section_symbol(s, secs) and s['aux_count'] == 1]
            if len(source_aux) != 1 or source_aux[0][5] != 1 or source_aux[0][4]:
                block('INCOMING_CODE_SECTION_OWNERSHIP_UNSUPPORTED', use)
            if ('section', use['section']) in graph['live']:
                block('INCOMING_USE_FROM_PROTECTED_CODE', use)
        section_symbols = []
        for i in indices:
            s = syms[i]
            exact_section = (s['name'], s['storage'], s['type'], s['value'], s['aux_count']) == (sec['name'], 3, 0, 0, 1)
            if exact_section:
                a = struct.unpack('<IHHIhBBH', s['aux'])
                section_symbols.append(i)
                expected_selection = 1 if form and form[2] else 0
                if not (a[0] == sec['size'] and a[1] == 0 and a[2] == 0 and
                        a[4] == 0 and a[5] == expected_selection and a[6] == a[7] == 0):
                    block('CANDIDATE_SECTION_AUXILIARY_DIFFERS', i)
            elif not (s['storage'] in (2, 3) and s['type'] == 0 and not s['aux_count'] and
                      0 <= s['value'] < sec['size']):
                block('CANDIDATE_SYMBOL_FORM_UNSUPPORTED', i)
            if not exact_section and special_symbol(s['name']):
                block('CANDIDATE_COMPILER_OR_SPECIAL_IDENTITY', i)
            aliases = sorted(j for j in graph['names'].get(s['name'], []) if j not in indices) if not exact_section else []
            if aliases: block('CANDIDATE_NAME_EQUIVALENCE_ESCAPES_SECTION', dict(symbol_index=i, aliases=aliases))
        if len(section_symbols) != 1: block('CANDIDATE_SECTION_SYMBOL_UNIVERSE_DIFFERS', section_symbols)
        source_fields = [f for f in contract['fields'] if f['coff_relocation']['symbol_index'] in indices]
        if source_fields: block('ORIGINAL_RETAINED_DATA_FIELD_DEPENDENCY', [digest(f) for f in source_fields])
        originals = [b for b in replay['blockers'] if b['code'] == 'UNSUPPORTED_SECTION_SEMANTICS' and
                     b['evidence'] == dict(section=sn, name=sec['name'], flags=sec['flags'])]
        if len(originals) != 1: block('EXACT_ORIGINAL_SECTION_BLOCKER_REQUIRED', len(originals))
        row = dict(section=sn, name=sec['name'], flags=sec['flags'], extent=sec['size'],
                   payload_sha256=coff.digest(sec['payload']), symbol_indices=indices,
                   section_symbol_indices=section_symbols, incoming_physical_uses=uses,
                   outgoing_physical_uses=sec['relocs'], original_retained_data_fields=[],
                   original_data_field_classification='NO_RETAINED_DATA_FIELDS_OMITTED_ONLY_PHYSICAL_USES' if not source_fields else 'UNPROVED_RETAINED_DATA_FIELD_USES',
                   original_data_type_or_base_binding_proved=False,
                   approved=not blockers, blockers=blockers,
                   discharge_blocker_ids=[originals[0]['blocker_id']] if not blockers else [])
        rows.append(row)
    discharged = [i for r in rows for i in r['discharge_blocker_ids']]
    remaining = [b for b in replay['blockers'] if b['blocker_id'] not in discharged]
    return dict(schema_version=1, policy_id=POLICY, kind='typed-initialized-data-omission-witness',
                object_sha256=coff.digest(raw), source_sha256=contract['provenance'].get('source_sha256'),
                recipe_id=contract['recipe_id'], requested_sections=requested_sections,
                contract_identity_sha256=digest(contract), original_certificate_sha256=digest(certificate),
                complete_physical_graph_sha256=digest(dict(sections=certificate['sections'], symbols=certificate['symbols'], edges=certificate['edges'])),
                protected_directed_graph_sha256=graph['graph_sha256'],
                protected_directed_graph_nodes=graph['graph_nodes'], protected_directed_graph_edges=graph['graph_edges'],
                protected_seed_nodes=[list(n) for n in sorted(graph['seeds'])],
                rows=rows, witness_complete=all(r['approved'] for r in rows),
                discharge_blocker_ids=discharged, remaining_blockers=remaining,
                original_certificate_unchanged=True, adapted_root_certificate_created=False,
                collector_envelope_authentication_required=True, **FALSE)
