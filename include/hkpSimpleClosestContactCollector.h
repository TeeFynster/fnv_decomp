#pragma once

#include "hkpCdPointCollector.h"
#include "Contact228.h"

class hkpSimpleClosestContactCollector : public hkpCdPointCollector
{
public:
    hkpSimpleClosestContactCollector();
    virtual ~hkpSimpleClosestContactCollector();
    virtual void AddCdPoint(const ContactPointPair& point);
    virtual void reset();

    void addContactPoint(const Contact228& point);
    void Reset();

    unsigned char m_bOk;
    Contact228 contact;
};
