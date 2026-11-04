# Runtime audit

Audit baseline: `87eb937`, reference recipe `build/units.json`; read-only source/recipe inspection on 2026-11-02. This audit adds no runtime implementation. No native link, startup execution, menu, gameplay or save/load result has been established here. Addresses below identify reference ownership; they are not proposed fixed runtime addresses.

## First link target and startup

The first correct target is a separate **x86 Windows executable**, using selected source objects and a real CRT startup. It must own its code, data and TLS, and must not forward execution into the original executable. Keep the reference recipe and matching tools unchanged. A small standalone CRT/TLS/import test is useful preliminary evidence, but does not establish that the game links or runs.

Verified source ownership:

| Reference entry | Source owner / recipe symbol | Evidence and remaining obligation |
|---|---|---|
| `0x0086a850` | `src/fallout/misc/main.cpp`, `?FUN_0086a850@@YGHIIII@Z` | Existing 4,532-byte recipe function; source is `int __stdcall FUN_0086a850(unsigned int, unsigned int, unsigned int, unsigned int)`. It creates the game window/subsystems, parses the command line, runs the message/render loop and tears down. It is a strong WinMain-shaped application-entry candidate, not an absent function. Prove its caller and semantic parameter contract before wiring startup. |
| `0x00ec658f` | Eight bound reference spellings, including `_atexit` | Used by the main unit and generated initialization. No function entry at that address is listed by this recipe. Identify the intended CRT provider and exit-table ownership; do not label every spelling a missing game function. |

The selected private runtime-text image passed all 16 existing `image_ok` fingerprint probes. Read-only PE metadata reports i386/PE32, Windows GUI subsystem, image base `0x00400000` and entry VA `0x014092ee`. That header entry lies in a packaging/binding context (`.bind` is present); it is **not proof of the application entry or of missing WinMain source**. No wrapper reconstruction or copy-protection change is proposed. The exact normal CRT-to-application startup path remains unverified.

A source search found no named `mainCRTStartup`, `WinMainCRTStartup`, `__security_init_cookie` or CRT `_initterm` implementation; recipe name searches likewise do not identify those providers. This is limited negative evidence: compiler-generated/runtime material is outside the README's matching scope, and source names are often synthetic. Establish actual COFF undefineds and library providers before deciding what must be implemented.

A bounded source-level startup dependency tree (not a resolved COFF closure) is:

- Normal Windows/CRT startup → global initialization/exit registration → application candidate `0x0086a850` (first two edges still require provider/caller proof).
- Application candidate → KERNEL32/USER32/SHELL32/GDI32 imports for mutex, system information, argument parsing and window creation; `param_1` is used as the instance for `LoadIconA`, window registration and creation.
- Application candidate → `0x00c3bd30` and four adjacent configuration setters, all owned by `src/staging/blk_00c20000_od.cpp`; callback `0x0086a580` is owned by `src/bsmenu/xuserinterface.cpp`.
- Application candidate → `0x00876ad0`, owned by `src/fallout/misc/saveload/bgssaveloadmanager.cpp` as `BGSSaveLoadManager::GetSaveDirectory`; reference spelling in the caller differs.
- Application candidate → allocation and numerous subsystem constructors, callback/data pointers and resource ID `0x65` for `LoadIconA`. Code ownership alone does not provide their data/resource definitions.

This tree provides initial bounded inventory roots; the actual linker graph must identify unresolved providers, calls through data/vtables and initializer dependencies. Do not edit signatures or supply fallback stubs before that graph is available.

## CRT and compiler variants

The 2,988 recipe entries select 2,713 `sp1`, 274 `rtm`, and one `vc8` compiler entry. The VC8 owner is `src/staging/blk_009e0000_o2.cpp`. The application-entry owner uses SP1 with `/MT /Od /Oy- /GS /EHsc /Gy /GF`. These are reference-build selections, not three ready-to-link runtime libraries.

Record each object's `.drectve` default libraries, exception/RTTI/security-cookie references and ABI before selecting a single runtime policy. Do not resolve competing CRTs with blanket `/FORCE:MULTIPLE` or assume that `/NODEFAULTLIB` plus arbitrary definitions creates a functioning runtime. Preserve RTM/SP1/VC8 identities in the inventory even when a later separately validated runtime selection differs.

## TLS: one template, many source aliases

PE TLS-directory metadata identifies template `[0x01272000, 0x012722c4)` (708 bytes), index cell `0x0126fd98`, zero additional fill and a callback array whose first pointer is null. This says nothing yet about the values or semantic initial state of individual fields. No template bytes were copied into this audit.

