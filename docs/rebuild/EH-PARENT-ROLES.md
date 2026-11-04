# Fixed-scope EH parent/state-role evidence

Implementation status: the source/schema passed independent review and all
fourteen focused synthetic tests passed. Root then authorized the fixed two-object
read-only observation, which completed and passed independent output
reconciliation within the review scope below. No frame contract, type repair or
provider has been approved.
No compilation, linking, native process execution, extraction, object rewrite or
provider adoption belongs to this tool.

The producer is deliberately restricted to recipe 802 constructor `0x0043fd40`
and recipe 2761 destructor `0x00bd6570`. It preserves the final
[diagnostic triage](EH-DIAGNOSTIC-TRIAGE.md) and existing EH tools. The first parent
contains the two exact `SubObjB` cleanup roles whose same source spelling leads
to two distinct original destinations. The second is the negative example in
which one native `ObjectReference` helper section has conflicting original
placements. Neither is a new canonical runtime component.

## Inputs and trust boundary

`tools/rebuild/eh_parent_roles.py` pins the exact retained manifest, authoritative
recipe, v3 receipt and original oracle identities already recorded in the triage.
The receipt binds the exact owned reference-image hash and original comparison
producer hashes. All current producer hashes must agree. Current source/object
observations are rehashed for just the two exact manifest-selected units; no
archive search or complete object inventory occurs. The optional function-index
presence/hash must agree with the receipt. All observed files are checked again
before exclusive creation of the new metadata output.

The tool imports the original matching implementation unchanged. It performs a
fresh bounded ordinary comparison of the two selected parents and replays the
original `eh_sections` on the two units, requiring its complete returned piece
arrays, ordered diagnostics and inferred mappings to equal v3. A trace hook
observes only the hash-pinned original relocation-resolution branch. It cannot
silently reinterpret the original verdict. An existing Python tracing session
rejects rather than being replaced. No inferred name from a failed piece is
turned into a provider.

The ordinary comparison uses the unchanged baseline's absent optional-index
policy, with explicit original recipe symbol/function bindings and just the
selected ordinary function as its comparison root. It reports counts and
relocation targets, never raw byte differences. A reference MATCH still does
not establish correct source type identity or complete compiler causality.
Source hashes are current observations and do not reconstruct transitive header
or historical compilation provenance.

## Schema 1

The top-level kind is `fnv-two-parent-eh-role-observations`, policy
`two-parent-state-role-evidence-v1`, status `analysis-only`. Runtime eligibility,
provider selection and each component's frame-contract verification remain
false. The receipt records manifest/recipe/v3/image hashes, all implementation
and imported-producer hashes, exact source/object hashes, two components and
aggregate role/failed-role counts. It contains no original payloads, disassembly,
raw difference records or personal input paths.

Each component retains:

- The exact same-object parent proof and fresh ordinary comparison, including
  all original relocation expected/observed targets and verdicts.
- Every selected parent-owned local code piece, original/native interval,
  receipt verdict, actual physical association chain, exact local symbols,
  non-relocation comparison counts and each original relocation result.
- The local handler and FuncInfo anchors, metadata association, complete
  non-relocation table comparison and each metadata pointer comparison.
- All FuncInfo/unwind-map states and transitions: state, predecessor state,
  original predecessor, local action symbol/offset, original pointer field,
  exact original cleanup and role identity.
- Per-role own-unit binding, global-name binding, original expected/resolved
  destination, whether inference was involved and the preserved failed verdict.
  A role ID includes parent, state and local cleanup offset; same symbol or
  same destination never merges roles.
- The exact source member declaration observations and their source lines.
  These declarations are not assigned to native cleanup roles without proof.

Only EH3 FuncInfo with a complete bounded unwind map and no try/IP/exception-spec
subtables is supported. A changed version, unmodeled field or relocation,
missing/invalid transition, foreign-parent cleanup, stale association, missing
piece or conflicting handler/table pointer rejects. This scope limit does not
imply other EH formats are invalid; they require another reviewed parser.

The only instruction observation recognizes an entire, bounded local cleanup
form which loads ECX from one EBP slot, optionally adjusts ECX, and tail-jumps
through its single REL32 reference. It reports semantic slot/adjustment values
or `unknown-shape`. It never scans for a convenient byte subsequence or decodes
arbitrary surrounding code. Even a recognized local form leaves the parent's
saved-this origin, source member role and whole frame contract unverified.
No nearest-address or source-field-name inference fills those unknowns.

## Commands after independent approval

Use exact known private input paths and a new ignored output path:

```text
python tools/rebuild/eh_parent_roles.py --manifest <retained-manifest> --retained <v3-receipt> --recipes build/units.json --image <owned-reference> --out <new-private-role-report.json>
```

The caller cannot widen the unit/address scope or re-attest a replacement v3
receipt by supplying a new hash. Existing outputs and input aliases reject.
Output publication uses exclusive creation; a failed write removes only the new
partial file created by that invocation.

