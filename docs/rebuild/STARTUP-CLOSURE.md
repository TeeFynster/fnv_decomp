# Startup closure: retained-object evidence and first implementation contract

Scope: bounded inspection of retained native COFF at baseline `87eb937`, not a complete link graph or game launch. The full inventory owns global resolution. This document proposes a narrow implementation; it does not authorize automatic alias selection, signature edits or guessed runtime data. Existing reference units and oracle remain unchanged.

## Retained inputs and observed closure

The retained-object run `20261103T030230Z-7cfc935c` supplies these inputs. Each listed object was checked against its builder-recorded SHA-256 before inspection; the report and objects stay in private build output.

| Recipe identity | Object SHA-256 | Role |
|---|---|---|
| `0576-dd603b7071c482c6` | `a6c310961921f70eea2c70b9c18dba3d85ac19bffdfe3164922e9c3462ab425b` | `src/fallout/misc/main.cpp` |
| `1678-5d04bbafe881aedd` | `7cdcfe40803bbe2874b7edae06ee372329901f91867be56d923a4e6cb06388ca` | `src/generated/global_object_initializers.cpp`, two selected roots inspected |
| `2734-15835374a1b91660` | `10c9d726dbf44ac2258f10eecf1f3bbbeef95df9759de18d585756873643c1c1` | `src/staging/blk_00aa0000_o2.cpp`, allocation wrapper section inspected |

The main object has 240 external definitions, 2,088 undefined external names and directives `/DEFAULTLIB:"LIBCMT" /DEFAULTLIB:"OLDNAMES"`. Its relocations comprise 1,254 DIR32, 2,764 REL32 and one SECREL. These are whole-object counts, **not unresolved-game-function counts**. Its ordinary, EH and metadata sections include `.text`, `.text$x`, `.xdata$x`, `.sxdata`, `.bss`, `.rdata` and `.data`.

Application candidate `?FUN_0086a850@@YGHIIII@Z` occupies section 199 at offset zero. That section has 442 relocations, 432 targeting symbols undefined in this object and ten targeting definitions in it. There are 280 unique target names, including 25 imported-pointer names; all 280 have original-address bindings. Binding completeness does not establish provider completeness. Dead/unselected COMDAT references and references from the entire large main object must not be confused with the entry section's retained closure.

Native undefineds confirm `___CxxFrameHandler3`, `___security_cookie`, `@__security_check_cookie@4`, `__ftol2_sse`, `_atexit`, `__tls_index` and `__tls_array`. The last is bound to `0x2c`, a TLS access mechanism value, not an ordinary image data address. The normal x86 GUI CRT must establish exception/security/runtime state and execute initializers before application entry; do not generate a data allocation for every bound value. The original packaged PE header's entry remains unsuitable as sole application-startup evidence; see [runtime audit](RUNTIME-AUDIT.md).

## Bounded provider ledger

“Definition observed” below means a real external symbol exists in the hash-checked native provider object. “Candidate” means reference-address/source evidence, pending the full graph and ABI review. Different decorated spellings are intentional facts to resolve, not proof that bodies are absent.

| Actual main undefined / binding | Existing provider | ABI class and action |
|---|---|---|
| `??2@YAPAXI@Z` → `0x00401000` | Definition observed: `?FUN_00401000@@YAPAXI@Z`, recipe 370, `src/fallout/ai/middlehighprocess.cpp` | cdecl `void*(unsigned)`; source forwards to manager allocation. Entry section has three REL32 call references. Candidate for reviewed code-symbol remap, not CRT operator-new substitution. |
| `??3@YAXPAX@Z` → `0x00401030` | Definition observed: `?FUN_00401030@@YAXPAX@Z`, recipe 591, `src/fallout/misc/saveload/bgssaveloaddefines.cpp` | cdecl `void(void*)`; source uses manager deallocation. Present in the main object but absent from the selected entry section's relocations. |
| `?FUN_00401020@@YAPAUReceiver86@@XZ` → `0x00401020` | Definition observed: `?FUN_00401020@@YAPAVMemoryManager@@XZ`, recipe 1515, `src/gamebryo2.2/corelibs/nimain/nismartpointer_h_unit.cpp` | cdecl singleton pointer return; differing class/struct names require compatible pointer/indirection contract. Entry has one REL32 reference. |
| `??2NiMemObject@@SAPAXI@Z` → `0x00aa13e0` | Definition observed in recipe 2734: `?FUN_00aa13e0@@YAXH@Z` | cdecl allocation pointer result survives despite void source spelling; detailed proof below. Not an ordinary global-new alias. |
| Entry configuration calls → `0x00c3bd30` and adjacent setters | Candidate recipe 2766, `src/staging/blk_00c20000_od.cpp` | Function/callback argument-width contracts need per-use review; no automatic remap from matching address alone. |
| `0x00876ad0`, callback `0x0086a580` | Candidates `BGSSaveLoadManager::GetSaveDirectory`, recipe 599, and recipe 107 `src/bsmenu/xuserinterface.cpp` | Different spellings retain source ownership; callbacks and function pointers must be included, not only direct calls. |

