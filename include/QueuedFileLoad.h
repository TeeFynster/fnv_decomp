#pragma once

#include "QueuedFileEntry.h"

class LoadedFile;

class QueuedFileLoad : public QueuedFileEntry
{
public:
    virtual ~QueuedFileLoad();
    virtual void Run();
    virtual void Finish();
    virtual void DispatchToManager();
    virtual unsigned char GetFileIndex();

    LoadedFile* GetLoadedFile();
    void FUN_00441d20();
    void* FUN_00441cf0(unsigned int flags);

    char m_pLoadedFile[4];
    union
    {
        int m_iLoadPriority;
        unsigned char fileIndex;
    };
};
