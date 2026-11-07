#pragma once

#include "QueuedFileEntry.h"

class BGSDistantTreeBlock;
class Fake076;

class BGSDistantTreeBlockLoadTask : public QueuedFileEntry
{
public:
    BGSDistantTreeBlockLoadTask(BGSDistantTreeBlock* apBlock, Fake076* apWorld, int aiCellX, int aiCellY, int aiLODLevel, int aiUnused);

    virtual ~BGSDistantTreeBlockLoadTask();
    virtual void Run();
    virtual void Finish();
    virtual void Cancel(BS_TASK_STATE state, void* parent);
    virtual bool GetDescription(char* description, unsigned int bufferSize);
    virtual void DispatchToManager();
    virtual void OnChildCompletion();
    virtual unsigned char GetFileIndex();

    void* Destroy(unsigned int flags);
    void FUN_006f94a0();
    void QueuedFile_Cancel(int a1, void* a2);
    void Cancel_006f9540(int a1, void* a2);
    void QueueMe();
    bool __thiscall FormatDescription(char* apDescription, unsigned int aiBufferSize);

    unsigned char unk30[8];
    int iX;
    int iY;
    int iLevel;
    bool m_bCancelled;
    bool m_bLoadComplete;
};
