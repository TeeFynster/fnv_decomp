// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_PATHINGINFOITEM_H
#define FNV_PATHINGINFOITEM_H

#include "../../../include/PathingLocation.h"
class PathingInfoEntry;
class PathingInfoParams;
#include "../../../include/PATHING_INFO_TYPE.h"
#include "../../../include/PATHING_MESSAGE_ID.h"
#include "../../../include/PATHING_PARAMETER_ID.h"
#pragma pack(push, 4)
class PathingInfoParams
{
  public:
    int ints[3];               // +0x0, 12 bytes
    PathingLocation location;  // +0xC, 40 bytes
    // PathingInfoParams
    // const PathingInfoParams& __cdecl PathingInfoParams::*(const PathingInfoParams&)
    // void __cdecl PathingInfoParams::*()
    // void __cdecl PathingInfoParams::*()
    // void* __cdecl PathingInfoParams::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(PathingInfoParams) == 52);
FNV_STATIC_ASSERT(offsetof(PathingInfoParams, ints) == 0);
FNV_STATIC_ASSERT(offsetof(PathingInfoParams, location) == 12);
#pragma pack(push, 4)
class PathingInfoEntry
{
  public:
    PathingInfoEntry& operator=(const PathingInfoEntry&);
    PATHING_INFO_TYPE InfoType;    // +0x0, 4 bytes
    PATHING_MESSAGE_ID MessageID;  // +0x4, 4 bytes
    PATHING_PARAMETER_ID ParamID;  // +0x8, 4 bytes
    PathingInfoParams Params;      // +0xC, 52 bytes
    // PathingInfoEntry
    // PathingInfoEntry& __cdecl PathingInfoEntry::*(const PathingInfoEntry&)
    // void __cdecl PathingInfoEntry::*(IDebugText*)
    // void __cdecl PathingInfoEntry::*(char*, int)
    // void __cdecl PathingInfoEntry::*()
    // void* __cdecl PathingInfoEntry::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(PathingInfoEntry) == 64);
FNV_STATIC_ASSERT(offsetof(PathingInfoEntry, InfoType) == 0);
FNV_STATIC_ASSERT(offsetof(PathingInfoEntry, MessageID) == 4);
FNV_STATIC_ASSERT(offsetof(PathingInfoEntry, ParamID) == 8);
FNV_STATIC_ASSERT(offsetof(PathingInfoEntry, Params) == 12);
#endif
