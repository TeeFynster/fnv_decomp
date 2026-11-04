# Canonical address candidate plan

`tools/rebuild/canonical_plan.py` builds an auditable candidate graph from retained COFF objects and each recipe's own original-address metadata. It does not rename symbols, select variants, rewrite objects, link, or establish ABI compatibility. Every candidate remains `UNSELECTED`, with `abi_verified: false` and no selected provider. Preserve the reference oracle and read [LINK-INVENTORY.md](LINK-INVENTORY.md), [BUILD.md](BUILD.md), the repository README and LICENSE.

```powershell
python tools/rebuild/canonical_plan.py --recipes build/units.json --manifest build/rebuild/objects.json --inventory build/rebuild/link-inventory-compact-v2.json --out build/rebuild/canonical-plan-new.json --candidate-gzip build/rebuild/canonical-candidates-new.ndjson.gz
```

Outputs must be new, distinct paths. Existing evidence and all supplied input/object paths are protected. A failed new gzip stream is removed. The aggregate report contains capped examples with truncation flags; the optional gzip NDJSON contains complete per-address candidate groups, without per-relocation duplication. No game image is read. Detailed reports remain private and ignored.

To consume an actual retained-object verification receipt, add `--verification <receipt.json> --verification-sha256 <expected-receipt-sha256>`. The explicit digest pins the immutable receipt being reviewed. Without this option the plan retains candidate-only behavior and byte-checked coverage remains zero.

## Evidence checks and scope

The tool independently verifies the authoritative recipe fingerprint, exact recipe index set, canonical recipe IDs, full recipe contents and compiler/source fields. It checks the inventory's header against both recipe and retained-manifest fingerprints and requires independently reconciled complete coverage. It streams a SHA-256 over the inventory file, reads at most 64 KiB of its generated provenance header, and never loads its detailed graph. Reordered/oversized provenance fails rather than triggering an unbounded parse.

Every retained object hash is verified, and each native object is freshly parsed one at a time. A second pass rechecks hashes before classifying uses. Original addresses come only from that object's own recipe functions, folded aliases and symbol map; another unit's name-to-address map is never borrowed. Actual definition section flags establish code/data candidates. Section names/flags, TLS distinctions, COMDAT policy, direct associative child counts and whole-object versus section closure warnings remain attached to candidates.

External and genuinely mapped static definitions can supply address identity candidates. Static providers explicitly say `object_local_requires_explicit_remap`; they do not satisfy an external linker name today. Ordinary local section labels without their own address evidence do not become providers. Function entries and exact-address static definitions are important: excluding static functions would falsely suggest that thousands of original functions have no body.

Undefined uses distinguish function declarations, data views, IAT pointer slots, TLS mechanisms, absent/ambiguous own bindings and data-typed references to code addresses with unknown ABI. A code-backed symbol named like an import pointer is not accepted as IAT storage. Data-typed callback/code addresses remain explicit `code_address_view_abi_unknown` candidates. `__tls_array` bound to `0x2c` is a TLS mechanism, not an image address. Typed TLS data views require TLS review. Names already externally defined are separately checked for address contradictions or multiple original addresses; they are not silently certified by name presence.

An address match does not prove calling convention, return type, object layout, storage size, initializer/lifetime, import DLL/export identity, COMDAT liveness or a safe canonical alias. Multiple providers can include duplicate recipe variants and separately named views of one implementation. All remain unselected. The plan preserves same-name/different-address cases, including the two `BloodSplatterBeamShader::CreateShader` implementations. It does not collapse them by decorated name.

Code providers also carry a separate reference selection basis. `SELECTED_RECIPE_FUNCTION` means the actual defined symbol has exactly the name/address selected in this recipe. `SAME_OBJECT_SELECTED_FUNCTION_ALIAS` additionally requires the same native section and offset as that selected entry. `METADATA_BOUND_UNVERIFIED_BODY` means only that a separately compiled body has its own metadata binding; inline/template copies can differ under other flags, declarations or macros. Missing/ambiguous actual selected symbols fail rather than falling back to another name at the same address.

