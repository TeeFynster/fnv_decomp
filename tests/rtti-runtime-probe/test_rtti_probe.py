"""Synthetic tests for the RTTI runtime probe: checker, plan, driver source, docs.

Every report used here is invented. Synthetic reports exercise the checker
only; they are not native evidence of any compile, link, run or cast result.

Run from the checkout root:
    python -m unittest discover -s tests/rtti-runtime-probe -p "test_*.py" -v
"""

import ast
import builtins
import copy
import hashlib
import importlib.util
import io
import json
import os
import pathlib
import re
import tempfile
import unittest

HERE = pathlib.Path(__file__).resolve().parent
ROOT = HERE.parents[1]
TOOL_DIR = ROOT / "tools" / "rtti-runtime-probe"
TOOL = TOOL_DIR / "rtti_probe_check.py"
DRIVER = TOOL_DIR / "driver" / "rtti_probe_main.cpp"
PLAN = TOOL_DIR / "run-plan.json"
FIXTURE_DIR = ROOT / "tools" / "rtti-abi" / "fixture"
HEADER = FIXTURE_DIR / "rtti_abi_fixture.h"
CONSUMER = FIXTURE_DIR / "rtti_consumer.cpp"
PRODUCER = FIXTURE_DIR / "rtti_producer.cpp"
METADATA = FIXTURE_DIR / "fixture-metadata.json"
EXPECTED_ABI = ROOT / "tools" / "rtti-abi" / "expected-ABI.md"
SAMPLES = HERE / "samples"


def _load_tool():
    spec = importlib.util.spec_from_file_location("rtti_probe_check_under_test", TOOL)
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    return mod


chk = _load_tool()

# ---------------------------------------------------------------- hand matrix
#
# Written out again here, independently of the checker's MATRIX, from the case
# table in tools/rtti-abi/expected-ABI.md. Address: D must differ, L layout
# dependent, N not applicable. Input: O object view, Z null pointer.

HAND = """
S01 pointer O success L
S02 pointer O null N
S03 pointer O success L
S04 reference O bad_cast N
S05 reference O success L
S06 pointer Z null N
S07 void_pointer O success L
S08 pointer O success L
M01 pointer O success D
M02 pointer O success D
M03 pointer O success L
M04 pointer O null N
M05 reference O bad_cast N
M06 reference O success D
M07 pointer Z null N
M08 void_pointer O success L
M09 pointer O null N
M10 pointer O success L
V01 pointer O success L
V02 pointer O success D
V03 pointer O success L
V04 pointer O null N
V05 reference O bad_cast N
V06 reference O success D
V07 pointer Z null N
V08 pointer O success L
V09 void_pointer O success L
A01 pointer O null N
A02 reference O bad_cast N
A03 pointer O success L
A04 pointer O success D
A05 pointer O success D
"""
_ADDR = {"D": "must_differ", "L": "layout_dependent", "N": "not_applicable"}
_INP = {"O": "object", "Z": "null"}
HAND_ROWS = tuple((a, b, _INP[c], d, _ADDR[e])
                  for a, b, c, d, e in (line.split() for line in HAND.strip().splitlines()))
IDS = tuple(r[0] for r in HAND_ROWS)
ROW = {r[0]: r for r in HAND_ROWS}
OUT = {"not_run": 0, "success": 1, "null": 2, "bad_cast": 3}
ADDR = {"not_applicable": -2, "layout_dependent": -1, "must_equal": 0, "must_differ": 1}
MUST_DIFFER = tuple(r[0] for r in HAND_ROWS if r[4] == "must_differ")
LAYOUT = tuple(r[0] for r in HAND_ROWS if r[4] == "layout_dependent")
FAILURE_CASES = tuple(r[0] for r in HAND_ROWS if r[3] != "success")

# ---------------------------------------------------------------- synthetic reports


def make_case(cid, layout_changed=0):
    _id, _form, _inp, outcome, address = ROW[cid]
    if outcome == "success":
        ac = 1 if address == "must_differ" else layout_changed
        observed = {"outcome": 1, "result_matches": 1, "address_changed": ac}
    else:
        observed = {"outcome": OUT[outcome], "result_matches": -1, "address_changed": -1}
    claims = {"expected": OUT[outcome], "address_expected": ADDR[address], "passed": 1}
    return {"id": cid, "fixture_claims": claims, "observed": observed}


def make_cycle(number, layout_changed=0):
    return {
        "cycle": number, "status": "completed", "exception_kind": "none",
        "exception_stage": "none", "views_null_before_create": True, "create_calls": 1,
        "create_returned": True, "views_all_set_after_create": True, "run_calls": 1,
        "run_capacity": 32, "run_returned": 32, "guard_intact": True, "destroy_calls": 1,
        "views_null_at_end": True, "destructor_count": "unknown",
        "cases": [make_case(cid, layout_changed) for cid in IDS],
    }


def make_report(cycles=1, origin="synthetic", layout_changed=0):
    """A synthetic, all-consistent report. Layout values are arbitrary inventions."""
    return {
        "schema": "fnv-rtti-runtime-report", "schema_version": 1, "origin": origin,
        "fixture": "rtti_abi_fixture_v1", "case_count_constant": 32,
        "cycles_requested": cycles,
        "cycles": [make_cycle(n + 1, layout_changed) for n in range(cycles)],
        "driver_status": "ok", "driver_exit_code": 0, "end_of_report": True,
    }


def fixture_passed(case):
    """What rtti_consumer.cpp record() would compute for `passed`."""
    c, o = case["fixture_claims"], case["observed"]
    ok = o["outcome"] == c["expected"] and o["result_matches"] != 0
    if c["address_expected"] == 0:
        ok = ok and o["address_changed"] == 0
    elif c["address_expected"] == 1:
        ok = ok and o["address_changed"] == 1
    return 1 if ok else 0


def realistic(rep):
    """Recompute fixture `passed` and the driver summary, as an honest run would."""
    for cy in rep["cycles"]:
        for case in cy["cases"]:
            if isinstance(case.get("fixture_claims"), dict) and isinstance(
                    case.get("observed"), dict):
                case["fixture_claims"]["passed"] = fixture_passed(case)
    status = chk.driver_status(rep)
    rep["driver_status"] = status
    rep["driver_exit_code"] = chk.DRIVER_EXIT[status]
    return rep


def case_of(rep, cid, cycle=0):
    for case in rep["cycles"][cycle]["cases"]:
        if case["id"] == cid:
            return case
    raise KeyError(cid)


def render(rep):
    """Serialise in the driver's layout (two-space nesting, one case per line)."""
    def scalar(v):
        return json.dumps(v)
    lines = ["{"]
    top = [k for k in rep]
    for ti, key in enumerate(top):
        end = "," if ti + 1 < len(top) else ""
        if key != "cycles":
            lines.append(f'  "{key}": {scalar(rep[key])}{end}')
            continue
        if not rep["cycles"]:
            lines.append(f'  "cycles": []{end}')
            continue
        lines.append('  "cycles": [')
        for ci, cy in enumerate(rep["cycles"]):
            lines.append("    {")
            keys = list(cy)
            for ki, k in enumerate(keys):
                kend = "," if ki + 1 < len(keys) else ""
                if k != "cases":
                    lines.append(f'      "{k}": {scalar(cy[k])}{kend}')
                elif not cy["cases"]:
                    lines.append(f'      "cases": []{kend}')
                else:
                    lines.append('      "cases": [')
                    for xi, case in enumerate(cy["cases"]):
                        xend = "," if xi + 1 < len(cy["cases"]) else ""
                        lines.append("        " + json.dumps(case, separators=(", ", ": "))
                                     + xend)
                    lines.append("      ]" + kend)
            lines.append("    }" + ("," if ci + 1 < len(rep["cycles"]) else ""))
        lines.append("  ]" + end)
    lines.append("}")
    return "\n".join(lines) + "\n"


def outcome(doc, metadata=None):
    """Return (verdict, failure codes, conflict codes)."""
    try:
        r = chk.check_report(doc, metadata)
    except chk.InputError as exc:
        return "INVALID", {c for _w, c, _m in exc.errors}, set()
    return r["verdict"], {f["code"] for f in r["failures"]}, {f["code"] for f in r["conflicts"]}


def metadata_doc():
    return json.loads(METADATA.read_text(encoding="utf-8"))


def run_cli(*args):
    out, err = io.StringIO(), io.StringIO()
    code = chk.main(list(args), stdout=out, stderr=err)
    return code, out.getvalue(), err.getvalue()


# ---------------------------------------------------------------- samples

def _sample_forged_pass():
    rep = make_report()
    case = case_of(rep, "M01")
    case["observed"].update(outcome=2, result_matches=-1, address_changed=-1)
    return rep  # passed stays 1 and driver_status stays "ok": both forged


def _sample_not_run():
    rep = make_report()
    case_of(rep, "S05")["observed"].update(outcome=0, result_matches=-1, address_changed=-1)
    return realistic(rep)


def _sample_relation():
    rep = make_report()
    case_of(rep, "V02")["observed"]["address_changed"] = 0
    return realistic(rep)


def _sample_missing():
    rep = make_report()
    rep["cycles"][0]["cases"] = [c for c in rep["cycles"][0]["cases"] if c["id"] != "A03"]
    rep["cycles"][0]["run_returned"] = 31
    return realistic(rep)


def _sample_duplicate():
    rep = make_report()
    cases = rep["cycles"][0]["cases"]
    cases[IDS.index("V04")] = copy.deepcopy(cases[IDS.index("V03")])
    return realistic(rep)


