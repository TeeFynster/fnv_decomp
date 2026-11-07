#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
// The SDK's __m128 adds byte arrays that introduce /GS cookies in this unit.
// Preserve the intrinsic layout used by the matching source.
// Exe 0x00db0ec0 FUN_00db0ec0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
#define _INCLUDED_MM2
#include "../../../../../include/hkVector4.h"
#include "../../../../../include/hkTransform.h"
#include "../../../../../include/hkBool.h"
#include "../../../../../include/hkContactPoint.h"
#define FNV_VEC4_NO_SSE
#define FNV_VEC4_SIMD
#include "../../../../../include/Vec4.h"

__forceinline void Vec4::operator=(const Vec4& v)
{
    m_vComponents = v.m_vComponents;
}
__forceinline void Vec4::operator=(const LocalM128& v)
{
    m_vComponents = v;
}
__forceinline float& Vec4::operator()(int i)
{
    return reinterpret_cast<float*>(this)[i];
}
__forceinline const float& Vec4::operator()(int i) const
{
    return reinterpret_cast<const float*>(this)[i];
}

// src/havok/physics/collide/boxbox/hkpboxboxcollisiondetection_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/boxbox/hkpboxboxcollisiondetection.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/collide/boxbox/hkpboxboxcollisiondetection.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/boxbox/hkpboxboxcollisiondetection.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
// RemoveValueAt - drops slot <index> of the eight-slot table held by
// FUN_00db0920: the last slot in use is moved into the hole and the used-slot
// counter goes down by one.
struct FUN_00db0920
{
    int values[8];        // +0x00: eight four-byte slots, low half holds the key
    unsigned char unk20;  // +0x20
    unsigned char count;  // +0x21: number of slots in use
    unsigned char flag;   // +0x22
    void RemoveValueAt(int index);
};
extern "C"
{
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_andnot_ps(LocalM128, LocalM128);
    LocalM128 _mm_cmpeq_ss(LocalM128, LocalM128);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_mul_ss(LocalM128, LocalM128);
    LocalM128 _mm_rsqrt_ss(LocalM128);
    LocalM128 _mm_set_ps1(float);
    LocalM128 _mm_set_ss(float);
    LocalM128 _mm_setzero_ps(void);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
    void _mm_store_ss(float*, LocalM128);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_sub_ss(LocalM128, LocalM128);
    LocalM128 _mm_xor_ps(LocalM128, LocalM128);
}
extern "C"
{
    double __cdecl fabs(double _X);
}
extern "C++"
{
    inline float __cdecl fabs(float _X)
    {
        return ((float)fabs((double)(_X)));
    }
}
// Keep the original inline transform accessors in this translation unit.
__forceinline const hkRotation& hkTransform::getRotation() const
{
    return *reinterpret_cast<const hkRotation*>(this);
}
__forceinline const hkVector4& hkTransform::getTranslation() const
{
    return *reinterpret_cast<const hkVector4*>(&m_vTranslation);
}
__forceinline const hkVector4& hkTransform::getColumn(int i) const
{
    return reinterpret_cast<const hkVector4*>(&m_kColumn0)[i];
}
// Keep the original inline vector operations in this translation unit.
inline float& hkVector4::operator()(int i)
{
    return reinterpret_cast<float*>(this)[i];
}
inline const float& hkVector4::operator()(int i) const
{
    return reinterpret_cast<const float*>(this)[i];
}
struct BoxBoxEdgeContact
{
    hkVector4 m_vContactPosition;                  // 0x00
    hkVector4 unk10;                       // 0x10
    hkVector4 m_vHitNormal;                    // 0x20
    float unk30;                           // 0x30
    float m_fClosestPointDistanceSquared;  // 0x34
    int m_featureA;                        // 0x38
    int m_featureB;                        // 0x3c
};
extern const hkVector4 g_boxVertexSigns[8];
extern const LocalM128 g_negateMask;
struct BoxBoxCollisionDetection
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    hkVector4 m_rotation[3];        // 0x20
    hkVector4 m_vTranslation;       // 0x50
    hkVector4 m_kBoxBasisVector;            // 0x60
    hkVector4 m_kThirdBasisVector;  // 0x70
    hkVector4 unk80;
    hkVector4 unk90;
    hkVector4 unkA0;
    float m_fScalar;          // 0xb0
    float m_minNormalLength;  // 0xb4

    hkBool TestEdgeEdgeContact(BoxBoxEdgeContact* contact);
};
static __forceinline LocalM128 splat(const float& f)
{
    return _mm_set_ps1(f);
}
static __forceinline const hkVector4& boxVertexSign(int byteOffset)
{
    return *reinterpret_cast<const hkVector4*>(reinterpret_cast<const char*>(g_boxVertexSigns) + byteOffset);
}
static inline float hkFabs(float r)
{
    return fabs(r);
}
static __forceinline LocalM128 dot3v(LocalM128 a, LocalM128 b)
{
    LocalM128 p = _mm_mul_ps(a, b);
    LocalM128 s = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
    return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), s);
}
static __forceinline float toReal(LocalM128 v)
{
    float r;
    _mm_store_ss(&r, v);
    return r;
}
static __forceinline float dot3(LocalM128 a, LocalM128 b)
{
    LocalM128 p = _mm_mul_ps(a, b);
    LocalM128 s = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
    s = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), s);
    float r;
    _mm_store_ss(&r, s);
    return r;
}

struct SimdValue
{
    LocalM128 value;
    __forceinline SimdValue(LocalM128 v) : value(v)
    {}
    __forceinline LocalM128 broadcast() const
    {
        return _mm_shuffle_ps(value, value, 0);
    }
};
static __forceinline void productVec(hkVector4& out, const SimdValue& f, const LocalM128& row)
{
    out.m_vComponents = _mm_mul_ps(f.broadcast(), row);
}
static __forceinline void productValue(hkVector4& out, const SimdValue& f, LocalM128 row)
{
    out.m_vComponents = _mm_mul_ps(f.broadcast(), row);
}
extern "C" void _ReadWriteBarrier();
extern "C"
{
    LocalM128 _mm_load_ps(const float*);
    LocalM128 _mm_load_ss(const float*);
    LocalM128 _mm_load_ss(const float*);
    void _mm_store_ps(float*, LocalM128);
    LocalM128 _mm_set_ps(float, float, float, float);
    LocalM128 _mm_setr_ps(float, float, float, float);
    LocalM128 _mm_and_ps(LocalM128, LocalM128);
    LocalM128 _mm_or_ps(LocalM128, LocalM128);
    LocalM128 _mm_cmplt_ps(LocalM128, LocalM128);
    int _mm_movemask_ps(LocalM128);
    LocalM128 _mm_unpacklo_ps(LocalM128, LocalM128);
    LocalM128 _mm_unpackhi_ps(LocalM128, LocalM128);
    LocalM128 _mm_movelh_ps(LocalM128, LocalM128);
    LocalM128 _mm_movehl_ps(LocalM128, LocalM128);
}
extern "C" double __cdecl sqrt(double);
static __forceinline float sqrtf(float x)
{
    return (float)sqrt(x);
}
extern float DAT_010d5360;
extern float DAT_010d5364;
extern const LocalM128 DAT_01017d10;  // abs mask
extern double DAT_010c9300;
extern float DAT_01011d78;
struct __declspec(align(16)) Vec4f
{
    float x;
    float y;
    float z;
    float w;
};
struct Mat3f
{
    hkVector4 r0;
    hkVector4 r1;
    hkVector4 r2;
    void Transpose(LocalM128* rows);
};
struct ThisCls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    LocalM128 m_20;
    LocalM128 m_30;
    LocalM128 m_40;
    LocalM128 m_50;
    LocalM128 m_60;
    LocalM128 m_70;
    LocalM128 m_80;
    LocalM128 m_90;
    LocalM128 m_a0;
    LocalM128 m_b0;
    LocalM128 m_c0;
    LocalM128 m_d0;
    LocalM128 m_e0;
    LocalM128 m_f0;
    LocalM128 m_100;
    LocalM128 m_110;
    LocalM128 m_120;
    __declspec(noinline) int ProcessAndReturnValue_00db0ec0(Vec4f* arg);
};
static __forceinline float recipEps(float s)
{
    return 1.0f / sqrtf((float)((double)s + DAT_010c9300));
}

__forceinline void hkVector4::add4(const hkVector4& b)
{
    m_vComponents = _mm_add_ps(m_vComponents, b.m_vComponents);
}
__forceinline void hkVector4::sub4(const hkVector4& b)
{
    m_vComponents = _mm_sub_ps(m_vComponents, b.m_vComponents);
}
struct MathVector : hkVector4
{
    __forceinline void multiply(const hkVector4& b)
    {
        m_vComponents = _mm_mul_ps(m_vComponents, b.m_vComponents);
    }
    __forceinline void scale(const SimdValue& f, const hkVector4& b)
    {
        m_vComponents = _mm_mul_ps(f.broadcast(), b.m_vComponents);
    }
};
static __forceinline SimdValue getScalar(const hkVector4& v, int i)
{
    if (i == 0)
        return SimdValue(v.m_vComponents);
    if (i == 1)
        return SimdValue(_mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x55));
    return SimdValue(_mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xaa));
}

struct AxisRows
{
    hkVector4 r0, r1, r2;
};
static __forceinline void absoluteVector(hkVector4& d, const hkVector4& s)
{
    d.m_vComponents = _mm_and_ps(s.m_vComponents, DAT_01017d10);
}
static __forceinline void rotatedVector(hkVector4& d, const AxisRows& rows, const hkVector4& e)
{
    LocalM128 second = _mm_mul_ps(_mm_shuffle_ps(e.m_vComponents, e.m_vComponents, 0x55), rows.r1.m_vComponents);
    LocalM128 first = _mm_mul_ps(_mm_shuffle_ps(e.m_vComponents, e.m_vComponents, 0), rows.r0.m_vComponents);
    second = _mm_add_ps(second, first);
    LocalM128 third = _mm_mul_ps(_mm_shuffle_ps(e.m_vComponents, e.m_vComponents, 0xaa), rows.r2.m_vComponents);
    d.m_vComponents = _mm_add_ps(second, third);
}

