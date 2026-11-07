
// src/havok/physics/dynamics/constraint/bilateral/prismatic/hkpprismaticconstraintdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/bilateral/prismatic/hkpprismaticconstraintdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Preserve the float-only SIMD representation used by the matched routines.
#define _INCLUDED_MM2
// Exe 0x00d4f8f0 setInWorldSpace: retain this LocalM128 view; the CRT type does not preserve this unit.
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

#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/hkRotation.h"
#include "../../../../../../../include/hkTransform.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkpConstraintData.h"
#include "../../../../../../../include/hkpSetLocalTransformsConstraintAtom.h"

typedef float hkReal;

// No include/hkpPrismaticConstraintData.h exists yet; retain its reflected 0xD0 layout and methods here.
class hkpPrismaticConstraintData : public hkpConstraintData
{
public:
    char padC[4];
    char m_kBridgeAtoms[0xC0];

    __declspec(noinline) virtual ~hkpPrismaticConstraintData() throw();
    static void operator delete(void* pItem) throw();
    hkpPrismaticConstraintData* DestroyObject(unsigned int uFlags) throw();
    void* __thiscall getConstraintInfo_00d4f880(int iFirst);
    void setInWorldSpace(const hkTransform& kBodyATransform, const hkTransform& kBodyBTransform,
                         const hkVector4& kPivot, const hkVector4& kAxis);
    hkBool IsValid() const;
    void setInBodySpace(const hkVector4& kPivotA, const hkVector4& kPivotB,
                        const hkVector4& kAxisA, const hkVector4& kAxisB,
                        const hkVector4& kAxisAPerp, const hkVector4& kAxisBPerp);
};


extern "C" void* __cdecl hkpConstraintData_getConstraintInfoUtil(void* self, int a, void* b);

// @fnv 0x00d4f880
// src: HAVOK_LIB 0x00d4f880
void* __thiscall hkpPrismaticConstraintData::getConstraintInfo_00d4f880(int a)
{
    return hkpConstraintData_getConstraintInfoUtil((char*)this + 0x10, 0xc0, (void*)a);
}

// @fnv 0x00d4f8a0
// src: HAVOK_LIB 0x00d4f8a0
void __stdcall hkpPrismaticConstraintData_getRuntimeInfo(int aiUnused, hkpPrismaticConstraintData* apConstraintData)
{
    *(int*)((char*)apConstraintData + 4) = 8;
    *(int*)((char*)apConstraintData + 0) = 0x48;
}

extern int DAT_010d0b3c;
extern int DAT_0102e388;
inline hkpConstraintData::~hkpConstraintData() throw() {}

// Releases the motor stored at +0xAC before destroying the constraint base.
// @fnv 0x00d4f8d0
hkpPrismaticConstraintData::~hkpPrismaticConstraintData() throw()
{
    hkReferencedObject* motor = *reinterpret_cast<hkReferencedObject**>(m_kBridgeAtoms + 0x9C);
    *reinterpret_cast<int**>(this) = &DAT_010d0b3c;
    if (motor)
        motor->removeReference();
    *reinterpret_cast<int**>(this) = &DAT_0102e388;
}

// FUN_00d4f8c0: cdecl constant-return leaf (mov eax,6; ret)
// @fnv 0x00d4f8c0
// src: GUESS 0x00d4f8c0 (confidence: high)
int Object_ReturnSix_00d4f8c0()
{
    return 6;
}

extern float DAT_01017d00;

// The old transform view called hkRotation::IsOrthonormal at 0x00CB2E70 (also bound by the hinge unit).
// @fnv 0x00d4fdd0
hkBool hkpPrismaticConstraintData::IsValid() const
{
    const hkpSetLocalTransformsConstraintAtom& transforms =
        *reinterpret_cast<const hkpSetLocalTransformsConstraintAtom*>(m_kBridgeAtoms);
    return transforms.m_kBodyALocalFrame.m_rotation.IsOrthonormal(DAT_01017d00) &&
           transforms.m_kBodyBLocalFrame.m_rotation.IsOrthonormal(DAT_01017d00) &&
           *reinterpret_cast<const float*>(m_kBridgeAtoms + 0xB8) <= *reinterpret_cast<const float*>(m_kBridgeAtoms + 0xBC);
}

