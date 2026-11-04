# Root CODE closure observer

`root_code_closure.py` is a separate metadata-only observer. Its current source is the reviewed ordinary-v2 successor; the ordinary-v1 source and blocked receipts remain separately frozen. It never rewrites names, serializes objects, emits code/data, compiles, links or executes. It preserves the frozen pool/inventory implementations. Its supported driver is fixed to allocator `0x00aa13e0` (recipe2734, section41/symbol141/62bytes) and application entry `0x0086a850` (recipe0576, section199/symbol1215/4532bytes). Source/schema review must precede their exact read-only observation.

The observer consumes exact pinned recipes, producer manifest, selection v2, retained proof v3 and final binding v2 plus its compressed details. It validates all saved binding rows/counts but opens only the two named original objects and sources. The parser is explicitly pinned to `76244d2d4dca4c1f8aa72224be1ef5c92f68976b5cda7d31b5cfe23d3cc29e64`; reused inventory helpers remain pinned to `c2fdbd52b4b7f4b7c68f9d80ad03708ba57d42b29e5938dfcf9769366a1ffd0b`. Producer/oracle/compiler observations remain evidence claims, not authentication or runtime ABI approval.

## Pure API and graph

`assess_object(parsed_object, contract)` returns a metadata certificate. The contract has exact roots `{original_address,symbol,symbol_index,section,value,size}`, source/object/producer/proof provenance, complete per-root binding rows, original missing-field identities, parent-EH observations and the fixed `selected-code-only-no-source-initializers-v1` export policy. Incomplete evidence is rejected, not treated as an empty dependency set. The driver guards the exact known identities and hashes; arbitrary direct Python calls are not an authorization boundary.

The observer validates every physical primary/auxiliary slot and complete section metadata. Every section relocation, including omitted sections, appears in `PHYSICAL_SECTION_RELOCATION` edges; these edges alone do not make omitted targets live. Exact reviewed name/characteristic combinations are supported for ordinary CODE/data/debug/EH sections and the two known linker tables. Unknown section flags/names, unrecognized symbol storage/type semantics or missing COMDAT auxiliaries fail closed instead of receiving approved omission status. Special initializer/TLS sections currently remain unsupported rather than guessed droppable. Known section auxiliary associations are decoded in both directions, including omitted sections, with global cycle and hidden-index checks. Known weak records require valid primary fallback indices, the observed search characteristic2, one auxiliary, understood type/section/value and zero reserved fields. Opaque auxiliary forms, unknown weak semantics and fallback cycles block even if no ordinary relocation references them. File auxiliaries are recognized as compiler/debug provenance, not copied as bytes.

Selected CODE sections must have exact complete checked extent, external function identity at value0, the reviewed ordinary flags and COMDAT selection1. Extra function entries/aliases remain blockers. Recognized static local labels can remain at their exact offsets. The only current debug association omission is the observed 16-byte `.debug$F` form with the exact flags and one DIR32NB reference to its physical parent; unknown/EH children block instead of being guessed debug-only.

All retained runtime relocations must join one-to-one with the complete saved physical field proof. Actual symbol metadata, kind, operand/addend bits, field offset, original base/target arithmetic, overlap count and exact own-source consistency are checked. TLS/EH/unsupported address roles, ABSOLUTE targets, IAT/body confusion and special source-domain conversions remain blockers. References into omitted ordinary definitions become explicit conversion obligations; no definition/storage is generated. A physical symbol with conflicting base/role identity blocks. Missing baseline fields and parent EH independently remain blockers.

Name resolution is conservative dependency discovery, not provider aliasing. Starting from every retained symbol, relocation target, compiler metadata record and identified directive root, the observer follows exact same-name symbol records and known weak fallback chains. Section/file metadata names do not collapse unrelated section records. An otherwise unused weak/common record sharing a live external spelling cannot disappear merely because the relocation chose a different physical index. Reachable weak/common records block; an extra live name-alias without an exact retained/field disposition also blocks. Name equivalence never selects a provider or merges physical records.

