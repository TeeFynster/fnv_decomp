#!/usr/bin/env python3
"""Read-only validator for the unexecuted FNV runtime smoke-test record.

This tool only reads JSON and prints text. It never launches anything, never
writes files and never touches the network. Python 3.10+, stdlib only.

Usage:
    python smoke_template.py validate <record.json> [--template]
    python smoke_template.py print-template

Exit codes: 0 valid, 1 problems found, 2 usage / IO / JSON error.
"""

import argparse
import errno
import json
import os
import re
import sys
from pathlib import Path
import readiness_check as path_guard

SCHEMA_NAME = "fnv-runtime-smoke-test-record"
SCHEMA_VERSION = 1
MAX_FILE_BYTES = 1024 * 1024  # 1 MiB
TEMPLATE_PATH = Path(__file__).resolve().with_name("smoke-test-template.json")

ALLOWED_RESULTS = ("pass", "fail", "blocked", "not-run")
ALLOWED_PHASES = ("preflight", "startup", "menu", "gameplay",
                  "persistence", "shutdown", "postflight")

# Required step ids, in the order they must appear relative to each other.
REQUIRED_STEP_IDS = (
    "preflight-record-identity",
    "preflight-backup-and-isolate",
    "launch-to-window",
    "clean-exit-from-startup",
    "menu-responsive",
    "new-game",
    "movement",
    "render",
    "audio",
    "save-game",
    "reload-save",
    "load-game-from-menu",
    "clean-exit",
    "postflight-verify-untouched",
    "cleanup-rollback",
)

STEP_KEYS = frozenset((
    "id", "title", "phase", "depends_on", "preconditions", "procedure",
    "expected", "observed", "result", "evidence_location",
    "cleanup_rollback", "notes",
))

# Section -> {field: kind}. kinds: str, list, tri (None/bool), int_or_none.
SECTIONS = {
    "record": {"record_id": "str", "prepared_by": "dict", "date": "str",
               "approval_reference": "str"},
    "build_identity": {
        "source_commit": "str", "source_branch": "str",
        "build_recipe_or_command_reference": "str",
        "executable_placeholder": "str", "executable_sha256": "str",
        "executable_size_bytes": "int_or_none",
        "toolchain_report_reference": "str",
        "readiness_report_reference": "str"},
    "platform": {"target": "str", "os_name_version": "str", "cpu_arch": "str",
                 "gpu_and_driver": "str", "audio_device": "str",
                 "display_mode": "str"},
    "owned_inputs": {
        "installation_placeholder": "str", "installation_version": "str",
        "original_executable_left_unchanged_verified": "tri",
        "data_files_used": "list", "addons_and_localization": "str",
        "access_arrangement": "str"},
    "isolation": {
        "isolated_config_and_saves_placeholder": "str",
        "existing_user_config_and_saves_backed_up": "tri",
        "backup_location_reference": "str",
        "existing_user_config_and_saves_untouched_verified": "tri",
        "dll_provider_placeholder": "str", "dll_search_policy": "str"},
    "launch": {
        "application_directory_placeholder": "str",
        "working_directory_placeholder": "str", "arguments": "list",
        "environment_changes": "list", "expected_reads": "list",
        "expected_writes": "list"},
    "summary": {"overall_result": "str", "blocking_issues": "list",
                "follow_ups": "list"},
}

# (section, field) -> exact placeholder text that must remain in any record.
FIXED_VALUES = {
    ("build_identity", "executable_placeholder"): "<private-built-exe>",
    ("owned_inputs", "installation_placeholder"): "<owned-game-data>",
    ("isolation", "isolated_config_and_saves_placeholder"):
        "<isolated-config-and-saves>",
    ("isolation", "dll_provider_placeholder"): "<verified-dll-providers>",
    ("launch", "application_directory_placeholder"): "<application-directory>",
    ("launch", "working_directory_placeholder"): "<working-directory>",
}

_PRIVATE_PATH_RES = (
    re.compile(r"(?<![A-Za-z0-9])[A-Za-z]:[\\/]"),                 # C:\ or D:/
    re.compile(r"(?<![\\\w])\\\\[A-Za-z0-9_.$-]"),                  # UNC \\server
    re.compile(r"(?:^|[\s\"'(=:;,])/(?:home|Users|mnt|root|media)/"),  # POSIX
    re.compile(r"(?:^|[\s\"'(=:;,])/[A-Za-z]/[^\s/]"),            # MSYS/Git Bash /c/...
)


def looks_like_private_path(text):
    return any(rx.search(text) for rx in _PRIVATE_PATH_RES)


def _lint_privacy(node, where, problems):
    """Flag private-path-like strings anywhere. Never echo the value."""
    if isinstance(node, str):
        if looks_like_private_path(node):
            problems.append(f"{where}: looks like a private absolute path; "
                            "use a placeholder instead")
    elif isinstance(node, dict):
        for key, value in node.items():
            if isinstance(key, str) and looks_like_private_path(key):
                problems.append(f"{where}: a key looks like a private "
                                "absolute path")
            _lint_privacy(value, f"{where}.<key>" if where else "<key>",
                          problems)
    elif isinstance(node, list):
        for i, value in enumerate(node):
            _lint_privacy(value, f"{where}[{i}]", problems)


