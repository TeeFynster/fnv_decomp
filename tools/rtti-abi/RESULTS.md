# RTTI ABI fixture: delivery results (2026-11-03)

This delivery adds only `tools/rtti-abi/` and `tests/rtti-abi/`. It was built
from the source-only handoff packet in a standalone folder, not inside a
checkout of the active branch.

Nothing in this work:

- ran a compiler or a linker;
- executed the fixture;
- inspected an object file, executable, game image or disassembly;
- installed anything;
- used the network.

## Attribution

All of it was done by Claude Opus 5.5 (`claude-opus-5-5`) in Claude Code (the
desktop app), using file read/write/edit and shell tools. That covers:

- the class design and the C++ fixture;
- the case matrix and the metadata schema;
- the validator and the plan check;
- the examples, the documents and the tests.

No subagents were used.

## Native results

| Item | Result |
|---|---|
| Compile producer (`od_mt`) | `NOT_RUN` |
| Compile consumer (`od_mt`) | `NOT_RUN` |
| Compiler identity and hashes | `NOT_RUN` |
| Link | Not planned |
| Run the 32 cases | Not planned |
| Any RTTI record, offset, flag or name | Not observed |

No observed compiler record, native build, dynamic cast, exception behaviour,
runtime readiness or playable-game result is claimed.

## Test results

```
python -m unittest discover -s tests/rtti-abi -p "test_*.py" -v
```

On Python 3.12.10 under Windows 11, the result was `Ran 93 tests ... OK`. The
tool's syntax was also parsed as Python 3.10, but the suite was not run on 3.10,
3.11, Linux or macOS.

The tests cover:

- **The fixture's C++ semantics.** All 32 casts give the outcome and address
  relation derived by hand, independently of the metadata. The mechanism
  (static, run-time or null input) is checked. The matrix covers:
  - pointer success, null result and null input;
  - reference success and `bad_cast`;
  - `void*`;
  - cross-casts and must-differ adjustments in all four families.
- **The rule engine on invented hierarchies:**
  - downcasts and failed downcasts;
  - cross-casts;
  - private and protected bases;
  - ambiguity, including the case where two owning subobjects fall back to an
    ambiguous cross-cast;
  - shared versus duplicated virtual and non-virtual bases;
  - `void*`, identity and static upcasts;
  - non-polymorphic sources;
  - ill-formed casts.
- **Claim conflicts.**
  - Wrong outcomes.
  - `none` or `nonzero` claimed where C++ does not decide (rejected as
    promotion).
  - Other adjustment conflicts, `result_path` and `same_result_as`, and bad
    paths.
  - `unknown` is accepted for every cast and stays `unknown` in the summary.
- **Structure.**
  - Top-level keys, the identifier grammar and class fields.
  - Missing references, cycles, repeated direct bases, duplicate and
    case-folded ids, and polymorphism conflicts.
  - Object and cast references, and cast field errors.
  - Count limits, and a hierarchy that doubles its base subobjects at every
    level (bounded at 1024).
- **Layout claims and measurements.**
  - `observed` and invented statuses are rejected.
  - Value, offset, name and evidence fields cannot be recorded.
  - Unknown claims cannot carry an expectation.
  - Hypotheses are limited to the allowed values.
  - Claims that contradict the hierarchy, and duplicate claims, are rejected.
  - Measurement results other than `NOT_RUN` are rejected.
- **Examples.** Both valid examples pass. Each of the 10 invalid examples fails
  for exactly its one documented code.
- **JSON input.** Malformed input, `NaN` and `Infinity`, duplicate keys, a BOM,
  non-UTF-8, oversized input and deep nesting (including 100000 open brackets).
- **CLI and privacy.**
  - Exit codes.
  - UNC and device paths are refused before any file access; links and
    oversized files are refused.
  - Diagnostics are identical across runs, and never contain injected values,
    the temporary directory or argument values.
  - The error count is capped at 50 and the total is reported.
  - With file-system wrappers in place, only the named file is opened.
- **Isolation.** The tool's imports are limited to 8 standard-library modules.
  It has no process, network, dynamic-code, deletion or write calls.
- **The compile plan.**
  - The plan is valid, compile-only and `NOT_RUN`.
  - The source hashes match the delivered files.
  - 20 forbidden arguments are rejected, including `/link`, `/Fe`, `/GR-`,
    `/EHa`, `/Zi`, `/FA`, `/D` and `@file`.
  - Any other argv change is rejected.
  - Compiler discovery or a literal compiler path is rejected.
  - Outputs, sources, the environment and the forbidden-operation list are
    checked.
