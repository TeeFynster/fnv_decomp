#pragma once

#include "hkpShape.h"

class hkSphere;
struct CollisionSphereData;

class hkpHeightFieldShape : public hkpShape
{
public:
    virtual void CollideSpheres(const CollisionSphereData& input, hkSphere* hitResults);
};
