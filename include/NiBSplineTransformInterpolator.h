#pragma once

#include "NiBSplineInterpolator.h"
#include "NiQuatTransform.h"

class NiBSplineTransformInterpolator : public NiBSplineInterpolator
{
public:
    virtual void LoadBinary(NiStream& stream);

    void CopyUnknownFields(NiBSplineTransformInterpolator* interpolator, CloningProcess& cloning);

    NiQuatTransform m_kDefaultTransform;
    unsigned int m_kTransCPHandle;
    unsigned int m_kRotCPHandle;
    unsigned int m_kScaleCPHandle;
};
