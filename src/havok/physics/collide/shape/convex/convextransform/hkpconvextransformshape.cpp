
// src/havok/physics/collide/shape/convex/convextransform/hkpconvextransformshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/convex/convextransform/hkpconvextransformshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../include/hkBool.h"
#define FNV64_HKVECTOR4_OWN_COPY
#define FNV64_HKVECTOR4_OWN_ASSIGN
#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/hkBaseObject.h"
#include "../../../../../../../include/hkMatrix3.h"
#include "../../../../../../../include/hkRotation.h"
#include "../../../../../../../include/hkTransform.h"
#include <string.h>

// Retain the scalar aggregate copy operations used by this unit.
__forceinline hkVector4::hkVector4(const hkVector4& other)
{
    memcpy(this, &other, sizeof(*this));
}

__forceinline void hkVector4::operator=(const hkVector4& other)
{
    memcpy(this, &other, sizeof(*this));
}


#include "../../../../../../../include/hkpShape.h"
#include "../../../../../../../include/hkpConvexShape.h"
#include "../../../../../../../include/hkpConvexTransformShape.h"
#include "../../../../../../../include/hkVector4q.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkpCdBody.h"


// Keep the original intrinsic representation: its aliasing affects SIMD register allocation.
namespace fnv_simd {
// Exe 0x00d5d800 GetAabb: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C" LocalM128 _mm_sub_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_add_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_unpacklo_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_unpackhi_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_movelh_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_movehl_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
extern "C" void _ReadWriteBarrier(void);

extern "C" LocalM128 _mm_load_ps(const float*);
extern "C" void _mm_store_ps(float*, LocalM128);
extern "C" LocalM128 _mm_add_ss(LocalM128, LocalM128);
extern "C" LocalM128 _mm_load_ps1(const float*);
extern "C" void _mm_store_ss(float*, LocalM128);
}
typedef fnv_simd::LocalM128 ShapeQuad;

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

// Calls pChild->v3 with "Child" and this+0x18, then FUN_00c90360 with pChild and g_01268970_arg1.
// @fnv 0x00d5d730
// src: HAVOK_SRC 0x00d5d730
void FUN_00d5d730_class::hkpConvexTransformShape_calcContentStatistics(FUN_00d5d730_class* pChild, const char* name)
{
    pChild->v3("Child", *(const char**)((char*)this + 0x18), 0);
    ((FUN_00c90360_helper*)this)->hkReferencedObject_calcContentStatistics(pChild, &g_01268970_arg1);
}

struct FUN_00d5e020_standin
{
    int hkpConvexTransformShape_calcSizeForSpu(int a, int b);
};

// @fnv 0x00d5e020
// src: HAVOK_LIB 0x00d5e020
int FUN_00d5e020_standin::hkpConvexTransformShape_calcSizeForSpu(int a, int aiLimit)
{
    char* p = (char*)this;
    int iLimit = aiLimit - 0x60;
    int iResult =
        (*(int(__thiscall**)(void*, int, int))(*(int*)(*(int*)(p + 0x18)) + 0x18))(*(void**)(p + 0x18), a, iLimit);
    if (iResult < 0)
        return -1;
    if (iResult > iLimit)
        return -1;
    if (*(int*)(p + 0x18) == (int)(p + 0x60))
    {
        *(int*)(p + 0x1c) = 0;
        return iResult + 0x60;
    }
    *(int*)(p + 0x1c) = iResult;
    return 0x60;
}

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

// @fnv 0x00d5d720
// src: HAVOK_SRC 0x00d5d720
void FUN_00d5d720_cls::hkpConvexTransformShape_getNumCollisionSpheresImpl()
{
    m_pInner->Tail();
}

struct GetChildShapeHost : hkpConvexTransformShapeBase
{
    hkpSingleShapeContainer* hkpConvexTransformShape_getContainer();
};

