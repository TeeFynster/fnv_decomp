#pragma once

#include "hkBool.h"

class WorldRayCastInput;
class hkpCollidable;
struct ClassMemberDescriptor;

class hkpRayCollidableFilter
{
public:
    static const ClassMemberDescriptor Members[];

    virtual ~hkpRayCollidableFilter();
    virtual hkBool IsCollisionEnabled(const WorldRayCastInput& input, const hkpCollidable& collidable) const = 0;
};
