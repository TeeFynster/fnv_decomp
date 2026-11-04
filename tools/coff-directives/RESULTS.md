# COFF directive witness: delivery results (2026-11-03)

This delivery adds only `tools/coff-directives/` and `tests/coff-directives/`.
It was built from the source-only handoff packet in a standalone scratch
checkout. The packet contained only `AGENTS.md`, `LICENSE` and the task
document. No existing file was edited.

**It is not integrated.** The coordinator owns integration.

Nothing in this work:

- opened, parsed or inspected an object file, executable, game image, real
  `.drectve` section or private receipt;
- ran a compiler, a linker or any native tool;
- used the network. The two Microsoft pages named in the task were not fetched,
  so the format references were not re-read;
- installed anything or modified a system setting.

## Attribution

All of it was done by Claude Opus 5.5 (`claude-opus-5-5`) in Claude Code (the
desktop app), using file read/write/edit and shell tools. That covers the
library, the tests, the three documents and the mutation checks. No subagents
were used.

## Results

| Item | Result |
|---|---|
| Unit tests (`python -m unittest discover -s tests/coff-directives -p "test_*.py"`) | `Ran 111 tests ... OK`, none skipped |
| Same run with `-W error` | `OK` |
| Deliberately broken copies of the library | 28 of 28 caught |
| Syntax parsed as Python 3.8 | Both Python files parse |
| Native compile, link or run | `NOT_RUN` (not applicable to this task) |
| Use of a real object, section or receipt | `NOT_RUN` (none was supplied or used) |
| Integration into the branch, ledger entry, docs links | `NOT_RUN` |

The suite ran on Windows 11 with Python 3.12.10 only. It was not run on 3.8
through 3.11, Linux or macOS.

## What the tests cover

- **Byte accounting.**
  - Each of the 256 single-byte payloads.
  - Every payload of up to 5 bytes over a 9-byte alphabet (66,430 payloads),
    compared with an independent regular-expression tokenizer written in the
    tests.
  - 3,000 random payloads.
  - Spans are contiguous, their raw bytes concatenate to the payload, and the
    hash and length are exact.
- **The existing default and a three-library candidate.** Exact offsets, raw
  slices, order, and the byte-for-byte comparison with the two existing
  tokens.
- **Distinctions that must not collapse.**
  - Slash against dash.
  - Case of the option name and of the library, with and without `.lib` in
    any case.
  - Unquoted against quoted values.
  - Order and multiplicity.
  - Lookalike names such as `NODEFAULTLIB` and `DEFAULTLIBS`.
- **Malformed input.**
  - NUL, tab, CR, LF, DEL and other control bytes, leading and trailing.
  - UTF-8 BOM, a UTF-16 BOM-like start, UTF-16 text, and non-ASCII bytes.
  - Unterminated, mid-token and doubled quotes, and a backslash before a quote.
  - Missing separators, space runs, and empty or missing values.
  - Empty and blank payloads.
  - Non-`bytes` input.
- **Context.** Each inconsistency in the section facts, and about 70
  wrong-typed or wrong-form values across all eleven fields, including `bool`
  for an integer, float, string digits, bytes, a trailing newline and
  oversized values. Values are not echoed.
- **Toolchain, policy, obligations and original identities.**
  - Unsupported assertions.
  - 25 invalid policies.
  - Missing, extra, unreviewed, duplicate, conflicting and reused obligations.
  - Malformed identities and hashes.
  - No blockers, duplicate blocker identities, and no directive-related
    blocker.
  - Blocker multiplicity.
- **Hidden operations.** `INCLUDE`, `ALTERNATENAME`, `EXPORT`, `ENTRY`,
  `SECTION`, `MERGE` and `NODEFAULTLIB` in three cases and both prefixes,
  alone, mixed with the default libraries at every position, and with odd
  framing. Unknown, malformed and not-an-option tokens.
- **Bounds.** Each bound at its limit and one past it. Rejected results carry
  no partial spans.
- **Binding.** The binding hash changes when any one of 18 inputs changes. It
  can be recomputed from the echoed inputs, and it is withheld when an input is
  unusable.
- **Approvals.** Every false field on every kind of result. The fields cannot
  be set through the constructor or by assignment.
- **Fuzzing against an independent oracle.** 6,005 payloads, half of them
  mutated near-valid shapes. Evidence is present exactly when a separately
  written regular-expression recogniser accepts the payload under the closed
  policy. A further 2,000 payloads with an inserted dangerous byte never give
  evidence.
- **A scenario for every finding code.** The test table must equal the
  module's registry of codes, each code must be producible, and every code must
  appear in `INTEGRATION.md`.
