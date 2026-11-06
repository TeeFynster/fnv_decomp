#pragma once

#include "NiSingleInterpController.h"

class NiFloatInterpolator;

class NiFloatInterpController : public NiSingleInterpController
{
public:
    NiFloatInterpController();
    virtual ~NiFloatInterpController();

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
    virtual void UpdateFloatValue(float* value);

    void CopyMemberData(NiFloatInterpController* clone, CloningProcess* process);
    void SetInterpolatorValue(NiInterpolator* interpolator, unsigned short index);
    NiFloatInterpolator* CreateFadeNodeFromValue(unsigned short index);
    void Init();
    NiFloatInterpController& operator=(const NiFloatInterpController& other);

};
