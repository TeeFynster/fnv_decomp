
// src/staging/blk_00d60000_od_o2_gs_nood_nogs_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/staging/blk_00d60000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00d60000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"

#include <xmmintrin.h>
#include "../../include/hkVector4.h"
#include "../../include/hkQuaternion.h"
extern __declspec(align(16)) const unsigned int DAT_010c44d0[4];


// @fnv 0x00d6bec0
// src: GUESS 0x00d6bec0 (confidence: low)
void hkQuaternion::UpdateFields_00d6bec0(const hkQuaternion& q, hkVector4& out) const
{
    const __m128& qVec = *reinterpret_cast<const __m128*>(&q);
    const __m128& vec = *reinterpret_cast<const __m128*>(this);
    out.m_vComponents = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(qVec, qVec, 0xd2),
                                              _mm_shuffle_ps(vec, vec, 0xc9)),
                                   _mm_mul_ps(_mm_shuffle_ps(qVec, qVec, 0xc9),
                                              _mm_shuffle_ps(vec, vec, 0xd2)));
    __m128 w = _mm_shuffle_ps(qVec, qVec, 0xff);
    out.m_vComponents = _mm_sub_ps(out.m_vComponents, _mm_mul_ps(_mm_shuffle_ps(w, w, 0), vec));
    __m128 tw = _mm_shuffle_ps(vec, vec, 0xff);
    out.m_vComponents = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(tw, tw, 0), qVec), out.m_vComponents);
    out.m_vComponents = _mm_add_ps(out.m_vComponents, out.m_vComponents);
    __m128 d = _mm_mul_ps(qVec, vec);
    d = _mm_add_ps(_mm_shuffle_ps(d, d, 0x4e), d);
    d = _mm_add_ps(_mm_shuffle_ps(d, d, 0xb1), d);
    if (_mm_movemask_ps(d) & 1)
        out.m_vComponents = _mm_xor_ps(out.m_vComponents, *(const __m128*)DAT_010c44d0);
}

namespace fnv_00d6c470 {
struct FaceCode
{
    unsigned char unk00;
    unsigned char unk01;
    unsigned char index;
};
union ThreeVectors
{
    struct
    {
        __m128 x;
        __m128 y;
        __m128 z;
    };
};
extern unsigned char DAT_010d33c1[];
extern unsigned char DAT_010d33c2[];
extern __m128 DAT_010c44d0;
extern void __cdecl hk1dAngularBilateralConstraintBuildJacobian(ThreeVectors*, int, int);

// @fnv 0x00d6c470
// src: GUESS 0x00d6c470 (confidence: low)
static __declspec(noinline) void Runtime_UpdateState_00d6c470(const FaceCode* face, const __m128* normals, const unsigned char* points,
                                              int a, int b)
{
    unsigned int index = face->index;
    unsigned int first = DAT_010d33c1[index];
    unsigned int second = DAT_010d33c2[index];
    ThreeVectors basis;
    basis.x = normals[index];
    basis.z = *reinterpret_cast<const __m128*>(points + first);
    basis.y = *reinterpret_cast<const __m128*>(points + second);
    hk1dAngularBilateralConstraintBuildJacobian(&basis, a, b);
    basis.z = *reinterpret_cast<const __m128*>(points + second);
    basis.y = _mm_xor_ps(DAT_010c44d0, *reinterpret_cast<const __m128*>(points + first));
    hk1dAngularBilateralConstraintBuildJacobian(&basis, a, b);
}
const FaceCode* volatile inputFace;
const __m128* volatile inputNormals;
const unsigned char* volatile inputPoints;
volatile int inputA, inputB;
extern "C" const FaceCode* getFace();
extern "C" const __m128* getNormals();
extern "C" const unsigned char* getPoints();
extern "C" int getA();
extern "C" int getB();
void invoke()
{
    Runtime_UpdateState_00d6c470(getFace(), getNormals(), getPoints(), getA(), getB());
}
}  // namespace fnv_00d6c470

struct Span
{
    unsigned char u0;
    unsigned char u1;
    unsigned char start;
    unsigned char count;
};

struct Box
{
    char* p;
};

extern unsigned char DAT_010d33c0[];

void __cdecl hk1dAngularBilateralConstraintBuildJacobian(__m128* vec, int a1, int a2);

struct Triple
{
    __m128 second;
    __m128 first;
    __m128 third;
};

// @fnv 0x00d6c500
// src: GUESS 0x00d6c500 (confidence: low)
static __declspec(noinline) void Object_ProcessEntries_00d6c500(Span* span, int a1, Box base, Box p10, int a2)
{
    char* b = base.p;
    for (int i = span->start; i < span->start + span->count; ++i)
    {
        Triple t;
        t.first = *(__m128*)(b + DAT_010d33c0[i]);
        t.second = *(__m128*)(b + DAT_010d33c0[i + 1]);
        t.third = *(__m128*)(p10.p + DAT_010d33c0[i + 2]);
        hk1dAngularBilateralConstraintBuildJacobian(&t.second, a1, a2);
    }
}

Span* g_span;
int g_a1;
Box g_base;
Box g_p10;
int g_a2;
int g_sink;

void zz_call()
{
    Object_ProcessEntries_00d6c500(g_span, g_a1, g_base, g_p10, g_a2);
    g_sink = 1;
}
