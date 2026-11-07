
// src/havok/physics/dynamics/constraint/bilateral/limitedhinge/hkplimitedhingeconstraintdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/bilateral/limitedhinge/hkplimitedhingeconstraintdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#define FNV64_HKVECTOR4_OWN_ASSIGN
#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../include/hkRotation.h"
#include "../../../../../../../include/hkTransform.h"
#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/hkpConstraintData.h"
#include "../../../../../../../include/hkpLimitedHingeConstraintData.h"

typedef float hkReal;

// @fnv 0x00cb8a90
void __thiscall hkpLimitedHingeConstraintData::SetConstraintFlag(int aiBitIndex)
{
    ((char*)this)[0xd6] = (char)(1 << aiBitIndex);
}

extern "C" void* __cdecl hkpConstraintData_getConstraintInfoUtil(void* self, int a, int b);

// @fnv 0x00cb8af0
void* __thiscall hkpLimitedHingeConstraintData::vf15(int arg)
{
    return hkpConstraintData_getConstraintInfoUtil((char*)this + 0x10, 0xcc, arg);
}

// @fnv 0x00cb8b10
void __thiscall hkpLimitedHingeConstraintData::vf09(int* apUnused, int* a2)
{
    a2[1] = 8;
    a2[0] = 80;
}

// @fnv 0x00cb8a70
void __thiscall hkpLimitedHingeConstraintData::vf03(float v)
{
    *(float*)((char*)this + 0xd8) = v;
}

// The shared header has no motor setter; keep its implementation as a local helper.
// @fnv 0x00cb8ac0
void __fastcall SetLimitedHingeMotor(hkpLimitedHingeConstraintData* self, void*, hkReferencedObject* pObject)
{
    if (pObject)
        pObject->addReference();
    hkReferencedObject* pOldObject = *(hkReferencedObject**)((char*)self + 0xb0);
    if (pOldObject)
        pOldObject->removeReference();
    *(hkReferencedObject**)((char*)self + 0xb0) = pObject;
}

extern int DAT_010c89e4;
extern int DAT_0102e388;

// @fnv 0x00cb8b40
void __fastcall DestroyLimitedHingeMotor(hkpLimitedHingeConstraintData* self, void*)
{
    hkReferencedObject* p = (hkReferencedObject*)*((int*)self + 44);
    *((int*)self) = (int)&DAT_010c89e4;
    if (p)
        p->removeReference();
    *((int*)self) = (int)&DAT_0102e388;
}

// Stores b at self+0xa2 and its negation at self+0xb6; if a is non-null, zeroes four floats at a->0x30->0x1c.
// @fnv 0x00cb8fe0
// src: HAVOK_LIB 0x00cb8fe0
void __fastcall hkpLimitedHingeConstraintData_setMotorActive(char* self, int, int a, bool b)
{
    self[0xa2] = b;
    self[0xb6] = !b;
    if (a)
    {
        int* p = *(int**)((char*)a + 0x30);
        if (p)
        {
            float* f = *(float**)((char*)p + 0x1c);
            if (f)
            {
                f[0] = 0.0f;
                f[1] = 0.0f;
                f[2] = 0.0f;
                f[3] = 0.0f;
            }
        }
    }
}

// @fnv 0x00cb8a80
float hkpLimitedHingeConstraintData::vf04()
{
    return *reinterpret_cast<const float*>(reinterpret_cast<const char*>(this) + 0xd8);
}

// @fnv 0x00cb8ab0
unsigned char __thiscall hkpLimitedHingeConstraintData::vf06()
{
    return reinterpret_cast<const unsigned char*>(this)[0xd6] >> 1;
}

// @fnv 0x00cb8b30
int hkpLimitedHingeConstraintData::vf08()
{
    return 2;
}

// @fnv 0x00cb9020
hkBool hkpLimitedHingeConstraintData::vf07() const
{
    const hkTransform& frameA = *reinterpret_cast<const hkTransform*>(m_kBridgeAtoms.pad0 + 0x10);
    const hkTransform& frameB = *reinterpret_cast<const hkTransform*>(m_kBridgeAtoms.pad0 + 0x50);
    return frameA.m_rotation.IsOrthonormal(1e-3f) &&
           frameB.m_rotation.IsOrthonormal(1e-3f) &&
           (!reinterpret_cast<const bool*>(this)[0xa2] || reinterpret_cast<const bool*>(this)[0xc2]);
}

