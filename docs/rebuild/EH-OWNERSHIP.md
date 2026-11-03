# Exact EH ownership observations

`tools/rebuild/eh_ownership.py` persists the exact-address EH-piece join from
[the generated-code gaps audit](GENERATED-CODE-GAPS.md). It reads hash-bound
metadata and relevant retained COFF objects; it never reads the game image,
compiles, rechecks function bytes, rewrites objects, applies fixups, selects
providers, links or executes code. Outputs remain private under ignored
`build/rebuild/` or another private directory.

## Invocation and input contract

Supply independently trusted SHA-256 identities for the ledger, data plan,
retained v3 receipt and retained-object manifest. The plan binds the streamed
detail and authoritative recipe identities; the ledger must bind the same plan,
detail, recipe and receipt. The receipt must bind this exact manifest and recipe.
Use the exact artifact identities recorded in the generated-code gaps audit.

```powershell
python tools/rebuild/eh_ownership.py --ledger <runtime-gaps.json> --ledger-sha256 <trusted-hash> --plan <data-plan-owned-v4.json> --plan-sha256 <trusted-hash> --detail <data-plan-owned-v4.jsonl.gz> --retained <retained-verify-full-v3.json> --retained-sha256 <trusted-hash> --manifest <retained-objects.json> --manifest-sha256 <trusted-hash> --out <new-private-report.json> --details-gz <new-private-observations.jsonl.gz>
```

`--recipes` defaults to `build/units.json`; `--root` defaults to this checkout
and resolves source and optional index paths. The object paths resolve relative
to the supplied manifest's directory and its optional `object_root_relative`.
There is no path search. Every manifest recipe is reconciled against the exact
authoritative recipe, identity, source and compiler. Every receipt unit must
agree with its manifest's object/source/recipe identity and have status `ok`.
Full retained scope, input stability, function/global-EH/original-parity passes
are required. The receipt's original comparator, oracle and verifier source
hashes must agree with the current implementations. Local diagnostics are
preserved separately; their absence is not required for an evidence record.

The complete data detail is streamed, duplicate sites rejected, all category
counts reconciled against the plan and selected target groups reconciled against
the ledger. The historical population counts are **not hardcoded**. JSON inputs
are capped at 64 MiB each by the shared bound-input reader, detail at 200,000
rows and 8,192 characters per row. Per-target records and relevant unit metadata
are held in memory. Only units having a matching piece containing a selected
target have their actual objects and source observations rehashed and objects
reparsed. No complete inventory or function byte re-verification runs.

An absent optional function index stays an explicit original-oracle limitation.
An index appearing/disappearing or changing identity relative to the receipt
fails. All observed input hashes and index presence are checked again before
publication. Existing outputs, input aliases and duplicate output paths are
rejected. Files use exclusive creation; a failed write removes only files newly
created by that invocation. A new output filename is required for a new run.

## Candidate mapping and parent distinctions

For each exact target, every retained receipt piece with `match=true` and
`start <= target < end` is retained. Boundaries are half-open; no nearest-piece
assignment, contiguous-placement assumption or overlap resolution occurs.
Nonmatching pieces do not become candidates. Repeated observations retain their
unit and piece-row identities, even if their intervals happen to agree.

The v3 receipt lacks native EH section/offset fields. The tool recovers them
structurally from the actual hash-checked COFF using the unchanged oracle's
order: scan recipe functions in order; identify in-span DIR32/REL32 references
to `.text$x`; keep the first anchor parent for each section; emit sorted section
indices, split at every symbol value and section boundary. It pairs these pieces
with the trusted receipt's ordered rows, requiring equal counts, lengths and
anchor parents. The original placement comes from the receipt, including any
noncontiguous placement. Native target offset is piece offset plus exact target
offset within that original interval.

This association requires a trusted receipt produced without row reordering by
the hash-bound original producer. Equal-length, same-parent rows cannot be
independently distinguished from placement metadata alone after a caller
arbitrarily reorders and re-attests the receipt. A stale trusted receipt hash
rejects a reordered input; accepting a new hash is not independent placement
proof. Candidate field `native_mapping` explicitly says
`STRUCTURAL_ORACLE_SECTION_CUT_ORDER`, with that producer/order assumption.
This is no new game-image comparison.

