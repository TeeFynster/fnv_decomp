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

    void FUN_004538a0(unsigned int threadID);
    void FUN_004538c0();
    bool FUN_0078d200();
    void Leave();
    void FUN_0040fbf0(char* name);
};
