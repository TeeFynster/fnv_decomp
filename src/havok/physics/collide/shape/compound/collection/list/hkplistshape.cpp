// src/havok/physics/collide/shape/compound/collection/list/hkplistshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/compound/collection/list/hkplistshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Keep the unit's original intrinsic type; the CRT adds byte arrays that alter /GS analysis.
#define _INCLUDED_MM2
// Exe 0x00cf5590 FUN_00cf5590: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C"
{
    LocalM128 _mm_cmple_ps(LocalM128 a, LocalM128 b);
    int _mm_movemask_ps(LocalM128 a);
    LocalM128 _mm_set_ps1(float a);
    LocalM128 _mm_xor_ps(LocalM128 a, LocalM128 b);
    LocalM128 _mm_min_ps(LocalM128 a, LocalM128 b);
    LocalM128 _mm_max_ps(LocalM128 a, LocalM128 b);
}
#include "../../../../../../../../include/hkArray.h"
#include "../../../../../../../../include/hkBaseObject.h"
#include "../../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../../include/hkpShape.h"
#include "../../../../../../../../include/hkpShapeContainer.h"
#include "../../../../../../../../include/hkpShapeCollection.h"
#include "../../../../../../../../include/hkClass.h"
#include "../../../../../../../../include/hkStatisticsCollector.h"
#include "../../../../../../../../include/hkBool.h"
#include "../../../../../../../../include/hkVector4.h"
#include "../../../../../../../../include/hkpListShapeChildInfo.h"
#include "../../../../../../../../include/hkpListShape.h"
#include "../../../../../../../../include/hkpCdBody.h"
#include "../../../../../../../../include/hkVector4q.h"

struct hkPListShape
{
    void __thiscall SetChildShape(int index, void* shape);
};
// @fnv 0x00cf50a0
void __thiscall hkPListShape::SetChildShape(int index, void* shape)
{
    *(void**)((char*)*(int*)((char*)this + 0x18) + (index << 4) + 4) = shape;
}

struct FUN_00cf5070_class
{
    void* GetShapeAt(int index, void* buffer);
};

// @fnv 0x00cf5070
void* FUN_00cf5070_class::GetShapeAt(int index, void* buffer)
{
    void** shapes = *(void***)((char*)this + 8);
    return *(void**)((char*)shapes + (index << 4));
}

struct hkPListShape2
{
    int __thiscall GetElementAt(int index);
};

// @fnv 0x00cf5080
int hkPListShape2::GetElementAt(int index)
{
    return *(int*)(*(int*)((char*)this + 8) + (index << 4) + 4);
}

struct S_00cf5880
{
    int unk0;
    void FindNextEnabledChild(int a);
    void FindNextEnabledChild_Thunk();
};
// @fnv 0x00cf5880
// src: GUESS 0x00cf5880 (confidence: medium)
void S_00cf5880::FindNextEnabledChild_Thunk()
{
    FindNextEnabledChild(-1);
}

struct __declspec(align(16)) BufAligned32
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

struct FUN_00cf4fb0_Obj
{
    void ProcessEntries_00cf4fb0(void* a1);
};

struct FUN_00cf5420_class
{
    void hkpListShape_recalcAabbExtents();
};

// @fnv 0x00cf5420
// src: HAVOK_LIB 0x00cf5420
void FUN_00cf5420_class::hkpListShape_recalcAabbExtents()
{
    BufAligned32 bufAligned;
    FUN_00cf4fb0_Obj* obj = (FUN_00cf4fb0_Obj*)this;
    obj->ProcessEntries_00cf4fb0(&bufAligned);
}

extern const hkClass DAT_01269198;

int __cdecl hkStatisticsCollector_getAllocatedSize(const void* pvChunk, int iNumBytes) throw();

template <class T, class Allocator>
void hkStatisticsCollector::addArray(const char* pcName, const hkArray<T, Allocator>& kArray)
{
    if ((kArray.m_iCapacityState & 0x80000000) == 0 || m_reportInplaceAllocations)
    {
        const T* pData = kArray.m_data;
        int iAllocated = hkStatisticsCollector_getAllocatedSize(pData, kArray.getCapacity() * sizeof(T));
        AddMemoryChunk(3, pcName, kArray.m_data, kArray.GetLogicalSize() * sizeof(T), iAllocated);
    }
}

