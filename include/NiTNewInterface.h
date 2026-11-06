#pragma once

// Gamebryo 2.2 NiTCollection.h: allocator policy of NiTObjectArray / NiTLargeObjectArray / NiTObjectSet
// (RTTI names such as NiTArray<X, NiTNewInterface<X> >). Stateless: static NiNew T[n] / NiDelete[] wrappers, no data members.
template <class T> class NiTNewInterface
{
  public:
    static T* Allocate(unsigned int uiNumElements);
    static void Deallocate(T* pArray);
};
