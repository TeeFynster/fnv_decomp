# Static TLS owner proposal

Read-only planning, November 3, 2026 (America/Chicago). No source/object changes,
template emission, profile generation, compilation, DLL loading or execution
were performed. Completed DATA/scalar/leaf/EH/binding tools remain unchanged.
This proposes an original fixture first and identifies one possible later game
reader; neither is a provider-adoption decision.

## Original PE storage and initial state

The exact plaintext reference still has the retained-v3 image hash, and the
unchanged fingerprint gate passed 16/16 probes. Fresh PE-directory/relocation
inspection confirms:

| Property | Observed original identity/value |
|---|---|
| TLS directory | RVA `0x00d0147c`, size 24 |
| Template start / exclusive end | `0x01272000` / `0x012722c4` |
| Declared initialized template | 708 raw-backed bytes |
| Additional loader zero-fill | 0 |
| `.tls` logical / raw extent | 709 / 1,024 bytes |
| `.tls` protection | Read/write, non-executable |
| Index cell | `0x0126fd98`, four bytes wholly in `.data` virtual-zero storage |
| Callback-array pointer | `0x010113f0` in `.rdata`; first entry null |
| Directory characteristics | 0; no explicit directory alignment encoding |
| Template base relocations | None, including fields overlapping either boundary |
| Directory pointer relocations | HIGHLOW at offsets 0, 4, 8 and 12 |

The exact 708-byte template SHA-256 is
`4706ac65eb4aa08f7c42798200b54e4f186120eed2e74247d65b57fff27c4a75`.
It has twelve nonzero bytes distributed among six aligned words; it is not an
all-zero template. The byte at template offset `0x268` initially equals zero.
The four-byte integer at `0x2b4` initially equals **59**, matching the selected
reader's source initializer. `MemoryManager` initialization later clears that
field; the on-disk initial value must not be confused with initialized main
thread state after that routine runs. Other template fields' semantic types,
sentinel meanings and construction/use contracts remain unapproved. Absence of
HIGHLOW records does not alone classify every numeric field as nonpointer.

The extra logical byte after the directory's exclusive end is not part of the
708-byte initialized template. Its original symbol owner was not established
here; the normal CRT marker pattern below is supporting format evidence, not
permission to assign an original symbol or copy a complete template. Raw file
alignment padding is also outside the declared initial-data extent.

The index cell's file absence means loader-zero storage, not a missing extracted
integer. A new loader must assign its new module index; zero is a valid possible
index, so the fixture must not require it to be nonzero. The original callback
list is empty. Neither its address nor its null terminator should become a
second runtime callback/index/directory allocation.

`0x0126835c` is the separate Havok dynamic TLS-slot global used with
`TlsGetValue`. It is neither the PE static index nor a template offset. Its
allocation/initialization/free lifetime remains outside this proposal; it must
not be aliased to the new static TLS owner.

## Actual normal SP1 CRT owner and marker bias

The existing original CRT/TLS probe's source, object, executable and map hashes
still match its saved passing receipt. This audit inspected them without
rerunning the probe. Its map and PE agree on:

| Normal-probe contribution | Template-relative location | Provider |
|---|---:|---|
| `__tls_start`, `.tls` | 0; **one-byte** contribution, alignment 1 | `LIBCMT:tlssup.obj` |
| Alignment padding before source int | +1 through +3 | Link placement |
| `tls_value`, `.tls$` | +4; four initialized bytes, alignment 4 | Original probe object |
| `__tls_end`, `.tls$ZZZ` | +8; one-byte contribution | `LIBCMT:tlssup.obj` |

Its directory template is eight bytes, while `.tls` logical size is nine; the
end marker is excluded. A source variable at value zero in its own `.tls$`
contribution therefore does **not** occupy template offset zero. Treating the
start marker plus padding as a four-byte CRT marker would also be incorrect.

Named-member inspection of the exact SP1 `libcmt.lib` confirms `tlssup.obj`
owns the fresh four-byte BSS `__tls_index`, the one-byte start/end markers,
`.CRT$XLA`/`.CRT$XLZ` null sentinels and the 24-byte `__tls_used` directory in
`.rdata$T`. The directory's callback relocation is `___xl_a + 4`: it skips the
opening sentinel and, in the saved no-callback probe, points directly at the
closing null sentinel. Its SafeSEH feature metadata is `@feat.00=1`.

