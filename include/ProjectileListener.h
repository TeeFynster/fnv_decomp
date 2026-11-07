#pragma once

#include "bhkCharacterController.h"

class ProjectileListener : public bhkCharacterController
{
public:
    virtual ~ProjectileListener() throw();

    void bhkSerializable_Kill();

    int m4;
    int m8;
};