// @fnv 0x00d5d760
// src: HAVOK_SRC 0x00d5d760
hkpSingleShapeContainer* GetChildShapeHost::hkpConvexTransformShape_getContainer()
{
    return &m_pContainedShape;
}

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

// Combines t and m_kMotionTransform via FUN_00cb2240 and calls the contained shape's getAabb with the result, tol and out.
// @fnv 0x00d5d800
void Cls_00d5d800::GetAabb(const hkTransform& t, float tol, Aabb_00d5d800& out)
{
    __declspec(align(16)) ShapeQuad storage[4];
    hkTransform& tmp = reinterpret_cast<hkTransform&>(storage);
    tmp.hkTransform_setMul(t, m_kMotionTransform);
    reinterpret_cast<Shape_00d5d800*>(m_pContainedShape)->getAabb(tmp, tol, out);
}


extern "C" unsigned long DAT_0126835c;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern const char str_010d1074[];
extern const char str_010c41f8[];



struct hkTransformq
{
    hkVector4q m_kColumn0;
    hkVector4q m_kColumn1;
    hkVector4q m_kColumn2;
    hkVector4q m_vTranslation;
};

__forceinline void hkVector4q::SetTransformedPoint(const hkTransformq& t, const hkVector4q& b)
{
    const ShapeQuad input = reinterpret_cast<const ShapeQuad&>(b);
    const ShapeQuad column1 = reinterpret_cast<const ShapeQuad&>(t.m_kColumn1);
    const ShapeQuad column0 = reinterpret_cast<const ShapeQuad&>(t.m_kColumn0);
    const ShapeQuad column2 = reinterpret_cast<const ShapeQuad&>(t.m_kColumn2);
    const ShapeQuad translation = reinterpret_cast<const ShapeQuad&>(t.m_vTranslation);
    const ShapeQuad first = fnv_simd::_mm_add_ps(fnv_simd::_mm_mul_ps(fnv_simd::_mm_shuffle_ps(input, input, 0x55), column1),
                                   fnv_simd::_mm_mul_ps(fnv_simd::_mm_shuffle_ps(input, input, 0), column0));
    const ShapeQuad second = fnv_simd::_mm_add_ps(fnv_simd::_mm_mul_ps(fnv_simd::_mm_shuffle_ps(input, input, 0xaa), column2), translation);
    reinterpret_cast<ShapeQuad&>(*this) = fnv_simd::_mm_add_ps(first, second);
}


