#pragma once

// Checked constructor exception specification: NiDynamicGeometryGroup 0x00e957b0.
#ifndef FNV64_NITPRIMITIVEARRAY_CTOR_SPEC
#define FNV64_NITPRIMITIVEARRAY_CTOR_SPEC
#endif

#include "NiTArray.h"

// Gamebryo 2.2 NiTArray.h. RTTI: NiTPrimitiveArray<T> : NiTArray<T, NiTMallocInterface<T> >, one vftable slot (its own destructor,
// e.g. NiTPrimitiveArray<Actor *> vftable 0x01092928 -> 0x009e9be0), no data members of its own.
template <class T> class NiTPrimitiveArray : public NiTArray<T, NiTMallocInterface<T> >
{
  public:
    NiTPrimitiveArray(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1) FNV64_NITPRIMITIVEARRAY_CTOR_SPEC;
    // no user-declared destructor (Gamebryo declares none): the implicit virtual one, e.g. 0x009e9be0 (/Od) and 0x00a6c670 (/O2, a bare jmp to ~NiTArray), calls
    // ~NiTArray without storing a vftable, which a user-declared one would
};

#ifdef FNV64_NITARRAY_INLINE_BODIES
template <class T>
inline NiTPrimitiveArray<T>::NiTPrimitiveArray(unsigned int uiMaxSize, unsigned int uiGrowBy) FNV64_NITPRIMITIVEARRAY_CTOR_SPEC
    : NiTArray<T, NiTMallocInterface<T> >(uiMaxSize, uiGrowBy)
{
}
#endif
