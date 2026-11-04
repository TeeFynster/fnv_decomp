# Compatible undefined CODE reference groups: certificate-only v1

`tools/rebuild/canonical_reference_groups.py` supplies a separate read-only
candidate-certificate adapter. It does not change the existing CODE writer,
parser, source, original object or payload. It exports a proposed namespace and
explicit physical-to-planned-serialized index bijection as metadata; there is no
COFF emission, rename, serializer invocation, native command or executable path.
The existing writer still rejects duplicate destination names. This adapter
does not make that rejection disappear or authorize a consumer to bypass it.

The first actual scope is the selected application entry `0x0086a850`, recipe
`0576-dd603b7071c482c6`, section 199, symbol index 1215, full 4,532-byte extent.
Only source indices 289 and 1392 may share the canonical undefined CODE name for
selected original destination `0x0043d4d0`. Their eight zero-addend REL32 fields
must remain distinct and target the corresponding preserved symbol records.
These are two source type spellings, not a new approved callable interface.
See [the application-entry proposal](APPLICATION-ENTRY-LINK-PROPOSAL.md).

## Input and certificate contracts

`certify(data, request)` is the pure synthetic-test/core interface. A version-one
`compatible-undefined-reference-request` contains the object hash, complete
input hash ledger, exact root, separate complete root-closure observation and
its canonical digest, retained primary indices, full namespace plan, one group,
full field-proof records and their original detail ordinals/canonical hashes.
Hand-written core requests are untrusted candidate evidence; they are not a
replacement for the real pinned collector or independent root review.

Each namespace row records `physical_index`, `serialized_index` and `name`.
The planned serialized indices are recomputed over the separately certified
sorted retained primary set using the unchanged serializer's ordering, counting
all auxiliary slots. Both group members must have distinct physical and
serialized indices. The certificate also preserves every auxiliary mapping.
There is no record coalescing or relocation retargeting. A later serializer must
demonstrate that every emitted relocation references the mapped version of its
same original symbol index, including both aliases.

The separate root certificate must have policy
`root-code-closure-observation-v2`, status `observed`, no blockers, exactly the
same single root/recipe and identical retained primary indices. Its runtime
section set is `[199]`; the complete serialized section set is `[1,199]`,
including the actual `.drectve` section. The adapter independently derives the
required section-defined, field-target and compiler-metadata primary records
and every auxiliary slot from the native object; omission of directive,
metadata or section-auxiliary records is rejected. Its
complete observation is digested; independently computed exclusion lists cannot
be unioned. The real collector recomputes root drop closure with that
separately reviewed producer; the pure test/core API alone grants no approval.
It requires `graph_observation_complete` and `root_closure_candidate` true,
`full_serialization_eligible` and namespace-collision resolution false. [Root closure](ROOT-CODE-CLOSURE-PROPOSAL.md) remains an independently
reviewed prerequisite, including SafeSEH and omitted-definition dispositions.

V1 accepts only ordinary EXTERNAL undefined, zero-value, auxiliary-free group
members with identical supported COFF type status. Definitions, common/weak
records, IAT spellings, data roles, code interiors and mixed types fail closed.
There is no one-definition-plus-undefined equivalence rule in this version.
The selected physical provider identity determines the canonical CODE name; all
group rows must identify its same original entry with zero interior offset.
Every duplicate namespace index must be explicitly in this group, and no other
duplicate or pre-existing canonical spelling is accepted.

The core recomputes the complete physical group relocation set in the selected
root, matching each actual index/offset/kind against exactly one proof. It
requires zero source addend, REL32 width four, no overlapping fields, native
symbol-name/status/type equality, exact own-recipe source resolution and one
unambiguous selected-code owner. The recorded original field address and signed
displacement must establish the same base/target. Missing, repeated or hidden
fields, changed proof hashes, mixed roles/bases and different destinations are
rejected. This is field provenance; it is not an SDK/C++ ABI or lifetime proof.

