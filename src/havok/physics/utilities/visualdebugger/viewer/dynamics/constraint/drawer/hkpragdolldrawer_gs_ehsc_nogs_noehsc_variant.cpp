// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpragdolldrawer_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpragdolldrawer.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpragdolldrawer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpragdolldrawer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <math.h>
#include "../../../../../../../../../include/Vec4.h"

class ScalarLane
{
    __m128 value;

  public:
    ScalarLane()
    {}
    ScalarLane(const __m128& x) : value(x)
    {}
    ScalarLane(float x) : value(_mm_load_ss(&x))
    {}
    __forceinline const __m128& getQuad() const
    {
        return value;
    }
    __forceinline __m128 broadcast() const
    {
        return _mm_shuffle_ps(value, value, 0);
    }
};
__forceinline __m128& Vec4::getQuad()
{
    return *reinterpret_cast<__m128*>(this);
}
__forceinline const __m128& Vec4::getQuad() const
{
    return *reinterpret_cast<const __m128*>(this);
}
__forceinline void Vec4::setCross(const Vec4& a, const Vec4& b)
{
    __m128 p = _mm_mul_ps(_mm_shuffle_ps(a.getQuad(), a.getQuad(), 0xc9), _mm_shuffle_ps(b.getQuad(), b.getQuad(), 0xd2));
    __m128 n = _mm_mul_ps(_mm_shuffle_ps(a.getQuad(), a.getQuad(), 0xd2), _mm_shuffle_ps(b.getQuad(), b.getQuad(), 0xc9));
    getQuad() = _mm_sub_ps(p, n);
}
__forceinline void Vec4::orderedCross(const Vec4& left, const Vec4& right)
{
    __m128 a = left.getQuad(), b = right.getQuad();
    __m128 a2 = _mm_shuffle_ps(a, a, 0xd2);
    __m128 a1 = _mm_shuffle_ps(a, a, 0xc9);
    __m128 b1 = _mm_shuffle_ps(b, b, 0xc9);
    b1 = _mm_mul_ps(b1, a2);
    __m128 b2 = _mm_shuffle_ps(b, b, 0xd2);
    b2 = _mm_mul_ps(b2, a1);
    getQuad() = _mm_sub_ps(b2, b1);
}
__forceinline ScalarLane Vec4::dot3(const Vec4& a) const
{
    __m128 p = _mm_mul_ps(getQuad(), a.getQuad());
    __m128 xysum = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
    return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), xysum);
}
__forceinline ScalarLane Vec4::inverseLength3() const
{
    const __m128 half = _mm_set_ss(0.5f);
    const __m128 three = _mm_set_ss(3.0f);
    const __m128 zero = _mm_set_ss(0.0f);
    const __m128 squared = Vec4::dot3(*this).getQuad();
    const __m128 equal = _mm_cmpeq_ss(squared, zero);
    const __m128 estimate = _mm_rsqrt_ss(squared);
    const __m128 refined = _mm_mul_ss(_mm_mul_ss(half, estimate),
                                      _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(squared, estimate), estimate)));
    return _mm_andnot_ps(equal, refined);
}
__forceinline void Vec4::normalize3()
{
    __m128 scale = Vec4::inverseLength3().broadcast();
    getQuad() = _mm_mul_ps(scale, getQuad());
}
struct Buf40
{
    Vec4::Aligned a;
    Vec4::Aligned b;
    Vec4::Aligned c;
    Vec4::Aligned d;
    __forceinline Buf40()
        : a(Vec4::Uninitialized), b(Vec4::Uninitialized), c(Vec4::Uninitialized), d(Vec4::Uninitialized)
    {}
};
typedef Vec4::Aligned Sub40;

