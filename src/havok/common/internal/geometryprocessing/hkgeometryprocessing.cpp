#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit defines its own form
#define FNV64_HKVECTOR4_OWN_COPY   // this unit defines its own hkVector4 copy form
#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/hkVector4.h"
#include "../../../../../include/Vec4.h"

// src/havok/common/internal/geometryprocessing/hkgeometryprocessing.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/geometryprocessing/hkgeometryprocessing.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void __cdecl Deallocate(void*);
extern int DAT_010d9fc4;

struct FUN_00dee620
{
    void* m_pVTable;
    __thiscall FUN_00dee620(int testFlag);
};

// @fnv 0x00dee620
__thiscall FUN_00dee620::FUN_00dee620(int aiFlags)
{
    m_pVTable = &DAT_010d9fc4;
    if (aiFlags & 1)
        Deallocate(this);
}

extern "C" void __cdecl hkVector4_ProcessEntries_00dedf10(void*, void*, void*, void*, int, int);
// Forwards the four pointers to FUN_00dedf10 with two trailing int arguments set to 0.
// @fnv 0x00dee5f0
// src: HAVOK_LIB 0x00dee5f0
void __cdecl hkGeometryProcessing_generateRandomDistribution(void* first, void* second, void* third, void* fourth)
{
    hkVector4_ProcessEntries_00dedf10(first, second, third, fourth, 0, 0);
}

struct FUN_00dee6b0_Class
{
    int unk00;
    float unk04;
    float GetUnk04(int testFlag);
};
// @fnv 0x00dee6b0
// src: GUESS 0x00dee6b0 (confidence: low)
float FUN_00dee6b0_Class::GetUnk04(int testFlag)
{
    return unk04;
}

extern int DAT_010cd664;

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

struct FUN_00dee6c0_cls
{
    int m_vptr;

    FUN_00dee6c0_cls* FUN_00dee6c0(unsigned char acFlags);
};

// Sets the vtable pointer and, when acFlags has bit 0 set, frees this 0x40-byte object through the allocator from FUN_00c85750.
// @fnv 0x00dee6c0
FUN_00dee6c0_cls* FUN_00dee6c0_cls::FUN_00dee6c0(unsigned char acFlags)
{
    m_vptr = (int)&DAT_010cd664;
    if (acFlags & 1)
    {
        hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
        pAllocator->blockFree(this, 0x40);
    }
    return this;
}

// Preserve the original SSE storage and its aliasing behavior in geometry helpers.
namespace geometry_sse {
// Exe 0x00de94b0 FUN_00de94b0: retain this LocalM128 view; the CRT type changes the matched code.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
typedef LocalM128 GeometryQuad;
extern "C"
{
    GeometryQuad _mm_add_ss(GeometryQuad, GeometryQuad);
    GeometryQuad _mm_sub_ss(GeometryQuad, GeometryQuad);
    GeometryQuad _mm_div_ss(GeometryQuad, GeometryQuad);
    GeometryQuad _mm_add_ps(GeometryQuad, GeometryQuad);
    GeometryQuad _mm_sub_ps(GeometryQuad, GeometryQuad);
    GeometryQuad _mm_mul_ps(GeometryQuad, GeometryQuad);
    GeometryQuad _mm_shuffle_ps(GeometryQuad, GeometryQuad, unsigned int);
    GeometryQuad _mm_load_ps1(const float*);
    GeometryQuad _mm_and_ps(GeometryQuad, GeometryQuad);
    GeometryQuad _mm_setr_ps(float, float, float, float);
    GeometryQuad _mm_sqrt_ss(GeometryQuad);
    GeometryQuad _mm_set_ps1(float);
    GeometryQuad _mm_load_ss(const float*);
    GeometryQuad _mm_set_ss(float);
    GeometryQuad _mm_mul_ss(GeometryQuad, GeometryQuad);
    GeometryQuad _mm_rsqrt_ss(GeometryQuad);
    GeometryQuad _mm_cmpeq_ss(GeometryQuad, GeometryQuad);
    GeometryQuad _mm_andnot_ps(GeometryQuad, GeometryQuad);
    GeometryQuad _mm_load_ps(const float*);
    void _mm_store_ss(float*, GeometryQuad);
}
} // namespace geometry_sse
using geometry_sse::GeometryQuad;

static __forceinline const __m128& asSharedQuad(const GeometryQuad& value)
{
    return reinterpret_cast<const __m128&>(value);
}

static __forceinline const GeometryQuad& asGeometryQuad(const __m128& value)
{
    return reinterpret_cast<const GeometryQuad&>(value);
}

inline hkSimdReal::hkSimdReal()
{}

inline hkSimdReal::hkSimdReal(const __m128& r) : m_vValue(r)
{}

inline hkSimdReal::operator float() const
{
    float f;
    _mm_store_ss(&f, m_vValue);
    return f;
}

__forceinline hkSimdReal operator/(const hkSimdReal& a, const hkSimdReal& b)
{
    return asSharedQuad(_mm_div_ss(asGeometryQuad(a.m_vValue), asGeometryQuad(b.m_vValue)));
}

