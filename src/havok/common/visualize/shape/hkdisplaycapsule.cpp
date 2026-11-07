#define FNV64_HKVECTOR4_PACKET_BODIES
#define FNV64_HKVECTOR4_OWN_CONVERSION
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4
#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4

// src/havok/common/visualize/shape/hkdisplaycapsule.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/shape/hkdisplaycapsule.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/hkBool.h"
// Retain this unit's intrinsic representation when shared headers include xmmintrin.h.
#define _INCLUDED_MM2
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;

#include "../../../../../include/hkVector4.h"
#include "../../../../../include/Vec4.h"
#include "../../../../../include/hkDisplayCapsule.h"

struct StaticHelper
{
    static void HandleObjectEvent(void* a, void* b, float c, void* d, void* e, void* f, void* g);
};

// @fnv 0x00d22d70
// src: HAVOK_LIB 0x00d22d70
void hkDisplayCapsule::buildGeometry()
{
    StaticHelper::HandleObjectEvent((char*)this + 0x60, (char*)this + 0x70, *(float*)((char*)this + 0x80),
                                    *(void**)((char*)this + 0x88), *(void**)((char*)this + 0x84), (char*)this + 0x10,
                                    (char*)this + 0x8);
}

// @fnv 0x00d22db0
// src: COMMUNITY 0x00d22db0
void __stdcall nullsub_74(int, int)
{}

extern "C"
{
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_mul_ss(LocalM128, LocalM128);
    LocalM128 _mm_load_ss(const float*);
    void _mm_store_ss(float*, LocalM128);
    double sqrt(double);
    void _ReadWriteBarrier();
}
extern float DAT_0104da4c;
extern double DAT_01016978;
struct Matrix
{
    hkVector4 c0, c1, c2, c3;
};
struct Other
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34;
    Matrix* transform;
};
struct Limit
{
    hkVector4 axis, origin;
    float slope, positive, negative, scale;
};
static __forceinline LocalM128 dot3ScalarCall(const hkVector4& a, const hkVector4& b)
{
    LocalM128 p = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    LocalM128 xy = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
    return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), xy);
}
static __forceinline LocalM128 broadcast(LocalM128 a)
{
    return _mm_shuffle_ps(a, a, 0);
}
static __forceinline LocalM128 scalar(float a)
{
    return broadcast(_mm_load_ss(&a));
}
static __forceinline float value(LocalM128 a)
{
    float r;
    _mm_store_ss(&r, a);
    return r;
}
static __forceinline void crossProduct(hkVector4& result, const hkVector4& a, const hkVector4& b)
{
    LocalM128 p = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xc9), _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xd2));
    LocalM128 q = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xd2), _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xc9));
    result.m_vComponents = _mm_sub_ps(p, q);
}
// Projects a point onto a Limit cone defined by axis, origin, slope, and positive/negative limits, applying scale and transform constraints.
// @fnv 0x00d234e0
// src: GUESS 0x00d234e0 (confidence: medium)
static __declspec(noinline) void hkVector4_ProjectPointToLimitCone(Limit* apLimit, const hkVector4* point, hkVector4* out, Other* other)
{
    float slope = apLimit->slope;
    float scale = apLimit->scale;
    hkVector4 offset;
    offset.m_vComponents = _mm_sub_ps(point->m_vComponents, apLimit->origin.m_vComponents);
    hkVector4 origin = apLimit->origin;
    hkVector4 axis = apLimit->axis;
    LocalM128 axial = dot3ScalarCall(axis, offset);
    float distance2;
    _mm_store_ss(&distance2, dot3ScalarCall(offset, offset));
    offset.m_vComponents = _mm_sub_ps(offset.m_vComponents, _mm_mul_ps(broadcast(axial), axis.m_vComponents));
    float axial2;
    _mm_store_ss(&axial2, _mm_mul_ss(axial, axial));
    Matrix* transform = other->transform;
    float facing;
    _mm_store_ss(&facing, dot3ScalarCall(transform->c3, offset));
    float limit = facing > 0.0f ? apLimit->positive : apLimit->negative;
    if (limit > 0.0f)
    {
        float side = 0.0f;
        hkVector4 cross;
        crossProduct(cross, transform->c3, axis);
        float cross2;
        _mm_store_ss(&cross2, dot3ScalarCall(cross, cross));
        if (DAT_0104da4c < cross2)
        {
            float len = (float)sqrt(cross2);
            float inv = 1.0f / len;
            cross.m_vComponents = _mm_mul_ps(scalar(inv), cross.m_vComponents);
            side = value(dot3ScalarCall(cross, offset));
            float slope2 = slope * slope;
            float side2 = side * side;
            if (slope2 * axial2 >= side2)
            {
                offset.m_vComponents = _mm_sub_ps(offset.m_vComponents, _mm_mul_ps(scalar(side), cross.m_vComponents));
                side = 0.0f;
            }
        }
        float cone2 = (limit + slope) * (limit + slope);
        float residual2 = distance2 - side * side - axial2;
        if (cone2 * axial2 >= residual2)
        {
            if (side == 0.0f)
            {
                out->m_vComponents = origin.m_vComponents;
                return;
            }
            offset.m_vComponents = _mm_mul_ps(scalar(side), cross.m_vComponents);
        }
    }
    else
    {
        float slope2 = slope * slope;
        if ((slope2 + 1.0) * axial2 >= distance2)
        {
            out->m_vComponents = origin.m_vComponents;
            return;
        }
    }
    if (scale < 1.0f)
    {
        float projected2;
        _mm_store_ss(&projected2, dot3ScalarCall(offset, offset));
        if (DAT_0104da4c <= projected2 && distance2 * DAT_01016978 < projected2)
        {
            float ratio = distance2 / projected2;
            float root = (float)sqrt(ratio);
            float factor = scale + (1.0f - scale) * root;
            offset.m_vComponents = _mm_mul_ps(scalar(factor), offset.m_vComponents);
            LocalM128 component = dot3ScalarCall(axis, offset);
            offset.m_vComponents = _mm_sub_ps(offset.m_vComponents, _mm_mul_ps(broadcast(component), axis.m_vComponents));
        }
    }
    origin.m_vComponents = _mm_add_ps(origin.m_vComponents, offset.m_vComponents);
    out->m_vComponents = origin.m_vComponents;
}
Limit* volatile inputLimit;
const hkVector4* volatile inputPoint;
hkVector4* volatile outputPoint;
Other* volatile inputOther;
void invokeProjection()
{
    hkVector4_ProjectPointToLimitCone(inputLimit, inputPoint, outputPoint, inputOther);
}

