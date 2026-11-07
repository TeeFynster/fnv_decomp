#pragma once

#include <stddef.h>

__if_not_exists(__m128) { union __m128; }

class hkRotation;
class hkVector4;
class IkVector4;
class hkVector4X;
class hkVector4H;

class hkQuaternion
{
public:
    int unk00;
    unsigned short unk04;
    unsigned short unk06;
    int unk08;
    unsigned short unk0c;
    unsigned char unk0e;
    unsigned char unk0f;

    hkQuaternion();
    hkQuaternion(const hkQuaternion& q);
    hkQuaternion(const hkVector4& axis, float angle);

    void operator=(const hkQuaternion& q);
    __forceinline void copyRotation(const hkQuaternion& q)
    {
        unk00 = q.unk00;
        *reinterpret_cast<unsigned int*>(&unk04) = *reinterpret_cast<const unsigned int*>(&q.unk04);
        unk08 = q.unk08;
        *reinterpret_cast<unsigned int*>(&unk0c) = *reinterpret_cast<const unsigned int*>(&q.unk0c);
    }
    const hkVector4& getImag() const;
    float getReal() const;
    float GetAngle();
    void normalize();
    void set(const hkRotation& rotation);
    void setInverseMul(const hkQuaternion& q0, const hkQuaternion& q1);
    void SetConjugate(const hkQuaternion& q);
    void SetProduct(const hkQuaternion& q0, const hkQuaternion& q1);

    void setMul(const hkQuaternion& q0, const hkQuaternion& q1);
    __declspec(noalias) void normalize_005611c0();
    void hkQuaternion_setAxisAngle(const hkVector4& axis, float angle);
    void hkQuaternion_setAxisAngle(const IkVector4& axis, float angle);
    void hkQuaternion_setAxisAngle(void* axis, float angle);
    void FUN_00cb26e0(int matrix);
    void FUN_00cb26e0(const __m128* matrix);
    void FUN_00cb26e0(const hkRotation& rotation);
    void hkQuaternion_decomposeRestAxis(const hkVector4& axis, hkQuaternion& restOut, float& angleOut) const;
    void hkQuaternion_decomposeRestAxis(void* axis, void* restOut, float* angleOut);
    void UpdateState_00cdb910(float gain, const IkVector4& from, const IkVector4& to);
    void setMulInverse(const hkQuaternion& q0, const hkQuaternion& q1);
    void setMulInverse(const void* a, const void* b) throw();
    void D3D_ComputeClearColor(const hkQuaternion& q0, const hkQuaternion& q1, float t);
    void UpdateFields_00d6bec0(const hkQuaternion& to, hkVector4& angleOut) const;
    void ComputeValues_00cd9d10(const hkVector4& from, const hkVector4& to);
    void hkQuaternion_setInverseMul(const hkQuaternion& a, const hkQuaternion& b);
    void removeAxisComponent(const hkVector4& v);

    static void* __cdecl operator new(size_t nbytes);
    static const hkQuaternion& __cdecl GetIdentityTransform();

protected:
    void setFlippedRotation(const hkVector4& from) throw();
    void setFlippedRotation(const hkVector4X& from);
    void setFlippedRotation(const hkVector4H& from);
};
