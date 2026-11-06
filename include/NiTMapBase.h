#pragma once

#include "NiTMapItem.h"

// Gamebryo 2.2 NiTMapBase.h. RTTI: NiTMapBase<TAlloc, TKEY, TVAL> (no bases), 7 vftable slots: destructor,
// KeyToHashIndex, IsKeysEqual, SetValue, ClearValue, NewItem, DeleteItem (the last two pure: NiTFixedStringMapBase
// vftable 0x0109ca08 has _purecall 0x00ec60fa in slots 5 and 6). 16 bytes: the ctor of
// NiTMapBase<DFALL<NiTMapItem<__int64,int> >,__int64,int> (0x0084b750) stores the vtable, m_uiHashSize at 4, zeroes the
// count at 0xc and allocates/clears 4 * hashSize bytes into m_ppkHashTable at 8. The allocator is an empty base of
// the count (Gamebryo's anti-bloat trick); the FNV units call the count member m_kItemCount, its type MapEntryCount.
// Bodies: units define the ones they need out of class.
template <class TAlloc, class TKEY, class TVAL> class NiTMapBase
{
  public:
    typedef NiTMapItem<TKEY, TVAL> EntryType;
    struct AntiBloatAllocator : public TAlloc
    {
        unsigned int m_uiCount;
    };
    typedef AntiBloatAllocator MapEntryCount;

    NiTMapBase(unsigned int uiHashSize = 37);
    virtual ~NiTMapBase();

    unsigned int GetCount() const;
    bool IsEmpty() const;
    void SetAt(TKEY kKey, TVAL kVal);
    bool RemoveAt(TKEY kKey);
    void RemoveAll();
    bool GetAt(TKEY kKey, TVAL& kVal) const;
    void* GetFirstPos() const;
    void GetNext(void*& pPos, TKEY& kKey, TVAL& kVal) const;
    void Resize(unsigned int uNewHashSize);

  public:  // hashing and item policy, overridden per map type
    virtual unsigned int KeyToHashIndex(TKEY kKey) const;
    virtual bool IsKeysEqual(TKEY kKey1, TKEY kKey2) const;
    virtual void SetValue(NiTMapItem<TKEY, TVAL>* pItem, TKEY kKey, TVAL kVal);
    virtual void ClearValue(NiTMapItem<TKEY, TVAL>* pItem);
  public:  // item allocation (pure: the concrete map supplies it)
    virtual NiTMapItem<TKEY, TVAL>* NewItem() = 0;
    virtual void DeleteItem(NiTMapItem<TKEY, TVAL>* pItem) = 0;

    unsigned int m_uiHashSize;
    NiTMapItem<TKEY, TVAL>** m_ppkHashTable;
    AntiBloatAllocator m_kItemCount;
};
