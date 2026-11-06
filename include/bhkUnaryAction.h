#pragma once

#include "bhkAction.h"

class hkpUnaryAction;

class bhkUnaryAction : public bhkAction
{
public:
    bhkUnaryAction();
    virtual ~bhkUnaryAction();
    virtual void vf49();

    void Set(float x, float y, float z, float w);
    void __thiscall FUN_00c86720();
    void FUN_00553f70(void*);
    void FUN_00c86940(hkpUnaryAction* action); // 0x00c86940: adds the Havok action to the world (body in globalfunc_o2_variant.cpp)

    unsigned int unk0C;
};
