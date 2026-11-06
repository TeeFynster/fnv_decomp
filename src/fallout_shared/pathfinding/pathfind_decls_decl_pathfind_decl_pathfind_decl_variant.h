#pragma once

#include "../../../include/NiTPointerMap.h"

#include "../../../include/PATHING_REQUEST_TYPE.h"

class PathingRequestUnknown : public PathingRequest
{
};
bool FUN_006d0b10(PathingRequest*, PathingSolution*);
bool FUN_006d0be0(PathingRequestClosePoint*, PathingSolution*);
bool FUN_006d2c80(PathingRequestUnknown*, PathingSolution*);

#include "../../../include/PathingGraphNode.h"
class PacketNodeRecord : public PathingGraphNode
{
  public:
    bool FUN_006cac70();
};

int CollectNearbyEdges(PathingLocation*, int, TESObjectREFR*);

