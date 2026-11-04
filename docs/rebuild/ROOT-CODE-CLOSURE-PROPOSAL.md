# Selected-root CODE closure proposal

This proposes a separately reviewed extension to the unresolved CODE pool. It may remove a recipe-wide weak/common/SafeSEH blocker only after proving that the exact omitted records are outside the selected root set's physical and implicit-linker closure. It grants no emission, provider, link, ABI, initialization, runtime or game-execution approval. Existing writer, inventory, objects, source and receipts remain unchanged.

The intended product is an unresolved object/archive of explicitly selected source-code providers, not a semantically complete reproduction of each original translation unit. Excluded definitions and source initializers must remain an explicit exclusion ledger. Their omission cannot later be described as faithful startup behavior.

## Current evidence and realistic payoff

The accepted full inventory contains 68,657 selected owners: 16,859 serialization candidates and 51,798 blocked. Its primary recipe-wide category contains 40,176 owners. Nonexclusive reasons include 39,435 weak/common observations, 39,435 unsupported-auxiliary observations and 39,189 SafeSEH observations. These are conservative serialization-policy barriers, not proof that those game functions are missing or incorrect.

A reason-set census of that saved metadata identifies **22,590 owners in 980 recipes** whose complete current blocker sets contain only SafeSEH, weak/common and unsupported auxiliaries:

| Saved reason set | Owners |
| --- | ---: |
| SafeSEH + weak/common + auxiliary | 13,799 |
| SafeSEH only | 3,751 |
| Weak/common + auxiliary | 5,040 |

Those owners span 19,998 at 1-255 bytes, 1,613 at 256-511 bytes and 979 at 512+ bytes. This is an investigation population, not a promised unlock count. Unsupported auxiliaries need not all be weak records; a reachable or undecodable case still blocks. Other owners may retain a second independent barrier even after recipe-wide scope is proved.

This planning used the exact saved inventory/detail and two named objects only: allocator recipe `2734-15835374a1b91660` and application-entry recipe `0576-dd603b7071c482c6`. No new full object scan or archive enumeration occurred. The current producer's narrow dependency-pin correction changed its source hash; historical inventory behavior remains bound to the exact saved assessor source at `06f373e8592571244b8e70c913a037812a73c856bc8e42b5b2c9b509b732ed81`. It is not claimed to equal the current working-file hash.

## Named physical samples

| Identity | Application entry | Allocator |
| --- | --- | --- |
| Original address | `0x0086a850` | `0x00aa13e0` |
| Recipe | `0576-dd603b7071c482c6` | `2734-15835374a1b91660` |
| Relative source | `src/fallout/misc/main.cpp` | `src/staging/blk_00aa0000_o2.cpp` |
| Physical selected symbol | 1215 | 141 |
| Physical CODE section | 199 | 41 |
| Checked / whole section bytes | 4,532 / 4,532 | 62 / 62 |
| Relocations | 442 | 1 |
| Root COMDAT selection | 1 | 1 |
| Root parent EH pieces / missing fields | 0 / 0 | 0 / 0 |
| Current independent barriers | SafeSEH; canonical collision | Six weak records and their auxiliaries |

Both roots have exact whole-section extent, external function identity at value zero, and ordinary source-code flags. Both directive sections contain exactly the same two default-library directives, in observed order, with no directive relocations. These observations alone do not establish closure.

Allocator 2734 has six weak records at physical indices 124, 332, 366, 398, 430 and 541. Their fallback indices are respectively 123, 331, 365, 397, 429 and 540; their observed search characteristic is 2. There are no common symbols or SafeSEH registrations. Its root has one DIR32 at offset 23 to undefined data symbol index 142. Its known associative child is section 42, a 16-byte `.debug$F` section with a DIR32NB reference to root symbol 141. Neither root nor that child references a weak record. This makes it a useful omission-proof candidate; it does **not** make the allocator eligible in this proposal. A future implementation must prove all symbol/auxiliary/directive edges and final drop receipt, retain the original data identity and addend, and pass serialization validation.

