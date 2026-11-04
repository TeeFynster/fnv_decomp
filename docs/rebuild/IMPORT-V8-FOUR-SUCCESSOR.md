# Fixed four-cell, two-library import successor

`tools/rebuild/import_v8_four_successor.py` prepares exact supersets of two
accepted import libraries: KERNEL32 nine to twelve, and USER32 fifteen to
sixteen. ExitProcess, InterlockedIncrement and WaitForSingleObject are added to
KERNEL32; GetAsyncKeyState is added to USER32. The two old libraries and all
earlier receipts remain immutable. The new libraries must replace the old two;
the proposal does not rely on shared descriptors between old and new libraries.
The accepted GDI32 and SHELL32 libraries remain unchanged.

The offline producer binds the accepted V8 four-cell assessment and its review,
the original import catalog, the prior 27-pointer native collection/review and
the entire immutable 45,315-field V8 ledger. It replays `census_view` without
mutating that ledger and verifies all 91 new-cell uses, including their exact
ordinals and normative/temporary-row fingerprints. The counts are one
ExitProcess, 87 InterlockedIncrement, one WaitForSingleObject and two
GetAsyncKeyState uses. These are original-cell identities and field proofs;
source spellings cannot select DLLs or exports.

The private request has kind `fnv-v8-four-import-successor-request`, schema 1.
`replacements` binds each old library/hash, exact old/new counts, definition
hash, all selected original cells and prior native pointers. `cells` contains
31 distinct identities, `prior_pointer_aliases` retains all 27 old mappings,
and `new_cell_all_use_censuses` preserves the complete V8 use evidence.
`inputs` and `source_sha256` bind the request ancestry and producer/helpers.
Original catalog hints are preserved separately from future native hints.

The offline tool invokes no native process. It reparses the two actual old
import archives to verify their exact old DLL/export/pointer identities and
preserves the other two hashes. Safe, unquoted export tokens prevent the earlier
VC9 quoted-export defect. Inputs and sources are rechecked before output,
after DEF writes and after the final request write; drift removes only newly
owned files. Outputs require a new directory under ignored `build/rebuild`.

The separately reviewed native collector is bounded to two LIB generations
and read-only DUMPBIN inspections of those two new libraries under the root's
delegation and a coordinator-owned CPU lease. It records commands, tool and
source hashes, stdout/stderr, actual library bytes/hashes, archive indexes,
short imports, descriptor/null-thunk objects and pre/post input stability. It
must not self-reserve, replay an uncertain operation, link an executable or
load an imported DLL.

`reconcile(request, parsed_libraries, request_sha256)` is the pure native join;
`parsed_libraries` maps the two new library filenames to actual bounded archive
parses. Its result has kind `fnv-v8-four-import-successor-native-collection`,
schema 1, with `libraries=[{file,sha256,bytes,parsed_archive}]`, all 31 observed
pointer proposals, exact request/source/input identities and the two unchanged
libraries. Positive flags are `native_library_generated`,
`old_27_pointer_identities_preserved`, `replacement_identities_verified`, and
the actual collector's `all_inputs_tools_sources_stable`.

Alias application, source ABI approval, provider selection, runtime adoption,
compiler/executable linking, imported DLL loading and imported API calls remain
false. `global_caller_census_verified` remains false: the later diagnostic
consumer must validate every use against its own complete immutable cohort,
even when that cohort contains non-IAT additions after V8. Native identities
and descriptor conformance require independent actual-output review.

```powershell
python tests/rebuild/test_import_v8_four_successor.py -v
```
