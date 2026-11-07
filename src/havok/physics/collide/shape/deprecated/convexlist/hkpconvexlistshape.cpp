
// src/havok/physics/collide/shape/deprecated/convexlist/hkpconvexlistshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/deprecated/convexlist/hkpconvexlistshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkpConvexListShape.h"
#include "../../../../../../../include/hkStatisticsCollector.h"
#include "../../../../../../../include/hkAabb.h"
#include "../../../../../../../include/hkTransform.h"
#include "../../../../../../../include/hkArray.h"
#include "../../../../../../../include/hkBaseObject.h"
#include "../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../include/hkpShape.h"
#include "../../../../../../../include/hkpConvexShape.h"
#include "../../../../../../../include/hkpShapeContainer.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkVector4q.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkpCdBody.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMonitorStream.h"

// Free functions with an unused EDX parameter preserve the original thiscall ABI
// for methods the shared convex-list header does not declare.
// @fnv 0x00d5e2e0
int __fastcall GetNextKey(hkpShapeContainer* self, void*, int key)
{
    ++key;
    if (key >= reinterpret_cast<hkpConvexListShape*>(reinterpret_cast<char*>(self) - sizeof(hkpConvexShape))->m_kChildShapes.m_iElementCount)
        key = -1;
    return key;
}

// Iterates the objects in the array at offset 0x44 up to the count at 0x48, calling each object's virtual method at vtable offset 0x2c and summing the results.
// @fnv 0x00d5e190
int __fastcall SumVirtualResults(hkpConvexListShape* self)
{
    int iTotal = 0;
    int i = 0;
    if (self->m_kChildShapes.m_iElementCount > 0)
    {
        do
        {
            hkpConvexShape* shape = self->m_kChildShapes.m_data[i];
            iTotal += shape->GetNumCollisionSpheres();
            i++;
        } while (i < self->m_kChildShapes.m_iElementCount);
    }
    return iTotal;
}

// @fnv 0x00d5e2f0
// src: HAVOK_LIB 0x00d5e2f0
const hkpShape* __fastcall hkpConvexListShape_getChildShape(hkpShapeContainer* self, int edx, int key, int pad)
{
    return reinterpret_cast<hkpConvexListShape*>(reinterpret_cast<char*>(self) - sizeof(hkpConvexShape))->m_kChildShapes.m_data[key];
}

// Calls the convex-list destructor and optionally releases its allocation using m_usMemSizeAndFlags.
// @fnv 0x00d5e850
hkReferencedObject* __fastcall DestroyConvexListShape(hkReferencedObject* self, void*, int flags)
{
    static_cast<hkpConvexListShape*>(self)->hkpConvexListShape::~hkpConvexListShape();

    if (flags & 1)
    {
        hkMemoryRouter& router = hkMemoryRouter::getInstance();
        router.m_heap->blockFree(self, self->m_usMemSizeAndFlags);
    }

    return self;
}

// @fnv 0x00d5e0f0
hkpShapeContainer* __fastcall GetConvexListContainer(hkpConvexListShape* self)
{
    return static_cast<hkpShapeContainer*>(self);
}

// @fnv 0x00d5e0d0
// src: GUESS 0x00d5e0d0 (confidence: high)
int __cdecl hkpConvexListShape_ReturnZero()
{
    return 0;
}

// @fnv 0x00d5e0e0
// src: GUESS 0x00d5e0e0 (confidence: high)
int __stdcall Object_ReturnZero_00d5e0e0(int)
{
    return 0;
}

// @fnv 0x00d5e180
void __fastcall GetConvexListFirstVertex(hkpConvexListShape* self, void*, hkVector4& vertex)
{
    self->m_kChildShapes.m_data[0]->GetFirstVertex(vertex);
}

// Writes each element's data into destination, advancing the cursor by each element's element count times 16 bytes.
// @fnv 0x00d5e1c0
void* __fastcall WriteToBuffer(hkpConvexListShape* self, void*, void* destination)
{
    char* cursor = (char*)destination;
    for (int i = 0; i < self->m_kChildShapes.m_iElementCount; ++i)
    {
        hkpConvexShape* element = self->m_kChildShapes.m_data[i];
        element->GetCollisionSpheres(reinterpret_cast<hkSphere*>(cursor));
        cursor += element->GetNumCollisionSpheres() * 16;
    }
    return destination;
}

// @fnv 0x00d5e2d0
int __fastcall GetConvexListChildCount(hkpShapeContainer* self)
{
    return reinterpret_cast<hkpConvexListShape*>(reinterpret_cast<char*>(self) - sizeof(hkpConvexShape))->m_kChildShapes.m_iElementCount;
}

