#define FNV64_HKVECTOR4_PACKET_BODIES
#define FNV64_HKVECTOR4_OWN_CONVERSION
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4
#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4
// src/havok/physics/internal/collide/gjk/penetration/hkpconvexpenetrationutil_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/internal/collide/gjk/penetration/hkpconvexpenetrationutil_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/internal/collide/gjk/penetration/hkpconvexpenetrationutil_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/internal/collide/gjk/penetration/hkpconvexpenetrationutil.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/internal/collide/gjk/penetration/hkpconvexpenetrationutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/gjk/penetration/hkpconvexpenetrationutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/hkMatrix3.h"
#include "../../../../../../../include/hkTransform.h"
#include "../../../../../../../include/hkpConvexShape.h"

struct Entry
{
    hkVector4 m_iThirdValue;
    hkVector4 m_kPointA;
    hkVector4 m_kPointB;
    int m_flag;
};
struct Obj
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_num;
    int m_iThirdValue;
    int m_auiShapeKeys[4];
    Entry m_usTrailingValue[4];
    void ProcessEntries_00e2d440();
    void SetEntries(const hkVector4* a, const hkVector4* b, const hkVector4* c);
};
struct FUN_00df9c40_Obj
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
    __m128* unk60;
    __m128* unk64;
    __m128* unk68;
    int unk6C;

    void PushVectorTriple(const __m128* src);
};
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_xor_ps(__m128 a, __m128 b);
extern "C" void _mm_store_ps(float* p, __m128 a);
extern const __m128 DAT_010c44d0;
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
extern "C" __m128 _mm_unpacklo_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_unpackhi_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_movelh_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_movehl_ps(__m128 a, __m128 b);
struct hkpCdVertexPairDF9B
{
    hkVector4 m_vContactPosition;
    hkVector4 m_kVertexA;
    hkVector4 m_kVertexB;
};
class hkpMinkowskiDF9B
{
  public:
    void UpdateState_00df9b50(const hkVector4& kDirection, hkpCdVertexPairDF9B& kOut) const;

    hkTransform m_kTransform;
    unsigned int unk40, unk44, unk48, unk4C, unk50;
    const hkpConvexShape* m_pShapeA;
    const hkpConvexShape* m_pShapeB;
};
extern "C" __m128 _mm_xor_ps(__m128, __m128);
extern "C" __m128 _mm_load_ps(const float*);
extern "C" void _mm_store_ps(float*, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" void _mm_store_ss(float*, __m128);
template <class T> struct S00df9ef0_Pad
{
    T* m_p;
    __forceinline T* val() const
    {
        return m_p;
    }
    __forceinline T* operator->() const
    {
        return m_p;
    }
};
struct S00df9ef0_Hit
{
    hkVector4 a;
    hkVector4 b;
    hkVector4 c;
    int d;
};
struct S00df9ef0_Obj
{
    void UpdateState_00df9b50(const hkVector4* in, hkVector4* out);

    void ComputeValues_00df9ef0(hkVector4* p, S00df9ef0_Pad<hkVector4> r, S00df9ef0_Hit* q, S00df9ef0_Pad<float> outF);
};
static float S00df9ef0_Dot3(__m128 v)
{
    __m128 s1 = _mm_add_ss(_mm_shuffle_ps(v, v, 0x55), v);
    __m128 s = _mm_add_ss(_mm_shuffle_ps(v, v, 0xaa), s1);
    float f;
    _mm_store_ss(&f, s);
    return f;
}
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_cmplt_ps(__m128 a, __m128 b);
extern "C" int _mm_movemask_ps(__m128 a);
struct Tri
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    const hkVector4* m_p0;
    int unk14;
    int unk18;
    int unk1C;
    const hkVector4* m_p1;
    int unk24;
    int unk28;
    int unk2C;
    const hkVector4* m_p2;
};
struct Edges
{
    hkVector4 e0;
    hkVector4 e1;
    hkVector4 e2;
};
struct Result4 : hkVector4
{
    __declspec(noalias) void hkVector4_setRotatedInverseDir(const Edges* edges, const Tri* tri);
};
struct Shape
{
    int unk00;
    int unk04;
    int unk08;
    int m_iThirdValue;
    int m_10;
    int hkWingedEdge_findVisibilityBoundaryEdges(const Tri* tri, const hkVector4* pos, int* outA, int* outB);
    int AllocateTriangleFan(int a, int b, const hkVector4* pos);
};
struct Tester
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
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    hkVector4 m_40;
    int ComputeValues_00df9c90(Shape* shape, const Tri* tri, const hkVector4* pos, int* result);
};

