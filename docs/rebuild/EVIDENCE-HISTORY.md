# Rebuild evidence history

These are the prior shared guide, roadmap and work ledger, preserved at the documentation reorganization. Their status statements describe the time they were written; consult the current [guide](README.md), [roadmap](ROADMAP.md) and [work ledger](AGENT-WORK.md) for current assignments and gates. Phase documents and private receipts remain authoritative for their own evidence.

---

## Archived README.md

# Rebuild guide

This work is developing a separate source-built runtime. The current repository is a byte-matching reference, not a runnable game. A private-machine retained-object build has compiled all 2,988 recipe entries; full inventory has reconciled all entries and the independent full reference comparison passed on separately compiled temporary objects. Direct retained-object verification reports original parity across 68,667 recipe rows and 1,954 EH entries, with 95 local EH notes; strict local EH and runtime closure remain false. One four-byte game leaf ran 7,168 calls across seven values; link and game runtime gates remain open.

Start with the root [README](../../README.md) for the existing matching workflow, compiler versions and owned input requirements, and read [LICENSE](../../LICENSE). Then use these documents:

- [Roadmap](ROADMAP.md): milestone order and evidence required.
- [Build and toolchain](BUILD.md): native compiler setup, retained-object build, reports and separate original comparison.
- [COFF link inventory](LINK-INVENTORY.md): inventory of private objects and interpretation limits.
- [Canonical candidate plan](CANONICAL-PLAN.md): unselected address-provider candidates and evidence boundaries.
- [Data strategy](DATA-STRATEGY.md), [data coverage plan](DATA-PLAN.md) and [runtime gaps](RUNTIME-GAPS.md): persistent-data evidence and unresolved fixups.
- [Generated code gaps](GENERATED-CODE-GAPS.md): bounded metadata reconciliation and unresolved generated-code ownership.
- [Binding fixture](BINDING-FIXTURE.md): reviewed original symbol-binding mechanism, not game mappings.
- [Relocation audit](RELOCATION-AUDIT.md) and [absolute-address triage](ABSOLUTE-ADDRESS-TRIAGE.md): field geometry and unresolved missing fields.
- [Runtime binding plan](RUNTIME-BIND-PLAN.md) and [source overlay pilot](SOURCE-OVERLAY.md): read-only identities and one compile-only relocation experiment, with no provider approval.
- [Game component candidate](GAME-COMPONENT-CANDIDATE.md) and [scalar component](GAME-SCALAR-COMPONENT.md): one bounded source-built scalar execution and its limits.
- [TLS owner proposal](TLS-OWNER-PROPOSAL.md), [original TLS fixture](TLS-OWNER-FIXTURE.md) and [CRT integration proposal](CRT-INTEGRATION-PROPOSAL.md): reviewed evidence, without game provider or runtime approval.
- [Runtime data owner proposal](RUNTIME-DATA-OWNER-PROPOSAL.md) and [data-owner ledger](RUNTIME-DATA-OWNERS.md): reconciled metadata, without materialization or fixup approval.
- [EH diagnostic triage](EH-DIAGNOSTIC-TRIAGE.md): local diagnostic evidence and remaining uncertainty.
- [EH closure pilot](EH-CLOSURE-PILOT.md): one bounded constructor and compiler-generated EH graph, with remaining dependencies.
- [Function selection](FUNCTION-SELECTION.md) and [import plan](IMPORT-PLAN.md): reviewed ownership choices and import metadata, without runtime approval.
- [CRT provider contract](CRT-PROVIDER.md) and [original data fixture](DATA-FIXTURE.md): reviewed bounded experiments, not game provider or data adoption.
- [EH ownership](EH-OWNERSHIP.md): hash-bound metadata observations and unresolved alternatives.
- [Original EH fixture probe](EH-FIXTURE-PROBE.md): independently reviewed fixture execution, not game EH closure.
- [CRT bootstrap contract](CRT-BOOTSTRAP-CONTRACT.md), [EH type overlay](EH-TYPE-OVERLAY.md) and [game TLS component](GAME-TLS-COMPONENT.md): bounded reviewed experiments, not game startup.
- [Runtime code pool](RUNTIME-CODE-POOL.md), [pool proposal](RUNTIME-CODE-POOL-PROPOSAL.md) and [inventory](RUNTIME-CODE-INVENTORY.md): bounded archive serialization and all-size assessments, not runtime readiness.
- [Runtime audit](RUNTIME-AUDIT.md): startup, ABI and runtime findings and unknowns.
- [Startup closure](STARTUP-CLOSURE.md): evidence and remaining startup blockers.
- [Narrow COFF rewrite](COFF-REWRITE.md) and [extraction](COFF-EXTRACT.md): constrained object-copy operations and validation limits.
- [Game leaf probe](GAME-LEAF-PROBE.md): one independently reviewed leaf experiment, not gameplay.
- [Retained-object verification](RETAINED-VERIFY.md): direct checks and strict diagnostic status.
- [Standalone CRT/TLS probe](RUNTIME-PROBE.md): independent synthetic runtime test, not game startup.
- [Standalone import alias probe](IMPORT-PROBE.md): independent linker mechanism test, not game ABI validation.
- [Validation](VALIDATION.md): acceptance gates and isolation.
- [Work ledger](AGENT-WORK.md): ownership, current evidence and next gates.

