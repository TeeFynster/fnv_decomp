
// src/havok/physics/collide/shape/compound/tree/mopp/hkpmoppbvtreeshape_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-30 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/shape/compound/tree/mopp/hkpmoppbvtreeshape.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/shape/compound/tree/mopp/hkpmoppbvtreeshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/compound/tree/mopp/hkpmoppbvtreeshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../../include/hkAabb.h"
#include "../../../../../../../../include/hkMoppBvTreeShapeBase.h"
#include "../../../../../../../../include/hkpMoppCode.h"
#include "../../../../../../../../include/hkArray.h"
#include "../../../../../../../../include/hkpSingleShapeContainer.h"
#include "../../../../../../../../include/hkpMoppBvTreeShape.h"

extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance();


// ~hkArray: clearAndDeallocate through the router heap (the trailing m_data / capacity stores are dead here).
template <typename T, typename A> __forceinline hkArray<T, A>::~hkArray()
{
    hkMemoryAllocator& alloc = reinterpret_cast<hkMemoryAllocator&>(hkMemoryRouter_getInstance().heap());
    this->m_iElementCount = 0;
    if ((this->m_iCapacityState & 0x80000000) == 0)
    {
        alloc.bufFree(this->m_data, this->getCapacity() * sizeof(T));
    }
}

__forceinline void initMoppCode(hkpMoppCode* code, const hkVector4_X& offset, const void* data, int size)
{
    code->m_info.m_offset.m_vComponents = offset.m_vComponents;
    code->m_data.setOwnedData((unsigned char*)data, size, size);
    // hkEnum's shared declaration exposes no value setter; its storage is one signed byte.
    reinterpret_cast<hkInt8&>(code->m_eBuildType) = hkpMoppCode::BUILD_NOT_SET;
}

// 0x00DD1DA0 is the scalar MOPP AABB query; its 0x40-byte workspace starts with the hit-array pointer.
struct MoppAabbQueryMachine
{
    hkArray<unsigned int>* m_kHits;
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

    void hkpMoppObbVirtualMachine_queryAabb(const hkpMoppCode* code, const hkAabb* aabb, hkArray<unsigned int>* hits) throw();
};

extern double DAT_01091c00;

// @fnv 0x00d54810
// src: XBOX_PDB 0x00d54810
int hkMoppBvTreeShapeBase::queryAabbImpl(const hkAabb& aabbIn, unsigned int* hits, int maxNumKeys) const
{
    const hkVector4_X& offset = m_kMoppCodeInfo;

    __m128 aabbStorage[2];
    hkAabb& aabb = *reinterpret_cast<hkAabb*>(aabbStorage);
    int buffer[16];
    hkpMoppCode* code = (hkpMoppCode*)(((unsigned int)buffer + 15) & ~15u);
    initMoppCode(code, offset, m_pMoppData, m_uiMoppDataSize);
    float extent = (float)(DAT_01091c00 / m_kMoppCodeInfo.m_vComponents.m128_f32[3]);
    aabb.m_kMinimumCorner.m_vComponents = _mm_max_ps(offset.m_vComponents, aabbIn.m_kMinimumCorner.m_vComponents);
    aabb.m_kMaximumCorner.m_vComponents =
        _mm_min_ps(_mm_add_ps(_mm_set_ps1(extent), offset.m_vComponents), aabbIn.m_kMaximumCorner.m_vComponents);
    hkArray<unsigned int> hitsArray(hits, 0, maxNumKeys);
    MoppAabbQueryMachine machine;
    machine.hkpMoppObbVirtualMachine_queryAabb(code, &aabb, &hitsArray);
    int numHits = machine.m_kHits->m_iElementCount;
    return numHits;
}

// Moved from hkpmoppbvtreeshape.cpp: no EH frame in the original (Havok was built without exceptions).
inline hkpShapeContainer::~hkpShapeContainer() {}
inline hkpSingleShapeContainer::~hkpSingleShapeContainer()
{
    if (m_pContainedShape)
        const_cast<hkpShape*>(m_pContainedShape)->removeReference();
}

inline hkMoppBvTreeShapeBase::~hkMoppBvTreeShapeBase() throw()
{
    const_cast<hkpMoppCode*>(m_pMoppCode)->removeReference();
}

// @fnv 0x00d543e0
__declspec(noinline) hkpMoppBvTreeShape::~hkpMoppBvTreeShape() throw()
{}
