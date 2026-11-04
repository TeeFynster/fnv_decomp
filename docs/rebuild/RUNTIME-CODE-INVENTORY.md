# All-size CODE serialization inventory

This metadata-only target accounts for every one of the 68,657 selected source-retained function owners across all sizes. It does not emit objects, archive members, original bytes, rewritten data, a link, or an executable. Serialization candidate status is an assessment under the reviewed writer subset; it proves neither successful serialization nor ABI, lifetime, provider, or runtime closure. Every execution/provider/readiness flag remains false.

`tools/rebuild/runtime_code_inventory.py` shares `runtime_code_pool.assess_parsed` and `coff_code_archive.parse` with the bounded writer. It calls neither extraction, namespace rewriting, serialization nor archive APIs. The parser runs once per exact manifest-listed object, serially, and the shared structural index is cached within that object. No directory or archive enumeration is used. There is no size ceiling.

## Exact evidence and joins

The fixed report pins are:

| Input | SHA-256 |
| --- | --- |
| selection v2 | `48ae62cdc5b1754b9c4af674ef4716d53afb554882e174a93acf860eaf1c6cb1` |
| retained manifest | `bc62a5fb2553431b1e0547d11f366e52efb73096ea8ceb206c556ae5740a53eb` |
| retained proof v3 | `04d44b73e81982f846bfe8d81806db72ea669586b579ff22007dfd6f7d831297` |
| authoritative recipes | `62f2c8da5f0daa912abdf4576328706711c6561eef7f01c93a89cb71ad46fb6c` |
| binding v2 | `275714631903758efbf5a4f82e2428c6f51838f53b90d0c56d2e5dec5da1d804` |
| data owner v1 | `fac1496a2675e9a6b697d604c8d5b35a2e4b8bb6194e2ec823e5a37d1092f2e8` |
| EH roles v1 | `1e08ae8a908dc0a9d7feba4e5fa3cbcfe3a5f9ed6be3004ed6ac8639497fd788` |

The binding and owner compressed streams must match their exact report hashes. Both reports join the same recipes/selection/objects/proof and image identity; the EH receipt joins the same proof and reference. The image is not opened. Optional index absence remains a checked state before and after observation. The original producer manifest, compiler variants, proof tool hashes, current source hashes, object hashes, assessor/parser hashes and invoked local reader hashes are retained. Report claims are observed evidence, not authentication or proof that a historical command executed.

All 2,988 compiled manifest records must reconcile against authoritative recipes and all 68,667 checked proof rows must retain MATCH status with their exact source/object identities. Each selected row must match its full selected native section/value/span. The data-owner provider identity supplies the physical symbol index; the current parsed object must contain the matching definition at that exact physical index (duplicate spellings elsewhere stay distinct). Source-generated globals and four-byte declarations never become storage extents or selected data providers.

## Detail schema and complete accounting

The private gzip JSONL has three record classes:

- `SELECTED_CODE_SERIALIZATION_ASSESSMENT`: one per selected address. Includes immutable recipe/object/symbol-index identity, source hash, native section/value/size, size band, shared assessor result, exclusive category, full blocker/obligation metadata, exact binding row ordinal and canonical row SHA-256, missing-field count, same-parent EH pieces and false-piece count. Each original binding row remains anchored to the pinned complete stream, preserving its original target, interior/base, kind, physical field and signed-addend bits without replicating that row. No extraction plan or payload is published.
- `RECIPE_COFF_METADATA`: one per parsed manifest object. Includes every section index/name/complete extent/flags/relocation count and relocation-metadata digest, total physical symbol-table slots, symbol/aux metadata digest, decoded section auxiliaries, association children, global weak/common/aux/SafeSEH/directive problems and exact source directives. The original object hash anchors all omitted table bytes. A strict-parser rejection is an explicit format blocker for every selected owner in that recipe, with the object identity retained.
- `RECIPE_EH_EVIDENCE`: one per recipe, retaining every v3 piece (including unsuccessful pieces without a textual note) and every diagnostic. All 95 original notes remain visible. Absence of a note never proves EH/frame closure. Typed EH role evidence remains hash-linked, not treated as an automatic repair.

The binding stream is consumed in monotonic recipe order with bounded per-unit buffering, exact event/class/kind/consistency census and duplicate-site rejection. All 490,713 ordinary field rows plus the 88 original missing fields must be consumed, and all 59 affected owners remain blocked even if another policy observation would otherwise qualify them. Overlay evidence cannot replace the original 88-field baseline. Owner stream census and exact selected-provider coverage must also reconcile. All data/arena/view/provider obligations remain linked through the pinned complete owner ledger; no new materialization approval is inferred.

The summary contains mutually exclusive bands `1-255` (59,634), `256-511` (4,604) and `512+` (4,419), exclusive primary categories and their cross-tabulation. Every blocker is additionally counted in a nonexclusive reason census so primary-category precedence cannot hide a second blocker. The primary order is missing relocation, failed parent EH/association, unsupported format, recipe-wide policy, section/symbol, then other field/policy. Unblocked owners are split by whether canonical undefined obligations remain.

## Conservative shared policy

The initial writer requires a fully owned ordinary whole CODE section with checked extent. Shared/extra-entry sections, unsupported auxiliaries or opaque hidden indices cannot be truncated or silently discarded. It rejects unsupported EH/associative/SafeSEH closure and missing-field cases. Defined source placeholder data is not retained. Only the already proved scalar's two literal sections (physical 25/26 in its exact recipe) are allowed by this inventory. Other unresolved addresses may remain canonical undefined identities where the shared assessor permits them; that syntax does not supply a provider, safe IAT conversion, CRT/TLS implementation, EH helper or callable interior contract.

