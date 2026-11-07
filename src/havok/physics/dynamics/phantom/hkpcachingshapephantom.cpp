
// src/havok/physics/dynamics/phantom/hkpcachingshapephantom.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/phantom/hkpcachingshapephantom.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <string.h>
#include "../../../../../include/hkArray.h"
#include "../../../../../include/hkBool.h"
#include "../../../../../include/hkBoolResult.h"
#include "../../../../../include/hkpCollidable.h"
#include "../../../../../include/hkpWorldObject.h"
#include "../../../../../include/hkClass.h"
#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/hkStatisticsCollector.h"
#include "../../../../../include/hkVector4.h"
#include "../../../../../include/hkTransform.h"
#include "../../../../../include/hkAabb.h"
#include "../../../../../include/hkpShape.h"
#include "../../../../../include/hkpWorld.h"
#include "../../../../../include/hkpShapePhantom.h"
#include "../../../../../include/hkpCdBodyPairCollector.h"
#include "../../../../../include/hkpCollisionAgent.h"
#include "../../../../../include/hkpCollisionDispatcher.h"
#include "../../../../../include/hkpCollisionInput.h"

typedef unsigned short hkUint16;
typedef short hkInt16;
typedef unsigned __int64 hkUint64;

inline const hkpShape* hkpCollidable::getShape() const { return m_pCollisionShape; }
__forceinline unsigned int hkpCollidable::GetFilterInfoForKey() const { return m_kBroadPhaseHandle.m_uiCollisionFilterData; }

inline hkpShapeType hkpShape::getType() const
{
    return *reinterpret_cast<const hkpShapeType*>(&m_type);
}

void __cdecl SortEntriesByCollisionKey(void*, int, int, int);

// @fnv 0x00d4c910
// src: COMMUNITY 0x00d4c910
int hkpCachingShapePhantom_getType()
{
    return 2;
}

struct GskAgentInput;
struct WorldOperationEntry;

// The shared agent header does not yet declare its collision dispatch slots.
// Keep the calls here without introducing another definition of the agent.
__forceinline void ProcessAgent(hkpCollisionAgent* agent, const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                               const GskAgentInput& input, WorldOperationEntry& output)
{
    typedef void (__thiscall* Dispatch)(hkpCollisionAgent*, const hkpCdBody&, const hkpCdBody&,
                                       const GskAgentInput&, WorldOperationEntry&);
    reinterpret_cast<Dispatch>((*reinterpret_cast<void***>(agent))[4])(agent, bodyA, bodyB, input, output);
}

struct CollisionAgentPair
{
    hkpCollisionAgent* m_pCollisionAgent;
    hkpCollidable* m_kCollidable;
};

struct LinearCastParameters;
class hkpCdPointCollector;

// include/ has no hkpCachingShapePhantom.h yet; one real definition serves every function in this unit.
class hkpCachingShapePhantom : public hkpShapePhantom
{
public:
    hkArray<CollisionAgentPair> m_kCollisionDetails;
    hkBool m_bOrderDirty;

    static void* operator new(unsigned int uiSize) throw();
    static void operator delete(void* p) throw();
    hkpCachingShapePhantom(const hkpShape* shape, const hkTransform& transform, hkUint32 filter) throw();
    void ensureDeterministicOrder();
    void DispatchCollisionAgents(WorldOperationEntry& output, GskAgentInput* input);
    void GetPenetrations(hkpCdBodyPairCollector& collector, const hkpCollisionInput* input);
    hkBool ContainsCollidable(const hkpCollidable* collidable) const;
    void AddToCollector(hkStatisticsCollector* collector, const hkClass* cls) const throw();
    hkpWorldObject* clone_00d4d0d0() const throw();
    void removeOverlappingCollidable(hkpCollidable* collidable);
    // The shared hkBoolResult preserves NotifyAll's nontrivial byte-copy ABI.
    void NotifyAll(hkpCollidable* collidable, hkBoolResult found);
    int hkpPhantom_fireCollidableAdded(hkpCollidable* collidable) throw();
    void addOverlappingCollidable(hkpCollidable* collidable) throw();
    void QueryCollisionDetails();
    void hkpShapePhantom_deallocateInternalArrays();
    void deallocateInternalArrays();
    void hkpPhantom_updateBroadPhase(const hkAabb& aabb);
    void setPositionAndLinearCast(const hkVector4& position, const LinearCastParameters& input,
                    hkpCdPointCollector& collector, hkpCdPointCollector* startCollector);
    void CopyFrom(const hkTransform& transform, const LinearCastParameters& input,
                  hkpCdPointCollector& collector, hkpCdPointCollector* startCollector);
    void ReleaseCollisionAgents();
    hkpCachingShapePhantom* DeleteStorage(unsigned int flags);
};

