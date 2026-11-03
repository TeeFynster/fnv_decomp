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
