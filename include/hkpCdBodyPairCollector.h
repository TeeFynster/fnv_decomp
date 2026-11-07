#pragma once

#include "hkpCdBody.h"

class hkpCdBodyPairCollector
{
public:
    hkpCdBodyPairCollector();

    virtual ~hkpCdBodyPairCollector();
    virtual void AddCdBodyPair(const hkpCdBody& bodyA, const hkpCdBody& bodyB);
    virtual void hkpCdBodyPairCollector_reset();

    void dtor();
    void* hkpCdBodyPairCollector_hkpCdBodyPairCollector();
    void* FUN_0062d3f0(unsigned int flags);
    void SetVirtualTable_0062d420();
};
