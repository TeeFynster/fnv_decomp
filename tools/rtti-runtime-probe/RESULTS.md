# RTTI runtime probe: delivery results (2026-11-03)

This delivery adds only `tools/rtti-runtime-probe/` and
`tests/rtti-runtime-probe/`. It was built from the source-only handoff packet,
in a standalone scratch checkout, not inside a checkout of the active branch.
The supplied fixture files were used unchanged. None of them was edited or
copied into the delivery.

Nothing in this work:

- ran a compiler, a linker, the fixture or any program built from it;
- inspected an object file, executable, game image or disassembly;
- installed anything;
- used the network.

## Attribution

All of it was done by Claude Opus 5.5 (`claude-opus-5-5`) in Claude Code (the
desktop app), using file read/write/edit and shell tools. That covers:

- the driver and the report schema;
- the checker and the reviewed matrix;
- the plan and the plan check;
- the samples, the documents and the tests.

No subagents were used.

## Native results

| Item | Result |
|---|---|
| Compile producer | `NOT_RUN` |
| Compile consumer | `NOT_RUN` |
| Compile driver | `NOT_RUN` |
| Link | `NOT_RUN` |
| Run one cycle | `NOT_RUN` |
| Run three cycles | `NOT_RUN` |
| Check native reports | `NOT_RUN` (no native report exists) |
| Toolchain identity and hashes | `NOT_RUN` |
| Any cast outcome, address relation or destructor count | Not observed |

No observed compile, link, dynamic cast, exception behaviour, ownership,
runtime readiness or playable-game result is claimed. The ten files in
`tests/rtti-runtime-probe/samples/` are invented and marked
`"origin": "synthetic"`. They exercise the checker only.

## Test results

```
python -m unittest discover -s tests/rtti-runtime-probe -p "test_*.py" -v
```

On Python 3.12.10 under Windows 11, the result was
`Ran 163 tests ... OK (skipped=2)`.

- One test is skipped because `tools/rtti-abi/rtti_abi.py`, the earlier
  validator, is not in this packet. It runs where that file is present.
- One test is skipped because Windows did not allow creating a symbolic link
  without extra rights.

The checker's syntax was also parsed as Python 3.10. The suite was not run on
3.10, 3.11, Linux or macOS.

The tests cover:

- **The reviewed matrix.** The checker's matrix equals:
  - a hand table in the tests;
  - the casts in `fixture-metadata.json`;
  - every case call in `rtti_consumer.cpp`, by template, input kind and address
    constant;
  - the case table in `expected-ABI.md`.

  Metadata conflicts are reported, never repaired.
- **Positive reports.** One, two and three cycles pass, with:
  - layout-dependent values of 0, 1 or mixed;
  - CRLF output;
  - `--metadata`.
- **Malformed input.**
  - Empty input and malformed JSON.
  - `NaN` and `Infinity`, a BOM, and non-UTF-8.
  - Duplicate keys, both top-level and nested.
  - Depth limits, including 100000 open brackets, and the size limit.
  - Truncation at every seventh byte and at each of the last 60 bytes. Every
    truncated report is `INVALID`.
- **Schema.**
  - Unknown and missing fields at every level.
  - Wrong types, such as `true` for an integer or `"1"` for a number.
  - Wrong schema or version.
  - `destructor_count` other than `"unknown"`.
  - Bad enumerated strings, and the cycle and case limits.
- **Lifecycle.**
  - The cycle count, cycle numbering and missing cycles.
  - Creation failure; destroy after a failed creation; one destroy after an
    exception during creation.
  - Create, run or destroy called zero times or twice.
  - Views not null at the end, a record that was not fresh, and views missing
    after creation.
  - A wrong returned count or capacity, and a disturbed guard element.
  - Exception cycles, cases listed on an unfinished cycle, and an incomplete
    report.
- **Ids.** Missing ids in every family, duplicates, unknown and malformed ids,
  order, and ids not echoed.
