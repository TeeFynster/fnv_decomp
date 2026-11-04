# Synthetic RTTI ABI fixture and metadata validator

This directory holds three things:

- a small, invented C++ fixture that exercises `dynamic_cast` across two
  translation units;
- a versioned, machine-readable metadata schema with an offline validator;
- a compile-only plan for Microsoft Visual C++ 2008 SP1 x86.

**Nothing native has been run.** No compiler, linker or fixture has run for
this delivery. Every native result is `NOT_RUN`. The fixture source and these
synthetic tests do not establish runtime RTTI compatibility, cross-module or
game ABI compatibility, runtime readiness or a playable game.

## Files

| File | What it is |
|---|---|
| `README.md` | This file. |
| `expected-ABI.md` | What C++ requires of each cast, what the compiler is expected (but not known) to emit, and what stays unverified. |
| `COMPILE-PLAN.md` | The bounded compile-only plan, for the coordinator's review. Not executed. |
| `compile-plan.json` | The same plan in machine-readable form. |
| `RESULTS.md` | Test results, attribution and limitations. |
| `rtti_abi.py` | The validator and command-line tool. Python 3.10+, standard library only. |
| `fixture/rtti_abi_fixture.h` | Shared declarations: classes, views, producer and consumer interfaces. |
| `fixture/rtti_producer.cpp` | Translation unit 1: member definitions, object creation and destruction. |
| `fixture/rtti_consumer.cpp` | Translation unit 2: the 32 `dynamic_cast` cases. |
| `fixture/fixture-metadata.json` | The fixture's hierarchy, objects, case matrix, layout claims and measurements in schema v1. |
| `examples/valid-minimal.json` | Invented single-inheritance example, including a claim kept `unknown`. |
| `examples/valid-diamond.json` | Invented virtual-inheritance example with `same_result_as`. |
| `examples/invalid-missing-reference.json` | A base class that is never declared (`E-REF`). |
| `examples/invalid-duplicate-class.json` | A class declared twice (`E-DUP`). |
| `examples/invalid-cycle.json` | An inheritance cycle (`E-CYCLE`). |
| `examples/invalid-polymorphic-conflict.json` | A class with a polymorphic base marked non-polymorphic (`E-POLY`). |
| `examples/invalid-conflicting-outcome.json` | A failed cross-cast claimed to succeed (`E-OUTCOME`). |
| `examples/invalid-promoted-adjustment.json` | A layout-dependent address claimed as fact (`E-ADJUST`). |
| `examples/invalid-null-reference.json` | A reference cast with a null input (`E-ILLFORMED`). |
| `examples/invalid-observed-claim.json` | A claim marked `observed` (`E-OBSERVED`). |
| `examples/invalid-native-result.json` | A measurement result other than `NOT_RUN` (`E-NOT-RUN`). |
| `examples/invalid-same-result.json` | Two casts wrongly claimed to select the same subobject (`E-RESULT`). |

The tests are in `tests/rtti-abi/`.

## Usage

```
python tools/rtti-abi/rtti_abi.py validate <metadata.json> [--format text|json]
python tools/rtti-abi/rtti_abi.py check-plan <compile-plan.json> [--format text|json]
```

| Exit code | Meaning |
|---|---|
| 0 | Valid. A summary is printed. |
| 1 | Rejected. Each problem is listed with its JSON pointer and a stable code. |
| 2 | Usage or file error. |

Each command reads only the one JSON file it is given. It does not open the C++
sources, object files, executables, game files or anything else. It starts no
program, uses no network and writes no file.

Example:

```
python tools/rtti-abi/rtti_abi.py validate tools/rtti-abi/fixture/fixture-metadata.json
```

