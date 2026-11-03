# Playable rebuild roadmap

The goal is a separately built runtime that can eventually launch and play with owned, compatible inputs. **No playable build or complete game link has been demonstrated.** Preserve the existing reference matcher, recipe variants and official checks independently throughout.

| Milestone | Current evidence | Exit gate |
|---|---|---|
| Reference and full recipe | 2,988 retained recipes compiled; separate full reference and retained checks reported parity. | Preserve compiler identities, recipe variants and original matching gates. |
| Code, data and EH ownership | Code identities and bounded archive/data projections are being assessed; local EH diagnostics and provider/ABI contracts remain open. | Reconcile every selected identity, data lifetime, relocation and EH dependency without guessed providers. |
| Startup and private link | A startup host compiled; entry, imports, data and code work remain separate and unclosed. | Independently review exact inputs and resolve all dependencies in a private link, without weakening the oracle. |
| Menu and gameplay | Not demonstrated. | Repeat isolated launches to a responsive menu, then exercise a documented gameplay route and broader scenarios. |
| Save/load and reproducibility | Not demonstrated. | Verify isolated save/load round trips and reproduce the workflow in an independently prepared environment. |

## Next concrete gates

1. Finish independent artifact and native read-only reviews of the bounded entry, data and import projections; retain failed attempts and unresolved identities.
2. Complete guarded CODE production and reconcile its actual coverage and receipts. Serialization alone does not prove a callable ABI or runtime provider.
3. Review the expanded EH observer and its exact output; retain failed pieces and unknown frame/lifetime contracts.
4. Establish real startup, CRT, TLS, data and import ownership before attempting a private application link. A link alone is not a game launch.

The [work ledger](AGENT-WORK.md) tracks owners and current review status. Detailed previous evidence and test counts are preserved in [evidence history](EVIDENCE-HISTORY.md); current validation and private-output rules are in [VALIDATION.md](VALIDATION.md).
