
// src/havok/physics/dynamics/phantom/hkpphantom.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/phantom/hkpphantom.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Exe 0x00d07950 FUN_00d07950: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef struct __declspec(intrin_type) __declspec(align(16)) {
    float x, y, z, w;
} __m128, LocalM128;

#include "../../../../../include/hkArray.h"
#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkpPhantom.h"
#include "../../../../../include/hkAabb.h"
#include "../../../../../include/hkVector4.h"
#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/hkpWorld.h"
#include "../../../../../include/hkpBroadPhaseHandle.h"
#include "../../../../../include/hkpBroadPhase.h"
#include "../../../../../include/hkpCollisionFilter.h"
#include "../../../../../include/hkpCollidableCollidableFilter.h"
#include "../../../../../include/hkpPhantomListener.h"

class PhArchive;
struct PhTag;
// Data-free adapter for hkpPhantom methods missing from its shared declaration.
// 0x00d07950 and 0x00d07ec0 access only hkpPhantom state, not hkpAabbPhantom bounds.
struct PhantomOperations : hkpPhantom {
    void NotifyListeners();
    void hkpPhantom_removeNullPhantomListeners();
    void hkpPhantom_removeNullOverlapListeners();
    void RemoveListener(void* listener);
    void WriteToStream(PhArchive*, PhTag*);
    void WritePhantomLists(PhArchive*, int);
    void hkpPhantom_setBoundingVolumeData(const hkAabb&);
    void hkpPhantom_firePhantomRemoved();
    void AddItem(void*);
    void hkpPhantom_updateBroadPhase(const hkAabb&) throw();
    void NotifyElements();
};

// 0x00c85750 returns the shared router record: stack cursor +0x00, heap allocator +0x10.

__forceinline bool areCriticalOperationsLockedForPhantoms(const hkpWorld* world) {
    return world->m_iCriticalOperationsLockCountForPhantoms + world->m_iCriticalOperationsLockCount != 0;
}

__forceinline void hkpWorld::lockCriticalOperations() { m_iCriticalOperationsLockCount++; }
__forceinline void hkpWorld::unlockCriticalOperations() { m_iCriticalOperationsLockCount--; }
__forceinline void hkpWorld::attemptToExecutePendingOperations(bool) {
    if (m_iCriticalOperationsLockCount == 0 && !m_bBlockExecutingPendingOperations) {
        if (m_iPendingOperationCount) ExecutePendingOperations();
        if (m_iPendingOperationQueueCount == 1 && m_iQueuedOperationCount) ExecutePendingOperationQueues();
    }
}
__forceinline void hkpWorld::unlockAndAttemptToExecutePendingOperations() {
    unlockCriticalOperations();
    attemptToExecutePendingOperations();
}

typedef unsigned int hkUint32;

// Notifies phantom shape-set listeners in reverse, then compacts null entries.
// @fnv 0x00d07bd0
void PhantomOperations::NotifyListeners()
{
    for (int i = m_kPhantomListeners.GetLogicalSize() - 1; i >= 0; i--) {
        if (m_kPhantomListeners[i] != 0)
            static_cast<hkpPhantomListener*>(m_kPhantomListeners[i])->phantomShapeSetCallback(this);
    }
    hkpPhantom_removeNullPhantomListeners();
}

// @fnv 0x00d07c10
void PhantomOperations::RemoveListener(void* listener) {
    int foundIndex;
    int index = 0;
    int count = m_kPhantomListeners.m_iElementCount;
    if (count > 0) {
        void** ppCurrent = m_kPhantomListeners.m_data;
        do {
            if (*ppCurrent == listener) {
                foundIndex = index;
                goto found;
            }
            ++index;
            ++ppCurrent;
        } while (index < count);
    }
    foundIndex = -1;
found:
    --(volatile int&)m_kPhantomListeners.m_iElementCount;
    int bytes = ((volatile int&)m_kPhantomListeners.m_iElementCount - foundIndex) * 4;
    void** destination = m_kPhantomListeners.m_data + foundIndex;
    void** source = destination + 1;
    for (int offset = 0; offset < bytes; offset += 4) {
        *(void**)((char*)destination + offset) = *(void**)((char*)source + offset);
    }
}

class PhArchive {
public:
    char unk04[0xc];
    char m_flag;
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void Write(int type, const char* name, void* ptr, int size, int extra);
};
extern PhTag DAT_01268808;
int hkStatisticsCollector_getAllocatedSize(void* p, int n);