Directives preserve exact payload identity through the original object hash. Only the observed LIBCMT then OLDNAMES default-library contract is accepted; all other operations block globally. Recognized INCLUDE/EXPORT/ENTRY/ALTERNATENAME syntax additionally records candidate name-resolution edges while remaining unsupported. Unknown directives cannot be dropped or normalized. Default libraries remain unresolved future linkage dependencies.

SafeSEH tables are validated as index-bearing metadata, including their exact supported flags, entry boundaries, primary target identities and bounds. Whole-table omission is a candidate only if every registered handler is outside retained sections and live name/fallback resolution. Root/alias/retained handler membership remains an explicit adapter blocker. There is no entry filtering, index rewrite, handler substitution or synthesized table. Metadata `@feat.00` must retain the reviewed value1 and exact absolute/static form; `@comp.id` retains its observed value. Unknown compatibility values block.

## Certificate and consumers

The certificate includes:

- `policy_id=root-code-closure-observation-v1`, `status`, `closure_observed`, `root_closure_candidate` and always-false `full_serialization_eligible`, `graph_observation_complete` and exact contract/provenance hashes.
- `roots`, `exported_primary_indices`, `retained_runtime_section_indices`, full `retained_section_indices`, `retained_primary_indices` and `retained_physical_slots` (primary plus auxiliary). Full retained sections include `.drectve`; main's expected sets are runtime `[199]` and serialized `[1,199]`, not interchangeable.
- Complete per-section and per-symbol dispositions, decoded auxiliary fields, every graph edge, exact runtime field identities and original target/addend roles, SafeSEH registrations and `omitted_definition_conversions` with their original section/value and referencing field indices.
- Reason-coded blockers with stable `blocker_id` hashes. Every original section and physical symbol/auxiliary slot is accounted; candidate omission rows are never approval when the certificate is blocked.

All emission/provider/runtime/ABI/link/namespace flags remain false. `canonical_namespace_collisions_resolved` is always false. Main's two undefined records referring to selected original `0x0043d4d0` require the separate typed-name certificate; successful root closure alone does not relax collision protection. A consumer must verify the whole certificate's canonical hash, its file/stream hash, the exact original object/root-set and complete retained index sets. It must not combine one-root drop lists or ignore directive symbols in the planned index bijection.

Source-global placeholder definitions are excluded from exported/storage providers. The export set is exactly the selected CODE roots; omitted definitions, tentative commons, source initializers, CRT/TLS/IAT/loader storage and helper exports remain explicit excluded obligations. This product does not claim complete translation-unit initialization semantics or startup/lifetime closure.

## Composition with future EH policy

Graph observation completeness and serialization candidacy are separate. A complete physical graph may still contain known reachable weak/common, missing-field, parent-EH or live-SafeSEH blockers. The certificate embeds `omission_subcertificate` with exact object/root/retained-section/primary/slot scope, edge and disposition hashes, full provenance/contract/policy hashes, unresolved blocker IDs and the subset of exact EH/SafeSEH extension-obligation IDs. `omission_approved` stays false.

A separately reviewed composed EH policy may prove only the matching EH/SafeSEH obligations under identical physical identities. It cannot override unknown child/auxiliary/index/directive edges, weak/common resolution, original missing fields, bad proof joins or canonical-name conflicts. Unknown children fail graph completeness; their name alone does not identify EH. Adding retained runtime EH sections changes scope and requires recomputing omission/name/fallback/directive closure. No smaller-root certificate can approve the expanded set. The present observer deliberately does not adopt EH children or make a third EH positive; the future adapter must establish the expanded graph and all byte/frame obligations separately.

## Driver, stability and publication