// @fnv 0x00db0ec0
// src: GUESS 0x00db0ec0 (confidence: low)
__declspec(noinline) int ThisCls::ProcessAndReturnValue_00db0ec0(Vec4f* arg)
{

    float* __restrict p70 = (float*)&m_70;
    hkVector4 locA0;
    locA0.m_vComponents = _mm_load_ss(&DAT_010d5364);
    locA0(3) = locA0(3);
    hkVector4 loc60;
    loc60.m_vComponents = _mm_load_ss(&DAT_010d5360);
    loc60(3) = loc60(3);
    hkVector4 radius;
    radius.m_vComponents = m_70;
    float* __restrict p60 = (float*)&m_60;
    AxisRows sA;
    absoluteVector(sA.r0, *(hkVector4*)&m_20);
    absoluteVector(sA.r1, *(hkVector4*)&m_30);
    absoluteVector(sA.r2, *(hkVector4*)&m_40);
    hkVector4 weighted;
    rotatedVector(weighted, sA, radius);
    weighted.add4(*(hkVector4*)&m_60);
    hkVector4 sep;
    absoluteVector(sep, *(hkVector4*)&m_c0);
    sep.sub4(weighted);
    LocalM128 diff1 = sep.m_vComponents;
    int mask = _mm_movemask_ps(_mm_cmplt_ps(_mm_load_ps((float*)arg), diff1));
    LocalM128 a0 = sA.r0.m_vComponents, a1 = sA.r1.m_vComponents, a2 = sA.r2.m_vComponents;
    if ((mask & 7) != 0)
        return 1;
    m_e0 = diff1;
    _ReadWriteBarrier();
    {
        LocalM128 tmp = _mm_unpacklo_ps(a0, a1);
        LocalM128 ctmp = _mm_unpackhi_ps(a0, a1);
        a0 = _mm_movelh_ps(tmp, a2);
        a1 = _mm_movehl_ps(a0, tmp);
        a1 = _mm_shuffle_ps(a1, a2, 0xd4);
        a2 = _mm_shuffle_ps(ctmp, a2, 0xe4);
    }
    LocalM128 trow0 = a0, trow1 = a1, trow2 = a2;
    LocalM128 q55 = _mm_shuffle_ps(m_60, m_60, 0x55);
    q55 = _mm_mul_ps(q55, trow1);
    LocalM128 q0 = _mm_shuffle_ps(m_60, m_60, 0x00);
    q0 = _mm_mul_ps(q0, trow0);
    q55 = _mm_add_ps(q55, q0);
    LocalM128 qaa = _mm_shuffle_ps(m_60, m_60, 0xaa);
    qaa = _mm_mul_ps(qaa, trow2);
    q55 = _mm_add_ps(q55, qaa);
    q55 = _mm_add_ps(q55, m_70);
    LocalM128 bd0 = _mm_and_ps(m_d0, DAT_01017d10);
    LocalM128 diff2 = _mm_sub_ps(bd0, q55);
    LocalM128 cmp2 = _mm_cmplt_ps(_mm_load_ps((const float*)arg), diff2);
    int mask2 = _mm_movemask_ps(cmp2);
    if ((mask2 & 7) != 0)
        return 1;
    m_f0 = diff2;
    Mat3f trans;
    trans.Transpose(&m_20);
    LocalM128* outSep = &m_100;
    hkVector4 sRS;
    LocalM128 m80, hiAv, hiBv;
    LocalM128 scaled;
    (void)scaled;
    LocalM128 sq0;
    MathVector sq1;
    LocalM128 sq2;
    {
        sq1.m_vComponents = trans.r1.m_vComponents;
        sq1.multiply(sq1);
        sq0 = _mm_mul_ps(_mm_load_ps((const float*)&trans.r0), _mm_load_ps((const float*)&trans.r0));
        sq2 = _mm_mul_ps(trans.r2.m_vComponents, trans.r2.m_vComponents);
        MathVector P;
        P.scale(getScalar(*(hkVector4*)&m_c0, 2), trans.r1);
        P(3) = P(3);
        hkVector4 C;
        C.m_vComponents = getScalar(*(hkVector4*)&m_c0, 1).value;
        C(3) = C(3);

        LocalM128 sumsq = _mm_add_ps(sq2, sq1.m_vComponents);
        float v0 = sA.r0(1) * p60[2] + sA.r0(2) * p60[1] + sA.r2(0) * p70[1] + sA.r1(0) * p70[2];
        float v1 = sA.r1(1) * p60[2] + sA.r1(2) * p60[1] + sA.r2(0) * p70[0] + sA.r0(0) * p70[2];
        float v2 = sA.r2(1) * p60[2] + sA.r2(2) * p60[1] + sA.r1(0) * p70[0] + sA.r0(0) * p70[1];
        sRS.m_vComponents = sumsq;
        sRS(0) = recipEps(sRS(0));
        sRS(1) = recipEps(sRS(1));
        sRS(2) = recipEps(sRS(2));
        sRS(3) = 0.0f;
        hiBv = sRS.m_vComponents;
        LocalM128 V = _mm_setr_ps(v0, v1, v2, DAT_01011d78);
        LocalM128 D =
            _mm_and_ps(_mm_sub_ps(P.m_vComponents, _mm_mul_ps(_mm_shuffle_ps(C.m_vComponents, C.m_vComponents, 0),
                                                              trans.r2.m_vComponents)),
                       DAT_01017d10);
        D = _mm_sub_ps(D, V);
        scaled = _mm_mul_ps(D, hiBv);
        m80 = m_80;
        if ((_mm_movemask_ps(_mm_cmplt_ps(m80, scaled)) & 7) != 0)
            return 1;
        hiAv = _mm_shuffle_ps(locA0.m_vComponents, locA0.m_vComponents, 0);

        LocalM128 selMask = _mm_cmplt_ps(hiAv, hiBv);
        hiBv = _mm_shuffle_ps(loc60.m_vComponents, loc60.m_vComponents, 0);
        outSep[0] = _mm_or_ps(_mm_and_ps(selMask, hiBv), _mm_andnot_ps(selMask, scaled));
    }
    {
        MathVector P;
        P.scale(getScalar(*(hkVector4*)&m_c0, 0), trans.r2);
        P(3) = P(3);
        hkVector4 C;
        C.m_vComponents = _mm_shuffle_ps(m_c0, m_c0, 0xaa);
        C(3) = C(3);
        LocalM128 sumsq = _mm_add_ps(sq2, sq0);
        float v0 = sA.r0(2) * p60[0] + sA.r0(0) * p60[2] + sA.r2(1) * p70[1] + sA.r1(1) * p70[2];
        float v1 = sA.r1(0) * p60[2] + sA.r1(2) * p60[0] + sA.r2(1) * p70[0] + sA.r0(1) * p70[2];
        float v2 = sA.r2(0) * p60[2] + sA.r2(2) * p60[0] + sA.r1(1) * p70[0] + sA.r0(1) * p70[1];
        sRS.m_vComponents = sumsq;
        sRS(0) = recipEps(sRS(0));
        sRS(1) = recipEps(sRS(1));
        sRS(2) = recipEps(sRS(2));
        sRS(3) = 0.0f;
        LocalM128 R = sRS.m_vComponents;
        LocalM128 V = _mm_setr_ps(v0, v1, v2, DAT_01011d78);
        LocalM128 D =
            _mm_and_ps(_mm_sub_ps(P.m_vComponents, _mm_mul_ps(_mm_shuffle_ps(C.m_vComponents, C.m_vComponents, 0),
                                                              trans.r0.m_vComponents)),
                       DAT_01017d10);
        D = _mm_sub_ps(D, V);
        scaled = _mm_mul_ps(D, R);
        if ((_mm_movemask_ps(_mm_cmplt_ps(m80, scaled)) & 7) != 0)
            return 1;
        LocalM128 selMask = _mm_cmplt_ps(hiAv, R);
        outSep[1] = _mm_or_ps(_mm_and_ps(selMask, hiBv), _mm_andnot_ps(selMask, scaled));
    }
    {
        MathVector P;
        P.scale(getScalar(*(hkVector4*)&m_c0, 1), trans.r0);
        P(3) = P(3);
        hkVector4 C;
        C.m_vComponents = m_c0;
        C(3) = C(3);
        LocalM128 sumsq = _mm_add_ps(sq0, sq1.m_vComponents);
        float v0 = sA.r0(0) * p60[1] + sA.r0(1) * p60[0] + sA.r2(2) * p70[1] + sA.r1(2) * p70[2];
        float v1 = sA.r1(0) * p60[1] + sA.r1(1) * p60[0] + sA.r0(2) * p70[2] + sA.r2(2) * p70[0];
        float v2 = sA.r2(0) * p60[1] + sA.r2(1) * p60[0] + sA.r1(2) * p70[0] + sA.r0(2) * p70[1];
        sRS.m_vComponents = sumsq;
        sRS(0) = recipEps(sRS(0));
        sRS(1) = recipEps(sRS(1));
        sRS(2) = recipEps(sRS(2));
        sRS(3) = 0.0f;
        LocalM128 R = sRS.m_vComponents;
        LocalM128 V = _mm_setr_ps(v0, v1, v2, DAT_01011d78);
        LocalM128 D =
            _mm_and_ps(_mm_sub_ps(P.m_vComponents, _mm_mul_ps(_mm_shuffle_ps(C.m_vComponents, C.m_vComponents, 0),
                                                              trans.r1.m_vComponents)),
                       DAT_01017d10);
        D = _mm_sub_ps(D, V);
        scaled = _mm_mul_ps(D, R);
        if ((_mm_movemask_ps(_mm_cmplt_ps(m80, scaled)) & 7) != 0)
            return 1;
        outSep[2] = _mm_cmplt_ps(hiAv, R);
        outSep[2] = _mm_or_ps(_mm_and_ps(outSep[2], hiBv), _mm_andnot_ps(outSep[2], scaled));
    }
    return 0;
}

extern "C" void _ReadWriteBarrier();
extern "C" LocalM128 _mm_load_ps(const float*);
extern "C" LocalM128 _mm_load_ss(const float*);
extern "C" void _mm_store_ps(float*, LocalM128);

__forceinline LocalM128 ReadV(const LocalM128* p)
{
    LocalM128 v = _mm_load_ps((const float*)p);
    _ReadWriteBarrier();
    return v;
}

struct Record
{
    LocalM128 position;
    union
    {
        LocalM128 direction;
        struct
        {
            float dx;
            float dy;
            float dz;
            float time;
        };
    };
    unsigned int id;
    int unk24;
    int unk28;
    int unk2c;
};
struct Input
{
    unsigned char type;
    unsigned char subtype;
    unsigned short id;
};
struct Stream
{
    Record* cursor;
};

struct VtObj
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual unsigned int Impl(int a, int b, int c, Stream* s, int z, Record* out) = 0;
    __forceinline unsigned int Call(int a, int b, int c, Stream* s, int z, Record* out)
    {
        return Impl(a, b, c, s, z, out);
    }
};

struct __declspec(align(16)) Blob
{
    union
    {
        LocalM128 position;
        struct
        {
            float unk00, unk04, unk08, unk0c;
        };
    };
    union
    {
        LocalM128 otherPosition;
        struct
        {
            float unk10, unk14, unk18, unk1c;
        };
    };
    union
    {
        LocalM128 normal;
        struct
        {
            float unk20, unk24, unk28, unk2c;
        };
    };
    float unk30, unk34;
    int unk38, unk3c;
};

struct ContactList
{
    int values[8];
    unsigned char unk20;
    unsigned char count;
    unsigned char flag;
    void Drop(int);
    unsigned char* Lookup(unsigned char* flag, Input* p1);
    int Insert(int a, int b, Input* p1);
};

struct Owner
{
    int m_00;
    int m_04;
    int m_08;
    VtObj* m_0c;
    Stream* m_10;
    hkTransform* m_14;
    hkTransform* m_18;
    int unk1c;
    hkTransform relativeTransform;
    LocalM128 radiiA;
    LocalM128 radiiB;
    LocalM128 unk80, unk90, unkA0;
    float radius;
    float minimumNormalLength;
    unsigned char* Compute(unsigned char* flag, Blob* out);
    __declspec(noinline) void ProcessEntries_00db1990(ContactList* p0, Input* p1, float p2);
};

__forceinline LocalM128 LdV(const unsigned int* p)
{
    return _mm_load_ps((const float*)p);
}

__forceinline LocalM128 Xf(const hkTransform* m, LocalM128 v)
{
    LocalM128 yy = _mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), _mm_load_ps((const float*)&m->m_kColumn1));
    LocalM128 xx = _mm_mul_ps(_mm_shuffle_ps(v, v, 0), _mm_load_ps((const float*)&m->m_kColumn0));
    LocalM128 zz = _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), _mm_load_ps((const float*)&m->m_kColumn2));
    return _mm_add_ps(_mm_add_ps(yy, xx), _mm_add_ps(zz, _mm_load_ps((const float*)&m->m_vTranslation)));
}

__forceinline float Dot3(LocalM128 a)
{
    LocalM128 yx = _mm_add_ss(_mm_shuffle_ps(a, a, 0x55), a);
    LocalM128 zyx = _mm_add_ss(_mm_shuffle_ps(a, a, 0xaa), yx);
    float r;
    _mm_store_ss(&r, zyx);
    return r;
}

