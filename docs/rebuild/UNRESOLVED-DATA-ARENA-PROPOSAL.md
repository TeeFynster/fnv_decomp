# Private unresolved data arena projection

November 3, 2026, America/Chicago. This is a read-only implementation proposal.
It authorizes no materialization, compiler invocation, link, execution, provider
selection or original game initialization. Existing data, TLS, scalar, binding
and code-pool tools and receipts remain unchanged.

The next useful artifact is private **data-only COFF with unresolved symbolic
references**, accompanied by a complete storage and field ledger. It may preserve
owned non-executable initial storage without pretending that every view is a
typed object. An unresolved object is a transformation artifact, not an accepted
runtime provider. No original executable payload enters this projection.

## Existing evidence and bounded scope

Reuse [DATA-STRATEGY.md](DATA-STRATEGY.md),
[RUNTIME-DATA-OWNERS.md](RUNTIME-DATA-OWNERS.md), its accepted
[owner proposal](RUNTIME-DATA-OWNER-PROPOSAL.md), and the current
[code-pool contract](RUNTIME-CODE-POOL.md). The saved owner ledger reports four
geometry envelopes, 150,165 exact original HIGHLOW fields, 73,120 distinct target
views, 10,882 physical source-literal candidates and 11,274 disjoint arena-domain
segments. Of those segments, 968 have unresolved overlapping claims. These are
metadata observations, not four approved storage providers. All 88 missing code
fields, the complete 95 EH notes and false approval states remain blockers.

The existing envelopes distinguish logical storage from raw file padding:

| Candidate | Logical extent | Raw-backed logical bytes | Loader virtual zeros | Required original protection |
|---|---:|---:|---:|---|
| `.rdata` | 1,716,300 | 1,716,300 | 0 | Read-only, non-executable |
| `.data` | 977,564 | 262,656 | 714,908 | Read/write, non-executable |
| `CONST` | 31 | 31 | 0 | Read/write, non-executable despite its name |

The `.tls` envelope is excluded entirely from ordinary arenas. Its 709-byte
section and 708-byte directory template are different extents. Raw section
padding, including 436 `.rdata` bytes and 481 `CONST` bytes, is not logical data.
Actual supplied PE headers, raw bounds and directory ownership must be rechecked
by a future writer; these numbers are not hard-coded extraction instructions.
`CONST` remains quarantined until its semantic/domain classification is reviewed.

The compact owner ledger was rehashed in this planning task; its identity is
`fac1496a2675e9a6b697d604c8d5b35a2e4b8bb6194e2ec823e5a37d1092f2e8`.
Its existing compressed-detail identity is
`c54abfd434ac715a16d31711fa8afb498d4b41420bec3bfcc25347d0eab9bd08`.
The compact v4 data plan was rehashed as
`127644b75ed0c2826a3c1d89e4718076f4617b5a0d1f949b5faa4d61f54e6e93`.
This task read those exact compact reports and tracked contracts; it did not
repeat their full PE/object/detail scans or create a new data census.

## Arena geometry is not typed initialization

An arena envelope records original section identity, logical size, file-backed
intervals, genuine virtual-zero intervals, PE alignment/protection and disjoint
domain claims. Its identity is metadata; it is never a numeric runtime pointer.
An address-only view has a checked offset into an envelope and nullable object
extent/type/alignment/lifetime. Four-byte generated placeholders do not become
object extents. In particular, the known setting constructor's accesses beyond
four bytes and the menu pointer's non-null lifetime obligations remain visible.

Preserve original relative offsets only inside a single admitted allocation.
Keep stronger independently established compiler alignment constraints; record
unknown object alignment rather than infer it merely from an old address. COFF
alignment and later linker/map alignment must agree. Preserve exact logical
lengths and exclude raw alignment padding. Raw-backed zero bytes and loader
virtual zeros have equal initial values but different provenance; keep both in
the receipt. Initially emit raw-backed and virtual-zero extents as separate
fragments, each with its own anchor. Separate COFF contributions do not prove
ordering, adjacency or one allocation, even when they originated in one PE
section. Cross-contribution base-plus-offset relationships stay blocked unless
a later explicit, independently reviewed linker/layout contract proves them.

Holes are not silently zero-filled providers. The ledger must reserve imports,
loader directories, original CRT state, cookie/complement, exit registries, TLS
index/template/directory/callbacks, dynamic TLS slots, source-owned literals or
globals, resources and relocation metadata. Unknown CRT state extents and
overlapping claims remain quarantine intervals, not guessed four-byte holes.
No chosen interval may cross a hole, code/mixed section or protection boundary.

Initially an arena can exist only as an envelope anchor obligation. If admitted
ordinary spans are separated by holes, emit separate physical fragments with
their own anchors; do not advertise one contiguous allocation or define the
envelope anchor as if base-plus-offset still worked. A reserved gap inside a
larger byte allocation would still allocate old special state and must not be
used as a duplicate owner. A source reference spanning such a split remains
unresolved until its relationship contract is proved.

