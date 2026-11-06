#pragma once

#include "BSTaskThread.h"

class Q449;

class BackgroundCloneThread : public BSTaskThread
{
public:
    BackgroundCloneThread(unsigned int aiMaxThreads);
    virtual ~BackgroundCloneThread();
    virtual void RunBackgroundClone();

    void* __thiscall FUN_00442290(unsigned int flags);

    bool m_bThirdThreadFlag;
    int m_iState;
    Q449* m_pCloneQueue;
};
