// Synthetic RTTI runtime probe: driver with main (C++03).
//
// Runs the 32 synthetic dynamic_cast cases of the RTTI ABI fixture in
// tools/rtti-abi/fixture through its public interface only, and writes one
// bounded, versioned JSON report (fnv-rtti-runtime-report v1) to standard
// output. The fixture files are used unchanged. This driver defines no fixture
// class, performs no dynamic_cast itself, allocates no fixture object and
// counts no destructor: the fixture does not expose destructor counts, so the
// report states them as "unknown".
//
// The report holds observations and the fixture's own claims, kept apart. It is
// not a verdict: tools/rtti-runtime-probe/rtti_probe_check.py compares the
// observations with an independently reviewed matrix.
//
// The report never contains a pointer value, an address, raw memory, a path, an
// environment value or an exception message. Every string written is a
// constant of this file or a case id that passed a strict format check.
//
// Usage:   rtti_probe [--cycles N]     N is 1, 2 or 3 (default 1)
//
// Exit status (deterministic; the first matching row wins):
//   6  standard output could not be written or flushed
//   5  an unexpected exception was caught in a cycle
//   4  create_fixture_objects() returned false
//   3  structure failure: wrong case count, missing, duplicate, misplaced or
//      malformed case ids, fields outside their enums, a disturbed guard
//      element, or an unexpected lifecycle observation
//   1  case failure: a result that is not self-consistent with the fixture's
//      own claims (the independent checker decides the real verdict)
//   0  every cycle completed and every case was self-consistent
//   2  usage error (nothing is written to standard output)
//
// Invented code only. Not compiled, linked or run in this delivery (NOT_RUN).

#include "rtti_abi_fixture.h"

#include <cstdio>
#include <cstring>
#include <exception>
#include <new>
#include <typeinfo>

