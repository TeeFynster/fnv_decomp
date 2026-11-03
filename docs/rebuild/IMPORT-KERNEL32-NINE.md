# Fixed nine-export KERNEL32 replacement

`tools/rebuild/import_kernel32_nine.py` is an additive, offline eight-to-nine
import preparation. It preserves the accepted eight-export source, libraries,
receipts and reviews. The sole new identity is catalog import 13, original cell
`0x00fdf060`, `KERNEL32.dll!GetTickCount`, original hint 614. Source spellings do
not select the DLL, export or provider. A new nine-export library replaces the
selected eight-export KERNEL32 library; the other three libraries stay selected.

The request hash-binds the original catalog, accepted eight-export preparation,
native collection and independent outcome, and the fixed V5 unresolved ledger
and metadata assessment. It also verifies the actual eight-export archive and
the three unchanged library hashes. Two saved included uses are preserved:
recipe `0035-e741388caa42d2bf`, root `0x00aa5040`, and recipe
`0107-45cf4d1906d848ed`, root `0x00aa50a0`. Each must retain the exact canonical
cell, physical symbol index, field offset, DIR32 kind, zero addend and matching
original base/target. These records are metadata evidence, not a fresh extraction
proof or complete future-cohort census.

The new private preparation has kind
`fnv-kernel32-nine-import-extension-request`, schema 1. `replacement` binds the
old library name/hash, new `kernel32-nine.lib` and exact counts eight/nine.
`cells` preserves all nine original identities and hint/lookup metadata;
`prior_kernel32_aliases` preserves eight actual native pointer identities.
The 18 other aliases and three libraries retain their prior evidence.
`new_cell_included_use_records` preserves both V5 field records. The safe
unquoted nine-name DEF is bound by its hash. No native command is invoked by
this tool. All inputs and source helpers are rehashed before creation, after
the DEF write and after the final request write. Output is new, exclusive and
contained under ignored `build/rebuild`; drift removes only newly owned files.

The separately reviewed native collector may perform one bounded LIB command
and two DUMPBIN metadata inspections only under root's delegated go and a
coordinator-owned CPU-heavy lease. It uses the accepted VC9 SP1 binaries, source
and input hashes, durable operation journal, 30-second per-command bounds,
4-MiB combined stdout/stderr cap and a 120-second whole-phase bound. It never
self-reserves a resource slot or replays a failed/uncertain operation.

The native collection has kind
`fnv-kernel32-nine-import-extension-native-collection`, schema 1, status
`collected-awaiting-independent-conformance`. It binds the actual produced
`library={file,sha256,bytes}`, request/source/input identities, both archive
indexes, nine actual short imports and three descriptor/null-thunk members.
The positive mechanical flags are `native_library_generated`,
`replacement_identity_verified`, `old_eight_pointer_identities_preserved` and
the collector's `all_inputs_tools_sources_stable`. Twenty-seven distinct
canonical-to-native-pointer proposals retain the 18 unchanged mappings and
nine reobserved KERNEL32 members. Actual offsets, member hashes and native
hints are reobserved; old native hints or offsets are not presumed identical.

Alias application, source ABI verification, provider adoption, runtime
eligibility, compiling, executable linking, DLL loading and imported API calls
remain false. The consumer must separately validate every included use before
selecting global link-only aliases. Neither this preparation nor the native
identity result approves application execution.

```powershell
python tests/rebuild/test_import_kernel32_nine.py -v
```
