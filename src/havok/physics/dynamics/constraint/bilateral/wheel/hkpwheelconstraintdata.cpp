
// src/havok/physics/dynamics/constraint/bilateral/wheel/hkpwheelconstraintdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/bilateral/wheel/hkpwheelconstraintdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/hkMatrix3.h"
#include "../../../../../../../include/hkRotation.h"
#include "../../../../../../../include/hkTransform.h"
#include "../../../../../../../include/hkpWheelConstraintData.h"

typedef float hkReal;

// Reflection's wheel-atom fields are still opaque in the shared atoms header.
struct WheelAtomFields
{
    char suspensionHeader[0x10];
    hkTransform m_kBodyALocalFrame;
    hkTransform m_kBodyBLocalFrame;
    char steeringHeader[0x30];
    hkRotation m_kRotationA;
    hkRotation m_kRotationB;
    char trailingAtoms[0x10];
};

__forceinline float& hkVector4::operator()(int i) { return reinterpret_cast<float*>(&m_vComponents)[i]; }
__forceinline const float& hkVector4::operator()(int i) const { return reinterpret_cast<const float*>(&m_vComponents)[i]; }

// Writes 6 and 0x30 into a2[1] and a2[0] when a1 is nonzero, otherwise writes zeros to both.
// @fnv 0x00d4e580
// src: HAVOK_LIB 0x00d4e580
void __stdcall hkpWheelConstraintData_getRuntimeInfo(char a1, int* a2)
{
    if (a1)
    {
        a2[1] = 6;
        a2[0] = 0x30;
    }
    else
    {
        a2[1] = 0;
        a2[0] = 0;
    }
}

// The shared wheel header lacks these methods; free fastcall functions reserve EDX and preserve ECX=this.
void* __cdecl hkpConstraintData_getConstraintInfoUtil(void* a, int b, int c);
// @fnv 0x00d4e560
void* __fastcall PopulateWheelInfo(hkpWheelConstraintData* self, void*, int aiIndex)
{
    return hkpConstraintData_getConstraintInfoUtil(&self->m_kBridgeAtoms, 0x124, aiIndex);
}

// @fnv 0x00d4e5b0
// src: GUESS 0x00d4e5b0 (confidence: high)
int __cdecl hkpWheelConstraintData_ReturnConstant_9()
{
    return 9;
}

#include <xmmintrin.h>
#include <math.h>
namespace fnv_00d4e5c0 {
// Exe 0x00d4e5c0 UpdateWheelAtoms: retain this LocalM128 view; the CRT type does not preserve this unit.
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
    LocalM128 _mm_setzero_ps(void);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_sub_ss(LocalM128, LocalM128);
    LocalM128 _mm_mul_ss(LocalM128, LocalM128);
    LocalM128 _mm_rsqrt_ss(LocalM128);
    LocalM128 _mm_cmpeq_ss(LocalM128, LocalM128);
    LocalM128 _mm_set_ss(float);
}

static __forceinline LocalM128& simd(hkVector4& v) { return reinterpret_cast<LocalM128&>(v.m_vComponents); }
static __forceinline const LocalM128& simd(const hkVector4& v) { return reinterpret_cast<const LocalM128&>(v.m_vComponents); }

static __forceinline hkReal hkFabs(hkReal r)
{
    return (hkReal)fabs(r);
}

static __forceinline void hkNormalize3(hkVector4& v)
{
    LocalM128 p = _mm_mul_ps(simd(v), simd(v));
    LocalM128 len2 = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
    len2 = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), len2);
    LocalM128 e = _mm_rsqrt_ss(len2);
    LocalM128 r =
        _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), e), _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(len2, e), e)));
    r = _mm_andnot_ps(_mm_cmpeq_ss(len2, _mm_set_ss(0.0f)), r);
    simd(v) = _mm_mul_ps(_mm_shuffle_ps(r, r, 0), simd(v));
}

static __forceinline void hkCalculatePerpendicularVector(const hkVector4& in, hkVector4& out)
{
    int min = 0;
    int ok1 = 1;
    int ok2 = 2;

    hkReal a0 = hkFabs(in(0));
    hkReal a1 = hkFabs(in(1));
    hkReal a2 = hkFabs(in(2));

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

    simd(out) = _mm_setzero_ps();
    out(ok1) = in(ok2);
    out(ok2) = -in(ok1);
}

