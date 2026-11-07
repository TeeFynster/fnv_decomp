// src/havok/common/internal/convexhull/hkgeometryutility_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/common/internal/convexhull/hkgeometryutility.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/common/internal/convexhull/hkgeometryutility.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/convexhull/hkgeometryutility.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#ifndef _INCLUDED_MM2
// Exe 0x00d5b0c0 FUN_00d5b0c0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
#endif
#define FNV_VEC4_NO_SSE
#define FNV_VEC4_SIMD
#include "../../../../../include/Vec4.h"
#include "../../../../../include/hkMemoryRouter.h"
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
extern "C" hkMemoryRouter& __cdecl hkMemoryRouter_getInstance();
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
        D5C110Allocator& alloc = *reinterpret_cast<D5C110Allocator*>(hkMemoryRouter_getInstance().m_heap);
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
extern "C" LocalM128 _mm_setr_ps(float, float, float, float);
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
struct S00d5c060_Vec3
{
    float m_uiX;
    float m_uiY;
    float m_uiZ;
    unsigned int unk0C;
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
extern "C" LocalM128 _mm_add_ss(LocalM128, LocalM128);
extern "C" float _mm_cvtss_f32(LocalM128);
extern "C" void _mm_store_ss(float*, LocalM128);
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_setzero_ps(void);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
extern "C" LocalM128 _mm_sqrt_ss(LocalM128);
extern "C" LocalM128 _mm_sub_ps(LocalM128, LocalM128);
extern const float DAT_01012054;
struct MyPoint
{
    LocalM128 v;
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
LocalM128* __cdecl Hkgeometryutility_ProcessEntries_00d5beb0(LocalM128* out, MyPoint* pts, int count, int depth, float t);
extern "C" LocalM128 _mm_add_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_sub_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_add_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_mul_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_sub_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_rsqrt_ss(LocalM128);
extern "C" LocalM128 _mm_cmpeq_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_andnot_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_load_ss(const float*);
class ObbScalar
{
    LocalM128 val;

  public:
    __forceinline ObbScalar(LocalM128 x) : val(x)
    {}
    __forceinline ObbScalar(float x) : val(_mm_load_ss(&x))
    {}
    __forceinline LocalM128 splat() const
    {
        return _mm_shuffle_ps(val, val, 0);
    }
    __forceinline LocalM128 quad() const
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
    LocalM128 val;

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
        LocalM128 p = _mm_mul_ps(val, a.val);
        LocalM128 s = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), s);
    }
    __forceinline void cross(const ObbAxis& a, const ObbAxis& b)
    {
        LocalM128 u = _mm_mul_ps(_mm_shuffle_ps(a.val, a.val, 0xc9), _mm_shuffle_ps(b.val, b.val, 0xd2));
        LocalM128 v = _mm_mul_ps(_mm_shuffle_ps(a.val, a.val, 0xd2), _mm_shuffle_ps(b.val, b.val, 0xc9));
        val = _mm_sub_ps(u, v);
    }
    __forceinline void normalize()
    {
        LocalM128 half = _mm_load_ss(&kHalf), three = _mm_load_ss(&kThree), zero = _mm_load_ss(&kZero);
        LocalM128 d = dot(*this).quad();
        LocalM128 mask = _mm_cmpeq_ss(d, zero);
        LocalM128 r = _mm_rsqrt_ss(d);
        LocalM128 q = _mm_mul_ss(_mm_mul_ss(half, r), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(d, r), r)));
        LocalM128 inv = _mm_andnot_ps(mask, q);
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
extern "C" LocalM128 _mm_add_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_sub_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_mul_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_sub_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_rsqrt_ss(LocalM128);
extern "C" LocalM128 _mm_load_ss(const float*);
extern "C" LocalM128 _mm_cmpeq_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_andnot_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_set_ss(float);
extern const float DAT_010d1018 = 0.0000011920928955078125f;
struct S4
{
    int v;
    S4(int x) : v(x)
    {}
};
class AxisScalar
{
    LocalM128 value;

