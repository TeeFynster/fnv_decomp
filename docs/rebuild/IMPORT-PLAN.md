# Static normal-import provider plan

`tools/rebuild/import_plan.py` joins the owned reference PE's normal import
directory to exact retained-object import-pointer uses. It is a metadata and
bounded operand analysis: no recompilation, import-library generation, linker
alias, DLL loading, export execution, source edit, provider selection or data
fixup occurs. Outputs are private. See the [retained verification](RETAINED-VERIFY.md)
and [earlier standalone alias probe](IMPORT-PROBE.md).

## Inputs and invocation

Supply explicit trusted SHA-256 identities for the authoritative recipe,
immutable retained manifest, full v3 per-function receipt and owned compatible
plaintext reference. The manifest must reconcile every recipe/compiler/source
identity; the receipt must bind exactly that manifest, recipe and image and
carry the full function/global-EH/original-parity passes. Every unit's
object/source/recipe identities must agree, and every verified-function row must
cover the complete unique recipe-function set and match its actual COFF
section/value/span. Actual object and source hashes are checked, not inferred
from another compilation.

```powershell
python tools/rebuild/import_plan.py --recipes build/units.json --recipes-sha256 <trusted-hash> --manifest <retained-manifest.json> --manifest-sha256 <trusted-hash> --retained <retained-verify-full-v3.json> --retained-sha256 <trusted-hash> --reference <private-owned-reference> --reference-sha256 <trusted-hash> --out <new-private-import-plan.json> --details-gz <new-private-uses.jsonl.gz>
```

`--root` defaults to this checkout and resolves relative source and optional
function-index paths. Object paths come only from the exact supplied manifest,
relative to its directory and optional `object_root_relative`. No filesystem
enumeration or archive search is performed. The existing image probes and
receipt's original comparison/producer source hashes must agree. An optional
index appearing, disappearing or changing hash fails. All observed inputs are
rehashed before report publication.

Each input JSON is bounded to 64 MiB by the shared hash-bound reader. The PE
reader validates standard i386/PE32 headers, section bounds, raw backing and
directories. Import descriptors are bounded to 1 MiB, the table to 16,384
imports, DLL base names to 260 characters and export names to 1,024 characters.
Non-ASCII or unterminated identities fail rather than being normalized. Uses
are bounded to 100,000 records and compressed as objects are processed serially;
the full COFF inventory is never retained in memory.

Outputs must be new distinct paths, cannot alias inputs, and use exclusive
creation. Compressed candidate details are prepared in an automatically closed
temporary file before publication. Failure removes only newly created output
files; existing evidence is never overwritten. Reports contain metadata,
relative repository source paths and hashes, with no original bytes,
disassembly, raw COFF payloads or private input paths.

## Exact import identity and evidence classes

Every normal import retains its original DLL spelling, exported name and hint
or exact ordinal, and original four-byte IAT-cell VA. `OriginalFirstThunk`
provides lookup identities. A `FirstThunk`-only fallback is accepted only with
zero descriptor timestamp/forwarder chain and no bound-import directory; a
bound or ambiguous fallback is rejected. Hints are retained as metadata, never
used to choose a function. Ordinal identity remains **DLL plus ordinal**: no
ordinal-to-API-name guessing or export validation occurs.

The tool streams undefined `__imp_` and `_imp__` COFF symbols and their relocation
uses. Each use retains recipe/object/source identity, native section and field
offset, relocation kind/addend, exact per-recipe binding when present, and all
covering verified-function field observations. There is no global-name lookup
or nearest-address fallback.

| Status | Meaning |
|---|---|
| `VERIFIED_FUNCTION_EXACT_IAT_USE` | Actual matched-function DIR32 field, zero addend, exact original operand identifies an actual normal PE IAT cell; any per-recipe binding agrees. |
| `UNVERIFIED_BODY_RECIPE_IAT_BINDING` | Per-recipe symbol metadata points to an actual IAT cell, but this relocation has no matched-function field proof. |
| `UNRESOLVED_UNVERIFIED_BODY_NO_BINDING` | Neither such field proof nor exact per-recipe binding is available. |
| `UNRESOLVED_BINDING_IS_NOT_IAT_CELL` | The purported import-pointer binding is outside the actual normal IAT-cell set. It is not silently treated as a function provider. |
| Other unresolved statuses | Nonzero addends, unsupported relocation kinds, conflicting verified operands/bindings, non-IAT operands, weak-external contracts or unused undefined symbols remain explicit. |

