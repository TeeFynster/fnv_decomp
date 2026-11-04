#include "tls_owner_fixture.hpp"

FixtureTlsEvent fixture_tls_events[16] = {};
volatile LONG fixture_tls_event_count = 0;
volatile LONG fixture_tls_event_overflow = 0;
volatile LONG fixture_main_ok = 0;
volatile LONG fixture_destructed = 0;
DWORD fixture_main_thread_id = 0;
HANDLE fixture_detach_output = NULL;

extern "C" void NTAPI FixtureTlsCallback(void*, DWORD reason, void*) {
    if (reason==DLL_PROCESS_ATTACH)
        SetErrorMode(SEM_FAILCRITICALERRORS | SEM_NOGPFAULTERRORBOX | SEM_NOOPENFILEERRORBOX);
    const LONG slot = InterlockedIncrement(&fixture_tls_event_count)-1;
    if (slot<0 || slot>=16) {
        InterlockedExchange(&fixture_tls_event_overflow, 1);
        return;
    }
    FixtureTlsEvent* event = &fixture_tls_events[slot];
    unsigned char* block = FixtureModuleBlock();
    event->reason = reason;
    event->thread_id = GetCurrentThreadId();
    event->owner_offset = reinterpret_cast<unsigned char*>(&fixture_tls)-block;
    event->flag_offset = &fixture_tls.flag-block;
    event->context_offset = reinterpret_cast<unsigned char*>(&fixture_tls.context)-block;
    event->module_index = _tls_index;
    event->flag = fixture_tls.flag;
    event->context = fixture_tls.context;
    event->initial_ok = (reason==DLL_PROCESS_ATTACH || reason==DLL_THREAD_ATTACH) && FixtureInitialState();
    if (reason==DLL_PROCESS_DETACH) {
        // CRT termination has already printed/flushed its own receipt. This
        // final notification uses only Win32 and constant original text.
        const bool ok = fixture_main_ok==1 && fixture_destructed==1 &&
            fixture_tls_event_count==6 && !fixture_tls_event_overflow &&
            fixture_detach_output && fixture_detach_output!=INVALID_HANDLE_VALUE &&
            event->thread_id==fixture_main_thread_id && FixtureAliases(3, 103);
        static const char success[] = "{\"schema\":1,\"event\":\"process_detach\",\"checks_ok\":true}\n";
        static const char failure[] = "{\"schema\":1,\"event\":\"process_detach\",\"checks_ok\":false}\n";
        DWORD written = 0;
        WriteFile(fixture_detach_output, ok ? success : failure,
                  ok ? sizeof(success)-1 : sizeof(failure)-1, &written, NULL);
        if (fixture_detach_output && fixture_detach_output!=INVALID_HANDLE_VALUE)
            CloseHandle(fixture_detach_output);
    }
}

#pragma section(".CRT$XLB", read)
extern "C" __declspec(allocate(".CRT$XLB")) PIMAGE_TLS_CALLBACK fixture_tls_callback_entry = FixtureTlsCallback;
