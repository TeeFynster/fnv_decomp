"""Adversarial tests for tools/coff-directives/coff_directives.py.

Only invented bytes and opaque authored identifiers are used. The tests build
their own independent oracle (a regular-expression tokenizer and a regular
expression recogniser for the closed policy) instead of reusing the module's
logic. Run from the repository root:

    python -m unittest discover -s tests/coff-directives -p "test_*.py" -v
"""

import ast
import builtins
import dataclasses
import hashlib
import importlib.util
import itertools
import json
import pathlib
import random
import re
import socket
import subprocess
import sys
import unittest
from unittest import mock

HERE = pathlib.Path(__file__).resolve().parent
ROOT = HERE.parent.parent
TOOL_DIR = ROOT / "tools" / "coff-directives"
MODULE_PATH = TOOL_DIR / "coff_directives.py"

_spec = importlib.util.spec_from_file_location("coff_directives_under_test", str(MODULE_PATH))
cd = importlib.util.module_from_spec(_spec)
sys.modules["coff_directives_under_test"] = cd
_spec.loader.exec_module(cd)


def sha(data):
    return hashlib.sha256(data).hexdigest()


DEFAULT = b'/DEFAULTLIB:"LIBCMT" /DEFAULTLIB:"OLDNAMES"'
THREE = b'/DEFAULTLIB:"LIBCPMT" /DEFAULTLIB:"LIBCMT" /DEFAULTLIB:"OLDNAMES"'
FAMILIES_DEFAULT = ("libcmt", "oldnames")
FAMILIES_THREE = ("libcpmt", "libcmt", "oldnames")
APPROVAL_FIELDS = (
    "candidate_authorized", "adoption_authorized", "provider_authorized",
    "link_authorized", "abi_authorized", "runtime_authorized", "root_admitted",
    "original_certificate_invalidated", "policy_modified", "bytes_modified",
    "directives_executed",
)

POLICY_DEFAULT = cd.existing_default_policy("policy-A", sha(b"policy-A"))
POLICY_THREE = cd.three_library_policy("policy-B", sha(b"policy-B"))
POLICY_FUZZ = dataclasses.replace(
    POLICY_THREE, policy_id="policy-F",
    orders=(("libcmt", "oldnames"), ("libcpmt", "libcmt", "oldnames")))
TOOLCHAIN = cd.ToolchainAssertion("msvc", "vc2008-sp1", "static-multithreaded-release")


def obligations(*families):
    return tuple(cd.LibraryObligation(f, "obligation-" + f, sha(b"obligation-" + f.encode()), True)
                 for f in families)


def original(*codes):
    codes = codes or ("DIRECTIVE_CONTRACT_DIFFERS",)
    return cd.OriginalNegative(
        "certificate-A", sha(b"certificate-A"), "root-A", sha(b"root-A"),
        tuple(cd.BlockerRef(c, "blocker-%d" % i, sha(b"blocker-%d" % i))
              for i, c in enumerate(codes)))


def context(payload):
    data = bytes(payload) if not isinstance(payload, bytes) else payload
    return cd.SectionContext(
        "coff-object", ".drectve", "section-A", 1, 1, len(data),
        0 if not data else 100, 0x00100A00, 0, 0, sha(data))


AUTO = object()


def run(payload=DEFAULT, policy=AUTO, fams=AUTO, ctx_over=None, ctx=AUTO,
        tc=AUTO, obs=AUTO, orig=AUTO):
    """Evaluate with consistent defaults. Pass None (or anything) to replace a part."""
    is_three = isinstance(payload, bytes) and payload == THREE
    if policy is AUTO:
        policy = POLICY_THREE if is_three else POLICY_DEFAULT
    if fams is AUTO:
        fams = FAMILIES_THREE if is_three else FAMILIES_DEFAULT
    if ctx is AUTO:
        ctx = context(payload)
        if ctx_over:
            ctx = dataclasses.replace(ctx, **ctx_over)
    return cd.evaluate_library_candidate(
        payload, ctx, TOOLCHAIN if tc is AUTO else tc, policy,
        obligations(*fams) if obs is AUTO else obs,
        original() if orig is AUTO else orig)


def codes(result):
    return [f.code for f in result.findings]


def walk_keys(obj, path=""):
    if isinstance(obj, dict):
        for k, v in obj.items():
            yield path + "/" + k, v
            for item in walk_keys(v, path + "/" + k):
                yield item
    elif isinstance(obj, list):
        for i, v in enumerate(obj):
            for item in walk_keys(v, path + "[%d]" % i):
                yield item


# Independent tokenizer used as an oracle for the span layout.
_SPAN_RE = re.compile(
    rb' +|(?P<c>[\x00-\x1f\x7f])'
    rb'|(?P<t>(?:[^\x00-\x20\x7f"]|"[^"\x00-\x1f\x7f]*(?:"|(?=[\x00-\x1f\x7f])|\Z))+)')


def oracle_spans(payload):
    out = []
    pos = 0
    if payload.startswith(b"\xef\xbb\xbf"):
        out.append(("BOM_UTF8", 0, 3))
        pos = 3
    for m in _SPAN_RE.finditer(payload, pos):
        assert m.start() == pos, "oracle gap"
        kind = "CONTROL" if m.group("c") is not None else (
            "TOKEN" if m.group("t") is not None else "SEPARATOR")
        out.append((kind, m.start(), m.end()))
        pos = m.end()
    assert pos == len(payload)
    return out


def oracle_accepts(payload, forms, orders):
    """Independent recogniser for the closed policy used in the fuzz test."""
    m = re.fullmatch(rb' ?(/DEFAULTLIB:"[A-Za-z0-9.]+"(?: /DEFAULTLIB:"[A-Za-z0-9.]+")*) ?', payload)
    if not m:
        return None
    by_form = {f: f.lower().split(".")[0] for f in forms}
    fams = []
    for name in re.findall(rb'"([^"]*)"', m.group(1)):
        fam = by_form.get(name.decode("ascii"))
        if fam is None:
            return None
        fams.append(fam)
    return tuple(fams) if tuple(fams) in orders else None


class ParserTests(unittest.TestCase):
    def test_empty_payload_has_no_spans(self):
        p = cd.parse_drectve(b"")
        self.assertEqual((p.status, p.length, p.spans, p.tokens), ("PARSED", 0, (), ()))
        self.assertEqual(p.sha256, sha(b""))
        self.assertTrue(dict(p.coverage)["fully_accounted"])

    def test_default_offsets_and_raw_slices(self):
        payload = b' /DEFAULTLIB:"LIBCMT" /DEFAULTLIB:"OLDNAMES" '
        p = cd.parse_drectve(payload)
        got = [(s.kind, s.start, s.end, s.raw) for s in p.spans]
        self.assertEqual(got, [
            ("SEPARATOR", 0, 1, b" "),
            ("TOKEN", 1, 21, b'/DEFAULTLIB:"LIBCMT"'),
            ("SEPARATOR", 21, 22, b" "),
            ("TOKEN", 22, 44, b'/DEFAULTLIB:"OLDNAMES"'),
            ("SEPARATOR", 44, 45, b" "),
        ])
        self.assertEqual([t.raw for t in p.tokens], list(cd.EXISTING_DEFAULT_TOKENS))
        self.assertEqual(p.length, 45)
        self.assertEqual(p.sha256, sha(payload))
        self.assertEqual(b"".join(s.raw for s in p.spans), payload)

    def test_token_fields_for_default_tokens(self):
        t = cd.parse_drectve(DEFAULT).tokens[0]
        self.assertEqual((t.prefix, t.option_name, t.op_class, t.quote_style),
                         ("/", "DEFAULTLIB", "DEFAULTLIB", "VALUE_QUOTED"))
        self.assertEqual((t.library_spelling, t.library_stem, t.library_suffix, t.library_family),
                         ("LIBCMT", "LIBCMT", "", "libcmt"))
        self.assertEqual(t.value_start, 12)
        self.assertEqual(t.syntax_flags, ())
        self.assertTrue(t.syntax_well_formed)

    def test_every_single_byte_value(self):
        for value in range(256):
            payload = bytes([value])
            p = cd.parse_drectve(payload)
            self.assertEqual(len(p.spans), 1, value)
            s = p.spans[0]
            if value == 0x20:
                expected = "SEPARATOR"
            elif value < 0x20 or value == 0x7F:
                expected = "CONTROL"
            else:
                expected = "TOKEN"
            self.assertEqual((s.kind, s.start, s.end, s.raw), (expected, 0, 1, payload), value)
            if value == 0:
                self.assertEqual(s.detail, "NUL")
            if value >= 0x80:
                self.assertIn("NON_ASCII", p.tokens[0].syntax_flags)
                self.assertIsNone(p.tokens[0].ascii_text)

    def test_exhaustive_short_payloads_match_independent_tokenizer(self):
        alphabet = [b"\x00", b"\t", b" ", b'"', b"/", b":", b"\\", b"\x80", b"A"]
        checked = 0
        for length in range(0, 6):
            for combo in itertools.product(alphabet, repeat=length):
                payload = b"".join(combo)
                p = cd.parse_drectve(payload)
                self.assertEqual(p.status, "PARSED", payload)
                got = [(s.kind, s.start, s.end) for s in p.spans]
                self.assertEqual(got, oracle_spans(payload), payload)
                self.assertEqual(b"".join(s.raw for s in p.spans), payload)
                self.assertEqual(sum(s.end - s.start for s in p.spans), len(payload))
                for t in p.tokens:
                    self.assertFalse(any(b < 0x20 or b == 0x7F for b in t.raw), payload)
                    self.assertNotEqual(t.raw[:1], b" ", payload)
                checked += 1
        self.assertEqual(checked, sum(9 ** n for n in range(6)))

    def test_random_payloads_never_raise_and_stay_covered(self):
        rng = random.Random(20261103)
        for _ in range(3000):
            payload = bytes(rng.randrange(256) for _ in range(rng.randrange(0, 40)))
            p = cd.parse_drectve(payload)
            self.assertEqual(p.status, "PARSED")
            self.assertEqual(cd.verify_spans(payload, p.spans), ())
            self.assertEqual([(s.kind, s.start, s.end) for s in p.spans], oracle_spans(payload))

    def test_separators_recorded_exactly(self):
        p = cd.parse_drectve(b"  /A:b   /C:d ")
        self.assertEqual([(s.detail, s.end - s.start) for s in p.spans if s.kind == "SEPARATOR"],
                         [("SPACE_RUN", 2), ("SPACE_RUN", 3), ("SINGLE_SPACE", 1)])
        self.assertEqual([f.code for f in p.unsupported].count("SEPARATOR_RUN_UNCLASSIFIED"), 2)

    def test_quoted_space_stays_inside_token(self):
        p = cd.parse_drectve(b'/DEFAULTLIB:"A B" /X:y')
        self.assertEqual([t.raw for t in p.tokens], [b'/DEFAULTLIB:"A B"', b"/X:y"])
        self.assertEqual(p.tokens[0].value_text, "A B")
        self.assertIsNone(p.tokens[0].library_family)

    def test_unterminated_quote_swallows_spaces_until_end_or_control(self):
        p = cd.parse_drectve(b'/DEFAULTLIB:"LIBCMT /DEFAULTLIB:"OLDNAMES"')
        # The second quote closes the first quoted region and the third opens a
        # new one that never closes: a single, unterminated token.
        self.assertEqual(len(p.tokens), 1)
        self.assertIn("UNTERMINATED_QUOTE", p.tokens[0].syntax_flags)
        p = cd.parse_drectve(b'/DEFAULTLIB:"LIBCMT /X\x00/Y:z')
        self.assertEqual([s.kind for s in p.spans], ["TOKEN", "CONTROL", "TOKEN"])
        self.assertIn("UNTERMINATED_QUOTE", p.tokens[0].syntax_flags)
        self.assertEqual(p.tokens[0].quote_style, "UNTERMINATED")
        self.assertEqual(p.tokens[0].raw, b'/DEFAULTLIB:"LIBCMT /X')

    def test_control_bytes_are_their_own_spans(self):
        for byte, detail in ((b"\x00", "NUL"), (b"\t", "C0"), (b"\r", "C0"), (b"\n", "C0"),
                             (b"\x0b", "C0"), (b"\x0c", "C0"), (b"\x1a", "C0"), (b"\x7f", "DEL")):
            p = cd.parse_drectve(b"/A:b" + byte + b"/C:d")
            self.assertEqual([(s.kind, s.detail) for s in p.spans],
                             [("TOKEN", ""), ("CONTROL", detail), ("TOKEN", "")], byte)
            self.assertIn("NUL_BYTE" if detail == "NUL" else "CONTROL_BYTE",
                          [f.code for f in p.unsupported])

    def test_trailing_nul_is_not_stripped(self):
        p = cd.parse_drectve(DEFAULT + b"\x00")
        self.assertEqual(p.spans[-1].kind, "CONTROL")
        self.assertEqual(p.length, len(DEFAULT) + 1)
        self.assertEqual(p.sha256, sha(DEFAULT + b"\x00"))

    def test_bom_and_encoding_labels(self):
        bom = cd.parse_drectve(b'\xef\xbb\xbf' + DEFAULT)
        self.assertEqual((bom.spans[0].kind, bom.spans[0].end, bom.encoding),
                         ("BOM_UTF8", 3, "UTF8_BOM_PRESENT"))
        self.assertIn("ENCODING_UTF8_BOM_PRESENT", [f.code for f in bom.unsupported])
        wide = cd.parse_drectve(b"\xff\xfe/\x00A\x00")
        self.assertEqual(wide.encoding_hints, ("UTF16_BOM_LIKE_AT_START",))
        self.assertEqual(wide.encoding, "NON_ASCII_UNKNOWN_ENCODING")
        self.assertEqual(cd.parse_drectve(b"\xfe\xff").encoding_hints, ("UTF16_BOM_LIKE_AT_START",))
        self.assertEqual(cd.parse_drectve(DEFAULT).encoding, "STRICT_ASCII")
        self.assertEqual(cd.parse_drectve(b"/A:\xe9").encoding, "NON_ASCII_UNKNOWN_ENCODING")
        # A BOM that is not at offset zero is only a non-ASCII token, not a BOM.
        mid = cd.parse_drectve(b" \xef\xbb\xbf/A:b")
        self.assertNotIn("BOM_UTF8", [s.kind for s in mid.spans])

    def test_non_ascii_is_never_decoded_or_guessed(self):
        for payload in (b'/DEFAULTLIB:"LIB\xe9"', b'/DEFAULTLIB:"\xc3\xa9"', b'/DEFAULTLIB:"\xff"'):
            t = cd.parse_drectve(payload).tokens[0]
            self.assertIsNone(t.ascii_text)
            self.assertIsNone(t.value_text)
            self.assertIsNone(t.library_spelling)
            self.assertIn("NON_ASCII", t.syntax_flags)

    def test_input_types_other_than_bytes_are_rejected(self):
        class Sub(bytes):
            pass
        for bad in (bytearray(DEFAULT), memoryview(DEFAULT), "text", None, 5, Sub(DEFAULT), [DEFAULT]):
            p = cd.parse_drectve(bad)
            self.assertEqual((p.status, p.rejection_reason), ("REJECTED_INPUT", "PAYLOAD_NOT_BYTES"))
            self.assertEqual((p.spans, p.tokens, p.length, p.sha256), ((), (), None, None))
            self.assertFalse(dict(p.coverage)["fully_accounted"])

    def test_span_self_check_failure_is_reported_not_hidden(self):
        with mock.patch.object(cd, "_scan", return_value=([("TOKEN", 0, 1, "", False)], None)):
            p = cd.parse_drectve(b"AB")
        self.assertEqual((p.status, p.rejection_reason, p.spans, p.tokens),
                         ("INTERNAL_INCONSISTENCY", "SPAN_SELF_CHECK_FAILED", (), ()))
        with mock.patch.object(cd, "_scan", return_value=([("TOKEN", 0, 1, "", False)], None)):
            result = run(DEFAULT)
        self.assertEqual(result.status, "NO_EVIDENCE")
        self.assertIn("PAYLOAD_INTERNAL_INCONSISTENCY", codes(result))

    def test_verify_spans_detects_each_kind_of_damage(self):
        payload = b"/A:b /C:d"
        good = cd.parse_drectve(payload).spans
        self.assertEqual(cd.verify_spans(payload, good), ())
        self.assertIn("SPAN_COVERAGE_INCOMPLETE", cd.verify_spans(payload, good[:-1]))
        self.assertIn("SPAN_GAP_OR_OVERLAP", cd.verify_spans(payload, good[1:]))
        bad = dataclasses.replace(good[0], raw=b"/A:x")
        self.assertIn("SPAN_RAW_MISMATCH", cd.verify_spans(payload, (bad,) + good[1:]))
        bad = dataclasses.replace(good[0], kind="WHAT")
        self.assertIn("SPAN_KIND", cd.verify_spans(payload, (bad,) + good[1:]))
        bad = dataclasses.replace(good[1], index=7)
        self.assertIn("SPAN_INDEX", cd.verify_spans(payload, (good[0], bad) + good[2:]))

    def test_parse_is_deterministic_and_does_not_share_state(self):
        a = cd.canonical_json(cd.parse_drectve(THREE).to_dict())
        b = cd.canonical_json(cd.parse_drectve(THREE).to_dict())
        self.assertEqual(a, b)
        cd.parse_drectve(b"/INCLUDE:x\x00")
        self.assertEqual(cd.canonical_json(cd.parse_drectve(THREE).to_dict()), a)

    def test_no_token_claims_proven_semantics(self):
        d = cd.parse_drectve(THREE).to_dict()
        self.assertTrue(all(t["linker_semantics_proven"] is False for t in d["tokens"]))
        self.assertEqual(d["semantics"], {
            "linker_semantics_proven_for_vc2008_sp1": False,
            "slash_dash_equivalence_proven": False, "quoting_rules_proven": False,
            "case_rules_proven": False, "format_reference_only": True})

    def test_well_formed_syntax_is_not_semantics(self):
        t = cd.parse_drectve(b"/FOO:bar").tokens[0]
        self.assertTrue(t.syntax_well_formed)
        self.assertEqual(t.op_class, "UNKNOWN_OPTION")