  public:
    AxisScalar(LocalM128 q) : value(q)
    {}
    AxisScalar(float f) : value(_mm_load_ss(&f))
    {}
    __forceinline LocalM128 quad() const
    {
        return value;
    }
    __forceinline LocalM128 splat() const
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
    LocalM128 value;

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
        LocalM128 left = _mm_mul_ps(_mm_shuffle_ps(a.value, a.value, 0xc9), _mm_shuffle_ps(b.value, b.value, 0xd2));
        LocalM128 right = _mm_mul_ps(_mm_shuffle_ps(a.value, a.value, 0xd2), _mm_shuffle_ps(b.value, b.value, 0xc9));
        value = _mm_sub_ps(left, right);
    }
    __forceinline AxisScalar dot3(const Axis& v) const
    {
        LocalM128 product = _mm_mul_ps(value, v.value);
        LocalM128 sum = _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);
        return _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), sum);
    }
    __forceinline AxisScalar lengthSquared3() const
    {
        return dot3(*this);
    }
    __forceinline AxisScalar lengthInverse3() const
    {
        const LocalM128 h = _mm_set_ss(0.5f);
        const LocalM128 t = _mm_set_ss(3.0f);
        const LocalM128 z = _mm_set_ss(0.0f);
        LocalM128 square = dot3(*this).quad();
        LocalM128 mask = _mm_cmpeq_ss(square, z);
        LocalM128 inv = _mm_rsqrt_ss(square);
        LocalM128 correction = _mm_mul_ss(_mm_mul_ss(h, inv), _mm_sub_ss(t, _mm_mul_ss(_mm_mul_ss(square, inv), inv)));
        return _mm_andnot_ps(mask, correction);
    }
    __forceinline void normalize3()
    {
        LocalM128 scale = lengthInverse3().splat();
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

#include <math.h>

namespace BoxGeometrySse {
extern "C"
{

    LocalM128 _mm_and_ps(LocalM128, LocalM128);

    void _mm_store_ps(float*, LocalM128);
}
}

extern const float DAT_010718c0;

extern const double DAT_010d1020;

extern const float DAT_01017718;

extern const float DAT_01016248;

extern float DAT_01013ea4;

extern float DAT_01017d00;

extern const LocalM128 DAT_01017d10;

struct ObbVec
{

    LocalM128 q;

    float x() const
    {
        return q.m128_f32[0];
    }

    float y() const
    {
        return q.m128_f32[1];
    }

    float z() const
    {
        return q.m128_f32[2];
    }

    void setTransformedPos_00c7f640(const void* transform, const ObbVec* v) throw();

    void hkVector4_setRotatedDir(const void* transform, const ObbVec* v) throw();
};

struct ObbRot
{

    ObbVec c0, c1, c2;

    void invert_00cd4f10(float tolerance) throw();
};

struct ObbXf
{

    ObbVec c0, c1, c2, c3;

    void hkTransform_setInverse(const ObbXf* other) throw();
};

struct ObbInput
{
    ObbVec* data;
    int size;
    int cap;
    bool __cdecl getIsBoxGeometry(ObbVec& halfExtents, ObbXf& output, float tolerance) const;
};

struct ObbStride
{
    const ObbVec* data;
    int size;
    int stride;
};

struct ObbAllocator
{

    virtual void unk00();

    virtual void unk04();

    virtual void unk08();

    virtual void* allocate(int& n) throw();

    virtual void free(void* p, int n) throw();
};

namespace FitMemory {

hkMemoryRouter& hkMemoryRouter_getInstance() throw();

inline ObbAllocator& GetHeap(hkMemoryRouter& router)
{
    return *reinterpret_cast<ObbAllocator*>(router.m_heap);
}

}

void __cdecl ResizeAudioStream(void*, void*, int) throw();

ObbVec* __cdecl hlpC(ObbVec* out, const ObbStride*, float) throw();

struct ObbArray
{

    ObbVec* data;
    int size;
    int cap;

    ObbArray() throw() : data(0), size(0), cap(0x80000000)
    {}

    ~ObbArray() throw()
    {

        ObbAllocator& a = FitMemory::GetHeap(FitMemory::hkMemoryRouter_getInstance());

        size = 0;

        if ((cap & 0x80000000) == 0)
            a.free(data, (cap & 0x3fffffff) * 16);

        data = 0;
        cap = 0x80000000;
    }

    void push(const ObbVec& v) throw()
    {

        ObbAllocator& a = FitMemory::GetHeap(FitMemory::hkMemoryRouter_getInstance());

        if (size == (cap & 0x3fffffff))
            ResizeAudioStream(&a, this, 16);

        BoxGeometrySse::_mm_store_ps((float*)&data[size], v.q);

        ++size;
    }
};

struct ObbScratch
{

    ObbVec* data;
    int& cap;

    ObbScratch(int count, int& capacityOut) throw() : cap(capacityOut)
    {

        FitMemory::hkMemoryRouter_getInstance();

        FitMemory::hkMemoryRouter_getInstance();

        ObbAllocator& a = FitMemory::GetHeap(FitMemory::hkMemoryRouter_getInstance());

        if (count > 0)
        {

            int n = count * 16;

            data = (ObbVec*)a.allocate(n);

            int capacity = n / 16;

            if (capacity)
                cap = capacity;

            else
                cap = 0x80000000;
        }
    }

    ~ObbScratch() throw()
    {

        ObbAllocator& a = FitMemory::GetHeap(FitMemory::hkMemoryRouter_getInstance());

        if ((cap & 0x80000000) == 0)
            a.free(data, (cap & 0x3fffffff) * 16);
    }
};

static LocalM128 dot3(LocalM128 a, LocalM128 b)
{

    LocalM128 p = _mm_mul_ps(a, b);

    return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p));
}

