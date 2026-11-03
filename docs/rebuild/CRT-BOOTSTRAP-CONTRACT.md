# Original GUI CRT bootstrap contract: source and prepare phase

This implements the source/prepare phase of the independently accepted
[CRT integration proposal](CRT-INTEGRATION-PROPOSAL.md). It contains one original
SP1 GUI host and SP1, RTM and VC8 source-authored consumers. It calls no game
function, supplies no game provider, and passes no CRT/STL object, exception or
allocation across compiler boundaries. One normal SP1 static CRT is an
**experimental fixture choice**, not production adoption or a general VC8/VC9
compatibility claim. Existing hash-bound tools and receipts are unchanged.

## Protocol and early cookie observation

The host is intentionally `/GS-`. Consumers are `/GS`, and native preparation
requires actual cookie and check-helper relocations in each constructor,
destructor and protected work function. All state fields must link to the one
normal CRT cookie, and all registration calls to its one exit registry.

The original observer has the real C-initializer signature `int __cdecl(void)`:
zero continues; failure returns nonzero to normal CRT startup. Its pointer is
placed in `.CRT$XIAA`, immediately after the C-initializer begin category. This
refines the initially discussed `.CRT$XIU` placement so the actual table can
prove no other nonnull C initializer precedes it. Section spelling is not proof:
the tool checks the COFF pointer and complete native dependency closure, normal
GUI entry provider, exact linked C/C++ table ranges and contents, and every
consumer initializer. The C++ table may physically precede the C table in the
image; address order is not runtime stage order.

The observer's closure may reference only its original host functions, fully
readonly pointer-free local data, the two CRT cookie cells and the explicitly
listed Win32 imports. Hidden GS/EH/CRT helpers, mutable local dependencies and
unknown associative sections fail preparation. The observer checks nonzero,
non-library-default cookie and coherent complement, emitting only booleans,
never the live cookie. The default comes from the exact selected CRT member,
not old game state. It does not write cookie state or initialize it itself.
The observation does not distinguish loader initialization from the selected
normal startup's initialization, prove entropy or establish a failure policy.

Runtime acceptance still requires the observer event before every constructor
event, together with the statically bound unprotected observer and normal
initializer roots. A late cookie value or map symbol alone is insufficient.
No ordering is claimed from preparation alone.

Every event is six little-endian dwords (24 bytes), with fixed magic/schema,
lane, kind, value and auxiliary fields. The sink obtains the inherited stdout
handle on every event, requires a pipe and uses one checked `WriteFile`; it
has no mutable global state, allocation, CRT formatting or flush dependence.
It therefore works before WinMain and through normal exit. The future execution
gate must provide the inherited handle, drain it with a bounded reader after
termination and reject any missing, truncated, extra or failed record.

Both layouts contain the same three source-role consumer files and the same
SP1-built host. The control compiles all three consumers with SP1. The mixed
layout reuses the unchanged role-1 SP1 object and replaces only roles 2 and 3
with objects compiled by RTM and VC8 respectively. Role IDs and class/source
names are not assertions about the compiler used; actual compiler identity and
version are recorded separately for every object. Both layouts require all
three roles' events, so a one-consumer control cannot pass.

Each consumer owns one C++ global object, its constructor/destructor stack
buffers and a no-argument cdecl callback. C boundaries carry only fixed-width
values or borrowed stack-buffer views during a call. WinMain checks its four
GUI arguments, invokes each protected worker, explicitly registers callbacks
in lane order, emits a return marker and **returns normally**. No ExitProcess,
`_exit`, manual CRT startup, frame corruption or termination shortcut occurs.
The offline protocol checker accepts actual constructor order, expects explicit
callbacks in reverse registration order and generated destructors in reverse
observed construction order. It never assumes translation-unit order.

UI/WER suppression uses only process-local Win32 calls before protected
consumers. Missing suppression fails the C initializer; no registry or system
settings are changed. The fixture intentionally tests only valid GS frames.

## Source review must precede native preparation

