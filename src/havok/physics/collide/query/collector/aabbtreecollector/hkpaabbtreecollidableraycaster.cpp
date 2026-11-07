
// src/havok/physics/collide/query/collector/aabbtreecollector/hkpaabbtreecollidableraycaster.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/query/collector/aabbtreecollector/hkpaabbtreecollidableraycaster.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct hkpAabbTreeCollidableRaycaster
{
    void CollectRayHit(int);
    float addLeaf(int);
};
// @fnv 0x00d9a220
// src: HAVOK_LIB 0x00d9a220
float hkpAabbTreeCollidableRaycaster::addLeaf(int a)
{
    CollectRayHit(*(int*)(a + 0x20));
    return *(float*)((char*)this + 0x1c);
}

namespace fnv_00d9a240 {
struct hkpAabbTreeCollidableRaycaster
{
    void __thiscall CollectRayHit(void*);
    float __thiscall addLeaf_00d9a240(void* arg);
};
// @fnv 0x00d9a240
// src: HAVOK_LIB 0x00d9a240
float __thiscall hkpAabbTreeCollidableRaycaster::addLeaf_00d9a240(void* arg)
{
    ((hkpAabbTreeCollidableRaycaster*)((char*)this - 4))->CollectRayHit(*(void**)((char*)arg + 12));
    return *(float*)((char*)this + 0x18);
}
}  // namespace fnv_00d9a240

#include <xmmintrin.h>
struct FnvRayInput
{
    __m128 from;
    __m128 to;
    float unk20;
    int fraction;
};
struct FnvTransform
{
    __m128 axisX;
    __m128 axisY;
    __m128 axisZ;
    __m128 origin;
};
__declspec(align(16)) struct FnvQuery
{
    FnvQuery() : fraction(0), filterScale(0)
    {}
    float startX, startY, startZ, startW;
    float endX, endY, endZ, endW;
    int fraction;
    void* filterScale;
};
struct FnvHit
{
    __m128 position;
    float fraction;
    int unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30;
    int unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    int* object;
};
struct FnvExistingHit
{
    int unk00;
    float fraction;
};
struct FnvFilter
{
    virtual void ReportDiagnostic();
    virtual unsigned char* accepts(unsigned char*, FnvRayInput*, int*);
};
struct FnvRayNode
{
    virtual void ReportDiagnostic();
    virtual void unused1();
    virtual void unused2();
    virtual void FlushUsageData();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void collect(unsigned char*, FnvQuery*, FnvHit*);
    virtual void update(FnvQuery*, int*, FnvExistingHit*);
};

static __forceinline __m128 inversePoint(__m128 v, const FnvTransform* t)
{
    __m128 d = _mm_sub_ps(v, t->origin);
    __m128 a = t->axisX, b = t->axisY, c = t->axisZ;
    __m128 low = _mm_unpacklo_ps(a, b), high = _mm_unpackhi_ps(a, b);
    a = _mm_movelh_ps(low, c);
    b = _mm_shuffle_ps(_mm_movehl_ps(a, low), c, 0xd4);
    c = _mm_shuffle_ps(high, c, 0xe4);
    __m128 y = _mm_mul_ps(b, _mm_shuffle_ps(d, d, 0x55));
    __m128 x = _mm_mul_ps(a, _mm_shuffle_ps(d, d, 0));
    __m128 z = _mm_mul_ps(c, _mm_shuffle_ps(d, d, 0xaa));
    return _mm_add_ps(_mm_add_ps(y, x), z);
}

struct FnvRaycasterState
{
    int unk00;
    int unk04;
    FnvRayInput* ray;
    FnvFilter* filter;
    void* filterScale;
    FnvHit* hit;
    FnvExistingHit* existingHit;
    float fraction;
};

// If the filter accepts, transforms the ray into the source's space and calls node->update or node->collect, rotating a collected hit position back.
// @fnv 0x00d9a070
void hkpAabbTreeCollidableRaycaster::CollectRayHit(int request)
{
    FnvRaycasterState* st = (FnvRaycasterState*)this;
    int* source = (int*)request;
    FnvRayNode* node = (FnvRayNode*)source[0];
    if (!node)
        return;
    unsigned char accepted;
    if (st->filter && !*st->filter->accepts(&accepted, st->ray, source))
        return;
    FnvTransform* t = (FnvTransform*)source[2];
    FnvQuery query;
    _mm_store_ps(&query.startX, inversePoint(st->ray->from, t));
    _mm_store_ps(&query.endX, inversePoint(st->ray->to, t));
    query.fraction = st->ray->fraction;
    query.filterScale = st->filterScale;
    if (st->existingHit)
    {
        node->update(&query, source, st->existingHit);
        st->fraction = st->existingHit->fraction;
        return;
    }
    node->collect(&accepted, &query, st->hit);
    if (accepted)
    {
        st->hit->object = source;
        __m128 v = st->hit->position;
        __m128 y = _mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), t->axisY);
        __m128 x = _mm_mul_ps(_mm_shuffle_ps(v, v, 0), t->axisX);
        __m128 z = _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), t->axisZ);
        st->hit->position = _mm_add_ps(_mm_add_ps(y, x), z);
        st->fraction = st->hit->fraction;
    }
}

// sub ecx,4; jmp target  ==  MSVC adjustor thunk for a virtual overridden in a class with two bases.
struct PrimaryBaseA
{
    virtual void AdjustThisAndForward_00d9a260();
};

struct SecondaryBaseA
{
    virtual void AdjustThisAndForward_00d9a260();
};

struct DerivedA : PrimaryBaseA, SecondaryBaseA
{
    DerivedA();
// @fnv 0x00d9a260
// src: GUESS 0x00d9a260 (confidence: low)
    virtual void AdjustThisAndForward_00d9a260();
};

DerivedA::DerivedA()
{}

struct S_00d9a270_Heap
{
    virtual void unk0();
    virtual void unk4();
    virtual void ReleaseBlock(void* p, int nbytes);
};

struct S_00d9a270_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00d9a270_Heap* m_pStreamAllocator;
    static S_00d9a270_Router* hkMemoryRouter_getInstance();
    S_00d9a270_Heap& heap()
    {
        return *m_pStreamAllocator;
    }
};

struct S_00d9a270_Base
{
    virtual ~S_00d9a270_Base()
    {}
    void operator delete(void* p, unsigned int nbytes)
    {
        S_00d9a270_Router::hkMemoryRouter_getInstance()->heap().ReleaseBlock(p, nbytes);
    }
};

struct S_00d9a270_Second
{
    virtual void unk0();
};

struct FUN_00d9a270 : S_00d9a270_Base, S_00d9a270_Second
{
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    FUN_00d9a270();
    // Empty virtual destructor for FUN_00d9a270, which inherits from S_00d9a270_Base and S_00d9a270_Second.
// @fnv 0x00d9a270
    virtual ~FUN_00d9a270()
    {}
};

FUN_00d9a270::FUN_00d9a270()
{}
