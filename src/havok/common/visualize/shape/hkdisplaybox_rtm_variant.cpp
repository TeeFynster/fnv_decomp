#include "../../../../../include/hkArray.h"
// src/havok/common/visualize/shape/hkdisplaybox_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/common/visualize/shape/hkdisplaybox.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /O2 /GS /EHsc /Gy (unit lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton.


// src/havok/common/visualize/shape/hkdisplaybox.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/shape/hkdisplaybox.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../include/hkVector4.h"
#include "../../../../../include/hkTransform.h"

struct hkMemoryAllocator;
__declspec(nothrow) void __cdecl hkArrayUtil__reserve(hkMemoryAllocator& alloc, void* arr, int numElem, int sizeElem);
typedef hkArray<hkVector4> hkVector4Array;
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
    hkVector4 m_vHalfExtents;

    void GetEdgeLines(hkVector4Array& lines, hkMemoryAllocator& alloc);
};
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

extern "C" __m128 _mm_setr_ps(float x, float y, float z, float w);
extern "C" void _ReadWriteBarrier();
extern const float DAT_010c4990 = -0.0f;
extern const float DAT_01011d78 = 0.0f;

struct BoxBuild2190AllocCtx
{
    virtual void vf0();
    virtual void* alloc(int size);
};
struct BoxBuild2190Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    BoxBuild2190AllocCtx* m_10;
    __forceinline hkMemoryAllocator& heap()
    {
        return *reinterpret_cast<hkMemoryAllocator*>(m_10);
    }
};
BoxBuild2190Router* hkMemoryRouter_getInstance();

struct BoxBuild2190Tri
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
};
template <class T> struct BoxBuild2190MatchArrayLocalForm
{ // local form of hkArray: 0x00de2190 needs the original constructor stores; shared base construction changes bytes.
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    BoxBuild2190MatchArrayLocalForm() : m_data(0), m_iElementCount(0), m_iCapacityState((int)0x80000000)
    {}
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void reserve(hkMemoryAllocator& alloc, int n)
    {
        const int cap = getCapacity();
        if (cap < n)
        {
            int doubled = cap * 2;
            int desired = n < doubled ? doubled : n;
            hkArrayUtil__reserve(alloc, this, desired, sizeof(T));
        }
    }
    __forceinline T* append(hkMemoryAllocator& alloc)
    {
        int oldCount = m_iElementCount;
        reserve(alloc, oldCount + 1);
        ++m_iElementCount;
        return m_data + oldCount;
    }
};
struct BoxBuild2190Geom
{
    BoxBuild2190MatchArrayLocalForm<hkVector4> m_verts;
    BoxBuild2190MatchArrayLocalForm<BoxBuild2190Tri> m_tris;
};

struct BoxBuild2190BoxShell
{
    int unk00;
    int unk04;
    BoxBuild2190Geom* m_08;
    int unk0c;
    hkTransform m_kMotionTransform;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    hkVector4 m_vHalfExtents;
    void hkDisplayBox_buildGeometry();
};

