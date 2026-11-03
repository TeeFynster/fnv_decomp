# Typed root-certificate composition

`root_certificate_composer.py` adds metadata policy `typed-root-certificate-composition-v1`. It never edits the frozen ordinary observer (`4bfdb5001380a3d7e5db7517033285d49ab211be68e2fcba15964f0ad5b03c53`), an original object, or an existing certificate. Consumers must explicitly request this new policy; ordinary certificates retain their original blocked status.

`compose(raw, contract, base, witnesses, policy_id=POLICY)` reparses the exact hash-bound object and recomputes the complete ordinary certificate. It replays every supported witness using its separately pinned implementation, requires complete witness equality, then discharges only exact original blocker IDs of that witness's supported type. Duplicate witnesses, overlapping discharges, forged IDs, stale source/object/contract graphs and changed dependencies fail. Unknown remaining blockers stay fatal to the composed omission decision. A rejected witness has no discharge authority, even if other witness rows succeed.

The initialized-data witness is policy `unused-ordinary-initialized-data-omission-v1`, producer SHA `1a0e8aa2271218f59c11497c1363b41f099bb259791e19adac7d80718e7a5d7b`. It may discharge only its proven omitted `.rdata` section's exact `UNSUPPORTED_SECTION_SEMANTICS` ID. Its protected directed graph includes physical uses, names, weak fallback, associations, implicit roots and special state; it does not establish DATA type, storage ownership or a runtime provider. Its full incoming-use proof remains attached through the witness hash and operational demonstration output.

The local-label adapter uses a separate typed envelope containing its immutable evidence/decision JSON and freshly decoded result. It may discharge only `LABEL_OMISSION_NOT_PROVED`, `UNPROVED_RETAINED_ENTRY_OR_ALIAS` or `UNSUPPORTED_LIVE_REFERENCE_RECORD` IDs for the exact proved physical labels. Its independently reviewed successor is pinned at `57cecc88c2f2aaccdf87ca8605fe84461c31a4c391884d503240329636e5f826`; absent or changed policy fails closed. That version permits an explicit source-bound supplemental four-byte operand/HIGHLOW witness for an omitted STATIC local label, with exact original reference/object/physical-field authority. The composer never invokes its serializer or merges same-spelling local symbols.

The result preserves the full unchanged base certificate, original false closure/graph flags, exact roots and retained primary/auxiliary slots. `composed_omission_complete` describes only absence of unresolved omission blockers under this new typed policy. Namespace, full serialization, materialization, provider, ABI, linking, emission and runtime flags remain false. EH/TLS/IAT/provider obligations, canonical-reference collisions and original missing fields are not discharged by either witness family. Even a complete omission result needs a separately reviewed source-COFF projection consumer.

Dependency pins follow the invoked witness families. DATA-only composition pins the initialized-data helper, parser and ordinary observer; it does not import the label helper. A label witness additionally requires its exact reviewed helper pin before import and replay. This does not waive any dependency used by DATA-only observations.

Blocker IDs identify content, not occurrence uniqueness. The base observer can report the same unknown directive twice with an identical content hash; both remain unchanged and separately numbered in `remaining_blocker_occurrences`. A typed discharge requires exactly one matching base occurrence. Ambiguous duplicate discharge requests fail closed; unknown multiplicity is never silently deduplicated.

## Cached demonstration contract

`demonstrate_cached_case` accepts one exact indexed row from the independently accepted central receipt SHA `290ac0e8c1ffbfd89df7dd6cdbbdb8df363edca58111b7aa19fe842aa26cc8e4`. It verifies the lane gzip, row, full contract and bare certificate hashes, joins the recipe and ten-field roots to the pinned manifest, then opens only that named original object and source for hash checking. Explicit external `witness_inputs` hashes join the same protected pre/post-publication set. It regenerates/replays typed witnesses, saves metadata only in a fresh exclusive output, and rechecks all inputs/tools and optional-index absence after publication. Output is removed on drift. No new global field stream, archive enumeration, compiler, linker, image read or Game execution occurs.

This operational evidence chain is not an authentication boundary against a Python caller editing or forging local code. The source review, accepted central receipt and fresh native-object recomputation are explicit inputs; a self-hash is never treated as permission to emit code.

## Separate complete physical CODE identity map

Root also authorized a metadata-only provider-map export for the relocation factory. Policy `selected-physical-provider-map-v1` streams the exact accepted data-owner details once, checking every event's false promotion flags and the complete event census/sequence digest. Each of the 68,657 selected CODE owner rows must join selection, original object/source/recipe identities and the exact retained v3 function section/value/span. Duplicate addresses, conflicting physical identities, missing rows and stale proof locations fail.