static float dotf(LocalM128 a, LocalM128 b)
{
    float f;
    _mm_store_ss(&f, dot3(a, b));
    return f;
}

static LocalM128 normalizeScale(LocalM128 v)
{

    LocalM128 s = dot3(v, v);

    LocalM128 r = _mm_rsqrt_ss(s);

    LocalM128 mask = _mm_cmpeq_ss(s, _mm_load_ss(&DAT_01011d78));

    LocalM128 three = _mm_set_ss(DAT_01017718);

    LocalM128 half = _mm_load_ss(&DAT_01016248);

    return _mm_andnot_ps(mask, _mm_mul_ss(_mm_mul_ss(half, r), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(s, r), r))));
}

// src: HAVOK_LIB 0x00d5ad60
static __declspec(noinline) unsigned char approxEquals(S00d5ad60_cls* self, float* other, float threshold)
{

    float d = *(float*)self - *other;

    d = (float)fabs(d);

    return d < threshold;
}

static __forceinline unsigned char hlpA(const float* a, const float* b, float eps)
{
    return (approxEquals)((S00d5ad60_cls*)a, (float*)b, eps);
}

static __declspec(noinline) bool hlpB(const ObbVec* v, float eps) throw()
{

    float x = (float)fabs(v->x()), y = (float)fabs(v->y()), z = (float)fabs(v->z());

    float m = x > y ? x : y;

    m = m > z ? m : z;

    return (float)fabs(m - 1.0) < eps;
}

