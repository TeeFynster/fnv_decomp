#pragma once

#include "hkpShape.h"

class hkSphere;

class hkpSphereRepShape : public hkpShape
{
public:
    static const ClassMemberDescriptor Members[];

    hkpSphereRepShape(hkpShapeType type);
    hkpSphereRepShape(FinishingFlag flag);

    int getNumCollisionSpheres() const;
    const hkSphere* getCollisionSpheres(hkSphere* sphereBuffer) const;
};
