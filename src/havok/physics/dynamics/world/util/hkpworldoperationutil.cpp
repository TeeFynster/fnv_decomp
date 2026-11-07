#include "../../../../../../include/hkArray.h"
// src/havok/physics/dynamics/world/util/hkpworldoperationutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/util/hkpworldoperationutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/Actor.h"
#include "../../../../../../include/hkpCollidableQualityType.h"
#include "../../../../../../include/hkpSimulationIsland.h"
#include "../../../../../../include/hkpWorld.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/hkBool.h"
#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkpAction.h"
#include "../../../../../../include/hkpConstraintInstance.h"
#include "../../../../../../include/hkpEntity.h"

template <class T> __forceinline T* hkMemoryAllocator::_bufAlloc(int& reqNumInOut)
{
    int n = reqNumInOut * sizeof(T);
    T* p = (T*)bufAlloc(n);
    reqNumInOut = n / (int)sizeof(T);
    return p;
}

struct FUN_00cb7460_class
{
    int __thiscall hkpAgentNnTrack_getSectorSize(int value);
};

// @fnv 0x00cb7460
// src: HAVOK_LIB 0x00cb7460
int __thiscall FUN_00cb7460_class::hkpAgentNnTrack_getSectorSize(int value)
{
    if (value + 1 == *(int*)((char*)this + 8))
        return *(int*)this;
    return 0x200;
}

// If the slot index at p+0x22 is not 0xffff, clears the entry in the array at thisPtr+0x40 and resets the index to 0xffff.
// @fnv 0x00cb3fd0
void ClearSlotReference(int* thisPtr, int* p)
{
    unsigned short* s = (unsigned short*)((char*)p + 0x22);
    if (*s != 0xffff)
    {
        int* base = *(int**)((char*)thisPtr + 0x40);
        base[*s] = 0;
        *s = 0xffff;
    }
}

void hkpWorldConstraintUtil_addConstraint(int first, int second);
void hkpWorldCallbackUtil_fireConstraintAdded(int first, int second);
// @fnv 0x00cb3c80
// src: HAVOK_LIB 0x00cb3c80
void hkpWorldOperationUtil_addConstraintToCriticalLockedIsland(int first, int second)
{
    hkpWorldConstraintUtil_addConstraint(first, second);
    hkpWorldCallbackUtil_fireConstraintAdded(first, second);
}

void __cdecl hkpWorldConstraintUtil_addConstraint(hkpWorld* object, int* value);
void __cdecl hkpWorldCallbackUtil_fireConstraintAdded(hkpWorld* object, int* value);

// @fnv 0x00cb3ca0
// src: HAVOK_LIB 0x00cb3ca0
int* __cdecl hkpWorldOperationUtil_addConstraintImmediately(hkpWorld* object, int* value, int shouldNotify)
{
    ++object->m_iCriticalOperationsLockCount;
    hkpWorldConstraintUtil_addConstraint(object, value);
    if (shouldNotify != 0)
    {
        hkpWorldCallbackUtil_fireConstraintAdded(object, value);
    }
    --object->m_iCriticalOperationsLockCount;
    if (object->m_iCriticalOperationsLockCount == 0 && object->m_bBlockExecutingPendingOperations.m_cBooleanValue == 0)
    {
        if (object->m_iPendingOperationCount != 0)
        {
            object->FUN_00c91120();
        }
        if (object->m_iPendingOperationQueueCount == 1 && object->m_iQueuedOperationCount != 0)
        {
            object->UpdateFields_00c91140();
        }
    }
    return value;
}

void NotifyTargets(hkpWorld* ctx, void* p);
void DetachRecord(void* p);

// If ctx->m_kConstraintListeners.m_iElementCount is nonzero, calls NotifyTargets with ctx and p, then always calls DetachRecord on p.
// @fnv 0x00cb3da0
// src: GUESS 0x00cb3da0 (confidence: medium)
void Object_NotifyAndDetachRecord(hkpWorld* ctx, void* p)
{
    if (ctx->m_kConstraintListeners.m_iElementCount != 0)
        NotifyTargets(ctx, p);
    DetachRecord(p);
}

struct CB3DD0Collidable
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    unsigned char unk24;
    unsigned char m_flags;
};

inline void hkpWorld::lockCriticalOperations()
{
    m_iCriticalOperationsLockCount++;
}
inline void hkpWorld::unlockCriticalOperations()
{
    if (--m_iCriticalOperationsLockCount)
        return;
    if (m_bBlockExecutingPendingOperations.m_cBooleanValue)
        return;
    if (m_iPendingOperationCount)
        ExecutePendingOperations();
    if (m_iPendingOperationQueueCount == 1 && m_iQueuedOperationCount)
        ExecutePendingOperationQueues();
}

void __cdecl NotifyTargets(hkpWorld* world, hkpConstraintInstance* entity);
void __cdecl DetachRecord(hkpConstraintInstance* entity);

// @fnv 0x00cb3dd0
// src: HAVOK_LIB 0x00cb3dd0
void __cdecl hkpWorldOperationUtil_removeConstraintImmediately(hkpWorld* world, hkpConstraintInstance* entity, int fireCallbacks)
{
    CB3DD0Collidable* collidable = reinterpret_cast<CB3DD0Collidable*>(entity->m_pOwnerObject);
    collidable->m_flags = (collidable->m_flags & ~2) | 1;
    if (world->m_iCriticalOperationsLockCount)
    {
        if (fireCallbacks && world->m_kConstraintListeners.m_iElementCount)
            NotifyTargets(world, entity);
        DetachRecord(entity);
        return;
    }
    world->lockCriticalOperations();
    if (fireCallbacks && world->m_kConstraintListeners.m_iElementCount)
        NotifyTargets(world, entity);
    DetachRecord(entity);
    world->unlockCriticalOperations();
}

// The shared island header does not yet declare FUN_00d070b0().
struct FUN_00d070b0_class
{
    void nullsub_30();
};

// Calls FUN_00d070b0 on every object in firstObjects and secondObjects in reverse order, then on finalObject.
// @fnv 0x00cb3e90
// src: HAVOK_LIB 0x00cb3e90
void __cdecl hkpWorldOperationUtil_validateWorld(hkpWorld* apCleanupList)
{
    int i = apCleanupList->m_kActiveSimulationIslands.m_iElementCount - 1;
    while (i >= 0)
    {
        static_cast<FUN_00d070b0_class*>(apCleanupList->m_kActiveSimulationIslands.m_data[i])->nullsub_30();
        --i;
    }
    i = apCleanupList->m_kInactiveSimulationIslands.m_iElementCount - 1;
    while (i >= 0)
    {
        static_cast<FUN_00d070b0_class*>(apCleanupList->m_kInactiveSimulationIslands.m_data[i])->nullsub_30();
        --i;
    }
    static_cast<FUN_00d070b0_class*>(apCleanupList->m_pFixedIsland)->nullsub_30();
}

struct Obj;

// The shared island header does not yet declare RemoveItem(Obj*).
struct Agent
{
    virtual void v0(int);
    char pad0[0x20 - 4];
    unsigned short m_20;
    char pad1[0x4c - 0x22];
    int m_4c;
    __declspec(nothrow) void RemoveItem(Obj* o);
};

struct Obj
{
    int pad0[2];
    int m_8;
    char pad1[0xc8 - 0xc];
    char pad2[4];
    Agent* m_cc;
};

__declspec(nothrow) void __cdecl RemoveListItem(hkpWorld* o, Agent* a);

// Clears o->m_8, calls the agent's RemoveItem, and if the agent's m_20 is not 0xffff, m_4c is 0 and ctx->m_c8 is set, calls RemoveListItem and v0(1).
// @fnv 0x00cb4740
// src: HAVOK_LIB 0x00cb4740
void __cdecl hkpWorldOperationUtil_removeEntitySI(hkpWorld* ctx, Obj* o)
{
    Agent* a = o->m_cc;
    o->m_8 = 0;
    a->RemoveItem(o);
    if (a->m_20 != 0xffff && a->m_4c == 0 && ctx->m_bWantSimulationIslands.m_cBooleanValue)
    {
        RemoveListItem(ctx, a);
        a->v0(1);
    }
}


struct S_00cb5d00_Stack
{
    char* m_next;
    int unk04;
    int unk08;
    int unk0C;
    void* allocateStack(int nbytes) throw()
    {
        char* p = m_next;
        m_next = p + ((nbytes + 127) & ~127);
        return p;
    }
    void deallocateStack(void* p) throw()
    {
        m_next = (char*)p;
    }
};
struct S_00cb5d00_Router
{
    S_00cb5d00_Stack m_aiEntries;
    hkMemoryAllocator* m_pStreamAllocator;
    static S_00cb5d00_Router& hkMemoryRouter_getInstance() throw();
    S_00cb5d00_Stack& stack() throw()
    {
        return m_aiEntries;
    }
    hkMemoryAllocator& heap() throw()
    {
        return *m_pStreamAllocator;
    }
};
struct S_00cb5d00_Elem
{
    int unk00;
    int unk04;
};
template <class T>
static __forceinline void S_00cb5d00_Array_destroy(hkArrayBase<T>& self) throw();

template <class T>
static __forceinline void S_00cb5d00_Array__clearAndDeallocate(hkArrayBase<T>& self, hkMemoryAllocator& alloc) throw();

template <class T>
static __forceinline void S_00cb5d00_Array_destroy(hkArrayBase<T>& self) throw()
{
        S_00cb5d00_Array__clearAndDeallocate(self, *S_00cb5d00_Router::hkMemoryRouter_getInstance().m_pStreamAllocator);
    }

template <class T>
static __forceinline void S_00cb5d00_Array__clearAndDeallocate(hkArrayBase<T>& self, hkMemoryAllocator& alloc) throw()
{
        self.m_iElementCount = 0;
        if ((self.m_iCapacityState & 0x80000000) == 0)
            alloc.bufFree(self.m_data, (self.m_iCapacityState & 0x3fffffff) * sizeof(T));
        self.m_data = 0;
        self.m_iCapacityState = 0x80000000;
    }

struct S_00cb5d00_ArrayPolicy
{
    template <class T>
    static __forceinline void destroy(hkArrayBase<T>& self) { S_00cb5d00_Array_destroy(self); }
};
template <class T> struct S_00cb5d00_LocalArray : hkArray<T, S_00cb5d00_ArrayPolicy>
{
    T* m_pStackAllocation;
    __forceinline S_00cb5d00_LocalArray(int capacity) throw()
    {
        this->m_data = (T*)S_00cb5d00_Router::hkMemoryRouter_getInstance().stack().allocateStack(capacity * sizeof(T));
        this->m_iCapacityState = capacity | 0x80000000;
        m_pStackAllocation = this->m_data;
    }
    __forceinline ~S_00cb5d00_LocalArray() throw()
    {
        T* mem = m_pStackAllocation;
        if (mem == this->m_data)
            this->m_iElementCount = 0;
        S_00cb5d00_Router::hkMemoryRouter_getInstance().stack().deallocateStack(mem);
    }
};
struct S_00cb5d00_Source
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C(void* key, hkArray<S_00cb5d00_Elem, S_00cb5d00_ArrayPolicy>* out);
    void query(void* key, hkArray<S_00cb5d00_Elem, S_00cb5d00_ArrayPolicy>* out) throw()
    {
        unk1C(key, out);
    }
};
struct S_00cb5d00_Sink
{
    void DispatchPairs(S_00cb5d00_Elem* data, int n) throw();
};

struct S_00cb5d00_Query
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
};
// @fnv 0x00cb5d00
// src: HAVOK_LIB 0x00cb5d00
void hkpWorldOperationUtil_removePhantomBP(hkpWorld* owner, S_00cb5d00_Query* query)
{
    S_00cb5d00_LocalArray<S_00cb5d00_Elem> results(owner->m_iBroadPhaseQuerySize);
    static_cast<S_00cb5d00_Source*>(owner->m_pJobSemaphore)->query(&query->unk24, &results);
    if (results.m_iElementCount != 0)
        static_cast<S_00cb5d00_Sink*>(owner->m_pBroadPhaseDispatcher)->DispatchPairs(results.m_data, results.m_iElementCount);
}


extern void __cdecl PropagateStateToChildren(hkpWorld*, int*);
// If object->enabled is set, walks object->items backwards and calls PropagateStateToChildren for each item whose byte at offset 0x25 has bits 0-1 set.
// @fnv 0x00cb6f30
// src: HAVOK_LIB 0x00cb6f30
void __cdecl hkpWorldOperationUtil_splitSimulationIslands(hkpWorld* object)
{
    if (object->m_bWantSimulationIslands.m_cBooleanValue != 0)
    {
        int index = object->m_kActiveSimulationIslands.m_iElementCount - 1;
        for (; index >= 0; --index)
        {
            int* item = static_cast<int*>(object->m_kActiveSimulationIslands.m_data[index]);
            if ((*(unsigned char*)((char*)item + 0x25) & 3) != 0)
                PropagateStateToChildren(object, item);
        }
    }
}

struct Box
{
    char pad[0x14];
    unsigned short a;
    unsigned short b;
    unsigned short c;
};

struct Holder
{
    char pad[0x30];
    Box* box;
};

struct Stats
{
    char pad[8];
    int maxv;
    int sum0;
    int sum1;
    int sum2;
    void AccumulateStats(Holder* h, const int* s);
};

// If the holder has a box, updates maxv and the three sums from s, adds s[1..3] into the box fields, and raises maxv to the box's a.
// @fnv 0x00cb74d0
void Stats::AccumulateStats(Holder* apHolder, const int* aiStats)
{
    if (apHolder->box)
    {
        {
            int t = aiStats[0];
            maxv = maxv > t ? maxv : t;
        }
        maxv = maxv > aiStats[1] ? maxv : aiStats[1];
        sum0 += aiStats[1];
        sum1 += aiStats[2];
        sum2 += aiStats[3];
        Box* b = apHolder->box;
        int nc = b->c + aiStats[3];
        int na = b->a + aiStats[1];
        b->b += aiStats[2];
        b->c = nc;
        b->a = na;
        int a = apHolder->box->a;
        maxv = maxv > a ? maxv : a;
    }
}


struct S_00dd7d00_Item;

typedef hkBool(__cdecl* S_00dd7d00_Less)(S_00dd7d00_Item* a, S_00dd7d00_Item* b);

// Sorts the range [d, h] of pArr in place with a Hoare-style quicksort using cmpLess, recursing on the left part and looping on the right.
// @fnv 0x00dd7d00
// src: XBOX_PDB 0x00dd7d00
void hkAlgorithm_quickSortRecursive_hkFreeList_Block_hkBool_cdecl_hkFreeList_Block_const_hkFreeList_Block_const(S_00dd7d00_Item** apItems, int aiLow, int aiHigh, S_00dd7d00_Less apfnLess)
{
    int i, j;
    __declspec(align(16)) S_00dd7d00_Item* pPivot;
begin:
    i = aiHigh;
    j = aiLow;
    pPivot = apItems[(aiLow + aiHigh) >> 1];
    do
    {
        while (apfnLess(apItems[j], pPivot))
            j++;
        while (apfnLess(pPivot, apItems[i]))
            i--;
        if (i >= j)
        {
            if (i != j)
            {
                S_00dd7d00_Item* pTemp = apItems[i];
                apItems[i] = apItems[j];
                apItems[j] = pTemp;
            }
            i--;
            j++;
        }
    } while (j <= i);
    if (aiLow < i)
        hkAlgorithm_quickSortRecursive_hkFreeList_Block_hkBool_cdecl_hkFreeList_Block_const_hkFreeList_Block_const(apItems, aiLow, i, apfnLess);
    if (j < aiHigh)
    {
        aiLow = j;
        goto begin;
    }
}

struct S_00c6aca0_Tls
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int ctx;
};
__declspec(thread) S_00c6aca0_Tls DAT_tls;

struct S_00c6aca0_Ctx
{
    int saved;
    __forceinline S_00c6aca0_Ctx(int c)
    {
        saved = DAT_tls.ctx;
        DAT_tls.ctx = c;
    }
    __forceinline ~S_00c6aca0_Ctx()
    {
        DAT_tls.ctx = saved;
    }
};


__forceinline void ReturnMemoryBlock(hkMemoryAllocator& allocator, void* p, int bytes) throw()
{
    allocator.bufFree(p, bytes);
}

struct S_00c6aca0_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkMemoryAllocator* m10;
    __forceinline hkMemoryAllocator& heap()
    {
        return *m10;
    }
};
S_00c6aca0_Router* hkMemoryRouter_getInstance() throw();

struct S_00c6aca0_Item
{
    virtual ~S_00c6aca0_Item();
};
struct S_00c6aca0_Arr4
{
    S_00c6aca0_Item** m_data;
    int m_iElementCount;
    int m_cap;
    __forceinline void _clearAndDeallocate(hkMemoryAllocator& h) throw()
    {
        int cap = m_cap;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
        {
            int n = cap & 0x3fffffff;
            ReturnMemoryBlock(h, m_data, n * 4);
        }
        m_data = 0;
        m_cap = 0x80000000;
    }
    __forceinline ~S_00c6aca0_Arr4() throw()
    {
        _clearAndDeallocate(hkMemoryRouter_getInstance()->heap());
    }
};
struct S_00c6aca0_Arr8
{
    void* m_data;
    int m_iElementCount;
    int m_cap;
    __forceinline void _clearAndDeallocate(hkMemoryAllocator& h) throw()
    {
        int cap = m_cap;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
            ReturnMemoryBlock(h, m_data, (cap & 0x3fffffff) * 8);
        m_data = 0;
        m_cap = 0x80000000;
    }
    __forceinline ~S_00c6aca0_Arr8() throw()
    {
        _clearAndDeallocate(hkMemoryRouter_getInstance()->heap());
    }
};

