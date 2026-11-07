
// src/havok/physics/dynamics/phantom/hkpaabbphantom.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/phantom/hkpaabbphantom.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Keep the original intrinsic representation: the SDK union adds aliasing views
// that change code generation in the ray cast.
#define _INCLUDED_MM2
// Exe 0x00cf26b0 FUN_00cf26b0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C" LocalM128 _mm_load_ps(const float*);
extern "C" void _mm_store_ps(float*, LocalM128);
extern "C" LocalM128 _mm_sub_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_add_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_unpacklo_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_unpackhi_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_movelh_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_movehl_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);

#include "../../../../../include/hkpAabbPhantom.h"
#include "../../../../../include/hkpCollidable.h"
#include "../../../../../include/hkpWorldObject.h"
#include "../../../../../include/hkStatisticsCollector.h"
#include "../../../../../include/hkClass.h"
#include "../../../../../include/hkAabb.h"
#include "../../../../../include/hkArray.h"
#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/hkRotation.h"
#include "../../../../../include/hkTransform.h"
#include "../../../../../include/hkMonitorStream.h"

typedef unsigned short hkUint16;
typedef short hkInt16;
typedef unsigned int hkUint32;

// hkMemoryRouter is the shared hkMemoryRouter: 0x00c85750 returns it,
// and the heap allocator pointer is at +0x10 in every use in this unit.
extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance();
__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return hkMemoryRouter_getInstance().heap();
}

template <typename T> __forceinline T* hkMemoryAllocator::_bufAlloc(int& n)
{
    int bytes = n * sizeof(T);
    void* p = bufAlloc(bytes);
    n = bytes / (int)sizeof(T);
    return (T*)p;
}
template <typename T> __forceinline void hkMemoryAllocator::_bufFree(void* p, int n)
{
    bufFree(p, n * sizeof(T));
}
template <typename T> __forceinline void hkArrayBase<T>::clear()
{
    for (int i = 0; i < m_iElementCount; ++i)
        m_data[i].~T();
    m_iElementCount = 0;
}
template <typename T> __forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& alloc)
{
    clear();
    if ((m_iCapacityState & 0x80000000) == 0)
        alloc._bufFree<T>(m_data, getCapacity());
    m_data = 0;
    m_iCapacityState = 0x80000000;
}
template <typename T, typename A> __forceinline hkArray<T, A>::~hkArray()
{
    clearAndDeallocate();
}
void __cdecl ResizeAudioStream(void* pvAlloc, void* apvArray, int iElemSize);
template <typename T> __forceinline void hkArrayBase<T>::_pushBack(hkMemoryAllocator& alloc, const T& t)
{
    if (m_iElementCount == getCapacity())
        ResizeAudioStream(&alloc, this, sizeof(T));
    T* p = m_data + m_iElementCount;
    for (int i = 0; i < 1; ++i)
        p[i] = t;
    m_iElementCount++;
}
template <typename T> __forceinline hkArrayBase<T>& hkArrayBase<T>::copyFromArray(
    hkMemoryAllocator& alloc, const hkArrayBase<T>& a, hkTypeIsPod)
{
    if (getCapacity() < a.GetLogicalSize())
    {
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc._bufFree<T>(m_data, getCapacity());
        int n = a.GetLogicalSize();
        m_data = alloc._bufAlloc<T>(n);
        m_iCapacityState = n;
    }
    m_iElementCount = a.GetLogicalSize();
    copy(m_data, a.m_data, m_iElementCount);
    return *this;
}
template <typename T, typename A> __forceinline hkArray<T, A>& hkArray<T, A>::operator=(const hkArray& a)
{
    copyFromArray(A().get(this), a, hkTypeIsPod());
    return *this;
}
__forceinline hkAabb::hkAabb() {}

// @fnv 0x00cf2460
// src: GUESS 0x00cf2460 (confidence: high)
int __cdecl Object_ReturnZero_00cf2460()
{
    return 0;
}

