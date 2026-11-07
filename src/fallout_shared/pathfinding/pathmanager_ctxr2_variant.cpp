// fallout_shared/pathfinding/pathmanager_ctxr2_variant.cpp: free functions (1 function)

#include "../../../include/PathingRequest.h"

class PathManagerImpl
{
  public:
    char pad[0x14c0];
};

class BSSpinLock_r006eb6b0
{
  public:
    void Lock(const char*);
    void Unlock();
};

struct PathSlot
{
    int unk00;
    int unk04;
};

struct PathWorkList
{
    int unk00[4];
    PathWorkList();
    ~PathWorkList();
    bool LockFreeMap_char_const_Model_LockFreeMapIterator_GetFinished();
};

struct PathIndex
{
    bool TryGetNextEntry(PathWorkList* list, PathingRequest** ref, int* out, bool flag);
};

struct FUN_006eb6b0_cls : public PathManagerImpl
{
    void PathManagerImpl_CancelCurrentPathsAndPause_0(int id);
};

// @fnv 0x006eb6b0
// src: COMMUNITY 0x006eb6b0
void FUN_006eb6b0_cls::PathManagerImpl_CancelCurrentPathsAndPause_0(int id)
{
    reinterpret_cast<BSSpinLock_r006eb6b0*>(reinterpret_cast<char*>(this) + 0xc38)
        ->Lock("PathManagerImpl::CancelCurrentPathsAndPause");
    PathingRequest* ref;
    int outA2;
    PathWorkList list3;
    while (!list3.LockFreeMap_char_const_Model_LockFreeMapIterator_GetFinished())
    {
        if (reinterpret_cast<PathIndex*>(reinterpret_cast<char*>(this) + 0x1480)
                ->TryGetNextEntry(&list3, &ref, &outA2, true))
        {
            if (reinterpret_cast<PathSlot*>(ref->GetActorLockData())->unk04 == id)
            {
                reinterpret_cast<PathSlot*>(ref->GetActorLockData())->unk04 = 0;
                reinterpret_cast<PathSlot*>(ref->GetActorLockData())->unk00 = 0;
            }
        }
    }
    reinterpret_cast<BSSpinLock_r006eb6b0*>(reinterpret_cast<char*>(this) + 0xc38)->Unlock();
}
