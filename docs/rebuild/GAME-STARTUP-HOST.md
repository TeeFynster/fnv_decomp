# Actual application startup host: compile-only source checkpoint

This is an original normal WinMain adapter and an offline compile/closure plan.
It does not implement a CRT or an original executable entry stub. No native
compiler, linker or executable has been invoked for this checkpoint. The tool
has no native invocation path. Its generated private plan grants no compile,
remap, link, provider or execution approval.

## Owned boundary and evidence

The actual retained application body is `src/fallout/misc/main.cpp`, recipe
`0576-dd603b7071c482c6`, symbol `?FUN_0086a850@@YGHIIII@Z`, physical symbol
1215, section 199, offset zero, size 4,532. The source declares
`int __stdcall(unsigned int, unsigned int, unsigned int, unsigned int)`.
Its first parameter supplies the window-class instance, `LoadIconA` instance,
window creation instance and a globals constructor. Parameters two through four
are unused in that body. It parses the full Unicode command line itself through
`GetCommandLineW` and `CommandLineToArgvW`, and frees that allocation with
`LocalFree`. It has early returns and an explicit teardown/return path.

This establishes the source's four-dword stdcall boundary and WinMain-shaped
first argument. The historical caller and exact original CRT-to-application
edge remain unverified. The packaged PE entry is not an appropriate substitute.
The adapter is a proposed new runtime boundary, not a claim to reconstruct that
historical startup path. Source observations and the retained object identity
are documented in [the entry proposal](APPLICATION-ENTRY-LINK-PROPOSAL.md) and
[startup closure](STARTUP-CLOSURE.md); no original code was decoded here.

`runtime/startup/game_startup_host.cpp` uses the real SDK `WinMain` types and
returns the application's result normally. Compile-time width checks require
x86 pointer, `int` and `unsigned int` widths. The three pointer arguments are
converted to unsigned dword bits without dereferencing or taking ownership.
The signed show state becomes its modulo-2^32 dword representation. The fourth
parameter currently has no use in the retained body; forwarding it preserves
the whole proposed boundary. There is no manual CRT initialization, allocation,
game provider, state definition, alias directive, fixed-address dispatch or
termination shortcut in the adapter.

The typed declaration deliberately produces `_fnv_game_application_entry@16`.
The selected CODE serializer's agreed export is
`_fnv_code_a6aec00b5758b2c5c1dd3e4ad43d42c70a7d4b3ba314830a56d8d21afb4e93f2`.
That name identifies recipe, object hash and physical symbol; it does not encode
the calling convention. A subsequent independently reviewed identity-only COFF
binding must map the host's undefined typed symbol to that exact export while
preserving section contents, relocation indices/kinds/addends and symbol
provenance. This checkpoint neither implements nor approves that transform.
Declaring the provider cdecl merely to obtain an undecorated name is excluded.
The actual entry projection remains independently owned work; no projected
object or transitive provider is assumed present by this plan.

## Exact offline preparation

`tools/rebuild/game_startup_host.py` reads only the explicitly supplied doctor,
its exact SP1 compiler/linker files, the pinned recipe and entry source, and its
four owned source/test/document files. It verifies the doctor hash supplied by
the coordinator, SP1 readiness/version, tool hashes and explicit include roots.
There is no environment-root fallback and no doctor rerun. The existing private
`build/rebuild/doctor-all.json` is the intended doctor input. Its private paths
appear only in ignored output, not in this document.

The planned command uses the exact doctor-selected SP1 `cl.exe` with `/c`,
`/MT /Od /Oy- /GS /EHsc /W4 /WX`. The sole output is a prospective host object;
there is no link command. The plan explicitly reports that actual header
discovery and native input closure have not occurred. Current file hashes are
checked again before returning the plan, but this is not a native preparation
attestation. No source is added to `build/units.json` and no matching gate changes.

An offline plan can be written with:

```powershell
python tools/rebuild/game_startup_host.py --doctor <exact-private-doctor.json> --doctor-sha256 <trusted-doctor-hash> --out <new-private-plan.json>
```

The output must be new. Paths within this checkout are restricted to ignored
`build/rebuild`; an explicit private destination outside the checkout is also
allowed. Do not publish the plan's private toolchain paths. Tests use original
non-executable placeholder files exclusively to exercise metadata rejection;
those files are never compiler or game providers.

## Normal CRT and application closure gates

The eventual target is a normal x86 Windows GUI executable without `/ENTRY`
override. Its real CRT GUI startup must establish security-cookie state before
protected code, configure CRT state, execute the selected C/C++ initializer
tables, supply WinMain arguments and process normal return through the shared
exit registry. A candidate SP1 static CRT is recorded only as a proposal.
The independently reviewed [CRT bootstrap fixture](CRT-BOOTSTRAP-CONTRACT.md)
demonstrated narrow original-fixture behavior; it does not approve this game's
mixed compiler ABI, generated initializers, exceptions or allocations.

Before a native host compile, root needs independent review of these exact
four files and a separately reviewed compile-only runner. That runner must
bind code generators, actual SDK headers and native OS dependencies, constrain
implicit compiler options and include roots, use a new private output directory,
and retain an append-only progress/error receipt. No native attempt is hidden
behind the offline plan. After compile, independent COFF inspection must verify
the exact GUI definition, four-dword stdcall undefined reference, ordinary
directives and absence of unexpected host dependencies before any name binding.

Link remains blocked on real CODE/data/import providers, normal CRT and fresh
cookie ownership, TLS template/index and loader behavior, rooted initializer
retention/order and shared exit ownership. The entry's 279 direct destinations
and transitive dependencies remain obligations. Icon resource `0x65`, window
class/title data, window procedure signature and instance ownership require real
contracts. All import signatures and IAT indirections, allocation pairings,
callee EH/RTTI and shutdown lifetimes remain separately reviewed gates. No fake
provider, old-data overlay or absolute-address fallback can satisfy these gates.

Current boundary: source frozen for review; eight focused offline tests pass.
No host object, remap, game link, launch, menu, gameplay or save/load result is
claimed. The four owned files are the adapter, planner, focused tests and this
document; shared progress ledgers remain coordinator-owned.
