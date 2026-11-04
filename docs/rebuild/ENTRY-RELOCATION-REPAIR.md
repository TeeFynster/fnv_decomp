# Entry-reachable source relocation repair

The first proposed repair covers two actual missing fields in two selected
application-entry dependencies. It replaces only their numeric address operands
with the addresses of existing global C++ carriers. The ordinary matching
sources, headers, recipes, original retained objects and comparison tools stay
unchanged. This is a private compile-and-compare experiment; no executable,
runtime provider, data definition or object-byte patch is involved.

## Bounded classification

The entry graph is relocation reachability, not an executed call graph.
Private `entry-dependencies-next-projects-v1.json`, SHA-256
`eca726d106f800b023c831280c7f2ce7eb3d448a00a570f827dcd264d7dfc803`,
identifies 47 missing fields in 27 reachable selected owners. Its follow-on
priority derivation has not yet received separate independent review. Its
parent graph summary hash is
`20638f661c8595d92230b34f8277c0d1ba9b5e0c03c09f4c745afa0659000c66`,
detail hash `9e2eb957ef26378561843c82bae6366400bfd1122e966193878b8747c22410be`.

All 47 recipe/function/field-offset/native-section/native-offset/original-field
identities were joined exactly against the existing bounded source triage
`absolute-triage-evidence-v1.json`, SHA-256
`4e06af226997152e1a7097e93f3b96d92804b229f97139dd21c89e249c6f5a28`.
No object, image or archive scan was needed for this classification. Existing
triage supplies the recorded actual HIGHLOW operands and source expressions;
that original PE/COFF evidence was not freshly rederived during classification.

| Source-expression role | Reachable fields | Current disposition |
|---|---:|---|
| Object dispatch-header candidate | 22 | Two proposed below; one previous pilot; remaining carriers, scope and context need separate review. |
| Code-address storage | 14 | Preserve calling convention, member/free-function distinction and callback lifetime unknowns; no synthesized declarations. |
| Settings-object dereference | 5 | Complete object layout, initialization and receiver compatibility remain unknown. |
| Static indexed table access | 3 | Array extent, stride, element type and bounds remain unknown. |
| Integer-return address | 1 | Intended pointer ABI and storage identity remain unknown. |
| Opaque descriptor pointer/header | 1 | No inferred descriptor type or ABI. |
| Address-shaped base/index arithmetic | 1 | Recovered base-versus-index semantics remain questionable; no symbolic rewrite. |

These 47 are actual original HIGHLOW sites, rather than constants selected
because their values resemble addresses. Ordinary numeric constants are outside
the repair set. Missing relocation intent proves neither target storage layout
nor executable ABI. Some code targets have existing same-recipe names, but that
alone does not validate casting an arbitrary member-function identity to a raw
callback. No such repair is proposed here.

The existing `0x00aa0fc0` pilot is reachable and already has its independently
reviewed one-field compile-only evidence. Its result remains separate and does
not reduce the unchanged original 47 reachable or 88 global missing-field census.

## Exact first subset

| Owner / recipe | Original field | Existing target and binding | Source operation |
|---|---|---|---|
| `0x0084ba20`, `2689-cd7a30f3908a1d49` | Section 60, function +12; `0x0084ba2c` | `0x0107f4e8`, `?DAT_0107f4e8@@3HA` | `m_vft = (void*)0x0107f4e8;` becomes `m_vft = (void*)&::DAT_0107f4e8;`. |
| `0x00c033c0`, `2763-d9f880a2cbd3ef77` | Section 124, function +12; `0x00c033cc` | `0x010bc8a4`, `?DAT_010bc8a4@@3HA` | `*(int*)this = 0x10bc8a4;` becomes `*(int*)this = reinterpret_cast<int>(&::DAT_010bc8a4);`. |

The first source is `src/staging/blk_00840000_od.cpp`, hash
`3f69d0280bf866b54150ec59583bab93167fc743de5086e768d31a282a25c3d0`.
Its selected method is `?Init@FUN_0084ba20@fnv_0084ba20@@QAEXXZ`, extent 43.
The original statement is line 853. A global `extern int DAT_0107f4e8;`
already exists at line 1206 and its address is used at line 1219. The overlay
repeats that identical declaration in the blank line after the existing include,
before the method's namespace, preserving every newline and every other byte.
Explicit `::` qualification binds to the existing global identity.

The second source is `src/staging/blk_00c00000_o2.cpp`, hash
`7ff7286ef3b6b27740d70b6670df8486091517cb0963e151e843bd227e540b8a`.
Its constructor is `??0FUN_00c033c0@@QAE@XZ`, extent 38. The original statement
is line 1469; the same global carrier is already declared at line 1369 and
used by address at line 1427. No declaration insertion is needed.

Both own recipes bind the exact decorated global to the original target.
Neither rewrite defines an `int` at that location or asserts that the target
table is an integer. The existing declaration is only an address carrier.
Read-only placement, table extents/slots, class identities, initialization,
data lifetime, calling ABI and runtime provider adoption remain open. Existing
stores, receiver behavior, base calls and volatile member initialization stay
unchanged. No const/volatile/EH/assembly or class-layout change is introduced.

