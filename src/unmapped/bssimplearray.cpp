#include "../../include/NiPoint3.h"
#include "../../include/PathingLocation.h"
#include "../../include/BSScrapArray.h"
#include "../../include/PathingAvoidNode.h"
#include "../../include/BSSimpleArray.h"
#include "../../include/PathingGraphNode.h"
#include "../../include/MemoryManager.h"
#include "../../include/NiColorA.h"
#include "../../include/PathBuilder.h"
#include "../../include/CombatSearchDoor.h"

// Owner of the nested element type needed in this unit.
class PathSmoother
{
public:
    struct AvoidNode;
};

// 0x006a8500 releases pBuffer through virtual _Deallocate (slot 2), then clears it.
// Keep this ECX-only helper declaration here until the shared array declares it.
void __fastcall FreeSimpleArrayStorage(void* array);

// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern int DAT_0106b8a0;

struct FUN_006cf9d0
{
    int* vfptr;
    void BSSimpleArray_WeaponData_1024_InitialSetup(unsigned int maxSize, unsigned int growBy);
    FUN_006cf9d0(unsigned int maxSize, unsigned int growBy);
};

// Initializes the object's vfptr to DAT_0106b8a0 and calls FUN_009a3d00 with maxSize and growBy.
// @fnv 0x006cf9d0
FUN_006cf9d0::FUN_006cf9d0(unsigned int maxSize, unsigned int growBy) : vfptr(&DAT_0106b8a0)
{
    this->BSSimpleArray_WeaponData_1024_InitialSetup(maxSize, growBy);
}

extern int DAT_0106b91c;
struct FUN_006cf180
{
    void* vfptr;
    void ResizeAndConstruct(int a, int b);
    FUN_006cf180();
};
// Sets the vtable pointer to DAT_0106b91c and calls ResizeAndConstruct with 0, 0.
// @fnv 0x006cf180
FUN_006cf180::FUN_006cf180()
{
    vfptr = &DAT_0106b91c;
    ResizeAndConstruct(0, 0);
}

struct FUN_006cf250_Class
{
    void* __thiscall AllocateBuffer(unsigned int count);
};

// Allocates count * 0x18 bytes with operator new and returns the pointer.
// @fnv 0x006cf250
void* __thiscall FUN_006cf250_Class::AllocateBuffer(unsigned int count)
{
    void* buffer = operator new(count * 0x18);
    return buffer;
}

extern "C" void* __cdecl _Reallocate(void* p, unsigned int size);
struct FUN_006cf280_Class
{
    void* __thiscall _Reallocate_Thunk_006cf280(void* p, unsigned int n);
};
// @fnv 0x006cf280
// src: GUESS 0x006cf280 (confidence: medium)
void* __thiscall FUN_006cf280_Class::_Reallocate_Thunk_006cf280(void* p, unsigned int n)
{
    return _Reallocate(p, n * 0x18);
}

// @fnv 0x006cf760
bool AreBytesEqual(const unsigned char* pucA, const unsigned char* pucB)
{
    return *pucA == *pucB;
}

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
// Sets the vtable pointer to DAT_0106b8c8 and forwards maxSize and growBy to FUN_006b3f40.
// @fnv 0x006cf9a0
FUN_006cf9a0::FUN_006cf9a0(int maxSize, int growBy)
{
    vfptr = &DAT_0106b8c8;
    BSSimpleArray_NavMeshPOVSearchNode_1024_InitialSetup(maxSize, growBy);
}

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
// @fnv 0x006cfaa0
// src: GUESS 0x006cfaa0 (confidence: medium)
void FUN_006cfaa0::ResetVirtualTableAndClear_006cfaa0()
{
    vfptr = &DAT_0106c9e0;
    ((GlobalObject_00869f00*)this)->Clear(true);
}

struct FUN_006e91e0_cls
{
    void* __thiscall AllocateBlock(int count);
};

// Allocates count * 0x30 bytes with operator new and returns the pointer.
// @fnv 0x006e91e0
void* __thiscall FUN_006e91e0_cls::AllocateBlock(int count)
{
    void* p = operator new(count * 0x30);
    return p;
}

void* __cdecl _Reallocate(void* p, unsigned int size);

struct FUN_006e9210
{
    void Reallocate(void* p, unsigned int size);
};

// @fnv 0x006e9210
void FUN_006e9210::Reallocate(void* p, unsigned int auiCount)
{
    _Reallocate(p, auiCount * 0x30);
}

extern int DAT_0106d4e8;
struct FUN_006e9230_class
{
    int* vfptr;
    void BSSimpleArray_PathingNode_1024_InitialSetup(int a, int b);
    FUN_006e9230_class();
};
// Sets the vtable pointer to DAT_0106d4e8 and calls FUN_006e97a0 with 0, 0.
// @fnv 0x006e9230
FUN_006e9230_class::FUN_006e9230_class()
{
    vfptr = &DAT_0106d4e8;
    BSSimpleArray_PathingNode_1024_InitialSetup(0, 0);
}

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
// @fnv 0x006e9260
// src: GUESS 0x006e9260 (confidence: low)
void FUN_006e9260Class::SetVirtualTableAndProcessState_006e9260()
{
    vfptr = (int*)&DAT_0106d4e8;
    FUN_006cf120(true);
}

// Allocates count * 0x3c bytes with operator new and returns the resulting pointer.
// @fnv 0x006e93c0
template <>
PathingGraphNode* BSSimpleArray<PathingGraphNode, 1024>::_Allocate(unsigned int count)
{
    void* result = operator new(count * sizeof(PathingGraphNode));
    return static_cast<PathingGraphNode*>(result);
}

void* __cdecl Reallocate(void* p, int size);

struct FUN_006e93f0
{
    void* __thiscall Reallocate_Thunk(void* p, int n);
};

// @fnv 0x006e93f0
// src: GUESS 0x006e93f0 (confidence: medium)
void* __thiscall FUN_006e93f0::Reallocate_Thunk(void* p, int aiCount)
{
    return Reallocate(p, aiCount * 0x3c);
}

// Returns true if this point's x, y and z are all equal to the corresponding components of a.
// @fnv 0x004390c0
// src: GUESS 0x004390c0 (confidence: high)
bool NiPoint3::HasEqualComponents(const NiPoint3& aPoint)
{
    return x == aPoint.x && y == aPoint.y && z == aPoint.z;
}

struct FUN_00691820_arr
{
    int m0;
    unsigned short* pBuffer;
    unsigned int GetNextPosition();
    unsigned int Append(const unsigned short* aValue);
};
// @fnv 0x00691820
unsigned int FUN_00691820_arr::Append(const unsigned short* aValue)
{
    unsigned int iElementIndex = GetNextPosition();
    ((BSSimpleArray<unsigned short, 1024>*)this)->InitializeItems((unsigned short*)((unsigned int)pBuffer + iElementIndex * 2), 1);
    pBuffer[iElementIndex] = *aValue;
    return iElementIndex;
}

struct PacketNodeRecord
{
    void FUN_006a8500();
};
// @fnv 0x006cefa0
template <>
void BSSimpleArray<PacketNodeRecord, 1024>::Clear(bool abFreeMemory)
{
    if (pBuffer)
    {
        ReleaseElements(pBuffer, iSize);
        if (abFreeMemory)
        {
            FreeSimpleArrayStorage(this);
            pBuffer = 0;
            SimpleArrayStorage = 0;
        }
        iSize = 0;
    }
}