__declspec(noinline) unsigned char* Owner::Compute(unsigned char* result, Blob* contact)
{
    const int axisA = contact->unk38 & 15;
    const int axisB = contact->unk3c & 15;
    const LocalM128 signA = g_boxVertexSigns[(contact->unk38 & 0x70) >> 4].m_vComponents;
    const LocalM128 signB = g_boxVertexSigns[(contact->unk3c & 0x70) >> 4].m_vComponents;
    LocalM128 pointA = _mm_mul_ps(radiiA, signA);
    const LocalM128 pointB = _mm_mul_ps(radiiB, signB);
    const float extentA = radiiA.m128_f32[axisA];
    const float extentB = radiiB.m128_f32[axisB];
    const float edgeLengthA = (float)(-2.0 * extentA);
    const float edgeLengthB = (float)(extentB + extentB);
    const LocalM128 axis = _mm_load_ps(reinterpret_cast<const float*>(&relativeTransform) + axisB * 4);
    const LocalM128 edgeB = _mm_mul_ps(_mm_set_ps1(edgeLengthB), axis);
    const LocalM128 separation = _mm_sub_ps(Xf(&relativeTransform, pointB), pointA);
    const float mixed = (float)(edgeB.m128_f32[axisA] * edgeLengthA);
    const float squareA = (float)(edgeLengthA * edgeLengthA);
    const float squareB = (float)(extentB * extentB * 4.0);
    const float dotB = Dot3(_mm_mul_ps(separation, edgeB));
    const float determinant = (float)(squareA * squareB - mixed * mixed);
    const float absoluteDeterminant = (float)fabs(determinant);
    const float projectedA = (float)(separation.m128_f32[axisA] * edgeLengthA);
    const float numeratorA = (float)(projectedA * squareB - dotB * mixed);
    const float lowerA = (float)(1.1920928955078125e-07 * absoluteDeterminant);
    if (!(lowerA < numeratorA))
    {
        *result = 0;
        return result;
    }
    const double upperFraction = 0.9999998807907104;
    if (upperFraction * absoluteDeterminant <= numeratorA)
    {
        *result = 0;
        return result;
    }
    const float fractionA = (float)(numeratorA / absoluteDeterminant);
    const float numeratorB = (float)(fractionA * mixed - dotB);
    if (!(1.1920928955078125e-07 * squareB < numeratorB))
    {
        *result = 0;
        return result;
    }
    if ((float)(upperFraction * squareB) <= numeratorB)
    {
        *result = 0;
        return result;
    }
    pointA.m128_f32[axisA] = (float)(pointA.m128_f32[axisA] + fractionA * edgeLengthA);
    LocalM128 edgeA = _mm_setzero_ps();
    edgeA.m128_f32[axisA] = (float)(edgeLengthA * 0.5);
    const LocalM128 cross = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(edgeA, edgeA, 0xc9), _mm_shuffle_ps(edgeB, edgeB, 0xd2)),
                                    _mm_mul_ps(_mm_shuffle_ps(edgeA, edgeA, 0xd2), _mm_shuffle_ps(edgeB, edgeB, 0xc9)));
    const LocalM128 squares = _mm_mul_ps(cross, cross);
    LocalM128 lengthSquared = _mm_add_ss(_mm_shuffle_ps(squares, squares, 0x55), squares);
    lengthSquared = _mm_add_ss(_mm_shuffle_ps(squares, squares, 0xaa), lengthSquared);
    const LocalM128 estimate = _mm_rsqrt_ss(lengthSquared);
    const LocalM128 correction = _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(lengthSquared, estimate), estimate));
    const LocalM128 inverse = _mm_andnot_ps(_mm_cmpeq_ss(lengthSquared, _mm_set_ss(0.0f)),
                                         _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), estimate), correction));
    const LocalM128 inverseAll = _mm_shuffle_ps(inverse, inverse, 0);
    float length;
    _mm_store_ss(&length, _mm_mul_ss(lengthSquared, inverseAll));
    if (minimumNormalLength > length)
    {
        *result = 0;
        return result;
    }
    LocalM128 normal = _mm_mul_ps(inverseAll, cross);
    if (Dot3(_mm_mul_ps(signA, normal)) < 0.0f)
        normal = _mm_xor_ps(normal, g_negateMask);
    const float distance = Dot3(_mm_mul_ps(normal, separation));
    if (distance > radius)
    {
        *result = 0;
        return result;
    }
    contact->position = pointA;
    contact->unk34 = distance;
    contact->normal = _mm_xor_ps(normal, g_negateMask);
    *result = 1;
    return result;
}

// @fnv 0x00db1990
// src: GUESS 0x00db1990 (confidence: low)
__declspec(noinline) void Owner::ProcessEntries_00db1990(ContactList* p0, Input* p1, float p2)
{
    unsigned char c;
    if (*p0->Lookup(&c, p1) != 0)
    {
        return;
    }
    unsigned long v = p1->type;
    unsigned int m = p1->subtype;
    Blob j;
    *(float*)&j.unk30 = 0.0f;
    j.unk38 = v;
    _mm_store_ps((float*)&j.unk00, _mm_setzero_ps());
    _mm_store_ps((float*)&j.unk10, _mm_setzero_ps());
    j.unk3c = m;
    if (*Compute(&c, &j) == 0)
    {
        return;
    }
    if (!(*(float*)&j.unk34 >= (double)p2 * (double)0.999f))
    {
        return;
    }
    LocalM128 pos1 = j.otherPosition;
    LocalM128 point;
    point = j.position;
    if (p1->type <= 6)
    {
        LocalM128 d;
        if (p1->type <= 2)
        {
            d = Xf(m_18, pos1);
        }
        else
        {
            d = Xf(m_14, point);
        }
        for (int i = 0; i < p0->count; ++i)
        {
            if ((unsigned char)p0->values[i] > 6)
            {
                continue;
            }
            LocalM128 rec = reinterpret_cast<Record*>(m_10)[i].direction;
            LocalM128 r = _mm_sub_ps(d, rec);
            float pos0 = Dot3(_mm_mul_ps(r, r));
            float n = radius * radius + 1.1920928955078125e-07;
            if (pos0 <= n)
            {
                return;
            }
        }
    }
    if (8 <= p0->count)
    {
        return;
    }
    int row = p0->Insert(m_00, m_04, p1);
    if (row < 0)
    {
        return;
    }
    Record* rec = m_10->cursor;
    LocalM128 b;
    int b2 = j.unk38;
    if (2 >= b2)
    {
        long axis = p1->type;
        float y = -*(float*)&j.unk30;
        unsigned int zz = p1->id;
        rec->id = zz;
        LocalM128 flag;
        flag = Xf(m_18, j.otherPosition);
        rec->position = flag;
        LocalM128 raw = _mm_load_ss(&y);
        _ReadWriteBarrier();
        LocalM128 prev = _mm_load_ps((const float*)&reinterpret_cast<LocalM128*>(m_14)[axis]);
        rec->direction = _mm_mul_ps(_mm_shuffle_ps(raw, _mm_load_ps((const float*)&raw), 0), prev);
    }
    else
    {
        LocalM128 out = j.position;
        if (6 >= b2)
        {
            long axis = p1->type - 4;
            float y = -j.unk30;
            unsigned int zz = p1->id;
            rec->id = zz;
            rec->position = Xf(m_14, out);
            LocalM128 raw = _mm_load_ss(&y);
            LocalM128 prev = _mm_load_ps((const float*)&reinterpret_cast<LocalM128*>(m_18)[axis]);
            rec->direction = _mm_mul_ps(_mm_shuffle_ps(raw, _mm_load_ps((const float*)&raw), 0), prev);
        }
        else
        {
            rec->id = p1->id;
            LocalM128 flag;
            flag = Xf(m_14, out);
            rec->position = flag;
            LocalM128 f1c = j.normal;
            const hkTransform* xf = m_14;
            LocalM128 normal = _mm_mul_ps(_mm_shuffle_ps(f1c, f1c, 0x55), _mm_load_ps((const float*)&xf->m_kColumn1));
            LocalM128 vec1 = _mm_mul_ps(_mm_shuffle_ps(f1c, f1c, 0xaa), _mm_load_ps((const float*)&xf->m_kColumn2));
            LocalM128 vec0 = _mm_mul_ps(_mm_shuffle_ps(f1c, f1c, 0), _mm_load_ps((const float*)&xf->m_kColumn0));
            rec->direction = _mm_add_ps(_mm_add_ps(normal, vec0), vec1);
        }
    }
    rec->time = j.unk34;
    if (p0->count > 1)
    {
        LocalM128 s = _mm_load_ps((float*)&m_10->cursor[-1].direction);
        float ptr = Dot3(_mm_mul_ps(_mm_load_ps((float*)&rec->direction), s));
        if (ptr <= 0.0f)
        {
            p0->Drop(row);
            return;
        }
    }
    long t58;
    t58 = m_0c->Call(m_00, m_04, m_08, m_10, 0, rec);
    unsigned short* pForm = reinterpret_cast<unsigned short*>(&p0->values[row]) + 1;
    *pForm = t58;
    if ((unsigned short)t58 == 0xffff)
    {
        p0->Drop(row);
        return;
    }
    m_10->cursor++;
    p1->id = *pForm;
    rec->id = *pForm;
    if (6 < p1->type)
    {
        return;
    }
    p0->unk20 += 1;
}

extern "C"
{
    LocalM128 __cdecl _mm_load_ss(const float*);
    void __cdecl _mm_store_ps(float*, LocalM128);

    LocalM128 __cdecl _mm_add_ps(LocalM128, LocalM128);
    LocalM128 __cdecl _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 __cdecl _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
    LocalM128 __cdecl _mm_set_ps1(float);
}

struct __declspec(align(16)) MyDb0920
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    char unk20;
    char unk21;
    char unk22;
    char unk23;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    void InitializeEmptyEntries();
};

struct ContactScalar
{
    LocalM128 m_vValue;
    __forceinline ContactScalar(float f)
    {
        LocalM128 low = _mm_load_ss(&f);
        m_vValue = _mm_shuffle_ps(low, low, 0);
    }
};

struct hkRotation;

struct __declspec(align(16)) ContactVector
{
    LocalM128 m_vComponents;

    __forceinline ContactVector& operator=(const ContactVector& v)
    {
        m_vComponents = v.m_vComponents;
        return *this;
    }
    __forceinline void _setTransformedPos(const hkTransform& aTb, const ContactVector& in);
    __forceinline void _setRotatedDir(const struct hkRotation& aRb, const ContactVector& in);
    __forceinline void setMul4(const ContactScalar& factor, const ContactVector& a)
    {
        LocalM128 f = factor.m_vValue;
        m_vComponents = _mm_mul_ps(f, a.m_vComponents);
    }
    __forceinline void addMul4(const ContactScalar& factor, const ContactVector& a)
    {
        LocalM128 f = factor.m_vValue;
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(f, a.m_vComponents));
    }
    __forceinline float& operator()(int i)
    {
        return ((float*)&m_vComponents)[i];
    }
    __forceinline const float& operator()(int i) const
    {
        return ((float*)&m_vComponents)[i];
    }
};

#include "../../../../../include/hkRotation.h"



__forceinline void ContactVector::_setTransformedPos(const hkTransform& aTb, const ContactVector& in)
{
    LocalM128 t1 = _mm_shuffle_ps(in.m_vComponents, in.m_vComponents, 0x55);
    t1 = _mm_mul_ps(t1, aTb.m_kColumn1);

    LocalM128 t0 = _mm_shuffle_ps(in.m_vComponents, in.m_vComponents, 0x00);
    t0 = _mm_mul_ps(t0, aTb.m_kColumn0);
    t0 = _mm_add_ps(t0, t1);

    LocalM128 t2 = _mm_shuffle_ps(in.m_vComponents, in.m_vComponents, 0xaa);
    t2 = _mm_mul_ps(t2, aTb.m_kColumn2);
    t2 = _mm_add_ps(t2, aTb.m_vTranslation);

    m_vComponents = _mm_add_ps(t0, t2);
}

__forceinline void ContactVector::_setRotatedDir(const hkRotation& aRb, const ContactVector& in)
{
    LocalM128 t1 = _mm_shuffle_ps(in.m_vComponents, in.m_vComponents, 0x55);
    t1 = _mm_mul_ps(t1, aRb.m_kColumn1.m_vComponents);

    LocalM128 t0 = _mm_shuffle_ps(in.m_vComponents, in.m_vComponents, 0x00);
    t0 = _mm_mul_ps(t0, aRb.m_kColumn0.m_vComponents);
    t1 = _mm_add_ps(t1, t0);

    LocalM128 t2 = _mm_shuffle_ps(in.m_vComponents, in.m_vComponents, 0xaa);
    t2 = _mm_mul_ps(t2, aRb.m_kColumn2.m_vComponents);

    m_vComponents = _mm_add_ps(t1, t2);
}

__forceinline void hkContactPoint::setDistance(float d)
{
    ((float*)&m_vSeparatingNormal)[3] = d;
}
static __forceinline void setContactPoint(hkContactPoint& point, const ContactVector& position,
                                         const ContactVector& separatingNormal, float distance)
{
    _mm_store_ps((float*)&point.m_vSeparatingNormal, separatingNormal.m_vComponents);
    _mm_store_ps((float*)&point.m_vContactPosition, position.m_vComponents);
    point.setDistance(distance);
}

struct Local0c
{
    unsigned char m_kAxisEndPoints, m_sub;
    unsigned short m_flags;
};

struct __declspec(align(16)) Local10
{
    ContactVector m_vec0;
    ContactVector m_vec1;
    ContactVector m_vec2;
    float m_dist0;
    float m_dist1;
    int m_iContactIndex;
    int m_unk3C;
    int m_unk40;
    int m_unk44;
    int m_unk48;
    int m_unk4C;
};