extern "C" void _ReadWriteBarrier();
extern "C" void _ReadBarrier();
extern "C" void _ReadWriteBarrier();
#include <math.h>
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_mul_ss(__m128, __m128);
extern "C" __m128 _mm_sub_ss(__m128, __m128);
extern "C" __m128 _mm_load_ss(const float*);
extern "C" void _mm_store_ss(float*, __m128);
extern "C" __m128 _mm_rsqrt_ss(__m128);
extern "C" __m128 _mm_cmpeq_ss(__m128, __m128);
extern "C" __m128 _mm_andnot_ps(__m128, __m128);
extern "C" __m128 _mm_and_ps(__m128, __m128);
extern "C" __m128 _mm_xor_ps(__m128, __m128);
extern "C" __m128 _mm_sqrt_ss(__m128);
extern "C" double fabs(double);
extern "C" __m128 _mm_setzero_ps();
extern "C" __m128 _mm_set_ss(float);
extern const __m128 DAT_010c44d0;
extern const __m128 DAT_01268380;
extern const __m128 DAT_01017d10;
extern const __m128 DAT_010ec7f0;
extern const float DAT_01011d78;
extern const float DAT_01017718;
extern const float DAT_01016248;
extern const double DAT_010c9300;
extern const int DAT_01267e30;
void __cdecl Hkpconvexpenetrationutil_ComputeTriangleBarycentricCoordinates(const void* g, void* a, void* b, void* c, void* out);

struct Scalar
{
    __m128 v;
    __forceinline operator float() const
    {
        float f;
        _mm_store_ss(&f, v);
        return f;
    }
};
__forceinline void hkVector4::sub(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
}
__forceinline Scalar hkVector4::dot(const hkVector4& b) const
{
    __m128 t = _mm_mul_ps(m_vComponents, b.m_vComponents);
    __m128 xy = _mm_add_ss(_mm_shuffle_ps(t, t, 0x55), t);
    Scalar s;
    s.v = _mm_add_ss(_mm_shuffle_ps(t, t, 0xaa), xy);
    return s;
}
__forceinline Scalar hkVector4::sum() const
{
    __m128 xy = _mm_add_ss(_mm_shuffle_ps(m_vComponents, m_vComponents, 0x55), m_vComponents);
    Scalar s;
    s.v = _mm_add_ss(_mm_shuffle_ps(m_vComponents, m_vComponents, 0xaa), xy);
    return s;
}
__forceinline void hkVector4::cross(const hkVector4& a, const hkVector4& b)
{
    __m128 x = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xc9), _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xd2));
    __m128 y = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xd2), _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xc9));
    m_vComponents = _mm_sub_ps(x, y);
}
__forceinline void hkVector4::normalize()
{
    __m128 half = _mm_set_ss(0.5f);
    __m128 three = _mm_set_ss(3.0f);
    __m128 zero = _mm_set_ss(0.0f);
    __m128 len = dot(*this).v;
    __m128 eq = _mm_cmpeq_ss(len, zero);
    __m128 inv = _mm_rsqrt_ss(len);
    __m128 factor = _mm_mul_ss(_mm_mul_ss(half, inv), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len, inv), inv)));
    factor = _mm_andnot_ps(eq, factor);
    m_vComponents = _mm_mul_ps(_mm_shuffle_ps(factor, factor, 0), m_vComponents);
}