static __forceinline GeometryQuad& geometryQuad(hkVector4& value)
{
    return reinterpret_cast<GeometryQuad&>(value.m_vComponents);
}

static __forceinline const GeometryQuad& geometryQuad(const hkVector4& value)
{
    return asGeometryQuad(value.m_vComponents);
}

inline hkVector4::hkVector4(const hkVector4& value) : m_vComponents(value.m_vComponents) {}

__forceinline void hkVector4::sub4(const hkVector4& a)
{
    geometryQuad(*this) = _mm_sub_ps(geometryQuad(*this), geometryQuad(a));
}
__forceinline void hkVector4::setSub4(const hkVector4& a, const hkVector4& b)
{
    geometryQuad(*this) = _mm_sub_ps(geometryQuad(a), geometryQuad(b));
}
__forceinline void hkVector4::setAddMul4(const hkVector4& a, const hkVector4& b, const hkSimdReal& r)
{
    geometryQuad(*this) =
        _mm_add_ps(geometryQuad(a),
                   _mm_mul_ps(_mm_shuffle_ps(asGeometryQuad(r.m_vValue), asGeometryQuad(r.m_vValue), 0),
                              geometryQuad(b)));
}
__forceinline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
    const GeometryQuad x2 = _mm_mul_ps(geometryQuad(*this), geometryQuad(a));
    const GeometryQuad xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    const GeometryQuad z = _mm_shuffle_ps(x2, x2, 0xaa);
    return asSharedQuad(_mm_add_ss(z, xySum));
}
__forceinline hkSimdReal hkVector4::lengthSquared3() const
{
    return dot3(*this);
}

__forceinline void hkVector4::setCross(const hkVector4& a, const hkVector4& b)
{
    const GeometryQuad cross0 = _mm_mul_ps(_mm_shuffle_ps(geometryQuad(a), geometryQuad(a), 0xc9),
                                         _mm_shuffle_ps(geometryQuad(b), geometryQuad(b), 0xd2));
    const GeometryQuad cross1 = _mm_mul_ps(_mm_shuffle_ps(geometryQuad(a), geometryQuad(a), 0xd2),
                                         _mm_shuffle_ps(geometryQuad(b), geometryQuad(b), 0xc9));
    geometryQuad(*this) = _mm_sub_ps(cross0, cross1);
}
__forceinline float hkVector4::dot3scalar(const hkVector4& a) const
{
    const GeometryQuad x2 = _mm_mul_ps(geometryQuad(*this), geometryQuad(a));
    const GeometryQuad res = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2));
    float result;
    _mm_store_ss(&result, res);
    return result;
}

extern const hkVector4 DAT_010c7160;

// Computes the squared distance from point a to the segment bc, clamping the projection parameter to [0,1] and storing it in out.
// @fnv 0x00de94b0
// src: GUESS 0x00de94b0 (confidence: medium)
float __cdecl hkVector4_GetPointSegmentSquaredDistance(const hkVector4& a, const hkVector4& b, const hkVector4& c, float* pfT)
{
    hkVector4 d1;
    d1.setSub4(b, a);
    hkVector4 vSegmentVec;
    vSegmentVec.setSub4(c, b);
    const hkSimdReal fLenSq = vSegmentVec.lengthSquared3();
    const hkSimdReal num =
        asSharedQuad(_mm_sub_ss(geometryQuad(DAT_010c7160), asGeometryQuad(vSegmentVec.dot3(d1).m_vValue)));
    const float t = num / fLenSq;
    *pfT = t;
    if (t < 0.0f)
    {
        *pfT = 0.0f;
    }
    else if (t > 1.0f)
    {
        *pfT = 1.0f;
    }
    hkVector4 v;
    geometryQuad(v) =
        _mm_add_ps(_mm_mul_ps(geometry_sse::_mm_load_ps1(pfT), geometryQuad(vSegmentVec)), geometryQuad(d1));
    return v.lengthSquared3();
}