struct __declspec(align(16)) PosNormal
{
    ContactVector m_vHitNormal;
    ContactVector m_pos;
};

struct ResultWork
{
    Local10 result;
    PosNormal pn;
};

struct BoxAgent
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    const hkTransform* m_kBodyALocalFrame;
    const hkTransform* m_kBodyBLocalFrame;
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
    int m_unk80;

    void UpdateFields_00d40940();
    int ProcessAndReturnValue_00db0ec0(void* pUnk80);
    __declspec(noalias) int hkpBoxBoxCollisionDetection_findClosestPoint(MyDb0920* a1, Local0c* a2, Local10* a3);

    __declspec(noinline) hkBool& UpdateState_00db2750(hkBool& valid, hkContactPoint& outPoint);
};

// @fnv 0x00db2750
// src: GUESS 0x00db2750 (confidence: low)
__declspec(noinline) hkBool& BoxAgent::UpdateState_00db2750(hkBool& valid, hkContactPoint& outPoint)
{
    valid = false;
    MyDb0920 local_80;
    local_80.InitializeEmptyEntries();
    Local0c local_0c;
    local_0c.m_flags = 0;
    this->UpdateFields_00d40940();
    if (this->ProcessAndReturnValue_00db0ec0(&this->m_unk80) == 0)
    {
        ResultWork work;
        Local10& local_10 = work.result;
        if (this->hkpBoxBoxCollisionDetection_findClosestPoint(&local_80, &local_0c, &local_10) == 2)
        {
            valid = true;

            ContactVector& normal = work.pn.m_vHitNormal;
            ContactVector pos;

            int feature = local_10.m_iContactIndex;
            unsigned char axis = local_0c.m_kAxisEndPoints;

            if (feature <= 2)
            {
                float factor = -local_10.m_dist0;
                pos._setTransformedPos(*this->m_kBodyBLocalFrame, local_10.m_vec1);
                normal.setMul4(factor, reinterpret_cast<const ContactVector&>(this->m_kBodyALocalFrame->getColumn(axis)));
            }
            else if (feature <= 6)
            {
                float factor = -local_10.m_dist0;
                pos._setTransformedPos(*this->m_kBodyALocalFrame, local_10.m_vec0);
                normal.setMul4(factor, reinterpret_cast<const ContactVector&>(this->m_kBodyBLocalFrame->getColumn(axis - 4)));
            }
            else
            {
                pos._setTransformedPos(*this->m_kBodyALocalFrame, local_10.m_vec0);
                normal._setRotatedDir(reinterpret_cast<const hkRotation&>(this->m_kBodyALocalFrame->getRotation()), local_10.m_vec2);
            }

            float dist = local_10.m_dist1;
            normal(3) = dist;

            if (axis > 2)
            {
                float neg_dist = -dist;
                pos.addMul4(neg_dist, normal);
            }

            setContactPoint(outPoint, pos, normal, dist);
            return valid;
        }
        valid = false;
    }
    return valid;
}

typedef LocalM128 ClosestPointQuad;

namespace ClosestPointUtilities {
struct ClosestPointBool
{
    char m_cBooleanValue;
    ClosestPointBool(bool v) : m_cBooleanValue((char)v)
    {}
};
extern "C" double __cdecl fabs(double);
namespace ClosestPointSimd {
extern const ClosestPointQuad DAT_010d52d0[8];
}
struct ClosestPointVector
{
    ClosestPointQuad m_vComponents;
};
namespace ClosestPointSimd {
extern "C"
{
    ClosestPointQuad _mm_add_ps(ClosestPointQuad, ClosestPointQuad);
    ClosestPointQuad _mm_add_ss(ClosestPointQuad, ClosestPointQuad);
    ClosestPointQuad _mm_andnot_ps(ClosestPointQuad, ClosestPointQuad);
    ClosestPointQuad _mm_cmpeq_ss(ClosestPointQuad, ClosestPointQuad);
    ClosestPointQuad _mm_mul_ps(ClosestPointQuad, ClosestPointQuad);
    ClosestPointQuad _mm_mul_ss(ClosestPointQuad, ClosestPointQuad);
    ClosestPointQuad _mm_rsqrt_ss(ClosestPointQuad);
    ClosestPointQuad _mm_set_ps1(float);
    ClosestPointQuad _mm_set_ss(float);
    ClosestPointQuad _mm_setzero_ps(void);
    ClosestPointQuad _mm_shuffle_ps(ClosestPointQuad, ClosestPointQuad, unsigned int);
    void _mm_store_ss(float*, ClosestPointQuad);
    ClosestPointQuad _mm_sub_ps(ClosestPointQuad, ClosestPointQuad);
    ClosestPointQuad _mm_sub_ss(ClosestPointQuad, ClosestPointQuad);
    ClosestPointQuad _mm_xor_ps(ClosestPointQuad, ClosestPointQuad);
    ClosestPointQuad _mm_setr_ps(float, float, float, float);
    ClosestPointQuad _mm_load_ss(const float*);
    void _mm_store_ps(float*, ClosestPointQuad);
    ClosestPointQuad _mm_cmplt_ps(ClosestPointQuad, ClosestPointQuad);
    ClosestPointQuad _mm_and_ps(ClosestPointQuad, ClosestPointQuad);
    ClosestPointQuad _mm_or_ps(ClosestPointQuad, ClosestPointQuad);
    ClosestPointQuad _mm_unpacklo_ps(ClosestPointQuad, ClosestPointQuad);
    ClosestPointQuad _mm_unpackhi_ps(ClosestPointQuad, ClosestPointQuad);
    ClosestPointQuad _mm_movelh_ps(ClosestPointQuad, ClosestPointQuad);
    ClosestPointQuad _mm_movehl_ps(ClosestPointQuad, ClosestPointQuad);
    int _mm_movemask_ps(ClosestPointQuad);
}
}

struct KeyEntry
{
    unsigned char k0, k1;
    unsigned short unk02;
};

extern const float DAT_0104e148;             // -FLT_MAX
extern const ClosestPointQuad DAT_010c44d0;  // sign mask
extern const ClosestPointQuad DAT_01017d10;  // abs mask
struct Out
{
    Vec4 o0;  // 0x00
    Vec4 o1;  // 0x10
    Vec4 o2;
    float f30;  // 0x30
    float f34;  // 0x34
    int i38;    // 0x38
    int i3c;    // 0x3c
};
struct Arg0
{
    KeyEntry entries[8];
    unsigned char unk20;
    unsigned char count;  // 0x21
};
struct ClosestPointDetector
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    Vec4 rotation[3];
    Vec4 s0;             // 0x50
    Vec4 s1;             // 0x60
    Vec4 s2;             // 0x70
    Vec4 t0;             // 0x80
    Vec4 t1;             // 0x90
    Vec4 t2;             // 0xa0
    Vec4 u0;             // 0xb0
    Vec4 u1;             // 0xc0
    Vec4 u2;             // 0xd0
    mutable Vec4 pl[5];  // 0xe0..0x12f
    __declspec(noinline) int hkpBoxBoxCollisionDetection_findClosestPoint(Arg0& ref0, KeyEntry& ref1, Out& ref2) const;
    ClosestPointBool TestEdgeEdgeContact(Out* out) const;
};
static ClosestPointQuad load4(const Vec4& v)
{
    return v;
}
static ClosestPointQuad dot3scalar(ClosestPointQuad value)
{
    ClosestPointQuad y = (ClosestPointSimd::_mm_shuffle_ps)(value, value, 0x55);
    ClosestPointQuad z = (ClosestPointSimd::_mm_shuffle_ps)(value, value, 0xaa);
    return (ClosestPointSimd::_mm_add_ss)(z, (ClosestPointSimd::_mm_add_ss)(y, value));
}
__declspec(noinline) ClosestPointBool ClosestPointDetector::TestEdgeEdgeContact(Out* out) const
{
    unsigned axisA = out->i38 & 15;
    unsigned axisB = out->i3c & 15;
    ClosestPointQuad signA = ClosestPointSimd::DAT_010d52d0[(out->i38 & 0x70) >> 4];
    ClosestPointQuad signB = ClosestPointSimd::DAT_010d52d0[(out->i3c & 0x70) >> 4];
    Vec4 pointA;
    (ClosestPointSimd::_mm_store_ps)(&pointA(0), (ClosestPointSimd::_mm_mul_ps)(load4(s1), signA));
    ClosestPointQuad pointB = (ClosestPointSimd::_mm_mul_ps)(load4(s2), signB);
    float lengthB = (&s2(0))[axisB] + (&s2(0))[axisB];
    float lengthA = (float)((&s1(0))[axisA] * -2.0);
    Vec4 directionB;
    (ClosestPointSimd::_mm_store_ps)(
        &directionB(0),
        (ClosestPointSimd::_mm_mul_ps)((ClosestPointSimd::_mm_set_ps1)(lengthB), load4(rotation[axisB])));
    ClosestPointQuad worldB = (ClosestPointSimd::_mm_add_ps)(
        (ClosestPointSimd::_mm_add_ps)(
            (ClosestPointSimd::_mm_mul_ps)((ClosestPointSimd::_mm_shuffle_ps)(pointB, pointB, 0x55),
                                           load4(rotation[1])),
            (ClosestPointSimd::_mm_mul_ps)((ClosestPointSimd::_mm_shuffle_ps)(pointB, pointB, 0), load4(rotation[0]))),
        (ClosestPointSimd::_mm_add_ps)(
            (ClosestPointSimd::_mm_mul_ps)((ClosestPointSimd::_mm_shuffle_ps)(pointB, pointB, 0xaa),
                                           load4(rotation[2])),
            load4(s0)));
    Vec4 delta;
    (ClosestPointSimd::_mm_store_ps)(&delta(0), (ClosestPointSimd::_mm_sub_ps)(worldB, load4(pointA)));
    float dotAB = (&directionB(0))[axisA] * lengthA;
    float squareA = lengthA * lengthA;
    float squareB = (float)((&s2(0))[axisB] * (&s2(0))[axisB] * 4.0);
    float dotDeltaB;
    (ClosestPointSimd::_mm_store_ss)(&dotDeltaB,
                                     dot3scalar((ClosestPointSimd::_mm_mul_ps)(load4(delta), load4(directionB))));
    float determinant = squareA * squareB - dotAB * dotAB;
    determinant = (float)fabs(determinant);
    float dotDeltaA = (&delta(0))[axisA] * lengthA;
    float numerator = dotDeltaA * squareB - dotDeltaB * dotAB;
    if (!(1.1920928955078125e-7 * determinant < numerator) || !(0.9999998807907104 * determinant > numerator))
    {
        return ClosestPointBool(false);
    }
    float fractionA = numerator / determinant;
    float numeratorB = fractionA * dotAB - dotDeltaB;
    if (!(1.1920928955078125e-7 * squareB < numeratorB) || !(0.9999998807907104 * squareB > numeratorB))
    {
        return ClosestPointBool(false);
    }
    (&pointA(0))[axisA] += fractionA * lengthA;
    Vec4 halfDirectionA;
    halfDirectionA = (ClosestPointSimd::_mm_setzero_ps)();
    (&halfDirectionA(0))[axisA] = (float)(lengthA * 0.5);
    ClosestPointQuad av = load4(halfDirectionA);
    ClosestPointQuad bv = load4(directionB);
    ClosestPointQuad cross = (ClosestPointSimd::_mm_sub_ps)(
        (ClosestPointSimd::_mm_mul_ps)((ClosestPointSimd::_mm_shuffle_ps)(av, av, 0xc9),
                                       (ClosestPointSimd::_mm_shuffle_ps)(bv, bv, 0xd2)),
        (ClosestPointSimd::_mm_mul_ps)((ClosestPointSimd::_mm_shuffle_ps)(av, av, 0xd2),
                                       (ClosestPointSimd::_mm_shuffle_ps)(bv, bv, 0xc9)));
    ClosestPointQuad square = (ClosestPointSimd::_mm_mul_ps)(cross, cross);
    ClosestPointQuad sum = dot3scalar(square);
    ClosestPointQuad reciprocal = (ClosestPointSimd::_mm_rsqrt_ss)(sum);
    ClosestPointQuad refined = (ClosestPointSimd::_mm_mul_ss)(
        (ClosestPointSimd::_mm_mul_ss)((ClosestPointSimd::_mm_set_ss)(0.5f), reciprocal),
        (ClosestPointSimd::_mm_sub_ss)(
            (ClosestPointSimd::_mm_set_ss)(3.0f),
            (ClosestPointSimd::_mm_mul_ss)((ClosestPointSimd::_mm_mul_ss)(sum, reciprocal), reciprocal)));
    refined = (ClosestPointSimd::_mm_andnot_ps)(
        (ClosestPointSimd::_mm_cmpeq_ss)(sum, (ClosestPointSimd::_mm_setzero_ps)()), refined);
    ClosestPointQuad factor = (ClosestPointSimd::_mm_shuffle_ps)(refined, refined, 0);
    ClosestPointQuad normal = (ClosestPointSimd::_mm_mul_ps)(factor, cross);
    float magnitude;
    (ClosestPointSimd::_mm_store_ss)(&magnitude, (ClosestPointSimd::_mm_mul_ss)(sum, factor));
    if (u0(1) > magnitude)
    {
        return ClosestPointBool(false);
    }
    float orientation;
    (ClosestPointSimd::_mm_store_ss)(&orientation, dot3scalar((ClosestPointSimd::_mm_mul_ps)(signA, normal)));
    if (orientation < 0.0f)
        normal = (ClosestPointSimd::_mm_xor_ps)(normal, DAT_010c44d0);
    float separation;
    (ClosestPointSimd::_mm_store_ss)(&separation, dot3scalar((ClosestPointSimd::_mm_mul_ps)(normal, load4(delta))));
    if (u0(0) < separation)
    {
        return ClosestPointBool(false);
    }
    (ClosestPointSimd::_mm_store_ps)(&out->o0(0), load4(pointA));
    out->f34 = separation;
    (ClosestPointSimd::_mm_store_ps)(&out->o2(0), (ClosestPointSimd::_mm_xor_ps)(normal, DAT_010c44d0));
    return ClosestPointBool(true);
}
static __forceinline void inverseAxes(ClosestPointVector& dst, const Vec4* rows, const ClosestPointVector& input)
{
    ClosestPointQuad c0 = load4(rows[0]), c1 = load4(rows[1]), c2 = load4(rows[2]);
    ClosestPointQuad lo = (ClosestPointSimd::_mm_unpacklo_ps)(c0, c1);
    c0 = (ClosestPointSimd::_mm_unpackhi_ps)(c0, c1);
    c1 = (ClosestPointSimd::_mm_movelh_ps)(lo, c2);
    ClosestPointQuad y = (ClosestPointSimd::_mm_shuffle_ps)((ClosestPointSimd::_mm_movehl_ps)(c1, lo), c2, 0xd4);
    c2 = (ClosestPointSimd::_mm_shuffle_ps)(c0, c2, 0xe4);
    ClosestPointQuad b0 = (ClosestPointSimd::_mm_shuffle_ps)(input.m_vComponents, input.m_vComponents, 0);
    ClosestPointQuad r0 = (ClosestPointSimd::_mm_mul_ps)(c1, b0);
    ClosestPointQuad b1 = (ClosestPointSimd::_mm_shuffle_ps)(input.m_vComponents, input.m_vComponents, 0x55);
    ClosestPointQuad r1 = (ClosestPointSimd::_mm_mul_ps)(y, b1);
    ClosestPointQuad b2 = (ClosestPointSimd::_mm_shuffle_ps)(input.m_vComponents, input.m_vComponents, 0xaa);
    ClosestPointQuad r2 = (ClosestPointSimd::_mm_mul_ps)(c2, b2);
    dst.m_vComponents = (ClosestPointSimd::_mm_add_ps)((ClosestPointSimd::_mm_add_ps)(r0, r1), r2);
}

