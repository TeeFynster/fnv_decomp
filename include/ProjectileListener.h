#pragma once

#include "bhkCharacterController.h"

class ProjectileListener : public bhkCharacterController
{
public:
    virtual ~ProjectileListener() throw();

    void FUN_00c876a0();

    int m4;
    int m8;
};
