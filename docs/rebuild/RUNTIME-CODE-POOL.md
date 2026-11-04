# Private unresolved CODE archive experiment

`tools/rebuild/runtime_code_pool.py` implements the bounded source-built CODE
archive contract from the [proposal](RUNTIME-CODE-POOL-PROPOSAL.md). It does not
link, compile, load or execute anything. Provider, runtime, materialization and
link approvals remain false. Original source, recipe and comparator gates are
unchanged. Archive format validity and unresolved references are separate from
callable ABI, frame, data, CRT, TLS and startup closure.

At reviewed source freeze v3, the deliverable was source/tests/schema only;
no real object/archive emission or native inspection had occurred. A read-only
six-object preflight exposed unrelated weak
records in the allocator's larger recipe. Root explicitly kept the conservative
policy and approved changing the *planned* emitted subset to three members;
unsupported weak metadata is not silently discarded to force the proposal's
four tentative positives. The subsequently authorized bounded Python result
and its dependency-pin limitation are recorded below. Native archive inspection
was separately authorized later; its measured result is recorded below.

## Exact bounded accounting

The source-only [fixed policy](../../runtime/code-pools/initial-unresolved.json)
records exact source/object hashes, original physical owner indices, spans,
field/base/addend observations and required statuses for all six identities.

| Original identity | Recipe | Expected result under v1 |
|---|---|---|
| `0x00be0b90` | `0000-674cf48524ad6cf3` | Emit complete four-byte leaf; drop explicit debug child. |
| `0x00646d00` | `0703-3a582158246b390e` | Emit complete 55-byte scalar and its two distinct eight-byte source literal sections. |
| `0x00aa13e0` | `2734-15835374a1b91660` | Quarantine: unrelated weak records and unsupported weak auxiliaries in the original object; observed data obligation remains unresolved. |
| `0x00a28740` | `1264-84849a360cbb59fe` | Emit complete 614-byte quaternion function; leave the two original data bases undefined. |
| `0x0043fd40` | `0802-87f974b83dab6f45` | Block actual same-parent EH sections; additional conservative object-level blockers remain visible. |
| `0x00aa0fc0` | `1401-50cd6090ff456b83` | Block original missing HIGHLOW field at +10; never substitute the separate overlay. |

The expected receipt has six assessments, three emitted members, three
quarantines, 673 checked code bytes and 16 retained source literal bytes. Two
undefined data base symbols are expected in the emitted quaternion member;
these define no storage. The allocator is assessed with its full blocker set,
not counted as emitted, omitted from the assessed universe or treated as an
absent source body. A later root-unreachable weak-record exclusion needs its
own proof, reviewed contract and policy change. Any unexpected assessment,
hash/proof change or serializer invariant failure stops the entire run. All six
assessments occur before any member emission.

## Supported mechanical subset

`coff_code_archive.py` is a checked pure-bytes i386 standard COFF reader/writer.
The name-only phase appends strings and updates only the selected physical
symbol Name fields and string length. Numeric physical indices, payloads,
relocation records, addend bits and auxiliary bytes stay identical. Equal names
can denote different physical records; canonical definition names derive from
`(recipe ID, original object hash, original symbol index)`, not spellings or
equal payloads. Conflicting facts for a physical source symbol block it.

The selection phase has explicit bijections for sections, primary symbol slots
and auxiliary slots. Supported section-definition auxiliaries retain length,
checksum, relocation count and COMDAT selection; a retained associative index
must translate through the section map. Unknown index-bearing auxiliary fields,
line metadata, unsupported records and escaping associations fail closed.
Ordinary DIR32 and signed REL32 fields retain their payload/addend bits and
target the translated physical record. Unsupported TLS/SECREL and other
compiler mechanisms block. Import-like source spelling cannot establish an IAT
cell: an authentic binding classification/import ID is required, and an
explicit source-pointer conflict blocks the member. Whole sections only: no slicing, padding removal,
unverified extra entry or source absolute runtime binding is accepted.

