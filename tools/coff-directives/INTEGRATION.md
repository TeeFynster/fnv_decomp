# COFF directive witness: integration contract

**Status: library integrated; no consumer or policy adoption.** The coordinator owns integration. Nothing
in this directory changes any existing policy, consumer, serializer, build
recipe or source, and nothing here reads a file, an object, a game image or a
real section.

The module is `coff_directives.py`: Python standard library only, library
functions only. There is no command line, no file or directory access, no
network, no subprocess, no environment access and no native tool. The parse and candidate evaluation entry points return rejected parses or
findings for malformed inputs. Low-level helper functions require their documented
input types and can raise when called incorrectly.

## What it provides

| Function | Purpose |
|---|---|
| `parse_drectve(payload)` | Syntax witness for caller-supplied `.drectve` bytes. Returns a `ParseResult`. |
| `evaluate_library_candidate(payload, context, toolchain, policy, obligations, original)` | Candidate-only witness for a closed set of library-only `DEFAULTLIB` forms. Returns a `CandidateResult`. |
| `compute_binding(inputs)` | Recomputes the binding hash from a result's `inputs` dictionary. |
| `verify_spans(payload, spans)` | Independent byte-coverage check for a span list. |
| `describe_section_flags(flags)` | Names the known flag bits; lists unknown bits without guessing. |
| `canonical_json(obj)` | Deterministic ASCII JSON for any result dictionary. |
| `existing_default_policy(id, sha256)` | Policy for the two-library order `LIBCMT`, `OLDNAMES`. |
| `three_library_policy(id, sha256)` | Policy for the three-library order `LIBCPMT`, `LIBCMT`, `OLDNAMES`. |

Both result types have `to_dict()`, which returns only strings, integers,
booleans, `None`, lists and dictionaries. Equal inputs give equal output.

## Syntax contract (this module's tokenization only)

This is a conservative, documented tokenizer. It is **not** a claim about how a
VC++ 2008 linker reads a `.drectve` section. The linker documentation and the
PE/COFF description are format references only. Older-toolchain behaviour is
unproven.

- The payload is split into spans that cover every byte, with no gap and no
  overlap. Every span keeps its offsets and raw bytes.
- Span kinds: `BOM_UTF8` (exactly the three bytes at offset 0), `SEPARATOR`
  (a maximal run of ASCII space), `CONTROL` (one byte below 0x20, or 0x7f),
  and `TOKEN`.
- A token starts at any other byte and runs to the next space that is outside
  a double-quoted region, or to the next control byte, or to the end. Spaces
  inside quotes stay in the token. An unclosed quote runs to a control byte or
  the end and is flagged. Bytes of 0x80 and above stay inside tokens, flagged.
- NUL and other control bytes (tab, CR, LF and the rest) are never separators
  and are never skipped. A trailing NUL is kept as its own span.
- No code page is inferred. Strict ASCII is decoded for display. A UTF-8 BOM,
  a UTF-16 BOM-like start and any byte of 0x80 and above are labelled and
  left uninterpreted.
- An option token is a prefix `/` or `-`, an ASCII name, and an optional value
  after the first colon. The prefix, the exact spelling of the name and the
  exact bytes of the value are recorded. `/` and `-` are never treated as
  equal, and neither are different cases or extensions.
- Quote style per token: `NONE`, `VALUE_QUOTED` (exactly one pair around the
  whole value), `UNTERMINATED`, or `OTHER` (flagged as ambiguous). A
  backslash directly before a double quote is flagged as an ambiguous escape.
- A token is "well formed" when it has no syntax flag. That says nothing about
  what the linker does with it. Every token and every result carries
  `linker_semantics_proven: false`.
- Option names are recognised case-insensitively **only** so that hidden
  operations can be reported. The exact spelling is always kept.

## Bounds

A payload or token stream beyond a bound is rejected as a whole
(`REJECTED_BOUNDS`) with no partial spans or tokens, so a partial list cannot be
mistaken for complete coverage.

| Bound | Value |
|---|---|
| `max_payload_bytes` | 16384 |
| `max_spans` | 1024 |
| `max_tokens` | 256 |
| `max_token_bytes` | 1024 |
| `max_blockers` | 64 |
| `max_obligations` | 8 |

## Statuses

