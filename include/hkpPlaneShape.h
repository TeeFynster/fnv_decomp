#pragma once

#include "hkpHeightFieldShape.h"
#include "hkVector4.h"

class hkpPlaneShape : public hkpHeightFieldShape
{
public:
    virtual void vf12();

    hkVector4 m_kTriangleNormal;
    hkVector4 m_kAabbCenter;
    hkVector4 m_kAabbHalfExtents;
};