struct FnvCpu_FUN_00cb9220_CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct FnvCpu_FUN_00cb9220_CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00cb9220_CpuAllocator* allocator;
};
FnvCpu_FUN_00cb9220_CpuAllocatorHolder* __cdecl hkMemoryRouter_getInstance();

// Destroys the hinge and, when requested, frees its recorded allocation size through the Havok allocator.
// @fnv 0x00cb9220
hkpLimitedHingeConstraintData* __fastcall DeleteLimitedHinge(hkpLimitedHingeConstraintData* self, void*, unsigned int flags)
{
    reinterpret_cast<void (__thiscall*)(hkpLimitedHingeConstraintData*)>(DestroyLimitedHingeMotor)(self);
    if (flags & 1)
    {
        FnvCpu_FUN_00cb9220_CpuAllocatorHolder* pAllocatorHolder = hkMemoryRouter_getInstance();
        pAllocatorHolder->allocator->Invoke(self, self->m_usMemSizeAndFlags);
    }
    return self;
}

struct FUN_00b5aea0_self
{
    void BSSimpleArray_ShadowSceneLight_1024_MoveItems(int* a, int* b, unsigned int c);
};

struct FUN_00cb9ce0_cls
{
    virtual void v0();
    virtual void* v1(int a);
    virtual void v2(int a);
    virtual int v3(int a, int b);
    virtual void v4(int a, int b);
    int m_004;
    int m_008;
    int m_00c;
    void BSSimpleArray_Resize(int a, int b);
};

// @fnv 0x00cb9ce0
// src: COMMUNITY 0x00cb9ce0
void FUN_00cb9ce0_cls::BSSimpleArray_Resize(int a, int b)
{
    if (m_004)
    {
        if (b == m_00c)
        {
            m_004 = v3(m_004, a);
        }
        else
        {
            int r = reinterpret_cast<int>(v1(a));
            reinterpret_cast<FUN_00b5aea0_self*>(this)->BSSimpleArray_ShadowSceneLight_1024_MoveItems(reinterpret_cast<int*>(r),
                                                                     reinterpret_cast<int*>(m_004), b);
            v2(m_004);
            m_004 = r;
        }
    }
    else
    {
        int r = reinterpret_cast<int>(v1(a));
        m_00c = a;
        m_004 = r;
    }
}

extern "C" __m128 _mm_setzero_ps(void);

__forceinline void hkVector4::setZero4()
{
    m_vComponents = _mm_setzero_ps();
}

__forceinline float& hkVector4::operator()(int i)
{
    return m_vComponents.m128_f32[i];
}

__forceinline const float& hkVector4::operator()(int i) const
{
    return m_vComponents.m128_f32[i];
}

__forceinline hkRotation::hkRotation() {}
__forceinline hkTransform::hkTransform() {}

__forceinline void hkRotation::setIdentity()
{
    m_kColumn0.setZero4();
    m_kColumn1.setZero4();
    m_kColumn2.setZero4();
    m_kColumn0(0) = 1.0f;
    m_kColumn1(1) = 1.0f;
    m_kColumn2(2) = 1.0f;
}

__forceinline void hkTransform::setIdentity()
{
    m_rotation.setIdentity();
    position.setZero4();
}

__forceinline hkpConstraintData::hkpConstraintData() throw()
{
    m_ulUserData = 0;
}

class __declspec(align(16)) PrismaticAtomConstruction
{
  public:
    PrismaticAtomConstruction() throw();

    unsigned short m_transformsType;
    unsigned short unk02;
    int unk04, unk08, unk0C;
    hkTransform m_kBodyALocalFrame;
    hkTransform m_kBodyBLocalFrame;
    unsigned short m_stabilizationType;
    volatile unsigned char m_stabilizationEnabled;
    volatile unsigned char m_motorEnabled;
    volatile short m_iInitializedOffset;
    volatile short m_iPreviousTargetAngleOffset;
    volatile float m_fTargetAngle;
    volatile unsigned long m_pMotor;
    unsigned short m_frictionType;
    unsigned char unkA2;
    volatile unsigned char m_frictionEnabled;
    volatile float m_fMaxFrictionTorque;
    unsigned short m_ang2dType;
    volatile unsigned char m_ang2dEnabled;
    volatile unsigned char m_ang2dFreeAxis;
    unsigned short m_angTypeB;
    volatile unsigned char m_angAxisB;
    unsigned char unkAF;
    unsigned short m_angTypeC;
    volatile unsigned char m_angAxisC;
    unsigned char unkB3;
    unsigned short m_limitType;
    volatile unsigned char m_limitEnabled;
    unsigned char unkB7;
    volatile float m_fMinAngle;
    volatile float m_fMaxAngle;
    int unkC0, unkC4, unkC8, unkCC;
};

