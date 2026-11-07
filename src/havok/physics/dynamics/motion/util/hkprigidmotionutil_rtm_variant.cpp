#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_COPY   // this unit defines its own hkVector4 copy form
// Keep this unit's original SSE intrinsic type: the SDK union's byte arrays
// trigger VC9 /GS parameter copies and change the generated game code.
#define _INCLUDED_MM2
// Exe 0x00d28a30 FUN_00d28a30: retain LocalM128; the CRT extent is 3592 bytes versus 3580 in the exe.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
} __m128, LocalM128;
extern "C"
{
    LocalM128 _mm_set1_ps(float);
    LocalM128 _mm_load_ss(const float*);
    LocalM128 _mm_load_ps(const volatile float*);
    void _mm_store_ss(float*, LocalM128);
    void _mm_store_ps(float*, LocalM128);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, int);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_setzero_ps();
    LocalM128 _mm_rcp_ps(LocalM128);
    LocalM128 _mm_and_ps(LocalM128, LocalM128);
    LocalM128 _mm_cmplt_ps(LocalM128, LocalM128);
    LocalM128 _mm_cmpeq_ps(LocalM128, LocalM128);
    int _mm_movemask_ps(LocalM128);
    LocalM128 _mm_unpacklo_ps(LocalM128, LocalM128);
    LocalM128 _mm_unpackhi_ps(LocalM128, LocalM128);
    LocalM128 _mm_movelh_ps(LocalM128, LocalM128);
    LocalM128 _mm_movehl_ps(LocalM128, LocalM128);
}

#include <string.h>
#include "../../../../../../include/QuantizedFloat8.h"
#include "../../../../../../include/Transform.h"
#include "../../../../../../include/NiPoint3.h"
#include "../../../../../../include/hkSimdReal.h"
#include "../../../../../../include/hkBool.h"
#include "../../../../../../include/hkMatrix3.h"
#include "../../../../../../include/hkMotionState.h"
#include "../../../../../../include/hkQuaternion.h"
#include "../../../../../../include/hkRotation.h"
#include "../../../../../../include/hkStepInfo.h"
#include "../../../../../../include/hkSweptTransform.h"
#include "../../../../../../include/hkTransform.h"
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkpBoxMotion.h"
#include "../../../../../../include/hkpMotion.h"
#include "../../../../../../include/hkpThinBoxMotion.h"

#include "../../../../../../include/hkHalf.h"

// src/havok/physics/dynamics/motion/util/hkprigidmotionutil_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/dynamics/motion/util/hkprigidmotionutil.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/dynamics/motion/util/hkprigidmotionutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/motion/util/hkprigidmotionutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void _ReadWriteBarrier();

static __forceinline LocalM128 broadcast(float f)
{
    LocalM128 v = _mm_load_ss(&f);
    return _mm_shuffle_ps(v, v, 0);
}
extern const LocalM128 DAT_010ec7f0;

struct OutputHeader
{
    unsigned char unk00;
    char unk01, unk02, unk03;
    int unk04;
    union
    {
        int unk08;
        float scalar08;
    };
    int unk0C;
};
union OutputCell
{
    LocalM128 vector;
    OutputHeader header;
    struct
    {
        float x, y, z, w;
    };
};
struct TargetItem
{
    OutputCell cells[8];
};

// @fnv 0x00d29830
// src: COMMUNITY 0x00d29830
TargetItem* __cdecl hkRigidMotionUtilApplyForcesAndBuildAccumulators(hkStepInfo* a0, hkpMotion** a1, int a2, int a3, TargetItem* a4)
{
    int count = a2 - 1;
    if (count >= 0)
    {

        OutputCell* last = &a4->cells[7];
        do
        {
            hkpMotion* item = (hkpMotion*)((char*)*a1 + a3);
            switch (*reinterpret_cast<const unsigned char*>(&item->m_type))
            {
            case 0:
            case 3:
            case 6: {
                float dt = a0->m_fTimeStep;
                float d1 = 1.0f - dt * item->m_kMotionState.m_fLinearDamping;

                LocalM128 s1 = broadcast(0.0f > d1 ? 0.0f : d1);
                item->m_kTranslationalVelocity.m_vComponents = _mm_mul_ps(s1, item->m_kTranslationalVelocity.m_vComponents);
                _ReadWriteBarrier();

                float d2 = 1.0f - dt * item->m_kMotionState.m_fAngularDamping;

                LocalM128 s2 = broadcast(0.0f > d2 ? 0.0f : d2);
                item->m_kAngularVelocity.m_vComponents = _mm_mul_ps(s2, item->m_kAngularVelocity.m_vComponents);

                hkMotionState* sub = &item->m_kMotionState;
                ((hkMatrix3*)&last[-2].vector)->_setTranspose(*reinterpret_cast<const hkMatrix3*>(sub));
                a4->cells[0].header.unk00 = 0;
                last[-4].vector = _mm_load_ps((const volatile float*)&item->m_kInertiaAndMassInv.m_vComponents);
                last[-6].vector = item->m_kTranslationalVelocity.m_vComponents;

                float ldt = (a0->m_uiStartTime - sub->m_kSweptTransform.m_vCenterOfMass0.w) * sub->m_kSweptTransform.m_vCenterOfMass1.w;
                LocalM128 dtv = broadcast(ldt);
                LocalM128 inv_dt = _mm_sub_ps(DAT_010ec7f0, dtv);
                last[-3].vector = _mm_add_ps(_mm_mul_ps(inv_dt, sub->m_kSweptTransform.m_vCenterOfMass0.m_vComponents), _mm_mul_ps(dtv, sub->m_kSweptTransform.m_vCenterOfMass1.m_vComponents));

                LocalM128 v = item->m_kAngularVelocity.m_vComponents;
                LocalM128 c1 =
                    _mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), _mm_load_ps((const volatile float*)&last[-1].vector));
                LocalM128 c0 =
                    _mm_mul_ps(_mm_shuffle_ps(v, v, 0x00), _mm_load_ps((const volatile float*)&last[-2].vector));
                LocalM128 res = _mm_add_ps(c1, c0);
                LocalM128 c2 = _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), last[0].vector);
                last[-5].vector = _mm_add_ps(res, c2);

                last[-7].header.unk04 = item->m_kMotionState.m_uiDeactivationClass;
                last[-7].header.unk08 = ((int)item->m_fGravityFactor.m_value) << 16;
                break;
            }
            case 7:
                a4->cells[0].header.unk00 = 2;
                goto handle_case_2;
            case 2:
                a4->cells[0].header.unk00 = 0;
            handle_case_2: {
                float dt = a0->m_fTimeStep;
                float d1 = 1.0f - dt * item->m_kMotionState.m_fLinearDamping;

                LocalM128 s1 = broadcast(0.0f > d1 ? 0.0f : d1);
                item->m_kTranslationalVelocity.m_vComponents = _mm_mul_ps(s1, item->m_kTranslationalVelocity.m_vComponents);
                _ReadWriteBarrier();

                float d2 = 1.0f - dt * item->m_kMotionState.m_fAngularDamping;

                LocalM128 s2 = broadcast(0.0f > d2 ? 0.0f : d2);
                item->m_kAngularVelocity.m_vComponents = _mm_mul_ps(s2, item->m_kAngularVelocity.m_vComponents);

                last[-4].vector = _mm_load_ps((const volatile float*)&item->m_kInertiaAndMassInv.m_vComponents);

                float ldt = (a0->m_uiStartTime - item->m_kMotionState.m_kSweptTransform.m_vCenterOfMass0.w) * item->m_kMotionState.m_kSweptTransform.m_vCenterOfMass1.w;
                LocalM128 dtv = broadcast(ldt);
                LocalM128 inv_dt = _mm_sub_ps(DAT_010ec7f0, dtv);
                last[-3].vector = _mm_add_ps(_mm_mul_ps(inv_dt, item->m_kMotionState.m_kSweptTransform.m_vCenterOfMass0.m_vComponents), _mm_mul_ps(dtv, item->m_kMotionState.m_kSweptTransform.m_vCenterOfMass1.m_vComponents));

                last[-5].vector = item->m_kAngularVelocity.m_vComponents;
                last[-6].vector = item->m_kTranslationalVelocity.m_vComponents;

                LocalM128 zero = _mm_setzero_ps();
                last[-2].vector = zero;
                last[-1].vector = zero;
                last[0].vector = zero;
                *(volatile float*)&last[-2].x = 1.0f;
                *(volatile float*)&last[-1].y = 1.0f;
                *(volatile float*)&last[0].z = 1.0f;

                last[-7].header.unk04 = item->m_kMotionState.m_uiDeactivationClass;
                last[-7].header.unk08 = ((int)item->m_fGravityFactor.m_value) << 16;
                break;
            }
            case 5: {
                LocalM128 zero = _mm_setzero_ps();
                last[-7].header.scalar08 = 0.0f;
                a4->cells[0].header.unk00 = 1;
                last[-4].vector = zero;
                last[-6].vector = zero;
                last[-5].vector = zero;
                last[-3].vector = zero;
                last[-2].vector = zero;
                last[-1].vector = zero;
                last[0].vector = zero;
                break;
            }
            case 4: {
                a4->cells[0].header.unk00 = 1;
                LocalM128 zero = _mm_setzero_ps();
                last[-4].vector = zero;
                last[-3].vector = item->m_kMotionState.m_kSweptTransform.m_vCenterOfMass1.m_vComponents;
                last[-5].vector = item->m_kAngularVelocity.m_vComponents;
                last[-6].vector = item->m_kTranslationalVelocity.m_vComponents;
                last[-2].vector = zero;
                last[-1].vector = zero;
                last[0].vector = zero;
                *(volatile float*)&last[-2].x = 1.0f;
                *(volatile float*)&last[-1].y = 1.0f;
                *(volatile float*)&last[0].z = 1.0f;
                last[-7].header.unk08 = ((int)item->m_fGravityFactor.m_value) << 16;
                break;
            }
            default:
                break;
            }

            a1++;
            a4++;
            last += 8;
        } while (--count >= 0);
    }
    return a4;
}

