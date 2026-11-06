#pragma once

#include "NiPoint3.h"
#include "NiPoint3.h"
#include "NiPoint3.h"
#include "Vec4.h"

class Pt;

class Mat3
{
public:
    float m00;
    float m01;
    float m02;
    float m10;
    float m11;
    float m12;
    float m20;
    float m21;
    float m22;

    Mat3();
    Mat3(const NiPoint3& c0, const NiPoint3& c1, const NiPoint3& c2);

    Vec4& getColumn(int i);
    const Vec4& getColumn(int i) const;
    float& operator()(int r, int c);
    const float& operator()(int r, int c) const;
    void setZero();
    void setDiagonal(float a, float b, float c);
    void _setTranspose(const Mat3& source);

    NiPoint3 RotateCaptured(const NiPoint3& v, const float& cachedm01,
                        const float& cachedm02, const float& cachedm10) const;
    NiPoint3 InverseRotate(const float& vx, const float& vy, const float& vz) const;
    NiPoint3 operator*(const NiPoint3& point) const;
    Mat3 operator*(float scale) const;
    Mat3 operator+(const Mat3& other) const;
    Mat3 operator-(const Mat3& other) const;
    Mat3 operator*(const Mat3& other) const;
    Mat3 Multiply(const Mat3& rhs) const;

    void SetZRotation(float angle);
    void SetXRotation(float angle);
    void FromAngles(float a, float b, float c);
    void GetCol(unsigned int col, NiPoint3& out) const;
    void GetColumn(unsigned int col, NiPoint3& out) const;
    void SetRow(unsigned int row, const Pt& value);

    Mat3 FUN_0043f8d0(const Mat3& other);
    Mat3* FUN_0043f8d0(Mat3* result, Mat3* input);
    void FUN_004a0c90(float angle);
    __declspec(noalias) NiPoint3 FUN_004b4500(const NiPoint3& point) const;
    __declspec(noalias) NiPoint3 FUN_004b4500(const NiPoint3* point) const;
    void FUN_00cd5880(const void* rotation);

    static const Mat3 IDENTITY;
};