Each candidate keeps three separate parent concepts:

- `receipt_anchor_parent`: the exact matched function row used by the oracle's
  anchor observation, checked against its recipe and native section/value.
- `tail_declared_parents`: every same-recipe listed EH-tail interval containing
  this target, with its declared parent retained. An empty list is explicit;
  source proximity does not supply a parent.
- `physical_associative_parent`: the actual COFF section-auxiliary association
  chain and root function symbols. Exact section/value matched-body records in
  this same object are listed separately. Missing association/function evidence
  remains unknown; invalid/cyclic associations fail. A distinct unlisted header
  body is not credited from another function's match or another object's receipt.

Even a physical parent with an exact same-object verified body does not prove
that it is compatible with every original tail-declared parent, nor that its
frame, cleanup state, associated metadata and dependencies form a valid runtime
component. `frame_contract_verified`, ABI, lifetime, provider selection and
runtime eligibility remain false. Review these distinctions alongside the
[EH closure pilot](EH-CLOSURE-PILOT.md).

## Output schema

The compact schema-1 JSON has kind `fnv-eh-ownership-observations`, analysis-only
status, input hashes, implementation hash, optional-index status, population and
coverage summaries, and one record for every selected target, including those
without a candidate. Per-target fields retain original class/site counts,
candidate count, multiple-observation status, input EH ambiguity, and whether
any candidate's unit has local EH diagnostics. Input ambiguity stays unresolved.

With `--details-gz`, one compressed JSONL row per candidate contains target VA,
recipe identity/index, relative source and source/object hashes, the parent
distinctions above, receipt piece index, exact original/native piece intervals,
native section/name/target offset, entry/interior classification, inferred-name
dependencies and the unit's local diagnostic count. The JSON report binds the
compressed file hash and format. Without it, every candidate is included inline.
No game bytes, disassembly, raw COFF payloads or private input paths are emitted.
Field widths and addresses do not establish C++ field type, ABI or lifetime.

## Verification and measured native run

Fourteen original synthetic tests pass:

```powershell
python -m unittest discover -s tests/rebuild -p test_eh_ownership.py -v
```

They exercise same-length cuts, relocation order differing from section order,
noncontiguous original placement, overlapping alternatives, repeated data-site
observations, interior and unmatched targets, changed objects and source,
altered receipts including a same-length row swap against a trusted hash,
conflicting identities, stale manifests and producer hashes, diagnostics,
absent-index reporting and index presence changes, physical parent/header-copy
unknowns, association cycles, inline details and output overwrite rejection.

The native metadata run used the exact audited ledger, v4 plan/detail, v3
retained receipt, authoritative recipe and `objects.json` identities. It took
approximately 3.0 seconds, reparsed 119 relevant retained objects and emitted
1,693 candidate observations for 7,422 targets / 8,549 site occurrences:

| Input category | Covered targets / sites | Uncovered targets / sites |
|---|---:|---:|
| `other-code` | 1,006 / 1,006 | 5,932 / 7,050 |
| `EH-interior-ambiguous` | 484 / 493 | 0 / 0 |

There are 96 targets with multiple observations and 663 targets with at least
one diagnostic-bearing candidate. All 1,693 observations have an associative
root function with exact same-object matched-body evidence. This finding alone
does not settle original-parent compatibility or frame contracts; every candidate
remains runtime-ineligible and no provider is selected.

Private `eh-ownership-native-v2.json` is 1,800,491 bytes, SHA-256
`67bc0711d7d864bf51e7d82532c8708e6538969d388ee6c6ec53f8a7cac5629d`;
`eh-ownership-native-v2.jsonl.gz` is 104,831 bytes, SHA-256
`01c6166ebef21c234f6e1ef4b412b92f216bc87f98e88936914b2af86598d08f`.
The earlier v1 metadata run is preserved as a pre-parent-distinction artifact.
These are private audit results, not new byte-match, startup or gameplay results.