## Frozen implementation and gates

`runtime/source-overlays/entry-existing-carriers.json` is fixed by SHA-256
`5884f7d9d3cf13f28bbe767e35b871698d2ec63844c9e417037d213c23e64ff0`.
`tools/rebuild/entry_relocation_repair.py` generates complete private TUs from
the exact original source bytes. It uses the unchanged frozen pilot helpers,
original recipe/compiler flags and plain comparator. Output is a new exclusive
ignored directory; no retained input is overwritten. Compiler diagnostics and
generated sources/objects remain private.

The two pinned SP1 recipes use their existing Od/O2 flags respectively. Both
include only the original `layout_support.h`, whose stddef/CRT header chain is
explicitly pinned. Source-directory include search preserves the original
relative include origin; actual `/showIncludes` paths must remain within that
bounded set. The layout header's `__LINE__`-based static assertions retain their
original context because no line is added or removed.

Before compiling, the tool checks source, recipe, selected owner, retained
proof/object, existing same-unit carrier binding, exact reachable field and
triage identity, reference image hash and compiler identity. The compiler and
code-generator files, six explicit compiler headers and protected inputs are
observed before use and rechecked at completion. The source and output object
are pinned across geometry and comparison and checked again at completion.
An append-only fsynced progress journal and preserved failure receipt prevent
lost operations from becoming implied successes.

Acceptance requires each new field to be exactly one zero-addend DIR32 to one
undefined EXTERNAL carrier, every other relocation identical, and every other
selected-function byte identical to its retained object. Actual original
HIGHLOW site/operand and image probes are rechecked. All 182 and 118 original
same-unit function rows must pass the unchanged plain comparison, including
the exact selected extents. These are recipe rows, not newly accepted source
contributions. No broader original baseline rerun is requested.

Seven focused offline tests passed. They cover both reversible exact source
transformations, line preservation, stale/comment-only source, unauthorized
policy changes, synthetic valid/wrong-kind/nonzero/defined/duplicate DIR32
references, non-field behavior changes and complete comparison/extent gates.

```powershell
python -m unittest discover -s tests/rebuild -p test_entry_relocation_repair.py -v
```

Independent source/policy review accepted the corrected complete-row checks and
independently passed all seven tests before the coordinator's explicit native
go. All link, execution, provider and runtime states remain false. An accepted
overlay can only supply a new candidate observation; it cannot silently replace
the original selection, retained proof or census.

The CLI has no prepare-only mode: after a reviewed go, invoking it with the
required `--compile-only`, `--reference`, `--doctor` and new `--out` arguments
performs both actual native compiles and comparisons. The explicit flag records
operation intent; it is not an approval or authentication mechanism. Offline
source/test review does not invoke this CLI. Complete recipe row identities
(address, symbol and size, including multiplicity) must equal both the retained
proof before compilation and the fresh comparator output afterward. Missing,
duplicate, extra or altered comparison rows reject acceptance.

## One actual compile-only observation

The single authorized operation compiled each full affected TU once. It passed
the unchanged plain original comparator for all 182 and 118 function rows,
respectively, retaining selected extents of exactly 43 and 38 bytes. Both new
+12 fields are exact zero-addend DIR32 references to the stated existing
undefined EXTERNAL carriers. Every other selected-function byte and relocation
equals the retained original. The original PE HIGHLOW operands, image probes,
all protected input hashes, actual bounded include paths and generated
source/object stability checks passed. No compiler failure or retry occurred.

Private `entry-relocation-repair-native-v1/result.json` SHA-256 is
`87adf213385326b21869f3ffbbb327bfce03a4c12d8110439ee9416074fe6633`.
The generated source/object identities are:

| Recipe | Generated source SHA-256 | Overlay object SHA-256 |
|---|---|---|
| `2689-cd7a30f3908a1d49` | `1f4b8af77c3a620647cf07fb6069baaf3716bf6eacfd179fbe1f8cc966553adb` | `c0f9ce97214904a1d4968657b884057b19f65018a5b0a83819eae6d78d731cce` |
| `2763-d9f880a2cbd3ef77` | `fd8c95bdcf7f192dca432136c407dcd24d41625d2ac04fe25d112e76238fd2a0` | `d5d128c01f8abdeff48afbf664fe0ae99487293fc781e9d23c2033555b23fcb6` |

The operation finished in approximately two seconds and produced 2,098,091
private output bytes. Peak memory was not independently measured; no memory
exhaustion was observed. No executable was emitted, linked or run. The frozen
tool hash used was `e53492e5df865f0e862f665b7afaeba66ce6e5cffbaa85304479b8352d62e3b6`.
Independent outcome review accepted both actual artifacts. A separate raw COFF
parser verified the two relocations and all selected non-field bytes; the review
also reconciled all 300 saved comparison rows, exact generated source transforms
and 35 protected input hashes. It did not recompile or execute anything, or
independently rerun the original comparator. These two candidate-specific repairs
leave the original 47 reachable and 88 global missing field observations intact
and approve no runtime table storage or provider.
