#include "../../../../../include/hkArray.h"
// src/havok/common/visualize/shape/hkdisplaycone_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/common/visualize/shape/hkdisplaycone.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/common/visualize/shape/hkdisplaycone.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/shape/hkdisplaycone.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <xmmintrin.h>
struct __declspec(align(16)) Vertex
{
    __m128 value;
};
struct Edge
{
    int polygon, end, start, adjacent;
};
// Exe 0x00de57a0: three-word Havok owning arrays, initialized with DONT_DEALLOCATE_FLAG.

struct GeometryBuffers
{
    hkArray<Vertex> vertices;
    hkArray<Edge> edges;
    GeometryBuffers() : vertices(), edges()
    {}
    static void* operator new(unsigned int, void* position)
    {
        return position;
    }
};
struct Allocator
{
    virtual void unused();
    virtual void* __thiscall Allocate(unsigned int);
};
struct GlobalContext
{
    int unk00, unk04, unk08, unk0c;
    Allocator* allocator;
};
extern "C" GlobalContext* __cdecl hkMemoryRouter_getInstance();
extern "C" void __cdecl ResizeAudioStream(Allocator*, hkArray<Vertex>*, int);
extern "C" void __cdecl hkArrayUtil__reserve(Allocator*, hkArray<Edge>*, int, int);
struct ForwardArg
{
    GeometryBuffers* value;
};
struct MeshBuilder;
extern "C" void __fastcall hkDisplayCone_generateConeVertices(MeshBuilder*, ForwardArg);
struct MeshBuilder
{
    int unk00;
    int unk04;
    GeometryBuffers* geometry;
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
    Vertex initialVertex;
    int unk70, unk74, unk78, unk7c;
    volatile int segmentCount;
    void __thiscall InitializeGeometry();
};

#include <math.h>
extern "C" void _ReadWriteBarrier();

extern const ::__m128 DAT_010c71e0;

