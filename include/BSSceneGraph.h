#pragma once

#include "NiNode.h"

class BSSceneGraph : public NiNode
{
  public:
    virtual const NiRTTI* GetRTTI() const;
    virtual void vf64();
    virtual void vf65();
};
