#pragma once

#include "bhkConvexShape.h"

class bhkTriangleShape : public bhkConvexShape
{
public:
    static NiObject* __cdecl CreateObject();
};
