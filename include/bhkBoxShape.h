#pragma once

#include "bhkConvexShape.h"
#include "NiRTTI.h"
#include "hkVector4.h"

class bhkBoxShape : public bhkConvexShape
{
public:

    virtual const NiRTTI* GetRTTI() const;

    void Init(const hkVector4& halfExtents);
    void FUN_00c84e50(bool b);

    static NiObject* __cdecl CreateObject();
    static const NiRTTI ms_kRTTI;
};
