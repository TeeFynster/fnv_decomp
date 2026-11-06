#pragma once

#include "NiTSet.h"

// Gamebryo 2.2 NiTSet.h: NiTSet over NiMalloc storage, no members of its own (12 bytes).
template <class T> class NiTPrimitiveSet : public NiTSet<T, NiTMallocInterface<T> >
{
  public:
    NiTPrimitiveSet(unsigned int uiInitialSize = 0);
};
