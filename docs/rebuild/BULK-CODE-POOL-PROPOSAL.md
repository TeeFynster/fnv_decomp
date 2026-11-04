# Bulk unresolved CODE pool proposal

Produce a private unresolved CODE archive set for the **16,859 current
serialization candidates**, grouped by retained recipe, while retaining a
complete accounting record for all **68,657 selected owners**. This is a
proposed serialization target, not an executable link, source rebuild, runtime
provider decision or expansion of eligibility. The existing 51,798 blocked
owners remain blocked. A caller may retain a canonical undefined reference to
one of those owners; that does not borrow its unchecked/blocked body.

This assignment writes only this proposal. It has performed no object/archive
emission, native command, compilation, link or execution. Planning used the
saved inventory summary and a bounded prefix containing recipe 0000's metadata,
plus the exact saved manifest row. It opened no retained objects and performed
no new global source/object scan. The completed writer, policy and tests remain
frozen. Their measured bounded/native result is in
[RUNTIME-CODE-POOL.md](RUNTIME-CODE-POOL.md).

## Approved population and input identity

| Saved evidence | SHA-256 |
| --- | --- |
| All-size inventory summary | `02a77cce3f43c1786cd027e72ffb17e76ffe6766c2823872254015b6e40549f6` |
| Complete compressed inventory detail | `91cdc91af6530e6e80e2104cdfeb9bd6928e17fa0f75bcf066734985248f1031` |
| Authoritative recipes | `62f2c8da5f0daa912abdf4576328706711c6561eef7f01c93a89cb71ad46fb6c` |
| Retained-object manifest | `bc62a5fb2553431b1e0547d11f366e52efb73096ea8ceb206c556ae5740a53eb` |
| Retained v3 proof | `04d44b73e81982f846bfe8d81806db72ea669586b579ff22007dfd6f7d831297` |
| Selected owners v2 | `48ae62cdc5b1754b9c4af674ef4716d53afb554882e174a93acf860eaf1c6cb1` |
| Binding v2 / complete detail | `275714631903758efbf5a4f82e2428c6f51838f53b90d0c56d2e5dec5da1d804` / `4dfc437064b16c1bb933008aebf7def8d279a903eef9cca24d0fedcc12d7d826` |
| Data owners v1 / complete detail | `fac1496a2675e9a6b697d604c8d5b35a2e4b8bb6194e2ec823e5a37d1092f2e8` / `c54abfd434ac715a16d31711fa8afb498d4b41420bec3bfcc25347d0eab9bd08` |
| EH parent-role ledger | `1e08ae8a908dc0a9d7feba4e5fa3cbcfe3a5f9ed6be3004ed6ac8639497fd788` |
| Owned reference identity | `df1788907c6e26ef4df0b448ead526825336356b5606650165a1ce0825097eb7` |

The current census is fixed, including every size:

| Band, diagnostic only | Selected | Requested candidates | Baseline blocked |
| --- | ---: | ---: | ---: |
| 1–255 | 59,634 | 15,745 | 43,889 |
| 256–511 | 4,604 | 607 | 3,997 |
| 512+ | 4,419 | 507 | 3,912 |
| Total | 68,657 | 16,859 | 51,798 |

The candidate split remains 15,595 with canonical undefined obligations and
1,264 with owned fields only. These are previous assessment counts, not emitted
counts or runtime-ready functions. The 68,667 checked recipe rows, ten explicit
repeated-address selections, 88 missing fields/59 affected owners, 95 EH notes
and 128 unsuccessful EH pieces remain distinct conserved facts. No overlay or
future root-closure relaxation substitutes for the baseline.

### Old assessor versus corrected producer