class TokenSyntaxTests(unittest.TestCase):
    def tok(self, raw):
        p = cd.parse_drectve(raw)
        self.assertEqual(len(p.tokens), 1, raw)
        return p.tokens[0]

    def test_slash_and_dash_are_recorded_not_merged(self):
        a, b = self.tok(b'/DEFAULTLIB:"LIBCMT"'), self.tok(b'-DEFAULTLIB:"LIBCMT"')
        self.assertEqual((a.prefix, b.prefix), ("/", "-"))
        self.assertNotEqual(a.raw, b.raw)
        self.assertEqual((a.op_class, b.op_class), ("DEFAULTLIB", "DEFAULTLIB"))

    def test_case_and_extension_are_preserved(self):
        cases = {
            b'/DEFAULTLIB:"LIBCMT"': ("LIBCMT", "LIBCMT", "", "libcmt"),
            b'/DEFAULTLIB:"libcmt"': ("libcmt", "libcmt", "", "libcmt"),
            b'/DEFAULTLIB:"LibCMT.lib"': ("LibCMT.lib", "LibCMT", ".lib", "libcmt"),
            b'/DEFAULTLIB:"LIBCMT.LIB"': ("LIBCMT.LIB", "LIBCMT", ".LIB", "libcmt"),
            b'/DEFAULTLIB:"oldnames.lib"': ("oldnames.lib", "oldnames", ".lib", "oldnames"),
            b'/DEFAULTLIB:"LIBCPMT"': ("LIBCPMT", "LIBCPMT", "", "libcpmt"),
            b'/DEFAULTLIB:"LIBCMT.obj"': ("LIBCMT.obj", "LIBCMT.obj", "", None),
            b'/DEFAULTLIB:".lib"': (".lib", ".lib", "", None),
            b'/DEFAULTLIB:"LIBCMT.lib.lib"': ("LIBCMT.lib.lib", "LIBCMT.lib", ".lib", None),
            b'/DEFAULTLIB:"C:\\x\\libcmt.lib"': ("C:\\x\\libcmt.lib", "C:\\x\\libcmt", ".lib", None),
            b'/DEFAULTLIB:"LIBCMTD"': ("LIBCMTD", "LIBCMTD", "", None),
        }
        for raw, (spelling, stem, suffix, family) in cases.items():
            t = self.tok(raw)
            self.assertEqual((t.library_spelling, t.library_stem, t.library_suffix, t.library_family),
                             (spelling, stem, suffix, family), raw)

    def test_option_name_case_is_preserved_and_recognised_case_insensitively(self):
        for raw, spelling in ((b"/defaultlib:A", "defaultlib"), (b"/DefaultLib:A", "DefaultLib"),
                              (b"-DEFAULTLIB:A", "DEFAULTLIB")):
            t = self.tok(raw)
            self.assertEqual((t.option_name, t.op_class), (spelling, "DEFAULTLIB"))

    def test_lookalike_operations_are_not_defaultlib(self):
        for raw, op in ((b"/NODEFAULTLIB:LIBCMT", "NODEFAULTLIB"),
                        (b"/DEFAULTLIBS:LIBCMT", "UNKNOWN_OPTION"),
                        (b"/DEFAULT:LIBCMT", "UNKNOWN_OPTION"),
                        (b"/DEFAULTLIB2:x", "UNKNOWN_OPTION"),
                        (b"/_DEFAULTLIB:x", "MALFORMED_OPTION"),
                        (b"/DEFAULT-LIB:x", "MALFORMED_OPTION"),
                        (b"/1DEFAULTLIB:x", "MALFORMED_OPTION"),
                        (b"/:x", "MALFORMED_OPTION"), (b"/", "MALFORMED_OPTION"),
                        (b"DEFAULTLIB:LIBCMT", "NOT_AN_OPTION"),
                        (b"LIBCMT.lib", "NOT_AN_OPTION")):
            self.assertEqual(self.tok(raw).op_class, op, raw)

    def test_hidden_operation_names_are_classified_in_any_case_and_prefix(self):
        for name in cd.HIDDEN_ROOT_OPERATIONS:
            for variant in (name, name.lower(), name.capitalize()):
                for prefix in (b"/", b"-"):
                    raw = prefix + variant.encode() + b":thing"
                    self.assertEqual(self.tok(raw).op_class, name, raw)
            self.assertEqual(self.tok(b"/" + name.encode()).op_class, name)

    def test_quote_styles(self):
        cases = {
            b"/DEFAULTLIB:LIBCMT": "NONE",
            b'/DEFAULTLIB:"LIBCMT"': "VALUE_QUOTED",
            b'/DEFAULTLIB:""': "VALUE_QUOTED",
            b'/DEFAULTLIB:"LIBCMT': "UNTERMINATED",
            b'/DEFAULTLIB:LIBCMT"': "UNTERMINATED",
            b'"/DEFAULTLIB:LIBCMT"': "OTHER",
            b'/DEFAULTLIB:"LIB"CMT': "OTHER",
            b'/DEFAULTLIB:LIB"CMT"': "OTHER",
            b'/DEFAULTLIB:"LIBCMT""OLDNAMES"': "OTHER",
            b'/DEFAULTLIB:"A"B"C"': "OTHER",
            b'/DEF"AULT"LIB:x': "OTHER",
        }
        for raw, style in cases.items():
            self.assertEqual(self.tok(raw).quote_style, style, raw)
        for raw in (b'"/DEFAULTLIB:LIBCMT"', b'/DEFAULTLIB:"LIB"CMT', b'/DEFAULTLIB:""""'):
            self.assertIn("AMBIGUOUS_QUOTING", self.tok(raw).syntax_flags, raw)

    def test_backslash_before_quote_is_ambiguous_but_other_backslashes_are_not(self):
        self.assertIn("AMBIGUOUS_ESCAPE", self.tok(b'/DEFAULTLIB:"A\\"B"').syntax_flags)
        self.assertNotIn("AMBIGUOUS_ESCAPE", self.tok(b'/DEFAULTLIB:"A\\B"').syntax_flags)

    def test_empty_and_missing_values(self):
        self.assertIn("EMPTY_VALUE", self.tok(b'/DEFAULTLIB:""').syntax_flags)
        self.assertIn("EMPTY_VALUE", self.tok(b"/DEFAULTLIB:").syntax_flags)
        self.assertIn("MISSING_VALUE", self.tok(b"/DEFAULTLIB").syntax_flags)
        self.assertNotIn("MISSING_VALUE", self.tok(b"/NODEFAULTLIB").syntax_flags)
        self.assertIsNone(self.tok(b'/DEFAULTLIB:""').library_spelling)

    def test_first_colon_splits_option_from_value(self):
        t = self.tok(b'/DEFAULTLIB:"C:\\x"')
        self.assertEqual(t.value_text, "C:\\x")
        self.assertEqual(t.value_start, 12)