def _sample_create_failed():
    rep = make_report()
    cy = rep["cycles"][0]
    cy.update(status="create_failed", create_returned=False, views_all_set_after_create=False,
              run_calls=0, run_returned=-1, destroy_calls=0, cases=[])
    return realistic(rep)


def _sample_conflict():
    rep = make_report()
    case = case_of(rep, "A01")
    case["fixture_claims"]["expected"] = 1   # the fixture's claim, not the matrix
    case["fixture_claims"]["address_expected"] = -1
    return realistic(rep)


SAMPLE_SET = {
    # name: (builder, cut_to_bytes or None, verdict, exit code, required codes)
    "synthetic-pass-one-cycle.json": (lambda: make_report(1), None, "PASS", 0, set()),
    "synthetic-pass-three-cycles.json": (lambda: make_report(3, layout_changed=1), None,
                                         "PASS", 0, set()),
    "synthetic-forged-pass.json": (_sample_forged_pass, None, "FAIL", 1,
                                   {"E-OUTCOME", "E-FORGED-PASS", "E-DRIVER-STATUS"}),
    "synthetic-not-run.json": (_sample_not_run, None, "FAIL", 1, {"E-NOT-RUN"}),
    "synthetic-relation-failure.json": (_sample_relation, None, "FAIL", 1, {"E-RELATION"}),
    "synthetic-missing-case.json": (_sample_missing, None, "FAIL", 1,
                                    {"E-MISSING-ID", "E-COUNT"}),
    "synthetic-duplicate-id.json": (_sample_duplicate, None, "FAIL", 1,
                                    {"E-DUP-ID", "E-MISSING-ID"}),
    "synthetic-create-failed.json": (_sample_create_failed, None, "FAIL", 1,
                                     {"E-LIFECYCLE"}),
    "synthetic-fixture-conflict.json": (_sample_conflict, None, "UNRESOLVED", 3,
                                        {"C-FIXTURE-EXPECTED", "C-FIXTURE-ADDRESS",
                                         "C-FIXTURE-PASSED"}),
    "synthetic-truncated.json": (lambda: make_report(1), 4000, "INVALID", 1, {"E-JSON"}),
}


def sample_text(name):
    builder, cut, *_ = SAMPLE_SET[name]
    text = render(builder())
    return text[:cut] if cut else text


# ================================================================ tests


class MatrixTests(unittest.TestCase):
    """The reviewed matrix against the hand table, metadata, consumer and docs."""

    def test_checker_matrix_equals_hand_table(self):
        self.assertEqual(chk.MATRIX, HAND_ROWS)
        self.assertEqual(len(IDS), 32)
        self.assertEqual(len(set(IDS)), 32)

    def test_counts(self):
        outcomes = [r[3] for r in HAND_ROWS]
        self.assertEqual((outcomes.count("success"), outcomes.count("null"),
                          outcomes.count("bad_cast")), (20, 8, 4))
        self.assertEqual(len(MUST_DIFFER), 7)
        self.assertEqual(len(LAYOUT), 13)

    def test_metadata_agrees(self):
        r = chk.compare_metadata(metadata_doc())
        self.assertEqual(r["verdict"], "PASS", r)
        self.assertEqual(r["metadata_casts_compared"], 32)

    def test_metadata_independently(self):
        meta = metadata_doc()
        self.assertEqual(meta["fixture"], "rtti_abi_fixture_v1")
        adj = {"nonzero": "must_differ", "layout_dependent": "layout_dependent",
               "not_applicable": "not_applicable"}
        got = tuple((c["id"], c["form"], "null" if "null_of" in c["input"] else "object",
                     c["expect"], adj[c["adjustment"]]) for c in meta["casts"])
        self.assertEqual(got, HAND_ROWS)

    def test_consumer_calls_agree(self):
        text = CONSUMER.read_text(encoding="utf-8")
        calls = re.findall(r'^\s+(\w+)(?:<[^>]*>)?\(sink, "([A-Z]\d\d)"(.*)\);$', text, re.M)
        kinds = {
            "pointer_case": ("pointer", "object", "success"),
            "pointer_fail_case": ("pointer", "object", "null"),
            "null_input_case": ("pointer", "null", "null"),
            "reference_case": ("reference", "object", "success"),
            "reference_fail_case": ("reference", "object", "bad_cast"),
            "void_case": ("void_pointer", "object", "success"),
        }
        consts = {"kAddressMustDiffer": "must_differ",
                  "kAddressLayoutDependent": "layout_dependent",
                  "kAddressMustBeEqual": "must_equal"}
        rows = []
        for fn, cid, rest in calls:
            form, inp, out = kinds[fn]
            tail = rest.rsplit(",", 1)[-1].strip() if rest else ""
            address = consts.get(tail, "not_applicable")
            rows.append((cid, form, inp, out, address))
        self.assertEqual(tuple(rows), HAND_ROWS)

    def test_expected_abi_table_agrees(self):
        text = EXPECTED_ABI.read_text(encoding="utf-8")
        rows = re.findall(r"^\| ([A-Z]\d\d) \| ([^|]+) \| ([^|]+) \| [^|]+ \| ([^|]+) \| ([^|]+) \|",
                          text, re.M)
        forms = {"pointer": "pointer", "reference": "reference", "`void*`": "void_pointer"}
        address = {"must differ": "must_differ", "layout-dependent": "layout_dependent",
                   "n/a": "not_applicable"}
        got = tuple((cid, forms[f.strip()], "null" if i.strip().startswith("null") else "object",
                     o.strip().strip("`"), address[a.strip()]) for cid, f, i, o, a in rows)
        self.assertEqual(got, HAND_ROWS)

    def test_rtti_abi_validator_agrees_if_present(self):
        validator = ROOT / "tools" / "rtti-abi" / "rtti_abi.py"
        if not validator.is_file():
            self.skipTest("tools/rtti-abi/rtti_abi.py is not in this checkout")
        spec = importlib.util.spec_from_file_location("rtti_abi_for_probe_tests", validator)
        mod = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(mod)
        summary = mod.validate_metadata(metadata_doc())
        self.assertTrue(summary)

    def test_metadata_conflicts_are_reported_not_fixed(self):
        meta = metadata_doc()
        original = copy.deepcopy(meta)
        meta["casts"][IDS.index("M09")]["expect"] = "success"
        meta["casts"][IDS.index("A04")]["adjustment"] = "layout_dependent"
        r = chk.compare_metadata(meta)
        self.assertEqual(r["verdict"], "UNRESOLVED")
        self.assertEqual(r["conflicts_total"], 3)
        self.assertNotEqual(meta, original)  # the input object itself was not "repaired"
        self.assertEqual(chk.MATRIX, HAND_ROWS)


