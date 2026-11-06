#pragma once

#include "NiTPointerMap.h"
#include "NiTStringTemplateMap.h"

// Gamebryo 2.2 NiTStringMap.h. RTTI: NiTStringPointerMap<V> : NiTStringTemplateMap<NiTPointerMap<char const *,V>,V>,
// 7 vftable slots (only the destructor is its own: NiTStringPointerMap<int> vftable 0x01094dbc, NewItem 0x00a0d280 and
// DeleteItem 0x00a0d7c0 are NiTPointerMap's). No members of its own: 0x14 bytes, like NiTStringTemplateMap.
template <class TVAL>
class NiTStringPointerMap : public NiTStringTemplateMap<NiTPointerMap<const char*, TVAL>, TVAL>
{
  public:
    NiTStringPointerMap(unsigned int uiHashSize = 37, bool bCopy = true);
    virtual ~NiTStringPointerMap();
};
