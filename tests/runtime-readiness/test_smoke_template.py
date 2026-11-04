import ast
import contextlib
import copy
import io
import json
import runpy
import sys
import tempfile
import unittest
from pathlib import Path

TOOLS = Path(__file__).resolve().parents[2] / "tools" / "runtime-readiness"
sys.path.insert(0, str(TOOLS))

import smoke_template as st  # noqa: E402

MD_PATH = TOOLS / "SMOKE-TEST-TEMPLATE.md"
SCRIPT_PATH = TOOLS / "smoke_template.py"


def run_main(argv):
    out, err = io.StringIO(), io.StringIO()
    with contextlib.redirect_stdout(out), contextlib.redirect_stderr(err):
        code = st.main(argv)
    return code, out.getvalue(), err.getvalue()


def passing_record():
    rec = st.load_template()
    for step in rec["steps"]:
        step["result"] = "pass"
        step["observed"] = "synthetic observation"
        step["evidence_location"] = "evidence-ref-1"
    rec["summary"]["overall_result"] = "pass"
    return rec


class TemplateTests(unittest.TestCase):
    def test_bundled_template_validates_unexecuted(self):
        self.assertEqual(
            st.validate_record(st.load_template(), require_unexecuted=True), [])

    def test_template_identity_and_flags(self):
        t = st.load_template()
        self.assertEqual(t["schema"], "fnv-runtime-smoke-test-record")
        self.assertEqual(t["schema_version"], 1)
        self.assertIs(t["launch_authorized"], False)

    def test_every_step_not_run_and_blank(self):
        t = st.load_template()
        for step in t["steps"]:
            self.assertEqual(step["result"], "not-run", step["id"])
            self.assertEqual(step["observed"], "")
            self.assertEqual(step["evidence_location"], "")
            self.assertTrue(step["cleanup_rollback"].strip())
        self.assertEqual(t["summary"]["overall_result"], "not-run")

    def test_required_ids_present_and_ordered(self):
        ids = [s["id"] for s in st.load_template()["steps"]]
        for rid in st.REQUIRED_STEP_IDS:
            self.assertIn(rid, ids)
        self.assertEqual(len(ids), len(set(ids)))
        self.assertLess(ids.index("clean-exit-from-startup"),
                        ids.index("menu-responsive"))
        self.assertLess(ids.index("menu-responsive"), ids.index("new-game"))

    def test_markdown_mentions_every_step_id(self):
        md = MD_PATH.read_text(encoding="utf-8")
        for step in st.load_template()["steps"]:
            self.assertIn("`%s`" % step["id"], md)
        self.assertIn("NO LAUNCH AUTHORIZED", md)

    def test_missing_required_step_rejected(self):
        t = st.load_template()
        t["steps"] = [s for s in t["steps"] if s["id"] != "audio"]
        for s in t["steps"]:
            s["depends_on"] = [d for d in s["depends_on"] if d != "audio"]
        self.assertTrue(any("audio" in p for p in st.validate_record(t)))

    def test_forward_dependency_rejected(self):
        t = st.load_template()
        t["steps"][0]["depends_on"] = ["new-game"]
        self.assertTrue(st.validate_record(t))

    def test_duplicate_id_rejected(self):
        t = st.load_template()
        t["steps"][1]["id"] = t["steps"][0]["id"]
        self.assertTrue(any("duplicate" in p for p in st.validate_record(t)))

    def test_empty_cleanup_rejected(self):
        t = st.load_template()
        t["steps"][3]["cleanup_rollback"] = "  "
        self.assertTrue(any("cleanup_rollback" in p
                            for p in st.validate_record(t)))

    def test_bad_result_value_rejected(self):
        t = st.load_template()
        t["steps"][0]["result"] = "passed"
        self.assertTrue(any("result must be" in p
                            for p in st.validate_record(t)))
        t = st.load_template()
        t["summary"]["overall_result"] = "ok"
        self.assertTrue(any("overall_result" in p
                            for p in st.validate_record(t)))