Additional STATIC nonfunction labels wholly within the selected span can keep
their real offsets. Retained labels are not exported as callable aliases.
Selected STATIC functions, extra external aliases and additional function
entries require future contracts. A referenced omitted definition may become
an EXTERNAL UNDEFINED record with zero section/value only when it has no
auxiliary record and its exact original base/role is proved. This conversion is
recorded separately from naming, defines no placeholder storage and preserves
the field addend. Canonical undefined identities name the original **base**;
the final original target is also preserved in the obligation ledger. Nothing
turns a source allocator's `void` spelling into a runtime ABI approval.

Only the exact LIBCMT/OLDNAMES default directive sequence is retained, byte for
byte. It records the original contract and does not adopt a CRT provider.
Unknown defaults, `/INCLUDE`, alternate names, export/entry requirements and
other directives block. No aliases are inherited. v1 conservatively blocks any
weak/common records, unknown auxiliary records or `.sxdata` anywhere in a
recipe, including unrelated records; the inventory distinguishes those global
policy reasons from actual same-parent EH. FILE auxiliaries are explicitly
omitted as source/compiler provenance. Known `@feat.00=1` and ordinary `@comp.id` records keep
their actual compiler values; unsupported feature metadata blocks. Debug-only associations are explicit exclusions with
section/parent/size/relocation receipts; executable, EH and unknown children
block. Every original section and primary/auxiliary record gets a disposition
in an emitted member receipt. Unselected extra code is called unverified.

## Assessment interface shared with all-size inventory

`assess_member(data, contract)` parses and verifies the declared object hash.
`assess_parsed(obj, contract)` accepts the immutable output of
`coff_code_archive.parse(data)`; its caller must pin the bytes/hash before and
after. `index_object(obj)` computes the per-recipe symbol, auxiliary and
association indices once and caches them. This supports one parse per recipe
without reparsing a large object for every selected function.

Contracts contain `recipe_id`, `object_sha256`, `source_sha256`, and `selected`
with `original_address`, `symbol`, `symbol_index`, `section`, `value`, `size`.
`verified_match`, `fields_complete` and `missing_fields_complete` must be true.
`fields` are complete raw binding-v2 observations, joined to the exact selected
owner; `missing_fields` are all corresponding migration blockers. Optional
`literal_sections` are explicitly requested complete owners with full literal
proofs. All other source data definitions may only become unresolved
obligations. `provider_identities` maps exact original code bases to checked
physical selected-owner identities; it never imports provider bytes or adopts
runtime compatibility.

Results have schema 1, `policy_id`, `candidate_eligible`, complete
`blockers:[{code,evidence}]`, `obligations`, `observations` and an internal
`extraction_plan`. The separately owned all-size accounting tool strips the
internal plan and records every approved selected address, including global
policy blockers and pending rows. Assessment has no byte-size ceiling and
does not establish completed all-size accounting. The bounded driver does not
emit a full eligible population or claim coverage of 68,657 owners.

## Archive, validation and crash contract

The deterministic container is a standard COFF archive candidate: magic,
60-byte member headers, two linker members, null-terminated long-name table,
stable recipe member names, even-byte alignment, big-endian first index and
little-endian second index/one-based member ordinals. Only actual EXTERNAL
definitions appear in export lookup; unresolved dependencies stay in objects.
Duplicate exported identities/member names reject. A separate archive reader
recovers all staged object hashes and validates both complete export tables,
offsets, names, padding and ordinals. Section, primary-symbol and auxiliary-slot
receipt mappings must be injective and exactly cover output slots; forged alias
maps and incomplete auxiliary maps reject. Independent verification also
rechecks conversion eligibility: the original defining section must be omitted;
an old section number cannot alias an unrelated retained output section. At source freeze, native Microsoft-tool compatibility remained unverified.
The later separately authorized read-only check below covers this exact bounded
archive only.

