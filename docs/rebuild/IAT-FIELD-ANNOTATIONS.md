# Immutable IAT field-proof annotations

`tools/rebuild/iat_field_annotations.py` is a pure metadata adapter for the
CODE59 fields added to the later application cohort. It restores IAT tags from
the complete accepted original field proof, never from source spelling. The
compact projection witness and the complete proof payload remain unchanged.
There is no native process, archive rewrite, import-library generation or alias
application in this module.

`annotate(mapped_fields, full_proofs, catalog_plan, expected_locations)` returns
a copy of the supplied fields. `full_proofs` maps each compact witness's
`field_proof_sha256` to its exact original field record. Each expected location
is the tuple `(component, member, root, physical_section,
physical_symbol_index, offset, kind, field_proof_sha256)`. The complete set of
CODE59 IAT rows must equal that declared set, without missing, extra or duplicate
locations, and the full-proof map must have exactly the required proof hashes.

The adapter validates the canonical SHA-256 of each full record; recipe and
function; physical section, symbol and field; four-byte DIR32 kind and zero
addend; exact own-recipe source resolution; single field overlap; original
operand, representation and base/target; and the canonical `iat-cell` name.
The full proof's original `import_id` and classification must agree with the
exact normal-IAT catalog cell. A conflict or runtime-promotion flag rejects the
record. Source names are provenance only and cannot choose an export.

For each selected row, the returned ledger adds:

- `original_field_proof`: the complete original record, byte-value unchanged.
- `IAT_annotation`: exact catalog identity, import ID, classification, original
  proof hash and false ABI/provider flags.
- Top-level `import_id` and `classification` copied from that authenticated
  original proof.

The original compact `row.proof` and every other field row stay unchanged.
Existing conflicting annotations fail closed. A producer binds the complete
original CODE59 member ledger and sealed context index/spool, reads only the
selected frames with the accepted factory reader, and publishes these
annotations before the cohort's full-field fingerprint is frozen. They are not
a later mutation of an accepted ledger.

`census_view(annotated_fields, catalog_plan)` revalidates the embedded full proof,
physical join and exact catalog annotation, then returns a temporary copy whose
compact witness includes the restored `import_id` and `classification`. This is
the view supplied to the frozen IAT evaluator. The normative annotated ledger
and original proof hashes stay unchanged, so the full-field fingerprint and IAT
census share one immutable evidence source.

The current CODE59 selection has ten IAT fields. A separate bounded metadata
collector accounts for every physical location and records membership in the
accepted 27-cell import mapping. Catalog cells outside that mapping remain
unaliased. These annotations establish no new DLL provider, source ABI,
extraction completeness, runtime closure or application-execution approval.

```powershell
python tests/rebuild/test_iat_field_annotations.py -v
```
