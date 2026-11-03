# Parent-owned EH graphs in the unresolved CODE pool

Read-only design, November 3, 2026. This proposes a separately reviewed EH
retention/serialization adapter. It emits nothing and changes no source, recipe,
comparison core, object, metadata, existing serializer or approval flag. No
compiler, linker, archive emission or execution occurred. Existing original EH
fixture and real type-overlay results supply the mechanics/evidence basis; no
new arbitrary runtime demo is proposed.

The product remains **unresolved source-built CODE**, not a runnable component.
Ordinary/EH byte and state evidence, serialization closure, source-role identity,
frame convention, lifetime and provider adoption are distinct obligations. A
correct index map does not make a function safe to call.

## Coordination and selected scope

The startup owner inspected the actual application entry `0x0086a850`, recipe
`0576-dd603b7071c482c6`, section 199/value zero/4,532 bytes. Its exact native root
has no same-parent EH piece and no associative child. Its larger object has other
EH material and 18 SafeSEH registrations, all outside that selected root. The
root-closure owner's SafeSEH exclusion and duplicate-undefined/canonical-identity
policy remain the appropriate work for that root. This proposal does not label
it EH-bearing from whole-object counts, prove exception independence or duplicate
that generic policy analysis.

The first EH adapter should instead target the already audited **IOTask
constructor `0x00440540`**, recipe `0069-3b6fc41592bb705f`. Its complete ordinary
body and both local EH pieces match in the exact retained object. It has the
same small compiler-owned cleanup/handler/FuncInfo form exercised by the reviewed
original fixture, and one whole SafeSEH record. Its remaining CODE/DATA/CRT
references stay explicit unresolved obligations.

The failed `SubObjA` cleanup in constructor `0x0043fd40`, recipe 802, is the main
negative case. A second, smaller recipe-802 EH graph at `0x0044a040` was inspected
as a structural stress case, but its object's alternate-name directive and mixed
SafeSEH table keep it blocked under existing policy. Nothing here changes the
planned initial CODE archive's selected subset or predicts population unlocks.

## Positive parent: exact source/native evidence

Source `src/bsmain/bstaskmanager.h` defines `IOTask::IOTask` by constructing
`BSTask<__int64>` then calling `SetIOTaskPriority`. Its adjacent type header has
layout assertions; the retained recipe uses exact SP1 `/MT /Od /Oy- /GS /EHsc /Gy`.
The body is complete readable source, not an invented handler. If the derived
body call fails after base construction, the compiler emits the base cleanup.
There is one unwind state and no source catch block.

| Native owner | Exact role and evidence |
|---|---|
| Section 3, `.text`, 101 bytes | Whole no-duplicates COMDAT, root symbol index 8/value zero. V3 has exact same-object ordinary MATCH. |
| Section 4, `.text$x`, 35 bytes | Associative child of 3; static cleanup at +0, static handler at +8. V3 pieces `[0x00eec240,0x00eec248)` and `[0x00eec248,0x00eec263)` both match. |
| Section 6, `.xdata$x`, 44 bytes | Associative child of 3; unwind map at +0 and FuncInfo at +8. One transition 0 -> -1, no try map, EH flags 1. The existing pilot separately checked all non-relocation metadata content and its two pointer fields. |
| Section 16, `.sxdata`, four bytes | Non-associative index-bearing record; its word names original primary symbol index 19, the local handler. No ordinary relocation expresses this edge. |
| Section 1, `.drectve` | Exact reviewed LIBCMT/OLDNAMES default sequence, with no alternate-name/entry/export/include operation. |

The graph has eleven runtime relocations: five in the parent, four in EH code and
two in state metadata. It needs seven unresolved external identities after the
permitted DATA-boundary conversion: base constructor, priority setter, base
destructor; CRT cookie, cookie checker and frame handler; and the IOTask vtable
view. Every field/addend/role still needs the CODE pool's complete binding and
original-missing-field evidence. A v3 body MATCH alone does not attest that lane.

