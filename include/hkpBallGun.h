#pragma once

#include "hkpFirstPersonGun.h"
#include "hkVector4.h"

class hkpBallGun : public hkpFirstPersonGun
{
public:
    hkReal m_fBulletRadius;
    hkReal m_fBulletVelocity;
    hkReal m_fBulletMass;
    hkReal m_fBulletSpread;
    hkInt32 m_iBulletBatchCount;
    char pad34[0xC];
    hkVector4 m_kBulletDirection;
    void* m_pBulletQueue;
    char pad54[0xC];
};