def _kind_ok(kind, value):
    if kind == "str":
        return isinstance(value, str)
    if kind == "list":
        return isinstance(value, list)
    if kind == "dict":
        return isinstance(value, dict)
    if kind == "tri":
        return value is None or isinstance(value, bool)
    if kind == "int_or_none":
        return value is None or (isinstance(value, int)
                                 and not isinstance(value, bool))
    return False


def _nonempty(value):
    return isinstance(value, str) and value.strip() != ""


def load_template():
    """Return the bundled template as a dict (read-only)."""
    return read_json_file(TEMPLATE_PATH)


def _check_steps(record, require_unexecuted, problems):
    steps = record.get("steps")
    if not isinstance(steps, list):
        problems.append("steps: must be a list")
        return
    results = {}
    positions = {}
    for idx, step in enumerate(steps):
        where = f"steps[{idx}]"
        if not isinstance(step, dict):
            problems.append(f"{where}: must be an object")
            continue
        sid = step.get("id")
        if not _nonempty(sid):
            problems.append(f"{where}: id must be a non-empty string")
            sid = None
        else:
            if sid in positions:
                problems.append(f"{where}: duplicate step id")
            else:
                positions[sid] = idx
        keys = set(step.keys())
        for missing in sorted(STEP_KEYS - keys):
            problems.append(f"{where}: missing field '{missing}'")
        for extra in sorted(keys - STEP_KEYS):
            problems.append(f"{where}: unexpected field")

        phase = step.get("phase")
        if phase not in ALLOWED_PHASES:
            problems.append(f"{where}: phase must be one of "
                            f"{', '.join(ALLOWED_PHASES)}")
        for field in ("title", "preconditions", "expected", "observed",
                      "evidence_location", "notes", "cleanup_rollback"):
            if field in step and not isinstance(step[field], str):
                problems.append(f"{where}: '{field}' must be a string")
        proc = step.get("procedure")
        if not (isinstance(proc, list) and proc
                and all(_nonempty(p) for p in proc)):
            problems.append(f"{where}: procedure must be a non-empty list of "
                            "non-empty strings")
        if not _nonempty(step.get("cleanup_rollback")):
            problems.append(f"{where}: cleanup_rollback must be non-empty")

        deps = step.get("depends_on")
        if not (isinstance(deps, list)
                and all(isinstance(d, str) for d in deps)):
            problems.append(f"{where}: depends_on must be a list of step ids")
            deps = []
        for dep in deps:
            if dep not in results:
                problems.append(f"{where}: dependency is not an "
                                "earlier step id")

        result = step.get("result")
        if not isinstance(result, str) or result not in ALLOWED_RESULTS:
            problems.append(f"{where}: result must be one of "
                            f"{', '.join(ALLOWED_RESULTS)}")
            result = None

        observed = step.get("observed", "")
        evidence = step.get("evidence_location", "")
        notes = step.get("notes", "")
        if require_unexecuted:
            if result != "not-run":
                problems.append(f"{where}: result must be 'not-run' in an "
                                "unexecuted template")
            if _nonempty(observed):
                problems.append(f"{where}: observed must be empty in an "
                                "unexecuted template")
            if _nonempty(evidence):
                problems.append(f"{where}: evidence_location must be empty "
                                "in an unexecuted template")
        if result in ("pass", "fail"):
            if not _nonempty(observed):
                problems.append(f"{where}: result '{result}' requires "
                                "non-empty observed")
            if not _nonempty(evidence):
                problems.append(f"{where}: result '{result}' requires "
                                "non-empty evidence_location")
        if result == "blocked" and not _nonempty(notes):
            problems.append(f"{where}: result 'blocked' requires notes "
                            "explaining the blocker")
        if result == "pass":
            for dep in deps:
                if results.get(dep) != "pass":
                    problems.append(f"{where}: cannot be 'pass' because "
                                    "a dependency is not 'pass'")
        if sid is not None and sid not in results:
            results[sid] = result

    for rid in REQUIRED_STEP_IDS:
        if rid not in positions:
            problems.append(f"steps: required step '{rid}' is missing")
    present = [rid for rid in REQUIRED_STEP_IDS if rid in positions]
    for a, b in zip(present, present[1:]):
        if positions[a] > positions[b]:
            problems.append(f"steps: required step '{a}' must come before "
                            f"'{b}'")

    summary = record.get("summary")
    if isinstance(summary, dict):
        overall = summary.get("overall_result")
        if not isinstance(overall, str) or overall not in ALLOWED_RESULTS:
            problems.append("summary.overall_result must be one of "
                            f"{', '.join(ALLOWED_RESULTS)}")
        else:
            if require_unexecuted and overall != "not-run":
                problems.append("summary.overall_result must be 'not-run' in "
                                "an unexecuted template")
            if overall == "pass":
                bad = [s for s, r in results.items() if r != "pass"]
                if bad or not results:
                    problems.append("summary.overall_result cannot be 'pass' "
                                    "unless every step is 'pass'")


