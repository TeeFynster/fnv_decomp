#include "../../include/BSSimpleArray.h"
#include "../../include/MemoryManager.h"
#include "../../include/NiPoint3.h"
#include "../../include/PathingLocation.h"
#include "../../include/BSScrapArray.h"
#include "../../include/PathingAvoidNode.h"
#include "../../include/PathBuilderDetailedPathInfos.h"
#include "../../include/PathingGraphNode.h"

// src/unmapped/bssimplearray_ob1_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/unmapped/bssimplearray.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern int DAT_0106b8a0;
struct FUN_006cf9d0
{
    int* vfptr;
    void BSSimpleArray_WeaponData_1024_InitialSetup(unsigned int maxSize, unsigned int growBy);
    FUN_006cf9d0(unsigned int maxSize, unsigned int growBy);
};
extern int DAT_0106b91c;
struct FUN_006cf180
{
    void* vfptr;
    void ResizeAndConstruct(int a, int b);
    FUN_006cf180();
};
struct FUN_006cf250_Class
{
    void* __thiscall AllocateBuffer(unsigned int count);
};
extern "C" void* __cdecl _Reallocate(void* p, unsigned int size);
struct FUN_006cf280_Class
{
    void* __thiscall _Reallocate_Thunk_006cf280(void* p, unsigned int n);
};
bool AreBytesEqual(const unsigned char* a, const unsigned char* b);
extern int DAT_0106b8c8;
struct Dummy_0061bf20
{
    void BSSimpleArray_NavMeshPOVSearchNode_1024_InitialSetup(int, int);
};
struct FUN_006cf9a0 : Dummy_0061bf20
{
    int* vfptr;
    FUN_006cf9a0(int maxSize, int growBy);
};
extern int DAT_0106c9e0;
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct FUN_006cfaa0
{
    int* vfptr;
    void ResetVirtualTableAndClear_006cfaa0();
};
struct FUN_006e91e0_cls
{
    void* __thiscall AllocateBlock(int count);
};
void* __cdecl _Reallocate(void* p, unsigned int size);
struct FUN_006e9210
{
    void Reallocate(void* p, unsigned int size);
};
extern int DAT_0106d4e8;
struct FUN_006e9230_class
{
    int* vfptr;
    void BSSimpleArray_PathingNode_1024_InitialSetup(int a, int b);
    FUN_006e9230_class();
};
extern int DAT_0106d4e8;
struct PSNodeStub
{
    int* vfptr;
    void FUN_006cf120(bool);
};
struct FUN_006e9260Class : PSNodeStub
{
    void SetVirtualTableAndProcessState_006e9260();
};
void* __cdecl Reallocate(void* p, int size);
struct FUN_006e93f0
{
    void* __thiscall Reallocate_Thunk(void* p, int n);
};
struct PacketNodeRecord
{
    void FUN_006a8500();
};
struct PathingLocationArray
{
    void* m_pBase;
    void* m_pItems;
    unsigned int m_uiCount;
    void ConstructItems(PathingLocation* pItems, unsigned int ItemUpdateArray);
    unsigned int AppendSlot();
    unsigned int FUN_006cf1b0(const PathingLocation& aValue);
};
struct FUN_006cf340 : PathBuilderDetailedPathInfos
{
    virtual ~FUN_006cf340();
};
struct _Mem_20a4
{
    void* vfptr;
    int m_04;
    _Mem_20a4(int, int, int);
    virtual ~_Mem_20a4();
};
struct FUN_006cf440 : _Mem_20a4
{
    int m_08;
    virtual ~FUN_006cf440();
};
struct ParentSpaceNode
{
    bool m_bIsWorldspace;
    void* m_pContainingWorldspace;
    void* m_pReferenceCell;
};
struct ArrHelper
{
    void __thiscall ConstructParentSpaceNodes(ParentSpaceNode* p, unsigned int count);
};
struct S5460
{
    unsigned int __thiscall BSSimpleArray_NiPoint3_1024_AddUninitialized();
};
struct FUN_006cf4c0_Array
{
    ParentSpaceNode* pDummy;
    ParentSpaceNode* pBuffer;
    unsigned int iSize;
    unsigned int BSSimpleArray_ParentSpaceNode_1024_Add(const ParentSpaceNode& aValue);
};
extern int DAT_0106c990;
struct FUN_0069b1d0
{
    virtual ~FUN_0069b1d0();
    void Clear(bool);
};
struct FUN_006cf610 : FUN_0069b1d0
{
    ~FUN_006cf610();
};
struct ScrapHeapBuffer
{
    void* Allocate(unsigned int, unsigned int);
    void Deallocate(void*);
};
// Exe 0x00a0d0c0: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct BssimplearrayOffset08View
{
    unsigned int GetFlags();
};
extern unsigned int DAT_010a2720;
void* __cdecl __memcpy(void* dst, const void* src, unsigned int size);
struct FUN_006cf6a0_Class
{
    void* __thiscall CopyAndFreeBuffer(void* src, unsigned int size);
};
void __cdecl Deallocate(void* p);
struct FUN_006cf230_Class
{
    void* __thiscall FUN_006cf230();
};
struct FUN_006cfc80_Class
{
    void* __thiscall FUN_006cfc80(unsigned int flags);
};
void __cdecl Deallocate(void* p);
struct FUN_006cf340_Class
{
    void* __thiscall FUN_006cf340();
};
struct FUN_006cfcb0_Class
{
    void* __thiscall FUN_006cfcb0(unsigned int flags);
};
void __cdecl operator delete(void* p);
struct FUN_006cfd40_Class
{
    void __thiscall FUN_006cf610();
    void* __thiscall FUN_006cfd40(unsigned int flags);
};
struct FUN_006e9410_shell
{
    void FUN_006e90a0(int a, int b);
    void* GetElementAddress30_006e8f40(int a, void* b);
};
struct FUN_006e9530_shell
{
    void VirtualPathingNode_Copy();
};
struct FUN_006e9410_class
{
    void __thiscall BSSimpleArray_VirtualPathingNode_1024_Copy(void* arg);
};
void* __cdecl FUN_00ec7230(char* dst, const char* src, unsigned int size);
struct FUN_006dc6e0_Class
{
    void __thiscall BSSimpleArray_BSCompoundFrustum_FunctionOp_1024_MoveItems(char* a, char* b, unsigned int count);
};
struct FUN_006cf820
{
    virtual ~FUN_006cf820();
};
struct FUN_006cf840 : FUN_006cf820
{
    virtual ~FUN_006cf840();
};
struct TypeValueCount
{
    int a;
    float b;
};
struct FUN_006c8a30_Class
{
    void FUN_006a8500();
};
struct FUN_006dc590
{
    int* vfptr;
    TypeValueCount* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;
    void __thiscall UpdateState_006dc590(unsigned int aiNewSize, unsigned int aiCopyCount);
};
struct FUN_0072ba80_shell
{
    void FUN_0072ba80(char* dst, unsigned int count);
};
struct FUN_006f9eb0_class
{
    void BSSimpleArray_Resize_0(unsigned int newSize, int oldSize);
};
struct FUN_006f9790_class
{
    void* vfptr;
    char* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;
    void BSSimpleArray_SetAllocSize(unsigned int aiReserveSize);
};
struct FUN_006e1280_Class
{
    void VisitPlacementAddresses(char* p, unsigned int n);
};
struct FUN_006cf520_Class
{
    int __thiscall BSScrapArray_bool_1024_Add(const unsigned char* aValue);
};
struct FUN_006d0450_Class
{
    int __thiscall GetNextIndex();
};
void* __cdecl operator new(unsigned int, void*);
struct EightByteData
{
    unsigned char m_data[8];
};
struct NavMeshEdgeReference
{
    EightByteData m_triHandle;
    int m_iEdgeIndex;
};
struct FUN_006f3170_Class
{
    bool BSSimpleArray_HasSufficientCapacity();
};
struct FUN_00869600_Class
{
    unsigned int BSSimpleArray_GetOptimalCapacity();
};
struct FUN_0061bf70_Class
{
    virtual void FUN_0061bf70_vtable0();
    virtual NavMeshEdgeReference* FUN_0061bf70_alloc(unsigned int count);