struct SubC0
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    void __thiscall hkpPrimitiveDrawer_setDisplayHandler(void* p2);
    void __thiscall ComputeValues_00e10d50(void* target, Vec4* a, Vec4* b, int color, float t, int p3, int p4);
};
struct FloatPair
{
    float a;
    float b;
    FloatPair(float av, float bv) : a(av), b(bv)
    {}
};
struct DisplayBase
{
    int table;
    unsigned short allocatorFlags, references;
    void* geometry;
    Buf40 pose;
    int kind;
};
struct SubReg : DisplayBase
{
    Vec4::Aligned start, axis;
    int count;
    float angle, height;
    void __thiscall InitializeFields_00de5370(float, float, int, Vec4*, void*);
};
struct Sub280 : DisplayBase
{
    Vec4::Aligned normal, center, perpendicular, extent;
    void __thiscall SetFromVectors(Vec4*, Vec4*, void*, Vec4*);
};
struct MatrixColumns
{
    Vec4::Aligned first, second, third;
    __forceinline const Vec4& getColumn(int i) const
    {
        return (&first)[i];
    }
};
struct RotationColumns : MatrixColumns
{
};
struct Mat
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    RotationColumns rotationA;
    RotationColumns rotationB;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    float fa0;
    int fA4;
    int fA8;
    int fAC;
    float fb0;
    float fb4;
};
struct P1
{
    int f00;
    int f04;
    int f08;
    Mat* mat;
};
struct __declspec(align(16)) PtrVec
{
    void** buf;
    int len;
    int cap;
};
struct PoolObj
{
    virtual void Reserved0();
    virtual void Reserved1();
    virtual void Reserved2();
    virtual void Reserved3();
    virtual void Release(void* buf, int bytes);
};
struct Singleton
{
    int s00;
    int s04;
    int s08;
    int s0c;
    PoolObj* pool;
};
Singleton* __cdecl hkMemoryRouter_getInstance();
void __cdecl hkArrayUtil__reserve(PoolObj* pool, PtrVec* vec, int count, int elemSize);
int __cdecl FUN_00cabb00(int a, int b, int c, int d);
extern int DAT_01267e30;
extern float DAT_01011d78;
extern float DAT_01017718;
extern float DAT_01016248;
extern double DAT_01030f38;
extern const __m128 DAT_010c44d0;
struct P2Vtbl
{
    virtual void Reserved00();
    virtual void Reserved01();
    virtual void Reserved02();
    virtual void Reserved03();
    virtual void Reserved04();
    virtual void Reserved05();
    virtual void Reserved06();
    virtual void Reserved07();
    virtual void Reserved08();
    virtual void Reserved09();
    virtual void Reserved10();
    virtual void Reserved11();
    virtual void Reserved12();
    virtual void Reserved13();
    virtual void DrawVec(PtrVec* vec, int color, int p3, int p4);
};
struct DrawBasis
{
    Vec4::Aligned t60;
    Vec4::Aligned t70;
    Vec4::Aligned t80;
    Vec4::Aligned t90;
    Vec4::Aligned bufA0;
    Vec4::Aligned tb0;
    Vec4::Aligned tc0;
};

struct RendererRef
{
    P2Vtbl* object;
    RendererRef& operator=(const RendererRef& r)
    {
        object = r.object;
        return *this;
    }
};
struct Group50
{
    Sub40 m50;
    RotationColumns m60, m90;
    SubC0 mC0;
    SubReg mD0, m160, m1F0;
    Sub280 m280;
};

struct DrawerBase
{

    int f00;
    int f04;
    int f08;
    float f0c;
    float f10;
    float f14;
    int f18;
    float f1c;
    Vec4::Aligned bodyA, bodyB;
    Sub40 m40;
    Sub40 m50;
    RotationColumns m60, m90;
    SubC0 mC0;

    void __thiscall hkpConstraintDrawer_updateCommonParameters(P1*, Buf40*, Buf40*);
    void __thiscall hkpConstraintDrawer_drawPivots(int, int);
    __forceinline float arrowSize() const
    {
        return f1c * f0c;
    }
    __forceinline float coneSize() const
    {
        return f1c * f10;
    }
    __forceinline float planeSize() const
    {
        return f1c * f14;
    }
};
struct This : DrawerBase
{
    SubReg mD0, m160, m1F0;
    Sub280 m280;