`tools/rebuild/crt_bootstrap_contract.py` is **prepare-only**. It has no fixture
execution command. Native preparation requires both `--allow-native-prepare`
and a separately written, hash-bound source review. No compiler/linker is
invoked by the offline tests or source-manifest calculation.

The schema-1 review has kind `crt-bootstrap-source-review`, status `approved`,
a reviewer identity, `allow_prepare=true`, `allow_execute=false`, and `sources`
exactly equal to `source_manifest()` (the five fixture source/header files,
runner and tests). Its required checks are `original_fixture_only`,
`normal_GUI_return`, `unprotected_early_observer`,
`bounded_pre_main_Win32_sink`, `consumer_GS_and_C_boundaries`, and
`single_experimental_CRT`, `same_three_source_control`,
`bound_linker_search_and_contributors`, `explicit_named_API_policy`, and
`duplicate_map_provenance_rejected`. Root must also coordinate a compiler-slot window;
the runner itself invokes native tools serially, using at most one slot.

```powershell
python tools/rebuild/crt_bootstrap_contract.py --doctor <approved-doctor.json> --doctor-sha256 <trusted-hash> --source-review <independent-source-review.json> --source-review-sha256 <trusted-hash> --allow-native-prepare --out <new-private-directory>
```

The approved doctor pins all three original compiler versions and SP1 linker.
Preparation additionally hashes frontends/code generators, the selected normal
SP1 static/import libraries, source review, current sources/tools and direct/core
x86 OS dependencies. A syntax-only `/showIncludes` discovery pass precedes each
code-generation pass; the actual included headers are hashed before compilation
and rechecked afterward, and the compile include set must agree exactly. This
is bounded to the explicit compiler/SDK include roots and fixture directory.
Those explicit roots and every included path are canonicalized consistently.
The physical canonical root and filesystem identity are pinned before any
native command and rechecked before/after each command and at publication.
Nested junctions that resolve outside the canonical approved-root union fail;
repointing or replacing an approved root fails even if the logical path remains.
This introduces no implicit root or ignored include entry.

Preparation links the complete all-SP1 control before compiling the replacement
RTM/VC8 consumers and linking the mixed candidate. Objects must contain exactly
the reviewed default-library directives. The host retains the two `uuid.lib`
requests emitted by the actual old SDK headers, evidenced in the saved,
hash-bound original purecall fixture; those two requests are not duplicate state
definitions. Extra UUID requests, duplicated CRT defaults, forced or ignored
library policies fail. Normal GUI entry, cookie
initialization/state, exit tables, pointer encoding and locks must come from
LIBCMT. The linked consumer state fields are independently read back and checked
against the exact current CRT providers.

Before and after each link, exact CWD/VC/SDK search-order checks reject earlier
shadow copies of LIBCMT, OLDNAMES, KERNEL32 or UUID. Only the bound SP1 VC and SDK
library paths are permitted; inherited LINK, _LINK_ and LIBPATH are rejected.
`/VERBOSE:LIB` must expose every expected absolute search path, and loaded-member
rows are bound to that exact active search context. All map object/library
contributors must be the explicit objects or those four bound libraries, with
only a tiny enumerated linker-defined metadata exception. Duplicate map symbol
names are rejected even if addresses agree; provider evidence is never silently
overwritten. Full search/member and contributor observations are retained.

Direct imports must be unique named KERNEL32 entries from the explicit fixed
API policy in the source. That list is grounded in the already hash-bound normal
SP1 purecall fixture plus this fixture's exact Win32 calls; required source APIs
must appear. Unknown APIs, ordinals, additional runtime/DLL imports and missing
source APIs fail rather than expanding a DLL-wide permission. The presence of
normal CRT exit/failure APIs in the allowed import set does not permit the
fixture source to bypass normal return. Forwarded/transitive OS closure is not
claimed. Any real native shape outside this source-reviewed policy requires
explicit review before a new preparation attempt.