Cross-fragment/arena subtraction, ordering, range comparisons, one-past pointers,
base-plus-offset arithmetic, integer casts, tagged/encoded pointers and runtime
computed addresses can depend on the original layout. Independent relocations
do not preserve those relationships. Record them as separate obligations and
block runtime adoption where unknown. Do not place fragments at original VAs to
hide this problem. Page protections and logical C++ bounds are separate facts.

## Field representation and canonical undefined names

Convert each admitted original four-byte HIGHLOW site exactly once to COFF
`IMAGE_REL_I386_DIR32`. Validate original site identity and raw/zero geometry,
the exact original word, relocation kind and complete target-domain evidence.
The emitted field contains only its checked addend; the old executable address
is removed. Every target is an explicit undefined symbol until a separate owner
contract selects a definition. A classified ordinary function entry still needs
its exact source-built physical owner; interior code/EH/helper targets need
their own span, frame, control-flow and ABI proofs. Never use the nearest entry,
a copied code address, a dummy function or a source spelling alone.

The code-pool owner confirmed its current contract:

```text
undefined = "_fnv_undefined_" + SHA256(compact_sorted_JSON({
    "original_base": "0x%08x", "role": role
}))
role = data | code | iat-cell | crt-contract
selected code = "_fnv_code_" + SHA256(compact_sorted_JSON({
    "recipe_id": ..., "object_sha256": ..., "symbol_index": ...
}))
```

Use that exact shared serializer and role vocabulary under pinned tool identity;
do not independently invent a similar hash. Original source-code fields keep
their authentic original symbol base, raw signed/unsigned addend bits and final
target separately. The quaternion's existing undefined data bases remain
distinct; no automatic arena-anchor rebasing is currently authorized.

A data-only HIGHLOW word does not reveal an original COFF symbol base. For such
a field, propose the exact observed target address as an **address-view demand**,
use the exact proven shared role (`data`, `code`, `iat-cell` or `crt-contract`)
at that address and addend zero, and record
`base_basis=exact_highlow_target`, `source_symbol_base=null`. This does not claim
an original symbol existed there. A classified IAT cell retains `iat-cell` and
indirection; classified CRT state retains `crt-contract`. Neither may flatten
to generic data/code. Unknown or conflicting roles quarantine the demand, even
when its address matches a known demand with another role. Special-domain
demands remain unresolved and are not definitions in an ordinary arena.

Later a reviewed interior symbol can define an ordinary-data demand at a
physical fragment offset. Bridging an exact-target demand to an existing
source-base-plus-addend demand requires an explicit view/relationship and
migration record: prove the same original final address, exact compatible role,
selected physical owner/offset, bounds and all required address relationships.
Keep both input identities and each field's original addend bits in that record.
Select one output expression per field and verify its final address algebra;
do not automatically collapse names, conflate roles or add a source addend again
to an already-final exact-target address. Source fields remain unchanged until
that separately reviewed migration is authorized.

New envelope/fragment anchors need a separate versioned namespace derived from
owned-image hash, original section identity, admitted interval and partition
policy hash. They must not redefine an existing `_fnv_undefined_` base merely
because it falls inside the envelope. The simplest first writer leaves all
target demands undefined and exports only the exact admitted fragment anchors.
It may describe a potential interior view in metadata without defining it.

Only known relocation sites are rewritten. Nonrelocated numeric words remain
unchanged, including address-shaped values. HIGHLOW is an opaque loader address
representation, not proof of C++ field type. RVAs, DIR32NB, REL32, SECREL,
resource grammars, relative tables and serialized offsets require separate
format contracts. No directory replay, integer scan or image-wide rebase fills
the gaps. A field crossing raw/virtual-zero, interval or domain boundaries,
overlapping another field or using an unsupported relocation fails closed.
Zero-backed HIGHLOW fields remain blocked unless independently explained; the
saved v4 sites are all raw-backed, not evidence that future zero sites are valid.

## Source owners and fresh runtime domains

Equal literal bytes are not shared identity. A source-emitted literal and an
original arena copy may represent the same original address, distinct pooled
copies, or an unresolved alternative. Require a per-original-identity decision:
retain the exact source literal and reserve its arena interval, or retain the
arena identity and separately redirect/suppress the source definition. Do not
silently emit both active owners or merge distinct originals. Preserve all
physical source candidates and the binding plan's literal-pooling tolerances.
Same-byte proof alone cannot settle address comparisons or writable aliases.

Fresh CRT owns cookie/locks/heaps/locale/stdio, constructor and termination
machinery, and atexit/onexit state. Fresh import infrastructure owns each IAT
cell and its indirection, not copied DLL addresses. Normal CRT/loader owns TLS
directory/index/markers/callbacks; static module offsets and the separate Havok
dynamic slot remain separate contracts. The successful one-getter component
used authored synthetic TLS initialization; it adopted no original template.
None of these cells can be supplied by an ordinary data arena.

