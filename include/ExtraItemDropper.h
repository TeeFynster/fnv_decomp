#pragma once

#include "BSExtraData.h"

namespace extra_save
{
class SForm;
}

class ExtraItemDropper : public BSExtraData
{
public:
    extra_save::SForm* dropper;
};
