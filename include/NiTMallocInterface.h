#pragma once

// Gamebryo 2.2 NiTCollection.h: allocator policy of NiTPrimitiveArray / NiTLargePrimitiveArray / NiTPrimitiveSet
// (RTTI names such as NiTArray<X, NiTMallocInterface<X> >). Stateless: static NiMalloc / NiFree wrappers, no data members.
template <class T> class NiTMallocInterface
{
  public:
    static T* Allocate(unsigned int uiNumElements);
    static void Deallocate(T* pArray);
};
