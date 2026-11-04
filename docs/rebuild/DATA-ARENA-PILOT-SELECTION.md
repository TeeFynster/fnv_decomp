# Whole-fragment pilot selection: two raw storage candidates

## Current v2 proposal

November 3, 2026. Propose the existing whole 219-byte and 227-byte read-only raw
fragments below: **446 private initialized storage bytes, 16 explicit canonical
address aliases, and 20 real app-entry reference fields**. Neither fragment has
a HIGHLOW field. That is a measured property, not a pilot rejection reason.
Typed object extents, string lengths, runtime semantics and initialization remain
unapproved. Exact untyped storage projection does not require declaring them
complete initialized C++ objects.

This revises v1's overly restrictive selection conclusion. The v1 negative
receipt remains immutable, and its document version was preserved privately
before this update. Its large raw-fragment quarantines and live-receiver zero
storage blockers remain valid. The 5,001-byte raw interval is unnecessary for
this bounded pilot; no slicing or widening of the two selected domains occurs.

| Proposed whole fragment | Exact original interval | Storage / alignment | Canonical aliases / app-entry fields | Payload SHA256 |
|---|---|---|---:|---|
| `cb8d58d939251b22cc7429f62751a51e83d1c6f11abeef2489d3b96a973b7c1a` | `0x010828e9..0x010829c4` | 219 raw bytes; read-only nonexec; alignment 1 | 9 / 9 | `85075986c217c34e5e30b1db7ae066192496e1114d28afe108a34c150094cad6` |
| `a80a7435d3665b08022dc0a36be353e4ffafa56da5fd9b4337224164f96aedeb` | `0x010829fd..0x01082ae0` | 227 raw bytes; read-only nonexec; alignment 1 | 7 / 11 | `be434b05ac538cb305c1402ff6d341eddfb82c2db2fa60577898ad5e7e38bb84` |

Both fragments are wholly within the exact `.rdata` section, flags `0x40000040`.
Their owner-ledger domain ordinals are 84,924 and 84,926. The complete existing
field census proves zero contained HIGHLOW sites and no straddling site; no
relocation is manufactured to exercise the writer. Their payloads were read
only for hashing and compared equal between the full-hash-bound owned original
and reference. No original payload was emitted or embedded in tracked files.
The private receipt records original PE/raw-file geometry and full input hashes.

The exact known storage-domain evidence was streamed for intersections with
both complete intervals: neither intersects any source-literal, special/fresh
CRT/TLS/IAT, loader or conflicting domain evidence. This is bounded absence in
the current ledger, not a proof that every runtime representation is understood.
The excluded interval between these fragments remains excluded; no common
allocation, adjacency, ordering or cross-fragment pointer arithmetic is claimed.

The proposed aliases are address-only external definitions at these exact
fragment offsets; each has nullable type and object extent, not a four-byte
allocation:

| Fragment | Original base identities and physical offsets |
|---|---|
| 219-byte | `0x010828ec:+3`, `0x010828fc:+19`, `0x01082910:+39`, `0x01082924:+59`, `0x0108293c:+83`, `0x0108295c:+115`, `0x01082978:+143`, `0x01082990:+167`, `0x010829b4:+203` |
| 227-byte | `0x01082a00:+3`, `0x01082a10:+19`, `0x01082a28:+43`, `0x01082a38:+59`, `0x01082a48:+75`, `0x01082a7c:+127`, `0x01082ab8:+187` |

For each, use the existing shared `_fnv_undefined_` identity with exact original
base and `data` role. The 20 actual source bindings prove base equals final target
and addend zero. Each alias would define that same demanded identity in this
one physical fragment; it does not convert another source-base/addend expression,
select a duplicate source allocation or infer a typed extent. All canonical
spellings, original symbol indices, binding ordinals/hashes and field offsets
are listed privately. Existing entry code remains unmodified in this task.

The 227-byte fragment supplies actual entry inputs to `CreateMutexA` and
`MessageBoxA` through source-declared character arrays; its other addresses go
to existing game helpers. The 219-byte addresses likewise feed source helper
and shutdown-text paths. These are useful original entry storage dependencies,
not artificial zero checks. Their callers, imports and helper semantics remain
separate unresolved obligations; no call or link is authorized by this proposal.

The current serializer is deliberately `anchors_only`. Supporting these 16
interior alias records needs a separately reviewed source/schema extension that
proves exact fragment/offset/role identity, alias uniqueness and output symbol
indices without declaring typed extents. No current policy selection or emission
gate is changed. Exact payload retention is mechanical; RVA/encoded-content,
cross-fragment relationships and lifetime remain unresolved runtime flags.

Private v2 selection identity:
`c35bdda25e5f797da6e0b088ca1b78a8b461779c7f088d0bac951fba674a3893`.
It resides in `build/rebuild/data-arena-pilot-selection-v2/selection.json` and
includes all 16 alias demands, 20 field records, geometry, payload/input hashes,
the empty conflict joins and retained blocker families. No original data bytes
are in that receipt. Independent selection review precedes any source extension
or root projection decision.

