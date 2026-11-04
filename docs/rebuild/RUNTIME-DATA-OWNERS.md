# Runtime data owner ledger

`tools/rebuild/runtime_data_owners.py` implements the accepted
[RUNTIME-DATA-OWNER-PROPOSAL.md](RUNTIME-DATA-OWNER-PROPOSAL.md) as metadata only.
It emits no original payload, storage, COFF, executable or provider. All runtime,
materialization, link and fixup approvals stay false/zero. The accepted proposal
and all existing hash-bound tools remain unchanged.

## Exact input and observation scope

The supported input anchors are data-plan-owned-v4 and binding-plan-native-v2,
with their exact saved SHA-256 identities. Their compressed details are pinned
by the compact reports. Authoritative recipe, retained manifest, full v3 proof,
selection and import plan must match the binding report and each other. The
owned reference is hashed and only its PE header/directory/TLS-directory metadata
is read here; this task performs no instruction scan or raw-byte extraction.

The driver reparses each exact manifest object serially once, validates complete
selected/native function identities and fresh source/object hashes, and derives
physical source-code provider **obligations**, keyed by recipe/object/symbol
index. It does not recompile or rerun the original comparison. All original
comparison-tool, implementation dependency and source inputs are rehashed before
exclusive publication, with optional function-index absence preserved.

## Output schema

The compact report has kind `fnv-runtime-data-owner-ledger`, schema 1,
`analysis-only` status and aggregate hashes/counts. The gzip JSONL contains:

| Event | Evidence and limits |
|---|---|
| `ARENA_GEOMETRY` | Complete logical section envelope, raw/zero extents, excluded raw padding, flags and observed PE alignment. Object type/extent and alignment approval remain null. |
| `SOURCE_CODE_PROVIDER_OBLIGATION` | Exact selected source/native identity and proved span; not callable, frame or runtime adoption. |
| `STORAGE_DOMAIN_EVIDENCE` | Exact import cells, PE-directory metadata, TLS/index, known cookie cell and full source-literal projection candidates. Other CRT/runtime state extents remain explicit unresolved obligations. |
| `DISJOINT_ARENA_DOMAIN` | Complete disjoint coverage of each envelope, including ordinary gaps and unresolved competing/special/source-projection evidence. |
| `DISJOINT_EXTERNAL_DOMAIN` | Excluded resource/relocation/other special ranges outside ordinary arenas, still disjoint and obligation-only. |
| `CODE_TARGET_OBLIGATION` | Grouped exact old targets plus complete hash/ordinal-linked code-field provenance and per-use roles. |
| `DATA_HIGHLOW_FIELD` | Every original seven-column v4 record, exact site identity, original target, source arena/offset, source-domain references and target view/provider candidates. |
| `ORIGINAL_TARGET_VIEW` | Arena-relative or code-interior view; unknown object offset/bounds/type remain null. |
| `MISSING_FIELD_BLOCKER` | Every original missing-field observation, unchanged, separately retained. No overlay substitution. |
| `STARTUP_LIFECYCLE_OBLIGATION` | Sole detailed real global lead, `g_011dee84`, with six exact fields/five functions, shared BSS and CRT slot, unproved extent and actual non-null lifetime blockers. |

The original 490,713 code-field rows are not copied wholesale. Each target group
retains the original binding-detail hash, every exact input row ordinal and a
canonical sequence hash. All source/native/physical joins, event/class/kind/
consistency counts, unique field keys and full group coverage must agree; no
source row may disappear silently. Original signed addends and target/base
identities remain available at the exact hash-bound rows. All 88 missing rows
are retained separately and are never replaced by optional candidate overlays.

For data-only HIGHLOW fields, the source COFF symbol base/addend is unknown and
remains null. The original row's target offset is preserved verbatim; an arena
relative offset is a separate geometry fact. Identical target values do not
merge different sites, and identical source literal payloads do not select one
runtime owner. Every literal candidate keeps its physical/original identity.

Special ranges may overlap in the input evidence. The ledger partitions them
into nonoverlapping segments and labels every distinct overlapping claim as
unresolved, including distinct candidates within the same family; there
is no priority-based owner choice. Source projections remain alternatives.
Resource/RVA grammars, cross-domain arithmetic, one-past aliases, unknown CRT
state extents, TLS mechanism constants and code/EH helper closure remain explicit
obligations. No address-shaped numeric scanning or fallback is available.

## Real global scope

