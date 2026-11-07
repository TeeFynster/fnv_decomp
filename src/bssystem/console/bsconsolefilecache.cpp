// bssystem/console/bsconsolefilecache.cpp: FaceGenData (13 functions)

#include "bsconsolefilecache_decls.h"
#include "../../../include/MemoryManager.h"

// Initializes the object's fields to zero/default values and clears the three primitive arrays.
// @fnv 0x005dd590
FaceGenData::FaceGenData()
{
    m_pHair = 0;
    iHairColor = 0;
    m_fHairLength = 0.0f;
    pEyes = 0;
    m_eSex = SEX_SEX_MALE;
    m_kModelObjectsItem.RemoveAll();
    pTexture.RemoveAll();
    m_kTexturePaths.RemoveAll();
    bFaceGenTexturing = false;
    m_bFaceGenDataValid = false;
    m_eFaceGenLOD = BS_FACEGEN_LOD_NONE;
}

// @fnv 0x00b01c00
BSWin32FileCache::BSWin32FileCache()
{}

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
struct FUN_00b02310_shell
{
    bool BSWin32TaskletManager_CloseTaskGroupData(unsigned char* param);
};
// @fnv 0x00b02310
// src: COMMUNITY 0x00b02310
bool FUN_00b02310_shell::BSWin32TaskletManager_CloseTaskGroupData(unsigned char* pObject)
{
    unsigned char* p = pObject;
    bool b;
    EnterCriticalSection(p + 0x14);
    if (p[0x2C] != 0)
    {
        p[0x2D] = 0;
        b = 1;
    }
    else
    {
        b = 0;
    }
    LeaveCriticalSection(p + 0x14);
    return b;
}

struct DelObj
{
    virtual ~DelObj()
    {}
};
struct FUN_00b02360_shell
{
    void DeleteIfNotNull(DelObj* p);
};
// Deletes the given object if the pointer is non-null.
// @fnv 0x00b02360
void FUN_00b02360_shell::DeleteIfNotNull(DelObj* apObject)
{
    if (apObject)
        delete apObject;
}

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
// Waits on the inner handle, decrements the inner counter, calls ResumeAllThreads, then exits the thread.
// @fnv 0x00b023b0
void __stdcall WaitAndExitThread(Outer_00b023b0* pOuter)
{
    Inner_00b023b0* pInner = &pOuter->inner;
    WaitForSingleObject(pInner->h, 0xFFFFFFFF);
    InterlockedDecrement(&pInner->cnt);
    pOuter->ResumeAllThreads();
    ExitThread(0);
}

extern "C" __declspec(dllimport) void __stdcall ExitThread(unsigned long);
struct Unk00b023f0
{
    void CallVfn1OnAllEntries();
    void BSWin32TaskletManager_ProcessQueue();
    void CallVirtualOnAllEntries();
};
// Calls three methods on p in sequence, then terminates the calling thread with ExitThread(0).
// @fnv 0x00b023f0
// src: COMMUNITY 0x00b023f0
void __stdcall BSWin32TaskletManager_ThreadProc(Unk00b023f0* pTarget)
{
    pTarget->CallVfn1OnAllEntries();
    pTarget->BSWin32TaskletManager_ProcessQueue();
    pTarget->CallVirtualOnAllEntries();
    ExitThread(0);
}

extern "C" __declspec(dllimport) unsigned long __stdcall ResumeThread(void*);
struct FUN_00b02420_Data
{
    unsigned char pad[0x1C];
    unsigned int cnt;
    void* h[1];
    void ResumeAllThreads();
};
// Resumes each thread handle stored in the array, iterating cnt times.
// @fnv 0x00b02420
void FUN_00b02420_Data::ResumeAllThreads()
{
    for (unsigned int i = 0; i < cnt; ++i)
        ResumeThread(h[i]);
}

struct FUN_00b02600_shell
{
    bool ContainsValue(int);
};
// Scans the six ints at offset 0x38 of this object and returns true if any equals a, otherwise false.
// @fnv 0x00b02600
bool FUN_00b02600_shell::ContainsValue(int aiValue)
{
    for (unsigned int i = 0; i < 6; ++i)
    {
        if (((int*)((char*)this + 0x38))[i] == aiValue)
            return true;
    }
    return false;
}

extern MemoryManager g_memoryManager;
struct S00b02640
{
    void DestroyAndFreeLibraries();
    void* FUN_00b02640(unsigned int);
};
// Calls DestroyAndFreeLibraries, then deallocates this via g_memoryManager if flags has bit 1 set, and returns this.
// @fnv 0x00b02640
void* S00b02640::FUN_00b02640(unsigned int flags)
{
    DestroyAndFreeLibraries();
    if (flags & 1)
        g_memoryManager._DeallocateAlias(this);
    return this;
}

struct FUN_00b02130_shell
{
    bool QueueItem(void* p);
};
extern "C" __declspec(dllimport) void __stdcall ReleaseSemaphore(void* hSemaphore, long cReleaseCount,
                                                                 long* lPreviousCount);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* lpAddend);

