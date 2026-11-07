#ifndef BSSCRAPARRAY_H
#define BSSCRAPARRAY_H

#include "bsscraparray_decls.h"
template <>
// @fnv 0x0087d1b0
ScrapArrayWithBase<NiPointer<NiAVObject>, 1024>::ScrapArrayWithBase()
{

    m_pAllocator = MemoryManager_Instance()->GetGeneralAllocator();
    BSSimpleArray_NiPointer_ObstacleUndoData_1024_InitialSetup(0, false);
}
template <>
// @fnv 0x009789e0
ScrapArrayWithBase<Animation*, 1024>::ScrapArrayWithBase()
{

    m_pAllocator = MemoryManager_Instance()->GetGeneralAllocator();
    reinterpret_cast<BSSimpleArray<NavMeshInfo*, 1024>*>(this)->BSSimpleArray_float_1024_InitialSetup(0, false);
}
#endif
