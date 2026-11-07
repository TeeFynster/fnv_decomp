#define FNV64_HKVECTOR4_OWN_ASSIGN   // this unit defines its own hkVector4 assign form
#define FNV64_HKVECTOR4_OWN_COPY   // this unit defines its own hkVector4 copy form
// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprimitivedrawer_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprimitivedrawer_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprimitivedrawer_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-29 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprimitivedrawer.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprimitivedrawer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprimitivedrawer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../../../../include/hkVector4.h"
#include "../../../../../../../../../include/hkMatrix3.h"
#include "../../../../../../../../../include/hkQuaternion.h"
#include "../../../../../../../../../include/hkDebugDisplayHandler.h"
#include "../../../../../../../../../include/hkThreadMemory.h"

struct CpuObject
{
    int value;
    void hkpPrimitiveDrawer_setDisplayHandler(int value);
};


inline hkVector4::hkVector4(const hkVector4& vector)
{
    m_vComponents = vector.m_vComponents;
}

inline void hkVector4::operator=(const hkVector4& vector)
{
    m_vComponents = vector.m_vComponents;
}

inline hkQuaternion::hkQuaternion()
{}

static __forceinline void SetSubMul4(hkVector4& result, const hkVector4& a, const hkVector4& b, hkReal r)
{
    __m128 s = _mm_load_ss(&r);
    s = _mm_shuffle_ps(s, s, 0);
    result.m_vComponents = _mm_sub_ps(a.m_vComponents, _mm_mul_ps(s, b.m_vComponents));
}

class AxisDisplayOwner
{
  public:
    hkDebugDisplayHandler* m_handler;
    void UpdateState_00e10bf0(const hkVector4& pos, const hkMatrix3& rot, hkReal size, int color, int id, int tag);
};

// @fnv 0x00e10bf0
// src: GUESS 0x00e10bf0 (confidence: low)
void AxisDisplayOwner::UpdateState_00e10bf0(const hkVector4& pos, const hkMatrix3& rot, hkReal size, int color, int id, int tag)
{
    hkVector4 x = rot.m_kColumn0;
    hkVector4 y = rot.m_kColumn1;
    hkVector4 z = rot.m_kColumn2;
    hkVector4 start;
    hkVector4 end;
    SetSubMul4(start, pos, x, size);
    SetSubMul4(end, pos, x, -size);
    m_handler->DisplayLine(start, end, color, id, tag);
    SetSubMul4(start, pos, y, size);
    SetSubMul4(end, pos, y, -size);
    m_handler->DisplayLine(start, end, color, id, tag);
    SetSubMul4(start, pos, z, size);
    SetSubMul4(end, pos, z, -size);
    m_handler->DisplayLine(start, end, color, id, tag);
}

extern "C" void _ReadWriteBarrier();

char* __cdecl FUN_00c85690(hkMemory* alloc, int size);
void __cdecl hkMemoryRouter_easyFree(hkMemory* owner, char* data);

extern __declspec(align(16)) float DAT_010c71e0[4];
extern double DAT_0101ff48;

struct VectorArg
{
    __m128* p;
    VectorArg(__m128* v) : p(v)
    {}
    operator __m128*() const
    {
        return p;
    }
};

struct CircleDrawer
{
    hkDebugDisplayHandler* drawer;
    void ProcessEntries_00e10f60(float angle, __m128* base, __m128* a10, VectorArg a14, int count, int a1c, float a20, int a24,
                      int a28);
};

static __forceinline __m128 RotateInitial(const hkQuaternion& quat, const __m128& vector)
{
    const __m128& v = vector;
    __m128 q = *(const __m128*)&quat;
    __m128 w = _mm_shuffle_ps(q, q, 0xff);
    __m128 factor = _mm_add_ps(*(const __m128*)DAT_010c71e0, _mm_mul_ps(w, w));
    __m128 scaled = _mm_mul_ps(v, factor);
    __m128 m = _mm_mul_ps(q, v);
    __m128 sumxy = _mm_add_ss(_mm_shuffle_ps(m, m, 0x55), m);
    __m128 dot = _mm_add_ss(_mm_shuffle_ps(m, m, 0xaa), sumxy);
    __m128 d = _mm_shuffle_ps(dot, dot, 0);
    scaled = _mm_add_ps(scaled, _mm_mul_ps(d, q));
    __m128 first = _mm_mul_ps(_mm_shuffle_ps(q, q, 0xc9), _mm_shuffle_ps(v, v, 0xd2));
    __m128 second = _mm_mul_ps(_mm_shuffle_ps(q, q, 0xd2), _mm_shuffle_ps(v, v, 0xc9));
    __m128 cross = _mm_sub_ps(first, second);
    scaled = _mm_add_ps(scaled, _mm_mul_ps(w, cross));
    return _mm_add_ps(scaled, scaled);
}

