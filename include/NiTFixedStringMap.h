#pragma once

#include "DFALL.h"
#include "NiTFixedStringMapBase.h"

// Gamebryo 2.2 NiTFixedStringMap.h. RTTI: NiTFixedStringMap<V> : NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,V> >,V>,
// 3 vftable slots (destructor, NewItem, DeleteItem; e.g. NiTFixedStringMap<NiGlobalConstantEntry *> vftable 0x010a2154:
// 0x00aa02f0, 0x00a6ef50, 0x00aa0330). No members of its own: 16 bytes.
template <class TVAL>
class NiTFixedStringMap : public NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString, TVAL> >, TVAL>
{
  public:
    NiTFixedStringMap(unsigned int uiHashSize = 37);
    virtual ~NiTFixedStringMap();

    virtual NiTMapItem<NiFixedString, TVAL>* NewItem();
    virtual void DeleteItem(NiTMapItem<NiFixedString, TVAL>* pkItem);
};
