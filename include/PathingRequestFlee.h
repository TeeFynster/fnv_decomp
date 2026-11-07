#pragma once

#include "PathingRequest.h"

class FleeActor;
class PathingAvoidNodeArray;
class PathingRequestOwner;
namespace FleeUpdate { class Actor; }

class PathingRequestFlee : public PathingRequest
{
public:
    PathingRequestFlee();
    PathingRequestFlee(PathingRequestOwner* owner);
    virtual ~PathingRequestFlee();
    virtual void CopyTo(PathingRequest* apDest);
    virtual PATHING_REQUEST_TYPE GetType();
    virtual void SaveGame(BGSSaveFormBuffer* apSaveGameBuffer);
    virtual void LoadGame(BGSLoadFormBuffer* apLoadGameBuffer);

    void* DestroyAndFree(unsigned int flags);
    void CopyToWithFleeData(PathingRequest* apDest);
    void InitFromActor(Actor* actor);
    void InitFromActor(FleeActor* actor);
    void InitFromActor(FleeUpdate::Actor* actor);
    void SetInitialPathHeading(float heading);
    void SetCantOpenDoors(bool cantOpenDoors);

    void FUN_006d3b00(float);
    void FUN_006d61e0(PathingAvoidNodeArray*);
    void FUN_006d61e0(void*);
    void PathingRequestClosePoint_SetMinDistance(float);
    void FUN_006d1bc0(const PathingLocation&);
    void PathingRequest_SetNoDestination();

    float fleeRadius;
};
