#pragma once

#include "NiPSysModifierCtlr.h"

class NiPSysModifierFloatCtlr : public NiPSysModifierCtlr
{
public:
    NiPSysModifierFloatCtlr();
    virtual ~NiPSysModifierFloatCtlr();

    virtual void LinkObject(NiStream& stream) override;
    virtual void GetValue(float* value);
    virtual void SetTargetVal61(float fVal);

    void SetTargetValue(float fValue);
    void GetTargetValue(float& rfValue);
    void UpdateController(float& fTime);
    void __thiscall SynchronizePoseInterpolator_00c32e90(NiObject* pkInterp, unsigned short usIndex);
};