struct S_00c6aca0_Cont
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ~S_00c6aca0_Cont();
    void DeleteListNodesAndReleaseOwner();
};

struct S_00c6aca0_Mm
{
    void MemoryManager_Deallocate(int p);
};
extern S_00c6aca0_Mm DAT_011f6238;
extern int DAT_012677a4;

struct S_00c6aca0_Ref
{
    void FUN_00c905b0();
};
struct S_00c6aca0_Base
{
    int unk04;
    int unk08;
    int unk0c;
    virtual ~S_00c6aca0_Base();
    void bhkSerializable_Kill();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    __forceinline void callVfn94()
    {
        vfn_94();
    }
};

struct FUN_00c6aca0 : S_00c6aca0_Base
{
    S_00c6aca0_Ref* unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    S_00c6aca0_Arr4 unk70;
    S_00c6aca0_Arr8 unk7c;
    int unk88;
    int unk8c;
    S_00c6aca0_Cont unk90;
    ~FUN_00c6aca0();
};

// @fnv 0x00c6aca0
FUN_00c6aca0::~FUN_00c6aca0()
{
    S_00c6aca0_Ctx ctxOuter(0x10);
    --DAT_012677a4;
    {
        S_00c6aca0_Ctx inner(0x10);
        if (unk10)
        {
            callVfn94();
            unk10->FUN_00c905b0();
            unk10 = 0;
        }
    }
    callVfn94();
    bhkSerializable_Kill();
    {
        int p = unk2c;
        DAT_011f6238.MemoryManager_Deallocate(p);
    }
    {
        int p = unk34;
        DAT_011f6238.MemoryManager_Deallocate(p);
    }
    {
        int p = unk3c;
        DAT_011f6238.MemoryManager_Deallocate(p);
    }
    {
        int p = unk44;
        DAT_011f6238.MemoryManager_Deallocate(p);
    }
    {
        int p = unk4c;
        DAT_011f6238.MemoryManager_Deallocate(p);
    }
    for (int i = 0; i < unk70.m_iElementCount; i++)
    {
        S_00c6aca0_Item* p = unk70.m_data[i];
        if (p)
            delete p;
    }
    unk70.m_iElementCount = 0;
    unk90.DeleteListNodesAndReleaseOwner();
}

// Returns false if b is null, true if a is null, otherwise compares a's inner unkD4 against b's inner unkD4.
// @fnv 0x00cb3f90
// src: HAVOK_LIB 0x00cb3f90
hkBool worldOperationUtil_less_hkSimulationIslandPtr(hkpSimulationIsland* pObjA, hkpSimulationIsland* pObjB)
{
    if (!pObjB)
        return false;
    if (!pObjA)
        return true;
    return pObjA->entities.data[0]->m_uiUniqueId < pObjB->entities.data[0]->m_uiUniqueId;
}

namespace fnv_00cb4000 {

void ClearSlotReference(int* thisPtr, int* p);

// Removes item from one of the owner's two lists by swapping in the last element, fixes its index, decrements the count, then calls ClearSlotReference.
// @fnv 0x00cb4000
void RemoveListItem(hkpWorld* self, hkpSimulationIsland* volatile item)
{
    hkpSimulationIsland* pItem = item;
    if ((pItem->flags26 & 3) == 0)
    {
        hkpSimulationIsland** arr = reinterpret_cast<hkpSimulationIsland**>(self->m_kInactiveSimulationIslands.m_data);
        int last = self->m_kInactiveSimulationIslands.m_iElementCount - 1;
        arr[pItem->storageIndex] = arr[last];
        reinterpret_cast<hkpSimulationIsland**>(self->m_kInactiveSimulationIslands.m_data)[pItem->storageIndex]->storageIndex = pItem->storageIndex;
        self->m_kInactiveSimulationIslands.m_iElementCount--;
    }
    else
    {
        hkpSimulationIsland** arr = reinterpret_cast<hkpSimulationIsland**>(self->m_kActiveSimulationIslands.m_data);
        int last = self->m_kActiveSimulationIslands.m_iElementCount - 1;
        arr[pItem->storageIndex] = arr[last];
        reinterpret_cast<hkpSimulationIsland**>(self->m_kActiveSimulationIslands.m_data)[pItem->storageIndex]->storageIndex = pItem->storageIndex;
        self->m_kActiveSimulationIslands.m_iElementCount--;
    }
    ClearSlotReference((int*)self, (int*)pItem);
}
}  // namespace fnv_00cb4000

namespace fnv_00cb5420 {
struct S_00cb5420_Heap;
struct S_00cb5420_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S_00cb5420_Heap* m_pStreamAllocator;
    S_00cb5420_Heap& heap()
    {
        return *m_pStreamAllocator;
    }
};

S_00cb5420_Router& __cdecl hkMemoryRouter_getInstance();
void __cdecl ResizeAudioStream(S_00cb5420_Heap& alloc, void* array, int elemSize);



// Clears bits 0x0C in the item's flags; if the item's index is 0xFFFF, assigns it the container's item count and appends the item to the container's array.
template<class T> __forceinline void appendDirtyIsland(hkArrayBase<T>& a,const T& t) {
 S_00cb5420_Heap& alloc=hkMemoryRouter_getInstance().heap();
 if(a.m_iElementCount==(a.m_iCapacityState&0x3fffffff)) ResizeAudioStream(alloc,&a,sizeof(T));
 T* p=a.m_data+a.m_iElementCount;for(int i=0;i<1;++i)p[i]=t;a.m_iElementCount++;
}
// @fnv 0x00cb5420
void AddItemToContainer(hkpWorld* pContainer, hkpSimulationIsland* item)
{
    item->flags26 &= ~0x0C;
    if (item->dirtyIndex == 0xFFFF)
    {
        item->dirtyIndex = (unsigned short)pContainer->m_kDirtySimulationIslands.m_iElementCount;
        appendDirtyIsland(reinterpret_cast<hkArrayBase<hkpSimulationIsland*>&>(pContainer->m_kDirtySimulationIslands),item);
    }
}
}  // namespace fnv_00cb5420

struct ObjB;
// The shared world header does not yet declare FUN_00c91160(void*).
struct ObjA
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int m_94;
    void hkpWorld_queueOperation(void* p);
};
struct ObjB
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int m_cc;
};

struct FUN_00cb5570_arg
{
    unsigned char tag;
    ObjB* owner;
    ObjB* other;
};

void __cdecl hkpWorldOperationUtil_internalMergeTwoIslands(ObjA* a1, int a2, int a3);

// @fnv 0x00cb5570
// src: HAVOK_LIB 0x00cb5570
void __cdecl hkpWorldOperationUtil_mergeIslands(ObjA* apObjA, ObjB* apOwner, ObjB* apOther)
{
    int iOwnerValue = apOwner->m_cc;
    int iOtherValue = apOther->m_cc;
    if (apObjA->m_94 != 0)
    {
        FUN_00cb5570_arg arg;
        arg.tag = 0xc;
        arg.owner = apOwner;
        arg.other = apOther;
        apObjA->hkpWorld_queueOperation(&arg);
        return;
    }
    hkpWorldOperationUtil_internalMergeTwoIslands(apObjA, iOwnerValue, iOtherValue);
}

namespace fnv_00cb59f0 {
struct S_00cb59f0_Elem
{
    int unk00;
    int unk04;
};

struct S_00cb59f0_Xf
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};


struct S_00cb59f0_Router
{
    char* stackCur;
    int unk04;
    int unk08;
    int unk0c;
    hkMemoryAllocator* heap;
};

S_00cb59f0_Router* hkMemoryRouter_getInstance() throw();

struct S_00cb59f0_Local
{
    S_00cb59f0_Elem* m_data;
    int m_iElementCount;
    int m_cap;
    S_00cb59f0_Elem* m_localMem;
    __forceinline S_00cb59f0_Local(int n) throw()
    {
        m_data = 0;
        m_iElementCount = 0;
        m_cap = 0x80000000;
        S_00cb59f0_Router* r = hkMemoryRouter_getInstance();
        char* p = r->stackCur;
        r->stackCur = p + ((n * 8 + 0x7f) & 0xffffff80);
        m_data = (S_00cb59f0_Elem*)p;
        m_localMem = m_data;
        m_cap = n | 0x80000000;
    }
    __forceinline ~S_00cb59f0_Local() throw()
    {
        S_00cb59f0_Elem* lm = m_localMem;
        if (lm == m_data)
            m_iElementCount = 0;
        hkMemoryRouter_getInstance()->stackCur = (char*)lm;
        hkMemoryAllocator& h = *hkMemoryRouter_getInstance()->heap;
        int cap = m_cap;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
            h.bufFree(m_data, (cap & 0x3fffffff) * 8);
    }
};

struct S_00cb59f0_Obj58
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14(int* a, S_00cb59f0_Xf* b, S_00cb59f0_Local* c) throw();
};

struct S_00cb59f0_Obj64
{
    void hkpTypedBroadPhaseDispatcher_addPairs(S_00cb59f0_Elem* data, int n, char* extra) throw();
};

struct S_00cb59f0_Ctx
{
    int unk00;
};

struct S_00cb59f0_Sub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};

struct S_00cb59f0_B
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00cb59f0_Sub sub;
    int unk28;
    int unk2c;
    S_00cb59f0_Xf unk30;
};

void __cdecl hkpEntityAabbUtil_entityBatchRecalcAabb(S_00cb59f0_Ctx* ctx, S_00cb59f0_B** items, int n) throw();

// @fnv 0x00cb59f0
// src: HAVOK_LIB 0x00cb59f0
void __cdecl hkpWorldOperationUtil_addEntityBP(hkpWorld* a, S_00cb59f0_B* b) throw()
{
    S_00cb59f0_Sub* sub = &b->sub;
    if (sub->unk00 != 0)
    {
        S_00cb59f0_Local arr(a->m_iBroadPhaseQuerySize);
        hkpEntityAabbUtil_entityBatchRecalcAabb(static_cast<S_00cb59f0_Ctx*>(a->m_pCollisionInput), &b, 1);
        __declspec(align(16)) S_00cb59f0_Xf localXf = b->unk30;
        static_cast<S_00cb59f0_Obj58*>(a->m_pJobSemaphore)->vfn_14(&sub->unk14, &localXf, &arr);
        if (arr.m_iElementCount > 0)
            static_cast<S_00cb59f0_Obj64*>(a->m_pBroadPhaseDispatcher)->hkpTypedBroadPhaseDispatcher_addPairs(arr.m_data, arr.m_iElementCount, static_cast<char*>(a->m_pCollisionFilter) ? static_cast<char*>(a->m_pCollisionFilter) + 8 : 0);
    }
}
}  // namespace fnv_00cb59f0

namespace fnv_00cb5b10 {
// QueryEntityIntoBuffer candidate


struct __declspec(align(16)) OutSlot
{
    void* m_ptr;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
};


struct LocalArr
{
    void* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapBits;
};

struct BroadRec
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void Query(void* aabbA, void* aabbB, LocalArr* out);
};

struct DispatchRec
{
    void hkpTypedBroadPhaseDispatcher_addPairs(void* pairs, int count, void* filter);
};

struct FilterRec
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
};

struct EntityRec
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18(OutSlot* out);
    void hkpPhantom_setBoundingVolumeData(OutSlot* out);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int m_24;
    unsigned int m_28;
    unsigned int m_2c;
    unsigned int m_30;
};

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

struct ArrFrame
{
    LocalArr arr;
    unsigned char* saved;
};

struct OutPad
{
    OutSlot out;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
};

// @fnv 0x00cb5b10
void QueryEntityIntoBuffer(hkpWorld* world, EntityRec* apEntity)
{
    unsigned int cap = world->m_iBroadPhaseQuerySize;
    ArrFrame fr;
    fr.arr.m_pData = 0;
    fr.arr.m_iArrayLength = 0;
    fr.arr.m_uCapBits = 0x80000000u;
    hkMemoryRouter* holder = hkMemoryRouter_getInstance();
    unsigned char* old = reinterpret_cast<unsigned char*&>(holder->m_stack.m_next.m_storage);
    reinterpret_cast<unsigned char*&>(holder->m_stack.m_next.m_storage) = old + ((cap * 8 + 0x7f) & 0xffffff80u);
    fr.arr.m_pData = old;
    fr.arr.m_uCapBits = cap | 0x80000000u;
    fr.saved = old;

    OutPad outp;
    OutSlot* outPtr = &outp.out;
    apEntity->v18(outPtr);
    static_cast<BroadRec*>(world->m_pJobSemaphore)->Query(&apEntity->m_24, outPtr, &fr.arr);
    apEntity->hkpPhantom_setBoundingVolumeData(outPtr);

    if (fr.arr.m_iArrayLength != 0)
    {
        FilterRec* f = static_cast<FilterRec*>(world->m_pCollisionFilter);
        void* filter = f != 0 ? (void*)((char*)f + 8) : 0;
        static_cast<DispatchRec*>(world->m_pBroadPhaseDispatcher)->hkpTypedBroadPhaseDispatcher_addPairs(fr.arr.m_pData, fr.arr.m_iArrayLength, filter);
    }
    unsigned char* saved = fr.saved;
    if (saved == fr.arr.m_pData)
    {
        fr.arr.m_iArrayLength = 0;
    }
    reinterpret_cast<unsigned char*&>(hkMemoryRouter_getInstance()->m_stack.m_next.m_storage) = saved;
    hkMemoryAllocator* alloc = reinterpret_cast<hkMemoryAllocator*>(hkMemoryRouter_getInstance()->m_heap);
    fr.arr.m_iArrayLength = 0;
    if ((fr.arr.m_uCapBits & 0x80000000u) == 0)
    {
        alloc->bufFree(fr.arr.m_pData, (fr.arr.m_uCapBits & 0x3fffffffu) * 8);
    }
}
}  // namespace fnv_00cb5b10

// Stand-in model for the objects the original touches.
// The polymorphic target: vtable slots 0x10 / 0x1c / 0x20 are used.
struct VObj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10(void* p, int n);
    virtual void v14();
    virtual void v18();
    virtual void v1c(void* a, void* b);
    virtual void v20(void* a, int b, void* c, int d);
};

// The object at [owner + 0x64] - its member at 0xcf70f0 pops its own arguments.
struct Coll
{
    void __thiscall add(void* p, int n);
};

// The four-word record that is handed to v1c by address.
struct Slot
{
    void* a;
    int b;
    int c;
    void* d;
};

// The thread local block the accessor at 0xc85750 returns.
struct TlsBlk
{
    void* f0;
    void* f1;
    void* f2;
    void* f3;
    VObj* f4;
};

// The second argument.
struct Evt
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
};

// The first argument.


// The thread local accessor at 0xc85750.
void* __cdecl tlsSlot_cb5c10();

// @fnv 0x00cb5c10
// src: HAVOK_LIB 0x00cb5c10
void __cdecl hkpWorldOperationUtil_removeEntityBP(hkpWorld* pOwner, Evt* pEvent)
{
    // q is the flag word at +0x10; the original keeps that pointer in a
    // register, so &pEvt->unk24 is reached as q + 5.
    int* q = &pEvent->unk10;
    if (*q == 0)
        return;

    Slot s;
    // The address of the record escapes here: that is what keeps the dead
    // store of zero below and the shared zero register alive.
    Slot* pSlot = &s;

    reinterpret_cast<VObj*>(pOwner->m_pSimulation)->v20(&pEvent, 1, pOwner, 1);

    unsigned int count = pOwner->m_iBroadPhaseQuerySize;

    s.a = 0;
    s.b = 0;
    s.c = 0x80000000;

    TlsBlk* t = (TlsBlk*)tlsSlot_cb5c10();
    void* base = t->f0;
    t->f0 = (char*)base + ((count * 8 + 0x7f) & 0xffffff80u);
    s.a = base;
    s.d = base;

    s.c = count | 0x80000000u;

    static_cast<VObj*>(pOwner->m_pJobSemaphore)->v1c(q + 5, pSlot);

    int n = s.b;
    if (n > 0)
        static_cast<Coll*>(pOwner->m_pBroadPhaseDispatcher)->add(s.a, n);

    void* d = s.d;
    if (d == s.a)
        s.b = 0;

    t = (TlsBlk*)tlsSlot_cb5c10();
    t->f0 = d;
    t = (TlsBlk*)tlsSlot_cb5c10();
    // The flag is read through a volatile lvalue so that the load keeps its
    // place in front of the receiver load, exactly as the original does.
    int c = *(volatile int*)&s.c;
    VObj* o = t->f4;
    s.b = 0;
    if (!(c & 0x80000000))
        o->v10(s.a, (c & 0x3fffffff) * 8);
}

