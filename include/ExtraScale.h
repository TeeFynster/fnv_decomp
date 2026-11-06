#pragma once

#include "BSExtraData.h"

class ExtraScale : public BSExtraData
{
public:
    bool Compare(BSExtraData* apCompare) override;

    float fScale;
};