void WritePhantomLists();
__forceinline void WritePhantomLists(const hkpCachingShapePhantom* object, hkStatisticsCollector* collector, const hkClass* cls)
{
    typedef void (__thiscall* Collect)(const hkpCachingShapePhantom*, hkStatisticsCollector*, const hkClass*);
    reinterpret_cast<Collect>(static_cast<void (*)()>(&WritePhantomLists))(object, collector, cls);
}

// @fnv 0x00d4d090
// src: HAVOK_SRC 0x00d4d090
void hkpCachingShapePhantom::ensureDeterministicOrder()
{
    if (m_bOrderDirty)
    {
        int size = m_kCollisionDetails.m_iElementCount;

        union
        {
            unsigned char byteValue;
            unsigned int value;
        } seed;

        seed.byteValue = 0;

        if (size > 1)
            SortEntriesByCollisionKey(m_kCollisionDetails.m_data, 0, size - 1, seed.value);

        m_bOrderDirty = 0;
    }
}

// @fnv 0x00d4c920
void hkpCachingShapePhantom::DispatchCollisionAgents(WorldOperationEntry& output, GskAgentInput* input)
{
    if (!input)
    {
        input = (GskAgentInput*)((hkpWorld*)this->m_pOwningWorld)->m_pCollisionInput;
    }
    for (int i = this->m_kCollisionDetails.m_iElementCount - 1; i >= 0; --i)
    {
        CollisionAgentPair* detail = &this->m_kCollisionDetails.m_data[i];
        ProcessAgent(detail->m_pCollisionAgent, *(hkpCdBody*)&this->m_kCollidable, *(hkpCdBody*)detail->m_kCollidable, *input, output);
    }
}

__forceinline void GetAgentPenetrations(hkpCollisionAgent* agent, const hkpCdBody& bodyA, const hkpCdBody& bodyB,
                                   const hkpCollisionInput& input, hkpCdBodyPairCollector& collector)
{
    typedef void (__thiscall* Dispatch)(hkpCollisionAgent*, const hkpCdBody&, const hkpCdBody&,
                                       const hkpCollisionInput&, hkpCdBodyPairCollector&);
    reinterpret_cast<Dispatch>((*reinterpret_cast<void***>(agent))[3])(agent, bodyA, bodyB, input, collector);
}

// The collector's early-out byte follows its vtable pointer; the shared header
// currently declares only its methods.
__forceinline const hkBool& earlyOutHit(const hkpCdBodyPairCollector& collector)
{
    return *reinterpret_cast<const hkBool*>(reinterpret_cast<const char*>(&collector) + sizeof(void*));
}

// Iterates the cached collision agent/collidable pairs and calls getPenetrations on each, stopping early if the collector signals an early-out hit.
// @fnv 0x00d4c980
void hkpCachingShapePhantom::GetPenetrations(hkpCdBodyPairCollector& collector,
                                                     const hkpCollisionInput* input)
{
    if (!input)
    {
        input = (const hkpCollisionInput*)((hkpWorld*)m_pOwningWorld)->m_pCollisionInput;
    }

    for (int i = m_kCollisionDetails.m_iElementCount - 1; i >= 0; i--)
    {
        CollisionAgentPair* detail = &m_kCollisionDetails.m_data[i];
        GetAgentPenetrations(detail->m_pCollisionAgent, *(hkpCdBody*)&m_kCollidable, *(hkpCdBody*)detail->m_kCollidable, *input, collector);
        if (earlyOutHit(collector))
        {
            break;
        }
    }
}