class ScalarLane
{
    ClosestPointQuad value;

  public:
    ScalarLane(float f)
    {
        value = (ClosestPointSimd::_mm_load_ss)(&f);
    }
    ScalarLane(const ClosestPointQuad& f) : value(f)
    {}
    __forceinline const ClosestPointQuad& low() const
    {
        return value;
    }
    __forceinline ClosestPointQuad broadcast() const
    {
        return (ClosestPointSimd::_mm_shuffle_ps)(value, value, 0);
    }
};
class VectorLanes
{
    ClosestPointQuad value;

  public:
    __forceinline VectorLanes()
    {}
    __forceinline VectorLanes(const ClosestPointQuad& f) : value(f)
    {}
    __forceinline VectorLanes(const VectorLanes& f) : value(f.value)
    {}
    __forceinline void operator=(const ClosestPointQuad& f)
    {
        value = f;
    }
    __forceinline void operator=(const VectorLanes& f)
    {
        value = f.value;
    }
    __forceinline operator ClosestPointQuad() const
    {
        return value;
    }
    __forceinline void fill(const ScalarLane& f)
    {
        value = (ClosestPointSimd::_mm_shuffle_ps)(f.low(), f.low(), 0);
    }
    __forceinline void fill(float f)
    {
        value = (ClosestPointSimd::_mm_set_ps1)(f);
    }
    __forceinline void multiply(const ScalarLane& f)
    {
        value = (ClosestPointSimd::_mm_mul_ps)(f.broadcast(), value);
    }
};
static __forceinline void chooseVector(VectorLanes& result, float replacement, const Vec4& vec, float bound)
{
    ClosestPointQuad v = (ClosestPointSimd::_mm_load_ss)(&replacement);
    ClosestPointQuad b = (ClosestPointSimd::_mm_load_ss)(&bound);
    VectorLanes selected;
    selected.fill(ScalarLane(v));
    ClosestPointQuad vs = selected;
    ClosestPointQuad bs = (ClosestPointSimd::_mm_shuffle_ps)(b, b, 0);
    ClosestPointQuad mask = (ClosestPointSimd::_mm_cmplt_ps)(bs, load4(vec));
    result = (ClosestPointSimd::_mm_or_ps)((ClosestPointSimd::_mm_and_ps)(vs, mask),
                                           (ClosestPointSimd::_mm_andnot_ps)(mask, (ClosestPointQuad)result));
}

