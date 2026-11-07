#pragma once

#include "QueuedFileEntry.h"

class TESWorldSpace;

template <class T>
struct ChunkPtr
{
    ChunkPtr(T* p);
    ~ChunkPtr();

    T* p;
};

#pragma pack(push, 4)
class BGSTerrainChunkLoadTask : public QueuedFileEntry
{
public:
    BGSTerrainChunkLoadTask(void* block, TESWorldSpace* space, int x, int y, int level);

    virtual ~BGSTerrainChunkLoadTask();
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

    bool GetDescription_006fc400(char* apDescription, unsigned int aiBufferSize);

    bool unk30;
    unsigned char unk31[3];
    int iX;
    int iY;
    int iLevel;
    void* owner;
    TESWorldSpace* world;
    ChunkPtr<void> unk48;
    ChunkPtr<void> unk4c;
    ChunkPtr<void> unk50;
    ChunkPtr<void> unk54;
    bool unk58;
    unsigned char unk59[3];
};
#pragma pack(pop)