// @fnv 0x00d5c6d0
// src: XBOX_PDB 0x00d5c6d0
bool __cdecl ObbInput::getIsBoxGeometry(ObbVec& halfExtents, ObbXf& output, float tolerance) const
{

    const ObbInput& input = *this;

    ObbVec sphere;

    {

        ObbVec temp;

        ObbStride strided;

        strided.size = input.size;

        strided.stride = 16;

        strided.data = input.data;

        sphere.q = hlpC(&temp, &strided, DAT_010718c0)->q;
    }

    int scratchCapacity;

    ObbScratch scratch(8, scratchCapacity);

    ObbArray selected;

    int count = input.size;

    for (int i = 0; i < count; i++)
    {

        LocalM128 diff = _mm_sub_ps(input.data[i].q, sphere.q);

        float distance;

        _mm_store_ss(&distance, _mm_sqrt_ss(dot3(diff, diff)));

        float error = distance - sphere.q.m128_f32[3];

        error = (float)fabs(error);

        if (error < tolerance)
            selected.push(input.data[i]);
    }

    if (selected.size != 8)
        return false;

    for (int i = 0; i < 8; i++)
        scratch.data[i].q = selected.data[i].q;

    ObbVec a;

    {
        ObbVec x = scratch.data[0];
        ObbVec y = scratch.data[1];
        a.q = _mm_sub_ps(x.q, y.q);
    }

    ObbVec b;

    {
        ObbVec x = scratch.data[0];
        ObbVec y = scratch.data[2];
        b.q = _mm_sub_ps(x.q, y.q);
    }

    for (int i = 3; i < 8; i++)
    {

        ObbVec d = scratch.data[0];

        d.q = _mm_sub_ps(d.q, scratch.data[i].q);

        if (dotf(d.q, d.q) < dotf(a.q, a.q))
        {

            if (dotf(a.q, a.q) < dotf(b.q, b.q))
                b.q = a.q;

            a.q = d.q;
        }
        else if (dotf(d.q, d.q) < dotf(b.q, b.q))
            b.q = d.q;
    }

    float perpendicular;

    _mm_store_ss(&perpendicular, dot3(b.q, a.q));

    if (perpendicular > 0.00001f)
        return false;

    LocalM128 cross = _mm_sub_ps(

        _mm_mul_ps(_mm_shuffle_ps(b.q, b.q, 0xd2), _mm_shuffle_ps(a.q, a.q, 0xc9)),

        _mm_mul_ps(_mm_shuffle_ps(b.q, b.q, 0xc9), _mm_shuffle_ps(a.q, a.q, 0xd2)));

    LocalM128 na = normalizeScale(a.q), nb = normalizeScale(b.q), nc = normalizeScale(cross);

    ObbRot rotation;

    rotation.c0.q = _mm_mul_ps(_mm_shuffle_ps(na, na, 0), a.q);

    rotation.c1.q = _mm_mul_ps(_mm_shuffle_ps(nb, nb, 0), b.q);

    rotation.c2.q = _mm_mul_ps(_mm_shuffle_ps(nc, nc, 0), cross);

    rotation.invert_00cd4f10(DAT_01013ea4);

    ObbVec* vertex = scratch.data;

    for (int i = 0; i < 8; ++i, ++vertex)
        vertex->hkVector4_setRotatedDir(&rotation, vertex);

    float minX = scratch.data[0].x(), maxX = scratch.data[0].x();

    float minY = scratch.data[0].y(), maxY = scratch.data[0].y();

    float minZ = scratch.data[0].z(), maxZ = scratch.data[0].z();

    for (int i = 1; i < 8; i++)
    {

        if (minX > scratch.data[i].x())
            minX = scratch.data[i].x();

        else if (maxX < scratch.data[i].x())
            maxX = scratch.data[i].x();

        if (minY > scratch.data[i].y())
            minY = scratch.data[i].y();

        else if (maxY < scratch.data[i].y())
            maxY = scratch.data[i].y();

        if (minZ > scratch.data[i].z())
            minZ = scratch.data[i].z();

        else if (maxZ < scratch.data[i].z())
            maxZ = scratch.data[i].z();
    }

    for (int i = 0; i < 8; i++)
    {

        if ((!hlpA(&scratch.data[i].q.m128_f32[0], &minX, DAT_01017d00) &&

             !hlpA(&scratch.data[i].q.m128_f32[0], &maxX, DAT_01017d00)) ||

            (!hlpA(&scratch.data[i].q.m128_f32[1], &minY, DAT_01017d00) &&

             !hlpA(&scratch.data[i].q.m128_f32[1], &maxY, DAT_01017d00)) ||

            (!hlpA(&scratch.data[i].q.m128_f32[2], &minZ, DAT_01017d00) &&

             !hlpA(&scratch.data[i].q.m128_f32[2], &maxZ, DAT_01017d00)))
            return false;
    }

    halfExtents.q.m128_f32[0] = maxX - minX;

    halfExtents.q.m128_f32[1] = maxY - minY;

    halfExtents.q.m128_f32[2] = maxZ - minZ;

    LocalM128 h = _mm_load_ss(&DAT_01016248);
    halfExtents.q = _mm_mul_ps(_mm_shuffle_ps(h, h, 0), halfExtents.q);

    float cx = (float)((maxX + minX) * 0.5), cy = (float)((maxY + minY) * 0.5), cz = (float)((maxZ + minZ) * 0.5);

    ObbVec center;

    center.q = _mm_mul_ps(_mm_setr_ps(cx, cy, cz, 0.0f),
                          _mm_shuffle_ps(_mm_load_ss(&DAT_01012054), _mm_load_ss(&DAT_01012054), 0));

    ObbXf inverse;

    inverse.c0.q = rotation.c0.q;

    inverse.c1.q = rotation.c1.q;

    inverse.c2.q = rotation.c2.q;

    inverse.c3 = center;

    output.hkTransform_setInverse(&inverse);

    if (hlpB(&rotation.c0, tolerance) && hlpB(&rotation.c1, tolerance) && hlpB(&rotation.c2, tolerance))
    {

        halfExtents.hkVector4_setRotatedDir(&output, &halfExtents);

        halfExtents.q.m128_f32[3] = 0;

        halfExtents.q = BoxGeometrySse::_mm_and_ps(halfExtents.q, DAT_01017d10);

        rotation.c0.q = _mm_setzero_ps();
        rotation.c0.q.m128_f32[0] = 1;

        rotation.c1.q = _mm_setzero_ps();
        rotation.c1.q.m128_f32[1] = 1;

        rotation.c2.q = _mm_setzero_ps();
        rotation.c2.q.m128_f32[2] = 1;

        output.c0.q = rotation.c0.q;

        output.c1.q = rotation.c1.q;

        output.c2.q = rotation.c2.q;
    }

    inverse.hkTransform_setInverse(&output);

    for (int i = 0; i < input.size; i++)
    {

        ObbVec transformed;

        transformed.setTransformedPos_00c7f640(&inverse, &input.data[i]);

        for (int j = 0; j < 3; j++)
        {

            float d = (float)fabs(transformed.q.m128_f32[j]);

            if (d > halfExtents.q.m128_f32[j] * DAT_010d1020)
                return false;
        }
    }

    return true;
}

