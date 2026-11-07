#define FNV64_HKVECTOR4_OWN_COPY   // this unit defines its own hkVector4 copy form
// src/havok/physics/collide/shape/convex/cylinder/hkpcylindershape_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/shape/convex/cylinder/hkpcylindershape_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/collide/shape/convex/cylinder/hkpcylindershape_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/shape/convex/cylinder/hkpcylindershape.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/collide/shape/convex/cylinder/hkpcylindershape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/convex/cylinder/hkpcylindershape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../../include/hkBaseObject.h"
#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../include/hkpConvexShape.h"
#include "../../../../../../../include/hkpShape.h"
#include "../../../../../../../include/hkpSphereRepShape.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkStackMemory.h"
#include "../../../../../../../include/hkSimdReal.h"
#include "../../../../../../../include/hkAabb.h"
#include "../../../../../../../include/hkVector4_S.h"
#include "../../../../../../../include/hkpCapsuleShape.h"
#include "../../../../../../../include/hkpCylinderShape.h"
#include "../../../../../../../include/hkThreadLocalData.h"
#include "../../../../../../../include/hkTransform.h"
#include <string.h>
__forceinline hkVector4::hkVector4(const hkVector4& v) { memcpy(this, &v, sizeof(*this)); }

int __cdecl hkpCylinderShape_ReturnConstant_0x12();
// FUN_00d571a0: __thiscall getter returning the float at this+0x14,
// which is hkpCylinderShape::m_fCylinderRadius in the pack's layout
//  m_type 0xC, m_fSphereRadius 0x10, m_fCylinderRadius 0x14).
extern char DAT_01268940[];
void __cdecl hkReferencedObject_calcContentStatistics(void* item, const char* type);
void __cdecl hkpCylinderShape_calcContentStatistics(void* item, const char*);

#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged
extern char DAT_010305a8;
extern char DAT_010d0f1c;
extern float DAT_011b5be8;
// src: HAVOK_LIB 0x00d571d0
static __declspec(noinline) float minValueRoundedUpTo1()
{
    return 0.0f;
}

#include <xmmintrin.h>

#include <xmmintrin.h>
#include <math.h>

struct CylVec4
{
    __m128 m_vComponents;
    void setMul4(float r, const CylVec4& a) { m_vComponents = _mm_mul_ps(_mm_set1_ps(r), a.m_vComponents); }
    void addMul4(float r, const CylVec4& a) { m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(_mm_set1_ps(r), a.m_vComponents)); }
    void mul4(float r) { m_vComponents = _mm_mul_ps(m_vComponents, _mm_set1_ps(r)); }
    void add4(const CylVec4& a) { m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents); }
    void setInt24W(int value) { ((int*)this)[3] = value | 0x3f000000; }
};

struct CylShapeAdapter : public hkpCylinderShape
{
    void __thiscall hkpCylinderShape_convertVertexIdsToVerticesImpl(const unsigned short* ids, int numIds, CylVec4* verticesOut) const;
};

extern float DAT_011b5be4;
struct CylSimd
{
    __m128 m_vValue;
    CylSimd(const float& x) { m_vValue = _mm_load_ss(&x); }
    __m128 broadcast() const { return _mm_shuffle_ps(m_vValue, m_vValue, 0); }
};

static inline float CylSqrt(float r) { return (float)sqrt(r); }

// @fnv 0x00d576d0
// src: XBOX_PDB 0x00d576d0
void CylShapeAdapter::hkpCylinderShape_convertVertexIdsToVerticesImpl(const unsigned short* ids, int numIds, CylVec4* verticesOut) const
{
    for (int i = numIds - 1; i >= 0;)
    {
        int id = ids[0];

        float value = float(ids[0] & 15) + 0.5;
        int sinSign = (ids[0] >> 6) & 1;
        int isBaseA = (ids[0] >> 7) & 1;
        int cosSign = (ids[0] >> 5) & 1;
        value *= DAT_011b5be4;
        float other = CylSqrt(1.0f - value * value);

        float cosValue;
        float sinValue;
        if (ids[0] & 0x10)
        {
            sinValue = value;
            cosValue = other;
        }
        else
        {
            cosValue = value;
            sinValue = other;
        }
        if (!sinSign) sinValue = -sinValue;
        if (!cosSign) cosValue = -cosValue;

        --i;
        __m128 tmp = _mm_add_ps(_mm_mul_ps(CylSimd(sinValue).broadcast(), reinterpret_cast<const __m128&>(m_kPerpendicular2)), _mm_mul_ps(CylSimd(cosValue).broadcast(), reinterpret_cast<const __m128&>(m_kPerpendicular1)));
        CylVec4& vertex = *verticesOut;
        vertex.m_vComponents = _mm_add_ps(_mm_mul_ps(tmp, CylSimd(m_fCylinderRadius).broadcast()), reinterpret_cast<const __m128&>((&m_kVertexA)[1 - isBaseA]));
        vertex.setInt24W(id);
        ++verticesOut;
        ids++;
    }
}

__declspec(align(16)) static const unsigned int g_wClearMask[4] = { 0xffffffff, 0xffffffff, 0xffffffff, 0 };

