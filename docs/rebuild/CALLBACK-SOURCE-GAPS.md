# Source-ownership workpack for the remaining conditional XC targets

The [callback correspondence audit](CALLBACK-IDENTITIES.md) leaves 537 XC
targets with no saved source-body correspondence. These are conditional table
targets, not 537 proved missing functions. Instruction boundaries, extents,
original caller reachability and whole-stage identity remain unapproved.

`tools/rebuild/callback_source_gap_pack.py` makes this ownership queue concrete
without opening the original image, retained objects or code payloads. It
preserves every original table index/site/target and explicitly prohibits an
original-address fallback or stub. Five synthetic tests cover half-open
geometry, disagreement among anchors, invalid extents and the distinction
between a geometry lead and ownership.

The producer streams the exact saved all-size CODE inventory: 2,988 recipe
metadata rows and 68,657 selected-source anchors. For each selected native code
section it derives a **hypothetical**, unapproved section base from its known
ordinary-function VA/value anchors. No target is assigned to the nearest
function. All anchor sets agree in this saved population, but no remaining XC
target falls in even those extended native-section envelopes. This does not
establish an original section mapping or verify any bytes beyond the checked
ordinary function span.

The complete canonical candidate stream has 91,176 exact address groups, with
no group for these targets. Its source candidates are not silently substituted
for source ownership. The inventory additionally contains 64,135 unanchored
native code sections. Their existence means relevant compiled source may still
be present without a verified original address. Full unbound symbol tables are
not included in this saved section-metadata view. Neither negative join proves
that source is absent, that a target begins a function, or that initialization
may omit it.

| Workpack observation | Count |
|---|---:|
| Conditional XC targets retained | 537 |
| Exact canonical address candidates | 0 |
| Anchored native-section geometry leads | 0 |
| Non-affine anchor groups | 0 |
| Original image/object payload reads | 0 |

Inputs include the exact selection and manifest used by earlier audits,
`runtime-code-inventory-native-v1.jsonl.gz` SHA-256
`91cdc91af6530e6e80e2104cdfeb9bd6928e17fa0f75bcf066734985248f1031`,
and `canonical-candidates-byte-verified.ndjson.gz` SHA-256
`d9effec2d39f8bb0d962ae04c7bdec855ae31230be4b247c861075cd0e95d0ad`.
Private `callback-source-gap-pack-v1.json` is 218,395 bytes, SHA-256
`75005cf7ad3902370bb10a74f99c57509b8b9d21bfb46f4f1ab63dd9c36a524b`.
Independent source/output review reproduced all 2,988 inventory joins, 68,657
anchor hypotheses, 64,135 unanchored sections, 91,176 exact address groups,
all 537 work entries and every uncertainty flag; the five tests pass. No
original image or object payload was reread. No runtime provider, source body,
function extent or registration is emitted or selected.

The next source-owner task must obtain an authoritative source or
compiler-generated callback binding for each remaining target. A bounded
symbol/section census of relevant unanchored compiled source may supply leads,
but it must preserve unsupported cases and establish original-address identity
before treating them as providers. Any proposed original-code comparison needs
its own legitimate named-source/library evidence and approved finite scope;
this workpack grants no such read. No whole-text search, guessed boundary,
blanket library-role assignment, zero replacement or automatic registration
can close these gaps.
