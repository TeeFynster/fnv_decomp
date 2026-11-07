#pragma once

#include "NiExtraDataController.h"
#include "NiColorExtraData.h"

class StrArr;

class NiColorExtraDataController : public NiExtraDataController
{
public:
    virtual void SetInterpolatorForTarget(NiInterpolator* interpolator, unsigned short index) override;

    void SynchronizePoseInterpolator(NiInterpolator* pkInterp, unsigned short usIndex);
    void* CreatePoseInterpolator(unsigned short usIndex);
    void AppendString(StrArr* pkStrings);

};