New private directories prevent overwriting inputs or receipts. An append-only,
fsynced progress journal records compilation/link stages; failures retain logs
and an error receipt rather than replaying work. Actual includes, directives,
objects, maps, executables, selected CRT member and OS identities are bound in
the preparation receipt and rehashed before publication. It never links an
old game object, reads original game code or launches either fixture image.

## Status and next gate

The eight assigned files are refrozen for independent source review. Twenty-two
offline tests pass, covering protocol/order/failure semantics, actual GS/exit
metadata requirements, exact linked state fields, unprotected closure rejection,
initializer table identity, exact three-role control/mixed compiler plans,
directive counts, include context, CWD/VC/SDK shadow libraries, unbound/changed
actual searches, exact API policy, extra contributors, same-address duplicate
map provenance and stale/no-review native-call guards. The additional root tests
cover canonical aliases, simulated nested-junction escape/repointing and actual
same-path directory replacement. Native shape
differences, unavailable old-compiler behavior or an unproved table/observer
closure must be reported before changing scope; no automatic workaround exists.
The earlier source checkpoints remain intermediate evidence. The approved first
native preparation stopped at its first syntax-only include discovery: the
compiler successfully reported a header through an approved SDK junction, but
the allowed-root containment compared an unresolved root with the resolved
header. No object generation, link or fixture execution followed. Private
`crt-bootstrap-native-v1` retains its error receipt, syntax log and progress.
The narrow canonical-root correction requires renewed independent review and
a new output directory; it does not replay or overwrite that failed attempt.

The narrow correction passed independent delta review and 22 tests before a
root-authorized prepare-only v2 attempt. Host syntax/include discovery and code
generation succeeded, as did all three same-source SP1 control consumers and
the control link. The attempt then stopped at its library-evidence guard:
resolved `Uuid.Lib` and pinned `uuid.lib` were compared as strings despite equal
Windows path identity and matching bytes. The saved VC9 `/VERBOSE:LIB` output
also contains absolute search rows but no member-load rows, so the currently
required member-load evidence was not obtained. Neither issue was bypassed.
Mixed replacement objects were not compiled, and no executable was launched.

Private v2 error receipt SHA-256 is
`0c29fa817694a39784d4e6fab238bf78a9b6840deafc5ff45a54f6129587f435`;
its link log is
`897c8fbcdffe1f279940b4102a8be4f3ef65308853d25a6b61f8d330525d7016`.
The retained **unapproved** control executable and map have hashes
`c7ffdafea5457917755fe8c2c4ac3a72764780f5f90ab31dc0e26490569c7d33`
and `49cbe3bf29f9ee2cf754d0d72db05ea7aafe3ad7021e0bda8605f629b11cc2d0`.
They are failed-preparation evidence, not an accepted native contract. A change
to path/evidence handling and any new preparation require explicit review/go;
there is no automatic fallback or attempt replay.

After source review and root's coordinated preparation go, the exact native
artifacts need a separate independent review. Fixture execution remains a later
root-authorized task, requiring a bounded inherited-pipe launcher, hash-bound
artifact approval and root go. At the v2 stopping point, no receipt implied execution approval.

## Windows library evidence correction (historical)

The retained v2 failure remains immutable. The next source checkpoint compares
canonical Windows paths plus file device/inode, size and SHA-256, so a case-only
`Uuid.Lib` spelling resolves to the same bound file. Another directory or file
with the same basename or bytes does not qualify. Library identities and search
shadowing are still rechecked around each link and before receipt publication.

The pinned old linker can emit only absolute `Searching` rows. The report now
labels that log mode honestly and keeps `loaded_members` empty. It requires a
second evidence channel: every map-visible library symbol must join an exact
member in one of the four pinned archives. The bounded archive directory and
first linker index identify member offsets; a standard COFF symbol definition
confirms static member provenance. Short import members require the exact
symbol/index/member join. VC9 map octal escapes are decoded for this metadata
join only, retaining the original map spelling in the report. Inline/local
symbols absent from that member's public index require an exact definition in
the map-named member; a different compilation's indexed definition is not used.
Unknown members, missing symbols and unresolved alternative members fail closed.
This is map-visible selected-member evidence, not a claim to possess missing
`Loaded` rows or a complete loaded-member enumeration.