The native vtable is external definition index 16 in section 5 at +4, bound to
original `0x01016c10`. It is **not** the parent's EH metadata. Existing CODE-pool
policy can turn a referenced omitted definition without auxiliaries into an
explicit canonical undefined obligation only after exact original base/role proof.
That is the proposed boundary here: preserve the DIR32 addend and original vptr
view identity, define no placeholder storage, and retain no guessed vtable/RTTI.
The underlying table's preceding metadata slot and full DATA extent remain a
separate ownership problem; this undefined view is not a recovered data object.

The omitted original vtable/RTTI graph reaches weak deleting-destructor records.
A hash-bound generic omission/implicit-root subcertificate must decode their
physical fallback edges and prove them outside the fully expanded retained/implicit
closure, rather than silently delete them. Its retained EH/SafeSEH blockers remain
present until the separate composition step below; it need not falsely report
ordinary-root serialization success. The initial global-weak policy still blocks until that
certificate policy is implemented and reviewed. The EH adapter does not choose a
weak fallback, suppress a destructor or adopt a vtable provider.

Thus this is a **locally verified EH-parent pilot**, not an already eligible
emission. It awaits complete field/missing-field evidence, the generic root
certificate, the explicit undefined DATA boundary and the new EH adapter review.
Its current runtime/frame/lifetime/provider approvals remain false. It is not an
assumed third positive of the main/allocator ordinary-root policy.

## Small original fixture proves machinery, not game closure

The reviewed fixture extractor retained a 100-byte source constructor, a 35-byte
associative cleanup/handler, 44-byte associative state metadata, understood
directives and one SafeSEH record. It rebuilt physical section/symbol indices,
auxiliaries and the handler index, reparsed output independently and was reviewed
before linking/execution through a real CRT. The original fixture passed normal
construction/destruction, body-throw rollback and base-throw behavior at two
layouts, with 1,024 rounds of three paths per layout.

Reuse that already accepted record-rebuilding and negative-test basis. It does
not authorize applying the fixture-only extractor directly to game objects:
its hardcoded source/provider/shape guards deliberately reject that use. The
new adapter should consume an explicit evidence contract and the CODE pool's
existing bijective writer, leaving both current policies unchanged by default.

The selected CRT frame-coordinate research is conditional on the exact reviewed
CRT/form and ordinary x86 nonvolatile-register preservation. It is not proof of
the original game's dispatcher identity or all transitively called helper bodies.
Neither serializer acceptance nor the fixture result promotes those contracts.

## Component and record retention contract

A future observer produces a versioned parent-EH retention plan for a **root set**
in one immutable input object. It consumes the generic omission/implicit-root subcertificate owned separately by
symbol_binding, including its unchanged retained EH/SafeSEH blockers. It does not
require an ordinary-root serialization-positive certificate for a root that that
policy intentionally blocks, nor independently redefine live roots, weak semantics,
directive roots or canonical provider selection.

Required evidence includes exact recipe/source/object/producers, full v3 identity,
selected root's native entry/span, complete original binding and missing-field
rows, every local EH piece verdict, complete metadata/state comparisons and the
actual auxiliary/association/registry graph. Input hashes and optional-index
presence must be stable. Caller review claims are operational approval evidence,
not cryptographic execution or compiler-causality proof.

The plan must retain complete sections and records:

1. Keep the exact whole parent CODE section and supported associative runtime
   descendants. Traverse associations in both directions. An unknown child,
   shared section, unrelated function entry or escaping parent blocks selection.
2. Keep all parent-local cleanup/handler symbols with their real storage classes,
   type fields and offsets, plus FuncInfo/unwind-map symbols and every metadata
   relocation. These are private parent-frame material, never independent CODE
   roots, public archive exports or callable aliases.
3. Model every state and transition, including the terminal state, all action
   symbols/offsets, original action destinations and own/global/inferred binding
   distinctions. First scope admits only the exact reviewed EH3 form with no
   catch, try, IP-state or exception-specification subtables. Other forms remain
   explicit blockers; names and nearest addresses cannot reconstruct them.
