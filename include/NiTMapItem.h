#pragma once

// Gamebryo 2.2 NiTMapBase.h: hash chain node, next 0, key 4, value 8 (12 bytes for 4-byte keys and values;
// the NiTMapBase<...,__int64,int> instantiation puts the 8-byte key at 8). Not polymorphic.
template <class TKEY, class TVAL> class NiTMapItem
{
  public:
    NiTMapItem* m_pkNext;
    TKEY m_key;
    TVAL m_val;
};