// The shared list/collection headers lack these statistics overrides; this extension adds no layout.
// CollectBaseStatistics is the hkpShapeCollection statistics method at 0x00d213e0.
class ListShapeStatistics : public hkpListShape
{
  public:
    void CollectBaseStatistics(hkStatisticsCollector* pkCollector, const hkClass* pkClass) const throw();
    void AddChildObjectsToCollector(hkStatisticsCollector* pkCollector, const hkClass* pkClass) const throw();
};

// @fnv 0x00cf5440
void ListShapeStatistics::AddChildObjectsToCollector(hkStatisticsCollector* pkCollector, const hkClass* pkClass) const
    throw()
{
    pkCollector->addArray("ChildPtrs", m_kChildInfoList);
    for (int i = 0; i < m_kChildInfoList.GetLogicalSize(); i++)
        pkCollector->beginObject("Child", m_kChildInfoList.m_data[i].m_pCollisionShape, 0);
    CollectBaseStatistics(pkCollector, &DAT_01269198);
}

// These shared constructor bodies preserve the finishing constructor's uninitialized storage.
template <typename ENUM, typename STORAGE>
inline hkEnum<ENUM, STORAGE>::hkEnum() {}
template <typename ENUM, typename STORAGE>
inline hkEnum<ENUM, STORAGE>::hkEnum(ENUM value) : m_kStorage(value) {}
inline hkpShape::hkpShape(FinishingFlag flag) : hkReferencedObject(flag)
{
    if (flag.m_bFinishing)
        m_type = HK_SHAPE_INVALID;
}

// Retained collection finishing layout: hkpShapeCollection has no FinishingFlag constructor.
class ShapeCollectionFinishing : public hkpShape, public hkpShapeContainer
{
  public:
    hkBool m_bDisableWelding;
    unsigned char m_eCollectionType;

    ShapeCollectionFinishing(FinishingFlag flag) : hkpShape(flag)
    {
        if (flag.m_bFinishing)
        {
            m_type = HK_SHAPE_COLLECTION;
            m_eCollectionType = hkpShapeCollection::COLLECTION_USER;
        }
    }
};

class FUN_00cf56f0 : public ShapeCollectionFinishing
{
  public:
    FUN_00cf56f0(FinishingFlag flag) throw();
    virtual ~FUN_00cf56f0() throw();
    virtual void i0();
};

// @fnv 0x00cf56f0
FUN_00cf56f0::FUN_00cf56f0(FinishingFlag aFinishFlag) throw() : ShapeCollectionFinishing(aFinishFlag)
{
    if (aFinishFlag.m_bFinishing)
    {
        m_type = HK_SHAPE_LIST;
        m_eCollectionType = hkpShapeCollection::COLLECTION_LIST;
    }
}

struct hkListShapeCF58
{
    int unk00;
    int unk04;
    void* m_kChildInfoList;
    int m_childInfoSize;
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
    unsigned int m_uiChildEnabledFlags[8];

    unsigned int isChildEnabled(unsigned int index) const
    {
        if (index < 256)
            return m_uiChildEnabledFlags[index >> 5] & (1 << (index & 31));
        return 1;
    }

    int FindNextEnabledChild(int oldKey) const;
};

// Scans child indices after oldKey up to m_childInfoSize and returns the first enabled one, or -1 if none.
// @fnv 0x00cf5840
int hkListShapeCF58::FindNextEnabledChild(int oldKey) const
{
    for (int i = oldKey + 1; i < m_childInfoSize; i++)
    {
        if (isChildEnabled(i))
            return i;
    }
    return -1;
}

extern "C" hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();
struct FnvCpu_FUN_00cf5890_CpuObject
{
    unsigned int unk00;
    unsigned short size;
    void FUN_00cf5750();
    FnvCpu_FUN_00cf5890_CpuObject* Destroy(unsigned int flags);
};
// Calls FUN_00cf5750, then if flags has bit 0 set, invokes the allocator from FUN_00c85750 on this with size, and returns this.
// @fnv 0x00cf5890
FnvCpu_FUN_00cf5890_CpuObject* FnvCpu_FUN_00cf5890_CpuObject::Destroy(unsigned int flags)
{
    FUN_00cf5750();
    if (flags & 1)
    {
        hkMemoryRouter* pAllocatorHolder = hkMemoryRouter_getInstance();
        pAllocatorHolder->heap().blockFree(this, size);
    }
    return this;
}

