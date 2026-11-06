// Unit-private PC LockFreeMap and LipSyncBackgroundManager declarations.
// Public JohnnyGuitarNVSE headers provide members and virtual declaration order.
// Pointer-only dependencies remain genuine forward declarations.
#ifndef FNV_PROCESSLISTS_PRIVATE_LOCK_FREE_MAP_H
#define FNV_PROCESSLISTS_PRIVATE_LOCK_FREE_MAP_H

#include "processlists_layout_support.h"
#include "processlists_sync.h"

class LipTask;
template <class T> class ThreadInterfaceManager;

template <class K, class T> class LockFreeMap : public InterfacedClass
{
  public:
    LockFreeMap(unsigned int auiMaxThreads, unsigned int auiBucketCount, unsigned int auiDeleteBatchSize);
    virtual ~LockFreeMap();

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
    virtual void* AllocateInterface(unsigned int auiThread);

    template <class PTR> struct ThreadSafePointer
    {
        enum
        {
            POINTER_MARK_FLAG = 1u,
            POINTER_MASK = ~1u
        };
        ThreadSafePointer();
        ThreadSafePointer(bool abMark, PTR* apValue);
        volatile PTR* pPointer;
        bool GetMark() const;
        void SetMark(bool abMark);
        void Clear();
        PTR* GetPointer() const;
        PTR* operator->() const;
        operator int();
    };

    struct ThreadSafeHashTableNode
    {
        ThreadSafeHashTableNode(K aKey, const T& arData);
        ~ThreadSafeHashTableNode();
        K tKey;
        T tData;
        ThreadSafePointer<ThreadSafeHashTableNode> pNext;
        bool GetMark() const;
        ThreadSafeHashTableNode* GetNextDelete();
        void SetNextDelete(ThreadSafeHashTableNode* apNext);
    };

    class DeletedNodeScanner
    {
      public:
        DeletedNodeScanner(LockFreeMap* apOwner, ThreadSafeHashTableNode** apNode0, ThreadSafeHashTableNode** apNode1,
                           ThreadSafeHashTableNode** apNode2);
        ~DeletedNodeScanner();
        LockFreeMap* pOwner;
        ThreadSafeHashTableNode** m_ppDeletedNodeBuffers[3];
        ThreadSafePointer<ThreadSafeHashTableNode>* pPrev;
        ThreadSafePointer<ThreadSafeHashTableNode> kCurrent;
        ThreadSafePointer<ThreadSafeHashTableNode> kNext;
        ThreadSafeHashTableNode* m_pDeletedNodeHead;
        unsigned int uiDeleteCount;
        bool GetAt(K aKey, T& arData);
        bool GetAt(unsigned int auiBucket, K aKey, T& arData);
        bool SetAt(K aKey, const T& arData, bool abReplaceExisting);
        bool SetAt(unsigned int auiBucket, K aKey, T& arData, bool abReplaceExisting);
        bool RemoveAt(K aKey);
        bool RemoveAt(unsigned int auiBucket, K aKey);
        bool Remove(unsigned int auiBucket, T& arData);
        bool GetFirst(unsigned int auiBucket, K& arKey, T& arData);
        bool GetNext(unsigned int auiBucket, K& arKey, T& arData);
        bool Find(unsigned int auiBucket, K aKey);
        bool FindValue(unsigned int auiBucket, T& arData);
        void DeleteNode(ThreadSafeHashTableNode* apNode);
        void ClearReferencedNodes();
        void ScanForDeletedNodes();
    };
    typedef ThreadInterfaceManager<DeletedNodeScanner> Manager;
    class LockFreeMapIterator;

    ThreadSafeHashTableNode** m_ppDeletedNodeBuffers;
    unsigned int uiNumBuckets;
    ThreadSafePointer<ThreadSafeHashTableNode>* m_pBuckets;
    unsigned int uiDeleteBatchSize;
    Manager* pManager;
    unsigned int ItemUpdateArray;
    mutable RecursiveSpinLock kLock;

    DeletedNodeScanner* GetInterface();
    unsigned int GetMaxThreads() const;
    unsigned int GetNumBuckets() const;
    unsigned int GetDeleteBatchSize() const;
    ThreadSafePointer<ThreadSafeHashTableNode>* GetBucket(unsigned int auiBucket);
    bool GetNext(LockFreeMapIterator& arIter, K& arKey, T& arData, bool abSwitchBuckets);
    bool GetNextAndRemove(LockFreeMapIterator& arIter, K& arKey, T& arData, bool abSwitchBuckets);
    void RemoveAll(bool abCalledByDestructor);
    void ScanForDeletedNodes();
    void DeleteNode(ThreadSafeHashTableNode* apNode);
    void Lock() const;
    bool TryLock() const;
    void Unlock() const;
};
typedef LockFreeMap<MobileObject*, NiPointer<LipTask> > ProcessListsLipMap;
FNV_STATIC_ASSERT(sizeof(ProcessListsLipMap) == 0x40);
FNV_STATIC_ASSERT(__alignof(ProcessListsLipMap) == 32);
FNV_STATIC_ASSERT(offsetof(ProcessListsLipMap, m_ppDeletedNodeBuffers) == 4);
FNV_STATIC_ASSERT(offsetof(ProcessListsLipMap, uiNumBuckets) == 8);
FNV_STATIC_ASSERT(offsetof(ProcessListsLipMap, m_pBuckets) == 0xC);
FNV_STATIC_ASSERT(offsetof(ProcessListsLipMap, uiDeleteBatchSize) == 0x10);
FNV_STATIC_ASSERT(offsetof(ProcessListsLipMap, pManager) == 0x14);
FNV_STATIC_ASSERT(offsetof(ProcessListsLipMap, ItemUpdateArray) == 0x18);
FNV_STATIC_ASSERT(offsetof(ProcessListsLipMap, kLock) == 0x20);

class LipSyncBackgroundManager
{
  public:
    LockFreeMap<MobileObject*, NiPointer<LipTask> > kLipMap;
};
FNV_STATIC_ASSERT(sizeof(LipSyncBackgroundManager) == 0x40);
FNV_STATIC_ASSERT(__alignof(LipSyncBackgroundManager) == 32);
FNV_STATIC_ASSERT(offsetof(LipSyncBackgroundManager, kLipMap) == 0);
#endif
