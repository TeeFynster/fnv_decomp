// fallout/ai/lowprocess_types_PackageLocation.h: declares LocationDescriptor

#include "../../../include/PACK_LOC_TYPE.h"
// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_PACKAGELOCATION_H
#define FNV_PACKAGELOCATION_H
#include "layout_support.h"
#include "../../../include/TESForm.h"
#include "../../../include/TESObjectREFR.h"
#include "layout_support.h"
class LocationDescriptor;
#pragma pack(push, 4)
class LocationDescriptor
{
  public:
    bool PackageLocation_IsLocationGeneric();
    TESBoundObject* FUN_0067f430();
    PACKAGE_OBJECT_TYPE GetObjectType();
    TESObjectREFR* GetLocationReference();
    PACK_LOC_TYPE GetLocType() const;

    char m_ucLocationType;  // +0x0, 1 bytes
    unsigned char layoutPadding1[3];
    unsigned int m_pLocationData;  // +0x4, 4 bytes
    union
    {                                  // overlapping CodeView storage
        TESForm* pObject;              // +0x8, 4 bytes
        PACKAGE_OBJECT_TYPE eObjType;  // +0x8, 4 bytes
        TESObjectREFR* pRef;           // +0x8, 4 bytes
        TESObjectCELL* pCell;          // +0x8, 4 bytes
        TESForm* m_pLocationObject;    // +0x8, 4 bytes
    };
    // LocationDescriptor
    // void __cdecl LocationDescriptor::*()
    // PACK_LOC_TYPE __cdecl LocationDescriptor::*()
    // void __cdecl LocationDescriptor::*(PACK_LOC_TYPE)
    // void __cdecl LocationDescriptor::*(unsigned int)
    // TESObjectREFR* __cdecl LocationDescriptor::*()
    // TESObjectCELL* __cdecl LocationDescriptor::*()
    // TESForm* __cdecl LocationDescriptor::*()
    // PACKAGE_OBJECT_TYPE __cdecl LocationDescriptor::*()
    // void __cdecl LocationDescriptor::*(TESObjectREFR*)
    // void __cdecl LocationDescriptor::*(TESObjectCELL*)
    // void __cdecl LocationDescriptor::*(TESForm*)
    // void __cdecl LocationDescriptor::*(PACKAGE_OBJECT_TYPE)
    // void __cdecl LocationDescriptor::*(LocationDescriptor*, bool)
    // bool __cdecl LocationDescriptor::*(LocationDescriptor*)
    // void __cdecl LocationDescriptor::*(CHUNK_ID)
    // void __cdecl LocationDescriptor::*(TESForm*)
    // bool __cdecl LocationDescriptor::*()
    // bool __cdecl LocationDescriptor::*(TESForm*)
    // bool __cdecl LocationDescriptor::*()
    // TESObjectREFR* __cdecl LocationDescriptor::*(MobileObject*)
    // bool __cdecl LocationDescriptor::*(MobileObject*, TESObjectREFR*, bool&)
    // unsigned short __cdecl LocationDescriptor::*()
    // SaveGame
    // LoadGame
    // InitLoadGame
    // unsigned int __cdecl LocationDescriptor::*()
    // void* __cdecl LocationDescriptor::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(LocationDescriptor) == 12);
FNV_STATIC_ASSERT(offsetof(LocationDescriptor, m_ucLocationType) == 0);
FNV_STATIC_ASSERT(offsetof(LocationDescriptor, m_pLocationData) == 4);
FNV_STATIC_ASSERT(offsetof(LocationDescriptor, pObject) == 8);
FNV_STATIC_ASSERT(offsetof(LocationDescriptor, eObjType) == 8);
FNV_STATIC_ASSERT(offsetof(LocationDescriptor, pRef) == 8);
FNV_STATIC_ASSERT(offsetof(LocationDescriptor, pCell) == 8);
FNV_STATIC_ASSERT(offsetof(LocationDescriptor, m_pLocationObject) == 8);
#endif
