#pragma once

#include "NiBlendInterpolator.h"
#include "NiQuatTransform.h"

class AccumItem;
class NiObjectNET;

class NiBlendAccumTransformInterpolator : public NiBlendInterpolator
{
public:
    virtual bool vf59(NiQuatTransform* value);

    void ResetAccumulation();
    void UpdateAccumulation(float time, NiObjectNET* target);
    bool UpdateAccumulatedTransform(float time, NiObjectNET* target, NiQuatTransform& result);

    NiQuatTransform m_kAccumulatedTransform;
    AccumItem* m_pAccumulationData;
    bool m_bHasAccumulation;
};
