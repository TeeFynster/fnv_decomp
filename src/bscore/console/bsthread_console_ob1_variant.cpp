
// to their real unit once identified.

#include "bsthread_console_pc.h"
#include "bsthread_console_pc.h"
#include "bsthread_console_pc.h"
unsigned long __stdcall RunThreadProc(void* thread);
struct CRITSEC
{
    int a[6];
};
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CRITSEC*);
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITSEC*);
struct FUN_00aa64f0_t
{
    int vt;
    CRITSEC cs;
    void* handle;
    int pad[3];
    char running;
    void StopAndCloseHandle();
};

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void* pkCriticalSection);

struct ThreadCriticalSectionLocalForm
{ // local form of BSThreadCriticalSectionPC: 0x00aa63c0 needs member-destructor EH cleanup; explicit cleanup on the shared form produces 41 bytes versus exe 97.
    ~ThreadCriticalSectionLocalForm()
    {
        DeleteCriticalSection(this);
    }
    void* DebugInfo;
    long LockCount;
    long RecursionCount;
    void* OwningThread;
    void* LockSemaphore;
    unsigned long SpinCount;
};

class FUN_00aa63c0
{
  public:
    virtual ~FUN_00aa63c0();
    void Shutdown();

    ThreadCriticalSectionLocalForm m_kCriticalSection;
    void* m_hThread;
    void* m_hParent;
    unsigned int m_uiThreadID;
    unsigned int m_uiParentID;
    bool m_bModifierActive;
};

// @fnv 0x00aa63c0
FUN_00aa63c0::~FUN_00aa63c0()
{
    Shutdown();
}