struct __declspec(align(16)) ShapeRayCastQuery
{
    // Preserve the original whole-query copy with the shared vector constructors.
    __forceinline ShapeRayCastQuery(const ShapeRayCastQuery& other)
    {
        memcpy(this, &other, sizeof(*this));
    }

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

static __forceinline ShapeQuad rt_inv(const hkTransformq& tr, const hkVector4q& in)
{
    ShapeQuad t0 = fnv_simd::_mm_sub_ps(reinterpret_cast<const ShapeQuad&>(in), reinterpret_cast<const ShapeQuad&>(tr.m_vTranslation));
    ShapeQuad c0 = reinterpret_cast<const ShapeQuad&>(tr.m_kColumn0);
    ShapeQuad c1 = reinterpret_cast<const ShapeQuad&>(tr.m_kColumn1);
    ShapeQuad c2 = reinterpret_cast<const ShapeQuad&>(tr.m_kColumn2);
    ShapeQuad tmp = fnv_simd::_mm_unpacklo_ps(c0, c1);
    ShapeQuad ctmp = fnv_simd::_mm_unpackhi_ps(c0, c1);
    c0 = fnv_simd::_mm_movelh_ps(tmp, c2);
    ctmp = fnv_simd::_mm_shuffle_ps(ctmp, c2, 0xe4);
    c1 = fnv_simd::_mm_shuffle_ps(fnv_simd::_mm_movehl_ps(c0, tmp), c2, 0xd4);
    c2 = ctmp;
    ShapeQuad b0 = fnv_simd::_mm_shuffle_ps(t0, t0, 0x00);
    ShapeQuad r0 = fnv_simd::_mm_mul_ps(c0, b0);
    ShapeQuad b1 = fnv_simd::_mm_shuffle_ps(t0, t0, 0x55);
    ShapeQuad r1 = fnv_simd::_mm_mul_ps(c1, b1);
    ShapeQuad b2 = fnv_simd::_mm_shuffle_ps(t0, t0, 0xaa);
    ShapeQuad r2 = fnv_simd::_mm_mul_ps(c2, b2);
    return fnv_simd::_mm_add_ps(fnv_simd::_mm_add_ps(r0, r1), r2);
}

struct RtStandin : public hkpConvexTransformShape
{
    hkBool hkpConvexTransformShape_castRayImpl(const ShapeRayCastQuery& input, ShapeRayCastOutput& output) const;
};

static __forceinline void timer_begin(const char* name)
{
    hkMonitorStream* stream = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    char* ptr = stream->m_end.m_storage;
    if (ptr < stream->m_capacityMinus16.val())
    {
        *(const char**)ptr = name;
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        *(unsigned int*)(ptr + 4) = t;
        ptr += 12;
        stream->m_end.m_storage = ptr;
    }
}

// Transforms the ray endpoints into local space, delegates to the contained child shape, and rotates the hit direction back to world space.
// @fnv 0x00d5d940
// src: HAVOK_SRC 0x00d5d940
hkBool RtStandin::hkpConvexTransformShape_castRayImpl(const ShapeRayCastQuery& input, ShapeRayCastOutput& output) const
{
    timer_begin(str_010d1074);

    ShapeRayCastQuery localInput = input;
    reinterpret_cast<ShapeQuad&>(localInput.m_vFrom) = rt_inv(reinterpret_cast<const hkTransformq&>(m_kMotionTransform), reinterpret_cast<const hkVector4q&>(input.m_vFrom));

    reinterpret_cast<ShapeQuad&>(localInput.m_vTo) = rt_inv(reinterpret_cast<const hkTransformq&>(m_kMotionTransform), reinterpret_cast<const hkVector4q&>(input.m_vTo));

    ++output.m_uiShapeKeyIndex;
    const hkpShape* child = m_pContainedShape.m_pContainedShape;
    hkBool res = child->IntersectRayWithShape(localInput, output);
    --output.m_uiShapeKeyIndex;

    if (res)
    {
        hkVector4 temp = output.m_vHitNormal;
        output.m_vHitNormal.SetRotatedDirection(m_kMotionTransform.m_rotation, temp);
        output.m_uiShapeKeys[output.m_uiShapeKeyIndex] = 0;
    }

    timer_begin(str_010c41f8);
    return res;
}

__forceinline hkpCdBody::hkpCdBody(const hkpCdBody* parent, const void* motionState)
{
    m_pMotionState = motionState;
    m_parent = parent;
}

__forceinline void hkpCdBody::SetCollisionShapeAndKey(const hkpShape* shape, unsigned int key)
{
    m_pCollisionShape = shape;
    m_uiCollisionShapeKey = key;
}

namespace fnv_00d5dae0 {
extern "C" unsigned long DAT_0126835c;
extern "C" const char str_010d1084[];
extern "C" const char str_010c41f8[];
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern "C" unsigned __int64 __rdtsc(void);

struct ShapeRayCastQuery
{
    __forceinline ShapeRayCastQuery(const ShapeRayCastQuery& other)
    {
        memcpy(this, &other, sizeof(*this));
    }

