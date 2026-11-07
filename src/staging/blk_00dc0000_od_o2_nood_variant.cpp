
// src/staging/blk_00dc0000_od_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_moves.py: the bytes and the matched neighbours of these functions
// say /MT /O2 /GS /EHsc /Gy (unit src/staging/blk_00dc0000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions to their real
// unit once identified.

// src/staging/blk_00dc0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
#include "../../include/FinishingFlag.h"

// Retain this unit's intrinsic storage view; VC9 treats the CRT byte lanes as GS buffers.
#ifndef _INCLUDED_MM2
#define _INCLUDED_MM2
// Exe 0x00dd62e0 FUN_00dd62e0: retain this LocalM128 view; the CRT type does not reproduce this function.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C"
{
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
    float _mm_cvtss_f32(LocalM128);
    void _mm_store_ss(float*, LocalM128);
}
#endif

#include "../../include/Pair.h"
#include "../../include/hkVector4q.h"

struct VecArray
{
    LocalM128* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

struct MemAllocator;

struct MemRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    MemAllocator* unk10;
    MemAllocator& heap()
    {
        return *unk10;
    }
};

void* __cdecl hkMemoryRouter_getInstance();
void __cdecl hkArrayUtil__reserve(MemAllocator* alloc, VecArray* arr, int newCap, int elemSize);

static __forceinline float distanceSquared(LocalM128 a, LocalM128 b)
{
    LocalM128 v = _mm_sub_ps(a, b);
    LocalM128 d = _mm_mul_ps(v, v);
    LocalM128 yx = _mm_add_ss(_mm_shuffle_ps(d, d, 0x55), d);
    float r;
    _mm_store_ss(&r, _mm_add_ss(_mm_shuffle_ps(d, d, 0xaa), yx));
    return r;
}

// @fnv 0x00dd68d0
// src: GUESS 0x00dd68d0 (confidence: low)
void __cdecl hkMemoryRouter_getInstance_ProcessEntries_00dd68d0(float tol, VecArray* arr, int* outCount)
{
    LocalM128* cur = arr->m_data;
    int rem = arr->m_iElementCount - 1;
    LocalM128* out = arr->m_data;
    if (rem >= 0)
    {
        LocalM128* last = out - 1;
        while (rem >= 0)
        {
            LocalM128* lim = last;
            bool dup = false;
            for (; lim >= arr->m_data; --lim)
            {
                if (lim->m128_f32[0] < cur->m128_f32[0] - (double)0.01f)
                    break;
                if (distanceSquared(*lim, *cur) < tol)
                {
                    dup = true;
                    break;
                }
            }
            if (!dup)
            {
                LocalM128* dst = out;
                out++;
                last++;
                *dst = *cur;
            }
            else
            {
                for (int t = rem - 1; t >= 0; --t)
                {
                    if (!(distanceSquared(*lim, cur[1]) < tol))
                        break;
                    ++cur;
                    --rem;
                }
            }
            ++cur;
            --rem;
        }
    }
    *outCount = (int)(out - arr->m_data);
    int count = *outCount;
    MemAllocator& alloc = ((MemRouter*)hkMemoryRouter_getInstance())->heap();
    int cap = arr->m_iCapacityState & 0x3fffffff;
    if (cap < count)
    {
        int cap2 = cap * 2;
        int newCap = (count < cap2) ? cap2 : count;
        hkArrayUtil__reserve(&alloc, arr, newCap, 16);
    }
    arr->m_iElementCount = count;
}

namespace fnv_00dd6a10 {
// Exe 0x00dd62e0 FUN_00dd62e0: retain this LocalM128 view; the CRT type does not reproduce this function.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;

typedef LocalM128 Plane;

struct Triangle
{
    Plane plane;
    int v0, v1, v2;
    int unk1c;
};

struct Edge
{
    int a, b;
    Triangle* tri;
    int unk0c;
    Plane plane;