Weak/common/auxiliary and directive checks currently apply to the whole recipe. Thus the allocator proposal is blocked by unrelated weak/aux records even when a selected section appears simple. This is serialization-policy conservatism, not evidence of semantic invalidity of that game function. The inventory uses the same assessor; it does not introduce a weaker global-symbol pruning rule or alias names by spelling/content.

Physical original section/symbol indices remain immutable provenance. A future separately reviewed extraction can use an exact old/new index bijection; this observation target performs no remapping. It never inserts tombstones, fillers, empty fake sections or guessed boundaries.

## Publication, recovery and review gate

Outputs are exclusive. Summary, compressed details and progress journal must be distinct from every named input/source/object/tool. Compressed output is staged privately, and complete coverage and post-observation hash stability must pass before publication. An fsynced journal records start, every hundred objects, completion or failure; a failed run keeps its journal and removes only outputs published by that attempt. No preexisting failure is overwritten. Current inputs are rehashed after the read-only pass, including exact original objects/sources and dependency modules.

Planned private paths are `build/rebuild/runtime-code-inventory-native-v1.json`, `.jsonl.gz` and `.json.progress.jsonl`. The CLI requires explicit writer/parser hashes and the seven exact report paths plus compressed binding/owner details. These operational pins are not an authentication boundary. Source/schema and synthetic test review, followed by root go, is required before the actual manifest object observation. The first approved all-size run completed; its observations follow.

Focused command: `python -m unittest discover -s tests/rebuild -p test_runtime_code_inventory.py`. The 20 original synthetic tests cover all-size boundaries, source/native/physical joins, exact signed field provenance and duplicate spellings, stream gaps/counts/duplicates, missing/EH overrides, unrelated weak quarantine, unowned placeholder exclusion, parser failure accounting, byte/path exclusion, collisions and dependency mutation. They invoke no compiler, linker or game code.


## First complete read-only observation

Root authorized the reviewed inventory at `c2fdbd52b4b7f4b7c68f9d80ad03708ba57d42b29e5938dfcf9769366a1ffd0b`, shared assessor `06f373e8592571244b8e70c913a037812a73c856bc8e42b5b2c9b509b732ed81` and parser `76244d2d4dca4c1f8aa72224be1ef5c92f68976b5cda7d31b5cfe23d3cc29e64`. The single serial pass completed in 53.265 seconds. It accounted for all 2,988 objects, 68,657 selected owners and 68,667 checked recipe rows. All protected sources, objects and tools remained hash-stable; the optional index remained absent. Producer variants remain 2,713 SP1, 274 RTM and one VC8 recipes, without treating comparison provenance as runtime ABI compatibility.

| Size band | Selected owners | Serialization candidates | Blocked |
| --- | ---: | ---: | ---: |
| 1-255 | 59,634 | 15,745 | 43,889 |
| 256-511 | 4,604 | 607 | 3,997 |
| 512+ | 4,419 | 507 | 3,912 |
| Total | 68,657 | 16,859 | 51,798 |

Candidates split into 15,595 with canonical undefined obligations and 1,264 with only owned fields under this policy. Neither group was emitted. Exclusive blocker categories are 40,176 recipe-wide policy, 6,395 parent EH/association, 5,079 section/symbol, 89 other field/policy and 59 missing-relocation owners. Full nonexclusive reasons remain in the receipt; for example 39,435 owners encounter weak/common records and 39,189 encounter SafeSEH, and these populations overlap. The 88 original missing fields across 59 owners, 95 EH diagnostics and 128 unsuccessful EH pieces remain intact, including unsuccessful pieces without a diagnostic. The complete binding row sequence digest is `d59b03314c5e061745ccba02af72fc6da00a77ecda4e2d94fafb9e340cff2d6e`, matching the existing owner-ledger provenance.

Private artifacts are the planned `runtime-code-inventory-native-v1` files under ignored rebuild output:

| Artifact | SHA-256 |
| --- | --- |
| summary JSON | `02a77cce3f43c1786cd027e72ffb17e76ffe6766c2823872254015b6e40549f6` |
| compressed details | `91cdc91af6530e6e80e2104cdfeb9bd6928e17fa0f75bcf066734985248f1031` |
| persistent progress journal | `6873179f438bcc9f0d8b57f0abf913783c497fb14e888ed90890c68641d778d9` |

Independent output reconciliation passed: all 68,657 owner assessments and all 490,801 binding references were joined to the pinned source streams, and missing-field/EH counts reconciled. This was stream reconciliation, without a second original-object scan. No code/data emission, compile, link, native execution, provider selection or runtime/ABI approval occurred. The accepted source/test files remain unchanged after the run.

The inventory receipt binds the then-current `runtime_code_pool.py` producer
SHA-256 `06f373e8592571244b8e70c913a037812a73c856bc8e42b5b2c9b509b732ed81`.
A subsequent deferred-reader pin change produced the current tool SHA-256
`729f189e2893c7f3a3e3cd97df7d7381ac115169e1d75cf664e6bbc1c587b277`.
The exact earlier producer is preserved in the private bounded-pool v3 source
freeze; the inventory receipt does not bind the later tool version.
