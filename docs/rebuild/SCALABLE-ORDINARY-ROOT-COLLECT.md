# Finite ordinary-root metadata collector

`scalableordinary_root_collect.py` collects a finite explicit set of selected source-code roots under the **unchanged** ordinary observer. It supports serial batches grouped by exact recipe/object, with one original object parse per requested recipe. It produces metadata certificates, not objects, archives, links or executables. It does not change frozen ordinary source `4bfdb5001380a3d7e5db7517033285d49ab211be68e2fcba15964f0ad5b03c53`, existing main/allocator certificates, the separate expanded-EH producer or any writer/provider gate.

A larger request does not automatically make more code eligible. Every root in the hash-bound request is accounted, but each per-recipe **union** must pass the same conservative whole-section, symbol/auxiliary, relocation, name/fallback, SafeSEH, directive, DATA-conversion and original missing/EH rules. Unknown relationships stay blocked. Root-closure observation is separate from serialization, ABI, provider, lifetime and runtime closure.

## Request schema

The request is ordinary JSON with only `schema_version:1`, `kind:'fnv-finite-ordinary-root-request'` and a nonempty finite `roots` list. It has no approval boolean, signatures or new approval framework. The CLI requires the exact request SHA-256. Each root has exactly ten fields:

`original_address`, `recipe_id`, `recipe_index`, `object_sha256`, `source_sha256`, `symbol`, `symbol_index`, `section`, `value`, `size`.

Every field must match the pinned selected owner, authoritative manifest/recipe, complete v3 proof and accepted data-owner provider ledger. The selected address is additionally joined to the exact v3 native section/value row, not merely the symbol/address/size set; agreement between selection, request and provider cannot replace that checked physical location. Physical indices are never guessed from name spelling or address proximity. Duplicate addresses/physical identities, stale indices/spans/hashes, unknown request fields and boolean numeric identities are rejected. The maximum list is the finite selected-address universe; there is no function-size band limit.

The request is an observed caller instruction bound by hash, not an authentication boundary or provider authorization. The root coordinator reviews the exact finite request before a real observation. All runtime/provider/full-serialization flags remain false.

## Complete inputs and grouped observation

The collector reuses the exact seven report pins in the accepted all-size inventory (selection, retained objects/proof, authoritative recipes, final binding, data-owner and EH ledgers), plus original import plan `e39b8db63ef73aea57b5dd4963ff29310524644ca36e137cd8b5461a3c90a23f`. Compressed binding/owner details must match their pinned reports. Reference identity joins across reports are checked; the PE/reference image is never opened.

The complete accepted owner stream is consumed once to verify provider identities and census. The complete saved binding stream is consumed once in recipe order, preserving all 490,713 field references, original88 missing fields/59 affected functions and their sequence identity. This is a saved-metadata pass, not a new scan of all native objects or archives.

Only requested manifest-listed objects are opened. Within each recipe group, selected roots are sorted by native section/value/index/address, a single parse produces the current symbol/section graph, and the frozen `assess_object` sees the entire requested root set. Thus an added root can make a SafeSEH handler, weak fallback, alias or child live and invalidate an earlier smaller-root omission. One-root drop lists are never unioned.

The contract contains every requested parent field and original missing-field row, full same-parent EH evidence, complete unit proof rows, and all unit label/IAT omission proofs needed by the frozen policy. Current source/object/recipe/proof/producer/compiler identities, original reference identity, request hash, import/owner/binding report and detail hashes, tools, exact row ordinals/digests and optional-index absence are retained. Unselected unit EH pieces and diagnostics remain observations in `unit_EH_evidence`; absence of a selected-root error does not certify a frame or helper. The source/proof receipt is observed historical evidence, not proof that the collector compiled anything.

Unsupported strict COFF format receives an explicit blocked group record accounting for every requested root. Wrong object hashes or current native identities fail rather than publishing a stale certificate. No source-placeholder storage, original-address fallback, unknown relocation or speculative provider is introduced.

## Output and stability

The private summary records every requested recipe group, all requested addresses, canonical record/certificate hashes and blockers. Compressed JSONL has one record per requested recipe union, with a bare ordinary certificate nested under `certificate` when parsing succeeds. The complete certificate retains exact physical section/primary/auxiliary sets, all decoded edges/dispositions and original field roles/addends. Format failures carry a structured blocker instead of silently dropping requested owners.

Inputs, requested native objects and source files, reused immutable producer/parser/helpers, and original proof tool modules are hashed before/after. Optional index absence is checked before/after. Every manifest-listed object/source path is reserved against output collisions without opening unrequested objects. Outputs are exclusive; gzip metadata is staged, an fsynced journal preserves progress/failure, and only outputs created by a failing attempt are removed. No existing failure or source artifact is overwritten. After both detail and summary writes, inputs and optional-index absence are checked again; drift removes both newly created outputs and preserves the failure journal.

`collect_group` calls the frozen parser once and the exact frozen assessor once per requested recipe. It contains no namespace rewrite, index remapping, projection, code/data emission, archive write, compiler, linker, DLL load or execution API. Current library flags—including unknown/missing/EH blockers and false namespace/full-serialization/runtime approval—are not weakened for batch convenience.

## First concrete request: source-owned FILE read leaf

The first planned actual request is the original source-backed read leaf below, not a synthetic runtime demo:

| Identity | Exact value |
| --- | --- |
| Selected original entry | `0x00d2bcd0` |
| Recipe | `1821-ead65709d249dd91` / SP1 |
| Source | `src/havok/common/base/system/io/reader/stdio/hkstdiostreamreader.cpp` |
| Source SHA-256 | `43d508c3d5f60166bc76f62a4521692a69ccc68d0273d9314727b42000bd10d0` |
| Original object SHA-256 | `c768b253bc216a32ff93300d2cd488a33c6c726c7aa01d9fb0e230fa7e396e4b` |
| Native entry | Section3/value0/primary8/39bytes |
| Source symbol | `?ReadOrMarkFailed@FUN_00d2bcd0_class@@QAEXPAXI@Z` |
| Saved field | Offset20/primary9/`_fread`, zero-addend original target identity `0x00ecb3a8` |

The saved all-size inventory reports only recipe-wide SafeSEH as its initial writer barrier, with no own-parent EH or original missing field. That report is not a new ordinary certificate; the stricter frozen observer may discover additional blockers. The actual observation must report them honestly.

The source-owned FILE lifecycle context is separately recorded in `entry-crt-link-plan-native-v1.json` (`99e16d2120d7b8249136fde98a78fb2c08f1c268f8cb4d424ab33216dad57082`). Its exact leaf field is binding ordinal384166, row SHA `83415e073df0a14b1829cab56d4e6af6f4bd806ef797491dad668f941c3b3b7c`. It has five source methods, nine fields and three DATA-owner obligations; this request contains only the read leaf. A future `_fread` provider, FILE storage/type/lifetime and the rest of that lifecycle remain separate contracts. No native preparation or provider adoption is authorized here.

A concrete private metadata-only request was prepared from existing saved identities as `fread-ordinary-root-request-v1.json`, SHA `1bddbf8b18461c3383106b3a9d164e9b088625d30955ee27a37a0a91dd67e91e`. No original object was opened to prepare it. Planned fresh outputs are `build/rebuild/fread-ordinary-root-observation-v1.json`, `.jsonl.gz` and `.json.progress.jsonl`. The actual command requires all exact report/detail paths and this request hash. Source/schema review and a separate root go precede the single leaf metadata observation.

## Source checkpoint

Fifteen focused original synthetic tests pass with `python -m unittest discover -s tests/rebuild -p test_scalableordinary_root_collect.py`. They cover complete request identity/provider joins, stale/duplicate/unknown/malformed requests, one parse for a multi-root recipe, recomputation when root union makes a SafeSEH handler live, unchanged field/addend/CRT obligation, missing-field/EH blockers, unselected diagnostics, complete format-failure accounting, source/object/index drift, all-unit omission proofs, protected outputs, dependency mutation, exact retained-proof section/value disagreement and input/index drift induced during summary publication with output cleanup. They execute no original object or native tool.

No real FILE-leaf object observation, broader reachable-set scan, new ordinary rule, emission, link, provider adoption or native operation has occurred at this checkpoint. The first reviewed batch is still one requested root; future finite requests require their own exact input/result review and cannot borrow its certificate.


## First actual leaf result

Root authorized the exact one-root request above at corrected source `e7e5b45df15af0a2bd5cb4a65b36d85ca21eb753656714c0a9a5d8dd919e58ad`, after independent source review and 15 focused test passes. The requested object was parsed once; one recipe/root group was accounted, with complete graph and root-closure observation and no blockers. All protected input/source/object/tool hashes remained stable after publication, and the optional index stayed absent.

The retained sections are `[1,3]`, primary indices `[0,1,2,6,8,9]`, and complete physical slots `[0,1,2,3,6,7,8,9]`. The one SafeSEH registration belongs outside the requested runtime/name closure, and the object has no weak records. Directive section1 remains retained exactly. The only runtime field is REL32 at section3/offset20 to primary9, with zero addend and original base/target `0x00ecb3a8`; it matches ordinal384166 and the saved row hash above.

Its **actual frozen classification is `UNSELECTED_EXECUTABLE_TARGET_UNCLASSIFIED`, canonical role `code`**. The source name `_fread` does not change that role to `crt-contract`, select a provider or prove a function boundary/ABI. A future namespace plan must preserve the original undefined CODE identity; a normal CRT provider requires its own typed boundary and review. No source storage or FILE lifecycle was adopted by this certificate.

| Private artifact | SHA-256 |
| --- | --- |
| Summary | `231a3cd6cc858264dc8d873072519cf5c5b6d551a98f99d935854df3a8e48068` |
| Compressed group details | `cd06640c539276bc6216364453fd086529b66c194fc51a2073643e63d3866738` |
| Progress journal | `75203d71a6f33cd0a07b42555b4e2bccf0a2350860d033b32678c5e36c8a59d6` |
| Canonical outer group record | `57a23a85e203c7ce2cfaf71581ad5f951b3a14aebe6eab75260337180e2ac282` |
| Canonical nested ordinary certificate | `01a1c3c9161a9a035301ce040251937f48d3ebfb74f34f0dee92ab2402f7a7b2` |

The collector's journal records 14.234 seconds after metadata preflight; a near-completion process sample recorded peak working set487,419,904bytes, and all three outputs total13,688bytes. The observation completed within the authorized practical ten-minute/1GiB/100MiB-output envelope. No object/code/data was emitted or executed.

Independent selected/v3/object/field/SafeSEH reconciliation passed, including output and certificate hashes. The CODE obligation remains unresolved. Full serialization, namespace, provider, ABI, link and runtime flags remain false. Frozen ordinary/expanded-EH modules and all older source/results stayed unchanged; this one-root result does not certify the remaining FILE methods or any larger reachable set.