namespace fnv_00cb5f50 {


struct S_00cb5f50_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocator* m_pStreamAllocator;
    hkMemoryAllocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

S_00cb5f50_Router* hkMemoryRouter_getInstance() throw();

template <typename T>
struct S_00cb5f50_Array
{ // local form of hkArrayBase: 0x00cb5f50 needs local helper inlining and base lifetime behavior; the shared form changes extent from 263 to 264 bytes.
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    ~S_00cb5f50_Array() throw()
    {
        _clearAndDeallocate(hkMemoryRouter_getInstance()->heap());
    }
    void _clearAndDeallocate(hkMemoryAllocator& alloc) throw()
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    void clear()
    {
        m_iElementCount = 0;
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    const T& operator[](int i) const
    {
        return m_data[i];
    }
};

template <typename T, int N> struct S_00cb5f50_InplaceArray : S_00cb5f50_Array<T>
{
    T m_kStorage[N];
    S_00cb5f50_InplaceArray() throw()
    {
        this->m_data = m_kStorage;
        this->m_iElementCount = 0;
        this->m_iCapacityState = N | 0x80000000;
    }
};

struct S_00cb5f50_Island;


// The shared island header does not yet declare AddItem(hkpAction*).
struct S_00cb5f50_Island
{
    void AddItem(hkpAction* c) throw();
};

void hkpWorldOperationUtil_mergeIslands(hkpWorld* world, hkpEntity* a, hkpEntity* b) throw();

// @fnv 0x00cb5f50
void __cdecl ApplyConstraintsToEntity(hkpWorld* world, hkpEntity* entity,
                                      const S_00cb5f50_Array<hkpAction*>* constraints) throw()
{
    S_00cb5f50_Island* island = reinterpret_cast<S_00cb5f50_Island*>(entity->m_pSimulationIsland);
    S_00cb5f50_InplaceArray<hkpEntity*, 16> entities;
    for (int i = 0; i < constraints->m_iElementCount; i++)
    {
        hkpAction* c = constraints->m_data[i];
        if (island != world->m_pFixedIsland)
        {
            island->AddItem(c);
            c->FUN_00c905b0();
            entities.clear();
            c->GetEntities(reinterpret_cast<hkArray<hkpEntity*>&>(entities));
            for (int j = 0; j < entities.m_iElementCount; j++)
            {
                hkpEntity* other = entities[j];
                if (other != entity && reinterpret_cast<const unsigned char&>(other->m_pMotionState.m_type) != 5 && reinterpret_cast<const unsigned char&>(entity->m_pMotionState.m_type) != 5 &&
                    other->m_pSimulationIsland != entity->m_pSimulationIsland)
                    hkpWorldOperationUtil_mergeIslands(reinterpret_cast<hkpWorld*>(other->m_pOwningWorld), other, entity);
            }
        }
        else
        {
            static_cast<S_00cb5f50_Island*>(world->m_pFixedIsland)->AddItem(c);
            c->FUN_00c905b0();
        }
    }
}
}  // namespace fnv_00cb5f50

struct FUN_00cb7480_node
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    unsigned short m_14;
    unsigned short m_16;
    unsigned short m_18;
};

struct FUN_00cb7480_holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    FUN_00cb7480_node* m_30;
};

struct FUN_00cb7480_delta
{
    int unk00;
    int m_04;
    int m_08;
    int m_0c;
};

struct FUN_00cb7480_cls
{
    int unk00;
    int unk04;
    int unk08;
    int m_0c;
    int m_10;
    int m_14;

    void hkpConstraintOwner_subConstraintInfo(FUN_00cb7480_holder* a1, FUN_00cb7480_delta* a2);
};

// Subtracts the delta's m_04, m_08 and m_0c from m_0c, m_10 and m_14, and from the node's m_14, m_16 and m_18, when a1->m_30 is non-null.
// @fnv 0x00cb7480
// src: HAVOK_LIB 0x00cb7480
void FUN_00cb7480_cls::hkpConstraintOwner_subConstraintInfo(FUN_00cb7480_holder* apHolder, FUN_00cb7480_delta* apDelta)
{
    if (apHolder->m_30 != 0)
    {
        m_0c -= apDelta->m_04;
        m_10 -= apDelta->m_08;
        m_14 -= apDelta->m_0c;
        FUN_00cb7480_node* n = apHolder->m_30;
        int dy = n->m_18 - apDelta->m_0c;
        int dx = n->m_14 - apDelta->m_04;
        n->m_16 -= (unsigned short)apDelta->m_08;
        n->m_14 = (unsigned short)dx;
        n->m_18 = (unsigned short)dy;
    }
}

class BSAudio;
namespace fnv_00d282c0 {


__declspec(nothrow) BSAudio* __cdecl hkMemoryRouter_getInstance();
inline hkMemoryRouter* audio()
{
    return (hkMemoryRouter*)hkMemoryRouter_getInstance();
}

__declspec(nothrow) void __cdecl hkArrayUtil__reserve(hkMemoryAllocator& alloc, void* arr, int numElem, int sizeElem);

template <class T> struct hkLocalArr
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline hkLocalArr(int n)
    {
        hkMemoryAllocator& alloc = audio()->stack();
        m_data = n ? alloc._bufAlloc<T>(n) : 0;
        m_iElementCount = 0;
        m_iCapacityState = n ? n : 0x80000000;
    }
    __forceinline ~hkLocalArr()
    {
        hkMemoryAllocator& alloc = audio()->stack();
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
    }
};

// hkArray<int>::setSize (hkArray.inl: _reserve then the size; ints need no construction), heap from the router.
static __forceinline void SetSizeAndGrow(hkArray<int>& a, int n)
{
    hkMemoryAllocator& alloc = audio()->heap();
    if (a.getCapacity() < n)
    {
        int cap = 2 * a.getCapacity();
        hkArrayUtil__reserve(alloc, &a, n < cap ? cap : n, sizeof(int));
    }
    a.m_iElementCount = n;
}

__forceinline int* localAlloc(hkMemoryAllocator& alloc, int n, int& m_iCapacity)
{
    int* p = n ? alloc._bufAlloc<int>(n) : 0;
    m_iCapacity = n ? n : 0x80000000;
    return p;
}

struct IndexRemap
{
    int** m_ppIndices;
    int m_iIndexCount;

    void RemapAndAccumulate(const hkArray<int>& map, int n, hkArray<int>& values);
};

// Remaps each entry of the index array through map, then sums values into n buckets by mapped index and writes the sums back into values.
// @fnv 0x00d282c0
void IndexRemap::RemapAndAccumulate(const hkArray<int>& map, int n, hkArray<int>& values)
{
    for (int i = 0; i < m_iIndexCount; i++)
        (*m_ppIndices)[i] = map.m_data[(*m_ppIndices)[i]];

    hkMemoryAllocator& stackAlloc = audio()->temp();
    int m_iCapacity;
    int* sums = localAlloc(stackAlloc, n, m_iCapacity);
    for (int i = 0; i < n; i++)
        sums[i] = 0;
    for (int i = 0; i < values.m_iElementCount; i++)
        sums[map.m_data[i]] += values.m_data[i];

    SetSizeAndGrow(values, n);
    for (int i = 0; i < n; i++)
        values.m_data[i] = sums[i];

    hkMemoryAllocator& alloc = audio()->temp();
    if ((m_iCapacity & 0x80000000) == 0)
        alloc.bufFree(sums, (m_iCapacity & 0x3fffffff) * sizeof(int));
}
}  // namespace fnv_00d282c0

inline void* operator new(unsigned int, void* p)
{
    return p;
}

struct S00cb5310_List
{
    hkpSimulationIsland** m_00;
    int m_04;
    unsigned int m_08;
};

extern int DAT_01267e30;
void ResizeAudioStream(void* alloc, S00cb5310_List* list, int n);
bool Object_ProcessEntries_00d28560(float* p, hkpEntity** arr, int n, int size);
void UpdateRotationInterpolation(float f, void* p);
void hkpWorldCallbackUtil_fireIslandDeactivated(hkpWorld* a1, hkpSimulationIsland* a2);
// If FUN_00d28560 passes, moves node a2 from the owner's m_28 array to its m_34 list, updates its pieces and calls FUN_00d011b0; else sets a flag bit and returns.
// @fnv 0x00cb5310
// src: HAVOK_LIB 0x00cb5310
void __cdecl hkpWorldOperationUtil_internalDeactivateIsland(hkpWorld* apOwner, hkpSimulationIsland* apNode)
{
    hkpEntity** pForm;
    pForm = apNode->entities.data;
    long holder;
    holder = apNode->entities.count;
    float* pf = &reinterpret_cast<float&>(apOwner->pad1C8[8]);
    if (Object_ProcessEntries_00d28560(pf, pForm, holder, 0xe0) == 0)
    {
        apNode->flags26 = (unsigned char)((apNode->flags26 & 0xf7) | 4);
        return;
    }
    S00cb5310_List* list;
    list = reinterpret_cast<S00cb5310_List*>(&apOwner->m_kInactiveSimulationIslands);
    hkMemoryRouter* p = reinterpret_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance());
    if (list->m_04 == (int)(list->m_08 & 0x3fffffffu))
    {
        ResizeAudioStream(p->m_heap, list, 4);
    }
    hkpSimulationIsland** slot;
    slot = list->m_00 + list->m_04;
    __assume((bool)slot);
    new (slot) hkpSimulationIsland*(apNode);
    list->m_04 += 1;
    reinterpret_cast<hkpSimulationIsland**>(apOwner->m_kActiveSimulationIslands.m_data)[apNode->storageIndex] = reinterpret_cast<hkpSimulationIsland**>(apOwner->m_kActiveSimulationIslands.m_data)[apOwner->m_kActiveSimulationIslands.m_iElementCount - 1];
    reinterpret_cast<hkpSimulationIsland**>(apOwner->m_kActiveSimulationIslands.m_data)[apNode->storageIndex]->storageIndex = apNode->storageIndex;
    S00cb5310_List* _lst = reinterpret_cast<S00cb5310_List*>(&apOwner->m_kInactiveSimulationIslands);
    apOwner->m_kActiveSimulationIslands.m_iElementCount--;
    apNode->storageIndex = (unsigned short)(_lst->m_04 - 1);
    apNode->flags26 &= 0xfc;
    int i;
    reinterpret_cast<float&>(apNode->unk44) = *pf;
    i = 0;
    if (apNode->entities.count > i)
    {
        do
        {
            hkpEntity* pPiece = apNode->entities.data[i];
            UpdateRotationInterpolation(reinterpret_cast<float&>(apNode->unk44), &pPiece->m_pMotionState.m_kMotionState);
            pPiece->m_pMotionState.SetTranslationalVelocity(reinterpret_cast<const hkVector4&>(DAT_01267e30));
            pPiece->m_pMotionState.SetRotationalVelocity(reinterpret_cast<const hkVector4&>(DAT_01267e30));
            ++i;
        } while (i < apNode->entities.count);
    }
    hkpWorldCallbackUtil_fireIslandDeactivated(apOwner, apNode);
}

namespace fnv_00cb5500 {
inline void* __cdecl operator new(unsigned int, void* place)
{
    return place;
}
struct Entry
{
    unsigned int unk00, unk04, unk08, unk0c;
    unsigned int unk10, unk14, unk18, unk1c;
    unsigned short unk20;
    unsigned short index;
    unsigned short unk24;
    unsigned char flags;
};
struct EntryArray
{
    Entry** entries;
    unsigned int count;
    unsigned int capacity;
};
struct AllocatorContext
{
    unsigned int unk00, unk04, unk08, unk0c;
    unsigned int allocator;
};
extern AllocatorContext* __cdecl hkMemoryRouter_getInstance();
extern void __cdecl ResizeAudioStream(unsigned int allocator, EntryArray* list, int entrySize);

// Sets entry flags, and if entry->index is 0xffff, appends entry to the EntryArray at owner+0x40, resizing it via ResizeAudioStream when full.
// @fnv 0x00cb5500
void __cdecl AddEntryToList(void* owner, Entry* entry)
{
    unsigned char bits = entry->flags;
    if ((bits & 0x0c) == 0 && (bits & 3) != 0)
    {
        entry->flags = (bits & ~0x20) | 0x10;
    }
    entry->flags = (entry->flags & ~0x08) | 0x04;
    if (entry->index == 0xffff)
    {
        entry->index = (unsigned short)*(unsigned int*)((unsigned char*)owner + 0x44);
        EntryArray* list = (EntryArray*)((unsigned char*)owner + 0x40);
        AllocatorContext* allocator = hkMemoryRouter_getInstance();
        if (list->count == (list->capacity & 0x3fffffff))
        {
            ResizeAudioStream(allocator->allocator, list, 4);
        }
        Entry** slot = list->entries + list->count;
        __assume(slot != 0);
        new (slot) Entry*(entry);
        ++list->count;
    }
}
}  // namespace fnv_00cb5500

struct Cb5750_Deferred
{
    unsigned char tag;
    struct Cb5750_Param* arg;
};

struct Cb5750_Bv
{
    unsigned int m_kMinimumCorner[3];
    unsigned char m_ucExpansionMin[3];
    unsigned char m_ucExpansionShift;
    unsigned int m_kMaximumCorner[3];
    unsigned char m_ucExpansionMax[3];
    unsigned char m_auiShapeKeys;
};

struct Cb5750_Nav
{
    int unk00;
    int unk04;
    int unk08;
    Cb5750_Bv m_bv;
};

struct Cb5750_Inner
{
    void* m_pCollisionShape;
    int m_uiCollisionShapeKey;
    void* m_pMotionState;
    void* m_parent;
    int m_bpId;
    Cb5750_Nav m_nav;
};

struct Cb5750_Param
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Cb5750_Inner inner;
};

struct Cb5750_Aabb
{
    unsigned int m_kMinimumCorner[4];
    unsigned int m_kMaximumCorner[4];
};

struct Cb5750_Sub8
{
    int unk00;
    int unk04;
    int unk08;
};

S_00c6aca0_Router* Cb5750_router() throw();

struct Cb5750_Stack
{
    char* m_next;
    int unk04;
    int unk08;
    int unk0C;
    __forceinline void* allocateStack(int nbytes) throw()
    {
        char* p = m_next;
        m_next = p + ((nbytes + 127) & ~127);
        return p;
    }
    __forceinline void deallocateStack(void* p) throw()
    {
        m_next = (char*)p;
    }
};

template <class T>
static __forceinline void Cb5750_Array_destroy(hkArrayBase<T>& self) throw();

template <class T>
static __forceinline void Cb5750_Array_destroy(hkArrayBase<T>& self) throw()
{
        S_00c6aca0_Router* router = Cb5750_router();
        hkMemoryAllocator& heap = *router->m10;
        int cap = self.m_iCapacityState;
        self.m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
            heap.bufFree(self.m_data, (cap & 0x3fffffff) * (int)sizeof(T));
        self.m_data = 0;
        self.m_iCapacityState = 0x80000000;
    }

struct Cb5750_ArrayPolicy
{
    template <class T>
    static __forceinline void destroy(hkArrayBase<T>& self) { Cb5750_Array_destroy(self); }
};

template <class T> struct Cb5750_LocalArray : hkArray<T, Cb5750_ArrayPolicy>
{
    T* m_pStackAllocation;
    __forceinline Cb5750_LocalArray(int capacity) throw()
    {
        this->m_data = (T*)((Cb5750_Stack*)Cb5750_router())->allocateStack(capacity * sizeof(T));
        this->m_iCapacityState = capacity | 0x80000000;
        m_pStackAllocation = this->m_data;
    }
    __forceinline ~Cb5750_LocalArray() throw()
    {
        T* mem = m_pStackAllocation;
        if (mem == this->m_data)
            this->m_iElementCount = 0;
        ((Cb5750_Stack*)Cb5750_router())->deallocateStack(mem);
    }
};

struct Cb5750_Source
{
    virtual void v00() throw();
    virtual void v04() throw();
    virtual void v08() throw();
    virtual void v0c() throw();
    virtual void v10() throw();
    virtual void v14() throw();
    virtual void v18() throw();
    virtual void v1c() throw();
    virtual void v20() throw();
    virtual void v24() throw();
    virtual void v28() throw();
    virtual void v2c(Cb5750_Nav** key, Cb5750_Aabb* aabb, int count, hkArray<S_00cb5d00_Elem, Cb5750_ArrayPolicy>* a,
                     hkArray<S_00cb5d00_Elem, Cb5750_ArrayPolicy>* b) throw();
};

struct Cb5750_Sink
{
    void addSecond(S_00cb5d00_Elem* data, int n) throw();
    void addFirst(S_00cb5d00_Elem* data, int n, void* extra) throw();
};

S_00c6aca0_Router* Cb5750_router() throw();
void __cdecl Cb5750_merge(hkArray<S_00cb5d00_Elem, Cb5750_ArrayPolicy>* a, hkArray<S_00cb5d00_Elem, Cb5750_ArrayPolicy>* b) throw();
void __cdecl Cb5750_invalid(void* world, Cb5750_Param** pp, int count) throw();

// The shared world header lacks AddCollisionShape and the deferred-operation method used here.
struct Cb5750_Owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    Cb5750_Source* unk58;
    int unk5C;
    int unk60;
    Cb5750_Sink* unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    void* unk78;
    Cb5750_Sub8* unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    unsigned char flag9c;
    unsigned char unk9d;
    unsigned char unk9e;
    unsigned char unk9f;
    int unkA0;
    int unkA4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;

    void defer(Cb5750_Deferred* d) throw();
    void flush8c() throw();
    void flush90() throw();
    void __cdecl AddCollisionShape(Cb5750_Param* param) throw();
};

