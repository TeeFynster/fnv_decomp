#ifndef FNV_CRT_BOOTSTRAP_CONTRACT_HPP
#define FNV_CRT_BOOTSTRAP_CONTRACT_HPP

// Original finite fixture protocol. No CRT/C++ objects cross these C boundaries.
enum FnvBootstrapEventKind {
    FnvEarly = 1, FnvCtor = 2, FnvMain = 3, FnvProtected = 4,
    FnvRegistered = 5, FnvReturning = 6, FnvCallback = 7, FnvDtor = 8
};
struct FnvBootstrapEvent {
    unsigned int magic, schema, lane, kind, value, auxiliary;
};
typedef char FnvEventMustBe24Bytes[sizeof(FnvBootstrapEvent) == 24 ? 1 : -1];

extern "C" int __cdecl fnv_bootstrap_event(unsigned int, unsigned int, unsigned int, unsigned int);
extern "C" unsigned int __cdecl fnv_bootstrap_sum(const unsigned char*, unsigned int);
extern "C" unsigned int __cdecl fnv_bootstrap_sp1_work(void);
extern "C" unsigned int __cdecl fnv_bootstrap_rtm_work(void);
extern "C" unsigned int __cdecl fnv_bootstrap_vc8_work(void);
extern "C" int __cdecl fnv_bootstrap_sp1_register(void);
extern "C" int __cdecl fnv_bootstrap_rtm_register(void);
extern "C" int __cdecl fnv_bootstrap_vc8_register(void);

#endif