class RecordRuleTests(unittest.TestCase):
    def test_fully_passing_record_is_valid(self):
        self.assertEqual(st.validate_record(passing_record()), [])

    def test_bad_schema_rejected(self):
        for key, value in (("schema", "other"), ("schema_version", 2),
                           ("schema_version", True)):
            t = st.load_template()
            t[key] = value
            self.assertTrue(st.validate_record(t), (key, value))

    def test_non_object_rejected(self):
        self.assertTrue(st.validate_record([]))

    def test_pass_without_evidence_rejected(self):
        rec = passing_record()
        rec["steps"][0]["evidence_location"] = ""
        self.assertTrue(any("evidence_location" in p
                            for p in st.validate_record(rec)))
        rec = passing_record()
        rec["steps"][0]["observed"] = ""
        self.assertTrue(any("observed" in p for p in st.validate_record(rec)))

    def test_fail_requires_observed_and_evidence(self):
        rec = st.load_template()
        rec["steps"][0]["result"] = "fail"
        self.assertEqual(len([p for p in st.validate_record(rec)
                              if "requires" in p]), 2)

    def test_blocked_requires_notes(self):
        rec = st.load_template()
        rec["steps"][0]["result"] = "blocked"
        self.assertTrue(any("notes" in p for p in st.validate_record(rec)))
        rec["steps"][0]["notes"] = "waiting for approval"
        self.assertEqual(st.validate_record(rec), [])

    def test_pass_depending_on_non_pass_rejected(self):
        rec = passing_record()
        rec["steps"][2]["result"] = "fail"  # launch-to-window
        problems = st.validate_record(rec)
        self.assertTrue(any("dependency" in p for p in problems))

    def test_overall_pass_with_not_run_rejected(self):
        rec = st.load_template()
        rec["summary"]["overall_result"] = "pass"
        self.assertTrue(any("overall_result" in p
                            for p in st.validate_record(rec)))
        rec = passing_record()
        rec["steps"][-1]["result"] = "not-run"
        self.assertTrue(any("overall_result" in p
                            for p in st.validate_record(rec)))

    def test_require_unexecuted_rejects_executed_or_authorized(self):
        rec = passing_record()
        self.assertTrue(st.validate_record(rec, require_unexecuted=True))
        t = st.load_template()
        t["launch_authorized"] = True
        self.assertTrue(st.validate_record(t, require_unexecuted=True))
        self.assertEqual(st.validate_record(t), [])
        t = st.load_template()
        t["steps"][0]["observed"] = "something"
        self.assertTrue(st.validate_record(t, require_unexecuted=True))
        t = st.load_template()
        t["steps"][0]["evidence_location"] = "x"
        self.assertTrue(st.validate_record(t, require_unexecuted=True))

    def test_step_extra_or_missing_field_rejected(self):
        t = st.load_template()
        t["steps"][0]["extra"] = 1
        del t["steps"][1]["notes"]
        problems = st.validate_record(t)
        self.assertTrue(any("unexpected field" in p for p in problems))
        self.assertTrue(any("missing field" in p for p in problems))

    def test_placeholder_replacement_rejected(self):
        t = st.load_template()
        t["build_identity"]["executable_placeholder"] = "game.exe"
        self.assertTrue(st.validate_record(t))


class PrivacyTests(unittest.TestCase):
    BAD = ["C:\\Users\\someone\\game.exe", "D:/games/x", "\\\\server\\share\\f",
           "/home/user/x", "/Users/someone/x", "/mnt/c/x",
           "see /mnt/data/file"]
    GOOD = ["<private-built-exe>", "<owned-game-data>", "http-free text",
            "a/b/c relative", "ratio 3:4", "e.g. step 1: do it"]

    def test_private_paths_flagged_anywhere(self):
        for bad in self.BAD:
            for where in ("top", "nested", "list", "step"):
                t = st.load_template()
                if where == "top":
                    t["status_notice"] = bad
                elif where == "nested":
                    t["build_identity"]["source_branch"] = bad
                elif where == "list":
                    t["launch"]["arguments"] = [bad]
                else:
                    t["steps"][0]["notes"] = bad
                problems = st.validate_record(t)
                self.assertTrue(any("private absolute path" in p
                                    for p in problems), (bad, where))
                self.assertFalse(any(bad in p for p in problems))

    def test_placeholders_and_plain_text_not_flagged(self):
        for good in self.GOOD:
            t = st.load_template()
            t["steps"][0]["notes"] = good
            self.assertEqual(st.validate_record(t), [], good)


