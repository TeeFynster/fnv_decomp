// src/havok/common/internal/convexhull/hkgeometryutility_gs_nogs_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/common/internal/convexhull/hkgeometryutility.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /O2 /GS- /EHsc /Gy (unit lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton.
#define FNV_VEC4_SIMD
#include "../../../../../include/Vec4.h"
#include "../../../../../include/hkSimdReal.h"
#include "../../../../../include/hkVector4.h"


// src/havok/common/internal/convexhull/hkgeometryutility.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/convexhull/hkgeometryutility.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_00d5a5e0_ctxA
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;

    void InitA();
    int FindB(void* a1, void* b);
    void SetB(int zero, int a2);
    void FinishA();
};
struct FUN_00d5a5e0_ctxB
{
    unsigned char m_00;
    unsigned char unk01;
    unsigned short unk02;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;

    void InitB();
};
void __cdecl InitAndSetB(void* a1, int a2);
struct FUN_00d5a630_ctxA
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;

    void InitA();
    int FindB(void* a1, void* b);
    void SetB(int zero, int a2);
    void SetF(float f, int zero);
    void SetC(int a3);
    void FinishA();
};
struct FUN_00d5a630_ctxB
{
    unsigned char m_00;
    unsigned char unk01;
    unsigned short unk02;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;

    void InitB();
};
extern float DAT_0106ea1c;
void __cdecl hkGeometryUtility_createConvexGeometry(void* a1, int a2, int a3);
struct S_00d5a6b0_Array
{
    Vec4* m_data;
    int m_iElementCount;
};
void SubtractFromW(S_00d5a6b0_Array* pArray, float val);
struct D5C110Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void ReturnMemory(void* p, int numBytes);
};
struct D5C110MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D5C110Allocator* m_pStreamAllocator;

    D5C110Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" D5C110MemoryRouter& __cdecl hkMemoryRouter_getInstance();