    hkVector4 m_vFrom;
    hkVector4 m_vTo;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
};



static __forceinline ShapeQuad rotateInverse(const hkTransform& a, const hkVector4& b)
{
    ShapeQuad t = fnv_simd::_mm_sub_ps((const ShapeQuad&)b, (const ShapeQuad&)a.m_vTranslation);
    ShapeQuad c0 = (const ShapeQuad&)a.m_rotation.m_kColumn0;
    ShapeQuad c1 = (const ShapeQuad&)a.m_rotation.m_kColumn1;
    ShapeQuad c2 = (const ShapeQuad&)a.m_rotation.m_kColumn2;
    ShapeQuad tmp = fnv_simd::_mm_unpacklo_ps(c0, c1);
    ShapeQuad ctmp = fnv_simd::_mm_unpackhi_ps(c0, c1);
    c0 = fnv_simd::_mm_movelh_ps(tmp, c2);
    c1 = fnv_simd::_mm_movehl_ps(c0, tmp);
    c1 = fnv_simd::_mm_shuffle_ps(c1, c2, 0xd4);
    c2 = fnv_simd::_mm_shuffle_ps(ctmp, c2, 0xe4);
    ShapeQuad b0 = fnv_simd::_mm_shuffle_ps(t, t, 0x00);
    ShapeQuad b1 = fnv_simd::_mm_shuffle_ps(t, t, 0x55);
    ShapeQuad b2 = fnv_simd::_mm_shuffle_ps(t, t, 0xaa);
    return fnv_simd::_mm_add_ps(fnv_simd::_mm_add_ps(fnv_simd::_mm_mul_ps(b0, c0), fnv_simd::_mm_mul_ps(b1, c1)), fnv_simd::_mm_mul_ps(b2, c2));
}

class hkpConvexTransformShapeWrapper : public hkpConvexTransformShape
{
  public:
    void hkpConvexTransformShape_castRayWithCollectorImpl(const ShapeRayCastQuery& input, const hkpCdBody& cdBody, hkpRayHitCollector& collector) const;
};

// Transforms the ray endpoints into the contained shape's local space and delegates the ray cast to the contained shape with a derived motion state.
// @fnv 0x00d5dae0
// src: HAVOK_SRC 0x00d5dae0
void hkpConvexTransformShapeWrapper::hkpConvexTransformShape_castRayWithCollectorImpl(const ShapeRayCastQuery& input, const hkpCdBody& cdBody,
                                                  hkpRayHitCollector& collector) const
{
    hkMonitorStream* stream = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    hkMonitorStream::TimerCommand* pMonitorEntry =
        (hkMonitorStream::TimerCommand*)stream->m_end.val();
    if ((char*)pMonitorEntry < stream->m_capacityMinus16.val())
    {
        pMonitorEntry->m_commandAndMonitor = str_010d1084;
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        pMonitorEntry->m_time0 = t;
        stream->m_end.m_storage = (char*)(pMonitorEntry + 1);
    }

    ShapeQuad vFromLocal = rotateInverse(m_kMotionTransform, input.m_vFrom);

    ShapeRayCastQuery localInput = input;
    (ShapeQuad&)localInput.m_vFrom = vFromLocal;

    ShapeQuad vToLocal = rotateInverse(m_kMotionTransform, input.m_vTo);
    (ShapeQuad&)localInput.m_vTo = vToLocal;

    __declspec(align(16)) ShapeQuad storage[4];
    hkTransform& transform = reinterpret_cast<hkTransform&>(storage);
    transform.hkTransform_setMul(*static_cast<const hkTransform*>(cdBody.m_pMotionState), m_kMotionTransform);

    hkpCdBody childCdBody(&cdBody, (const void*)&transform);
    childCdBody.SetCollisionShapeAndKey(m_pContainedShape.m_pContainedShape, 0);

    m_pContainedShape.m_pContainedShape->CastRayWithCollector(
        reinterpret_cast<const ::ShapeRayCastQuery&>(localInput), childCdBody, collector);

    hkMonitorStream* endStream = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    hkMonitorStream::TimerCommand* endEntry =
        (hkMonitorStream::TimerCommand*)endStream->m_end.val();
    if ((char*)endEntry < endStream->m_capacityMinus16.val())
    {
        endEntry->m_commandAndMonitor = str_010c41f8;
        _ReadWriteBarrier();
        volatile unsigned int uiEndTimestamp = (unsigned int)__rdtsc();
        endEntry->m_time0 = uiEndTimestamp;
        endStream->m_end.m_storage = (char*)(endEntry + 1);
    }
}
}  // namespace fnv_00d5dae0

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

// An explicit vtable word keeps this layout at +0x18/+0x20 with the aligned shared vectors.
struct FUN_00d5de40_Obj
{
    const void* m_vtable;
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

// @fnv 0x00d5de40
// src: HAVOK_SRC 0x00d5de40
void FUN_00d5de40_Obj::hkpConvexTransformShape_getCentreImpl(hkVector4* value)
{
    unk18->vf44(value);

    ShapeQuad input = *reinterpret_cast<const ShapeQuad*>(value);
    ShapeQuad column1 = *reinterpret_cast<const ShapeQuad*>(&unk30);
    ShapeQuad column0 = *reinterpret_cast<const ShapeQuad*>(&unk20);
    ShapeQuad column2 = *reinterpret_cast<const ShapeQuad*>(&unk40);
    ShapeQuad translation = *reinterpret_cast<const ShapeQuad*>(&unk50);

    ShapeQuad first = fnv_simd::_mm_add_ps(fnv_simd::_mm_mul_ps(fnv_simd::_mm_shuffle_ps(input, input, 0x55), column1),
                              fnv_simd::_mm_mul_ps(fnv_simd::_mm_shuffle_ps(input, input, 0), column0));
    ShapeQuad second = fnv_simd::_mm_add_ps(fnv_simd::_mm_mul_ps(fnv_simd::_mm_shuffle_ps(input, input, 0xaa), column2), translation);

    *reinterpret_cast<ShapeQuad*>(value) = fnv_simd::_mm_add_ps(first, second);
}

// The child call at vtable +0x34 is GetFirstVertex; the transform at +0x20 identifies the convex transform shape.
// The shared host header omits this override; unused EDX preserves its thiscall ABI without a local class copy.
// @fnv 0x00d5dea0
void __fastcall GetConvexTransformFirstVertex(const hkpConvexTransformShape* self, void*, hkVector4q& vertexOut)
{
    __declspec(align(16)) hkVector4 childVertex;
    static_cast<const hkpConvexShape*>(self->m_pContainedShape.m_pContainedShape)->GetFirstVertex(childVertex);
    vertexOut.SetTransformedPoint(reinterpret_cast<const hkTransformq&>(self->m_kMotionTransform),
                                 reinterpret_cast<const hkVector4q&>(childVertex));
}

struct FnvCpu_FUN_00d5d770_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    ShapeQuad field20;
    ShapeQuad field30;
    ShapeQuad field40;
    ShapeQuad field50;
    void CopyFromCpuData(hkTransform* input0);
};
// Copies the transform columns into the object's field20 through field50.
// @fnv 0x00d5d770
void FnvCpu_FUN_00d5d770_CpuObject::CopyFromCpuData(hkTransform* apCpuData)
{
    this->field20 = reinterpret_cast<const ShapeQuad&>(apCpuData->m_kColumn0);
    this->field30 = reinterpret_cast<const ShapeQuad&>(apCpuData->m_kColumn1);
    this->field40 = reinterpret_cast<const ShapeQuad&>(apCpuData->m_kColumn2);
    this->field50 = reinterpret_cast<const ShapeQuad&>(apCpuData->m_vTranslation);
}

extern int DAT_010d102c;

struct BaseHelper
{
    void* FUN_00c9e340(int a, float r, const hkpConvexShape* child, int refPolicy);
};

struct Standin
{
    const void* vtable;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    hkTransform m_kMotionTransform;

