#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit defines its own form

// src/staging/blk_00e60000_od_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_moves.py: the bytes and the matched neighbours of these functions
// say /MT /O2 /GS /EHsc /Gy (unit src/staging/blk_00e60000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions to their real
// unit once identified.

// src/staging/blk_00e60000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
// Retain this unit's original SSE intrinsic representation and declarations.
#define _INCLUDED_MM2
// Exe 0x00e61e70 FUN_00e61e70: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
} __m128, LocalM128;
extern "C"
{
    LocalM128 _mm_load_ps(const float*);
    LocalM128 _mm_load_ss(const float*);
    void _mm_store_ps(float*, LocalM128);
    void _mm_store_ss(float*, LocalM128);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_xor_ps(LocalM128, LocalM128);
    LocalM128 _mm_mul_ss(LocalM128, LocalM128);
    LocalM128 _mm_sub_ss(LocalM128, LocalM128);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_cmpeq_ss(LocalM128, LocalM128);
    LocalM128 _mm_andnot_ps(LocalM128, LocalM128);
    LocalM128 _mm_cmplt_ps(LocalM128, LocalM128);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, int);
    LocalM128 _mm_rsqrt_ss(LocalM128);
    LocalM128 _mm_set_ss(float);
    LocalM128 _mm_set_ps1(float);
    int _mm_movemask_ps(LocalM128);
}
extern "C" LocalM128 _mm_setzero_ps(void);
extern "C" LocalM128 _mm_load_ps1(const float*);
#include "../../include/hkVector4.h"
#include "../../include/hkMatrix4.h"