The bounded driver pins the proposal, authoritative recipe, retained manifest,
v3 receipt, selection, final binding/detail, current data-owner/detail and EH
role ledger, owned reference identity, producer tools, image fingerprint spec,
six source/object observations and absent optional-index state before/after.
The current follow-up also pins the deferred independent-reader wrapper
`coff_rewrite.py` explicitly; v1's omission of that wrapper is disclosed below.
It needs a hash-bound review JSON with `phase="bounded-three-member-emission"`,
`approved=true`, `independent_source_schema_review_pass=true`,
`root_authorized=true`, and `source_sha256` covering exactly the six owned
source/test/policy/doc files. This records an explicit phase approval; it is not
an authentication mechanism. The root supplies it only after review.

After that authorization, the driver will freshly compare each emitted body
before and after rewriting against the owned image using the unchanged
comparator/fingerprint gate and an explicit new-name-to-original-base metadata
view. It additionally reparses staged output with the separately authored
strict inventory parser, checks section/symbol facts and repeats strict parsing
of archive-recovered members. No comparator or oracle flag is changed.

Outputs require a new exclusive directory under ignored `build/rebuild/`.
The fsynced progress ledger records exact inputs, assessments and member hashes;
staged/recovered objects, final archive and a complete hash-bound receipt stay
private. Failures and crash artifacts remain for reconciliation. A rerun must
use a new directory and never overwrite uncertain work. Publication of several
files is not power-failure atomic: consumers require a parsed complete receipt
whose archive/member hashes agree. File existence or a partial journal is not
success. No compiler, `lib.exe`, linker, native child, game launch, fake
executable, automatic provider, original-address fallback or `/FORCE` path is
implemented.

## Synthetic validation

Run the two focused suites with Python unittest discovery for
`test_coff_code_archive.py` and `test_runtime_code_pool.py`. The current 30
authored synthetic tests pass: physical duplicate names versus identities,
full literal owners/equal content, signed/unsigned addends, static interior
labels, section/primary/auxiliary maps, definition conversion, malformed bounds,
hidden metadata, directives/EH/weak/SafeSEH blockers, exact field coverage,
archive indices/long names/alignment, unresolved dependencies, stale inputs,
exclusive writes, source-review requirements and interrupted publication.
These tests execute no compiled payload and contain no copied game bytes.
The new dependency-pin regression proves stale wrapper rejection before proof
processing and detects later drift. The later separately authorized native archive check is recorded below; these
synthetic tests alone do not establish conformance.

## Authorized bounded Python outcome and follow-up

After both independent source reviews accepted freeze v3, root authorized the
bounded private Python phase. The independently authored phase receipt
`build/rebuild/code-pool-emission-review-v3.json`, SHA-256
`e032a8c1355f7f762df78fa3e0ac0fad687541efe4e9c5147452c43af5aef240`,
records that authorization and the actual reviewer identities.

Private `build/rebuild/code-pool-bounded-v1/receipt.json`, SHA-256
`ccf3d585e3ae48482887436fef2c1048f5f37a280b50098fabecf9ad42a402fe`,
reports exactly six assessments, three emitted recipe members, three explicit
quarantines, 673 checked code bytes and 16 source literal bytes. Its archive
SHA-256 is
`d938dd68a5512761e5c1af5f5a9bfa9d6e2a4f6741d45d5f44baf2b4994f73f1`.
The leaf/scalar have no undefined references; the quaternion retains exactly
two undefined original-data base identities. All three fresh before/after
unchanged-core comparisons returned MATCH. The exact allocator/EH/missing-field
statuses agree with the fixed table above.

Independent outcome reviews rehashed the receipt, archive, progress and 40
observed inputs; checked original/staged/recovered payloads, flags, symbols,
auxiliaries, physical mappings and relocation targets with the separate COFF
reader; independently decoded both archive indices, all three members/five
exports, long names and padding; and reconciled the six proof/obligation joins,
canonical data bases, false approval flags and complete progress. The saved
fresh comparator reports were checked; those reviewers did not rerun the
original comparison. Native archive conformance remains unverified.

