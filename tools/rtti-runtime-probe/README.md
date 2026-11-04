# Synthetic RTTI runtime probe

This directory provides two things, plus a reviewed plan for building and running them:

- A C++03 driver (`main`). It runs the 32 synthetic `dynamic_cast` cases of the
  fixture in `tools/rtti-abi/fixture/` and writes a bounded, versioned JSON
  report.
- An independent standard-library checker for that report.

The fixture files are used unchanged, and nothing here edits or copies them.

**Original delivery status: build, link and execution were `NOT_RUN`.** No compiler, linker,
fixture or program was invoked for that delivery. The synthetic sample reports
exercise the checker only; they are not native evidence. See `RESULTS.md`.

## Files

| File | What it is |
|---|---|
| `tools/rtti-runtime-probe/driver/rtti_probe_main.cpp` | The C++03 driver with `main` |
| `tools/rtti-runtime-probe/rtti_probe_check.py` | The report checker, the metadata comparison and the plan check |
| `tools/rtti-runtime-probe/run-plan.json` | The machine-readable build, link, run and check plan (`NOT_RUN`) |
| `tools/rtti-runtime-probe/RUN-PLAN.md` | Short instructions for reviewing the plan |
| `tools/rtti-runtime-probe/README.md` | This file |
| `tools/rtti-runtime-probe/RESULTS.md` | Results, attribution and limitations |
| `tests/rtti-runtime-probe/test_rtti_probe.py` | The synthetic tests |
| `tests/rtti-runtime-probe/samples/` | Ten invented reports, all marked `"origin": "synthetic"` |

## Usage

```
python -I tools/rtti-runtime-probe/rtti_probe_check.py check <report.json> [--metadata tools/rtti-abi/fixture/fixture-metadata.json] [--format text|json]
python -I tools/rtti-runtime-probe/rtti_probe_check.py compare-metadata tools/rtti-abi/fixture/fixture-metadata.json
python -I tools/rtti-runtime-probe/rtti_probe_check.py check-plan tools/rtti-runtime-probe/run-plan.json
python -m unittest discover -s tests/rtti-runtime-probe -p "test_*.py" -v
```

| Exit code | `check` and `compare-metadata` | `check-plan` |
|---|---|---|
| 0 | `PASS` | The plan is valid |
| 1 | `FAIL`, or `INVALID` (malformed, truncated, empty or schema-invalid) | Rejected |
| 2 | Usage or file error (stderr) | Usage or file error |
| 3 | `UNRESOLVED`: no failure, but at least one conflict | Not used |

A failure outranks a conflict. Findings are printed as
`<JSON pointer>: <code>: <message>`, in a fixed order, capped at 50, with the
total. They never echo paths, argument values, unknown key names, unreviewed
ids or out-of-range values.

Example output, from a synthetic sample:

```
PASS [synthetic sample: not native evidence]: 1 of 1 cycle(s); cases meeting the reviewed matrix per cycle: 32 (of 32).
  must-differ relations held per cycle: 7 (of 7).
  layout-dependent observations: 0 changed, 13 unchanged (observations only; no offset or guarantee follows).
  lifecycle: create calls [1], destroy calls [1], views null at end [True]; destructor count unknown.
  driver status stated 'ok', recomputed 'ok' (the stated status is not trusted).
Note: this checks the report only. It is native evidence only together with the coordinator's private run record (exit code, hashes, identities).
```

## The driver

`rtti_probe [--cycles N]`, where N is 1, 2 or 3. The default is 1. Any other
arguments give exit 2, and nothing is written to stdout.

It uses only the fixture's public interface from `rtti_abi_fixture.h`. Each
cycle runs these steps:

1. Start a fresh `FixtureObjects` and set all 24 view pointers to null. Record
   whether they are all null.
2. Fill `CaseResult[33]` with a sentinel value. Element 32 is a guard just past
   the capacity.
3. Call `create_fixture_objects` once, through a guard object.
   - On failure, stop.
   - Otherwise record whether every view is set. If a view is not set, release
     and stop.
4. Call `run_cast_cases(objects, results, 32)` once.
5. Release, which calls `destroy_fixture_objects` once.
6. Record whether every view is null again, and whether the guard element is
   untouched.
