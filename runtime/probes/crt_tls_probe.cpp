// Standalone CRT/TLS/import probe. Contains no game code or assets.
#include <windows.h>
#include <stdio.h>

__declspec(thread) int tls_value = 37;
static int constructed = 0;
static int main_ok = 0;
static int initial_main = 0;
static int final_main = 0;
static int initial_thread[2] = {0, 0};
static int final_thread[2] = {0, 0};

struct Receipt {
    Receipt() { constructed = 1; }
    ~Receipt() {
        // Printed on the ordinary CRT exit path, proving this destructor ran.
        printf("{\"schema\":1,\"constructor\":%d,\"destructor\":1,\"main_initial\":%d,\"main_final\":%d,\"thread_initial\":[%d,%d],\"thread_final\":[%d,%d],\"checks_ok\":%d}\n",
               constructed, initial_main, final_main, initial_thread[0], initial_thread[1],
               final_thread[0], final_thread[1], main_ok);
        fflush(stdout);
    }
};
static Receipt receipt;

struct Worker {
    int index;
    HANDLE ready;
    HANDLE release;
};

static DWORD WINAPI worker_proc(void* arg) {
    Worker* worker = static_cast<Worker*>(arg);
    const int index = worker->index;
    initial_thread[index] = tls_value;
    tls_value = 101 + index;
    if (!SetEvent(worker->ready)) return 1;
    if (WaitForSingleObject(worker->release, 10000) != WAIT_OBJECT_0) return 2;
    final_thread[index] = tls_value;
    return 0;
}

int main() {
    HANDLE ready[2] = {NULL, NULL};
    HANDLE threads[2] = {NULL, NULL};
    HANDLE release = CreateEventA(NULL, TRUE, FALSE, NULL);
    Worker workers[2];
    bool ok = constructed == 1 && release != NULL;
    initial_main = tls_value;
    tls_value = 99;
    for (int i = 0; i < 2 && ok; ++i) {
        ready[i] = CreateEventA(NULL, TRUE, FALSE, NULL);
        workers[i].index = i; workers[i].ready = ready[i]; workers[i].release = release;
        if (!ready[i]) { ok = false; break; }
        threads[i] = CreateThread(NULL, 0, worker_proc, &workers[i], 0, NULL);
        if (!threads[i]) ok = false;
    }
    if (ok && WaitForMultipleObjects(2, ready, TRUE, 10000) != WAIT_OBJECT_0) ok = false;
    final_main = tls_value;
    if (release && !SetEvent(release)) ok = false;
    for (int j = 0; j < 2; ++j) {
        if (threads[j]) {
            DWORD code = 1;
            if (WaitForSingleObject(threads[j], 12000) != WAIT_OBJECT_0 ||
                !GetExitCodeThread(threads[j], &code) || code != 0) ok = false;
            CloseHandle(threads[j]);
        }
        if (ready[j]) CloseHandle(ready[j]);
    }
    if (release) CloseHandle(release);
    main_ok = ok && initial_main == 37 && final_main == 99 &&
        initial_thread[0] == 37 && initial_thread[1] == 37 &&
        final_thread[0] == 101 && final_thread[1] == 102;
    return main_ok ? 0 : 1;
}
