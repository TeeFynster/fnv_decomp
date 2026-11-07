
// src/havok/physics/dynamics/phantom/hkpsimpleshapephantom.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/phantom/hkpsimpleshapephantom.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/hkpShape.h"
#include "../../../../../include/hkpSimpleShapePhantom.h"
#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/hkArray.h"
#include "../../../../../include/hkBool.h"
#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkStatisticsCollector.h"
#include "../../../../../include/hkTransform.h"
#include "../../../../../include/hkVector4.h"
#include "../../../../../include/hkpCdBody.h"
#include "../../../../../include/hkpCollidable.h"
#include "../../../../../include/hkpCollisionDispatcher.h"
#include "../../../../../include/hkpCollisionInput.h"

class hkpSimpleShapePhantomCollisionDetail
{
  public:
    hkpCollidable* m_kCollidable;
};

template <class T> __forceinline void hkArrayBase<T>::removeAt(int index)
{
    m_iElementCount--;
    if (m_iElementCount != index)
        m_data[index] = m_data[m_iElementCount];
}

template <typename T> inline T* hkMemoryAllocator::_bufAlloc(int& count)
{
    int n = count * sizeof(T);
    void* p = bufAlloc(n);
    count = n / (int)sizeof(T);
    return (T*)p;
}
template <typename T> inline void hkMemoryAllocator::_bufFree(void* p, int count)
{
    bufFree(p, count * sizeof(T));
}


typedef unsigned short hkUint16;
typedef short hkInt16;

inline unsigned int hkpCollidable::GetFilterInfoForKey() const
{
    return m_kBroadPhaseHandle.m_uiCollisionFilterData;
}

inline const hkpShape* hkpCollidable::getShape() const
{
    return m_pCollisionShape;
}

inline hkpShapeType hkpShape::getType() const
{
    return *reinterpret_cast<const hkpShapeType*>(&m_type);
}

hkMemoryRouter* _D1A0E0GetMemoryRouter();

struct FUN_00d1f9c0_StandIn
{
    void* vtable;
    unsigned short size;

    void FUN_00d1f780();
    void* FUN_00d1f9c0(unsigned int flags);
};

// Calls FUN_00d1f780, then if flags has bit 1 set frees this through the memory router's free with this->size, and returns this.
// @fnv 0x00d1f9c0
void* FUN_00d1f9c0_StandIn::FUN_00d1f9c0(unsigned int flags)
{
    this->FUN_00d1f780();

    if (flags & 1)
    {
        hkMemoryRouter* router = _D1A0E0GetMemoryRouter();
        hkMemoryAllocator* memory = reinterpret_cast<hkMemoryAllocator*>(router->m_heap);
        unsigned short size = this->size;
        memory->blockFree(this, size);
    }

    return this;
}

// @fnv 0x00d1f220
// src: GUESS 0x00d1f220 (confidence: high)
int Object_ReturnOne_00d1f220()
{
    return 1;
}

struct ShapeDetail
{
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    unsigned int key;
};
typedef __declspec(align(16)) ShapeDetail* AlignedShapePtr;
struct DetailLess
{
    bool operator()(ShapeDetail* const& a, ShapeDetail* const& b) const
    {
        return a->key < b->key;
    }
};
// Sorts the range [lo, hi] of a ShapeDetail pointer array in place by key using a quicksort partition loop and recursion.
// @fnv 0x00cf2ed0
void __cdecl QuickSortShapeDetails(ShapeDetail** apItems, int lo, int hi, DetailLess aComparator)
{
    for (;;)
    {
        int i = lo;
        int iRight = hi;
        AlignedShapePtr pivot = apItems[(lo + hi) >> 1];
        do
        {
            while (aComparator(apItems[i], pivot))
                ++i;
            while (aComparator(pivot, apItems[iRight]))
                --iRight;
            if (iRight >= i)
            {
                if (iRight != i)
                {
                    ShapeDetail* pTemp = apItems[iRight];
                    apItems[iRight] = apItems[i];
                    apItems[i] = pTemp;
                }
                --iRight;
                ++i;
            }
        } while (i <= iRight);
        if (lo < iRight)
            QuickSortShapeDetails(apItems, lo, iRight, aComparator);
        if (i >= hi)
            break;
        lo = i;
    }
}

class hkObjXd1f230
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
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
    hkArray<void*> m_items;

    hkBool Contains(void* pv) const;
};

