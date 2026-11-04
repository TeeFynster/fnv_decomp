# Function code-ownership selection

`tools/rebuild/function_selection.py` selects exactly one hash-bound, explicitly recipe-selected function row per symbolic original address. It does not select metadata-only extra bodies, link objects, rewrite symbols, normalize source or method types, or authorize runtime use. Both `runtime_eligible` and `link_ready` remain false. A selected row is code ownership evidence, not ABI, data, COMDAT, initializer or exception-handling closure.

The tool checks complete recipe and retained object identity using the canonical planner's existing reconciliation, validates the pinned v3 retained-verification receipt and current source, verifier, comparator and optional-index observations, and reparses each native object to validate every selected symbol and span. It streams the complete candidate gzip and requires exact selected-row coverage and matching native section metadata. It rejects absent or duplicate groups, unexpected or conflicting rows, metadata-only substitutes, stale hashes and incomplete or extraneous overrides. The receipt's global EH and local diagnostic results remain separate in the private report. Receipt hash linkage is evidence of the observed run, not proof of execution or compiler causality.

The complete selected-basis input has 68,667 rows for 68,657 symbolic addresses: 68,647 have one candidate and ten have two. The public override table is an explicit review decision for the ten repeated addresses. The recommendation prefers the recipe covering more selected rows, with no implication that its whole object can safely be linked. All ten pairs independently match the same original target and size, share a source and exact decorated name, have zero same-unit local EH notes and zero direct associative children. Their actual section/value, compiler flags and coverage were reviewed separately; matching the oracle is not a claim of raw byte identity or closure. The receipt preserves 95 local EH diagnostics in 16 units, strict local EH false, runtime closure false, and an absent optional function index.

Outputs are new private files under ignored `build/rebuild`; they contain symbolic original IDs, not fixed runtime addresses. Supply exact SHA-256 pins for the plan, candidate stream and receipt, alongside the recipe, retained manifest, inventory and public override table. For example:

```text
python tools/rebuild/function_selection.py --recipes build/units.json --manifest <retained-manifest> --inventory <inventory> --receipt <receipt> --receipt-sha256 <sha256> --plan <plan> --plan-sha256 <sha256> --candidates <gzip-ndjson> --candidates-sha256 <sha256> --overrides runtime/function-provider-overrides.json --output <new-private-report>
```

The plan and gzip digests must come from the reviewed evidence; the plan does not itself bind the gzip digest. Inputs and objects are rehashed after the streaming pass. These checks do not make original symbolic addresses runtime pointers, and an output report does not approve extracting or executing game code.

## Full private metadata run

The approved table produced 68,657 selected symbolic code owners from 68,667 checked recipe rows, including the ten explicit choices. The private `build/rebuild/function-selection-v2.json` SHA-256 is `48ae62cdc5b1754b9c4af674ef4716d53afb554882e174a93acf860eaf1c6cb1`. It preserves all 95 diagnostic records across 16 units, reports the absent function index, and keeps runtime eligibility, link readiness and closure false. This run parses metadata and validates retained hashes; it does not link or execute code.

Eight focused synthetic tests cover unambiguous selection, mandatory exact overrides, metadata-only substitution, missing and duplicate groups, conflicting or forged selected evidence, extra overrides, duplicate override addresses and stale plan pins. They do not replace independent review of the real metadata.
