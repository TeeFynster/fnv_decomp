#pragma once

#include "NiTLargeArray.h"

// Gamebryo 2.2 NiTLargeArray.h. RTTI: NiTLargePrimitiveArray<T> : NiTLargeArray<T, NiTMallocInterface<T> >, one
// vftable slot (the destructor, e.g. NiTLargePrimitiveArray<BLENDKEY> vftable 0x010c6b0c); 0x18 bytes, no members
// of its own (TopicInfoArray, .?AVTopicInfoArray@@, derives from NiTLargePrimitiveArray<TESTopicInfo *>).
template <class T> class NiTLargePrimitiveArray : public NiTLargeArray<T, NiTMallocInterface<T> >
{
  public:
    NiTLargePrimitiveArray(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1);
    virtual ~NiTLargePrimitiveArray();
};
