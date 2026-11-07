#pragma once

#include "NiPoint3.h"

class P3
{
public:
    float x;
    float y;
    float z;

    __declspec(noalias) P3() throw();
    P3 operator*(float f) const;
    P3 operator+(const P3& rhs) const;
    P3 operator-(const P3& rhs) const;
    P3 Cross(const P3& rhs) const;
    bool Eq(const P3& rhs);
    float DotProduct(P3* rhs);
    P3 ApplyScaled(float scale);
    void Set(float fX, float fY, float fZ);
    float Length() const;
    float FUN_004a7290() const;

    __declspec(noalias) void Unitize_004a0c10();
    void FUN_006815c0();
    P3 SubtractIntoVector(P3* rhs);
    NiPoint3 SubtractIntoVector(const NiPoint3& rhs) const;
    P3* GetNegatedVector(P3* rhs);
};