Application entry has no weak/common/unknown auxiliary records, no associative children under section 199, no same-parent v3 EH pieces and no original missing relocation. Its recipe's 76 other EH piece observations do not belong to this entry and do not certify its ABI. The `.sxdata` section 9 contains 18 symbol-index registrations. Every registered handler belongs to another section, and no entry relocation directly references one of those registered symbol indices. The proposed complete closure check still has to show no retained child, implicit root or hidden index brings one back; absence of a direct relocation alone is insufficient.

The entry also has a **separate canonical-name collision**. Physical undefined external function records 289 and 1392 both refer to selected original code identity `0x0043d4d0`, with value zero and no auxiliary. Seven zero-addend REL32 fields use 289 (offsets 268, 301, 316, 1015, 1030, 2253 and 3835); one uses 1392 (offset 1278). The different source spellings are not the proof. Exact per-field binding rows establish the same selected provider/base and target. Current policy rejects duplicate canonical names, so SafeSEH omission alone cannot unlock main. No new provider or binary alias has been adopted.

## Root-set graph and omission certificate

A new pure observer should take a **set** of selected roots in one exact object, not apply independent one-root drop lists and then union them. Its inputs include the authoritative recipe/manifest/source hash, original object hash, full v3 proof, all selected physical identities, final per-field binding rows, original missing-field rows, EH observations and an explicit export policy. A root-set identity includes its sorted physical section/symbol identities and complete input hashes.

Construct and validate the full object's metadata graph once. Nodes include sections, primary symbols, auxiliary slots, symbol-index tables, directive operations and selected original identities. Decode known edges from relocations, section association parents and children, weak fallbacks, auxiliary tag/next/line references where supported, SafeSEH index entries and linker directives. Validate every index against the primary/auxiliary slot distinction and every range against its real extent. An unknown auxiliary with potentially hidden indices is a global undecodable-closure blocker; it cannot be dismissed just because no ordinary relocation points at it.

Use three explicit sets:

- **Retained runtime closure:** complete selected sections, their supported required runtime children, all symbols/auxiliaries needed to represent them, and every relocation's physical target record. Calls to omitted source-code/data definitions may become canonical undefined obligations only through the existing exact binding contract; that does not recursively adopt their sections or providers.
- **Proven debug exclusions:** recognized debug-only associations satisfying the existing narrow exclusion contract, with complete physical identities and their index-bearing fields accounted. A debug name alone does not authorize omission.
- **Omitted records:** every other section/symbol/auxiliary/table record, each with an explicit reason and decoded outgoing edges. There must be no implicit linker root or unhandled dependency that requires it. Every original section and symbol/auxiliary slot must be retained, excluded by a recognized rule, converted through an exact approved undefined contract, or blocked; none disappears from accounting.

Associations require both directions: a retained associative child requires its parent, and a retained parent requires examining every child. Unknown/non-debug/EH children remain blocked unless a separate same-parent adapter proves their full closure. Do not truncate a shared section, infer ownership by proximity, drop an unverified helper in a retained section, or create filler/tombstone records. Root scope is not permission to ignore malformed metadata elsewhere in the object.

The certificate should contain decoded-edge counts/digests, retained and omitted physical indices, reason-coded omission rows, implicit-root resolution, original-to-new provenance obligations and all blockers. Its completeness key sets must equal the entire parsed metadata universe. A final original-object rehash and source/proof stability check must pass. Policy approval is an operational reviewer claim, not authentication.

## Weak/common records

Initially decode only exact reviewed forms. For the observed weak form require storage class 105, the expected undefined section/value/type contract, one auxiliary, a valid primary fallback index, recognized search characteristic and known reserved fields. Record its fallback edge even when the whole weak record is omitted. Do not claim to implement weak resolution semantics merely by decoding the structure.

Omit a weak record only if it is not a selected export, not referenced by a retained relocation, retained auxiliary, index table or directive, and not reached through another live fallback chain. Its entire auxiliary must be omitted with it. A selected or reachable weak record/fallback remains `REACHABLE_WEAK_REQUIRES_POLICY`; do not convert it to an ordinary extern, pick its fallback or change search characteristics. Cycles, malformed tags, unknown reserved values or auxiliary index semantics remain blockers.

A common symbol is a different case. Its nonzero undefined value records tentative storage size, not an approved provider or a source object's full semantic extent. An unrelated, fully decoded common record may be excluded from this selected CODE product under the explicit non-export policy. A selected/reachable common must remain blocked pending a storage/initialization owner; it cannot silently become zero storage or an undefined four-byte stand-in. This proposal has no actual common-symbol sample and proves no common removal eligible.