`observe_main(paths, report_path, report_sha256, details_path, details_sha256)` is the real read-only input
collector, implemented for later separately authorized observation. It has no
automatic entry point and has **not been run**. A raw self-hashed closure object
is insufficient: it requires the complete observer summary and two bare gzip
certificates, their linked file/canonical hashes, exact protected producer and
dependency pins, and stable input states. The producer is pinned to independently accepted
root-observer source SHA-256
`4bfdb5001380a3d7e5db7517033285d49ab211be68e2fcba15964f0ad5b03c53`;
its exact helper/parser/proof-tool dependency dictionary must also agree. It verifies the fixed input
hashes before reading the exact main object, joins authoritative recipe and
retained/selection records, and streams the two existing compressed inventories.
Only the root and selected provider inventory records plus the 442 root binding
identities are retained. All 442 binding identities must reconcile before the
eight group fields are selected. The namespace proposal is recovered from the
old writer's complete collision diagnostic and scoped to the independent root
certificate's retained symbols. It reconstructs the main root-observer contract
from all 442 pinned field rows, retained proof and exact source/object/producer
provenance, then recomputes the complete root certificate with the pinned
observer and requires canonical equality. The adapter records its own source
hash before reading inputs; all inputs, streams, producers/dependencies and
that original implementation hash are rechecked before return. The current
`build/function_index.json` path must be absent at both entry and exit; a
historical receipt's absent-index observation is insufficient.

Output kind is `compatible-undefined-reference-certificate-candidate`. It records
input/request/root-closure/field hashes, exact field tuples, namespace rows,
primary and auxiliary bijections and producer identities. Runtime, provider,
ABI, link and emission approval flags are false. A caller may save this metadata
to a fresh private file only after source/schema review and root observation go;
it must retain the exact certificate file hash for consumers. The certificate
does not contain source/library/game payload bytes or disassembly.

## Exact proposed main observation pins

These existing reports are under private `build/rebuild`; the object/source
identities are unchanged from the application-entry audit. The collector's
required input-key set is exact. The separately produced root certificate gets
its own caller-supplied file hash and its complete canonical observation digest.

| Input | SHA-256 |
|---|---|
| Recipe `build/units.json` | `62f2c8da5f0daa912abdf4576328706711c6561eef7f01c93a89cb71ad46fb6c` |
| Retained manifest | `bc62a5fb2553431b1e0547d11f366e52efb73096ea8ceb206c556ae5740a53eb` |
| Main object | `a6c310961921f70eea2c70b9c18dba3d85ac19bffdfe3164922e9c3462ab425b` |
| Main source | `89d09f8b4ba6d9758fca0ac3ebd32e18c9cc82c68a739c044457ed5c005ae3c5` |
| Retained v3 proof | `04d44b73e81982f846bfe8d81806db72ea669586b579ff22007dfd6f7d831297` |
| Function selection v2 | `48ae62cdc5b1754b9c4af674ef4716d53afb554882e174a93acf860eaf1c6cb1` |
| Runtime binding v2 / detail | `275714631903758efbf5a4f82e2428c6f51838f53b90d0c56d2e5dec5da1d804` / `4dfc437064b16c1bb933008aebf7def8d279a903eef9cca24d0fedcc12d7d826` |
| All-size inventory v1 / detail | `02a77cce3f43c1786cd027e72ffb17e76ffe6766c2823872254015b6e40549f6` / `91cdc91af6530e6e80e2104cdfeb9bd6928e17fa0f75bcf066734985248f1031` |
| Unchanged `coff_code_archive.py` | `76244d2d4dca4c1f8aa72224be1ef5c92f68976b5cda7d31b5cfe23d3cc29e64` |
| Unchanged `runtime_code_pool.py` | `729f189e2893c7f3a3e3cd97df7d7381ac115169e1d75cf664e6bbc1c587b277` |

## Validation and next gate

Thirteen offline tests use an original synthetic i386 COFF object with two actual
reference records, two REL32 fields, an ordinary section auxiliary, actual
directive section and compiler metadata. They
cover the positive unchanged-index certificate, wrong role/base/provider,
ambiguous ownership, definitions/common/weak/type mismatches, hidden indices,
missing bijections, coalescing/retargeting, incomplete/repeated/kind/addend/proof
errors, original displacement mismatch, stale producer/closure/field identities
and missing real-input sets. Additional negatives reject dropped directive,
metadata, section-auxiliary and auxiliary-slot records even after a fabricated
closure is rehashed, plus adapter/dependency changes during observation.
A forged self-hashed root graph/provenance body is also rejected against the
complete recomputed observation. No game input or native tool is used by the tests.

```text
python -m unittest discover -s tests/rebuild -p test_canonical_reference_groups.py
```

The next step is independent source/schema review of this adapter and the
separate root-certificate producer, then a root-authorized read-only main
observation. Only after both actual certificates pass review may a separately
assigned namespace adapter serialize the real entry. Its native conformance
plan must verify two distinct undefined primary records with the same name,
their exact physical-to-serialized mappings, all eight unchanged reference
targets/addends and archive views through the pinned old Microsoft tools.
Duplicate definitions and wrong-provider negatives must fail before an artifact
is used. A later bounded link-conformance check needs separate authorization;
no native tool or executable link is part of the present certificate task.
The 95 EH notes, optional-index absence, baseline 88 missing identities and
unselected/provider/closure states remain unchanged.

