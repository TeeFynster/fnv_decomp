
// src/havok/physics/dynamics/constraint/bilateral/ragdoll/hkpragdollconstraintdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/bilateral/ragdoll/hkpragdollconstraintdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Keep the original float-only intrinsic type: the CRT union adds byte arrays
// that make this compiler insert stack security checks into SIMD-only routines.
// Exe 0x00cdeae0 setInWorldSpace: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
} __m128, LocalM128;

#define _INCLUDED_MM2
#include "../../../../../../../include/Vec4.h"
#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../include/hkRotation.h"
#include "../../../../../../../include/hkMatrix3.h"
#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/hkTransform.h"
#include "../../../../../../../include/hkpConstraintAtom.h"
#include "../../../../../../../include/hkpConstraintData.h"
#include "../../../../../../../include/hkpSetLocalTransformsConstraintAtom.h"
#include "../../../../../../../include/hkpAngFrictionConstraintAtom.h"
#include "../../../../../../../include/hkpBallSocketConstraintAtom.h"
#include "../../../../../../../include/hkpRagdollConstraintDataAtoms.h"
#include "../../../../../../../include/hkpRagdollConstraintData.h"
#include "../../../../../../../include/hkpLimitedHingeConstraintDataAtoms.h"
#include "../../../../../../../include/hkUFloat8.h"

extern "C"
{
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_unpacklo_ps(LocalM128, LocalM128);
    LocalM128 _mm_unpackhi_ps(LocalM128, LocalM128);
    LocalM128 _mm_movelh_ps(LocalM128, LocalM128);
    LocalM128 _mm_movehl_ps(LocalM128, LocalM128);
    LocalM128 _mm_andnot_ps(LocalM128, LocalM128);
    LocalM128 _mm_setzero_ps(void);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_sub_ss(LocalM128, LocalM128);
    LocalM128 _mm_mul_ss(LocalM128, LocalM128);
    LocalM128 _mm_rsqrt_ss(LocalM128);
    LocalM128 _mm_cmpeq_ss(LocalM128, LocalM128);
    LocalM128 _mm_set_ss(float);
}

__forceinline LocalM128& Vec4::getQuad()
{
    return *reinterpret_cast<LocalM128*>(this);
}

__forceinline const LocalM128& Vec4::getQuad() const
{
    return *reinterpret_cast<const LocalM128*>(this);
}

extern "C" void _mm_store_ps(float*, LocalM128);

__forceinline void Vec4::setZero4()
{
    _mm_store_ps(&x, _mm_setzero_ps());
}

// The shared ragdoll declaration lacks setInWorldSpace/setInBodySpace and the frame getters.
// Keep this declaration until those methods are available in the approved header.

__forceinline hkpConstraintAtom::hkpConstraintAtom(FinishingFlag) {}
__forceinline hkpConstraintData::hkpConstraintData() throw() { m_ulUserData = 0; }
__forceinline hkpConstraintData::~hkpConstraintData() throw() {}
__forceinline hkTransform::hkTransform() {}
__forceinline void hkRotation::setIdentity()
{
    _mm_store_ps(&m_kColumn0.x, _mm_setzero_ps());
    _mm_store_ps(&m_kColumn1.x, _mm_setzero_ps());
    _mm_store_ps(&m_kColumn2.x, _mm_setzero_ps());
    m_kColumn0.x = 1.0f;
    m_kColumn1.y = 1.0f;
    m_kColumn2.z = 1.0f;
}
__forceinline void hkTransform::setIdentity()
{
    m_rotation.setIdentity();
    _mm_store_ps(reinterpret_cast<float*>(&m_vTranslation), _mm_setzero_ps());
}

// @fnv 0x00cde9d0
// src: HAVOK_LIB 0x00cde9d0
void __stdcall hkpRagdollConstraintData_getRuntimeInfo(int* apUnused, int* apiOut)
{
    apiOut[1] = 0xc;
    apiOut[0] = 0x80;
}

// @fnv 0x00cde980
void __thiscall hkpRagdollConstraintData::vf05(int aiBitIndex)
{
    m_kBridgeAtoms.m_kBallSocket.m_ucBodiesToNotify = (char)(1 << aiBitIndex);
}