extern "C"
{

    LocalM128 _mm_mul_ps(LocalM128, LocalM128);

    LocalM128 _mm_add_ps(LocalM128, LocalM128);

    LocalM128 _mm_sub_ps(LocalM128, LocalM128);

    LocalM128 _mm_add_ss(LocalM128, LocalM128);

    LocalM128 _mm_sub_ss(LocalM128, LocalM128);

    LocalM128 _mm_mul_ss(LocalM128, LocalM128);

    LocalM128 _mm_rsqrt_ss(LocalM128);

    LocalM128 _mm_set_ss(float);

    LocalM128 _mm_set_ps1(float);

    LocalM128 _mm_cmpeq_ss(LocalM128, LocalM128);

    LocalM128 _mm_andnot_ps(LocalM128, LocalM128);

    LocalM128 _mm_load_ss(const float*);

    LocalM128 _mm_set_ps(float, float, float, float);

    float _mm_cvtss_f32(LocalM128);
}

extern "C" LocalM128 _mm_load_ps(const float*);

extern "C" LocalM128 _mm_loadu_ps(const float*);

extern "C" LocalM128 _mm_load1_ps(const float*);

extern "C" void _ReadWriteBarrier();

struct BoundsVector
{

    union
    {

        LocalM128 packed;

        float component[4];
    };
};

extern const float DAT_01016248;

extern float DAT_01011d78;

extern const float DAT_01017718;

extern const float DAT_010d1014;

