#pragma once

#include <cstddef>
#include "FinishingFlag.h"
#include "hkpShape.h"

typedef signed char hkInt8;
typedef std::size_t hk_size_t;

class hkpMaterial
{
public:
    enum ResponseType
    {
        RESPONSE_INVALID = 0,
        RESPONSE_SIMPLE_CONTACT = 1,
        RESPONSE_REPORTING = 2,
        RESPONSE_NONE = 3,
        RESPONSE_MAX_ID = 4
    };

    hkEnum<ResponseType, hkInt8> m_eResponseType;
    char pad1[3];
    hkReal m_fSlipAngle;
    hkReal m_fElasticity;

    hkpMaterial(FinishingFlag flag);
    static void* __cdecl operator new(hk_size_t nbytes);
};
