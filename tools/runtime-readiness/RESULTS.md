# Runtime readiness: delivery results (2026-11-03)

**No rebuilt game exists. No gameplay or launch test was run. Every step in the
smoke-test template is `not-run`.** Nothing was launched, and no game
installation, Steam, user configuration or game binary was accessed.

## Attribution

- Checker, observed inventory, examples, README, checker tests and review
  fixes: Claude Opus 5.5 (`claude-opus-5-5`) in Claude Code (desktop app).
- Smoke-test template (`SMOKE-TEST-TEMPLATE.md`, `smoke-test-template.json`,
  `smoke_template.py`, `tests/runtime-readiness/test_smoke_template.py`):
  drafted by a Claude Code subagent launched with the `sonnet` model alias
  (requested as Sonnet 5.5; the exact version behind the alias was not
  independently confirmed), then reviewed and patched by the Opus session.
- Independent read-only audit against the handoff: a second subagent under the
  same `sonnet` alias. Its findings (edge-input crashes, `--out` guards,
  intermediate link following, UNC/device paths, text encoding, attested exit
  code, isolation gaps, validator path leaks) were fixed and covered by
  `tests/runtime-readiness/test_readiness_regressions.py`.

Built in a standalone folder that holds only these two directories, from the
source-only packet; it was not run inside a checkout of the active branch.

## Test results

```powershell
python -m unittest discover -s tests/runtime-readiness -p "test_*.py" -v
```

Python 3.12.10 on Windows 11: `Ran 107 tests ... OK` (checker 49, regressions
25, smoke template 33). All fixtures are synthetic files in temporary
directories. Not run on Linux, macOS or under Wine.

```powershell
python tools/runtime-readiness/smoke_template.py validate tools/runtime-readiness/smoke-test-template.json --template
# OK: record is valid (unexecuted template)   exit 0

python tools/runtime-readiness/readiness_check.py
# Verdict: UNKNOWN (launch authorized: no); 16 necessary items unknown   exit 1
```

## Unresolved assumptions for the coordinator

1. **Contract list.** The 11 unobservable contracts (build gates, x86 GUI
   platform, rebuilt dependency set, DLL versions/exports, transitive/dynamic
   loads, loader search policy, resource identity, config/save paths, working
   directory/asset lookup, Data/add-ons/localization, Steam/ownership
   integration) are my reading of the handoff and runtime inventory.
2. **Attestations.** A user attestation with provenance turns a contract
   `present` with basis `user-attested`. The best possible verdict is
   `attested-pending-review` (exit 4). No verdict exits 0. If attestations
   should never change status, drop them in `check()`.
3. **Policy blocks I chose.** A rebuilt executable inside the installation is
   blocked, and so is a working directory that overlaps a protected path.
4. **Lexical overlap.** Location overlap checks do not resolve links, so a link
   inside a supplied path could hide an overlap. File identity for "is this the
   original executable" uses `lstat`, which does not follow links. Link and
   junction handling is tested with mocked `lstat` results, not real links,
   because the handoff forbids creating junctions.
5. **Toolchain report.** Accepted only as `schema_version` 1 with exactly
   `sp1`/`rtm`/`vc8` entries that each have a boolean `ready`. This matches the
   packet's `toolchain.py`, which does not document a stable schema. Reports
   from `recipe_audit.py` and `build_and_match.py` are not consumed, because
   their formats were not in the packet.
6. **Observed inventory.** The names, sizes and import counts come from
   `GAME-RUNTIME-ENVIRONMENT.md`. Add-on file names are derived from its prose.
   The original executable's SHA-256 and the import-plan hash are deliberately
   not copied.
7. **Bounds.** Requirement paths go at most two levels deep. The checker checks
   sizes only and never hashes. The isolated-profile count stops at 1,000.
8. **Redaction is heuristic.** Absolute-looking paths in free text are
   replaced. Relative paths such as `..\..\Users\x` and unexpanded variables
   such as `%USERPROFILE%` pass through.
9. **Template choices.** I added `<application-directory>` and
   `<working-directory>` placeholders. Step order is enforced. Hashing the
   original executable and backing up existing saves are manual steps for the
   owner during a future approved test.

## Integration review after Claude delivery

The source attribution above describes the submitted archive; subsequent fixes were made by Codex after independent review. Ancestor symlink/reparse checks now guard metadata probes, JSON input and output parents; existing output overwrite is disabled and creation is exclusive. An unknown DLL candidate remains unknown. Diagnostics no longer echo untrusted manifest keys or smoke-template object keys. Filesystem path checks remain non-atomic against concurrent replacement; use a trusted, stable local tree. The original 107-test result above is the submitter's historical result; the coordinator records the separate post-fix validation.
