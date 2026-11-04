# Persistent data strategy

Read-only investigation at reference baseline `87eb937`, November 2, 2026.
This document proposes a private data reconstruction experiment. No data
extractor, storage provider or game runtime is implemented here. Read the
[runtime audit](RUNTIME-AUDIT.md), [startup closure](STARTUP-CLOSURE.md) and
[COFF inventory](LINK-INVENTORY.md) alongside it. The canonical ownership plan
must supply approved providers before any automatic fixups are permitted.

## Decision

Use existing source definitions where their complete layout and lifetime are
proved. For remaining data, investigate **private, interval-based storage derived
from the owner's original on-disk non-executable data**, with explicit pointer
fixups to source-built code and new runtime providers. This is a plausible way to
preserve unnamed constants, tables and address-interior relationships without
inventing thousands of zero arrays. It is not yet safe to materialize all data.

Copying complete PE data sections and replaying base relocations is insufficient.
Base relocation adjusts a location for one image-base change; a rebuilt program
can move each function and data interval independently. Every retained pointer
needs an approved target identity, appropriate offset and lifetime. Imports,
CRT state, static TLS and constructors require fresh runtime ownership. No
pointer may keep execution in the original executable, its packaging section or
an unowned original address.

## What the bounded checks establish

The existing full oracle passed all reference units; that proves their code and
reference relocation comparisons, not complete persistent data. This investigation
read PE headers/directories, relocation records and selected data, inspected three
known retained objects/source owners, and compared non-executable section hashes.
It wrote no image bytes, disassembly or copied data artifacts and did not launch
or modify the game.

The sibling workspace's `scripts/capture-runtime-image.py` starts with the owned
on-disk file and replaces only its `.text` range from a normally running module
at the preferred base. That is creator-code evidence, not a historical receipt
proving a particular invocation. More directly, the currently selected private
reference and the currently owned installed executable have identical section
metadata and SHA-256-equal raw contents for all six non-executable sections:
`.rdata`, `.data`, `.tls`, `CONST`, `.rsrc` and `.reloc`. Executable section
payloads were excluded from this comparison. Thus these raw data ranges currently
agree with the owner's on-disk file; they are not evidence of a captured,
post-constructor writable-memory image. This does not prove that every range is
plaintext, typed correctly or already suitable for a fresh runtime.

| PE storage evidence | Observation | Consequence |
|---|---:|---|
| `.rdata` | Virtual size 1,716,300; raw size 1,716,736; read-only | Raw alignment padding is not an object-size catalogue. |
| `.data` | Virtual size 977,564; raw size 262,656; writable | 714,908 bytes of virtual extent have no raw file payload. |
| `.tls` | Section virtual size 709; raw size 1,024 | The directory's 708-byte template, not either section size, defines the audited initialized template. |
| `CONST` | Writable section despite its name | Names cannot decide mutability or protection. |
| `.text`, `.bind` | Executable sections; `.bind` remains present | Exclude from general data copying; no wrapper or protected-code reconstruction. |

The PE defines file-backed and virtual extents separately, and base relocation
records describe loader adjustments. These are format facts, not object type or
lifetime information. See Microsoft's [PE format specification](https://learn.microsoft.com/en-us/windows/win32/debug/pe-format).

The relocation directory contains 351,931 x86 HIGHLOW entries and 1,717 padding
entries. Of those fixup sites, 135,996 lie in `.rdata` and 14,169 in `.data`.
Selected destination classifications, derived from those data-site words, are:

| Source | Into `.text` | Into `.rdata` | Into `.data` | Into `.tls` |
|---|---:|---:|---:|---:|
| `.rdata` | 98,619 | 29,615 | 7,760 | 2 |
| `.data` | 2,830 | 9,846 | 1,493 | 0 |

Among `.rdata` targets into `.text`, 84,331 identify listed ordinary function
entries, 228 fall inside listed ordinary function spans, and 14,060 fall outside
those spans. Corresponding `.data` counts are 2,691 entries and 139 outside.
These are pointer-site counts, not distinct functions or missing-code counts.
Uncovered spans may include EH, CRT, generated helpers or other material. They
must be reconciled with the canonical plan and the oracle's inferred EH bindings;
they cannot be approved by assigning the nearest function. Interior code targets
need a proved retained section/offset and valid control-flow contract.