// @fnv 0x006cf120
template <>
void BSSimpleArray<PathingGraphNode, 1024>::Clear(bool bFreeStorage)
{
    if (pBuffer)
    {
        ReleaseElements(pBuffer, iSize);
        if (bFreeStorage)
        {
            FreeSimpleArrayStorage(this);
            pBuffer = 0;
            SimpleArrayStorage = 0;
        }
        iSize = 0;
    }
}


// Appends a copy of aValue to the array at the next free index and returns that index.
// @fnv 0x006cf1b0
template <>
unsigned int BSSimpleArray<PathingLocation, 1024>::Append(const PathingLocation& aValue)
{
    unsigned int uiIndex = ReserveIndex();
    InitializeItems((PathingLocation*)((char*)pBuffer + uiIndex * 0x28), 1);
    ((PathingLocation*)((char*)pBuffer + uiIndex * 0x28))[0] = aValue;
    return uiIndex;
}

// PolyDetailedPathInfos: unit-local; the base 0x006cf340 tears down is polymorphic (its virtual destructor), unlike the
// shared PathBuilderDetailedPathInfos: with the shared class 0x006cf340 compiles 6 bytes longer
struct PolyDetailedPathInfos
{
    int* vfptr;
    void Clear(bool);
    virtual ~PolyDetailedPathInfos();
};
struct FUN_006cf340 : PolyDetailedPathInfos
{
    virtual ~FUN_006cf340();
};
// Destructor that calls Clear(true) on the PolyDetailedPathInfos base.
// @fnv 0x006cf340
FUN_006cf340::~FUN_006cf340()
{
    Clear(true);
}

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
// @fnv 0x006cf440
FUN_006cf440::~FUN_006cf440()
{
    ((GlobalObject_00869f00*)this)->Clear(true);
}

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
// @fnv 0x006cf4c0
// src: XBOX_PDB 0x006cf4c0
unsigned int FUN_006cf4c0_Array::BSSimpleArray_ParentSpaceNode_1024_Add(const ParentSpaceNode& aValue)
{
    unsigned int iElementIndex = ((S5460*)this)->BSSimpleArray_NiPoint3_1024_AddUninitialized();
    ((ArrHelper*)this)->ConstructParentSpaceNodes((ParentSpaceNode*)((char*)pBuffer + iElementIndex * 12), 1);
    *(ParentSpaceNode*)((char*)pBuffer + iElementIndex * 12) = aValue;
    return iElementIndex;
}

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
// Destructor that calls Clear(true) on the base object.
// @fnv 0x006cf610
FUN_006cf610::~FUN_006cf610()
{
    Clear(true);
}

struct ScrapHeapBuffer
{
    void* Allocate(unsigned int, unsigned int);
    void Deallocate(void*);
};
// Exe 0x006cf6a0: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct BssimplearrayOffset08View
{
    unsigned int GetFlags();
};
extern unsigned int DAT_010a2720;
void* __cdecl __memcpy(void* dst, const void* src, unsigned int size);
// Allocates size bytes from the allocator at this+0x10, copies GetFlags() bytes from src into it, frees src, and returns the new buffer.
// @fnv 0x006cf6a0
template <>
unsigned char* BSScrapArray<unsigned char>::_Reallocate(unsigned char* src, unsigned int size)
{
    void* result = m_pPoolBase->Allocate(size, DAT_010a2720);
    __memcpy(result, src, reinterpret_cast<BssimplearrayOffset08View*>(this)->GetFlags());
    m_pPoolBase->Deallocate(src);
    return static_cast<unsigned char*>(result);
}

// Allocates count*4 bytes, copies GetFlags()*4 bytes from src, frees src, and returns the new buffer.
// @fnv 0x006cfc20
template <>
unsigned int* BSScrapArray<unsigned int>::_Reallocate(unsigned int* src, unsigned int count)
{
    void* p = m_pPoolBase->Allocate(count * 4, DAT_010a2720);
    __memcpy(p, src, ((BssimplearrayOffset08View*)this)->GetFlags() * 4);
    m_pPoolBase->Deallocate((void*)src);
    return static_cast<unsigned int*>(p);
}

void __cdecl Deallocate(void* p);

struct FUN_006cf230_Class
{
    void* __thiscall FUN_006cf230();
};

struct FUN_006cfc80_Class
{
    void* __thiscall FUN_006cfc80(unsigned int flags);
};

// Calls FUN_006cf230 on this, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x006cfc80
void* __thiscall FUN_006cfc80_Class::FUN_006cfc80(unsigned int flags)
{
    ((FUN_006cf230_Class*)this)->FUN_006cf230();
    if (flags & 1)
        Deallocate(this);
    return this;
}

void __cdecl Deallocate(void* p);
struct FUN_006cf340_Class
{
    void* __thiscall FUN_006cf340();
};
struct FUN_006cfcb0_Class
{
    void* __thiscall FUN_006cfcb0(unsigned int flags);
};
// Calls FUN_006cf340 on this, then frees this when flags has bit 0 set, and returns this.
// @fnv 0x006cfcb0
void* __thiscall FUN_006cfcb0_Class::FUN_006cfcb0(unsigned int flags)
{
    ((FUN_006cf340_Class*)this)->FUN_006cf340();
    if (flags & 1)
        Deallocate(this);
    return this;
}

