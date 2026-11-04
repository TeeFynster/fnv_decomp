#include "eh_fixture.hpp"
FixtureCounters fixture_counts = {0,0,0,0,0};
FixtureBase::FixtureBase(int mode) : sentinel(0x1234abcdU) {
    ++fixture_counts.base_started;
    if (mode == 2) { FixtureFailure f = {2, 202}; throw f; }
    ++fixture_counts.base_completed;
}
FixtureBase::~FixtureBase() {
    if (sentinel != 0x1234abcdU) fixture_counts.base_destroyed += 1000000;
    ++fixture_counts.base_destroyed;
    sentinel = 0;
}
FixtureDerived::~FixtureDerived() { ++fixture_counts.derived_destroyed; }
void FixtureOperation(FixtureBase* object, int mode) {
    ++fixture_counts.body;
    if (object->sentinel != 0x1234abcdU) { FixtureFailure f = {9, 909}; throw f; }
    if (mode == 1) { FixtureFailure f = {1, 101}; throw f; }
}
