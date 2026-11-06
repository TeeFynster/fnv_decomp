#pragma once

#include <cstddef>

struct ContactPointPair;

class hkpCdPointCollector
{
public:
    hkpCdPointCollector();
    virtual ~hkpCdPointCollector() throw();
    virtual void AddCdPoint(const ContactPointPair& point) = 0;
    virtual void reset();

    float getEarlyOutDistance() const;
    static void* __cdecl operator new(std::size_t nbytes);

    float m_fEarlyOutDistance;
};