The inventory pinned `runtime_code_pool.py` at
`06f373e8592571244b8e70c913a037812a73c856bc8e42b5b2c9b509b732ed81`.
The current producer is
`729f189e2893c7f3a3e3cd97df7d7381ac115169e1d75cf664e6bbc1c587b277`.
The reviewed delta adds the missing `coff_rewrite.py` dependency pin in
`verify_basis`; it changes neither `assess_parsed`/`index_object`, the policy nor
serialization. The parser/writer remains
`76244d2d4dca4c1f8aa72224be1ef5c92f68976b5cda7d31b5cfe23d3cc29e64`.
Exact old and new source snapshots and independent delta acceptance are saved;
the old receipt must keep its actual old producer hash. Do not relabel it as a
run of the new source or compare only a shortened hash.

A bulk producer must pin both the historical evidence and its newly reviewed
implementation/dependencies. Revalidate every requested root on its exact
manifest object with the unchanged current assessor and complete binding,
missing-field and EH joins, before computing a union. Compare the resulting
candidate key set, all per-root facts and blockers to the saved inventory, not
only the total 16,859. Then apply the additional union gates below. No root is
promoted merely because its old boolean is true. Changed objects, sources,
producer hashes, index state, field stream or eligibility are a global stop and
new review, not automatic candidate substitution. Fresh per-root eligibility
is necessary but is not itself union eligibility.

## Container and bounded production design

Use **one ordinary i386 COFF member per nonempty recipe union**. There are at
most 2,988 such groups; their actual candidate-group count is not established
by this proposal. Do not emit one object per function, combine compiler
variants into one synthetic object, or combine every recipe into a giant COFF
object. Each member retains a single real source compilation identity, the
original compiler/flags and the whole selected native sections from that
object. The 2,713 SP1, 274 RTM and one VC8 recipe counts describe the full
producer universe; candidate-group compiler counts must be measured rather
than invented.

Build a deterministic root/recipe plan first. Process the manifest serially;
only exact requested recipe paths are opened. Parse each required object once,
cache its structural index, collect the recipe's bounded field records and
construct one union. Keep one original object and one union in memory at a
time. Append verified union bytes to a **single private spool file** and fsync
a compact member ledger containing its byte offset, length, hash, recipe,
root-set digest and source/object proof identities. A private spool plus one
index avoids 16,859 small files and does not require all unions in memory.
The current in-memory `archive(members)` helper is not a bulk streaming writer;
the new streaming producer needs its own review and conformance tests.

Generate archive indices from the complete verified member/export ledger,
calculate all header/long-name/index sizes, then stream member ranges from the
spool to new exclusive archive files. Rehash each copied range. Whole shards,
not individual members, are the final publication units. Archive-relative
offsets differ from spool offsets and must be calculated independently.

### Microsoft limits and deterministic shards

The second Microsoft linker member has nonzero **16-bit, one-based member
numbers**, so one archive cannot index more than 65,535 object members. Its
offsets, the first index's offsets and counts, and standard COFF file offsets
have separate 32-bit bounds. This population's per-recipe upper bound of 2,988
members fits the ordinal limit; it does not prove a file-size bound. A future
per-function 68,657-member archive would exceed that limit. A recipe union also
avoids introducing that future problem unnecessarily.

Use deterministic shards ordered by authoritative recipe index, cutting only
**between complete recipe members**. Proposed fixed engineering ceilings are
60,000 members per shard and 1 GiB total serialized archive size, with checked
arithmetic also enforcing the actual COFF/archive format maxima. These are
container ceilings, not function-size eligibility limits. Include both linker
members, long names, every header and alignment byte in the predicted size.
Do not let a symbol/string table overflow despite a small code payload. A
member that cannot fit is an explicit new container blocker; do not truncate a
root, split a literal owner, insert filler or silently drop it. An all-candidate
run with such a blocker cannot claim complete all-candidate production.

The current universe has only 16,859 candidate code sections and two approved
literal sections globally, so its root-section population alone cannot exceed
the standard signed positive section-number limit of 32,767 within one recipe.
Actual retained metadata/section/symbol/string and relocation limits must still
be checked. Existing extended-relocation or unsupported auxiliary restrictions
are not relaxed. Shards use stable recipe member names, deterministic ordering,
zero archive timestamps and the already established two-index/long-name/padding
format. Global export ownership is verified across **all** shards, not only
inside each shard. Archive linker indices name defined public exports only.
Undefined references remain in member symbol tables and the separate complete
obligation ledger; they are not indexed as exports. Neither the archive set nor
that ledger chooses library search order or a runtime provider.