    void set(Triangle* t, int ia, int ib)
    {
        a = ia;
        b = ib;
        tri = t;
    }
};

struct Allocator
{
    virtual void* v00();
    virtual void* v04();
    virtual void* v08();
    virtual void* v0c();
    virtual void freeBlock(void* data, int size);
};

struct Holder
{
    int unk00, unk04, unk08, unk0c;
    Allocator* allocator;
    Allocator& heap()
    {
        return *allocator;
    }
};

Holder* __cdecl hkMemoryRouter_getInstance();
void __cdecl ResizeAudioStream(Allocator* allocator, void* container, int elementSize);

template <class T> __forceinline void hkConstructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T> struct Arr_00dd6a10
{
    T* data;
    int size;
    int capacity;

    __forceinline int findEdge(const Edge& e) const
    {
        int i = 0;
        if (size <= 0)
            return -1;
        for (; i < size; i++)
        {
            const T& o = data[i];
            if ((o.a == e.a && o.b == e.b) || (o.b == e.a && o.a == e.b))
                return i;
        }
        return -1;
    }
    __forceinline void AddBack(const T& v)
    {
        Holder* h = hkMemoryRouter_getInstance();
        if (size == (capacity & 0x3fffffff))
            ResizeAudioStream(h->allocator, this, sizeof(T));
        T* p = &data[size];
        if (p)
            *p = v;
        size++;
    }
    __forceinline void pushBackPlain(const T& v)
    {
        Allocator& a = hkMemoryRouter_getInstance()->heap();
        if (size == (capacity & 0x3fffffff))
            ResizeAudioStream(&a, this, sizeof(T));
        hkConstructWithCopy(data + size, 1, v);
        size++;
    }
    __forceinline void clearAndFree()
    {
        Allocator& a = hkMemoryRouter_getInstance()->heap();
        size = 0;
        if ((capacity & 0x80000000) == 0)
            a.freeBlock(data, (capacity & 0x3fffffff) * sizeof(T));
    }
};

typedef Arr_00dd6a10<Plane> PlaneArray;
typedef Arr_00dd6a10<Triangle> TriangleArray;
typedef Arr_00dd6a10<Edge> EdgeArray;

char* __cdecl hkBool_ProcessEntries_00dd66d0(char* flag, Plane* plane, PlaneArray* vertices, int a, int b, Triangle* tri,
                           TriangleArray* out);
void __cdecl Object_UpdateFields_00dd62e0(PlaneArray* vertices, int i1, int i2, int i3, Plane* out);

// @fnv 0x00dd6a10
// src: GUESS 0x00dd6a10 (confidence: low)
void __cdecl Runtime_ProcessEntries_00dd6a10(Edge* edgeIn, PlaneArray* vertices, EdgeArray* visited, PlaneArray* planes)
{
    Edge* edge = edgeIn;
    EdgeArray*& vr = visited;
    if (vr->findEdge(*edge) != -1)
        return;
    vr->AddBack(*edge);

    TriangleArray neighbours;
    neighbours.data = 0;
    neighbours.size = 0;
    neighbours.capacity = 0x80000000;
    char flag;
    if (*hkBool_ProcessEntries_00dd66d0(&flag, &edge->plane, vertices, edge->a, edge->b, edge->tri, &neighbours))
    {
        planes->pushBackPlain(neighbours.data[0].plane);

        for (int i = 0; i < neighbours.size; i++)
        {
            Edge e1;
            e1.a = neighbours.data[i].v0;
            e1.b = neighbours.data[i].v2;
            e1.tri = &neighbours.data[i];
            Object_UpdateFields_00dd62e0(vertices, e1.tri->v0, e1.tri->v2, e1.tri->v1, &e1.plane);
            Runtime_ProcessEntries_00dd6a10(&e1, vertices, vr, planes);
            Edge e2;
            e2.a = neighbours.data[i].v1;
            e2.b = neighbours.data[i].v2;
            e2.tri = &neighbours.data[i];
            Object_UpdateFields_00dd62e0(vertices, e2.tri->v1, e2.tri->v2, e2.tri->v0, &e2.plane);
            Runtime_ProcessEntries_00dd6a10(&e2, vertices, vr, planes);
        }
    }
    neighbours.clearAndFree();
}
}  // namespace fnv_00dd6a10

