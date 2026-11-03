# Constructor EH typed-view repair proposal

Scope: read-only planning for recipe 802 constructor `0x0043fd40` only,
November 3, 2026. **A runtime repair is not ready.** Static evidence establishes
the ordinary receiver save, normal member-construction offsets and, for the exact
previously selected fixture CRT, the cleanup frame-coordinate algebra below. It
identifies two different destruction behaviors. It does not establish the original
game CRT implementation identity, complete replacement class layout, nonthrowing
rollback contracts or an eligible game runtime provider set. No source/type overlay, object rewrite,
compilation, linking or native execution occurred.

The finalized [parent/state-role producer](EH-PARENT-ROLES.md), its tests and its
receipt are unchanged. Unit 2761 remains negative background evidence and is not
part of this repair proposal.

## Incoming receiver and two frame coordinates

The actual hash-checked 166-byte parent decodes completely into 50 instructions.
Its ordinary control flow is straight-line, with five direct constructor calls
and no conditional branches. Bounded register/stack dataflow, starting with the
incoming member-call receiver in ECX, establishes:

| Native parent offset | Observed semantic fact |
|---:|---|
| +1 | Establishes its ordinary EBP frame. |
| +35 | Saves the incoming ECX receiver to ordinary `[EBP - 16]`, before any constructor call. |
| +45 | Calls the base constructor with the same receiver. |
| +83 | Calls the first member constructor with receiver +`0x2c`. |
| +100 | Calls the common SubObjB constructor with receiver +`0x30`. |
| +117 | Calls the common SubObjB constructor with receiver +`0x34`. |
| +134 | Calls the final member constructor with receiver +`0x38`. |
| +163 | Returns the original receiver in EAX and removes eight stack-argument bytes. |

Thus **incoming receiver -> ordinary EBP-16 is proved** for this retained parent,
rather than inferred by searching for a plausible store. The dataflow tracks
instruction boundaries, stack/register expressions and caller-clobbered registers;
unknown operations invalidate affected facts. Complete extent and branch checks
bound this observation to the selected parent, not adjacent code.

The previously reconciled local cleanup forms separately load their receiver from
**unwind EBP-16**, adding `0x30` or `0x34` before tail-jumping to the destruction
action. Ordinary EBP and unwind EBP are different coordinate concepts. Their equal
spelling and displacement do not prove that the CRT establishes the same value.
The 27-byte local handler loads its establisher argument from stack +8, forms an
establisher-relative address at +12, reads a value at establisher -8 for its cookie
check, and transfers to the selected C++ frame handler. That handler stub does not
itself establish the local funclet EBP in the inspected range.

**For the original game dispatcher, the complete incoming-receiver -> unwind-slot
chain remains unproved.** The follow-up below statically traces the exact selected
fixture CRT, rather than inferring its convention solely from the earlier fixture
execution. That establishes a selected-runtime compatibility equation, not the
original game CRT implementation or a whole-component execution proof. Existing
finalized report flags remain unchanged.

## What the compiler output says about the member layout

`modelloader.cpp:11565-11610` declares a polymorphic base, nine integer base
fields, an integer `m_28`, and members `m_2c`, `m_30`, `m_34`, `m_38`, each with one
integer storage field in its declared helper type. Its initializer list names
those four members in that order. There is no local packing pragma in that
translation unit. Source field names alone are not a layout proof.

The actual compiler output supplies the missing normal-construction evidence:
the ordered member calls use the saved incoming receiver plus `0x2c`, `0x30`,
`0x34`, `0x38`, respectively. Both middle calls resolve to original `0x00633c90`,
use the same native external constructor spelling, and pass zero. Together with
the exact source initializer order and the same-object matched parent proof,
these observations support **normal construction of `m_30` at +0x30 and `m_34`
at +0x34**. They do not establish their complete original C++ type identities.
Unwind-to-source member assignment in the original game remains conditional on
its separate dispatcher contract. The selected-CRT convention below supplies a
conditional coordinate mapping for a future runtime using that exact provider;
it does not alter the finalized evidence report or certify complete type identity.

