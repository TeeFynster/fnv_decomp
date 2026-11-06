#pragma once

#include "hkpCdPointCollector.h"

class hkpSymmetricAgentFlipCollector : public hkpCdPointCollector
{
public:
    virtual ~hkpSymmetricAgentFlipCollector();
    virtual void AddCdPoint(const ContactPointPair& point);

    void dispose();
    void collect(float value);
    void process(void* value);
    void unk00();

    void* unk08;
};