The supported CLI requires exact manifest, retained, selection, recipes, binding and binding-details paths, explicit parser hash and fresh summary/detail paths. It hash-checks sources, named objects, parser, observer, reused helpers and retained proof tool dependencies before/after observation. Source/object/source-proof/recipe identities and optional-index absence are preserved. The original reference is never opened; only its agreed receipt identity is retained.

The summary lists canonical certificate hashes; gzip JSONL contains two bare certificate objects, selectable by exact recipe/root identity. Planned private paths are `build/rebuild/root-code-closure-native-v1.json`, `.jsonl.gz` and `.json.progress.jsonl`. Outputs are exclusive and cannot alias protected inputs; the fsynced journal preserves start/object/completion/failure notes. Failed publication removes only newly written outputs and preserves the failure journal. A second final stability check runs before summary publication.

The first source/schema checkpoint has 26 original synthetic tests, run with `python -m unittest discover -s tests/rebuild -p test_root_code_closure.py`. Cases cover unused/reachable/same-name weak records, fallback chains/cycles/unknown indices, common storage, hidden auxiliaries, root/alias/mixed/invalid SafeSEH, debug/EH children, association cycles, implicit directives/order, metadata compatibility, missing/EH blockers, root-set unions, exact addend/field coverage, placeholder conversions complete physical slot accounting, omitted-section relocation edges, full provenance scope and unknown section/symbol semantics. They perform no original-object observation or native calls. The first approved two-object observation completed with blockers; its factual result follows.


## Ordinary v1 observation: both cases blocked

The exact reviewed observer `2d07eea2d711d9c9ac0b17e1fd0275ca8753f6a6c2bc25b82fbe973d1d3189e8` ran read-only on the two named objects with all source/object/producer/proof/tool hashes unchanged. The optional index remained absent. Both `graph_observation_complete` and `root_closure_candidate` are false for both cases; full serialization, namespace, provider, ABI, link and runtime flags remain false. No positive certificate was fabricated and no policy was weakened after observation.

| Case | Runtime / full serialized section set | Required primary / physical slots | Actual remaining blockers |
| --- | --- | ---: | --- |
| Application entry0576 | `[199]` / `[1,199]` | 285 / 287 | 23 unsupported storage-class6 LABEL records in omitted sections; one unproved live same-name dependency |
| Allocator2734 | `[41]` / `[1,41]` | 6 / 8 | Five unsupported storage-class6 LABEL records in omitted section141 |

The complete graph includes 4,019 physical section relocations for main (442 retained references), and 359 for allocator (one retained reference). Main's 18 SafeSEH registrations remain outside the retained scope. Allocator's six weak records/fallbacks are decoded, none reached by the root; debug child42 is accounted as the known excluded association. These facts do not override the remaining blockers.

Main's additional name-resolution blocker is exact spelling `__imp__GetForegroundWindow@0`, physical live index680 and nonretained index2830. It is distinct from the separate typed-name adapter's zero-addend selected-code group289/1392. The observer correctly refused to discard the second name-equivalent record without a proof. A future narrow extension must retain exact IAT pointer-cell identity and cannot equate import cells from spelling alone.

The LABEL records are a concrete unsupported-format population, not evidence of missing game code. No generic unknown-record fallback was added. Supporting this known form requires its own bounded rule, tests and review; v1 remains immutable evidence of the original strict policy.

| Private artifact or certificate | SHA-256 |
| --- | --- |
| `root-code-closure-native-v1.json` | `d3bf0d5148f594384c400485cd25e5377b6bb16408f57a835cfca9d0df90feaa` |
| compressed certificate details | `93a5ddce2b4fc8649377ae9be7ad780d9f4a658fb722b0507535762282efa9b1` |
| persistent progress journal | `b5df3e5a03e95230290b9e7ae52d8c463b72485b3d09d2985bee15c2630f41ac` |
| Canonical main certificate | `afbfedab3dec5b26520dbab3b17b3ee32ce34c0e7b1b94e3201d98f11f0124e8` |
| Canonical allocator certificate | `0320c41e0cf91e4eaa62ccb90edd9cceccf7d067a3127f5b3b0cab3e5534bfde` |

