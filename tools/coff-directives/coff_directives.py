"""Conservative parser and candidate-only witness for COFF .drectve payloads.

Pure library, Python standard library only. It never opens a file, lists a
directory, starts a process, uses the network or reads the environment. All
inputs are caller-supplied bytes and plain data. The parse and candidate
evaluation entry points reject malformed inputs with results or findings;
low-level helper functions require their documented input types.

Two layers are kept apart:

* ``parse_drectve`` is a syntax witness. It splits the payload into spans that
  cover every byte, keeps the raw bytes of every span, and classifies tokens.
  A well-formed token is NOT a proven VC++ 2008 linker behaviour: slash versus
  dash, quoting, case and abbreviations are recorded, never assumed equal.
* ``evaluate_library_candidate`` is a candidate-only witness for a closed,
  caller-declared set of library-only DEFAULTLIB forms. Its result is evidence
  for a later, separately reviewed consumer. Every approval field is False.

See README.md and INTEGRATION.md in this directory.
"""

import copy
import dataclasses
import hashlib
import json
import re
from dataclasses import dataclass, field

SCHEMA_PARSE = "fnv-coff-drectve-parse"
SCHEMA_CANDIDATE = "fnv-coff-drectve-library-candidate"
SCHEMA_VERSION = 1

# ---------------------------------------------------------------- bounds
MAX_PAYLOAD_BYTES = 16384
MAX_SPANS = 1024
MAX_TOKENS = 256
MAX_TOKEN_BYTES = 1024
MAX_BLOCKERS = 64
MAX_OBLIGATIONS = 8
LIMITS = (
    ("max_payload_bytes", MAX_PAYLOAD_BYTES),
    ("max_spans", MAX_SPANS),
    ("max_tokens", MAX_TOKENS),
    ("max_token_bytes", MAX_TOKEN_BYTES),
    ("max_blockers", MAX_BLOCKERS),
    ("max_obligations", MAX_OBLIGATIONS),
)

# ------------------------------------------------------------ constants
IMAGE_SCN_ALIGN_1BYTES = 0x00100000
IMAGE_SCN_LNK_INFO = 0x00000200
IMAGE_SCN_LNK_REMOVE = 0x00000800
RETAINED_ROOT_SECTION_FLAGS = 0x00100A00
EXISTING_DEFAULT_TOKENS = (b'/DEFAULTLIB:"LIBCMT"', b'/DEFAULTLIB:"OLDNAMES"')

LIBRARY_FAMILIES = ("libcpmt", "libcmt", "oldnames")
SUPPORTED_COMPILER_FAMILY = "msvc"
SUPPORTED_COMPILER_VERSION = "vc2008-sp1"
SUPPORTED_RUNTIME_MODEL = "static-multithreaded-release"

DIRECTIVE_RELATED_BLOCKERS = (
    "DIRECTIVE_CONTRACT_DIFFERS",
    "UNSUPPORTED_IMPLICIT_LINKER_DIRECTIVE",
    "UNKNOWN_DIRECTIVE_CONTRACT",
)

SPAN_KINDS = ("BOM_UTF8", "SEPARATOR", "TOKEN", "CONTROL")
STATUS_PARSED = "PARSED"
STATUS_REJECTED_INPUT = "REJECTED_INPUT"
STATUS_REJECTED_BOUNDS = "REJECTED_BOUNDS"
STATUS_INTERNAL = "INTERNAL_INCONSISTENCY"
STATUS_EVIDENCE = "EVIDENCE_PRESENT"
STATUS_NO_EVIDENCE = "NO_EVIDENCE"

# Operations that can create roots or change namespace or link behaviour.
# They are recognised (case-insensitively) only so that they can be reported.
_OPERATION_TABLE = {
    "DEFAULTLIB": "DEFAULTLIB",
    "INCLUDE": "INCLUDE",
    "ALTERNATENAME": "ALTERNATENAME",
    "EXPORT": "EXPORT",
    "ENTRY": "ENTRY",
    "SECTION": "SECTION",
    "MERGE": "MERGE",
    "NODEFAULTLIB": "NODEFAULTLIB",
}
HIDDEN_ROOT_OPERATIONS = (
    "INCLUDE", "ALTERNATENAME", "EXPORT", "ENTRY", "SECTION", "MERGE", "NODEFAULTLIB",
)
TOKEN_SYNTAX_FLAGS = (
    "NON_ASCII", "UNTERMINATED_QUOTE", "AMBIGUOUS_ESCAPE", "NOT_AN_OPTION",
    "BAD_OPTION_NAME", "AMBIGUOUS_QUOTING", "EMPTY_VALUE", "MISSING_VALUE",
)

