# Expected ABI: synthetic x86 RTTI fixture

**Status: nothing in this document has been observed.** No compiler, linker
or fixture has been run for this delivery. Every native result is `NOT_RUN`.

This document describes what Microsoft Visual C++ 2008 SP1 for x86, with `/GR`
and `/EHsc`, is expected to emit for the fixture in `fixture/`, and lists what
stays unverified. It keeps three levels of statement apart:

| Label | Meaning |
|---|---|
| **C++ rule** | Required by the C++ language, whatever the compiler. The validator (`rtti_abi.py`) checks these from the declared hierarchy. |
| **Hypothesis** | What this compiler is commonly expected to do, based on public descriptions of the MSVC RTTI scheme and of its C runtime. It has not been measured here, and may be wrong for these exact flags. |
| **Unknown** | No expectation is stated. It must be measured before anyone relies on it. |

No byte offset, record size, field width, field order, decorated name or emitted
value is given anywhere below as a fact. Where one matters, it is marked
unknown.

## 1. Fixture boundaries

| Part | What it holds |
|---|---|
| `rtti_abi_fixture.h` | Shared declarations: 16 invented polymorphic classes, the view structs, the producer and consumer interfaces. |
| `rtti_producer.cpp` (translation unit 1) | Every constructor, destructor and virtual function. Creates and destroys the objects. Fills each view by implicit derived-to-base conversion. Performs no `dynamic_cast`. |
| `rtti_consumer.cpp` (translation unit 2) | Every `dynamic_cast` in the case matrix. Sees declarations only; some casts require runtime checks, while null inputs and the ordinary upcast may be folded without an RTTI helper. |

The class families are:

- **Single inheritance:** `SiLeaf : SiMid : SiRoot`.
- **Multiple inheritance:** `MiJoin : public MiLeft, public MiRight`, and
  `MiSealed : public MiLeft, private MiRight`.
- **Virtual inheritance:** `ViLeft` and `ViRight` each derive virtually from
  `ViBase`; `ViJoin : public ViLeft, public ViRight` has one shared `ViBase`.
- **Ambiguity:** `AmLeft` and `AmRight` each derive non-virtually from `AmBase`;
  `AmJoin : public AmLeft, public AmRight, public AmTag` has two `AmBase`
  subobjects.

**Lifetimes.** `create_fixture_objects()` allocates one object of each tested
dynamic type with `new` and fills the views. The objects live until
`destroy_fixture_objects()` deletes them through their complete-object pointers.
The consumer never creates, deletes or retains them.

**Exception boundary.** No exception is meant to cross the producer/consumer
interface. `create_fixture_objects()` catches `std::bad_alloc` and cleans up. In
the consumer, each reference case catches `std::bad_cast` itself. Nothing
catches `...`, so any other exception propagates to whoever calls
`run_cast_cases()`.

**Preconditions for every case:**

1. Both translation units are compiled by the same compiler, with the same
   flags and the same C runtime model (see `COMPILE-PLAN.md`).
2. They are linked into one module. Linking is not part of this delivery, and a
   cast across a module boundary (for example a DLL) is outside this fixture.
3. `create_fixture_objects()` returned true, and the objects have not been
   destroyed.
4. Nothing else modifies the objects while the cases run.

## 2. C++ semantic expectations

### 2.1 Rules used

These are the language rules for `dynamic_cast` (the "dynamic cast" section of
the C++ standard, `[expr.dynamic.cast]`; section numbers differ between
editions). The fixture performs every cast outside any class scope, so only
public bases are accessible.

1. **Static conversion.** If the target is the source type or an accessible,
   unambiguous base of it, the cast is an ordinary upcast with no run-time check
   (case S08). An ambiguous or inaccessible base makes the cast ill-formed.
2. **Run-time check** (polymorphic source type only):
   - *Downcast:* if the input is a public base subobject of exactly one object
     of the target type, the result is that object.
   - *Cross-cast:* otherwise, if the input is a public base subobject of the
     most derived object, and that object has exactly one public base subobject
     of the target type, the result is that subobject.
   - *Failure:* otherwise the pointer form yields a null pointer, and the
     reference form throws `std::bad_cast`.
3. **Null input:** the pointer form of a null input yields a null pointer of
   the target type. A reference cannot be null.
4. **`dynamic_cast<void*>`:** yields the address of the most derived object.

### 2.2 Address guarantees

The `Address` column says what C++ itself decides about the result address
compared with the input address:

- **same**: the result is the input subobject itself.
- **must differ**: the result and the input are distinct subobjects, neither
  contains the other, and both are polymorphic, so neither can be a zero-size
  base subobject. C++ requires such objects to have distinct addresses (C++03
  section 1.8; `[intro.object]` in later editions). This is a nonzero base
  adjustment that the class design forces, and it needs no layout knowledge.
- **layout-dependent**: one subobject contains the other (for example a
  downcast, or a static upcast). C++ does not say whether their addresses
  differ. Under the common MSVC layout, a first non-virtual base is expected to
  share the derived object's address, and a virtual base is not. That is a
  **hypothesis**, and the metadata keeps it as `layout_dependent`.
- **n/a**: the cast has no result.

Independently of layout, each successful case also compares the result with the
producer's view of the expected subobject. Equality of the two pointers is a C++
rule. The views were made by static conversion in the other translation unit,
so the check needs no layout knowledge.

### 2.3 Case matrix

The columns are: the case id; the cast form; the input (object, and the base
path from its dynamic type to the static type of the input); the target type;
the outcome C++ requires; and the address relation C++ decides. The same matrix
is in `fixture/fixture-metadata.json` and in `run_cast_cases()`, and the tests
keep all three in step.

| Case | Form | Input | Target | Expected | Address |
|---|---|---|---|---|---|
| S01 | pointer | si_leaf: SiLeaf > SiMid > SiRoot | SiLeaf | success | layout-dependent |
| S02 | pointer | si_mid: SiMid > SiRoot | SiLeaf | null | n/a |
| S03 | pointer | si_leaf: SiLeaf > SiMid > SiRoot | SiMid | success | layout-dependent |
| S04 | reference | si_mid: SiMid > SiRoot | SiLeaf | `bad_cast` | n/a |
| S05 | reference | si_leaf: SiLeaf > SiMid > SiRoot | SiMid | success | layout-dependent |
| S06 | pointer | null `SiRoot*` | SiLeaf | null | n/a |
| S07 | `void*` | si_leaf: SiLeaf > SiMid > SiRoot | (most derived) | success | layout-dependent |
| S08 | pointer | si_leaf: SiLeaf | SiRoot | success | layout-dependent |
| M01 | pointer | mi_join: MiJoin > MiLeft | MiRight | success | must differ |
| M02 | pointer | mi_join: MiJoin > MiRight | MiLeft | success | must differ |
| M03 | pointer | mi_join: MiJoin > MiRight | MiJoin | success | layout-dependent |
| M04 | pointer | mi_left: MiLeft | MiRight | null | n/a |
| M05 | reference | mi_left: MiLeft | MiRight | `bad_cast` | n/a |
| M06 | reference | mi_join: MiJoin > MiRight | MiLeft | success | must differ |
| M07 | pointer | null `MiRight*` | MiLeft | null | n/a |
| M08 | `void*` | mi_join: MiJoin > MiRight | (most derived) | success | layout-dependent |
| M09 | pointer | mi_sealed: MiSealed > MiLeft | MiRight | null | n/a |
| M10 | pointer | mi_sealed: MiSealed > MiLeft | MiSealed | success | layout-dependent |
| V01 | pointer | vi_join: ViJoin > ViLeft > ViBase | ViJoin | success | layout-dependent |
| V02 | pointer | vi_join: ViJoin > ViLeft | ViRight | success | must differ |
| V03 | pointer | vi_join: ViJoin > ViLeft > ViBase | ViRight | success | layout-dependent |
| V04 | pointer | vi_left: ViLeft > ViBase | ViRight | null | n/a |
| V05 | reference | vi_left: ViLeft > ViBase | ViRight | `bad_cast` | n/a |
| V06 | reference | vi_join: ViJoin > ViLeft | ViRight | success | must differ |
| V07 | pointer | null `ViBase*` | ViJoin | null | n/a |
| V08 | pointer | vi_join: ViJoin > ViRight > ViBase | ViJoin | success | layout-dependent |
| V09 | `void*` | vi_join: ViJoin > ViRight > ViBase | (most derived) | success | layout-dependent |
| A01 | pointer | am_join: AmJoin > AmTag | AmBase | null | n/a |
| A02 | reference | am_join: AmJoin > AmTag | AmBase | `bad_cast` | n/a |
| A03 | pointer | am_join: AmJoin > AmLeft > AmBase | AmJoin | success | layout-dependent |
| A04 | pointer | am_join: AmJoin > AmRight > AmBase | AmLeft | success | must differ |
| A05 | pointer | am_join: AmJoin > AmTag | AmLeft | success | must differ |