## Recompute a recipe union; do not concatenate one-root plans

The union root set is explicit and hash-bound. Start with complete selected
code sections plus the original directive section. Only the already approved
scalar's physical literal sections 25/26 may add data definitions. Recompute
associations, every retained symbol's disposition and every runtime edge over
that **whole root set**. A symbol converted undefined by one root may be the
actual retained definition of another root; blindly unioning the one-root
`undefined`/drop lists would corrupt that case.

Every retained runtime byte must belong to a complete checked selected span or
an explicitly approved complete literal owner. No unverified helper/tail,
padding guess, initializer array, EH piece or source placeholder storage is
admitted because another section in the object is selected. Known debug-only
children may be excluded with exact parent/section/relocation receipts.
Unknown/EH associations and current recipe-wide weak/common/SafeSEH/directive
blockers remain blockers for this baseline. All unselected extra bodies remain
unverified background content with explicit drop dispositions.

Use injective old-to-new maps for retained sections, primary symbols and every
auxiliary slot. Numeric indices remain immutable provenance keys; only the
new serialized object uses the new indices. Independently verify complete
output-slot coverage, auxiliary disjointness, exact relocation translation,
association remapping and absence of omitted-section number aliases. Retained
symbol values, full payloads, relocation kind/addend bits, protection/alignment
flags, checksum and supported COMDAT selection stay unchanged. Do not turn
`no_duplicates` into `any`, or create aliases to make duplicate definitions
linkable. Ordinary compiler metadata keeps its real values.

Per-section and per-symbol dispositions must cover the entire source object,
including file/debug auxiliaries and unverified unselected definitions. A
retained field to another retained root is an ordinary real definition use.
A real STATIC interior label in a retained checked section may keep its exact
offset with same-object physical proof; it is not a new exported/callable
entry. Cross-member interior identities stay undefined without a separate
owner/offset contract. Do not infer a prototype or change the allocator's
machine return behavior from its source spelling.

### Shared physical symbols and canonical name groups

Aggregate all per-use facts for an original physical symbol across every union
root before writing names. Require one consistent original base, role, field
semantics and provider identity; retain every final original target separately.
Conflicts block the group rather than cloning a physical symbol or changing
addends. A shared physical record is serialized once and every relocation
uses its mapped index. In particular, a shared IAT cell stays a pointer-cell
obligation, with authentic import ID evidence; source spelling is insufficient.

Definitions retain the established canonical name of their immutable
`(recipe ID, object hash, original symbol index)`. Undefined address-role names
remain the current `unresolved(original_base, role)` contract, preserving the
existing signed/unsigned addend bits. Selected code references use the exact
chosen physical code-provider identity even when that provider is blocked or
not in the archive. No arena-anchor rebasing, storage extent, signature or
actual import/CRT provider is inferred from a name.

Separate physical undefined records from different roots may legitimately have
the same canonical obligation name. The completed narrow `namespace` helper
intentionally rejects all duplicate target names. **It must not be weakened in
place.** The parallel v1 adapter is **all-undefined only**. Bulk use needs its
exact separately reviewed typed equivalence-group contract:

- Retain distinct physical records and indices; never coalesce symbol slots.
- Permit duplicate names only for proved equivalent EXTERNAL, zero-value,
  zero-section, no-aux reference records, with no retained definition in the
  group. Do not extend this v1 adapter to a definition-plus-references group.
- Require compatible role/base/provider and, for cells, exact import identity;
  no name-only equivalence and no definition-to-definition merging.