# Every finding code this module can emit, with a one-line meaning.
FINDING_CODES = {
    "PAYLOAD_REJECTED_INPUT": "payload was not bytes",
    "PAYLOAD_REJECTED_BOUNDS": "payload exceeded a documented bound",
    "PAYLOAD_INTERNAL_INCONSISTENCY": "span self-check failed",
    "ENCODING_UTF8_BOM_PRESENT": "payload starts with a UTF-8 BOM; encoding not interpreted",
    "ENCODING_UTF16_BOM_LIKE": "payload starts with a UTF-16 BOM-like pair; not interpreted",
    "NON_ASCII_BYTES": "payload has bytes outside strict ASCII",
    "NUL_BYTE": "payload has a NUL byte",
    "CONTROL_BYTE": "payload has a control byte other than NUL",
    "SEPARATOR_RUN_UNCLASSIFIED": "a run of more than one space; linker treatment unproven",
    "NO_DIRECTIVE_TOKENS": "payload has no tokens",
    "MIXED_OPERATIONS": "DEFAULTLIB mixed with another operation",
    "UNKNOWN_OPERATION": "option name outside the recognised table",
    "UNKNOWN_LIBRARY": "DEFAULTLIB value is not libcpmt, libcmt or oldnames",
    "PREFIX_NOT_DECLARED": "option prefix not declared by the policy",
    "OPTION_SPELLING_NOT_DECLARED": "option spelling not declared by the policy",
    "QUOTE_STYLE_NOT_DECLARED": "quote style not declared by the policy",
    "LIBRARY_FORM_NOT_DECLARED": "library spelling differs from the policy form",
    "DUPLICATE_LIBRARY_DIRECTIVE": "the same library form appears more than once",
    "CONFLICTING_LIBRARY_FORMS": "one library appears with different spellings",
    "ORDER_NOT_DECLARED": "library order not declared by the policy",
    "CONTEXT_MISSING_OR_WRONG_TYPE": "section context missing or wrong type",
    "CONTEXT_FIELD_INVALID": "a section context field has the wrong type or form",
    "CONTEXT_NOT_OBJECT_ONLY": "container is not declared as a COFF object",
    "CONTEXT_SECTION_NAME_NOT_DRECTVE": "section name is not .drectve",
    "CONTEXT_SECTION_COUNT_NOT_ONE": "object does not have exactly one .drectve section",
    "CONTEXT_FLAGS_MISSING_LNK_INFO": "flags lack IMAGE_SCN_LNK_INFO",
    "CONTEXT_FLAGS_DIFFER_FROM_REVIEWED_SHAPE": "flags differ from 0x00100a00",
    "CONTEXT_RELOCATIONS_PRESENT": "relocation count is not zero",
    "CONTEXT_LINE_NUMBERS_PRESENT": "line-number count is not zero",
    "CONTEXT_RAW_SIZE_MISMATCH": "raw size differs from the payload length",
    "CONTEXT_EXTENT_OVERFLOW": "raw offset plus size exceeds 32 bits",
    "CONTEXT_EMPTY_EXTENT_NONZERO_OFFSET": "zero raw size with a non-zero raw offset",
    "CONTEXT_MISSING_RAW_OFFSET": "non-zero raw size with a zero raw offset",
    "CONTEXT_PAYLOAD_HASH_MISMATCH": "asserted payload hash differs from the computed hash",
    "TOOLCHAIN_MISSING_OR_WRONG_TYPE": "toolchain assertion missing or wrong type",
    "TOOLCHAIN_FIELD_INVALID": "a toolchain field has the wrong type or form",
    "TOOLCHAIN_FAMILY_UNSUPPORTED": "compiler family is not msvc",
    "TOOLCHAIN_VERSION_UNSUPPORTED": "compiler version is not vc2008-sp1",
    "TOOLCHAIN_RUNTIME_MODEL_INCOMPATIBLE": "runtime model is not static-multithreaded-release",
    "POLICY_MISSING_OR_WRONG_TYPE": "policy missing or wrong type",
    "POLICY_FIELD_INVALID": "a policy field has the wrong type or form",
    "POLICY_DUPLICATE_ENTRY": "a policy list repeats an entry",
    "POLICY_OPTION_NOT_DEFAULTLIB": "a declared option spelling is not DEFAULTLIB",
    "POLICY_FORM_UNKNOWN_LIBRARY": "a declared form is not libcpmt, libcmt or oldnames",
    "POLICY_DUPLICATE_FORM": "the same form is declared twice",
    "POLICY_CONFLICTING_FORMS": "two spellings are declared for one library",
    "POLICY_ORDER_UNKNOWN_FAMILY": "an order names an unknown library",
    "POLICY_ORDER_REPEATS_FAMILY": "an order repeats a library",
    "POLICY_ORDER_FAMILY_WITHOUT_FORM": "an order names a library with no declared form",
    "POLICY_DUPLICATE_ORDER": "the same order is declared twice",
    "POLICY_FORM_UNUSED": "a declared form appears in no order",
    "OBLIGATIONS_MISSING_OR_WRONG_TYPE": "obligations missing or not a tuple",
    "OBLIGATION_FIELD_INVALID": "an obligation field has the wrong type or form",
    "OBLIGATION_NOT_REVIEWED": "an obligation is not marked reviewed",
    "OBLIGATION_DUPLICATE_FAMILY": "two obligations for one library",
    "OBLIGATION_CONFLICT": "two different obligations for one library",
    "OBLIGATION_IDENTITY_REUSED": "one obligation identity used for two libraries",
    "MISSING_LIBRARY_OBLIGATION": "a referenced library has no obligation",
    "OBLIGATION_FOR_UNREFERENCED_LIBRARY": "an obligation names an unreferenced library",
    "ORIGINAL_MISSING_OR_WRONG_TYPE": "original negative identities missing or wrong type",
    "ORIGINAL_FIELD_INVALID": "an original-negative field has the wrong type or form",
    "ORIGINAL_NO_BLOCKERS": "the original negative lists no blockers",
    "ORIGINAL_DUPLICATE_BLOCKER_IDENTITY": "two blockers share one identity",
    "NO_DIRECTIVE_RELATED_BLOCKER": "no directive-related blocker to consider",
}
for _flag in TOKEN_SYNTAX_FLAGS:
    FINDING_CODES["TOKEN_SYNTAX_" + _flag] = "token syntax: " + _flag
for _op in HIDDEN_ROOT_OPERATIONS:
    FINDING_CODES["UNSUPPORTED_OPERATION_" + _op] = "unsupported operation: " + _op

OBSERVATION_CODES = {
    "OBS_DEFAULT_TOKENS_MATCH_BUT_DIFFERS_BLOCKER_PRESENT":
        "tokens equal the existing default but a DIRECTIVE_CONTRACT_DIFFERS blocker is listed",
}

UNVERIFIED = (
    "LIBRARY_EXISTENCE",
    "LIBRARY_COMPATIBILITY_WITH_RUNTIME",
    "LIBRARY_SELECTION_BY_LINKER",
    "VC2008_LINKER_DIRECTIVE_PARSING",
    "VC2008_QUOTING_RULES",
    "SLASH_DASH_EQUIVALENCE",
    "OPTION_NAME_CASE_AND_ABBREVIATION_RULES",
    "SECTION_CONTEXT_FACTS_ASSERTED_BY_CALLER",
    "TOOLCHAIN_AND_RUNTIME_ASSERTION",
    "POLICY_REVIEW",
    "LIBRARY_IDENTITY_OBLIGATION_REVIEW",
    "ORIGINAL_NEGATIVE_CERTIFICATE_CORRECTNESS",
    "ALL_OTHER_BLOCKERS",
    "LEGACY_CONSUMER_TOKENIZATION",
)
SEMANTICS_NOTE = (
    ("linker_semantics_proven_for_vc2008_sp1", False),
    ("slash_dash_equivalence_proven", False),
    ("quoting_rules_proven", False),
    ("case_rules_proven", False),
    ("format_reference_only", True),
)

_ID_RE = re.compile(r"[A-Za-z0-9][A-Za-z0-9._:\-]{0,63}")
_SHA_RE = re.compile(r"[0-9a-f]{64}")
_CODE_RE = re.compile(r"[A-Z][A-Z0-9_]{0,63}")
_KIND_RE = re.compile(r"[a-z0-9\-]{1,32}")
_NAME_BYTES_RE = re.compile(rb"[A-Za-z][A-Za-z0-9_]*")
_OPTION_SPELLING_RE = re.compile(r"[A-Za-z]{1,16}")
_FORM_RE = re.compile(r"[A-Za-z0-9._]{1,32}")
_FAMILY_RE = re.compile(r"[a-z]{1,16}")

_BOM_UTF8 = b"\xef\xbb\xbf"


# ------------------------------------------------------------ data types
@dataclass(frozen=True)
class Finding:
    code: str
    where: str

    def to_dict(self):
        return {"code": self.code, "where": self.where}


@dataclass(frozen=True)
class Span:
    index: int
    kind: str
    start: int
    end: int
    raw: bytes
    detail: str

    def to_dict(self):
        return {
            "index": self.index, "kind": self.kind, "start": self.start,
            "end": self.end, "length": self.end - self.start,
            "raw_hex": self.raw.hex(), "detail": self.detail,
        }