The separate normal CRT member `atlssup.obj` defines `__tls_array` as an
EXTERNAL **ABSOLUTE constant 44**, not storage. The saved map likewise records
`__tls_array=0x2c` as absolute. Game uses are undefined external COFF symbols;
the [binding plan](RUNTIME-BIND-PLAN.md) correctly preserves their numeric-offset
role rather than inventing process VA 44. The compiler's thread-block lookup,
this constant and the loader-managed index are separate from an ordinary global
data-pointer relocation. Any future implementation must review the actual
addressing mechanism and never allocate a data object at that numeric value.

Evidence hashes: SP1 archive
`bd9700d126d378f31f32736abc0c88cb08a8e0f0914acb6e2c8cbfd1ab99f411`;
named `tlssup.obj` member
`103a8d4b812cb3a44bb65274690e3d279c4cd73839a42a4de3c3fb73c1f576b3`;
named `atlssup.obj` member
`ec20c7c83e332edfc1f2c23e8e31f358f498a18a3af610a00a198cc13a52df7f`.
Saved original-probe receipt hash:
`e164462adbbc81d57560f1fcf54bd9d6a6fb9a555890e7c6aba598e15e1e3ab4`.
These are metadata identities, not copied template/code bytes or private paths.

## Offset aliases and selected-field evidence

The finalized binding-plan-v2 report/detail hashes agree with the approved
evidence. Its selected-field stream contains 2,023 SECREL fields: 1,095 have
zero addend and 928 have a nonzero addend. The report separately preserves
1,096 static-index fields and 1,084 compiler TLS-array numeric-offset fields.
These counts are field observations, not independent allocations or a complete
inventory of unrelocated immediate constants.

The exact inspected contrast is:

| Source use | Selected COFF interpretation | Required semantic offset |
|---|---|---|
| `memorymanager.cpp::FUN_00aa39c0`, `g_tls.m_2b4` | SECREL against a block-view symbol plus explicit addend `0x2b4` | Block view must project to template base, not source-owner start +4 |
| `effectitem.cpp::GetTlsField`, `DAT_tls_field` | Zero-addend SECREL against the scalar field symbol | Field symbol itself must project to template +`0x2b4` |

Both use DIR32 references to the static index and the compiler TLS-array
constant. In the first case the explicit source member offset is carried by a
SECREL addend; it is not permission to allocate another padded struct. In the
second case the field's retained object happens to place its symbol at native
`.tls$` value **`0x2b8`**, while the original operand and recipe binding project
to **template `0x2b4`**. The unchanged comparator uses the original semantic
binding; it does not certify that the whole source TLS contribution has a
runtime-correct layout. Retaining that accidental `0x2b8`, or adding the CRT +4
bias again, would read the wrong field.

A canonical ledger must distinguish template-base views, field aliases,
SECREL addends and the physical owning subsection. It cannot resolve every
thread-local spelling by separately compiling its source definition. The
inspected metadata does not establish all other source views, direct thread
block accesses or Havok dynamic-slot users. Those remain separate obligations.

## Smallest original fixture proposal

First assign a new **fully source-authored**, POD-only TLS fixture. Preserve
normal `tlssup`/`atlssup` ownership; define no second `_tls_used`, index, start/end
marker or callback directory. Use no copied game template and no handwritten
assembly or global settings. Initial values should be visibly original, for
example flag 1 and context 37, rather than reproducing unknown game state.

A deliberately bounded layout hypothesis is one align-4, 704-byte source TLS
owner in `.tls$`, with fixture fields at owner-relative `0x264` and `0x2b0`.
If and only if the actual linker places that owner at template +4, the fields
will occupy module-template `0x268` and `0x2b4`, and its end will precede the CRT
end marker at template +708. Named reserved fixture arrays and all initial
values are authored layout, not guesses about a game class. This is a hypothesis
to test, not an instruction to implement from this document or to assume
subsection ordering/alignment. Extra TLS contributions or a different offset
must reject the layout rather than silently adjust game offsets.

