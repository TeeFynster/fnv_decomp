#pragma once

class ThreadSemaphore
{
public:
    long count;
    void* handle;
    long limit;

    ThreadSemaphore();
    ~ThreadSemaphore();
};