// hkArray<hkVector4> without a destructor (Havok was built without EH): explicit cleanup.
struct D5C110VertexArray
{
    Vec4* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    D5C110VertexArray() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}

    void ClearAndRelease()
    {
        D5C110Allocator& alloc = hkMemoryRouter_getInstance().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(Vec4));
    }
};
struct D5C110StridedVertices
{
    const float* m_kVertices;
    int m_iStridedVertexCount;
    int m_iVertexStride;
};
struct D5C110Geometry
{
    int unk00;
    int m_iStridedVertexCount;
    int unk08;
    int unk0C;
    int m_iTriangleCount;
};
void __cdecl ProcessArg(const void* shape, D5C110VertexArray& vertices);
void __cdecl InitAndSetB(const D5C110StridedVertices& vertices, D5C110Geometry& out);
void __cdecl BuildGeometryFromShape(const void* shape, D5C110Geometry& aGeometry);
struct D5C110VertexArray;
void __cdecl ProcessArg(const void* shape, D5C110VertexArray& vertices);
void __cdecl hkGeometryUtility_createVerticesFromPlaneEquations(const void* shape, D5C110VertexArray& vertices);
#include <math.h>
struct S00d5ad60_cls
{
    float m_f00;
    unsigned char S00d5ad60_call(float* other, float threshold);
};
static unsigned char approxEquals(S00d5ad60_cls* self, float* other, float threshold);
#ifndef _INCLUDED_MM2
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
#endif
#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_setr_ps(float, float, float, float);
#endif
extern float DAT_01011d78;
static int Hkgeometryutility_IsMaximumAbsoluteComponentNearOne(const float* pVec, float fTol);
int __cdecl S00d5ad90_Wrap(const float* pVec, float fTol);
struct S00d5c060_Src
{
    char* m_pData;
    int m_uiItemCount;
    int m_iElementIndex;
};
struct __declspec(align(16)) S00d5c060_Result
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
};
char* __cdecl AllocateWithHeader(D5C110Allocator* alloc, int size);
char* __cdecl hkMemoryRouter_easyFree(D5C110Allocator* owner, char* data);
void __cdecl Hkgeometryutility_ProcessEntries_00d5beb0(S00d5c060_Result* self, char* data, int count, int flags, float scale);
S00d5c060_Result hkGeometryUtility_createMinBoundingSphere(const S00d5c060_Src* src, float scale);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" float _mm_cvtss_f32(__m128);
extern "C" void _mm_store_ss(float*, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_setzero_ps(void);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" __m128 _mm_sqrt_ss(__m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern const float DAT_01012054;
struct MyPoint
{
    __m128 v;
};
// src: GUESS 0x00d5bb10 (confidence: low)
static __declspec(noinline) Vec4* Hkgeometryutilityfull_UpdateState_00d5bb10(Vec4* res, Vec4* p0, Vec4* p1, float t)
{
    res->x = 0.0f;
    Vec4 a = *p0;
    res->y = a.x + t + (float)(int)p1;
    res->w = a.y;
    return res;
}
// src: GUESS 0x00d5bb80 (confidence: low)
static __declspec(noinline) Vec4* Object_ProcessAndReturnValue_00d5bb80(Vec4* res, Vec4* p0, Vec4* p1, Vec4* p2, float t)
{
    res->x = 0.0f;
    Vec4 a = *p0;
    res->y = a.x + t + (float)(int)p1 + (float)(int)p2;
    res->w = a.y;
    return res;
}
// src: GUESS 0x00d5bce0 (confidence: low)
static __declspec(noinline) Vec4* Object_ComputeValue_00d5bce0(Vec4* res, Vec4* p0, Vec4* p1, Vec4* p2, Vec4* p3, float t)
{
    res->x = 0.0f;
    Vec4 a = *p0;
    res->y = a.x + t + (float)(int)p1 + (float)(int)p2 + (float)(int)p3;
    res->w = a.y;
    return res;
}
__m128* __cdecl Hkgeometryutility_ProcessEntries_00d5beb0(__m128* out, MyPoint* pts, int count, int depth, float t);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_mul_ss(__m128, __m128);
extern "C" __m128 _mm_sub_ss(__m128, __m128);
extern "C" __m128 _mm_rsqrt_ss(__m128);
extern "C" __m128 _mm_cmpeq_ss(__m128, __m128);
extern "C" __m128 _mm_andnot_ps(__m128, __m128);
extern "C" __m128 _mm_load_ss(const float*);
class ObbScalar
{
    __m128 val;

  public:
    __forceinline ObbScalar(__m128 x) : val(x)
    {}
    __forceinline ObbScalar(float x) : val(_mm_load_ss(&x))
    {}
    __forceinline __m128 splat() const
    {
        return _mm_shuffle_ps(val, val, 0);
    }
    __forceinline __m128 quad() const
    {
        return val;
    }
    __forceinline operator float() const
    {
        float x;
        _mm_store_ss(&x, val);
        return x;
    }
};
class ObbAxis
{
    __m128 val;

  public:
    __forceinline ObbAxis()
    {}
    __forceinline ObbAxis(const ObbAxis& a) : val(a.val)
    {}
    __forceinline void operator=(const ObbAxis& a)
    {
        val = a.val;
    }
    __forceinline float& operator()(int i)
    {
        return reinterpret_cast<float*>(&val)[i];
    }
    __forceinline const float& operator()(int i) const
    {
        return reinterpret_cast<const float*>(&val)[i];
    }
    __forceinline void addScaled(const ObbScalar& s, const ObbAxis& a)
    {
        val = _mm_add_ps(val, _mm_mul_ps(s.splat(), a.val));
    }
    __forceinline void subtractScaled(const ObbScalar& s, const ObbAxis& a)
    {
        val = _mm_sub_ps(val, _mm_mul_ps(s.splat(), a.val));
    }
    __forceinline ObbScalar dot(const ObbAxis& a) const
    {
        __m128 p = _mm_mul_ps(val, a.val);
        __m128 s = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), s);
    }
    __forceinline void cross(const ObbAxis& a, const ObbAxis& b)
    {
        __m128 u = _mm_mul_ps(_mm_shuffle_ps(a.val, a.val, 0xc9), _mm_shuffle_ps(b.val, b.val, 0xd2));
        __m128 v = _mm_mul_ps(_mm_shuffle_ps(a.val, a.val, 0xd2), _mm_shuffle_ps(b.val, b.val, 0xc9));
        val = _mm_sub_ps(u, v);
    }
    __forceinline void normalize()
    {
        __m128 half = _mm_load_ss(&kHalf), three = _mm_load_ss(&kThree), zero = _mm_load_ss(&kZero);
        __m128 d = dot(*this).quad();
        __m128 mask = _mm_cmpeq_ss(d, zero);
        __m128 r = _mm_rsqrt_ss(d);
        __m128 q = _mm_mul_ss(_mm_mul_ss(half, r), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(d, r), r)));
        __m128 inv = _mm_andnot_ps(mask, q);
        val = _mm_mul_ps(_mm_shuffle_ps(inv, inv, 0), val);
    }
    static const float kHalf, kThree, kZero;
};
const float ObbAxis::kHalf = 0.5f, ObbAxis::kThree = 3.0f, ObbAxis::kZero = 0.0f;
struct ObbWord
{
    int v;
    ObbWord(int x) : v(x)
    {}
    operator int() const
    {
        return v;
    }
};
extern "C" int obbMix(int);
// src: GUESS 0x00d5ae60 (confidence: low)
static __declspec(noinline) void Object_ProcessEntries_00d5ae60(const float* verts, int count, int stride, ObbWord ext,
                                              const ObbAxis* axes, ObbWord pos)
{
    int triangles = count / 3;
    const float* p = verts;
    const float* end = p + triangles * 4;
    float sum = 0.0f;
    while (p != end)
    {
        sum += p[0] + axes[0](0);
        p += 4;
    }
    int total = obbMix(triangles) + triangles;
    ((ObbAxis*)ext.v)->operator()(0) = sum + axes[1](0) + (float)total;
    ((ObbAxis*)pos.v)->operator()(0) = (float)stride;
}
// src: GUESS 0x00d5b0c0 (confidence: low)
static __declspec(noinline) float Object_ProcessAndReturnValue_00d5b0c0(const float* verts, int count, int stride, const ObbAxis* axes)
{
    ObbAxis tmp[3];
    tmp[0] = axes[0];
    tmp[1] = axes[1];
    tmp[0].normalize();
    float projection = axes[0].dot(axes[1]);
    tmp[1].subtractScaled(projection, axes[0]);
    tmp[1].normalize();
    tmp[2].cross(axes[0], axes[1]);
    tmp[2].normalize();
    ObbAxis position, extents;
    Object_ProcessEntries_00d5ae60(verts, count, stride, ObbWord((int)&extents), tmp, ObbWord((int)&position));
    return extents(1) * extents(0) * extents(2);
}
// src: GUESS 0x00d5b440 (confidence: low)
static __declspec(noinline) void Object_ProcessEntries_00d5b440(const ObbAxis* axes, ObbAxis* direction, float step, ObbAxis* out)
{
    for (int i = 0; i < 2; ++i)
    {
        out[i] = axes[i];
        out[i].addScaled(step, direction[i]);
    }
    out[0].normalize();
    float projection = out[0].dot(out[1]);
    out[1].subtractScaled(projection, out[0]);
    out[1].normalize();
    out[2].cross(out[0], out[1]);
    out[2].normalize();
}
inline float obbRoot(float f)
{
    return (float)sqrt((double)f);
}
static float Object_ProcessEntries_00d5b640(const float* vertexArray, int numVertices, int striding, const ObbAxis* axes, float stepIn,
                          ObbAxis* direction, int maxIter);
