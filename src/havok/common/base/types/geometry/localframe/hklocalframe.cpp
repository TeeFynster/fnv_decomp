
// src/havok/common/base/types/geometry/localframe/hklocalframe.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/types/geometry/localframe/hklocalframe.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Keep the unit's intrinsic register declaration: the SDK's byte-array aliases
// cause this compiler to add /GS cookies to the transform stack temporaries.
#define _INCLUDED_MM2
// Exe 0x00df66a0 GetWorldTransform: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C" LocalM128 _mm_sub_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_mul_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_add_ss(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_sqrt_ss(LocalM128 a);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128 a, LocalM128 b, unsigned int imm);
extern "C" void _mm_store_ss(float* p, LocalM128 a);
extern "C" void _ReadWriteBarrier();
#pragma intrinsic(_ReadWriteBarrier)

#include "../../../../../../../include/hkArray.h"
#include "../../../../../../../include/hkBaseObject.h"
#include "../../../../../../../include/hkReferencedObject.h"
#include "../../../../../../../include/hkMemoryAllocator.h"
// Shared hkMemoryRouter layout: allocator pointers at +0x0c and +0x10.
#include "../../../../../../../include/hkMemoryRouter.h"
// Shared hkSimdReal layout: one SSE register, converted through its low float.
#include "../../../../../../../include/hkSimdReal.h"
#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/hkTransform.h"


// These shared declarations leave their per-unit inline forms to the source.
__forceinline hkTransform::hkTransform() {}
__forceinline hkTransform::hkTransform(const hkTransform& t)
{
    const LocalM128 column0 = t.m_kColumn0;
    // The original column copy loads the first row before the return-buffer pointer.
    _ReadWriteBarrier();
    m_kColumn0 = column0;
    m_kColumn1 = t.m_kColumn1;
    m_kColumn2 = t.m_kColumn2;
    m_vTranslation = t.m_vTranslation;
}
__forceinline hkSimdReal::hkSimdReal() {}
__forceinline hkSimdReal::operator float() const
{
    float f;
    _mm_store_ss(&f, m_vValue);
    return f;
}
__forceinline hkSimdReal hkVector4::length3() const
{
    const LocalM128 x2 = _mm_mul_ps(m_vComponents, m_vComponents);
    const LocalM128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    hkSimdReal r;
    r.m_vValue = _mm_sqrt_ss(_mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xySum));
    return r;
}

struct FUN_00df6550
{
    void AddObjectReference(hkReferencedObject* p);
};

// @fnv 0x00df6550
void FUN_00df6550::AddObjectReference(hkReferencedObject* apObject)
{
    if (apObject)
        apObject->addReference();
    hkReferencedObject* pOldObject = *(hkReferencedObject**)((char*)this + 0x60);
    if (pOldObject)
        pOldObject->removeReference();
    *(hkReferencedObject**)((char*)this + 0x60) = apObject;
}

struct FUN_00df6690_StandIn
{
    char pad[0x50];
    int** m_table;

    int* hkSimpleLocalFrame_getChildFrame(int index);
};

// @fnv 0x00df6690
// src: HAVOK_LIB 0x00df6690
int* FUN_00df6690_StandIn::hkSimpleLocalFrame_getChildFrame(int index)
{
    return m_table[index];
}

struct FnvCpu_FUN_00df6680_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    int value;
    int GetValue_00df6680();
};
// @fnv 0x00df6680
// src: GUESS 0x00df6680 (confidence: high)
int FnvCpu_FUN_00df6680_CpuObject::GetValue_00df6680()
{
    return value;
}

class FUN_00df66a0_Node
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(hkTransform* dest);
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual FUN_00df66a0_Node* v8();
    void GetWorldTransform(hkTransform* dest);
};
// Computes the node's world transform: if it has a parent, combines the parent's transform with the local transform, otherwise writes the local transform to dest.
// @fnv 0x00df66a0
void FUN_00df66a0_Node::GetWorldTransform(hkTransform* dest)
{
    if (v8())
    {
        hkTransform parent;
        hkTransform local;
        v8()->GetWorldTransform(&parent);
        v3(&local);
        dest->hkTransform_setMul(parent, local);
    }
    else
    {
        v3(dest);
    }
}

class hkpDF65Node;

class hkpDF65Collector
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void AddHit(hkpDF65Node* pkNode, float fDistance);
};

class hkpDF65Child
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void query(const hkVector4& kLocalPos, float fRadius, hkpDF65Collector* pkCollector);
};

class hkpDF65Node : public hkReferencedObject
{
  public:
    void hkSimpleLocalFrame_getNearbyFrames(const hkVector4& kPos, float fRadius, hkpDF65Collector* pkCollector);

    unsigned int unk08, unk0C;
    hkTransform m_kMotionTransform;
    hkArray<hkpDF65Child*> m_children;
};