extern "C" double __cdecl sqrt(double);
extern const LocalM128 DAT_01267e30;  // zero
extern const LocalM128 DAT_010c44d0;  // sign mask xyzw
extern const signed char DAT_010ececc[];
extern const signed char DAT_010eced4[];
extern const signed char DAT_010eced6[];
__forceinline hkSimdReal::hkSimdReal(const LocalM128& scalar)
{
    m_vValue = scalar;
}
__forceinline hkSimdReal::hkSimdReal(float scalar)
{
    m_vValue = _mm_load_ss(&scalar);
}
__forceinline hkSimdReal::operator float() const
{
    float result;
    _mm_store_ss(&result, m_vValue);
    return result;
}
__forceinline float& hkVector4::operator()(int index)
{
    return m_vComponents.m128_f32[index];
}
__forceinline const float& hkVector4::operator()(int index) const
{
    return m_vComponents.m128_f32[index];
}
inline void hkVector4::setSub4(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
}
__forceinline float hkVector4::dot3scalar(const hkVector4& b) const
{
    LocalM128 product = _mm_mul_ps(m_vComponents, b.m_vComponents);
    LocalM128 sum = _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);
    LocalM128 result = _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), sum);
    float value;
    _mm_store_ss(&value, result);
    return value;
}
inline void hkVector4::setMul4(LocalM128 scalar, const hkVector4& a)
{
    m_vComponents = _mm_mul_ps(scalar, a.m_vComponents);
}
inline void hkVector4::setCross(const hkVector4& v1, const hkVector4& v2)
{
    LocalM128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                               _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
    LocalM128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                               _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
    m_vComponents = _mm_sub_ps(cross0, cross1);
}
__forceinline void hkVector4::setZero4()
{
    m_vComponents = _mm_setzero_ps();
}
static __forceinline float LengthSquared3(const hkVector4& vector)
{
    LocalM128 s = _mm_mul_ps(vector.m_vComponents, vector.m_vComponents);
    float r;
    _mm_store_ss(&r, _mm_add_ss(_mm_shuffle_ps(s, s, 0xaa), _mm_add_ss(_mm_shuffle_ps(s, s, 0x55), s)));
    return r;
}
static __forceinline void Normalize3(hkVector4& vector)
{
    LocalM128 square = _mm_mul_ps(vector.quad, vector.quad);
    LocalM128 sum =
        _mm_add_ss(_mm_shuffle_ps(square, square, 0xaa), _mm_add_ss(_mm_shuffle_ps(square, square, 0x55), square));
    LocalM128 root = _mm_rsqrt_ss(sum);
    LocalM128 refined = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), root),
                                _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(sum, root), root)));
    refined = _mm_andnot_ps(_mm_cmpeq_ss(sum, _mm_set_ss(0.0f)), refined);
    vector.quad = _mm_mul_ps(_mm_shuffle_ps(refined, refined, 0), vector.quad);
}
struct __declspec(align(16)) PlainPoint
{
    float x, y, z, w;
};
struct DistOut
{
    hkVector4 m_vHitNormal;
    float m_fClosestPointDistanceSquared;
};
struct Feature
{
    char m_type;
    char pad01;
    short m_idx[3];
};
int __cdecl hkLineSegmentUtil_closestPointLineSeg(const hkVector4* p, const hkVector4* a, const hkVector4* b, hkVector4* out);
static __forceinline LocalM128 Dot3(LocalM128 a, LocalM128 b)
{
    LocalM128 x2 = _mm_mul_ps(a, b);
    LocalM128 s = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), s);
}
static __forceinline float ToReal(LocalM128 x)
{
    float r;
    _mm_store_ss(&r, x);
    return r;
}
static __forceinline LocalM128 Splat(const float& f)
{
    return _mm_shuffle_ps(_mm_load_ss(&f), _mm_load_ss(&f), 0);
}
__forceinline hkSimdReal hkVector4::normalizeWithLength3()
{
    LocalM128 lenSq = Dot3(m_vComponents, m_vComponents);
    LocalM128 rs = _mm_rsqrt_ss(lenSq);
    LocalM128 inv = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), rs),
                            _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(lenSq, rs), rs)));
    inv = _mm_andnot_ps(_mm_cmpeq_ss(lenSq, _mm_set_ss(0.0f)), inv);
    inv = _mm_shuffle_ps(inv, inv, 0);
    LocalM128 l2 = Dot3(m_vComponents, m_vComponents);
    m_vComponents = _mm_mul_ps(m_vComponents, inv);
    return hkSimdReal(_mm_mul_ss(l2, inv));
}
struct Comparison
{
    LocalM128 bits;
    __forceinline operator int() const
    {
        return _mm_movemask_ps(bits) & 7;
    }
};
// @fnv 0x00e62100
// src: GUESS 0x00e62100 (confidence: low)
int __cdecl hkVector4_ProcessAndReturnValue_00e62100(const hkVector4* point, const hkVector4* tri, const float* plane, DistOut* out, Feature* feat)
{
    if (feat)
        feat->m_type = 0;
    hkVector4 e0, e2, v1;
    hkVector4& edge = e2;
    hkVector4& alias0 = e0;
    v1.setSub4(tri[1], *point);
    e0.setSub4(tri[0], tri[1]);
    float d0 = e0.dot3scalar(v1);
    e2.setSub4(tri[2], tri[1]);
    float d1 = e2.dot3scalar(v1);
    float u = plane[2] * d1 - plane[1] * d0;
    float v = plane[2] * d0 - plane[0] * d1;
    const float eps = 0.001f;
    hkVector4 bary;
    bary.m_vComponents.m128_f32[0] = u + eps;
    bary.m_vComponents.m128_f32[1] = 1.0f + eps - u - v;
    bary.m_vComponents.m128_f32[2] = v + eps;
    bary.m_vComponents.m128_f32[3] = eps;
    Comparison mask = {_mm_cmplt_ps(DAT_01267e30, bary.m_vComponents)};
    if (mask == 7)
    {
        LocalM128 negative = _mm_mul_ps(_mm_shuffle_ps(edge.m_vComponents, edge.m_vComponents, 0xc9),
                                     _mm_shuffle_ps(alias0.m_vComponents, alias0.m_vComponents, 0xd2));
        LocalM128 positive = _mm_mul_ps(_mm_shuffle_ps(edge.m_vComponents, edge.m_vComponents, 0xd2),
                                     _mm_shuffle_ps(alias0.m_vComponents, alias0.m_vComponents, 0xc9));
        LocalM128 n = _mm_sub_ps(positive, negative);
        out->m_vHitNormal.m_vComponents = n;
        n = _mm_mul_ps(_mm_set_ps1(plane[3]), n);
        float d = ToReal(Dot3(v1.m_vComponents, n));
        out->m_fClosestPointDistanceSquared = d;
        out->m_vHitNormal.m_vComponents = n;
        if (d > 0.0f)
        {
            out->m_vHitNormal.m_vComponents = _mm_xor_ps(n, DAT_010c44d0);
        }
        else
        {
            out->m_fClosestPointDistanceSquared = -d;
        }
        if (feat)
        {
            feat->m_type = 3;
            feat->m_idx[0] = 0;
            feat->m_idx[1] = 1;
            feat->m_idx[2] = 2;
        }
        return 0;
    }
    int idx = DAT_010ececc[mask];
    if (idx < 0)
    {
        idx += 8;
        int r = hkLineSegmentUtil_closestPointLineSeg(point, &tri[DAT_010eced6[idx]], &tri[DAT_010eced4[idx]], &bary);
        if (feat)
        {
            if (r == 4)
            {
                feat->m_idx[0] = DAT_010eced4[idx];
                feat->m_type = 1;
            }
            else if (r == 8)
            {
                feat->m_idx[0] = DAT_010eced6[idx];
                feat->m_type = 1;
            }
            else
            {
                feat->m_idx[0] = DAT_010eced4[idx];
                feat->m_idx[1] = DAT_010eced6[idx];
                feat->m_type = 2;
            }
        }
        out->m_vHitNormal.m_vComponents = _mm_sub_ps(point->m_vComponents, bary.m_vComponents);
        out->m_fClosestPointDistanceSquared = out->m_vHitNormal.normalizeWithLength3();
        return 1;
    }
    hkVector4 c1;
    int r0 = hkLineSegmentUtil_closestPointLineSeg(point, &tri[idx], &tri[DAT_010eced6[idx]], &bary);
    int r1 = hkLineSegmentUtil_closestPointLineSeg(point, &tri[DAT_010eced4[idx]], &tri[idx], &c1);
    hkVector4 d0v, d1v;
    d0v.m_vComponents = _mm_sub_ps(point->m_vComponents, bary.m_vComponents);
    d1v.m_vComponents = _mm_sub_ps(point->m_vComponents, c1.m_vComponents);
    float l0 = ToReal(Dot3(d0v.m_vComponents, d0v.m_vComponents));
    float l1 = ToReal(Dot3(d1v.m_vComponents, d1v.m_vComponents));
    if (l0 < l1)
    {
        float inv = 1.0f / (float)sqrt(l0);
        if (feat)
        {
            if (r0 == 4)
            {
                feat->m_type = 1;
                feat->m_idx[0] = (short)idx;
            }
            else if (r0 == 8)
            {
                feat->m_type = 1;
                feat->m_idx[0] = DAT_010eced6[idx];
            }
            else
            {
                feat->m_type = 2;
                feat->m_idx[0] = (short)idx;
                feat->m_idx[1] = DAT_010eced6[idx];
            }
        }
        out->m_fClosestPointDistanceSquared = l0 * inv;
        out->m_vHitNormal.m_vComponents = _mm_mul_ps(Splat(inv), d0v.m_vComponents);
        return 1;
    }
    else
    {
        float inv = 1.0f / (float)sqrt(l1);
        if (feat)
        {
            if (r1 == 4)
            {
                feat->m_type = 1;
                feat->m_idx[0] = (short)idx;
            }
            else if (r1 == 8)
            {
                feat->m_type = 1;
                feat->m_idx[0] = DAT_010eced4[idx];
            }
            else
            {
                feat->m_type = 2;
                feat->m_idx[0] = (short)idx;
                feat->m_idx[1] = DAT_010eced4[idx];
            }
        }
        out->m_fClosestPointDistanceSquared = l1 * inv;
        out->m_vHitNormal.m_vComponents = _mm_mul_ps(Splat(inv), d1v.m_vComponents);
        return 1;
    }
}

