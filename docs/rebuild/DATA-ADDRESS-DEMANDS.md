# Exact original address demands, provider selection deferred

November 3, 2026. Propose a versioned private address-demand contract so a
relocatable DATA object can describe an exact dependency before its runtime
provider, type or lifetime is approved. This does not change the frozen 446-byte
projection, existing four-role canonical namespace, CODE producers or policies.
No wider DATA materialization, object mutation, compiler, link or execution is
authorized here. This task adds a proposal and private metadata evidence only.

The distinction is concrete: **known site/target/addend is enough to describe an
unresolved relocation; it is not enough to select a provider.** Provider and ABI
obligations must not be reported as unknown bytes or discarded to obtain a link.
The resulting object may honestly remain unlinked with all runtime flags false.

## Exact existing large-fragment evidence

Use the already observed whole raw fragment
`374b2034599e26fb66895c38ed20cdebd079783c94fde6c9ba470cacb54e88b4`,
`0x01183000..0x011c16bc`, 255,676 bytes, read/write, nonexec, alignment 4,096.
Its exact owner-ledger domain ordinal is 91,188. Its current field sequence
contains 13,869 raw HIGHLOW sites: 12,482 current symbolic demands and 1,387
classifier quarantines. No arbitrary slice, zero-fill extension, source-owned
interval, cookie cell or protection change is proposed.

All 1,387 quarantines have an exact original field, four-byte HIGHLOW, exact
original target address and proposed exact-target addend zero. Their original
COFF base/addend are unknown and remain null; zero here is the new relocation
expression, not a claim that an original symbol had zero addend. Every old word
would be verified against its target before replacement. These are not missing
site, unreadable payload, unsupported loader relocation or lost-addend failures.

| Current quarantine family | Fields | Exact target identities | Remaining uncertainty |
|---|---:|---:|---|
| Nonexec targets with source-literal owner alternatives | 1,359 | 22 | Which physical source/arena allocation will own each original identity |
| Executable targets without selected source owner | 28 | Seven | Source/helper/fresh-CRT provider and callable/identity contract |

The 28 executable demands group as follows:

| Exact original identity | DATA fields | Candidate evidence, not provider approval |
|---|---:|---|
| `0x005dc0f0`, `0x005dc1b0`, `0x005dc290`, `0x00dfddb0` | One each | Executable range; no selected owner or listed recipe entry |
| `0x00ec9907` | Six | Saved source references include differing close-related spellings |
| `0x00ecb3a8` | Twelve | Four saved source bindings spell `_fread`; focused CRT owner investigation is separate |
| `0x00ecb562` | Six | Saved source references include tell-related spellings |

The latter names cannot automatically become `crt-contract` identities. A link
to a function with a familiar name is not an ABI, FILE-layout, lock or state
contract. Exact address knowledge nevertheless permits an undefined dependency.
Original executable bytes never enter the DATA output or a fallback target.

## Original raw backing versus alternative source literal owners

A bounded join of the 1,359 fields found **22 unique target intervals and 112
physical `SOURCE_PROJECTION_CANDIDATE` claims**. Ten target intervals have two
claims, six have three, three have four, and one each has five, six and 51.
All intersecting storage evidence for these targets is in that candidate family;
no fresh CRT/TLS/IAT/resource claim was found in this bounded join. Every interval
has authoritative original nonexec RAW geometry inside `.rdata` and its already
hash-bound owned/reference section identity. Multiple source candidates do not
make the original bytes or address unknowable.

That is authoritative **storage identity evidence**, not an automatically chosen
runtime owner. The current partition intentionally reserves source-projection
candidates; do not change that label by priority. A later explicit policy may
choose original arena backing for one of these exact whole intervals instead
of a compiler-literal provider, while preserving all original-address views.
No nearest-symbol object extent or arbitrary cut follows. All 112 candidates,
their physical recipe/object/symbol identities and full-range equality evidence
remain attached to the 22 original intervals.

The proposed first large DATA template does not emit those target intervals at
all: it leaves their demands undefined. Therefore it need not choose among the
112 alternative source owners to describe its own exact address fields. If a
future provider chooses original backing, it must separately suppress/redirect
any source-literal definition for that same original identity; equal bytes cannot
justify duplicate active owners or merge distinct original addresses.

The already selected scalar's two eight-byte original literal ranges are
`0x0101de30..0x0101de38` and `0x01051680..0x01051688`. None of these 1,359 target
fields intersects either range. Those selected 16 source-owned bytes remain
excluded, as do the known TLS, CRT and import domains. Any later overlap would
be an explicit conflict, never absorbed into the 22-interval policy.

## Proposed address-demand schema and namespace

Use a new namespace, **not** an unannounced reinterpretation of
`_fnv_undefined_` or its existing `data/code/iat-cell/crt-contract` roles:

```text
symbol = "_fnv_address_v1_" + SHA256(compact_sorted_ASCII_JSON(identity))
identity = {
  "version": 1,
  "address_space": <hash-bound owned/reference/recipe coordinate-space ID>,
  "original_target": "0x........",
  "representation": "absolute32",
  "role": "original-nonexec-storage-address-v1"
          | "original-executable-address-v1"
}
```

The coordinate-space ID must derive from the exact owned full-image hash,
compatible reference hash, nonexec identity digest and authoritative recipe
hash, not an agent ID or current load base. Canonical JSON/hashing and role
enumeration need a reviewed shared implementation before use. These are original
coordinate identities; no old process address becomes the emitted field value.

