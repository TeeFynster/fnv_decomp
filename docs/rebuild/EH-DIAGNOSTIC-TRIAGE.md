# Local EH diagnostic triage

Read-only audit, November 3, 2026 (America/Chicago), following checkpoint
`38cc726`. All **95 preserved diagnostics across 16 retained objects** are
accounted for below. The failed strict baseline, v2 and v3 have the exact same
ordered diagnostic lists and object identities. This audit does not repair them.

| Evidence class | Diagnostics | What prevents strict local proof |
|---|---:|---|
| B: bound-target conflict | 22 | Cleanup non-relocation content agrees, but the own-recipe or globally unique name binding resolves to a different target. Eight use own-recipe bindings; fourteen use the cross-recipe name dictionary. |
| S: same native helper, conflicting placements | 2 | The same defined native helper section is observed at two different original destinations; the comparator's first section placement cannot satisfy subsequent uses. |
| N: native cleanup content/layout conflict | 71 | Six to ten non-relocation bytes differ at an exact unwind-map-derived cleanup pointer. Relabeling a call target cannot repair this evidence. Source ABI/cleanup declaration versus original semantic cause remains unresolved. |
| Parser exception, unsupported relocation or bad symbol-index diagnostic | 0 | None of the 95 diagnostic messages comes from these paths. This does not certify every parser feature or an entire runtime component. |

Every diagnostic arises from `tools/build_and_match.py::eh_sections` line 168,
its relocation-target mismatch path. All 61 affected parent observations have
actual associative `.text$x` owners and matched same-object ordinary parent
rows. Each failure has a pointer-field origin in a hash-checked native `.xdata`
section. Across those **61 xdata blocks**, every non-relocation metadata byte
agrees with the corresponding original block. The 95 exact pointer fields are
listed separately below. This materially narrows the placement uncertainty;
it does not prove the complete EH frame/state/ABI contract or all relocated
metadata fields.

The unchanged function was replayed only on the sixteen exact manifest-selected
objects, using v3's actual matched-parent rows and the unchanged full-recipe name
map. A Python tracing hook observed the mismatch branch's existing locals; it
changed neither the function nor its result. Complete returned piece arrays,
inferred mappings and ordered diagnostic lists agreed with v3. Original/source
objects, the image and matching core were read only; no compilation, linking,
native execution, disassembly, section extraction, alias adoption or service/model
operation occurred. Code payloads and raw differences are excluded from this
report. Difference counts mask all relocation fields within the piece, including
fields after the particular reported mismatch.

## Why the original overall MATCH remains true

The original `eh_tails` gate accepts each listed interval if matching pieces from
any valid unit cover it; it does not require every unit's local helper declarations
to reproduce that interval. Therefore 1,954 globally covered listed tails and
68,667 matched ordinary recipe rows can coexist with these 95 local notes.
The 95 textual notes are not a complete failed-piece inventory: v3 records
116 false local pieces among 1,720 pieces in these sixteen units, plus twelve
false pieces in units without textual EH errors. The unchanged function marks
a non-relocation mismatch `ok=false` at lines 169-171 without appending a text
error. This audit classifies the requested 95 textual diagnostics only; it does
not silently certify the other pieces. A future provider gate must inspect all
retained code and metadata results, not merely an empty `eh_errors` list.

The existing `strict_local_eh_diagnostics_pass=false` and
`runtime_closure_verified=false` remain correct. The absent optional function
index remains an explicit baseline limitation, not a new cause assigned to these
95 relocation diagnostics. No original gate, receipt or diagnostic was changed.

## Source and native ownership implications

**Binding conflicts (B).** Global symbol-name uniqueness is a recipe indexing
fact, not type identity or one correct runtime provider. Examples include inline
`Ptr` and `RefPtr` types with different reference-counting declarations across
translation units. In unit 10, its inline `Ptr` destructor is actually defined in
native section 157, yet the global dictionary wins before section-local evidence:
both cleanup calls bind to `0x0045cec0`, while their original destinations are
`0x00ae9290`. Eight B observations already use explicit own-unit bindings; they
cannot be explained solely as cross-unit borrowing. Unit 88's named local-list
destructor binding (`0x00ae83e0`) conflicts with `0x00a0c7a0`, for example.

Unit 802 is especially decisive: constructor `0x0043fd40` source at
`src/fallout_shared/modelloader.cpp:11581` uses `SubObjA` for members +0x2c/+0x38
and `SubObjB` for +0x30/+0x34. All its cleanup non-relocation content agrees, but
three calls disagree with global bindings. Two distinct cleanup roles bearing
the same `SubObjB` name call `0x0040c110` and `0x0045cec0`, while that name binds
to `0x00488ff0`. No single global rename of `SubObjB::~SubObjB` can satisfy both.
Member offsets and actual state edges must determine separate role identities.
The named source line does not alone establish which offset belongs to which
cleanup; that association is a next proof obligation, not inferred here.

Unit 2576 provides a small allocator-pairing warning:
`havokstream.cpp:1074` supplies class-specific `operator new` forwarding to
`FUN_0056d280`, but no class-specific delete declaration in that type. The emitted
failure cleanup references ordinary `operator delete`, bound to `0x00401030`;
the original destination is `0x00538eb0`. The remaining cleanup content agrees.
This supports investigating the allocator-family contract, not substituting a
new deallocator on address evidence alone.

