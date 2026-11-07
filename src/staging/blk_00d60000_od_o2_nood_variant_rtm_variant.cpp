
// src/staging/blk_00d60000_od_o2_nood_variant_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00d60000_od_o2_nood_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /O2 /GS /EHsc /Gy (unit lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton.

// src/staging/blk_00d60000_od_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/staging/blk_00d60000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/staging/blk_00d60000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
#include "../../include/hkQuaternion.h"
namespace sd6ae50 {

extern "C" const char DAT_010cc040[];

struct FinishLoadedObjectFlag
{
    int m_iFinishing;
};

struct LoadedMember
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;

    LoadedMember(FinishLoadedObjectFlag kFlag);
};

struct __declspec(align(16)) LoadedObject
{
    const char* m_pVtbl;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int m_uiLogicalSize;
    unsigned short m_usCapacity;
    unsigned short m_usFlags;
    LoadedMember m_kMember;

    LoadedObject(FinishLoadedObjectFlag kFlag)
        : m_pVtbl(DAT_010cc040), m_uiLogicalSize(0), m_usCapacity(0), m_usFlags(0x8000), m_kMember(kFlag)
    {}
};

// @fnv 0x00d6ae50
// src: HAVOK_LIB 0x00d6ae50
const char* getVtablehkpConstraintInstance()
{
    FinishLoadedObjectFlag kFlag;
    kFlag.m_iFinishing = 0;
    LoadedObject kObject(kFlag);
    return kObject.m_pVtbl;
}

}
struct FUN_00d6aec0_seed
{
    int v;
};
__declspec(align(16)) class FUN_00d6aec0_obj
{
  public:
    FUN_00d6aec0_obj(FUN_00d6aec0_seed s) throw();
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
};
int Object_ProcessAndReturnValue_00d6aec0() throw();
#include <xmmintrin.h>
#include <math.h>
#include "../../include/Vec4.h"
extern float DAT_0104da4c;
extern const float DAT_01011d78;
union Basis
{
    struct
    {
        __m128 x;
        __m128 y;
        __m128 z;
    };
};
struct FUN_004b4ab0_Class
{
    union
    {
        __m128 value;
    };
    void hkVector4_setRotatedInverseDir(int basis, int vector);
    void hkVector4_setRotatedDir(const Basis* basis, const FUN_004b4ab0_Class* vector);
};
struct MotionInput
{
    float scale;
    __m128 directionA;
    __m128 directionB;
    __m128 axis;
    __m128 position;
    __m128 target;
    float maxLength;
    __m128 translation;
};
static __forceinline float scalar(__m128 a)
{
    float value;
    _mm_store_ss(&value, a);
    return value;
}
static __forceinline __m128 cross3(const __m128& a, const __m128& b)
{
    __m128 first = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2));
    return _mm_sub_ps(first, _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9)));
}
static __forceinline __m128 dot3(__m128 a)
{
    __m128 squares = _mm_mul_ps(a, a);
    __m128 sum = _mm_add_ss(_mm_shuffle_ps(squares, squares, 0x55), squares);
    return _mm_add_ss(_mm_shuffle_ps(squares, squares, 0xaa), sum);
}
static __forceinline __m128 normalized3(__m128 a)
{
    __m128 lengthSquared = dot3(a);
    __m128 inverseLength = _mm_rsqrt_ss(lengthSquared);
    __m128 correction =
        _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(lengthSquared, inverseLength), inverseLength));
    __m128 refined = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), inverseLength), correction);
    refined = _mm_andnot_ps(_mm_cmpeq_ss(lengthSquared, _mm_set_ss(DAT_01011d78)), refined);
    return _mm_mul_ps(_mm_shuffle_ps(refined, refined, 0), a);
}
static __forceinline void buildBasis(const MotionInput* input, __m128 normal, Basis& basis)
{
    __m128 side = normalized3(cross3(normal, input->axis));
    __m128 up = normalized3(cross3(side, input->axis));
    basis.x = side;
    basis.y = up;
    basis.z = input->axis;
}
void __cdecl hkpCharacterMovementUtil_calculateMovement(const MotionInput* input, float outputBits);
struct BodySource
{
    Vec4 m_000, m_010, m_020, m_030, m_040, m_050, m_060, m_070;
    Vec4 m_080, m_090, m_0a0, m_0b0, m_0c0, m_0d0, m_0e0, m_0f0;
    Vec4 m_100, m_110, m_120, m_130;
    Vec4 m_140;
    Vec4 m_150;
    Vec4 m_160;
    Vec4 m_170;
    Vec4 m_180;
    Vec4 m_190;
    Vec4 m_1a0;
    Vec4 m_1b0;
    Vec4 m_1c0;
};
struct BodyList
{
    int m_iElementCount;
    BodySource** m_data;
};
struct BodyOut
{
    Vec4 m_00;
    Vec4 m_10;
    Vec4 m_20;
    Vec4 m_30;
};
void hkaKeyFrameHierarchyUtility_initialize(BodyList* list, BodyOut* out);
struct __declspec(align(16)) V16
{
    float x, y, z, w;
};
struct __declspec(align(16)) D6Vec3
{
    V16 a;
    V16 b;
    V16 c;
};
struct D6Owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    V16 f30;
};
struct D6Idx
{
    unsigned char unk00;
    unsigned char unk01;
    unsigned char idx02;
};
extern "C" void __cdecl hk1dLinearBilateralConstraintBuildJacobian(D6Vec3* s, void* d, void* e);
extern "C" V16* __cdecl D6GetArray(void);
void Runtime_UpdateState_00d6c030(D6Owner* a, V16* b, D6Idx* c, void* d, void* e);
volatile D6Owner* g_d6Owner;
volatile D6Idx* g_d6Idx;
volatile void* g_d6D;
volatile void* g_d6E;
extern "C" __declspec(noinline) void d6c030_dummy_caller(void)
{
    Runtime_UpdateState_00d6c030((D6Owner*)g_d6Owner, D6GetArray(), (D6Idx*)g_d6Idx, (void*)g_d6D, (void*)g_d6E);
}

