# Normal CRT providers for the observed application frontier

This read-only proposal turns the [entry dependency observation](ENTRY-DEPENDENCIES.md)
into concrete normal-CRT provider work. The existing reference sources, recipe,
matching oracle, frozen observer and writer policies remain unchanged. No
compiler, linker, executable, DLL load or game-image read was used here. No
runtime provider, original-data fixup or application ABI is approved.

The intended runtime model is source-built application objects linked to one
explicit normal static CRT, with fresh startup, per-thread state, heap, streams,
cookie and exit registry. Installing a second CRT or forwarding calls into old
game addresses is not a provider plan. Reference byte matching stays separate:
a functional normal-CRT substitution need not reproduce the old helper's code
bytes, but it must satisfy the retained caller ABI, state and behavior contracts.
This investigation establishes export/metadata evidence and remaining gates;
it does not establish those contracts by similar names or matching section hashes.

## Exact physical use sets

The accepted graph has 16,838 selected owners. Within that scope the six existing
explicit CRT candidates have these actual undefined external COFF spellings.
Every recorded use is REL32, zero addend, exact own-recipe numeric resolution,
and an undefined non-common external physical source symbol. Counts are fields,
not six complete application dependencies or automatically approved APIs.

| Original target / physical spelling | Fields | Distinct recipe/function callers | SP1 / RTM fields |
|---|---:|---:|---:|
| `0x00ec408c` / `@__security_check_cookie@4` | 574 | 558 | 538 / 36 |
| `0x00ec43fb` / `___RTDynamicCast` | 409 | 206 | 409 / 0 |
| `0x00ec6040` / `__CIsqrt` | 66 | 42 | 34 / 32 |
| `0x00ec62c0` / `__ftol2_sse` | 461 | 217 | 460 / 1 |
| `0x00ec658f` / `_atexit` | 30 | 28 | 30 / 0 |
| `0x00ec7894` / `__CxxThrowException@8` | 70 | 55 | 70 / 0 |

There are no VC8 fields in this particular six-candidate reachable subset.
Compiler columns identify original source-object producers; they do not select
the provider runtime. The earlier complete six-target inventory covers 10,261
uses across the whole selected universe and remains separate evidence.

New private `entry-crt-provider-evidence-v1.json` binds 2,004 complete physical
sites: those 1,610 fields, all 389 reachable `0x00406d50` uses, the one
`0x00ecc071` use and four additional `_fread` uses. Each retains the binding
ordinal/hash, recipe, caller, source hash, object hash, native section/offset,
physical target symbol index/spelling, target/base, kind and addend. Source and
object hashes are provenance from the retained manifest; no object was reread.
The four `_fread` callers are outside the current selected entry closure.
Original data-held function pointers therefore remain a real way to expand it.

## First useful contract: ordinary stream I/O

`0x00ecb3a8` is an unusually concrete lead: all four exact recipe and COFF uses
spell `_fread`, with C linkage and matching four-argument source declarations.
They are still original identity evidence rather than an original-body comparison.

| Recipe / caller | Physical source section / field offset / symbol index |
|---|---|
| `0049-a7bea53a8ad2db8e`, `IO_Thread::ThreadProc`, `0x00aa8430` | 3 / 221 / 14 |
| `1050-933f55521cb9d4f5`, `GvBinaryFile_SV::FUN_00ac52b0`, `0x00ac52b0` | 517 / 42 / 2060 |
| `1821-ead65709d249dd91`, `ReadOrMarkFailed`, `0x00d2bcd0` | 3 / 20 / 9 |
| `2739-c4c330f887b3310d`, `FutBinaryFileC::FUN_00ac3fe0`, `0x00ac3fe0` | 910 / 310 / 3618 |

The complete source/object hashes are in the evidence.
Binding ordinals are respectively 3312, 247721, 384166 and 450469. The selected
source uses are byte reads, an item-count comparison, a positive-read check and
a signature read. The final source opens a binary stream and closes it through
its local guard. This does not trace all producers of the other stream pointers.

All three installed old `stdio.h` files declare the normal cdecl `fread` taking
a destination, two `size_t` quantities and `FILE*`, returning `size_t`. Microsoft's
[fread contract](https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/fread?view=msvc-170)
counts complete items, distinguishes short reads from full reads and documents
stream state and locking. The x86 source declarations use unsigned integers for
the two sizes and result; the pointer declarations vary between `_iobuf*`, a
recovered file type and `void*`. These spellings do not prove the actual stream
object's allocation, internal layout or runtime owner.

