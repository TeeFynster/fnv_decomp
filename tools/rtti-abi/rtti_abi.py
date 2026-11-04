#!/usr/bin/env python3
"""Offline validator for synthetic RTTI ABI metadata and the compile-only plan.

Commands:
  validate <metadata.json> [--format text|json]
  check-plan <compile-plan.json> [--format text|json]

Each command reads exactly the one JSON file it is given. Nothing else is
opened: no source file, object file, executable, game image or compiler. No
program is started and no network is used.

`validate` checks a `fnv-rtti-abi-metadata` v1 document: identities and
references, missing and duplicate nodes, the class graph, and every declared
dynamic_cast against the C++ language rules computed from the declared
hierarchy. It never assumes a compiler record layout. Address claims are
accepted only where C++ itself decides them, and `unknown` stays unknown.
Schema v1 cannot record an observed compiler fact, and every measurement must
be NOT_RUN.

`check-plan` checks that a `fnv-rtti-abi-compile-plan` v1 document is the
bounded, compile-only plan: placeholders instead of paths, exact reviewed
argv, no link or run step, and every result NOT_RUN. It does not run the plan.

Python standard library only (3.10 or newer).
"""

from __future__ import annotations

import argparse
import errno
import json
import os
import re
import stat
import sys
from pathlib import Path

METADATA_SCHEMA = "fnv-rtti-abi-metadata"
PLAN_SCHEMA = "fnv-rtti-abi-compile-plan"
SCHEMA_VERSION = 1

MAX_INPUT_BYTES = 256 * 1024
MAX_DEPTH = 8
MAX_CLASSES = 64
MAX_BASES = 8
MAX_OBJECTS = 64
MAX_CASTS = 256
MAX_CLAIMS = 512
MAX_MEASUREMENTS = 16
MAX_PATH = 16
MAX_SUBOBJECTS = 1024
MAX_REPORTED = 50

EXIT_OK = 0
EXIT_INVALID = 1
EXIT_USAGE = 2

NOT_RUN = "NOT_RUN"

_ID = re.compile(r"[A-Za-z][A-Za-z0-9_]{0,47}")
_SAFE_KEY = re.compile(r"[A-Za-z_][A-Za-z0-9_]{0,40}")
_HEX64 = re.compile(r"[0-9a-f]{64}")
_LOCAL_DEVICE = re.compile(
    r"(con|prn|aux|nul|com[0-9]|lpt[0-9]|conin\$|conout\$)(\..*)?", re.IGNORECASE)

FORMS = ("pointer", "reference", "void_pointer")
OUTCOMES = ("success", "null", "bad_cast")
ADJUSTMENTS = ("none", "nonzero", "layout_dependent", "unknown", "not_applicable")
ACCESS = ("public", "protected", "private")
STATUSES = ("unknown", "hypothesis")

_PRESENCE = ("present", "absent")
_ZERO = ("zero", "nonzero")
_FLAG = ("set", "clear")
# record -> property -> expectations a hypothesis may state ("()" = unknown only)
RECORDS = {
    "complete_object_locator": {"emitted": _PRESENCE, "offset_field": _ZERO,
                                "cd_offset_field": _ZERO},
    "type_descriptor": {"emitted": _PRESENCE, "name_string": ()},
    "class_hierarchy_descriptor": {"emitted": _PRESENCE, "multiple_inheritance_flag": _FLAG,
                                   "virtual_inheritance_flag": _FLAG, "base_count": ()},
    "base_class_descriptor": {"emitted": _PRESENCE, "mdisp": _ZERO, "pdisp": (),
                              "vdisp": (), "attributes": ()},
    "vftable": {"emitted": _PRESENCE, "locator_reference": _PRESENCE},
    "vbtable": {"emitted": _PRESENCE},
}
_PATH_RECORDS = {"complete_object_locator": False, "vftable": False,
                 "base_class_descriptor": True}  # True: base_path required

NOT_VERIFIED = (
    "Not verified: any compiler-emitted record, field, offset or decorated name; "
    "linking; run-time cast or exception behaviour; cross-module or game ABI "
    "compatibility; runtime readiness. Native results: NOT_RUN."
)


class InputError(Exception):
    """The JSON file was read but rejected. ``errors`` holds (pointer, code, message)."""

    def __init__(self, errors, total=None):
        super().__init__(f"{len(errors)} problem(s)")
        self.errors = list(errors)
        self.total = len(self.errors) if total is None else total


class UsageError(Exception):
    """Bad arguments or a file that cannot be used."""


# ---------------------------------------------------------------- diagnostics

class _Errors:
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


def _key_label(key):
    return repr(key) if isinstance(key, str) and _SAFE_KEY.fullmatch(key) else "<key>"


def _keys(obj, where, required, optional, errs):
    if not isinstance(obj, dict):
        errs.add(where, "E-SCHEMA", "must be a JSON object")
        return False
    ok = True
    for key in sorted(k for k in obj if k not in required and k not in optional):
        errs.add(where, "E-SCHEMA", f"unknown key {_key_label(key)}")
        ok = False
    for key in required:
        if key not in obj:
            errs.add(where, "E-SCHEMA", f"missing required key {key!r}")
            ok = False
    return ok


def _list(value, where, limit, errs, what="list", minimum=0):
    if not isinstance(value, list):
        errs.add(where, "E-SCHEMA", f"{what} must be a JSON array")
        return None
    if len(value) > limit:
        errs.add(where, "E-LIMIT", f"{what} has more than {limit} entries")
        return None
    if len(value) < minimum:
        errs.add(where, "E-SCHEMA", f"{what} needs at least {minimum} entr"
                 f"{'y' if minimum == 1 else 'ies'}")
        return None
    return value


