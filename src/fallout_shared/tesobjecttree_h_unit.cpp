#include "../../include/BGSProjectile.h"
#include "../../include/PathingRequest.h"
#include "../../include/TESWorldSpace.h"

// @fnv 0x0045cd80
float BGSProjectile::GetExplosionProximity() const
{
    return Data.LightExplosionSoundData;
}

// @fnv 0x0051b860
float PathingRequest::GetSmoothingRandomness()
{
    return PathingActorSpatialData;
}

// @fnv 0x006a78f0
float PathingRequest::GetTargetRadius()
{
    return m_fCenterRadius;
}

// @fnv 0x009a7c40
float PathingRequest::GetActorRadius()
{
    return m_fSecondValueAfterActorData;
}

// @fnv 0x009b0bd0
float PathingRequest::GetCenterRadius()
{
    return fWeaponSpread;
}

// @fnv 0x0051b8e0
float PathingRequest::GetGoalZDelta()
{
    return m_fFloatAfterCenter;
}

// @fnv 0x0051b840
void PathingRequest::SetActorRadius(float value)
{
    m_fSecondValueAfterActorData = value;
}

// @fnv 0x00584150
// src: COMMUNITY 0x00584150
void TESWorldSpace::SetWaterLODHeight(float value)
{
    field7c = value;
}

// @fnv 0x006d3b00
void PathingRequest::SetCenterRadius(float value)
{
    fWeaponSpread = value;
}

// @fnv 0x006e2960
void PathingRequest::SetSmoothingRandomness(float value)
{
    PathingActorSpatialData = value;
}
