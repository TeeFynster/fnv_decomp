# Generated-code target gaps and ownership queue

Read-only recovery audit of checkpoint `fb73d342e64c90d1aa7d1fccb43c6955524b82e4`,
November 2, 2026. This audit classifies evidence and proposes implementation
tasks. It does not supply 7,422 missing functions, select runtime providers,
approve data fixups, or establish a playable executable. See the
[data plan](DATA-PLAN.md), [runtime gaps ledger](RUNTIME-GAPS.md),
[data strategy](DATA-STRATEGY.md) and [retained verification](RETAINED-VERIFY.md).

## Recovered input identities

Recovery freshly hashed the following exact private artifacts under the ignored
`build/rebuild/` directory. No archive traversal, image mutation, game execution,
service call, compiler invocation or additional instruction sampling was needed.

| Artifact | SHA-256 |
|---|---|
| `data-plan-owned-v4.json` | `127644b75ed0c2826a3c1d89e4718076f4617b5a0d1f949b5faa4d61f54e6e93` |
| `data-plan-owned-v4.jsonl.gz` | `92c4058fa8ce0a74dd05d8919cc664ebf8326e9d76303d2e67338969880e5fc6` |
| `runtime-gaps/runtime-gaps.json` | `f55cd3fdcdf95c6ed515f138d5a60e5286754440fdaa85a63c543c09126fbdea` |
| `retained-verify-full-v3.json` | `04d44b73e81982f846bfe8d81806db72ea669586b579ff22007dfd6f7d831297` |
| `canonical-plan-v3.json` | `195e11142592bb31290afcd8f10cefb90d2eba57170a5ae8b45a53cdc688ebfc` |
| `canonical-plan-byte-verified.json` | `9cde281141ccd6900118b1317f03cd3a0ae548864591373adfef14349b8f367b` |
| `canonical-candidates-byte-verified.ndjson.gz` | `d9effec2d39f8bb0d962ae04c7bdec855ae31230be4b247c861075cd0e95d0ad` |

The authoritative `build/units.json` hash remains
`62f2c8da5f0daa912abdf4576328706711c6561eef7f01c93a89cb71ad46fb6c`.
The gaps ledger binds the earlier **canonical-plan-v3**, not the later
byte-verified plan. The later candidate stream is separate evidence; recovery
does not silently substitute it into the original ledger's provenance.
Both canonical plans and the retained v3 receipt bind retained-manifest hash
`bc62a5fb2553431b1e0547d11f366e52efb73096ea8ceb206c556ae5740a53eb`.

Recovery streamed the complete v4 detail, rejected duplicate sites, checked its
150,165 rows and every class count against the bound plan, and reproduced every
exact-target/class occurrence group in the gaps ledger. This is a metadata
reconciliation, not a new image or retained-object comparison. The existing v3
receipt reports all 16 image probes passed, function/global-EH/original-parity
passes, 95 local EH diagnostics across 16 units, and runtime closure false.
The optional function index is absent; no index was fetched or reconstructed.

## Population evidence

| Input category | Data-site occurrences | Unique exact target VAs |
|---|---:|---:|
| `other-code` | 8,056 | 6,938 |
| `EH-interior-ambiguous` | 493 | 484 |
| Total | 8,549 | 7,422 |

All 7,422 target VAs fall in the plan's `.text` logical range; none falls in
`.bind`. Among the 6,938 other-code targets, 4,944 are in
`[0x00f10000, 0x00f30000)` and another 683 in
`[0x00f30000, 0x00f40000)`. Address concentration is a search-priority fact,
not a semantic label. Executable flags do not prove every target begins code,
nor rule out literals or tables in executable storage.

Fresh exact containment in retained-v3 `eh_sections` rows whose match flag is
true gives this narrower partition. Intervals use their recorded half-open
`start <= target < end` bounds; no nearest-address assignment is used.

| Category | Targets inside matching EH pieces | Their sites | Targets outside those pieces | Their sites |
|---|---:|---:|---:|---:|
| `other-code` | 1,006 | 1,006 | 5,932 | 7,050 |
| `EH-interior-ambiguous` | 484 | 493 | 0 | 0 |

Of the covered targets, 81 other-code and 15 ambiguous-EH targets have multiple
matching-piece rows. Rows can come from repeated recipes or overlapping
observations; they are not automatically distinct owners. Even a single row
does not establish a callable entry, parent-frame ABI or complete provider.
All 484 ambiguous targets remain ambiguous in the data plan. The piece join
adds useful exact evidence without repairing overlapping authoritative spans.
The 5,932 uncovered targets are unclassified by this join, not proven absent
from source or CRT libraries. These are target addresses, not inferred function
boundaries or a missing-source count.

Eight targets have exact recipe-symbol aliases. These are bindings, with no
selected recipe function entry or checked provider implied: `0x00aa7830`,
`0x00ecb3a8`, `0x00ec9907`, `0x00ecb562`, `0x008d0430`, `0x00ad7020`,
`0x00ec7944` and `0x00ec79a1`. The aliases include `_fread`, several conflicting
`fclose` spellings/signatures and `_ftell`. They are useful CRT/ABI leads; name
agreement alone cannot choose a library or normalize signatures.

## Concrete source and helper evidence