static __forceinline void hkSetCross(hkVector4& out, const hkVector4& v0, const hkVector4& v1)
{
    LocalM128 b = simd(v1);
    LocalM128 a = simd(v0);
    LocalM128 cross0 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2));
    LocalM128 cross1 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9));
    simd(out) = _mm_sub_ps(cross0, cross1);
}

static __forceinline void hkSetCrossDirect(hkVector4& out, const hkVector4& v0, const hkVector4& v1)
{
    LocalM128 cross0 = _mm_mul_ps(_mm_shuffle_ps(simd(v0), simd(v0), 0xc9),
                               _mm_shuffle_ps(simd(v1), simd(v1), 0xd2));
    LocalM128 cross1 = _mm_mul_ps(_mm_shuffle_ps(simd(v0), simd(v0), 0xd2),
                               _mm_shuffle_ps(simd(v1), simd(v1), 0xc9));
    simd(out) = _mm_sub_ps(cross0, cross1);
}

static __forceinline void hkSetRotatedInverseDir(hkVector4& out, const hkTransform& t, const hkVector4& v)
{
    out.setRotatedInverseDir(t.m_rotation, v);
}

static __forceinline void hkSetTransformedInversePos(hkVector4& out, const hkTransform& t, const hkVector4& p)
{
    hkVector4 s;
    simd(s) = _mm_sub_ps(reinterpret_cast<const LocalM128&>(p), reinterpret_cast<const LocalM128&>(t.m_vTranslation));
    hkSetRotatedInverseDir(out, t, s);
}

static __forceinline void hkSetIdentity(hkRotation& r)
{
    LocalM128 zero = _mm_setzero_ps();
    simd(r.m_kColumn0) = zero;
    simd(r.m_kColumn1) = zero;
    simd(r.m_kColumn2) = zero;
    r.m_kColumn0(0) = 1.0f;
    r.m_kColumn1(1) = 1.0f;
    r.m_kColumn2(2) = 1.0f;
}

// Normalizes axle and steering axes, then writes body local frames, rotations, and axle/steering directions into m_kBridgeAtoms.
// @fnv 0x00d4e5c0
void __fastcall UpdateWheelAtoms(hkpWheelConstraintData* self, void*, const hkTransform& bodyATransform, const hkTransform& bodyBTransform,
                                                const hkVector4& pivot, const hkVector4& axle,
                                                const hkVector4& suspensionAxis, const hkVector4& steeringAxis)
{
    hkVector4 axleN;
    reinterpret_cast<unsigned int*>(&axleN)[0] = reinterpret_cast<const unsigned int*>(&axle)[0];
    reinterpret_cast<unsigned int*>(&axleN)[1] = reinterpret_cast<const unsigned int*>(&axle)[1];
    reinterpret_cast<unsigned int*>(&axleN)[2] = reinterpret_cast<const unsigned int*>(&axle)[2];
    reinterpret_cast<unsigned int*>(&axleN)[3] = reinterpret_cast<const unsigned int*>(&axle)[3];
    hkNormalize3(axleN);

    hkVector4 steeringN;
    reinterpret_cast<unsigned int*>(&steeringN)[0] = reinterpret_cast<const unsigned int*>(&steeringAxis)[0];
    reinterpret_cast<unsigned int*>(&steeringN)[1] = reinterpret_cast<const unsigned int*>(&steeringAxis)[1];
    reinterpret_cast<unsigned int*>(&steeringN)[2] = reinterpret_cast<const unsigned int*>(&steeringAxis)[2];
    reinterpret_cast<unsigned int*>(&steeringN)[3] = reinterpret_cast<const unsigned int*>(&steeringAxis)[3];
    hkNormalize3(steeringN);

    WheelAtomFields& atoms = *reinterpret_cast<WheelAtomFields*>(&self->m_kBridgeAtoms);

    hkSetTransformedInversePos(atoms.m_kBodyALocalFrame.position, bodyATransform, pivot);
    hkSetTransformedInversePos(atoms.m_kBodyBLocalFrame.position, bodyBTransform, pivot);
    hkSetIdentity(atoms.m_kBodyALocalFrame.m_rotation);
    hkSetRotatedInverseDir(atoms.m_kBodyBLocalFrame.m_rotation.m_kColumn0, bodyBTransform, suspensionAxis);
    hkCalculatePerpendicularVector(atoms.m_kBodyBLocalFrame.m_rotation.m_kColumn0,
                                   atoms.m_kBodyBLocalFrame.m_rotation.m_kColumn1);
    hkNormalize3(atoms.m_kBodyBLocalFrame.m_rotation.m_kColumn1);
    hkSetCross(atoms.m_kBodyBLocalFrame.m_rotation.m_kColumn2, atoms.m_kBodyBLocalFrame.m_rotation.m_kColumn0,
               atoms.m_kBodyBLocalFrame.m_rotation.m_kColumn1);

    {
        hkRotation& rotA = atoms.m_kRotationA;
        hkRotation& rotB = atoms.m_kRotationB;
        hkSetRotatedInverseDir(rotA.m_kColumn0, bodyATransform, axleN);
        hkSetRotatedInverseDir(rotB.m_kColumn0, bodyBTransform, axleN);
        simd(self->m_kAxleDirectionInBodyB) = simd(rotB.m_kColumn0);
        hkSetRotatedInverseDir(rotA.m_kColumn1, bodyATransform, steeringN);
        hkSetRotatedInverseDir(rotB.m_kColumn1, bodyBTransform, steeringN);
        simd(self->m_kSteeringDirectionInBodyB) = simd(rotB.m_kColumn1);
        hkSetCross(rotA.m_kColumn2, rotA.m_kColumn0, rotA.m_kColumn1);
        hkSetCrossDirect(rotB.m_kColumn2, rotB.m_kColumn0, rotB.m_kColumn1);
    }
}
}  // namespace fnv_00d4e5c0