- **Case results.**
  - `kOutcomeNotRun` in every case, including with a forged `passed`.
  - Wrong outcomes in both directions, and `bad_cast` reported as null.
  - A wrong view.
  - `result_matches == -1` on a success case, which the fixture's own rule
    would count as passed.
  - Each of the 7 must-differ relations broken.
  - A missing relation.
  - The not-applicable values changed in all 12 failure cases.
  - Out-of-range fields, which are not echoed.
  - A sentinel entry from an unwritten result.
  - A failure in one cycle of three.
- **Conflicts.**
  - The fixture's own expected outcome, address claim or `passed` disagrees
    with the matrix (`UNRESOLVED`).
  - A fixture claim matches an observation that the matrix rejects (`FAIL`).
  - Metadata form, input kind, outcome or adjustment differs.
  - Metadata casts are missing, extra or duplicated, or name another fixture.
  - Metadata `unknown` is read as no claim.
  - A failure outranks a conflict.
- **The driver's summary.**
  - A forged `ok` status, or a mismatched exit code, is rejected.
  - The status precedence is mirrored.
  - A missing cycle counts as a structure failure.
- **Stability.** A relation that changes between cycles is rejected.
- **Samples.**
  - Each of the 10 files equals its builder in the tests.
  - Each is marked synthetic.
  - Each gives its documented verdict and exit code through the CLI.
- **CLI and privacy.**
  - Exit codes 0, 1, 2 and 3.
  - Usage errors never echo arguments or the temporary directory.
  - UNC, device, directory and link paths are refused, and so are oversized
    files.
  - Output is identical across runs.
  - Findings are capped at 50, with the total.
  - With file-system wrappers in place, only the named files are opened and no
    directory is listed.
- **Isolation.**
  - The checker's imports are limited to 8 standard-library modules.
  - It makes no process, network, environment, dynamic-code, listing or write
    calls.
  - `open` is only used read-only.
- **The plan.**
  - The plan is valid, canonical and `NOT_RUN` throughout.
  - Its source hashes match the files, and its command hashes match the argv.
  - The exact reviewed argv, the bounds, and isolated, distinct outputs.
  - No toolchain discovery.
  - 20 forbidden compile options and 17 forbidden link options are rejected,
    and so are literal paths.
  - Any result or identity value other than `NOT_RUN` is rejected, as is a
    native record inside the repository.
  - Any other change to the plan is rejected.
- **The driver source, by static review only.**
  - ASCII and LF, with only the six expected includes.
  - No C++11 constructs.
  - No `printf`, `%p`, pointer casts, `memcpy` or `what()`.
  - No environment, DLL, process or `dynamic_cast` calls.
  - No allocation, and no fixture class definitions.
  - Each fixture entry point is called exactly once in the source.
  - The guard's shape.
  - The four exception handlers.
  - The id list equals the matrix.
  - Both view lists equal the header's 24 view members.
  - The report keys and enum names equal the checker's schema.
  - The exit codes, the mirrored rule lines, the written strings, argument
    parsing and output-error checks.
- **The fixture is unchanged.** The fixture hashes match the plan, and the
  delivery contains no copy of a fixture file.
- **Documents.**
  - The README lists every file.
  - `RUN-PLAN.md` shows every exact command.
  - The native items above are `NOT_RUN`.
  - There are no private paths or long hex values.
  - All delivered text is ASCII with LF line endings.

As a check that the tests can fail, 18 deliberately broken copies were run
against them. Before each run, the plan hashes were refreshed, so no copy could
be caught only by a hash mismatch. Every one failed:

- the checker:
  - accepting `result_matches -1` on success;
  - trusting the fixture's `passed`;
  - ignoring must-differ;
  - allowing duplicate ids;
  - trusting the driver status;
  - ignoring `end_of_report`;
  - allowing unknown fields;
  - accepting missing cycles;
  - dropping the not-applicable check;
  - ignoring the metadata outcome;
  - ignoring unstable relations;
  - allowing destroy after a failed creation;
- the plan check allowing `/DEBUG`;
- the driver:
  - keeping ownership while destroying;
  - passing capacity 31;
  - forgetting a view when clearing;
  - an id list out of order;
  - skipping the `ferror` check.

## Observations about the supplied packet (left unresolved)

