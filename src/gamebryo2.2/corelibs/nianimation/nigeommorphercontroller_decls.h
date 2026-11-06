#ifndef FNV_NIGEOMMORPHERCONTROLLER_DECLS_H
#define FNV_NIGEOMMORPHERCONTROLLER_DECLS_H

#include "../../../../include/NiGeomMorpherController.h"
#include "MemoryManager.h"

extern MemoryManager g_memoryManager;

inline void NiInterpolator::DecRefCount()
{
    NiRefObject::DecRefCount();
}

__declspec(nothrow) __forceinline NiGeomMorpherController::InterpItem::~InterpItem()
{
}

inline void* NiGeomMorpherController::InterpItem::operator new[](unsigned int size) throw()
{
    return g_memoryManager.Allocate(size);
}

inline void NiGeomMorpherController::InterpItem::operator delete[](void* p) throw()
{
    g_memoryManager.Deallocate(p);
}

#endif