def _ident(value, where, errs, what="id"):
    if not isinstance(value, str) or not _ID.fullmatch(value):
        errs.add(where, "E-ID", f"{what} must match [A-Za-z][A-Za-z0-9_]{{0,47}}")
        return None
    return value


def _enum(value, where, allowed, errs, what="value", code="E-SCHEMA"):
    if not isinstance(value, str) or value not in allowed:
        errs.add(where, code, f"{what} must be one of: {', '.join(allowed)}")
        return None
    return value


def _bool(value, where, errs, what="value"):
    if type(value) is not bool:
        errs.add(where, "E-SCHEMA", f"{what} must be true or false")
        return None
    return value


def _const(value, where, expected, errs, what):
    if type(value) is not type(expected) or value != expected:
        errs.add(where, "E-SCHEMA", f"{what} must be {json.dumps(expected)}")
        return False
    return True


# ---------------------------------------------------------------- JSON input

class _DuplicateKey(ValueError):
    pass


def _pairs(pairs):
    out = {}
    for key, value in pairs:
        if key in out:
            raise _DuplicateKey(key)
        out[key] = value
    return out


def _reject_constant(_name):
    raise ValueError("non-finite number")


def _max_depth(text):
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
                if deepest > MAX_DEPTH:
                    return deepest
        elif ch in "]}":
            depth -= 1
    return deepest


def parse_json_bytes(data):
    """Decode bounded, strict JSON. Raise InputError on any problem."""
    def fail(code, message):
        raise InputError([("/", code, message)])

    if len(data) > MAX_INPUT_BYTES:
        fail("E-LIMIT", f"input is larger than {MAX_INPUT_BYTES} bytes")
    if data.startswith(b"\xef\xbb\xbf"):
        fail("E-ENCODING", "input starts with a UTF-8 byte order mark")
    try:
        text = data.decode("utf-8")
    except UnicodeDecodeError:
        fail("E-ENCODING", "input is not valid UTF-8")
    if _max_depth(text) > MAX_DEPTH:
        fail("E-LIMIT", f"input nests deeper than {MAX_DEPTH} levels")
    try:
        return json.loads(text, object_pairs_hook=_pairs, parse_constant=_reject_constant)
    except _DuplicateKey as exc:
        fail("E-DUPKEY", f"duplicate JSON key {_key_label(exc.args[0])}")
    except json.JSONDecodeError as exc:
        fail("E-JSON", f"malformed JSON at line {exc.lineno} column {exc.colno}")
    except (ValueError, RecursionError):
        fail("E-JSON", "malformed JSON (unsupported number or structure)")


# ---------------------------------------------------------------- C++ model

class _TooLarge(Exception):
    pass


class _Subobjects:
    """Base-class subobjects of one complete object of a class.

    Node 0 is the complete object. A virtual base class is one node shared by
    every path that reaches it; each non-virtual base is its own node. Only the
    language-level structure is modelled: no offset, size or order.
    """

    def __init__(self, hierarchy, cls):
        self.cls = []          # node -> class id
        self.edges = []        # node -> [(child, virtual, access)]
        virtual_nodes = {}

        def new(c):
            if len(self.cls) >= MAX_SUBOBJECTS:
                raise _TooLarge()
            self.cls.append(c)
            self.edges.append([])
            return len(self.cls) - 1

        def expand(node):
            for base, is_virtual, access in hierarchy.bases[self.cls[node]]:
                if is_virtual and base in virtual_nodes:
                    self.edges[node].append((virtual_nodes[base], True, access))
                    continue
                child = new(base)
                if is_virtual:
                    virtual_nodes[base] = child
                self.edges[node].append((child, is_virtual, access))
                expand(child)

        expand(new(cls))
        self.desc = [None] * len(self.cls)
        self.pub = [None] * len(self.cls)
        for n in range(len(self.cls)):
            self._closure(n)

    def _closure(self, n):
        if self.desc[n] is None:
            desc, pub = set(), set()
            for child, _virtual, access in self.edges[n]:
                self._closure(child)
                desc.add(child)
                desc |= self.desc[child]
                if access == "public":
                    pub.add(child)
                    pub |= self.pub[child]
            self.desc[n], self.pub[n] = frozenset(desc), frozenset(pub)

    def resolve(self, path):
        """Node reached by a path of class ids from the complete object, or None."""
        if not path or path[0] != self.cls[0]:
            return None
        node = 0
        for name in path[1:]:
            nxt = [c for c, _v, _a in self.edges[node] if self.cls[c] == name]
            if len(nxt) != 1:
                return None
            node = nxt[0]
        return node

    def has_virtual_base(self):
        return any(v for edges in self.edges for _c, v, _a in edges)


class _Hierarchy:
    def __init__(self, classes):
        self.bases = {c: [(b["class"], b["virtual"], b["access"]) for b in v["bases"]]
                      for c, v in classes.items()}
        self.poly = {c: v["polymorphic"] for c, v in classes.items()}
        self._cache = {}

    def layout(self, cls):
        if cls not in self._cache:
            self._cache[cls] = _Subobjects(self, cls)
        return self._cache[cls]


def _adjustment(sub, hierarchy, source, result):
    """What C++ decides about the result address compared with the input.

    'none': same subobject, same address. 'nonzero': the two subobjects are
    distinct, neither contains the other, and both are polymorphic (so neither
    is a zero-size subobject); C++ gives them distinct addresses.
    'layout_dependent': C++ does not decide (one is nested in the other, or a
    subobject could have zero size).
    """
    if result == source:
        return "none"
    if result in sub.desc[source] or source in sub.desc[result]:
        return "layout_dependent"
    if hierarchy.poly[sub.cls[source]] and hierarchy.poly[sub.cls[result]]:
        return "nonzero"
    return "layout_dependent"