@dataclass(frozen=True)
class Token:
    index: int
    span_index: int
    start: int
    end: int
    raw: bytes
    ascii_text: object
    syntax_flags: tuple
    prefix: str
    option_name: object
    op_class: str
    value_start: object
    quote_style: str
    value_text: object
    library_spelling: object
    library_stem: object
    library_suffix: object
    library_family: object

    @property
    def syntax_well_formed(self):
        return not self.syntax_flags

    def to_dict(self):
        return {
            "index": self.index, "span_index": self.span_index,
            "start": self.start, "end": self.end, "raw_hex": self.raw.hex(),
            "ascii_text": self.ascii_text, "syntax_flags": list(self.syntax_flags),
            "syntax_well_formed": self.syntax_well_formed,
            "prefix": self.prefix, "option_name": self.option_name,
            "op_class": self.op_class, "value_start": self.value_start,
            "quote_style": self.quote_style, "value_text": self.value_text,
            "library_spelling": self.library_spelling,
            "library_stem": self.library_stem,
            "library_suffix": self.library_suffix,
            "library_family": self.library_family,
            "linker_semantics_proven": False,
        }


@dataclass(frozen=True)
class ParseResult:
    status: str
    rejection_reason: object
    length: object
    sha256: object
    encoding: str
    encoding_hints: tuple
    spans: tuple
    tokens: tuple
    unsupported: tuple
    coverage: tuple

    def to_dict(self):
        return {
            "schema": SCHEMA_PARSE, "version": SCHEMA_VERSION,
            "status": self.status, "rejection_reason": self.rejection_reason,
            "length": self.length, "sha256": self.sha256,
            "encoding": self.encoding, "encoding_hints": list(self.encoding_hints),
            "coverage": dict(self.coverage),
            "spans": [s.to_dict() for s in self.spans],
            "tokens": [t.to_dict() for t in self.tokens],
            "unsupported": [f.to_dict() for f in self.unsupported],
            "limits": dict(LIMITS), "semantics": dict(SEMANTICS_NOTE),
        }


@dataclass(frozen=True)
class SectionContext:
    container_kind: str
    section_name: str
    physical_section_id: str
    section_index: int
    drectve_section_count: int
    raw_size: int
    raw_data_offset: int
    flags: int
    relocation_count: int
    line_number_count: int
    payload_sha256: str


@dataclass(frozen=True)
class ToolchainAssertion:
    compiler_family: str
    compiler_version: str
    runtime_model: str


@dataclass(frozen=True)
class LibraryPolicy:
    policy_id: str
    policy_sha256: str
    prefixes: tuple
    option_spellings: tuple
    quote_styles: tuple
    forms: tuple
    orders: tuple


@dataclass(frozen=True)
class LibraryObligation:
    family: str
    obligation_id: str
    obligation_sha256: str
    reviewed: bool


@dataclass(frozen=True)
class BlockerRef:
    code: str
    identity_id: str
    identity_sha256: str


@dataclass(frozen=True)
class OriginalNegative:
    certificate_id: str
    certificate_sha256: str
    root_id: str
    root_sha256: str
    blockers: tuple


@dataclass(frozen=True)
class LibraryOperation:
    operation_index: int
    token_index: int
    span_index: int
    start: int
    end: int
    raw: bytes
    prefix: str
    option_spelling: str
    quote_style: str
    library_spelling: str
    library_stem: str
    library_suffix: str
    family: str

    def to_dict(self):
        return {
            "operation_index": self.operation_index, "token_index": self.token_index,
            "span_index": self.span_index, "start": self.start, "end": self.end,
            "raw_hex": self.raw.hex(), "prefix": self.prefix,
            "option_spelling": self.option_spelling, "quote_style": self.quote_style,
            "library_spelling": self.library_spelling,
            "library_stem": self.library_stem, "library_suffix": self.library_suffix,
            "family": self.family,
        }


@dataclass(frozen=True)
class CandidateResult:
    status: str
    findings: tuple
    parse: ParseResult
    inputs: object
    binding_sha256: object
    library_operations: tuple
    existing_contract_observation: object
    blocker_multiplicity: tuple
    unresolved_observations: tuple
    reviewable_conjunct: object
    # Constant approval fields. None of them can be set through the constructor.
    candidate_authorized: bool = field(default=False, init=False)
    adoption_authorized: bool = field(default=False, init=False)
    provider_authorized: bool = field(default=False, init=False)
    link_authorized: bool = field(default=False, init=False)
    abi_authorized: bool = field(default=False, init=False)
    runtime_authorized: bool = field(default=False, init=False)
    root_admitted: bool = field(default=False, init=False)
    original_certificate_invalidated: bool = field(default=False, init=False)
    blockers_discharged: tuple = field(default=(), init=False)
    policy_modified: bool = field(default=False, init=False)
    bytes_modified: bool = field(default=False, init=False)
    directives_executed: bool = field(default=False, init=False)

    def __post_init__(self):
        # Own nested witness data instead of retaining a constructor caller's
        # mutable references. Frozen dataclasses alone are shallow.
        for name in ("inputs", "existing_contract_observation", "reviewable_conjunct"):
            value = object.__getattribute__(self, name)
            object.__setattr__(self, name, copy.deepcopy(value))

    def __getattribute__(self, name):
        value = object.__getattribute__(self, name)
        if name in ("inputs", "existing_contract_observation", "reviewable_conjunct"):
            return copy.deepcopy(value)
        return value

    def to_dict(self):
        return {
            "schema": SCHEMA_CANDIDATE, "version": SCHEMA_VERSION,
            "status": self.status,
            "findings": [f.to_dict() for f in self.findings],
            "inputs": self.inputs, "binding_sha256": self.binding_sha256,
            "library_operations": [o.to_dict() for o in self.library_operations],
            "existing_contract_observation": self.existing_contract_observation,
            "blocker_multiplicity": dict(self.blocker_multiplicity),
            "unresolved_observations": [f.to_dict() for f in self.unresolved_observations],
            "reviewable_conjunct": self.reviewable_conjunct,
            "unverified": list(UNVERIFIED),
            "candidate_authorized": self.candidate_authorized,
            "adoption_authorized": self.adoption_authorized,
            "provider_authorized": self.provider_authorized,
            "link_authorized": self.link_authorized,
            "abi_authorized": self.abi_authorized,
            "runtime_authorized": self.runtime_authorized,
            "root_admitted": self.root_admitted,
            "original_certificate_invalidated": self.original_certificate_invalidated,
            "blockers_discharged": list(self.blockers_discharged),
            "policy_modified": self.policy_modified,
            "bytes_modified": self.bytes_modified,
            "directives_executed": self.directives_executed,
            "parse": self.parse.to_dict(),
        }


# --------------------------------------------------------------- helpers
def canonical_json(obj):
    """Deterministic ASCII JSON text for any result dictionary."""
    return json.dumps(obj, sort_keys=True, separators=(",", ":"),
                      ensure_ascii=True, allow_nan=False)