namespace fnv_00e61fb0 {
extern "C" void _ReadWriteBarrier(void);






template <typename T> inline void swapE6F(T& x, T& y)
{
    T t = x;
    x = y;
    y = t;
}

// @fnv 0x00e61fb0
// src: GUESS 0x00e61fb0 (confidence: low)
void __cdecl hkVector4_ComputeValues_00e61fb0(const hkVector4* pkTriangle, const float* afInputValues, hkMatrix4& kMatrixOut,
                          hkVector4& kNormalOut)
{
    hkVector4 e12;
    e12.setSub4(pkTriangle[2], pkTriangle[1]);
    hkVector4 e20;
    e20.setSub4(pkTriangle[0], pkTriangle[2]);
    hkVector4 e01;
    e01.setSub4(pkTriangle[1], pkTriangle[0]);

    LocalM128 ws = _mm_load_ss(afInputValues + 3);
    hkVector4 n;
    n.setCross(e12, e20);
    n.m_vComponents = _mm_mul_ps(n.m_vComponents, _mm_shuffle_ps(ws, ws, 0));
    kNormalOut.m_vComponents = n.m_vComponents;

    hkVector4 a;
    a.setMul4(_mm_load_ps1(afInputValues + 0), e12);
    hkVector4 b;
    b.setMul4(_mm_load_ps1(afInputValues + 1), e20);
    hkVector4 c;
    c.setMul4(_mm_load_ps1(afInputValues + 2), e01);

    LocalM128 nc9 = _mm_shuffle_ps(n.m_vComponents, n.m_vComponents, 0xc9);
    LocalM128 nd2 = _mm_shuffle_ps(n.m_vComponents, n.m_vComponents, 0xd2);
    kMatrixOut.m_kColumn0.m_vComponents =
        _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xc9), nd2),
                   _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xd2), nc9));
    kMatrixOut.m_kColumn1.m_vComponents =
        _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xc9), nd2),
                   _mm_mul_ps(_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xd2), nc9));
    kMatrixOut.m_kColumn2.m_vComponents =
        _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(c.m_vComponents, c.m_vComponents, 0xc9), nd2),
                   _mm_mul_ps(_mm_shuffle_ps(c.m_vComponents, c.m_vComponents, 0xd2), nc9));

    swapE6F(kMatrixOut.m_kColumn1(0), kMatrixOut.m_kColumn0(1));
    swapE6F(kMatrixOut.m_kColumn2(0), kMatrixOut.m_kColumn0(2));
    swapE6F(kMatrixOut.m_kColumn2(1), kMatrixOut.m_kColumn1(2));

    kMatrixOut.m_kColumn0(3) = kNormalOut(0);
    kMatrixOut.m_kColumn1(3) = kNormalOut(1);
    kMatrixOut.m_kColumn2(3) = kNormalOut(2);
    kMatrixOut.m_kColumn3.setZero4();
    kMatrixOut.m_kColumn3(0) = -afInputValues[0] * afInputValues[4];
}
}  // namespace fnv_00e61fb0