**Section conflict (S).** Both observations belong to unit 2761 parent
`0x00bd6570`, `.text$x` section 471, whose physical parent is section 470.
Source `blk_00bc0000_o2.cpp:7385` models all three members as the same
`ObjectReference` type and emits one 33-byte destructor in section 468, with an
IAT reference to `InterlockedDecrement`. The first cleanup (+0, not a diagnostic)
places that helper at `0x0045cec0`. The +8 and +19 cleanups instead call
`0x00b66f20`. Their non-relocation content agrees, but `data_bases.setdefault`
(lines 160-162) preserves the first helper-section placement, leaving these two
expected targets unresolved. This is a demonstrated single-native-helper to
multiple-original-role conflict, not a corrupt symbol index. Address-based helper
cloning or choosing the first call would erase the unresolved source/type roles.

**Content/layout conflicts (N).** Sixty-two involve ordinary delete, four
`NiMemObject` delete, one the memory-manager global and four names first inferred
elsewhere within the same failing unit. Source examples include `tileimage.cpp`
array/object allocations, `debugshader.cpp` nested `new` expressions and
`blk_00bc0000_o2.cpp:2102` class-specific allocation with no matching delete
declaration. This connects the generated cleanups to actual source lifetime
constructs. It does not prove their intended original deallocation signature.
The independent table/scalar agreement and exact pointer fields rule out a bare
nearest-parent guess as the evidence used here. Native code content still differs
under those placements; decoding ABI/state semantics remains required.

The four inferred-name mismatch observations are unit 253 #4, unit 362 #2/#3 and
unit 2761 #25. `eh_sections` lines 163-165 will infer a REL32 destination when a
name is absent, without first proving non-relocation content or target executable
membership. In these already incompatible cleanups, a first arithmetic value can
then conflict on a subsequent use. Such receipt values are retained historical
inference, not callable addresses or canonical providers. Accordingly, the N rows
below suppress numeric target arithmetic rather than presenting it as recovered
code identity. In total, the 95 resolution paths are 89 bound-name conflicts,
four repeated inferred-name conflicts and two defined-section conflicts.

## Per-unit reconciliation

| Unit | Source | B | S | N | Total |
|---:|---|---:|---:|---:|---:|
| 10 | `src/bsaudio/bsaudiomanager_ob1_variant.cpp` | 2 | 0 | 1 | 3 |
| 88 | `src/bsmenu/tile.cpp` | 1 | 0 | 0 | 1 |
| 98 | `src/bsmenu/tileimage.cpp` | 0 | 0 | 5 | 5 |
| 149 | `src/bsshader/debugshader.cpp` | 0 | 0 | 4 | 4 |
| 253 | `src/fallout/ai/actor.cpp` | 0 | 0 | 4 | 4 |
| 362 | `src/fallout/ai/highprocess.cpp` | 0 | 0 | 6 | 6 |
| 386 | `src/fallout/ai/movement/actormover.cpp` | 0 | 0 | 7 | 7 |
| 396 | `src/fallout/ai/playercharacter.cpp` | 0 | 0 | 4 | 4 |
| 549 | `src/fallout/magic/magicprojectile.cpp` | 0 | 0 | 1 | 1 |
| 802 | `src/fallout_shared/modelloader.cpp` | 3 | 0 | 0 | 3 |
| 1030 | `src/fallout_shared/tesleveledlist.cpp` | 0 | 0 | 2 | 2 |
| 2576 | `src/havok/unplaced/havokstream.cpp` | 1 | 0 | 0 | 1 |
| 2629 | `src/staging/blk_00420000_od.cpp` | 1 | 0 | 0 | 1 |
| 2698 | `src/staging/blk_008c0000_od.cpp` | 0 | 0 | 3 | 3 |
| 2759 | `src/staging/blk_00ba0000_o2.cpp` | 4 | 0 | 16 | 20 |
| 2761 | `src/staging/blk_00bc0000_o2.cpp` | 10 | 2 | 18 | 30 |

## Complete diagnostic ledger

Ordinals are one-based within each unit's exact original `eh_errors` list; repeated
identical strings remain distinct observations. Native offsets are decimal.
Expected/observed values are shown only where non-relocation content agrees.
Neither category B nor S authorizes a provider or local runtime extraction.

