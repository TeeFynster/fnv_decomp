#pragma once

#include "NiGeometry.h"

class NiParticles : public NiGeometry
{
  public:
    NiParticles();
    virtual ~NiParticles();
    virtual const NiRTTI* GetRTTI() const;
    virtual void CalculateConsistency(bool bTool);
};
