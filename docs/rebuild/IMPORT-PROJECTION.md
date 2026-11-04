# Normal import projection: offline identity preparation v2

`tools/rebuild/import_projection.py` prepares the actual selected main entry's
25 original IAT-cell obligations and 30 verified DIR32 fields. It emits an
original JSON metadata report and four text DEF files; it never invokes LIB,
LINK, a compiler, DLL loading, an API or game code. It reads only the three
explicit input artifacts, with their exact accepted SHA-256 identities. This
is preparation for normal import libraries, not a usable linked provider.

The full v3 catalog remains 280 separate original cells, 256 named and 24
ordinal identities from 17 DLLs. The core validates that complete catalog but
selects only exact verified uses of main `0x0086a850`, recipe
`0576-dd603b7071c482c6`. Every selected row must preserve the exact original
DLL and exported name, or DLL and ordinal. Hints do not select exports. Source
spellings are recorded only as provenance. For example, main field 2805 calls
through source spelling `__imp__GetForegroundWindow@0`, but original cell
`0x00fdf2fc` identifies USER32 `GetActiveWindow`. The DEF therefore names
`GetActiveWindow`. No SDK library or API is chosen from the source spelling.

Canonical labels follow the accepted CODE namespace: `unresolved(base,
'iat-cell')` from `runtime_code_pool.py`. The actual preparation separately
pins, records and rechecks that helper file's exact SHA-256 before publication;
changed helper source fails closed. It also
hash-binds `canonical-reference-main-v1/certificate.json` and requires every
selected physical symbol index to have exactly that label in its namespace
plan. Planned serialized indices are copied as explicit metadata. These labels
denote pointer cells, never function bodies. No original address becomes a
runtime absolute fallback.

## Report and DEF contract

`preparation.json` has kind `fnv-normal-import-projection-preparation`, schema
version 2, status `offline-preparation-only`. `selected_cells` preserves
`import_id`, `original_IAT_va`, `dll`, exact `export` and
`canonical_IAT_symbol`. `fields` preserves physical/serialized symbol indices,
section, field offset, zero addend, DIR32 kind, source spelling, one-based detail
ordinal and canonical JSON detail hash. The report binds all three input file
hashes and its implementation hash. The actual scope must reconcile 25 cells,
25 physical symbols and 30 fields. DLL counts are GDI32 1, KERNEL32 7,
SHELL32 2 and USER32 15, all named exports.

The DEF files contain `LIBRARY` with the exact DLL spelling and `EXPORTS` with
the actual exported names as safe **unquoted** tokens. The report records
`definition_syntax=vc9-unquoted-safe-export-tokens-v2`. This first DEF writer
accepts only simple export tokens matching `[A-Za-z_][A-Za-z0-9_]*`, which covers
the actual main selection. The complete catalog retains decorated and unusual
original identities unchanged, but generating a DEF for such a selected name
fails pending separate syntax conformance. Quotes, spaces, comment/alias
separators, paths and `@` decoration are never escaped or guessed. Ordinal catalog entries are supported by the core as
`fnv_ordinal_NNNNN @N NONAME`: the generated token is only an import-library
local symbol, with no inferred API name. This first actual main selection has
no ordinal entries. Duplicate export identities within one DLL may share a DEF
entry, but their original cells and canonical obligations remain distinct in
the report; this preparation authorizes no pointer-cell coalescing.

`definition_preparation` records each DEF hash, DLL, proposed private library
basename and an unevaluated `LIB /MACHINE:X86 /DEF:... /OUT:...` operation.
The tool does not locate or execute LIB. It emits **no canonical link aliases**.
The generated import-library member's actual public pointer symbol cannot be
assumed from export spelling or calling-convention decoration. It must be
inspected independently after a separately approved native LIB run. In
particular, ordinal symbols, underscore-prefixed exports and VC9 decoration
remain explicit mechanical conformance obligations.

All source ABI, provider adoption, native library generation, native pointer
symbol verification and executable-link flags remain false. The report's
blockers distinguish source review/root approval, native member conformance and
source call ABI/runtime adoption. Successful identity preparation does not
approve mismatched source declarations, callbacks, argument types, return
types, module lifetimes, runtime flags or eventual application execution.

## Private invocation and gates

After source review and a recorded root go, prepare into a new private directory:

```powershell
python tools/rebuild/import_projection.py --plan build/rebuild/import-plan-native-v3.json --details build/rebuild/import-plan-native-v3.jsonl.gz --namespace build/rebuild/canonical-reference-main-v1/certificate.json --out build/rebuild/import-projection-main-v2
```

Independent source review and run authorization are recorded by the coordinator;
the tool has no native execution capability and no separate approval CLI.

Existing output directories are rejected, as are destinations inside the
checkout outside ignored `build/rebuild`. External private destinations are
allowed. Inputs, tool and namespace helper are rehashed before output creation
and again after DEF writes before final report publication; detail streaming has
bounded row/count limits. Failures remove
only files created by this invocation in its newly created directory. Reports
contain no private input paths, binary payloads, disassembly or game bytes.

The next separately authorized operation is native library creation and
independent import-member inspection, followed by an exact pointer-to-pointer
canonical alias proposal and alias-only extraction verification against the
actual retained application-entry object. That operation cannot link or run an
executable, load DLLs or approve application semantics. Full provider closure,
source ABI review and executable linking remain later gates. The earlier
synthetic alias fixture is not repeated or promoted to actual main evidence.

Offline tests:

```powershell
python -m unittest discover -s tests/rebuild -p test_import_projection.py -v
```

The actual metadata-only join was evaluated in memory: all 25 labels agree
with the accepted main namespace, all 30 fields agree with the v3 import use
details, and four DEF texts were prepared in memory. No output preparation
directory, native library, executable, linker alias or provider was created
during that source-development check.

## Preserved v1 native failure

The independently reviewed v1 metadata preparation was followed by a separately
authorized bounded native LIB inspection. Its first GDI32 library revealed that
VC9 LIB retains quote characters around an `EXPORTS` token as part of the
exported name. The actual member therefore exposed `__imp__"GetStockObject"`
and would request the wrong export. The exact DLL/export join rejected that
library. The other three LIB operations were never attempted. No alias, link,
DLL load or imported API call occurred.

Private `import-native-main-v1/failure-reconciliation.json` records the failure,
all completed commands, hashes and unchanged original inputs, tools and source.
Its SHA-256 is
`6132322ba435d806e30c92221022aab368e9b159446a0d9172d6e19293d8353d`.
The v1 DEFs, failed library and operation journal remain immutable evidence;
they are not usable import providers. V2 removes only the export-token quotes
from the already restricted identity grammar. New metadata and native output
directories, independent source/output review and coordinator authorization are
required before that compatibility correction becomes accepted native evidence.