// Searches the collision detail array for an entry whose collidable pointer equals pkCollidable and returns true if found, otherwise false.
// @fnv 0x00d4c9e0
hkBool hkpCachingShapePhantom::ContainsCollidable(const hkpCollidable* pkCollidable) const
{
    for (int i = 0; i < m_kCollisionDetails.GetLogicalSize(); i++)
    {
        if (m_kCollisionDetails[i].m_kCollidable == pkCollidable)
            return true;
    }
    return false;
}

extern const hkClass DAT_0126902c;

int __cdecl hkStatisticsCollector_getAllocatedSize(const void* pvChunk, int iNumBytes) throw();

// The collector header lacks the one-argument beginObject and this unit's virtual slot ordering.
__forceinline void BeginAgentCollection(hkStatisticsCollector* collector, const char* name)
{
    typedef void (__thiscall* Dispatch)(hkStatisticsCollector*, const char*);
    reinterpret_cast<Dispatch>((*reinterpret_cast<void***>(collector))[6])(collector, name);
}
__forceinline void EndAgentCollection(hkStatisticsCollector* collector)
{
    typedef void (__thiscall* Dispatch)(hkStatisticsCollector*);
    reinterpret_cast<Dispatch>((*reinterpret_cast<void***>(collector))[7])(collector);
}
__forceinline void CollectChildAgent(hkStatisticsCollector* collector, const char* name, const void* object, const void* cls)
{
    typedef void (__thiscall* Dispatch)(hkStatisticsCollector*, const char*, const void*, const void*);
    reinterpret_cast<Dispatch>((*reinterpret_cast<void***>(collector))[3])(collector, name, object, cls);
}
template <class T> __forceinline void CollectAgentArray(hkStatisticsCollector* collector, const char* name, const hkArray<T>& array)
{
    if ((array.m_iCapacityState & 0x80000000) == 0 || collector->m_reportInplaceAllocations)
    {
        int allocated = hkStatisticsCollector_getAllocatedSize(array.m_data, array.getCapacity() * sizeof(T));
        typedef void (__thiscall* Dispatch)(hkStatisticsCollector*, int, const char*, const void*, int, int);
        reinterpret_cast<Dispatch>((*reinterpret_cast<void***>(collector))[5])(
            collector, 3, name, array.m_data, array.GetLogicalSize() * sizeof(T), allocated);
    }
}

// Adds this phantom's base data and its AgentPtr array to the collector, then reports each collision agent as a child object under "agents".
// @fnv 0x00d4cd60
void hkpCachingShapePhantom::AddToCollector(hkStatisticsCollector* pkCollector,
                                                const hkClass* pkClass) const throw()
{
    WritePhantomLists(this, pkCollector, &DAT_0126902c);
    CollectAgentArray(pkCollector, "AgentPtr", m_kCollisionDetails);
    BeginAgentCollection(pkCollector, "agents");
    for (int i = 0; i < m_kCollisionDetails.GetLogicalSize(); i++)
        CollectChildAgent(pkCollector, 0, m_kCollisionDetails.m_data[i].m_pCollisionAgent, 0);
    EndAgentCollection(pkCollector);
}

extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance();

__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*) { return hkMemoryRouter_getInstance().heap(); }

template <typename T> T* hkMemoryAllocator::_bufAlloc(int& requested)
{
    int bytes = requested * sizeof(T);
    void* p = bufAlloc(bytes);
    requested = bytes / (int)sizeof(T);
    return (T*)p;
}
template <typename T> void hkMemoryAllocator::_bufFree(void* p, int count)
{
    bufFree(p, count * sizeof(T));
}
template <typename T, typename A> __forceinline hkArray<T, A>& hkArray<T, A>::operator=(const hkArray& other)
{
    hkMemoryAllocator& alloc = hkMemoryRouter_getInstance().heap();
    if (getCapacity() < other.GetLogicalSize())
    {
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc._bufFree<T>(m_data, getCapacity());
        int n = other.GetLogicalSize();
        m_data = alloc._bufAlloc<T>(n);
        m_iCapacityState = n;
    }
    m_iElementCount = other.GetLogicalSize();
    hkArrayBase<T>::copy(m_data, other.m_data, m_iElementCount);
    return *this;
}
template <typename T> __forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& alloc)
{
    m_iElementCount = 0;
    if ((m_iCapacityState & 0x80000000) == 0)
        alloc.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
    m_data = 0;
    m_iCapacityState = 0x80000000;
}