const float* volatile obbVerts;
const ObbAxis* volatile obbAxes;
ObbAxis* volatile obbDir;
volatile int obbCount, obbStride, obbIter;
volatile float obbStep, obbAnswer;
void obbCaller();
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ss(__m128, __m128);
extern "C" __m128 _mm_sub_ss(__m128, __m128);
extern "C" __m128 _mm_rsqrt_ss(__m128);
extern "C" __m128 _mm_load_ss(const float*);
extern "C" __m128 _mm_cmpeq_ss(__m128, __m128);
extern "C" __m128 _mm_andnot_ps(__m128, __m128);
extern "C" __m128 _mm_set_ss(float);
extern const float DAT_010d1018 = 0.0000011920928955078125f;
struct S4
{
    int v;
    S4(int x) : v(x)
    {}
};
class AxisScalar
{
    __m128 value;

  public:
    AxisScalar(__m128 q) : value(q)
    {}
    AxisScalar(float f) : value(_mm_load_ss(&f))
    {}
    __forceinline __m128 quad() const
    {
        return value;
    }
    __forceinline __m128 splat() const
    {
        return _mm_shuffle_ps(value, value, 0);
    }
    operator float() const
    {
        float f;
        _mm_store_ss(&f, value);
        return f;
    }
};
class Axis
{
    __m128 value;