namespace {

using rtti_abi::CaseResult;
using rtti_abi::FixtureObjects;

// Compile-time check that the fixture still declares 32 cases.
template <bool Condition> struct CompileTimeCheck;
template <> struct CompileTimeCheck<true> { enum { value = 1 }; };
enum { kCaseCountIs32 = CompileTimeCheck<rtti_abi::kCastCaseCount == 32>::value };

const int kCaseCount = rtti_abi::kCastCaseCount;
const int kMaxCycles = 3;
const int kViewCount = 24;
const int kSentinel = -1000;  // outside every allowed field value

enum ExitCode {
    kExitOk = 0,
    kExitCaseFailure = 1,
    kExitUsage = 2,
    kExitStructureFailure = 3,
    kExitCreateFailed = 4,
    kExitException = 5,
    kExitOutputError = 6
};

// The case ids in the fixture's fixed order, as reviewed in
// tools/rtti-abi/expected-ABI.md. Only ids are listed here; expectations live
// in the independent checker.
const char* const kExpectedIds[kCaseCount] = {
    "S01", "S02", "S03", "S04", "S05", "S06", "S07", "S08",
    "M01", "M02", "M03", "M04", "M05", "M06", "M07", "M08", "M09", "M10",
    "V01", "V02", "V03", "V04", "V05", "V06", "V07", "V08", "V09",
    "A01", "A02", "A03", "A04", "A05"
};

enum CycleStatus {
    kCycleIncomplete,
    kCycleCompleted,
    kCycleCreateFailed,
    kCycleViewsInvalid,
    kCycleException
};

enum ExceptionKind {
    kExceptionNone,
    kExceptionBadAlloc,
    kExceptionBadCast,
    kExceptionStd,
    kExceptionUnknown
};

enum Stage {
    kStageNone,
    kStageCreate,
    kStageRun,
    kStageDestroy
};

// One case as copied out of the fixture's CaseResult. The id is copied into
// local storage only after it passed the format check.
struct CaseRecord {
    bool id_valid;
    char id[4];
    int expected;
    int observed;
    int result_matches;
    int address_expected;
    int address_changed;
    int passed;
};

struct CycleRecord {
    int number;
    CycleStatus status;
    ExceptionKind exception_kind;
    Stage exception_stage;
    bool views_null_before_create;
    int create_calls;
    bool create_returned;
    bool views_all_set_after_create;
    int run_calls;
    int run_returned;  // -1 when run_cast_cases() was not called
    bool guard_intact;
    int destroy_calls;
    bool views_null_at_end;
    int case_count;    // entries copied into `cases`
    CaseRecord cases[kCaseCount];
};

// ------------------------------------------------------------------ views

// Sets every pointer of a FixtureObjects to null, so the record owns nothing.
void clear_views(FixtureObjects& o)
{
    o.si_leaf.complete = 0;
    o.si_leaf.as_mid = 0;
    o.si_leaf.as_root = 0;
    o.si_mid.complete = 0;
    o.si_mid.as_root = 0;
    o.mi_join.complete = 0;
    o.mi_join.as_left = 0;
    o.mi_join.as_right = 0;
    o.mi_left.complete = 0;
    o.mi_sealed.complete = 0;
    o.mi_sealed.as_left = 0;
    o.vi_join.complete = 0;
    o.vi_join.as_left = 0;
    o.vi_join.as_right = 0;
    o.vi_join.as_base_via_left = 0;
    o.vi_join.as_base_via_right = 0;
    o.vi_left.complete = 0;
    o.vi_left.as_base = 0;
    o.am_join.complete = 0;
    o.am_join.as_left = 0;
    o.am_join.as_right = 0;
    o.am_join.as_tag = 0;
    o.am_join.as_left_base = 0;
    o.am_join.as_right_base = 0;
}

// Copies every view pointer for null tests only. Values are never printed.
void list_views(const FixtureObjects& o, const void* views[kViewCount])
{
    int i = 0;
    views[i++] = o.si_leaf.complete;
    views[i++] = o.si_leaf.as_mid;
    views[i++] = o.si_leaf.as_root;
    views[i++] = o.si_mid.complete;
    views[i++] = o.si_mid.as_root;
    views[i++] = o.mi_join.complete;
    views[i++] = o.mi_join.as_left;
    views[i++] = o.mi_join.as_right;
    views[i++] = o.mi_left.complete;
    views[i++] = o.mi_sealed.complete;
    views[i++] = o.mi_sealed.as_left;
    views[i++] = o.vi_join.complete;
    views[i++] = o.vi_join.as_left;
    views[i++] = o.vi_join.as_right;
    views[i++] = o.vi_join.as_base_via_left;
    views[i++] = o.vi_join.as_base_via_right;
    views[i++] = o.vi_left.complete;
    views[i++] = o.vi_left.as_base;
    views[i++] = o.am_join.complete;
    views[i++] = o.am_join.as_left;
    views[i++] = o.am_join.as_right;
    views[i++] = o.am_join.as_tag;
    views[i++] = o.am_join.as_left_base;
    views[i++] = o.am_join.as_right_base;
}

int count_null_views(const FixtureObjects& o)
{
    const void* views[kViewCount];
    list_views(o, views);
    int nulls = 0;
    for (int i = 0; i < kViewCount; ++i) {
        if (views[i] == 0) {
            ++nulls;
        }
    }
    return nulls;
}

bool all_views_null(const FixtureObjects& o)
{
    return count_null_views(o) == kViewCount;
}

bool all_views_set(const FixtureObjects& o)
{
    return count_null_views(o) == 0;
}

// ------------------------------------------------------------------ guard

// Owns the fixture objects of one cycle. create() calls
// create_fixture_objects() at most once in the guard's lifetime. release()
// calls destroy_fixture_objects() at most once, and only if the guard owns
// objects; ownership is cleared before the call, so the objects can never be
// destroyed twice. The destructor releases on every exit path, including
// exceptions.
//
// Creation failure: when create_fixture_objects() returns false it has already
// destroyed what it made and nulled every view, so the guard owns nothing and
// destroy_fixture_objects() is not called. If it were to throw despite its
// contract, the guard keeps ownership, so the objects whose complete pointers
// were stored are still destroyed once.
class FixtureGuard {
public:
    FixtureGuard(FixtureObjects& objects, int& create_calls, int& destroy_calls)
        : objects_(objects),
          create_calls_(create_calls),
          destroy_calls_(destroy_calls),
          attempted_(false),
          owned_(false)
    {
    }

    ~FixtureGuard()
    {
        release();
    }

    bool create()
    {
        if (attempted_) {
            return false;
        }
        attempted_ = true;
        ++create_calls_;
        owned_ = true;
        const bool created = rtti_abi::create_fixture_objects(objects_);
        owned_ = created;
        return created;
    }