namespace fnv_006cfce0 {
struct FUN_006cf440_class
{
    void FUN_006cf440();
};
void* __cdecl Deallocate(void*);
struct FUN_006cfce0_class
{
    void* __thiscall FUN_006cfce0(unsigned int flags);
};
// @fnv 0x006cfce0
void* __thiscall FUN_006cfce0_class::FUN_006cfce0(unsigned int flags)
{
    ((FUN_006cf440_class*)this)->FUN_006cf440();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}  // namespace fnv_006cfce0

namespace fnv_006cfd10 {
void* __cdecl Deallocate(void* p);

struct FUN_006cf820_Class
{
    void* __thiscall FUN_006cf820();
};

struct FUN_006cfd10_Class
{
    void* __thiscall FUN_006cfd10(unsigned int flags);
};

// Calls FUN_006cf820 on this, frees this when flags has bit 0 set, and returns this.
// @fnv 0x006cfd10
void* __thiscall FUN_006cfd10_Class::FUN_006cfd10(unsigned int flags)
{
    reinterpret_cast<FUN_006cf820_Class*>(this)->FUN_006cf820();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}  // namespace fnv_006cfd10

void __cdecl operator delete(void* p);
struct FUN_006cfd40_Class
{
    void __thiscall FUN_006cf610();
    void* __thiscall FUN_006cfd40(unsigned int flags);
};
// Calls FUN_006cf610, deletes this when flags has bit 0 set, and returns this.
// @fnv 0x006cfd40
void* __thiscall FUN_006cfd40_Class::FUN_006cfd40(unsigned int flags)
{
    FUN_006cf610();
    if (flags & 1)
        operator delete(this);
    return this;
}

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
// @fnv 0x006e9410
// src: COMMUNITY 0x006e9410
void __thiscall FUN_006e9410_class::BSSimpleArray_VirtualPathingNode_1024_Copy(void* arg)
{
    ((FUN_006e9410_shell*)arg)->FUN_006e90a0(*(int*)((char*)this + 8), 1);
    for (unsigned int i = 0; i < *(unsigned int*)((char*)this + 8); ++i)
        ((FUN_006e9530_shell*)((FUN_006e9410_shell*)arg)->GetElementAddress30_006e8f40(i, (char*)*(void**)((char*)this + 4) + i * 0x30))
            ->VirtualPathingNode_Copy();
}

namespace fnv_007a1c30 {
struct FUN_007a86b0_Item
{
    int a;
};
struct FUN_007a63b0_holder
{
    void BSSimpleArray_BSStringT_char_1024_DestructItems(FUN_007a86b0_Item*, unsigned int);
};
struct FUN_007a1c30_holder
{
    int pad;
    FUN_007a86b0_Item* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;
    void ClearBuffer(bool freeStorage);
};
// @fnv 0x007a1c30
void FUN_007a1c30_holder::ClearBuffer(bool freeStorage)
{
    if (pBuffer)
    {
        ((FUN_007a63b0_holder*)this)->BSSimpleArray_BSStringT_char_1024_DestructItems(pBuffer, iSize);
        if (freeStorage)
        {
            FreeSimpleArrayStorage(this);
            pBuffer = 0;
            SimpleArrayStorage = 0;
        }
        iSize = 0;
    }
}
}  // namespace fnv_007a1c30

namespace fnv_008454f0 {
struct FUN_0072ba80_shell
{
    void FUN_0072ba80(void* p, unsigned int n);
};
struct FUN_008454f0
{
    void* vfptr;
    void* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;
    void Clear(bool freeStorage);
};
// @fnv 0x008454f0
void FUN_008454f0::Clear(bool freeStorage)
{
    if (pBuffer)
    {
        ((FUN_0072ba80_shell*)this)->FUN_0072ba80(pBuffer, iSize);
        if (freeStorage)
        {
            FreeSimpleArrayStorage(this);
            pBuffer = 0;
            SimpleArrayStorage = 0;
        }
        iSize = 0;
    }
}
}  // namespace fnv_008454f0

void* __cdecl FUN_00ec7230(char* dst, const char* src, unsigned int size);

struct FUN_006dc6e0_Class
{
    void __thiscall BSSimpleArray_BSCompoundFrustum_FunctionOp_1024_MoveItems(char* a, char* b, unsigned int count);
};

// @fnv 0x006dc6e0
// src: XBOX_PDB 0x006dc6e0
void __thiscall FUN_006dc6e0_Class::BSSimpleArray_BSCompoundFrustum_FunctionOp_1024_MoveItems(char* pDst, char* pSrc, unsigned int count)
{
    if (count <= 0)
        return;
    if (pDst < pSrc)
    {
        for (unsigned int i = 0; i < count; ++i)
            FUN_00ec7230(pDst + i * 0xc, pSrc + i * 0xc, 0xc);
    }
    else
    {
        if (pDst > pSrc)
        {
            for (int i = (int)count - 1; i >= 0; --i)
                FUN_00ec7230(pDst + i * 0xc, pSrc + i * 0xc, 0xc);
        }
    }
}

struct FUN_006cf820
{
    virtual ~FUN_006cf820();
};
struct FUN_006cf840 : FUN_006cf820
{
    virtual ~FUN_006cf840();
};
// Destructor that calls Clear(true) on the object at this address.
// @fnv 0x006cf840
FUN_006cf840::~FUN_006cf840()
{
    reinterpret_cast<GlobalObject_00869f00*>(this)->Clear(true);
}

struct TypeValueCount
{
    int a;
    float b;
};
struct FUN_006dc590
{
    int* vfptr;
    TypeValueCount* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;
    void __thiscall UpdateState_006dc590(unsigned int aiNewSize, unsigned int aiCopyCount);
};
// @fnv 0x006dc590
// src: GUESS 0x006dc590 (confidence: low)
void __thiscall FUN_006dc590::UpdateState_006dc590(unsigned int aiNewSize, unsigned int aiCopyCount)
{
    if (pBuffer)
    {
        if (aiCopyCount == SimpleArrayStorage)
        {
            pBuffer = (TypeValueCount*)((void*(__thiscall*)(void*, TypeValueCount*, unsigned int))vfptr[3])(
                this, pBuffer, aiNewSize);
        }
        else
        {
            TypeValueCount* pnewBuffer =
                (TypeValueCount*)((void*(__thiscall*)(void*, unsigned int))vfptr[1])(this, aiNewSize);
            ((FUN_006dc6e0_Class*)this)->BSSimpleArray_BSCompoundFrustum_FunctionOp_1024_MoveItems((char*)pnewBuffer, (char*)pBuffer, aiCopyCount);
            FreeSimpleArrayStorage(this);
            pBuffer = pnewBuffer;
        }
    }
    else
    {
        pBuffer = (TypeValueCount*)((void*(__thiscall*)(void*, unsigned int))vfptr[1])(this, aiNewSize);
        SimpleArrayStorage = aiNewSize;
    }
}

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
// @fnv 0x006f9790
// src: COMMUNITY 0x006f9790
void FUN_006f9790_class::BSSimpleArray_SetAllocSize(unsigned int aiReserveSize)
{
    if (aiReserveSize == SimpleArrayStorage)
    {
    }
    else
    {
        if (aiReserveSize < iSize)
        {
            ((FUN_0072ba80_shell*)this)->FUN_0072ba80(pBuffer + aiReserveSize * 32, iSize - aiReserveSize);
            iSize = aiReserveSize;
        }
        ((FUN_006f9eb0_class*)this)->BSSimpleArray_Resize_0(aiReserveSize, iSize);
        SimpleArrayStorage = aiReserveSize;
    }
}

namespace fnv_0084b5c0 {
struct FUN_0042fc00_shell
{
    void FUN_0042fc00(unsigned int a, unsigned int b);
};
struct FUN_0072ba80_shell
{
    void FUN_0072ba80(void* p, unsigned int n);
};

struct FUN_0084b5c0_Array
{
    void* m_00;
    void** pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;
    void BSSimpleArray_TESObjectREFR_1024_SetReservedSize(unsigned int aiReserveSize);
};

// @fnv 0x0084b5c0
// src: XBOX_PDB 0x0084b5c0
void FUN_0084b5c0_Array::BSSimpleArray_TESObjectREFR_1024_SetReservedSize(unsigned int aiReserveSize)
{
    if (aiReserveSize == SimpleArrayStorage)
        return;
    if (aiReserveSize < iSize)
    {
        ((FUN_0072ba80_shell*)this)->FUN_0072ba80(pBuffer + aiReserveSize, iSize - aiReserveSize);
        iSize = aiReserveSize;
    }
    ((FUN_0042fc00_shell*)this)->FUN_0042fc00(aiReserveSize, iSize);
    SimpleArrayStorage = aiReserveSize;
}
}  // namespace fnv_0084b5c0

namespace fnv_009a4320 {
unsigned int __cdecl FUN_0042f5a0(unsigned int, unsigned int);
struct FUN_0072ba80_shell
{
    void FUN_0072ba80(void*, unsigned int);
};
struct FUN_0042fb60_shell
{
    void FUN_0042fb60(char*, char*, unsigned int);
};
struct FUN_009a4320_arr
{
    int* vfptr;
    void* pBuffer;
    unsigned int iSize;
    void FUN_0072ba80(void* p, unsigned int n);
    void FUN_0042fb60(char* a, char* b, unsigned int n);
    void BSSimpleArray_Actor_1024_RemoveFast(unsigned int aiIndex, unsigned int aiHowMany);
};
// Removes aiHowMany elements at aiIndex from the buffer, shifting the trailing elements down and shrinking iSize.
// @fnv 0x009a4320
// src: XBOX_PDB 0x009a4320
void FUN_009a4320_arr::BSSimpleArray_Actor_1024_RemoveFast(unsigned int aiIndex, unsigned int aiHowMany)
{
    unsigned int iitemsToMove = FUN_0042f5a0(iSize - aiIndex - aiHowMany, aiHowMany);
    FUN_0072ba80((char*)pBuffer + aiIndex * 4, aiHowMany);
    FUN_0042fb60((char*)pBuffer + aiIndex * 4, (char*)pBuffer + iSize * 4 - iitemsToMove * 4, iitemsToMove);
    iSize -= aiHowMany;
}
}  // namespace fnv_009a4320

namespace fnv_009f6540 {
struct FUN_006c8bd0_Class
{
    void BSSimpleArray_NiColorA_1024_CopyItems(const char*, const char*, unsigned int);
};
struct FUN_009f6540_Class
{
    virtual void* FUN_009f6540_0();
    virtual void* FUN_009f6540_1(unsigned int);
    virtual void FUN_009f6540_2();
    virtual void* FUN_009f6540_3(unsigned int, unsigned int);
    void* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;
    void BSSimpleArray_TeleportLink_1024_ReallocateBuffer(unsigned int aiNewSize, unsigned int aiCopyCount);
};
// @fnv 0x009f6540
// src: XBOX_PDB 0x009f6540
void FUN_009f6540_Class::BSSimpleArray_TeleportLink_1024_ReallocateBuffer(unsigned int aiNewSize, unsigned int aiCopyCount)
{
    if (pBuffer)
    {
        if (aiCopyCount == SimpleArrayStorage)
        {
            pBuffer = FUN_009f6540_3((unsigned int)pBuffer, aiNewSize);
        }
        else
        {
            unsigned int pnewBuffer = (unsigned int)FUN_009f6540_1(aiNewSize);
            ((FUN_006c8bd0_Class*)this)->BSSimpleArray_NiColorA_1024_CopyItems((const char*)pnewBuffer, (const char*)pBuffer, aiCopyCount);
            FreeSimpleArrayStorage(this);
            pBuffer = (void*)pnewBuffer;
        }
    }
    else
    {
        pBuffer = FUN_009f6540_1(aiNewSize);
        SimpleArrayStorage = aiNewSize;
    }
}
}  // namespace fnv_009f6540

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

// @fnv 0x006cf520
// src: COMMUNITY 0x006cf520
int __thiscall FUN_006cf520_Class::BSScrapArray_bool_1024_Add(const unsigned char* aValue)
{
    int iVar1;
    iVar1 = ((FUN_006d0450_Class*)this)->GetNextIndex();
    ((FUN_006e1280_Class*)this)->VisitPlacementAddresses((char*)(*(int*)((char*)this + 4) + iVar1), 1);
    *(unsigned char*)(*(int*)((char*)this + 4) + iVar1) = *aValue;
    return iVar1;
}


// @fnv 0x005eee80
template <>
void BSSimpleArray<unsigned short, 1024>::SetSize(unsigned int aiNewSize, bool abFreeMemory)
{
    if (aiNewSize == 0)
    {
        Clear(abFreeMemory);
    }
    else if (aiNewSize > SimpleArrayStorage)
    {
        if (SimpleArrayStorage == 0)
        {
            pBuffer = _Allocate(aiNewSize);
            SimpleArrayStorage = aiNewSize;
        }
        else
        {
            ReallocateStorage(aiNewSize, iSize);
            SimpleArrayStorage = aiNewSize;
        }

        InitializeItems(pBuffer + iSize, aiNewSize - iSize);
        iSize = aiNewSize;
    }
    else if (aiNewSize < iSize)
    {
        ReleaseElements(pBuffer + aiNewSize, iSize - aiNewSize);
        iSize = aiNewSize;

        if (abFreeMemory && aiNewSize <= (SimpleArrayStorage >> 2))
        {
            ReallocateStorage(aiNewSize, aiNewSize);
            SimpleArrayStorage = aiNewSize;
        }
    }
    else
    {
        InitializeItems(pBuffer + iSize, aiNewSize - iSize);
        iSize = aiNewSize;
    }
}

void* __cdecl operator new(unsigned int, void*);

// @fnv 0x005ef650
template <>
void BSSimpleArray<unsigned short, 1024>::InitializeItems(unsigned short* items, unsigned int growBy)
{
    unsigned int i;
    void* p2;
    for (i = 0; i < growBy; ++i)
    {
        p2 = operator new(2, (void*)((unsigned int)items + i * 2));
    }
}

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

typedef BSSimpleArray<NavMeshEdgeReference, 1024> FUN_0061bf70_Class;


// @fnv 0x0061bf70
template <> void BSSimpleArray<NavMeshEdgeReference, 1024>::RemoveAt(unsigned int aiIndex, bool abShrink)
{
    unsigned int inewSize;
    NavMeshEdgeReference* pnewBuffer;

    if (abShrink && reinterpret_cast<FUN_006f3170_Class*>(this)->BSSimpleArray_HasSufficientCapacity())
    {
        inewSize = reinterpret_cast<FUN_00869600_Class*>(this)->BSSimpleArray_GetOptimalCapacity();
        pnewBuffer = this->_Allocate(inewSize);

        reinterpret_cast<FUN_006dc6e0_Class*>(this)->BSSimpleArray_BSCompoundFrustum_FunctionOp_1024_MoveItems(reinterpret_cast<char*>(pnewBuffer),
                                                                  reinterpret_cast<char*>(this->pBuffer), aiIndex);

        reinterpret_cast<FUN_0072ba80_shell*>(this)->FUN_0072ba80(reinterpret_cast<char*>(this->pBuffer + aiIndex), 1);

        reinterpret_cast<FUN_006dc6e0_Class*>(this)->BSSimpleArray_BSCompoundFrustum_FunctionOp_1024_MoveItems(reinterpret_cast<char*>(pnewBuffer + aiIndex),
                                                                  reinterpret_cast<char*>(this->pBuffer + aiIndex + 1),
                                                                  this->iSize - 1);

        FreeSimpleArrayStorage(this);

        this->pBuffer = pnewBuffer;
        this->SimpleArrayStorage = inewSize;
    }
    else
    {
        reinterpret_cast<FUN_0072ba80_shell*>(this)->FUN_0072ba80(reinterpret_cast<char*>(this->pBuffer + aiIndex), 1);

        reinterpret_cast<FUN_006dc6e0_Class*>(this)->BSSimpleArray_BSCompoundFrustum_FunctionOp_1024_MoveItems(reinterpret_cast<char*>(this->pBuffer + aiIndex),
                                                                  reinterpret_cast<char*>(this->pBuffer + aiIndex + 1),
                                                                  this->iSize - aiIndex - 1);
    }

    --this->iSize;
}




// @fnv 0x0069cea0
template <>
void __thiscall BSSimpleArray<CombatSearchDoor, 1024>::SetSize(unsigned int aiNewSize, bool abFreeMemory)
{
    if (aiNewSize == 0)
    {
        Clear(abFreeMemory);
    }
    else if (aiNewSize > SimpleArrayStorage)
    {
        if (SimpleArrayStorage == 0)
        {
            pBuffer = _Allocate(aiNewSize);
            SimpleArrayStorage = aiNewSize;
        }
        else
        {
            ReallocateStorage(aiNewSize, iSize);
            SimpleArrayStorage = aiNewSize;
        }

        InitializeItems((CombatSearchDoor*)((char*)pBuffer + iSize * sizeof(CombatSearchDoor)), aiNewSize - iSize);
        iSize = aiNewSize;
    }
    else if (aiNewSize < iSize)
    {
        ReleaseElements((CombatSearchDoor*)((char*)pBuffer + aiNewSize * sizeof(CombatSearchDoor)), iSize - aiNewSize);
        iSize = aiNewSize;

        if (abFreeMemory && aiNewSize <= SimpleArrayStorage / 4)
        {
            ReallocateStorage(aiNewSize, aiNewSize);
            SimpleArrayStorage = aiNewSize;
        }
    }
    else
    {
        InitializeItems((CombatSearchDoor*)((char*)pBuffer + iSize * sizeof(CombatSearchDoor)), aiNewSize - iSize);
        iSize = aiNewSize;
    }
}


// @fnv 0x006a6660
template <>
void BSSimpleArray<NiColorA, 1024>::SetSize(unsigned int newSize, bool freeMemory)
{
    if (newSize == 0)
    {
        Clear(freeMemory);
    }
    else if (newSize > SimpleArrayStorage)
    {
        if (SimpleArrayStorage == 0)
        {
            pBuffer = _Allocate(newSize);
            SimpleArrayStorage = newSize;
        }
        else
        {
            ReallocateStorage(newSize, iSize);
            SimpleArrayStorage = newSize;
        }

        InitializeItems(pBuffer + iSize, newSize - iSize);
        iSize = newSize;
    }
    else if (newSize < iSize)
    {
        ReleaseElements(pBuffer + newSize, iSize - newSize);
        iSize = newSize;

        if (freeMemory && newSize <= SimpleArrayStorage / 4)
        {
            ReallocateStorage(newSize, newSize);
            SimpleArrayStorage = newSize;
        }
    }
    else
    {
        InitializeItems(pBuffer + iSize, newSize - iSize);
        iSize = newSize;
    }
}


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

// @fnv 0x006cf200
FUN_006cf200::FUN_006cf200()
{
    vfptr = (int*)&DAT_0106c954;
    ((FUN_006d0310_Class*)this)->BSSimpleArray_NavMeshEdgeLocation_1024_InitialSetup(0, 0);
}

// @fnv 0x006cf670
template <>
// src: XBOX_PDB 0x006cf670
void* __thiscall BSScrapArray<unsigned char>::BSScrapArray_bool_1024_Allocate(unsigned int size)
{
    void* result;
    result = m_pPoolBase->Allocate(size, DAT_010a2720);
    return result;
}

// @fnv 0x006cf820
template <>
BSSimpleArray<PathBuilder::VirtualNodeSegment, 1024>::~BSSimpleArray()
{
    Clear(true);
}


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

// Copies the base EH part and the m_Location sub-object from aLocation into this object and returns *this.
// @fnv 0x006cf900
// src: GUESS 0x006cf900 (confidence: medium)
FUN_006cf900_Class& FUN_006cf900_Class::CopyFields_006cf900(const FUN_006cf900_Class* aLocation)
{
    EH::operator=(*aLocation);
    m_Location = aLocation->m_Location;
    return *this;
}

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

typedef BSSimpleArray<PacketNodeRecord, 1024> FUN_006e90a0_class;


// @fnv 0x006e90a0
template <> void BSSimpleArray<PacketNodeRecord, 1024>::SetSize(unsigned int aiNewSize, bool abFreeMemory)
{
    if (aiNewSize == 0)
    {
        reinterpret_cast<PSClearStub*>(this)->Clear(abFreeMemory);
    }
    else if (aiNewSize > this->SimpleArrayStorage)
    {
        if (this->SimpleArrayStorage == 0)
        {
            this->pBuffer = this->_Allocate(aiNewSize);
            this->SimpleArrayStorage = aiNewSize;
        }
        else
        {
            reinterpret_cast<S5460Helper*>(this)->BSSimpleArray_VirtualPathingNode_1024_ReallocateBuffer(aiNewSize, this->iSize);
            this->SimpleArrayStorage = aiNewSize;
        }

        reinterpret_cast<SaveGameSizeState*>(this)->BSSimpleArray_VirtualPathingNode_1024_ConstructItems(
            reinterpret_cast<unsigned int>(this->pBuffer + this->iSize * 0x30), aiNewSize - this->iSize);
        this->iSize = aiNewSize;
    }
    else if (aiNewSize < this->iSize)
    {
        reinterpret_cast<BSSimpleArray<PacketNodeRecord, 1024>*>(this)->ReleaseElements(this->pBuffer + aiNewSize * 0x30,
                                                                         this->iSize - aiNewSize);
        this->iSize = aiNewSize;

        if (abFreeMemory && aiNewSize <= this->SimpleArrayStorage / 4)
        {
            reinterpret_cast<S5460Helper*>(this)->BSSimpleArray_VirtualPathingNode_1024_ReallocateBuffer(aiNewSize, aiNewSize);
            this->SimpleArrayStorage = aiNewSize;
        }
    }
    else
    {
        reinterpret_cast<SaveGameSizeState*>(this)->BSSimpleArray_VirtualPathingNode_1024_ConstructItems(
            reinterpret_cast<unsigned int>(this->pBuffer + this->iSize * 0x30), aiNewSize - this->iSize);
        this->iSize = aiNewSize;
    }
}

struct FUN_006e9080
{
    virtual ~FUN_006e9080();
};
struct FUN_006e94d0 : FUN_006e9080
{
    void* FUN_006e94d0_006e94d0(unsigned int flags);
};
// @fnv 0x006e94d0
void* FUN_006e94d0::FUN_006e94d0_006e94d0(unsigned int flags)
{
    this->FUN_006e9080::~FUN_006e9080();
    if (flags & 1)
        operator delete(this);
    return this;
}

class NavMeshInfo;

// @fnv 0x006f2290
template <>
void BSSimpleArray<NavMeshInfo*, 1024>::SetSize(unsigned int aiNewSize, bool abFreeMemory)
{
    if (aiNewSize == 0)
    {
        Clear(abFreeMemory);
    }
    else if (aiNewSize > SimpleArrayStorage)
    {
        if (SimpleArrayStorage == 0)
        {
            pBuffer = _Allocate(aiNewSize);
            SimpleArrayStorage = aiNewSize;
        }
        else
        {
            ReallocateStorage(aiNewSize, iSize);
            SimpleArrayStorage = aiNewSize;
        }

        InitializeItems(pBuffer + iSize, aiNewSize - iSize);
        iSize = aiNewSize;
    }
    else if (aiNewSize < iSize)
    {
        ReleaseElements(pBuffer + aiNewSize, iSize - aiNewSize);
        iSize = aiNewSize;

        if (abFreeMemory && aiNewSize <= SimpleArrayStorage / 4)
        {
            ReallocateStorage(aiNewSize, aiNewSize);
            SimpleArrayStorage = aiNewSize;
        }
    }
    else
    {
        InitializeItems(pBuffer + iSize, aiNewSize - iSize);
        iSize = aiNewSize;
    }
}


// Resizes the array to count elements: clears when count is 0, grows the buffer when needed, shrinks and optionally frees excess capacity.
// @fnv 0x006f4480
template <>
void BSSimpleArray<PathSmoother::AvoidNode, 1024>::SetSize(unsigned int count, bool freeMemory)
{
    if (count == 0)
    {
        Clear(freeMemory);
    }
    else if (count > SimpleArrayStorage)
    {
        if (SimpleArrayStorage == 0)
        {
            pBuffer = _Allocate(count);
            SimpleArrayStorage = count;
        }
        else
        {
            ReallocateStorage(count, iSize);
            SimpleArrayStorage = count;
        }

        InitializeItems(
            reinterpret_cast<PathSmoother::AvoidNode*>(reinterpret_cast<char*>(pBuffer) + iSize * 16), count - iSize);
        iSize = count;
    }
    else if (count < iSize)
    {
        ReleaseElements(reinterpret_cast<PathSmoother::AvoidNode*>(reinterpret_cast<char*>(pBuffer) + count * 16),
                        iSize - count);
        iSize = count;

        if (freeMemory && count <= SimpleArrayStorage / 4)
        {
            ReallocateStorage(count, count);
            SimpleArrayStorage = count;
        }
    }
    else
    {
        InitializeItems(
            reinterpret_cast<PathSmoother::AvoidNode*>(reinterpret_cast<char*>(pBuffer) + iSize * 16), count - iSize);
        iSize = count;
    }
}


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

// Removes the element at aiIndex from the buffer, optionally reallocating to a smaller size and shifting the remaining elements down.
// @fnv 0x006bf8f0
// src: XBOX_PDB 0x006bf8f0
void __thiscall FUN_006bf8f0_Class::BSSimpleArray_HUDMainMenu_SubtitleData_1024_Remove(unsigned int aiIndex, bool abShrink)
{
    unsigned int inewSize;
    char* pnewBuffer;

    if (abShrink && reinterpret_cast<FUN_006f3170_Class*>(this)->BSSimpleArray_HasSufficientCapacity())
    {
        inewSize = reinterpret_cast<FUN_00869600_Class*>(this)->BSSimpleArray_GetOptimalCapacity();
        pnewBuffer = FUN_006bf8f0_reallocate(inewSize);

        reinterpret_cast<FUN_0042fb60_shell*>(this)->FUN_0042fb60(pnewBuffer, pBuffer, aiIndex);

        reinterpret_cast<FUN_0072ba80_shell*>(this)->FUN_0072ba80(pBuffer + aiIndex * 4, 1);

        reinterpret_cast<FUN_0042fb60_shell*>(this)->FUN_0042fb60(pnewBuffer + aiIndex * 4, pBuffer + aiIndex * 4 + 4,
                                                                  iSize - 1);

        FreeSimpleArrayStorage(this);

        pBuffer = pnewBuffer;
        SimpleArrayStorage = inewSize;
    }
    else
    {
        reinterpret_cast<FUN_0072ba80_shell*>(this)->FUN_0072ba80(pBuffer + aiIndex * 4, 1);

        reinterpret_cast<FUN_0042fb60_shell*>(this)->FUN_0042fb60(pBuffer + aiIndex * 4, pBuffer + aiIndex * 4 + 4,
                                                                  iSize - aiIndex - 1);
    }

    iSize--;
}

struct FUN_006a2270_class
{
    void BSSimpleArray_PathingNode_1024_CopyItems(char* pDest, char* pSource, unsigned int ItemUpdateArray);
};

// @fnv 0x006cf000
template <>
void BSSimpleArray<PathingGraphNode, 1024>::RemoveAt(unsigned int uiIndex, bool bCondition)
{
    PathingGraphNode* newBuffer;

    if (bCondition && reinterpret_cast<FUN_006f3170_Class*>(this)->BSSimpleArray_HasSufficientCapacity())
    {
        unsigned int newSize = reinterpret_cast<FUN_00869600_Class*>(this)->BSSimpleArray_GetOptimalCapacity();
        newBuffer = this->_Allocate(newSize);

        reinterpret_cast<FUN_006a2270_class*>(this)->BSSimpleArray_PathingNode_1024_CopyItems(reinterpret_cast<char*>(newBuffer),
                                                                  reinterpret_cast<char*>(this->pBuffer), uiIndex);

        ReleaseElements(this->pBuffer + uiIndex, 1);

        reinterpret_cast<FUN_006a2270_class*>(this)->BSSimpleArray_PathingNode_1024_CopyItems(reinterpret_cast<char*>(newBuffer + uiIndex),
                                                                  reinterpret_cast<char*>(this->pBuffer + uiIndex + 1),
                                                                  this->iSize - 1);

        FreeSimpleArrayStorage(this);

        this->pBuffer = newBuffer;
        this->SimpleArrayStorage = newSize;
    }
    else
    {
        ReleaseElements(this->pBuffer + uiIndex, 1);

        reinterpret_cast<FUN_006a2270_class*>(this)->BSSimpleArray_PathingNode_1024_CopyItems(reinterpret_cast<char*>(this->pBuffer + uiIndex),
                                                                  reinterpret_cast<char*>(this->pBuffer + uiIndex + 1),
                                                                  this->iSize - uiIndex - 1);
    }

    this->iSize = this->iSize - 1;
}

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

// @fnv 0x006e3ad0
void BSSimpleArray_PathingAvoidNode_1024::SetSize(unsigned int aiNewSize, bool abFreeMemory)
{
    if (aiNewSize == 0)
    {
        ((BSSimpleArray<PathingAvoidNode, 1024>*)this)->Clear(abFreeMemory);
        return;
    }

    if (aiNewSize > SimpleArrayStorage)
    {
        if (SimpleArrayStorage == 0)
        {
            pBuffer = (PathingAvoidNode*)Allocate(aiNewSize);
            SimpleArrayStorage = aiNewSize;
        }
        else
        {
            ((S5460_FUN_006e3d30_Helper*)this)->BSSimpleArray_PathingAvoidNode_1024_ReallocateBuffer(aiNewSize, iSize);
            SimpleArrayStorage = aiNewSize;
        }

        InitializeItems(pBuffer + iSize, aiNewSize - iSize);
        iSize = aiNewSize;
    }
    else
    {
        if (aiNewSize < iSize)
        {
            ((FUN_0072ba80_shell*)this)->FUN_0072ba80((char*)(pBuffer + aiNewSize), iSize - aiNewSize);
            iSize = aiNewSize;

            if (abFreeMemory && aiNewSize <= SimpleArrayStorage / 4)
            {
                ((S5460_FUN_006e3d30_Helper*)this)->BSSimpleArray_PathingAvoidNode_1024_ReallocateBuffer(aiNewSize, aiNewSize);
                SimpleArrayStorage = aiNewSize;
            }
        }
        else
        {
            InitializeItems(pBuffer + iSize, aiNewSize - iSize);
            iSize = aiNewSize;
        }
    }
}

class SandBoxChoiceListItem;

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

// @fnv 0x009f6200
// src: XBOX_PDB 0x009f6200
void FUN_009f6200_Class::BSSimpleArray_SandBoxChoiceListItem_1024_SetSize(unsigned int aiNewSize, bool abFreeMemory)
{
    if (aiNewSize == 0)
    {
        reinterpret_cast<BSSimpleArray<SandBoxChoiceListItem, 1024>*>(this)->Clear(abFreeMemory);
        return;
    }

    if (aiNewSize > SimpleArrayStorage)
    {
        if (SimpleArrayStorage == 0)
        {
            pBuffer = static_cast<char*>(FUN_009f6200_v1(aiNewSize));
            SimpleArrayStorage = aiNewSize;
        }
        else
        {
            reinterpret_cast<FUN_009f6540_Helper*>(this)->BSSimpleArray_TeleportLink_1024_ReallocateBuffer(aiNewSize, iSize);
            SimpleArrayStorage = aiNewSize;
        }

        reinterpret_cast<Host9f6340*>(this)->BSSimpleArray_SandBoxChoiceListItem_1024_ConstructItems(reinterpret_cast<int>(pBuffer + iSize * 16),
                                                          static_cast<int>(aiNewSize - iSize));
        iSize = aiNewSize;
    }
    else if (aiNewSize < iSize)
    {
        reinterpret_cast<FUN_0072ba80_shell*>(this)->FUN_0072ba80(pBuffer + aiNewSize * 16, iSize - aiNewSize);
        iSize = aiNewSize;

        if (abFreeMemory && aiNewSize <= (SimpleArrayStorage >> 2))
        {
            reinterpret_cast<FUN_009f6540_Helper*>(this)->BSSimpleArray_TeleportLink_1024_ReallocateBuffer(aiNewSize, aiNewSize);
            SimpleArrayStorage = aiNewSize;
        }
    }
    else
    {
        reinterpret_cast<Host9f6340*>(this)->BSSimpleArray_SandBoxChoiceListItem_1024_ConstructItems(reinterpret_cast<int>(pBuffer + iSize * 16),
                                                          static_cast<int>(aiNewSize - iSize));
        iSize = aiNewSize;
    }
}

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

// @fnv 0x0069cfe0
void FUN_0069cfe0_cls::CopyElementsTo(FUN_0069cfe0_Dst* dst)
{
    dst->FUN_0069cea0(this->m_08, 1);
    for (unsigned int i = 0; i < this->m_08; i++)
    {
        *dst->Object_GetIndexedValue_006a1440(i) = *(this->m_04 + i);
    }
}

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

// Sets the vtable, stores heap or a default heap from FUN_00401020, then calls FUN_006b3eb0 with first and second.
// @fnv 0x006cf2a0
FUN_006cf2a0::FUN_006cf2a0(int first, int second, void* heap)
{
    m_vftable = &DAT_0106c968;
    m_pStreamAllocator = heap ? heap : MemoryManager_Instance()->FUN_00aa42e0();
    BSSimpleArray_float_1024_InitialSetup(first, second);
}

namespace fnv_006cf3a0 {
struct DefaultPathSource
{
    void* FUN_00aa42e0();
};
DefaultPathSource* __cdecl MemoryManager_Instance();
struct FUN_005e04c0
{
    FUN_005e04c0();
    virtual ~FUN_005e04c0();
};
struct FUN_006cf3a0 : FUN_005e04c0
{
    int unk04;
    int unk08;
    int unk0c;
    void* unk10;
    FUN_006cf3a0(int arg1, int arg2, void* source);
    virtual ~FUN_006cf3a0();
    void BSSimpleArray_float_1024_InitialSetup(int arg1, int arg2);
};
// @fnv 0x006cf3a0
FUN_006cf3a0::FUN_006cf3a0(int arg1, int arg2, void* source) : FUN_005e04c0()
{
    unk10 = source ? source : MemoryManager_Instance()->FUN_00aa42e0();
    BSSimpleArray_float_1024_InitialSetup(arg1, arg2);
}
}  // namespace fnv_006cf3a0

struct FUN_006cf700_cls
{
    int m_00;
    int m_04;
    unsigned int m_08;
    int FindIndexIf(int a, unsigned int start, bool (*pred)(int, int));
};

// Scans indices from start up to m_08 and returns the first i where pred(m_04 + i, a) is true, or -1 if none match.
// @fnv 0x006cf700
int FUN_006cf700_cls::FindIndexIf(int aiValue, unsigned int start, bool (*pred)(int, int))
{
    unsigned int i;
    for (i = start; i < m_08; i++)
    {
        if (m_04 != 0)
        {
            if (pred(m_04 + i, aiValue))
            {
                return i;
            }
        }
    }
    return -1;
}

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

// Calls Prepare with iCount and 1, then for each item calls ProcessItem and invokes FUN_006cf900 on the result.
// @fnv 0x006cf8a0
void FUN_006cf8a0_cls::ProcessItems(ParamHost* pHost)
{
    pHost->Prepare(iCount, 1);
    for (unsigned int i = 0; i < iCount; i++)
    {
        ((ItemFinish*)pHost->ProcessItem(i, &pItems[i]))->CopyFields_006cf900();
    }
}

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

// @fnv 0x006cf940
// src: COMMUNITY 0x006cf940
void FUN_006cf940_cls::BSSimpleArray_CopyTo_0(FUN_006cf940_Owner* pOwner)
{
    pOwner->ResizeArrayStorage(this->m_08, 1);
    for (unsigned int i = 0; i < this->m_08; ++i)
    {
        pOwner->FUN_00691750(i, this->m_04 + i * 0x28)->FUN_006dcce0();
    }
}

namespace fnv_006cfa00 {
extern int DAT_0106c9cc;

class FUN_006cfa00_base
{
  public:
    virtual void v00();
    int m_04;
    int m_08;
    int m_0c;