- Definition-to-undefined conversion remains a separate proved operation that
  rejects retained defining sections, unsupported auxiliaries and hidden
  frame/compiler targets. A hypothetical post-conversion zero record is not
  implicit permission to broaden the v1 adapter's reviewed original-record
  subset; unsupported conversion/group combinations remain blocked.
- Keep approved literal definitions under their physical source identity.
  A general undefined data reference is not redirected to a literal merely
  because its address or contents happen to agree.

The adapter's name-only phase changes only approved Name fields and string
length, preserves every numeric index/auxiliary/payload/relocation byte, and
has its own byte-change proof. Its later selection phase records conversions
explicitly. Referenced local-label names may receive unique physical names
while keeping STATIC storage/offsets, so fresh comparison metadata never
depends on globally ambiguous `$LN` spellings. Section-definition symbols and
compiler metadata keep their existing structural meaning. Any name group that
does not meet this exact contract is a new union blocker, not an alias guess.

A group containing one retained selected definition and separate references
to that identity is a **different, future contract**, not part of the
all-undefined v1 adapter. That contract would have to prove the one immutable
code-provider definition, every exact referencing identity/base/role, unchanged
record types/indices/addends and unique global export ownership. It would need
separate implementation, tests, source/output review and root authorization;
it cannot select an unowned data provider. Until then, such a mixed group is
an explicit union blocker. An all-candidate run encountering it is incomplete,
even if all individual roots were historical candidates. Do not promise that
the all-undefined mechanism alone can complete the full population.

### Shared literals, source groups and variants

If several roots in the scalar recipe reference one of the same two approved
physical literal owners, retain that complete section **once** in the recipe
union. Join every use's original-base/extent/content/nonpointer proof to that
physical owner. Do not duplicate the literal once per root or export it from
several shards. Equal bytes in different physical source owners remain
different identities. No new literal policy is proposed for other recipes.

Keep a source-group ledger mapping relative source path/hash to every recipe,
compiler and optimization variant, selected root set and retained literal set.
Do not infer that equal source, equal machine code, equal symbol spelling or
equal literal contents mean one runtime storage identity. The ten approved
duplicate-address choices remain exactly the existing choices; unselected
variant definitions are not additional providers. Other variants may provide
different selected addresses without combining their object-level globals.
All unowned data, CRT state, IAT cells and arena views stay canonical undefined
obligations; no source `.bss` or placeholder definition is retained. Exact
LIBCMT/OLDNAMES directives remain once per original recipe member, in their
original bytes/order. They are observations, not CRT adoption or permission
for automatic executable linking. No shard-wide guessed aliases/defaults or
new library-selection policy is introduced.

## First real multi-root batch

Use all six existing candidate roots of recipe `0000-674cf48524ad6cf3`, source
`src/NiRenderedTexture.cpp`, SP1 flags `/MT /O2 /GS /EHsc /Gy`. Source SHA-256 is
`fb8590bc8cc30dd2591c9588233a487b230b427b9453044bba77dc2f4dae8b04`;
the original retained object SHA-256 is
`4c82eab96222de5e1494f2cedafcfe5f09d727c364e3cbd93d267ad63e14fc39`.
These facts come from saved recipe/inventory evidence, not a new object read.

| Selected original ID | Old section | Old owner symbol | Complete code size |
| --- | ---: | ---: | ---: |
| `0x00a7fc00` | 3 | 8 | 304 |
| `0x00a7fd30` | 5 | 21 | 94 |
| `0x00a7fbd0` | 7 | 30 | 6 |
| `0x00a7fbe0` | 9 | 36 | 14 |
| `0x00a7fbf0` | 11 | 41 | 14 |
| `0x00be0b90` | 13 | 46 | 4 |

The fixed planned union has **436 checked code bytes**, the original 47-byte
directive section and no data definitions. Proposed retained sections are
`[1,3,5,7,9,11,13]`, with explicit debug child exclusions
`[4,6,8,10,12,14]`; revalidate these exact facts on the actual object after
source review/root go. There are 14 runtime fields and 13 distinct referenced
physical external records. IAT record 13 is shared by Create/Destroy: its
original pointer-cell base is `0x00fdf1c4`. The other IAT base is `0x00fdf1c0`.
The planned unresolved set comprises six code identities, two IAT cells and
five original-data identities. In particular the allocator `0x00aa13e0` remains
undefined and blocked; this pilot does not adopt its provider.

