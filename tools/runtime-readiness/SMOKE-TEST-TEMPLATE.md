# Runtime Smoke-Test Template (manual, unexecuted)

> **NOT RUN. NO LAUNCH AUTHORIZED.**
> This is a template for a future, separately approved build. Nothing in this
> repository authorizes launching any executable. Every result below is
> `not-run` and must stay `not-run` until the step is actually performed.

## Purpose

A reproducible, manual checklist for the first gameplay smoke test of a future
privately rebuilt x86 Windows GUI executable (prospective, unverified). It
records build identity, platform, owned inputs, isolated config/saves,
arguments and working directory, and then, in order: startup and clean exit,
a responsive menu, and only later gameplay (new game, movement, render, audio),
save/reload, load from menu, and a final clean exit. Each step captures
expected and observed result, `pass`/`fail`/`blocked`/`not-run`, evidence
location and cleanup/rollback.

Files: `smoke-test-template.json` (the record), `smoke_template.py` (read-only
validator), this document.

## Safety rules

- Do not launch anything from this repository or on the strength of this
  document. Launch requires separate written approval referenced in the record.
- The original game executable stays unchanged and is **not** a runtime
  provider. Reference it only to hash it before and after; that hashing is a
  manual step by the owner during an approved test, never done by the
  readiness checker, which reads metadata only.
- No Steam stub, protection bypass, credential handling, junctions or asset
  copying. Game data is referenced in place; the project grants no licence.
- Never overwrite existing user configuration or saves. Back them up by
  copying, run only against an isolated, empty config/saves location, and
  verify afterwards.
- Never put private absolute paths, game bytes, assets or credentials in the
  record. Use only the placeholders below; resolved private locations are kept
  outside public artifacts.
- Record real model/tool attribution of who filled the record
  (`record.prepared_by`); do not infer it.
- Keep the application directory and working directory as separate fields.

Placeholders: `<private-built-exe>`, `<owned-game-data>`,
`<isolated-config-and-saves>`, `<verified-dll-providers>`, plus
`<application-directory>` and `<working-directory>` for the two launch fields.

## Gates that must be closed first

All of these must be closed, and the readiness report from the separate
readiness checker reviewed, before any step is performed:

1. Source link gate
2. CRT/TLS gate
3. ABI gate
4. Resource gate
5. Provider gate (`<verified-dll-providers>` vetted; original executable not a provider)
6. Written approval of this exact build for testing, referenced in
   `record.approval_reference`

## Record fields

| Section | Fields |
| --- | --- |
| `record` | `record_id`, `prepared_by` (`name`, `model_or_tool_attribution`), `date`, `approval_reference` |
| `build_identity` | `source_commit`, `source_branch`, `build_recipe_or_command_reference`, `executable_placeholder`, `executable_sha256`, `executable_size_bytes`, `toolchain_report_reference`, `readiness_report_reference` |
| `platform` | `target`, `os_name_version`, `cpu_arch`, `gpu_and_driver`, `audio_device`, `display_mode` |
| `owned_inputs` | `installation_placeholder`, `installation_version`, `original_executable_left_unchanged_verified`, `data_files_used`, `addons_and_localization`, `access_arrangement` |
| `isolation` | `isolated_config_and_saves_placeholder`, `existing_user_config_and_saves_backed_up`, `backup_location_reference`, `existing_user_config_and_saves_untouched_verified`, `dll_provider_placeholder`, `dll_search_policy` |
| `launch` | `application_directory_placeholder`, `working_directory_placeholder`, `arguments`, `environment_changes`, `expected_reads`, `expected_writes` |
| `steps` | ordered list (below) |
| `summary` | `overall_result`, `blocking_issues`, `follow_ups` |

## How to use

1. Copy the JSON to a PRIVATE location outside the repository (do not fill it
   in place, and never commit a filled record):
   `python tools/runtime-readiness/smoke_template.py print-template > <private-copy>.json`
   (the redirect is done by your shell; the tool itself never writes files).
2. Fill it in the private copy, step by step, only as each step is really
   performed. Change a result from `not-run` only after performing the step.
3. `pass` and `fail` need non-empty `observed` and `evidence_location`;
   `blocked` needs `notes` explaining the blocker; a step cannot be `pass` if a
   step it depends on is not `pass`; `summary.overall_result` is `pass` only
   when every step is `pass`.