extern "C"
{
    LocalM128 _mm_setr_ps(float, float, float, float);
    LocalM128 _mm_and_ps(LocalM128, LocalM128);
    LocalM128 _mm_cmplt_ps(LocalM128, LocalM128);
    int _mm_movemask_ps(LocalM128);
    double fabs(double);
}
static __forceinline float root(float f)
{
    return (float)sqrt(f);
}
static __forceinline float absoluteValue(float f)
{
    return (float)fabs(f);
}
extern float DAT_0104da4c;
extern const LocalM128 DAT_01017d10;
extern const float DAT_01011d78;

static __forceinline LocalM128 scalarParam(float f)
{
    return _mm_load_ss(&f);
}
static __forceinline float scalar(LocalM128 q)
{
    float f;
    _mm_store_ss(&f, q);
    return f;
}

struct Basis
{
    hkVector4 first, second, third;
};
struct Record : Limit
{
    int priority, unk34, unk38, unk3c;
};
struct State
{
    int unk00, unk04, unk08;
    int state;
};
struct Shape : Matrix
{
    int unk40, unk44;
    Record* records;
};
struct Working
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    State* states;
};
struct Context
{
    Other base;
    Working* working;
};
struct ContextArg
{
    Context* p;
};
struct VecArg
{
    hkVector4* p;
    VecArg(hkVector4* v) : p(v)
    {}
};

static __forceinline LocalM128 prefixColumns(Context* context, Record* a, Record* b, const hkVector4& raw, const hkVector4& unit,
                                          const Basis& basis, float inv, hkVector4& base, LocalM128& first, LocalM128& second)
{
    float bDot = scalar(dot3ScalarCall(b->origin, b->axis));
    float aDot = scalar(dot3ScalarCall(a->origin, a->axis));
    hkVector4 centerSum;
    centerSum.m_vComponents = _mm_add_ps(a->origin.m_vComponents, b->origin.m_vComponents);
    float midpointDot = scalar(dot3ScalarCall(centerSum, unit)) * 0.5;
    LocalM128 weights = _mm_setr_ps(midpointDot, aDot, bDot, DAT_01011d78);
    first = _mm_mul_ps(_mm_shuffle_ps(weights, weights, 0), basis.first.m_vComponents);
    second = _mm_mul_ps(_mm_shuffle_ps(weights, weights, 0x55), basis.second.m_vComponents);
    LocalM128 third = _mm_mul_ps(_mm_shuffle_ps(weights, weights, 0xaa), basis.third.m_vComponents);
    return third;
}
// Uses the cross product of a and b's axes to compute a point written to out; if that is degenerate or out of bounds, calls FUN_00d234e0 on both records.
// @fnv 0x00d23850
// src: GUESS 0x00d23850 (confidence: low)
static __declspec(noinline) void hkVector4_ComputeValues_00d23850(Context* context, Record* a, Record* b, VecArg point, hkVector4* out)
{
    float threshold = DAT_0104da4c;
    hkVector4 raw;
    crossProduct(raw, a->axis, b->axis);
    float fLengthSq = scalar(dot3ScalarCall(raw, raw));
    if (threshold >= fLengthSq)
        goto fallback;
    {
        float inv = 1.0f / root(fLengthSq);
        LocalM128 scale = scalarParam(inv);
        hkVector4 unit;
        unit.m_vComponents = _mm_mul_ps(_mm_shuffle_ps(scale, scale, 0), raw.m_vComponents);
        Basis basis;
        basis.first.m_vComponents = raw.m_vComponents;
        crossProduct(basis.second, b->axis, unit);
        crossProduct(basis.third, unit, a->axis);
        hkVector4 base;
        LocalM128 first;
        LocalM128 second;
        LocalM128 third = prefixColumns(context, a, b, raw, unit, basis, inv, base, first, second);
        base.m_vComponents = _mm_mul_ps(_mm_add_ps(_mm_add_ps(first, second), third),
                               _mm_shuffle_ps(scalarParam(inv), scalarParam(inv), 0));
        LocalM128 absolute = _mm_and_ps(base.m_vComponents, DAT_01017d10);
        if (_mm_movemask_ps(_mm_cmplt_ps(context->base.transform->c2.m_vComponents, absolute)) & 7)
            goto fallback;

        hkVector4 delta;
        delta.m_vComponents = _mm_sub_ps(point.p->m_vComponents, base.m_vComponents);
        float distance2 = scalar(dot3ScalarCall(delta, delta));
        float preferred = scalar(dot3ScalarCall(context->base.transform->c3, unit));
        float axial = scalar(dot3ScalarCall(delta, unit));
        float displacement = axial;
        float radius = a->slope + b->slope;
        if (axial * preferred > 0.0)
            radius += preferred * (a->positive + b->positive);
        else
            radius += preferred * (a->negative + b->negative);
        radius = radius * 0.5;
        float blend = (a->scale + b->scale) * 0.5;
        float axial2 = axial * axial;
        if ((distance2 - axial2) * float(radius * radius) >= axial2)
        {
            out->m_vComponents = base.m_vComponents;
            return;
        }
        if (blend < 1.0f && distance2 * DAT_01016978 < axial * axial)
        {
            float invAxial = 1.0f / axial;
            invAxial = absoluteValue(invAxial);
            float ratio = root(distance2);
            ratio = ratio * invAxial;
            ratio = blend + (1.0f - blend) * ratio;
            displacement = ratio * axial;
        }
        out->m_vComponents =
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(_mm_load_ss(&displacement), _mm_load_ss(&displacement), 0), unit.m_vComponents),
                       base.m_vComponents);
        return;
    }