static __forceinline const float* getSignAddress(const Out& out)
{
    return &out.f30;
}
// @fnv 0x00db1ed0
// src: XBOX_PDB 0x00db1ed0
__declspec(noinline) int ClosestPointDetector::hkpBoxBoxCollisionDetection_findClosestPoint(Arg0& ref0, KeyEntry& ref1, Out& ref2) const
{
    Arg0* arg0 = &ref0;
    KeyEntry* arg1 = &ref1;
    Out* out = &ref2;
    volatile float signF30;
    unsigned int bits;
    int counter = 8;
    for (;;)
    {
        float best = pl[0](0);
        unsigned int idx = 0;
        if (pl[0](0) > best)
        {
            best = pl[0](0);
            idx = 0;
        }
        if (pl[0](1) > best)
        {
            best = pl[0](1);
            idx = 1;
        }
        if (pl[0](2) > best)
        {
            best = pl[0](2);
            idx = 2;
        }
        if (pl[1](0) > best)
        {
            best = pl[1](0);
            idx = 4;
        }
        if (pl[1](1) > best)
        {
            best = pl[1](1);
            idx = 5;
        }
        if (pl[1](2) > best)
        {
            best = pl[1](2);
            idx = 6;
        }
        if (pl[2](0) > best)
        {
            best = pl[2](0);
            idx = 8;
        }
        if (pl[2](1) > best)
        {
            best = pl[2](1);
            idx = 9;
        }
        if (pl[2](2) > best)
        {
            best = pl[2](2);
            idx = 10;
        }
        if (pl[3](0) > best)
        {
            best = pl[3](0);
            idx = 12;
        }
        if (pl[3](1) > best)
        {
            best = pl[3](1);
            idx = 13;
        }
        if (pl[3](2) > best)
        {
            best = pl[3](2);
            idx = 14;
        }
        if (pl[4](0) > best)
        {
            best = pl[4](0);
            idx = 16;
        }
        if (pl[4](1) > best)
        {
            best = pl[4](1);
            idx = 17;
        }
        if (pl[4](2) > best)
        {
            best = pl[4](2);
            idx = 18;
        }
        if (idx <= 2)
        {
            KeyEntry* pairp = arg1;
            Arg0* tbl = arg0;
            pairp->k0 = (unsigned char)idx;
            out->i38 = idx;
            float thr = (&u1(0))[idx];
            ClosestPointQuad col3 = (ClosestPointSimd::_mm_setr_ps)((&rotation[0](0))[idx], (&rotation[1](0))[idx],
                                                                    (&rotation[2](0))[idx], 0.0f);
            ClosestPointQuad v70;
            if (thr < 0.0f)
            {
                out->f30 = -1.0f;
                v70 = load4(s2);
            }
            else
            {
                out->f30 = 1.0f;
                v70 = (ClosestPointSimd::_mm_xor_ps)(load4(s2), DAT_010c44d0);
            }
            (ClosestPointSimd::_mm_store_ps)(&out->o1(0), v70);
            VectorLanes tweak;
            tweak.fill(-1.0e-5f);
            chooseVector(tweak, 1.0e-5f, u2, 0.0f);
            tweak.multiply(ScalarLane(out->f30));
            ClosestPointQuad sel = tweak;
            sel = (ClosestPointSimd::_mm_add_ps)(sel, col3);
            sel = (ClosestPointSimd::_mm_and_ps)(sel, DAT_010c44d0);
            ClosestPointQuad o1v = load4(out->o1);
            o1v = (ClosestPointSimd::_mm_xor_ps)(sel, o1v);
            (ClosestPointSimd::_mm_store_ps)(&out->o1(0), o1v);
            signF30 = out->f30;
            bits = *(unsigned int*)&signF30;
            o1v = load4(out->o1);
            ClosestPointQuad a1 = (ClosestPointSimd::_mm_shuffle_ps)(o1v, o1v, 0x55);
            a1 = (ClosestPointSimd::_mm_mul_ps)(a1, load4(rotation[1]));
            ClosestPointQuad a2 = (ClosestPointSimd::_mm_shuffle_ps)(o1v, o1v, 0x00);
            a2 = (ClosestPointSimd::_mm_mul_ps)(a2, load4(rotation[0]));
            a1 = (ClosestPointSimd::_mm_add_ps)(a1, a2);
            ClosestPointQuad a3 = (ClosestPointSimd::_mm_shuffle_ps)(o1v, o1v, 0xaa);
            a3 = (ClosestPointSimd::_mm_mul_ps)(a3, load4(rotation[2]));
            a3 = (ClosestPointSimd::_mm_add_ps)(a3, load4(s0));
            a1 = (ClosestPointSimd::_mm_add_ps)(a1, a3);
            (ClosestPointSimd::_mm_store_ps)(&out->o0(0), a1);
            const Vec4* __restrict pn = &out->o1;
            int mm = (ClosestPointSimd::_mm_movemask_ps)(
                         (ClosestPointSimd::_mm_cmplt_ps)(load4(*pn), (ClosestPointSimd::_mm_setzero_ps)())) &
                     7;
            unsigned char b1 = (unsigned char)((mm << 4) | ((bits >> 0x1c) & 8));
            pairp->k1 = b1;
            int n = tbl->count - 1;
            if (n >= 0)
            {
                unsigned char first = pairp->k0;
                for (int i = n; i >= 0; --i)
                {
                    const KeyEntry& e = tbl->entries[i];
                    if (e.k0 == first && e.k1 == pairp->k1)
                        return 1;
                }
            }
            Vec4 absA = out->o0;
            ClosestPointQuad lv = load4(absA);
            lv = (ClosestPointSimd::_mm_and_ps)(lv, DAT_01017d10);
            int am = (ClosestPointSimd::_mm_movemask_ps)((ClosestPointSimd::_mm_cmplt_ps)(lv, load4(t1))) & 7;
            if (am != 7)
            {
                goto reject;
            }
            {
                const float* of = (const float*)out;
                out->f34 = of[out->i38] * out->f30 - (&s1(0))[out->i38];
            }
            return 2;
        }
        else if (idx <= 6)
        {
            Vec4* vectorOut = &out->o0;
            const float* __restrict signIn = &out->f30;
            int feature = idx - 4;
            KeyEntry* pairp = arg1;
            Arg0* tbl = arg0;
            pairp->k0 = (unsigned char)idx;
            out->i38 = feature + 4;
            float thr = (&u2(0))[feature];
            Vec4 loc = rotation[feature];
            ClosestPointQuad v60;
            if (thr < 0.0f)
            {
                out->f30 = -1.0f;
                v60 = (ClosestPointSimd::_mm_xor_ps)(load4(s1), DAT_010c44d0);
            }
            else
            {
                out->f30 = 1.0f;
                v60 = load4(s1);
            }
            signF30 = -out->f30;
            (ClosestPointSimd::_mm_store_ps)(&(*vectorOut)(0), v60);

            VectorLanes tweak;
            tweak.fill(1.0e-5f);
            chooseVector(tweak, -1.0e-5f, u1, 0.0f);
            tweak.multiply(ScalarLane((ClosestPointSimd::_mm_load_ss)((const float*)&signF30)));
            *(float*)&signF30 = *signIn;
            ClosestPointQuad sel = tweak;
            ClosestPointQuad locv = load4(loc);
            sel = (ClosestPointSimd::_mm_add_ps)(sel, locv);
            sel = (ClosestPointSimd::_mm_and_ps)(sel, DAT_010c44d0);
            ClosestPointQuad o0v = load4(out->o0);
            o0v = (ClosestPointSimd::_mm_xor_ps)(sel, o0v);
            (ClosestPointSimd::_mm_store_ps)(&(*vectorOut)(0), o0v);
            ClosestPointVector temp;
            temp.m_vComponents = (ClosestPointSimd::_mm_sub_ps)(o0v, load4(s0));
            inverseAxes(*(ClosestPointVector*)&out->o1, rotation, temp);
            int mm = (ClosestPointSimd::_mm_movemask_ps)(
                         (ClosestPointSimd::_mm_cmplt_ps)(load4(out->o0), (ClosestPointSimd::_mm_setzero_ps)())) &
                     7;
            unsigned char b1 = (unsigned char)(mm << 4);
            b1 |= (unsigned char)(((*(volatile unsigned int*)&signF30) >> 28) & 8);
            pairp->k1 = b1;
            int n = (int)tbl->count - 1;
            for (int i = n; i >= 0; --i)
            {
                const KeyEntry& e = tbl->entries[i];
                if (e.k0 == pairp->k0 && e.k1 == pairp->k1)
                    return 1;
            }
            Vec4 absB = out->o1;
            ClosestPointQuad lv = load4(absB);
            lv = (ClosestPointSimd::_mm_and_ps)(lv, DAT_01017d10);
            int am = (ClosestPointSimd::_mm_movemask_ps)((ClosestPointSimd::_mm_cmplt_ps)(lv, load4(t2))) & 7;
            if (am != 7)
            {
                goto reject;
            }
            {
                const float* of = (const float*)out;
                int a = out->i38 - 4;
                out->f34 = of[4 + a] * -out->f30 - (&s2(0))[a];
            }
            return 2;
        }
        else
        {
            KeyEntry* pairp = arg1;
            Arg0* tbl = arg0;
            unsigned int t = idx - 8;
            unsigned int ebx = t >> 2;
            unsigned int rem = t & 3;
            out->i38 = ebx;
            out->i3c = rem;
            Vec4 loc70 = rotation[rem];
            Vec4 arr90;
            (ClosestPointSimd::_mm_store_ps)(&arr90(0), (ClosestPointSimd::_mm_setzero_ps)());
            (&arr90(0))[ebx] = 1.0f;
            ClosestPointQuad av = load4(arr90);
            ClosestPointQuad bvec = load4(loc70);
            ClosestPointQuad x1 = av;
            ClosestPointQuad x3 = (ClosestPointSimd::_mm_shuffle_ps)(x1, x1, 0xd2);
            ClosestPointQuad x0 = bvec;
            ClosestPointQuad x2 = (ClosestPointSimd::_mm_shuffle_ps)(bvec, bvec, 0xc9);
            x2 = (ClosestPointSimd::_mm_mul_ps)(x2, x3);
            x1 = (ClosestPointSimd::_mm_shuffle_ps)(av, av, 0xc9);
            x0 = (ClosestPointSimd::_mm_shuffle_ps)(bvec, bvec, 0xd2);
            x0 = (ClosestPointSimd::_mm_mul_ps)(x0, x1);
            ClosestPointQuad c0v = load4(u1);
            x0 = (ClosestPointSimd::_mm_sub_ps)(x0, x2);
            c0v = (ClosestPointSimd::_mm_mul_ps)(c0v, x0);
            ClosestPointQuad d2 = (ClosestPointSimd::_mm_shuffle_ps)(c0v, c0v, 0x55);
            ClosestPointQuad d3 = (ClosestPointSimd::_mm_shuffle_ps)(c0v, c0v, 0xaa);
            d2 = (ClosestPointSimd::_mm_add_ss)(d2, c0v);
            d3 = (ClosestPointSimd::_mm_add_ss)(d3, d2);
            float dot;
            (ClosestPointSimd::_mm_store_ss)(&dot, d3);
            if (dot < 0.0f)
                x0 = (ClosestPointSimd::_mm_xor_ps)(x0, DAT_010c44d0);
            ClosestPointQuad edgeMatrix0 = load4(rotation[0]);
            ClosestPointQuad edgeMatrix1 = load4(rotation[1]);
            ClosestPointQuad edgeMatrix2 = load4(rotation[2]);
            (ClosestPointSimd::_mm_store_ps)(&out->o0(0), x0);
            ClosestPointQuad mlow = (ClosestPointSimd::_mm_unpacklo_ps)(edgeMatrix0, edgeMatrix1);
            ClosestPointQuad mhigh = (ClosestPointSimd::_mm_unpackhi_ps)(edgeMatrix0, edgeMatrix1);
            edgeMatrix0 = (ClosestPointSimd::_mm_movelh_ps)(mlow, edgeMatrix2);
            Vec4 loc30 = out->o0;
            (&loc30(0))[ebx] = 1.0f;
            ClosestPointQuad my = (ClosestPointSimd::_mm_shuffle_ps)(
                (ClosestPointSimd::_mm_movehl_ps)(edgeMatrix0, mlow), edgeMatrix2, 0xd4);
            ClosestPointQuad mz = (ClosestPointSimd::_mm_shuffle_ps)(mhigh, edgeMatrix2, 0xe4);
            ClosestPointQuad trans = (ClosestPointSimd::_mm_add_ps)(
                (ClosestPointSimd::_mm_add_ps)(
                    (ClosestPointSimd::_mm_mul_ps)(my, (ClosestPointSimd::_mm_shuffle_ps)(x0, x0, 0x55)),
                    (ClosestPointSimd::_mm_mul_ps)((ClosestPointSimd::_mm_shuffle_ps)(x0, x0, 0), edgeMatrix0)),
                (ClosestPointSimd::_mm_mul_ps)(mz, (ClosestPointSimd::_mm_shuffle_ps)(x0, x0, 0xaa)));
            (ClosestPointSimd::_mm_store_ps)(&out->o1(0), trans);
            Vec4 loc40 = out->o1;
            (&loc40(0))[rem] = 1.0f;
            int mm0 = (ClosestPointSimd::_mm_movemask_ps)(
                (ClosestPointSimd::_mm_cmplt_ps)(load4(loc30), (ClosestPointSimd::_mm_setzero_ps)()));
            unsigned char byte0 = (unsigned char)(((mm0 | 0xf8) << 4) | (ebx & 0xff));
            pairp->k0 = byte0;
            int mm1 = (ClosestPointSimd::_mm_movemask_ps)(
                (ClosestPointSimd::_mm_cmplt_ps)(load4(loc40), (ClosestPointSimd::_mm_setzero_ps)()));
            unsigned char byte1 = (unsigned char)((((~mm1) & 7) << 4) + (rem & 0xff));
            pairp->k1 = byte1;
            out->i38 = byte0;
            out->i3c = pairp->k1;
            int n = (int)tbl->count - 1;
            bool found = false;
            for (int i = n; i >= 0; --i)
            {
                const KeyEntry& e = tbl->entries[i];
                if (e.k0 == pairp->k0 && e.k1 == pairp->k1)
                {
                    found = true;
                    break;
                }
            }
            if (found)
                return 1;
            ClosestPointBool callLocal = TestEdgeEdgeContact(out);
            if (callLocal.m_cBooleanValue != 0)
            {
                return 2;
            }
            goto reject;
        }
    reject:
        (&pl[idx >> 2](0))[idx & 3] = DAT_0104e148;
        if (--counter <= 0)
            return 0;
    }
}

}

typedef LocalM128 ManifoldQuad;

extern "C" void _ReadBarrier();
extern "C" LocalM128 _mm_load_ss(const float*);
extern "C" LocalM128 _mm_load_ps(const float*);
extern "C" LocalM128 _mm_and_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_cmplt_ps(LocalM128, LocalM128);
extern "C" int _mm_movemask_ps(LocalM128);
extern "C" LocalM128 _mm_unpacklo_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_unpackhi_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_movelh_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_movehl_ps(LocalM128, LocalM128);

namespace Manifold {
extern const ManifoldQuad DAT_01017d10;
extern const ManifoldQuad DAT_010c44d0;
class NBool
{
    char value;

  public:
    __forceinline NBool()
    {}
    __forceinline NBool(bool b)
    {
        value = (char)b;
    }
    __forceinline operator bool() const
    {
        return value != 0;
    }
    __forceinline NBool& operator=(bool b)
    {
        value = (char)b;
        return *this;
    }
};
template <class T> class NPad
{
    T value;

  public:
    __forceinline NPad()
    {}
    __forceinline NPad(T t) : value(t)
    {}
    __forceinline void operator=(T t)
    {
        value = t;
    }
    __forceinline operator T() const
    {
        return value;
    }
};
class NS
{
    ManifoldQuad quad;

  public:
    __forceinline NS()
    {}
    __forceinline NS(const ManifoldQuad& v) : quad(v)
    {}
    __forceinline NS(float f) : quad(_mm_load_ss(&f))
    {}
    __forceinline const ManifoldQuad& getQuad() const
    {
        return quad;
    }
    __forceinline operator float() const
    {
        float f;
        _mm_store_ss(&f, quad);
        return f;
    }
};
struct NR;
class NV
{
    ManifoldQuad quad;