The sole lifecycle focus is original `g_011dee84`. Exact source declarations,
placeholder-header identity, native symbol index 27506 in shared BSS section
6424/+120 and the `.CRT$XCU` record 6425/+11828 must agree. The observed four-byte
placeholder is never extent proof. Its initializer/cleanup identities are
recorded along with SceneGraph mutation, non-null destruction, constructor
machine ABI, fresh atexit ordering and duplicate-allocation suppression blockers. The seven
actual constructor/initializer/cleanup field edges must match the complete
selected binding observations, and the real SceneGraph assignment and non-null
cleanup statements are separately tied to current proof-bound source hashes.
These remain field/source observations, never lifetime or ABI approval.
A null-only demonstration is not proposed or executed.

The old 95 EH notes and all false/unselected states remain in the compact
report; the additionally reported false local-piece issue is not waived by an
empty diagnostic string list. No general game data universe is adopted.

## Invocation and recovery

Supply explicit hashes for all compact inputs and a new private output pair:

```text
python tools/rebuild/runtime_data_owners.py --data-plan <v4.json> --data-plan-sha256 <hash> --data-details <v4.jsonl.gz> --binding <binding-v2.json> --binding-sha256 <hash> --binding-details <binding-v2.jsonl.gz> --recipes <recipes> --recipes-sha256 <hash> --manifest <manifest> --manifest-sha256 <hash> --retained <v3> --retained-sha256 <hash> --selection <selection> --selection-sha256 <hash> --imports <imports-v3> --imports-sha256 <hash> --reference <owned-reference> --reference-sha256 <hash> --out <new-private-report> --details-gz <new-private-detail>
```

Outputs must be distinct and cannot alias protected inputs. Gzip detail is
staged before exclusive publication; failure removes only newly published
outputs. A separate fsynced progress journal preserves start, named-object
checkpoints and terminal status. Reports contain metadata/hashes, no original
bytes, disassembly or private input paths. Hash linkage is observed provenance,
not cryptographic proof of execution or complete program semantics.

Fifteen focused original metadata tests pass: arena overlap/hole coverage,
interior aliases, special/source conflicts, external resource ranges, complete
per-site identity, virtual-zero and boundary fields, exact code provenance and
signed addends, stale joins/counts, separate missing rows and wrong source/
placeholder rejection, same-family overlapping claims and wrong seven-edge/
source-statement lifecycle evidence without object-extent promotion.

```text
python -m unittest discover -s tests/rebuild -p test_runtime_data_owners.py -v
```

Independent source/schema review accepted the exact tool before root authorized
the read-only actual ledger run. The v1 run completed in approximately 43.7
seconds and rehashed all observed inputs before publication. No compiler,
linker, DLL load, materialization or native execution occurred.

| Observation | Count |
|---|---:|
| Arena geometry envelopes | 4 |
| Selected source-code owner obligations | 68,657 |
| Original data HIGHLOW fields, preserved exactly | 150,165 |
| Hash/ordinal-linked code-field observations | 490,713 |
| Original separate missing-field blockers | 88 |
| Distinct physical source-literal projection candidates | 10,882 |
| Disjoint arena-domain segments | 11,274 |
| Segments with unresolved overlapping claims | 968 |
| Code-target obligation groups | 102,232 |

There are 73,120 distinct data-target views. Every data-site row remains raw
backed in this saved input; the arena envelopes additionally preserve their
full virtual-zero storage geometry. Physical literal-candidate counts are not
unique original-address counts and must not be merged by equal content.
The sole lifecycle lead retains its six fields/five selected functions, seven
actual root field-edge observations and four source-statement observations.
Its object extent/type, ABI and SceneGraph/non-null lifetime remain unresolved.

Private `build/rebuild/runtime-data-owners-native-v1.json` is 27,903 bytes,
SHA-256 `fac1496a2675e9a6b697d604c8d5b35a2e4b8bb6194e2ec823e5a37d1092f2e8`.
Its gzip detail is 29,837,226 bytes,
SHA-256 `c54abfd434ac715a16d31711fa8afb498d4b41420bec3bfcc25347d0eab9bd08`.
The reviewed tool SHA-256 is
`9cbe1b28b5e5f5a440c4a7755bd76a1283f4325d2992800a16859e2819eb6304`;
test source SHA-256
`5f6d633e943a6d9835993083c18656ac924ba7d5891bdc1ae77e73eadcfa31b1`.

Independent output review reconciled all input/output hashes, every one of the
150,165 original data records, complete code-field group ordinals/digests, all
88 missing identities, arena coverage, overlap accounting, lifecycle evidence
and false approval flags. It did not repeat the original PE/object scan or
approve materialization. All 15 focused tests passed independently. The full
95 EH notes and optional-index absence remain intact; all runtime/provider/
materialization/link/fixup states remain false or zero.