// If unk94 is set, defers the call; otherwise expands the shape's bounding volume into an AABB, queries unk58 with it, and passes results to unk64.
// @fnv 0x00cb5750
void __cdecl Cb5750_Owner::AddCollisionShape(Cb5750_Param* param) throw()
{
    if (unk94 != 0)
    {
        Cb5750_Deferred deferred;
        deferred.tag = 3;
        deferred.arg = param;
        defer(&deferred);
        return;
    }

    Cb5750_Param* held = param;
    void* shape = held->inner.m_pCollisionShape;
    unk94 = 1;
    if (shape != 0)
    {
        Cb5750_Inner* inner = &held->inner;
        Cb5750_LocalArray<S_00cb5d00_Elem> arr1(unk338);
        Cb5750_LocalArray<S_00cb5d00_Elem> arr2(unk338);
        if (inner->m_nav.m_bv.m_kMinimumCorner[0] > inner->m_nav.m_bv.m_kMaximumCorner[0])
            Cb5750_invalid(unk78, &param, 1);

        __declspec(align(16)) Cb5750_Aabb aabb;
        unsigned int uiExpansionShift = inner->m_nav.m_bv.m_ucExpansionShift;
        aabb.m_kMinimumCorner[0] =
            inner->m_nav.m_bv.m_kMinimumCorner[0] - (inner->m_nav.m_bv.m_ucExpansionMin[0] << uiExpansionShift);
        aabb.m_kMinimumCorner[1] =
            inner->m_nav.m_bv.m_kMinimumCorner[1] - (inner->m_nav.m_bv.m_ucExpansionMin[1] << uiExpansionShift);
        aabb.m_kMinimumCorner[2] =
            inner->m_nav.m_bv.m_kMinimumCorner[2] - (inner->m_nav.m_bv.m_ucExpansionMin[2] << uiExpansionShift);
        aabb.m_kMaximumCorner[0] =
            inner->m_nav.m_bv.m_kMaximumCorner[0] + (inner->m_nav.m_bv.m_ucExpansionMax[0] << uiExpansionShift);
        aabb.m_kMaximumCorner[1] =
            inner->m_nav.m_bv.m_kMaximumCorner[1] + (inner->m_nav.m_bv.m_ucExpansionMax[1] << uiExpansionShift);
        aabb.m_kMaximumCorner[2] =
            inner->m_nav.m_bv.m_kMaximumCorner[2] + (inner->m_nav.m_bv.m_ucExpansionMax[2] << uiExpansionShift);
        Cb5750_Nav* key = &inner->m_nav;

        unk58->v2c(&key, &aabb, 1, &arr1, &arr2);
        if (arr1.m_iElementCount + arr2.m_iElementCount > 0)
        {
            Cb5750_merge(&arr1, &arr2);
            unk64->addSecond(arr2.m_data, arr2.m_iElementCount);
            Cb5750_Sub8* sub = unk7C;
            void* extra = sub ? &sub->unk08 : 0;
            unk64->addFirst(arr1.m_data, arr1.m_iElementCount, extra);
        }
    }

    if (--unk94 == 0 && flag9c == 0)
    {
        if (unk8C != 0)
            flush8c();
        if (unkA4 == 1 && unk90 != 0)
            flush90();
    }
}

namespace fnv_00cb5dd0 {
inline void* __cdecl operator new(unsigned int, void* place)
{
    return place;
}
struct Heap
{
    virtual void unk0();
    virtual void unk4();
    virtual void unk8();
    virtual void unkC();
    virtual void freeMemory(void* pointer, unsigned int bytes);
};
struct MemoryContext
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Heap* heap;
};
extern "C" MemoryContext* __cdecl hkMemoryRouter_getInstance();
extern "C" void __cdecl ResizeAudioStream(void* heap, void* array, int elementSize);

template <class T> struct Array
{
    T** data;
    int length;
    unsigned int capacity;
    void add(T* p)
    {
        MemoryContext* memory = hkMemoryRouter_getInstance();
        if (length == (int)(capacity & 0x3fffffff))
            fnv_00cb5dd0::ResizeAudioStream(memory->heap, this, 4);
        T** address = data + length;
        __assume(address != 0);
        new (address) T*(p);
        ++length;
    }
};
struct Scratch : Array<hkpEntity>
{
    hkpEntity* inline0;
    hkpEntity* inline1;
    hkpEntity* inline2;
    hkpEntity* inline3;
    hkpEntity* inline4;
    hkpEntity* inline5;
    hkpEntity* inline6;
    hkpEntity* inline7;
    hkpEntity* inline8;
    hkpEntity* inline9;
    hkpEntity* inline10;
    hkpEntity* inline11;
    hkpEntity* inline12;
    hkpEntity* inline13;
    hkpEntity* inline14;
    hkpEntity* inline15;
    Scratch()
    {
        data = &inline0;
        length = 0;
        capacity = 0x80000010;
    }
};

struct Manager
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    hkpSimulationIsland* currentCC;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    hkpAction** producers208;
    unsigned short producerCount20c;
};

// Enumerates each producer's actors, adds qualifying producers to output, removes them from currentCC, and frees the scratch buffer.
// @fnv 0x00cb5dd0
void __cdecl CollectProducers(hkpWorld* context, Manager* manager, Array<hkpAction>* output)
{
    Scratch scratch;
    int index = 0;
    hkpSimulationIsland* handle = manager->currentCC;
    for (; index < manager->producerCount20c; ++index)
    {
        hkpAction* object = manager->producers208[index];
        object->GetEntities(reinterpret_cast<hkArray<hkpEntity*>&>(scratch));
        int j = 0;
        if (scratch.length > 0)
        {
            do
            {
                hkpEntity* other = scratch.data[j];
                if (reinterpret_cast<const unsigned char&>(other->m_pMotionState.m_type) != 5 && other != reinterpret_cast<hkpEntity*>(manager))
                    goto next_object;
                ++j;
            } while (j < scratch.length);
        }
        output->add(object);
        object->FUN_00c90510();
        handle->RemoveEntry(object);
        handle->flags25 = (handle->flags25 & 0xdf) | 0x10;
        if (handle->dirtyIndex == 0xffff)
        {
            handle->dirtyIndex = (unsigned short)context->m_kDirtySimulationIslands.m_iElementCount;
            reinterpret_cast<Array<hkpSimulationIsland>&>(context->m_kDirtySimulationIslands).add(handle);
        }
    next_object:;
    }
    MemoryContext* memory = hkMemoryRouter_getInstance();
    Heap* heap = memory->heap;
    unsigned int cap = scratch.capacity;
    scratch.length = 0;
    if ((cap & 0x80000000u) == 0)
        heap->freeMemory(scratch.data, (cap & 0x3fffffff) * 4);
}
}  // namespace fnv_00cb5dd0

struct List_cb3d10
{
    hkpSimulationIsland** m_data;
    int m_iElementCount;
};
// Scans the last 20 islands for a non-target island below the desired size and marks the match.
// @fnv 0x00cb3d10
static __declspec(noinline) hkpSimulationIsland* FindItemForThreshold(hkpWorld* owner, List_cb3d10* list, int threshold,
                                                              hkpSimulationIsland* target)
{
    int limit = reinterpret_cast<const int&>(owner->m_uiMinDesiredIslandSize);
    if (threshold >= limit)
        return 0;
    if (!owner->m_bWantSimulationIslands.m_cBooleanValue)
        return 0;
    int i = list->m_iElementCount;
    int lo = (i - 20 < 0) ? 0 : i - 20;
    for (--i; i >= lo; --i)
    {
        hkpSimulationIsland* item = list->m_data[i];
        if (target != item)
        {
            int v = item->entities.count;
            if (v <= item->unk1C)
                v = item->unk1C;
            if (item->flags26 & 0xc)
            {
                if (v + threshold < limit)
                {
                    item->flags25 = (item->flags25 & 0xf7) | 4;
                    return item;
                }
            }
        }
    }
    return 0;
}
volatile int g_cb3d10_thr;
hkpWorld* volatile g_cb3d10_owner;
List_cb3d10* volatile g_cb3d10_list;
hkpSimulationIsland* volatile g_cb3d10_target;
hkpSimulationIsland* volatile g_cb3d10_out;
void CallTarget_cb3d10()
{
    g_cb3d10_out = FindItemForThreshold(g_cb3d10_owner, g_cb3d10_list, g_cb3d10_thr, g_cb3d10_target);
}

struct B10293_Item
{
    unsigned short Field(int off) const
    {
        return *(const unsigned short*)((const char*)this + off);
    }
};
struct B10293_List
{
    B10293_Item** m_data;
    int m_uiItemCount;
};

struct B10293_Arr
{
    int* m_aiIndexedValues;
};
struct B10293_Chain
{
    B10293_Arr* m_aiIndexedValues;
};
static inline int Dec(int w, unsigned char s)
{
    if (s == (w >> 14))
        return (w >> 7) & 0x7f;
    return w & 0x7f;
}
// Zeroes out the output array, then for each list item computes a threshold from two packed fields and sets the indexed slot to 1 when the threshold is 5 or less.
// @fnv 0x00cb4080
static void MarkIndexedValues(int count, B10293_List* list, int** out, B10293_Chain* chain, hkpWorld* ctx)
{
    int i;
    for (i = 0; i < count; i++)
        (*out)[i] = 0;
    int j;
    for (j = 0; j < list->m_uiItemCount; j++)
    {
        B10293_Item* item = list->m_data[j];
        int a = Dec(item->Field(0xec), reinterpret_cast<unsigned char&>(ctx->pad1C8[0x13e]));
        int c = Dec(item->Field(0xea), reinterpret_cast<unsigned char&>(ctx->pad1C8[0x13d]));
        a &= 0x7f;
        c &= 0x7f;
        if (c > a)
            a = c;
        if (a <= 5)
            (*out)[chain->m_aiIndexedValues->m_aiIndexedValues[j]] = 1;
    }
}
int keep_alive_b10293(int count, B10293_List* list, int** out, B10293_Chain* chain, hkpWorld* ctx)
{
    MarkIndexedValues(count, list, out, chain, ctx);
    return count;
}

struct Shape
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    unsigned short m_numShapeKeys;  // +0xb0
};

struct ShapeList
{
    Shape** m_items;
    int m_uiItemCount;
};

// For each shape in list, set flags[idx] to 1 and add its m_numShapeKeys (minimum 1) to counts[idx].
// @fnv 0x00cb41e0
// src: HAVOK_LIB 0x00cb41e0
static void estimateSolverSize(int*** indexMap, int** counts, ShapeList* list, int** flags)
{
    int**** pp = &indexMap;
    for (int i = 0; i < list->m_uiItemCount; i++)
    {
        Shape* s = list->m_items[i];
        int idx = (***pp)[i];
        (*flags)[idx] = 1;
        int n = s->m_numShapeKeys;
        (*counts)[idx] += n < 1 ? 1 : n;
    }
}
int keep_alive_b11420(ShapeList* list, int** flags, int*** indexMap, int** counts)
{
    estimateSolverSize(indexMap, counts, list, flags);
    return 0;
}

namespace fnv_00cb4790 {
inline void* __cdecl operator new(unsigned int, void* place)
{
    return place;
}

struct Cell
{
    void* value;
    Cell()
    {}
};
struct Array
{
    Cell* data;
    int size;
    unsigned capacity;
};
struct Heap
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* allocator;
};
Heap* __cdecl hkMemoryRouter_getInstance();
void __cdecl ResizeAudioStream(void*, Array*, int);


// Collects actions from the fixed island and appends the island to the dirty list when needed.
// @fnv 0x00cb4790
void __cdecl CollecthkpSimulationIslandEntries(int* parent, int* elements, Array* output)
{
    for (int i = 0; i < *(unsigned short*)&elements[0x83]; i++)
    {
        hkpAction* item = ((hkpAction**)elements[0x82])[i];
        if (item->m_pCurrentSimulationIsland == (hkpSimulationIsland*)parent[8])
        {
            Heap* heap = hkMemoryRouter_getInstance();
            if (output->size == (int)(output->capacity & 0x3fffffff))
                ResizeAudioStream(heap->allocator, output, 4);
            Cell* dst = &output->data[output->size];
            new (dst) Cell();
            dst->value = item;
            output->size++;
            item->FUN_00c90510();
            ((hkpSimulationIsland*)parent[8])->RemoveEntry(item);
            ((hkpSimulationIsland*)parent[8])->flags25 = (((hkpSimulationIsland*)parent[8])->flags25 & 0xdf) | 0x10;
            hkpSimulationIsland* actor = (hkpSimulationIsland*)parent[8];
            if (actor->dirtyIndex == 0xffff)
            {
                actor->dirtyIndex = (unsigned short)((Array*)&parent[16])->size;
                Array* other = (Array*)&parent[16];
                Heap* heap2 = hkMemoryRouter_getInstance();
                if (other->size == (int)(other->capacity & 0x3fffffff))
                    ResizeAudioStream(heap2->allocator, other, 4);
                Cell* dst2 = &other->data[other->size];
                new (dst2) Cell();
                dst2->value = actor;
                other->size++;
            }
        }
    }
}
}  // namespace fnv_00cb4790

template <class T> inline void S00cb4c60_copy(T* p, int n, const T& v)
{
    for (int i = 0; i < n; ++i)
        p[i] = v;
}

void __cdecl hkArrayUtil__reserve(void*, void*, int, int);
void __cdecl ResizeAudioStream(void*, void*, int);
template <class T> inline int hkArrayNative<T>::getCapacity() const
{
    return capRaw & 0x3fffffff;
}
template <class T> inline void hkArrayNative<T>::reserve(int n)
{
    hkMemoryAllocator& a = hkMemoryRouter_getInstance()->heap();
    const int cap = getCapacity();
    if (cap < n)
    {
        int cap2 = 2 * cap;
        int newSize = (n < cap2) ? cap2 : n;
        hkArrayUtil__reserve(&a, this, newSize, sizeof(T));
    }
}
template <class T> inline void hkArrayNative<T>::AddBack(const T& t)
{
    S_00c6aca0_Router* r = hkMemoryRouter_getInstance();
    if (count == getCapacity())
        ResizeAudioStream(&r->heap(), this, sizeof(T));
    S00cb4c60_copy(data + count, 1, t);
    count++;
}
template <class T> inline void hkArrayNative<T>::SetSize(int size)
{
    reserve(size);
    count = size;
}

struct ConstraintRuntimeInfo
{
    hkpConstraintInstance* constraint;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
};

