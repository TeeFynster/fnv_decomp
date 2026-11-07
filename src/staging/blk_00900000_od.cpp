
// src/staging/blk_00900000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
// BSSpinLockUnlock_blk_00900000_od: local type (was include/BSSpinLockUnlock.h, which had no evidence of one real class); its methods are 0x0040fba0 BSSpinLock::Unlock, 0x0040fbf0 BSSpinLock::Lock
class BSSpinLockUnlock_blk_00900000_od
{
public:
    void Lock(const char*);
    void Unlock();
};
#include "../../include/PathingAvoidNode.h"

extern int DAT_01088438;

struct FUN_00905670_Class
{
    void __thiscall SetVTable();
};

// @fnv 0x00905670
void __thiscall FUN_00905670_Class::SetVTable()
{
    *(int*)this = (int)&DAT_01088438;
}

extern int DAT_010159d4;

struct GlobalObject_00869f00
{
    int* m_p;
    void Clear(bool);
    void InitFromGlobal();
};

void GlobalObject_00869f00::Clear(bool)
{}

// @fnv 0x00905910
void GlobalObject_00869f00::InitFromGlobal()
{
    m_p = &DAT_010159d4;
    Clear(true);
}

extern "C" void __cdecl FUN_009059f0();
extern void* DAT_01088418;

struct FUN_00905990_Class
{
    void** vtbl;
    int field_4;
    void FUN_009059f0();
    FUN_00905990_Class();
};

// Calls FUN_009059f0, sets the vtable pointer to DAT_01088418 and initializes field_4 to 0.
// @fnv 0x00905990
FUN_00905990_Class::FUN_00905990_Class()
{
    FUN_009059f0();
    vtbl = &DAT_01088418;
    field_4 = 0;
}

extern int DAT_01088438;

struct FUN_009059f0_Class
{
    int* pVftable;
    FUN_009059f0_Class();
};

// @fnv 0x009059f0
FUN_009059f0_Class::FUN_009059f0_Class()
{
    pVftable = (int*)&DAT_01088438;
}

namespace p07 {
struct DelStandIn
{
    void* Destroy(unsigned int);
    void* Destroy_Thunk();
};
}

// @fnv 0x00905ae0
// src: GUESS 0x00905ae0 (confidence: medium)
void* p07::DelStandIn::Destroy_Thunk()
{
    return Destroy(0);
}

extern "C" void __cdecl DAT_01088640();

struct FUN_00906110_Class
{
    void __thiscall SetVtableAndProcessState_00906110();
};

// @fnv 0x00906110
// src: GUESS 0x00906110 (confidence: low)
void __thiscall FUN_00906110_Class::SetVtableAndProcessState_00906110()
{
    *reinterpret_cast<void**>(this) = &DAT_01088640;
}

extern int DAT_01088fd4;
struct FUN_00913810_t
{
    void FUN_00913810(int a);
};
struct FUN_009137b0_t
{
    int* m;
    FUN_009137b0_t* Construct(int a);
};
// Calls FUN_00913810 with a, sets m to point at DAT_01088fd4, and returns this.
// @fnv 0x009137b0
FUN_009137b0_t* FUN_009137b0_t::Construct(int a)
{
    ((FUN_00913810_t*)this)->FUN_00913810(a);
    m = &DAT_01088fd4;
    return this;
}

struct FUN_00913980_StandIn
{
    void UpdateFields_009138e0();
    void* FUN_00913980(unsigned int flags);
};

