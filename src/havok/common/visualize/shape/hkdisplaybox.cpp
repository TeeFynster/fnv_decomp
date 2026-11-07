#include "../../../../../include/hkArray.h"

// src/havok/common/visualize/shape/hkdisplaybox.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/shape/hkdisplaybox.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/hkRotation.h"
#include "../../../../../include/hkTransform.h"

struct hkMemoryAllocator;

inline void hkVector4::setZero4()
{
    *reinterpret_cast<__m128*>(this) = _mm_setzero_ps();
}
inline hkRotation::hkRotation() {}
// Keep the display geometry vector a POD for its original scalar copy behavior.
struct __declspec(align(16)) DisplayBoxVector
{
    float x, y, z, w;
    void setTransformedPos_00c7f640(const hkTransform& t, const DisplayBoxVector& p);
    void set(const DisplayBoxVector& o)
    {
        *(__m128*)&x = *(const __m128*)&o.x;
    }
};

__declspec(nothrow) void __cdecl hkArrayUtil__reserve(hkMemoryAllocator& alloc, void* arr, int numElem, int sizeElem);

typedef hkArrayBase<DisplayBoxVector> hkVector4Array;
template<> __forceinline void hkArrayBase<DisplayBoxVector>::_setSize(hkMemoryAllocator& sharedAlloc, int n)
{
hkMemoryAllocator& alloc = reinterpret_cast<hkMemoryAllocator&>(sharedAlloc);

        if (getCapacity() < n)
        {
            int cap = 2 * getCapacity();
            hkArrayUtil__reserve(alloc, this, n < cap ? cap : n, sizeof(DisplayBoxVector));
        }
        m_iElementCount = n;
    
}


struct hkBoxGeometry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkTransform m_kMotionTransform;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    DisplayBoxVector m_vHalfExtents;

    void GetEdgeLines(hkVector4Array& lines, hkMemoryAllocator& alloc);
};

// @fnv 0x00de2050
void hkBoxGeometry::GetEdgeLines(hkVector4Array& aEdgeLines, hkMemoryAllocator& aAllocator)
{
    aEdgeLines._setSize(aAllocator, 24);

    DisplayBoxVector verts[8];
    for (int iVertex = 0; iVertex < 8; iVertex++)
    {
        DisplayBoxVector halfExtent = m_vHalfExtents;
        if (iVertex & 1)
            halfExtent.x *= -1.0;
        if (iVertex & 2)
            halfExtent.y *= -1.0;
        if (iVertex & 4)
            halfExtent.z *= -1.0;
        verts[iVertex].setTransformedPos_00c7f640(m_kMotionTransform, halfExtent);
    }

    int n = 0;
    for (int iVertex = 0; iVertex < 8; iVertex++)
    {
        for (int iBit = 1; iBit < 8; iBit <<= 1)
        {
            int iOtherVertex = iVertex ^ iBit;
            if (iVertex < iOtherVertex)
            {
                aEdgeLines.m_data[n++].set(verts[iVertex]);
                aEdgeLines.m_data[n++].set(verts[iOtherVertex]);
            }
        }
    }
}

extern "C" __m128 _mm_setzero_ps(void);
struct __declspec(align(16)) Vector4D22DC0
{
    float x;
    float y;
    float z;
    float w;
    void setZero4()
    {
        *reinterpret_cast<__m128*>(this) = _mm_setzero_ps();
    }
    void operator=(const Vector4D22DC0& kOther)
    {
        *reinterpret_cast<__m128*>(this) = *reinterpret_cast<const __m128*>(&kOther);
    }
};
inline float& rotationElement(hkRotation& rotation, int row, int column)
{
    return reinterpret_cast<float*>(&rotation.m_kColumn0 + column)[row];
}
inline void hkRotation::setIdentity()
{
    m_kColumn0.setZero4();
    m_kColumn1.setZero4();
    m_kColumn2.setZero4();
    rotationElement(*this, 0, 0) = 1.0f;
    rotationElement(*this, 1, 1) = 1.0f;
    rotationElement(*this, 2, 2) = 1.0f;
}
inline hkTransform::hkTransform() {}
inline void hkTransform::setIdentity()
{
    reinterpret_cast<hkRotation*>(&m_kColumn0)->setIdentity();
    m_vTranslation = _mm_setzero_ps();
}
struct ReferencedD22DC0
{
    ReferencedD22DC0() throw()
    {
        m_sReferenceCount = 1;
    }
    virtual ~ReferencedD22DC0() throw();
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
};
struct ShapeD22DC0 : public ReferencedD22DC0
{
    ShapeD22DC0(int iType) throw() : m_ulUserData(0), m_type(iType)
    {
        m_kMotionTransform.setIdentity();
    }
    virtual ~ShapeD22DC0() throw();
    int m_ulUserData;
    int unk0C;
    hkTransform m_kMotionTransform;
    int m_type;
};
struct FUN_00d58510 : public ShapeD22DC0
{
    FUN_00d58510(const Vector4D22DC0& kA, const Vector4D22DC0& kB, float fRadius, int iA, int iB) throw();
    virtual ~FUN_00d58510() throw();
    Vector4D22DC0 m_kA;
    Vector4D22DC0 m_kB;
    float m_fBoundRadius;
    int m_iA;
    int m_iB;
};

// @fnv 0x00d58510
FUN_00d58510::FUN_00d58510(const Vector4D22DC0& kA, const Vector4D22DC0& kB, float afBoundRadius, int iA,
                           int iB) throw()
    : ShapeD22DC0(9), m_iA(iA), m_iB(iB)
{
    m_kA = kA;
    m_kB = kB;
    m_fBoundRadius = afBoundRadius;
}