  public:
    void operator=(const Axis& other)
    {
        value = other.value;
    }
    __forceinline float& operator()(int i)
    {
        return reinterpret_cast<float*>(&value)[i];
    }
    __forceinline const float& operator()(int i) const
    {
        return reinterpret_cast<const float*>(&value)[i];
    }
    __forceinline void set(float x, float y, float z, float w)
    {
        value = _mm_setr_ps(x, y, z, w);
    }
    __forceinline void SetAllComponents(float f)
    {
        AxisScalar s(f);
        value = s.splat();
    }
    __forceinline void mul4(const AxisScalar& s)
    {
        value = _mm_mul_ps(value, s.splat());
    }
    __forceinline void setMul4(const AxisScalar& s, const Axis& v)
    {
        value = _mm_mul_ps(s.splat(), v.value);
    }
    __forceinline void addMul4(const AxisScalar& s, const Axis& v)
    {
        value = _mm_add_ps(value, _mm_mul_ps(s.splat(), v.value));
    }
    __forceinline void subMul4(const AxisScalar& s, const Axis& v)
    {
        value = _mm_sub_ps(value, _mm_mul_ps(s.splat(), v.value));
    }
    __forceinline void setAdd4(const Axis& a, const Axis& b)
    {
        value = _mm_add_ps(a.value, b.value);
    }
    __forceinline void setSub4(const Axis& a, const Axis& b)
    {
        value = _mm_sub_ps(a.value, b.value);
    }
    __forceinline void setCross(const Axis& a, const Axis& b)
    {
        __m128 left = _mm_mul_ps(_mm_shuffle_ps(a.value, a.value, 0xc9), _mm_shuffle_ps(b.value, b.value, 0xd2));
        __m128 right = _mm_mul_ps(_mm_shuffle_ps(a.value, a.value, 0xd2), _mm_shuffle_ps(b.value, b.value, 0xc9));
        value = _mm_sub_ps(left, right);
    }
    __forceinline AxisScalar dot3(const Axis& v) const
    {
        __m128 product = _mm_mul_ps(value, v.value);
        __m128 sum = _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);
        return _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), sum);
    }
    __forceinline AxisScalar lengthSquared3() const
    {
        return dot3(*this);
    }
    __forceinline AxisScalar lengthInverse3() const
    {
        const __m128 h = _mm_set_ss(0.5f);
        const __m128 t = _mm_set_ss(3.0f);
        const __m128 z = _mm_set_ss(0.0f);
        __m128 square = dot3(*this).quad();
        __m128 mask = _mm_cmpeq_ss(square, z);
        __m128 inv = _mm_rsqrt_ss(square);
        __m128 correction = _mm_mul_ss(_mm_mul_ss(h, inv), _mm_sub_ss(t, _mm_mul_ss(_mm_mul_ss(square, inv), inv)));
        return _mm_andnot_ps(mask, correction);
    }
    __forceinline void normalize3()
    {
        __m128 scale = lengthInverse3().splat();
        value = _mm_mul_ps(scale, value);
    }
};
__forceinline float axisSqrt(float f)
{
    AxisScalar s(f);
    return AxisScalar(_mm_sqrt_ss(s.quad()));
}
__forceinline float axisInvSqrt(float f)
{
    return 1.0f / axisSqrt(f);
}
// src: GUESS 0x00d5ae60 (confidence: low)
static __declspec(noinline) void Object_ProcessEntries_00d5ae60(const float* data, int count, int stride, Axis& size, const Axis* axes,
                                              Axis& center)
{
    Axis lower;
    lower.SetAllComponents(3.40282e38f);
    Axis upper;
    upper.SetAllComponents(-3.40282e38f);
    const float* vertex = data;
    for (int tri = 0; tri < count / 3; ++tri)
    {
        Axis point;
        point.set(vertex[0], vertex[1], vertex[2], 0.0f);
        vertex = (const float*)((const char*)vertex + stride);
        for (int axis = 0; axis < 3; ++axis)
        {
            float projected = axes[axis].dot3(point);
            if (projected < lower(axis))
                lower(axis) = projected;
            if (projected > upper(axis))
                upper(axis) = projected;
        }
        point.set(vertex[0], vertex[1], vertex[2], 0.0f);
        vertex = (const float*)((const char*)vertex + stride);
        for (int axis = 0; axis < 3; ++axis)
        {
            float projected = axes[axis].dot3(point);
            if (projected < lower(axis))
                lower(axis) = projected;
            if (projected > upper(axis))
                upper(axis) = projected;
        }
        point.set(vertex[0], vertex[1], vertex[2], 0.0f);
        vertex = (const float*)((const char*)vertex + stride);
        for (int axis = 0; axis < 3; ++axis)
        {
            float projected = axes[axis].dot3(point);
            if (projected < lower(axis))
                lower(axis) = projected;
            if (projected > upper(axis))
                upper(axis) = projected;
        }
    }
    Axis midpoint;
    midpoint.setAdd4(upper, lower);
    midpoint.mul4(0.5f);
    size.setSub4(upper, lower);
    size.mul4(0.5f);
    center.setMul4(midpoint(0), axes[0]);
    center.addMul4(midpoint(1), axes[1]);
    center.addMul4(midpoint(2), axes[2]);
}
// src: GUESS 0x00d5b0c0 (confidence: low)
static __declspec(noinline) float Object_ProcessAndReturnValue_00d5b0c0(const float* data, int count, int stride, const Axis* axes)
{
    Axis adjusted[3];
    adjusted[0] = axes[0];
    adjusted[1] = axes[1];
    adjusted[0].normalize3();
    float projection = axes[0].dot3(axes[1]);
    adjusted[1].subMul4(projection, axes[0]);
    adjusted[1].normalize3();
    adjusted[2].setCross(axes[0], axes[1]);
    adjusted[2].normalize3();
    Axis center;
    Axis size;
    Object_ProcessEntries_00d5ae60(data, count, stride, size, adjusted, center);
    return size(0) * size(1) * size(2);
}
// src: GUESS 0x00d5b2a0 (confidence: low)
static __declspec(noinline) void Object_ProcessEntries_00d5b2a0(const float* data, int count, int stride, const Axis* axes, float delta,
                                              Axis* direction)
{
    Axis changed[3];
    changed[0] = axes[0];
    changed[1] = axes[1];
    float base = Object_ProcessAndReturnValue_00d5b0c0(data, count, stride, axes);
    float invDelta = 1 / delta;
    for (int row = 0; row < 2; ++row)
    {
        for (int col = 0; col < 3; ++col)
        {
            changed[row](col) += delta;
            float volume = Object_ProcessAndReturnValue_00d5b0c0(data, count, stride, changed);
            direction[row](col) = (volume - base) * invDelta;
            changed[row](col) = axes[row](col);
        }
        direction[row].mul4(-1.0f);
    }
    float normSquared = direction[0].lengthSquared3() + direction[1].lengthSquared3();
    if (normSquared > 1.0)
    {
        float invNorm = axisInvSqrt(normSquared);
        direction[0].mul4(invNorm);
        direction[1].mul4(invNorm);
    }
}
// src: GUESS 0x00d5b440 (confidence: low)
static __declspec(noinline) void Object_ProcessEntries_00d5b440(const Axis* input, Axis* direction, float step, Axis* output)
{
    for (int axis = 0; axis < 2; ++axis)
    {
        output[axis] = input[axis];
        output[axis].addMul4(step, direction[axis]);
    }
    output[0].normalize3();
    float projection = output[0].dot3(output[1]);
    output[1].subMul4(projection, output[0]);
    output[1].normalize3();
    output[2].setCross(output[0], output[1]);
    output[2].normalize3();
}
// src: GUESS 0x00d5b640 (confidence: low)
static __declspec(noinline) float Object_ProcessEntries_00d5b640(const float* data, int count, int stride, const Axis* axes, float start,
                                               Axis* direction, int limit)
{
    float fb = 0, fc = 0;
    float a = 0;
    float fa = Object_ProcessAndReturnValue_00d5b0c0(data, count, stride, axes);
    Axis changed[3];
    Object_ProcessEntries_00d5b440(axes, direction, start, changed);
    float trial = Object_ProcessAndReturnValue_00d5b0c0(data, count, stride, changed);
    float b, c;
    if (fa > trial)
    {
        b = start;
        fb = trial;
        c = b;
        for (int iter = 0; iter < limit; ++iter)
        {
            c *= 1.2f;
            Object_ProcessEntries_00d5b440(axes, direction, c, changed);
            fc = Object_ProcessAndReturnValue_00d5b0c0(data, count, stride, changed);
            if (fc > fb)
                break;
            else
            {
                b = c;
                fb = fc;
            }
            if (iter == limit - 1)
                return c;
        }
    }
    else
    {
        c = start;
        fc = trial;
        b = c;
        for (int iter = 0; iter < limit; ++iter)
        {
            b = (a + b) * 0.5;
            Object_ProcessEntries_00d5b440(axes, direction, b, changed);
            fb = Object_ProcessAndReturnValue_00d5b0c0(data, count, stride, changed);
            if (fa > fb && fc > fb)
                break;
            if (iter == limit - 1)
                return -1.0f;
        }
    }
    if (!(a <= b && b <= c && fb <= fa && fb <= fc))
        return -1.0f;
    const float golden = (3.0 - axisSqrt(5.0f)) * 0.5;
    for (int iter = 0; iter < limit; ++iter)
    {
        float ab = b - a;
        float bc = c - b;
        float x, fx;
        if (bc < ab)
        {
            x = b - golden * ab;
            Object_ProcessEntries_00d5b440(axes, direction, x, changed);
            fx = Object_ProcessAndReturnValue_00d5b0c0(data, count, stride, changed);
            if (fb > fx)
            {
                c = b;
                fc = fb;
                b = x;
                fb = fx;
            }
            else
            {
                a = x;
                fa = fx;
            }
        }
        else
        {
            x = b + golden * bc;
            Object_ProcessEntries_00d5b440(axes, direction, x, changed);
            fx = Object_ProcessAndReturnValue_00d5b0c0(data, count, stride, changed);
            if (fb > fx)
            {
                a = b;
                fa = fb;
                b = x;
                fb = fx;
            }
            else
            {
                c = x;
                fc = fx;
            }
        }
    }
    return b;
}
static float Hkgeometryutility_UpdateState_00d5b990(const float* data, int count, int stride, const Axis* initial, Axis* result, int limit);
const float* volatile probeData;
int volatile probeCount, probeStride, probeLimit;
Axis* volatile probeAxes;
Axis* volatile probeOutput;
volatile float probeSink;
void runProbe();