#include <math.h>
#include "../../../../../../include/hkBaseObject.h"
#include "../../../../../../include/hkReferencedObject.h"
namespace ApplyAccumulatorsPrivate {

typedef float hkReal;
typedef float hkTime;
typedef LocalM128 hkQuadReal;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef short hkInt16;
typedef unsigned int hkUint32;
typedef long hkLong;

// zeroElement, the identity transform.
extern const hkReal DAT_010c7948[];
extern const double DAT_010ce4b0;
extern const double DAT_010ce4a8;
extern const double DAT_010ce4a0;
extern const double DAT_010ce498;
extern const double DAT_010ce488;
extern const hkQuadReal DAT_010cbf80;
extern const hkUint32 DAT_01017d10[4];
extern const hkUint32 DAT_010cbf90[4][4];
extern const hkQuadReal DAT_01268370[4];

typedef const hkSimdReal& hkSimdRealParameter;

namespace MathUtilities {
__forceinline hkQuadReal quadReciprocal(hkQuadReal r)
{
    hkQuadReal e = _mm_rcp_ps(r);
    return _mm_sub_ps(_mm_add_ps(e, e), _mm_mul_ps(_mm_mul_ps(e, r), e));
}
__forceinline hkReal sqrt(hkReal r)
{
    return sqrtf(r);
}
__forceinline hkReal sqrtInverse(hkReal r)
{
    return 1.0f / MathUtilities::sqrt(r);
}
template <typename T> __forceinline T max2(T x, T y)
{
    return x > y ? x : y;
}
template <typename T> __forceinline T min2(T x, T y)
{
    return x < y ? x : y;
}
}

} // namespace ApplyAccumulatorsPrivate

class Vector4Comparison
{
  public:
    __forceinline int GetLaneMask() const
    {
        return _mm_movemask_ps(m_uiMask);
    }

  private:
    LocalM128 m_uiMask;
    friend class hkVector4;
};

// Retain the original inline implementations against the shared class declarations.
__forceinline QuantizedFloat8::operator float() const
{
    return ApplyAccumulatorsPrivate::DAT_010c7948[*reinterpret_cast<const unsigned char*>(this)];
}

__forceinline hkSimdReal::hkSimdReal(const LocalM128& x) 
{ m_vValue = x; }

__forceinline hkSimdReal::hkSimdReal(float x)
{
    m_vValue = _mm_load_ss(&x);
}

__forceinline hkSimdReal::operator float() const
{
    float s;
    _mm_store_ss(&s, m_vValue);
    return s;
}

__forceinline LocalM128 hkSimdReal::broadcast() const
{
    return _mm_shuffle_ps(m_vValue, m_vValue, 0);
}



__forceinline const hkVector4& hkMatrix3::getColumn(int x) const
{
    return (&m_kColumn0)[x];
}

__forceinline hkTransform& hkMotionState::getTransform()
{
    return m_kMotionTransform;
}

__forceinline const hkTransform& hkMotionState::getTransform() const
{
    return m_kMotionTransform;
}

__forceinline const hkSweptTransform& hkMotionState::getSweptTransform() const
{
    return m_kSweptTransform;
}

__forceinline hkSweptTransform& hkMotionState::getSweptTransform()
{
    return m_kSweptTransform;
}

__forceinline hkQuaternion::hkQuaternion()
{}

__forceinline void hkQuaternion::operator=(const hkQuaternion& q)
{
    (*reinterpret_cast<hkVector4*>(this)) = (*reinterpret_cast<const hkVector4*>(&q));
}

__forceinline void hkQuaternion::normalize()
{
    (*reinterpret_cast<hkVector4*>(this)).normalize_005611c0();
}

__forceinline hkRotation& hkTransform::getRotation()
{
    return (*reinterpret_cast<hkRotation*>(&m_row0));
}

__forceinline const hkRotation& hkTransform::getRotation() const
{
    return (*reinterpret_cast<const hkRotation*>(&m_row0));
}

__forceinline void hkTransform::SetBodyOrientation(const hkQuaternion& quatRotation)
{
    (*reinterpret_cast<hkRotation*>(&m_row0)).hkRotation_set(quatRotation);
}

