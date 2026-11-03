# One normal CRT purecall provider contract

`tools/rebuild/crt_provider.py` investigates one CRT contract candidate for the
1,013 data-site occurrences targeting `0x00ec60fa` in the
[generated-code gaps audit](GENERATED-CODE-GAPS.md). This is a normal static CRT
provider investigation, not a newly written game function. No game fixup is
approved, original executable pointer retained, or program-wide CRT selected.
RTM and VC8 recipe units still require separate compatibility decisions.

## Bounded identity evidence

The `audit` command locates exactly one `__purecall` archive member through the
first COFF archive linker symbol table in each supplied native `libcmt.lib`.
Archives are bounded to 32 MiB, linker tables to 100,000 symbols and the selected
member to 1 MiB. Existing COFF/PE parsers inspect only that named member and
the named 42-byte reference target, plus the existing image fingerprint probes.
A temporary private member file is removed on exit. No library/game bytes or
disassembly enter reports or tracked files; inputs are never modified.

The fresh comparison passed all 16 existing image probes. SP1 and RTM each have
a 42-byte section defining direct COFF function `__purecall` at section 3/value
0. Twenty-two nonrelocation bytes agree with the named reference entry. The
remaining twenty bytes are five four-byte relocation fields:

| Offset | COFF kind | Dependency symbol | Observed original target VA |
|---:|---|---|---|
| 2 | DIR32 | `___pPurecall` | `0x01270464` |
| 7 | REL32 | `__decode_pointer` | `0x00ed0f92` |
| 21 | REL32 | `__NMSG_WRITE` | `0x00ed290c` |
| 30 | REL32 | `__set_abort_behavior` | `0x00ecf44c` |
| 38 | REL32 | `_abort` | `0x00ecf335` |

Both libraries have the same relocation names, kinds, offsets and zero addends.
The report derives original target addresses from the actual reference operands
and records their identities as **unverified**. It does not infer target bodies
or data lifetimes from a matching instruction skeleton. This is not a complete
relocation-identity MATCH or a new official game-source match.

| Input | SHA-256 |
|---|---|
| SP1 `libcmt.lib` | `bd9700d126d378f31f32736abc0c88cb08a8e0f0914acb6e2c8cbfd1ab99f411` |
| RTM `libcmt.lib` | `bd8fe9fa475deb84014af41870182b447bb969c91661d7012ae8d1b26bb6a86c` |
| SP1 selected member | `13ab03cb6fe2d9b6600a735ec0c4d6c019beef62cad6173e76c898bb481feab1` |
| RTM selected member | `f2bb237b539545b7fba3fe142ee3a5356e20ab0c8a06171c69edf189135a3399` |

Member sizes are 8,193 and 8,201 bytes; their archive header offsets are
7,129,866 and 7,133,868. These whole-member hashes can differ while the selected
function's nonrelocation bytes agree. The owned reference identity is the
existing retained-v3 image hash; no installed protected image was decoded.
Private `build/rebuild/crt-purecall-audit-v2.json` has SHA-256
`cb3e37d22132c9db7f0e7bd6dffe693eb897737566a810c0b2fd857287e8c0dc`.

## APIs and fresh CRT state

The actual VC2008 SP1 `VC/include/stdlib.h` declares `_purecall_handler` as
`void (__cdecl*)(void)`, `_set_purecall_handler`, `_get_purecall_handler`,
`_set_error_mode` and `_set_abort_behavior`, with `_OUT_TO_STDERR`,
`_WRITE_ABORT_MSG` and `_CALL_REPORTFAULT`. Its handler comment explicitly says
the handler never returns normally. This fixture therefore does not test a
returning hook. Microsoft's [handler documentation](https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/get-purecall-handler-set-purecall-handler?view=msvc-170)
supports process-wide handler replacement and restoration, but current docs are
not substituted for the actual old declarations.

Microsoft documents [the internal `_purecall` entry](https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/purecall?view=msvc-170)
as `extern "C" int __cdecl _purecall()` without a public header declaration and
as an implementation detail not intended for normal application calls. The
fixture uses an explicit declaration only for isolated conformance-test child
modes. It creates no C++ class or undefined pure-virtual dispatch.

The original source fixture `runtime/probes/crt_purecall_probe.cpp` uses normal
SP1 `/MT` startup. Its map must show direct `__purecall` and handler API providers
from `LIBCMT:purevirt.obj`, fresh hook storage from `inithelp.obj`, pointer
encoding/decoding from `tidtable.obj`, abort behavior from `abort.obj`, runtime
message output from `crt0msg.obj` and cookie initialization/storage from
`gs_support.obj`/`gs_cookie.obj`. An IAT slot named `__imp___purecall` is rejected.
No old hook, encoded pointer, abort state or security cookie is copied into the
new process. The normal CRT owns its state and startup; no duplicate state
definition or fixed-address fallback is supplied.

## Preparation, independent review and bounded execution

`audit`, `prepare` and `execute` are separate commands. Each requires a new
output path; no report is overwritten. `audit` requires explicit trusted hashes
for the reference and both libraries. `prepare` requires the audit's exact hash
and the same SP1 library. It compiles/links one fixture serially, checks compiler
version `15.00.30729.01`, inspects the actual map and imports, and records 23
input/output identities including source/runner/imported tooling, old API
headers, compiler/linker/dumpbin, static/import libraries, object/executable/map,
logs and the actual x86 OS `kernel32.dll`. Its direct import list must contain
only `KERNEL32.dll`; forwarded/transitive OS modules are not claimed as closed.

