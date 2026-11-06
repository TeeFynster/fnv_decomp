#pragma once

#include "hkpKeyframedRigidMotion.h"

class hkpMaxSizeMotion : public hkpKeyframedRigidMotion
{
public:
    static const ClassMemberDescriptor Members[];

private:
    void operator=(const hkpMaxSizeMotion& other);
};
