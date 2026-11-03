#ifndef ORIGINAL_TLS_OWNER_FIXTURE_HPP
#define ORIGINAL_TLS_OWNER_FIXTURE_HPP
#include <windows.h>
#include <stddef.h>

// Authored fixture layout, not a game class or copied game TLS template.
struct FixtureTlsStorage {
    unsigned char reserved_prefix[0x264];
    unsigned char flag;
    unsigned char reserved_middle[0x4b];
    int context;
    unsigned char reserved_tail[0xc];
};
typedef char FixtureTlsLayout[(sizeof(void*)==4 && sizeof(FixtureTlsStorage)==704 &&
    __alignof(FixtureTlsStorage)==4 && offsetof(FixtureTlsStorage, flag)==0x264 &&
    offsetof(FixtureTlsStorage, context)==0x2b0) ? 1 : -1];
extern __declspec(thread) __declspec(align(4)) FixtureTlsStorage fixture_tls;
typedef char FixtureTlsVariableAlignment[__alignof(fixture_tls)==4 ? 1 : -1];
unsigned char* FixtureModuleBlock();
bool FixtureInitialState();
bool FixtureAliases(unsigned char flag, int context);

struct FixtureTlsEvent {
    DWORD reason, thread_id;
    unsigned owner_offset, flag_offset, context_offset, module_index;
    unsigned char flag;
    int context;
    unsigned initial_ok;
};
extern FixtureTlsEvent fixture_tls_events[16];
extern volatile LONG fixture_tls_event_count;
extern volatile LONG fixture_tls_event_overflow;
extern volatile LONG fixture_main_ok;
extern volatile LONG fixture_destructed;
extern DWORD fixture_main_thread_id;
extern HANDLE fixture_detach_output;
extern "C" unsigned long _tls_index;
extern "C" void NTAPI FixtureTlsCallback(void*, DWORD, void*);
#endif