Notes on specific cases:

- **M01, M02, M06, V02, V06, A05** are cross-casts between sibling bases. They
  must change the address.
- **M09** fails because `MiRight` is a private base of `MiSealed`. The cross-cast
  rule requires a public base. Conformance of the compiler's run-time helper on
  private bases is **unknown** and is worth measuring.
- **M10** succeeds: the input reaches the most derived object through a public
  base, even though the object also has a private base.
- **V01, V03, V08** start from the shared virtual base. A `static_cast` from a
  virtual base is ill-formed, so only `dynamic_cast` can do these. V08 reaches the
  same `ViBase` subobject by the other path and must give the same result as V01
  (`same_result_as` in the metadata).
- **A01, A02** fail because `AmJoin` has two `AmBase` subobjects, so the target
  is ambiguous.
- **A04** starts from the `AmBase` inside `AmRight`. No `AmLeft` contains that
  subobject, so the downcast rule does not apply. The cross-cast rule then finds
  the single `AmLeft` of the most derived object.
- **S06, M07, V07** have null inputs. Whether the compiler checks for null
  inline or leaves it to the helper is **unknown**. The C++ result is null
  either way.

## 3. Compiler-specific expectations (hypotheses)

Everything in this section is a **hypothesis** or **unknown** for
MSVC 2008 SP1, x86, `/GR /EHsc /Od /MT`. The fixture metadata records the same
items as `layout_claims`, each with status `hypothesis` or `unknown`. Schema v1
cannot record an observed value.

### 3.1 RTTI records

The public descriptions of the MSVC scheme name the records below. Field names
are given only to say what would be measured. Their order, width and encoding
are **unknown** here.

