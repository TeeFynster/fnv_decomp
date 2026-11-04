# Finite ordinary CODE projection

`tools/rebuild/ordinary_code_projection.py` is a separate, finite producer for
original selected CODE roots whose actual singleton omission observations are
positive. It does not change the frozen bulk producer, parser, all-size policy,
original sources, original objects, or the 12,946-export baseline archive.

Version 1 deliberately supports only roots with no relocation fields. This is
an explicit initial scope, not a claim that every positive ordinary observation
can be serialized. Retained CODE and directives must have zero relocations;
field proofs, missing fields, parent EH, references, omitted-definition
conversions and unexpected external records are rejected. TLS, EH, unknown
directives, unsupported COMDAT, source initializers and provider choices gain
no authorization. Canonical reference groups are not applicable to this
zero-field scope; the adapter does not accept or waive a collision certificate.
A field-bearing successor must separately consume its complete fresh field
proof and the reviewed CODE-only V2 group core where applicable.

The operational request uses the existing exact finite schema:

```json
{"schema_version":1,"kind":"fnv-finite-ordinary-root-request","roots":[]}
```

Version 1 also requires every requested root's original coverage status to be
`HISTORICAL_BLOCKED`, checked before any materialization and again in coverage
publication. It rejects `BLOCKED_UNION` candidates, including roots that could
already be present in the separately accepted 1,372-export supplemental pool.
No combined manifest or provider adoption is implied. A later consumer that
admits historical candidates must pin and check every accepted supplemental
export ledger rather than assuming absence from the old 12,946-export pool.

The nonempty root list contains exactly ten fields per root: `original_address`,
`recipe_id`, `recipe_index`, `object_sha256`, `source_sha256`, `symbol`,
`symbol_index`, `section`, `value`, and `size`. Scope is dynamic and finite, at
most 205 roots; no fixed Box address or source spelling selects a provider.

The new central collector's actual receipt binds eight lane artifacts, complete
record ordinals/hashes, exact full contracts, bare frozen ordinary certificates,
all 205 singleton observations and 98 recipe-union observations. This adapter
checks those record hashes and the producer/source pins. Each requested root
must equal an actual singleton's complete original physical identity. It cannot
borrow a mixed union certificate, combine singleton omission decisions into an
unobserved union, or substitute a symbol spelling for a physical index.
Historical blocked status remains provenance; a positive certificate substitutes
only for its proved root-specific omission layer.

An independently authored operational review receipt is mandatory. Its kind is
`ordinary-code-projection-review-v1`; it binds the exact request, accepted actual
central receipt, complete three-file source freeze and producer hashes. It must
record independent source/schema acceptance, independent central outcome
acceptance, a named reviewer and root authorization, with native tools and
executable linking disabled. Root has delegated bounded known-root Python
production after these reviews; the review must describe that existing
authorization honestly rather than manufacture an additional approval.

For an eligible request the driver freshly hashes its exact source and original
manifest object, reconciles authoritative recipes, complete retained v3 MATCH
proof and selected native section/extent, and checks the owned reference image's
exact file hash, exact loaded-buffer digest and unchanged probes. It freshly parses the object and replays the
frozen ordinary observer against the authenticated complete contract; the bare
certificate must be exactly equal. Numeric original indices remain provenance.
No unrelated object or old archive directory is searched.

The pure `project_member` first checks the exact retained section, primary-symbol
and physical auxiliary-slot universes. It retains the exact approved directive
section and selected CODE sections, and nothing else. The frozen name-only
namespace phase preserves every numeric slot. Export names derive from the
original `(recipe_id, object_sha256, symbol_index)` identity. The unchanged
serializer then emits explicit section/symbol/auxiliary bijections. It accepts
no undefined conversion. Independent reparse verifies metadata and payloads;
the exact export census must contain only the requested canonical CODE roots.