namespace SimdC {
// Exe 0x00d6b510 FUN_00d6b510: retain this LocalM128 view; the CRT type changes the matched code.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    struct
    {
        float x, y, z, w;
    } m128_f32;
    struct
    {
        unsigned __int64 lo, hi;
    } m128_u64;
} __m128, LocalM128;
extern "C"
{
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_set_ps1(float);
    LocalM128 _mm_load_ps(float const*);
    LocalM128 _mm_load_ss(float const*);
    LocalM128 _mm_load_ps1(float const*);
    LocalM128 _mm_unpackhi_ps(LocalM128, LocalM128);
    void _mm_store_ps(float*, LocalM128);
}

}
extern "C" void _ReadWriteBarrier();
extern SimdC::LocalM128 DAT_010c71e0;
extern SimdC::LocalM128 DAT_010ec7f0;
extern float DAT_01267e30;

// hkVector4 of the hkQsTransform/pose records (translation, scale) with the unit's own inline forms over SimdC::__m128.
struct PoseVector4
{
    SimdC::LocalM128 m_vComponents;
    __forceinline SimdC::LocalM128& quad()
    {
        return m_vComponents;
    }
    __forceinline const SimdC::LocalM128& quad() const
    {
        return m_vComponents;
    }
    __forceinline void SetRotatedDirection(const hkQuaternion& q, const PoseVector4& d);
    __forceinline void setRotatedTranslation(const hkQuaternion& q, const PoseVector4& d);
    __forceinline void setAdd4(const PoseVector4& a, const PoseVector4& b)
    {
        m_vComponents = SimdC::_mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void add4(const PoseVector4& a)
    {
        m_vComponents = SimdC::_mm_add_ps(m_vComponents, a.m_vComponents);
    }
    __forceinline void setMul4(const PoseVector4& a, const PoseVector4& b)
    {
        m_vComponents = SimdC::_mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
};
// Keep this unit's empty construction and aggregate SIMD copy inline.
__forceinline hkQuaternion::hkQuaternion()
{}

__forceinline void hkQuaternion::operator=(const hkQuaternion& q)
{
    reinterpret_cast<PoseVector4&>(*this) = reinterpret_cast<const PoseVector4&>(q);
}

// hkQsTransform layout (translation, hkQuaternion, scale) over this unit's Vec stand-in.
struct PoseQsTransform
{
    PoseVector4 position;
    hkQuaternion rotation;
    PoseVector4 scale;
    __forceinline void SetProduct(const PoseQsTransform& a, const PoseQsTransform& b);
};
struct Pose
{
    PoseVector4 position;
    hkQuaternion rotation;
};
struct OutputPair
{
    PoseQsTransform world;
    PoseQsTransform local;
};
struct Binding
{
    int count;
    BodySource** nodes;
    short* parents;
    int* indices;
    float* weights;
};
struct Weight
{
    float value;
    float unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
};

__forceinline SimdC::LocalM128 rotate(SimdC::LocalM128 q, SimdC::LocalM128 v)
{
    SimdC::LocalM128 w = SimdC::_mm_shuffle_ps(q, q, 0xff);
    SimdC::LocalM128 p = SimdC::_mm_mul_ps(v, q);
    SimdC::LocalM128 y = SimdC::_mm_shuffle_ps(p, p, 0x55);
    y = SimdC::_mm_add_ss(y, p);
    SimdC::LocalM128 z = SimdC::_mm_shuffle_ps(p, p, 0xaa);
    SimdC::LocalM128 d = SimdC::_mm_add_ss(z, y);
    SimdC::LocalM128 cross =
        SimdC::_mm_sub_ps(SimdC::_mm_mul_ps(SimdC::_mm_shuffle_ps(v, v, 0xd2), SimdC::_mm_shuffle_ps(q, q, 0xc9)),
                          SimdC::_mm_mul_ps(SimdC::_mm_shuffle_ps(v, v, 0xc9), SimdC::_mm_shuffle_ps(q, q, 0xd2)));
    SimdC::LocalM128 r = SimdC::_mm_add_ps(
        SimdC::_mm_mul_ps(cross, w),
        SimdC::_mm_add_ps(SimdC::_mm_mul_ps(SimdC::_mm_add_ps(SimdC::_mm_mul_ps(w, w), DAT_010c71e0), v),
                          SimdC::_mm_mul_ps(SimdC::_mm_shuffle_ps(d, d, 0), q)));
    return SimdC::_mm_add_ps(r, r);
}
__forceinline void PoseVector4::SetRotatedDirection(const hkQuaternion& quat, const PoseVector4& direction)
{
    SimdC::LocalM128 qreal = SimdC::_mm_shuffle_ps(reinterpret_cast<const PoseVector4&>(quat).m_vComponents, reinterpret_cast<const PoseVector4&>(quat).m_vComponents, 0xff);
    SimdC::LocalM128 p = SimdC::_mm_mul_ps(reinterpret_cast<const PoseVector4&>(quat).m_vComponents, direction.m_vComponents);
    SimdC::LocalM128 y = SimdC::_mm_add_ss(SimdC::_mm_shuffle_ps(p, p, 0x55), p);
    SimdC::LocalM128 d = SimdC::_mm_add_ss(SimdC::_mm_shuffle_ps(p, p, 0xaa), y);
    SimdC::LocalM128 cross = SimdC::_mm_sub_ps(
        SimdC::_mm_mul_ps(SimdC::_mm_shuffle_ps(reinterpret_cast<const PoseVector4&>(quat).m_vComponents, reinterpret_cast<const PoseVector4&>(quat).m_vComponents, 0xc9),
                          SimdC::_mm_shuffle_ps(direction.m_vComponents, direction.m_vComponents, 0xd2)),
        SimdC::_mm_mul_ps(SimdC::_mm_shuffle_ps(reinterpret_cast<const PoseVector4&>(quat).m_vComponents, reinterpret_cast<const PoseVector4&>(quat).m_vComponents, 0xd2),
                          SimdC::_mm_shuffle_ps(direction.m_vComponents, direction.m_vComponents, 0xc9)));
    SimdC::LocalM128 r = SimdC::_mm_add_ps(
        SimdC::_mm_mul_ps(cross, qreal),
        SimdC::_mm_add_ps(SimdC::_mm_mul_ps(SimdC::_mm_add_ps(SimdC::_mm_mul_ps(qreal, qreal), DAT_010c71e0),
                                            direction.m_vComponents),
                          SimdC::_mm_mul_ps(SimdC::_mm_shuffle_ps(d, d, 0), reinterpret_cast<const PoseVector4&>(quat).m_vComponents)));
    m_vComponents = SimdC::_mm_add_ps(r, r);
}
__forceinline void PoseVector4::setRotatedTranslation(const hkQuaternion& quat, const PoseVector4& direction)
{
    SimdC::LocalM128 qreal = SimdC::_mm_shuffle_ps(reinterpret_cast<const PoseVector4&>(quat).m_vComponents, reinterpret_cast<const PoseVector4&>(quat).m_vComponents, 0xff);
    SimdC::LocalM128 p = SimdC::_mm_mul_ps(SimdC::_mm_load_ps(&reinterpret_cast<const PoseVector4&>(quat).m_vComponents.m128_f32.x), direction.m_vComponents);
    SimdC::LocalM128 y = SimdC::_mm_add_ss(SimdC::_mm_shuffle_ps(p, p, 0x55), p);
    SimdC::LocalM128 d = SimdC::_mm_add_ss(SimdC::_mm_shuffle_ps(p, p, 0xaa), y);
    SimdC::LocalM128 cross = SimdC::_mm_sub_ps(
        SimdC::_mm_mul_ps(SimdC::_mm_shuffle_ps(reinterpret_cast<const PoseVector4&>(quat).m_vComponents, reinterpret_cast<const PoseVector4&>(quat).m_vComponents, 0xc9),
                          SimdC::_mm_shuffle_ps(direction.m_vComponents, direction.m_vComponents, 0xd2)),
        SimdC::_mm_mul_ps(SimdC::_mm_shuffle_ps(reinterpret_cast<const PoseVector4&>(quat).m_vComponents, reinterpret_cast<const PoseVector4&>(quat).m_vComponents, 0xd2),
                          SimdC::_mm_shuffle_ps(direction.m_vComponents, direction.m_vComponents, 0xc9)));
    SimdC::LocalM128 r = SimdC::_mm_add_ps(
        SimdC::_mm_mul_ps(cross, qreal),
        SimdC::_mm_add_ps(SimdC::_mm_mul_ps(SimdC::_mm_add_ps(SimdC::_mm_mul_ps(qreal, qreal), DAT_010c71e0),
                                            direction.m_vComponents),
                          SimdC::_mm_mul_ps(SimdC::_mm_shuffle_ps(d, d, 0), reinterpret_cast<const PoseVector4&>(quat).m_vComponents)));
    m_vComponents = SimdC::_mm_add_ps(r, r);
}
__forceinline void PoseQsTransform::SetProduct(const PoseQsTransform& a, const PoseQsTransform& b)
{
    PoseVector4 extra;
    extra.setRotatedTranslation(a.rotation, b.position);
    position.setAdd4(extra, a.position);
    rotation.setMul(a.rotation, b.rotation);
    scale.setMul4(a.scale, b.scale);
}
__forceinline SimdC::LocalM128 blendPosition(const PoseVector4& position, const PoseVector4& target, float weight)
{
    SimdC::LocalM128 scalar = SimdC::_mm_load_ss(&weight);
    SimdC::LocalM128 t = SimdC::_mm_shuffle_ps(scalar, scalar, 0);
    return SimdC::_mm_add_ps(SimdC::_mm_mul_ps(SimdC::_mm_sub_ps(DAT_010ec7f0, t), position.quad()),
                             SimdC::_mm_mul_ps(t, target.quad()));
}

extern "C" unsigned int __security_cookie;
extern "C" void __fastcall __security_check_cookie(unsigned int);
// src: COMMUNITY 0x00c66320
__declspec(noinline) void hkQuaternion::setMul(const hkQuaternion& a, const hkQuaternion& b)
{
    SimdC::LocalM128 av = reinterpret_cast<const PoseVector4&>(a).m_vComponents, bv = reinterpret_cast<const PoseVector4&>(b).m_vComponents;
    SimdC::LocalM128 cross =
        SimdC::_mm_sub_ps(SimdC::_mm_mul_ps(SimdC::_mm_shuffle_ps(bv, bv, 0xd2), SimdC::_mm_shuffle_ps(av, av, 0xc9)),
                          SimdC::_mm_mul_ps(SimdC::_mm_shuffle_ps(bv, bv, 0xc9), SimdC::_mm_shuffle_ps(av, av, 0xd2)));
    SimdC::LocalM128 ar = SimdC::_mm_shuffle_ps(av, av, 0xff);
    ar = SimdC::_mm_shuffle_ps(ar, ar, 0);
    SimdC::LocalM128 br = SimdC::_mm_shuffle_ps(bv, bv, 0xff);
    br = SimdC::_mm_shuffle_ps(br, br, 0);
    SimdC::LocalM128 xyz =
        SimdC::_mm_add_ps(SimdC::_mm_mul_ps(br, av), SimdC::_mm_add_ps(SimdC::_mm_mul_ps(ar, bv), cross));
    SimdC::LocalM128 p = SimdC::_mm_mul_ps(bv, av);
    SimdC::LocalM128 dot =
        SimdC::_mm_add_ss(SimdC::_mm_shuffle_ps(p, p, 0xaa), SimdC::_mm_add_ss(SimdC::_mm_shuffle_ps(p, p, 0x55), p));
    SimdC::LocalM128 w = SimdC::_mm_sub_ps(p, SimdC::_mm_shuffle_ps(dot, dot, 0));
    reinterpret_cast<PoseVector4*>(this)->m_vComponents = SimdC::_mm_shuffle_ps(xyz, SimdC::_mm_unpackhi_ps(xyz, w), 0xc4);
    __security_check_cookie(__security_cookie);
}

// @fnv 0x00d6b510
// src: GUESS 0x00d6b510 (confidence: low)
static __declspec(noinline) void hkQuaternion_ProcessEntries_00d6b510(Binding* binding, Weight* weights, const PoseQsTransform* root,
                                              PoseQsTransform* output, const PoseQsTransform* __restrict transforms)
{
    for (int i = 0; i < binding->count; ++i)
    {
        const PoseQsTransform& input = transforms[i];
        PoseQsTransform& outWorld = output[2 * i];
        PoseQsTransform& outLocal = output[2 * i + 1];
        int parentIndex = binding->parents[i];
        const PoseQsTransform* parent = parentIndex >= 0 ? &output[2 * parentIndex + 1] : root;
        outLocal.SetProduct(*parent, input);
        Pose local;
        local.rotation = outLocal.rotation;
        local.position = outLocal.position;
        int weightIndex = binding->indices ? binding->indices[i] : 0;
        if (weightIndex == -1)
            continue;
        float weight = weights[weightIndex].value;
        if (binding->weights)
            weight = (float)(weight * binding->weights[i]);
        if (weight > 0.0f && parentIndex >= 0)
        {
            BodySource* node = binding->nodes[parentIndex];
            PoseQsTransform reference;
            reference.position = *reinterpret_cast<const PoseVector4*>(&node->m_120);
            reference.scale.quad() = SimdC::_mm_set_ps1(1.0f);
            reference.rotation = *reinterpret_cast<const hkQuaternion*>(&node->m_160);
            PoseQsTransform composed;
            composed.SetProduct(reference, input);
            local.rotation.D3D_ComputeClearColor(local.rotation, composed.rotation, weight);
            local.position.quad() = blendPosition(local.position, composed.position, weight);
        }
        PoseVector4 offset;
        offset.SetRotatedDirection(local.rotation, *reinterpret_cast<const PoseVector4*>(&binding->nodes[i]->m_170));
        outWorld.position.setAdd4(offset, local.position);
        reinterpret_cast<PoseVector4&>(outWorld.rotation).m_vComponents = reinterpret_cast<const PoseVector4&>(local.rotation).m_vComponents;
        outWorld.scale.quad() = SimdC::_mm_load_ps(&DAT_01267e30);
    }
}

void RunCompose_d6b510(Binding* binding, Weight* weights, const PoseQsTransform* root, PoseQsTransform* output,
                       const PoseQsTransform* __restrict transforms)
{
    hkQuaternion_ProcessEntries_00d6b510(binding, weights, root, output, transforms);
}
