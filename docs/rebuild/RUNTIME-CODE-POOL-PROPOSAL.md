# Private runtime CODE pool proposal

Implement a **private unresolved COFF code archive**, with at most one emitted
member per retained recipe, followed by complete all-size accounting. Its job
is to retain source-built machine-code providers under exact identities; it is
not a game link, startup target or executable. Canonical undefined references
are legitimate unresolved linkage obligations. They are not invented providers,
stubs or old-address fallback calls.

This document is read-only planning. No object/archive/data emission, native
tool, compilation, linking, DLL load or execution occurred. The only new file
is this proposal. Existing extraction/binding/data/EH tools remain unchanged.

## Full selected universe and separate gates

Consume the exact function selection, v3 source/object proof, authoritative
recipe/manifest, final binding observations and current data/EH ledgers. The
selected universe is **68,657 addresses**, from 68,667 checked recipe rows.
Selection metadata spans every size from 1 through 26,620 bytes:

| Diagnostic band only | Selected addresses |
|---|---:|
| 1-255 bytes | 59,634 |
| 256-511 bytes | 4,604 |
| 512+ bytes | 4,419 |

No band is an emission limit. All selected entries currently have native value
zero, and no two chosen owners share the same `(recipe index, native section)`.
Those selection facts do not establish full section coverage, COMDAT/auxiliary
safety or absence of unverified helpers; the producer must check actual objects.
The largest selected identity is `0x00741500`, recipe
`0456-912bf78b57df41d5`, 26,620 bytes. Its size is not a reason to skip it or an
assertion that its section is eligible.

Every address must receive exactly one accounting record:

- `OBJECT_EMISSION_ELIGIBLE`: complete supported section/serialization and
  identity gates pass, possibly with explicit canonical undefined obligations.
- `BLOCKED`: one or more exact reasons and source/native evidence.

Before full classification, unvisited rows explicitly remain
`BLOCKED_PENDING_SECTION_ACCOUNTING`; they are not omitted or counted eligible.
Require the accounting-key set to equal the approved 68,657-address set, with
no duplicate/missing/extra owners. Size/compiler/status histograms reconcile to
that universe. A completed archive may contain fewer providers than this set;
its receipt must distinguish emitted, eligible-but-not-requested and blocked.

Existing function MATCH/code ownership, **object emission**, archive validity,
link completeness, callable/frame ABI and runtime eligibility are separate
fields. Provider/runtime/link/materialization approvals stay false. An ordinary
caller may be eligible for an unresolved object even when a callee/data owner
is blocked. It must expose the unresolved canonical symbol; it cannot masquerade
as a completed link or silently receive a real CRT/game provider.

## Initial eligibility policy

Begin with a selected ordinary native code section whose complete payload is
exactly its checked function span, with supported COMDAT policy, unique selected
entry, understood section auxiliary and no unproved runtime byte range. Preserve
that whole section. No guessed end, instruction splitting, padding stripping or
size truncation is permitted. Initial policy may reject even apparently harmless
unverified padding rather than claiming it was checked.

Additional STATIC labels wholly inside that checked section can retain their
exact offsets as local identities when their record/relocation forms are
understood. A separate function/helper entry or extra alias whose identity is
unproved blocks the section. A future fully covered shared-section group is
possible only with complete ownership of every runtime byte and symbol; do not
extract one function from it. Record unselected/unverified helpers explicitly.

Walk actual associative relationships and all direct runtime references. A
known debug-only child can be dropped with a complete section/association/drop
receipt using the existing narrow proof. Unknown associations or non-debug/EH
children block this initial policy. Actual parent-frame/EH dependencies block
emission until a separately reviewed same-parent closure adapter exists. Do not
let ordinary-body MATCH, passing listed-tail coverage or empty `eh_errors`
certify local handlers, FuncInfo, cleanup pieces or frame coordinates.

For the first policy, selected STATIC roots needing a public export, weak/common
records, unsupported auxiliary forms, unsupported relocation/ordinal formats,
source absolute runtime bindings, unknown directives and TLS/SECREL/compiler
mechanism cases receive explicit blockers. They remain in all-size accounting;
they are not hidden by dropping their records. Later adapters require their own
contracts. Code-only unresolved IAT/CRT/data references may remain canonical
undefined identities when their exact field/base role is already proved.