  public:
    __forceinline NV()
    {}
    __forceinline NV(const NV& v) : quad(v.quad)
    {}
    __forceinline void operator=(const NV& v)
    {
        quad = v.quad;
    }
    __forceinline void operator=(const ManifoldQuad& v)
    {
        quad = v;
    }
    __forceinline operator ManifoldQuad() const
    {
        return quad;
    }
    __forceinline ManifoldQuad& getQuad()
    {
        return quad;
    }
    __forceinline const ManifoldQuad& getQuad() const
    {
        return quad;
    }
    __forceinline float& operator()(int i)
    {
        return ((float*)&quad)[i];
    }
    __forceinline const float& operator()(int i) const
    {
        return ((const float*)&quad)[i];
    }
    __forceinline void setZero4()
    {
        quad = _mm_setzero_ps();
    }
    __forceinline void setAll3(float f)
    {
        ManifoldQuad t = _mm_load_ss(&f);
        quad = _mm_shuffle_ps(t, t, 0);
    }
    __forceinline void setAbs4(const NV& v)
    {
        quad = _mm_and_ps(v.quad, DAT_01017d10);
    }
    __forceinline void setNeg4(const NV& v)
    {
        quad = _mm_xor_ps(v.quad, DAT_010c44d0);
    }
    __forceinline void setSub4(const NV& a, const NV& b)
    {
        quad = _mm_sub_ps(a.quad, b.quad);
    }
    __forceinline void setMul4(const NV& a, const NV& b)
    {
        quad = _mm_mul_ps(a.quad, b.quad);
    }
    __forceinline void setMul4(const NS& f, const NV& v)
    {
        ManifoldQuad q = f.getQuad();
        quad = _mm_mul_ps(_mm_shuffle_ps(q, q, 0), v.quad);
    }
    __forceinline int allLessThan3(const NV& v) const
    {
        return (_mm_movemask_ps(_mm_cmplt_ps(quad, v.quad)) & 7) == 7;
    }
    __forceinline int negativeMask() const
    {
        return _mm_movemask_ps(_mm_cmplt_ps(quad, _mm_setzero_ps()));
    }
    __forceinline NS dot3(const NV& v) const
    {
        ManifoldQuad p = _mm_mul_ps(quad, v.quad);
        ManifoldQuad s = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), s);
    }
    __forceinline NS lengthSquared3() const
    {
        return dot3(*this);
    }
    __forceinline void _setTransformedPos(const hkTransform&, const NV&);
    __forceinline void _setTransformedInversePos(const hkTransform&, const NV&);
    __forceinline void _setRotatedDir(const NR&, const NV&);
    __forceinline void _setRotatedInverseDir(const NR&, const NV&);
    void hkVector4_setRotatedDir(const NR&, const NV&);
};
struct NMatrixBase
{
    NV first, second, third;
    __forceinline const NV& getColumn(int i) const
    {
        return (&first)[i];
    }
};
struct NR : NMatrixBase
{
};
__forceinline void NV::_setTransformedPos(const hkTransform& t, const NV& v)
{
    const NR& r = reinterpret_cast<const NR&>(t.getRotation());
    ManifoldQuad x = _mm_shuffle_ps(v.quad, v.quad, 0);
    ManifoldQuad ax = _mm_mul_ps(r.getColumn(0).getQuad(), x);
    ManifoldQuad y = _mm_shuffle_ps(v.quad, v.quad, 0x55);
    ManifoldQuad ay = _mm_mul_ps(r.getColumn(1).getQuad(), y);
    ManifoldQuad z = _mm_shuffle_ps(v.quad, v.quad, 0xaa);
    ManifoldQuad az = _mm_mul_ps(r.getColumn(2).getQuad(), z);
    quad = _mm_add_ps(_mm_add_ps(ax, ay), _mm_add_ps(az, t.m_vTranslation));
}
__forceinline void NV::_setRotatedDir(const NR& r, const NV& v)
{
    ManifoldQuad sx = _mm_shuffle_ps(v.quad, v.quad, 0);
    ManifoldQuad x = _mm_mul_ps(r.getColumn(0).getQuad(), sx);
    ManifoldQuad sy = _mm_shuffle_ps(v.quad, v.quad, 0x55);
    ManifoldQuad y = _mm_mul_ps(r.getColumn(1).getQuad(), sy);
    ManifoldQuad sz = _mm_shuffle_ps(v.quad, v.quad, 0xaa);
    ManifoldQuad z = _mm_mul_ps(r.getColumn(2).getQuad(), sz);
    quad = _mm_add_ps(_mm_add_ps(x, y), z);
}
__forceinline void NV::_setRotatedInverseDir(const NR& r, const NV& v)
{
    ManifoldQuad a = r.getColumn(0).getQuad(), b = r.getColumn(1).getQuad(), c = r.getColumn(2).getQuad();
    ManifoldQuad low = _mm_unpacklo_ps(a, b), high = _mm_unpackhi_ps(a, b);
    a = _mm_movelh_ps(low, c);
    b = _mm_shuffle_ps(_mm_movehl_ps(a, low), c, 0xd4);
    c = _mm_shuffle_ps(high, c, 0xe4);
    ManifoldQuad sx = _mm_shuffle_ps(v.quad, v.quad, 0);
    ManifoldQuad x = _mm_mul_ps(a, sx);
    ManifoldQuad sy = _mm_shuffle_ps(v.quad, v.quad, 0x55);
    ManifoldQuad y = _mm_mul_ps(b, sy);
    ManifoldQuad sz = _mm_shuffle_ps(v.quad, v.quad, 0xaa);
    ManifoldQuad z = _mm_mul_ps(c, sz);
    quad = _mm_add_ps(_mm_add_ps(x, y), z);
}
__forceinline void NV::_setTransformedInversePos(const hkTransform& t, const NV& v)
{
    NV d;
    d.setSub4(v, reinterpret_cast<const NV&>(t.getTranslation()));
    _setRotatedInverseDir(reinterpret_cast<const NR&>(t.getRotation()), d);
}
static __forceinline float NMin(float a, float b)
{
    return a < b ? a : b;
}

extern const float DAT_010d52d0[32];
extern const unsigned short DAT_010d5350;
extern const double DAT_010c9300;
extern const double DAT_0107d1b8;
extern const double DAT_010ce488;
extern const double DAT_0103c7c8;
extern const double DAT_010d5378;