static __forceinline __m128 Rotate(const hkQuaternion& quat, const __m128& vector)
{
    __m128 v = vector;
    __m128 q = *(const __m128*)&quat;
    __m128 w = _mm_shuffle_ps(q, q, 0xff);
    __m128 factor = _mm_add_ps(*(const __m128*)DAT_010c71e0, _mm_mul_ps(w, w));
    __m128 scaled = _mm_mul_ps(v, factor);
    __m128 m = _mm_mul_ps(q, v);
    __m128 sumxy = _mm_add_ss(_mm_shuffle_ps(m, m, 0x55), m);
    __m128 dot = _mm_add_ss(_mm_shuffle_ps(m, m, 0xaa), sumxy);
    __m128 d = _mm_shuffle_ps(dot, dot, 0);
    scaled = _mm_add_ps(scaled, _mm_mul_ps(d, q));
    __m128 first = _mm_mul_ps(_mm_shuffle_ps(q, q, 0xc9), _mm_shuffle_ps(v, v, 0xd2));
    __m128 second = _mm_mul_ps(_mm_shuffle_ps(q, q, 0xd2), _mm_shuffle_ps(v, v, 0xc9));
    __m128 cross = _mm_sub_ps(first, second);
    scaled = _mm_add_ps(scaled, _mm_mul_ps(w, cross));
    return _mm_add_ps(scaled, scaled);
}

// @fnv 0x00e10f60
// src: GUESS 0x00e10f60 (confidence: low)
void CircleDrawer::ProcessEntries_00e10f60(float angle, __m128* base, __m128* a10, VectorArg a14, int count, int a1c, float a20,
                                int a24, int a28)
{
    hkThreadMemory* h = hkThreadMemory::GetMonitorStream();
    hkMemory* allocator = h->m_pMemoryAllocator;
    char* buf = FUN_00c85690(allocator, count * 16);
    float r = a20 / angle;
    __declspec(align(16)) hkQuaternion q1;
    q1.hkQuaternion_setAxisAngle((void*)(__m128*)a14, angle);
    __declspec(align(16)) hkQuaternion q2;
    float ang2 = (float)(DAT_0101ff48 / (double)count);
    __m128* direction = a10;
    q2.hkQuaternion_setAxisAngle(direction, ang2);
    __m128 v = RotateInitial(q1, *direction);
    __m128* center = base;
    __m128* out = (__m128*)buf;
    for (int i = 0; i < count; i++)
    {
        out[i] = *center;
        _ReadWriteBarrier();
        out[i] = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(_mm_load_ss(&r), _mm_load_ss(&r), 0), v), out[i]);
        v = Rotate(q2, v);
    }
    for (int i = 0; i < count; i++)
    {
        drawer->DisplayLine(*(hkVector4*)base, *(hkVector4*)(buf + i * 16), a1c, a24, a28);
        drawer->DisplayLine(*(hkVector4*)(buf + i * 16), *(hkVector4*)(buf + (((i + 1) % count) * 16)), a1c, a24, a28);
    }
    h = hkThreadMemory::GetMonitorStream();
    hkMemoryRouter_easyFree(h->m_pMemoryAllocator, buf);
}