| Original location | Recipe evidence | Runtime obligation |
|---|---|---|
| `0x0126fd98` | 118 unit/name reference pairs; spellings include COFF `__tls_index` and `DAT_0126fd98` variants | One loader-managed static-TLS index cell; do not allocate an independent index for each spelling. Source `_tls_index` naturally decorates to COFF `__tls_index` on x86. |
| `0x01272000` | 297 pairs; `g_tls`, `g_tlsBlock`, audio/render/physics TLS structure views and `?__tls_index@@3PAEA` | One shared template base with verified field views and SECREL semantics. Distinct C++ names do not imply distinct template objects. |
| `0x01272268` (offset `0x268`) | 118 pairs, mostly console/debug echo flags | One field, not one independent bool per source declaration. |
| `0x012722b4` (offset `0x2b4`) | 206 pairs, memory-context/audio-thread spellings | One field shared by those views. `MemoryManager` initialization explicitly clears its `g_tls.m_2b4`. |
| `0x0126835c` | 218 pairs, Havok monitor-stream/TLS-slot names | Separate dynamic TLS-slot global used with `TlsGetValue`; do not merge with the PE static-TLS index or template. Establish its `TlsAlloc`/release/init owner. |

These counts come from `units[].symbols`, not definitions or proof of runtime providers. `tools/compare.py::Pe.secrel` already models static thread variables as template-relative offsets for reference comparison; that mechanism does not emit runtime storage.

Concrete collision: `src/fallout_shared/tesscriptfunctions.cpp` declares `__declspec(thread) unsigned char __tls_index[0x269]`, while `src/bscore/memorymanager.cpp` has `extern "C" int _tls_index` and an extern thread-local `g_tls` view containing field `+0x2b4`. The similarly named objects are different roles. Linking these declarations naively may create overlapping semantic aliases as separate allocations or conflicting storage types. Implement a canonical runtime TLS owner only after the COFF/SECREL inventory establishes its users, sizes, alignment and initial state.

## Global construction and persistent data

Initialization source is already present in five recipe units: `src/generated/global_object_initializers.cpp` (6,285 functions), `global_object_initializers2.cpp` (888), `global_object_initializers_o2.cpp` (928), and their two flag variants (14 and 1). Counts include compiler-generated helpers; they are not counts of independently ordered constructors.

The main generated unit explicitly says constructors, exit thunks and argument data are bound by original address and initializers run at CRT startup. For example `g_011c32f0` has initializer `0x00f35420`; its constructor `0x00a2e180` already has source in `src/gamebryo2.2/corelibs/nianimation/bsmultitargettreadtransfcontroller.cpp`. `GlobalObject_0040c150` constructors resolve to reference `0x0040c150`, whose implementation owner is `src/unmapped/setting.cpp`, under a different decorated type/signature. `0x004037b0` is owned by `src/bscore/bsstring.cpp`, again with a different spelling.

Therefore an extern constructor is not evidence that its body is absent. Conversely, generated header types with `char storage[4]` and address-bound constructor arguments do not establish complete runtime object sizes or data ownership. Audit constructor writes and user views before allocating storage. Retain each selected initializer/terminator once, determine `.CRT$X*` ordering and dependencies, and prove real startup executes them before game code. Never replace unknown data with zero-filled guessed arrays, discard unresolved initializer records, or rely on source-file order as proof of original initialization order.

The data backlog includes globals, literals, pointer tables, vtables/RTTI, constructor argument arrays and resources. A recipe symbol-to-address mapping is a comparison binding, not a definition of any of these. Establish real COFF providers and relocation graphs before generating missing-data work.

## Allocator ownership and ABI hazards

| Reference entry | Existing implementation owner | Obligation |
|---|---|---|
| `0x00401020` | `src/gamebryo2.2/corelibs/nimain/nismartpointer_h_unit.cpp`, `?FUN_00401020@@YAPAVMemoryManager@@XZ` | Singleton accessor; recipe binds its global manager to `0x011f6238`. |
| `0x00aa39c0` | `src/bscore/memorymanager.cpp` | Clears pool tables, initializes heaps and resets thread-local context. |
| `0x00866e00` | `src/fallout/misc/appmemory_console.cpp`, `MemoryManager::InitializeHeaps` | Constructs and assigns three real heaps; heap objects/constructors and bootstrap allocation must be supplied, not bypassed. |
| `0x00aa3e40` | `src/staging/blk_00aa0000_od_ob1_variant.cpp`, `MemoryManagerStandIn` method | Existing plain allocation implementation under synthetic naming. |
| `0x00aa4060` | `src/gamebryo2.2/corelibs/nimain/nipalette_od_variant.cpp`, `FNV_MemoryManager` method | Existing deallocation implementation under synthetic naming. |
| `0x00aa4150`, `0x00aa44c0` | `src/bscore/memorymanager.cpp` | Reallocate and Size paths also use CRT `realloc`, `_msize`, and `memmove`; preserve allocator pairing and fallback behavior. |
| `0x00aa13e0` | `src/staging/blk_00aa0000_o2.cpp`, `?FUN_00aa13e0@@YAXH@Z` | Bound by 533 distinct spellings including NiMemObject allocation operators. Source declares a void-returning function while callers can require a returned pointer: instruction matching alone does not express the full C++ contract. Verify return register and virtual dispatch ABI before selecting runtime aliases. |
| `0x00aa1460` | `src/gamebryo2.2/corelibs/nisystem/nimemobject_o2_variant_iso_variant.cpp` | 98 reference spellings, including sized-delete names. Preserve correct allocation/deallocation pairing. |

