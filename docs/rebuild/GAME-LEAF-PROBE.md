# First source-built game leaf probe

One existing source-built game function has executed successfully in a newly linked private x86 probe using an original typed C++ fixture. This proves a narrow machine-ABI/linking mechanism; it does **not** establish a working game, complete game class layout, real subsystem initialization or game runtime closure.

## Selected body and caller

The selected recipe is `0000-674cf48524ad6cf3` (`src/NiRenderedTexture.cpp`). Its function `?FUN_00be0b90@FnvCpu_FUN_00be0b90_CpuObject@@QAEHXZ` at reference `0x00be0b90` is an x86 thiscall `int` member returning a field at offset `0x30`. The source view declares twelve preceding unsigned fields and an int value. Native section 13 is a four-byte `no_duplicates` COMDAT with zero runtime relocations; its only associated child is debug-only `.debug$F`, with a self-reference. There are no game globals, vtables, callbacks or EH dependencies in this leaf's reviewed runtime closure.

The original fixture `runtime/probes/game_leaf_probe.cpp` declares a separate `GameLeafFixture` with twelve fixture words and an int at the reviewed offset, with compile-time assertions for offset and int width. Its `ReadValue()` method is declared but not implemented in fixture source. The retained function's copied definition is renamed to that method's exact decorated identity, preserving thiscall, argument and return ABI. Calls use the ordinary compiler-generated member-call ABI; there are no function-address casts, assembly, fixed executable addresses or forwarders into the original game.

The fixture supplies only its own ordinary object storage. The preceding words and total fixture shape are a test arrangement, not a claim about the complete production game's class. Seven signed field values, including zero, negative values and both signed int limits, are read repeatedly through the real linked source-built body.

## Preserved first failure

The initially authorized direct whole-object link used the copied/renamed full recipe object, genuine VC9 CRT, `/OPT:REF` and `/OPT:NOICF`. It failed with **LNK1120: 11 unresolved externals** from unrelated object members despite the isolated leaf having no runtime relocations. No stubs, `/FORCE`, guessed data or additional providers were added. No failed-link output was executed. Private failure artifacts remain under `build/rebuild/game-leaf-probe/`, including the original link receipt/log and a separate hash-bound `closure-blockers.json` review.

The blockers' original bindings are:

| Dependency from other member | Reference binding |
|---|---|
| `NiRenderedTexture::ms_bUseMipMaps` | `0x011ab3c4` |
| `NiRenderedTexture::ms_eDepthStencilFormat` | `0x011ab3c8` |
| `NiRenderedTexture::ms_bUseDepthBuffer` | `0x011f4ac0` |
| `Ni2DBuffer::Create` | `0x00a8f260` |
| `NiRenderedTexture` constructor | `0x00a7fb80` |
| `NiMemObject::operator new` | `0x00aa13e0` |
| `__Dummy_00b6fef0` | `0x00aa1460` |
| `DestroyFogProperty` | `0x00a5c240` |
| `FUN_00a5f800` | `0x00a5f800` |
| `DAT_0109b944` | `0x0109b944` |
| `g_012708e4_arg1` | `0x011f4ac4` |

These are link dependencies, not a determination that their source bodies or data are absent. The failure justified a separately authorized narrow selection mechanism rather than fabricating those providers.

## Extracted link and execution

After authorization, the [zero-relocation extractor](COFF-EXTRACT.md) selected the proven function, explicitly recorded debug/unselected COMDAT drops and retained understood CRT directives. The [definition renamer](COFF-REWRITE.md) changed only its identity. An unchanged-core comparison of the extracted/renamed body against the SHA-bound owned image returned **match: four bytes, zero relocations, zero differences**. The final retained v3 receipt supplies the original object and exact selected/native-function proof; aggregate source-compilation success alone was not used as that attestation.

The new private probe linked normally with the genuine static CRT. Independent review confirmed only `ReadValue` from the selected game object in the public map, the original fixture's `main`, ordinary CRT initialization, no game XCU/TLS initializers, and only `KERNEL32.dll` imports. The linked leaf payload hash equals the retained leaf payload hash. The reviewed map hash is `071f5d2186102cc8ecd220959d0fdaca49d575b1fb459d3ea1e7134bedba3890`; the new executable hash is `8ed476eee518854a6e2d1bbfee21409e5533b65a703cf1c3503ef55193c0577c`.

Only after that independent review and root authorization was the new executable launched. It returned zero with `cases=7`, `calls=7168`, `checks_ok=1`. The execution receipt binds the reviewed map, executable and link receipt. No game executable, assets, Steam process, UI or network activity was used by this fixture. Original retained objects and source/oracle inputs remain unchanged.

Private evidence is under `build/rebuild/game-leaf-probe-extracted/`: retained verification reference, extraction/drop ledger, identity-rename receipt, selected/renamed objects, compiler/link logs, map/import inspection, link receipt and execution receipt. These artifacts remain private. The source-only tools/probe and this metadata document contain no game binary payload or disassembly.

## Reproduction and next limit

`tools/rebuild/game_leaf_probe.py` first validates the SHA-pinned retained receipt and actual per-function native entry, source/object observations, full input object's initializer/TLS/directive profile and selected closure. Default preparation reproduces the whole-object attempt. The explicit `--extract-reviewed-leaf` option additionally requires the same private comparison image, invokes the narrow extractor/renamer, runs the unchanged four-byte check and links. It does not execute automatically. Execution of an existing successful probe requires an explicitly independently reviewed map hash through `--reviewed-map-sha256`; hashes of the executable, map, objects, imports and fixture source must still match.

Eight synthetic tests exercise object/initializer audits, changed spans, map rejection of extra game providers, explicit unresolved reporting, per-function-proof requirements, receipt/hash checks and rejection of execution without a successful reviewed link. Full retained verification and native execution are separate evidence from those synthetic tests.

This slice demonstrates that an actual retained source-built method can be safely selected, renamed, linked at a new address and called through its reviewed ABI. More complex functions need explicit relocation, data, EH and initialization closure work. No broader extraction, runtime-provider approval, application startup or playability conclusion follows from this result.
