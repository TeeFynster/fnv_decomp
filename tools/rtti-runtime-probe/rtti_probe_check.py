#!/usr/bin/env python3
"""Independent checker for synthetic RTTI runtime-probe reports, and plan check.

Commands:
  check <report.json> [--metadata <fixture-metadata.json>] [--format text|json]
  compare-metadata <fixture-metadata.json> [--format text|json]
  check-plan <run-plan.json> [--format text|json]

`check` reads one `fnv-rtti-runtime-report` v1 document, as written by
driver/rtti_probe_main.cpp, and compares every observation with the reviewed
semantic matrix held in this file (MATRIX). It trusts none of the fixture's
own `expected`, `address_expected` or `passed` fields, nor the driver's stated
status: the fixture's claims are compared with the matrix and any disagreement
is reported as an unresolved conflict, and the driver's status is recomputed.
`kOutcomeNotRun`, missing or truncated output, and result_matches == -1 on a
case that must succeed never count as a pass. A layout-dependent address
change is recorded as an observation only, never as a guarantee or offset.

With `--metadata`, the fixture metadata is also compared with MATRIX and any
difference is reported as an unresolved conflict. Nothing is changed.

`check-plan` checks the authored build/link/run plan: placeholders instead of
paths, the exact reviewed commands, command hashes, bounded output, isolated
outputs and every result NOT_RUN. It never runs anything.

Only the files named on the command line are opened, read-only. No program is
started, no network is used, nothing is written except to stdout and stderr.
A report that passes here is consistent; whether it came from a native run is
established only by the coordinator's separate, private run record.

Python standard library only (3.10 or newer).
"""

from __future__ import annotations

import argparse
import errno
import hashlib
import json
import os
import re
import stat
import sys
from pathlib import Path

REPORT_SCHEMA = "fnv-rtti-runtime-report"
CHECK_SCHEMA = "fnv-rtti-runtime-check"
PLAN_SCHEMA = "fnv-rtti-runtime-plan"
METADATA_SCHEMA = "fnv-rtti-abi-metadata"
REVIEWED_METADATA_CANONICAL_SHA256 = "e32957288572389ffdae20dc2a7c4b192158b7b74535f81f551c1af0f092567c"
SCHEMA_VERSION = 1
FIXTURE_NAME = "rtti_abi_fixture_v1"
NOT_RUN = "NOT_RUN"

MAX_REPORT_BYTES = 64 * 1024   # equals the run step's stdout capture limit
MAX_METADATA_BYTES = 256 * 1024
MAX_PLAN_BYTES = 64 * 1024
MAX_DEPTH = 8
MAX_CYCLES = 3
MAX_CASES = 64
MAX_REPORTED = 50

EXIT_PASS = 0
EXIT_FAIL = 1
EXIT_USAGE = 2
EXIT_UNRESOLVED = 3

# ---------------------------------------------------------------- reviewed matrix
#
# One row per case, in the fixture's fixed order:
#   (id, form, input, outcome, address)
# form:    pointer | reference | void_pointer
# input:   object (a view of a live fixture object) | null (a null pointer)
# outcome: success | null | bad_cast
# address: must_differ | must_equal | layout_dependent | not_applicable
#
# Reviewed against tools/rtti-abi/expected-ABI.md section 2, the casts in
# fixture-metadata.json and the calls in rtti_consumer.cpp; the tests keep the
# three in step. It is written out here, not read from the fixture, so the
# checker does not depend on the fixture's own expectations.

MATRIX = (
    ("S01", "pointer", "object", "success", "layout_dependent"),
    ("S02", "pointer", "object", "null", "not_applicable"),
    ("S03", "pointer", "object", "success", "layout_dependent"),
    ("S04", "reference", "object", "bad_cast", "not_applicable"),
    ("S05", "reference", "object", "success", "layout_dependent"),
    ("S06", "pointer", "null", "null", "not_applicable"),
    ("S07", "void_pointer", "object", "success", "layout_dependent"),
    ("S08", "pointer", "object", "success", "layout_dependent"),
    ("M01", "pointer", "object", "success", "must_differ"),
    ("M02", "pointer", "object", "success", "must_differ"),
    ("M03", "pointer", "object", "success", "layout_dependent"),
    ("M04", "pointer", "object", "null", "not_applicable"),
    ("M05", "reference", "object", "bad_cast", "not_applicable"),
    ("M06", "reference", "object", "success", "must_differ"),
    ("M07", "pointer", "null", "null", "not_applicable"),
    ("M08", "void_pointer", "object", "success", "layout_dependent"),
    ("M09", "pointer", "object", "null", "not_applicable"),
    ("M10", "pointer", "object", "success", "layout_dependent"),
    ("V01", "pointer", "object", "success", "layout_dependent"),
    ("V02", "pointer", "object", "success", "must_differ"),
    ("V03", "pointer", "object", "success", "layout_dependent"),
    ("V04", "pointer", "object", "null", "not_applicable"),
    ("V05", "reference", "object", "bad_cast", "not_applicable"),
    ("V06", "reference", "object", "success", "must_differ"),
    ("V07", "pointer", "null", "null", "not_applicable"),
    ("V08", "pointer", "object", "success", "layout_dependent"),
    ("V09", "void_pointer", "object", "success", "layout_dependent"),
    ("A01", "pointer", "object", "null", "not_applicable"),
    ("A02", "reference", "object", "bad_cast", "not_applicable"),
    ("A03", "pointer", "object", "success", "layout_dependent"),
    ("A04", "pointer", "object", "success", "must_differ"),
    ("A05", "pointer", "object", "success", "must_differ"),
)
CASE_COUNT = 32
MATRIX_IDS = tuple(row[0] for row in MATRIX)
MATRIX_BY_ID = {row[0]: row for row in MATRIX}

# Fixture enum values (rtti_abi_fixture.h).
OUTCOME_CODE = {"not_run": 0, "success": 1, "null": 2, "bad_cast": 3}
OUTCOME_NAME = {v: k for k, v in OUTCOME_CODE.items()}
ADDRESS_CODE = {"not_applicable": -2, "layout_dependent": -1, "must_equal": 0, "must_differ": 1}

# Allowed field values in a report. Anything else is E-FIELD.
FIELD_VALUES = {
    "expected": (1, 2, 3),
    "address_expected": (-2, -1, 0, 1),
    "passed": (0, 1),
    "outcome": (0, 1, 2, 3),
    "result_matches": (-1, 0, 1),
    "address_changed": (-1, 0, 1),
}

# Metadata vocabulary (fnv-rtti-abi-metadata v1) mapped to the matrix's.
METADATA_ADDRESS = {"nonzero": "must_differ", "none": "must_equal",
                    "layout_dependent": "layout_dependent",
                    "not_applicable": "not_applicable", "unknown": None}

ORIGINS = ("driver", "synthetic")
STATUSES = ("completed", "create_failed", "views_invalid", "exception", "incomplete")
EXCEPTION_KINDS = ("none", "bad_alloc", "bad_cast", "std_exception", "unknown")
EXCEPTION_STAGES = ("none", "create", "run", "destroy")
DRIVER_EXIT = {"ok": 0, "case_failure": 1, "structure_failure": 3, "create_failed": 4,
               "exception": 5}

TOP_KEYS = ("schema", "schema_version", "origin", "fixture", "case_count_constant",
            "cycles_requested", "cycles", "driver_status", "driver_exit_code",
            "end_of_report")
CYCLE_KEYS = ("cycle", "status", "exception_kind", "exception_stage",
              "views_null_before_create", "create_calls", "create_returned",
              "views_all_set_after_create", "run_calls", "run_capacity", "run_returned",
              "guard_intact", "destroy_calls", "views_null_at_end", "destructor_count",
              "cases")