No claim is made that these few entries close the application's 280-target graph. Data/literal/resource/vtable dependencies and address-interior relationships require their own providers. The first implementation should validate the remapping mechanism on a tiny proven slice while the full inventory classifies the rest.

## Canonical import specification: GetCommandLineW

Actual entry-section relocation at offset 619 is DIR32 to undefined `__imp_?GetCommandLineW@@YGHXZ`, bound by the recipe to original IAT slot `0x00fdf0f4`. Read-only PE import metadata identifies that slot as `KERNEL32.dll!GetCommandLineW`. The source declares an imported stdcall function with no parameters and a 32-bit integer return, then passes that return to command-line parsing. On this x86 target that returned value carries the pointer bits; no structure return or different argument cleanup is involved.

The canonical Win32 import-library spelling is **`__imp__GetCommandLineW@0`**. An explicit per-recipe COFF symbol remap from the former import-pointer spelling to this spelling is the preferred first fix experiment. Preserve DIR32 relocation type, operand addend and IAT indirection; never map it to code symbol `_GetCommandLineW@0` or a guessed numeric address. The import library must be the real x86 Windows dependency provider. Confirm that exact spelling against the selected import library before applying the map.

The adjacent entry relocation at offset 626 is DIR32 to `__imp_?CommandLineToArgvW@@YGHHPAH@Z`, bound to `0x00fdf270`, whose PE import is `SHELL32.dll!CommandLineToArgvW`. Its candidate canonical pointer spelling is `__imp__CommandLineToArgvW@8`. Review both arguments and pointer return as an independent two-argument ABI contract. Keep `LocalFree` ownership for its returned allocation. Do not generalize this proof to all 25 imports or all C++ declarations: structures, callbacks, widths and argument counts can differ.

Acceptance: a small original probe with the same C++ import declaration is remapped and linked against the actual import library; normal runtime execution obtains the command-line pointer and, separately, parses/frees arguments through the correct DLLs. Verify import-table identities and that the remapper changes symbol identity only. Separately verify the actual main object's two relocations resolve to those import-pointer symbols after transformation. This synthetic probe proves import mechanics, not game startup.

## Allocation wrapper: machine return contract

The retained allocation-wrapper object has one 62-byte `.text` COMDAT section (index 41), selection `no_duplicates`, defining `?FUN_00aa13e0@@YAXH@Z` at offset zero. Its only relocation is DIR32 at offset 23 to undefined `_DAT_011f6080`. An associative `.debug$F` section is attached. There is no observed EH/security dependency in this section's relocation closure.

Existing C++ source at `src/staging/blk_00aa0000_o2.cpp` describes size normalization (zero becomes one), size/alignment locals, manager/allocator indirection and a virtual dispatch with seven arguments. `src/gamebryo2.2/corelibs/nisystem/nistandardallocator.cpp::StdAllocator` independently declares the allocation slot returning `void*`, taking size/alignment references, allocation type, accuracy flag, file, line and function. This supports the semantic interpretation, but source types alone are not the decisive proof.

A bounded local check found the retained wrapper's entire non-relocation payload equal to the reference 62-byte span and its sole DIR32 relocation resolving to the recipe's expected target. This is a narrow one-function check, not a full official source-oracle run. Native-object decoding independently confirmed the same EAX/return behavior. Bounded read-only decoding of the owned reference image's complete 62-byte wrapper established:

- Its sole call dispatches via a register loaded from virtual-table offset `+4`.
- Neither instruction after that call writes EAX, and the function returns with no immediate stack-pop amount. Thus the virtual allocator's EAX result survives the wrapper; the wrapper's public calling convention is consistent with cdecl and its existing one-dword input declaration.
- Existing consumer `NiRenderedTexture::Create` (`0x00a7fc00`, `src/NiRenderedTexture.cpp`) calls `0x00aa13e0` at function offset 98 and reads EAX before any overwrite (the first read is two instructions after the call). Its C++ source constructs `new NiRenderedTexture` and uses the returned object.

