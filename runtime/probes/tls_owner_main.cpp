#include "tls_owner_fixture.hpp"
#include <stdio.h>
#include <stdlib.h>

struct WorkerState {
    unsigned index;
    HANDLE ready, release;
    DWORD thread_id;
    unsigned initial_ok, final_ok, module_index;
    unsigned char* block;
};
static WorkerState workers[2];
static unsigned constructed = 0;
static unsigned initial_main_ok = 0;

static bool CallbackEvents() {
    if (fixture_tls_event_count!=5 || fixture_tls_event_overflow) return false;
    unsigned process_attach=0, attach[2]={0,0}, detach[2]={0,0};
    for (LONG i=0; i<fixture_tls_event_count; ++i) {
        const FixtureTlsEvent& event = fixture_tls_events[i];
        if (event.owner_offset!=4 || event.flag_offset!=0x268 || event.context_offset!=0x2b4 ||
            event.module_index!=_tls_index) return false;
        if (event.reason==DLL_PROCESS_ATTACH && event.thread_id==fixture_main_thread_id && event.initial_ok) {
            ++process_attach;
        } else {
            bool known=false;
            for (unsigned j=0; j<2; ++j) {
                if (event.thread_id!=workers[j].thread_id) continue;
                known=true;
                if (event.reason==DLL_THREAD_ATTACH && event.initial_ok && event.flag==1 && event.context==37) ++attach[j];
                else if (event.reason==DLL_THREAD_DETACH && event.flag==5+j*2 && event.context==201+static_cast<int>(j)) ++detach[j];
                else return false;
            }
            if (!known) return false;
        }
    }
    return process_attach==1 && attach[0]==1 && attach[1]==1 && detach[0]==1 && detach[1]==1;
}

struct FixtureReceipt {
    FixtureReceipt() {
        ++constructed;
        fixture_main_thread_id = GetCurrentThreadId();
        initial_main_ok = FixtureInitialState() && FixtureAliases(1, 37) && fixture_tls_event_count==1;
    }
    ~FixtureReceipt() {
        const bool callbacks_ok = CallbackEvents();
        const bool main_preserved = FixtureAliases(3, 103);
        const bool indices_ok = workers[0].module_index==_tls_index && workers[1].module_index==_tls_index;
        const bool blocks_distinct = workers[0].block && workers[1].block &&
            workers[0].block!=workers[1].block && workers[0].block!=FixtureModuleBlock() && workers[1].block!=FixtureModuleBlock();
        const unsigned initial_checks = initial_main_ok+workers[0].initial_ok+workers[1].initial_ok;
        const unsigned alias_checks = static_cast<unsigned>(main_preserved)+workers[0].final_ok+workers[1].final_ok;
        const bool ok = fixture_main_ok==1 && constructed==1 && initial_checks==3 && alias_checks==3 &&
            callbacks_ok && indices_ok && blocks_distinct;
        if (!ok) InterlockedExchange(&fixture_main_ok, 0);
        printf("{\"schema\":1,\"constructor\":%u,\"destructor\":1,\"threads\":2,\"initial_checks\":%u,\"alias_checks\":%u,\"main_preserved\":%s,\"callbacks\":%ld,\"callbacks_ok\":%s,\"indices_ok\":%s,\"blocks_distinct\":%s,\"owner_offset\":4,\"flag_offset\":616,\"context_offset\":692,\"checks_ok\":%s}\n",
            constructed, initial_checks, alias_checks, main_preserved ? "true" : "false", fixture_tls_event_count,
            callbacks_ok ? "true" : "false", indices_ok ? "true" : "false", blocks_distinct ? "true" : "false", ok ? "true" : "false");
        fflush(stdout);
        InterlockedExchange(&fixture_destructed, 1);
    }
};
static FixtureReceipt receipt;

static DWORD WINAPI Worker(void* parameter) {
    WorkerState* state = static_cast<WorkerState*>(parameter);
    state->thread_id = GetCurrentThreadId();
    state->initial_ok = FixtureInitialState() && FixtureAliases(1, 37);
    state->module_index = _tls_index;
    state->block = FixtureModuleBlock();
    fixture_tls.flag = static_cast<unsigned char>(5+state->index*2);
    fixture_tls.context = 201+state->index;
    if (!SetEvent(state->ready)) return 30;
    if (WaitForSingleObject(state->release, 10000)!=WAIT_OBJECT_0) return 31;
    state->final_ok = FixtureAliases(static_cast<unsigned char>(5+state->index*2), 201+state->index);
    return state->initial_ok && state->final_ok ? 0 : 32;
}

int main() {
    SetErrorMode(SEM_FAILCRITICALERRORS | SEM_NOGPFAULTERRORBOX | SEM_NOOPENFILEERRORBOX);
    _set_error_mode(_OUT_TO_STDERR);
    volatile unsigned caller_sentinel = 0x13579bdfu;
    const bool detach_channel = DuplicateHandle(GetCurrentProcess(), GetStdHandle(STD_OUTPUT_HANDLE),
        GetCurrentProcess(), &fixture_detach_output, 0, FALSE, DUPLICATE_SAME_ACCESS)!=0;
    HANDLE ready[2]={NULL,NULL}, threads[2]={NULL,NULL};
    HANDLE release = CreateEventA(NULL, TRUE, FALSE, NULL);
    bool ok = constructed==1 && initial_main_ok==1 && release!=NULL && detach_channel;
    fixture_tls.flag = 3;
    fixture_tls.context = 103;
    for (unsigned i=0; i<2 && ok; ++i) {
        ready[i] = CreateEventA(NULL, TRUE, FALSE, NULL);
        workers[i].index=i; workers[i].ready=ready[i]; workers[i].release=release;
        if (!ready[i]) { ok=false; break; }
        threads[i] = CreateThread(NULL, 0, Worker, &workers[i], 0, NULL);
        if (!threads[i]) ok=false;
    }
    if (ok && WaitForMultipleObjects(2, ready, TRUE, 10000)!=WAIT_OBJECT_0) ok=false;
    ok = ok && FixtureAliases(3, 103) && caller_sentinel==0x13579bdfu;
    if (release && !SetEvent(release)) ok=false;
    for (unsigned j=0; j<2; ++j) {
        if (threads[j]) {
            DWORD code=1;
            if (WaitForSingleObject(threads[j], 12000)!=WAIT_OBJECT_0 || !GetExitCodeThread(threads[j], &code) || code) ok=false;
            CloseHandle(threads[j]);
        }
        if (ready[j]) CloseHandle(ready[j]);
    }
    if (release) CloseHandle(release);
    ok = ok && FixtureAliases(3, 103) && caller_sentinel==0x13579bdfu && CallbackEvents();
    InterlockedExchange(&fixture_main_ok, ok ? 1 : 0);
    return ok ? 0 : 33;
}