// hkpWorldObject.h lacks CopyEntriesFrom; preserve its thiscall through a local call adapter.
void CopyWorldObjectEntries();
__forceinline void CopyWorldObjectEntries(hkpWorldObject* object, const hkpWorldObject* other)
{
    typedef void (__thiscall* Copy)(hkpWorldObject*, const hkpWorldObject*);
    reinterpret_cast<Copy>(static_cast<void (*)()>(&CopyWorldObjectEntries))(object, other);
}

__forceinline void* hkpCachingShapePhantom::operator new(unsigned int uiSize) throw()
{
    hkpWorldObject* p = (hkpWorldObject*)hkMemoryRouter_getInstance().heap().blockAlloc(uiSize);
    p->m_usMemSizeAndFlags = (hkUint16)uiSize;
    return p;
}

typedef char fnv_check_d4d0d0[(sizeof(hkpCachingShapePhantom) == 0x170) ? 1 : -1];

// @fnv 0x00d4d0d0
// src: HAVOK_SRC 0x00d4d0d0
hkpWorldObject* hkpCachingShapePhantom::clone_00d4d0d0() const throw()
{
    const hkpCollidable* pkCollidable = &m_kCollidable;
    hkpCachingShapePhantom* pkPhantom =
        new hkpCachingShapePhantom(pkCollidable->getShape(), m_kMotionState.m_kMotionTransform, pkCollidable->GetFilterInfoForKey());
    pkPhantom->m_kPhantomOverlapListeners = m_kPhantomOverlapListeners;
    pkPhantom->m_kPhantomListeners = m_kPhantomListeners;
    CopyWorldObjectEntries(pkPhantom, this);
    return pkPhantom;
}

struct CollisionTarget
{
    int unknown00;
    int unknown04;
    int unknown08;
    int unknown0c;
    int unknown10;
    unsigned int collisionKey;
};
struct CollisionKeyEntry
{
    int shapeKey;
    CollisionTarget* target;
};
// Recursively quicksorts entries by their target's collisionKey, partitioning around a pivot and swapping out-of-order elements.
// @fnv 0x00d4d250
void __cdecl SortEntriesByCollisionKey(CollisionKeyEntry* entries, int left, int right, int context)
{
    int i = left;
    int iRight = right;
    __declspec(align(16)) CollisionKeyEntry pivotEntry = entries[(i + iRight) >> 1];
    do
    {
        while (entries[i].target->collisionKey < pivotEntry.target->collisionKey)
            ++i;
        while (pivotEntry.target->collisionKey < entries[iRight].target->collisionKey)
            --iRight;
        if (iRight < i)
            break;
        if (iRight != i)
        {
            CollisionKeyEntry tempEntry = entries[iRight];
            entries[iRight] = entries[i];
            entries[i] = tempEntry;
        }
        --iRight;
        ++i;
    } while (i <= iRight);
    if (left < iRight)
        SortEntriesByCollisionKey(entries, left, iRight, context);
    if (i < right)
        SortEntriesByCollisionKey(entries, i, right, context);
}

// @fnv 0x00d4d310
hkpCachingShapePhantom* hkpCachingShapePhantom::DeleteStorage(unsigned int flags)
{
    ReleaseCollisionAgents();
    if (flags & 1)
        hkMemoryRouter_getInstance().heap().blockFree(this, m_usMemSizeAndFlags);
    return this;
}

// Copies the rotation columns, then casts from the transform's translation.
// @fnv 0x00d4cc50
void hkpCachingShapePhantom::CopyFrom(const hkTransform& transform, const LinearCastParameters& input,
                                    hkpCdPointCollector& collector, hkpCdPointCollector* startCollector)
{
    m_kMotionState.m_kMotionTransform.m_kColumn0 = transform.m_kColumn0;
    m_kMotionState.m_kMotionTransform.m_kColumn1 = transform.m_kColumn1;
    m_kMotionState.m_kMotionTransform.m_kColumn2 = transform.m_kColumn2;
    setPositionAndLinearCast(*reinterpret_cast<const hkVector4*>(&transform.m_vTranslation), input, collector, startCollector);
}

