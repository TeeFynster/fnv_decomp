# One game code and compiler-literal candidate

Read-only candidate audit, November 2, 2026 (America/Chicago). No extraction,
object/source changes, compilation, linking or execution were performed by this
audit. The reviewed original DATA fixture remains unchanged. This document
proposes one bounded next mechanism; it does not approve game-data fixups or
promote a metadata-selected body to runtime eligibility.

## Candidate and source contract

Use `GetWeaponHealthConditionMultiplier(float)` at symbolic reference identity
`0x00646d00`, defined in `src/fallout_shared/combatformulas.cpp:453` (body through
line 463). Its exact decorated name is
`?GetWeaponHealthConditionMultiplier@@YAMM@Z`.

This is a free x86 `__cdecl` function taking and returning one float. It needs
no object, class layout, hidden structure-return pointer or virtual dispatch.
For input greater than 0.75 it returns 1.0; otherwise it returns the float result
of `1.0 - (0.75 - input) * 0.6700000166893005`. These are literal source
expressions, not external settings or initialized globals. The function has no
source calls, allocation, locks, TLS, imports, asset access or state mutation.
The source does not clamp negative inputs to zero.

`combatformulas_dependencies.h:155` declares the same float-to-float function.
The translation unit also includes `combatformulas_support.h` and
`combatformulas_camera.h`; their unrelated game class declarations are not part
of this scalar function's ABI. The current source hash agrees with the retained
manifest and v3 receipt. Header observations in this audit do not retroactively
prove the full transitive-header environment of the historical compilation.

The earlier four-float negate lead was rejected for this task: its selected
section has no runtime relocation and supplies no code-plus-literal experiment.
No second component is proposed.

## Exact retained ownership and proof

| Identity | Observed value |
|---|---|
| Authoritative recipe index / ID | 703 / `0703-3a582158246b390e` |
| Compiler / flags | SP1; `/MT /Od /Oy- /GS /EHsc /Gy` |
| Selected native parent | Section 24, `.text`, symbol value 0, extent 55 |
| Code section policy | `no_duplicates` COMDAT, 16-byte alignment, read/execute |
| Function proof | Exact v3 row: same address, decorated name, section, value, size; `verdict=match` |
| Unit-local EH diagnostics | None for this unit |
| Parent associative children | None |
| Parent runtime relocations | Three DIR32 fields; all addends zero |

The approved `function-selection-v2.json` selects this exact code-owner tuple
without an ambiguity override. It retains `runtime_eligible=false` and
`link_ready=false`. Its selected code ownership is separate from the proposed
literal owner and future native ABI/link checks.

The immutable manifest, approved selection and v3 proof hashes were checked
against one another and the actual retained object. Metadata identities are:

| Evidence | SHA-256 |
|---|---|
| Authoritative recipe | `62f2c8da5f0daa912abdf4576328706711c6561eef7f01c93a89cb71ad46fb6c` |
| Immutable retained manifest | `bc62a5fb2553431b1e0547d11f366e52efb73096ea8ceb206c556ae5740a53eb` |
| Approved function selection v2 | `48ae62cdc5b1754b9c4af674ef4716d53afb554882e174a93acf860eaf1c6cb1` |
| Retained v3 proof | `04d44b73e81982f846bfe8d81806db72ea669586b579ff22007dfd6f7d831297` |
| Selected whole retained object | `211a7bcbb50adc39d9aad96dba73f2229609d53cd93a0e2f44470fe0c99cbb31` |
| Current/recorded source | `64e0d987b3b5c12e7327e698d51e390a3801f8cf2d1686e2655b164de80f32ec` |

These are evidence hashes, not payload or disassembly. Exact private artifact
locations remain in the existing local evidence and coordinator handoff, rather
than personal paths in tracked documentation.

## Complete proposed runtime subgraph

The actual retained COFF was reparsed with the existing strict reader. Only the
following data edges leave the selected parent; there are no code-call edges:

| Parent-relative field | Kind / addend | Target symbol | Target section / value / extent | Scalar meaning |
|---|---|---|---|---|
| +9 | DIR32 / 0 | `__real@3fe8000000000000` | 26 / 0 / 8 | double 0.75 |
| +31 | DIR32 / 0 | `__real@3fe8000000000000` | 26 / 0 / 8 | Same retained literal |
| +37 | DIR32 / 0 | `__real@3fe570a3e0000000` | 25 / 0 / 8 | double 0.6700000166893005 |

Both targets are source/compiler-emitted eight-byte `.rdata` COMDATs with
selection `any`, eight-byte alignment, read-only/non-executable flags, a complete
section-sized literal at value zero, no relocations and no associated children.
Each section contains only its section symbol/auxiliary record and the named
external literal. They have no embedded pointers or constructor, destructor,
TLS, IAT or EH ownership requirement. This makes their retained source-emitted
storage a distinct candidate runtime owner; it requires no copied PE data and
no semantic pointer fixup inside either literal. Pooled copies and aliasing
relationships outside this component receive no ownership decision here.