class ContractTests(unittest.TestCase):
    def test_existing_default_contract_is_evidence_with_exact_order(self):
        r = run(DEFAULT)
        self.assertEqual((r.status, r.findings), ("EVIDENCE_PRESENT", ()))
        self.assertEqual([o.library_spelling for o in r.library_operations], ["LIBCMT", "OLDNAMES"])
        self.assertEqual([o.family for o in r.library_operations], ["libcmt", "oldnames"])
        self.assertEqual([(o.start, o.end, o.raw) for o in r.library_operations],
                         [(0, 20, b'/DEFAULTLIB:"LIBCMT"'), (21, 43, b'/DEFAULTLIB:"OLDNAMES"')])
        self.assertTrue(r.existing_contract_observation["raw_tokens_equal_existing_default"])
        self.assertTrue(r.existing_contract_observation["section_flags_equal_existing"])
        self.assertEqual(r.reviewable_conjunct["ordered_library_forms"], ["LIBCMT", "OLDNAMES"])

    def test_leading_and_trailing_single_spaces_are_accepted_and_recorded(self):
        for payload in (b" " + DEFAULT, DEFAULT + b" ", b" " + DEFAULT + b" "):
            r = run(payload)
            self.assertEqual(r.status, "EVIDENCE_PRESENT", payload)
            self.assertEqual(sum(s.end - s.start for s in r.parse.spans), len(payload))

    def test_three_library_candidate(self):
        r = run(THREE)
        self.assertEqual(r.status, "EVIDENCE_PRESENT")
        self.assertEqual([o.family for o in r.library_operations], list(FAMILIES_THREE))
        self.assertEqual([o.operation_index for o in r.library_operations], [0, 1, 2])
        self.assertFalse(r.existing_contract_observation["raw_tokens_equal_existing_default"])
        self.assertEqual(r.blocker_multiplicity, (("DIRECTIVE_CONTRACT_DIFFERS", 1),))

    def test_same_payload_is_rejected_by_the_other_policy(self):
        r = run(THREE, policy=POLICY_DEFAULT, fams=FAMILIES_THREE)
        self.assertEqual(r.status, "NO_EVIDENCE")
        self.assertIn("LIBRARY_FORM_NOT_DECLARED", codes(r))
        r = run(DEFAULT, policy=POLICY_THREE)
        self.assertEqual(r.status, "NO_EVIDENCE")
        self.assertIn("ORDER_NOT_DECLARED", codes(r))

    def test_order_matters_and_is_reported_as_observed(self):
        swapped = b'/DEFAULTLIB:"OLDNAMES" /DEFAULTLIB:"LIBCMT"'
        r = run(swapped)
        self.assertEqual(codes(r), ["ORDER_NOT_DECLARED"])
        both = dataclasses.replace(POLICY_DEFAULT, orders=(("libcmt", "oldnames"), ("oldnames", "libcmt")))
        r = run(swapped, policy=both)
        self.assertEqual(r.status, "EVIDENCE_PRESENT")
        self.assertEqual([o.library_spelling for o in r.library_operations], ["OLDNAMES", "LIBCMT"])

    def test_exact_case_extension_quoting_forms_are_distinguished(self):
        policy = dataclasses.replace(POLICY_DEFAULT, forms=("libcmt.LIB", "OldNames"),
                                     quote_styles=("VALUE_QUOTED", "NONE"))
        good = b'/DEFAULTLIB:"libcmt.LIB" /DEFAULTLIB:OldNames'
        r = run(good, policy=policy)
        self.assertEqual(r.status, "EVIDENCE_PRESENT")
        self.assertEqual([(o.library_spelling, o.library_stem, o.library_suffix, o.quote_style)
                          for o in r.library_operations],
                         [("libcmt.LIB", "libcmt", ".LIB", "VALUE_QUOTED"),
                          ("OldNames", "OldNames", "", "NONE")])
        for variant in (b'/DEFAULTLIB:"libcmt.lib" /DEFAULTLIB:OldNames',
                        b'/DEFAULTLIB:"LIBCMT.LIB" /DEFAULTLIB:OldNames',
                        b'/DEFAULTLIB:"libcmt" /DEFAULTLIB:OldNames',
                        b'/DEFAULTLIB:"libcmt.LIB" /DEFAULTLIB:oldnames',
                        b'/DEFAULTLIB:"libcmt.LIB" /DEFAULTLIB:OLDNAMES'):
            r = run(variant, policy=policy)
            self.assertEqual(r.status, "NO_EVIDENCE", variant)
            self.assertEqual(codes(r), ["LIBRARY_FORM_NOT_DECLARED"], variant)

    def test_quote_style_prefix_and_option_spelling_must_be_declared(self):
        self.assertEqual(codes(run(b'/DEFAULTLIB:LIBCMT /DEFAULTLIB:OLDNAMES')),
                         ["QUOTE_STYLE_NOT_DECLARED"] * 2)
        self.assertEqual(codes(run(b'-DEFAULTLIB:"LIBCMT" /DEFAULTLIB:"OLDNAMES"')),
                         ["PREFIX_NOT_DECLARED"])
        self.assertEqual(codes(run(b'/defaultlib:"LIBCMT" /DEFAULTLIB:"OLDNAMES"')),
                         ["OPTION_SPELLING_NOT_DECLARED"])
        wide = dataclasses.replace(POLICY_DEFAULT, prefixes=("/", "-"),
                                   option_spellings=("DEFAULTLIB", "defaultlib"))
        r = run(b'-defaultlib:"LIBCMT" /DEFAULTLIB:"OLDNAMES"', policy=wide)
        self.assertEqual(r.status, "EVIDENCE_PRESENT")
        self.assertEqual([(o.prefix, o.option_spelling) for o in r.library_operations],
                         [("-", "defaultlib"), ("/", "DEFAULTLIB")])

    def test_duplicates_and_conflicts_fail_closed(self):
        self.assertIn("DUPLICATE_LIBRARY_DIRECTIVE", codes(run(
            b'/DEFAULTLIB:"LIBCMT" /DEFAULTLIB:"LIBCMT" /DEFAULTLIB:"OLDNAMES"')))
        r = run(b'/DEFAULTLIB:"LIBCMT" /DEFAULTLIB:"libcmt.lib" /DEFAULTLIB:"OLDNAMES"')
        self.assertIn("CONFLICTING_LIBRARY_FORMS", codes(r))
        self.assertEqual(r.status, "NO_EVIDENCE")
        self.assertEqual(r.library_operations, ())
        for payload in (b'/DEFAULTLIB:"LIBCMT"', b'/DEFAULTLIB:"OLDNAMES" /DEFAULTLIB:"OLDNAMES"'):
            self.assertEqual(run(payload).status, "NO_EVIDENCE", payload)

    def test_unknown_libraries_fail_closed(self):
        for name in (b"MSVCRT", b"LIBCMTD", b"LIBCPMTD", b"MSVCPRT", b"KERNEL32", b"libc", b"LIBCMT.obj",
                     b"..\\LIBCMT", b"LIB CMT", b""):
            payload = b'/DEFAULTLIB:"' + name + b'" /DEFAULTLIB:"OLDNAMES"'
            r = run(payload)
            self.assertEqual(r.status, "NO_EVIDENCE", payload)
            self.assertEqual(r.library_operations, ())

    def test_candidate_never_approves_anything(self):
        results = [run(DEFAULT), run(THREE), run(b"/INCLUDE:x"), run(b""), run(bytearray(b"x"))]
        for r in results:
            d = r.to_dict()
            for name in APPROVAL_FIELDS:
                self.assertIs(d[name], False, name)
                self.assertIs(getattr(r, name), False)
            self.assertEqual(d["blockers_discharged"], [])
            for key, value in walk_keys(d):
                if re.search(r"authorized|admitted|invalidated|discharged|modified|executed", key):
                    self.assertIn(value, (False, []), key)

    def test_approval_fields_cannot_be_set_by_the_caller(self):
        r = run(DEFAULT)
        for name in APPROVAL_FIELDS + ("blockers_discharged",):
            with self.assertRaises((TypeError, ValueError)):
                dataclasses.replace(r, **{name: True})
            with self.assertRaises(TypeError):
                cd.CandidateResult(status="x", findings=(), parse=r.parse, inputs=None, binding_sha256=None,
                                   library_operations=(), existing_contract_observation=None,
                                   blocker_multiplicity=(), unresolved_observations=(),
                                   reviewable_conjunct=None, **{name: True})
            with self.assertRaises(dataclasses.FrozenInstanceError):
                setattr(r, name, True)

    def test_evidence_is_reviewable_but_requires_separate_review(self):
        r = run(DEFAULT, orig=original("DIRECTIVE_CONTRACT_DIFFERS", "UNSUPPORTED_IMPLICIT_LINKER_DIRECTIVE",
                                       "SOME_OTHER_BLOCKER", "SOME_OTHER_BLOCKER", "UNKNOWN_DIRECTIVE_CONTRACT"))
        c = r.reviewable_conjunct
        self.assertEqual(c["conjunct_id"], "RETAINED_ROOT_DIRECTIVE_TOKEN_CONTRACT")
        self.assertTrue(c["requires_separate_review"])
        self.assertEqual(c["related_blocker_codes"],
                         ["DIRECTIVE_CONTRACT_DIFFERS", "UNKNOWN_DIRECTIVE_CONTRACT",
                          "UNSUPPORTED_IMPLICIT_LINKER_DIRECTIVE"])
        self.assertEqual(c["not_addressed_blocker_codes"], ["SOME_OTHER_BLOCKER"])
        self.assertEqual(r.blocker_multiplicity, (
            ("DIRECTIVE_CONTRACT_DIFFERS", 1), ("SOME_OTHER_BLOCKER", 2),
            ("UNKNOWN_DIRECTIVE_CONTRACT", 1), ("UNSUPPORTED_IMPLICIT_LINKER_DIRECTIVE", 1)))
        self.assertEqual(r.blockers_discharged, ())
        self.assertIsNone(run(b"/INCLUDE:x").reviewable_conjunct)

    def test_unverified_list_is_always_present(self):
        for r in (run(DEFAULT), run(b"/INCLUDE:x"), run(bytearray(b"x"))):
            d = r.to_dict()
            self.assertEqual(d["unverified"], list(cd.UNVERIFIED))
            for needed in ("LIBRARY_EXISTENCE", "LIBRARY_COMPATIBILITY_WITH_RUNTIME",
                           "LIBRARY_SELECTION_BY_LINKER", "VC2008_QUOTING_RULES",
                           "SLASH_DASH_EQUIVALENCE", "ALL_OTHER_BLOCKERS"):
                self.assertIn(needed, d["unverified"])

    def test_default_match_with_differs_blocker_is_reported_unresolved(self):
        r = run(DEFAULT, orig=original("DIRECTIVE_CONTRACT_DIFFERS"))
        self.assertEqual([f.code for f in r.unresolved_observations],
                         ["OBS_DEFAULT_TOKENS_MATCH_BUT_DIFFERS_BLOCKER_PRESENT"])
        self.assertEqual(r.status, "EVIDENCE_PRESENT")
        r = run(DEFAULT, orig=original("UNKNOWN_DIRECTIVE_CONTRACT"))
        self.assertEqual(r.unresolved_observations, ())
        r = run(THREE, orig=original("DIRECTIVE_CONTRACT_DIFFERS"))
        self.assertEqual(r.unresolved_observations, ())


