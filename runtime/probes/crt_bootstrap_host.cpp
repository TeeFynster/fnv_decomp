// Original normal-GUI-startup fixture. Intentionally compiled /GS- so the
// C-initializer observer and its complete source closure are unprotected.
#include <windows.h>
#include <stdlib.h>
#include "crt_bootstrap_contract.hpp"

#ifndef FNV_CRT_COOKIE_DEFAULT
#error Bind the actual selected normal CRT cookie default in preparation.
#endif

// Read-only observation of actual four-byte x86 CRT definitions. Preparation
// must verify their native symbol kinds, sizes, owners and one linked identity.
extern "C" unsigned int __security_cookie;
extern "C" unsigned int __security_cookie_complement;

extern "C" int __cdecl fnv_bootstrap_event(unsigned int lane, unsigned int kind,
                                         unsigned int value, unsigned int auxiliary) {
    HANDLE pipe = GetStdHandle(STD_OUTPUT_HANDLE);
    if (!pipe || pipe == INVALID_HANDLE_VALUE || GetFileType(pipe) != FILE_TYPE_PIPE) return 1;
    FnvBootstrapEvent event;
    event.magic = 0x464e5643; event.schema = 1; event.lane = lane;
    event.kind = kind; event.value = value; event.auxiliary = auxiliary;
    DWORD written = 0;
    return WriteFile(pipe, &event, sizeof(event), &written, 0) && written == sizeof(event) ? 0 : 1;
}

extern "C" unsigned int __cdecl fnv_bootstrap_sum(const unsigned char* bytes, unsigned int count) {
    unsigned int sum = 0;
    for (unsigned int i = 0; i < count; ++i) sum += bytes[i];
    return sum;
}

static bool suppress_process_ui(void) {
    const UINT mode = SEM_FAILCRITICALERRORS | SEM_NOGPFAULTERRORBOX | SEM_NOOPENFILEERRORBOX;
    SetErrorMode(mode);
    if ((SetErrorMode(mode) & mode) != mode) return false;
    typedef HRESULT (WINAPI *SetFlags)(DWORD);
    typedef HRESULT (WINAPI *GetFlags)(HANDLE, DWORD*);
    HMODULE kernel = GetModuleHandleA("kernel32.dll");
    SetFlags set = reinterpret_cast<SetFlags>(GetProcAddress(kernel, "WerSetFlags"));
    GetFlags get = reinterpret_cast<GetFlags>(GetProcAddress(kernel, "WerGetFlags"));
    DWORD flags = 0;
    return set && get && SUCCEEDED(set(0x0020)) &&
        SUCCEEDED(get(GetCurrentProcess(), &flags)) && (flags & 0x0020) != 0;
}

extern "C" int __cdecl fnv_bootstrap_early(void) {
    // Correct _PIFV contract: zero permits normal C/C++ initialization to
    // continue; nonzero is a startup failure, never a successful shortcut.
    if (!suppress_process_ui()) return 1;
    const unsigned int cookie = __security_cookie;
    unsigned int flags = 0;
    if (cookie != 0) flags |= 1;
    if (cookie != FNV_CRT_COOKIE_DEFAULT) flags |= 2;
    if (__security_cookie_complement == ~cookie) flags |= 4;
    if (fnv_bootstrap_event(0, FnvEarly, flags, 0)) return 1;
    return flags == 7 ? 0 : 1;
}

typedef int (__cdecl *FnvCInitializer)(void);
// Immediately after the C-initializer begin sentinel. Actual linked table
// contents, not this spelling alone, must prove no nonnull initializer precedes it.
#pragma section(".CRT$XIAA", long, read)
extern "C" __declspec(allocate(".CRT$XIAA")) FnvCInitializer fnv_bootstrap_early_slot = fnv_bootstrap_early;
#pragma comment(linker, "/include:_fnv_bootstrap_early_slot")

static int exercise(unsigned int lane, unsigned int (__cdecl *work)(void), int (__cdecl *registration)(void)) {
    const unsigned int expected = 64 * lane + 2016;
    if (work() != expected) return 1;
    const int result = registration();
    if (fnv_bootstrap_event(lane, FnvRegistered, static_cast<unsigned int>(result), 0)) return 1;
    return result == 0 ? 0 : 1;
}

int WINAPI WinMain(HINSTANCE instance, HINSTANCE previous, LPSTR command, int show) {
    _set_error_mode(_OUT_TO_STDERR);
    _set_abort_behavior(0, _WRITE_ABORT_MSG | _CALL_REPORTFAULT);
    unsigned int arguments = 0;
    if (instance) arguments |= 1;
    if (!previous) arguments |= 2;
    if (command) arguments |= 4;
    if (show == SW_HIDE) arguments |= 8;
    const unsigned int lanes = 3; // Same three source roles in control and mixed images.
    if (fnv_bootstrap_event(0, FnvMain, lanes, arguments) || arguments != 15) return 1;
    if (exercise(1, fnv_bootstrap_sp1_work, fnv_bootstrap_sp1_register)) return 1;
    if (exercise(2, fnv_bootstrap_rtm_work, fnv_bootstrap_rtm_register) ||
        exercise(3, fnv_bootstrap_vc8_work, fnv_bootstrap_vc8_register)) return 1;
    if (fnv_bootstrap_event(0, FnvReturning, 0, 0)) return 1;
    return 0; // Only ordinary CRT termination can satisfy the event contract.
}
