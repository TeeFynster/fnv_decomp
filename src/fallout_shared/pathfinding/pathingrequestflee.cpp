// src/fallout_shared/pathfinding/pathingrequestflee.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/pathfinding/pathingrequestflee.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/BGSLoadFormBuffer.h"
#include "../../../include/BGSSaveFormBuffer.h"
#include "../../../include/PathingRequestFlee.h"

class PathingRequestOwner
{
public:
    float GetGoalRadius() const;
};

// Initializes the base request and the flee radius.
// @fnv 0x006e5390
PathingRequestFlee::PathingRequestFlee()
{
    fleeRadius = 128.0f;
}

// Destructs the base and optionally frees the request.
// @fnv 0x006e53c0
void* PathingRequestFlee::DestroyAndFree(unsigned int flags)
{
    PathingRequest::DestroyPathingRequest();
    if (flags & 1)
        PathingRequest::operator delete(this, 0xb4);
    return this;
}

// Constructs the base from the owner and takes its goal radius.
// @fnv 0x006e5400
PathingRequestFlee::PathingRequestFlee(PathingRequestOwner* owner) : PathingRequest(owner)
{
    fleeRadius = owner->GetGoalRadius();
}

// @fnv 0x006e5470
void PathingRequestFlee::CopyToWithFleeData(PathingRequest* apDest)
{
    PathingRequest* pdest = apDest;
    PathingRequest::CopyTo(pdest);
    ((PathingRequestFlee*)pdest)->fleeRadius = fleeRadius;
}

// Saves the base request and the flee radius.
// @fnv 0x006e54b0
void PathingRequestFlee::SaveGame(BGSSaveFormBuffer* apSaveGameBuffer)
{
    PathingRequest::SaveGame(apSaveGameBuffer);
    apSaveGameBuffer->SaveData(&fleeRadius, 4, 0);
}

// Loads the base request and the flee radius.
// @fnv 0x006e54e0
void PathingRequestFlee::LoadGame(BGSLoadFormBuffer* apLoadGameBuffer)
{
    PathingRequest::LoadGame(apLoadGameBuffer);
    apLoadGameBuffer->ReadTypedData((void*)&fleeRadius, 4u);
}
