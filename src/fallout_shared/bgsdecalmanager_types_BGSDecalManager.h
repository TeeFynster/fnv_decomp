#include "../../include/NiTListBase.h"
#include "../../include/NiTListBase.h"
class NiTPointerAllocator_unsigned_int_;
class BGSDecalEmitter;
// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BGSDECALMANAGER_H
#define FNV_BGSDECALMANAGER_H

#include "layout_support.h"
#include "layout_support.h"
class BGSDecalManager;
class BSRenderedTexture;
class BSShaderAccumulator;
class NiCamera;
class NiTAbstractPoolAllocator_unsigned_int_;
typedef NiTListBase<NiTPointerAllocator_unsigned_int_, BGSDecalEmitter* > NiTListBase_NiTPointerAllocator_unsigned_int__BGSDecalEmitter___;
class NiTListBase_NiTPointerAllocator_unsigned_int__BGSDecalEmitter_____AntiBloatAllocator;
typedef NiTListBase<NiTPointerAllocator_unsigned_int_, DecalNiPointer<BSTempEffectSimpleDecal> > NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_BSTempEffectSimpleDecal___;
class NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_BSTempEffectSimpleDecal_____AntiBloatAllocator;
class NiTListItem_BGSDecalEmitter___;
class NiTListItem_NiPointer_BSTempEffectSimpleDecal___;
class NiTPointerAllocator_unsigned_int_;
class NiTPointerList_BGSDecalEmitter___;
class NiTPointerList_NiPointer_BSTempEffectSimpleDecal___;
class NiTPointerListBase_NiTPointerAllocator_unsigned_int__BGSDecalEmitter___;
class NiTPointerListBase_NiTPointerAllocator_unsigned_int__NiPointer_BSTempEffectSimpleDecal___;
#pragma pack(push, 4)
class NiTAbstractPoolAllocator_unsigned_int_
{
  public:
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTAbstractPoolAllocator_unsigned_int_) == 1);
#include "../../include/NiTPointerAllocator_unsigned_int_.h"
#pragma pack(push, 4)
class NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_BSTempEffectSimpleDecal_____AntiBloatAllocator
    : public NiTPointerAllocator_unsigned_int_
{
  public:
    // base DecalNiTPointerAllocator<unsigned int> at +0x0, size 1
    unsigned int m_uiCount;  // +0x0, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(
    sizeof(NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_BSTempEffectSimpleDecal_____AntiBloatAllocator) ==
    4);
FNV_STATIC_ASSERT(
    offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_BSTempEffectSimpleDecal_____AntiBloatAllocator,
             m_uiCount) == 0);
#pragma pack(push, 4)

#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_BSTempEffectSimpleDecal___) == 12);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_BSTempEffectSimpleDecal___,
                           m_pkHead) == 0);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_BSTempEffectSimpleDecal___,
                           m_pkTail) == 4);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_BSTempEffectSimpleDecal___,
                           m_kItemCount) == 8);
