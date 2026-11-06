#pragma once

#include "hkpCdBody.h"

class hkpCdBodyPairCollector
{
public:
    hkpCdBodyPairCollector();

    virtual ~hkpCdBodyPairCollector();
    virtual void AddCdBodyPair(const hkpCdBody& bodyA, const hkpCdBody& bodyB);
    virtual void FUN_0062d330();

    void dtor();
    void* FUN_0062d3c0();
    void* FUN_0062d3f0(unsigned int flags);
    void FUN_0062d420();
};