void __cdecl hkArrayUtil__reserve(hkMemoryAllocator& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();


__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return hkMemoryRouter_getInstance()->heap();
}

template <class T>
__forceinline void hkArrayBase<T>::GrowArrayCapacity(hkMemoryAllocator& kAlloc, int n)
{
    const int iCap = getCapacity();
    if (iCap < n)
    {
        int iCap2 = 2 * iCap;
        int iNewCap = (n < iCap2) ? iCap2 : n;
        hkArrayUtil__reserve(kAlloc, this, iNewCap, sizeof(T));
    }
}

template <class T, class Allocator>
__forceinline hkArray<T, Allocator>::~hkArray()
{
    hkMemoryAllocator& alloc = Allocator().get(this);
    m_iElementCount = 0;
    if ((m_iCapacityState & 0x80000000) == 0)
        alloc.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
    m_data = 0;
    m_iCapacityState = 0x80000000;
}

// The shared collection lacks its (shape type, collection type) constructor at 0x00d21410.
// This constructor-only extension uses the shared collection layout.
class ShapeCollectionConstruction : public hkpShapeCollection
{
  public:
    ShapeCollectionConstruction(int iType, int iFlags) throw();
};

class FUN_00cf5640 : public ShapeCollectionConstruction
{
  public:
    hkArray<hkVector4> m_kPoints;
    short m_flags24;
    short m_flags26;
    int unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C;
    int m_aiIds[8];

    FUN_00cf5640(int iA, int iB, int iC) throw();
    void hkpListShape_setShapes(int iA, int iB, int iZero, int iC) throw();
};

// Constructs a shape by reserving 4 points, calling FUN_00cf54d0 with iA, iB, 0, iC, and initializing m_aiIds to -1 and flags to 0.
// @fnv 0x00cf5640
FUN_00cf5640::FUN_00cf5640(int iA, int iB, int iC) throw() : ShapeCollectionConstruction(9, 0)
{
    m_kPoints.reserve(4);
    hkpListShape_setShapes(iA, iB, 0, iC);
    for (int i = 0; i < 8; i++)
        m_aiIds[i] = -1;
    m_flags26 = 0;
    m_flags24 = 0;
}

struct ListShapeCF
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    hkArray<hkpListShapeChildInfo> m_kChildInfoList;
    int hkpListShape_calcSizeForSpu(const bool& input, int spuBufferSizeLeft);
};
// @fnv 0x00cf50c0
// src: HAVOK_LIB 0x00cf50c0
int ListShapeCF::hkpListShape_calcSizeForSpu(const bool& input, int spuBufferSizeLeft)
{
    if (input && m_kChildInfoList.GetLogicalSize() > 252)
        return -1;
    if (m_kChildInfoList.GetLogicalSize() >= 4095)
        return -1;
    for (int i = 0; i < m_kChildInfoList.GetLogicalSize(); i++)
    {
        m_kChildInfoList[i].m_iShapeKey = m_kChildInfoList[i].m_pCollisionShape->CalcSizeForSpu(reinterpret_cast<const hkpShape::PhysicsShape&>(input), 256);
        m_kChildInfoList[i].m_iChildShapeCount = m_kChildInfoList.GetLogicalSize();
        if (m_kChildInfoList[i].m_iShapeKey == -1)
            return -1;
    }
    return 0x70;
}

void __cdecl hkArrayUtil__reserve(void* allocator, void* array, int capacity, int elementSize);
void __cdecl hkReferencedObject_addReferences(void* data, int count, int elementSize);

struct ListShapeCF54 : public hkpListShape
{
    void hkpListShape_recalcAabbExtents();
    void hkpListShape_setShapes(int* shapes, int count, int* shapeData, int flag);
};

