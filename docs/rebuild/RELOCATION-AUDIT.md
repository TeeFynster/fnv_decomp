# Selected-code relocation audit

This read-only audit asks whether original PE HIGHLOW fields within selected,
byte-verified source function spans have compatible physical COFF references.
It does not decode instructions, scan numeric values for address-like constants,
rewrite code, add relocations, extract sections, select providers or run code.
A missing COFF field is a migration concern; it is neither a verdict against an
original submission nor an approved patch location.

`tools/rebuild/relocation_audit.py` requires exact SHA-256 pins for the approved
function selection, authoritative recipe, retained-object manifest, full v3
per-function proof and the same owned plaintext reference image. It reconciles
all recipes, proof/tool/source/object hashes, exact selected native section,
value and span, complete owner coverage, image probes and optional index state.
Objects are parsed serially once and all observed inputs are rehashed before
publishing the report. It performs no baseline recompilation or reference
comparison rerun. Hash-linked receipts are observed execution evidence, not
cryptographic proof of compiler causality.

```text
python tools/rebuild/relocation_audit.py --recipes <recipe> --recipes-sha256 <hash> --manifest <manifest> --manifest-sha256 <hash> --retained <v3-proof> --retained-sha256 <hash> --selection <approved-selection> --selection-sha256 <hash> --reference <owned-plaintext-image> --reference-sha256 <hash> --out <new-private-report> --details-gz <new-private-gzip-jsonl>
```

Outputs must be new distinct private paths outside protected inputs. Details are
staged in a closed temporary gzip stream before exclusive publication. Failure
removes only outputs created by that attempt; a new append-only, fsynced progress
sidecar preserves start, bounded object checkpoints and terminal status. Private
aggregate/details contain metadata, not raw code bytes or disassembly.

For every selected candidate, original HIGHLOW sites whose four-byte field
intersects its exact span are correlated to `section/value + original offset`.
Fields beginning up to three bytes before the span remain visible. Every COFF
record overlapping the physical field is retained, including duplicate or
partially overlapping records. Original and physical competing owners remain
explicit lists; no nearest-owner rule resolves them.

| Status | Observation |
|---|---|
| `EXACT_DIR32` | One exact four-byte DIR32 field. This proves geometry/kind compatibility only; target semantics remain unresolved. |
| `MISSING_COFF_RELOCATION` | No physical COFF relocation intersects a wholly contained original HIGHLOW field. |
| `CONFLICTING_FIELD` | Duplicate, partial or multiple overlapping COFF fields. |
| `STRADDLING_FUNCTION_SPAN` | Original HIGHLOW field crosses the selected span boundary. |
| `UNSUPPORTED_KIND` | One exact-position field has another relocation kind. |

A true REL32 field normally has no original HIGHLOW entry. That absence creates
no event or defect. Unknown COFF relocation kinds/widths reject analysis. Known zero-width
ABSOLUTE padding records establish no field and do not intersect runtime fields.
Only actual PE HIGHLOW and COFF relocation metadata supplies evidence. An
identical-looking numeric constant without such metadata is not scanned.

A separate event class records executable-section COFF relocations whose target
symbol has section -1 and a value within the original image. It retains the
physical field, kind, addend, exact symbol and all covering verified/selected
owners. Standard `@feat.00` and `@comp.id` metadata remain a separate category,
including if malformed address-shaped metadata were observed. The audit does
not infer direct function or IAT semantics from an absolute symbol spelling.

The approved selection and retained EH notes remain unchanged. Runtime eligibility,
link readiness, provider adoption, closure and approved game fixups remain false
or zero. Absence of a detected concern does not establish ABI, EH, provider,
startup, gameplay or executable relinking safety.

Fifteen synthetic tests cover complete/missing/conflicting DIR32, unsupported
kinds, true REL32, straddling starts and ends, competing owners, actual ABSOLUTE
symbols versus linker metadata, stale proof/image, native/selected identity,
address-shaped constants without HIGHLOW, a complete PE/COFF pipeline, output
collisions and late input drift. They use no game inputs or native execution:

```powershell
python -m unittest discover -s tests/rebuild -p test_relocation_audit.py -v
```

After independent source/schema review, the bounded actual metadata audit
processed all 2,988 retained objects, 68,657 selected owners and 68,667 checked
recipe rows in approximately 15 seconds. The image gate passed 16 of 16 probes.
The PE relocation directory contains 351,931 HIGHLOW sites in total; selected
code spans account for the following exact correlation events:

| Result | Events |
|---|---:|
| Exact DIR32 geometry/kind | 189,111 |
| Missing COFF relocation | 88 |
| Conflicting, unsupported or straddling field | 0 |
| Original/physical ownership ambiguity | 0 |
| Executable COFF reference to in-image ABSOLUTE symbol | 0 |

The 88 missing fields occur in 59 selected functions across 47 recipe units.
They require a separately reviewed semantic investigation before any relinking
or patch plan. No field was changed. The scan also counted 5,976 standard linker
metadata symbols separately. The full 95 EH notes, strict-local-EH false state
and absent optional function index remain preserved. All runtime and game-fixup
approval states remain false or zero.

Private report `build/rebuild/relocation-audit-native-v1.json` is 14,928 bytes,
SHA-256 `5f667f1bb8e4471ff4111b6a2faf00d04fb35db4e362c3d30520f9c156d3a33a`.
Its compressed detail `relocation-audit-native-v1.jsonl.gz` is 6,682,092 bytes,
SHA-256 `8d5cb3673ae6553ff188cbabedab82490acc716d14846f5a046fe3b309a34348`.
Independent light review verified both hashes, all event counts, exact field
geometry, empty missing-field matches, false safe-patch states and the 59/47
function/unit counts. The reviewer independently passed the 15 synthetic tests;
the complete native metadata scan was not independently rerun. No executable
was launched, and no original/reference baseline rerun was performed.
