#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit defines its own form

// src/havok/common/base/math/matrix/hkmatrix6.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/math/matrix/hkmatrix6.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/hkMatrix3.h"


inline void hkVector4::add4(const hkVector4& v)
{
    m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents);
}

inline hkMatrix3::hkMatrix3()
{
}

inline void hkMatrix3::add(const hkMatrix3& a)
{
    m_kColumn0.add4(a.m_kColumn0);
    m_kColumn1.add4(a.m_kColumn1);
    m_kColumn2.add4(a.m_kColumn2);
}

struct FUN_00e29290_Block
{
    hkMatrix3 f0;
    hkMatrix3 f1;
    hkMatrix3 f2;
    hkVector4 f3;
    hkVector4 f4;
    hkVector4 f5;
};

// Adds each matrix and vector of b into the corresponding member of a.
// @fnv 0x00e29290
// src: GUESS 0x00e29290 (confidence: medium)
extern "C" void __cdecl hkMatrix6_AddMatricesAndVectorsInPlace(FUN_00e29290_Block* pDst, const FUN_00e29290_Block* pSrc)
{
    pDst->f0.add(pSrc->f0);
    pDst->f1.add(pSrc->f1);
    pDst->f2.add(pSrc->f2);
    pDst->f3.add4(pSrc->f3);
    pDst->f4.add4(pSrc->f4);
    pDst->f5.add4(pSrc->f5);
}

struct E29250Matrix6
{
    hkMatrix3 m_iUnknownValue2[2][2];
};

// @fnv 0x00e29250
// src: HAVOK_LIB 0x00e29250
void __cdecl _hkMatrix6SetTranspose(E29250Matrix6& out, const E29250Matrix6& in)
{
    out.m_iUnknownValue2[0][0]._setTranspose(in.m_iUnknownValue2[0][0]);
    out.m_iUnknownValue2[0][1]._setTranspose(in.m_iUnknownValue2[1][0]);
    out.m_iUnknownValue2[1][0]._setTranspose(in.m_iUnknownValue2[0][1]);
    out.m_iUnknownValue2[1][1]._setTranspose(in.m_iUnknownValue2[1][1]);
}

// @fnv 0x00e29510
// src: GUESS 0x00e29510 (confidence: low)
void hkVector4_ComputeValues_00e29510(__m128* out, const __m128* aMatrix, const __m128* aVectors)
{
    __m128 v0 = aVectors[0];
    __m128 a = _mm_mul_ps(_mm_shuffle_ps(v0, v0, 0x55), aMatrix[1]);
    a = _mm_add_ps(a, _mm_mul_ps(_mm_shuffle_ps(v0, v0, 0x00), aMatrix[0]));
    a = _mm_add_ps(a, _mm_mul_ps(_mm_shuffle_ps(v0, v0, 0xaa), aMatrix[2]));
    __m128 v2 = aVectors[1];
    __m128 b = _mm_mul_ps(_mm_shuffle_ps(v2, v2, 0x55), aMatrix[4]);
    b = _mm_add_ps(b, _mm_mul_ps(_mm_shuffle_ps(v2, v2, 0x00), aMatrix[3]));
    b = _mm_add_ps(b, _mm_mul_ps(_mm_shuffle_ps(v2, v2, 0xaa), aMatrix[5]));
    _mm_store_ps((float*)out, b);
    __m128 w0 = aVectors[0];
    __m128 d = _mm_mul_ps(_mm_shuffle_ps(w0, w0, 0x55), aMatrix[7]);
    d = _mm_add_ps(d, _mm_mul_ps(_mm_shuffle_ps(w0, w0, 0x00), aMatrix[6]));
    d = _mm_add_ps(d, _mm_mul_ps(_mm_shuffle_ps(w0, w0, 0xaa), aMatrix[8]));
    __m128 w2 = aVectors[1];
    __m128 e = _mm_mul_ps(_mm_shuffle_ps(w2, w2, 0x55), aMatrix[10]);
    e = _mm_add_ps(e, _mm_mul_ps(_mm_shuffle_ps(w2, w2, 0x00), aMatrix[9]));
    e = _mm_add_ps(e, _mm_mul_ps(_mm_shuffle_ps(w2, w2, 0xaa), aMatrix[11]));
    _mm_store_ps((float*)out, _mm_add_ps(_mm_load_ps((float*)out), a));
    hkVector4* dest = reinterpret_cast<hkVector4*>(out);
    dest[1].m_vComponents = e;
    hkVector4 extra;
    extra.m_vComponents = d;
    dest[1].add4(extra);
}

__forceinline void AddVector(__m128& dst, const __m128& src)
{
    dst = _mm_add_ps(dst, src);
}
__forceinline __m128 AddValues(__m128 dst, __m128 src)
{
    return _mm_add_ps(dst, src);
}
__forceinline void AddPointers(__m128* dst, const __m128* src)
{
    *dst = _mm_add_ps(_mm_load_ps((float*)dst), _mm_load_ps((const float*)src));
}

struct PodPointer
{
    void* p;
};
struct WrappedPointer
{
    void* p;
    WrappedPointer(void* q) : p(q)
    {}
};
extern "C" void __cdecl hkMatrix3_MultiplyMatrixColumns(void* out, const void* a,
                                     const void*

                                         b);

// @fnv 0x00e29470
// src: GUESS 0x00e29470 (confidence: low)
void __cdecl hkMatrix3_ProcessEntries_00e29470(void* apDest, WrappedPointer src, WrappedPointer rhs)

{

    char* source = (char*)src.p;

    __m128* cur = (__m128*)apDest + 2;

    int outer = 2;

    do

    {

        char* right = (char*)rhs.p;

        int inner = 2;

        do

        {

            hkMatrix3 tempMatrix;

            hkMatrix3_MultiplyMatrixColumns(&tempMatrix, source, right);

            hkMatrix3_MultiplyMatrixColumns(cur - 2, source + 0x30, right + 0x60);

            cur[-2] = _mm_add_ps(cur[-2], tempMatrix.m_kColumn0.m_vComponents);
            AddVector(cur[-1], tempMatrix.m_kColumn1.m_vComponents);
            *cur = _mm_add_ps(*cur, _mm_load_ps((float*)&tempMatrix.m_kColumn2.m_vComponents));
            right += 0x30;

            cur += 3;

        } while (--inner != 0);

        source += 0x60;

    } while (--outer != 0);
}

__forceinline void subtract(__m128& a, const __m128& b)
{
    a = _mm_sub_ps(a, b);
}
__forceinline void subtractGroup(__m128* d, const __m128* s)
{
    subtract(d[0], s[0]);
    subtract(d[1], s[1]);
    subtract(d[2], s[2]);
}
// Subtracts 12 __m128 values from source into destination, using subtractGroup for the first two triplets and individual subtract calls for the remaining six.
// @fnv 0x00e29380
// src: GUESS 0x00e29380 (confidence: medium)
void __cdecl Object_SubtractVectorBundles(__m128* destination, const __m128* source)
{
    subtractGroup(destination + 0, source + 0);
    subtractGroup(destination + 3, source + 3);
    subtract(destination[6], source[6]);
    subtract(destination[7], source[7]);
    subtract(destination[8], source[8]);
    subtract(destination[9], source[9]);
    subtract(destination[10], source[10]);
    subtract(destination[11], source[11]);
}