// Copies shape and filter data into m_kChildInfoList, growing capacity as needed, then calls FUN_00cf5420.
// @fnv 0x00cf54d0
// src: HAVOK_LIB 0x00cf54d0
void ListShapeCF54::hkpListShape_setShapes(int* shapes, int count, int* shapeData, int flag)
{
    hkArray<hkpListShapeChildInfo>& children = m_kChildInfoList;
    hkMemoryAllocator& heap = hkMemoryRouter_getInstance()->heap();
    int capacity = children.m_iCapacityState & 0x3fffffff;
    if (capacity < count)
    {
        int increasedCapacity = capacity * 2;
        if (count >= increasedCapacity)
            increasedCapacity = count;
        hkArrayUtil__reserve(&heap, &children, increasedCapacity, 16);
    }
    children.m_iElementCount = count;
    if (count > 0)
    {
        int* current = shapes;
        int offset = 0;
        volatile int difference = (int)shapeData - (int)shapes;
        int remaining = count;
        do
        {
            int shape = *current;
            if (shape)
            {
                *(int*)((char*)children.m_data + offset) = shape;
                int filter = shapeData ? *(int*)((char*)current + difference) : 0;
                *(int*)((char*)children.m_data + offset + 4) = filter;
                *(int*)((char*)this->m_kChildInfoList.m_data + offset + 12) = count;
                *(int*)((char*)this->m_kChildInfoList.m_data + offset + 8) = 0;
            }
            ++current;
            offset += 16;
        } while (--remaining);
    }
    if (flag == 1)
        hkReferencedObject_addReferences(children.m_data, this->m_kChildInfoList.m_iElementCount, 16);
    hkpListShape_recalcAabbExtents();
}

// Preserve uninitialized construction of the shared vector union member.

__forceinline void hkVector4q::setMin4(const hkVector4q& a, const hkVector4q& b)
{
    m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents);
}

__forceinline void hkVector4q::setMax4(const hkVector4q& a, const hkVector4q& b)
{
    m_vComponents = _mm_max_ps(a.m_vComponents, b.m_vComponents);
}

__forceinline int hkVector4q::compareLessThanEqual4(const hkVector4q& v) const
{
    return _mm_movemask_ps(_mm_cmple_ps(m_vComponents, v.m_vComponents));
}

extern const hkVector4q DAT_01267e30;  // HK_QUADREAL_MINUS1
extern const float DAT_010cc3b0;       // HK_REAL_MAX
extern const hkVector4q DAT_010c44d0;  // sign mask

__forceinline void hkVector4q::setNeg4(const hkVector4q& v)
{
    m_vComponents = _mm_xor_ps(v.m_vComponents, DAT_010c44d0.m_vComponents);
}

struct hkAabbq
{
    hkVector4q m_kMinimumCorner;
    hkVector4q m_kMaximumCorner;
};

class hkpListShapeq
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_usMemSizeAndFlags;
    unsigned int m_sReferenceCount;
    unsigned int m_ulUserData;
    unsigned int m_type;
    unsigned int unk14;
    hkArray<hkpListShapeChildInfo> m_kChildInfoList;
    unsigned short m_flags;
    unsigned short m_usNumDisabledChildren;
    unsigned int unk28;
    unsigned int unk2C;
    hkVector4q m_kAabbHalfExtents;
    hkVector4q m_kAabbCenter;

    void hkpListShape_recalcAabbExtents();
    void hkpListShape_getAabb(const hkTransform& localToWorld, float tolerance, hkAabbq& out);
};

// Computes the combined AABB of all child shapes by querying each child's AABB and merging the min and max corners.
// @fnv 0x00cf5590
// src: XBOX_PDB 0x00cf5590
void hkpListShapeq::hkpListShape_getAabb(const hkTransform& localToWorld, float tolerance, hkAabbq& out)
{
    if (m_kAabbHalfExtents.compareLessThanEqual4(DAT_01267e30) == 15)
    {
        hkpListShape_recalcAabbExtents();
    }

    out.m_kMinimumCorner.m_vComponents = _mm_set_ps1(1.70141001e+38f);
    out.m_kMaximumCorner.setNeg4(out.m_kMinimumCorner);

    for (int i = 0; i < m_kChildInfoList.m_iElementCount; i++)
    {
        hkAabbq childAabb;
        const hkpShape* childShape = m_kChildInfoList.m_data[i].m_pCollisionShape;
        childShape->CalculateAabb(localToWorld, tolerance, reinterpret_cast<hkAabb&>(childAabb));
        out.m_kMinimumCorner.setMin4(out.m_kMinimumCorner, childAabb.m_kMinimumCorner);
        out.m_kMaximumCorner.setMax4(out.m_kMaximumCorner, childAabb.m_kMaximumCorner);
    }
}

extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
#include <string.h>
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_0126835c;
extern const char str_010cc398[];
extern const char str_010c41f8[];

struct S00cf5140_Input
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
    const struct S00cf5140_Filter* m_pRayShapeCollectionFilter;
};

struct S00cf5140_Output
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    unsigned int m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;
};

struct S00cf5140_Filter
{
    virtual hkBool IsCollisionEnabled(const S00cf5140_Input& aInput, const hkpShape& shape,
                                              const hkpShapeContainer& container, unsigned int aKey) const;
};

struct S00cf5140_Stream
{
    int unk0;
    char* m_curr;
    int unk8;
    char* m_kRayEnd;

    void timerBegin(const char* name)
    {
        char* p = m_curr;
        if (p < m_kRayEnd)
        {
            *(const char**)p = name;
            _ReadWriteBarrier();
            unsigned int tb = (unsigned int)__rdtsc();
            _ReadWriteBarrier();
            *(unsigned int*)(p + 4) = *&tb;
            if (0)
                memmove(&tb, &tb, 4);
            p += 12;
            m_curr = p;
        }
    }

    void timerEnd()
    {
        char* p = m_curr;
        if (p < m_kRayEnd)
        {
            *(const char**)p = str_010c41f8;
            _ReadWriteBarrier();
            unsigned int te = (unsigned int)__rdtsc();
            _ReadWriteBarrier();
            *(unsigned int*)(p + 4) = *&te;
            if (0)
                memmove(&te, &te, 4);
            p += 12;
            m_curr = p;
        }
    }
};

struct S00cf5140_Obj : public hkpListShape
{
    unsigned int isChildEnabled(unsigned int i) const
    {
        if (i < 0x100)
        {
            return m_uiChildEnabledFlags[i >> 5] & (1 << (i & 0x1f));
        }
        return 1;
    }

    hkBool hkpListShape_castRayImpl(const S00cf5140_Input& input, S00cf5140_Output& results) const;
};

// Performs a ray cast against all enabled child shapes of this list shape, recording the hit child index in the output and returning whether any child was hit.
// @fnv 0x00cf5140
// src: HAVOK_LIB 0x00cf5140
hkBool S00cf5140_Obj::hkpListShape_castRayImpl(const S00cf5140_Input& input, S00cf5140_Output& results) const
{
    ((S00cf5140_Stream*)TlsGetValue(DAT_0126835c))->timerBegin(str_010cc398);

    results.m_uiShapeKeyIndex++;
    int hitChild = -1;

    if (!input.m_pRayShapeCollectionFilter)
    {
        for (unsigned int i = 0; (int)i < m_kChildInfoList.m_iElementCount; i++)
        {
            if (isChildEnabled(i))
            {
                const hkpShape* child = m_kChildInfoList.m_data[i].m_pCollisionShape;
                hkBool hit = child->IntersectRayWithShape(reinterpret_cast<const ShapeRayCastQuery&>(input), reinterpret_cast<ShapeRayCastOutput&>(results));
                if (hit)
                {
                    hitChild = i;
                }
            }
        }
    }
    else
    {
        for (unsigned int i = 0; (int)i < m_kChildInfoList.m_iElementCount; i++)
        {
            if (isChildEnabled(i))
            {
                if (input.m_pRayShapeCollectionFilter->IsCollisionEnabled(
                        input, *this, *static_cast<const hkpShapeContainer*>(this), i))
                {
                    const hkpShape* child = m_kChildInfoList.m_data[i].m_pCollisionShape;
                    hkBool hit = child->IntersectRayWithShape(reinterpret_cast<const ShapeRayCastQuery&>(input), reinterpret_cast<ShapeRayCastOutput&>(results));
                    if (hit)
                    {
                        hitChild = i;
                    }
                }
            }
        }
    }

    results.m_uiShapeKeyIndex--;
    if (hitChild != -1)
    {
        results.m_uiShapeKeys[results.m_uiShapeKeyIndex] = hitChild;
    }

    ((S00cf5140_Stream*)TlsGetValue(DAT_0126835c))->timerEnd();
    return hitChild != -1;
}

