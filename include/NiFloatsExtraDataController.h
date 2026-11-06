#pragma once

#include "NiExtraDataController.h"
#include "NiFixedString.h"

class NiFloatsExtraDataController : public NiExtraDataController
{
public:
    virtual bool IsEqual(NiObject* object) const;

    void ApplyInterpolatorValue(NiInterpolator* interpolator, unsigned short index);

    int m_iFloatsExtraDataIndex;
    NiFixedString m_kCtlrID;
};