class HiddenOperationTests(unittest.TestCase):
    def test_each_hidden_operation_alone_is_unsupported(self):
        for name in cd.HIDDEN_ROOT_OPERATIONS:
            for payload in (b"/" + name.encode() + b":x", b"-" + name.lower().encode() + b':"x"',
                            b"/" + name.encode()):
                r = run(payload, fams=())
                self.assertEqual(r.status, "NO_EVIDENCE", payload)
                self.assertIn("UNSUPPORTED_OPERATION_" + name, codes(r), payload)
                self.assertEqual(r.library_operations, ())
                self.assertIsNone(r.reviewable_conjunct)

    def test_each_hidden_operation_mixed_with_the_default_libraries(self):
        for name in cd.HIDDEN_ROOT_OPERATIONS:
            for position in range(3):
                parts = [b'/DEFAULTLIB:"LIBCMT"', b'/DEFAULTLIB:"OLDNAMES"']
                parts.insert(position, b"/" + name.encode() + b":hidden_root")
                r = run(b" ".join(parts))
                self.assertEqual(r.status, "NO_EVIDENCE", parts)
                self.assertIn("UNSUPPORTED_OPERATION_" + name, codes(r))
                self.assertIn("MIXED_OPERATIONS", codes(r))
                self.assertEqual(r.library_operations, ())

    def test_unknown_malformed_and_not_option_tokens(self):
        for payload, expected in ((b"/FOO:bar", "UNKNOWN_OPERATION"),
                                  (b"/EDITANDCONTINUE", "UNKNOWN_OPERATION"),
                                  (b"/FAILIFMISMATCH:a=b", "UNKNOWN_OPERATION"),
                                  (b"/MANIFESTDEPENDENCY:x", "UNKNOWN_OPERATION"),
                                  (b"/_:x", "TOKEN_SYNTAX_BAD_OPTION_NAME"),
                                  (b"plain.obj", "TOKEN_SYNTAX_NOT_AN_OPTION"),
                                  (b"/DEFAULTLIB", "TOKEN_SYNTAX_MISSING_VALUE"),
                                  (b"/DEFAULTLIB:", "TOKEN_SYNTAX_EMPTY_VALUE")):
            r = run(payload, fams=())
            self.assertEqual(r.status, "NO_EVIDENCE", payload)
            self.assertIn(expected, codes(r), payload)

    def test_hidden_root_operations_are_not_hidden_by_odd_framing(self):
        for payload in (b'/INCLUDE:"_main"', b'/include:_main', b'-INCLUDE:_main',
                        b'/ALTERNATENAME:a=b', b'/EXPORT:f,@1', b'/ENTRY:start', b'/SECTION:.x,R',
                        b'/MERGE:.a=.b', b'/NODEFAULTLIB:LIBCMT', b'/NODEFAULTLIB', b'/Include:x'):
            for framed in (payload, b" " + payload, payload + b" ", b'/DEFAULTLIB:"LIBCMT" ' + payload):
                r = run(framed, fams=FAMILIES_DEFAULT if b"DEFAULTLIB" in framed else ())
                self.assertEqual(r.status, "NO_EVIDENCE", framed)
                self.assertTrue(any(c.startswith("UNSUPPORTED_OPERATION_") for c in codes(r)), framed)

    def test_defaultlib_value_cannot_smuggle_another_operation(self):
        for payload in (b'/DEFAULTLIB:"LIBCMT /INCLUDE:x"', b'/DEFAULTLIB:"LIBCMT" /INCLUDE:x',
                        b'/DEFAULTLIB:LIBCMT,/INCLUDE:x'):
            r = run(payload, fams=("libcmt",))
            self.assertEqual(r.status, "NO_EVIDENCE", payload)


class MalformedPayloadTests(unittest.TestCase):
    def assert_blocked(self, payload, expected_code, fams=FAMILIES_DEFAULT):
        r = run(payload, fams=fams)
        self.assertEqual(r.status, "NO_EVIDENCE", payload)
        self.assertIn(expected_code, codes(r), payload)
        self.assertEqual(r.library_operations, ())
        return r

    def test_nul_and_control_bytes(self):
        self.assert_blocked(DEFAULT + b"\x00", "NUL_BYTE")
        self.assert_blocked(b"\x00" + DEFAULT, "NUL_BYTE")
        self.assert_blocked(b'/DEFAULTLIB:"LIBCMT"\x00/DEFAULTLIB:"OLDNAMES"', "NUL_BYTE")
        self.assert_blocked(b'/DEFAULTLIB:"LIB\x00CMT" /DEFAULTLIB:"OLDNAMES"', "NUL_BYTE")
        for byte in (b"\t", b"\r", b"\n", b"\x0b", b"\x0c", b"\x1b", b"\x7f"):
            self.assert_blocked(b'/DEFAULTLIB:"LIBCMT"' + byte + b'/DEFAULTLIB:"OLDNAMES"', "CONTROL_BYTE")
            self.assert_blocked(DEFAULT + byte, "CONTROL_BYTE")

    def test_line_endings_are_not_separators(self):
        for sep in (b"\r\n", b"\n", b"\r", b"\t"):
            r = self.assert_blocked(b'/DEFAULTLIB:"LIBCMT"' + sep + b'/DEFAULTLIB:"OLDNAMES"', "CONTROL_BYTE")
            self.assertEqual(len(r.parse.tokens), 2)

    def test_encoding_cases(self):
        self.assert_blocked(b"\xef\xbb\xbf" + DEFAULT, "ENCODING_UTF8_BOM_PRESENT")
        self.assert_blocked(b"\xef\xbb\xbf\xef\xbb\xbf" + DEFAULT, "ENCODING_UTF8_BOM_PRESENT")
        self.assert_blocked(b"\xff\xfe" + DEFAULT, "ENCODING_UTF16_BOM_LIKE")
        self.assert_blocked(b'/DEFAULTLIB:"LIB\xe9" /DEFAULTLIB:"OLDNAMES"', "NON_ASCII_BYTES")
        self.assert_blocked(b'/DEFAULTLIB:"\xef\xbc\xa1" /DEFAULTLIB:"OLDNAMES"', "TOKEN_SYNTAX_NON_ASCII")
        wide = "/DEFAULTLIB:\"LIBCMT\"".encode("utf-16-le")
        self.assert_blocked(wide, "NUL_BYTE", fams=())

    def test_quote_and_escape_cases(self):
        self.assert_blocked(b'/DEFAULTLIB:"LIBCMT /DEFAULTLIB:"OLDNAMES"', "TOKEN_SYNTAX_UNTERMINATED_QUOTE",
                            fams=())
        self.assert_blocked(b'/DEFAULTLIB:"LIBCMT', "TOKEN_SYNTAX_UNTERMINATED_QUOTE", fams=())
        self.assert_blocked(b'/DEFAULTLIB:LIBCMT"', "TOKEN_SYNTAX_UNTERMINATED_QUOTE", fams=())
        self.assert_blocked(b'"/DEFAULTLIB:LIBCMT" /DEFAULTLIB:"OLDNAMES"', "TOKEN_SYNTAX_NOT_AN_OPTION")
        self.assert_blocked(b'/DEFAULTLIB:"LIB"CMT /DEFAULTLIB:"OLDNAMES"', "TOKEN_SYNTAX_AMBIGUOUS_QUOTING")
        self.assert_blocked(b'/DEFAULTLIB:"LIBCMT\\" /DEFAULTLIB:"OLDNAMES"', "TOKEN_SYNTAX_AMBIGUOUS_ESCAPE")
        self.assert_blocked(b"/DEFAULTLIB:'LIBCMT' /DEFAULTLIB:\"OLDNAMES\"", "UNKNOWN_LIBRARY")

    def test_separator_cases(self):
        self.assert_blocked(b'/DEFAULTLIB:"LIBCMT"  /DEFAULTLIB:"OLDNAMES"', "SEPARATOR_RUN_UNCLASSIFIED")
        self.assert_blocked(b'  ' + DEFAULT, "SEPARATOR_RUN_UNCLASSIFIED")
        self.assert_blocked(DEFAULT + b'   ', "SEPARATOR_RUN_UNCLASSIFIED")
        # No separator: two tokens never merge silently.
        r = self.assert_blocked(b'/DEFAULTLIB:"LIBCMT"/DEFAULTLIB:"OLDNAMES"', "TOKEN_SYNTAX_AMBIGUOUS_QUOTING",
                                fams=())
        self.assertEqual(len(r.parse.tokens), 1)
        self.assert_blocked(b'/DEFAULTLIB:"LIBCMT",/DEFAULTLIB:"OLDNAMES"', "TOKEN_SYNTAX_AMBIGUOUS_QUOTING",
                            fams=())
        self.assert_blocked(b'/DEFAULTLIB:"LIBCMT";/DEFAULTLIB:"OLDNAMES"', "TOKEN_SYNTAX_AMBIGUOUS_QUOTING",
                            fams=())

    def test_empty_and_blank_payloads(self):
        r = self.assert_blocked(b"", "NO_DIRECTIVE_TOKENS", fams=())
        self.assertEqual(r.parse.tokens, ())
        self.assert_blocked(b" ", "NO_DIRECTIVE_TOKENS", fams=())

    def test_bad_input_types(self):
        for bad in (bytearray(DEFAULT), "text", None, 3, memoryview(DEFAULT)):
            r = run(bad, ctx=context(DEFAULT), fams=FAMILIES_DEFAULT)
            self.assertEqual(r.status, "NO_EVIDENCE")
            self.assertIn("PAYLOAD_REJECTED_INPUT", codes(r))
            self.assertIsNone(r.binding_sha256)
            self.assertIsNone(r.inputs)

    def test_oversize_inputs_are_rejected_not_truncated(self):
        r = run(b" " * (cd.MAX_PAYLOAD_BYTES + 1), ctx=context(DEFAULT))
        self.assertIn("PAYLOAD_REJECTED_BOUNDS", codes(r))
        self.assertEqual((r.parse.length, r.parse.sha256, r.parse.rejection_reason),
                         (cd.MAX_PAYLOAD_BYTES + 1, None, "PAYLOAD_TOO_LARGE"))


class BoundsTests(unittest.TestCase):
    def test_payload_size_edge(self):
        ok = cd.parse_drectve(b" " * cd.MAX_PAYLOAD_BYTES)
        self.assertEqual((ok.status, ok.length), ("PARSED", cd.MAX_PAYLOAD_BYTES))
        over = cd.parse_drectve(b" " * (cd.MAX_PAYLOAD_BYTES + 1))
        self.assertEqual((over.status, over.spans, over.tokens), ("REJECTED_BOUNDS", (), ()))
        self.assertFalse(dict(over.coverage)["fully_accounted"])

    def test_token_count_edge(self):
        ok = cd.parse_drectve(b" ".join([b"/X"] * cd.MAX_TOKENS))
        self.assertEqual((ok.status, len(ok.tokens)), ("PARSED", cd.MAX_TOKENS))
        over = cd.parse_drectve(b" ".join([b"/X"] * (cd.MAX_TOKENS + 1)))
        self.assertEqual((over.status, over.rejection_reason, over.tokens),
                         ("REJECTED_BOUNDS", "TOO_MANY_TOKENS", ()))

    def test_token_length_edge(self):
        ok = cd.parse_drectve(b"/X:" + b"a" * (cd.MAX_TOKEN_BYTES - 3))
        self.assertEqual(ok.status, "PARSED")
        over = cd.parse_drectve(b"/X:" + b"a" * (cd.MAX_TOKEN_BYTES - 2))
        self.assertEqual((over.status, over.rejection_reason), ("REJECTED_BOUNDS", "TOKEN_TOO_LONG"))

    def test_span_count_edge(self):
        ok = cd.parse_drectve(b"\x00" * cd.MAX_SPANS)
        self.assertEqual((ok.status, len(ok.spans)), ("PARSED", cd.MAX_SPANS))
        over = cd.parse_drectve(b"\x00" * (cd.MAX_SPANS + 1))
        self.assertEqual((over.status, over.rejection_reason), ("REJECTED_BOUNDS", "TOO_MANY_SPANS"))
        bom = cd.parse_drectve(b"\xef\xbb\xbf" + b"\x00" * (cd.MAX_SPANS - 1))
        self.assertEqual(bom.status, "PARSED")
        self.assertEqual(cd.parse_drectve(b"\xef\xbb\xbf" + b"\x00" * cd.MAX_SPANS).status, "REJECTED_BOUNDS")

    def test_quoted_token_length_counts_the_spaces(self):
        raw = b'/X:"' + b" " * (cd.MAX_TOKEN_BYTES - 5) + b'"'
        self.assertEqual(len(raw), cd.MAX_TOKEN_BYTES)
        self.assertEqual(cd.parse_drectve(raw).status, "PARSED")
        self.assertEqual(cd.parse_drectve(raw + b"a").status, "REJECTED_BOUNDS")

    def test_blocker_and_obligation_bounds(self):
        many = tuple(cd.BlockerRef("DIRECTIVE_CONTRACT_DIFFERS", "blocker-%d" % i, sha(b"%d" % i))
                     for i in range(cd.MAX_BLOCKERS))
        base = original()
        ok = run(DEFAULT, orig=dataclasses.replace(base, blockers=many))
        self.assertEqual(ok.status, "EVIDENCE_PRESENT")
        self.assertEqual(ok.blocker_multiplicity, (("DIRECTIVE_CONTRACT_DIFFERS", cd.MAX_BLOCKERS),))
        over = many + (cd.BlockerRef("DIRECTIVE_CONTRACT_DIFFERS", "blocker-x", sha(b"x")),)
        r = run(DEFAULT, orig=dataclasses.replace(base, blockers=over))
        self.assertIn("ORIGINAL_FIELD_INVALID", codes(r))
        too_many = tuple(cd.LibraryObligation("libcmt", "ob-%d" % i, sha(b"o%d" % i), True)
                         for i in range(cd.MAX_OBLIGATIONS + 1))
        self.assertIn("OBLIGATIONS_MISSING_OR_WRONG_TYPE", codes(run(DEFAULT, obs=too_many)))