There is no saved `sizeof`/alignment/compiler layout diagnostic for a replacement
type view. A common four-byte spacing is not permission to assert every size,
alignment, padding, parent/vtable layout or lifetime contract. This proposal
therefore requires a source/layout-only compilation gate before any typed-view
implementation could be accepted.

## The two destruction actions are different operations

Both original destinations have exact recipe-listed, byte-verified function rows
in the retained v3 receipt. These are candidate body identities, not selected
runtime providers.

| Destination | Provider candidate | Bounded call/body contract |
|---|---|---|
| `0x0040c110` | Recipe 791, `magicitem.cpp`, 29 bytes; source is a one-argument `__fastcall` free function | Receives the wrapper address in ECX; never reads EDX; consumes no stacked argument. Reads the pointer at wrapper +0, skips null, otherwise calls `0x0040c130` on that pointee. No result is consumed by the cleanup. |
| `0x0045cec0` | Recipe 386, `actormover.cpp`, 29 bytes; source is a no-argument `__thiscall` member | Receives the wrapper address in ECX; never reads EDX; consumes no stacked argument. Reads the pointer at wrapper +0, skips null, otherwise calls `0x00401970` on that pointee. No result is consumed by the cleanup. |

Both wrappers have a normal prologue/epilogue and a single conditional null path.
They remove zero argument bytes on return. Their unrelocated native payloads are
identical, but their outbound relocations differ. At this narrow machine-call
boundary the free-function fastcall spelling and member thiscall spelling use
compatible ECX/no-stacked-argument transport; this does not establish C++ type
identity, pointer lifetime, exception behavior or a general alias rule. A
runtime-only declared member destructor must not silently become a globally
aliased fastcall function because these two rows happen to match in shape.

The exact outbound source/body candidates explain the semantic difference:

| Action body | Evidence and limit |
|---|---|
| `0x0040c130`, recipe 2628, 26 matched bytes | Passes pointee +4 to bound `0x004019a0` and returns the result. The bounded body contains no conditional destruction callback. |
| `0x00401970`, recipe 633, 43 matched bytes | Calls the same bound `0x004019a0` on its reference field at pointee +4, then calls virtual slot +4 when the result is zero. The exact pointee/vtable/callback lifetime and nonthrowing behavior are unresolved. |
| `0x004019a0`, recipe 633, 15-byte matched row | Its source returns `InterlockedDecrement(value)`. The `WaitForSingleObjectEx` spelling used by a source declaration is misleading; no wait semantics are adopted. This primitive was not independently decoded in this task. |

The first role decrements without the second role's zero-count virtual action.
Replacing one with the other would change lifetime behavior. Neither wrapper
clears its pointer member in its bounded source/body, so blindly invoking both
or replaying rollback is not idempotent. Their null branches do not establish
validity for non-null pointees or safe exception propagation during unwinding.

## Shared construction does not unify destruction or prove ICF

Both normal middle-member calls target `0x00633c90`. Its exact candidate is recipe
253, a matched 42-byte constructor that stores one pointer and, for a non-null
input, calls `0x0040f6e0`. Its return removes four argument bytes. The current
parent supplies zero. The non-null helper's full semantics were not inspected
and are not certified as retention merely from the surrounding type names.

One shared original constructor address is compatible with common construction
behavior for distinct source views. It does not prove original source type
identity or that linker identical-COMDAT folding caused the sharing. Conversely,
the two destruction wrappers' identical unrelocated payload fingerprints do not
make them foldable equivalents: their relocation targets lead to different
operations. No linker ICF decision or type unification is authorized here.

## Parent lifetime constraints remain attached to the parent

The constructor records unwind states only after successful base/member calls:
state 0 after the base, then states 1, 2 and 3 after the first three members. It
resets to -1 after the last member returns. The four-state map is complete; a
fifth state is not missing merely because a fourth member is named in source.
A failure during construction of `m_34` leaves state 2 and must destroy completed
`m_30` before earlier completed subobjects. A failure in the final member leaves
state 3 and must destroy completed `m_34`, then `m_30` and earlier subobjects.
An incomplete member is not destroyed as a complete object.

The local cleanup frame/state machine, handler, FuncInfo, unwind transitions and
cookie checks must stay compiler-owned. Do not turn the local cleanups into
ordinary independently callable functions. Current zero constructor inputs make
null wrapper states relevant, but do not justify discarding later pointer or
rollback contracts. This scoped plan does not prove all future writes or the
normal complete object's destruction path.

