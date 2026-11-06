#pragma once

#include "ImageSpaceModifierInstance.h"

class ImageSpaceModifierInstanceTemp : public ImageSpaceModifierInstance
{
  public:
    ImageSpaceModifierInstanceTemp(float, float, NiAVObject*, float);
    virtual ~ImageSpaceModifierInstanceTemp();

    void DestroyMembers();
    bool IsExpired();

    float fDuration;
};
