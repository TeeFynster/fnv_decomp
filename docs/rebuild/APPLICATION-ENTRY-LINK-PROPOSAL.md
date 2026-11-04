# Real application entry: unresolved CODE retention before executable linkage

The next application milestone should retain the actual selected application
entry in a private unresolved CODE archive. It should not substitute another
fixture for that entry or attempt an executable before its providers are closed.
The current writer rejects the root for two precise policy reasons. Neither is
a size limit or evidence that the source body failed comparison. This read-only
proposal authorizes no writer change, emission, compile, link or game launch.

## Exact root and serialization blockers

Selected original identity `0x0086a850` is recipe `0576-dd603b7071c482c6`,
`src/fallout/misc/main.cpp`, physical symbol index 1215,
`?FUN_0086a850@@YGHIIII@Z`. It occupies all 4,532 bytes of section 199 at
offset zero. The section is executable `.text`, COMDAT `no_duplicates`, with
one ordinary section auxiliary. Its 442 actual fields comprise 152 DIR32 and
290 REL32 references. There are 280 physical target symbols: 432 occurrences
refer to undefined symbols and ten to definitions elsewhere in this object.
Those ten definitions are not an authorization to retain their whole sections;
their omitted CODE identities must remain explicitly undefined in a root-only
member.

The exact all-size row is `serialization_candidate=false`,
`writer_candidate_eligible=false`, with these complete blocker codes:

| Current blocker | Actual evidence | Required next contract |
|---|---|---|
| `SAFESEH_REQUIRES_CLOSURE` | Recipe section 9 is `.sxdata`. The separate physical-root audit finds 18 handler indices, all outside root section 199, and no root relocation targeting those indices. | A reviewed root-reachability/exclusion certificate for this exact selection, preserving dropped-handler dispositions. Do not delete SafeSEH metadata globally. The [root-closure proposal](ROOT-CODE-CLOSURE-PROPOSAL.md) owns generic weak/aux/SafeSEH policy. |
| `CANONICAL_NAMESPACE_COLLISION` | Two distinct undefined physical symbols, indices 289 and 1392, both resolve to selected original CODE identity `0x0043d4d0`. The writer rejects duplicate resulting names. Its evidence contains all 281 rename entries, not 281 independent collisions. | Preserve both source records and field provenance while representing one exact destination. Review duplicate-undefined alias support separately, preserving two distinct serialized physical indices and a symbol-index bijection with no relocation retargeting; never suppress the diagnostic or select one typed spelling as a provider. |

The two aliases are `?Int@GlobalObject2_0040c150@@QAEPAHXZ` and
`?Int@Setting86@@QAEPAHXZ`. All their observed fields have zero addends and
agree on the same selected original entry. This is not a same-name/different-VA
contradiction. It also does not prove the two source receiver types compatible
for application execution. The proposed adapter must retain duplicate undefined records with one canonical
destination, two distinct serialized physical indices and an explicit symbol-index
bijection. Coalescing the records or retargeting relocations is excluded. Its
serializer, independent reader and native archive/linker conformance require
explicit tests and approval before actual artifact use. No such change is made
here.

The row reports zero same-parent EH pieces, zero false same-parent pieces,
zero original missing relocation fields and no associative children. The body
occupies its whole section and has no retained local-label/extra-entry issue.
The physical-root audit also finds no weak/common records or unknown auxiliaries
in this recipe, and no direct weak target. These findings distinguish this root
from the current recipe-wide SafeSEH restriction. They do not establish
exception behavior of callees or prove every possible indirect dependency absent.

The recipe has 76 EH-piece observations for other parents, including one false
piece, and zero textual local EH notes. None can be borrowed as this root's
frame contract. Global retained verification still preserves all 95 textual
notes, strict-local-EH false and the absent optional function index. The separate
EH graph proposal should address actual EH-bearing parents, rather than attach
an unrelated main-recipe cleanup graph to this root.

## Exact direct dependency join

All 442 inventory binding-row references were joined to their exact one-based
runtime-binding detail ordinals and canonical record hashes. Every row reports
`EXACT_OWN_SOURCE_RESOLUTION`, `OWN_RECIPE_BINDING` and addend zero. The known
280-name set is **279 distinct original destinations** because of the pair above.
These are direct fields of the root, not transitive graph completeness.

