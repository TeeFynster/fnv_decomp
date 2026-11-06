#pragma once

#include "NiBlendInterpolator.h"

class NiBlendTransformInterpolator : public NiBlendInterpolator
{
  public:
    NiBlendTransformInterpolator() throw();
    virtual ~NiBlendTransformInterpolator() throw();

    virtual bool UpdateTransform(float fTime, NiObjectNET* pkObject, NiQuatTransform& kTransform);

    bool Update(float fTime, NiObjectNET* pkObject, NiQuatTransform& kTransform);
    bool UpdateAccumulatedTransform(float fTime, NiObjectNET* pkObject, NiQuatTransform& kTransform);
    bool UpdateSingleInterpolator(float fTime, NiObjectNET* pkObject, NiQuatTransform& kTransform);
    bool FUN_00a40b30(float time, NiObjectNET* object, NiQuatTransform& value);

};