namespace fnv_00d4e960 {
// Exe 0x00d4e5c0 UpdateWheelAtoms: retain this LocalM128 view; the CRT type does not preserve this unit.
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
    LocalM128 _mm_setzero_ps(void);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_sub_ss(LocalM128, LocalM128);
    LocalM128 _mm_mul_ss(LocalM128, LocalM128);
    LocalM128 _mm_rsqrt_ss(LocalM128);
    LocalM128 _mm_cmpeq_ss(LocalM128, LocalM128);
    LocalM128 _mm_set_ss(float);
}

static __forceinline LocalM128& simd(hkVector4& v) { return reinterpret_cast<LocalM128&>(v.m_vComponents); }
static __forceinline const LocalM128& simd(const hkVector4& v) { return reinterpret_cast<const LocalM128&>(v.m_vComponents); }

static __forceinline hkReal hkFabs(hkReal r)
{
    return (hkReal)fabs(r);
}

static __forceinline void hkNormalize3(hkVector4& v)
{
    LocalM128 p = _mm_mul_ps(simd(v), simd(v));
    LocalM128 len2 = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
    len2 = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), len2);
    LocalM128 e = _mm_rsqrt_ss(len2);
    LocalM128 r =
        _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), e), _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(len2, e), e)));
    r = _mm_andnot_ps(_mm_cmpeq_ss(len2, _mm_set_ss(0.0f)), r);
    simd(v) = _mm_mul_ps(_mm_shuffle_ps(r, r, 0), simd(v));
}

static __forceinline void hkCalculatePerpendicularVector(const hkVector4& in, hkVector4& out)
{
    int min = 0;
    int ok1 = 1;
    int ok2 = 2;

    hkReal a0 = hkFabs(in(0));
    hkReal a1 = hkFabs(in(1));
    hkReal a2 = hkFabs(in(2));

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

    simd(out) = _mm_setzero_ps();
    out(ok1) = in(ok2);
    out(ok2) = -in(ok1);
}

static __forceinline hkReal getA(const hkVector4& v, int i)
{
    return reinterpret_cast<const hkReal*>(&simd(v))[i];
}
static __forceinline hkReal getP(const hkVector4& v, int i)
{
    const hkReal* p = reinterpret_cast<const hkReal*>(&v) + i;
    return *p;
}
static __forceinline hkReal getQ(const hkVector4& v, int i)
{
    const hkReal* p = reinterpret_cast<const hkReal*>(&v);
    const hkReal* q = p + i;
    return *q;
}
static __forceinline hkReal& refA(hkVector4& v, int i)
{
    return reinterpret_cast<hkReal*>(&simd(v))[i];
}
static __forceinline hkReal& refP(hkVector4& v, int i)
{
    hkReal* p = reinterpret_cast<hkReal*>(&v) + i;
    return *p;
}
static __forceinline hkReal& refQ(hkVector4& v, int i)
{
    hkReal* p = reinterpret_cast<hkReal*>(&v);
    hkReal* q = p + i;
    return *q;
}
static __forceinline void perpI1(const hkVector4& in, hkVector4& out)
{
    int min = 0;
    int ok1 = 1;
    int ok2 = 2;
    hkReal a0 = hkFabs(in(0));
    hkReal a1 = hkFabs(in(1));
    hkReal a2 = hkFabs(in(2));
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
    simd(out) = _mm_setzero_ps();
    refA(out, ok1) = getA(in, ok2);
    refQ(out, ok2) = -getQ(in, ok1);
}