The **88 original missing fields / 59 functions** are explicit migration
blockers, even though their bodies MATCH. The one compile-only source overlay
is separate candidate evidence and is never substituted into this baseline
pool. No original absolute operand is retained as an executable fallback.

## Canonical linkage without invented providers

Definitions use the selected provider's immutable
`(recipe ID, object hash, original symbol index)` identity. Per-use mappings use
the final binding plan, exact physical symbol index and original symbol-base
identity. Source spellings are observations, never global aliases.

Preserve both final original target and derived original symbol base. Namespace
the **base**, leaving the existing field kind and signed/unsigned addend bits
unchanged. Otherwise a nonzero addend would be applied twice. Conflicting facts
for one physical source symbol block the member; do not clone/rebind fields to
hide the conflict. The final binding metric currently observes zero such
physical-symbol conflicts, despite 760 globally disagreeing source names and
1,484 name/recipe disagreements.

| Reference role | Object/library representation |
|---|---|
| Selected ordinary code entry | Canonical undefined name of that selected physical provider, or a retained definition in this member. A blocked provider stays undefined. |
| Exact known code/local interior | Keep its real local offset if the owner section survives. Cross-member aliases require an explicit owner/offset alias contract; otherwise retain an unresolved interior identity, never a guessed callable entry. |
| Full source literal owner | Retain a complete proved source section under physical/original identity, or leave a canonical undefined data identity. Equal content does not merge original copies. |
| Original data/arena view | Canonical undefined owner/view identity, joined to the data-owner ledger. No source placeholder `.bss` definition or manufactured extent is retained. |
| IAT pointer cell | Undefined **cell** identity preserving pointer indirection and exact DLL/export-or-ordinal/slot evidence; never the function body. Signature/real import-library mapping remains unapproved. |
| Normal CRT candidate/state | Undefined contract identity until the selected runtime owns it. Do not let an old spelling/default library silently establish compatibility or duplicate cookie/exit state. |
| Unknown code/helper/data target | Exact unresolved address-role identity with provenance and blocker. It defines no bytes and contains no numeric fallback. Frame-local EH targets are not covered by this ordinary-reference allowance. |
| Numeric TLS/compiler mechanism | Not an image-address identity; explicit unsupported/special obligation in v1. No allocation for numeric `__tls_array` value 44. |

No C++ wrapper or guessed new prototype is generated. In particular, the allocator
wrapper's source void spelling must not lose the original machine return value.
Defining a namespace symbol in a relocatable object describes retained code;
it does not approve calling that code or choose a runtime ABI.

## Two serialization phases and exact invariants

**Name-only phase:** append strings and update only approved symbol Name fields
and string-table length. Numeric indices, payloads, relocation bytes/addends,
characteristics, values/storage and auxiliary bytes remain unchanged. Reuse the
reviewed physical-name mechanism where its subset is applicable; do not modify
that hash-bound tool to broaden its meaning.

**Selection/serialization phase:** preserve original physical indices as
provenance keys; use a checked old-to-new bijection for retained serialized
section/symbol indices. Every relocation target and index-bearing auxiliary or
association must translate through that map. Retained code/local symbol values,
payloads, flags/alignment, COMDAT policy and known auxiliary fields retain their
meaning. No fake empty sections, tombstones or artificial filler are allowed.
Known metadata such as `@feat.00`/`@comp.id` keeps its real compiler meaning.

Omitted data definitions referenced by retained code need a separately tested
conversion to the exact canonical UNDEFINED external base identity, with zero
undefined symbol value and no storage allocation. Record that definition-to-
reference conversion explicitly; it is not merely a Name edit. It must preserve
all field/addend semantics. Auxiliary-bearing or otherwise unsupported conversion
blocks the member. Do not present a changed storage class/value as unchanged.

Retain original directive bytes only under an explicit complete contract.
Initial batch uses exactly LIBCMT/OLDNAMES defaults. Those defaults are recorded,
not proof of CRT adoption. Name-bearing `/INCLUDE`, exports, alternate names,
entry or other unknown requirements cannot be silently suppressed or replayed
with stale names. Initially block them pending an appropriate rewrite/closure
contract. Likewise, do not retain stale `.sxdata` handler indices while dropping
their handlers; initial non-EH members may only omit unrelated EH/SafeSEH data
with exact evidence that no retained handler depends on it.

