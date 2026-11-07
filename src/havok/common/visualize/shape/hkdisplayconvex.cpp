#define FNV64_HKVECTOR4_OWN_ASSIGN   // this unit defines its own hkVector4 assign form

// src/havok/common/visualize/shape/hkdisplayconvex.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/shape/hkdisplayconvex.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/hkVector4.h"
#include "../../../../../include/hkGeometry.h"
#include "../../../../../include/hkMemoryAllocator.h"


inline void hkVector4::setZero4()
{
    m_vComponents = _mm_setzero_ps();
}

inline void hkVector4::operator=(const hkVector4& vector)
{
    m_vComponents = vector.m_vComponents;
}

// @fnv 0x00de1d10
// src: COMMUNITY 0x00de1d10
void __cdecl nullsub_84()
{}

// local form of hkMatrix3: 0x00de1d20 needs implicit ctor and inline setIdentity; shared form gives 81 bytes vs exe 72.
struct S_00de1d20_Matrix3
{
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
    float& operator()(int r, int c)
    {
        return ((float*)&m_kColumn0)[c * 4 + r];
    }
    void setZero()
    {
        m_kColumn0.setZero4();
        m_kColumn1.setZero4();
        m_kColumn2.setZero4();
    }
    void setIdentity()
    {
        setZero();
        (*this)(0, 0) = 1.0f;
        (*this)(1, 1) = 1.0f;
        (*this)(2, 2) = 1.0f;
    }
};

struct S_00de1d20_Base
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    S_00de1d20_Base()
    {
        m_sReferenceCount = 1;
    }
    virtual void v0();
};

struct S_00de1d20_Mid : S_00de1d20_Base
{
    int unk8;
    S_00de1d20_Matrix3 unk10;
    hkVector4 unk40;
    int unk50;

    __forceinline S_00de1d20_Mid(int a)
    {
        unk50 = 6;
        unk10.setIdentity();
        unk40.setZero4();
    }
};

struct FUN_00de1d20 : S_00de1d20_Mid
{
    FUN_00de1d20(int a);
    virtual void v1();
};

// Constructor that initializes the base class with the given int and stores it in the unk8 field.
// @fnv 0x00de1d20
FUN_00de1d20::FUN_00de1d20(int aiValue) : S_00de1d20_Mid(aiValue)
{
    unk8 = aiValue;
}

void __cdecl ResizeAudioStream(void* alloc, void* array, int elemSize);

template <typename T> __forceinline void hkConstructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
    {
        p[i] = t;
    }
}

template <typename T> __forceinline void hkArrayBase<T>::_pushBack(hkMemoryAllocator& alloc, const T& t)
{
    if (m_iElementCount == getCapacity())
    {
        ResizeAudioStream(&alloc, this, sizeof(T));
    }
    hkConstructWithCopy(m_data + m_iElementCount, 1, t);
    m_iElementCount++;
}

namespace fnv_00de1d70 {
struct TriIndices
{
    int a;
    int b;
    int c;
};

struct EdgeBuilder
{
    int unk00;
    int unk04;
    hkGeometry* m_pSourceGeometry;
    void hkDisplayConvex_getWireframeGeometry(hkArray<hkVector4>& lines, hkMemoryAllocator& alloc);
};

// For each triangle in the source geometry, appends three vertex pairs (a-b, a-c, b-c) to lines.
// @fnv 0x00de1d70
// src: HAVOK_SRC 0x00de1d70
void EdgeBuilder::hkDisplayConvex_getWireframeGeometry(hkArray<hkVector4>& lines, hkMemoryAllocator& alloc)
{
    if (m_pSourceGeometry)
    {
        for (int i = m_pSourceGeometry->m_uiTriangleCount.m_iElementCount - 1; i >= 0; i--)
        {
            TriIndices k;
            k.a = m_pSourceGeometry->m_uiTriangleCount.m_data[i].m_kPointA;
            k.b = m_pSourceGeometry->m_uiTriangleCount.m_data[i].m_kPointB;
            k.c = m_pSourceGeometry->m_uiTriangleCount.m_data[i].m_iThirdValue;
            lines._pushBack(alloc, m_pSourceGeometry->m_kVertices.m_data[k.a]);
            lines._pushBack(alloc, m_pSourceGeometry->m_kVertices.m_data[k.b]);
            lines._pushBack(alloc, m_pSourceGeometry->m_kVertices.m_data[k.a]);
            lines._pushBack(alloc, m_pSourceGeometry->m_kVertices.m_data[k.c]);
            lines._pushBack(alloc, m_pSourceGeometry->m_kVertices.m_data[k.b]);
            lines._pushBack(alloc, m_pSourceGeometry->m_kVertices.m_data[k.c]);
        }
    }
}
}  // namespace fnv_00de1d70
