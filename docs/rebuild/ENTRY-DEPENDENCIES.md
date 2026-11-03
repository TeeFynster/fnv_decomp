# Application entry selected dependency observation

`tools/rebuild/entry_dependencies.py` observes the selected CODE graph rooted
at exact application identity `0x0086a850`. It reads only the explicit saved
selection v2, binding v2 and all-size CODE inventory v1 metadata reports and
their two complete compressed detail streams. It opens no objects, source
bodies, image, archive or directory tree. Original comparison and the existing
writer remain unchanged. Actual saved-ledger observation requires independent
source/test review before execution. The first approved result follows below.

The binding stream is bounded to one million rows, each at most four MiB,
and consumed once into compact ordinal/hash/role/target references. Every
source joins the selected recipe, symbol, native section, offset and span.
Duplicate physical sites, stale identities, unknown classifications and absent
selected destinations reject the observation. Its complete class/event/kind
and consistency counts must agree with the pinned summary. The inventory
stream then reconciles every owner's exact binding ordinal/hash list, selected
native identity and complete owner coverage, with the binding sequence digest
and inventory event census. Zero-field owners remain explicit selected nodes.

Only explicit `SELECTED_CODE_ENTRY` evidence and unique interior owner evidence
create graph edges. Interior edges retain the containing selected owner and
never establish a callable interior ABI. The summary separately counts reachability
using only entry edges. Neither graph represents dynamically executed call
reachability: relocation fields include function-address references, and
indirect calls, data-held pointers, callbacks, initialization and unselected
executable targets remain unresolved frontiers. Missing selected mappings reject
the report rather than becoming invented graph nodes.

Boundary roles distinguish import pointer cells, unowned data, literal
projections, CRT and compiler EH candidates, TLS storage and numeric offsets,
missing fields and unknown executable/numeric targets. The executable boundary
is deliberately named “generated or unselected code unknown”; this observer
does not infer that such a target is generated code or choose its provider.
Addresses can have different per-use roles. Distinct ordinary targets per role
must not be summed, and numeric TLS offsets are not process addresses.

An iterative traversal and iterative strongly connected component algorithm
avoid recursion depth limits. Outputs distinguish field occurrences, unique
source/destination pairs, role-specific graph edges, selected universe,
reachable owners and current serialization categories. All reachable owner
blocker codes remain in a separate nonexclusive census. Serialization
candidate status does not approve a runtime provider, data lifetime, EH,
import signature or ABI, and reachability does not alter candidate status.

The private compressed detail preserves each reachable selected owner and its
inventory row hash, complete binding ordinal/hash references, every labeled
edge with occurrence count and every SCC membership. These references recover
the exact original signed addends, physical symbols and field provenance from
the pinned binding stream without copying payloads or source bodies. The
summary pins all five inputs and the observer implementation. The caller must
supply the reviewed observer hash through `--implementation-sha256`; that hash
is checked at entry and again before publication. Historical compiler counts
and source producer tool hashes are copied from the pinned inventory; they
remain historical provenance rather than a new comparison. Inputs are
rehashed before publication, including after compressed output. Outputs use
exclusive creation, cannot alias an input or this tool, and failed publication
removes only files created by that attempt. Existing outputs are never replaced.

Synthetic verification:

```powershell
python -m unittest discover -s tests/rebuild -p test_entry_dependencies.py -v
```

No compile, executable emission, linker, native call, image disassembly, service
mutation or model worker is involved. Publication requires separate review of
private metadata output; the repository license grants no distribution rights.

## First observed entry closure

Root authorized one serial metadata pass after independent source/schema
review. It completed with exit zero, inside the ten-minute, one-GiB practical
working-memory and 100-MiB output bounds; sampled process peak working set was
425,725,952 bytes. All five inputs and the observer remained hash-stable. The
test and then-current documentation hashes also remained unchanged. Independent
outcome review subsequently reconciled the complete metadata joins, closure,
edge counts and SCCs without opening original objects or the image.

| Observation | Count |
|---|---:|
| Selected universe | 68,657 |
| Entry-reachable selected owners | 16,838 |
| Reachable using entry edges only | 16,838 |
| Selected owners outside this observed closure | 51,819 |
| Reachable field occurrences, including missing fields | 164,265 |
| Role-specific directed owner edges / unique owner pairs | 65,220 / 65,207 |
| SCCs / cyclic SCCs / largest SCC members | 13,265 / 365 / 3,517 |
| Current serialization candidates / blocked owners | 1,205 / 15,633 |
| Missing original relocation fields / affected owners | 47 / 27 |

Interior-retention edges add no new owners in this particular observation;
their evidence remains separately labeled. The 1,205 serialization candidates
split into 933 with canonical undefined obligations and 272 with owned fields
only under the existing policy. Neither set is runtime-ready or emitted.

