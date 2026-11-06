#pragma once

#include "hkpCdBody.h"

struct RayCastHitResult;

class hkpRayHitCollector
{
public:
    hkpRayHitCollector();

    virtual void CollectRayHit(const hkpCdBody& cdBody, const RayCastHitResult& hitInfo) = 0;
    virtual void vf01();

    void reset();

    float m_fEarlyOutHitFraction;
};
