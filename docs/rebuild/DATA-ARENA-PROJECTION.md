# Unresolved data arena planner and private serializer

November 3, 2026. This implements the source/synthetic phase of
[UNRESOLVED-DATA-ARENA-PROPOSAL.md](UNRESOLVED-DATA-ARENA-PROPOSAL.md).
No actual ledger observation or original data projection has run. There is no
compiler, linker, DLL loading or native execution path. Existing fixtures,
original source, recipe, comparator and receipts remain unchanged.

`tools/rebuild/data_arena_projection.py` provides a read-only adapter, pure
metadata planner and separately gated DATA-only COFF serializer. The tracked
policy `runtime/data-arenas/unresolved-original-v1.json` selects no fragments and
disables projection. Source/schema review precedes any actual observation;
actual emission needs a later reviewed nonempty selection and root authority.

## Observation and provenance

`adapt_saved(paths, policy, owned_sha256, root, review)` accepts explicit exact
paths for the owner ledger/detail, v4/detail, binding-v2/detail, recipes,
manifest, retained-v3, selection, imports, reference, fingerprint specification
and owned on-disk image. It discovers no image or archive. The policy pins saved
input and implementation identities. An independent observation review must
bind canonical policy hash, actual tool hash, explicit owned-image full hash,
reviewer and root authorization. No source attestation upgrades runtime flags.

Before/after checks rehash every supplied input, exact manifest-listed original
source/object, retained comparator tool and ready producer compiler. The adapter
reads only owned/reference PE geometry and non-executable identities, plus the
unchanged bounded fingerprint probes on the reference. It requires exact saved
nonexec hashes, header/geometry agreement and observed fingerprint agreement.
It does not recompile or rerun the full function comparison. Historical hashes
remain observed provenance rather than cryptographic execution proof.

The adapter streams the pinned owner gzip detail with line/count/uncompressed
limits. Every event is counted and sequence-hashed. Arena/domain/field events
retain their full original record and ordinal; all other events remain unchanged
obligations. Excluded TLS geometry, external domains, source literal alternatives,
code-target/helper/lifetime obligations and original missing fields survive.
Every original v4 field is joined in sequence to its owner record and checked
against the saved complete sequence digest. No missing row is replaced by an
overlay. Optional function-index absence is checked before and after.

The normalized schema contains disjoint `.rdata`, `.data` and `CONST` envelopes,
raw/virtual-zero domain partitions, all ordinary-source HIGHLOW fields, separate
external-field quarantines, unchanged obligations and original event provenance.
`observe_saved(...)` publishes this evidence and candidate plan together only
after stability checks. The private receipt preserves protected input identities;
no raw data payload is emitted. Actual adapter conformance and resource usage
remain unmeasured until separately authorized observation.

## Planner contract

`build_plan(evidence, policy)` checks logical/raw/padding/zero geometry, disjoint
complete domain coverage, flags and alignment. Only nonexec readable ordinary
domains can be admitted; source-owned, special-state and conflicting domains
remain excluded. Fragment alignment is reduced as required by its original
start offset, rather than claiming every subdivision retains page alignment.
Unsupported PE flags and executable/mixed storage reject.

Raw-backed and virtual-zero extents are separate fragments with separate anchors.
No ordering, adjacency, whole-allocation or cross-fragment base-plus-offset
relationship is implied. Typed extent/type stay null. The planner supports no
identity bridges or adjacency approval. Original cross-domain, RVA, lifetime and
unknown-state obligations remain unresolved, never suppressed by projection.

Every HIGHLOW site has width/kind/bounds/domain/overlap checks. An exact-target
demand has zero addend and null source-symbol base. Exact `data`, `code`,
`iat-cell` and `crt-contract` roles use the code-pool's shared undefined serializer;
same address with different roles remains different identity. Special-domain
conflicts, TLS, unknown helpers, ambiguous ownership and unsupported pointer
representations quarantine rather than guess. Known IAT and CRT roles are never
flattened. No source-base-plus-addend migration or double addition is supported.

