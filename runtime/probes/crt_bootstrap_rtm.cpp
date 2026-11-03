// Original RTM consumer. Own C++ state stays inside this translation unit.
#include <stdlib.h>
#include "crt_bootstrap_contract.hpp"
class FnvBootstrapRtmObject {
public:
    FnvBootstrapRtmObject() {
        unsigned char bytes[32];
        for (unsigned int i = 0; i < 32; ++i) bytes[i] = static_cast<unsigned char>(2 + i);
        fnv_bootstrap_event(2, FnvCtor, fnv_bootstrap_sum(bytes, 32), 0);
    }
    ~FnvBootstrapRtmObject() {
        unsigned char bytes[32];
        for (unsigned int i = 0; i < 32; ++i) bytes[i] = static_cast<unsigned char>(3 + i);
        fnv_bootstrap_event(2, FnvDtor, fnv_bootstrap_sum(bytes, 32), 0);
    }
};
FnvBootstrapRtmObject rtm_instance;
static void __cdecl rtm_callback(void) { fnv_bootstrap_event(2, FnvCallback, 0, 0); }
extern "C" int __cdecl fnv_bootstrap_rtm_register(void) { return atexit(rtm_callback); }
extern "C" unsigned int __cdecl fnv_bootstrap_rtm_work(void) {
    unsigned char bytes[64];
    for (unsigned int i = 0; i < 64; ++i) bytes[i] = static_cast<unsigned char>(2 + i);
    const unsigned int result = fnv_bootstrap_sum(bytes, 64);
    fnv_bootstrap_event(2, FnvProtected, result, 0);
    return result;
}
