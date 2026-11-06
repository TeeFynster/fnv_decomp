#pragma once

#include "NiBlendInterpolator.h"

class BSBlendTreadTransfInterpolator : public NiBlendInterpolator
{
  public:
    virtual bool UpdateTransform(float, NiObjectNET*, NiQuatTransform&);
    virtual NiObject* MakeClone(CloningProcess&);

    bool Update(float, NiObjectNET*, NiQuatTransform&);
    bool UpdateSingleInterpolator(float, NiObjectNET*, NiQuatTransform&);
    bool UpdateAccumulatedTransform(float, NiObjectNET*, NiQuatTransform&);

    float m_fPhase;
};
