# Runtime gaps ledger

This private analysis groups the `other-code` and `EH-interior-ambiguous` target occurrences from the bounded v4 data-plan detail by **exact original target VA**. It streams the complete detail, checks every target-class count against the bound plan, verifies the 150,165-site scope and the two expected occurrence counts, and rejects duplicate sites. A target with ten site occurrences is one unique target, not ten functions. It does not extract executable bytes, approve fixups, modify the data plan, select providers, or run game code.

Use a trusted pre-recorded SHA-256 for the input data plan. The detail digest and authoritative recipe digest must match the plan, and optional canonical-plan and retained-verification files each require their own explicit SHA-256. When both optional inputs are present, their retained-manifest digests must agree. A new private output directory is required; existing output is not overwritten. For example:

```powershell
python tools/rebuild/runtime_gaps.py --plan <private-data-plan.json> --plan-sha256 <trusted-sha256> --detail <private-detail.jsonl.gz> --recipes build/units.json --out <new-private-output-directory>
```

Optional `--canonical <file> --canonical-sha256 <sha256>` and `--retained <file> --retained-sha256 <sha256>` add narrowly scoped evidence. Defaults place output under ignored `build/rebuild/runtime-gaps`. Records are prioritized by occurrence frequency and list exact-address recipe symbols, function entries, and any optional sampled candidate or retained-function evidence. A symbol mapping is an original-address reference, not proof of a definition or usable provider. Canonical candidate examples are a sample, and absence from them is not evidence of absence. Retained verdicts establish only what their verification report states; they do not prove runtime closure. Search labels derived from names are explicitly heuristic. `EH-ambiguous-from-input` preserves the input classification; it never chooses a nearby span or resolves overlaps.

Run offline tests with `python -m unittest discover -s tests/rebuild -p test_runtime_gaps.py -v`. The ledger is scoped to the two selected classes and the supplied plan. It is not a full link dependency graph, a count of missing functions, a runtime startup verdict, or approval to apply any fixup.
