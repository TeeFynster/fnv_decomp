
// src/havok/physics/dynamics/motion/rigid/hkpspheremotion.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/motion/rigid/hkpspheremotion.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Keep the unit's intrinsic representation: the CRT __m128 adds byte arrays
// that change MSVC 2008 /GS parameter handling in the SIMD motion methods.
// Exe 0x00d1e410 ApplyImpulse: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;

extern "C" LocalM128 _mm_mul_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_add_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_sub_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_add_ss(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128 a, LocalM128 b, unsigned int imm);
extern "C" void _mm_store_ss(float* p, LocalM128 a);
extern "C" LocalM128 _mm_setzero_ps();
extern "C" void _mm_store_ps(float* p, LocalM128 a);

#include "../../../../../../include/hkBaseObject.h"
#include "../../../../../../include/hkReferencedObject.h"
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkMatrix3.h"
#include "../../../../../../include/hkSimdReal.h"
#include "../../../../../../include/hkpMotion.h"
#include "../../../../../../include/hkpSphereMotion.h"

// Retained locally: include/hkpSphereMotion.h declares only a constructor,
// and lacks these eight sphere-motion methods (0x00d1e1d0 through 0x00d1e5a0).

inline hkSimdReal::hkSimdReal(const LocalM128& value) : m_vValue(value) {}

inline hkSimdReal::operator float() const
{
    float scalar;
    _mm_store_ss(&scalar, m_vValue);
    return scalar;
}

template <typename T>
inline hkSimdReal hkSimdReal::operator+(const T& value) const
{
    return _mm_add_ss(m_vValue, value.m_vValue);
}

inline hkSimdReal hkVector4::getSimdAt3() const
{
    return _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
}

inline void hkVector4::setMul4(const hkSimdReal& scalar, const hkVector4& vector)
{
    m_vComponents = _mm_mul_ps(_mm_shuffle_ps(scalar.m_vValue, scalar.m_vValue, 0), vector.m_vComponents);
}

inline void hkVector4::setCross(const hkVector4& a, const hkVector4& b)
{
    const LocalM128 cross0 = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xc9),
                                    _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xd2));
    const LocalM128 cross1 = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xd2),
                                    _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xc9));
    m_vComponents = _mm_sub_ps(cross0, cross1);
}

__forceinline hkSimdReal hkVector4::dot3(const hkVector4& vector) const
{
    const LocalM128 product = _mm_mul_ps(m_vComponents, vector.m_vComponents);
    const LocalM128 sum = _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);
    return _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), sum);
}

inline hkSimdReal hkVector4::lengthSquared3() const
{
    return dot3(*this);
}

inline const float& hkVector4::operator()(int index) const
{
    return reinterpret_cast<const float*>(&m_vComponents)[index];
}

template <class T> inline T hkMax2(T x, T y)
{
    return x > y ? x : y;
}

// Stores the reciprocal of the largest diagonal inertia component into m_kInertiaAndMassInv for the sphere motion.
// @fnv 0x00d1e290
// src: HAVOK_SRC 0x00d1e290
void hkpSphereMotion::setInertiaLocal(const hkMatrix3& inertia)
{
    float a = hkMax2(hkMax2(inertia.m_kColumn0.x, inertia.m_kColumn1.y), inertia.m_kColumn2.z);
    float fInvMaxDiag;
    if (a > 0.0f)
        fInvMaxDiag = 1.0f / a;
    else
        fInvMaxDiag = 0.0f;
    m_kInertiaAndMassInv.x = fInvMaxDiag;
    m_kInertiaAndMassInv.y = fInvMaxDiag;
    m_kInertiaAndMassInv.z = fInvMaxDiag;
}

// Computes the minimum of param_2[0], param_2[5] and param_2[10] and stores it in m_kInertiaAndMassInv x, y and z.
// @fnv 0x00d1e320
void hkpSphereMotion::SetInertiaAndMassInv(const float* param_2)
{
    float v0 = param_2[0];
    float v5 = param_2[5];

    float minVal;
    if (v0 < v5)
    {
        minVal = v0;
    }
    else
    {
        minVal = v5;
    }

    float v10 = param_2[10];

    float result;
    if (minVal < v10)
    {
        result = minVal;
    }
    else
    {
        result = v10;
    }

    this->m_kInertiaAndMassInv.x = result;
    this->m_kInertiaAndMassInv.y = result;
    this->m_kInertiaAndMassInv.z = result;
}