None of these labels alone claims the retained object was byte-checked. The earlier oracle run rebuilt its own objects; its results are association evidence, not a hash-bound receipt for these retained artifacts. Without a validated retained receipt, byte status remains `NO_HASH_BOUND_ORACLE_RECEIPT_FOR_THIS_OBJECT` and checked coverage is zero. With a valid receipt, only exact selected entries gain `hash_bound_function_byte_verified: true` and their precise native span; a same-object alias can inherit identity only when it is at that entry and the entire native section is exactly the verified span, with no additional function entries. Metadata-only extra bodies require their own comparison and never inherit a selected function's result merely by address.

Receipt consumption validates the schema, exact full authoritative recipe/unit scope, recipe and retained-manifest hashes, every actual object hash, source-file observations, current unchanged comparator/span/image-gate/verifier tool hashes, function-index presence/hash, per-unit recipe hash and complete selected-function records. Each record must match the recipe's symbol/address/size and the actual native symbol's section/offset. Counts-only receipts, another function's proof, partial coverage, stale inputs and wrong native entries fail closed. Receipt/current-input observations are evidence of the recorded run; hashes do not cryptographically prove execution or source/compiler causality.

Function-byte verification, ABI, COMDAT selection, strict local EH diagnostics, global listed-EH coverage and runtime closure remain separate. **Every candidate still has `eligible_for_selection: false`, `abi_verified: false`, `runtime_closure_verified: false` and `selection_state: UNSELECTED`, even after its bytes are verified.** The ten repeated-address recipe choices are not automatically resolved. A receipt with passing original function/global-EH gates and nonzero local EH diagnostics can establish the selected function-byte scope; those diagnostics remain visible and do not become a claim of local EH closure.

## Native full-plan evidence

The current private report is `build/rebuild/canonical-plan-byte-verified.json`, with complete candidate groups in `build/rebuild/canonical-candidates-byte-verified.ndjson.gz`. It consumes `build/rebuild/retained-verify-full-v3.json`; earlier candidate-only reports remain separate historical evidence. All 2,988 retained recipes were verified and reparsed. The recipe contains 68,667 function entries at **68,657 distinct addresses**; the ten repeated entries are retained.

| Distinct manifest function addresses | Count |
|---|---:|
| One actual code provider candidate | 66,798 |
| Multiple unselected actual code provider candidates | 1,859 |
| No actual code provider candidate | 0 |
| Candidates confined to one recipe, possibly multiple aliases | 67,436 |
| Candidates from multiple unselected recipes | 1,221 |

This establishes body candidates for every ordinary manifest function identity, not a single chosen runtime implementation. Selection still has to distinguish aliases, recipes and whole-object extras. The ordinary function address set excludes generated EH/CRT/thunk code that may be the target of data references.

The broad code-provider table includes 10,455 metadata-bound **unverified extra bodies**, alongside 68,667 explicitly recipe-selected bodies. Restricting the identity table to explicit recipe-selected entries or proven same-object aliases leaves 68,647 function addresses with one selected-basis candidate and ten with multiple unselected candidates, with zero absent. The validated v3 receipt now supplies selected-function byte evidence for **68,667 provider rows at all 68,657 distinct manifest function addresses**. All 10,455 extra bodies and 28,123 data/TLS view provider occurrences remain unverified. No automatic variant selection or runtime eligibility follows.

The receipt preserves passing global coverage of all 1,954 listed EH tails with zero inference conflicts and original-oracle parity. It also preserves **95 local EH diagnostics across 16 units**, `strict_local_eh_diagnostics_pass: false` and `runtime_closure_verified: false`. The plan carries these counts, unit examples and provider-local diagnostic counts. A globally covered original EH address does not certify a chosen provider's local EH graph or section extraction.

The full raw-name inventory contained 174,649 undefined names without identically named external definitions. Address planning partitions those names as follows; a name can have multiple occurrences with different own bindings, so counts concern all of its uses rather than only its best occurrence.

| Raw-name disposition | Names |
|---|---:|
| Every own-bound occurrence has an address provider candidate | 121,590 |
| Some occurrences have candidates; others still require review | 4,694 |
| No compatible address provider candidate from the supplied own bindings | 37,515 |
| Library support or own binding absent for every occurrence | 10,561 |
| Authentic IAT import provider required | 288 |
| TLS mechanism mixed with absent own bindings | 1 |

