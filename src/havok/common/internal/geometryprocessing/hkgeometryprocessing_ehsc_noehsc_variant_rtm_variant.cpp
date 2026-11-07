#define FNV64_HKVECTOR4_OWN_ASSIGN   // this unit defines its own hkVector4 assign form
#define FNV64_HKVECTOR4_OWN_COPY   // this unit defines its own hkVector4 copy form
// src/havok/common/internal/geometryprocessing/hkgeometryprocessing_ehsc_noehsc_variant_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/common/internal/geometryprocessing/hkgeometryprocessing_ehsc_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /O2 /GS /EHs-c- /Gy (unit lists /MT /O2 /GS /EHs-c- /Gy). Declarations copied from that unit's skeleton.

// src/havok/common/internal/geometryprocessing/hkgeometryprocessing_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/common/internal/geometryprocessing/hkgeometryprocessing.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/internal/geometryprocessing/hkgeometryprocessing.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/geometryprocessing/hkgeometryprocessing.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
// Keep this unit's float-only SIMD declaration: VC9 treats the byte arrays in
// xmmintrin.h's union as /GS buffers, changing FUN_00dedf10's stack frame.
// Exe 0x00dedf10 FUN_00dedf10: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
#define _INCLUDED_MM2
#include "../../../../../include/hkSimdReal.h"
#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkMemoryRouter.h"
#include "../../../../../include/hkVector4.h"
#include <string.h>

extern "C"
{
    LocalM128 _mm_add_ss(LocalM128 a, LocalM128 b);
    LocalM128 _mm_sub_ss(LocalM128 a, LocalM128 b);
    LocalM128 _mm_div_ss(LocalM128 a, LocalM128 b);
    LocalM128 _mm_add_ps(LocalM128 a, LocalM128 b);
    LocalM128 _mm_sub_ps(LocalM128 a, LocalM128 b);
    LocalM128 _mm_mul_ps(LocalM128 a, LocalM128 b);
    LocalM128 _mm_shuffle_ps(LocalM128 a, LocalM128 b, unsigned int imm);
    LocalM128 _mm_load_ps1(const float* p);
    void _mm_store_ss(float* p, LocalM128 a);
    LocalM128 _mm_and_ps(LocalM128, LocalM128);
    LocalM128 _mm_setr_ps(float, float, float, float);
    LocalM128 _mm_sqrt_ss(LocalM128);
    LocalM128 _mm_set_ps1(float);
    LocalM128 _mm_load_ss(const float*);
}

extern "C" void __cdecl Deallocate(void*);
extern int DAT_010d9fc4;
struct FUN_00dee620
{
    void* m_pVTable;
    __thiscall FUN_00dee620(int testFlag);
};
extern "C" void __cdecl hkVector4_ProcessEntries_00dedf10(void*, void*, void*, void*, int, int);
void __cdecl hkGeometryProcessing_generateRandomDistribution(void* first, void* second, void* third, void* fourth);
struct FUN_00dee6b0_Class
{
    int unk00;
    float unk04;
    float GetUnk04(int testFlag);
};
extern int DAT_010cd664;

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();
struct FUN_00dee6c0_cls
{
    int m_vptr;

    FUN_00dee6c0_cls* FUN_00dee6c0(unsigned char acFlags);
};
inline hkSimdReal::hkSimdReal()
{}

inline hkSimdReal::hkSimdReal(const LocalM128& r) : m_vValue(r)
{}

inline hkSimdReal::operator float() const
{
    float f;
    _mm_store_ss(&f, m_vValue);
    return f;
}