CASE_KEYS = ("id", "fixture_claims", "observed")
CLAIM_KEYS = ("expected", "address_expected", "passed")
OBSERVED_KEYS = ("outcome", "result_matches", "address_changed")
CYCLE_INTS = ("cycle", "create_calls", "run_calls", "run_capacity", "run_returned",
              "destroy_calls")
CYCLE_BOOLS = ("views_null_before_create", "create_returned", "views_all_set_after_create",
               "guard_intact", "views_null_at_end")

_CASE_ID = re.compile(r"[A-Z][0-9]{2}")
_HEX64 = re.compile(r"[0-9a-f]{64}")
_LOCAL_DEVICE = re.compile(
    r"(con|prn|aux|nul|com[0-9]|lpt[0-9]|conin\$|conout\$)(\..*)?", re.IGNORECASE)
_INT32 = (-2 ** 31, 2 ** 31 - 1)


class InputError(Exception):
    """The file was read but cannot be interpreted. ``errors`` holds findings."""

    def __init__(self, errors, total=None):
        super().__init__(f"{len(errors)} problem(s)")
        self.errors = list(errors)
        self.total = len(self.errors) if total is None else total


class UsageError(Exception):
    """Bad arguments or a file that cannot be used."""


# ---------------------------------------------------------------- findings

class _Findings:
    """Bounded, ordered list of (JSON pointer, code, message)."""

    def __init__(self):
        self.items = []
        self.total = 0

    def add(self, where, code, message):
        self.total += 1
        if len(self.items) < MAX_REPORTED:
            self.items.append((where or "/", code, message))

    def __bool__(self):
        return self.total > 0

    def raise_if_any(self):
        if self.total:
            raise InputError(self.items, self.total)


def _as_dicts(findings):
    return [{"where": w, "code": c, "message": m} for w, c, m in findings.items]


# ---------------------------------------------------------------- JSON input

class _DuplicateKey(ValueError):
    pass


def _pairs(pairs):
    out = {}
    for key, value in pairs:
        if key in out:
            raise _DuplicateKey()
        out[key] = value
    return out


def _reject_constant(_name):
    raise ValueError("non-finite number")


def _max_depth(text, limit):
    depth = deepest = 0
    in_string = escaped = False
    for ch in text:
        if in_string:
            if escaped:
                escaped = False
            elif ch == "\\":
                escaped = True
            elif ch == '"':
                in_string = False
        elif ch == '"':
            in_string = True
        elif ch in "[{":
            depth += 1
            if depth > deepest:
                deepest = depth
                if deepest > limit:
                    return deepest
        elif ch in "]}":
            depth -= 1
    return deepest


def parse_json_bytes(data, limit=MAX_REPORT_BYTES):
    """Decode bounded, strict JSON. Raise InputError on any problem."""
    def fail(code, message):
        raise InputError([("/", code, message)])

    if len(data) > limit:
        fail("E-LIMIT", f"input is larger than {limit} bytes")
    if not data.strip():
        fail("E-EMPTY", "input is empty; missing output never counts as a pass")
    if data.startswith(b"\xef\xbb\xbf"):
        fail("E-ENCODING", "input starts with a UTF-8 byte order mark")
    try:
        text = data.decode("utf-8")
    except UnicodeDecodeError:
        fail("E-ENCODING", "input is not valid UTF-8")
    if _max_depth(text, MAX_DEPTH) > MAX_DEPTH:
        fail("E-LIMIT", f"input nests deeper than {MAX_DEPTH} levels")
    try:
        return json.loads(text, object_pairs_hook=_pairs, parse_constant=_reject_constant)
    except _DuplicateKey:
        fail("E-DUPKEY", "duplicate JSON key (name not echoed)")
    except json.JSONDecodeError as exc:
        fail("E-JSON", f"malformed or truncated JSON at line {exc.lineno} column {exc.colno}")
    except (ValueError, RecursionError):
        fail("E-JSON", "malformed JSON (unsupported number or structure)")


# ---------------------------------------------------------------- schema helpers

def _is_int(value):
    return type(value) is int


def _keys(obj, where, required, errs):
    """Exact key set: every key required, unknown keys rejected (not echoed)."""
    if not isinstance(obj, dict):
        errs.add(where, "E-SCHEMA", "must be a JSON object")
        return False
    ok = True
    unknown = sum(1 for k in obj if k not in required)
    if unknown:
        errs.add(where, "E-SCHEMA", f"{unknown} unknown key(s); names not echoed")
        ok = False
    for key in required:
        if key not in obj:
            errs.add(where, "E-SCHEMA", f"missing required key {key!r}")
            ok = False
    return ok


def _need_int(obj, key, where, errs):
    value = obj[key]
    if not _is_int(value) or not _INT32[0] <= value <= _INT32[1]:
        errs.add(f"{where}/{key}", "E-SCHEMA", "must be a 32-bit integer")
        return False
    return True


def _need_bool(obj, key, where, errs):
    if type(obj[key]) is not bool:
        errs.add(f"{where}/{key}", "E-SCHEMA", "must be true or false")
        return False
    return True


def _need_enum(obj, key, where, allowed, errs):
    value = obj[key]
    if not isinstance(value, str) or value not in allowed:
        errs.add(f"{where}/{key}", "E-SCHEMA", "must be one of: " + ", ".join(allowed))
        return False
    return True


# ---------------------------------------------------------------- report schema

def _schema(doc):
    """Structural validation. Raise InputError (verdict INVALID) on any problem."""
    errs = _Findings()
    if not _keys(doc, "", TOP_KEYS, errs):
        errs.raise_if_any()
    if doc["schema"] != REPORT_SCHEMA:
        errs.add("/schema", "E-SCHEMA", f"schema must be {REPORT_SCHEMA!r}")
    if not _is_int(doc["schema_version"]) or doc["schema_version"] != SCHEMA_VERSION:
        errs.add("/schema_version", "E-VERSION",
                 f"only schema_version {SCHEMA_VERSION} is understood")
    errs.raise_if_any()

    _need_enum(doc, "origin", "", ORIGINS, errs)
    if not isinstance(doc["fixture"], str):
        errs.add("/fixture", "E-SCHEMA", "must be a string")
    for key in ("case_count_constant", "cycles_requested", "driver_exit_code"):
        _need_int(doc, key, "", errs)
    _need_enum(doc, "driver_status", "", tuple(DRIVER_EXIT), errs)
    _need_bool(doc, "end_of_report", "", errs)

    cycles = doc["cycles"]
    if not isinstance(cycles, list):
        errs.add("/cycles", "E-SCHEMA", "must be a JSON array")
        errs.raise_if_any()
    if len(cycles) > MAX_CYCLES:
        errs.add("/cycles", "E-LIMIT", f"more than {MAX_CYCLES} cycles")
        errs.raise_if_any()
    for ci, cycle in enumerate(cycles):
        cw = f"/cycles/{ci}"
        if not _keys(cycle, cw, CYCLE_KEYS, errs):
            continue
        for key in CYCLE_INTS:
            _need_int(cycle, key, cw, errs)
        for key in CYCLE_BOOLS:
            _need_bool(cycle, key, cw, errs)
        _need_enum(cycle, "status", cw, STATUSES, errs)
        _need_enum(cycle, "exception_kind", cw, EXCEPTION_KINDS, errs)
        _need_enum(cycle, "exception_stage", cw, EXCEPTION_STAGES, errs)
        if cycle["destructor_count"] != "unknown":
            errs.add(cw + "/destructor_count", "E-SCHEMA",
                     "must be \"unknown\": the fixture exposes no destructor count")
        cases = cycle["cases"]
        if not isinstance(cases, list):
            errs.add(cw + "/cases", "E-SCHEMA", "must be a JSON array")
            continue
        if len(cases) > MAX_CASES:
            errs.add(cw + "/cases", "E-LIMIT", f"more than {MAX_CASES} cases")
            continue
        for ki, case in enumerate(cases):
            kw = f"{cw}/cases/{ki}"
            if not _keys(case, kw, CASE_KEYS, errs):
                continue
            cid = case["id"]
            if cid is not None and not isinstance(cid, str):
                errs.add(kw + "/id", "E-SCHEMA", "must be a string or null")
            for part, keys in (("fixture_claims", CLAIM_KEYS), ("observed", OBSERVED_KEYS)):
                if _keys(case[part], f"{kw}/{part}", keys, errs):
                    for k in keys:
                        _need_int(case[part], k, f"{kw}/{part}", errs)
    errs.raise_if_any()