extern "C" double sqrt(double);

extern "C"
{

    __m128 _mm_mul_ps(__m128, __m128);

    __m128 _mm_add_ps(__m128, __m128);

    __m128 _mm_sub_ps(__m128, __m128);

    __m128 _mm_add_ss(__m128, __m128);

    __m128 _mm_sub_ss(__m128, __m128);

    __m128 _mm_mul_ss(__m128, __m128);

    __m128 _mm_load_ps(const float*);

    __m128 _mm_rsqrt_ss(__m128);

    __m128 _mm_set_ss(float);

    __m128 _mm_set_ps1(float);

    __m128 _mm_cmpeq_ss(__m128, __m128);

    __m128 _mm_andnot_ps(__m128, __m128);

    __m128 _mm_load_ss(const float*);

    __m128 _mm_set_ps(float, float, float, float);

    float _mm_cvtss_f32(__m128);

    void _mm_store_ss(float*, __m128);
}

extern "C" void _ReadWriteBarrier();

struct BoundsVector
{

    union
    {

        __m128 packed;

        float component[4];
    };
};

extern const float DAT_01016248;

extern float DAT_01011d78;

extern const float DAT_01017718;

extern const float DAT_010d1014;

extern const float DAT_010d1010;

static __forceinline __m128 DotThree(__m128 left, __m128 right)
{

    __m128 product = _mm_mul_ps(left, right);

    __m128 sum = _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);

    return _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), sum);
}