On Windows, after configuring the private compiler roots described in [BUILD.md](BUILD.md), the basic commands are:

```powershell
python tools/rebuild/toolchain.py --out build/rebuild/doctor.json
python tools/rebuild/recipe_audit.py --out build/rebuild/recipe-audit
python tools/rebuild/build_objects.py --jobs 2 --output build/rebuild
python tools/rebuild/coff_inventory.py --manifest build/rebuild/objects.json --out build/rebuild/link-inventory.json --recipes build/units.json --require-full
python tools/rebuild/canonical_plan.py --recipes build/units.json --manifest build/rebuild/objects.json --inventory build/rebuild/link-inventory.json --out build/rebuild/canonical-plan.json
python -m unittest discover -s tests/rebuild -p "test_*.py"
```

The full build can take significant time; a subset is a smoke test only. The compact full inventory report was about 201 KB in the documented run; the optional legacy full-detail JSON occupied about 1.37 GB. Consult the inventory guide before requesting detailed output. A successful retained-object build or inventory does not establish byte matching or linkability. The canonical command shown omits the optional retained verification receipt, so it produces unverified candidates; see the canonical and retained-verification guides for receipt binding. Run the original comparison separately as described in the root README. `compare_builds.py` checkout/clean operations must use a disposable scratch worktree.

Keep game inputs and compiler installations outside the checkout. Generated objects, logs, inventories and reports are private: `build/rebuild/` is ignored, and output can instead be directed to a private location outside the repository. Ignore rules are a backstop; review all material before sharing and never publish game bytes, assets, binaries, objects, disassembly, credentials or personal paths. No licence is granted by the existing repository license; any eventual publication needs a separate rights review.

---

## Archived ROADMAP.md

# Playable rebuild roadmap

This is a development plan, not a claim of a playable build. The existing repository is a reference-matching project: its documented 70,611 in-scope entries comprise 68,657 ordinary function addresses and 1,954 exception-handling entries; other generated runtime/linker material remains outside that scope. The starting checkout was commit `87eb937`. Matching individual functions does not establish a working executable. Preserve the existing reference workflow and its oracle throughout.

## Milestones and exit evidence

1. **Reference matching.** Keep the existing `build_and_match.py` image fingerprint, function, relocation and exception-handling comparisons and the pull-request comparison workflow intact. Record the revision, compiler versions and results of any run; do not claim a local full run without performing it. Run `compare_builds.py` checkout/clean operations only in disposable scratch worktrees.
2. **Full recipe baseline.** Reproduce the full approximately 2,988-unit `build/units.json` recipe using its exact compiler, flags and per-unit variants. Account for each recipe entry and failures, including variants that share source. Establish the actual result on a suitable private machine before calling this complete.
3. **Retained COFF graph.** Retain generated objects privately and inventory definitions, references, sections, relocations and duplicate/variant relationships. Make the graph traceable to recipe entries and compiler configuration. Objects and derived sensitive content stay private.
4. **Canonical definitions, data and ABI.** Resolve competing definitions and variant ownership with evidence; identify missing data, initialization, calling conventions, layouts, libraries and runtime dependencies. Separate facts from hypotheses and maintain an auditable unresolved-symbol and ABI ledger. Do not silently discard recipe variants.
5. **Startup and link.** Design a separate runtime target, select canonical inputs, resolve startup and library integration, and produce a private link with documented dependencies. A successful link alone is not a functioning game and must not alter the matching oracle.
6. **Menu.** Establish a repeatable private launch to the main menu with owned, compatible inputs. Record environment, observed behavior, blockers and repeatable checks; avoid reporting a menu milestone from a link alone.
7. **Gameplay.** Exercise a documented minimal gameplay path, then expand coverage with reproducible scenarios and track failures and compatibility assumptions.
8. **Save and load.** Demonstrate a documented save/load round trip across restarts, checking state integrity and recording limitations and compatibility.
9. **Reproducibility.** Provide a stranger-readable setup, pinned toolchain identification, deterministic configuration and independently repeatable private builds and smoke checks. Assess reproducibility throughout, and make final claims only with recorded evidence.

## Inputs, output and publication

Follow the existing README for supported image and Microsoft compiler requirements. Obtain compilers and owned game inputs separately; never store or publish them here. Generated rebuild files, logs and inventories default to the ignored `build/rebuild/` directory; a private directory outside the checkout is also suitable. Review any output before sharing: game code bytes, disassembly, assets, executables, objects, credentials, personal absolute paths and context packs do not belong in publishable files. Metadata may still reveal private information and needs review.

`LICENSE` explicitly grants no licence to contributions; third-party components retain their own licences. Private development does not establish rights to publish a rebuild or its inputs. A separate rights review is needed before any eventual publication. No copy-protection bypass is part of this plan.

## Current evidence and next work