def _runtime_cast(sub, source, target):
    """C++ run-time check of dynamic_cast ([expr.dynamic.cast]); node or None."""
    # Downcast: the input is a public base subobject of exactly one T object.
    owners = [x for x in range(len(sub.cls))
              if sub.cls[x] == target and source in sub.pub[x]]
    if len(owners) == 1:
        return owners[0]
    # Cross-cast: the input is a public base subobject of the complete object,
    # which has a single, public base subobject of type T.
    if source == 0 or source in sub.pub[0]:
        bases = [x for x in range(1, len(sub.cls)) if sub.cls[x] == target]
        if len(bases) == 1 and bases[0] in sub.pub[0]:
            return bases[0]
    return None


# ---------------------------------------------------------------- metadata

def _check_classes(doc, errs):
    raw = _list(doc.get("classes"), "/classes", MAX_CLASSES, errs, "classes", 1)
    if raw is None:
        return None
    classes, folded = {}, {}
    for i, item in enumerate(raw):
        where = f"/classes/{i}"
        if not _keys(item, where, ("id", "polymorphic", "bases"), (), errs):
            continue
        cid = _ident(item["id"], where + "/id", errs, "class id")
        poly = _bool(item["polymorphic"], where + "/polymorphic", errs, "polymorphic")
        bases_raw = _list(item["bases"], where + "/bases", MAX_BASES, errs, "bases")
        bases, ok = [], cid is not None and poly is not None and bases_raw is not None
        for j, base in enumerate(bases_raw or ()):
            bw = f"{where}/bases/{j}"
            if not _keys(base, bw, ("class", "virtual", "access"), (), errs):
                ok = False
                continue
            b = _ident(base["class"], bw + "/class", errs, "base class")
            v = _bool(base["virtual"], bw + "/virtual", errs, "virtual")
            a = _enum(base["access"], bw + "/access", ACCESS, errs, "access")
            if b is None or v is None or a is None:
                ok = False
                continue
            bases.append({"class": b, "virtual": v, "access": a, "where": bw})
        if cid is None:
            continue
        if cid.lower() in folded:
            errs.add(where + "/id", "E-DUP", f"class id duplicates {folded[cid.lower()]}")
            continue
        folded[cid.lower()] = where
        if ok:
            classes[cid] = {"polymorphic": poly, "bases": bases, "where": where}
    if errs:
        return None

    for cid, item in classes.items():
        seen = set()
        for base in item["bases"]:
            if base["class"] not in classes:
                errs.add(base["where"] + "/class", "E-REF", "base class is not declared")
            elif base["class"] == cid:
                errs.add(base["where"] + "/class", "E-CYCLE", "class lists itself as a base")
            elif base["class"] in seen:
                errs.add(base["where"] + "/class", "E-BASE-DUP",
                         "the same class is listed twice as a direct base")
            seen.add(base["class"])
    if errs:
        return None

    state = {}

    def visit(c):  # cycle check over the base graph
        state[c] = 1
        for base in classes[c]["bases"]:
            b = base["class"]
            if state.get(b) == 1:
                errs.add(base["where"] + "/class", "E-CYCLE", "inheritance cycle")
            elif b not in state:
                visit(b)
        state[c] = 2

    for c in classes:
        if c not in state:
            visit(c)
    if errs:
        return None

    poly_cache = {}

    def inherits_poly(c):
        if c not in poly_cache:
            poly_cache[c] = any(classes[b["class"]]["polymorphic"] or inherits_poly(b["class"])
                                for b in classes[c]["bases"])
        return poly_cache[c]

    for cid, item in classes.items():
        if not item["polymorphic"] and inherits_poly(cid):
            errs.add(item["where"] + "/polymorphic", "E-POLY",
                     "a class with a polymorphic base is polymorphic")
    if errs:
        return None
    hierarchy = _Hierarchy(classes)
    for cid, item in classes.items():
        try:
            hierarchy.layout(cid)
        except _TooLarge:
            errs.add(item["where"], "E-LIMIT",
                     f"class has more than {MAX_SUBOBJECTS} base subobjects")
    return None if errs else (classes, hierarchy)


def _check_path(value, where, errs):
    path = _list(value, where, MAX_PATH, errs, "path", 1)
    if path is None:
        return None
    out = [_ident(p, f"{where}/{k}", errs, "path entry") for k, p in enumerate(path)]
    return None if None in out else out


def _cast_entry(item, where, classes, objects, errs):
    if not _keys(item, where, ("id", "form", "input", "expect", "adjustment"),
                 ("target", "result_path", "same_result_as"), errs):
        return None
    cid = _ident(item["id"], where + "/id", errs, "cast id")
    form = _enum(item["form"], where + "/form", FORMS, errs, "form")
    expect = _enum(item["expect"], where + "/expect", OUTCOMES, errs, "expect")
    adjust = _enum(item["adjustment"], where + "/adjustment", ADJUSTMENTS, errs, "adjustment")
    target = None
    if form == "void_pointer":
        if "target" in item:
            errs.add(where + "/target", "E-SCHEMA", "a void_pointer cast has no target class")
            return None
    elif form is not None:
        if "target" not in item:
            errs.add(where, "E-SCHEMA", "missing required key 'target'")
            return None
        target = _ident(item["target"], where + "/target", errs, "target")
        if target is not None and target not in classes:
            errs.add(where + "/target", "E-REF", "target class is not declared")
            target = None
        if target is None:
            return None

    inp, iw = item["input"], where + "/input"
    obj = path = null_of = None
    if isinstance(inp, dict) and "null_of" in inp:
        if not _keys(inp, iw, ("null_of",), (), errs):
            return None
        null_of = _ident(inp["null_of"], iw + "/null_of", errs, "null_of")
        if null_of is not None and null_of not in classes:
            errs.add(iw + "/null_of", "E-REF", "class is not declared")
            null_of = None
        if null_of is None:
            return None
    else:
        if not _keys(inp, iw, ("object", "path"), (), errs):
            return None
        obj = _ident(inp["object"], iw + "/object", errs, "object")
        path = _check_path(inp["path"], iw + "/path", errs)
        if obj is not None and obj not in objects:
            errs.add(iw + "/object", "E-REF", "object is not declared")
            obj = None
        if obj is None or path is None:
            return None

    result_path = None
    if "result_path" in item:
        result_path = _check_path(item["result_path"], where + "/result_path", errs)
        if result_path is None:
            return None
    same = None
    if "same_result_as" in item:
        same = _ident(item["same_result_as"], where + "/same_result_as", errs, "same_result_as")
        if same is None:
            return None
    if None in (cid, form, expect, adjust):
        return None
    return {"id": cid, "form": form, "target": target, "expect": expect, "adjustment": adjust,
            "object": obj, "path": path, "null_of": null_of, "result_path": result_path,
            "same_result_as": same, "where": where}


