# Original loader-owned TLS fixture

This fixture implements the original-source experiment in the
[TLS owner proposal](TLS-OWNER-PROPOSAL.md). It accepts no game image, emits no
game template or provider aliases and executes no game getter. Its flag 1 and
context 37 are authored fixture values, not original game initialization.
Existing hash-bound DATA/scalar/leaf/EH/binding tools remain unchanged.

## Authored storage and normal infrastructure

The header declares one align-4, 704-byte POD storage owner. Compile-time checks
bind its complete extent and flag/context offsets `0x264`/`0x2b0`. All reserved
fixture arrays are explicitly authored zero storage. Only `tls_owner_storage.cpp`
defines this thread variable. Other source files refer to that same allocation.

Normal SP1 `LIBCMT:tlssup.obj` remains the sole provider of the loader index,
directory, start/end markers and callback sentinels. The named normal CRT
`atlssup.obj` supplies the absolute `__tls_array=44` mechanism constant. The
tool rechecks the reviewed member hashes and actual metadata; it defines no
replacement TLS directory, index or CRT marker.

The intended layout remains conditional until preparation proves it: one-byte
CRT start marker, three alignment bytes, source owner at template +4 and a
one-byte excluded CRT end marker at +708. Only if actual COFF/map/PE evidence
agrees do owner fields occupy template-relative `0x268` and `0x2b4`. Incorrect
extent, alignment, an additional contribution or a shifted owner fails closed.
The fixture does not infer a complete game class or template from this layout.

`FixtureModuleBlock` uses the actual VC9-declared `__readfsdword` intrinsic and
the normal loader-owned index, without handwritten assembly. Source thread
field accesses use the compiler's normal SECREL mechanism. Runtime checks
compare the independently obtained module block, owner and both field addresses
and values. Preparation verifies each actual selected source TLS relocation:
DIR32 index references point to the new index cell, `__tls_array` references
remain numeric 44 without base relocations, and SECREL operands equal the
actual +4 owner position plus the field addend.

## Loader notifications and independent threads

One original callback pointer in `.CRT$XLB` lies between the normal opening and
closing sentinels. Callback code uses bounded POD storage and Win32 calls, no
CRT heap, formatting, allocation or loader APIs. It records process/thread
reason, thread ID, index, owner/field offsets and values. Process attach also
sets error-dialog policy for this child process only.

The normal CRT constructor must observe the complete authored initial state,
the correct aliases and the earlier process-attach callback. Main writes its
own flag/context, starts two simultaneously alive workers, and checks that
both workers receive fresh initialization, distinct block addresses, the same
module index, correct source/direct-block aliasing and independent writes.
Ready/release events keep workers alive together; main's TLS and caller sentinel
must remain unchanged while they run. Worker attach/detach records must match
their actual IDs and initial/final values.

Normal CRT destruction emits and flushes the first JSON receipt. A separate
Win32-only process-detach receipt proves the final loader callback and its
observed main state after that destructor. Main duplicates the child's output
handle specifically for this final notification, so it does not depend on CRT
stdio handle lifetime. The callback writes bounded constant text with `WriteFile`
and closes the duplicate. Missing/partial output or notification failure cannot
produce a successful parent receipt.

## Gates and evidence

`tools/rebuild/tls_owner_fixture.py prepare` compiles only the four named
original fixture sources/header using the existing exact SP1 toolchain. It
provides no user-selected PE/template extraction path. Compiler calls are
sequential and require a shared slot. Preparation links two normal native
layouts with changed preferred bases and object order; it runs neither.

The checks require exactly one authored TLS contribution and one correct
callback record, normal library directives, SafeSEH source metadata and no
source definition of CRT infrastructure. Linked verification checks complete
authored template equality, virtual extent, protections, one-byte markers and
padding, fresh index data, callback pointer/order/termination, directory and
callback HIGHLOWs, absence of template fixups, all source TLS fields, normalized
source code payloads, SafeSEH table, normal CRT providers and direct imports of
only `KERNEL32.dll`. Source/compiler/CRT/OS inputs, objects, map/PE/log artifacts
and observed contracts are hash-bound in an exclusive preparation receipt.
Unknown ownership, extent/alignment, relocation, callback or late input drift
fails rather than broadening the layout.

