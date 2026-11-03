# Rebuild work and ownership

Coordinate changes before editing a path owned by another contributor. The recipe-audit owner also owns the synthetic runtime probe and coordinates compiler slots with the toolchain owner. The table records assignments, not completed milestones. Each owner should document verified behavior, checks and blockers in their own deliverable; the coordinator integrates without claiming unrun tests or a runnable game.

| Area | Assigned deliverables | Owner and configured route | Status |
|---|---|---|---|
| Build and toolchain | `tools/rebuild/build_objects.py`, `tools/rebuild/toolchain.py`, `docs/rebuild/BUILD.md` | `/root/rebuild_toolchain`; gpt-6.1-sol medium | Full retained build compiled 2,988 of 2,988; independent full reference comparison also passed, exit 0. |
| Symbols and COFF | `tools/rebuild/coff_inventory.py`, `docs/rebuild/LINK-INVENTORY.md` | `/root/rebuild_symbols`; gpt-6.1-sol medium | Full inventory reconciled all 2,988 entries with zero parse errors or omissions; canonical-provider planning is in progress. |
| Canonical provider planning | `tools/rebuild/canonical_plan.py`, `tests/rebuild/`, `docs/rebuild/CANONICAL-PLAN.md` | `/root/rebuild_symbols`; gpt-6.1-sol medium | Owner reports v3 receipt consumer and 19 tests: selected recipe rows cover 68,657 byte-verified addresses; all candidates remain unselected and runtime closure remains false. |
| Narrow COMDAT extraction and leaf proof | `tools/rebuild/coff_extract.py`, `tools/rebuild/game_leaf_probe.py`, `runtime/probes/game_leaf_probe.cpp`, `tests/rebuild/`, `docs/rebuild/COFF-EXTRACT.md`, `docs/rebuild/GAME-LEAF-PROBE.md` | `/root/rebuild_runtime`; gpt-6.1-sol medium | Owner reports the initial whole-object link failed on 11 unrelated references; constrained extraction then enabled an independently map/hash/import-reviewed native leaf probe (7 values, 7,168 calls). Final independent validation passed; no gameplay or general closure is claimed. |
| Retained-object verification | `tools/rebuild/verify_objects.py`, `tests/rebuild/`, `docs/rebuild/RETAINED-VERIFY.md` | `/root/rebuild_runtime`; gpt-6.1-sol medium | Independently reviewed v3 checks all 2,988 retained objects: selected function rows and global EH coverage match original parity, with 95 local EH notes preserved. Strict local EH and runtime closure remain false. |
| Narrow COFF rewrite | `tools/rebuild/coff_rewrite.py`, `tests/rebuild/`, `docs/rebuild/COFF-REWRITE.md` | `/root/rebuild_runtime`; gpt-6.1-sol medium | Owner reports nine tests and a narrow private rename/match check; independent validation is pending before expansion. |
| Data coverage plan | `tools/rebuild/data_plan.py`, `tests/rebuild/`, `docs/rebuild/DATA-PLAN.md` | `/root/rebuild_toolchain`; gpt-6.1-sol medium | Owner reports 15 synthetic tests and a successful private metadata run; 8,549 classified targets unresolved and no semantic fixups approved. |
| Data strategy | `docs/rebuild/DATA-STRATEGY.md` | `/root/rebuild_toolchain`; gpt-6.1-sol medium | Read-only evidence audit delivered; canonical data ownership and initialization remain open. |
| Startup closure | `docs/rebuild/STARTUP-CLOSURE.md` | `/root/rebuild_runtime`; gpt-6.1-sol medium | Audit delivered; startup remains unproven. |
| Runtime gaps join | `tools/rebuild/runtime_gaps.py`, `tests/rebuild/test_runtime_gaps.py`, `docs/rebuild/RUNTIME-GAPS.md` | `/root/rebuild_recipe_audit`; gpt-6.1-terra high | Metadata join and private receipt independently reviewed; relocation occurrences are not a missing-function count. |
| Recipe audit | `tools/rebuild/recipe_audit.py` | `/root/rebuild_recipe_audit`; gpt-6.1-terra high | Assigned; implementation and verification in progress. |
| Synthetic runtime probe | `runtime/probes/crt_tls_probe.cpp`, `tools/rebuild/runtime_probe.py`, `tests/rebuild/test_runtime_probe.py`, `docs/rebuild/RUNTIME-PROBE.md` | `/root/rebuild_recipe_audit`; gpt-6.1-terra high | Native independent CRT/TLS probe passed; it is not game startup. |
| Synthetic import alias probe | `runtime/probes/import_alias_probe.cpp`, `tools/rebuild/import_probe.py`, `tests/rebuild/test_import_probe.py`, `docs/rebuild/IMPORT-PROBE.md` | `/root/rebuild_recipe_audit`; gpt-6.1-terra high | Owner reports a standalone native pass; game ABI and startup remain unverified. |
| Validation and review | `docs/rebuild/VALIDATION.md`, read-only implementation review | `/root/rebuild_validation`; gpt-6.1-terra high | Assigned; review in progress. |
| Runtime audit | `docs/rebuild/RUNTIME-AUDIT.md` | `/root/rebuild_runtime`; gpt-6.1-sol medium | In progress: source audit identifies an application-entry candidate and unresolved startup and ABI contracts; no runtime launch established. |
| Offline CI workflow | `.github/workflows/rebuild-tests.yml` | `/root/rebuild_integration`; gpt-6.1-terra high | Validator reviewed workflow and native opt-in guards; public CI has not run. |
| Documentation integration | `AGENTS.md`, `docs/rebuild/README.md`, `docs/rebuild/ROADMAP.md`, `docs/rebuild/AGENT-WORK.md`, additive `.gitignore` rules | `/root/rebuild_integration`; gpt-6.1-terra high | Initial integration documentation in progress. |