static __forceinline void perpI2(const hkVector4& in, hkVector4& out)
{
    int min = 0;
    int ok1 = 1;
    int ok2 = 2;
    hkReal a0 = hkFabs(in(0));
    hkReal a1 = hkFabs(in(1));
    hkReal a2 = hkFabs(in(2));
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
    simd(out) = _mm_setzero_ps();
    refA(out, ok1) = getA(in, ok2);
    refA(out, ok2) = -getA(in, ok1);
}

static __forceinline void hkSetCross(hkVector4& out, const hkVector4& v0, const hkVector4& v1)
{
    const LocalM128& b = simd(v1);
    const LocalM128& a = simd(v0);
    LocalM128 c0 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2));
    LocalM128 c1 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9));
    simd(out) = _mm_sub_ps(c0, c1);
}

static __forceinline void hkSetRotatedInverseDir(hkVector4& out, const hkTransform& t, const hkVector4& v)
{
    out.setRotatedInverseDir(t.m_rotation, v);
}

static __forceinline void hkSetTransformedInversePos(hkVector4& out, const hkTransform& t, const hkVector4& p)
{
    hkVector4 s;
    simd(s) = _mm_sub_ps(reinterpret_cast<const LocalM128&>(p), reinterpret_cast<const LocalM128&>(t.m_vTranslation));
    hkSetRotatedInverseDir(out, t, s);
}

static __forceinline void hkSetIdentity(hkRotation& r)
{
    LocalM128 zero = _mm_setzero_ps();
    simd(r.m_kColumn0) = zero;
    simd(r.m_kColumn1) = zero;
    simd(r.m_kColumn2) = zero;
    r.m_kColumn0(0) = 1.0f;
    r.m_kColumn1(1) = 1.0f;
    r.m_kColumn2(2) = 1.0f;
}

static __forceinline void hkSetCrossC(hkVector4& out, const hkVector4& v0, const hkVector4& v1)
{
    LocalM128 a = simd(v0);
    LocalM128 b = simd(v1);
    LocalM128 cross0 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2));
    LocalM128 cross1 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9));
    simd(out) = _mm_sub_ps(cross0, cross1);
}
static __forceinline void hkSetCrossF(hkVector4& out, const hkVector4& v0, const hkVector4& v1)
{
    LocalM128 b = simd(v1);
    LocalM128 a = simd(v0);
    LocalM128 cross0 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2));
    LocalM128 cross1 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9));
    simd(out) = _mm_sub_ps(cross0, cross1);
}
static __forceinline void hkSetCrossD(hkVector4& out, const hkVector4& v0, const hkVector4& v1)
{
    hkVector4 t;
    hkSetCross(t, v0, v1);
    simd(out) = simd(t);
}

static __forceinline hkVector4& rotationColumn(hkRotation& r, int i)
{
    return (&r.m_kColumn0)[i];
}

static __forceinline void hkSetVec(hkVector4& out, const hkVector4& v)
{
    simd(out) = reinterpret_cast<const LocalM128&>(v);
}

