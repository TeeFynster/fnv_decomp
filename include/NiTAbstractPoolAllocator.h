#pragma once

class RecursiveSpinLock;

// Gamebryo 2.2 NiTPool / NiTAbstractPoolAllocator.h: the shared static block pool behind NiTPointerAllocator<T>
// (list and map nodes of 12 bytes). Static members only, no instance data: as a base it costs nothing.
// AllocNode matches NiTListItem<T> / NiTMapItem<K, V> in size: next, user data, element.
template <class T> class NiTAbstractPoolAllocator
{
  public:
    class AllocNode
    {
      public:
        AllocNode* m_pkNext;
        void* m_pkData;
        T m_element;
    };

    static AllocNode* ms_pkBlockHeader;
    static AllocNode* ms_pkFreeMem;
    static unsigned int ms_uiBlockSize;
    // the pool's lock (Gamebryo's critical section, a RecursiveSpinLock in FNV): NiTPointerAllocator<unsigned
    // int>::Deallocate 0x0045cee0 locks 0x011c5f80 (Lock 0x0040fbf0, Unlock 0x0040fba0) around the free list
    // ms_pkFreeMem 0x011c5f58
    static RecursiveSpinLock ms_kCriticalSection;

    static void _SDMInit();
    static void _SDMShutdown();

  protected:
    static void CreateFreeMem();
};
