
// src/havok/physics/collide/shape/convex/hkpconvexshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/convex/hkpconvexshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#define FNV_VEC4_SIMD
#include "../../../../../../include/Vec4.h"
#include "../../../../../../include/hkReferencedObject.h"
#include "../../../../../../include/hkpShape.h"
#include "../../../../../../include/hkpConvexShape.h"
#include "../../../../../../include/hkpSingleShapeContainer.h"

// @fnv 0x00c9e1e0
// src: COMMUNITY 0x00c9e1e0
int __stdcall hkpConvexShape_weldContactPointImpl(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    return 2;
}

// Inline Havok constructors used by this unit's convex transform base constructor.


template <typename ENUM, typename STORAGE>
inline hkEnum<ENUM, STORAGE>::hkEnum() {}

inline hkpShape::hkpShape() { m_ulUserData = 0; }

inline hkpConvexShape::hkpConvexShape(int type, float radius)
{
    m_fSphereRadius = radius;
    *reinterpret_cast<unsigned int*>(&m_type) = type;
}

inline hkpSingleShapeContainer::hkpSingleShapeContainer(hkpShape* child, int ref)
    : m_pContainedShape(child)
{
    if (ref == 1)
        child->addReference();
}

class FUN_00c9e340 : public hkpConvexShape
{
  public:
    hkpSingleShapeContainer m_pContainedShape;

    FUN_00c9e340(int iType, hkReal fRadius, hkpShape* pkChild, int iRef) throw();
    virtual ~FUN_00c9e340() throw();
};

// @fnv 0x00c9e340
FUN_00c9e340::FUN_00c9e340(int iShapeType, hkReal fRadius, hkpShape* pkChild, int iRef) throw()
    : hkpConvexShape(iShapeType, fRadius), m_pContainedShape(pkChild, iRef)
{}

#include <xmmintrin.h>
// The shared convex shape lacks this projection override; keep its body as a helper.
// The unused register parameter preserves the original member-call ABI without a stand-in class.
// @fnv 0x00c9e1f0
float __fastcall ConvexMaximumProjection(const hkpConvexShape* shape, void*, int arg)
{
    __declspec(align(16)) float buf[4];
    shape->GetSupportVertex(*reinterpret_cast<const hkVector4*>(arg),
                            *reinterpret_cast<Vector4WithInt24W*>(buf));

    __m128 v = _mm_load_ps(reinterpret_cast<const float*>(arg));
    __m128 w = _mm_load_ps(buf);
    __m128 vProduct = _mm_mul_ps(v, w);

    __m128 s1 = _mm_shuffle_ps(vProduct, vProduct, 0x55);
    __m128 s2 = _mm_shuffle_ps(vProduct, vProduct, 0xAA);

    s1 = _mm_add_ss(s1, vProduct);
    s2 = _mm_add_ss(s2, s1);

    float dot;
    _mm_store_ss(&dot, s2);
    return shape->m_fSphereRadius + dot;
}

// hkRotation layout (three Vec4 columns).
struct ConvexRotation
{
    Vec4 c0, c1, c2;
};

struct Out
{
    Vec4 v;
    float t;
    int flags;
    int unk01;
    int unk02;
    int b;
    int unk03;
    int unk04;
    int unk05;
    int unk06;
    int unk07;
    int unk08;
    int unk09;
    int c;
};

struct P2
{
    int unk0;
    int unk1;
    ConvexRotation* m;
};

struct Cb;

struct VTable
{
    void(__thiscall* fn)(Cb*, P2*, Vec4*);
};

struct Cb
{
    VTable* vt;
    float f;
};

class Shape
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(bool* ok, void* p1, Out* out);
};

struct FN : public Shape
{
    void hkpBoxShape_castRayWithCollectorImpl(int p1, int p2, Cb* p3);
};

// Calls v8 to fill out.v, multiplies it by the Mat3 in P2, stores the result back, then invokes the VTable callback fn on Cb.
// @fnv 0x00c9e2a0
// src: HAVOK_SRC 0x00c9e2a0
void FN::hkpBoxShape_castRayWithCollectorImpl(int p1, int p2, Cb* apCb)
{
    bool ok;
    Out out;

    out.t = apCb->f;
    out.flags = -1;
    out.b = -1;
    out.c = 0;

    this->v8(&ok, (void*)(*(volatile int*)&p1), &out);

    if (ok)
    {
        __m128 v = _mm_load_ps(&out.v.x);
        int p2Value = p2;
        P2* pP2 = (P2*)p2Value;
        ConvexRotation* m = pP2->m;
        VTable* vt = apCb->vt;
        void(__thiscall * fn)(Cb*, P2*, Vec4*) = vt->fn;

        __m128 c0 = _mm_load_ps(&m->c0.x);
        __m128 c1 = _mm_load_ps(&m->c1.x);
        __m128 c2 = _mm_load_ps(&m->c2.x);

        __m128 r = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), c1), _mm_mul_ps(_mm_shuffle_ps(v, v, 0), c0));
        r = _mm_add_ps(r, _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), c2));

        _mm_store_ps(&out.v.x, r);
        fn(apCb, pP2, &out.v);
    }
}
