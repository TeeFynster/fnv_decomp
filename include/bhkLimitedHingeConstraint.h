#pragma once

#include "bhkConstraint.h"

class bhkLimitedHingeOutput;

class bhkLimitedHingeConstraint : public bhkConstraint
{
public:
    void PopulateOutput(bhkLimitedHingeOutput*);
    const float* GetFirst() const;
    const float* GetSecond() const;

    static NiObject* __cdecl CreateObject();
};
