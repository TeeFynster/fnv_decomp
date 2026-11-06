#pragma once

class CountingSemaphore
{
public:
    volatile int iCount;
    void* hSemaphore;
    int m_iMaximumCount;

    CountingSemaphore();
    CountingSemaphore(unsigned int auiCount);
    CountingSemaphore(int count);
    CountingSemaphore(unsigned int auiCount, unsigned int auiMaxCount);
    CountingSemaphore(int count, int maxCount);
    ~CountingSemaphore();

    void Signal();
    void Wait();
    bool Test();
};