namespace fnv_00dea810 {
// Exe 0x00de94b0 FUN_00de94b0: retain this LocalM128 view; the CRT type changes the matched code.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C" LocalM128 _mm_setr_ps(float, float, float, float);
extern "C" LocalM128 _mm_setzero_ps(void);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_add_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_cmplt_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_and_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_andnot_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_or_ps(LocalM128, LocalM128);
extern float DAT_0104e148;

struct hkVector4Comparisonq
{
    LocalM128 m_uiMask;
};
static __forceinline LocalM128& supportingQuad(hkVector4& value)
{
    return reinterpret_cast<LocalM128&>(value.m_vComponents);
}
static __forceinline const LocalM128& supportingQuad(const hkVector4& value)
{
    return reinterpret_cast<const LocalM128&>(value.m_vComponents);
}
static __forceinline hkVector4Comparisonq compareLessThan(const hkVector4& value, const hkVector4& a)
{
    hkVector4Comparisonq c;
    c.m_uiMask = _mm_cmplt_ps(supportingQuad(value), supportingQuad(a));
    return c;
}
static __forceinline void selectSupporting(hkVector4& result, const hkVector4Comparisonq& comp,
                                          const hkVector4& trueValue, const hkVector4& falseValue)
{
    supportingQuad(result) = _mm_or_ps(_mm_and_ps(comp.m_uiMask, supportingQuad(trueValue)),
                                      _mm_andnot_ps(comp.m_uiMask, supportingQuad(falseValue)));
}
template <int I> static __forceinline void broadcastSupporting(hkVector4& result, const hkVector4& value)
{
    supportingQuad(result) = _mm_shuffle_ps(supportingQuad(value), supportingQuad(value), (I << 6) | (I << 4) | (I << 2) | I);
}

struct hkFourTransposedPointsq
{
    hkVector4 m_kVertices[3];
};

struct FourPointsArray
{
    hkFourTransposedPointsq* m_data;
    int m_iElementCount;
};

extern hkVector4 DAT_010d9fe0;
extern hkVector4 DAT_010d0fa0;

static __forceinline void setSupporting(hkVector4& result, float x, float y, float z, float w)
{
    supportingQuad(result) = _mm_setr_ps(x, y, z, w);
}
static __forceinline void multiplySupporting(hkVector4& result, const hkVector4& a, const hkVector4& b)
{
    supportingQuad(result) = _mm_mul_ps(supportingQuad(a), supportingQuad(b));
}
static __forceinline void addSupporting(hkVector4& result, const hkVector4& a, const hkVector4& b)
{
    supportingQuad(result) = _mm_add_ps(supportingQuad(a), supportingQuad(b));
}
static __forceinline void addSupporting(hkVector4& result, const hkVector4& a)
{
    supportingQuad(result) = _mm_add_ps(supportingQuad(result), supportingQuad(a));
}
static __forceinline float& supportingComponent(hkVector4& value, int i)
{
    return supportingQuad(value).m128_f32[i];
}

// Finds the vertex with the maximum dot product against direction, stores it in supportingVertexOut, and packs vertexId into the w component.
// @fnv 0x00dea810
// src: GUESS 0x00dea810 (confidence: medium)
void __cdecl hkVector4_FindSupportingVertex(const FourPointsArray& rotatedVertices, const hkVector4& direction,
                          hkVector4& supportingVertexOut)
{

    hkVector4 vBestDot;
    setSupporting(vBestDot, DAT_0104e148, DAT_0104e148, DAT_0104e148, DAT_0104e148);
    hkVector4 vCurIndices;
    supportingQuad(vCurIndices) = supportingQuad(DAT_010d9fe0);
    hkVector4 vBestIndices;
    supportingQuad(vBestIndices) = _mm_setzero_ps();

    int i = 0;
    const hkFourTransposedPointsq* p = rotatedVertices.m_data;
    hkVector4 vDirX;
    broadcastSupporting<0>(vDirX, direction);
    hkVector4 vDirY;
    supportingQuad(vDirY) = _mm_shuffle_ps(supportingQuad(direction), supportingQuad(direction), 0x55);
    hkVector4 vDirZ;
    broadcastSupporting<2>(vDirZ, direction);

    {
        for (; i < rotatedVertices.m_iElementCount * 4; i += 4)
        {
            hkVector4 x;
            multiplySupporting(x, vDirX, p->m_kVertices[0]);
            hkVector4 y;
            multiplySupporting(y, vDirY, p->m_kVertices[1]);
            hkVector4 z;
            multiplySupporting(z, vDirZ, p->m_kVertices[2]);
            hkVector4 dot;
            addSupporting(dot, x, y);
            addSupporting(dot, z);
            hkVector4Comparisonq comp = compareLessThan(vBestDot, dot);
            selectSupporting(vBestDot, comp, dot, vBestDot);
            selectSupporting(vBestIndices, comp, vCurIndices, vBestIndices);
            supportingQuad(vCurIndices) = _mm_add_ps(supportingQuad(vCurIndices), supportingQuad(DAT_010d0fa0));
            ++p;
        }
    }

    int a = (supportingComponent(vBestDot, 0) > supportingComponent(vBestDot, 1)) ? 0 : 1;
    int b = (supportingComponent(vBestDot, 2) > supportingComponent(vBestDot, 3)) ? 2 : 3;
    int best = (supportingComponent(vBestDot, a) > supportingComponent(vBestDot, b)) ? a : b;
    int vertexId = (int)supportingComponent(vBestIndices, best);

    const hkFourTransposedPointsq& f = rotatedVertices.m_data[(unsigned int)vertexId >> 2];
    int c = vertexId & 3;
    setSupporting(supportingVertexOut, supportingQuad(f.m_kVertices[0]).m128_f32[c], supportingQuad(f.m_kVertices[1]).m128_f32[c],
                            supportingQuad(f.m_kVertices[2]).m128_f32[c], 0.0f);
    *(int*)&supportingComponent(supportingVertexOut, 3) = vertexId | 0x3f000000;
}
}  // namespace fnv_00dea810

extern GeometryQuad DAT_010c71d0;

struct FUN_00dee640_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    GeometryQuad m_vec10;
    float m_fDist20;
    int unk24;
    int unk28;
    int unk2C;
    void* m_pTag30;
    float UpdateNearestDistance(void* pair);
};

