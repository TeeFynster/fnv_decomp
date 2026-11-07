
// src/havok/common/visualize/shape/hkdisplaysphere_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/common/visualize/shape/hkdisplaysphere.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /O2 /GS /EHsc /Gy (unit lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton.

// src/havok/common/visualize/shape/hkdisplaysphere.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/shape/hkdisplaysphere.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../include/hkReferencedObject.h"
#include "../../../../../include/hkVector4.h"

struct __declspec(align(16)) hkVec4f
{
    float x, y, z, w;
};
extern float DAT_012683b0;
struct FUN_008cd6a0_Class
{
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
    hkVector4 m_vTranslation;

    void setIdentity()
    {
        m_kColumn0.setZero4();
        m_kColumn1.setZero4();
        m_kColumn2.setZero4();
        float* d = &m_kColumn0(0);
        d[0] = 1.0f;
        d[5] = 1.0f;
        d[10] = 1.0f;
        m_vTranslation.setZero4();
    }
    void hkRotation_set(void* p);
};
struct __declspec(align(16)) ShapeBase : hkReferencedObject
{
    int m_ulUserData;
    FUN_008cd6a0_Class m_kMotionTransform;
    int m_type;

    ShapeBase()
    {
        m_ulUserData = 0;
        m_type = 1;
        m_kMotionTransform.setIdentity();
    }
};
struct __declspec(align(16)) FUN_00e0af50 : ShapeBase
{
    hkVec4f m_vec;
    int m_kPointA;
    int m_kPointB;

    FUN_00e0af50(const hkVec4f& v, int a, int b);
};
void __stdcall nullsub_91(int a, int b);

extern "C" ::__m128 _mm_setr_ps(float, float, float, float);
extern "C" void _ReadWriteBarrier();

extern double DAT_010ea650;
extern double DAT_010ea648;

struct SphereBuildAllocator
{
    virtual ~SphereBuildAllocator();
    virtual void* Alloc(int size);
};

struct SphereBuildMemory
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    SphereBuildAllocator* m_10;
};

SphereBuildMemory* __cdecl hkMemoryRouter_getInstance();

struct SphereBuildVertex
{
    ::__m128 q;
    __forceinline void set(float x, float y, float z, float w)
    {
        q = (_mm_setr_ps)(x, y, z, w);
    }
};

struct SphereBuildVertices
{
    SphereBuildVertex* volatile m_pData;
    int m_iArrayLength;
    int m_iCap;
};

struct SphereBuildFace
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
};

inline void SphereBuildSetFace(SphereBuildFace* f, int a, int b, int c)
{
    f->m_00 = a;
    f->m_04 = b;
    f->m_08 = c;
    f->m_0c = -1;
}

struct SphereBuildFaces
{
    SphereBuildFace* m_pData;
    int m_iArrayLength;
    int m_iCap;
};

struct SphereBuildGeometry
{
    SphereBuildVertices verts;
    SphereBuildFaces faces;
};

extern "C" void __cdecl hkArrayUtil__reserve(SphereBuildAllocator* ctx, void* arr, int newCap, int stride);
void __cdecl _subdivideRecursive(void* obj, int idx, float v, float f2);

struct SphereMeshBuilder
{
    int m_00;
    int m_04;
    SphereBuildGeometry* m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    float m_6c;
    void hkDisplaySphere_buildGeometry();
};