Before each real object compilation, a syntax-only `/Zs /showIncludes` pass
discovers actual headers. Every included path must remain under the approved
fixture, VC or SDK include root. Each header is then hashed before compilation;
the real `/showIncludes` set and every protected hash must still agree afterward.
Compiler `c1xx`/`c2` backends and named present support/runtime DLLs are bound
before compiler calls and rechecked around tool execution. Discovery itself is
not claimed as a pre-bound object compilation.

The exact Windows-header directive contract includes two `uuid.lib` defaults,
as observed in the existing hash-bound original CRT/TLS probe and evidenced by
the SDK `objbase.h` pragma, followed by `LIBCMT` and `OLDNAMES`. The named SDK
`uuid.lib` is hashed; other directive surprises reject preparation. Actual PE
imported API names must match an explicit source-reviewed normal-CRT baseline
plus fixture APIs, with required source APIs present. Unknown API names, ordinals
or other DLLs fail; this is not a DLL-wide import allowance.

Library ownership is checked against the actual controlled current-directory,
VC and SDK search order before and after linking. An earlier competing library
fails, including a VC `uuid.lib` ahead of the intended SDK provider. Linker
`/VERBOSE:LIB` must name the exact absolute bound paths for all four normal
libraries; missing path evidence or an unbound provider rejects preparation.
Those search observations and file hashes are recorded per layout.

V2's normal-only link then passed the unchanged layout/ownership/SECREL gates,
but stopped on fifteen named KERNEL32 imports outside the original saved-probe
baseline. Its complete 91-name import set and post-failure evidence are retained;
neither that executable nor a moved variant was run. Independent review joined
each of the fifteen names to actual relocation targets in map-selected members
of the exact bound `LIBCMT`: `a_cmp`, `getqloc`, `mlock`, `rand_s`, `tidtable`,
`strftime`, `w_loc`/`a_loc`, `tzset`, `heapinit`, `winsig` and `setenv`. The tool
now admits only those exact reviewed names, pins the whole CRT archive hash and
requires their reviewed members in each fresh map. There is no API wildcard.

Fresh preparation also binds actual i386 SysWOW64 files and reads bounded PE
export metadata to follow each imported name through any export-forwarder
chain, without loading a DLL or reading export function bodies. Cycles,
unresolved modules/exports, unsafe names or data exports reject preparation.
File hashes are protected before and after each child. The evidence explicitly
concerns on-disk files/export forwarding, not in-memory KnownDLL sections,
internal wrapper transfers, a dynamic call trace or complete transitive OS
imports. V2 was not OS-bound and is not retroactively upgraded by this change.

The reviewed VC9 TLS and EH links advertise load-configuration directory size
64, while the actual raw-backed structure self-size is 72. This tool accepts
only that exact old-linker form or advertised size 72, still requiring all 72
bytes raw-backed, self-size 72, aligned read-only/non-executable SafeSEH table,
its pointer HIGHLOW and sorted unique executable handlers. Truncation or a
changed table remains a failure.

Independent source review is required before native preparation. Independent
artifact review must then check the exact source/CRT contract, template layout,
SECREL and module-relative semantics, callback identity/safety, SafeSEH,
map/imports, OS export identities and protected artifact hashes for both variants. Only a new
hash-bound approval plus root go permits the separately exposed execution
stage. Protected inputs and approval/preparation hashes are checked immediately
before and after each child. Existing receipts are never overwritten.

Execution is bounded to the two own fixture children, 45 seconds each, with
captured output and no visible console. Each must exit zero, emit empty stderr
and produce exactly the normal CRT receipt followed by the successful process
detach receipt. Unsupported initialization, shifted aliases, shared thread state,
wrong caller state, missing callbacks, timeout or artifact change is a terminal
error receipt. No fallback normalizes state or substitutes a game provider.

Hash-bound command observations do not cryptographically prove compiler
causality, all transitive header inputs or the full transitive Windows loader
graph. Even a future fixture pass would not approve game TLS materialization,
all TLS aliases, Havok's separate dynamic slot, startup or gameplay.

## Current validation status