After those reviews, the producer identified a pinning omission: the deferred
independent-reader wrapper `coff_rewrite.py` was used but its own source hash
was absent from v1's 40 observed inputs. Its inventory dependency and unchanged
oracle were pinned. No wrapper change was observed, but v1 does not prove that
wrapper's before/after hash; it must not be described as pinning every producer.
The source now explicitly pins its exact existing hash
`48cea438b05a1c2de992eea4200b45a1eb14e49a27704a5c6fff98f941b1ae4c`.
This is a provenance correction, with no serializer or assessment-policy change.
The newly reviewed private bounded rerun is recorded below.

All six original freeze-v3 source/test/policy/doc files are preserved under the
private v1 directory's `source-freeze-v3/`, byte-hash checked against the original
freeze receipt. The two subsequently edited source/test files were reconstructed
by removing only the disclosed pin/test additions, then their original hashes
were verified before exclusive archival. V1 receipts and artifacts were not
rewritten. Both Python emission phases used no compiler, native archive tool,
executable link or game execution. Later read-only archive inspection is separate.


## Corrected v2 and native read-only outcome

After the designated independent narrow delta review and renewed root
authorization, private `build/rebuild/code-pool-bounded-v2/receipt.json`, SHA-256
`adfffdc5b6327050f180f1ea1abebe57673ec67fafba30ce1e265d719ab1ad81`,
passed with 41 observed inputs, including the previously omitted reader wrapper.
The source/schema delta adds only that producer pin and its negative test;
assessment, policy and serialization are unchanged. A separate independent
outcome review checked all 41 hashes, all six statuses, complete progress and
pre-emission source snapshots. The archive and all three staged/recovered
member objects are byte-identical to v1. Fresh unchanged-core before/after
comparisons again passed for all three emitted functions. Counts remain six
assessed, three emitted, three quarantined, 673 code bytes and 16 literal bytes.

Root then separately authorized native **read-only** archive conformance on
that exact v2 artifact. Existing trusted SP1 Microsoft Library Manager and
COFF/PE Dumper version `9.00.30729.01` performed exactly five commands:
`LIB /LIST` and `DUMPBIN /HEADERS`, `/SYMBOLS`, `/LINKERMEMBER:1`,
`/LINKERMEMBER:2`. All five returned zero. There was no compiler invocation,
executable link, archive rewrite, raw-data/disassembly switch or member/game
execution. Tool hashes and private wrapper sources/commands are recorded in
the new read-only receipt; the archive hash remains
`d938dd68a5512761e5c1af5f5a9bfa9d6e2a4f6741d45d5f44baf2b4994f73f1`.

Private `build/rebuild/code-pool-native-conformance-v1/receipt.json`, SHA-256
`eb5c39775918b10a6927b032bc3ac2884caeb26c1b59f7eeffb3d7e7af8dd937`,
records 69 bound input/tool/source/member/log hashes with unchanged before/after
observations. Actual Microsoft views agree with the independent Python
expectations for three I386 members, five exported definitions, both complete
linker-index tables and offsets/ordinals, section extents/flags/relocation counts,
primary symbols and section auxiliaries/checksums, and exactly two undefined
quaternion data symbols. `LIB /LIST` presents the three names in reverse physical
order; the complete member multiset matches and that presentation difference
is explicitly recorded.

The designated independent reviewer checked all 69 hashes and exact read-only
command/log bindings, reconciled the native views and replayed the offline
reconciler without rerunning a native command. That replay reproduced the saved
receipt after JSON normalization. This establishes that the exact bounded
archive is readable through these Microsoft views. It does not prove executable
link completion, callable ABI, data/provider/CRT/TLS/EH closure or game runtime
readiness. The OS loader graph was not independently reconstructed.

All six exact pre-emission v4 source/test/policy/doc files remain preserved in
private `build/rebuild/code-pool-source-freeze-v4/`. The measured documentation
update occurred only after the v2 and native outcome reviews; it is distinguished
from producer drift by the private `post-run-documentation.json` record beside
the native receipt. The five implementation/test/policy files remain byte-hash
identical to reviewed v4. Original receipts, source snapshots and failed/limited
evidence are retained; no commit or push was made by this implementation.