The map records original address, recipe, original object hash, physical symbol index, source hash, native section/value/size and source symbol. `planned_canonical_name` uses the existing physical identity formula `_fnv_code_` plus SHA-256 of canonical JSON `{recipe_id,object_sha256,symbol_index}`. These are planned namespace identities, not materialized exports: `materialized_exports` stays zero and every provider/runtime/emission flag stays false. This does not touch the DATA-provider bridge or create storage.

`export_provider_map` pins the existing owner summary/details, selection, manifest and retained receipt by exact hashes. It reads no native objects or source bodies and does not rescan the binding stream. It requires absent optional index and stable inputs after exclusive publication. The planned private destination is `root-certificate-composer-v1/physical-provider-map.json` under the ignored rebuild output directory. Source/schema review precedes this one export.

## Focused verification

The authored synthetic suite checks exact data discharge with the unchanged false base, explicit policy opt-in, unsupported/incomplete witnesses, preserved missing-field blockers, stale objects/contracts/certificates, forged graph/IDs, duplicate witnesses, dependency drift, unreviewed labels, complete physical provider identity and planned namespace calculation, missing/duplicate/conflicting owner rows, wrong source/native/proof spans, promotion/census/sequence failures, and post-publication drift cleanup. No original code/data bytes or native tools are used in these tests.

## Accepted physical identity export

The separate one-pass metadata export completed in 95.094 seconds with all 68,657 selected physical identities and no materialized exports. The 29,229,986-byte private map has SHA-256 `6cd5bf884bb28d460cfc92f63b765c15413904f58355844243ddd6b59b97001c`. Input hashes and absent optional-index state remained stable after publication. No source, original object, image, compiler or native loader was opened by this export.

Independent review reconciled every map identity with the pinned selected, retained and manifest records, checked physical uniqueness and canonical names, and accepted the artifact. The complete owner-stream sequence is the producer's checked observation; the independent reviewer did not rescan that stream or replay the export. Historical producer SHA `0e2f3ec93515c6fbe5d7dcf0ae03f9668f8fd58da6930ac875214e5994e7c745` is preserved byte-exact in the private `source-freeze-v1` snapshot; the later used-witness dependency correction does not change this map or its recorded producer.

The dependency correction was independently accepted with 21 focused tests. The first combined DATA observation failed cleanly because the composer incorrectly required globally unique blocker IDs; two identical `/DEFAULTLIB` unknown directives are legitimate separate base occurrences. Its abort receipt is preserved, with no success receipt. The successor preserves their multiplicity and allows only unambiguous typed discharges. No source-level numeric fallback or unknown-field waiver was introduced.

## Accepted typed-label composition

The occurrence-aware successor passed 23 focused tests and independent source review. One delegated metadata-only demonstration then consumed the exact central singleton for original root `0x00706320`, together with the independently accepted 26-record/26-use local-label witness. The supplemental operand proof remains separately hash-bound; the composer read no original reference image and copied no original code into an output.

The saved composed observation has SHA-256 `ec4488ae7e53e772e5506764831da766cfe2771a085ed360b8043c77aac8d3c0`. It preserves the full ordinary base certificate with its 19 original label blockers and false closure status. Nineteen uniquely identified occurrences are discharged under the new typed policy, with zero remaining omission blockers. `composed_omission_complete` is true; namespace, full serialization, provider, materialization and runtime flags remain false.

Independent output review joined the exact cached row/base/object/witness identities, replayed the pinned composer on fresh original COFF metadata, and checked every discharge against its original ordinal. The operation completed in 1.063 seconds with post-publication source/object/tool/witness stability and optional-index absence. No COFF serialization, compiler, linker, DLL load or native Game execution occurred. Projection consumers must opt into this composed policy and independently validate their serialization and namespace requirements.

## Shared initialized-data observations

The separately reviewed witness wrapper's fresh successor pass reused each of its 26 cached original objects across 79 exact central views and invoked the pinned composer on those same bytes. Its receipt has SHA-256 `46a7c8b274f4247ea5f65648a5534b08b87849f5913ac50102860d0e4c638aa8`; compressed witness/composition details have SHA-256 `4322a3a5770ee43ea92df02ab2b33de819cee24e1e082e391fd63977f06f5f0f`. The earlier clean failure remains separate and immutable.

Twenty-nine views passed their typed initialized-data witness, producing 29 exact blocker discharges. Sixteen composed omission views are complete: 11 singleton roots and five unions across six recipes. All 11 positive singleton roots have retained relocation fields; these are not new zero-reference projection results. Remaining unknown directives, EH, labels and other blockers retain their exact occurrences.

Independent composer-outcome review joined all 79 saved rows to central row/base/witness/composition hashes and reproduced the exact discharges, multiplicity, 16 complete views and 11 positive-root summaries. It did not reread original objects, replay the witness helper or scan global streams; separate witness-producer outcome review remains with that wrapper's owner. All runtime, provider, namespace, emission and full-serialization flags remain false.
