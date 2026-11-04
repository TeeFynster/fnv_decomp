# One source-built game TLS getter

This fixed-scope component supports only `GetTlsField()` at original symbolic
identity `0x00404f50`: recipe `0781-3b6aac24065e157e`, native section 56/value zero,
26 bytes, actual decorated name `?GetTlsField@@YAHXZ`. The source is
`src/fallout_shared/magic/effectitem.cpp:557-565`, with ABI `int __cdecl(void)`.
It reads one thread-local int and has no calls, class ABI, assets or other game
state. No existing TLS/scalar/binding tool or source is changed.

The exact retained object hash is
`ab8a41852bfdda260348209f47ddc6ed125fd68a5228216f2b6656745cc15310`;
source hash is
`716b704c5f9e3893014f9458ad8020ddf47c1fdacd628fac62cf3a8fd6c96358`.
The fixed recipe, approved selection-v2, complete retained-v3 proof, original
SP1 producer identity/flags and owned reference are pinned and rechecked.
The optional function index must remain absent. The unchanged original image
gate and comparator run before extraction and again on the extracted object.
The original field's source initializer 59 is evidence, not adopted runtime
initialization. No original PE code or TLS payload becomes generated storage.

## Kept code, external field and exact directive policy

The getter keeps its source-built 26-byte code payload, no-duplicates COMDAT,
16-byte code alignment, read/execute flags, section auxiliary and SafeSEH feature
metadata. Its only runtime edges are:

| Field | Kind / addend | Runtime meaning |
|---|---|---|
| +4 | DIR32 / 0, `__tls_index` | New normal CRT loader-index cell |
| +11 | DIR32 / 0, `__tls_array` | Normal CRT absolute constant 44, not a process VA or HIGHLOW |
| +20 | SECREL / 0, `?DAT_tls_field@@3HA` | Symbolic field view resolving to module offset `0x2b4` |

The old field definition at native source `.tls$` offset **`0x2b8`** becomes an
undefined external field symbol. The original 700-byte TLS contribution is
omitted entirely. No old source placement or original address is retained as a
runtime fallback. Unknown edges/addends, aliases, children, line/auxiliary records,
producer features or source/proof drift reject extraction.

The pinned original directive list contains these two unrelated tokens:

```text
/alternatename:?EffectSetting_GetArchetype@@YIHPAUEffectSetting@@@Z=?GetArchetype@EffectSetting@@QAEHXZ
/alternatename:?EffectSetting_GetArchetype@@YIHAAVEffectSetting@@@Z=?GetArchetype@EffectSetting@@QAEHXZ
```

Only those exact two tokens are dropped, with a receipt ledger. Original and
output default directives are exactly `/DEFAULTLIB:"LIBCMT"` and
`/DEFAULTLIB:"OLDNAMES"`. A changed or additional token fails; there is no generic
alias-ignore rule. Neither alias endpoint may belong to the retained getter
closure, authored TLS/CRT infrastructure or actual fresh caller/storage symbols.
The original input/directive policy is checked before any fresh compilation;
actual caller-symbol exclusion is checked after compilation before publication.

## Authored storage interior view

The new caller reuses the unchanged reviewed `tls_owner_fixture.hpp`,
`tls_owner_storage.cpp` and `tls_owner_callback.cpp`. Normal CRT remains the
sole index/directory/marker/callback-sentinel owner. The independently reviewed
original TLS fixture's exact preparation, approval and execution receipts and
protected inputs are checked as mechanism evidence; they are not rerun.

A fresh source-built storage object is copied privately. The writer appends
one external COFF symbol named `?DAT_tls_field@@3HA` at the author's declared
`FixtureTlsStorage::context` member: owning `.tls$` section, value `0x2b0`, extent
four bytes and alignment four. The source owner is the full authored 704-byte
POD, physically alignment four, with source initializer **37**. The alias is not
an absolute symbol or numeric process pointer. Every original payload byte,
section flag, relocation, existing symbol and auxiliary record remains unchanged;
only symbol-count/string-table bookkeeping and the new symbolic record are added.
Strict reparse checks that exact transformation and rejects collisions.

The linked image must prove owner +4 after the normal one-byte marker and three
alignment bytes, hence context at module +`0x2b4`. The field's template-image map
address must equal owner plus the source member offset; that map identity is not
a shared per-process variable. The getter's SECREL operand must be numeric
`0x2b4`, never `0x2b8`, `0x2b0` or the template-image VA. The 708-byte authored
template, excluded end marker and 709-byte logical section retain the reviewed
fixture contract. No complete game TLS layout or initialization is claimed.

## Original caller and stage gates

`runtime/probes/game_tls_probe.cpp` declares and directly calls the actual
selected getter. It supplies no game function implementation. Main and two
simultaneously alive workers each test the initial synthetic context 37, write
independent values (main 103; workers 201/202), and test them again. Each phase
repeats 256 getter calls: nine phases, 2,304 expected calls per layout. Game calls
begin in `main` and occur in the two worker procedures; original loader callbacks
and the constructor remain unchanged in their source-only TLS behavior.
The caller also retains full initial-state/alias checks, distinct blocks,
consistent indices, main/caller preservation and normal callback/CRT/final
own-handle termination receipts. Expectations are not changed to fit results.

