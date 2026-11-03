# CRT integration inventory and next bootstrap contract

Read-only inventory, November 3, 2026. This accounts for the **six distinct
original target identities classified as explicit normal-CRT candidates** by
the final [runtime binding plan](RUNTIME-BIND-PLAN.md). It is not a complete CRT
dependency inventory. The category is a per-use role, not provider adoption,
original payload equivalence, signature approval or runtime closure. No code,
native receipt, source, object or library was modified; no compilation, link,
DLL load, instruction decoding or execution occurred for this proposal.

## Exact evidence and scope

The complete final binding report and compressed detail were freshly hashed and
streamed. All 10,261 uses in this category have an actual selected-function
REL32 field, zero COFF addend, exact own-recipe numeric binding and exact
source-resolution consistency. Each record retains its physical object/symbol
index and source field offset; names were not globally merged. The six targets
have no selected ordinary-function body in that plan.

| Private input | SHA-256 |
|---|---|
| `runtime-bind-plan-native-v2.json` | `275714631903758efbf5a4f82e2428c6f51838f53b90d0c56d2e5dec5da1d804` |
| `runtime-bind-plan-native-v2.jsonl.gz` | `4dfc437064b16c1bb933008aebf7def8d279a903eef9cca24d0fedcc12d7d826` |
| Immutable retained manifest | `bc62a5fb2553431b1e0547d11f366e52efb73096ea8ceb206c556ae5740a53eb` |
| Retained v3 receipt | `04d44b73e81982f846bfe8d81806db72ea669586b579ff22007dfd6f7d831297` |
| Function selection v2 | `48ae62cdc5b1754b9c4af674ef4716d53afb554882e174a93acf860eaf1c6cb1` |
| Authoritative recipe | `62f2c8da5f0daa912abdf4576328706711c6561eef7f01c93a89cb71ad46fb6c` |

The new private metadata inventory
`build/rebuild/crt-integration-inventory-v1.json` is 2,474,181 bytes, SHA-256
`c0a34faa28dfff30ba42e364f39535c153ebec99c85556b0c9841376cd209624`.
It preserves every one of the 10,261 exact field uses, per-recipe source/object
hashes and bindings, compiler counts, selected library-member identities and
dependency metadata. It also records freshly checked hashes of the eight
representative retained objects below and thirteen source/header files.
This is a new metadata artifact, not a new native execution or byte-match receipt.
No original image payload was reread for this audit.

## Six-target accounting

Counts are selected-code **field uses**, not unique callers, missing functions
or startup reachability counts. Compiler columns describe the source object's
reference-build compiler; they do not select the provider's CRT version.

| Original target / actual COFF spelling | SP1 / RTM / VC8 fields | Total | Distinct recipe units |
|---|---:|---:|---:|
| `0x00ec43fb` / `___RTDynamicCast` | 1,679 / 11 / 0 | 1,690 | 371 |
| `0x00ec408c` / `@__security_check_cookie@4` | 2,043 / 88 / 2 | 2,133 | 524 |
| `0x00ec658f` / `_atexit` | 4,816 / 1 / 0 | 4,817 | 46 |
| `0x00ec62c0` / `__ftol2_sse` | 1,119 / 23 / 0 | 1,142 | 220 |
| `0x00ec6040` / `__CIsqrt` | 133 / 123 / 0 | 256 | 99 |
| `0x00ec7894` / `__CxxThrowException@8` | 222 / 1 / 0 | 223 | 29 |

Concrete source and physical-field examples, all bound to the corresponding
recipe's immutable object/source hashes in the private inventory:

