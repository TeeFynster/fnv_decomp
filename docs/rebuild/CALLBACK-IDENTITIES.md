# Conditional callback identities and remaining source gaps

This continues [GAME-INITIALIZERS.md](GAME-INITIALIZERS.md) using its exact saved
conditional ranges. It does not establish that the original process reached
those callers, approve a table boundary, identify every callback, or execute
Game initialization. The earlier source/observation files remain frozen.

## Complete saved-map join

`tools/rebuild/callback_identity_audit.py` preserves all **547 distinct**
unresolved non-null cells: 537 XC, eight XI and two XP. It joins every exact
target and interior against all of these saved populations:

| Saved evidence | Population | Targets with containment evidence |
|---|---:|---:|
| Selected ordinary source-code spans | 68,657 | 0 |
| Listed recipe EH spans | 1,954 | 0 |
| All retained EH-piece rows | 12,429 | 0 |
| Matched retained EH-piece subset | 12,301 | 0 |
| Original recipe function/symbol bindings | Complete recipe | 0 |
| Bound reconstructed native CRT slots | Complete retained inventory | 0 |
| Previously observed finite CRT-model spans | All saved models | 0 |
| Selected-code binding records | 490,801 | 0 callback references |

Overlapping/repeated spans and failed EH pieces remain separate. There is no
nearest-address fallback. The 4,260 unbound native CRT slots have no proved
original function addresses and cannot be assigned by names or population
agreement. An absent join establishes only absence from these saved maps,
not absence from all source or proof of a callable instruction boundary.

The selected-code ledger contains no incoming field to the `__cinit` candidate
or application-entry candidate. It has one exact own-recipe reference from
source-owned `0x00eccf00` to the `_doexit` candidate. This supports that local
exit relation; it proves neither global reachability nor nonreachability.
Independent review reproduced all 547 map joins and incoming counts without
reading the original image.

Private `callback-identity-audit-v1.json` is 317,696 bytes, SHA-256
`4c3232a5cf35ec00055edfb4a35e383732a30a93aa4c5b5cf0138a49d60f89f9`.
The audit has no original-image argument or read path; five offline tests pass.

## Native runtime contribution evidence

`tools/rebuild/crt_callback_roster.py` reads only the exact three pinned
`libcmt.lib` archives. It inventories native section-name headers first and
parses CRT-containing members plus exact named definitions. Full native
sections, symbol offsets, intra-section ownership, relocation fields and
unsupported cases remain explicit; code bytes are not emitted.

Each library has 17 observed CRT-containing members and 16 relocated slots,
including TLS contributions outside this callback probe. The roster retains
132 unsupported member headers per family and unsupported TLS relocation
cases. It therefore does not claim exhaustive native archive coverage. The
supported XI contributions identify eight distinct candidate names per family;
XP identifies three, including an optional console/temporary-file alternative.
Duplicate CRT origins for one physical function are retained as provenance.

Private `crt-callback-roster-v2.json` is 127,015 bytes, SHA-256
`12e5fd6111af319026fe20b027d5ba016f9e929ea9b1f6990927c50cfd92e463`.
Six offline tests pass. A source/input reviewer independently reconstructed
the legitimate named-function grid before any original code read.

## Finite XI/XP comparisons

The reviewed `crt_stage_callback_probe.py` operation read ten exact windows
once, **1,754 bytes total**, and recorded all 210 native candidate comparisons.
No XC target, code search, executable-entry route, protection component or
recursive dependency was read. Whole native sections include their actual
padding/aliases; no guessed function slicing or mismatch trimming occurs.

The result has 23 fixed-span matches across nine targets and 187 failed
comparisons, with all 1,056 candidate relocation interpretations retained.
Only the fields in matching source patterns are evidence for those source
operand shapes; failed candidate interpretations do not identify callees.
The remaining XI target `0x00ec3b9a` failed every tested LIBCMT pattern.

Private `crt-stage-callback-probe-native-v1/report.json` is 622,808 bytes,
SHA-256 `290c279d409029dec63dc4d8a6a4ccbb4a34afb7c7c3dcf3240f7543595c5525`.
Its review hash is
`53c9e9d6f3ec2f06f5f790f0723bba903f028754a172da6059d74f1291c6eef3`.
Independent saved-outcome reconciliation checked all target/profile/relocation
rows and the completion journal without rereading the reference. Five scoped
offline tests pass.

A separate source-only check of the exact doctor-root `libcpmt.lib` archives
found the genuine `.CRT$XID` callback `__InitCPLocHash`, with a complete
19-byte native section in each family. The CPP library hashes are separately
pinned; their presence under a toolchain root is not proof of the original
compiler/library version or approval to adopt that runtime. Their complete
roster has no unsupported headers in this observation.

