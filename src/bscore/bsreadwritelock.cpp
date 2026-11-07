// bscore/bsreadwritelock.cpp: free functions (7 functions)

#include "../../include/BGSEntryPointPerkEntry.h"

// Runs the BGSPerkEntry constructor (0x005e9530), then sets the derived vtable and clears the function data, conditions, condition count and function.
// @fnv 0x005e9f60
BGSEntryPointPerkEntry::BGSEntryPointPerkEntry()
{
    m_pFunctionData = 0;
    m_pConditions = 0;
    Data.m_ucConditionCount = 0;
    Data.m_ucFunction = 0;
}

struct ReadWriteLock
{
    void LockForRead();
    void LockForWrite();
    bool TryLockForRead();
    bool TryLockForWrite();
    bool TryLockForWriteAndReserve();
    void UnlockRead();
    void UnlockWrite();
    bool IsWritingThread();
    unsigned int m_uiLockState;
    unsigned int m_uiWriterThreadId;
};
typedef char _sizecheck_BSReadWriteLock[sizeof(ReadWriteLock) == 8 ? 1 : -1];
struct FUN_00aa62e0_shell : public ReadWriteLock
{
    void BSReadWriteLock_UnlockWrite();
};

__declspec(dllimport) long __stdcall InterlockedCompareExchange(long volatile* Destination, long Exchange,
                                                                long Comperand);

// @fnv 0x00aa62e0
// src: XBOX_PDB 0x00aa62e0
void FUN_00aa62e0_shell::BSReadWriteLock_UnlockWrite()
{
    m_uiLockState -= 1;
    if (m_uiLockState == 0x80000000)
    {
        unsigned int uiCurrentLock = m_uiLockState;
        InterlockedCompareExchange((volatile long*)&m_uiLockState, 0, uiCurrentLock);
        m_uiWriterThreadId = 0;
    }
}

namespace fnv_00aa6060 {
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();
extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(volatile long*, long, long);
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long);
// @fnv 0x00aa6060
void __fastcall AcquireLock(ReadWriteLock* lock)
{
    unsigned int uiz;
    unsigned int uia;
    unsigned int uib;
    uiz = GetCurrentThreadId();
    if (lock->m_uiWriterThreadId == uiz)
    {
        lock->m_uiLockState++;
        return;
    }
    uib = lock->m_uiLockState & 0xFFFFFFF;
    uia = lock->m_uiLockState | 0x80000000;
    while (InterlockedCompareExchange((volatile long*)lock, uia, uib) != uib)
    {
        Sleep(0);
        uib = lock->m_uiLockState & 0xFFFFFFF;
        uia = lock->m_uiLockState | 0x80000000;
    }
    while (InterlockedCompareExchange((volatile long*)lock, 0x80000001, 0x80000000) != 0x80000000)
        Sleep(0);
    lock->m_uiWriterThreadId = uiz;
}
}  // namespace fnv_00aa6060

namespace fnv_00aa6120 {
extern "C"
{
    __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId(void);
    __declspec(dllimport) long __stdcall InterlockedCompareExchange(volatile long*, long, long);
    __declspec(dllimport) void __stdcall Sleep(unsigned long);
}
struct Lock00aa6120
{
    unsigned int state;
    unsigned long owner;
    bool BSReadWriteLock_TryLockForRead();
};
// @fnv 0x00aa6120
// src: COMMUNITY 0x00aa6120
bool Lock00aa6120::BSReadWriteLock_TryLockForRead()
{
    bool bLocked = false;
    unsigned long dwThreadId = GetCurrentThreadId();
    if (owner == dwThreadId)
    {
        state = state + 1;
        bLocked = true;
    }
    else
    {
        unsigned int uiCurrent = state & 0xfffffff;
        while (InterlockedCompareExchange((volatile long*)this, uiCurrent + 1, uiCurrent) != uiCurrent)
        {
            if (state & 0x80000000)
                return false;
            Sleep(0);
            uiCurrent = state & 0xfffffff;
        }
        bLocked = true;
    }
    return bLocked;
}
}  // namespace fnv_00aa6120

namespace fnv_00aa61b0 {
extern "C"
{
    __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId(void);
    __declspec(dllimport) long __stdcall InterlockedCompareExchange(volatile long*, long, long);
    __declspec(dllimport) void __stdcall Sleep(unsigned long);
}
struct Lock00aa61b0
{
    unsigned int state;
    unsigned long owner;
    bool BSReadWriteLock_TryLockForWrite();
};
// Tries to acquire the lock: re-enters if already owned by this thread, otherwise atomically sets state and records the owner thread id.
// @fnv 0x00aa61b0
// src: COMMUNITY 0x00aa61b0
bool Lock00aa61b0::BSReadWriteLock_TryLockForWrite()
{
    bool bLocked = false;
    unsigned long dwThreadId = GetCurrentThreadId();
    if (owner == dwThreadId)
    {
        state = state + 1;
        bLocked = true;
    }
    else
    {
        bLocked = InterlockedCompareExchange((volatile long*)this, 0x80000001, 0) == 0;
        if (bLocked)
        {
            owner = dwThreadId;
        }
    }
    return bLocked;
}
}  // namespace fnv_00aa61b0

namespace fnv_00aa6220 {
extern "C"
{
    __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId(void);
    __declspec(dllimport) long __stdcall InterlockedCompareExchange(volatile long*, long, long);
    __declspec(dllimport) void __stdcall Sleep(unsigned long);
}
struct Lock00aa6220
{
    unsigned int state;
    unsigned long owner;
    bool BSReadWriteLock_TryLockForWriteAndReserve();
};
// Tries to acquire the lock: re-enters if already owned by this thread, otherwise claims the state word via InterlockedCompareExchange and records the owner.
// @fnv 0x00aa6220
// src: COMMUNITY 0x00aa6220
bool Lock00aa6220::BSReadWriteLock_TryLockForWriteAndReserve()
{
    bool bLocked = false;
    unsigned long dwThreadId = GetCurrentThreadId();
    if (owner == dwThreadId)
    {
        state = state + 1;
        bLocked = true;
    }
    else
    {
        unsigned int uiCompare = state;
        if (owner == 0)
        {
            unsigned int uiExchange = state | 0x80000000;
            if (InterlockedCompareExchange((volatile long*)this, uiExchange, uiCompare) == uiCompare)
            {
                if (InterlockedCompareExchange((volatile long*)this, 0x80000001, 0x80000000) == 0x80000000)
                {
                    bLocked = true;
                    owner = dwThreadId;
                }
                else
                {
                    bLocked = false;
                }
            }
        }
    }
    return bLocked;
}
}  // namespace fnv_00aa6220

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct Lock00aa62c0
{
    long count;
    void BSReadWriteLock_UnlockRead();
};
// @fnv 0x00aa62c0
// src: XBOX_PDB 0x00aa62c0
void Lock00aa62c0::BSReadWriteLock_UnlockRead()
{
    InterlockedDecrement(&count);
}