inline void hkpPrismaticConstraintData::operator delete(void* p) throw()
{
    hkMemoryRouter::getInstance().heap().blockFree(
        p, static_cast<hkpPrismaticConstraintData*>(p)->m_usMemSizeAndFlags);
}

// Runs the destructor and frees the allocation when bit 0 is set; returns this.
// @fnv 0x00d4ffd0
hkpPrismaticConstraintData* hkpPrismaticConstraintData::DestroyObject(unsigned int flags) throw()
{
    this->hkpPrismaticConstraintData::~hkpPrismaticConstraintData();
    if (flags & 1)
        hkpPrismaticConstraintData::operator delete(this);
    return this;
}

extern int DAT_010d0b9c;

struct Embedded
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    void Run();
};

struct FUN_00d50c50
{
    int* vtbl;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    Embedded mSub;
    hkReferencedObject** mArr;
    int mCount;
    ~FUN_00d50c50();
};

// @fnv 0x00d50c50
FUN_00d50c50::~FUN_00d50c50()
{
    vtbl = &DAT_010d0b9c;
    for (int i = 0; i < mCount; ++i)
    {
        mArr[i]->removeReference();
    }
    mSub.Run();
    vtbl = &DAT_0102e388;
}

// Raw SIMD arithmetic temporaries: these expose no game-class methods or ABI.
union SimdLaneVector
{
    LocalM128 m_vComponents;

    __forceinline float& operator()(int i)
    {
        return reinterpret_cast<float*>(&m_vComponents)[i];
    }
    __forceinline const float& operator()(int i) const
    {
        return reinterpret_cast<const float*>(&m_vComponents)[i];
    }
};

struct SimdColumnMatrix
{
    SimdLaneVector m_col[3];
};

static __forceinline void hkNormalize3(SimdLaneVector& v)
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

static __forceinline void hkSetCross(SimdLaneVector& out, const SimdLaneVector& v0, const SimdLaneVector& v1)
{
    LocalM128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xc9),
                               _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2));
    LocalM128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xd2),
                               _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9));
    out.m_vComponents = _mm_sub_ps(cross0, cross1);
}

// SIMD frame storage view: the 16-byte atom prefix is followed by two 64-byte local frames.
struct PrismaticFrameStorage
{
    char atomPrefix[0x10];
    SimdColumnMatrix rotationA;
    hkVector4 translationA;
    SimdColumnMatrix rotationB;
    hkVector4 translationB;
};

// Stores pivotA/pivotB as translations and builds rotation matrices from axis/axisPerp pairs into m_kBridgeAtoms.
// @fnv 0x00d4fba0
void hkpPrismaticConstraintData::setInBodySpace(const hkVector4& pivotA, const hkVector4& pivotB,
                                                const hkVector4& axisA, const hkVector4& axisB,
                                                const hkVector4& axisAPerp, const hkVector4& axisBPerp)
{
    PrismaticFrameStorage& t = *reinterpret_cast<PrismaticFrameStorage*>(m_kBridgeAtoms);

    reinterpret_cast<SimdLaneVector&>(t.translationA).m_vComponents =
        reinterpret_cast<const SimdLaneVector&>(pivotA).m_vComponents;
    reinterpret_cast<SimdLaneVector&>(t.translationB).m_vComponents =
        reinterpret_cast<const SimdLaneVector&>(pivotB).m_vComponents;

    SimdColumnMatrix& ca = t.rotationA;
    ca.m_col[0].m_vComponents = reinterpret_cast<const SimdLaneVector&>(axisA).m_vComponents;
    hkNormalize3(ca.m_col[0]);
    ca.m_col[1].m_vComponents = reinterpret_cast<const SimdLaneVector&>(axisAPerp).m_vComponents;
    hkNormalize3(ca.m_col[1]);
    hkSetCross(ca.m_col[2], ca.m_col[0], ca.m_col[1]);

    SimdColumnMatrix& cb = t.rotationB;
    cb.m_col[0].m_vComponents = reinterpret_cast<const SimdLaneVector&>(axisB).m_vComponents;
    hkNormalize3(cb.m_col[0]);
    cb.m_col[1].m_vComponents = reinterpret_cast<const SimdLaneVector&>(axisBPerp).m_vComponents;
    hkNormalize3(cb.m_col[1]);
    hkSetCross(t.rotationB.m_col[2], t.rotationB.m_col[0], t.rotationB.m_col[1]);
}

