# Physical scalar-component binding

This fixed extension namespaces only the already reviewed 55-byte scalar
function `GetWeaponHealthConditionMultiplier(float)` and its two complete
eight-byte source/compiler literal owners. It adds no game provider or data
owner and does not modify original retained objects, source, recipes, matching
tools, scalar extraction tools or original caller. Native preparation is a
separate review gate; this tool has no execution command.

## Physical identity and preservation

`tools/rebuild/component_binding.py` derives a name from the complete
`(recipe_id, retained_object_sha256, retained_symbol_index)` provider identity.
An explicit per-input row separately binds its current object hash/symbol index,
role and original target identity. A selected extraction's index map connects
its current record to the retained owner. The original caller's one exact
undefined function record explicitly receives that same provider identity.
There is no global spelling map and no new source stub or linker alias.

The internal original-fixture writer accepts both EXTERNAL and auxiliary-free
STATIC symbol records. Duplicate spellings remain separate physical records;
same-content literals remain separate owners. A repeated physical provider with
conflicting original-target/role facts fails. Missing/stale indices, duplicate
mappings, unknown symbols, auxiliary-bearing selected records, name collisions,
IAT/compiler metadata bindings and unsupported directives fail closed.

Only selected eight-byte symbol Name fields, the string-table length and
appended names change. All existing symbol indices, section/payload bytes,
flags, symbol values/types/storage, COMDAT policies/associations, auxiliary
records, relocation targets/fields and addend bit patterns remain identical.
This preserves signed REL32 addends without reinterpreting them as absolute
addresses. The staged output receives a strict independent reparse and a check
of every original byte outside the permitted fields before exclusive publication.

## Fixed scalar preparation

The supported public entry point is the fixed scalar preparation, not an
arbitrary game-binding CLI. It invokes the unchanged reviewed extractor and its
full hash-bound original recipe/object/source/selection/v3/reference gates.
The complete selected object must contain exactly the reviewed directive,
55-byte code and two eight-byte read-only literal sections. Only the parent,
literal owners, section auxiliaries and known compiler metadata may survive.
EH, TLS, CRT initializer sections, IAT/unowned providers, pointer-bearing or
mutable literals, unknown associations and missing/changed code fields reject.
The component retains exactly its two reviewed CRT defaults. The unchanged
Windows caller separately retains exactly two uuid.lib defaults followed by
LIBCMT/OLDNAMES. No broad directive whitelist is used. Actual `/VERBOSE:LIB`
searches must match the hash-bound uuid/libcmt/oldnames/kernel32 libraries
resolved in the exact controlled VC-then-SDK LIB order; unknown libraries reject.

The preparation freshly compiles the unchanged original scalar caller, pinned
by its reviewed source hash, using the existing SP1 toolchain and the original
finite rational golden header. It namespaces only the caller's exact intended
undefined function record; its standard CRT/Windows references remain normal
caller dependencies. Source/proof/tool/compiler/library inputs, including the invoked PE reader,
and generated objects are hash-bound. The generated golden header is pinned
immediately after creation and rechecked after compilation and before publication. A cross-input physical binding check retains the same
original function target on both definition and caller reference.

The unchanged original comparator is run with an explicit renamed manifest
that maps each new physical identity to its already proved original target.
The source-built 55-byte function must still MATCH, including its three exact
literal references. Original target values remain comparison metadata and
never become fixed runtime fallback pointers.

```text
python tools/rebuild/component_binding.py --doctor <doctor.json> --manifest <immutable-manifest.json> --selection <selection-v2.json> --verification <retained-v3.json> --image <owned-reference> --out <new-private-directory>
```

Preparation links two private layouts with bases, object order and alignment
changed. It checks all three physical map providers, exact linked DIR32 values
and HIGHLOW locations, literal ownership/alignment/protections and every
nonrelocated payload byte. All three targets must move and at least one relative
layout position must change. Normal CRT startup/control/printing/exit/security
providers must come from LIBCMT, with exactly KERNEL32 direct imports. No other
game provider or original game code is copied into this component.

New distinct private outputs are exclusive; source objects remain immutable.
Per-object receipts preserve every physical binding. A fsynced progress journal
records command boundaries and failures; unsuccessful work remains available
without being presented as a completed preparation. All observed protected and
linked/generated artifacts are rechecked before publishing `prepare.json`.
Observed hashes/commands are not cryptographic compiler-causality proof or a
complete transitive OS loader graph.

## Review and execution boundary

Independent source/policy review must pass before native preparation. Then the
exact private objects, receipts, maps, executables, caller ABI/goldens and linked
fields require independent native pre-execution review. **Execution additionally
requires root's explicit go.** There is no execution API in this implementation.
The original scalar finite contract may be used only through a separately
reviewed gate; no general game relink, startup or provider adoption is approved.
The original 88 missing fields and 95 EH notes remain unchanged and do not enter
this already closed component.

