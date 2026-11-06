// Unit-private PC declarations from the public JohnnyGuitarNVSE Bethesda
// task-data, tasklet, message-queue and free-list headers. No implementations.
#ifndef FNV_PROCESSLISTS_PRIVATE_TASK_DATA_H
#define FNV_PROCESSLISTS_PRIVATE_TASK_DATA_H

#include "processlists_layout_support.h"
#include "processlists_sync.h"

class MobileObject;
class BSWin32TaskletGroupData;

class MobileObjectTaskletContext
{
  public:
    MobileObjectTaskletContext();
    MobileObjectTaskletContext(MobileObject* apObject);
    MobileObjectTaskletContext(unsigned int auiObjectCount);
    ~MobileObjectTaskletContext();
    enum Type
    {
        START = 0,
        EXECUTE = 1,
        END = 2
    };

    unsigned int eType;
    unsigned int uiObjectCount;
    MobileObject* pObject;
};
FNV_STATIC_ASSERT(sizeof(MobileObjectTaskletContext) == 0xC);
FNV_STATIC_ASSERT(offsetof(MobileObjectTaskletContext, eType) == 0);
FNV_STATIC_ASSERT(offsetof(MobileObjectTaskletContext, uiObjectCount) == 4);
FNV_STATIC_ASSERT(offsetof(MobileObjectTaskletContext, pObject) == 8);

#include "../../../../include/BSTStaticFreeList.h"

#include "../../../../include/BSTStaticFreeList.h"

#include "../../../../include/BSTStaticFreeList.h"
FNV_STATIC_ASSERT(sizeof(BSTFreeListElem<MobileObjectTaskletContext>) == 0x10);
FNV_STATIC_ASSERT(offsetof(BSTFreeListElem<MobileObjectTaskletContext>, kRawElem) == 0);
FNV_STATIC_ASSERT(offsetof(BSTFreeListElem<MobileObjectTaskletContext>, pNext) == 0xC);
FNV_STATIC_ASSERT(sizeof(BSTFreeList<MobileObjectTaskletContext>) == 0xC);
FNV_STATIC_ASSERT(offsetof(BSTFreeList<MobileObjectTaskletContext>, m_uiLockState) == 4);
FNV_STATIC_ASSERT(offsetof(BSTFreeList<MobileObjectTaskletContext>, pFree) == 8);
typedef BSTStaticFreeList<MobileObjectTaskletContext, 4096> ProcessListsMessagePool;
FNV_STATIC_ASSERT(sizeof(ProcessListsMessagePool) == 0x1000C);
FNV_STATIC_ASSERT(offsetof(ProcessListsMessagePool, kElems) == 0xC);

template <class T> class BSTMessageQueue
{
  public:
    BSTMessageQueue();
    virtual ~BSTMessageQueue();
    virtual bool Push(const T& arMessage) = 0;
    virtual bool TryPush(const T& arMessage) = 0;
    virtual bool Pop(T& arMessage) = 0;
    virtual bool TryPop(T& arMessage) = 0;
    virtual bool EnqueueMessage(const T& arMessage) = 0;
    virtual bool RemoveMessage(T& arMessage) = 0;
};

template <class T> class BSTCommonMessageQueue : public BSTMessageQueue<T>
{
  public:
    BSTCommonMessageQueue();
    virtual ~BSTCommonMessageQueue();

    LockPrimitive kLock;

    virtual bool Push(const T& arMessage);
    virtual bool TryPush(const T& arMessage);
    virtual bool Pop(T& arMessage);
    virtual bool TryPop(T& arMessage);
    virtual bool EnqueueMessage(const T& arMessage);
    virtual bool RemoveMessage(T& arMessage);
};