void __cdecl hkpWorldOperationUtil_internalActivateIsland(hkpWorld*, hkpSimulationIsland*, hkBool = false);
void __cdecl _hkAgentNnMachine_AppendTrack(void*, void*);
void __cdecl hkArrayUtil__reserve(void*, void*, int, int);
void __cdecl ResizeAudioStream(void*, void*, int);
void __cdecl ClearSlotReference(hkpWorld*, hkpSimulationIsland*);
static inline int GrowCap(int cap, int need)
{
    int nc = cap * 2;
    if (need >= nc)
        nc = need;
    return nc;
}
// Merges island Q into P, reassigns entity and action owners, updates world lists, and deletes Q.
// @fnv 0x00cb4c60
// src: HAVOK_LIB 0x00cb4c60
void __cdecl hkpWorldOperationUtil_internalMergeTwoIslands(hkpWorld* apWorld, hkpSimulationIsland* apTarget, hkpSimulationIsland* apSource)
{
    hkpWorld* o = apWorld;
    if (apTarget->entities.count > apSource->entities.count)
    {
    }
    else if (apTarget->entities.count < apSource->entities.count || apTarget->storageIndex > apSource->storageIndex)
    {
        hkpSimulationIsland* t = apTarget;
        apTarget = apSource;
        apSource = t;
    }
    o->m_iCriticalOperationsLockCount++;
    unsigned char pf = apTarget->flags26;
    unsigned char cl = pf & 3;
    unsigned char dl;
    if (cl == 0 && (apSource->flags26 & 3) == 0)
        dl = 0;
    else
        dl = 1;
    unsigned char f18;
    if ((pf & 0xc) != 0 || (apSource->flags26 & 0xc) != 0)
        f18 = 1;
    else
        f18 = 0;
    if (dl)
    {
        if (cl == 0)
        {
            apTarget->flags26 = (pf & 0xf7) | 4;
            hkpWorldOperationUtil_internalActivateIsland(apWorld, apTarget);
        }
        else if ((apSource->flags26 & 3) == 0)
        {
            apSource->flags26 = (apSource->flags26 & 0xf7) | 4;
            hkpWorldOperationUtil_internalActivateIsland(apWorld, apSource);
        }
    }
    apTarget->flags25 |= (apSource->flags25 & 0xc);
    apTarget->nullsub_10();
    apSource->nullsub_10();
    static_cast<hkpSimulationIsland*>(o->m_pFixedIsland)->nullsub_10();
    _hkAgentNnMachine_AppendTrack(&apTarget->unk58, &apSource->unk58);
    int iTargetCount = apTarget->entities.count;
    unsigned short idx = (unsigned short)iTargetCount;
    int total = iTargetCount + apSource->entities.count;
    hkArrayNative<hkpEntity*>* v48 = &apTarget->entities;
    v48->SetSize(total);
    hkArrayNative<hkpEntity*>* pSourceEntities = &apSource->entities;
    for (int i = 0; i < pSourceEntities->count; ++i, ++idx)
    {
        v48->data[idx] = pSourceEntities->data[i];
        pSourceEntities->data[i]->m_pSimulationIsland = apTarget;
        pSourceEntities->data[i]->m_usStorageIndex = (unsigned short)idx;
    }
    int k = apTarget->actions.count;
    int iTotalActions = k + apSource->actions.count;
    hkArrayNative<hkpAction*>* v38 = &apTarget->actions;
    v38->SetSize(iTotalActions);
    hkArrayNative<hkpAction*>* pSourceActions = &apSource->actions;
    for (int i = 0; i < pSourceActions->count; ++i)
    {
        if (pSourceActions->data[i] != 0)
        {
            v38->data[k] = pSourceActions->data[i];
            v38->data[k]->m_pCurrentSimulationIsland = apTarget;
            ++k;
        }
    }
    v38->SetSize(k);
    for (int i = 0; i < pSourceEntities->count; ++i)
    {
        hkpEntity* e = pSourceEntities->data[i];
        ConstraintRuntimeInfo* rec = (ConstraintRuntimeInfo*)e->m_eSmallArraySerializeOverrideType.m_data;
        for (int cnt = e->m_eSmallArraySerializeOverrideType.m_iElementCount - 1; cnt >= 0; --cnt)
        {
            rec->constraint->m_pOwnerObject = reinterpret_cast<hkpConstraintOwner*>(apTarget);
            ++rec;
        }
    }
    apTarget->MergeFrom(apSource);
    apTarget->unk1C += apSource->unk1C;
    apSource->unk1C = 0;
    unsigned short uSourceIndex = apSource->storageIndex;
    hkArrayNative<hkpSimulationIsland*>* c = ((apSource->flags26 & 3) != 0) ? reinterpret_cast<hkArrayNative<hkpSimulationIsland*>*>(&o->m_kActiveSimulationIslands) : reinterpret_cast<hkArrayNative<hkpSimulationIsland*>*>(&o->m_kInactiveSimulationIslands);
    int iListCount = c->count;
    if ((int)uSourceIndex < iListCount - 1)
    {
        c->data[uSourceIndex] = c->data[iListCount - 1];
        c->data[uSourceIndex]->storageIndex = uSourceIndex;
    }
    c->count--;
    unsigned char al = ((apTarget->flags25 & 3) != 0 || (apSource->flags25 & 3) != 0) ? 1 : 0;
    unsigned char x25 = apTarget->flags25;
    x25 ^= al;
    x25 &= 3;
    apTarget->flags25 ^= x25;
    unsigned char cl2 = apTarget->flags25;
    unsigned char al2 = ((cl2 & 0x30) != 0 || (apSource->flags25 & 0x30) != 0) ? 1 : 0;
    unsigned char uNewFlags = (unsigned char)(al2 << 4);
    uNewFlags ^= cl2;
    uNewFlags &= 0x30;
    uNewFlags ^= cl2;
    apTarget->flags25 = uNewFlags;
    apTarget->f26.f26mid = f18 != 0;
    if (apSource->dirtyIndex != 0xffff && apTarget->dirtyIndex == 0xffff)
    {
        apTarget->dirtyIndex = (unsigned short)o->m_kDirtySimulationIslands.m_iElementCount;
        hkArrayNative<hkpSimulationIsland*>* pDirtyList = reinterpret_cast<hkArrayNative<hkpSimulationIsland*>*>(&o->m_kDirtySimulationIslands);
        pDirtyList->AddBack(apTarget);
    }
    ClearSlotReference(apWorld, apSource);
    delete apSource;
    int w;
    if ((apTarget->flags26 & 3) != 0 && (w = apTarget->storageIndex) != 0)
    {
        hkArrayNative<hkpSimulationIsland*>* pActiveList = reinterpret_cast<hkArrayNative<hkpSimulationIsland*>*>(&o->m_kActiveSimulationIslands);
        hkpSimulationIsland* pFirstIsland = pActiveList->data[0];
        if (apTarget->entities.count > pFirstIsland->entities.count)
        {
            apTarget->storageIndex = 0;
            pFirstIsland->storageIndex = w;
            pActiveList->data[0] = apTarget;
            pActiveList->data[w] = pFirstIsland;
        }
    }
    apWorld->nullsub_5(apTarget);
    if (--o->m_iCriticalOperationsLockCount == 0 && o->m_bBlockExecutingPendingOperations.m_cBooleanValue == 0)
    {
        if (o->m_iPendingOperationCount != 0)
            o->FUN_00c91120();
        if (o->m_iPendingOperationQueueCount == 1 && o->m_iQueuedOperationCount != 0)
        {
            o->UpdateFields_00c91140();
            return;
        }
    }
}

struct IslandList
{
    struct hkpSimulationIsland** items;
    int count;
    int capacity;
};

void __cdecl hkpWorldOperationUtil_splitSimulationIsland(hkpSimulationIsland* data, hkpWorld* object, IslandList* list, int value);
void __cdecl AddItemToContainer(hkpWorld* object, hkpSimulationIsland* item);
// Picks a list by the node's low state, runs FUN_00cb6060, then for each new item copies that state, sets its index, and may call AddItemToContainer.
// @fnv 0x00cb6e70
void __cdecl PropagateStateToChildren(hkpWorld* object, int* apNode)
{
    hkpSimulationIsland* node = (hkpSimulationIsland*)apNode;
    unsigned char uiLowState = node->flags26 & 3;
    IslandList* list;
    if (uiLowState != 0)
        list = reinterpret_cast<IslandList*>(&object->m_kActiveSimulationIslands);
    else
        list = reinterpret_cast<IslandList*>(&object->m_kInactiveSimulationIslands);
    node->flags25 &= 0xfc;
    int initialIndex = list->count;
    hkpWorldOperationUtil_splitSimulationIsland(node, object, list, 0);
    unsigned char uiHighState = (node->flags26 >> 2) & 3;
    int currentIndex = initialIndex;
    while (currentIndex < list->count)
    {
        hkpSimulationIsland* item = list->items[currentIndex];
        item->f26.f26mid = uiLowState;
        item->f26.f26lo = uiLowState;
        if (uiLowState != 0 && uiHighState == 0)
            AddItemToContainer(object, item);
        item->unk24 = (unsigned char)(node->unk24 - initialIndex + currentIndex);
        ++currentIndex;
    }
}

#include <windows.h>
namespace fnv_00cb5480 {
// Lock-guarded append of a pointer item into the list at this+0x40.
// Clears flag bits on the item, and if its word slot is 0xffff, stamps the
// current count into it and appends the item (growing via the allocator).


extern "C" hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
extern "C" void __cdecl ResizeAudioStream(void* pAllocator, void* pArray, int iStride);

struct PtrArray
{
    void* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapFlags;
};

// Clears bits 0xc of pItem's m_b26, then under the lock, if m_w22 is 0xffff, stores the array size in it and appends pItem to m_40.
// @fnv 0x00cb5480
// src: HAVOK_LIB 0x00cb5480
void hkpWorldOperationUtil_markIslandInactiveMt(hkpWorld* pList, hkpSimulationIsland* pItem)
{
    pItem->flags26 &= 0xf3;
    EnterCriticalSection(static_cast<CRITICAL_SECTION*>(pList->m_pIslandDirtyListCriticalSection));
    if (pItem->dirtyIndex == 0xffff)
    {
        pItem->dirtyIndex = (unsigned short)pList->m_kDirtySimulationIslands.m_iElementCount;
        PtrArray* arr = reinterpret_cast<PtrArray*>(&pList->m_kDirtySimulationIslands);
        hkMemoryRouter* holder = hkMemoryRouter_getInstance();
        if (arr->m_iArrayLength == (int)(arr->m_uCapFlags & 0x3fffffff))
        {
            fnv_00cb5480::ResizeAudioStream(holder->m_heap, arr, 4);
        }
        hkpSimulationIsland** slot = (hkpSimulationIsland**)((char*)arr->m_pData + *(volatile int*)&arr->m_iArrayLength * 4);
        *slot = pItem;
        arr->m_iArrayLength++;
    }
    LeaveCriticalSection(static_cast<CRITICAL_SECTION*>(pList->m_pIslandDirtyListCriticalSection));
}
}  // namespace fnv_00cb5480


struct Cb4890_ElemArray
{
    hkpEntity** m_data;
    int m_iElementCount;
};
struct Cb4890_IntArray
{
    int* m_data;
    int m_iElementCount;
};
struct Cb4890_CharArray
{
    char* m_data;
    int m_iElementCount;
};
struct Cb4890_Stack
{
    char* m_next;
    __forceinline void* allocateStack(int nbytes) throw()
    {
        char* p = m_next;
        m_next = p + ((nbytes + 127) & ~127);
        return p;
    }
    __forceinline void deallocateStack(void* p) throw()
    {
        m_next = (char*)p;
    }
};
template <class T> struct Cb4890_LocalBuffer
{
    T* m_p;
    int m_iElementCount;
    __forceinline Cb4890_LocalBuffer(int n) throw()
    {
        m_p = (T*)((Cb4890_Stack*)hkMemoryRouter_getInstance())->allocateStack(n * (int)sizeof(T));
    }
    __forceinline ~Cb4890_LocalBuffer() throw()
    {
        ((Cb4890_Stack*)hkMemoryRouter_getInstance())->deallocateStack(m_p);
    }
    __forceinline T& operator[](int i) throw()
    {
        return m_p[i];
    }
};

struct Cb4890_RemapTable
{
    Cb4890_IntArray* m_entries;
    int m_iElementCount;
    void RemapAndAccumulate(Cb4890_LocalBuffer<int>& map, int count, Cb4890_IntArray* src) throw();
};
template <class T> __forceinline T Cb4890_max2(T a, T b)
{
    return a > b ? a : b;
}

__forceinline int RemapOne(Cb4890_LocalBuffer<int>& used, int* mapped, Cb4890_CharArray* out, int i, int count)
{
    if (used[i])
        mapped[i] = 0;
    else
    {
        mapped[i] = count;
        out->m_data[count] = 0;
        count++;
    }
    return count;
}
// Marks entries used by list elements whose decoded m_ea and m_ec are both at most 5, renumbers the rest via RemapOne, then calls RemapAndAccumulate unless k > n.
// @fnv 0x00cb4890
static __declspec(noinline) void RemapElements(const Cb4890_ElemArray& list, Cb4890_RemapTable* remap,
                                               hkpWorld* owner, Cb4890_IntArray* src, Cb4890_CharArray* out)
{
    int n = src->m_iElementCount;
    Cb4890_LocalBuffer<int> used(n);
    for (int i = 0; i < n; i++)
        used[i] = 0;
    for (int j = 0; j < list.m_iElementCount; j++)
    {
        const hkpEntity* e = list.m_data[j];
        int a = e->m_pMotionState.m_ausDeactivationNumInactiveFrames[1];
        if (reinterpret_cast<unsigned char&>(owner->pad1C8[0x13e]) == (a >> 14))
            a = (a >> 7) & 0x7f;
        else
            a &= 0x7f;
        int b = e->m_pMotionState.m_ausDeactivationNumInactiveFrames[0];
        if (reinterpret_cast<unsigned char&>(owner->pad1C8[0x13d]) == (b >> 14))
            b = (b >> 7) & 0x7f;
        else
            b &= 0x7f;
        if (Cb4890_max2(b & 0x7f, a & 0x7f) <= 5)
            used[remap->m_entries->m_data[j]] = 1;
    }
    int* remapOut = used.m_p;
    int k = 1;
    out->m_data[0] = 1;
    for (int i = 0; i < n; i++)
    {
        k = RemapOne(used, remapOut, out, i, k);
    }
    if (k > n)
        out->m_data[0] = 0;
    else
        remap->RemapAndAccumulate(used, k, src);
}

volatile int g_cb4890[5];
void Cb4890_caller()
{
    RemapElements(*(Cb4890_ElemArray*)g_cb4890[0], (Cb4890_RemapTable*)g_cb4890[1], (hkpWorld*)g_cb4890[2],
                  (Cb4890_IntArray*)g_cb4890[3], (Cb4890_CharArray*)g_cb4890[4]);
}

struct S00cb5100_WBits
{
    unsigned short lo : 14;
    unsigned short hi : 2;
};
struct S00cb5100_Bits
{
    unsigned char lo : 2;
    unsigned char hi : 6;
};

__forceinline void SetDeactivationFilter(hkpEntity* entity, int a0, int a1, int a2)
{
    if ((unsigned int)(a2 & 3) < (unsigned int)(entity->m_pMotionState.m_ucDeactivationIntegrateCounter & 3))
        a0 = (~a0) << 14;
    else
        a0 <<= 14;
    if (a2 < entity->m_pMotionState.m_ucDeactivationIntegrateCounter)
        a1 = (~a1) << 14;
    else
        a1 <<= 14;
    entity->m_pMotionState.m_ausDeactivationNumInactiveFrames[0] = (unsigned short)((entity->m_pMotionState.m_ausDeactivationNumInactiveFrames[0] & 0x3fff) | a0);
    entity->m_pMotionState.m_ausDeactivationNumInactiveFrames[1] = (unsigned short)((entity->m_pMotionState.m_ausDeactivationNumInactiveFrames[1] & 0x3fff) | a1);
}


void ResizeAudioStream(void* heap, void* arr, int elemSize);
struct S00cb5100_Arr
{
    hkpSimulationIsland** m_data;
    int m_iElementCount;
    int m_cap;
    hkpSimulationIsland* pick(int* n, hkpSimulationIsland** b, int k);
    void AddBack(hkpSimulationIsland* const& e)
    {
        S_00c6aca0_Router* r = hkMemoryRouter_getInstance();
        if (m_iElementCount == (m_cap & 0x3fffffff))
            ResizeAudioStream(r->m10, this, 4);
        hkpSimulationIsland** out = m_data + m_iElementCount;
        for (int k = 0; k < 1; ++k)
            out[k] = e;
        ++m_iElementCount;
    }
};
void hkSweptTransformUtil_setTimeInformation(float a, float b, void* p);
void ProcessBlocks(hkpSimulationIsland* b, float f, float g, int h);


void ProcessSceneCallbacks(hkpWorld* w, hkpSimulationIsland* b);

static __declspec(noinline) hkpSimulationIsland* FindItemForThreshold(hkpWorld* w, S00cb5100_Arr* arr, int n,
                                                                 hkpSimulationIsland* b)
{
    if (w->m_kInactiveSimulationIslands.m_iElementCount == 0 || arr->m_iElementCount == 0)
        return 0;
    return arr->pick(&n, &b, w->m_kInactiveSimulationIslands.m_iElementCount);
}

static inline bool S00cb5100_lt(unsigned char a, unsigned char b)
{
    return a < b;
}

// Moves b from w's data34 list to arr28, resets its entries, then merges it with another body via FUN_00cb4c60 if merge allows, else may swap it to the front.
// @fnv 0x00cb5100
// src: HAVOK_LIB 0x00cb5100
void hkpWorldOperationUtil_internalActivateIsland(hkpWorld* apWorld, hkpSimulationIsland* apBody, bool merge)
{
    reinterpret_cast<hkpSimulationIsland**>(apWorld->m_kInactiveSimulationIslands.m_data)[apBody->storageIndex] = reinterpret_cast<hkpSimulationIsland**>(apWorld->m_kInactiveSimulationIslands.m_data)[apWorld->m_kInactiveSimulationIslands.m_iElementCount - 1];
    reinterpret_cast<hkpSimulationIsland**>(apWorld->m_kInactiveSimulationIslands.m_data)[apBody->storageIndex]->storageIndex = apBody->storageIndex;
    apWorld->m_kInactiveSimulationIslands.m_iElementCount--;

    S00cb5100_Arr* arr = reinterpret_cast<S00cb5100_Arr*>(&apWorld->m_kActiveSimulationIslands);
    arr->AddBack(apBody);

    apBody->storageIndex = (unsigned short)(apWorld->m_kActiveSimulationIslands.m_iElementCount - 1);
    reinterpret_cast<float&>(apBody->unk30) = 0.0f;
    reinterpret_cast<float&>(apBody->unk34) = 0.0f;
    apBody->flags26 = (apBody->flags26 & ~2) | 1;

    for (int i = 0; i < apBody->entities.count; i++)
    {
        hkpEntity* e = apBody->entities.data[i];
        hkSweptTransformUtil_setTimeInformation(0.0f, 0.0f, &e->m_pMotionState.m_kMotionState);
        e->m_pMotionState.m_ausDeactivationNumInactiveFrames[0] = 0;
        e->m_pMotionState.m_ausDeactivationNumInactiveFrames[1] = 0;
        SetDeactivationFilter(e, reinterpret_cast<unsigned char&>(apWorld->pad1C8[0x13d]), reinterpret_cast<unsigned char&>(apWorld->pad1C8[0x13e]), reinterpret_cast<unsigned char&>(apWorld->pad1C8[0x13f]));
    }

    ProcessBlocks(apBody, reinterpret_cast<float&>(apBody->unk44), reinterpret_cast<float&>(apWorld->pad1C8[8]), reinterpret_cast<int>(apWorld->m_pCollisionInput));
    hkpEntity* e0 = apBody->entities.data[0];
    e0->addReference();
    ProcessSceneCallbacks(apWorld, apBody);
    if (e0->m_pSimulationIsland == reinterpret_cast<hkpSimulationIsland*>(apBody))
    {
        e0->removeReference();
        if (merge)
        {
            int m = apBody->unk1C + 3;
            int n = apBody->entities.count + 1;
            if (n > m)
                m = n;
            hkpSimulationIsland* o = FindItemForThreshold(apWorld, arr, m, apBody);
            if (o)
            {
                hkpWorldOperationUtil_internalMergeTwoIslands((ObjA*)apWorld, (int)o, (int)apBody);
                return;
            }
        }
        unsigned int idx = apBody->storageIndex;
        if (idx != 0)
        {
            hkpSimulationIsland* first = arr->m_data[0];
            if (apBody->entities.count > first->entities.count)
            {
                apBody->storageIndex = 0;
                first->storageIndex = (unsigned short)idx;
                arr->m_data[0] = apBody;
                arr->m_data[idx] = first;
            }
        }
    }
    else
    {
        e0->removeReference();
    }
}