// @fnv 0x00cde960
void __thiscall hkpRagdollConstraintData::vf03(float a)
{
    m_kBridgeAtoms.m_kBallSocket.m_usFlags = a;
}

void* __cdecl hkpConstraintData_getConstraintInfoUtil(void* a, int b, int c);

// @fnv 0x00cde9b0
char* hkpRagdollConstraintData::vf15(int aiIndex)
{
    return (char*)hkpConstraintData_getConstraintInfoUtil(&m_kBridgeAtoms, sizeof(m_kBridgeAtoms), aiIndex);
}

// @fnv 0x00cdf1f0
hkpRagdollConstraintData::~hkpRagdollConstraintData() throw()
{
    for (int i = 0; i < 3; ++i)
    {
        hkReferencedObject* p = reinterpret_cast<hkReferencedObject*>(m_kBridgeAtoms.m_kMotor.m_ppMotors[i]);
        if (p)
            p->removeReference();
    }
}

// @fnv 0x00cde970
float hkpRagdollConstraintData::vf04()
{
    return m_kBridgeAtoms.m_kBallSocket.m_usFlags;
}

// FUN_00cde9a0
//   movzx eax, byte ptr [ecx + 0x13a]
//   shr   eax, 1
//   ret
//
// The unit file does not declare this function, so it is modelled here from the
// disassembly.  The object is an hkpRagdollConstraintData (m_kBridgeAtoms at +0x10);
// inside m_kBridgeAtoms the hkpBallSocketConstraintAtom sits at +0x128, so its
// hkUint8 m_ucBodiesToNotify member is at +0x13a of the complete object.
// The getter returns that byte shifted right by one bit.

// @fnv 0x00cde9a0
int hkpRagdollConstraintData::vf06()
{
    return m_kBridgeAtoms.m_kBallSocket.m_ucBodiesToNotify >> 1;
}

// @fnv 0x00cdead0
// src: GUESS 0x00cdead0 (confidence: high)
int __cdecl hkpRagdollConstraintData_ReturnConstant_7()
{
    return 7;
}

// Copies body A's constraint frame into the output rotation.
// @fnv 0x00cdf190
void hkpRagdollConstraintData::getConstraintFrameA(hkRotation* out)
{
    out->m_kColumn0.m_vComponents = m_kBridgeAtoms.m_kTransforms.m_kBodyALocalFrame.m_kColumn0;
    out->m_kColumn1.m_vComponents = m_kBridgeAtoms.m_kTransforms.m_kBodyALocalFrame.m_kColumn1;
    out->m_kColumn2.m_vComponents = m_kBridgeAtoms.m_kTransforms.m_kBodyALocalFrame.m_kColumn2;
}

struct FnvCpu_FUN_00cdf530_CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct FnvCpu_FUN_00cdf530_CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00cdf530_CpuAllocator* allocator;
};
FnvCpu_FUN_00cdf530_CpuAllocatorHolder* __cdecl hkMemoryRouter_getInstance();
__forceinline void hkReferencedObject::operator delete(void* block)
{
    FnvCpu_FUN_00cdf530_CpuAllocatorHolder* holder = hkMemoryRouter_getInstance();
    holder->allocator->Invoke(block, static_cast<hkReferencedObject*>(block)->m_usMemSizeAndFlags);
}

// Copies body B's constraint frame into the output rotation.
// @fnv 0x00cdf1c0
void hkpRagdollConstraintData::getConstraintFrameB(hkRotation* out)
{
    out->m_kColumn0.m_vComponents = m_kBridgeAtoms.m_kTransforms.m_kBodyBLocalFrame.m_kColumn0;
    out->m_kColumn1.m_vComponents = m_kBridgeAtoms.m_kTransforms.m_kBodyBLocalFrame.m_kColumn1;
    out->m_kColumn2.m_vComponents = m_kBridgeAtoms.m_kTransforms.m_kBodyBLocalFrame.m_kColumn2;
}