class PositiveTests(unittest.TestCase):

    def test_one_cycle_passes(self):
        r = chk.check_report(make_report(1))
        self.assertEqual(r["verdict"], "PASS")
        self.assertEqual(r["cases_meeting_matrix"], [32])
        self.assertEqual(r["must_differ_held"], [7])
        self.assertEqual(r["failures_total"] + r["conflicts_total"], 0)

    def test_two_and_three_cycles_pass(self):
        for n in (2, 3):
            r = chk.check_report(make_report(n))
            self.assertEqual(r["verdict"], "PASS")
            self.assertEqual(r["cases_meeting_matrix"], [32] * n)
            self.assertEqual(r["lifecycle"]["create_calls"], [1] * n)
            self.assertEqual(r["lifecycle"]["destroy_calls"], [1] * n)

    def test_layout_dependent_either_value_is_an_observation(self):
        for value, word in ((0, "unchanged"), (1, "changed")):
            r = chk.check_report(make_report(2, layout_changed=value))
            self.assertEqual(r["verdict"], "PASS")
            self.assertEqual(set(r["layout_dependent_observations"]), set(LAYOUT))
            for cid in LAYOUT:
                self.assertEqual(r["layout_dependent_observations"][cid], [word, word])

    def test_mixed_layout_values_pass(self):
        rep = make_report(1)
        for i, cid in enumerate(LAYOUT):
            case_of(rep, cid)["observed"]["address_changed"] = i % 2
        self.assertEqual(outcome(rep)[0], "PASS")

    def test_metadata_option_passes(self):
        r = chk.check_report(make_report(1), metadata_doc())
        self.assertEqual(r["verdict"], "PASS")
        self.assertEqual(r["metadata_casts_compared"], 32)

    def test_destructor_count_stays_unknown(self):
        r = chk.check_report(make_report(1))
        self.assertEqual(r["lifecycle"]["destructor_count"], "unknown")

    def test_native_evidence_never_claimed(self):
        for origin in ("driver", "synthetic"):
            r = chk.check_report(make_report(1, origin=origin))
            self.assertEqual(r["native_evidence"], "not established by this checker")

    def test_text_labels_synthetic_and_never_claims_native(self):
        lines = "\n".join(chk.report_lines(chk.check_report(make_report(1))))
        self.assertIn("[synthetic sample: not native evidence]", lines)
        self.assertIn("observations only", lines)
        lines = "\n".join(chk.report_lines(chk.check_report(make_report(1, origin="driver"))))
        self.assertNotIn("synthetic", lines)
        self.assertIn("private run record", lines)

    def test_driver_layout_round_trips(self):
        rep = make_report(3, origin="driver")
        self.assertEqual(json.loads(render(rep)), rep)
        self.assertEqual(outcome(json.loads(render(rep)))[0], "PASS")

    def test_crlf_output_is_accepted(self):
        data = render(make_report(1)).replace("\n", "\r\n").encode("ascii")
        self.assertEqual(outcome(chk.parse_json_bytes(data))[0], "PASS")

    def test_three_cycle_report_fits_capture_limit(self):
        data = render(make_report(3)).replace("\n", "\r\n").encode("ascii")
        self.assertLess(len(data), chk.MAX_REPORT_BYTES // 2)


class MalformedInputTests(unittest.TestCase):

    def parse_code(self, data):
        with self.assertRaises(chk.InputError) as ctx:
            chk.parse_json_bytes(data)
        return ctx.exception.errors[0][1]

    def test_empty_and_whitespace(self):
        self.assertEqual(self.parse_code(b""), "E-EMPTY")
        self.assertEqual(self.parse_code(b" \r\n\t"), "E-EMPTY")

    def test_malformed(self):
        for data in (b"{", b"[1,]", b"{'a': 1}", b"nul", b"{\"a\" 1}", b"{}{}"):
            self.assertEqual(self.parse_code(data), "E-JSON", data)

    def test_non_finite_numbers(self):
        for data in (b'{"a": NaN}', b'{"a": Infinity}', b'{"a": -Infinity}'):
            self.assertEqual(self.parse_code(data), "E-JSON")

    def test_bom_and_encoding(self):
        self.assertEqual(self.parse_code(b"\xef\xbb\xbf{}"), "E-ENCODING")
        self.assertEqual(self.parse_code(b'{"a": "\xff"}'), "E-ENCODING")

    def test_duplicate_keys_top_and_nested(self):
        self.assertEqual(self.parse_code(b'{"a": 1, "a": 2}'), "E-DUPKEY")
        text = render(make_report(1)).replace('"outcome": 1,', '"outcome": 1, "outcome": 1,', 1)
        self.assertEqual(self.parse_code(text.encode()), "E-DUPKEY")

    def test_duplicate_key_name_not_echoed(self):
        with self.assertRaises(chk.InputError) as ctx:
            chk.parse_json_bytes(b'{"SECRET_NAME_123": 1, "SECRET_NAME_123": 2}')
        self.assertNotIn("SECRET", str(ctx.exception.errors))

    def test_depth_limit(self):
        self.assertEqual(self.parse_code(b"[" * 9 + b"]" * 9), "E-LIMIT")
        self.assertEqual(self.parse_code(b"[" * 100000), "E-LIMIT")
        chk.parse_json_bytes(b"[" * 8 + b"]" * 8)

    def test_brackets_inside_strings_do_not_count(self):
        chk.parse_json_bytes(json.dumps({"a": "[[[[[[[[[[[[{{{{{{"}).encode())

    def test_size_limit(self):
        self.assertEqual(self.parse_code(b" " * (chk.MAX_REPORT_BYTES + 1)), "E-LIMIT")

    def test_truncated_output_never_passes(self):
        text = render(make_report(1)).encode("ascii")
        end = len(text.rstrip())
        cuts = list(range(0, end, 7)) + list(range(max(0, end - 60), end))
        for cut in cuts:
            verdict = outcome_bytes(text[:cut])
            self.assertEqual(verdict, "INVALID", cut)

    def test_non_object_top(self):
        for doc in ([], "x", 1, None):
            self.assertEqual(outcome(doc)[0], "INVALID")


def outcome_bytes(data):
    try:
        doc = chk.parse_json_bytes(data)
    except chk.InputError:
        return "INVALID"
    return outcome(doc)[0]


class SchemaTests(unittest.TestCase):

    def assertInvalid(self, rep, code="E-SCHEMA"):
        verdict, codes, _ = outcome(rep)
        self.assertEqual(verdict, "INVALID")
        self.assertIn(code, codes)

    def test_unknown_field_at_every_level(self):
        for target in ("top", "cycle", "case", "claims", "observed"):
            rep = make_report(1)
            obj = {"top": rep, "cycle": rep["cycles"][0], "case": rep["cycles"][0]["cases"][0],
                   "claims": rep["cycles"][0]["cases"][0]["fixture_claims"],
                   "observed": rep["cycles"][0]["cases"][0]["observed"]}[target]
            obj["extra_PRIVATE"] = 1
            self.assertInvalid(rep)
            self.assertNotIn("PRIVATE", str(chk.main.__doc__))
            try:
                chk.check_report(rep)
            except chk.InputError as exc:
                self.assertNotIn("PRIVATE", str(exc.errors))

    def test_missing_field_at_every_level(self):
        for key in chk.TOP_KEYS:
            rep = make_report(1)
            del rep[key]
            self.assertInvalid(rep)
        for key in chk.CYCLE_KEYS:
            rep = make_report(1)
            del rep["cycles"][0][key]
            self.assertInvalid(rep)
        for part, keys in (("fixture_claims", chk.CLAIM_KEYS), ("observed", chk.OBSERVED_KEYS)):
            for key in keys:
                rep = make_report(1)
                del rep["cycles"][0]["cases"][3][part][key]
                self.assertInvalid(rep)

    def test_wrong_types(self):
        cases = [
            ("schema_version", "1", "E-VERSION"), ("cycles_requested", True, "E-SCHEMA"),
            ("cycles_requested", 1.0, "E-SCHEMA"), ("end_of_report", 1, "E-SCHEMA"),
            ("cycles", {}, "E-SCHEMA"), ("driver_exit_code", "0", "E-SCHEMA"),
            ("fixture", None, "E-SCHEMA"), ("origin", "native", "E-SCHEMA"),
            ("driver_status", "passed", "E-SCHEMA"),
        ]
        for key, value, code in cases:
            rep = make_report(1)
            rep[key] = value
            self.assertInvalid(rep, code)
        rep = make_report(1)
        rep["cycles"][0]["cases"][0]["observed"]["outcome"] = True
        self.assertInvalid(rep)
        rep = make_report(1)
        rep["cycles"][0]["cases"][0]["fixture_claims"]["passed"] = "1"
        self.assertInvalid(rep)
        rep = make_report(1)
        rep["cycles"][0]["guard_intact"] = 1
        self.assertInvalid(rep)
        rep = make_report(1)
        rep["cycles"][0]["run_returned"] = 2 ** 40
        self.assertInvalid(rep)

    def test_wrong_schema_and_version(self):
        rep = make_report(1)
        rep["schema"] = "fnv-rtti-abi-metadata"
        self.assertInvalid(rep)
        for version in (0, 2):
            rep = make_report(1)
            rep["schema_version"] = version
            self.assertInvalid(rep, "E-VERSION")

    def test_destructor_count_must_be_unknown(self):
        for value in (8, "8", None, "known"):
            rep = make_report(1)
            rep["cycles"][0]["destructor_count"] = value
            self.assertInvalid(rep)

    def test_enumerated_strings(self):
        for key in ("status", "exception_kind", "exception_stage"):
            rep = make_report(1)
            rep["cycles"][0][key] = "other"
            self.assertInvalid(rep)

    def test_id_type(self):
        rep = make_report(1)
        rep["cycles"][0]["cases"][0]["id"] = 1
        self.assertInvalid(rep)

    def test_limits(self):
        rep = make_report(3)
        rep["cycles"].append(make_cycle(4))
        self.assertInvalid(rep, "E-LIMIT")
        rep = make_report(1)
        rep["cycles"][0]["cases"] = rep["cycles"][0]["cases"] * 3
        self.assertInvalid(rep, "E-LIMIT")


class CycleTests(unittest.TestCase):

    def assertFail(self, rep, *codes, honest=True):
        if honest:
            realistic(rep)
        verdict, got, _ = outcome(rep)
        self.assertEqual(verdict, "FAIL", got)
        for code in codes:
            self.assertIn(code, got)
        return got

    def test_cycles_requested_out_of_bounds(self):
        for n in (0, 4, -1):
            rep = make_report(1)
            rep["cycles_requested"] = n
            self.assertFail(rep, "E-CYCLES")

    def test_fewer_cycles_than_requested(self):
        rep = make_report(3)
        rep["cycles"].pop()
        self.assertFail(rep, "E-CYCLES")
        rep = make_report(1)
        rep["cycles"] = []
        self.assertFail(rep, "E-CYCLES")

    def test_cycle_numbering(self):
        rep = make_report(2)
        rep["cycles"][1]["cycle"] = 1
        self.assertFail(rep, "E-CYCLES")

    def test_create_failure(self):
        rep = realistic(_sample_create_failed())
        got = self.assertFail(rep, "E-LIFECYCLE")
        self.assertEqual(rep["driver_status"], "create_failed")
        self.assertEqual(rep["driver_exit_code"], 4)
        self.assertNotIn("E-DRIVER-STATUS", got)

    def test_destroy_after_failed_creation_rejected(self):
        rep = _sample_create_failed()
        wheres = {f["where"] for f in chk.check_report(rep)["failures"]}
        self.assertNotIn("/cycles/0/destroy_calls", wheres)
        rep["cycles"][0]["destroy_calls"] = 1
        self.assertFail(rep, "E-LIFECYCLE")
        wheres = {f["where"] for f in chk.check_report(rep)["failures"]}
        self.assertIn("/cycles/0/destroy_calls", wheres)

    def test_partial_creation_exception_allows_one_destroy(self):
        rep = _sample_create_failed()
        rep["cycles"][0].update(status="exception", exception_kind="unknown",
                                exception_stage="create", destroy_calls=1)
        realistic(rep)
        wheres = {f["where"] for f in chk.check_report(rep)["failures"]}
        self.assertNotIn("/cycles/0/destroy_calls", wheres)
        rep["cycles"][0]["destroy_calls"] = 2
        wheres = {f["where"] for f in chk.check_report(rep)["failures"]}
        self.assertIn("/cycles/0/destroy_calls", wheres)

    def test_create_calls(self):
        for n in (0, 2):
            rep = make_report(1)
            rep["cycles"][0]["create_calls"] = n
            self.assertFail(rep, "E-LIFECYCLE")

    def test_destroy_missing_or_doubled(self):
        for n in (0, 2):
            rep = make_report(1)
            rep["cycles"][0]["destroy_calls"] = n
            self.assertFail(rep, "E-LIFECYCLE")

    def test_views_not_null_after_destroy(self):
        rep = make_report(2)
        rep["cycles"][1]["views_null_at_end"] = False
        self.assertFail(rep, "E-LIFECYCLE")

    def test_record_not_fresh(self):
        rep = make_report(1)
        rep["cycles"][0]["views_null_before_create"] = False
        self.assertFail(rep, "E-LIFECYCLE")

    def test_views_invalid_cycle(self):
        rep = make_report(1)
        rep["cycles"][0].update(status="views_invalid", views_all_set_after_create=False,
                                run_calls=0, run_returned=-1, cases=[])
        self.assertFail(rep, "E-LIFECYCLE")
        self.assertEqual(rep["driver_status"], "structure_failure")

    def test_view_missing_after_create(self):
        rep = make_report(1)
        rep["cycles"][0]["views_all_set_after_create"] = False
        self.assertFail(rep, "E-LIFECYCLE")

    def test_run_calls(self):
        for n in (0, 2):
            rep = make_report(1)
            rep["cycles"][0]["run_calls"] = n
            self.assertFail(rep, "E-LIFECYCLE")

    def test_run_returned_wrong(self):
        for n in (31, 33, 0, -1):
            rep = make_report(1)
            rep["cycles"][0]["run_returned"] = n
            self.assertFail(rep, "E-COUNT")

    def test_capacity_wrong(self):
        rep = make_report(1)
        rep["cycles"][0]["run_capacity"] = 16
        self.assertFail(rep, "E-COUNT")

    def test_guard_disturbed(self):
        rep = make_report(1)
        rep["cycles"][0]["guard_intact"] = False
        self.assertFail(rep, "E-GUARD")

    def test_exception_cycle(self):
        for kind in ("bad_alloc", "bad_cast", "std_exception", "unknown"):
            rep = make_report(2)
            rep["cycles"] = rep["cycles"][:1]
            rep["cycles"][0].update(status="exception", exception_kind=kind,
                                    exception_stage="run", run_returned=-1, cases=[])
            self.assertFail(rep, "E-EXCEPTION")
            self.assertEqual(rep["driver_exit_code"], 5)

    def test_exception_fields_must_agree_with_status(self):
        rep = make_report(1)
        rep["cycles"][0]["exception_kind"] = "unknown"
        self.assertFail(rep, "E-LIFECYCLE")
        rep = make_report(1)
        rep["cycles"][0].update(status="exception", run_returned=-1, cases=[])
        self.assertFail(rep, "E-LIFECYCLE", "E-EXCEPTION")

    def test_cases_on_unfinished_cycle(self):
        rep = _sample_create_failed()
        rep["cycles"][0]["cases"] = [make_case("S01")]
        self.assertFail(rep, "E-COUNT")

    def test_incomplete_status(self):
        rep = make_report(1)
        rep["cycles"][0]["status"] = "incomplete"
        self.assertFail(rep, "E-LIFECYCLE")

    def test_end_of_report_false(self):
        rep = make_report(1)
        rep["end_of_report"] = False
        self.assertFail(rep, "E-INCOMPLETE", honest=False)

    def test_fixture_and_case_count_constant(self):
        rep = make_report(1)
        rep["fixture"] = "other_fixture"
        self.assertFail(rep, "E-FIXTURE", honest=False)
        rep = make_report(1)
        rep["case_count_constant"] = 31
        self.assertFail(rep, "E-COUNT", honest=False)


class CaseIdTests(unittest.TestCase):

    def run_case(self, rep, *codes):
        realistic(rep)
        verdict, got, _ = outcome(rep)
        self.assertEqual(verdict, "FAIL", got)
        for code in codes:
            self.assertIn(code, got)
        return got

    def test_missing_each_family(self):
        for cid in ("S04", "M10", "V09", "A05"):
            rep = make_report(1)
            rep["cycles"][0]["cases"] = [c for c in rep["cycles"][0]["cases"] if c["id"] != cid]
            self.run_case(rep, "E-MISSING-ID", "E-COUNT")

    def test_duplicate_id(self):
        self.run_case(_sample_duplicate(), "E-DUP-ID", "E-MISSING-ID")

    def test_duplicate_appended(self):
        rep = make_report(1)
        rep["cycles"][0]["cases"].append(make_case("S01"))
        self.run_case(rep, "E-DUP-ID", "E-COUNT")

    def test_unknown_and_malformed_ids(self):
        for bad in ("Z99", "S1", "s01", "S010", "", None, "S01\u0000"):
            rep = make_report(1)
            rep["cycles"][0]["cases"][5]["id"] = bad
            got = self.run_case(rep, "E-ID", "E-MISSING-ID")
            self.assertNotIn("E-DUP-ID", got)

    def test_order(self):
        rep = make_report(1)
        cases = rep["cycles"][0]["cases"]
        cases[0], cases[1] = cases[1], cases[0]
        self.run_case(rep, "E-ORDER")

    def test_id_values_never_echoed_unless_reviewed(self):
        rep = make_report(1)
        rep["cycles"][0]["cases"][0]["id"] = "Q42"
        r = chk.check_report(realistic(rep))
        self.assertNotIn("Q42", json.dumps(r))


class CaseResultTests(unittest.TestCase):

    def check(self, rep, *codes, honest=True):
        if honest:
            realistic(rep)
        verdict, got, _ = outcome(rep)
        self.assertEqual(verdict, "FAIL", got)
        for code in codes:
            self.assertIn(code, got)
        return got

    def test_not_run_never_passes(self):
        for cid in IDS:
            rep = make_report(1)
            case_of(rep, cid)["observed"].update(outcome=0, result_matches=-1,
                                                 address_changed=-1)
            self.check(rep, "E-NOT-RUN")

    def test_not_run_with_forged_pass(self):
        rep = make_report(1)
        case_of(rep, "S01")["observed"].update(outcome=0, result_matches=-1, address_changed=-1)
        self.check(rep, "E-NOT-RUN", "E-FORGED-PASS", "E-DRIVER-STATUS", honest=False)

    def test_success_case_returns_null(self):
        for cid in ("S01", "M03", "V08", "A05"):
            rep = make_report(1)
            case_of(rep, cid)["observed"].update(outcome=2, result_matches=-1,
                                                 address_changed=-1)
            self.check(rep, "E-OUTCOME")

    def test_success_reference_throws(self):
        for cid in ("S05", "M06", "V06"):
            rep = make_report(1)
            case_of(rep, cid)["observed"].update(outcome=3, result_matches=-1,
                                                 address_changed=-1)
            self.check(rep, "E-OUTCOME")

    def test_failure_case_succeeds(self):
        for cid in FAILURE_CASES:
            rep = make_report(1)
            case_of(rep, cid)["observed"].update(outcome=1, result_matches=-1,
                                                 address_changed=1)
            self.check(rep, "E-OUTCOME")

    def test_bad_cast_reported_as_null(self):
        rep = make_report(1)
        case_of(rep, "M05")["observed"]["outcome"] = 2
        self.check(rep, "E-OUTCOME")

    def test_wrong_view(self):
        rep = make_report(1)
        case_of(rep, "V03")["observed"]["result_matches"] = 0
        self.check(rep, "E-VIEW")

    def test_minus_one_is_not_success_proof(self):
        rep = make_report(1)
        case_of(rep, "M10")["observed"]["result_matches"] = -1
        got = self.check(rep, "E-VIEW")
        # The fixture's own rule counts -1 as "not 0"; the checker does not.
        self.assertEqual(fixture_passed(case_of(rep, "M10")), 1)
        self.assertIn("E-FORGED-PASS", got)

    def test_must_differ_violated(self):
        for cid in MUST_DIFFER:
            rep = make_report(1)
            case_of(rep, cid)["observed"]["address_changed"] = 0
            self.check(rep, "E-RELATION")

    def test_missing_relation_on_success(self):
        rep = make_report(1)
        case_of(rep, "S07")["observed"]["address_changed"] = -1
        self.check(rep, "E-RELATION")

    def test_not_applicable_values_preserved(self):
        for cid in FAILURE_CASES:
            for field, value in (("result_matches", 0), ("result_matches", 1),
                                 ("address_changed", 0), ("address_changed", 1)):
                rep = make_report(1)
                case_of(rep, cid)["observed"][field] = value
                self.check(rep, "E-NA")

    def test_forged_pass_sample(self):
        got = self.check(_sample_forged_pass(), "E-OUTCOME", "E-FORGED-PASS", "E-DRIVER-STATUS",
                         honest=False)
        self.assertTrue(got)

    def test_out_of_range_fields(self):
        cases = [("observed", "outcome", 4), ("observed", "outcome", -1),
                 ("observed", "result_matches", 2), ("observed", "address_changed", -2),
                 ("fixture_claims", "expected", 0), ("fixture_claims", "passed", 2),
                 ("fixture_claims", "address_expected", 2),
                 ("observed", "address_changed", -1000)]
        for part, field, value in cases:
            rep = make_report(1)
            case_of(rep, "M02")[part][field] = value
            got = self.check(rep, "E-FIELD", honest=False)
            r = chk.check_report(rep)
            self.assertNotIn(str(value) + " ", " ".join(f["message"] for f in r["failures"]
                                                        if f["code"] == "E-FIELD"))
            self.assertTrue(got)

    def test_sentinel_case_from_unwritten_result(self):
        rep = make_report(1)
        rep["cycles"][0]["cases"][31] = {
            "id": None,
            "fixture_claims": {"expected": -1000, "address_expected": -1000, "passed": -1000},
            "observed": {"outcome": -1000, "result_matches": -1000, "address_changed": -1000}}
        self.check(rep, "E-ID", "E-MISSING-ID")
        self.assertEqual(rep["driver_status"], "structure_failure")

    def test_failure_in_one_of_three_cycles(self):
        rep = make_report(3)
        case_of(rep, "A04", cycle=2)["observed"]["address_changed"] = 0
        realistic(rep)
        r = chk.check_report(rep)
        self.assertEqual(r["verdict"], "FAIL")
        self.assertEqual(r["cases_meeting_matrix"], [32, 32, 31])
        self.assertEqual(r["must_differ_held"], [7, 7, 6])


class ConflictTests(unittest.TestCase):

    def test_fixture_expected_conflict_is_unresolved(self):
        rep = realistic(_sample_conflict())
        verdict, fails, conflicts = outcome(rep)
        self.assertEqual(verdict, "UNRESOLVED")
        self.assertEqual(fails, set())
        self.assertEqual(conflicts, {"C-FIXTURE-EXPECTED", "C-FIXTURE-ADDRESS",
                                     "C-FIXTURE-PASSED"})
        self.assertEqual(rep["driver_status"], "case_failure")

    def test_observation_matching_wrong_fixture_claim_fails(self):
        rep = make_report(1)
        case = case_of(rep, "M09")       # the matrix requires null
        case["fixture_claims"].update(expected=1, address_expected=-1)
        case["observed"].update(outcome=1, result_matches=1, address_changed=0)
        realistic(rep)
        verdict, fails, conflicts = outcome(rep)
        self.assertEqual(verdict, "FAIL")
        self.assertIn("E-OUTCOME", fails)
        self.assertIn("C-FIXTURE-EXPECTED", conflicts)

    def test_address_claim_conflict_still_enforces_matrix(self):
        rep = make_report(1)
        case_of(rep, "M01")["fixture_claims"]["address_expected"] = -1
        case_of(rep, "M01")["observed"]["address_changed"] = 0
        realistic(rep)
        verdict, fails, conflicts = outcome(rep)
        self.assertEqual(verdict, "FAIL")
        self.assertIn("E-RELATION", fails)
        self.assertIn("C-FIXTURE-ADDRESS", conflicts)

    def test_fixture_passed_zero_on_good_observation(self):
        rep = make_report(1)
        case_of(rep, "S03")["fixture_claims"]["passed"] = 0
        rep["driver_status"], rep["driver_exit_code"] = "case_failure", 1
        verdict, fails, conflicts = outcome(rep)
        self.assertEqual(verdict, "UNRESOLVED")
        self.assertEqual(conflicts, {"C-FIXTURE-PASSED"})

    def test_metadata_conflicts(self):
        edits = [
            ("expect", "S02", "success"), ("adjustment", "M01", "layout_dependent"),
            ("form", "S05", "pointer"), ("adjustment", "S07", "something"),
        ]
        for field, cid, value in edits:
            meta = metadata_doc()
            meta["casts"][IDS.index(cid)][field] = value
            verdict, fails, conflicts = outcome(make_report(1), meta)
            self.assertEqual(verdict, "UNRESOLVED", (field, cid))
            self.assertEqual(conflicts, {"C-METADATA"})

    def test_metadata_null_input_kind(self):
        meta = metadata_doc()
        meta["casts"][IDS.index("S06")]["input"] = {"object": "si_leaf", "path": ["SiLeaf"]}
        self.assertEqual(outcome(make_report(1), meta)[2], {"C-METADATA"})

    def test_metadata_missing_extra_duplicate_cast(self):
        meta = metadata_doc()
        del meta["casts"][IDS.index("V05")]
        self.assertEqual(outcome(make_report(1), meta)[0], "UNRESOLVED")
        meta = metadata_doc()
        meta["casts"].append(dict(meta["casts"][0], id="X01"))
        self.assertEqual(outcome(make_report(1), meta)[0], "UNRESOLVED")
        meta = metadata_doc()
        meta["casts"].append(copy.deepcopy(meta["casts"][0]))
        self.assertEqual(outcome(make_report(1), meta)[0], "UNRESOLVED")

    def test_metadata_fixture_name(self):
        meta = metadata_doc()
        meta["fixture"] = "other"
        self.assertEqual(outcome(make_report(1), meta)[2], {"C-METADATA"})

    def test_metadata_unknown_adjustment_is_no_claim(self):
        meta = metadata_doc()
        meta["casts"][IDS.index("S01")]["adjustment"] = "unknown"
        self.assertEqual(outcome(make_report(1), meta)[0], "UNRESOLVED")

    def test_metadata_wrong_document(self):
        for meta in ({}, [], {"schema": "fnv-rtti-abi-metadata", "schema_version": 2,
                              "casts": []}):
            verdict, fails, _ = outcome(make_report(1), meta)
            self.assertEqual(verdict, "FAIL")
            self.assertIn("E-METADATA", fails)

    def test_failure_outranks_conflict(self):
        rep = _sample_conflict()
        case_of(rep, "V02")["observed"]["address_changed"] = 0
        realistic(rep)
        self.assertEqual(outcome(rep)[0], "FAIL")


class DriverSummaryTests(unittest.TestCase):

    def test_forged_ok_status(self):
        rep = make_report(1)
        case_of(rep, "M04")["observed"].update(outcome=1, result_matches=-1, address_changed=1)
        case_of(rep, "M04")["fixture_claims"]["passed"] = 0
        verdict, fails, _ = outcome(rep)
        self.assertEqual(verdict, "FAIL")
        self.assertIn("E-DRIVER-STATUS", fails)

    def test_exit_code_must_match_status(self):
        rep = make_report(1)
        rep["driver_exit_code"] = 1
        self.assertIn("E-DRIVER-STATUS", outcome(rep)[1])

    def test_status_claiming_failure_on_clean_report(self):
        rep = make_report(1)
        rep["driver_status"], rep["driver_exit_code"] = "case_failure", 1
        verdict, fails, _ = outcome(rep)
        self.assertEqual(verdict, "FAIL")
        self.assertIn("E-DRIVER-STATUS", fails)

    def test_mirror_precedence(self):
        rep = make_report(3)
        self.assertEqual(chk.driver_status(rep), "ok")
        case_of(rep, "S01", 0)["observed"]["result_matches"] = 0
        self.assertEqual(chk.driver_status(rep), "case_failure")
        rep["cycles"][1]["guard_intact"] = False
        self.assertEqual(chk.driver_status(rep), "structure_failure")
        rep["cycles"][2].update(status="create_failed", create_returned=False, cases=[])
        self.assertEqual(chk.driver_status(rep), "create_failed")
        rep["cycles"][0]["status"] = "exception"
        self.assertEqual(chk.driver_status(rep), "exception")

    def test_mirror_missing_cycle_is_structure(self):
        rep = make_report(2)
        rep["cycles"].pop()
        self.assertEqual(chk.driver_status(rep), "structure_failure")

    def test_exit_codes_table(self):
        self.assertEqual(chk.DRIVER_EXIT, {"ok": 0, "case_failure": 1, "structure_failure": 3,
                                           "create_failed": 4, "exception": 5})


class StabilityTests(unittest.TestCase):

    def test_layout_observation_must_be_stable_across_cycles(self):
        rep = make_report(2)
        case_of(rep, "V01", 1)["observed"]["address_changed"] = 1
        realistic(rep)
        verdict, fails, _ = outcome(rep)
        self.assertEqual(verdict, "FAIL")
        self.assertIn("E-UNSTABLE", fails)


class SampleTests(unittest.TestCase):

    def test_sample_set_is_complete(self):
        on_disk = sorted(p.name for p in SAMPLES.glob("*.json"))
        self.assertEqual(on_disk, sorted(SAMPLE_SET))

    def test_samples_match_builders(self):
        for name in SAMPLE_SET:
            data = (SAMPLES / name).read_bytes().replace(b"\r\n", b"\n")
            self.assertEqual(data.decode("ascii"), sample_text(name), name)

    def test_samples_are_marked_synthetic(self):
        for name in SAMPLE_SET:
            text = (SAMPLES / name).read_text(encoding="ascii")
            self.assertIn('"origin": "synthetic"', text, name)
            self.assertTrue(name.startswith("synthetic-"))

    def test_sample_verdicts_through_cli(self):
        for name, (_b, _cut, verdict, code, codes) in SAMPLE_SET.items():
            rc, out, err = run_cli("check", str(SAMPLES / name), "--format", "json")
            self.assertEqual(rc, code, name)
            self.assertEqual(err, "")
            result = json.loads(out)
            self.assertEqual(result["verdict"], verdict, name)
            found = {f["code"] for f in result.get("failures", [])} | \
                    {f["code"] for f in result.get("conflicts", [])}
            self.assertTrue(codes <= found, (name, found))

    def test_pass_samples_with_metadata(self):
        for name in ("synthetic-pass-one-cycle.json", "synthetic-pass-three-cycles.json"):
            rc, out, _ = run_cli("check", str(SAMPLES / name), "--metadata", str(METADATA))
            self.assertEqual(rc, 0)
            self.assertTrue(out.startswith("PASS [synthetic sample: not native evidence]"))


class CliTests(unittest.TestCase):

    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.dir = pathlib.Path(self.tmp.name)

    def tearDown(self):
        self.tmp.cleanup()

    def write(self, name, data):
        path = self.dir / name
        path.write_bytes(data if isinstance(data, bytes) else data.encode("utf-8"))
        return str(path)

    def test_exit_codes(self):
        ok = self.write("ok.json", render(make_report(1)))
        self.assertEqual(run_cli("check", ok)[0], 0)
        bad = self.write("bad.json", render(_sample_relation()))
        self.assertEqual(run_cli("check", bad)[0], 1)
        conflict = self.write("c.json", render(realistic(_sample_conflict())))
        self.assertEqual(run_cli("check", conflict)[0], 3)
        broken = self.write("broken.json", "{")
        rc, out, _ = run_cli("check", broken)
        self.assertEqual(rc, 1)
        self.assertTrue(out.startswith("INVALID"))
        self.assertEqual(run_cli("check")[0], 2)
        self.assertEqual(run_cli("frobnicate", ok)[0], 2)
        self.assertEqual(run_cli("check", ok, "--format", "xml")[0], 2)

    def test_empty_output_file_fails(self):
        empty = self.write("empty.json", b"")
        rc, out, _ = run_cli("check", empty)
        self.assertEqual(rc, 1)
        self.assertIn("E-EMPTY", out)

    def test_usage_errors_never_echo_arguments(self):
        marker = "PRIVATE_ARGUMENT_MARKER"
        for args in (("check", marker + ".json"), ("check", "--bogus", marker),
                     ("check-plan", str(self.dir / marker)), ("check", "a", "--metadata",
                                                              marker)):
            rc, out, err = run_cli(*args)
            self.assertEqual(rc, 2, args)
            self.assertNotIn(marker, out + err)
            self.assertNotIn(self.tmp.name, out + err)

    def test_refused_paths(self):
        for path in ("\\\\server\\share\\r.json", "//server/share/r.json", "NUL", "con.json",
                     "", str(self.dir)):
            rc, _out, err = run_cli("check", path)
            self.assertEqual(rc, 2, path)
            self.assertTrue(err.startswith("ERROR:"))

    def test_oversized_file(self):
        big = self.write("big.json", b" " * (chk.MAX_REPORT_BYTES + 1))
        rc, out, _ = run_cli("check", big)
        self.assertEqual(rc, 1)
        self.assertIn("E-LIMIT", out)

    @unittest.skipUnless(hasattr(os, "symlink"), "no symlink support")
    def test_link_refused(self):
        target = self.write("t.json", render(make_report(1)))
        link = self.dir / "link.json"
        try:
            os.symlink(target, link)
        except OSError:
            self.skipTest("symlink creation not permitted")
        self.assertEqual(run_cli("check", str(link))[0], 2)

    def test_diagnostics_are_stable_and_private(self):
        rep = _sample_forged_pass()
        rep["cycles"][0]["cases"][2]["observed"]["result_matches"] = 0
        path = self.write("f.json", render(rep))
        first = run_cli("check", path)
        second = run_cli("check", path)
        self.assertEqual(first, second)
        self.assertNotIn(self.tmp.name, first[1] + first[2])
        self.assertNotIn("f.json", first[1] + first[2])

    def test_findings_capped(self):
        rep = make_report(3)
        for cy in rep["cycles"]:
            for case in cy["cases"]:
                case["observed"].update(outcome=0, result_matches=-1, address_changed=-1)
        path = self.write("many.json", render(rep))
        rc, out, _ = run_cli("check", path, "--format", "json")
        result = json.loads(out)
        self.assertEqual(rc, 1)
        self.assertEqual(len(result["failures"]), chk.MAX_REPORTED)
        self.assertGreater(result["failures_total"], chk.MAX_REPORTED)
        rc, text, _ = run_cli("check", path)
        self.assertIn(f"({chk.MAX_REPORTED} shown)", text)

    def test_json_output_is_sorted_and_parseable(self):
        path = self.write("ok.json", render(make_report(2)))
        rc, out, _ = run_cli("check", path, "--format", "json")
        self.assertEqual(rc, 0)
        self.assertEqual(out, json.dumps(json.loads(out), indent=2, sort_keys=True) + "\n")

    def test_invalid_json_output_format(self):
        path = self.write("b.json", "[")
        rc, out, _ = run_cli("check", path, "--format", "json")
        self.assertEqual(rc, 1)
        self.assertEqual(json.loads(out)["verdict"], "INVALID")

    def test_metadata_errors_are_prefixed(self):
        ok = self.write("ok.json", render(make_report(1)))
        meta = self.write("m.json", "{")
        rc, out, _ = run_cli("check", ok, "--metadata", meta)
        self.assertEqual(rc, 1)
        self.assertIn("metadata:/", out)

    def test_compare_metadata_command(self):
        self.assertEqual(run_cli("compare-metadata", str(METADATA))[0], 0)
        meta = metadata_doc()
        meta["casts"][0]["expect"] = "null"
        path = self.write("m.json", json.dumps(meta))
        rc, out, _ = run_cli("compare-metadata", path)
        self.assertEqual(rc, 3)
        self.assertTrue(out.startswith("UNRESOLVED"))

    def test_only_named_files_are_opened(self):
        ok = self.write("ok.json", render(make_report(1)))
        opened = []
        real_open = builtins.open
        real_listdir, real_scandir = os.listdir, os.scandir

        def spy_open(file, *a, **k):
            opened.append(str(file))
            return real_open(file, *a, **k)

        def refuse(*_a, **_k):
            raise AssertionError("directory listing is not allowed")

        builtins.open = spy_open
        os.listdir = os.scandir = refuse
        try:
            rc, _out, _err = run_cli("check", ok, "--metadata", str(METADATA))
        finally:
            builtins.open = real_open
            os.listdir, os.scandir = real_listdir, real_scandir
        self.assertEqual(rc, 0)
        self.assertEqual(opened, [ok, str(METADATA)])


class IsolationTests(unittest.TestCase):

    def setUp(self):
        self.tree = ast.parse(TOOL.read_text(encoding="utf-8"))

    def test_imports_are_limited(self):
        names = set()
        for node in ast.walk(self.tree):
            if isinstance(node, ast.Import):
                names.update(a.name.split(".")[0] for a in node.names)
            elif isinstance(node, ast.ImportFrom):
                names.add(node.module.split(".")[0])
        self.assertEqual(names, {"__future__", "argparse", "errno", "hashlib", "json", "os",
                                 "re", "stat", "sys", "pathlib"})

    def test_no_process_network_dynamic_code_or_writes(self):
        banned_names = {"eval", "exec", "compile", "__import__", "system", "popen", "spawn",
                        "remove", "unlink", "rmdir", "rename", "replace", "makedirs", "mkdir",
                        "chmod", "putenv", "environ", "getenv", "listdir", "scandir", "walk",
                        "startfile", "execv", "add_dll_directory"}
        for node in ast.walk(self.tree):
            if isinstance(node, ast.Attribute):
                if node.attr == "compile":   # re.compile is the only allowed use
                    self.assertEqual(getattr(node.value, "id", None), "re")
                    continue
                self.assertNotIn(node.attr, banned_names, node.attr)
            if isinstance(node, ast.Name):
                self.assertNotIn(node.id, banned_names, node.id)
        text = TOOL.read_text(encoding="utf-8")
        for word in ("subprocess", "socket", "urllib", "http.client", "ctypes", "winreg",
                     "telemetry"):
            self.assertNotIn(word, text)

    def test_open_is_read_only(self):
        for node in ast.walk(self.tree):
            if isinstance(node, ast.Call) and getattr(node.func, "id", None) == "open":
                self.assertEqual(node.args[1].value, "rb")

    def test_syntax_is_python_310(self):
        ast.parse(TOOL.read_text(encoding="utf-8"), feature_version=(3, 10))


def lf_sha256(path):
    return hashlib.sha256(path.read_bytes().replace(b"\r\n", b"\n")).hexdigest()


class PlanTests(unittest.TestCase):

    def setUp(self):
        self.plan = json.loads(PLAN.read_text(encoding="utf-8"))

    def bad(self, plan, code):
        with self.assertRaises(chk.InputError) as ctx:
            chk.validate_plan(plan)
        codes = {c for _w, c, _m in ctx.exception.errors}
        self.assertIn(code, codes)

    def test_plan_valid_and_not_run(self):
        s = chk.validate_plan(self.plan)
        self.assertEqual((s["compile_steps"], s["link_steps"], s["run_steps"],
                          s["check_steps"]), (3, 1, 2, 2))
        self.assertEqual(s["status"], "NOT_RUN")
        self.assertFalse(s["executed_by_this_tool"])
        results = [st["result"] for st in self.plan["steps"]]
        self.assertEqual(set(results), {"NOT_RUN"})
        self.assertEqual({i["value"] for i in self.plan["identity"]}, {"NOT_RUN"})
        self.assertEqual(self.plan["native_record"]["status"], "NOT_RUN")
        self.assertEqual(self.plan["object_reuse"]["result"], "NOT_RUN")

    def test_plan_file_is_canonical(self):
        hashes = {s["path"]: s["sha256_lf"] for s in self.plan["sources"]}
        self.assertEqual(self.plan, chk.canonical_plan(hashes))

    def test_source_hashes_match_files(self):
        for item in self.plan["sources"]:
            self.assertEqual(item["sha256_lf"], lf_sha256(ROOT / item["path"]), item["path"])

    def test_command_hashes(self):
        for step in self.plan["steps"]:
            self.assertEqual(step["command_sha256"], chk.command_sha256(step["argv"]))

    def test_reviewed_commands(self):
        steps = {s["id"]: s for s in self.plan["steps"]}
        self.assertEqual(steps["compile_producer"]["argv"], [
            "<CALLER_SUPPLIED_CL_EXE>", "/nologo", "/c", "/TP", "/X",
            "/I<CALLER_SUPPLIED_VC_INCLUDE>", "/GR", "/EHsc", "/W4", "/Od", "/MT",
            "/Fo<PRIVATE_OUT_DIR>/od_mt/obj/rtti_producer.obj",
            "tools/rtti-abi/fixture/rtti_producer.cpp"])
        self.assertIn("/Itools/rtti-abi/fixture", steps["compile_driver"]["argv"])
        self.assertEqual(steps["link"]["argv"][:6], [
            "<CALLER_SUPPLIED_LINK_EXE>", "/NOLOGO", "/MACHINE:X86", "/SUBSYSTEM:CONSOLE",
            "/INCREMENTAL:NO", "/MANIFEST:NO"])
        self.assertEqual(steps["run_one_cycle"]["argv"][1:], ["--cycles", "1"])
        self.assertEqual(steps["run_three_cycles"]["argv"][1:], ["--cycles", "3"])
        self.assertIn("--metadata", steps["check_one_cycle"]["argv"])

    def test_bounds(self):
        for step in self.plan["steps"]:
            self.assertLessEqual(step["timeout_seconds"], 120)
            self.assertLessEqual(step["stdout_limit_bytes"], chk.MAX_REPORT_BYTES)
            self.assertLessEqual(step["stderr_limit_bytes"], 16384)
            self.assertEqual(step["stdin"], "null_device")

    def test_outputs_isolated_and_distinct(self):
        outs = [o for s in self.plan["steps"] for o in s["outputs"]]
        self.assertEqual(len(outs), len(set(outs)))
        for o in outs:
            self.assertTrue(o.startswith("<PRIVATE_OUT_DIR>/"), o)
        self.assertFalse(self.plan["output_in_repository"])
        self.assertFalse(self.plan["native_record"]["in_repository"])

    def test_toolchain_never_discovered(self):
        tc = self.plan["toolchain"]
        self.assertFalse(tc["automatic_discovery"])
        self.assertFalse(tc["install"])
        self.assertFalse(tc["trusted_before_review"])
        self.assertIn("discover_compiler", self.plan["forbidden_operations"])
        self.assertIn("change_dll_search_path", self.plan["forbidden_operations"])

    def test_forbidden_compile_flags(self):
        for flag in ("/link", "/Fefoo.exe", "/Zi", "/Z7", "/GR-", "/EHa", "/MD", "/MTd",
                     "/DGAME=1", "/UX", "@args.rsp", "/FAs", "/Fa", "/FIx.h", "/E", "/P",
                     "/clr", "/LD", "/Yu", "-Zi"):
            plan = copy.deepcopy(self.plan)
            step = plan["steps"][0]
            step["argv"].insert(5, flag)
            step["command_sha256"] = chk.command_sha256(step["argv"])
            self.bad(plan, "E-PLAN-FORBIDDEN")

    def test_forbidden_link_flags(self):
        for flag in ("/DEBUG", "/debug", "/MAP", "/PDB:x.pdb", "/DLL", "/DEF:x.def",
                     "/NODEFAULTLIB", "/DEFAULTLIB:x.lib", "/INCLUDE:sym", "/ENTRY:main",
                     "/FORCE", "/ALTERNATENAME:a=b", "@link.rsp", "/OPT:REF", "/LTCG",
                     "/DELAYLOAD:x.dll", "/EXPORT:f"):
            plan = copy.deepcopy(self.plan)
            step = plan["steps"][3]
            step["argv"].insert(2, flag)
            step["command_sha256"] = chk.command_sha256(step["argv"])
            self.bad(plan, "E-PLAN-FORBIDDEN")

    def test_literal_paths_rejected(self):
        for text in ("C:\\VC\\bin\\cl.exe", "D:/sdk/lib", "\\\\server\\cl.exe",
                     "../outside/cl.exe", "/home/user/cl"):
            plan = copy.deepcopy(self.plan)
            plan["toolchain"]["placeholders"]["compiler"] = text
            self.bad(plan, "E-PLAN-PATH")

    def test_results_must_stay_not_run(self):
        for edit in ("status", "step", "identity", "native", "reuse"):
            plan = copy.deepcopy(self.plan)
            if edit == "status":
                plan["status"] = "PASS"
            elif edit == "step":
                plan["steps"][4]["result"] = "PASS"
            elif edit == "identity":
                plan["identity"][0]["value"] = "0" * 64
            elif edit == "native":
                plan["native_record"]["status"] = "PASS"
            else:
                plan["object_reuse"]["result"] = "PASS"
            self.bad(plan, "E-NOT-RUN")

    def test_native_record_outside_repository(self):
        plan = copy.deepcopy(self.plan)
        plan["native_record"]["in_repository"] = True
        self.bad(plan, "E-PLAN")

    def test_command_hash_mismatch(self):
        plan = copy.deepcopy(self.plan)
        plan["steps"][4]["command_sha256"] = "0" * 64
        self.bad(plan, "E-PLAN-HASH")

    def test_any_other_change_rejected(self):
        edits = [
            lambda p: p["steps"][4]["argv"].__setitem__(2, "4"),
            lambda p: p["steps"][4].__setitem__("timeout_seconds", 3600),
            lambda p: p["steps"][4].__setitem__("stdout_limit_bytes", 10 ** 9),
            lambda p: p["environments"]["run"]["set"].__setitem__("PATH", "<X>"),
            lambda p: p["environments"]["build"].__setitem__("inherit", True),
            lambda p: p["toolchain"].__setitem__("automatic_discovery", True),
            lambda p: p["steps"].pop(),
            lambda p: p.__setitem__("extra", 1),
            lambda p: p["forbidden_operations"].pop(),
            lambda p: p["sources"][0].__setitem__("sha256_lf", "x"),
        ]
        for edit in edits:
            plan = copy.deepcopy(self.plan)
            edit(plan)
            for step in plan["steps"]:
                step["command_sha256"] = chk.command_sha256(step["argv"])
            with self.assertRaises(chk.InputError):
                chk.validate_plan(plan)

    def test_check_plan_cli(self):
        rc, out, _ = run_cli("check-plan", str(PLAN))
        self.assertEqual(rc, 0)
        self.assertIn("NOT_RUN", out)


def strip_comments(text):
    text = re.sub(r"/\*.*?\*/", " ", text, flags=re.S)
    return re.sub(r"//[^\n]*", "", text)


def strip_strings(text):
    return re.sub(r'"(?:\\.|[^"\\])*"', '""', text)


class DriverSourceTests(unittest.TestCase):
    """Static review of the C++03 driver. The driver has never been compiled."""

    def setUp(self):
        self.raw = DRIVER.read_text(encoding="ascii")
        self.code = strip_comments(self.raw)
        self.bare = re.sub(r"^#include [^\n]*", "", strip_strings(self.code), flags=re.M)

    def test_ascii_lf_no_tabs(self):
        data = DRIVER.read_bytes()
        self.assertTrue(all(b < 128 for b in data))
        self.assertNotIn(b"\r", data)
        self.assertNotIn(b"\t", data)

    def test_includes(self):
        includes = re.findall(r"^#include ([<\"][^>\"]+[>\"])", self.raw, re.M)
        self.assertEqual(includes, ['"rtti_abi_fixture.h"', "<cstdio>", "<cstring>",
                                    "<exception>", "<new>", "<typeinfo>"])

    def test_cpp03_only(self):
        for token in (r"\bnullptr\b", r"\bconstexpr\b", r"\bstatic_assert\b", r"\bnoexcept\b",
                      r"\bdecltype\b", r"\boverride\b", r"\benum\s+class\b", r"=\s*delete\b",
                      r"=\s*default\b", r"\bauto\b", r"\blong\s+long\b", r"\bthread_local\b",
                      r"\[\]\s*\(", r"for\s*\([^;)]*:", r">>", r"\bstd::(unique_ptr|move|array)\b",
                      r"<cstdint>", r"\balignas\b", r"\busing\s+\w+\s*="):
            self.assertIsNone(re.search(token, self.bare), token)

    def test_no_addresses_or_raw_memory_printed(self):
        for token in (r"printf", r"%p", r"reinterpret_cast", r"intptr_t", r"uintptr_t",
                      r"\(\s*(int|long|unsigned)\s*\)\s*\w", r"memcpy", r"memcmp", r"fwrite",
                      r"cout", r"iostream", r"what\s*\("):
            self.assertIsNone(re.search(token, self.bare), token)

    def test_no_process_environment_or_dll_calls(self):
        for token in ("getenv", "GetEnvironment", "LoadLibrary", "GetProcAddress",
                      "SetDllDirectory", "AddDllDirectory", "SetDefaultDllDirectories",
                      "CreateProcess", "ShellExecute", "WinExec", "system(", "_popen", "fopen",
                      "socket", "windows.h", "__asm", "asm(", "#pragma", "__RTDynamicCast",
                      "__RTCastToVoid", "dynamic_cast", "typeid", "argv[0]"):
            self.assertNotIn(token, self.code, token)

    def test_no_allocation_or_fixture_definitions(self):
        self.assertIsNone(re.search(r"\bnew\b|\bdelete\b|\bmalloc\b|\bfree\s*\(", self.bare))
        for cls in ("SiRoot", "MiJoin", "ViBase", "AmJoin"):
            self.assertNotIn(cls + "::", self.code)
        self.assertNotIn("class Si", self.code)

    def test_fixture_entry_points_called_once_each(self):
        self.assertEqual(self.code.count("rtti_abi::create_fixture_objects("), 1)
        self.assertEqual(self.code.count("rtti_abi::destroy_fixture_objects("), 1)
        self.assertEqual(self.code.count("rtti_abi::run_cast_cases("), 1)
        self.assertIn("rtti_abi::run_cast_cases(objects, results, kCaseCount)", self.code)

    def test_guard_shape(self):
        guard = self.code[self.code.index("class FixtureGuard"):self.code.index("void fill_sentinel")]
        self.assertRegex(guard, r"private:\s*FixtureGuard\(const FixtureGuard&\);\s*"
                                r"FixtureGuard& operator=\(const FixtureGuard&\);")
        self.assertRegex(guard, r"~FixtureGuard\(\)\s*\{\s*release\(\);\s*\}")
        release = guard[guard.index("void release()"):]
        self.assertRegex(release, r"if \(!owned_\) \{\s*return;\s*\}\s*owned_ = false;\s*"
                                  r"\+\+destroy_calls_;\s*rtti_abi::destroy_fixture_objects")
        create = guard[guard.index("bool create()"):guard.index("void release()")]
        self.assertRegex(create, r"if \(attempted_\) \{\s*return false;\s*\}\s*attempted_ = true;")
        self.assertRegex(create, r"owned_ = true;\s*const bool created = "
                                 r"rtti_abi::create_fixture_objects\(objects_\);\s*"
                                 r"owned_ = created;")

    def test_cycle_handles_every_exception(self):
        body = self.code[self.code.index("void run_cycle"):self.code.index("bool cycle_structure_ok")]
        handlers = re.findall(r"catch \(([^)]*)\)", body)
        self.assertEqual(handlers, ["const std::bad_alloc&", "const std::bad_cast&",
                                    "const std::exception&", "...", "..."])
        self.assertIn("FixtureObjects objects;\n    clear_views(objects);", body)
        self.assertIn("CaseResult results[kCaseCount + 1];", body)

    def test_expected_ids_match_matrix(self):
        block = self.raw[self.raw.index("kExpectedIds[kCaseCount] = {"):]
        block = block[:block.index("};")]
        self.assertEqual(tuple(re.findall(r'"([A-Z]\d\d)"', block)), IDS)

    def test_view_lists_match_header(self):
        header = HEADER.read_text(encoding="utf-8")
        structs = dict(re.findall(r"struct (\w+Views) \{(.*?)\};", header, re.S))
        members = re.findall(r"^    (\w+Views) (\w+);", header, re.M)
        expected = [f"o.{obj}.{field}" for view, obj in members
                    for field in re.findall(r"\w+\* (\w+);", structs[view])]
        self.assertEqual(len(expected), 24)
        clear = re.findall(r"(o\.\w+\.\w+) = 0;", self.code)
        listed = re.findall(r"views\[i\+\+\] = (o\.\w+\.\w+);", self.code)
        self.assertEqual(clear, expected)
        self.assertEqual(listed, expected)
        self.assertIn("const int kViewCount = 24;", self.code)

    def test_report_keys_match_checker_schema(self):
        keys = set(re.findall(r'w\.key\("([a-z_]+)"\)', self.code))
        schema = set(chk.TOP_KEYS) | set(chk.CYCLE_KEYS) | set(chk.CASE_KEYS) | \
            set(chk.CLAIM_KEYS) | set(chk.OBSERVED_KEYS)
        self.assertEqual(keys, schema)

    def test_enum_names_match_checker(self):
        def names(fn):
            body = self.code[self.code.index(f"const char* {fn}("):]
            body = body[:body.index("\n}\n")]
            return set(re.findall(r'return "([a-z_]+)";', body))
        self.assertEqual(names("status_name"), set(chk.STATUSES))
        self.assertEqual(names("exception_name"), set(chk.EXCEPTION_KINDS))
        self.assertEqual(names("stage_name"), set(chk.EXCEPTION_STAGES))
        self.assertEqual(names("driver_status_name"), set(chk.DRIVER_EXIT))

    def test_exit_codes_match_checker(self):
        codes = dict(re.findall(r"kExit(\w+) = (\d)", self.code))
        self.assertEqual(codes, {"Ok": "0", "CaseFailure": "1", "Usage": "2",
                                 "StructureFailure": "3", "CreateFailed": "4",
                                 "Exception": "5", "OutputError": "6"})

    def test_constants_and_report_header(self):
        self.assertIn("const int kMaxCycles = 3;", self.code)
        self.assertIn("const int kSentinel = -1000;", self.code)
        for allowed in chk.FIELD_VALUES.values():
            self.assertNotIn(-1000, allowed)
        for text in ('w.text("fnv-rtti-runtime-report")', 'w.text("driver")',
                     'w.text("rtti_abi_fixture_v1")', 'w.text("unknown")'):
            self.assertIn(text, self.code)
        self.assertIn("CompileTimeCheck<rtti_abi::kCastCaseCount == 32>", self.code)

    def test_mirrored_rules_anchor_lines(self):
        for line in (
            "c.observed == rtti_abi::kOutcomeNotRun || c.observed != c.expected || c.passed != 1",
            "return c.result_matches == -1 && c.address_changed == -1 &&",
            "bool structure = attempted < requested;",
            "if (records[i].status != kCycleCompleted) {",
            "r.run_returned != kCaseCount || !r.guard_intact || r.destroy_calls != 1 ||",
        ):
            self.assertIn(line, self.code, line)

    def test_strings_written_are_constants_or_validated_ids(self):
        calls = re.findall(r"w\.text\((.*)\);$", self.code, re.M)
        self.assertEqual(len(calls), 9)
        for arg in calls:
            self.assertTrue(arg.startswith('"') or arg in (
                "c.id", "status_name(r.status)", "exception_name(r.exception_kind)",
                "stage_name(r.exception_stage)", "driver_status_name(exit_code)"), arg)
        self.assertIn("if (c.id_valid) {\n        w.text(c.id);", self.code)

    def test_argument_parsing_bounded(self):
        body = self.code[self.code.index("bool parse_arguments"):]
        body = body[:body.index("\n}\n")]
        self.assertIn('std::strcmp(argv[1], "--cycles") != 0', body)
        self.assertIn("n[0] < '1' || n[0] > '0' + kMaxCycles || n[1] != '\\0'", body)

    def test_output_errors_checked(self):
        self.assertIn("std::fputs(text, out_) < 0", self.code)
        self.assertIn("std::fflush(out_) != 0", self.code)
        self.assertIn("std::ferror(out_) != 0", self.code)
        self.assertIn("return kExitOutputError;", self.code)


class FixtureUnchangedTests(unittest.TestCase):

    def test_fixture_hashes_match_plan(self):
        plan = json.loads(PLAN.read_text(encoding="utf-8"))
        for item in plan["sources"]:
            if item["path"].startswith("tools/rtti-abi/"):
                self.assertEqual(lf_sha256(ROOT / item["path"]), item["sha256_lf"], item["path"])

    def test_delivery_holds_no_copy_of_fixture_files(self):
        fixture_names = {"rtti_abi_fixture.h", "rtti_producer.cpp", "rtti_consumer.cpp",
                         "fixture-metadata.json", "expected-ABI.md"}
        fixture_hashes = {lf_sha256(FIXTURE_DIR / n) for n in fixture_names - {"expected-ABI.md"}}
        fixture_hashes.add(lf_sha256(EXPECTED_ABI))
        for base in (TOOL_DIR, HERE):
            for path in base.rglob("*"):
                if path.is_file():
                    self.assertNotIn(path.name, fixture_names, path.name)
                    self.assertNotIn(lf_sha256(path), fixture_hashes, path.name)


class DocumentationTests(unittest.TestCase):

    def delivered(self):
        out = []
        for base in (TOOL_DIR, HERE):
            for p in sorted(base.rglob("*")):
                if p.is_file() and "__pycache__" not in p.parts:
                    out.append(p)
        return out

    def test_readme_lists_every_file(self):
        readme = (TOOL_DIR / "README.md").read_text(encoding="utf-8")
        for p in self.delivered():
            rel = p.relative_to(ROOT).as_posix()
            if "/samples/" in rel:
                continue
            self.assertIn(rel, readme, rel)
        self.assertIn("tests/rtti-runtime-probe/samples/", readme)

    def test_results_state_not_run(self):
        results = (TOOL_DIR / "RESULTS.md").read_text(encoding="utf-8")
        for item in ("Compile producer", "Compile consumer", "Compile driver", "Link",
                     "Run one cycle", "Run three cycles"):
            self.assertRegex(results, rf"\| {item} \| `NOT_RUN` \|")
        self.assertIn("claude-opus-5-5", results)

    def test_run_plan_doc_shows_exact_commands(self):
        doc = (TOOL_DIR / "RUN-PLAN.md").read_text(encoding="utf-8")
        plan = json.loads(PLAN.read_text(encoding="utf-8"))
        for step in plan["steps"]:
            self.assertIn(" ".join(step["argv"]), doc, step["id"])

    def test_no_private_paths_or_addresses(self):
        # The local account name is taken at run time, so it never appears in source.
        pattern = re.compile(r"[A-Za-z]:[\\/](?!/)|\\\\[A-Za-z]|/Users/|/home/|AppData|"
                             r"0x[0-9A-Fa-f]{5,}|" + re.escape(pathlib.Path.home().name),
                             re.IGNORECASE)
        for p in self.delivered():
            if p.suffix not in (".md", ".json", ".py", ".cpp"):
                continue
            text = p.read_text(encoding="utf-8")
            if p == pathlib.Path(__file__).resolve():
                continue  # this file holds the patterns themselves
            hits = [m.group(0) for m in pattern.finditer(text)]
            self.assertEqual(hits, [], p.name)

    def test_delivered_text_is_ascii_lf(self):
        for p in self.delivered():
            data = p.read_bytes()
            self.assertTrue(all(b < 128 for b in data), p.name)
            self.assertNotIn(b"\r\n", data, p.name)


if __name__ == "__main__":
    unittest.main()