__forceinline hkVector4& hkTransform::getTranslation()
{
    return (*reinterpret_cast<hkVector4*>(&m_row3));
}

__forceinline const hkVector4& hkTransform::getColumn(int x) const
{
    return (*reinterpret_cast<const hkRotation*>(&m_row0)).getColumn(x);
}

__forceinline const hkTransform& hkTransform::GetIdentityTransform()
{
    return reinterpret_cast<const hkTransform&>(ApplyAccumulatorsPrivate::DAT_01268370);
}

__forceinline LocalM128& hkVector4::getQuad()
{
    return m_vComponents;
}


__forceinline void hkVector4::zeroElement(int i)
{
    m_vComponents = _mm_and_ps(m_vComponents, reinterpret_cast<const LocalM128*>(ApplyAccumulatorsPrivate::DAT_010cbf90)[i]);
}

__forceinline void hkVector4::setAdd4(const hkVector4& v0, const hkVector4& v1)
{
    m_vComponents = _mm_add_ps(v0.m_vComponents, v1.m_vComponents);
}

__forceinline void hkVector4::setSub4(const hkVector4& v0, const hkVector4& v1)
{
    m_vComponents = _mm_sub_ps(v0.m_vComponents, v1.m_vComponents);
}

__forceinline void hkVector4::mul4(const hkVector4& v)
{
    m_vComponents = _mm_mul_ps(m_vComponents, v.m_vComponents);
}

__forceinline void hkVector4::mul4(const hkSimdReal& s)
{
    m_vComponents = _mm_mul_ps(s.broadcast(), m_vComponents);
}

__forceinline void hkVector4::setMul4(const hkSimdReal& r, const hkVector4& v1)
{
    m_vComponents = _mm_mul_ps(r.broadcast(), v1.m_vComponents);
}

__forceinline void hkVector4::addMul4(const hkSimdReal& r, const hkVector4& v1)
{
    m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(r.broadcast(), v1.m_vComponents));
}

__forceinline Vector4Comparison hkVector4::compareLessThan4(const hkVector4& a) const
{
    Vector4Comparison m;
    m.m_uiMask = _mm_cmplt_ps(m_vComponents, a.m_vComponents);
    return m;
}

__forceinline Vector4Comparison hkVector4::compareEqual4(const hkVector4& a) const
{
    Vector4Comparison m;
    m.m_uiMask = _mm_cmpeq_ps(m_vComponents, a.m_vComponents);
    return m;
}

__forceinline void hkVector4::setAbs4(const hkVector4& v)
{
    m_vComponents = _mm_and_ps(v.m_vComponents, *(const LocalM128*)&ApplyAccumulatorsPrivate::DAT_01017d10);
}

__forceinline void hkVector4::_setRotatedDir(const hkRotation& r, const hkVector4& v)
{
    _setMul3(r, v);
}

__forceinline void hkVector4::setRotatedInverseDir(const hkRotation& t, const hkVector4& v)
{
    _setRotatedInverseDir(t, v);
}

__forceinline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
    LocalM128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
    LocalM128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xySum);
}

__forceinline hkSimdReal hkVector4::dot4(const hkVector4& a) const
{
    LocalM128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
    LocalM128 sum0 = _mm_add_ps(_mm_shuffle_ps(x2, x2, 0x4e), x2);
    LocalM128 sum1 = _mm_shuffle_ps(sum0, sum0, 0xb1);
    return _mm_add_ps(sum0, sum1);
}

__forceinline hkSimdReal hkVector4::lengthSquared3() const
{
    return this->dot3(*this);
}

__forceinline float hkVector4::lengthSquared4() const
{
    return this->dot4(*this);
}

__forceinline float& hkVector4::operator()(int a)
{
    return reinterpret_cast<float*>(&m_vComponents)[a];
}

__forceinline const hkTransform& hkpMotion::getTransform() const
{
    return m_kMotionState.getTransform();
}

__forceinline int hkpMotion::getNumInactiveFrames(int select)
{
    return m_ausDeactivationNumInactiveFrames[select] & 0x7f;
}

__forceinline void hkpMotion::incrementNumInactiveFramesMt(int select, int worldDeactivationNumInactiveFramesSelectFlag)
{
    int dc = m_ausDeactivationNumInactiveFrames[select];
    dc = dc & 0x7f;
    int newdc = dc + 1 - (dc >> 6);
    dc = newdc | (dc << 7) | (worldDeactivationNumInactiveFramesSelectFlag << 14);
    m_ausDeactivationNumInactiveFrames[select] = hkUint16(dc);
}

__forceinline void hkpMotion::zeroNumInactiveFramesMt(int select, int worldDeactivationNumInactiveFramesSelectFlag)
{
    int dc = m_ausDeactivationNumInactiveFrames[select];
    dc = dc & 0x7f;
    dc = (dc << 7) | (worldDeactivationNumInactiveFramesSelectFlag << 14);
    m_ausDeactivationNumInactiveFrames[select] = hkUint16(dc);
}

__forceinline void hkVector4::_setMul3(const hkRotation& a, const hkVector4& b)
{
    const LocalM128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0);
    const LocalM128 r0 = _mm_mul_ps(a.getColumn(0).m_vComponents, b0);
    const LocalM128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    const LocalM128 r1 = _mm_mul_ps(a.getColumn(1).m_vComponents, b1);
    const LocalM128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    const LocalM128 r2 = _mm_mul_ps(a.getColumn(2).m_vComponents, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}
__forceinline void hkVector4::_setRotatedInverseDir(const hkRotation& r, const hkVector4& b)
{
    LocalM128 c0 = r.getColumn(0).m_vComponents;
    LocalM128 c1 = r.getColumn(1).m_vComponents;
    LocalM128 c2 = r.getColumn(2).m_vComponents;
    {
    LocalM128 _tmp, _ctmp;
    _tmp = _mm_unpacklo_ps(c0, c1);
    _ctmp = _mm_shuffle_ps(_mm_unpackhi_ps(c0, c1), c2, 0xe4);
    c0 = _mm_movelh_ps(_tmp, c2);
    c1 = _mm_shuffle_ps(_mm_movehl_ps(c0, _tmp), c2, 0xd4);
    c2 = _ctmp;
}
    const LocalM128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0);
    const LocalM128 r0 = _mm_mul_ps(c0, b0);
    const LocalM128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    const LocalM128 r1 = _mm_mul_ps(c1, b1);
    const LocalM128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    const LocalM128 r2 = _mm_mul_ps(c2, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}
__forceinline const hkVector4& hkRotation::getColumn(int x) const { return (&m_kColumn0)[x]; }
__forceinline hkVector4::hkVector4(const hkVector4& v) { memcpy(this, &v, sizeof(*this)); }
__forceinline hkQuaternion::hkQuaternion(const hkQuaternion& q) { memcpy(this, &q, sizeof(*this)); }

__forceinline LocalM128& hkVector4::q() { return m_vComponents; }

