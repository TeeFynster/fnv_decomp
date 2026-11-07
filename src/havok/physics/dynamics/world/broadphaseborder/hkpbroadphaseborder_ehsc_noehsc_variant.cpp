#include <string.h>
#include "../../../../../../include/hkAabb.h"
#include "../../../../../../include/hkReferencedObject.h"
#include "../../../../../../include/hkpAabbPhantom.h"
#include "../../../../../../include/hkpPhantom.h"
#include "../../../../../../include/hkpTypedBroadPhaseHandle.h"
#include "../../../../../../include/hkpPhantomOverlapListener.h"
#include "../../../../../../include/hkpWorld.h"
#include "../../../../../../include/hkpWorldDeletionListener.h"
#include "../../../../../../include/hkpWorldPostSimulationListener.h"

// src/havok/physics/dynamics/world/broadphaseborder/hkpbroadphaseborder_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/physics/dynamics/world/broadphaseborder/hkpbroadphaseborder.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

struct D0B6A0Allocator;
struct D0B6A0MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D0B6A0Allocator* m_pStreamAllocator;

    D0B6A0Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" D0B6A0MemoryRouter& __cdecl hkMemoryRouter_getInstance();
struct D0B6A0Allocator
{
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
    virtual void* AllocateMemoryBlock(int numBytes);
};

// Keep the original unit's inline operations on the shared class declarations.


inline void* __cdecl hkReferencedObject::operator new(std::size_t nbytes)
{
    hkReferencedObject* b = static_cast<hkReferencedObject*>(hkMemoryRouter_getInstance().heap().AllocateMemoryBlock(nbytes));
    b->m_usMemSizeAndFlags = static_cast<unsigned short>(nbytes);
    return b;
}

inline void hkVector4::set(float x, float y, float z, float w)
{
    m_vComponents = _mm_setr_ps(x, y, z, w);
}

inline float& hkVector4::operator()(int i)
{
    return m_vComponents.m128_f32[i];
}

inline const float& hkVector4::operator()(int i) const
{
    return m_vComponents.m128_f32[i];
}

inline void hkpTypedBroadPhaseHandle::setType(int type)
{
    m_type = static_cast<signed char>(type);
}

namespace bpb {

struct hkpBroadPhaseBorder : hkReferencedObject,
                             hkpWorldDeletionListener,
                             hkpPhantomOverlapListener,
                             hkpWorldPostSimulationListener
{
    hkpBroadPhaseBorder(hkpWorld* world, int type, bool postponeAndSortCallbacks);
    __forceinline void createPhantom(hkpWorld* world, const hkAabb& aabb, int i)
    {
        hkpAabbPhantom* phantom =
            static_cast<hkpAabbPhantom*>(hkReferencedObject::operator new(0xe0))->FUN_00cf2cb0(aabb, 0);
        phantom->m_kCollidable.m_kBroadPhaseHandle.setType(3);
        phantom->addPhantomOverlapListener_00d07de0(this);
        m_kPhantoms[i] = phantom;
        world->hkpWorld_addPhantom(phantom);
    }
    hkpWorld* m_pOwningWorld;
    hkpPhantom* m_kPhantoms[6];
    int m_type;
    bool m_bPostponeAndSortCallbacks;
    hkArray<void*> m_kPostponedCallbacks;
};

}

// @fnv 0x00d0b710
bpb::hkpBroadPhaseBorder::hkpBroadPhaseBorder(hkpWorld* world, int type, bool postponeAndSortCallbacks)
{
    m_type = type;
    m_pOwningWorld = world;
    m_bPostponeAndSortCallbacks = postponeAndSortCallbacks;
    addReference();
    m_pOwningWorld->hkpWorld_addWorldDeletionListener(static_cast<hkpWorldDeletionListener*>(this));
    m_pOwningWorld->hkpWorld_addWorldPostSimulationListener(static_cast<hkpWorldPostSimulationListener*>(this));

    // These temporary bounds require uninitialized, aligned storage, as in the original unit.
    struct __declspec(align(16)) BorderBounds
    {
        float maximumCorner[4];
        float minimumCorner[4];
        float face[8];
    } bounds;
    __declspec(align(16)) float minimum[4];
    __declspec(align(16)) float maximum[4];
    hkVector4& wMin = reinterpret_cast<hkVector4&>(minimum);
    hkVector4& wMax = reinterpret_cast<hkVector4&>(maximum);
    memcpy(&wMin, &m_pOwningWorld->m_kBroadPhaseAabb[0], sizeof(wMin));
    memcpy(&wMax, &m_pOwningWorld->m_kBroadPhaseAabb[1], sizeof(wMax));
    hkVector4& maximumCorner = reinterpret_cast<hkVector4&>(bounds.maximumCorner);
    hkVector4& minimumCorner = reinterpret_cast<hkVector4&>(bounds.minimumCorner);
    hkAabb& aabb = reinterpret_cast<hkAabb&>(bounds.face);

    aabb.m_kMinimumCorner.set(wMax(0), wMin(1), wMin(2));
    maximumCorner.set(wMax(0), wMax(1), wMax(2));
    aabb.m_kMaximumCorner.m_vComponents = maximumCorner.m_vComponents;
    createPhantom(world, aabb, 0);

    minimumCorner.set(wMin(0), wMin(1), wMin(2));
    aabb.m_kMinimumCorner.m_vComponents = minimumCorner.m_vComponents;
    aabb.m_kMaximumCorner.set(wMin(0), wMax(1), wMax(2));
    createPhantom(world, aabb, 1);

    aabb.m_kMinimumCorner.set(wMin(0), wMax(1), wMin(2));
    aabb.m_kMaximumCorner.m_vComponents = maximumCorner.m_vComponents;
    createPhantom(world, aabb, 2);

    aabb.m_kMinimumCorner.m_vComponents = minimumCorner.m_vComponents;
    aabb.m_kMaximumCorner.set(wMax(0), wMin(1), wMax(2));
    createPhantom(world, aabb, 3);

    aabb.m_kMinimumCorner.set(wMin(0), wMin(1), wMax(2));
    aabb.m_kMaximumCorner.m_vComponents = maximumCorner.m_vComponents;
    createPhantom(world, aabb, 4);

    aabb.m_kMinimumCorner.m_vComponents = minimumCorner.m_vComponents;
    aabb.m_kMaximumCorner.set(wMax(0), wMax(1), wMin(2));
    createPhantom(world, aabb, 5);
}
