#pragma once

#include "MobIterOperator.h"

class Actor;
class TESBoundObject;

class Reset3DMobIterator : public MobIterOperator
{
public:
    TESBoundObject* base;
    bool reset;

    Reset3DMobIterator();
    void Tesscriptfunctions_UpdateState_005d8b10();
    void FUN_006ecd40(int);
    virtual void Operate(MobileObject* mobile);
    void operator()(Actor* actor);
};
