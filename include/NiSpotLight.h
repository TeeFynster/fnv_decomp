#pragma once

#include "NiPointLight.h"
#include "NiPoint3.h"

class NiSpotLight : public NiPointLight
{
  public:
    virtual bool IsEqual(NiObject* object) const;
    using NiPointLight::IsEqual;

    NiPoint3 m_kWorldDir;
    float m_f0108;
    float m_f010c;
    float m_f0110;
};