struct VertexOutput { hkVector4* p; VertexOutput(hkVector4* q) : p(q) {} };

static inline __m128 scalar(float value) { return _mm_load_ss(&value); }

class CylVertices : public hkpCylinderShape {
public:
    hkVector4* hkpCylinderShape_getCollisionSpheresImpl(VertexOutput output);
    hkVector4* prime(VertexOutput output);
};

hkVector4* CylVertices::prime(VertexOutput output)
{
    __m128 offA, sC, kA, kB;
    hkVector4* v = &m_kVertexA;
    float cylRadius = m_fCylinderRadius;
    __m128 vA = _mm_load_ps(&m_kVertexA.x);
    __m128 vB = _mm_load_ps(&m_kVertexB.x);
    __m128 diff = _mm_sub_ps(vB, vA);
    __m128 sq = _mm_mul_ps(diff, diff);
    __m128 t1 = _mm_shuffle_ps(sq, sq, 0x55);
    __m128 s1 = _mm_add_ss(t1, sq);
    __m128 t2 = _mm_shuffle_ps(sq, sq, 0xaa);
    __m128 s2 = _mm_add_ss(t2, s1);
    float lenSq;
    _mm_store_ss(&lenSq, s2);

    float s = cylRadius;
    float c = 0.0f;
    if (lenSq >= cylRadius * 4.0 * cylRadius) {
        c = cylRadius;
        s = cylRadius * m_fCylinderRadiusSquared;
    }

    __m128 p2 = _mm_load_ps(&m_kPerpendicular2.x);
    __m128 mask = _mm_load_ps((const float*)g_wClearMask);
    __m128 p2c = _mm_load_ps(&m_kPerpendicular2.x);
    float k = (float)(s * 0.7071067690849304);
    kA = scalar((float)(k));
    __m128 kAs = _mm_shuffle_ps(kA,kA,0);
    kB = scalar((float)(0.7071067690849304 * s));
    float radius = m_fSphereRadius;
    __m128 s0 = _mm_load_ss(&s);
    sC = s0;
    __m128 sA = sC;
    __m128 p1 = _mm_load_ps(&m_kPerpendicular1.x);
    __m128 kBs = _mm_shuffle_ps(kB,kB,0);
    offA = _mm_mul_ps(_mm_shuffle_ps(sA,sA,0),p1);
    p2c = _mm_add_ps(p1,p2c);
    __m128 offB = _mm_mul_ps(kAs,p2c);
    __m128 sS = _mm_shuffle_ps(_mm_load_ss(&s),_mm_load_ss(&s),0);
    __m128 dif = _mm_sub_ps(p1,p2);
    __m128 offC = _mm_mul_ps(sS,p2);
    offA = _mm_and_ps(offA,mask);
    offC = _mm_and_ps(offC,mask);
    offB = _mm_and_ps(offB,mask);
    __m128 offD = _mm_mul_ps(kBs,dif);
    offD = _mm_and_ps(offD,mask);

    hkVector4* out = output.p;
    hkVector4* o = out + 2;
    int i = 2;
    do {
        hkVector4 temp = *v;
        temp.w = radius;
        __m128 p = _mm_load_ps(&temp.x);
        _mm_store_ps(&o[-2].x, _mm_add_ps(p, offA));
        _mm_store_ps(&o[-1].x, _mm_add_ps(p, offB));
        _mm_store_ps(&o[0].x, _mm_add_ps(p, offC));
        _mm_store_ps(&o[1].x, _mm_sub_ps(p, offD));
        _mm_store_ps(&o[2].x, _mm_sub_ps(p, offA));
        _mm_store_ps(&o[3].x, _mm_sub_ps(p, offB));
        _mm_store_ps(&o[4].x, _mm_sub_ps(p, offC));
        _mm_store_ps(&o[5].x, _mm_add_ps(p, offD));
        ++v;
        o += 8;
        --i;
    } while (i != 0);

    __m128 q2 = _mm_load_ps(&m_kPerpendicular2.x);
    __m128 q1 = _mm_load_ps(&m_kPerpendicular1.x);
    __m128 lhs = _mm_shuffle_ps(q1, q1, 0xc9);
    __m128 rhs = _mm_shuffle_ps(q2, q2, 0xd2);
    lhs = _mm_mul_ps(rhs, lhs);
    rhs = _mm_shuffle_ps(q1, q1, 0xd2);
    q2 = _mm_shuffle_ps(q2, q2, 0xc9);
    rhs = _mm_mul_ps(q2, rhs);
    __m128 cross = _mm_sub_ps(lhs, rhs);
    float nc = -c;
    __m128 c0 = _mm_load_ss(&c);
    __m128 c1 = _mm_shuffle_ps(c0, c0, 0);
    __m128 a0 = _mm_load_ps(&m_kVertexA.x);
    __m128 e1 = _mm_mul_ps(c1, cross);
    e1 = _mm_add_ps(e1, a0);
    _mm_store_ps(&out[16].x, e1);
    __m128 n0 = _mm_load_ss(&nc);
    __m128 n1 = _mm_shuffle_ps(n0, n0, 0);
    __m128 b0 = _mm_load_ps(&m_kVertexB.x);
    __m128 e2 = _mm_mul_ps(n1, cross);
    e2 = _mm_add_ps(e2, b0);
    _mm_store_ps(&out[17].x, e2);
    out[16].w = c + radius;
    out[17].w = c + radius;
    return out;
}
// @fnv 0x00d57890
// src: XBOX_PDB 0x00d57890
hkVector4* CylVertices::hkpCylinderShape_getCollisionSpheresImpl(VertexOutput output)
{
    __m128 offA, sC, kA, kB;
    hkVector4* v = &m_kVertexA;
    float cylRadius = m_fCylinderRadius;
    __m128 vA = _mm_load_ps(&m_kVertexA.x);
    __m128 vB = _mm_load_ps(&m_kVertexB.x);
    __m128 diff = _mm_sub_ps(vB, vA);
    __m128 sq = _mm_mul_ps(diff, diff);
    __m128 t1 = _mm_shuffle_ps(sq, sq, 0x55);
    __m128 s1 = _mm_add_ss(t1, sq);
    __m128 t2 = _mm_shuffle_ps(sq, sq, 0xaa);
    __m128 s2 = _mm_add_ss(t2, s1);
    float lenSq;
    _mm_store_ss(&lenSq, s2);

    float s = cylRadius;
    float c = 0.0f;
    if (lenSq >= cylRadius * 4.0 * cylRadius) {
        c = cylRadius;
        s = cylRadius * m_fCylinderRadiusSquared;
    }

    __m128 p2 = _mm_load_ps(&m_kPerpendicular2.x);
    __m128 mask = _mm_load_ps((const float*)g_wClearMask);
    __m128 p2c = _mm_load_ps(&m_kPerpendicular2.x);
    float k = (float)(s * 0.7071067690849304);
    kA = scalar((float)(k));
    __m128 kAs = _mm_shuffle_ps(kA,kA,0);
    kB = scalar((float)(0.7071067690849304 * s));
    float radius = m_fSphereRadius;
    __m128 s0 = _mm_load_ss(&s);
    sC = s0;
    __m128 sA = sC;
    __m128 p1 = _mm_load_ps(&m_kPerpendicular1.x);
    __m128 kBs = _mm_shuffle_ps(kB,kB,0);
    offA = _mm_mul_ps(_mm_shuffle_ps(sA,sA,0),p1);
    p2c = _mm_add_ps(p1,p2c);
    __m128 offB = _mm_mul_ps(kAs,p2c);
    __m128 sS = _mm_shuffle_ps(_mm_load_ss(&s),_mm_load_ss(&s),0);
    __m128 dif = _mm_sub_ps(p1,p2);
    __m128 offC = _mm_mul_ps(sS,p2);
    offA = _mm_and_ps(offA,mask);
    offC = _mm_and_ps(offC,mask);
    offB = _mm_and_ps(offB,mask);
    __m128 offD = _mm_mul_ps(kBs,dif);
    offD = _mm_and_ps(offD,mask);

    hkVector4* out = output.p;
    hkVector4* o = out + 2;
    int i = 2;
    do {
        hkVector4 temp = *v;
        temp.w = radius;
        __m128 p = _mm_load_ps(&temp.x);
        _mm_store_ps(&o[-2].x, _mm_add_ps(p, offA));
        _mm_store_ps(&o[-1].x, _mm_add_ps(p, offB));
        _mm_store_ps(&o[0].x, _mm_add_ps(p, offC));
        _mm_store_ps(&o[1].x, _mm_sub_ps(p, offD));
        _mm_store_ps(&o[2].x, _mm_sub_ps(p, offA));
        _mm_store_ps(&o[3].x, _mm_sub_ps(p, offB));
        *reinterpret_cast<__m128*>(&o[4]) = _mm_sub_ps(p, offC);
        *reinterpret_cast<__m128*>(&o[5]) = _mm_add_ps(p, offD);
        ++v;
        o += 8;
        --i;
    } while (i != 0);

    __m128 q2 = _mm_load_ps(&m_kPerpendicular2.x);
    __m128 q1 = _mm_load_ps(&m_kPerpendicular1.x);
    __m128 lhs = _mm_shuffle_ps(q1, q1, 0xc9);
    __m128 rhs = _mm_shuffle_ps(q2, q2, 0xd2);
    lhs = _mm_mul_ps(rhs, lhs);
    rhs = _mm_shuffle_ps(q1, q1, 0xd2);
    q2 = _mm_shuffle_ps(q2, q2, 0xc9);
    rhs = _mm_mul_ps(q2, rhs);
    __m128 cross = _mm_sub_ps(lhs, rhs);
    float nc = -c;
    __m128 c0 = _mm_load_ss(&c);
    __m128 c1 = _mm_shuffle_ps(c0, c0, 0);
    __m128 a0 = _mm_load_ps(&m_kVertexA.x);
    __m128 e1 = _mm_mul_ps(c1, cross);
    e1 = _mm_add_ps(e1, a0);
    _mm_store_ps(&out[16].x, e1);
    __m128 n0 = _mm_load_ss(&nc);
    __m128 n1 = _mm_shuffle_ps(n0, n0, 0);
    __m128 b0 = _mm_load_ps(&m_kVertexB.x);
    __m128 e2 = _mm_mul_ps(n1, cross);
    e2 = _mm_add_ps(e2, b0);
    _mm_store_ps(&out[17].x, e2);
    out[16].w = c + radius;
    out[17].w = c + radius;
    return out;
}