    NavMeshEdgeReference* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;

    void FUN_0061bf70(unsigned int aiIndex, bool abShrink);
};
extern int DAT_0106c954;
struct FUN_006d0310_Class
{
    void BSSimpleArray_NavMeshEdgeLocation_1024_InitialSetup(unsigned int, unsigned int);
};
struct FUN_006cf200
{
    int* vfptr;
    FUN_006cf200();
};
struct EH
{
    int m_00;
    int m_04;
    int m_08;

    EH& operator=(const EH&);
};
struct FUN_006cf900_Class : EH
{
    struct Location
    {
        int m_00;
        int m_04;
        int m_08;
    } m_Location;

    FUN_006cf900_Class& CopyFields_006cf900(const FUN_006cf900_Class* aLocation);
};
struct PSClearStub
{
    void __thiscall Clear(bool abFreeMemory);
};
struct SaveGameSizeState
{
    void __thiscall BSSimpleArray_VirtualPathingNode_1024_ConstructItems(unsigned int pBuffer, unsigned int ItemUpdateArray);
};
struct S5460Helper
{
    void __thiscall BSSimpleArray_VirtualPathingNode_1024_ReallocateBuffer(unsigned int aiNewSize, unsigned int uiOldSize);
};
struct FUN_006e90a0_class
{
    virtual ~FUN_006e90a0_class();
    virtual PacketNodeRecord* Allocate(unsigned int size);

