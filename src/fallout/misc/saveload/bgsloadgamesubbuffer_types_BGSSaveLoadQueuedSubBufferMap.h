// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BGSSAVELOADQUEUEDSUBBUFFERMAP_H
#define FNV_BGSSAVELOADQUEUEDSUBBUFFERMAP_H

#include <stddef.h>
#include "../../../../include/TESForm.h"
#include "../../../../include/BGSLoadGameSubBuffer.h"
#include "../../../../include/BGSLoadFormBuffer.h"
class LoadGameSubBufferQueue;
class DFALL_NiTMapItem_TESForm___BGSLoadGameSubBuffer___;
class NiTMap_TESForm___BGSLoadGameSubBuffer_;
class NiTMapBase_DFALL_NiTMapItem_TESForm___BGSLoadGameSubBuffer____TESForm___BGSLoadGameSubBuffer_;
class NiTMapBase_DFALL_NiTMapItem_TESForm___BGSLoadGameSubBuffer____TESForm___BGSLoadGameSubBuffer___AntiBloatAllocator;
typedef char SubBufferMapLayoutCheck1[(sizeof(BGSLoadGameSubBuffer) == 4) ? 1 : -1];
typedef char SubBufferMapLayoutCheck2[(offsetof(BGSLoadGameSubBuffer, pBuffer) == 0) ? 1 : -1];
#pragma pack(push, 4)
class DFALL_NiTMapItem_TESForm___BGSLoadGameSubBuffer___
{
  public:
    // void* __cdecl DFALL<NiTMapItem<TESForm *,BGSLoadGameSubBuffer> >::*()
    // void __cdecl DFALL<NiTMapItem<TESForm *,BGSLoadGameSubBuffer> >::*(void*)
};
#pragma pack(pop)
typedef char SubBufferMapLayoutCheck3[(sizeof(DFALL_NiTMapItem_TESForm___BGSLoadGameSubBuffer___) == 1) ? 1 : -1];
#pragma pack(push, 4)
class NiTMapBase_DFALL_NiTMapItem_TESForm___BGSLoadGameSubBuffer____TESForm___BGSLoadGameSubBuffer___AntiBloatAllocator
    : public DFALL_NiTMapItem_TESForm___BGSLoadGameSubBuffer___
{
  public:
    // base DFALL<NiTMapItem<TESForm *,BGSLoadGameSubBuffer> > at +0x0, size 1
    unsigned int m_uiCount;  // +0x0, 4 bytes
};
#pragma pack(pop)
typedef char SubBufferMapLayoutCheck4[(
    sizeof(
        NiTMapBase_DFALL_NiTMapItem_TESForm___BGSLoadGameSubBuffer____TESForm___BGSLoadGameSubBuffer___AntiBloatAllocator) ==
    4) ? 1 : -1];
typedef char SubBufferMapLayoutCheck5[(
    offsetof(
        NiTMapBase_DFALL_NiTMapItem_TESForm___BGSLoadGameSubBuffer____TESForm___BGSLoadGameSubBuffer___AntiBloatAllocator,
        m_uiCount) == 0) ? 1 : -1];
