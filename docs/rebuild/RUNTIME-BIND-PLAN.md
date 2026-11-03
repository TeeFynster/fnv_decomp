# Per-field runtime binding observations

`tools/rebuild/runtime_bind_plan.py` is a read-only plan for the selected
source-built function fields. It derives original identities from exact
relocation operands, rather than treating the 174,649 raw unresolved COFF names
as missing functions or globally interchangeable symbols. It emits no source,
data, object, import library, aliases, executable or original-code fallback.
All providers, fixups, link readiness and runtime closure remain unapproved.

## Hash-bound inputs and output contract

Required inputs are the approved function-selection-v2, authoritative recipe,
immutable retained manifest, complete v3 per-function receipt, the owned
plaintext reference image, import-plan-v3 and the original compact relocation
audit. Each needs an explicit trusted SHA-256. Supply the audit's compressed
detail with `--audit-details`; its digest is bound by that compact audit. The
tool streams and reconciles all audit event counts and extracts every missing
field's exact recipe/function/original-field/native-section-offset identity.
It recomputes and compares both that exact missing set and the complete HIGHLOW
geometry partition, rather than copying or reducing the 88 missing fields.
See [function selection](FUNCTION-SELECTION.md),
[import planning](IMPORT-PLAN.md), [EH ownership](EH-OWNERSHIP.md) and the
[relocation audit](RELOCATION-AUDIT.md).

```powershell
python tools/rebuild/runtime_bind_plan.py --recipes <recipes.json> --recipes-sha256 <hash> --manifest <objects.json> --manifest-sha256 <hash> --retained <retained-v3.json> --retained-sha256 <hash> --selection <selection-v2.json> --selection-sha256 <hash> --reference <private-reference> --reference-sha256 <hash> --imports <import-plan-v3.json> --imports-sha256 <hash> --audit <original-relocation-audit.json> --audit-sha256 <hash> --audit-details <original-relocation-audit.jsonl.gz> --out <new-private-report.json> --details-gz <new-private-fields.jsonl.gz>
```

Optional `--eh <report> --eh-sha256 <hash>` and
`--overlay <hardened-overlay-result> --overlay-sha256 <hash>` retain separately
named candidate evidence. Their provenance/state and the supplied overlay's
generated artifact hashes are checked. The overlay object is never parsed or
substituted into the original retained-object scan, nor does it remove a
baseline missing-field record. The absence of either candidate report does not
authorize a guessed replacement.

Shared validated readers reconcile complete recipe/proof/source/object identity,
every selected physical field's function span, complete unique per-unit
verified-function coverage and exact selected-owner coverage. Original
comparison/producer source hashes, reference image identity and existing image
probes must agree. The actual normal import directory is parsed again and must
match the pinned import plan's DLL/name-or-ordinal/slot identities. Optional
function-index absence remains explicit, and presence/content changes fail.

Each retained object is loaded and parsed once, serially, from its exact
manifest path. No archive enumeration, compiler, linker or native process runs.
Only actual selected COFF fields, existing image fingerprint probes and actual
original PE HIGHLOW fields are read as code evidence; no instruction decoding
or search for address-shaped numeric constants occurs. All observed inputs are
rehashed before publishing results.

JSON inputs are capped at 64 MiB each, complete output records at one million,
and compiler string-literal projection at 65,536 bytes. Aggregate identity sets
are kept in memory; complete records stream through a temporary compressed file.
Outputs and the append-only fsynced progress journal require new distinct paths
outside protected inputs. Publication uses exclusive creation; failure removes
only files newly created by that attempt and retains an honest failure journal.
No raw code, literal contents, disassembly or private input paths enter reports.

## Field semantics and source consistency

The compressed schema-1 JSONL contains one
`SELECTED_FUNCTION_COFF_RELOCATION` record per selected physical relocation use,
plus separate `MISSING_ORIGINAL_HIGHLOW_SOURCE_MIGRATION_BLOCKER` records.
Each physical-use record identifies its recipe, selected function, source field
offset, native section/offset, original field VA, COFF symbol/index/section/value,
kind, width and addend. DIR32 and REL32 preserve both the final original target
identity and the symbol-base identity derived by subtracting the addend.

- DIR32 reads an absolute four-byte original operand.
- REL32 reads a signed original displacement and adds its exact original field
  end; the COFF addend is separately sign-extended. Neither is treated as an
  unsigned absolute field.