// Computes the squared distance from m_vec10 to the midpoint of the pair and updates m_fDist20 and m_pTag30 when it is smaller.
// @fnv 0x00dee640
float FUN_00dee640_cls::UpdateNearestDistance(void* pair)
{
    const GeometryQuad* ab = (const GeometryQuad*)pair;
    GeometryQuad vMidpoint = _mm_mul_ps(_mm_add_ps(ab[0], ab[1]), DAT_010c71d0);
    GeometryQuad d = _mm_sub_ps(m_vec10, vMidpoint);
    d = _mm_mul_ps(d, d);
    GeometryQuad xy = _mm_add_ss(_mm_shuffle_ps(d, d, 0x55), d);
    float fDistSq;
    _mm_store_ss(&fDistSq, _mm_add_ss(_mm_shuffle_ps(d, d, 0xaa), xy));
    if (fDistSq < m_fDist20)
    {
        m_fDist20 = fDistSq;
        m_pTag30 = pair;
    }
    return 1.0f;
}

extern GeometryQuad DAT_01267e30;

struct Vertex
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    GeometryQuad m_vContactPosition;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    GeometryQuad m_vHitNormal;
};

struct Triangle
{
    unsigned int unk00;
    unsigned int unk04;
    Vertex* m_kVertices[3];
    unsigned int m_ppLinks[3];
    unsigned int unk20;
};

struct Edge
{
    Triangle* m_pkTriangle;
    unsigned int m_uiEdgeIndex;

    Edge(Triangle* t, unsigned int i) : m_pkTriangle(t), m_uiEdgeIndex(i)
    {}
    Edge(unsigned int uid)
    {
        m_uiEdgeIndex = uid & 3;
        m_pkTriangle = (Triangle*)(uid & ~3u);
    }
    unsigned int uid() const
    {
        return (unsigned int)m_pkTriangle + m_uiEdgeIndex;
    }
    Edge link() const
    {
        return Edge(m_pkTriangle->m_ppLinks[m_uiEdgeIndex]);
    }
    void bind(const Edge& other) const
    {
        m_pkTriangle->m_ppLinks[m_uiEdgeIndex] = other.uid();
        other.m_pkTriangle->m_ppLinks[other.m_uiEdgeIndex] = uid();
    }
    void bindSafe(const Edge& other) const
    {
        m_pkTriangle->m_ppLinks[m_uiEdgeIndex] = other.uid();
        if (other.m_pkTriangle)
            other.m_pkTriangle->m_ppLinks[other.m_uiEdgeIndex] = uid();
    }
};

struct PendingBlock
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    int m_40;
    int m_44;
    unsigned int unk48;
    unsigned int unk4C;
};

struct Sub08_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    Vertex* PushFront(PendingBlock* out);
};

struct Sub20_cls
{
    Triangle* UpdateFields_00e241a0(Triangle* node);
};

struct FUN_00e19200_cls
{
    unsigned int unk00;
    unsigned int unk04;
    Sub08_cls m_08;
    Sub20_cls m_20;
    void SplitTriangleWithNewVertex(Triangle* a, const __m128* b, int c);
};

// Creates a new vertex from b, assigns it to three triangles, and rewires their edge links to split t0.
// @fnv 0x00e19200
// src: GUESS 0x00e19200 (confidence: medium)
void FUN_00e19200_cls::SplitTriangleWithNewVertex(Triangle* apTriangle, const __m128* b, int aiUnused)
{
    PendingBlock stBlock;
    stBlock.m_40 = -1;
    stBlock.m_44 = -1;
    Vertex* v = m_08.PushFront(&stBlock);
    v->m_vHitNormal = DAT_01267e30;
    v->m_vContactPosition = asGeometryQuad(*b);
    Triangle* pTriangle1 = m_20.UpdateFields_00e241a0(apTriangle);
    Triangle* pTriangle2 = m_20.UpdateFields_00e241a0(apTriangle);
    apTriangle->m_kVertices[0] = v;
    pTriangle1->m_kVertices[1] = v;
    pTriangle2->m_kVertices[2] = v;
    Edge(pTriangle1, 2).bindSafe(Edge(apTriangle, 2).link());
    Edge(pTriangle2, 0).bindSafe(Edge(apTriangle, 0).link());
    Edge(apTriangle, 0).bind(Edge(pTriangle2, 1));
    Edge(pTriangle1, 0).bind(Edge(pTriangle2, 2));
    Edge(pTriangle1, 1).bind(Edge(apTriangle, 2));
}