extern const float DAT_010d1010;

static __forceinline LocalM128 DotThree(LocalM128 left, LocalM128 right)
{

    LocalM128 product = _mm_mul_ps(left, right);

    LocalM128 sum = _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);

    return _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), sum);
}

template <bool Initialize>

static __forceinline void NormalizeThree(BoundsVector& output, LocalM128 value, LocalM128& zero, LocalM128& three, LocalM128& half)
{

    LocalM128 length = DotThree(value, value);

    LocalM128 reciprocal = _mm_rsqrt_ss(length);

    if (Initialize)
    {

        zero = _mm_set_ss(DAT_01011d78);

        three = _mm_set_ss(DAT_01017718);

        half = _mm_set_ss(DAT_01016248);
    }

    LocalM128 correction = _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(length, reciprocal), reciprocal));

    LocalM128 scale = _mm_mul_ss(_mm_mul_ss(half, reciprocal), correction);

    scale = _mm_andnot_ps(_mm_cmpeq_ss(length, zero), scale);

    output.packed = _mm_mul_ps(_mm_shuffle_ps(_mm_load_ps(reinterpret_cast<const float*>(&scale)), scale, 0), value);
}

static __forceinline void IncludeBoundsPoint(const BoundsVector* axes, const char*& vertices, int stride,

                                             BoundsVector& minimum, BoundsVector& maximum)
{

    const float* point = reinterpret_cast<const float*>(vertices);

    LocalM128 packed = _mm_set_ps(DAT_01011d78, point[2], point[1], point[0]);

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

    LocalM128 widths = _mm_sub_ps(maximum.packed, minimum.packed);

    halfExtents->packed = widths;

    LocalM128 middle = _mm_mul_ps(_mm_set_ps1(DAT_01016248), _mm_add_ps(maximum.packed, minimum.packed));

    halfExtents->packed = _mm_mul_ps(_mm_set_ps1(DAT_01016248), widths);

    center->packed = _mm_mul_ps(_mm_shuffle_ps(middle, middle, 0), axes[0].packed);

    center->packed = _mm_add_ps(center->packed, _mm_mul_ps(_mm_shuffle_ps(middle, middle, 0x55), axes[1].packed));

    center->packed = _mm_add_ps(center->packed, _mm_mul_ps(_mm_shuffle_ps(middle, middle, 0xaa), axes[2].packed));
}

// @fnv 0x00d5b0c0
// src: GUESS 0x00d5b0c0 (confidence: low)
static __declspec(noinline) float Object_ProcessAndReturnValue_00d5b0c0(const BoundsVector* input, int stride, const char* vertices, int count)
{

    // The zero comparison mask is dead when the bounds helper writes the extents.

    BoundsVector axes[3], halfExtents, center;

    LocalM128 first = input[0].packed;

    LocalM128 half, three;

    LocalM128 second = input[1].packed;

    NormalizeThree<true>(axes[0], first, halfExtents.packed, three, half);

    float projection = _mm_cvtss_f32(DotThree(second, first));

    second =
        _mm_sub_ps(second, _mm_mul_ps(_mm_shuffle_ps(_mm_load_ss(&projection), _mm_load_ss(&projection), 0), first));

    // Keep the projection work ahead of the next normalization.

    _ReadWriteBarrier();

    NormalizeThree<false>(axes[1], second, halfExtents.packed, three, half);

    _ReadWriteBarrier();

    LocalM128 sourceSecond = input[1].packed;

    LocalM128 cross = _mm_sub_ps(

        _mm_mul_ps(_mm_shuffle_ps(sourceSecond, sourceSecond, 0xd2), _mm_shuffle_ps(first, first, 0xc9)),

        _mm_mul_ps(_mm_shuffle_ps(sourceSecond, sourceSecond, 0xc9), _mm_shuffle_ps(first, first, 0xd2)));

    NormalizeThree<false>(axes[2], cross, halfExtents.packed, three, half);

    Object_ProcessEntries_00d5ae60(axes, vertices, count, stride, &halfExtents, &center);

    return halfExtents.component[0] * halfExtents.component[1] * halfExtents.component[2];
}

