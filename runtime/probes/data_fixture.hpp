#ifndef ORIGINAL_DATA_FIXTURE_HPP
#define ORIGINAL_DATA_FIXTURE_HPP
#include <stddef.h>
typedef int (__cdecl *FixtureCallback)(int);
struct FixturePayload {
    unsigned tag;
    int signed_value;
    unsigned char bytes[8];
    const unsigned char* interior;
    FixtureCallback callback;
    unsigned numeric_address_shape;
    unsigned tail;
};
typedef char FixtureLayout[(sizeof(FixturePayload)==32 && sizeof(void*)==4 &&
    offsetof(FixturePayload, interior)==16 && offsetof(FixturePayload, callback)==20 &&
    offsetof(FixturePayload, numeric_address_shape)==24 && offsetof(FixturePayload, tail)==28) ? 1 : -1];
extern "C" {
    extern FixturePayload fixture_payload;
    extern unsigned char fixture_zero[8192];
    int __cdecl fixture_callback(int value);
}
#endif
