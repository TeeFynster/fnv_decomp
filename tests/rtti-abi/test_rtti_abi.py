"""Synthetic tests for tools/rtti-abi.

Every input here is invented. No compiler, linker, executable, object file,
game data or network is used, and no fixture is compiled or run.

Run from the repository root:
    python -m unittest discover -s tests/rtti-abi -p "test_*.py" -v
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
from unittest import mock

ROOT = pathlib.Path(__file__).resolve().parents[2]
TOOL_DIR = ROOT / "tools" / "rtti-abi"
FIXTURE_DIR = TOOL_DIR / "fixture"
EXAMPLES = TOOL_DIR / "examples"

_spec = importlib.util.spec_from_file_location("rtti_abi", TOOL_DIR / "rtti_abi.py")
ra = importlib.util.module_from_spec(_spec)
_spec.loader.exec_module(ra)


def load(path):
    return json.loads(pathlib.Path(path).read_text(encoding="utf-8"))


FIXTURE_META = load(FIXTURE_DIR / "fixture-metadata.json")
PLAN = load(TOOL_DIR / "compile-plan.json")


def run(argv):
    out, err = io.StringIO(), io.StringIO()
    code = ra.main(argv, stdout=out, stderr=err)
    return code, out.getvalue(), err.getvalue()


def errors_of(doc, validator=None):
    """Return the list of (pointer, code, message) for an invalid document."""
    validator = validator or ra.validate_metadata
    try:
        validator(doc)
    except ra.InputError as exc:
        return exc.errors
    raise AssertionError("document was accepted")


def codes(doc, validator=None):
    return [c for _w, c, _m in errors_of(doc, validator)]


def cls(cid, bases=(), poly=True):
    return {"id": cid, "polymorphic": poly,
            "bases": [{"class": b, "virtual": v, "access": a} for b, v, a in bases]}


def meta(classes, objects=(), casts=(), claims=None, measurements=None):
    doc = {"schema": "fnv-rtti-abi-metadata", "schema_version": 1, "fixture": "t",
           "classes": list(classes), "objects": [{"id": o, "class": c} for o, c in objects],
           "casts": list(casts)}
    if claims is not None:
        doc["layout_claims"] = list(claims)
    if measurements is not None:
        doc["measurements"] = list(measurements)
    return doc


def cast(cid, obj, path, target, expect, adjustment, form="pointer", **extra):
    d = {"id": cid, "form": form, "input": {"object": obj, "path": list(path)},
         "expect": expect, "adjustment": adjustment}
    if target is not None:
        d["target"] = target
    d.update(extra)
    return d


P, PRIV, PROT = "public", "private", "protected"
MI = [cls("L"), cls("R"), cls("J", [("L", False, P), ("R", False, P)])]


def detail(doc):
    return {d["id"]: d for d in ra.validate_metadata(doc)["cast_detail"]}


class Base(unittest.TestCase):
    def assertCodes(self, doc, *expected, validator=None):
        self.assertEqual(sorted(set(codes(doc, validator))), sorted(expected))


# ---------------------------------------------------------------- positive

class PositiveTests(Base):
    def test_fixture_metadata_is_valid(self):
        s = ra.validate_metadata(FIXTURE_META)
        self.assertEqual(s["classes"], 16)
        self.assertEqual(s["objects"], 8)
        self.assertEqual(s["casts"], {"total": 32, "success": 20, "null": 8, "bad_cast": 4})
        self.assertEqual(s["native_results"], "NOT_RUN")
        self.assertEqual(s["layout_claims"]["observed"], 0)
        self.assertEqual(s["measurements"], {"total": 1, "NOT_RUN": 1})

    # Expected results derived by hand from the C++ rules, independently of
    # the metadata file and of the validator.
    HAND = {
        "S01": ("success", "layout_dependent"), "S02": ("null", "not_applicable"),
        "S03": ("success", "layout_dependent"), "S04": ("bad_cast", "not_applicable"),
        "S05": ("success", "layout_dependent"), "S06": ("null", "not_applicable"),
        "S07": ("success", "layout_dependent"), "S08": ("success", "layout_dependent"),
        "M01": ("success", "nonzero"), "M02": ("success", "nonzero"),
        "M03": ("success", "layout_dependent"), "M04": ("null", "not_applicable"),
        "M05": ("bad_cast", "not_applicable"), "M06": ("success", "nonzero"),
        "M07": ("null", "not_applicable"), "M08": ("success", "layout_dependent"),
        "M09": ("null", "not_applicable"), "M10": ("success", "layout_dependent"),
        "V01": ("success", "layout_dependent"), "V02": ("success", "nonzero"),
        "V03": ("success", "layout_dependent"), "V04": ("null", "not_applicable"),
        "V05": ("bad_cast", "not_applicable"), "V06": ("success", "nonzero"),
        "V07": ("null", "not_applicable"), "V08": ("success", "layout_dependent"),
        "V09": ("success", "layout_dependent"), "A01": ("null", "not_applicable"),
        "A02": ("bad_cast", "not_applicable"), "A03": ("success", "layout_dependent"),
        "A04": ("success", "nonzero"), "A05": ("success", "nonzero"),
    }

    def test_fixture_casts_match_hand_derived_rules(self):
        got = {k: (v["outcome"], v["adjustment_computed"]) for k, v in detail(FIXTURE_META).items()}
        self.assertEqual(got, self.HAND)

    def test_fixture_mechanisms(self):
        d = detail(FIXTURE_META)
        self.assertEqual(d["S08"]["mechanism"], "static_conversion")
        for k in ("S06", "M07", "V07"):
            self.assertEqual(d[k]["mechanism"], "null_input")
        self.assertEqual(d["M01"]["mechanism"], "runtime_check")

    def test_fixture_covers_required_matrix(self):
        casts = FIXTURE_META["casts"]
        forms = {(c["form"], c["expect"]) for c in casts}
        for need in (("pointer", "success"), ("pointer", "null"), ("reference", "success"),
                     ("reference", "bad_cast"), ("void_pointer", "success")):
            self.assertIn(need, forms)
        self.assertTrue(any("null_of" in c["input"] for c in casts))
        self.assertTrue(any(c["adjustment"] == "nonzero" for c in casts))
        kinds = {c["id"][0] for c in casts}
        self.assertEqual(kinds, {"S", "M", "V", "A"})

    def test_valid_examples(self):
        for name in ("valid-minimal", "valid-diamond"):
            with self.subTest(name=name):
                code, out, err = run(["validate", str(EXAMPLES / f"{name}.json")])
                self.assertEqual((code, err), (0, ""))
                self.assertIn("OK: metadata is valid", out)

    def test_unknown_adjustment_is_kept_unknown(self):
        d = detail(load(EXAMPLES / "valid-minimal.json"))
        self.assertEqual(d["C6"]["adjustment_claimed"], "unknown")
        s = ra.validate_metadata(load(EXAMPLES / "valid-minimal.json"))
        self.assertEqual(s["adjustment"]["claimed_unknown_preserved"], 1)

    def test_unknown_accepted_for_every_computed_relation(self):
        doc = copy.deepcopy(FIXTURE_META)
        for c in doc["casts"]:
            c["adjustment"] = "unknown"
        s = ra.validate_metadata(doc)
        self.assertEqual(s["adjustment"]["claimed_unknown_preserved"], 32)

    def test_missing_optional_sections_stay_missing(self):
        s = ra.validate_metadata(meta(MI, [("j", "J")], [
            cast("X", "j", ["J", "L"], "R", "success", "nonzero")]))
        self.assertEqual(s["layout_claims"], {"unknown": 0, "hypothesis": 0, "observed": 0})
        self.assertEqual(s["measurements"], {"total": 0, "NOT_RUN": 0})
        self.assertEqual(s["native_results"], "NOT_RUN")

    def test_json_summary_says_nothing_verified_natively(self):
        code, out, _ = run(["validate", str(FIXTURE_DIR / "fixture-metadata.json"),
                            "--format", "json"])
        self.assertEqual(code, 0)
        s = json.loads(out)
        self.assertIn("Native results: NOT_RUN", s["not_verified"])
        self.assertEqual(s["layout_claims"]["observed"], 0)


# ---------------------------------------------------------------- C++ rules

class SemanticsTests(Base):
    def outcome(self, classes, obj_cls, path, target, form="pointer"):
        doc = meta(classes, [("o", obj_cls)], [cast("X", "o", path, target, "success",
                                                    "unknown", form=form)])
        try:
            d = detail(doc)["X"]
            return d["outcome"], d["adjustment_computed"]
        except ra.InputError as exc:
            for _w, code, message in exc.errors:
                if code == "E-OUTCOME":
                    return re.search(r"computed: (\w+)", message).group(1), None
            raise

    def test_downcast_and_failed_downcast(self):
        h = [cls("A"), cls("B", [("A", False, P)]), cls("C", [("A", False, P)])]
        self.assertEqual(self.outcome(h, "B", ["B", "A"], "B"), ("success", "layout_dependent"))
        self.assertEqual(self.outcome(h, "B", ["B", "A"], "C")[0], "null")
        self.assertEqual(self.outcome(h, "B", ["B", "A"], "C", "reference")[0], "bad_cast")

    def test_cross_cast_between_disjoint_polymorphic_bases_must_differ(self):
        self.assertEqual(self.outcome(MI, "J", ["J", "L"], "R"), ("success", "nonzero"))

    def test_disjoint_but_non_polymorphic_target_is_layout_dependent(self):
        h = [cls("L"), cls("E", poly=False), cls("J", [("L", False, P), ("E", False, P)])]
        self.assertEqual(self.outcome(h, "J", ["J", "L"], "E"), ("success", "layout_dependent"))

    def test_private_and_protected_bases_block_cross_cast(self):
        for access in (PRIV, PROT):
            with self.subTest(access=access):
                h = [cls("L"), cls("R"), cls("J", [("L", False, P), ("R", False, access)])]
                self.assertEqual(self.outcome(h, "J", ["J", "L"], "R")[0], "null")

    def test_input_reached_only_privately_cannot_downcast(self):
        h = [cls("L"), cls("R"), cls("J", [("L", False, P), ("R", False, PRIV)])]
        self.assertEqual(self.outcome(h, "J", ["J", "R"], "J")[0], "null")

    def test_ambiguous_target_fails(self):
        h = [cls("B"), cls("X", [("B", False, P)]), cls("Y", [("B", False, P)]), cls("T"),
             cls("J", [("X", False, P), ("Y", False, P), ("T", False, P)])]
        self.assertEqual(self.outcome(h, "J", ["J", "T"], "B")[0], "null")
        # From one B subobject to the sibling branch is an unambiguous cross-cast.
        self.assertEqual(self.outcome(h, "J", ["J", "Y", "B"], "X"), ("success", "nonzero"))

    def test_virtual_base_is_shared(self):
        h = [cls("V"), cls("L", [("V", True, P)]), cls("R", [("V", True, P)]),
             cls("J", [("L", False, P), ("R", False, P)])]
        self.assertEqual(self.outcome(h, "J", ["J", "L", "V"], "R"),
                         ("success", "layout_dependent"))
        doc = meta(h, [("o", "J")], [
            cast("A", "o", ["J", "L", "V"], "J", "success", "layout_dependent"),
            cast("B", "o", ["J", "R", "V"], "J", "success", "layout_dependent",
                 same_result_as="A")])
        ra.validate_metadata(doc)

    def test_non_virtual_diamond_bases_are_distinct(self):
        h = [cls("V"), cls("L", [("V", False, P)]), cls("R", [("V", False, P)]),
             cls("J", [("L", False, P), ("R", False, P)])]
        doc = meta(h, [("o", "J")], [
            cast("A", "o", ["J", "L", "V"], "R", "success", "nonzero"),
            cast("B", "o", ["J", "R", "V"], "R", "success", "layout_dependent",
                 same_result_as="A")])
        ra.validate_metadata(doc)  # both reach J's single R subobject
        doc["casts"][1].update(target="L", adjustment="nonzero")
        self.assertCodes(doc, "E-RESULT")

    def test_two_owning_subobjects_fall_back_to_ambiguous_cross_cast(self):
        # V is shared, and two distinct T subobjects contain it.
        h = [cls("V"), cls("T", [("V", True, P)]), cls("P1", [("T", False, P)]),
             cls("P2", [("T", False, P)]), cls("D", [("P1", False, P), ("P2", False, P)])]
        self.assertEqual(self.outcome(h, "D", ["D", "P1", "T", "V"], "T")[0], "null")

    def test_void_pointer_gives_complete_object(self):
        self.assertEqual(self.outcome(MI, "J", ["J", "R"], None, "void_pointer"),
                         ("success", "layout_dependent"))
        self.assertEqual(self.outcome(MI, "J", ["J"], None, "void_pointer"),
                         ("success", "none"))

    def test_identity_and_static_upcast(self):
        self.assertEqual(self.outcome(MI, "J", ["J"], "J"), ("success", "none"))
        d = detail(meta(MI, [("o", "J")], [cast("X", "o", ["J"], "R", "success", "unknown")]))
        self.assertEqual(d["X"]["mechanism"], "static_conversion")

    def test_static_upcast_from_non_polymorphic_source_is_allowed(self):
        h = [cls("A", poly=False), cls("B", [("A", False, P)], poly=False)]
        doc = meta(h, [("o", "B")], [cast("X", "o", ["B"], "A", "success", "layout_dependent")])
        ra.validate_metadata(doc)

    def test_ill_formed_casts_are_rejected(self):
        np = [cls("A", poly=False), cls("B", [("A", False, P)], poly=False)]
        cases = {
            "non-polymorphic downcast": (np, "B", ["B", "A"], "B", "pointer"),
            "non-polymorphic void": (np, "B", ["B", "A"], None, "void_pointer"),
            "ambiguous upcast": ([cls("V"), cls("L", [("V", False, P)]),
                                  cls("R", [("V", False, P)]),
                                  cls("J", [("L", False, P), ("R", False, P)])],
                                 "J", ["J"], "V", "pointer"),
            "inaccessible upcast": ([cls("A"), cls("B", [("A", False, PRIV)])],
                                    "B", ["B"], "A", "pointer"),
        }
        for name, (h, o, path, target, form) in cases.items():
            with self.subTest(name=name):
                doc = meta(h, [("o", o)], [cast("X", "o", path, target, "success",
                                                "unknown", form=form)])
                self.assertCodes(doc, "E-ILLFORMED")

    def test_null_input(self):
        doc = meta(MI, casts=[{"id": "N", "form": "pointer", "input": {"null_of": "L"},
                               "target": "R", "expect": "null",
                               "adjustment": "not_applicable"}])
        self.assertEqual(detail(doc)["N"]["mechanism"], "null_input")
        doc["casts"][0]["expect"] = "success"
        self.assertCodes(doc, "E-OUTCOME")
        doc["casts"][0].update(form="reference", expect="bad_cast")
        self.assertCodes(doc, "E-ILLFORMED")


class ClaimConflictTests(Base):
    def test_outcome_conflicts(self):
        for expect in ("null", "bad_cast"):
            doc = meta(MI, [("j", "J")], [cast("X", "j", ["J", "L"], "R", expect, "unknown")])
            self.assertCodes(doc, "E-OUTCOME")

    def test_promoting_layout_dependent_is_rejected(self):
        for claimed in ("none", "nonzero"):
            with self.subTest(claimed=claimed):
                doc = meta(MI, [("j", "J")], [cast("X", "j", ["J", "R"], "J", "success",
                                                   claimed)])
                errs = errors_of(doc)
                self.assertEqual([c for _w, c, _m in errs], ["E-ADJUST"])
                self.assertIn("promote", errs[0][2])

    def test_other_adjustment_conflicts(self):
        for claimed in ("layout_dependent", "none", "not_applicable"):
            doc = meta(MI, [("j", "J")], [cast("X", "j", ["J", "L"], "R", "success", claimed)])
            self.assertCodes(doc, "E-ADJUST")
        doc = meta(MI, [("l", "L")], [cast("X", "l", ["L"], "R", "null", "nonzero")])
        self.assertCodes(doc, "E-ADJUST")

    def test_result_path(self):
        doc = meta(MI, [("j", "J")], [cast("X", "j", ["J", "L"], "R", "success", "nonzero",
                                           result_path=["J", "L"])])
        self.assertCodes(doc, "E-RESULT")
        doc["casts"][0]["result_path"] = ["J", "Q"]
        self.assertCodes(doc, "E-PATH")
        doc = meta(MI, [("l", "L")], [cast("X", "l", ["L"], "R", "null", "not_applicable",
                                           result_path=["L"])])
        self.assertCodes(doc, "E-RESULT")

    def test_same_result_as(self):
        doc = meta(MI, [("j", "J"), ("k", "J")], [
            cast("A", "j", ["J", "L"], "J", "success", "layout_dependent"),
            cast("B", "k", ["J", "R"], "J", "success", "layout_dependent",
                 same_result_as="A")])
        self.assertCodes(doc, "E-RESULT")  # different objects
        doc["casts"][1]["same_result_as"] = "B"
        self.assertCodes(doc, "E-REF")
        doc["casts"][1]["same_result_as"] = "Nope"
        self.assertCodes(doc, "E-REF")

    def test_path_errors(self):
        for path in (["L"], ["J", "J"], ["J", "L", "R"], ["J", "Missing"]):
            with self.subTest(path=path):
                doc = meta(MI, [("j", "J")], [cast("X", "j", path, "R", "success", "unknown")])
                self.assertCodes(doc, "E-PATH")


# ---------------------------------------------------------------- structure

class StructureTests(Base):
    def test_top_level(self):
        self.assertCodes([], "E-SCHEMA")
        doc = meta(MI)
        doc["extra"] = 1
        self.assertCodes(doc, "E-SCHEMA")
        for key, value in (("schema", "other"), ("schema_version", 2),
                           ("schema_version", True), ("schema_version", 1.0)):
            with self.subTest(key=key, value=value):
                doc = meta(MI)
                doc[key] = value
                self.assertCodes(doc, "E-SCHEMA")
        doc = meta(MI)
        del doc["casts"]
        self.assertCodes(doc, "E-SCHEMA")

    def test_identifier_grammar(self):
        for bad in ("", "1A", "A-B", "A B", "Ä", "A" * 49, 7, None, "A\nB"):
            with self.subTest(bad=bad):
                self.assertCodes(meta([cls("A"), {"id": bad, "polymorphic": True,
                                                  "bases": []}]), "E-ID")

    def test_class_fields(self):
        for item in ({"id": "A", "polymorphic": 1, "bases": []},
                     {"id": "A", "polymorphic": True, "bases": {}},
                     {"id": "A", "polymorphic": True},
                     {"id": "A", "polymorphic": True, "bases": [], "size": 4}):
            with self.subTest(item=item):
                self.assertCodes(meta([item]), "E-SCHEMA")
        bad_base = {"class": "B", "virtual": "no", "access": "public"}
        self.assertCodes(meta([cls("B"), {"id": "A", "polymorphic": True,
                                          "bases": [bad_base]}]), "E-SCHEMA")
        bad_access = {"class": "B", "virtual": False, "access": "friend"}
        self.assertCodes(meta([cls("B"), {"id": "A", "polymorphic": True,
                                          "bases": [bad_access]}]), "E-SCHEMA")
        offset = {"class": "B", "virtual": False, "access": "public", "offset": 4}
        self.assertCodes(meta([cls("B"), {"id": "A", "polymorphic": True,
                                          "bases": [offset]}]), "E-SCHEMA")

    def test_empty_class_list(self):
        self.assertCodes(meta([]), "E-SCHEMA")

    def test_graph_problems(self):
        self.assertCodes(meta([cls("A", [("Z", False, P)])]), "E-REF")
        self.assertCodes(meta([cls("A", [("A", False, P)])]), "E-CYCLE")
        self.assertCodes(meta([cls("A", [("B", False, P)]), cls("B", [("A", False, P)])]),
                         "E-CYCLE")
        self.assertCodes(meta([cls("B"), cls("A", [("B", False, P), ("B", True, P)])]),
                         "E-BASE-DUP")
        self.assertCodes(meta([cls("A"), cls("A")]), "E-DUP")
        self.assertCodes(meta([cls("Abc"), cls("aBC")]), "E-DUP")
        self.assertCodes(meta([cls("A"), cls("B", [("A", False, P)], poly=False)]), "E-POLY")
        self.assertCodes(meta([cls("A"), cls("B", [("A", False, P)]),
                               cls("C", [("B", False, P)], poly=False)]), "E-POLY")

    def test_object_and_cast_references(self):
        self.assertCodes(meta(MI, [("o", "Missing")]), "E-REF")
        self.assertCodes(meta(MI, [("o", "J"), ("o", "L")]), "E-DUP")
        self.assertCodes(meta(MI, [("o", "J")], [cast("X", "q", ["J"], "L", "success",
                                                      "unknown")]), "E-REF")
        self.assertCodes(meta(MI, [("o", "J")], [cast("X", "o", ["J"], "Q", "success",
                                                      "unknown")]), "E-REF")
        self.assertCodes(meta(MI, casts=[{"id": "X", "form": "pointer",
                                          "input": {"null_of": "Q"}, "target": "L",
                                          "expect": "null", "adjustment": "not_applicable"}]),
                         "E-REF")
        two = [cast("X", "o", ["J"], "L", "success", "unknown")] * 2
        self.assertCodes(meta(MI, [("o", "J")], two), "E-DUP")

    def test_cast_fields(self):
        base = cast("X", "o", ["J", "L"], "R", "success", "nonzero")
        mutations = {
            "bad form": {"form": "static"},
            "bad expect": {"expect": "maybe"},
            "bad adjustment": {"adjustment": "4"},
            "extra key": {"offset": 4},
            "both inputs": {"input": {"object": "o", "path": ["J"], "null_of": "L"}},
            "input not object": {"input": "o"},
            "path not list": {"input": {"object": "o", "path": "J"}},
            "empty path": {"input": {"object": "o", "path": []}},
        }
        for name, change in mutations.items():
            with self.subTest(name=name):
                c = dict(base, **change)
                self.assertTrue(set(codes(meta(MI, [("o", "J")], [c]))) <= {"E-SCHEMA", "E-ID"})
        c = dict(base)
        del c["target"]
        self.assertCodes(meta(MI, [("o", "J")], [c]), "E-SCHEMA")
        c = dict(base, form="void_pointer")
        self.assertCodes(meta(MI, [("o", "J")], [c]), "E-SCHEMA")

    def test_limits(self):
        many = [cls(f"C{i}") for i in range(ra.MAX_CLASSES + 1)]
        self.assertCodes(meta(many), "E-LIMIT")
        bases = [cls(f"B{i}") for i in range(ra.MAX_BASES + 1)]
        wide = bases + [cls("W", [(b["id"], False, P) for b in bases])]
        self.assertCodes(meta(wide), "E-LIMIT")
        long_path = cast("X", "o", ["J"] * (ra.MAX_PATH + 1), "L", "success", "unknown")
        self.assertCodes(meta(MI, [("o", "J")], [long_path]), "E-LIMIT")
        casts = [cast(f"X{i}", "o", ["J"], "L", "success", "unknown")
                 for i in range(ra.MAX_CASTS + 1)]
        self.assertCodes(meta(MI, [("o", "J")], casts), "E-LIMIT")

    def test_subobject_explosion_is_bounded(self):
        classes, prev = [cls("D0")], "D0"
        for k in range(1, 12):  # each level doubles the base subobjects
            classes += [cls(f"A{k}", [(prev, False, P)]), cls(f"B{k}", [(prev, False, P)]),
                        cls(f"D{k}", [(f"A{k}", False, P), (f"B{k}", False, P)])]
            prev = f"D{k}"
        self.assertCodes(meta(classes), "E-LIMIT")

    def test_measurements(self):
        good = {"id": "N", "kind": "compile_only", "variant": "v", "result": "NOT_RUN"}
        ra.validate_metadata(meta(MI, measurements=[good]))
        for result in ("PASS", "OK", "FAIL", None, "not_run", ""):
            with self.subTest(result=result):
                self.assertCodes(meta(MI, measurements=[dict(good, result=result)]),
                                 "E-NOT-RUN")
        self.assertCodes(meta(MI, measurements=[dict(good, kind="link")]), "E-SCHEMA")
        self.assertCodes(meta(MI, measurements=[good, good]), "E-DUP")
        self.assertCodes(meta(MI, measurements=[dict(good, sha256="00")]), "E-SCHEMA")


# ---------------------------------------------------------------- layout claims

class LayoutClaimTests(Base):
    V = [cls("V"), cls("L", [("V", True, P)]), cls("N", poly=False), cls("J", [("L", False, P)])]

    def claim(self, **kw):
        d = {"id": "K", "record": "type_descriptor", "class": "L", "property": "emitted",
             "status": "unknown"}
        d.update(kw)
        return d

    def check(self, *claims):
        return ra.validate_metadata(meta(self.V, claims=claims))

    def test_valid_claims(self):
        s = self.check(
            self.claim(),
            self.claim(id="K2", status="hypothesis", expect="present", **{"class": "J"}),
            self.claim(id="K3", record="vbtable", status="hypothesis", expect="present"),
            self.claim(id="K4", record="base_class_descriptor", base_path=["L", "V"],
                       property="vdisp"),
            self.claim(id="K5", record="class_hierarchy_descriptor",
                       property="virtual_inheritance_flag", status="hypothesis", expect="set"),
            self.claim(id="K6", record="complete_object_locator", property="offset_field",
                       base_path=["J", "L", "V"], **{"class": "J"}),
        )
        self.assertEqual(s["layout_claims"], {"unknown": 3, "hypothesis": 3, "observed": 0})

    def test_observed_is_not_representable(self):
        errs = errors_of(meta(self.V, claims=[self.claim(status="observed")]))
        self.assertEqual([c for _w, c, _m in errs], ["E-OBSERVED"])
        for status in ("measured", "confirmed", "", None):
            self.assertCodes(meta(self.V, claims=[self.claim(status=status)]), "E-SCHEMA")

    def test_values_cannot_be_recorded(self):
        for extra in ({"value": 4}, {"offset": 0}, {"name": "x"}, {"evidence": ["N"]}):
            with self.subTest(extra=extra):
                self.assertCodes(meta(self.V, claims=[self.claim(**extra)]), "E-SCHEMA")

    def test_unknown_with_expectation_is_rejected(self):
        self.assertCodes(meta(self.V, claims=[self.claim(expect="present")]), "E-CLAIM")

    def test_hypothesis_rules(self):
        bad = [
            self.claim(status="hypothesis"),                                  # no expect
            self.claim(property="name_string", status="hypothesis", expect="present"),
            self.claim(record="base_class_descriptor", base_path=["L", "V"],
                       property="pdisp", status="hypothesis", expect="zero"),
        ]
        for c in bad:
            with self.subTest(claim=c):
                self.assertCodes(meta(self.V, claims=[c]), "E-CLAIM")
        self.assertCodes(meta(self.V, claims=[self.claim(status="hypothesis", expect="zero")]),
                         "E-SCHEMA")

    def test_claims_that_contradict_the_hierarchy(self):
        bad = [
            # A non-polymorphic class has no vftable.
            self.claim(record="vftable", status="hypothesis", expect="present",
                       **{"class": "N"}),
            # V has no virtual base, so no vbtable.
            self.claim(record="vbtable", status="hypothesis", expect="present",
                       **{"class": "V"}),
            # L has a virtual base; V does not.
            self.claim(record="class_hierarchy_descriptor", property="virtual_inheritance_flag",
                       status="hypothesis", expect="clear"),
            self.claim(record="class_hierarchy_descriptor", property="virtual_inheritance_flag",
                       status="hypothesis", expect="set", **{"class": "V"}),
            # A class is at displacement zero from itself.
            self.claim(record="base_class_descriptor", base_path=["L"], property="mdisp",
                       status="hypothesis", expect="nonzero"),
        ]
        for c in bad:
            with self.subTest(claim=c):
                self.assertCodes(meta(self.V, claims=[c]), "E-CLAIM")

    def test_claim_references_and_paths(self):
        self.assertCodes(meta(self.V, claims=[self.claim(**{"class": "Q"})]), "E-REF")
        self.assertCodes(meta(self.V, claims=[self.claim(record="base_class_descriptor",
                                                         property="vdisp")]), "E-SCHEMA")
        self.assertCodes(meta(self.V, claims=[self.claim(base_path=["L", "V"])]), "E-SCHEMA")
        self.assertCodes(meta(self.V, claims=[self.claim(record="base_class_descriptor",
                                                         base_path=["J", "V"],
                                                         property="vdisp")]), "E-PATH")
        self.assertCodes(meta(self.V, claims=[self.claim(record="nope")]), "E-SCHEMA")
        self.assertCodes(meta(self.V, claims=[self.claim(property="mdisp")]), "E-SCHEMA")

    def test_duplicate_claims(self):
        self.assertCodes(meta(self.V, claims=[self.claim(), self.claim()]), "E-DUP")
        self.assertCodes(meta(self.V, claims=[self.claim(), self.claim(id="K2")]), "E-DUP")


# ---------------------------------------------------------------- examples

class ExampleTests(Base):
    EXPECTED = {
        "invalid-missing-reference": "E-REF",
        "invalid-duplicate-class": "E-DUP",
        "invalid-cycle": "E-CYCLE",
        "invalid-polymorphic-conflict": "E-POLY",
        "invalid-conflicting-outcome": "E-OUTCOME",
        "invalid-promoted-adjustment": "E-ADJUST",
        "invalid-null-reference": "E-ILLFORMED",
        "invalid-observed-claim": "E-OBSERVED",
        "invalid-native-result": "E-NOT-RUN",
        "invalid-same-result": "E-RESULT",
    }

    def test_each_invalid_example_fails_for_its_one_reason(self):
        names = sorted(p.stem for p in EXAMPLES.glob("invalid-*.json"))
        self.assertEqual(names, sorted(self.EXPECTED))
        for name, code in self.EXPECTED.items():
            with self.subTest(name=name):
                rc, out, err = run(["validate", str(EXAMPLES / f"{name}.json")])
                self.assertEqual((rc, out), (1, ""))
                found = re.findall(r"^  \S+: (E-[A-Z-]+): ", err, re.M)
                self.assertEqual(found, [code])

    def test_examples_use_invented_names_only(self):
        for path in EXAMPLES.glob("*.json"):
            text = path.read_text(encoding="utf-8")
            self.assertNotRegex(text, r"0x[0-9A-Fa-f]|[A-Za-z]:[\\/]|\\\\")


# ---------------------------------------------------------------- JSON input

class JsonInputTests(Base):
    def rejected(self, data):
        with self.assertRaises(ra.InputError) as ctx:
            ra.parse_json_bytes(data)
        return [c for _w, c, _m in ctx.exception.errors]

    def test_malformed(self):
        for data in (b"", b"{", b"{'a': 1}", b"[1,]", b'{"a": 1} x'):
            self.assertEqual(self.rejected(data), ["E-JSON"])

    def test_non_finite_and_duplicates(self):
        self.assertEqual(self.rejected(b'{"a": NaN}'), ["E-JSON"])
        self.assertEqual(self.rejected(b'{"a": Infinity}'), ["E-JSON"])
        self.assertEqual(self.rejected(b'{"a": 1, "a": 2}'), ["E-DUPKEY"])

    def test_encoding(self):
        self.assertEqual(self.rejected(b"\xef\xbb\xbf{}"), ["E-ENCODING"])
        self.assertEqual(self.rejected(b'{"a": "\xff"}'), ["E-ENCODING"])

    def test_size_and_depth(self):
        self.assertEqual(self.rejected(b" " * (ra.MAX_INPUT_BYTES + 1)), ["E-LIMIT"])
        deep = b"[" * (ra.MAX_DEPTH + 1) + b"]" * (ra.MAX_DEPTH + 1)
        self.assertEqual(self.rejected(deep), ["E-LIMIT"])
        self.assertEqual(self.rejected(b"[" * 100000), ["E-LIMIT"])
        ok = b"[" * ra.MAX_DEPTH + b"]" * ra.MAX_DEPTH
        self.assertEqual(ra.parse_json_bytes(ok), [[[[[[[[]]]]]]]])

    def test_brackets_inside_strings_do_not_count(self):
        ra.parse_json_bytes(json.dumps({"a": "[" * 50 + "\\\"" + "{" * 50}).encode())

    def test_fixture_depth_is_within_limit(self):
        text = (FIXTURE_DIR / "fixture-metadata.json").read_text(encoding="utf-8")
        self.assertLessEqual(ra._max_depth(text), ra.MAX_DEPTH)


# ---------------------------------------------------------------- CLI and privacy

class CliTests(Base):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.dir = pathlib.Path(self.tmp.name)

    def tearDown(self):
        self.tmp.cleanup()

    def write(self, name, data):
        p = self.dir / name
        p.write_bytes(data if isinstance(data, bytes) else json.dumps(data).encode())
        return str(p)

    def test_exit_codes(self):
        self.assertEqual(run(["validate", self.write("ok.json", meta(MI))])[0], 0)
        self.assertEqual(run(["validate", self.write("bad.json", meta([]))])[0], 1)
        self.assertEqual(run(["validate", str(self.dir / "missing.json")])[0], 2)
        self.assertEqual(run(["validate", str(self.dir)])[0], 2)
        self.assertEqual(run([])[0], 2)
        self.assertEqual(run(["compile", "x"])[0], 2)
        self.assertEqual(run(["validate", "x", "--format", "xml"])[0], 2)
        self.assertEqual(run(["check-plan", str(TOOL_DIR / "compile-plan.json")])[0], 0)
        self.assertEqual(run(["check-plan", str(FIXTURE_DIR / "fixture-metadata.json")])[0], 1)

    def test_unsafe_input_paths_refused_before_access(self):
        with mock.patch.object(ra.os, "lstat", side_effect=AssertionError("touched")), \
                mock.patch.object(builtins, "open", side_effect=AssertionError("touched")):
            for path in ("\\\\server\\share\\m.json", "//server/share/m.json",
                         "\\\\?\\C:\\m.json", "\\\\.\\pipe\\x", "NUL", "con.json",
                         "dir/COM1", "", "a\x00b"):
                with self.subTest(path=path):
                    code, out, err = run(["validate", path])
                    self.assertEqual(code, 2)
                    self.assertNotIn("touched", err)

    def test_links_are_refused(self):
        target = self.write("t.json", meta(MI))
        fake = os.stat_result((0o120777, 0, 0, 1, 0, 0, 10, 0, 0, 0))
        with mock.patch.object(ra.os, "lstat", return_value=fake):
            code, _out, err = run(["validate", target])
        self.assertEqual(code, 2)
        self.assertIn("link", err)

    def test_oversized_file(self):
        p = self.write("big.json", b" " * (ra.MAX_INPUT_BYTES + 1))
        code, _out, err = run(["validate", p])
        self.assertEqual(code, 1)
        self.assertIn("E-LIMIT", err)

    def test_diagnostics_are_stable_and_do_not_echo(self):
        secret = "C:/Users/zzSecretzz/private"
        doc = meta([cls("A"), {"id": secret, "polymorphic": True, "bases": []}],
                   [("o", "A")],
                   [cast("X", "o", [secret], "A", "success", secret)])
        doc[secret] = secret
        p = self.write("secret.json", doc)
        first, second = run(["validate", p]), run(["validate", p])
        self.assertEqual(first, second)
        code, out, err = first
        self.assertEqual(code, 1)
        self.assertNotIn("zzSecretzz", err + out)
        self.assertNotIn(str(self.dir), err + out)
        self.assertNotIn(self.dir.name, err + out)
        for line in err.splitlines()[1:]:
            self.assertRegex(line, r"^  /\S*: E-[A-Z-]+: [ -~]+$")

    def test_usage_errors_do_not_echo_arguments(self):
        for argv in (["validate"], ["zzSecretzz"], ["validate", "a", "--zzSecretzz"]):
            code, out, err = run(argv)
            self.assertEqual(code, 2)
            self.assertNotIn("zzSecretzz", out + err)
        code, _o, err = run(["validate", str(self.dir / "zzSecretzz.json")])
        self.assertEqual(code, 2)
        self.assertNotIn("zzSecretzz", err)

    def test_error_count_is_capped_but_total_reported(self):
        doc = meta([{"id": f"{i}bad", "polymorphic": True, "bases": []} for i in range(60)])
        code, _out, err = run(["validate", self.write("many.json", doc)])
        self.assertEqual(code, 1)
        self.assertIn("(60 problem(s), 50 shown)", err)
        self.assertEqual(len(err.splitlines()), 51)

    def test_only_the_named_file_is_touched(self):
        target = self.write("m.json", FIXTURE_META)
        touched = []
        real_open, real_lstat = builtins.open, os.lstat

        def rec(fn):
            def inner(path, *a, **k):
                touched.append(os.fspath(path))
                return fn(path, *a, **k)
            return inner

        def forbid(*_a, **_k):
            raise AssertionError("unexpected file access")

        with mock.patch("gettext.find", return_value=None), \
                mock.patch.object(builtins, "open", rec(real_open)), \
                mock.patch.object(ra.os, "lstat", rec(real_lstat)), \
                mock.patch.object(ra.os, "stat", forbid), \
                mock.patch.object(ra.os, "listdir", forbid), \
                mock.patch.object(ra.os, "scandir", forbid), \
                mock.patch.object(ra.os.path, "exists", forbid), \
                mock.patch.object(ra.os.path, "isfile", forbid):
            for command in ("validate", "check-plan"):
                run([command, target])
        self.assertIn(target, touched)
        self.assertTrue(all(pathlib.Path(path).resolve() in (pathlib.Path(target).resolve(), *pathlib.Path(target).resolve().parents) for path in touched))


class IsolationTests(Base):
    SOURCE = (TOOL_DIR / "rtti_abi.py").read_text(encoding="utf-8")

    def test_imports_are_standard_library_allowlist(self):
        tree = ast.parse(self.SOURCE)
        names = set()
        for node in ast.walk(tree):
            if isinstance(node, ast.Import):
                names |= {a.name.split(".")[0] for a in node.names}
            elif isinstance(node, ast.ImportFrom):
                names.add(node.module.split(".")[0])
        self.assertLessEqual(names, {"__future__", "argparse", "errno", "json", "os", "re",
                                     "stat", "sys", "pathlib"})

    def test_no_process_network_or_dynamic_code(self):
        for word in ("subprocess", "socket", "urllib", "http.", "ctypes", "shutil",
                     "importlib", "os.system", "os.popen", "os.spawn", "os.exec",
                     "os.startfile", "os.remove", "os.unlink", "os.walk", "glob"):
            self.assertNotIn(word, self.SOURCE)
        self.assertNotRegex(self.SOURCE, r"(?<![.\w])(eval|exec|compile|__import__)\s*\(")

    def test_tool_writes_nothing(self):
        self.assertNotRegex(self.SOURCE, r"open\([^)]*['\"][wax]")
        self.assertNotIn(".write_", self.SOURCE)


# ---------------------------------------------------------------- compile plan

class PlanTests(Base):
    def mutate(self, fn):
        doc = copy.deepcopy(PLAN)
        fn(doc)
        return doc

    def plan_codes(self, fn):
        return set(codes(self.mutate(fn), ra.validate_plan))

    def step(self, doc, i=0):
        return doc["variants"][0]["steps"][i]

    def test_plan_is_valid_and_not_run(self):
        s = ra.validate_plan(PLAN)
        self.assertEqual((s["compile_steps"], s["link_steps"], s["run_steps"]), (2, 0, 0))
        self.assertFalse(s["executed_by_this_tool"])
        self.assertEqual(PLAN["status"], "NOT_RUN")
        for step in PLAN["variants"][0]["steps"]:
            self.assertEqual(step["result"], "NOT_RUN")
            self.assertIn("/c", step["argv"])
            self.assertIn("/GR", step["argv"])
            self.assertIn("/EHsc", step["argv"])
        self.assertTrue(all(i["value"] == "NOT_RUN" for i in PLAN["identity"]))

    def test_source_hashes_match_delivered_files(self):
        for src in PLAN["sources"]:
            data = (ROOT / src["path"]).read_bytes().replace(b"\r\n", b"\n")
            self.assertEqual(hashlib.sha256(data).hexdigest(), src["sha256_lf"], src["path"])

    def test_results_must_stay_not_run(self):
        for value in ("PASS", "OK", "RUN", None, 0):
            with self.subTest(value=value):
                self.assertEqual(self.plan_codes(
                    lambda d: self.step(d).update(result=value)), {"E-NOT-RUN"})
        self.assertEqual(self.plan_codes(lambda d: d.update(status="DONE")), {"E-NOT-RUN"})
        self.assertEqual(self.plan_codes(lambda d: d["identity"][0].update(value="ab" * 32)),
                         {"E-NOT-RUN"})

    def test_forbidden_arguments(self):
        for arg in ("/link", "/Fe<PRIVATE_OUT_DIR>/x.exe", "/LD", "/MD", "/GR-", "/EHa",
                    "/Zi", "/Z7", "/Fa<PRIVATE_OUT_DIR>/x.asm", "/FAs", "/P", "/E", "/EP",
                    "/clr", "@args.rsp", "/DGAME=1", "/FIforced.h", "-link", "/Yu", "/analyze"):
            with self.subTest(arg=arg):
                self.assertEqual(self.plan_codes(
                    lambda d: self.step(d)["argv"].insert(5, arg)), {"E-PLAN-FORBIDDEN"})

    def test_argv_must_be_the_reviewed_command(self):
        for fn in (lambda a: a.remove("/GR"), lambda a: a.remove("/EHsc"),
                   lambda a: a.remove("/c"), lambda a: a.remove("/X"),
                   lambda a: a.append("/O2"), lambda a: a.insert(1, a.pop(2)),
                   lambda a: a.__setitem__(-1, "tools/rtti-abi/fixture/rtti_consumer.cpp"),
                   lambda a: a.__setitem__(-2, "/Fobuild/rtti_producer.obj"),
                   lambda a: a.__setitem__(5, "/IC:/vc/include")):
            with self.subTest(fn=fn):
                self.assertEqual(self.plan_codes(lambda d: fn(self.step(d)["argv"])),
                                 {"E-PLAN-ARGV"})

    def test_compiler_must_be_the_caller_supplied_placeholder(self):
        for exe in ("cl.exe", "cl", "C:/vc/bin/cl.exe", "<DISCOVERED_CL>"):
            with self.subTest(exe=exe):
                self.assertEqual(self.plan_codes(
                    lambda d: self.step(d)["argv"].__setitem__(0, exe)), {"E-PLAN"})
        for key, value in (("automatic_discovery", True), ("trusted_before_review", True),
                           ("placeholder", "cl.exe"), ("selection", ["auto"])):
            with self.subTest(key=key):
                self.assertTrue(self.plan_codes(lambda d: d["compiler"].update({key: value})))

    def test_outputs_and_sources(self):
        self.assertEqual(self.plan_codes(lambda d: self.step(d).update(
            outputs=["build/x.obj"])), {"E-PLAN"})
        self.assertEqual(self.plan_codes(lambda d: self.step(d).update(
            outputs=[])), {"E-PLAN"})
        self.assertTrue(self.plan_codes(lambda d: d["sources"].append(
            {"path": "tools/other.cpp", "role": "compile", "sha256_lf": "0" * 64})))
        self.assertEqual(self.plan_codes(lambda d: d["sources"][0].update(sha256_lf="xyz")),
                         {"E-PLAN"})
        self.assertEqual(self.plan_codes(lambda d: d["sources"][0].update(role="compile")),
                         {"E-PLAN"})
        self.assertTrue(self.plan_codes(lambda d: self.step(d).update(
            source="tools/rtti-abi/fixture/rtti_abi_fixture.h")))
        self.assertTrue(self.plan_codes(lambda d: d["variants"][0]["steps"].pop()))
        self.assertTrue(self.plan_codes(lambda d: d["variants"].append(
            copy.deepcopy(d["variants"][0]))))

    def test_environment_is_closed(self):
        self.assertEqual(self.plan_codes(lambda d: d["environment"]["set"].update(
            CL="/link")), {"E-PLAN"})
        self.assertEqual(self.plan_codes(lambda d: d["environment"]["unset"].remove("CL")),
                         {"E-PLAN"})
        self.assertEqual(self.plan_codes(lambda d: d["environment"].update(inherit=True)),
                         {"E-SCHEMA"})
        self.assertEqual(self.plan_codes(lambda d: d.update(cwd="C:/checkout")), {"E-SCHEMA"})

    def test_forbidden_operations_are_listed(self):
        self.assertEqual(self.plan_codes(lambda d: d["forbidden_operations"].remove("link")),
                         {"E-PLAN"})
        self.assertEqual(set(PLAN["forbidden_operations"]),
                         {"discover_compiler", "install_toolchain", "link", "run_fixture",
                          "extract_rtti_from_binary", "select_game_alias",
                          "change_runtime_provider"})

    def test_plan_contains_placeholders_not_paths(self):
        text = (TOOL_DIR / "compile-plan.json").read_text(encoding="utf-8")
        self.assertNotRegex(text, r"[A-Za-z]:[\\/]|\\\\|/Users/|/home/")
        for ph in ("<CALLER_SUPPLIED_CL_EXE>", "<CALLER_SUPPLIED_VC_INCLUDE>",
                   "<PRIVATE_OUT_DIR>", "<CHECKOUT_ROOT>"):
            self.assertIn(ph, text)


# ---------------------------------------------------------------- C++ sources

HEADER = (FIXTURE_DIR / "rtti_abi_fixture.h").read_text(encoding="utf-8")
PRODUCER = (FIXTURE_DIR / "rtti_producer.cpp").read_text(encoding="utf-8")
CONSUMER = (FIXTURE_DIR / "rtti_consumer.cpp").read_text(encoding="utf-8")

# Each producer view: the object it belongs to and its base path.
VIEWS = {
    "si_leaf.complete": ("si_leaf", ["SiLeaf"]),
    "si_leaf.as_mid": ("si_leaf", ["SiLeaf", "SiMid"]),
    "si_leaf.as_root": ("si_leaf", ["SiLeaf", "SiMid", "SiRoot"]),
    "si_mid.complete": ("si_mid", ["SiMid"]),
    "si_mid.as_root": ("si_mid", ["SiMid", "SiRoot"]),
    "mi_join.complete": ("mi_join", ["MiJoin"]),
    "mi_join.as_left": ("mi_join", ["MiJoin", "MiLeft"]),
    "mi_join.as_right": ("mi_join", ["MiJoin", "MiRight"]),
    "mi_left.complete": ("mi_left", ["MiLeft"]),
    "mi_sealed.complete": ("mi_sealed", ["MiSealed"]),
    "mi_sealed.as_left": ("mi_sealed", ["MiSealed", "MiLeft"]),
    "vi_join.complete": ("vi_join", ["ViJoin"]),
    "vi_join.as_left": ("vi_join", ["ViJoin", "ViLeft"]),
    "vi_join.as_right": ("vi_join", ["ViJoin", "ViRight"]),
    "vi_join.as_base_via_left": ("vi_join", ["ViJoin", "ViLeft", "ViBase"]),
    "vi_join.as_base_via_right": ("vi_join", ["ViJoin", "ViRight", "ViBase"]),
    "vi_left.complete": ("vi_left", ["ViLeft"]),
    "vi_left.as_base": ("vi_left", ["ViLeft", "ViBase"]),
    "am_join.complete": ("am_join", ["AmJoin"]),
    "am_join.as_left": ("am_join", ["AmJoin", "AmLeft"]),
    "am_join.as_right": ("am_join", ["AmJoin", "AmRight"]),
    "am_join.as_tag": ("am_join", ["AmJoin", "AmTag"]),
    "am_join.as_left_base": ("am_join", ["AmJoin", "AmLeft", "AmBase"]),
    "am_join.as_right_base": ("am_join", ["AmJoin", "AmRight", "AmBase"]),
}

_CASE_LINE = re.compile(
    r"^    (pointer_case|pointer_fail_case|reference_case|reference_fail_case|null_input_case"
    r"|void_case)(?:<([\w, ]+)>)?\(sink, \"(\w+)\"(?:, (.*))?\);$", re.M)


def header_classes():
    out = {}
    for name, bases in re.findall(r"^class (\w+)(?: : ([^{]+))? \{$", HEADER, re.M):
        parsed = []
        for part in filter(None, (bases or "").split(", ")):
            m = re.fullmatch(r"(public|protected|private)( virtual)? (\w+)", part.strip())
            parsed.append({"class": m.group(3), "virtual": bool(m.group(2)),
                           "access": m.group(1)})
        out[name] = parsed
    return out


def header_structs():
    out = {}
    for name, body in re.findall(r"^struct (\w+) \{\n(.*?)^\};", HEADER, re.M | re.S):
        out[name] = dict((f, t) for t, f in re.findall(r"^    (\w+)\* (\w+);", body, re.M))
    return out


def consumer_cases():
    rows = []
    for kind, targs, cid, args in _CASE_LINE.findall(CONSUMER):
        rows.append((kind, [t.strip() for t in targs.split(",")] if targs else [], cid,
                     [a.strip() for a in args.split(", ")] if args else []))
    return rows


def view(expr):
    expr = expr.lstrip("*")
    assert expr.startswith("o."), expr
    return VIEWS[expr[2:]]


class FixtureSourceTests(Base):
    def test_header_hierarchy_matches_metadata(self):
        meta_classes = {c["id"]: c["bases"] for c in FIXTURE_META["classes"]}
        self.assertEqual(header_classes(), meta_classes)

    def test_every_class_is_polymorphic_with_out_of_line_members(self):
        for name in header_classes():
            with self.subTest(name=name):
                self.assertRegex(HEADER, rf"\n    virtual ~{name}\(\);")
                self.assertIn(f"\n{name}::{name}() : ", PRODUCER)
                self.assertIn(f"\n{name}::~{name}() {{}}", PRODUCER)
        self.assertTrue(all(c["polymorphic"] for c in FIXTURE_META["classes"]))

    def test_views_match_header_and_hierarchy(self):
        structs = header_structs()
        members = dict((f, t) for t, f in re.findall(r"^    (\w+Views) (\w+);", HEADER, re.M))
        hierarchy = ra._Hierarchy({c["id"]: c for c in FIXTURE_META["classes"]})
        objects = {o["id"]: o["class"] for o in FIXTURE_META["objects"]}
        declared = {f"{m}.{f}" for m, s in members.items() for f in structs[s]}
        self.assertEqual(declared, set(VIEWS))
        for key, (obj, path) in VIEWS.items():
            with self.subTest(view=key):
                group, field = key.split(".")
                self.assertEqual(obj, group)
                self.assertEqual(structs[members[group]][field], path[-1])
                self.assertEqual(path[0], objects[obj])
                self.assertIsNotNone(hierarchy.layout(path[0]).resolve(path))

    def test_producer_fills_views_by_static_conversion(self):
        for key, (_obj, path) in VIEWS.items():
            group, field = key.split(".")
            if field == "complete":
                self.assertIn(f"out.{key} = new {path[0]}();", PRODUCER)
                continue
            m = re.search(rf"^        out\.{re.escape(key)} = (.+);$", PRODUCER, re.M)
            self.assertIsNotNone(m, key)
            rhs = m.group(1)
            via = re.fullmatch(rf"static_cast<(\w+)\*>\(out\.{group}\.complete\)", rhs)
            if via:  # explicit intermediate base, used where the target is ambiguous
                self.assertIn(via.group(1), path[1:-1])
            else:
                self.assertEqual(rhs, f"out.{group}.complete")
        self.assertNotRegex(PRODUCER, r"\bdynamic_cast\s*<")

    def test_consumer_cases_match_metadata(self):
        rows = consumer_cases()
        casts = FIXTURE_META["casts"]
        self.assertEqual([r[2] for r in rows], [c["id"] for c in casts])
        count = int(re.search(r"kCastCaseCount = (\d+)", HEADER).group(1))
        self.assertEqual(count, len(casts))
        kinds = {"pointer_case": ("pointer", "success"),
                 "pointer_fail_case": ("pointer", "null"),
                 "reference_case": ("reference", "success"),
                 "reference_fail_case": ("reference", "bad_cast"),
                 "null_input_case": ("pointer", "null"),
                 "void_case": ("void_pointer", "success")}
        address = {"kAddressMustDiffer": "nonzero", "kAddressLayoutDependent": "layout_dependent",
                   "kAddressMustBeEqual": "none"}
        for (kind, targs, cid, args), c in zip(rows, casts):
            with self.subTest(case=cid):
                self.assertEqual(kinds[kind], (c["form"], c["expect"]))
                if kind == "null_input_case":
                    self.assertEqual(targs, [c["target"], c["input"]["null_of"]])
                    self.assertEqual(args, [])
                    continue
                if kind == "void_case":
                    self.assertEqual(targs, [])
                else:
                    self.assertEqual(targs, [c["target"]])
                obj, path = view(args[0])
                self.assertEqual((obj, path), (c["input"]["object"], c["input"]["path"]))
                if kind.endswith("fail_case"):
                    self.assertEqual(len(args), 1)
                    self.assertEqual(c["adjustment"], "not_applicable")
                    continue
                robj, rpath = view(args[1])
                self.assertEqual((robj, rpath), (obj, c["result_path"]))
                self.assertEqual(address[args[2]], c["adjustment"])
                if kind == "reference_case":
                    self.assertTrue(args[0].startswith("*"))

    def test_reference_failures_catch_bad_cast_only(self):
        self.assertEqual(CONSUMER.count("catch (const std::bad_cast&)"), 2)
        self.assertEqual(CONSUMER.count("catch"), 2)
        self.assertNotIn("catch (...)", CONSUMER + PRODUCER)
        self.assertIn("catch (const std::bad_alloc&)", PRODUCER)

    def test_consumer_never_manages_lifetime(self):
        self.assertNotRegex(CONSUMER, r"\b(new|delete|malloc|free)\b")
        self.assertIn("destroy_fixture_objects(out);", PRODUCER)

    def test_sources_avoid_forbidden_constructs(self):
        banned = [r"__RTDynamicCast", r"__RTCastToVoid", r"\b_?_?asm\b", r"#\s*pragma",
                  r"reinterpret_cast", r"\b0x[0-9A-Fa-f]", r"\bnullptr\b", r"\boverride\b",
                  r"\bconstexpr\b", r"\bstatic_assert\b", r"__declspec", r"extern \"C\"",
                  r"\bauto\b", r"\btypeid\b", r"\bgoto\b", r"\bvolatile\b", r"\bunion\b",
                  r"\(\s*(char|void|int)\s*\*\s*\)", r"\blong long\b"]
        for name, text in (("header", HEADER), ("producer", PRODUCER), ("consumer", CONSUMER)):
            for pattern in banned:
                with self.subTest(file=name, pattern=pattern):
                    self.assertNotRegex(text, pattern)

    def test_includes_are_limited(self):
        includes = re.findall(r"^#include (.+)$", HEADER + PRODUCER + CONSUMER, re.M)
        self.assertEqual(sorted(includes),
                         sorted(['"rtti_abi_fixture.h"', '"rtti_abi_fixture.h"', "<new>",
                                 "<typeinfo>"]))

    def test_source_text_is_plain(self):
        for path in FIXTURE_DIR.iterdir():
            data = path.read_bytes()
            with self.subTest(file=path.name):
                self.assertTrue(all(b == 0x0A or 0x20 <= b <= 0x7E for b in data))
                self.assertTrue(data.endswith(b"\n"))


# ---------------------------------------------------------------- documents

class DocumentationTests(Base):
    ABI = (TOOL_DIR / "expected-ABI.md").read_text(encoding="utf-8")
    PLAN_DOC = (TOOL_DIR / "COMPILE-PLAN.md").read_text(encoding="utf-8")
    README = (TOOL_DIR / "README.md").read_text(encoding="utf-8")
    RESULTS = (TOOL_DIR / "RESULTS.md").read_text(encoding="utf-8")

    def test_expected_abi_case_table_matches_metadata(self):
        rows = {m.group(1): m.group(2) for m in re.finditer(
            r"^\| ([SMVA]\d\d) \|(.*)\|$", self.ABI, re.M)}
        words = {"success": "success", "null": "null", "bad_cast": "`bad_cast`"}
        addr = {"nonzero": "must differ", "layout_dependent": "layout-dependent",
                "not_applicable": "n/a", "none": "same"}
        self.assertEqual(sorted(rows), sorted(c["id"] for c in FIXTURE_META["casts"]))
        for c in FIXTURE_META["casts"]:
            cells = [x.strip() for x in rows[c["id"]].split("|")]
            with self.subTest(case=c["id"]):
                self.assertEqual(cells[-2], words[c["expect"]])
                self.assertEqual(cells[-1], addr[c["adjustment"]])

    def test_expected_abi_covers_required_topics(self):
        for topic in ("complete object locator", "type descriptor", "class hierarchy descriptor",
                      "base class descriptor", "base class array", "vbtable", "mdisp", "pdisp",
                      "vdisp", "std::bad_cast", "/GR", "/EHsc", "NOT_RUN", "unknown",
                      "hypothesis", "cross-cast", "translation unit", "COMDAT", "import"):
            self.assertIn(topic.lower(), self.ABI.lower(), topic)

    def test_expected_abi_states_no_fixed_layout(self):
        self.assertNotRegex(self.ABI, r"\b0x[0-9A-Fa-f]+\b")
        self.assertNotRegex(self.ABI, r"(offset|displacement|size) (of )?\+?\d")
        self.assertNotRegex(self.ABI, r"\?\?_R|\.\?AV|\?\?_7")  # no decorated names

    def test_compile_plan_doc_shows_exact_argv(self):
        for step in PLAN["variants"][0]["steps"]:
            self.assertIn(" ".join(step["argv"]), self.PLAN_DOC)
        self.assertIn("NOT_RUN", self.PLAN_DOC)

    def test_readme_lists_delivered_files_and_commands(self):
        for path in TOOL_DIR.rglob("*"):
            if path.is_file() and "__pycache__" not in path.parts:
                self.assertIn(path.name, self.README, path.name)
        self.assertIn('python -m unittest discover -s tests/rtti-abi -p "test_*.py" -v',
                      self.README)

    def test_results_record_attribution_and_not_run(self):
        self.assertIn("claude-opus-5-5", self.RESULTS)
        self.assertIn("NOT_RUN", self.RESULTS)

    def test_no_private_paths_in_delivered_text(self):
        for path in TOOL_DIR.rglob("*"):
            if path.is_file() and path.suffix in (".md", ".json", ".h", ".cpp", ".py"):
                text = path.read_text(encoding="utf-8")
                with self.subTest(file=path.name):
                    self.assertNotRegex(text, r"[A-Za-z]:\\|[A-Za-z]:/(?!/)|/Users/|/home/|"
                                              r"AppData|Downloads")


if __name__ == "__main__":
    unittest.main()