1. **The fixture differs from the original rtti-abi delivery in comments
   only.** The supplied header, consumer and `expected-ABI.md` add or reword
   comments: the ownership and capacity preconditions, and the note that some
   casts may be folded. The code is the same. The plan's hashes are those of
   the supplied files.
2. **Historical comments.** The fixture header still points to
   `COMPILE-PLAN.md`, which is not in this packet, and says the fixture has not
   been compiled. The consumer and producer still say `NOT_RUN`. The handoff
   says they have since compiled separately. These comments were left as they
   are, because the fixture is not to be edited. Nothing here depends on them.
3. **No metadata conflict was found.** The metadata, the consumer calls and the
   `expected-ABI.md` table all agree with the reviewed matrix.

## Limitations and unresolved assumptions

1. **The driver has never been compiled.** It is written as C++03 for Visual
   C++ 2008 SP1 x86. Three things are unknown:
   - whether it compiles, and with which `/W4` warnings;
   - whether `<cstdio>` and the other headers resolve with only the one VC
     include directory;
   - whether the linker's other defaults suit this build. These include
     `/DYNAMICBASE`, `/NXCOMPAT` and the subsystem version, none of which is
     pinned.

   Every check on the driver is a static text review.
2. **Python mirrors the C++ rules by hand.** The checker recomputes the
   driver's status with rules mirrored from the C++ source. The tests tie them
   together with anchor lines, but nothing has executed the C++ rules.
3. **Structured exceptions.** With `/EHsc`, an access violation or other
   structured exception is not caught. The process would end without a
   complete report. The checker then fails the missing or truncated output, and
   the run record's exit code shows the crash.
4. **Standard output is in text mode.** On Windows each newline becomes CRLF.
   The checker accepts this. The captured bytes, and their hash, include the CR
   characters.
5. **Destructor counts are unknown.** The fixture exposes none. The report
   records `create_fixture_objects` and `destroy_fixture_objects` calls, and
   all-null views afterwards, which is not proof that every destructor ran.
6. **Evidence of origin.** `"origin": "driver"` is a claim made in the file.
   The checker cannot tell a native report from an invented one. Provenance
   comes only from the coordinator's private run record: exit code, hashes of
   the command, program and stdout, and the toolchain identity.
7. **The matrix was reviewed, not re-derived.** The checker's matrix was
   compared with the metadata, the consumer and `expected-ABI.md`. The C++
   rules were derived in the earlier rtti-abi delivery. They were not
   re-derived here, except where the earlier validator is present for the
   optional test.
8. **Scope.** Even a future native `PASS` would cover only this synthetic,
   single-module fixture, with one compiler, one flag set and the static
   runtime. It would not establish any of the following:
   - game RTTI, cross-module or DLL behaviour;
   - ownership or exception frames;
   - playable readiness.

   The local COFF metadata measurement is outside this task.
9. **The plan is fixed.** It has one variant (`/Od /MT`) and two run sizes, 1
   and 3 cycles. Any other variant means revising both the plan and
   `check-plan`.
10. **Platforms.** It was tested only on Windows 11 with Python 3.12.10.
11. **Not done.** These are left to the coordinator:
    - integration into the branch;
    - the `docs/rebuild/AGENT-WORK.md` ledger entry and docs links;
    - commits;
    - every native step.

## Coordinator review

Codex added exact canonical fixture-metadata identity binding to prevent unreviewed source/path/target changes passing comparison, plus ancestor reparse/device input checks. The original 163-test result above is the submitter historical result.

## Separate reviewed synthetic runtime phase

After the original delivery, three authored translation units compiled with VC++ 2008 SP1 x86 and linked in a single console program using the reviewed normal static runtime. A separately reviewed one-cycle run and three-cycle run each returned exit 0. The independent checker, with the exact reviewed fixture metadata, found all 32 cases and all seven required differing-address relationships correct in every cycle. Each cycle recorded one create and one destroy call and null views afterward; destructor counts remain unknown. Layout-dependent address changes are observations, not fixed offsets. This result covers only this synthetic configuration and does not prove game RTTI, cross-module compatibility, ownership, exception-frame closure or gameplay. The original delivered plan remains `NOT_RUN` as historical evidence; private receipts record the actual later operations.