// Returns true if the pointer pv is found in the m_items array, otherwise false.
// @fnv 0x00d1f230
hkBool hkObjXd1f230::Contains(void* apItem) const
{
    for (int i = 0; i < m_items.m_iElementCount; i++)
    {
        if (m_items.m_data[i] == apItem)
            return true;
    }
    return false;
}

class PhantomOverlapRemoval : public hkpSimpleShapePhantom
{
  public:
    // Shared hkpSimpleShapePhantom lacks the 0x00ca9520 overlap notification helper.
    void NotifyAll(hkpCollidable* collidable, hkBool wasAdded) throw();
    void hkpSimpleShapePhantom_removeOverlappingCollidable(hkpCollidable* pkCollidable) throw();
};

// @fnv 0x00d1f5a0
// src: HAVOK_LIB 0x00d1f5a0
void PhantomOverlapRemoval::hkpSimpleShapePhantom_removeOverlappingCollidable(hkpCollidable* pkCollidable) throw()
{
    if (pkCollidable->getShape() != 0)
    {
        for (int i = m_kCollisionDetails.GetLogicalSize() - 1; i >= 0; i--)
        {
            if (m_kCollisionDetails[i].m_kCollidable == pkCollidable)
            {
                NotifyAll(pkCollidable, true);
                m_kCollisionDetails.removeAt(i);
                m_bOrderDirty = true;
                return;
            }
        }
        NotifyAll(pkCollidable, false);
    }
}

class hkClassD1F6;

extern const hkClassD1F6 DAT_0126902c;

int __cdecl hkStatisticsCollector_getAllocatedSize(const void* pvChunk, int iNumBytes) throw();

template <class T> inline void AddArrayStatistics(hkStatisticsCollector* collector, const char* name, const hkArray<T>& array)
{
    if ((array.m_iCapacityState & 0x80000000) == 0 || collector->m_reportInplaceAllocations)
    {
        const T* data = array.m_data;
        int allocated = hkStatisticsCollector_getAllocatedSize(data, array.getCapacity() * sizeof(T));
        collector->AddMemoryChunk(3, name, array.m_data, array.GetLogicalSize() * sizeof(T), allocated);
    }
}

class hkObjD1F6 : public hkpSimpleShapePhantom
{
  public:
    // 0x00d07cf0 is the phantom listener statistics helper, absent from the shared declaration.
    void WritePhantomLists(hkStatisticsCollector* collector, const hkClassD1F6* cls) const throw();

    void CollectStatistics(hkStatisticsCollector* pkCollector, const hkClassD1F6* pkClass) const throw();
};

// Collects the base phantom listener statistics, then reports the collision-detail array as "OverlapPtr".
// @fnv 0x00d1f620
void hkObjD1F6::CollectStatistics(hkStatisticsCollector* pkCollector, const hkClassD1F6* pkClass) const throw()
{
    WritePhantomLists(pkCollector, &DAT_0126902c);
    AddArrayStatistics(pkCollector, "OverlapPtr", m_kCollisionDetails);
}

extern "C" int __stdcall hkpPhantom_fireCollidableAdded(void* object);
extern "C" hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
void __cdecl ResizeAudioStream(void* allocator, void* array, int elementSize);

struct FUN_00d1f690_Member : hkpSimpleShapePhantom
{
    void AddCollisionDetail(void* object);
};

// If the object's first pointer is non-null and FUN_00ca94c0 returns 0, appends the object to the collision detail array, growing it when full, and sets a flag.
// @fnv 0x00d1f690
void FUN_00d1f690_Member::AddCollisionDetail(void* object)
{
    if (*reinterpret_cast<void**>(object) != 0)
    {
        if (hkpPhantom_fireCollidableAdded(object) == 0)
        {
            hkArray<hkpSimpleShapePhantomCollisionDetail>* details = &m_kCollisionDetails;
            hkMemoryRouter* router = hkMemoryRouter_getInstance();
            if (details->m_iElementCount == (details->m_iCapacityState & 0x3fffffff))
            {
                ResizeAudioStream(router->m_heap, details, 4);
            }
            void** slot = reinterpret_cast<void**>(details->m_data) + details->m_iElementCount;
            ++details->m_iElementCount;
            *slot = object;
            m_bOrderDirty = 1;
        }
    }
}

