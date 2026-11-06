#pragma once

#include "BSExtraData.h"
#include "MagicCaster.h"

class NonActorMagicCaster : public BSExtraData, public MagicCaster
{
public:
    void SetSelectedMagicItem(MagicItem* spell);
};