# ---------------------------------------------------------------- driver mirror

def _fields_ok(case):
    claims, obs = case["fixture_claims"], case["observed"]
    cid = case["id"]
    if not isinstance(cid, str) or not _CASE_ID.fullmatch(cid):
        return False
    return all(claims[k] in FIELD_VALUES[k] for k in CLAIM_KEYS) and \
        all(obs[k] in FIELD_VALUES[k] for k in OBSERVED_KEYS)


def _self_consistent(case):
    """The driver's case_self_consistent(): uses the fixture's own claims."""
    c, o = case["fixture_claims"], case["observed"]
    e, ae, p = c["expected"], c["address_expected"], c["passed"]
    out, rm, ac = o["outcome"], o["result_matches"], o["address_changed"]
    if out == 0 or out != e or p != 1:
        return False
    if e == 1:
        if rm != 1:
            return False
        if ae == 0:
            return ac == 0
        if ae == 1:
            return ac == 1
        if ae == -1:
            return ac in (0, 1)
        return False
    return rm == -1 and ac == -1 and ae == -2


def _cycle_structure_ok(cy):
    """The driver's cycle_structure_ok()."""
    if cy["status"] != "completed" or not cy["views_null_before_create"] \
            or cy["create_calls"] != 1 or not cy["create_returned"] \
            or not cy["views_all_set_after_create"] or cy["run_calls"] != 1 \
            or cy["run_returned"] != CASE_COUNT or not cy["guard_intact"] \
            or cy["destroy_calls"] != 1 or not cy["views_null_at_end"] \
            or len(cy["cases"]) != CASE_COUNT:
        return False
    return all(_fields_ok(c) and c["id"] == MATRIX_IDS[i] for i, c in enumerate(cy["cases"]))


def driver_status(doc):
    """Recompute the status the driver must have stated (overall_exit())."""
    cycles = doc["cycles"]
    saw_exception = create_failed = case_failure = False
    structure = len(cycles) < doc["cycles_requested"]
    for cy in cycles:
        if cy["status"] == "exception":
            saw_exception = True
        elif cy["status"] == "create_failed":
            create_failed = True
        elif not _cycle_structure_ok(cy):
            structure = True
        elif not all(_self_consistent(c) for c in cy["cases"]):
            case_failure = True
    if saw_exception:
        return "exception"
    if create_failed:
        return "create_failed"
    if structure:
        return "structure_failure"
    if case_failure:
        return "case_failure"
    return "ok"


# ---------------------------------------------------------------- semantics

def _check_lifecycle(cy, cw, fails):
    status = cy["status"]
    if status == "exception":
        fails.add(cw + "/status", "E-EXCEPTION",
                  f"an unexpected exception ({cy['exception_kind']}) was caught at stage "
                  f"{cy['exception_stage']}")
        if cy["exception_kind"] == "none" or cy["exception_stage"] == "none":
            fails.add(cw, "E-LIFECYCLE", "an exception cycle must name its kind and stage")
    elif status != "completed":
        fails.add(cw + "/status", "E-LIFECYCLE", f"cycle did not complete ({status})")
    if status != "exception" and (cy["exception_kind"] != "none"
                                  or cy["exception_stage"] != "none"):
        fails.add(cw, "E-LIFECYCLE", "exception fields are set on a cycle without exception")

    if not cy["views_null_before_create"]:
        fails.add(cw + "/views_null_before_create", "E-LIFECYCLE",
                  "the record passed to create_fixture_objects() was not fresh")
    if cy["create_calls"] != 1:
        fails.add(cw + "/create_calls", "E-LIFECYCLE",
                  "create_fixture_objects() must be called exactly once per cycle")
    if cy["create_returned"]:
        if cy["destroy_calls"] != 1:
            fails.add(cw + "/destroy_calls", "E-LIFECYCLE",
                      "destroy_fixture_objects() must be called exactly once after a "
                      "successful creation")
    else:
        if status == "completed":
            fails.add(cw + "/create_returned", "E-LIFECYCLE",
                      "a completed cycle needs a successful creation")
        partial = status == "exception" and cy["exception_stage"] == "create"
        if cy["destroy_calls"] > (1 if partial else 0) or cy["destroy_calls"] < 0:
            fails.add(cw + "/destroy_calls", "E-LIFECYCLE",
                      "destroy_fixture_objects() was called although creation failed")
    if not cy["views_null_at_end"]:
        fails.add(cw + "/views_null_at_end", "E-LIFECYCLE",
                  "fixture views were not all null after destruction")
    if cy["run_capacity"] != CASE_COUNT:
        fails.add(cw + "/run_capacity", "E-COUNT",
                  f"run_cast_cases() must be given capacity {CASE_COUNT}")
    if not cy["guard_intact"]:
        fails.add(cw + "/guard_intact", "E-GUARD",
                  "the result element past the capacity was written")

    if status == "completed":
        if not cy["views_all_set_after_create"]:
            fails.add(cw + "/views_all_set_after_create", "E-LIFECYCLE",
                      "a view was null after a successful creation")
        if cy["run_calls"] != 1:
            fails.add(cw + "/run_calls", "E-LIFECYCLE",
                      "run_cast_cases() must be called exactly once per cycle")
        if cy["run_returned"] != CASE_COUNT:
            fails.add(cw + "/run_returned", "E-COUNT",
                      f"run_cast_cases() must return {CASE_COUNT}")
    else:
        if cy["cases"]:
            fails.add(cw + "/cases", "E-COUNT", "cases are listed for a cycle that did not "
                      "complete")