struct S00e62c10_List
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
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    LocalM128* unk60;
    LocalM128* unk64;
    LocalM128* unk68;
    int unk6c;

    void UpdateState_00e62c10(const LocalM128* param);
};

// @fnv 0x00e62c10
// src: GUESS 0x00e62c10 (confidence: low)
void S00e62c10_List::UpdateState_00e62c10(const LocalM128* param)
{
    int index = unk6c;
    unk68[index] = param[0];
    unk60[index] = param[1];
    unk64[index] = param[2];
    unk6c = index + 1;
}

namespace fnv_00e63ba0 {



struct TetraVertex
{
    hkVector4 m_vContactPosition;
    hkVector4 m_kPointA;
    hkVector4 m_kPointB;
    int m_flags;
    int unk34;
    int unk38;
    int unk3C;
};

struct TetraHull
{
    int unk00;
    int unk04;
    int m_iStridedVertexCount;
    int m_iResultCode;
    int m_numFaces;
    int unk14;
    int unk18;
    int unk1C;
    TetraVertex m_kVertices[4];

    void ProcessEntries_00e679d0();
    void ProcessEntries_00e63ba0(const hkVector4* a, const hkVector4* b, const hkVector4* c);
};

// @fnv 0x00e63ba0
// src: GUESS 0x00e63ba0 (confidence: low)
void TetraHull::ProcessEntries_00e63ba0(const hkVector4* a, const hkVector4* b, const hkVector4* c)
{
    m_iStridedVertexCount = 4;
    TetraVertex* v = m_kVertices;
    for (int i = 0; i < 4; i++, v++)
    {
        v->m_kPointA = a[i];
        v->m_kPointB = b[i];
        v->m_vContactPosition = c[i];
        v->m_flags = 0;
    }
    ProcessEntries_00e679d0();
    m_iResultCode = 0;
}
}  // namespace fnv_00e63ba0