Source-review revisions are saved and thirteen tests pass. The adapter is refrozen
to the root observer's accepted source identity and exact final observation
schema for renewed independent review. This is source acceptance of a separate
producer, not approval of an as-yet unrun observation. No real observation or
native operation has occurred in this task.

## Preserved blocked root-v1 outcome

The root-observer owner reports that private `root-code-closure-native-v1.json`
(SHA-256 `d3bf0d5148f594384c400485cd25e5377b6bb16408f57a835cfca9d0df90feaa`)
and its detail stream
(`93a5ddce2b4fc8649377ae9be7ad780d9f4a658fb722b0507535762282efa9b1`)
contain a **blocked** actual main certificate, canonical hash
`afbfedab3dec5b26520dbab3b17b3ee32ce34c0e7b1b94e3201d98f11f0124e8`.
Its graph/closure gates are false. The reported blockers are 23 unsupported
storage-class-6 LABEL records outside the root and a live same-name IAT alias:
retained physical index 680 versus omitted index 2830,
`__imp__GetForegroundWindow@0`. That IAT relation is outside this adapter's
all-undefined CODE-only pair and cannot be silently admitted here.

The reported retained set is 285 primaries/287 physical slots across sections
1 and 199. These extents do not override the failed graph gates. Independent
root-outcome review is separate; this task has not rerun that observation or
invoked the real adapter collector. The collector deliberately rejects this
blocked v1 certificate; the later ordinary-v2 result below is separate. Source acceptance of this adapter cannot make an
actual positive main certificate or entry archive ready. Root policy fixes,
new reviewed observations and independent outcome acceptance are required
before that result could support a positive adapter observation.

## Ordinary-v2 compatibility delta: source only

The root observer's ordinary-v2 producer adds a pinned import report and an
explicit full-unit omission-proof contract. The adapter now accepts only policy
`root-code-closure-observation-v2` and producer
`4bfdb5001380a3d7e5db7517033285d49ab211be68e2fcba15964f0ad5b03c53`.
Input `imports` must hash to
`e39b8db63ef73aea57b5dd4963ff29310524644ca36e137cd8b5461a3c90a23f`.
Its source/object/reference proof joins are checked, and import ID 175 is
selected from the actual report, not guessed from a source spelling.

For complete root recomputation the collector additionally reconstructs
`unit_proofs_complete`, the retained receipt's `unit_verified_functions`,
`omission_field_proofs`, and `iat_import_observation`. Omission proofs are the
full unit's field rows targeting storage-class-6 LABELs or exact source name
`__imp__GetForegroundWindow@0`. The provenance's
`omission_binding_row_references` retains **all** unit field/missing-row
identities in the observer's function insertion order, including ordinary rows
that are not omission proofs. `imports_sha256` and the unchanged exact dependency
manifest are bound into the recomputed contract/provenance. The adapter does
not implement or broaden the observer's LABEL/IAT rules itself. Import ID 175
is actual USER32 `GetActiveWindow`; its misleading source spelling is preserved
as evidence, not adopted as an export identity.

The root observer's independently reconciled ordinary-v2 summary is
`root-code-closure-native-v2.json`, SHA-256
`2273d54cdf913e58c4eb9317bf4f289a71a7e49639ed16a6cf2a317bc37d17b3`;
its detail SHA-256 is
`7dda28aafa2e6ae2791827978b319b8844c0d29d70bc1ddf48a29bbdf12973e6`.
The main certificate is
`9bbbdfe0b590b4919ae773094c9d466d16ff41f38333803d67a69ff1364a3037`.
Independent outcome review receipt
`root-code-closure-native-v2-independent-review.json`, SHA-256
`dd939a576f89af41c54dd3ca99eb8b37257efe2a3f6cc535211dc495809f007e`,
accepted the scoped root closure. Full retained sections remain `[1,199]`,
with 285 primary records and 287 slots. Namespace resolution and full
serialization eligibility remain false. In particular, retained CODE indices
289 and 1392 still require this separate adapter contract.

The earlier accepted eleven-test adapter source/test/document bytes are
preserved in private `canonical-reference-reviewed-v1-snapshot`. This compatibility
delta and its thirteen-test suite await independent consumer source acceptance.
No actual adapter observation, emission or native operation has run. The
producer's accepted outcome does not by itself authorize this changed consumer.
