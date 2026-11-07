#pragma once

#include "NiExtraData.h"
#include "NiColorA.h"

class NiColorExtraData : public NiExtraData
{
  public:
    virtual void SaveBinary(NiStream& kStream);

    void SaveBinary_00a893d0(NiStream& kStream);
    void SetColor(NiColorA kColor);

    NiColorA m_kFogTint;
};