namespace fnv_00dea6b0 {
// Checks if point p lies inside triangle abc by verifying the dot product of each edge cross product with the triangle normal is at least tol.
// @fnv 0x00dea6b0
// src: XBOX_PDB 0x00dea6b0
bool __cdecl hkGeometryProcessing_checkPointInsideTriangle(const hkVector4& p, const hkVector4& a, const hkVector4& b,
                          const hkVector4& c, float afTolerance)
{
    hkVector4 ab;
    ab.setSub4(b, a);
    hkVector4 vEdgeAC;
    vEdgeAC.setSub4(c, a);
    hkVector4 n;
    n.setCross(ab, vEdgeAC);
    {
        hkVector4 e0;
        e0.setSub4(a, p);
        hkVector4 e1;
        e1.setSub4(b, p);
        hkVector4 cr;
        cr.setCross(e0, e1);
        if (cr.dot3scalar(n) < afTolerance)
            return false;
    }
    {
        hkVector4 e0;
        e0.setSub4(b, p);
        hkVector4 e1;
        e1.setSub4(c, p);
        hkVector4 cr;
        cr.setCross(e0, e1);
        if (cr.dot3scalar(n) < afTolerance)
            return false;
    }
    {
        hkVector4 e0;
        e0.setSub4(c, p);
        hkVector4 e1;
        e1.setSub4(a, p);
        hkVector4 cr;
        cr.setCross(e0, e1);
        if (cr.dot3scalar(n) < afTolerance)
            return false;
    }
    return true;
}
}  // namespace fnv_00dea6b0

extern GeometryQuad DAT_01017d10;
extern float DAT_01011d78;

struct CubeVector
{
    GeometryQuad lanes;
    __forceinline void sum(const CubeVector& lhs, const CubeVector& rhs)
    {
        lanes = _mm_add_ps(lhs.lanes, rhs.lanes);
    }
    __forceinline void difference(const CubeVector& lhs, const CubeVector& rhs)
    {
        lanes = _mm_sub_ps(lhs.lanes, rhs.lanes);
    }
    __forceinline void scale(const GeometryQuad& k)
    {
        lanes = _mm_mul_ps(k, lanes);
    }
    __forceinline int longestAxis() const
    {
        CubeVector magnitude;
        magnitude.lanes = _mm_and_ps(lanes, DAT_01017d10);
        const float* p = (const float*)&magnitude.lanes;
        if (p[0] < p[1])
            return p[1] < p[2] ? 2 : 1;
        return p[0] < p[2] ? 2 : 0;
    }
    __forceinline float component(int i) const
    {
        return ((const float*)&lanes)[i];
    }
};
struct CubeBox
{
    CubeVector lower;
    CubeVector upper;
    __forceinline void center(CubeVector& dst) const
    {
        dst.sum(lower, upper);
        dst.scale(DAT_010c71d0);
    }
    __forceinline void extent(CubeVector& dst) const
    {
        dst.difference(upper, lower);
        dst.scale(DAT_010c71d0);
    }
};

// Sets lower and upper from the center using the signed extent component with greatest magnitude on x, y, or z.
// @fnv 0x00de9590
// src: GUESS 0x00de9590 (confidence: medium)
void __cdecl Hkgeometryprocessing_GetCubeBoundsFromLargestExtent(CubeBox* box)
{
    CubeVector center;
    CubeVector extent;
    box->extent(extent);
    box->center(center);
    float size = extent.component(extent.longestAxis());
    CubeVector vRadius;
    vRadius.lanes = geometry_sse::_mm_setr_ps(size, size, size, DAT_01011d78);
    box->lower.difference(center, vRadius);
    box->upper.sum(center, vRadius);
}

#include <math.h>
extern const float DAT_0104da4c = 1.1920928955078125e-7f;
extern float DAT_0104da48;

// Computes the closest distance between two line segments defined by start and end points, writing clamped parameters to the output pointers.
// @fnv 0x00dea450
// src: GUESS 0x00dea450 (confidence: medium)
float __cdecl hkVector4_GetClosestSegmentParameters(const hkVector4& firstStart, const hkVector4& firstEnd, const hkVector4& secondStart,
                           const hkVector4& secondEnd, float* firstParameter, float* secondParameter)
{
    hkVector4 firstDirection;
    firstDirection.setSub4(firstEnd, firstStart);
    hkVector4 separation;
    separation.setSub4(secondStart, firstStart);
    hkVector4 secondDirection;
    secondDirection.setSub4(secondEnd, secondStart);
    float crossDot = firstDirection.dot3(secondDirection);
    float firstOffset = separation.dot3(firstDirection);
    float secondOffset = separation.dot3(secondDirection);
    float firstSquare = firstDirection.lengthSquared3();
    float secondSquare = secondDirection.lengthSquared3();
    float determinant = secondSquare * firstSquare - crossDot * crossDot;
    float magnitude = (float)fabs(determinant);
    if (magnitude > DAT_0104da4c)
    {
        float numerator = firstSquare * secondOffset - crossDot * firstOffset;
        float parameter = -numerator / determinant;
        float clamped = parameter < 0.0f ? 0.0f : (parameter > 1.0f ? 1.0f : parameter);
        *secondParameter = clamped;
        hkVector4 point;
        point.setAddMul4(secondStart, secondDirection, hkSimdReal(asSharedQuad(geometry_sse::_mm_load_ss(secondParameter))));
        hkVector4 offset;
        offset.setSub4(firstStart, point);
        hkSimdReal squaredLength = firstDirection.lengthSquared3();
        hkSimdReal projected = offset.dot3(firstDirection);
        hkSimdReal s =
            asSharedQuad(_mm_sub_ss(geometryQuad(DAT_010c7160),
                                   _mm_div_ss(asGeometryQuad(projected.m_vValue), asGeometryQuad(squaredLength.m_vValue))));
        float rawFirst = s;
        float firstClamped = rawFirst < 0.0f ? 0.0f : (rawFirst > 1.0f ? 1.0f : rawFirst);
        *firstParameter = firstClamped;
        hkVector4 difference;
        geometryQuad(difference) =
            _mm_sub_ps(_mm_add_ps(_mm_mul_ps(geometry_sse::_mm_set_ps1(*firstParameter), geometryQuad(firstDirection)),
                                  geometryQuad(firstStart)),
                       geometryQuad(point));
        hkSimdReal result = asSharedQuad(_mm_sqrt_ss(asGeometryQuad(difference.dot3(difference).m_vValue)));
        return result;
    }
    *secondParameter = 0.0f;
    *firstParameter = 0.0f;
    return DAT_0104da48;
}

