// Unit-private additions. No supplied header or accepted definition is changed.
#ifndef FNV_EXTRADATAOBJECTS_ADDITIONS_H
#define FNV_EXTRADATAOBJECTS_ADDITIONS_H

// Canonical callable identities from IDENTITIES.md. Settings named by
// JohnnyGuitarNVSE GameSettingCollection.hpp and JIP settings_enum.h.
#include "../../include/GameSettingCollection.h"
#include "../../include/SettingT_GameSettingCollection_.h"

#include "../../include/NiPoint3.h"

// Names of nested/template specializations use the canonical generator identifier mapping.
class ReferenceIntersectionData
{
  public:
    ReferenceIntersectionData();
    TESObjectREFR* m_pHitReference;  // +0x0, 4 bytes
    NiPoint3 Intersect;              // +0x4, 12 bytes
    NiPoint3 Normal;                 // +0x10, 12 bytes
};
FNV_STATIC_ASSERT(sizeof(ReferenceIntersectionData) == 28);
FNV_STATIC_ASSERT(offsetof(ReferenceIntersectionData, m_pHitReference) == 0);
FNV_STATIC_ASSERT(offsetof(ReferenceIntersectionData, Intersect) == 4);
FNV_STATIC_ASSERT(offsetof(ReferenceIntersectionData, Normal) == 16);

// Names of nested/template specializations use the canonical generator identifier mapping.
#include "../../include/ExtraHealth.h"

// independently declares these names/types and the PC8-byte record layout.
class FactionReaction
{
  public:
    TESFaction* pFaction;
    char m_ucRank;
};
FNV_STATIC_ASSERT(sizeof(FactionReaction) == 8);
FNV_STATIC_ASSERT(offsetof(FactionReaction, pFaction) == 0);
FNV_STATIC_ASSERT(offsetof(FactionReaction, m_ucRank) == 4);
void* __cdecl operator new(unsigned int size);
void __cdecl operator delete(void* pointer);

void* __cdecl operator new[](unsigned int size);
void __cdecl operator delete[](void* pointer);
extern "C" void* __cdecl memcpy(void* destination, const void* source, unsigned int size);

// Public names/layout: JohnnyGuitarNVSE BGSQuestObjective.hpp; its cpp
// explicitly annotates SetOwner as GAME00437730. No implementation copied.
class TESQuest;
class RegionObjectEntry;
#include "../../include/BGSQuestObjective.h"
#endif