namespace ApplyAccumulatorsPrivate {

struct ConstraintSolverInfo
{
    struct FloatAndHalfRecord
    {
        float m_fFirstFloat;
        float m_fSecondFloat;
        float m_fThirdValue;
        float m_fFourthFloat;
        float m_afFloatPair[2];
        hkHalf m_ahHalfPair[2];
    };
    __declspec(align(16)) float m_iCachedVertexCount;
    float m_fTau;
    float m_fMotorDamping;
    float m_fPostDampingParameter;
    hkVector4 m_kGravity;
    hkVector4 m_kSecondSolverVector;
    hkVector4 m_kTimeStep;
    hkVector4 GetTimeStepFactor;
    float m_fFirstTrailingParameter;
    float m_fSecondTrailingParameter;
    float m_fThirdTrailingParameter;
    float m_fFourthTrailingParameter;
    float m_fContactRestingVelocity;
    FloatAndHalfRecord m_kDeactivationClassInfo[6];
    float m_fTimeStep;
    float m_fInverseDeltaTime;
    int m_iToiEventCount;
    int m_iMicroStepCount;
    float m_fInverseMicroStepCount;
    float m_fInverseStepCount;
    hkBool m_bForceCoherentConstraintOrderingInSolver;
    hkUint8 m_ucDeactivationInactiveFrameSelectFlags[2];
    hkUint8 m_ucDeactivationIntegrateCounter;
    float m_fMaxConstraintViolationSquared;
};

class QuantizedBoundsData
{
  public:
    __forceinline const hkVector4& getSumLinearVel() const
    {
        return getScratch0();
    }
    __forceinline const hkVector4& getSumAngularVel() const
    {
        return getScratch1();
    }
    __forceinline const hkVector4& getScratch0() const
    {
        return m_vCenterOfMass;
    }
    __forceinline const hkVector4& getScratch1() const
    {
        return m_kCoreFromWorldMatrix.getColumn(0);
    }
    hkUint8 m_type;
    hkUint32 m_uiDeactivationClass;
    hkReal m_fGravityFactor;
    hkVector4 m_vLinearVelocity;
    hkVector4 m_vAngularVelocity;
    hkVector4 m_vInverseInertiaAndMass;
    hkVector4 m_vCenterOfMass;
    hkRotation m_kCoreFromWorldMatrix;
};

template <typename TYPE> __forceinline TYPE* hkAddByteOffset(TYPE* base, hkLong offset)
{
    return reinterpret_cast<TYPE*>(reinterpret_cast<char*>(base) + offset);
}

extern unsigned int __cdecl PackFloatsToUInt(const hkVector4& qin);

namespace hkVector4Util_S {
__forceinline void unPackInt32IntoQuaternion(hkUint32 ivalue, hkVector4& qout)
{
    int a = ivalue;
    int b = ivalue >> 8;
    int c = ivalue >> 16;
    int d = ivalue >> 24;
    a &= 0xff;
    b &= 0xff;
    c &= 0xff;
    a -= 0x80;
    b -= 0x80;
    c -= 0x80;
    d -= 0x80;
    qout(0) = DAT_010ce488 * (hkReal)a;
    qout(1) = DAT_010ce488 * (hkReal)b;
    qout(2) = DAT_010ce488 * (hkReal)c;
    qout(3) = DAT_010ce488 * (hkReal)d;
}
}

namespace MotionUtilities {

__forceinline void calcTransAtT1(const hkSweptTransform& sweptTrans, hkTransform& transformOut)
{
    const hkQuaternion& qt = sweptTrans.m_qRotation1;
    transformOut.SetBodyOrientation(qt);
    hkVector4 centerShift;
    centerShift._setRotatedDir(transformOut.getRotation(), sweptTrans.m_vCenterOfMassLocal);
    transformOut.getTranslation().setSub4(sweptTrans.m_vCenterOfMass1, centerShift);
}

__forceinline void _clipVelocities(const hkMotionState& motionState, hkVector4& linearVelocity,
                                   hkVector4& angularVelocity)
{
    hkReal linVelSq = linearVelocity.lengthSquared3();
    hkReal angVelSq = angularVelocity.lengthSquared3();
    const hkReal maxLinear = motionState.m_fSurfaceFriction * motionState.m_fSurfaceFriction;
    const hkReal maxAngular = motionState.m_fRestitution * motionState.m_fRestitution;
    if ((linVelSq > maxLinear) || (linVelSq != linVelSq))
    {
        hkReal f = motionState.m_fSurfaceFriction * MathUtilities::sqrtInverse(linVelSq);
        linearVelocity.mul4(hkSimdReal(f));
        if (linVelSq != linVelSq)
        {
            linearVelocity = hkTransform::GetIdentityTransform().getColumn(0);
        }
    }
    if ((angVelSq > maxAngular) || (angVelSq != angVelSq))
    {
        hkReal f = motionState.m_fRestitution * MathUtilities::sqrtInverse(angVelSq);
        angularVelocity.mul4(hkSimdReal(f));
        if (angVelSq != angVelSq)
        {
            angularVelocity = hkTransform::GetIdentityTransform().getColumn(0);
        }
    }
}

__forceinline void _stepMotionState(const hkStepInfo& info, hkVector4& linearVelocity, hkVector4& angularVelocity,
                                    hkMotionState& motionState)
{
    {
        hkVector4 absLin;
        absLin.setAbs4(linearVelocity);
        hkVector4 absAng;
        absAng.setAbs4(angularVelocity);

        hkVector4 maxVel;
        maxVel.getQuad() = DAT_010cbf80;
        int mask = absLin.compareLessThan4(maxVel).GetLaneMask() & absAng.compareLessThan4(maxVel).GetLaneMask();
        mask &= linearVelocity.compareEqual4(linearVelocity).GetLaneMask() &
                angularVelocity.compareEqual4(angularVelocity).GetLaneMask();
        if ((mask & 7) != 7)
        {
            linearVelocity = hkTransform::GetIdentityTransform().getColumn(0);
            angularVelocity = hkTransform::GetIdentityTransform().getColumn(0);
        }
    }

    motionState.getSweptTransform().m_vCenterOfMass0 = motionState.getSweptTransform().m_vCenterOfMass1;
    motionState.getSweptTransform().m_vCenterOfMass0(3) = info.m_uiStartTime;

    hkReal linVelSq = linearVelocity.lengthSquared3();
    if (linVelSq > motionState.m_fSurfaceFriction * motionState.m_fSurfaceFriction)
    {
        hkReal f = motionState.m_fSurfaceFriction * MathUtilities::sqrtInverse(linVelSq);
        linearVelocity.mul4(hkSimdReal(f));
    }

    motionState.getSweptTransform().m_vCenterOfMass1.addMul4(info.m_fTimeStep.val(), linearVelocity);
    motionState.getSweptTransform().m_vCenterOfMass1(3) = info.m_fInverseDeltaTime;

    __declspec(align(16)) hkQuaternion newRotation = motionState.getSweptTransform().m_qRotation1;
    motionState.getSweptTransform().m_qRotation0 = newRotation;

    hkReal angle;
    {
        __declspec(align(16)) hkQuaternion dq;
        (*reinterpret_cast<hkVector4*>(&dq)).setMul4(hkSimdReal(info.m_fTimeStep * 0.5f), angularVelocity);
        const hkReal pi = 3.14159265358979f;
        hkReal dx2 = hkReal((*reinterpret_cast<hkVector4*>(&dq)).lengthSquared3()) * DAT_010ce4b0;

        const hkReal maxAnglePerStep = MathUtilities::min2(0.9f, info.m_fTimeStep.val() * motionState.m_fRestitution);

        if (dx2 <= maxAnglePerStep * maxAnglePerStep)
        {
            const hkReal dx4 = dx2 * dx2;
            const hkReal w = 1.0f - DAT_010ce4a8 * dx2 - DAT_010ce4a0 * dx4 - DAT_010ce498 * dx2 * dx4;
            (*reinterpret_cast<hkVector4*>(&dq))(3) = w;
        }
        else
        {
            hkReal factor = maxAnglePerStep * MathUtilities::sqrtInverse(dx2);
            angularVelocity.mul4(hkSimdReal(factor));
            (*reinterpret_cast<hkVector4*>(&dq)).mul4(hkSimdReal(factor));

            dx2 = maxAnglePerStep * maxAnglePerStep;
            const hkReal dx4 = dx2 * dx2;
            const hkReal w = 1.0f - DAT_010ce4a8 * dx2 - DAT_010ce4a0 * dx4 - DAT_010ce498 * dx2 * dx4;
            (*reinterpret_cast<hkVector4*>(&dq))(3) = w;
        }

        newRotation.setMul(dq, newRotation);
        newRotation.normalize();

        motionState.m_kDeltaAngle.setAdd4((*reinterpret_cast<hkVector4*>(&dq)), (*reinterpret_cast<hkVector4*>(&dq)));
        angle = MathUtilities::sqrt(dx2) * pi;
        motionState.m_kDeltaAngle(3) = angle;
    }
    motionState.getSweptTransform().m_qRotation1 = newRotation;
    calcTransAtT1(motionState.getSweptTransform(), motionState.getTransform());
}

}

static __forceinline hkReal calcVelocityForDeactivation(const hkpMotion& motion, hkReal radius)
{
    hkReal linVelSqrd = motion.m_kTranslationalVelocity.lengthSquared3();
    hkReal angVelSqrd = motion.m_kAngularVelocity.lengthSquared3();
    hkReal velSqrd = linVelSqrd + radius * radius * angVelSqrd;
    return velSqrd;
}

static __forceinline int hkRigidMotionUtilCheckDeactivation(const ConstraintSolverInfo& si, hkpMotion& motion)
{
    hkUint32 c = motion.m_ucDeactivationIntegrateCounter;
    c += 1;
    motion.m_ucDeactivationIntegrateCounter = hkUint8(c);
    if (c & 3)
    {
        goto END_OF_FUNCTION;
    }
    {
        int select;
        if (c & 15)
        {
            select = 0;
        }
        else
        {
            if (c == 0x100)
            {
                motion.m_ucDeactivationIntegrateCounter = 0xff;
                goto END_OF_FUNCTION;
            }
            motion.m_ucDeactivationIntegrateCounter = 0;
            select = 1;
        }

        hkReal radius = MathUtilities::min2(1.0f, motion.m_kMotionState.m_fObjectRadius);
        {
            hkReal velSqrd = calcVelocityForDeactivation(motion, radius);
            hkReal& maxDeactVel = motion.m_akDeactivationReferencePositions[select](3);
            maxDeactVel = MathUtilities::max2(maxDeactVel, velSqrd);
        }

        hkVector4& refPosition = motion.m_akDeactivationReferencePositions[select];
        hkUint32& refOrientation = motion.m_auiDeactivationReferenceOrientations[select];
        const hkSweptTransform& sweptTransform = motion.m_kMotionState.getSweptTransform();
        const hkVector4& currentPosition = sweptTransform.m_vCenterOfMass1;
        const hkQuaternion& currentRotation = sweptTransform.m_qRotation1;

        while (1)
        {
            const ConstraintSolverInfo::FloatAndHalfRecord& di =
                si.m_kDeactivationClassInfo[motion.m_kMotionState.m_uiDeactivationClass];
            {
                hkReal maxSqrd = di.m_afFloatPair[select];
                hkVector4 transDist;
                transDist.setSub4(refPosition, currentPosition);
                const hkReal distSqrd = transDist.lengthSquared3();
                if (distSqrd > maxSqrd)
                {
                    break;
                }
            }
            {
                __declspec(align(16)) hkQuaternion refQ;
                hkVector4Util_S::unPackInt32IntoQuaternion(refOrientation, (*reinterpret_cast<hkVector4*>(&refQ)));
                hkReal maxSqrd = di.m_ahHalfPair[select];
                hkVector4 dist;
                dist.setSub4((*reinterpret_cast<hkVector4*>(&refQ)), (*reinterpret_cast<const hkVector4*>(&currentRotation)));
                const hkReal distSqrd = dist.dot4(dist);
                if (distSqrd > maxSqrd)
                {
                    break;
                }
            }
            motion.incrementNumInactiveFramesMt(select, si.m_ucDeactivationInactiveFrameSelectFlags[select]);
            goto END_OF_FUNCTION;
        }

        motion.zeroNumInactiveFramesMt(select, si.m_ucDeactivationInactiveFrameSelectFlags[select]);
        {
            hkVector4 pos = currentPosition;
            pos.zeroElement(3);
            refPosition = pos;
        }
        refOrientation = PackFloatsToUInt((*reinterpret_cast<const hkVector4*>(&currentRotation)));
    }
END_OF_FUNCTION:
    return MathUtilities::max2(motion.getNumInactiveFrames(0), motion.getNumInactiveFrames(1));
}

static __forceinline void setReciprocal4(hkVector4& result, const hkVector4& vector)
{
    result.m_vComponents = MathUtilities::quadReciprocal(vector.m_vComponents);
}

// @fnv 0x00d29bf0
// src: COMMUNITY 0x00d29bf0
extern "C" int __cdecl hkRigidMotionUtilApplyAccumulators(const ConstraintSolverInfo& solverInfo, const hkStepInfo& info,
                                    const QuantizedBoundsData* accumulators, hkpMotion* const* motions, int numMotions,
                                    int motionOffset)
{
    const QuantizedBoundsData* accu = accumulators;
    int numInactiveFrames = 0x7fffffff;

    for (int i = numMotions - 1; i >= 0; motions++, accu++, i--)
    {
        hkpMotion* motion = hkAddByteOffset(motions[0], motionOffset);

        hkVector4 integrationLinearVelocity;
        hkVector4 integrationAngularVelocity;
        hkVector4 angularMomentum;

        switch (*reinterpret_cast<const hkUint8*>(&motion->m_type))
        {
        case hkpMotion::MOTION_INVALID:
        case hkpMotion::MOTION_THIN_BOX_INERTIA: {
            hkpThinBoxMotion* tbm = static_cast<hkpThinBoxMotion*>(motion);
            hkVector4 angVelLocalSpace = accu->m_vAngularVelocity;
            hkVector4 in;
            setReciprocal4(in, tbm->m_kInertiaAndMassInv);
            angVelLocalSpace.mul4(in);
            angularMomentum.hkVector4_setRotatedDir(tbm->getTransform().getRotation(), angVelLocalSpace);
        }
        case hkpMotion::MOTION_BOX_INERTIA: {
            motion->m_kTranslationalVelocity = accu->m_vLinearVelocity;
            motion->m_kAngularVelocity._setRotatedDir(motion->getTransform().getRotation(), accu->m_vAngularVelocity);
            integrationLinearVelocity = accu->getSumLinearVel();
            integrationAngularVelocity.hkVector4_setRotatedDir(motion->getTransform().getRotation(), accu->getSumAngularVel());
            goto sphereInertia;
        }
        case hkpMotion::MOTION_KEYFRAMED: {
            motion->m_kTranslationalVelocity = motion->m_kTranslationalVelocity;
            motion->m_kAngularVelocity = motion->m_kAngularVelocity;
            integrationLinearVelocity = motion->m_kTranslationalVelocity;
            integrationAngularVelocity = motion->m_kAngularVelocity;
            goto sphereInertia;
        }
        case hkpMotion::MOTION_SPHERE_INERTIA:
        case hkpMotion::MOTION_CHARACTER: {
            motion->m_kTranslationalVelocity = accu->m_vLinearVelocity;
            motion->m_kAngularVelocity = accu->m_vAngularVelocity;
            integrationLinearVelocity = accu->getSumLinearVel();
            integrationAngularVelocity = accu->getSumAngularVel();
        }
        sphereInertia:
            MotionUtilities::_stepMotionState(info, integrationLinearVelocity, integrationAngularVelocity,
                                              motion->m_kMotionState);
        default:
            break;
        }

        if (*reinterpret_cast<const hkUint8*>(&motion->m_type) == hkpMotion::MOTION_THIN_BOX_INERTIA)
        {
            hkpThinBoxMotion* tbm = static_cast<hkpThinBoxMotion*>(motion);
            tbm->m_kTranslationalVelocity = accu->m_vLinearVelocity;
            hkVector4 h;
            h.setRotatedInverseDir(tbm->getTransform().getRotation(), angularMomentum);
            h.mul4(tbm->m_kInertiaAndMassInv);
            tbm->m_kAngularVelocity.hkVector4_setRotatedDir(tbm->getTransform().getRotation(), h);
        }
        MotionUtilities::_clipVelocities(motion->m_kMotionState, motion->m_kTranslationalVelocity,
                                         motion->m_kAngularVelocity);
        numInactiveFrames =
            MathUtilities::min2(numInactiveFrames, hkRigidMotionUtilCheckDeactivation(solverInfo, *motion));
    }
    return numInactiveFrames;
}

}