| Existing planner class | Fields | Physical target symbols | Distinct original targets | Remaining obligation |
|---|---:|---:|---:|---|
| Selected CODE entry | 296 | 200 | 199 | Exact selected owners exist; CODE serialization, callable ABI and each owner's dependencies remain separate. |
| Original image data needing owner | 111 | 52 | 52 | No storage provider is selected. Preserve exact bases, indirection and lifetime obligations. |
| IAT pointer cell | 30 | 25 | 25 | Supply reviewed ordinary import-pointer cells, not function addresses. |
| Explicit normal-CRT candidate | 1 | 1 | 1 | Cookie check `0x00ec408c`, final field offset 4522; no automatic runtime adoption. |
| Unselected executable target, unclassified | 4 | 2 | 2 | `0x00ecc071` at offset 768 and `0x00406d50` at offsets 893, 964 and 1134 remain unresolved. |
| Compiler literal with full equality evidence / code interior / TLS / EH helper / special relocation | 0 | 0 | 0 | No direct root field has one of these classes. Their absence here says nothing about callees. |

Only nine of the 199 direct selected CODE destinations are current serialization
candidates; 190 are quarantined by the existing all-size policy. This is a join
to those 199 saved rows, not a second graph expansion. Their overlapping blocker
sets include 182 SafeSEH restrictions, 100 weak/common and 100 auxiliary
restrictions, 51 directive restrictions and 32 actual same-parent EH/association
restrictions. At least one direct destination also has an original missing-field
blocker. Unresolved archive retention can honestly proceed before these are
solved; an executable cannot treat them as supplied code.

The 52 direct data views have no selected canonical owner. Their saved domain
evidence is 47 ordinary-unclassified targets, four source-projection candidates
and one fresh-normal-CRT-state target. The latter is `___security_cookie` at
original `0x011c16bc`, used at field offset 10. It belongs to fresh normal CRT
cookie/complement state, not copied old PE storage. The four source projections
are not approved literal payload owners; no direct target passes the planner's
full read-only/nonpointer equality class. Source definitions, fake receiver
types, equal contents and writable arena geometry do not establish ownership.

The 25 IAT destinations join the actual PE imports as 15 USER32, seven KERNEL32,
two SHELL32 and one GDI32 named imports. There are no ordinal imports in this
direct set. It includes window registration/creation, message dispatch,
`LoadIconA`, mutex/system APIs, `CommandLineToArgvW` and `ShellExecuteA`.
All 30 import detail rows for this root are exact verified-function IAT uses;
the ledger's source-signature/calling-convention approval remains false. SDK
library names can be proposals only. The previous alias fixture's direct SDK
calls did not prove alias-only import-member extraction.

Source calls give leads, not contracts, for the two unselected executable
destinations: one compares a command-line wide-string option; the other appends
to local path buffers through the source's variadic `int` declarations. Do not
infer a CRT API or choose a library provider from those uses or addresses. A
bounded provider-identity/signature investigation is needed if these are ever
resolved. The direct explicit CRT class is not a complete CRT inventory:
security state is separately classified as data, and callee EH/RTTI/allocation,
floating-point and exit-registry obligations remain outside this direct join.
There is no direct root TLS field; the separate TLS owner remains authoritative.

## Smallest real source-link milestone

1. Obtain separate reviews for the exact root SafeSEH exclusion and the
   duplicate-undefined adapter above, coordinated with the root-closure owner.
   The adapter must preserve both serialized physical indices, a symbol-index
   bijection and every relocation target without retargeting.
   Keep all other quarantine rules and the baseline 88 missing-field identities.
   Require positives and negatives for reachable handlers, ambiguous aliases,
   duplicate definitions, differing destinations/addends and incomplete fields.
2. Assess this same 4,532-byte root again and serialize its entire source-built
   section plus ordinary auxiliary into a new private unresolved member.
   Preserve physical source records and all 442 field offsets, kinds, payloads
   and addends; publish complete dispositions for omitted definitions and
   SafeSEH records. Do not retain unrelated main.cpp bodies, old data or `.CRT`
   tables. Keep the 279 direct destination obligations explicit.
3. Independently parse and recover that member, reconcile exact symbol/auxiliary
   mappings and all fields, repeat the unchanged comparison through an explicit
   canonical-name view, and perform separately authorized native archive
   conformance before actual artifact use. The outcome is “real application
   entry retained with unresolved
   references,” not an executable or startup claim.