// LocalhkpLimitedHingeConstraintData: its constructor 0x00cb9090 is throw() and stores into named atom fields;
// include/hkpLimitedHingeConstraintData.h declares the constructor without throw() over a pad0[0xD0] atom block.
class LocalhkpLimitedHingeConstraintData : public hkpConstraintData
{
  public:
    LocalhkpLimitedHingeConstraintData() throw();
    virtual ~LocalhkpLimitedHingeConstraintData() throw();

    int unk0C;
    hkpLimitedHingeConstraintDataAtoms m_kBridgeAtoms;
};

// Initializes m_kBridgeAtoms with identity transforms, default angular limits, friction, motor, and 2D angular constraint values.
// @fnv 0x00cb9090
LocalhkpLimitedHingeConstraintData::LocalhkpLimitedHingeConstraintData() throw()
{
    m_kBridgeAtoms.m_kTransforms.m_kBodyALocalFrame.setIdentity();
    m_kBridgeAtoms.m_kTransforms.m_kBodyBLocalFrame.setIdentity();

    m_kBridgeAtoms.m_kTwoDimensionalAngular.m_ucFreeRotationAxis = 0;

    m_kBridgeAtoms.m_kAngularLimit.m_ucLimitAxis = 0;
    m_kBridgeAtoms.m_kAngularLimit.m_fMinAngle = -3.14159274f;
    m_kBridgeAtoms.m_kAngularLimit.m_fMaxAngle = 3.14159274f;
    m_kBridgeAtoms.m_kAngularLimit.m_fAngularLimitsTauFactor = 1.0f;

    m_kBridgeAtoms.m_kFriction.m_ucFirstFrictionAxis = 0;
    m_kBridgeAtoms.m_kFriction.m_ucNumFrictionAxes = 1;
    m_kBridgeAtoms.m_kFriction.m_fMaxFrictionTorque = 0.0f;

    m_kBridgeAtoms.m_kAngularMotor.m_iInitializedOffset = 0x40;
    m_kBridgeAtoms.m_kAngularMotor.m_iPreviousTargetAngleOffset = 0x44;
    m_kBridgeAtoms.m_kAngularMotor.m_iCorrespondingAngLimitSolverResultOffset = 0x10;
    m_kBridgeAtoms.m_kAngularMotor.m_bLimitEnabled = false;
    m_kBridgeAtoms.m_kAngularMotor.m_fTargetAngle = 0.0f;
    m_kBridgeAtoms.m_kAngularMotor.m_pMotor = 0;
    m_kBridgeAtoms.m_kAngularMotor.m_ucMotorAxis = 0;
}

static __forceinline void hkNormalize3(hkVector4& v)
{
    LocalM128 p = _mm_mul_ps(v.m_vComponents, v.m_vComponents);
    LocalM128 len2 = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
    len2 = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), len2);
    LocalM128 e = _mm_rsqrt_ss(len2);
    LocalM128 r =
        _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), e), _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(len2, e), e)));
    r = _mm_andnot_ps(_mm_cmpeq_ss(len2, _mm_set_ss(0.0f)), r);
    v.m_vComponents = _mm_mul_ps(_mm_shuffle_ps(r, r, 0), v.m_vComponents);
}

static __forceinline void hkSetCross(hkVector4& out, const hkVector4& v0, const hkVector4& v1)
{
    LocalM128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xc9),
                               _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2));
    LocalM128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xd2),
                               _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9));
    out.m_vComponents = _mm_sub_ps(cross0, cross1);
}

__forceinline hkMatrix3::hkMatrix3() {}
__forceinline hkVector4& hkMatrix3::getColumn(int i) { return reinterpret_cast<hkVector4*>(this)[i]; }
__forceinline const hkVector4& hkMatrix3::getColumn(int i) const { return reinterpret_cast<const hkVector4*>(this)[i]; }
__forceinline void hkMatrix3::operator=(const hkMatrix3& m)
{
    m_kColumn0.m_vComponents = m.m_kColumn0.m_vComponents;
    m_kColumn1.m_vComponents = m.m_kColumn1.m_vComponents;
    m_kColumn2.m_vComponents = m.m_kColumn2.m_vComponents;
}

