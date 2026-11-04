# Rebuild guide

This project is developing a separate source-built runtime. The repository currently produces byte-matching reference objects; **it is not a playable game**. A private full build compiled all 2,988 recipe entries. Separate reference and retained-object checks reported parity for 68,667 recipe rows and 1,954 EH entries. The 95 local EH notes and unresolved provider, data, startup and link contracts remain open.

Start with the root [README](../../README.md) for the matching workflow, compatible owned input and compiler versions, and read [LICENSE](../../LICENSE). The [roadmap](ROADMAP.md) shows milestones and next gates; the [work ledger](AGENT-WORK.md) records active ownership and review status. [Evidence history](EVIDENCE-HISTORY.md) preserves prior shared progress records, while each phase document records its own scope and receipts.

## Setup and basic checks

Configure the private Windows compiler roots as described in [BUILD.md](BUILD.md). The following commands inspect the toolchain, account for the recipe and run the offline tests:

```powershell
python tools/rebuild/toolchain.py --out build/rebuild/doctor.json
python tools/rebuild/recipe_audit.py --out build/rebuild/recipe-audit
python -m unittest discover -s tests/rebuild -p "test_*.py"
```

A full retained build and inventory are separate, time-consuming operations; follow [BUILD.md](BUILD.md) and [LINK-INVENTORY.md](LINK-INVENTORY.md), coordinate compiler slots and do not repeat an existing baseline without a reason. Run the original comparison separately as described in the root README. A successful build or inventory does not prove matching or linkability. Use disposable scratch worktrees for `compare_builds.py` operations that check out or clean files.

## Evidence and boundaries

- [Validation gates](VALIDATION.md) distinguish checked observations from unrun link, startup and gameplay tests.
- [Function selection](FUNCTION-SELECTION.md), [runtime binding plan](RUNTIME-BIND-PLAN.md) and [import plan](IMPORT-PLAN.md) describe selected code identities and unresolved ABI, provider and import contracts.
- [Data strategy](DATA-STRATEGY.md), [data owners](RUNTIME-DATA-OWNERS.md), [EH ownership](EH-OWNERSHIP.md) and [EH diagnostics](EH-DIAGNOSTIC-TRIAGE.md) record remaining storage, initialization and exception-handling obligations.
- [Scalar component](GAME-SCALAR-COMPONENT.md), [game TLS component](GAME-TLS-COMPONENT.md), [CRT bootstrap](CRT-BOOTSTRAP-CONTRACT.md) and [code pool](RUNTIME-CODE-POOL.md) document bounded experiments; none establishes game startup.

Keep owned game inputs and compiler installations private. Generated objects, reports and logs default to ignored `build/rebuild/` or a private location outside the checkout. Never publish binaries, game bytes, assets, disassembly, credentials, personal paths or private packs. The repository license grants no licence to contributions; any eventual release needs a separate rights review.