```
OK: metadata is valid (fnv-rtti-abi-metadata v1): 16 classes, 8 objects, 32 casts, 62 layout claims, 1 measurement(s).
Outcomes required by the C++ rules: success 20, null 8, bad_cast 4.
Result address versus input, as C++ decides it: same 0, must differ 7. Not decided by C++ (layout-dependent): 13. No result: 12. Claimed unknown and kept unknown: 0.
Layout claims: unknown 28, hypothesis 34, observed 0 (schema v1 cannot record observations).
Measurements and native results: all NOT_RUN.
Checked: references, duplicates, class graph, C++ dynamic_cast semantics and C++ address guarantees.
Not verified: any compiler-emitted record, field, offset or decorated name; linking; run-time cast or exception behaviour; cross-module or game ABI compatibility; runtime readiness. Native results: NOT_RUN.
```

## Metadata schema: `fnv-rtti-abi-metadata`, version 1

The input is strict JSON: UTF-8 without a byte order mark, with no duplicate
keys and no `NaN` or `Infinity`. Unknown keys are rejected at every level.
Identifiers match `[A-Za-z][A-Za-z0-9_]{0,47}`. Class ids must also be unique
when compared case-insensitively.

| Key | Required | Value |
|---|---|---|
| `schema` | yes | `"fnv-rtti-abi-metadata"` |
| `schema_version` | yes | `1` |
| `fixture` | yes | An identifier. |
| `classes` | yes | 1 to 64 classes. |
| `objects` | yes | Up to 64 complete objects: `{"id", "class"}`. The class is the object's dynamic type. |
| `casts` | yes | Up to 256 casts. |
| `layout_claims` | no | Up to 512 claims about compiler records. |
| `measurements` | no | Up to 16 planned measurements. |

**Class:** `{"id", "polymorphic": bool, "bases": [...]}`. Each class has up to 8
direct bases, each `{"class", "virtual": bool, "access": "public" |
"protected" | "private"}`. There is no field for a size, offset or order.

**Cast:**

| Key | Value |
|---|---|
| `id` | An identifier. |
| `form` | `pointer`, `reference` or `void_pointer`. |
| `input` | `{"object", "path"}`, or `{"null_of": class}` for a null pointer of that static type. `path` lists class ids from the object's dynamic type down to the input's static type, through direct bases (1 to 16 entries). |
| `target` | The target class; required unless `form` is `void_pointer`, for which it is forbidden. |
| `expect` | `success`, `null` or `bad_cast`. |
| `adjustment` | `none`, `nonzero`, `layout_dependent`, `not_applicable` or `unknown`. |
| `result_path` | Optional: the path to the subobject the result must be. |
| `same_result_as` | Optional: another cast that must select the same subobject of the same object. |

**Layout claim:** `{"id", "record", "class", "property", "status"}`, plus
`base_path` and `expect` where allowed.

- `status` is `unknown` or `hypothesis`. `observed` is rejected (`E-OBSERVED`):
  version 1 cannot record an observed compiler fact.
- An `unknown` claim states no expectation.
- A `hypothesis` states `expect` from the property's short list.
- There is no field for a numeric value, offset, name or evidence.

| Record | Properties (allowed hypothesis values) |
|---|---|
| `complete_object_locator` | `emitted` (present/absent), `offset_field` (zero/nonzero), `cd_offset_field` (zero/nonzero). Optional `base_path` names the subobject whose vftable it serves. |
| `type_descriptor` | `emitted` (present/absent), `name_string` (unknown only). |
| `class_hierarchy_descriptor` | `emitted`, `multiple_inheritance_flag` (set/clear), `virtual_inheritance_flag` (set/clear), `base_count` (unknown only). |
| `base_class_descriptor` | Requires `base_path`. `emitted`, `mdisp` (zero/nonzero), `pdisp`, `vdisp` and `attributes` (unknown only). |
| `vftable` | `emitted`, `locator_reference` (present/absent). Optional `base_path`. |
| `vbtable` | `emitted` (present/absent). |

**Measurement:** `{"id", "kind": "compile_only", "variant", "result": "NOT_RUN"}`.
Any other result is rejected (`E-NOT-RUN`).

## What the validator checks

1. **Structure and limits.** Types, required and unknown keys, identifier
   grammar and counts. Input is limited to 256 KiB and 8 levels of nesting, and
   a class to 1024 base subobjects.
2. **Identities and references.** Duplicate ids (`E-DUP`). Every class, object,
   target and `same_result_as` reference resolves (`E-REF`).
