# Root closure blocker refinement

The preserved ordinary v1 observation correctly blocks both cases. The bounded evidence supports proposing two distinct successor rules: recognize known **unreachable local LABEL records**, and prove the exclusion of one **unused, redundant undefined IAT reference**. Neither rule changes a source, operand, symbol index, original identity or provider. This document authorizes no implementation, new observer run, emission or native operation.

Microsoft's [PE/COFF specification](https://learn.microsoft.com/en-us/windows/win32/debug/pe-format#storage-class) identifies storage class6 as a module-defined code label whose value is a section offset. It separately distinguishes zero-value undefined external references, nonzero-value common symbols and weak externals with fallback auxiliaries. Those format meanings explain the narrow classifications below; they do not establish linkage/provider equivalence for this game.

## Exact evidence scope

Only the 28 storage-class6 records and main's physical records680/2830 were inspected, together with their incoming physical relocations, same-name records, known auxiliary/fallback/SafeSEH/directive uses and saved source-field bindings. The two exact named objects were hash-verified; all further joins use the pinned manifest, v3 proof, final binding and original static-import observations. No directory/archive search or all-object scan occurred. Both current original source hashes still match their producer observations.

The immutable v1 summary/detail hashes are `d3bf0d5148f594384c400485cd25e5377b6bb16408f57a835cfca9d0df90feaa` and `93a5ddce2b4fc8649377ae9be7ad780d9f4a658fb722b0507535762282efa9b1`. They remain blocked; this refinement does not edit or supersede them.

## All 28 LABEL records

Every inspected record has storage6, type0, no auxiliary, positive section number and a value strictly inside its exact `.text` extent. All five owner sections have the reviewed ordinary flags `0x60501020`, complete MATCH spans at value0 and are omitted from the main/allocator selected-root set. Every label has exactly one incoming DIR32 relocation, from its own containing section. All 28 uses are outside retained runtime/directive sections, none is a weak-fallback target or SafeSEH registration, and the exact two default-library directives have no label-root operation.

| Recipe | Containing physical section | Exact checked owner | Extent | Label physical index:section offset |
| --- | ---: | --- | ---: | --- |
| 0576 | 185 | `0x00a234c0` | 268 | 1142:201, 1143:157, 1144:112, 1145:83 |
| 0576 | 195 | `0x00706320` | 661 | 1185:496, 1187:426, 1192:302, 1201:175, 1202:170 |
| 0576 | 258 | `0x00a23390` | 248 | 2523:179, 2525:157, 2527:135, 2530:113, 2531:105, 2532:97, 2533:89, 2534:81, 2535:73, 2536:63 |
| 0576 | 259 | `0x00a238a0` | 308 | 2544:210, 2547:172, 2550:134, 2553:93 |
| 2734 | 141 | `0x00aa1de0` | 295 | 470:176, 471:126, 473:113, 474:89, 475:77 |

All 28 physical fields also join exact final binding rows classified `UNIQUE_CODE_INTERIOR_OR_LOCAL_LABEL_NOT_CALLABLE_APPROVAL`, with `EXACT_OWN_SOURCE_RESOLUTION`, kind6 and zero addend. Each original base/target is the exact proved owner's original start plus that label's physical value. This is interior-label identity, not a separately callable/exportable function. The private evidence retains every binding ordinal/hash and full field identity; no numeric target is inferred from disassembly or appearance alone.

Repeated `$LN...` spellings occur across these omitted sections. In particular class6 index2535 (`$LN13`, section258/value73) shares a spelling with class3 index1146 in section185/value252. The latter is also an auxiliary-free local static record. No matching EXTERNAL/WEAK/common record was found for the inspected label names. These physical labels must never be merged or linked globally by spelling.

### Proposed narrow LABEL rule

Support only storage6/type0/aux0 records with the observed compiler-local `$LN` numeric spelling, a valid positive ordinary CODE section and a value strictly below the exact section extent. The spelling is an additional guard, never the semantic proof. Require complete physical relocation/index/auxiliary/directive/name-resolution accounting and explicit non-export status. Accept exclusion only when the entire containing section is excluded, every incoming relocation is from excluded sections, and no retained/root/alias, weak fallback, SafeSEH entry, recognized implicit linker root or unproved name relationship needs the label.

Each accepted exclusion records the original recipe/object/symbol index, section/value, exact containing owner proof and all incoming-use identities. Same-spelled recognized local records remain separate. Unknown same-name storage semantics or external/weak/common ambiguity remains blocked. No CODE payload or relocation is rewritten; the record disappears only with a proven omitted section.

A label inside a retained section or reached from retained metadata/relocation remains blocked in this first successor rule. Supporting retained class6 labels would require a later explicit local-symbol serialization contract. Class7 undefined labels, nonzero type, auxiliary records, invalid/end/out-of-bounds values, unrecognized section/flags or compiler spelling remain unsupported. This is not a blanket acceptance of storage6 or all `$LN` symbols.

## The two GetForegroundWindow spellings

Both physical records have the same observed fields:

| Field | Index680 | Index2830 |
| --- | --- | --- |
| Name | `__imp__GetForegroundWindow@0` | `__imp__GetForegroundWindow@0` |
| Section/value | 0 / 0 | 0 / 0 |
| Type/storage/aux count | 0 / 2 / 0 | 0 / 2 / 0 |
| Physical relocation uses | section117/+11; retained section199/+2805 | omitted section273/+154 |
| Kind/addend | DIR32 / 0 for both uses | DIR32 / 0 |
| Weak fallback / SafeSEH / directive-root uses | None | None |