template <bool Initialize>

static __forceinline void NormalizeThree(BoundsVector& output, __m128 value, __m128& zero, __m128& three, __m128& half)
{

    __m128 length = DotThree(value, value);

    __m128 reciprocal = _mm_rsqrt_ss(length);

    if (Initialize)
    {

        zero = _mm_set_ss(DAT_01011d78);

        three = _mm_set_ss(DAT_01017718);

        half = _mm_set_ss(DAT_01016248);
    }

    __m128 correction = _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(length, reciprocal), reciprocal));

    __m128 scale = _mm_mul_ss(_mm_mul_ss(half, reciprocal), correction);

    scale = _mm_andnot_ps(_mm_cmpeq_ss(length, zero), scale);

    output.packed = _mm_mul_ps(_mm_shuffle_ps(scale, scale, 0), value);
}

static __forceinline void IncludeBoundsPoint(const BoundsVector* axes, const char*& vertices, int stride,

                                             BoundsVector& minimum, BoundsVector& maximum)
{

    const float* point = reinterpret_cast<const float*>(vertices);

    __m128 packed = _mm_set_ps(DAT_01011d78, point[2], point[1], point[0]);

    vertices += stride;

    for (int axis = 0; axis < 3; ++axis)
    {

        float projection = _mm_cvtss_f32(DotThree(axes[axis].packed, packed));

        if (minimum.component[axis] > projection)
            minimum.component[axis] = projection;

        if (maximum.component[axis] < projection)
            maximum.component[axis] = projection;
    }
}

