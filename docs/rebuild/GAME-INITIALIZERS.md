# Game initializer registration: bounded metadata audit

The normal source-authored CRT host establishes a fresh CRT, but it does not
discover reconstructed plain initializer functions by their names or original
addresses. Application initialization and termination registration remain a
separate, **unapproved** provider obligation. No complete original C/C++
initializer, pre-terminator or terminator table bounds or runtime order have
been established. No game initializer was executed or registered by this work.

## Exact observation

`tools/rebuild/game_initializers.py` is metadata only. Its pinned inputs are the
retained manifest `objects-20261103T030230Z-7cfc935c.json`, function selection v2,
runtime-data-owner v1, owned data-plan v4 and its compressed HIGHLOW detail,
the unchanged recipe and the already approved owned reference. The owner ledger
anchors the reference hash
`df1788907c6e26ef4df0b448ead526825336356b5606650165a1ce0825097eb7`.
Input identities, nine exact native objects and their source files were freshly
hashed before and after observation. No directory/archive search was performed.

For those nine named recipes, the tool reads native `.CRT$` section metadata,
DIR32 pointer relocations and their actual native function symbols. It preserves
each physical recipe/section/offset/symbol-index identity and joins bound targets
to the selected CODE owner. It then streams the existing data HIGHLOW ledger.
Every joined pointer site was independently read from the non-executable,
raw-backed owned reference and checked against its actual HIGHLOW relocation
metadata. Executable payloads were excluded. Pointer values are reported only
as address metadata; no bytes, disassembly, storage or provider is emitted.

| Recipe / generated source | Native XCU slots | Bound, selected physical owners | Native `_atexit` fields in those owners |
|---|---:|---:|---:|
| 1671 / aggregate initializers | 188 | 188 | 0 |
| 1677 / float-call initializers | 0 | 0 | 0 |
| 1678 / global-object initializers | 3,365 | 3,365 | 2,901 |
| 1679 / second global-object unit | 445 | 445 | 443 |
| 1680 / optimized global-object unit | 888 | 888 | 42 |
| 1681 / optimized Od variant | 888 | 0 | 0 |
| 1682 / optimized variant | 3,365 | 0 | 0 |
| 1683 / setting EH initializers | 71 | 71 | 71 |
| 1684 / setting float initializers | 1,308 | 1,308 | 1,308 |
| **Bounded total** | **10,518** | **6,265** | **4,765** |

Each of the 6,265 bound initializer targets has exactly one observed original
HIGHLOW pointer-site candidate in this data ledger. The 4,253 unbound native
slots remain separately recorded; they are not silently assigned to equivalent
names or selected variant functions. The full native arrays therefore cannot
be copied wholesale into a new runtime. This is a nine-recipe observation, not
an inventory of every translation unit's CRT contribution.

For example, source annotation `@fnv 0x00f35420` on `g_011c32f0` identifies
function `??__Eg_011c32f0@@YAXXZ`, not the object's data address. Its native
`.CRT$XCU` slot is recipe 1678, section 6425, offset 0, symbol index 566; the
selected CODE owner is section 156, offset 0, size 15. Its original pointer-site
candidate is `0x00fdf588`. This is a real function-pointer-field relationship,
not proof that the candidate belongs to a particular bounded CRT table.

The existing lifetime lead `g_011dee84` has initializer `0x00fa2380` at native
XCU offset 11828. The selected initializer's native `_atexit` REL32 field is
at function offset 21; its DIR32 function-pointer field at offset 16 names
selected cleanup `0x00fd8e10`. The audit labels pointer-field candidates
separately: relocation metadata alone does not prove a particular pointer is
the argument passed to a particular registration. The source/field lifetime
evidence and unresolved non-null object extent remain as recorded in
[RUNTIME-DATA-OWNERS.md](RUNTIME-DATA-OWNERS.md).

## Ordering and termination blocker

All recipe bindings were checked for the exact standard x86 CRT spellings
`___xc_a/z`, `___xi_a/z`, `___xp_a/z`, `___xt_a/z`, `__initterm` and
`__initterm_e`; none is present. This negative spelling check is limited
evidence: renamed or unbound identities remain possible. The PE data directories
do not supply a C/C++ CRT initializer-table directory. The fixture's normal CRT
boundary symbols describe its freshly linked tables and cannot bind the
original game's tables.

