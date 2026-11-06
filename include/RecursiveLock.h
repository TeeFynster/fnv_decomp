#pragma once

class BSCriticalSectionEntry;

class RecursiveLock
{
public:
    char CriticalSection[28];
    unsigned long m_uiFirstValue;
    unsigned long m_uiSecondValue;
    int m_uiRecursionCount;

    void Enter(char*);
    void Leave();
    void Lock(char*);
    void Unlock();
    void Unlock(BSCriticalSectionEntry** entry, unsigned int* key, unsigned int* value);
    bool TryLock();
    void Wait();
    static void OutputTrackingInfo();
    unsigned int QOwningThreadID();
    unsigned int QCurrentLockCount();
    void InitWithSpinCount(unsigned long);
    void* __vecDelDtor(unsigned int);
};