def _sha256_hex(data):
    return hashlib.sha256(data).hexdigest()


def _is_id(v):
    return type(v) is str and _ID_RE.fullmatch(v) is not None


def _is_sha(v):
    return type(v) is str and _SHA_RE.fullmatch(v) is not None


def _is_u32(v):
    return type(v) is int and 0 <= v <= 0xFFFFFFFF


def _is_tuple_of(v, kind, low, high):
    return type(v) is tuple and low <= len(v) <= high and all(type(x) is kind for x in v)


def _split_library(spelling):
    """Return (stem, suffix, family) without normalising the spelling."""
    if len(spelling) > 4 and spelling[-4:].lower() == ".lib":
        stem, suffix = spelling[:-4], spelling[-4:]
    else:
        stem, suffix = spelling, ""
    lowered = stem.lower()
    return stem, suffix, (lowered if lowered in LIBRARY_FAMILIES else None)


def describe_section_flags(flags):
    """Describe a section flag word. Pure; unknown bits are listed, not guessed."""
    named = (
        (0x00000020, "IMAGE_SCN_CNT_CODE"), (0x00000040, "IMAGE_SCN_CNT_INITIALIZED_DATA"),
        (0x00000080, "IMAGE_SCN_CNT_UNINITIALIZED_DATA"), (0x00000100, "IMAGE_SCN_LNK_OTHER"),
        (0x00000200, "IMAGE_SCN_LNK_INFO"), (0x00000800, "IMAGE_SCN_LNK_REMOVE"),
        (0x00001000, "IMAGE_SCN_LNK_COMDAT"), (0x02000000, "IMAGE_SCN_MEM_DISCARDABLE"),
        (0x04000000, "IMAGE_SCN_MEM_NOT_CACHED"), (0x08000000, "IMAGE_SCN_MEM_NOT_PAGED"),
        (0x10000000, "IMAGE_SCN_MEM_SHARED"), (0x20000000, "IMAGE_SCN_MEM_EXECUTE"),
        (0x40000000, "IMAGE_SCN_MEM_READ"), (0x80000000, "IMAGE_SCN_MEM_WRITE"),
    )
    known = 0x00F00000
    names = []
    for bit, name in named:
        known |= bit
        if flags & bit:
            names.append(name)
    return {
        "value": "0x%08x" % flags,
        "named_bits": names,
        "alignment_field": (flags >> 20) & 0xF,
        "unnamed_bits": "0x%08x" % (flags & ~known & 0xFFFFFFFF),
    }


# ---------------------------------------------------------------- parser
def verify_spans(payload, spans):
    """Independent coverage check: returns a tuple of issue codes (empty if exact)."""
    issues = []
    position = 0
    for i, s in enumerate(spans):
        if s.index != i:
            issues.append("SPAN_INDEX")
        if s.kind not in SPAN_KINDS:
            issues.append("SPAN_KIND")
        if s.start != position:
            issues.append("SPAN_GAP_OR_OVERLAP")
        if s.end <= s.start:
            issues.append("SPAN_EMPTY")
        if s.raw != payload[s.start:s.end]:
            issues.append("SPAN_RAW_MISMATCH")
        position = s.end
    if position != len(payload):
        issues.append("SPAN_COVERAGE_INCOMPLETE")
    return tuple(issues)


def _scan(payload):
    """Split into (kind, start, end, detail, unterminated). Returns (list, reason)."""
    n = len(payload)
    out = []
    i = 0
    if payload.startswith(_BOM_UTF8):
        out.append(("BOM_UTF8", 0, 3, "", False))
        i = 3
    tokens = 0
    while i < n:
        if len(out) >= MAX_SPANS:
            return None, "TOO_MANY_SPANS"
        b = payload[i]
        if b == 0x20:
            j = i
            while j < n and payload[j] == 0x20:
                j += 1
            out.append(("SEPARATOR", i, j, "SINGLE_SPACE" if j - i == 1 else "SPACE_RUN", False))
            i = j
        elif b < 0x20 or b == 0x7F:
            detail = "NUL" if b == 0 else ("DEL" if b == 0x7F else "C0")
            out.append(("CONTROL", i, i + 1, detail, False))
            i += 1
        else:
            j = i
            in_quote = False
            while j < n:
                c = payload[j]
                if c < 0x20 or c == 0x7F:
                    break
                if c == 0x20 and not in_quote:
                    break
                if c == 0x22:
                    in_quote = not in_quote
                j += 1
            tokens += 1
            if tokens > MAX_TOKENS:
                return None, "TOO_MANY_TOKENS"
            if j - i > MAX_TOKEN_BYTES:
                return None, "TOKEN_TOO_LONG"
            out.append(("TOKEN", i, j, "", in_quote))
            i = j
    return out, None


def _analyze_token(index, span_index, start, raw, unterminated):
    flags = []
    ascii_ok = all(b < 0x80 for b in raw)
    if not ascii_ok:
        flags.append("NON_ASCII")
    if unterminated:
        flags.append("UNTERMINATED_QUOTE")
    if b'\\"' in raw:
        flags.append("AMBIGUOUS_ESCAPE")
    prefix = ""
    option_name = None
    op_class = "NOT_AN_OPTION"
    name_b = value_b = None
    value_start = None
    first = raw[0:1]
    if first in (b"/", b"-"):
        prefix = first.decode("ascii")
        rest = raw[1:]
        colon = rest.find(b":")
        if colon < 0:
            name_b = rest
        else:
            name_b, value_b = rest[:colon], rest[colon + 1:]
            value_start = start + 1 + colon + 1
        if _NAME_BYTES_RE.fullmatch(name_b):
            option_name = name_b.decode("ascii")
            op_class = _OPERATION_TABLE.get(option_name.upper(), "UNKNOWN_OPTION")
        else:
            flags.append("BAD_OPTION_NAME")
            op_class = "MALFORMED_OPTION"
    else:
        flags.append("NOT_AN_OPTION")

    quotes = raw.count(b'"')
    if quotes == 0:
        quote_style = "NONE"
    elif unterminated:
        quote_style = "UNTERMINATED"
    elif (option_name is not None and value_b is not None and len(value_b) >= 2
          and value_b[0:1] == b'"' and value_b[-1:] == b'"' and value_b.count(b'"') == 2):
        quote_style = "VALUE_QUOTED"
    else:
        quote_style = "OTHER"
        flags.append("AMBIGUOUS_QUOTING")

    value_text = None
    if value_b is not None and ascii_ok and quote_style in ("NONE", "VALUE_QUOTED"):
        inner = value_b[1:-1] if quote_style == "VALUE_QUOTED" else value_b
        value_text = inner.decode("ascii")
        if not inner:
            flags.append("EMPTY_VALUE")
    elif value_b is None and op_class == "DEFAULTLIB":
        flags.append("MISSING_VALUE")

    spelling = stem = suffix = family = None
    if op_class == "DEFAULTLIB" and value_text:
        spelling = value_text
        stem, suffix, family = _split_library(spelling)
    return Token(
        index=index, span_index=span_index, start=start, end=start + len(raw), raw=raw,
        ascii_text=raw.decode("ascii") if ascii_ok else None,
        syntax_flags=tuple(flags), prefix=prefix, option_name=option_name,
        op_class=op_class, value_start=value_start, quote_style=quote_style,
        value_text=value_text, library_spelling=spelling, library_stem=stem,
        library_suffix=suffix, library_family=family,
    )


