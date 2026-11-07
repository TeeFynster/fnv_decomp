
// src/havok/physics/collide/shape/convex/convextranslate/hkpconvextranslateshape_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/shape/convex/convextranslate/hkpconvextranslateshape.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/shape/convex/convextranslate/hkpconvextranslateshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/convex/convextranslate/hkpconvextranslateshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../../include/hkpConvexTranslateShape.h"
#include "../../../../../../../include/hkpConvexShape.h"
#include "../../../../../../../include/hkSphere.h"
// FUN_00dd5e60 : the stub family - load a sub-object pointer out of `this`
// and tail-jump to one of its virtuals.
//   mov ecx,[ecx+0x18] / mov eax,[ecx] / mov edx,[eax+0x2c] / jmp edx
// The target is in EDX, so the virtual takes NO stack argument.  MSVC puts the
// first virtual at vptr+0 (the RTTI pointer is at [vftable-4]), so vtable
// offset 0x2c needs twelve virtuals: eleven dummies and the real one.
struct Sub_dd5e60
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
};
struct Own_dd5e60
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    Sub_dd5e60* m_sub;  // at +0x18
    void __thiscall hkpConvexTranslateShape_getNumCollisionSpheresImpl();
};
struct Sub_dd5e70
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C(const char* name, void* child, int flags);
};
extern int DAT_01268940;
struct Own_dd5e70
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    void* m_sub;

    void __thiscall hkReferencedObject_calcContentStatistics(Sub_dd5e70* object, const int* attribute);
    void __thiscall AttachChildAndAttribute(Sub_dd5e70* object, int unused);
};
struct FUN_00dd5ea0_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    void* hkpConvexTranslateShape_getContainer();
};

#include <xmmintrin.h>
struct FUN_00dd5eb0_Sub
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual float v0C(__m128* a);
};
struct FUN_00dd5eb0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    FUN_00dd5eb0_Sub* m_18;
    int unk1C;
    __m128 unk20;
    float hkpConvexTranslateShape_getMaximumProjection(__m128* a);
};
// @fnv 0x00dd5eb0
// src: HAVOK_SRC 0x00dd5eb0
float FUN_00dd5eb0_cls::hkpConvexTranslateShape_getMaximumProjection(__m128* a)
{
    float d = m_18->v0C(a);
    __m128 m = _mm_mul_ps(*a, unk20);
    __m128 sum = _mm_add_ss(_mm_shuffle_ps(m, m, 0xaa), _mm_add_ss(_mm_shuffle_ps(m, m, 0x55), m));
    float dot;
    _mm_store_ss(&dot, sum);
    d += dot;
    return d;
}

struct Sub_dd5f10
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38(float* a, float* b);
};

struct Own_dd5f10
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    Sub_dd5f10* m_sub;
    int unk1C;
    __m128 m_trans;
    void __thiscall hkpConvexTranslateShape_getSupportingVertexImpl(float* a, float* b);
};
// @fnv 0x00dd5f10
// src: HAVOK_SRC 0x00dd5f10
void __thiscall Own_dd5f10::hkpConvexTranslateShape_getSupportingVertexImpl(float* a, float* b)
{
    Sub_dd5f10* s = m_sub;
    s->v38(a, b);
    __m128* pb = (__m128*)b;
    *pb = _mm_add_ps(m_trans, *pb);
}

// Slots 0x2c/0x30 are GetNumCollisionSpheres/GetCollisionSpheres (the convex-vertices implementations bind at 0x00d58d10/0x00d58d80).
// The shared translate-shape header does not yet declare this override.
class ConvexTranslateCollisionSpheresView : public hkpConvexTranslateShape
{
  public:
    virtual const hkSphere* GetCollisionSpheres(hkSphere* pBuffer) const;
};

// @fnv 0x00dd6000
const hkSphere* ConvexTranslateCollisionSpheresView::GetCollisionSpheres(hkSphere* pBuffer) const
{
    hkSphere* pDst = pBuffer;
    const hkSphere* m_pkDeltas = static_cast<const hkpConvexShape*>(m_pContainedShape.m_pContainedShape)->GetCollisionSpheres(pDst);
    int iEntryIndex = static_cast<const hkpConvexShape*>(m_pContainedShape.m_pContainedShape)->GetNumCollisionSpheres();
    for (int i = 0; i < iEntryIndex; ++i)
    {
        pDst->m_pos.m_vComponents = _mm_add_ps(m_pkDeltas->m_pos.m_vComponents, m_vTranslation.m_vComponents);
        ++m_pkDeltas;
        ++pDst;
    }
    return pBuffer;
}

#include <string.h>
struct __declspec(align(16)) MyVec
{
    union
    {
        __m128 quad;
        struct
        {
            float x, y, z, w;
        };
    };
};

struct __declspec(align(16)) MyTransform
{
    MyVec col0;
    MyVec col1;
    MyVec col2;
    MyVec col3;
};

struct LocalCdBody
{
    MyTransform m_kMotionTransform;
    void hkTransform_setMul(const void*, const MyTransform*);
};

struct Context2
{
    void* m_pContainedShape;
    int m_zero;
    const void* m_localBody;
    const Context2* m_parentContext;
};

struct ChildShape
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24(MyVec* vectors, const Context2* c2, int value);
};

struct Dummy
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    ChildShape* m_pContainedShape;
    MyVec m_vTranslation;

    void hkpConvexTranslateShape_castRayWithCollectorImpl(const MyVec* points, const Context2* context, int value);
};

// @fnv 0x00dd61b0
// src: HAVOK_SRC 0x00dd61b0
void Dummy::hkpConvexTranslateShape_castRayWithCollectorImpl(const MyVec* points, const Context2* context, int value)
{
    __m128 p1 = m_vTranslation.quad;
    __m128 s = _mm_sub_ps(points[0].quad, p1);

    MyVec localBody[3];
    memcpy(localBody, points, 48);

    const void* motion = context->m_localBody;

    localBody[0].quad = s;
    __m128 t = _mm_sub_ps(points[1].quad, p1);

    MyTransform c;
    localBody[1].quad = t;

    c.col0.quad = _mm_setzero_ps();
    c.col0.x = 1.0f;
    c.col1.quad = _mm_setzero_ps();
    c.col1.y = 1.0f;
    c.col2.quad = _mm_setzero_ps();
    c.col3.quad = p1;
    c.col2.z = 1.0f;

    LocalCdBody r;
    r.hkTransform_setMul(motion, &c);

    Context2 trans;
    trans.m_localBody = &r;
    trans.m_parentContext = context;
    trans.m_pContainedShape = m_pContainedShape;
    trans.m_zero = 0;

    m_pContainedShape->v24(localBody, &trans, value);
}
