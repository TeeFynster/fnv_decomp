#pragma once

#include "BSExtraData.h"

class ReferenceLightData;

class __declspec(align(8)) ExtraLight : public BSExtraData
{
public:
    virtual ~ExtraLight();

    ReferenceLightData* apTargetLight;
};