## Source definitions: useful providers and a concrete storage failure

Three bounded narrow-string definitions in the native `main.cpp` object matched
their bound private-image data exactly, with lengths 7, 5 and 30 bytes. These are
already source-built providers; private extraction is unnecessary for them.
Pooled copies may have distinct original addresses, so identity and address
aliasing still need explicit decisions.

The generated global-initializer header is not a reliable layout header:

- `GlobalObject_0040c150` has `char storage[4]`. The generated native object
  defines `g_011c3264` in `.bss`. Its real constructor at `0x0040c150` is in
  `src/unmapped/setting.cpp`; it calls the base constructor at `0x00404920`.
  That base's source in
  `src/fallout_shared/pathfinding/navmeshpovsearch.cpp` writes fields at offsets
  +4 and +8, and the derived constructor writes the vptr at +0. At least twelve
  bytes are accessed. The four-byte generated allocation therefore cannot be
  accepted as its complete runtime storage.
- `g_011c32f0` uses a different generated four-byte placeholder, but its actual
  constructor at `0x00a2e180` uses an empty class declaration and changes a separate
  global reference count. Increasing every placeholder to twelve bytes would
  manufacture a different, equally unsupported layout.
- `g_011dee84` is a generated object and a `NiPointer<NiNode>` view elsewhere.
  Its constructor at `0x00633c90` stores a pointer and conditionally increments
  a reference. The matching four-byte use is supporting evidence for this slice,
  not validation of the entire placeholder family.

The first two globals, `g_011dee84`, the memory-manager global at `0x011f6238`
and TLS-index cell at `0x0126fd98` are not raw-backed even for a four-byte read in
the selected PE. They lie in virtual storage, not in a missing extraction file.
The source-built generated `.bss` layout is a separate allocation from the
original PE's address intervals; matching initializer instructions did not prove
those allocations interchangeable.

## Proposed representation and ownership

The proposed unit is a reviewed **storage interval**, not a symbol spelling and
not an entire section selected by name. A private ledger should contain original
interval/start/extent, alignment, provenance hash, initialized versus zero-fill
extent, mutability, typed source views, owner/lifetime, all aliases, approved
interior targets, and the new object/section provider. Every fixup needs its site,
width, representation, old target identity/addend, new provider and review proof.
Reject conflicting/overlapping owners; preserve intentional shared storage.

An authoritative PE-sized arena could preserve offsets among proved data
intervals, including genuine zero-fill, while COFF symbols expose reviewed typed
views into it. That zero-fill derives from image storage extent, not guessed
array sizes. It must never silently coexist with a second generated `.bss`
allocation for the same original object. Replacing or suppressing an existing
definition requires a separately reviewed object transformation and ownership
contract. First use smaller, fully bounded intervals; whole arenas remain
conditional on complete classification.

Choose source-defined constants, real globals, vtables and RTTI when the emitted
layout and semantics are proved. Private raw data is a fallback for verified
initial bytes, not a replacement for missing type/lifetime evidence. Preserve
virtual-table slot ordering, negative metadata slots, RTTI relationships,
multiple-inheritance adjustments and deleting-destructor conventions. Every code
slot must resolve to a source-built provider or an explicitly selected runtime;
an unclassified thunk or original code pointer blocks that table.

Mixed content remains a hard classification problem. Executable flags do not
prove every byte is an instruction, and read-only data includes function pointers
and metadata. A complete code/data partition has not been established. Do not
copy executable sections as data, promote a jump table by guessing its extent,
or assume `.rdata` consists only of constants.

## Fixups and fresh process state

The following are design obligations inferred from the observed graph, not
implemented relocation support:

- **Pointer identity and interiors:** translate `old object + offset` through
  an approved interval mapping. Bounds, one-past pointers and tagged pointers
  require their own contracts. A single old-to-new image delta works only for a
  layout preserved uniformly, which is not proved here. Never scan arbitrary
  integer words and patch values merely because they resemble addresses.
