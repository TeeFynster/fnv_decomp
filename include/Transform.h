#pragma once

#if defined(FNV_TRANSFORM_NO_SSE)
__if_not_exists(__m128) { union __m128; }
#else
#include <xmmintrin.h>
#endif

class Src;
class ValidationResult;
class hkVector4;
class DisplayVectorCallLocal_00ddfd10;
class NiPoint3;
class NiPoint3;
struct NiPoint3;
class Quaternion;
class Matrix43;
class Matrix;
class Scalar;

#pragma pack(push, 4)

class Transform
{
public:
    struct Mat
    {
        float entries[3][3];

        void DecomposeToEulerAngles(float& x, float& y, float& z);
        void NiMatrix3_GetCol(unsigned int axis, NiPoint3& out);
        void FUN_004769c0(int axis, const NiPoint3& value);
        Mat FUN_004768c0();
        Mat FUN_0043f8d0(const Mat& other);
        NiPoint3 FUN_004b4500(const NiPoint3& value);
    };

    struct PlainVec
    {
        float x;
        float y;
        float z;
    };

    struct Translation
    {
        int unk00;
        int unk04;
        int unk08;
        int unk0c;

        void SetQuaternionComponentsFromVector(const void* source);
    };

#if defined(FNV_TRANSFORM_NO_SSE)
    struct Rows
    {
        float entries[16];

        __forceinline __m128& operator[](unsigned int index)
        {
            return *reinterpret_cast<__m128*>(entries + index * 4);
        }

        __forceinline const __m128& operator[](unsigned int index) const
        {
            return *reinterpret_cast<const __m128*>(entries + index * 4);
        }
    };

#endif

    union
    {
        struct
        {
            float m_f00;
            float m_f04;
            float m_f08;
            float m_f0c;
            float m_f10;
            float m_f14;
            float m_f18;
            float m_f1c;
            float m_f20;
            float m_f24;
            float m_f28;
            float m_f2c;
            float m_f30;
            float m_f34;
            float m_f38;
            float m_f3c;
        };
        struct
        {
            Mat rotation;
            PlainVec position;
            float scale;
        };
        struct
        {
            float unk00[12];
            Translation translation;
        };
#if defined(FNV_TRANSFORM_NO_SSE)
        Rows r;
#else
        __m128 r[4];
#endif
    };

    __forceinline Transform() {}
    Transform(const Transform& rhs);
    Transform(Src* apSrc);
    Transform(void* apFirst, void* apSecond);

    Transform& operator=(const Transform& rhs);
    Transform operator*(const Transform& rhs) const;
    Transform& Relative(Transform& out, const Transform& other);
    Matrix FUN_004b45b0() const;

    __forceinline operator const Matrix&() const
    {
        return *reinterpret_cast<const Matrix*>(&m_f00);
    }

    void Invert(Transform* out);

    const __m128& getTranslation() const;
    const __m128& getScale() const;
    void setIdentity();
    void SetConjugate(const Transform& source);
    void SetProduct(const Transform& a, const Transform& b);
    void interpolate(const Transform& a, const Transform& b, const Scalar& t);
    void setInverseAfter(const Transform& source);
    void setInverseFinal(const Transform& source);
    void setMulFinal(const Transform& a, const Transform& b);
    void setTranslation(const hkVector4& p);
    void setTranslation(const DisplayVectorCallLocal_00ddfd10& p);
    ValidationResult IsTransformValid(float tolerance);

    Transform* NiTransform_NiTransform();
    void FUN_004b4880(Transform* out);
    void FUN_004b4880(Transform& out);
    Transform* FUN_004b4880(Transform* out) const;
    NiPoint3* ComputeValue_00524c40(NiPoint3* out, const NiPoint3* point);
    NiPoint3* ComputeValue_00524c40(NiPoint3* out, const NiPoint3* point) const;
    void bhkTransform_setIdentity();
    Transform* FUN_0062c250(Transform* out, const Transform* other) const;
    Transform FUN_0062c250(const Transform& rhs) const;
    void FUN_008b42e0(Transform& out) const;
    void FUN_00c6cd60(const Transform& other);
    void FUN_00c6cd60(const Transform* other);
    void hkTransform_setMul(const Transform& a, const Transform& b);
    void hkTransform_setMul(const Transform* a, const Transform* b);
    void hkTransform_setMulInverseMul(Transform* a, Transform* b);
    void hkTransform_setMulInverseMul(const Transform& a, const Transform& b);
    void hkTransform_setMulInverseMul(const Transform* a, const Transform* b);
    void hkTransform_setMulInverseMul(void* a, void* b);
    void hkRotation_set(const Quaternion* rotation);
    void hkRotation_set(void* rotation);
    void hkRotation_renormalize();
    void setFromTransformNoScale(const Transform* other) throw();
    void BuildMatrixFromRotationScaleAndPosition(int value);
    void Object_ForwardCall_00ce5300(Matrix43* out);

    static const Transform& GetIdentityTransform();
};

#pragma pack(pop)
