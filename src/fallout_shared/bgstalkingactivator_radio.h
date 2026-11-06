#include "../../include/Pathing.h"
// fallout_shared/bgstalkingactivator_radio.h: declares NiPoint3, TESObjectREFR, ParentSpaceNode, TeleportLink, PathingPath and more
#ifndef FNV_BGSTALKINGACTIVATOR_RADIO_H
#define FNV_BGSTALKINGACTIVATOR_RADIO_H

#include "bgstalkingactivator.h"
#include <float.h>
#include "../../include/PathingPath.h"
#include "../../include/BSSimpleArray.h"
class TESWorldSpace;
class TESObjectCELL;
class NavMeshInfo;
class PathingActorData;
#include "../../include/NiPoint3.h"
#include "../../include/RADIO_RANGE_TYPE.h"
#include "../../include/TESObjectREFR.h"
class ParentSpaceNode
{
  public:
    bool m_bIsWorldspace;
    TESWorldSpace* m_pContainingWorldspace;
    TESObjectCELL* m_pReferenceCell;
};
class TeleportLink
{
  public:
    TESObjectREFR* pPathNodeDoor;
    NiPoint3 m_kDestinationPosition;
};
#include "../../include/PathingLocation.h"

FNV_STATIC_ASSERT(sizeof(PathingPath) == 56);
FNV_STATIC_ASSERT(sizeof(ParentSpaceNode) == 12);
#endif
