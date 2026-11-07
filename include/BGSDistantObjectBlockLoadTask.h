#pragma once

#include "QueuedFileEntry.h"
#include "NiAVObject.h"

class BGSDistantObjectBlock;
class TESWorldSpace;

class BGSDistantObjectBlockLoadTask : public QueuedFileEntry
{
public:
    BGSDistantObjectBlockLoadTask(int iParent, int iWorld, int iX, int iY, int iLevel,
                                bool bForce, bool bAlt, bool abLOD);
    BGSDistantObjectBlockLoadTask(BGSDistantObjectBlock* parent, TESWorldSpace* world,
                                int x, int y, int level, bool force, bool alternate, bool lod);
    BGSDistantObjectBlockLoadTask(void* owner, void* output, int x, int y, void* world,
                                int level, int alternate, int lod);

    virtual ~BGSDistantObjectBlockLoadTask();
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
    virtual unsigned char GetFileIndex();

    void BGSDistantObjectBlockLoadTask_GetWaterGeometry(void* destination);
    void QueuedFile_Cancel(void* pState, void* pOwner);
    void RunOnce(void* apTaskState, void* apTaskOwner);
    void FUN_006f6fe0();
    void* FUN_006f6fb0(unsigned int flags);
    void LoadDistantObjectBlock();
    void UpdateLoadingState();
    void QueueLODModelLoads();

    union
    {
        unsigned int unk30;
        unsigned char m_bDone;
        bool bFadeQueuedCur;
    };
    union { int iX; int m_iX; };
    union { int iY; int m_iY; };
    union { int iLevel; int m_iZ; };
    BGSDistantObjectBlock* m_pParent;
    TESWorldSpace* m_pContainingWorldspace;
    NiPointer<NiAVObject> m_spNode;
    NiPointer<NiAVObject> m_spLand;
    unsigned char m_bLoadComplete;
    union { bool m_bLOD; bool bSkipLoad; };
    unsigned char unk52[2];
    int unk54;
};