extern const float DAT_0101622c;
// @fnv 0x00de9b90
// src: GUESS 0x00de9b90 (confidence: low)
Vec4 __cdecl Hkgeometryprocessing_ComputeValues_00de9b90(const Vec4& a, const Vec4& b, const Vec4& c, const Vec4& d)
{
    GeometryQuad scale = geometry_sse::_mm_load_ss(&DAT_0101622c);
    GeometryQuad cv = reinterpret_cast<const GeometryQuad&>(c);
    GeometryQuad dv = reinterpret_cast<const GeometryQuad&>(d);
    GeometryQuad bv = reinterpret_cast<const GeometryQuad&>(b);
    GeometryQuad cd = _mm_add_ps(cv, dv);
    GeometryQuad av = reinterpret_cast<const GeometryQuad&>(a);
    GeometryQuad ab = _mm_add_ps(av, bv);
    GeometryQuad sum = _mm_add_ps(cd, ab);
    scale = _mm_shuffle_ps(scale, scale, 0);
    Vec4::Aligned result(Vec4::Uninitialized);
    reinterpret_cast<GeometryQuad&>(result) = _mm_mul_ps(sum, scale);
    return result;
}

extern const float DAT_01012054, DAT_01012068, DAT_0106c2e0;

class ScalarValue
{
    GeometryQuad value;

  public:
    ScalarValue()
    {}
    ScalarValue(const GeometryQuad& x) : value(x)
    {}
    ScalarValue(float x) : value(geometry_sse::_mm_load_ss(&x))
    {}
    operator float() const
    {
        float x;
        _mm_store_ss(&x, value);
        return x;
    }
    __forceinline const GeometryQuad& lanes() const
    {
        return value;
    }
    __forceinline GeometryQuad spread() const
    {
        return _mm_shuffle_ps(value, value, 0);
    }
};
inline ScalarValue operator+(const ScalarValue& x, const ScalarValue& y)
{
    return _mm_add_ss(x.lanes(), y.lanes());
}
inline ScalarValue operator/(const ScalarValue& x, const ScalarValue& y)
{
    return _mm_div_ss(x.lanes(), y.lanes());
}
inline ScalarValue operator-(const ScalarValue& x)
{
    return _mm_sub_ss(geometryQuad(DAT_010c7160), x.lanes());
}