## Large fragment: byte mechanics versus provider obligations

The 255,676-byte fragment still has 1,387 quarantined fields under the current
classifier. **All have exact original target addresses and exact-target addend
zero.** These are not demonstrated unreadable bytes, missing relocation sites
or unknown addends. The current implementation blocks them because its target
role requires stronger selected-owner evidence. Preserve that guard until an
explicit contract changes it; do not portray it as a fundamental COFF limitation.

| Current family | Fields | Exact mechanical fact | Remaining blocker |
|---|---:|---|---|
| Targets with source-literal projection alternatives | 1,359 | Raw HIGHLOW site, exact nonexec target and zero addend known | Competing physical literal ownership; no canonical source/arena definition selected. The byte demand can remain unresolved without choosing a source literal. |
| Unselected executable target identities | 28, seven targets | Raw HIGHLOW site and exact executable-range target known | No selected source/helper/CRT owner or callable ABI. No copied original code or guessed nearest entry is allowed. |

The executable subgroups are four singleton targets (`0x005dc0f0`,
`0x005dc1b0`, `0x005dc290`, `0x00dfddb0`) and three repeated identities:
`0x00ec9907` at six fields, `0x00ecb3a8` at twelve and `0x00ecb562` at six.
None is a listed recipe entry. The saved binding observations name the latter
three with stdio-related spellings; spelling alone does not adopt a fresh CRT.

A precise next provider-contract candidate is the twelve fields targeting
`0x00ecb3a8`: all four saved source binding observations for that target use
`_fread`. Review its source ABI, fresh CRT owner and data-held function-pointer
role explicitly. The singleton groups are smaller by count but lack a proved
source provider; they stay unresolved. Other stdio identities include multiple
spellings and must not inherit the `_fread` decision.

Separately, a future **exact-address unresolved-demand** contract could separate
target identity from owner selection: keep the exact original target, opaque
absolute32 representation and zero addend while recording uncertain owner/ABI
as obligations. For literal alternatives, a nonexec `data` address demand need
not choose one physical source literal. For unselected executable targets,
mechanical address knowledge must not claim a selected callable `code` provider
or reinterpret a CRT identity. If a new opaque role/namespace is required,
propose it explicitly and review compatibility with existing base-plus-addend
and shared canonical roles; no silent role relaxation or automatic bridging is
approved here. This can permit honest unresolved dependency assembly without
claiming runtime closure. It is separate from the small-fragment pilot.

## Historical v1 bounded negative report

November 3, 2026. **No fragment is selected for projection.** The bounded
application-entry and audited-initializer references reach six existing admitted
ordinary fragments, but none satisfies the requested small, understood,
whole-fragment pilot. The only reached raw fragment containing HIGHLOW demands
has 1,387 quarantined fields. The smaller zero fragment lacks a proved complete
storage/initialization contract. Slicing either to make it pass is not proposed.

This is a selection result, not a new census or an assertion that no suitable
fragment exists elsewhere. No original data bytes, object or executable were
emitted; no compiler, linker or native program ran. Existing tools, source,
policy selection and original receipts are unchanged.

## Exact bounded evidence

The read-only observation's detail identity remains
`0b1a982b8acf78e2d0fc33cf36f7d40f67b4c978c113f504a5ea792216bc5b57`.
Its summary is
`673ed7dcf9251f97680e37afb68c7d02fb70e1b0a04b6bc990831f0da43e1048`.
Only its existing fragment/field arrays and the exact saved binding stream were
read. Arrays were consumed incrementally; no producer observation was repeated.
All 150,165 existing plan-field records were streamed once to retain complete
field sets for the six reached admitted fragments. A first-pass bookkeeping
hash mistakenly used a whole-file read after the streaming scan; it completed,
and subsequent input/stability hashing used chunks. No original file changed.

The only roots examined are application entry `0x0086a850` and the previously
audited initializer/cleanup pair `0x00fa2380` / `0x00fd8e10`. Their saved binding
row counts are 442, four and two. Of these, 113 rows require original image data
ownership: 111 entry rows and one each from initializer and cleanup. The private
receipt preserves every one with exact binding ordinal, canonical row hash and
original record. Six admitted fragments contain 102 of those references; the
remaining references do not become ordinary admitted storage by proximity.

The exact current `src/fallout/misc/main.cpp` and generated initializer source
hashes agree with their retained manifest. The source neighborhoods establish
uses, not whole-fragment types or initialization. No source body was copied.

## Two closest candidates, neither eligible

