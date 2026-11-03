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

The latest independent aggregate ran 251 tests: 249 passed and two native opt-ins were skipped.
