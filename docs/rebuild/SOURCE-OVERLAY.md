# One fixed runtime source overlay

This experiment replaces one source literal with the address of the existing
undefined `DAT_010a2304` carrier. It does not define storage, create a vtable,
select a provider, link or execute code. The original 88-field relocation audit
and all original source/retained proofs remain unchanged.

The public `runtime/source-overlays/niaccumulator-address.json` policy supports
only recipe `1401-50cd6090ff456b83`, the selected 25-byte constructor at original
symbolic address `0x00aa0fc0`, field +10. The policy is checked against the
implementation's fixed expected contract. It is an operational scope guard,
not an authentication boundary or permission to patch arbitrary source.

The generated private translation unit starts from the complete exact original
source bytes. One guarded contiguous span covering lines 3-8 keeps the quoted
include and all line endings/counts, places the identical existing extern
address-carrier declaration into the original blank line, and changes the
numeric RHS to `reinterpret_cast<unsigned int>(&DAT_010a2304)`. The later extern
declaration stays. Every other original byte is preserved. The volatile store,
implicit NiObject base construction and camera-member initialization remain.
No bytes in an object or executable are patched.

`tools/rebuild/runtime_source_overlay.py` pins the original recipe, retained
manifest, v3 proof, selection, owned reference, source and sole included class
header. It observes the exact SP1 compiler and code-generator hashes and
rehashes all protected inputs at completion. Generated source and the fresh object
are also pinned across compiler use, geometry parsing and plain comparison. Original `/MT /O2 /GS /EHsc /Gy`
flags stay unchanged; separately recorded context adaptations add the original
source-directory include search and diagnostic `/showIncludes`. This recovers
the original quoted-header origin without copying or rewriting a header.
Actual compiler include output must identify exactly the original class header.
The pinned source/header have no nested includes or path/time-sensitive macros;
the header guard is the only relevant preprocessor definition.

Use a new ignored private output directory:

```powershell
python tools/rebuild/runtime_source_overlay.py --doctor build/rebuild/doctor-all.json --reference <owned-hash-bound-plaintext-image> --out build/rebuild/source-overlay-niaccumulator-new
```

The fixed original recipe/proof paths default to their reviewed private saved
filenames. Outputs include the generated TU, object, private compiler log,
sanitized unchanged-comparator observation and result receipt. Source creation
is staged and exclusive; the new directory prevents overwriting evidence.
An append-only fsynced progress journal records compilation and verification
phases. Failures preserve artifacts/logs and an error receipt. No tool option
links or launches the constructor or any other executable.

Acceptance requires the unchanged plain original comparator to match the
constructor with exact 25-byte extent and all same-TU recipe functions, plus
independent geometry checks: the original field is an actual PE HIGHLOW with
operand `0x010a2304`; the new +10 DIR32 has zero addend and exact undefined
EXTERNAL `?DAT_010a2304@@3HA`; that name occurs exactly once and has no definition;
the existing +4 REL32/base target stays identical; every other constructor byte
is identical to the retained original. A candidate-specific re-audit records
one missing field becoming an exact DIR32 reference. It does not change the
original global count or adopt this object for runtime.

The carrier's C++ `int` type is address syntax, not the table storage type or
extent. Earlier bounded target review observed NiAccumulator RTTI, distinct
from the recovered constructor class name. Vtable extent/slots, class layout,
base-provider, storage protection/alignment, initialization, lifetime, teardown
and callable ABI remain open. No game fixup or execution is approved.

Fourteen offline tests cover exact source-span/line preservation, stale source,
wrong/comment-only/duplicate matches, wrong recipe/target, unauthorized changes,
include/macro context, changed volatile/member/base code, wrong/nonzero/duplicate
defined carrier references, path collisions, generated-source/object drift and failed plain comparison/extent.

```powershell
python -m unittest discover -s tests/rebuild -p test_runtime_source_overlay.py -v
```

Independent source/policy review and 14 offline tests passed before compilation.
The one private native compile completed successfully. Actual `/showIncludes`
identified only the original class header. The unchanged plain comparator
reported MATCH for all 12 original same-TU function rows; the selected
constructor's compiled extent remains exactly 25 bytes. The geometry checks
found precisely the new undefined-carrier DIR32 at +10, zero addend, unchanged
base REL32 at +4 and identical non-field constructor bytes. Original PE HIGHLOW
correspondence and all protected input hashes were rechecked. No link or native
execution occurred. Independent hardened-v2 review accepted the exact raw COFF
non-field bytes and +4/+10 relocations, confirmed all input/generated stability
flags and hashes, and independently reran the unchanged comparator: 12 of 12
rows MATCH, with the constructor extent exactly 25 bytes. The source/context
review independently verified the fixed transformation, sole pinned include and
false execution/provider/runtime states. Both reviewers independently passed
all 14 focused tests.

Private `source-overlay-niaccumulator-v2/result.json` SHA-256 is
`1f08b5be6d3eb7c090a3d7a3b7aee9b003136d40504d8c8f404d80eee4b5c1d3`;
generated TU SHA-256
`d4965b241022b18efd6321340d49e8d845f49af16ff2bd8007d7c5f6822cd8f4`;
overlay object SHA-256
`20a62376dd67ed8bc75730bb42039ff9f2989f7a53faf5a14d7455268d276387`;
plain comparison observation SHA-256
`255d651306960f8aea09d460f4657dad9b9ee214808940c55893bc1b9fd6df44`.
These are distinct new overlay artifacts, not replacements for retained baseline
objects or v3 proofs. The original global 88 missing-field count remains intact.

The current tool SHA-256 is
`21ac7e73c18afb814bb333af545a0608fc30d42702fb79ab060889e647a39fe6`.
The v1 artifacts remain preserved as intermediate evidence. The v2 tool adds
explicit generated TU/object before-and-after stability checks; transformation,
compiler flags, generated source and plain comparison content are unchanged.
Only focused tests and this single authorized recompile were repeated; the full
baseline was not rerun.