4. Keep the complete positive pilot's `.sxdata` section and translate its actual
   handler primary-symbol index. Preserve compiler features such as actual
   `@feat.00=1`, `@comp.id`, alignment/section flags, COMDAT policies and exact
   understood directives. No SafeSEH bit clearing or safety-diagnostic disabling.
5. Retain every relocation's physical target record. An external unresolved
   CODE/DATA/CRT/IAT/TLS obligation is distinct from a selected provider. An omitted
   definition becomes undefined only under the already reviewed exact binding
   contract; never by zeroing its address or guessing storage.

No component may use a matching piece from another object to fill a failed local
piece. A folded/shared original tail needs exact physical ownership and compatible
parent evidence; equal bytes, section proximity and a global coverage row do not
supply that contract. Multiple roots must recompute their union closure before
classification; independently valid drop lists cannot simply be unioned.

## Noncircular certificate composition

The generic observer's overall result remains false for an EH root. Its useful
output is a **hash-bound omission/implicit-root subcertificate**, not an ordinary
serialization pass. It must enumerate the complete input metadata universe,
retained roots and proposed runtime-extension sections, decoded ordinary/auxiliary/
association/SafeSEH/directive edges, exact omissions and conversions, and every
blocker. Retained EH material is not omitted merely because its semantic adapter
is pending. Unknown metadata remains a blocker.

The root-policy owner identified two exact extension-obligation codes:
`RETAINED_PARENT_EH_OR_UNKNOWN_CHILD` and
`LIVE_SAFESEH_HANDLER_REQUIRES_ADAPTER`. Preserve their original blocker IDs,
physical evidence rows and false overall status. The first code deliberately
includes unknown children: its spelling alone is not evidence that a section is
supported EH, and it is not an automatic discharge allowlist.

A separately reviewed EH certificate may resolve only exact obligations whose
physical graph it has proved. Its composition key must include:

- Original object, source, authoritative recipe, v3 and all producer hashes;
  generic/EH policy and schema versions; the immutable generic observation hash.
- The exact selected physical root set **and fully proposed retained section
  set**, with symbols/auxiliary identities and edge-set digests. For the IOTask
  candidate this includes root section 3, EH children 4/6, whole registry section
  16 and directive section 1, plus explicitly proved target records/conversions.
- For each proposed discharge, the exact generic blocker ID and evidence-row
  hash/range: parent/child section and association edges, or SafeSEH section,
  record ordinal and handler primary-symbol index. IOTask's registry obligation
  names section 16, ordinal 0, handler index 19; it cannot authorize another
  handler, a neighboring section or a future larger root set.
- The matching EH proof nodes/edges, native/original spans and every same-object
  code/state/metadata verdict; exact required retention and complete index maps.
  Merely calling an unknown child `.text$x` cannot supply this evidence.

The composer must recompute the generic graph for that expanded retained set
before accepting its omission subcertificate. If adding EH children makes a weak
fallback, auxiliary, directive, registration, conversion conflict or other target
live, the earlier smaller-set omission proof is stale. Combining roots likewise
requires recomputation for their union. Cached certificates may be reused only
when the complete roots, retained-section set, edges and all input identities
remain identical; root function address equality alone is insufficient.

The new composed policy returns a new decision with the unchanged generic
observation hash, separate EH certificate hash, exact one-to-one discharge rows,
and every remaining blocker. It does not edit the original generic receipt,
turn its false result into true, remove reasons by category/string matching, or
add a blanket “EH adapter accepted” waiver. Every EH/SafeSEH obligation must be
proved and discharged exactly once; an unmatched, duplicated, ambiguous or extra
discharge fails. All non-EH blockers remain fatal to serialization. In particular,
unknown child/auxiliary semantics, missing fields, failed local pieces, live weak
records, unknown directives and canonical identity collisions cannot be excused
by this EH certificate. The normal unresolved CODE/DATA/CRT obligations still
remain recorded and do not become runtime providers.

Only a separately versioned composed result may make a bounded serializer plan
eligible after all serialization blockers are resolved. That result is still
not ABI/frame/lifetime/provider/link or game-runtime approval. The current main
and allocator ordinary-root certificates and their policies are unchanged.
IOTask is a separately reviewed extension scope and is not presumed eligible
until this exact composition exists and passes its own checks.

