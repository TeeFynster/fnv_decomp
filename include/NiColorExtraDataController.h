#pragma once

#include "NiExtraDataController.h"
#include "NiColorExtraData.h"

class StrArr;

class NiColorExtraDataController : public NiExtraDataController
{
public:
    virtual void SetInterpolatorForTarget(NiInterpolator* interpolator, unsigned short index) override;

    void FUN_00a4fc90(NiInterpolator* pkInterp, unsigned short usIndex);
    void* FUN_00a4fb30(unsigned short usIndex);
    void AppendString(StrArr* pkStrings);

};