#pragma pack(push, 4)
class NiTMapBase_DFALL_NiTMapItem_TESForm___BGSLoadGameSubBuffer____TESForm___BGSLoadGameSubBuffer_
{
  public:
    void** m_ppVirtualMethodTable;                                              // +0x0, 4 bytes
    unsigned int m_uiHashSize;                                    // +0x4, 4 bytes
    NiTMapItem<TESForm*, BGSLoadGameSubBuffer>** m_ppkHashTable;  // +0x8, 4 bytes
    NiTMapBase_DFALL_NiTMapItem_TESForm___BGSLoadGameSubBuffer____TESForm___BGSLoadGameSubBuffer___AntiBloatAllocator
        m_kItemCount;  // +0xC, 4 bytes
    // NiTMapBase<DFALL<NiTMapItem<TESForm *,BGSLoadGameSubBuffer> >,TESForm *,BGSLoadGameSubBuffer>
    // unsigned int __cdecl NiTMapBase<DFALL<NiTMapItem<TESForm *,BGSLoadGameSubBuffer> >,TESForm *,BGSLoadGameSubBuffer>::*()
    // bool __cdecl NiTMapBase<DFALL<NiTMapItem<TESForm *,BGSLoadGameSubBuffer> >,TESForm *,BGSLoadGameSubBuffer>::*()
    // void __cdecl NiTMapBase<DFALL<NiTMapItem<TESForm *,BGSLoadGameSubBuffer> >,TESForm *,BGSLoadGameSubBuffer>::*(TESForm*, BGSLoadGameSubBuffer)
    // bool __cdecl NiTMapBase<DFALL<NiTMapItem<TESForm *,BGSLoadGameSubBuffer> >,TESForm *,BGSLoadGameSubBuffer>::*(TESForm*)
    // void __cdecl NiTMapBase<DFALL<NiTMapItem<TESForm *,BGSLoadGameSubBuffer> >,TESForm *,BGSLoadGameSubBuffer>::*()
    // bool __cdecl NiTMapBase<DFALL<NiTMapItem<TESForm *,BGSLoadGameSubBuffer> >,TESForm *,BGSLoadGameSubBuffer>::*(TESForm*, BGSLoadGameSubBuffer&)
    // void* __cdecl NiTMapBase<DFALL<NiTMapItem<TESForm *,BGSLoadGameSubBuffer> >,TESForm *,BGSLoadGameSubBuffer>::*()
    // void __cdecl NiTMapBase<DFALL<NiTMapItem<TESForm *,BGSLoadGameSubBuffer> >,TESForm *,BGSLoadGameSubBuffer>::*(void*&, TESForm*&, BGSLoadGameSubBuffer&)
    // NiTMapItem<TESForm *,BGSLoadGameSubBuffer>* __cdecl NiTMapBase<DFALL<NiTMapItem<TESForm *,BGSLoadGameSubBuffer> >,TESForm *,BGSLoadGameSubBuffer>::*(TESForm*)
    // NiTMapBase<DFALL<NiTMapItem<TESForm *,BGSLoadGameSubBuffer> >,TESForm *,BGSLoadGameSubBuffer>& __cdecl NiTMapBase<DFALL<NiTMapItem<TESForm *,BGSLoadGameSubBuffer> >,TESForm *,BGSLoadGameSubBuffer>::*(const NiTMapBase<DFALL<NiTMapItem<TESForm *,BGSLoadGameSubBuffer> >,TESForm *,BGSLoadGameSubBuffer>&)
    // void __cdecl NiTMapBase<DFALL<NiTMapItem<TESForm *,BGSLoadGameSubBuffer> >,TESForm *,BGSLoadGameSubBuffer>::*()
    // void __cdecl NiTMapBase<DFALL<NiTMapItem<TESForm *,BGSLoadGameSubBuffer> >,TESForm *,BGSLoadGameSubBuffer>::*()
};
#pragma pack(pop)
typedef char SubBufferMapLayoutCheck6[(
    sizeof(NiTMapBase_DFALL_NiTMapItem_TESForm___BGSLoadGameSubBuffer____TESForm___BGSLoadGameSubBuffer_) == 16) ? 1 : -1];
typedef char SubBufferMapLayoutCheck7[(
    offsetof(NiTMapBase_DFALL_NiTMapItem_TESForm___BGSLoadGameSubBuffer____TESForm___BGSLoadGameSubBuffer_, m_ppVirtualMethodTable) ==
    0) ? 1 : -1];
typedef char SubBufferMapLayoutCheck8[(
    offsetof(NiTMapBase_DFALL_NiTMapItem_TESForm___BGSLoadGameSubBuffer____TESForm___BGSLoadGameSubBuffer_,
             m_uiHashSize) == 4) ? 1 : -1];
