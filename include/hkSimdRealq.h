#pragma once

__if_not_exists(__m128)
{
#include <xmmintrin.h>
}

struct hkSimdRealq
{
public:
    __m128 m_vValue;

    __forceinline hkSimdRealq() {}
    __forceinline hkSimdRealq(const __m128& q)
    {
        m_vValue = q;
    }
};
