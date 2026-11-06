#pragma once

#include "Tile__Action.h"

class Tile__FloatAction : public Tile__Action
{
public:
    float fValue;

    float GetStoredFloatValue();
};