| Unit | Diagnostic ordinal | Parent | Native section + piece offset | Symbol | Class | Nonrelocation differences | Expected / observed target |
|---|---:|---|---|---|---|---:|---|
| 10 | 1 | `0x00adea90` | 155 + 8 | `??1Ptr@@QAE@XZ` | B | 0 | `0x45cec0` / `0xae9290` |
| 10 | 2 | `0x00adea90` | 155 + 16 | `??1Ptr@@QAE@XZ` | B | 0 | `0x45cec0` / `0xae9290` |
| 10 | 3 | `0x00add960` | 318 + 0 | `?DAT_011f6238@@3UPoolX@@A` | N | 10 | untrusted target arithmetic; content differs |
| 88 | 1 | `0x00a07dc0` | 59 + 0 | `??1FUN_00ae83e0@fnv_00a07dc0@@QAE@XZ` | B | 0 | `0xae83e0` / `0xa0c7a0` |
| 98 | 1 | `0x00a1fd50` | 30 + 8 | `??3@YAXPAX@Z` | N | 10 | untrusted target arithmetic; content differs |
| 98 | 2 | `0x00a1fd50` | 30 + 22 | `??3@YAXPAX@Z` | N | 10 | untrusted target arithmetic; content differs |
| 98 | 3 | `0x00a1fd50` | 30 + 47 | `??3@YAXPAX@Z` | N | 10 | untrusted target arithmetic; content differs |
| 98 | 4 | `0x00a1fd50` | 30 + 61 | `??3@YAXPAX@Z` | N | 10 | untrusted target arithmetic; content differs |
| 98 | 5 | `0x00a1fd50` | 30 + 86 | `??3@YAXPAX@Z` | N | 9 | untrusted target arithmetic; content differs |
| 149 | 1 | `0x00bd24c0` | 169 + 0 | `??3NiMemObject@@SAXPAX@Z` | N | 7 | untrusted target arithmetic; content differs |
| 149 | 2 | `0x00bd24c0` | 169 + 11 | `??3NiMemObject@@SAXPAX@Z` | N | 7 | untrusted target arithmetic; content differs |
| 149 | 3 | `0x00bd24c0` | 169 + 22 | `??3NiMemObject@@SAXPAX@Z` | N | 7 | untrusted target arithmetic; content differs |
| 149 | 4 | `0x00bd23f0` | 242 + 0 | `??3NiMemObject@@SAXPAX@Z` | N | 7 | untrusted target arithmetic; content differs |
| 253 | 1 | `0x008c4d10` | 892 + 0 | `??3@YAXPAX@Z` | N | 7 | untrusted target arithmetic; content differs |
| 253 | 2 | `0x008b2c30` | 934 + 0 | `??3@YAXPAX@Z` | N | 9 | untrusted target arithmetic; content differs |
| 253 | 3 | `0x008b2c30` | 934 + 14 | `??3@YAXPAX@Z` | N | 9 | untrusted target arithmetic; content differs |
| 253 | 4 | `0x008b52a0` | 1098 + 44 | `??3Node@fnv_008b52a0@@SAXPAX@Z` | N | 10 | untrusted target arithmetic; content differs |
| 362 | 1 | `0x00904450` | 41 + 0 | `??3@YAXPAX@Z` | N | 7 | untrusted target arithmetic; content differs |
| 362 | 2 | `0x008df1e0` | 399 + 91 | `??3Query65@fnv_008df1e0@@SAXPAX@Z` | N | 10 | untrusted target arithmetic; content differs |
| 362 | 3 | `0x008df1e0` | 399 + 105 | `??3Queue65@fnv_008df1e0@@SAXPAX@Z` | N | 9 | untrusted target arithmetic; content differs |
| 362 | 4 | `0x009a1400` | 510 + 0 | `??3@YAXPAX@Z` | N | 7 | untrusted target arithmetic; content differs |
| 362 | 5 | `0x009a1400` | 510 + 19 | `??3@YAXPAX@Z` | N | 7 | untrusted target arithmetic; content differs |
| 362 | 6 | `0x009a1400` | 510 + 52 | `??3@YAXPAX@Z` | N | 10 | untrusted target arithmetic; content differs |
| 386 | 1 | `0x009db090` | 157 + 0 | `??3@YAXPAX@Z` | N | 7 | untrusted target arithmetic; content differs |
| 386 | 2 | `0x009db090` | 157 + 11 | `??3@YAXPAX@Z` | N | 7 | untrusted target arithmetic; content differs |
| 386 | 3 | `0x009db090` | 157 + 22 | `??3@YAXPAX@Z` | N | 7 | untrusted target arithmetic; content differs |
| 386 | 4 | `0x009db090` | 157 + 33 | `??3@YAXPAX@Z` | N | 7 | untrusted target arithmetic; content differs |
| 386 | 5 | `0x009db090` | 157 + 44 | `??3@YAXPAX@Z` | N | 10 | untrusted target arithmetic; content differs |
| 386 | 6 | `0x009db090` | 157 + 58 | `??3@YAXPAX@Z` | N | 10 | untrusted target arithmetic; content differs |
| 386 | 7 | `0x009db090` | 157 + 72 | `??3@YAXPAX@Z` | N | 10 | untrusted target arithmetic; content differs |
| 396 | 1 | `0x009614b0` | 402 + 11 | `??3@YAXPAX@Z` | N | 10 | untrusted target arithmetic; content differs |
| 396 | 2 | `0x00962de0` | 429 + 0 | `??3@YAXPAX@Z` | N | 9 | untrusted target arithmetic; content differs |
| 396 | 3 | `0x00962de0` | 429 + 14 | `??3@YAXPAX@Z` | N | 9 | untrusted target arithmetic; content differs |
| 396 | 4 | `0x00962de0` | 429 + 28 | `??3@YAXPAX@Z` | N | 10 | untrusted target arithmetic; content differs |
| 549 | 1 | `0x0081aab0` | 49 + 33 | `??3@YAXPAX@Z` | N | 7 | untrusted target arithmetic; content differs |
| 802 | 1 | `0x0043fd40` | 793 + 8 | `??1SubObjA@@QAE@XZ` | B | 0 | `0x4037d0` / `0x44cbf0` |
| 802 | 2 | `0x0043fd40` | 793 + 19 | `??1SubObjB@@QAE@XZ` | B | 0 | `0x488ff0` / `0x40c110` |
| 802 | 3 | `0x0043fd40` | 793 + 30 | `??1SubObjB@@QAE@XZ` | B | 0 | `0x488ff0` / `0x45cec0` |
| 1030 | 1 | `0x00c60d70` | 59 + 0 | `??3@YAXPAX@Z` | N | 6 | untrusted target arithmetic; content differs |
| 1030 | 2 | `0x00c610a0` | 69 + 0 | `??3@YAXPAX@Z` | N | 7 | untrusted target arithmetic; content differs |
| 2576 | 1 | `0x00624f10` | 107 + 0 | `??3@YAXPAX@Z` | B | 0 | `0x401030` / `0x538eb0` |
| 2629 | 1 | `0x00436660` | 264 + 8 | `??1NodeBase@@QAE@XZ` | B | 0 | `0xba3d30` / `0x40ecb0` |
| 2698 | 1 | `0x008d6bb0` | 128 + 0 | `??3@YAXPAX@Z` | N | 7 | untrusted target arithmetic; content differs |
| 2698 | 2 | `0x008d6bb0` | 128 + 11 | `??3@YAXPAX@Z` | N | 7 | untrusted target arithmetic; content differs |
| 2698 | 3 | `0x008d6bb0` | 128 + 22 | `??3@YAXPAX@Z` | N | 7 | untrusted target arithmetic; content differs |
| 2759 | 1 | `0x00bb7300` | 94 + 0 | `??3@YAXPAX@Z` | N | 7 | untrusted target arithmetic; content differs |
| 2759 | 2 | `0x00bb3e30` | 127 + 0 | `??3@YAXPAX@Z` | N | 7 | untrusted target arithmetic; content differs |
| 2759 | 3 | `0x00ba82a0` | 225 + 0 | `??3@YAXPAX@Z` | N | 7 | untrusted target arithmetic; content differs |
| 2759 | 4 | `0x00ba8a00` | 247 + 0 | `??3@YAXPAX@Z` | N | 7 | untrusted target arithmetic; content differs |
| 2759 | 5 | `0x00baa0e0` | 287 + 0 | `??1BAA0E0Base@@UAE@XZ` | B | 0 | `0xa5c240` / `0xa99f30` |
| 2759 | 6 | `0x00baedc0` | 354 + 0 | `??3@YAXPAX@Z` | N | 7 | untrusted target arithmetic; content differs |
| 2759 | 7 | `0x00baee40` | 358 + 0 | `??3@YAXPAX@Z` | N | 7 | untrusted target arithmetic; content differs |
| 2759 | 8 | `0x00bb1080` | 458 + 8 | `??3@YAXPAX@Z` | N | 7 | untrusted target arithmetic; content differs |
| 2759 | 9 | `0x00bb3170` | 502 + 0 | `??3@YAXPAX@Z` | N | 7 | untrusted target arithmetic; content differs |
| 2759 | 10 | `0x00bb3280` | 516 + 0 | `??3@YAXPAX@Z` | N | 7 | untrusted target arithmetic; content differs |
| 2759 | 11 | `0x00bb45d0` | 640 + 0 | `??3@YAXPAX@Z` | N | 7 | untrusted target arithmetic; content differs |
| 2759 | 12 | `0x00bb4680` | 662 + 8 | `??3@YAXPAX@Z` | N | 7 | untrusted target arithmetic; content differs |
| 2759 | 13 | `0x00bb7210` | 676 + 0 | `??3@YAXPAX@Z` | N | 7 | untrusted target arithmetic; content differs |
| 2759 | 14 | `0x00bb7ef0` | 704 + 0 | `??3@YAXPAX@Z` | N | 7 | untrusted target arithmetic; content differs |
| 2759 | 15 | `0x00bb9180` | 734 + 0 | `??1SpawnedBase@@QAE@XZ` | B | 0 | `0x40ecb0` / `0xba3d30` |
| 2759 | 16 | `0x00baec90` | 832 + 8 | `??1RefPtr@@QAE@XZ` | B | 0 | `0x44cbf0` / `0x45cec0` |
| 2759 | 17 | `0x00baec90` | 832 + 30 | `??1RefPtr@@QAE@XZ` | B | 0 | `0x44cbf0` / `0x45cec0` |
| 2759 | 18 | `0x00bb3f10` | 929 + 0 | `??3@YAXPAX@Z` | N | 7 | untrusted target arithmetic; content differs |
| 2759 | 19 | `0x00bb3fc0` | 981 + 0 | `??3@YAXPAX@Z` | N | 7 | untrusted target arithmetic; content differs |
| 2759 | 20 | `0x00baff20` | 1499 + 0 | `??3@YAXPAX@Z` | N | 7 | untrusted target arithmetic; content differs |
| 2761 | 1 | `0x00bc2020` | 124 + 0 | `??3@YAXPAX@Z` | N | 7 | untrusted target arithmetic; content differs |
| 2761 | 2 | `0x00bc2cb0` | 139 + 0 | `??3@YAXPAX@Z` | N | 7 | untrusted target arithmetic; content differs |
| 2761 | 3 | `0x00bc33f0` | 190 + 0 | `??3@YAXPAX@Z` | N | 7 | untrusted target arithmetic; content differs |
| 2761 | 4 | `0x00bc3620` | 212 + 0 | `??3@YAXPAX@Z` | N | 7 | untrusted target arithmetic; content differs |
| 2761 | 5 | `0x00bc3830` | 234 + 0 | `??3@YAXPAX@Z` | N | 7 | untrusted target arithmetic; content differs |
| 2761 | 6 | `0x00bc38c0` | 240 + 0 | `??3@YAXPAX@Z` | N | 7 | untrusted target arithmetic; content differs |
| 2761 | 7 | `0x00bc4340` | 262 + 0 | `??3@YAXPAX@Z` | N | 7 | untrusted target arithmetic; content differs |
| 2761 | 8 | `0x00bc43b0` | 272 + 8 | `??3@YAXPAX@Z` | N | 7 | untrusted target arithmetic; content differs |
| 2761 | 9 | `0x00bc4830` | 309 + 22 | `??1RefPtr@@QAE@XZ` | B | 0 | `0x44cbf0` / `0xb66f20` |
| 2761 | 10 | `0x00bc4830` | 309 + 36 | `??1RefPtr@@QAE@XZ` | B | 0 | `0x44cbf0` / `0xb66f20` |
| 2761 | 11 | `0x00bd6570` | 471 + 8 | `??1ObjectReference@@QAE@XZ` | S | 0 | `unresolved` / `0xb66f20` |
| 2761 | 12 | `0x00bd6570` | 471 + 19 | `??1ObjectReference@@QAE@XZ` | S | 0 | `unresolved` / `0xb66f20` |
| 2761 | 13 | `0x00bc3540` | 557 + 0 | `??3@YAXPAX@Z` | N | 7 | untrusted target arithmetic; content differs |
| 2761 | 14 | `0x00bcfb00` | 624 + 0 | `??3@YAXPAX@Z` | N | 7 | untrusted target arithmetic; content differs |
| 2761 | 15 | `0x00bc0c90` | 873 + 22 | `??1RefPtr@@QAE@XZ` | B | 0 | `0x44cbf0` / `0xb66f20` |
| 2761 | 16 | `0x00bc0c90` | 873 + 36 | `??1RefPtr@@QAE@XZ` | B | 0 | `0x44cbf0` / `0xb66f20` |
| 2761 | 17 | `0x00bc3110` | 1223 + 0 | `??3@YAXPAX@Z` | N | 7 | untrusted target arithmetic; content differs |
| 2761 | 18 | `0x00bc36a0` | 1229 + 0 | `??3@YAXPAX@Z` | N | 7 | untrusted target arithmetic; content differs |
| 2761 | 19 | `0x00bc39f0` | 1235 + 8 | `??1?$NiPointer@URefObj@@@@QAE@XZ` | B | 0 | `0xb66f20` / `0x45cec0` |
| 2761 | 20 | `0x00bc39f0` | 1235 + 22 | `??1?$NiPointer@URefObj@@@@QAE@XZ` | B | 0 | `0xb66f20` / `0x45cec0` |
| 2761 | 21 | `0x00bc39f0` | 1235 + 36 | `??1?$NiPointer@URefObj@@@@QAE@XZ` | B | 0 | `0xb66f20` / `0x45cec0` |
| 2761 | 22 | `0x00bcb210` | 1376 + 74 | `??1?$NiPointer@VNiRefObject@@@@QAE@XZ` | B | 0 | `0xb66f20` / `0x45cec0` |
| 2761 | 23 | `0x00bcb210` | 1376 + 88 | `??1?$NiPointer@VNiRefObject@@@@QAE@XZ` | B | 0 | `0xb66f20` / `0x45cec0` |
| 2761 | 24 | `0x00bcb210` | 1376 + 102 | `??1?$NiPointer@VNiRefObject@@@@QAE@XZ` | B | 0 | `0xb66f20` / `0x45cec0` |
| 2761 | 25 | `0x00bd4d30` | 1428 + 11 | `??3NiD3DShaderConstantMap@@SAXPAX@Z` | N | 7 | untrusted target arithmetic; content differs |
| 2761 | 26 | `0x00bd6190` | 1432 + 30 | `??3@YAXPAX@Z` | N | 7 | untrusted target arithmetic; content differs |
| 2761 | 27 | `0x00bd6190` | 1432 + 41 | `??3@YAXPAX@Z` | N | 7 | untrusted target arithmetic; content differs |
| 2761 | 28 | `0x00bd6190` | 1432 + 52 | `??3@YAXPAX@Z` | N | 7 | untrusted target arithmetic; content differs |
| 2761 | 29 | `0x00bd6190` | 1432 + 63 | `??3@YAXPAX@Z` | N | 7 | untrusted target arithmetic; content differs |
| 2761 | 30 | `0x00bc3190` | 1480 + 0 | `??3@YAXPAX@Z` | N | 7 | untrusted target arithmetic; content differs |