class GeomVector
{
  public:
    GeometryQuad data;
    GeomVector()
    {}
    GeomVector(const GeometryQuad& x) : data(x)
    {}
    __forceinline GeomVector(const GeomVector& x) : data(x.data)
    {}
    __forceinline void operator=(const GeomVector& x)
    {
        data = x.data;
    }
    __forceinline void difference(const GeomVector& x, const GeomVector& y)
    {
        data = _mm_sub_ps(x.data, y.data);
    }
    __forceinline void cross(const GeomVector& x, const GeomVector& y)
    {
        GeometryQuad first = _mm_mul_ps(_mm_shuffle_ps(x.data, x.data, 0xc9), _mm_shuffle_ps(y.data, y.data, 0xd2));
        GeometryQuad second = _mm_mul_ps(_mm_shuffle_ps(x.data, x.data, 0xd2), _mm_shuffle_ps(y.data, y.data, 0xc9));
        data = _mm_sub_ps(first, second);
    }
    __forceinline ScalarValue dot(const GeomVector& x) const
    {
        GeometryQuad product = _mm_mul_ps(data, x.data);
        GeometryQuad xy = _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);
        return _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), xy);
    }
    __forceinline ScalarValue magnitude() const
    {
        return _mm_sqrt_ss(dot(*this).lanes());
    }
    __forceinline ScalarValue inverseMagnitude() const
    {
        const GeometryQuad half = geometry_sse::_mm_set_ss(0.5f);
        const GeometryQuad three = geometry_sse::_mm_set_ss(3.0f);
        const GeometryQuad zero = geometry_sse::_mm_set_ss(0.0f);
        const GeometryQuad squared = dot(*this).lanes();
        const GeometryQuad empty = _mm_cmpeq_ss(squared, zero);
        const GeometryQuad estimate = _mm_rsqrt_ss(squared);
        const GeometryQuad refined = _mm_mul_ss(_mm_mul_ss(half, estimate),
                                          _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(squared, estimate), estimate)));
        return _mm_andnot_ps(empty, refined);
    }
    __forceinline void normalize()
    {
        GeometryQuad scale = inverseMagnitude().spread();
        data = _mm_mul_ps(scale, data);
    }
    __forceinline float& component(int i)
    {
        return ((float*)&data)[i];
    }
    __forceinline ScalarValue selected(int i) const
    {
        switch (i)
        {
        case 0:
            return data;
        case 1:
            return _mm_shuffle_ps(data, data, 0x55);
        case 2:
            return _mm_shuffle_ps(data, data, 0xaa);
        default:
            return _mm_shuffle_ps(data, data, 0xff);
        }
    }
    __forceinline void addScaled(const GeomVector& base, const GeomVector& direction, const ScalarValue& scale)
    {
        data = _mm_add_ps(base.data, _mm_mul_ps(scale.spread(), direction.data));
    }
    __forceinline void set(float x, float y, float z, float w)
    {
        data = geometry_sse::_mm_setr_ps(x, y, z, w);
    }
    __forceinline ScalarValue sum() const
    {
        GeometryQuad xy = _mm_add_ss(_mm_shuffle_ps(data, data, 0x55), data);
        return _mm_add_ss(_mm_shuffle_ps(data, data, 0xaa), xy);
    }
    __forceinline void scale(const ScalarValue& x)
    {
        data = _mm_mul_ps(x.spread(), data);
    }
};
static __forceinline GeomVector offsetCross(const GeomVector& origin, const GeomVector& a, const GeomVector& b)
{
    GeomVector first;
    first.difference(a, origin);
    GeomVector second;
    second.difference(b, origin);
    GeomVector result;
    result.cross(first, second);
    return result;
}
static __forceinline GeomVector makePlane(const GeomVector& a, const GeomVector& b, const GeomVector& c,
                                          bool normalized)
{
    GeomVector result = offsetCross(a, b, c);
    if (normalized)
        result.normalize();
    result.component(3) = -result.dot(a);
    return result;
}
static __forceinline float doubleArea(const GeomVector& origin, const GeomVector& a, const GeomVector& b)
{
    return offsetCross(origin, a, b).magnitude();
}
float __cdecl hkGeometryProcessing_squaredDistanceFromPointToLine(const GeomVector&, const GeomVector&, const GeomVector&, GeomVector&, float*);

// Computes the squared distance from a point to a triangle, returning the closest normal and optional barycentric weights.
// @fnv 0x00de9f10
// src: XBOX_PDB 0x00de9f10
float __cdecl hkGeometryProcessing_squaredDistanceFromPointToTriangle(const GeomVector& point, const GeomVector& a, const GeomVector& b, const GeomVector& c,
                           GeomVector& normal, GeomVector* weights)
{
    GeomVector plane = makePlane(a, b, c, true);
    float distance = plane.dot(point) + plane.selected(3);
    GeomVector projected;
    projected.addScaled(point, plane, -distance);
    if (offsetCross(projected, a, b).dot(plane) > 0 && offsetCross(projected, b, c).dot(plane) > 0 &&
        offsetCross(projected, c, a).dot(plane) > 0)
    {
        normal = plane;
        if (weights)
        {
            weights->set(doubleArea(projected, b, c), doubleArea(projected, c, a), doubleArea(projected, a, b), 0);
            ScalarValue sum = weights->sum();
            if (sum > DAT_0104da4c)
                weights->scale(ScalarValue(DAT_01012068) / sum);
            else
                weights->set(DAT_0106c2e0, DAT_0106c2e0, DAT_0106c2e0, 0);
        }
        if (distance < 0)
            normal.scale(DAT_01012054);
        return distance * distance;
    }
    else
    {
        GeomVector normals[3];
        float fractions[3];
        float distances[3];
        distances[0] = hkGeometryProcessing_squaredDistanceFromPointToLine(point, a, b, normals[0], &fractions[0]);
        distances[1] = hkGeometryProcessing_squaredDistanceFromPointToLine(point, b, c, normals[1], &fractions[1]);
        distances[2] = hkGeometryProcessing_squaredDistanceFromPointToLine(point, c, a, normals[2], &fractions[2]);
        int edge =
            distances[0] < distances[1] ? (distances[0] < distances[2] ? 0 : 2) : (distances[1] < distances[2] ? 1 : 2);
        normal = normals[edge];
        if (weights)
        {
            switch (edge)
            {
            case 0:
                weights->set(1 - fractions[0], fractions[0], 0, 0);
                break;
            case 1:
                weights->set(0, 1 - fractions[1], fractions[1], 0);
                break;
            case 2:
                weights->set(fractions[2], 0, 1 - fractions[2], 0);
                break;
            }
        }
        return distances[edge];
    }
}

#include <float.h>

inline GeometryQuad S00dea980_cross(GeometryQuad a, GeometryQuad b)
{
    GeometryQuad b_yzx = _mm_shuffle_ps(b, b, 0xc9);
    GeometryQuad a_zxy = _mm_shuffle_ps(a, a, 0xd2);
    GeometryQuad a_yzx = _mm_shuffle_ps(a, a, 0xc9);
    GeometryQuad prod1 = _mm_mul_ps(b_yzx, a_zxy);
    GeometryQuad b_zxy = _mm_shuffle_ps(b, b, 0xd2);
    GeometryQuad prod2 = _mm_mul_ps(b_zxy, a_yzx);
    return _mm_sub_ps(prod2, prod1);
}

