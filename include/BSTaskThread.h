#pragma once

// RTTI: no bases, vftable 0x010c1844 (slot 0 destructor 0x00c3f130, slot 1 pure); constructor 0x00c42dd0,
// destructor 0x00c42f00. Size 0x30 (BackgroundCloneThread's own members start there).
class BSTaskThread
{
public:
    // Semaphore built inline by the constructor (count, CreateSemaphore handle, maximum).
    struct Semaphore
    {
        long iCount;
        void* hSemaphore;
        long iMaxCount;
    };

    BSTaskThread(unsigned int auiType, const char* apName);
    virtual ~BSTaskThread();

    void* hThread;
    unsigned int uiThreadID;
    Semaphore kStartSemaphore;
    Semaphore kDoneSemaphore;
    int unk24;
    int unk28;
    unsigned int uiOwnerThreadID;
};
