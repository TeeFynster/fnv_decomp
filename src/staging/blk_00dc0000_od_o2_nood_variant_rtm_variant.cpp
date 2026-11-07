// src/staging/blk_00dc0000_od_o2_nood_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/staging/blk_00dc0000_od_o2_nood_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/staging/blk_00dc0000_od_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_moves.py: the bytes and the matched neighbours of these functions
// say /MT /O2 /GS /EHsc /Gy (unit src/staging/blk_00dc0000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions to their real
// unit once identified.
// src/staging/blk_00dc0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
#include "../../include/FinishingFlag.h"
// Keep the intrinsic storage view without CRT byte lanes, which change VC9 /GS code generation.
#define _INCLUDED_MM2
// Exe 0x00ddd2c0 FUN_00ddd2c0: retain this LocalM128 view; the CRT type does not preserve this unit.
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
void __cdecl hkMemoryRouter_getInstance_ProcessEntries_00dd68d0(float tol, VecArray* arr, int* outCount);
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
const void* __cdecl Runtime_GetVtableFromTemporary_00dced70();
struct __declspec(align(16)) FUN_00dd1f00
{
    LocalM128 unk00;
    int unk10;
    float unk14;
    int unk18;
    int unk1c;
    FUN_00dd1f00(const FUN_00dd1f00& o);
};
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
            if (data[i].a == t.a && data[i].b == t.b)
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
int __cdecl hkVector4q_ProcessEntries_00dd6c10(VecArr_00dd6c10* vectors, int* first, int* second, PlanePoint* q, PlanePoint* p);

extern "C" double __cdecl fabs(double);
#pragma intrinsic(fabs)
inline float fabsf(float x)
{
    return (float)fabs((double)x);
}
extern "C" LocalM128 _mm_mul_ss(LocalM128, LocalM128);

extern float DAT_0104da48;

struct TriangleProjectionData
{
    LocalM128 edge0;
    LocalM128 edge1;
    LocalM128 vertices[3];
};

// @fnv 0x00ddd2c0
// src: GUESS 0x00ddd2c0 (confidence: low)
int __cdecl Object_ProcessEntries_00ddd2c0(const LocalM128* origin, const LocalM128* firstAxis, const LocalM128* secondAxis,
                         const TriangleProjectionData* triangle, const LocalM128* direction)
{
    float maximum = DAT_0104e148;
    const LocalM128* entry = origin;
    const LocalM128 center = *entry;
    entry = firstAxis;
    const LocalM128 axis = *entry;
    entry = triangle->vertices;
    const LocalM128* begin = entry;
    float minimum = DAT_0104da48;
    const LocalM128* vertex = begin;
    int remaining = 3;
    do
    {
        LocalM128 p = _mm_mul_ps(_mm_sub_ps(*vertex, center), axis);
        LocalM128 y = _mm_shuffle_ps(p, p, 0x55);
        LocalM128 z = _mm_shuffle_ps(p, p, 0xAA);
        y = _mm_add_ss(y, p);
        z = _mm_add_ss(z, y);
        float projection;
        _mm_store_ss(&projection, z);
        if (projection > maximum)
            maximum = projection;
        if (projection < minimum)
            minimum = projection;
        ++vertex;
    } while (remaining-- != 1);

    if (maximum > 0.01f || minimum < 0.01f)
    {
        if (maximum > 0.20000000298023224 && minimum < 0.20000000298023224)
            return 0;
        int useDirection = 1;
        if (!(fabsf(maximum) > fabsf(minimum)))
            useDirection = 0;
        float scale = (float)useDirection;
        LocalM128 p = _mm_mul_ps(*secondAxis, *direction);
        LocalM128 y = _mm_shuffle_ps(p, p, 0x55);
        LocalM128 z = _mm_shuffle_ps(p, p, 0xAA);
        y = _mm_add_ss(y, p);
        z = _mm_add_ss(z, y);
        z = _mm_mul_ss(z, _mm_load_ss(&scale));
        float directedProjection;
        _mm_store_ss(&directedProjection, z);
        if (directedProjection < 0.0f)
            return 1;
    }

    float secondMaximum = DAT_0104e148;
    float secondMinimum = DAT_0104da48;
    vertex = begin;
    remaining = 3;
    do
    {
        LocalM128 p = _mm_mul_ps(_mm_sub_ps(*vertex, center), *secondAxis);
        LocalM128 y = _mm_shuffle_ps(p, p, 0x55);
        LocalM128 z = _mm_shuffle_ps(p, p, 0xAA);
        y = _mm_add_ss(y, p);
        z = _mm_add_ss(z, y);
        float projection;
        _mm_store_ss(&projection, z);
        if (projection > secondMaximum)
            secondMaximum = projection;
        if (projection < secondMinimum)
            secondMinimum = projection;
        ++vertex;
    } while (remaining-- != 1);

    if (!(secondMaximum > 0.01f || secondMinimum < 0.01f))
        return 0;
    if (secondMaximum > 0.20000000298023224 && secondMinimum < 0.20000000298023224)
        return 0;
    int useDirection = 1;
    if (!(fabsf(secondMaximum) > fabsf(secondMinimum)))
        useDirection = 0;
    float scale = (float)useDirection;
    LocalM128 p = _mm_mul_ps(*firstAxis, *direction);
    LocalM128 y = _mm_shuffle_ps(p, p, 0x55);
    LocalM128 z = _mm_shuffle_ps(p, p, 0xAA);
    y = _mm_add_ss(y, p);
    z = _mm_add_ss(z, y);
    z = _mm_mul_ss(z, _mm_load_ss(&scale));
    float directedProjection;
    _mm_store_ss(&directedProjection, z);
    if (directedProjection > 0.0f)
        return 1;
    return 0;
}