def _check_case(case, row, kw, fails, conflicts):
    """Compare one case with its matrix row. Return the address observation or None."""
    _, _form, _input, outcome, address = row
    want_outcome = OUTCOME_CODE[outcome]
    want_address = ADDRESS_CODE[address]
    claims, obs = case["fixture_claims"], case["observed"]
    cid = case["id"]

    if claims["expected"] != want_outcome:
        conflicts.add(kw + "/fixture_claims/expected", "C-FIXTURE-EXPECTED",
                      f"{cid}: the fixture claims outcome {claims['expected']} "
                      f"({OUTCOME_NAME[claims['expected']]}); the reviewed matrix says "
                      f"{want_outcome} ({outcome}); left unresolved")
    if claims["address_expected"] != want_address:
        conflicts.add(kw + "/fixture_claims/address_expected", "C-FIXTURE-ADDRESS",
                      f"{cid}: the fixture claims address expectation "
                      f"{claims['address_expected']}; the reviewed matrix says {want_address} "
                      f"({address}); left unresolved")

    ok = True
    seen = obs["outcome"]
    rm, ac = obs["result_matches"], obs["address_changed"]
    if seen == OUTCOME_CODE["not_run"]:
        fails.add(kw + "/observed/outcome", "E-NOT-RUN",
                  f"{cid}: observed kOutcomeNotRun; a case that did not run never passes")
        ok = False
    elif seen != want_outcome:
        fails.add(kw + "/observed/outcome", "E-OUTCOME",
                  f"{cid}: observed {seen} ({OUTCOME_NAME[seen]}); the reviewed matrix "
                  f"requires {want_outcome} ({outcome})")
        ok = False
    elif outcome == "success":
        if rm == 0:
            fails.add(kw + "/observed/result_matches", "E-VIEW",
                      f"{cid}: the result is not the expected producer view")
            ok = False
        elif rm == -1:
            fails.add(kw + "/observed/result_matches", "E-VIEW",
                      f"{cid}: result_matches is -1 (not applicable) on a case that must "
                      "succeed; that is not evidence of a correct result")
            ok = False
        if ac == -1:
            fails.add(kw + "/observed/address_changed", "E-RELATION",
                      f"{cid}: the address relation is missing")
            ok = False
        elif address == "must_differ" and ac != 1:
            fails.add(kw + "/observed/address_changed", "E-RELATION",
                      f"{cid}: C++ requires the result address to differ from the input; "
                      "it did not")
            ok = False
        elif address == "must_equal" and ac != 0:
            fails.add(kw + "/observed/address_changed", "E-RELATION",
                      f"{cid}: C++ requires the result address to equal the input; it did not")
            ok = False
    else:
        if rm != -1 or ac != -1:
            fails.add(kw + "/observed", "E-NA",
                      f"{cid}: a {outcome} case must keep the fixture's not-applicable "
                      "values (result_matches -1, address_changed -1)")
            ok = False

    passed = claims["passed"]
    if passed == 1 and not ok:
        fails.add(kw + "/fixture_claims/passed", "E-FORGED-PASS",
                  f"{cid}: the fixture's passed=1 contradicts the observation; a stated "
                  "pass is not evidence")
    elif passed == 0 and ok:
        conflicts.add(kw + "/fixture_claims/passed", "C-FIXTURE-PASSED",
                      f"{cid}: the fixture reports passed=0 but the observation meets the "
                      "reviewed matrix; left unresolved")
    if ok and outcome == "success":
        return ac
    return None


def _check_cases(cy, cw, fails, conflicts):
    """Check ids and every case of one completed cycle. Return {id: address_changed}."""
    cases = cy["cases"]
    if len(cases) != CASE_COUNT:
        fails.add(cw + "/cases", "E-COUNT",
                  f"{len(cases)} cases listed; exactly {CASE_COUNT} are required")
    seen, observations, passes = set(), {}, 0
    for ki, case in enumerate(cases):
        kw = f"{cw}/cases/{ki}"
        cid = case["id"]
        if not isinstance(cid, str) or not _CASE_ID.fullmatch(cid):
            fails.add(kw + "/id", "E-ID", "case id is missing or malformed (not echoed)")
            continue
        if cid not in MATRIX_BY_ID:
            fails.add(kw + "/id", "E-ID", "case id is not a case of this fixture (not echoed)")
            continue
        if cid in seen:
            fails.add(kw + "/id", "E-DUP-ID", f"{cid}: duplicate case id")
            continue
        seen.add(cid)
        if ki >= CASE_COUNT or MATRIX_IDS[ki] != cid:
            fails.add(kw + "/id", "E-ORDER",
                      f"{cid}: out of the fixture's fixed order (position {ki})")
        bad = [k for k in CLAIM_KEYS if case["fixture_claims"][k] not in FIELD_VALUES[k]]
        bad += [k for k in OBSERVED_KEYS if case["observed"][k] not in FIELD_VALUES[k]]
        if bad:
            for k in bad:
                part = "fixture_claims" if k in CLAIM_KEYS else "observed"
                fails.add(f"{kw}/{part}/{k}", "E-FIELD",
                          f"{cid}: value outside the fixture's enum (not echoed)")
            continue
        before = fails.total
        ac = _check_case(case, MATRIX_BY_ID[cid], kw, fails, conflicts)
        if fails.total == before:
            passes += 1
        if ac is not None:
            observations[cid] = ac
    missing = [i for i in MATRIX_IDS if i not in seen]
    if missing:
        fails.add(cw + "/cases", "E-MISSING-ID", "missing case id(s): " + ", ".join(missing))
    return observations, passes


def _compare_metadata(meta, conflicts, fails):
    """Compare fixture metadata with MATRIX. Differences are conflicts."""
    where = "metadata:"
    if not isinstance(meta, dict) or meta.get("schema") != METADATA_SCHEMA \
            or meta.get("schema_version") != SCHEMA_VERSION \
            or not isinstance(meta.get("casts"), list):
        fails.add(where + "/", "E-METADATA",
                  f"not a {METADATA_SCHEMA} v{SCHEMA_VERSION} document with a casts array")
        return 0
    canonical = json.dumps(meta, sort_keys=True, separators=(",", ":"), ensure_ascii=True).encode("ascii")
    if hashlib.sha256(canonical).hexdigest() != REVIEWED_METADATA_CANONICAL_SHA256:
        conflicts.add(where + "/", "C-METADATA", "metadata differs from the exact reviewed fixture; full semantic identity is unverified")
    if meta.get("fixture") != FIXTURE_NAME:
        conflicts.add(where + "/fixture", "C-METADATA",
                      f"metadata names a different fixture than {FIXTURE_NAME!r}")
    casts = meta["casts"]
    if len(casts) > 4 * CASE_COUNT:
        fails.add(where + "/casts", "E-METADATA", "too many casts")
        return 0
    seen = {}
    compared = 0
    for i, cast in enumerate(casts):
        cw = f"{where}/casts/{i}"
        if not isinstance(cast, dict) or not isinstance(cast.get("id"), str):
            fails.add(cw, "E-METADATA", "cast entry without a string id")
            continue
        cid = cast["id"]
        if cid not in MATRIX_BY_ID:
            conflicts.add(cw + "/id", "C-METADATA", "cast id is not in the reviewed matrix "
                          "(not echoed)")
            continue
        if cid in seen:
            conflicts.add(cw + "/id", "C-METADATA", f"{cid}: listed more than once")
            continue
        seen[cid] = i
        _, form, inp, outcome, address = MATRIX_BY_ID[cid]
        compared += 1
        if cast.get("form") != form:
            conflicts.add(cw + "/form", "C-METADATA",
                          f"{cid}: metadata form differs from the reviewed matrix ({form})")
        null_input = isinstance(cast.get("input"), dict) and "null_of" in cast["input"]
        if null_input != (inp == "null"):
            conflicts.add(cw + "/input", "C-METADATA",
                          f"{cid}: metadata input kind differs from the reviewed matrix ({inp})")
        if cast.get("expect") != outcome:
            conflicts.add(cw + "/expect", "C-METADATA",
                          f"{cid}: metadata outcome differs from the reviewed matrix ({outcome})")
        adj = cast.get("adjustment")
        if adj not in METADATA_ADDRESS:
            conflicts.add(cw + "/adjustment", "C-METADATA",
                          f"{cid}: metadata adjustment is not a known value")
        elif METADATA_ADDRESS[adj] is not None and METADATA_ADDRESS[adj] != address:
            conflicts.add(cw + "/adjustment", "C-METADATA",
                          f"{cid}: metadata adjustment differs from the reviewed matrix "
                          f"({address})")
    missing = [i for i in MATRIX_IDS if i not in seen]
    if missing:
        conflicts.add(where + "/casts", "C-METADATA",
                      "matrix case(s) absent from metadata: " + ", ".join(missing))
    return compared