The original pointer-site candidates identify an address ordering of fields,
not the standard CRT traversal's start/end arguments or stage. Sorting those
addresses, initializer function addresses, source declarations or native object
slots cannot prove runtime invocation order. Neighboring nulls also cannot
establish boundaries without independent table identity. No guessed boundary,
run, null sentinel, pre-terminator order or terminator order is adopted.

The missing proof is the identity of all eight standard boundary objects and
their traversal/stage relationship. Existing original link-map/PDB metadata
would be one input; it is not required by default. A bounded comparison of
legitimate standard CRT functions and all their relocation/call-flow semantics
is the actively investigated equivalent route, described below. After that
proof, enumerate every slot, including nulls and unselected/runtime entries,
with original table index, callable type and exact source/native or normal-CRT
owner. This work does not inspect or modify packaging/protection startup,
execute the owned reference or derive bounds from that startup.

Termination requires its own classification. Existing 4,765 generated-initializer
registration fields agree with the independent CRT integration inventory; other
function-local and explicit registrations are outside this bound. A fresh shared
`atexit` registry must retain the order of successful registrations, including
later lazy initialization. Do not synthesize a destructor list by reversing
initializer names or pre-registering all cleanup functions. Original XP/XT
tables and dynamically registered callbacks are distinct obligations.

## Proposed source-to-normal-CRT provider, after proof

1. Build an explicit reviewed registration manifest from proven table/stage/index
   identities. Every non-null game slot must name its exact selected canonical
   source-built CODE symbol and no-argument callable contract; C initializers
   additionally require their integer status/failure contract. Every runtime-owned
   slot must have a reviewed normal-CRT replacement/phase contract. Unknowns block
   emission. Preserve object storage, ctor/EH closure and non-null lifetime gates.
2. Generate new source-authored registration glue referencing canonical CODE
   symbols through relocatable function pointers. Never call original numeric
   addresses. A single ordered dispatcher is appropriate only if the proven
   original stage is one application-only interval compatible with the new normal
   CRT stage. Otherwise preserve each reviewed interval and interleaving contract;
   do not flatten C/C++ stages or mix original runtime entries into fresh arrays.
3. Retain exactly those approved roots and suppress duplicate reconstructed XCU
   registration contributions through an independently reviewed projection plan.
   Do not register both a native generated array and a dispatcher for the same
   initializer. A generated-function definition alone is insufficient retention.
4. Bind initializer registration calls to the same reviewed fresh normal-CRT
   registry used by the host. Preserve each initializer body's registration
   behavior and later function-local registration. Original onexit pointer
   templates or runtime snapshots must never initialize this registry.
5. Prove linked table contents and actual call trace on original synthetic
   fixtures first, including C-initializer failure, duplicate-root rejection,
   ordering and normal termination. Actual game registration stays blocked until
   CODE/DATA/EH/provider/lifetime obligations independently close.

No registration provider source was generated because the boundary/stage proof
is missing. The existing normal-CRT bootstrap fixture remains separate evidence.

## Reproduction and review

Supply explicit input files with the pins in the tool and a new private output:

```text
python tools/rebuild/game_initializers.py --manifest <retained-manifest> --selection <selection-v2> --owners <runtime-data-owner-v1> --data-plan <owned-v4> --data-details <owned-v4.jsonl.gz> --recipes <units.json> --reference <owned-reference> --source-root <checkout> --out <new-private-report>
python -m unittest discover -s tests/rebuild -p test_game_initializers.py -v
```

Nine original offline metadata tests pass. They cover exact physical ownership,
unbound variants, wrong function/relocation kinds and interiors, duplicate/raw
site requirements, candidate multiplicity/order preservation and termination
pointer/argument uncertainty. No compiler, linker, native code or game is run.

Private `game-initializers-native-v2.json` is 9,967,641 bytes, SHA-256
`3c9e5073115525587a0cf8ebfe1ff0ad92b6dcb73a6aeed1cc86deee6394cfb1`.
Its implementation SHA-256 is
`7fe75a1eed7131f7306c14817a40868c911a4e1a8b18566688cfe3b7672ccbd4`.
The earlier bounded and v1 observations remain intact as narrower historical
artifacts. These are metadata receipts, not official MATCH, table-boundary,
runtime-provider or execution approvals. Independent review reproduced all
10,518 slot identities, 6,265 pointer-site joins and 4,765 registration fields;
the nine-object scope and boundary/stage/lifetime limitations remain unchanged.

## Finite standard-CRT candidate observation