// @fnv 0x00de2190
// src: HAVOK_SRC 0x00de2190
void BoxBuild2190BoxShell::hkDisplayBox_buildGeometry()
{
    BoxBuild2190Router* router = hkMemoryRouter_getInstance();
    BoxBuild2190Geom* mem = (BoxBuild2190Geom*)router->m_10->alloc(sizeof(BoxBuild2190Geom));
    BoxBuild2190Geom* geom;
    if (mem)
    {
        mem->m_verts.m_data = 0;
        mem->m_verts.m_iElementCount = 0;
        _ReadWriteBarrier();
        mem->m_verts.m_iCapacityState = (int)0x80000000;
        _ReadWriteBarrier();
        mem->m_tris.m_data = 0;
        mem->m_tris.m_iElementCount = 0;
        mem->m_tris.m_iCapacityState = (int)0x80000000;
        geom = mem;
    }
    else
        geom = 0;
    m_08 = geom;

    {
        BoxBuild2190MatchArrayLocalForm<hkVector4>* arr = &m_08->m_verts;
        hkMemoryAllocator* allocp = &hkMemoryRouter_getInstance()->heap();
        _ReadWriteBarrier();
        hkVector4* dst = arr->append(*allocp);
        *reinterpret_cast<__m128*>(dst) =
            (_mm_setr_ps)(-m_vHalfExtents.x, m_vHalfExtents.y, m_vHalfExtents.z, DAT_01011d78);
    }
    {
        BoxBuild2190MatchArrayLocalForm<hkVector4>* arr = &m_08->m_verts;
        hkMemoryAllocator* allocp = &hkMemoryRouter_getInstance()->heap();
        _ReadWriteBarrier();
        hkVector4* dst = arr->append(*allocp);
        *reinterpret_cast<__m128*>(dst) =
            (_mm_setr_ps)(m_vHalfExtents.x, m_vHalfExtents.y, m_vHalfExtents.z, DAT_01011d78);
    }
    {
        BoxBuild2190MatchArrayLocalForm<hkVector4>* arr = &m_08->m_verts;
        hkMemoryAllocator* allocp = &hkMemoryRouter_getInstance()->heap();
        _ReadWriteBarrier();
        hkVector4* dst = arr->append(*allocp);
        *reinterpret_cast<__m128*>(dst) =
            (_mm_setr_ps)(m_vHalfExtents.x, -m_vHalfExtents.y, m_vHalfExtents.z, DAT_01011d78);
    }
    {
        BoxBuild2190MatchArrayLocalForm<hkVector4>* arr = &m_08->m_verts;
        hkMemoryAllocator* allocp = &hkMemoryRouter_getInstance()->heap();
        _ReadWriteBarrier();
        hkVector4* dst = arr->append(*allocp);
        *reinterpret_cast<__m128*>(dst) =
            (_mm_setr_ps)(-m_vHalfExtents.x, -m_vHalfExtents.y, m_vHalfExtents.z, DAT_01011d78);
    }
    {
        BoxBuild2190MatchArrayLocalForm<hkVector4>* arr = &m_08->m_verts;
        hkMemoryAllocator* allocp = &hkMemoryRouter_getInstance()->heap();
        _ReadWriteBarrier();
        hkVector4* dst = arr->append(*allocp);
        *reinterpret_cast<__m128*>(dst) =
            (_mm_setr_ps)(-m_vHalfExtents.x, m_vHalfExtents.y, -m_vHalfExtents.z, DAT_01011d78);
    }
    {
        BoxBuild2190MatchArrayLocalForm<hkVector4>* arr = &m_08->m_verts;
        hkMemoryAllocator* allocp = &hkMemoryRouter_getInstance()->heap();
        _ReadWriteBarrier();
        hkVector4* dst = arr->append(*allocp);
        *reinterpret_cast<__m128*>(dst) =
            (_mm_setr_ps)(m_vHalfExtents.x, m_vHalfExtents.y, -m_vHalfExtents.z, DAT_01011d78);
    }
    {
        BoxBuild2190MatchArrayLocalForm<hkVector4>* arr = &m_08->m_verts;
        hkMemoryAllocator* allocp = &hkMemoryRouter_getInstance()->heap();
        _ReadWriteBarrier();
        hkVector4* dst = arr->append(*allocp);
        *reinterpret_cast<__m128*>(dst) =
            (_mm_setr_ps)(m_vHalfExtents.x, -m_vHalfExtents.y, -m_vHalfExtents.z, DAT_01011d78);
    }
    {
        BoxBuild2190MatchArrayLocalForm<hkVector4>* arr = &m_08->m_verts;
        hkMemoryAllocator* allocp = &hkMemoryRouter_getInstance()->heap();
        _ReadWriteBarrier();
        hkVector4* dst = arr->append(*allocp);
        *reinterpret_cast<__m128*>(dst) =
            (_mm_setr_ps)(-m_vHalfExtents.x, -m_vHalfExtents.y, -m_vHalfExtents.z, DAT_01011d78);
    }

    for (int i = 0; i < m_08->m_verts.m_iElementCount; i++)
        m_08->m_verts.m_data[i].setTransformedPos_00c7f640(m_kMotionTransform, m_08->m_verts.m_data[i]);

    {
        BoxBuild2190MatchArrayLocalForm<BoxBuild2190Tri>* arr = &m_08->m_tris;
        hkMemoryAllocator* allocp = &hkMemoryRouter_getInstance()->heap();
        _ReadWriteBarrier();
        BoxBuild2190Tri* t = arr->append(*allocp);
        t->m_kPointA = 3;
        t->m_kPointB = 2;
        t->m_iThirdValue = 1;
        t->m_iFourthElementInteger = -1;
    }
    {
        BoxBuild2190MatchArrayLocalForm<BoxBuild2190Tri>* arr = &m_08->m_tris;
        hkMemoryAllocator* allocp = &hkMemoryRouter_getInstance()->heap();
        _ReadWriteBarrier();
        BoxBuild2190Tri* t = arr->append(*allocp);
        t->m_kPointA = 3;
        t->m_kPointB = 1;
        t->m_iThirdValue = 0;
        t->m_iFourthElementInteger = -1;
    }
    {
        BoxBuild2190MatchArrayLocalForm<BoxBuild2190Tri>* arr = &m_08->m_tris;
        hkMemoryAllocator* allocp = &hkMemoryRouter_getInstance()->heap();
        _ReadWriteBarrier();
        BoxBuild2190Tri* t = arr->append(*allocp);
        t->m_kPointA = 6;
        t->m_kPointB = 7;
        t->m_iThirdValue = 4;
        t->m_iFourthElementInteger = -1;
    }
    {
        BoxBuild2190MatchArrayLocalForm<BoxBuild2190Tri>* arr = &m_08->m_tris;
        hkMemoryAllocator* allocp = &hkMemoryRouter_getInstance()->heap();
        _ReadWriteBarrier();
        BoxBuild2190Tri* t = arr->append(*allocp);
        t->m_kPointA = 6;
        t->m_kPointB = 4;
        t->m_iThirdValue = 5;
        t->m_iFourthElementInteger = -1;
    }
    {
        BoxBuild2190MatchArrayLocalForm<BoxBuild2190Tri>* arr = &m_08->m_tris;
        hkMemoryAllocator* allocp = &hkMemoryRouter_getInstance()->heap();
        _ReadWriteBarrier();
        BoxBuild2190Tri* t = arr->append(*allocp);
        t->m_kPointA = 4;
        t->m_kPointB = 7;
        t->m_iThirdValue = 3;
        t->m_iFourthElementInteger = -1;
    }
    {
        BoxBuild2190MatchArrayLocalForm<BoxBuild2190Tri>* arr = &m_08->m_tris;
        hkMemoryAllocator* allocp = &hkMemoryRouter_getInstance()->heap();
        _ReadWriteBarrier();
        BoxBuild2190Tri* t = arr->append(*allocp);
        t->m_kPointA = 4;
        t->m_kPointB = 3;
        t->m_iThirdValue = 0;
        t->m_iFourthElementInteger = -1;
    }
    {
        BoxBuild2190MatchArrayLocalForm<BoxBuild2190Tri>* arr = &m_08->m_tris;
        hkMemoryAllocator* allocp = &hkMemoryRouter_getInstance()->heap();
        _ReadWriteBarrier();
        BoxBuild2190Tri* t = arr->append(*allocp);
        t->m_kPointA = 2;
        t->m_kPointB = 6;
        t->m_iThirdValue = 5;
        t->m_iFourthElementInteger = -1;
    }
    {
        BoxBuild2190MatchArrayLocalForm<BoxBuild2190Tri>* arr = &m_08->m_tris;
        hkMemoryAllocator* allocp = &hkMemoryRouter_getInstance()->heap();
        _ReadWriteBarrier();
        BoxBuild2190Tri* t = arr->append(*allocp);
        t->m_kPointA = 2;
        t->m_kPointB = 5;
        t->m_iThirdValue = 1;
        t->m_iFourthElementInteger = -1;
    }
    {
        BoxBuild2190MatchArrayLocalForm<BoxBuild2190Tri>* arr = &m_08->m_tris;
        hkMemoryAllocator* allocp = &hkMemoryRouter_getInstance()->heap();
        _ReadWriteBarrier();
        BoxBuild2190Tri* t = arr->append(*allocp);
        t->m_kPointA = 7;
        t->m_kPointB = 6;
        t->m_iThirdValue = 2;
        t->m_iFourthElementInteger = -1;
    }
    {
        BoxBuild2190MatchArrayLocalForm<BoxBuild2190Tri>* arr = &m_08->m_tris;
        hkMemoryAllocator* allocp = &hkMemoryRouter_getInstance()->heap();
        _ReadWriteBarrier();
        BoxBuild2190Tri* t = arr->append(*allocp);
        t->m_kPointA = 7;
        t->m_kPointB = 2;
        t->m_iThirdValue = 3;
        t->m_iFourthElementInteger = -1;
    }
    {
        BoxBuild2190MatchArrayLocalForm<BoxBuild2190Tri>* arr = &m_08->m_tris;
        hkMemoryAllocator* allocp = &hkMemoryRouter_getInstance()->heap();
        _ReadWriteBarrier();
        BoxBuild2190Tri* t = arr->append(*allocp);
        t->m_kPointA = 1;
        t->m_kPointB = 5;
        t->m_iThirdValue = 4;
        t->m_iFourthElementInteger = -1;
    }
    {
        BoxBuild2190MatchArrayLocalForm<BoxBuild2190Tri>* arr = &m_08->m_tris;
        hkMemoryAllocator* allocp = &hkMemoryRouter_getInstance()->heap();
        _ReadWriteBarrier();
        BoxBuild2190Tri* t = arr->append(*allocp);
        t->m_kPointA = 1;
        t->m_kPointB = 4;
        t->m_iThirdValue = 0;
        t->m_iFourthElementInteger = -1;
    }
}
