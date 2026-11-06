#pragma once

#include "hkBool.h"

typedef unsigned long hkPrimitiveId;
typedef float hkReal;

class hkKdTreeCastCollector
{
public:
    virtual ~hkKdTreeCastCollector();
    virtual hkBool ReportHit(hkPrimitiveId primId) = 0;
    virtual hkBool DidHit() = 0;
    virtual hkReal GetHitFraction() = 0;
};
