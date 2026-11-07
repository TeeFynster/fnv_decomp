#pragma once

#include <stddef.h>
#include "hkBool.h"
#include "hkVector4.h"

class hkRotation;
class hkSimdReal;
enum hkResult;

class hkMatrix3
{
public:
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;

#ifndef FNV64_HKMATRIX3_TRIVIAL_DEFAULT
    hkMatrix3();
#endif
    __forceinline hkVector4& getColumn(int i);
    __forceinline const hkVector4& getColumn(int i) const;
    float& operator()(int row, int col);
    const float& operator()(int row, int col) const;
#ifndef FNV64_HKMATRIX3_TRIVIAL_DEFAULT
    void operator=(const hkMatrix3& a);
#endif

    void setCols(const hkVector4& r0, const hkVector4& r1, const hkVector4& r2);
    void setZero();
    void setIdentity();
    void SetDiagonalElements(const hkVector4& r) throw();
    void transpose() throw();
    void _setTranspose(const hkMatrix3& s);
    void SetProduct(const hkMatrix3& a, const hkMatrix3& b) throw();
    void setMul2(const hkMatrix3& a, const hkMatrix3& b);
    void _setMul(const hkMatrix3& aTb, const hkMatrix3& bTc);
    void add(const hkMatrix3& a);
    void addTo(hkMatrix3& dst) const;
    void addMul(const hkSimdReal& scale, const hkMatrix3& a) throw();
    void sub(const hkMatrix3& a) throw();
    void _sub(const hkMatrix3& a);
    void Multiply(const hkSimdReal& s);
    void SetFromRotation(const hkRotation& t) throw();
    hkSimdReal GetDeterminant() throw();
    hkResult DiagonalizeSymmetric(hkMatrix3& eigenVec, hkVector4& eigenVal,
                                 int maxIter = 5, float epsilon = 1e-4f) const throw();

    int invert_00cd4f10(float epsilon);
    void __thiscall SetTransposeProduct(char* a, char* b);
    hkBool isOk_00cd4af0() const;
    unsigned char* CompareMatrixColumnsWithinTolerance(unsigned char* result, const hkMatrix3* other, float epsilon);
    bool hkMatrix3_isSymmetric(float epsilon);
    void ComputeInverseWithDeterminantThreshold();
    float _offDiagNorm();
    void hkMatrix3f_mul(const hkMatrix3& other);

    static void* __cdecl operator new(size_t nbytes);
    static const hkMatrix3& __cdecl GetIdentityTransform() throw();
    // Scalar access spellings for the padded 3x4 matrix used by inertia helpers.
    __forceinline float get_m00() const { return m_kColumn0.m_f[0]; }
    __forceinline void set_m00(float value) { m_kColumn0.m_f[0] = value; }
    __declspec(property(get=get_m00, put=set_m00)) float m00;
    __forceinline float get_m01() const { return m_kColumn0.m_f[1]; }
    __forceinline void set_m01(float value) { m_kColumn0.m_f[1] = value; }
    __declspec(property(get=get_m01, put=set_m01)) float m01;
    __forceinline float get_m02() const { return m_kColumn0.m_f[2]; }
    __forceinline void set_m02(float value) { m_kColumn0.m_f[2] = value; }
    __declspec(property(get=get_m02, put=set_m02)) float m02;
    __forceinline float get_m03() const { return m_kColumn0.m_f[3]; }
    __forceinline void set_m03(float value) { m_kColumn0.m_f[3] = value; }
    __declspec(property(get=get_m03, put=set_m03)) float m03;
    __forceinline float get_m10() const { return m_kColumn1.m_f[0]; }
    __forceinline void set_m10(float value) { m_kColumn1.m_f[0] = value; }
    __declspec(property(get=get_m10, put=set_m10)) float m10;
    __forceinline float get_m11() const { return m_kColumn1.m_f[1]; }
    __forceinline void set_m11(float value) { m_kColumn1.m_f[1] = value; }
    __declspec(property(get=get_m11, put=set_m11)) float m11;
    __forceinline float get_m12() const { return m_kColumn1.m_f[2]; }
    __forceinline void set_m12(float value) { m_kColumn1.m_f[2] = value; }
    __declspec(property(get=get_m12, put=set_m12)) float m12;
    __forceinline float get_m13() const { return m_kColumn1.m_f[3]; }
    __forceinline void set_m13(float value) { m_kColumn1.m_f[3] = value; }
    __declspec(property(get=get_m13, put=set_m13)) float m13;
    __forceinline float get_m20() const { return m_kColumn2.m_f[0]; }
    __forceinline void set_m20(float value) { m_kColumn2.m_f[0] = value; }
    __declspec(property(get=get_m20, put=set_m20)) float m20;
    __forceinline float get_m21() const { return m_kColumn2.m_f[1]; }
    __forceinline void set_m21(float value) { m_kColumn2.m_f[1] = value; }
    __declspec(property(get=get_m21, put=set_m21)) float m21;
    __forceinline float get_m22() const { return m_kColumn2.m_f[2]; }
    __forceinline void set_m22(float value) { m_kColumn2.m_f[2] = value; }
    __declspec(property(get=get_m22, put=set_m22)) float m22;
    __forceinline float get_m23() const { return m_kColumn2.m_f[3]; }
    __forceinline void set_m23(float value) { m_kColumn2.m_f[3] = value; }
    __declspec(property(get=get_m23, put=set_m23)) float m23;
};

typedef char hkMatrix3_size_check[(sizeof(hkMatrix3) == 48) ? 1 : -1];
typedef char hkMatrix3_column0_offset_check[(offsetof(hkMatrix3, m_kColumn0) == 0) ? 1 : -1];
typedef char hkMatrix3_column1_offset_check[(offsetof(hkMatrix3, m_kColumn1) == 16) ? 1 : -1];
typedef char hkMatrix3_column2_offset_check[(offsetof(hkMatrix3, m_kColumn2) == 32) ? 1 : -1];
