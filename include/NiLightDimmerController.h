#pragma once

#include "NiFloatInterpController.h"

class NiLightDimmerController : public NiFloatInterpController
{
public:
    void GetLightDimmer(float& fValue);
};