The `m_2c` cleanup still has its separate preserved `SubObjA` binding failure,
and the base/member/vtable closure is not a selected runtime component. Fixing
the two SubObjB roles would not make the whole parent strictly verified or linked.
Those residual failures must remain visible.

## Selected CRT frame-coordinate follow-up

A bounded read-only follow-up used the exact normal CRT providers already linked,
reviewed and executed in the original EH fixture. It did not rebuild or rerun that
fixture. The normal executable and map were rehashed against its reviewed
`prepare.json`; the current `LIBCMT` file agrees with its recorded hash
`bd9700d126d378f31f32736abc0c88cb08a8e0f0914acb6e2c8cbfd1ab99f411`.
The map identifies exact members, so no archive search/extraction was needed:

| Relevant mapped range | Member | Bound | Coordinate evidence |
|---|---|---:|---|
| `___CxxFrameHandler3` | `_trnsctrl_.obj` | 54 bytes | Forwards its registration-node argument unchanged into the internal handler. The adjacent catch guard is not treated as this function. |
| `___InternalCxxFrameHandler` | `frame.obj` | 230 bytes | Its unwind call forwards the same node as the first argument to `___FrameUnwindToState`. |
| `___FrameUnwindToState` | `frame.obj` | 225 bytes | Loads that argument into EBX at +15; EBX is passed as argument two at +119; the loop-path reload at +150 and a later reload at +192 obtain the same registration argument. It is forwarded to `__CallSettingFrame@12`. The callback comes from the unwind-map action field. |
| `__CallSettingFrame@12` | `lowhelpr.obj` | 76 bytes | At +27 establishes callback EBP as registration node +12; calls the cleanup through its first argument at +37. |
| `__SEH_prolog4` | `sehprolg4.obj` | 69 bytes | Confirms the unwind routine's argument/frame coordinate after its prolog helper; ordinary EBP is entry stack pointer -4. |
| `__NLG_Notify1` and its internal continuation | `exsup.obj` | 40 bytes | The reachable notification path preserves callback EAX and unwind EBP, restores its saved registers and removes its four-byte notification argument. It therefore does not break the setup before the indirect cleanup call. |

The prolog helper was followed because the unwind routine calls it, rather than
assuming the routine had an inline ordinary prolog. Its call sequence places the
helper entry stack twelve bytes below the routine entry stack; the helper
establishes EBP eight bytes above its own entry stack. Thus body EBP is routine
entry stack -4, and body `[EBP + 8]` is the first incoming argument. This supplies
the missing argument-coordinate justification for EBX's node value.

Both the actual unit 802 parent and the fixture constructor publish their
registration node to FS at parent offset +29 as **ordinary EBP -12**. Their
27-byte unrelocated local handler payloads agree; cookie/FuncInfo/frame-handler
relocation fields have the same relative roles. Their FuncInfo state counts
differ, as expected, but this frame setup does not depend on the state count.
The forwarding chain relies on the ordinary x86 callee-saved register contract:
intervening normal subcalls preserve EBX/EBP and other nonvolatile registers as
required by their interfaces. The bounded inventory of writes in the caller alone
cannot prove that arbitrary callees honor this contract. Not every transitively
called CRT helper was independently audited, and no such whole-library claim is
made. The specific notification preservation and frame-setting sites above were
checked directly. **Under that explicit ABI preservation assumption**, the selected
CRT's frame setup gives:

```text
registration node = ordinary EBP - 12
cleanup EBP       = registration node + 12
                  = ordinary EBP
cleanup slot -16  = the parent's saved incoming receiver slot
```

This closes the **conditional static selected-CRT convention** gap for the
inspected compiler form, under the stated normal ABI preservation assumption. Combined with the verified ordinary receiver save, the +0x30/+0x34 cleanup
adjustments correspond to those normal member starts **if the future runtime
uses that exact reviewed CRT and registration/handler form unchanged**.