// 0x00cf24d0 searches the AABB phantom overlap array; the shared class lacks this method.
class PhantomOverlapSearch : public hkpAabbPhantom
{
  public:
    hkBool ContainsItem(void* pv) const;
};

// Searches m_ppOverlappingCollidables for pv and returns true if found, otherwise false.
// @fnv 0x00cf24d0
hkBool PhantomOverlapSearch::ContainsItem(void* apItem) const
{
    for (int i = 0; i < m_ppOverlappingCollidables.m_iElementCount; i++)
    {
        if (m_ppOverlappingCollidables.m_data[i] == apItem)
            return true;
    }
    return false;
}

// This call requires a nontrivial copy constructor to construct the flag directly
// in the outgoing argument slot; shared hkBool currently has only a trivial copy.
struct PresentFlag
{
    bool value;
    PresentFlag(bool v) : value(v)
    {}
    PresentFlag(const PresentFlag& v) : value(v.value)
    {}
};
// The shared class lacks the removal method and the nontrivial notification flag signature.
struct PhantomOverlapRemoval : hkpAabbPhantom
{
    void NotifyAll(hkpCollidable* collidable, PresentFlag wasPresent);
    void hkpAabbPhantom_removeOverlappingCollidable(hkpCollidable* collidable);
};
// Searches the phantom's collidable list for the given collidable, notifies via NotifyAll whether it was present, and removes it by swapping in the last entry.
// @fnv 0x00cf2a60
// src: HAVOK_LIB 0x00cf2a60
void PhantomOverlapRemoval::hkpAabbPhantom_removeOverlappingCollidable(hkpCollidable* collidable)
{
    int index;
    int count = m_ppOverlappingCollidables.m_iElementCount;
    int i = 0;
    if (count > 0)
    {
        void** ppEntry = m_ppOverlappingCollidables.m_data;
        do
        {
            if (*ppEntry == collidable)
            {
                index = i;
                goto search_done;
            }
            ++i;
            ++ppEntry;
        } while (i < count);
    }
    index = -1;
search_done:
    NotifyAll(collidable, PresentFlag(index >= 0));
    if (index >= 0)
    {
        --m_ppOverlappingCollidables.m_iElementCount;
        int lastIndex = m_ppOverlappingCollidables.m_iElementCount;
        if (lastIndex != index)
            m_ppOverlappingCollidables.m_data[index] = m_ppOverlappingCollidables.m_data[lastIndex];
        m_bOrderDirty = 1;
    }
}

extern const hkClass DAT_0126902c;

int __cdecl hkStatisticsCollector_getAllocatedSize(const void* pvChunk, int iNumBytes) throw();

template <class T, class Allocator>
void hkStatisticsCollector::addArray(const char* pcName, const hkArray<T, Allocator>& kArray)
{
    if ((kArray.m_iCapacityState & 0x80000000) == 0 || m_reportInplaceAllocations)
    {
        int iAllocated = hkStatisticsCollector_getAllocatedSize(kArray.m_data, kArray.getCapacity() * sizeof(T));
        AddMemoryChunk(3, pcName, kArray.m_data, kArray.GetLogicalSize() * sizeof(T), iAllocated);
    }
}

// 0x00cf2ae0 is the AABB phantom statistics override; the shared class lacks its declaration.
class PhantomStatistics : public hkpAabbPhantom
{
  public:
    void CollectStatistics(hkStatisticsCollector* pkCollector, const hkClass* pkClass) const throw();
};

// Adds the collidable pointer array and the base class data to the statistics collector.
// @fnv 0x00cf2ae0
void PhantomStatistics::CollectStatistics(hkStatisticsCollector* pkCollector,
                                         const hkClass* pkClass) const throw()
{
    pkCollector->addArray("OvrlpCollPtr", m_ppOverlappingCollidables);
    hkpPhantom::calcContentStatistics(pkCollector, &DAT_0126902c);
}