## Explicit section/symbol/auxiliary bijections

The serialization receipt must enumerate both directions, not just counts:

| Mapping | Required invariant |
|---|---|
| Input section -> output section | Every retained complete section has one output owner; every output owner has an input identity. Association parent numbers translate through this map. |
| Input primary-symbol physical index -> output primary index | One retained source record maps to one destination record and vice versa. Equal names never merge physical records; one source helper is never split into multiple targets to repair a mismatch. |
| Input auxiliary slot -> output auxiliary slot | Each retained primary keeps its supported auxiliary count/group. Translate only fields whose exact index semantics are decoded; keep all other supported metadata fields. Unknown index-bearing fields block. |
| Relocation field -> translated primary record | Same field offset, type, width, payload/addend bits and original role; new symbol index is exactly the mapped physical target. No relocation to an auxiliary slot. |
| SafeSEH source ordinal/index -> output ordinal/index | Resolve to the same local handler identity after section/value translation, not a code address or an ordinary parent symbol. |
| String-table reference -> output name bytes | Preserve supported symbol/section-name bytes except an independently approved canonical-name phase. Rebuild lengths/offsets; no name-based alias inference. |

For IOTask, the plan's supported runtime section set is 1/3/4/6/16. The vtable
symbol's definition-to-undefined conversion is a separate explicitly authorized
record transformation, not a new retained DATA section. All other sections,
primary records and auxiliary slots get dispositions from the full generic
certificate: retained, supported debug exclusion, proved omission, exact undefined
conversion or blocker. No record disappears from accounting.

Keep original code/state payloads and addends byte-for-byte. The only table
payload change in the first case is the numeric SafeSEH index translated through
the bijection. Rebuilt headers, relocation indices, string offsets and understood
auxiliary section indices must be recorded separately from immutable payloads.
If a table index changes, apply the same reviewed explicit auxiliary-checksum
policy as the fixture writer, with before/after fields in the receipt; do not keep
an unexplained stale checksum or rewrite code/data to match it.

Independently reparse the staged object with both the strict COFF reader and an
independent structural reader. Compare every kept symbol/auxiliary record, section
payload/characteristic, runtime edge, association and registry target against its
translated input identity. Run the unchanged ordinary/EH comparison on the output
under the explicit original-identity ledger, and separately compare all metadata
scalars and pointers; the original oracle does not compare every EH data scalar.
Publish only new exclusive outputs with receipt/output hashes and final input
rehashes. No approved archive index may export static frame helpers or unresolved
storage as definitions.

## Mixed SafeSEH tables and directive blockers stay separate

The root-closure proposal currently permits whole-table omission only when no
retained root/runtime child intersects its records. A retained handler instead
requires this EH adapter. The positive IOTask case keeps its **whole one-record
table**, so the first serializer extension need not invent a filtered table.

The bounded stress case `0x0044a040` is an 83-byte source-backed destructor in
`modelloader.cpp:20843-20861`. Its source calls `CleanupReceiver::FUN_0065f240` and
then performs compiler-owned base destruction. Native sections 1076/1077/1078
are 83/35/44 bytes; both EH pieces match. A bounded read-only check additionally
found zero non-relocation differences in its original 44-byte metadata at
`0x0114f848`, and both metadata pointers agree. This proves those local facts,
not the callees' runtime contracts.

Its handler index 5411 is ordinal 118 in shared section 15, which has **119
SafeSEH records, 119 distinct handler indices and 119 distinct associative roots**.
All records structurally resolve to static function symbols in associative EH
code. Every record was inspected in this one known object; no global scan was
performed. Retaining only this root while copying all registrations would create
references to omitted handlers; silently dropping the other records would evade
the current policy.

A later, independently reviewed projection policy could explicitly account for
every retained/omitted ordinal and its code owner, preserve the root-set union,
and translate only actual kept handler records. It must prove no retained or
implicit root needs any omitted registration. This is **not** part of the first
whole-table pilot or an existing permission to filter.