The committed foundation compiled all 2,988 recipe entries. A separate full original comparison and direct retained verification report parity for 68,667 recipe rows and 1,954 EH entries; 95 local EH notes remain, and strict local EH and runtime closure are false. The offline suite passed 118 of 120 tests with two native opt-ins skipped; three separate native probes were executed and verified, including one four-byte game leaf exercised in 7,168 calls across seven values. No playable game has been demonstrated. These results do not complete canonical ownership, startup or link.

The fixture-only EH extractor and constructor-rollback probe executed successfully in two independently reviewed layouts; the metadata-only ownership tool records hash-bound EH piece alternatives with runtime selection false. The independent final aggregate ran 149 tests, with 147 passing and two native opt-ins skipped. Real IOTask, vtable and RTTI closure is not authorized in this slice. Evidence-backed data ownership and initialization and actual CRT, helper and import-library provider contracts remain subsequent work. The recovery audits are delivered with bounded independent review. See [agent work and ownership](AGENT-WORK.md) for assignments and evidence boundaries.

The latest independently reviewed phase selected 68,657 function CODE owners, including ten approved overrides, and mapped 280 import slots across 17 DLLs as metadata. The import plan records 9,700 uses, including 6,306 exact verified fields. Reviewed CRT and original data fixtures passed; none authorizes game provider adoption or data fixups. The prior aggregate ran 195 tests: 193 passed and two native opt-ins were skipped.

A reviewed original binding fixture passed, and two reviewed layouts of one source-built game scalar function with two literals each passed 9,216 exact-bit calls with x87 state unchanged. A metadata scan found 189,111 matching relocation field geometries and 88 missing COFF fields across 59 functions and 47 units; no safe patch has been established. Read-only triage is underway. These results do not establish game startup or broader closure.

The latest independent aggregate ran 283 tests: 281 passed and two native opt-ins were skipped.

The independently reviewed runtime binding plan records 490,713 actual fields and 88 exact missing identities; its 18 focused tests passed. A separate one-source overlay passed 14 focused tests and 12/12 same-unit comparisons while moving one field to a DIR32 relocation. It was compiled only, not linked or executed. Neither result approves providers or fixups; the original 88-field baseline remains unchanged.

Reviewed TLS and CRT proposals do not approve runtime providers. EH triage found 95 textual notes in 16 units and 128 false pieces in total: 116 in those units and 12 elsewhere. The review did not independently reconstruct every role label or the full trace, and these counts do not establish EH closure. The latest stable scoped suite remains 301 passed and two skipped out of 303 tests.

Both independently reviewed layouts of an original TLS fixture passed thread isolation and shutdown checks. Its named file-backed OS dependency review does not attest in-memory KnownDLL state or the entire loader graph; no game TLS provider is approved. The runtime-data ledger reconciles 150,165 data records and 88 missing identities without repeating the original PE/object scan or approving materialization. The latest scoped aggregate ran 353 tests: 351 passed and two native opt-ins were skipped.

Reviewed experiments now include six original CRT bootstrap processes with 108 event records, 4,608 game TLS getter calls across two layouts with authored TLS storage, and a compile-only EH overlay improving two targeted cleanup matches while SubObjA remains failed. A bounded archive contains three members, five exports and two undefineds. An all-size inventory accounts for 68,657 owners: 16,859 candidates and 51,798 blocked. These results do not establish a game launch, full provider closure or runtime readiness. New closure, bulk-pool, application-entry and data-arena proposals are read-only.

The latest independently reviewed aggregate ran 468 tests: 466 passed and two native opt-ins were skipped. No native probe was rerun for that aggregate.

Current uncommitted work includes independently reconciled ordinary root-closure metadata, a six-root archive pilot with read-only native conformance, and a streamed DATA observation with selection disabled. Entry projection and an expanded EH observer remain under development and review. None establishes a full game link, provider closure or runtime.

---

## Archived AGENT-WORK.md

# Rebuild work and ownership

Coordinate changes before editing a path owned by another contributor. The recipe-audit owner also owns the synthetic runtime probe and coordinates compiler slots with the toolchain owner. The table records assignments, not completed milestones. Each owner should document verified behavior, checks and blockers in their own deliverable; the coordinator integrates without claiming unrun tests or a runnable game.