#include <xmmintrin.h>
#include <math.h>

struct __declspec(align(16)) hkVector4A {
    hkReal x, y, z, w;
    inline void setMax4(const hkVector4A& a, const hkVector4A& b) {
        *(__m128*)this = _mm_max_ps(*(__m128*)&a, *(__m128*)&b);
    }
    inline void setMin4(const hkVector4A& a, const hkVector4A& b) {
        *(__m128*)this = _mm_min_ps(*(__m128*)&a, *(__m128*)&b);
    }
    inline void sub4(const hkVector4A& a) {
        *(__m128*)this = _mm_sub_ps(*(__m128*)this, *(__m128*)&a);
    }
    inline void add4(const hkVector4A& a) {
        *(__m128*)this = _mm_add_ps(*(__m128*)this, *(__m128*)&a);
    }
};

struct Lane61 {
    __m128 value;
    Lane61(const float& f) { value = _mm_load_ss(&f); }
    const __m128& get() const { return value; }
    __m128 splat() const { return _mm_shuffle_ps(get(), get(), 0); }
};
struct __declspec(align(16)) Vector61 {
    union { __m128 value; float component[4]; };
    __m128 quad() const { return _mm_load_ps(component); }
    float& at(int i) { return component[i]; }
    void scale(const Lane61& x) { value = _mm_mul_ps(x.splat(), quad()); }
    void sum(const Lane61& x, const Vector61& v) { value = _mm_add_ps(x.splat(), v.quad()); }
    void normalise() {
        __m128 v = quad();
        __m128 sq = _mm_mul_ps(v, v);
        __m128 y = _mm_shuffle_ps(sq, sq, 0x55);
        y = _mm_add_ss(y, sq);
        __m128 z = _mm_shuffle_ps(sq, sq, 0xaa);
        z = _mm_add_ss(z, y);
        z = _mm_rsqrt_ss(z);
        y = _mm_shuffle_ps(z, z, 0);
        value = _mm_mul_ps(y, v);
    }
};

