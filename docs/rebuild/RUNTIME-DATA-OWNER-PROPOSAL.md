# Runtime data owner proposal

The practical next step is a **private, section-backed owner ledger**, followed
by a separately approved materializer that connects those owners to source-built
code. Preserve original non-executable layout where useful instead of inventing
thousands of C++ object extents. Do not copy the old process/runtime state or
turn unresolved pointers into numeric fallbacks.

No actual startup data component in the bounded known-global set is fully closed
by the present evidence. The smallest concrete lead is `g_011dee84`, the menu
smart-pointer storage. Its real construction, assignment and teardown edges are
identified below. Select it for the first real owner/lifecycle evidence contract,
not another null-only demonstration or an approved four-byte allocation.

This task read only exact saved metadata, named source neighborhoods and five
exact retained objects. It emitted no data/object/PE, changed no source or
provider, compiled/linked/loaded nothing and executed no code.

## Storage ownership is different from object extent

A proven PE section can supply a complete **storage arena** even when every
individual object boundary is not known. An arena owns the section's logical
extent and original relative offsets, with file-backed initial bytes and actual
virtual zero-fill distinguished. A view at an original address is an offset
into that owner; it does not imply that a generated `char storage[4]` declaration
owns four bytes, or that the next symbol ends the real object. A constructor
writing +8 is not forced into a four-byte allocation when the canonical arena
preserves the enclosing original storage and neighboring layout.

Conversely, section geometry does not establish every object's type, validity,
lifetime, pointer representation or runtime provider. Whole-section ownership
must not silently approve every original pointer or every constructor. Unknown
object extent alone does not rule out an arena; unresolved special-state,
address-identity, initialization and code/EH contracts still block an accepted
runtime. Keep storage geometry and semantic/lifecycle approval as separate gates.

The exact owned-data plan supplies these envelopes, not an object catalogue:

| Original symbolic range, exclusive end | Logical storage | Raw-backed logical bytes | Virtual zeros | Policy |
|---|---:|---:|---:|---|
| `.rdata` `0x00fdf000..0x0118204c` | 1,716,300 | 1,716,300 | 0 | Read-only arena candidate; split/reserve exact loader/import/CRT metadata domains. |
| `.data` `0x01183000..0x01271a9c` | 977,564 | 262,656 | 714,908 | Writable arena candidate; preserve initial file/zero distinction and exclude fresh runtime state. |
| `.tls` `0x01272000..0x012722c5` | 709 section bytes | 709 | 0 | Not an ordinary arena: the loader directory defines a separate 708-byte template. |
| `CONST` `0x01273000..0x0127301f` | 31 | 31 | 0 | Writable despite its name; semantic role remains unresolved. |

Raw alignment padding is excluded: `.rdata` has 436 extra raw bytes, `.tls` 315
and `CONST` 481. Resources and relocation sections remain separate format owners;
executable `.text` and packaging/binding ranges are never data sources. The
metadata says these non-executable raw sections currently equal the owned on-disk
file and reference; it does not describe post-constructor memory. A future writer
must pin the actual supplied owned image and recheck this relationship before
reading any selected initial bytes. The v4 report's non-executable digest is not
a substitute for a new full-input pin or a complete initial-state attestation.

## One canonical owner model

A future schema should have the following distinct records. Every original
identity is metadata, never a runtime pointer.

| Record | Required content and acceptance meaning |
|---|---|
| `arena` | Owned image/nonexec hashes, section identity, original start/logical extent, raw-backed/zero intervals, required alignment/protection, exclusions and proposed private output owner. An envelope may remain unapproved. |
| `storage_domain` | Ordinary arena-owned bytes, explicit source-owned interval, loader/CRT/TLS/import/resource state, or unresolved/reserved bytes. Exactly one active owner for each admitted original identity; overlapping typed views share storage. |
| `view` | Original address, arena-relative offset or selected source-owner offset, optional independently proved bound/type, role and physical source references. Unknown bounds remain null; address-only carriers are not sized objects. |
| `provider` | Exact retained recipe/object/symbol index and section/value/span, source proof, literal proof or separately reviewed normal-runtime/import contract. Code interior aliases require exact owning frame/control-flow evidence. |
| `field` | Actual original source site, width/representation, original target and symbol-base identity, signed/unsigned addend semantics, canonical target owner plus offset, code/data proof and blockers. |
| `lifecycle` | Pre-constructor state, initializer root/registration, dependencies and ordering, writes/alias relationships, mutation paths, paired teardown/exit registration and approval state. |