def _rejected(status, reason, length, digest):
    return ParseResult(
        status=status, rejection_reason=reason, length=length, sha256=digest,
        encoding="UNKNOWN", encoding_hints=(), spans=(), tokens=(), unsupported=(),
        coverage=(("bytes_total", length), ("fully_accounted", False)),
    )


def parse_drectve(payload):
    """Parse caller-supplied .drectve bytes. Never raises; never skips a byte."""
    if type(payload) is not bytes:
        return _rejected(STATUS_REJECTED_INPUT, "PAYLOAD_NOT_BYTES", None, None)
    n = len(payload)
    if n > MAX_PAYLOAD_BYTES:
        return _rejected(STATUS_REJECTED_BOUNDS, "PAYLOAD_TOO_LARGE", n, None)
    digest = _sha256_hex(payload)
    scanned, reason = _scan(payload)
    if reason is not None:
        return _rejected(STATUS_REJECTED_BOUNDS, reason, n, digest)

    spans = []
    tokens = []
    for kind, start, end, detail, unterminated in scanned:
        span_index = len(spans)
        raw = payload[start:end]
        spans.append(Span(span_index, kind, start, end, raw, detail))
        if kind == "TOKEN":
            tokens.append(_analyze_token(len(tokens), span_index, start, raw, unterminated))
    spans = tuple(spans)
    if verify_spans(payload, spans):
        return _rejected(STATUS_INTERNAL, "SPAN_SELF_CHECK_FAILED", n, digest)

    non_ascii = sum(1 for b in payload if b >= 0x80)
    if payload.startswith(_BOM_UTF8):
        encoding = "UTF8_BOM_PRESENT"
    elif non_ascii:
        encoding = "NON_ASCII_UNKNOWN_ENCODING"
    else:
        encoding = "STRICT_ASCII"
    hints = ("UTF16_BOM_LIKE_AT_START",) if payload[:2] in (b"\xff\xfe", b"\xfe\xff") else ()

    unsupported = []
    if payload.startswith(_BOM_UTF8):
        unsupported.append(Finding("ENCODING_UTF8_BOM_PRESENT", "span[0]"))
    if hints:
        unsupported.append(Finding("ENCODING_UTF16_BOM_LIKE", "payload"))
    for s in spans:
        where = "span[%d]" % s.index
        if s.kind == "CONTROL":
            unsupported.append(Finding("NUL_BYTE" if s.detail == "NUL" else "CONTROL_BYTE", where))
        elif s.kind == "SEPARATOR" and s.detail == "SPACE_RUN":
            unsupported.append(Finding("SEPARATOR_RUN_UNCLASSIFIED", where))
    for t in tokens:
        for flag in t.syntax_flags:
            unsupported.append(Finding("TOKEN_SYNTAX_" + flag, "token[%d]" % t.index))

    by_kind = {}
    for s in spans:
        by_kind[s.kind] = by_kind.get(s.kind, 0) + (s.end - s.start)
    coverage = (
        ("bytes_total", n), ("fully_accounted", True), ("span_count", len(spans)),
        ("token_count", len(tokens)),
        ("token_bytes", by_kind.get("TOKEN", 0)),
        ("separator_bytes", by_kind.get("SEPARATOR", 0)),
        ("control_bytes", by_kind.get("CONTROL", 0)),
        ("bom_bytes", by_kind.get("BOM_UTF8", 0)),
        ("nul_bytes", payload.count(b"\x00")),
        ("non_ascii_bytes", non_ascii),
    )
    return ParseResult(
        status=STATUS_PARSED, rejection_reason=None, length=n, sha256=digest,
        encoding=encoding, encoding_hints=hints, spans=spans, tokens=tuple(tokens),
        unsupported=tuple(unsupported), coverage=coverage,
    )


# ------------------------------------------------- candidate input checks
def _bad(findings, code, where):
    findings.append(Finding(code, where))


def _check_context(ctx, parse):
    """Return (findings, normalised dict or None)."""
    findings = []
    if type(ctx) is not SectionContext:
        return [Finding("CONTEXT_MISSING_OR_WRONG_TYPE", "context")], None
    structural = [
        ("container_kind", type(ctx.container_kind) is str and _KIND_RE.fullmatch(ctx.container_kind)),
        ("section_name", type(ctx.section_name) is str and 1 <= len(ctx.section_name) <= 8
         and all(0x21 <= ord(c) <= 0x7E for c in ctx.section_name)),
        ("physical_section_id", _is_id(ctx.physical_section_id)),
        ("section_index", type(ctx.section_index) is int and 1 <= ctx.section_index <= 65279),
        ("drectve_section_count", type(ctx.drectve_section_count) is int
         and 0 <= ctx.drectve_section_count <= 65279),
        ("raw_size", _is_u32(ctx.raw_size)),
        ("raw_data_offset", _is_u32(ctx.raw_data_offset)),
        ("flags", _is_u32(ctx.flags)),
        ("relocation_count", _is_u32(ctx.relocation_count)),
        ("line_number_count", _is_u32(ctx.line_number_count)),
        ("payload_sha256", _is_sha(ctx.payload_sha256)),
    ]
    for name, ok in structural:
        if not ok:
            _bad(findings, "CONTEXT_FIELD_INVALID", "context." + name)
    if findings:
        return findings, None

    if ctx.container_kind != "coff-object":
        _bad(findings, "CONTEXT_NOT_OBJECT_ONLY", "context.container_kind")
    if ctx.section_name != ".drectve":
        _bad(findings, "CONTEXT_SECTION_NAME_NOT_DRECTVE", "context.section_name")
    if ctx.drectve_section_count != 1:
        _bad(findings, "CONTEXT_SECTION_COUNT_NOT_ONE", "context.drectve_section_count")
    if not ctx.flags & IMAGE_SCN_LNK_INFO:
        _bad(findings, "CONTEXT_FLAGS_MISSING_LNK_INFO", "context.flags")
    elif ctx.flags != RETAINED_ROOT_SECTION_FLAGS:
        _bad(findings, "CONTEXT_FLAGS_DIFFER_FROM_REVIEWED_SHAPE", "context.flags")
    if ctx.relocation_count != 0:
        _bad(findings, "CONTEXT_RELOCATIONS_PRESENT", "context.relocation_count")
    if ctx.line_number_count != 0:
        _bad(findings, "CONTEXT_LINE_NUMBERS_PRESENT", "context.line_number_count")
    if parse.length is not None and ctx.raw_size != parse.length:
        _bad(findings, "CONTEXT_RAW_SIZE_MISMATCH", "context.raw_size")
    if ctx.raw_data_offset + ctx.raw_size > 0xFFFFFFFF:
        _bad(findings, "CONTEXT_EXTENT_OVERFLOW", "context.raw_data_offset")
    if ctx.raw_size == 0 and ctx.raw_data_offset != 0:
        _bad(findings, "CONTEXT_EMPTY_EXTENT_NONZERO_OFFSET", "context.raw_data_offset")
    if ctx.raw_size != 0 and ctx.raw_data_offset == 0:
        _bad(findings, "CONTEXT_MISSING_RAW_OFFSET", "context.raw_data_offset")
    if parse.sha256 is not None and ctx.payload_sha256 != parse.sha256:
        _bad(findings, "CONTEXT_PAYLOAD_HASH_MISMATCH", "context.payload_sha256")

    normal = {
        "assertion_status": "CALLER_ASSERTED_UNVERIFIED",
        "container_kind": ctx.container_kind, "section_name": ctx.section_name,
        "physical_section_id": ctx.physical_section_id,
        "section_index": ctx.section_index,
        "drectve_section_count": ctx.drectve_section_count,
        "raw_size": ctx.raw_size, "raw_data_offset": ctx.raw_data_offset,
        "raw_extent_end": ctx.raw_data_offset + ctx.raw_size,
        "flags": ctx.flags, "flags_description": describe_section_flags(ctx.flags),
        "relocation_count": ctx.relocation_count,
        "line_number_count": ctx.line_number_count,
        "payload_sha256": ctx.payload_sha256,
    }
    return findings, normal