static __forceinline void hkSetTransposeMul(hkMatrix3& out, const hkMatrix3& a, const hkMatrix3& b)
{
    LocalM128 c0 = a.getColumn(0).m_vComponents;
    LocalM128 c1 = a.getColumn(1).m_vComponents;
    LocalM128 c2 = a.getColumn(2).m_vComponents;
    LocalM128 tmp = _mm_unpacklo_ps(c0, c1);
    LocalM128 ctmp = _mm_unpackhi_ps(c0, c1);
    c0 = _mm_movelh_ps(tmp, c2);
    c1 = _mm_movehl_ps(c0, tmp);
    c1 = _mm_shuffle_ps(c1, c2, 0xd4);
    c2 = _mm_shuffle_ps(ctmp, c2, 0xe4);

    for (int i = 0; i < 3; i++)
    {
        const LocalM128 v = b.getColumn(i).m_vComponents;
        LocalM128 b0 = _mm_shuffle_ps(v, v, 0x00);
        LocalM128 b1 = _mm_shuffle_ps(v, v, 0x55);
        LocalM128 b2 = _mm_shuffle_ps(v, v, 0xaa);
        out.getColumn(i).m_vComponents = _mm_add_ps(_mm_add_ps(_mm_mul_ps(b0, c0), _mm_mul_ps(b1, c1)), _mm_mul_ps(b2, c2));
    }
}

// Builds a constraint basis from twist and plane axes, then stores rotated and translated transforms into the ragdoll bridge atom data.
// @fnv 0x00cdeae0
void hkpRagdollConstraintData::setInWorldSpace(const hkTransform& bodyATransform, const hkTransform& bodyBTransform,
                                              const hkVector4& pivot, const hkVector4& twistAxisW,
                                              const hkVector4& planeAxisW)
{
    hkMatrix3 baseConstraint;
    baseConstraint.getColumn(0).m_vComponents = twistAxisW.m_vComponents;
    hkNormalize3(baseConstraint.getColumn(0));
    baseConstraint.getColumn(1).m_vComponents = planeAxisW.m_vComponents;
    hkNormalize3(baseConstraint.getColumn(1));
    hkSetCross(baseConstraint.getColumn(2), baseConstraint.getColumn(0), baseConstraint.getColumn(1));

    hkpSetLocalTransformsConstraintAtom& t = m_kBridgeAtoms.m_kTransforms;

    hkSetTransposeMul(reinterpret_cast<hkMatrix3&>(t.m_kBodyALocalFrame.m_rotation), reinterpret_cast<const hkMatrix3&>(bodyATransform.m_rotation), baseConstraint);
    hkSetTransposeMul(reinterpret_cast<hkMatrix3&>(t.m_kBodyBLocalFrame.m_rotation), reinterpret_cast<const hkMatrix3&>(bodyBTransform.m_rotation), baseConstraint);

    t.m_kBodyALocalFrame.position.SetTransformedPosition(bodyATransform, pivot);
    t.m_kBodyBLocalFrame.position.SetTransformedPosition(bodyBTransform, pivot);

    reinterpret_cast<hkMatrix3&>(m_kBridgeAtoms.m_kMotor.m_kMotorAxes) = reinterpret_cast<hkMatrix3&>(t.m_kBodyBLocalFrame.m_rotation);
}

extern const LocalM128 DAT_010c71e0;

struct Quat
{
    LocalM128 m_vec;
    void hkQuaternion_setAxisAngle(const LocalM128* axis, float angle);
};