// @fnv 0x00d5e6e0
void hkpConvexListShape::SetChildren(hkpConvexShape** children, int numChildren) throw()
{
    hkArray<hkpConvexShape*>* pChildrenArray = &m_kChildShapes;
    hkMemoryRouter& router = hkMemoryRouter::getInstance();
    hkMemoryAllocator& allocator = *router.m_heap;
    int iCapacity = pChildrenArray->m_iCapacityState & 0x3fffffff;
    if (iCapacity < numChildren)
    {
        iCapacity *= 2;
        if (numChildren >= iCapacity)
        {
            iCapacity = numChildren;
        }
        hkArrayUtil::_reserve(allocator, pChildrenArray, iCapacity, sizeof(hkpConvexShape*));
    }
    pChildrenArray->m_iElementCount = numChildren;
    m_fSphereRadius = children[0]->m_fSphereRadius;
    for (int i = 0; i < numChildren; i++)
    {
        pChildrenArray->m_data[i] = children[i];
        children[i]->addReference();
    }
}

// @fnv 0x00d5e100
void __fastcall GetChildData(hkpConvexListShape* self, void*, const unsigned short* keys, int numKeys, hkVector4q* out)
{
    for (int i = 0; i < numKeys; i++)
    {
        int key = keys[0];
        int childIdx = (unsigned short)key >> 8;
        int childKey = key & 0xff;
        self->m_kChildShapes.m_data[childIdx]->GetVerticesFromIds(reinterpret_cast<const hkpVertexId*>(&childKey), 1,
                                                   reinterpret_cast<Vector4WithInt24W*>(out));
        out->m_vComponents.m128_u32[3] = ((out->m_vComponents.m128_u32[3] & 0xc0ffffff) + ((unsigned int)childIdx << 8)) | 0x3f000000;
        keys++;
        out++;
    }
}

// VC9 treats the SDK intrinsic union's byte arrays as stack buffers.
// Use float-only intrinsic temporaries to retain the original stack code.
namespace float_simd {
// Exe 0x00d5e300 GetConvexListSupportVertex: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C" LocalM128 _mm_min_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_max_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_add_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_mul_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_add_ss(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128 a, LocalM128 b, unsigned int imm);
extern "C" void _mm_store_ss(float* p, LocalM128 a);
}

inline void hkVector4q::setMin4(const hkVector4q& a, const hkVector4q& b)
{
    reinterpret_cast<float_simd::LocalM128&>(m_vComponents) = float_simd::_mm_min_ps(
        reinterpret_cast<const float_simd::LocalM128&>(a.m_vComponents),
        reinterpret_cast<const float_simd::LocalM128&>(b.m_vComponents));
}

inline void hkVector4q::setMax4(const hkVector4q& a, const hkVector4q& b)
{
    reinterpret_cast<float_simd::LocalM128&>(m_vComponents) = float_simd::_mm_max_ps(
        reinterpret_cast<const float_simd::LocalM128&>(a.m_vComponents),
        reinterpret_cast<const float_simd::LocalM128&>(b.m_vComponents));
}

inline void hkVector4q::setAdd4(const hkVector4q& a, const hkVector4q& b)
{
    reinterpret_cast<float_simd::LocalM128&>(m_vComponents) = float_simd::_mm_add_ps(
        reinterpret_cast<const float_simd::LocalM128&>(a.m_vComponents),
        reinterpret_cast<const float_simd::LocalM128&>(b.m_vComponents));
}

__forceinline hkReal hkVector4q::dot3(const hkVector4q& a) const
{
    const float_simd::LocalM128 x2 = float_simd::_mm_mul_ps(
        reinterpret_cast<const float_simd::LocalM128&>(m_vComponents),
        reinterpret_cast<const float_simd::LocalM128&>(a.m_vComponents));
    const float_simd::LocalM128 xySum = float_simd::_mm_add_ss(float_simd::_mm_shuffle_ps(x2, x2, 0x55), x2);
    const float_simd::LocalM128 z = float_simd::_mm_shuffle_ps(x2, x2, 0xaa);
    const float_simd::LocalM128 xyzSum = float_simd::_mm_add_ss(z, xySum);
    hkReal r;
    float_simd::_mm_store_ss(&r, xyzSum);
    return r;
}

__forceinline int hkVector4q::getInt24W() const
{
    return reinterpret_cast<const int*>(&m_vComponents)[3] & ~0x3f000000;
}

__forceinline void hkVector4q::setInt24W(int value)
{
    reinterpret_cast<int*>(&m_vComponents)[3] = value | 0x3f000000;
}