    FUN_006cfa00_base();
    ~FUN_006cfa00_base();
};

struct FUN_00aa42e0_cls
{
    int FUN_00aa42e0();
};

void* __cdecl MemoryManager_Instance();

class FUN_006cfa00 : public FUN_006cfa00_base
{
  public:
    int m_10;

    void BSSimpleArray_NavMeshTriHandle_1024_InitialSetup(int a, int b);

    FUN_006cfa00(int a1, int a2, int a3);
};

// Sets m_10 to a3, or to the result of FUN_00aa42e0 when a3 is zero, then calls FUN_006dc440 with a1 and a2.
// @fnv 0x006cfa00
FUN_006cfa00::FUN_006cfa00(int aiFirst, int aiSecond, int aiValue)
{
    m_10 = (aiValue != 0) ? aiValue : ((FUN_00aa42e0_cls*)MemoryManager_Instance())->FUN_00aa42e0();
    BSSimpleArray_NavMeshTriHandle_1024_InitialSetup(aiFirst, aiSecond);
}
}  // namespace fnv_006cfa00

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

// Destructor that calls FUN_008454f0 with flag 1.
// @fnv 0x006cfac0
FUN_006cfac0_cls::~FUN_006cfac0_cls()
{
    this->FUN_008454f0(1);
}

namespace fnv_006cfb20 {
extern int DAT_0106c9f4;

struct FUN_00694de0_base
{
    FUN_00694de0_base();
    ~FUN_00694de0_base();
};

struct FUN_00aa42e0_obj
{
    void* __thiscall FUN_00aa42e0();
};

FUN_00aa42e0_obj* __cdecl MemoryManager_Instance();

struct FUN_006cfb20_cls : FUN_00694de0_base
{
    int* vfptr;
    int unk04;
    int unk08;
    int unk0c;
    void* m_10;

