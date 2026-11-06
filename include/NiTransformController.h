#pragma once

#include "NiSingleInterpController.h"

class NiTransformController : public NiSingleInterpController
{
public:
    NiTransformController();
    virtual ~NiTransformController();

    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& process);
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual bool RegisterStreamables(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool IsEqual(NiObject* object) const;
    virtual void GetViewerStrings(NiViewerStringsArray* strings);
    virtual void Update(NiUpdateData& update);
    virtual NiInterpolator* GetInterpolatorAtIndex(unsigned short index);
    virtual void SetInterpolatorForTarget(NiInterpolator* interpolator, unsigned short index);
    virtual NiBlendInterpolator* GetBlendInterpolator(unsigned short index, bool managerControlled,
                                                     bool accumulateAnimations, float threshold, unsigned char size);
    virtual bool TargetIsRequired(NiObjectNET* target) const;
    virtual bool ControlsTransform(NiInterpolator* interpolator, unsigned short index) const;

    void CopyMemberData(NiTransformController* clone, CloningProcess& process);
    void CopyMemberData(NiTransformController* clone, void* process);
    bool IsTargetOfType(NiObjectNET* target) const;
};