def _check_toolchain(tc):
    findings = []
    if type(tc) is not ToolchainAssertion:
        return [Finding("TOOLCHAIN_MISSING_OR_WRONG_TYPE", "toolchain")], None
    for name in ("compiler_family", "compiler_version", "runtime_model"):
        if not _is_id(getattr(tc, name)):
            _bad(findings, "TOOLCHAIN_FIELD_INVALID", "toolchain." + name)
    if findings:
        return findings, None
    if tc.compiler_family != SUPPORTED_COMPILER_FAMILY:
        _bad(findings, "TOOLCHAIN_FAMILY_UNSUPPORTED", "toolchain.compiler_family")
    if tc.compiler_version != SUPPORTED_COMPILER_VERSION:
        _bad(findings, "TOOLCHAIN_VERSION_UNSUPPORTED", "toolchain.compiler_version")
    if tc.runtime_model != SUPPORTED_RUNTIME_MODEL:
        _bad(findings, "TOOLCHAIN_RUNTIME_MODEL_INCOMPATIBLE", "toolchain.runtime_model")
    normal = {
        "assertion_status": "CALLER_ASSERTED_UNVERIFIED",
        "compiler_family": tc.compiler_family, "compiler_version": tc.compiler_version,
        "runtime_model": tc.runtime_model,
    }
    return findings, normal


def _check_policy(policy):
    """Return (findings, normalised dict or None, usable)."""
    findings = []
    if type(policy) is not LibraryPolicy:
        return [Finding("POLICY_MISSING_OR_WRONG_TYPE", "policy")], None, False
    if not _is_id(policy.policy_id):
        _bad(findings, "POLICY_FIELD_INVALID", "policy.policy_id")
    if not _is_sha(policy.policy_sha256):
        _bad(findings, "POLICY_FIELD_INVALID", "policy.policy_sha256")
    for name, high in (("prefixes", 2), ("option_spellings", 8), ("quote_styles", 2),
                       ("forms", len(LIBRARY_FAMILIES)), ("orders", 8)):
        value = getattr(policy, name)
        if name == "orders":
            ok = (type(value) is tuple and 1 <= len(value) <= high
                  and all(_is_tuple_of(o, str, 1, len(LIBRARY_FAMILIES)) for o in value))
        else:
            ok = _is_tuple_of(value, str, 1, high)
        if not ok:
            _bad(findings, "POLICY_FIELD_INVALID", "policy." + name)
    if findings:
        return findings, None, False

    if any(p not in ("/", "-") for p in policy.prefixes):
        _bad(findings, "POLICY_FIELD_INVALID", "policy.prefixes")
    if any(_OPTION_SPELLING_RE.fullmatch(s) is None for s in policy.option_spellings):
        _bad(findings, "POLICY_FIELD_INVALID", "policy.option_spellings")
    if any(q not in ("NONE", "VALUE_QUOTED") for q in policy.quote_styles):
        _bad(findings, "POLICY_FIELD_INVALID", "policy.quote_styles")
    if any(_FORM_RE.fullmatch(f) is None for f in policy.forms):
        _bad(findings, "POLICY_FIELD_INVALID", "policy.forms")
    if any(_FAMILY_RE.fullmatch(f) is None for o in policy.orders for f in o):
        _bad(findings, "POLICY_FIELD_INVALID", "policy.orders")
    if findings:
        return findings, None, False

    for name in ("prefixes", "option_spellings", "quote_styles"):
        value = getattr(policy, name)
        if len(set(value)) != len(value):
            _bad(findings, "POLICY_DUPLICATE_ENTRY", "policy." + name)
    if any(s.upper() != "DEFAULTLIB" for s in policy.option_spellings):
        _bad(findings, "POLICY_OPTION_NOT_DEFAULTLIB", "policy.option_spellings")

    form_for_family = {}
    for form in policy.forms:
        _, _, family = _split_library(form)
        if family is None:
            _bad(findings, "POLICY_FORM_UNKNOWN_LIBRARY", "policy.forms")
        elif family in form_for_family:
            code = ("POLICY_DUPLICATE_FORM" if form_for_family[family] == form
                    else "POLICY_CONFLICTING_FORMS")
            _bad(findings, code, "policy.forms")
        else:
            form_for_family[family] = form
    seen_orders = set()
    used = set()
    for order in policy.orders:
        if any(f not in LIBRARY_FAMILIES for f in order):
            _bad(findings, "POLICY_ORDER_UNKNOWN_FAMILY", "policy.orders")
        if len(set(order)) != len(order):
            _bad(findings, "POLICY_ORDER_REPEATS_FAMILY", "policy.orders")
        if any(f in LIBRARY_FAMILIES and f not in form_for_family for f in order):
            _bad(findings, "POLICY_ORDER_FAMILY_WITHOUT_FORM", "policy.orders")
        if order in seen_orders:
            _bad(findings, "POLICY_DUPLICATE_ORDER", "policy.orders")
        seen_orders.add(order)
        used.update(order)
    if any(family not in used for family in form_for_family):
        _bad(findings, "POLICY_FORM_UNUSED", "policy.forms")

    content = {
        "prefixes": list(policy.prefixes), "option_spellings": list(policy.option_spellings),
        "quote_styles": list(policy.quote_styles), "forms": list(policy.forms),
        "orders": [list(o) for o in policy.orders],
    }
    normal = {
        "assertion_status": "CALLER_DECLARED_UNREVIEWED_BY_THIS_MODULE",
        "policy_id": policy.policy_id, "policy_sha256": policy.policy_sha256,
        "content_sha256": _sha256_hex(canonical_json(content).encode("ascii")),
        "content": content,
    }
    return findings, normal, not findings


