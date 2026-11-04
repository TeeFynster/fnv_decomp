// Synthetic RTTI ABI fixture: shared declarations.
//
// Every class here is invented for this fixture. Nothing is taken from a game,
// a game address or a disassembly. The code is meant to be compiled as C++03
// by Microsoft Visual C++ 2008 SP1 for x86 with RTTI (/GR) and synchronous C++
// exceptions (/EHsc). It has not been compiled: see COMPILE-PLAN.md.
//
// Translation units:
//   rtti_producer.cpp  defines every constructor, destructor and virtual
//                      function, and creates and destroys the fixture objects.
//   rtti_consumer.cpp  sees only these declarations. It receives objects
//                      through FixtureObjects and performs every dynamic_cast.
//
// The fixture uses only language-level dynamic_cast. It contains no
// hand-written RTTI records, no direct call of a runtime cast helper, no
// assembly and no fixed address or offset.

#ifndef RTTI_ABI_FIXTURE_H
#define RTTI_ABI_FIXTURE_H

namespace rtti_abi {

// ---------------------------------------------------------------------------
// Single inheritance: SiLeaf -> SiMid -> SiRoot.

class SiRoot {
public:
    SiRoot();
    virtual ~SiRoot();
    virtual int depth() const;
    int root_value;
};

class SiMid : public SiRoot {
public:
    SiMid();
    virtual ~SiMid();
    virtual int depth() const;
    int mid_value;
};

class SiLeaf : public SiMid {
public:
    SiLeaf();
    virtual ~SiLeaf();
    virtual int depth() const;
    int leaf_value;
};

// ---------------------------------------------------------------------------
// Multiple (non-virtual) inheritance. MiLeft and MiRight are unrelated
// polymorphic classes. In MiJoin both are public bases. In MiSealed, MiRight is
// a private base, so a run-time cross-cast to it must fail.

class MiLeft {
public:
    MiLeft();
    virtual ~MiLeft();
    virtual int left_value() const;
    int left_data;
};

class MiRight {
public:
    MiRight();
    virtual ~MiRight();
    virtual int right_value() const;
    int right_data;
};

class MiJoin : public MiLeft, public MiRight {
public:
    MiJoin();
    virtual ~MiJoin();
    virtual int left_value() const;
    virtual int right_value() const;
    int join_data;
};

class MiSealed : public MiLeft, private MiRight {
public:
    MiSealed();
    virtual ~MiSealed();
    int sealed_data;
};

// ---------------------------------------------------------------------------
// Virtual inheritance (a diamond). ViJoin holds exactly one ViBase subobject,
// shared by its ViLeft and ViRight parts. Only destructors are overridden
// below ViBase, so every virtual function has a unique final overrider.

class ViBase {
public:
    ViBase();
    virtual ~ViBase();
    virtual int base_value() const;
    int base_data;
};

class ViLeft : public virtual ViBase {
public:
    ViLeft();
    virtual ~ViLeft();
    int left_data;
};

class ViRight : public virtual ViBase {
public:
    ViRight();
    virtual ~ViRight();
    int right_data;
};

class ViJoin : public ViLeft, public ViRight {
public:
    ViJoin();
    virtual ~ViJoin();
    int join_data;
};

// ---------------------------------------------------------------------------
// Ambiguity: AmJoin holds two distinct AmBase subobjects (one in AmLeft, one
// in AmRight) and an unrelated AmTag base. A run-time cast from AmTag to AmBase
// is ambiguous and must fail.

class AmBase {
public:
    AmBase();
    virtual ~AmBase();
    int base_data;
};

class AmLeft : public AmBase {
public:
    AmLeft();
    virtual ~AmLeft();
    int left_data;
};

class AmRight : public AmBase {
public:
    AmRight();
    virtual ~AmRight();
    int right_data;
};

class AmTag {
public:
    AmTag();
    virtual ~AmTag();
    int tag_data;
};

class AmJoin : public AmLeft, public AmRight, public AmTag {
public:
    AmJoin();
    virtual ~AmJoin();
    int join_data;
};

// ---------------------------------------------------------------------------
// Views. For each fixture object the producer stores the complete-object
// pointer and the base-class pointers obtained from it by ordinary implicit
// (static) derived-to-base conversion. The consumer uses one view as the cast
// input and compares the cast result with another view. No address arithmetic
// is used anywhere.

struct SiLeafViews {
    SiLeaf* complete;
    SiMid* as_mid;
    SiRoot* as_root;
};

struct SiMidViews {
    SiMid* complete;
    SiRoot* as_root;
};

struct MiJoinViews {
    MiJoin* complete;
    MiLeft* as_left;
    MiRight* as_right;
};

struct MiLeftViews {
    MiLeft* complete;
};

struct MiSealedViews {
    MiSealed* complete;
    MiLeft* as_left;  // MiRight is private here, so no MiRight view exists.
};

struct ViJoinViews {
    ViJoin* complete;
    ViLeft* as_left;
    ViRight* as_right;
    ViBase* as_base_via_left;   // ViJoin -> ViLeft -> ViBase
    ViBase* as_base_via_right;  // ViJoin -> ViRight -> ViBase (same subobject)
};

struct ViLeftViews {
    ViLeft* complete;
    ViBase* as_base;
};

struct AmJoinViews {
    AmJoin* complete;
    AmLeft* as_left;
    AmRight* as_right;
    AmTag* as_tag;
    AmBase* as_left_base;   // AmJoin -> AmLeft -> AmBase
    AmBase* as_right_base;  // AmJoin -> AmRight -> AmBase (a different subobject)
};

struct FixtureObjects {
    SiLeafViews si_leaf;
    SiMidViews si_mid;
    MiJoinViews mi_join;
    MiLeftViews mi_left;
    MiSealedViews mi_sealed;
    ViJoinViews vi_join;
    ViLeftViews vi_left;
    AmJoinViews am_join;
};

// ---------------------------------------------------------------------------
// Producer interface (rtti_producer.cpp).
//
// Lifetime contract:
//   - Pass a fresh record that owns no live objects. Do not reuse a successful
//     record until destroy_fixture_objects() has been called.
//   - create_fixture_objects() first sets every pointer in `out` to null. It
//     then allocates each object with new. On success it returns true and every
//     pointer is valid. If an allocation throws std::bad_alloc, it destroys the
//     objects created so far, leaves every pointer null and returns false. No
//     exception leaves this function.
//   - The pointers stay valid until destroy_fixture_objects() is called on the
//     same FixtureObjects. That function deletes each object through its
//     complete-object pointer and sets every pointer to null. Calling it on an
//     all-null FixtureObjects does nothing.
//   - The consumer never deletes, retains or creates fixture objects.

bool create_fixture_objects(FixtureObjects& out);
void destroy_fixture_objects(FixtureObjects& objects);

// ---------------------------------------------------------------------------
// Consumer interface (rtti_consumer.cpp).

enum Outcome {
    kOutcomeNotRun = 0,
    kOutcomeSuccess = 1,   // non-null pointer, or a reference was bound
    kOutcomeNull = 2,      // pointer form returned null
    kOutcomeBadCast = 3    // reference form threw std::bad_cast
};

// What the case expects of the address of the result compared with the
// address of the input. Only the first two are guaranteed by C++; see
// expected-ABI.md.
enum AddressExpectation {
    kAddressNotApplicable = -2,  // failure, or null input
    kAddressLayoutDependent = -1, // C++ does not decide; recorded only
    kAddressMustBeEqual = 0,     // the result is the input subobject itself
    kAddressMustDiffer = 1       // disjoint, non-empty subobjects
};

struct CaseResult {
    const char* id;          // matches a cast id in fixture-metadata.json
    int expected;            // Outcome required by the C++ rules
    int observed;            // Outcome seen when the case ran
    int result_matches;      // 1 or 0: result equals the expected view; -1: n/a
    int address_expected;    // AddressExpectation
    int address_changed;     // 1 or 0: result address differs from input; -1: n/a
    int passed;              // 1 if every applicable check held
};

enum { kCastCaseCount = 32 };

// Precondition: `objects` came from a successful create_fixture_objects() and
// has not been destroyed. If capacity is positive, results must point to an
// array with at least capacity CaseResult elements; otherwise it may be null.
// Runs every case in a fixed order and writes at most
// `capacity` results. Returns kCastCaseCount; if that is larger than
// `capacity`, the extra results were not stored. Only std::bad_cast is caught,
// and only inside a reference case. The function allocates and frees nothing
// itself.
int run_cast_cases(const FixtureObjects& objects, CaseResult* results, int capacity);

}  // namespace rtti_abi

#endif  // RTTI_ABI_FIXTURE_H