    void BSSimpleArray_float_1024_InitialSetup(int a, int b);
    FUN_006cfb20_cls(int a, int b, void* c);
};

// Constructor: sets vfptr, stores c (or a default from FUN_00401020) in m_10, then calls FUN_006b3eb0(a, b).
// @fnv 0x006cfb20
FUN_006cfb20_cls::FUN_006cfb20_cls(int aiArg1, int aiArg2, void* apData)
{
    vfptr = (int*)&DAT_0106c9f4;
    m_10 = apData != 0 ? apData : MemoryManager_Instance()->FUN_00aa42e0();
    BSSimpleArray_float_1024_InitialSetup(aiArg1, aiArg2);
}
}  // namespace fnv_006cfb20

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
};

struct FUN_006cfe70_Class : public FUN_006d0540_shell
{
    void __thiscall BSSimpleArray_VirtualPathingNode_1024_ReallocateBuffer(int value, int count);
};

// @fnv 0x006cfe70
// src: COMMUNITY 0x006cfe70
void __thiscall FUN_006cfe70_Class::BSSimpleArray_VirtualPathingNode_1024_ReallocateBuffer(int value, int count)
{
    if (this->unk04 != 0)
    {
        if (count == this->unk0c)
        {
            this->unk04 = this->vf0c(this->unk04, value);
        }
        else
        {
            void* newItem = this->vf04(value);
            this->CopyOverlappingElements30(newItem, this->unk04, count);
            FreeSimpleArrayStorage(this);
            this->unk04 = newItem;
        }
    }
    else
    {
        this->unk04 = this->vf04(value);
        this->unk0c = value;
    }
}

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

// Placement-constructs count SpawnedObject9 instances at 0x24-byte strides starting at base.
// @fnv 0x006e3c90
void FUN_006e3c90_cls::ConstructSpawnedObjects(char* base, unsigned int count)
{
    for (unsigned int i = 0; i < count; i++)
    {
        new (base + i * 0x24) SpawnedObject9();
    }
}

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

// @fnv 0x006e9470
// src: COMMUNITY 0x006e9470
void FUN_006e9470_cls::BSSimpleArray_PathingNode_1024_Copy(FUN_006e9470_Helper* pHelper)
{
    pHelper->BSSimpleArray_PathingNode_1024_SetSize(m_08, 1);
    for (unsigned int i = 0; i < m_08; i++)
    {
        ((FUN_006e9470_Obj*)pHelper->GetPathingGraphNodeAddress(i, m_04 + i * 60))->FUN_006e9570();
    }
}

struct S_00a0d000_Class
{
    virtual unsigned int ReserveSlotAndIncrementSize();
    virtual void* FUN_00a0d010(unsigned int size);