Emit one member with six code exports, preserving the already proved leaf
section as a regression anchor. Reparse the member and archive, compare every
root freshly with unchanged reference logic and an explicit physical-name to
original-base metadata view, and inspect the archive through separately
authorized Microsoft read-only commands. The 304-byte root prevents this pilot
from being described as tiny-only; the prior 614-byte bounded result remains a
separate regression, not a substitute for all 507 large candidates.

The pilot must retain accounting for all 68,657 owners: six requested candidates,
16,853 candidates explicitly not requested, and 51,798 unchanged baseline
blocked owners. It need not re-open unrelated objects merely to reproduce that
ledger. Its compressed coverage records refer to the exact saved inventory
rows/hashes and record the pilot selection separately. Shared literal and
equivalent-distinct-reference cases absent from this real pilot must already
pass original synthetic tests; do not claim the pilot exercised them.

## All-candidate mode and final receipts

After the multi-root mechanism and pilot pass independent review, an explicit
root-approved all-candidate mode requests the exact 16,859-address set. Reuse
the complete recipe/binding/owner/EH streams, retaining exact per-row ordinal
and hash joins. Open each required object once, serially by manifest. Recheck
its current source/object hashes and exact v3 native owners, run fresh per-root
assessment, construct the union, reparse it independently, and freshly compare
all its selected functions under the unchanged reference/fingerprint gate.
Load the owned reference once for the process; do not run a compiler per root
or alter the official/reference matching gates. Every actual field/base/addend
and full retained literal must be checked, not merely a sample of functions.

Require one coverage status per approved address, with no extra/missing/duplicate
keys. Keep baseline inventory status, fresh individual assessment, union
eligibility, emitted shard/member, fresh MATCH and runtime readiness as separate
fields. Baseline blocked rows preserve all reasons and their original evidence;
requested candidates can be `EMITTED`, `BLOCKED_UNION` or explicitly pending.
Do not rewrite an old candidate as historically blocked. A new semantic/hash
conflict stops the run; isolated unsupported union/container cases can be
quarantined only with exact owner coverage and a receipt marked **incomplete**.
No full-success/all-candidate completion claim is allowed unless all 16,859
requested roots are emitted and checked. Changing that target or adopting a
partial result requires an explicit root decision.

The 51,798 baseline-blocked records retain their hash-bound historical
observations; carrying them into complete accounting does not claim a fresh
body comparison or fresh eligibility assessment for an unrequested owner.
Requested candidate recipes and all shared producer/evidence inputs are
revalidated. If root later requires a fresh observation of every blocked
object too, that is an explicit wider read-only scope rather than an implied
claim hidden in the coverage total.

Expected full-success code exports are 16,859; the only permitted extra data
exports are the two proved scalar literal identities, each defined once. Thus
16,861 is an expected export count to verify, not permission to add records to
reach a target. Record the actual member/shard count, every definition's unique
physical owner, exact canonical undefined uses and their role/base/final target,
all shared-name equivalence groups, section/primary/auxiliary maps, dispositions
and reference-comparison results. Check exported identities globally across
shards; no duplicate selected definition and no hidden export is acceptable.

Persist a fsynced progress/member journal before long work and after each
verified spool append. Publish only new private output directories. A failed or
interrupted append is not an accepted member: reconcile exact saved length,
hash and ledger state; do not replay an uncertain publication or overwrite a
reviewed archive. Keep bounded buffers, one object pipeline and one archive
writer. Complete final inputs/producers/reference/index rechecks must pass.
Receipts bind archive set, spool/member ledger, compressed complete coverage
and obligations, source-group/variant ledger, source snapshots and tools.
Consumers require the complete matching receipt set, not file existence.