def _evaluate(cast, hierarchy, objects, errs):
    """Apply the C++ rules to one cast. Return the computed facts, or None."""
    w = cast["where"]
    source = cast["null_of"] if cast["null_of"] else (cast["path"] or [None])[-1]
    sub = node = None
    if cast["object"] is not None:
        sub = hierarchy.layout(objects[cast["object"]])
        if cast["path"][0] != objects[cast["object"]]:
            errs.add(w + "/input/path/0", "E-PATH",
                     "path must start with the object's class")
            return None
        node = sub.resolve(cast["path"])
        if node is None:
            errs.add(w + "/input/path", "E-PATH",
                     "path does not follow direct bases of the object's class")
            return None
    if cast["form"] == "reference" and cast["null_of"]:
        errs.add(w + "/input", "E-ILLFORMED", "a reference cast cannot have a null input")
        return None

    mechanism = "runtime_check"
    if cast["form"] != "void_pointer":
        standalone = hierarchy.layout(source)
        targets = [x for x in range(len(standalone.cls)) if standalone.cls[x] == cast["target"]]
        if targets:
            if len(targets) > 1:
                errs.add(w + "/target", "E-ILLFORMED",
                         "target is an ambiguous base of the source type; the cast does not compile")
                return None
            if targets[0] != 0 and targets[0] not in standalone.pub[0]:
                errs.add(w + "/target", "E-ILLFORMED",
                         "target is an inaccessible base of the source type; the cast does not compile")
                return None
            mechanism = "static_conversion"
    if mechanism == "runtime_check" and not hierarchy.poly[source]:
        errs.add(w + "/input", "E-ILLFORMED",
                 "the source type is not polymorphic, so this dynamic_cast does not compile")
        return None

    if cast["null_of"]:
        return {"outcome": "null", "adjustment": "not_applicable", "mechanism": "null_input",
                "object": None, "result": None}
    if mechanism == "static_conversion":
        found = [x for x in ({node} | sub.desc[node]) if sub.cls[x] == cast["target"]]
        result = found[0]
    elif cast["form"] == "void_pointer":
        result = 0
    else:
        result = _runtime_cast(sub, node, cast["target"])
    if result is None:
        outcome = "bad_cast" if cast["form"] == "reference" else "null"
        return {"outcome": outcome, "adjustment": "not_applicable", "mechanism": mechanism,
                "object": cast["object"], "result": None}
    return {"outcome": "success", "adjustment": _adjustment(sub, hierarchy, node, result),
            "mechanism": mechanism, "object": cast["object"], "result": result, "sub": sub}


def _check_claim(item, where, classes, hierarchy, errs):
    if not _keys(item, where, ("id", "record", "class", "property", "status"),
                 ("base_path", "expect"), errs):
        return None
    cid = _ident(item["id"], where + "/id", errs, "claim id")
    record = _enum(item["record"], where + "/record", tuple(RECORDS), errs, "record")
    cls = _ident(item["class"], where + "/class", errs, "class")
    status = item["status"]
    if status == "observed":
        errs.add(where + "/status", "E-OBSERVED",
                 "schema v1 cannot record an observed compiler fact; nothing has been measured")
        return None
    status = _enum(status, where + "/status", STATUSES, errs, "status")
    if None in (cid, record, cls, status):
        return None
    if cls not in classes:
        errs.add(where + "/class", "E-REF", "class is not declared")
        return None
    prop = _enum(item["property"], where + "/property", tuple(RECORDS[record]), errs,
                 "property for this record")
    if prop is None:
        return None

    sub = hierarchy.layout(cls)
    node = 0
    if "base_path" in item:
        if record not in _PATH_RECORDS:
            errs.add(where + "/base_path", "E-SCHEMA", "this record takes no base_path")
            return None
        path = _check_path(item["base_path"], where + "/base_path", errs)
        if path is None:
            return None
        node = sub.resolve(path)
        if node is None:
            errs.add(where + "/base_path", "E-PATH",
                     "base_path does not follow direct bases from the claim's class")
            return None
    elif _PATH_RECORDS.get(record):
        errs.add(where, "E-SCHEMA", "missing required key 'base_path'")
        return None

    expect = item.get("expect")
    if status == "unknown":
        if "expect" in item:
            errs.add(where + "/expect", "E-CLAIM",
                     "an unknown claim states no expectation; use status 'hypothesis'")
            return None
    else:
        allowed = RECORDS[record][prop]
        if not allowed:
            errs.add(where + "/status", "E-CLAIM",
                     "schema v1 allows only 'unknown' for this property")
            return None
        if "expect" not in item:
            errs.add(where, "E-CLAIM", "a hypothesis must state 'expect'")
            return None
        expect = _enum(expect, where + "/expect", allowed, errs, "expect")
        if expect is None:
            return None
        if record in ("complete_object_locator", "vftable") and not hierarchy.poly[sub.cls[node]]:
            errs.add(where, "E-CLAIM",
                     "a non-polymorphic subobject has no vftable or complete object locator")
            return None
        has_vbase = sub.has_virtual_base()
        if (record == "class_hierarchy_descriptor" and prop == "virtual_inheritance_flag"
                and (expect == "set") != has_vbase):
            errs.add(where + "/expect", "E-CLAIM",
                     "conflicts with the declared hierarchy's virtual inheritance")
            return None
        if record == "vbtable" and expect == "present" and not has_vbase:
            errs.add(where + "/expect", "E-CLAIM",
                     "a class with no virtual base has nothing for a vbtable to locate")
            return None
        if record == "base_class_descriptor" and prop == "mdisp" and node == 0 \
                and expect == "nonzero":
            errs.add(where + "/expect", "E-CLAIM",
                     "the displacement of a class from itself is zero")
            return None
    return {"id": cid, "key": (record, cls, node, prop), "status": status, "where": where}


