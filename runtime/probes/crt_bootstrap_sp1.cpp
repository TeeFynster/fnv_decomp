// Original SP1 consumer. Own C++ state stays inside this translation unit.
#include <stdlib.h>
#include "crt_bootstrap_contract.hpp"
class FnvBootstrapSp1Object {
public:
    FnvBootstrapSp1Object() {
        unsigned char bytes[32];
        for (unsigned int i = 0; i < 32; ++i) bytes[i] = static_cast<unsigned char>(1 + i);
        fnv_bootstrap_event(1, FnvCtor, fnv_bootstrap_sum(bytes, 32), 0);
    }
    ~FnvBootstrapSp1Object() {
        unsigned char bytes[32];
        for (unsigned int i = 0; i < 32; ++i) bytes[i] = static_cast<unsigned char>(2 + i);
        fnv_bootstrap_event(1, FnvDtor, fnv_bootstrap_sum(bytes, 32), 0);
    }
};
FnvBootstrapSp1Object sp1_instance;
static void __cdecl sp1_callback(void) { fnv_bootstrap_event(1, FnvCallback, 0, 0); }
extern "C" int __cdecl fnv_bootstrap_sp1_register(void) { return atexit(sp1_callback); }
extern "C" unsigned int __cdecl fnv_bootstrap_sp1_work(void) {
    unsigned char bytes[64];
    for (unsigned int i = 0; i < 64; ++i) bytes[i] = static_cast<unsigned char>(1 + i);
    const unsigned int result = fnv_bootstrap_sum(bytes, 64);
    fnv_bootstrap_event(1, FnvProtected, result, 0);
    return result;
}