```powershell
python tools/rebuild/crt_provider.py audit --reference <private-reference> --reference-sha256 <trusted-hash> --sp1-lib <native-sp1-libcmt.lib> --sp1-library-sha256 <trusted-hash> --rtm-lib <native-rtm-libcmt.lib> --rtm-library-sha256 <trusted-hash> --out <new-private-audit.json>
python tools/rebuild/crt_provider.py prepare --sp1-root <native-sp1-root> --audit <audit.json> --audit-sha256 <trusted-hash> --out <new-private-directory>
```

No executable launches during preparation. Independent review must separately
write schema-1 kind `crt-purecall-fixture-independent-review`, status `approved`,
a reviewer identity, exact preparation/executable/map hashes and true checks
`source_no_virtual_dispatch`, `bounded_child_suppression`,
`normal_static_CRT_providers`, `hash_bound_inputs`, and
`expected_modes_and_failure_semantics`. Execution requires this review's trusted
hash, the preparation's trusted hash and an explicit opt-in:

```powershell
python tools/rebuild/crt_provider.py execute --proof <prepare.json> --proof-sha256 <trusted-hash> --review <independent-review.json> --review-sha256 <trusted-hash> --allow-execute --out <new-private-execution.json>
```

The runner rehashes proof/review and every prepared input immediately before and
after **each** child. Children have no stdin, captured output, no visible window
and a ten-second timeout. Python kills and waits for a timed-out direct child.
The fixture spawns no descendants. Every child first applies and verifies
process-local error/UI suppression: `SetErrorMode`, CRT error output to stderr,
abort-report flags cleared, and dynamically resolved `WerSetFlags`/`WerGetFlags`
confirming `WER_FAULT_REPORTING_NO_UI`. Missing/failed suppression exits before
calling `_purecall`. No machine or user settings are changed.

Microsoft's [SetErrorMode documentation](https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/nf-errhandlingapi-seterrormode)
describes the error modes and recommends the WER no-UI flag. That flag is absent
from the original Vista SDK; its Windows ABI value `0x0020` is also recorded in
the primary [Go Windows runtime definitions](https://go.googlesource.com/go/+/9922fb1d248467741150f62b8b6ca9b56c05176e/src/internal/runtime/syscall/windows/defs_windows.go).
The API is resolved from the already loaded system DLL, with successful calls
and returned flags checked before any failure-mode test proceeds.

The fixed child sequence distinguishes four outcomes:

| Child | Expected observation |
|---|---|
| `state` | Fresh null hook; set/get/restore round trip; exit 0. |
| `exit-hook` | Fresh null hook; installed hook prints marker and intentionally uses `ExitProcess(73)`. This says nothing about default abort policy. |
| `default` | Hook installed and restored to null; direct CRT entry prints no return marker and is expected to terminate with exit 3 and runtime error R6025 on stderr, under the fixture's suppressed UI/report policy. |
| `state` again | Another fresh process starts with a null hook and passes the round trip; prior child state did not persist. |

These are process-state and policy observations, not proof that a game vtable,
its IAT/data field, an old encoded hook or mixed-version CRT ownership is safe.
No returning-hook result is claimed. Failures and unexpected termination codes
are retained in an execution report rather than reclassified as success.

## Verification status

Ten original synthetic tests pass with no native launch. They cover archive
bounds/named-member selection, changed nonrelocation bytes and relocation
shapes, unknown/overlapping relocations, stale library/reference/proof/review
identities, no-opt-in/no-review rejection, distinct failure-mode expectations,
per-child input revalidation, and exclusive output creation.

```powershell
python -m unittest discover -s tests/rebuild -p test_crt_provider.py -v
```

The saved v2 preparation is `build/rebuild/crt-purecall-probe-v2/prepare.json`,
SHA-256 `7b629bdd4d57719ec0154178d5538498edc7a625c1d591025a2ab143072a6bc6`.
It compiled/linked and passed the map/import checks. Independent review checked
all 23 identities, the actual x86 imports, eleven normal CRT providers, child
guards, mode semantics and the synthetic tests before approving execution.
Private `independent-review.json` is 811 bytes, SHA-256
`0fae4653d2695311fc72c987e12e258566a10106cc67e9cbde0a0a1c20a7a274`.

The exact approved runner then passed all four bounded child modes: exit codes
0, 73, 3 and 0. The default null-hook child emitted the expected R6025 pure
virtual-call message on stderr and did not return to its caller. Both independent
state children began with a null handler and passed the set/restore round trip.
There were no timeouts or observed dialogs. This establishes the selected normal
SP1 CRT behavior under the fixture's deliberate process-local suppression; it
does not establish unsuppressed default UI/report policy or returning-hook
behavior. Private `execution.json` is 998 bytes, SHA-256
`e2dbba79951450746898f21d5b111ad2f3a3f32c7183342daaa31c3fd8b6ff90`,
and binds both preparation and independent review.

The audit/preparation reports are 4,302 and 5,661 bytes. Earlier v1 audit and
preparation files are retained as superseded intermediate evidence. No original
game dependency target identity was upgraded, game fixup approved, provider
selected, whole-program CRT chosen or game startup demonstrated by this result.
