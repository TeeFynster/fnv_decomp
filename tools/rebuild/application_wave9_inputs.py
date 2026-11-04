"""Exact 31-cell extension of the reviewed per-cell diagnostic identity gate.

No library generation, execution or ABI/provider adoption occurs here.
"""
import application_link_diagnostic as diagnostic
digest=diagnostic.digest
def require(ok,message):
    if not ok:raise ValueError(message)

def wave9_alias_census(proposals, fields, catalog, libraries):
    """Scope extension of the frozen per-cell positive proof, without waivers."""
    require(len(proposals) == 31 and len({p['canonical_IAT_symbol'] for p in proposals}) == 31,
        'exact expanded 31-cell scope required')
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

