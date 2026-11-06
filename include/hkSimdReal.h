#pragma once

#include <crtdefs.h>
#include <mmintrin.h>
#include <malloc.h>

__if_not_exists(__m128)
{
#include <xmmintrin.h>
}

// src: HAVOK_SRC (name); existing decompiled scalar packet declarations.
class hkSimdReal
{
public:
    union
    {
        struct
        {
            float x;
            float y;
            float z;
            float w;
        };
        __m128 m_vValue;
        __m128 v;
        __m128 value;
        __m128 m;
    };

    hkSimdReal();
    hkSimdReal(float value);
    hkSimdReal(const __m128& value);

    template <typename T>
    hkSimdReal operator+(const T& value) const;
    operator float() const;
    __m128& q();
    const __m128& q() const;
    const __m128& getQuad() const;
    __m128 broadcast() const;
    float getReal() const;
    float storeInto(float& scalar) const;
    void FUN_005dbf20(float value);
};