// Populates wheel constraint atoms and axle/steering directions from pivot, axle, suspension, and steering vectors.
// @fnv 0x00d4e960
void __fastcall SetWheelInBodySpace(hkpWheelConstraintData* self, void*, const hkVector4& pivotA, const hkVector4& pivotB, const hkVector4& axleA,
                                         const hkVector4& axleB, const hkVector4& suspensionB,
                                         const hkVector4& steeringB)
{
    WheelAtomFields& atoms = *reinterpret_cast<WheelAtomFields*>(&self->m_kBridgeAtoms);

    hkSetVec(atoms.m_kBodyALocalFrame.position, pivotA);
    hkSetVec(atoms.m_kBodyBLocalFrame.position, pivotB);
    hkSetIdentity(atoms.m_kBodyALocalFrame.m_rotation);

    hkSetVec(atoms.m_kBodyBLocalFrame.m_rotation.m_kColumn0, suspensionB);
    perpI1(atoms.m_kBodyBLocalFrame.m_rotation.m_kColumn0, atoms.m_kBodyBLocalFrame.m_rotation.m_kColumn1);
    hkNormalize3(atoms.m_kBodyBLocalFrame.m_rotation.m_kColumn1);
    hkSetCrossF(atoms.m_kBodyBLocalFrame.m_rotation.m_kColumn2, atoms.m_kBodyBLocalFrame.m_rotation.m_kColumn0,
                atoms.m_kBodyBLocalFrame.m_rotation.m_kColumn1);

    hkVector4 axleAn;
    hkSetVec(axleAn, axleA);
    hkNormalize3(axleAn);
    simd(atoms.m_kRotationA.m_kColumn0) = simd(axleAn);

    hkVector4 axleBn;
    hkSetVec(axleBn, axleB);
    hkSetVec(rotationColumn(atoms.m_kRotationB, 0), axleB);
    hkNormalize3(axleBn);
    simd(atoms.m_kRotationB.m_kColumn0) = simd(axleBn);
    simd(self->m_kAxleDirectionInBodyB) = simd(axleBn);

    hkVector4& baseIn = atoms.m_kRotationA.m_kColumn0;
    perpI2(baseIn, atoms.m_kRotationA.m_kColumn1);
    hkNormalize3(atoms.m_kRotationA.m_kColumn1);
    hkSetVec(atoms.m_kRotationB.m_kColumn1, steeringB);
    hkNormalize3(atoms.m_kRotationB.m_kColumn1);
    simd(self->m_kSteeringDirectionInBodyB) =
        simd(atoms.m_kRotationB.m_kColumn1);

    hkSetCrossF(atoms.m_kRotationA.m_kColumn2, atoms.m_kRotationA.m_kColumn0, atoms.m_kRotationA.m_kColumn1);
    hkSetCross(atoms.m_kRotationB.m_kColumn2, atoms.m_kRotationB.m_kColumn0, atoms.m_kRotationB.m_kColumn1);
}
}  // namespace fnv_00d4e960

extern int DAT_010d0a64;
extern "C" void ConstructWheelAtoms();

static __forceinline void InitializeWheelRotation(hkRotation& r)
{
    __m128 zero = _mm_setzero_ps();
    r.m_kColumn0.m_vComponents = zero;
    r.m_kColumn1.m_vComponents = zero;
    r.m_kColumn2.m_vComponents = zero;
    reinterpret_cast<volatile float*>(&r.m_kColumn0)[0] = 1.0f;
    reinterpret_cast<volatile float*>(&r.m_kColumn1)[1] = 1.0f;
    reinterpret_cast<volatile float*>(&r.m_kColumn2)[2] = 1.0f;
}

// The shared wheel and atoms headers lack constructor declarations, so initialize the shared storage here.
// @fnv 0x00d4edc0
hkpWheelConstraintData* __fastcall ConstructWheel(hkpWheelConstraintData* self, void*)
{
    self->m_sReferenceCount = 1;
    self->m_ulUserData = 0;
    *reinterpret_cast<int**>(self) = &DAT_010d0a64;
    typedef void (__thiscall *AtomsConstructor)(hkpWheelConstraintDataAtoms*);
    reinterpret_cast<AtomsConstructor>(ConstructWheelAtoms)(&self->m_kBridgeAtoms);

    char* atoms = reinterpret_cast<char*>(self);
    *reinterpret_cast<float*>(atoms + 0xa4) = -0.5f;
    atoms[0xa2] = 0;
    *reinterpret_cast<float*>(atoms + 0xa8) = 0.5f;
    atoms[0xae] = 0;
    atoms[0xba] = 1;
    atoms[0xbe] = 2;
    *reinterpret_cast<float*>(atoms + 0xb4) = *reinterpret_cast<float*>(atoms + 0xb0) = 0.0f;
    InitializeWheelRotation(*reinterpret_cast<hkRotation*>(atoms + 0xd0));
    InitializeWheelRotation(*reinterpret_cast<hkRotation*>(atoms + 0x100));
    InitializeWheelRotation(*reinterpret_cast<hkRotation*>(atoms + 0x20));
    __m128 zero = _mm_setzero_ps();
    *reinterpret_cast<__m128*>(atoms + 0x50) = zero;
    InitializeWheelRotation(*reinterpret_cast<hkRotation*>(atoms + 0x60));
    *reinterpret_cast<__m128*>(atoms + 0x90) = zero;
    *reinterpret_cast<volatile unsigned char*>(atoms + 0x132) = 0;
    return self;
}