    void* pBuffer;
    unsigned int m_uiSize;
    unsigned int m_uiReservedSize;

    void UpdateFields_00a0d0c0(unsigned int newCapacity, unsigned int copyCount);
};

// Grows the buffer when size equals reserved size, then increments m_uiSize and returns the index of the newly added slot.
// @fnv 0x00a0d000
// src: GUESS 0x00a0d000 (confidence: medium)
unsigned int S_00a0d000_Class::ReserveSlotAndIncrementSize()
{
    unsigned int allocationSize;
    unsigned int newCapacity;
    bool bFull2;
    struct FramePad
    {
        unsigned int unk00;
        unsigned int unk04;
        unsigned int unk08;
    };
    FramePad framePad;
    if (this->m_uiSize == this->m_uiReservedSize)
        bFull2 = true;
    else
        bFull2 = false;

    if (bFull2)
    {
        if (this->m_uiReservedSize == 0)
        {
            allocationSize = 4;
            this->pBuffer = this->FUN_00a0d010(allocationSize);
            this->m_uiReservedSize = allocationSize;
        }
        else
        {
            newCapacity = (this->m_uiReservedSize > 8) ? this->m_uiReservedSize + 8 : this->m_uiReservedSize << 1;
            this->UpdateFields_00a0d0c0(newCapacity, this->m_uiSize);
            this->m_uiReservedSize = newCapacity;
        }
    }

    this->m_uiSize++;
    return this->m_uiSize - 1;
}

struct FUN_006cf230
{
    virtual ~FUN_006cf230();
    void Clear(bool abFree);
};

// @fnv 0x006cf230
FUN_006cf230::~FUN_006cf230()
{
    Clear(true);
}

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
    FUN_006cf780_Pool(int iCapacity, int iGrowBy, ScrapHeapBuffer* pkAllocator);
    virtual ~FUN_006cf780_Pool();