#pragma pack(push, 4)
class NiTPointerListBase_NiTPointerAllocator_unsigned_int__NiPointer_BSTempEffectSimpleDecal___
    : public NiTListBase_NiTPointerAllocator_unsigned_int__NiPointer_BSTempEffectSimpleDecal___
{
  public:
    // base NiTListBase<DecalNiTPointerAllocator<unsigned int>,DecalNiPointer<BSTempEffectSimpleDecal> > at +0x0, size 12
    // void __cdecl DecalNiTPointerListBase<DecalNiTPointerAllocator<unsigned int>,DecalNiPointer<BSTempEffectSimpleDecal> >::*()
    // void __cdecl DecalNiTPointerListBase<DecalNiTPointerAllocator<unsigned int>,DecalNiPointer<BSTempEffectSimpleDecal> >::*(const DecalNiPointer<BSTempEffectSimpleDecal>&)
    // void __cdecl DecalNiTPointerListBase<DecalNiTPointerAllocator<unsigned int>,DecalNiPointer<BSTempEffectSimpleDecal> >::*(const DecalNiPointer<BSTempEffectSimpleDecal>&)
    // void* __cdecl DecalNiTPointerListBase<DecalNiTPointerAllocator<unsigned int>,DecalNiPointer<BSTempEffectSimpleDecal> >::*(void*, const DecalNiPointer<BSTempEffectSimpleDecal>&)
    // void* __cdecl DecalNiTPointerListBase<DecalNiTPointerAllocator<unsigned int>,DecalNiPointer<BSTempEffectSimpleDecal> >::*(void*, const DecalNiPointer<BSTempEffectSimpleDecal>&)
    // const DecalNiPointer<BSTempEffectSimpleDecal>& __cdecl DecalNiTPointerListBase<DecalNiTPointerAllocator<unsigned int>,DecalNiPointer<BSTempEffectSimpleDecal> >::*()
    // const DecalNiPointer<BSTempEffectSimpleDecal>& __cdecl DecalNiTPointerListBase<DecalNiTPointerAllocator<unsigned int>,DecalNiPointer<BSTempEffectSimpleDecal> >::*()
    // const DecalNiPointer<BSTempEffectSimpleDecal>& __cdecl DecalNiTPointerListBase<DecalNiTPointerAllocator<unsigned int>,DecalNiPointer<BSTempEffectSimpleDecal> >::*(void*)
    // const DecalNiPointer<BSTempEffectSimpleDecal>& __cdecl DecalNiTPointerListBase<DecalNiTPointerAllocator<unsigned int>,DecalNiPointer<BSTempEffectSimpleDecal> >::*(void*&)
    // const DecalNiPointer<BSTempEffectSimpleDecal>& __cdecl DecalNiTPointerListBase<DecalNiTPointerAllocator<unsigned int>,DecalNiPointer<BSTempEffectSimpleDecal> >::*(void*&)
    // DecalNiPointer<BSTempEffectSimpleDecal> __cdecl DecalNiTPointerListBase<DecalNiTPointerAllocator<unsigned int>,DecalNiPointer<BSTempEffectSimpleDecal> >::*()
    // DecalNiPointer<BSTempEffectSimpleDecal> __cdecl DecalNiTPointerListBase<DecalNiTPointerAllocator<unsigned int>,DecalNiPointer<BSTempEffectSimpleDecal> >::*()
    // DecalNiPointer<BSTempEffectSimpleDecal> __cdecl DecalNiTPointerListBase<DecalNiTPointerAllocator<unsigned int>,DecalNiPointer<BSTempEffectSimpleDecal> >::*(const DecalNiPointer<BSTempEffectSimpleDecal>&)
    // DecalNiPointer<BSTempEffectSimpleDecal> __cdecl DecalNiTPointerListBase<DecalNiTPointerAllocator<unsigned int>,DecalNiPointer<BSTempEffectSimpleDecal> >::*(void*&)
    // void* __cdecl DecalNiTPointerListBase<DecalNiTPointerAllocator<unsigned int>,DecalNiPointer<BSTempEffectSimpleDecal> >::*(const DecalNiPointer<BSTempEffectSimpleDecal>&, void*)
    // void __cdecl DecalNiTPointerListBase<DecalNiTPointerAllocator<unsigned int>,DecalNiPointer<BSTempEffectSimpleDecal> >::*()
    // void __cdecl DecalNiTPointerListBase<DecalNiTPointerAllocator<unsigned int>,DecalNiPointer<BSTempEffectSimpleDecal> >::*(int __cdecl (void*, void*)*)
    // NiTListItem<DecalNiPointer<BSTempEffectSimpleDecal> >* __cdecl DecalNiTPointerListBase<DecalNiTPointerAllocator<unsigned int>,DecalNiPointer<BSTempEffectSimpleDecal> >::*()
    // void __cdecl DecalNiTPointerListBase<DecalNiTPointerAllocator<unsigned int>,DecalNiPointer<BSTempEffectSimpleDecal> >::*(NiTListItem<DecalNiPointer<BSTempEffectSimpleDecal> >*)
    // DecalNiTPointerListBase<DecalNiTPointerAllocator<unsigned int>,DecalNiPointer<BSTempEffectSimpleDecal> >
    // DecalNiTPointerListBase<DecalNiTPointerAllocator<unsigned int>,DecalNiPointer<BSTempEffectSimpleDecal> >& __cdecl DecalNiTPointerListBase<DecalNiTPointerAllocator<unsigned int>,DecalNiPointer<BSTempEffectSimpleDecal> >::*(const DecalNiTPointerListBase<DecalNiTPointerAllocator<unsigned int>,DecalNiPointer<BSTempEffectSimpleDecal> >&)
    // void* __cdecl DecalNiTPointerListBase<DecalNiTPointerAllocator<unsigned int>,DecalNiPointer<BSTempEffectSimpleDecal> >::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPointerListBase_NiTPointerAllocator_unsigned_int__NiPointer_BSTempEffectSimpleDecal___) ==
                  12);
