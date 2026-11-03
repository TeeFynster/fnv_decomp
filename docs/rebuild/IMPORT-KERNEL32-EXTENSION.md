# Exact KERNEL32 import extension

`tools/rebuild/import_kernel32_extension.py` prepares one replacement for the
accepted seven-export KERNEL32 library. Its new eight-export DEF preserves
those seven identities and adds catalog import 102, original IAT cell
`0x00fdf1c4`, `KERNEL32.dll!InterlockedDecrement`. The other three accepted
libraries stay unchanged, and the earlier four libraries are never overwritten.
The replacement must be selected instead of the old KERNEL32 library; the
contract does not rely on descriptor sharing between two KERNEL32 archives.

The tool is offline: it cannot invoke LIB, DUMPBIN, a compiler or linker, load a
DLL or call an imported API. It hash-binds the exact original import catalog,
accepted v2 preparation/native collection, all four actual old libraries and
its source helpers. The bounded pure archive reader was derived from the
accepted native-v2 reader, with extra size and malformed-input guards. It
reconciles both linker indexes and actual short-import header/name encodings.
Ordinary descriptor objects remain separately subject to independent conformance
review; this reader records their machine and hashes without claiming full
descriptor semantic verification.

The DEF emits only safe unquoted simple export tokens, preserving the lesson
from the immutable v1 quoted-export failure. Original hints and lookup mode are
retained as metadata in the request, never used to guess an export, stack
convention or pointer symbol. Existing native pointer identities for the seven
old exports must be preserved. New member offsets and the additional pointer
symbol must be observed from the actual new library.

## Metadata and later native schema

The private `preparation.json` has kind
`fnv-kernel32-import-extension-request`, schema 1, status `offline-prepared`.
It binds `inputs` and `source_sha256`; its `replacement` names the old library
and hash and the new `kernel32-eight.lib`, with counts seven and eight.
`cells` contains exactly eight original import IDs, IAT cells, canonical
pointer labels, DLL/export identities and original export hint metadata.
`prior_kernel32_aliases` retains the seven accepted old pointer mappings;
`prior_other_aliases` and `unchanged_libraries` preserve the other 18 cells and
three libraries. `definition` binds the exact `kernel32-eight.def` hash.
`operation_plan` contains only one proposed LIB generation and two DUMPBIN
metadata inspections, without executing any of them.

The future private native result has kind
`fnv-kernel32-import-extension-native-collection`, schema 1, status
`collected-awaiting-independent-conformance`. It must bind the exact request
file hash, the request's source/input ledger, an actual
`library={file,sha256,bytes}` and `parsed_archive` from that same library.
Its positive mechanical flags are `native_library_generated`,
`replacement_identity_verified`, `old_seven_pointer_identities_preserved` and
the native collector's `all_inputs_tools_sources_stable`.
`proposed_pointer_aliases` contains 26 distinct canonical cell/native pointer
pairs: the eight reobserved KERNEL32 members and the 18 unchanged prior mappings.
It cannot apply those aliases. A caller must independently validate the actual
archive and source/request hashes; an arbitrary JSON assertion is not evidence.

Alias application, source ABI verification, runtime-provider adoption,
executable linking, compiling, DLL loading, imported API calls, runtime
eligibility and provider selection remain explicitly false. The tool also
leaves `global_caller_census_verified=false`: the separate application cohort
owner must certify every included use of all 26 canonical cells before any
global link-only alias plan is selected. Import-prefixed source-use metadata
alone is not a complete census of arbitrary emitted source spellings.

## Bounded preparation

After independent source/input review, the coordinator can prepare a new
private directory using the reviewed source hash:

```powershell
python tools/rebuild/import_kernel32_extension.py --plan build/rebuild/import-plan-native-v3.json --previous build/rebuild/import-projection-main-v2/preparation.json --native build/rebuild/import-native-main-v2/collection.json --source-sha256 <reviewed-source-hash> --out build/rebuild/import-kernel32-extension-v1
```

Outputs must be new and contained under ignored `build/rebuild`.
Source/input/old-library hashes are rechecked before output creation,
after the DEF write and after final request publication. Failure removes only
new files. No game bytes, payloads, disassembly or private paths enter public
tooling, tests or documentation.

Any native phase requires separately scoped source/input review, coordinator
go and the existing CPU-heavy lease. Its one LIB command and read-only DUMPBIN
inspections use the accepted VC9 SP1 tools, finite per-command time/output
bounds, durable operation records and input/tool/source/artifact hashes before
and after the operation. A failed or uncertain operation is retained and
reconciled rather than replayed.

Offline tests:

```powershell
python -m unittest discover -s tests/rebuild -p test_import_kernel32_extension.py -v
```