    Standin* hkpConvexTransformShape_hkpConvexTransformShape(const hkpConvexShape* childShape, const hkTransform& transform, int refPolicy);
};

// Calls FUN_00c9e340 with childShape and its m_fSphereRadius, sets the vtable, copies the four rows of transform into m_kMotionTransform, and returns this.
// @fnv 0x00d5d7a0
// src: EXE 0x00d5d7a0
Standin* Standin::hkpConvexTransformShape_hkpConvexTransformShape(const hkpConvexShape* childShape, const hkTransform& transform, int refPolicy)
{
    ((BaseHelper*)this)->FUN_00c9e340(0xc, childShape->m_fSphereRadius, childShape, refPolicy);
    this->vtable = &DAT_010d102c;
    reinterpret_cast<ShapeQuad&>(this->m_kMotionTransform.m_kColumn0) = reinterpret_cast<const ShapeQuad&>(transform.m_kColumn0);
    reinterpret_cast<ShapeQuad&>(this->m_kMotionTransform.m_kColumn1) = reinterpret_cast<const ShapeQuad&>(transform.m_kColumn1);
    reinterpret_cast<ShapeQuad&>(this->m_kMotionTransform.m_kColumn2) = reinterpret_cast<const ShapeQuad&>(transform.m_kColumn2);
    reinterpret_cast<ShapeQuad&>(this->m_kMotionTransform.m_vTranslation) = reinterpret_cast<const ShapeQuad&>(transform.m_vTranslation);
    return this;
}


struct TransformChild
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
    virtual void vf3c(int a, int b, int c);
};