// Writes the overlap and phantom lists to the archive via Write, after calling WriteToStream with DAT_01268808.
// @fnv 0x00d07cf0
void PhantomOperations::WritePhantomLists(PhArchive* pArchive, int unused)
{
    WriteToStream(pArchive, &DAT_01268808);
    int overlapCapacity = m_kPhantomOverlapListeners.m_iCapacityState;
    if (!(overlapCapacity & 0x80000000) || pArchive->m_flag) {
        void* base = m_kPhantomOverlapListeners.m_data;
        int e = hkStatisticsCollector_getAllocatedSize(base, (overlapCapacity & 0x3fffffff) * 4);
        pArchive->Write(3, "OvrlapLisPtr", m_kPhantomOverlapListeners.m_data, m_kPhantomOverlapListeners.m_iElementCount * 4, e);
    }
    int listenerCapacity = m_kPhantomListeners.m_iCapacityState;
    if (!(listenerCapacity & 0x80000000) || pArchive->m_flag) {
        void* base = m_kPhantomListeners.m_data;
        int e = hkStatisticsCollector_getAllocatedSize(base, (listenerCapacity & 0x3fffffff) * 4);
        pArchive->Write(3, "PhantmLisPtr", m_kPhantomListeners.m_data, m_kPhantomListeners.m_iElementCount * 4, e);
    }
}

extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance();

__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return hkMemoryRouter_getInstance().heap();
}

template <typename T>
__forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& alloc)
{
    m_iElementCount = 0;
    if ((m_iCapacityState & 0x80000000) == 0)
        alloc.bufFree(m_data, getCapacity() * sizeof(T));
    m_data = 0;
    m_iCapacityState = 0x80000000;
}

template <typename T, typename Allocator>
__forceinline hkArray<T, Allocator>::~hkArray()
{
    this->_clearAndDeallocate(Allocator().get(this));
}

template <typename T>
__forceinline void hkArrayBase<T>::removeAtAndCopy(int index)
{
    m_iElementCount--;
    char* dst = reinterpret_cast<char*>(m_data + index);
    const char* src = reinterpret_cast<const char*>(m_data + index + 1);
    int bytes = (m_iElementCount - index) * sizeof(T);
    for (int i = 0; i < bytes; i += 4)
        *reinterpret_cast<unsigned int*>(dst + i) = *reinterpret_cast<const unsigned int*>(src + i);
}

void __cdecl ResizeAudioStream(void* pool, void* array, int sizeElem);

template <typename T>
__forceinline void hkArrayBase<T>::_pushBack(hkMemoryAllocator& alloc, const T& e)
{
    if (m_iElementCount == getCapacity())
        ResizeAudioStream(&alloc, this, sizeof(T));
    const unsigned int* src = reinterpret_cast<const unsigned int*>(&e);
    unsigned int* dst = reinterpret_cast<unsigned int*>(m_data + m_iElementCount);
    int i = 0;
    do {
        dst[i] = src[i];
    } while (++i < sizeof(T) / 4);
    m_iElementCount++;
}

// Frees the overlap-listener and phantom-listener arrays when they are empty, releasing their buffers through the memory router's heap.
// @fnv 0x00d07e20
void hkpPhantom::FreeListenerArrays() throw()
{
    if (m_kPhantomOverlapListeners.m_iElementCount == 0)
        m_kPhantomOverlapListeners._clearAndDeallocate(hkMemoryRouter_getInstance().heap());
    if (m_kPhantomListeners.m_iElementCount == 0)
        m_kPhantomListeners._clearAndDeallocate(hkMemoryRouter_getInstance().heap());
}

#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged

extern "C" LocalM128 _mm_add_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_min_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_max_ps(LocalM128, LocalM128);

extern float DAT_011b6d70;
extern float DAT_01267e30;

// World +0x78 is m_pCollisionInput; its quantization vectors are at +0x20, +0x30 and +0x40.
struct CollisionInputQuantizationData {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    hkReal m_vOffsetLow[4];
    hkReal m_vOffsetHigh[4];
    hkReal m_vScale[4];
};

__forceinline int hkToIntFastD07950(hkReal r)
{
    return fnv_FloatToInt(r);
}

__forceinline hkReal compAtD07950(const hkVector4& v, int i)
{
    const hkReal* p = &v.x;
    return p[i];
}

__forceinline void zeroExpD07950(hkpCollidableBoundingVolumeData& b)
{
    b.m_ucExpansionShift = 0;
    b.m_ucExpansionMin[0] = 0;
    b.m_ucExpansionMin[1] = 0;
    b.m_ucExpansionMin[2] = 0;
    b.m_ucExpansionMax[0] = 0;
    b.m_ucExpansionMax[1] = 0;
    b.m_ucExpansionMax[2] = 0;
}

