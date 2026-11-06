#pragma once

#include "BSLinearTaskThread.h"
#include "hkMemoryRouter.h"

class AILinearTaskThread : public BSLinearTaskThread
{
public:
    AILinearTaskThread(void(__cdecl* taskFunction)());
    virtual ~AILinearTaskThread();

    void StartTaskThread();
    void ExecuteTask();

    void(__cdecl* m_pTaskFunction)();
    hkMemoryRouter ThreadMemory;
    void* m_pTaskMemory;
};