struct TransformHost
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    TransformChild* unk18;
    int unk1c;
    hkVector4 unk20;
    hkVector4 unk30;
    hkVector4 unk40;
    hkVector4 unk50;

    void __thiscall hkpConvexTransformShape_convertVertexIdsToVerticesImpl(int a, int b, float* c);
};

// Calls unk18->vf3c(a, b, c), then transforms the b vectors in c in place by the matrix made from unk20, unk30, unk40 and unk50.
// @fnv 0x00d5dd40
// src: HAVOK_SRC 0x00d5dd40
void __thiscall TransformHost::hkpConvexTransformShape_convertVertexIdsToVerticesImpl(int a, int aiCount, float* apPoints)
{
    unk18->vf3c(a, aiCount, (int)apPoints);
    __declspec(align(16)) ShapeQuad storage[4];
    hkTransform& localTransform = reinterpret_cast<hkTransform&>(storage);
    reinterpret_cast<hkVector4&>(localTransform.m_kColumn0) = unk20;
    reinterpret_cast<hkVector4&>(localTransform.m_kColumn1) = unk30;
    reinterpret_cast<hkVector4&>(localTransform.m_kColumn2) = unk40;
    reinterpret_cast<hkVector4&>(localTransform.m_vTranslation) = unk50;
    ShapeQuad c0 = fnv_simd::_mm_load_ps(&reinterpret_cast<const hkVector4&>(localTransform.m_kColumn0).x);
    ShapeQuad c1 = fnv_simd::_mm_load_ps(&reinterpret_cast<const hkVector4&>(localTransform.m_kColumn1).x);
    ShapeQuad c2 = fnv_simd::_mm_load_ps(&reinterpret_cast<const hkVector4&>(localTransform.m_kColumn2).x);
    ShapeQuad c3 = fnv_simd::_mm_load_ps(&reinterpret_cast<const hkVector4&>(localTransform.m_vTranslation).x);
    int i = aiCount - 1;
    float* p = apPoints + i * 4;
    do
    {
        ShapeQuad v = fnv_simd::_mm_load_ps(p);
        ShapeQuad vy = fnv_simd::_mm_shuffle_ps(v, v, 0x55);
        ShapeQuad vx = fnv_simd::_mm_shuffle_ps(v, v, 0);
        ShapeQuad px = fnv_simd::_mm_mul_ps(vx, c0);
        ShapeQuad py = fnv_simd::_mm_mul_ps(vy, c1);
        ShapeQuad r = fnv_simd::_mm_add_ps(fnv_simd::_mm_add_ps(py, px), fnv_simd::_mm_add_ps(fnv_simd::_mm_mul_ps(fnv_simd::_mm_shuffle_ps(v, v, 0xaa), c2), c3));
        _ReadWriteBarrier();
        ShapeQuad old = fnv_simd::_mm_load_ps(p);
        fnv_simd::_mm_store_ps(p, fnv_simd::_mm_shuffle_ps(r, fnv_simd::_mm_unpackhi_ps(r, old), 0xc4));
        --i;
        p -= 4;
    } while (i >= 0);
}