typedef char SubBufferMapLayoutCheck9[(
    offsetof(NiTMapBase_DFALL_NiTMapItem_TESForm___BGSLoadGameSubBuffer____TESForm___BGSLoadGameSubBuffer_,
             m_ppkHashTable) == 8) ? 1 : -1];
typedef char SubBufferMapLayoutCheck10[(
    offsetof(NiTMapBase_DFALL_NiTMapItem_TESForm___BGSLoadGameSubBuffer____TESForm___BGSLoadGameSubBuffer_,
             m_kItemCount) == 12) ? 1 : -1];
#pragma pack(push, 4)
class NiTMap_TESForm___BGSLoadGameSubBuffer_
    : public NiTMapBase_DFALL_NiTMapItem_TESForm___BGSLoadGameSubBuffer____TESForm___BGSLoadGameSubBuffer_
{
  public:
    NiTMap_TESForm___BGSLoadGameSubBuffer_(unsigned int hashSize = 37);
    ~NiTMap_TESForm___BGSLoadGameSubBuffer_();
    // base NiTMapBase<DFALL<NiTMapItem<TESForm *,BGSLoadGameSubBuffer> >,TESForm *,BGSLoadGameSubBuffer> at +0x0, size 16
    // NiTMap<TESForm *,BGSLoadGameSubBuffer>
    // void __cdecl NiTMap<TESForm *,BGSLoadGameSubBuffer>::*()
    // NiTMapItem<TESForm *,BGSLoadGameSubBuffer>* __cdecl NiTMap<TESForm *,BGSLoadGameSubBuffer>::*()
    // void __cdecl NiTMap<TESForm *,BGSLoadGameSubBuffer>::*(NiTMapItem<TESForm *,BGSLoadGameSubBuffer>*)
    // NiTMap<TESForm *,BGSLoadGameSubBuffer>& __cdecl NiTMap<TESForm *,BGSLoadGameSubBuffer>::*(const NiTMap<TESForm *,BGSLoadGameSubBuffer>&)
    // void __cdecl NiTMap<TESForm *,BGSLoadGameSubBuffer>::*()
    // void __cdecl NiTMap<TESForm *,BGSLoadGameSubBuffer>::*()
};
#pragma pack(pop)
typedef char SubBufferMapLayoutCheck11[(sizeof(NiTMap_TESForm___BGSLoadGameSubBuffer_) == 16) ? 1 : -1];
#pragma pack(push, 4)
class LoadGameSubBufferQueue
{
  public:
    NiTMap_TESForm___BGSLoadGameSubBuffer_ m_kSubBuffersByType[3];  // +0x0, 48 bytes
    LoadGameSubBufferQueue();
    void QueueAnimationAndCharController();
    void ProcessQueuedSubBuffers(QUEUED_SUB_BUFFER_TYPE type);
    void ProcessSubBuffer(QUEUED_SUB_BUFFER_TYPE type, BGSLoadFormBuffer* buffer, TESForm* form);
    // LoadGameSubBufferQueue
    // void __cdecl LoadGameSubBufferQueue::*()
    // void __cdecl LoadGameSubBufferQueue::*(QUEUED_SUB_BUFFER_TYPE, BGSLoadFormBuffer*, TESForm*)
    // void __cdecl LoadGameSubBufferQueue::*()
    // void __cdecl LoadGameSubBufferQueue::*(QUEUED_SUB_BUFFER_TYPE)
    // LoadGameSubBufferQueue& __cdecl LoadGameSubBufferQueue::*(const LoadGameSubBufferQueue&)
    // void* __cdecl LoadGameSubBufferQueue::*(unsigned int)
};
#pragma pack(pop)
typedef char SubBufferMapLayoutCheck12[(sizeof(LoadGameSubBufferQueue) == 48) ? 1 : -1];
typedef char SubBufferMapLayoutCheck13[(offsetof(LoadGameSubBufferQueue, m_kSubBuffersByType) == 0) ? 1 : -1];
#endif
