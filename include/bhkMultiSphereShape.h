#pragma once

#include "bhkSphereRepShape.h"

class bhkMultiSphereShape : public bhkSphereRepShape
{
public:
    static NiObject* __cdecl CreateObject();
    unsigned int GetInstanceSize();
};