def validate_metadata(doc):
    """Validate a parsed metadata document. Return a summary dict or raise InputError."""
    errs = _Errors()
    if not _keys(doc, "/", ("schema", "schema_version", "fixture", "classes", "objects",
                            "casts"), ("layout_claims", "measurements"), errs):
        errs.raise_if_any()
    _const(doc["schema"], "/schema", METADATA_SCHEMA, errs, "schema")
    _const(doc["schema_version"], "/schema_version", SCHEMA_VERSION, errs, "schema_version")
    fixture = _ident(doc["fixture"], "/fixture", errs, "fixture")
    errs.raise_if_any()

    model = _check_classes(doc, errs)
    errs.raise_if_any()
    classes, hierarchy = model

    measurements = {}
    for i, m in enumerate(_list(doc.get("measurements", []), "/measurements",
                                MAX_MEASUREMENTS, errs, "measurements") or ()):
        where = f"/measurements/{i}"
        if not _keys(m, where, ("id", "kind", "variant", "result"), (), errs):
            continue
        mid = _ident(m["id"], where + "/id", errs, "measurement id")
        _enum(m["kind"], where + "/kind", ("compile_only",), errs, "kind")
        _ident(m["variant"], where + "/variant", errs, "variant")
        if m["result"] != NOT_RUN:
            errs.add(where + "/result", "E-NOT-RUN",
                     "every native result in schema v1 must be NOT_RUN")
        if mid is not None:
            if mid in measurements:
                errs.add(where + "/id", "E-DUP", "measurement id duplicates another")
            measurements[mid] = where

    objects = {}
    for i, o in enumerate(_list(doc["objects"], "/objects", MAX_OBJECTS, errs, "objects") or ()):
        where = f"/objects/{i}"
        if not _keys(o, where, ("id", "class"), (), errs):
            continue
        oid = _ident(o["id"], where + "/id", errs, "object id")
        cls = _ident(o["class"], where + "/class", errs, "object class")
        if oid is None or cls is None:
            continue
        if cls not in classes:
            errs.add(where + "/class", "E-REF", "object class is not declared")
        elif oid in objects:
            errs.add(where + "/id", "E-DUP", "object id duplicates another")
        else:
            objects[oid] = cls

    casts, seen = [], {}
    for i, item in enumerate(_list(doc["casts"], "/casts", MAX_CASTS, errs, "casts") or ()):
        cast = _cast_entry(item, f"/casts/{i}", classes, objects, errs)
        if cast is None:
            continue
        if cast["id"] in seen:
            errs.add(cast["where"] + "/id", "E-DUP", "cast id duplicates another")
            continue
        seen[cast["id"]] = cast
        casts.append(cast)
    errs.raise_if_any()

    for cast in casts:
        w = cast["where"]
        facts = _evaluate(cast, hierarchy, objects, errs)
        cast["facts"] = facts
        if facts is None:
            continue
        if cast["expect"] != facts["outcome"]:
            errs.add(w + "/expect", "E-OUTCOME",
                     f"conflicts with the C++ rules for this hierarchy (computed: {facts['outcome']})")
        claimed, computed = cast["adjustment"], facts["adjustment"]
        if claimed != "unknown" and claimed != computed:
            if claimed in ("none", "nonzero") and computed == "layout_dependent":
                message = ("C++ does not decide this address; the claim would promote a "
                           "layout assumption to a fact (use layout_dependent or unknown)")
            else:
                message = f"conflicts with the C++ rules (computed: {computed})"
            errs.add(w + "/adjustment", "E-ADJUST", message)
        if cast["result_path"] is not None:
            sub = facts.get("sub")
            if facts["result"] is None:
                errs.add(w + "/result_path", "E-RESULT", "the cast has no result subobject")
            elif sub.resolve(cast["result_path"]) is None:
                errs.add(w + "/result_path", "E-PATH",
                         "result_path does not follow direct bases of the object's class")
            elif sub.resolve(cast["result_path"]) != facts["result"]:
                errs.add(w + "/result_path", "E-RESULT",
                         "names a different subobject from the one C++ selects")

    for cast in casts:
        other_id = cast["same_result_as"]
        if other_id is None or cast["facts"] is None:
            continue
        w = cast["where"] + "/same_result_as"
        other = seen.get(other_id)
        if other is None or other is cast:
            errs.add(w, "E-REF", "must name another declared cast")
            continue
        a, b = cast["facts"], other["facts"]
        if b is None:
            continue
        if not (a["result"] is not None and b["result"] is not None
                and a["object"] == b["object"] and a["result"] == b["result"]):
            errs.add(w, "E-RESULT", "the two casts do not select the same subobject "
                     "of the same object")

    claims, claim_keys = [], {}
    for i, item in enumerate(_list(doc.get("layout_claims", []), "/layout_claims",
                                   MAX_CLAIMS, errs, "layout_claims") or ()):
        claim = _check_claim(item, f"/layout_claims/{i}", classes, hierarchy, errs)
        if claim is None:
            continue
        if claim["id"] in {c["id"] for c in claims}:
            errs.add(claim["where"] + "/id", "E-DUP", "claim id duplicates another")
            continue
        if claim["key"] in claim_keys:
            errs.add(claim["where"], "E-DUP",
                     "another claim already covers this record, class, subobject and property")
            continue
        claim_keys[claim["key"]] = claim
        claims.append(claim)
    errs.raise_if_any()
    return _summary(fixture, classes, objects, casts, claims, measurements)