    void release()
    {
        if (!owned_) {
            return;
        }
        owned_ = false;
        ++destroy_calls_;
        rtti_abi::destroy_fixture_objects(objects_);
    }

private:
    FixtureGuard(const FixtureGuard&);             // not copyable
    FixtureGuard& operator=(const FixtureGuard&);  // not assignable

    FixtureObjects& objects_;
    int& create_calls_;
    int& destroy_calls_;
    bool attempted_;
    bool owned_;
};

// ------------------------------------------------------------------ cases

void fill_sentinel(CaseResult& r)
{
    r.id = 0;
    r.expected = kSentinel;
    r.observed = kSentinel;
    r.result_matches = kSentinel;
    r.address_expected = kSentinel;
    r.address_changed = kSentinel;
    r.passed = kSentinel;
}

bool is_sentinel(const CaseResult& r)
{
    return r.id == 0 && r.expected == kSentinel && r.observed == kSentinel &&
           r.result_matches == kSentinel && r.address_expected == kSentinel &&
           r.address_changed == kSentinel && r.passed == kSentinel;
}

// Exactly one upper-case letter, two digits and the terminator. Reads stop at
// the first character that fails, so no byte past a terminator is read.
bool valid_id(const char* id)
{
    return id != 0 && id[0] >= 'A' && id[0] <= 'Z' && id[1] >= '0' && id[1] <= '9' &&
           id[2] >= '0' && id[2] <= '9' && id[3] == '\0';
}

bool in_range(int value, int low, int high)
{
    return value >= low && value <= high;
}

bool case_fields_ok(const CaseRecord& c)
{
    return c.id_valid &&
           in_range(c.expected, rtti_abi::kOutcomeSuccess, rtti_abi::kOutcomeBadCast) &&
           in_range(c.observed, rtti_abi::kOutcomeNotRun, rtti_abi::kOutcomeBadCast) &&
           in_range(c.result_matches, -1, 1) &&
           in_range(c.address_expected, rtti_abi::kAddressNotApplicable,
                    rtti_abi::kAddressMustDiffer) &&
           in_range(c.address_changed, -1, 1) &&
           in_range(c.passed, 0, 1);
}

// Self-consistency with the fixture's own claims only. kOutcomeNotRun never
// passes, and result_matches == -1 never counts as proof of success.
bool case_self_consistent(const CaseRecord& c)
{
    if (c.observed == rtti_abi::kOutcomeNotRun || c.observed != c.expected || c.passed != 1) {
        return false;
    }
    if (c.expected == rtti_abi::kOutcomeSuccess) {
        if (c.result_matches != 1) {
            return false;
        }
        if (c.address_expected == rtti_abi::kAddressMustBeEqual) {
            return c.address_changed == 0;
        }
        if (c.address_expected == rtti_abi::kAddressMustDiffer) {
            return c.address_changed == 1;
        }
        if (c.address_expected == rtti_abi::kAddressLayoutDependent) {
            return c.address_changed == 0 || c.address_changed == 1;
        }
        return false;
    }
    return c.result_matches == -1 && c.address_changed == -1 &&
           c.address_expected == rtti_abi::kAddressNotApplicable;
}

void copy_cases(const CaseResult* results, CycleRecord& record)
{
    int stored = record.run_returned;
    if (stored > kCaseCount) {
        stored = kCaseCount;
    }
    if (stored < 0) {
        stored = 0;
    }
    for (int i = 0; i < stored; ++i) {
        const CaseResult& r = results[i];
        CaseRecord& c = record.cases[i];
        c.id_valid = valid_id(r.id);
        if (c.id_valid) {
            c.id[0] = r.id[0];
            c.id[1] = r.id[1];
            c.id[2] = r.id[2];
        } else {
            c.id[0] = '\0';
            c.id[1] = '\0';
            c.id[2] = '\0';
        }
        c.id[3] = '\0';
        c.expected = r.expected;
        c.observed = r.observed;
        c.result_matches = r.result_matches;
        c.address_expected = r.address_expected;
        c.address_changed = r.address_changed;
        c.passed = r.passed;
    }
    record.case_count = stored;
}

// ------------------------------------------------------------------ cycles

void reset_record(int number, CycleRecord& record)
{
    record.number = number;
    record.status = kCycleIncomplete;
    record.exception_kind = kExceptionNone;
    record.exception_stage = kStageNone;
    record.views_null_before_create = false;
    record.create_calls = 0;
    record.create_returned = false;
    record.views_all_set_after_create = false;
    record.run_calls = 0;
    record.run_returned = -1;
    record.guard_intact = false;
    record.destroy_calls = 0;
    record.views_null_at_end = false;
    record.case_count = 0;
}

void note_exception(CycleRecord& record, ExceptionKind kind, Stage stage)
{
    if (record.status == kCycleException) {
        return;  // keep the first exception
    }
    record.status = kCycleException;
    record.exception_kind = kind;
    record.exception_stage = stage;
}

// One fresh cycle: fresh FixtureObjects, one create, one run with capacity 32,
// one destroy. Every exception is caught here; the guard destroys the objects
// on every path after a successful creation.
void run_cycle(int number, CycleRecord& record)
{
    reset_record(number, record);

    FixtureObjects objects;
    clear_views(objects);
    record.views_null_before_create = all_views_null(objects);

    // One guard element past the capacity detects writes beyond it.
    CaseResult results[kCaseCount + 1];
    for (int i = 0; i < kCaseCount + 1; ++i) {
        fill_sentinel(results[i]);
    }

    Stage stage = kStageNone;
    {
        FixtureGuard guard(objects, record.create_calls, record.destroy_calls);
        try {
            stage = kStageCreate;
            record.create_returned = guard.create();
            if (!record.create_returned) {
                record.status = kCycleCreateFailed;
            } else {
                record.views_all_set_after_create = all_views_set(objects);
                if (!record.views_all_set_after_create) {
                    stage = kStageDestroy;
                    guard.release();
                    record.status = kCycleViewsInvalid;
                } else {
                    stage = kStageRun;
                    ++record.run_calls;
                    record.run_returned =
                        rtti_abi::run_cast_cases(objects, results, kCaseCount);
                    stage = kStageDestroy;
                    guard.release();
                    record.status = kCycleCompleted;
                }
            }
        } catch (const std::bad_alloc&) {
            note_exception(record, kExceptionBadAlloc, stage);
        } catch (const std::bad_cast&) {
            note_exception(record, kExceptionBadCast, stage);
        } catch (const std::exception&) {
            note_exception(record, kExceptionStd, stage);
        } catch (...) {
            note_exception(record, kExceptionUnknown, stage);
        }

        // Normally a no-op: release() was called above unless an exception
        // skipped it. It is retried here, outside the first handler.
        try {
            guard.release();
        } catch (...) {
            note_exception(record, kExceptionUnknown, kStageDestroy);
        }
    }  // ~FixtureGuard(): nothing left to release

    record.views_null_at_end = all_views_null(objects);
    record.guard_intact = is_sentinel(results[kCaseCount]);
    copy_cases(results, record);
}

bool cycle_structure_ok(const CycleRecord& r)
{
    if (r.status != kCycleCompleted || !r.views_null_before_create || r.create_calls != 1 ||
        !r.create_returned || !r.views_all_set_after_create || r.run_calls != 1 ||
        r.run_returned != kCaseCount || !r.guard_intact || r.destroy_calls != 1 ||
        !r.views_null_at_end || r.case_count != kCaseCount) {
        return false;
    }
    for (int i = 0; i < kCaseCount; ++i) {
        const CaseRecord& c = r.cases[i];
        if (!case_fields_ok(c) || std::strcmp(c.id, kExpectedIds[i]) != 0) {
            return false;
        }
    }
    return true;
}

// Mirrored by driver_status() in rtti_probe_check.py, which recomputes it from
// the report and rejects a report whose stated status does not follow.
int overall_exit(const CycleRecord* records, int attempted, int requested)
{
    bool saw_exception = false;
    bool create_failed = false;
    bool structure = attempted < requested;
    bool case_failure = false;
    for (int i = 0; i < attempted; ++i) {
        const CycleRecord& r = records[i];
        if (r.status == kCycleException) {
            saw_exception = true;
        } else if (r.status == kCycleCreateFailed) {
            create_failed = true;
        } else if (!cycle_structure_ok(r)) {
            structure = true;
        } else {
            for (int k = 0; k < r.case_count; ++k) {
                if (!case_self_consistent(r.cases[k])) {
                    case_failure = true;
                }
            }
        }
    }
    if (saw_exception) {
        return kExitException;
    }
    if (create_failed) {
        return kExitCreateFailed;
    }
    if (structure) {
        return kExitStructureFailure;
    }
    if (case_failure) {
        return kExitCaseFailure;
    }
    return kExitOk;
}

// ------------------------------------------------------------------ names

const char* status_name(CycleStatus status)
{
    switch (status) {
    case kCycleCompleted:
        return "completed";
    case kCycleCreateFailed:
        return "create_failed";
    case kCycleViewsInvalid:
        return "views_invalid";
    case kCycleException:
        return "exception";
    case kCycleIncomplete:
        break;
    }
    return "incomplete";
}

const char* exception_name(ExceptionKind kind)
{
    switch (kind) {
    case kExceptionBadAlloc:
        return "bad_alloc";
    case kExceptionBadCast:
        return "bad_cast";
    case kExceptionStd:
        return "std_exception";
    case kExceptionUnknown:
        return "unknown";
    case kExceptionNone:
        break;
    }
    return "none";
}

const char* stage_name(Stage stage)
{
    switch (stage) {
    case kStageCreate:
        return "create";
    case kStageRun:
        return "run";
    case kStageDestroy:
        return "destroy";
    case kStageNone:
        break;
    }
    return "none";
}

const char* driver_status_name(int exit_code)
{
    switch (exit_code) {
    case kExitOk:
        return "ok";
    case kExitCaseFailure:
        return "case_failure";
    case kExitStructureFailure:
        return "structure_failure";
    case kExitCreateFailed:
        return "create_failed";
    default:
        break;
    }
    return "exception";
}

// ------------------------------------------------------------------ output

// Writes only constant text, validated ids, integers and booleans. Any failed
// write or flush is remembered and turns into exit status 6.
class Writer {
public:
    explicit Writer(std::FILE* out) : out_(out), ok_(out != 0) {}