Independent output reconciliation passed: certificate hashes, complete physical-slot and relocation counts, blocker identities and all false approval flags reconcile. Both results remain blocked with incomplete graph observations; no omission or serialization is approved. No all-size rerun, expanded-EH mode, source/object mutation, code/data emission, compile, link or native execution occurred. The future expanded-retention composition remains a separate versioned policy and cannot consume this ordinary blocked certificate as a positive.


## Ordinary-v2 source successor: two explicit refinements

Root approved implementation only after independent review of `ROOT-CLOSURE-BLOCKER-REFINEMENT.md` (`c5ea304c2c92cdc21fd09457a46cc97cc5650f4699dc50cd7f9860610ee7f1f9`) and evidence (`23613b8ac464a606f6ffff667fa118f5df401bbbe2d28a9e3fbe63bedd674d48`). Before edits, v1 tool/test/doc bytes were preserved privately under `root-code-closure-native-v1/source-freeze-v1`; the tool remains exactly `2d07eea2d711d9c9ac0b17e1fd0275ca8753f6a6c2bc25b82fbe973d1d3189e8`. Its blocked outcomes above are not superseded or relabeled.

The new ordinary policy is `root-code-closure-observation-v2`, still schema1. This is not the reserved future expanded-EH retention mode. Its fixed driver remains main0576/allocator2734 only, and no new real-object observation is authorized by the source change.

The only supported additions are:

- **Proved omitted local LABEL:** class6/type0/aux0, observed numeric `$LN` form, valid positive ordinary `.text` section/flags and strict in-bounds offset. The containing complete MATCH section and every incoming field must prove exact own-section use, zero-addend DIR32, exact original interior base/target and non-callable label role. All users and the label section must be omitted, with no retained, directive, fallback or SafeSEH dependency. Same-spelled local records stay physically distinct; external/weak/common/unknown name ambiguity blocks. Retained labels, unknown forms and incomplete use/owner proofs stay blocked.
- **Proved unused redundant undefined IAT record:** only the observed `__imp__GetForegroundWindow@0` group with plain section0/value0/type0/storage2/aux0 members. Every actual member use must join exact source/field metadata and the original cell `0x00fdf2fc`, import175, pointer-cell role, zero DIR32 addend and the pinned original USER32 `GetActiveWindow` descriptor. The unused member must have no retained/fallback/SafeSEH/directive dependency; exactly one member remains required. The complete name relationship stays in the graph with an explicit proof/disposition, rather than silently disappearing. If multiple members become required, a separate namespace-policy blocker remains.

No symbol index is merged, renamed or retargeted. No provider/export is chosen from the misleading source spelling. The retained selected-code group289/1392 remains independent and `canonical_namespace_collisions_resolved` stays false.

The pure contract now additionally requires `unit_proofs_complete`, `unit_verified_functions`, `omission_field_proofs` and `iat_import_observation`. The driver derives them from the exact v3 complete unit proofs, the complete saved binding stream and pinned original import plan (`e39b8db63ef73aea57b5dd4963ff29310524644ca36e137cd8b5461a3c90a23f`). The CLI adds required `--imports`. Omission-field rows are restricted to class6 target records and the observed IAT spelling; complete actual physical-use coverage is then checked against the parsed object. Provenance includes unit binding row ordinal/hash references and the import-plan hash. Consumers must reconstruct the new exact contract and compare a freshly recomputed full certificate under the pinned producer source, not accept an arbitrary self-hashed candidate.

New `omission_refinements` rows retain physical member identities, all exact use proofs, original target roles, and reason-coded label/IAT dispositions. Source/producer/input/index stability, complete physical graph/disposition accounting, original88 baseline blockers and existing EH/weak/unknown-format gates remain intact. Full serialization/namespace/provider/runtime approval stays false even if the new root-closure candidate succeeds.