| Recipe / selected source function | Exact field | Source evidence and limit |
|---|---|---|
| `0001-f1ee94d1632e46da`, `CameraPathManager::InitializeCameraPaths`, `0x0058b850`, `src/bgscamerapathmanager.cpp` | `+79` → `0x00ec43fb` | Explicit `dynamic_cast<BGSCameraPath*>` from the form lookup. This explains compiler RTTI use; it does not validate all runtime class metadata or object layouts. |
| `0002-72d0f307e5fdbf89`, `BGSEncounterZone::Load`, `0x00525d40`, `src/bgsencounterzone.cpp` | `+283` → `0x00ec408c` | Source uses `_alloca` for an editor-ID buffer; the `/GS` compiler emits the check. There is no handwritten source declaration/call that independently proves its machine register contract. |
| `0009-d9abba680e7db947`, `FUN_00ad9060`, `0x00ad9060`, `src/bsaudio/bsaudiomanager.cpp` | `+82` → `0x00ec658f` | A function-local static has a destructor. The source also declares `extern "C" int __cdecl atexit(void(__cdecl*)())`; registration is compiler generated. Object lifetime and callback closure remain separate. |
| `0010-4056cf21aa35c9cf`, `FUN_00adb690`, `0x00adb690`, `src/bsaudio/bsaudiomanager_ob1_variant.cpp` | `+106` → `0x00ec62c0` | Source converts `fSeconds * 1000.0` to `int`. The helper is compiler generated, not an ordinary declared `long(double)` API. |
| `0115-b9b815d1a05d96f9`, `IsWithinFadeDistance`, `0x00b4e030`, `src/bsshader/bsfadenode.cpp` | `+174` → `0x00ec6040` | Source calls `sqrtf(kDiff.Dot(kDiff))`. That source expression and the actual COFF helper use are established; the full helper floating-point contract is not. |
| `0741-ce8aa7ba226fb162`, `FUN_00ac0b00`, `0x00ac0b00`, `src/fallout_shared/facegen/bsfacegenmodel_ob1_variant.cpp` | `+89` → `0x00ec7894` | Source throws `std::length_error`. Recovered exception-class declarations do not independently validate original exception-object, ThrowInfo or destructor ownership. |

Bootstrap relevance is already concrete. The application candidate
`0x0086a850` in recipe `0576-dd603b7071c482c6` has its cookie-check reference at
`+4522`. The generated initializer units account for **4,765** of the 4,817
`atexit` fields: 2,901 in `global_object_initializers.cpp`, 443 in its second
unit, 42 in its optimized unit, 71 in setting EH initializers and 1,308 in
setting float initializers. For example, recipe `1678-5d04bbafe881aedd` has a
registration at initializer `0x00f35430 +29`. These functions need a fresh exit
registry and retained initializer ordering before application entry, not more
nominally resolved names. Generated placeholder storage is not approved by
these registration counts.

## Candidate native library providers

The first linker symbol table of each exact known `VC/lib/libcmt.lib` located
one member defining each requested symbol. Existing bounded COFF readers then
recorded definition section/value, whole-section hashes, relocations and member
undefineds. Temporary member files were removed. No library payload was copied
into tracked files. The private inventory holds full hashes for all 18 primary
members and twelve additional cookie/frame-handler member observations.

| Compiler family | Exact `libcmt.lib` SHA-256 |
|---|---|
| VC2008 SP1 | `bd9700d126d378f31f32736abc0c88cb08a8e0f0914acb6e2c8cbfd1ab99f411` |
| VC2008 RTM | `bd8fe9fa475deb84014af41870182b447bb969c91661d7012ae8d1b26bb6a86c` |
| VC2005 SP1 | `3bc6c5b90f8507964839fd0264d8565c3b766d01f9efcad336532a11e8f06ac3` |

| Symbol | SP1 / RTM member | VC8 member | Selected code-section bytes: VC9 / VC8 |
|---|---|---|---:|
| `___RTDynamicCast` | `rtti.obj` | `rtti.obj` | 213 / 213 |
| `@__security_check_cookie@4` | `secchk.obj` | `secchk.obj` | 15 / 15 |
| `_atexit` | `onexit.obj` | `onexit.obj` | 23 / 18 |
| `__ftol2_sse` | `ftol2.obj` | `ftol2.obj` | 171 / 171 |
| `__CIsqrt` | `_sqrt_.obj` | `sqrt.obj` | 186 / 186 |
| `__CxxThrowException@8` | `throw.obj` | `throw.obj` | 76 / 74 |