// Calls FUN_009138e0, then deletes this if bit 0 of flags is set, and returns this.
// @fnv 0x00913980
void* FUN_00913980_StandIn::FUN_00913980(unsigned int flags)
{
    UpdateFields_009138e0();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct QHeadPtr
{
    void dtor();
};
struct FUN_009157c0
{
    QHeadPtr m;
    void Method();
};
// @fnv 0x009157c0
void FUN_009157c0::Method()
{
    ((QHeadPtr*)((char*)this + 0x14))->dtor();
}

struct FUN_00905a10_StandIn
{
    unsigned int GetNextIndex();
};
struct BSSimpleArray_PathingAvoidNode_1024
{
    void InitializeItems(PathingAvoidNode* pDest, unsigned int count);
};
struct FUN_00905450_StandIn
{
    int m_iArrayLength;
    PathingAvoidNode* m_pData;
    unsigned int GetNextIndex();
    unsigned int AppendNode(PathingAvoidNode* pSrc);
};
// Appends a copy of the given node to the array and returns the index it was stored at.
// @fnv 0x00905450
unsigned int FUN_00905450_StandIn::AppendNode(PathingAvoidNode* apNode)
{
    unsigned int count = GetNextIndex();
    ((BSSimpleArray_PathingAvoidNode_1024*)this)->InitializeItems(&m_pData[count], 1);
    *(PathingAvoidNode*)&m_pData[count] = *apNode;
    return count;
}

int __cdecl BSAtomicCompareExchange(long volatile*, long, long);
// Exe 0x00905510: unit-local Interface view; declarations and layout are preserved.
struct BlkInterfaceView
{
    static void __cdecl PrintDebugMessage(void);
};
struct FUN_00905510_Class
{
    void** vtbl;
    char LockAndCall(int a);
};
// Spins until the lock at this+1 is acquired, calls the virtual method at vtbl[6] with a, then releases the lock and returns its result.
// @fnv 0x00905510
char FUN_00905510_Class::LockAndCall(int aiArg)
{
    char r;
    while (true)
    {
        if (BSAtomicCompareExchange((long volatile*)(this + 1), 0, 1) == 0)
        {
            BlkInterfaceView::PrintDebugMessage();
            r = ((char(__thiscall*)(void*, int))vtbl[6])(this, aiArg);
            BlkInterfaceView::PrintDebugMessage();
            BSAtomicCompareExchange((long volatile*)(this + 1), 1, 0);
            break;
        }
    }
    return r;
}

struct FUN_00905690_Class
{
    void __thiscall SetVtableAndProcessState_00905650();
    void* __thiscall FUN_00905690(unsigned int flags);
};

// @fnv 0x00905690
void* FUN_00905690_Class::FUN_00905690(unsigned int flags)
{
    SetVtableAndProcessState_00905650();
    if (flags & 1)
        operator delete(this);
    return this;
}

void __cdecl Deallocate(void*);

struct FUN_009056c0_Class
{
    void __thiscall SetVTable();
    void* __thiscall FUN_009056c0(unsigned int flags);
};

// @fnv 0x009056c0
void* __thiscall FUN_009056c0_Class::FUN_009056c0(unsigned int flags)
{
    SetVTable();
    if (flags & 1)
        Deallocate(this);
    return this;
}

extern "C" void __cdecl _Deallocate(void*);
struct FUN_009055c0_Class
{
    void __thiscall FUN_009055c0();
    void* __thiscall FUN_00905930(unsigned int flags);
};
// @fnv 0x00905930
void* __thiscall FUN_009055c0_Class::FUN_00905930(unsigned int flags)
{
    FUN_009055c0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_00905960_Class
{
    void* FUN_00905960(unsigned int flags);
};
// @fnv 0x00905960
void* FUN_00905960_Class::FUN_00905960(unsigned int flags)
{
    ((GlobalObject_00869f00*)this)->InitFromGlobal();
    if (flags & 1)
        operator delete(this);
    return this;
}

extern void __cdecl Deallocate(void*);
struct FUN_00906130_Class
{
    void* __thiscall FUN_00906130(unsigned int flags);
};
// Calls FUN_00906110 on this, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00906130
void* FUN_00906130_Class::FUN_00906130(unsigned int flags)
{
    reinterpret_cast<FUN_00906110_Class*>(this)->SetVtableAndProcessState_00906110();
    if (flags & 1)
        Deallocate(this);
    return this;
}

#include "../../include/RecursiveSpinLock.h"
struct FUN_00449f80_Class
{
    void* LockFreeMap_GetInterface_0(void* a, void* b, void* c, bool d);
};
struct FUN_0044d070_Class
{
    bool InsertOrReplace();
};
struct FUN_009063b0_Class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void* m_iThirdValue;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    RecursiveSpinLock m_20;
    bool LockedCall(void* a, void* b, void* c, bool d);
};
// Locks m_20, calls FUN_00449f80 with the arguments, calls InsertOrReplace on the result, unlocks m_20 and returns its bool.
// @fnv 0x009063b0
bool FUN_009063b0_Class::LockedCall(void* apArg1, void* apArg2, void* apArg3, bool d)
{
    m_20.Lock(0);
    bool r = reinterpret_cast<FUN_0044d070_Class*>(
                 reinterpret_cast<FUN_00449f80_Class*>(this)->LockFreeMap_GetInterface_0(apArg1, apArg2, apArg3, d))
                 ->InsertOrReplace();
    m_20.Unlock();
    return r;
}

struct S5460
{
    virtual void v0();
    virtual void* v1(unsigned int);
    virtual void* v2(unsigned int);
    virtual void v3();
    virtual void v4();
    bool BSSimpleArray_NavMeshInfo_1024_ShouldGrow();
    unsigned int BSSimpleArray_NavMeshInfo_1024_GetNewSizeForGrow();
    void* BSSimpleArray_PathingAvoidNode_1024_ReallocateBuffer(unsigned int a, unsigned int b);
    void* m_iWordAt04;
    unsigned int m_8;
    unsigned int m_iThirdValue;
    unsigned int GetNextIndex();
};
// @fnv 0x00905a10
unsigned int S5460::GetNextIndex()
{
    if (BSSimpleArray_NavMeshInfo_1024_ShouldGrow())
    {
        if (m_iThirdValue == 0)
        {
            unsigned int count = 4;
            m_iWordAt04 = v1(count);
            m_iThirdValue = count;
        }
        else
        {
            unsigned int idx = BSSimpleArray_NavMeshInfo_1024_GetNewSizeForGrow();
            BSSimpleArray_PathingAvoidNode_1024_ReallocateBuffer(idx, m_8);
            m_iThirdValue = idx;
        }
    }
    ++m_8;
    return m_8 - 1;
}

struct _Base_00441d20
{
    ~_Base_00441d20();
};
struct FUN_00905c30 : _Base_00441d20
{
    ~FUN_00905c30();
};
// @fnv 0x00905c30
FUN_00905c30::~FUN_00905c30()
{}

struct FUN_00906690_t
{
    void* m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    char m_iThirdValue;
    FUN_00906690_t();
};
// @fnv 0x00906690
FUN_00906690_t::FUN_00906690_t()
{
    m_iWordAt00 = (void*)&DAT_01088640;
    m_iWordAt04 = 0;
    m_8 = 0;
    m_iThirdValue = 0;
}

struct FUN_009064e0_Class
{
    void FUN_009064e0();
    void* FUN_009067f0(unsigned int flags);
};

// @fnv 0x009067f0
void* FUN_009064e0_Class::FUN_009067f0(unsigned int flags)
{
    FUN_009064e0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct GlobalObject_009137b0
{
    ~GlobalObject_009137b0();
    void* FUN_009137e0(unsigned int flags);
};
// Runs the destructor, then frees the object with _Deallocate when flags has bit 0 set, and returns the object pointer.
// @fnv 0x009137e0
void* GlobalObject_009137b0::FUN_009137e0(unsigned int flags)
{
    this->GlobalObject_009137b0::~GlobalObject_009137b0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

extern void __cdecl NiFree(void*);
extern int DAT_01088ff4;
struct FUN_009138e0_Class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void UpdateFields_009138e0();
    void FUN_008448e0();
};
// @fnv 0x009138e0
// src: GUESS 0x009138e0 (confidence: low)
void FUN_009138e0_Class::UpdateFields_009138e0()
{
    m_iWordAt00 = (void*)&DAT_01088ff4;
    FUN_008448e0();
    NiFree(m_8);
}

struct FUN_00913950_Class
{
    void* __thiscall UpdateState_00913950(int a);
};

// @fnv 0x00913950
// src: GUESS 0x00913950 (confidence: low)
void* FUN_00913950_Class::UpdateState_00913950(int a)
{
    ((int*)this)[0] = 0;
    ((int*)this)[1] = 0;
    return this;
}

extern void* DAT_01088418;

// @fnv 0x00905650
// src: GUESS 0x00905650 (confidence: low)
void FUN_00905690_Class::SetVtableAndProcessState_00905650()
{
    *reinterpret_cast<int*>(this) = reinterpret_cast<int>(&DAT_01088418);
    reinterpret_cast<FUN_00905670_Class*>(this)->SetVTable();
}

void* __cdecl Memory_ReturnPlacementAddress(unsigned int size, void* heap);

struct SpawnedObject_b9530
{
    char m00[8];
    SpawnedObject_b9530(int a);
    static void* operator new(unsigned int size, void* heap)
    {
        return Memory_ReturnPlacementAddress(size, heap);
    }
    static void operator delete(void* p, void* heap)
    {}
};

struct FUN_00905b00_cls
{
    char m00[0x14];
    void FUN_00483710();
    void ConstructSpawnedObject(int a);
};

// Calls FUN_00483710, then placement-constructs a SpawnedObject_b9530 at this from a.
// @fnv 0x00905b00
void FUN_00905b00_cls::ConstructSpawnedObject(int a)
{
    FUN_00483710();
    new (this) SpawnedObject_b9530(a);
}

struct FUN_00906400_Guard
{
    int m_iWordAt00;
    FUN_00906400_Guard(int a, int b, const char* file, int line);
    ~FUN_00906400_Guard();
};

struct FUN_00906400_Sub
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    FUN_00906400_Sub(void* owner, int* p0, int* p1, int* p2);
};

struct FUN_00906400_Owner
{
    int m_iWordAt00;
    int* m_iWordAt04;
    FUN_00906400_Sub* LockFreeMap_AllocateInterface(int a);
};

// @fnv 0x00906400
// src: COMMUNITY 0x00906400
FUN_00906400_Sub* FUN_00906400_Owner::LockFreeMap_AllocateInterface(int aiIndex)
{
    FUN_00906400_Guard guard(6, 1, "d:\\_fallout3\\platforms\\common\\code\\bsmain\\ThreadSafeStructures.h", 0x18e);
    return new FUN_00906400_Sub(this, &m_iWordAt04[aiIndex * 3], &m_iWordAt04[aiIndex * 3 + 1],
                                &m_iWordAt04[aiIndex * 3 + 2]);
}

struct Request9065
{
    int unk00;
    unsigned int index;
    void* element;
    bool LockFreeMap_char_const_Model_LockFreeMapIterator_GetFinished();
    bool IsFlagSet();
    void FUN_0044de40(bool);
    void FUN_0044de80(bool);
};
struct Iterator9065
{
    bool ProcessEntry();
    bool ProcessEntries_00906c10();
};
struct FUN_00906570_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    RecursiveSpinLock lock;
    Iterator9065* LockFreeMap_GetInterface_0(unsigned int, void**, void*);
    unsigned int FUN_0044ddc0();
    bool AdvanceRequest(Request9065*, void**, void*, bool);
};
// @fnv 0x00906570
bool FUN_00906570_Class::AdvanceRequest(Request9065* request, void** ppOut, void* context, bool repeat)
{
    lock.Lock(0);
    bool success = false;
    if (request->LockFreeMap_char_const_Model_LockFreeMapIterator_GetFinished())
    {
        success = false;
    }
    else
    {
        while (true)
        {
            if (!request->IsFlagSet())
            {
                success = LockFreeMap_GetInterface_0(request->index, &request->element, context)->ProcessEntry();
                request->FUN_0044de40(true);
            }
            else
            {
                success = LockFreeMap_GetInterface_0(request->index, &request->element, context)->ProcessEntries_00906c10();
            }
            if (!success)
            {
                request->index = request->index + 1;
                if (request->index >= FUN_0044ddc0())
                    request->FUN_0044de80(true);
                else if (repeat)
                {
                    request->FUN_0044de40(false);
                    continue;
                }
            }
            else
            {
                *ppOut = request->element;
            }
            break;
        }
    }
    lock.Unlock();
    return success;
}