extern "C" void IsOrthonormal();
extern float DAT_01267e30;

// Transform IsOrthonormal is not declared by the shared header yet; retain its original thiscall target.
typedef hkBool (hkTransform::*MemFn)(float tol);

// Returns true if IsOrthonormal passes with 0.001f on both body frames and the two rotation-based transforms and m_suspensionMin <= m_suspensionMax.
// @fnv 0x00d4eec0
hkBool* __fastcall IsWheelValid(hkpWheelConstraintData* self, void*, hkBool* result)
{
    const char* atoms = self->m_kBridgeAtoms.pad0;
    const hkTransform& bodyAFrame = *reinterpret_cast<const hkTransform*>(atoms + 0x10);
    const hkTransform& bodyBFrame = *reinterpret_cast<const hkTransform*>(atoms + 0x50);
    const hkRotation& rotationA = *reinterpret_cast<const hkRotation*>(atoms + 0xc0);
    const hkRotation& rotationB = *reinterpret_cast<const hkRotation*>(atoms + 0xf0);
    MemFn fn;
    *(void**)&fn = (void*)IsOrthonormal;

    // Pointer-slot storage keeps the original 64-byte stack frames without introducing a /GS array buffer.
    __declspec(align(16)) void* t1Storage[sizeof(hkTransform) / sizeof(void*)];
    __declspec(align(16)) void* t2Storage[sizeof(hkTransform) / sizeof(void*)];
    hkTransform& t1 = *reinterpret_cast<hkTransform*>(t1Storage);
    hkTransform& t2 = *reinterpret_cast<hkTransform*>(t2Storage);

    t1.m_rotation.m_kColumn0.m_vComponents =
        rotationA.m_kColumn0.m_vComponents;
    t1.m_rotation.m_kColumn1.m_vComponents =
        rotationA.m_kColumn1.m_vComponents;
    t1.m_rotation.m_kColumn2.m_vComponents =
        rotationA.m_kColumn2.m_vComponents;
    reinterpret_cast<unsigned int*>(&t1.m_vTranslation)[0] = reinterpret_cast<const unsigned int*>(&DAT_01267e30)[0];
    reinterpret_cast<unsigned int*>(&t1.m_vTranslation)[1] = reinterpret_cast<const unsigned int*>(&DAT_01267e30)[1];
    reinterpret_cast<unsigned int*>(&t1.m_vTranslation)[2] = reinterpret_cast<const unsigned int*>(&DAT_01267e30)[2];
    reinterpret_cast<unsigned int*>(&t1.m_vTranslation)[3] = reinterpret_cast<const unsigned int*>(&DAT_01267e30)[3];

    t2.m_rotation.m_kColumn0.m_vComponents =
        rotationB.m_kColumn0.m_vComponents;
    t2.m_rotation.m_kColumn1.m_vComponents =
        rotationB.m_kColumn1.m_vComponents;
    t2.m_rotation.m_kColumn2.m_vComponents =
        rotationB.m_kColumn2.m_vComponents;
    reinterpret_cast<unsigned int*>(&t2.m_vTranslation)[0] = reinterpret_cast<const unsigned int*>(&DAT_01267e30)[0];
    reinterpret_cast<unsigned int*>(&t2.m_vTranslation)[1] = reinterpret_cast<const unsigned int*>(&DAT_01267e30)[1];
    reinterpret_cast<unsigned int*>(&t2.m_vTranslation)[2] = reinterpret_cast<const unsigned int*>(&DAT_01267e30)[2];
    reinterpret_cast<unsigned int*>(&t2.m_vTranslation)[3] = reinterpret_cast<const unsigned int*>(&DAT_01267e30)[3];

    result->m_cBooleanValue = static_cast<char>((((hkTransform*)&bodyAFrame)->*fn)(0.001f) &&
            (((hkTransform*)&bodyBFrame)->*fn)(0.001f) &&
            (((hkTransform*)&t1)->*fn)(0.001f) && (((hkTransform*)&t2)->*fn)(0.001f) &&
            (*reinterpret_cast<const float*>(atoms + 0x94) <= *reinterpret_cast<const float*>(atoms + 0x98)));
    return result;
}
