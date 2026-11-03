# Rebuild work and ownership

Current checkpoint: `8fcc7535729f84c85bf0187dbd1eeaa11d23b344`. The next wave is uncommitted. The root coordinator integrates work and review; owners edit only their assigned files. No full game link, provider closure or runtime has been established.

| Work | Owner / independent review | Current state and next gate |
|---|---|---|
| Startup host | `/root/rebuild_startup_host` / `/root/rebuild_startup_review` | Native compile-only result accepted; no remap, executable link or execution. |
| Entry dependencies and projection | `/root/rebuild_entry_dependencies` / `/root/rebuild_dependency_review`; projection `/root/rebuild_gaps_recovery` | The reviewed V6 CRT diagnostic LINK failed with 273 unresolved groups / 284 occurrences; four groups disappeared from V5 and none were added. No executable was produced or run; no completed application link. |
| DATA arena | `/root/rebuild_data_fixture` / `/root/rebuild_tls_component_review` | Native read-only review accepted the whole 255,676-byte DATA projection with 13,869 relocations and 6,379 demands. The provider bridge implementation is partial and untested; no tests, documentation, freeze or application exist. Runtime selection remains false. |
| Import projection | `/root/rebuild_import_projection` / independent review | Nine-export KERNEL32 replacement passed independent native metadata conformance. Alias, ABI and runtime adoption remain unapproved. |
| All-current CODE | `/root/rebuild_code_pool` / `/root/rebuild_function_selection` | Prepared ordinary exports total 14,329 across separately reviewed bounded production; serialization is not provider, ABI or runtime readiness. Further native conformance is under review. |
| Finite union-reference production | `/root/rebuild_gaps_recovery` / independent outcome review | Accepted Python production covers 185 recipes and 1,372 roots; fresh before/after matches were reconciled. Supplemental native metadata conformance passed; ABI, provider and runtime approval remain false. The three Box roots are included in the 1,372. |
| Expanded EH | `/root/rebuild_symbol_binding` and `/root/rebuild_eh_recovery` | Independently reviewed IOTask EH projection preserves the ordinary match and 11 original targets/addends; both 8-byte and 27-byte EH pieces match and seven CODE/DATA/CRT references remain unresolved. Provider, ABI, link and runtime flags remain false; no native or game execution. |
| Entry relocation batch | `/root/rebuild_entry_relocation_repair` / independent review | V1 first four translation units: 190 rows, 11 fields passed; fifth: 147 of 148 rows matched after `$SG7466` to `$SG7468` renumbering. Source fix is under review; the oracle remains unchanged. |
| DATA provider bridge | `/root/rebuild_data_fixture` | `data_provider_bridge.py` and provider-bridge-v1 policy are partial and untested. The subagent continuation was blocked by safety systems for “Potentially unintended activity”; no specific blocked action or tool call is visible. The last visible successful `apply_patch` concerned strict object handling. Root is not retrying or rerouting blocked writes; previously accepted artifacts remain unchanged. |
| Independent follow-on work | Registry, CRT, union driver and diagnostic owners | Supplemental native conformance passed after an offline saved-log decoder correction, without replaying native calls. The non-executable CRT table observation and registration plan were independently reviewed; runtime order and provider approvals remain open. No gameplay build. |
| Shared documentation | `/root/rebuild_docs_recovery` | Reorganizing current guidance; phase evidence and prior shared text remain in [evidence history](EVIDENCE-HISTORY.md). |

Earlier scoped work, receipts and canonical owner identities are preserved in [evidence history](EVIDENCE-HISTORY.md) and the linked phase documents. Current untracked source, test, policy and documentation groups are intentional work in progress; do not stage them until their owners report stable freezes and the coordinator authorizes the exact checkpoint.

## Coordination and recovery

Inspect actual agent status before assigning work or review. `send_message` queues a message but does not start a completed agent; use `followup_task` on the existing canonical identity for an idle or completed reviewer. Do not spawn duplicates solely because a queued message is unanswered. Save owned progress and exact operation and artifact identities before long work; reconcile saved outputs after a crash before rerunning.

Keep the recipe and reference oracle unchanged. Preserve private artifacts under ignored `build/rebuild/` or outside the checkout; never publish private paths, objects, game bytes, assets, binaries, disassembly, credentials or packs. Use disposable scratch worktrees for comparison operations that check out or clean files. See the [roadmap](ROADMAP.md) for milestones and [validation gates](VALIDATION.md) for evidence requirements.