The owner separately authorized a finite, candidate-only comparison of eight
named normal CRT functions from each of the pinned SP1, RTM and VC8 `libcmt`
archives. `tools/rebuild/crt_table_boundaries.py` first read their exact library
member/COFF metadata without reading reference code. The native `crt0dat`
member contains `__initterm`, `__initterm_e`, `__cinit`, `_doexit` and four exit
wrappers. Each searched span is the entire native section with exactly one
named function, including local funclets, with every supported COFF relocation
field precisely excluded from the non-relocation comparison. Unknown,
overlapping or out-of-range relocation formats are rejected.

Independent source review accepted the exact candidate scanner and eight
offline tests. Its hash-bound review is
`66244016ee3631d363c6768011c2cae331e4b8da1fde82682b80f41c12c36847`.
After separate root go, exactly one scan read the checked reference's pinned
`.text` logical extent (12,440,971 bytes), plus PE/hash/HIGHLOW metadata. No
other executable section or original instruction listing was read or emitted.
It preserved every full-span match and every relocation result. It did not
read boundary target payloads or run any code.

| Named function | Unique SP1/RTM candidate | Complete section span |
|---|---|---:|
| `__initterm` | `0x00ecccd3` | 29 |
| `__initterm_e` | `0x00ecccf0` | 36 |
| `__cinit` | `0x00eccd14` | 133 |
| `_doexit` | `0x00eccd99` | 300 |
| `_exit` | `0x00eccec5` | 22 |
| `__exit` | `0x00eccedb` | 22 |
| `__cexit` | `0x00eccef1` | 15 |
| `__c_exit` | `0x00eccf00` | 15 |

All eight SP1 patterns and all eight RTM patterns have one match each at the
same addresses. Thus compiler-family identity is not distinguished by these
matches. VC8 has no match for six patterns and matches the two shared small
exit wrappers; those alternatives remain explicit. Every observed DIR32 field
has actual original HIGHLOW provenance; REL32 fields have none. All decoded
target addresses fit image geometry and the same-family named traversal and
exit-helper candidates join consistently. External helper and data-symbol
identities remain unverified, even where a numeric binding agrees with an
existing source observation.

The named relocation operands yield these **unverified boundary candidates**:

| Stage spelling | Begin candidate | End candidate | Named caller |
|---|---|---|---|
| XI | `0x010113c4` | `0x010113e8` | `__cinit` |
| XC | `0x00fdf4a4` | `0x010113c0` | `__cinit` |
| XP | `0x010113f4` | `0x01011400` | `_doexit` |
| XT | `0x01011404` | `0x01011408` | `_doexit` |

They come from exact named native relocations in the matched caller spans,
never from pointer runs, nearest nulls or address sorting. They are not adopted
table bounds. Required next proof includes every remaining helper/data/EH
relocation identity and variant-specific call/argument/failure/termination
semantics. Native library inspection already shows why a generic signature is
insufficient: this SP1 `__initterm` receives its begin pointer through EAX and
its end pointer on the stack, while `__initterm_e` takes two stack arguments;
the unmatched VC8 `__cinit` inlines its XC loop. No new public prototype or
runtime provider is approved by recognizing those mechanics.

Private `crt-boundary-candidates-native-v1.json` is 95,950 bytes, SHA-256
`f268c8d3ebd5cd305b022c6b0bec3dc40d1709ec862e1a942ba71733c6d3df7c`.
The scanner SHA-256 is
`374b3cd65e5879b2450bdff5eb9d152b900e689300dacf353af016116b3c8c06`;
test source SHA-256 is
`f893b84f5bd356516db7b5070f858cd1ded7f39aef2844dd2078ed0b27ea90a6`.
Independent direct receipt reconciliation checked all 18 saved matched spans
and 100 relocation sites against the pinned text/native members and HIGHLOW
metadata. It did not repeat the search or establish uniqueness/exhaustiveness,
helper identity or stage/boundary proof. All boundary, runtime-order,
registration and provider flags remain false.

The next finite proof can probe eleven direct standard-CRT helpers at the exact
targets already decoded from this receipt, rather than searching `.text` again:
`__IsNonwritableInCurrentImage`, `__initp_misc_cfltcvt_tab`, `__RTC_Terminate`,
`_atexit`, `__SEH_prolog4`, `__SEH_epilog4`, `__lock`, `__unlock`,
`__decode_pointer`, `__encoded_null` and `___crtExitProcess`. All have real
definitions in the pinned normal library. Their entire native sections and
relocations must be compared; the two SEH helpers share one 89-byte section
with epilog symbol offset 69, so slicing at guessed function boundaries is
inappropriate. New dependencies must remain explicit until independently
proved. An address derived from a caller operand is a probe target, not proof
of that callee's identity.

