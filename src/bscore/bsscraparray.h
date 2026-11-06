#ifndef BSSCRAPARRAY_H
#define BSSCRAPARRAY_H

#include "bsscraparray_decls.h"
template <>
// @fnv 0x0087d1b0
ScrapArrayWithBase<NiPointer<NiAVObject>, 1024>::ScrapArrayWithBase()
{

    m_pAllocator = FUN_00401020()->GetGeneralAllocator();
    FUN_00822860(0, false);
}
template <>
// @fnv 0x009789e0
ScrapArrayWithBase<Animation*, 1024>::ScrapArrayWithBase()
{

    m_pAllocator = FUN_00401020()->GetGeneralAllocator();
    reinterpret_cast<BSSimpleArray<NavMeshInfo*, 1024>*>(this)->FUN_006b3eb0(0, false);
}
#endif