It does not prove the original game's frame-handler implementation is identical,
that its dispatch path follows these exact library members, or that an unresolved
game component can execute correctly. The original handler's external name and
an unrelated successful fixture are insufficient for that historical claim. The
bounded chain stops here: original-game CRT implementation/placement proof,
whole-component lifetimes, provider eligibility and live game rollback remain
unproved. The finalized parent-role report's false flags are not retroactively
changed by this proposal.

The original mapped scan of `FrameUnwindToState` extended 69 bytes beyond its
225-byte COFF section into adjacent
`?ExFilterRethrow@@YAHPAU_EXCEPTION_POINTERS@@@Z`, also from `frame.obj`. That
separate function begins at fixture `0x00403909` and ends at
`___DestructExceptionObject`, `0x0040394e`. No essential coordinate fact depends
on those 69 bytes: the registration load, callback call, both later reloads and
loop backedge all lie within the first 225 bytes. Final evidence distinguishes
the two owners and does not call that adjacent region part of the unwind routine.

Final relevant decoding is 1,014 bytes: 694 selected CRT bytes plus 320 parent/
fixture prolog-and-handler bytes. Nonessential mapped-neighbor inspections
account for another 184 unique bytes, making **1,198 unique bytes under a fixed
1,536-byte bound**. No broad code/archive enumeration, original game CRT body hunt or raw
instruction publication occurred.

The exact semantic follow-up is private
`build/rebuild/eh-frame-coordinate-v5.json`, 9,021 bytes, SHA-256
`8e93fd86e652d195fa8a68a4609a58c02d22e9e0af1357c75715b8fb0010f207`.
It binds fixture executable/map/library identities, unit 802 object and prior
parent-role evidence; it contains ranges, pointer/argument algebra and semantic
observations, not instruction payloads or personal paths. The preliminary v1-v4 observations are
preserved. V5 retains the explicit intervening callee-saved ABI assumption and
separately identifies the nonessential adjacent filter range, alongside the
loop-path reload evidence and reachable notification-preservation summary.

Independent follow-up review verified the final v5 hash and ownership split,
matched the named archive members to mapped fixture code outside relocations,
and checked the essential call/argument/loop/prolog/frame/notification algebra
plus both parent/fixture registrations. Acceptance is for separately assigned
compile-only research under the explicit nonvolatile-callee ABI assumption.
It is not a transitive helper audit, original-game dispatcher proof or runtime
repair approval.

## Earliest useful compile-only typed-view experiment

Unproved original-game unwind execution must **not block pure source-comparison
research**. The following experiment needs no live rollback proof or provider
adoption. It is the smallest next implementation contract, subject to independent
source/schema review and a separate root assignment.

Use a new private, hash-bound runtime-only source/header slice for this exact
constructor. Preserve original parent/base identity, arguments and initializer
order. Change only the declared member views for `m_30` and `m_34` into two
separately named, nonpolymorphic views. Each has a declaration-only constructor
with the current one-stack-argument member-call shape and its own declaration-only
destructor. Retain the existing storage declaration initially; its meaning is not
silently upgraded into an original pointer type. Do not inline an adapter, add
provider bodies, add `throw()`/nothrow annotations, repair `SubObjA`, or edit the
original translation unit or recipe.

The private comparison ledger may bind both new constructor names to the existing
original `0x00633c90` identity, while binding the two destructor names separately
to `0x0040c110` and `0x0045cec0`. This is **reference-comparison metadata only**;
it must never be passed to a runtime linker as an automatically approved alias
plan. All actual runtime eligibility, ABI adoption, lifetime and link flags stay
false even if the source comparison improves.

| Gate | Before | Required experiment result |
|---|---|---|
| Ordinary parent | Exact 166-byte MATCH under the original recipe. Both middle constructor calls resolve to `0x00633c90`. | Same extent, instructions, stack/result behavior and original relocation destinations under explicit private comparison bindings. No extra wrapper/thunk/call. |
| Two targeted cleanup actions | Both use one `SubObjB` destructor spelling; global binding `0x00488ff0` disagrees with original `0x0040c110`/`0x0045cec0`. | Two separately named actions resolve to their respective original destinations, with the same local receiver slot and +0x30/+0x34 adjustments. Their ordinary code plus relocations must compare, not just their target numbers. |
| State/metadata graph | Four states, five local pieces, preserved handler, FuncInfo and cookie behavior. | Preserve all states/transitions, associations, complete non-relocation table content and pointer fields. No omitted child or independently invented funclet. |
| Other local failures | The `m_2c`/SubObjA binding failure remains unresolved. | Preserve and report it. Two targeted improvements cannot be relabeled a strict whole-parent MATCH. |
| Runtime eligibility | False. | False: no provider adoption, linking, native execution or game closure claim. |

