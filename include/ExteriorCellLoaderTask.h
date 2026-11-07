#pragma once

#include "IOTask.h"

class ExteriorCellLoaderTask : public IOTask
{
public:
    virtual ~ExteriorCellLoaderTask();
    virtual void Run();
    virtual void Finish();
    virtual void Cancel(BS_TASK_STATE state, void* parent);
    virtual bool GetDescription(char* description, unsigned int bufferSize);
    virtual void ProcessLoadedAnimIdle();
    virtual void GenerateKey();
    virtual void ChangePriority(IO_TASK_PRIORITY priority);

    void Finish_00527ce0();
};
