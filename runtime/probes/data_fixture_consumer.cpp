#include "data_fixture.hpp"
#include <stdio.h>
extern "C" int __cdecl fixture_callback(int value) { return value * 3 + 7; }
int main() {
    const unsigned char expected[8] = {3, 17, 29, 43, 59, 71, 89, 101};
    if (fixture_payload.tag != 0x13579bdfu || fixture_payload.signed_value != -1234567 ||
        fixture_payload.numeric_address_shape != 0x00401234u || fixture_payload.tail != 0x2468ace0u) return 10;
    for (unsigned i=0; i<8; ++i) if (fixture_payload.bytes[i] != expected[i]) return 11;
    if (fixture_payload.interior != fixture_payload.bytes+2 || *fixture_payload.interior != 29) return 12;
    if (fixture_payload.callback != fixture_callback) return 13;
    for (int j=-32; j<=32; ++j) if (fixture_payload.callback(j) != j*3+7) return 14;
    for (unsigned k=0; k<8192; ++k) if (fixture_zero[k] != 0) return 15;
    for (unsigned k=0; k<8192; ++k) fixture_zero[k] = static_cast<unsigned char>((k*7+13)&255);
    for (unsigned k=0; k<8192; ++k) if (fixture_zero[k] != ((k*7+13)&255)) return 16;
    printf("{\"schema\":1,\"scalar_checks\":4,\"byte_checks\":8,\"callback_calls\":65,\"zero_checks\":8192,\"write_checks\":8192,\"interior_identity\":true}\n");
    return 0;
}