extern "C" void* __cdecl memset(void* pvDest, int iValue, unsigned int ItemUpdateArray);
void* NiMalloc(unsigned int uiSize);

class NiTMapItem913;

class FUN_00913810
{
  public:
    FUN_00913810(unsigned int uiHashSize);
    virtual ~FUN_00913810();

    unsigned int m_uiHashSize;
    NiTMapItem913** m_ppkHashTable;
    unsigned int m_uiCount;
};

// Initializes the hash table: stores the hash size, zeroes the count, allocates the bucket array and clears it.
// @fnv 0x00913810
FUN_00913810::FUN_00913810(unsigned int uiHashSize)
{
    m_uiHashSize = uiHashSize;
    m_uiCount = 0;

    unsigned int uiSize = sizeof(NiTMapItem913*) * m_uiHashSize;
    m_ppkHashTable = (NiTMapItem913**)NiMalloc(uiSize);
    memset(m_ppkHashTable, 0, m_uiHashSize * sizeof(NiTMapItem913*));
}

// FUN_00913910 : thiscall, 1 stack argument (a pointer to an out-record).
// Builds a small two-dword local with an external constructor, copies it into
// the record and then hands the record to a helper that lives in the
// sub-object at offset 0x0c of this.

struct LocalPair
{
    int m_kPointA;
    int m_kPointB;
    void __thiscall UpdateState_00913950(int a);
};

