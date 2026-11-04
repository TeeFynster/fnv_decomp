# Fixed raw storage and canonical address aliases

November 3, 2026. This separate source/synthetic extension implements the accepted
[two-fragment selection](DATA-ARENA-PILOT-SELECTION.md). The older arena planner,
empty policy, source files, observations and historical negative selection stay
unchanged. No actual data object has been emitted by this extension. No compiler,
linker, native inspection or game execution ran.

The supported scope is exactly the complete 219-byte and 227-byte admitted raw
`.rdata` fragments, 446 bytes total, with 16 exact address aliases resolving 20
application-entry fields. Both ranges are read-only, non-executable and wholly
raw-backed. There are no contained or crossing HIGHLOW fields. This is useful
actual entry storage without inventing a relocation or a typed object extent.

`runtime/data-arenas/entry-raw-aliases-v1.json` pins the accepted selection SHA256
`c35bdda25e5f797da6e0b088ca1b78a8b461779c7f088d0bac951fba674a3893`, full owned
and reference identities, whole-fragment geometry/payload hashes and all 16
canonical identities/offsets. It also pins the reused serializer, namespace and
strict-reader dependencies. The default action is verify-only; private emission
requires a separate exact review and root authorization. Runtime/provider/link/
materialization approvals remain false and semantic fixup approval remains zero.

## Source interface and physical meaning

`verify_selection(selection, policy)` checks the fixed fragment IDs, original
domains, flags, alignment, raw backing, zero HIGHLOW/conflict evidence and all
20 field-to-alias relationships. Every source field must retain the actual app
entry identity, DIR32, undefined external source symbol, exact original base
equal to final target, and zero addend. Every alias must have an actual field
demand; duplicate, missing, retyped, shifted or extra aliases fail.

Each alias uses the existing shared `namespace.unresolved(original_base, data)`
identity. The emitted symbol is EXTERNAL, section 1, value equal to the proved
fragment-relative offset, type zero, no auxiliary record. It shares one physical
allocation with its anchor. This is an ordinary same-section COFF definition,
not a SECREL relocation, a module offset, an absolute/process-VA symbol, a new
allocation or a compiler type claim. Later DIR32 references would resolve
through the normal linker; this task neither links nor rewrites entry fields.

`alias_object(fragment, aliases, payload)` reuses the frozen minimal DATA writer
for the unchanged raw contribution and understood `@feat.00=1`. It appends only
canonical alias symbol records/strings and adjusts the symbol count. Section
payload/flags/geometry remain unchanged; no relocations or directives are added.
Independent `strict_object` reparsing checks exact section/size/protection,
complete raw payload, zero relocations, exact anchor/feature/alias symbols,
same-section values and absence of hidden symbols, types or auxiliaries.

The physical section is `.data` with read-only flags `0x40100040` and alignment
one; its name does not make it writable. It preserves the original fragment's
read-only/nonexec protection. No `.tls`, `.CRT`, IAT, initializer table, code,
resource or original source-literal owner is introduced. Bounds/type/lifetime
for the address views stay null or false. No adjacency relationship across the
excluded interval between the fragments is claimed.

## Owned input gate and private publication

`load_verified(selection_path, policy_path, owned, reference, root)` requires
the exact accepted selection and full image hashes. It rehashes the selection's
saved input metadata, current entry source and namespace tool, plus all pinned
implementation dependencies. Hashing is chunked, including the large saved
metadata input. It does not load that file wholesale or repeat its observation.

The input PE readers verify full recorded base/image/section/raw-file geometry,
exact raw extent, flags and both selected payload hashes/equality. They enumerate
the owned relocation metadata and reject any HIGHLOW overlapping either range,
including a field starting before the fragment. No executable section payload
is read except as part of opaque whole-file hashing. Only the exact 446 raw data
bytes are retained transiently for writing; no arbitrary range API is offered
through the fixed production gate.

`project(selection_path, policy_path, owned, reference, root, review_path, out)`
first requires an independent review of kind `entry-raw-alias-projection-review`,
phase `private-446B-projection`, with reviewer, approval, root authorization and
exact tool/policy/selection hashes. Implementation/source approval alone does
not meet this later emission gate. It never compiles, links, loads or executes.

Both objects stage privately and pass the strict independent reparse before
exclusive publication. Existing outputs, input/output aliases, stale evidence,
helper drift and late file changes reject. Only newly created outputs are
removed after publication failure. A successful private receipt binds every
input, object/payload hash, physical alias definition and exact 446/16/20/zero
counts. No original target address is substituted as a runtime fallback.

All original bytes/objects/complete metadata remain in ignored private output.
Tracked policy/tests/code contain hashes, address identities and invented
payloads only. No source-owned literal duplication, unknown typed extent,
original initialization, CRT/TLS/import provider, ABI or runtime readiness is
approved. The large fragment's 1,387 quarantines remain a separate namespace/
provider investigation; they are not relaxed here.

## Validation and pending work

Thirteen synthetic tests pass. They cover the fixed 16-alias/20-field bijection;
wrong geometry/protection/role/typed extent; conflicts, virtual-zero and HIGHLOW
evidence; changed source base/addend/kind; same-section symbols and exact invented
payload preservation; duplicate/process-VA aliases; independent output mutation
rejection; absent private authorization; exclusive publication and drift;
unexpected/crossing owned HIGHLOWs; stale image and pinned helper replacement.

```text
python -m unittest discover -s tests/rebuild -p test_data_arena_alias_projection.py
```

Source/schema review precedes any actual private 446-byte projection. Root must
then separately authorize that exact operation. Microsoft COFF conformance,
future linkage, entry namespace integration and every runtime obligation remain
separate gates. The original DATA fixture supplies existing native mechanics
evidence; this component adds no arbitrary runtime demonstration.