Twenty-one offline synthetic tests pass. They exercise source extent/alignment and
SECREL failures, duplicate infrastructure, callback identity, actual PE marker/
module offsets, shifted layouts, changed code, unexpected TLS fixups, normal
directives, immutable approval/output gates, thread/caller/notification receipts,
own-child timeout, PE drift during the final child, actual-header/backend drift,
named API/ordinal rejection, competing/resolved-library and hash drift, and the
strict VC9 64/72 SafeSEH case. They compile and execute
nothing:

```text
python -m unittest discover -s tests/rebuild -p test_tls_owner_fixture.py -v
```

Both source reviews accepted the hardened implementation before root authorized
one prepare-only attempt. The private `tls-owner-fixture-v1` attempt compiled
all three original translation units with captured header traces, then rejected
the storage contribution before linking: its extent is 704 bytes but VC9 emits
alignment 8 (`0xc0400040`), while the source type's alignment-4 assertion passes.
The required contribution alignment 4 was not satisfied. No executable was
linked or run, and no guard or layout fallback was relaxed.

Objects/logs and a separately labeled post-failure observation receipt are
preserved privately. That observation is not a retrospective pre/post hash
attestation or an accepted preparation receipt. The +4 owner and 708/709 linked
layout therefore remain unproved by this source declaration. Any source remedy
needs a fresh bounded review/authorization and new private output directory;
existing failed evidence must remain intact. No game TLS work is implied.

Root authorized one smallest source-only v2 hypothesis: explicit variable-level
`__declspec(align(4))` on both the TLS owner declaration and definition, retaining
the same 704-byte type, authored initial data and intended module offsets. The
alignment-4/708-byte-template guards remain unchanged; no COFF flags are patched.
The original v1 sources were snapshotted separately before this edit, and v1
failure artifacts remain immutable. V2 requires renewed source acceptance and
a fresh prepare-only directory; if the compiler still emits alignment 8, that
variant must stop without a layout fallback. V2 proved source alignment 4 in
its normal-only failed attempt. The reviewed named-API and actual OS-evidence
changes received renewed source acceptance before fresh v3 preparation.

Private `tls-owner-fixture-v3` preparation completed for both normal and moved
layouts. Each proves the 708-byte template/709-byte logical section, owner +4,
fields +`0x268`/+`0x2b4`, 63 TLS operand relationships, eleven normalized source
code sections, three SafeSEH handlers and the complete 91-name import set.
The preparation binds 125 inputs, including actual per-TU header sets of
97/86/88 files, and 22 artifacts. Actual SysWOW64 kernel32/kernelbase/ntdll file
identities and all 91 export chains, six forwarded, are recorded with the stated
on-disk-only limitations. The preparation SHA-256 is
`235b3572a0863456c747562c91dd1a21aba77112e78115345d08c1469ab9337e`.
Independent full artifact review approved the exact layouts, including actual
COFF/PE fields and bounds, all 63 TLS operands, the 91 OS export chains and all
fifteen CRT member-to-API relocation attributions. Its review SHA-256 is
`968c80feca21b7180c3a80640260aee4e586dd2e11ad6e16b046f6b68eb1de0a`.

Root then separately authorized one run of each exact reviewed executable.
Both passed with exit zero, empty stderr and exactly the expected two-record
sequence. Each observed three complete initial-state checks, three alias checks,
main-thread state and caller sentinel preservation, distinct main/two-worker
blocks with the same module index, successful independent writes, normal CRT
construction/destruction once, five pre-detach loader events and a successful
final process-detach receipt through the duplicated own output handle. The
actual owner/field offsets were +4/+`0x268`/+`0x2b4` in both layouts.

The execution SHA-256 is
`3a53a9adc6b33557689c003d7013b991987e989607867c61b9c6057398780525`.
Independent final verification accepted both exact outcomes and preparation/
approval bindings with zero protected-input drift. No source, tool, dependency
or expectation changed after preparation. V1/v2 failures and their post-failure
evidence limitations remain intact. This is a successful original loader-owned
TLS fixture only; no game getter ran, no game TLS bytes were materialized and
no game TLS alias/provider, startup or gameplay claim follows.