def _check_obligations(obligations):
    findings = []
    if type(obligations) is not tuple or len(obligations) > MAX_OBLIGATIONS:
        return [Finding("OBLIGATIONS_MISSING_OR_WRONG_TYPE", "obligations")], None
    for i, ob in enumerate(obligations):
        where = "obligations[%d]" % i
        if type(ob) is not LibraryObligation:
            _bad(findings, "OBLIGATION_FIELD_INVALID", where)
            continue
        if not (type(ob.family) is str and ob.family in LIBRARY_FAMILIES):
            _bad(findings, "OBLIGATION_FIELD_INVALID", where + ".family")
        if not _is_id(ob.obligation_id):
            _bad(findings, "OBLIGATION_FIELD_INVALID", where + ".obligation_id")
        if not _is_sha(ob.obligation_sha256):
            _bad(findings, "OBLIGATION_FIELD_INVALID", where + ".obligation_sha256")
        if type(ob.reviewed) is not bool:
            _bad(findings, "OBLIGATION_FIELD_INVALID", where + ".reviewed")
    if findings:
        return findings, None
    seen = {}
    for i, ob in enumerate(obligations):
        where = "obligations[%d]" % i
        if not ob.reviewed:
            _bad(findings, "OBLIGATION_NOT_REVIEWED", where)
        if ob.family in seen:
            same = (seen[ob.family].obligation_id == ob.obligation_id
                    and seen[ob.family].obligation_sha256 == ob.obligation_sha256)
            _bad(findings, "OBLIGATION_DUPLICATE_FAMILY" if same else "OBLIGATION_CONFLICT", where)
        else:
            seen[ob.family] = ob
    ids = [ob.obligation_id for ob in seen.values()]
    shas = [ob.obligation_sha256 for ob in seen.values()]
    if len(set(ids)) != len(ids) or len(set(shas)) != len(shas):
        _bad(findings, "OBLIGATION_IDENTITY_REUSED", "obligations")
    normal = [
        {"family": ob.family, "obligation_id": ob.obligation_id,
         "obligation_sha256": ob.obligation_sha256, "reviewed": ob.reviewed,
         "assertion_status": "CALLER_ASSERTED_UNVERIFIED"}
        for ob in obligations
    ]
    return findings, normal


def _check_original(original):
    findings = []
    if type(original) is not OriginalNegative:
        return [Finding("ORIGINAL_MISSING_OR_WRONG_TYPE", "original")], None
    for name in ("certificate_id", "root_id"):
        if not _is_id(getattr(original, name)):
            _bad(findings, "ORIGINAL_FIELD_INVALID", "original." + name)
    for name in ("certificate_sha256", "root_sha256"):
        if not _is_sha(getattr(original, name)):
            _bad(findings, "ORIGINAL_FIELD_INVALID", "original." + name)
    if not (type(original.blockers) is tuple and len(original.blockers) <= MAX_BLOCKERS):
        _bad(findings, "ORIGINAL_FIELD_INVALID", "original.blockers")
    else:
        for i, b in enumerate(original.blockers):
            where = "original.blockers[%d]" % i
            if type(b) is not BlockerRef:
                _bad(findings, "ORIGINAL_FIELD_INVALID", where)
                continue
            if not (type(b.code) is str and _CODE_RE.fullmatch(b.code)):
                _bad(findings, "ORIGINAL_FIELD_INVALID", where + ".code")
            if not _is_id(b.identity_id):
                _bad(findings, "ORIGINAL_FIELD_INVALID", where + ".identity_id")
            if not _is_sha(b.identity_sha256):
                _bad(findings, "ORIGINAL_FIELD_INVALID", where + ".identity_sha256")
    if findings:
        return findings, None
    if not original.blockers:
        _bad(findings, "ORIGINAL_NO_BLOCKERS", "original.blockers")
    identities = [b.identity_id for b in original.blockers]
    if len(set(identities)) != len(identities):
        _bad(findings, "ORIGINAL_DUPLICATE_BLOCKER_IDENTITY", "original.blockers")
    codes = [b.code for b in original.blockers]
    if not any(c in DIRECTIVE_RELATED_BLOCKERS for c in codes):
        _bad(findings, "NO_DIRECTIVE_RELATED_BLOCKER", "original.blockers")
    normal = {
        "assertion_status": "CALLER_ASSERTED_UNVERIFIED",
        "certificate_id": original.certificate_id,
        "certificate_sha256": original.certificate_sha256,
        "root_id": original.root_id, "root_sha256": original.root_sha256,
        "blockers": [
            {"code": b.code, "identity_id": b.identity_id,
             "identity_sha256": b.identity_sha256}
            for b in original.blockers
        ],
    }
    return findings, normal


# ----------------------------------------------------- candidate logic
def _check_tokens(parse, policy_normal, policy_usable):
    """Return (findings, families seen in token order for known libraries)."""
    findings = []
    families = []
    op_classes = set()
    form_for_family = {}
    if policy_usable:
        for form in policy_normal["content"]["forms"]:
            form_for_family[_split_library(form)[2]] = form
    if not parse.tokens:
        findings.append(Finding("NO_DIRECTIVE_TOKENS", "payload"))
    spellings = {}
    for t in parse.tokens:
        where = "token[%d]" % t.index
        if t.op_class in ("NOT_AN_OPTION", "MALFORMED_OPTION"):
            continue
        op_classes.add(t.op_class)
        if t.op_class == "UNKNOWN_OPTION":
            findings.append(Finding("UNKNOWN_OPERATION", where))
            continue
        if t.op_class != "DEFAULTLIB":
            findings.append(Finding("UNSUPPORTED_OPERATION_" + t.op_class, where))
            continue
        if t.library_spelling is None:
            continue  # missing or empty value is already a syntax finding
        if t.library_family is None:
            findings.append(Finding("UNKNOWN_LIBRARY", where))
            continue
        if t.syntax_flags:
            continue
        families.append(t.library_family)
        spellings.setdefault(t.library_family, []).append(t.library_spelling)
        if not policy_usable:
            continue
        content = policy_normal["content"]
        if t.prefix not in content["prefixes"]:
            findings.append(Finding("PREFIX_NOT_DECLARED", where))
        if t.option_name not in content["option_spellings"]:
            findings.append(Finding("OPTION_SPELLING_NOT_DECLARED", where))
        if t.quote_style not in content["quote_styles"]:
            findings.append(Finding("QUOTE_STYLE_NOT_DECLARED", where))
        if t.library_spelling != form_for_family.get(t.library_family):
            findings.append(Finding("LIBRARY_FORM_NOT_DECLARED", where))
    if "DEFAULTLIB" in op_classes and len(op_classes) > 1:
        findings.append(Finding("MIXED_OPERATIONS", "payload"))
    clean_order = True
    for family in LIBRARY_FAMILIES:
        seen = spellings.get(family, [])
        if len(seen) > 1:
            clean_order = False
            code = ("DUPLICATE_LIBRARY_DIRECTIVE" if len(set(seen)) == 1
                    else "CONFLICTING_LIBRARY_FORMS")
            findings.append(Finding(code, "family:" + family))
    if policy_usable and clean_order and families and not findings:
        orders = [tuple(o) for o in policy_normal["content"]["orders"]]
        if tuple(families) not in orders:
            findings.append(Finding("ORDER_NOT_DECLARED", "payload"))
    return findings, families