fallback:
    context->working->states[a - static_cast<Shape*>(context->base.transform)->records].state = 2;
    context->working->states[b - static_cast<Shape*>(context->base.transform)->records].state = 2;
    ContextArg ca = {context};
    hkVector4* dst = out;
    hkVector4* src = point.p;
    if (a->priority > b->priority)
    {
        hkVector4_ProjectPointToLimitCone(b, src, dst, &ca.p->base);
        hkVector4_ProjectPointToLimitCone(a, dst, dst, &ca.p->base);
    }
    else
    {
        hkVector4_ProjectPointToLimitCone(a, src, dst, &ca.p->base);
        hkVector4_ProjectPointToLimitCone(b, dst, dst, &ca.p->base);
    }
}

extern Context* volatile testContext;
extern Record* volatile testLeft;
extern Record* volatile testRight;
extern hkVector4* volatile testPoint;
extern hkVector4* volatile testOut;
void invokeGeometry()
{
    VecArg p(testPoint);
    hkVector4_ComputeValues_00d23850(testContext, testLeft, testRight, p, testOut);
}

struct V
{
    union
    {
        LocalM128 v;
        float f[4];
    };
    V()
    {}
    V(const V& r)
    {
        v = r.v;
    }
    void operator=(const V& r)
    {
        v = r.v;
    }
    void cross(const V& a, const V& b);
};
struct CrossBasis
{
    V bc;
    V ca;
    V ab;
    CrossBasis()
    {}
    V& column(int n)
    {
        return (&bc)[n];
    }
    const V& column(int n) const
    {
        return (&bc)[n];
    }
};
struct PlaneMeta
{
    int priority, unk34, unk38, unk3c;
};
struct PlaneRecord
{

    V normal;

    V point;

    LocalM128 auxiliary;

    PlaneMeta metadata;
};

struct PlaneStatus
{
    int unk00;
    int unk04;
    int unk08;
    int marked;
};

struct PlaneGeometry
{

    LocalM128 unk00;

    LocalM128 unk10;

    LocalM128 bounds;

    LocalM128 unk30;

    int unk40;

    int unk44;

    PlaneRecord* planes;
};

struct PlaneStatusStore
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

    PlaneStatus* entries;
};

struct IntersectionContext
{

    int unk00;

    PlaneRecord* first;

    int unk08;
    int unk0c;

    PlaneRecord* second;

    int unk14;
    int unk18;

    PlaneRecord* third;

    int unk20;
    int unk24;
    int unk28;
    int unk2c;

    int count;

    int unk34;

    PlaneGeometry* geometry;

    PlaneStatusStore* status;
};

extern void __cdecl Object_ProcessEntries_00d23380(IntersectionContext* context);

inline void V::cross(const V& a, const V& b)
{

    LocalM128 lhs = _mm_mul_ps(_mm_shuffle_ps(a.v, a.v, 0xc9), _mm_shuffle_ps(b.v, b.v, 0xd2));

    LocalM128 rhs = _mm_mul_ps(_mm_shuffle_ps(a.v, a.v, 0xd2), _mm_shuffle_ps(b.v, b.v, 0xc9));

    v = _mm_sub_ps(lhs, rhs);
}

inline float dot(const LocalM128& a, const LocalM128& b)
{

    LocalM128 p = _mm_mul_ps(a, b);

    LocalM128 xy = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);

    LocalM128 total = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), xy);

    float result;
    _mm_store_ss(&result, total);
    return result;
}

inline LocalM128 distances3(float a, float b, float c)
{
    return _mm_setr_ps(a, b, c, DAT_01011d78);
}

extern void __cdecl hkVector4_ProjectPointToLimitCone(IntersectionContext*, PlaneRecord*, const LocalM128*);

extern const double DAT_01011588 = 0.5;

struct PairPlane
{
    PlaneRecord* p;
};

struct PairRead
{
    const LocalM128* p;
};

struct PairWrite
{
    LocalM128* p;
};

// src: GUESS 0x00d23850 (confidence: low)
static __declspec(noinline) void hkVector4_ComputeValues_00d23850(IntersectionContext* ctx, PairPlane aw, PairPlane bw, PairRead fw,
                                              PairWrite rw)