`ParseResult.status`: `PARSED`, `REJECTED_INPUT` (not exactly `bytes`; a
`bytearray`, `memoryview` or `bytes` subclass is rejected), `REJECTED_BOUNDS`,
`INTERNAL_INCONSISTENCY` (the module's own coverage self-check failed).

`CandidateResult.status`: `EVIDENCE_PRESENT` or `NO_EVIDENCE`. `EVIDENCE_PRESENT`
is evidence only. It is not an approval.

## Candidate inputs

All of these are **assertions by the caller**. The module checks them for form
and for consistency with each other and with the payload. It does not verify
any of them against an object, a toolchain, a policy review or a certificate.
Identifiers match `[A-Za-z0-9][A-Za-z0-9._:-]{0,63}` and hashes are 64
lowercase hex digits. Wrong types (including `bool` for an integer, or a list
for a tuple) are rejected, not coerced.

| Input | Fields |
|---|---|
| `SectionContext` | `container_kind` (`coff-object`), `section_name` (`.drectve`), `physical_section_id`, `section_index` (1 to 65279), `drectve_section_count` (1), `raw_size` (equals the payload length), `raw_data_offset` (non-zero unless `raw_size` is 0; offset plus size within 32 bits), `flags` (must equal `0x00100a00`, which includes `IMAGE_SCN_LNK_INFO`), `relocation_count` (0), `line_number_count` (0), `payload_sha256` (equals the computed hash) |
| `ToolchainAssertion` | `compiler_family` (`msvc`), `compiler_version` (`vc2008-sp1`), `runtime_model` (`static-multithreaded-release`) |
| `LibraryPolicy` | `policy_id`, `policy_sha256`, `prefixes`, `option_spellings` (each `DEFAULTLIB` in some case), `quote_styles` (`NONE`, `VALUE_QUOTED`), `forms` (exact library spellings, at most one per library), `orders` (accepted ordered library sequences) |
| `LibraryObligation` | `family` (`libcpmt`, `libcmt`, `oldnames`), `obligation_id`, `obligation_sha256`, `reviewed` (must be `True`) |
| `OriginalNegative` | `certificate_id`, `certificate_sha256`, `root_id`, `root_sha256`, `blockers` (a tuple of `BlockerRef`: `code`, `identity_id`, `identity_sha256`; order and multiplicity are kept) |

The closed vocabulary for the compiler and runtime assertions is this module's
choice. Extending it is a coordinator decision.

## Candidate rules

Evidence is present only when there are no findings at all. In particular:

- every token is an option token, a `DEFAULTLIB` operation, with a library
  spelling whose stem is `libcpmt`, `libcmt` or `oldnames` (any case) plus an
  optional `.lib` suffix (any case);
- the prefix, option spelling, quote style and library spelling are each
  declared by the policy. The library spelling must equal the policy's single
  form for that library exactly, so `LIBCMT`, `libcmt` and `LIBCMT.lib` are
  three different forms;
- the ordered library sequence equals one of the policy's `orders`;
- no library appears twice (`DUPLICATE_LIBRARY_DIRECTIVE`) or with two
  spellings (`CONFLICTING_LIBRARY_FORMS`);
- separators are single spaces, with at most one leading and one trailing
  space. Runs of spaces are `SEPARATOR_RUN_UNCLASSIFIED`;
- there are no BOM, non-ASCII, NUL or control bytes, no quoting or escape
  ambiguity and no unterminated quote;
- exactly one reviewed obligation exists for each referenced library, and none
  for an unreferenced one. Two libraries cannot share an obligation identity.
  A name alone never counts;
- the policy is itself consistent: no duplicate or conflicting entries, and no
  form that no order uses;
- the original negative lists at least one blocker, no two blockers share an
  identity, and at least one blocker code is one of `DIRECTIVE_CONTRACT_DIFFERS`,
  `UNSUPPORTED_IMPLICIT_LINKER_DIRECTIVE` or `UNKNOWN_DIRECTIVE_CONTRACT`.

`INCLUDE`, `ALTERNATENAME`, `EXPORT`, `ENTRY`, `SECTION`, `MERGE`,
`NODEFAULTLIB`, any unknown operation, any malformed token and any mixture are
reported as findings. Nothing is executed, deleted, rewritten, selected,
aliased or admitted. Input bytes are never modified.

## What a result carries

- `parse`: the complete parse (spans, tokens, raw bytes as hex, labels).
- `findings`: ordered `{code, where}` pairs. A finding never repeats payload
  text.
- `inputs` and `binding_sha256`: every validated input, echoed as an
  assertion, and a SHA-256 over their canonical form. It covers the payload
  length and complete hash, every context field, the toolchain assertion, the
  policy identity, hash and derived content hash, every obligation in order,
  and the original certificate, root and blocker identities and hashes in
  order. Both are `null` when any input is structurally unusable. A negative
  result is bound too.
- `library_operations`: filled only when evidence is present.
- `existing_contract_observation`: whether the raw tokens equal the two
  existing default tokens byte for byte, and whether the section shape equals
  the existing one. It is compared with this module's tokenization. The legacy
  consumer's tokenization was not supplied.
- `blocker_multiplicity`: the count of each original blocker code.
- `unresolved_observations`: conflicts that are reported and left unresolved.
- `reviewable_conjunct`: filled only when evidence is present. It names the one
  directive-token conjunct a later, separately reviewed consumer could
  consider, lists which of the three directive-related blocker codes it
  relates to, and lists the codes it does not address. It always says
  `requires_separate_review: true`.
- `unverified`: always present. It lists what remains unverified:

- `LIBRARY_EXISTENCE`
- `LIBRARY_COMPATIBILITY_WITH_RUNTIME`
- `LIBRARY_SELECTION_BY_LINKER`
- `VC2008_LINKER_DIRECTIVE_PARSING`
- `VC2008_QUOTING_RULES`
- `SLASH_DASH_EQUIVALENCE`
- `OPTION_NAME_CASE_AND_ABBREVIATION_RULES`
- `SECTION_CONTEXT_FACTS_ASSERTED_BY_CALLER`
- `TOOLCHAIN_AND_RUNTIME_ASSERTION`
- `POLICY_REVIEW`
- `LIBRARY_IDENTITY_OBLIGATION_REVIEW`
- `ORIGINAL_NEGATIVE_CERTIFICATE_CORRECTNESS`
- `ALL_OTHER_BLOCKERS`
- `LEGACY_CONSUMER_TOKENIZATION`

## Approval and effect fields (constant)

These are fixed by the type. They cannot be passed to the constructor, and
setting one raises. Every result, including one with evidence, has them all
false or empty.

| Field | Value |
|---|---|
| `candidate_authorized` | `false` |
| `adoption_authorized` | `false` |
| `provider_authorized` | `false` |
| `link_authorized` | `false` |
| `abi_authorized` | `false` |
| `runtime_authorized` | `false` |
| `root_admitted` | `false` |
| `original_certificate_invalidated` | `false` |
| `blockers_discharged` | `[]` |
| `policy_modified` | `false` |
| `bytes_modified` | `false` |
| `directives_executed` | `false` |

The frozen observer's negative outcomes are not changed or superseded by this
module. Integration is a separate reviewed decision.

## Finding codes

| Code | Meaning |
|---|---|
| `CONFLICTING_LIBRARY_FORMS` | one library appears with different spellings |
| `CONTEXT_EMPTY_EXTENT_NONZERO_OFFSET` | zero raw size with a non-zero raw offset |
| `CONTEXT_EXTENT_OVERFLOW` | raw offset plus size exceeds 32 bits |
| `CONTEXT_FIELD_INVALID` | a section context field has the wrong type or form |
| `CONTEXT_FLAGS_DIFFER_FROM_REVIEWED_SHAPE` | flags differ from 0x00100a00 |
| `CONTEXT_FLAGS_MISSING_LNK_INFO` | flags lack IMAGE_SCN_LNK_INFO |
| `CONTEXT_LINE_NUMBERS_PRESENT` | line-number count is not zero |
| `CONTEXT_MISSING_OR_WRONG_TYPE` | section context missing or wrong type |
| `CONTEXT_MISSING_RAW_OFFSET` | non-zero raw size with a zero raw offset |
| `CONTEXT_NOT_OBJECT_ONLY` | container is not declared as a COFF object |
| `CONTEXT_PAYLOAD_HASH_MISMATCH` | asserted payload hash differs from the computed hash |
| `CONTEXT_RAW_SIZE_MISMATCH` | raw size differs from the payload length |
| `CONTEXT_RELOCATIONS_PRESENT` | relocation count is not zero |
| `CONTEXT_SECTION_COUNT_NOT_ONE` | object does not have exactly one .drectve section |
| `CONTEXT_SECTION_NAME_NOT_DRECTVE` | section name is not .drectve |
| `CONTROL_BYTE` | payload has a control byte other than NUL |
| `DUPLICATE_LIBRARY_DIRECTIVE` | the same library form appears more than once |
| `ENCODING_UTF16_BOM_LIKE` | payload starts with a UTF-16 BOM-like pair; not interpreted |
| `ENCODING_UTF8_BOM_PRESENT` | payload starts with a UTF-8 BOM; encoding not interpreted |
| `LIBRARY_FORM_NOT_DECLARED` | library spelling differs from the policy form |
| `MISSING_LIBRARY_OBLIGATION` | a referenced library has no obligation |
| `MIXED_OPERATIONS` | DEFAULTLIB mixed with another operation |
| `NON_ASCII_BYTES` | payload has bytes outside strict ASCII |
| `NO_DIRECTIVE_RELATED_BLOCKER` | no directive-related blocker to consider |
| `NO_DIRECTIVE_TOKENS` | payload has no tokens |
| `NUL_BYTE` | payload has a NUL byte |
| `OBLIGATIONS_MISSING_OR_WRONG_TYPE` | obligations missing or not a tuple |
| `OBLIGATION_CONFLICT` | two different obligations for one library |
| `OBLIGATION_DUPLICATE_FAMILY` | two obligations for one library |
| `OBLIGATION_FIELD_INVALID` | an obligation field has the wrong type or form |
| `OBLIGATION_FOR_UNREFERENCED_LIBRARY` | an obligation names an unreferenced library |
| `OBLIGATION_IDENTITY_REUSED` | one obligation identity used for two libraries |
| `OBLIGATION_NOT_REVIEWED` | an obligation is not marked reviewed |
| `OPTION_SPELLING_NOT_DECLARED` | option spelling not declared by the policy |
| `ORDER_NOT_DECLARED` | library order not declared by the policy |
| `ORIGINAL_DUPLICATE_BLOCKER_IDENTITY` | two blockers share one identity |
| `ORIGINAL_FIELD_INVALID` | an original-negative field has the wrong type or form |
| `ORIGINAL_MISSING_OR_WRONG_TYPE` | original negative identities missing or wrong type |
| `ORIGINAL_NO_BLOCKERS` | the original negative lists no blockers |
| `PAYLOAD_INTERNAL_INCONSISTENCY` | span self-check failed |
| `PAYLOAD_REJECTED_BOUNDS` | payload exceeded a documented bound |
| `PAYLOAD_REJECTED_INPUT` | payload was not bytes |
| `POLICY_CONFLICTING_FORMS` | two spellings are declared for one library |
| `POLICY_DUPLICATE_ENTRY` | a policy list repeats an entry |
| `POLICY_DUPLICATE_FORM` | the same form is declared twice |
| `POLICY_DUPLICATE_ORDER` | the same order is declared twice |
| `POLICY_FIELD_INVALID` | a policy field has the wrong type or form |
| `POLICY_FORM_UNKNOWN_LIBRARY` | a declared form is not libcpmt, libcmt or oldnames |
| `POLICY_FORM_UNUSED` | a declared form appears in no order |
| `POLICY_MISSING_OR_WRONG_TYPE` | policy missing or wrong type |
| `POLICY_OPTION_NOT_DEFAULTLIB` | a declared option spelling is not DEFAULTLIB |
| `POLICY_ORDER_FAMILY_WITHOUT_FORM` | an order names a library with no declared form |
| `POLICY_ORDER_REPEATS_FAMILY` | an order repeats a library |
| `POLICY_ORDER_UNKNOWN_FAMILY` | an order names an unknown library |
| `PREFIX_NOT_DECLARED` | option prefix not declared by the policy |
| `QUOTE_STYLE_NOT_DECLARED` | quote style not declared by the policy |
| `SEPARATOR_RUN_UNCLASSIFIED` | a run of more than one space; linker treatment unproven |
| `TOKEN_SYNTAX_AMBIGUOUS_ESCAPE` | token syntax: AMBIGUOUS_ESCAPE |
| `TOKEN_SYNTAX_AMBIGUOUS_QUOTING` | token syntax: AMBIGUOUS_QUOTING |
| `TOKEN_SYNTAX_BAD_OPTION_NAME` | token syntax: BAD_OPTION_NAME |
| `TOKEN_SYNTAX_EMPTY_VALUE` | token syntax: EMPTY_VALUE |
| `TOKEN_SYNTAX_MISSING_VALUE` | token syntax: MISSING_VALUE |
| `TOKEN_SYNTAX_NON_ASCII` | token syntax: NON_ASCII |
| `TOKEN_SYNTAX_NOT_AN_OPTION` | token syntax: NOT_AN_OPTION |
| `TOKEN_SYNTAX_UNTERMINATED_QUOTE` | token syntax: UNTERMINATED_QUOTE |
| `TOOLCHAIN_FAMILY_UNSUPPORTED` | compiler family is not msvc |
| `TOOLCHAIN_FIELD_INVALID` | a toolchain field has the wrong type or form |
| `TOOLCHAIN_MISSING_OR_WRONG_TYPE` | toolchain assertion missing or wrong type |
| `TOOLCHAIN_RUNTIME_MODEL_INCOMPATIBLE` | runtime model is not static-multithreaded-release |
| `TOOLCHAIN_VERSION_UNSUPPORTED` | compiler version is not vc2008-sp1 |
| `UNKNOWN_LIBRARY` | DEFAULTLIB value is not libcpmt, libcmt or oldnames |
| `UNKNOWN_OPERATION` | option name outside the recognised table |
| `UNSUPPORTED_OPERATION_ALTERNATENAME` | unsupported operation: ALTERNATENAME |
| `UNSUPPORTED_OPERATION_ENTRY` | unsupported operation: ENTRY |
| `UNSUPPORTED_OPERATION_EXPORT` | unsupported operation: EXPORT |
| `UNSUPPORTED_OPERATION_INCLUDE` | unsupported operation: INCLUDE |
| `UNSUPPORTED_OPERATION_MERGE` | unsupported operation: MERGE |
| `UNSUPPORTED_OPERATION_NODEFAULTLIB` | unsupported operation: NODEFAULTLIB |
| `UNSUPPORTED_OPERATION_SECTION` | unsupported operation: SECTION |

`TOKEN_SYNTAX_*` and `UNSUPPORTED_OPERATION_*` are one code per syntax flag and
per hidden operation. Each is listed above.

## Observation codes

| Code | Meaning |
|---|---|
| `OBS_DEFAULT_TOKENS_MATCH_BUT_DIFFERS_BLOCKER_PRESENT` | tokens equal the existing default but a DIRECTIVE_CONTRACT_DIFFERS blocker is listed |

## Unresolved assumptions for the coordinator

1. The legacy consumer, the existing retained-root policy source and the
   observer were not in the packet. The existing policy is encoded only from
   the task description: one section, flags `0x00100a00`, zero relocations and
   the ordered tokens `/DEFAULTLIB:"LIBCMT"`, `/DEFAULTLIB:"OLDNAMES"`.
2. How the legacy consumer separates tokens (leading or trailing spaces,
   quotes, case) is unknown. `existing_contract_observation` uses this module's
   tokenization.
3. The names of the non-ASCII and unsupported-section-shape blockers are not
   given. Blocker codes are opaque strings here, except the three named
   directive-related ones.
4. The closed compiler, version and runtime vocabulary, the exact-flags rule
   (`0x00100a00`), the single-space separator rule and the bounds are this
   module's conservative choices. Each can be widened only by a reviewed change.
5. No claim is made that an unlock count, a cached root, or any real object
   would change status.

## Coordinator source reconciliation

Read-only inspection of the existing retained-root observer and legacy pool confirms their exact ordered default tokens. Both use an ASCII decode and the same regular-expression token extraction: whitespace and NUL outside balanced quoted groups are skipped, quoted groups stay within a token, and the final comparison is case-sensitive and order-sensitive. Malformed quotes can be partially tokenized by that old regex; this module instead reports ambiguous/unterminated syntax and control spans. Its own tokenization must not be substituted for the historical observer when replaying a negative certificate. The retained-root observer checks exactly one section, flags `0x00100a00`, and zero relocations, and emits `NONASCII_DIRECTIVE`, `UNSUPPORTED_DIRECTIVE_SECTION`, `DIRECTIVE_CONTRACT_DIFFERS` and `UNSUPPORTED_IMPLICIT_LINKER_DIRECTIVE` on their respective paths. The legacy pool independently emits `UNKNOWN_DIRECTIVE_CONTRACT` and has its own section-shape check. This witness additionally requires zero line numbers; it does not claim the frozen observer checked them. No observer or policy was changed.

Candidate result nested inputs, legacy observation and conjunct are defensively copied at construction and access, including `to_dict()`, so routine caller mutation cannot make an existing result's binding silently stale. This is API integrity, not a security boundary against hostile Python code; consumers must still recheck the binding and original identity.
