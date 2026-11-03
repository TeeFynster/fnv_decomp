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

See [agent work and ownership](AGENT-WORK.md) for present assignments; the assigned runtime audit will record runtime findings.