Retain a coverage partition, not an address-to-name dictionary. Join all 150,165
actual non-executable HIGHLOW sites to the complete binding observations and
canonical provider decisions. Preserve exact field identities and conflicts,
not just aggregate counts. Data-only fields have no source COFF symbol-base
proof: leave that attribute null and retain the exact arena-relative target
until a stronger view is established. Raw data's site identity is `(owned image, source
arena, field offset)`; code uses `(recipe, object hash, symbol index, physical
field)`. The reviewed physical namespacing mechanism can connect them later;
it does not create missing owners or convert a spelling into an extent.

### Arena/source ownership decisions

1. Ordinary bytes may stay in one section-backed arena with interior symbols.
   Preserving the enclosing original layout can avoid guessed per-global sizes.
   Known field views retain original offsets and all aliases into the same owner.
2. A complete proved source global/literal may instead be canonical. Its original
   address maps to that exact source owner/offset. A duplicate active allocation
   in an arena or generated `.bss` must not coexist for that original identity.
3. An arena envelope may reserve source-owned or fresh-state holes, but those
   bytes are not a second provider. Any base-plus-offset arithmetic spanning a
   hole or crossing arenas needs an explicit address-relationship contract.
   Splitting storage cannot silently preserve a relationship it actually breaks.
4. Alternatively retain a literal interval canonically in the arena and later
   remove/redirect its source definition through a reviewed transformation.
   Existing source-literal ownership is the simpler choice when complete. Do
   not merge distinct original copies just because their bytes agree; preserve
   the binding plan's 20 literal-pooling tolerances as separate observations.
5. Keep page/section alignment from the actual PE and stronger known compiler
   owner constraints. A page-aligned arena with unchanged offsets preserves
   known within-page alignment; do not infer an arbitrary object's required
   alignment solely from its old address. Do not cross final protection domains
   to save an allocation. Code is never emitted into a data arena.

The original `g_011c3264` example still rejects a four-byte object-sized provider:
its constructor/base access at least offsets 0, 4 and 8. It does **not** by itself
reject a correctly bounded original `.data` arena. The arena can preserve the
required neighboring bytes while object boundaries remain unknown. Its actual
initializer/vtable/teardown semantics and special-state relationships remain
separate blockers. The same distinction applies to the large memory-manager
storage: an envelope is possible; real heap/bootstrap providers are not proved.

## Fields and new runtime addresses

An actual loader HIGHLOW record proves a four-byte base-adjusted address field;
it does not establish a C++ pointer type. A future reviewed policy can preserve
that opaque representation without inventing a C++ type, provided its exact
canonical target identity, alignment, bounds/alias relationship and required
code/lifetime closure are settled. All current semantic-fixup approvals remain
zero. Unclassified fields remain blockers, not copied original numeric targets.

For an approved data-held absolute address, emit a symbolic DIR32 reference to
its actual source-code provider, source data owner or arena interior alias with
its proved addend. Preserve non-field bytes and original address relationships.
The existing DATA fixture already proved symbolic interior addends and virtual
zeros; the scalar and component-binding work proved source-literal ownership and
physical namespacing under changed layouts. Reuse those mechanisms and negative
cases rather than authoring another arbitrary runtime fixture.

RVA/DIR32NB, signed REL32, table-relative offsets, SECREL, tagged/encoded pointers,
serialized identifiers and runtime-populated pointers are distinct formats.
HIGHLOW absence does not prove a numeric constant or complete pointer census.
Unknown representations cannot be guessed from address-shaped values. Known
numeric sentinels stay numeric. Signed addends must retain their actual semantics.
One-past views and code/data interior aliases require explicit contracts; no
nearest-function/next-symbol resolution is allowed.

For source code, preserve the original 88 exact missing-field blockers. The
single reviewed compile-only overlay is candidate-specific evidence; it does
not repair the original audit or create a provider for its table. Any missing
field touched by the selected runtime must acquire a separately reviewed real
source relocation or keep that component ineligible. Do not patch code bytes
or leave the old operand as a fallback.

## Fresh-state and metadata ownership boundaries

| Domain | Required owner/action; never ordinary copied game state |
|---|---|
| Normal CRT | One selected normal runtime owns cookie/complement, exit tables/locks/encoding, heap/runtime objects, helper dispatch and startup. Source game allocation-manager state is a different graph. The CRT integration contract remains in its owner's lane. |
| Static TLS | Separate 708-byte original directory/template evidence, fresh loader-managed index, normal CRT array-offset mechanism and canonical field views. Original template +0x268/+0x2b4 differ from source subsection offsets; the field initially 59 is not generically zero. Current source-only TLS fixture is not game-template adoption. |
| Dynamic TLS | Havok's dynamic slot is separate from static TLS. Do not overlay it with the loader index or one shared thread block. |
| IAT/imports | Create fresh import-library/loader cells for exact DLL/name-or-ordinal identities; preserve pointer indirection. Never replace an IAT cell with a function body or copy a process DLL address. Signature/provider approval remains per contract. |
| Loader/PE state | Rebuild directory/relocation/load-config structures through the new link. Reserve/exclude their original intervals from ordinary aliases. Do not copy binding wrapper, old entry point, handles or live process state. |
| Resources/RVAs | Separate private format-aware resource plan with explicit RVA relationships. No assumption that a raw resource section is an ordinary C++ global. |
| Game RTTI/vtables/EH | Arena geometry may retain data layout, including negative metadata slots and interior relationships. Every code/helper/type-info/frame target still needs the correct provider. A named address carrier is not a complete table or class ABI. |
| Global initializer storage | One canonical pre-constructor allocation, explicit `.CRT$XCU` roots/order/dependencies and paired normal exit. Do not seed post-constructor bytes and run the constructor again, or retain a second generated placeholder allocation. |

Do not solve excluded cells merely by moving them outside an arena and assuming
all arithmetic remains valid. Any observed address/interior relation across
that boundary must be reviewed. Reserved backing space is not an active runtime
state owner; an old special-state address must resolve only to the fresh selected
owner, or remain blocked.

The data plan still contains 8,549 explicitly unresolved sites: 8,056 other-code
and 493 ambiguous EH interiors. The stronger binding plan is per-use evidence,
not a global code/data partition: 137,062 fields / 45,357 targets need image-data
ownership; 7,507 fields / 363 targets are unclassified executable targets; 6,468
fields are local EH/helper candidates. Do not sum per-role unique counts or
promote entry classification into ABI/frame closure. Preserve the full 95 local
EH diagnostics and the additionally observed 33 false local pieces; an empty
text diagnostic list is not EH closure. The EH role-aware unit-802 task remains
separate. No unresolved code/EH edge gets an original-address or guessed stub.

## One actual startup lead and why it is not closed yet

Choose `g_011dee84` for the next bounded **owner/lifecycle ledger**, because its
storage role is smaller and clearer than the setting/memory-manager examples.
This is a candidate pointer-sized **view**, not extent approval inferred from
its generated class. Actual evidence:

| Observation | Exact bounded fact |
|---|---|
| Generated root | `src/generated/global_object_initializers.cpp:8570` constructs `g_011dee84(0)`. Header lines 233-239 declare a generated class with four storage bytes; that declaration alone is not object extent proof. |
| Startup/cleanup source owners | Recipe `1678-5d04bbafe881aedd`; initializer `0x00fa2380`, 30 bytes, section 3115; cleanup `0x00fd8e10`, 15 bytes, section 6170. Both v3 rows match. |
| Physical generated storage | Symbol index 27506, section 6424/value 120 in a shared 13,460-byte `.bss`, flags `0xc0300080`, no COMDAT. Neither that offset nor the next symbol determines the real object's extent. |
| CRT registration | One actual `.CRT$XCU` field in section 6425/+11828 refers to initializer symbol index 13730. This is retention evidence, not initializer ordering or complete startup closure. |
| Constructor | Actor recipe `0253-640f4832895103e8`, `0x00633c90`, 42 bytes, section 479/value 0. Actual source has one pointer member, stores the argument and conditionally calls `0x0040f6e0`; null is the startup argument. |
| Source views | `main.cpp:12` and two staging users declare `NiPointer<NiNode>`. `main.cpp:18` assigns a newly created menu SceneGraph, so lifetime is not permanently null. |
| Cleanup | Generated cleanup calls `0x0045cec0` in recipe 386, whose actual body conditionally calls `0x00401970` on the held object. Its release/ABI and non-null destruction graph are not closed here. |
| Initial backing | The proposed four-byte view lies wholly in `.data` virtual-zero storage. That establishes zero backing for this window, not a four-byte whole-object owner or initialized SceneGraph state. |
| Complete selected-code reference census | Six exact fields in five selected functions; no addend/interior view was observed for this address. This is the saved selected scope, not proof that every unselected/generated use is absent. |
| Data-held reference census | No v4 HIGHLOW site touches the four-byte window and no v4 data target falls inside it. Zero-filled/runtime-computed pointers need not have HIGHLOW records; this negative result does not prove pointer-free lifetime. |

The six fields are:

| Selected function | Field offsets | Role |
|---|---|---|
| `0x004dc5c0` | +113 | Menu SceneGraph assignment through a smart-pointer view. |
| `0x004dc560` | +4, +23 | Object destruction and assigning null. |
| `0x005bac60` | +4 | Getter through the NiPointer view. |
| `0x00fa2380` | +6 | Initializer's storage reference. |
| `0x00fd8e10` | +4 | Exit cleanup's storage reference. |

The seven actual direct edges across the constructor/initializer/cleanup roots
are known: constructor +29 to `0x0040f6e0`; initializer +6 to the storage, +11 to
constructor, +16 to cleanup and +21 to `_atexit` (`0x00ec658f`); cleanup +4 to the
storage and +9 to destructor `0x0045cec0`. Exact code entry ownership does not
settle the differing decorated class names, ABI, non-null reference-count path,
SceneGraph allocation/destruction, or fresh exit-registry contract.

The other two previously bounded globals are not better immediate pilots:
`g_011c3264` has demonstrated placeholder under-allocation and unclosed base/
vtable initialization, while `g_011c32f0` has an empty recovered class and an
external reference-count side effect, without a complete lifetime/storage type.
This is a negative result for this **bounded three-root set**, not a claim that
no small data component exists anywhere in the game.

A full startup component cannot currently be accepted from these facts. A
null-only construction/destruction run would avoid the real menu assignment and
would not meet the goal. Do not substitute a fake NiNode/allocator or classify a
virtual-zero view as a complete live object. Preserve the candidate's position
inside a prospective `.data` arena while resolving its complete lifecycle.

## Concrete next implementation contract

Assign one new read-only `tools/rebuild/runtime_data_owners.py` with focused
`tests/rebuild/test_runtime_data_owners.py` and a fixed real-data policy/report.
Its first output is an **arena-and-view ledger**, not bytes. Suggested phases:

1. Consume only the exact v4 data plan/detail, v2 binding plan/detail, selected
   owners, v3 receipt, import/TLS/CRT/EH contracts and explicit owned-image pin.
   Reconcile all 150,165 data-site identities and all original 88 missing fields;
   preserve full original and physical identities, conflicts and input stability.
2. Create section arena envelopes from actual logical/raw/zero extents, plus a
   separate explicit special-state/exclusion ledger. Do not derive object sizes
   from placeholders or neighboring symbols. Report ordinary, source-owned,
   reserved/special and unresolved domains separately; no unreviewed owner wins
   an overlap automatically.
3. Produce per-field symbolic target proposals to selected source code/literals,
   arena interior views and fresh-runtime/import/TLS owners. Undefined/unclassified
   targets remain named blockers; do not emit old numeric pointers. Retain exact
   signed addends and every address-relationship constraint crossing domains.
4. For **g_011dee84 only**, bind all six fields, the five known selected functions,
   actual `.CRT$XCU` slot and constructor/destructor dependency graph. Establish
   its full typed view/alignment or retain an arena-relative unbounded view; do
   not assume its generated four bytes prove extent. Account for all overlapping
   views, runtime mutations, SceneGraph ownership and full non-null teardown.
5. Describe how a later copy of selected code/initializer records will reference
   the canonical owner without retaining generated `.bss` section 6424 as a
   second allocation. That section contains many globals; do not carve out or
   resize it by nearest symbols. One new canonical arena/view provider and exact
   per-physical reference remaps require separately reviewed transformations.
   `.CRT$XCU` root selection/order must match fresh CRT initialization dependencies;
   copying an entire old initializer array is not permission to execute it.
6. Independently review the complete ledger and exact blockers before authorizing
   a private materializer. Reuse the existing DATA fixture, namespaced scalar,
   source-overlay and changed-layout proofs as mechanics regression evidence.
   Do not implement another arbitrary synthetic runtime in this lane.

A later materializer may emit private COFF data arenas/views with symbolic
fixups from owned non-executable initial bytes or exact source providers only
after its selected set has zero unresolved required fields/ownership/lifecycle
edges. It must preserve envelope geometry, initial raw/zero distinction,
protections/alignment, aliases and approved original target identities, reparse
all records, link at changed layouts and obtain independent pre-execution review.
It must never emit original executable payloads, generic filler globals, old
loader/CRT/TLS state or fallback addresses. Publication remains generic code and
metadata only; derived private bytes stay private. This contract proposes the
next implementation, not current copy/link/execution approval.

## Evidence identities and review limits

All four primary saved plan/detail hashes were checked before/after the bounded
queries. Current source hashes for the eight inspected candidate/helper files
were checked; five exact retained object hashes below also matched their manifest
identities. No original payload or disassembly enters this document.

| Input | SHA-256 |
|---|---|
| Data plan owned v4 | `127644b75ed0c2826a3c1d89e4718076f4617b5a0d1f949b5faa4d61f54e6e93` |
| Data plan compressed metadata detail | `92c4058fa8ce0a74dd05d8919cc664ebf8326e9d76303d2e67338969880e5fc6` |
| Final binding plan v2 | `275714631903758efbf5a4f82e2428c6f51838f53b90d0c56d2e5dec5da1d804` |
| Final binding compressed detail | `4dfc437064b16c1bb933008aebf7def8d279a903eef9cca24d0fedcc12d7d826` |
| Retained manifest | `bc62a5fb2553431b1e0547d11f366e52efb73096ea8ceb206c556ae5740a53eb` |
| Full v3 proof | `04d44b73e81982f846bfe8d81806db72ea669586b579ff22007dfd6f7d831297` |
| Function selection v2 | `48ae62cdc5b1754b9c4af674ef4716d53afb554882e174a93acf860eaf1c6cb1` |
| Owned reference identity from v3 | `df1788907c6e26ef4df0b448ead526825336356b5606650165a1ce0825097eb7` |
| Nonexec section-content digest in v4 | `2089a87127041bb39c60b7013554a15adbe0c52d55f377f4ab63384bf2863b54` |
| Generated initializer object, recipe 1678 | `7cdcfe40803bbe2874b7edae06ee372329901f91867be56d923a4e6cb06388ca` |
| Actor constructor object, recipe 253 | `0ebbc5c1b782db36699b48132a9360df811123a7b446148c56a1f61f9bf3aa48` |
| Destructor object, recipe 386 | `e707c4c67a75efef32342cef03b11f7faf0a2188fe19733e1c4c90a5bd99503c` |
| Main source object, recipe 576 | `a6c310961921f70eea2c70b9c18dba3d85ac19bffdfe3164922e9c3462ab425b` |
| Constructor-callee object, recipe 2628 | `9a193059d9e5042721cb7962cf0ab86be535ba8f890d1a3258101d51ed7b7ae6` |

The CRT owner confirmed no copied cookie/complement, exit registry, runtime
objects or helper state; its original GUI bootstrap/cookie/exit contract is a
separate assignment. The TLS owner confirmed separate static loader state and
Havok dynamic TLS, with only original-fixture preparation authorized, not game template/reader adoption.
The EH diagnostic/role proposal remains separate. No duplicated archive audit,
fixture implementation or provider adoption occurred in this lane.

This proposal has not independently rerun the baseline comparison, data scan or
native programs. It consumes their hash-bound receipts and inspects only the
listed storage/source/reference metadata. Independent bounded proposal review
passed: it verified the plan/detail hashes, all 150,165 v4 records, the exact
six binding target-or-base matches, absence of lead-window HIGHLOWs, five
object/current-source hashes, actual constructor/initializer/cleanup relocations,
shared BSS/XCU geometry and the real SceneGraph/non-null cleanup observations.
It did not rerun the baseline or inspect the complete owner universe. The
review accepts this planning contract, not a materializer or game provider.
All runtime eligibility, link readiness and game-fixup approval states stay false
or zero. The full 95 EH notes and optional index absence remain preserved.
