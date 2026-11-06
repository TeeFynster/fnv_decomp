#pragma once

#include "NiTMapItem.h"

class NiFixedString;

// Gamebryo 2.2 NiTFixedStringMap.h. RTTI: NiTFixedStringMapBase<TAlloc,TVAL> (no bases), 3 vftable slots: destructor,
// NewItem, DeleteItem (both pure: NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,char const *> >,char const *>
// vftable 0x0109ca08 has _purecall 0x00ec60fa in slots 1 and 2). Hashing and key compare are not virtual here.
// 16 bytes: vftable, m_uiHashSize 4, m_ppkHashTable 8, the item count 0xc (the allocator is its empty base).
// Bodies: units define the ones they need out of class.
template <class TAlloc, class TVAL> class NiTFixedStringMapBase
{
  public:
    typedef NiTMapItem<NiFixedString, TVAL> EntryType;
    struct AntiBloatAllocator : public TAlloc
    {
        unsigned int m_uiCount;
    };

    NiTFixedStringMapBase(unsigned int uiHashSize = 37);
    virtual ~NiTFixedStringMapBase();

    unsigned int GetCount() const;
    bool IsEmpty() const;
    void SetAt(const NiFixedString& kKey, TVAL val);
    bool RemoveAt(const NiFixedString& kKey);
    void RemoveAll();
    bool GetAt(const NiFixedString& kKey, TVAL& val) const;
    void* GetFirstPos() const;
    void GetNext(void*& pos, NiFixedString& kKey, TVAL& val) const;

    unsigned int KeyToHashIndex(const NiFixedString& kKey) const;
    bool IsKeysEqual(const NiFixedString& kKey1, const NiFixedString& kKey2) const;
    void SetValue(NiTMapItem<NiFixedString, TVAL>* pkItem, const NiFixedString& kKey, TVAL val);
    void ClearValue(NiTMapItem<NiFixedString, TVAL>* pkItem);

    virtual NiTMapItem<NiFixedString, TVAL>* NewItem() = 0;
    virtual void DeleteItem(NiTMapItem<NiFixedString, TVAL>* pkItem) = 0;

    unsigned int m_uiHashSize;
    NiTMapItem<NiFixedString, TVAL>** m_ppkHashTable;
    AntiBloatAllocator m_kItemCount;
};
