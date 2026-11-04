"""Pure joins for the three-component/nine-import diagnostic successor.

The caller re-parses the actual library with the pinned bounded reader and
binds producer/outcome receipts. No native tool or provider is selected here.
"""
import import_kernel32_nine as nine
import application_link_diagnostic as diagnostic

digest = diagnostic.digest

NINE_SOURCE = '696903fd3d5affaf0158da5ccbed7278f05a3b1f3da775c331b72eab22cd3864'
COMPONENTS = {
    'field-first3': ('04a10404134431f73d6ec0bce2b877d566a675b095d254b33d1241f76b8b53c0', 3, 3, 29),
    'typed-code12': ('06857caa370cc3d618dd11204bc2d43fba3a09eba4e7bc7d1f42202db192fa9c', 12, 12, 146),
    'eh-file': ('db86fc462255ec7bf109486538cf16f8b94ae5bcc6135a0f8d3b4778d5e3582b', 1, 1, 12),
}
FALSE_OPERATIONS = ('compiler_performed','archive_generated','object_rewritten','executable_linked',
    'Game_execution','provider_selected','runtime_eligible','ABI_verified')

def require(ok, message):
    if not ok: raise ValueError(message)

def native_component_scope(receipt):
    rows = receipt.get('components', [])
    require(type(receipt.get('schema_version')) is int and receipt['schema_version'] == 1 and
        receipt.get('kind') == 'application-additional-code-native-conformance-v1' and
        receipt.get('status') == 'pass' and receipt.get('input_stability_verified') is True and
        all(receipt.get(key) is False for key in FALSE_OPERATIONS), 'additional native conformance state differs')
    require(len(rows) == 3 and {row.get('label') for row in rows} == set(COMPONENTS), 'exact three native components required')
    for row in rows:
        require(row.get('input_sha256') == COMPONENTS[row['label']][0] and row.get('native_metadata_matches') is True,
            'native component input/metadata differs')
        _, members, exports, relocations = COMPONENTS[row['label']]
        facts = row.get('facts', {})
        if row['label'] == 'eh-file':
            require(row.get('kind') == 'object' and facts.get('all_native_metadata_matches') is True and
                facts.get('relocations') == relocations, 'native EHFile field census differs')
        else:
            objects = facts.get('objects', [])
            require(row.get('kind') == 'archive' and facts.get('complete_native_linker_index') is True and
                facts.get('members') == members and facts.get('exports') == exports and len(objects) == members and
                all(obj.get('all_native_metadata_matches') is True for obj in objects) and
                sum(obj.get('relocations', -1) for obj in objects) == relocations, 'native archive member/export/field census differs')
    return {row['label']: row for row in rows}

def native_nine_evidence(receipt, request, request_sha256, parsed):
    """Replay the accepted producer's exact contract against freshly parsed bytes."""
    expected_inputs = {key+'_sha256': value for key, value in nine.PINS.items()}
    expected_sources = dict(nine.HELPER_PINS, **{'tools/rebuild/import_kernel32_nine.py':NINE_SOURCE})
    require(request.get('inputs') == expected_inputs and request.get('source_sha256') == expected_sources,
        'nine-import original evidence/source ancestry differs')
    expected = nine.reconcile(request, parsed, request_sha256)
    require(all(key in receipt and receipt[key] == value for key, value in expected.items()),
        'native nine-import produced library/request/member facts differ')
    require(receipt.get('all_inputs_tools_sources_stable') is True, 'native nine-import stability not proven')
    return expected


# Exact per-cell proof from the frozen 26-cell runner (39e4af77...), with
# only this separately reviewed cohort cardinality increased to 27.
def frontier_alias_census(proposals, fields, catalog, libraries):
    """Scope extension of the frozen per-cell positive proof, without waivers."""
    require(len(proposals) == 27 and len({p['canonical_IAT_symbol'] for p in proposals}) == 27,
        'exact expanded 27-cell scope required')
    cells = {row['original_IAT_va']: row for row in catalog['imports']}
    require(len(cells) == len(catalog['imports']), 'duplicate original IAT catalog cell')
    result = []
    for proposal in proposals:
        name, va = proposal['canonical_IAT_symbol'], proposal['original_IAT_va']
        uses = [field for field in fields if field['canonical'] == name]
        blockers = []; positive = None; native = None; cell = cells.get(va)
        try:
            require(cell is not None, 'missing original cell')
            positive = diagnostic.import_identity(cell['dll'], cell['export'])
            require(positive == diagnostic.import_identity(proposal['dll'], proposal['export']), 'original import identity differs')
            native = diagnostic.native_pointer_proof(proposal, libraries)
        except ValueError as error:
            blockers.append('IMPORT_IDENTITY:' + str(error))
        expected = '_fnv_undefined_' + digest(diagnostic.canonical(dict(original_base=va, role='iat-cell')))
        if not (name == expected and proposal['pointer_indirection_preserved'] is True and
            proposal['alias_applied'] is False and proposal['runtime_provider_adopted'] is False and
            proposal['source_ABI_approved'] is False):
            blockers.append('POINTER_CELL_POLICY_CONFLICT')
        if not uses:
            blockers.append('NO_INCLUDED_USE')
        for use in uses:
            proof = use['proof']
            if not (use['undefined'] and use['kind'] == 6 and proof.get('role') == 'iat-cell' and
                proof.get('original_base') == proof.get('original_target') == va and proof.get('addend_bits') == 0 and
                proof.get('classification') == 'IAT_POINTER_CELL_NOT_FUNCTION_BODY' and cell is not None and
                (use['component'] == 'actual-entry' or proof.get('import_id') == cell['import_id'])):
                blockers.append('UNPROVED_USE:' + use['component'] + ':' + use['member'] + ':' + str(use['offset']))
        result.append(dict(canonical=name, native_pointer=proposal['proposed_pointer_symbol'],
            library=proposal['library'], original_IAT_va=va, positive_import_identity=positive,
            catalog_export_observation=cell['export'] if cell else None,
            documented_catalog_hint=cell['export'].get('hint') if cell else None,
            native_pointer_proof=native, complete_actual_uses=uses, use_count=len(uses),
            enabled=not blockers, blockers=blockers, scope='expanded diagnostic LINK identity only',
            ABI_approved=False, provider_adopted=False))
    return result