// @fnv 0x00d57b70
void hkpCylinderShape::CalculateAabb(const hkTransform& localToWorld, hkReal tolerance, hkAabb& out) const
{
    hkVector4 c0 = reinterpret_cast<const hkVector4&>(localToWorld.m_row0);
    hkVector4 c1 = reinterpret_cast<const hkVector4&>(localToWorld.m_row1);
    hkVector4 c2 = reinterpret_cast<const hkVector4&>(localToWorld.m_row2);
    hkVector4 tr = reinterpret_cast<const hkVector4&>(localToWorld.m_row3);

    __declspec(align(16)) hkVector4A transVertices[2];

    const hkVector4* vertices = &m_kVertexA;
    for (int i = 1; i >= 0; --i)
    {
        __m128 vb = *(__m128*)&vertices[i];
        __m128 col0 = *(__m128*)&c0;
        __m128 col1 = *(__m128*)&c1;
        __m128 col2 = *(__m128*)&c2;
        __m128 trans = *(__m128*)&tr;

        __m128 vy = _mm_shuffle_ps(vb, vb, 0x55);
        __m128 vx = _mm_shuffle_ps(vb, vb, 0x00);
        __m128 r0 = _mm_mul_ps(vx, col0);
        __m128 r1 = _mm_mul_ps(vy, col1);
        __m128 sum01 = _mm_add_ps(r1, r0);

        __m128 vz = _mm_shuffle_ps(vb, vb, 0xaa);
        __m128 r2 = _mm_mul_ps(vz, col2);
        __m128 sum2tr = _mm_add_ps(r2, trans);
        __m128 res = _mm_add_ps(sum01, sum2tr);

        *(__m128*)&transVertices[i] = res;
    }

    __m128 dir = _mm_sub_ps(*(__m128*)&transVertices[1], *(__m128*)&transVertices[0]);

    __m128 d0 = _mm_mul_ps(dir, dir);
    __m128 d2 = _mm_shuffle_ps(d0, d0, 0x55);
    d2 = _mm_add_ss(d2, d0);
    __m128 d3 = _mm_shuffle_ps(d0, d0, 0xaa);
    d3 = _mm_add_ss(d3, d2);
    d3 = _mm_rsqrt_ss(d3);
    d2 = _mm_shuffle_ps(d3, d3, 0);
    dir = _mm_mul_ps(d2, dir);

    Vector61 normDir;
    *(__m128*)&normDir = dir;

    float dx = (float)((double)1.01f - normDir.at(0) * normDir.at(0));
    normDir.at(0) = (float)sqrt(dx);
    float dy = (float)((double)1.01f - normDir.at(1) * normDir.at(1));
    normDir.at(1) = (float)sqrt(dy);
    float dz = (float)((double)1.01f - normDir.at(2) * normDir.at(2));
    normDir.at(2) = (float)sqrt(dz);

    normDir.scale(Lane61(m_fCylinderRadius));
    float total = m_fSphereRadius + tolerance;
    Vector61 expansion;
    expansion.sum(Lane61(total), normDir);

    ((hkVector4A*)&out.m_kMinimumCorner)->setMin4(transVertices[0], transVertices[1]);
    ((hkVector4A*)&out.m_kMinimumCorner)->sub4(*(hkVector4A*)&expansion);
    ((hkVector4A*)&out.m_kMaximumCorner)->setMax4(transVertices[0], transVertices[1]);
    ((hkVector4A*)&out.m_kMaximumCorner)->add4(*(hkVector4A*)&expansion);
}

