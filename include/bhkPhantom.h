#pragma once

#include "bhkWorldObject.h"

class NiTransform;

class bhkPhantom : public bhkWorldObject
{
public:
    virtual ~bhkPhantom();

    void FUN_0056df20(const NiTransform&); // 0x0056df20
    void FUN_00623150(void*); // 0x00623150
    void* FUN_00c9f3b0();
    void* FUN_0056e420(unsigned int flags);
};
