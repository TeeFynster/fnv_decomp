// src/fallout_shared/pathfinding/pathingrequestclosepoint.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/pathfinding/pathingrequestclosepoint.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../include/BGSLoadFormBuffer.h"
#include "../../../include/BGSSaveFormBuffer.h"
#include "../../../include/PathingRequest.h"
#include "../../../include/PathingRequestClosePoint.h"

extern float g_011c7b14_arg1;

// @fnv 0x006e3f30
PathingRequestClosePoint::PathingRequestClosePoint() : PathingRequest()
{
    fPointHeight = 128.0f;
    m_fUnknownValue2 = g_011c7b14_arg1;
}

// Runs the destructor and, when bit 0 of flags is set, frees the object with operator delete; returns this.
// @fnv 0x006e3f70
void* __thiscall PathingRequestClosePoint::FUN_006e3f70(unsigned int flags)
{
    this->PathingRequestClosePoint::~PathingRequestClosePoint();
    if (flags & 1)
        PathingRequestClosePoint::operator delete(this, 0xb8);
    return this;
}

// Calls the base save routine, then writes the two close-point fields to the save buffer.
// @fnv 0x006e5f00
// src: XBOX_PDB 0x006e5f00
void __thiscall PathingRequestClosePoint::PathingRequestOptimalLocation_SaveGame(BGSSaveFormBuffer* apSaveGameBuffer)
{
    PathingRequest::PathingRequest_SaveGame(apSaveGameBuffer);
    apSaveGameBuffer->SaveData(&fPointHeight, 4, 0);
    apSaveGameBuffer->SaveData(&m_fUnknownValue2, 4, 0);
}

// Calls the base load routine, then reads the two close-point fields from the buffer.
// @fnv 0x006e5f50
// src: XBOX_PDB 0x006e5f50
void PathingRequestClosePoint::PathingRequestOptimalLocation_LoadGame(BGSLoadFormBuffer* apLoadGameBuffer)
{
    PathingRequest::LoadGame(apLoadGameBuffer);
    apLoadGameBuffer->ReadTypedData(&fPointHeight, 4u);
    apLoadGameBuffer->ReadTypedData(&m_fUnknownValue2, 4u);
}

// @fnv 0x006e4030
void __thiscall PathingRequestClosePoint::CopyToWithClosePoint(PathingRequest* apDest)
{
    PathingRequestClosePoint* pdest = (PathingRequestClosePoint*)apDest;
    PathingRequest::CopyTo((PathingRequest*)pdest);
    pdest->PathingRequestClosePoint_SetMinDistance(this->fPointHeight);
    pdest->SetMaxDistance_006e5ee0(this->m_fUnknownValue2);
}

// @fnv 0x006e3fb0
PathingRequestClosePoint::PathingRequestClosePoint(PathingRequestClosePoint* src) : PathingRequest(src)
{
    fPointHeight = src->GetMinDist();
    m_fUnknownValue2 = src->GetMaxDist();
}