All six definitions are observed at value zero in their respective code
sections. Section size is **not** an independently recovered function extent;
a section can contain related entry points or helpers. SP1 and RTM have equal
selected-section payload hashes for these six entries. VC8 agrees for the four
other rows but differs for `atexit` and throw. Whole-member hashes differ even
where the selected section agrees. This is library-to-library payload evidence,
not a comparison against these six original executable bodies or a proof of
transitive relocation equivalence, state layout or cross-version ABI.

The exact compiler versions remain those already recorded by the toolchain
lane: 15.00.30729.01, 15.00.21022.08 and 14.00.50727.762. This task did not invoke
them. No `libcpmt`, debug CRT, dynamic CRT, modern UCRT or alternate provider has
been substituted.

## Contracts still needed

The following dependency names are actual **member-wide undefineds**, a
conservative dependency set rather than proof that every symbol is reached
from the named entry.

- **RTTI:** `rtti.obj` refers to `type_info`, bad-cast/typeid/exception classes,
  throw support, SEH prolog/epilog/handler machinery and string comparison.
  Microsoft's [RTDynamicCast documentation](https://learn.microsoft.com/en-us/cpp/c-runtime-library/rtdynamiccast?view=msvc-170)
  describes object/vfptr adjustment, source/target type descriptors and pointer
  versus reference failure behavior. It does not validate this game's recovered
  hierarchy tables or the original compiler revisions. A smallest later fixture
  would compile original single/multiple-inheritance classes, pointer success
  and failure, and reference failure with actual compiler-emitted RTTI; no manual
  guessed helper prototype or copied type descriptors.