class FileAndCliTests(unittest.TestCase):
    def setUp(self):
        self._td = tempfile.TemporaryDirectory()
        self.addCleanup(self._td.cleanup)
        self.dir = Path(self._td.name)

    def write(self, name, obj):
        p = self.dir / name
        p.write_text(json.dumps(obj), encoding="utf-8")
        return str(p)

    def test_oversized_file_refused(self):
        p = self.dir / "big.json"
        p.write_bytes(b" " * (st.MAX_FILE_BYTES + 1))
        with self.assertRaises(ValueError):
            st.read_json_file(p)
        code, _, err = run_main(["validate", str(p)])
        self.assertEqual(code, 2)
        self.assertIn("1 MiB", err)

    def test_cli_valid_template_exit_0(self):
        p = self.write("t.json", st.load_template())
        code, out, _ = run_main(["validate", p, "--template"])
        self.assertEqual(code, 0)
        self.assertIn("OK", out)

    def test_cli_executed_record_valid_without_template_flag(self):
        p = self.write("r.json", passing_record())
        self.assertEqual(run_main(["validate", p])[0], 0)
        self.assertEqual(run_main(["validate", p, "--template"])[0], 1)

    def test_cli_problems_exit_1(self):
        rec = st.load_template()
        rec["schema"] = "nope"
        code, out, _ = run_main(["validate", self.write("b.json", rec)])
        self.assertEqual(code, 1)
        self.assertIn("INVALID", out)

    def test_cli_io_and_json_errors_exit_2(self):
        self.assertEqual(run_main(["validate", str(self.dir / "none.json")])[0], 2)
        bad = self.dir / "bad.json"
        bad.write_text("{not json", encoding="utf-8")
        self.assertEqual(run_main(["validate", str(bad)])[0], 2)

    def test_cli_usage_errors_exit_2(self):
        self.assertEqual(run_main([])[0], 2)
        self.assertEqual(run_main(["bogus"])[0], 2)
        self.assertEqual(run_main(["validate"])[0], 2)

    def test_cli_print_template_matches_bundle_and_writes_nothing(self):
        before = sorted(p.name for p in self.dir.iterdir())
        code, out, _ = run_main(["print-template"])
        self.assertEqual(code, 0)
        self.assertEqual(json.loads(out), st.load_template())
        self.assertEqual(before, sorted(p.name for p in self.dir.iterdir()))

    def test_runpy_main_entry_point(self):
        p = self.write("t.json", st.load_template())
        old = sys.argv
        sys.argv = [str(SCRIPT_PATH), "validate", p, "--template"]
        try:
            with contextlib.redirect_stdout(io.StringIO()):
                with self.assertRaises(SystemExit) as cm:
                    runpy.run_path(str(SCRIPT_PATH), run_name="__main__")
        finally:
            sys.argv = old
        self.assertEqual(cm.exception.code, 0)


class SourceSafetyTests(unittest.TestCase):
    BANNED = {"subprocess", "socket", "urllib", "http", "ftplib",
              "requests", "ctypes", "shutil"}

    def test_no_banned_imports(self):
        tree = ast.parse(SCRIPT_PATH.read_text(encoding="utf-8"))
        found = set()
        for node in ast.walk(tree):
            if isinstance(node, ast.Import):
                found.update(a.name.split(".")[0] for a in node.names)
            elif isinstance(node, ast.ImportFrom) and node.module:
                found.add(node.module.split(".")[0])
        self.assertEqual(found & self.BANNED, set())

    def test_source_has_no_write_or_exec_calls(self):
        src = SCRIPT_PATH.read_text(encoding="utf-8")
        for needle in ("os.system", "os.popen", "write_text", "write_bytes",
                       "'w'", '"w"', "'wb'", '"wb"', "__import__"):
            self.assertNotIn(needle, src)


if __name__ == "__main__":
    unittest.main()
