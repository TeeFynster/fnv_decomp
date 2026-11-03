# Finite all-current Python supervisor

`tools/rebuild/bulk_code_supervisor.py` launches exactly one invocation of the
frozen bulk producer, in `all-current` mode only. It contains no COFF,
namespace, selection, provider or archive-reader implementation. The producer
SHA-256 remains
`4e6d697c1881c56c4c3f6a84788df6e0e2617b284d8e0226805828829bce49ed`.
No actual all-current production or native operation has run during this
supervisor's source/test development.

The all-current branch/readiness review has been accepted independently; this
new supervisor still requires its exact source review and a separate root
authorization for the actual guarded attempt. It does not expand eligibility,
enable certificates, retry failures or convert a partial child result to full
success. See [the readiness plan](ALL-CURRENT-CODE-POOL-READINESS.md) for the
16,859 requested roots, 1,429 candidate-containing recipes and complete 68,657
historical accounting scope.

## One authorization, one owned child

Use one independently authored all-current phase receipt for both components.
The existing child gate still requires `phase="bulk-code-pool-all-current-emission"`,
`mode="all-current"`, the actual review/root booleans, proposal hash, exactly
the four child `source_sha256` entries and empty certificate inputs. Additional
supervisor fields are:

- `supervisor_source_review_pass=true`;
- `supervisor_source_sha256` covering exactly this supervisor, its test and
  this document;
- `python_executable_sha256` for the actual existing Python interpreter;
- `supervision_limits` exactly equal to the constants below.

This is a recorded operational decision, not an authentication mechanism.
No receipt asserting a root go is created by the supervisor. Its CLI accepts
only the thirteen existing named input paths, review path/hash and a fresh
private `--run-dir`; it accepts no arbitrary executable, command, mode or
producer override. The child command is the pinned interpreter with `-E -s -B`,
the pinned producer script, the exact named inputs, `--mode all-current` and
the same review receipt. It uses no shell and invokes no native compiler,
linker, reader or game executable.

The new run directory must lie below ignored `build/rebuild/` and must not
exist. The child gets its own initially absent `production/` directory. Review
and input paths cannot be inside the new run directory. Before launch the
supervisor pins its own three sources, the child's four sources, the review
and interpreter, saves exact supervisor source snapshots and checks initial
free space. The child preserves its own source snapshots and performs all
existing source/object/proof/reference/namespace/coverage verification itself.

## Sampled resource and stop controls

| Threshold | Value |
| --- | ---: |
| Child wall-time abort threshold | 1,800 seconds |
| Poll interval | 2 seconds |
| Working-set abort, including observed OS peak | 1.5 GiB |
| Private committed abort | 2 GiB |
| Child spool abort | 128 MiB |
| Total recognized new-output abort | 512 MiB |
| Child output-log abort | 16 MiB |
| Minimum free space before launch | 2 GiB |
| Free-space abort while monitoring | Below 1 GiB |

These are sampled abort controls, **not hard real-time, memory, filesystem or
Windows job-object quotas**. A process can exceed a threshold between polls;
filesystem/memory query time and termination wait can extend the observed
deadline. The timeout controls the monitored child interval, not a claimed
hard bound on preflight/final hash verification. No full-run duration or memory
completion promise follows from the modest input sizes. In particular, the
unchanged comparator scans object symbols for each requested function and the
6,925-root recipe can be CPU intensive.

Memory is queried only through the owned `Popen` process handle using the
Windows process-memory API; no process enumeration, PID search or unrelated
worker termination is performed. Disk accounting walks only the one new child
output directory at its top level, plus exact known child/supervisor snapshot
paths. It never recursively scans old work/archive/checkpoint stores. Unexpected
directories/reparse paths, path escapes, invalid samples or monitoring errors
fail closed. A 4,096-entry top-level safety bound exceeds the current maximum
1,429 shards plus expected files. Unrelated global disk pressure can trigger
the free-space abort, intentionally protecting other work.

The operator can create `<run-dir>/stop.request` to request a stop. The
supervisor never removes it and never starts another child. On any abort it
kills/waits for only its owned child, with a ten-second termination wait. The
frozen child launches no descendant tools. If termination itself fails, the
receipt preserves that error for explicit reconciliation. No automatic
retry, spool truncation, resume or new attempt is performed.

## Receipts and interrupted work

New private files are `supervisor-progress.jsonl`, `child-output.log`, exact
`supervisor-snapshots/`, the child `production/` tree and
`supervisor-receipt.json`. Progress is fsynced at preflight, child launch and
each sample; it records the exact command/hash and owned PID. The terminal
receipt records resource maxima/minimum free space, child return status,
source/review/interpreter hashes, errors, limit configuration and whether any
late child receipt is unaccepted.

On a normal zero child exit, the supervisor requires a valid terminal
all-current child receipt tied to the same phase review, hashes that receipt
and verifies its exact spool, member ledger, coverage, union and shard hashes.
It does not repeat the child's COFF or selection logic. Child `complete`
becomes supervisor `completed`; child `incomplete` becomes
`completed-incomplete`, preserving conservative union quarantine. Either
result still needs independent artifact/outcome review before acceptance.

An abort never returns an accepted `child_receipt`, even if a complete-looking
child file exists. Its hash is recorded only as unaccepted evidence when safe
and within a bounded receipt size. A corrupt/oversized log or receipt may have
its hash omitted rather than following an escaping/reparse path or performing
unbounded hashing. Existing run directories are rejected without modifying
them. Source drift after a successful child invalidates supervision. Partial
artifacts, journals or the child receipt alone are not a successful guarded run.

An ordinary handled preflight/monitor/child error gets a complete abort
receipt in this owned new directory. Power loss, forced supervisor termination
or a failed filesystem write cannot guarantee a terminal receipt; reconcile
the saved exact command/PID/progress before any manual action. The supervisor
does not claim OS orphan prevention or transactional multi-file publication.

## Source/test status and next action

Fourteen authored synthetic tests pass. They use fake owned processes and
temporary authored files, never the actual producer or a native tool. They
exercise each resource threshold, sampled wall/peak behavior, operator stop,
initial free-space refusal, exact command/gate/source pins, path confinement,
monitor failures, owned-child termination, nonzero/wrong-mode child results,
source drift, partial-result distinction, artifact/receipt hash binding,
exclusive directories and complete abort records.

```text
python -m unittest discover -s tests/rebuild -p test_bulk_code_supervisor.py
```

After independent acceptance of these exact three files, root may authorize
one guarded all-current Python attempt with the single reviewed phase receipt.
No further theoretical collector or duplicate producer is needed. Native
archive inspection remains a later separate root gate for the actual produced
shards; executable linking, provider/ABI adoption and Game execution remain
outside this supervisor.
