#include "../../../include/NiPointer.h"
#include "../../../include/Pathing.h"
#include "../../../include/layout_support.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/NavMeshPtr.h"
#include "../../../include/PathBuilder.h"
#include "../../../include/PathingLocation.h"
#include "../../../include/PathingSolution.h"
#include "../../../include/AutoMemContext.h"
// ActorDeletionQueue_pathfind_decls: local type (was include/ActorDeletionQueue.h, which had no evidence of one real class); its methods are 0x0096d450 ProcessLists::AddReference, 0x0096d470 ProcessLists::RemoveReference, 0x0096d490 ProcessLists::GetSystemTimeClock
// PathfindQueueStorage_pathfind_decls: local type (was include/PathfindQueueStorage.h, which had no evidence of one real class); its methods are 0x0096aaf0 ProcessArray::RemoveActor
class MobileObject;

class PathfindQueueStorage_pathfind_decls
{
public:
    void ProcessArray_RemoveActor_0096aaf0(MobileObject* apObject, int aeLevel);
};

class MobileObject;
class ActorSV;
struct ReferenceView;

class ActorDeletionQueue_pathfind_decls
{
public:
    unsigned int pad;
    PathfindQueueStorage_pathfind_decls storage;
    unsigned char unk05[3];

    void ProcessLists_RemoveReference(MobileObject*, int);
    void ProcessLists_RemoveReference(ActorSV*, int);
    void ProcessLists_RemoveReference(ReferenceView*, int);
    float ProcessLists_GetSystemTimeClock();
    void ProcessLists_AddReference(MobileObject*, int, bool, bool, bool);
    void ProcessLists_AddReference(ActorSV*, int, bool, bool, ActorSV*);
};
#include "../../../include/PathingPath.h"
class NavMesh;
class PathingActorData;
class TESObjectREFR;
#include "../../../include/PATHING_REQUEST_TYPE.h"
#include "../../../include/PathingRequestClosePoint.h"
#include "../../../include/PathingRequestHide.h"
#include "../../../include/PathingRequestFlee.h"
#include "../../../include/PathingRequestLOS.h"
#include "../../../include/PathingRequestOptimalLocation.h"
#include "../../../include/TESPackage.h"
#include "../../../include/NavMesh.h"
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
#include "../../../include/BSSimpleArray.h"
int CollectNearbyEdges(PathingLocation*, int, TESObjectREFR*);
