#pragma once

#include "NiTMapBase.h"
#include "NiTPointerAllocator.h"

// Gamebryo 2.2 NiTPointerMap.h. RTTI: NiTPointerMap<K,V> : NiTMapBase<NiTPointerAllocator<unsigned int>,K,V>, 7 vftable
// slots (e.g. NiTPointerMap<char const *,int> vftable 0x01094dfc: destructor 0x00a0d520, KeyToHashIndex, IsKeysEqual,
// SetValue, ClearValue, NewItem 0x00a0d280, DeleteItem 0x00a0d7c0). Overrides the destructor, NewItem and DeleteItem
// (map nodes come from the NiTPointerAllocator block pool). No members of its own: 16 bytes.
// Bodies: units define the ones they need out of class.
template <class TKEY, class TVAL>
class NiTPointerMap : public NiTMapBase<NiTPointerAllocator<unsigned int>, TKEY, TVAL>
{
  public:
    NiTPointerMap(unsigned int uiHashSize = 37);
    virtual ~NiTPointerMap();

    virtual NiTMapItem<TKEY, TVAL>* NewItem();
    virtual void DeleteItem(NiTMapItem<TKEY, TVAL>* pkItem);
};