Each demand record contains original site and target; original record/ordinal/
hash; exact source raw extent and HIGHLOW width/kind; actual target section/domain
evidence; new identity; zero addend bits; nullable original source symbol base;
all source/provider alternatives; owner-selection and ABI/lifetime blockers;
and separate false runtime/provider/link/fixup approval flags. Multiple fields
may share a demand name, while every physical field identity remains distinct.

Admission to these two roles requires positive evidence, not unknown-to-data
fallback. The first role requires a mapped, nonexec ordinary storage identity
with explicit backing and no selected source-owner/fresh-state conflict. The
second requires a mapped executable target and an explicit source-required
obligation. It does **not** claim that the address is a function entry, callable
alias, whole verified CODE owner or fresh CRT function. Unknown/mixed domains,
unmapped targets, resources/RVAs, TLS/IAT/CRT state conflicts and inconsistent
coordinate-space facts remain mechanically quarantined. No opaque demand is
silently converted to the existing `iat-cell` or `crt-contract` role.

For the 1,359 source-literal alternatives, a policy must explicitly distinguish
unselected alternative claims from an active selected source owner. It may
admit an exact nonexec address demand without selecting either alternative.
It cannot use that permission to define the target allocation. The independent
ledger's full overlap evidence remains present and runtime ownership unresolved.

## Whole-fragment template: every address field symbolic

The concrete next source extension should describe the **entire existing
255,676-byte raw fragment**, with all 13,869 HIGHLOW fields accounted. A uniform
new address-demand namespace for every positively classified target is preferable
to quietly treating the 1,387 old quarantines as four-role canonical references.
Keep the old field classifications/provider candidates as evidence, not as an
implicit migration. The new contract needs its own root assignment and review.

For every admitted site: check the original word equals the pinned exact target,
replace all four bytes with zero, and emit one DIR32 to its undefined address
demand. Even if no provider exists yet, this is a valid symbolic dependency.
No original numeric pointer remains as a fallback. Nonrelocated numeric bytes
remain unchanged; address-shaped integers are never scanned. No field may cross
the raw/domain boundary, overlap another or acquire an unsupported relocation.
The complete old raw and all output non-field bytes must compare equal.

If any source field's identity/word/representation or target domain is genuinely
unknown, stop or publish a metadata-only blocked plan. Do not manufacture a
successful whole-fragment payload with an old address left in place, remove a
field, cut around it, weaken data flags or add zero placeholders. Unresolved
provider/ABI/lifetime alone is recorded separately and need not block an honest
undefined demand. The object remains partial dependency assembly, not runnable.

## Fulfilling a demand later without duplicating storage

A later fulfillment certificate must join the exact original demand to one
canonical physical provider: source-built CODE section/value/span, complete
DATA arena/source interval and offset, or separately approved fresh CRT owner.
It records the full provider recipe/object/library/member hashes, primary symbol
indices and section/offset, domain compatibility, view bounds and required
relationships. Executable interior/EH/helper addresses need their actual
control-flow/frame contract; a nearest function or wrapper is not a substitute.

The demand can be defined by a same-section external alias at the proved new
provider offset, sharing its one existing allocation. Its COFF value is an
offset, never the original VA. A fresh CRT alias needs an independently reviewed
linker/provider mechanism and ABI/state contract; this proposal does not choose
one or add `/alternatename` directives. If no valid provider exists, keep the
symbol undefined and let a normal link remain unresolved.

For cross-component compatibility, preserve old four-role and physical CODE
identities as separate names. An explicit bridge may define both names at the
same selected physical location; it must not allocate a second object, rename
distinct original addresses together or equate arbitrary roles. The fulfillment
ledger enforces one active owner per original storage identity and records any
suppressed/redirected source-literal or generated-global definition.

The addend algebra is mandatory. If an existing source field is `B + a = T`,
and selected provider location for `B` is `P + o`, that field retains its original
addend and resolves to `P + o + a`. The exact-target address demand for `T` has
addend zero and must be defined at `P + (o + a)`. Aliasing it directly to the base
name at `P + o` is wrong when `a` is nonzero; adding `a` again is also wrong.
The bridge must prove the original final address and physical interior offset,
compatible domain, supported bounds and required address relationships. Unknown
one-past, tagged or cross-allocation relationships remain blocked. No CODE field
or existing alias is rewritten by this planning task.

## Next implementation and independent gates

Propose one new metadata/schema module and synthetic tests for the versioned
identity, distinct semantic/provider states and exact fulfillment algebra,
followed by a separately assigned DATA serializer extension. First consume the
already saved whole-fragment metadata; do not repeat the 446-byte pilot or create
another arbitrary native fixture. Actual larger payload emission still needs
an explicit reviewed policy and root go.

Tests should distinguish known address/unknown owner from unknown address;
preserve all 13,869 identities and field addends; reject selected-source/special
domain overlap, resource/TLS/IAT/CRT role flattening, coordinate-space drift,
same-address incompatible roles, old numeric pointer fallback, missing/extra
relocations and unknown-to-data promotion. Fulfillment tests must catch duplicate
owners, wrong physical section/offset, source literal duplication, executable
interior guesses, direct-base aliasing with nonzero addend and double addition.
Independent strict reparse must recover every undefined demand and zero field.

Private evidence `build/rebuild/data-address-demands-v1/evidence.json` has SHA256
`2e7bfee400512522db0677eaae54e61c7a60f36b27f4c38d7bc39b5def673d61`.
It retains all 1,387 original field records, the 112 literal owner claims with
ledger ordinals, the four arena geometry records and exact selected-scalar
binding evidence. Only exact known metadata inputs were read; the 1 GB
observation was not loaded or regenerated. No original data bytes are included.
The full original missing/EH/relationship obligations remain untouched. This
proposal seeks source-contract review, not materialization or runtime adoption.
