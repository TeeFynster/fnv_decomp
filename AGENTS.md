# Working in this repository

This repository currently builds reference objects for byte comparison; it is not a runnable game. Read `README.md` and `LICENSE` before changing it. The existing license grants no licence to contributions. Do not infer publication or distribution rights from this development plan; an eventual release requires a separate rights review.

Preserve `build/units.json`, including compiler and optimization variants, and the existing byte-matching oracle and official checks. A linkable runtime is a separate target, not evidence that reference matching passed. Do not weaken or replace matching gates to make a runtime build work. Record evidence and unresolved assumptions honestly.

Keep private development inputs outside the repository; generated rebuild output defaults to the ignored `build/rebuild/` directory and may instead be kept outside the checkout. Protect: game files and assets, executables, game code bytes, disassembly, context packs, generated objects, compiler installations, credentials and private paths. Never put these in publishable source, documentation, logs or commits. The ignore rules are a backstop, not permission to include them. Do not distribute a game binary or instructions to bypass protection. Follow the original README's requirements for a personally owned, compatible image when running a comparison.

Use disposable scratch worktrees for `tools/compare_builds.py` operations that check out or clean files; never point them at an active working tree. Coordinate edits using `docs/rebuild/AGENT-WORK.md`, and use `docs/rebuild/ROADMAP.md` for milestones and evidence. Do not reset, clean, or overwrite another contributor's work.

For agent coordination, inspect actual agent status before assigning work or review. `send_message` queues a message but does not start a completed agent; use `followup_task` on the existing canonical identity for an idle or completed reviewer. Do not spawn duplicates because a queued message went unanswered. Save owned progress and exact operation and artifact identities before long work; after a crash, reconcile saved outputs before rerunning.