#include <math.h>
#include <xmmintrin.h>
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkMemoryAllocator.h"

// Cylinder tessellation factor, its reciprocal, and the fistp rounding bias.
// factor/inv are filled by the shape's static init; bias starts negative and
// is replaced by the first constructor.
extern const float DAT_010cb428 = 1.4210854715202004e-14f;
extern const double DAT_0103c7c8 = (double)0.05f;
extern float DAT_011b5be0;
extern float DAT_011b5be4;
extern float DAT_011b5be8;

struct CylinderSupportArithmetic {
    __m128 q;
    __forceinline float dot(const CylinderSupportArithmetic& other) const {
    __m128 a = q, b = other.q;
    __m128 p = _mm_mul_ps(a, b);
    __m128 s = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
    __m128 t = _mm_add_ss(_mm_shuffle_ps(p, p, 0xAA), s);
    float r;
    _mm_store_ss(&r, t);
    return r;
}
};

struct CylinderSupportStore : CylinderSupportArithmetic {
    __forceinline void assign(__m128 value,int id) {
        q = value;
        reinterpret_cast<unsigned int*>(&q)[3] = (unsigned int)id | 0x3f000000u;
    }
};
class CylinderSupportShape : public hkpCylinderShape {
public:
    void hkpCylinderShape_getSupportingVertexImpl(const hkVector4& direction, CylinderSupportStore& output) const;
};

// @fnv 0x00d57400
// src: XBOX_PDB 0x00d57400
void CylinderSupportShape::hkpCylinderShape_getSupportingVertexImpl(const hkVector4& direction, CylinderSupportStore& output) const
{
    int vertexId;
    {
    const float eps = 1.19209290e-7f;
    const CylinderSupportArithmetic& dir = *reinterpret_cast<const CylinderSupportArithmetic*>(&direction);
    __m128 axis = _mm_sub_ps(_mm_load_ps(&m_kVertexB.x), _mm_load_ps(&m_kVertexA.x));
    float u = dir.dot(*reinterpret_cast<const CylinderSupportArithmetic*>(&m_kPerpendicular1));
    float v = dir.dot(*reinterpret_cast<const CylinderSupportArithmetic*>(&m_kPerpendicular2));
    float len2 = u * u + v * v;

    if (len2 >= eps * eps)
    {
        float invLen = 1.0f / sqrtf(len2);
        v *= invLen;
        u *= invLen;
    }
    else
    {
        v = 0.0f;
        u = 1.0f;
    }

    int vSign = (v >= 0.0f);
    int uSign = (u >= 0.0f);
    float absV = fabsf(v);
    float absU = fabsf(u);
    int sinLesser;
    float minAbs;
    if (absV <= absU)
    {
        sinLesser = 1;
        minAbs = absV;
    }
    else
    {
        sinLesser = 0;
        minAbs = absU;
    }

    int isBaseA = (dir.dot(*reinterpret_cast<const CylinderSupportArithmetic*>(&axis)) <= 0.0f);
    float factor = DAT_011b5be0;
    float bias = DAT_011b5be8;
    int angleIndex = fnv_FloatToInt((float)((factor * minAbs - bias) + DAT_0103c7c8));
    vertexId = (sinLesser + 2 * (uSign + 2 * (vSign + 2 * isBaseA))) << 4;
    vertexId += angleIndex;

    }
    float u,v;
    int idx = vertexId & hkpCylinderShape::VERTEX_ID_ENCODING_VALUE_MASK;
    unsigned short id16 = (unsigned short)vertexId;
    float half = (float)(idx + 0.5);
    int baseBit = (id16 >> hkpCylinderShape::VERTEX_ID_ENCODING_IS_BASE_A_SHIFT) & 1;
    int sinSign = (id16 >> hkpCylinderShape::VERTEX_ID_ENCODING_SIN_SIGN_SHIFT) & 1;
    int cosSign = (id16 >> hkpCylinderShape::VERTEX_ID_ENCODING_COS_SIGN_SHIFT) & 1;
    float s = half * DAT_011b5be4;
    float c = sqrtf(1.0f - s * s);

    if (vertexId & (1 << hkpCylinderShape::VERTEX_ID_ENCODING_IS_SIN_LESSER_SHIFT))
    {
        v = s;
        u = c;
    }
    else
    {
        u = s;
        v = c;
    }
    if (sinSign == 0)
        v = -v;
    if (cosSign == 0)
        u = -u;

    __m128 uLoad = _mm_load_ss(&u);
    __m128 vLoad = _mm_load_ss(&v);
    __m128 radial = _mm_add_ps(
        _mm_mul_ps(_mm_shuffle_ps(vLoad,vLoad,0), _mm_load_ps(&m_kPerpendicular2.x)),
        _mm_mul_ps(_mm_shuffle_ps(uLoad, uLoad, 0), _mm_load_ps(&m_kPerpendicular1.x)));
    __m128 scaled = _mm_mul_ps(radial, _mm_shuffle_ps(_mm_load_ss(&m_fCylinderRadius), _mm_load_ss(&m_fCylinderRadius), 0));
    int slot = 3 - baseBit;
    const hkVector4* vecs = reinterpret_cast<const hkVector4*>(this);
    __m128 support = _mm_add_ps(scaled, _mm_load_ps(&vecs[slot].x));
    output.assign(support,vertexId);
}