// 0x00ca94c0 checks overlap acceptance; the shared class lacks the add-overlap method.
class PhantomOverlapInsertion : public hkpAabbPhantom
{
  public:
    int hkpPhantom_fireCollidableAdded(void* p);
    void AddOverlap(void* p);
};

// @fnv 0x00cf2b50
void PhantomOverlapInsertion::AddOverlap(void* pOverlap)
{
    if (hkpPhantom_fireCollidableAdded(pOverlap) == 0)
    {
        m_ppOverlappingCollidables.pushBack(pOverlap);
        m_bOrderDirty = true;
    }
}

struct hkLessCF2B
{
};

void __cdecl QuickSortShapeDetails(void** pArr, int iStart, int iEnd, hkLessCF2B kCmp);

inline void quickSortCF2B(void** pArr, int iSize, hkLessCF2B kCmp)
{
    if (iSize > 1)
        QuickSortShapeDetails(pArr, 0, iSize - 1, kCmp);
}

// 0x00cf2bb0 sorts the overlap array; the shared class lacks its declaration.
struct PhantomOverlapSort : public hkpAabbPhantom
{
    void SortIfDirty();
};

// Sorts the overlap array when dirty, then clears the flag.
// @fnv 0x00cf2bb0
void PhantomOverlapSort::SortIfDirty()
{
    if (m_bOrderDirty)
    {
        quickSortCF2B(m_ppOverlappingCollidables.m_data, m_ppOverlappingCollidables.m_iElementCount, hkLessCF2B());
        m_bOrderDirty = false;
    }
}

// @fnv 0x00cf2bf0
hkpAabbPhantom::~hkpAabbPhantom() throw()
{}

namespace fnv_00cf2c50 {

// 0x00cf2c50 releases an empty overlap array; the shared class lacks this override.
class PhantomArrayCleanup : public hkpAabbPhantom
{
  public:
    void ClearOverlapsIfEmpty();
};

// If the overlaps array is empty, frees it via the heap allocator, then calls FreeListenerArrays.
// @fnv 0x00cf2c50
void PhantomArrayCleanup::ClearOverlapsIfEmpty()
{
    if (m_ppOverlappingCollidables.m_iElementCount == 0)
        m_ppOverlappingCollidables.clearAndDeallocate();
    hkpPhantom::FreeListenerArrays();
}
}  // namespace fnv_00cf2c50

namespace fnv_00cf2d50 {

// 0x00cf2d50 clones an AABB phantom; 0x00ca92a0 copies world-object properties.
// Only these missing method declarations and this unit's inline allocator remain local.
class PhantomClone : public hkpAabbPhantom
{
  public:
    static __forceinline void* operator new(unsigned int uiSize) throw()
    {
        hkpWorldObject* p = (hkpWorldObject*)hkMemoryRouter_getInstance().heap().blockAlloc(uiSize);
        p->m_usMemSizeAndFlags = (hkUint16)uiSize;
        return p;
    }
    static void operator delete(void* p) throw();

    void CopyEntriesFrom(const hkpWorldObject* pkOtherObj) throw();
    PhantomClone(const hkAabb& kAabb, hkUint32 uiCollisionFilterInfo) throw();
    hkpWorldObject* Clone() const throw();
};

typedef char fnv_check_cf2d50[(sizeof(PhantomClone) == 0xe0) ? 1 : -1];

// @fnv 0x00cf2d50
hkpWorldObject* PhantomClone::Clone() const throw()
{
    PhantomClone* pkPhantom = new PhantomClone(m_kBounds, m_kCollidable.GetFilterInfoForKey());
    pkPhantom->m_kPhantomOverlapListeners = m_kPhantomOverlapListeners;
    pkPhantom->m_kPhantomListeners = m_kPhantomListeners;
    pkPhantom->CopyEntriesFrom(this);
    return pkPhantom;
}
}  // namespace fnv_00cf2d50

namespace fnv_00cf2f60 {

// 0x00cf2f60 is the scalar deleting-destructor body, absent from the shared declaration.
class PhantomDeletion : public hkpAabbPhantom
{
  public:
    static void operator delete(void* p) throw()
    {
        hkMemoryRouter_getInstance().heap().blockFree(p, static_cast<hkpAabbPhantom*>(p)->m_usMemSizeAndFlags);
    }