// @fnv 0x00df65d0
// src: HAVOK_SRC 0x00df65d0
void hkpDF65Node::hkSimpleLocalFrame_getNearbyFrames(const hkVector4& kPos, float afRadius, hkpDF65Collector* pkCollector)
{
    hkVector4 kDiff;
    kDiff.setSub4(kPos, m_kMotionTransform.position);
    const float fDistance = kDiff.length3();
    if (fDistance <= afRadius)
    {
        pkCollector->AddHit(this, fDistance);
    }
    if (m_children.GetLogicalSize() > 0)
    {
        hkVector4 kLocalPos;
        kLocalPos.hkVector4_setTransformedInversePos(m_kMotionTransform, kPos);
        for (int i = 0; i < m_children.GetLogicalSize(); i++)
        {
            m_children[i]->query(kLocalPos, afRadius, pkCollector);
        }
    }
}

// object returned per iteration; slot 0xc fetches the vector, slot 0x20 walks to the next one
struct df6710_frame
{
    virtual void unk00();
    virtual void unk01();
    virtual void unk02();
    virtual void unk03(hkTransform* v);
    virtual void unk04();
    virtual void unk05();
    virtual void unk06();
    virtual void unk07();
    virtual df6710_frame* unk08();
};

// 'this' of FUN_00df6710: vtable slot 0x14 registers the matrix, slot 0x20 returns first frame
struct df6710_self
{
    virtual void unk00();
    virtual void unk01();
    virtual void unk02();
    virtual void unk03();
    virtual void unk04();
    virtual void unk05(hkVector4* m);
    virtual void unk06();
    virtual void unk07();
    virtual df6710_frame* unk08();
    void hkLocalFrame_getPositionInRoot(hkVector4* m);
};

// Calls unk05 with m, then walks the unk08 chain and passes each unk03 output and m to FUN_00c7f640.
// @fnv 0x00df6710
// src: HAVOK_LIB 0x00df6710
void df6710_self::hkLocalFrame_getPositionInRoot(hkVector4* apMatrix)
{
    hkTransform buf;
    unk05(apMatrix);
    for (df6710_frame* p = unk08(); p; p = p->unk08())
    {
        p->unk03(&buf);
        apMatrix->setTransformedPos_00c7f640(buf, *apMatrix);
    }
}

namespace fnv_00df6770 {
struct LocalFrameStandIn
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void getTransform(hkTransform* result);
    void GetTranslation(hkVector4* result);
};
// Calls getTransform to fill a local hkTransform and copies its translation column into the result hkVector4.
// @fnv 0x00df6770
void LocalFrameStandIn::GetTranslation(hkVector4* apTranslation)
{
    hkTransform localTransform;
    getTransform(&localTransform);
    apTranslation->m_vComponents = localTransform.m_vTranslation;
}
}  // namespace fnv_00df6770

class FUN_00df67a0_cls
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkTransform m_kMotionTransform;

    hkTransform GetMotionTransform() const;
};

// Returns the m_kMotionTransform member of the class.
// @fnv 0x00df67a0
hkTransform FUN_00df67a0_cls::GetMotionTransform() const
{
    return m_kMotionTransform;
}

extern "C" hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();


template <typename T, typename Allocator>
__forceinline hkArray<T, Allocator>::~hkArray() throw()
{
    hkMemoryAllocator& alloc = hkMemoryRouter_getInstance()->heap();
    m_iElementCount = 0;
    if ((m_iCapacityState & 0x80000000) == 0)
        alloc.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
    m_data = 0;
    m_iCapacityState = 0x80000000;
}

struct FUN_00cb0c00_class
{
    const char* m_pcText;
    void Object_UpdateFields_00cb0c00() throw();
    ~FUN_00cb0c00_class() throw()
    {
        Object_UpdateFields_00cb0c00();
    }
};

class FUN_00df67d0 : public hkReferencedObject
{
  public:
    int unk08;
    int unk0C;
    float m_kMotionTransform[16];
    hkArray<hkReferencedObject*> m_children;
    hkReferencedObject* m_pParentFrame;
    hkReferencedObject* m_kGroupData;
    FUN_00cb0c00_class m_name;

    virtual ~FUN_00df67d0();
};

// Calls FUN_00c905b0 on each entry in m_children and on m_kGroupData when it is nonnull.
// @fnv 0x00df67d0
FUN_00df67d0::~FUN_00df67d0()
{
    int n = m_children.m_iElementCount;
    for (int i = 0; i < n; i++)
        m_children.m_data[i]->removeReference();
    if (m_kGroupData)
        m_kGroupData->removeReference();
}

struct FnvCpu_FUN_00df6580_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    LocalM128 field10;
    LocalM128 field20;
    LocalM128 field30;
    LocalM128 field40;
    void CopyFrom(hkTransform* input0);
};
// Copies the transform columns into the local-frame transform at +0x10.
// @fnv 0x00df6580
void FnvCpu_FUN_00df6580_CpuObject::CopyFrom(hkTransform* apCpuData)
{
    this->field10 = apCpuData->m_kColumn0;
    this->field20 = apCpuData->m_kColumn1;
    this->field30 = apCpuData->m_kColumn2;
    this->field40 = apCpuData->m_vTranslation;
}

namespace fnv_00df65b0 {
class FUN_00df65b0_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    hkVector4 m_vector;

    hkVector4 hkSimpleLocalFrame_getLocalPosition() const;
};

// @fnv 0x00df65b0
// src: HAVOK_SRC 0x00df65b0
hkVector4 FUN_00df65b0_cls::hkSimpleLocalFrame_getLocalPosition() const
{
    return m_vector;
}
}  // namespace fnv_00df65b0
