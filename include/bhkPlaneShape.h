#pragma once

#include "bhkHeightFieldShape.h"

class bhkPlaneShape : public bhkHeightFieldShape
{
public:
    static NiObject* __cdecl CreateObject();
};
