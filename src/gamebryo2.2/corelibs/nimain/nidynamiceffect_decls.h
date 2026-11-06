// gamebryo2.2/corelibs/nimain/nidynamiceffect_decls.h: stream and pool helpers
#ifndef FNV_NIDYNAMICEFFECT_DECLS_H
#define FNV_NIDYNAMICEFFECT_DECLS_H

#include "../../../../include/NiDynamicEffect.h"
#include "../../../../include/NiTListItem.h"
#include "../../../../include/RecursiveSpinLock.h"

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);

template <class T> inline void ReadBinaryValue(NiStream& stream, T& value)
{
    stream.m_pkIstr->Read(&value, sizeof(T));
}
template <class T> class PoolAllocatorBase
{
  public:
    struct LinkedListEntry
    {
        LinkedListEntry* m_pkNext;
        void* m_pUserData;
        T m_element;
    };
    static LinkedListEntry* ms_pFreeList;
    static RecursiveSpinLock ms_kPoolState;
};
template <class T> class PoolMemoryAllocator : public PoolAllocatorBase<T>
{
  public:
    static void CreateFreeMem();
};
inline NiTListItem<NiNode*>* NiDynamicEffectNewListItem()
{
    typedef PoolAllocatorBase<unsigned int> Pool;
    Pool::ms_kPoolState.Lock(0);
    Pool::LinkedListEntry* item = Pool::ms_pFreeList;
    if (!item)
    {
        PoolMemoryAllocator<unsigned int>::CreateFreeMem();
        item = Pool::ms_pFreeList;
    }
    Pool::ms_pFreeList = item->m_pkNext;
    item->m_element = 0;
    item->m_pkNext = 0;
    item->m_pUserData = 0;
    Pool::ms_kPoolState.Unlock();
    return reinterpret_cast<NiTListItem<NiNode*>*>(item);
}
extern volatile long DAT_011a9b58;
typedef char NiDynamicEffect_size_check[(sizeof(NiDynamicEffect) == 0xc4) ? 1 : -1];
typedef char NiDynamicEffect_switch_offset_check[(offsetof(NiDynamicEffect, switchState) == 0x9c) ? 1 : -1];
typedef char NiDynamicEffect_nodes_offset_check[(offsetof(NiDynamicEffect, unaffectedNodes) == 0xb8) ? 1 : -1];
#endif