The complete later candidate stream has exactly one address-level intersection
with these 7,422 targets: `0x00aa7830`, which has 18 data-site occurrences.
Its sole candidate is `??1ScaledVec6@@QAE@XZ`, recipe
`2746-7143c9beb8bf3624`, source `src/staging/blk_00b20000_od.cpp`, native section
49/value 0, COMDAT selection `any`. The candidate explicitly says
`METADATA_BOUND_UNVERIFIED_BODY`, `hash_bound_function_byte_verified=false`,
ABI/runtime closure false and provider unselected. The source destructor calls
`FUN_00aa7830_holder::FUN_00aa7830`; its spelling does not prove that wrapper is
the complete original destructor or a suitable runtime provider. Exact-address
candidate absence for the remaining targets does not imply missing bodies:
inferred EH mappings were deliberately not consumed by canonical planning.

A source correction matters when interpreting generated initializers.
`src/generated/global_object_initializers.cpp` annotates the declaration
`GlobalObject_00a2e180 g_011c32f0;` with `@fnv 0x00f35420`. That address denotes
the compiler-generated dynamic initializer, not a constructor argument or a
data address. The constructor at `0x00a2e180`, in
`src/gamebryo2.2/corelibs/nianimation/bsmultitargettreadtransfcontroller.cpp`,
increments `DAT_011f36a0` and conditionally calls `FUN_00aa2080` with two other
global addresses. This is direct source-use evidence for shared reference-count
and registration dependencies. It does not prove a four-byte generated storage
placeholder is the real type or establish the initializer's entire lifetime
graph. Generic padding changes cannot resolve these contracts.

## Preserved observations from before the crash

The previous worker reported exactly 64 deterministic ledger-target samples,
each bounded to at most 96 bytes and 32 decoded instructions, after all 16
existing fingerprint probes passed. It reported 43 frame-relative cleanup or
call/exit shapes, three this-adjustment tails, 12 unrecognized targets and other
categories. No NUL-terminated ASCII or UTF-16 candidate was reported in that
sample. Those observations were handed off before the crash, but neither the
sample-selection algorithm nor a per-target receipt was recovered from the
bounded known report locations. They were **not independently reproduced** by
this recovery and are not a population classification or a proof of no literals.
No replacement sample or invented sample indices were introduced.

The prior worker also reported a strong CRT lead at `0x00ec60fa` (1,013 sites,
freshly confirmed as the highest-frequency ledger target): both native VC2008
SP1 and RTM `libcmt.lib` `__purecall` implementations had 42-byte sections whose
non-relocation bytes agreed within an already sampled 96-byte window. Five
relocations named `___pPurecall`, `__decode_pointer`, `__NMSG_WRITE`,
`__set_abort_behavior` and `_abort`. This library comparison is a preserved
pre-crash observation, not a freshly recovered hash-bound provider receipt.
It supports a targeted CRT ownership task; it neither approves substituting
one CRT version nor proves `_purecall` policy/state compatibility. No library
member bytes, game bytes or disassembly are included here.

## Proposed implementation queue

These are concrete next assignments for coordinator review. No code generation,
fixup application, full link or runtime launch is authorized by this audit.

1. **Persist an EH ownership join.** Add a bounded metadata-only consumer of the
   exact ledger, v3 receipt, recipe and retained manifest identities. Emit every
   exact matching-piece candidate with recipe/object/section and parent evidence,
   distinguishing byte coverage, local diagnostics and runtime eligibility.
   Retain all alternatives; reject stale hashes and conflicting mappings. Tests
   should exercise overlapping pieces, repeated observations, interior targets,
   diagnostic-bearing units and absent-index behavior. Expected native audit
   totals are the 1,006/484 partition above, with zero providers auto-selected.
2. **Close one EH component.** Use the separately assigned
   [EH closure pilot](EH-CLOSURE-PILOT.md) to identify a parent, handler,
   cleanup/catch/unwind fragments, associated metadata, relocations and every
   helper/data/CRT dependency. Prove each selected section and offset, parent
   frame contract and COMDAT retention before rewriting or linking. A source
   return or destructor stub cannot replace a frame-dependent fragment.
3. **Establish the `__purecall` provider contract.** Revalidate the reported
   native library-member identity with library hashes and relocation-aware
   comparison; select one CRT owner for hook state, pointer encoding, abort
   policy and startup. Check all five dependencies and calling convention.
   A synthetic source-built virtual-call failure fixture can test the selected
   runtime policy without invoking game code. Keep original-address identity
   evidence separate from behavioral runtime selection.
4. **Resolve the `0x00aa7830` candidate.** Check the actual candidate body and
   its call-through dependency against an explicit bounded identity/ABI
   contract, rather than treating its containing object's successful functions
   as proof. Reject an unresolved recursive alias or wrapper mismatch. Record
   the relevant vtable/cleanup uses before deciding ownership.
5. **Expand classification by evidenced families.** Start with exact metadata
   and source-use joins for the remaining 5,932 targets. Introduce an explicit
   unknown state, full population accounting and per-family evidence receipts.
   Use separately assigned bounded inspection only where metadata is
   insufficient; any code/literal decision needs cross-source evidence,
   instruction boundaries and use context. Never manufacture thousands of
   stand-alone functions from target addresses or promote the 64-target sample
   into a whole-population result.
6. **Gate data materialization on component closure.** Retain every semantic
   fixup as unapproved until its storage owner, field representation, target
   provider/addend and lifetime are reviewed. Start with the original synthetic
   fixture proposed in the data strategy, then one closed game-data component.
   Generated initializer retention/order and fresh CRT/TLS state are separate
   obligations. No original executable pointer may survive as a runtime fallback.

This audit's verification was complete input-hash/detail reconciliation,
population-range and exact EH-piece joins, a complete later-candidate stream
join, and bounded reading of the named source owners. It created only this
documentation file. No new byte match, function implementation, executable,
game startup, menu, gameplay or save/load result is claimed.
