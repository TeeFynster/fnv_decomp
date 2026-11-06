#pragma once

#include "hkpBallGun.h"
#include "hkVector4.h"

class hkpMountedBallGun : public hkpBallGun
{
public:
    hkVector4 m_vContactPosition;
};
