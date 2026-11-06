#pragma once

#include "DFALL.h"
#include "NiTMapBase.h"

// Gamebryo 2.2 NiTMap.h. RTTI: NiTMap<K,V> : NiTMapBase<DFALL<NiTMapItem<K,V> >,K,V>, 7 vftable slots (overrides the
// destructor, NewItem and DeleteItem, e.g. NiTMap<__int64,int> vftable 0x0107f494). No members of its own: 16 bytes.
template <class TKEY, class TVAL> class NiTMap : public NiTMapBase<DFALL<NiTMapItem<TKEY, TVAL> >, TKEY, TVAL>
{
  public:
    NiTMap(unsigned int uiHashSize = 37);
    virtual ~NiTMap();

    virtual NiTMapItem<TKEY, TVAL>* NewItem();
    virtual void DeleteItem(NiTMapItem<TKEY, TVAL>* pkItem);
};