// Adds impulse times inverse mass to translational velocity and (pos - center of mass) cross impulse times inverse inertia to angular velocity.
// @fnv 0x00d1e410
void hkpSphereMotion::ApplyImpulse(const hkVector4& kImpulse, const hkVector4& kPos)
{
    hkVector4 kDeltaLin;
    kDeltaLin.setMul4(m_kInertiaAndMassInv.getSimdAt3(), kImpulse);
    m_kTranslationalVelocity.add4(kDeltaLin);

    hkVector4 kRelPos;
    kRelPos.setSub4(kPos, m_kMotionState.m_kSweptTransform.m_vCenterOfMass1);
    hkVector4 kAngImpulse;
    kAngImpulse.setCross(kRelPos, kImpulse);
    hkVector4 kDeltaAng;
    kDeltaAng.setMul4(kAngImpulse, m_kInertiaAndMassInv);
    m_kAngularVelocity.add4(kDeltaAng);
}

// Multiplies m_kInertiaAndMassInv by imp into a temporary, adds it to m_kAngularVelocity, and returns imp.
// @fnv 0x00d1e4a0
const hkVector4& hkpSphereMotion::AddAngularImpulse(const hkVector4& imp)
{
    hkVector4 dangVel;
    dangVel.setMul4(m_kInertiaAndMassInv, imp);
    m_kAngularVelocity.add4(dangVel);
    return imp;
}

// Computes velocity along kNormal at kPos from angular and translational velocity, and an inverse virtual mass from the inertia, mass inverse and cross term.
// @fnv 0x00d1e5a0
void hkpSphereMotion::ComputeVelocityAndInverseVirtualMass(const hkVector4& kPos,
                                                        const hkVector4& kNormal, float& fVelOut,
                                                        float& fInvVirtMassOut) const
{
    hkVector4 kArm;
    kArm.setSub4(kPos, m_kMotionState.m_kSweptTransform.m_vCenterOfMass1);
    hkVector4 kRel;
    kRel.setCross(kNormal, kArm);
    fVelOut = m_kAngularVelocity.dot3(kRel) + m_kTranslationalVelocity.dot3(kNormal);
    fInvVirtMassOut = m_kInertiaAndMassInv(0) * kRel.lengthSquared3() + m_kInertiaAndMassInv(3);
}

extern double DAT_010c9300;
extern float DAT_0104da4c;

// Reads m_kInertiaAndMassInv.x (replaced by DAT_0104da4c if below DAT_010c9300) and writes a matrix at out with its reciprocal on the diagonal, zeros elsewhere.
// @fnv 0x00d1e1d0
// src: HAVOK_SRC 0x00d1e1d0
void hkpSphereMotion::getInertiaLocal(int out)
{
    hkReal x = m_kInertiaAndMassInv.x;
    hkReal y = (double)x < DAT_010c9300 ? DAT_0104da4c : x;
    hkMatrix3* p0 = (hkMatrix3*)(*(volatile int*)&out);
    float* p = reinterpret_cast<float*>(p0);
    hkReal inv = 1.0f / y;
    _mm_store_ps(p, _mm_setzero_ps());
    _mm_store_ps(p + 4, _mm_setzero_ps());
    _mm_store_ps(p + 8, _mm_setzero_ps());
    p[0] = inv;
    p[5] = inv;
    p[10] = inv;
}

// Writes a diagonal hkMatrix3 with m_kInertiaAndMassInv.x on the diagonal and zeros elsewhere into out.
// @fnv 0x00d1e3d0
// src: GUESS 0x00d1e390 (confidence: medium)
void hkpSphereMotion::GetDiagonalInverseInertia(hkMatrix3* out) const
{
    float inverse = m_kInertiaAndMassInv.x;
    LocalM128 zero = _mm_setzero_ps();
    LocalM128* columns = reinterpret_cast<LocalM128*>(out);
    columns[0] = zero;
    columns[1] = zero;
    columns[2] = zero;
    volatile hkMatrix3* diagonal = out;
    diagonal->m_kColumn0.x = inverse;
    diagonal->m_kColumn1.y = inverse;
    diagonal->m_kColumn2.z = inverse;
}

// Zeroes the 3x3 matrix and sets its diagonal entries to the scalar m_kInertiaAndMassInv.x value.
// @fnv 0x00d1e390
// src: GUESS 0x00d1e3d0 (confidence: medium)
void hkpSphereMotion::GetDiagonalInverseInertia_00d1e3d0(hkMatrix3& inertiaInvOut)
{
    hkReal val = m_kInertiaAndMassInv.x;
    LocalM128 zero = _mm_setzero_ps();
    LocalM128* col = (LocalM128*)&inertiaInvOut;
    for (int i = 0; i < 3; ++i)
    {
        col[i] = zero;
    }
    inertiaInvOut.m_kColumn0.x = val;
    inertiaInvOut.m_kColumn1.y = val;
    inertiaInvOut.m_kColumn2.z = val;
}
