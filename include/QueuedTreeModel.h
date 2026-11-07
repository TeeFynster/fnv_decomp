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

    bool QueuedFileEntry_GetDescription(char* apDescription, unsigned int aiBufferSize, const char* apName);
    bool GetTreeModelDescription(char* apDescription, unsigned int aiBufferSize);
    bool GrassLoadTask_GetDescription(char* pBuf, unsigned int uiSize);
    bool QueuedTexture_GetDescription(char* apDescription, unsigned int aiBufferSize);
    bool QueuedKF_GetDescription(char* apDescription, unsigned int aiBufferSize);
    bool QueuedModel_GetDescription(char* apDescription, unsigned int aiBufferSize);
    void QueueTreeModelLoad();
    void Run_0043da00();
    void SetVtableAndProcessState_0043d8f0();
    void* FUN_0043d8c0(unsigned int flags);

    unsigned char padding[0x48 - sizeof(QueuedModel)];
    TESObjectREFR* pRef;
    TESObjectTREE* pTree;
};