    PhantomDeletion* DestroyAndFree(unsigned int uiFlags) throw();
};

// Runs the destructor, then frees the object via operator delete when uiFlags has bit 0 set, and returns this.
// @fnv 0x00cf2f60
PhantomDeletion* PhantomDeletion::DestroyAndFree(unsigned int uiFlags) throw()
{
    this->hkpAabbPhantom::~hkpAabbPhantom();
    if (uiFlags & 1)
        PhantomDeletion::operator delete(this);
    return this;
}
}  // namespace fnv_00cf2f60

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned long DAT_0126835c;

struct WorldRayCastInput
{
    hkVector4 m_vFrom;
    hkVector4 m_vTo;
    hkBool m_bEnableShapeCollectionFilter;
    char m_pad21;
    char m_pad22;
    char m_pad23;
    hkUint32 m_uiFilterInfo;
};

struct __declspec(align(16)) ShapeRayCastQuery
{
    hkVector4 m_vFrom;
    hkVector4 m_vTo;
    hkUint32 m_uiFilterInfo;
    const void* m_pRayShapeCollectionFilter;
};

struct DummyNormal : public hkVector4
{
    void hkVector4_setRotatedDir(const void* rot, const void* dir);
};

struct WorldRayCastOutput
{
    DummyNormal m_vHitNormal;
    float m_fHitFraction;
    int m_iExtraInfo;
    int m_uiShapeKeyIndex;
    int m_pad1c;
    hkUint32 m_shapeKeys0;
    hkUint32 m_shapeKeys1;
    hkUint32 m_shapeKeys2;
    hkUint32 m_shapeKeys3;
    hkUint32 m_shapeKeys4;
    hkUint32 m_shapeKeys5;
    hkUint32 m_shapeKeys6;
    hkUint32 m_shapeKeys7;
    hkUint32 m_shapeKeys8;
    hkUint32 m_shapeKeys9;
    hkUint32 m_shapeKeys10;
    hkUint32 m_shapeKeys11;
    const hkpCollidable* m_pRootCollidable;
};

struct DummyShape
{
    virtual void func0() = 0;
    virtual void func1() = 0;
    virtual void func2() = 0;
    virtual void func3() = 0;
    virtual void func4() = 0;
    virtual void func5() = 0;
    virtual void func6() = 0;
    virtual void func7() = 0;
    virtual hkBool RayCast(const ShapeRayCastQuery& input, WorldRayCastOutput& output) const = 0;
};

struct DummyWorld
{
    int m_unk00;
    int m_unk04;
    int m_unk08;
    int m_unk0c;
    int m_unk10;
    int m_unk14;
    int m_unk18;
    int m_unk1c;
    int m_unk20;
    int m_unk24;
    int m_unk28;
    int m_unk2c;
    int m_unk30;
    int m_unk34;
    int m_unk38;
    int m_unk3c;
    int m_unk40;
    int m_unk44;
    int m_unk48;
    int m_unk4c;
    int m_unk50;
    int m_unk54;
    int m_unk58;
    int m_unk5c;
    int m_unk60;
    int m_unk64;
    int m_unk68;
    int m_unk6c;
    int m_unk70;
    int m_unk74;
    int m_unk78;
    char* m_pCollisionFilter;
};

