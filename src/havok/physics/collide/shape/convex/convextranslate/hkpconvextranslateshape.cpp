
// src/havok/physics/collide/shape/convex/convextranslate/hkpconvextranslateshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/convex/convextranslate/hkpconvextranslateshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Exe 0x00dd5f50 FUN_00dd5f50: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C" LocalM128 _mm_add_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_load_ps(const float*);
extern "C" void _mm_store_ps(float*, LocalM128);
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, int);

#include "../../../../../../../include/hkpConvexTranslateShape.h"
#include "../../../../../../../include/hkpShape.h"
#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/hkRotation.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include "../../../../../../../include/hkMonitorStream.h"
#include <string.h>

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

// @fnv 0x00dd5e60
// src: HAVOK_SRC 0x00dd5e60
void __thiscall Own_dd5e60::hkpConvexTranslateShape_getNumCollisionSpheresImpl()
{
    m_sub->v2C();
}

// Vtable slot 0x18 is hkpShape::CalcSizeForSpu, not a shape-collection operation.
// The shared translate-shape header does not yet declare this override.
class ConvexTranslateSpuSizingView : public hkpConvexTranslateShape
{
  public:
    virtual int CalcSizeForSpu(const PhysicsShape& input, int spuBufferSizeLeft) const;
};

// @fnv 0x00dd5e10
int ConvexTranslateSpuSizingView::CalcSizeForSpu(const PhysicsShape& input, int spuBufferSizeLeft) const
{
    const int iMax = spuBufferSizeLeft - 0x30;
    int iResult = m_pContainedShape.m_pContainedShape->CalcSizeForSpu(input, iMax);
    if (iResult < 0)
        return -1;
    if (iResult > iMax)
        return -1;
    if (m_pContainedShape.m_pContainedShape == reinterpret_cast<const hkpShape*>(this + 1))
    {
        const_cast<ConvexTranslateSpuSizingView*>(this)->m_iChildShapeSize = 0;
        return iResult + 0x30;
    }
    const_cast<ConvexTranslateSpuSizingView*>(this)->m_iChildShapeSize = iResult;
    return 0x30;
}

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

// @fnv 0x00dd5e70
void __thiscall Own_dd5e70::AttachChildAndAttribute(Sub_dd5e70* object, int unused)
{
    object->v0C("Child", m_sub, 0);
    hkReferencedObject_calcContentStatistics(object, &DAT_01268940);
}

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
// @fnv 0x00dd5ea0
// src: HAVOK_SRC 0x00dd5ea0
void* FUN_00dd5ea0_class::hkpConvexTranslateShape_getContainer()
{
    return &unk14;
}

struct ObjDD5F50
{
    void* m_vptr;
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void __thiscall FUN_00dd5f50_v(const unsigned short* ids, int numIds, hkVector4* verticesOut);
};

struct ClsDD5F50
{
    void* m_unk00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    ObjDD5F50* m_pContainedShape;  // +0x18
    int m_1c;
    hkVector4 m_vTranslation;  // +0x20

    void __thiscall hkpConvexTranslateShape_convertVertexIdsToVerticesImpl(const unsigned short* ids, int numIds, hkVector4* verticesOut);
};

// Calls the contained shape's virtual vertex generator, then adds m_vTranslation to each output vertex.
// @fnv 0x00dd5f50
// src: HAVOK_SRC 0x00dd5f50
void ClsDD5F50::hkpConvexTranslateShape_convertVertexIdsToVerticesImpl(const unsigned short* ids, int numIds, hkVector4* verticesOut)
{
    m_pContainedShape->FUN_00dd5f50_v(ids, numIds, verticesOut);
    for (int i = 0; i < numIds; i++)
    {
        verticesOut[i].add4(m_vTranslation);
    }
}

