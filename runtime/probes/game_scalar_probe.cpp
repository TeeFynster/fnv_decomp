// Original caller for one separately retained scalar function; no game assets.
#include <windows.h>
#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include "scalar_goldens.hpp"

float __cdecl GetWeaponHealthConditionMultiplier(float value);
union ScalarBits { unsigned bits; float value; };
typedef char ScalarLayout[(sizeof(float)==4 && sizeof(unsigned)==4) ? 1 : -1];

int main() {
    SetErrorMode(SEM_FAILCRITICALERRORS | SEM_NOGPFAULTERRORBOX | SEM_NOOPENFILEERRORBOX);
    _set_error_mode(_OUT_TO_STDERR);
    const unsigned before = _control87(0, 0);
    if (before != _CW_DEFAULT) {
        printf("{\"status\":\"unsupported_x87\",\"observed\":%u,\"expected\":%u}\n", before, (unsigned)_CW_DEFAULT);
        return 20;
    }
    volatile unsigned sentinels[4] = {0x13579bdfu, 0x2468ace0u, 0x31415926u, 0x27182818u};
    unsigned calls = 0;
    for (unsigned round=0; round<1024; ++round) {
        for (unsigned i=0; i<scalar_case_count; ++i) {
            ScalarBits input, result;
            input.bits = scalar_cases[i].input;
            result.value = GetWeaponHealthConditionMultiplier(input.value);
            ++calls;
            if (result.bits != scalar_cases[i].expected || input.bits != scalar_cases[i].input ||
                sentinels[0] != 0x13579bdfu || sentinels[1] != 0x2468ace0u ||
                sentinels[2] != 0x31415926u || sentinels[3] != 0x27182818u) {
                printf("{\"status\":\"assertion_failed\",\"round\":%u,\"case\":%u,\"observed_bits\":%u,\"expected_bits\":%u}\n",
                       round, i, result.bits, scalar_cases[i].expected);
                return 21;
            }
        }
    }
    const unsigned after = _control87(0, 0);
    if (after != before) return 22;
    printf("{\"schema\":1,\"cases\":%u,\"rounds\":1024,\"calls\":%u,\"sentinels_ok\":true,\"x87_before\":%u,\"x87_after\":%u}\n",
           scalar_case_count, calls, before, after);
    return 0;
}
