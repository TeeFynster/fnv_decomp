# Compile-only constructor type-view experiment

The reviewed compile-only experiment completed with the exact targeted result:
both ordinary parents match at size/extent 166; the two distinct cleanup actions
now match their original comparison targets, and the separate SubObjA failure
remains. Fourteen focused tests pass. Independent outcome reconciliation passed within the scope recorded below. No linking, native execution or runtime provider adoption occurred.

The first authorized attempt stopped after a successful baseline compile at a
strict diagnostic-format parser; that error receipt and later read-only partial
reconciliation remain preserved. A reviewed format-only correction preceded a
fresh root-authorized baseline/overlay retry. See the measured result below.

## Scope and source transformation

`runtime/source-overlays/constructor-0043fd40.json` fixes recipe 802, parent
`0x0043fd40`, 166 bytes and the exact original source/slice identities. It contains
no function body or binary payload. The tool reads only the selected source
lines and immutable manifests/proofs. Original source, headers, recipe, matching
core and prior EH tools/receipts are never edited.

Preparation emits two private header/source pairs. The baseline copies the exact
bounded class declarations and constructor definition. The overlay changes only
the declaration types of `m_30` and `m_34` into two distinct nonpolymorphic views.
Each view declares one integer storage member, one constructor and its own
destructor, all without adapter bodies, virtual methods, inline definitions or
nothrow annotations. The parent constructor text and initializer order remain
exactly unchanged. `SubObjA` and every other declaration remain unchanged.

Both new constructor names receive **comparison-only** original identity
`0x00633c90`. The destructor comparison identities remain distinct:
`m_30` -> `0x0040c110`, `m_34` -> `0x0045cec0`. These bindings are never a linker
alias file or adopted runtime provider list. Runtime, provider and link flags
stay false, even if the experiment passes.

## Preparation and review boundary

Preparation pins the original source/object/recipe/full-v3 identities, exact
SP1 compiler, C++ frontend/backend DLLs, known CRT header dependencies and every
imported comparison/helper producer. It records generated header/source hashes,
fixed layout contracts and explicit comparison bindings. All inputs and generated
files are rehashed before publication and before/after compilation; appearance of
the absent optional function index rejects. `/showIncludes` later rejects any
unreviewed included header.

The source-only receipt has kind `fnv-eh-type-overlay-prepared`, schema 1, status
`source-only-pending-review`. An independent source review must bind the exact
prepare hash, generated-file hash map and reviewer identity with all five checks
true: `source_slice`, `declaration_only_views`, `layout_checks`,
`comparison_only_bindings`, `compile_only_runner`. Kind is
`fnv-eh-type-overlay-source-review`; it uses `approved=true` and schema 1.
A stale or incomplete review fails before invoking the compiler.

The actual prepared inputs are private
`build/rebuild/eh-type-overlay-source-v4/prepare.json`. V1-v3 are preserved as
intermediate source-only preparations; they are not eligible after tool changes.
The preparation step writes no object and starts no compiler or linker.

## Native layout gate and preserved first attempt

The first authorized attempt is private `eh-type-overlay-compile-v1/compile.json`,
SHA-256 `da72ee1dea181b5c604c589f5e7e665dfb020c0e171240293b789f71cef75823`.
Its baseline compiler returned zero, but VC9 interleaves include-note text into
class-layout lines. The initial parser rejected that output. The revised parser
accepts exactly one recognized note marker anywhere on a line, still requiring
an absolute path in the exact pinned allowlist; malformed/multiple markers reject.
The real unnumbered base heading is accepted only with the nested vptr at zero
and inherited fields at the expected offsets within that same base subsection,
plus unchanged compile-time assertions. A read-only parse of the saved baseline
log now recognizes six pinned/generated includes and the four required baseline
type layouts. No compiler was invoked to perform that diagnostic reconciliation.

The compile path is serial and hardcodes `/c`, the exact original SP1 flags,
`/showIncludes` and `/d1reportAllClassLayout`. The module contains no linker or
native probe execution path. It has no caller-supplied additional compiler flags.
Existing output paths reject, and generated artifacts stay ignored or outside
the checkout. Compiler failures and private logs remain explicit failures.

