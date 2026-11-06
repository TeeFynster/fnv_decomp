#pragma once

#include "QueuedModel.h"

class TESObjectREFR;
class TESObjectTREE;

class QueuedTreeModel : public QueuedModel
{
public:
    virtual ~QueuedTreeModel();
    virtual void Run() override;
    virtual void Finish() override;
    virtual void Cancel(BS_TASK_STATE state, void* parent) override;
    virtual bool GetDescription(char* description, unsigned int bufferSize) override;
    virtual void ProcessLoadedAnimIdle() override;
    virtual void GenerateKey() override;
    virtual void ChangePriority(IO_TASK_PRIORITY priority) override;
    virtual void DispatchToManager() override;
    virtual void HandleChildCompletion(QueuedFile* apChild) override;
    virtual void OnChildCompletion() override;
    virtual unsigned char GetFileIndex() override;
    virtual void vf12() override;

    bool FUN_00c3d0e0(char* apDescription, unsigned int aiBufferSize, const char* apName);
    bool GetTreeModelDescription(char* apDescription, unsigned int aiBufferSize);
    bool FUN_00b600c0(char* pBuf, unsigned int uiSize);
    bool FUN_0043c6b0(char* apDescription, unsigned int aiBufferSize);
    bool FUN_0043e550(char* apDescription, unsigned int aiBufferSize);
    bool FUN_0043d510(char* apDescription, unsigned int aiBufferSize);
    void QueueTreeModelLoad();
    void FUN_0043da00();
    void FUN_0043d8f0();
    void* FUN_0043d8c0(unsigned int flags);

    unsigned char padding[0x48 - sizeof(QueuedModel)];
    TESObjectREFR* pRef;
    TESObjectTREE* pTree;
};