The reference recipe is the source of truth for compiler selection, flags and variant identity. Runtime selection must be an explicit, separately evidenced decision. Keep sensitive inputs outside the checkout; generated output defaults to the ignored `build/rebuild/` directory and can instead be kept outside the checkout, and do not commit local paths, secrets, binaries, assets, disassembly, game code bytes or packs. Preserve the matching and official gates. Use a disposable scratch checkout for any `compare_builds.py` command that checks out or cleans files. See [the roadmap](ROADMAP.md) and the root README for setup and constraints.


## Continuation ledger

Starting checkout: `87eb937` on `main`, clean before branch `codex/playable-rebuild` was created. The root coordinator assigns work, integrates reports and resolves shared ownership; individual owners edit only their assigned deliverables. The work began on an uncommitted branch; private artifacts remain ignored and no push is part of this checkpoint.

Next gates:

1. Owners finish and report the actual interfaces, tests, limitations and private output handling for their assigned deliverables. Integration checks documentation against the implemented commands and updates this ledger from verified reports.
2. Review recipe accounting and synthetic COFF inventory tests; resolve reported implementation issues before calling either tool ready. Keep generated data and reports private.
3. Preserve and review the full retained-build and independent reference-comparison evidence, including compiler identity and variant coverage; compilation alone does not establish a matching baseline.
4. Use retained private objects to classify definition, reference, data and ABI blockers. Only then plan canonical runtime inputs and a separate startup/link target.

The coordinator reports all three compiler probes passed and the full retained-object build compiled 2,988 of 2,988 recipes with exit 0. Full COFF inventory reconciled all 2,988 entries, with zero parse errors or omissions; it recorded 814,858 relocations, 180,206 external definitions, 11,727 duplicate names and 174,649 raw unresolved names. Raw unresolved names are not a missing-source count. The independent full reference comparison passed on separately compiled temporary objects, exit 0: 68,667 of 68,667 recipe function rows and 1,954 of 1,954 EH entries matched. Recipe rows include repeated addresses and are not unique-function counts. That run does not intrinsically bind the retained objects. The independently reviewed direct retained-object v3 check reports original parity and matching selected function rows/global EH coverage, preserving 95 local EH notes also found in the baseline. Strict local EH and individual provider runtime closure remain unverified; prior receipts remain intact. An earlier owner-reported SP1 smoke retained two of 2,988 recipe objects. The partial inventory reported 115 relocations, 28 external definitions, 55 unresolved names and two imports; these are sample counts, not whole-program totals. The final independently run suite reports 120 tests with two intentionally skipped native opt-ins; the separate native CRT/TLS probe passed constructor and destructor checks and independent main/worker thread-local values. This synthetic bootstrap is not game startup. A runnable executable, menu, gameplay and save/load remain future milestones; none has been demonstrated in this wave.


























Independent final validation reviewed the v3 retained, data, canonical, gaps and leaf receipts and passed scoped privacy and diff checks. The next work remains canonical data ownership, provider and per-function EH closure, startup and link; none is established by the leaf probe. Hosted CI has not run.