def evaluate_library_candidate(payload, context, toolchain, policy, obligations, original):
    """Evaluate one payload against one closed policy. Never raises, never approves."""
    parse = parse_drectve(payload)
    findings = []
    if parse.status != STATUS_PARSED:
        findings.append(Finding("PAYLOAD_" + parse.status, "payload"))
    else:
        findings.extend(parse.unsupported)
        if parse.encoding == "NON_ASCII_UNKNOWN_ENCODING":
            findings.append(Finding("NON_ASCII_BYTES", "payload"))

    ctx_f, ctx_n = _check_context(context, parse)
    tc_f, tc_n = _check_toolchain(toolchain)
    pol_f, pol_n, pol_usable = _check_policy(policy)
    ob_f, ob_n = _check_obligations(obligations)
    orig_f, orig_n = _check_original(original)

    families = []
    if parse.status == STATUS_PARSED:
        tok_f, families = _check_tokens(parse, pol_n, pol_usable)
        findings.extend(tok_f)
    findings.extend(ctx_f)
    findings.extend(tc_f)
    findings.extend(pol_f)

    # Obligations: exactly one reviewed obligation for each referenced library.
    findings.extend(ob_f)
    if ob_n is not None:
        provided = [o["family"] for o in ob_n]
        for family in LIBRARY_FAMILIES:
            if family in families and family not in provided:
                findings.append(Finding("MISSING_LIBRARY_OBLIGATION", "family:" + family))
        for family in LIBRARY_FAMILIES:
            if family in provided and family not in families:
                findings.append(Finding("OBLIGATION_FOR_UNREFERENCED_LIBRARY", "family:" + family))
    elif families:
        for family in LIBRARY_FAMILIES:
            if family in families:
                findings.append(Finding("MISSING_LIBRARY_OBLIGATION", "family:" + family))
    findings.extend(orig_f)

    status = STATUS_NO_EVIDENCE if findings else STATUS_EVIDENCE

    inputs = None
    binding = None
    if (parse.status == STATUS_PARSED and ctx_n is not None and tc_n is not None
            and pol_n is not None and ob_n is not None and orig_n is not None):
        inputs = {
            "payload": {"length": parse.length, "sha256": parse.sha256},
            "context": ctx_n, "toolchain": tc_n, "policy": pol_n,
            "obligations": ob_n, "original": orig_n,
        }
        binding = compute_binding(inputs)

    multiplicity = ()
    codes = []
    if orig_n is not None:
        codes = [b["code"] for b in orig_n["blockers"]]
        multiplicity = tuple(sorted((c, codes.count(c)) for c in set(codes)))

    observation = None
    unresolved = []
    if parse.status == STATUS_PARSED:
        raw_tokens = tuple(t.raw for t in parse.tokens)
        equal = raw_tokens == EXISTING_DEFAULT_TOKENS
        observation = {
            "existing_default_tokens": [t.decode("ascii") for t in EXISTING_DEFAULT_TOKENS],
            "raw_tokens_equal_existing_default": equal,
            "section_flags_equal_existing": (ctx_n["flags"] == RETAINED_ROOT_SECTION_FLAGS
                                             if ctx_n is not None else None),
            "relocation_count_zero": (ctx_n["relocation_count"] == 0
                                      if ctx_n is not None else None),
            "note": "compared with this module's tokenization; the legacy "
                    "consumer's tokenization was not supplied",
        }
        if equal and "DIRECTIVE_CONTRACT_DIFFERS" in codes:
            unresolved.append(Finding(
                "OBS_DEFAULT_TOKENS_MATCH_BUT_DIFFERS_BLOCKER_PRESENT", "original.blockers"))

    operations = ()
    conjunct = None
    if status == STATUS_EVIDENCE:
        ops = []
        for t in parse.tokens:
            ops.append(LibraryOperation(
                operation_index=len(ops), token_index=t.index, span_index=t.span_index,
                start=t.start, end=t.end, raw=t.raw, prefix=t.prefix,
                option_spelling=t.option_name, quote_style=t.quote_style,
                library_spelling=t.library_spelling, library_stem=t.library_stem,
                library_suffix=t.library_suffix, family=t.library_family))
        operations = tuple(ops)
        related = sorted(set(c for c in codes if c in DIRECTIVE_RELATED_BLOCKERS))
        other = sorted(set(c for c in codes if c not in DIRECTIVE_RELATED_BLOCKERS))
        conjunct = {
            "conjunct_id": "RETAINED_ROOT_DIRECTIVE_TOKEN_CONTRACT",
            "statement": "As asserted by the caller, the sole object-only .drectve "
                         "section carries exactly the ordered library-only DEFAULTLIB "
                         "forms listed here under the declared closed policy.",
            "ordered_library_forms": [o.library_spelling for o in operations],
            "ordered_families": [o.family for o in operations],
            "related_blocker_codes": related,
            "not_addressed_blocker_codes": other,
            "requires_separate_review": True,
        }

    return CandidateResult(
        status=status, findings=tuple(findings), parse=parse, inputs=inputs,
        binding_sha256=binding, library_operations=operations,
        existing_contract_observation=observation, blocker_multiplicity=multiplicity,
        unresolved_observations=tuple(unresolved), reviewable_conjunct=conjunct,
    )


def compute_binding(inputs):
    """SHA-256 over the canonical form of every bound input (domain separated)."""
    data = b"fnv-coff-drectve-binding-v1\n" + canonical_json(inputs).encode("ascii")
    return _sha256_hex(data)


# ----------------------------------------------------- policy builders
def _policy(policy_id, policy_sha256, forms, orders):
    return LibraryPolicy(
        policy_id=policy_id, policy_sha256=policy_sha256, prefixes=("/",),
        option_spellings=("DEFAULTLIB",), quote_styles=("VALUE_QUOTED",),
        forms=forms, orders=orders)


def existing_default_policy(policy_id, policy_sha256):
    """The two-library order the existing retained-root policy recognises."""
    return _policy(policy_id, policy_sha256, ("LIBCMT", "OLDNAMES"), (("libcmt", "oldnames"),))


def three_library_policy(policy_id, policy_sha256):
    """Candidate: libcpmt, libcmt, oldnames in that exact order only."""
    return _policy(policy_id, policy_sha256, ("LIBCPMT", "LIBCMT", "OLDNAMES"),
                   (("libcpmt", "libcmt", "oldnames"),))