def check_report(doc, metadata=None):
    """Check a parsed report. Return a result dict; raise InputError if INVALID."""
    _schema(doc)
    fails, conflicts = _Findings(), _Findings()

    if doc["fixture"] != FIXTURE_NAME:
        fails.add("/fixture", "E-FIXTURE", f"report is not for {FIXTURE_NAME!r}")
    if doc["case_count_constant"] != CASE_COUNT:
        fails.add("/case_count_constant", "E-COUNT",
                  f"the driver was built against a fixture without {CASE_COUNT} cases")
    if doc["end_of_report"] is not True:
        fails.add("/end_of_report", "E-INCOMPLETE", "the report is not marked complete")

    requested = doc["cycles_requested"]
    cycles = doc["cycles"]
    if not 1 <= requested <= MAX_CYCLES:
        fails.add("/cycles_requested", "E-CYCLES", f"must be 1 to {MAX_CYCLES}")
    if len(cycles) != requested:
        fails.add("/cycles", "E-CYCLES",
                  f"{len(cycles)} cycle(s) reported for {requested} requested; missing "
                  "cycles never count as a pass")

    per_cycle, passes = [], []
    for ci, cy in enumerate(cycles):
        cw = f"/cycles/{ci}"
        if cy["cycle"] != ci + 1:
            fails.add(cw + "/cycle", "E-CYCLES", f"cycle number must be {ci + 1}")
        _check_lifecycle(cy, cw, fails)
        if cy["status"] == "completed":
            obs, n = _check_cases(cy, cw, fails, conflicts)
            per_cycle.append(obs)
            passes.append(n)
        else:
            per_cycle.append({})
            passes.append(0)

    # Address relations of one class layout cannot change between cycles.
    for cid in MATRIX_IDS:
        values = [obs[cid] for obs in per_cycle if cid in obs]
        if len(set(values)) > 1:
            fails.add("/cycles", "E-UNSTABLE",
                      f"{cid}: the address relation differs between cycles")

    stated = doc["driver_status"]
    recomputed = driver_status(doc)
    if stated != recomputed:
        fails.add("/driver_status", "E-DRIVER-STATUS",
                  f"the driver states {stated!r} but its own rules give {recomputed!r}; the "
                  "stated summary is not accepted")
    if doc["driver_exit_code"] != DRIVER_EXIT[stated]:
        fails.add("/driver_exit_code", "E-DRIVER-STATUS",
                  "the exit code does not match the stated driver status")
    if stated != "ok" and not fails and not conflicts:
        fails.add("/driver_status", "E-DRIVER-STATUS", f"the driver reported {stated!r}")

    metadata_compared = None
    if metadata is not None:
        metadata_compared = _compare_metadata(metadata, conflicts, fails)

    if fails:
        verdict = "FAIL"
    elif conflicts:
        verdict = "UNRESOLVED"
    else:
        verdict = "PASS"

    layout = {}
    for cid, _f, _i, _o, address in MATRIX:
        if address == "layout_dependent":
            layout[cid] = [("changed" if obs[cid] else "unchanged") if cid in obs else "none"
                           for obs in per_cycle]
    must_differ = [cid for cid, _f, _i, _o, a in MATRIX if a == "must_differ"]
    held = [sum(1 for cid in must_differ if obs.get(cid) == 1) for obs in per_cycle]
    return {
        "schema": CHECK_SCHEMA,
        "schema_version": SCHEMA_VERSION,
        "verdict": verdict,
        "origin": doc["origin"],
        "native_evidence": "not established by this checker",
        "cycles_requested": requested,
        "cycles_reported": len(cycles),
        "cases_required_per_cycle": CASE_COUNT,
        "cases_meeting_matrix": passes,
        "must_differ_required": len(must_differ),
        "must_differ_held": held,
        "layout_dependent_observations": layout,
        "lifecycle": {
            "create_calls": [cy["create_calls"] for cy in cycles],
            "destroy_calls": [cy["destroy_calls"] for cy in cycles],
            "views_null_at_end": [cy["views_null_at_end"] for cy in cycles],
            "destructor_count": "unknown",
        },
        "driver_status_stated": stated,
        "driver_status_recomputed": recomputed,
        "metadata_casts_compared": metadata_compared,
        "failures": _as_dicts(fails),
        "failures_total": fails.total,
        "conflicts": _as_dicts(conflicts),
        "conflicts_total": conflicts.total,
    }


def compare_metadata(meta):
    fails, conflicts = _Findings(), _Findings()
    n = _compare_metadata(meta, conflicts, fails)
    verdict = "FAIL" if fails else "UNRESOLVED" if conflicts else "PASS"
    return {"schema": CHECK_SCHEMA, "schema_version": SCHEMA_VERSION, "verdict": verdict,
            "metadata_casts_compared": n, "failures": _as_dicts(fails),
            "failures_total": fails.total, "conflicts": _as_dicts(conflicts),
            "conflicts_total": conflicts.total}


def _finding_lines(result):
    lines = []
    for title, key in (("failures", "failures"), ("unresolved conflicts", "conflicts")):
        total = result[key + "_total"]
        if total:
            shown = len(result[key])
            lines.append(f"{title}: {total} ({shown} shown)")
            lines.extend(f"  {f['where']}: {f['code']}: {f['message']}" for f in result[key])
    return lines


def report_lines(r):
    synthetic = r["origin"] == "synthetic"
    tag = " [synthetic sample: not native evidence]" if synthetic else ""
    held = ", ".join(str(n) for n in r["cases_meeting_matrix"]) or "none"
    lines = [f"{r['verdict']}{tag}: {r['cycles_reported']} of {r['cycles_requested']} "
             f"cycle(s); cases meeting the reviewed matrix per cycle: {held} "
             f"(of {r['cases_required_per_cycle']})."]
    lines.append("  must-differ relations held per cycle: "
                 + (", ".join(str(n) for n in r["must_differ_held"]) or "none")
                 + f" (of {r['must_differ_required']}).")
    changed = sum(v.count("changed") for v in r["layout_dependent_observations"].values())
    unchanged = sum(v.count("unchanged") for v in r["layout_dependent_observations"].values())
    lines.append(f"  layout-dependent observations: {changed} changed, {unchanged} unchanged "
                 "(observations only; no offset or guarantee follows).")
    lc = r["lifecycle"]
    lines.append(f"  lifecycle: create calls {lc['create_calls']}, destroy calls "
                 f"{lc['destroy_calls']}, views null at end {lc['views_null_at_end']}; "
                 "destructor count unknown.")
    lines.append(f"  driver status stated {r['driver_status_stated']!r}, recomputed "
                 f"{r['driver_status_recomputed']!r} (the stated status is not trusted).")
    if r["metadata_casts_compared"] is not None:
        lines.append(f"  metadata casts compared with the matrix: {r['metadata_casts_compared']}.")
    lines.extend(_finding_lines(r))
    lines.append("Note: this checks the report only. It is native evidence only together "
                 "with the coordinator's private run record (exit code, hashes, identities).")
    return lines


def metadata_lines(r):
    return [f"{r['verdict']}: metadata casts compared with the reviewed matrix: "
            f"{r['metadata_casts_compared']} (of {CASE_COUNT})."] + _finding_lines(r)


# ---------------------------------------------------------------- run plan

P_CL = "<CALLER_SUPPLIED_CL_EXE>"
P_LINK = "<CALLER_SUPPLIED_LINK_EXE>"
P_PYTHON = "<CALLER_SUPPLIED_PYTHON_EXE>"
P_VC_INCLUDE = "<CALLER_SUPPLIED_VC_INCLUDE>"
P_VC_LIB = "<CALLER_SUPPLIED_VC_LIB>"
P_SDK_LIB = "<CALLER_SUPPLIED_SDK_LIB>"
P_TOOL_PATH = "<CALLER_SUPPLIED_TOOL_PATH>"
P_SYSTEMROOT = "<CALLER_SUPPLIED_SYSTEMROOT>"
P_TEMP = "<PRIVATE_TEMP_DIR>"
P_OUT = "<PRIVATE_OUT_DIR>"
P_CWD = "<REVIEWED_CHECKOUT_ROOT>"
VARIANT = "od_mt"