7. Copy each result. An id is copied only if it is one upper-case letter
   followed by two digits.

The C++03 guard object (`FixtureGuard`) works like this:

- It cannot be copied, and calls `create_fixture_objects` at most once.
- It clears its ownership before calling `destroy_fixture_objects`, so it can
  never destroy the objects twice.
- Its destructor releases on every path.
- When creation returns `false`, it owns nothing, so destroy is not called.
- If creation were to throw despite its contract, it still destroys once
  whatever was stored.

Every exception is caught inside a cycle: `std::bad_alloc`, `std::bad_cast`,
other `std::exception`, and `...`. Only its kind and stage are recorded, never
its message. With `/EHsc`, structured exceptions such as access violations are
not caught. In that case the process ends without a complete report, and the
checker fails the missing or truncated output.

Further cycles run only after a completed cycle. Every cycle uses fresh
objects. The fixture does not expose destructor counts, so the report states
`"destructor_count": "unknown"`, and no counter is invented.

Exit status is deterministic. The first matching row wins:

| Exit | `driver_status` | Meaning |
|---|---|---|
| 6 | (none written) | stdout could not be written or flushed |
| 5 | `exception` | An unexpected exception was caught in a cycle |
| 4 | `create_failed` | `create_fixture_objects` returned `false` |
| 3 | `structure_failure` | Wrong count; a missing, duplicate, misplaced or malformed id; a field outside its enum; a disturbed guard; or an unexpected lifecycle observation |
| 1 | `case_failure` | A result is not self-consistent with the fixture's own claims |
| 0 | `ok` | Every cycle completed and every case was self-consistent |
| 2 | (none written) | Usage error |

The driver's own check uses the fixture's claims, so it is only preliminary.
The checker decides.

The output contains:

- no pointer values, addresses or raw memory;
- no paths, environment values or exception messages.

Every string it writes is a constant in the source, or an id that passed the
format check.

## Report schema (`fnv-rtti-runtime-report` v1)

**Top level.** Every key is required. Unknown keys are rejected at every level.

| Key | Value |
|---|---|
| `schema` | `"fnv-rtti-runtime-report"` |
| `schema_version` | `1` |
| `origin` | `"driver"`, or `"synthetic"` for invented samples |
| `fixture` | `"rtti_abi_fixture_v1"` |
| `case_count_constant` | `kCastCaseCount` as built (`32`) |
| `cycles_requested` | 1 to 3 |
| `cycles` | The cycles the driver attempted (at most 3) |
| `driver_status` | `ok`, `case_failure`, `structure_failure`, `create_failed` or `exception` |
| `driver_exit_code` | The exit code matching `driver_status` |
| `end_of_report` | `true` |

**Each cycle**

- `cycle` (1-based);
- `status`: `completed`, `create_failed`, `views_invalid`, `exception` or
  `incomplete`;
- `exception_kind` and `exception_stage`;
- `views_null_before_create`, `create_calls` and `create_returned`;
- `views_all_set_after_create`;
- `run_calls`, `run_capacity` and `run_returned` (`-1` if not called);
- `guard_intact`;
- `destroy_calls` and `views_null_at_end`;
- `destructor_count`, which is always `"unknown"`;
- `cases`.

**Each case** keeps the fixture's claims apart from the runtime observations:

```
{"id": "S01",
 "fixture_claims": {"expected": 1, "address_expected": -1, "passed": 1},
 "observed": {"outcome": 1, "result_matches": 1, "address_changed": 0}}
```

The values are the fixture's enums:

- outcome: 0 not run, 1 success, 2 null, 3 `bad_cast`;
- address expectation: -2 not applicable, -1 layout-dependent, 0 must equal,
  1 must differ;
- `result_matches` and `address_changed`: 1 or 0, or -1 for not applicable.

## What the checker checks

The checker holds its own reviewed matrix (`MATRIX`): form, input kind, outcome
and address rule for each of the 32 cases. The tests keep it in step with
`expected-ABI.md`, `fixture-metadata.json` and the calls in
`rtti_consumer.cpp`.

It trusts none of the following:

- the fixture's `expected`, `address_expected` or `passed`;
- the driver's stated status.

**Input**

- At most 64 KiB, nested at most 8 levels deep.
- UTF-8 without a BOM.
- No duplicate keys, `NaN` or `Infinity`.
- Empty input is `INVALID`, and so is truncated input.

**Structure**

- Exact keys and types.
- `destructor_count` must be `"unknown"`.
- At most 3 cycles, and at most 64 cases per cycle.

**Cycles**

- The count equals `cycles_requested`, and the cycles are numbered 1 to N.
- Each cycle completed.
- The record was fresh before creation.
- `create_fixture_objects` was called once and succeeded.
- Every view was set after creation.
- `run_cast_cases` was called once, with capacity 32, and returned 32.
- The guard element is untouched.
- `destroy_fixture_objects` was called exactly once after the successful
  creation, and never after a failed one.
- Every view is null at the end.

**Ids.** There must be exactly the 32 reviewed ids: no unknown, malformed or
duplicate id, none missing, and all in the fixture's fixed order.

**Each case against the matrix**

- An observed `kOutcomeNotRun` never passes (`E-NOT-RUN`).
- The outcome must equal the matrix (`E-OUTCOME`).
- A success needs `result_matches == 1`. A value of -1 is not proof of success
  (`E-VIEW`).
- Must-differ cases need `address_changed == 1` (`E-RELATION`).
- Layout-dependent cases accept 0 or 1. The value is reported as an
  observation only.
- Null and `bad_cast` cases must keep -1 in both `result_matches` and
  `address_changed` (`E-NA`).
- If the fixture's `passed` is 1 but the observation fails, that is
  `E-FORGED-PASS`.

**Stability.** A case's address relation must be the same in every cycle
(`E-UNSTABLE`).

**Driver summary.** The checker recomputes the driver's status from the report,
with the same rules as the driver. A stated status or exit code that does not
follow is rejected (`E-DRIVER-STATUS`).

**Conflicts.** These are reported as `C-*` codes and left unresolved, never
fixed:

- the fixture claims an outcome or address rule that differs from the matrix;
- the fixture reports `passed=0` for an observation that meets the matrix;
- `--metadata` differs from the matrix in form, input kind, outcome or
  adjustment, or has missing, extra or duplicate casts, or another fixture
  name.

Metadata `unknown` is a weaker claim; any difference from the exact reviewed metadata remains unresolved.

**Plan** (`check-plan`). See `RUN-PLAN.md`. It checks:

- the reviewed plan with only placeholders: no literal or parent paths;
- no forbidden compile or link option;
- each command hash matches its argv;
- every result and identity value is `NOT_RUN`;
- the native record is kept outside the repository.

## What it does not do

The checker:

- opens only the files named on its command line, read-only;
- starts no process;
- uses no network or telemetry;
- reads no environment variable;
- changes no DLL search path;
- writes only to stdout and stderr.

A `PASS` shows that a report is consistent. Whether that report came from a
native run is shown only by the coordinator's private run record. Even then,
it covers only this synthetic fixture with one compiler, flag set and runtime.
It says nothing about game RTTI, ownership, exception frames or playable
readiness.

Metadata comparison requires the canonical full reviewed fixture document; any changed semantic identity or other metadata remains unresolved pending separate review. Input ancestor link/reparse checks are best-effort, not atomic against concurrent changes; use a stable trusted local tree.

Additional synthetic review regressions: `tests/rtti-runtime-probe/test_independent_review.py`.

`tools/rtti-runtime-probe/native_compile_once.py` is the separate reviewed three-unit compile-only driver. Native execution remains separately reviewed and authorized.

`tools/rtti-runtime-probe/native_link_once.py` is the separately reviewed single synthetic link stage.

`tools/rtti-runtime-probe/native_run_once.py` is the separately reviewed hash-bound single execution and metadata-check stage.

A separate reviewed SP1 x86 synthetic phase subsequently compiled three units, linked a console fixture, and ran one and three cycles. The independent checker passed all 32 cases and seven required differing-address relations in each cycle. This is evidence only for that synthetic single-module configuration; it does not establish game ABI or playable readiness. See `RESULTS.md`.