extern const __m128 DAT_010c71d0;
static const float DAT_0104da48 = 3.40282e+38f;
static const float DAT_0104e148 = -3.40282e+38f;

inline hkAabb::hkAabb() {}

static __forceinline void includeAabb(hkAabb& bounds, const hkAabb& other)
{
    reinterpret_cast<float_simd::LocalM128&>(bounds.m_kMinimumCorner.m_vComponents) = float_simd::_mm_min_ps(
        reinterpret_cast<const float_simd::LocalM128&>(bounds.m_kMinimumCorner.m_vComponents),
        reinterpret_cast<const float_simd::LocalM128&>(other.m_kMinimumCorner.m_vComponents));
    reinterpret_cast<float_simd::LocalM128&>(bounds.m_kMaximumCorner.m_vComponents) = float_simd::_mm_max_ps(
        reinterpret_cast<const float_simd::LocalM128&>(bounds.m_kMaximumCorner.m_vComponents),
        reinterpret_cast<const float_simd::LocalM128&>(other.m_kMaximumCorner.m_vComponents));
}

extern hkTransform DAT_01268370;

// Stores bUseCachedAabb and, when true, computes m_kAabbCenter and m_kAabbHalfExtents from the union of child shape AABBs.
// @fnv 0x00d5e210
void hkpConvexListShape::UpdateCachedAabb(bool bUseCachedAabb) throw()
{
    m_bUseCachedAabb = bUseCachedAabb;
    if (bUseCachedAabb)
    {
        hkAabb kAabb;
        kAabb.m_kMinimumCorner.m_vComponents = _mm_load_ps1(&DAT_0104da48);
        kAabb.m_kMaximumCorner.m_vComponents = _mm_load_ps1(&DAT_0104e148);
        for (int i = 0; i < m_kChildShapes.GetLogicalSize(); i++)
        {
            hkAabb kChildAabb;
            m_kChildShapes[i]->CalculateAabb(DAT_01268370, 0.0f, kChildAabb);
            includeAabb(kAabb, kChildAabb);
        }
        hkVector4q kTargetCenter;
        kTargetCenter.setAdd4(reinterpret_cast<const hkVector4q&>(kAabb.m_kMinimumCorner),
                              reinterpret_cast<const hkVector4q&>(kAabb.m_kMaximumCorner));
        kTargetCenter.m_vComponents = _mm_mul_ps(kTargetCenter.m_vComponents, DAT_010c71d0);
        m_kAabbCenter.m_vComponents = kTargetCenter.m_vComponents;
        hkVector4q m_kPoint2;
        m_kPoint2.setSub4(reinterpret_cast<const hkVector4q&>(kAabb.m_kMaximumCorner),
                         reinterpret_cast<const hkVector4q&>(kAabb.m_kMinimumCorner));
        m_kPoint2.m_vComponents = _mm_mul_ps(m_kPoint2.m_vComponents, DAT_010c71d0);
        m_kAabbHalfExtents.m_vComponents = m_kPoint2.m_vComponents;
    }
}

namespace fnv_00d5e3c0 {

void __cdecl hkAabbUtil_calcAabb_00d26230(const hkTransform& kLocalToWorld, const hkVector4& m_kPoint2,
                          const hkVector4& kTargetCenter, float fExtraRadius, hkAabb& kAabbOut);

// Computes the world-space AABB of a convex list shape, using cached extents when available or merging child shape AABBs otherwise.
// @fnv 0x00d5e3c0
void __fastcall CalculateConvexListAabb(const hkpConvexListShape* self, void*,
                                          const hkTransform& kLocalToWorld, float fTolerance, hkAabb& kOut)
{
    if (self->m_bUseCachedAabb)
    {
        hkAabbUtil_calcAabb_00d26230(kLocalToWorld, self->m_kAabbHalfExtents, self->m_kAabbCenter, self->m_fSphereRadius + fTolerance, kOut);
        return;
    }

    self->m_kChildShapes[0]->CalculateAabb(kLocalToWorld, fTolerance, kOut);
    hkAabb kTemp;
    for (int i = 1; i < self->m_kChildShapes.GetLogicalSize(); i++)
    {
        self->m_kChildShapes[i]->CalculateAabb(kLocalToWorld, fTolerance, kTemp);
        includeAabb(kOut, kTemp);
    }
}
}  // namespace fnv_00d5e3c0


template <typename ENUM, typename STORAGE>
inline hkEnum<ENUM, STORAGE>::hkEnum() {}

