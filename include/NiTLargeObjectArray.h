#pragma once

#include "NiTLargeArray.h"

// Gamebryo 2.2 NiTLargeArray.h. RTTI: NiTLargeObjectArray<T> : NiTLargeArray<T, NiTNewInterface<T> >, one vftable slot (its own destructor,
// e.g. NiTLargeObjectArray<NiFixedString> vftable 0x0109bf74 -> 0x00a66070), no data members of its own.
template <class T> class NiTLargeObjectArray : public NiTLargeArray<T, NiTNewInterface<T> >
{
  public:
    NiTLargeObjectArray(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1);
    virtual ~NiTLargeObjectArray();
};

#ifdef FNV64_NITARRAY_INLINE_BODIES
template <class T>
inline NiTLargeObjectArray<T>::NiTLargeObjectArray(unsigned int uiMaxSize, unsigned int uiGrowBy)
    : NiTLargeArray<T, NiTNewInterface<T> >(uiMaxSize, uiGrowBy)
{
}

template <class T> inline NiTLargeObjectArray<T>::~NiTLargeObjectArray()
{
}
#endif