def _summary(fixture, classes, objects, casts, claims, measurements):
    outcome = {k: 0 for k in OUTCOMES}
    adjust = {k: 0 for k in ("none", "nonzero", "layout_dependent", "not_applicable")}
    preserved = 0
    detail = []
    for c in casts:
        f = c["facts"]
        outcome[f["outcome"]] += 1
        adjust[f["adjustment"]] += 1
        if c["adjustment"] == "unknown":
            preserved += 1
        detail.append({"id": c["id"], "form": c["form"], "mechanism": f["mechanism"],
                       "outcome": f["outcome"], "adjustment_computed": f["adjustment"],
                       "adjustment_claimed": c["adjustment"]})
    return {
        "schema": METADATA_SCHEMA, "schema_version": SCHEMA_VERSION, "valid": True,
        "fixture": fixture, "classes": len(classes), "objects": len(objects),
        "casts": {"total": len(casts), **outcome},
        "adjustment": {**adjust, "claimed_unknown_preserved": preserved},
        "cast_detail": detail,
        "layout_claims": {"unknown": sum(c["status"] == "unknown" for c in claims),
                          "hypothesis": sum(c["status"] == "hypothesis" for c in claims),
                          "observed": 0},
        "measurements": {"total": len(measurements), "NOT_RUN": len(measurements)},
        "native_results": NOT_RUN,
        "checked": "references, duplicates, class graph, C++ dynamic_cast semantics and "
                   "C++ address guarantees",
        "not_verified": NOT_VERIFIED,
    }


def metadata_lines(s):
    c, a, lc = s["casts"], s["adjustment"], s["layout_claims"]
    return [
        f"OK: metadata is valid ({METADATA_SCHEMA} v{SCHEMA_VERSION}): {s['classes']} classes, "
        f"{s['objects']} objects, {c['total']} casts, {lc['unknown'] + lc['hypothesis']} "
        f"layout claims, {s['measurements']['total']} measurement(s).",
        f"Outcomes required by the C++ rules: success {c['success']}, null {c['null']}, "
        f"bad_cast {c['bad_cast']}.",
        f"Result address versus input, as C++ decides it: same {a['none']}, "
        f"must differ {a['nonzero']}. Not decided by C++ (layout-dependent): "
        f"{a['layout_dependent']}. No result: {a['not_applicable']}. "
        f"Claimed unknown and kept unknown: {a['claimed_unknown_preserved']}.",
        f"Layout claims: unknown {lc['unknown']}, hypothesis {lc['hypothesis']}, observed 0 "
        "(schema v1 cannot record observations).",
        "Measurements and native results: all NOT_RUN.",
        f"Checked: {s['checked']}.",
        s["not_verified"],
    ]


# ---------------------------------------------------------------- compile plan

PLAN_COMPILER = "<CALLER_SUPPLIED_CL_EXE>"
PLAN_INCLUDE = "/I<CALLER_SUPPLIED_VC_INCLUDE>"
PLAN_OUT_ROOT = "<PRIVATE_OUT_DIR>"
PLAN_CWD = "<CHECKOUT_ROOT>"
PLAN_ENV_SET = {"PATH": "<CALLER_SUPPLIED_TOOL_PATH>", "TMP": "<PRIVATE_TEMP_DIR>",
                "TEMP": "<PRIVATE_TEMP_DIR>", "SystemRoot": "<CALLER_SUPPLIED_SYSTEMROOT>"}
PLAN_ENV_UNSET = ("CL", "_CL_", "INCLUDE", "LIB", "LIBPATH")
PLAN_VARIANT = "od_mt"
PLAN_FLAGS = ("/nologo", "/c", "/TP", "/X", PLAN_INCLUDE, "/GR", "/EHsc", "/W4", "/Od", "/MT")
PLAN_SOURCES = {
    "tools/rtti-abi/fixture/rtti_producer.cpp": ("compile", "producer"),
    "tools/rtti-abi/fixture/rtti_consumer.cpp": ("compile", "consumer"),
    "tools/rtti-abi/fixture/rtti_abi_fixture.h": ("header", None),
}
PLAN_SELECTION = ("caller_supplied_path", "private_doctor_report")
PLAN_FORBIDDEN = ("discover_compiler", "install_toolchain", "link", "run_fixture",
                  "extract_rtti_from_binary", "select_game_alias", "change_runtime_provider")
PLAN_IDENTITY = ("compiler_sha256", "compiler_version_banner", "front_end_sha256",
                 "back_end_sha256", "pdb_support_dll_sha256", "include_dir_listing_sha256",
                 "source_sha256_at_run", "object_sha256", "stdout_sha256", "stderr_sha256",
                 "exit_code")
# Arguments that would link, run, change RTTI or EH, change the CRT, emit debug,
# listing or browse output, or read extra input. cl options are case-sensitive.
# The first group matches by prefix (these options take attached arguments);
# the second needs a word end, because /E is a prefix of the required /EHsc.
_FORBIDDEN_FLAG = re.compile(
    r"@|[/-](link|clr|analyze|Fe|Fa|FA|Fd|Fp|FR|Fr|FI|FU|AI|D|U|Yc|Yu|Zi|ZI|Z7"
    r"|GR-|EHa|EHs-|EHc-|LD|MD|MTd)|[/-](E|EP|P)(?![A-Za-z])")


