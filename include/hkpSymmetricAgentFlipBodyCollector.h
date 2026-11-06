#pragma once

#include "hkpCdBodyPairCollector.h"

class hkpSymmetricAgentFlipBodyCollector : public hkpCdBodyPairCollector
{
public:
    void addBody();
    void reset();

    unsigned char unk04[4];
    void* payload;
};
