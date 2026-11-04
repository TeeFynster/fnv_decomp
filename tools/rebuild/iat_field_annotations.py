"""Pure exact IAT annotations over mapped fields and immutable full field proofs."""
from __future__ import annotations
import copy
import hashlib
import json
import import_projection as imports

CLASSIFICATION = 'IAT_POINTER_CELL_NOT_FUNCTION_BODY'
CATALOG_SHA256 = imports.PLAN_PIN
require = imports.require


def digest(value):
    return hashlib.sha256(json.dumps(value, sort_keys=True, separators=(',', ':')).encode()).hexdigest()


def location(row):
    proof = row['proof']
    section = proof['physical_section']
    require(proof['section'] == section and proof['symbol_index'] == row['physical_symbol_index'] and
            proof['offset'] == proof['field_offset'] == row['offset'] and proof['kind'] == row['kind'],
            'compact physical field coordinates differ')
    return (row['component'], row['member'], row['root'], section, row['physical_symbol_index'],
            row['offset'], row['kind'], proof['field_proof_sha256'])


def validate_full(row, full):
    compact = row['proof']; key = location(row)
    require(digest(full) == compact['field_proof_sha256'], 'full original proof hash differs')
    native = full['coff_relocation']
    base = compact['original_base']
    require(row['undefined'] is True and row['canonical'] == compact['canonical_name'] ==
            imports.unresolved(base, 'iat-cell') and compact['role'] == 'iat-cell' and
            compact['original_target'] == base, 'mapped canonical IAT role/base differs')
    require(row['kind'] == native['kind'] == 6 and compact['addend_bits'] == native['addend'] == 0 and
            native['width'] == 4 and full['physical_field_overlap_count'] == 1,
            'not one exact zero-addend DIR32 pointer field')
    require(full['physical_section'] == key[3] and native['symbol_index'] == key[4] and
            full['physical_offset'] == native['offset'] == key[5] and full['function_va'] == row['root'] and
            full['recipe_id'] == row['recipe_id'] and full['event'] == 'SELECTED_FUNCTION_COFF_RELOCATION' and
            int(full['original_field_va'], 16) == int(row['root'], 16)+full['source_field_offset'],
            'full proof physical/recipe/function join differs')
    require(full['classification'] == CLASSIFICATION and full['proof_consistency'] == 'EXACT_OWN_SOURCE_RESOLUTION'
            and full['source_resolution_basis'] == 'OWN_RECIPE_BINDING' and
            full.get('import_pointer_source_conflict') is not True, 'unverified or conflicting original IAT proof')
    require(full['derived_source_symbol_base_va'] == full['exact_original_target_va'] ==
            full['expected_original_target_va'] == base and full['original_operand'] == int(base, 16) and
            full['representation'] == dict(addend=0, representation='ABSOLUTE_VA_DIR32', target=int(base, 16)),
            'original field operand/base/representation differs')
    require(all(full.get(flag) is not True for flag in
            ('provider_selected', 'runtime_eligible', 'game_fixup_approved', 'abi_verified')),
            'original proof has unexpected runtime promotion')
    return key


def annotate(mapped_fields, full_proofs, catalog_plan, expected_locations):
    """Annotate exactly the declared CODE59 IAT fields; never edit original proofs."""
    catalog = imports.catalog(catalog_plan)
    expected = set(map(tuple, expected_locations))
    require(len(expected) == len(expected_locations) and expected, 'expected field set duplicated or empty')
    selected = [r for r in mapped_fields if r['component'] == 'CODE59' and r['proof'].get('role') == 'iat-cell']
    keys = [location(r) for r in selected]
    require(len(keys) == len(set(keys)) and set(keys) == expected, 'missing, extra or duplicated CODE59 IAT field')
    required_hashes = {r['proof']['field_proof_sha256'] for r in selected}
    require(set(full_proofs) == required_hashes, 'full original proof coverage differs')
    result = copy.deepcopy(mapped_fields)
    for row in result:
        if row['component'] != 'CODE59' or row['proof'].get('role') != 'iat-cell':
            continue
        full = full_proofs[row['proof']['field_proof_sha256']]
        validate_full(row, full)
        base = row['proof']['original_base']
        require(base in catalog, 'exact original base is outside normal IAT catalog')
        cell = catalog[base]
        require(full['import_id'] == cell['import_id'], 'original full proof/catalog import identity differs')
        annotation = dict(schema_version=1, kind='exact-original-IAT-field-annotation',
            catalog_sha256=CATALOG_SHA256, original_IAT_va=base, import_id=full['import_id'],
            classification=CLASSIFICATION, dll=cell['dll'], export=cell['export'],
            field_proof_sha256=row['proof']['field_proof_sha256'],
            provider_selected=False, ABI_verified=False)
        for key, value in dict(original_field_proof=full, IAT_annotation=annotation,
                               import_id=full['import_id'], classification=CLASSIFICATION).items():
            require(key not in row or row[key] == value, 'existing annotation conflicts')
            row[key] = copy.deepcopy(value)
    return result


def census_view(annotated_fields, catalog_plan):
    """Revalidate annotations and return a temporary view for the frozen IAT census."""
    result = copy.deepcopy(annotated_fields)
    catalog = imports.catalog(catalog_plan)
    for row in result:
        if 'IAT_annotation' not in row:
            require(not (row['component'] == 'CODE59' and row['proof'].get('role') == 'iat-cell'),
                    'CODE59 IAT field missing reviewed annotation')
            continue
        full = row['original_field_proof']; validate_full(row, full)
        ann = row['IAT_annotation']
        cell = catalog.get(row['proof']['original_base'])
        require(ann.get('kind') == 'exact-original-IAT-field-annotation' and ann.get('schema_version') == 1 and
                cell is not None and ann['dll'] == cell['dll'] and ann['export'] == cell['export'] and
                ann['import_id'] == cell['import_id'] and
                ann['catalog_sha256'] == CATALOG_SHA256 and ann['original_IAT_va'] == row['proof']['original_base'] and
                ann['field_proof_sha256'] == row['proof']['field_proof_sha256'] and
                ann['import_id'] == row['import_id'] == full['import_id'] and
                ann['classification'] == row['classification'] == full['classification'] == CLASSIFICATION and
                ann['provider_selected'] is False and ann['ABI_verified'] is False,
                'annotation/full-proof identity or promotion differs')
        # Only this returned view changes the compact witness. The published
        # ledger and embedded original full proof retain their exact hashes.
        row['proof']['import_id'] = full['import_id']
        row['proof']['classification'] = full['classification']
        if 'import_pointer_source_conflict' in full:
            row['proof']['import_pointer_source_conflict'] = full['import_pointer_source_conflict']
    return result
