#pragma once

#include "BSThread.h"
#include "CountingSemaphore.h"

class LoadingMenuThread : public BSThread
{
public:
    CountingSemaphore m_kFirstSemaphore;
    CountingSemaphore m_kSecondSemaphore;
    volatile bool m_bFirstThreadFlag;
    volatile bool m_bSecondThreadFlag;
    volatile bool m_bThirdThreadFlag;

    LoadingMenuThread();
    virtual unsigned int ThreadProc();
};