__forceinline hkSimdReal operator/(const hkSimdReal& a, const hkSimdReal& b)
{
    return _mm_div_ss(a.m_vValue, b.m_vValue);
}
__forceinline void hkVector4::setAddMul4(const hkVector4& a, const hkVector4& b, const hkSimdReal& r)
{
    m_vComponents =
        _mm_add_ps(a.m_vComponents, _mm_mul_ps(_mm_shuffle_ps(r.m_vValue, r.m_vValue, 0), b.m_vComponents));
}
__forceinline hkSimdReal hkVector4::dot3(const hkVector4& a) const
{
    const LocalM128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
    const LocalM128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    const LocalM128 z = _mm_shuffle_ps(x2, x2, 0xaa);
    return _mm_add_ss(z, xySum);
}
__forceinline hkSimdReal hkVector4::lengthSquared3() const
{
    return dot3(*this);
}
extern const hkVector4 DAT_010c7160;
float __cdecl hkVector4_GetPointSegmentSquaredDistance(const hkVector4& a, const hkVector4& b, const hkVector4& c, float* out);
extern LocalM128 DAT_010c71d0;
struct FUN_00dee640_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    LocalM128 m_vec10;
    float m_fDist20;
    int unk24;
    int unk28;
    int unk2C;
    void* m_pTag30;
    float UpdateNearestDistance(void* pair);
};
extern LocalM128 DAT_01267e30;
struct Vertex
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    LocalM128 m_vContactPosition;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    LocalM128 m_vHitNormal;
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
    void SplitTriangleWithNewVertex(Triangle* a, const LocalM128* b, int c);
};
extern LocalM128 DAT_01017d10;
extern float DAT_01011d78;
struct CubeVector
{
    LocalM128 lanes;
    __forceinline void sum(const CubeVector& lhs, const CubeVector& rhs)
    {
        lanes = _mm_add_ps(lhs.lanes, rhs.lanes);
    }
    __forceinline void difference(const CubeVector& lhs, const CubeVector& rhs)
    {
        lanes = _mm_sub_ps(lhs.lanes, rhs.lanes);
    }
    __forceinline void scale(const LocalM128& k)
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
void __cdecl Hkgeometryprocessing_GetCubeBoundsFromLargestExtent(CubeBox* box);
#include <math.h>
extern const float DAT_0104da4c = 1.1920928955078125e-7f;
extern float DAT_0104da48;
float __cdecl hkVector4_GetClosestSegmentParameters(const hkVector4& firstStart, const hkVector4& firstEnd, const hkVector4& secondStart,
                           const hkVector4& secondEnd, float* firstParameter, float* secondParameter);

struct Sdedf10_PlacementArg;

struct Sdedf10_TypeIsPod
{
};
struct Sdedf10_TypeIsClass
{
};

struct Sdedf10_Allocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void ReturnMemory(void* p, int numBytes);
};
class Sdedf10_MemoryRouter
{
  public:
    static Sdedf10_MemoryRouter& __cdecl GetMonitorStream();
    __forceinline Sdedf10_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }

  private:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Sdedf10_Allocator* m_pStreamAllocator;
};
__forceinline Sdedf10_Allocator& Sdedf10_heap()
{
    return Sdedf10_MemoryRouter::GetMonitorStream().heap();
}

void __cdecl Sdedf10_reserve(Sdedf10_Allocator& a, void* array, int reqElem, int sizeElem);
void __cdecl Sdedf10_reserveMore(Sdedf10_Allocator& a, void* array, int sizeElem);

template <typename T> __forceinline void Sdedf10_construct(T* t, int n, Sdedf10_TypeIsPod)
{}
template <typename T> __forceinline void Sdedf10_destruct(T* t, int n, Sdedf10_TypeIsPod)
{}
template <typename T> __forceinline void Sdedf10_constructWithCopy(T* t, int n, const T& tcopy, Sdedf10_TypeIsPod)
{
    for (int i = 0; i < n; ++i)
    {
        t[i] = tcopy;
    }
}
template <typename T> __forceinline void Sdedf10_constructWithCopy(T* t, int n, const T& tcopy, Sdedf10_TypeIsClass)
{
    for (int i = 0; i < n; ++i)
    {
        new (reinterpret_cast<Sdedf10_PlacementArg*>(t + i)) T(tcopy);
    }
}