There is also an actual directive blocker: this object's `.drectve` starts with
an alternate-name operation before LIBCMT/OLDNAMES. Its source template spelling
is physical undefined record 5216; the fallback spelling has no COFF symbol
record. The current exact-two-default-library contract must reject it. Do not
strip it as unrelated text, normalize it into a library name or invent a missing
fallback record. A separate directive/implicit-root contract belongs to the
root-policy owner. These barriers remain visible even though the selected local
EH graph matches.

## Failed-piece negative: source repair is not serialization

The preserved full-v3 evidence has **128 false local EH pieces**, not merely 95
text diagnostics: 116 false pieces in the sixteen diagnostic-bearing units and
twelve in units without textual errors. A unit's empty `eh_errors` list is not
an eligibility test. Every retained local piece and its complete source/data
metadata must pass its own same-object checks, or be explicitly quarantined.
Global coverage of all listed tails does not waive that condition.

The actual type-view experiment preserved the 166-byte ordinary constructor,
all code/metadata payloads, four states and five local pieces, while two distinct
compiler-emitted destructor names improved local verdicts from
`true,false,false,false,true` to `true,false,true,true,true`. SubObjA remains
false, with the identical diagnostic. The experiment is compile-only and its
comparison bindings were never adopted as runtime aliases.

This negative demonstrates why a serializer must be bijective. The original
SubObjB helper record cannot be split or its two call relocations redirected to
different fabricated output records to force success. Legitimate distinct source
views create separate compiler records in a new source object; that new object
needs its own complete proof and selection policy. It cannot lend an unchecked
helper to the immutable retained original. Neither original nor overlay becomes
an EH serialization positive while the same-parent SubObjA piece remains false.

The first adapter must reject this parent before emission. It must also reject a
quarantined component hidden behind a successful ordinary MATCH, a matching global
tail from another unit, no textual warning, a source-hash-only assertion or a
manually patched metadata target. No runtime/source fix is performed here.

## First implementation contract and negative tests

The next assignment should add a **versioned EH plan/serializer adapter**, not
relax the default CODE-pool policy. Keep the fixture-only extractor and prior
policies unchanged. Before emission, the new observer consumes the hash-bound generic omission/
implicit-root subcertificate with retained EH/SafeSEH blockers still present, and
a separate reviewed EH certificate. The new composer discharges only exact proved
obligations for the expanded retained set and returns a complete parent-retention
plan or all remaining blockers; no generic overall-positive precondition is used.
Its first actual proposed roots are IOTask69 and the failed SubObjA parent, using
exact already-known manifests/objects. The 83-byte stress case can remain
assessment-only to demonstrate mixed-table/directive rejection.

The writer extension then serializes only a fully accepted composed whole-table plan,
using the existing COFF writer's explicit section/primary/auxiliary maps. No new
compile, full corpus scan or runtime demo is needed to validate the initial
mechanics. First reproduce the existing original fixture's extraction invariants
with authored structural fixtures; after independent source review, a separate
root authorization may permit bounded actual object/archive emission and
independent native archive inspection. Linking/execution remains another gate.

Required focused tests:

- Complete parent+cleanup+handler+FuncInfo/state map with a non-associative
  SafeSEH index; exact payload/flag/addend preservation and round-trip bijections.
- A symbol-index table pointing to an auxiliary slot, wrong handler, missing
  registry, unsupported feature value or an unmapped association; all reject.
- Missing or cyclic state transitions, absent metadata pointer, stale parent
  association, foreign-frame cleanup, extra function in a kept section or a
  co-owned/shared EH section without a contract; all reject.
- False local piece with no text error, ordinary MATCH with failed cleanup,
  metadata scalar/pointer mismatch and global coverage borrowed from another
  unit; all reject. Include the original SubObjA and overlay's remaining failure.
- Duplicate names in distinct physical records keep distinct indices; merged
  primary/auxiliary records, split one-helper records, reordered dangling indices
  or transformed relocation targets outside the exact plan reject.
- The approved vtable-to-undefined boundary preserves base/addend/kind, emits no
  storage or RTTI and leaves an unresolved DATA obligation. A guessed extent,
  zero-array substitute, reachable weak fallback or missing field proof rejects.
