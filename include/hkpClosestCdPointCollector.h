#pragma once

#include "hkpCdPointCollector.h"
#include "hkContactPoint.h"
#include "hkpRootCdPoint.h"

class hkpClosestCdPointCollector : public hkpCdPointCollector
{
public:
    hkpClosestCdPointCollector();
    virtual ~hkpClosestCdPointCollector();
    virtual void AddCdPoint(const ContactPointPair& point);
    virtual void reset();

    bool DidHit() const;

    int unk08;
    int unk0C;
    hkpRootCdPoint m_kHitPoint;
    hkpRootCdPoint m_unweldedHitPoint;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
};