## Bounded metadata observations

| Unit | Diagnostic ordinal | Native xdata section + pointer-field offset | Original xdata base | Original cleanup pointer | Nonrelocation metadata differences |
|---|---:|---|---|---|---:|
| 10 | 1 | 156 + 12 | `0x116de68` | `0xf22105` | 0 |
| 10 | 2 | 156 + 20 | `0x116de68` | `0xf2210d` | 0 |
| 10 | 3 | 319 + 4 | `0x116de00` | `0xf220a1` | 0 |
| 88 | 1 | 60 + 4 | `0x11683e4` | `0xf1d058` | 0 |
| 98 | 1 | 33 + 48 | `0x116978c` | `0xf1e589` | 0 |
| 98 | 2 | 33 + 56 | `0x116978c` | `0xf1e59e` | 0 |
| 98 | 3 | 33 + 72 | `0x116978c` | `0xf1e5be` | 0 |
| 98 | 4 | 33 + 80 | `0x116978c` | `0xf1e5d3` | 0 |
| 98 | 5 | 33 + 96 | `0x116978c` | `0xf1e5f3` | 0 |
| 149 | 1 | 175 + 4 | `0x1178658` | `0xf2cb80` | 0 |
| 149 | 2 | 175 + 12 | `0x1178658` | `0xf2cb92` | 0 |
| 149 | 3 | 175 + 20 | `0x1178658` | `0xf2cba1` | 0 |
| 149 | 4 | 243 + 4 | `0x1178054` | `0xf2c310` | 0 |
| 253 | 1 | 893 + 4 | `0x11620a4` | `0xf157c0` | 0 |
| 253 | 2 | 935 + 4 | `0x1161c44` | `0xf15280` | 0 |
| 253 | 3 | 935 + 12 | `0x1161c44` | `0xf15292` | 0 |
| 253 | 4 | 1099 + 72 | `0x1161ce0` | `0xf15373` | 0 |
| 362 | 1 | 42 + 4 | `0x1162f34` | `0xf16a40` | 0 |
| 362 | 2 | 400 + 104 | `0x11628f4` | `0xf162c6` | 0 |
| 362 | 3 | 400 + 112 | `0x11628f4` | `0xf162db` | 0 |
| 362 | 4 | 511 + 40 | `0x1165d78` | `0xf1a3b0` | 0 |
| 362 | 5 | 511 + 56 | `0x1165d78` | `0xf1a3c7` | 0 |
| 362 | 6 | 511 + 80 | `0x1165d78` | `0xf1a3ef` | 0 |
| 386 | 1 | 159 + 40 | `0x1166f0c` | `0xf1b9c0` | 0 |
| 386 | 2 | 159 + 48 | `0x1166f0c` | `0xf1b9d2` | 0 |
| 386 | 3 | 159 + 56 | `0x1166f0c` | `0xf1b9e4` | 0 |
| 386 | 4 | 159 + 64 | `0x1166f0c` | `0xf1b9f6` | 0 |
| 386 | 5 | 159 + 72 | `0x1166f0c` | `0xf1ba08` | 0 |
| 386 | 6 | 159 + 80 | `0x1166f0c` | `0xf1ba1d` | 0 |
| 386 | 7 | 159 + 88 | `0x1166f0c` | `0xf1ba32` | 0 |
| 396 | 1 | 404 + 48 | `0x1164460` | `0xf1859b` | 0 |
| 396 | 2 | 430 + 4 | `0x11644e0` | `0xf18640` | 0 |
| 396 | 3 | 430 + 12 | `0x11644e0` | `0xf18652` | 0 |
| 396 | 4 | 430 + 20 | `0x11644e0` | `0xf18664` | 0 |
| 549 | 1 | 50 + 20 | `0x115e528` | `0xf11211` | 0 |
| 802 | 1 | 795 + 12 | `0x1140130` | `0xeec198` | 0 |
| 802 | 2 | 795 + 20 | `0x1140130` | `0xeec1a3` | 0 |
| 802 | 3 | 795 + 28 | `0x1140130` | `0xeec1ae` | 0 |
| 1030 | 1 | 60 + 4 | `0x117b740` | `0xf30090` | 0 |
| 1030 | 2 | 70 + 4 | `0x117b76c` | `0xf300ba` | 0 |
| 2576 | 1 | 108 + 4 | `0x114d1b8` | `0xefc070` | 0 |
| 2629 | 1 | 266 + 12 | `0x113fa64` | `0xeeb998` | 0 |
| 2698 | 1 | 129 + 4 | `0x11625f8` | `0xf15e30` | 0 |
| 2698 | 2 | 129 + 12 | `0x11625f8` | `0xf15e3f` | 0 |
| 2698 | 3 | 129 + 20 | `0x11625f8` | `0xf15e4e` | 0 |
| 2759 | 1 | 95 + 4 | `0x1177924` | `0xf2baa0` | 0 |
| 2759 | 2 | 128 + 4 | `0x117729c` | `0xf2b260` | 0 |
| 2759 | 3 | 226 + 4 | `0x1176db8` | `0xf2ac80` | 0 |
| 2759 | 4 | 248 + 4 | `0x1176e68` | `0xf2ad40` | 0 |
| 2759 | 5 | 289 + 4 | `0x1176f70` | `0xf2ae60` | 0 |
| 2759 | 6 | 355 + 4 | `0x117729c` | `0xf2b260` | 0 |
| 2759 | 7 | 359 + 4 | `0x11772c8` | `0xf2b290` | 0 |
| 2759 | 8 | 459 + 12 | `0x11774ac` | `0xf2b508` | 0 |
| 2759 | 9 | 503 + 4 | `0x1177610` | `0xf2b6d0` | 0 |
| 2759 | 10 | 517 + 4 | `0x117763c` | `0xf2b700` | 0 |
| 2759 | 11 | 641 + 4 | `0x1177790` | `0xf2b880` | 0 |
| 2759 | 12 | 663 + 12 | `0x11777bc` | `0xf2b8b8` | 0 |
| 2759 | 13 | 677 + 4 | `0x11778f8` | `0xf2ba70` | 0 |
| 2759 | 14 | 705 + 4 | `0x1177a48` | `0xf2bbf0` | 0 |
| 2759 | 15 | 736 + 4 | `0x1176f9c` | `0xf2ae90` | 0 |
| 2759 | 16 | 834 + 12 | `0x1177258` | `0xf2b218` | 0 |
| 2759 | 17 | 834 + 28 | `0x1177258` | `0xf2b22e` | 0 |
| 2759 | 18 | 930 + 4 | `0x117729c` | `0xf2b260` | 0 |
| 2759 | 19 | 982 + 4 | `0x117cf48` | `0xf31c30` | 0 |
| 2759 | 20 | 1500 + 4 | `0x117d614` | `0xf32430` | 0 |
| 2761 | 1 | 125 + 4 | `0x1177e0c` | `0xf2c080` | 0 |
| 2761 | 2 | 140 + 4 | `0x1177e64` | `0xf2c0e0` | 0 |
| 2761 | 3 | 191 + 4 | `0x1177ebc` | `0xf2c140` | 0 |
| 2761 | 4 | 213 + 4 | `0x1177e90` | `0xf2c110` | 0 |
| 2761 | 5 | 235 + 4 | `0x117594c` | `0xf29080` | 0 |
| 2761 | 6 | 241 + 4 | `0x1177f14` | `0xf2c1a0` | 0 |
| 2761 | 7 | 263 + 4 | `0x1177fb0` | `0xf2c250` | 0 |
| 2761 | 8 | 273 + 12 | `0x1177fdc` | `0xf2c288` | 0 |
| 2761 | 9 | 311 + 20 | `0x1178010` | `0xf2c2d6` | 0 |
| 2761 | 10 | 311 + 28 | `0x1178010` | `0xf2c2e4` | 0 |
| 2761 | 11 | 472 + 12 | `0x11788a8` | `0xf2cea8` | 0 |
| 2761 | 12 | 472 + 20 | `0x11788a8` | `0xf2ceb3` | 0 |
| 2761 | 13 | 558 + 4 | `0x1177ee8` | `0xf2c170` | 0 |
| 2761 | 14 | 625 + 4 | `0x11784c4` | `0xf2c960` | 0 |
| 2761 | 15 | 876 + 20 | `0x1177cbc` | `0xf2bf06` | 0 |
| 2761 | 16 | 876 + 28 | `0x1177cbc` | `0xf2bf14` | 0 |
| 2761 | 17 | 1224 + 4 | `0x1177e90` | `0xf2c110` | 0 |
| 2761 | 18 | 1230 + 4 | `0x1177ebc` | `0xf2c140` | 0 |
| 2761 | 19 | 1237 + 12 | `0x1177f40` | `0xf2c1d8` | 0 |
| 2761 | 20 | 1237 + 20 | `0x1177f40` | `0xf2c1e6` | 0 |
| 2761 | 21 | 1237 + 28 | `0x1177f40` | `0xf2c1f4` | 0 |
| 2761 | 22 | 1378 + 72 | `0x1178364` | `0xf2c7ba` | 0 |
| 2761 | 23 | 1378 + 80 | `0x1178364` | `0xf2c7c8` | 0 |
| 2761 | 24 | 1378 + 88 | `0x1178364` | `0xf2c7d6` | 0 |
| 2761 | 25 | 1429 + 12 | `0x1178330` | `0xf2c73f` | 0 |
| 2761 | 26 | 1433 + 64 | `0x117884c` | `0xf2ce3e` | 0 |
| 2761 | 27 | 1433 + 72 | `0x117884c` | `0xf2ce50` | 0 |
| 2761 | 28 | 1433 + 80 | `0x117884c` | `0xf2ce62` | 0 |
| 2761 | 29 | 1433 + 88 | `0x117884c` | `0xf2ce74` | 0 |
| 2761 | 30 | 1481 + 4 | `0x1177ebc` | `0xf2c140` | 0 |