static inline void setRotatedInverseDir(hkVector4& out, const hkRotation& r, const LocalM128& b)
{
    LocalM128 c0 = *(const LocalM128*)&r.m_kColumn0;
    LocalM128 c1 = *(const LocalM128*)&r.m_kColumn1;
    LocalM128 c2 = *(const LocalM128*)&r.m_kColumn2;
    LocalM128 tmp = _mm_unpacklo_ps(c0, c1);
    LocalM128 ctmp = _mm_unpackhi_ps(c0, c1);
    c0 = _mm_movelh_ps(tmp, c2);
    c1 = _mm_movehl_ps(c0, tmp);
    c1 = _mm_shuffle_ps(c1, c2, 0xd4);
    c2 = _mm_shuffle_ps(ctmp, c2, 0xe4);
    LocalM128 b0 = _mm_shuffle_ps(b, b, 0x00);
    LocalM128 r0 = _mm_mul_ps(c0, b0);
    LocalM128 b1 = _mm_shuffle_ps(b, b, 0x55);
    LocalM128 r1 = _mm_mul_ps(c1, b1);
    LocalM128 b2 = _mm_shuffle_ps(b, b, 0xaa);
    LocalM128 r2 = _mm_mul_ps(c2, b2);
    *(LocalM128*)&out = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}

static inline void SetTransformedPosition(hkVector4& out, const hkTransform* t, const hkVector4& in)
{
    LocalM128 d = _mm_sub_ps(*(const LocalM128*)&in, *(const LocalM128*)&t->m_vTranslation);
    setRotatedInverseDir(out, t->m_rotation, d);
}

// The shared ray-cast declaration has a different signature (void pointers and non-const this).
class PhantomRayCast : public hkpAabbPhantom
{
  public:
    void hkpAabbPhantom_castRay_00cf26b0(const WorldRayCastInput& input, WorldRayCastOutput& output) const;
};

// Performs a ray cast against overlapping collidables, transforming ray endpoints into local space and recording the hit root collidable.
// @fnv 0x00cf26b0
// src: XBOX_PDB 0x00cf26b0
void PhantomRayCast::hkpAabbPhantom_castRay_00cf26b0(const WorldRayCastInput& input, WorldRayCastOutput& output) const
{
    hkMonitorStream* pTlsCursor = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    char* cmd = pTlsCursor->m_end.m_storage;
    if (cmd < pTlsCursor->m_capacityMinus16.m_storage)
    {
        *(const char**)cmd = "TtrcPhantom";
        _ReadWriteBarrier();
        volatile hkUint32 time = (hkUint32)__rdtsc();
        *(hkUint32*)(cmd + 4) = time;
        cmd += 12;
        pTlsCursor->m_end.m_storage = cmd;
    }

    ShapeRayCastQuery shapeQuery;
    shapeQuery.m_pRayShapeCollectionFilter = 0;
    shapeQuery.m_uiFilterInfo = input.m_uiFilterInfo;
    if (input.m_bEnableShapeCollectionFilter)
    {
        char* filter = ((DummyWorld*)m_pOwningWorld)->m_pCollisionFilter;
        shapeQuery.m_pRayShapeCollectionFilter = filter ? filter + 0x10 : 0;
    }
    else
    {
        shapeQuery.m_pRayShapeCollectionFilter = 0;
    }

    const hkpCollidable* const* ppCollidables = (const hkpCollidable* const*)m_ppOverlappingCollidables.m_data;
    for (int i = m_ppOverlappingCollidables.m_iElementCount - 1; i >= 0; i--)
    {
        const DummyShape* shape = reinterpret_cast<const DummyShape*>((*ppCollidables)->m_pCollisionShape);
        if (shape)
        {
            const hkTransform* pMotionState = static_cast<const hkTransform*>((*ppCollidables)->m_pMotionState);
            SetTransformedPosition(shapeQuery.m_vFrom, pMotionState, input.m_vFrom);
            SetTransformedPosition(shapeQuery.m_vTo, pMotionState, input.m_vTo);
            hkBool hit = shape->RayCast(shapeQuery, output);
            if (hit.m_cBooleanValue)
            {
                output.m_pRootCollidable = *ppCollidables;
            }
        }
        ppCollidables++;
    }

    if (output.m_pRootCollidable)
    {
        output.m_vHitNormal.hkVector4_setRotatedDir(output.m_pRootCollidable->m_pMotionState, &output.m_vHitNormal);
    }

    hkMonitorStream* hit = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    char* cmd2 = hit->m_end.m_storage;
    if (cmd2 < hit->m_capacityMinus16.m_storage)
    {
        *(const char**)cmd2 = "Et";
        _ReadWriteBarrier();
        volatile hkUint32 time2 = (hkUint32)__rdtsc();
        *(hkUint32*)(cmd2 + 4) = time2;
        cmd2 += 12;
        hit->m_end.m_storage = cmd2;
    }
}