#include <math.h>
typedef unsigned char hkUint8_S;
typedef unsigned short hkUint16_S;
typedef unsigned int hkUint32_S;
typedef unsigned long __w64 hkUlong_S;
typedef unsigned __w64 hk_size_t;

typedef float hkReal_S;

;
typedef __m128 hkQuadReal;
extern const __m128 DAT_010ec7f0;

inline hkSimdReal::hkSimdReal(const __m128& x) : m_vValue(x) {}
inline hkSimdReal::hkSimdReal(float x) { m_vValue = _mm_load_ss(&x); }
inline hkSimdReal::operator float() const { float s; _mm_store_ss(&s, m_vValue); return s; }
__forceinline __m128 hkSimdReal::broadcast() const { return _mm_shuffle_ps(m_vValue, m_vValue, 0); }
__forceinline const __m128& hkSimdReal::getQuad() const { return m_vValue; }
typedef const hkSimdReal&hkSimdRealParameter;class Vector4Comparison;
typedef const Vector4Comparison&hkVector4ComparisonParameter;extern "C"{
double __cdecl sqrt([SA_Pre(Null=SA_No)][SA_Pre(Deref=1,Valid=SA_Yes,Access=SA_Read)]double _X);
}
namespace MathUtilities
{
inline hkReal_S __cdecl sqrt(hkReal_S r){return::sqrtf(r);}
}
__forceinline void hkVector4_S::operator=(const hkVector4_S&v)
{
m_vComponents=v.m_vComponents;
}
__forceinline void hkVector4_S::setAdd4(const hkVector4_S&v0,const hkVector4_S&v1)
{
m_vComponents=_mm_add_ps(v0.m_vComponents,v1.m_vComponents);
}
__forceinline void hkVector4_S::setSub4(const hkVector4_S&v0,const hkVector4_S&v1)
{
m_vComponents=_mm_sub_ps(v0.m_vComponents,v1.m_vComponents);
}
__forceinline void hkVector4_S::mul4(hkSimdRealParameter s)
{
m_vComponents=_mm_mul_ps(s.broadcast(),m_vComponents);
}
__forceinline void hkVector4_S::setMul4(hkSimdRealParameter r,const hkVector4_S&v1)
{
m_vComponents=_mm_mul_ps(r.broadcast(),v1.m_vComponents);
}
__forceinline void hkVector4_S::setAddMul4(const hkVector4_S&a,const hkVector4_S&b,hkSimdRealParameter r)
{
m_vComponents=_mm_add_ps(a.m_vComponents,
_mm_mul_ps(r.broadcast(),b.m_vComponents));
}
__forceinline void hkVector4_S::setCross(const hkVector4_S&v0,const hkVector4_S&v1)
{
hkQuadReal cross0;
cross0=_mm_mul_ps(
_mm_shuffle_ps(v0.m_vComponents,v0.m_vComponents,(((3)<<6)|((0)<<4)|((2)<<2)|((1)))),
_mm_shuffle_ps(v1.m_vComponents,v1.m_vComponents,(((3)<<6)|((1)<<4)|((0)<<2)|((2)))));
hkQuadReal cross1;
cross1=_mm_mul_ps(
_mm_shuffle_ps(v0.m_vComponents,v0.m_vComponents,(((3)<<6)|((1)<<4)|((0)<<2)|((2)))),
_mm_shuffle_ps(v1.m_vComponents,v1.m_vComponents,(((3)<<6)|((0)<<4)|((2)<<2)|((1)))));
m_vComponents=_mm_sub_ps(cross0,cross1);}
__forceinline void hkVector4_S::setInterpolate4(const hkVector4_S&v0,const hkVector4_S&v1,hkSimdRealParameter _t)
{
hkQuadReal t = _t.broadcast();
hkQuadReal s = _mm_sub_ps(DAT_010ec7f0, t);
hkQuadReal p0 = _mm_mul_ps(s, v0.m_vComponents);
hkQuadReal p1 = _mm_mul_ps(t, v1.m_vComponents);
m_vComponents = _mm_add_ps(p0, p1);
}
__forceinline hkSimdReal hkVector4_S::dot3(const hkVector4_S&a)const
{
hkQuadReal x2=_mm_mul_ps(m_vComponents,a.m_vComponents);
hkQuadReal xySum=_mm_add_ss(_mm_shuffle_ps(x2,x2,(((1)<<6)|((1)<<4)|((1)<<2)|((1)))),x2);
return _mm_add_ss(_mm_shuffle_ps(x2,x2,(((2)<<6)|((2)<<4)|((2)<<2)|((2)))),xySum);}
__forceinline hkSimdReal hkVector4_S::length3()const
{
return _mm_sqrt_ss(this->dot3(*this).getQuad());
}
__forceinline hkSimdReal hkVector4_S::lengthSquared3()const
{
return this->dot3(*this);
}
__forceinline hkSimdReal hkVector4_S::lengthInverse3()const
{
const hkQuadReal half=_mm_set_ss(0.5f);
const hkQuadReal three=_mm_set_ss(3.0f);
const hkQuadReal zero=_mm_set_ss(0.0f);
const hkQuadReal len2=this->dot3(*this).getQuad();
const hkQuadReal len2EqualsZero=_mm_cmpeq_ss(len2,zero);
const hkQuadReal approx=_mm_rsqrt_ss(len2);
const hkQuadReal refined=_mm_mul_ss(
_mm_mul_ss(half,approx),
_mm_sub_ss(three,_mm_mul_ss(_mm_mul_ss(len2,approx),approx)));
return _mm_andnot_ps(len2EqualsZero,refined);}
__forceinline void hkVector4_S::normalize3()
{
hkQuadReal lenInv=lengthInverse3().broadcast();
m_vComponents=_mm_mul_ps(lenInv,m_vComponents);
}
__forceinline hkSimdReal hkVector4_S::normalizeWithLength3()
{
hkQuadReal len2=this->dot3(*this).getQuad();
hkQuadReal lenInv=lengthInverse3().broadcast();
m_vComponents=_mm_mul_ps(lenInv,m_vComponents);
return _mm_mul_ss(len2,lenInv);
}