#include <math.h>
namespace ApplyForcesStepPrivate {
extern "C" void _ReadWriteBarrier(void);

struct DeactivationClass
{
    float unk00, unk04, unk08, unk0c;
    float positionThreshold[2];
    short rotationThreshold[2];
};
struct SolverInfo
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60;
    DeactivationClass deactivation[6];
    unsigned char unk10c, unk10d, unk10e, unk10f;
    int unk110, unk114, unk118, unk11c, unk120;
    unsigned char unk124, selectFlags[2];
};
extern float DAT_010c7948[];

extern const double DAT_010ce4a0 = (double)0.130529f;
extern const double DAT_010ce498 = (double)0.044408f;
extern const double DAT_010ce488;

extern hkVector4 DAT_01268370;
extern hkVector4 DAT_01017d10;
extern hkVector4 DAT_010cbf80;
extern hkVector4 DAT_010cbfc0;
unsigned int __cdecl PackFloatsToUInt(hkQuaternion*);

static __forceinline LocalM128 splat(float b)
{
    LocalM128 t = _mm_load_ss(&b);
    return _mm_shuffle_ps(t, t, 0);
}
static __forceinline float maxf2(float a, float b)
{
    return a > b ? a : b;
}
static __forceinline float maxVelocity(const unsigned char& index)
{
    return DAT_010c7948[index];
}
static __forceinline const float& maxVelocityRef(const unsigned char& index)
{
    return DAT_010c7948[index];
}
static __forceinline float& elem(hkVector4& v, int i)
{
    return ((float*)&v.m_vComponents)[i];
}
static __forceinline float lengthSquared3(const LocalM128& a)
{
    LocalM128 v = _mm_mul_ps(a, a);
    LocalM128 y = _mm_shuffle_ps(v, v, 0x55);
    LocalM128 z = _mm_shuffle_ps(v, v, 0xaa);
    float r;
    _mm_store_ss(&r, _mm_add_ss(z, _mm_add_ss(y, v)));
    return r;
}
static __forceinline bool validVelocities(hkpMotion* motion)
{
    const hkVector4& l = motion->m_kTranslationalVelocity;
    const hkVector4& a = motion->m_kAngularVelocity;
    LocalM128 fMinimumInputValue = DAT_010cbf80.m_vComponents;
    int bits = _mm_movemask_ps(_mm_cmplt_ps(_mm_and_ps(l.m_vComponents, DAT_01017d10.m_vComponents), fMinimumInputValue));
    bits &= _mm_movemask_ps(_mm_cmplt_ps(_mm_and_ps(a.m_vComponents, DAT_01017d10.m_vComponents), fMinimumInputValue));
    bits &= _mm_movemask_ps(_mm_cmpeq_ps(l.m_vComponents, l.m_vComponents));
    bits &= _mm_movemask_ps(_mm_cmpeq_ps(a.m_vComponents, a.m_vComponents));
    return (bits & 7) == 7;
}
static __forceinline void clampVelocities(hkpMotion* motion)
{
    hkMotionState* s = &motion->m_kMotionState;
    float maxAngularSquare = maxVelocity(*reinterpret_cast<const unsigned char*>(&s->m_fRestitution)) * maxVelocity(*reinterpret_cast<const unsigned char*>(&s->m_fRestitution));

    LocalM128 linear = (*reinterpret_cast<LocalM128*>(&motion->m_kTranslationalVelocity));
    float linearSquare = lengthSquared3(linear);
    float angularSquare = lengthSquared3((*reinterpret_cast<LocalM128*>(&motion->m_kAngularVelocity)));
    float maxLinearSquare = maxVelocity(*reinterpret_cast<const unsigned char*>(&s->m_fSurfaceFriction)) * maxVelocity(*reinterpret_cast<const unsigned char*>(&s->m_fSurfaceFriction));
    if (linearSquare > maxLinearSquare || linearSquare != linearSquare)
    {
        float inverse = 1.0f / (float)sqrt(linearSquare);
        (*reinterpret_cast<LocalM128*>(&motion->m_kTranslationalVelocity)) = _mm_mul_ps(splat(inverse * maxVelocity(*reinterpret_cast<const unsigned char*>(&s->m_fSurfaceFriction))), linear);
        if (linearSquare != linearSquare)
            (*reinterpret_cast<LocalM128*>(&motion->m_kTranslationalVelocity)) = DAT_01268370.m_vComponents;
    }
    if (angularSquare > maxAngularSquare || angularSquare != angularSquare)
    {
        float inverse = 1.0f / (float)sqrt(angularSquare);
        (*reinterpret_cast<LocalM128*>(&motion->m_kAngularVelocity)) =
            _mm_mul_ps(splat(inverse * maxVelocity(*reinterpret_cast<const unsigned char*>(&s->m_fRestitution))), (*reinterpret_cast<LocalM128*>(&motion->m_kAngularVelocity)));
        if (angularSquare != angularSquare)
            (*reinterpret_cast<LocalM128*>(&motion->m_kAngularVelocity)) = DAT_01268370.m_vComponents;
    }
}
static __forceinline float minf2(float a, float b)
{
    return b < a ? b : a;
}
static __forceinline float minf(float a, float b)
{
    return a > b ? b : a;
}
static __forceinline void updateTransform(const hkSweptTransform& history, hkTransform& world)
{
    reinterpret_cast<hkRotation*>(&world.m_row0)->hkRotation_set(history.m_qRotation1);
    LocalM128 local = history.m_vCenterOfMassLocal.m_vComponents;
    LocalM128 y = _mm_mul_ps(_mm_shuffle_ps(local, local, 0x55), world.m_row1);
    LocalM128 x = _mm_mul_ps(_mm_shuffle_ps(local, local, 0), world.m_row0);
    LocalM128 z = _mm_mul_ps(_mm_shuffle_ps(local, local, 0xaa), world.m_row2);
    world.m_row3 = _mm_sub_ps(history.m_vCenterOfMass1.m_vComponents, _mm_add_ps(_mm_add_ps(y, x), z));
}