struct NFeature
{
    __forceinline static void* operator new(unsigned int, void* p)
    {
        return p;
    }
    unsigned char type, sub;
    unsigned short id;
    NFeature() : id(0)
    {}
};
struct NCache
{
    NV a, b, normal;
    float sign, depth;
    int type, subtype;
};
struct NBody;
struct NOutput;
struct NManager
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual unsigned short add(const NBody&, const NBody&, const void*, NOutput&, void*, const void*);
    virtual void v10();
    virtual void remove(unsigned short, void*);
};
struct NRecord
{
    NV position, normal;
    int id, unk24, unk28, unk2c;
    __forceinline float distance() const
    {
        return normal(3);
    }
    __forceinline void setDistance(float d)
    {
        normal(3) = d;
    }
    __forceinline NRecord& operator=(const NRecord& p)
    {
        position = p.position;
        normal = p.normal;
        id = p.id;
        return *this;
    }
};
struct NOutput
{
    NPad<NRecord*> cursor;
    void* owner;
    int unk08, unk0c;
    NRecord first;
    __forceinline int size() const
    {
        return (NRecord*)cursor - &first;
    }
    __forceinline NRecord* end()
    {
        return cursor;
    }
    __forceinline NRecord* reserve()
    {
        return cursor;
    }
    __forceinline void commit(int n)
    {
        cursor = (NRecord*)cursor + n;
    }
    __forceinline NRecord& at(int i)
    {
        return (&first)[i];
    }
};
struct NManifold
{
    NFeature entries[8];
    unsigned char faces, count;
    NBool complete, normalSet;
    unsigned int packed;
    int unk28, unk2c;
    NV normal;
    void RemoveValueAt(int);
    int hkpBoxBoxManifold_addPoint(const NBody&, const NBody&, NFeature&);
    NBool ContainsKey(const NFeature&);
    __forceinline int size()
    {
        return count;
    }
    __forceinline NFeature& at(int i)
    {
        return entries[i];
    }
    __forceinline NBool find(const NFeature& f)
    {
        for (int i = count - 1; i >= 0; --i)
            if (entries[i].type == f.type && entries[i].sub == f.sub)
                return true;
        return false;
    }
    __forceinline NBool full()
    {
        return count >= 8;
    }
};
inline NBool NManifold::ContainsKey(const NFeature& f)
{
    for (int i = count - 1; i >= 0; --i)
        if (entries[i].type == f.type && entries[i].sub == f.sub)
            return true;
    return false;
}
struct NInverse
{
    void hkVector4_setRotatedInverseDir(const NR&, const NV&);
};
unsigned int PackFloatsToUInt(const NV&);
struct NDetector
{
    const NBody& bodyA;
    const NBody& bodyB;
    const void* input;
    NManager* manager;
    NOutput* output;
    const hkTransform& worldA;
    const hkTransform& worldB;
    int unk1c;
    hkTransform aTb;
    NV radiusA, radiusB, tolerance4, keepA, keepB;
    const float tolerance, boundaryTolerance;
    int unkB8, unkBC;
    NV dinA, dinB;
    void UpdateFields_00d40940() const;
    int ProcessAndReturnValue_00db0ec0(const NV&) const;
    __declspec(noalias) int hkpBoxBoxCollisionDetection_findClosestPoint(NManifold&, NFeature&, NCache&) const;
    __declspec(noalias) NBool TestEdgeEdgeContact(NCache&) const;
    void CheckFeatureCacheCoverage(NManifold&, int, int) const;
    __forceinline void remove(NManifold&, int) const;
    __forceinline void fillA(NCache&, const NFeature&) const;
    __forceinline void fillScan(NCache&, const NFeature&) const;
    __forceinline void fillB(NCache&, const NFeature&) const;
    __forceinline NBool validA(NCache&) const;
    __forceinline NBool validB(NCache&) const;
    __forceinline void emitA(NRecord&, const NFeature&, const NCache&) const;
    __forceinline void emitB(NRecord&, const NFeature&, const NCache&) const;
    __forceinline void emitEdge(NRecord&, const NFeature&, const NCache&) const;
    __forceinline void emit(NRecord&, const NFeature&, const NCache&) const;
    __forceinline void refresh(NManifold&) const;
    __forceinline NBool query(NManifold&) const;
    __forceinline void normalFromCache(NV&, const NFeature&, NCache&, NBool) const;
    __forceinline void compact(NManifold&) const;
    __forceinline int AddContactPoint(NManifold&, const NCache&, NFeature&) const;
    __forceinline int addScan(NManifold&, const NCache&, NFeature&) const;
    __forceinline void scanA(NManifold&, NFeature, unsigned short, float) const;
    __forceinline void scanB(NManifold&, NFeature, unsigned short, float) const;
    __forceinline void extra(NManifold&, NFeature) const;
    __declspec(noinline) void hkpBoxBoxCollisionDetection_calcManifold(NManifold&) const;
};
static __forceinline float NSign(unsigned short bits)
{
    float f = 1.0f;
    unsigned int* p = (unsigned int*)&f;
    *p = *p | ((bits & ~7) << 28);
    return f;
}
static __forceinline const NV& NVertex(unsigned short bits)
{
    return *(const NV*)((const char*)DAT_010d52d0 + (bits & 0x70));
}
static __forceinline void NUnpack(unsigned int bits, NV& out)
{
    out(0) = (float)((int(bits & 255) - 128) * DAT_010ce488);
    out(1) = (float)((int(((bits >> 8) & 255)) - 128) * DAT_010ce488);
    out(2) = (float)((int(((bits >> 16) & 255)) - 128) * DAT_010ce488);
    out(3) = (float)(int(bits >> 24) - 128) * DAT_010ce488;
}
__forceinline void NDetector::remove(NManifold& m, int i) const
{
    if (m.at(i).type <= 6)
        --m.faces;
    manager->remove(m.at(i).id, output->owner);
    m.RemoveValueAt(i);
}
__forceinline void NDetector::fillA(NCache& c, const NFeature& f) const
{
    c.type = f.type;
    c.sign = NSign(f.sub);
    const NV& vertex = NVertex(f.sub);
    c.b.setMul4(radiusB, vertex);
    c.a._setTransformedPos(aTb, c.b);
}
__forceinline void NDetector::fillScan(NCache& c, const NFeature& f) const
{
    c.type = f.type;
    c.sign = NSign(f.sub);
    NV point;
    point.setMul4(radiusB, NVertex(f.sub));
    c.b = point;
    c.a._setTransformedPos(aTb, point);
}
__forceinline void NDetector::fillB(NCache& c, const NFeature& f) const
{
    c.type = f.type;
    c.sign = NSign(f.sub);
    const NV& vertex = NVertex(f.sub);
    c.a.setMul4(radiusA, vertex);
    c.b._setTransformedInversePos(aTb, c.a);
}
__forceinline NBool NDetector::validA(NCache& c) const
{
    NV v = c.a;
    v.setAbs4(v);
    if (v.allLessThan3(keepA))
    {
        int axis = c.type;
        c.depth = c.a(axis) * c.sign - radiusA(axis);
        return true;
    }
    return false;
}
__forceinline NBool NDetector::validB(NCache& c) const
{
    NV v = c.b;
    v.setAbs4(v);
    if (v.allLessThan3(keepB))
    {
        int axis = c.type - 4;
        c.depth = (-c.sign) * c.b(axis) - radiusB(axis);
        return true;
    }
    return false;
}
__forceinline void NDetector::emitA(NRecord& out, const NFeature& f, const NCache& c) const
{
    int axis = f.type;
    out.id = f.id;
    out.position._setTransformedPos(worldB, c.b);
    out.normal.setMul4(-c.sign, reinterpret_cast<const NR&>(worldA.getRotation()).getColumn(axis));
    out.setDistance(c.depth);
}
__forceinline void NDetector::emitB(NRecord& out, const NFeature& f, const NCache& c) const
{
    int axis = f.type - 4;
    out.id = f.id;
    out.position._setTransformedPos(worldA, c.a);
    out.normal.setMul4(-c.sign, reinterpret_cast<const NR&>(worldB.getRotation()).getColumn(axis));
    out.setDistance(c.depth);
}
__forceinline void NDetector::emitEdge(NRecord& out, const NFeature& f, const NCache& c) const
{
    out.id = f.id;
    out.position._setTransformedPos(worldA, c.a);
    out.normal._setRotatedDir(reinterpret_cast<const NR&>(worldA.getRotation()), c.normal);
    out.setDistance(c.depth);
}
__forceinline void NDetector::emit(NRecord& out, const NFeature& f, const NCache& c) const
{
    int type = c.type;
    if (type <= 2)
        emitA(out, f, c);
    else if (type <= 6)
        emitB(out, f, c);
    else
        emitEdge(out, f, c);
}
__forceinline void NDetector::refresh(NManifold& m) const
{
    int i = 0;
    while (i < m.size())
    {
        const NFeature& f = m.at(i);
        int type = f.type;

        if (type <= 2)
        {
            NCache c;
            fillA(c, f);
            if (validA(c))
            {
                NRecord* out = output->reserve();
                output->commit(1);
                emitA(*out, f, c);
                ++i;
                continue;
            }
        }
        else if (type <= 6)
        {
            NCache c;
            fillB(c, f);
            if (validB(c))
            {
                NRecord* out = output->reserve();
                output->commit(1);
                emitB(*out, f, c);
                ++i;
                continue;
            }
        }
        else
        {
            NCache c;
            c.type = f.type;
            c.subtype = f.sub;
            if (TestEdgeEdgeContact(c))
            {
                NRecord* out = output->reserve();
                output->commit(1);
                emitEdge(*out, f, c);
                ++i;
                continue;
            }
        }
        remove(m, i);
    }
}
__forceinline NBool NDetector::query(NManifold& m) const
{
    if (m.size() < 2)
    {
        m.normalSet = false;
        return true;
    }
    if (!m.normalSet)
    {
        NV n;
        ((NInverse*)&n)->hkVector4_setRotatedInverseDir(reinterpret_cast<const NR&>(aTb.getRotation()), m.normal);
        m.normalSet = true;
        m.packed = PackFloatsToUInt(n);
        return true;
    }
    NV decoded;
    NUnpack(m.packed, decoded);
    NV inA;
    inA._setRotatedDir(reinterpret_cast<const NR&>(aTb.getRotation()), decoded);
    const float cosine = m.normal.dot3(inA);
    return cosine < DAT_0107d1b8;
}
__forceinline void NDetector::normalFromCache(NV& n, const NFeature& f, NCache& c, NBool edgeValid) const
{
    int type = c.type;
    if (type <= 2)
    {
        n.setZero4();
        n(f.type) = -c.sign;
    }
    else if (type <= 6)
    {
        n.setMul4(-c.sign, reinterpret_cast<const NR&>(aTb.getRotation()).getColumn(f.type - 4));
    }
    else if (edgeValid)
        n = c.normal;
}
__forceinline void NDetector::compact(NManifold& m) const
{
    NV normalWorld;
    normalWorld.hkVector4_setRotatedDir(reinterpret_cast<const NR&>(worldA.getRotation()), m.normal);
    int outIndex = output->size() - m.size();
    int i = 0;
    while (i < m.size())
    {
        const NRecord& out = output->at(outIndex);
        const float cosine = out.normal.dot3(normalWorld);
        if (cosine < DAT_0107d1b8)
        {
            output->at(outIndex) = output->end()[-1];
            remove(m, i);
            output->commit(-1);
        }
        else
        {
            ++i;
            ++outIndex;
        }
    }
    if (m.size() < 2)
        m.normalSet = false;
    else
    {
        NV n;
        n._setRotatedInverseDir(reinterpret_cast<const NR&>(aTb.getRotation()), m.normal);
        m.packed = PackFloatsToUInt(n);
        m.normalSet = true;
    }
}
static __forceinline unsigned short NCreate(NManager* mgr, const NBody& a, const NBody& b, const void* input,
                                            NOutput* output, NRecord* point)
{
    return mgr->add(a, b, input, *output, 0, point);
}
__forceinline int NDetector::AddContactPoint(NManifold& m, const NCache& c, NFeature& f) const
{
    const double epsilon = DAT_010c9300;
    if (f.type <= 6)
    {
        NV candidate;
        if (f.type <= 2)
            candidate._setTransformedPos(worldB, c.b);
        else
            candidate._setTransformedPos(worldA, c.a);
        for (int i = 0; i < m.size(); ++i)
        {
            NV difference;
            if (m.at(i).type <= 6)
            {
                const NRecord& point = output->at(i);
                difference.setSub4(candidate, point.position);
                const float radius = (float)((double)tolerance * tolerance + epsilon);
                if (float(difference.lengthSquared3()) <= radius)
                    return 1;
            }
        }
    }
    if (m.full())
        return 1;
    int index = m.hkpBoxBoxManifold_addPoint(bodyA, bodyB, f);
    if (index >= 0)
    {
        NRecord* out = output->reserve();
        emit(*out, f, c);
        if (m.size() > 1)
        {
            const NRecord* existing = output->end() - 1;
            if (float(existing->normal.dot3(out->normal)) <= 0.0f)
            {
                m.RemoveValueAt(index);
                return 1;
            }
        }
        m.at(index).id = NCreate(manager, bodyA, bodyB, input, output, out);
        if (m.at(index).id == 0xffff)
            m.RemoveValueAt(index);
        else
        {
            output->commit(1);
            f.id = m.at(index).id;
            out->id = m.at(index).id;
            if (f.type <= 6)
                ++m.faces;
        }
    }
    return 0;
}
__forceinline int NDetector::addScan(NManifold& m, const NCache& c, NFeature& f) const
{
    const double epsilon = DAT_010c9300;
    if (f.type <= 6)
    {
        NV candidate;
        if (f.type <= 2)
            candidate._setTransformedPos(worldB, c.b);
        else
            candidate._setTransformedPos(worldA, c.a);
        for (int i = 0; i < m.size(); (_ReadBarrier(), ++i))
        {
            NV difference;
            if (m.at(i).type <= 6)
            {
                const NRecord& point = output->at(i);
                difference.setSub4(candidate, point.position);
                const float radius = (float)((double)tolerance * tolerance + epsilon);
                if (float(difference.lengthSquared3()) <= radius)
                    return 1;
            }
        }
    }
    if (m.full())
        return 1;
    int index = m.hkpBoxBoxManifold_addPoint(bodyA, bodyB, f);
    if (index >= 0)
    {
        NRecord* out = output->reserve();
        emit(*out, f, c);
        if (m.size() > 1)
        {
            const NRecord* existing = output->end() - 1;
            if (float(existing->normal.dot3(out->normal)) <= 0.0f)
            {
                m.RemoveValueAt(index);
                return 1;
            }
        }
        m.at(index).id = NCreate(manager, bodyA, bodyB, input, output, out);
        if (m.at(index).id == 0xffff)
            m.RemoveValueAt(index);
        else
        {
            output->commit(1);
            f.id = m.at(index).id;
            out->id = m.at(index).id;
            if (f.type <= 6)
                ++m.faces;
        }
    }
    return 0;
}
static __forceinline NBool NValidateScan(const NDetector& d, NCache& c, int axis)
{
    NV v = c.a;
    v.setAbs4(v);
    if (v.allLessThan3(d.keepA))
    {
        c.depth = c.a(axis) * c.sign - d.radiusA(axis);
        return true;
    }
    return false;
}
__forceinline void NDetector::scanA(NManifold& m, NFeature key, unsigned short mask, float minimum) const
{
    for (const unsigned short* iter = &DAT_010d5350; (int)iter < (int)(&DAT_010d5350 + 7); ++iter)
    {
        unsigned int cycle = *iter;
        if ((unsigned short)(mask & cycle) == 0)
        {
            unsigned short sub = cycle ^ key.sub;
            NFeature f = key;
            f.sub = (f.sub & 0xff0f) | sub;
            if (!m.ContainsKey(f))
            {
                NCache c;
                fillScan(c, f);
                if (NValidateScan(*this, c, f.type) && c.depth >= minimum - DAT_010c9300)
                    addScan(m, c, f);
            }
        }
    }
}
__forceinline void NDetector::scanB(NManifold& m, NFeature key, unsigned short mask, float minimum) const
{
    for (const unsigned short* iter = &DAT_010d5350; (int)iter < (int)(&DAT_010d5350 + 7); ++iter)
    {
        unsigned int cycle = *iter;
        if ((unsigned short)(mask & cycle) == 0)
        {
            unsigned short sub = cycle ^ key.sub;
            NFeature f = key;
            f.sub = (f.sub & 0xff0f) | sub;
            if (!m.ContainsKey(f))
            {
                NCache c;
                fillB(c, f);
                if (validB(c) && c.depth >= minimum - DAT_010c9300)
                    AddContactPoint(m, c, f);
            }
        }
    }
}
static __forceinline int NPlane(const NV& absolute, const NV& direction, int& axis)
{
    int a, mask;
    if (absolute(0) > absolute(1))
    {
        a = 0;
        mask = 0x10;
    }
    else
    {
        a = 1;
        mask = 0x20;
    }
    if (absolute(2) > absolute(a))
    {
        a = 2;
        mask = 0x40;
    }
    axis = a;
    return mask;
}
static __forceinline unsigned short NBits(const NV& v, float f)
{
    unsigned int bits = *(unsigned int*)&f;
    return (unsigned short)(((v.negativeMask() & 7) << 4) | ((bits >> 28) & 8));
}
__forceinline void NDetector::extra(NManifold& m, NFeature keyA) const
{
    if (m.size() < 1)
        return;
    NV normalA, normalB;
    int index = output->size() - m.size();
    int axisA, axisB, maskA, maskB;
    {
        const NRecord& point = output->at(index);
        const NV& normal = point.normal;
        normalA._setRotatedInverseDir(reinterpret_cast<const NR&>(worldA.getRotation()), normal);
        normalB._setRotatedInverseDir(reinterpret_cast<const NR&>(worldB.getRotation()), normal);
        normalA.setNeg4(normalA);
        NV absoluteA = normalA, absoluteB = normalB;
        absoluteA.setAbs4(absoluteA);
        absoluteB.setAbs4(absoluteB);
        maskA = NPlane(absoluteA, normalA, axisA);
        maskB = NPlane(absoluteB, normalB, axisB);
        if (absoluteA(axisA) < DAT_010d5378 || absoluteB(axisB) < DAT_010d5378)
            return;
    }
    NFeature keyB;
    {
        const float sideA = dinA(axisA), sideB = dinB(axisB);
        keyA.sub = (unsigned char)NBits(normalB, sideA);
        keyB.sub = (unsigned char)NBits(normalA, sideB);
    }
    keyA.type = (unsigned char)axisA;
    keyB.type = (unsigned char)(axisB + 4);
    float minimum = 1.0f;
    for (int i = 0; i < m.size(); ++i)
    {
        const float d = output->at(index + i).distance();
        if (d < minimum)
            minimum = d;
    }
    scanA(m, keyA, (unsigned short)maskB, minimum);
    scanB(m, keyB, (unsigned short)maskA, minimum);
    if (m.faces >= 4)
        m.complete = true;
    else
        CheckFeatureCacheCoverage(m, maskA, maskB);
}
// @fnv 0x00db2960
// src: XBOX_PDB 0x00db2960
__declspec(noinline) void NDetector::hkpBoxBoxCollisionDetection_calcManifold(NManifold& m) const
{
    union
    {
        float minimum;
        unsigned int keyBits;
    };
    UpdateFields_00d40940();
    NRecord* saved = output->cursor;
    refresh(m);
    NBool request = query(m);
    if (!request && m.complete)
        return;
    int intersect;
    if (m.size())
    {
        minimum = saved->distance();
        for (int i = m.size() - 1; i > 0; --i)
            minimum = NMin(minimum, saved[i].distance());
        minimum -= tolerance4(0) * DAT_0103c7c8;
        NV bound;
        bound.setAll3(minimum);
        intersect = ProcessAndReturnValue_00db0ec0(bound);
    }
    else
        intersect = ProcessAndReturnValue_00db0ec0(tolerance4);
    if (intersect != 0)
        return;
    NFeature& feature = *new (&keyBits) NFeature;
    NCache cache;
    cache.normal.setZero4();
    int valid = hkpBoxBoxCollisionDetection_findClosestPoint(m, feature, cache);
    if (request && valid)
    {
        normalFromCache(m.normal, feature, cache, valid == 2);
        if (m.normalSet)
            compact(m);
    }
    if (valid != 2)
        return;
    if (AddContactPoint(m, cache, feature) == 0)
        extra(m, feature);
}

}
