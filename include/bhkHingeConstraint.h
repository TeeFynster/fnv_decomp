#pragma once

#include "bhkConstraint.h"

class bhkHingeConstraint : public bhkConstraint
{
public:
    virtual const NiRTTI* GetRTTI() const;

    static NiObject* __cdecl CreateObject();
    unsigned int GetInstanceSize();
    void* FUN_009ba520(unsigned int);

    static const NiRTTI ms_kRTTI;
};
