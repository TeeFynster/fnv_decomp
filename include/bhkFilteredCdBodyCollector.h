#pragma once

#include "hkpAllCdBodyPairCollector.h"

class bhkFilteredCdBodyCollector : public hkpAllCdBodyPairCollector
{
public:
    virtual ~bhkFilteredCdBodyCollector();
    virtual void vf03();
};