    void Initialize(int iCapacity, int iGrowBy);

    ScrapHeapBuffer* m_pHeapAllocator;
};

// Stores the given allocator, or the memory manager's default allocator when none is given, then initializes the pool with the capacity and grow-by values.
// @fnv 0x006cf780
FUN_006cf780_Pool::FUN_006cf780_Pool(int iCapacity, int iGrowBy, ScrapHeapBuffer* pkAllocator)
{
    m_pHeapAllocator = pkAllocator ? pkAllocator : MemoryManager::GetSingleton().GetGeneralAllocator();
    Initialize(iCapacity, iGrowBy);
}

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

// Destructor that calls Clear(true) to free the object's resources.
// @fnv 0x006cfbc0
FUN_006cfbc0::~FUN_006cfbc0()
{
    Clear(true);
}

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

// @fnv 0x006e9280
// src: XBOX_PDB 0x006e9280
void FUN_006e9280_shell::BSSimpleArray_PathingNode_1024_SetSize(unsigned int uiNewSize, bool bShrink)
{
    if (uiNewSize == 0)
    {
        ((PSNodeStub*)this)->FUN_006cf120(bShrink);
    }
    else if (uiNewSize > m_uiCapacity)
    {
        if (m_uiCapacity == 0)
        {
            m_pBuffer = Allocate(uiNewSize);
            m_uiCapacity = uiNewSize;
        }
        else
        {
            BSSimpleArray_PathingNode_1024_ReallocateBuffer(uiNewSize, m_uiSize);
            m_uiCapacity = uiNewSize;
        }
        ConstructArray(&m_pBuffer[m_uiSize], uiNewSize - m_uiSize);
        m_uiSize = uiNewSize;
    }
    else if (uiNewSize < m_uiSize)
    {
        FUN_006cff20(&m_pBuffer[uiNewSize], m_uiSize - uiNewSize);
        m_uiSize = uiNewSize;
        if (bShrink && uiNewSize <= m_uiCapacity >> 2)
        {
            BSSimpleArray_PathingNode_1024_ReallocateBuffer(uiNewSize, uiNewSize);
            m_uiCapacity = uiNewSize;
        }
    }
    else
    {
        ConstructArray(&m_pBuffer[m_uiSize], uiNewSize - m_uiSize);
        m_uiSize = uiNewSize;
    }
}

