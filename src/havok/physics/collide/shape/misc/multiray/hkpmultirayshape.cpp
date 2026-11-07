
// src/havok/physics/collide/shape/misc/multiray/hkpmultirayshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/misc/multiray/hkpmultirayshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Keep this unit's original intrinsic representation; the CRT union's byte arrays add /GS instrumentation.
// Exe 0x00e3c800 CalculateAabb: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C"
{
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_min_ps(LocalM128, LocalM128);
    LocalM128 _mm_max_ps(LocalM128, LocalM128);
    LocalM128 _mm_set_ps1(float);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_sub_ss(LocalM128, LocalM128);
    LocalM128 _mm_mul_ss(LocalM128, LocalM128);
    LocalM128 _mm_sqrt_ss(LocalM128);
    LocalM128 _mm_rsqrt_ss(LocalM128);
    LocalM128 _mm_set_ss(float);
    LocalM128 _mm_andnot_ps(LocalM128, LocalM128);
    LocalM128 _mm_cmpeq_ss(LocalM128, LocalM128);
    LocalM128 _mm_load_ps1(float const*);
    void _mm_store_ss(float*, LocalM128);
}

#include "../../../../../../../include/hkpMultiRayShape.h"
#include "../../../../../../../include/hkpShape.h"
#include "../../../../../../../include/hkArray.h"
#include "../../../../../../../include/hkStatisticsCollector.h"
#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/hkAabb.h"
#include "../../../../../../../include/hkTransform.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkMemoryRouter.h"

// FUN_00e3c610: stores zero byte through first stdcall argument and returns it.

// @fnv 0x00e3c610
// src: XBOX_PDB 0x00e3c610
unsigned char* __stdcall hkpMultiRayShape_castRayImpl(unsigned char* out, int a1, int a2)
{
    *out = 0;
    return out;
}

// @fnv 0x00e3c600
// src: COMMUNITY 0x00e3c600
void __stdcall nullsub_86(int a1, int a2, int a3)
{}

extern const hkClass DAT_01268910;

int __cdecl hkStatisticsCollector_getAllocatedSize(const void* pvChunk, int iNumBytes) throw();

// The shared shape header has no multi-ray overrides; this adapter adds declarations, with no data of its own.
class MultiRayShapeOperations : public hkpMultiRayShape
{
  public:
    virtual void calcContentStatistics(hkStatisticsCollector* collector, const hkClass* cls) const;
    virtual void CalculateAabb(const hkTransform& localToWorld, hkReal tolerance, hkAabb& out) const;
};

template <class T> static __forceinline void addArray(hkStatisticsCollector* collector, const char* name, const hkArray<T>& array)
{
    if ((array.m_iCapacityState & 0x80000000) == 0 || collector->m_reportInplaceAllocations)
    {
        const T* pData = array.m_data;
        int iAllocated = hkStatisticsCollector_getAllocatedSize(pData, array.getCapacity() * sizeof(T));
        collector->AddMemoryChunk(3, name, array.m_data, array.GetLogicalSize() * sizeof(T), iAllocated);
    }
}

// Adds the Rays array to the statistics collector, then reports the base shape's statistics with the class descriptor.
// @fnv 0x00e3c620
void MultiRayShapeOperations::calcContentStatistics(hkStatisticsCollector* pkCollector, const hkClass* pkClass) const
{
    addArray(pkCollector, "Rays", m_kRays);
    hkReferencedObject::calcContentStatistics(pkCollector, &DAT_01268910);
}

extern float DAT_0104da48;
extern float DAT_0104e148;



extern "C" hkMemoryRouter* hkMemoryRouter_getInstance() throw();
void __cdecl hkArrayUtil__reserve(hkMemoryAllocator* alloc, void* array, int reqCapacity, int elemSize) throw();

__forceinline hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return hkMemoryRouter_getInstance()->heap();
}

template <class T> __forceinline void hkArrayBase<T>::GrowArrayCapacity(hkMemoryAllocator& alloc, int n)
{
    const int cap = getCapacity();
    if (cap < n)
    {
        int cap2 = 2 * cap;
        int newSize = (n < cap2) ? cap2 : n;
        hkArrayUtil__reserve(&alloc, this, newSize, sizeof(T));
    }
}

template <class T> __forceinline void hkArrayBase<T>::_setSize(hkMemoryAllocator& alloc, int n)
{
    GrowArrayCapacity(alloc, n);
    m_iElementCount = n;
}

template <class T> __forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& alloc)
{
    m_iElementCount = 0;
    if ((m_iCapacityState & 0x80000000) == 0)
        alloc.bufFree(m_data, getCapacity() * sizeof(T));
}

template <class T, class A> __forceinline hkArray<T, A>::~hkArray()
{
    clearAndDeallocate();
}

// A scratch ray stores two native SIMD registers; persistent shape rays use hkpMultiRayShape::Ray.
struct __declspec(align(16)) WorldRayRegisters
{
    LocalM128 start;
    LocalM128 end;
};

struct WorldRayScratch : hkArrayBase<WorldRayRegisters>
{
    WorldRayRegisters storage[16];
    __forceinline WorldRayScratch()
    {
        m_data = storage;
        m_iElementCount = 0;
        m_iCapacityState = 0x80000010;
    }
    __forceinline void SetSizeAndGrow(int n) { _setSize(hkMemoryRouter_getInstance()->heap(), n); }
};