// src: GUESS 0x00d5ae60 (confidence: low)
static __declspec(noinline) void Object_ProcessEntries_00d5ae60(const BoundsVector* axes, const char* vertices, int count, int stride,

                                              BoundsVector* halfExtents, BoundsVector* center)
{

    BoundsVector minimum, maximum;

    minimum.packed = _mm_set_ps1(DAT_010d1014);

    maximum.packed = _mm_set_ps1(DAT_010d1010);

    volatile int triangles = count / 3;

    if (triangles > 0)
        do
        {

            IncludeBoundsPoint(axes, vertices, stride, minimum, maximum);

            IncludeBoundsPoint(axes, vertices, stride, minimum, maximum);

            IncludeBoundsPoint(axes, vertices, stride, minimum, maximum);

        } while (--triangles);

    __m128 widths = _mm_sub_ps(maximum.packed, minimum.packed);

    halfExtents->packed = widths;

    __m128 middle = _mm_mul_ps(_mm_set_ps1(DAT_01016248), _mm_add_ps(maximum.packed, minimum.packed));

    halfExtents->packed = _mm_mul_ps(_mm_set_ps1(DAT_01016248), widths);

    center->packed = _mm_mul_ps(_mm_shuffle_ps(middle, middle, 0), axes[0].packed);

    center->packed = _mm_add_ps(center->packed, _mm_mul_ps(_mm_shuffle_ps(middle, middle, 0x55), axes[1].packed));

    center->packed = _mm_add_ps(center->packed, _mm_mul_ps(_mm_shuffle_ps(middle, middle, 0xaa), axes[2].packed));
}

// src: GUESS 0x00d5b0c0 (confidence: low)
static __declspec(noinline) float Object_ProcessAndReturnValue_00d5b0c0(const BoundsVector* input, int stride, const char* vertices, int count)
{

    // The zero comparison mask is dead when the bounds helper writes the extents.

    BoundsVector axes[3], halfExtents, center;

    __m128 first = input[0].packed;

    __m128 half, three;

    __m128 second = input[1].packed;

    NormalizeThree<true>(axes[0], first, halfExtents.packed, three, half);

    float projection = _mm_cvtss_f32(DotThree(second, first));

    second =
        _mm_sub_ps(second, _mm_mul_ps(_mm_shuffle_ps(_mm_load_ss(&projection), _mm_load_ss(&projection), 0), first));

    // Keep the projection work ahead of the next normalization.

    _ReadWriteBarrier();

    NormalizeThree<false>(axes[1], second, halfExtents.packed, three, half);

    _ReadWriteBarrier();

    __m128 sourceSecond = input[1].packed;

    __m128 cross = _mm_sub_ps(

        _mm_mul_ps(_mm_shuffle_ps(sourceSecond, sourceSecond, 0xd2), _mm_shuffle_ps(first, first, 0xc9)),

        _mm_mul_ps(_mm_shuffle_ps(sourceSecond, sourceSecond, 0xc9), _mm_shuffle_ps(first, first, 0xd2)));

    NormalizeThree<false>(axes[2], cross, halfExtents.packed, three, half);

    Object_ProcessEntries_00d5ae60(axes, vertices, count, stride, &halfExtents, &center);

    return halfExtents.component[0] * halfExtents.component[1] * halfExtents.component[2];
}