{

    PlaneRecord* a = aw.p;
    PlaneRecord* b = bw.p;

    const V& na = a->normal;
    const V& nb = b->normal;

    V direction;
    direction.cross(na, nb);

    float squaredLength = dot(direction.v, direction.v);

    if (!(squaredLength < DAT_0104da4c))
    {

        float inverse = 1.0f / root(squaredLength);

        direction.v = _mm_mul_ps(direction.v, scalar(inverse));

        V right, left;
        right.cross(nb, direction);
        left.cross(direction, na);

        float db = dot(b->point.v, nb.v);

        float da = dot(a->point.v, na.v);

        float average = (float)(dot(_mm_add_ps(a->point.v, b->point.v), direction.v) * DAT_01011588);

        LocalM128 distances = distances3(average, db, da);

        LocalM128 sum = _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(distances, distances, 0),
                       _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(nb.v, nb.v, 0xd2), _mm_shuffle_ps(na.v, na.v, 0xc9)),
                                  _mm_mul_ps(_mm_shuffle_ps(nb.v, nb.v, 0xc9), _mm_shuffle_ps(na.v, na.v, 0xd2)))),
            _mm_mul_ps(_mm_shuffle_ps(distances, distances, 0x55), left.v));

        sum = _mm_add_ps(sum, _mm_mul_ps(_mm_shuffle_ps(distances, distances, 0xaa), right.v));

        LocalM128 position = _mm_mul_ps(sum, scalar(inverse));

        if (!(_mm_movemask_ps(_mm_cmplt_ps(ctx->geometry->bounds, _mm_and_ps(position, DAT_01017d10))) & 7))
        {

            LocalM128 difference = _mm_sub_ps(*fw.p, position);

            float squared = dot(difference, difference);

            float radius = dot(ctx->geometry->unk30, direction.v);

            float projection = dot(difference, direction.v);

            float threshold = (float)((a->auxiliary.m128_f32[0] + b->auxiliary.m128_f32[0] +
                                       radius * ((projection * radius > 0.0f)
                                                     ? a->auxiliary.m128_f32[1] + b->auxiliary.m128_f32[1]
                                                     : a->auxiliary.m128_f32[2] + b->auxiliary.m128_f32[2])) *
                                      DAT_01011588);

            float blend = (float)((a->auxiliary.m128_f32[3] + b->auxiliary.m128_f32[3]) * DAT_01011588);

            if ((squared - projection * projection) * threshold * threshold >= projection * projection)
            {
                *rw.p = position;
                return;
            }

            float adjustment = projection;

            if (blend < 1.0f && !(0.001f * squared < projection * projection))

                adjustment = projection * (blend + root(squared) * absoluteValue(1.0f / projection) * (1.0f - blend));

            *rw.p = _mm_add_ps(position, _mm_mul_ps(scalar(adjustment), direction.v));

            return;
        }
    }

    ctx->status->entries[a - ctx->geometry->planes].marked = 2;

    ctx->status->entries[b - ctx->geometry->planes].marked = 2;

    if (a->metadata.priority > b->metadata.priority)
    {

        hkVector4_ProjectPointToLimitCone(ctx, b, fw.p);
        hkVector4_ProjectPointToLimitCone(ctx, a, rw.p);
    }
    else
    {
        hkVector4_ProjectPointToLimitCone(ctx, a, fw.p);
        hkVector4_ProjectPointToLimitCone(ctx, b, rw.p);
    }
}

struct Wrap_b
{
    PlaneRecord* p;
};

struct Wrap_c
{
    PlaneRecord* p;
};

struct Wrap_reorder
{
    int p;
};

struct Wrap_fallback
{
    const LocalM128* p;
};

struct Wrap_result
{
    LocalM128* p;
};

// Computes the intersection point of three planes using a cross-product basis, falling back to sequential pairwise intersection if the determinant is near zero.
// @fnv 0x00d23ca0
// src: GUESS 0x00d23ca0 (confidence: low)
static __declspec(noinline) void Object_ProcessAndReturnValue_00d23ca0(IntersectionContext* ctx, PlaneRecord* apPlaneA, PlaneRecord* apPlaneB,
                                              PlaneRecord* apPlaneC, Wrap_reorder reorder, Wrap_fallback fallback,
                                              Wrap_result result)
{
    V point;
    CrossBasis basis;
    V& bc = basis.column(0);
    V& ca = basis.column(1);
    V& ab = basis.column(2);
    bc.cross(apPlaneB->normal, apPlaneC->normal);
    ca.cross(apPlaneC->normal, apPlaneA->normal);
    ab.cross(apPlaneA->normal, apPlaneB->normal);
    float determinant = dot(bc.v, apPlaneA->normal.v);
    if (absoluteValue(determinant) < 0.00000011920928955078125f)
        goto sequential;
    {
        V weights;
        float dc = dot(apPlaneC->normal.v, apPlaneC->point.v);
        float db = dot(apPlaneB->normal.v, apPlaneB->point.v);
        weights.v = distances3(dot(apPlaneA->normal.v, apPlaneA->point.v), db, dc);
        LocalM128 wx = _mm_shuffle_ps(weights.v, weights.v, 0);
        LocalM128 first = _mm_mul_ps(basis.column(0).v, wx);
        LocalM128 wy = _mm_shuffle_ps(weights.v, weights.v, 0x55);
        LocalM128 second = _mm_mul_ps(basis.column(1).v, wy);
        LocalM128 wz = _mm_shuffle_ps(weights.v, weights.v, 0xaa);
        LocalM128 third = _mm_mul_ps(basis.column(2).v, wz);
        point.v = _mm_add_ps(_mm_add_ps(first, second), third);
        float inverse = 1.0f / determinant;
        point.v = _mm_mul_ps(point.v, _mm_shuffle_ps(_mm_load_ss(&inverse), _mm_load_ss(&inverse), 0));
        V absolute;
        absolute.v = _mm_and_ps(point.v, DAT_01017d10);
        if (_mm_movemask_ps(_mm_cmplt_ps(ctx->geometry->bounds, absolute.v)) & 7)
            goto sequential;
        *result.p = point.v;
        return;
    }
sequential:
    if (reorder.p)
    {
        Object_ProcessEntries_00d23380(ctx);
        apPlaneA = ctx->first;
        apPlaneB = ctx->second;
        apPlaneC = ctx->third;
    }
    ctx->status->entries[apPlaneA - ctx->geometry->planes].marked = 1;
    ctx->status->entries[apPlaneB - ctx->geometry->planes].marked = 1;
    ctx->status->entries[apPlaneC - ctx->geometry->planes].marked = 1;
    int oldCount = ctx->count;
    {
        PairPlane pa = {apPlaneA}, pb = {apPlaneB};
        PairRead pf = {fallback.p};
        PairWrite pr = {result.p};
        hkVector4_ComputeValues_00d23850(ctx, pa, pb, pf, pr);
    }
    if (oldCount == ctx->count)
    {
        PairPlane pa = {apPlaneA}, pc = {apPlaneC};
        PairRead pf = {result.p};
        PairWrite pr = {result.p};
        hkVector4_ComputeValues_00d23850(ctx, pa, pc, pf, pr);
    }
    if (oldCount == ctx->count)
    {
        PairPlane pb = {apPlaneB}, pc = {apPlaneC};
        PairRead pf = {result.p};
        PairWrite pr = {result.p};
        hkVector4_ComputeValues_00d23850(ctx, pb, pc, pf, pr);
    }
}