template <class T> class BSTCommonLLMessageQueue : public BSTCommonMessageQueue<T>
{
  public:
    BSTCommonLLMessageQueue(BSTFreeList<T>* apList);
    virtual ~BSTCommonLLMessageQueue();

    BSTFreeList<T>* pSizeClassFreeList;
    BSTFreeListElem<T>* pHead;
    BSTFreeListElem<T>** m_ppTailLink;

    virtual bool EnqueueMessage(const T& arMessage);
    virtual bool RemoveMessage(T& arMessage);
};
FNV_STATIC_ASSERT(sizeof(BSTMessageQueue<MobileObjectTaskletContext>) == 4);
FNV_STATIC_ASSERT(sizeof(BSTCommonMessageQueue<MobileObjectTaskletContext>) == 8);
FNV_STATIC_ASSERT(offsetof(BSTCommonMessageQueue<MobileObjectTaskletContext>, kLock) == 4);
FNV_STATIC_ASSERT(sizeof(BSTCommonLLMessageQueue<MobileObjectTaskletContext>) == 0x14);
FNV_STATIC_ASSERT(offsetof(BSTCommonLLMessageQueue<MobileObjectTaskletContext>, pSizeClassFreeList) == 8);
FNV_STATIC_ASSERT(offsetof(BSTCommonLLMessageQueue<MobileObjectTaskletContext>, pHead) == 0xC);
FNV_STATIC_ASSERT(offsetof(BSTCommonLLMessageQueue<MobileObjectTaskletContext>, m_ppTailLink) == 0x10);

class BSTaskletData
{
  public:
    BSTaskletData();
    virtual ~BSTaskletData();
    virtual bool StartTaskThread();
    virtual void Process();
    virtual void OnComplete();

    bool m_bTaskYielded;

    void TaskYield();
};
FNV_STATIC_ASSERT(sizeof(BSTaskletData) == 8);
FNV_STATIC_ASSERT(offsetof(BSTaskletData, m_bTaskYielded) == 4);

class BSWin32TaskletData : public BSTaskletData
{
  public:
    BSWin32TaskletData();
    virtual ~BSWin32TaskletData();

    BSWin32TaskletGroupData* m_pTaskletGroupData;
    bool m_bFlagAfterTaskletGroup;
    LockPrimitive kTaskDataLock;
    BSWin32TaskletData* m_pTaskletData;
};
FNV_STATIC_ASSERT(sizeof(BSWin32TaskletData) == 0x18);
FNV_STATIC_ASSERT(offsetof(BSWin32TaskletData, m_pTaskletGroupData) == 8);
FNV_STATIC_ASSERT(offsetof(BSWin32TaskletData, m_bFlagAfterTaskletGroup) == 0xC);
FNV_STATIC_ASSERT(offsetof(BSWin32TaskletData, kTaskDataLock) == 0x10);
FNV_STATIC_ASSERT(offsetof(BSWin32TaskletData, m_pTaskletData) == 0x14);

class MobileObjectTaskletData : public BSWin32TaskletData
{
  public:
    MobileObjectTaskletData(BSTFreeList<MobileObjectTaskletContext>* apList);
    virtual ~MobileObjectTaskletData();
    virtual void SetMobileObjectCount(unsigned int auiObjectCount);
    virtual void ProcessMobileObject(MobileObject* apObject);
    virtual void SetThreadNumber(unsigned int auiThreadNumber);

    BSSimpleList<MobileObject*>* pMobList;
    BSTCommonLLMessageQueue<MobileObjectTaskletContext> kMessageQueue;
    unsigned int MobileObjectTaskletState;
    unsigned int eType;
};
FNV_STATIC_ASSERT(sizeof(MobileObjectTaskletData) == 0x38);
FNV_STATIC_ASSERT(offsetof(MobileObjectTaskletData, pMobList) == 0x18);
FNV_STATIC_ASSERT(offsetof(MobileObjectTaskletData, kMessageQueue) == 0x1C);
FNV_STATIC_ASSERT(offsetof(MobileObjectTaskletData, MobileObjectTaskletState) == 0x30);
FNV_STATIC_ASSERT(offsetof(MobileObjectTaskletData, eType) == 0x34);

