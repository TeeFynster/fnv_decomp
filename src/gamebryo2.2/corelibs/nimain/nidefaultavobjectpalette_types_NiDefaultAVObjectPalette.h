// Map layout helpers: the shared palette owns a map whose shared declaration exposes only its prefix.
// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NIDEFAULTAVOBJECTPALETTE_H
#define FNV_NIDEFAULTAVOBJECTPALETTE_H

#include <stddef.h>

template <class K, class V> class NiTMapItem;
#include "NiFixedString.h"
#include "NiObjectNET.h"
class DFALL_NiTMapItem_NiFixedString_NiAVObject_____;
class PaletteObjectMapView;
class NiTFixedStringMapBase_DFALL_NiTMapItem_NiFixedString_NiAVObject______NiAVObject___;
class NiTFixedStringMapBase_DFALL_NiTMapItem_NiFixedString_NiAVObject______NiAVObject_____AntiBloatAllocator;
#pragma pack(push, 4)
class DFALL_NiTMapItem_NiFixedString_NiAVObject_____
{
  public:
    // void* __cdecl DFALL<NiTMapItem<NiFixedString,NiAVObject *> >::*()
    // void __cdecl DFALL<NiTMapItem<NiFixedString,NiAVObject *> >::*(void*)
};
#pragma pack(pop)
typedef char NiDefaultPalette_layout_check_2[(sizeof(DFALL_NiTMapItem_NiFixedString_NiAVObject_____) == 1) ? 1 : -1];
#pragma pack(push, 4)
class NiTFixedStringMapBase_DFALL_NiTMapItem_NiFixedString_NiAVObject______NiAVObject_____AntiBloatAllocator
    : public DFALL_NiTMapItem_NiFixedString_NiAVObject_____
{
  public:
    // base DFALL<NiTMapItem<NiFixedString,NiAVObject *> > at +0x0, size 1
    unsigned int m_uiCount;  // +0x0, 4 bytes
};
#pragma pack(pop)
typedef char NiDefaultPalette_layout_check_3[(
    sizeof(NiTFixedStringMapBase_DFALL_NiTMapItem_NiFixedString_NiAVObject______NiAVObject_____AntiBloatAllocator) ==
    4) ? 1 : -1];
typedef char NiDefaultPalette_layout_check_4[(
    offsetof(NiTFixedStringMapBase_DFALL_NiTMapItem_NiFixedString_NiAVObject______NiAVObject_____AntiBloatAllocator,
             m_uiCount) == 0) ? 1 : -1];
#pragma pack(push, 4)
class NiTFixedStringMapBase_DFALL_NiTMapItem_NiFixedString_NiAVObject______NiAVObject___
{
  public:
    void RemoveAll();
    void** m_ppVirtualMethodTable;                                          // +0x0, 4 bytes
    unsigned int m_uiHashSize;                                // +0x4, 4 bytes
    NiTMapItem<NiFixedString, NiAVObject*>** m_ppkHashTable;  // +0x8, 4 bytes
    NiTFixedStringMapBase_DFALL_NiTMapItem_NiFixedString_NiAVObject______NiAVObject_____AntiBloatAllocator
        m_kItemCount;  // +0xC, 4 bytes
    // NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiAVObject *> >,NiAVObject *>
    // unsigned int __cdecl NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiAVObject *> >,NiAVObject *>::*()
    // bool __cdecl NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiAVObject *> >,NiAVObject *>::*()
    // void __cdecl NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiAVObject *> >,NiAVObject *>::*(NiFixedString&, NiAVObject*)
    // bool __cdecl NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiAVObject *> >,NiAVObject *>::*(NiFixedString&)
    // void __cdecl NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiAVObject *> >,NiAVObject *>::*()
    // bool __cdecl NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiAVObject *> >,NiAVObject *>::*(const NiFixedString&, NiAVObject*&)
    // void* __cdecl NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiAVObject *> >,NiAVObject *>::*()
    // void __cdecl NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiAVObject *> >,NiAVObject *>::*(void*&, NiFixedString&, NiAVObject*&)
    // unsigned int __cdecl NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiAVObject *> >,NiAVObject *>::*(const NiFixedString&)
    // bool __cdecl NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiAVObject *> >,NiAVObject *>::*(const NiFixedString&, const NiFixedString&)
    // NiTMapItem<NiFixedString,NiAVObject *>* __cdecl NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiAVObject *> >,NiAVObject *>::*(const NiFixedString&)
    // void __cdecl NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiAVObject *> >,NiAVObject *>::*(NiTMapItem<NiFixedString,NiAVObject *>*, NiFixedString&, NiAVObject*)
    // void __cdecl NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiAVObject *> >,NiAVObject *>::*(NiTMapItem<NiFixedString,NiAVObject *>*)
    // NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiAVObject *> >,NiAVObject *>& __cdecl NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiAVObject *> >,NiAVObject *>::*(const NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiAVObject *> >,NiAVObject *>&)
    // void __cdecl NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiAVObject *> >,NiAVObject *>::*()
    // void __cdecl NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiAVObject *> >,NiAVObject *>::*()
};
#pragma pack(pop)
typedef char NiDefaultPalette_layout_check_5[(sizeof(NiTFixedStringMapBase_DFALL_NiTMapItem_NiFixedString_NiAVObject______NiAVObject___) == 16) ? 1 : -1];
typedef char NiDefaultPalette_layout_check_6[(offsetof(NiTFixedStringMapBase_DFALL_NiTMapItem_NiFixedString_NiAVObject______NiAVObject___,
                           m_ppVirtualMethodTable) == 0) ? 1 : -1];
typedef char NiDefaultPalette_layout_check_7[(offsetof(NiTFixedStringMapBase_DFALL_NiTMapItem_NiFixedString_NiAVObject______NiAVObject___,
                           m_uiHashSize) == 4) ? 1 : -1];
typedef char NiDefaultPalette_layout_check_8[(offsetof(NiTFixedStringMapBase_DFALL_NiTMapItem_NiFixedString_NiAVObject______NiAVObject___,
                           m_ppkHashTable) == 8) ? 1 : -1];
typedef char NiDefaultPalette_layout_check_9[(offsetof(NiTFixedStringMapBase_DFALL_NiTMapItem_NiFixedString_NiAVObject______NiAVObject___,
                           m_kItemCount) == 12) ? 1 : -1];
#pragma pack(push, 4)
class PaletteObjectMapView
    : public NiTFixedStringMapBase_DFALL_NiTMapItem_NiFixedString_NiAVObject______NiAVObject___
{
  public:
    void GetNext(void*&, NiFixedString&, NiAVObject*&);
    void RemoveAll();
    // base NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiAVObject *> >,NiAVObject *> at +0x0, size 16
    // NiTFixedStringMap<NiAVObject *>
    // void __cdecl NiTFixedStringMap<NiAVObject *>::*()
    // NiTMapItem<NiFixedString,NiAVObject *>* __cdecl NiTFixedStringMap<NiAVObject *>::*()
    // void __cdecl NiTFixedStringMap<NiAVObject *>::*(NiTMapItem<NiFixedString,NiAVObject *>*)
    // NiTFixedStringMap<NiAVObject *>& __cdecl NiTFixedStringMap<NiAVObject *>::*(const NiTFixedStringMap<NiAVObject *>&)
    // void __cdecl NiTFixedStringMap<NiAVObject *>::*()
    // void __cdecl NiTFixedStringMap<NiAVObject *>::*()
};
#pragma pack(pop)
typedef char NiDefaultPalette_layout_check_10[(sizeof(PaletteObjectMapView) == 16) ? 1 : -1];
#endif