There are 144,918 candidate-covered use occurrences: 126,227 function uses, 17,798 ordinary data views, 441 TLS data views and 452 code-address views with unknown ABI. None is an automatically linkable alias. A total of 21,282 raw names have at least one occurrence with absent own address metadata. Names already present have 28 use occurrences whose own address is absent from the named provider's address set and six whose named provider has multiple original addresses; these remain explicit conflicts.

The remaining non-code cases prominently include `type_info` vtable storage (9,670 relocations), the security cookie (8,584), `__tls_index` (1,768), the Havok TLS slot at `0x0126835c` (509), and `NiFixedString` empty-string storage (485). CRT code support includes security checks, `atexit`, C++ EH, dynamic casts and floating-point conversions. Imports require real import providers and IAT indirection. Equal numeric addresses cannot turn an IAT slot into the callee function.

The plan deliberately consumes **no reference-check inferred EH bindings**. The separate native baseline reports 525 EH tails matched with 1,001 inferred names and zero inference conflicts. Those names are not new canonical providers or evidence of missing bodies. Missing original metadata, generated EH/CRT targets and code pointers outside ordinary function spans need separate provenance and closure work; a flat data image's code pointers cannot all be remapped using only the 68,657 ordinary function identities.

The initial full candidate run took 17.334 seconds, with peak process memory 460,283,904 bytes. Its aggregate was 633,958 bytes; complete compressed candidates were approximately 2.6 MB. Later reviewed reports add per-provider selection-basis evidence; their measured timing and peak memory are recorded in each private aggregate. Memory retains recipes and compact name/address indexes plus one parsed object, rather than the full inventory graph. Measurements are machine-specific.

The receipt-bound run took 33.585 seconds, with peak process memory 564,830,208 bytes. Its aggregate was 950,614 bytes and complete compressed candidates were 3,872,824 bytes. The optional verification receipt is loaded as compact per-function records; the detailed inventory graph remains unread.

## Next reviewed slice proposal

Start with a self-contained leaf such as original `0x00be0b90` from recipe 0 (`NiRenderedTexture.cpp`): its source reads the integer field at offset `0x30`; the actual retained object has that selected symbol at section 13 offset zero, a four-byte `.text` COMDAT `no_duplicates`, and zero section relocations. A future approved extractor should retain exactly the chosen COMDAT, its primary symbol/auxiliary metadata, required associative closure and directive/runtime policy. It must reject shared sections, extra public definitions or unexpected references. A normal C++ harness can provide a correctly sized test object and call the leaf using the reviewed x86 member-call ABI. Link a genuine selected game-source code section with real toolchain libraries, then verify the harness result and retained code/relocation identity. This avoids introducing fake game providers just to reach a first link. First bind an actual retained-object byte-check receipt; reference selection alone is insufficient.

That first smoke is a mechanics test, not startup. The allocator at original `0x00aa13e0` is a useful next ABI-reviewed slice: the runtime audit independently established its 62-byte body, a sole data reference to `0x011f6080`, unchanged EAX after its virtual dispatch, and a consumer that uses EAX as the allocated pointer. Its source-level void signature therefore must not drive a global prototype rewrite. It still needs authentic heap storage/initialization and reviewed COMDAT/associative closure before a standalone link; a fabricated zero heap global would not be a safe smoke.

For startup, preserve `.CRT$XCU` roots, initializer dependencies, TLS mechanisms, shared `.sxdata`/EH tables and the actual C++-decorated WinAPI IAT references. The runtime audit identified `GetCommandLineW` and `CommandLineToArgvW` import-slot cases whose prospective aliases require authentic DLL/export evidence and pointer indirection. Do not perform a global address-based rename pass or pull entire overlapping recipe objects merely because a function candidate was found.

## Checks

```powershell
python -m unittest discover -s tests/rebuild -p test_canonical_plan.py -v
python -m unittest discover -s tests/rebuild -p test_coff_inventory.py -v
```

Synthetic tests exercise no cross-unit borrowing, same-address/different-name candidates, local provider visibility, same-name/different-address conflicts, unselected variants, IAT/code separation, TLS pseudo-bindings, data/code ABI uncertainty, stale evidence, bounded header failure and preservation of prior output on failure. They do not substitute for native matching or prove runtime safety.