extern PlaneRecord* volatile feed_a;

extern IntersectionContext* volatile feed_ctx;

extern PlaneRecord* volatile feed_b;

extern PlaneRecord* volatile feed_c;

extern int volatile feed_reorder;

extern const LocalM128* volatile feed_fallback;

extern LocalM128* volatile feed_result;

void emit_intersection()
{
    Wrap_b w_b = {feed_b};

    Wrap_c w_c = {feed_c};

    Wrap_reorder w_reorder = {feed_reorder};

    Wrap_fallback w_fallback = {feed_fallback};

    Wrap_result w_result = {feed_result};

    Object_ProcessAndReturnValue_00d23ca0(feed_ctx, feed_a, w_b.p, w_c.p, w_reorder, w_fallback, w_result);
}

extern float runtimeFloatSettingDefault166;

inline LocalM128& Vec4::getQuad()
{
    return *reinterpret_cast<LocalM128*>(&x);
}

inline const LocalM128& Vec4::getQuad() const
{
    return *reinterpret_cast<const LocalM128*>(&x);
}

struct ActivePlane
{
    int m_uiEdgeIndex;
    PlaneRecord* m_pHavokConstraint;
    PlaneStatus* m_pPlaneStatus;
};

struct SimplexInput
{
    Vec4 m_vContactPosition;
    Vec4 m_fVelocity;
    Vec4 m_vThirdInputVector;
    Vec4 m_vFourthInputVector;
    float m_fTimeStep;
    float m_fConstraintParameter;
    PlaneRecord* m_ppConstraints;
    int m_iConstraintCount;
};

struct SimplexOutput
{
    Vec4 m_vContactPosition;
    Vec4 m_fVelocity;
    float m_fTimeStep;
    PlaneStatus* m_pPlaneStatuses;
};

struct SimplexInfo
{
    ActivePlane m_kActivePlanes[4];
    int m_iActivePlaneCount;
    float m_fElapsedSimulationTime;
    const SimplexInput* m_pRayCastInput;
    SimplexOutput* m_pRayCastOutput;
};

// src: GUESS 0x00d234e0 (confidence: medium)
static __declspec(noinline) void hkVector4_ProjectPointToLimitCone(const SimplexInfo& other_, const PlaneRecord& self_, const Vec4& point_,
                                              Vec4& out_)
{
    const Limit* self = (const Limit*)&self_;
    const hkVector4* point = (const hkVector4*)&point_;
    hkVector4* out = (hkVector4*)&out_;
    const Other* other = (const Other*)&other_;
    float slope = self->slope;
    float scale = self->scale;
    hkVector4 offset;
    offset.m_vComponents = _mm_sub_ps(point->m_vComponents, self->origin.m_vComponents);
    hkVector4 origin = self->origin;
    hkVector4 axis = self->axis;
    LocalM128 axial = dot3ScalarCall(axis, offset);
    float distance2;
    _mm_store_ss(&distance2, dot3ScalarCall(offset, offset));
    offset.m_vComponents = _mm_sub_ps(offset.m_vComponents, _mm_mul_ps(broadcast(axial), axis.m_vComponents));
    float axial2;
    _mm_store_ss(&axial2, _mm_mul_ss(axial, axial));
    Matrix* transform = other->transform;
    float facing;
    _mm_store_ss(&facing, dot3ScalarCall(transform->c3, offset));
    float limit = facing > 0.0f ? self->positive : self->negative;
    if (limit > 0.0f)
    {
        float side = 0.0f;
        hkVector4 cross;
        crossProduct(cross, transform->c3, axis);
        float cross2;
        _mm_store_ss(&cross2, dot3ScalarCall(cross, cross));
        if (DAT_0104da4c < cross2)
        {
            float len = (float)sqrt(cross2);
            float inv = 1.0f / len;
            cross.m_vComponents = _mm_mul_ps(scalar(inv), cross.m_vComponents);
            side = value(dot3ScalarCall(cross, offset));
            float slope2 = slope * slope;
            float side2 = side * side;
            if (slope2 * axial2 >= side2)
            {
                offset.m_vComponents = _mm_sub_ps(offset.m_vComponents, _mm_mul_ps(scalar(side), cross.m_vComponents));
                side = 0.0f;
            }
        }
        float cone2 = (limit + slope) * (limit + slope);
        float residual2 = distance2 - side * side - axial2;
        if (cone2 * axial2 >= residual2)
        {
            if (side == 0.0f)
            {
                out->m_vComponents = origin.m_vComponents;
                return;
            }
            offset.m_vComponents = _mm_mul_ps(scalar(side), cross.m_vComponents);
        }
    }
    else
    {
        float slope2 = slope * slope;
        if ((slope2 + 1.0) * axial2 >= distance2)
        {
            out->m_vComponents = origin.m_vComponents;
            return;
        }
    }
    if (scale < 1.0f)
    {
        float projected2;
        _mm_store_ss(&projected2, dot3ScalarCall(offset, offset));
        if (DAT_0104da4c <= projected2 && distance2 * DAT_01016978 < projected2)
        {
            float ratio = distance2 / projected2;
            float root = (float)sqrt(ratio);
            float factor = scale + (1.0f - scale) * root;
            offset.m_vComponents = _mm_mul_ps(scalar(factor), offset.m_vComponents);
            LocalM128 component = dot3ScalarCall(axis, offset);
            offset.m_vComponents = _mm_sub_ps(offset.m_vComponents, _mm_mul_ps(broadcast(component), axis.m_vComponents));
        }
    }
    origin.m_vComponents = _mm_add_ps(origin.m_vComponents, offset.m_vComponents);
    out->m_vComponents = origin.m_vComponents;
}