Every original source section/symbol has a disposition: retained definition,
retained local record, converted undefined obligation, explicitly omitted
unselected definition/debug record, or unsupported blocker. The drop ledger
names unverified extra code/helpers as unverified, not as harmless garbage.
Their omission is not a missing-source or provider-completeness claim.

## Bounded real-source batch before scaling

The following six exact source identities were inspected as bounded metadata.
The first four are **candidate positives for the new writer**, not emitted or
newly runtime-approved here. Their section payloads exactly equal the listed
spans, all start at value zero, use `no_duplicates`, and have only the ordinary
section auxiliary and external owner. All four have the exact two-default
contract. The only listed associations are known 16-byte debug children.

| Selected original ID | Recipe / native section / size | Outbound fields and initial disposition |
|---|---|---|
| `0x00be0b90` | `0000-674cf48524ad6cf3`, section 13, 4 bytes | Zero runtime fields; debug child 14. Reviewed leaf extraction is a regression anchor. |
| `0x00646d00` | `0703-3a582158246b390e`, section 24, 55 bytes | Three DIR32 fields to two complete eight-byte source literals; retain those exact owners or explicit unresolved literal identities. No child. |
| `0x00aa13e0` | `2734-15835374a1b91660`, section 41, 62 bytes | One DIR32 data obligation to original `0x011f6080`; leave undefined. Debug child 42. No fake manager. |
| `0x00a28740` | `1264-84849a360cbb59fe`, section 3, **614 bytes** | Three DIR32 fields: +19 to `0x010241b0`, +105/+557 to `0x011f3cc0`; leave two data base identities undefined. Debug child 5. |
| `0x0043fd40` | `0802-87f974b83dab6f45`, section 792, 166 bytes | **Block**: actual associated `.text$x` 793 / `.xdata$x` 795 and failed cleanup roles. Do not archive just the passing ordinary parent. |
| `0x00aa0fc0` | `1401-50cd6090ff456b83`, section 3, 25 bytes | **Block**: original missing HIGHLOW source field at +10. The accepted overlay is not substituted. |

The 614-byte quaternion interpolation candidate has no observed EH target in its
three fields or non-debug associative child, and its v3 unit has no textual EH
diagnostic. These are bounded supporting facts, not whole-frame/runtime closure.
It is the useful first move beyond tiny/scalar-only serialization: retain its
complete source code while honestly leaving data linkage unresolved.

The first positive pool is four recipe members containing 735 checked code
bytes, plus the scalar's two 8-byte literal owners if the fixed policy retains
them. It has at least three explicit original-data base obligations and no game
entry-point/initializer scheduling target. Link failure on those undefineds is
expected; do not invent providers to make it execute.

## One concrete implementation contract

Proposed new files: `tools/rebuild/runtime_code_pool.py`,
`tests/rebuild/test_runtime_code_pool.py`, and
`docs/rebuild/RUNTIME-CODE-POOL.md`. A public fixed first-batch policy contains
only source/recipe/section/symbol identities, supported records and expected
obligations; no binary payloads or private paths.

1. Implement authored synthetic COFF serialization tests first: one complete
   ordinary code section, static/interior labels, equal-name/different-identity
   literal owners, signed REL32 and DIR32 addends, long names, section auxiliaries
   and exact association/index remapping. Add negative shared/unverified tails,
   frame/EH/unknown children, missing relocation, placeholder data definition,
   conflicting physical mapping, unknown directive/weak/auxiliary and malformed
   bounds cases. No synthetic game stubs or runtime demonstration is needed.
2. Prove byte/semantic preservation through an independent strict reparse and
   source-to-output section/symbol/field bijections. Test definition-to-undefined
   conversion separately, preserving role/base/addend and rejecting incompatible
   auxiliary layouts. Test stale hashes, missing/duplicate coverage rows,
   output collisions and crash-interrupted publication.
3. After source/schema review, process exactly the four positive and two negative
   real identities above. Emit only the requested positive copied-source sections
   and approved literal owners, with complete dispositions and undefined ledger.
   Fresh unchanged comparison of affected functions must still MATCH under an
   explicit new-name-to-original-identity metadata view; no comparator/flag edit.
4. Build one **standard COFF archive** with one stable recipe member, rather than
   one file per function or a giant object with new format limits. The writer's
   archive index, long names, offsets, padding and export lookup need independent
   format/conformance tests. Do not call an arbitrary concatenation a `.lib`.
   An independently validated member extractor must recover exactly the staged
   objects/hashes and a complete expected export index. Native inspection, if
   needed for conformance, is a separately authorized review step; never a link
   or execution requirement disguised as validation.