struct MoppQueryState
{
    unsigned int primitiveOffset;
    unsigned int properties[1];
};
struct MoppResults
{
    unsigned int* data;
    int count, capacity;
};
struct MoppMemoryRouter
{
    int unk00, unk04, unk08, unk0c;
    void* heap;
};
void* __cdecl hkMemoryRouter_getInstance();
void __cdecl ResizeAudioStream(void* heap, MoppResults* array, int elementSize);
struct MoppErrorSink
{
    virtual void unknown0();
    virtual void unknown1();
    virtual void unknown2();
    virtual int Report(int severity, unsigned int id, const char* message, const char* file, int line);
};
extern MoppErrorSink* DAT_01268360;
struct MoppFormatter
{
    void* vtable;
    unsigned short memorySize, referenceCount;
    void* writer;
    void FUN_00cb1600(char* buffer, int length);
    void ProcessAndReturnValue_00cc01c0(const char* text);
    void FUN_00cc00e0();
};
struct MoppFindAllVM
{
    MoppResults* results;
    void hkpMoppFindAllVirtualMachine_queryOnTreeRight(const MoppQueryState* current, const unsigned char* program);
};
static __forceinline void decodeWord(const unsigned char* __restrict p, unsigned int* __restrict out,
                                     unsigned int index)
{
    out[index] = p[0];
    out[index] <<= 8;
    out[index] += p[1];
}
extern "C" void _ReadWriteBarrier();
static unsigned int readBig16(const unsigned char* p)
{
    return (unsigned(p[0]) << 8) + p[1];
}
static unsigned int readBig24(const unsigned char* p)
{
    return (readBig16(p) << 8) + p[2];
}
static unsigned int readBig32(const unsigned char* p)
{
    return (readBig24(p) << 8) + p[3];
}
// @fnv 0x00e66290
// src: HAVOK_LIB 0x00e66290
void MoppFindAllVM::hkpMoppFindAllVirtualMachine_queryOnTreeRight(const MoppQueryState* current, const unsigned char* program)
{
    MoppQueryState local;
    unsigned int primitive;
    for (;;)
    {
        unsigned int op = *program;
        switch (op)
        {
        case 0x10:
        case 0x11:
        case 0x12:
        case 0x13:
        case 0x14:
        case 0x15:
        case 0x16:
        case 0x17:
        case 0x18:
        case 0x19:
        case 0x1a:
        case 0x1b:
        case 0x1c:
            program += program[3] + 4;
            break;
        case 0x20:
        case 0x21:
        case 0x22:
            program += program[2] + 3;
            break;
        case 0x23:
        case 0x24:
        case 0x25:
            program += readBig16(program + 5) + 7;
            break;
        case 0x29:
        case 0x2a:
        case 0x2b:
            program += 7;
            break;
        case 5:
            program += program[1] + 2;
            break;
        case 6:
            program += readBig16(program + 1) + 3;
            break;
        case 7:
            program += readBig24(program + 1) + 4;
            break;
        case 0x1:
        case 0x2:
        case 0x3:
        case 0x4:
            program += 4;
            break;
        case 9: {
            unsigned int offset = program[1];
            if (current != &local)
            {
                local = *current;
                current = &local;
            }
            local.primitiveOffset += offset;
            program += 2;
            break;
        }
        case 10: {
            unsigned int offset = readBig16(program + 1);
            if (current != &local)
            {
                local = *current;
                current = &local;
            }
            local.primitiveOffset += offset;
            program += 3;
            break;
        }
        case 11: {
            unsigned int offset = readBig32(program + 1);
            if (current != &local)
            {
                local = *current;
                current = &local;
            }
            local.primitiveOffset = offset;
            program += 5;
            break;
        }
        case 0x26:
        case 0x27:
        case 0x28:
            program += 3;
            break;
        case 0x60:
        case 0x61:
        case 0x62:
        case 0x63: {
            unsigned int property = program[1];
            program += 2;
            local.properties[op - 96] = property;
            goto propertiesUpdated;
        }
        case 0x64:
        case 0x65:
        case 0x66:
        case 0x67:
            decodeWord(program + 1, local.properties, op - 100);
            program += 3;
            goto propertiesUpdated;
        case 0x68:
        case 0x69:
        case 0x6a:
        case 0x6b:
            local.properties[op - 104] = readBig32(program + 1);
            program += 5;
        propertiesUpdated: {
            unsigned int value = local.properties[0];
            if (current != &local)
            {
                local = *current;
                current = &local;
            }
            local.properties[0] = value;
            break;
        }
        case 0:
            return;
        default: {
            MoppFormatter formatter;
            unsigned __int64 buffer[64];
            char* text = reinterpret_cast<char*>(buffer);
            formatter.FUN_00cb1600(text, 512);
            formatter.ProcessAndReturnValue_00cc01c0(
                "Unknown command - This mopp data has been corrupted (check for memory trashing), or an hkpMoppBvTreeShape has been pointed at invalid mopp data.\n");
            if (DAT_01268360->Report(3, 0x1298fedd, text, ".\\Collide\\Mopp\\Machine\\hkpMoppFindAllVirtualMachine.cpp",
                                     211))
                __debugbreak();
            formatter.FUN_00cc00e0();
            break;
        }
        case 0x50:
            primitive = program[1];
            goto terminal;
        case 0x51:
            primitive = readBig16(program + 1);
            goto terminal;
        case 0x52:
            primitive = readBig24(program + 1);
            goto terminal;
        case 0x53: {
            struct
            {
                unsigned hi, b3, b4;
            } t;
            t.b3 = program[3];
            t.hi = readBig16(program + 1) << 16;
            t.b3 <<= 8;
            t.b4 = program[4] + t.hi;
            primitive = t.b4 + t.b3;
        }
            goto terminal;
        case 0x30:
        case 0x31:
        case 0x32:
        case 0x33:
        case 0x34:
        case 0x35:
        case 0x36:
        case 0x37:
        case 0x38:
        case 0x39:
        case 0x3a:
        case 0x3b:
        case 0x3c:
        case 0x3d:
        case 0x3e:
        case 0x3f:
        case 0x40:
        case 0x41:
        case 0x42:
        case 0x43:
        case 0x44:
        case 0x45:
        case 0x46:
        case 0x47:
        case 0x48:
        case 0x49:
        case 0x4a:
        case 0x4b:
        case 0x4c:
        case 0x4d:
        case 0x4e:
        case 0x4f:
            primitive = op - 0x30;
        terminal:
            primitive += current->primitiveOffset;
            MoppResults* array = results;
            MoppMemoryRouter* router = (MoppMemoryRouter*)hkMemoryRouter_getInstance();
            if (array->count == (array->capacity & 0x3fffffff))
                ResizeAudioStream(router->heap, array, 4);
            unsigned int* dest = &array->data[array->count++];
            *dest = primitive;
            return;
        }
    }
}