- **Representations absent from base relocations:** RVAs, relative offsets,
  table indices, serialized IDs, runtime-computed pointers and encoded values
  are not a complete semantic pointer inventory in that directory. Describe
  their format explicitly. Retain COFF DIR32/DIR32NB/REL32/SECREL evidence and
  source uses rather than treating every field as an absolute pointer.
- **Imports and CRT:** create new import descriptors/IAT cells and use the
  selected CRT's own tables, cookie, locks, exit state and startup. Discard no
  unresolved field by substituting a copied DLL address, heap pointer, handle,
  old IAT value or old CRT object. Preserve IAT-pointer indirection demonstrated
  in the [startup closure](STARTUP-CLOSURE.md).
- **Static TLS:** construct one canonical template, new loader-managed index
  cell, directory and required callbacks. Keep field aliases at proved template
  offsets; do not copy the old process's TLS index or one thread's live block.
  Keep the separate Havok dynamic TLS slot distinct. Windows supports per-thread
  storage, not one shared mutable template instance; see Microsoft's
  [TLS documentation](https://learn.microsoft.com/en-us/cpp/parallel/thread-local-storage-tls?view=msvc-170).
- **Construction and destruction:** materialize pre-constructor storage, then
  execute the selected initializer graph once through the new CRT, with paired
  termination. Do not seed constructor-completed bytes and run constructors
  again. `.CRT$XCU` retention and ordering are separate from source-file order;
  see Microsoft's [CRT initialization documentation](https://learn.microsoft.com/en-us/cpp/c-runtime-library/crt-initialization?view=msvc-170).
- **Assets/resources:** keep owned external assets as owned inputs. Embedded
  resources need a private, format-aware resource decision; they are not C++
  globals. Do not copy the packaged PE's entry point, certificate, binding wrapper
  or loader directories into the new executable.
- **Protection and ASLR:** the observed image lacks DYNAMIC_BASE, but this does
  not prove new addresses equal old ones. Test changed bases/layouts. Plan page
  boundaries so final constant data is read-only and mutable storage writable;
  do not make arenas executable. Page protections operate at page granularity,
  as documented under [working with pages](https://learn.microsoft.com/en-us/windows/win32/memory/working-with-pages).

## Bounded next experiment and acceptance gate

First implement an entirely original, small data fixture after explicit task
assignment. Compile it with the already proved native toolchain and new CRT;
include a twelve-byte structured global, initialized and zero-fill fields,
constant data, an interior pointer and two aliases, a callback, a small virtual
class/RTTI case, an import-pointer use, one constructor/destructor pair and static
TLS exercised by two threads. Use a second source-built layout with moved code
and data, and test a changed load base. Include an explicitly described RVA or
relative-offset field so a HIGHLOW-only implementation cannot pass accidentally.

The future experiment should materialize only this fixture's selected data,
using an authored identity ledger, and prove: exact pre-constructor values and
extents; one canonical shared allocation; correct interior aliases and new-code
callback dispatch; proper imports; constructor/destructor counts; independent
TLS initialization; unchanged source objects; and final protection boundaries.
Deliberately reject a four-byte substitute for the twelve-byte owner, unknown
code target, unclassified interior pointer, stale live-process pointer, omitted
TLS ownership and missing pointer-format metadata. Compare behavior across both
layouts and bases. This fixture is planned, not executed by this investigation.

Only after that passes should a private game-data pilot be considered: the
already verified source literals first, then one proved zero-initialized object
and constructor closure. The setting object requires a reviewed full layout;
the memory manager requires its real heap/bootstrap graph. Neither is permission
to call into an unresolved game entry point.

Whole-data materialization remains blocked until every retained interval and
pointer representation has provenance, canonical ownership and a complete target
closure. A source-built private executable can use owned assets and privately
derived data, but a reusable public tool must contain only generic logic and
original fixtures: no game bytes, personal paths, copied image or assumed process
addresses. This investigation establishes a practical direction and specific
rejection gates, not a recovered static initial state or a playable result.
