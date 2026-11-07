
// src/havok/common/visualize/shape/hkdisplaysphere_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/common/visualize/shape/hkdisplaysphere_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/common/visualize/shape/hkdisplaysphere_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-29 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/common/visualize/shape/hkdisplaysphere.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/common/visualize/shape/hkdisplaysphere.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/shape/hkdisplaysphere.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../include/hkReferencedObject.h"
#include "../../../../../include/hkVector4.h"

struct __declspec(align(16)) hkVec4f
{
    float x, y, z, w;
};
extern float DAT_012683b0;
struct FUN_008cd6a0_Class
{
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
    hkVector4 m_vTranslation;

    void setIdentity()
    {
        m_kColumn0.setZero4();
        m_kColumn1.setZero4();
        m_kColumn2.setZero4();
        float* d = &m_kColumn0(0);
        d[0] = 1.0f;
        d[5] = 1.0f;
        d[10] = 1.0f;
        m_vTranslation.setZero4();
    }
    void hkRotation_set(void* p);
};
struct __declspec(align(16)) ShapeBase : hkReferencedObject
{
    int m_ulUserData;
    FUN_008cd6a0_Class m_kMotionTransform;
    int m_type;

    ShapeBase()
    {
        m_ulUserData = 0;
        m_type = 1;
        m_kMotionTransform.setIdentity();
    }
};
struct __declspec(align(16)) FUN_00e0af50 : ShapeBase
{
    hkVec4f m_vec;
    int m_kPointA;
    int m_kPointB;

    FUN_00e0af50(const hkVec4f& v, int a, int b);
};
void __stdcall nullsub_91(int a, int b);

extern "C" void _ReadBarrier();
void* hkMemoryRouter_getInstance(void);
void __cdecl hkArrayUtil__reserve(void* allocator, void* self, unsigned int newCap, int elemSize);

struct AllocatorHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_pAllocator;
};

struct SubdivVecArray
{
    hkVector4* m_data;
    int m_uiItemCount;
    unsigned int m_capFlags;
};

struct SubdivTri
{
    int a;
    int b;
    int c;
    int d;
};

struct SubdivTriArray
{
    SubdivTri* m_data;
    int m_uiItemCount;
    unsigned int m_capFlags;
};

struct SubdivMesh
{
    SubdivVecArray m_verts;
    SubdivTriArray m_tris;
};

static __forceinline void SubdivMidpoint(__m128* dst, __m128 m, const float* pw)
{
    __m128 zero = _mm_set_ss(0.0f);
    __m128 half = _mm_set_ss(0.5f);
    __m128 three = _mm_set_ss(3.0f);
    _mm_store_ps((float*)dst, m);
    __m128 sq = _mm_mul_ps(m, m);
    __m128 yy = _mm_shuffle_ps(sq, sq, 0x55);
    __m128 len2 = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), _mm_add_ss(yy, sq));
    __m128 r = _mm_rsqrt_ss(len2);
    __m128 nr = _mm_mul_ss(_mm_mul_ss(len2, r), r);
    __m128 inv = _mm_mul_ss(_mm_mul_ss(half, r), _mm_sub_ss(three, nr));
    inv = _mm_andnot_ps(_mm_cmpeq_ss(len2, zero), inv);
    __m128 n = _mm_mul_ps(_mm_shuffle_ps(inv, inv, 0), m);
    _mm_store_ps((float*)dst, n);
    _mm_store_ps((float*)dst, _mm_mul_ps(_mm_shuffle_ps(_mm_load_ss(pw), _mm_load_ss(pw), 0), n));
}
struct OutputPair
{
    __m128 first;
    __m128 second;
};
static __forceinline void SecondMidpoint(OutputPair* dst, __m128 m, const float* pw)
{
    __m128 zero = _mm_set_ss(0.0f);
    __m128 half = _mm_set_ss(0.5f);
    __m128 three = _mm_set_ss(3.0f);
    dst->second = m;
    __m128 sq = _mm_mul_ps(m, m);
    __m128 yy = _mm_shuffle_ps(sq, sq, 0x55);
    __m128 len2 = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), _mm_add_ss(yy, sq));
    __m128 r = _mm_rsqrt_ss(len2);
    __m128 nr = _mm_mul_ss(_mm_mul_ss(len2, r), r);
    __m128 inv = _mm_mul_ss(_mm_mul_ss(half, r), _mm_sub_ss(three, nr));
    inv = _mm_andnot_ps(_mm_cmpeq_ss(len2, zero), inv);
    __m128 n = _mm_mul_ps(_mm_shuffle_ps(inv, inv, 0), m);
    dst->second = n;
    dst->second = _mm_mul_ps(_mm_shuffle_ps(_mm_load_ss(pw), _mm_load_ss(pw), 0), dst->second);
}

template <class Array> static __forceinline void SubdivExpand(Array* array, int amount)
{
    AllocatorHolder* holder = (AllocatorHolder*)hkMemoryRouter_getInstance();
    void* alloc = holder->m_pAllocator;
    int need = array->m_uiItemCount + amount;
    int cap = array->m_capFlags & 0x3fffffffu;
    if (cap < need)
    {
        int newCap = cap + cap;
        if (need < newCap)
            need = newCap;
        hkArrayUtil__reserve(alloc, array, need, 16);
    }
    array->m_uiItemCount += amount;
}

// @fnv 0x00e0afe0
// src: XBOX_PDB 0x00e0afe0
void __cdecl _subdivideRecursive(SubdivMesh* self, int idx, float w, float t)
{
    if (t == 0.0f)
    {
        return;
    }

    for (;;)
    {
        int oldV = self->m_verts.m_uiItemCount;
        int oldT = self->m_tris.m_uiItemCount;
        SubdivExpand(&self->m_verts, 3);
        SubdivExpand(&self->m_tris, 3);

        SubdivTri* original = &self->m_tris.m_data[idx];
        hkVector4* V = self->m_verts.m_data;
        const __m128& p0 = V[original->a].m_vComponents;
        const __m128& p1 = V[original->b].m_vComponents;
        const __m128& p2 = V[original->c].m_vComponents;

        __m128* mid = &V[oldV].m_vComponents;
        __m128* mid2 = &V[oldV + 2].m_vComponents;
        SubdivMidpoint(mid, _mm_add_ps(p1, p0), &w);
        SecondMidpoint((OutputPair*)mid, _mm_add_ps(p2, p1), &w);
        SubdivMidpoint(mid2, _mm_add_ps(p2, p0), &w);

        SubdivTri* T = self->m_tris.m_data;
        SubdivTri* T0 = &T[oldT];
        SubdivTri* T2 = &T[oldT + 2];
        T0->a = original->a;
        T0->b = oldV;
        T0->c = oldV + 2;
        *(volatile int*)&T0[1].a = oldV;
        T0[1].b = original->b;
        T0[1].c = oldV + 1;
        T2->a = oldV + 2;
        T2->b = oldV + 1;
        T2->c = original->c;
        original->a = oldV;
        original->b = oldV + 1;
        original->c = oldV + 2;

        double t1 = t - 1.0;
        _subdivideRecursive(self, oldT, w, t1);
        _subdivideRecursive(self, oldT + 1, w, t1);
        _subdivideRecursive(self, oldT + 2, w, t1);
        t = t1;
        if (t == 0.0f)
        {
            break;
        }
    }
}