The actual SP1 and RTM `fread.obj` each define `_fread` at section 11/value zero
in a 29-byte section; VC8's corresponding section is 27 bytes. These are section
extents, not recovered original function sizes. SP1's selected section has one
REL32 field at +20 to `_fread_s`, defined within the same member. Member-wide
undefineds conservatively include stream locks, `__filbuf`, `__fileno`, `__read`,
`__errno`, invalid-parameter handling, SEH machinery, `_memcpy_s` and `_memset`.
An export alone does not close those dependencies.

The next implementable provider package should bind an exact normal SP1
`_fread` provider to the canonical **code** identity only after reviewing the
four source declarations and the data-held pointer type. The same package must
select normal `fopen`/seek/tell/write/close and stream-buffer/descriptor ownership
where those pointers originate. A new stream must come from that chosen CRT;
copied old `FILE` bytes, old descriptor numbers and a guessed four-byte file
object cannot supply it. Microsoft's
[CRT object boundary guidance](https://learn.microsoft.com/en-us/cpp/c-runtime-library/potential-errors-passing-crt-objects-across-dll-boundaries?view=msvc-170)
explains why separate runtime copies cannot safely exchange their stream or
allocation state. The existing bootstrap fixture deliberately did not test
that boundary.

Use the actual source-owned binary-file component for the later bounded
preparation: prove its open/read/short-read/seek/close routes and normal CRT
providers from the final map, rather than add another disconnected generic
startup fixture. A later approved run can use a small newly authored scratch
file, with no game assets, and check item counts, EOF/error distinction and
cleanup. This document authorizes no preparation or execution and supplies no
stub for any remaining component dependency.

## The two direct main targets remain identity investigations

Main recipe `0576-dd603b7071c482c6`, section 199, has these exact fields:

| Original target | Main field / physical symbol | Actual spelling |
|---|---|---|
| `0x00ecc071` | +768 / 1420 | `?FUN_00ecc071@@YAHZZ` |
| `0x00406d50` | +893, +964, +1134 / 1409 | `?FUN_00406d50@@YAHZZ` |

The wide comparison consumes an argument from `CommandLineToArgvW` and tests
whether its result is zero. Its only recipe alias is the shown variadic cdecl
declaration. The installed archives contain both normal `_wcscmp` and
`__wcsicmp`, but this use cannot distinguish case sensitivity, locale policy,
null handling or a wrapper. Microsoft's
[case-insensitive comparison contract](https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/stricmp-wcsicmp-mbsicmp-stricmp-l-wcsicmp-l)
has observably different case/locale behavior from `wcscmp`. Neither is selected.

The append target has 389 reachable uses in 53 recipe/function callers and 44
physical source symbols. Seventeen physical spellings include cdecl
`int(char*, unsigned int, const char*)`, `void` variants and variadic aliases.
The full recipe has 72 symbol-binding rows for this target, including more
unreachable declarations. Main passes capacity 260 for local path buffers and
ignores the returned value. The normal installed `_strcat_s` export and the
three-argument source shape make it a candidate, not proof that an original
wrapper's behavior equals CRT `strcat_s`. Its
[public contract](https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/strcat-s-wcscat-s-mbscat-s?view=msvc-170)
uses total destination capacity and has defined error/invalid-parameter policy;
those behaviors must be resolved before substitution. The installed library
exports C `_strcat_s`, not the recovered C++ spellings above.

The next identity review should use the already bound source-use sets and
one separately authorized bounded original/member comparison if still needed.
Do not normalize the reference declarations, choose `wcscmp` by proximity,
or map all append aliases to `_strcat_s` merely to satisfy a linker.

## Six helper contracts and an actual link plan

The [earlier CRT inventory](CRT-INTEGRATION-PROPOSAL.md) already has exact
SP1/RTM/VC8 members and dependency metadata for these helpers. This proposal
rehashes their actual libraries and reuses that evidence rather than repeating
six generic fixtures.

| Retained helper | Normal member / remaining caller contract |
|---|---|
| `@__security_check_cookie@4` | `secchk.obj`: preserve the compiler-generated x86 register boundary, one fresh cookie/complement and normal failure provider. Main's exact check is +4522. The accepted [bootstrap contract](CRT-BOOTSTRAP-CONTRACT.md) establishes limited cookie-before-initializer behavior with SP1/RTM/VC8 consumers, not every game frame. |
| `_atexit` | `onexit.obj`: old `stdlib.h` declares cdecl registration of a no-argument cdecl callback. All 30 reachable uses must register source-owned callbacks into the same fresh CRT exit registry. Callback retention and lifetime remain open. [Microsoft's contract](https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/atexit?view=msvc-170) specifies normal-termination registration and reverse registration order. |
| `__ftol2_sse` | `ftol2.obj`: an actual compiler-emitted conversion helper, referencing fresh `___sse2_available`. No matching public prototype was found in the inspected old headers. Preserve its exact generated-call register/FPU/result contract; an ordinary handwritten `int(double)` declaration or cast wrapper is insufficient. |
| `__CIsqrt` | SP1/RTM `_sqrt_.obj`, VC8 `sqrt.obj`: [Microsoft documents a compiler-specific x86 floating-stack convention](https://learn.microsoft.com/en-us/cpp/c-runtime-library/cisqrt?view=msvc-170). Old `math.h` declares ordinary `sqrt`, not this helper. Normal math error/FPU support and `___fastflag` remain dependencies; the `sqrtf` source expression does not close them. |
| `___RTDynamicCast` | `rtti.obj`: [the documented helper](https://learn.microsoft.com/en-us/cpp/c-runtime-library/rtdynamiccast?view=msvc-170) takes object/vfptr displacement/source type/target type/reference mode and can throw on failed reference casts. The installed roots lack `rttidata.h`. Retained RTTI descriptors, hierarchy/layout and exception owners remain unapproved. |
| `__CxxThrowException@8` | `throw.obj`: [the documented compiler entry](https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/cxxthrowexception?view=msvc-170) has a stdcall object/ThrowInfo boundary. Actual member metadata refers to `RaiseException`; that export does not approve recovered ThrowInfo, object destructors or cross-version EH frame compatibility. |

For a future real link, normal SP1 `/MT` GUI startup is the proposed single
runtime owner because it already has the narrow accepted bootstrap evidence.
RTM consumer compatibility still needs the actual helper/RTTI/EH checks above;
VC8 cannot be adopted from equal member sections. Resolve canonical undefined
identities through a reviewed provider alias table keyed by original **base and
role**, preserving each physical caller site and addend. The frozen writer
uses `crt-contract` for explicit helper fields and `code` for unknown executable
fields; one target can have both roles. For example `0x00ec43fb` also has 56
unknown-role reachable uses, outside the 1,610 candidate fields. A global
original-address or source-name replacement would hide that obligation.

The future provider table must point at actual normal CRT exports in the final
map, without changing their library bodies or retaining any old absolute VA.
It needs exact archive/member identities, archive extraction/search provenance,
one state owner, normal startup order and ordinary OS import closure. Unknown
main targets stay unresolved until their contracts are reviewed. Keep data,
EH, TLS and callback closure as separate gates, and do not use `_FORCE`, duplicate
suppression, fake function bodies or function-address/IAT-cell interchange.

## Bounded library evidence and review boundary

Only the three doctor-selected `VC/lib/libcmt.lib` files were opened. Existing
bounded archive-directory/index and COFF readers checked four named exports
per library: `_fread`, `_strcat_s`, `_wcscmp`, `__wcsicmp`. The index locates
the selected physical members; same-basename static alternatives are checked
by the existing reader. This is indexed export evidence, not a complete
library-loaded-member or whole-runtime closure claim. Temporary selected member
files were removed. No library payload or game operand bytes enter this document
or the new evidence.

| Actual normal library | SHA-256 |
|---|---|
| SP1 | `bd9700d126d378f31f32736abc0c88cb08a8e0f0914acb6e2c8cbfd1ab99f411` |
| RTM | `bd8fe9fa475deb84014af41870182b447bb969c91661d7012ae8d1b26bb6a86c` |
| VC8 | `3bc6c5b90f8507964839fd0264d8565c3b766d01f9efcad336532a11e8f06ac3` |

All twelve new named exports were found. Actual members are `fread.obj`,
`strcat_s.obj`, `wcscmp.obj`, `wcsicmp.obj`. SP1's selected `_strcat_s` section
is 116 bytes with errno/invalid-parameter fields, `_wcscmp` is a 55-byte section
without relocations, and `__wcsicmp` is a 147-byte section referring to locale
state, errno/invalid-parameter and its same-member locale-specific helper.
No claim is made that these sections reproduce either original main target.

Private evidence is 2,228,274 bytes, SHA-256
`f18aed478641b9502a262b608421757c9c9707f9f4f730d2b152db93bc5891f1`.
It pins the doctor (`9b24d10209fe0361a5e6b16b11a072e8e0ebc6505cd4b5e1bd782fe23854f29f`),
accepted graph/derivation, original six-provider inventory, bounded data-worker
lead and retained manifest. It records exact library filesystem identities,
member/index hashes, old header hashes, five named source hashes and the existing
metadata reader tool hashes. Inputs, readers, named sources and libraries were
rechecked after the pass; old header hashes record the inspected installed files.
No new generic provider framework, source wrapper, compile test or runtime fixture
was added. This document and the metadata need independent review before any
native preparation or provider adoption; actual application compatibility remains
false.