FIXTURE_DIR = "tools/rtti-abi/fixture"
SRC_HEADER = FIXTURE_DIR + "/rtti_abi_fixture.h"
SRC_PRODUCER = FIXTURE_DIR + "/rtti_producer.cpp"
SRC_CONSUMER = FIXTURE_DIR + "/rtti_consumer.cpp"
SRC_METADATA = FIXTURE_DIR + "/fixture-metadata.json"
SRC_DRIVER = "tools/rtti-runtime-probe/driver/rtti_probe_main.cpp"
SRC_CHECKER = "tools/rtti-runtime-probe/rtti_probe_check.py"
PLAN_SOURCES = (
    (SRC_HEADER, "fixture_header"),
    (SRC_PRODUCER, "fixture_source"),
    (SRC_CONSUMER, "fixture_source"),
    (SRC_METADATA, "fixture_metadata"),
    (SRC_DRIVER, "driver_source"),
    (SRC_CHECKER, "checker"),
)

OBJ_DIR = f"{P_OUT}/{VARIANT}/obj"
EXE = f"{P_OUT}/{VARIANT}/bin/rtti_probe.exe"
COMPILE_FLAGS_A = ("/nologo", "/c", "/TP", "/X", "/I" + P_VC_INCLUDE)
COMPILE_FLAGS_B = ("/GR", "/EHsc", "/W4", "/Od", "/MT")
LINK_FLAGS = ("/NOLOGO", "/MACHINE:X86", "/SUBSYSTEM:CONSOLE", "/INCREMENTAL:NO",
              "/MANIFEST:NO")
RUN_TIMEOUT = 30
BUILD_TIMEOUT = 120
STDOUT_LIMIT = MAX_REPORT_BYTES
STDERR_LIMIT = 16 * 1024

PLAN_IDENTITY = (
    "compiler_sha256", "compiler_version_banner", "front_end_sha256", "back_end_sha256",
    "linker_sha256", "linker_version_banner", "pdb_support_dll_sha256",
    "static_crt_library_sha256", "sdk_kernel32_library_sha256",
    "include_dir_listing_sha256", "library_dir_listing_sha256", "source_sha256_at_run",
    "object_sha256", "executable_sha256", "substituted_command_sha256", "python_version",
)
NATIVE_RECORD_FIELDS = (
    "step_id", "substituted_command_sha256", "started", "exit_code", "timed_out",
    "wall_seconds", "stdout_bytes", "stdout_sha256", "stdout_truncated", "stderr_bytes",
    "stderr_sha256", "stderr_truncated",
)
PLAN_FORBIDDEN = (
    "discover_compiler", "install_toolchain", "run_without_coordinator_review",
    "use_game_files_or_assets", "use_game_addresses_or_aliases", "inspect_binary_bytes",
    "modify_fixture_files", "change_dll_search_path", "network_access",
    "commit_native_outputs",
)
ACCEPTANCE = (
    "every build step exits 0 within its timeout and output limits",
    "the run step exits within its timeout, with stdout and stderr not truncated",
    "the run step's exit code equals the report's driver_exit_code",
    "the check step prints PASS with --metadata, without the synthetic tag",
    "a PASS covers only this fixture with this compiler, flags and static runtime",
)
SCOPE_LIMITS = (
    "tests only this synthetic fixture with the selected compiler and runtime configuration",
    "is not evidence of retained game RTTI, object ownership, exception frames, "
    "cross-module behaviour or playable readiness",
    "the separate local COFF metadata measurement is outside this plan",
)

# Arguments that would link or run from cl, change RTTI, EH or the CRT, emit
# debug, listing or browse output, or read extra input. cl options are
# case-sensitive. The second group needs a word end, because /E is a prefix of
# the required /EHsc.
_FORBIDDEN_CL = re.compile(
    r"@|[/-](link|clr|analyze|Fe|Fa|FA|Fd|Fp|FR|Fr|FI|FU|AI|D|U|Yc|Yu|Zi|ZI|Z7"
    r"|GR-|EHa|EHs-|EHc-|LD|MD|MTd)|[/-](E|EP|P)(?![A-Za-z])")
# Linker options (case-insensitive) that would change entry, exports, default
# libraries, debug or map output, or read extra input.
_FORBIDDEN_LINK = re.compile(
    r"@|[/-](DLL|DEF|EXPORT|INCLUDE:|NODEFAULTLIB|DEFAULTLIB|FORCE|ALTERNATENAME|DEBUG|MAP"
    r"|PDB|ASSEMBLY|CLRIMAGETYPE|DELAYLOAD|ENTRY|IMPLIB|MANIFESTUAC|MANIFESTFILE|SECTION"
    r"|STUB|LTCG|ORDER|BASE|FIXED|MERGE|OPT:|PROFILE)", re.IGNORECASE)
_LITERAL_PATH = re.compile(
    r"(^|[^A-Za-z])[A-Za-z]:[\\/]|\\\\|\.\.|(^|[\s=:])/(home|Users|tmp|mnt|var|opt|root)/")


def command_sha256(argv):
    """SHA-256 of the canonical JSON form of an argv template."""
    text = json.dumps(list(argv), separators=(",", ":"), ensure_ascii=True)
    return hashlib.sha256(text.encode("ascii")).hexdigest()


def _compile_step(step_id, source, obj, extra=()):
    argv = [P_CL, *COMPILE_FLAGS_A, *extra, *COMPILE_FLAGS_B, f"/Fo{OBJ_DIR}/{obj}", source]
    return {"id": step_id, "kind": "compile", "environment": "build", "cwd": P_CWD,
            "argv": argv, "inputs": [source, SRC_HEADER], "outputs": [f"{OBJ_DIR}/{obj}"],
            "stdin": "null_device", "timeout_seconds": BUILD_TIMEOUT,
            "stdout_limit_bytes": STDOUT_LIMIT, "stderr_limit_bytes": STDERR_LIMIT,
            "command_sha256": command_sha256(argv), "result": NOT_RUN}


def _run_step(step_id, cycles, run_dir):
    argv = [EXE, "--cycles", str(cycles)]
    return {"id": step_id, "kind": "run", "environment": "run", "cwd": run_dir,
            "argv": argv, "inputs": [EXE],
            "outputs": [f"{run_dir}/stdout.json", f"{run_dir}/stderr.txt"],
            "stdin": "null_device", "timeout_seconds": RUN_TIMEOUT,
            "stdout_limit_bytes": STDOUT_LIMIT, "stderr_limit_bytes": STDERR_LIMIT,
            "command_sha256": command_sha256(argv), "result": NOT_RUN}


def _check_step(step_id, run_dir):
    argv = [P_PYTHON, "-I", SRC_CHECKER, "check", f"{run_dir}/stdout.json",
            "--metadata", SRC_METADATA]
    return {"id": step_id, "kind": "check", "environment": "check", "cwd": P_CWD,
            "argv": argv, "inputs": [f"{run_dir}/stdout.json", SRC_METADATA, SRC_CHECKER],
            "outputs": [f"{run_dir}/check.txt"], "stdin": "null_device",
            "timeout_seconds": RUN_TIMEOUT, "stdout_limit_bytes": STDOUT_LIMIT,
            "stderr_limit_bytes": STDERR_LIMIT, "command_sha256": command_sha256(argv),
            "result": NOT_RUN}


