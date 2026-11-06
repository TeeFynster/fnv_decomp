#pragma once

class BSSemaphore_adf080
{
public:
    long count;
    void* semaphore;

    void Signal();
    void Wait();
};
