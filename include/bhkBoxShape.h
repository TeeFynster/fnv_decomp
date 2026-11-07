#pragma once

#include "bhkConvexShape.h"
#include "NiRTTI.h"
#include "hkVector4.h"

class bhkBoxShape : public bhkConvexShape
{
public:

    virtual const NiRTTI* GetRTTI() const;

    void Init(const hkVector4& halfExtents);
    void bhkShape_Link(bool b);

    static NiObject* __cdecl CreateObject();
    static const NiRTTI ms_kRTTI;
};