extern int DAT_010ccebc;

// Stack constraint owner: cleanup slot 7 receives the object with vtable 0x010ccebc.
struct PhantomConstraintOwner
{
    int* m_vtbl;
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
    int unk08, unk0C, unk10, unk14;
};

__forceinline void cleanupCollisionAgent(hkpCollisionAgent* agent, PhantomConstraintOwner* owner)
{
    typedef void (__thiscall* Dispatch)(hkpCollisionAgent*, PhantomConstraintOwner*);
    reinterpret_cast<Dispatch>((*reinterpret_cast<void***>(agent))[7])(agent, owner);
}

inline void CopyFourByteWords(void* dst, const void* src, int nbytes)
{
    for (int i = 0; i < nbytes; i += 4)
        *(unsigned int*)((char*)dst + i) = *(const unsigned int*)((const char*)src + i);
}

template <typename T> __forceinline void hkArrayBase<T>::removeAt(int index)
{
    m_iElementCount--;
    if (m_iElementCount != index)
        CopyFourByteWords(m_data + index, m_data + m_iElementCount, sizeof(T));
}

// Removes a cached collidable, notifies overlap listeners, and marks the ordering dirty.
// @fnv 0x00d4cca0
// src: HAVOK_LIB 0x00d4cca0
void hkpCachingShapePhantom::removeOverlappingCollidable(hkpCollidable* apOwned)
{
    PhantomConstraintOwner visitor;
    visitor.m_sReferenceCount = 1;
    visitor.m_vtbl = &DAT_010ccebc;
    if (!apOwned->m_pCollisionShape)
        return;
    for (int i = m_kCollisionDetails.GetLogicalSize() - 1; i >= 0; i--)
    {
        if (m_kCollisionDetails[i].m_kCollidable == apOwned)
        {
            NotifyAll(apOwned, hkBoolResult(true));
            if (m_kCollisionDetails[i].m_pCollisionAgent)
                cleanupCollisionAgent(m_kCollisionDetails[i].m_pCollisionAgent, &visitor);
            m_kCollisionDetails.removeAt(i);
            m_bOrderDirty = 1;
            return;
        }
    }
    NotifyAll(apOwned, hkBoolResult(false));
}

void ResizeAudioStream(void* pvAlloc, void* apvArray, int iSizeElem) throw();

template <typename T> __forceinline T& hkArrayBase<T>::_expandOne(hkMemoryAllocator& alloc)
{
    if (m_iElementCount == getCapacity())
        ResizeAudioStream(&alloc, this, sizeof(T));
    return m_data[m_iElementCount++];
}

// The game selects the PSI quality (index 1), at dispatcher offset 0x1c60.
// The old one-int quality stand-in incorrectly described that address as index 0.
__forceinline hkpCollisionQualityInfo* hkpCollisionDispatcher::getCollisionQualityInfo(CollisionQualityIndex index)
{
    return &m_pCollisionQualityInfo[index];
}

// Preserve this unit's inline 0x50-byte collision-input copy.
inline hkpCollisionInput::hkpCollisionInput(const hkpCollisionInput& other)
{
    memcpy(this, &other, sizeof(*this));
}

struct hkpProcessCollisionInput : public hkpCollisionInput
{
    hkReal m_uiStartTime;
    hkReal m_fEndTime;
    hkReal m_fTimeStep;
    hkReal m_fInverseDeltaTime;
    hkpCollisionQualityInfo* m_pCollisionQualityInfo;
    void* m_pAgent1nSector;
    void* m_pCollisionFilter;
    hkBool m_bEnableDeprecatedWelding;
    hkBool m_bAllowToSkipConfirmedCallbacks;
    void* m_pConfiguration;

    __forceinline static void* operator new(size_t, void* storage) { return storage; }