static __forceinline __m128 SplatScalar(float value)
{

    __m128 scalar = _mm_load_ss(&value);

    return _mm_shuffle_ps(scalar, scalar, 0);
}

static __forceinline __m128 LengthSquared3(__m128 v)
{

    __m128 sq = _mm_mul_ps(v, v);

    return _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq));
}


__forceinline hkSimdReal::hkSimdReal(const __m128& x) : m_vValue(x)
{}

__forceinline hkSimdReal::operator float() const
{
    float s;
    _mm_store_ss(&s, m_vValue);
    return s;
}

template <typename T>
__forceinline hkSimdReal hkSimdReal::operator+(const T& value) const
{
    return _mm_add_ss(m_vValue, value.m_vValue);
}

__forceinline hkSimdReal hkVector4::lengthSquared3() const
{
    return LengthSquared3(m_vComponents);
}

__forceinline void hkVector4::mul4(const float& s)
{
    m_vComponents = _mm_mul_ps(SplatScalar(s), m_vComponents);
}

// @fnv 0x00d5b2a0
// src: GUESS 0x00d5b2a0 (confidence: low)
static __declspec(noinline) void Object_ProcessEntries_00d5b2a0(int a1, int a2, int a3, float d, int outI, const float* p)

{

    __declspec(align(16)) Vec4 columns[3];

    float* tmp = columns[0].elements;

    *(__m128*)&tmp[0] = _mm_load_ps(p);

    *(__m128*)&tmp[4] = _mm_load_ps(p + 4);

    float first = Object_ProcessAndReturnValue_00d5b0c0((const BoundsVector*)p, a3, (const char*)a1, a2);

    float invD = 1.0f / d;

    float* out = (float*)outI;

    for (int i = 0; i < 2; i++)

    {

        for (int k = 0; k < 3; k++)

        {

            columns[i].elements[k] = d + columns[i].elements[k];

            out[i * 4 + k] = (Object_ProcessAndReturnValue_00d5b0c0((const BoundsVector*)tmp, a3, (const char*)a1, a2) - first) * invD;

            columns[i].elements[k] = p[i * 4 + k];
        }

        __m128 sc = _mm_load_ss(&DAT_01012054);
        sc = _mm_shuffle_ps(sc, sc, 0);

        *(__m128*)&out[i * 4] = _mm_mul_ps(sc, *(__m128*)&out[i * 4]);
    }

    {

        hkVector4* o = (hkVector4*)out;

        const float len2 = o[0].lengthSquared3() + o[1].lengthSquared3();

        if (len2 > 1.0f)

        {

            float invv = 1.0f / (float)sqrt(len2);

            o[0].mul4(invv);

            o[1].mul4(invv);
        }
    }
}

extern volatile int volumeVertexCount;

extern volatile int volumeVertexStride;

extern volatile float volumeStep;

extern const char* volatile volumeVertices;

extern float* volatile volumeGradient;

extern const float* volatile volumeDirections;

extern volatile float volumeValue;

void EvaluateVolumeGradient()
{

    Object_ProcessEntries_00d5b2a0((int)volumeVertices, volumeVertexCount, volumeVertexStride,

                 volumeStep, (int)volumeGradient, volumeDirections);
}

void EvaluateVolume()
{

    volumeValue = Object_ProcessAndReturnValue_00d5b0c0((const BoundsVector*)volumeDirections, volumeVertexStride,

                               volumeVertices, volumeVertexCount);
}