namespace fnv_00e67740 {


extern const float DAT_01011d78 = 0.0f;
extern const float DAT_01017718;
extern const float DAT_01016248;
static __forceinline void SetHullCross(hkVector4& result, const hkVector4& a, const hkVector4& b)
    {
        LocalM128 a0 = _mm_shuffle_ps(a.quad, a.quad, 0xc9);
        LocalM128 b0 = _mm_shuffle_ps(b.quad, b.quad, 0xd2);
        a0 = _mm_mul_ps(a0, b0);
        b0 = _mm_shuffle_ps(a.quad, a.quad, 0xd2);
        LocalM128 b1 = _mm_shuffle_ps(b.quad, b.quad, 0xc9);
        b0 = _mm_mul_ps(b0, b1);
        result.quad = _mm_sub_ps(b0, a0);
    }
struct HullEdge;
struct HullLink;
struct HullVertex
{
    hkVector4 position;
    int unknown10, unknown14, unknown18, unknown1c;
    int unknown20, unknown24, unknown28, unknown2c;
    HullLink* next;
    int unknown34, unknown38, unknown3c;
};
struct HullLink
{
    HullVertex* vertex;
    HullLink* second;
    HullLink* next;
    HullEdge* owner;
};
struct HullEdge
{
    hkVector4 normal;
    HullLink side[3];
    float dot;
    int state, unknown48, unknown4c;
};
struct HullResult
{
    int value;
    __forceinline HullResult(int code) : value(code)
    {}
};
struct Hull
{
    int unknown00, unknown04;
    int vertexCount, freeCount, edgeCount;
    int unknown14, unknown18, unknown1c;
    HullVertex vertices[55];
    HullEdge* freeEdges[100];
    HullEdge edges[100];
    __forceinline HullEdge* getEdge(int index)
    {
        return &edges[index];
    }
    __forceinline void allocateEdges(HullEdge** result, int num)
    {
        for (int i = 0; i < num; ++i)
            result[i] = getEdge(edgeCount++);
    }
    int ProcessAndTransformResult_00e67740(int count, HullLink* links, const HullVertex* endpoint);
    __forceinline HullResult buildFan(int count, HullLink* links, const HullVertex* endpoint);
};
__forceinline HullResult Hull::buildFan(int count, HullLink* links, const HullVertex* endpoint)
{
    int gathered, remaining, oldCount, following;
    HullLink* cursor;
    int index;
    HullEdge* edge;
    HullEdge* next;
    HullVertex* endPoint;
    HullVertex* startPoint;

    {
        HullEdge* queue[100];
        gathered = 0;
        remaining = count;
        oldCount = freeCount - 1;
        while (remaining && oldCount >= 0)
        {
            queue[gathered] = freeEdges[oldCount];
            --freeCount;
            --remaining;
            ++gathered;
            --oldCount;
        }
        if (0 < remaining)
        {
            allocateEdges(queue + gathered, remaining);
        }
        cursor = links;
        for (index = 0; index < count; index = following)
        {
            if (!cursor)
                return 2;
            edge = queue[index];
            following = index + 1;
            if (following < count)
                next = queue[index + 1];
            else
                next = queue[0];
            edge->side[0].owner = edge;
            edge->side[1].owner = edge;
            edge->side[2].owner = edge;
            edge->side[0].second = &edge->side[1];
            edge->side[1].second = &edge->side[2];
            edge->side[2].second = &edge->side[0];
            endPoint = cursor->second->vertex;
            startPoint = cursor->vertex;
            edge->side[0].vertex = endPoint;
            edge->side[2].vertex = const_cast<HullVertex*>(endpoint);
            edge->side[1].vertex = startPoint;
            cursor->next = &edge->side[0];
            edge->side[0].next = cursor;
            next->side[1].next = &edge->side[2];
            edge->side[2].next = &next->side[1];
            hkVector4 u;
            hkVector4 v;
            hkVector4 normal;
            u.m_vComponents = _mm_sub_ps((endPoint->position).m_vComponents, (startPoint->position).m_vComponents);
            v.m_vComponents = _mm_sub_ps((startPoint->position).m_vComponents, (endpoint->position).m_vComponents);
            SetHullCross(normal, v, u);
            if (LengthSquared3(normal) == 0.0f)
                return 2;
            Normalize3(normal);
            edge->dot = ToReal(Dot3(endPoint->position.m_vComponents, normal.m_vComponents));
            edge->normal.quad = normal.quad;
            HullVertex* consumed = cursor->second->vertex;
            cursor = consumed->next;
            consumed->next = 0;
        }
        for (int i = 0; i < edgeCount; ++i)
            edges[i].state = 0;
        for (int j = 0; j < vertexCount; ++j)
            vertices[j].next = 0;
        return links != cursor ? 2 : 0;
    }
}

// @fnv 0x00e67740
// src: GUESS 0x00e67740 (confidence: low)
int Hull::ProcessAndTransformResult_00e67740(int count, HullLink* links, const HullVertex* endpoint)
{
    return buildFan(count, links, endpoint).value;
}
}  // namespace fnv_00e67740

