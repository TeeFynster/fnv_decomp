// Original CRT contract fixture. No game code, classes or virtual dispatch.
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Microsoft documents this compiler runtime implementation entry without a
// public header declaration. Used only by bounded contract-test child modes.
extern "C" int __cdecl _purecall(void);

static void marker(const char* text) { puts(text); fflush(stdout); }
static void __cdecl exit_hook(void) {
    marker("hook-exit-73");
    ExitProcess(73); // Intentional hook policy; does not establish CRT abort policy.
}

static bool suppress_process_ui(void) {
    const UINT mode = SEM_FAILCRITICALERRORS | SEM_NOGPFAULTERRORBOX | SEM_NOOPENFILEERRORBOX;
    SetErrorMode(mode);
    if ((SetErrorMode(mode) & mode) != mode) return false;
    typedef HRESULT (WINAPI *SetFlags)(DWORD);
    typedef HRESULT (WINAPI *GetFlags)(HANDLE, DWORD*);
    HMODULE kernel = GetModuleHandleA("kernel32.dll");
    SetFlags set_flags = reinterpret_cast<SetFlags>(GetProcAddress(kernel, "WerSetFlags"));
    GetFlags get_flags = reinterpret_cast<GetFlags>(GetProcAddress(kernel, "WerGetFlags"));
    // WER_FAULT_REPORTING_NO_UI is absent from the Vista SDK headers used here.
    // Current Windows ABI constant; see the accompanying contract documentation.
    const DWORD no_ui = 0x0020;
    DWORD flags = 0;
    if (!set_flags || !get_flags || FAILED(set_flags(no_ui)) ||
        FAILED(get_flags(GetCurrentProcess(), &flags)) || !(flags & no_ui)) return false;
    _set_error_mode(_OUT_TO_STDERR);
    _set_abort_behavior(0, _WRITE_ABORT_MSG | _CALL_REPORTFAULT);
    return true;
}

int main(int argc, char** argv) {
    if (argc != 2 || (strcmp(argv[1], "state") && strcmp(argv[1], "exit-hook") &&
                       strcmp(argv[1], "default"))) return 90;
    if (!suppress_process_ui()) return 91; // Never enter a failure path without guards.
    if (_get_purecall_handler() != 0) return 92;
    marker("fresh-null-handler");
    _purecall_handler old = _set_purecall_handler(exit_hook);
    if (old != 0 || _get_purecall_handler() != exit_hook) return 93;
    if (!strcmp(argv[1], "exit-hook")) {
        marker("before-exit-hook");
        _purecall();
        return 94;
    }
    if (_set_purecall_handler(old) != exit_hook || _get_purecall_handler() != old) return 95;
    if (!strcmp(argv[1], "state")) {
        marker("set-restored-null");
        return 0;
    }
    marker("before-default-abort");
    _purecall();
    return 96; // A return is failure, never accepted as default termination.
}