    PacketNodeRecord* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;

    void FUN_006e90a0(unsigned int aiNewSize, bool abFreeMemory);
};
struct FUN_006e9080
{
    virtual ~FUN_006e9080();
};
struct FUN_006e94d0 : FUN_006e9080
{
    void* FUN_006e94d0_006e94d0(unsigned int flags);
};
struct FUN_0042fb60_shell
{
    void __thiscall FUN_0042fb60(char* dst, char* src, unsigned int count);
};
struct FUN_006bf8f0_Class
{
    virtual void FUN_006bf8f0_slot0() = 0;
    virtual char* FUN_006bf8f0_reallocate(unsigned int size) = 0;

    char* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;

    void __thiscall BSSimpleArray_HUDMainMenu_SubtitleData_1024_Remove(unsigned int aiIndex, bool abShrink);
};
struct FUN_006a2270_class
{
    void BSSimpleArray_PathingNode_1024_CopyItems(char* pDest, char* pSource, unsigned int ItemUpdateArray);
};
struct FUN_006cf000_Class
{
    virtual void FUN_006cf000_Dummy() = 0;
    virtual PathingGraphNode* FUN_006cf000_Reallocate(unsigned int uiSize) = 0;

    PathingGraphNode* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;

    void RemoveAt(unsigned int uiIndex, bool bCondition);
};
struct S5460_FUN_006e3d30_Helper
{
    void* __thiscall BSSimpleArray_PathingAvoidNode_1024_ReallocateBuffer(unsigned int newSize, unsigned int oldSize);
};
struct BSSimpleArray_PathingAvoidNode_1024
{
    virtual void* Dummy();
    virtual void* Allocate(unsigned int newSize);

    PathingAvoidNode* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;

    void InitializeItems(PathingAvoidNode* pItems, unsigned int ItemUpdateArray);
    void SetSize(unsigned int aiNewSize, bool abFreeMemory);
};
struct FUN_009f6540_Helper
{
    void __thiscall BSSimpleArray_TeleportLink_1024_ReallocateBuffer(unsigned int, unsigned int);
};
struct Host9f6340
{
    void __thiscall BSSimpleArray_SandBoxChoiceListItem_1024_ConstructItems(int, int);
};
struct FUN_009f6200_Class
{
    virtual void FUN_009f6200_v0();
    virtual void* FUN_009f6200_v1(unsigned int);