- **The C++ sources against the metadata.**
  - The header's class hierarchy equals the metadata's.
  - Every view is declared, resolves and is filled by static conversion.
  - Every consumer case line matches its metadata cast: form, target, input
    view, expected view and address constant.
  - Only `std::bad_cast` and `std::bad_alloc` are caught, and the consumer
    never manages lifetimes.
  - Includes are limited.
  - No runtime-helper call, assembly, pragma, `reinterpret_cast`, hex literal,
    C++11 keyword or C-style pointer cast.
  - The source text is plain ASCII with LF line endings.
- **Documents.**
  - The case table in `expected-ABI.md` matches the metadata.
  - The required topics are covered.
  - No hex values, numeric offsets or decorated names appear.
  - `COMPILE-PLAN.md` shows the exact argv.
  - The README lists every file.
  - No private paths appear.

As a check that the tests can fail, 10 deliberately broken copies were run
against them. Every one failed:

- the validator promoting layout-dependent addresses;
- the validator accepting `observed`;
- the validator ignoring base access;
- the validator replacing `unknown` with the computed value;
- the validator accepting any native result;
- the plan check allowing `/link`;
- the validator opening another file;
- a consumer case with the wrong target;
- a consumer case dropping the must-differ check;
- the header losing virtual inheritance.

## Limitations and unresolved assumptions

1. **Never compiled.** The fixture is written as C++03 for Visual C++ 2008 SP1,
   but whether it compiles, and with which `/W4` warnings, is unknown.
2. **No compiler record is known.** Everything in `expected-ABI.md` section 3
   is a hypothesis or unknown, including:
   - which records are emitted, and by which translation unit;
   - their fields, displacements, flags, counts and name strings;
   - whether vtordisp fields are emitted;
   - the helper names, their arguments and their linkage form;
   - where the null check sits.
3. **The validator models a subset of C++.** It covers casts written outside
   any class scope, so only public bases are accessible, on complete objects of
   the declared dynamic type. It does not model:
   - access from members or friends;
   - cv-qualification;
   - abstract or incomplete classes;
   - casts during construction or destruction, where the dynamic type is the
     class under construction.

   A subobject reachable by at least one all-public path is treated as a
   public base.
4. **Address claims are conservative.** `nonzero` is accepted only for
   distinct, non-nested, polymorphic subobjects. Any containment, including
   through a virtual base, is `layout_dependent`.
5. **Language edition.** The rules follow the current wording of the standard,
   and the C++03 intent is the same. Whether this compiler's run-time helper
   handles the private-base case (M09) and the ambiguous cases (A01, A02) as
   C++ requires is unknown.
6. **One module only.** Casts across modules or DLLs, mixed C runtime models,
   and any game binary are outside this fixture. Fixture source and synthetic
   tests cannot establish cross-module or game ABI compatibility.
7. **Schema v1 cannot record observations.** Measured results would need a new,
   reviewed schema version.
8. **The plan is fixed.** It has one variant (`/Od /MT`). Another variant would
   mean revising both the plan and `check-plan`. Two things are unverified:
   - whether `cl.exe` accepts forward slashes in `/Fo` and in source paths;
   - whether the single include directory is enough.
9. **Source hashes are over LF text.** `sha256_lf` normalizes CRLF to LF. A
   checkout that converts line endings compiles different bytes. The plan's
   identity record would capture those bytes at run time.
10. **No driver.** There is no `main`. Running the cases would need a small
    driver and a link step, and neither is part of this delivery.
11. **Platforms.** Tested only on Windows 11 with Python 3.12.10.
12. **Not done.** Integration into the branch, the `docs/rebuild/AGENT-WORK.md`
    ledger entry, docs links, commits and any native step. The coordinator does
    these.

## Coordinator review

Codex clarified fixture ownership and output-buffer preconditions, corrected claims about potentially folded casts, and added input ancestor reparse checks. The original 93-test count above is the submitter historical result, not the coordinator rerun. Native results remain NOT_RUN in this delivery.

## Separate SP1 compile-only phase

After independent source and command review, the coordinator compiled the two synthetic translation units once each with VC++ 2008 SP1 x86. Both returned exit code 0 with empty stderr. No link, fixture execution or RTTI object inspection occurred. This confirms only compiler acceptance of these fixture units, not runtime cast semantics or game compatibility. The delivered plan and its original `NOT_RUN` fields remain historical and unchanged.
