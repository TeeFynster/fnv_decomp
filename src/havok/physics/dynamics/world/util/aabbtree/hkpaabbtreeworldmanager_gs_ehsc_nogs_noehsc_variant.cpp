
// src/havok/physics/dynamics/world/util/aabbtree/hkpaabbtreeworldmanager_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-30 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/dynamics/world/util/aabbtree/hkpaabbtreeworldmanager.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/dynamics/world/util/aabbtree/hkpaabbtreeworldmanager.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/util/aabbtree/hkpaabbtreeworldmanager.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkArray.h"
#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../include/hkpBroadPhaseCastCollector.h"
#include "../../../../../../../include/hkpCollidableCollidableFilter.h"
#include "../../../../../../../include/hkpCollidable.h"
#include "../../../../../../../include/hkpCollisionFilter.h"
#include "../../../../../../../include/hkpEntity.h"
#include "../../../../../../../include/hkpRayCollidableFilter.h"
#include "../../../../../../../include/hkpShape.h"

// This flag variant only defines the tree-building function below; unused declarations from
// the parent unit are supplied by the shared headers rather than partial local classes.
extern unsigned int DAT_0126835c;
extern char DAT_010c41f8[];
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc();
extern "C" void _ReadWriteBarrier();
void __cdecl DispatchToOffsetTarget(hkpCollidable* collidable, unsigned short value);
inline hkMemoryAllocator& getTreeBuildHeap(hkMemoryRouter& router)
{
    return *reinterpret_cast<hkMemoryAllocator*>(router.m_heap);
}

#include <xmmintrin.h>
extern const float DAT_01011d78;
extern const __m128 DAT_010c7170;

struct S00d09020_Vec
{
    __m128 m_vComponents;
    void mul(const S00d09020_Vec& b)
    {
        m_vComponents = _mm_mul_ps(m_vComponents, b.m_vComponents);
    }
    void mulR(const S00d09020_Vec& b)
    {
        m_vComponents = _mm_mul_ps(b.m_vComponents, m_vComponents);
    }
    void sub(const S00d09020_Vec& b)
    {
        m_vComponents = _mm_sub_ps(m_vComponents, b.m_vComponents);
    }
    void SetProduct(const S00d09020_Vec& a, const S00d09020_Vec& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
};

struct S00d09020_Aabb
{
    S00d09020_Vec m_kMinimumCorner;
    S00d09020_Vec m_kMaximumCorner;
};

template <typename T, typename Allocator>
__forceinline hkArray<T, Allocator>::~hkArray()
{
    hkMemoryAllocator& a = getTreeBuildHeap(hkMemoryRouter::getInstance());
    this->m_iElementCount = 0;
    if ((this->m_iCapacityState & 0x80000000) == 0)
        a.bufFree(this->m_data, (this->m_iCapacityState & 0x3fffffff) * sizeof(T));
    this->m_data = 0;
    this->m_iCapacityState = 0x80000000;
}

template <typename T>
__forceinline void hkArrayBase<T>::GrowArrayCapacity(hkMemoryAllocator& a, int n)
{
    int cap = this->m_iCapacityState & 0x3fffffff;
    if (cap < n)
    {
        int c = cap * 2;
        hkArrayUtil::_reserve(a, this, n < c ? c : n, sizeof(T));
    }
}

template <typename T>
__forceinline void hkArrayBase<T>::_setSize(hkMemoryAllocator& a, int n)
{
    GrowArrayCapacity(a, n);
    this->m_iElementCount = n;
}

// Stack-backed tree-build scratch storage: the original uses hkMemoryRouter::a as a LIFO arena,
// rounded to 128 bytes, and an ordinary hkArray for fallback heap allocation.
template <class T> struct TreeBuildScratchArray : public hkArray<T>
{
    T* m_pStackAllocation;
    TreeBuildScratchArray(int n)
    {
        hkMemoryRouter& r = hkMemoryRouter::getInstance();
        char* top = (char*)r.m_stack.m_next.m_storage;
        r.m_stack.m_next.m_storage = top + ((n * sizeof(T) + 0x7f) & ~0x7f);
        this->m_data = (T*)top;
        this->m_iCapacityState = n | 0x80000000;
        m_pStackAllocation = (T*)top;
    }
    ~TreeBuildScratchArray()
    {
        T* mem = m_pStackAllocation;
        if (mem == this->m_data)
            this->m_iElementCount = 0;
        hkMemoryRouter::getInstance().m_stack.m_next.m_storage = mem;
    }
};

struct S00d09020_Builder
{
    void hkAabbTree_hkAabbTreeData_hkAabbTreeAabb16_unsigned_short_build(S00d09020_Aabb* aabbs, hkpCollidable** elems, int n, hkArray<unsigned short>* out);
};

struct D090Rows
{
    S00d09020_Vec m_offset;
    S00d09020_Vec m_unused;
    S00d09020_Vec m_vScale;
};
struct D090Phase
{
    S00d09020_Vec m_pHeadNode;
    S00d09020_Vec m_iSecondInteger;
    D090Rows m_rows;
};
struct S00d09020_Inner
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74;
    D090Phase* m_78;
};

