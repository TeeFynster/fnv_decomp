
// src/fallout_shared/pathfinding/pathingrequestoptimallocation.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/pathfinding/pathingrequestoptimallocation.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/PathingRequest.h"
#include "../../../include/PathingRequestOptimalLocation.h"

extern void _delete(void* p, unsigned int size);

// @fnv 0x006e5d70
void* PathingRequestOptimalLocation::FUN_006e5d70(unsigned int flags)
{
    this->PathingRequest::DestroyPathingRequest();
    if (flags & 1)
        _delete(this, 0xc0);
    return this;
}

extern float g_011c7b14_arg1;

// Initializes the PathingRequest base and the four optimal-location values.
// @fnv 0x006e5d10
PathingRequestOptimalLocation::PathingRequestOptimalLocation() : PathingRequest()
{
    fPointHeight = 128.0f;
    m_fUnknownValue2 = g_011c7b14_arg1;
    m_fUnknownValue3 = 128.0f;
    m_fUnknownValue4 = g_011c7b14_arg1;
}

// @fnv 0x006e5e60
void PathingRequestOptimalLocation::CopyTo(PathingRequest* apDest)
{
    PathingRequest* pdest = apDest;
    PathingRequest::CopyTo(pdest);
    pdest->PathingRequestClosePoint_SetMinDistance(fPointHeight);
    pdest->SetMaxDistance_006e5ee0(m_fUnknownValue2);
    pdest->PathingRequestCoveredMove_SetAttackerHeight(m_fUnknownValue3);
    pdest->PathingRequestCoveredMove_SetAttackerSneakHeight(m_fUnknownValue4);
}

// @fnv 0x006e5db0
PathingRequestOptimalLocation::PathingRequestOptimalLocation(PathingRequestOptimalLocation* pSource)
    : PathingRequest(pSource)
{
    fPointHeight = pSource->GetFloatAtOffsetB0();
    m_fUnknownValue2 = pSource->GetFieldB4Float();
    m_fUnknownValue3 = pSource->GetFieldB8Float();
    m_fUnknownValue4 = pSource->BSSceneGraph_GetCameraFOV();
}
