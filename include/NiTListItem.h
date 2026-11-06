#pragma once

// Gamebryo 2.2 NiTListBase.h: doubly linked list node, next 0, prev 4, element 8 (12 bytes for a pointer element;
// the list code in the exe walks +0 forward and +4 backward and reads the element at +8). Every Gamebryo list
// node in FNV is this shape (the copies agree on m_pkNext / m_pkPrev / m_element).
template <class T> class NiTListItem
{
  public:
    NiTListItem* m_pkNext;
    NiTListItem* m_pkPrev;
    T m_element;
};