class __declspec(align(16)) S00dced70_Object
{
  public:
    S00dced70_Object(FinishingFlag flag);  // FUN_00d4dfc0
    void* m_ppVirtualMethodTable;
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
};

// Havok getVtable helper: build the object with the finish-loading flag and read its vtable pointer.
// @fnv 0x00dced70
// src: GUESS 0x00dced70 (confidence: medium)
const void* __cdecl Runtime_GetVtableFromTemporary_00dced70()
{
    FinishingFlag flag(0);
    S00dced70_Object kObject(flag);
    return kObject.m_ppVirtualMethodTable;
}

struct __declspec(align(16)) FUN_00dd1f00
{
    LocalM128 unk00;
    int unk10;
    float unk14;
    int unk18;
    int unk1c;
    FUN_00dd1f00(const FUN_00dd1f00& o);
};

// @fnv 0x00dd1f00
FUN_00dd1f00::FUN_00dd1f00(const FUN_00dd1f00& o)
{
    unk00 = o.unk00;
    unk10 = o.unk10;
    unk14 = o.unk14;
    unk18 = o.unk18;
    unk1c = o.unk1c;
}

namespace fnv_00dd62e0 {
// Exe 0x00dd62e0 FUN_00dd62e0: retain this LocalM128 view; the CRT type does not reproduce this function.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float f[4];
} __m128, LocalM128;
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, int);
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_sub_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_add_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_xor_ps(LocalM128, LocalM128);
extern "C" float _mm_cvtss_f32(LocalM128);
extern "C" void _mm_store_ss(float*, LocalM128);
extern const LocalM128 DAT_010c44d0;
struct VectorArray
{
    LocalM128* field_00;
};

// @fnv 0x00dd62e0
// src: GUESS 0x00dd62e0 (confidence: low)
void __cdecl Object_UpdateFields_00dd62e0(VectorArray* self, int a, int b, int c, LocalM128* out)
{
    const LocalM128& x = self->field_00[b];
    const LocalM128& y = self->field_00[a];
    LocalM128& cross = *out;
    cross = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(x, x, 0xd2), _mm_shuffle_ps(y, y, 0xc9)),
                       _mm_mul_ps(_mm_shuffle_ps(x, x, 0xc9), _mm_shuffle_ps(y, y, 0xd2)));
    LocalM128 product = _mm_mul_ps(self->field_00[c], cross);
    float dot;
    _mm_store_ss(&dot, _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa),
                                  _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product)));
    if (dot > 0.0f)
        *out = _mm_xor_ps(cross, DAT_010c44d0);
}
}  // namespace fnv_00dd62e0

inline Pair::Pair() throw() {}
inline Pair::Pair(int aa, int bb) : a(aa), b(bb) {}

static __forceinline Pair makePair(int a, int b)
{
    Pair p;
    p.a = a;
    p.b = b;
    return p;
}

static __forceinline bool operator==(const Pair& a, const Pair& b)
{
    return a.a == b.a && a.b == b.b;
}

struct Alloc_00dd6c10
{
    virtual void* v00();
    virtual void* v04();
    virtual void* v08();
    virtual void* v0c();
    virtual void freeBlock(void* data, int size);
};

struct Holder_00dd6c10
{
    int unk00, unk04, unk08, unk0c;
    Alloc_00dd6c10* allocator;
    __forceinline Alloc_00dd6c10& heap()
    {
        return *allocator;
    }
};