Preparation uses exact SP1 and the reviewed header/backend/library/API/OS gates
from the original TLS driver without changing that driver. It binds all actual
included headers before object compilation, confirms identical include sets and
hashes afterward, proves resolved library paths, permits only reviewed named
imports and binds actual on-disk SysWOW64 export/forwarder identities. Historical
OS evidence is not a substitute for the new preparation's fresh OS evidence;
in-memory KnownDLL and full transitive loader identities remain outside scope.

Fresh normal/moved layouts must preserve every nonrelocated getter byte, bind
its three operands correctly, expose exactly one game function, prove the
symbolic field view and unchanged authored storage, and retain normal CRT,
SafeSEH, callbacks, imports and protections. Separate extraction and storage-view
receipts distinguish the two transformations. Outputs are new and exclusive;
input collisions or late drift fail closed.

The two omitted directives also have a conservative syntactic library gate:
all three exact long decorated endpoint names must be absent across every byte
of all four actual resolved, hash-bound libraries, including unselected members.
The driver bounds each archive to 32 MiB and checks ordinary native COFF/import
member header forms, including the observed architecture-neutral directive-only
members. Opaque, compressed, LTCG or other unsupported forms fail. These ordinary
long COFF/string-table and linker directive names occur contiguously as ASCII;
weak targets refer to those same named symbol records. Any occurrence rejects,
even if unused. The identities and absence are checked before and after each
link, and retained in each variant receipt. This is deliberately stronger than
checking map publics; it does not claim complete selected-member enumeration or
dynamic runtime closure. Existing fresh-object, retained-closure and linked-map
endpoint exclusions remain required, as do the exact allowed library searches.

The unique caller source REL32 relocation is independently joined to its unique
`main.obj` function map owner. Its actual linked signed displacement must resolve
exactly to the selected getter map address. Nonzero source addends, unsupported
anchors, writable/nonexecutable placement, or overlapping HIGHLOW fields fail.
Masking a relocation during payload comparison cannot substitute for this check.

Independent source review precedes any compiler call. Preparation runs neither
executable. Exact independent native artifact review and a separate root go
precede bounded execution; all protected files and approval/preparation hashes
are rechecked before and after each own child. Each must exit zero with empty
stderr and the exact caller receipt followed by the original final-detach
receipt. Failure/timeout is recorded without a state or placement fallback.

```text
python tools/rebuild/game_tls_component.py prepare --doctor <existing-doctor.json> --manifest <immutable-manifest.json> --selection <approved-selection-v2.json> --verification <retained-v3.json> --image <owned-plaintext-reference> --out <new-private-directory>
python tools/rebuild/game_tls_component.py execute --prepare <prepare.json> --review <independent-review.json> --review-sha256 <exact-hash> --receipt <new-execution.json>
```

Private artifacts remain ignored under `build/rebuild/`. Hash-bound observed
commands/source/objects are not cryptographic compiler-causality proof. This
single getter is separate from general TLS aliases/provider adoption, original
game initialization, Havok's dynamic slot, game startup or gameplay.

## Current validation

Twenty-six focused offline tests pass: fourteen extraction/view tests and twelve
component operand/receipt tests. They cover exact directive removal, unknown
tokens/auxiliary/features/children, code and relocation drift, source field
externalization, wrong old/native/source/VA offsets, symbolic view extent and
collision, immutable storage, stale proof/context/artifacts, complete review,
thread/caller/getter counts, final detach, redirected actual call operands,
hidden library endpoint names, opaque/stale library inputs and own-child timeout. They compile
or execute nothing and use invented COFF/PE payloads rather than game bytes.

On November 3, 2026, source review and independent native artifact review passed.
The exact source-built getter passed the unchanged comparator and all 16 image
probes before extraction and on the extracted component. Both prepared layouts
retained the 26-byte body, symbolic storage view, module offset `0x2b4`, normal
CRT index/absolute-44 mechanism, and actual caller target. Independent review
checked the maps, protections, imports, OS identities and all protected hashes.

Each reviewed layout then ran exactly once. Both exited zero with empty stderr
and the exact two expected records. Each made 2,304 getter calls across nine
phases on the main thread and two workers; all three initial-value and alias
checks passed. The workers had distinct TLS blocks, their independent writes
remained isolated, and the main thread's state was preserved. Each observed one
CRT constructor and destructor, five validated callback events and a successful
final process-detach record. The observed owner/flag/context module offsets were
`4`, `0x268` and `0x2b4`. Independent outcome reconciliation found zero drift in
all 166 protected inputs, 29 artifacts and three OS files.

The private immutable receipt identities are:

| Receipt | SHA256 |
|---|---|
| Prepare | `e99f7b2d9373d24b5da0675c1cf8dbcce33eff867301fc1b60d336e2e44d9a30` |
| Independent review | `76a95a8934a95bd6089fea74e102dc8e5af611f4a3ec0aa021f30f0eb4d439d2` |
| Execution | `dc3c1caf24e0302efcbc3ead801bb5649f8fff5e53cef3fba04a8b48f72ccc61` |

The reviewed document version was preserved privately before this factual
post-run update. All five implementation/test/caller files retain their reviewed
hashes. No native build or execution was repeated for documentation. This proves
one source-built game getter reading an authored TLS allocation with synthetic
initialization and independent thread state. It adopts neither original game
TLS initialization nor a general game TLS provider, and establishes no game
startup or gameplay result.