// SIMD lvalue views preserve VC9's original velocity loads and register assignment.
static __forceinline void integrateMotion(hkpMotion* motion, const hkStepInfo* step)
{
    hkMotionState* s = &motion->m_kMotionState;
    if (!validVelocities(motion))
    {
        (*reinterpret_cast<LocalM128*>(&motion->m_kTranslationalVelocity)) = DAT_01268370.m_vComponents;
        (*reinterpret_cast<LocalM128*>(&motion->m_kAngularVelocity)) = DAT_01268370.m_vComponents;
    }
    s->m_kSweptTransform.m_vCenterOfMass0.m_vComponents = s->m_kSweptTransform.m_vCenterOfMass1.m_vComponents;
    elem(s->m_kSweptTransform.m_vCenterOfMass0, 3) = step->m_uiStartTime;
    LocalM128 linear = (*reinterpret_cast<LocalM128*>(&motion->m_kTranslationalVelocity));
    float speedSquare = lengthSquared3(linear);
    if (speedSquare > maxVelocity(*reinterpret_cast<const unsigned char*>(&s->m_fSurfaceFriction)) * maxVelocity(*reinterpret_cast<const unsigned char*>(&s->m_fSurfaceFriction)))
    {
        float inverse = 1.0f / (float)sqrt(speedSquare);
        (*reinterpret_cast<LocalM128*>(&motion->m_kTranslationalVelocity)) = _mm_mul_ps(splat(inverse * maxVelocity(*reinterpret_cast<const unsigned char*>(&s->m_fSurfaceFriction))), linear);
    }
    float dt = step->m_fTimeStep;
    s->m_kSweptTransform.m_vCenterOfMass1.m_vComponents = _mm_add_ps(_mm_mul_ps(splat(dt), (*reinterpret_cast<LocalM128*>(&motion->m_kTranslationalVelocity))), s->m_kSweptTransform.m_vCenterOfMass1.m_vComponents);
    elem(s->m_kSweptTransform.m_vCenterOfMass1, 3) = step->m_fInverseDeltaTime;
    __declspec(align(16)) hkQuaternion rotation;
    memcpy(&rotation, &s->m_kSweptTransform.m_qRotation1, sizeof(rotation));
    (*reinterpret_cast<LocalM128*>(&s->m_kSweptTransform.m_qRotation0)) = (*reinterpret_cast<LocalM128*>(&rotation));
    LocalM128 angular = (*reinterpret_cast<LocalM128*>(&motion->m_kAngularVelocity));
    hkVector4 angle;
    angle.q() = _mm_mul_ps(splat((float)(step->m_fTimeStep * 0.5)), angular);
    float halfSquare = (float)(lengthSquared3(angle.q()) * (4.0 / (3.1415927410125732 * 3.1415927410125732)));
    float limit = minf(maxVelocity(*reinterpret_cast<const unsigned char*>(&s->m_fRestitution)) * step->m_fTimeStep, 0.9f);
    float limitSquare = limit * limit;
    if (halfSquare <= limitSquare)
    {
        float fourth = halfSquare * halfSquare;
        angle.w = (float)((1.0 - ((double)0.822948f) * halfSquare - DAT_010ce4a0 * fourth) -
                          (halfSquare * DAT_010ce498) * fourth);
    }
    else
    {
        float root = (float)sqrt(halfSquare);
        float inverse = 1.0f / root;
        float factor = inverse * limit;
        (*reinterpret_cast<LocalM128*>(&motion->m_kAngularVelocity)) = _mm_mul_ps(splat(factor), angular);
        angle.q() = _mm_mul_ps(splat(factor), angle.q());
        halfSquare = limit * limit;
        float h = halfSquare;
        float fourth = h * h;
        angle.w = (float)((1.0 - ((double)0.822948f) * h - DAT_010ce4a0 * fourth) - (h * DAT_010ce498) * fourth);
    }
    rotation.setMul(*reinterpret_cast<const hkQuaternion*>(&angle), rotation);
    reinterpret_cast<hkVector4*>(&rotation)->normalize_005611c0();
    s->m_kDeltaAngle.m_vComponents = _mm_add_ps(angle.q(), angle.q());
    ((float*)&s->m_kDeltaAngle)[3] = (float)((float)sqrt(halfSquare) * 3.1415927410125732);
    (*reinterpret_cast<LocalM128*>(&s->m_kSweptTransform.m_qRotation1)) = (*reinterpret_cast<LocalM128*>(&rotation));
    updateTransform(s->m_kSweptTransform, s->m_kMotionTransform);
}
static __forceinline void applyGravity(hkpMotion* motion, const hkVector4* gravity, LocalM128 gravityFactor)
{
    LocalM128 impulse = _mm_mul_ps(_mm_shuffle_ps(gravityFactor, gravityFactor, 0), gravity->v);
    (*reinterpret_cast<LocalM128*>(&motion->m_kTranslationalVelocity)) = _mm_add_ps(impulse, (*reinterpret_cast<LocalM128*>(&motion->m_kTranslationalVelocity)));
}
static __forceinline void mul4(hkVector4& v, float s)
{
    LocalM128 t = _mm_load_ss(&s);
    v.m_vComponents = _mm_mul_ps(_mm_shuffle_ps(t, t, 0), v.m_vComponents);
}
static __forceinline void applyDamping(hkpMotion* motion, const hkStepInfo* step)
{
    float delta = step->m_fTimeStep;
    float zero = 0.0f;
    float linear = 1.0f - motion->m_kMotionState.m_fLinearDamping * delta;
    mul4(motion->m_kTranslationalVelocity, zero > linear ? zero : linear);
    float angular = 1.0f - motion->m_kMotionState.m_fAngularDamping * delta;
    mul4(motion->m_kAngularVelocity, zero > angular ? zero : angular);
}

