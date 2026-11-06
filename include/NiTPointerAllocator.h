#pragma once

#include "NiTAbstractPoolAllocator.h"

// Gamebryo 2.2 NiTPointerAllocator.h: pool allocator policy of NiTPointerList / NiTPointerMap
// (RTTI: NiTPointerMap<K,V> : NiTMapBase<NiTPointerAllocator<unsigned int>,K,V>). No instance data.
template <class T> class NiTPointerAllocator : public NiTAbstractPoolAllocator<T>
{
  public:
    void* Allocate();
    void Deallocate(void* p);
};