    __forceinline hkpProcessCollisionInput(const hkpProcessCollisionInput& kOther) throw() : hkpCollisionInput(kOther)
    {
        m_pAgent1nSector = 0;
        FUN_00cfa7d0(kOther);
    }
    ~hkpProcessCollisionInput() throw()
    {
        if (m_pAgent1nSector)
            hkMemoryRouter_getInstance().heap().blockFree(m_pAgent1nSector, 0x200);
    }
    void FUN_00cfa7d0(const hkpProcessCollisionInput& kOther);
};

// The shared dispatcher exposes the tables but has no agent-creation convenience method.
__forceinline hkpCollisionAgent* CreateCachedCollisionAgent(const hkpCollisionDispatcher* dispatcher,
    const hkpCdBody& kBodyA, const hkpCdBody& kBodyB, const hkpProcessCollisionInput& kInput, hkpContactMgr* pvMgr)
{
    int iTypeA = kBodyA.m_pCollisionShape->getType();
    int iTypeB = kBodyB.m_pCollisionShape->getType();
    const hkUint8* pTypes = kInput.m_bCreatePredictiveAgents
        ? &dispatcher->m_agent3TypeMap[0][0] : &dispatcher->m_agent2TypeMap[0][0];
    int iIdx = pTypes[iTypeA * 32 + iTypeB];
    hkpCollisionDispatcher::CreateFunc pfnCreate = dispatcher->m_agent2Funcs[iIdx].m_pCreateFunc;
    return pfnCreate(kBodyA, kBodyB, reinterpret_cast<const CollisionAgentContext&>(kInput), pvMgr);
}

// Use pointer storage for the local input: the original function has no GS cookie.
// @fnv 0x00d4cf10
// src: HAVOK_SRC 0x00d4cf10
void hkpCachingShapePhantom::addOverlappingCollidable(hkpCollidable* pkCollidable) throw()
{
    if (pkCollidable->m_pCollisionShape != 0 && hkpPhantom_fireCollidableAdded(pkCollidable) == 0)
    {
        CollisionAgentPair& kDetail = m_kCollisionDetails.expandOne();
        __declspec(align(16)) void* inputStorage[sizeof(hkpProcessCollisionInput) / sizeof(void*)];
        hkpProcessCollisionInput& kInput = *new (inputStorage) hkpProcessCollisionInput(
            *(hkpProcessCollisionInput*)((hkpWorld*)m_pOwningWorld)->m_pCollisionInput);
        kInput.m_bCreatePredictiveAgents = false;
        kInput.m_pCollisionQualityInfo = kInput.m_pCollisionDispatcher->getCollisionQualityInfo(static_cast<hkpCollisionDispatcher::CollisionQualityIndex>(
            hkpCollisionDispatcher::COLLISION_QUALITY_PSI));
        kDetail.m_pCollisionAgent =
            CreateCachedCollisionAgent(kInput.m_pCollisionDispatcher, *(hkpCdBody*)&m_kCollidable, *(hkpCdBody*)pkCollidable, kInput, 0);
        kDetail.m_kCollidable = pkCollidable;
        m_bOrderDirty = true;
        kInput.~hkpProcessCollisionInput();
    }
}

__forceinline void queryCollisionAgent(hkpCollisionAgent* agent, void* a, hkpCollidable* b, int* c, void* d)
{
    typedef void (__thiscall* Dispatch)(hkpCollisionAgent*, void*, hkpCollidable*, int*, void*);
    reinterpret_cast<Dispatch>((*reinterpret_cast<void***>(agent))[8])(agent, a, b, c, d);
}

__declspec(align(8)) struct QueryDC4A30
{
    int m_pOwningWorld;
    hkUint16 m_unk04;
    hkUint16 m_type;
    hkUint64 m_unk08;
    hkUint64 m_unk10;
};

// Copies 0x50 bytes from the pointer at (this->8)+0x78 into a local buffer, then calls v20 on each collision detail entry with it and a type-1 query.
// @fnv 0x00d4ca30
void hkpCachingShapePhantom::QueryCollisionDetails()
{
    QueryDC4A30 query;
    __declspec(align(16)) int buffer[20];

    char* src = (char*)((hkpWorld*)m_pOwningWorld)->m_pCollisionInput;
    memcpy(buffer, src, 0x50);

    query.m_type = 1;
    query.m_pOwningWorld = (int)&DAT_010ccebc;

    for (int i = 0; i < m_kCollisionDetails.m_iElementCount; ++i)
    {
        CollisionAgentPair* pair = m_kCollisionDetails.m_data + i;
        queryCollisionAgent(pair->m_pCollisionAgent, &m_kCollidable, pair->m_kCollidable, buffer, &query);
    }
}

