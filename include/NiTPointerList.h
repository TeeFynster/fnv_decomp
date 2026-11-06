#pragma once

#include "NiTPointerAllocator.h"
#include "NiTPointerListBase.h"

// Gamebryo 2.2 NiTPointerList.h: NiTPointerListBase over the shared pointer pool. No members of its own: 12 bytes
// (e.g. Tile's child list, include/NiTPointerList_Tile___.h).
template <class T> class NiTPointerList : public NiTPointerListBase<NiTPointerAllocator<unsigned int>, T>
{
public:
    void* Find(const T& element, void* position);
};

template <class T> class NiPointer;
class NiAVObject;
class NiTriBasedGeom;
class BSFaceGenKeyframe;
// Exe 0x00b9fda0/0x00649680 require these instantiations' explicit construction and cleanup calls.
template <> class NiTPointerList<NiPointer<NiAVObject> >
    : public NiTPointerListBase<NiTPointerAllocator<unsigned int>, NiPointer<NiAVObject> >
{
public:
    NiTPointerList() { m_kItemCount.m_uiCount = 0; m_pkHead = 0; m_pkTail = 0; }
    ~NiTPointerList();
};
template <> class NiTPointerList<NiPointer<NiTriBasedGeom> >
    : public NiTPointerListBase<NiTPointerAllocator<unsigned int>, NiPointer<NiTriBasedGeom> >
{
public:
    NiTPointerList() { m_kItemCount.m_uiCount = 0; m_pkHead = 0; m_pkTail = 0; }
    ~NiTPointerList();
};
template <> class NiTPointerList<BSFaceGenKeyframe*>
    : public NiTPointerListBase<NiTPointerAllocator<unsigned int>, BSFaceGenKeyframe*>
{
  public:
    NiTPointerList();
    ~NiTPointerList();
};