inline hkMonitorStream& hkMonitorStream::getInstance()
{
    extern hkThreadLocalData<hkMonitorStream*> g_pMonitorStream;
    return *g_pMonitorStream.getData();
}
__forceinline char* __cdecl hkMonitorStream::getEnd() { return m_end.val(); }
__forceinline char* __cdecl hkMonitorStream::getCapacityMinus16() { return m_capacityMinus16.val(); }
__forceinline hkBool __cdecl hkMonitorStream::memoryAvailable() { return getEnd() < getCapacityMinus16(); }
__forceinline void __cdecl hkMonitorStream::setEnd(char* ptr) { m_end = ptr; }
__forceinline void hkMonitorStream::TimerCommand::setTime()
{
hkUint32_S ticks;
__asm{
rdtsc
mov dword ptr[ticks],eax
}
m_time0=ticks;
}
class Vector4WithInt24W:public hkVector4_S
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}};
#include "../../../../../../../include/hkpBufferSize.h"
typedef __declspec(align(16))char hkpShapeBuffer[HK_SHAPE_BUFFER_SIZE];

typedef hkUint32_S hkpShapeKey;
struct RayCastHitResult
{
hkVector4_S m_vHitNormal;
hkReal_S m_fHitFraction;};struct ShapeRayCastOutput:public RayCastHitResult
{
public:
enum{MAX_HIERARCHY_DEPTH=8};
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
__forceinline void setKey(hkpShapeKey key);
private:
__forceinline void _reset();
public:
hkpShapeKey m_uiShapeKeys[MAX_HIERARCHY_DEPTH];
private:
int m_uiShapeKeyIndex;};inline void ShapeRayCastOutput::setKey(hkpShapeKey key)
{
m_uiShapeKeys[m_uiShapeKeyIndex]=key;
}

const hkVector4& hkpCylinderShape::getVertex(int i) const
{
    return GetIndexedVertices()[i];
}

// The shared capsule header declares the hkVector4 helpers. This unit calls
// the distinct SIMD-vector implementations, retained here as free declarations.
void __cdecl CapsuleClosestPointOnLineSegment(const hkVector4_S& A, const hkVector4_S& B,
                                              const hkVector4_S& B2, hkVector4_S& pt);
void __cdecl CapsuleClosestPointsBetweenInfiniteLines(const hkVector4_S& A, const hkVector4_S& dA,
                                                       const hkVector4_S& B, const hkVector4_S& dB,
                                                       float& distSquared, float& t, float& u,
                                                       hkVector4_S& p, hkVector4_S& q);
