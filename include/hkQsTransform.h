#pragma once

#include <stddef.h>

// A matched unit can supply explicitly named local SIMD storage types without
// redefining the shared hkVector4/hkQuaternion names during header inclusion.
#ifndef FNV64_HKQSTRANSFORM_LOCAL_TYPES
__if_not_exists(hkVector4::m_vComponents)
{
#include "hkVector4.h"
}

__if_not_exists(hkQuaternion::getImag)
{
#include "hkQuaternion.h"
}

#endif

class hkTransform;
class hkBool;
class hkSimdReal;
typedef const hkSimdReal& hkSimdRealParameter;

struct hkQsTransform
{
public:
#ifdef FNV64_HKQSTRANSFORM_LOCAL_TYPES
    typedef FNV64_HKQSTRANSFORM_VECTOR_TYPE VectorStorage;
    typedef FNV64_HKQSTRANSFORM_QUATERNION_TYPE QuaternionStorage;
#else
    typedef hkVector4 VectorStorage;
    typedef hkQuaternion QuaternionStorage;
#endif

    VectorStorage m_vTranslation;
    __declspec(align(16)) QuaternionStorage m_rotation;
    VectorStorage m_vScale;

    hkQsTransform();
    hkQsTransform(const hkQsTransform& t);
    void operator=(const hkQsTransform& t);
    hkQsTransform& CopyFromFloatArray(const hkQsTransform& t);

    void SetFromTransform(const hkTransform& transform);
    void setFromTransformNoScale(const hkTransform& transform);

    void setIdentity();
    void SetConjugate(const hkQsTransform& t);
    void SetProduct(const hkQsTransform& a, const hkQsTransform& b);
    void setMulContext(const hkQsTransform& a, const hkQsTransform& b);
    void setRelativeContext(const hkQsTransform& a, const hkQsTransform& b);
    void setMulInitial(const hkQsTransform& a, const hkQsTransform& b);
    void setMulFirst(const hkQsTransform& a, const hkQsTransform& b);
    void SetMulInverse(const hkQsTransform& a, const hkQsTransform& b);
    void setInterpolate4(const hkQsTransform& a, const hkQsTransform& b, hkSimdRealParameter t);
    const VectorStorage& getTranslation() const;
    const QuaternionStorage& getRotation() const;
    void SetBodyOrientation(const QuaternionStorage& rotation);
    void set(const VectorStorage& t, const QuaternionStorage& r, const VectorStorage& s);
    // 0x00ce5120: translation, scale and rotation (either sign) all within epsilon of other
    hkBool ProcessAndReturnValue_00ce5120(const hkQsTransform& other, float epsilon) const;
};

typedef char hkQsTransform_size_check[(sizeof(hkQsTransform) == 48) ? 1 : -1];
typedef char hkQsTransform_translation_offset_check[(offsetof(hkQsTransform, m_vTranslation) == 0) ? 1 : -1];
typedef char hkQsTransform_rotation_offset_check[(offsetof(hkQsTransform, m_rotation) == 16) ? 1 : -1];
typedef char hkQsTransform_scale_offset_check[(offsetof(hkQsTransform, m_vScale) == 32) ? 1 : -1];