// @fnv 0x00b02130
bool __thiscall FUN_00b02130_shell::QueueItem(void* apItem)
{
    void* pInnerTmp = *(void**)((char*)apItem + 8);
    void* pInner2;
    unsigned int idx;
    char* p26c3;
    bool result9;
    if (pInnerTmp)
    {
        EnterCriticalSection((void*)((char*)this + 0x54));
        pInner2 = *(void**)((char*)apItem + 8);
        idx = *(unsigned int*)((char*)pInner2 + 0x30);
        if (idx >= 0x40)
            idx = 0x3f;
        if (*(void**)((char*)this + 0x6c + idx * 4) == 0)
            *(void**)((char*)this + 0x16c + idx * 4) = (char*)this + 0x6c + idx * 4;
        *(void**)(*(void**)((char*)this + 0x16c + idx * 4)) = apItem;
        *(void**)((char*)this + 0x16c + idx * 4) = (char*)apItem + 0x14;
        *(void**)((char*)apItem + 0x14) = 0;
        *(char*)((char*)apItem + 4) = 0;
        LeaveCriticalSection((void*)((char*)this + 0x54));
        p26c3 = (char*)this + 0x26c;
        ReleaseSemaphore(*(void**)(p26c3 + 4), 1, 0);
        InterlockedIncrement((long*)p26c3);
        result9 = true;
    }
    else
        result9 = false;
    return result9;
}

struct FUN_00b020a0_shell
{
    char BSWin32TaskletManager_OpenTaskGroupData(void* p);
};
// @fnv 0x00b020a0
// src: COMMUNITY 0x00b020a0
char FUN_00b020a0_shell::BSWin32TaskletManager_OpenTaskGroupData(void* pObject)
{
    unsigned char flag;
    void* obj = pObject;
    EnterCriticalSection((char*)obj + 0x14);
    if (!(*(unsigned char*)((char*)obj + 0x2c)))
    {
        WaitForSingleObject(*(void**)((char*)obj + 0xc), 0);
        flag = 1;
        *(unsigned char*)((char*)obj + 0x2c) = flag;
        *(unsigned char*)((char*)obj + 4) = 0;
        *(unsigned char*)((char*)obj + 0x2d) = 1;
        *(unsigned char*)((char*)obj + 0x2e) = 0;
        *(unsigned int*)((char*)obj + 0x34) = 0;
        *(unsigned int*)((char*)obj + 0x38) = 0;
    }
    else
    {
        flag = 0;
    }
    LeaveCriticalSection((char*)obj + 0x14);
    return (char)flag;
}

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForMultipleObjects(unsigned long nCount,
                                                                                const void* const* lpHandles,
                                                                                int bWaitAll,
                                                                                unsigned long dwMilliseconds);
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);

struct FUN_00b01f50_shell
{
    void BSWin32TaskletManager_ShutdownAllTasks();
};

// @fnv 0x00b01f50
// src: COMMUNITY 0x00b01f50
void FUN_00b01f50_shell::BSWin32TaskletManager_ShutdownAllTasks()
{
    unsigned int i;

    *(char*)((char*)this + 0x50) = 1;
    if (*(unsigned char*)((char*)this + 5))
    {
        for (i = 0; i < *(unsigned int*)((char*)this + 0x1c); ++i)
        {
            Inner_00b023b0* pInner = (Inner_00b023b0*)((char*)this + 0x26c);
            ReleaseSemaphore(pInner->h, 1, 0);
            InterlockedIncrement(&pInner->cnt);
        }
        WaitForMultipleObjects(*(unsigned int*)((char*)this + 0x1c), (const void* const*)((char*)this + 0x20), 1,
                               0xFFFFFFFF);
    }

    for (i = 0; i < *(unsigned int*)((char*)this + 0x1c); ++i)
    {
        CloseHandle(*(void**)((char*)this + i * 4 + 0x20));
    }
    CloseHandle(*(void**)((char*)this + 0x14));
}

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
// @fnv 0x00b02220
bool FUN_00b02220_Class::TryStartTask(void* pOwner, void* pTask, bool bClearPending)
{
    FUN_00b02220_Owner* pkOwner = (FUN_00b02220_Owner*)pOwner;
    FUN_00b02220_Task* pkTask2 = (FUN_00b02220_Task*)pTask;
    EnterCriticalSection(&pkOwner->m_kLock);
    bool bResult;
    bool bAcquired;
    if ((bAcquired = InterlockedCompareExchange(&pkTask2->m_lBusy, 1, 0) == 0))
    {
    }
    if (bAcquired)
    {
        bResult = pkOwner->m_bEnableState && pkOwner->m_bPending && pkTask2->m_pkOwnerManager == 0;
        if (bResult == true)
        {
            pkTask2->m_pkOwnerManager = pkOwner;
            pkTask2->m_bDone = false;
            if (bClearPending)
                pkOwner->m_bPending = false;
            bResult = QueueItem(pkTask2);
            pkOwner->m_iArrayLength++;
        }
        else
        {
            pkTask2->m_lBusy = 0;
        }
    }
    else
    {
        bResult = false;
    }
    LeaveCriticalSection(&pkOwner->m_kLock);
    return bResult;
}