static __forceinline LocalM128 loadQuadWords(const void* vector)
{
    union { LocalM128 quad; unsigned int words[4]; } copy;
    const unsigned int* words = static_cast<const unsigned int*>(vector);
    copy.words[0] = words[0];
    copy.words[1] = words[1];
    copy.words[2] = words[2];
    copy.words[3] = words[3];
    return copy.quad;
}

static __forceinline void TransformPointArray(const hkTransform& t, const LocalM128* vectorsIn, int numVectors,
                                              LocalM128* vectorsOut)
{
    const LocalM128 q0 = loadQuadWords(&t.m_kColumn0);
    const LocalM128 q1 = loadQuadWords(&t.m_kColumn1);
    const LocalM128 q2 = loadQuadWords(&t.m_kColumn2);
    const LocalM128 RunFourthVirtual = loadQuadWords(&t.m_vTranslation);
    int i = numVectors - 1;
    do
    {
        LocalM128 b = vectorsIn[i];
        LocalM128 b0 = _mm_shuffle_ps(b, b, 0x00);
        LocalM128 b1 = _mm_shuffle_ps(b, b, 0x55);
        LocalM128 b2 = _mm_shuffle_ps(b, b, 0xaa);
        LocalM128 r0 = _mm_mul_ps(b0, q0);
        LocalM128 r1 = _mm_mul_ps(b1, q1);
        LocalM128 r2 = _mm_mul_ps(b2, q2);
        vectorsOut[i] = _mm_add_ps(_mm_add_ps(r1, r0), _mm_add_ps(r2, RunFourthVirtual));
        i--;
    } while (i >= 0);
}

// Transforms the shape's rays into world space and computes their combined axis-aligned bounding box into out.
// @fnv 0x00e3c800
void MultiRayShapeOperations::CalculateAabb(const hkTransform& localToWorld, hkReal tolerance, hkAabb& out) const
{
    WorldRayScratch worldRays;
    worldRays.SetSizeAndGrow(m_kRays.m_iElementCount);
    TransformPointArray(localToWorld, reinterpret_cast<const LocalM128*>(m_kRays.m_data), m_kRays.m_iElementCount * 2,
                        &worldRays.m_data[0].start);

    LocalM128 mn = _mm_set_ps1(DAT_0104da48);
    LocalM128 mx = _mm_set_ps1(DAT_0104e148);
    const WorldRayRegisters* ray = worldRays.m_data;
    for (int i = 0; i < worldRays.m_iElementCount; i++, ray++)
    {
        mn = _mm_min_ps(mn, ray->end);
        mx = _mm_max_ps(mx, ray->end);
        mn = _mm_min_ps(mn, ray->start);
        mx = _mm_max_ps(mx, ray->start);
    }
    out.m_kMinimumCorner.m_vComponents = mn;
    out.m_kMaximumCorner.m_vComponents = mx;
    worldRays._clearAndDeallocate(hkMemoryRouter_getInstance()->heap());
}

template <class T> __forceinline T* hkArrayBase<T>::_expandBy(hkMemoryAllocator& alloc, int n)
{
    int oldsize = m_iElementCount;
    GrowArrayCapacity(alloc, oldsize + n);
    m_iElementCount += n;
    return m_data + oldsize;
}

template <class E, class S> __forceinline hkEnum<E, S>::hkEnum(E value) : m_kStorage(value) {}
__forceinline hkpShape::hkpShape(hkpShapeType type) : m_ulUserData(0), m_type(type) {}

static inline LocalM128 dot3(LocalM128 a)
{
    LocalM128 x2 = _mm_mul_ps(a, a);
    LocalM128 s = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), s);
}

// Copies rays, computes their length, normalizes the direction, and extends the end by m_fRayRadius.
// @fnv 0x00e3c680
hkpMultiRayShape::hkpMultiRayShape(const Ray* rays, int nRays, float rayPenetrationDistance) : hkpShape(static_cast<hkpShapeType>(0x18))
{
    m_fRayRadius = rayPenetrationDistance;
    hkpMultiRayShape::Ray* ray = m_kRays.expandBy(nRays);
    for (int i = nRays - 1; i >= 0; i--)
    {
        ray->m_kRayStart.m_vComponents = rays->m_kRayStart.m_vComponents;
        ray->m_kRayEnd.m_vComponents = rays->m_kRayEnd.m_vComponents;
        LocalM128 vec = _mm_sub_ps(ray->m_kRayEnd.m_vComponents, ray->m_kRayStart.m_vComponents);
        {
            float len;
            _mm_store_ss(&len, _mm_sqrt_ss(dot3(vec)));
            ray->m_kRayStart.w = len;
        }
        {
            LocalM128 len2 = dot3(vec);
            LocalM128 e = _mm_rsqrt_ss(len2);
            LocalM128 r = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), e),
                                  _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(len2, e), e)));
            r = _mm_andnot_ps(_mm_cmpeq_ss(len2, _mm_set_ss(0.0f)), r);
            vec = _mm_mul_ps(_mm_shuffle_ps(r, r, 0), vec);
        }
        LocalM128 dd = _mm_load_ps1(&m_fRayRadius);
        ray->m_kRayEnd.m_vComponents = _mm_add_ps(_mm_mul_ps(vec, dd), ray->m_kRayEnd.m_vComponents);
        ray++;
        rays++;
    }
}
