# Partial application link inputs

This separate Python-only assembler combines the actual compiled WinMain host,
actual source-built application-entry archive, two accepted DATA objects and
four native import libraries into a new private directory. It does not produce
or invoke an executable. The source checkpoint awaits independent review and
separate root authorization before an actual assembly operation.

`tools/rebuild/application_link_inputs.py` pins the exact accepted component
receipts and artifacts by SHA-256, including the host compile receipt
`5e8e9407f5c1ba995193a62d838c819d3261adfa681ffee08f2106d8c7dafde4`,
entry projection receipt
`b46ffd72903c4363f545884d3dbb5cbb3bcf355d1ef8e84171c8fae1861eeb6b`,
DATA receipt `b1a6554ad8170f06f7367a21d5b6ecd6b8b6c910e3fa3241ef8a3bde039db792`
and native import collection
`4e75e3a126b459914e6b6d9946a7d3154e8114860a8317496975ea67600f244b`.
These identities select inputs, not runtime providers. Independent native
conformance and source ABI decisions remain separate evidence owned by the
component reviewers. The original receipts are not edited or promoted.

## One actual host edge

The existing immutable `coff_code_archive.namespace` helper changes the host's
single physical undefined `_fnv_game_application_entry@16` to the actual entry's
sole canonical export. The helper is itself pinned. Source typing remains the
four-dword x86 stdcall call from the reviewed WinMain source; no ABI conversion,
forwarding function or cdecl declaration is introduced. Independent COFF parsing
requires one GUI definition, one typed undefined function, one REL32 call and
no other host references. After the name transform every section, relocation,
symbol property and auxiliary record must equal the input except that name.
The original compiled host and application-entry objects remain untouched.

## Concrete partial namespace

The assembler recovers the actual entry archive through both checked indices
and requires its only member to equal the accepted entry object. Every one of
the entry's 442 actual fields is joined through the saved physical-to-serialized
symbol/section maps to its original obligation. Both distinct undefined records
for one canonical CODE name remain distinct; no relocation is retargeted.

Sixteen DATA definitions must join their exact object hash, physical index,
section/value and accepted namespace records. Their twenty entry fields must
retain the accepted physical symbol, DIR32, zero addend and original-base
identity. This is address-only storage coverage, not an approved object layout,
type, lifetime or resource provider. Remaining CODE, DATA, CRT and IAT field
lists stay explicit in the manifest.

Both native indices of each import archive are independently parsed. Every
ordinary support member is inspected, and each short import must have the exact
x86 code-import/name-type encoding, named export, DLL and two public names in
its actual index. The twenty-five canonical IAT-to-native pointer proposals
must join accepted actual DLL/export identities and all thirty actual entry
fields. A pointer cannot be replaced by the imported code symbol. Proposals
remain unapplied; ABI and provider adoption remain false.

Selected host/entry/DATA definitions and public import-code/pointer candidates
cannot collide. Lazy import-descriptor and null-thunk support definitions are
reported with physical member provenance. In particular, the four archives'
`__NULL_IMPORT_DESCRIPTOR` candidates remain separate, unselected library
members. They are ordinary lazy archive candidates, not four selected storage
providers. The manifest records their duplicate names and leaves extraction
to a future actual normal link. It performs no support-member coalescing and
does not use `/FORCE` or hide selected-provider conflicts.

## Output and remaining link work

After source review and root go:

```powershell
python tools/rebuild/application_link_inputs.py --source-sha256 <reviewed-assembler-hash> --out <new-private-directory>
```

The destination must be new and private; within this checkout it must lie under
ignored `build/rebuild`. The output contains the renamed host, unchanged entry
archive and evidence member, unchanged DATA objects, unchanged four import
libraries and a hash-bound manifest. Inputs, implementation dependencies and
written components are checked again before manifest publication. The exact
reviewed test/document and imported namespace, COFF-reader and startup-contract
module hashes are pinned before assembly; the assembler's own reviewed hash is
supplied explicitly to avoid a self-referential hash. Every source/dependency
identity is rechecked before creating output and before manifest publication.
No private
input path or code payload is printed in the summary. A failure during writing
can leave private partial files; preserve them and use a fresh directory after
reconciliation rather than replaying into that directory.

The manifest includes a concrete eventual x86 GUI LINK argument plan using
those filenames and normal CRT defaults. It contains no `/ENTRY`, fixed-address
fallback, fake provider or CRT stub. The executable command remains unready:
the exact linker/library search closure, remaining transitive CODE/DATA/CRT
providers, actual IAT bindings and source signatures, initializer ordering,
fresh CRT state, game TLS, resources and shutdown contracts are unresolved.
One resolved host edge and twenty DATA fields do not establish a game link,
launch, menu, gameplay or save/load milestone.

Focused tests use original synthetic COFF/archive metadata only. They cover
typed host binding and name-only preservation, duplicate selected definitions,
weak/common rejection, both native indices and pointer identities, physical
field mapping, exact DATA alias coverage and private/stale-input rejection.

The first authorized actual assembly stopped before creating its output
directory: the accepted collection preserves first-index/member row order,
while the new reader reports the second index's lexical order. The import
headers, member counts, hashes and symbol/member pairs agreed. No artifact was
published and no native tool ran. Private `application-link-inputs-v1` preserves
an error receipt with SHA-256
`b771f53fe61f52bc91f7f34c07f89023e51b179d9d3fca5df52a4beef1f4edc8`.

The narrow corrected comparison sorts the exact symbol/physical-member pairs
without deduplicating; missing, repeated or moved records still fail. Both raw
native index orders and the accepted collection order are preserved in the
manifest. Component bytes and identities remain unchanged. Independent delta
acceptance and a separate root go are required before one attempt in a new
private directory; the failed directory and receipt remain intact.