struct hkSphereq
{
    hkVector4q m_pos;
};

class hkpConvexShapeSpheres
{
  public:
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
    virtual int getNumCollisionSpheres() const;
    virtual const hkSphereq* getCollisionSpheres(hkSphereq* sphereBuffer) const;
};

class hkpConvexTransformShapeSpheres : public hkpConvexTransformShape
{
  public:
    const hkpConvexShapeSpheres* GetShapeForKey() const
    {
        return (const hkpConvexShapeSpheres*)m_pContainedShape.m_pContainedShape;
    }
    const hkSphereq* hkpConvexTransformShape_getCollisionSpheresImpl(hkSphereq* sphereBuffer) const;
};

static __forceinline void hkTransformPoints(const hkTransform& t, const hkVector4q* vectorsIn, int numVectors,
                                            hkVector4q* vectorsOut)
{
    hkVector4q c0;
    *reinterpret_cast<hkVector4*>(&c0) = t.m_rotation.m_kColumn0;
    hkVector4q c1;
    *reinterpret_cast<hkVector4*>(&c1) = t.m_rotation.m_kColumn1;
    hkVector4q c2;
    *reinterpret_cast<hkVector4*>(&c2) = t.m_rotation.m_kColumn2;
    hkVector4q trans;
    *reinterpret_cast<hkVector4*>(&trans) = reinterpret_cast<const hkVector4&>(t.m_vTranslation);
    int i = numVectors - 1;
    do
    {
        const ShapeQuad b = reinterpret_cast<const ShapeQuad&>(vectorsIn[i]);
        const ShapeQuad b0 = fnv_simd::_mm_shuffle_ps(b, b, 0x00);
        const ShapeQuad r0 = fnv_simd::_mm_mul_ps(reinterpret_cast<const ShapeQuad&>(c0), b0);
        const ShapeQuad b1 = fnv_simd::_mm_shuffle_ps(b, b, 0x55);
        const ShapeQuad r1 = fnv_simd::_mm_mul_ps(reinterpret_cast<const ShapeQuad&>(c1), b1);
        const ShapeQuad b2 = fnv_simd::_mm_shuffle_ps(b, b, 0xaa);
        const ShapeQuad r2 = fnv_simd::_mm_mul_ps(reinterpret_cast<const ShapeQuad&>(c2), b2);
        const ShapeQuad p = fnv_simd::_mm_add_ps(fnv_simd::_mm_add_ps(r0, r1), fnv_simd::_mm_add_ps(r2, reinterpret_cast<const ShapeQuad&>(trans)));
        reinterpret_cast<ShapeQuad&>(vectorsOut[i]) = fnv_simd::_mm_shuffle_ps(p, fnv_simd::_mm_unpackhi_ps(p, reinterpret_cast<const ShapeQuad&>(vectorsIn[i])), 0xc4);
    } while (--i >= 0);
}

