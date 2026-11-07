#include "../../../include/BSThreadCriticalSectionPC.h"

// to their real unit once identified.

#include "bsconsolefilecache_decls.h"
#include "../../../include/MemoryManager.h"
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
struct FUN_00b02310_shell
{
    bool BSWin32TaskletManager_CloseTaskGroupData(unsigned char* param);
};
struct DelObj
{
    virtual ~DelObj()
    {}
};
struct FUN_00b02360_shell
{
    void DeleteIfNotNull(DelObj* p);
};
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle,
                                                                             unsigned long dwMilliseconds);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* lpAddend);
extern "C" __declspec(dllimport) void __stdcall ExitThread(unsigned long dwExitCode);
struct Inner_00b023b0
{
    long cnt;
    void* h;
};
struct Outer_00b023b0
{
    char pad[8];
    Inner_00b023b0 inner;
    void ResumeAllThreads();
};
void __stdcall WaitAndExitThread(Outer_00b023b0* p);
extern "C" __declspec(dllimport) void __stdcall ExitThread(unsigned long);
struct Unk00b023f0
{
    void CallVfn1OnAllEntries();
    void BSWin32TaskletManager_ProcessQueue();
    void CallVirtualOnAllEntries();
};
void __stdcall BSWin32TaskletManager_ThreadProc(Unk00b023f0* p);
extern "C" __declspec(dllimport) unsigned long __stdcall ResumeThread(void*);
struct FUN_00b02420_Data
{
    unsigned char pad[0x1C];
    unsigned int cnt;
    void* h[1];
    void ResumeAllThreads();
};
struct FUN_00b02600_shell
{
    bool ContainsValue(int);
};
extern MemoryManager g_memoryManager;
struct S00b02640
{
    void DestroyAndFreeLibraries();
    void* FUN_00b02640(unsigned int);
};
struct FUN_00b02130_shell
{
    bool QueueItem(void* p);
};
extern "C" __declspec(dllimport) void __stdcall ReleaseSemaphore(void* hSemaphore, long cReleaseCount,
                                                                 long* lPreviousCount);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* lpAddend);
struct FUN_00b020a0_shell
{
    char BSWin32TaskletManager_OpenTaskGroupData(void* p);
};
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForMultipleObjects(unsigned long nCount,
                                                                                const void* const* lpHandles,
                                                                                int bWaitAll,
                                                                                unsigned long dwMilliseconds);
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);
struct FUN_00b01f50_shell
{
    void BSWin32TaskletManager_ShutdownAllTasks();
};
extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(long volatile*, long, long);
struct Lock_00b02220
{
    int m_debugInfo;
    int m_lLockCount;
    int m_recursionCount;
    void* m_owningThread;
    void* m_lockSemaphore;
    unsigned int m_spinCount;
};
struct FUN_00b02220_Owner
{
    int u000;
    int u004;
    int u008;
    int u00C;
    int u010;
    Lock_00b02220 m_kLock;
    bool m_bEnableState;
    bool m_bPending;
    short u02E;
    int u030;
    int m_iArrayLength;
};
struct FUN_00b02220_Task
{
    int unk00;
    bool m_bDone;
    char u005;
    short u006;
    FUN_00b02220_Owner* m_pkOwnerManager;
    int unk0C;
    long m_lBusy;
};
struct FUN_00b02220_Class : FUN_00b02130_shell
{
    bool TryStartTask(void* pOwner, void* pTask, bool bClearPending);
};

extern MemoryManager DAT_011f6238;

struct Spawned_b02010
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    Spawned_b02010();
    static void* operator new(unsigned int size)
    {
        return DAT_011f6238.Game_DoHeapAlloc(size);
    }
    static void operator delete(void*)
    {}
};

struct Owner_b02010
{
    unsigned int unk00;
    bool BSWin32TaskletManager_CreateTaskGroupData(Spawned_b02010** out);
};

// @fnv 0x00b02010
// src: COMMUNITY 0x00b02010
bool Owner_b02010::BSWin32TaskletManager_CreateTaskGroupData(Spawned_b02010** out)
{
    Spawned_b02010* v = new Spawned_b02010;
    *out = v;
    return v != 0;
}

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle,
                                                                             unsigned long dwMilliseconds);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* lpAddend);
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds);
extern "C" __declspec(dllimport) void __stdcall ReleaseSemaphore(void*, long, long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);

struct JobSemaphore
{
    long cnt;
    void* h;
    void Wait()
    {
        WaitForSingleObject(h, -1);
        InterlockedDecrement(&cnt);
    }
    void Signal()
    {
        ReleaseSemaphore(h, 1, 0);
        InterlockedIncrement(&cnt);
    }
};
struct JobOwner
{
    int unk00;
    int unk04;
    JobSemaphore completion;
    int unk10;
    BSThreadCriticalSectionPC kLock;
    bool enabled;
    bool pending;
    bool bBusy;
    char unk2F;
    unsigned int priority;
    unsigned int count;
    unsigned int completed;
    void CompleteTask()
    {
        EnterCriticalSection(&kLock);
        ++completed;
        bool done = !pending && completed == count;
        LeaveCriticalSection(&kLock);
        if (done)
            completion.Signal();
    }
    bool IsBusy()
    {
        return bBusy;
    }
};
struct Job
{
    virtual void Release();
    virtual bool HasFinished();
    virtual void Run();
    virtual void Cancel();
    bool bHasCallback;
    JobOwner* pOwner;
    bool bPending;
    int unk10;
    Job* pNext;
};
struct JobThread
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    bool bStop;
    BSThreadCriticalSectionPC kLock;
    Job* m_pQueueHeads[64];
    Job** pQueueTails[64];
    JobSemaphore kSemaphore;
    bool QueueItem(void* p);
    void BSWin32TaskletManager_ProcessQueue();
};
// @fnv 0x00b02460
// src: COMMUNITY 0x00b02460
void JobThread::BSWin32TaskletManager_ProcessQueue()
{
    Job* pJobB;
    JobOwner* pOwner;
    unsigned int i;
    Job** ppSlot;
    bool bRun;
    while (!bStop)
    {
        pJobB = 0;
        pOwner = 0;
        kSemaphore.Wait();
        if (!bStop)
        {
            EnterCriticalSection(&kLock);
            for (i = 0, ppSlot = m_pQueueHeads; i < 64; ++i, ++ppSlot)
            {
                pJobB = *ppSlot;
                if (pJobB)
                {
                    *ppSlot = pJobB->pNext;
                    pOwner = pJobB->pOwner;
                    break;
                }
            }
            LeaveCriticalSection(&kLock);
            if (pJobB && pOwner && pJobB && !pOwner->IsBusy())
            {
                if ((bRun = pJobB->bPending ? pJobB->HasFinished() : true))
                {
                    pJobB->bPending = false;
                    pJobB->Run();
                }
            }
            if (pJobB && pOwner)
            {
                if (pJobB->bHasCallback && !pOwner->IsBusy())
                {
                    QueueItem(pJobB);
                }
                else
                {
                    pJobB->Cancel();
                    pJobB->pOwner = 0;
                    pJobB->unk10 = 0;
                    pOwner->CompleteTask();
                }
            }
        }
        Sleep(0);
    }
}