Original C++ initializer/atexit tables are not ordinary inert constants merely
because stored in `.rdata` or `.data`. Recover each registration, source-built
initializer/helper target, ordering and paired teardown through fresh CRT
mechanisms. Retaining an old table does not authorize executing it; pre-constructor
image bytes do not prove a constructed object's lifetime. Do not copy completed
state and run its constructor again. Keep original registration arrays reserved
until every selected entry and ordering mechanism is reviewed. Source callbacks,
vtables and RTTI likewise need complete source function/helper/ABI obligations.

## One bounded implementation to assign next

Propose new `tools/rebuild/unresolved_data_arenas.py`,
`tests/rebuild/test_unresolved_data_arenas.py`, a fixed metadata-only policy under
`runtime/data-pools/`, and a new implementation document. Assignment would approve
source/tests first; actual private emission requires another explicit gate.
Reuse the reviewed minimal DATA-only COFF machinery and independent reparse
pattern; do not change its frozen original fixture or install a dependency.

The serializer has two explicit phases:

1. **Prepare metadata.** Pin the full supplied owned on-disk image and compatible
   reference, current fingerprint specification, v4/detail, owner ledger/detail,
   binding-v2/detail, recipe/manifest/v3/selection, source providers, code-pool
   namespace/tool and exact domain policy. Validate saved relationships and input
   stability, optional index state and complete field joins. Produce a disjoint
   geometry/obligation ledger with no payload and no automatic winning owner.
2. **Project a fixed reviewed set.** Read only admitted owned NONEXEC spans.
   Emit standard i386 DATA-only COFF fragments for their raw/zero extents with
   observed protections/alignment, explicit anchor definitions and undefined
   symbolic DIR32 targets. Preserve each exact known field and addend, all other
   admitted bytes, and the complete exclusion/quarantine ledger. Do not emit an
   archive or link it automatically. Partial projection must be labelled partial;
   unresolved sites never disappear from coverage counts.

The private report records `ARENA_ENVELOPE`, `ADMITTED_FRAGMENT`,
`RESERVED_DOMAIN`, `ADDRESS_VIEW_DEMAND`, `HIGHLOW_TO_DIR32`,
`SOURCE_OWNER_ALTERNATIVE`, `RELATIONSHIP_BLOCKER` and `REJECTED_INTERVAL` records.
Each field carries original site/target/domain, source-word hash or private value,
base basis, undefined identity, representation, addend bits, input/output physical
section/symbol/relocation indices and disposition. Object bounds/type/lifetime
stay nullable, approvals false and semantic-fixup approval zero.

An independent strict reader must reparse output without trusting serializer
maps: prove DATA-only sections, no executable/TLS/CRT/import infrastructure,
exact section geometry/flags, initialized content except replaced fields, actual
zero semantics, symbol/aux/section index bijections, complete DIR32 coverage,
undefined target identity/addend and absence of old target words at rewritten
sites. Old address-shaped numbers outside fields are expected unchanged. Full
input and implementation hashes are checked again before exclusive publication;
temporary failures and immutable receipts are preserved. Reject input/output
alias, symlink/hardlink collision, overwrite, stale policy, late drift and missing
proof. Do not publish a successful payload receipt for a failed projection.

Meaningful negative tests must cover executable/mixed ranges; raw padding and
wrong logical/zero extent; protection/alignment drift; reserved-domain overlap
and same-family competing claims; duplicated/straddling/unsupported HIGHLOW;
unknown or ambiguous code/EH/helper target; wrong source base/double addend;
missing/extra output relocation; wrong role or namespace hash; duplicate source
literal identity; misrepresented contiguous anchor across a hole; cross-domain
arithmetic left unblocked; assumed raw/virtual-zero contribution adjacency;
same-address different-role identity conflation or ambiguity; automatic
exact-target/source-base bridging or double addition; copied TLS/IAT/CRT/initializer state; nonrelocated
numeric preservation; unsupported RVA/table representation; forged index maps;
stale image/detail/tool/source evidence and output/input collision.

Reuse [DATA-FIXTURE.md](DATA-FIXTURE.md)'s already reviewed source-authored proof
of interior addends, function-symbol relocation, real virtual zeros, writable
storage and moved consumer layout. The real scalar and TLS components add narrow
literal/source-view evidence. No new arbitrary native demo is needed. These
proofs support mechanics only; later arena link/runtime testing needs a separately
closed component and independent artifact review, never a full-game claim.

## Privacy and acceptance

Owned-image payloads, projected objects, field words and complete address ledgers
remain private under ignored `build/rebuild/` or an explicitly supplied private
directory. Tracked code/policy/tests contain generic serializers, metadata/hash
contracts and original synthetic inputs only: no game bytes, disassembly, raw
template, private absolute paths, compiler copies or generated game binaries.
The image must be explicitly supplied by its owner; no downloading, archive
search, installed-game mutation, process capture or original-code copying occurs.

The next acceptance is independent review of that bounded serializer/schema and
negative tests. A later fixed private emission may demonstrate relocatable,
unresolved storage geometry. It does not approve ordinary data wholesale,
select every view, resolve special runtime domains, authorize semantic fixups or
establish initialized game objects. This planning task emitted no game data,
invoked no compiler/linker and executed no native program.
