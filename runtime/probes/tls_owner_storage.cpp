#include "tls_owner_fixture.hpp"
#include <intrin.h>
#pragma intrinsic(__readfsdword)

__declspec(thread) __declspec(align(4)) FixtureTlsStorage fixture_tls = {{0}, 1, {0}, 37, {0}};

unsigned char* FixtureModuleBlock() {
    // Source intrinsic, not handwritten assembly. The constant is independently
    // checked against the selected normal CRT's absolute __tls_array provider.
    void** modules = reinterpret_cast<void**>(__readfsdword(0x2c));
    return static_cast<unsigned char*>(modules[_tls_index]);
}

bool FixtureInitialState() {
    for (unsigned i=0; i<sizeof(fixture_tls.reserved_prefix); ++i)
        if (fixture_tls.reserved_prefix[i]) return false;
    for (unsigned i=0; i<sizeof(fixture_tls.reserved_middle); ++i)
        if (fixture_tls.reserved_middle[i]) return false;
    for (unsigned i=0; i<sizeof(fixture_tls.reserved_tail); ++i)
        if (fixture_tls.reserved_tail[i]) return false;
    unsigned char* block = FixtureModuleBlock();
    return block && !block[0] && !block[1] && !block[2] && !block[3] &&
        fixture_tls.flag==1 && fixture_tls.context==37;
}

bool FixtureAliases(unsigned char flag, int context) {
    unsigned char* block = FixtureModuleBlock();
    return block && reinterpret_cast<unsigned char*>(&fixture_tls)==block+4 &&
        &fixture_tls.flag==block+0x268 &&
        reinterpret_cast<unsigned char*>(&fixture_tls.context)==block+0x2b4 &&
        fixture_tls.flag==flag && fixture_tls.context==context &&
        block[0x268]==flag && *reinterpret_cast<int*>(block+0x2b4)==context;
}