Root expressly permitted one **19-byte reread** for these new named models
because the earlier raw window was not retained. The overlap and reason are
recorded in separate operation journals; the old 210 comparisons were not
replayed. After separate peer source/input review and a metadata lease, all
three new source patterns matched. The two operand roles point to
`__ReleaseCPLocHash` candidate `0x00ec3b5a` and `_atexit` at `0x00ec658f`.
The cleanup body and all remaining target identities are not approved by this
match. Four offline tests pass and independent saved-outcome review accepted
the three profile/six relocation joins without another original read.

Private `cpp-crt-callback-roster-v1.json` has SHA-256
`3e1b57b2407d422f157ebe2904c024bb7c3f1a501fe7c9aa10cded84d6e6fbf9`;
`cpp-crt-callback-probe-native-v1/report.json` is 6,445 bytes, SHA-256
`1af59369361c6dd4b9d508bb0dfcf564208b20ad556fc038b01b76d95b940e73`.
The exact source/input review hash is
`cb874d4fb9c9187ecfb62bf86bdc18caabdb9ed19f5ef48704611828925136e1`.

## What now corresponds to named runtime source

The metadata-only `callback_correspondence.py` retains all 547 records and all
matching compiler-family alternatives. Ten targets have one matching native
symbol name each; this is **source-body correspondence**, not an approved
function instance, ABI, relocation identity or runtime provider.

| Stage | Original target | Matching native symbol | Native contribution category |
|---|---|---|---|
| XI | `0x00ec6522` | `___onexitinit` | `.CRT$XIC` |
| XI | `0x00ec7d95` | `___inittime` | `.CRT$XIC` |
| XI | `0x00ecdf4a` | `___initstdio` | `.CRT$XIC` |
| XI | `0x00ed1989` | `___sse2_available_init` | `.CRT$XIC` |
| XI | `0x00ed417e` | `___initmbctable` | `.CRT$XIC` |
| XI | `0x00ed454f` | `__sse2_mathfcns_init` | `.CRT$XIC` |
| XI | `0x00ec3b9a` | `__InitCPLocHash` | `.CRT$XID` |
| XI | `0x00edd4e7` | `___CxxSetUnhandledExceptionFilter` | `.CRT$XIY` |
| XP | `0x00ee628e` | `___termcon` | `.CRT$XPX` |
| XP | `0x00ecdffb` | `___endstdio` | `.CRT$XPXA` |

All positive field-geometry checks pass, while their independent target
identities remain open. Sixty-eight scoped relocation consistency groups have
no numeric-target conflict in this evidence. External names form consistency
hypotheses only; statics, weak records and compiler literals stay tied to
physical source members/indices. No alias or provider is chosen by name.

The 537 XC targets remain outside every saved ordinary/EH/native/address map
and have no body correspondence in the performed probes. They are not
labelled missing functions, EH handlers or constructors merely because they
are executable-section targets in the candidate range. Their exact original
cell positions and addresses remain the next ownership work list. No code at
those 537 targets was read by this continuation.

Private `callback-correspondence-v1.json` is 516,003 bytes, SHA-256
`8be8c6647f6019933e967461447790f9fd019c441d74662d3829ca1e6901a3a4`.
Five offline tests pass. Independent correspondence review rejoined all 547
callbacks, 213 compared profiles, native categories, 68 scoped consistency
groups and all false flags without reading the original image. It approved
the saved-evidence classification, not callback identity or runtime adoption.

## Why the startup interpretation is conditional

The evidence is stronger than pointer shape: actual local instruction/operand
models correspond to named CRT C/C++ walkers; their exact direct-call arguments
consume the four intervals; XI error returns locally bypass XC; and source
callback bodies/categories corroborate normal runtime initialization and exit
roles. In original slot order the XI categories are six XIC entries, then XID,
then XIY; XP is XPX then XPXA. This ordering is observed from the saved cells,
not obtained by sorting function addresses or native category labels.

That establishes a conditional normal-CRT table-consumption interpretation.
It does **not** prove that the original Game process reached those callers,
exclude an unused path or different-boundary hypothesis, or approve complete
original startup order. The separate normal-CRT fixture demonstrates the
fresh source-owned mechanism only; it is not an original-Game trace. No entry
or protection investigation is proposed to fill this gap here.

The next registration implementation still requires reviewed ownership for
every XC gap, actual canonical exports, callback ABI, data extent/lifetime,
EH/CRT compatibility and fresh linked-table placement. The ten runtime-source
correspondences can guide explicit fresh-runtime role mappings; they do not
authorize replaying original addresses or silently omitting callbacks. The
[fresh registration proposal](GAME-INITIALIZERS.md) remains unadopted. There is
no automatic registration, original-address fallback or Game execution.