struct OutRecord
{
    int unk00;
    int unk04;
    LocalPair m_pair;
};

struct SubObject
{
    void __thiscall FreeMemory(OutRecord* pOut);
};

class FUN_00913910_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    SubObject m_sub;
    void ResetPairAndFreeEntry(OutRecord* pOut);
};

// Initializes a LocalPair with 0, copies it into pOut->m_pair, then calls m_sub.FreeMemory(pOut).
// @fnv 0x00913910
// src: GUESS 0x00913910 (confidence: medium)
void FUN_00913910_cls::ResetPairAndFreeEntry(OutRecord* pOut)
{
    LocalPair local;
    local.UpdateState_00913950(0);
    pOut->m_pair = local;
    m_sub.FreeMemory(pOut);
}

struct QHeadPtrDest
{
    QHeadPtrDest& Assign(const QHeadPtr&);
    void* AssignTaskReference(void*);
};

struct SubItem
{
    void* unk0;
    QHeadPtr headPtr;
    bool FUN_0044df20();
};

struct Member14_18
{
    int unk;
    int ClearLowBit();
    SubItem* ClearLowBit_Thunk();
};

struct OwnerClass
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12(void*, void**);
};

void ProgramFlow();

struct TargetClass
{
    OwnerClass* field_0;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    Member14_18 m_14;
    Member14_18 m_18;