Only actual verified-function DIR32/zero-addend uses read a corresponding
four-byte original code operand. The exact function's original address plus
field offset locates it; instruction decoding and adjacent-code sampling are
unnecessary. The observed operand demonstrates an original **IAT pointer cell**,
not a direct function body. A wrong IAT cell, direct-body address or conflicting
binding remains unresolved even if the source spelling resembles a familiar API.

Source ABI facts are deliberately narrow: i386 COFF, the actual undefined import
pointer spelling, and a four-byte DIR32 field when applicable. Decoration does
not verify a C++/SDK declaration, return type, calling convention, argument count,
ownership or semantic API contract. Those remain false/unknown in the ledger.
Unverified body uses are never promoted from another function's successful
object-wide comparison. Duplicate source names with different exact IAT
identities remain distinct per-slot records and an explicit duplicate-name list.

Each import's future provider contract requires a normal import library
preserving pointer indirection and its exact DLL/name or DLL/ordinal identity.
Selected standard SDK library names are proposals only, with verification false.
Ordinal exports must be checked separately before any provider approval. No
`.def`, `.lib`, import thunk or alias is generated by this tool.

## Native result and remaining work

The complete native metadata analysis used the unchanged authoritative recipe,
retained manifest and v3 receipt identities recorded in the rebuild audits,
plus reference image SHA-256
`df1788907c6e26ef4df0b448ead526825336356b5606650165a1ce0825097eb7`.
All 16 existing image probes passed. In approximately 10 seconds it processed
all 2,988 retained objects and 9,700 import-pointer relocation uses:

| Evidence class | Uses |
|---|---:|
| Verified-function exact IAT use | 6,306 |
| Unverified-body per-recipe IAT binding | 3,263 |
| Unverified body with no binding | 123 |
| Binding outside the actual normal IAT-cell set | 8 |

The normal import directory contains 280 imports from 17 DLLs: 256 named and 24
ordinal. The ordinals belong to XINPUT1_3, WSOCK32 and DSOUND; no API names are
assigned to them. There is no delay-import directory in this input. Of the 280
cells, 184 have retained source aliases and verified-function-use evidence;
96 have no such observed source use. Absence from these retained-object uses
does not authorize dropping an import or claim it is unreachable at runtime.

Two source names map to more than one exact IAT identity:

- `__imp__FreeLibrary@4`: `0x00fdf07c`, `0x00fdf0a8`, `0x00fdf15c`.
- `__imp__SteamUser`: `0x00fdf484`, `0x00fdf49c`.

These sets are retained without assuming that their source names are correct or
their DLL/export contracts interchangeable. The eight outside-IAT binding uses
involve `FreeBlockImp` and a `BoneRecordArray` spelling and remain unresolved;
their pointer-looking names do not establish normal import ownership.

The original receipt's 95 local EH notes remain untouched and hash-bound;
the plan reports their count and strict-local-EH false state. All function and
import providers remain unselected, runtime closure remains false and approved
game fixups remain zero.

Private `build/rebuild/import-plan-native-v3.json` is 201,289 bytes, SHA-256
`e39b8db63ef73aea57b5dd4963ff29310524644ca36e137cd8b5461a3c90a23f`.
Its compressed detail is 318,241 bytes, SHA-256
`4731ab38156dc5c4d65cd9c0ba595c3a06ba3775ab6e9c226e74e388e07ffc41`.
Earlier private v1/v2 results remain intermediate evidence, not overwritten
receipts.

Thirteen original synthetic tests pass:

```powershell
python -m unittest discover -s tests/rebuild -p test_import_plan.py -v
```

They exercise actual synthetic PE/COFF joins, named/ordinal identities,
same-name/different-slot preservation, wrong-IAT and direct-body rejection,
nonzero/unsupported relocations, unverified uses, stale input hashes,
incomplete/duplicated or native-conflicting function records, malformed/bound
fallback descriptors and conflicting exact operand observations.

Next work is a separately assigned ABI review and export/import-library contract
for selected DLL identities, followed by a narrow alias-only fixture if approved.
The prior original import-alias probe also called the direct SDK APIs, so it did
not independently prove extraction of only an alias-selected import-library
member. This plan retains that limitation and supplies no stronger link or
runtime claim. It did not load a DLL, generate a library, apply an alias or execute
game/OS code.