- **Security:** `secchk.obj` refers to `___security_cookie` and
  `___report_gsfailure`. Normal startup must initialize the one selected CRT's
  cookie before protected code or initializer frames run; failure handling and
  related EH state belong to that same runtime. The old `process.h` in all three
  roots declares `void __cdecl __security_init_cookie(void)`. Microsoft also
  [requires initialization before protected functions](https://learn.microsoft.com/en-us/previous-versions/ms235362%28v%3Dvs.140%29).
  Nominal x86 decorated calling convention and identical library sections do
  not independently prove original frame/register handling. The next fixture
  below should cover valid `/GS` consumers and startup ordering; failure-policy
  testing is outside its first contract.
- **Exit registry:** `onexit.obj` refers to fresh begin/end cells, allocation,
  pointer encode/decode, exit locks and SEH helpers. Actual old `stdlib.h`
  declarations support `int __cdecl atexit(void (__cdecl*)(void))`.
  [Microsoft documents](https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/atexit)
  registration failure and reverse registration order. A fresh normal CRT must
  own this heap/registry/lock state. It must never interpret an old encoded exit
  pointer or run a destructor on an unowned game allocation.
- **Float-to-integer helper:** `ftol2.obj` refers to `___sse2_available`. The
  inspected code section contains compiler helper material; no direct public
  function prototype was established here. A later fixture should compile
  original conversion expressions with the actual frontends, check the emitted
  helper references and test finite in-range positive/negative fractions with
  exact expected integer results and preserved floating control/stack state.
  Invalid/out-of-range casts must not be used as an ABI test. CPU-dispatch state
  must be initialized by the selected CRT rather than copied from the old image.
- **Square-root helper:** the selected member refers to floating control,
  conversion, fast-path and error-handling helpers. Microsoft's
  [CIsqrt description](https://learn.microsoft.com/en-us/cpp/c-runtime-library/cisqrt?view=msvc-170)
  explicitly describes a compiler-understood stack convention. A later fixture
  should use compiled `sqrt`/`sqrtf` expressions and verify actual emitted entry,
  finite result bits and supported x87/SSE control state. A handwritten ordinary
  C prototype would not establish this interface. Domain, NaN and alternate
  control-mode behavior remain separate obligations.
- **Throwing:** `throw.obj` refers to the real `RaiseException` import. The
  [documented compiler-only throw entry](https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/cxxthrowexception?view=msvc-170)
  takes an exception object and ThrowInfo; it must not be called with fabricated
  metadata. The existing original EH fixture is useful single-toolchain
  evidence, not proof for original game handlers or mixed compiler metadata.
  The smallest later mixed-version extension would use compiler-generated
  throw/catch and observable copy/destructor lifetimes across a deliberately
  narrow type boundary, with every participating handler and descriptor owned.

## Obligations outside the six-target category

`___CxxFrameHandler3`, cookie data and `_purecall` have not been omitted or
silently adopted. They occupy different parts of the evidence graph:

- The actual main retained object has 18 relocations to `___CxxFrameHandler3`,
  all in `.text$x`, and no own-recipe binding for that name. Other exact recipe
  bindings identify `0x00ec3d33`; that is contextual evidence, not permission to
  import a global name binding into main. It is absent from this category
  because this plan scans selected ordinary function fields. All three native
  libraries define the symbol (`_trnsctrl_.obj` in VC9, `trnsctrl.obj` in VC8).
  Original parent frames, funclets, ThrowInfo/RTTI data, SEH chains and cookie
  interactions still need their own closed EH contract.
- Cookie data `0x011c16bc` has 7,310 selected-code field observations, classified
  as image-data ownership rather than a CRT function candidate. The main object
  separately has 21 whole-object references and an exact own binding. Native
  cookie/complement definitions are in `gs_cookie.obj`; initialization is in
  `gs_support.obj`. A four-byte size or source spelling does not authorize an
  old cookie overlay or independent duplicate allocation. Both normal startup
  and protected consumers must use the one fresh selected runtime's state.
- The [purecall contract](CRT-PROVIDER.md) remains separately evidenced: the
  1,013 unresolved **data-held** target occurrences, bounded SP1/RTM comparison
  and original normal-SP1 child fixture do not turn it into one of these six
  selected-code targets. Its hook, pointer encoding and abort policy remain
  fresh CRT state. That fixture does not approve a game vtable slot or any
  mixed-version CRT.

This proposal does not take over static-TLS template/index ownership. The TLS
owner's separate task remains responsible for that graph and its dedicated
compiler mechanism evidence.

## Compatibility decision and one next implementation

Do not select three libraries merely because three compilers occur, or force
all objects onto SP1 because several sections agree. The original recipe counts
are 2,713 SP1, 274 RTM and one VC8 entry. Only the cookie row in this six-target
subset has observed VC8 consumers. Shared exit tables, allocation state,
exception/RTTI layouts, compiler helpers and startup remain a combined contract.
Microsoft's [upgrade guidance](https://learn.microsoft.com/en-us/cpp/porting/overview-of-potential-upgrade-issues-visual-cpp?view=vs-2017)
does not support older CRT mixing simply because symbols link. Its
[modern compatibility promise](https://learn.microsoft.com/en-us/lifecycle/faq/visual-c-faq)
applies to v14-era tools, not VC8/VC9. A finite local compatibility experiment
must therefore remain research evidence, not a general vendor guarantee or
blanket production policy. No `/FORCE:MULTIPLE`, fabricated runtime definitions
or old CRT-state materialization should resolve a failure.

**Propose one normal GUI-startup, cookie and exit-registration contract fixture.**
It addresses the already observed application-entry check and thousands of
initializers. This extends the earlier SP1-only startup/purecall demonstrations
with a concrete cross-compiler consumer question; it does not repeat six
isolated arithmetic or error-handler probes.

Proposed new files, for a separate implementation assignment:

- `runtime/probes/crt_bootstrap_contract.hpp`
- `runtime/probes/crt_bootstrap_host.cpp`
- `runtime/probes/crt_bootstrap_sp1.cpp`
- `runtime/probes/crt_bootstrap_rtm.cpp`
- `runtime/probes/crt_bootstrap_vc8.cpp`
- `tools/rebuild/crt_bootstrap_contract.py`
- `tests/rebuild/test_crt_bootstrap_contract.py`
- `docs/rebuild/CRT-BOOTSTRAP-CONTRACT.md`

The SP1 host should enter through the normal GUI CRT and a correctly typed
original `WinMain`; it must not call the game application candidate. The three
small original consumer units use their exact old compiler and headers,
`/MT /GS /EHsc`, private C++ objects and plain fixed-width C event boundaries.
Retain and inspect real generated `/GS`, `.CRT$XCU`, destructor-registration and
callback references. Do not pass CRT/STL objects, exceptions, allocations or
RTTI classes across compiler boundaries in this first contract.

The candidate fixture runtime is one explicitly pinned normal SP1 static CRT,
chosen **only for this experiment**. First bind an all-SP1 control, then a
mixed-compiler consumer candidate, with actual default directives, maps, import
tables and library/member hashes showing the intended single state owner.
Successful linking alone is not acceptance. If an old consumer cannot link or
observe the finite contract honestly, retain the failure without overriding
duplicates, substituting code or broadening the runtime policy.

Cookie ordering needs independently checked evidence that the selected normal
startup calls cookie initialization before entering the first protected
initializer. An alternative is a truly unprotected early observation, with its
emitted code and placement independently checked: it must run before any
protected initializer and must not itself depend on `/GS`, EH or initialized
CRT/C++ state. A later cookie value, a successful protected return or the
initializer's presence in a map cannot establish this ordering alone. Observe
one canonical cookie/complement owner and valid protected calls from each
consumer without corrupting a frame.

The event channel must already work **before WinMain**, when generated
constructors run, and remain usable through normal CRT callbacks/destruction.
The parent should supply a deterministic inherited OS standard handle, with a
bounded fixed-format record protocol. The original sink can obtain that handle
and write each complete event directly through checked Win32 calls; it must not
wait for WinMain to initialize a handle or depend on mutable C++ global state,
CRT stream buffering, `printf` or final flush order. Independently validate the
handle inheritance, record-write bounds and pre-main usability. The parent
must retain the channel, drain it with a bounded reader and validate its full
contents after normal child termination; sink errors, missing/truncated events,
extra output or timeouts are failures.

Record the actual constructor and registration sequence, require each generated
constructor/destructor once and every explicit registration to succeed, then
check explicit callbacks in reverse registration order and generated destruction
against that recorded sequence. Do not assume translation-unit or source-file
order defines `.CRT$XCU` order. WinMain must return normally through the selected
CRT exit path. `ExitProcess`, `_exit` or another shortcut that skips CRT
termination cannot count as successful callback/destructor evidence. Repeat in
fresh bounded child processes with isolated UI suppression; no system settings
or game state changes.

Preparation must compile serially or within the two-slot budget and execute
nothing. Bind all sources, headers, compilers, libraries, directives,
objects/maps/executables and normal OS imports. Independent review must approve
the exact control and mixed candidate before separately hash-bound, timeout-
limited execution. Missing guards, stale input, wrong provider/state owner or
unexpected event order must fail. A pass would establish only this finite
bootstrap/callback/cookie boundary. It would not close original EH/RTTI/math,
TLS, game initializer storage, WinMain semantic arguments, assets, subsystem
startup or gameplay.

This proposal is saved for independent source/metadata review through the root
coordinator. No fixture files above have been created and no execution approval
is requested by this document itself.
