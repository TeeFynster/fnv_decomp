// Synthetic RTTI ABI fixture: consumer translation unit.
//
// Performs every dynamic_cast of the case matrix on objects created by the
// producer translation unit. This file sees the class declarations but none of
// their member definitions. Several inputs require runtime type checks; literal
// null and ordinary upcasts may be folded without a runtime RTTI helper.
//
// Case ids, inputs, targets and expectations match fixture-metadata.json, and
// the tests in tests/rtti-abi check that they stay in step. expected-ABI.md
// explains each expectation.
//
// Invented code only. Not compiled or run in this delivery (NOT_RUN).

#include "rtti_abi_fixture.h"

#include <typeinfo>

namespace rtti_abi {

namespace {

struct CaseSink {
    CaseResult* results;
    int capacity;
    int count;
};

int address_changed(const void* input, const void* result)
{
    return input != result ? 1 : 0;
}

void record(CaseSink& sink, const char* id, int expected, int observed,
            int result_matches, int address_expected, int changed)
{
    bool ok = (observed == expected) && (result_matches != 0);
    if (address_expected == kAddressMustBeEqual) {
        ok = ok && (changed == 0);
    } else if (address_expected == kAddressMustDiffer) {
        ok = ok && (changed == 1);
    }

    CaseResult r;
    r.id = id;
    r.expected = expected;
    r.observed = observed;
    r.result_matches = result_matches;
    r.address_expected = address_expected;
    r.address_changed = changed;
    r.passed = ok ? 1 : 0;

    if (sink.count < sink.capacity) {
        sink.results[sink.count] = r;
    }
    ++sink.count;
}

// Pointer form that must succeed. `expected` is the producer's view of the
// subobject the result must point to.
template <class Target, class Source>
void pointer_case(CaseSink& sink, const char* id, Source* input, Target* expected,
                  int address_expected)
{
    Target* result = dynamic_cast<Target*>(input);
    if (result == 0) {
        record(sink, id, kOutcomeSuccess, kOutcomeNull, -1, address_expected, -1);
        return;
    }
    record(sink, id, kOutcomeSuccess, kOutcomeSuccess, result == expected ? 1 : 0,
           address_expected, address_changed(input, result));
}

// Pointer form that must yield a null pointer.
template <class Target, class Source>
void pointer_fail_case(CaseSink& sink, const char* id, Source* input)
{
    Target* result = dynamic_cast<Target*>(input);
    if (result == 0) {
        record(sink, id, kOutcomeNull, kOutcomeNull, -1, kAddressNotApplicable, -1);
        return;
    }
    record(sink, id, kOutcomeNull, kOutcomeSuccess, -1, kAddressNotApplicable,
           address_changed(input, result));
}

// Pointer form with a null input. The result must be null.
template <class Target, class Source>
void null_input_case(CaseSink& sink, const char* id)
{
    Source* input = 0;
    Target* result = dynamic_cast<Target*>(input);
    record(sink, id, kOutcomeNull, result == 0 ? kOutcomeNull : kOutcomeSuccess, -1,
           kAddressNotApplicable, -1);
}

// Reference form that must succeed.
template <class Target, class Source>
void reference_case(CaseSink& sink, const char* id, Source& input, Target* expected,
                    int address_expected)
{
    try {
        Target& result = dynamic_cast<Target&>(input);
        record(sink, id, kOutcomeSuccess, kOutcomeSuccess, &result == expected ? 1 : 0,
               address_expected, address_changed(&input, &result));
    } catch (const std::bad_cast&) {
        record(sink, id, kOutcomeSuccess, kOutcomeBadCast, -1, address_expected, -1);
    }
}

// Reference form that must throw std::bad_cast. The exception is thrown by the
// language runtime and caught here; it never crosses the producer/consumer
// interface.
template <class Target, class Source>
void reference_fail_case(CaseSink& sink, const char* id, Source& input)
{
    try {
        Target& result = dynamic_cast<Target&>(input);
        record(sink, id, kOutcomeBadCast, kOutcomeSuccess, -1, kAddressNotApplicable,
               address_changed(&input, &result));
    } catch (const std::bad_cast&) {
        record(sink, id, kOutcomeBadCast, kOutcomeBadCast, -1, kAddressNotApplicable, -1);
    }
}

// dynamic_cast<void*>: the result must be the address of the most derived
// object, which the producer supplies as `complete`.
template <class Source>
void void_case(CaseSink& sink, const char* id, Source* input, const void* complete,
               int address_expected)
{
    void* result = dynamic_cast<void*>(input);
    if (result == 0) {
        record(sink, id, kOutcomeSuccess, kOutcomeNull, -1, address_expected, -1);
        return;
    }
    record(sink, id, kOutcomeSuccess, kOutcomeSuccess, result == complete ? 1 : 0,
           address_expected, address_changed(input, result));
}

}  // namespace

int run_cast_cases(const FixtureObjects& o, CaseResult* results, int capacity)
{
    CaseSink sink;
    sink.results = results;
    sink.capacity = capacity < 0 ? 0 : capacity;
    sink.count = 0;

    // Single inheritance.
    pointer_case<SiLeaf>(sink, "S01", o.si_leaf.as_root, o.si_leaf.complete, kAddressLayoutDependent);
    pointer_fail_case<SiLeaf>(sink, "S02", o.si_mid.as_root);
    pointer_case<SiMid>(sink, "S03", o.si_leaf.as_root, o.si_leaf.as_mid, kAddressLayoutDependent);
    reference_fail_case<SiLeaf>(sink, "S04", *o.si_mid.as_root);
    reference_case<SiMid>(sink, "S05", *o.si_leaf.as_root, o.si_leaf.as_mid, kAddressLayoutDependent);
    null_input_case<SiLeaf, SiRoot>(sink, "S06");
    void_case(sink, "S07", o.si_leaf.as_root, o.si_leaf.complete, kAddressLayoutDependent);
    pointer_case<SiRoot>(sink, "S08", o.si_leaf.complete, o.si_leaf.as_root, kAddressLayoutDependent);

    // Multiple inheritance.
    pointer_case<MiRight>(sink, "M01", o.mi_join.as_left, o.mi_join.as_right, kAddressMustDiffer);
    pointer_case<MiLeft>(sink, "M02", o.mi_join.as_right, o.mi_join.as_left, kAddressMustDiffer);
    pointer_case<MiJoin>(sink, "M03", o.mi_join.as_right, o.mi_join.complete, kAddressLayoutDependent);
    pointer_fail_case<MiRight>(sink, "M04", o.mi_left.complete);
    reference_fail_case<MiRight>(sink, "M05", *o.mi_left.complete);
    reference_case<MiLeft>(sink, "M06", *o.mi_join.as_right, o.mi_join.as_left, kAddressMustDiffer);
    null_input_case<MiLeft, MiRight>(sink, "M07");
    void_case(sink, "M08", o.mi_join.as_right, o.mi_join.complete, kAddressLayoutDependent);
    pointer_fail_case<MiRight>(sink, "M09", o.mi_sealed.as_left);
    pointer_case<MiSealed>(sink, "M10", o.mi_sealed.as_left, o.mi_sealed.complete, kAddressLayoutDependent);

    // Virtual inheritance.
    pointer_case<ViJoin>(sink, "V01", o.vi_join.as_base_via_left, o.vi_join.complete, kAddressLayoutDependent);
    pointer_case<ViRight>(sink, "V02", o.vi_join.as_left, o.vi_join.as_right, kAddressMustDiffer);
    pointer_case<ViRight>(sink, "V03", o.vi_join.as_base_via_left, o.vi_join.as_right, kAddressLayoutDependent);
    pointer_fail_case<ViRight>(sink, "V04", o.vi_left.as_base);
    reference_fail_case<ViRight>(sink, "V05", *o.vi_left.as_base);
    reference_case<ViRight>(sink, "V06", *o.vi_join.as_left, o.vi_join.as_right, kAddressMustDiffer);
    null_input_case<ViJoin, ViBase>(sink, "V07");
    pointer_case<ViJoin>(sink, "V08", o.vi_join.as_base_via_right, o.vi_join.complete, kAddressLayoutDependent);
    void_case(sink, "V09", o.vi_join.as_base_via_right, o.vi_join.complete, kAddressLayoutDependent);

    // Ambiguity.
    pointer_fail_case<AmBase>(sink, "A01", o.am_join.as_tag);
    reference_fail_case<AmBase>(sink, "A02", *o.am_join.as_tag);
    pointer_case<AmJoin>(sink, "A03", o.am_join.as_left_base, o.am_join.complete, kAddressLayoutDependent);
    pointer_case<AmLeft>(sink, "A04", o.am_join.as_right_base, o.am_join.as_left, kAddressMustDiffer);
    pointer_case<AmLeft>(sink, "A05", o.am_join.as_tag, o.am_join.as_left, kAddressMustDiffer);

    return sink.count;
}

}  // namespace rtti_abi