- **Determinism and isolation.**
  - Equal inputs give identical canonical JSON.
  - Inputs and module data are not mutated.
  - With file, process, socket and directory calls replaced by failures, nothing
    is called.
  - A static scan shows imports limited to `dataclasses`, `hashlib`, `json`
    and `re`, no `open`, `print`, `exec`, `eval`, `try`, `with` or path
    arguments, and no command-line entry point.
- **Documents.** ASCII, LF only, no private path, no long hex value, every
  finding code and false field present, the bounds stated, and only the five
  expected files in the delivered tree.

The 28 broken copies each changed one rule: tab allowed inside tokens, quote
tracking removed, the BOM not recognised, an escape not flagged, a lookalike
matched as `DEFAULTLIB`, a `bytearray` accepted, an off-by-one payload bound,
two approval fields defaulting to true, evidence despite findings,
case-insensitive form matching, the prefix, order, mixed-operation, duplicate,
empty-payload, raw-size, payload-hash, relocation and exact-flags checks
removed, unreviewed and unreferenced obligations accepted, duplicate blocker
identities ignored, obligations and later blockers left out of the binding, a
duplicate policy form accepted, the mismatch observation dropped, and the span
self-check skipped. Every one failed the suite.

## Observations (reported, not resolved)

1. **The existing policy was not supplied.** The retained-root policy, the
   legacy consumer and the frozen observer were not in the packet. Their
   behaviour is encoded only from the task description. Nothing here was
   compared with their source.
2. **A token comparison depends on tokenization.** The raw tokens are compared
   with the two existing default tokens using this module's tokenizer. The
   legacy consumer's treatment of leading or trailing spaces, quoting and case
   is unknown.

## Limitations and unresolved assumptions

1. **This tokenizer is a design, not VC++ 2008 behaviour.** Slash against dash,
   quoting, case, abbreviations, escapes, multiple spaces and a BOM are
   recorded but unproven. A candidate that this module accepts can still be
   misread by a real linker.
2. **Every context fact is an assertion.** Section identity, extent, flags,
   counts, the toolchain and runtime model, the policy identity, the library
   obligations and the original certificate, root and blocker identities are
   checked only for form and for consistency with each other. Nothing verifies
   them against an object, a toolchain, a review or a certificate.
3. **Library existence, compatibility and selection are unverified.** An
   obligation is an opaque reviewed-identity claim. It is a required input, not
   proof. The result's `unverified` list says so every time.
4. **Conservative choices that may reject legitimate objects.**
   - Flags must equal `0x00100a00`.
   - Only single spaces separate tokens, with at most one leading and one
     trailing.
   - Only `/DEFAULTLIB:"NAME"` style is declared by the shipped policies.
   - The compiler, version and runtime vocabulary is fixed to `msvc`,
     `vc2008-sp1` and `static-multithreaded-release`.
   - A NUL-padded or newline-terminated section is `NO_EVIDENCE`.
   - The size and count bounds are arbitrary: 16384 bytes, 1024 spans, 256
     tokens, 1024 bytes per token, 64 blockers and 8 obligations.

   Each can be widened only by a reviewed change.
5. **The tests share an author with the library.** The oracle and the hand
   tables are independent code, but the same mind wrote both. A shared
   misreading of the task would not be caught. The 28 broken copies show
   sensitivity to those 28 changes only.
6. **Constant fields are not a security boundary.** The approval fields cannot
   be set through the normal API, but Python code can still bypass a frozen
   dataclass. The consumer must not accept a result from an untrusted source on
   the strength of those fields alone.
7. **The binding does not cover the module itself.** It binds the inputs. The
   coordinator should record the hash of `coff_directives.py` that produced a
   result.
8. **No unlock count is promised.** Whether any cached root has a directive
   blocker that this evidence could matter for is unknown. A root whose
   blockers include none of the three directive-related codes gets
   `NO_EVIDENCE`.
9. **Platforms.** Tested only on Windows 11 with Python 3.12.10.
10. **Not done.** These are left to the coordinator: integration, the
    `docs/rebuild/AGENT-WORK.md` ledger entry and docs links, commits, and any
    use of a real object or receipt.

## Coordinator review

After the historical delivery, independent review identified shallow mutable candidate-result fields. Codex added defensive copies and synthetic regressions for constructor inputs, direct nested access and serialized output. The separate coordinator test result is recorded in the integration receipt. The 28 broken-copy checks reported above are Claude-reported and were not independently reproduced. Existing root policies and runtime admission remain unchanged.