Native library metadata also supplies concrete data obligations: `__FPinit`
is in a 12-byte read-only section with three function-pointer fields; the TLS
callback cell has one native function-pointer field; three exit-state symbols
occupy distinct offsets in shared BSS; and onexit begin/end are tentative
four-byte declarations. These observations neither adopt original runtime
values nor establish production storage or object extent. Any subsequent
read-only field proof must be bounded to named operands, with no payload
pattern search or null-based boundary inference. These next helper/data proof
steps require their own concrete source/tests, review and root authorization;
they were not included in the one completed candidate scan.

The exact-address helper source and five offline tests are now prepared as
`tools/rebuild/crt_boundary_helpers.py`. Contracts-only mode inspected the
eleven named native helpers and the saved candidate receipt, with no original
code read. Its planned complete native-section probes request 682 bytes in
total, including the shared SEH section twice under its two named symbols.
Private `crt-boundary-helper-contracts-v1.json` is 17,857 bytes, SHA-256
`815398cfc3466f7e89661779be3c917cc8b1688db3d90bf7eabcc605358584dc`.
After independent review and separate root go, the exact eleven helper probes
ran once under the shared metadata lease: 682 requested bytes, exit zero in
approximately 0.59 seconds. All eleven complete native-section comparisons
matched outside their relocation fields. The 35 field observations retain
three `___ImageBase` references with the existing outside-logical-section
diagnostic; their header-base role is not silently waived. No extra address,
recursive helper, payload search or game execution was attempted.

Private `crt-boundary-helper-probes-native-v1.json` is 36,704 bytes, SHA-256
`46a32adedeed001defb64c68ef59a1df6ba4506c8ce0f5b85bb04d890ad005df`.
Its exact source-review hash is
`6f2b7201c633a7940add06b00edc57c2adf8d9ae0dad190b25d8b5efb2746a5e`.
Exclusive start and separate terminal operation journals preserve the once-only
operation. Independent saved-receipt reconciliation accepted all 11/682/35
joins without rereading the original. This still approves no helper identity,
boundary, stage, ABI or runtime provider.

## Complete retained-object CRT inventory

The earlier compact whole-recipe COFF inventory retains aggregate evidence,
not per-object CRT slot details. After independent source review of
`tools/rebuild/game_crt_inventory.py` and five offline tests, a separate root
go authorized one serial exact-manifest observation. It reparsed the 2,988
retained objects, rechecked source/object/input hashes and emitted all native
`.CRT`/`.CRT$` metadata to a private gzip ledger. It read no game image,
walked no directory and invoked no compiler, linker or native code.

| Complete retained metadata observation | Count |
|---|---:|
| Objects inspected | 2,988 |
| Objects with CRT sections | 15 |
| CRT sections, all named `.CRT$XCU` | 17 |
| Native pointer relocations | 10,526 |
| Bound targets at selected physical source-code locations | 6,266 |
| Unbound native targets | 4,260 |
| Unrelocated native-zero slots | 1 |
| Relocations with recorded structural issues | 0 |

Compared with the nine-object observation, there are eight additional native
relocations. Only one has a recipe binding and selected physical owner:
`??__EgNiPoint3StartupDst@@YAXXZ`, original function `0x00a62110`, recipe 1385.
The other seven remain unbound; the original 4,253 variant slots are retained
separately. Recipe 2739 additionally has one unrelocated native-zero slot and
an associative XCU section whose actual association is preserved.

These are compiler-emitted source-object facts. Even a selected bound function
in a native XCU section is not proof that the original game registered that
function in its original CRT table: reconstruction scaffolding can emit extra
initialization. This inventory supplies candidates and exclusions for the
future original-table join; it cannot establish original table participation,
replace stage/order proof or select all arrays for runtime use.

