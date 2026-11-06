#pragma once

#include "hkpCdBodyPairCollector.h"

class hkpFlagCdBodyPairCollector : public hkpCdBodyPairCollector
{
public:
    bool m_flag;

    hkpFlagCdBodyPairCollector();
    bool DidHit() const { return m_flag; }
};
