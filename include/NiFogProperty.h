#pragma once

#include "NiProperty.h"
#include "NiColor.h"

class NiFogProperty : public NiProperty
{
  public:
    NiFogProperty();
    virtual ~NiFogProperty();

    void SetColor(const NiColor& color);

    unsigned short m_uiObjectFlags;
    float m_fFogDepth;
    NiColor m_kFogTint;
};