## SafeSEH and compiler metadata

Treat `.sxdata` as an index-bearing table even when it has no relocations. Validate its actual extent, flags, complete entry boundaries, primary symbol indices, target section/value and any auxiliary/association relationships. Record all entries; malformed or unknown table layout blocks the object.

For the first extension, omission of the **whole** SafeSEH table is permitted only when no registration targets a retained root or retained runtime child, no retained record depends on the table, and no implicit root requires one of its handlers. Every registered handler must be among explicitly omitted sections/definitions. Incoming edges from an omitted table do not by themselves make every handler live: otherwise no scoped omission would be possible. Their omission is valid only under the selected-export artifact contract and complete edge accounting.

If the root itself, an entry inside its retained section, or any retained runtime child appears in the table, retain a blocker requiring the EH/SafeSEH closure adapter. A handler name pattern or the fact that the main symbol differs from the registered symbol cannot waive this check. Do not strip individual entries, synthesize a filtered table, clear table flags, replace indices by addresses or redirect a handler to a normal function body in this first extension. Mixed live/omitted tables remain blocked until a separately reviewed table-preservation/remapping contract exists.

Preserve actual absolute compiler metadata. `@feat.00` compatibility cannot be inferred from a desired outcome: preserve the reviewed observed value 1 only within its supported contract; other values remain unsupported. Do not clear SafeSEH bits to force linking or fabricate metadata because the output dropped a table. Preserve actual `@comp.id` value. Native conformance of an artifact without a SafeSEH table is a later independent gate, not established by this graph proof.

## Directives, implicit roots and excluded exports

Retain exact `.drectve` bytes, order and flags; the first extension still accepts only the already reviewed two-default-library contract. Default libraries are unresolved linker dependencies, not permission to select their runtime providers. Unknown directives remain global blockers because `/INCLUDE`, `/EXPORT`, `/ENTRY`, `/ALTERNATENAME`, merge/section options, symbol decoration and other operations can introduce roots or change ownership without a relocation. A future directive decoder must resolve every name to exact physical identities or explicitly reject ambiguous spellings; it cannot discard directives as unrelated text.

The archive export set is exactly the approved selected provider definitions, using their immutable recipe/object/original-symbol identities. Excluded source definitions, weak aliases, tentative globals, initializer tables, TLS/IAT/loader cells and helper exports must not leak into a member's public archive index. Selected functions' references to source-global placeholders remain canonical undefined obligations where already proved; they never retain generated placeholder storage. Source `.CRT$XCU` slots and initializers are excluded obligations, not silently adopted startup behavior. An explicit dependency of the selected root on such semantics still prevents runtime closure.

The graph records ordinary outgoing calls and data references separately from roots introduced by object metadata. It does not need to close the entire application call graph to create an unresolved CODE product. It must close the **serialization semantics** of every retained or removed index-bearing record. Resources/RVAs, cross-domain arithmetic, IAT pointer/body role, CRT state and TLS ownership retain their existing independent gates.

## Main-entry identity adapter remains separate

A narrowly proposed follow-on can allow two **undefined** physical records to share one canonical selected-provider name only when all their retained per-field references independently prove the exact same provider identity, original base/target role and compatible addend semantics. Both original physical indices must remain distinct in the name-only phase; later extraction must preserve a verified old/new bijection. No symbol-index coalescing or relocation retargeting is required or authorized by this proposal.

This would address main's indices 289/1392 without aliasing by spelling, bytes or numerical proximity. It must reject a definition in the equivalence class, differing provider/base/role, IAT/body confusion, incompatible addends or any unbound use. Before actual emission, original synthetic COFF tests and independent archive/native-tool conformance must establish that the chosen duplicate-undefined representation is valid. Until that separate contract is reviewed, main remains blocked even if its SafeSEH drop certificate passes. Existing collision protections are not weakened here.

## Concrete next implementation contract