// @fnv 0x00d07950
// src: XBOX_PDB 0x00d07950
void PhantomOperations::hkpPhantom_setBoundingVolumeData(const hkAabb& aabb)
{
    CollisionInputQuantizationData* collisionInput = static_cast<CollisionInputQuantizationData*>(static_cast<hkpWorld*>(m_pOwningWorld)->m_pCollisionInput);
    const LocalM128 vClampMax = *(const LocalM128*)&DAT_011b6d70;

    LocalM128 vMin = _mm_add_ps(*(const LocalM128*)&collisionInput->m_vOffsetLow, *(const LocalM128*)&aabb.m_kMinimumCorner);
    vMin = _mm_mul_ps(vMin, *(const LocalM128*)&collisionInput->m_vScale);
    vMin = _mm_min_ps(vMin, vClampMax);
    vMin = _mm_max_ps(vMin, *(const LocalM128*)&DAT_01267e30);
    hkVector4 kMinBoundsCur;
    *(LocalM128*)&kMinBoundsCur = vMin;
    hkUint32* outMin = m_kCollidable.m_kBoundingVolumeData.m_kMinimumCorner;
    outMin[0] = hkToIntFastD07950(compAtD07950(kMinBoundsCur, 0));
    outMin[1] = hkToIntFastD07950(compAtD07950(kMinBoundsCur, 1));
    outMin[2] = hkToIntFastD07950(compAtD07950(kMinBoundsCur, 2));
    outMin[3] = hkToIntFastD07950(compAtD07950(kMinBoundsCur, 3));

    LocalM128 vMax = _mm_add_ps(*(const LocalM128*)&collisionInput->m_vOffsetHigh, *(const LocalM128*)&aabb.m_kMaximumCorner);
    vMax = _mm_mul_ps(vMax, *(const LocalM128*)&collisionInput->m_vScale);
    vMax = _mm_min_ps(vMax, vClampMax);
    vMax = _mm_max_ps(vMax, *(const LocalM128*)&DAT_01267e30);
    hkVector4 kMaxPoint;
    *(LocalM128*)&kMaxPoint = vMax;
    hkUint32* outMax = m_kCollidable.m_kBoundingVolumeData.m_kMaximumCorner;
    outMax[0] = hkToIntFastD07950(compAtD07950(kMaxPoint, 0));
    outMax[1] = hkToIntFastD07950(compAtD07950(kMaxPoint, 1));
    outMax[2] = hkToIntFastD07950(compAtD07950(kMaxPoint, 2));
    outMax[3] = hkToIntFastD07950(compAtD07950(kMaxPoint, 3));

    zeroExpD07950(m_kCollidable.m_kBoundingVolumeData);
}

// Iterates m_kPhantomOverlapListeners in reverse and removes any null entries via removeAtAndCopy.
// @fnv 0x00d07a90
// src: HAVOK_LIB 0x00d07a90
void PhantomOperations::hkpPhantom_removeNullOverlapListeners()
{
    for (int i = m_kPhantomOverlapListeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (m_kPhantomOverlapListeners.m_data[i] == 0)
            m_kPhantomOverlapListeners.removeAtAndCopy(i);
    }
}

// Iterates m_kPhantomListeners in reverse and removes any null entries via removeAtAndCopy.
// @fnv 0x00d07af0
// src: HAVOK_LIB 0x00d07af0
void PhantomOperations::hkpPhantom_removeNullPhantomListeners()
{
    for (int i = m_kPhantomListeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (m_kPhantomListeners.m_data[i] == 0)
            m_kPhantomListeners.removeAtAndCopy(i);
    }
}

// The notification loop reads each listener through a pointer to its array slot.
static __forceinline void** listenerSlot(hkArray<void*>& a, int i) { return a.m_data + i; }

// Iterates the m_kPhantomListeners array in reverse, calling phantomRemoved on each non-null entry, then calls FUN_00d07af0.
// @fnv 0x00d07b50
// src: HAVOK_LIB 0x00d07b50
void PhantomOperations::hkpPhantom_firePhantomRemoved()
{
    for (int i = m_kPhantomListeners.m_iElementCount - 1; i >= 0; --i) {
        if (*listenerSlot(m_kPhantomListeners, i))
            static_cast<hkpPhantomListener*>(*listenerSlot(m_kPhantomListeners, i))->PhantomRemovedCallback(this);
    }
    hkpPhantom_removeNullPhantomListeners();
}