inline hkpShape::hkpShape(hkpShapeType type) : m_ulUserData(0)
{
    *reinterpret_cast<hkUint32*>(&m_type) = type;
}
inline hkpConvexShape::hkpConvexShape(int type, float radius)
    : hkpShape(static_cast<hkpShapeType>(type))
{
    m_fSphereRadius = radius;
}
inline hkpShapeContainer::~hkpShapeContainer() {}

// @fnv 0x00d5e750
hkpConvexListShape::hkpConvexListShape(hkpConvexShape** children, int numChildren) throw()
    : hkpConvexShape(0x16, 0.0f)
{
    m_fMaximumRadius = 1.0f;
    SetChildren(children, numChildren);
    UpdateCachedAabb(true);
}


inline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return hkMemoryRouter::getInstance().heap();
}

template <typename T>
__forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& kAlloc)
{
    m_iElementCount = 0;
    if ((m_iCapacityState & 0x80000000) == 0)
        kAlloc.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
    m_data = 0;
    m_iCapacityState = 0x80000000;
}

template <typename T, typename Allocator>
__forceinline hkArray<T, Allocator>::~hkArray()
{
    this->_clearAndDeallocate(Allocator().get(this));
}

// @fnv 0x00d5e7c0
hkpConvexListShape::~hkpConvexListShape() throw()
{
    for (int i = 0; i < m_kChildShapes.GetLogicalSize(); i++)
    {
        m_kChildShapes.m_data[i]->removeReference();
    }
}

extern int _FUN_00d06f80(void*, int);
extern int DAT_01268940;
extern const char str_010cc3a4[];

// @fnv 0x00d5e480
// src: HAVOK_LIB 0x00d5e480
void hkpConvexListShape::calcContentStatistics_00d5e480(hkStatisticsCollector* visitor, int)
{
    const int& capacity = m_kChildShapes.m_iCapacityState;
    if (!(capacity & 0x80000000) || visitor->m_reportInplaceAllocations != 0)
    {
        hkpConvexShape** childArray = m_kChildShapes.m_data;
        int allocationSize = (capacity & 0x3fffffff) * 4;
        int allocated = _FUN_00d06f80(childArray, allocationSize);
        visitor->AddMemoryChunk(3, str_010cc3a4, m_kChildShapes.m_data, m_kChildShapes.m_iElementCount * 4, allocated);
    }

    {
        int index = 0;
        while (index < m_kChildShapes.m_iElementCount)
        {
            visitor->beginObject(0, reinterpret_cast<const hkClass*>(m_kChildShapes.m_data[index]), 0);
            ++index;
        }
    }

    hkReferencedObject_calcContentStatistics(visitor, &DAT_01268940);
}


#include <windows.h>
extern "C" void _ReadWriteBarrier(void);

extern DWORD DAT_0126835c;
unsigned __int64 __cdecl __rdtsc(void);

struct Node;
struct Coll
{
    virtual void v00();
    virtual void v04();
    virtual int First();
    virtual int Next(int id);
    virtual void v10();
    virtual Node* Get(int id, void* buf);
};
struct State
{
    DWORD unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int slots[8];
    int depth;
};
struct Node
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual bool* hkpConvexListShape_castRayImpl(bool* __restrict result, void* other, State* st);
    DWORD unk04, unk08, unk0C, unk10;
    Coll coll;
};
struct __declspec(align(16)) Buf
{
    DWORD d[128];
};

// Recursively searches coll children for a match, records the selected id in st->slots, and sets *result to whether one was found.
// @fnv 0x00d5e500
// src: HAVOK_LIB 0x00d5e500
bool* Node::hkpConvexListShape_castRayImpl(bool* __restrict result, void* other, State* st)
{
    Buf buf;
    struct F
    {
        bool a, b, c, d;
    } found;
    hkMonitorStream* pBuf = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    if (pBuf->m_end.m_storage < pBuf->m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* pRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pBuf->m_end.m_storage);
        volatile DWORD ticks;
        pRec->m_commandAndMonitor = "TtrcCxList";
        _ReadWriteBarrier();
        ticks = (DWORD)__rdtsc();
        pRec->m_time0 = ticks;
        pBuf->m_end.m_storage = reinterpret_cast<char*>(pRec + 1);
    }
    st->depth++;
    int iSelected = -1;
    for (int id = coll.First(); id != -1; id = coll.Next(id))
    {
        coll.Get(id, &buf)->hkpConvexListShape_castRayImpl(&found.d, other, st);
        if (found.d)
            iSelected = id;
    }
    st->depth--;
    if (iSelected != -1)
        st->slots[st->depth] = iSelected;
    *result = iSelected != -1;
    pBuf = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    if (pBuf->m_end.m_storage < pBuf->m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* pRec = reinterpret_cast<hkMonitorStream::TimerCommand*>(pBuf->m_end.m_storage);
        volatile DWORD ticks;
        pRec->m_commandAndMonitor = "Et";
        _ReadWriteBarrier();
        ticks = (DWORD)__rdtsc();
        pRec->m_time0 = ticks;
        pBuf->m_end.m_storage = reinterpret_cast<char*>(pRec + 1);
    }
    return result;
}

extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);

extern DWORD hkMonitorStream__tlsIndex;

inline void hkMonitorStream::TimerCommand::setTime()
{
    _ReadWriteBarrier();
    volatile hkUint32 ticks = hkUint32(__rdtsc());
    m_time0 = ticks;
}

inline hkMonitorStream& hkMonitorStream::getInstance()
{
    return *static_cast<hkMonitorStream*>(TlsGetValue(hkMonitorStream__tlsIndex));
}

inline hkBool __cdecl hkMonitorStream::memoryAvailable()
{
    return m_end.val() < m_capacityMinus16.val();
}

inline char* __cdecl hkMonitorStream::getEnd()
{
    return m_end.val();
}

inline void __cdecl hkMonitorStream::setEnd(char* e)
{
    m_end.m_storage = e;
}

struct ShapeRayCastQuery;
struct hkpRayHitCollector;

inline hkpCdBody::hkpCdBody(const hkpCdBody* parent)
{
    m_parent = parent;
    m_pMotionState = parent->m_pMotionState;
}

inline void hkpCdBody::SetCollisionShapeAndKey(const hkpShape* shape, hkUint32 key)
{
    m_pCollisionShape = shape;
    m_uiCollisionShapeKey = key;
}

// Iterates child shape keys, builds a child hkpCdBody for each, and calls castRayWithCollector on every child shape.
// @fnv 0x00d5e600
void __fastcall CastConvexListRayWithCollector(const hkpConvexListShape* self, void*,
                                      const ShapeRayCastQuery& input, const hkpCdBody& cdBody, hkpRayHitCollector& collector)
{
    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable())
        {
            hkMonitorStream::TimerCommand* h =
                reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = "TtrcShpCollect";
            h->setTime();
            mStream.setEnd(reinterpret_cast<char*>(h + 1));
        }
    }
    hkUint32 key = self->GetFirstKey();
    while (key != 0xffffffff)
    {
        Buf shapeBuffer;
        const hkpShape* childShape = self->GetShapeForKey(key, reinterpret_cast<hkpShapeBuffer&>(shapeBuffer));
        hkpCdBody childBody(&cdBody);
        childBody.SetCollisionShapeAndKey(childShape, key);
        childShape->CastRayWithCollector(input, childBody, collector);
        key = self->GetNextShapeKey(key);
    }
    {
        hkMonitorStream& mStream = hkMonitorStream::getInstance();
        if (mStream.memoryAvailable())
        {
            hkMonitorStream::TimerCommand* h =
                reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());
            h->m_commandAndMonitor = "Et";
            h->setTime();
            mStream.setEnd(reinterpret_cast<char*>(h + 1));
        }
    }
}

// sub ecx,0x14; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x14).
struct PrimaryBase
{
    virtual void AdjustThisAndForward_00d5e840();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

struct SecondaryBase
{
    virtual void AdjustThisAndForward_00d5e840();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d5e840
// src: GUESS 0x00d5e840 (confidence: low)
    virtual void AdjustThisAndForward_00d5e840();
};

Derived::Derived()
{}

// Finds the child convex shape with the maximum dot product against direction, sets supportingVertex, and encodes the child index into the vertex's w component.
// @fnv 0x00d5e300
void __fastcall GetConvexListSupportVertex(const hkpConvexListShape* self, void*,
                                                 const hkVector4q& direction, hkVector4q& supportingVertex)
{
    hkReal maxDot = DAT_0104e148;
    int subShape = 0;
    for (int i = 0; i < self->m_kChildShapes.m_iElementCount; i++)
    {
        hkVector4q support;
        const hkpConvexShape* shape = self->m_kChildShapes.m_data[i];
        shape->GetSupportVertex(reinterpret_cast<const hkVector4&>(direction),
                                reinterpret_cast<Vector4WithInt24W&>(support));
        hkReal dot = support.dot3(direction);
        if (dot > maxDot)
        {
            maxDot = dot;
            supportingVertex = support;
            subShape = i;
        }
    }
    int id = supportingVertex.getInt24W();
    id += (subShape << 8);
    supportingVertex.setInt24W(id);
}
