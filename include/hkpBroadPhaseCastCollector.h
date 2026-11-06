#pragma once

#include "hkpBroadPhaseHandle.h"

class hkpBroadPhaseCastCollector
{
public:
    virtual ~hkpBroadPhaseCastCollector();
    virtual float ReleaseCollector(const hkpBroadPhaseHandle* broadphaseHandle, int castIndex) = 0;
};
