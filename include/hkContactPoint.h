#pragma once

#include <stddef.h>
// Define this when a complete local hkVector4 definition precedes this header.
#ifndef FNV64_HKCONTACTPOINT_USE_LOCAL_HKVECTOR4
#include "hkVector4.h"
#endif

struct ClassMemberDescriptor;

class hkContactPoint
{
public:
    hkVector4 m_vContactPosition;
    hkVector4 m_vSeparatingNormal;

    static const ClassMemberDescriptor Members[];

    hkVector4& getPosition();
    const hkVector4& getPosition() const;
    const hkVector4& getNormal() const;
    hkVector4& getSeparatingNormal();
    const hkVector4& getSeparatingNormal() const;
    float getDistance() const;

    void setSeparatingNormal(const hkVector4& separatingNormal);
    void setSeparatingNormal(const hkVector4& normal, float dist);
    void setNormal(const hkVector4& normal);
    void setDistance(float d);
    void setFlipped(const hkContactPoint& point);
    void flip();
    hkContactPoint& operator=(const hkContactPoint& other);

    static void* __cdecl operator new(size_t nbytes);
};