struct Support
{
    hkVector4 c, a, b;
    int flag;
};
struct Output
{
    hkVector4 direction, point;
    float distance;
};
struct Host
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
    hkVector4 v30;
    float f40;
    int unk44;
    int unk48;
    int unk4c;
    float thresh;
    int unk54;
    int unk58;
    int unk5c;
    hkVector4* mat;
    int unk64;
    hkVector4* pts;
    int feat;
    void UpdateState_00df9b50(const hkVector4* direction, Support* support);
    void PushVectorTriple(const Support* support);
    void ComputeValues_00df9ef0(const hkVector4* direction, const hkVector4* point, Support* support, float* distance);
    int ProcessAndReturnValue_00df9fe0(Output* out, int* pfeat);
};

static inline float absScalar(float v)
{
    return fabsf(v);
}
static __forceinline void makePerp(const hkVector4& edge, hkVector4& perp)
{
    int idx = 0, other = 1, sel = 2;
    float a0 = absScalar(edge.m_vComponents.m128_f32[0]);
    float a1 = absScalar(edge.m_vComponents.m128_f32[1]);
    float a2 = absScalar(edge.m_vComponents.m128_f32[2]);
    if (a1 < a0)
    {
        other = 0;
        idx = 1;
        a0 = a1;
    }
    if (a2 < a0)
    {
        sel = idx;
        idx = 2;
    }
    perp.m_vComponents = _mm_setzero_ps();
    perp.m_vComponents.m128_f32[other] = edge.m_vComponents.m128_f32[sel];
    perp.m_vComponents.m128_f32[sel] = -edge.m_vComponents.m128_f32[other];
}
// @fnv 0x00df9fe0
// src: GUESS 0x00df9fe0 (confidence: low)
int Host::ProcessAndReturnValue_00df9fe0(Output* out, int* pfeat)
{
    const hkVector4* point;
    int best = -1;
    hkVector4 normal, initial, scratch;
    Support support, support2;
    switch (feat)
    {
    case 0:
        goto stage0;
    case 1:
        goto stage1;
    case 2:
        goto stage2;
    case 3:
        goto stage3;
    case 4:
        goto stage4;
    default:
        goto failedDefault;
    }
stage4: {
    hkVector4 e1, e2, d;
    e1.sub(pts[0], pts[1]);
    e2.sub(pts[1], pts[2]);
    normal.cross(e1, e2);
    float len = normal.dot(normal);
    d.sub(pts[3], pts[0]);
    float dot = normal.dot(d);
    float prod = thresh * len;
    if (dot * dot <= prod)
    {
        if (best < 3)
        {
            feat = 3;
            goto stage3;
        }
        *pfeat = 3;
        _ReadWriteBarrier();
        return 1;
    }
    *pfeat = 0;
    _ReadWriteBarrier();
    return 0;
}
stage3: {
    hkVector4 e1, e2;
    e1.sub(pts[0], pts[1]);
    e2.sub(pts[1], pts[2]);
    normal.cross(e1, e2);
    float len = normal.dot(normal);
    if (len == 0.0f)
    {
        int two = 2;
        if (best < two)
        {
            feat = two;
            goto stage2;
        }
        goto outLine;
    }
    goto triangleSupport;
}
stage2: {
    hkVector4 e;
    e.sub(pts[0], pts[1]);
    float len = e.dot(e);
    if (!(len <= thresh))
        goto lineSupport;
}
    if (best < 1)
    {
        feat = 1;
        goto stage1;
    }
    *pfeat = 3;
    return 1;
stage1: {
    point = pts;
    float len = point[0].dot(point[0]);
    if (!(len <= thresh))
        goto pointSupport;
}
    if (best < 0)
    {
        feat = 0;
        goto stage0;
    }
    *pfeat = 3;
    return 1;
stage0: {
    Scalar simdLen = v30.dot(v30);
    _ReadBarrier();
    float lv = simdLen;
    {
        __m128 mask = DAT_010c44d0;
        __m128 v = v30.m_vComponents;
        initial.m_vComponents = _mm_xor_ps(v, mask);
    }
    if (lv <= thresh)
        initial.m_vComponents = DAT_01268380;
    UpdateState_00df9b50(&initial, &support);
    PushVectorTriple(&support);
    point = pts;
    float nextLen = point[0].dot(point[0]);
    if (nextLen <= thresh)
        goto outPoint;
    best = 0;
    goto stage1;
}
pointSupport: {
    point = pts;
    best = 1;
    UpdateState_00df9b50(point, &support2);
    hkVector4 delta, negative;
    delta.sub(support2.c, pts[0]);
    float distance = delta.dot(delta);
    negative.m_vComponents = _mm_xor_ps(point->m_vComponents, DAT_010c44d0);
    UpdateState_00df9b50(&negative, &support);
    hkVector4 delta2;
    delta2.sub(support.c, pts[0]);
    float distance2 = delta2.dot(delta2);
    if (distance >= distance2)
    {
        PushVectorTriple(&support2);
        goto stage2;
    }
    PushVectorTriple(&support);
    goto stage2;
}
lineSupport: {
    hkVector4 perp, second;
    scratch.sub(pts[0], pts[1]);
    best = 2;
    makePerp(scratch, perp);
    second.cross(scratch, perp);
    perp.normalize();
    second.normalize();
    float d1, d2;
    ComputeValues_00df9ef0(&perp, pts, &support, &d1);
    ComputeValues_00df9ef0(&second, pts, &support2, &d2);
    if (d1 > d2)
    {
        PushVectorTriple(&support);
        goto stage3;
    }
    PushVectorTriple(&support2);
    goto stage3;
}
triangleSupport: {
    best = 3;
    normal.normalize();
    float distance;
    ComputeValues_00df9ef0(&normal, pts, &support, &distance);
    if (distance < f40)
        goto outTriangle;
    PushVectorTriple(&support);
    goto stage4;
}
outPoint: {
    const hkVector4* finalPoint = pts;
    Scalar len;
    len.v = _mm_sqrt_ss(finalPoint[0].dot(finalPoint[0]).v);
    out->distance = len;
    out->direction = initial;
    out->point = support.a;
    *pfeat = 0;
    _ReadWriteBarrier();
    return 1;
}
outLine: {
    out->distance = 0.0f;
    hkVector4 edge;
    edge.sub(pts[0], pts[1]);
    makePerp(edge, out->direction);
    out->direction.normalize();
    hkVector4 ab;
    ab.m_vComponents = _mm_and_ps(pts[0].m_vComponents, DAT_01017d10);
    float s = ab.sum(), u = ab.sum();
    float t = s / (s + u + DAT_010c9300);
    __m128 ts = _mm_load_ss(&t);
    ts = _mm_shuffle_ps(ts, ts, 0);
    out->point.m_vComponents = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(DAT_010ec7f0, ts), mat[0].m_vComponents), _mm_mul_ps(mat[1].m_vComponents, ts));
    *pfeat = 0;
    _ReadWriteBarrier();
    return 1;
}
outTriangle: {
    out->distance = 0.0f;
    out->direction = normal;
    Hkpconvexpenetrationutil_ComputeTriangleBarycentricCoordinates(&DAT_01267e30, pts, &pts[1], &pts[2], &scratch);
    __m128 c0 = _mm_load_ss(&scratch.m_vComponents.m128_f32[0]);
    __m128 c1, c2;
    {
        float y = scratch.m_vComponents.m128_f32[1];
        c1 = _mm_load_ss(&y);
    }
    {
        float z = scratch.m_vComponents.m128_f32[2];
        c2 = _mm_load_ss(&z);
    }
    __m128 t1 = _mm_mul_ps(_mm_shuffle_ps(c1, c1, 0), mat[1].m_vComponents);
    __m128 t0 = _mm_mul_ps(_mm_shuffle_ps(c0, c0, 0), mat[0].m_vComponents);
    __m128 t2 = _mm_mul_ps(_mm_shuffle_ps(c2, c2, 0), mat[2].m_vComponents);
    out->point.m_vComponents = _mm_add_ps(_mm_add_ps(t1, t0), t2);
    *pfeat = 0;
    _ReadWriteBarrier();
    return 1;
}
failedDefault:
    *pfeat = 3;
    return 1;
}