namespace fnv_00dd60e0 {
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern "C" unsigned long DAT_0126835c;
extern "C" const char DAT_010d1074[];
extern "C" const char DAT_010c41f8[];
extern "C" unsigned __int64 __rdtsc();
extern "C" void _ReadWriteBarrier();

static const char s_kEndTimer[] = "Et";
static inline void TimerMark(const char* name)
{
    hkMonitorStream* s = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    if (s->m_end.m_storage < s->m_capacityMinus16.m_storage)
    {
        hkMonitorStream::TimerCommand* h = (hkMonitorStream::TimerCommand*)s->m_end.m_storage;
        h->m_commandAndMonitor = name;
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        h->m_time0 = t;
        s->m_end.m_storage = (char*)(h + 1);
    }
}

class HkBoolDD
{
  public:
    char m_cBooleanValue;
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct RayInputDD60
{
    hkVector4 m_vFrom;
    hkVector4 m_vTo;
    unsigned int m_uiFilterInfo;
    void* m_pRayShapeCollectionFilter;
    int pad[2];
};

struct RayOutputDD60
{
    hkVector4 m_vHitNormal;
    float m_fHitFraction;
    int m_iExtraInfo;
    int pad[2];
    unsigned int m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;
    void changeLevel(int delta)
    {
        m_uiShapeKeyIndex += delta;
    }
    void setKey(unsigned int key)
    {
        m_uiShapeKeys[m_uiShapeKeyIndex] = key;
    }
};

class ShapeDD60
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual HkBoolDD RayCast(const RayInputDD60& input, RayOutputDD60& results) const;
};

class ConvexTranslateDD60
{
  public:
    int pad[6];
    const ShapeDD60* m_pContainedShape;
    int pad1c;
    hkVector4 m_vTranslation;
    HkBoolDD hkpConvexTranslateShape_castRayImpl(const RayInputDD60& input, RayOutputDD60& results) const;
};

// Subtracts m_vTranslation from the ray endpoints, calls m_pContainedShape->RayCast, and sets the shape key to 0 on a hit.
// @fnv 0x00dd60e0
// src: HAVOK_SRC 0x00dd60e0
HkBoolDD ConvexTranslateDD60::hkpConvexTranslateShape_castRayImpl(const RayInputDD60& input, RayOutputDD60& results) const
{
    TimerMark("TtrcConvTransl");
    RayInputDD60 subInput;
    memcpy(&subInput, &input, sizeof(subInput));
    subInput.m_vFrom.setSub4(input.m_vFrom, m_vTranslation);
    subInput.m_vTo.setSub4(input.m_vTo, m_vTranslation);
    results.changeLevel(1);
    HkBoolDD hit = m_pContainedShape->RayCast(subInput, results);
    results.changeLevel(-1);
    if (hit)
        results.setKey(0);
    TimerMark(s_kEndTimer);
    return hit;
}
}  // namespace fnv_00dd60e0

struct FNV_dd6060_Shape
{

    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();

    virtual void v10();
    virtual void v14();
    virtual void v18();

    virtual void v1C(const hkRotation* rotation, float distance, LocalM128* output) const;
};

struct FNV_dd6060_Class : hkpConvexTranslateShape
{

    void __thiscall hkpConvexTranslateShape_getAabbImpl(const hkRotation* rotation, float distance, LocalM128* output);
};

// Calls the contained shape's v1C, then adds the translation rotated by the rotation columns to output[0] and output[1].
// @fnv 0x00dd6060
// src: HAVOK_SRC 0x00dd6060
void FNV_dd6060_Class::hkpConvexTranslateShape_getAabbImpl(const hkRotation* rotation, float distance, LocalM128* output)

{

    const FNV_dd6060_Shape* shape = reinterpret_cast<const FNV_dd6060_Shape*>(m_pContainedShape.m_pContainedShape);

    shape->v1C(rotation, distance, output);

    LocalM128 translation = _mm_load_ps(&m_vTranslation.x);

    LocalM128 moved = _mm_mul_ps(_mm_shuffle_ps(translation, translation, 0x55), _mm_load_ps(&rotation->m_kColumn1.x));

    moved = _mm_add_ps(
        moved, _mm_mul_ps(_mm_shuffle_ps(translation, translation, 0x00), _mm_load_ps(&rotation->m_kColumn0.x)));

    moved = _mm_add_ps(
        moved, _mm_mul_ps(_mm_shuffle_ps(translation, translation, 0xaa), _mm_load_ps(&rotation->m_kColumn2.x)));

    output[0] = _mm_add_ps(output[0], moved);

    output[1] = _mm_add_ps(output[1], moved);
}