- DIR32NB records an original-image RVA projection, without calling it an
  ordinary absolute VA binding.
- SECREL validates the original TLS offset against the source binding and the
  image's TLS section, while retaining dedicated TLS ownership as unresolved.
- SECTION and other known special kinds remain explicit special/unsupported
  semantics. Unknown field widths fail rather than being guessed.

An additional narrow compiler-mechanism candidate preserves `__tls_array` with
an own recipe binding and zero-addend DIR32 numeric operand of 44 separately.
In the actual records the COFF symbol is undefined EXTERNAL (section 0/value 0),
not a section -1 ABSOLUTE definition. The value is a compiler/linker constant
lead, not a process VA or a data object. Its addressing-mode/segment semantics
are not decoded or approved. V2 keeps the numeric value only in the explicit
offset-candidate representation, with original-target/base-VA fields null.

Original-target consistency uses the unchanged comparator's per-unit rules:
own recipe/fold bindings, exact bounded native-function containment for local
labels and explicit source absolute symbols. It never consults a global name
map or the nearest function. A direct mismatch fails unless the unchanged
original `same_literal` rule accepts its literal-pooling tolerance. Such a
tolerance is separately labeled, with both original identities preserved;
it does not approve runtime pooling or waive stronger literal projection gates.

## Projection roles and unresolved owners

Exact targets are distinguished as selected code entries, unique code interiors
or local labels, ambiguous overlapping code interiors, IAT pointer cells,
fully evidenced compiler literals, native compiler-local EH metadata/helper
candidates, original image data requiring a canonical owner, TLS template/index
owners, explicit normal-CRT contract candidates or unsupported/unclassified
targets. Entry ownership and interior-label identity are not callable/frame ABI
approval. A source `__imp_` reference to a non-IAT target remains an explicit
pointer-role conflict; an IAT cell is never replaced by a function body.

The stricter compiler-literal projection requires an actual defined, readable,
raw-backed COFF source section, a complete compiler literal extent, exact
original content equality, immutable source/reference ranges and
no source relocations or intersecting original HIGHLOW fields. Only bounded
compiler-generated string COMDATs or exact floating/vector literal tokens are
eligible for that evidence. Ordinary named globals, writable storage, guessed
extents and pointer-bearing intervals do not qualify. Every original address is
preserved even when contents agree. This is a source projection observation,
not a runtime allocation or lifetime decision.

Native `.text$x`/`.xdata` or explicit CRT names are candidate roles only. They
do not prove EH parent-frame compatibility, CRT state ownership or a source ABI.
Original data references do not prove that a source global or a generated
four-byte class owns the complete runtime storage. Source absolute symbols
remain separately marked migration blockers even when their observed target
is otherwise classified.

The compact report has kind `fnv-runtime-binding-observations`, analysis-only
status, all input/report-detail hashes, event/kind/class/consistency counts,
unique exact-target count, per-source-name and same-unit name disagreement
counts, a separate actual physical-symbol-index disagreement metric, bounded
examples, and the original full retained EH notes. Complete
per-field identities remain in the gzip rather than a repeated manifest dump.
The 95 local EH diagnostics, strict-local-EH false result, absent index and
unselected runtime/provider states remain intact.

## Native observations and validation

Eighteen original synthetic tests pass, covering per-unit name
conflicts, IAT/function confusion, signed REL32/addends, ambiguous code interiors,
full readonly literal equality versus mutable globals, TLS/SECTION/RVA roles,
source absolute symbols, missing HIGHLOW relocation records, wrong operands,
stale metadata, a complete synthetic PE/COFF publication and late-input drift.
They also reject undefined/absolute/non-readable/non-raw literal proof, keep a
TLS numeric offset out of process-VA identities, and reject a changed missing
field identity even when its aggregate count stays unchanged.

```powershell
python -m unittest discover -s tests/rebuild -p test_runtime_bind_plan.py -v
```

Independent schema review preceded the first native metadata scan. The final
v2 scan processed all 2,988 retained objects, 68,657 selected functions and
68,667 checked recipe rows in approximately 29.55 seconds. It emitted 490,713
actual selected-function COFF field records and all 88 exact original missing
HIGHLOW migration records. The original partition remains 189,111 exact DIR32
geometry events and 88 missing fields, with the missing identities matched
against the independently pinned original audit detail. No overlay was adopted.