- Whole one-record SafeSEH retention passes structurally; mixed records needing
  projection, newly live records after root-set union and hidden directive roots
  remain blocked under the first policy. Preserve the 119-record/alternate-name
  stress case as an assessment negative.
- Exact allowed directive bytes/order remain; unknown `/ALTERNATENAME`, include,
  export/entry or unparsed auxiliary metadata rejects. No blanket cleanup of
  unrelated object safety metadata is permitted.
- A generic observation remains overall blocked while exposing valid omission
  evidence; only the exact reviewed EH/SafeSEH obligations may be discharged.
  Wrong blocker IDs, row hashes/ranges, section/handler indices, duplicate or
  omitted discharge rows, and an unknown child sharing the broad EH blocker code
  reject. No reason-category-only waiver or mutation of the generic receipt.
- Expanded EH retention or a root-set union that reaches a previously omitted
  weak/directive/auxiliary/registry dependency requires a fresh generic graph;
  reuse of a smaller-set subcertificate rejects. Missing fields, false local
  pieces and canonical collisions stay fatal after an otherwise valid EH proof.
- Stale source/object/proof/producer/index state, output collision, incomplete
  publication or altered staged output reject; prior files survive every failure.

Acceptance separates ordinary/EH/state/reference checks, serialization-plan
completeness, independently inspected COFF/archive validity and unresolved
obligation counts. `runtime_eligible`, `provider_selected`, ABI/lifetime approval,
link approval and game readiness stay false. No static cleanup is exported as an
ordinary provider. Only after a bounded accepted adapter should a separately
assigned metadata census measure broader eligibility; this plan claims no new
all-size unlock count.

## Exact evidence and limits

The plan read existing documents/reports and only the named retained units 69,
576 and 802. Candidate inspection inside those exact objects is not a new full
corpus scan. Application-entry scope was coordinated with the startup owner;
generic root/canonical policy remains with the root-closure owner. No old
workspace/archive enumeration occurred.

| Evidence | SHA-256 |
|---|---|
| Retained manifest | `bc62a5fb2553431b1e0547d11f366e52efb73096ea8ceb206c556ae5740a53eb` |
| Full retained v3 | `04d44b73e81982f846bfe8d81806db72ea669586b579ff22007dfd6f7d831297` |
| IOTask69 object | `4e7ad6d343e1abc45e1ef23eb96436174032d7cdd5a0c69b2f0748bd8b37607b` |
| Main576 object | `a6c310961921f70eea2c70b9c18dba3d85ac19bffdfe3164922e9c3462ab425b` |
| Recipe802 object | `678bb9bf0aad418bdd58cb1e252282bad07537b24037e3ae7f2ff97145b52cc0` |
| Original fixture preparation | `247f69a4e62eb5a7e3874caa7884e083a6e7fd35c9036c75338f649bd2180e02` |
| Original fixture extraction receipt | `e7a43f1b43cf456ae1ca93d4194b74b9263bc22c9f19848b6fa6e009a4a498fb` |
| Original fixture independent review | `5276c7f97acb53b7f7cc2a248d0a29062cef208b23b5c26a37d3332b684049b1` |
| Original fixture execution receipt | `3b1b5786bb98b35696229625356a393736b2711c483a08028496a6522d21efe3` |
| Actual type-overlay compile receipt | `e2c85032f5d06218faf0dd519860cfe0bd491b16713e4149b7eb77d735d3d76e` |
| Root-policy two-object evidence | `5413edffdcc4bb322511a6ff9c928e9d48222fd91349a08fd19fa009a7afe7b3` |

These private artifacts remain under ignored build output. This document contains
only identities, structural/state facts and future contracts, with no original
payloads, disassembly or personal input paths. It does not independently rerun the
prior fixture or claim a new full byte-matching baseline. The fresh 83-byte-root
metadata check was bounded and read-only; the first serializer's primary IOTask
metadata proof remains the previously recorded pilot evidence. Independent review
must precede any new adapter implementation or emission assignment.
