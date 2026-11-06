#pragma once

// node type: include/NiTListItem.h (only pointers to it here; many units still define their own copy)
template <class T> class NiTListItem;

// Gamebryo 2.2 NiTListBase.h. Not polymorphic (no RTTI type descriptor for any NiTList/NiTPointerList
// instantiation in the exe): head 0, tail 4, item count 8 = 12 bytes (Tile's NiTPointerList<Tile *> child list,
// include/NiTListBase_NiTPointerAllocator_unsigned_int__Tile___.h). The allocator is an empty base of the count
// (Gamebryo's "anti-bloat" trick), so it costs no space. The FNV units call the count member m_kItemCount and its
// type MapEntryCount.
//
// Bodies: units define the ones they need out of class (VC9 inlining differs per unit).
template <class TAlloc, class T> class NiTListBase
{
  public:
    struct AntiBloatAllocator : public TAlloc
    {
        unsigned int m_uiCount;
    };
    typedef AntiBloatAllocator MapEntryCount;

    // Exe ConsoleManager history helpers: fixed targets rebound per unit.
    void* DereferenceIfNotNull(void*);
    T& AddEight(void*);
    void AssignString(const T&);
    T PopFront();
    void RemoveAll();

    unsigned int GetSize() const;
    bool IsEmpty() const;
    void* GetHeadPos() const;
    void* GetTailPos() const;
    void* GetNextPos(void* pos) const;
    void* GetPrevPos(void* pos) const;

    NiTListItem<T>* NewItem();
    void DeleteItem(NiTListItem<T>* pkItem);
    void AddNodeHead(NiTListItem<T>* pkNode);
    void AddNodeTail(NiTListItem<T>* pkNode);
    void* InsertNodeBefore(void* pos, NiTListItem<T>* pkNode);
    void* InsertNodeAfter(void* pos, NiTListItem<T>* pkNode);

    NiTListItem<T>* m_pkHead;
    NiTListItem<T>* m_pkTail;
    AntiBloatAllocator m_kItemCount;
};