template <typename T, typename Tag> struct Sdedf10_ArrayBaseLocalForm
{ // local form of hkArrayBase: 0x00dedf10 needs the original constructor stores; shared base construction changes bytes.
    enum
    {
        CAPACITY_MASK = 0x3FFFFFFF,
        DONT_DEALLOCATE_FLAG = 0x80000000
    };
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline Sdedf10_ArrayBaseLocalForm() : m_data(0), m_iElementCount(0), m_iCapacityState(DONT_DEALLOCATE_FLAG)
    {}
    __forceinline ~Sdedf10_ArrayBaseLocalForm()
    {}
    __forceinline int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    __forceinline int getCapacity() const
    {
        return m_iCapacityState & CAPACITY_MASK;
    }
    __forceinline T& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline const T& operator[](int i) const
    {
        return m_data[i];
    }
    __forceinline T* begin()
    {
        return m_data;
    }
    __forceinline void clear()
    {
        Sdedf10_destruct(m_data, m_iElementCount, Sdedf10_TypeIsPod());
        m_iElementCount = 0;
    }
    __forceinline void _clearAndDeallocate(Sdedf10_Allocator& alloc)
    {
        clear();
        if ((m_iCapacityState & DONT_DEALLOCATE_FLAG) == 0)
        {
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        }
        m_data = 0;
        m_iCapacityState = DONT_DEALLOCATE_FLAG;
    }
    __forceinline void _reserveExactly(Sdedf10_Allocator& alloc, int n)
    {
        if (getCapacity() < n)
        {
            Sdedf10_reserve(alloc, this, n, sizeof(T));
        }
    }
    __forceinline void GrowArrayCapacity(Sdedf10_Allocator& alloc, int n)
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            Sdedf10_reserve(alloc, this, newSize, sizeof(T));
        }
    }
    __forceinline void _pushBack(Sdedf10_Allocator& alloc, const T& t)
    {
        if (m_iElementCount == getCapacity())
        {
            Sdedf10_reserveMore(alloc, this, sizeof(T));
        }
        Sdedf10_constructWithCopy(m_data + m_iElementCount, 1, t, Tag());
        m_iElementCount++;
    }
    __forceinline void _setSize(Sdedf10_Allocator& alloc, int n)
    {
        GrowArrayCapacity(alloc, n);
        Sdedf10_destruct(m_data + n, m_iElementCount - n, Sdedf10_TypeIsPod());
        Sdedf10_construct(m_data + m_iElementCount, n - m_iElementCount, Sdedf10_TypeIsPod());
        m_iElementCount = n;
    }
};

template <typename T, typename Tag = Sdedf10_TypeIsPod> struct Sdedf10_Array : Sdedf10_ArrayBaseLocalForm<T, Tag>
{
    __forceinline Sdedf10_Array()
    {}
    __forceinline ~Sdedf10_Array()
    {
        this->_clearAndDeallocate(Sdedf10_heap());
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        this->_setSize(Sdedf10_heap(), n);
    }
    __forceinline void reserveExactly(int n)
    {
        this->_reserveExactly(Sdedf10_heap(), n);
    }
    __forceinline void AddBack(const T& t)
    {
        this->_pushBack(Sdedf10_heap(), t);
    }
};

__forceinline hkSimdReal::hkSimdReal(float x)
{
    m_vValue = _mm_load_ss(&x);
}

__forceinline LocalM128 hkSimdReal::broadcast() const
{
    return _mm_shuffle_ps(m_vValue, m_vValue, 0);
}

__forceinline hkVector4::hkVector4(const hkVector4& vector)
{
    memcpy(this, &vector, sizeof(*this));
}
__forceinline void hkVector4::operator=(const hkVector4& vector)
{
    memcpy(this, &vector, sizeof(*this));
}
__forceinline void hkVector4::SetAllComponents(float a)
{
    m_vComponents = _mm_set_ps1(a);
}
__forceinline float& hkVector4::operator()(int a)
{
    return reinterpret_cast<float*>(&m_vComponents)[a];
}

class Sdedf10_Aabb
{
  public:
    __forceinline static void* __cdecl operator new(unsigned int, Sdedf10_PlacementArg* p) throw()
    {
        return p;
    }
    __forceinline static void __cdecl operator delete(void*, Sdedf10_PlacementArg*) throw()
    {}
    __forceinline Sdedf10_Aabb()
    {}
    __forceinline Sdedf10_Aabb(const Sdedf10_Aabb& box)
    {
        memcpy(this, &box, sizeof(*this));
    }
    hkVector4 m_kMinimumCorner;
    hkVector4 m_kMaximumCorner;
};