class ContextTests(unittest.TestCase):
    def test_each_inconsistency_is_reported(self):
        table = [
            ({"container_kind": "pe-image"}, "CONTEXT_NOT_OBJECT_ONLY"),
            ({"section_name": ".drectv"}, "CONTEXT_SECTION_NAME_NOT_DRECTVE"),
            ({"section_name": ".DRECTVE"}, "CONTEXT_SECTION_NAME_NOT_DRECTVE"),
            ({"drectve_section_count": 0}, "CONTEXT_SECTION_COUNT_NOT_ONE"),
            ({"drectve_section_count": 2}, "CONTEXT_SECTION_COUNT_NOT_ONE"),
            ({"flags": 0x00100800}, "CONTEXT_FLAGS_MISSING_LNK_INFO"),
            ({"flags": 0}, "CONTEXT_FLAGS_MISSING_LNK_INFO"),
            ({"flags": 0x00100A00 | 0x00000020}, "CONTEXT_FLAGS_DIFFER_FROM_REVIEWED_SHAPE"),
            ({"flags": 0x00100200}, "CONTEXT_FLAGS_DIFFER_FROM_REVIEWED_SHAPE"),
            ({"flags": 0x00200A00}, "CONTEXT_FLAGS_DIFFER_FROM_REVIEWED_SHAPE"),
            ({"flags": 0x80100A00}, "CONTEXT_FLAGS_DIFFER_FROM_REVIEWED_SHAPE"),
            ({"relocation_count": 1}, "CONTEXT_RELOCATIONS_PRESENT"),
            ({"line_number_count": 1}, "CONTEXT_LINE_NUMBERS_PRESENT"),
            ({"raw_size": len(DEFAULT) + 1}, "CONTEXT_RAW_SIZE_MISMATCH"),
            ({"raw_size": len(DEFAULT) - 1}, "CONTEXT_RAW_SIZE_MISMATCH"),
            ({"raw_data_offset": 0xFFFFFFFF}, "CONTEXT_EXTENT_OVERFLOW"),
            ({"raw_data_offset": 0}, "CONTEXT_MISSING_RAW_OFFSET"),
            ({"payload_sha256": sha(b"other")}, "CONTEXT_PAYLOAD_HASH_MISMATCH"),
        ]
        for over, expected in table:
            r = run(DEFAULT, ctx_over=over)
            self.assertEqual(r.status, "NO_EVIDENCE", over)
            self.assertEqual(codes(r), [expected], over)
            self.assertEqual(r.library_operations, ())

    def test_empty_extent_rules(self):
        r = run(b"", ctx_over={"raw_data_offset": 4})
        self.assertIn("CONTEXT_EMPTY_EXTENT_NONZERO_OFFSET", codes(r))

    def test_valid_extreme_values_pass_structural_checks(self):
        r = run(DEFAULT, ctx_over={"raw_data_offset": 0xFFFFFFFF - len(DEFAULT), "section_index": 65279,
                                   "physical_section_id": "s" * 64})
        self.assertEqual(r.status, "EVIDENCE_PRESENT")
        self.assertEqual(r.inputs["context"]["raw_extent_end"], 0xFFFFFFFF)

    def test_structural_failures_do_not_echo_values(self):
        bad_values = {
            "container_kind": (None, 5, "", "Coff-Object", "coff object", "x" * 33, b"coff-object"),
            "section_name": (None, "", ".drectve1", ".dre ctv", ".drectve\n", 7),
            "physical_section_id": (None, "", " a", "a b", "a\n", "-a", "a" * 65, 5),
            "section_index": (None, 0, -1, 65280, True, 1.0, "1"),
            "drectve_section_count": (None, -1, 65280, True, 1.0, "1"),
            "raw_size": (None, -1, 0x100000000, True, 1.5, "5"),
            "raw_data_offset": (None, -1, 0x100000000, False, "0"),
            "flags": (None, -1, 0x100000000, True, "0x200", 512.0),
            "relocation_count": (None, -1, True, 0.0, "0"),
            "line_number_count": (None, -1, True, 0.0, "0"),
            "payload_sha256": (None, "", sha(DEFAULT).upper(), sha(DEFAULT)[:-1], sha(DEFAULT) + "0",
                               sha(DEFAULT) + "\n", 5, bytes.fromhex(sha(DEFAULT))),
        }
        for name, values in bad_values.items():
            for value in values:
                r = run(DEFAULT, ctx_over={name: value})
                self.assertEqual(r.status, "NO_EVIDENCE", (name, value))
                self.assertIn("CONTEXT_FIELD_INVALID", codes(r), (name, value))
                self.assertIsNone(r.inputs)
                self.assertIsNone(r.binding_sha256)
                if isinstance(value, str) and len(value) > 3 and name != "payload_sha256":
                    self.assertNotIn(value, cd.canonical_json(r.to_dict()))

    def test_context_object_must_be_the_expected_type(self):
        for bad in (None, {}, "x", 5, [], dataclasses.asdict(context(DEFAULT))):
            r = run(DEFAULT, ctx=bad)
            self.assertIn("CONTEXT_MISSING_OR_WRONG_TYPE", codes(r))
            self.assertEqual(r.status, "NO_EVIDENCE")

    def test_flags_are_described_without_guessing(self):
        d = cd.describe_section_flags(0x00100A00)
        self.assertEqual(d, {"value": "0x00100a00",
                             "named_bits": ["IMAGE_SCN_LNK_INFO", "IMAGE_SCN_LNK_REMOVE"],
                             "alignment_field": 1, "unnamed_bits": "0x00000000"})
        self.assertEqual(cd.describe_section_flags(0x00000400)["unnamed_bits"], "0x00000400")

    def test_context_is_echoed_as_an_assertion(self):
        r = run(DEFAULT)
        for part in ("context", "toolchain", "original"):
            self.assertEqual(r.inputs[part]["assertion_status"], "CALLER_ASSERTED_UNVERIFIED")
        self.assertEqual(r.inputs["policy"]["assertion_status"], "CALLER_DECLARED_UNREVIEWED_BY_THIS_MODULE")
        self.assertTrue(all(o["assertion_status"] == "CALLER_ASSERTED_UNVERIFIED" for o in r.inputs["obligations"]))


class ToolchainTests(unittest.TestCase):
    def test_unsupported_assertions_fail_closed(self):
        table = [
            (dataclasses.replace(TOOLCHAIN, compiler_family="clang"), "TOOLCHAIN_FAMILY_UNSUPPORTED"),
            (dataclasses.replace(TOOLCHAIN, compiler_family="MSVC"), "TOOLCHAIN_FAMILY_UNSUPPORTED"),
            (dataclasses.replace(TOOLCHAIN, compiler_version="vc2010"), "TOOLCHAIN_VERSION_UNSUPPORTED"),
            (dataclasses.replace(TOOLCHAIN, compiler_version="vc2008"), "TOOLCHAIN_VERSION_UNSUPPORTED"),
            (dataclasses.replace(TOOLCHAIN, runtime_model="static-multithreaded-debug"),
             "TOOLCHAIN_RUNTIME_MODEL_INCOMPATIBLE"),
            (dataclasses.replace(TOOLCHAIN, runtime_model="dll-multithreaded-release"),
             "TOOLCHAIN_RUNTIME_MODEL_INCOMPATIBLE"),
        ]
        for tc, expected in table:
            r = run(DEFAULT, tc=tc)
            self.assertEqual(codes(r), [expected])

    def test_missing_or_malformed_assertions(self):
        for bad in (None, {}, ("msvc", "vc2008-sp1", "x"), "msvc"):
            self.assertIn("TOOLCHAIN_MISSING_OR_WRONG_TYPE", codes(run(DEFAULT, tc=bad)))
        for name in ("compiler_family", "compiler_version", "runtime_model"):
            for value in (None, "", "a b", 5, "x\n", "a" * 65):
                r = run(DEFAULT, tc=dataclasses.replace(TOOLCHAIN, **{name: value}))
                self.assertIn("TOOLCHAIN_FIELD_INVALID", codes(r), (name, value))
                self.assertIsNone(r.binding_sha256)


class PolicyTests(unittest.TestCase):
    def test_invalid_policies_fail_closed(self):
        p = POLICY_DEFAULT
        table = [
            (None, "POLICY_MISSING_OR_WRONG_TYPE"),
            (dataclasses.replace(p, policy_id="bad id"), "POLICY_FIELD_INVALID"),
            (dataclasses.replace(p, policy_sha256="abc"), "POLICY_FIELD_INVALID"),
            (dataclasses.replace(p, prefixes=["/"]), "POLICY_FIELD_INVALID"),
            (dataclasses.replace(p, prefixes=()), "POLICY_FIELD_INVALID"),
            (dataclasses.replace(p, prefixes=("//",)), "POLICY_FIELD_INVALID"),
            (dataclasses.replace(p, prefixes=("/", "/")), "POLICY_DUPLICATE_ENTRY"),
            (dataclasses.replace(p, option_spellings=("DEFAULTLIB", "DEFAULTLIB")), "POLICY_DUPLICATE_ENTRY"),
            (dataclasses.replace(p, option_spellings=("NODEFAULTLIB",)), "POLICY_OPTION_NOT_DEFAULTLIB"),
            (dataclasses.replace(p, option_spellings=("DEFAULTLIB1",)), "POLICY_FIELD_INVALID"),
            (dataclasses.replace(p, quote_styles=("OTHER",)), "POLICY_FIELD_INVALID"),
            (dataclasses.replace(p, quote_styles=("NONE", "NONE")), "POLICY_DUPLICATE_ENTRY"),
            (dataclasses.replace(p, forms=("LIBCMT", "MSVCRT"), orders=(("libcmt",),)),
             "POLICY_FORM_UNKNOWN_LIBRARY"),
            (dataclasses.replace(p, forms=("LIBCMT", "LIBCMT", "OLDNAMES")), "POLICY_DUPLICATE_FORM"),
            (dataclasses.replace(p, forms=("LIBCMT", "libcmt", "OLDNAMES")), "POLICY_CONFLICTING_FORMS"),
            (dataclasses.replace(p, forms=("LIBCMT", "LIBCMT.lib")), "POLICY_CONFLICTING_FORMS"),
            (dataclasses.replace(p, orders=(("libcmt", "bogus"),)), "POLICY_ORDER_UNKNOWN_FAMILY"),
            (dataclasses.replace(p, orders=(("libcmt", "libcmt"),)), "POLICY_ORDER_REPEATS_FAMILY"),
            (dataclasses.replace(p, orders=(("libcmt", "oldnames", "libcpmt"),)),
             "POLICY_ORDER_FAMILY_WITHOUT_FORM"),
            (dataclasses.replace(p, orders=(("libcmt", "oldnames"), ("libcmt", "oldnames"))),
             "POLICY_DUPLICATE_ORDER"),
            (dataclasses.replace(p, orders=(("libcmt",),)), "POLICY_FORM_UNUSED"),
            (dataclasses.replace(p, orders=()), "POLICY_FIELD_INVALID"),
            (dataclasses.replace(p, orders=(["libcmt"],)), "POLICY_FIELD_INVALID"),
            (dataclasses.replace(p, orders=((),)), "POLICY_FIELD_INVALID"),
            (dataclasses.replace(p, forms=("LIB CMT",)), "POLICY_FIELD_INVALID"),
        ]
        for policy, expected in table:
            r = run(DEFAULT, policy=policy)
            self.assertEqual(r.status, "NO_EVIDENCE", policy)
            self.assertIn(expected, codes(r), policy)
            self.assertEqual(r.library_operations, ())

    def test_invalid_policy_does_not_let_unrelated_checks_pass(self):
        bad = dataclasses.replace(POLICY_DEFAULT, forms=("LIBCMT", "libcmt", "OLDNAMES"))
        r = run(DEFAULT, policy=bad)
        self.assertEqual(r.status, "NO_EVIDENCE")
        self.assertIsNotNone(r.binding_sha256)

    def test_policy_content_hash_is_derived_not_trusted(self):
        a = run(DEFAULT).inputs["policy"]
        b = run(DEFAULT, policy=dataclasses.replace(POLICY_DEFAULT, policy_sha256=sha(b"other"))).inputs["policy"]
        self.assertEqual(a["content_sha256"], b["content_sha256"])
        self.assertNotEqual(a["policy_sha256"], b["policy_sha256"])
        c = run(DEFAULT, policy=dataclasses.replace(POLICY_DEFAULT, prefixes=("/", "-"))).inputs["policy"]
        self.assertNotEqual(a["content_sha256"], c["content_sha256"])


