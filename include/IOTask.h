#pragma once

#include "BSTask.h"

enum IO_TASK_PRIORITY;
class RefObj;

class IOTask : public BSTask<__int64>
{
public:
    IOTask(IO_TASK_PRIORITY priority);
    IOTask(int priority);
    virtual ~IOTask();
    virtual void Run();
    virtual void Finish();
    virtual void Cancel(BS_TASK_STATE state, void* parent);
    virtual bool GetDescription(char* description, unsigned int bufferSize);
    virtual void ProcessLoadedAnimIdle();
    virtual void GenerateKey();
    virtual void ChangePriority(IO_TASK_PRIORITY priority);

    void ChangePriority(int priority);
    void SetIOTaskPriority(IO_TASK_PRIORITY priority);
    unsigned char GetPriority();
    void SetKey(char, unsigned int, unsigned char, unsigned short);
    unsigned int InitScriptRunLockTask();
    void NotifyParents();
    void AddToPostProcessQueue();
    RefObj* GetCur();
    void SetState(long state);
    void AcquireReference();
    void FUN_00c3d440();
    bool FUN_00449110();
    bool FUN_00449130();
    bool FUN_0043caa0();
    bool FUN_0043caf0();
    IO_TASK_PRIORITY FUN_0043cc60();
    unsigned short FUN_0043dc10();
    void FUN_0044dd60();
    void FUN_00c3cb70(int state, RefObj* obj);
    void FUN_00c3c7e0(RefObj* obj);

    static unsigned char GetPriorityFromKey(__int64& key);
};
