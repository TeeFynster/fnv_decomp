# Read-only private PE data plan

`tools/rebuild/data_plan.py` inventories data storage extents and base-relocation
sites from an owned i386 PE32 file. It produces no data object, executable, raw
payload or disassembly. Successful analysis is **not approval to apply fixups or
link a runtime**. See [the data strategy](DATA-STRATEGY.md) for the storage and
lifetime obligations that this format analysis cannot settle.

Use Python 3.10 or newer. Supply the owner's on-disk image separately; the tool
does not locate, launch, download or modify the game. Reports stay private:

```powershell
python tools/rebuild/data_plan.py --image <owned-on-disk-PE> --reference <private-checker-image> --out build/rebuild/data-plan-new.json --details-gz build/rebuild/data-plan-new.jsonl.gz
```

`--recipes` defaults to `build/units.json`. With `--reference`, all section
headers and non-executable raw section identities must agree with the owned
image; the reference must also pass the existing `build/image_check.json` probe
threshold. `--image-check` permits an explicit fingerprint specification. The
owned image's executable payload is not read: its protected code may differ from
the compatible private reference. Only the explicitly supplied reference's
bounded fingerprint probes read code. Omitting `--reference` permits structural
analysis but establishes no game-image compatibility. The report distinguishes
these facts; it is not a complete input-image attestation.

`--out` is required and must not exist. Optional `--details-gz` must also be new.
Outputs cannot be input files or each other; creation is exclusive. Detail is
streamed to an automatically closed temporary file during analysis, then
published only after validation succeeds. Failed analysis publishes no detail
stream. Choose a new output name rather than overwriting an existing artifact.
The compact JSON report contains metadata, hashes and aggregate counts. Optional
gzip detail is streamed as JSON lines; each row is an address/fixup record, never
a copy of section bytes. No full inventory is retained in memory.

## What is checked

The reader bounds-checks headers, directories, raw ranges and logical virtual
ranges. It rejects non-i386/non-PE32 inputs, overlapping sections, malformed
relocation blocks, unsupported relocation kinds, duplicate/overlapping four-byte
HIGHLOW fields and fields outside a logical section. x86 HIGHLOW establishes a
four-byte loader fixup width; it does not prove a C++ pointer field type.
ABSOLUTE padding is skipped. No unknown relocation form is guessed.
To bound resource use, relocation directories larger than 8 MiB or more than
one million HIGHLOW sites are rejected explicitly.

Code/executable flags exclude a section even if it also advertises initialized
data. Resource and relocation sections are metadata exclusions; supported
non-executable initialized/uninitialized sections are candidate storage only.
Unknown content remains unapproved. The report preserves virtual extent, raw
extent, zero-fill derived from their difference and raw alignment padding. It
does not assign object sizes from the next symbol or treat file padding as an
object definition. A fixup field wholly in declared virtual zero-fill is analyzed
as zero with an explicit blocker; a raw/zero-fill straddle is rejected.

All HIGHLOW sites are checked for extent and overlap, including sites in excluded
code sections. Their executable payload is never read. Only candidate data sites
have target words inspected. Targets are classified against the authoritative
ordinary-function and EH recipe spans and PE metadata:

| Class | Meaning and limit |
|---|---|
| `ordinary-entry`, `ordinary-interior` | Address lies at/in a listed function; provider/ABI approval is separate. |
| `EH-entry`, `EH-interior` | Address lies at/in a recipe EH span; no inferred name is manufactured. |
| `EH-interior-ambiguous` | More than one overlapping EH span contains the interior address; unresolved. |
| `other-code` | Executable range not covered by these recipe spans; may be CRT/EH/helper material, not proof of missing source. |
| `data` | Non-executable section address; offset is section-relative, not a proven object-relative offset. |
| `TLS-template`, `TLS-index` | TLS-directory identity; fresh loader-managed runtime ownership is still required. |
| `import-IAT` | Address of an IAT cell; preserve pointer indirection and review interior/misaligned targets. |
| `resource` | Resource-directory range, not an ordinary global provider. |
| `unmapped-metadata`, `unmapped`, `outside-image` | Unsupported/unresolved target; no implicit rebase or guessed allocation. |

Every inspected site retains `semantic-field-type-unproved` and
`canonical-provider-unapproved` blockers. `approved_semantic_fixups` is always
zero and `runtime_ready` is always false. A target category is address evidence,
not semantic closure. Relative/RVA/encoded/runtime-populated references absent
from the base-relocation table are outside this inventory.

The legacy full oracle JSON has useful inferred EH observations, but does not
record pre-execution hashes binding all inputs. This implementation deliberately
does not consume those observations as verified bindings. It records that limit
instead of inventing a `verified=true` receipt or retroactive execution proof.
Future hash-bound observation ingestion is a separate task. A caller attestation
alone must not upgrade fixup readiness.

## Recorded private validation

On November 2, 2026, eighteen original synthetic tests passed. They cover virtual
zero-fill, ordinary/EH interiors, overlapping EH ambiguity, IAT indirection,
executable/mixed section exclusion, malformed and unsupported relocations,
overlapping fields/sections, wrong architecture, truncation, provenance mismatch
and overwrite rejection. No compiler, game process or service is needed:

```powershell
python -m unittest discover -s tests/rebuild -p test_data_plan.py -v
```

The private owned-image/reference analysis passed structural checks, exact
non-executable section equality and all 16 existing fingerprint probes. It
inspected 351,931 HIGHLOW records and 150,165 candidate non-executable data sites:

| Target classification | Sites |
|---|---:|
| Ordinary function entries | 87,022 |
| Ordinary function interiors | 228 |
| EH entries | 1,922 |
| Unambiguous EH interiors | 3,728 |
| Ambiguous EH interiors | 493 |
| Other code | 8,056 |
| Data | 48,714 |
| TLS template / index | 1 / 1 |

The 1,954 EH recipe spans include 62 adjacent overlapping interval pairs. Exact
entries remain identifiable; ambiguous interiors are not assigned to the nearest
entry. There are 8,549 explicitly unresolved target sites (8,056 other-code and
493 ambiguous EH interior sites). **All 150,165 semantic fixups remain
unapproved**, including the classified addresses, because full types, storage
ownership, canonical providers and lifetime have not been proved.

Private evidence is in `build/rebuild/data-plan-owned-v4.json` and its optional
streamed detail. The initial attempt rejected overlapping EH spans; its partial
gzip artifact was retained rather than overwritten. The corrected reader records
that genuine recipe ambiguity explicitly. No source, reference recipe, matching
oracle, owned image, running game or live service was changed.
