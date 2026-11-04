#!/usr/bin/env python3
"""Validate a resource declaration manifest and render Windows resource (.rc) source.

Standard library only. The tool reads the one JSON manifest it is given and, for
``render --out``, writes the one .rc file it is told to write. It never opens,
stats or lists a file named inside the manifest (icon, XML manifest or any
other), never reads or writes .res or PE files, never runs a compiler, linker or
other program, and never uses the network.

Every value that reaches the output passes a strict allowlist first; nothing is
"sanitized". A declaration that cannot be represented safely is rejected.

See README.md in this directory for the schema, the path grammar and the limits.
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
import tempfile
from pathlib import Path

SCHEMA_NAME = "fnv-resource-source-manifest"
SCHEMA_VERSION = 1

# Bounds (documented in README.md).
MAX_MANIFEST_BYTES = 256 * 1024
MAX_DEPTH = 8
MAX_RESOURCES = 256
MAX_PATH_CHARS = 200
MAX_SEGMENTS = 8
MAX_SEGMENT_CHARS = 64
MAX_STRING_CHARS = 256
MAX_REPORTED_ERRORS = 50

ID_MIN, ID_MAX = 1, 65535
MANIFEST_ID_MAX = 16          # Windows reserves manifest IDs 1-16.
LANG_PRIMARY_MAX = 0x3FF      # 10-bit primary language.
LANG_SUB_MAX = 0x3F           # 6-bit sublanguage.
VERSION_PART_MAX = 65535
DWORD_MAX = 0xFFFFFFFF
CODEPAGES = (1200, 1252)

# Type token -> (rendered RC type, required file extensions or None).
TYPES = {
    "ICON": ("ICON", (".ico",)),
    "MANIFEST": ("24", (".manifest", ".xml")),
    "VERSIONINFO": ("VERSIONINFO", None),
}
TYPE_ORDER = {"ICON": 0, "MANIFEST": 1, "VERSIONINFO": 2}

VERSION_STRING_FIELDS = (
    "Comments", "CompanyName", "FileDescription", "FileVersion", "InternalName",
    "LegalCopyright", "LegalTrademarks", "OriginalFilename", "PrivateBuild",
    "ProductName", "ProductVersion", "SpecialBuild",
)
FIXED_FIELDS = (  # manifest key -> RC statement, in render order
    ("file_flags_mask", "FILEFLAGSMASK"),
    ("file_flags", "FILEFLAGS"),
    ("file_os", "FILEOS"),
    ("file_type", "FILETYPE"),
    ("file_subtype", "FILESUBTYPE"),
)

_TYPE_TOKEN = re.compile(r"[A-Za-z]{1,16}")
_SEGMENT = re.compile(r"[A-Za-z0-9_][A-Za-z0-9_.-]*")
_DEVICE = re.compile(r"(con|prn|aux|nul|com[0-9]|lpt[0-9])", re.IGNORECASE)
_STRING_VALUE = re.compile(r"[A-Za-z0-9 .,_():;/&'-]+")
_SAFE_KEY = re.compile(r"[A-Za-z_][A-Za-z0-9_]{0,40}")
_LOCAL_DEVICE = re.compile(
    r"(con|prn|aux|nul|com[0-9]|lpt[0-9]|conin\$|conout\$)(\..*)?", re.IGNORECASE)

EXIT_OK = 0
EXIT_INVALID = 1
EXIT_USAGE = 2


class ManifestError(Exception):
    """The manifest was read but rejected. ``errors`` holds (pointer, message)."""

    def __init__(self, errors):
        super().__init__(f"{len(errors)} problem(s)")
        self.errors = list(errors)


class UsageError(Exception):
    """A file could not be used (unreadable, unsafe path, refused output)."""


# ---------------------------------------------------------------- validation

class _Errors:
    def __init__(self):
        self.items = []
        self.total = 0

    def add(self, where, message):
        self.total += 1
        if len(self.items) < MAX_REPORTED_ERRORS:
            self.items.append((where or "/", message))


def _key_label(key):
    return repr(key) if isinstance(key, str) and _SAFE_KEY.fullmatch(key) else "<key>"


def _is_int(value):
    return type(value) is int  # bool and float are rejected


def _check_keys(obj, where, required, optional, errs):
    ok = True
    for key in sorted(k for k in obj if k not in required and k not in optional):
        errs.add(where, f"unknown key {_key_label(key)}")
        ok = False
    for key in required:
        if key not in obj:
            errs.add(where, f"missing required key {key!r}")
            ok = False
    return ok


def _int_in(value, where, low, high, errs, what="value"):
    if not _is_int(value):
        errs.add(where, f"{what} must be a JSON integer")
        return None
    if not low <= value <= high:
        errs.add(where, f"{what} is out of range ({low}..{high})")
        return None
    return value


def _language(value, where, errs):
    if not isinstance(value, dict):
        errs.add(where, "language must be an object with 'primary' and 'sub'")
        return None
    if not _check_keys(value, where, ("primary", "sub"), (), errs):
        return None
    primary = _int_in(value["primary"], where + "/primary", 0, LANG_PRIMARY_MAX, errs,
                      "primary language")
    sub = _int_in(value["sub"], where + "/sub", 0, LANG_SUB_MAX, errs, "sublanguage")
    if primary is None or sub is None:
        return None
    return (primary, sub)


def _rel_path(value, where, extensions, errs):
    """Validate a caller-supplied relative file placeholder (never opened)."""
    def bad(message):
        errs.add(where, message)
        return None

    if not isinstance(value, str):
        return bad("file must be a string")
    if value == "":
        return bad("file must not be empty")
    if len(value) > MAX_PATH_CHARS:
        return bad(f"file is longer than {MAX_PATH_CHARS} characters")
    if any(ord(c) < 0x20 or ord(c) == 0x7F for c in value):
        return bad("file contains a control character or line break")
    if '"' in value:
        return bad("file contains a quote")
    if any(ord(c) > 0x7E for c in value):
        return bad("file contains a non-ASCII character")
    if "\\" in value:
        return bad("file uses a backslash; the only separator is '/'")
    if value.startswith("//"):
        return bad("file is a UNC or device path; only relative paths are allowed")
    if value.startswith("/"):
        return bad("file is an absolute path; only relative paths are allowed")
    if re.match(r"[A-Za-z]:", value):
        return bad("file starts with a drive letter; only relative paths are allowed")
    if ":" in value:
        return bad("file contains ':'")
    segments = value.split("/")
    if len(segments) > MAX_SEGMENTS:
        return bad(f"file has more than {MAX_SEGMENTS} segments")
    for seg in segments:
        if seg == "":
            return bad("file has an empty segment (leading, trailing or doubled '/')")
        if seg in (".", ".."):
            return bad("file contains a '.' or '..' segment; traversal is not allowed")
        if ".." in seg:
            return bad("file segment contains '..'")
        if len(seg) > MAX_SEGMENT_CHARS:
            return bad(f"file segment is longer than {MAX_SEGMENT_CHARS} characters")
        if not _SEGMENT.fullmatch(seg):
            return bad("file contains a character outside the allowlist "
                       "(letters, digits, '_', '-', '.'; segments start with a letter, "
                       "digit or '_')")
        if seg.endswith("."):
            return bad("file segment ends with '.'")
        if _DEVICE.fullmatch(seg.split(".", 1)[0]):
            return bad("file segment is a reserved Windows device name")
    if extensions and not segments[-1].lower().endswith(extensions):
        return bad("file must end with " + " or ".join(extensions))
    return value


def _version_quad(value, where, errs):
    if (not isinstance(value, list) or len(value) != 4):
        errs.add(where, "version must be a list of exactly 4 integers")
        return None
    parts = [_int_in(v, f"{where}/{i}", 0, VERSION_PART_MAX, errs, "version part")
             for i, v in enumerate(value)]
    return None if None in parts else tuple(parts)


def _string_value(value, where, errs):
    if not isinstance(value, str):
        errs.add(where, "string value must be a string")
        return None
    if value == "" or len(value) > MAX_STRING_CHARS:
        errs.add(where, f"string value must be 1..{MAX_STRING_CHARS} characters")
        return None
    if not _STRING_VALUE.fullmatch(value):
        errs.add(where, "string value contains a character outside the allowlist "
                        "(letters, digits, space and . , _ ( ) : ; / & ' -)")
        return None
    if "//" in value:
        errs.add(where, "string value contains '//'")
        return None
    if value != value.strip(" ") or "  " in value:
        errs.add(where, "string value has leading, trailing or doubled spaces")
        return None
    return value


def _string_table(value, where, errs):
    if not isinstance(value, dict):
        errs.add(where, "string_table must be an object")
        return None
    if not _check_keys(value, where, ("language", "codepage", "strings"), (), errs):
        return None
    lang = _language(value["language"], where + "/language", errs)
    codepage = value["codepage"]
    if not _is_int(codepage) or codepage not in CODEPAGES:
        errs.add(where + "/codepage", "codepage must be one of "
                 + ", ".join(str(c) for c in CODEPAGES))
        codepage = None
    strings = value["strings"]
    out = {}
    if not isinstance(strings, dict) or not strings:
        errs.add(where + "/strings", "strings must be a non-empty object")
        strings = {}
    lower = {f.lower(): f for f in VERSION_STRING_FIELDS}
    for key in sorted(strings):
        sub = f"{where}/strings"
        if key not in VERSION_STRING_FIELDS:
            hint = lower.get(key.lower()) if isinstance(key, str) else None
            errs.add(sub, f"unknown string field {_key_label(key)}"
                     + (f" (names are case-sensitive: {hint!r})" if hint else ""))
            continue
        checked = _string_value(strings[key], f"{sub}/{key}", errs)
        if checked is not None:
            out[key] = checked
    if lang is None or codepage is None or len(out) != len(strings):
        return None
    return {"language": lang, "codepage": codepage, "strings": out}


def _version_info(res, where, errs):
    fv = _version_quad(res["file_version"], where + "/file_version", errs)
    pv = _version_quad(res["product_version"], where + "/product_version", errs)
    fixed = {}
    for key, _stmt in FIXED_FIELDS:
        if key in res:
            fixed[key] = _int_in(res[key], f"{where}/{key}", 0, DWORD_MAX, errs, key)
    table = None
    if "string_table" in res:
        table = _string_table(res["string_table"], where + "/string_table", errs)
        if table is None:
            return None
    if fv is None or pv is None or None in fixed.values():
        return None
    if "file_flags" in fixed:
        if "file_flags_mask" not in fixed:
            errs.add(where + "/file_flags", "file_flags needs an explicit file_flags_mask")
            return None
        if fixed["file_flags"] & ~fixed["file_flags_mask"]:
            errs.add(where + "/file_flags", "file_flags sets bits outside file_flags_mask")
            return None
    if table:
        for key, quad in (("FileVersion", fv), ("ProductVersion", pv)):
            if key in table["strings"] and table["strings"][key] != ".".join(map(str, quad)):
                errs.add(f"{where}/string_table/strings/{key}",
                         f"{key} conflicts with the numeric version "
                         "(it must be written as a.b.c.d with the same numbers)")
                return None
    return {"file_version": fv, "product_version": pv, "fixed": fixed,
            "string_table": table}


def _resource(res, where, default_language, errs):
    if not isinstance(res, dict):
        errs.add(where, "resource must be an object")
        return None
    token = res.get("type")
    if not isinstance(token, str):
        errs.add(where + "/type", "type must be a string")
        return None
    if not _TYPE_TOKEN.fullmatch(token) or token.upper() not in TYPES:
        errs.add(where + "/type", "unsupported type (supported: ICON, MANIFEST, VERSIONINFO; "
                                  "ASCII letters, any case)")
        return None
    rtype = token.upper()
    if rtype == "VERSIONINFO":
        required = ("type", "id", "file_version", "product_version")
        optional = ("language", "string_table") + tuple(k for k, _ in FIXED_FIELDS)
    else:
        required, optional = ("type", "id", "file"), ("language",)
    if not _check_keys(res, where, required, optional, errs):
        return None

    rid = res["id"]
    if isinstance(rid, str):
        errs.add(where + "/id", "id must be a JSON integer; string resource names "
                                "are not supported")
        rid = None
    else:
        high = MANIFEST_ID_MAX if rtype == "MANIFEST" else ID_MAX
        rid = _int_in(rid, where + "/id", ID_MIN, high, errs, "id")

    lang = None
    if "language" in res:
        lang = _language(res["language"], where + "/language", errs)
        if lang is None:
            rid = None
    elif default_language is not None:
        lang = default_language

    out = {"type": rtype, "id": rid, "language": lang}
    if rtype == "VERSIONINFO":
        info = _version_info(res, where, errs)
        if info is None:
            return None
        out.update(info)
    else:
        out["file"] = _rel_path(res["file"], where + "/file", TYPES[rtype][1], errs)
        if out["file"] is None:
            return None
    return None if rid is None else out


def validate_document(doc):
    """Validate a parsed manifest. Return the normalized model or raise ManifestError."""
    errs = _Errors()
    if not isinstance(doc, dict):
        raise ManifestError([("/", "manifest must be a JSON object")])
    if not _check_keys(doc, "", ("schema_version", "resources"),
                       ("schema", "default_language"), errs):
        raise ManifestError(errs.items)
    if "schema" in doc and doc["schema"] != SCHEMA_NAME:
        errs.add("/schema", f"schema must be {SCHEMA_NAME!r}")
    version = doc["schema_version"]
    if not _is_int(version) or version != SCHEMA_VERSION:
        errs.add("/schema_version", f"unsupported schema_version (this tool reads "
                                    f"{SCHEMA_VERSION} as a JSON integer)")
    default_language = None
    if "default_language" in doc:
        default_language = _language(doc["default_language"], "/default_language", errs)
    resources = doc["resources"]
    if not isinstance(resources, list):
        errs.add("/resources", "resources must be a list")
        raise ManifestError(errs.items)
    if len(resources) > MAX_RESOURCES:
        errs.add("/resources", f"more than {MAX_RESOURCES} resources")
        raise ManifestError(errs.items)
    if errs.items:
        raise ManifestError(errs.items)

    model = []
    for i, res in enumerate(resources):
        item = _resource(res, f"/resources/{i}", default_language, errs)
        if item is not None:
            model.append((i, item))

    # Identity: (type, id, language). A missing language could become any
    # language at compile time, so it collides with every other language.
    seen = {}
    for i, item in model:
        for j, other in seen.get((item["type"], item["id"]), ()):
            a, b = item["language"], other["language"]
            if a == b:
                errs.add(f"/resources/{i}", f"duplicates /resources/{j} "
                         "(same type, id and language; type names are case-insensitive)")
            elif a is None or b is None:
                errs.add(f"/resources/{i}", f"ambiguous with /resources/{j}: same type "
                         "and id, and one of them has no language")
        seen.setdefault((item["type"], item["id"]), []).append((i, item))
    versions = [i for i, item in model if item["type"] == "VERSIONINFO"]
    for i in versions[1:]:
        errs.add(f"/resources/{i}", "only one VERSIONINFO resource is supported")
    if errs.total:
        raise ManifestError(errs.items)
    return {"schema_version": SCHEMA_VERSION,
            "resources": sorted((item for _i, item in model), key=_sort_key)}


def _sort_key(item):
    lang = item["language"]
    return (lang is not None, lang or (0, 0), TYPE_ORDER[item["type"]], item["id"])


# ---------------------------------------------------------------- parsing

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


def parse_manifest_bytes(data):
    """Parse and validate manifest bytes. Return the model or raise ManifestError."""
    if len(data) > MAX_MANIFEST_BYTES:
        raise ManifestError([("/", f"manifest is larger than {MAX_MANIFEST_BYTES} bytes")])
    if data.startswith(b"\xef\xbb\xbf"):
        raise ManifestError([("/", "manifest starts with a UTF-8 byte order mark")])
    try:
        text = data.decode("utf-8")
    except UnicodeDecodeError:
        raise ManifestError([("/", "manifest is not valid UTF-8")]) from None
    if _max_depth(text) > MAX_DEPTH:
        raise ManifestError([("/", f"manifest nests deeper than {MAX_DEPTH} levels")])
    try:
        doc = json.loads(text, object_pairs_hook=_pairs, parse_constant=_reject_constant)
    except _DuplicateKey as exc:
        raise ManifestError([("/", f"duplicate JSON key {_key_label(exc.args[0])}")]) from None
    except json.JSONDecodeError as exc:
        raise ManifestError([("/", f"malformed JSON at line {exc.lineno} column {exc.colno}")]) from None
    except (ValueError, RecursionError):
        raise ManifestError([("/", "malformed JSON (unsupported number or structure)")]) from None
    return validate_document(doc)


# ---------------------------------------------------------------- rendering

def digest(model):
    canonical = json.dumps(model, sort_keys=True, separators=(",", ":"))
    return hashlib.sha256(canonical.encode("ascii")).hexdigest()


def _render_version(item):
    fv = ",".join(str(p) for p in item["file_version"])
    pv = ",".join(str(p) for p in item["product_version"])
    lines = [f"{item['id']} VERSIONINFO", f"FILEVERSION {fv}", f"PRODUCTVERSION {pv}"]
    for key, statement in FIXED_FIELDS:
        if key in item["fixed"]:
            lines.append(f"{statement} 0x{item['fixed'][key]:08X}")
    lines.append("BEGIN")
    table = item["string_table"]
    if table:
        primary, sub = table["language"]
        langid = (sub << 10) | primary
        lines += ['    BLOCK "StringFileInfo"', "    BEGIN",
                  f'        BLOCK "{langid:04X}{table["codepage"]:04X}"', "        BEGIN"]
        for key in sorted(table["strings"]):
            lines.append(f'            VALUE "{key}", "{table["strings"][key]}"')
        lines += ["        END", "    END", '    BLOCK "VarFileInfo"', "    BEGIN",
                  f'        VALUE "Translation", 0x{langid:04X}, {table["codepage"]}',
                  "    END"]
    lines.append("END")
    return lines


def render(model):
    """Render the normalized model as .rc source bytes (ASCII, CRLF)."""
    lines = [
        f"// Generated by tools/resource-source/resource_source.py ({SCHEMA_NAME} v{SCHEMA_VERSION}).",
        "// Rendered only from explicit caller declarations. Referenced files were not",
        "// opened or checked: this source does not show that they exist, that a",
        "// resource compiler accepts it, or that a program finds these resources.",
        f"// Declaration digest: sha256:{digest(model)}",
        "",
    ]
    resources = model["resources"]
    if not resources:
        lines.append("// No resources declared.")
    current = "unset"
    for item in resources:
        lang = item["language"]
        if lang != current:
            if lang is None:
                lines += ["// No language declared: the resource compiler default applies.", ""]
            else:
                lines += [f"LANGUAGE 0x{lang[0]:03X}, 0x{lang[1]:02X}", ""]
            current = lang
        if item["type"] == "VERSIONINFO":
            lines += _render_version(item)
        else:
            lines.append(f'{item["id"]} {TYPES[item["type"]][0]} "{item["file"]}"')
        lines.append("")
    while lines and lines[-1] == "":
        lines.pop()
    text = "\r\n".join(lines) + "\r\n"
    _assert_safe_output(text)
    return text.encode("ascii")


def _assert_safe_output(text):
    # Defence in depth: everything emitted is printable ASCII, and no line is a
    # preprocessor directive.
    for line in text.split("\r\n"):
        if any(not 0x20 <= ord(c) <= 0x7E for c in line) or line.lstrip().startswith("#"):
            raise AssertionError("internal error: unsafe output line")


# ---------------------------------------------------------------- files

def _is_link(st):
    return stat.S_ISLNK(st.st_mode) or bool(getattr(st, "st_file_attributes", 0) & 0x400)


def _check_local_path(path, role):
    if not path or "\x00" in path:
        raise UsageError(f"{role} path is empty or contains NUL")
    if path.startswith(("\\\\", "//")):
        raise UsageError(f"{role} path is a UNC or device path; use a local path")
    for part in re.split(r"[\\/]", path):
        if _LOCAL_DEVICE.fullmatch(part.rstrip(" .")):
            raise UsageError(f"{role} path is a reserved device name")


def _reject_link_ancestors(path, role):
    # Best effort only; use a trusted stable local tree to avoid races.
    absolute = Path(os.path.abspath(path))
    for ancestor in reversed(absolute.parents):
        try:
            st = os.lstat(ancestor)
        except FileNotFoundError:
            break
        except OSError as exc:
            raise UsageError(f"{role} ancestor cannot be checked ({_errname(exc)})") from None
        if _is_link(st):
            raise UsageError(f"{role} ancestor is a link or reparse point")


def read_manifest(path):
    """Read the explicitly named manifest file (bounded). Return bytes."""
    _check_local_path(path, "manifest")
    _reject_link_ancestors(path, "manifest")
    try:
        st = os.lstat(path)
    except FileNotFoundError:
        raise UsageError("manifest not found") from None
    except OSError as exc:
        raise UsageError(f"manifest cannot be read ({_errname(exc)})") from None
    if _is_link(st):
        raise UsageError("manifest is a link; pass the file itself")
    if not stat.S_ISREG(st.st_mode):
        raise UsageError("manifest is not a regular file")
    if st.st_size > MAX_MANIFEST_BYTES:
        raise ManifestError([("/", f"manifest is larger than {MAX_MANIFEST_BYTES} bytes")])
    try:
        with open(path, "rb") as fh:
            return fh.read(MAX_MANIFEST_BYTES + 1)
    except OSError as exc:
        raise UsageError(f"manifest cannot be read ({_errname(exc)})") from None


def write_output(path, data, manifest_path, overwrite=False):
    _check_local_path(path, "output")
    _reject_link_ancestors(path, "output")
    if not path.lower().endswith(".rc"):
        raise UsageError("output must end with .rc")
    if os.path.normcase(os.path.abspath(path)) == os.path.normcase(os.path.abspath(manifest_path)):
        raise UsageError("output is the manifest")
    parent = os.path.dirname(path) or "."
    if not os.path.isdir(parent):
        raise UsageError("output directory does not exist (it is not created)")
    try:
        st = os.lstat(path)
    except FileNotFoundError:
        st = None
    except OSError as exc:
        raise UsageError(f"output cannot be checked ({_errname(exc)})") from None
    if st is not None:
        if _is_link(st):
            raise UsageError("output is a link")
        if not stat.S_ISREG(st.st_mode):
            raise UsageError("output exists and is not a regular file")
        try:
            if os.path.samestat(st, os.lstat(manifest_path)):
                raise UsageError("output is the manifest")
        except OSError:
            pass
        if not overwrite:
            raise UsageError("output exists; pass --overwrite to replace it")
    temporary = None
    try:
        if st is not None:
            descriptor, temporary = tempfile.mkstemp(prefix=".resource-source-", suffix=".tmp", dir=parent)
            with os.fdopen(descriptor, "wb") as fh:
                fh.write(data)
            os.replace(temporary, path)
            temporary = None
        else:
            with open(path, "xb") as fh:
                fh.write(data)
    except FileExistsError:
        raise UsageError("output exists; choose a new file") from None
    except OSError as exc:
        raise UsageError(f"output cannot be written ({_errname(exc)})") from None
    finally:
        if temporary is not None:
            try:
                os.unlink(temporary)
            except FileNotFoundError:
                pass
            except OSError as exc:
                raise UsageError(f"temporary output cleanup failed ({_errname(exc)}); a temporary file may remain") from None


def _errname(exc):
    return errno.errorcode.get(exc.errno or 0, type(exc).__name__)


# ---------------------------------------------------------------- CLI

NOT_ESTABLISHED = (
    "Not established: that referenced files exist or are suitable, that a resource "
    "compiler accepts the output, that a program finds these resources at run time, "
    "or any startup, runtime, ABI or provider obligation."
)


def summary_lines(model):
    resources = model["resources"]
    lines = [f"OK: manifest is valid ({SCHEMA_NAME} v{SCHEMA_VERSION}); "
             f"{len(resources)} resource(s) declared."]
    for item in resources:
        lang = item["language"]
        lang_text = "not declared" if lang is None else f"0x{lang[0]:03X}/0x{lang[1]:02X}"
        detail = f" file {item['file']}" if "file" in item else ""
        lines.append(f"  {item['type']} {item['id']} (language: {lang_text}){detail}")
    if any(r["type"] == "ICON" and r["id"] == 101 for r in resources):
        lines.append("Note: ICON 101 is declared. Its file was not opened or checked.")
    else:
        lines.append("Note: no ICON 101 is declared. The startup source looks up icon 101; "
                     "nothing was added.")
    lines.append(NOT_ESTABLISHED)
    return lines


def summary_json(model):
    resources = model["resources"]
    return {
        "schema": SCHEMA_NAME,
        "schema_version": SCHEMA_VERSION,
        "valid": True,
        "digest": "sha256:" + digest(model),
        "resources": [
            {"type": r["type"], "id": r["id"],
             "language": None if r["language"] is None
             else {"primary": r["language"][0], "sub": r["language"][1]},
             **({"file": r["file"]} if "file" in r else {})}
            for r in resources
        ],
        "icon_101_declared": any(r["type"] == "ICON" and r["id"] == 101 for r in resources),
        "files_checked": False,
        "compiler_run": False,
        "not_established": NOT_ESTABLISHED,
    }


class _Parser(argparse.ArgumentParser):
    def error(self, message):  # never echo argument values (they may be paths)
        raise UsageError("invalid arguments; run with --help")


def _parser():
    p = _Parser(prog="resource_source.py",
                description="Validate a resource declaration manifest and render .rc source.")
    sub = p.add_subparsers(dest="command", required=True, parser_class=_Parser)
    v = sub.add_parser("validate", help="validate a manifest and summarize it")
    v.add_argument("manifest")
    v.add_argument("--format", choices=("text", "json"), default="text")
    r = sub.add_parser("render", help="render .rc source to stdout or --out")
    r.add_argument("manifest")
    r.add_argument("--out", help="write to this .rc file instead of stdout")
    r.add_argument("--overwrite", action="store_true", help="atomically replace an existing regular output file")
    return p


def _write_stream(stream, data):
    buffer = getattr(stream, "buffer", None)
    if buffer is not None:
        stream.flush()
        buffer.write(data)
        buffer.flush()
    else:
        stream.write(data.decode("ascii"))


def main(argv=None, stdout=None, stderr=None):
    stdout = stdout or sys.stdout
    stderr = stderr or sys.stderr
    try:
        args = _parser().parse_args(argv)
        model = parse_manifest_bytes(read_manifest(args.manifest))
        if args.command == "validate":
            if args.format == "json":
                stdout.write(json.dumps(summary_json(model), indent=2, sort_keys=True) + "\n")
            else:
                stdout.write("\n".join(summary_lines(model)) + "\n")
            return EXIT_OK
        data = render(model)
        if args.out:
            write_output(args.out, data, args.manifest, args.overwrite)
            stderr.write(f"OK: wrote {len(data)} bytes of .rc source "
                         f"({len(model['resources'])} resource(s)). {NOT_ESTABLISHED}\n")
        else:
            _write_stream(stdout, data)
        return EXIT_OK
    except ManifestError as exc:
        stderr.write(f"INVALID: manifest rejected ({len(exc.errors)} problem(s) shown); "
                     "nothing rendered.\n")
        for where, message in exc.errors:
            stderr.write(f"  {where}: {message}\n")
        return EXIT_INVALID
    except UsageError as exc:
        stderr.write(f"ERROR: {exc}\n")
        return EXIT_USAGE


if __name__ == "__main__":
    sys.exit(main())
