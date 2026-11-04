// Original VC8 consumer. Own C++ state stays inside this translation unit.
#include <stdlib.h>
#include "crt_bootstrap_contract.hpp"
class FnvBootstrapVc8Object {
public:
    FnvBootstrapVc8Object() {
        unsigned char bytes[32];
        for (unsigned int i = 0; i < 32; ++i) bytes[i] = static_cast<unsigned char>(3 + i);
        fnv_bootstrap_event(3, FnvCtor, fnv_bootstrap_sum(bytes, 32), 0);
    }
    ~FnvBootstrapVc8Object() {
        unsigned char bytes[32];
        for (unsigned int i = 0; i < 32; ++i) bytes[i] = static_cast<unsigned char>(4 + i);
        fnv_bootstrap_event(3, FnvDtor, fnv_bootstrap_sum(bytes, 32), 0);
    }
};
FnvBootstrapVc8Object vc8_instance;
static void __cdecl vc8_callback(void) { fnv_bootstrap_event(3, FnvCallback, 0, 0); }
extern "C" int __cdecl fnv_bootstrap_vc8_register(void) { return atexit(vc8_callback); }
extern "C" unsigned int __cdecl fnv_bootstrap_vc8_work(void) {
    unsigned char bytes[64];
    for (unsigned int i = 0; i < 64; ++i) bytes[i] = static_cast<unsigned char>(3 + i);
    const unsigned int result = fnv_bootstrap_sum(bytes, 64);
    fnv_bootstrap_event(3, FnvProtected, result, 0);
    return result;
}