inline GeometryQuad S00dea980_len2m(GeometryQuad v)
{
    GeometryQuad m = _mm_mul_ps(v, v);
    GeometryQuad s = _mm_add_ss(_mm_shuffle_ps(m, m, 0x55), m);
    return _mm_add_ss(_mm_shuffle_ps(m, m, 0xaa), s);
}

inline GeometryQuad S00dea980_hadd(GeometryQuad v)
{
    GeometryQuad s = _mm_add_ss(_mm_shuffle_ps(v, v, 0x55), v);
    return _mm_add_ss(_mm_shuffle_ps(v, v, 0xaa), s);
}

inline float S00dea980_f(GeometryQuad v)
{
    float s;
    _mm_store_ss(&s, v);
    return s;
}

// @fnv 0x00dea980
// src: GUESS 0x00dea980 (confidence: low)
float hkVector4_ProcessAndReturnValue_00dea980(const hkVector4* apFirst, const hkVector4* apSecond, const hkVector4* apThird)
{
    GeometryQuad vFirst = geometryQuad(*apFirst);
    GeometryQuad v1 = geometryQuad(*apSecond);
    GeometryQuad v2 = geometryQuad(*apThird);

    GeometryQuad eSecondFirst = _mm_sub_ps(v1, vFirst);
    GeometryQuad eThirdFirst = _mm_sub_ps(v2, vFirst);

    GeometryQuad cr = S00dea980_cross(eSecondFirst, eThirdFirst);

    float fCrossLength = S00dea980_f(_mm_sqrt_ss(S00dea980_len2m(cr)));
    float fSqrtThree = (float)sqrt(3.0);
    float num = fSqrtThree * (fCrossLength * 2.0f);

    float fLenSqThirdFirst = S00dea980_f(S00dea980_len2m(eThirdFirst));
    float fLenSqSecondThird = S00dea980_f(S00dea980_len2m(_mm_sub_ps(v1, v2)));
    float fLenSqFirstSecond;
    _mm_store_ss(&fLenSqFirstSecond, S00dea980_len2m(_mm_sub_ps(vFirst, v1)));

    GeometryQuad vLengthsSq = geometry_sse::_mm_setr_ps(fLenSqFirstSecond, fLenSqSecondThird, fLenSqThirdFirst, 0.0f);
    GeometryQuad vDenominator = S00dea980_hadd(vLengthsSq);

    if (S00dea980_f(vDenominator) > FLT_EPSILON)
    {
        return S00dea980_f(_mm_div_ss(geometry_sse::_mm_load_ss(&num), vDenominator));
    }

    return 0.0f;
}

extern float DAT_01016248;
extern GeometryQuad DAT_010ec7f0;
static __forceinline void medianInterpolate(hkVector4& result, const hkVector4& first, const hkVector4& second,
                                            const hkSimdReal& fraction)
{
    GeometryQuad weight = _mm_shuffle_ps(asGeometryQuad(fraction.m_vValue), asGeometryQuad(fraction.m_vValue), 0);
    GeometryQuad complement = _mm_sub_ps(DAT_010ec7f0, weight);
    geometryQuad(result) =
        _mm_add_ps(_mm_mul_ps(complement, geometryQuad(first)), _mm_mul_ps(weight, geometryQuad(second)));
}
// Interpolates between first and second using a fraction loaded from DAT_01016248.
// @fnv 0x00de9b10
// src: GUESS 0x00de9b10 (confidence: medium)
hkVector4 __cdecl hkVector4_InterpolateVectorsWithGlobalFraction(const hkVector4& first, const hkVector4& second)
{
    hkVector4 result;
    medianInterpolate(result, first, second, hkSimdReal(asSharedQuad(geometry_sse::_mm_load_ss(&DAT_01016248))));
    return result;
}


extern const float DAT_0106c2e0;

struct CentroidVector
{
    GeometryQuad value;
};

// @fnv 0x00de9b50
// src: GUESS 0x00de9b50 (confidence: low)
CentroidVector __cdecl Hkgeometryprocessing_ComputeValues_00de9b50(const CentroidVector* apCentroidA, const CentroidVector* apCentroidB,
                                    const CentroidVector* apCentroidC)
{
    GeometryQuad vSum = geometry_sse::_mm_load_ps((const float*)&apCentroidA->value);
    GeometryQuad scale = geometry_sse::_mm_load_ss(&DAT_0106c2e0);
    GeometryQuad vb = geometry_sse::_mm_load_ps((const float*)&apCentroidB->value);

    vSum = _mm_add_ps(vSum, vb);

    GeometryQuad vc = geometry_sse::_mm_load_ps((const float*)&apCentroidC->value);
    vSum = _mm_add_ps(vSum, vc);
    vSum = _mm_mul_ps(vSum, _mm_shuffle_ps(scale, scale, 0));

    CentroidVector result;
    result.value = vSum;
    return result;
}