def validate_record(record, *, require_unexecuted=False):
    """Return a list of problem strings; an empty list means valid."""
    problems = []
    if not isinstance(record, dict):
        return ["record: top level must be a JSON object"]

    if record.get("schema") != SCHEMA_NAME:
        problems.append(f"schema: must be exactly '{SCHEMA_NAME}'")
    version = record.get("schema_version")
    if isinstance(version, bool) or version != SCHEMA_VERSION \
            or not isinstance(version, int):
        problems.append(f"schema_version: must be exactly {SCHEMA_VERSION}")

    if not _nonempty(record.get("status_notice")):
        problems.append("status_notice: must be a non-empty string")
    launch_authorized = record.get("launch_authorized")
    if not isinstance(launch_authorized, bool):
        problems.append("launch_authorized: must be a boolean")
    elif require_unexecuted and launch_authorized:
        problems.append("launch_authorized: must be false in an unexecuted "
                        "template")

    for section, fields in SECTIONS.items():
        body = record.get(section)
        if not isinstance(body, dict):
            problems.append(f"{section}: missing or not an object")
            continue
        for field, kind in fields.items():
            if field not in body:
                problems.append(f"{section}.{field}: missing")
            elif not _kind_ok(kind, body[field]):
                problems.append(f"{section}.{field}: wrong type "
                                f"(expected {kind})")
    for (section, field), expected in FIXED_VALUES.items():
        body = record.get(section)
        if isinstance(body, dict) and field in body \
                and body[field] != expected:
            problems.append(f"{section}.{field}: must remain the placeholder "
                            f"'{expected}'")
    rec = record.get("record")
    pb = rec.get("prepared_by") if isinstance(rec, dict) else None
    if isinstance(pb, dict):
        for field in ("name", "model_or_tool_attribution"):
            if not isinstance(pb.get(field), str):
                problems.append(f"record.prepared_by.{field}: must be a "
                                "string")

    _check_steps(record, require_unexecuted, problems)
    _lint_privacy(record, "", problems)
    return problems


def _err_name(exc):
    code = getattr(exc, "errno", None)
    return errno.errorcode.get(code, type(exc).__name__) if code else type(exc).__name__


def read_json_file(path):
    """Read a JSON file, refusing anything over 1 MiB. Raises OSError/ValueError."""
    try:
        p = path_guard.safe_input_path(path, 'record')
        value, _ = path_guard._read_json(p, 'record')
        return value
    except path_guard.InputError as exc:
        message = str(exc)
        if 'larger than' in message: message = 'file is larger than 1 MiB'
        raise ValueError(message) from exc



def _build_parser():
    parser = argparse.ArgumentParser(
        prog="smoke_template.py",
        description="Read-only validator for the unexecuted FNV smoke-test "
                    "record. Never launches anything and never writes files.")
    sub = parser.add_subparsers(dest="command", required=True)
    val = sub.add_parser("validate", help="validate a record JSON file")
    val.add_argument("record", help="path to the record JSON file")
    val.add_argument("--template", action="store_true",
                     help="also require an unexecuted template "
                          "(all not-run, launch_authorized false)")
    sub.add_parser("print-template",
                   help="print the bundled template JSON to stdout")
    return parser


def main(argv=None):
    parser = _build_parser()
    try:
        args = parser.parse_args(argv)
    except SystemExit as exc:
        code = exc.code
        return code if isinstance(code, int) else 2

    if args.command == "print-template":
        try:
            text = json.dumps(read_json_file(TEMPLATE_PATH), indent=2) + "\n"
        except (OSError, ValueError) as exc:
            print(f"error: cannot read bundled template ({_err_name(exc)})",
                  file=sys.stderr)
            return 2
        sys.stdout.write(text)
        return 0

    try:
        record = read_json_file(args.record)
    except OSError as exc:  # the exception text would contain the path
        print(f"error: cannot read record ({_err_name(exc)})", file=sys.stderr)
        return 2
    except RecursionError:
        print("error: record JSON is nested too deeply", file=sys.stderr)
        return 2
    except ValueError as exc:  # JSONDecodeError and size refusals carry no path
        print(f"error: {exc}", file=sys.stderr)
        return 2

    problems = validate_record(record, require_unexecuted=args.template)
    if problems:
        print(f"INVALID: {len(problems)} problem(s) found")
        for problem in problems:
            print(f"- {problem}")
        return 1
    print("OK: record is valid" + (" (unexecuted template)"
                                   if args.template else ""))
    return 0


if __name__ == "__main__":
    sys.exit(main())