Compile with `/c` only, exact existing SP1 identity/recipe flags and one coordinated
compiler job. Record input/source/header/compiler hashes, exact commands, output
hashes and comparison evidence in new exclusive private artifacts. Compile-time
size/alignment/member-offset checks or equivalent native compiler layout evidence
must show that both views preserve the baseline normal member starts. Obtain
complete parent/base size, alignment and padding evidence; four-byte spacing or a
field name alone cannot pass. If compiler diagnostics cannot establish this,
stop and report that layout gap rather than guessing allocation sizes.

Use the original comparison functions unchanged. Ordinary comparison must remain
MATCH. The expected bounded improvement is exactly two targeted failed cleanup
pieces becoming matching, while the existing SubObjA failure remains: the
constructor goes from three failed local pieces to one, never to an unqualified
strict-local pass. Stop if another piece changes or an additional diagnostic
appears. The EH result must separate the two targeted actions, complete metadata,
all other pieces and preserved failures. Fail closed on changed ordinary output,
layout, target transport, merged destructor identity, lost transitions, altered
cookie/handler policy or hidden new references. Do not weaken the overall strict
local gate to make a targeted experiment appear complete.

If this succeeds, it establishes a feasible **compile-only source view**, not a
runnable repair. A later runtime assignment must still review actual provider
bindings, pointee/virtual-call lifetime and nonthrowing destruction contracts,
original-vs-selected CRT policy, the residual SubObjA failure and full closure.

## Exact private evidence

The final semantic machine evidence is private
`build/rebuild/eh-runtime-repair-static-v4.json`, 16,511 bytes, SHA-256
`e6b743fcd282e8f6920036e2a9fec8ad5a88887706dd95573c2e198956e97aa5`.
It contains input/decoder hashes, complete bounded decode extents, semantic
register/frame/call observations and matched provider identities, without raw
instruction bytes, disassembly strings or private input paths. Earlier private
v1-v3 observations remain preserved; v4 explicitly avoids overstating the
uninspected constructor helper's semantics.

| Input | SHA-256 |
|---|---|
| Reconciled parent-role report | `1e08ae8a908dc0a9d7feba4e5fa3cbcfe3a5f9ed6be3004ed6ac8639497fd788` |
| Retained v3 receipt | `04d44b73e81982f846bfe8d81806db72ea669586b579ff22007dfd6f7d831297` |
| Retained manifest | `bc62a5fb2553431b1e0547d11f366e52efb73096ea8ceb206c556ae5740a53eb` |
| Unit 802 object | `678bb9bf0aad418bdd58cb1e252282bad07537b24037e3ae7f2ff97145b52cc0` |
| Unit 791 object | `d58cd19fcabfc888fc2ac4a67664768b125a6a0e5fecff1c4c603ac0342a8409` |
| Unit 386 object | `e707c4c67a75efef32342cef03b11f7faf0a2188fe19733e1c4c90a5bd99503c` |
| Unit 2628 object | `9a193059d9e5042721cb7962cf0ab86be535ba8f890d1a3258101d51ed7b7ae6` |
| Unit 633 object | `31a2a98ae9fe7d96d7a77e9d5366f3785261b1ffecc3cc0706db1c31f64824c2` |
| Unit 253 object | `0ebbc5c1b782db36699b48132a9360df811123a7b446148c56a1f61f9bf3aa48` |

All six exact source/object observations were rehashed against the manifest;
the saved ordinary row proofs are from the pinned v3 receipt. The reference-image
hash agrees with v3. Original producer hashes and absent-index state were checked.
A bounded decoder inspected only the 166-byte parent, two 29-byte wrappers,
26/43/42-byte named outbound bodies and 27-byte local handler: 362 bytes total.
No generic code hunt, source/type modification, binary rewrite or execution
occurred. Independent review is required before assigning any repair work.