// @fnv 0x00e0b360
// src: HAVOK_SRC 0x00e0b360
__declspec(noinline) void SphereMeshBuilder::hkDisplaySphere_buildGeometry()
{
    SphereBuildMemory* holder = hkMemoryRouter_getInstance();
    SphereBuildGeometry* raw = (SphereBuildGeometry*)holder->m_10->Alloc(0x18);
    SphereBuildGeometry* geo;
    SphereBuildVertex* zero;
    if (raw)
    {
        raw->verts.m_pData = 0;
        raw->verts.m_iArrayLength = 0;
        raw->verts.m_iCap = (int)0x80000000;
        zero = (SphereBuildVertex* const&)raw->verts.m_pData;
        raw->faces.m_pData = (SphereBuildFace*)zero;
        raw->faces.m_iArrayLength = (int)zero;
        raw->faces.m_iCap = (int)0x80000000;
        geo = raw;
    }
    else
    {
        geo = 0;
        zero = 0;
    }
    m_08 = geo;
    _ReadWriteBarrier();
    float v = m_6c;
    float s = (float)(v * DAT_010ea650);
    float t = (float)(v * DAT_010ea648);
    _ReadWriteBarrier();
    SphereBuildMemory* vertexHolder = hkMemoryRouter_getInstance();
    SphereBuildAllocator* va = vertexHolder->m_10;
    _ReadWriteBarrier();
    if ((geo->verts.m_iCap & 0x3fffffff) < 12)
    {
        int nc = (geo->verts.m_iCap & 0x3fffffff) + (geo->verts.m_iCap & 0x3fffffff);
        if (nc <= 12)
            nc = 12;
        hkArrayUtil__reserve(va, &geo->verts, nc, 0x10);
    }
    geo->verts.m_iArrayLength = 12;
    ((SphereBuildVertex* const&)geo->verts.m_pData)[0].set(-s, 0.0f, t, 0.0f);
    geo->verts.m_pData[1].set(s, 0.0f, t, 0.0f);
    {
        SphereBuildVertex* dst = (SphereBuildVertex* const&)geo->verts.m_pData + 2;
        __assume(((unsigned int)dst & 15) == 0);
        dst->set(-s, 0.0f, -t, 0.0f);
    }
    geo->verts.m_pData[3].set(s, 0.0f, -t, 0.0f);
    geo->verts.m_pData[4].set(0.0f, t, s, 0.0f);
    geo->verts.m_pData[5].set(0.0f, t, -s, 0.0f);
    geo->verts.m_pData[6].set(0.0f, -t, s, 0.0f);
    geo->verts.m_pData[7].set(0.0f, -t, -s, 0.0f);
    geo->verts.m_pData[8].set(t, s, 0.0f, 0.0f);
    geo->verts.m_pData[9].set(-t, s, 0.0f, 0.0f);
    ((SphereBuildVertex* const&)geo->verts.m_pData)[10].set(t, -s, 0.0f, 0.0f);
    geo->verts.m_pData[11].q = (_mm_setr_ps)(-t, -s, 0.0f, 0.0f);
    SphereBuildFaces* fv = &((SphereBuildGeometry*)m_08)->faces;
    SphereBuildMemory* faceHolder = hkMemoryRouter_getInstance();
    SphereBuildAllocator* fa = faceHolder->m_10;
    _ReadWriteBarrier();
    if ((fv->m_iCap & 0x3fffffff) < 20)
    {
        int nc2 = (fv->m_iCap & 0x3fffffff) + (fv->m_iCap & 0x3fffffff);
        if (nc2 <= 20)
            nc2 = 20;
        hkArrayUtil__reserve(fa, fv, nc2, 0x10);
    }
    fv->m_iArrayLength = 20;
    SphereBuildSetFace(fv->m_pData + 0, 1, 4, (int)zero);
    SphereBuildSetFace(fv->m_pData + 1, 4, 9, (int)zero);
    SphereBuildSetFace(fv->m_pData + 2, 4, 5, 9);
    SphereBuildSetFace(fv->m_pData + 3, 8, 5, 4);
    SphereBuildSetFace(fv->m_pData + 4, 1, 8, 4);
    SphereBuildSetFace(fv->m_pData + 5, 1, 10, 8);
    SphereBuildSetFace(fv->m_pData + 6, 10, 3, 8);
    SphereBuildSetFace(fv->m_pData + 7, 8, 3, 5);
    SphereBuildSetFace(fv->m_pData + 8, 3, 2, 5);
    SphereBuildSetFace(fv->m_pData + 9, 3, 7, 2);
    SphereBuildSetFace(fv->m_pData + 10, 3, 10, 7);
    SphereBuildSetFace(fv->m_pData + 11, 10, 6, 7);
    SphereBuildSetFace(fv->m_pData + 12, 6, 11, 7);
    SphereBuildSetFace(fv->m_pData + 13, 6, 0, 11);
    SphereBuildSetFace(fv->m_pData + 14, 6, 1, 0);
    SphereBuildSetFace(fv->m_pData + 15, 10, 1, 6);
    SphereBuildSetFace(fv->m_pData + 16, 11, 0, 9);
    SphereBuildSetFace(fv->m_pData + 17, 2, 11, 9);
    SphereBuildSetFace(fv->m_pData + 18, 5, 2, 9);
    SphereBuildSetFace(fv->m_pData + 19, 11, 2, 7);
    for (int i = 0; i < 20; ++i)
        _subdivideRecursive(m_08, i, v, 2.0f);
}
