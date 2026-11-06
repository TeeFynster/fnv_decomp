#pragma once

#include "NiTListBase.h"

// Gamebryo 2.2 NiTPointerListBase.h: the element-level API of a list of small values (pointers, NiPointer<X>),
// nodes from TAlloc (NiTPointerAllocator<unsigned int> in every FNV instantiation). No members of its own: 12 bytes.
// Bodies: units define the ones they need out of class.
template <class TAlloc, class T> class NiTPointerListBase : public NiTListBase<TAlloc, T>
{
  public:
    void AddHead(const T& element);
    void AddTail(const T& element);
    void* InsertBefore(void* pos, const T& element);
    void* InsertAfter(void* pos, const T& element);

    const T& GetHead() const;
    const T& GetTail() const;
    T& GetNext(void*& pos);
    const T& GetNext(void*& pos) const;
    const T& GetPrev(void*& pos) const;
    const T& Get(void* pos) const;
    void* FindPos(const T& element, void* start = 0) const;

    T RemoveHead();
    T RemoveTail();
    T Remove(const T& element);
    T RemovePos(void*& pos);
    void RemoveAll();

    NiTListItem<T>* NewItem();
    void DeleteItem(NiTListItem<T>* pkItem);
};
