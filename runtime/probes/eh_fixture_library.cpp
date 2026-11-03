#include "eh_fixture.hpp"
FixtureDerived::FixtureDerived(int mode) : FixtureBase(mode) {
    FixtureOperation(this, mode);
}
extern void FixtureUnresolvedSentinel();
void FixtureUnrelated() { FixtureUnresolvedSentinel(); }