void* __cdecl hkMemoryRouter_getInstance();
void __cdecl ResizeAudioStream(void* allocator, void* container, int elementSize);

template <class T> struct Arr_00dd6c10
{
    T* data;
    int size;
    int capacity;
};

struct PairList_00dd6c10
{
    Pair* data;
    int size;
    int capacity;
    Pair storage[32];

    __forceinline void init()
    {
        data = storage;
        size = 0;
        capacity = 0x80000020;
    }
    __forceinline int indexOf(const Pair& t) const
    {
        for (int i = 0; i < size; i++)
        {
            if (data[i] == t)
                return i;
        }
        return -1;
    }
    __forceinline void add(const Pair& item)
    {
        Holder_00dd6c10* h = static_cast<Holder_00dd6c10*>(hkMemoryRouter_getInstance());
        if (size == (capacity & 0x3fffffff))
            ResizeAudioStream(h->allocator, this, sizeof(Pair));
        Pair* p = &data[size];
        if (p)
        {
            p->a = item.a;
            p->b = item.b;
        }
        size++;
    }
    __forceinline void _clearAndDeallocate(Alloc_00dd6c10& a)
    {
        size = 0;
        if ((capacity & 0x80000000) == 0)
            a.freeBlock(data, (capacity & 0x3fffffff) * sizeof(Pair));
    }
    __forceinline void clearAndFree()
    {
        _clearAndDeallocate(static_cast<Holder_00dd6c10*>(hkMemoryRouter_getInstance())->heap());
    }
};

typedef Arr_00dd6c10<LocalM128> VecArr_00dd6c10;

static __forceinline float dot3_00dd6c10(const LocalM128& a, const LocalM128& b)
{
    LocalM128 p = _mm_mul_ps(a, b);
    LocalM128 s = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
    float r;
    _mm_store_ss(&r, _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), s));
    return r;
}

static __forceinline LocalM128 cross_00dd6c10(LocalM128 b, LocalM128 a)
{
    return _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(b, b, 0xd2), _mm_shuffle_ps(a, a, 0xc9)),
                      _mm_mul_ps(_mm_shuffle_ps(b, b, 0xc9), _mm_shuffle_ps(a, a, 0xd2)));
}
static __forceinline LocalM128 cross2_00dd6c10(LocalM128 a, LocalM128 b)
{
    LocalM128 t0 = _mm_mul_ps(_mm_shuffle_ps(b, b, 0xc9), _mm_shuffle_ps(a, a, 0xd2));
    LocalM128 t1 = _mm_mul_ps(_mm_shuffle_ps(b, b, 0xd2), _mm_shuffle_ps(a, a, 0xc9));
    return _mm_sub_ps(t1, t0);
}
__forceinline void hkVector4q::setCross(const hkVector4q& v1, const hkVector4q& v2)
{
    LocalM128 positive = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                                 _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
    LocalM128 negative = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                                 _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
    m_vComponents = _mm_sub_ps(positive, negative);
}
static __forceinline bool lt_00dd6c10(const float& a, const float& b)
{
    return a < b;
}
static __forceinline bool gt_00dd6c10(const float& a, const float& b)
{
    return a > b;
}
extern float DAT_0104e148;
extern const float DAT_010c8440 = -1.1920929e-07f;

