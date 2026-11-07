
// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkphingelimitsdrawer_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkphingelimitsdrawer.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /O2 /GS /EHsc /Gy (unit lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton.

// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkphingelimitsdrawer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkphingelimitsdrawer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Exe 0x00de6d80 FUN_00de6d80: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
} __m128, LocalM128;

extern "C"
{
    LocalM128 __cdecl _mm_add_ps(LocalM128, LocalM128);
    LocalM128 __cdecl _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 __cdecl _mm_load_ss(const float*);
    LocalM128 __cdecl _mm_shuffle_ps(LocalM128, LocalM128, int);
    void __cdecl _mm_store_ps(float*, LocalM128);
}

static __forceinline LocalM128 splat(const float& f)
{
    LocalM128 t = _mm_load_ss(&f);
    return _mm_shuffle_ps(t, t, 0);
}

static __forceinline LocalM128 splatRounded(double f)
{
    float scalar = (float)f;
    LocalM128 t = _mm_load_ss(&scalar);
    return _mm_shuffle_ps(t, t, 0);
}

struct Visitor
{
    void** vt;
};

struct Src
{
    int u00;
    int u04;
    int u08;
    unsigned char* m0c;
};

struct Mat4
{
    LocalM128 r0, r1, r2, r3;
};
// hkRotation (passed to 0x00c7f700 = hkVector4::setRotatedDir) over this unit's own __m128 typedef.
struct HingeDrawRotation
{
    LocalM128 r0, r1, r2;
};

// The unit keeps its own __m128 (float lanes only, so /GS adds no cookie); hkVector4.h uses it.
#include "../../../../../../../../../include/hkVector4.h"

struct Holder
{
    void* p;
    void hkpPrimitiveDrawer_setDisplayHandler(Visitor* a);
};

extern const double DAT_0106d4c8;

struct T
{
    float f00;
    float u04, u08, u0c, u10, u14, u18;
    float f1c;
    LocalM128 m20;
    LocalM128 m30;
    hkVector4 m40;
    hkVector4 m50;
    HingeDrawRotation m60;
    HingeDrawRotation m90;
    Holder mc;
    void hkpConstraintDrawer_updateCommonParameters(Src* a, Mat4* b, Mat4* c);
    void hkpConstraintDrawer_drawPivots(int a, int b);
    void hkpConstraintDrawer_drawBodyFrames(int a, int b);
    void ProcessEntries_00de6d80(Src* a1, Visitor* a2, int a3, int a4);
};

int __cdecl PackColorBigEndian(float a, float b, float c, float d);

typedef void(__thiscall* DrawFn)(Visitor*, void*, void*, int, int, int);

// @fnv 0x00de6d80
// src: GUESS 0x00de6d80 (confidence: low)
void T::ProcessEntries_00de6d80(Src* a1, Visitor* a2, int a3, int a4)
{
    struct Work
    {
        hkVector4 va;
        hkVector4 vb;
        Mat4 matA;
        Mat4 matB;
        LocalM128 buf[12];
    } w;
    unsigned char* e = a1->m0c;
    mc.hkpPrimitiveDrawer_setDisplayHandler(a2);
    hkpConstraintDrawer_updateCommonParameters(a1, &w.matA, &w.matB);
    // Mat4 has the hkTransform layout, HingeDrawRotation the hkRotation one; 0x00c7f640 = hkVector4::_setTransformedPos,
    // 0x00c7f700 = hkVector4::_setRotatedDir.
    m50.setTransformedPos_00c7f640(reinterpret_cast<const hkTransform&>(w.matA), *reinterpret_cast<const hkVector4*>(e + 0x90));
    m40.setTransformedPos_00c7f640(reinterpret_cast<const hkTransform&>(w.matB), *reinterpret_cast<const hkVector4*>(e + 0x50));
    hkpConstraintDrawer_drawPivots(a3, a4);
    hkpConstraintDrawer_drawBodyFrames(a3, a4);
    w.vb.hkVector4_setRotatedDir(reinterpret_cast<const hkRotation*>(&m90), reinterpret_cast<const hkVector4*>(e + ((((int)e[0xa2] + 1) % 3) + 6) * 16));
    w.va.hkVector4_setRotatedDir(reinterpret_cast<const hkRotation*>(&m90), reinterpret_cast<const hkVector4*>(e + ((((int)e[0xa2] + 2) % 3) + 6) * 16));
    float s = f1c * f00;
    float t = s;
    float sd = s + t;
    float s2 = (float)(DAT_0106d4c8 * s);
    LocalM128 base = m50.v;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = -1; j <= 1; ++j)
        {
            LocalM128 x = i ? w.vb.v : w.va.v;
            LocalM128* __restrict ptry = i ? &w.va.v : &w.vb.v;
            LocalM128 y = *ptry;
            LocalM128* p = &w.buf[i * 6 + (j + 1) * 2 + 1];
            _mm_store_ps((float*)(p - 1), base);
            _mm_store_ps((float*)p, base);
            float ty = (float)((double)j * 1.4f * s);
            _mm_store_ps((float*)(p - 1), _mm_add_ps(_mm_mul_ps(splat(sd), x), p[-1]));
            _mm_store_ps((float*)p, _mm_add_ps(_mm_mul_ps(splat(s2), x), p[0]));
            _mm_store_ps((float*)(p - 1), _mm_add_ps(_mm_mul_ps(splatRounded(ty), y), p[-1]));
            _mm_store_ps((float*)p, _mm_add_ps(_mm_mul_ps(splatRounded(ty), y), p[0]));
        }
    }
    LocalM128* q = w.buf;
    int n = 6;
    do
    {
        DrawFn* slot = (DrawFn*)&a2->vt[9];
        (*slot)(a2, q, q + 1, PackColorBigEndian(0.8f, 0.8f, 0.8f, 1.0f), a3, a4);
        q += 2;
    } while (--n);
    DrawFn* slot = (DrawFn*)&a2->vt[9];
    (*slot)(a2, &m40, &m20, PackColorBigEndian(0.3f, 0.3f, 0.8f, 1.0f), a3, a4);
}
