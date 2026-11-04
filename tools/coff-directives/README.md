# COFF directive witness (candidate only)

A pure Python library that parses caller-supplied `.drectve` section payload
bytes conservatively and produces a **candidate-only** witness for a closed set
of library-only `DEFAULTLIB` directives. It is evidence for a later, separately
reviewed consumer. It approves nothing.

**Status: library integrated; no consumer or policy adoption.** Nothing here is wired into any existing
policy, consumer, serializer, build recipe or source.

## Files

| Path | What it is |
|---|---|
| `tools/coff-directives/coff_directives.py` | The library. Python standard library only; no command line. |
| `tools/coff-directives/README.md` | This file. |
| `tools/coff-directives/INTEGRATION.md` | The integration contract: inputs, rules, outputs, bounds, every finding code, every false field. |
| `tools/coff-directives/RESULTS.md` | Test and mutation results, attribution, limitations. |
| `tests/coff-directives/test_coff_directives.py` | The adversarial tests. Invented bytes and opaque identifiers only. |

## What it does and does not do

- It splits a payload into spans that account for **every byte**, keeping each
  span's offsets and raw bytes. Nothing is skipped, stripped or normalised.
- It records prefix, option spelling, quoting, library spelling, case, suffix,
  order and multiplicity exactly as found.
- It labels encodings (strict ASCII, UTF-8 BOM, non-ASCII) and never guesses a
  code page.
- It separates well-formed **syntax** from proven **VC++ 2008 linker
  semantics**. The second is never claimed.
- It treats the section context, toolchain, policy, library obligations and
  original negative identities as caller assertions. It checks them for form
  and consistency only.
- It never opens a file, lists a directory, uses the network, starts a process,
  reads the environment or touches game data. It never executes a directive,
  rewrites bytes, selects a provider or declares a root admitted.
- Candidate, adoption, provider, link, ABI and runtime authorization are always
  `false`. The original negative certificate is never declared invalid and no
  blocker is ever discharged.

## Use

```python
import coff_directives as cd

parsed = cd.parse_drectve(payload_bytes)           # syntax witness only
policy = cd.existing_default_policy("policy-A", policy_sha256)
result = cd.evaluate_library_candidate(
    payload_bytes, section_context, toolchain_assertion, policy,
    library_obligations, original_negative)
print(cd.canonical_json(result.to_dict()))
```

`result.status` is `EVIDENCE_PRESENT` or `NO_EVIDENCE`. `result.findings`
explains every reason for `NO_EVIDENCE`. See `INTEGRATION.md` for each type.

## Run the tests

From the repository root:

```
python -m unittest discover -s tests/coff-directives -p "test_*.py" -v
```

The tests load the module by path, need no third-party package and write
nothing.

## Not done

Any consumer adoption, commits and use of a real object, section or receipt
remain separate coordinator decisions.

Independent API-integrity regressions are in `tests/coff-directives/test_independent_review.py`. Returned nested candidate fields and `to_dict()` values are defensive copies; callers must still verify binding hashes before using saved evidence.