| Area | Assigned deliverables | Owner and configured route | Status |
|---|---|---|---|
| Build and toolchain | `tools/rebuild/build_objects.py`, `tools/rebuild/toolchain.py`, `docs/rebuild/BUILD.md` | `/root/rebuild_toolchain`; gpt-6.1-sol medium | Full retained build compiled 2,988 of 2,988; independent full reference comparison also passed, exit 0. |
| Symbols and COFF | `tools/rebuild/coff_inventory.py`, `docs/rebuild/LINK-INVENTORY.md` | `/root/rebuild_symbols`; gpt-6.1-sol medium | Full inventory reconciled all 2,988 entries with zero parse errors or omissions; canonical-provider planning is in progress. |
| Canonical provider planning | `tools/rebuild/canonical_plan.py`, `tests/rebuild/`, `docs/rebuild/CANONICAL-PLAN.md` | `/root/rebuild_symbols`; gpt-6.1-sol medium | Owner reports v3 receipt consumer and 19 tests: selected recipe rows cover 68,657 byte-verified addresses; all candidates remain unselected and runtime closure remains false. |
| Narrow COMDAT extraction and leaf proof | `tools/rebuild/coff_extract.py`, `tools/rebuild/game_leaf_probe.py`, `runtime/probes/game_leaf_probe.cpp`, `tests/rebuild/`, `docs/rebuild/COFF-EXTRACT.md`, `docs/rebuild/GAME-LEAF-PROBE.md` | `/root/rebuild_runtime`; gpt-6.1-sol medium | Owner reports the initial whole-object link failed on 11 unrelated references; constrained extraction then enabled an independently map/hash/import-reviewed native leaf probe (7 values, 7,168 calls). Final independent validation passed; no gameplay or general closure is claimed. |
| Retained-object verification | `tools/rebuild/verify_objects.py`, `tests/rebuild/`, `docs/rebuild/RETAINED-VERIFY.md` | `/root/rebuild_runtime`; gpt-6.1-sol medium | Independently reviewed v3 checks all 2,988 retained objects: selected function rows and global EH coverage match original parity, with 95 local EH notes preserved. Strict local EH and runtime closure remain false. |
| Narrow COFF rewrite | `tools/rebuild/coff_rewrite.py`, `tests/rebuild/`, `docs/rebuild/COFF-REWRITE.md` | `/root/rebuild_runtime`; gpt-6.1-sol medium | Nine focused tests and a narrow private rename/match check documented; broader rewrite remains unproven. |
| Data coverage plan | `tools/rebuild/data_plan.py`, `tests/rebuild/`, `docs/rebuild/DATA-PLAN.md` | `/root/rebuild_toolchain`; gpt-6.1-sol medium | Owner reports 15 synthetic tests and a successful private metadata run; 8,549 classified targets unresolved and no semantic fixups approved. |
| Data strategy | `docs/rebuild/DATA-STRATEGY.md` | `/root/rebuild_toolchain`; gpt-6.1-sol medium | Read-only evidence audit delivered; canonical data ownership and initialization remain open. |
| Generated code gaps audit | `docs/rebuild/GENERATED-CODE-GAPS.md` | `/root/rebuild_gaps_recovery`; gpt-6.1-sol medium | Recovery audit delivered and independently reviewed against named-file hashes; complete joins were not independently rerun. Historical sample and CRT lead remain unverified. |
| EH closure pilot | `docs/rebuild/EH-CLOSURE-PILOT.md` | `/root/rebuild_eh_recovery`; gpt-6.1-sol medium | Recovery audit independently reviewed against named object hashes; PE metadata observations were not independently rechecked. One constructor graph has no catches and still needs vtable, RTTI, deleting-destructor and lock-provider closure. |
| Fixture-only EH extraction and probe | `tools/rebuild/coff_eh_extract.py`, `tools/rebuild/eh_fixture_probe.py`, four original EH C++ fixture files, two test files, `docs/rebuild/EH-FIXTURE-PROBE.md` | `/root/rebuild_eh_recovery` (implementation); `/root/rebuild_docs_recovery` (documentation) | Both reviewed original fixture layouts executed successfully; independent final suite and scoped source/privacy review passed. The existing zero-relocation extractor remains unchanged. Real IOTask, vtable and RTTI closure is not authorized in this slice. |
| Metadata-only EH ownership | `tools/rebuild/eh_ownership.py`, its tests, `docs/rebuild/EH-OWNERSHIP.md` | `/root/rebuild_gaps_recovery`; gpt-6.1-sol medium | Metadata implementation and private run delivered; records exact hash-bound EH piece alternatives with runtime selection false. Independent final suite and scoped source/privacy review passed. |
| CRT provider contract | `tools/rebuild/crt_provider.py`, `tests/rebuild/test_crt_provider.py`, `runtime/probes/crt_purecall_probe.cpp`, `docs/rebuild/CRT-PROVIDER.md` | `/root/rebuild_gaps_recovery`; gpt-6.1-sol medium | Completed: ten tests and independently reviewed child exits 0/73/3/0. The fixture does not adopt a game provider. |
| Function ownership selection | `tools/rebuild/function_selection.py`, `tests/rebuild/test_function_selection.py`, `docs/rebuild/FUNCTION-SELECTION.md`, `runtime/function-provider-overrides.json` | `/root/rebuild_function_selection`; gpt-6.1-terra | Root approved ten choices based on checked same-source candidates; report records 68,657 CODE owners and 68,667 checked rows. Independent review reconciled all choices and rows; ABI, EH, data, link and runtime eligibility remain false. |
| Import plan | `tools/rebuild/import_plan.py`, its tests and `docs/rebuild/IMPORT-PLAN.md` | `/root/rebuild_gaps_recovery`; gpt-6.1-sol medium | Metadata-only report independently reviewed: 280 slots across 17 DLLs, 9,700 uses and 6,306 exact verified fields. No game import provider adoption or closure is claimed. |
| Original data fixture | Original producer/consumer fixture and minimal DATA-only COFF writer, tests and documentation | `/root/rebuild_data_fixture`; gpt-6.1-sol | Reviewed original producer/consumer fixture execution passed; fixture scope excludes real game data materialization. |
| Metadata review | Function choices and import plan | `/root/rebuild_metadata_review`; gpt-6.1-terra | Function selection and import reports independently reviewed; full native PE parsing and every raw operand were not independently rerun. |
| Original symbol-binding fixture | `tools/rebuild/coff_bind.py`, `tools/rebuild/binding_fixture.py`, six original fixture files, two tests, `docs/rebuild/BINDING-FIXTURE.md` | `/root/rebuild_symbol_binding`; gpt-6.1-sol | Completed mechanism-only fixture: 17 focused tests passed; one independently reviewed native child passed with 131 calls and distinct isolated writable data. No game mappings or provider adoption. |
| Game component candidate audit | `docs/rebuild/GAME-COMPONENT-CANDIDATE.md` | `/root/rebuild_data_fixture`; gpt-6.1-sol | Read-only candidate audit and selected-owner review completed; its audit alone authorized no extraction or native game execution. |
| Game scalar component | `tools/rebuild/coff_literal_extract.py`, `tools/rebuild/game_scalar_component.py`, two tests, original `game_scalar_probe.cpp` caller, `docs/rebuild/GAME-SCALAR-COMPONENT.md` | `/root/rebuild_data_fixture`; gpt-6.1-sol | Both independently reviewed layouts passed 9,216 exact-bit calls each, with sentinels and x87 state unchanged; 24 focused tests passed. Scope is one 55-byte scalar function and two source-emitted eight-byte read-only literals, not game startup or broader closure. |
| Relocation geometry audit | `tools/rebuild/relocation_audit.py`, `tests/rebuild/test_relocation_audit.py`, `docs/rebuild/RELOCATION-AUDIT.md` | `/root/rebuild_symbol_binding`; gpt-6.1-sol | Reviewed metadata scan: 189,111 matching field geometries; 88 missing COFF fields across 59 functions and 47 units. No safe patch or game fixup is approved. |
| Absolute-address triage | `docs/rebuild/ABSOLUTE-ADDRESS-TRIAGE.md` | `/root/rebuild_symbol_binding`; gpt-6.1-sol; metadata review by `/root/rebuild_metadata_review` | Read-only triage and bounded independent review completed; role labels and inline provenance were not fully independently reconstructed. It did not itself authorize a source fix. |
| Runtime source overlay pilot | `tools/rebuild/runtime_source_overlay.py`, its tests, `runtime/source-overlays/niaccumulator-address.json`, `docs/rebuild/SOURCE-OVERLAY.md` | `/root/rebuild_symbol_binding`; gpt-6.1-sol | One-source v2 overlay completed and reviewed: 14 focused tests, 12/12 same-unit comparator rows match and one field has the intended DIR32 relocation. It is compile-only, unlinked and unexecuted; no provider is adopted and original source is unchanged. |
| Runtime binding plan | `tools/rebuild/runtime_bind_plan.py`, its tests, `docs/rebuild/RUNTIME-BIND-PLAN.md` | `/root/rebuild_gaps_recovery`; gpt-6.1-sol | Finalized and independently reviewed read-only plan records 490,713 actual fields and 88 exact missing identities; 18 focused tests passed. No provider, fixup or runtime closure is approved. |
| Scalar component binding | `tools/rebuild/component_binding.py`, its test and documentation | `/root/rebuild_symbol_binding`; gpt-6.1-sol | Reviewed physical-symbol identity namespacing passed 20 focused tests and both v2 native layouts: 9,216 exact-bit calls each, with sentinels and x87 state unchanged. V1 failed before link and is preserved. This establishes only the selected scalar component. |
| TLS owner fixture | `tools/rebuild/tls_owner_fixture.py`, its tests, four original probes, `docs/rebuild/TLS-OWNER-FIXTURE.md` and `TLS-OWNER-PROPOSAL.md` | `/root/rebuild_data_fixture`; gpt-6.1-sol | Both independently reviewed original-fixture layouts passed isolation, callbacks and shutdown. V1/v2 failures and their post-failure evidence limits remain preserved. Review covers named file-backed OS chains, not in-memory KnownDLL state or the full loader graph. No game TLS provider is approved. |
| EH diagnostic triage | `docs/rebuild/EH-DIAGNOSTIC-TRIAGE.md` | `/root/rebuild_eh_recovery`; gpt-6.1-sol | Read-only triage independently reviewed within stated limits: 95 textual notes in 16 units, 116 false pieces in those units and 12 elsewhere. Labels and full trace were not independently reconstructed. No comparator changes, provider or runtime closure. |
| CRT bootstrap contract | `tools/rebuild/crt_bootstrap_contract.py`, tests, five original probe files and `docs/rebuild/CRT-BOOTSTRAP-CONTRACT.md` | `/root/rebuild_gaps_recovery`; gpt-6.1-sol | Reviewed original fixture: six processes and 108 event records passed. This is not game startup or general CRT compatibility. |
| EH parent-role metadata | `tools/rebuild/eh_parent_roles.py`, its tests, `docs/rebuild/EH-PARENT-ROLES.md` | `/root/rebuild_eh_recovery`; gpt-6.1-sol | Independently reconciled two-object read-only result: two parents, seven roles, nine pieces and five failed pieces; 14 focused tests passed. Saved-this, member, frame, provider and runtime contracts remain unverified. |
| EH type overlay | `tools/rebuild/eh_type_overlay.py`, its test, runtime overlay and `docs/rebuild/EH-TYPE-OVERLAY.md`; `EH-RUNTIME-REPAIR-PROPOSAL.md` | `/root/rebuild_eh_recovery`; gpt-6.1-sol | Reviewed compile-only experiment improved two targeted cleanup matches; SubObjA remains failed. No link, execution or provider adoption. |
| Runtime data owners | `tools/rebuild/runtime_data_owners.py`, its tests, `docs/rebuild/RUNTIME-DATA-OWNERS.md` and `RUNTIME-DATA-OWNER-PROPOSAL.md` | `/root/rebuild_symbol_binding`; gpt-6.1-sol | Metadata ledger independently reconciled all 150,165 data records and 88 missing identities; original PE/object scan was not rerun. No storage owner, materialization, fixup or runtime provider is approved. |
| Game TLS getter component | `coff_tls_extract.py`, `game_tls_component.py`, two tests, original caller and `GAME-TLS-COMPONENT.md` | `/root/rebuild_data_fixture`; gpt-6.1-sol | Independently reviewed two-layout execution: 4,608 getter calls total. Authored TLS fixture only; no game TLS owner or startup approval. |
| Runtime code pool and inventory | `coff_code_archive.py`, `runtime_code_pool.py`, related tests, policy and docs; `runtime_code_inventory.py`, test and doc | `/root/rebuild_code_pool` and `/root/rebuild_symbol_binding` | Reviewed bounded archive has three members, five exports and two undefineds. All-size inventory accounts for 68,657 owners: 16,859 candidates and 51,798 blocked. Serialization and candidate status do not establish ABI, provider or runtime readiness. |
| Root code closure proposal | `docs/rebuild/ROOT-CODE-CLOSURE-PROPOSAL.md` | `/root/rebuild_symbol_binding` | Read-only proposal for 40,176 recipe-wide blocks; no emission or native work. |
| Bulk code pool proposal | `docs/rebuild/BULK-CODE-POOL-PROPOSAL.md` | `/root/rebuild_code_pool` | Read-only proposal for the 16,859 candidates; no emission or native work. |
| Application entry link proposal | `docs/rebuild/APPLICATION-ENTRY-LINK-PROPOSAL.md` | `/root/rebuild_gaps_recovery` | Read-only proposal for the 4,532-byte entry; no emission or native work. |
| Unresolved data arena proposal | `docs/rebuild/UNRESOLVED-DATA-ARENA-PROPOSAL.md` | `/root/rebuild_data_fixture` | Read-only private data-only symbolic projection proposal; no emission or native work. |
| Ordinary root closure and canonical main evidence | `tools/rebuild/root_code_closure.py`, `canonical_reference_groups.py`, corresponding tests and docs | `/root/rebuild_symbol_binding`; canonical adapter by `/root/rebuild_gaps_recovery` | Ordinary-v2 two-object observation and canonical main certificate independently accepted as metadata. Full serialization, namespaces, providers, ABI and runtime remain false; adapter compatibility delta and actual entry projection need their own review. |
| Six-root bulk code pilot | `tools/rebuild/bulk_code_pool.py`, its test, policy and `docs/rebuild/BULK-CODE-POOL.md` | `/root/rebuild_code_pool` | Six-root pilot and native read-only conformance independently accepted. No executable link, provider closure or all-candidate production approval. |
| DATA arena observation | `tools/rebuild/data_arena_projection.py`, its test, policy and associated docs | `/root/rebuild_data_fixture` | Saved observation streamed and independently reconciled, including 150,165 fields and 11,273 fragment classifications; original PE geometry and every non-field event were not independently rederived. Earlier bounded selection found no suitable whole-fragment pilot under its preference. Owner is reevaluating small whole zero and HIGHLOW fragments for mechanical private projection; prior HIGHLOW preference is not a hard requirement. Runtime eligibility remains false. |
| Expanded EH observer | `tools/rebuild/eh_code_closure.py`, its test, policy and docs | `/root/rebuild_eh_recovery` | Existing consumer namespace correction passed source review and 16 synthetic tests; actual observation remains blocked on an expanded-root certificate. Additive producer schema is under development with `/root/rebuild_symbol_binding`; consumer adaptation needs independent review and a separately authorized observation. No type repair or runtime provider closure. |
| Startup host | Original startup host implementation and review | `/root/rebuild_startup_host`; independent review `/root/rebuild_startup_review` | In progress; implementation and review are separate. No game startup or runtime closure is claimed. |
| Entry dependencies | Application-entry dependency implementation and review | `/root/rebuild_entry_dependencies`; independent review `/root/rebuild_dependency_review` | In progress; implementation and review are separate. No completed game link or provider closure is claimed. |
| All-current CODE supervisor | Bounded supervisor source and tests | `/root/rebuild_code_pool` | Source work authorized and in progress; no completed all-current emission or runtime readiness is claimed. |
| Startup closure | `docs/rebuild/STARTUP-CLOSURE.md` | `/root/rebuild_runtime`; gpt-6.1-sol medium | Audit delivered; startup remains unproven. |
| Runtime gaps join | `tools/rebuild/runtime_gaps.py`, `tests/rebuild/test_runtime_gaps.py`, `docs/rebuild/RUNTIME-GAPS.md` | `/root/rebuild_recipe_audit`; gpt-6.1-terra high | Metadata join and private receipt independently reviewed; relocation occurrences are not a missing-function count. |
| Recipe audit | `tools/rebuild/recipe_audit.py` | `/root/rebuild_recipe_audit`; gpt-6.1-terra high | Foundation implementation committed; offline suite and independent review cover the delivered tool. |
| Synthetic runtime probe | `runtime/probes/crt_tls_probe.cpp`, `tools/rebuild/runtime_probe.py`, `tests/rebuild/test_runtime_probe.py`, `docs/rebuild/RUNTIME-PROBE.md` | `/root/rebuild_recipe_audit`; gpt-6.1-terra high | Native independent CRT/TLS probe passed; it is not game startup. |
| Synthetic import alias probe | `runtime/probes/import_alias_probe.cpp`, `tools/rebuild/import_probe.py`, `tests/rebuild/test_import_probe.py`, `docs/rebuild/IMPORT-PROBE.md` | `/root/rebuild_recipe_audit`; gpt-6.1-terra high | Standalone native probe passed; game ABI and startup remain unverified. |
| Validation and review | `docs/rebuild/VALIDATION.md`, read-only implementation review | `/root/rebuild_validation_recovery`; gpt-6.1-terra high | Recovery audits and prior EH implementations reviewed within recorded limits; Reviewed the CRT and data fixture pre-execution gates and final aggregate. |
| Runtime audit | `docs/rebuild/RUNTIME-AUDIT.md` | `/root/rebuild_runtime`; gpt-6.1-sol medium | Audit delivered: application-entry candidate identified; startup and ABI contracts remain unresolved and no game runtime launch established. |
| Offline CI workflow | `.github/workflows/rebuild-tests.yml` | `/root/rebuild_integration`; gpt-6.1-terra high | Validator reviewed workflow and native opt-in guards; public CI has not run. |
| Documentation integration | `AGENTS.md`, `docs/rebuild/README.md`, `docs/rebuild/ROADMAP.md`, `docs/rebuild/AGENT-WORK.md`, additive `.gitignore` rules | `/root/rebuild_docs_recovery`; gpt-6.1-terra high | Recovery integration continues alongside the newly authorized implementations. |