namespace fnv_00d1f6f0 {
struct hkLessD1F6
{
};

void __cdecl QuickSortShapeDetails(void** pArr, int iStart, int iEnd, hkLessD1F6 kCmp);

inline void quickSortD1F6(void** pArr, int iSize, hkLessD1F6 kCmp)
{
    if (iSize > 1)
        QuickSortShapeDetails(pArr, 0, iSize - 1, kCmp);
}

struct hkObjD1F6
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
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
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
    void** m_160;
    int m_164;
    int m_168;
    char m_16c;
    void SortAndClearFlag();
};

// If m_16c is set, sorts the m_160 array of m_164 elements with quickSortD1F6 and clears m_16c.
// @fnv 0x00d1f6f0
void hkObjD1F6::SortAndClearFlag()
{
    if (m_16c)
    {
        quickSortD1F6(m_160, m_164, hkLessD1F6());
        m_16c = 0;
    }
}
}  // namespace fnv_00d1f6f0

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

extern "C" hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
template <typename T, typename Allocator> __forceinline hkArray<T, Allocator>& hkArray<T, Allocator>::operator=(const hkArray& a)
{
    copyFromArray(*reinterpret_cast<hkMemoryAllocator*>(hkMemoryRouter_getInstance()->m_heap), a, hkTypeIsPod());
    return *this;
}

namespace fnv_00d1f7e0 {

extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance();

inline hkMemoryAllocator& heapD1F7(hkMemoryRouter& router)
{
    return *reinterpret_cast<hkMemoryAllocator*>(router.m_heap);
}

class FUN_00d1f730 : public hkpSimpleShapePhantom
{
  public:
    static __forceinline void* operator new(unsigned int uiSize) throw()
    {
        hkpWorldObject* p = (hkpWorldObject*)heapD1F7(hkMemoryRouter_getInstance()).blockAlloc(uiSize);
        p->m_usMemSizeAndFlags = (hkUint16)uiSize;
        return p;
    }
    static void operator delete(void* p) throw();

    const hkTransform& getTransform() const
    {
        return m_kMotionState.m_kMotionTransform;
    }
    const hkpCollidable* getCollidable() const { return &m_kCollidable; }
    // 0x00ca92a0 copies world-object properties; the shared header has no declaration yet.
    void CopyEntriesFrom(const hkpWorldObject* other) throw();

    FUN_00d1f730(const hkpShape* pkShape, const hkTransform& kTransform,
                 hkUint32 uiCollisionFilterInfo) throw();
    hkpWorldObject* ClonePhantom() const throw();
};

typedef char fnv_check_d1f7e0[(sizeof(FUN_00d1f730) == 0x170) ? 1 : -1];

// @fnv 0x00d1f7e0
hkpWorldObject* FUN_00d1f730::ClonePhantom() const throw()
{
    const hkpCollidable* pkCollidable = getCollidable();
    FUN_00d1f730* pkPhantom =
        new FUN_00d1f730(pkCollidable->getShape(), getTransform(), pkCollidable->GetFilterInfoForKey());
    pkPhantom->m_kPhantomOverlapListeners = m_kPhantomOverlapListeners;
    pkPhantom->m_kPhantomListeners = m_kPhantomListeners;
    pkPhantom->CopyEntriesFrom(this);
    return pkPhantom;
}
}  // namespace fnv_00d1f7e0

struct WorldD1F
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    hkpCollisionInput* m_pCollisionInput;
};
class PhantomD1F
{
  public:
    int unk000;
    int unk004;
    WorldD1F* m_pOwningWorld;
    int unk00C;
    hkpCdBody m_kCollisionBody;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
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
    hkArray<hkpCdBody*> m_overlaps;
    void DispatchOverlaps(void* collector, const hkpCollisionInput* input);
};
// @fnv 0x00d1f4a0
void PhantomD1F::DispatchOverlaps(void* collector, const hkpCollisionInput* apCollisionInput)
{
    if (!apCollisionInput)
        apCollisionInput = m_pOwningWorld->m_pCollisionInput;
    hkpCollisionDispatcher* dispatcher = apCollisionInput->m_pCollisionDispatcher;
    for (int i = m_overlaps.GetLogicalSize() - 1; i >= 0; i--)
    {
        hkpCdBody*& pOtherBody = m_overlaps[i];
        hkpCollisionDispatcher::GetClosestPointsFunc pAgentFunc =
            dispatcher
                ->m_agent2Funcs[dispatcher->m_agent2TypeMap[m_kCollisionBody.m_pCollisionShape->getType()]
                                                       [pOtherBody->m_pCollisionShape->getType()]]
                .m_pGetPenetrationsFunc;
        pAgentFunc(m_kCollisionBody, *pOtherBody, reinterpret_cast<const CollisionAgentContext&>(*apCollisionInput),
                   *static_cast<hkpCdPointCollector*>(collector));
    }
}

