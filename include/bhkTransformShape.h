#pragma once

#include "bhkShape.h"

class bhkTransformShape : public bhkShape
{
public:
    static NiObject* __cdecl CreateObject();
    void* __thiscall Destroy(unsigned int);
};
