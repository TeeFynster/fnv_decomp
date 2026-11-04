# Original EH fixture probe

This original nonpolymorphic constructor fixture tests a narrow compiler-generated exception-handling component. It is not game code and does not establish real game EH, vtable, RTTI, data or runtime closure. The existing zero-relocation extractor remains separate and unchanged.

The producer compiled with the existing SP1 compiler. Its constructor has an associated cleanup/handler and unwind data plus a SafeSEH record. An intentionally unrelated function has an undefined sentinel; extraction omits it rather than supplying a stub. The policy-specific extractor and runner prepare two layouts, with private receipts and artifacts, for independent review before execution. The runner requires a hash-bound review of both variants and checks covering closure, linked EH metadata, SafeSEH, CRT providers, map and imports. Prepare and execution are separate steps; an execution requires exact reviewed inputs and a new receipt.

## Observed execution

The independently reviewed private `eh-fixture-v3` artifacts ran in both normal and moved layouts. The saved `execution.json` reports a pass, zero exit status and empty stderr for each. Each layout ran 1,024 rounds of three paths, with 2,048 typed catches, 3,072 resumptions and successful counters and sentinel checks. These results concern the original fixture and its reviewed build; they do not prove application startup or game EH closure.

The preparation, review, maps, executables and execution receipt are private outputs under ignored `build/rebuild/`; they must not be committed. The execution receipt binds the preparation and review hashes. The runner rechecks protected inputs before execution, but its recorded build commands and hashes are not a cryptographic proof of compiler execution or a complete transitive operating-system dependency attestation.

## Tests and use

Offline tests cover the policy-specific COFF extractor and the review/execution runner. The independent final suite ran 149 tests: 147 passed and two native opt-ins were skipped. It included 15 EH fixture-focused tests. The reviewer verified the prepared input hashes and execution bindings and performed a scoped source/privacy check. The runner exposes `prepare` and `execute` subcommands; execution requires the exact independently reviewed receipt and artifact hashes. Consult its command help and the [validation gates](VALIDATION.md) before using a new private output directory. No native fixture run is needed to repeat the offline suite.