struct ShapeRayCastQuery
{
hkVector4_S m_vFrom;
// @fnv 0x00d57d50
hkVector4_S m_vTo;};hkBool hkpCylinderShape::IntersectRayWithShape(const ShapeRayCastQuery&input,ShapeRayCastOutput&results)const
{
const hkpCylinderShape*thisObj=this;
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="T" "t" "rcCylinder";h->setTime();mStream.setEnd((char*)(h+1));}};
hkVector4_S radiusAxis;radiusAxis.setCross(reinterpret_cast<const hkVector4_S&>(thisObj->m_kPerpendicular2),reinterpret_cast<const hkVector4_S&>(thisObj->m_kPerpendicular1));
radiusAxis.mul4(thisObj->m_fSphereRadius);
hkVector4_S vertex0;vertex0.setAdd4(reinterpret_cast<const hkVector4_S&>(thisObj->getVertex(0)),radiusAxis);
hkVector4_S vertex1;vertex1.setSub4(reinterpret_cast<const hkVector4_S&>(thisObj->getVertex(1)),radiusAxis);
hkReal_S cylTotalRadius=thisObj->m_fSphereRadius+thisObj->m_fCylinderRadius;
{
hkVector4_S res;CapsuleClosestPointOnLineSegment(input.m_vFrom,vertex0,vertex1,res);
hkVector4_S join;join.setSub4(input.m_vFrom,res);
hkReal_S sToCylDist=join.length3();
if(sToCylDist<cylTotalRadius)
{
hkVector4_S axis;axis.setSub4(vertex1,vertex0);
{
hkVector4_S fromBottom;fromBottom.setSub4(input.m_vFrom,vertex0);
hkReal_S dot1=axis.dot3(fromBottom);
if(dot1>0.0f)
{
hkVector4_S fromTop;fromTop.setSub4(input.m_vFrom,vertex1);
hkReal_S dot2=axis.dot3(fromTop);
if(dot2<0.0f)
{
goto returnFalse;
}
}
}
}
hkReal_S infInfDistSquared=3.40282e+38f;
hkReal_S t,u;
hkVector4_S p,q;
hkVector4_S dA;dA.setSub4(input.m_vTo,input.m_vFrom);
hkVector4_S dB;dB.setSub4(vertex1,vertex0);
CapsuleClosestPointsBetweenInfiniteLines(input.m_vFrom,dA,vertex0,dB,infInfDistSquared,t,u,p,q);
if(infInfDistSquared>cylTotalRadius*cylTotalRadius)
{
goto returnFalse;
}
hkVector4_S axis;axis=dB;
hkReal_S axisLength;
hkReal_S ipT;
{
const hkReal_S axisLengthSqrd=axis.lengthSquared3();
if(axisLengthSqrd>1.192092896e-07F)
{
axisLength=axis.normalizeWithLength3();
}
else
{
goto returnFalse;
}
hkVector4_S dir=dA;
hkReal_S component=dir.dot3(axis);
hkVector4_S flatDir;flatDir.setAddMul4(dir,axis,-component);
hkReal_S d=MathUtilities::sqrt(cylTotalRadius*cylTotalRadius-infInfDistSquared);
if(flatDir.lengthSquared3()!=0.0f)
{
d*=flatDir.lengthInverse3();
ipT=t-d;
}
else
{
ipT=-1.0f;
}
}
if(ipT>=results.m_fHitFraction)
{
goto returnFalse;
}
hkReal_S pointAProj=vertex0.dot3(axis);
hkVector4_S intersectPt;intersectPt.setInterpolate4(input.m_vFrom,input.m_vTo,ipT);
const hkReal_S ptProj=intersectPt.dot3(axis);
hkReal_S ptHeight=ptProj-pointAProj;
if(ipT>=0.0f&&ptHeight>0.0f&&ptHeight<axisLength)
{
hkVector4_S projPtOnAxis;projPtOnAxis.setInterpolate4(vertex0,vertex1,ptHeight / axisLength);
hkVector4_S normal;normal.setSub4(intersectPt,projPtOnAxis);
normal.normalize3();
results.m_vHitNormal=normal;
results.m_fHitFraction=ipT;
results.setKey(0xffffffff);
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="E" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};
return true;
}
else
{
const hkReal_S fromPointProj=input.m_vFrom.dot3(axis);
hkReal_S axisSign;
hkVector4_S capCenter;
if(fromPointProj<pointAProj)
{
axisSign=-1.0f;
capCenter=vertex0;
}
else if(fromPointProj>pointAProj+axisLength)
{
axisSign=1.0f;
capCenter=vertex1;
}
else
{
goto returnFalse;
}
hkReal_S hitFract;
{
hkVector4_S toCap;toCap.setSub4(capCenter,input.m_vFrom);
hitFract=hkReal_S(toCap.dot3(axis))*axisSign*-1.0f;
if(hitFract<0.0f)
{
goto returnFalse;
}
hkReal_S div=axisSign*-1.0f*hkReal_S(dA.dot3(axis));
if(hitFract>=div*results.m_fHitFraction)
{
goto returnFalse;
}
hitFract /=div;
}
hkVector4_S hitOnPlane;hitOnPlane.setInterpolate4(input.m_vFrom,input.m_vTo,hitFract);
hkReal_S dist2;
{
hkVector4_S diff;diff.setSub4(hitOnPlane,capCenter);
dist2=diff.lengthSquared3();
}
if(dist2>cylTotalRadius*cylTotalRadius)
{
goto returnFalse;
}
results.m_vHitNormal.setMul4(axisSign,axis);
results.m_fHitFraction=hitFract;
results.setKey(0xffffffff);
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="E" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};
return true;
}
}
returnFalse:
{hkMonitorStream&mStream=hkMonitorStream::getInstance();if(mStream.memoryAvailable()){hkMonitorStream::TimerCommand*h=reinterpret_cast<hkMonitorStream::TimerCommand*>(mStream.getEnd());h->m_commandAndMonitor="E" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};
return false;
}