struct FUN_00d1f520_Collector
{
    int unk00;
    hkBool m_fHitDistance;
};

struct FUN_00d1f520_World
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
    hkpCollisionInput* m_pCollisionInput;
};
struct FUN_00d1f520_Phantom : public hkpSimpleShapePhantom
{
    void QueryPenetrations(FUN_00d1f520_Collector& collector, const hkpCollisionInput* input);
};
// Iterates collision details and calls the dispatcher's agent2 penetration query function, breaking early when the collector reports a hit distance.
// @fnv 0x00d1f520
void FUN_00d1f520_Phantom::QueryPenetrations(FUN_00d1f520_Collector& collector, const hkpCollisionInput* input)
{
    if (!input)
        input = static_cast<FUN_00d1f520_World*>(m_pOwningWorld)->m_pCollisionInput;
    hkpCollisionDispatcher* d = input->m_pCollisionDispatcher;
    for (int i = m_kCollisionDetails.m_iElementCount - 1; i >= 0; i--)
    {
        hkpSimpleShapePhantomCollisionDetail* pDetail = m_kCollisionDetails.m_data + i;
        int ta = m_kCollidable.m_pCollisionShape->getType();
        d->m_agent2Funcs[d->m_agent2TypeMap[ta][pDetail->m_kCollidable->m_pCollisionShape->getType()]]
            .m_pQueryPenetrationsFunc(reinterpret_cast<const hkpCdBody&>(m_kCollidable),
                                     reinterpret_cast<const hkpCdBody&>(*pDetail->m_kCollidable),
                                     reinterpret_cast<const CollisionAgentContext&>(*input),
                                     reinterpret_cast<hkpCdBodyPairCollector&>(collector));
        if (collector.m_fHitDistance)
            break;
    }
}

#include <xmmintrin.h>
struct FUN_00d1f450_Obj
{
    void hkpSimpleShapePhantom_setPositionAndLinearCast(int* a, int b, int c, int d);
    void hkpSimpleShapePhantom_setTransformAndLinearCast(int* source, int a, int b, int c);
};

// Copies 12 floats from source to this at float index 0x2C using SSE, then calls FUN_00d1f270 with source plus 0x30 bytes and a, b, c.
// @fnv 0x00d1f450
// src: HAVOK_SRC 0x00d1f450
void FUN_00d1f450_Obj::hkpSimpleShapePhantom_setTransformAndLinearCast(int* source, int a, int b, int c)
{
    float* destination = reinterpret_cast<float*>(this) + 0x2C;
    float* vectors = reinterpret_cast<float*>(source);

    _mm_store_ps(destination + 0, _mm_load_ps(vectors + 0));
    _mm_store_ps(destination + 4, _mm_load_ps(vectors + 4));
    _mm_store_ps(destination + 8, _mm_load_ps(vectors + 8));

    this->hkpSimpleShapePhantom_setPositionAndLinearCast(reinterpret_cast<int*>(reinterpret_cast<char*>(source) + 0x30), a, b, c);
}

namespace fnv_00d1f960 {
// @fnv 0x00d1f960
hkMemoryRouter* hkMemoryRouter_getInstance();
struct C : hkpSimpleShapePhantom
{
    void hkpSimpleShapePhantom_deallocateInternalArrays();
    void hkpShapePhantom_deallocateInternalArrays();
};
// src: HAVOK_LIB 0x00d1f960
void C::hkpSimpleShapePhantom_deallocateInternalArrays()
{
    if (m_kCollisionDetails.m_iElementCount == 0)
    {
        hkMemoryAllocator& allocator = reinterpret_cast<hkMemoryAllocator&>(hkMemoryRouter_getInstance()->heap());
        int flags = m_kCollisionDetails.m_iCapacityState;
        m_kCollisionDetails.m_iElementCount = 0;
        if ((flags & 0x80000000) == 0)
        {
            allocator.bufFree(m_kCollisionDetails.m_data, (flags & 0x3fffffff) * 4);
        }
        m_kCollisionDetails.m_data = 0;
        m_kCollisionDetails.m_iCapacityState = 0x80000000;
    }
    hkpShapePhantom_deallocateInternalArrays();
}
}  // namespace fnv_00d1f960