namespace fnv_00e11180 {
static inline void PlaneDrawAdd(hkVector4& result, const hkVector4& a)
{
    result.m_vComponents = _mm_add_ps(result.m_vComponents, a.m_vComponents);
}

static inline __m128 PlaneDrawDot3(__m128 t)
{
    __m128 a = _mm_shuffle_ps(t, t, 0x55);
    a = _mm_add_ss(a, t);
    __m128 b = _mm_shuffle_ps(t, t, 0xaa);
    return _mm_add_ss(b, a);
}

extern const float DAT_01011d78;
extern const float DAT_01017718;
extern const float DAT_01016248;
extern const __m128 DAT_010c71e0;
extern const float DAT_01064f60;
extern const float DAT_0101ff38;
extern const double DAT_010eacc0;

static __forceinline __m128 PlaneDrawRotate(__m128 q, __m128 p)
{
    __m128 nh = DAT_010c71e0;
    __m128 qw = _mm_shuffle_ps(q, q, 0xff);
    __m128 factor = _mm_add_ps(nh, _mm_mul_ps(qw, qw));
    __m128 sum = _mm_mul_ps(p, factor);
    __m128 dot = PlaneDrawDot3(_mm_mul_ps(q, p));
    dot = _mm_shuffle_ps(dot, dot, 0);
    sum = _mm_add_ps(sum, _mm_mul_ps(dot, q));
    __m128 cp0 =
        _mm_mul_ps(_mm_shuffle_ps(q, q, 0xc9), _mm_shuffle_ps(p, p, 0xd2));
    __m128 cp1 =
        _mm_mul_ps(_mm_shuffle_ps(q, q, 0xd2), _mm_shuffle_ps(p, p, 0xc9));
    __m128 cross = _mm_sub_ps(cp0, cp1);
    sum = _mm_add_ps(sum, _mm_mul_ps(qw, cross));
    return _mm_add_ps(sum, sum);
}

struct PlaneDrawObject : CpuObject
{
    void ProcessEntries_00e11180(const hkVector4* p1, int p2, const hkVector4* p3, int p4, float p5, int p6, int p7);
    void ComputeValues_00e10d50(const hkVector4* p1, int p2, const hkVector4* v, int p4, float p5, int p6, int p7);
};

// @fnv 0x00e11180
// src: GUESS 0x00e11180 (confidence: low)
void PlaneDrawObject::ProcessEntries_00e11180(const hkVector4* p1, int p2, const hkVector4* p3, int p4, float p5,
                                   int p6, int p7)
{
    float s = (float)((double)p5 * DAT_010eacc0);
    hkVector4 L;
    hkVector4 P1v;
    __m128 t = _mm_load_ss(&s);
    __m128 splat = _mm_shuffle_ps(t, t, 0);
    *(__m128*)&L = _mm_mul_ps(splat, *(const __m128*)p3);
    hkQuaternion D1;
    D1.hkQuaternion_setAxisAngle((void*)p2, DAT_0101ff38);
    hkQuaternion D2;
    D2.hkQuaternion_setAxisAngle((void*)p2, DAT_01064f60);

    L.m_vComponents = PlaneDrawRotate(*(__m128*)&D2, L.m_vComponents);
    P1v.m_vComponents = p1->m_vComponents;
    hkVector4 A[4];
    for (int i = 0; i < 4; ++i)
    {
        A[i] = P1v;
        PlaneDrawAdd(A[i], L);
        L.m_vComponents = PlaneDrawRotate(*(__m128*)&D1, L.m_vComponents);
    }

    {
        hkDebugDisplayHandler* sk = (hkDebugDisplayHandler*)this->value;
        sk->DisplayLine(A[0], A[1], p4, p6, p7);
    }
    {
        hkDebugDisplayHandler* sk = (hkDebugDisplayHandler*)this->value;
        sk->DisplayLine(A[1], A[2], p4, p6, p7);
    }
    {
        hkDebugDisplayHandler* sk = (hkDebugDisplayHandler*)this->value;
        sk->DisplayLine(A[2], A[3], p4, p6, p7);
    }
    {
        hkDebugDisplayHandler* sk = (hkDebugDisplayHandler*)this->value;
        sk->DisplayLine(A[3], A[0], p4, p6, p7);
    }
    {
        hkDebugDisplayHandler* sk = (hkDebugDisplayHandler*)this->value;
        sk->DisplayLine(A[0], A[2], p4, p6, p7);
    }
    {
        hkDebugDisplayHandler* sk = (hkDebugDisplayHandler*)this->value;
        sk->DisplayLine(A[1], A[3], p4, p6, p7);
    }

    __m128 ll = *(const __m128*)&L;
    __m128 sq2 = _mm_mul_ps(ll, ll);
    __m128 dot = PlaneDrawDot3(sq2);
    __m128 r = dot;
    r = _mm_rsqrt_ss(r);
    __m128 mask = _mm_cmpeq_ss(dot, _mm_set_ss(DAT_01011d78));
    __m128 dr = _mm_mul_ss(_mm_mul_ss(dot, r), r);
    __m128 t3 = _mm_sub_ss(_mm_set_ss(DAT_01017718), dr);
    __m128 scale =
        _mm_mul_ss(_mm_mul_ss(_mm_set_ss(DAT_01016248), r), t3);
    __m128 sel = _mm_andnot_ps(mask, scale);
    __m128 spl = sel;
    spl = _mm_shuffle_ps(spl, sel, 0);
    *(__m128*)&L = _mm_mul_ps(spl, ll);

    this->ComputeValues_00e10d50(p1, p2, &L, p4, p5, p6, p7);
}
}  // namespace fnv_00e11180