The whole object also contains unrelated game code and dependencies. It must
not be linked wholesale. Its normal library directives are exactly
`/DEFAULTLIB:"LIBCMT"` and `/DEFAULTLIB:"OLDNAMES"`; retaining reviewed directives
does not retain other game sections or establish their closure.

## Reference binding checked without extraction

The exact owned plaintext reference hash agrees with v3, and the unchanged
existing fingerprint gate passed all 16 probes. A fresh invocation of the
unchanged comparison core against the retained parent returned `match`, extent
55, zero byte differences and all three relocation comparisons matching. This
was read-only verification of an existing object, not fresh compilation or
execution.

The two +9/+31 target words both resolve to the recipe's symbolic literal
identity `0x0101de30`; +37 resolves to `0x01051680`. At each observed address the
complete eight-byte reference range equals the corresponding compiler literal
payload exactly. Each lies entirely in raw-backed `.rdata`, read-only and
non-executable, with eight-byte alignment. All three parent fields have actual
PE HIGHLOW records. Neither literal range contains or straddles a PE base
relocation. The relationships are therefore explicit code-to-literal address
references, not address-shaped scalar values being guessed as pointers.

The reference addresses above are comparison identities only. A future runtime
must resolve the three DIR32 fields to its own two retained literal symbols;
none may remain an original executable address or use an address fallback.
The broad PE data plan remains unapproved, including all 150,165 semantic
fixups. No reference payload was written to an artifact in this audit.

## Proposed bounded extension and native assertions

Assign a new policy-specific code-plus-read-only-literal extractor and original
native caller only after review of this proposal. Keep the existing
zero-relocation extractor unchanged. The minimal authorized input set would be
the exact selected parent section 24 and literal sections 25 and 26 of the
hash-pinned retained object, with understood symbol/section auxiliary records,
relocation index remapping, SafeSEH feature metadata where present, and reviewed
normal CRT directives. It would reject any new edge, nonzero addend, changed
extent/alignment/selection/protection, literal mismatch, unknown record, hidden
EH/initializer child or stale ownership/proof hash. No generalized recursive
game closure or whole-data extraction is needed.

Retain the existing function name and call it using a matching float-to-float
`__cdecl` declaration in an original fixture. This avoids introducing a class,
stub provider or identity rename. Preserve the source-emitted literal bytes
and let the normal linker relocate the three code fields. The new mechanism
must write private exclusive outputs, preserve the original retained object,
and freshly compare the selected component with the unchanged reference gate.
Before execution, independently inspect the extracted COFF and linked map,
relocations, literal values/protection, selected-only game providers, normal CRT
startup/imports and exact input/output hashes.

A minimal native test should use two reviewed preferred bases/layouts, verify
that code and both literals moved, and validate linked DIR32 targets and
nonrelocated content before running either. Proposed scalar cases are:

| Input | Expected single-precision result |
|---|---|
| 0 | 0.4975000023841858 |
| 0.25 | 0.6649999618530273 |
| 0.5 | 0.8324999809265137 |
| 0.75 | 1 |
| 0.875 | 1 |
| 1 | 1 |

These expectations are proposed exact binary-float results from the source
formula and literal values, not observed native results. Include immediate
single-precision neighbors below and above the 0.75 threshold, negative input
to demonstrate the absence of an extra clamp, preserved caller sentinels and
repeatable results. Derive their golden results independently with explicit
single-precision rounding; do not silently change the process floating-point
environment or weaken comparisons with an arbitrary tolerance. Record and check
the default x87 control state without modifying it. Nonfinite
inputs and alternate rounding/control modes can remain outside this first
finite-input contract, with that limitation recorded.

Preparation, independent hash-bound artifact approval and bounded execution
must remain separate stages, as for the original fixtures. A pass would prove
one source-built game scalar function plus its two compiler literals in a
normal native process. It would establish no complete combat subsystem,
game-object layout, startup, menu, assets or gameplay.

## Independent review status

Independent metadata review confirmed the exact approved selection/v3/manifest
owner tuple and current source/object hashes, reparsed all three zero-addend
DIR32 edges and both complete literal COMDATs, and checked literal identity
against the source constants. It found no blocking metadata issue for the
bounded proposal. A subsequent independent reference check confirmed the v3
image hash, all three target fields/HIGHLOW sites, exact aligned literal
payloads, read-only/non-executable `.rdata` and absence of overlapping literal
fixups. That reviewer did not repeat the comparator or fingerprint probes.
The main binary/native reviewer independently rehashed the exact object and
checked the selected symbols, flags, relocation graph and absence of associated
children or a second EH entry in the function section. The whole object has no
`.sxdata`, `.CRT*`, `.tls*`, `.pdata*` or `.xdata*` section; `@feat.00` is 1 and
the library defaults agree with those recorded above. The reviewer reproduced
all six finite expected values and found no blocker to the bounded plan,
requiring independently derived float-bit golden values and observed default
x87 state for any subsequent native test. This remains an unexecuted candidate
proposal; extraction and runtime selection require the next explicit assignment.
