#pragma once

#include "bhkUnaryAction.h"

class bhkMouseSpringAction : public bhkUnaryAction
{
public:
    virtual ~bhkMouseSpringAction();

    void __thiscall FUN_00c86cb0();
    void* __thiscall FUN_004b5230(unsigned int);
    static NiObject* __cdecl CreateObject();
};
