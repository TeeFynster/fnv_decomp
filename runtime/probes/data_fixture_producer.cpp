#include "data_fixture.hpp"
extern "C" {
    int __cdecl fixture_callback(int value) { return value * 3 + 7; }
    FixturePayload fixture_payload = {
        0x13579bdfu, -1234567, {3, 17, 29, 43, 59, 71, 89, 101},
        fixture_payload.bytes + 2, fixture_callback, 0x00401234u, 0x2468ace0u
    };
    unsigned char fixture_zero[8192];
}
// This source is original fixture evidence. The producer is never executed.
int main() { return fixture_payload.callback(fixture_zero[0]); }