float BoundsVolume(const BoundsVector* input, int stride, const char* vertices, int count)
{
    return Object_ProcessAndReturnValue_00d5b0c0(input, stride, vertices, count);
}

class Lane
{
  public:
    Lane(const LocalM128& x) : m_vValue(x)
    {}
    Lane(float x)
    {
        m_vValue = _mm_load_ss(&x);
    }
    __forceinline LocalM128 broadcast() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }
    __forceinline const LocalM128& getQuad() const
    {
        return m_vValue;
    }
    operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }

  private:
    LocalM128 m_vValue;
};

class StepAxis
{
  public:
    StepAxis()
    {}
    StepAxis(const StepAxis& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void operator=(const StepAxis& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void addMul4(const Lane& r, const StepAxis& v)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(r.broadcast(), v.m_vComponents));
    }
    __forceinline void subMul4(const Lane& r, const StepAxis& v)
    {
        m_vComponents = _mm_sub_ps(m_vComponents, _mm_mul_ps(r.broadcast(), v.m_vComponents));
    }
    __forceinline void setCross(const StepAxis& a, const StepAxis& b)
    {
        LocalM128 c0 = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xc9),
                               _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xd2));
        LocalM128 c1 = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xd2),
                               _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(c0, c1);
    }
    __forceinline Lane dot3(const StepAxis& a) const
    {
        LocalM128 p = _mm_mul_ps(m_vComponents, a.m_vComponents);
        LocalM128 xy = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), xy);
    }
    __forceinline Lane lengthInverse3() const
    {
        const LocalM128 half = _mm_set_ss(0.5f);
        const LocalM128 three = _mm_set_ss(3.0f);
        const LocalM128 zero = _mm_set_ss(0.0f);
        const LocalM128 len2 = dot3(*this).getQuad();
        const LocalM128 isZero = _mm_cmpeq_ss(len2, zero);
        const LocalM128 guess = _mm_rsqrt_ss(len2);
        const LocalM128 better =
            _mm_mul_ss(_mm_mul_ss(half, guess), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len2, guess), guess)));
        return _mm_andnot_ps(isZero, better);
    }
    __forceinline void normalize3()
    {
        LocalM128 inv = lengthInverse3().broadcast();
        m_vComponents = _mm_mul_ps(inv, m_vComponents);
    }

  private:
    LocalM128 m_vComponents;
};

// @fnv 0x00d5b440
// src: GUESS 0x00d5b440 (confidence: low)
static __declspec(noinline) void Object_ProcessEntries_00d5b440(const StepAxis* axesIn, StepAxis* direction, float stepLength,
                                              StepAxis* axesOut)
{
    for (int i = 0; i < 2; i++)
    {
        axesOut[i] = axesIn[i];
        axesOut[i].addMul4(stepLength, direction[i]);
    }
    axesOut[0].normalize3();
    float dotProd = axesOut[0].dot3(axesOut[1]);
    axesOut[1].subMul4(dotProd, axesOut[0]);
    axesOut[1].normalize3();
    axesOut[2].setCross(axesOut[0], axesOut[1]);
    axesOut[2].normalize3();
}

StepAxis g_d5b440In0;
StepAxis g_d5b440Dir0;
StepAxis g_d5b440Out0;
float g_d5b440Step;

void d5b440_caller()
{
    Object_ProcessEntries_00d5b440(&g_d5b440In0, &g_d5b440Dir0, g_d5b440Step, &g_d5b440Out0);
}

class Scalar
{
  public:
    Scalar(const LocalM128& x) : m_vValue(x)
    {}
    Scalar(float x)
    {
        m_vValue = _mm_load_ss(&x);
    }
    __forceinline LocalM128 broadcast() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }
    __forceinline const LocalM128& getQuad() const
    {
        return m_vValue;
    }
    operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }

  private:
    LocalM128 m_vValue;
};