5. Only after this bounded writer passes, run **all-size accounting** over every
   selected owner and exact native section, serially by recipe. Emit one status
   per address with complete reason sets, section/association/relocation facts,
   code/data/EH obligations and original missing identities. No 255/511 budget,
   size-based skip, broad archive search or baseline recompilation applies.
   Reconcile exactly 68,657 selected owners and 68,667 checked rows. Keep all
   10,455 previously reported unverified extra bodies visible as background
   scope, not borrowed checked providers; exact native disposition wins over
   assuming that historical count applies to this selected subset.
6. A later root-approved all-eligible build can serialize one recipe at a time to
   a private spool and one archive writer. Keep only a bounded number of objects
   in memory; avoid 68,657 small filesystem artifacts, concurrent journal scans
   and per-function compiler invocations. A failed run preserves an fsynced
   progress/member ledger and never overwrites a reviewed archive. Stage final
   archive plus compact receipt and compressed complete coverage/obligations;
   consumers require matching hashes, not mere file existence.

Archive completion is a tangible source-linked CODE artifact, even while many
external identities remain unresolved. A future linker consumer must check exact
member/root selection, data/CRT/TLS/import/EH providers and every undefined role
before any executable is attempted. Global initializer code in a pool is not
permission to retain/execute an old `.CRT$XCU` array. No startup, fake successful
link, `/FORCE` workaround, copied game code, original-address fallback or new
runtime provider is part of this first contract.

## Exact evidence and remaining uncertainties

| Input | SHA-256 |
|---|---|
| Authoritative recipe | `62f2c8da5f0daa912abdf4576328706711c6561eef7f01c93a89cb71ad46fb6c` |
| Retained manifest | `bc62a5fb2553431b1e0547d11f366e52efb73096ea8ceb206c556ae5740a53eb` |
| Full retained v3 proof | `04d44b73e81982f846bfe8d81806db72ea669586b579ff22007dfd6f7d831297` |
| Selected owners v2 | `48ae62cdc5b1754b9c4af674ef4716d53afb554882e174a93acf860eaf1c6cb1` |
| Final binding v2 / detail | `275714631903758efbf5a4f82e2428c6f51838f53b90d0c56d2e5dec5da1d804` / `4dfc437064b16c1bb933008aebf7def8d279a903eef9cca24d0fedcc12d7d826` |
| Data-owner v1 / detail | `fac1496a2675e9a6b697d604c8d5b35a2e4b8bb6194e2ec823e5a37d1092f2e8` / `c54abfd434ac715a16d31711fa8afb498d4b41420bec3bfcc25347d0eab9bd08` |
| EH parent-role v1 | `1e08ae8a908dc0a9d7feba4e5fa3cbcfe3a5f9ed6be3004ed6ac8639497fd788` |
| Owned reference identity | `df1788907c6e26ef4df0b448ead526825336356b5606650165a1ce0825097eb7` |
| 614-byte candidate object | `89e780f4b8dfcb2e7a17e761da8bf556e67162b0603b22dfd542bcef9ea31f8f` |
| 614-byte candidate source | `9134a34b9d81951d72ffa2bcde18b2c3be348399ffb090fc9cf975302057fe10` |

The 614-byte source is
`src/gamebryo2.2/corelibs/nianimation/nirotkey.cpp`. Its actual external owner
symbol index is 8; section-definition index 6 has the ordinary section auxiliary.
The other batch objects retain their hashes in the reviewed leaf/scalar/allocator,
EH parent and source-overlay records; this task rehashed the six exact objects
while inspecting their metadata. No new whole source/object scan occurred.

Remaining decisions are bounded: archive index conformance; the precise
supported label/auxiliary subset; definition-to-undefined conversion; complete
all-size eligibility counts after implementation; and independent validation of
all exported/interior identities. Whole-game data/EH/CRT/TLS/ABI and missing-field
closure remain unresolved linkage/runtime obligations, not reasons to fake a
complete executable or to postpone all relocatable code retention.

Independent proposal review is pending. The current data ledger's 95 EH notes,
33 false local-piece warning, optional-index absence, unadopted overlays and all
runtime/provider/materialization flags remain unchanged.