## Current evidence

Twenty focused original synthetic tests pass without compiler or game input.
They cover global/local duplicate names, repeated local records, two identical
literal payloads with distinct native owners, signed addend bit patterns,
changed physical table layouts, conflicting bindings, stale/unknown indices,
unsupported auxiliary/metadata/IAT records, payload/relocation corruption,
EH/TLS/CRT/unowned data and missing fields, output collisions, explicit PE-reader dependency coverage and generated-golden
header mutation.

```text
python -m unittest discover -s tests/rebuild -p test_component_binding.py -v
```

The first prepare-only attempt, private `component-binding-v1`, failed before
linking because the original caller has two existing uuid.lib defaults that
were outside the component-only directive contract. Its artifacts and failure
journal remain immutable. The narrow correction gives caller/component
separate exact contracts, preserves every directive byte and pins the actual
resolved library files; tests cover contract separation and lookup/hash drift.
Both reviewers accepted the corrected fixed source/plan and all 20 tests before
the new v2 preparation. The three new implementation/test/document files were
kept outside the completed documentation checkpoint while under review.

## Reviewed v2 result

V2 preparation passed in a new private directory. Definition identities are
retained recipe `0703-3a582158246b390e`, object SHA-256
`211a7bcbb50adc39d9aad96dba73f2229609d53cd93a0e2f44470fe0c99cbb31`,
and retained symbol indices 143 (function), 146 (coefficient) and 149 (threshold).
Their selected-object indices remain 6, 9 and 12. The caller's exact undefined
record is index 15 and names the same function provider. Original target
identities `0x00646d00`, `0x01051680` and `0x0101de30` remain provenance only.

The strict writer/reparse checks preserved every non-name original byte, symbol
index and relocation/addend. A fresh unchanged comparison of the namespaced
function reported MATCH with extent 55 and its three intended literal edges.
Both new linked layouts passed exact map/provider, payload, protection and
HIGHLOW checks. Their bases are 0x500000 and 0x700000, all three owner addresses
move, and their relative layout offsets also change. Direct imports are exactly
KERNEL32.dll. Verbose linker logs identify only the four pinned library files,
including the actual resolved Uuid.Lib, without introducing a game provider.

Independent native pre-execution review checked all bound hashes, both complete
name-only object changes, both linked provider sets/fields/protections/literal
payloads, CRT/imports, the unchanged comparator and all nine exact golden bits.
Only after that acceptance did root authorize one run of each existing reviewed
executable. No object, golden header or executable was regenerated between
review and execution.

Both actual runs exited zero with empty stderr and exact expected JSON: nine
cases, 1,024 rounds, 9,216 calls, successful sentinels, x87 before/after 589855
(`0x9001f`). Captured elapsed times were approximately 0.062 and 0.047 seconds.
The bounded single-run operation saved stdout/stderr/exit/time and an fsynced
journal, with all protected input/artifact/OS dependency hashes checked before
and after each child and again at completion. Independent final review verified
the preparation/execution/script bindings, journal, actual results and zero
protected-input drift. No original game executable was launched.

Private artifacts remain under ignored `build/rebuild/component-binding-v2/`:

| Artifact | SHA-256 |
|---|---|
| `prepare.json` | `42dcb72385d09befe106a0e05b55f2980f0f6995dc1f2bf9d6e964b671a1de8b` |
| `component.obj` | `ab3fd839d1e1254543141d7cd3c50df34598d8d30b90d7451a1406b92f81e0b3` |
| `caller.obj` | `eb89aed0f158fb9a47609728cdf0d803e6634cb18411be713d895d2d7f981361` |
| `normal.exe` | `ee78da429ca4472a0e747693105664169d6923af5ad3692a5292f91fa8d7efe9` |
| `moved.exe` | `c7ddf704916d23bfaf6ccbbf69cd339766dfd5ab0c5d97f639a051c291e2bd3c` |
| `execution.json` | `6a9a698ec873ca1de455ccd1e31a2090334df9ecc18a93db24fe22608e5224d6` |

The reviewed implementation SHA-256 remains
`e5005eeee155c190332578724fca7b7da99c5e9ef95e016b9d508b8dcf52cdf6`;
focused test source SHA-256
`e278a2199a3b0cd0f6a1f3e922d6f0b4fd21d0bcd6ae6c1fecb99b89be91c427`.
This establishes physical namespacing mechanics for this one already closed
scalar component and its existing finite ABI contract. It does not repair the
original 88 migration fields, adopt broader providers, close EH/TLS/startup,
or establish menu/gameplay/asset support. Original scalar/binding/source/proof
files remain unchanged.