Preserve exact pre-emission source/test/policy/doc snapshots before any later
measured documentation changes. Record such post-run document-only deltas
separately from producer drift, following the corrected bounded v2 practice.
No private paths, game bytes, disassembly or generated objects enter tracked
source; generated data stays under ignored private rebuild output.

## Tests and review gates before implementation scales

New bulk tools/tests should be additive; the six completed bounded source,
policy and test files remain frozen. A reasonable separate implementation is
a per-recipe union planner/name adapter and a streaming archive writer, each
with independent verification rather than in-place broadening of the bounded
policy. Proposed tests are original authored fixtures, not copied game code:

- Two or more ordinary roots, shared physical references, retained same-object
  code entry/interior uses and omitted unsupported helpers; every union byte
  and symbol has ownership/disposition evidence.
- Repeated name/different physical identity, equal-content distinct literals,
  one literal shared by several roots, same-original-address contradictory
  owners, conflicting per-root base/role and def/undef disposition conflicts.
- Typed all-undefined equivalent groups, rejecting mixed definition/reference
  groups under v1, two definitions, IAT-role conflicts, mismatched import IDs,
  common/weak/aux conversions and guessed data aliases. A later mixed-group
  contract needs its own positive and negative tests rather than being enabled
  through the all-undefined suite.
- Exact section/primary/auxiliary bijections, forged maps/omitted-section aliases,
  signed REL32 and DIR32 addends, COMDAT flags/checksums, debug exclusions,
  frame/EH/SafeSEH/TLS blockers and unknown directive rejection.
- Streaming output byte-identical to the accepted small in-memory archive
  writer on supported fixtures; both native index representations, export
  lookup, long names, alignment and source-to-recovered-member hashes.
- Arithmetic/member-number boundary planning at 65,535/65,536 and 32-bit offsets,
  deterministic whole-member shard cuts, oversized indivisible member rejection,
  duplicate exports across shards, bounded spool recovery and interrupted
  final publication. Exercise planner limits without manufacturing filler code.
- Current-versus-historical assessor compatibility, stale dependency/source/
  reference/index detection, complete selected/candidate/blocked key coverage,
  all size/variant histograms and exclusion of the original missing-field set.

Independent source/schema review comes before any real pilot emission.
Root then authorizes that bounded Python phase; independent output review
checks maps/payloads/fields/proofs. Native archive-read conformance is a
separately authorized check of exact artifacts and pinned Microsoft reader
tools, with complete `/LIST`, header/symbol and both linker-member expectations.
It must cover each produced shard, not a sample, and never invoke executable
linking, raw-data/disassembly views or member execution. After the pilot,
all-candidate Python production and its complete native read-only reconciliation
need their own explicit root gates. No runnable Game target is part of them.

## Interfaces to parallel proposals

The [root-code closure proposal](ROOT-CODE-CLOSURE-PROPOSAL.md) owns any later
root-scoped relaxation of unrelated weak/common/SafeSEH records. This bulk
baseline consumes no such unlock. A later version may consume its hash-bound
root-set closure token, exact section/symbol roots, reachable associations and
fully enumerated exclusions. It must recompute closure for the **union**, not
combine independent one-root reachability certificates or drop SafeSEH handlers
that another retained root needs. A new policy/population requires new
accounting and source review; never silently expand 16,859 using that research.

The [data arena proposal](UNRESOLVED-DATA-ARENA-PROPOSAL.md) may consume the exact
canonical undefined demand ledger and source-group provenance. Existing code
field base/addend naming stays unchanged. New arena anchors, storage-domain
owners or pointer-field materialization require their own versioned contract;
the bulk pool supplies neither placeholder extents nor allocated data. Import,
CRT, EH/frame, initializer, startup and ABI decisions likewise remain separate.

The useful deliverable is a complete, source-linked relocatable CODE archive
set with honest unresolved obligations and conserved blockers. Archive
completion and Microsoft readability do not establish a complete link or a
playable game.
