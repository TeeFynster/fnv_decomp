#pragma once

#include "NiBSplineTransformInterpolator.h"

class NiBSplineCompTransformInterpolator : public NiBSplineTransformInterpolator
{
public:
    virtual void LoadBinary(NiStream& stream);
    virtual bool UpdateTransform(float time, NiObjectNET* target, NiQuatTransform& value);

    void CopyMemberData(NiBSplineCompTransformInterpolator* destination, CloningProcess& cloningProcess);
    bool Update(float time, NiObjectNET* target, NiQuatTransform& value);

    float m_afOffsetAndHalfRange[6];
};
