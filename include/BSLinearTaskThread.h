#pragma once

#include "BSThread.h"
#include "ThreadSemaphore.h"

class BSLinearTaskThread : public BSThread
{
public:
    __declspec(dllexport) BSLinearTaskThread() : stopping(false)
    {}
    virtual ~BSLinearTaskThread();
    virtual unsigned int ThreadProc();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();

    ThreadSemaphore request;
    ThreadSemaphore completion;
    bool stopping;
};