Implement a new read-only `root_code_closure` observer and synthetic tests before modifying a writer. Its only positive result is `ROOT_SERIALIZATION_CLOSURE_OBSERVED`, with no emission/runtime/ABI/provider flags. Keep the old all-size inventory and writer policy unchanged and name the new policy independently. The first bounded actual observation should contain allocator 2734 and entry 0576, with negative roots whose own/retained-child handler is registered, plus original synthetic metadata; no new all-object pass is needed to validate the design.

Required tests include unreachable versus reachable weak fallback chains, malformed/opaque auxiliary indices, weak/common selected exports, weak cycles, retained-child associations, root and child SafeSEH registrations, unrelated/mixed/invalid SafeSEH tables, hidden directive roots, changed directive order or extra operation, unsupported `@feat.00`, common size versus provider extent, shared/partially checked CODE sections, wrong source/object/proof identities, the original 88 missing fields and failed parent-EH pieces, and a root-set union that makes a previously omitted handler live. Every omission needs a stable original physical identity and reason; counts must reconcile exactly.

Then independently review the observer and its two exact observation receipts. A separately authorized writer adapter can consume only accepted certificates, apply the existing verified index-remapping serializer, preserve every retained payload/addend/flag/association and exact undefined target role, and prove no omitted definitions are exported. Review the main-only duplicate-undefined adapter independently if entry inclusion is a priority. Fresh before/after unchanged-comparator receipts and independent serialized-object/archive validation remain mandatory; a matched ordinary body does not prove EH/frame or runtime closure.

Only after bounded acceptance should a new metadata-only all-size census measure actual unlocks. It must account for all 68,657 owners, keep all 88 missing fields and original EH evidence, and compare candidate/blocker changes against the exact old inventory. The present 22,590 reason-only population is not that measurement. Full source-linked runtime integration remains a later task with CRT/TLS/data/EH providers and application lifetime closed explicitly.

## Evidence identities and recovery

| Evidence | SHA-256 |
| --- | --- |
| Full inventory summary | `02a77cce3f43c1786cd027e72ffb17e76ffe6766c2823872254015b6e40549f6` |
| Full inventory detail | `91cdc91af6530e6e80e2104cdfeb9bd6928e17fa0f75bcf066734985248f1031` |
| Retained manifest | `bc62a5fb2553431b1e0547d11f366e52efb73096ea8ceb206c556ae5740a53eb` |
| Retained proof v3 | `04d44b73e81982f846bfe8d81806db72ea669586b579ff22007dfd6f7d831297` |
| Selection v2 | `48ae62cdc5b1754b9c4af674ef4716d53afb554882e174a93acf860eaf1c6cb1` |
| Final binding v2 summary | `275714631903758efbf5a4f82e2428c6f51838f53b90d0c56d2e5dec5da1d804` |
| Final binding v2 detail | `4dfc437064b16c1bb933008aebf7def8d279a903eef9cca24d0fedcc12d7d826` |
| Exact bounded object/physical evidence v2 | `5413edffdcc4bb322511a6ff9c928e9d48222fd91349a08fd19fa009a7afe7b3` |
| Saved reason-only census | `3ae8bc3ea74639e08cd19bc04bc5026c8379f75521500edb166cfdcffb7efd88` |
| Allocator object | `10c9d726dbf44ac2258f10eecf1f3bbbeef95df9759de18d585756873643c1c1` |
| Allocator source | `01663b0100edd275dbfdc48bbf198ecb71593e48c7d400ff33cda9e2cf5d90bf` |
| Entry object | `a6c310961921f70eea2c70b9c18dba3d85ac19bffdfe3164922e9c3462ab425b` |
| Entry source | `89d09f8b4ba6d9758fca0ac3ebd32e18c9cc82c68a739c044457ed5c005ae3c5` |

Bounded evidence/census and progress notes are saved under ignored rebuild output. Both exact named object and current source hashes were rechecked against the producer manifest. The parser used was `76244d2d4dca4c1f8aa72224be1ef5c92f68976b5cda7d31b5cfe23d3cc29e64`; the saved historical assessor has the exact inventory-bound hash noted above. The private observation helper's initial optional-field and syntax failures are preserved; corrected bounded observations did not weaken any proof or serialization gate. No original bytes, disassembly or personal paths appear here. No existing source/tool, object or receipt was edited, and no materialization, compiler, linker or execution was invoked.