__forceinline void S00d09020_trace(const char* tag, volatile unsigned int& ticks)
{
    hkMonitorStream* s = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    hkMonitorStream::TimerCommand* e = (hkMonitorStream::TimerCommand*)s->m_end.m_storage;
    if (e < (hkMonitorStream::TimerCommand*)s->m_capacityMinus16.m_storage)
    {
        e->m_commandAndMonitor = tag;
        _ReadWriteBarrier();
        ticks = (unsigned int)__rdtsc();
        e->m_time0 = ticks;
        s->m_end.m_storage = (char*)e + 12;
    }
}

__forceinline void S00d09020_set(S00d09020_Vec& v, float x, float y, float z, float w)
{
    v.m_vComponents = _mm_setr_ps(x, y, z, w);
}

struct S00d09020_This
{
    int unk00;
    int unk04;
    int unk08;
    S00d09020_Builder* m_builder;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    S00d09020_Inner* m_inner;
    void hkpAabbTreeWorldManager_buildInactiveTree(hkArray<hkpCollidable*>* arg, int p2, int p3);
};

// @fnv 0x00d09020
// src: XBOX_PDB 0x00d09020
void S00d09020_This::hkpAabbTreeWorldManager_buildInactiveTree(hkArray<hkpCollidable*>* arg, int p2, int p3)
{
    union BuilderTime
    {
        S00d09020_Builder* ptr;
        volatile unsigned int tick;
    } builder;
    builder.ptr = m_builder;
    volatile unsigned int timestamp;
    int n = arg->m_iElementCount;

    TreeBuildScratchArray<S00d09020_Aabb> aabbs(n);
    aabbs._setSize(getTreeBuildHeap(hkMemoryRouter::getInstance()), n);
    TreeBuildScratchArray<hkpCollidable*> elems(n);
    elems._setSize(getTreeBuildHeap(hkMemoryRouter::getInstance()), n);

    {
        hkMonitorStream* s = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
        hkMonitorStream::TimerCommand* e = (hkMonitorStream::TimerCommand*)s->m_end.m_storage;
        if (e < (hkMonitorStream::TimerCommand*)s->m_capacityMinus16.m_storage)
        {
            e->m_commandAndMonitor = "Ttprepare";
            _ReadWriteBarrier();
            timestamp = (unsigned int)__rdtsc();
            e->m_time0 = timestamp;
            s->m_end.m_storage = (char*)(e + 1);
        }
    }
    const D090Rows& xf = m_inner->m_78->m_rows;
    for (int i = 0; i < n; i++)
    {
        // Quantized bounds occupy two 16-byte rows, including their packed expansion bytes.
        const unsigned int* q = reinterpret_cast<const unsigned int*>(&arg->m_data[i]->m_kBoundingVolumeData);
        S00d09020_Aabb* base = aabbs.m_data;
        if (q[0] <= q[4])
        {
            S00d09020_Aabb* out = &base[i];
            S00d09020_Vec retained;
            S00d09020_set(retained, (float)q[0], (float)q[1], (float)q[2], 0.0f);
            out->m_kMinimumCorner.m_vComponents = retained.m_vComponents;
            S00d09020_set(out->m_kMaximumCorner, (float)q[4], (float)q[5], (float)q[6], 0.0f);
            __m128 scale = xf.m_vScale.m_vComponents;
            __m128 t = _mm_shuffle_ps(scale, _mm_unpackhi_ps(scale, DAT_010c7170), 0xc4);
            __m128 r = _mm_rcp_ps(t);
            __m128 inv = _mm_sub_ps(_mm_add_ps(r, r), _mm_mul_ps(_mm_mul_ps(r, t), r));
            __m128 product = inv;
            product = _mm_mul_ps(product, retained.m_vComponents);
            out->m_kMinimumCorner.m_vComponents = product;
            S00d09020_Vec* hi = (S00d09020_Vec*)out + 1;
            hi->m_vComponents = _mm_mul_ps(hi->m_vComponents, inv);
            out->m_kMinimumCorner.m_vComponents =
                _mm_sub_ps(_mm_load_ps((const float*)&out->m_kMinimumCorner), xf.m_offset.m_vComponents);
            out->m_kMaximumCorner.sub(xf.m_offset);
        }
        else
        {
            arg->m_data[i]->m_pCollisionShape->CalculateAabb(
                arg->m_data[i]->getTransform(), 0.0f, reinterpret_cast<hkAabb&>(base[i]));
        }
        elems.m_data[i] = arg->m_data[i];
    }
    {
        hkMonitorStream* s = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
        hkMonitorStream::TimerCommand* e = (hkMonitorStream::TimerCommand*)s->m_end.m_storage;
        if (e < (hkMonitorStream::TimerCommand*)s->m_capacityMinus16.m_storage)
        {
            e->m_commandAndMonitor = DAT_010c41f8;
            _ReadWriteBarrier();
            timestamp = (unsigned int)__rdtsc();
            e->m_time0 = timestamp;
            s->m_end.m_storage = (char*)(e + 1);
        }
    }

    hkArray<unsigned short> ids;
    {
        hkMonitorStream* s = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
        hkMonitorStream::TimerCommand* e = (hkMonitorStream::TimerCommand*)s->m_end.m_storage;
        if (e < (hkMonitorStream::TimerCommand*)s->m_capacityMinus16.m_storage)
        {
            e->m_commandAndMonitor = "Ttbuild";
            _ReadWriteBarrier();
            timestamp = (unsigned int)__rdtsc();
            e->m_time0 = timestamp;
            s->m_end.m_storage = (char*)(e + 1);
        }
    }
    if (n > 0)
        builder.ptr->hkAabbTree_hkAabbTreeData_hkAabbTreeAabb16_unsigned_short_build(aabbs.m_data, elems.m_data, n, &ids);
    {
        hkMonitorStream* s = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
        hkMonitorStream::TimerCommand* e = (hkMonitorStream::TimerCommand*)s->m_end.m_storage;
        if (e < (hkMonitorStream::TimerCommand*)s->m_capacityMinus16.m_storage)
        {
            e->m_commandAndMonitor = DAT_010c41f8;
            _ReadWriteBarrier();
            builder.tick = (unsigned int)__rdtsc();
            e->m_time0 = builder.tick;
            s->m_end.m_storage = (char*)(e + 1);
        }
    }

    for (int j = 0; j < n; j++)
        DispatchToOffsetTarget(arg->m_data[j], ids.m_data[j]);
}