__forceinline void Sdedf10_calcAabb(const hkVector4& center, float innerRadius, Sdedf10_Aabb& aabbOut)
{
    hkVector4 ir;
    ir.SetAllComponents(innerRadius);
    aabbOut.m_kMinimumCorner.setSub4(center, ir);
    aabbOut.m_kMaximumCorner.setAdd4(center, ir);
    aabbOut.m_kMinimumCorner(3) = 0;
    aabbOut.m_kMaximumCorner(3) = 0;
}

struct Sdedf10_IFunction
{
    __forceinline Sdedf10_IFunction()
    {}
    virtual ~Sdedf10_IFunction()
    {}
    virtual float evaluate(const hkVector4&) const = 0;
};

struct Sdedf10_ConstFunction : Sdedf10_IFunction
{
    Sdedf10_ConstFunction(const float& value) : m_uiFilterValue(value)
    {}
    float evaluate(const hkVector4&) const
    {
        return m_uiFilterValue;
    }
    float m_uiFilterValue;
};

struct Sdedf10_PseudoRandom
{
    __forceinline Sdedf10_PseudoRandom(int s)
    {
        m_uiState = (unsigned int)s;
        m_pTileTemplate = m_uiState;
    }
    unsigned int m_uiState;
    unsigned int m_pTileTemplate;
};

struct Sdedf10_Geometry;
struct Sdedf10_Transform;
extern const Sdedf10_Transform DAT_01268370;

struct __declspec(align(16)) Sdedf10_Mesh
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
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;

    Sdedf10_Mesh();
    ~Sdedf10_Mesh();
    void AppendGeometry(const Sdedf10_Geometry& geometry, const Sdedf10_Transform& transform, int material);
    void assignVertexNormals();
    void FinalizeMesh();
};

struct Sdedf10_NodeManager
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    ~Sdedf10_NodeManager();
};

struct Sdedf10_TreeNode
{
    Sdedf10_Aabb m_iBufferSize;
    void* m_ulUserData;
    template <typename T> __forceinline T getLeafData() const
    {
        return reinterpret_cast<T>(m_ulUserData);
    }
};

class Sdedf10_Tree
{
  public:
    Sdedf10_Tree();
    virtual ~Sdedf10_Tree()
    {
        clear();
    }
    void build(Sdedf10_Aabb* volumes, void** userDatas, int numLeaves, Sdedf10_Array<unsigned int>& leavesOut);
    void clear();
    void update(unsigned int leafIdx, const Sdedf10_Aabb& aabb);

    Sdedf10_TreeNode* m_pAabbRootNode;
    unsigned int m_usManagerValue;
    int m_iNodeCount;
    Sdedf10_NodeManager m_kNodeManager;
    hkVector4 m_kAabbMin;
    hkVector4 m_kAabbMaximum;
    hkVector4 m_kAabbScale;
    hkVector4 m_kAabbInverseScale;
};

struct Sdedf10_Collector
{
    __forceinline Sdedf10_Collector()
    {}
    virtual ~Sdedf10_Collector()
    {}
    virtual float GetHitDistance(const Sdedf10_TreeNode* leaf) = 0;
};

struct Sdedf10_ClosestPointCollector : Sdedf10_Collector
{
    __forceinline Sdedf10_ClosestPointCollector(const hkVector4& point, float initDistanceSquared)
        : m_kPoint(point), m_fValue(initDistanceSquared)
    {}
    virtual ~Sdedf10_ClosestPointCollector()
    {}
    virtual float GetHitDistance(const Sdedf10_TreeNode* leaf) = 0;

    hkVector4 m_kPoint;
    float m_fValue;
};

struct Sdedf10_NearestFeaturePolicy : Sdedf10_ClosestPointCollector
{
    __forceinline Sdedf10_NearestFeaturePolicy(const hkVector4& point, float maxDistance)
        : Sdedf10_ClosestPointCollector(point, maxDistance), m_nearest(0)
    {}
    virtual ~Sdedf10_NearestFeaturePolicy()
    {}
    virtual float GetHitDistance(const Sdedf10_TreeNode* leaf);