#include <xmmintrin.h>
extern float DAT_01017d00;

__forceinline int c6a870Equals3(const __m128& a, const __m128& b, float eps = 0.001f)
{
    static __declspec(align(16)) const unsigned int mask[4] = {0x7fffffff, 0x7fffffff, 0x7fffffff, 0x7fffffff};
    __m128 d = _mm_sub_ps(a, b);
    d = _mm_and_ps(d, _mm_load_ps((const float*)mask));
    __m128 e = _mm_set_ps1(eps);
    return (_mm_movemask_ps(_mm_cmple_ps(d, e)) & 7) == 7;
}

template <typename T> __forceinline T* AllocateBuffer(hkMemoryAllocator& allocator, int& n, int& numBytes)
{
    typedef void* (__thiscall* AllocateBufferFn)(hkMemoryAllocator*, int&);
    AllocateBufferFn alloc = (*reinterpret_cast<AllocateBufferFn**>(&allocator))[3];
    numBytes = n * int(sizeof(T));
    void* p = alloc(&allocator, numBytes);
    n = numBytes / int(sizeof(T));
    return (T*)p;
}

__forceinline hkMemoryAllocator& c6a870Heap()
{
    return *(hkMemoryAllocator*)&hkMemoryRouter_getInstance()->heap();
}

template <typename T> __forceinline void c6a870Copy(T* dst, const T* src, int n)
{
    if (n <= 0)
        return;
    for (int i = 0; i < n; i++)
        dst[i] = src[i];
}



void __cdecl hkpWorldOperationUtil_cleanupDirtyIslands(hkpWorld* world);
void __cdecl AddItemToContainer(hkpWorld* world, hkpSimulationIsland* item);

struct C6A870_Self;
typedef hkpWorld*(__thiscall* C6A870_Query)(C6A870_Self*);
struct C6A870Allocator {
 template<class T,class A> static __forceinline void destroy(hkArray<T,A>& a) {
 hkMemoryAllocator& h=c6a870Heap();a.m_iElementCount=0;
 if((a.m_iCapacityState&0x80000000)==0)h.bufFree(a.m_data,a.getCapacity()*sizeof(T));
 a.m_data=0;a.m_iCapacityState=0x80000000;
 }
};
template<class T> __forceinline void copyIslandArray(hkArrayBase<T>& a,const hkArrayBase<T>& src,int& scratch) {
 hkMemoryAllocator& h=c6a870Heap();
 if(a.getCapacity()<src.GetLogicalSize()) {
 if((a.m_iCapacityState&0x80000000)==0)h.bufFree(a.m_data,a.getCapacity()*sizeof(T));
 int n=src.GetLogicalSize();a.m_data=AllocateBuffer<T>(h,n,scratch);a.m_iCapacityState=n;
 }
 a.m_iElementCount=src.GetLogicalSize();c6a870Copy(a.m_data,src.m_data,a.m_iElementCount);
}
struct C6A870_QueryTable
{
    void* f00;
    void* f04;
    void* f08;
    void* f0c;
    void* f10;
    void* f14;
    void* f18;
    void* f1c;
    void* f20;
    void* f24;
    void* f28;
    void* f2c;
    void* f30;
    void* f34;
    void* f38;
    void* f3c;
    void* f40;
    void* f44;
    void* f48;
    void* f4c;
    void* f50;
    void* f54;
    void* f58;
    void* f5c;
    void* f60;
    void* f64;
    void* f68;
    void* f6c;
    void* f70;
    void* f74;
    void* f78;
    void* f7c;
    void* f80;
    void* f84;
    void* f88;
    void* f8c;
    void* f90;
    C6A870_Query query;
};
struct C6A870_View
{
    C6A870_QueryTable* table;
};

struct C6A870_Self
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual hkpWorld* getWorld();

    void bhkWorld_DeactivateAllIslands();
};

// Calls AddItemToContainer for each world item whose children all have both constraint vectors equal to a constant, with FUN_00cb55d0 called before and after.
// @fnv 0x00c6a870
// src: XBOX_PDB 0x00c6a870
void C6A870_Self::bhkWorld_DeactivateAllIslands()
{
    int i;
    hkpWorld* world = getWorld();
    if (!world)
        return;

    getWorld();
    hkpWorldOperationUtil_cleanupDirtyIslands(world);
    getWorld();

    hkArray<hkpSimulationIsland*,C6A870Allocator> items;
    getWorld();
    copyIslandArray<hkpSimulationIsland*>(items, reinterpret_cast<hkArrayBase<hkpSimulationIsland*>&>(world->m_kActiveSimulationIslands), i);
    C6A870_QueryTable* pQueryTable = ((C6A870_View*)this)->table;
    pQueryTable->query(this);

    for (i = 0; i < items.GetLogicalSize(); ++i)
    {
        hkpSimulationIsland* item = items[i];
        char moved = 0;
        int n = item->entities.count;
        for (int j = 0; j < n; j++)
        {
            if (moved)
                break;
            hkpEntity* c = item->entities.data[j];
            if (c6a870Equals3(c->m_pMotionState.m_kTranslationalVelocity.m_vComponents, _mm_load_ps((const float*)&DAT_01267e30)))
            {
                if (c6a870Equals3(c->m_pMotionState.m_kAngularVelocity.m_vComponents, _mm_load_ps((const float*)&DAT_01267e30)))
                    continue;
            }
            moved = 1;
        }
        if (!moved)
        {
            getWorld();
            AddItemToContainer(world, item);
            getWorld();
        }
    }

    getWorld();
    hkpWorldOperationUtil_cleanupDirtyIslands(world);
    getWorld();
}


struct Selector
{
    unsigned char first;
    unsigned char second;
};


__forceinline int GetInactiveFrames(hkpMotion& motion, int slot, int flag)
{
    int packed = motion.m_ausDeactivationNumInactiveFrames[slot];
    int mode = packed >> 14;
    int n;
    if (flag != mode)
        n = packed & 127;
    else
        n = (packed >> 7) & 127;
    return n & 127;
}

template <class T> struct View4120
{
    T* data;
    int count;
    __forceinline const T& operator[](int i) const
    {
        return data[i];
    }
    __forceinline T& operator[](int i)
    {
        return data[i];
    }
    __forceinline int size() const
    {
        return count;
    }
};
struct Groups4120
{
    View4120<int>& groups;
    int n;
};
template <class T> __forceinline T greater4120(T a, T b)
{
    return a > b ? a : b;
}

// Iterates entries, marks active groups when motion frames are 5 or fewer, and accumulates per-group size counts.
// @fnv 0x00cb4120
static __declspec(noinline) void UpdateGroupActivity(const Groups4120& map, const View4120<hkpEntity*>& entries,
                                                     int unusedGroups, View4120<int>& active, View4120<int>& sizes,
                                                     unsigned char* flags)
{
    for (int i = 0; i < entries.size(); ++i)
    {
        hkpEntity* entity = entries[i];
        int group = map.groups[i];
        int frames = greater4120(GetInactiveFrames(entity->m_pMotionState, 0, flags[0]), GetInactiveFrames(entity->m_pMotionState, 1, flags[1]));
        if (frames <= 5)
        {
            active[group] = 1;
        }
        int count = greater4120(1, (int)entity->m_eSmallArraySerializeOverrideType.m_iElementCount);
        sizes[group] += count;
    }
}

extern const Groups4120* volatile inputMap4120;
extern const View4120<hkpEntity*>* volatile inputEntities4120;
extern View4120<int>* volatile outputActive4120;
extern View4120<int>* volatile outputSizes4120;
extern unsigned char* volatile inputFlags4120;
extern int volatile groupCount4120;
void caller4120()
{
    UpdateGroupActivity(*inputMap4120, *inputEntities4120, groupCount4120, *outputActive4120, *outputSizes4120,
                        inputFlags4120);
}

struct CallA
{
    signed char delta;
    void UpdateCollisionIndices();
    void CopyAndSortGeometryList(void* p);
};

struct MotionObj
{
    void* vt;
    int unk04;
    hkpWorld* m_08;
    int unk0c;
    CallA collidable;
    unsigned char unk11, unk12, unk13;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    hkpSimulationIsland* m_cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    unsigned char m_e8, unke9, unkea, unkeb;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int m_1f8;
};

typedef void(__thiscall* FnFree)(void* self, void* p, int bytes);
typedef void(__thiscall* Fn20)(void* self, void* p, int a, void* b, int c);
struct RemRef
{
    void FUN_00c905b0();
};

struct CallB
{
    void UpdateNodeSlotIndices();
    void FUN_00c90510();
};
// The shared world header does not yet declare FUN_00c946e0(void*, void*, int).
struct CallInner
{
    void hkpWorld_updateCollisionFilterOnEntity(void* p, void* q, int a);
};
void hkpSimulation_collideEntitiesBroadPhaseDiscrete(void* p, int a, void* b);
void hkpWorldOperationUtil_removeAttachedConstraints(MotionObj* a0, void* b);
void CollectActorEntries(hkpWorld* s, MotionObj* a0, void* a);
void CollectProducers(hkpWorld* s, MotionObj* a0, void* a);
void hkpWorldOperationUtil_removeEntitySI(hkpWorld* s, MotionObj* a0);
void hkpWorldOperationUtil_addConstraintImmediately(hkpWorld* s, void* e, int z);
struct ModeBool
{
    bool value;
    ModeBool()
    {}
    ModeBool(bool b) : value(b)
    {}
    ModeBool(const ModeBool& b) : value(b.test())
    {}
    void set(bool b)
    {
        static_cast<volatile bool&>(value) = b;
    }
    bool test() const
    {
        return value;
    }
    operator bool() const
    {
        return test();
    }
};
void hkpWorldOperationUtil_replaceMotionObject(MotionObj* a0, int mode, ModeBool fMode, ModeBool fCur, hkpWorld* s);
void hkpWorldOperationUtil_addEntitySI(hkpWorld* s, int a5, int a7);
void ApplyConstraintsToEntity(hkpWorld* s, int a8, void* p);
void hkpWorldOperationUtil_removeAttachedAgentsConnectingTheEntityAndAFixedPartnerEntityPlus(void* m, MotionObj* a3, void* w, int mode);
void _hkAgentNnMachine_AppendTrack(void* m, void* w);
void hkpWorldOperationUtil_mergeIslands(hkpWorld* in, MotionObj* a0, MotionObj* e);
void UpdateRotationInterpolation(float f, void* p);
void NotifyEntityRemoved(void* p, MotionObj* a3);
struct VecB
{
    void* data;
    int size;
    int cap;
    void* buf[16];
};
struct VecA
{
    void* data;
    int size;
    int cap;
    void* buf[16];
};
struct Work
{
    int f0;
    void* data;
    int size;
    int cap;
    int buf0;
};
struct Elem8
{
    int f0;
    MotionObj* f4;
};
struct VecC
{
    Elem8* data;
    int size;
    int cap;
    VecC() : data(0), size(0), cap((int)0x80000000)
    {}
};
struct HeadC
{
    short unk10;
    ModeBool fCur;
    ModeBool fMode;
};
static __forceinline void FreeVec(void** dataP, int* sizeP, int* capP, int elem)
{
    S_00c6aca0_Router* m = hkMemoryRouter_getInstance();
    void* fo = m->m10;
    int cap = *capP;
    *sizeP = 0;
    if ((cap & (int)0x80000000) == 0)
    {
        FnFree fn = (FnFree)(*(void***)fo)[4];
        fn(fo, *dataP, (cap & 0x3fffffff) * elem);
    }
    *dataP = 0;
    *capP = (int)0x80000000;
}
// Returns if mode equals a0->m_e8; else calls FUN_00cb4230 and, if a0->m_08 is set and exactly one mode is 5, updates owner state, lists and constraints.
// @fnv 0x00cb6f70
// src: HAVOK_LIB 0x00cb6f70
void hkpWorldOperationUtil_setRigidBodyMotionType(MotionObj* apMotionObj, int aiNewMode, int a2, MotionObj* a3, int a4, int a5, int a6, int a7, int a8)
{
    {
        ModeBool fCur;
        ModeBool fMode;
        unsigned long uiCurMode = apMotionObj->m_e8;
        if (uiCurMode == aiNewMode)
            return;
        if (uiCurMode == 5)
        {
            apMotionObj->collidable.UpdateCollisionIndices();
            ((CallB*)apMotionObj)->UpdateNodeSlotIndices();
        }
        if (aiNewMode == 5)
            fMode.set(0);
        else
        {
            fMode.set(1);
            if (aiNewMode == 4)
                fMode.set(0);
        }
        if (uiCurMode == 5)
            fCur.set(0);
        else
        {
            fCur.set(1);
            if (uiCurMode == 4)
                fCur.set(0);
        }
        if (fMode.test() && !fCur.test() && apMotionObj->m_1f8 == 0)
            return;
        ((CallB*)apMotionObj)->FUN_00c90510();
        hkpWorld* pForm = apMotionObj->m_08;
        bool diff5 = ((uiCurMode == 5) != (aiNewMode == 5));
        if (pForm != 0 && diff5)
        {
            VecB adj;
            VecA a;
            Work esi;
            adj.data = adj.buf;
            adj.cap = (int)0x80000010;
            a.data = a.buf;
            a.cap = (int)0x80000010;
            pForm->m_bBlockExecutingPendingOperations.m_cBooleanValue = 1;
            pForm->m_bBlockExecutingPendingOperationQueues.m_cBooleanValue = 0;
            adj.size = 0;
            a.size = 0;
            esi.data = &esi.buf0;
            esi.size = 0;
            esi.cap = (int)0x80000001;
            esi.f0 = 0x200;
            hkpWorldOperationUtil_removeAttachedConstraints(apMotionObj, &adj);
            if (aiNewMode != 5)
                CollectActorEntries(pForm, apMotionObj, &a);
            else
                CollectProducers(pForm, apMotionObj, &a);
            hkpSimulationIsland* manager = apMotionObj->m_cc;
            hkpWorldOperationUtil_removeAttachedAgentsConnectingTheEntityAndAFixedPartnerEntityPlus(&manager->unk58, apMotionObj, &esi, aiNewMode);
            if (uiCurMode != 5)
            {
                if (apMotionObj->m_cc->entities.count > 2)
                    apMotionObj->m_cc->flags25 = (apMotionObj->m_cc->flags25 & 0xfc) | 1;
            }
            hkpWorldOperationUtil_removeEntitySI(pForm, apMotionObj);
            hkpWorldOperationUtil_replaceMotionObject(apMotionObj, aiNewMode, fMode, fCur, pForm);
            hkpWorldOperationUtil_addEntitySI(pForm, (int)apMotionObj, a2);
            ApplyConstraintsToEntity(pForm, (int)apMotionObj, &a);
            pForm->m_bBlockExecutingPendingOperationQueues.m_cBooleanValue = 1;
            VecC vec;
            for (int i = 0; i < adj.size; i++)
            {
                MotionObj* e = ((MotionObj**)adj.data)[i];
                hkpWorldOperationUtil_addConstraintImmediately(pForm, e, 0);
                ((RemRef*)e)->FUN_00c905b0();
            }
            if (aiNewMode != 5)
            {
                apMotionObj->collidable.CopyAndSortGeometryList(&vec);
                for (int i = 0; i < vec.size; i++)
                {
                    MotionObj* pOtherMotion = vec.data[i].f4;
                    MotionObj* work =
                        (MotionObj*)((char*)pOtherMotion + (int)(signed char)pOtherMotion->collidable.delta);
                    if (apMotionObj->m_e8 == 5)
                        continue;
                    if (work->m_e8 == 5)
                        continue;
                    if (apMotionObj->m_cc == work->m_cc)
                        continue;
                    hkpWorldOperationUtil_mergeIslands(apMotionObj->m_08, apMotionObj, work);
                }
            }
            _hkAgentNnMachine_AppendTrack(&apMotionObj->m_cc->unk58, &esi);
            if (aiNewMode == 5)
            {
                UpdateRotationInterpolation(reinterpret_cast<float&>(pForm->pad1C8[8]), &apMotionObj->unk0f0);
                MotionObj* o8 = reinterpret_cast<MotionObj*>(pForm->m_pSimulation);
                pForm->m_iCriticalOperationsLockCount++;
                Fn20 fn = (Fn20)(*(void***)o8)[8];
                fn(o8, &apMotionObj, 1, pForm, 7);
                hkpSimulation_collideEntitiesBroadPhaseDiscrete(&apMotionObj, 1, pForm);
                NotifyEntityRemoved(apMotionObj->m_08, apMotionObj);
                pForm->m_iCriticalOperationsLockCount--;
            }
            ((CallInner*)pForm)->hkpWorld_updateCollisionFilterOnEntity(apMotionObj, a3, 1);
            pForm->m_bBlockExecutingPendingOperations.m_cBooleanValue = 0;
            if (pForm->m_iCriticalOperationsLockCount == 0)
            {
                if (pForm->m_iPendingOperationCount != 0)
                    pForm->FUN_00c91120();
                if (pForm->m_iPendingOperationQueueCount == 1 && pForm->m_iQueuedOperationCount != 0)
                    pForm->UpdateFields_00c91140();
            }
            FreeVec((void**)&vec.data, &vec.size, &vec.cap, 8);
            FreeVec(&esi.data, &esi.size, &esi.cap, 4);
            FreeVec(&a.data, &a.size, &a.cap, 4);
            FreeVec(&adj.data, &adj.size, &adj.cap, 4);
        }
        else
        {
            hkpWorldOperationUtil_replaceMotionObject(apMotionObj, aiNewMode, fMode, fCur, pForm);
            if (pForm ? true : false)
                ((CallInner*)pForm)->hkpWorld_updateCollisionFilterOnEntity(apMotionObj, a3, 1);
        }
    }
    ((RemRef*)apMotionObj)->FUN_00c905b0();
}