They are plain undefined external records. Neither is a weak external, common allocation, storage definition, function body, auxiliary-bearing alias or exported provider. The full physical same-name set is exactly these two records. Current root scope retains680 because main references it;2830's only physical relocation source is omitted section273.

The three saved field proofs independently establish the same original pointer cell:

| Binding ordinal | Checked source owner / field offset | Physical target | Original base = target | Import identity |
| ---: | --- | ---: | --- | ---: |
| 159672 | `0x0086a850` / 2805 | 680 | `0x00fdf2fc` | 175 |
| 161468 | `0x00871d10` / 11 | 680 | `0x00fdf2fc` | 175 |
| 163166 | `0x00a24830` / 154 | 2830 | `0x00fdf2fc` | 175 |

Each is `IAT_POINTER_CELL_NOT_FUNCTION_BODY`, exact own-source resolution and a single physical field with zero DIR32 addend. The basis for their relationship is the complete hash-bound field/slot evidence, not their equal strings or equal-looking operand values. These input hashes and receipt joins are operational evidence, not an authentication boundary or proof that a historical command executed.

Crucially, import175's actual original contract is **USER32.dll, GetActiveWindow**, at this pointer cell. The saved static-import plan lists both `__imp__GetActiveWindow@0` and `__imp__GetForegroundWindow@0` as checked source aliases. Its proposed import-library/signature/runtime-provider approval remains false. The source spelling therefore must not choose a GetForegroundWindow provider or substitute a callable function body. Equal source names alone would conceal this distinction.

### Smallest safe omission proposal

After complete closure for the exact root set, classify2830 as `OMIT_UNREFERENCED_REDUNDANT_UNDEFINED_IAT_RECORD` only when:

1. All records in the exact external-name group are ordinary section0/value0/type0/storage2/aux0 references, with no weak/common/defined/unknown member or hidden name/fallback/directive root.
2. Every physical use of every member is enumerated and joins the same pinned original IAT cell, import ID and pointer-cell role, with exact kind/addend/field evidence. Conflicting or absent evidence fails closed.
3. The omitted member has no relocation, auxiliary, index-table or implicit-root use in the retained set; its physical users all belong to explicitly omitted sections. The retained representative680 and its exact field identity remain unchanged.
4. Canonical namespacing later uses the original pointer-cell identity and role. It does not select an OS export from the source spelling or invent an IAT provider.

This removes an unneeded reference record; it does not merge indices, retarget a relocation, equate definitions, modify weak resolution or create a binary alias. The receipt must retain2830's original physical identity, all omitted uses and the exact cross-record field/slot evidence. Expanding the selected root set to include section273 forces recomputation; the omission certificate cannot be reused. If both records become required, preservation of two physical undefined records under a common canonical identity requires a separately reviewed name-only representation contract.

The selected-code duplicate group289/1392 targeting `0x0043d4d0` is independent. Its two records are both retained by main and cannot be removed by this unused-IAT-record rule. The typed-code identity adapter must prove that group separately. Neither adapter may convert the IAT cell to a code target or use a source name as provider authority.

## Implementation/review contract

The next proposed source change is a narrow successor version of the root observer, retaining v1 and its negative receipts. Add separate recognized-unreachable-label and evidence-bound-redundant-undefined-IAT exclusion rules, plus exact omission reasons and their provenance. Preserve all original indices and future old/new bijection requirements. Keep current unknown-format/global checks, original88 missing fields, EH/SafeSEH, directives, source/producer/index stability and false full-serialization/runtime/provider flags.

Before any new observation, tests should reject reachable labels, bad class/type/aux/value/bounds, unknown code flags, external/weak/common same-name ambiguity, directive and SafeSEH label roots, an IAT member with a weak fallback or definition, missing/conflicting use evidence, different original slot/import ID/role/addend, source-name/provider mismatch, and root-set expansion making2830 live. Positive tests should preserve repeated local LABEL spellings without global aliasing and exclude only the actually unused IAT member. Complete physical-slot/edge/disposition key sets must still reconcile.

Independent source/schema review must precede a fresh two-object metadata v2 run. A positive root-closure result would still be scoped omission evidence, not successful emission or full serialization. Main remains subject to its separate code-reference identity adapter and downstream archive conformance gates. No source rewrite, policy implementation, new root-observer certificate, compiler, link, DLL load, materialization or execution occurred during this refinement.

## Evidence identities

Private evidence `root-closure-blocker-refinement-evidence-v3.json` has SHA-256 `23613b8ac464a606f6ffff667fa118f5df401bbbe2d28a9e3fbe63bedd674d48`. Earlier bounded evidence files remain preserved. The final artifact includes all 28 records and their use sets, the two exact import records, 28 label binding rows, all three IAT binding rows, complete import175 observation and input hashes. Original objects and current source hashes remain exactly those in the accepted root proposal and v1 certificate provenance.

| Input | SHA-256 |
| --- | --- |
| Binding summary | `275714631903758efbf5a4f82e2428c6f51838f53b90d0c56d2e5dec5da1d804` |
| Binding detail | `4dfc437064b16c1bb933008aebf7def8d279a903eef9cca24d0fedcc12d7d826` |
| Original import plan | `e39b8db63ef73aea57b5dd4963ff29310524644ca36e137cd8b5461a3c90a23f` |
| Retained proof v3 | `04d44b73e81982f846bfe8d81806db72ea669586b579ff22007dfd6f7d831297` |
| Producer manifest | `bc62a5fb2553431b1e0547d11f366e52efb73096ea8ceb206c556ae5740a53eb` |

The tracked document contains metadata only, with no original bytes, disassembly or private absolute paths. Existing code, policy, source, frame/native outcomes and v1 receipts remain frozen.