```text
python -m unittest discover -s tests/rebuild -p test_eh_parent_roles.py -v
```

The fourteen tests use authored metadata containers and instruction-pattern
fixtures, never an original image or compiler. They exercise complete states,
missing transitions, cross-parent actions, stale associations, duplicate/merged
role identities and actions, duplicate metadata relocations, final producer/index
stability, silently promoted failed pieces, provider/frame
promotion, cyclic states, unknown metadata, wrong original pointers, stale input
hashes, output protection, non-relocation mismatches and unknown frame shapes.
They establish the proposed policy checks, not native observation results.

## Measured read-only observation

Private `build/rebuild/eh-parent-roles-v1.json` is 54,554 bytes, SHA-256
`1e08ae8a908dc0a9d7feba4e5fa3cbcfe3a5f9ed6be3004ed6ac8639497fd788`.
It reports **two parents, seven state roles, nine local code pieces and five
failed roles**, all retained as analysis-only. Both fresh ordinary-parent checks
match. Both complete metadata blocks have zero non-relocation differences and
all nine metadata relocations agree. Producer hashes, reference/object/source
identities and absent-index state remained stable.

| Parent | State -> predecessor | Local cleanup offset | Local ECX adjustment | Original action destination | Piece comparison |
|---|---|---:|---:|---|---|
| `0x0043fd40` | 0 -> -1 | 0 | 0 | `0x00c3c620` | Match; original oracle inferred the external base-destructor name, not its body. |
| `0x0043fd40` | 1 -> 0 | 8 | `0x2c` | `0x0044cbf0` | Failed target binding; non-relocation content matches. |
| `0x0043fd40` | 2 -> 1 | 19 | `0x30` | `0x0040c110` | Failed `SubObjB` binding; non-relocation content matches. |
| `0x0043fd40` | 3 -> 2 | 30 | `0x34` | `0x0045cec0` | Failed `SubObjB` binding; non-relocation content matches. |
| `0x00bd6570` | 0 -> -1 | 0 | 0 | `0x0045cec0` | Match under the original first helper-section placement. |
| `0x00bd6570` | 1 -> 0 | 8 | 4 | `0x00b66f20` | Failed same-helper section placement; non-relocation content matches. |
| `0x00bd6570` | 2 -> 1 | 19 | 8 | `0x00b66f20` | Failed same-helper section placement; non-relocation content matches. |

All seven bounded local patterns recognize the same EBP-relative receiver slot
at -16. This is a local cleanup observation only: the producer deliberately does
not search the parent for a plausible save instruction, so it has not proved
that this slot is the parent's original `this`. The member assignments remain
unknown. The source separately observes `SubObjB m_30` and `m_34` at lines
11599/11600 of `modelloader.cpp`, and the three `ObjectReference` declarations at
lines 7405-7407 of `blk_00bc0000_o2.cpp`. These are separate facts, not an automatic
native/source mapping.

The constructor's actual FuncInfo has four states; the negative destructor has
three. The tool requires every native unwind transition and every cleanup to be
accounted for. It does not manufacture a fifth state for a named source member.
The last member's construction and source lifetime interpretation still need
explicit source/compiler contract review before making runtime claims.

The constructor handler is in native section 793 at +41, and FuncInfo in section
795 at +32. The negative-case handler is in section 471 at +30, and FuncInfo in
section 472 at +24. Physical associations return to the exact same-object matched
parent sections. Both handlers are separate local pieces rather than ordinary
callable providers. No original instructions, table payloads or disassembly are
included here.

Independent output reconciliation checked the exact output hash and pinned
inputs, all nine receipt intervals and physical associations, original code
relocation destinations and non-relocation counts, all nine metadata pointer
values and non-relocation content, all seven native/reference transitions and
local frame patterns, and the required distinct helper destinations. The reviewer
did not separately replay the complete original oracle inference algorithm.
That distinction remains explicit; this is evidence-only acceptance.

## Proposed smallest source/type repair boundary

The approved observation confirms the triage finding that globally
renaming `SubObjB::~SubObjB` cannot satisfy both constructor cleanup roles. The
smallest plausible runtime-only change is two distinct member-type views for the
`+0x30` and `+0x34` cleanup roles, each with a separately reviewed destructor
contract, while preserving established layout and ordinary constructor behavior. That is only a proposal: first prove the parent stores its incoming receiver in
the observed frame slot and tie each adjustment to a source member using bounded
instruction-boundary/dataflow evidence. Then establish each destructor ABI/body
and the constructor/rollback contracts for the separate views. Exact member
assignment, saved-this provenance and those provider/lifetime proofs remain open. If the new ledger cannot establish them, retain explicit unknowns and
request the smallest further bounded investigation. Do not clone frame-local
funclets, patch calls, merge role identities or edit reference source automatically.

For the `ObjectReference` negative case, do not solve the section-placement
conflict by choosing the first observed destination. Preserve its three states
and distinct original action destinations; a later source/view proposal must
explain why the original roles differ before adopting any helper body.