The reference recipe is the source of truth for compiler selection, flags and variant identity. Runtime selection must be an explicit, separately evidenced decision. Keep sensitive inputs outside the checkout; generated output defaults to the ignored `build/rebuild/` directory and can instead be kept outside the checkout, and do not commit local paths, secrets, binaries, assets, disassembly, game code bytes or packs. Preserve the matching and official gates. Use a disposable scratch checkout for any `compare_builds.py` command that checks out or cleans files. See [the roadmap](ROADMAP.md) and the root README for setup and constraints.


## Agent coordination

Inspect actual agent status before assigning work or review. `send_message` queues a message but does not start a completed agent; use `followup_task` on the existing canonical identity for an idle or completed reviewer. Do not spawn duplicates solely because a queued message is unanswered. Save owned progress and exact operation and artifact identities before long work; reconcile saved outputs after a crash before rerunning.

## Crash recovery continuation

The foundation checkpoint contains 50 files. Recovery continues from that checkpoint without repeating the completed build baseline. The current coordinator is `/root`; recovery owners are `/root/rebuild_gaps_recovery`, `/root/rebuild_eh_recovery`, `/root/rebuild_validation_recovery`, and `/root/rebuild_docs_recovery`, with the scopes in the table above. Prior agents are no longer active. The two audits were not saved before the interruption; their recovered versions are delivered and reviewed within the limits recorded below. Preserve the existing uncommitted ledger changes.

