
// src/havok/physics/collide/shape/convex/convextransform/hkpconvextransformshape_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/shape/convex/convextransform/hkpconvextransformshape.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/shape/convex/convextransform/hkpconvextransformshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/convex/convextransform/hkpconvextransformshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../../../../include/V4.h"
#include "../../../../../../../include/hkBool.h"
#include "../../../../../../../include/hkpConvexTransformShape.h"
#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkVector4q.h"
extern const char* const g_01268970_arg1;
struct FUN_00d5d730_class
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(const char*, const char*, int);
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    void hkpConvexTransformShape_calcContentStatistics(FUN_00d5d730_class* pChild, const char* name);
};
struct FUN_00c90360_helper
{
    void hkReferencedObject_calcContentStatistics(FUN_00d5d730_class* pChild, const char* const* name);
};
struct FUN_00d5e020_standin
{
    int hkpConvexTransformShape_calcSizeForSpu(int a, int b);
};
struct Inner
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void Tail();
};
struct FUN_00d5d720_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    Inner* m_pInner;
    void hkpConvexTransformShape_getNumCollisionSpheresImpl();
};
struct GetChildShapeHost : hkpConvexTransformShapeBase
{
    hkpSingleShapeContainer* hkpConvexTransformShape_getContainer();
};
struct Aabb_00d5d800;
struct Shape_00d5d800
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void getAabb(const hkTransform& t, float tol, Aabb_00d5d800& out) = 0;
};
struct Xf_00d5d800 : hkTransform
{
    void hkTransform_setMul(const hkTransform& a, const hkTransform& b);
};
struct Cls_00d5d800
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    hkpShape* m_pContainedShape;
    int unk1c;
    hkTransform m_kMotionTransform;
    void GetAabb(const hkTransform& t, float tol, Aabb_00d5d800& out);
};
extern "C" unsigned long DAT_0126835c;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern const char str_010d1074[];
extern const char str_010c41f8[];
struct hkVector4Rot : public hkVector4
{
    void SetRotatedDirection(const hkRotation& r, const hkVector4& v);
};
struct hkTransformq
{
    hkVector4q m_kColumn0;
    hkVector4q m_kColumn1;
    hkVector4q m_kColumn2;
    hkVector4q m_vTranslation;
};
struct ShapeRayCastQuery
{
    hkVector4q m_vFrom;
    hkVector4q m_vTo;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
};
struct ShapeRayCastOutput
{
    hkVector4 m_vHitNormal;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;
};
static __forceinline __m128 rt_inv(const hkTransformq& tr, const hkVector4q& in)
{
    __m128 t0 = _mm_sub_ps(in.m_vComponents, tr.m_vTranslation.m_vComponents);
    __m128 c0 = tr.m_kColumn0.m_vComponents;
    __m128 c1 = tr.m_kColumn1.m_vComponents;
    __m128 c2 = tr.m_kColumn2.m_vComponents;
    __m128 tmp = _mm_unpacklo_ps(c0, c1);
    __m128 ctmp = _mm_unpackhi_ps(c0, c1);
    c0 = _mm_movelh_ps(tmp, c2);
    ctmp = _mm_shuffle_ps(ctmp, c2, 0xe4);
    c1 = _mm_shuffle_ps(_mm_movehl_ps(c0, tmp), c2, 0xd4);
    c2 = ctmp;
    __m128 b0 = _mm_shuffle_ps(t0, t0, 0x00);
    __m128 r0 = _mm_mul_ps(c0, b0);
    __m128 b1 = _mm_shuffle_ps(t0, t0, 0x55);
    __m128 r1 = _mm_mul_ps(c1, b1);
    __m128 b2 = _mm_shuffle_ps(t0, t0, 0xaa);
    __m128 r2 = _mm_mul_ps(c2, b2);
    return _mm_add_ps(_mm_add_ps(r0, r1), r2);
}
struct RtChild : public hkpShape
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual hkBool RayCast(const ShapeRayCastQuery& input, ShapeRayCastOutput& output) const;
};
struct RtStandin : public hkpConvexTransformShape
{
    hkBool hkpConvexTransformShape_castRayImpl(const ShapeRayCastQuery& input, ShapeRayCastOutput& output) const;
};
static __forceinline void timer_begin(const char* name)
{
    hkMonitorStream* stream = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    char* ptr = stream->m_end.m_storage;
    if (ptr < stream->m_capacityMinus16.m_storage)
    {
        *(const char**)ptr = name;
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        *(unsigned int*)(ptr + 4) = t;
        ptr += 12;
        stream->m_end.m_storage = ptr;
    }
}
struct FUN_00d5de40_Child
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void vf40();
    virtual void vf44(hkVector4* value)
    {}
};
struct FUN_00d5de40_Obj
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void vf40();
    virtual void vf44(hkVector4* value)
    {}

    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    FUN_00d5de40_Child* unk18;
    int unk1c;
    hkVector4 unk20;
    hkVector4 unk30;
    hkVector4 unk40;
    hkVector4 unk50;

    void hkpConvexTransformShape_getCentreImpl(hkVector4* value);
};

struct ChildShape
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void GetSupportPoint(const V4& dir, V4& out);
};

struct XformShape
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    ChildShape* m_pChildAtom;
    int unk1c;
    __m128 m_c0, m_c1, m_c2, m_t;
    void hkpConvexTransformShape_getSupportingVertexImpl(const V4& dir, V4& out);
};

// @fnv 0x00d5dc70
// src: HAVOK_SRC 0x00d5dc70
void XformShape::hkpConvexTransformShape_getSupportingVertexImpl(const V4& dir, V4& out)
{
    __m128 a = m_c0, b = m_c1, c = m_c2;
    __m128 tmp = _mm_unpacklo_ps(a, b);
    __m128 ctmp = _mm_shuffle_ps(_mm_unpackhi_ps(a, b), c, 0xe4);
    a = _mm_movelh_ps(tmp, c);
    tmp = _mm_movehl_ps(a, tmp);
    b = _mm_shuffle_ps(tmp, c, 0xd4);
    c = ctmp;
    __m128 d = *(const __m128*)&dir;
    __m128 localDirStorage;
    V4& localDir = reinterpret_cast<V4&>(localDirStorage);
    *(__m128*)&localDir =
        _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(*(const __m128*)&dir, *(const __m128*)&dir, 0x00), a),
                              _mm_mul_ps(_mm_shuffle_ps(d, d, 0x55), b)),
                   _mm_mul_ps(_mm_shuffle_ps(d, d, 0xaa), c));
    __m128 supportStorage;
    V4& v = reinterpret_cast<V4&>(supportStorage);
    m_pChildAtom->GetSupportPoint(localDir, v);
    __m128 s = *(__m128*)&v;
    __m128 r = _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(s, s, 0x55), _mm_load_ps((const float*)&m_c1)),
                                     _mm_mul_ps(_mm_shuffle_ps(s, s, 0x00), _mm_load_ps((const float*)&m_c0))),
                          _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(s, s, 0xaa), _mm_load_ps((const float*)&m_c2)),
                                     _mm_load_ps((const float*)&m_t)));
    *(__m128*)&out = _mm_shuffle_ps(r, _mm_unpackhi_ps(r, s), 0xc4);
}
