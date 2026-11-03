# EH closure pilot: one constructor and its native dependency graph

Read-only audit, November 2, 2026 (America/Chicago). Reference baseline `87eb937`, retained run
`20261103T030230Z-7cfc935c`. This audit changes no source, recipe, comparison
logic, object or image, and performs no compilation, extraction, link or execution.
The proposed next implementation requires a separate assignment. Current
`coff_extract.py` remains restricted to its reviewed zero-relocation leaf case.

## Selected evidence

Recipe `0069-3b6fc41592bb705f` owns `IOTask::IOTask(IO_TASK_PRIORITY)` at
`0x00440540`, 101 bytes. Source is `src/bsmain/bstaskmanager_h_unit.cpp`, including
`bstaskmanager.h` and `bstaskmanager_types.h` beside it. Its SP1 flags are
`/MT /Od /Oy- /GS /EHsc /Gy`. The retained object SHA-256 is
`4e7ad6d343e1abc45e1ef23eb96436174032d7cdd5a0c69b2f0748bd8b37607b`;
this audit rehashed that exact manifest-selected file. The full retained v3 receipt
SHA-256 was rechecked as
`04d44b73e81982f846bfe8d81806db72ea669586b579ff22007dfd6f7d831297`.
Its exact parent row is section 3, value zero, size 101, verdict match, with no
local EH diagnostic. Two matched pieces cover its listed 35-byte tail:
`[0x00eec240,0x00eec248)` and `[0x00eec248,0x00eec263)`.

Source constructs `BSTask<__int64>` first, then calls `SetIOTaskPriority`.
If the latter throws after successful base construction, compiler-generated
unwinding destroys the base. There is no source catch block in this constructor.
The local cleanup is not a separately callable ordinary game function.

## Native section and relocation closure

All entries below are observed in the actual retained COFF; offsets identify
relocation fields, not proposed fixed runtime addresses.

| Section | Native identity | Dependencies and obligation |
|---|---|---|
| 3 | `.text`, 101 bytes, no-duplicates COMDAT; constructor at +0 | DIR32 +6 to section 4 handler +8; DIR32 +19 security cookie; REL32 +42 base constructor; DIR32 +58 IOTask vtable +4 in section 5; REL32 +70 priority setter. |
| 4 | `.text$x`, 35 bytes, associative child of 3 | Local unwind funclet at +0, local handler at +8. REL32 +4 base destructor; REL32 +21 security check; DIR32 +26 FuncInfo at section 6 +8; REL32 +31 `___CxxFrameHandler3`. |
| 6 | `.xdata$x`, 44 bytes, associative child of 3 | Unwind map at +0, FuncInfo at +8. DIR32 +4 to section 4 cleanup +0; DIR32 +16 to section 6 unwind map +0. |
| 16 | `.sxdata`, four bytes, non-associative | Contains COFF symbol index 19, the local handler. This is an index record, not an ordinary relocation or game address. Rebuild its index if symbols move. |
| 5 | `.rdata`, 36 bytes, largest COMDAT | Vtable symbol starts at +4; preceding slot references the complete-object locator. Eight virtual slots follow. It is reached by the parent and cannot simply be dropped. |
| 7-15 | Compiler-emitted RTTI data COMDAT graph | Complete-object locator, two type descriptors, hierarchy descriptors, base arrays and base descriptors; reaches external `type_info` vtable. Preserve type identity and canonical ownership. |
| 17 | `.text`, 44 bytes, any COMDAT | Scalar deleting destructor; calls IOTask destructor and deallocation. Reached through weak vtable slot selection, not through a parent direct call. |

The object has only the understood `LIBCMT` and `OLDNAMES` default directives.
Sections 4 and 6 are real associative runtime children, unlike the debug-only
child accepted by the existing leaf extractor. Section 16 has no association
edge, so walking only associative children misses handler registration.

The deleting-destructor vtable relocation targets a weak external with search
mode 2 and fallback to the scalar deleting destructor. The object also defines
that fallback in section 17. Preserve or explicitly resolve the weak record and
its auxiliary symbol index; do not substitute the weak symbol with a guessed
ordinary name. The local handler/FuncInfo/unwind-map symbols have static storage
class and offsets inside their sections. They must remain internal to this
parent closure, even when an original-address alias appears elsewhere.

## Metadata verification beyond the existing code receipt

The unchanged oracle uses handler references to locate `.xdata` and reads its
pointers to locate cleanup pieces. Its successful tail comparison does not
compare every EH data scalar or prove linked metadata semantics. This audit
therefore separately followed the selected handler's DIR32 reference into the
owned reference image: it identifies the 44-byte table at `0x011401cc`.
Every non-relocation byte of that exact table agrees with the emitted COFF.
Its two pointer fields point respectively to the matching cleanup and the same
unwind map. Decoded structure has one unwind-map entry, no try blocks, no try
map, and EH flags value 1. There is no catch-handler array to invent for this
pilot. These are bounded observations, not a general x86 EH decoder or a new
hash-bound extractor receipt.

The matching cleanup must execute with its parent's compiler-established frame,
saved `this` and unwind-state transitions. Rebinding it as an independent normal
C++ function discards that contract. The handler, cookie check, FuncInfo and
unwind map belong with the source-built parent. They should be emitted from
that retained compiler output, with relocations resolved to the new layout;
old PE copies of those tables must not coexist as a second metadata owner.
The selected new CRT supplies its own security cookie/check and frame-handler
implementation. Keeping original CRT addresses is not an acceptable provider.

## Vtable, RTTI and external provider boundary

