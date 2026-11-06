#pragma once

#include "bhkGenericConstraint.h"

class bhkFixedConstraint : public bhkGenericConstraint
{
public:
    bhkFixedConstraint();
    virtual ~bhkFixedConstraint();

    static NiObject* __cdecl CreateObject();
};
