// Standalone import-pointer alias proof; no game code or data.
#include <windows.h>
#include <stdio.h>

__declspec(dllimport) LPWSTR WINAPI FetchCommandLineW(void);
__declspec(dllimport) DWORD WINAPI ReadCurrentProcessId(void);

int main() {
    LPWSTR text = FetchCommandLineW();
    DWORD pid = ReadCurrentProcessId();
    int wide_ok = text != NULL && text[0] != L'\0' && text == GetCommandLineW();
    int pid_ok = pid != 0 && pid == GetCurrentProcessId();
    int ok = wide_ok && pid_ok;
    printf("{\"schema\":1,\"wide_command_line_valid\":%d,\"process_id_valid\":%d,\"checks_ok\":%d}\n", wide_ok, pid_ok, ok);
    return ok ? 0 : 1;
}