// sub ecx,0x10; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x10).
struct PrimaryBase
{
    virtual void AdjustThisAndForward_00cf5820();
    int unk04;
    int unk08;
    int unk0C;
};

struct SecondaryBase
{
    virtual void AdjustThisAndForward_00cf5820();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00cf5820
// src: GUESS 0x00cf5820 (confidence: low)
    virtual void AdjustThisAndForward_00cf5820();
};

Derived::Derived()
{}

inline hkpShapeContainer::~hkpShapeContainer() {}

namespace fnv_00cf5750 {
class FUN_00cf5750 : public hkpShapeCollection
{
  public:
    hkArray<hkpListShapeChildInfo> m_kChildInfoList;

    virtual ~FUN_00cf5750() throw();
};

// Destructor that calls FUN_00c905b0 on each child's m_pCollisionShape in m_kChildInfoList.
// @fnv 0x00cf5750
FUN_00cf5750::~FUN_00cf5750() throw()
{
    for (int i = 0; i < m_kChildInfoList.m_iElementCount; i++)
    {
        hkpListShapeChildInfo& info = m_kChildInfoList[i];
        info.m_pCollisionShape->removeReference();
    }
}
}  // namespace fnv_00cf5750

struct hkpRayHitCollector;

// Preserve the original uninitialized body construction.
inline hkpCdBody::hkpCdBody() {}

struct S00cf52c0_Obj : public S00cf5140_Obj
{
    void hkpListShape_castRayWithCollectorImpl(const S00cf5140_Input& input, const hkpCdBody& cdBody, hkpRayHitCollector& collector) const;
};

// Iterates enabled children, optionally filtering via m_pRayShapeCollectionFilter, and casts a ray on each child's collision shape into the collector.
// @fnv 0x00cf52c0
// src: HAVOK_LIB 0x00cf52c0
void S00cf52c0_Obj::hkpListShape_castRayWithCollectorImpl(const S00cf5140_Input& input, const hkpCdBody& cdBody,
                                 hkpRayHitCollector& collector) const
{
    hkpCdBody child;
    ((S00cf5140_Stream*)TlsGetValue(DAT_0126835c))->timerBegin("TtrcList");

    if (!input.m_pRayShapeCollectionFilter)
    {
        for (unsigned int i = 0; (int)i < m_kChildInfoList.m_iElementCount; i++)
        {
            if (isChildEnabled(i))
            {
                child.m_pCollisionShape =
                    reinterpret_cast<const hkpShape*>(m_kChildInfoList.m_data[i].m_pCollisionShape);
                child.m_parent = &cdBody;
                child.m_pMotionState = cdBody.m_pMotionState;
                child.m_uiCollisionShapeKey = i;
                child.m_pCollisionShape->CastRayWithCollector(reinterpret_cast<const ShapeRayCastQuery&>(input), child, collector);
            }
        }
    }
    else
    {
        for (unsigned int i = 0; (int)i < m_kChildInfoList.m_iElementCount; i++)
        {
            if (isChildEnabled(i))
            {
                if (input.m_pRayShapeCollectionFilter
                        ->IsCollisionEnabled(input, *this, *static_cast<const hkpShapeContainer*>(this), i)
                        .m_cBooleanValue)
                {
                    child.m_pCollisionShape =
                        reinterpret_cast<const hkpShape*>(m_kChildInfoList.m_data[i].m_pCollisionShape);
                    child.m_parent = &cdBody;
                    child.m_pMotionState = cdBody.m_pMotionState;
                    child.m_uiCollisionShapeKey = i;
                    child.m_pCollisionShape->CastRayWithCollector(reinterpret_cast<const ShapeRayCastQuery&>(input), child, collector);
                }
            }
        }
    }

    ((S00cf5140_Stream*)TlsGetValue(DAT_0126835c))->timerEnd();
}