#pragma pack(push, 4)
class NiTPointerList_NiPointer_BSTempEffectSimpleDecal___
    : public NiTPointerListBase_NiTPointerAllocator_unsigned_int__NiPointer_BSTempEffectSimpleDecal___
{
  public:
    // base DecalNiTPointerListBase<DecalNiTPointerAllocator<unsigned int>,DecalNiPointer<BSTempEffectSimpleDecal> > at +0x0, size 12
    // NiTPointerList<DecalNiPointer<BSTempEffectSimpleDecal> >
    // void __cdecl NiTPointerList<DecalNiPointer<BSTempEffectSimpleDecal> >::*()
    // NiTPointerList<DecalNiPointer<BSTempEffectSimpleDecal> >& __cdecl NiTPointerList<DecalNiPointer<BSTempEffectSimpleDecal> >::*(const NiTPointerList<DecalNiPointer<BSTempEffectSimpleDecal> >&)
    // void* __cdecl NiTPointerList<DecalNiPointer<BSTempEffectSimpleDecal> >::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPointerList_NiPointer_BSTempEffectSimpleDecal___) == 12);
#pragma pack(push, 4)
class NiTListBase_NiTPointerAllocator_unsigned_int__BGSDecalEmitter_____AntiBloatAllocator
    : public NiTPointerAllocator_unsigned_int_
{
  public:
    // base DecalNiTPointerAllocator<unsigned int> at +0x0, size 1
    unsigned int m_uiCount;  // +0x0, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTListBase_NiTPointerAllocator_unsigned_int__BGSDecalEmitter_____AntiBloatAllocator) == 4);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__BGSDecalEmitter_____AntiBloatAllocator,
                           m_uiCount) == 0);
#pragma pack(push, 4)

#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTListBase_NiTPointerAllocator_unsigned_int__BGSDecalEmitter___) == 12);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__BGSDecalEmitter___, m_pkHead) == 0);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__BGSDecalEmitter___, m_pkTail) == 4);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__BGSDecalEmitter___, m_kItemCount) == 8);
#pragma pack(push, 4)
class NiTPointerListBase_NiTPointerAllocator_unsigned_int__BGSDecalEmitter___
    : public NiTListBase_NiTPointerAllocator_unsigned_int__BGSDecalEmitter___
{
  public:
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPointerListBase_NiTPointerAllocator_unsigned_int__BGSDecalEmitter___) == 12);
#pragma pack(push, 4)
class NiTPointerList_BGSDecalEmitter___ : public NiTPointerListBase_NiTPointerAllocator_unsigned_int__BGSDecalEmitter___
{
  public:
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPointerList_BGSDecalEmitter___) == 12);
#pragma pack(push, 4)
class BGSDecalManager
{
  public:
    DecalNiPointer<BSRenderedTexture> m_pDecalRenderTexture;  // +0x0, 4 bytes
    bool m_bDecalRenderingEnabled;                       // +0x4, 1 bytes
    unsigned char layoutPadding5[3];
    NiTPointerList_NiPointer_BSTempEffectSimpleDecal___ m_kSimpleDecalList;  // +0x8, 12 bytes
    NiTPointerList_BGSDecalEmitter___ BGSDecalEmitterList;                   // +0x14, 12 bytes
    DecalNiPointer<BSShaderAccumulator> m_spShaderAccumulator;                    // +0x20, 4 bytes
    DecalNiPointer<NiCamera> m_pDecalCamera;                                      // +0x24, 4 bytes
    void RenderDecals();
    void RemoveDecal(BSTempEffectSimpleDecal*);
    // void __cdecl BGSDecalManager::*()
    // BGSDecalManager* __cdecl BGSDecalManager::*()
    // bool __cdecl BGSDecalManager::*()
    // void __cdecl BGSDecalManager::*()
    // void __cdecl BGSDecalManager::*()
    // void __cdecl BGSDecalManager::*()
    // void __cdecl BGSDecalManager::*()
    // void __cdecl BGSDecalManager::*(BSTempEffectSimpleDecal*)
    // void __cdecl BGSDecalManager::*()
    // void __cdecl BGSDecalManager::*()
    // void __cdecl BGSDecalManager::*()
    // bool __cdecl BGSDecalManager::*(TESObjectREFR*, BGSDecalManager::DECAL_TYPE)
    // void __cdecl BGSDecalManager::*(int, NiPoint3*, NiPoint3*, float, float, float, float)
    // BGSDecalManager
    // BGSDecalManager& __cdecl BGSDecalManager::*(const BGSDecalManager&)
    // void* __cdecl BGSDecalManager::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSDecalManager) == 40);
FNV_STATIC_ASSERT(offsetof(BGSDecalManager, m_pDecalRenderTexture) == 0);
FNV_STATIC_ASSERT(offsetof(BGSDecalManager, m_bDecalRenderingEnabled) == 4);
FNV_STATIC_ASSERT(offsetof(BGSDecalManager, m_kSimpleDecalList) == 8);
FNV_STATIC_ASSERT(offsetof(BGSDecalManager, BGSDecalEmitterList) == 20);
FNV_STATIC_ASSERT(offsetof(BGSDecalManager, m_spShaderAccumulator) == 32);
FNV_STATIC_ASSERT(offsetof(BGSDecalManager, m_pDecalCamera) == 36);
#endif
