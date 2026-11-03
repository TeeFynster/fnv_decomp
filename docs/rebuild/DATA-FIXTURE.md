# Original data relocation fixture

This bounded fixture tests transformation mechanics only: original source-built
PE data becomes a standard i386 COFF data object, linked into a separately built
normal CRT consumer at a different preferred image base. It contains no game
source or data. All 150,165 real-game semantic fixups remain unapproved, and this
does not establish game data ownership, startup or gameplay.

`tools/rebuild/data_fixture.py` has no user-selected image extraction command.
Its `prepare` command compiles the named original fixture sources using the
exact existing SP1 toolchain selected by the private doctor report. Compiler and
linker hashes and version must match; implicit linker environment options are
rejected. Compiler commands run sequentially and must be coordinated with the
repository's two-job limit. Preparation never runs either fixture executable.

## Fixed ownership and output

The header asserts a 32-byte x86 payload with ordinary scalar fields, eight
authored bytes, an interior pointer at offset 16 and a typed `__cdecl` callback
pointer at offset 20. An address-shaped integer at offset 24 deliberately stays
numeric. The source also defines 8,192 bytes of zero-initialized storage.

Only these two source-owned ranges are materialized. Exact producer object and
map evidence must agree with the fixed layout and expected contents. Executable
payloads and CRT storage are never copied. PE HIGHLOW relocation sites touching
owned ranges must be exactly the two declared pointer fields. Unknown targets,
missing or extra fields, boundary-crossing fields, unsupported relocations,
overlap, TLS, metadata/IAT intersections and executable/mixed-code sections
reject preparation. A virtual-zero extent must actually exist; raw alignment
padding cannot establish the extent of an object. Raw-backed zero bytes and
virtual loader-zero bytes both contribute to the proved source-defined range.

The minimal writer emits `.data` and `.bss`, with no executable section. The
interior field becomes a DIR32 relocation against `_fixture_payload`, retaining
addend 10. The callback becomes a DIR32 relocation against the explicitly
undefined `_fixture_callback`, with addend zero. The consumer's original source
provides that callback; no game dependency or placeholder is involved. Standard
`@feat.00` metadata declares the code-free object compatible with SafeSEH. The
generated object is independently parseable by the existing strict COFF reader
and the toolchain's `dumpbin`.

Producer and consumer use different preferred bases and object layouts. The
consumer link must place all three named targets at different addresses, retain
the two symbolic relationships, preserve every nonrelocated byte, and provide
normal static CRT startup, `printf` and `exit` from `LIBCMT`. Direct imports must
be exactly `KERNEL32.dll`. This is a source-built fixture contract, not an ABI
contract for a game function.

## Review and execution

Private artifacts belong under ignored `build/rebuild/`. Use a new output
directory; existing artifacts are never overwritten:

```powershell
python tools/rebuild/data_fixture.py prepare --doctor build/rebuild/doctor-all.json --out build/rebuild/data-fixture-new
```

Preparation records source, tool, producer PE/map/object, selected data object,
consumer PE/map/object, compiler/CRT and direct/core Windows dependency hashes,
commands, map providers, observed owned extents and relocation proofs. These are
hash-bound command observations, not cryptographic proof of compiler causality
or a complete transitive OS loader graph. Logs and partial preparatory artifacts
may remain after failure; only a successful preparation publishes `prepare.json`.

An independent reviewer must inspect exact artifacts and create an exclusive
review receipt of kind `original-data-fixture-review`, schema version 1, with
`approved: true`, reviewer identity, exact preparation/executable/map hashes and
true checks for `data_ownership`, `linked_fixups`, `virtual_zero`, `normal_crt`
and `map_and_imports`. Execution requires that receipt's exact hash:

```powershell
python tools/rebuild/data_fixture.py execute --prepare <prepare.json> --review <review.json> --review-sha256 <exact-sha256> --receipt <new-execution.json>
```

The execution gate rechecks all protected hashes immediately before launching
the consumer. The consumer checks all four scalar values, eight bytes, interior
pointer identity, callback identity and 65 calls, all 8,192 initial zero bytes,
and writes then verifies every zero-storage byte. It emits one exact JSON result
and must exit zero with empty stderr. Failed execution records an error receipt.
The producer is never executed.

## Validation status

Fifteen offline synthetic tests passed during implementation, covering symbolic
addends, numeric preservation, virtual zeros, malformed/unsupported or unknown
relocations, boundary crossing, mixed code, TLS/IAT, overlap, ownership, stale
review/input hashes and output collisions. Repeat without native tools:

```powershell
python -m unittest discover -s tests/rebuild -p test_data_fixture.py -v
```

The private `data-fixture-v1` preparation passed without broadening the fixed
ownership policy. The producer's zero allocation contains 384 raw-backed zero
bytes and 7,808 virtual-zero bytes; the consumer's allocation contains 224 and
7,968 respectively. Both preserve the same source-defined 8,192-byte object.

Independent pre-execution review checked every bound input and artifact hash,
the emitted COFF with `dumpbin`, both PE layouts with an independent PE reader,
map owners, protections, payload content, both relocation sites, zero extents,
callback provider, normal CRT providers and direct imports. The review approved
only the exact hash-bound consumer. The resulting private `execution.json`
reports pass with exit status zero, empty stderr and the exact expected scalar,
byte, interior-identity, callback, zero-storage and writable-storage checks.
The producer was not executed. Preparation, review and execution receipts remain
private under ignored `build/rebuild/`; no game runtime result is established.