// Notifies phantom-added listeners in reverse, then compacts null entries.
// @fnv 0x00d07b90
// src: HAVOK_LIB 0x00d07b90
void hkpPhantom::firePhantomAdded()
{
    for (int i = m_kPhantomListeners.GetLogicalSize(); --i >= 0; ) {
        if (m_kPhantomListeners[i]) {
            static_cast<hkpPhantomListener*>(m_kPhantomListeners[i])->PhantomAddedCallback(this);
        }
    }
    static_cast<PhantomOperations*>(this)->hkpPhantom_removeNullPhantomListeners();
}

inline int FindListener(const hkArray<void*>& listeners, void* listener)
{
    for (int index = 0; index < listeners.m_iElementCount; ++index) {
        if (listeners.m_data[index] == listener) return index;
    }
    return -1;
}

inline void CopyPointerRange(void** destination, void** source, int byteCount)
{
    for (int offset = 0; offset < byteCount; offset += 4) {
        *(void**)((char*)destination + offset) =
            *(void**)((char*)source + offset);
    }
}

// Removes the given listener from m_kPhantomOverlapListeners by shifting subsequent entries down and decrementing the count.
// @fnv 0x00d07c80
// src: HAVOK_LIB 0x00d07c80
void hkpPhantom::removePhantomOverlapListener_00d07c80(hkpPhantomOverlapListener* listener) throw()
{
    int index = FindListener(m_kPhantomOverlapListeners, listener);
    --m_kPhantomOverlapListeners.m_iElementCount;
    CopyPointerRange(m_kPhantomOverlapListeners.m_data + index,
                     m_kPhantomOverlapListeners.m_data + index + 1,
                     (m_kPhantomOverlapListeners.m_iElementCount - index) * sizeof(void*));
}

// @fnv 0x00d07da0
void PhantomOperations::AddItem(void* item)
{
    m_kPhantomListeners.pushBack(item);
}

// Adds the given item to the owner's internal array of pointers.
// @fnv 0x00d07de0
// src: HAVOK_LIB 0x00d07de0
void hkpPhantom::addPhantomOverlapListener_00d07de0(hkpPhantomOverlapListener* item)
{
    void* pointer = item;
    m_kPhantomOverlapListeners.pushBack(pointer);
}

hkMemoryRouter& __cdecl GetMemoryRouterD07() throw();

template <typename T> __forceinline T* hkAllocateStackD07(int n)
{
    hkMemoryRouter& kRouter = GetMemoryRouterD07();
    char* pcCur = (char*)kRouter.m_stack.m_next.m_storage;
    kRouter.m_stack.m_next.m_storage = pcCur + ((n * sizeof(T) + 0x7f) & ~0x7f);
    return (T*)pcCur;
}
template <typename T> __forceinline void hkDeallocateStackD07(T* p)
{
    GetMemoryRouterD07().m_stack.m_next.m_storage = p;
}
// Stack-backed arrays carry an extra allocation pointer after the shared array fields.
template <typename T> struct PhantomStackArray : public hkArray<T> {
    __forceinline PhantomStackArray(int n) throw()
    {
        T* pLocal = hkAllocateStackD07<T>(n);
        this->m_data = pLocal;
        this->m_iCapacityState = n | 0x80000000;
        m_pStackAllocation = pLocal;
    }
    __forceinline ~PhantomStackArray() throw()
    {
        if (m_pStackAllocation == this->m_data)
            this->m_iElementCount = 0;
        hkDeallocateStackD07(m_pStackAllocation);
    }
    T* m_pStackAllocation;
};

// Pair type used by the shared hkpBroadPhase interface; no shared definition yet.
class BroadPhaseCastCollector {
public:
    hkpBroadPhaseHandle* m_kPointA;
    hkpBroadPhaseHandle* m_kPointB;
};

// The shared declaration omits the instance critical-section pointer at +0x10.
// Keep its original field access in these unit-local method definitions.
inline void hkpBroadPhase::lock() throw()
{
    if (*reinterpret_cast<void* const*>(reinterpret_cast<const char*>(this) + 0x10))
        lockImplementation();
}

inline void hkpBroadPhase::unlock() throw()
{
    if (*reinterpret_cast<void* const*>(reinterpret_cast<const char*>(this) + 0x10))
        unlockImplementation();
}

// No shared dispatcher header is available; calls bind to 0x00cf7130, 0x00cf70f0 and 0x00cf7080.
class hkpTypedBroadPhaseDispatcher {
public:
    static void __cdecl SortPairs(hkArray<BroadPhaseCastCollector>& kNewPairs, hkArray<BroadPhaseCastCollector>& kDelPairs) throw();
    void DispatchCollisionPairs(BroadPhaseCastCollector* pkPairs, int iNumPairs) throw();
    void DispatchNewPairs(BroadPhaseCastCollector* pkPairs, int iNumPairs, const hkpCollidableCollidableFilter* pkFilter) throw();
};

