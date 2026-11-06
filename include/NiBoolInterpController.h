#pragma once

#include "NiSingleInterpController.h"

class NiBoolInterpolator;

class NiBoolInterpController : public NiSingleInterpController
{
public:
    virtual const NiRTTI* GetRTTI() const;
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual bool RegisterStreamables(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;
    virtual void GetViewerStrings(NiViewerStringsArray* strings);
    virtual NiInterpolator* GetInterpolatorAtIndex(unsigned short index);
    virtual void SetInterpolatorForTarget(NiInterpolator* interpolator, unsigned short index);
    virtual NiBlendInterpolator* GetBlendInterpolator(unsigned short index, bool managerControlled,
                                                     bool accumulateAnimations, float threshold, unsigned char size);
    virtual bool ControlsTransform(NiInterpolator* interpolator, unsigned short index) const;
    virtual void GetPoseValue(bool& value);

    void CopyMemberData(NiBoolInterpController* clone, CloningProcess& process);
    void SetBoolInterpolatorValue(NiInterpolator* interpolator, unsigned short index);
    NiBoolInterpolator* LinkObject(NiStream* stream);
};