class DetectionTaskData : public MobileObjectTaskletData
{
  public:
    float m_fDetectionValue;
    int m_iDetectionState;
};
FNV_STATIC_ASSERT(sizeof(DetectionTaskData) == 0x40);
FNV_STATIC_ASSERT(offsetof(DetectionTaskData, m_fDetectionValue) == 0x38);
FNV_STATIC_ASSERT(offsetof(DetectionTaskData, m_iDetectionState) == 0x3C);

class AnimationTaskData : public MobileObjectTaskletData
{
};
FNV_STATIC_ASSERT(sizeof(AnimationTaskData) == 0x38);

class PackageUpdateTaskData : public MobileObjectTaskletData
{
  public:
    BSSimpleList<MobileObject*>* pPrevObjectList;
    unsigned int uiUpdatedCount;
    unsigned int uiSkippedCount;
};
FNV_STATIC_ASSERT(sizeof(PackageUpdateTaskData) == 0x44);
FNV_STATIC_ASSERT(offsetof(PackageUpdateTaskData, pPrevObjectList) == 0x38);
FNV_STATIC_ASSERT(offsetof(PackageUpdateTaskData, uiUpdatedCount) == 0x3C);
FNV_STATIC_ASSERT(offsetof(PackageUpdateTaskData, uiSkippedCount) == 0x40);

class ActorUpdateTaskData : public MobileObjectTaskletData
{
  public:
    unsigned int uiRunCount;
};
FNV_STATIC_ASSERT(sizeof(ActorUpdateTaskData) == 0x3C);
FNV_STATIC_ASSERT(offsetof(ActorUpdateTaskData, uiRunCount) == 0x38);

class ActorsScriptTaskData : public MobileObjectTaskletData
{
  public:
    BSSimpleList<MobileObject*>* pPrevObjectList;
    unsigned int uiRunCount;
};
FNV_STATIC_ASSERT(sizeof(ActorsScriptTaskData) == 0x40);
FNV_STATIC_ASSERT(offsetof(ActorsScriptTaskData, pPrevObjectList) == 0x38);
FNV_STATIC_ASSERT(offsetof(ActorsScriptTaskData, uiRunCount) == 0x3C);

class MovementTaskData : public MobileObjectTaskletData
{
  public:
    unsigned int uiRunCount;
};
FNV_STATIC_ASSERT(sizeof(MovementTaskData) == 0x3C);
FNV_STATIC_ASSERT(offsetof(MovementTaskData, uiRunCount) == 0x38);

class ActorTaskManager
{
  public:
    DetectionTaskData kDetectionTaskData;
    AnimationTaskData kAnimationTaskData;
    PackageUpdateTaskData kPackageUpdateTaskData;
    ActorUpdateTaskData kActorUpdateTaskData;
    ActorsScriptTaskData kActorsScriptTaskData;
    MovementTaskData kMovementTaskData;
    BSTStaticFreeList<MobileObjectTaskletContext, 4096> kMessagePool;
    bool m_bTrailingManagerFlag;
};
FNV_STATIC_ASSERT(sizeof(ActorTaskManager) == 0x10184);
FNV_STATIC_ASSERT(offsetof(ActorTaskManager, kDetectionTaskData) == 0);
FNV_STATIC_ASSERT(offsetof(ActorTaskManager, kAnimationTaskData) == 0x40);
FNV_STATIC_ASSERT(offsetof(ActorTaskManager, kPackageUpdateTaskData) == 0x78);
FNV_STATIC_ASSERT(offsetof(ActorTaskManager, kActorUpdateTaskData) == 0xBC);
FNV_STATIC_ASSERT(offsetof(ActorTaskManager, kActorsScriptTaskData) == 0xF8);
FNV_STATIC_ASSERT(offsetof(ActorTaskManager, kMovementTaskData) == 0x138);
FNV_STATIC_ASSERT(offsetof(ActorTaskManager, kMessagePool) == 0x174);
FNV_STATIC_ASSERT(offsetof(ActorTaskManager, m_bTrailingManagerFlag) == 0x10180);
#endif