class hkpKdTreeManager {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void setDirty(int aiDirtyFlags) throw();
};

struct hkWorldOperation {
    enum Type { UPDATE_PHANTOM_BP = 0x11 };
    struct TypeTag {
        TypeTag(Type eType) : m_type(static_cast<unsigned char>(eType)) {}
        unsigned char m_type;
    };
    struct PhantomBroadphaseUpdate : public TypeTag {
        PhantomBroadphaseUpdate() : TypeTag(UPDATE_PHANTOM_BP) {}
        hkpPhantom* m_pPhantom;
        const hkAabb* m_kBounds;
    };
};

// Updates the phantom's AABB in the broad phase, dispatches collision pair changes, and marks the KD-tree dirty if the world owns one.
// @fnv 0x00d07ec0
// src: HAVOK_LIB 0x00d07ec0
void PhantomOperations::hkpPhantom_updateBroadPhase(const hkAabb& kNewAabb) throw()
{
    if (m_pOwningWorld) {
        if (areCriticalOperationsLockedForPhantoms(static_cast<hkpWorld*>(m_pOwningWorld))) {
            hkWorldOperation::PhantomBroadphaseUpdate kOp;
            kOp.m_pPhantom = this;
            kOp.m_kBounds = &kNewAabb;
            static_cast<hkpWorld*>(m_pOwningWorld)->hkpWorld_queueOperation(&kOp);
            return;
        }

        static_cast<hkpWorld*>(m_pOwningWorld)->lockCriticalOperations();

        PhantomStackArray<BroadPhaseCastCollector> kNewPairs(static_cast<hkpWorld*>(m_pOwningWorld)->m_iBroadPhaseNumObjects);
        PhantomStackArray<BroadPhaseCastCollector> kDelPairs(static_cast<hkpWorld*>(m_pOwningWorld)->m_iBroadPhaseNumObjects);

        hkpBroadPhaseHandle* pkThisObj = reinterpret_cast<hkpBroadPhaseHandle*>(&m_kCollidable.m_kBroadPhaseHandle);
        static_cast<hkpBroadPhase*>(static_cast<hkpWorld*>(m_pOwningWorld)->m_pJobSemaphore)->lock();
        static_cast<hkpBroadPhase*>(static_cast<hkpWorld*>(m_pOwningWorld)->m_pJobSemaphore)->UpdateAabbs(&pkThisObj, &kNewAabb, 1, kNewPairs, kDelPairs);

        if (kNewPairs.GetLogicalSize() != 0 || kDelPairs.GetLogicalSize() != 0) {
            hkpTypedBroadPhaseDispatcher::SortPairs(kNewPairs, kDelPairs);
            static_cast<hkpTypedBroadPhaseDispatcher*>(static_cast<hkpWorld*>(m_pOwningWorld)->m_pBroadPhaseDispatcher)->DispatchCollisionPairs(kDelPairs.begin(), kDelPairs.GetLogicalSize());
            static_cast<hkpTypedBroadPhaseDispatcher*>(static_cast<hkpWorld*>(m_pOwningWorld)->m_pBroadPhaseDispatcher)->DispatchNewPairs(kNewPairs.begin(), kNewPairs.GetLogicalSize(), (static_cast<hkpWorld*>(m_pOwningWorld)->m_pCollisionFilter ? static_cast<hkpCollidableCollidableFilter*>(static_cast<hkpCollisionFilter*>(static_cast<hkpWorld*>(m_pOwningWorld)->m_pCollisionFilter)) : 0));
            hkpPhantom_removeNullOverlapListeners();
        }
        static_cast<hkpBroadPhase*>(static_cast<hkpWorld*>(m_pOwningWorld)->m_pJobSemaphore)->unlock();

        hkpPhantom_setBoundingVolumeData(kNewAabb);

        if (static_cast<hkpWorld*>(m_pOwningWorld)->m_pKdTreeManager)
            static_cast<hkpKdTreeManager*>(static_cast<hkpWorld*>(m_pOwningWorld)->m_pKdTreeManager)->setDirty(0);

        static_cast<hkpWorld*>(m_pOwningWorld)->unlockAndAttemptToExecutePendingOperations();
    }
}

// Destructor: calls NotifyElements, releases m_kPhantomListeners and m_kPhantomOverlapListeners, then calls FUN_00c9d3b0.
// @fnv 0x00d08130
hkpPhantom::~hkpPhantom() throw()
{
    static_cast<PhantomOperations*>(this)->NotifyElements();
}