// Type-6 cloning and vtable 0x010D0B3C identify this as prismatic construction.
class PrismaticConstraintConstruction : public hkpConstraintData
{
  public:
    PrismaticConstraintConstruction() throw();
    virtual ~PrismaticConstraintConstruction() throw();

    int unk0C;
    PrismaticAtomConstruction m_kBridgeAtoms;
};

// @fnv 0x00d4fe80
PrismaticConstraintConstruction::PrismaticConstraintConstruction() throw()
{
    m_kBridgeAtoms.m_kBodyALocalFrame.setIdentity();
    m_kBridgeAtoms.m_kBodyBLocalFrame.setIdentity();
    m_kBridgeAtoms.m_limitEnabled = 0;
    m_kBridgeAtoms.m_fMinAngle = -3.40282e+38f;
    m_kBridgeAtoms.m_frictionEnabled = 0;
    m_kBridgeAtoms.m_fMaxAngle = 3.40282e+38f;
    m_kBridgeAtoms.m_fMaxFrictionTorque = 0.0f;
    m_kBridgeAtoms.m_stabilizationEnabled = 0;
    m_kBridgeAtoms.m_fTargetAngle = 0.0f;
    m_kBridgeAtoms.m_pMotor = 0ul;
    m_kBridgeAtoms.m_motorEnabled = 0;
    m_kBridgeAtoms.m_ang2dEnabled = 0;
    m_kBridgeAtoms.m_iInitializedOffset = 0x40;
    m_kBridgeAtoms.m_iPreviousTargetAngleOffset = 0x44;
    m_kBridgeAtoms.m_ang2dFreeAxis = 3;
    m_kBridgeAtoms.m_angAxisB = 1;
    m_kBridgeAtoms.m_angAxisC = 2;
}

#include <math.h>
#include <string.h>
namespace limited_hinge_math
{
// Match the original compiler's SIMD intrinsic type without duplicating a game class.
// Exe 0x00cb8b60 SetLimitedHingeInWorldSpace: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C"
{
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_andnot_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_sub_ss(LocalM128, LocalM128);
    LocalM128 _mm_mul_ss(LocalM128, LocalM128);
    LocalM128 _mm_rsqrt_ss(LocalM128);
    LocalM128 _mm_cmpeq_ss(LocalM128, LocalM128);
    LocalM128 _mm_set_ss(float);
}
extern "C" LocalM128 _mm_setzero_ps(void);
}

struct ConstraintAtomHeader
{
    unsigned short m_type;
    unsigned short unk02;
    int unk04;
    int unk08;
    int unk0C;
};

// The shared atoms are opaque; the two transform frames occupy offsets 0x10 and 0x50 within them.
struct LimitedHingeLocalFrames
{
    ConstraintAtomHeader m_kHeader;
    hkTransform m_kBodyALocalFrame;
    hkTransform m_kBodyBLocalFrame;
};

namespace limited_hinge_math
{
static __forceinline hkReal hkFabs(hkReal r)
{
    return (hkReal)fabs(r);
}

static __forceinline void hkNormalize3(hkVector4& v)
{
    __m128 p = _mm_mul_ps(reinterpret_cast<__m128&>(v), reinterpret_cast<__m128&>(v));
    __m128 len2 = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
    len2 = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), len2);
    __m128 e = _mm_rsqrt_ss(len2);
    __m128 r =
        _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), e), _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(len2, e), e)));
    r = _mm_andnot_ps(_mm_cmpeq_ss(len2, _mm_set_ss(0.0f)), r);
    reinterpret_cast<__m128&>(v) = _mm_mul_ps(_mm_shuffle_ps(r, r, 0), reinterpret_cast<__m128&>(v));
}

