#pragma once

#include "hkpCdPointCollector.h"
class RootContactPoint;

class hkpFixedBufferCdPointCollector : public hkpCdPointCollector
{
public:
    hkpFixedBufferCdPointCollector(RootContactPoint* buffer, int capacity);
    virtual ~hkpFixedBufferCdPointCollector();
    virtual void AddCdPoint(const ContactPointPair& point);

    RootContactPoint* m_pPointBuffer;
    RootContactPoint* m_pPointBufferEnd;
    int m_pRayCursor;
    int m_iPointCount;
};
