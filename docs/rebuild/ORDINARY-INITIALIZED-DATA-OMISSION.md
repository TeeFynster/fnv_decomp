# Typed initialized-data omission witness

`tools/rebuild/ordinary_initialized_data_omission.py` observes a narrow omission
case that the frozen ordinary observer rejects as an unknown section form. It
does not alter that observer, its original certificate, the game sources, the
reference matcher, a DATA provider, or an object. No COFF emission occurs.

The pure API is `observe_omitted_initialized_data(raw, contract, certificate,
requested_sections)`. It pins the existing parser and observer, hashes the raw
object, checks source/recipe lineage, and recomputes the complete original
certificate. The supplied certificate must match exactly. Operational callers
must authenticate the accepted collector envelope, original source and retained
MATCH/selection proofs, and input stability separately. Contract booleans and a
replay are not a substitute for those external proofs.

The first policy recognizes exactly readonly initialized `.rdata` with flags
`0x40300040` (four-byte alignment without COMDAT) and `0x40101040` (one-byte
alignment with selection-one COMDAT). It accepts no mask-based expansion to
other flags, writable data, uninitialized storage, TLS or EH sections. Runtime
arrays and source initializers gain no ownership or adoption approval; physical
COFF type-zero DATA records do not establish their source-level type. A candidate
has its complete initialized payload, one
exact section-definition auxiliary record, only ordinary DATA primary records,
and no outgoing relocation fields or association links. Selection two is not
treated as selection one.

The witness builds a complete directed physical graph from all primary symbols,
section relocations, symbol-section relationships, external/function name
equivalence, weak fallbacks and associative COMDAT records. Roots protect every
retained section and primary, undefined-conversion target, weak endpoint,
directive name target, SafeSEH handler, special section and compiler/runtime
metadata identity. Symbol-to-section and section-to-symbol relationships are
followed, as are association links in both directions. Ordinary relocations are
directed: an omitted caller of a retained entry does not become a runtime root
merely because it calls that entry. Unknown structural auxiliary or directive
contracts prevent a witness.

An incoming relocation from omitted ordinary CODE is allowed only when its
source section and candidate target remain outside that protected closure. The
source must be an exact ordinary `.text` selection-one section. Any retained,
converted, weak, directive, SafeSEH, associated EH/compiler or transitive protected
use blocks the candidate. A repeated section-symbol spelling is not a linker
name-equivalence edge; an escaping ordinary DATA name relationship is blocked.

This proves local omission from this projected module only. It does not prove
that the original data or its callers are globally unreachable, that the data
has a particular source type or original base address, or that any runtime DATA
owner is available. Incoming omitted-to-omitted fields are recorded as physical
uses, without inventing original binding-row classifications. Retained DATA
fields remain blocked pending a separate authentic conversion contract.

The result identifies only exact original `UNSUPPORTED_SECTION_SEMANTICS`
blocker IDs for which a witness passed. Every other blocker is preserved. A
reviewed successor adapter must consume that typed witness and construct a new
source-bound certificate; this witness alone does not grant root closure,
serialization, namespace, provider, ABI or runtime approval. Failure rows retain
their precise blockers, and all promotion flags remain false.

Authored synthetic tests cover exact accepted forms, isolated omitted uses,
retained and transitive dependencies, outgoing pointers, unknown flags and
special domains, source/certificate drift, alias relationships, unsupported
COMDAT and compiler/runtime/RTTI symbol families. They read no original object
or reference image and invoke no native tools.