namespace fnv_00e679d0 {





struct TetraVertex
{
    hkVector4 m_vContactPosition;
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
};

struct TetraFace;

struct TetraEdge
{
    TetraVertex* m_pVertex;
    TetraEdge* m_next;
    TetraEdge* m_twin;
    TetraFace* m_face;
};

struct TetraFace
{
    hkVector4 m_kTriangleNormal;
    TetraEdge m_kEdges[3];
    float m_fClosestPointDistanceSquared;
    int m_flags;
    int unk48;
    int unk4C;

    __declspec(noinline) void ComputePlaneNormalAndDistance();
};

struct TetraEdgeInit
{
    int m_vertexOffset;
    int m_faceOffset;
    int m_edgeOffset;
};

extern TetraEdgeInit DAT_010ed0f0[12];

struct TetraHull
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_numFaces;
    int unk14;
    int unk18;
    int unk1C;
    TetraVertex m_kVertices[61];
    int unkF60;
    int unkF64;
    int unkF68;
    int unkF6C;
    TetraFace m_faces[4];

    void ProcessEntries_00e679d0();
};

// src: GUESS 0x00e67570 (confidence: high)
void TetraFace::ComputePlaneNormalAndDistance()
{
    LocalM128 a = m_kEdges[0].m_pVertex->m_vContactPosition.m_vComponents;
    LocalM128 b = m_kEdges[1].m_pVertex->m_vContactPosition.m_vComponents;
    LocalM128 c = m_kEdges[2].m_pVertex->m_vContactPosition.m_vComponents;
    LocalM128 e0 = _mm_sub_ps(a, b);
    LocalM128 e1 = _mm_sub_ps(b, c);
    LocalM128 n = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(e1, e1, 0xd2), _mm_shuffle_ps(e0, e0, 0xc9)),
                          _mm_mul_ps(_mm_shuffle_ps(e1, e1, 0xc9), _mm_shuffle_ps(e0, e0, 0xd2)));
    m_kTriangleNormal.m_vComponents = n;
    LocalM128 d = _mm_mul_ps(n, a);
    d = _mm_add_ss(_mm_shuffle_ps(d, d, 0xaa), _mm_add_ss(_mm_shuffle_ps(d, d, 0x55), d));
    _mm_store_ss(&m_fClosestPointDistanceSquared, d);
}

