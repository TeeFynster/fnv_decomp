// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_DOORTELEPORTDATA_H
#define FNV_DOORTELEPORTDATA_H
#include "layout_support.h"
#include "NiPoint3.h"
#include "TESObjectREFR.h"
class TeleportableReference;
#pragma pack(push, 4)
class TeleportableReference
{
  public:
    TESObjectREFR* m_pLinkedDoorReference;  // +0x0, 4 bytes
    NiPoint3 position;                      // +0x4, 12 bytes
    NiPoint3 rotation;                      // +0x10, 12 bytes
    unsigned char cFlags;                   // +0x1C, 1 bytes
    unsigned char layoutPadding1D[3];
    TESForm* GetTeleportDestinationForm(void);
    TESWorldSpace* GetTeleportWorldspace(void);
    void SetLinkedDoorReference(TESObjectREFR* reference, bool set);
    DoorCell* DoorTeleportData_GetTeleportCell(void);
    bool InitItem(TESForm* form);
    void Load(TESFile* file);
    // SaveGame
    // LoadGame
    // InitLoadGame
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TeleportableReference) == 32);
FNV_STATIC_ASSERT(offsetof(TeleportableReference, m_pLinkedDoorReference) == 0);
FNV_STATIC_ASSERT(offsetof(TeleportableReference, position) == 4);
FNV_STATIC_ASSERT(offsetof(TeleportableReference, rotation) == 16);
FNV_STATIC_ASSERT(offsetof(TeleportableReference, cFlags) == 28);
#endif