The foundation offline suite ran 120 tests: 118 passed and two native opt-ins were skipped. The latest independently reviewed aggregate ran 468 tests: 466 passed and two native opt-ins were skipped; no native probe was rerun. Three separate native probes were executed and verified: synthetic CRT/TLS, synthetic import alias, and a single four-byte game leaf (7 values, 7,168 calls). Source and tool hashes were stable after the foundation commit. The leaf is not a game launch. Hosted CI has not run.

The authorized fixture-only EH extractor and constructor-rollback probe and the metadata-only ownership tool are delivered and independently reviewed; the latter records exact hash-bound EH piece alternatives with runtime selection false. The existing narrow zero-relocation extractor stays unchanged; real IOTask, vtable and RTTI closure is outside this authorization. Subsequent work remains evidence-backed data ownership and initialization, CRT purecall and other actual provider contracts, and a metadata-bound candidate body/ABI check. No provider should be guessed or placeholder manufactured to satisfy a link. The generated-code audit was independently reviewed without rerunning its complete joins; the EH audit review checked object hashes without independently rechecking PE metadata.

## Current uncommitted integration

The new root-closure, canonical-reference, bulk-pool, DATA-arena and EH-observer tools, tests, policies and documents are intentional work in progress. Their proposals and the application-entry proposal are separate untracked work. Do not stage or checkpoint these groups until their owners finish and their exact review gates are reconciled. The actual entry projection source is pending. No full game link or runtime has been established.