    char* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;

    void BSSimpleArray_SandBoxChoiceListItem_1024_SetSize(unsigned int aiNewSize, bool abFreeMemory);
};
struct FUN_0069cfe0_Elem
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
};
struct FUN_0069cfe0_Dst
{
    void FUN_0069cea0(unsigned int count, int flag);
    FUN_0069cfe0_Elem* Object_GetIndexedValue_006a1440(unsigned int index);
};
struct FUN_0069cfe0_cls
{
    int m_00;
    FUN_0069cfe0_Elem* m_04;
    unsigned int m_08;

    void CopyElementsTo(FUN_0069cfe0_Dst* dst);
};
struct FUN_005e0510
{
    void* m_vftable;
    unsigned int m_uiItemCount;
    unsigned int m_pRayCursor;
    unsigned int m_flags;
    FUN_005e0510();
    ~FUN_005e0510();
};
extern int DAT_0106c968;
struct HeapProvider
{
    void* FUN_00aa42e0();
};
HeapProvider* __cdecl MemoryManager_Instance();
struct FUN_006cf2a0 : FUN_005e0510
{
    void* m_pStreamAllocator;
    FUN_006cf2a0(int first, int second, void* heap);
    void BSSimpleArray_float_1024_InitialSetup(int first, int second);
};
struct FUN_006cf700_cls
{
    int m_00;
    int m_04;
    unsigned int m_08;
    int FindIndexIf(int a, unsigned int start, bool (*pred)(int, int));
};
struct ItemRaw
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};
struct ParamHost
{
    void Prepare(unsigned int count, int flags);
    void* ProcessItem(unsigned int index, ItemRaw* item);
};
struct ItemFinish
{
    void CopyFields_006cf900();
};
struct FUN_006cf8a0_cls
{
    int unk00;
    ItemRaw* pItems;
    unsigned int iCount;

    void ProcessItems(ParamHost* p);
};
struct FUN_006cf940_Item
{
    void FUN_006dcce0();
};
struct FUN_006cf940_Owner
{
    void ResizeArrayStorage(unsigned int count, int flag);
    FUN_006cf940_Item* FUN_00691750(unsigned int index, char* pItem);
};
struct FUN_006cf940_cls
{
    int unk00;
    char* m_04;
    unsigned int m_08;

    void BSSimpleArray_CopyTo_0(FUN_006cf940_Owner* a1);
};
struct FUN_006cfac0_base
{
    int* vfptr;
    virtual ~FUN_006cfac0_base();
};
struct FUN_006cfac0_cls : FUN_006cfac0_base
{
    virtual ~FUN_006cfac0_cls();
    void FUN_008454f0(int flag);
};
struct FUN_006d0540_shell
{
    virtual void vf00();
    virtual void* vf04(int value);
    virtual void vf08();
    virtual void* vf0c(void* current, int value);

    void* unk04;
    int unk08;
    int unk0c;

    void __thiscall CopyOverlappingElements30(void* newItem, void* oldItem, unsigned int count);
    void __thiscall FUN_006a8500();
};
struct FUN_006cfe70_Class : public FUN_006d0540_shell
{
    void __thiscall BSSimpleArray_VirtualPathingNode_1024_ReallocateBuffer(int value, int count);
};
void* __cdecl operator new(unsigned int size, void* place);
void __cdecl operator delete(void* p, void* place);
struct SpawnedObject9
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;

    SpawnedObject9();
};
struct FUN_006e3c90_cls
{
    void ConstructSpawnedObjects(char* base, unsigned int count);
};
struct FUN_006e9470_Helper
{
    void BSSimpleArray_PathingNode_1024_SetSize(unsigned int count, int flag);
    void* GetPathingGraphNodeAddress(int index, void* item);
};
struct FUN_006e9470_Obj
{
    void FUN_006e9570();
};
struct FUN_006e9470_cls
{
    int m_00;
    char* m_04;
    unsigned int m_08;

