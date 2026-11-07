#pragma once

#include <stddef.h>

class NiStream;

class NiPoint2
{
public:
    union
    {
        struct
        {
            unsigned char last;
            unsigned char last2;
            unsigned char length;
            unsigned char first;
            unsigned int crc;
        };
        struct
        {
            float x;
            float y;
        };
        unsigned int data[2];
    };

    NiPoint2() {}
    NiPoint2(float x, float y);

    NiPoint2 operator+(const NiPoint2& point) const;
    NiPoint2 operator-(const NiPoint2& point) const;
    NiPoint2 operator*(float scalar) const;

    bool operator==(const NiPoint2& point) const
    {
        return x == point.x && y == point.y;
    }
// src: GUESS 0x0051c330 (confidence: low)
    __declspec(noinline) bool ForwardCall_0051c330(const NiPoint2& point) const
    {
        return !(*this == point);
    }
    bool HasEqualFloatPair(const NiPoint2& point) const;

    float Length();
    float SqrLength();
    float Dot(const NiPoint2& point);
    float Dot(void* point);
    float Unitize();
    float NormalizeXY();
    float NiPoint3_XYLength() const;
    NiPoint2& Scale(float scalar);
    NiPoint2& DivideBy(float scalar);
    NiPoint2 Subtract(const NiPoint2& point) const;

    void LoadBinary(NiStream* stream);
    void LoadBinary(NiStream& stream);
    void SaveBinary(NiStream* stream);
    char* FormatToBuffer(char* buffer);

    static NiPoint2 ComponentProduct(const NiPoint2& a, const NiPoint2& b);
    static NiPoint2 ComponentProduct(void* a, void* b);
    static void LoadBinary(NiStream* stream, NiPoint2* points, unsigned int count);
    static void SaveBinary(NiStream* stream, NiPoint2* points, unsigned int count);
    static void* operator new[](size_t size);
};