def _canonical_argv(step_name, source):
    return [PLAN_COMPILER, *PLAN_FLAGS,
            f"/Fo{PLAN_OUT_ROOT}/{PLAN_VARIANT}/rtti_{step_name}.obj", source]


def validate_plan(doc):
    """Validate a parsed compile plan. Return a summary dict or raise InputError."""
    errs = _Errors()
    top = ("schema", "schema_version", "status", "authorization", "compiler", "identity",
           "sources", "environment", "cwd", "output_root", "variants", "forbidden_operations")
    if not _keys(doc, "/", top, (), errs):
        errs.raise_if_any()
    _const(doc["schema"], "/schema", PLAN_SCHEMA, errs, "schema")
    _const(doc["schema_version"], "/schema_version", SCHEMA_VERSION, errs, "schema_version")
    if doc["status"] != NOT_RUN:
        errs.add("/status", "E-NOT-RUN", "the plan status must be NOT_RUN")
    _const(doc["authorization"], "/authorization", "coordinator_review_required", errs,
           "authorization")
    _const(doc["cwd"], "/cwd", PLAN_CWD, errs, "cwd")
    _const(doc["output_root"], "/output_root", PLAN_OUT_ROOT, errs, "output_root")

    comp = doc["compiler"]
    if _keys(comp, "/compiler", ("selection", "placeholder", "automatic_discovery",
                                 "expected_product", "trusted_before_review"), (), errs):
        if comp["selection"] != list(PLAN_SELECTION):
            errs.add("/compiler/selection", "E-PLAN",
                     "selection must be exactly: " + ", ".join(PLAN_SELECTION))
        _const(comp["placeholder"], "/compiler/placeholder", PLAN_COMPILER, errs, "placeholder")
        _const(comp["automatic_discovery"], "/compiler/automatic_discovery", False, errs,
               "automatic_discovery")
        _const(comp["trusted_before_review"], "/compiler/trusted_before_review", False, errs,
               "trusted_before_review")
        _const(comp["expected_product"], "/compiler/expected_product", "msvc_2008_sp1_x86",
               errs, "expected_product")

    ident = _list(doc["identity"], "/identity", len(PLAN_IDENTITY), errs, "identity")
    if ident is not None:
        names = []
        for i, item in enumerate(ident):
            where = f"/identity/{i}"
            if _keys(item, where, ("item", "value"), (), errs):
                names.append(_enum(item["item"], where + "/item", PLAN_IDENTITY, errs, "item"))
                if item["value"] != NOT_RUN:
                    errs.add(where + "/value", "E-NOT-RUN", "identity values must be NOT_RUN")
        if sorted(n for n in names if n) != sorted(PLAN_IDENTITY):
            errs.add("/identity", "E-PLAN", "identity must list each required item once")

    srcs = _list(doc["sources"], "/sources", len(PLAN_SOURCES), errs, "sources")
    if srcs is not None:
        seen = []
        for i, item in enumerate(srcs):
            where = f"/sources/{i}"
            if not _keys(item, where, ("path", "role", "sha256_lf"), (), errs):
                continue
            path = item["path"]
            if path not in PLAN_SOURCES:
                errs.add(where + "/path", "E-PLAN", "source is not one of the fixture files")
                continue
            if item["role"] != PLAN_SOURCES[path][0]:
                errs.add(where + "/role", "E-PLAN", "wrong role for this source")
            if not isinstance(item["sha256_lf"], str) or not _HEX64.fullmatch(item["sha256_lf"]):
                errs.add(where + "/sha256_lf", "E-PLAN", "must be 64 lowercase hex digits")
            seen.append(path)
        if sorted(seen) != sorted(PLAN_SOURCES):
            errs.add("/sources", "E-PLAN", "sources must list each fixture file once")

    env = doc["environment"]
    if _keys(env, "/environment", ("inherit", "set", "unset"), (), errs):
        _const(env["inherit"], "/environment/inherit", False, errs, "inherit")
        if env["set"] != PLAN_ENV_SET:
            errs.add("/environment/set", "E-PLAN",
                     "set must be exactly PATH, TMP, TEMP and SystemRoot as placeholders")
        if env["unset"] != list(PLAN_ENV_UNSET):
            errs.add("/environment/unset", "E-PLAN",
                     "unset must be exactly: " + ", ".join(PLAN_ENV_UNSET))

    if doc["forbidden_operations"] != list(PLAN_FORBIDDEN):
        errs.add("/forbidden_operations", "E-PLAN",
                 "must be exactly: " + ", ".join(PLAN_FORBIDDEN))

    steps_total, outputs = 0, set()
    variants = _list(doc["variants"], "/variants", 1, errs, "variants", 1)
    for vi, var in enumerate(variants or ()):
        vw = f"/variants/{vi}"
        if not _keys(var, vw, ("id", "steps"), (), errs):
            continue
        _const(var["id"], vw + "/id", PLAN_VARIANT, errs, "variant id")
        steps = _list(var["steps"], vw + "/steps", 2, errs, "steps", 2)
        names = []
        for si, step in enumerate(steps or ()):
            sw = f"{vw}/steps/{si}"
            if not _keys(step, sw, ("id", "source", "argv", "outputs", "result"), (), errs):
                continue
            steps_total += 1
            if step["result"] != NOT_RUN:
                errs.add(sw + "/result", "E-NOT-RUN", "every step result must be NOT_RUN")
            src = step["source"]
            info = PLAN_SOURCES.get(src) if isinstance(src, str) else None
            if info is None or info[0] != "compile" or info[1] != step["id"]:
                errs.add(sw + "/source", "E-PLAN", "step id and source must be producer or "
                         "consumer and match each other")
                continue
            names.append(step["id"])
            argv = step["argv"]
            if not isinstance(argv, list) or not all(isinstance(a, str) for a in argv) \
                    or len(argv) > 32:
                errs.add(sw + "/argv", "E-SCHEMA", "argv must be an array of at most 32 strings")
                continue
            bad = False
            for ai, arg in enumerate(argv):
                if ai and _FORBIDDEN_FLAG.match(arg):
                    errs.add(f"{sw}/argv/{ai}", "E-PLAN-FORBIDDEN",
                             "argument would link, run, change RTTI or EH, emit debug or "
                             "listing output, or read extra input")
                    bad = True
            if argv and argv[0] != PLAN_COMPILER:
                errs.add(sw + "/argv/0", "E-PLAN", "the compiler must be the caller-supplied "
                         "placeholder, never a discovered or literal path")
                bad = True
            expected = _canonical_argv(step["id"], src)
            if not bad and argv != expected:
                errs.add(sw + "/argv", "E-PLAN-ARGV",
                         "argv differs from the reviewed compile-only command")
            want_out = [expected[-2][3:]]
            if step["outputs"] != want_out:
                errs.add(sw + "/outputs", "E-PLAN",
                         "outputs must be exactly the step's /Fo object under the private root")
            elif want_out[0] in outputs:
                errs.add(sw + "/outputs", "E-PLAN", "output path is shared with another step")
            outputs.update(want_out if step["outputs"] == want_out else ())
        if steps is not None and sorted(names) != ["consumer", "producer"]:
            errs.add(vw + "/steps", "E-PLAN", "steps must be one producer and one consumer")
    errs.raise_if_any()
    return {"schema": PLAN_SCHEMA, "schema_version": SCHEMA_VERSION, "valid": True,
            "status": NOT_RUN, "variants": 1, "compile_steps": steps_total,
            "link_steps": 0, "run_steps": 0, "results": NOT_RUN,
            "executed_by_this_tool": False,
            "note": "Plan only. Running it needs the coordinator's separate review and "
                    "authorization of the exact command, compiler and environment."}