static __forceinline bool rotationMoved(hkpMotion* motion, const DeactivationClass* config, int which)
{
    unsigned int packed = motion->m_auiDeactivationReferenceOrientations[which];
    hkVector4 previous;
    previous.x = (float)(((int)(packed & 255) - 128) * DAT_010ce488);
    previous.y = (float)(((int)((packed >> 8) & 255) - 128) * DAT_010ce488);
    previous.z = (float)(((int)((packed >> 16) & 255) - 128) * DAT_010ce488);
    previous.w = (float)(DAT_010ce488 * (float)((int)(packed >> 24) - 128));
    LocalM128 difference = _mm_sub_ps(previous.q(), (*reinterpret_cast<const LocalM128*>(&motion->m_kMotionState.m_kSweptTransform.m_qRotation1)));
    difference = _mm_mul_ps(difference, difference);
    LocalM128 pair = _mm_add_ps(_mm_shuffle_ps(difference, difference, 0x4e), difference);
    float square;
    _mm_store_ss(&square, _mm_add_ps(_mm_shuffle_ps(pair, pair, 0xb1), pair));
    int thresholdBits = (int)config->rotationThreshold[which] << 16;
    float threshold = *(float*)&thresholdBits;
    _ReadWriteBarrier();
    return square > threshold;
}
template <class T> struct Ref
{
    T* p;
    T* operator->() const
    {
        return p;
    }
    operator T*() const
    {
        return p;
    }
};
struct MotionList
{
    hkpMotion** p;
    hkpMotion* operator*() const
    {
        return *p;
    }
    void next()
    {
        ++p;
    }
};