4. Use the resulting direct obligation ledger to select the next real provider
   work. Import-pointer contracts, the two unselected executable identities,
   fresh CRT state, actual data lifetimes and EH-bearing direct code owners are
   concrete work items. Do not invent stubs to force an entry link.

## Eventual normal WinMain bridge remains a separate gate

The actual source declaration at main.cpp line 6515 is an `int __stdcall`
function of four `unsigned int` values; the selected decorated name agrees.
Its first parameter is used as the window-class instance, the `LoadIconA`
instance and a `CreateWindowExA`/global-constructor argument (lines 6684 onward).
The other three parameters are not referenced in this source body. This is
source evidence for a WinMain-shaped x86 call boundary, not a validated SDK
signature. A future original bridge can accept normal `HINSTANCE`, previous
instance, command tail and show-state arguments, convert them only under an
explicit reviewed 32-bit ABI contract, and call the canonical entry. Do not
change the retained body signature or manufacture a PE entry stub.

The source has ordinary early `return 0` paths and an explicit cleanup/return
path near line 6950. It also calls subsystem helpers and
`ShellExecuteA`; a normal-return source path is not a guarantee that every
application path returns. No application call was made here. Normal GUI CRT
bootstrap, cookie-before-protected-initializer and shared exit-registration
behavior were demonstrated only by the separately reviewed original
[CRT fixture](CRT-BOOTSTRAP-CONTRACT.md), including mixed compiler consumers.
Those observations do not approve the game's generated initializer set,
exception/runtime contracts or global storage.

Resource identity is another real gate: the body requests icon resource `0x65`
from its instance and uses original window-class/title data plus an original
window-procedure identity. A newly linked executable does not inherit the old
resources automatically. Resource reconstruction, initializer
retention and ordering, callback signatures, command-line semantics and shutdown
lifetimes need explicit application contracts. None should be hidden inside the
CODE serializer or justified by the packaged PE's protected startup stub.

## Evidence identities and limits

All named inputs below were existing exact reports or the one selected source
and object; no old workspace search, transitive full-graph scan, decode,
compilation, link or launch occurred. The root's 442 field-record hashes were
reconciled, but original PE bytes and the full comparator were not rerun.

| Evidence | SHA-256 |
|---|---|
| `build/rebuild/objects.json` | `bc62a5fb2553431b1e0547d11f366e52efb73096ea8ceb206c556ae5740a53eb` |
| Selected main object | `a6c310961921f70eea2c70b9c18dba3d85ac19bffdfe3164922e9c3462ab425b` |
| Selected main source | `89d09f8b4ba6d9758fca0ac3ebd32e18c9cc82c68a739c044457ed5c005ae3c5` |
| `runtime-code-inventory-native-v1.json` / `.jsonl.gz` | `02a77cce3f43c1786cd027e72ffb17e76ffe6766c2823872254015b6e40549f6` / `91cdc91af6530e6e80e2104cdfeb9bd6928e17fa0f75bcf066734985248f1031` |
| `function-selection-v2.json` | `48ae62cdc5b1754b9c4af674ef4716d53afb554882e174a93acf860eaf1c6cb1` |
| `runtime-bind-plan-native-v2.json` / `.jsonl.gz` | `275714631903758efbf5a4f82e2428c6f51838f53b90d0c56d2e5dec5da1d804` / `4dfc437064b16c1bb933008aebf7def8d279a903eef9cca24d0fedcc12d7d826` |
| `runtime-data-owners-native-v1.json` / `.jsonl.gz` | `fac1496a2675e9a6b697d604c8d5b35a2e4b8bb6194e2ec823e5a37d1092f2e8` / `c54abfd434ac715a16d31711fa8afb498d4b41420bec3bfcc25347d0eab9bd08` |
| `import-plan-native-v3.json` / `.jsonl.gz` | `e39b8db63ef73aea57b5dd4963ff29310524644ca36e137cd8b5461a3c90a23f` / `4731ab38156dc5c4d65cd9c0ba595c3a06ba3775ab6e9c226e74e388e07ffc41` |
| `root-code-closure-proposal-evidence-v1.json` | `e33878057645e899e7506d00f1505c3748f373de4880bfb4c55f150059685eef` |

Report basenames in this table are under private `build/rebuild`. Physical
object provenance is the retained run `20261103T030230Z-7cfc935c`, exact recipe
0576, not a newly compiled or extracted image. All serialization, link,
runtime/provider/materialization approvals remain false. This proposal awaits
independent source/metadata review through the coordinator.