static __forceinline void hkCalculatePerpendicularVector(const hkVector4& in, hkVector4& out)
{
    int min = 0;
    int ok1 = 1;
    int ok2 = 2;

    hkReal a0 = hkFabs(reinterpret_cast<const float*>(&in)[0]);
    hkReal a1 = hkFabs(reinterpret_cast<const float*>(&in)[1]);
    hkReal a2 = hkFabs(reinterpret_cast<const float*>(&in)[2]);

    if (a1 < a0)
    {
        ok1 = 0;
        min = 1;
        a0 = a1;
    }

    if (a2 < a0)
    {
        ok2 = min;
        min = 2;
    }

    reinterpret_cast<__m128&>(out) = _mm_setzero_ps();
    reinterpret_cast<float*>(&out)[ok1] = reinterpret_cast<const float*>(&in)[ok2];
    reinterpret_cast<float*>(&out)[ok2] = -reinterpret_cast<const float*>(&in)[ok1];
}

static __forceinline void hkSetCross(hkVector4& out, const hkVector4& v0, const hkVector4& v1)
{
    __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(reinterpret_cast<const __m128&>(v0), reinterpret_cast<const __m128&>(v0), 0xc9),
                               _mm_shuffle_ps(reinterpret_cast<const __m128&>(v1), reinterpret_cast<const __m128&>(v1), 0xd2));
    __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(reinterpret_cast<const __m128&>(v0), reinterpret_cast<const __m128&>(v0), 0xd2),
                               _mm_shuffle_ps(reinterpret_cast<const __m128&>(v1), reinterpret_cast<const __m128&>(v1), 0xc9));
    reinterpret_cast<__m128&>(out) = _mm_sub_ps(cross0, cross1);
}

}

// Builds perpendicular axes from the normalized axis and stores them with the pivot in m_kBridgeAtoms as local frames for body A and body B via their transforms.
// The shared header has no frame-setup method; keep its implementation as a local helper.
// @fnv 0x00cb8b60
void __fastcall SetLimitedHingeInWorldSpace(hkpLimitedHingeConstraintData* self, void*,
                                           const hkTransform& bodyATransform, const hkTransform& bodyBTransform,
                                           const hkVector4& pivot, const hkVector4& axis)
{
    using namespace limited_hinge_math;
    hkVector4 axisN;
    memcpy(&axisN, &axis, sizeof(axisN));
    hkNormalize3(axisN);

    hkVector4 perpToAxle1;
    hkCalculatePerpendicularVector(axisN, perpToAxle1);
    hkNormalize3(perpToAxle1);

    hkVector4 perpToAxle2;
    hkSetCross(perpToAxle2, axisN, perpToAxle1);

    LimitedHingeLocalFrames& t = *reinterpret_cast<LimitedHingeLocalFrames*>(&self->m_kBridgeAtoms);

    static_cast<hkVector4&>(t.m_kBodyALocalFrame.m_rotation.m_kColumn0)
        .setRotatedInverseDir(bodyATransform.m_rotation, axisN);
    static_cast<hkVector4&>(t.m_kBodyALocalFrame.m_rotation.m_kColumn1)
        .setRotatedInverseDir(bodyATransform.m_rotation, perpToAxle1);
    static_cast<hkVector4&>(t.m_kBodyALocalFrame.m_rotation.m_kColumn2)
        .setRotatedInverseDir(bodyATransform.m_rotation, perpToAxle2);
    static_cast<hkVector4&>(t.m_kBodyALocalFrame.position).SetTransformedPosition(bodyATransform, pivot);

    static_cast<hkVector4&>(t.m_kBodyBLocalFrame.m_rotation.m_kColumn0)
        .setRotatedInverseDir(bodyBTransform.m_rotation, axisN);
    static_cast<hkVector4&>(t.m_kBodyBLocalFrame.m_rotation.m_kColumn1)
        .setRotatedInverseDir(bodyBTransform.m_rotation, perpToAxle1);
    static_cast<hkVector4&>(t.m_kBodyBLocalFrame.m_rotation.m_kColumn2)
        .setRotatedInverseDir(bodyBTransform.m_rotation, perpToAxle2);
    static_cast<hkVector4&>(t.m_kBodyBLocalFrame.position).SetTransformedPosition(bodyBTransform, pivot);
}

extern "C" void _ReadWriteBarrier(void);

__forceinline void hkVector4::operator=(const hkVector4& other)
{
    typedef limited_hinge_math::LocalM128 Quad;
    reinterpret_cast<Quad&>(*this) = reinterpret_cast<const Quad&>(other);
}