def plan_lines(s):
    return [
        f"OK: compile plan is valid ({PLAN_SCHEMA} v{SCHEMA_VERSION}): {s['compile_steps']} "
        "compile-only steps in 1 variant; no link or run step.",
        "Status and every result: NOT_RUN. This tool did not run anything.",
        s["note"],
    ]


# ---------------------------------------------------------------- files and CLI

def _is_link(st):
    return stat.S_ISLNK(st.st_mode) or bool(getattr(st, "st_file_attributes", 0) & 0x400)


def _errname(exc):
    return errno.errorcode.get(exc.errno or 0, type(exc).__name__)


def read_input(path):
    """Read the one explicitly named JSON file (bounded). Return bytes."""
    if not path or "\x00" in path:
        raise UsageError("input path is empty or contains NUL")
    if path.startswith(("\\\\", "//")):
        raise UsageError("input path is a UNC or device path; use a local path")
    if any(_LOCAL_DEVICE.fullmatch(part.rstrip(" .")) for part in re.split(r"[\\/]", path)):
        raise UsageError("input path is a reserved device name")
    try:
        for ancestor in reversed(Path(os.path.abspath(path)).parents):
            if _is_link(os.lstat(ancestor)):
                raise UsageError("input ancestor is a link or reparse point")
        st = os.lstat(path)
    except FileNotFoundError:
        raise UsageError("input not found") from None
    except OSError as exc:
        raise UsageError(f"input cannot be read ({_errname(exc)})") from None
    if _is_link(st):
        raise UsageError("input is a link; pass the file itself")
    if not stat.S_ISREG(st.st_mode):
        raise UsageError("input is not a regular file")
    if st.st_size > MAX_INPUT_BYTES:
        raise InputError([("/", "E-LIMIT", f"input is larger than {MAX_INPUT_BYTES} bytes")])
    try:
        with open(path, "rb") as fh:
            return fh.read(MAX_INPUT_BYTES + 1)
    except OSError as exc:
        raise UsageError(f"input cannot be read ({_errname(exc)})") from None


class _Parser(argparse.ArgumentParser):
    def error(self, message):  # never echo argument values (they may be paths)
        raise UsageError("invalid arguments; run with --help")


def _parser():
    p = _Parser(prog="rtti_abi.py",
                description="Validate synthetic RTTI ABI metadata or the compile-only plan.")
    sub = p.add_subparsers(dest="command", required=True, parser_class=_Parser)
    for name, text in (("validate", "validate a metadata document"),
                       ("check-plan", "validate the compile-only plan (never runs it)")):
        c = sub.add_parser(name, help=text)
        c.add_argument("input")
        c.add_argument("--format", choices=("text", "json"), default="text")
    return p


def main(argv=None, stdout=None, stderr=None):
    stdout = stdout or sys.stdout
    stderr = stderr or sys.stderr
    try:
        args = _parser().parse_args(argv)
        doc = parse_json_bytes(read_input(args.input))
        if args.command == "validate":
            summary, lines = validate_metadata(doc), metadata_lines
        else:
            summary, lines = validate_plan(doc), plan_lines
        if args.format == "json":
            stdout.write(json.dumps(summary, indent=2, sort_keys=True) + "\n")
        else:
            stdout.write("\n".join(lines(summary)) + "\n")
        return EXIT_OK
    except InputError as exc:
        shown = len(exc.errors)
        stderr.write(f"INVALID: input rejected ({exc.total} problem(s), {shown} shown).\n")
        for where, code, message in exc.errors:
            stderr.write(f"  {where}: {code}: {message}\n")
        return EXIT_INVALID
    except UsageError as exc:
        stderr.write(f"ERROR: {exc}\n")
        return EXIT_USAGE


if __name__ == "__main__":
    sys.exit(main())
