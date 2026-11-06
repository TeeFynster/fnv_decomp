#pragma once

#include "NiExtraDataController.h"
#include "NiFixedString.h"

class NiFloatsExtraDataPoint3Controller : public NiExtraDataController
{
public:
    virtual const NiRTTI* GetRTTI() const;
    virtual NiBlendInterpolator* GetBlendInterpolator(unsigned short index, bool managerControlled,
                                                     bool accumulateAnimations, float threshold, unsigned char size);

protected:
    virtual bool ControlsTransform(NiInterpolator* interpolator, unsigned short index) const;

public:
    int* __fastcall InitTimeController();

    static const NiRTTI ms_kRTTI;

    int m_iFloatsExtraDataIndex;
    NiFixedString m_kCtlrID;
};