## Exact retained object hashes

| Unit | Recipe identity | SHA-256 |
|---:|---|---|
| 10 | `0010-4056cf21aa35c9cf` | `4dae3dbc8ab6a549b9d48f273862c907bdeccaaa333e28650f53f707f949e7b9` |
| 88 | `0088-806415905962fa3a` | `f14845468d07ab5434dfea1f3544f4396b55a6e35e6556d95f2b02af280e3f04` |
| 98 | `0098-a0ffab4a2f2b65e3` | `90807448b46a74a4a9cd00d1fdde65c52cb43c425034c3fd7bb5a03841c14d8e` |
| 149 | `0149-51d8c6e60c0cc7a5` | `e5d4c91367d2f5e9283a6592458392bf108e4fbc7329f4e76bc84a5349bf5209` |
| 253 | `0253-640f4832895103e8` | `0ebbc5c1b782db36699b48132a9360df811123a7b446148c56a1f61f9bf3aa48` |
| 362 | `0362-6492a500e2520ad3` | `0a23d08ee4f7605ce5f7a4841b4a8dd4ee810870a7266e1d9e79116020dcce24` |
| 386 | `0386-09697cbb2992dcc9` | `e707c4c67a75efef32342cef03b11f7faf0a2188fe19733e1c4c90a5bd99503c` |
| 396 | `0396-a86e0db061d485dd` | `a457317714c677897183825de741e78dd32ffd9345fde3437432bfb76330a2d5` |
| 549 | `0549-7023b6e98b9a1db9` | `0ade9c2d34b3d716b0f156d46f9ff92dd43f4c96d7b979ad525c37954af60fdf` |
| 802 | `0802-87f974b83dab6f45` | `678bb9bf0aad418bdd58cb1e252282bad07537b24037e3ae7f2ff97145b52cc0` |
| 1030 | `1030-8af1f28b028fc897` | `bd9ddd430672d4b3d33455b9c481b03d7d60ccc20a9ef12e93f75d4685a34ecb` |
| 2576 | `2576-503f22357b5b60bb` | `c5faf1e7d99b33d231e3f9ee3eee57f0c9facf016175d5c7fc98164de6c10fea` |
| 2629 | `2629-9634b66d08912c0e` | `b5924d4cd114b1f85d7465e788a19b14e75fd444ff3a9e69a96cedb8262fbf9e` |
| 2698 | `2698-ef846f3a06d06dd8` | `486e65659947455c859ac66e3fae424654a7ebb2e3640f88cb451c7049d67315` |
| 2759 | `2759-54bb8b565e8060c9` | `a483cbe73a12c20619aec843a28d78b49cf94095149ec9a3ef6e815a5cef94a4` |
| 2761 | `2761-d09d5b8b282646ca` | `79b77622cbeb80391bad30d1815286bd50a5023b69403707a1c07c39bcc4ea0d` |
## Input identities and reproducibility boundary

