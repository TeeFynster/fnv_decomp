#pragma once

#include <stddef.h>
#include <xmmintrin.h>

class hkBool;
class hkVector4;
class hkRotation;
class hkQuaternion;

class __declspec(align(16)) hkTransform
{
public:
    union
    {
        __m128 m_kColumn0;
        float unk00;
    };
    union
    {
        __m128 m_kColumn1;
        float unk10;
    };
    union
    {
        __m128 m_kColumn2;
        float unk20;
    };
    union
    {
        __m128 m_vTranslation;
        float unk30;
    };

    __forceinline __m128& getRow0() { return m_kColumn0; }
    __forceinline const __m128& getRow0() const { return m_kColumn0; }
    __forceinline void setRow0(__m128 value) { m_kColumn0 = value; }
    __forceinline __m128& getRow1() { return m_kColumn1; }
    __forceinline const __m128& getRow1() const { return m_kColumn1; }
    __forceinline void setRow1(__m128 value) { m_kColumn1 = value; }
    __forceinline __m128& getRow2() { return m_kColumn2; }
    __forceinline const __m128& getRow2() const { return m_kColumn2; }
    __forceinline void setRow2(__m128 value) { m_kColumn2 = value; }
    __forceinline __m128& getRow3() { return m_vTranslation; }
    __forceinline const __m128& getRow3() const { return m_vTranslation; }
    __forceinline void setRow3(__m128 value) { m_vTranslation = value; }

    __declspec(property(get = getRow0, put = setRow0)) __m128 m_row0;
    __declspec(property(get = getRow1, put = setRow1)) __m128 m_row1;
    __declspec(property(get = getRow2, put = setRow2)) __m128 m_row2;
    __declspec(property(get = getRow3, put = setRow3)) __m128 m_row3;
    __declspec(property(get = getRow3, put = setRow3)) __m128 m_kColumn3;

    __forceinline hkRotation& getRotationMember() { return reinterpret_cast<hkRotation&>(m_kColumn0); }
    __forceinline const hkRotation& getRotationMember() const { return reinterpret_cast<const hkRotation&>(m_kColumn0); }
    __declspec(property(get = getRotationMember)) hkRotation m_rotation;

    __forceinline hkVector4& getPositionMember() { return reinterpret_cast<hkVector4&>(m_vTranslation); }
    __forceinline const hkVector4& getPositionMember() const { return reinterpret_cast<const hkVector4&>(m_vTranslation); }
    __forceinline void setPositionMember(const hkVector4& value) { m_vTranslation = reinterpret_cast<const __m128&>(value); }
    __declspec(property(get = getPositionMember, put = setPositionMember)) hkVector4 position;
    hkTransform();
    hkTransform(const hkQuaternion& rotation, const hkVector4& translation); // exe: 0x0062aae0
    hkTransform(const hkTransform& transform);
    void operator=(const hkTransform& transform);

    hkRotation& getRotation();
    const hkRotation& getRotation() const;
    hkVector4& getTranslation();
    const hkVector4& getTranslation() const;
    const hkVector4& getColumn(int index) const;

    void setIdentity();
    void setTranslation(const hkVector4& translation);
    void SetBodyOrientation(const hkRotation& rotation);
    void SetBodyOrientation(const hkQuaternion& rotation);
    void SetConjugate(const hkTransform& transform);
    void SetProduct(const hkTransform& a, const hkTransform& b);
    void SetMulInverse(const hkTransform& a, const hkTransform& b);
    hkBool IsEqualWithinTolerance(const hkTransform& other, float epsilon) const;
    void hkTransform_setMul(const hkTransform& a, const hkTransform& b);
    void hkTransform_setMulInverseMul(const hkTransform& a, const hkTransform& b);
    void hkTransform_setMulInverseMul(const void* a, const void* b);
    void ProcessTransformedMatrixCopy_00cb23e0(const hkTransform& transform);
    void bhkRigidBodyCinfo_SetPosition(const hkVector4& vector);

    static void* __cdecl operator new(size_t nbytes);
    static const hkTransform& __cdecl GetIdentityTransform();
    static const hkTransform s_identity;
};