For recovery, ordinary-v2 root summary SHA-256 is `2273d54cdf913e58c4eb9317bf4f289a71a7e49639ed16a6cf2a317bc37d17b3`; its canonical main certificate is `9bbbdfe0b590b4919ae773094c9d466d16ff41f38333803d67a69ff1364a3037`. The accepted six-root pilot receipt is `fb4aa4c58dad0d37df8ccf86ca169b23c4a4c3f2492f1abb77daa217970357ee` and native read-only conformance receipt is `765dd5f0b23a7199377f8a9eff470410e3be19079d860f342f9373f1ae3b58c8`. The accepted DATA observation summary is `673ed7dcf9251f97680e37afb68c7d02fb70e1b0a04b6bc990831f0da43e1048`, detail `0b1a982b8acf78e2d0fc33cf36f7d40f67b4c978c113f504a5ea792216bc5b57`. These are private artifact identities, not public artifacts or approval for further operations. Preserve their recorded inputs, snapshots and earlier failures.

## Continuation ledger

Starting checkout: `87eb937` on `main`, clean before branch `codex/playable-rebuild` was created. The root coordinator assigns work, integrates reports and resolves shared ownership; individual owners edit only their assigned deliverables. The foundation checkpoint is `fb73d342e64c90d1aa7d1fccb43c6955524b82e4`; reviewed EH ownership and fixture work is checkpointed at `a593364`, reviewed function ownership, import planning and data fixture work at `5600665`, scalar and binding work at `dddc7ec`, the runtime binding plan and overlay at `38cc726`, EH parent roles at `9b9b439`, the measured TLS fixture and data ledger at `35b5fa4`, and the source-link foundation at `6f5c26cf210bad11897cd2356440704e72406386`. The protected baseline remains unchanged. Private artifacts remain ignored and no push was made.