All hashes below were checked against the existing private files. Inputs are
located by the exact retained manifest rows, never an archive search.

| Input | SHA-256 |
|---|---|
| Retained v3 receipt | `04d44b73e81982f846bfe8d81806db72ea669586b579ff22007dfd6f7d831297` |
| Failed strict v1 baseline | `5431ff17b697f1070d2c0a6f283361fbf28d5561957c3cb4424ddec8056ee6c3` |
| Preserved v2 receipt | `c8a8ad08b97f4d0bf1c1469a6b79e18455b4400da7c0e03a57d3afd4322df8ac` |
| Retained objects manifest | `bc62a5fb2553431b1e0547d11f366e52efb73096ea8ceb206c556ae5740a53eb` |
| Authoritative recipe | `62f2c8da5f0daa912abdf4576328706711c6561eef7f01c93a89cb71ad46fb6c` |
| Owned reference image | `df1788907c6e26ef4df0b448ead526825336356b5606650165a1ce0825097eb7` |
| Unchanged original oracle | `e4c5f0d8ef8546d1ff82f4f2092e5f65164495daa867c4ff25efd9e45a25d727` |
| Unchanged comparator | `cfcf5921b71b7a58b6f430d999a511fab9a68f037791bc60295a3083535544d1` |
| Existing EH ownership v2 summary | `67bc0711d7d864bf51e7d82532c8708e6538969d388ee6c6ec53f8a7cac5629d` |
| Existing EH ownership v2 compressed detail | `01c6166ebef21c234f6e1ef4b412b92f216bc87f98e88936914b2af86598d08f` |