// Releases m_kCollisionDetails's buffer when its element count is 0, then calls FUN_00c9e820.
// @fnv 0x00d4d030
// src: HAVOK_LIB 0x00d4d030
void hkpCachingShapePhantom::deallocateInternalArrays()
{
    if (m_kCollisionDetails.m_iElementCount == 0)
        m_kCollisionDetails.clearAndDeallocate();
    hkpShapePhantom_deallocateInternalArrays();
}

namespace CastSimd {
// Exe 0x00d4cab0 FUN_00d4cab0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float f[4];
    unsigned __int64 u[2];
} __m128, LocalM128;
extern "C"
{
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_min_ps(LocalM128, LocalM128);
    LocalM128 _mm_max_ps(LocalM128, LocalM128);
    LocalM128 _mm_setzero_ps(void);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_sqrt_ss(LocalM128);
    float _mm_cvtss_f32(LocalM128);
}
}

extern float DAT_0104da4c;

struct GskAgentInput : public hkpCollisionInput
{
    int m_pad50;
    int m_pad54;
    int m_pad58;
    int m_pad5c;
    int m_pad60;
    int m_pad64;
    int m_pad68;
    int m_pad6c;
    void* m_pConfiguration;
};

struct ShapeSweepParameters : public hkpCollisionInput
{
    hkVector4 m_path;
    hkReal m_fMaxExtraPenetration;
    hkReal m_cachedDistances;
    void* m_pConfiguration;

    __forceinline void set(const GskAgentInput& input)
    {
        m_pCollisionDispatcher.m_storage = input.m_pCollisionDispatcher.m_storage;
        m_collisionQuality.m_storage = input.m_collisionQuality.m_storage;
        *reinterpret_cast<int*>(&m_fScalar.m_storage) = *reinterpret_cast<const int*>(&input.m_fScalar.m_storage);
        m_iFilter.m_storage = input.m_iFilter.m_storage;
        m_pConvexListCollisionFilter.m_storage = input.m_pConvexListCollisionFilter.m_storage;
        m_bCreatePredictiveAgents = input.m_bCreatePredictiveAgents;
        *(CastSimd::LocalM128*)&m_aiValues.m_kAabbMin = *(CastSimd::LocalM128*)&input.m_aiValues.m_kAabbMin;
        *(CastSimd::LocalM128*)&m_aiValues.m_kAabbMaximum = *(CastSimd::LocalM128*)&input.m_aiValues.m_kAabbMaximum;
        *(CastSimd::LocalM128*)&m_aiValues.m_kAabbScale = *(CastSimd::LocalM128*)&input.m_aiValues.m_kAabbScale;
        m_pConfiguration = input.m_pConfiguration;
    }
};

struct LinearCastParameters
{
    hkVector4 m_vTo;
    hkReal m_fMaxExtraPenetrationAgainstFixed;
    hkReal m_fMaxExtraPenetration;
};

__forceinline void linearCast(hkpCollisionAgent* agent, const hkpCdBody& a, const hkpCdBody& b,
                              const ShapeSweepParameters& input, hkpCdPointCollector& castCollector,
                              hkpCdPointCollector* startCollector)
{
    typedef void (__thiscall* Dispatch)(hkpCollisionAgent*, const hkpCdBody&, const hkpCdBody&,
                                       const ShapeSweepParameters&, hkpCdPointCollector&, hkpCdPointCollector*);
    reinterpret_cast<Dispatch>((*reinterpret_cast<void***>(agent))[5])(agent, a, b, input, castCollector, startCollector);
}