The `0x011f6238` manager has 789 unit/name reference pairs, including struct, class and pointer-looking declarations. Those views require layout and indirection validation; blindly materializing one global for every extern is incorrect. Address equality alone also cannot certify interchangeable calling conventions, return types or object views. Keep a canonical provider plus reviewed alias ledger, with incompatible uses explicitly unresolved. A prototype can reproduce correct instruction bytes while being semantically wrong at translation-unit boundaries; review return values, argument widths, stack cleanup, hidden `this`/structure-return parameters and virtual slots explicitly before accepting an alias.

## Imports and dynamically loaded dependencies

Read-only PE import inspection confirms 17 DLLs: `COMCTL32`, `d3d9`, `XINPUT1_3`, `KERNEL32`, `USER32`, `GDI32`, `ADVAPI32`, `SHELL32`, `ole32`, `steam_api`, `WSOCK32`, `d3dx9_38`, `DINPUT8`, `WINMM`, `DSOUND`, `binkw32`, and `libvorbisfile` (all `.dll`). The inspected image has no delay-import directory. The list is not a complete runtime dependency graph, and DLL presence is not proof of redistributable rights or matching x86 export ABIs.

A concrete linker issue already exists in the application-entry unit: `__imp_?GetCommandLineW@@YGHXZ` is bound at reference IAT slot `0x00fdf0f4`; PE metadata names that import `KERNEL32.dll!GetCommandLineW`. The source declaration lacks `extern "C"`. A normal Win32 import library does not supply that C++ spelling. Runtime-only ABI declaration normalization or explicit reviewed import aliases must preserve function convention and IAT indirection. Do not treat it as a missing implementation or resolve an `__imp_` pointer reference directly to a function body.

Dynamic evidence: `src/staging/blk_004c0000_od.cpp::FUN_004dd2c0` (`0x004dd2c0`) calls `LoadLibraryA("atiadlxx.dll")`, then `atiadlxy.dll`, and resolves eight `ADL_*` entrypoints via `GetProcAddress`. It returns failure when loading or resolution fails; this is a source-evidenced optional GPU-display capability path. Its RTM variant also declares the loader imports. This bounded inspection does not prove there are no other dynamically selected dependencies.

## Next bounded implementation tasks

1. **First x86 executable and real startup proof.** Build-tool owner: add a separate runtime target with a tiny original test entry, supported VC9 CRT, normal Windows imports, a real global constructor/destructor and static TLS exercised on two threads. Save link map, chosen libraries and observed checks privately. Then identify the actual CRT caller/parameter contract for `0x0086a850`; retain the existing application function rather than inventing WinMain absence. No game startup claim before its dependency closure is satisfied.
2. **Canonical startup closure and import ledger.** COFF/symbol owner: starting only at the `main.cpp` recipe unit plus its selected generated initializers, report actual undefineds, `.drectve`, `.CRT$X*`, EH/RTTI and imports. Classify provider, alias, missing data or unresolved ABI, with exact source owner. Resolve the demonstrated GetCommandLineW import spelling using a runtime-only mechanism and demonstrate the correct pointer indirection in the first link.
3. **TLS owner implementation after inventory.** Runtime/TLS owner: reconcile the five locations in the TLS table into one static template and separate Havok slot; establish field initialization/alignment and per-thread behavior. Introduce a runtime-only owner/header or reviewed offset-aware aliases, preserving reference units. Exercise memory-context and console-flag access across two threads without allocating duplicate aliases.
4. **Allocator and constructor bootstrap slice.** Runtime/data owner: follow the manager accessor, InitializeHeaps, allocation/deallocation and one real generated initializer/exit path listed above. Record exact global sizes and class layouts from source/relocations; reconcile constructor aliases and ABI before linking. Demonstrate allocations, frees, thread context and construction order in the private runtime. Expand toward full game-owned code/data/assets only after this slice works; a plugin, synthetic menu or link with guessed stubs does not meet the playable-game goal.

Verification performed for this audit: source/recipe ownership queries and bounded PE metadata inspection, including existing fingerprint probes. No source, oracle, service worker, original image or private reference image was changed. No image bytes, disassembly, copied binary or personal input paths are included here.
