# Physical local LABEL proof and serializer

`tools/rebuild/local_label_projection.py` implements a separate, narrow policy,
`physical-code-local-label-v3`. It changes neither the frozen `76244d2d...` COFF
serializer nor the frozen `4bfdb500...` ordinary-root observer. No original object
has been projected with this module. No link, compiler or executable runs here.

The module distinguishes physical COFF LABEL records (storage class 6) from
EXTERNAL definitions. Supported LABELs have type zero, no auxiliary records,
and an interior value in one complete, byte-checked `.text` owner. The initial
policy accepts only the ordinary `0x60501020` code flags and the standard two
CRT library directives. `$LN` spelling restricts this first supported compiler
form; spelling never establishes identity, ownership or equivalence. Separate
physical indices remain separate even when names are equal. Relevant retained
STATIC class-3 jump-table labels receive the same target/use checks. V2 also
includes omitted same-spelling STATIC records in the proof scope: each must have
its own checked CODE owner and complete physical-use evidence. This establishes
their local scope without merging equal spellings. The earlier narrower V1
observation failed closed on such an omitted STATIC record; no object was emitted.

## APIs

`prove_labels(raw, evidence)` returns an immutable `LabelCertificate`. The exact
evidence keys are:

- `object_sha256`, `source_sha256`, `authority_sha256`, `contract_sha256`;
- sorted integer `keep_sections` and `keep_symbols` lists;
- `unit_functions`, using the existing checked function records (`address`,
  `section`, `value`, `size`, `symbol`, `verdict`);
- `fields`, containing the existing binding-ledger rows for **all** physical
  relocations to all class-6 LABELs in the object, including omitted sections,
  and to retained class-3 jump-table labels;
- `original_highlow_sites`, a unique list of original field addresses from a
  separately bound original-image observation.

V3 additionally permits the explicitly named `supplemental_fields` list. These
must be omitted STATIC CODE references within their own physical section, with
exact native key/object, original field/operand and reference-image identity
bindings. They undergo the same full original operand, HIGHLOW and interior
equations. The decoder accepts exactly the union of the unchanged central field
ledger and those explicit supplements, with no arbitrary extra rows. An
independently reviewed bounded consumer must actually observe and authenticate
the supplemental operand; calculated targets alone are insufficient.

Every physical incoming relocation must have exactly one witness. The proof
checks native record attributes, field width, addend bits, overlap geometry,
source span and native owner identity, original operand, original field address,
target owner plus interior label value and addend, and HIGHLOW membership. DIR32
sites require HIGHLOW; REL32 sites must not have it. Both the label base and final
target must remain inside their exact checked CODE owner. Unknown auxiliary
index contexts, ambiguous external/weak/common lookup, LABEL SafeSEH use,
unsupported directives, escaped selection and unsupported storage fail closed.

`decode_label_policy(raw, contract, frozen_certificate, label_certificate)`
recomputes the unchanged frozen observer certificate. It binds the exact original
contract, source/object hashes, selected physical sets, checked-function ledger
and field rows. Its separate decision can discharge only exact blocker IDs for
proved local records: `UNPROVED_RETAINED_ENTRY_OR_ALIAS`,
`UNSUPPORTED_LIVE_REFERENCE_RECORD` and `LABEL_OMISSION_NOT_PROVED`. Other
blockers, including missing original fields and EH requirements, remain. The
original certificate is never edited or relabeled eligible.

`serialize_labels(raw, keep_sections, keep_symbols, undefined,
label_certificate)` returns `(bytes, maps, receipt)`. It revalidates the proof,
encodes class 6 directly, and preserves Name, Value, Type, StorageClass and
auxiliary identity. It never stages a LABEL as class 3 or EXTERNAL, canonicalizes
a local label, coalesces equal spellings or converts a LABEL to undefined. Normal
class-2/3 undefined conversions remain explicit structural operations requiring
the caller's separate provider/field policy. Selected sections are restricted to
`.text` and `.drectve`; literal/data policies belong to other reviewed consumers.

`verify_label_selection(before, after, maps, label_certificate)` independently
reparses both objects and validates complete injective section/symbol/auxiliary
maps, payloads, flags, relocation geometry, preserved addends and records, and
explicit conversions. The writer calls this verifier before returning. Neither
the writer nor verifier calls the frozen serializer with disguised class-3 data.

## Authority and actual-object gates

Hash equality and internally consistent witnesses do not authenticate their
origin. The pure API intentionally accepts authored synthetic inputs. A reviewed
disk consumer must independently bind the trusted central receipt, exact original
contract/certificate/source/producer hashes and original HIGHLOW evidence, then
require the separate label decoder and its own full projection/namespace policy.
The returned decision explicitly leaves
`original_highlow_authority_authenticated`, `emission_approved`, namespace,
provider and runtime approvals false. They are not implicit overrides.

The first target's five retained class-6 labels, two retained STATIC labels and
four omitted same-spelling class-6 records require nine distinct class-6 record
decisions and complete physical field witnesses. Source control-flow spelling
alone cannot discharge those records. Actual proof generation and any subsequent
object emission need independent review and the unchanged official comparison
and physical-identity gates. No actual-object success is claimed here.

## Original fixture validation

Fourteen focused tests in `test_local_label_projection.py` pass. They cover exact
same-spelling retained/omitted physical identities, section/symbol/auxiliary maps,
class-6 preservation, signed REL32 and DIR32 interior addends, operand/HIGHLOW
failures, missing/duplicate witnesses, match/owner failures, forbidden LABEL
conversion, stale proof and forged output/map rejection. The decoder tests
recompute real frozen certificates and show that an original missing-field
blocker survives label discharge.

The independent lane-06 module
`test_storage6_label_projection_independent.py` adds fourteen authored tests,
including five actual class-6 labels plus two STATIC jump-table labels, all seven
field maps, unchanged frozen-policy rejection, omitted-section uses, malformed
auxiliary records, global-name ambiguity, escaped addends and boolean numeric
identity rejection. These are synthetic source/tool tests only.

Run each exact module with `python -m unittest discover -s tests/rebuild -p
test_local_label_projection.py` and the corresponding independent filename.