    void raw(const char* text)
    {
        if (ok_ && std::fputs(text, out_) < 0) {
            ok_ = false;
        }
    }

    void key(const char* name)
    {
        raw("\"");
        raw(name);
        raw("\": ");
    }

    void text(const char* value)
    {
        raw("\"");
        raw(value);
        raw("\"");
    }

    void boolean(bool value)
    {
        raw(value ? "true" : "false");
    }

    void number(int value)
    {
        char buffer[16];
        int pos = 15;
        buffer[pos] = '\0';
        unsigned int magnitude = value < 0 ? 0u - static_cast<unsigned int>(value)
                                           : static_cast<unsigned int>(value);
        do {
            buffer[--pos] = static_cast<char>('0' + static_cast<int>(magnitude % 10u));
            magnitude /= 10u;
        } while (magnitude != 0u);
        if (value < 0) {
            buffer[--pos] = '-';
        }
        raw(buffer + pos);
    }

    bool finish()
    {
        if (ok_ && std::fflush(out_) != 0) {
            ok_ = false;
        }
        if (ok_ && std::ferror(out_) != 0) {
            ok_ = false;
        }
        return ok_;
    }

private:
    Writer(const Writer&);
    Writer& operator=(const Writer&);

    std::FILE* out_;
    bool ok_;
};

void write_case(Writer& w, const CaseRecord& c, bool last)
{
    w.raw("        {");
    w.key("id");
    if (c.id_valid) {
        w.text(c.id);
    } else {
        w.raw("null");
    }
    w.raw(", ");
    w.key("fixture_claims");
    w.raw("{");
    w.key("expected");
    w.number(c.expected);
    w.raw(", ");
    w.key("address_expected");
    w.number(c.address_expected);
    w.raw(", ");
    w.key("passed");
    w.number(c.passed);
    w.raw("}, ");
    w.key("observed");
    w.raw("{");
    w.key("outcome");
    w.number(c.observed);
    w.raw(", ");
    w.key("result_matches");
    w.number(c.result_matches);
    w.raw(", ");
    w.key("address_changed");
    w.number(c.address_changed);
    w.raw("}}");
    w.raw(last ? "\n" : ",\n");
}

void write_cycle(Writer& w, const CycleRecord& r, bool last)
{
    w.raw("    {\n      ");
    w.key("cycle");
    w.number(r.number);
    w.raw(",\n      ");
    w.key("status");
    w.text(status_name(r.status));
    w.raw(",\n      ");
    w.key("exception_kind");
    w.text(exception_name(r.exception_kind));
    w.raw(",\n      ");
    w.key("exception_stage");
    w.text(stage_name(r.exception_stage));
    w.raw(",\n      ");
    w.key("views_null_before_create");
    w.boolean(r.views_null_before_create);
    w.raw(",\n      ");
    w.key("create_calls");
    w.number(r.create_calls);
    w.raw(",\n      ");
    w.key("create_returned");
    w.boolean(r.create_returned);
    w.raw(",\n      ");
    w.key("views_all_set_after_create");
    w.boolean(r.views_all_set_after_create);
    w.raw(",\n      ");
    w.key("run_calls");
    w.number(r.run_calls);
    w.raw(",\n      ");
    w.key("run_capacity");
    w.number(kCaseCount);
    w.raw(",\n      ");
    w.key("run_returned");
    w.number(r.run_returned);
    w.raw(",\n      ");
    w.key("guard_intact");
    w.boolean(r.guard_intact);
    w.raw(",\n      ");
    w.key("destroy_calls");
    w.number(r.destroy_calls);
    w.raw(",\n      ");
    w.key("views_null_at_end");
    w.boolean(r.views_null_at_end);
    w.raw(",\n      ");
    w.key("destructor_count");
    w.text("unknown");
    w.raw(",\n      ");
    w.key("cases");
    if (r.case_count == 0) {
        w.raw("[]\n");
    } else {
        w.raw("[\n");
        for (int i = 0; i < r.case_count; ++i) {
            write_case(w, r.cases[i], i + 1 == r.case_count);
        }
        w.raw("      ]\n");
    }
    w.raw(last ? "    }\n" : "    },\n");
}

void write_report(Writer& w, int requested, const CycleRecord* records, int attempted,
                  int exit_code)
{
    w.raw("{\n  ");
    w.key("schema");
    w.text("fnv-rtti-runtime-report");
    w.raw(",\n  ");
    w.key("schema_version");
    w.number(1);
    w.raw(",\n  ");
    w.key("origin");
    w.text("driver");
    w.raw(",\n  ");
    w.key("fixture");
    w.text("rtti_abi_fixture_v1");
    w.raw(",\n  ");
    w.key("case_count_constant");
    w.number(kCaseCount);
    w.raw(",\n  ");
    w.key("cycles_requested");
    w.number(requested);
    w.raw(",\n  ");
    w.key("cycles");
    if (attempted == 0) {
        w.raw("[]");
    } else {
        w.raw("[\n");
        for (int i = 0; i < attempted; ++i) {
            write_cycle(w, records[i], i + 1 == attempted);
        }
        w.raw("  ]");
    }
    w.raw(",\n  ");
    w.key("driver_status");
    w.text(driver_status_name(exit_code));
    w.raw(",\n  ");
    w.key("driver_exit_code");
    w.number(exit_code);
    w.raw(",\n  ");
    w.key("end_of_report");
    w.boolean(true);
    w.raw("\n}\n");
}

// ------------------------------------------------------------------ main

// Accepts no arguments, or exactly "--cycles" followed by "1", "2" or "3".
// Argument text is never echoed.
bool parse_arguments(int argc, char** argv, int& cycles)
{
    cycles = 1;
    if (argc == 1) {
        return true;
    }
    if (argc != 3 || argv[1] == 0 || argv[2] == 0 || std::strcmp(argv[1], "--cycles") != 0) {
        return false;
    }
    const char* n = argv[2];
    if (n[0] < '1' || n[0] > '0' + kMaxCycles || n[1] != '\0') {
        return false;
    }
    cycles = n[0] - '0';
    return true;
}

}  // namespace

int main(int argc, char** argv)
{
    int requested = 1;
    if (!parse_arguments(argc, argv, requested)) {
        std::fputs("usage: rtti_probe [--cycles 1|2|3]\n", stderr);
        return kExitUsage;
    }

    CycleRecord records[kMaxCycles];
    int attempted = 0;
    try {
        for (int i = 0; i < requested; ++i) {
            run_cycle(i + 1, records[i]);
            ++attempted;
            if (records[i].status != kCycleCompleted) {
                break;  // no further cycle after a lifecycle failure
            }
        }
    } catch (...) {
        // run_cycle() catches everything itself; this is a backstop only.
        std::fputs("rtti_probe: internal error; no report written\n", stderr);
        return kExitException;
    }

    const int exit_code = overall_exit(records, attempted, requested);
    Writer w(stdout);
    write_report(w, requested, records, attempted, exit_code);
    if (!w.finish()) {
        return kExitOutputError;
    }
    return exit_code;
}
