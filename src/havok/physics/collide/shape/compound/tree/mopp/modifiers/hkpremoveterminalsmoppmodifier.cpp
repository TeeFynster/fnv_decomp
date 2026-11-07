// src/havok/physics/collide/shape/compound/tree/mopp/modifiers/hkpremoveterminalsmoppmodifier.cpp
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// The original unit uses this compact intrinsic quad declaration.
#define _INCLUDED_MM2
// Exe 0x00e485d0 0hkpRemoveTerminalsMoppModifier: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C" LocalM128 _mm_min_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_max_ps(LocalM128, LocalM128);

#include "../../../../../../../../../include/hkBool.h"
#include "../../../../../../../../../include/hkArray.h"
#include "../../../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../../../include/hkpMoppModifier.h"
#include "../../../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../../../include/hkVector4.h"
#include "../../../../../../../../../include/hkAabb.h"
#include "../../../../../../../../../include/hkTransform.h"
#include "../../../../../../../../../include/hkpShape.h"
#include "../../../../../../../../../include/hkpShapeContainer.h"
#include "../../../../../../../../../include/hkpRemoveTerminalsMoppModifier.h"

class hkpMoppCode;

__forceinline hkAabb::hkAabb() {}

__forceinline void hkVector4::setMin4(const hkVector4& a, const hkVector4& b)
{
    const LocalM128 av = a.m_vComponents;
    const LocalM128 bv = b.m_vComponents;
    m_vComponents = _mm_min_ps(av, bv);
}
__forceinline void hkVector4::setMax4(const hkVector4& a, const hkVector4& b)
{
    const LocalM128 av = a.m_vComponents;
    const LocalM128 bv = b.m_vComponents;
    m_vComponents = _mm_max_ps(av, bv);
}

// hkArray.h identifies hkMemoryRouter as the shared hkMemoryRouter layout.
extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance();

__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return hkMemoryRouter_getInstance().heap();
}
template <typename T> __forceinline void hkMemoryAllocator::_bufFree(void* p, int n)
{
    bufFree(p, n * sizeof(T));
}
template <typename T> __forceinline void hkArrayBase<T>::clear()
{
    for (int i = 0; i < m_iElementCount; i++)
        m_data[i].~T();
    m_iElementCount = 0;
}
template <typename T> __forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& alloc)
{
    clear();
    if ((m_iCapacityState & DONT_DEALLOCATE_FLAG) == 0)
        alloc._bufFree<T>(m_data, getCapacity());
    m_data = 0;
    m_iCapacityState = DONT_DEALLOCATE_FLAG;
}
template <typename T, typename Allocator> __forceinline hkArray<T, Allocator>::~hkArray()
{
    clearAndDeallocate();
}

// No include/hkpShapeBuffer.h exists; hkpShapeContainer.h only forward-declares this scratch buffer.
struct __declspec(align(16)) hkpShapeBuffer
{
    unsigned int m_kStorage[128];
};

// Retained locally: the shared header lacks both constructor overloads implemented below.
// Both constructors and the destructor bind the same vfptrs: 0x010e88b4 and 0x010e88a4.

// Retained locally: no include/hkBitField.h exists. Only its word pointer is needed here.

#include "../../../../../../../../../include/hkpRemoveTerminalsMoppModifier2.h"
#include "../../../../../../../../../include/hkBitField.h"

// @fnv 0x00e48510
hkBool hkpRemoveTerminalsMoppModifier::shouldTerminalBeRemoved(hkUint32 id, const hkUint32* properties) throw()
{
    return m_pTerminalIdsToRemove->indexOf(id) >= 0;
}

// @fnv 0x00e48550
hkBool hkpRemoveTerminalsMoppModifier2::shouldTerminalBeRemoved(hkUint32 id, const hkUint32* properties) throw()
{
    return !m_enabledKeys->get(static_cast<int>(id));
}

struct PackedTerminalRemoveInfo
{
    unsigned int lo : 8;
    unsigned int hi : 24;
};

// @fnv 0x00e48580
void hkpRemoveTerminalsMoppModifier::addTerminalRemoveInfo(int relativeMoppAddress) throw()
{
    hkArray<hkUint32>* arr = &m_kRemovedTerminalIds;
    hkMemoryRouter& router = hkMemoryRouter_getInstance();
    if (arr->m_iElementCount == (int)(arr->m_iCapacityState & 0x3fffffff))
    {
        hkArrayUtil::_reserveMore(router.heap(), arr, 4);
    }
    PackedTerminalRemoveInfo* entry = reinterpret_cast<PackedTerminalRemoveInfo*>(&arr->m_data[arr->m_iElementCount++]);
    entry->lo = 0;
    entry->hi = relativeMoppAddress;
}

extern const hkTransform DAT_01268370;
void __cdecl ConstructTemporaryObject(const hkpMoppCode* code, const hkAabb& aabb, hkpMoppModifier* modifier);

inline hkUint32 shapeKey(const hkArray<hkUint32>& shapes, int i)
{
    return shapes.m_data[i];
}

// @fnv 0x00e485d0
hkpRemoveTerminalsMoppModifier::hkpRemoveTerminalsMoppModifier(
    const hkpMoppCode* code, const hkpShapeContainer* container, const hkArray<hkUint32>& shapesToRemove) throw()
{
    if (shapesToRemove.GetLogicalSize() != 0)
    {
        hkAabb aabb;
        hkpShapeBuffer buffer;
        {
            const hkpShape* shape = container->GetShapeForKey(shapeKey(shapesToRemove, 0), buffer);
            shape->CalculateAabb(DAT_01268370, 0.0f, aabb);
        }
        for (int i = 1; i < shapesToRemove.GetLogicalSize(); i++)
        {
            const hkpShape* shape = container->GetShapeForKey(shapeKey(shapesToRemove, i), buffer);
            hkAabb nextAabb;
            shape->CalculateAabb(DAT_01268370, 0.0f, nextAabb);
            aabb.m_kMinimumCorner.setMin4(aabb.m_kMinimumCorner, nextAabb.m_kMinimumCorner);
            aabb.m_kMaximumCorner.setMax4(aabb.m_kMaximumCorner, nextAabb.m_kMaximumCorner);
        }
        m_pTerminalIdsToRemove = &shapesToRemove;
        ConstructTemporaryObject(code, aabb, this);
        m_pTerminalIdsToRemove = 0;
    }
}

// @fnv 0x00e486e0
hkpRemoveTerminalsMoppModifier::hkpRemoveTerminalsMoppModifier(
    const hkpMoppCode* code, const hkAabb& aabb, const hkArray<hkUint32>& shapesToRemove) throw()
{
    m_pTerminalIdsToRemove = &shapesToRemove;
    ConstructTemporaryObject(code, aabb, this);
    m_pTerminalIdsToRemove = 0;
}

// 0x00e48740 restores 0x010e8894, the hkpMoppModifier vfptr; its old listener stand-in was misidentified.
// @fnv 0x00e48740
hkpRemoveTerminalsMoppModifier::~hkpRemoveTerminalsMoppModifier() throw()
{}

struct __declspec(align(16)) FUN_00e67230_Obj
{
    int storage[20];
    void hkpMoppModifyVirtualMachine_queryAabb(int a1, int a2, int a3);
};

// @fnv 0x00e5d040
void __cdecl ConstructTemporaryObject(int a1, int a2, int a3)
{
    FUN_00e67230_Obj tmp;
    tmp.hkpMoppModifyVirtualMachine_queryAabb(a1, a2, a3);
}