The current adapter conservatively quarantines a special target with overlapping
domain evidence, even if one claim is an IAT or CRT cell. Ordinary code targets
require exactly one saved source-code candidate. It does not infer code/EH frame
or callable ABI closure from that candidate. A source literal interval stays
excluded; equal content selects neither identity nor an arena replacement.

Anchors derive from image/arena/fragment and stable planning-policy identity.
Later selection/enabling fields are excluded from that identity so there is no
circular requirement to select an ID that itself includes the selection list.
Changes to geometry/provenance/ownership policy still invalidate the plan.

## Private projection gate and output

`selected_plan` requires an enabled policy, exact plan/policy review hashes,
independent reviewer, root authorization and identical nonempty fragment list.
All selected fragments must be admitted, bounded and free of quarantined fields.
It creates no typed view definitions. The shipped policy fails this gate before
any original fragment is read. Changing its selection is a new reviewed phase.

`project_owned(observation_path, policy_path, review_path, out)` binds the exact
observation and all its protected inputs, reparses the explicitly pinned owned
PE and reads only selected raw nonexec spans. `project` is the lower-level
synthetic/serializer API with an explicit reader callback. Real use must enter
through `project_owned`; a synthetic callback is not owned-image evidence.

Each independent fragment becomes one standard i386 COFF object: `.data` with
the original read/write protection or a true raw-pointer-zero `.bss`, explicit
COFF alignment, one external anchor, undefined symbolic targets and understood
`@feat.00=1`. No directives, code, TLS/index/IAT/CRT infrastructure, aliases,
typed four-byte globals or source-literal duplicate owners are emitted.
Every admitted HIGHLOW becomes one DIR32 to an exact undefined demand with zero
addend. The original word must equal the pinned target before replacement;
other bytes, including address-shaped numeric words, remain untouched.

A separate strict COFF reader checks geometry/flags, symbol definitions and
auxiliary absence, exact relocation coverage/target/addend, real zero semantics
and preserved non-field bytes. It does not trust serializer index maps. All
objects stage privately; only after every reparse and protected-input recheck
are exclusive outputs published. Failure removes only the just-created outputs,
never inputs or older receipts. Final reports retain source/target field records,
fragment identities, all protected hashes, quarantine counts and partial status.

Unresolved obligations and missing code fields are preserved in a partial
projection's plan. Their existence forbids runtime adoption, not honest storage
format inspection. This source release contains no link/runtime approval or
automatic native verification. Broader relocation forms, C++ tables/resources,
fresh CRT/TLS/import providers, address-relationship proofs and actual view/
lifetime selections remain separate unimplemented contracts.

## Synthetic validation and next gate

Nineteen tests pass using invented metadata, original fake saved receipts and
synthetic DATA-only COFF. They cover raw/zero geometry and separate allocations;
flags/alignment/padding; domain gaps/overlap/reserved/source-owner exclusion;
exact-role identity and ambiguity; field overlap/bounds/kind/zero straddles;
unsupported bridges/adjacency/RVAs; stale/missing provenance/index/approvals;
numeric preservation and real BSS; independent COFF mutation rejection;
exclusive publication and late drift; disabled real policy; saved-adapter full
event/field preservation, bad counts/joins and wrong PE geometry.

```text
python -m unittest discover -s tests/rebuild -p test_data_arena_projection.py
```

The next gate is independent source/schema review of these four owned files.
Only afterward may root authorize an exact read-only observation. A production
fragment selection and private projection remain unapproved. The existing
[DATA fixture](DATA-FIXTURE.md) supplies the reviewed native mechanism evidence;
no arbitrary new native demonstration is proposed. Public files contain no game
payload, disassembly or private absolute path. Actual ledgers/objects and owned
inputs remain private, with all runtime/provider/link/fixup flags false or zero.
