# Rebuild work and ownership

Current checkpoint: `6f5c26cf210bad11897cd2356440704e72406386`. The next wave is uncommitted. The root coordinator integrates work and review; owners edit only their assigned files. No full game link, provider closure or runtime has been established.

| Work | Owner / independent review | Current state and next gate |
|---|---|---|
| Startup host | `/root/rebuild_startup_host` / `/root/rebuild_startup_review` | Native compile-only result accepted; no remap, executable link or execution. |
| Entry dependencies and projection | `/root/rebuild_entry_dependencies` / `/root/rebuild_dependency_review`; projection `/root/rebuild_gaps_recovery` | Dependency graph observation accepted (16,838 / 47). The 4,532-byte entry projection passed Python outcome review; native read-only conformance is underway. No application link. |
| DATA arena | `/root/rebuild_data_fixture` / `/root/rebuild_tls_component_review` | Private 446-byte projection with 16 aliases and 20 field observations passed Python artifact review; native read-only conformance is underway via the entry owner. Runtime selection remains false. |
| Import projection | `/root/rebuild_import_projection` / independent review | 25/30 DEF v1 native attempt hit a quote bug; failure retained and fix under review. No import-provider adoption. |
| All-current CODE | `/root/rebuild_code_pool` / `/root/rebuild_function_selection` | Guarded production for 16,859 candidates is authorized; outcome is not yet available. Do not infer coverage or runtime readiness. |
| Expanded EH | `/root/rebuild_symbol_binding` and `/root/rebuild_eh_recovery` | Additive collector and relocation work is in progress; full 300-row actual observation is pending review. Existing failed pieces and frame/lifetime unknowns remain. |
| Shared documentation | `/root/rebuild_docs_recovery` | Reorganizing current guidance; phase evidence and prior shared text remain in [evidence history](EVIDENCE-HISTORY.md). |

Earlier scoped work, receipts and canonical owner identities are preserved in [evidence history](EVIDENCE-HISTORY.md) and the linked phase documents. Current untracked source, test, policy and documentation groups are intentional work in progress; do not stage them until their owners report stable freezes and the coordinator authorizes the exact checkpoint.

## Coordination and recovery

Inspect actual agent status before assigning work or review. `send_message` queues a message but does not start a completed agent; use `followup_task` on the existing canonical identity for an idle or completed reviewer. Do not spawn duplicates solely because a queued message is unanswered. Save owned progress and exact operation and artifact identities before long work; reconcile saved outputs after a crash before rerunning.

Keep the recipe and reference oracle unchanged. Preserve private artifacts under ignored `build/rebuild/` or outside the checkout; never publish private paths, objects, game bytes, assets, binaries, disassembly, credentials or packs. Use disposable scratch worktrees for comparison operations that check out or clean files. See the [roadmap](ROADMAP.md) for milestones and [validation gates](VALIDATION.md) for evidence requirements.