struct S00cb4230_Vec4
{
    float& operator()(int a)
    {
        return reinterpret_cast<float*>(m_vComponents)[a];
    }
    const float& operator()(int a) const
    {
        return reinterpret_cast<const float*>(m_vComponents)[a];
    }
    __declspec(align(16)) float m_vComponents[4];
};
struct S00cb4230_Quat
{
    S00cb4230_Quat()
    {}
    S00cb4230_Vec4 m_vec;
};
// local form of hkMatrix3: 0x00cb4230 needs inline matrix construction and swept-time accessors; shared form gives 1160 bytes vs exe 1035.
struct InertiaTensor
{
    InertiaTensor()
    {}
    S00cb4230_Vec4 m_kColumn0;
    S00cb4230_Vec4 m_kColumn1;
    S00cb4230_Vec4 m_kColumn2;
};
struct S00cb4230_Rotation : InertiaTensor
{
    S00cb4230_Rotation()
    {}
};
struct S00cb4230_Transform
{
    S00cb4230_Transform()
    {}
    S00cb4230_Rotation m_rotation;
    S00cb4230_Vec4 m_vTranslation;
    const S00cb4230_Vec4& getTranslation() const
    {
        return m_vTranslation;
    }
};
// local form of hkSweptTransform: 0x00cb4230 needs inline matrix construction and swept-time accessors; shared form gives 1160 bytes vs exe 1035.
struct S00cb4230_Swept
{
    S00cb4230_Swept()
    {}
    float getInvDeltaTime() const
    {
        return m_vCenterOfMass1(3);
    }
    float getBaseTime() const
    {
        return m_vCenterOfMass0(3);
    }
    S00cb4230_Vec4 m_vCenterOfMass0;
    S00cb4230_Vec4 m_vCenterOfMass1;
    S00cb4230_Quat m_qRotation0;
    S00cb4230_Quat m_qRotation1;
    S00cb4230_Vec4 m_vCenterOfMassLocal;
};
extern float DAT_010c7948[];
struct S00cb4230_UFloat8
{
    S00cb4230_UFloat8()
    {}
    operator float() const
    {
        return DAT_010c7948[m_uiFilterValue];
    }
    unsigned char m_uiFilterValue;
};
struct S00cb4230_MotionStateData
{
    S00cb4230_MotionStateData()
    {}
    S00cb4230_Transform& getTransform()
    {
        return m_kMotionTransform;
    }
    const S00cb4230_Transform& getTransform() const
    {
        return m_kMotionTransform;
    }
    S00cb4230_Swept& getSweptTransform()
    {
        return m_kSweptTransform;
    }
    const S00cb4230_Swept& getSweptTransform() const
    {
        return m_kSweptTransform;
    }
    void hkMotionState_Copy(void* p);
    S00cb4230_Transform m_kMotionTransform;
    S00cb4230_Swept m_kSweptTransform;
    S00cb4230_Vec4 m_kDeltaAngle;
    float m_fObjectRadius;
    float m_fLinearDamping;
    float m_fAngularDamping;
    S00cb4230_UFloat8 m_fSurfaceFriction;
    S00cb4230_UFloat8 m_fRestitution;
    short m_uiDeactivationClass;
};
struct MotionFlag31
{
    inline MotionFlag31()
    {}
    inline MotionFlag31(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
    inline operator bool() const
    {
        return m_cBooleanValue != 0;
    }
    inline MotionFlag31 operator==(bool e) const
    {
        return static_cast<int>(m_cBooleanValue) == static_cast<int>(e);
    }
    inline MotionFlag31 operator!=(bool e) const
    {
        return static_cast<int>(m_cBooleanValue) != static_cast<int>(e);
    }

  private:
    char m_cBooleanValue;
};
template <typename E, typename S> struct S00cb4230_Enum
{
    S00cb4230_Enum()
    {}
    S00cb4230_Enum(E e)
    {
        m_kStorage = static_cast<S>(e);
    }
    operator E() const
    {
        return static_cast<E>(m_kStorage);
    }
    S m_kStorage;
};
struct AllocObj
{
    virtual void v00();
    virtual void* v01(int size);
};
struct MotionState;
struct S00cb4230_FinishFlag
{
    S00cb4230_FinishFlag() : m_bFinishing(0)
    {}
    int m_bFinishing;
};
struct S00cb4230_Half
{
    S00cb4230_Half()
    {}
    void operator=(const float& f)
    {
        int t = ((const int*)&f)[0];
        m_uiFilterValue = short(t >> 16);
    }
    short m_uiFilterValue;
};
struct S00cb4230_BaseObject
{
    S00cb4230_BaseObject()
    {}
    virtual void v00();
};
struct RefHeader31 : S00cb4230_BaseObject
{
    RefHeader31(S00cb4230_FinishFlag flag)
    {}
    unsigned short m_04;
    mutable short m_06;
};
struct MotionBase : RefHeader31
{
    MotionBase(S00cb4230_FinishFlag flag) : RefHeader31(flag)
    {
        if (flag.m_bFinishing)
        {
            m_fGravityFactor = 1.f;
        }
    }
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void GetInverseScaleMatrix(InertiaTensor& out) const;
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25(MotionState* p);
    virtual void v26();
    virtual void v27(MotionState* p);
    hkpMotion::MotionType getType() const
    {
        return m_type;
    }
    S00cb4230_MotionStateData* GetMotionState()
    {
        return &m_kMotionState;
    }
    const S00cb4230_Vec4& getPosition() const
    {
        return m_kMotionState.getTransform().getTranslation();
    }
    const S00cb4230_Quat& getRotation() const
    {
        return m_kMotionState.getSweptTransform().m_qRotation1;
    }
    const S00cb4230_Vec4& getCenterOfMassLocal() const
    {
        return m_kMotionState.getSweptTransform().m_vCenterOfMassLocal;
    }
    float getLinearDamping()
    {
        return m_kMotionState.m_fLinearDamping;
    }
    float getAngularDamping()
    {
        return m_kMotionState.m_fAngularDamping;
    }
    void setLinearDamping(float d)
    {
        m_kMotionState.m_fLinearDamping = d;
    }
    void setAngularDamping(float d)
    {
        m_kMotionState.m_fAngularDamping = d;
    }
    S00cb4230_Enum<hkpMotion::MotionType, unsigned char> m_type;
    char m_09;
    short m_0a;
    short m_0c;
    short m_0e;
    S00cb4230_MotionStateData m_kMotionState;
    S00cb4230_Vec4 m_kInertiaAndMassInv;
    S00cb4230_Vec4 m_kTranslationalVelocity;
    S00cb4230_Vec4 m_kAngularVelocity;
    S00cb4230_Vec4 m_akDeactivationReferencePositions[2];
    unsigned int m_auiDeactivationReferenceOrientations[2];
    MotionState* m_118;
    short m_11c;
    S00cb4230_Half m_fGravityFactor;
    void FUN_00c905b0();
    void FUN_00d1dff0();
    void SetFlagBits(int a, int b, int c);
    void getMotionStateAndVelocitiesAndDeactivationType(MotionBase* p);
    float FUN_00c86430();
    __forceinline static void* operator new(unsigned int nbytes)
    {
        hkMemoryAllocator& h = hkMemoryRouter_getInstance()->heap();
        RefHeader31* b = static_cast<RefHeader31*>(((AllocObj*)&h)->v01(static_cast<int>(nbytes)));
        b->m_04 = static_cast<unsigned short>(nbytes);
        return b;
    }
    __forceinline static void* operator new(unsigned int, void* p)
    {
        return p;
    }
};
struct S00cb4230_Keyframed : MotionBase
{
    S00cb4230_Keyframed() : MotionBase(S00cb4230_FinishFlag())
    {
        m_118 = 0;
    }
    S00cb4230_Keyframed(const S00cb4230_Vec4& position, const S00cb4230_Quat& rotation);
};
struct MotionState : S00cb4230_Keyframed
{
    MotionState() : S00cb4230_Keyframed()
    {}
};
struct BoxMotion : MotionBase
{
    BoxMotion(const S00cb4230_Vec4& position, const S00cb4230_Quat& rotation);
};
struct S00cb4230_String
{
    static __forceinline void __cdecl memCpy16NonEmpty(void* dst, const void* src, int numQuads)
    {
        const unsigned int* src32 = reinterpret_cast<const unsigned int*>(src);
        unsigned int* dst32 = reinterpret_cast<unsigned int*>(dst);
        {
            do
            {
                dst32[0] = src32[0];
                dst32[1] = src32[1];
                dst32[2] = src32[2];
                dst32[3] = src32[3];
                dst32 += 4;
                src32 += 4;
            } while (--numQuads > 0);
        }
    }
};
struct S00cb4230_Handle
{
    int m_iOwnerObjectOffset;
    char m_type;
    char m_iOwnerOffset;
    char m_ucObjectQualityType;
    char m_auiShapeKeys;
    int m_iFilter;
};
struct S00cb4230_Collidable
{
    const void* getShape() const
    {
        return m_pCollisionShape;
    }
    S00cb4230_Handle* getBroadPhaseHandle()
    {
        return &m_kBroadPhaseHandle;
    }
    hkpCollidableQualityType getQualityType() const
    {
        return hkpCollidableQualityType(m_kBroadPhaseHandle.m_ucObjectQualityType);
    }
    void setMotionState(const S00cb4230_MotionStateData* s)
    {
        m_pMotionState = s;
    }
    const void* m_pCollisionShape;
    int m_14;
    const void* m_pMotionState;
    int m_1c;
    int m_20;
    S00cb4230_Handle m_kBroadPhaseHandle;
};
struct ThisObj
{
    int m_00;
    int m_04;
    unsigned char m_08;
    char m_09;
    short m_0a;
    short m_0c;
    short m_0e;
    S00cb4230_Collidable m_kCollidable;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    float m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    int m_a4;
    int m_a8;
    int m_ac;
    int m_b0;
    int m_b4;
    int m_b8;
    unsigned char m_bc;
    unsigned char m_bd;
    short m_be;
    int m_c0;
    int m_c4;
    int m_c8;
    int m_cc;
    int m_d0;
    int m_d4;
    int m_d8;
    int m_dc;
    MotionState m_pMotionState;
    int m_200;
    int m_204;
    MotionBase* getMotion()
    {
        return &m_pMotionState;
    }
    MotionBase* getRigidMotion() const
    {
        return const_cast<MotionBase*>(static_cast<const MotionBase*>(&m_pMotionState));
    }
    const S00cb4230_Collidable* getCollidable() const
    {
        return &m_kCollidable;
    }
    S00cb4230_Collidable* getCollidableRw()
    {
        return &m_kCollidable;
    }
    const S00cb4230_Vec4& getPosition() const
    {
        return getRigidMotion()->getPosition();
    }
    const S00cb4230_Quat& getRotation() const
    {
        return getRigidMotion()->getRotation();
    }
    hkpCollidableQualityType getQualityType() const
    {
        return hkpCollidableQualityType(getCollidable()->getQualityType());
    }
    void setQualityType(hkpCollidableQualityType type)
    {
        getCollidableRw()->getBroadPhaseHandle()->m_ucObjectQualityType = char(type);
    }
    void UpdateBoundingVolume(void* a, const void* b);
};

void __cdecl hkString_memSet(void* p, int a, int b);
template <typename T> __forceinline T* __cdecl S00cb4230_AddByteOffset(T* base, long offset)
{
    return reinterpret_cast<T*>(reinterpret_cast<char*>(base) + offset);
}
void __cdecl hkpRigidBody_createDynamicRigidMotion(int mode, const S00cb4230_Vec4* p40, const S00cb4230_Quat* p80, float fret,
                          const InertiaTensor* out, const S00cb4230_Vec4* p90, float f0, float f1, MotionBase* motion);
void __cdecl UpdateRotationInterpolation(float f, S00cb4230_MotionStateData* p);

// Switches the object's motion state to the requested mode, copying or constructing the appropriate MotionBase and updating collidable motion state.
// @fnv 0x00cb4230
// src: HAVOK_LIB 0x00cb4230
void __cdecl hkpWorldOperationUtil_replaceMotionObject(ThisObj* self, hkpMotion::MotionType mode, MotionFlag31 flagA, MotionFlag31 flagB, hkpWorld* node)
{
    if (flagA)
    {
        if (!flagB)
        {
            MotionBase* motion = self->getMotion();
            MotionState* pState = motion->m_118;
            motion->v25(pState);
            pState->m_0a = 0;
            pState->m_0c = 0;
            self->setQualityType(hkpCollidableQualityType(motion->m_11c));
            S00cb4230_String::memCpy16NonEmpty(&self->m_pMotionState, pState, sizeof(MotionState) >> 4);
            hkString_memSet(S00cb4230_AddByteOffset(&self->m_pMotionState, sizeof(MotionState)), 0, 0);
            pState->FUN_00c905b0();
            self->UpdateBoundingVolume(node, self->getCollidable()->getShape());
        }

        if (self->m_pMotionState.getType() == mode || mode == hkpMotion::MOTION_DYNAMIC)
        {
        }
        else
        {
            MotionState localState;
            S00cb4230_String::memCpy16NonEmpty(&localState, &self->m_pMotionState, sizeof(MotionState) >> 4);
            InertiaTensor inertiaTensor;
            MotionBase* pMotionBase = &self->m_pMotionState;
            pMotionBase->GetInverseScaleMatrix(inertiaTensor);
            S00cb4230_MotionStateData* pStateData = localState.GetMotionState();
            float fRestitution = pStateData->m_fRestitution;
            float j = pStateData->m_fSurfaceFriction;
            hkpRigidBody_createDynamicRigidMotion(mode, &localState.getPosition(), &localState.getRotation(), localState.FUN_00c86430(),
                         &inertiaTensor, &localState.getCenterOfMassLocal(), j, fRestitution, &self->m_pMotionState);
            localState.getMotionStateAndVelocitiesAndDeactivationType(pMotionBase);
            pMotionBase->setLinearDamping(localState.getLinearDamping());
            pMotionBase->setAngularDamping(localState.getAngularDamping());
            localState.FUN_00d1dff0();
            goto e0;
        }
    }
    else
    {
        MotionBase* pObj;
        MotionState localState;
        S00cb4230_String::memCpy16NonEmpty(&localState, &self->m_pMotionState, sizeof(MotionState) >> 4);
        if (mode == hkpMotion::MOTION_FIXED)
        {
            pObj = new (&self->m_pMotionState) BoxMotion(self->getPosition(), self->getRotation());
            pObj->m_kMotionState.hkMotionState_Copy(&localState.m_kMotionState);
            pObj->m_09 = localState.m_09;
            float c = localState.GetMotionState()->getSweptTransform().getInvDeltaTime();
            if (c != 0.0f)
            {
                UpdateRotationInterpolation(node ? node->hkpWorld_getCurrentTime()
                                                 : 1.0f / c +
                                                       localState.GetMotionState()->getSweptTransform().getBaseTime(),
                                            &pObj->m_kMotionState);
            }
        }
        else
        {
            pObj = new (&self->m_pMotionState) S00cb4230_Keyframed(self->getPosition(), self->getRotation());
            localState.getMotionStateAndVelocitiesAndDeactivationType(pObj);
        }

        if (flagB)
        {
            MotionState* cnt = new MotionState();
            unsigned short GetAllocationSize = cnt->m_04;
            S00cb4230_String::memCpy16NonEmpty(cnt, &localState, sizeof(MotionState) >> 4);
            cnt->m_04 = GetAllocationSize;
            cnt->m_06 = 1;
            pObj->m_118 = cnt;
            pObj->m_11c = (short)self->getCollidable()->getQualityType();
            self->UpdateBoundingVolume(node, self->getCollidable()->getShape());
        }
        else
        {
            MotionBase* old = &localState;
            pObj->v27(old->m_118);
            pObj->m_11c = old->m_11c;
        }
        self->m_a4 = 0;
        self->setQualityType(hkpCollidableQualityType(mode != hkpMotion::MOTION_FIXED));
        localState.FUN_00d1dff0();
    }
e0:
    self->m_kCollidable.setMotionState(self->getRigidMotion()->GetMotionState());
    if ((bool)node)
    {
        self->getMotion()->SetFlagBits((unsigned char)node->pad1C8[0x13d], (unsigned char)node->pad1C8[0x13e],
                                       (unsigned char)node->pad1C8[0x13f]);
    }
}


union MergeListArg
{
    Cb4890_ElemArray* value;
};
static __forceinline void tallyActive(Cb4890_RemapTable* remap_, Cb4890_ElemArray*& list, int n,
                                      Cb4890_LocalBuffer<int>& map, Cb4890_LocalBuffer<int>& cnt, hkpWorld* owner,
                                      Cb4890_ElemArray* const volatile& home) throw()
{
    for (int i = 0; i < list->m_iElementCount; i++, list = home)
    {
        hkpEntity* e = list->m_data[i];
        int idx = remap_->m_entries->m_data[i];
        int a = Dec(e->m_pMotionState.m_ausDeactivationNumInactiveFrames[1], reinterpret_cast<unsigned char&>(owner->pad1C8[0x13e]));
        int b = Dec(e->m_pMotionState.m_ausDeactivationNumInactiveFrames[0], reinterpret_cast<unsigned char&>(owner->pad1C8[0x13d]));
        int am = a & 0x7f;
        int bm = b & 0x7f;
        int mx = (bm > am) ? bm : am;
        if (mx <= 5)
            map[idx] = 1;
        int w = (int)e->m_eSmallArraySerializeOverrideType.m_iElementCount;
        if (w < 1)
            w = 1;
        cnt[idx] += w;
    }
}

static __forceinline void tallyAll(Cb4890_RemapTable* remap_, Cb4890_ElemArray* list, int n,
                                   Cb4890_LocalBuffer<int>& map, Cb4890_LocalBuffer<int>& cnt) throw()
{
    for (int i = 0; i < list->m_iElementCount; i++)
    {
        hkpEntity* e = list->m_data[i];
        int idx = remap_->m_entries->m_data[i];
        map[idx] = 1;
        int w = (int)e->m_eSmallArraySerializeOverrideType.m_iElementCount;
        if (w < 1)
            w = 1;
        cnt[idx] += w;
    }
}
// Tallies element weights per remap index and packs them into slots bounded by the desired island size.
// @fnv 0x00cb49e0
// src: HAVOK_LIB 0x00cb49e0
void mergeSmallSubgroups(hkpWorld* owner, int remap_, MergeListArg listArg, Cb4890_IntArray* src, Cb4890_CharArray* out)
{
    Cb4890_ElemArray* list = listArg.value;
    int n = src->m_iElementCount;
    Cb4890_LocalBuffer<int> cnt(n);
    Cb4890_ElemArray* activeList = list;
    Cb4890_LocalBuffer<int> map(n);

    for (int i = 0; i < n; i++)
    {
        map[i] = 0;
        cnt[i] = 0;
    }

    if (owner->m_bWantDeactivation.m_cBooleanValue)
        tallyActive((Cb4890_RemapTable*)remap_, activeList, n, map, cnt, owner, listArg.value);
    else
        tallyAll((Cb4890_RemapTable*)remap_, list, n, map, cnt);

    for (int k = 0; k < n; k++)
    {
        if (map[k] == 0)
            cnt[k] = -1;
    }

    int pos = 0;
    int* pMap = map.m_p;
    for (int k = 0; k < n; k++)
    {
        int v = cnt[k];
        if (v == -2)
            continue;
        int p = pos++;
        out->m_data[p] = 0;
        pMap[k] = p;
        if (v < 0)
            continue;
        for (int j = k + 1; j < n; j++)
        {
            if (v + 10 >= reinterpret_cast<int&>(owner->m_uiMinDesiredIslandSize))
                break;
            int w = cnt[j];
            if (w < 0)
                continue;
            if (v + w >= reinterpret_cast<int&>(owner->m_uiMinDesiredIslandSize))
                continue;
            out->m_data[p] = 1;
            pMap[j] = p;
            v += w;
            cnt[j] = -2;
        }
    }

    ((Cb4890_RemapTable*)(*(volatile int*)&remap_))->RemapAndAccumulate(map, pos, src);
}

namespace fnv_00cb5000 {
extern "C" void _ReadWriteBarrier(void);
struct FUN_00cb5000_obj
{
    void Refresh();
};

struct Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pAllocator;
};

Holder* __cdecl hkMemoryRouter_getInstance();
void __cdecl ResizeAudioStream(void* apAllocator, void* apVector, unsigned int auiElemSize);
void __cdecl hkpWorldOperationUtil_removeConstraintImmediately(int aCtx, int aObj, int aFlag);

struct PtrVec
{
    int* m_pData;
    unsigned int m_uCount;
    unsigned int m_uCapFlags;
};

struct Entry48
{
    FUN_00cb5000_obj* m_pEntryObject;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
};

struct OwnerObj
{
    int unk00;
    int unk04;
    int m_iCtx;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    Entry48* m_pEntries;
    unsigned short m_wEntryCount;
    unsigned short unkB2;
    int* m_pPtrs;
    int m_iPtrCount;
};

// Walks owner entries and pointers in reverse, calling Refresh and FUN_00cb3dd0 on each object and appending it to the output vector.
// @fnv 0x00cb5000
// src: HAVOK_LIB 0x00cb5000
void __cdecl hkpWorldOperationUtil_removeAttachedConstraints(OwnerObj* apOwner, PtrVec* apOut)
{
    int ctx = apOwner->m_iCtx;
    int i = (int)apOwner->m_wEntryCount - 1;
    if (i >= 0)
    {
        do
        {
            FUN_00cb5000_obj* pObj = apOwner->m_pEntries[i].m_pEntryObject;
            pObj->Refresh();
            hkpWorldOperationUtil_removeConstraintImmediately(ctx, (int)pObj, 0);
            Holder* pHolder = hkMemoryRouter_getInstance();
            if (apOut->m_uCount == (apOut->m_uCapFlags & 0x3fffffffu))
            {
                ResizeAudioStream(pHolder->m_pAllocator, apOut, 4);
            }
            unsigned int idx = *(unsigned int volatile*)&apOut->m_uCount;
            int* data = apOut->m_pData;
            int* pSlot = &data[idx];
            _ReadWriteBarrier();
            *pSlot = (int)pObj;
            apOut->m_uCount++;
            i--;
        } while (i >= 0);
    }

    i = apOwner->m_iPtrCount - 1;
    if (i >= 0)
    {
        do
        {
            FUN_00cb5000_obj* pObj = (FUN_00cb5000_obj*)apOwner->m_pPtrs[i];
            pObj->Refresh();
            hkpWorldOperationUtil_removeConstraintImmediately(ctx, (int)pObj, 0);
            Holder* pHolder = hkMemoryRouter_getInstance();
            if (apOut->m_uCount == (apOut->m_uCapFlags & 0x3fffffffu))
            {
                ResizeAudioStream(pHolder->m_pAllocator, apOut, 4);
            }
            unsigned int idx = *(unsigned int volatile*)&apOut->m_uCount;
            int* data = apOut->m_pData;
            int* pSlot = &data[idx];
            _ReadWriteBarrier();
            *pSlot = (int)pObj;
            apOut->m_uCount++;
            i--;
        } while (i >= 0);
    }
}
}  // namespace fnv_00cb5000

