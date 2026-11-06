// RTTI 0x0101dce4 and ctor 0x004968b0 identify the 8-byte NiRefObject base, not PathingInfo.
#include "../../../include/NiRefObject.h"
// Names of nested/template specializations use the canonical generator identifier mapping.
#include "../../../include/PathingActorData.h"
#include "../../../include/PathingRequest.h"
#ifndef FNV_PATHINGREQUEST_H
#define FNV_PATHINGREQUEST_H

#include "layout_support.h"
class Actor;
template <class T, unsigned int N> class BSSimpleArray;
#include "InventoryChanges.h"
#include "NiPoint3.h"
#include "NiRefObject.h"
#include "PathingLocation.h"
#include "layout_support.h"
class BGSLoadFormBuffer;
class PathingActorData;
class PathingAvoidNodeArray;
class PathingRequest;
#include "../../../include/PATHING_REQUEST_TYPE.h"
#pragma pack(push, 4)
#pragma pack(pop)
#pragma pack(push, 4)

class PathingRequestLocation : public PathingLocation
{
  public:
    PathingRequestLocation();
    ~PathingRequestLocation();
};
class PathingRequestCenter : public NiPoint3
{
  public:
    PathingRequestCenter();
};
class PathingRequestAvoidPointer
{
  public:
    PathingAvoidNodeArray* m_pObject;
    PathingRequestAvoidPointer(PathingAvoidNodeArray*);
    ~PathingRequestAvoidPointer();
};
#pragma pack(pop)
#endif
