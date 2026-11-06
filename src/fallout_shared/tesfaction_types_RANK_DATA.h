// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_RANK_DATA_H
#define FNV_RANK_DATA_H

#include "layout_support.h"
#include "../../include/TESTexture.h"
#include "layout_support.h"
class FactionRankPresentation;
#pragma pack(push, 4)
class FactionRankPresentation
{
  public:
    BSStringT<char> m_kMaleRankName;    // +0x0, 8 bytes
    BSStringT<char> m_kFemaleRankName;  // +0x8, 8 bytes
    TESTexture m_kRankTexture;          // +0x10, 12 bytes
    FactionRankPresentation();
    ~FactionRankPresentation();
    static void* operator new(unsigned int);
    static void operator delete(void*);
    int DestroyAndFree(unsigned int);
    // FactionRankPresentation
    // void __cdecl FactionRankPresentation::*()
    // FactionRankPresentation& __cdecl FactionRankPresentation::*(const FactionRankPresentation&)
    // void* __cdecl FactionRankPresentation::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(FactionRankPresentation) == 28);
FNV_STATIC_ASSERT(offsetof(FactionRankPresentation, m_kMaleRankName) == 0);
FNV_STATIC_ASSERT(offsetof(FactionRankPresentation, m_kFemaleRankName) == 8);
FNV_STATIC_ASSERT(offsetof(FactionRankPresentation, m_kRankTexture) == 16);
#endif