The generated source uses compile-time size, alignment and member-offset checks
for the baseline base, both original helper views, parent and the two new views.
The candidate contracts require the base size 40/alignment 4, each one-member
view size 4/alignment 4, parent size 60/alignment 4 and all base/parent member
starts. These are **requirements to be proved by the compiler**, not assertions
that four-byte spacing has already established layout.

Successful compile-time checks plus complete native layout diagnostics must
confirm the hidden vptr prefix and base displacement. The derived layout ledger
then accounts for base prefix [0,4), base fields [4,40), parent base [0,40), and
five adjacent four-byte parent field intervals through [56,60). This supports
explicit zero internal/tail padding in this scoped compiler layout. Missing or
unrecognized diagnostics, changed offsets/sizes/alignment or unexpected packing
fails closed; no guessed layout fallback is provided.

## Byte/EH and extra-reference gates

The original ordinary and EH comparison functions are imported unchanged. Both
baseline and overlay must match the 166-byte ordinary parent against the exact
owned reference image, and both reported native `compiled_extent` values must
be exactly 166. An original-oracle MATCH with extra NOP/INT3 padding cannot pass
this experiment's stricter unchanged-extent requirement. Metadata observation checks physical parent associations,
all four unwind states/transitions, handler, complete table non-relocation content
and relocation graph, plus the explicit handler-index record.

The expected bounded result is exact:

| Property | Baseline | Required overlay |
|---|---|---|
| Ordinary parent | 166-byte MATCH | Same MATCH and original destinations. |
| Five local pieces | Match, fail, fail, fail, match | Match, fail, match, match, match. |
| Targeted cleanup fields | Shared SubObjB destructor identity at native offsets 26 and 37 | Separate new destructor names, respectively resolving to the two required original targets. |
| Other diagnostic | Existing SubObjA failure | Same preserved failure. |
| State/metadata graph | Four complete states | Identical states, handler, payloads, policy and associations. |
| Runtime/provider/link eligibility | False | False. |

Every selected runtime section payload, characteristic, COMDAT policy and
reference shape must remain the same, apart from the explicit symbol identities
and two expected cleanup-target improvements. All non-debug sections are also
compared structurally, with `.sxdata` compared by its resolved handler identity.
Additional code definitions, adapter bodies, new undefined references, runtime
sections, TLS/initializers or unknown directives reject. The tool cannot hide the
SubObjA failure or declare an overall strict local pass.

A passing receipt would have kind `fnv-eh-type-overlay-compile` and status
`targeted-compile-comparison-pass-with-preserved-failure`. It records commands,
object/log/layout/reference evidence and leaves `strict_local_eh_pass=false`.
The measured compiler/comparison result is recorded below; it is not a runtime
closure or provider-adoption result.

## Commands and tests

```text
python tools/rebuild/eh_type_overlay.py prepare --spec runtime/source-overlays/constructor-0043fd40.json --doctor <known-doctor> --manifest <known-retained-manifest> --retained <v3-receipt> --recipes build/units.json --out <new-private-source-folder>
```

After independent review and root compiler-slot go only:

```text
python tools/rebuild/eh_type_overlay.py compile --prepared <prepare.json> --review <source-review.json> --review-sha256 <review-hash> --image <owned-reference> --out <new-private-compile-folder>
```

```text
python -m unittest discover -s tests/rebuild -p test_eh_type_overlay.py -v
```

The fourteen tests never invoke a compiler. They cover the exact source change,
fixed scope and target separation, source/slice drift, class-layout diagnostics,
preserved failure/state/placement checks, added references/definitions/runtime
sections, merged destructor identities, matched-but-padded extent rejection for either
input, stale review/input protection and the
compile boundary rejecting an invalid review without calling CL. Native layout format compatibility and the targeted source-comparison outcome
were subsequently observed in the root-authorized retry recorded below. The two added tests cover
interleaved include allowlists and properly scoped unnumbered base diagnostics,
including wrong-base, wrong-offset and unrelated-vptr rejection.

## Measured compile-only result