There are 37 focused original synthetic tests. Added positives cover complete omitted label uses and exact unused IAT duplicate identity; negatives cover reachable/malformed labels, unknown storage/auxiliary/owner, local-name versus external ambiguity, cross-section uses, wrong cell/role/import ID/addend, missing evidence, definition/common/type/weak/aux distinctions, descriptor/source-name confusion and expanded root sets. Tests use authored metadata only. Source/schema review must pass before a fresh `root-code-closure-native-v2` summary/detail/progress run; no v2 actual-object observation has occurred yet.


## Ordinary-v2 actual read-only observation

After independent source/schema acceptance and 37 synthetic test passes, root authorized a fresh two-object observation at exact tool `4bfdb5001380a3d7e5db7517033285d49ab211be68e2fcba15964f0ad5b03c53`. Both cases now have complete graph observation and scoped root-closure candidacy with no remaining observer blockers. This is not full serialization or an emitted object. All full-serialization, namespace, provider, ABI, link and runtime flags remain false; the embedded omission subcertificate still grants no materialization/emission approval.

| Case | Proved refinements | Runtime / full retained sections | Retained primary / physical slots |
| --- | --- | --- | ---: |
| Main0576 | 23 omitted local LABELs; one unused plain IAT duplicate2830 | `[199]` / `[1,199]` | 285 / 287 |
| Allocator2734 | Five omitted local LABELs | `[41]` / `[1,41]` | 6 / 8 |

All 28 LABEL proofs include exact actual uses, own-section checks and original interior binding identity. Main's IAT proof includes all three actual group uses, retains680 unchanged, excludes2830 only from this root scope and preserves cell `0x00fdf2fc` / import175 / original USER32 `GetActiveWindow`. It does not choose GetForegroundWindow from the source spelling. Allocator's six weak/fallback records remain decoded outside the root closure; main's 18 SafeSEH registrations remain explicitly accounted outside retained scope. Full physical graphs, directives, original source/producer proofs, all original missing-field baseline metadata and optional-index absence remain unchanged.

The compressed details contain the complete retained primary and auxiliary sets, not just counts or inferred ranges. Canonical hashes of `{retained_section_indices,retained_primary_indices,retained_physical_slots}` are `249220d0fdbc366c6b0a3f16fa82d4b1659331b8b7b7f46e2d1723ebaa21eeeb` for main and `9f77136d59d6bbc68cd6f5554804aedea4c7f9916bc1eaa6689999066f8ffc5a` for allocator. The allocator primary set is `[0,1,2,139,141,142]`, with full slots `[0,1,2,3,139,140,141,142]`.

| Private v2 artifact/certificate | SHA-256 |
| --- | --- |
| Summary | `2273d54cdf913e58c4eb9317bf4f289a71a7e49639ed16a6cf2a317bc37d17b3` |
| Compressed details | `7dda28aafa2e6ae2791827978b319b8844c0d29d70bc1ddf48a29bbdf12973e6` |
| Progress journal | `ec7b9e838a4c96c82a20ab37c00ec881631c332c448efa3dffd63315559e0d15` |
| Canonical main certificate | `9bbbdfe0b590b4919ae773094c9d466d16ff41f38333803d67a69ff1364a3037` |
| Canonical allocator certificate | `1193510d019107038823fcfb61b2728bda8ceb80e0847bad080b2e4db84a4f91` |

Both original objects, sources and all protected input/tool hashes remained stable; no code or operand changed. V1 negative receipts/source snapshots remain intact. This observation does not upgrade the all-size inventory, resolve the retained code-reference group289/1392, or enable an expanded-EH mode. Independent output reconciliation passed; the exact review receipt `root-code-closure-native-v2-independent-review.json` has SHA-256 `dd939a576f89af41c54dd3ca99eb8b37257efe2a3f6cc535211dc495809f007e`. Consumer operations remain subject to their own source/review/root gates. No compiler, link, emission, materialization, native operation or game execution occurred.