class ObligationTests(unittest.TestCase):
    def test_each_missing_obligation(self):
        for missing in FAMILIES_THREE:
            have = tuple(f for f in FAMILIES_THREE if f != missing)
            r = run(THREE, obs=obligations(*have))
            self.assertEqual(codes(r), ["MISSING_LIBRARY_OBLIGATION"])
            self.assertEqual(r.findings[0].where, "family:" + missing)
        r = run(THREE, obs=())
        self.assertEqual(codes(r), ["MISSING_LIBRARY_OBLIGATION"] * 3)

    def test_extra_obligations_fail_closed(self):
        r = run(DEFAULT, obs=obligations("libcmt", "oldnames", "libcpmt"))
        self.assertEqual(codes(r), ["OBLIGATION_FOR_UNREFERENCED_LIBRARY"])

    def test_name_alone_is_not_an_obligation(self):
        r = run(DEFAULT, obs=())
        self.assertEqual(r.status, "NO_EVIDENCE")
        self.assertEqual(r.library_operations, ())

    def test_unreviewed_and_malformed_obligations(self):
        good = list(obligations("libcmt", "oldnames"))
        good[0] = dataclasses.replace(good[0], reviewed=False)
        self.assertEqual(codes(run(DEFAULT, obs=tuple(good))), ["OBLIGATION_NOT_REVIEWED"])
        for reviewed in (1, "yes", None):
            bad = list(obligations("libcmt", "oldnames"))
            bad[0] = dataclasses.replace(bad[0], reviewed=reviewed)
            self.assertIn("OBLIGATION_FIELD_INVALID", codes(run(DEFAULT, obs=tuple(bad))))
        for field_name, value in (("family", "msvcrt"), ("family", "LIBCMT"), ("obligation_id", "x y"),
                                  ("obligation_id", ""), ("obligation_sha256", "00"),
                                  ("obligation_sha256", sha(b"x").upper())):
            bad = list(obligations("libcmt", "oldnames"))
            bad[0] = dataclasses.replace(bad[0], **{field_name: value})
            r = run(DEFAULT, obs=tuple(bad))
            self.assertIn("OBLIGATION_FIELD_INVALID", codes(r), (field_name, value))
            self.assertIsNone(r.binding_sha256)

    def test_container_type_must_be_a_tuple_of_obligations(self):
        good = obligations("libcmt", "oldnames")
        self.assertIn("OBLIGATIONS_MISSING_OR_WRONG_TYPE", codes(run(DEFAULT, obs=list(good))))
        self.assertIn("OBLIGATIONS_MISSING_OR_WRONG_TYPE", codes(run(DEFAULT, obs=None)))
        self.assertIn("OBLIGATION_FIELD_INVALID", codes(run(DEFAULT, obs=("libcmt", "oldnames"))))

    def test_duplicate_conflicting_and_reused_obligations(self):
        a, b = obligations("libcmt", "oldnames")
        self.assertIn("OBLIGATION_DUPLICATE_FAMILY", codes(run(DEFAULT, obs=(a, a, b))))
        other = dataclasses.replace(a, obligation_id="obligation-other")
        self.assertIn("OBLIGATION_CONFLICT", codes(run(DEFAULT, obs=(a, other, b))))
        reused = dataclasses.replace(b, obligation_id=a.obligation_id)
        self.assertIn("OBLIGATION_IDENTITY_REUSED", codes(run(DEFAULT, obs=(a, reused))))
        reused = dataclasses.replace(b, obligation_sha256=a.obligation_sha256)
        self.assertIn("OBLIGATION_IDENTITY_REUSED", codes(run(DEFAULT, obs=(a, reused))))


class OriginalNegativeTests(unittest.TestCase):
    def test_missing_and_malformed_original(self):
        for bad in (None, {}, "x"):
            self.assertIn("ORIGINAL_MISSING_OR_WRONG_TYPE", codes(run(DEFAULT, orig=bad)))
        base = original()
        for name, value in (("certificate_id", "bad id"), ("certificate_sha256", "z" * 64),
                            ("root_id", ""), ("root_sha256", sha(b"x")[:-1]), ("blockers", [])):
            r = run(DEFAULT, orig=dataclasses.replace(base, **{name: value}))
            self.assertIn("ORIGINAL_FIELD_INVALID", codes(r), name)
            self.assertIsNone(r.binding_sha256)
        for ref in (cd.BlockerRef("lower_case", "blocker-0", sha(b"0")), cd.BlockerRef("", "blocker-0", sha(b"0")),
                    cd.BlockerRef("CODE", "bad id", sha(b"0")), cd.BlockerRef("CODE", "blocker-0", "short"),
                    "DIRECTIVE_CONTRACT_DIFFERS"):
            r = run(DEFAULT, orig=dataclasses.replace(base, blockers=(ref,)))
            self.assertIn("ORIGINAL_FIELD_INVALID", codes(r), ref)

    def test_negative_certificate_without_blockers_is_inconsistent(self):
        r = run(DEFAULT, orig=dataclasses.replace(original(), blockers=()))
        self.assertEqual(codes(r), ["ORIGINAL_NO_BLOCKERS", "NO_DIRECTIVE_RELATED_BLOCKER"])

    def test_duplicate_blocker_identity(self):
        b = cd.BlockerRef("DIRECTIVE_CONTRACT_DIFFERS", "blocker-0", sha(b"0"))
        r = run(DEFAULT, orig=dataclasses.replace(original(), blockers=(b, b)))
        self.assertEqual(codes(r), ["ORIGINAL_DUPLICATE_BLOCKER_IDENTITY"])

    def test_no_directive_related_blocker_means_nothing_to_consider(self):
        r = run(DEFAULT, orig=original("SOME_OTHER_BLOCKER", "NON_ASCII_BLOCKER"))
        self.assertEqual((r.status, codes(r)), ("NO_EVIDENCE", ["NO_DIRECTIVE_RELATED_BLOCKER"]))
        self.assertEqual(r.library_operations, ())

    def test_multiplicity_is_exact_and_ordered_by_code(self):
        r = run(DEFAULT, orig=original("B_BLOCK", "A_BLOCK", "B_BLOCK", "UNKNOWN_DIRECTIVE_CONTRACT", "B_BLOCK"))
        self.assertEqual(r.blocker_multiplicity, (("A_BLOCK", 1), ("B_BLOCK", 3), ("UNKNOWN_DIRECTIVE_CONTRACT", 1)))
        self.assertEqual([b["code"] for b in r.inputs["original"]["blockers"]],
                         ["B_BLOCK", "A_BLOCK", "B_BLOCK", "UNKNOWN_DIRECTIVE_CONTRACT", "B_BLOCK"])

    def test_original_certificate_is_never_declared_invalid(self):
        r = run(DEFAULT)
        d = r.to_dict()
        self.assertIs(d["original_certificate_invalidated"], False)
        self.assertEqual(d["inputs"]["original"]["certificate_id"], "certificate-A")
        self.assertEqual(d["blockers_discharged"], [])
        self.assertEqual(d["inputs"]["original"]["blockers"][0]["code"], "DIRECTIVE_CONTRACT_DIFFERS")


class BindingTests(unittest.TestCase):
    def test_binding_covers_every_input(self):
        base = run(DEFAULT)
        self.assertEqual(base.status, "EVIDENCE_PRESENT")
        seen = {base.binding_sha256}
        b = original()
        variants = {
            "payload": run(DEFAULT + b" "),
            "ctx.section_id": run(DEFAULT, ctx_over={"physical_section_id": "section-B"}),
            "ctx.index": run(DEFAULT, ctx_over={"section_index": 2}),
            "ctx.offset": run(DEFAULT, ctx_over={"raw_data_offset": 101}),
            "toolchain": None,
            "policy.id": run(DEFAULT, policy=dataclasses.replace(POLICY_DEFAULT, policy_id="policy-Z")),
            "policy.sha": run(DEFAULT, policy=dataclasses.replace(POLICY_DEFAULT, policy_sha256=sha(b"z"))),
            "policy.content": run(DEFAULT, policy=dataclasses.replace(POLICY_DEFAULT, prefixes=("/", "-"))),
            "obligation.id": run(DEFAULT, obs=(dataclasses.replace(obligations("libcmt")[0], obligation_id="ob-z"),
                                               obligations("oldnames")[0])),
            "obligation.sha": run(DEFAULT, obs=(dataclasses.replace(obligations("libcmt")[0],
                                                                    obligation_sha256=sha(b"z")),
                                                obligations("oldnames")[0])),
            "obligation.order": run(DEFAULT, obs=tuple(reversed(obligations("libcmt", "oldnames")))),
            "cert.id": run(DEFAULT, orig=dataclasses.replace(b, certificate_id="certificate-Z")),
            "cert.sha": run(DEFAULT, orig=dataclasses.replace(b, certificate_sha256=sha(b"z"))),
            "root.id": run(DEFAULT, orig=dataclasses.replace(b, root_id="root-Z")),
            "root.sha": run(DEFAULT, orig=dataclasses.replace(b, root_sha256=sha(b"z"))),
            "blocker.code": run(DEFAULT, orig=original("DIRECTIVE_CONTRACT_DIFFERS", "X_BLOCK")),
            "blocker.multiplicity": run(DEFAULT, orig=original("DIRECTIVE_CONTRACT_DIFFERS",
                                                               "DIRECTIVE_CONTRACT_DIFFERS")),
            "blocker.identity": run(DEFAULT, orig=dataclasses.replace(b, blockers=(
                cd.BlockerRef("DIRECTIVE_CONTRACT_DIFFERS", "blocker-9", sha(b"0")),))),
            "blocker.sha": run(DEFAULT, orig=dataclasses.replace(b, blockers=(
                cd.BlockerRef("DIRECTIVE_CONTRACT_DIFFERS", "blocker-0", sha(b"9")),))),
        }
        for name, r in variants.items():
            if r is None:
                continue
            self.assertIsNotNone(r.binding_sha256, name)
            self.assertNotIn(r.binding_sha256, seen, name)
            seen.add(r.binding_sha256)

    def test_binding_is_recomputable_from_the_echoed_inputs(self):
        for r in (run(DEFAULT), run(THREE), run(b"/INCLUDE:x", fams=())):
            self.assertEqual(cd.compute_binding(r.inputs), r.binding_sha256)
            roundtrip = json.loads(cd.canonical_json(r.to_dict()))
            self.assertEqual(cd.compute_binding(roundtrip["inputs"]), r.binding_sha256)
            tampered = json.loads(cd.canonical_json(r.to_dict()))["inputs"]
            tampered["original"]["root_id"] = "root-Z"
            self.assertNotEqual(cd.compute_binding(tampered), r.binding_sha256)

    def test_binding_carries_complete_hashes_and_lengths(self):
        r = run(THREE)
        self.assertEqual(r.inputs["payload"], {"length": len(THREE), "sha256": sha(THREE)})
        self.assertEqual(r.parse.sha256, sha(THREE))
        self.assertRegex(r.binding_sha256, r"^[0-9a-f]{64}$")

    def test_negative_results_are_bound_too(self):
        r = run(b"/INCLUDE:x", fams=())
        self.assertEqual(r.status, "NO_EVIDENCE")
        self.assertIsNotNone(r.binding_sha256)

    def test_binding_is_withheld_when_an_input_is_unusable(self):
        self.assertIsNone(run(DEFAULT, tc=None).binding_sha256)
        self.assertIsNone(run(DEFAULT, policy=5).binding_sha256)


