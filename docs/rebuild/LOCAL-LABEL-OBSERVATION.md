# Bounded local LABEL observation

`local_label_observe.py` is a read-only metadata consumer for one fixed recipe
and root. It never calls the LABEL writer. It requires independently reviewed
source and an externally coordinated metadata lease before the actual run.

The scope is the original manifest-selected object for recipe
`0576-dd603b7071c482c6`, the `0x00706320` singleton in lane 01, its exact source
hash, and the owned reference's PE base-relocation metadata. Explicit CLI hashes
pin all four inputs. One original object is loaded, at most 16 MiB, and rehashed
for stability. The own
lane is limited to 37 records and 128 MiB uncompressed; the frozen lane's gzip
size metadata reports 96,202,743 uncompressed bytes. No global binding, owner or
inventory stream is reread.

The reference is streamed for its full identity hash before and after the
operation. Its code payload is not interpreted or retained. Other reference
reads seek only to DOS/PE headers, the section table and the base-relocation
directory, capped at 4 MiB and required to lie in a non-code `.reloc` section.
The decoder accepts only original ABSOLUTE padding and HIGHLOW records, rejects
duplicate sites or unsupported forms, and produces addresses and metadata
fingerprints rather than original bytes.

The successor additionally permits exactly one separately reviewed four-byte
original relocation operand at `0x00a2350f`, tied to physical section 185 offset
79 and STATIC symbol 1146. Its source is the exact checked 268-byte CODE owner,
and its native target remains local to that owner. The original contract lacks
this one field witness; the separately typed supplement preserves the old
contract rather than fabricating a row in its ledger. No other CODE field,
function body, disassembly or address search is authorized by this consumer.
The receipt reports the actual four operand bytes read, retaining their address
value as relocation metadata rather than original code bytes.

The consumer builds the typed proof from the complete native label-use set and
the pinned central contract's selected/omitted field rows. It supplies actual
observed HIGHLOW membership and recomputes the frozen ordinary certificate
through the reviewed label decoder. Missing, inconsistent or unsupported proof
fails without an output object. A successful private JSON receipt preserves the
full evidence, authority fingerprints, exact label decision, tool identities and
remaining blockers. Tool, source, lane, manifest, reference and original-object
stability are checked before and after publication to a new private file. The
exclusive publisher flushes and fsyncs its output, and removes only its own
created file on a write failure or postwrite drift; preexisting files survive.

No code section is emitted, renamed or modified; no compiler, linker, DLL or
game function is executed. Provider/runtime/emission approvals remain false and
the output requires independent review. An actual metadata result is not an
official fresh comparison or permission to use the resulting code in a runtime.

Seven original authored tests cover exact HIGHLOW/ABSOLUTE handling,
duplicates and unsupported types, code-section rejection, truncation, malformed
headers, finite directory bounds, one-field operand scope, publication drift and fsync failure cleanup.
They use no original image or native tool.
The separate core and independent LABEL tests continue to validate proof and
serialization mechanics. No actual observation has been claimed at source freeze.