The summary is 4,833 bytes, SHA-256
`20638f661c8595d92230b34f8277c0d1ba9b5e0c03c09f4c745afa0659000c66`;
compressed details are 10,042,522 bytes, SHA-256
`9e2eb957ef26378561843c82bae6366400bfd1122e966193878b8747c22410be`.
Their private basenames are `entry-dependencies-native-v1.json` and `.jsonl.gz`.
Observer SHA-256 is
`3be7ec6ad07f6b9153783e94c55d69c6778211ac8790f66aa8064c7c16165ba9`;
the independently passed 14-test file is
`4a56b7a07e5a77d8f1fabdee6f492ff428133f1ae6196b20b25d36be42c646d7`.

## Concrete projects toward the entry link

Prioritize this observed closure rather than treating all 68,657 owners as an
immediate application link set. It is still an incomplete runtime dependency
graph, and future data/callback/provider closure can expand it.

1. **Review reusable CODE closure contracts, then apply them to exact reachable
   owners.** Overlapping blocker populations are 14,628 SafeSEH, 12,280
   weak/common and unsupported-auxiliary, 4,144 directive, 3,021 parent
   EH/association and 688 canonical-namespace-collision owners. These are not
   counts of independently broken functions. Current ordinary-root closure
   work covers only main recipe 0576 and allocator 2734, and the new expanded
   EH producer covers only IOTask recipe 0069. None generalizes automatically.
   The existing duplicate-undefined adapter owns main's indices 289/1392;
   further alias cases require their own exact field and physical-index proof.
2. **Close real provider frontiers before an application executable.** The
   reachable graph has 2,631 unknown-executable field uses at 190 exact targets.
   Main directly uses `0x00406d50` three times and `0x00ecc071` once. Across
   the closure `0x00406d50` has 389 such uses; the next largest unknowns are
   `0x00ec61c0` (225), `0x00ec7c56` (211) and `0x00ec782f` (167). These counts
   prioritize identity/signature investigations; they identify no library.
   Separate per-use CRT candidates cover cookie check `0x00ec408c` (574),
   float conversion `0x00ec62c0` (461), dynamic cast `0x00ec43fb` (409),
   throw `0x00ec7894` (70), square-root helper `0x00ec6040` (66) and exit
   registration `0x00ec658f` (30), based only on saved source spellings.
   The same `0x00ec43fb` also has 56 unknown-executable uses: a global target
   classification would erase that distinction. No CRT or library is selected.
3. **Advance data, imports and actual EH in parallel scoped components.** The
   reachable fields include 37,998 data uses at 10,255 per-use targets and
   2,521 IAT uses at 144 cells. Existing fixed data work supplies a proposal
   for only 16 aliases across two fragments and 20 main fields, with typed
   extents and runtime approval still false. EH candidate fields number 3,031
   at 2,141 targets; they do not prove frame compatibility. The EH owner
   currently handles only IOTask's parent/handler/unwind graph and one
   SafeSEH record; failed SubObjA evidence remains a separate negative case.
   Import signatures, callback contracts, TLS and fresh shared CRT state each
   remain explicit provider obligations, alongside startup host integration.
4. **Plan the large recursive component as a component, not thousands of
   leaf links.** The largest SCC contains 3,517 owners, excludes main, and has
   1,619 incoming and 24,957 outgoing role-specific selected-entry edges.
   Only 103 members are current serialization candidates. Its mutually
   exclusive blockers include 1,822 recipe-wide, 1,585 parent-EH, four missing
   relocation, two section/symbol and one other-field owners. Overlapping
   SafeSEH (3,361), weak/auxiliary (2,502) and EH/association (1,587) evidence
   makes independent root certificates insufficient to claim component closure.
   First specify complete physical root sets, omitted-symbol dispositions,
   associations, providers and signed field bindings; do not globally unlock
   this SCC with an ordinary-root or IOTask certificate.
5. **Repair missing-field source migrations under a separate runtime overlay.**
   Preserve the original 88-field baseline and reference sources. Exactly 47
   fields in 27 currently reachable owners need a reviewed source migration;
   no original-operand synthesis belongs in the writer. In the large SCC,
   these are `0x00509a10` offsets 73/83, `0x006dce10` offset 12,
   `0x0084e020` offset 26 and `0x009b3160` offsets 63/73. The largest remaining
   single owner is `0x008c7290`, with offsets 110/135/140/173/178/213/218.
   Exact original field VAs, recipe/native sites and ordinal/hash bindings for
   all 47 are retained in the private derivation below. Existing single-owner
   overlay evidence is unadopted and supplies no automatic repair here.

The follow-on prioritization reads only these saved outputs and their already
pinned binding stream, rechecking the requested ordinal/hash joins. It is a
derivation, not a second original-object observation. Its private
`entry-dependencies-next-projects-v1.json` contains all 190 exact executable
boundary identities and their complete 2,631 use sites, the six per-use CRT
identities, EH-candidate uses, the largest SCC membership and all 47 missing
field identities. It is 6,380,064 bytes, SHA-256
`eca726d106f800b023c831280c7f2ce7eb3d448a00a570f827dcd264d7dfc803`.
This derivation records hypotheses and unresolved work; it selects no provider
and changes no closure or runtime eligibility.