class DeterminismAndIsolationTests(unittest.TestCase):
    def battery(self):
        return [run(p) for p in (DEFAULT, THREE, b"/INCLUDE:x", b"", b"\x00", b'/DEFAULTLIB:"A')]

    def test_results_are_deterministic(self):
        a = [cd.canonical_json(r.to_dict()) for r in self.battery()]
        b = [cd.canonical_json(r.to_dict()) for r in self.battery()]
        self.assertEqual(a, b)
        for text in a:
            text.encode("ascii")
            json.loads(text)

    def test_output_is_pure_json_types(self):
        def check(obj):
            if isinstance(obj, dict):
                for k, v in obj.items():
                    self.assertIs(type(k), str)
                    check(v)
            elif isinstance(obj, list):
                for v in obj:
                    check(v)
            else:
                self.assertIn(type(obj), (str, int, bool, type(None)))
        for r in self.battery():
            check(r.to_dict())

    def test_inputs_are_not_mutated(self):
        payload = bytes(THREE)
        ctx = context(payload)
        before = (payload, dataclasses.astuple(ctx), POLICY_THREE, original())
        run(payload, ctx=ctx)
        self.assertEqual(before, (payload, dataclasses.astuple(ctx), POLICY_THREE, original()))

    def test_module_level_data_is_not_mutated_by_calls(self):
        names = ("FINDING_CODES", "OBSERVATION_CODES", "UNVERIFIED", "LIMITS", "SEMANTICS_NOTE",
                 "EXISTING_DEFAULT_TOKENS", "LIBRARY_FAMILIES", "HIDDEN_ROOT_OPERATIONS")
        before = {n: repr(getattr(cd, n)) for n in names}
        for r in self.battery():
            r.to_dict()["unverified"].append("x")
            r.to_dict()["parse"]["limits"]["max_tokens"] = 0
        self.assertEqual(before, {n: repr(getattr(cd, n)) for n in names})
        self.assertIsInstance(cd.UNVERIFIED, tuple)

    def test_library_calls_perform_no_io(self):
        def forbidden(*args, **kwargs):
            raise AssertionError("side effect attempted")
        with mock.patch.object(builtins, "open", forbidden), \
                mock.patch.object(subprocess, "Popen", forbidden), \
                mock.patch.object(socket, "socket", forbidden), \
                mock.patch.object(socket, "create_connection", forbidden), \
                mock.patch("os.listdir", forbidden), mock.patch("os.scandir", forbidden), \
                mock.patch("os.system", forbidden):
            for r in self.battery():
                cd.canonical_json(r.to_dict())
            cd.parse_drectve(DEFAULT)

    def test_module_source_imports_and_calls_are_restricted(self):
        tree = ast.parse(MODULE_PATH.read_text(encoding="ascii"))
        imports = set()
        for node in ast.walk(tree):
            if isinstance(node, ast.Import):
                imports.update(a.name for a in node.names)
            elif isinstance(node, ast.ImportFrom):
                imports.add(node.module)
        self.assertEqual(imports, {"copy", "dataclasses", "hashlib", "json", "re"})
        banned_names = {"open", "print", "exec", "eval", "compile", "__import__", "input", "breakpoint",
                        "exit", "quit", "globals", "locals", "setattr", "delattr"}
        banned_attrs = {"system", "popen", "environ", "getenv", "listdir", "scandir", "walk", "glob",
                        "read", "write", "read_bytes", "write_bytes", "read_text", "write_text",
                        "unlink", "remove", "rename", "connect", "urlopen", "run", "call", "Popen"}
        for node in ast.walk(tree):
            if isinstance(node, ast.Name):
                self.assertNotIn(node.id, banned_names, node.lineno)
            if isinstance(node, ast.Attribute):
                self.assertNotIn(node.attr, banned_attrs, node.lineno)
                if node.attr == "compile":
                    self.assertEqual(node.value.id, "re")
            self.assertNotIsInstance(node, (ast.Global, ast.Nonlocal, ast.Try, ast.With))

    def test_no_function_takes_a_path_and_none_is_a_cli(self):
        tree = ast.parse(MODULE_PATH.read_text(encoding="ascii"))
        for node in ast.walk(tree):
            if isinstance(node, ast.FunctionDef):
                for arg in node.args.args:
                    self.assertNotIn(arg.arg, ("path", "filename", "file", "directory", "argv", "args"))
        self.assertNotIn("__main__", MODULE_PATH.read_text(encoding="ascii"))
        self.assertFalse(hasattr(cd, "main"))

    def test_source_text_hygiene(self):
        for path in (MODULE_PATH, pathlib.Path(__file__)):
            raw = path.read_bytes()
            raw.decode("ascii")
            self.assertNotIn(b"\r", raw, path.name)
            self.assertNotIn(b"\t", raw, path.name)


class FuzzAgainstIndependentOracleTests(unittest.TestCase):
    PIECES = [
        b'/DEFAULTLIB:"LIBCMT"', b'/DEFAULTLIB:"OLDNAMES"', b'/DEFAULTLIB:"LIBCPMT"',
        b'/DEFAULTLIB:"libcmt"', b'/DEFAULTLIB:"LIBCMT.lib"', b'-DEFAULTLIB:"LIBCMT"',
        b'/DEFAULTLIB:LIBCMT', b'/defaultlib:"LIBCMT"', b'/INCLUDE:x', b'/NODEFAULTLIB:LIBCMT',
        b'/DEFAULTLIB:"LIB CMT"', b'/DEFAULTLIB:"MSVCRT"', b'\x00', b'\t', b' ', b'  ', b'"', b'\\',
        b'\xef\xbb\xbf', b'\xff', b'\r\n', b'/DEFAULTLIB:', b'/DEFAULTLIB', b'x',
    ]
    SEPARATORS = [b"", b" ", b" ", b" ", b"  "]

    def make(self, rng):
        count = rng.randrange(0, 6)
        parts = []
        for _ in range(count):
            parts.append(rng.choice(self.PIECES))
            parts.append(rng.choice(self.SEPARATORS))
        if rng.random() < 0.2:
            parts.insert(0, b" ")
        return b"".join(parts)

    def make_near_valid(self, rng):
        tokens = list(rng.choice([
            [b'/DEFAULTLIB:"LIBCMT"', b'/DEFAULTLIB:"OLDNAMES"'],
            [b'/DEFAULTLIB:"LIBCPMT"', b'/DEFAULTLIB:"LIBCMT"', b'/DEFAULTLIB:"OLDNAMES"']]))
        seps = [b" "] * (len(tokens) - 1)
        lead, trail = rng.choice([b"", b" "]), rng.choice([b"", b" "])
        for _ in range(rng.choice([0, 0, 1, 2])):
            what = rng.randrange(6)
            i = rng.randrange(len(tokens))
            if what == 0:
                tokens[i] = rng.choice(self.PIECES)
            elif what == 1 and len(tokens) > 1:
                del tokens[i]
                del seps[min(i, len(seps) - 1)]
            elif what == 2:
                tokens.insert(i, tokens[i])
                seps.insert(i, b" ")
            elif what == 3 and len(tokens) > 1:
                j = rng.randrange(len(tokens))
                tokens[i], tokens[j] = tokens[j], tokens[i]
            elif what == 4 and seps:
                seps[rng.randrange(len(seps))] = rng.choice([b"", b"  ", b"\t", b"\x00"])
            else:
                lead = rng.choice([b"  ", b"\x00", b"\xef\xbb\xbf", b" "])
        out = lead
        for k, tok in enumerate(tokens):
            out += tok
            if k < len(seps):
                out += seps[k]
        return out + trail

    def test_evidence_exactly_when_the_independent_oracle_accepts(self):
        rng = random.Random(1103)
        accepted = rejected = 0
        forms = POLICY_FUZZ.forms
        orders = POLICY_FUZZ.orders
        # Seed with the exact accepted shapes so both outcomes are well covered.
        corpus = [DEFAULT, THREE, b" " + DEFAULT, DEFAULT + b" ", b" " + THREE + b" "]
        corpus += [self.make(rng) for _ in range(3000)]
        corpus += [self.make_near_valid(rng) for _ in range(3000)]
        for payload in corpus:
            fams = oracle_accepts(payload, forms, orders)
            obs = obligations(*fams) if fams else obligations(*FAMILIES_THREE)
            r = cd.evaluate_library_candidate(payload, context(payload), TOOLCHAIN, POLICY_FUZZ, obs, original())
            self.assertEqual(r.status == "EVIDENCE_PRESENT", fams is not None, payload)
            if fams is not None:
                accepted += 1
                self.assertEqual(tuple(o.family for o in r.library_operations), fams, payload)
                self.assertEqual([o.raw for o in r.library_operations],
                                 re.findall(rb'/DEFAULTLIB:"[A-Za-z0-9.]+"', payload))
            else:
                rejected += 1
                self.assertEqual(r.library_operations, ())
                self.assertEqual(r.findings != (), True)
            d = r.to_dict()
            for name in APPROVAL_FIELDS:
                self.assertIs(d[name], False)
            self.assertEqual(cd.verify_spans(payload, r.parse.spans), ())
        self.assertGreater(accepted, 500)
        self.assertGreater(rejected, 2000)

    def test_dangerous_bytes_never_yield_evidence(self):
        rng = random.Random(77)
        for _ in range(2000):
            base = bytearray(THREE)
            kind = rng.randrange(5)
            at = rng.randrange(0, len(base) + 1)
            if kind == 0:
                base[at:at] = bytes([0])
            elif kind == 1:
                base[at:at] = bytes([rng.choice([1, 9, 10, 13, 31, 127])])
            elif kind == 2:
                base[at:at] = bytes([rng.randrange(128, 256)])
            elif kind == 3:
                base[at:at] = b'"'
            else:
                base[at:at] = b"  "
            payload = bytes(base)
            r = run(payload, policy=POLICY_THREE, fams=FAMILIES_THREE)
            self.assertEqual(r.status, "NO_EVIDENCE", payload)