__forceinline void Vec4::setCross(const Vec4& a, const Vec4& b)
{
    LocalM128 c0 = _mm_mul_ps(_mm_shuffle_ps(a.getQuad(), a.getQuad(), 0xc9),
                           _mm_shuffle_ps(b.getQuad(), b.getQuad(), 0xd2));
    LocalM128 c1 = _mm_mul_ps(_mm_shuffle_ps(a.getQuad(), a.getQuad(), 0xd2),
                           _mm_shuffle_ps(b.getQuad(), b.getQuad(), 0xc9));
    getQuad() = _mm_sub_ps(c0, c1);
}
__forceinline void Vec4::SetRotatedDirection(const Quat& quat, const Vec4& direction)
{
    const LocalM128& imag = quat.m_vec;
    LocalM128 qreal = _mm_shuffle_ps(imag, imag, 0xff);
    LocalM128 q2minus1 = _mm_mul_ps(qreal, qreal);
    q2minus1 = _mm_add_ps(q2minus1, DAT_010c71e0);
    LocalM128 ret = _mm_mul_ps(direction.getQuad(), q2minus1);
    LocalM128 product = _mm_mul_ps(imag, direction.getQuad());
    LocalM128 imagDotDir = _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa),
                                  _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product));
    ret = _mm_add_ps(ret, _mm_mul_ps(_mm_shuffle_ps(imagDotDir, imagDotDir, 0), imag));
    LocalM128 c0 = _mm_mul_ps(_mm_shuffle_ps(imag, imag, 0xc9),
                          _mm_shuffle_ps(direction.getQuad(), direction.getQuad(), 0xd2));
    LocalM128 c1 = _mm_mul_ps(_mm_shuffle_ps(imag, imag, 0xd2),
                          _mm_shuffle_ps(direction.getQuad(), direction.getQuad(), 0xc9));
    LocalM128 imagCrossDir = _mm_sub_ps(c0, c1);
    ret = _mm_add_ps(ret, _mm_mul_ps(imagCrossDir, qreal));
    getQuad() = _mm_add_ps(ret, ret);
}

// Rotates m_dir about m_kAxisEndPoints by minus the midpoint of a and b, sets m_kStartPerpendicular to their cross, and stores (b - a) / 2 in m_halfRange.
// @fnv 0x00cdef90
void hkpRagdollConstraintData::setPlaneAngularLimit(float afStart, float afEnd)
{
    Vec4& m_dir = reinterpret_cast<Vec4&>(m_kBridgeAtoms.m_kTransforms.m_kBodyBLocalFrame.m_kColumn0);
    Vec4& m_kAxisEndPoints = reinterpret_cast<Vec4&>(m_kBridgeAtoms.m_kTransforms.m_kBodyBLocalFrame.m_kColumn1);
    float& m_halfRange = m_kBridgeAtoms.m_kConeLimit.m_fMaxAngle;
    float center = (afStart + afEnd) * 0.5;
    Quat q;
    q.hkQuaternion_setAxisAngle(&m_kAxisEndPoints.getQuad(), -center);
    m_dir.SetRotatedDirection(q, m_dir);
    // Access through the byte view preserves the original post-rotation reload.
    const unsigned int frameBOffset = offsetof(hkpRagdollConstraintData, m_kBridgeAtoms)
        + offsetof(hkpRagdollConstraintDataAtoms, m_kTransforms)
        + offsetof(hkpSetLocalTransformsConstraintAtom, m_kBodyBLocalFrame);
    Vec4* perp = reinterpret_cast<Vec4*>(reinterpret_cast<char*>(this) + frameBOffset + 0x20);
    perp->setCross(*reinterpret_cast<const Vec4*>(reinterpret_cast<const char*>(this) + frameBOffset), m_kAxisEndPoints);
    m_halfRange = (afEnd - afStart) * 0.5;
}

// 00ca9360 is also bound as hkUFloat8::FUN_00ca9360 in hkprigidbody's recipe.
extern "C" float DAT_0104da48;