// 0x00cf2470 copies the AABB at +0xb0; the shared class lacks a bounds getter.
struct PhantomBoundsReader : public hkpAabbPhantom
{
    void GetBounds(hkAabb* bounds);
};
// @fnv 0x00cf2470
void PhantomBoundsReader::GetBounds(hkAabb* bounds)
{
    *(LocalM128*)&bounds->m_kMinimumCorner = *(const LocalM128*)&m_kBounds.m_kMinimumCorner;
    *(LocalM128*)&bounds->m_kMaximumCorner = *(const LocalM128*)&m_kBounds.m_kMaximumCorner;
}

// The shared bounds setter takes hkAabbQ instead of hkAabb; its update helper is absent.
struct PhantomBounds : public hkpAabbPhantom
{
    void __thiscall hkpPhantom_updateBroadPhase(hkAabb* bounds);
    void __thiscall hkpAabbPhantom_setAabb(const hkAabb& source);
};
// Copies the minimum and maximum corners from source into the embedded hkAabb at offset 0xb0, then calls FUN_00d07ec0 on it.
// @fnv 0x00cf24a0
// src: XBOX_PDB 0x00cf24a0
void PhantomBounds::hkpAabbPhantom_setAabb(const hkAabb& source)
{
    hkAabb* target = &m_kBounds;
    _mm_store_ps(&target->m_kMinimumCorner.x, _mm_load_ps(&source.m_kMinimumCorner.x));
    _mm_store_ps(&target->m_kMaximumCorner.x, _mm_load_ps(&source.m_kMaximumCorner.x));
    hkpPhantom_updateBroadPhase(target);
}

__forceinline unsigned int hkpCollidable::GetFilterInfoForKey() const
{
    return m_kBroadPhaseHandle.m_uiCollisionFilterData;
}

__forceinline void hkpCollidable::SetOwnerPointer(void* pvOwner)
{
    m_iOwnerOffset = (char)((unsigned int)pvOwner - (unsigned int)this);
}

// The shared hkpPhantom has no shape constructor; retain its construction here.
class PhantomConstructionBase : public hkpWorldObject
{
  public:
    PhantomConstructionBase(const void* pkShape) throw() : hkpWorldObject(pkShape, 2)
    {
        m_kCollidable.SetOwnerPointer(this);
    }
    hkArray<void*> m_kPhantomOverlapListeners;
    hkArray<void*> m_kPhantomListeners;
    int unkA4, unkA8, unkAC;
};

// 0x00cf2cb0 is the AABB phantom constructor; local fields remain only because
// hkpPhantom lacks the shape constructor needed to define the shared derived constructor.
class AabbPhantomConstruction : public PhantomConstructionBase
{
  public:
    AabbPhantomConstruction(const hkAabb& kAabb, unsigned int uiCollisionFilterInfo) throw();
    virtual ~AabbPhantomConstruction() throw();
    hkAabb m_kBounds;
    hkArray<void*> m_ppOverlappingCollidables;
    bool m_bOrderDirty;
};

// Constructs the Phantom base with a null shape, clears m_bOrderDirty, copies kAabb into m_kBounds and stores the collision filter data.
// @fnv 0x00cf2cb0
AabbPhantomConstruction::AabbPhantomConstruction(const hkAabb& kAabb, unsigned int uiCollisionFilterInfo) throw() : PhantomConstructionBase(0)
{
    m_bOrderDirty = false;
    m_kBounds = kAabb;
    m_kCollidable.m_kBroadPhaseHandle.m_uiCollisionFilterData = uiCollisionFilterInfo;
}