Map `<common>` storage remains a linker allocation with tentative declarations
in map-selected archive members, with all such declarations retained. Conflicting
sizes or alternative libraries fail closed. A global archive index's unselected
strong definition cannot substitute for those declarations. In particular,
onexit begin/end can be attributed to selected normal CRT tentative storage
without inventing a unique strong member owner. Exact archive absolute symbols
and the named linker SEH-count/table symbols retain separate provenance. None
of this establishes application ABI compatibility or provider approval.

Twenty-five offline tests cover case aliases, different-file rejection,
search-only log honesty, missing and ambiguous member/provider evidence,
selected-only tentative declarations and the unchanged source/native gates.
Read-only reconciliation of the saved v2 control finds 480 map symbols: 423
archive member/index joins, 34 fixture object symbols, 19 common allocations,
two linker-defined symbols, one archive absolute and one linker SEH count.
Its unchanged table/cookie-layout/API gates pass (59 named imports); it is still
an unapproved artifact from a failed attempt. No new compilation, linking or
execution occurred during this correction. At that point, independent delta review and a new
prepare-only authorization were required before a fresh directory was used.

The independent delta review found that a public archive index could hide an
unindexed second static definition with the same member basename. The corrected
join inspects every physical same-basename static member, while short-import
members still require their exact symbol index entry. Its regression covers an
indexed static definition plus an unindexed duplicate and the distinct
short-import index requirement. All 25 tests pass. Fresh read-only reconciliation
of the same saved v2 artifacts still accounts for all 480 symbols with the same
partition and no real ambiguity; no native preparation or execution occurred.

## Prepared and bounded execution result

After independent source-delta acceptance and separate root prepare-only go,
private native-v3 preparation completed for both layouts. Its receipt hash is
`11c875c4badb25e80e50e3c1a194de5e26133986c1d7df62d776aef18545ff6b`.
All 153 bound input identities were stable; each layout retained 480 exact map
provenance records, 59 allowed named imports and 24 consumer CRT field checks.
The prior failed preparations remain intact. Independent native-artifact review
accepted both images and their static closure before execution was considered.

A separate private bounded launcher, leaving all prepared sources/tools/images
unchanged, passed six mocked tests and independent source review. Its hash is
`198fac1ba01874b1d60f69fc01c04fd8deb10d5c3fe6cd7c9bd4afe8c72ab7d5`.
The native review and launcher review hashes are respectively
`6a19add324e944926b1810ef48fd5625be8b394c0bd1adb33dd5b0a50cf73cc8`
and `41a5247a5d0c5845830d9b8ee658fbad28726c6b0b42761578ad8685346959fc`.
Following separate root execution go, it ran exactly three fresh control/mixed
pairs, rechecking the complete bound closure before and after each child. Fixed
arguments/cwd, hidden shell-free launch, inherited bounded pipes, five-second
child timeout and first-failure stopping remained enforced.

All six processes returned zero with 18 validated events (432 stdout bytes),
empty stderr and no capture failure. Every trace recorded initialized-cookie
flags before protected constructor events, then normal main work/registration
and the return marker, explicit callbacks in reverse registration order and
generated destructors in reverse observed constructor order. The constructor
order actually observed in these six processes was source roles 1, 2, 3; this
is an observation, not a general translation-unit ordering rule. The execution
receipt hash is
`04a2c73b6b807888158069adb88de24d66d3da9f5987cf303198678c521fed9a`;
independent outcome reconciliation decoded and accepted all six exact traces,
verified the review bindings and confirmed zero protected input drift.

This establishes the narrow original fixture's normal SP1 CRT bootstrap, cookie
observation and shared exit-registry behavior with the tested RTM/VC8 consumers.
It approves no game provider, original-data overlay or application compatibility
claim; no game application was executed and no cross-boundary CRT/STL objects,
exceptions or allocations were tested.