namespace cone_vertex_detail {
static inline float my_abs(float x)
{
    return ::fabsf(x);
}
struct HArr;
struct Q;
struct HArr
{
    Q* m_data;
    int m_iElementCount;
    unsigned m_cap;
};
struct __declspec(align(16)) Q
{
    union
    {
        ::__m128 quad;
        float lanes[4];
    };
    float& component(unsigned int i)
    {
        return lanes[i];
    }
    const float& component(unsigned int i) const
    {
        return lanes[i];
    }
    const ::__m128& get() const
    {
        return quad;
    }
    void hkQuaternion_setAxisAngle(const Q* axis, float angle);
    void SetRotatedDirection(const Q& quaternion, const Q& vector);
    __forceinline void addMul(float scale, const Q& direction)
    {
        ::__m128 factor = ::_mm_load_ss(&scale);
        factor = ::_mm_shuffle_ps(factor, factor, 0);
        quad = ::_mm_add_ps(::_mm_mul_ps(factor, direction.quad), quad);
    }
};
struct ArrayRef
{
    HArr* value;
    ArrayRef(HArr* p) : value(p)
    {}
};
struct Cls
{
    int u00;
    int u04;
    int u08;
    int u0c;
    int u10;
    int u14;
    int u18;
    int u1c;
    int u20;
    int u24;
    int u28;
    int u2c;
    int u30;
    int u34;
    int u38;
    int u3c;
    int u40;
    int u44;
    int u48;
    int u4c;
    int u50;
    int u54;
    int u58;
    int u5c;
    ::__m128 m_kRayStart;
    Q m_kAxisEndPoints;
    int m_uiItemCount;
    float m_fConeAngle;
    float m_step;
    void __thiscall hkDisplayCone_generateConeVertices(ArrayRef output);
};
static __forceinline ::__m128 rot(const Q& quaternion, const Q& vector)
{
    const ::__m128& q = quaternion.get();
    const ::__m128& v = vector.get();
    ::__m128 w = ::_mm_shuffle_ps(q, q, 0xff);
    ::__m128 d = ::_mm_mul_ps(v, q);
    ::__m128 d_y = ::_mm_shuffle_ps(d, d, 0x55);
    ::__m128 sum_xy = ::_mm_add_ss(d_y, d);
    ::__m128 d_z = ::_mm_shuffle_ps(d, d, 0xaa);
    ::__m128 dot = ::_mm_add_ss(d_z, sum_xy);

    ::__m128 q_c9 = ::_mm_shuffle_ps(q, q, 0xc9);
    ::__m128 v_d2 = ::_mm_shuffle_ps(v, v, 0xd2);
    ::__m128 c1 = ::_mm_mul_ps(q_c9, v_d2);

    ::__m128 q_d2 = ::_mm_shuffle_ps(q, q, 0xd2);
    ::__m128 v_c9 = ::_mm_shuffle_ps(v, v, 0xc9);
    ::__m128 c2 = ::_mm_mul_ps(q_d2, v_c9);

    ::__m128 cross = ::_mm_sub_ps(c1, c2);
    ::__m128 cross_w = ::_mm_mul_ps(cross, w);

    ::__m128 w2 = ::_mm_mul_ps(w, w);
    ::__m128 w2_c = ::_mm_add_ps(w2, DAT_010c71e0);
    ::__m128 term1 = ::_mm_mul_ps(w2_c, v);

    ::__m128 dot_splat = ::_mm_shuffle_ps(dot, dot, 0);
    ::__m128 term2 = ::_mm_mul_ps(dot_splat, q);

    ::__m128 sum2 = ::_mm_add_ps(term1, term2);
    ::__m128 res = ::_mm_add_ps(cross_w, sum2);
    return ::_mm_add_ps(res, res);
}
__forceinline void Q::SetRotatedDirection(const Q& quaternion, const Q& vector)
{
    quad = rot(quaternion, vector);
}
// @fnv 0x00de54b0
// src: XBOX_PDB 0x00de54b0
void __thiscall Cls::hkDisplayCone_generateConeVertices(ArrayRef output)
{
    int count = m_uiItemCount;
    ::GlobalContext* context = ::hkMemoryRouter_getInstance();
    ::Allocator* ctx = context->allocator;
    _ReadWriteBarrier();
    HArr* arr = output.value;
    int capacity = arr->m_cap & 0x3fffffff;
    if (capacity < count)
    {
        int grow = capacity * 2;
        if (count >= grow)
            grow = count;
        ::hkArrayUtil__reserve(ctx, (::hkArray< ::Edge>*)arr, grow, 16);
    }
    arr->m_iElementCount = count;

    const Q* axis = &m_kAxisEndPoints;
    struct Scratch
    {
        volatile float best;
        int minIdx;
        volatile float temp;
        volatile float v1;
    } scratch;
    scratch.minIdx = 0;
    scratch.best = ::fabs((double)axis->component(0));
    scratch.best = scratch.best;
    int i = 1;
    int j = i + 1;
    scratch.temp = ::fabs((double)axis->component(1));
    scratch.v1 = scratch.temp;
    scratch.temp = ::fabs((double)axis->component(2));
    scratch.temp = scratch.temp;
    double cachedY = scratch.v1;
    if (cachedY < scratch.best)
    {
        scratch.best = cachedY;
        i = 0;
        scratch.minIdx = 1;
    }
    if (scratch.temp < scratch.best)
        j = scratch.minIdx;

    Q ls;
    ls.quad = ::_mm_setzero_ps();
    ls.component(i) = axis->component(j);
    ls.component(j) = -axis->component(i);
    ::__m128 pv = ls.quad;
    ::__m128 cur = ::_mm_mul_ps(pv, pv);
    ::__m128 t = ::_mm_add_ss(::_mm_shuffle_ps(cur, cur, 0xaa), ::_mm_add_ss(::_mm_shuffle_ps(cur, cur, 0x55), cur));
    ::__m128 r = ::_mm_rsqrt_ss(t);
    ::__m128 inv = ::_mm_mul_ss(::_mm_mul_ss(::_mm_set_ss(0.5f), r),
                                ::_mm_sub_ss(::_mm_set_ss(3.0f), ::_mm_mul_ss(::_mm_mul_ss(t, r), r)));
    inv = ::_mm_andnot_ps(::_mm_cmpeq_ss(t, ::_mm_set_ss(0.0f)), inv);
    ls.quad = ::_mm_mul_ps(::_mm_shuffle_ps(inv, inv, 0), pv);
    Q q1, q2;
    q1.hkQuaternion_setAxisAngle(&ls, m_fConeAngle);
    scratch.v1 = 2.0f * 3.14159265f / (float)m_uiItemCount;
    q2.hkQuaternion_setAxisAngle(axis, scratch.v1);
    Q d;
    d.SetRotatedDirection(q1, *axis);
    for (int k = 0; k < m_uiItemCount; k++)
    {
        arr->m_data[k].quad = m_kRayStart;
        arr->m_data[k].addMul(m_step, d);
        d.SetRotatedDirection(q2, d);
    }
}

}
