#pragma once

#include "NiPSysModifierFloatCtlr.h"

class NiPSysAirFieldAirFrictionCtlr : public NiPSysModifierFloatCtlr
{
public:
    void CopyMemberData(NiPSysAirFieldAirFrictionCtlr*, CloningProcess&);
    void GetTargetFloatValue_00c307d0(float& rfValue);
};