    bool ProcessNode(int a, void* b);
    void LockFreeMap_LockFreeMapInterface_ClearReferencedNodes();

    bool ProcessEntries_00906c10(int a, void** b, QHeadPtrDest* c);
};

// @fnv 0x00906c10
// src: GUESS 0x00906c10 (confidence: low)
bool TargetClass::ProcessEntries_00906c10(int a, void** b, QHeadPtrDest* apHeadDest)
{
    bool bResult = false;
    while (true)
    {
        bResult = this->ProcessNode(a, *b);
        if (bResult)
        {
            if (this->m_18.ClearLowBit())
            {
                if (this->m_18.ClearLowBit_Thunk()->FUN_0044df20())
                {
                    continue;
                }
                this->field_0->v12(this->m_18.ClearLowBit_Thunk()->unk0, b);
                apHeadDest->Assign(this->m_18.ClearLowBit_Thunk()->headPtr);
                bResult = true;
                ProgramFlow();
                if (this->m_18.ClearLowBit_Thunk()->FUN_0044df20())
                {
                    apHeadDest->AssignTaskReference(0);
                    continue;
                }
                break;
            }
            else
            {
                bResult = false;
                break;
            }
        }
        else
        {
            if (this->m_14.ClearLowBit())
            {
                if (this->m_14.ClearLowBit_Thunk()->FUN_0044df20())
                {
                    continue;
                }
                this->field_0->v12(this->m_14.ClearLowBit_Thunk()->unk0, b);
                apHeadDest->Assign(this->m_14.ClearLowBit_Thunk()->headPtr);
                bResult = true;
                ProgramFlow();
                if (this->m_14.ClearLowBit_Thunk()->FUN_0044df20())
                {
                    apHeadDest->AssignTaskReference(0);
                    continue;
                }
                break;
            }
            else
            {
                bResult = false;
                break;
            }
        }
    }
    this->LockFreeMap_LockFreeMapInterface_ClearReferencedNodes();
    return bResult;
}