// Performs a linear cast against collidables by computing an expanded AABB and invoking linearCast on each collision agent pair.
// @fnv 0x00d4cab0
// src: HAVOK_SRC 0x00d4cab0
void hkpCachingShapePhantom::setPositionAndLinearCast(const hkVector4& position, const LinearCastParameters& input,
                                               hkpCdPointCollector& castCollector, hkpCdPointCollector* startCollector)
{
    *(CastSimd::LocalM128*)&m_kMotionState.m_kMotionTransform.m_vTranslation = *(CastSimd::LocalM128*)&position;

    // These outputs are filled below without calling the out-of-line vector constructors.
    __declspec(align(16)) void* aabbStorage[sizeof(hkAabb) / sizeof(void*)];
    hkAabb& aabb = *reinterpret_cast<hkAabb*>(aabbStorage);
    hkReal tol =
        (hkReal)(((GskAgentInput*)((hkpWorld*)m_pOwningWorld)->m_pCollisionInput)->m_fScalar * 0.5) + input.m_fMaxExtraPenetration;
    m_kCollidable.m_pCollisionShape->CalculateAabb(m_kMotionState.m_kMotionTransform, tol, aabb);

    CastSimd::LocalM128 path = CastSimd::_mm_sub_ps(*(CastSimd::LocalM128*)&input.m_vTo, *(CastSimd::LocalM128*)&position);

    CastSimd::LocalM128 zero = CastSimd::_mm_setzero_ps();
    CastSimd::LocalM128 minVal = CastSimd::_mm_min_ps(zero, path);
    CastSimd::LocalM128 maxVal = CastSimd::_mm_max_ps(zero, path);

    CastSimd::LocalM128 auiLowerBounds = *(CastSimd::LocalM128*)&aabb.m_kMinimumCorner;
    CastSimd::LocalM128 auiUpperBounds = *(CastSimd::LocalM128*)&aabb.m_kMaximumCorner;

    auiLowerBounds = CastSimd::_mm_add_ps(minVal, auiLowerBounds);
    auiUpperBounds = CastSimd::_mm_add_ps(maxVal, auiUpperBounds);

    *(CastSimd::LocalM128*)&aabb.m_kMinimumCorner = auiLowerBounds;
    *(CastSimd::LocalM128*)&aabb.m_kMaximumCorner = auiUpperBounds;

    hkpPhantom_updateBroadPhase(aabb);

    // The shared collision input has no default constructor; initialize the sweep storage here.
    __declspec(align(16)) void* linearInputStorage[sizeof(ShapeSweepParameters) / sizeof(void*)];
    ShapeSweepParameters& linearInput = *reinterpret_cast<ShapeSweepParameters*>(linearInputStorage);
    linearInput.m_fMaxExtraPenetration = DAT_0104da4c;
    linearInput.m_collisionQuality.m_storage = 0;
    linearInput.set(*(GskAgentInput*)((hkpWorld*)m_pOwningWorld)->m_pCollisionInput);

    *(CastSimd::LocalM128*)&linearInput.m_path = path;

    CastSimd::LocalM128 sq = CastSimd::_mm_mul_ps(path, path);
    CastSimd::LocalM128 sh1 = CastSimd::_mm_shuffle_ps(sq, sq, 0x55);
    CastSimd::LocalM128 sh2 = CastSimd::_mm_shuffle_ps(sq, sq, 0xAA);
    CastSimd::LocalM128 add1 = CastSimd::_mm_add_ss(sh1, sq);
    CastSimd::LocalM128 add2 = CastSimd::_mm_add_ss(sh2, add1);
    CastSimd::LocalM128 len = CastSimd::_mm_sqrt_ss(add2);

    linearInput.m_cachedDistances = CastSimd::_mm_cvtss_f32(len);

    linearInput.m_fScalar = input.m_fMaxExtraPenetration;
    linearInput.m_fMaxExtraPenetration = input.m_fMaxExtraPenetrationAgainstFixed;

    for (int i = m_kCollisionDetails.m_iElementCount - 1; i >= 0; --i)
    {
        CollisionAgentPair* detail = &((CollisionAgentPair*)m_kCollisionDetails.m_data)[i];
        linearCast(detail->m_pCollisionAgent, *(hkpCdBody*)&m_kCollidable, *(hkpCdBody*)detail->m_kCollidable, linearInput, castCollector,
                         startCollector);
    }
}
