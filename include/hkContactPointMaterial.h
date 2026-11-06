#pragma once

#include <stddef.h>
#include "QuantizedFloat8.h"

struct ClassMemberDescriptor;

class hkContactPointMaterial
{
public:
    enum FlagEnum
    {
        CONTACT_IS_NEW = 1,
        CONTACT_USES_SOLVER_PATH2 = 2,
        CONTACT_BREAKOFF_OBJECT_ID = 4,
        CONTACT_IS_DISABLED = 8
    };

    unsigned int m_ulUserData;
    QuantizedFloat8 m_fSlipAngle;
    unsigned char m_fElasticity;
    QuantizedFloat8 m_usFlags;
    unsigned char m_flags;

    static const ClassMemberDescriptor Members[];

    hkContactPointMaterial();
    void reset();
    float getFriction() const;
    static void* __cdecl operator new(size_t nbytes);
};
