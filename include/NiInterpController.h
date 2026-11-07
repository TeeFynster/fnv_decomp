#pragma once

#include "NiTimeController.h"
#include "NiFixedString.h"
#include "NiInterpolator.h"

class NiBlendInterpolator;

class NiInterpController : public NiTimeController
{
public:
    NiInterpController() throw();
    virtual ~NiInterpController() throw();

    virtual void LinkObject(NiStream& stream);
    virtual void LoadBinary(NiStream& stream);

    virtual unsigned short GetTargetCount() const;
    virtual const char* GetTargetName(unsigned short index) const;
    virtual unsigned short GetTargetIndex(const char* id) const;
    virtual unsigned short GetTargetIndex(const NiFixedString& id) const;
    virtual NiInterpolator* GetInterpolator(unsigned short index) const;
    virtual void SetInterpolator(NiInterpolator* interpolator, unsigned short index);
    virtual void AdvanceControllerTime();
    virtual const char* GetControllerID() const;
    virtual NiInterpolator* GetInterpolatorAtIndex(unsigned short index);
    virtual void SetInterpolatorForTarget(NiInterpolator* interpolator, unsigned short index);
    virtual NiBlendInterpolator* GetBlendInterpolator(unsigned short index, bool managerControlled,
                                                     bool accumulateAnimations, float threshold, unsigned char size);
    virtual void SetActiveTimeRange(float startTime, float endTime);
    virtual bool ControlsTransform(NiInterpolator* interpolator, unsigned short index) const;

    void CopyMemberData(NiInterpController* pkClone, CloningProcess& kCloning);
    void NiMultiTargetTransformController_RemoveNodeRecurse(NiAVObject* object);

    static const unsigned short INVALID_INDEX;
};