// @fnv 0x00cb9170
__declspec(noinline) hkpLimitedHingeConstraintDataAtoms::hkpLimitedHingeConstraintDataAtoms() throw()
{
    float f = 1.0f;
    m_kTransforms.m_type = 2;
    static_cast<volatile unsigned short&>(m_kAngularMotor.m_type) = 0x12;
    static_cast<volatile char&>(m_kAngularMotor.m_bLimitEnabled.m_cBooleanValue) = 1;
    static_cast<volatile short&>(m_kAngularMotor.m_iInitializedOffset) = 0;
    static_cast<volatile short&>(m_kAngularMotor.m_iPreviousTargetAngleOffset) = 0;
    static_cast<volatile unsigned char&>(m_kFriction.m_bLimitEnabled) = 1;
    static_cast<volatile unsigned char&>(m_kFriction.m_ucNumFrictionAxes) = 1;
    static_cast<volatile unsigned short&>(m_kFriction.m_type) = 0x11;
    static_cast<volatile unsigned short&>(m_kAngularLimit.m_type) = 0xe;
    static_cast<volatile unsigned char&>(m_kAngularLimit.m_bLimitEnabled) = 1;
    volatile unsigned short* limit = &m_kTwoDimensionalAngular.m_type;
    *limit = 0xc;
    static_cast<volatile unsigned short&>(m_kBallSocket.m_type) = 5;
    m_kBallSocket.m_ucBodiesToNotify = 0;
    reinterpret_cast<hkUFloat8&>(m_kBallSocket.m_solvingMethod).FindFloatTableIndex(&f);
    m_kBallSocket.m_usFlags = DAT_0104da48;
}

// out = a x b, with the operands passed as (b, a)
static __forceinline void hkSetCrossReversed(hkVector4& out, const hkVector4& b, const hkVector4& a)
{
    LocalM128 cross1 = _mm_mul_ps(_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xc9),
                               _mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xd2));
    LocalM128 cross0 = _mm_mul_ps(_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xd2),
                               _mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xc9));
    out.m_vComponents = _mm_sub_ps(cross0, cross1);
}

// Stores normalized twist and plane axes, their cross product and the pivot for each body, then copies body B's rotation into the motor axes.
// @fnv 0x00cded30
void hkpRagdollConstraintData::setInBodySpace(const hkVector4& pivotA, const hkVector4& pivotB,
                                                     const hkVector4& planeAxisA, const hkVector4& planeAxisB,
                                                     const hkVector4& twistAxisA, const hkVector4& twistAxisB)
{
    hkpSetLocalTransformsConstraintAtom& layout = m_kBridgeAtoms.m_kTransforms;

    hkVector4& twistA = layout.m_kBodyALocalFrame.m_rotation.m_kColumn0;
    twistA.m_vComponents = twistAxisA.m_vComponents;
    hkNormalize3(twistA);
    layout.m_kBodyALocalFrame.m_rotation.m_kColumn1.m_vComponents =
        planeAxisA.m_vComponents;
    hkNormalize3(layout.m_kBodyALocalFrame.m_rotation.m_kColumn1);
    hkSetCross(layout.m_kBodyALocalFrame.m_rotation.m_kColumn2, layout.m_kBodyALocalFrame.m_rotation.m_kColumn0,
               layout.m_kBodyALocalFrame.m_rotation.m_kColumn1);
    layout.m_kBodyALocalFrame.m_vTranslation = pivotA.m_vComponents;

    hkVector4& twistB = layout.m_kBodyBLocalFrame.m_rotation.m_kColumn0;
    twistB.m_vComponents = twistAxisB.m_vComponents;
    hkNormalize3(twistB);
    layout.m_kBodyBLocalFrame.m_rotation.m_kColumn1.m_vComponents =
        planeAxisB.m_vComponents;
    hkNormalize3(layout.m_kBodyBLocalFrame.m_rotation.m_kColumn1);
    hkSetCrossReversed(layout.m_kBodyBLocalFrame.m_rotation.m_kColumn2, layout.m_kBodyBLocalFrame.m_rotation.m_kColumn1,
                       layout.m_kBodyBLocalFrame.m_rotation.m_kColumn0);
    layout.m_kBodyBLocalFrame.m_vTranslation = pivotB.m_vComponents;

    m_kBridgeAtoms.m_kMotor.m_kMotorAxes.m_kColumn0.m_vComponents = layout.m_kBodyBLocalFrame.m_rotation.m_kColumn0.m_vComponents;
    m_kBridgeAtoms.m_kMotor.m_kMotorAxes.m_kColumn1.m_vComponents = layout.m_kBodyBLocalFrame.m_rotation.m_kColumn1.m_vComponents;
    m_kBridgeAtoms.m_kMotor.m_kMotorAxes.m_kColumn2.m_vComponents = layout.m_kBodyBLocalFrame.m_rotation.m_kColumn2.m_vComponents;
}
