// src/havok/physics/dynamics/constraint/bilateral/pointtopath/hkplinearparametriccurve_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/dynamics/constraint/bilateral/pointtopath/hkplinearparametriccurve.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/dynamics/constraint/bilateral/pointtopath/hkplinearparametriccurve.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/bilateral/pointtopath/hkplinearparametriccurve.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
// Exe 0x00e47e80 appendLinearCurvePoint: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C" LocalM128 _mm_sub_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_add_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, int);
extern "C" LocalM128 _mm_add_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_sqrt_ss(LocalM128);
extern "C" LocalM128 _mm_load_ss(const float*);
extern "C" void _mm_store_ss(float*, LocalM128);

#include "../../../../../../../include/hkArray.h"
#include "../../../../../../../include/hkBaseObject.h"
#include "../../../../../../../include/hkSimdReal.h"
#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/hkpLinearParametricCurve.h"
#include <string.h>

void* hkMemoryRouter_getInstance();
void __cdecl ResizeAudioStream(void* pvAllocator, void* apvArray, int iElemSize);

// Only the thread allocator at +0x10 is used here; this is a view of the TLS allocation context.
struct CurveAllocationContext
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_pStreamAllocator;
};

// The shared array's pushBack returns void; this helper also returns the appended element.
template <class T> static __forceinline T* appendCurveElement(hkArray<T>& array, const T& value)
{
    CurveAllocationContext* context = (CurveAllocationContext*)hkMemoryRouter_getInstance();
    if (array.m_iElementCount == array.getCapacity())
        ResizeAudioStream(context->m_pStreamAllocator, &array, sizeof(T));
    T* element = &array.m_data[array.m_iElementCount];
    *element = value;
    array.m_iElementCount++;
    return element;
}

// The shared curve lacks addPoint. This helper keeps the original ECX receiver and stack point
// argument; the unused EDX parameter preserves that ABI without another curve class declaration.
// @fnv 0x00e47e80
float* __fastcall appendLinearCurvePoint(hkpLinearParametricCurve* curve, void*, const hkVector4& kPoint) throw()
{
    appendCurveElement(curve->m_kPoints, kPoint);
    if (curve->m_kPoints.GetLogicalSize() == 1)
        return appendCurveElement(curve->m_fClosestPointDistanceSquared, 0.0f);

    hkVector4 kPrev;
    memcpy(&kPrev, &curve->m_kPoints[curve->m_kPoints.GetLogicalSize() - 2], sizeof(kPrev));
    LocalM128 kDiff = _mm_sub_ps(kPoint.m_vComponents, kPrev.m_vComponents);
    LocalM128 kSq = _mm_mul_ps(kDiff, kDiff);
    LocalM128 kSum = _mm_add_ss(_mm_shuffle_ps(kSq, kSq, 0xaa), _mm_add_ss(_mm_shuffle_ps(kSq, kSq, 0x55), kSq));
    LocalM128 kLen =
        _mm_add_ss(_mm_sqrt_ss(kSum),
                   _mm_load_ss(&curve->m_fClosestPointDistanceSquared[curve->m_fClosestPointDistanceSquared.GetLogicalSize() - 1]));
    float fDist;
    _mm_store_ss(&fDist, kLen);
    return appendCurveElement(curve->m_fClosestPointDistanceSquared, fDist);
}