struct FUN_00528bb0_Class
{
    bool LockFreeMap_TESObjectREFR_NiPointer_QueuedReference_LockFreeMapInterface_RemoveAt();
};

struct FUN_009062e0_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    BSSpinLockUnlock_blk_00900000_od lock;
    void* LockFreeMap_GetInterface_0(void*);
    bool LockFreeMap_T_Key_NiPointer_IOTask_RemoveAt(void* a);
};

// Locks the spin lock, calls FUN_00528bb0 on the object returned by FUN_00449f80(a), unlocks, and returns the result.
// @fnv 0x009062e0
// src: COMMUNITY 0x009062e0
bool FUN_009062e0_Class::LockFreeMap_T_Key_NiPointer_IOTask_RemoveAt(void* a)
{
    lock.Lock(0);
    bool r = ((FUN_00528bb0_Class*)LockFreeMap_GetInterface_0(a))->LockFreeMap_TESObjectREFR_NiPointer_QueuedReference_LockFreeMapInterface_RemoveAt();
    lock.Unlock();
    return r;
}

struct FUN_00528cb0_Guard
{
    int value;
    FUN_00528cb0_Guard(int value);
    ~FUN_00528cb0_Guard();
    unsigned int Modelloader_GetReferencedThis(int flag);
};
struct FUN_0044ac40_Service
{
    void __thiscall BSTaskManager_CancelTask(unsigned int value);
};
extern FUN_0044ac40_Service* DAT_01202d98;
struct FUN_00906050_Class
{
    virtual void v0();
    virtual void v1();
    virtual unsigned char v2(int value, FUN_00528cb0_Guard* guard);
    void __thiscall CallVirtual5(int value);
    void __thiscall LipSyncBackgroundManager_CancelLipFile(int value);
};
// Creates a guard, calls v2 with the value and guard; if it succeeds, calls CallVirtual5 and passes the guard's flag result to DAT_01202d98.
// @fnv 0x00906050
// src: COMMUNITY 0x00906050
void FUN_00906050_Class::LipSyncBackgroundManager_CancelLipFile(int value)
{
    FUN_00528cb0_Guard guard(0);
    if (v2(value, &guard))
    {
        CallVirtual5(value);
        DAT_01202d98->BSTaskManager_CancelTask(guard.Modelloader_GetReferencedThis(0));
    }
}

class MapBase913880
{
  public:
    virtual ~MapBase913880();
    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
    void RemoveAll();
};
class FUN_00913880 : public MapBase913880
{
  public:
    virtual ~FUN_00913880();
};

// Removes all entries from the hash table before the object is destroyed.
// @fnv 0x00913880
FUN_00913880::~FUN_00913880()
{
    RemoveAll();
}

void __cdecl FormHeapFreeAndLog_00401030(void* p);

struct _Base_009064e0
{
    virtual void unk00();
    ~_Base_009064e0();
};

struct FUN_009064e0 : _Base_009064e0
{
    void unk04(int flag);
    void* m_iWordAt04;
    int m_8;
    void* m_iThirdValue;
    ~FUN_009064e0();
};

// @fnv 0x009064e0
FUN_009064e0::~FUN_009064e0()
{
    unk04(1);
    void* a = m_iThirdValue;
    FormHeapFreeAndLog_00401030(a);
    void* b = m_iWordAt04;
    FormHeapFreeAndLog_00401030(b);
}
