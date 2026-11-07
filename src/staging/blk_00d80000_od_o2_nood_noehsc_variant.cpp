
// src/staging/blk_00d80000_od_o2_nood_noehsc_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /Gy (unit src/staging/blk_00d80000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00d80000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"

#include "../../include/hkArray.h"
#include "../../include/hkMemoryAllocator.h"
#include "../../include/hkMemoryRouter.h"

// hkMemoryRouter: 0x00c85750 returns the shared hkMemoryRouter, with heap at +0x10.

__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return hkMemoryRouter::getInstance().heap();
}

template <class T> __forceinline void hkMemoryAllocator::_bufFree(void* p, int numElem)
{
    bufFree(p, numElem * sizeof(T));
}

template <class T> __forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& alloc)
{
    if ((m_iCapacityState & 0x80000000) == 0)
    {
        alloc._bufFree<T>(m_data, getCapacity());
    }
}

template <class T, class Allocator> __forceinline hkArray<T, Allocator>::~hkArray()
{
    this->_clearAndDeallocate(Allocator().get(this));
}

struct __declspec(align(16)) QueryCollector
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    float m20[4];
    float m30[4];
    float m40[4];
    int unk50;
    int unk54;
    int unk58;
    hkArray<void*> m_kHits;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    short unk7C;
    QueryCollector()
        : unk0C(1), unk10(1), unk14(0), unk18(0), unk1C(0), unk68(0), unk6C(0), unk70(0), unk74(0), unk78(0), unk7C(0)
    {}
};

int Object_ProcessAndReturnValue_00d883c0(void* a, int b, int c, QueryCollector* out);

// @fnv 0x00d88aa0
// src: GUESS 0x00d88aa0 (confidence: low)
int Object_ProcessAndReturnValue_00d88aa0(void* a)
{
    QueryCollector collector;
    return Object_ProcessAndReturnValue_00d883c0(a, 0, 0, &collector);
}
