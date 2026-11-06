#pragma once

#include "BSExtraData.h"
#include "SL.h"

class ExtraActivateRefChildren : public BSExtraData
{
public:
    virtual ~ExtraActivateRefChildren();

    ExtraActivateRefChildren();

    void __thiscall FUN_00433830();
    void* __thiscall FUN_00433800(unsigned int flags);

    SL m;
    float f;
};
