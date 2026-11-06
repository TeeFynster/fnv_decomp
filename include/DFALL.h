#pragma once

// Gamebryo 2.2 NiTDefaultAllocator, named DFALL in this build (RTTI: NiTMap<K,V> : NiTMapBase<DFALL<NiTMapItem<K,V> >,K,V>).
// Stateless: NiMalloc / NiFree of one T. No data members.
template <class T> class DFALL
{
  public:
    void* Allocate();
    void Deallocate(void* p);
};