struct S00cb3ee0_Entry
{
    int item;
    char* obj;
};

struct S00cb3ee0_Holder
{
    S00cb3ee0_Entry* entries;
    int count;
};

struct S00cb3ee0_Sub
{
    S00cb3ee0_Holder* hkpLinkedCollidable_getCollisionEntriesDeterministicUnchecked_00d081e0();
};

int PickIslandByValue(int a, int b, int c);
void CloneRecord(int a, int b);
void _hkAgentNnMachine_InternalDeallocateEntry(int a, int b);

// For each entry, calls FUN_00cfeca0 and FUN_00cfe020 if its owner byte at +0xe8 is 5, or if mode is 5 and PickIslandByValue returns motion+0xcc.
// @fnv 0x00cb3ee0
// src: HAVOK_LIB 0x00cb3ee0
void hkpWorldOperationUtil_removeAttachedAgentsConnectingTheEntityAndAFixedPartnerEntityPlus(void* m, MotionObj* motion, void* w, int mode)
{
    int a1 = (int)m;
    char* a2 = (char*)motion;
    int a3 = (int)w;
    int a4 = mode;
    S00cb3ee0_Holder* h = ((S00cb3ee0_Sub*)((char*)a2 + 0x10))->hkpLinkedCollidable_getCollisionEntriesDeterministicUnchecked_00d081e0();
    int i = 0;
    if (h->count > 0)
    {
        do
        {
            S00cb3ee0_Entry* e = &h->entries[i];
            char* obj = e->obj;
            char* esi = obj + (signed char)obj[0x10];
            if (*(unsigned char*)(esi + 0xe8) == 5)
            {
                int item = e->item;
                CloneRecord(a3, item);
                _hkAgentNnMachine_InternalDeallocateEntry(a1, item);
            }
            else if (a4 == 5)
            {
                if (PickIslandByValue(e->item, *(int*)(a2 + 0xcc), *(int*)(esi + 0xcc)) == *(int*)(a2 + 0xcc))
                {
                    int item = e->item;
                    CloneRecord(*(int*)(esi + 0xcc) + 0x58, item);
                    _hkAgentNnMachine_InternalDeallocateEntry(a1, item);
                }
            }
            ++i;
        } while (i < h->count);
    }
}


template <class T>
static __forceinline void S55Array_popBack(hkArrayBase<T>& self);

template <class T>
static __forceinline void S55Array_GrowArrayCapacity(hkArrayBase<T>& self, hkMemoryAllocator& a, int n);

template <class T>
static __forceinline void S55Array__setSize(hkArrayBase<T>& self, hkMemoryAllocator& a, int n);

template <class T>
static __forceinline void S55Array_popBack(hkArrayBase<T>& self)
{
        self.m_iElementCount--;
    }

template <class T>
static __forceinline void S55Array_GrowArrayCapacity(hkArrayBase<T>& self, hkMemoryAllocator& a, int n)
{

    const int capacity = self.getCapacity();

    if (capacity < n)
    {

        int cap2 = 2 * capacity;

        int newSize = (n < cap2) ? cap2 : n;

        hkArrayUtil__reserve(a, (&self), newSize, sizeof(T));
    }
}

template <class T>
static __forceinline void S55Array__setSize(hkArrayBase<T>& self, hkMemoryAllocator& a, int n)
{
        S55Array_GrowArrayCapacity(self, a, n);
        self.m_iElementCount = n;
    }

void __cdecl hkArrayUtil__reserve(hkMemoryAllocator& a, void* array, int reqCapacity, int sizeElem);



// The shared world header does not yet declare FUN_00c910b0().
struct S55Owner
{

    int unk00;

    int unk04;

    int unk08;

    int unk0c;

    int unk10;

    int unk14;

    int unk18;

    int unk1c;

    int unk20;

    int unk24;

    hkArrayBase<hkpSimulationIsland*> m_28;

    int unk34;

    int unk38;

    int unk3c;

    hkArrayBase<hkpSimulationIsland*> m_40;

    int unk4c;

    int unk50;

    int unk54;

    int unk58;

    int unk5c;

    int unk60;

    int unk64;

    int unk68;

    int unk6c;

    int unk70;

    int unk74;

    int unk78;

    int unk7c;

    int unk80;

    int unk84;

    int unk88;

    int unk8c;

    int unk90;

    int unk94;

    int unk98;

    int unk9c;

    int unka0;

    int unka4;

    int unka8;

    int unkac;

    int unkb0;

    int m_b4;

    int unkb8;

    int unkbc;

    int unkc0;

    int unkc4;

    unsigned char m_c8;

    void __thiscall nullsub_6();
};

void __cdecl hkpWorldOperationUtil_internalActivateIsland(S55Owner* owner, hkpSimulationIsland* item, hkBool b);

void __cdecl hkpWorldOperationUtil_internalDeactivateIsland(S55Owner* owner, hkpSimulationIsland* item);

extern "C" void __cdecl hkpWorldOperationUtil_mergeIslands(S55Owner* owner, ObjB* first, ObjB* second);

// Sorts owner->m_40, then drains it by popping items, compacting their m_38 arrays, and applying state changes via FUN_00cb5100, FUN_00cb5310, or FUN_00cb5570.
// @fnv 0x00cb55d0
// src: HAVOK_LIB 0x00cb55d0
void __cdecl hkpWorldOperationUtil_cleanupDirtyIslands(S55Owner* owner)

{

    if (owner->m_40.m_iElementCount == 0)

        return;

    if (owner->m_40.m_iElementCount > 1)

        hkAlgorithm_quickSortRecursive_hkFreeList_Block_hkBool_cdecl_hkFreeList_Block_const_hkFreeList_Block_const((S_00dd7d00_Item**)owner->m_40.m_data, 0, owner->m_40.m_iElementCount - 1,

                     (S_00dd7d00_Less)worldOperationUtil_less_hkSimulationIslandPtr);

    for (int i = 0; i < owner->m_40.m_iElementCount; i++)
    {

        hkpSimulationIsland* it = owner->m_40.m_data[i];

        if (it)

            it->dirtyIndex = (unsigned short)i;
    }

    hkpSimulationIsland* it;

    int w;

    while (owner->m_40.m_iElementCount)
    {

        w = -1;

        it = owner->m_40.back();

        owner->m_40.m_iElementCount += w;

        if (!it)

            continue;

        it->dirtyIndex = 0xffff;

        if (it->flags25 & 0x30)
        {

            hkArrayBase<hkpAction*>& arr = reinterpret_cast<hkArrayBase<hkpAction*>&>(it->actions);

            int k = 0;

            for (; k < arr.m_iElementCount; k++)
            {

                if (arr.m_data[k] == 0)
                {

                    w = k;

                    k++;

                    break;
                }
            }

            int d = w;

            for (; k < arr.m_iElementCount; k++)
            {

                if (arr.m_data[k] != 0)

                    arr.m_data[d++] = arr.m_data[k];
            }

            if (d != -1)

                S55Array__setSize(arr, hkMemoryRouter_getInstance()->heap(), d);

            it->flags25 &= 0xcf;
        }

        unsigned char f = it->flags26;

        unsigned char newState = (f >> 2) & 3;

        if (newState != (f & 3))
        {

            if (newState)

                hkpWorldOperationUtil_internalActivateIsland(owner, it, true);

            else

                hkpWorldOperationUtil_internalDeactivateIsland(owner, it);
        }
        else if (f & 0x30)
        {

            it->flags26 = f & 0xcf;

            int n = it->entities.count;

            if (n <= it->unk1C)

                n = it->unk1C;

            hkpSimulationIsland* r =
                (hkpSimulationIsland*)FindItemForThreshold((hkpWorld*)owner, (List_cb3d10*)&owner->m_28, n, (hkpSimulationIsland*)it);

            if (r)

                hkpWorldOperationUtil_mergeIslands(owner, *reinterpret_cast<ObjB**>(it->entities.data), *reinterpret_cast<ObjB**>(r->entities.data));
        }
    }

    owner->nullsub_6();
}

extern "C" void _ReadWriteBarrier();

namespace fnv_00cb4640 {
// The shared island header lacks the entity-add method and world-taking constructor below.
struct TaskNode
{
    int unk00;
    unsigned short size04;
    unsigned short unk06;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    short index20;
    unsigned short unk22;
    unsigned char id24;
    unsigned char flags25;
    union
    {
        unsigned char flags26;
        struct
        {
            unsigned char low26 : 2;
            unsigned char high26 : 2;
            unsigned char upper26 : 4;
        };
    };
    unsigned char unk27;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    void hkpSimulationIsland_internalAddEntity(hkpEntity* arg);
    TaskNode* FUN_00d07830(hkpWorld* arg);
};
struct TaskList
{
    TaskNode** data;
    union
    {
        int count;
        struct
        {
            short countLow;
            short countHigh;
        };
    };
    int capacity;
};

struct TaskHeap
{
    virtual void slot0();
    virtual TaskNode* alloc(int size);
};

// Sets b's parent to a, then calls FUN_00d07420 with b on a node of a: node20 if b's type is 5, else one found or allocated in list28/list34 or list28's first.
// @fnv 0x00cb4640
// src: HAVOK_LIB 0x00cb4640
void __cdecl hkpWorldOperationUtil_addEntitySI(hkpWorld* apParent, hkpEntity* apChild, int mode)
{
    apChild->m_pOwningWorld = apParent;
    if (reinterpret_cast<unsigned char&>(apChild->m_pMotionState.m_type) == 5)
    {
        static_cast<TaskNode*>(apParent->m_pFixedIsland)->hkpSimulationIsland_internalAddEntity(apChild);
        return;
    }
    TaskNode* node;
    if (apParent->m_bWantSimulationIslands.m_cBooleanValue)
    {
        bool active = mode == 1;
        TaskList* list;
        if (active)
        {
            list = reinterpret_cast<TaskList*>(&apParent->m_kActiveSimulationIslands);
            TaskNode* found = (TaskNode*)::FindItemForThreshold((::hkpWorld*)apParent, (::List_cb3d10*)list, 4, 0);
            if (found)
            {
                found->hkpSimulationIsland_internalAddEntity(apChild);
                return;
            }
        }
        else
        {
            list = reinterpret_cast<TaskList*>(&apParent->m_kInactiveSimulationIslands);
        }
        ::S_00c6aca0_Router* router = ::hkMemoryRouter_getInstance();
        TaskHeap* heap = (TaskHeap*)router->m10;
        TaskNode* raw = heap->alloc(0x6c);
        raw->size04 = 0x6c;
        node = raw->FUN_00d07830(apParent);
        node->high26 = active;
        node->low26 = active;
        node->index20 = (short)list->count;
        node->id24 = (unsigned char)node->index20;
        router = ::hkMemoryRouter_getInstance();
        if (list->count == (list->capacity & 0x3fffffff))
            ::fnv_00cb5480::ResizeAudioStream(router->m10, list, 4);
        TaskNode** slot = list->data + list->count;
        _ReadWriteBarrier();
        *slot = node;
        ++list->count;
    }
    else
    {
        node = static_cast<TaskNode*>(apParent->m_kActiveSimulationIslands.m_data[0]);
    }
    node->hkpSimulationIsland_internalAddEntity(apChild);
    node->id24 = static_cast<unsigned char>(apChild->m_uiUniqueId);
}

}


template <class T, class A> __forceinline hkArray<T, A>::~hkArray()
{
    __if_exists(A::destroy) { A::destroy(*this); }
    __if_not_exists(A::destroy) { clearAndDeallocate(); }
}