The original vptr binding is `0x01016c10`; the complete table interval begins four
bytes earlier. A bounded pointer read confirms eight virtual slots. The two
`Run`/`Finish` slots share `0x00ec60fa`, which has no selected ordinary recipe
function in this manifest; its CRT/provider identity remains unresolved here.
Other slots identify `0x00440610`, `0x008d0600`, `0x008d0300`, `0x00483710`,
`0x0043db70` and `0x00440660`. There are existing recipe-listed, byte-verified function candidates for
these addresses, sometimes with very different source type/method spellings.
Those rows are candidate observations, not approved ABI aliases or selected
runtime providers.

The original complete-object locator leads to an IOTask hierarchy with two base
entries. Bounded checks found the emitted type-descriptor non-pointer content,
hierarchy non-pointer fields and both 28-byte base-descriptor non-pointer fields
agree with their corresponding original data. Both emitted type-descriptor
non-pointer tails also agree. This supports these particular source identities;
it is not a complete relocated RTTI/vtable equality proof. All pointer edges,
COMDAT duplicates and the CRT `type_info` provider still need canonical selection.

The header asserts a 24-byte base and derived object, with base fields at +8,
+12 and +16. The existing base-constructor source writes those same offsets.
These facts support the observed local layout, but do not certify all virtual
signatures, complete game type identity or storage lifetime. In particular,
source method names differing from original roles cannot authorize arbitrary
reinterpret-cast dispatch.

Three immediate code dependencies already have recipe-listed, byte-verified
function candidates in recipe 802 (`src/fallout_shared/modelloader.cpp`), whose retained object hash was checked
as `678bb9bf0aad418bdd58cb1e252282bad07537b24037e3ae7f2ff97145b52cc0`:

| Original target | Existing provider | Remaining boundary |
|---|---|---|
| `0x00449090` | 73-byte base constructor, section 162 | Source provider is fastcall with object in ECX and no used EDX argument, unlike the caller's member spelling. References base vtable `0x01017138`, persistent global `0x011c3b38`, and `InitScriptRunLock` at `0x0040b460`. ABI/layout and initialization need review. |
| `0x004490e0` | 33-byte base destructor, section 574 | Inferred destructor target is supported by the matching cleanup receipt. Provider restores the base vptr and calls `FinishScriptRunLock` at `0x004019a0` using the same persistent global. A destructor alias still needs explicit ABI approval. |
| `0x004405b0` | 26-byte priority wrapper, section 117 | Existing provider takes unsigned char rather than the caller's enum; forwards to `0x004405d0`. Prove argument width/extension and transitive behavior before selecting. |

Thus the parent is a useful audit root, but is not yet a small runnable game
slice. Real base/global/vtable lifetimes and additional code providers remain
open. A stub base, fabricated vtable, zero-filled lock global or throw-injected
game method would produce different evidence and cannot demonstrate game closure.

## Next implementation contract for coordinator assignment

First add a separate, deliberately narrow EH closure operation; do not relax the
existing zero-relocation API. Initially admit only an entirely original native
fixture: a whole-function x86 constructor COMDAT, its exact `.text$x` and
`.xdata$x` associative children, explicit `.sxdata` handler records, understood
directives and required symbols. Accept only reviewed DIR32 and REL32 runtime
references, with an explicit provider ledger. Preserve code/data payloads,
addends, static symbol offsets, section characteristics, association indexes and
COMDAT policy. Rebuild all section/symbol/auxiliary/relocation indices and handler
index records; reparse independently. Reject unknown metadata, unsupported
relocations, omitted runtime children, cross-parent local funclet binding,
weak/common symbols outside scope, cycles, shared sections, TLS, initializers,
unknown directives, unresolved providers and input/output collisions. Produce
new exclusive hash-bound outputs and a complete retention/drop/external ledger.
This is a proposal, not authorization for general runtime/data extraction.

Use an original nonpolymorphic fixture base with an observable constructor and
non-inline destructor, and a derived constructor calling a separately compiled
operation that can throw a typed original exception. This avoids falsely claiming
that a fabricated game class/vtable has been recovered. Compile with the selected
VC9 SP1 `/EHsc /GS /Gy` policy, preserving an actual compiler-generated cleanup,
handler and unwind map; first inspect that output matches the proposed supported
shape. Link through normal CRT startup with real library EH/security providers.
Do not hand-write an unwind funclet or insert assembly.

Acceptance evidence must include:

1. Successful construction followed by explicit destruction: one base constructor,
   one base destructor, expected body results, no exception observed.
2. Throw after successful base construction: caller catches the same typed payload,
   exactly one base rollback destructor, no derived-destructor call, and a
   post-catch sentinel proving continued execution.
3. Base-constructor throw: no base destructor for that incomplete base and no body
   call. Repeat paths to catch state/stack corruption; verify counts and object
   sentinels, not just process exit.
4. Independent inspection of link map, selected payloads/relocations, relocated
   FuncInfo/unwind targets, `.sxdata` handler resolution and real CRT providers.
   Force a second layout/base and rerun: no original fixed addresses may survive.
5. Fail-closed synthetic cases for altered association, missing cleanup, wrong
   handler index, metadata relocation outside retained closure, unsupported kind,
   stale proof/hash and foreign-parent local symbol. Preserve original inputs.

Fixture success would prove narrow EH extraction/link mechanics only. Before
applying it to this IOTask parent, assign a separate extension covering its real
vtable/RTTI/weak/deleting-destructor graph plus all external providers above,
with bound metadata equality and ABI/lifetime evidence. No game execution is
justified until that complete graph is approved. This audit performs no extra
unknown-code decoding; the separate 64-target generated-code sample remains the
only authorized sample and cannot be extrapolated into independent new functions.
