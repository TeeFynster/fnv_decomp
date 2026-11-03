# One-definition COFF rename

`tools/rebuild/coff_rewrite.py` implements only an explicit external-definition name change in a copied standard i386 COFF object. It performs no alias/provider selection, section extraction, IAT mapping, signature conversion, linking or runtime execution. Keep original objects and the reference recipe unchanged. Outputs, receipts and private proof inputs belong in ignored private build output.

## Contract and invocation

Supply `--input`, `--output`, `--receipt`, `--provenance`, `--expected-sha256`, `--old-name` and `--new-name`. The expected hash must identify the exact input object. Input/output/receipt/provenance paths must differ; outputs must not exist and must not overwrite the declared source. Symbol names must be printable ASCII without spaces. The old spelling must occur exactly once as a section-defined external; the new spelling must not collide with any existing symbol. Import-pointer spellings are rejected.

The required provenance JSON has this shape (use actual values rather than these labels):

```json
{
  "schema_version": 1,
  "kind": "fnv-coff-rename-provenance",
  "recipe_id": "explicit recipe identity",
  "object_sha256": "64 lowercase hexadecimal characters",
  "source": "path to the source file",
  "source_sha256": "64 lowercase hexadecimal characters"
}
```

A relative source path resolves against the provenance file's parent. The tool independently checks object and source hashes and records the provenance-file hash. The recipe/source association is **caller-declared**; these checks do not independently prove the compiler produced that object from that source. For retained-recipe work, additionally cross-check the declaration against the immutable builder manifest, recipe identity and compile receipt, as done for the demonstration below. A standalone self-authored provenance file is not a replacement for those records.

The writer appends one NUL-terminated name to the existing string table, updates its four-byte length and updates only the selected symbol's eight-byte Name field. All existing symbol indices remain stable. Every other original byte must remain identical, including section payloads, relocation records/addends, auxiliary records, directives and COMDAT association records. The receipt records both hashes, selected symbol index/section/value/type, exact edit locations and preservation checks. A separate inventory parser reparses the staged output before publication.

The supported subset excludes bigobj/PE/archive inputs, extended relocation tables, trailing overlays, overlapping records, unsupported or malformed auxiliary layouts, invalid associative targets, and out-of-bounds/unknown relocations. Standard section auxiliary records, weak extern records with supported search policies, and FILE filename records are retained. Existing weak references keep their fallback **indices**; their displayed fallback spelling naturally follows a renamed target. No weak alias is created. The tool deliberately rejects other valid-but-unsupported auxiliary forms instead of guessing.

Outputs are staged privately, verified, then created exclusively. On a later publication/receipt failure, the tool removes only the object/receipt it created, and cleans its own staging file. This prevents a failed operation from leaving a named unreceipted object during ordinary exception handling. Two separate filesystem files cannot be published atomically across a process/power failure: consumers must require a valid receipt whose output hash matches before using an object. Existing paths are never overwritten.

## Actual retained-object demonstration

The owner-authorized proof used the hash-checked retained recipe `2734-15835374a1b91660`, source unit `src/staging/blk_00aa0000_o2.cpp`, input object SHA-256 `10c9d726dbf44ac2258f10eecf1f3bbbeef95df9759de18d585756873643c1c1`. The source/object provenance was cross-checked against the retained builder row; the tool also checked the declared source hash independently.

Only external symbol index 141 changed: `?FUN_00aa13e0@@YAXH@Z` became `_fnv_code_00aa13e0`. Its section remains 41, offset zero, type 32, storage class 2. The object output SHA-256 is `086a25fcd9700ca5531c08e4bb658952d9e10a2737bfdf701a437ef9fee34609`. No original input was modified and no other object was rewritten.

The allocator function remains a 62-byte `no_duplicates` COMDAT with one DIR32 relocation to `_DAT_011f6080` and its existing associative debug section. Independent reparse confirmed preserved structure. With a private copy of **only that function's metadata** naming the new definition and retaining original bindings, unchanged `tools/compare.py::compare` returned **match: 62 bytes, one relocation, zero differences** against the same owned reference image. All 16 existing image fingerprint probes passed. No matching tool, authoritative recipe, source prototype or original image changed. This is a narrow retained-object identity proof; the separately reported full baseline oracle remains a distinct result.

Private artifacts are under the task-owned `build/rebuild/coff-rename-proof/` directory, including the original demonstration and `verified-v2/` staged-publication verification. They contain objects and must remain private. This document includes only source identifiers and safe metadata, not binary payloads or personal input paths.

## Validation and next boundary

`python -m unittest discover -s tests/rebuild -p test_coff_rewrite.py -v` exercises original synthetic COFF fixtures. Nine tests cover preservation, long/short names, weak-index retention, wrong object/source hashes, collisions and nondefinitions, path/overwrite protection, import-pointer rejection, malformed/unsupported layouts, and receipt-failure cleanup. Independent validation should confirm these results before expanding scope.

The next possible runtime slice is **not implemented or authorized by this tool**: select the proven allocator code section and its verified closure, rename its code identity, and link it to an original typed C++ test fixture. The fixture would provide an ordinary C++ allocator object with a compiler-generated virtual table and a typed holder referenced through the sole data dependency. Its virtual allocation method would record seven arguments and return an ordinary fixture-owned allocation. Test size-zero normalization, nonzero size, returned pointer bits, arguments and repeated calls/stack balance. It must use fixture-defined types and ownership, not fabricated production game layouts or arbitrary address-backed data.

Before selection, independently verify every section relocation, associative COMDAT edge, potential EH/unwind/helper dependency, and any symbol-index metadata from the selected section. The currently observed dependency is one data-pointer reference plus virtual callback slot `+4`; the callback contract needs a reviewed x86 `thiscall` signature (size/alignment references, allocation type, accuracy flag, file, line and function, pointer return) and a fixture that proves those observations. Do not assume the entire source unit's EH and initializer material belongs to this one function, or discard it by name alone.

Such a fixture would show that this source-built machine-code body preserves the reviewed allocator ABI when linked under a new identity. It would establish neither the real game's allocator/data/bootstrap closure nor application startup, assets, menu or gameplay. Production manager storage and initialization remain unresolved here. The earlier [startup closure](STARTUP-CLOSURE.md) documents the return-register and consumer evidence that motivates this bounded experiment.
