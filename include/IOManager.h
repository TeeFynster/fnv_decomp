#pragma once

#include "BSTaskManager.h"

class IOQueue;
class QIOTask;
class RefObj;

class IOManager : public BSTaskManager<__int64>
{
public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void AddTask(QIOTask* task);
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();

    unsigned QueuedCount();
    unsigned SumArrayUpToCount(int);
    unsigned int CallSlotMethod(int);
    void CallElementAt(int);
    void SubmitTask();
    void RunQueuedTask(unsigned int, int);
    void IOManager_LoadAllQueuedPriorities();
    void BSTaskManager_CancelTask(RefObj*, void*);
    void BSTaskManager_CancelTask(int);
    void RequeuePrioritiesToNewPriority(int, int);
    bool UpdateQueue();
    void LoadQueuedPriority(int mode);
    void IOManager_PauseThread(int);
    void IOManager_ForceHighestPriority();
    void IOManager_Resume();
    void IOManager_AddPostProcessTask(IOManager* task);
    void ProcessEntries_00c3fce0();
    void CancelAllTasks();

    char unk04[0x18 - 0x04];
    unsigned m_18;
    char unk1C[0x64 - 0x1C];
    IOQueue* m_queue;
    int m_uiContentCount;
    union
    {
        unsigned (*m_pendingFn)();
        int m_6c;
    };
    void (*m_idleFn)();
    bool (*m_canRunFn)();
    void (*m_progressFn)(float);
};