__forceinline void hkVector4::normalize3()
{
    typedef limited_hinge_math::LocalM128 Quad;
    Quad& components = reinterpret_cast<Quad&>(*this);
    Quad mul = limited_hinge_math::_mm_mul_ps(components, components);
    Quad y = limited_hinge_math::_mm_shuffle_ps(mul, mul, 0x55);
    Quad xy = limited_hinge_math::_mm_add_ss(y, mul);
    Quad z = limited_hinge_math::_mm_shuffle_ps(mul, mul, 0xaa);
    Quad lenSq = limited_hinge_math::_mm_add_ss(z, xy);
    Quad r = limited_hinge_math::_mm_rsqrt_ss(lenSq);
    Quad zero = limited_hinge_math::_mm_set_ss(0.0f);
    Quad three = limited_hinge_math::_mm_set_ss(3.0f);
    Quad half = limited_hinge_math::_mm_set_ss(0.5f);
    Quad r_sq = limited_hinge_math::_mm_mul_ss(limited_hinge_math::_mm_mul_ss(lenSq, r), r);
    Quad diff = limited_hinge_math::_mm_sub_ss(three, r_sq);
    Quad half_r = limited_hinge_math::_mm_mul_ss(half, r);
    Quad nr = limited_hinge_math::_mm_mul_ss(half_r, diff);
    Quad mask = limited_hinge_math::_mm_cmpeq_ss(lenSq, zero);
    Quad inv = limited_hinge_math::_mm_andnot_ps(mask, nr);
    Quad inv4 = limited_hinge_math::_mm_shuffle_ps(inv, inv, 0);
    components = limited_hinge_math::_mm_mul_ps(inv4, components);
}

__forceinline void hkVector4::setCross(const hkVector4& first, const hkVector4& second)
{
    typedef limited_hinge_math::LocalM128 Quad;
    const Quad& a = reinterpret_cast<const Quad&>(first);
    const Quad& b = reinterpret_cast<const Quad&>(second);
    reinterpret_cast<Quad&>(*this) =
        _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2)),
                   _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9)));
}

// Sets the rotation and translation of m_kBodyALocalFrame and m_kBodyBLocalFrame from the given pivot and axis vectors.
// A frames view preserves aliasing between the input vectors and the destination transforms.
// @fnv 0x00cb8da0
void __fastcall SetLimitedHingeInBodySpace(hkpLimitedHingeConstraintData* self, void*, const hkVector4& pivotA, const hkVector4& pivotB,
                                         const hkVector4& axisA, const hkVector4& axisB,
                                         const hkVector4& axisAPerp, const hkVector4& axisBPerp)
{
    LimitedHingeLocalFrames& frames = *reinterpret_cast<LimitedHingeLocalFrames*>(&self->m_kBridgeAtoms);
    frames.m_kBodyALocalFrame.m_rotation.m_kColumn0 = axisA;
    frames.m_kBodyALocalFrame.m_rotation.m_kColumn0.normalize3();
    frames.m_kBodyALocalFrame.m_rotation.m_kColumn1 = axisAPerp;
    frames.m_kBodyALocalFrame.m_rotation.m_kColumn1.normalize3();
    frames.m_kBodyALocalFrame.m_rotation.m_kColumn2.setCross(
        frames.m_kBodyALocalFrame.m_rotation.m_kColumn0, frames.m_kBodyALocalFrame.m_rotation.m_kColumn1);
    frames.m_kBodyALocalFrame.position = pivotA;
    _ReadWriteBarrier();

    frames.m_kBodyBLocalFrame.m_rotation.m_kColumn0 = axisB;
    frames.m_kBodyBLocalFrame.m_rotation.m_kColumn0.normalize3();
    frames.m_kBodyBLocalFrame.m_rotation.m_kColumn1 = axisBPerp;
    frames.m_kBodyBLocalFrame.m_rotation.m_kColumn1.normalize3();
    limited_hinge_math::hkSetCross(frames.m_kBodyBLocalFrame.m_rotation.m_kColumn2,
                                   frames.m_kBodyBLocalFrame.m_rotation.m_kColumn0,
                                   frames.m_kBodyBLocalFrame.m_rotation.m_kColumn1);
    frames.m_kBodyBLocalFrame.position = pivotB;
}
