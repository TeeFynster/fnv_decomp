#pragma once

#include "InterfacedClass.h"
#include "RecursiveSpinLock.h"
template <class T> class ThreadInterfaceManager;

// PC RTTI 0x0106c674: InterfacedClass base, five slots (dtor, AllocateInterface,
// IncrementCount, DecrementCount, GetCount). Ctor 0x006c6450 has 0x40-byte size,
// head/tail at +4/+8, delete batch/buffers at +0xc/+0x10, manager at +0x14,
// count at +0x18 and the 32-byte-aligned RecursiveSpinLock at +0x20.
template <class T> class LockFreeQueue : public InterfacedClass
{
  public:
    struct LockFreeQueueEntry
    {
        LockFreeQueueEntry();
        LockFreeQueueEntry* pNext;
        T tData;
    };
    // Exe 0x0044c920: opaque delete-manager tag.
    class QueueDeleteManagerTag {};
    class LockFreeQueueNode;
    typedef ThreadInterfaceManager<QueueDeleteManagerTag> Manager;
    LockFreeQueue(unsigned int maxThreads, unsigned int deleteBatchSize);
    virtual ~LockFreeQueue();
    virtual void* AllocateInterface(unsigned int thread);
    virtual void IncrementCount();
    virtual void DecrementCount();
    virtual unsigned int GetCount() const;
    LockFreeQueueEntry* pHead;
    LockFreeQueueEntry* pTail;
    unsigned int m_uiDeleteBatchSize;
    LockFreeQueueEntry** m_ppDeletedNodeBuffers;
    Manager* pMenuInterfaceManager;
    volatile int iCount;
    RecursiveSpinLock kLock;

    bool LockFreeQueue_bhkRigidBody_Pop(T& item);
};

#include "LockFreeQueue_LockFreeQueueNode.h"