4. Validate (exit 0 valid, 1 problems, 2 usage/IO/JSON error; files over 1 MiB
   are refused):
   `python tools/runtime-readiness/smoke_template.py validate <private-copy>.json`
5. Check that the repository template itself is still unexecuted:
   `python tools/runtime-readiness/smoke_template.py validate tools/runtime-readiness/smoke-test-template.json --template`

The validator also flags strings that look like private absolute paths
(drive letters, UNC, `/home/`, `/Users/`, `/mnt/`).

## Steps

Order matters: later steps depend on earlier ones. Every step ships with
observed blank, result `not-run`, evidence location blank.

| ID | Depends on | Preconditions | Procedure | Expected | Observed | Result | Evidence location | Cleanup / rollback |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| `preflight-record-identity` | none | Gates closed; readiness report reviewed; approval referenced | Copy template privately; fill identity, attribution, platform, owned inputs; hash the private build read-only; validate | Placeholders-only record; validator clean; nothing launched | | `not-run` | | No state changed; relocate/delete stray copies |
| `preflight-backup-and-isolate` | `preflight-record-identity` | Private locations known (not recorded) | Copy existing config/saves to private backup; prepare empty isolated location; record isolation mechanism; baseline hashes; confirm provider policy | Verified backup; isolated location empty and separate | | `not-run` | | Restore anything changed from backup |
| `launch-to-window` | `preflight-backup-and-isolate` | Approval recorded; time limit chosen | Start the built exe once with recorded app dir, working dir, args; watch for a window; no interaction | Process starts, window appears, no loader errors, writes only in isolated location | | `not-run` | | End only the test process by normal means; reset isolated profile |
| `clean-exit-from-startup` | `launch-to-window` | Process running | Exit via normal close path; record exit code | Clean exit in time; nothing lingering | | `not-run` | | Reset isolated profile baseline |
| `menu-responsive` | `clean-exit-from-startup` | Relaunch as recorded | Reach main menu; move focus; open/back out of sub-menu | Menu renders and responds | | `not-run` | | Exit cleanly; reset isolated profile if settings written |
| `new-game` | `menu-responsive` | At main menu | Start New Game to controllable state | Reaches control without crash | | `not-run` | | Reset isolated profile baseline |
| `movement` | `new-game` | Player controllable | Walk, strafe, turn, look, jump | Smooth, correct response | | `not-run` | | Exit normally if unstable |
| `render` | `new-game` | Display mode recorded | Inspect world and UI; screenshots | No severe corruption or black frames | | `not-run` | | Copy evidence out before profile cleanup |
| `audio` | `new-game` | Audio device recorded | Listen for music/effects/speech | Plays without stutter or crash | | `not-run` | | Restore volume/device settings |
| `save-game` | `movement`, `render`, `audio` | Saves target isolated location | Save with unique name in the in-game menu; confirm file only in isolated location | One new save, only in isolated location | | `not-run` | | If written elsewhere: stop, restore from backup |
| `reload-save` | `save-game` | Save created in this run | Alter state; load that save; compare | State matches saved state | | `not-run` | | Load no other save |
| `load-game-from-menu` | `reload-save` | Can reach main menu | Main menu Load Game of the save from this run | Loads with matching state | | `not-run` | | Keep isolated profile intact |
| `clean-exit` | `load-game-from-menu` | Game running | Exit via menu/close; record exit code; list new files | Clean exit; only expected files | | `not-run` | | End only test process if hung |
| `postflight-verify-untouched` | `clean-exit` | Baselines exist | Re-hash original exe; compare user config/saves to backup; list isolated profile (names, sizes, hashes) | Original and user data unchanged | | `not-run` | | Restore from backup; record fail |
| `cleanup-rollback` | `postflight-verify-untouched` | Retention policy decided | Restore changes; delete or retain isolated profile per policy; remove temp files | State matches pre-test | | `not-run` | | Stop and report if restoration fails |

The authoritative step wording (full procedure lists, preconditions and
rollback text) is in `smoke-test-template.json`.

## Summary

`summary.overall_result`: `not-run`. `blocking_issues`: none recorded.
`follow_ups`: none recorded. No test has been performed.