// @fnv 0x00e679d0
// src: GUESS 0x00e679d0 (confidence: low)
void TetraHull::ProcessEntries_00e679d0()
{
    m_numFaces = 4;
    const TetraEdgeInit* init = DAT_010ed0f0;
    TetraFace* end = &m_faces[4];
    TetraFace* first = m_faces;
    for (TetraFace* f = m_faces; f != end; f++)
    {
        f->m_kEdges[0].m_next = &f->m_kEdges[1];
        f->m_kEdges[1].m_next = &f->m_kEdges[2];
        f->m_flags = 0;
        f->m_kEdges[2].m_next = &f->m_kEdges[0];
        for (TetraEdge* e = f->m_kEdges; e < f->m_kEdges + 3; e++)
        {
            e->m_face = f;
            e->m_pVertex = (TetraVertex*)((char*)m_kVertices + init->m_vertexOffset);
            e->m_twin = (TetraEdge*)((char*)m_faces[0].m_kEdges + init->m_faceOffset + init->m_edgeOffset);
            init++;
        }
    }

    TetraFace* last = &m_faces[3];
    last->ComputePlaneNormalAndDistance();

    LocalM128 d = _mm_mul_ps(_mm_sub_ps(m_kVertices[0].m_vContactPosition.m_vComponents, m_kVertices[1].m_vContactPosition.m_vComponents),
                          last->m_kTriangleNormal.m_vComponents);
    float dot;
    _mm_store_ss(&dot, _mm_add_ss(_mm_shuffle_ps(d, d, 0xaa), _mm_add_ss(_mm_shuffle_ps(d, d, 0x55), d)));
    if (dot > 0.0f)
    {
        TetraVertex* v1 = &m_kVertices[1];
        TetraVertex* v0 = &m_kVertices[0];
        m_faces[2].m_kEdges[0].m_pVertex = v1;
        m_faces[1].m_kEdges[0].m_pVertex = v1;
        first->m_kEdges[0].m_pVertex = v1;
        last->m_kEdges[0].m_pVertex = v0;
        m_faces[1].m_kEdges[1].m_pVertex = v0;
        first->m_kEdges[2].m_pVertex = v0;
    }

    TetraFace* f = first;
    for (int i = 3; i >= 0; i--)
    {
        f->ComputePlaneNormalAndDistance();
        f++;
    }
}
}  // namespace fnv_00e679d0

extern "C" LocalM128 _mm_rsqrt_ps(LocalM128);

extern LocalM128 DAT_010c71c0;
extern LocalM128 DAT_010c71d0;

// @fnv 0x00e61e70
// src: GUESS 0x00e61e70 (confidence: low)
void __cdecl hkVector4_ComputeValues_00e61e70(const float* p, float* out)
{
    hkVector4 b;
    b.m_vComponents = _mm_sub_ps(_mm_load_ps(p + 8), _mm_load_ps(p + 4));
    hkVector4 a;
    a.m_vComponents = _mm_sub_ps(_mm_load_ps(p), _mm_load_ps(p + 8));
    hkVector4 c;
    c.m_vComponents = _mm_sub_ps(_mm_load_ps(p + 4), _mm_load_ps(p));
    hkVector4 n;
    n.setCross(b, a);
    LocalM128 len;
    len.m128_f32[0] = LengthSquared3(b);
    len.m128_f32[1] = LengthSquared3(a);
    len.m128_f32[2] = LengthSquared3(c);
    float nl = LengthSquared3(n);
    len.m128_f32[3] = nl;
    LocalM128 r = _mm_rsqrt_ps(len);
    len = _mm_mul_ps(_mm_sub_ps(DAT_010c71c0, _mm_mul_ps(_mm_mul_ps(r, len), r)), _mm_mul_ps(DAT_010c71d0, r));
    out[0] = len.m128_f32[0];
    out[1] = len.m128_f32[1];
    out[2] = len.m128_f32[2];
    float w = len.m128_f32[3];
    out[3] = w;
    out[4] = nl * w;
}
