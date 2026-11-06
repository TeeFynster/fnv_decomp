#pragma once

#include "BSExtraData.h"

class AlchemyItem;

class ExtraPoison : public BSExtraData
{
public:
    bool IsDifferent(BSExtraData* apCompare);

    AlchemyItem* poison;
};
