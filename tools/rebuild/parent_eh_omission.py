"""Expanded EH readonly DATA omission; no storage, provider or serialization.

The caller invokes this during a fresh parent/EH replay. Ordinary certificates
and their narrower witnesses remain immutable. This independently recomputes
physical protection under the complete expanded retention scope.
"""
from __future__ import annotations
import copy
import hashlib
from pathlib import Path
import ordinary_initialized_data_omission as initialized

POLICY = 'parent-EH-expanded-readonly-omission-v1'
INITIALIZED_PIN = '1a0e8aa2271218f59c11497c1363b41f099bb259791e19adac7d80718e7a5d7b'


def observe(raw, contract, ordinary_certificate, expanded):
    """Return exact occurrence-bound discharges; unknown forms stay blockers.

    `expanded` is an internal fresh-observer scope, never an approval token.
    A disk writer must replay the complete parent observer, not trust this dict.
    """
    require = initialized.require
    digest = initialized.digest
    require(hashlib.sha256(Path(initialized.__file__).read_bytes()).hexdigest() == INITIALIZED_PIN,
            'initialized omission producer changed')
    obj = initialized.coff.parse(raw)
    require(ordinary_certificate == initialized.ordinary.assess_object(obj, contract),
            'ordinary replay differs')
    require(expanded['semantic_graph_verified'] is True and
            expanded['semantic']['object_sha256'] == initialized.coff.digest(raw) and
            expanded['semantic']['contract_sha256'] == digest(contract),
            'expanded semantic identity differs')
    sections, symbols = obj['sections'], obj['symbols']
    keep = expanded['retained_sections']; primary = expanded['retained_primary_indices']
    require(keep == sorted(set(keep)) and set(keep) <= sections.keys() and
            primary == sorted(set(primary)) and set(primary) <= symbols.keys(),
            'expanded physical scope differs')
    require(expanded['retained_physical_slots'] == sorted(j for i in primary
            for j in range(i, i + 1 + symbols[i]['aux_count'])), 'expanded aux scope differs')
    require(set(ordinary_certificate['retained_section_indices']) <= set(keep) and
            set(ordinary_certificate['retained_primary_indices']) <= set(primary),
            'expanded scope lost ordinary roots')
    requested = sorted({b['evidence']['section'] for b in expanded['blockers']
                        if b['code'] == 'UNSUPPORTED_SECTION_SEMANTICS' and
                        isinstance(b['evidence'], dict) and
                        (b['evidence'].get('name'), b['evidence'].get('flags')) in initialized.FORMS})
    if not requested:
        return dict(policy_id=POLICY, rows=[], discharge_occurrences=[],
                    expanded_scope_sha256=digest(expanded), provider_selected=False,
                    runtime_eligible=False, emission_approved=False)
    # Existing producer verifies the original certificate and every readonly
    # section predicate. Its result alone is insufficient for expanded scope.
    witness = initialized.observe_omitted_initialized_data(raw, contract, ordinary_certificate, requested)
    graph_scope = dict(retained_section_indices=keep, retained_primary_indices=primary,
                       omitted_definition_conversions=[dict(symbol_index=i) for i in expanded['undefined_conversions']],
                       edges=expanded['edges'])
    graph = initialized.protected_graph(obj, graph_scope)
    rows = []; occurrences = []
    for row in witness['rows']:
        sn = row['section']; indices = row['symbol_indices']; blockers = []
        if not row['approved']:
            blockers.append(dict(code='ORIGINAL_TYPED_READONLY_WITNESS_BLOCKED', evidence=row['blockers']))
        if sn in keep or ('section', sn) in graph['live']:
            blockers.append(dict(code='EXPANDED_DATA_SECTION_LIVE', evidence=sn))
        live = [i for i in indices if i in primary or ('symbol', i) in graph['live']]
        if live: blockers.append(dict(code='EXPANDED_DATA_SYMBOL_LIVE', evidence=live))
        for use in row['incoming_physical_uses']:
            if use['section'] in keep or ('section', use['section']) in graph['live']:
                blockers.append(dict(code='EXPANDED_INCOMING_USE_LIVE', evidence=use))
        original = [(ordinal, b) for ordinal, b in enumerate(ordinary_certificate['blockers'])
                    if b['blocker_id'] in row['discharge_blocker_ids']]
        if row['approved'] and len(original) != 1:
            blockers.append(dict(code='EXACT_BLOCKER_OCCURRENCE_REQUIRED', evidence=len(original)))
        discharged = [] if blockers else [dict(ordinal=ordinal, blocker_id=b['blocker_id'],
                                               blocker_sha256=digest(b)) for ordinal, b in original]
        occurrences.extend(discharged)
        rows.append(dict(section=sn, approved=not blockers, blockers=blockers,
                         original_row_sha256=digest(row), discharge_occurrences=discharged))
    require(len({r['ordinal'] for r in occurrences}) == len(occurrences), 'duplicate blocker occurrence')
    return dict(policy_id=POLICY, object_sha256=initialized.coff.digest(raw),
                contract_sha256=digest(contract), ordinary_certificate_sha256=digest(ordinary_certificate),
                expanded_scope_sha256=digest(graph_scope), expanded_graph_sha256=graph['graph_sha256'],
                physical_universe_sha256=digest(dict(sections=sorted(sections), primary=sorted(symbols),
                    slots=sorted(j for i, s in symbols.items() for j in range(i, i + 1 + s['aux_count'])))),
                original_witness=copy.deepcopy(witness), rows=rows, discharge_occurrences=occurrences,
                ordinary_result_unchanged=True, original_data_storage_adopted=False,
                provider_selected=False, runtime_eligible=False, emission_approved=False)
