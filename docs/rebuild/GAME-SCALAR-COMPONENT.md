# One scalar game-code and compiler-literal component

This implementation supports only the [reviewed candidate](GAME-COMPONENT-CANDIDATE.md):
the 55-byte `GetWeaponHealthConditionMultiplier(float)` code owner in recipe
`0703-3a582158246b390e`, native section 24/value zero, and complete eight-byte
compiler literals in sections 25 and 26. It does not link the whole game object,
copy data from the reference PE, provide a game stub or approve general game
data fixups. The existing DATA fixture, leaf/EH extractors and original matching
tools remain unchanged.

`tools/rebuild/coff_literal_extract.py` is a fixed policy-specific API, without a
generic image extraction command. Extraction itself verifies exact approved
recipe, immutable manifest, selected owner, retained v3 receipt, source, object
and owned-reference hashes. It checks the optional function index is still
absent, rehashes the v3 comparison tools and fingerprint specification, calls
the unchanged image gate and comparator, and requires the specific matched
function row. Global local-EH diagnostics elsewhere in v3 remain preserved;
they are not promoted to runtime closure.

## Retained graph and transformation

The selected parent has three zero-addend DIR32 fields: offsets 9 and 31 refer
to the source/compiler double 0.75, and offset 37 to the source/compiler double
0.6700000166893005. Neither literal has relocations or a constructor. Only the
four selected code/literal/directive sections, their exact named owners and
section auxiliary records, and understood `@comp.id`/SafeSEH `@feat.00` metadata
survive. The directive section contains only the reviewed `LIBCMT`/`OLDNAMES`
defaults. No undefined game provider remains.

The writer preserves code/literal payloads, COMDAT policies, alignment,
protections, zero addends and auxiliary metadata. It rebuilds section, symbol
and relocation indices. Unknown directives, code sharing/aliases, changed
literal identity, pointer/addend/relocation changes, hidden EH/TLS/initializer
records or children, unknown auxiliary fields and stale inputs fail closed.
An independent strict reparse and fresh unchanged reference comparison of the
selected object must pass before exclusive object/receipt publication. Existing
outputs and any input/output collision are rejected; partial staging is removed
on failure. No reference executable bytes become generated payload.

## Original caller and exact finite expectations

`runtime/probes/game_scalar_probe.cpp` declares the actual float-to-float
`__cdecl` function by its existing name. A private generated header provides
nine finite input/result pairs. Golden values use an algebraically derived
affine rational form and explicit binary32 round-to-nearest-even integer
division/remainder arithmetic, rather than host floating arithmetic or a second
native copy of the selected function. The rational values and generated header
are bound in the preparation evidence.

Cases cover the six audited inputs 0, 0.25, 0.5, 0.75, 0.875 and 1, the immediate
binary32 neighbors on either side of 0.75, and -0.25 to expose an accidental
extra clamp. The original caller runs all nine cases 1,024 times, checks exact
result bits and caller sentinels, and records 9,216 calls per layout. It reads
the x87 control state through `_control87(0, 0)` before and after; the only
supported state is the VC9 default `_CW_DEFAULT`. It does not change that
state or use arbitrary comparison tolerance. Alternate control modes and
nonfinite inputs remain outside this finite contract.

The caller suppresses dialogs only in its own process, emits failures to captured
output and returns a failure code. The parent captures stdout/stderr and limits
each own child to 20 seconds. It records failed assertions, unsupported control
state, nonzero exit or timeout as failure rather than acceptance.

## Separate preparation, review and execution

Use a new private directory under ignored `build/rebuild/`, the exact existing
SP1 toolchain, and at most two global compiler jobs. Preparation compiles only
the original caller and links it with the selected component twice, using
different bases, object orders and file alignment. It verifies that all three
named targets move and at least one relative layout offset changes. Every
linked code relocation must point to the intended current literal symbol;
all other code bytes and complete literal payloads must equal the reviewed
input. Selected code remains read/execute and nonwritable; literals remain
read-only/non-executable. Actual touching PE HIGHLOW records must be exactly
the three code fields, with none intersecting literals.

The map must contain only the selected game function and two literal providers
from `selected.obj`. Normal CRT startup, floating control, printing, exit and
security-cookie providers must come from `LIBCMT`; direct imports must be
exactly `KERNEL32.dll`. The preparation binds source/tool/proof/native inputs,
selected and caller objects, golden header, maps/executables/logs and direct/core
Windows dependency hashes. Hash-bound command observations do not prove compiler
causality, a complete historical transitive-header environment, or the full
transitive OS loader graph.

```text
python tools/rebuild/game_scalar_component.py prepare --doctor <existing-doctor.json> --manifest <immutable-manifest.json> --selection <approved-selection-v2.json> --verification <retained-v3.json> --image <owned-reference> --out <new-private-directory>
```

Preparation runs neither executable. An independent reviewer must strictly
reparse the selected COFF, inspect literal ownership, all linked relocations and
payloads/protections, maps, normal CRT/imports, golden rounding and x87 policy,
and recheck protected artifact hashes. Approval must name both exact layout
executable/map hashes and the preparation hash. Execution additionally requires
the approval receipt's exact hash:

```text
python tools/rebuild/game_scalar_component.py execute --prepare <prepare.json> --review <independent-review.json> --review-sha256 <exact-hash> --receipt <new-execution.json>
```

All protected files, preparation/review hashes and optional-index state are
rechecked immediately before and after each child, including the final child.
Each output receipt is new and immutable. Successful execution requires the
exact expected result, supported unchanged x87 mode, zero exit and empty stderr
for both reviewed layouts.

## Validation status

Twenty-four focused offline synthetic tests passed during implementation:
13 extractor tests and 11 rounding/review/execution-gate tests. They cover
malformed/missing literals, protection and COMDAT changes, addends, unsupported
and crossing relocations, child/TLS/feature/auxiliary records, stale proofs,
output collisions, strict remapping, binary32 ties/subnormals/neighbors, exact
goldens, incomplete reviews, stale artifacts, unsupported control receipts,
own-child timeout and mutation during the final child.

```text
python -m unittest discover -s tests/rebuild -p test_coff_literal_extract.py -v
python -m unittest discover -s tests/rebuild -p test_game_scalar_component.py -v
```

The private `game-scalar-component-v1` preparation passed, including a fresh
unchanged comparison of the extracted function with all three relocations.
Independent pre-execution review verified every protected hash, strict COFF
and `dumpbin` section/symbol/COMDAT evidence, both PE layouts' three linked
fields and actual HIGHLOW records, exact source payloads and protections,
selected provider sets, normal CRT/imports and all nine golden patterns/header.
The exact two variants received hash-bound approval before execution.

Both reviewed variants then passed: each ran nine cases for 1,024 rounds,
9,216 exact-bit calls with successful caller sentinels, zero exit and empty
stderr. The observed x87 control value was the supported default `0x9001f`
before and after in both layouts. No control normalization or tolerance fallback
was used. Independent final review confirmed the execution/preparation/approval
bindings, actual observations and zero protected-input drift. Private prepare,
review and execution receipts remain ignored; the source/tool inputs did not
change after preparation. This result concerns one scalar function and its two
source-emitted constants only. It establishes no game startup, combat subsystem
closure, menu, gameplay or asset support, and leaves general provider adoption
and game-data fixups outside this result.
