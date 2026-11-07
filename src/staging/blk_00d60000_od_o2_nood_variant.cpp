
// src/staging/blk_00d60000_od_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/staging/blk_00d60000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00d60000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
#include "../../include/Vec4.h"

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

// @fnv 0x00d6aec0
// src: GUESS 0x00d6aec0 (confidence: low)
int Object_ProcessAndReturnValue_00d6aec0() throw()
{
    FUN_00d6aec0_obj obj((FUN_00d6aec0_seed()));
    return obj.unk00;
}

#include <xmmintrin.h>
#include <math.h>
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

// @fnv 0x00d6aef0
// src: COMMUNITY 0x00d6aef0
void __cdecl hkpCharacterMovementUtil_calculateMovement(const MotionInput* input, float outputBits)
{
    __m128 a = input->directionA, b = input->directionB;
    __m128 t = _mm_mul_ps(_mm_shuffle_ps(b, b, 0xc9), _mm_shuffle_ps(a, a, 0xd2));
    __m128 normal = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(b, b, 0xd2), _mm_shuffle_ps(a, a, 0xc9)), t);
    if ((double)scalar(dot3(normal)) < 0.00000011920928955078125f)
        return;
    {
        normal = normalized3(normal);
        union Workspace
        {
            struct
            {
                Vec4 position;
                __m128 delta;
                Basis basis;
            };
        } workspace;
        buildBasis(input, normal, workspace.basis);
        (*reinterpret_cast<__m128*>(&workspace.position)) = _mm_sub_ps(input->position, input->translation);
        workspace.position.hkVector4_setRotatedInverseDir(reinterpret_cast<const Rot&>(workspace.basis), workspace.position);
        workspace.delta = _mm_sub_ps(input->target, (*reinterpret_cast<__m128*>(&workspace.position)));
        float distanceSquared;
        _mm_store_ss(&distanceSquared, dot3(workspace.delta));
        __m128 movement;
        if (distanceSquared * input->scale * input->scale > (double)input->maxLength * input->maxLength)
        {
            float length = (float)sqrt(distanceSquared);
            float inverse = 1.0f / length;
            float scale = inverse * input->maxLength;
            movement = _mm_mul_ps(_mm_set1_ps(scale), workspace.delta);
        }
        else
        {
            movement = _mm_mul_ps(_mm_set1_ps(input->scale), workspace.delta);
        }
        (*reinterpret_cast<__m128*>(&workspace.position)) = _mm_add_ps(movement, (*reinterpret_cast<__m128*>(&workspace.position)));
        Vec4* output = *reinterpret_cast<Vec4* const*>(&outputBits);
        output->hkVector4_setRotatedDir(static_cast<const void*>(&workspace.basis), workspace.position);
        __m128 translation = _mm_load_ps(reinterpret_cast<const float*>(&input->translation));
        __m128 transformed = _mm_load_ps(reinterpret_cast<const float*>(&output->x));
        _mm_store_ps(reinterpret_cast<float*>(&output->x), _mm_add_ps(translation, transformed));
    }
}

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

// @fnv 0x00d6b4b0
// src: COMMUNITY 0x00d6b4b0
void hkaKeyFrameHierarchyUtility_initialize(BodyList* list, BodyOut* out)
{
    for (int i = 0; i < list->m_iElementCount; i++)
    {
        BodySource* src = list->m_data[i];
        (*reinterpret_cast<__m128*>(&out[i].m_20)) = (*reinterpret_cast<__m128*>(&src->m_1b0));
        (*reinterpret_cast<__m128*>(&out[i].m_30)) = (*reinterpret_cast<__m128*>(&src->m_1c0));
        (*reinterpret_cast<__m128*>(&out[i].m_00)) = (*reinterpret_cast<__m128*>(&src->m_140));
        (*reinterpret_cast<__m128*>(&out[i].m_10)) = (*reinterpret_cast<__m128*>(&src->m_160));
    }
}

struct __declspec(align(16)) D6Vec3
{
    float ax, ay, az, aw;
    float bx, by, bz, bw;
    float cx, cy, cz, cw;
};

struct __declspec(align(16)) D6Owner
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
    Vec4 f30;
};

struct D6Idx
{
    unsigned char unk00;
    unsigned char unk01;
    unsigned char idx02;
};

extern "C" void __cdecl hk1dLinearBilateralConstraintBuildJacobian(D6Vec3* s, void* d, void* e);
extern "C" Vec4* __cdecl D6GetArray(void);

// @fnv 0x00d6c030
// src: GUESS 0x00d6c030 (confidence: low)
static __declspec(noinline) void Runtime_UpdateState_00d6c030(D6Owner* a, Vec4* b, D6Idx* c, void* d, void* e)
{
    D6Vec3 s;
    *(__m128*)&s.ax = *(__m128*)&a->f30;
    *(__m128*)&s.bx = *(__m128*)&b[3];
    *(__m128*)&s.cx = *(__m128*)&b[c->idx02];
    hk1dLinearBilateralConstraintBuildJacobian(&s, d, e);
}

volatile D6Owner* g_d6Owner;
volatile D6Idx* g_d6Idx;
volatile void* g_d6D;
volatile void* g_d6E;

extern "C" __declspec(noinline) void d6c030_dummy_caller(void)
{
    Runtime_UpdateState_00d6c030((D6Owner*)g_d6Owner, D6GetArray(), (D6Idx*)g_d6Idx, (void*)g_d6D, (void*)g_d6E);
}