The source observations for all sixteen manifest rows were rehashed and agree
with their recorded hashes. The object table above binds every affected object.
The original image was read from the same existing privately owned reference
used by v3; its complete hash agrees. No raw private path or payload is recorded
here. The prior ownership report remains analysis-only: its 1,693 observations,
663 targets with diagnostic-bearing candidates and three distinct parent concepts
must not be collapsed into runtime eligibility by this triage.

## Next bounded implementation: role-aware parent closure evidence

Extend the existing EH ownership evidence producer for **unit 802, constructor
`0x0043fd40` only**, before any provider adoption or extraction. This real source
component already demonstrates why symbol identity is insufficient. Do not make
another arbitrary synthetic runtime fixture or mutate the original oracle.

The new private evidence record should bind the current object/source/recipe and
v3 identities; retain the ordinary parent, actual association chain, handler,
FuncInfo, full unwind-map state transitions and every local cleanup symbol/offset.
For each cleanup record, identify the compiler-saved frame/object location and
source member role from explicit native evidence, retaining uncertainty. Keep
own-unit bindings, global-name bindings and observed original destinations in
separate fields. Capture all non-relocation and relocation comparison results for
both code and metadata, so a valid ordinary parent or matching table scalar never
silently certifies a failed cleanup. Preserve complete same-object proof and
original listed-tail coverage as different gates.

Acceptance is a complete one-parent state/role ledger explaining the distinct
`SubObjB` destinations, identifying their ABI and available source/provider
candidates, and identifying every unresolved frame or lifetime edge. Every local
cleanup remains attached to the compiler frame and state machine that owns it;
it is never promoted into an independently callable ordinary function. Reject
cross-parent borrowing, same-name automatic unification, inferred arithmetic from
failed pieces, or a role assignment based only on nearest address. If the source
has collapsed distinct member types, report the smallest runtime-only type/view
repair proposal with before/after contracts; changing reference source, metadata,
matching gates or runtime aliases requires a separately reviewed assignment.

In parallel planning, the already bounded unit 2761 `ObjectReference` conflict is
a useful second case: preserve its three roles and first-placement conflict as a
negative acceptance example. The 71 N observations require a later bounded
cleanup ABI/layout investigation; none is fixed by the proposed ownership ledger.
This deliverable selects no provider and proves no game link, startup or gameplay.
