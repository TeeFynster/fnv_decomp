#pragma once

#include <cstddef>
#include "hkVector4_S.h"

typedef std::size_t hk_size_t;

class hkSphere
{
public:
    hkVector4_S m_pos;

    static void* __cdecl operator new(hk_size_t nbytes);
};