| Per-use target role | Field records | Distinct ordinary target values with this evidence |
|---|---:|---:|
| Selected code entry | 288,731 | 36,436 |
| Unique code interior/local label, no callable approval | 11,256 | 10,477 |
| IAT pointer cell | 6,744 | 212 |
| Full readonly/nonpointer compiler-literal projection | 18,478 | 6,186 |
| Compiler-local EH metadata/helper candidate | 6,468 | 4,254 |
| Explicit normal-CRT contract candidate | 10,261 | 6 |
| Original image data requiring canonical ownership | 137,062 | 45,357 |
| Static TLS index requiring ownership | 1,096 | 1 |
| Unselected executable target, unclassified | 7,507 | 363 |
| Unsupported/unmapped numeric target | 3 | 3 |
| Static TLS SECREL offset projection, special owner | 2,023 | Not ordinary VA fields |
| Compiler TLS-array numeric-offset candidate | 1,084 | Not process VAs |

These are per-use evidence roles, not a global code/data partition. The same
original address can have stronger literal or helper evidence at one use than
another, so the distinct-target column must not be summed. There are 102,230
distinct ordinary observed target values overall. Code-only field coverage
does not establish reachability or account for all original data-held pointers.
In particular, 212 IAT cells here include source spellings beyond the narrower
undefined-`__imp_` scope of the import plan; their signatures remain unverified.

Physical kinds are 190,252 DIR32, 298,438 REL32 and 2,023 SECREL fields. Source
resolution agrees exactly at 488,670 fields; 2,023 have only the dedicated TLS
offset projection, and 20 preserve the original comparator's literal-pool
tolerance with both addresses retained. No source/body or provider approval
arises from that tolerance.

There are 760 source names with multiple derived original base identities
globally, and 1,484 name/recipe pairs with multiple identities. These include
repeated compiler-local `$LN` names represented by distinct COFF symbol records.
The more precise actual `(recipe index, COFF symbol index)` metric finds **zero**
physical symbols with multiple observed original base identities in this scope.
Thus a global name map is inadequate, while these observations do not themselves
demonstrate a need to split a single physical symbol by field. All individual
field identities/addends and literal-tolerance facts remain available; these
metrics do not prove shared storage or erase any future conflict.

The 95 local EH notes, index absence and false runtime/provider/fixup states
remain preserved. Optional EH and hardened overlay inputs appear only as named,
hash-bound candidate evidence. The v1 result is retained as an intermediate
observation predating the explicit TLS numeric-offset representation and the
physical-symbol metric.

Private `build/rebuild/runtime-bind-plan-native-v2.json` is 24,445 bytes, SHA-256
`275714631903758efbf5a4f82e2428c6f51838f53b90d0c56d2e5dec5da1d804`.
Its complete compressed detail is 27,435,261 bytes, SHA-256
`4dfc437064b16c1bb933008aebf7def8d279a903eef9cca24d0fedcc12d7d826`.
The detail is larger because it preserves complete per-field provenance rather
than a sampled subset; the tracked documentation contains no code bytes.

## Smallest proposed linker extension

The next concrete extension should namespace a **closed, already reviewed
code-and-literal component's physical COFF symbols**, keyed by recipe/object
identity and symbol index, with original target identity/addend retained in its
binding table. Start with the existing
[scalar component](GAME-SCALAR-COMPONENT.md): one proved function and its two
complete source-built, pointer-free literal owners. Rewrite only its symbol
and relocation identities through a separately reviewed COFF writer; preserve
all payloads, flags, COMDAT associations, source proofs and original identities.
This is a proposed assignment, not an implemented transformation here.

First use original synthetic fixtures to test repeated names across objects,
repeated local names within an object, same-content/different-original-identity
literals, signed addends and changed output layouts. Reject a true conflicting
physical-symbol binding rather than silently applying a global alias. Then
reparse and byte/relocation-check the single selected component and its linked
literal fields under an explicit new policy and independent review. The existing
finite scalar ABI contract can supply later native validation if separately
authorized. Keep unowned data, IAT/CRT/TLS/EH dependencies and all missing-field
functions outside this extension until their contracts are closed. No copied
original code, fixed original-address fallback or general game relink belongs
in that first implementation.