Consequently, reusing the **already compiled** wrapper under a reviewed cdecl pointer-return symbol can preserve the required machine contract without changing the void-returning reference source or recompiling it under a new prototype. Blind source-level forwarding through that void prototype would lose the expressed result and is not acceptable. The virtual allocator's real provider, manager storage, initialization, null/allocation-failure policy and all allocation/free pairings remain outside this limited proof.

A future isolated ABI fixture may supply a clearly synthetic, typed virtual allocator whose slot `+4` records arguments and returns a known pointer. It can execute the selected real wrapper and verify size-zero normalization, alignment/type arguments, preserved return value and stack balance. Such fixture data is a test double only; it must never be promoted into a production manager or counted as game-runtime completeness. No game-image bytes or assembly listing were written for this proof.

## Recommended next implementation: fail-closed COFF identity remapping

This is a proposed subsequent experiment, not the current implementation assignment. First finish the full inventory-based canonical plan and obtain explicit approved contracts; do not rewrite COFF yet. Proposed owner: one linker/COFF integrator, with runtime ABI review. Proposed paths (not implemented): `tools/rebuild/remap_coff.py`, a small explicit `tools/rebuild/contracts/startup-slice.json`, and focused `tests/rebuild/test_remap_coff.py`. Keep outputs private and source-authored test fixtures in a separately owned runtime-probe area.

The contract manifest must record input recipe identity/object hash, exact source symbol, expected definition/reference kind, original binding, selected canonical spelling, ABI evidence, allowed sections/relocations, provider identity/hash and review status. Start with the two import-pointer names and the single allocation-wrapper definition; do not automatically rewrite other symbols. Import mappings target real import-library symbols; code mappings choose an address-specific identity such as `fnv_code_00aa13e0`. Distinct original addresses always retain distinct canonical identities even when their source spelling matches.

The writer must preserve section payloads, symbol indices, storage classes, section/value/type fields, auxiliary records and relocation target indices/types/addends. Symbol/string-table updates may change file layout; they must not change machine code or data payload. Unknown auxiliary records, weak extern behavior, incompatible existing names, missing bindings, wrong kinds or unexpected hashes fail closed. A later manifest generator may propose mappings from the full inventory, but must not silently approve them.

`/Gy` is helpful section granularity, not permission to strip arbitrarily. Selecting a function must recursively retain associative COMDAT and EH/unwind dependencies, section-defined helpers and relocation/data closure, including pointer-based calls. Rooted `.CRT$XCU` and exit-thunk relationships require explicit retention and ordering. COMDAT selection policies (`no_duplicates`, `any`, associative and others) must retain their meaning. Ordinary multi-function sections cannot be split by guessed offsets. Scope unbound/local symbols by recipe where necessary; do not merge TLS, address-interior aliases, globals, RTTI or vtables merely because names/addresses resemble one another. Never use `/FORCE:MULTIPLE` as selection policy.

First limited acceptance, before any full automatic canonicalization:

1. Synthetic COFF tests prove only approved names change, code/data section payloads and all relocation semantics remain identical, auxiliary/COMDAT records survive, differing-address collisions stay distinct, and malformed/unreviewed inputs are rejected.
2. Transform copies of the exact main import references and the exact wrapper definition. Reinspect them with the independent inventory parser; demonstrate unchanged payload hashes, relocation counts/types/offsets, symbol-index targets and associated-section relationships except for the named identities. The original retained objects remain untouched.
3. Run the import probe against real Windows import libraries and the allocation ABI fixture against the selected source-built wrapper section plus its reviewed closure. Verify return bits, arguments, stack balance and zero-size normalization. Document that the fixture is synthetic and not a game startup test.
4. Run the unchanged reference matcher on the affected source units as part of the separate oracle lane. A passing remap test is not a substitute for source matching. Use the full inventory to select the next genuine code/data closure; do not suppress unresolved dependencies with stubs.

After this experiment, the precise remaining gap is program-wide canonical ownership and data/bootstrap closure, not the feasibility of preserving an already-proven machine ABI. The existing original CRT/TLS probe reported by integration is separate evidence; neither that probe nor this proposed remap experiment reaches the full game application.
