# COFF link inventory

`tools/rebuild/coff_inventory.py` inspects retained compiler objects without linking or reading a game image. It is a separate runtime feasibility tool. It neither changes nor establishes the reference byte-matching verdict. Read the repository [README](../../README.md), [LICENSE](../../LICENSE) and [rebuild roadmap](ROADMAP.md) first.

After building retained objects as described in [BUILD.md](BUILD.md), generate a private report:

```powershell
python tools/rebuild/coff_inventory.py --manifest build/rebuild/objects.json --out build/rebuild/link-inventory.json
```

The CLI defaults to compact aggregates and capped evidence examples. It processes one object at a time and retains global name indexes rather than the relocation graph. Add `--detail-gzip <new-private-path.ndjson.gz>` for a streaming gzip NDJSON record per object. The explicit `--full-detail-json` compatibility option retains the old full graph in memory and can produce very large files; it is not the default. Existing output paths are rejected rather than overwritten; choose fresh report names on repeat runs. Failed detail streams are removed, while a compact failure report can retain parse/omission evidence.

For independently checked full recipe coverage, supply `--recipes build/units.json --require-full`. Reconciliation verifies the authoritative file fingerprint, every recipe index exactly once, canonical recipe ID, complete recipe contents (including options and compiler variants), and repeated source/compiler fields. It rejects missing/duplicate indices and metadata substituted with freshly regenerated IDs. An unverified builder declaration alone cannot satisfy full mode. Supplying `--recipes` requests this full reconciliation and fails if the supplied objects cover only a subset.