class RegistryTests(unittest.TestCase):
    """Every finding code the module can emit has a scenario that produces it."""

    def scenarios(self):
        d = {}
        d["PAYLOAD_REJECTED_INPUT"] = lambda: run(bytearray(DEFAULT), ctx=context(DEFAULT))
        d["PAYLOAD_REJECTED_BOUNDS"] = lambda: run(b" " * 16385, ctx=context(DEFAULT))

        def internal():
            with mock.patch.object(cd, "_scan", return_value=([("TOKEN", 0, 1, "", False)], None)):
                return run(DEFAULT)
        d["PAYLOAD_INTERNAL_INCONSISTENCY"] = internal
        d["ENCODING_UTF8_BOM_PRESENT"] = lambda: run(b"\xef\xbb\xbf" + DEFAULT)
        d["ENCODING_UTF16_BOM_LIKE"] = lambda: run(b"\xff\xfe" + DEFAULT)
        d["NON_ASCII_BYTES"] = lambda: run(b'/DEFAULTLIB:"LIB\xe9"', fams=())
        d["NUL_BYTE"] = lambda: run(DEFAULT + b"\x00")
        d["CONTROL_BYTE"] = lambda: run(DEFAULT + b"\t")
        d["SEPARATOR_RUN_UNCLASSIFIED"] = lambda: run(DEFAULT + b"  ")
        d["NO_DIRECTIVE_TOKENS"] = lambda: run(b"", fams=())
        d["MIXED_OPERATIONS"] = lambda: run(DEFAULT + b" /INCLUDE:x")
        d["UNKNOWN_OPERATION"] = lambda: run(b"/FOO:x", fams=())
        d["UNKNOWN_LIBRARY"] = lambda: run(b'/DEFAULTLIB:"MSVCRT"', fams=())
        d["PREFIX_NOT_DECLARED"] = lambda: run(b'-DEFAULTLIB:"LIBCMT" /DEFAULTLIB:"OLDNAMES"')
        d["OPTION_SPELLING_NOT_DECLARED"] = lambda: run(b'/defaultlib:"LIBCMT" /DEFAULTLIB:"OLDNAMES"')
        d["QUOTE_STYLE_NOT_DECLARED"] = lambda: run(b'/DEFAULTLIB:LIBCMT /DEFAULTLIB:"OLDNAMES"')
        d["LIBRARY_FORM_NOT_DECLARED"] = lambda: run(b'/DEFAULTLIB:"libcmt" /DEFAULTLIB:"OLDNAMES"')
        d["DUPLICATE_LIBRARY_DIRECTIVE"] = lambda: run(DEFAULT + b' /DEFAULTLIB:"LIBCMT"')
        d["CONFLICTING_LIBRARY_FORMS"] = lambda: run(DEFAULT + b' /DEFAULTLIB:"libcmt"')
        d["ORDER_NOT_DECLARED"] = lambda: run(b'/DEFAULTLIB:"OLDNAMES" /DEFAULTLIB:"LIBCMT"')
        d["CONTEXT_MISSING_OR_WRONG_TYPE"] = lambda: run(ctx=None)
        d["CONTEXT_FIELD_INVALID"] = lambda: run(ctx_over={"raw_size": True})
        d["CONTEXT_NOT_OBJECT_ONLY"] = lambda: run(ctx_over={"container_kind": "pe-image"})
        d["CONTEXT_SECTION_NAME_NOT_DRECTVE"] = lambda: run(ctx_over={"section_name": ".text"})
        d["CONTEXT_SECTION_COUNT_NOT_ONE"] = lambda: run(ctx_over={"drectve_section_count": 2})
        d["CONTEXT_FLAGS_MISSING_LNK_INFO"] = lambda: run(ctx_over={"flags": 0})
        d["CONTEXT_FLAGS_DIFFER_FROM_REVIEWED_SHAPE"] = lambda: run(ctx_over={"flags": 0x00100200})
        d["CONTEXT_RELOCATIONS_PRESENT"] = lambda: run(ctx_over={"relocation_count": 1})
        d["CONTEXT_LINE_NUMBERS_PRESENT"] = lambda: run(ctx_over={"line_number_count": 1})
        d["CONTEXT_RAW_SIZE_MISMATCH"] = lambda: run(ctx_over={"raw_size": 1})
        d["CONTEXT_EXTENT_OVERFLOW"] = lambda: run(ctx_over={"raw_data_offset": 0xFFFFFFFF})
        d["CONTEXT_EMPTY_EXTENT_NONZERO_OFFSET"] = lambda: run(b"", fams=(), ctx_over={"raw_data_offset": 1})
        d["CONTEXT_MISSING_RAW_OFFSET"] = lambda: run(ctx_over={"raw_data_offset": 0})
        d["CONTEXT_PAYLOAD_HASH_MISMATCH"] = lambda: run(ctx_over={"payload_sha256": sha(b"x")})
        d["TOOLCHAIN_MISSING_OR_WRONG_TYPE"] = lambda: run(tc=5)
        d["TOOLCHAIN_FIELD_INVALID"] = lambda: run(tc=dataclasses.replace(TOOLCHAIN, runtime_model=""))
        d["TOOLCHAIN_FAMILY_UNSUPPORTED"] = lambda: run(tc=dataclasses.replace(TOOLCHAIN, compiler_family="gcc"))
        d["TOOLCHAIN_VERSION_UNSUPPORTED"] = lambda: run(tc=dataclasses.replace(TOOLCHAIN, compiler_version="v1"))
        d["TOOLCHAIN_RUNTIME_MODEL_INCOMPATIBLE"] = lambda: run(
            tc=dataclasses.replace(TOOLCHAIN, runtime_model="dll"))
        p = POLICY_DEFAULT
        d["POLICY_MISSING_OR_WRONG_TYPE"] = lambda: run(policy=5)
        d["POLICY_FIELD_INVALID"] = lambda: run(policy=dataclasses.replace(p, prefixes=("x",)))
        d["POLICY_DUPLICATE_ENTRY"] = lambda: run(policy=dataclasses.replace(p, prefixes=("/", "/")))
        d["POLICY_OPTION_NOT_DEFAULTLIB"] = lambda: run(
            policy=dataclasses.replace(p, option_spellings=("INCLUDE",)))
        d["POLICY_FORM_UNKNOWN_LIBRARY"] = lambda: run(policy=dataclasses.replace(p, forms=("LIBCMT", "FOO")))
        d["POLICY_DUPLICATE_FORM"] = lambda: run(policy=dataclasses.replace(p, forms=("LIBCMT", "LIBCMT")))
        d["POLICY_CONFLICTING_FORMS"] = lambda: run(policy=dataclasses.replace(p, forms=("LIBCMT", "libcmt")))
        d["POLICY_ORDER_UNKNOWN_FAMILY"] = lambda: run(policy=dataclasses.replace(p, orders=(("foo",),)))
        d["POLICY_ORDER_REPEATS_FAMILY"] = lambda: run(policy=dataclasses.replace(p, orders=(("libcmt", "libcmt"),)))
        d["POLICY_ORDER_FAMILY_WITHOUT_FORM"] = lambda: run(
            policy=dataclasses.replace(p, orders=(("libcmt", "libcpmt"),)))
        d["POLICY_DUPLICATE_ORDER"] = lambda: run(
            policy=dataclasses.replace(p, orders=(("libcmt", "oldnames"), ("libcmt", "oldnames"))))
        d["POLICY_FORM_UNUSED"] = lambda: run(policy=dataclasses.replace(p, orders=(("libcmt",),)))
        d["OBLIGATIONS_MISSING_OR_WRONG_TYPE"] = lambda: run(obs=None)
        d["OBLIGATION_FIELD_INVALID"] = lambda: run(obs=("x",))
        d["OBLIGATION_NOT_REVIEWED"] = lambda: run(obs=tuple(
            dataclasses.replace(o, reviewed=False) for o in obligations("libcmt", "oldnames")))
        d["OBLIGATION_DUPLICATE_FAMILY"] = lambda: run(obs=obligations("libcmt", "oldnames", "libcmt"))
        d["OBLIGATION_CONFLICT"] = lambda: run(obs=obligations("libcmt", "oldnames") + (
            dataclasses.replace(obligations("libcmt")[0], obligation_id="other"),))
        d["OBLIGATION_IDENTITY_REUSED"] = lambda: run(obs=(
            obligations("libcmt")[0], dataclasses.replace(obligations("oldnames")[0], obligation_id="obligation-libcmt")))
        d["MISSING_LIBRARY_OBLIGATION"] = lambda: run(obs=obligations("libcmt"))
        d["OBLIGATION_FOR_UNREFERENCED_LIBRARY"] = lambda: run(obs=obligations("libcmt", "oldnames", "libcpmt"))
        d["ORIGINAL_MISSING_OR_WRONG_TYPE"] = lambda: run(orig=5)
        d["ORIGINAL_FIELD_INVALID"] = lambda: run(orig=dataclasses.replace(original(), root_id=""))
        d["ORIGINAL_NO_BLOCKERS"] = lambda: run(orig=dataclasses.replace(original(), blockers=()))
        b = cd.BlockerRef("DIRECTIVE_CONTRACT_DIFFERS", "blocker-0", sha(b"0"))
        d["ORIGINAL_DUPLICATE_BLOCKER_IDENTITY"] = lambda: run(orig=dataclasses.replace(original(), blockers=(b, b)))
        d["NO_DIRECTIVE_RELATED_BLOCKER"] = lambda: run(orig=original("OTHER_BLOCKER"))
        for flag in cd.TOKEN_SYNTAX_FLAGS:
            payload = {
                "NON_ASCII": b"/X:\xe9", "UNTERMINATED_QUOTE": b'/X:"a',
                "AMBIGUOUS_ESCAPE": b'/X:"a\\"b"', "NOT_AN_OPTION": b"plain",
                "BAD_OPTION_NAME": b"/1:x", "AMBIGUOUS_QUOTING": b'/X:"a"b',
                "EMPTY_VALUE": b"/DEFAULTLIB:", "MISSING_VALUE": b"/DEFAULTLIB",
            }[flag]
            d["TOKEN_SYNTAX_" + flag] = (lambda pl: (lambda: run(pl, fams=())))(payload)
        for op in cd.HIDDEN_ROOT_OPERATIONS:
            d["UNSUPPORTED_OPERATION_" + op] = (lambda o: (lambda: run(b"/" + o.encode() + b":x", fams=())))(op)
        return d

    def test_every_registered_code_has_a_scenario_and_vice_versa(self):
        scenarios = self.scenarios()
        self.assertEqual(sorted(scenarios), sorted(cd.FINDING_CODES))

    def test_each_scenario_produces_its_code_and_no_evidence(self):
        for code, build in sorted(self.scenarios().items()):
            r = build()
            self.assertIn(code, codes(r), code)
            self.assertEqual(r.status, "NO_EVIDENCE", code)
            self.assertEqual(r.library_operations, (), code)
            self.assertIsNone(r.reviewable_conjunct, code)
            for f in r.findings:
                self.assertIn(f.code, cd.FINDING_CODES)

    def test_findings_are_stable_and_never_echo_payload_text(self):
        r = run(b'/DEFAULTLIB:"SECRET_NAME_7" /INCLUDE:secret_symbol')
        text = cd.canonical_json([f.to_dict() for f in r.findings])
        self.assertNotIn("SECRET_NAME_7", text)
        self.assertNotIn("secret_symbol", text)

    def test_observation_codes_are_registered(self):
        r = run(DEFAULT, orig=original("DIRECTIVE_CONTRACT_DIFFERS"))
        for f in r.unresolved_observations:
            self.assertIn(f.code, cd.OBSERVATION_CODES)


class DocumentationTests(unittest.TestCase):
    DOCS = ("README.md", "INTEGRATION.md", "RESULTS.md")

    def read(self, name):
        return (TOOL_DIR / name).read_text(encoding="ascii")

    def test_documents_exist_are_ascii_lf_and_private_free(self):
        home = re.escape(pathlib.Path.home().name)
        patterns = [re.compile(p) for p in (home, r"[A-Za-z]:\\", r"/Users/", r"/home/",
                                            r"AppData\b", r"[0-9a-f]{64}")]
        for name in self.DOCS:
            text = self.read(name)
            self.assertNotIn("\r", text, name)
            for pattern in patterns:
                self.assertIsNone(pattern.search(text), (name, pattern.pattern))

    def test_integration_contract_lists_every_finding_and_observation_code(self):
        text = self.read("INTEGRATION.md")
        for code in list(cd.FINDING_CODES) + list(cd.OBSERVATION_CODES):
            self.assertIn("`" + code + "`", text, code)

    def test_integration_contract_names_every_approval_field_and_false_value(self):
        text = self.read("INTEGRATION.md")
        for name in APPROVAL_FIELDS + ("blockers_discharged",):
            self.assertIn("`" + name + "`", text, name)

    def test_integration_contract_states_the_bounds(self):
        text = self.read("INTEGRATION.md")
        for name, value in cd.LIMITS:
            self.assertIn("`%s` | %d" % (name, value), text, name)

    def test_documents_state_that_nothing_is_integrated_or_native(self):
        text = self.read("RESULTS.md")
        for needle in ("not integrated", "NOT_RUN", "Claude Opus 5.5"):
            self.assertIn(needle, text, needle)

    def test_readme_lists_every_delivered_file(self):
        text = self.read("README.md")
        for rel in ("coff_directives.py", "README.md", "INTEGRATION.md", "RESULTS.md",
                    "tests/coff-directives/test_coff_directives.py"):
            self.assertIn(rel, text, rel)

    def test_delivered_tree_has_only_the_expected_files(self):
        found = sorted(p.relative_to(ROOT).as_posix() for base in (TOOL_DIR, HERE)
                       for p in base.rglob("*") if p.is_file() and "__pycache__" not in p.parts)
        self.assertEqual(found, [
            "tests/coff-directives/test_coff_directives.py",
            "tests/coff-directives/test_independent_review.py",
            "tools/coff-directives/INTEGRATION.md",
            "tools/coff-directives/README.md",
            "tools/coff-directives/RESULTS.md",
            "tools/coff-directives/coff_directives.py",
        ])


if __name__ == "__main__":
    unittest.main()