    const Sdedf10_TreeNode* m_nearest;
};

void __cdecl Sdedf10_queryClosestPoint(const Sdedf10_Tree* tree, const hkVector4& point,
                                       Sdedf10_Collector* collector);
bool __cdecl Sdedf10_generateRandomDistribution(const Sdedf10_Mesh& mesh, int numPoints,
                                                Sdedf10_Array<hkVector4>& points, Sdedf10_PseudoRandom& rng);

__forceinline const Sdedf10_IFunction* Sdedf10_getUnityFunction()
{
    static Sdedf10_ConstFunction unityFunction(1);
    return &unityFunction;
}

// @fnv 0x00dedf10
// src: GUESS 0x00dedf10 (confidence: low)
bool __cdecl hkVector4_ProcessEntries_00dedf10(const Sdedf10_Geometry& geometry, int numPoints, Sdedf10_Array<hkVector4>& points,
                          int maxIterations, int seed, const Sdedf10_IFunction* densityFunction)
{
    const Sdedf10_IFunction* unityFunction = Sdedf10_getUnityFunction();
    Sdedf10_PseudoRandom rng(seed);
    if (!densityFunction)
    {
        densityFunction = unityFunction;
    }

    Sdedf10_Mesh mesh;
    mesh.AppendGeometry(geometry, DAT_01268370, -1);
    mesh.assignVertexNormals();
    mesh.FinalizeMesh();

    const int base = points.GetLogicalSize();
    if (!Sdedf10_generateRandomDistribution(mesh, numPoints, points, rng))
    {
        return false;
    }

    if (maxIterations > 0)
    {
        hkVector4* pts = &points[base];
        Sdedf10_Array<unsigned int> leaves;
        Sdedf10_Tree tree;
        leaves.SetSizeAndGrow(numPoints);
        Sdedf10_Array<Sdedf10_Aabb, Sdedf10_TypeIsClass> aabbs;
        Sdedf10_Array<void*> datas;
        for (int i = 0; i < numPoints; ++i)
        {
            Sdedf10_Aabb box;
            Sdedf10_calcAabb(pts[i], 0, box);
            aabbs.AddBack(box);
            datas.AddBack(&pts[i]);
            const float w = densityFunction->evaluate(pts[i]);
            pts[i].mul4(hkSimdReal(w));
            pts[i](3) = w;
        }
        tree.build(aabbs.begin(), datas.begin(), aabbs.GetLogicalSize(), leaves);

        Sdedf10_Array<hkVector4> samples;
        const int doubled = numPoints * 2;
        const int numSamples = doubled < 0x100 ? 0x100 : (doubled > 0x2000 ? 0x2000 : doubled);
        samples.reserveExactly(numSamples);

        for (int iter = 0; iter < maxIterations; ++iter)
        {
            samples.clear();
            if (!Sdedf10_generateRandomDistribution(mesh, numSamples, samples, rng))
            {
                return false;
            }
            for (int j = 0; j < samples.GetLogicalSize(); ++j)
            {
                Sdedf10_NearestFeaturePolicy policy(samples[j], 3.40282e38f);
                Sdedf10_queryClosestPoint(&tree, samples[j], &policy);
                if (policy.m_nearest)
                {
                    hkVector4* target = policy.m_nearest->getLeafData<hkVector4*>();
                    const float w = densityFunction->evaluate(samples[j]);
                    samples[j].mul4(hkSimdReal(w));
                    samples[j](3) = w;
                    target->add4(samples[j]);
                }
            }
            for (int k = 0; k < numPoints; ++k)
            {
                const float invW = 1.0f / pts[k](3);
                pts[k].mul4(hkSimdReal(invW));
                Sdedf10_Aabb box;
                Sdedf10_calcAabb(pts[k], 0, box);
                tree.update(leaves[k], box);
                const float w = densityFunction->evaluate(pts[k]);
                pts[k].mul4(hkSimdReal(w));
                pts[k](3) = w;
            }
        }
    }
    return true;
}