def canonical_plan(source_hashes):
    """The reviewed plan. ``source_hashes`` maps each PLAN_SOURCES path to sha256_lf."""
    objs = [f"{OBJ_DIR}/rtti_producer.obj", f"{OBJ_DIR}/rtti_consumer.obj",
            f"{OBJ_DIR}/rtti_probe_main.obj"]
    link_argv = [P_LINK, *LINK_FLAGS, f"/OUT:{EXE}", f"/LIBPATH:{P_VC_LIB}",
                 f"/LIBPATH:{P_SDK_LIB}", *objs]
    run1 = f"{P_OUT}/{VARIANT}/run-1"
    run3 = f"{P_OUT}/{VARIANT}/run-3"
    steps = [
        _compile_step("compile_producer", SRC_PRODUCER, "rtti_producer.obj"),
        _compile_step("compile_consumer", SRC_CONSUMER, "rtti_consumer.obj"),
        _compile_step("compile_driver", SRC_DRIVER, "rtti_probe_main.obj",
                      ("/I" + FIXTURE_DIR,)),
        {"id": "link", "kind": "link", "environment": "build", "cwd": P_CWD,
         "argv": link_argv, "inputs": objs, "outputs": [EXE], "stdin": "null_device",
         "timeout_seconds": BUILD_TIMEOUT, "stdout_limit_bytes": STDOUT_LIMIT,
         "stderr_limit_bytes": STDERR_LIMIT, "command_sha256": command_sha256(link_argv),
         "result": NOT_RUN},
        _run_step("run_one_cycle", 1, run1),
        _check_step("check_one_cycle", run1),
        _run_step("run_three_cycles", 3, run3),
        _check_step("check_three_cycles", run3),
    ]
    return {
        "schema": PLAN_SCHEMA,
        "schema_version": SCHEMA_VERSION,
        "status": NOT_RUN,
        "authorization": "coordinator_review_required",
        "variant": VARIANT,
        "toolchain": {
            "expected_product": "msvc_2008_sp1_x86",
            "selection": ["caller_supplied_path", "private_doctor_report"],
            "automatic_discovery": False,
            "install": False,
            "trusted_before_review": False,
            "placeholders": {"compiler": P_CL, "linker": P_LINK, "python": P_PYTHON,
                             "vc_include": P_VC_INCLUDE, "vc_lib": P_VC_LIB,
                             "sdk_lib": P_SDK_LIB},
        },
        "cwd": P_CWD,
        "output_root": P_OUT,
        "output_in_repository": False,
        "sources": [{"path": p, "role": r, "sha256_lf": source_hashes[p]}
                    for p, r in PLAN_SOURCES],
        "object_reuse": {
            "default": "compile_from_source",
            "alternative": "reuse_approved_compile_only_objects",
            "alternative_requires": [
                "coordinator approval of the specific objects",
                "the same compiler identity as recorded for those objects",
                "the same compile flags as compile_producer and compile_consumer",
                "matching source sha256 for the header, producer and consumer",
                "object sha256 recorded before and after copying",
            ],
            "result": NOT_RUN,
        },
        "environments": {
            "build": {"inherit": False,
                      "set": {"PATH": P_TOOL_PATH, "TMP": P_TEMP, "TEMP": P_TEMP,
                              "SystemRoot": P_SYSTEMROOT},
                      "unset": ["CL", "_CL_", "LINK", "_LINK_", "INCLUDE", "LIB", "LIBPATH"]},
            "run": {"inherit": False, "set": {"SystemRoot": P_SYSTEMROOT}, "unset": []},
            "check": {"inherit": False, "set": {"SystemRoot": P_SYSTEMROOT},
                      "unset": ["PYTHONPATH", "PYTHONHOME", "PYTHONSTARTUP"]},
        },
        "steps": steps,
        "identity": [{"item": i, "value": NOT_RUN} for i in PLAN_IDENTITY],
        "native_record": {
            "location": f"{P_OUT}/native-run-record.json",
            "in_repository": False,
            "kept_apart_from": ["tools/rtti-runtime-probe/run-plan.json",
                                "tests/rtti-runtime-probe/samples"],
            "fields_per_step": list(NATIVE_RECORD_FIELDS),
            "status": NOT_RUN,
        },
        "acceptance": list(ACCEPTANCE),
        "scope_limits": list(SCOPE_LIMITS),
        "forbidden_operations": list(PLAN_FORBIDDEN),
    }


def _diff(actual, expected, where, errs):
    if isinstance(expected, dict):
        if not isinstance(actual, dict):
            errs.add(where or "/", "E-PLAN-DIFF", "must be a JSON object")
            return
        extra = sum(1 for k in actual if k not in expected)
        if extra:
            errs.add(where or "/", "E-PLAN-DIFF", f"{extra} unknown key(s); names not echoed")
        for key, value in expected.items():
            if key not in actual:
                errs.add(f"{where}/{key}", "E-PLAN-DIFF", "missing")
            else:
                _diff(actual[key], value, f"{where}/{key}", errs)
    elif isinstance(expected, list):
        if not isinstance(actual, list) or len(actual) != len(expected):
            errs.add(where, "E-PLAN-DIFF", f"must be an array of {len(expected)} entries")
            return
        for i, (a, e) in enumerate(zip(actual, expected)):
            _diff(a, e, f"{where}/{i}", errs)
    elif type(actual) is not type(expected) or actual != expected:
        errs.add(where, "E-PLAN-DIFF", "differs from the reviewed plan (value not echoed)")


def _walk_strings(value, where):
    if isinstance(value, dict):
        for k, v in value.items():
            yield from _walk_strings(v, f"{where}/<key>")
    elif isinstance(value, list):
        for i, v in enumerate(value):
            yield from _walk_strings(v, f"{where}/{i}")
    elif isinstance(value, str):
        yield where, value


