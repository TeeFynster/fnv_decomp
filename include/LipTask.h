#pragma once

#include "QueuedFileEntry.h"

class BGSTerrainManager;
class LipSyncBackgroundManager;
class UnkHolder;

class LipTask : public QueuedFileEntry
{
public:
    LipTask(int owner, int actor, const char* name);
    virtual ~LipTask();
    virtual void Run();
    virtual void Finish();
    virtual void Cancel(BS_TASK_STATE state, void* parent);
    virtual bool GetDescription(char* description, unsigned int bufferSize);

    void InitTerrainManager();
    void LipTask_Finish();
    void HandleStateChange(int aePreviousState, void* apTaskOwner);
    bool GetDescription_00905e00(char* apDescription, unsigned int aiBufferSize);
    int FUN_00c3cff0(int a1, int a2);
    using IOTask::QueuedFile_Cancel;
    void QueuedFile_Cancel(int state, void* owner);

    union
    {
        int unk30;
        int f30;
        UnkHolder* m_30;
        int _m30;
    };
    union
    {
        BGSTerrainManager* unk34;
        int f34;
        int m_34;
    };
    union
    {
        LipSyncBackgroundManager* unk38;
        int f38;
        LipSyncBackgroundManager* m_38;
        LipSyncBackgroundManager* _m38;
    };

    int unk3C;
};