    void BSSimpleArray_PathingNode_1024_Copy(FUN_006e9470_Helper* pHelper);
};
struct S_00a0d000_Class
{
    virtual unsigned int ReserveSlotAndIncrementSize();
    virtual void* FUN_00a0d010(unsigned int size);

    void* pBuffer;
    unsigned int m_uiSize;
    unsigned int m_uiReservedSize;

    void UpdateFields_00a0d0c0(unsigned int newCapacity, unsigned int copyCount);
};
struct FUN_006cf230
{
    virtual ~FUN_006cf230();
    void Clear(bool abFree);
};
class Allocator6CF;
class ContainerBase6CF
{
  public:
    ContainerBase6CF();
    virtual ~ContainerBase6CF();

    int unk04;
    int unk08;
    int unk0C;
};
class FUN_006cf780_Pool : public ContainerBase6CF
{
  public:
    FUN_006cf780_Pool(int iCapacity, int iGrowBy, Allocator6CF* pkAllocator);
    virtual ~FUN_006cf780_Pool();

    void Initialize(int iCapacity, int iGrowBy);

    Allocator6CF* m_pHeapAllocator;
};
// Destructor: clear the detailed path infos; the base list is destroyed afterwards.
class CFBC0Base
{
  public:
    virtual ~CFBC0Base();
    int unk04;
};
class FUN_006cfbc0 : public CFBC0Base
{
  public:
    virtual ~FUN_006cfbc0();
    void Clear(bool bFree);
};
struct FUN_006e9280_Item
{
    char data[0x3c];
};
struct FUN_006e9280_shell
{
    virtual void Unk_00();
    virtual FUN_006e9280_Item* Allocate(unsigned int ItemUpdateArray);
    FUN_006e9280_Item* m_pBuffer;
    unsigned int m_uiSize;
    unsigned int m_uiCapacity;
    void BSSimpleArray_PathingNode_1024_ReallocateBuffer(unsigned int uiNewAlloc, unsigned int uiCopy);
    void ConstructArray(FUN_006e9280_Item* pItems, unsigned int ItemUpdateArray);
    void FUN_006cff20(FUN_006e9280_Item* pItems, unsigned int ItemUpdateArray);
    void BSSimpleArray_PathingNode_1024_SetSize(unsigned int uiNewSize, bool bShrink);
};

struct ArrayStub
{
    virtual void vf0()
    {}
    virtual void* vf1(void* value)
    {
        return value;
    }
    virtual void vf2(void* value)
    {}
    virtual void* vf3(void* first, void* second)
    {
        return first;
    }

    void* unk04;
    unsigned int unk08;
    void* unk0C;

    void FUN_00a0cf60(char* dest, char* src, unsigned int count)
    {
        if (count == 0)
            return;
        if (dest < src)
        {
            for (unsigned int i = 0; i < count; i++)
                copyOne(dest + i * 4, src + i * 4);
        }
        else if (dest > src)
        {
            for (int j = (int)count - 1; j >= 0; j--)
                copyOne(dest + j * 4, src + j * 4);
        }
    }
    void copyOne(char* dest, char* src);

    void UpdateFields_00a0d0c0(void* newValue, void* key);
};

// @fnv 0x00a0d0c0
// src: GUESS 0x00a0d0c0 (confidence: low)
void ArrayStub::UpdateFields_00a0d0c0(void* newValue, void* key)
{
    if (unk04 != 0)
    {
        if (key == unk0C)
        {
            unk04 = vf3(unk04, newValue);
        }
        else
        {
            void* tmp = vf1(newValue);
            FUN_00a0cf60((char*)tmp, (char*)unk04, (unsigned int)key);
            vf2(unk04);
            unk04 = 0;
            unk04 = tmp;
        }
    }
    else
    {
        unk04 = vf1(newValue);
        unk0C = newValue;
    }
}