| Record | Hypothesis | Unknown |
|---|---|---|
| **vftable and locator reference** | Each vftable of a polymorphic class is accompanied by a reference to a complete object locator, stored next to the vftable's first slot. `MiJoin` is expected to have two vftables (one per polymorphic base), each with its own locator. | Where the reference sits, and the slot order. |
| **Complete object locator** | One per vftable. Described as holding a signature, an offset field (where this vftable's pointer sits within the complete object), a constructor-displacement (cd offset) field, a reference to the type descriptor and a reference to the class hierarchy descriptor. The offset field is expected to be zero for a primary vftable and nonzero for the `MiRight` vftable inside `MiJoin`. | Field values, and the cd offset field's value for the virtual-inheritance classes. |
| **Type descriptor** | One per class whose type is referenced. It refers to the vftable of `type_info` and holds the decorated type name as a string. | The name string's exact form. No decorated name is recorded in this delivery. |
| **Class hierarchy descriptor** | One per class. Described as holding a signature, attribute flags (including flags for multiple and for virtual inheritance), the number of base classes, and a reference to the base class array. Expected: the virtual-inheritance flag set for `ViLeft`, `ViRight` and `ViJoin`, clear for `MiJoin` and `AmJoin`; the multiple-inheritance flag set for `MiJoin`. | Flag bit values, the base count, and how `MiSealed` and `AmJoin` are flagged. |
| **Base class array and base class descriptors** | The base class array lists one base class descriptor for the class itself and one for each base subobject. Each descriptor is described as holding a type descriptor reference, a count of contained bases, a member displacement triple (`mdisp`, `pdisp`, `vdisp`) and attributes. For a non-virtual base, `pdisp` is expected to carry a "no virtual base" marker, and `mdisp` the displacement. For a virtual base, `pdisp` is expected to locate the vbtable pointer and `vdisp` to index the vbtable. A private base (in `MiSealed`) and the duplicated `AmBase` are expected to be marked in the attributes as not usable for the cast. | Every displacement value, the attribute bits, and the array order. `mdisp` for the class itself is zero by definition; for `MiRight` in `MiJoin` it is a nonzero **hypothesis**. |
| **vbtable** | `ViLeft`, `ViRight` and `ViJoin` are expected to have vbtables and vbtable pointers, because each has a virtual base. | Pointer position, entries and count. |
| **vtordisp** | `ViLeft`, `ViRight` and `ViJoin` override the virtual destructor of their virtual base and declare constructors. Under the default `/vd1`, the compiler may therefore add vtordisp fields. | Whether it does, where, and how that shows in the locator's cd offset field. |

### 3.2 Which translation unit emits what

| Item | Hypothesis | Unknown |
|---|---|---|
| vftables, locators, hierarchy descriptors, base class arrays and descriptors | Emitted by the producer, which defines every constructor and virtual function. Emitted as COMDAT sections and folded by the linker. | Whether the consumer emits any of these too. |
| Type descriptors | Emitted by the producer for every class. Emitted by the consumer for the source and target type of every run-time `dynamic_cast`, and for `std::bad_cast` as a catch type. Emitted as COMDAT and folded by the linker into one per type within a module. | Whether the consumer's copies are identical bytes. |
| Type identity at run time | The run-time helper matches the target type against the base class descriptors by type descriptor. | Whether it compares by address, by decorated name or both. This matters across modules, where COMDAT folding does not apply. |

### 3.3 Helper and library references

- **Run-time cast helper (hypothesis).** Each run-time `dynamic_cast` compiles
  to a call of a C runtime helper (`__RTDynamicCast` in public descriptions).
  It is described as taking the input pointer, the displacement of the input's
  vftable pointer, the source type descriptor, the target type descriptor and a
  flag for the reference form. `dynamic_cast<void*>` is described as calling a
  separate helper (`__RTCastToVoid`). The static upcast (S08) is expected to
  call no helper. The fixture never calls a helper directly.
- **Library linkage (hypothesis).** With `/MT`, the helpers and `type_info`
  come from the static C runtime and appear in the objects as external
  references. With `/MD` they would be imports from the C runtime DLL. Which
  symbol form, plain or import, each object file shows is **unknown**, and the
  plan fixes `/MT`.
- **Allocation (hypothesis).** The producer references `operator new` and
  `operator delete`, and the scalar deleting destructors of each class.
- **Exception handling (hypothesis).** Each function with a `try`/`catch` is
  expected to reference the compiler's C++ frame handler and to carry
  exception-handling records (function information, unwind map, try-block map
  and handler type records). The handler type records for `std::bad_cast` and
  `std::bad_alloc` refer to their type descriptors. The exact handler symbol and
  record layout are **unknown** here.

### 3.4 Reference-cast failure and the exception boundary

- **C++ rule.** A failed reference cast throws `std::bad_cast`. S04, M05, V05 and
  A02 catch it in the consumer.
- **Hypothesis.** The throw happens inside the run-time helper in the C runtime,
  using the C runtime's own throw information for `std::bad_cast`. It is caught
  by the consumer's handler through the C++ exception mechanism. That requires
  `/EHsc` in the consumer. With `/EHsc`, a catch clause does not catch
  structured (SEH) exceptions, and the fixture has no `catch (...)`.
- **Unknown.** Whether the helper raises a different exception type for a bad
  or non-polymorphic input. The fixture never passes such an input, and does
  not catch any other type.
- **Out of scope.** Exceptions that cross a module boundary, mixed C runtime
  models, and unwinding beyond the consumer.

## 4. What remains unverified

| Item | C++ status | Compiler status |
|---|---|---|
| Outcome of each case | Rule (section 2.3) | `NOT_RUN` |
| Result equals the producer's view | Rule | `NOT_RUN` |
| Address must differ (7 cases) | Rule | `NOT_RUN` |
| Address relation for the 13 layout-dependent cases | Not decided by C++ | Unknown |
| Records emitted, and by which translation unit | n/a | Hypothesis |
| Every record field, offset, displacement, flag, count and name string | n/a | Unknown |
| vtordisp presence | n/a | Unknown |
| Helper names, arguments and linkage form | n/a | Hypothesis |
| Null-input check placement | n/a | Unknown |
| Private-base and ambiguity handling by the helper | Rule | Unknown |
| `std::bad_cast` thrown and caught as written | Rule | `NOT_RUN` |
| Behaviour across modules or with game binaries | Outside this fixture | Not addressed |
| Compilation succeeds without warnings at `/W4` | n/a | `NOT_RUN` |

## 5. How the hypotheses could be measured later

`COMPILE-PLAN.md` describes the only native operation proposed here: compiling
the two translation units to object files. Even that needs the coordinator's
separate review and authorization. The plan contains no step that links, runs
the fixture, or extracts RTTI from a binary. Inspecting the resulting synthetic
objects, linking and running the cases would each be a further, separately
authorized step.

To record any observation, the metadata schema would need a new, reviewed
version that can link an observed value to the exact compiler identity,
command, source hashes and output hashes. Version 1 deliberately cannot do this.

Fixture ownership preconditions: a creation target owns no live objects and must be destroyed before reuse; a positive result capacity requires a non-null buffer of at least that many entries.