A valid explicitly partial inventory otherwise succeeds; parse/hash errors or omitted failed/unavailable builds return failure. The report distinguishes `supplied_manifest_complete` (all objects in this supplied manifest were inspected), `full_recipe_coverage_declared` (the builder's untrusted `selection.complete` declaration), and `recipe_reconciliation.verified` (the independent coverage check). Both recipe-manifest and retained-manifest SHA-256 fingerprints are included. An empty manifest is rejected. Output cannot overwrite the retained manifest, its objects or the supplied authoritative recipe file.

Keep objects, logs, detailed reports and private paths in ignored development output or outside the checkout. Do not distribute them. Only this tool, its original synthetic tests and documentation belong in source control.

## Evidence and categories

Each object retains the builder's recipe ID/index and source, so separately compiled optimization/compiler variants of one source remain distinct. Object bytes must match the builder's recorded SHA-256 before parsing. `objects[].symbols` records primary symbol indices, storage classes, section indices, offsets, types and auxiliary counts. Auxiliary records are not mistaken for symbols or relocation targets.

Complete object records appear in optional gzip NDJSON or explicit full JSON. Compact JSON leaves `objects` empty and provides aggregate counts plus bounded examples; absence from those examples is not absence from the graph. The Python `inventory()` API retains its detailed behavior by default for existing callers; pass `compact=True` for bounded detail retention.

External definitions, absolute definitions, common storage, ordinary undefined externals and weak externals are distinct. Static, section, file and other debug/local symbols never enter the global duplicate index: repeated `$SG` labels do not establish linker collisions. Same-section/same-offset external definitions are listed as defined aliases, without claiming semantic equivalence. Weak records preserve the fallback symbol and search characteristic; the report does not simulate library search or declare the fallback resolved.

Section auxiliary records retain COMDAT policy, checksum and associative parent index. Duplicate names are categorized as multiple strong definitions, common-storage merge review, equal absolute-definition review, COMDAT no-duplicates conflict, COMDAT policy review, or incompatible/unknown COMDAT policy. Even compatible `any`/`same_size`/`exact_match`/`largest`/`newest`/associative policies remain review items. The tool does not choose a winner, prove identical relocation semantics, or decide whether a discarded COMDAT belongs to the correct original function. Different original-address evidence is preserved, including multiple addresses for one name inside a recipe.

Every relocation retains its originating section/offset, type and target primary symbol, plus a code versus data/metadata section classification. A relocation from code is not automatically a call. A relocation to a local data symbol is not an unresolved global. Metadata symbol maps are address evidence, not definitions. `original_addresses` preserves all mappings from function entries, folded aliases and the recipe's symbol map; a singular `original_address` appears only when unambiguous.

Undefined externals absent from retained definitions are categorized as import-pointer providers or other external providers. The record includes both symbol-table occurrences and actual relocation uses, so declarations without references can be distinguished. An absent provider may live in an unselected object, an appropriate runtime/import library, generated runtime support or an as-yet-unreconstructed storage definition. It is not automatically missing source. `.drectve` tokens are retained as evidence of default libraries and possible linker aliases, without executing or interpreting their options.

## Verified native smoke

The initial native VC++ 2008 SP1 smoke inspected the first **2 of 2,988** recipe entries: `NiRenderedTexture.cpp` and `bgscamerapathmanager.cpp`. Both manifest hashes matched. The reader found 115 relocations, 28 external definitions, one weak external and 55 undefined external names without providers in this selected pair. Two of those names were import pointers. There were no duplicate global names in this pair; this says nothing about duplicates in the full recipe. The selected-manifest inventory completed, while full recipe coverage remained false. Private evidence was written to `build/rebuild/link-inventory-smoke.json`.

Concrete next closure work from those objects:

| Evidence | Closure task |
|---|---|
| `/DEFAULTLIB:"LIBCMT"`, `/DEFAULTLIB:"OLDNAMES"`; `___CxxFrameHandler3`, security-cookie and RTTI references | Identify compatible compiler runtime libraries and startup configuration; test real library providers without fabricated stubs. |
| `__imp__InterlockedIncrement@4` and `__imp__InterlockedDecrement@4` | Verify the corresponding import-library definitions and runtime ABI. Original IAT addresses are provenance, not runtime pointers. |
| Eleven relocations to `CameraPathManager::ms_pDefaultCameraPath`, mapped to original `0x011ca704` | Find or reconstruct the authentic typed storage, initialization and lifetime from corroborating source evidence; do not create zero storage merely to satisfy linking. |
| Game method references such as `NodePtr<SceneNode>::operator=` and array methods | Reconcile against the full retained definition set before calling them missing. The two-object sample omits almost all source providers. |
| Weak vector-deleting-destructor symbol with scalar-deleting-destructor fallback and search characteristic 2 | Preserve and validate compiler weak-library semantics; do not count the weak entry as a second strong definition. |

Full-object evidence must precede runtime variant selection. The known recipe-level same-name/multi-address cases and overlapping source variants are candidates for that reconciliation, not a reason to use `/FORCE:MULTIPLE`.

## Full retained-object inventory

The subsequent native build retained all **2,988** recipe objects. The full inventory independently reconciled every recipe index, canonical ID, compiler, source and recipe contents against `build/units.json` and verified every retained object hash, with zero parse/hash errors and no omitted recipes. This establishes full coverage of the supplied build evidence, not a link or a matching verdict. The current compact private report is `build/rebuild/link-inventory-compact-v2.json`; the earlier detailed report was a separate development artifact.

| Evidence | Count |
|---|---:|
| Relocations | 814,858 |
| External definition occurrences (including compiler-generated entities) | 180,206 |
| Weak external occurrences | 3,068 |
| Duplicate global names | 11,727 |
| Multiple strong-definition names | 4,495 |
| COMDAT no-duplicates conflict names | 1,213 |
| COMDAT policy-review names | 6,019 |
| Duplicate names with more than one normalized original-address mapping | 35 |
| Undefined names absent from retained external definitions | 174,649 |
| Of these, import-pointer names | 288 |

These are all reference recipe variants together, before a runtime selection. The duplicate categories are not 11,727 independently proven source defects, and the unresolved count is not a missing-source count. The inventory preserves 113 `/alternatename` directives without resolving them. Many separately named TU views may map to a provider at the same original address but require independent ABI/type evidence before runtime aliasing. The 35 multi-address duplicate names include functions, vtables, RTTI and literals; they are not the recipe audit's narrower 19-function collision set.

Real collision evidence includes `BloodSplatterBeamShader::CreateShader` from `beamshader.cpp` and `debugshader.cpp`, both COMDAT `no_duplicates`, mapped to distinct original addresses `0x00bc4af0` and `0x00bd23f0`. Real repeated-storage evidence includes 13 definitions of `g_tlsBlock`. Neither may be resolved by silently choosing the first object or forcing duplicate symbols through the linker.

Prioritize compatible CRT/startup providers (`__security_check_cookie`, `type_info`, security cookie, `atexit`, C++ EH), verified imports, TLS storage/layout, global initialization and address/ABI reconciliation of separately named methods/data. All 2,988 objects request `LIBCMT` and `OLDNAMES`; 350 also request `uuid.lib` and 31 request `libcpmt`. Identical library directive text across compiler variants does not prove the versions are compatible. A subsequent explicit runtime link plan must resolve that choice without changing the reference oracle.

The compact full run reproduced the detailed duplicate/unresolved counts in 8.719 seconds, producing a 200,862-byte report with a measured peak process working set of 662,851,584 bytes on the development machine. The earlier full JSON was approximately 1.37 GB. These measurements include Python, recipes and global name indexes; they are observations, not universal performance guarantees. The [canonical address plan](CANONICAL-PLAN.md) reparses the retained objects independently and explains how many differently named uses have address-provider candidates.

## Parser limits and validation

The reader supports standard little-endian i386 COFF, long names, symbol auxiliary records, ordinary and extended relocation counts, section COMDAT metadata and weak externals. It bounds-checks reads and rejects truncated tables, invalid string offsets, malformed overflow markers, invalid section indices and relocation/weak targets that point at auxiliary or absent symbol entries. PE files, archives, bigobj, non-i386 inputs and optional-header objects are rejected explicitly. Unknown relocation numbers remain visible; they are not silently treated as supported linker operations.

This is not a linker: it does not parse archive/import-library member formats, resolve library search order or directives, apply relocations, resolve associative COMDAT liveness, validate TLS layout, evaluate initializer ordering, select an entry point, or prove a playable runtime. Payload hashes and section checksums are evidence only; section bytes are never emitted in reports. No disassembly, inline assembly, game bytes, guessed data definitions or linker conflict overrides are added.

Run the original synthetic fixtures independently of any proprietary tools:

```powershell
python -m unittest discover -s tests/rebuild -p test_coff_inventory.py -v
```

The fixtures cover local label scoping, strong duplicates, defined aliases, COMDAT/association auxiliary handling, weak fallback/common/absolute storage, imports, data-origin relocations, invalid auxiliary targets, bounds and machine rejection, overflow relocation markers, ambiguous original addresses, hash binding, manifest-relative roots, partial/full selection behavior and evidence overwrite protection.
