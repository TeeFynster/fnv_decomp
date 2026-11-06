#pragma once

#include "PosGen.h"

class SymGen : public PosGen
{
public:
    virtual ~SymGen();
    virtual float Next();
};