// hkVector4 (m_vComponents, Havok 7.1 setSub4/addMul4/setCross/dot3) paired with the local Scalar (hkSimdReal);
// kept local because the shared hkVector4 takes hkSimdReal, not this Scalar. Not the shared x,y,z Point.
class GeomUtilVector4
{
  public:
    GeomUtilVector4()
    {}
    GeomUtilVector4(const GeomUtilVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void operator=(const GeomUtilVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline float& operator()(int i)
    {
        return reinterpret_cast<float*>(&m_vComponents)[i];
    }
    __forceinline const float& operator()(int i) const
    {
        return reinterpret_cast<const float*>(&m_vComponents)[i];
    }
    __forceinline void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    __forceinline void setSub4(const GeomUtilVector4& a, const GeomUtilVector4& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setAdd4(const GeomUtilVector4& a, const GeomUtilVector4& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setMul4(const Scalar& r, const GeomUtilVector4& v)
    {
        m_vComponents = _mm_mul_ps(r.broadcast(), v.m_vComponents);
    }
    __forceinline void addMul4(const Scalar& r, const GeomUtilVector4& v)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(r.broadcast(), v.m_vComponents));
    }
    __forceinline void setCross(const GeomUtilVector4& a, const GeomUtilVector4& b)
    {
        LocalM128 c0 = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xc9),
                               _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xd2));
        LocalM128 c1 = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xd2),
                               _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(c0, c1);
    }
    __forceinline Scalar dot3(const GeomUtilVector4& a) const
    {
        LocalM128 p = _mm_mul_ps(m_vComponents, a.m_vComponents);
        LocalM128 xy = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), xy);
    }
    __forceinline Scalar lengthSquared3() const
    {
        return dot3(*this);
    }
    __forceinline Scalar length3() const
    {
        return _mm_sqrt_ss(dot3(*this).getQuad());
    }

  private:
    LocalM128 m_vComponents;
};

class Ball
{
  public:
    inline Ball(const GeomUtilVector4& pt, float radius)
    {
        m_pos = pt;
        m_pos(3) = radius;
    }
    GeomUtilVector4 m_pos;
};

// @fnv 0x00d5bce0
// src: GUESS 0x00d5bce0 (confidence: low)
static __declspec(noinline) Ball
    Object_ComputeValue_00d5bce0(const GeomUtilVector4& pA, const GeomUtilVector4& pB, const GeomUtilVector4& pC, const GeomUtilVector4& pD, float slack)
{
    GeomUtilVector4 b;
    b.setSub4(pB, pA);
    GeomUtilVector4 c;
    c.setSub4(pC, pA);
    GeomUtilVector4 d;
    d.setSub4(pD, pA);
    float det =
        b(0) * (c(1) * d(2) - c(2) * d(1)) - b(1) * (c(0) * d(2) - c(2) * d(0)) + b(2) * (c(0) * d(1) - c(1) * d(0));
    GeomUtilVector4 acc;
    acc.setZero4();
    GeomUtilVector4 cr;
    cr.setCross(b, c);
    acc.addMul4(d.lengthSquared3(), cr);
    cr.setCross(d, b);
    acc.addMul4(c.lengthSquared3(), cr);
    cr.setCross(c, d);
    acc.addMul4(b.lengthSquared3(), cr);
    float scale = 0.5 / det;
    acc.setMul4(scale, acc);
    GeomUtilVector4 center;
    center.setAdd4(pA, acc);
    float radius = acc.length3();
    return Ball(center, radius + slack);
}

GeomUtilVector4 g_d5bce0P0;
GeomUtilVector4 g_d5bce0P1;
GeomUtilVector4 g_d5bce0P2;
GeomUtilVector4 g_d5bce0P3;
float g_d5bce0Slack;
Ball* g_d5bce0Out;

void d5bce0_caller()
{
    *g_d5bce0Out = Object_ComputeValue_00d5bce0(g_d5bce0P0, g_d5bce0P1, g_d5bce0P2, g_d5bce0P3, g_d5bce0Slack);
}
