#pragma once

#include "QueuedFile.h"

class QueuedReference : public QueuedFile
{
public:
    virtual ~QueuedReference();
    virtual void Run();
    virtual void Finish();
    virtual void Cancel(BS_TASK_STATE state, void* parent);
    virtual bool GetDescription(char* description, unsigned int bufferSize);
    virtual void ProcessLoadedAnimIdle();
    virtual void GenerateKey();
    virtual void ChangePriority(IO_TASK_PRIORITY priority);
    virtual void DispatchToManager();
    virtual void HandleChildCompletion(QueuedFile* apChild);
    virtual void OnChildCompletion();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vf16();

    void Attach();
    void ForwardCall_00441b80();
    void FUN_004414f0();
};
