#pragma once

// LockFreeMap<K, T>: Bethesda's thread-safe hash map (BSMain ThreadSafeStructures), derives from InterfacedClass.
// RTTI: LockFreeMap<MobileObject *,NiPointer<LipTask> > has 18 vftable slots (destructor, AllocateInterface from the
// base, then the 16 below) and a nested LockFreeMapIterator. 0x40 bytes, 32-byte aligned (the RecursiveSpinLock at
// +0x20): the constructor 0x00906160 calls InterfacedClass's (0x0044d7f0), stores the vftable 0x0108864c, constructs
// the lock at +0x20, zeroes +0x18 and fills +0x0c (buckets), +0x10 and +0x14 (the ThreadInterfaceManager).
// Layout and member names from the unit-private copies (processlists_lock_free_map.h, ThreadSafeStructuresMatch.h).

#include "InterfacedClass.h"
#include "RecursiveSpinLock.h"

template <class T> class ThreadInterfaceManager;

template <class K, class T> class LockFreeMap : public InterfacedClass
{
  public:
    LockFreeMap(unsigned int auiMaxThreads, unsigned int auiBucketCount, unsigned int auiDeleteBatchSize);
    virtual ~LockFreeMap();
    virtual void* AllocateInterface(unsigned int auiThread);

    virtual bool GetAt(K aKey, T& arData);
    virtual bool SetAt(unsigned int auiBucket, K aKey, const T& arData, bool abReplaceExisting);
    virtual bool SetAtAlt(K aKey, const T& arData, bool abReplaceExisting);
    virtual bool RemoveAt(K aKey);
    virtual bool Remove(unsigned int auiBucket, T aData);
    virtual bool RemoveAlt(T aData);
    virtual bool GetAtAlt(K aKey, T& arData);
    virtual unsigned int GetBucketForKey(K aKey);
    virtual void DeleteKey(K aKey);
    virtual K CopyKey(K aKey);
    virtual void CopyKeyDirect(K aKey, K& arCopiedKey);
    virtual bool IsKeyGreaterOrEqual(K aKey1, K aKey2) const;
    virtual bool IsKeyEqual(K aKey1, K aKey2) const;
    virtual void IncrementCount();
    virtual void DecrementCount();
    virtual unsigned int GetCount() const;

    template <class PTR> struct ThreadSafePointer
    {
        ThreadSafePointer();
        ThreadSafePointer(bool abMark, PTR* apValue);
        volatile PTR* pPointer;
        bool GetMark() const;
        void SetMark(bool abMark);
        void Clear();
        PTR* GetPointer() const;
        PTR* operator->() const;
    };

    struct ThreadSafeHashTableNode
    {
        ThreadSafeHashTableNode(K aKey, const T& arData);
        ~ThreadSafeHashTableNode();
        K tKey;
        T tData;
        ThreadSafePointer<ThreadSafeHashTableNode> pNext;
        ThreadSafeHashTableNode* GetNextDelete();
        void SetNextDelete(ThreadSafeHashTableNode* apNext);
    };

    class DeletedNodeScanner;
    class LockFreeMapIterator;
    typedef ThreadInterfaceManager<DeletedNodeScanner> Manager;

    ThreadSafeHashTableNode** m_ppDeletedNodeBuffers;               // 0x04
    unsigned int uiNumBuckets;                                      // 0x08
    ThreadSafePointer<ThreadSafeHashTableNode>* m_pBuckets;         // 0x0c
    unsigned int uiDeleteBatchSize;                                 // 0x10
    Manager* pManager;                                              // 0x14
    unsigned int uiCount;                                           // 0x18 ctor: 0
    mutable RecursiveSpinLock kLock;                                // 0x20

    DeletedNodeScanner* GetInterface();
    unsigned int GetMaxThreads() const;
    unsigned int GetNumBuckets() const;
    void RemoveAll(bool abCalledByDestructor);
    void ScanForDeletedNodes();
    void DeleteNode(ThreadSafeHashTableNode* apNode);
    void Lock() const;
    bool TryLock() const;
    void Unlock() const;
};

// Exe 0x0044f070: scanner state is 0x24 bytes; uses three deletion buffers per thread.
template <class K, class T> class LockFreeMap<K, T>::DeletedNodeScanner
{
  public:
    LockFreeMap* pOwner;
    ThreadSafeHashTableNode** m_ppDeletedNodeBuffers[3];
    ThreadSafePointer<ThreadSafeHashTableNode>* pPrev;
    ThreadSafePointer<ThreadSafeHashTableNode> Current;
    ThreadSafePointer<ThreadSafeHashTableNode> Next;
    ThreadSafeHashTableNode* m_pDeletedNodeHead;
    unsigned int m_uiDeleteCount;
    void ScanForDeletedNodes();
};