Next gates:

1. Preserve the independently reviewed original symbol-binding fixture evidence; existing reviewed source and data tools remain unchanged.
2. Preserve reviewed scalar, overlay and binding-plan receipts; neither the compile-only overlay nor the read-only plan establishes provider or runtime closure.
3. Preserve the reviewed function selection, import metadata and fixture receipts; retain false ABI, EH, data, link and runtime eligibility until separately established.
4. Preserve the full retained-build and independent reference-comparison evidence, including compiler identity and variant coverage; compilation alone does not establish a matching baseline.
5. Plan canonical runtime inputs and a separate startup/link target only after definition, reference, data and ABI blockers are evidenced.

The coordinator reports all three compiler probes passed and the full retained-object build compiled 2,988 of 2,988 recipes with exit 0. Full COFF inventory reconciled all 2,988 entries, with zero parse errors or omissions; it recorded 814,858 relocations, 180,206 external definitions, 11,727 duplicate names and 174,649 raw unresolved names. Raw unresolved names are not a missing-source count. The independent full reference comparison passed on separately compiled temporary objects, exit 0: 68,667 of 68,667 recipe function rows and 1,954 of 1,954 EH entries matched. Recipe rows include repeated addresses and are not unique-function counts. That run does not intrinsically bind the retained objects. The independently reviewed direct retained-object v3 check reports original parity and matching selected function rows/global EH coverage, preserving 95 local EH notes also found in the baseline. Strict local EH and individual provider runtime closure remain unverified; prior receipts remain intact. An earlier owner-reported SP1 smoke retained two of 2,988 recipe objects. The partial inventory reported 115 relocations, 28 external definitions, 55 unresolved names and two imports; these are sample counts, not whole-program totals. The foundation suite reported 120 tests with two intentionally skipped native opt-ins; the separate native CRT/TLS probe passed constructor and destructor checks and independent main/worker thread-local values. This synthetic bootstrap is not game startup. A runnable executable, menu, gameplay and save/load remain future milestones; none has been demonstrated in this wave.

Independent final validation reviewed the v3 retained, data, canonical, gaps and leaf receipts and passed scoped privacy and diff checks. The next work remains canonical data ownership, provider and per-function EH closure, startup and link; none is established by the leaf probe. Hosted CI has not run.

Next-phase audits are bounded: the current EH-piece join covers 1,006 other-code and 484 ambiguous-EH unique targets. A 64-target sample found 43 frame-cleanup targets, three this-adjust tails and 12 unrecognized targets, with other categories also present. These sample results do not classify the whole population or prove runtime closure. The two recovery audits are delivered with the review limits recorded above; use their exact evidence before planning a nontrivial EH/data component.