// src: GUESS 0x00d23480 (confidence: low)
static __declspec(noinline) hkBool hkBool_ProcessAndReturnValue_00d23480(const PlaneRecord& sci, const Vec4& velocityIn)
{
    V relativeVelocity;
    relativeVelocity.v = _mm_sub_ps(velocityIn.getQuad(), sci.point.v);
    float planeVel = dot(relativeVelocity.v, sci.normal.v);
    if (planeVel < runtimeFloatSettingDefault166)
    {
        return false;
    }
    return true;
}

// src: GUESS 0x00d23850 (confidence: low)
static __declspec(noinline) void hkVector4_ComputeValues_00d23850(SimplexInfo& ctx_, const PlaneRecord* a_, const PlaneRecord* b_,
                                              const Vec4* fw_, Vec4* rw_)
{
    IntersectionContext* ctx = (IntersectionContext*)&ctx_;
    const PlaneRecord* a = *(const PlaneRecord* const volatile*)&a_;
    const PlaneRecord* b = *(const PlaneRecord* const volatile*)&b_;
    const Vec4& fw = **(const Vec4* const volatile*)&fw_;
    Vec4& rw = **(Vec4* const volatile*)&rw_;
    const V& na = a->normal;
    const V& nb = b->normal;
    V direction;
    direction.cross(na, nb);
    float squaredLength = dot(direction.v, direction.v);
    if (!(squaredLength < DAT_0104da4c))
    {
        float inverse = 1.0f / root(squaredLength);
        direction.v = _mm_mul_ps(direction.v, scalar(inverse));
        V right, left;
        right.cross(nb, direction);
        left.cross(direction, na);
        float db = dot(b->point.v, nb.v);
        float da = dot(a->point.v, na.v);
        float average = (float)(dot(_mm_add_ps(a->point.v, b->point.v), direction.v) * DAT_01011588);
        LocalM128 distances = distances3(average, db, da);
        LocalM128 sum = _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(distances, distances, 0),
                       _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(nb.v, nb.v, 0xd2), _mm_shuffle_ps(na.v, na.v, 0xc9)),
                                  _mm_mul_ps(_mm_shuffle_ps(nb.v, nb.v, 0xc9), _mm_shuffle_ps(na.v, na.v, 0xd2)))),
            _mm_mul_ps(_mm_shuffle_ps(distances, distances, 0x55), left.v));
        sum = _mm_add_ps(sum, _mm_mul_ps(_mm_shuffle_ps(distances, distances, 0xaa), right.v));
        LocalM128 position = _mm_mul_ps(sum, scalar(inverse));
        if (!(_mm_movemask_ps(_mm_cmplt_ps(ctx->geometry->bounds, _mm_and_ps(position, DAT_01017d10))) & 7))
        {
            LocalM128 difference = _mm_sub_ps(fw.getQuad(), position);
            float squared = dot(difference, difference);
            float radius = dot(ctx->geometry->unk30, direction.v);
            float projection = dot(difference, direction.v);
            float threshold = (float)((a->auxiliary.m128_f32[0] + b->auxiliary.m128_f32[0] +
                                       radius * ((projection * radius > 0.0f)
                                                     ? a->auxiliary.m128_f32[1] + b->auxiliary.m128_f32[1]
                                                     : a->auxiliary.m128_f32[2] + b->auxiliary.m128_f32[2])) *
                                      DAT_01011588);
            float blend = (float)((a->auxiliary.m128_f32[3] + b->auxiliary.m128_f32[3]) * DAT_01011588);
            if ((squared - projection * projection) * threshold * threshold >= projection * projection)
            {
                rw.getQuad() = position;
                return;
            }
            float adjustment = projection;
            if (blend < 1.0f && !(0.001f * squared < projection * projection))
            {
                adjustment = projection * (blend + root(squared) * absoluteValue(1.0f / projection) * (1.0f - blend));
            }
            rw.getQuad() = _mm_add_ps(position, _mm_mul_ps(scalar(adjustment), direction.v));
            return;
        }
    }
    ctx->status->entries[a - ctx->geometry->planes].marked = 2;
    ctx->status->entries[b - ctx->geometry->planes].marked = 2;
    *(const PlaneRecord* const volatile*)&b_;
    if (a->metadata.priority > b->metadata.priority)
    {
        hkVector4_ProjectPointToLimitCone(ctx_, *b, fw, rw);
        hkVector4_ProjectPointToLimitCone(ctx_, *a, rw, rw);
    }
    else
    {
        hkVector4_ProjectPointToLimitCone(ctx_, *a, fw, rw);
        hkVector4_ProjectPointToLimitCone(ctx_, *b, rw, rw);
    }
}

