#pragma once

#include "../../../include/NiTPointerMap.h"

#include "../../../include/PATHING_REQUEST_TYPE.h"

class PathingRequestUnknown : public PathingRequest
{
};
bool Pathing_Pathfind(PathingRequest*, PathingSolution*);
bool Pathing_BuildFleePath(PathingRequestClosePoint*, PathingSolution*);
bool Pathing_BuildCoveredMovePath(PathingRequestUnknown*, PathingSolution*);

#include "../../../include/PathingGraphNode.h"
class PacketNodeRecord : public PathingGraphNode
{
  public:
    bool VirtualPathingNode_HasActualLocation();
};

int CollectNearbyEdges(PathingLocation*, int, TESObjectREFR*);

