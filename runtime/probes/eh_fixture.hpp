#ifndef ORIGINAL_EH_FIXTURE_HPP
#define ORIGINAL_EH_FIXTURE_HPP
struct FixtureFailure { int stage; int payload; };
struct FixtureCounters { int base_started, base_completed, base_destroyed, body, derived_destroyed; };
extern FixtureCounters fixture_counts;
struct FixtureBase {
    explicit FixtureBase(int mode);
    ~FixtureBase();
    unsigned sentinel;
};
struct FixtureDerived : FixtureBase {
    explicit FixtureDerived(int mode);
    ~FixtureDerived();
};
void FixtureOperation(FixtureBase* object, int mode);
#endif