#include <math.h>
static __forceinline hkReal hkFabs(hkReal r)
{
    return (hkReal)fabs(r);
}

static __forceinline void hkCalculatePerpendicularVector(const SimdLaneVector& in, SimdLaneVector& out)
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

    out.m_vComponents = _mm_setzero_ps();
    out(ok1) = in(ok2);
    out(ok2) = -in(ok1);
}

static __forceinline void hkSetTransposeMul(SimdColumnMatrix& out, const SimdColumnMatrix& a, const SimdColumnMatrix& b)
{
    LocalM128 c0 = a.m_col[0].m_vComponents;
    LocalM128 c1 = a.m_col[1].m_vComponents;
    LocalM128 c2 = a.m_col[2].m_vComponents;
    LocalM128 tmp = _mm_unpacklo_ps(c0, c1);
    LocalM128 ctmp = _mm_unpackhi_ps(c0, c1);
    c0 = _mm_movelh_ps(tmp, c2);
    c1 = _mm_movehl_ps(c0, tmp);
    c1 = _mm_shuffle_ps(c1, c2, 0xd4);
    c2 = _mm_shuffle_ps(ctmp, c2, 0xe4);

    for (int i = 0; i < 3; i++)
    {
        const LocalM128 v = b.m_col[i].m_vComponents;
        LocalM128 b0 = _mm_shuffle_ps(v, v, 0x00);
        LocalM128 b1 = _mm_shuffle_ps(v, v, 0x55);
        LocalM128 b2 = _mm_shuffle_ps(v, v, 0xaa);
        out.m_col[i].m_vComponents = _mm_add_ps(_mm_add_ps(_mm_mul_ps(b0, c0), _mm_mul_ps(b1, c1)), _mm_mul_ps(b2, c2));
    }
}

// Builds a basis from axis, then sets each body's local frame rotation via transpose-multiply and its translation from the transformed pivot.
// @fnv 0x00d4f8f0
void hkpPrismaticConstraintData::setInWorldSpace(const hkTransform& bodyATransform, const hkTransform& bodyBTransform,
                                           const hkVector4& pivot, const hkVector4& axis)
{
    SimdColumnMatrix rot;
    rot.m_col[0].m_vComponents = reinterpret_cast<const SimdLaneVector&>(axis).m_vComponents;
    hkNormalize3(rot.m_col[0]);

    hkCalculatePerpendicularVector(rot.m_col[0], rot.m_col[1]);
    hkNormalize3(rot.m_col[1]);

    hkSetCross(rot.m_col[2], rot.m_col[0], rot.m_col[1]);

    hkpSetLocalTransformsConstraintAtom& t = *reinterpret_cast<hkpSetLocalTransformsConstraintAtom*>(m_kBridgeAtoms);

    hkSetTransposeMul(reinterpret_cast<SimdColumnMatrix&>(t.m_kBodyALocalFrame.m_rotation),
                      reinterpret_cast<const SimdColumnMatrix&>(bodyATransform.m_rotation), rot);
    hkSetTransposeMul(reinterpret_cast<SimdColumnMatrix&>(t.m_kBodyBLocalFrame.m_rotation),
                      reinterpret_cast<const SimdColumnMatrix&>(bodyBTransform.m_rotation), rot);

    t.m_kBodyALocalFrame.position.SetTransformedPosition(bodyATransform, pivot);
    t.m_kBodyBLocalFrame.position.SetTransformedPosition(bodyBTransform, pivot);
}
