# Controlled original per-unit binding fixture

The fixture contains two original providers which intentionally export the same
C-linkage function and data names. Caller A expects A's arithmetic and storage;
caller B expects B's. A normal whole-object link must fail with duplicate
function and data definitions. The prepared transformed link assigns explicit
per-object identities to the four input units, retains normal CRT startup, and
provides a bounded test of both behaviors and independent writable storage.
No game object, mapping, source extraction, import-pointer conversion or runtime
provider adoption is authorized by this fixture.

`tools/rebuild/coff_bind.py` changes only selected EXTERNAL symbol Name fields,
the existing string-table length and appended NUL-terminated names. It preserves
symbol indices, code/data, relocations/addends, section characteristics, auxiliary
records, absolute metadata and directives. The unchanged strict COFF parser
validates both original and staged objects. A second structural comparison and
an all-original-byte check cover every byte outside the permitted fields.

Plans pin exact input object/source hashes and symbol indices and declare the
source and target kinds. They require unique EXTERNAL section definitions or
undefined references. The first implementation rejects weak/common symbols,
selected auxiliaries, import-pointer spellings, new-name collisions, unsupported
layouts and symbol-bearing directives. Only default-library and fail-if-mismatch
directives without renamed-name references are accepted. Undefined symbol ABI
kinds remain explicit source declarations, not facts inferred from spelling.
The supported binder API requires the fixture runner's fresh compilation context,
with the exact known fixture source set and compiler/source/object hashes. There
is no generic arbitrary-object CLI; the low-level transform is internal and used
by synthetic tests. This is an operational scope and provenance guard. A local
Python caller can edit or forge evidence; it is not an authentication boundary.
The plan's `approved` field is an observed caller claim, not authentication,
compiler-causality proof or independent execution approval.

Preparation uses the exact VC9 SP1 compiler/linker identified by the existing
private doctor report, rejects implicit compiler/linker options and compiles
sequentially within the global two-job limit. Generated artifacts belong in a
new ignored private output directory. Exclusive output creation and staged COFF
verification avoid overwriting evidence. An append-only fsynced progress journal
retains started/completed commands across interruption. Failed preparations and
normal duplicate-link failures remain available; only complete preparation
publishes `prepare.json`.

```powershell
python tools/rebuild/binding_fixture.py prepare --doctor build/rebuild/doctor-all.json --out build/rebuild/binding-fixture-new
```

Before execution an independent reviewer must inspect the exact original and
bound objects, source/tool/compiler/library observations, map providers, direct
imports, normal CRT and duplicate-link failure. The review JSON has schema 1,
kind `original-binding-fixture-review`, `approved: true`, reviewer identity,
exact preparation/executable/map hashes and true checks `non_name_bytes`,
`provider_identities`, `duplicate_link_failure`, `normal_crt`, `map_and_imports`.
The preparation binds every generated object, per-unit plan/receipt, log, map,
executable, input source/tool and observed core OS dependency. Execution rehashes
these protected artifacts immediately before bounded child launch.

```powershell
python tools/rebuild/binding_fixture.py execute --prepare <prepare.json> --review <review.json> --review-sha256 <sha256> --receipt <new-execution.json>
```

The executable checks 130 paired arithmetic calls across -32 through 32, one
post-mutation call, distinct source-defined data addresses, initial values and
isolated writable storage. Success requires exact one-line JSON, exit zero and
empty stderr. An execution error is preserved in a new receipt. Build command
observations and hash linkage do not cryptographically prove compiler causality
or establish a complete transitive OS loader graph. This fixture establishes no
game ABI, binding, data ownership, startup, menu, gameplay or save/load result.

Offline tests use original synthetic COFF and never launch native code:

```powershell
python -m unittest discover -s tests/rebuild -p test_coff_bind.py -v
python -m unittest discover -s tests/rebuild -p test_binding_fixture.py -v
```

Native preparation v3 completed with five freshly compiled original units,
expected duplicate-link failure and transformed link success at preferred base
0x680000. Independent review approved only the exact v3 fixture executable after checking
all bound hashes, non-name bytes for all four units, edited names, actual map
owners, duplicate-link failure, normal CRT and direct PE imports. The reviewed
child executed with exit zero, empty stderr and the exact expected JSON: 131
calls, distinct data identities and isolated writable storage. The earlier v1 preparation stopped at a compiler-banner return
code assumption; its log and progress remain intact. The issue was corrected
before v2. The v2 preparation remains intermediate unexecuted evidence; v3 adds
the reviewed operational fresh-fixture scope restriction. Preparation, independent
review and successful execution receipts remain private under the v3 output
directory. Twelve binder tests and five execution-gate tests pass, including
stale protected-artifact rejection before any launch.