// src: GUESS 0x00d23ca0 (confidence: low)
static __declspec(noinline) void Object_ProcessAndReturnValue_00d23ca0(SimplexInfo& ctx_, const PlaneRecord* a, const PlaneRecord* b,
                                              const PlaneRecord* c, int allowResort, const Vec4& fallback, Vec4& result)
{
    IntersectionContext* ctx = (IntersectionContext*)&ctx_;
    CrossBasis m;
    V& r0 = m.column(0);
    V& r1 = m.column(1);
    V& r2 = m.column(2);
    r0.cross(b->normal, c->normal);
    r1.cross(c->normal, a->normal);
    r2.cross(a->normal, b->normal);
    float det = dot(r0.v, a->normal.v);
    if (!(absoluteValue(det) < DAT_0104da4c))
    {
        float dc = dot(c->point.v, c->normal.v);
        float db = dot(b->point.v, b->normal.v);
        float da = dot(a->point.v, a->normal.v);
        LocalM128 t = distances3(da, db, dc);
        float invDet = 1.0f / det;
        LocalM128 sVel = _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(t, t, 0), r0.v), _mm_mul_ps(_mm_shuffle_ps(t, t, 0x55), r1.v)),
            _mm_mul_ps(_mm_shuffle_ps(t, t, 0xaa), r2.v));
        sVel = _mm_mul_ps(sVel, scalar(invDet));
        if (!(_mm_movemask_ps(_mm_cmplt_ps(ctx->geometry->bounds, _mm_and_ps(sVel, DAT_01017d10))) & 7))
        {
            result.getQuad() = sVel;
            return;
        }
    }
    if (allowResort)
    {
        Object_ProcessEntries_00d23380(ctx);
        a = ctx->first;
        b = ctx->second;
        c = ctx->third;
    }
    ctx->status->entries[a - ctx->geometry->planes].marked = 1;
    ctx->status->entries[b - ctx->geometry->planes].marked = 1;
    ctx->status->entries[c - ctx->geometry->planes].marked = 1;
    int oldNum = ctx->count;
    hkVector4_ComputeValues_00d23850(ctx_, a, b, &fallback, &result);
    if (ctx->count == oldNum)
    {
        hkVector4_ComputeValues_00d23850(ctx_, a, c, &result, &result);
    }
    if (ctx->count == oldNum)
    {
        hkVector4_ComputeValues_00d23850(ctx_, b, c, &result, &result);
    }
}

template <typename T> static __forceinline T hkMax2(T a, T b)
{
    return a > b ? a : b;
}