struct FUN_006d0420_Base
{
    virtual ~FUN_006d0420_Base();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FUN_006d0420_Base();
};
struct FUN_006cf570 : FUN_006d0420_Base
{
    void* m_pThreadAllocator;
    FUN_006cf570(unsigned int initialSize, unsigned int growth, void* allocator);
    virtual ~FUN_006cf570();
    void __thiscall BSSimpleArray_char_1024_InitialSetup(unsigned int initialSize, unsigned int growth);
};
// @fnv 0x006cf570
FUN_006cf570::FUN_006cf570(unsigned int initialSize, unsigned int growth, void* allocator) : FUN_006d0420_Base()
{
    m_pThreadAllocator = allocator ? allocator : MemoryManager_Instance()->FUN_00aa42e0();
    BSSimpleArray_char_1024_InitialSetup(initialSize, growth);
}

struct FUN_0069f920_Sub
{
    void* __thiscall ProcessAndReturnValue_006a1920();
    void* __thiscall GetPathingGraphNodeAddress(unsigned int);
};
struct FUN_006e2280
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38;
    FUN_006e2280(int, int);
};
void* __cdecl operator new(unsigned int, void*);
void __cdecl operator delete(void*, void*);
struct FUN_0069f920_cls
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    FUN_0069f920_Sub unk20;
    void* __thiscall PathingSolution_AddPathingNode(int, int);
};
// Calls unk20.FUN_006a1920 for a node, constructs FUN_006e2280(a, b) at the address FUN_006e8f80 returns for it, and returns the node.
// @fnv 0x0069f920
// src: COMMUNITY 0x0069f920
void* __thiscall FUN_0069f920_cls::PathingSolution_AddPathingNode(int aiArg1, int aiArg2)
{
    void* pNode = unk20.ProcessAndReturnValue_006a1920();
    void* pPlace = unk20.GetPathingGraphNodeAddress((unsigned int)pNode);
    new (pPlace) FUN_006e2280(aiArg1, aiArg2);
    return pNode;
}

struct FUN_009f6500
{
    char data[16];
    FUN_009f6500();
};

// Calls the FUN_009f6500 placement constructor on each 16-byte element of the arr array, count times.
// @fnv 0x009f6460
// src: XBOX_PDB 0x009f6460
void Host9f6340::BSSimpleArray_SandBoxChoiceListItem_1024_ConstructItems(int arr, int count)
{
    for (unsigned int i = 0; i < (unsigned int)count; ++i)
    {
        new ((void*)(arr + i * 16)) FUN_009f6500();
    }
}