inline void DeadQ1()
{
    int a[1];
}
inline void DeadQ2()
{
    int a[2];
}
inline void DeadQ3()
{
    int a[3];
}
inline void DeadQ4()
{
    int a[4];
}
inline void DeadQ5()
{
    int a[5];
}
inline void DeadQ6()
{
    int a[6];
}
struct PNQ0cd50
{
};
inline void* __cdecl operator new(unsigned int, void* p, PNQ0cd50*)
{
    return p;
}
struct ArrQ0cd50
{
    virtual ~ArrQ0cd50();
    virtual void** Allocate(unsigned int count);
    virtual void Free(void** p);
    void** m_pBuffer;
    unsigned int m_iElementCount;
    unsigned int m_alloc;
    void FUN_00a0cf00(void* const& item);
    void FUN_00a0cf60(void** dst, void** src, unsigned int count);
    bool IsFull()
    {
        if (m_iElementCount == m_alloc)
            return true;
        return false;
    }
    unsigned int GetNewSize()
    {
        return m_alloc > 8 ? m_alloc + 8 : m_alloc * 2;
    }
    void ConstructItems(void** p, unsigned int n)
    {
        for (unsigned int i = 0; i < n; i++)
            new (&p[i], (PNQ0cd50*)0) void*;
    }
    void AllocateStorage_00a0cd50(unsigned int index, void* const& item);
};
// @fnv 0x00a0cd50
// src: GUESS 0x00a0cd50 (confidence: low)
void ArrQ0cd50::AllocateStorage_00a0cd50(unsigned int index, void* const& item)
{
    DeadQ3();
    if (index == m_iElementCount)
    {
        FUN_00a0cf00(item);
        return;
    }
    if (IsFull())
    {
        DeadQ2();
        unsigned int newSize = GetNewSize();
        void** p = Allocate(newSize);
        FUN_00a0cf60(p, m_pBuffer, index);
        ConstructItems(p + index, 1);
        FUN_00a0cf60(p + index + 1, m_pBuffer + index, m_iElementCount - index);
        Free(m_pBuffer);
        m_pBuffer = 0;
        m_pBuffer = p;
        m_alloc = newSize;
    }
    else
    {
        DeadQ4();
        FUN_00a0cf60(m_pBuffer + index + 1, m_pBuffer + index, m_iElementCount - index);
        ConstructItems(m_pBuffer + index, 1);
    }
    m_iElementCount++;
    m_pBuffer[index] = item;
}

extern int DAT_0109527c;
inline void* __cdecl operator new(unsigned int, void* memory)
{
    return memory;
}
inline void __cdecl operator delete(void*, void*)
{}

struct ArrayVector
{
    float x, y, z, w;
    ArrayVector() : x(0), y(0), z(0), w(0)
    {}
};

struct ArrayElement
{
    unsigned int unk00, unk04, unk08, unk0c;
    ArrayVector value;
};

struct ArrayConstructor;
typedef void*(__thiscall* ArrayAllocate)(ArrayConstructor*, unsigned int);

struct ArrayConstructor
{
    int* vfptr;
    ArrayElement* data;
    unsigned int size;
    unsigned int capacity;

    void ConstructElements(ArrayElement* items, unsigned int count)
    {
        for (unsigned int i = 0; i < count; ++i)
            new (items + i) ArrayElement;
    }

    __forceinline void Initialize(unsigned int count, unsigned int initial)
    {
        data = 0;
        size = 0;
        capacity = 0;
        if (count < initial)
            count = initial;
        if (count > 0)
        {
            data = (ArrayElement*)((ArrayAllocate)(void*)vfptr[1])(this, count);
            capacity = count;
        }
        if (initial > 0)
        {
            ConstructElements(data, initial);
            size = initial;
        }
    }

    ArrayConstructor* BSSimpleArray_ButtonIcon_1024_BSSimpleArray_ButtonIcon_1024();
};

// @fnv 0x00a1bef0
// src: COMMUNITY 0x00a1bef0
ArrayConstructor* ArrayConstructor::BSSimpleArray_ButtonIcon_1024_BSSimpleArray_ButtonIcon_1024()
{
    vfptr = &DAT_0109527c;
    Initialize(0, 0);
    return this;
}