| Fact | Raw candidate | Virtual-zero candidate |
|---|---|---|
| Fragment ID | `374b2034599e26fb66895c38ed20cdebd079783c94fde6c9ba470cacb54e88b4` | `60e462c8cf0aa37a10cb63d06563206fbf798b5ebfb9335d549d651eba9ba48a` |
| Original symbolic interval, exclusive end | `0x01183000..0x011c16bc` | `0x01268360..0x0126fd98` |
| Whole extent | 255,676 raw-backed bytes | 31,288 genuine virtual-zero bytes |
| Protection / fragment alignment | Nonexec read/write / 4,096 | Nonexec read/write / 32 |
| Original owner-ledger domain ordinal | 91,188 | 91,193 |
| Related entry binding rows | Seven | Three |
| Contained HIGHLOW fields | 13,869 | Zero |
| Current disposition | 12,482 symbolic unresolved; 1,387 quarantined | Mechanically zero-backed; whole-fragment semantics/lifetime unresolved |

Both are complete existing `ORDINARY_UNCLASSIFIED` domains, not new object
boundaries. The raw fragment ends at the excluded cookie cell. The zero fragment
begins after the separately reserved dynamic TLS slot and ends at the excluded
static TLS index. Boundary facts do not prove the enclosed ranges contain no
other unidentified runtime state. Neither marker nor original address implies a
fresh CRT/TLS owner, and there is no contiguity claim across the excluded cells.

The raw fragment's 13,869 exact field/demand identities are preserved privately:
9,791 have `data` role, 2,691 have `code` role and 1,387 have unknown roles and are
quarantined. Every record retains original site/target, exact-target demand,
zero addend, original owner-ledger ordinal and original row. The seven app-entry
fields are binding ordinals 159435, 159438, 159484, 159490, 159551, 159554 and
159555, at source offsets +330, +368, +875, +946, +1652, +1765 and +1771. They
refer to the pointer globals at original `0x011a2fe8`, `0x011a2ff0` and
`0x011a2ff8`. Source uses include window-class/name and window creation paths.
Those uses do not select all other data/code targets in the 255,676-byte domain.
The existing serializer's selected-fragment gate rejects its quarantined fields.

The zero fragment's three references are binding ordinals 159593, 159657 and
159660, at app-entry offsets +2168, +2646 and +2664. All target
`DAT_0126fac4`. The actual entry calls methods through that pointer, including
`FUN_00ec16d0` and `FUN_00ec1800`; source elsewhere also views it as a movie-player
pointer. Fresh zero storage is not the initialized receiver needed by those
uses. No constructor/assignment/lifetime graph for the complete 31,288-byte
domain was proved here. A null-only runtime demonstration would avoid the
actual requirement, and is not proposed.

## Other reached ordinary fragments

| Original start / existing whole extent | Backing | Relevant references | Reason not selected |
|---|---|---:|---|
| `0x010828e9` / 219 | Raw | Nine entry references | No HIGHLOW fields; source uses named address carriers, but complete interval semantics are not established. |
| `0x010829fd` / 227 | Raw | Eleven entry references | No HIGHLOW fields; no whole-interval ownership/type contract. |
| `0x0105ac7b` / 5,001 | Raw | One entry reference | No HIGHLOW fields; one source address use does not explain the complete domain. |
| `0x011c3200` / 676,188 | Virtual zero | 69 entry plus initializer/cleanup | Broad global/lifetime domain, including the already unclosed `g_011dee84` lead; no arbitrary cut or four-byte replacement. |

The full IDs, original domain records/ordinals, exact related binding records,
complete contained fields and sequence hashes for all six are retained in the
private candidate detail. No same-byte literal merging or source-owned interval
replacement was performed. Unknown typed extents remain unknown.

## Receipt and next decision

Private `build/rebuild/data-arena-pilot-selection-v1/selection.json` has SHA256
`9571a00e110eadbb900bf7b8b85ce9e563b10074ac3bc4b22507cd77e0e4f7a9`.
The complete candidate-field metadata identity is
`99daf14954a75d1e68f025534d46ab57528e0e13b11d4e23714c58bd8bb21281`.
The final stability receipt is
`1b6656b8d74809ba639c13aad85c7c8e7fedaa398025e23ddfba060afb44bbce`.
It records a corrected slash-separator lookup in the wrapper's final assertion;
the original selection receipt was preserved and all exact inputs/sources were
then rehashed successfully. No data drift was observed.

All five relationship families remain unresolved: cross-fragment, cross-domain,
RVA grammar, lifetime and unknown state. No field is changed from final-target
demand to source-base-plus-addend identity. No adjacency/order, type, initialized
object, provider, fixup or runtime approval follows from this metadata.

The concrete next decision is **not projection of either candidate**. First
resolve the raw domain's 1,387 quarantined targets and bounded semantic exclusions,
or supply independent source/format evidence for a genuinely whole smaller
domain. Any new partition must follow that evidence and receive its own metadata
review; it cannot be an arbitrary slice around a convenient address. For the
zero domain, establish the actual pointer initialization and complete excluded
state/lifetime scope before proposing its whole allocation. The existing DATA
fixture already proves mechanics and does not need another arbitrary pilot.
