#pragma once

class __declspec(align(32)) RecursiveSpinLock
{
public:
    volatile unsigned int m_uiOwningThreadID;
    unsigned int m_uiRecursionCount;
    unsigned char layoutPadding8[24];

    __forceinline RecursiveSpinLock()
    {
        m_uiOwningThreadID = 0;
        m_uiRecursionCount = 0;
    }

    void Lock(const char* name);
    __forceinline void Unlock()
    {
        if (--m_uiRecursionCount == 0)
            m_uiOwningThreadID = 0;
    }
    bool TryLock();
    void UnlockUnconditional();
    bool IsLocked();
    bool IsLockedByUs();
    void Wait();

    static unsigned int ms_uiFirstValue;
    static unsigned int ms_uiSecondValue;

    void BSCriticalSection_Enter(unsigned int threadID);
    void FUN_004538c0();
    bool BSSpinLock_TryLock();
    void BSSpinLock_Unlock();
    void BSSpinLock_Lock(char* name);
};