3. **The class graph.** No cycle (`E-CYCLE`), no repeated direct base
   (`E-BASE-DUP`), and a class with a polymorphic base must be polymorphic
   (`E-POLY`).
4. **Paths.** Each `path`, `result_path` and `base_path` follows direct bases
   (`E-PATH`).
5. **C++ cast semantics.** The validator builds the subobjects of each object.
   A virtual base is one shared subobject; each non-virtual base is its own. It
   then applies the `dynamic_cast` rules (see `expected-ABI.md`, section 2) and
   requires:
   - the claimed outcome to match (`E-OUTCOME`);
   - the cast to be well-formed, so not a non-polymorphic run-time cast, an
     ambiguous or inaccessible upcast, or a null reference (`E-ILLFORMED`);
   - `result_path` and `same_result_as` to name the subobject C++ selects
     (`E-RESULT`).
6. **Adjustment evidence.** The claimed `adjustment` must equal what C++
   decides (`E-ADJUST`):
   - `none`: the result is the input subobject itself;
   - `nonzero`: distinct polymorphic subobjects, neither containing the other,
     must have distinct addresses;
   - `layout_dependent`: everything else.

   Claiming `none` or `nonzero` where C++ does not decide is rejected as
   promoting a layout assumption to a fact. `unknown` is always accepted and is
   reported as kept unknown. It is never replaced by the computed value.
7. **Layout claims.** Each claim must be consistent with the declared hierarchy
   (`E-CLAIM`). For example:
   - no vftable or locator for a non-polymorphic subobject;
   - a virtual-inheritance flag that agrees with the declared virtual bases;
   - no vbtable for a class without a virtual base;
   - a class's displacement from itself is not claimed nonzero.

   Duplicate claims are rejected. Nothing about the compiler's actual layout is
   assumed.

### Diagnostics

Each problem is printed as `  <JSON pointer>: <code>: <message>`. Problems
appear in document order, and the same input always gives the same output. At
most 50 are shown, with the total count.

Messages never repeat input values. They give no ids, paths or strings from the
file, never print the input path or any absolute path, and argument errors
never echo the arguments. Paths that are UNC or device paths, or reserved
device names, are refused before any file access.

Codes: `E-JSON`, `E-ENCODING`, `E-DUPKEY`, `E-LIMIT`, `E-SCHEMA`, `E-ID`, `E-DUP`,
`E-REF`, `E-CYCLE`, `E-BASE-DUP`, `E-POLY`, `E-PATH`, `E-ILLFORMED`,
`E-OUTCOME`, `E-ADJUST`, `E-RESULT`, `E-CLAIM`, `E-OBSERVED`, `E-NOT-RUN`,
`E-PLAN`, `E-PLAN-ARGV` and `E-PLAN-FORBIDDEN`.

## The compile plan check

`check-plan` accepts only the bounded plan in `COMPILE-PLAN.md`. It requires:

- status `NOT_RUN`, and `NOT_RUN` for every identity value and step result;
- the caller-supplied compiler placeholder, with automatic discovery off;
- the exact reviewed argument vector for each step;
- a separate output for each step under `<PRIVATE_OUT_DIR>`;
- a closed environment;
- the full list of forbidden operations.

It reports link, run, debug, listing, response-file and RTTI- or EH-changing
arguments as `E-PLAN-FORBIDDEN`, and any other change as `E-PLAN-ARGV` or
`E-PLAN`.

## QA

From the repository root:

```
python -m unittest discover -s tests/rtti-abi -p "test_*.py" -v
```

Input ancestor symlink and reparse-point checks are best-effort and not atomic against concurrent replacement; use a trusted stable local tree.

`compile_once.py` is a separate review-gated private two-unit compile-only driver; it does not link or run the fixture.

The separately reviewed SP1 x86 compile-only probe subsequently compiled the two synthetic translation units successfully. No link, fixture execution, compiler metadata inspection, or game RTTI compatibility was established. The original delivery plan remains a historical `NOT_RUN` plan; the private outcome has a separate receipt.