extern "C" LocalM128 _mm_load_ss(const float*);
extern "C" LocalM128 _mm_add_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_xor_ps(LocalM128, LocalM128);
extern const float DAT_010b9be8;
extern const LocalM128 DAT_010c44d0;
struct PlanePoint
{
    LocalM128 position;
    int plane0, plane1, plane2, unk1c;
    __forceinline void copyPlanes(const PlanePoint& other)
    {
        plane0 = other.plane0;
        plane1 = other.plane1;
        plane2 = other.plane2;
    }
};
int __cdecl Object_ProcessAndReturnValue_00dd6380(VecArr_00dd6c10* vectors, int first, int second, int third, PlanePoint* point);
// src: GUESS 0x00dd6510 (confidence: low)
__declspec(noinline) int __cdecl hkVector4_ProcessEntries_00dd6510(const LocalM128* normal, VecArr_00dd6c10* vectors, int first, int second,
                                              PlanePoint* lower, PlanePoint* upper)
{
    lower->plane0 = lower->plane1 = lower->plane2 = -1;
    upper->plane0 = upper->plane1 = upper->plane2 = -1;
    bool initialized = false;
    for (int i = 0; i < vectors->size; ++i)
    {
        if (i == first || i == second)
            continue;
        PlanePoint point;
        if (Object_ProcessAndReturnValue_00dd6380(vectors, first, second, i, &point) != 0)
            continue;
        if (!initialized)
        {
            LocalM128 scale = _mm_load_ss(&DAT_010b9be8);
            scale = _mm_shuffle_ps(scale, scale, 0);
            upper->position = _mm_add_ps(_mm_mul_ps(scale, *normal), point.position);
            lower->position = _mm_xor_ps(upper->position, DAT_010c44d0);
            initialized = true;
        }
        float topDistance = dot3_00dd6c10(_mm_sub_ps(upper->position, point.position), vectors->data[i]);
        if (topDistance > DAT_010c8440)
        {
            upper->position = point.position;
            upper->copyPlanes(point);
        }
        float bottomDistance = dot3_00dd6c10(_mm_sub_ps(lower->position, point.position), vectors->data[i]);
        if (bottomDistance > DAT_010c8440)
        {
            lower->position = point.position;
            lower->copyPlanes(point);
        }
    }
    if (lower->plane0 == -1)
    {
        if (upper->plane0 == -1)
            return 1;
        lower->copyPlanes(*upper);
    }
    if (upper->plane0 == -1)
    {
        if (lower->plane0 == -1)
            return 1;
        upper->copyPlanes(*lower);
    }
    return 0;
}

// @fnv 0x00dd6c10
// src: GUESS 0x00dd6c10 (confidence: low)
int __cdecl hkVector4q_ProcessEntries_00dd6c10(VecArr_00dd6c10* vectors, int* first, int* second, PlanePoint* q, PlanePoint* p)
{
    PairList_00dd6c10 visited;
    visited.init();
    hkVector4q normal;
    for (;;)
    {
        float best = DAT_0104e148;
        Pair bestPair = makePair(-1, -1);
        for (int i = 0; i < vectors->size; i++)
        {
            for (int j = i + 1; j < vectors->size; j++)
            {
                float score = dot3_00dd6c10(vectors->data[i], vectors->data[j]);
                if (score > best && score < 0.8999999761581421 && visited.indexOf(makePair(i, j)) == -1)
                {
                    best = score;
                    *first = i;
                    *second = j;
                    bestPair = makePair(i, j);
                }
            }
        }
        if (bestPair.a == -1)
        {
            visited.clearAndFree();
            return 1;
        }
        visited.add(bestPair);
        normal.setCross(reinterpret_cast<const hkVector4q&>(vectors->data[*first]),
                        reinterpret_cast<const hkVector4q&>(vectors->data[*second]));
        if (hkVector4_ProcessEntries_00dd6510(&normal.m_vComponents, vectors, *first, *second, p, q) == 1)
        {
            visited.clearAndFree();
            return 1;
        }
        LocalM128 dm = _mm_mul_ps(_mm_sub_ps(p->position, q->position), normal.m_vComponents);
        float d;
        _mm_store_ss(&d, _mm_add_ss(_mm_shuffle_ps(dm, dm, 0xaa), _mm_add_ss(_mm_shuffle_ps(dm, dm, 0x55), dm)));
        if (gt_00dd6c10(d, DAT_010c8440))
            break;
    }
    visited.clearAndFree();
    return 0;
}