def validate_plan(doc):
    """Validate a parsed run plan. Return a summary dict or raise InputError."""
    errs = _Findings()
    if not isinstance(doc, dict):
        errs.add("/", "E-SCHEMA", "must be a JSON object")
        errs.raise_if_any()

    # Safety properties first, with specific codes.
    for where, text in _walk_strings(doc, ""):
        if _LITERAL_PATH.search(text):
            errs.add(where, "E-PLAN-PATH", "a literal, absolute or parent-relative path is "
                     "not allowed; use a placeholder or a checkout-relative path")
    for key in ("status",):
        if doc.get(key) != NOT_RUN:
            errs.add("/" + key, "E-NOT-RUN", "the plan status must be NOT_RUN")
    steps = doc.get("steps") if isinstance(doc.get("steps"), list) else []
    for si, step in enumerate(steps):
        if not isinstance(step, dict):
            continue
        sw = f"/steps/{si}"
        if step.get("result") != NOT_RUN:
            errs.add(sw + "/result", "E-NOT-RUN", "every step result must be NOT_RUN")
        argv = step.get("argv")
        if isinstance(argv, list) and all(isinstance(a, str) for a in argv):
            pattern = {"compile": _FORBIDDEN_CL, "link": _FORBIDDEN_LINK}.get(step.get("kind"))
            for ai, arg in enumerate(argv[1:], 1):
                if pattern is not None and pattern.match(arg):
                    errs.add(f"{sw}/argv/{ai}", "E-PLAN-FORBIDDEN",
                             "argument would change RTTI, EH, the runtime, the entry point or "
                             "default libraries, emit debug or listing output, or read "
                             "extra input")
            if step.get("command_sha256") != command_sha256(argv):
                errs.add(sw + "/command_sha256", "E-PLAN-HASH",
                         "does not match the step's argv")
    for i, item in enumerate(doc.get("identity") or ()):
        if isinstance(item, dict) and item.get("value") != NOT_RUN:
            errs.add(f"/identity/{i}/value", "E-NOT-RUN", "identity values must be NOT_RUN")
    for path in ("native_record", "object_reuse"):
        part = doc.get(path)
        if isinstance(part, dict):
            key = "status" if path == "native_record" else "result"
            if part.get(key) != NOT_RUN:
                errs.add(f"/{path}/{key}", "E-NOT-RUN", "must be NOT_RUN")
    if isinstance(doc.get("native_record"), dict) \
            and doc["native_record"].get("in_repository") is not False:
        errs.add("/native_record/in_repository", "E-PLAN",
                 "a native run record must be kept outside the repository")

    # Source hashes are checked for form; the tests compare them with the files.
    hashes = {}
    srcs = doc.get("sources")
    if isinstance(srcs, list):
        for i, item in enumerate(srcs):
            if isinstance(item, dict) and isinstance(item.get("path"), str):
                h = item.get("sha256_lf")
                if not isinstance(h, str) or not _HEX64.fullmatch(h):
                    errs.add(f"/sources/{i}/sha256_lf", "E-PLAN",
                             "must be 64 lowercase hex digits")
                hashes[item["path"]] = h
    canonical = canonical_plan({p: hashes.get(p, "") for p, _r in PLAN_SOURCES})
    for i, (p, _r) in enumerate(PLAN_SOURCES):
        if isinstance(hashes.get(p), str):
            canonical["sources"][i]["sha256_lf"] = hashes[p]
    _diff(doc, canonical, "", errs)
    errs.raise_if_any()
    kinds = [s["kind"] for s in doc["steps"]]
    return {"schema": PLAN_SCHEMA, "schema_version": SCHEMA_VERSION, "valid": True,
            "status": NOT_RUN, "compile_steps": kinds.count("compile"),
            "link_steps": kinds.count("link"), "run_steps": kinds.count("run"),
            "check_steps": kinds.count("check"), "results": NOT_RUN,
            "executed_by_this_tool": False,
            "note": "Plan only. Running any step needs the coordinator's separate review "
                    "of the exact substituted commands, toolchain and environment."}


def plan_lines(s):
    return [
        f"OK: run plan is valid ({PLAN_SCHEMA} v{SCHEMA_VERSION}): {s['compile_steps']} "
        f"compile, {s['link_steps']} link, {s['run_steps']} run and {s['check_steps']} "
        "check steps.",
        "Status and every result: NOT_RUN. This tool did not run anything.",
        s["note"],
    ]


# ---------------------------------------------------------------- files and CLI

def _is_link(st):
    return stat.S_ISLNK(st.st_mode) or bool(getattr(st, "st_file_attributes", 0) & 0x400)


def _errname(exc):
    return errno.errorcode.get(exc.errno or 0, type(exc).__name__)


def read_input(path, limit, what="input"):
    """Read one explicitly named file (bounded). Return bytes. Paths are never echoed."""
    if not path or "\x00" in path:
        raise UsageError(f"{what} path is empty or contains NUL")
    if path.startswith(("\\\\", "//")):
        raise UsageError(f"{what} path is a UNC or device path; use a local path")
    if any(_LOCAL_DEVICE.fullmatch(part.rstrip(" .")) for part in re.split(r"[\\/]", path)):
        raise UsageError(f"{what} path is a reserved device name")
    try:
        for ancestor in reversed(Path(os.path.abspath(path)).parents):
            if _is_link(os.lstat(ancestor)):
                raise UsageError(f"{what} ancestor is a link or reparse point")
        st = os.lstat(path)
    except FileNotFoundError:
        raise UsageError(f"{what} not found") from None
    except OSError as exc:
        raise UsageError(f"{what} cannot be read ({_errname(exc)})") from None
    if _is_link(st):
        raise UsageError(f"{what} is a link; pass the file itself")
    if not stat.S_ISREG(st.st_mode):
        raise UsageError(f"{what} is not a regular file")
    if st.st_size > limit:
        raise InputError([("/", "E-LIMIT", f"{what} is larger than {limit} bytes")])
    try:
        with open(path, "rb") as fh:
            return fh.read(limit + 1)
    except OSError as exc:
        raise UsageError(f"{what} cannot be read ({_errname(exc)})") from None


class _Parser(argparse.ArgumentParser):
    def error(self, message):  # never echo argument values (they may be paths)
        raise UsageError("invalid arguments; run with --help")


def _parser():
    p = _Parser(prog="rtti_probe_check.py",
                description="Check a synthetic RTTI runtime-probe report, compare fixture "
                            "metadata with the reviewed matrix, or check the run plan.")
    sub = p.add_subparsers(dest="command", required=True, parser_class=_Parser)
    c = sub.add_parser("check", help="check a runtime-probe report")
    c.add_argument("input")
    c.add_argument("--metadata", default=None)
    c.add_argument("--format", choices=("text", "json"), default="text")
    m = sub.add_parser("compare-metadata", help="compare fixture metadata with the matrix")
    m.add_argument("input")
    m.add_argument("--format", choices=("text", "json"), default="text")
    k = sub.add_parser("check-plan", help="check the run plan (never runs it)")
    k.add_argument("input")
    k.add_argument("--format", choices=("text", "json"), default="text")
    return p


_EXIT_FOR = {"PASS": EXIT_PASS, "FAIL": EXIT_FAIL, "UNRESOLVED": EXIT_UNRESOLVED}


def main(argv=None, stdout=None, stderr=None):
    stdout = stdout or sys.stdout
    stderr = stderr or sys.stderr
    try:
        args = _parser().parse_args(argv)
        if args.command == "check":
            doc = parse_json_bytes(read_input(args.input, MAX_REPORT_BYTES, "report"))
            meta = None
            if args.metadata is not None:
                try:
                    meta = parse_json_bytes(
                        read_input(args.metadata, MAX_METADATA_BYTES, "metadata"),
                        MAX_METADATA_BYTES)
                except InputError as exc:
                    raise InputError([("metadata:" + w, c, m) for w, c, m in exc.errors],
                                     exc.total) from None
            result, lines = check_report(doc, meta), report_lines
            code = _EXIT_FOR[result["verdict"]]
        elif args.command == "compare-metadata":
            meta = parse_json_bytes(read_input(args.input, MAX_METADATA_BYTES, "metadata"),
                                    MAX_METADATA_BYTES)
            result, lines = compare_metadata(meta), metadata_lines
            code = _EXIT_FOR[result["verdict"]]
        else:
            doc = parse_json_bytes(read_input(args.input, MAX_PLAN_BYTES, "plan"),
                                   MAX_PLAN_BYTES)
            result, lines, code = validate_plan(doc), plan_lines, EXIT_PASS
        if args.format == "json":
            stdout.write(json.dumps(result, indent=2, sort_keys=True) + "\n")
        else:
            stdout.write("\n".join(lines(result)) + "\n")
        return code
    except InputError as exc:
        shown = len(exc.errors)
        if getattr(args, "format", "text") == "json":
            stdout.write(json.dumps({"schema": CHECK_SCHEMA, "schema_version": SCHEMA_VERSION,
                                     "verdict": "INVALID",
                                     "failures": [{"where": w, "code": c, "message": m}
                                                  for w, c, m in exc.errors],
                                     "failures_total": exc.total},
                                    indent=2, sort_keys=True) + "\n")
        else:
            stdout.write(f"INVALID: input rejected ({exc.total} problem(s), {shown} shown); "
                         "an invalid report never counts as a pass.\n")
            for where, code, message in exc.errors:
                stdout.write(f"  {where}: {code}: {message}\n")
        return EXIT_FAIL
    except UsageError as exc:
        stderr.write(f"ERROR: {exc}\n")
        return EXIT_USAGE


if __name__ == "__main__":
    sys.exit(main())