// Scratch velocities use the existing aligned, uninitialized hkVector4 storage; callees write all four lanes.
// Iteratively reduces the active plane set by testing velocity against planes and resolving intersections until a stable result is written to the ray-cast output.
// @fnv 0x00d23f50
// src: GUESS 0x00d23f50 (confidence: low)
static __declspec(noinline) void hkVector4_ProcessEntries_00d23f50(SimplexInfo& info)
{
    while (true)
    {
        switch (info.m_iActivePlaneCount)
        {
        case 1: {
            PlaneRecord* sci = info.m_kActivePlanes[0].m_pHavokConstraint;
            hkVector4_ProjectPointToLimitCone(info, *sci, info.m_pRayCastInput->m_fVelocity, info.m_pRayCastOutput->m_fVelocity);
            return;
        }
        case 2: {
            hkVector4 velocityStorage;
            Vec4& velocity = reinterpret_cast<Vec4&>(velocityStorage);
            hkVector4_ProjectPointToLimitCone(info, *info.m_kActivePlanes[1].m_pHavokConstraint, info.m_pRayCastInput->m_fVelocity,
                         velocity);
            hkBool plane0Used = hkBool_ProcessAndReturnValue_00d23480(*info.m_kActivePlanes[0].m_pHavokConstraint, velocity);
            if (!plane0Used)
            {
                info.m_pRayCastOutput->m_fVelocity.getQuad() = velocity.getQuad();
                info.m_kActivePlanes[0] = info.m_kActivePlanes[1];
                info.m_iActivePlaneCount = 1;
                return;
            }
            hkVector4_ComputeValues_00d23850(info, info.m_kActivePlanes[0].m_pHavokConstraint, info.m_kActivePlanes[1].m_pHavokConstraint,
                         &info.m_pRayCastInput->m_fVelocity, &info.m_pRayCastOutput->m_fVelocity);
            return;
        }
        case 3: {
            {
                hkVector4 velocityStorage;
                Vec4& velocity = reinterpret_cast<Vec4&>(velocityStorage);
                hkVector4_ProjectPointToLimitCone(info, *info.m_kActivePlanes[2].m_pHavokConstraint, info.m_pRayCastInput->m_fVelocity,
                             velocity);
                hkBool plane0Used = hkBool_ProcessAndReturnValue_00d23480(*info.m_kActivePlanes[0].m_pHavokConstraint, velocity);
                if (!plane0Used)
                {
                    hkBool plane1Used = hkBool_ProcessAndReturnValue_00d23480(*info.m_kActivePlanes[1].m_pHavokConstraint, velocity);
                    if (!plane1Used)
                    {
                        info.m_pRayCastOutput->m_fVelocity.getQuad() = velocity.getQuad();
                        info.m_kActivePlanes[0] = info.m_kActivePlanes[2];
                        info.m_iActivePlaneCount = 1;
                        break;
                    }
                }
            }
            {
                bool dropped_a_plane = false;
                for (int testPlane = 0; testPlane < 2; testPlane++)
                {
                    hkVector4 velocityStorage;
                    Vec4& velocity = reinterpret_cast<Vec4&>(velocityStorage);
                    hkVector4_ComputeValues_00d23850(info, info.m_kActivePlanes[testPlane].m_pHavokConstraint,
                                 info.m_kActivePlanes[2].m_pHavokConstraint, &info.m_pRayCastInput->m_fVelocity,
                                 &velocity);
                    bool planeUsed = hkBool_ProcessAndReturnValue_00d23480(*info.m_kActivePlanes[1 - testPlane].m_pHavokConstraint, velocity);
                    if (!planeUsed)
                    {
                        info.m_kActivePlanes[0] = info.m_kActivePlanes[testPlane];
                        info.m_kActivePlanes[1] = info.m_kActivePlanes[2];
                        info.m_iActivePlaneCount--;
                        dropped_a_plane = true;
                        break;
                    }
                }
                if (dropped_a_plane)
                {
                    break;
                }
            }
            Object_ProcessAndReturnValue_00d23ca0(info, info.m_kActivePlanes[0].m_pHavokConstraint, info.m_kActivePlanes[1].m_pHavokConstraint,
                         info.m_kActivePlanes[2].m_pHavokConstraint, true, info.m_pRayCastInput->m_fVelocity,
                         info.m_pRayCastOutput->m_fVelocity);
            return;
        }
        case 4: {
            Object_ProcessEntries_00d23380((IntersectionContext*)&info);
            bool dropped_a_plane = false;
            for (int i = 0; i < 3; i++)
            {
                hkVector4 velocityStorage;
                Vec4& velocity = reinterpret_cast<Vec4&>(velocityStorage);
                Object_ProcessAndReturnValue_00d23ca0(info, info.m_kActivePlanes[(i + 1) % 3].m_pHavokConstraint,
                             info.m_kActivePlanes[(i + 2) % 3].m_pHavokConstraint,
                             info.m_kActivePlanes[3].m_pHavokConstraint, false, info.m_pRayCastInput->m_fVelocity,
                             velocity);
                hkBool planeUsed = hkBool_ProcessAndReturnValue_00d23480(*info.m_kActivePlanes[i].m_pHavokConstraint, velocity);
                if (!planeUsed)
                {
                    info.m_kActivePlanes[i] = info.m_kActivePlanes[2];
                    info.m_kActivePlanes[2] = info.m_kActivePlanes[3];
                    info.m_iActivePlaneCount = 3;
                    dropped_a_plane = true;
                    break;
                }
            }
            if (dropped_a_plane)
            {
                break;
            }
            {
                hkVector4 velocityStorage;
                Vec4& velocity = reinterpret_cast<Vec4&>(velocityStorage);
                // Preserve the original scalar bit copy from the input velocity.
                const Vec4& inputVelocity = info.m_pRayCastInput->m_fVelocity;
                velocity.xb = inputVelocity.xb;
                velocity.yb = inputVelocity.yb;
                velocity.zb = inputVelocity.zb;
                velocity.wb = inputVelocity.wb;
                PlaneRecord* sci0 = info.m_kActivePlanes[0].m_pHavokConstraint;
                PlaneRecord* sci1 = info.m_kActivePlanes[1].m_pHavokConstraint;
                PlaneRecord* sci2 = info.m_kActivePlanes[2].m_pHavokConstraint;
                PlaneRecord* sci3 = info.m_kActivePlanes[3].m_pHavokConstraint;
                int oldNum = info.m_iActivePlaneCount;
                Object_ProcessAndReturnValue_00d23ca0(info, sci0, sci1, sci2, false, velocity, velocity);
                if (oldNum == info.m_iActivePlaneCount)
                {
                    Object_ProcessAndReturnValue_00d23ca0(info, sci0, sci1, sci3, false, velocity, velocity);
                }
                try
                {
                    if (oldNum != info.m_iActivePlaneCount)
                        goto skip2;
                }
                catch (...)
                {
                    throw;
                }
                Object_ProcessAndReturnValue_00d23ca0(info, sci0, sci2, sci3, false, velocity, velocity);
            skip2:
                try
                {
                    if (oldNum != info.m_iActivePlaneCount)
                        goto skip3;
                }
                catch (...)
                {
                    throw;
                }
                Object_ProcessAndReturnValue_00d23ca0(info, sci1, sci2, sci3, false, velocity, velocity);
            skip3:
                info.m_pRayCastOutput->m_fVelocity.getQuad() = velocity.getQuad();
            }
            {
                int maxStatus = 0;
                for (int j = 0; j < 4; j++)
                {
                    maxStatus = hkMax2(maxStatus, info.m_kActivePlanes[j].m_pPlaneStatus->marked);
                }
                for (int k = 0; k < 4; k++)
                {
                    if (maxStatus == info.m_kActivePlanes[k].m_pPlaneStatus->marked)
                    {
                        info.m_kActivePlanes[k] = info.m_kActivePlanes[3];
                        break;
                    }
                }
                info.m_iActivePlaneCount--;
                for (int l = 0; l < 3; l++)
                {
                    info.m_kActivePlanes[l].m_pPlaneStatus->marked = 0;
                }
            }
            break;
        }
        default:
            return;
        }
    }
}

SimplexInfo* volatile g_simplexInfo;
void invokeExamineActivePlanes()
{
    hkVector4_ProcessEntries_00d23f50(*g_simplexInfo);
}