The retry receipt is private
`build/rebuild/eh-type-overlay-compile-v2/compile.json`, 61,397 bytes, SHA-256
`e2c85032f5d06218faf0dd519860cfe0bd491b16713e4149b7eb77d735d3d76e`.
It binds v4 preparation and independent source-review hashes, exact input and
compiler identities, commands, source/object/log hashes, diagnostics and complete
reference comparisons. The two compiler commands ran serially with `/c` only.

| Property | Observed baseline | Observed overlay |
|---|---|---|
| Ordinary function | MATCH, size 166, compiled extent 166 | MATCH, size 166, compiled extent 166 |
| Local piece verdicts, native order | true, false, false, false, true | true, false, true, true, true |
| Native cleanup field +26 | Shared SubObjB binding disagrees with `0x0040c110` | Separate member-30 destructor binding matches `0x0040c110` |
| Native cleanup field +37 | Shared SubObjB binding disagrees with `0x0045cec0` | Separate member-34 destructor binding matches `0x0045cec0` |
| Remaining textual diagnostic | SubObjA plus two SubObjB mismatches | Identical SubObjA mismatch only |
| Unwind graph | Four states, five code pieces | Exact same states, code-piece intervals and handler offset 41 |
| Strict local EH pass | False | False |
| Runtime/provider/link eligibility | False | False |

State transitions remain 0 -> -1, 1 -> 0, 2 -> 1, 3 -> 2. FuncInfo remains at
native metadata +32, unwind map +0; there are no try blocks and EH flags remain 1.
The parent code, 68-byte EH-code section and 68-byte metadata section have equal
raw native payload hashes before/after. All non-debug runtime sections/reference
shapes agree after canonicalizing only the explicitly allowed new symbol names;
no adapter bodies, extra definitions, references or runtime sections appeared.
The code/metadata comparison uses the original implementation without changed
masking, extents or original target values.

Both compiles passed the complete generated size/alignment/member assertions.
Native class diagnostics confirm:

| Type/storage | Baseline and overlay compiler observation |
|---|---|
| SpawnedBase | Size 40, alignment 4; vptr at 0; nine integer fields at 4 through 36. |
| SubObjA and original SubObjB | Size 4, alignment 4, storage field at 0. |
| Two new declaration-only views | Each size 4, alignment 4, storage field at 0. |
| Parent | Size 60, alignment 4; base at 0; m_28 at 40, m_2c at 44, m_30 at 48, m_34 at 52, m_38 at 56. |
| Padding ledger | No internal or tail padding in these verified base/parent/member storage intervals. |

This establishes the baseline/overlay slice's actual compiler layout rather than
guessing from adjacent offsets. It does not reconstruct every original C++ type,
historical transitive header state or whole-game storage/lifetime contract.

Baseline object SHA-256:
`6cf2dd89370aa533d2d8cfab645cfba67a8425ac0cf4ee18faa365a52f3e0206`.
Overlay object SHA-256:
`dcee7bb38d3fb4d1b2af84bfa70fb2f3b9be14f3f148d884fcf11e6118c9aff9`.
The preserved first attempt's baseline-only read-only reconciliation is separate,
SHA-256 `0ab3db9a049f7e477567f9f8a986b0a0b4e35a4e9dbf96e4b6b5fcb8f9f9f422`;
it does not retroactively turn the initial error receipt into a pass.

The result demonstrates that distinct declaration-only source views can preserve
the ordinary constructor and encode the two original EH target distinctions.
Those identities remain private comparison metadata. No actual destructor body
was linked to the declarations, no game constructor was called, and no previous
provider/frame/runtime false flag was promoted.

Independent outcome review rehashed the preparation, inputs, generated sources,
compiler outputs and receipt; replayed the unchanged ordinary/EH comparison;
checked all five piece verdicts, the four-state graph and exact original action
destinations; and compared non-debug COFF payloads, flags, relocation shapes,
resolved handler identity and undefined-symbol multisets under only the approved
renames. It also reparsed the native layout logs. This is acceptance of the
compile-only research result, not a provider, link, execution or runtime repair
approval.
