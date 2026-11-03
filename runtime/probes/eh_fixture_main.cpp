#include "eh_fixture.hpp"
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
int main() {
    SetErrorMode(SEM_FAILCRITICALERRORS | SEM_NOGPFAULTERRORBOX | SEM_NOOPENFILEERRORBOX);
    _set_error_mode(_OUT_TO_STDERR);
    _set_abort_behavior(0, _WRITE_ABORT_MSG | _CALL_REPORTFAULT);
    int caught = 0, resumed = 0, ok = 1;
    const int rounds = 1024;
    for (int i=0; i<rounds; ++i) {
        for (int mode=0; mode<3; ++mode) {
            fixture_counts = FixtureCounters();
            volatile unsigned before = 0xabcdef12U;
            try {
                FixtureDerived object(mode);
                if (mode != 0 || object.sentinel != 0x1234abcdU) ok = 0;
            } catch (const FixtureFailure& failure) {
                ++caught;
                if (failure.stage != mode || failure.payload != (mode==1 ? 101 : 202)) ok = 0;
            } catch (...) { ok = 0; }
            if (before != 0xabcdef12U) ok = 0;
            ++resumed;
            if (fixture_counts.base_started != 1 ||
                fixture_counts.base_completed != (mode!=2) ||
                fixture_counts.base_destroyed != (mode!=2) ||
                fixture_counts.body != (mode!=2) ||
                fixture_counts.derived_destroyed != (mode==0)) ok = 0;
        }
    }
    if (caught != rounds*2 || resumed != rounds*3) ok=0;
    printf("{\"schema\":1,\"rounds\":1024,\"caught\":%d,\"resumed\":%d,\"checks_ok\":%d}\n", caught, resumed, ok);
    return ok ? 0 : 1;
}