The private `game-crt-all-native-v1/report.json` is 1,401 bytes, SHA-256
`ae4aa835090331446ec05d73330b6a9979d9e6a1b07393669817c28705cf0a3f`.
Its `details.jsonl.gz` is 523,905 bytes, SHA-256
`1dd38beb7dc802c3ca5ab56f23862e24c83f0141c9dce6a733eb18105db75929`.
Source review hash is
`68806763ed0718c18b6e47d0546f0cb1df1142f691cc247999ead52e32bc5c69`.
Independent actual inventory reconciliation checked the complete manifest join
and all 15 CRT-containing native source/object pairs. All registration,
original-order and runtime-provider approvals remain false.

## Conditional traversal witnesses and next cell classification

`tools/rebuild/crt_traversal_plan.py` reads only pinned native CRT code, saved
observations and data-plan geometry; it has no original-image argument. Its
complete instruction models cover both leaf walkers. Symbolic operand joins
and deliberately partial caller models verify the XI stack arguments and error
branch, the XC register/stack argument pair and the conditional XP/XT path.
Every native relocation is joined to its actual instruction operand field;
all 100 core and 35 helper observations remain in the output. Source/compiler
family alternatives and all unproved helper/data/EH/callback identities remain.

The accepted conclusions are local and conditional: a reached XI traversal
walks forward, skips nulls and returns a nonzero callback status; the local
caller then bypasses XC on nonzero status. On the stated exit path, dynamic
onexit processing precedes XP, which precedes XT. A nonzero tested exit flag
branches directly to XT. These are not observed calls, reachability, initial
state or whole-program startup/termination order. They do not establish that
saved addresses are definitive historical CRT identities or approve runtime
registration.

Independent source/receipt review reproduced four models and their exact
operand-derived range descriptions; all six focused tests pass. Private
`crt-traversal-plan-v2.json` is 83,919 bytes, SHA-256
`15a2c8695f45c891e390e5d34b8320c43adbb588f35d0e0bf525782964235426`.
The aggregate proposed non-executable read is 204,640 bytes: the four exact
begin-inclusive/end-exclusive ranges above plus their four named end cells.
The proposed read is geometry-checked and bounded, and is never inferred from
neighboring zeroes, pointer runs or function-address order. The saved plan's
table-read and startup/provider approval flags remain false.

The next concrete source draft is `tools/rebuild/crt_table_classify.py`, with
six passing offline tests. It would read exactly those four-byte cells through
the non-executable-only PE reader and preserve every original index, null,
unknown and relocation outcome. Code entry/interior candidates join the exact
saved selected-owner spans, native XCU slot identities and observed standard
CRT candidates without selecting providers. Competing intervals and physical
native slots remain separate; bound native targets not present in these
conditional ranges are reported explicitly. Non-address words are hashed
without emitting their raw values. The classifier has no original code read,
search, execution, initializer registration or source materialization path.

After independent source/input review, root delegated exactly that observation
under a metadata lease. It ran once, exit zero in approximately 1.37 seconds,
reading 204,640 non-executable bytes into 51,160 serialized cell records. No
original code was read or executed. Every null, unknown, source candidate,
native slot candidate and original index remains in the private detail.

| Conditional range | Traversed cells | Non-null code targets | Null cells, including named end | Cells with selected source owners | Cells with native XCU candidates |
|---|---:|---:|---:|---:|---:|
| XI | 9 | 8 | 2 | 0 | 0 |
| XC | 51,143 | 17,728 | 33,416 | 17,191 | 6,265 |
| XP | 3 | 2 | 2 | 0 | 0 |
| XT | 1 | 0 | 2 | 0 | 0 |

The XC targets are distinct; each of its 17,191 selected targets joins exactly
one source entry at offset zero. All 17,191 selected symbols have a
void/cdecl/no-argument source spelling. That observation is a signature
candidate, not callback ABI approval. The remaining 537 XC code targets and
all eight XI/two XP targets have no selected source owner or observed member
of the finite standard-CRT candidate set. They remain explicit unresolved
callbacks; none was replaced with null, a no-op or an alias.

Only 6,265 of the 6,266 bound native XCU targets occur in these ranges.
Initializer `0x00a62110` is not observed in these candidate intervals. Conversely, 10,926 selected XC entries have
no native reconstructed XCU contribution. Replaying the compiled native arrays
therefore cannot supply the observed conditional sequence. This non-observation
authorizes neither a general startup-registration exclusion nor deletion of its
selected code provider; other startup paths and whole-stage identity remain open.

