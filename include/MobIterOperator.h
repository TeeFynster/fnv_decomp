#pragma once

#include "BaseProcess.h"

class MobileObject;

class MobIterOperator
{
public:
    virtual void Operate(MobileObject* mobile);

    PROCESS_TYPE eType;
};
