#pragma once

#include <xmmintrin.h>

class Scalar4;

#pragma pack(push, 4)

class V4
{
public:
#if defined(FNV_V4_UNALIGNED)
    struct Quad
    {
        float m128_f32[4];

        __forceinline operator __m128&()
        {
            return *reinterpret_cast<__m128*>(this);
        }

        __forceinline operator const __m128&() const
        {
            return *reinterpret_cast<const __m128*>(this);
        }

        __forceinline void operator=(const __m128& value)
        {
            *reinterpret_cast<__m128*>(this) = value;
        }
    };

#else
    typedef __m128 Quad;
#endif

    union V4Storage
    {
        Quad quad;
        union
        {
            Quad vector;
            unsigned char lanes[16];
        } storage;
    };

    union
    {
        Quad m;
        Quad q;
        V4Storage bits;
        struct
        {
            float x, y, z, w;
        };
        float f[4];
        struct
        {
            float f0, f1, f2, f3;
        };
    };

    V4();
    V4(const V4& other);
    V4(const __m128& value);
    V4(float a, float b, float c, float d);
    void operator=(const V4& other);
    float& operator()(int i);
    const float& operator()(int i) const;

    void setMul4(const V4& a, const V4& b);
    void setAdd4(const V4& a, const V4& b);
    void add4(const V4& a);
    void setCross(const V4& a, const V4& b);
    void setNeg4(const V4& a);
    void setReciprocal4(const V4& a);
    void scaled(const Scalar4& scale, const V4& other);
    Scalar4 laneY() const;
    Scalar4 laneZ() const;
    Scalar4 laneAt(int i) const;
    void add(const V4& other);
    void mul4(const V4& a);
    void mul4(__m128 s);
    void setMax4(const V4& a, const V4& b);
    __m128 getW() const;
    float horizontalAdd3() const;
    void setAdd(const V4& a, const V4& b);
    void setSub(const V4& a, const V4& b);
    void setMin(const V4& a, const V4& b);
    void sub(const V4& a);
    void abs(const __m128& mask);
    float lengthSquared3() const;
    void setZero4();
    void setZero();
};

#pragma pack(pop)