    void __thiscall ComputeValues_00de59f0(P1*, P2Vtbl*, int, int);
};
// @fnv 0x00de59f0
// src: GUESS 0x00de59f0 (confidence: low)
void __thiscall This::ComputeValues_00de59f0(P1* p1, P2Vtbl* p2, int p3, int p4)
{
    Mat* mat = p1->mat;
    mC0.hkpPrimitiveDrawer_setDisplayHandler(p2);
    This& receivers = *this;
    {
        Buf40 bufferA, bufferB;
        hkpConstraintDrawer_updateCommonParameters(p1, &bufferA, &bufferB);
        receivers.m50.setTransformedPos_00c7f640(&bufferA, &DAT_01267e30);
        m40.setTransformedPos_00c7f640(&bufferB, &DAT_01267e30);
    }
    hkpConstraintDrawer_drawPivots(p3, p4);
    const RotationColumns& localA = mat->rotationA;
    const RotationColumns& localB = mat->rotationB;
    Vec4::Aligned t80(Vec4::Uninitialized);
    t80.hkVector4_setRotatedDir(reinterpret_cast<const RotationColumns&>(m90), localB.getColumn(0));
    const Vec4* matrixColumn60 = &localB.getColumn(1);
    Vec4::Aligned t70(Vec4::Uninitialized);
    t70.setCross(localB.getColumn(0), localB.getColumn(1));
    t70.normalize3();
    t70.hkVector4_setRotatedDir(reinterpret_cast<const RotationColumns&>(m90), t70);
    Vec4::Aligned t60(Vec4::Uninitialized);
    t60.hkVector4_setRotatedDir(reinterpret_cast<const RotationColumns&>(m90), *matrixColumn60);
    Vec4::Aligned tb0(Vec4::Uninitialized);
    {
        __m128 a = localA.getColumn(1).getQuad();
        __m128 b = localA.getColumn(0).getQuad();
        __m128 a2 = _mm_shuffle_ps(a, a, 0xd2);
        __m128 a1 = _mm_shuffle_ps(a, a, 0xc9);
        __m128 b1 = _mm_shuffle_ps(b, b, 0xc9);
        b1 = _mm_mul_ps(b1, a2);
        __m128 b2 = _mm_shuffle_ps(b, b, 0xd2);
        b2 = _mm_mul_ps(b2, a1);
        tb0.getQuad() = _mm_sub_ps(b2, b1);
    }

    tb0.normalize3();
    Vec4::Aligned t90(Vec4::Uninitialized);
    t90.hkVector4_setRotatedDir(reinterpret_cast<const RotationColumns&>(m60), tb0);
    Vec4::Aligned tc0(Vec4::Uninitialized);
    tc0.hkVector4_setRotatedDir(reinterpret_cast<const RotationColumns&>(m60), localA.getColumn(0));
    float prod1 = f1c * f0c;
    mC0.ComputeValues_00e10d50(&receivers.m50, &t80, &t70, 0xff008000, prod1, p3, p4);
    mC0.ComputeValues_00e10d50(&m40, &tc0, &t90, FUN_00cabb00(0xff, 0xff, 0, 0xff), f1c * f0c, p3, p4);
    void* subD0 = &mD0;
    mD0.InitializeFields_00de5370(mat->fa0, f1c * f10, f18, &t80, &receivers.m50);
    Vec4::Aligned bufA0(Vec4::Uninitialized);
    float prod2 = f14 * f1c;
    bufA0.getQuad() = _mm_load_ps1(&prod2);
    void* sub280 = &m280;
    m280.SetFromVectors(&t60, &t70, &receivers.m50, &bufA0);
    float fb0 = mat->fb0;
    void* sub160 = &m160;
    m160.InitializeFields_00de5370((float)(DAT_01030f38 - (double)(float)fabs((double)mat->fb4)), f1c * f10, f18, &t60,
                      &receivers.m50);
    void* sub1F0 = &m1F0;
    t60.getQuad() = _mm_xor_ps(t60.getQuad(), DAT_010c44d0);
    m1F0.InitializeFields_00de5370((float)(DAT_01030f38 - (double)(float)fabs((double)fb0)), f1c * f10, f18, &t60, &receivers.m50);
    {
        PtrVec vec1, vec3, vec2;
        vec1.buf = 0;
        vec1.len = 0;
        vec1.cap = (int)0x80000000;
        vec3.buf = 0;
        vec3.len = 0;
        vec3.cap = (int)0x80000000;
        vec2.buf = 0;
        vec2.len = 0;
        vec2.cap = (int)0x80000000;
        Singleton* sing = hkMemoryRouter_getInstance();
        PoolObj* pool = sing->pool;
        if ((vec1.cap & 0x3fffffff) < 1)
        {
            int nc = (vec1.cap & 0x3fffffff) * 2;
            if (nc <= 1)
                nc = 1;
            hkArrayUtil__reserve(pool, &vec1, nc, 4);
        }
        vec1.len = 1;
        sing = hkMemoryRouter_getInstance();
        pool = sing->pool;
        if ((vec2.cap & 0x3fffffff) < 1)
        {
            int nc = (vec2.cap & 0x3fffffff) * 2;
            if (nc <= 1)
                nc = 1;
            hkArrayUtil__reserve(pool, &vec2, nc, 4);
        }
        vec2.len = 1;
        sing = hkMemoryRouter_getInstance();
        pool = sing->pool;
        if ((vec3.cap & 0x3fffffff) < 2)
        {
            int nc = (vec3.cap & 0x3fffffff) * 2;
            if (nc <= 2)
                nc = 2;
            hkArrayUtil__reserve(pool, &vec3, nc, 4);
        }
        vec3.len = 2;
        vec1.buf[0] = subD0;
        vec3.buf[0] = sub160;
        vec3.buf[1] = sub1F0;
        vec2.buf[0] = sub280;
        p2->DrawVec(&vec1, 0xffffff00, p3, p4);
        p2->DrawVec(&vec3, 0xffff0000, p3, p4);
        p2->DrawVec(&vec2, FUN_00cabb00(0xff, 0, 0xff, 0xff), p3, p4);
        sing = hkMemoryRouter_getInstance();
        pool = sing->pool;
        vec2.len = 0;
        if (!(vec2.cap & (int)0x80000000))
            pool->Release(vec2.buf, (vec2.cap & 0x3fffffff) * 4);
        vec2.buf = 0;
        vec2.cap = (int)0x80000000;
        sing = hkMemoryRouter_getInstance();
        pool = sing->pool;
        vec3.len = 0;
        if (!(vec3.cap & (int)0x80000000))
            pool->Release(vec3.buf, (vec3.cap & 0x3fffffff) * 4);
        vec3.buf = 0;
        vec3.cap = (int)0x80000000;
        sing = hkMemoryRouter_getInstance();
        pool = sing->pool;
        vec1.len = 0;
        if (!(vec1.cap & (int)0x80000000))
            pool->Release(vec1.buf, (vec1.cap & 0x3fffffff) * 4);
        vec1.buf = 0;
        vec1.cap = (int)0x80000000;
    }
}