The original fixture should compare ordinary compiler SECREL access with an
independent module-block lookup and explicit offsets. A supported compiler
intrinsic such as the actual VC9-declared `__readfsdword` can express the x86
thread-array lookup without handwritten assembly, subject to pre-execution
review of its generated mechanism. Assert actual runtime relationships between
the block pointer, owner pointer and both fields; a map-only address assertion
is insufficient. Test template-base and field views as aliases of the same
bytes, not independent allocations. Canonical external SECREL aliases for game
symbols require their own later reviewed representation; the fixture's normal
C++ references do not manufacture them.

Add one original `.CRT$XLB` callback record inside the existing CRT sentinel
array, not a replacement directory. It should use only bounded POD/Win32-safe
event recording before CRT construction and record loader process/thread events.
Main and two concurrently alive worker threads must independently observe their
source-defined initial fields, mutate distinct values, preserve them across a
barrier and leave main unchanged. Check own workers' attach/detach events and
exactly-once normal CRT constructor/destructor behavior, without depending on
unclassified callbacks or heap use during loader notification.

Acceptance requires two changed base/layout builds; exact source/compiler/CRT,
COFF, map, PE and artifact hashes; one loader-owned index/directory; proved
one-byte start/end markers and actual padding; exact module-relative field
offsets and SECREL results; complete authored initial-data equality and zero
semantics; no unknown template pointers/fixups; correct callback termination;
normal imports, SafeSEH and CRT providers. Reject a +4 shift, duplicate owner,
unknown callback, stale evidence or unsupported linker record. Separate prepare,
independent artifact approval and bounded own-child execution; preserve failures.
At the proposal stage this fixture was unimplemented. The subsequently assigned
[original fixture](TLS-OWNER-FIXTURE.md) records its own source reviews and the
failed pre-link alignment experiment; no runtime layout or execution success is
implied here.

## One possible later game reader

Only `?GetTlsField@@YAHXZ` at symbolic identity `0x00404f50` is proposed:

| Evidence | Exact observation |
|---|---|
| Source | `src/fallout_shared/magic/effectitem.cpp:557-565` |
| ABI/semantics | `int __cdecl(void)`; returns `DAT_tls_field`, source initialized to 59 |
| Selected owner | `0781-3b6aac24065e157e`, index 781, section 56/value 0, 26 bytes |
| Code policy/children | `no_duplicates` COMDAT; no associated children or unit-local EH notes |
| Runtime edges | +4 DIR32 `__tls_index`; +11 DIR32 `__tls_array`; +20 SECREL field; all zero addend |
| Retained object hash | `ab8a41852bfdda260348209f47ddc6ed125fd68a5228216f2b6656745cc15310` |
| Source hash | `716b704c5f9e3893014f9458ad8020ddf47c1fdacd628fac62cf3a8fd6c96358` |

Exact selection, manifest and v3 function rows agree. Fresh unchanged reference
comparison passed all 26 bytes/three relocations with zero differences. Source
and observed field initializer 59 agree; there are no calls, class ABI or other
game state in this reader. Its closure still requires the proved normal index/
array mechanism and a correct field owner. A later isolated component may use
only an explicitly approved source-defined field/alias contract after the
original fixture succeeds. It must not preserve native source offset `0x2b8`,
copy the whole source `.tls$`, zero unknown game TLS fields or adopt all TLS uses.

Original fixture data is entirely authored. Any later private non-executable
game TLS initialization needs its own independently proven owned-data and
materialization contract; no game template/code bytes belong in tracked files.
One reader's source initializer is not proof of every other template field or
post-startup state. General TLS ownership and game startup remain blocked.

## Review status

Independent metadata review confirmed the single reader's exact owner, hashes,
relocations, source initializer and native-versus-original offset difference,
the original PE directory/extents/protection/index/callback facts, template hash
and field values, and saved normal-probe map marker bias. It found no blocking
metadata issue for a separately authorized original fixture. That reviewer did
not independently reparse the CRT archive members, repeat the comparator or
rerun the saved probe; those review limits remain explicit.

Root subsequently authorized original-fixture code/test preparation only in
`tools/rebuild/tls_owner_fixture.py`, `tests/rebuild/test_tls_owner_fixture.py`,
`runtime/probes/tls_owner_fixture.hpp`, `tls_owner_storage.cpp`,
`tls_owner_callback.cpp`, `tls_owner_main.cpp`, and its separate
`docs/rebuild/TLS-OWNER-FIXTURE.md`. Implementation needs its own independent
source gate before native preparation, and exact artifact review plus root go
before execution. No game getter extraction, linking or execution is authorized.