// Transforms the contained shape's collision spheres by the motion transform and writes them into the provided buffer.
// @fnv 0x00d5df10
// src: HAVOK_SRC 0x00d5df10
const hkSphereq* hkpConvexTransformShapeSpheres::hkpConvexTransformShape_getCollisionSpheresImpl(hkSphereq* sphereBuffer) const
{
    const hkSphereq* spheres = GetShapeForKey()->getCollisionSpheres(sphereBuffer);
    int numSpheres = GetShapeForKey()->getNumCollisionSpheres();
    hkTransformPoints(m_kMotionTransform, &spheres->m_pos, numSpheres, &sphereBuffer->m_pos);
    return sphereBuffer;
}


class ConvexChild_d5d8
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual float getMaximumProjection(const hkVector4q& direction) const;
};

class TransformShape_d5d8
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    ConvexChild_d5d8* m_pContainedShape;
    int unk1c;
    ShapeQuad m_kColumn0;
    ShapeQuad m_kColumn1;
    ShapeQuad m_kColumn2;
    ShapeQuad m_vTranslation;

    float hkpConvexTransformShape_getMaximumProjection(const ShapeQuad& direction);
};

// @fnv 0x00d5d840
// src: HAVOK_SRC 0x00d5d840
float TransformShape_d5d8::hkpConvexTransformShape_getMaximumProjection(const ShapeQuad& direction)
{
    ShapeQuad c0 = m_kColumn0;
    ShapeQuad c1 = m_kColumn1;
    ShapeQuad c2 = m_kColumn2;
    {
        ShapeQuad t = fnv_simd::_mm_unpacklo_ps(c0, c1);
        ShapeQuad ct = fnv_simd::_mm_unpackhi_ps(c0, c1);
        c0 = fnv_simd::_mm_movelh_ps(t, c2);
        c1 = fnv_simd::_mm_movehl_ps(c0, t);
        c1 = fnv_simd::_mm_shuffle_ps(c1, c2, 0xd4);
        c2 = fnv_simd::_mm_shuffle_ps(ct, c2, 0xe4);
    }
    ShapeQuad dir = direction;
    ShapeQuad b1 = fnv_simd::_mm_shuffle_ps(dir, dir, 0x55);
    ShapeQuad b0 = fnv_simd::_mm_shuffle_ps(dir, dir, 0x00);
    ShapeQuad b2 = fnv_simd::_mm_shuffle_ps(dir, dir, 0xaa);
    hkVector4q localDir;
    *(ShapeQuad*)&localDir = fnv_simd::_mm_add_ps(fnv_simd::_mm_add_ps(fnv_simd::_mm_mul_ps(b1, c1), fnv_simd::_mm_mul_ps(b0, c0)), fnv_simd::_mm_mul_ps(b2, c2));

    float projection = m_pContainedShape->getMaximumProjection(localDir);

    ShapeQuad support = fnv_simd::_mm_mul_ps(fnv_simd::_mm_load_ps1(&projection), *(const ShapeQuad*)&localDir);
    ShapeQuad world =
        fnv_simd::_mm_add_ps(fnv_simd::_mm_add_ps(fnv_simd::_mm_mul_ps(fnv_simd::_mm_shuffle_ps(support, support, 0x55), m_kColumn1),
                              fnv_simd::_mm_mul_ps(fnv_simd::_mm_shuffle_ps(support, support, 0x00), m_kColumn0)),
                   fnv_simd::_mm_add_ps(fnv_simd::_mm_mul_ps(fnv_simd::_mm_shuffle_ps(support, support, 0xaa), m_kColumn2), m_vTranslation));
    ShapeQuad prod = fnv_simd::_mm_mul_ps(world, direction);
    ShapeQuad sum = fnv_simd::_mm_add_ss(fnv_simd::_mm_shuffle_ps(prod, prod, 0xaa), fnv_simd::_mm_add_ss(fnv_simd::_mm_shuffle_ps(prod, prod, 0x55), prod));
    float result;
    fnv_simd::_mm_store_ss(&result, sum);
    return result;
}
