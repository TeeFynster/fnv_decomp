#pragma once

#include "bhkConstraint.h"

class bhkPrismaticConstraint : public bhkConstraint
{
public:
    static NiObject* __cdecl CreateObject();
};