The driver uses the unchanged ordinary comparator on the exact original object
before serialization and on the staged output afterward. Every result must be
MATCH with the original address, complete extent, no differences/errors and all
relocations matching. An emitted archive is independently reparsed, including
both defined-export indices; recovered members must be byte-identical and pass
the second COFF reader. No new compiler, native archive tool, executable linker,
disassembler or game/member execution is involved.

All baseline export names are checked for collisions before materialization.
The original 12,946 exports remain unchanged and cannot be silently replaced.
The successor coverage ledger preserves all 68,657 original rows and adds a
separate ordinary-projection status; it does not relabel original assessments.
Unsupported requested roots remain blocked and are not claimed freshly body
compared. Hash/proof, serialization or comparator failure aborts the attempt.

Outputs require a new exclusive private directory. Source snapshots and fsynced
progress precede member work. Limits are sampled peak memory 1 GiB, elapsed
15 minutes and private output 128 MiB, with original objects bounded to 16 MiB.
These are sampled operational checks, not OS hard quotas or a completion
promise. There is no automatic retry. The final receipt is fsynced to a pending
file and atomically published by an exclusive hard link; failed post-publication
input/resource checks remove only that attempt's successful receipt name and
retain evidence plus an abort record. Pre-existing receipt names are preserved.

```text
python -m unittest discover -s tests/rebuild -p test_ordinary_code_projection.py
```

Authored tests cover producer-backed COFF/central-record schemas, canonical
physical identity, zero-relocation enforcement, stale or forged roots/contracts/
certificates, live SafeSEH, extra export/slot scopes, source provenance, central
lane hashes/locators, incomplete coverage, baseline replacement, review refusal,
exclusive publication and drift after publication. Pure synthetic tests do not
open game inputs or native tools. Actual results will be recorded after review;
source readiness is not an emission result. All provider, ABI, link-ready and
runtime flags remain false, and native archive conformance remains separate.


## First measured projection

The independently accepted source v3 and exact eight-root request received a
hash-bound operational review under root's delegated bounded-production scope.
One Python operation completed all eight requests, with no blocked or skipped
root. The new private archive contains eight I386 members, eight canonical CODE
exports and 167 code bytes, with zero relocations and zero undefined records.
All roots were originally `HISTORICAL_BLOCKED`; the old 12,946-export archive and
the supplemental 1,372-export candidate pool were not replaced or modified.

The private result is
`build/rebuild/ordinary-code-projection-first8-v1/receipt.json`, SHA-256
`39f6ac1fabdeb0f4ebed433bbaf3dc86ef82472bd0c24fcb3af18f1aa5da1d80`.
Its archive SHA-256 is
`1f2beeea01a4aef884e474dfbb3ac9eb89bef3cf70de021e77fdd7ee65c3430b`.
The operation recorded eight fresh ordinary MATCH comparisons before projection
and eight afterward. All 55 bound inputs were stable. Sampled peak memory was
353,095,680 bytes; the pre-receipt output measurement was 8,835,585 bytes and
elapsed time 9.797 seconds, below the reviewed limits. Complete coverage preserves
all 68,657 original assessment rows and annotates eight new ordinary emissions
and 68,649 owners not requested in this operation. No wider 72-root eligibility
or source-policy promotion is inferred.

Independent outcome reconciliation checked all 55 pins, original-to-output
section/symbol/auxiliary maps, eight staged/archived/recovered members, both
archive indices, the sixteen saved MATCH reports, all 167 code bytes, complete
coverage and durable terminal journal. The successful receipt was published only
after the terminal journal was durable and closed. No operation was replayed.
The exact pre-emission three-file source snapshot is retained with the result;
a private `post-run-documentation.json` records this later documentation-only
hash transition separately from the unchanged tool and tests.

This is an independently reviewed Python projection result. Native archive
conformance, executable linking, ABI/provider adoption and game/member execution
were not performed and remain unproved. The archive is not automatically added
to an application manifest; all runtime and provider flags remain false.