Private `crt-table-classification-native-v1/report.json` is 691,117 bytes,
SHA-256 `1b55e12d7183c9ecba055bffac0f6b422b90dd07a978604edf2f56d200188dc5`.
Its `cells.jsonl.gz` is 1,090,248 bytes, SHA-256
`a64baec56c7d9ce887ef8b74971390e490c680cb95ed0a4b5dc42225c985ef12`.
The source/input review hash is
`33b8faa3b85f66e2115fc5b9fb45a1b56c608f2852c03780cad12a4d4661de49`.
Exclusive outer operation journals and the observer's fsynced completion log
remain private. Independent saved-outcome review reconciled all 51,160 cells,
exact stage/index/site order, per-stage counts, source/native/candidate joins,
participation and missing lists without rereading the original image.
The range evidence remains conditional; historical boundary, startup order,
callback ABI, storage/lifetime and runtime-provider approvals remain false.

## Concrete fresh-CRT registration proposal

`tools/rebuild/game_crt_registration_plan.py` is a saved-metadata transform,
with five passing synthetic tests. It emits no C++, COFF, callable stub or
provider. Every one of the 51,160 slots is retained. Its 17,191 source-reference
proposals join all physical source/native facts to the complete planned
namespace, whose input has **zero materialized exports**. The exact canonical
contract is `_fnv_code_` plus the hash of the original selected physical
`{recipe_id, object_sha256, symbol_index}` identity, never an address-derived
or spelling-derived alias. A prospective C identifier is recorded for review;
the source spelling does not authorize a declaration or indirect call.

Private `fresh-crt-registration-plan-v2/report.json` has SHA-256
`d9f622a2769473d6c97c7892d63eaddaca434b356b2bdb0a19b05b5a3a7116a6`;
its `entries.jsonl.gz` has SHA-256
`c0d34566abb8cb78e8cace869fc02f7164a2dfa88be71abe4283b94eaec872a8`.
The planned physical namespace is independently reviewed map
`6cd5bf884bb28d460cfc92f63b765c15413904f58355844243ddd6b59b97001c`.
The output distinguishes 17,191 proposed source references, 547 unresolved
callbacks, 33,418 conditional null skips and four end-cell observations.
No registration can be generated from this proposal while its blockers remain.
V1 remains as an unapproved historical proposal; v2 corrects its overly broad
startup-exclusion label to non-observation in these four candidate intervals.
Independent v2 review reconciled every slot against the saved classifier,
recomputed all 17,191 physical owner/span/canonical-name joins against the
planned namespace, and verified the counts, corrected scope and false flags.
The five offline tests pass. This accepts the metadata proposal, not source
emission, callable ABI, startup order, registration or runtime adoption.

The proposed implementation sequence is concrete:

1. Assign all 537 XC and ten XI/XP unknowns to exact source or standard-runtime
   roles with reviewed ABI and ownership. For the standard C/exit stages,
   inspect the pinned library's native CRT contribution metadata and the fresh
   host's actual linked tables, then propose finite exact-target comparisons if
   needed. Unknown Game callbacks need their own authorized source-owner work;
   do not expand the original-code read scope automatically.
2. Verify actual canonical exports and complete CODE/DATA/EH/CRT closure for
   every application callback, including non-null object extents, allocation,
   constructor and cleanup lifetime. A planned namespace is insufficient.
3. Match runtime-owned positions/stages against the one reviewed fresh normal
   CRT. Resolve original interleaving before choosing one aggregate Game
   dispatcher or several ordered application intervals. Do not copy original
   XI/XP/XT data or replay their callbacks alongside the fresh CRT's own tables.
4. Create source-authored normal-CRT registration roots referencing the exact
   canonical source entries in preserved original slot order. The normal CRT
   must already own cookie, TLS, C runtime state and the exit registry. Fresh
   linked table contents and root placement require independent inspection;
   source order or a guessed subsection name is insufficient.
5. Require independently reviewed duplicate-root and native-XCU contribution
   plans for the runtime target. Do not adopt unbound variants or derive a
   general startup exclusion from absence in the candidate intervals. Preserve
   reference objects and code providers.
   Keep each initializer body's registration behavior against the same fresh
   `atexit` registry; never pre-register a reversed destructor list or copy
   original onexit pointer templates.

First validate the registration glue on original synthetic callbacks covering
ordering, nulls, XI failure, duplicate-root rejection, lazy registration and
normal exit. Any Game initialization remains a separate gated operation.
Fresh CRT placement, original runtime identity/reachability and the complete
application lifetime contracts remain unresolved; no dispatch source or Game
initializer was emitted or executed by this work.
