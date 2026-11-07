#ifndef FNV_TESOBJECTTREE_H
#define FNV_TESOBJECTTREE_H
#include "tesobjecttree_packet_decls.h"

// @fnv 0x0045cd80
float BGSProjectile::GetExplosionProximity() const
{
    return explosionProximity;
}

// @fnv 0x0051b860
float PathingRequest::GetSmoothingRandomness()
{
    return smoothingRandomness;
}

// @fnv 0x006a78f0
float PathingRequest::GetTargetRadius()
{
    return targetRadius;
}

// @fnv 0x009a7c40
float PathingRequest::GetActorRadius()
{
    return actorRadius;
}

// @fnv 0x009b0bd0
float PathingRequest::GetCenterRadius()
{
    return centerRadius;
}

// @fnv 0x0051b8e0
float PathingRequest::GetGoalZDelta()
{
    return goalZDelta;
}

// @fnv 0x0051b840
void PathingRequest::SetActorRadius(float value)
{
    actorRadius = value;
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
    centerRadius = value;
}

// @fnv 0x006e2960
void PathingRequest::SetSmoothingRandomness(float value)
{
    smoothingRandomness = value;
}

#endif