// @fnv 0x00d28a30
// src: XBOX_PDB 0x00d28a30
extern "C" int __cdecl hkRigidMotionUtilApplyForcesAndStep(Ref<const SolverInfo> info, const hkStepInfo* step, Ref<const hkVector4> gravity,
                                    MotionList motions, int count, int offset)
{
    int minimum = 0x7fffffff;
    for (int remaining = count - 1; remaining >= 0; motions.next(), --remaining)
    {
        hkpMotion* motion = (hkpMotion*)((char*)*motions + offset);
        int gravityBits = (int)motion->m_fGravityFactor.m_value << 16;
        LocalM128 gravityFactor = _mm_load_ss((float*)&gravityBits);
        switch (*reinterpret_cast<const unsigned char*>(&motion->m_type))
        {
        case 6: {
            applyGravity(motion, gravity, gravityFactor);
            applyDamping(motion, step);
            hkVector4 localAngular;
            localAngular.hkVector4_setRotatedInverseDir(*reinterpret_cast<const hkRotation*>(&motion->m_kMotionState.m_kMotionTransform), motion->m_kAngularVelocity);
            LocalM128 inertia = motion->m_kInertiaAndMassInv.m_vComponents;
            LocalM128 reciprocal = _mm_rcp_ps(inertia);
            reciprocal =
                _mm_sub_ps(_mm_add_ps(reciprocal, reciprocal), _mm_mul_ps(_mm_mul_ps(reciprocal, inertia), reciprocal));
            localAngular.q() = _mm_mul_ps(reciprocal, localAngular.q());
            hkVector4 momentum;
            momentum.hkVector4_setRotatedDir(*reinterpret_cast<const hkRotation*>(&motion->m_kMotionState.m_kMotionTransform), localAngular);
            integrateMotion(motion, step);
            hkVector4 transformed;
            transformed.hkVector4_setRotatedInverseDir(*reinterpret_cast<const hkRotation*>(&motion->m_kMotionState.m_kMotionTransform), momentum);
            transformed.q() = _mm_mul_ps(transformed.q(), motion->m_kInertiaAndMassInv.m_vComponents);
            motion->m_kAngularVelocity.hkVector4_setRotatedDir(*reinterpret_cast<const hkRotation*>(&motion->m_kMotionState.m_kMotionTransform), transformed);
            clampVelocities(motion);
            break;
        }
        default:
            applyGravity(motion, gravity, gravityFactor);
        case 7:
            applyDamping(motion, step);
        case 4:
            integrateMotion(motion, step);
            break;
        case 5:
            continue;
        }
        unsigned int counter = (unsigned int)motion->m_ucDeactivationIntegrateCounter + 1;
        motion->m_ucDeactivationIntegrateCounter = (unsigned char)counter;
        if ((counter & 3) == 0)
        {
            int which;
            if ((counter & 15) != 0)
                which = 0;
            else if (counter == 256)
            {
                motion->m_ucDeactivationIntegrateCounter = 255;
                goto counters;
            }
            else
            {
                motion->m_ucDeactivationIntegrateCounter = 0;
                which = 1;
            }
            float radius = minf2(motion->m_kMotionState.m_fObjectRadius, 1.0f);
            float energy = lengthSquared3((*reinterpret_cast<LocalM128*>(&motion->m_kTranslationalVelocity))) +
                           radius * radius * lengthSquared3((*reinterpret_cast<LocalM128*>(&motion->m_kAngularVelocity)));
            float& refW = ((float*)&motion->m_akDeactivationReferencePositions[which])[3];
            refW = maxf2(refW, energy);
            hkVector4* reference = &motion->m_akDeactivationReferencePositions[which];
            hkQuaternion* rotation = &motion->m_kMotionState.m_kSweptTransform.m_qRotation1;
            LocalM128 difference = _mm_sub_ps(reference->quad, motion->m_kMotionState.m_kSweptTransform.m_vCenterOfMass1.m_vComponents);
            const DeactivationClass* config = &info->deactivation[motion->m_kMotionState.m_uiDeactivationClass];
            if (lengthSquared3(difference) > config->positionThreshold[which])
                goto reset;
            if (rotationMoved(motion, config, which))
            {
            reset:
                motion->m_ausDeactivationNumInactiveFrames[which] =
                    (unsigned short)((unsigned short)((unsigned short)info->selectFlags[which] << 7) |
                                     (unsigned short)(motion->m_ausDeactivationNumInactiveFrames[which] & 127))
                    << 7;
                hkVector4 center = *(hkVector4*)&motion->m_kMotionState.m_kSweptTransform.m_vCenterOfMass1;
                reference->quad = _mm_and_ps(center.q(), DAT_010cbfc0.m_vComponents);
                motion->m_auiDeactivationReferenceOrientations[which] = PackFloatsToUInt(rotation);
            }
            else
            {
                int count = motion->m_ausDeactivationNumInactiveFrames[which] & 127;
                motion->m_ausDeactivationNumInactiveFrames[which] =
                    (unsigned short)((count - (count >> 6) + 1) |
                                     (unsigned short)((unsigned short)((unsigned short)info->selectFlags[which] << 7) |
                                                      (unsigned short)count)
                                         << 7);
            }
        }
    counters:
        int inactive1 = motion->m_ausDeactivationNumInactiveFrames[1] & 127;
        int inactive0 = motion->m_ausDeactivationNumInactiveFrames[0] & 127;
        int inactive = inactive0 > inactive1 ? inactive0 : inactive1;
        if (minimum >= inactive)
            minimum = inactive;
    }
    return minimum;
}
}
