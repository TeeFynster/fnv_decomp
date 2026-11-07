typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
#define _INCLUDED_MM2

// src/havok/physics/utilities/weapons/hkpfirstpersongun.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/weapons/hkpfirstpersongun.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/hkResult.h"
#include "../../../../../include/hkArray.h"
#include "../../../../../include/hkReferencedObject.h"
#include "../../../../../include/hkMemoryRouter.h"
#define FNV64_HKVECTOR4Q_OWN_BODIES
#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkVector4q.h"

// Keep the generated reflection types separate from the shared SIMD types.
#include "havok/hkpFirstPersonGun.h"

template <typename T> void hkMemoryAllocator::_bufFree(void* p, int numElem)
{
    bufFree(p, numElem * sizeof(T));
}

// The router at 0x00c85750 has its heap allocator at +0x10 (hkMemoryRouter).


template <class T> __forceinline void destroyGunArrayElements(T* t, int n)
{
    for (int i = 0; i < n; i++)
        t[i].~T();
}

template <typename T> __forceinline void hkArrayBase<T>::clear()
{
    destroyGunArrayElements(m_data, m_iElementCount);
    m_iElementCount = 0;
}

template <typename T> __forceinline void hkArrayBase<T>::_clearAndDeallocate(hkMemoryAllocator& alloc)
{
    clear();
    if ((m_iCapacityState & 0x80000000) == 0)
        alloc._bufFree<T>(m_data, getCapacity());
    m_data = 0;
    m_iCapacityState = 0x80000000;
}

template <typename T, typename A> __forceinline hkArray<T, A>::~hkArray()
{
    this->_clearAndDeallocate(hkMemoryRouter::getInstance().heap());
}

struct FUN_00e463b0_cls
{
    int unk00;
    int unk04;
    int unk08;
    unsigned int m_0C;

    unsigned int hkpFirstPersonGun_getName();
};

// @fnv 0x00e463b0
// src: HAVOK_SRC 0x00e463b0
unsigned int FUN_00e463b0_cls::hkpFirstPersonGun_getName()
{
    return m_0C & 0xfffffffeu;
}

struct FUN_00e463c0_cls
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void Tail(int a);
    void hkpFirstPersonGun_quitGun(int a);
};

// @fnv 0x00e463c0
// src: HAVOK_SRC 0x00e463c0
void FUN_00e463c0_cls::hkpFirstPersonGun_quitGun(int a)
{
    this->Tail(a);
}

struct FUN_00cb0b80
{
    char* m_kStringBuffer;
    FUN_00cb0b80(const char* s) throw();
};
class FUN_00e46660 : public hkReferencedObject
{
  public:
    volatile unsigned char m_type;
    char unk09, unk0A, unk0B;
    FUN_00cb0b80 m_name;
    unsigned char m_uiKeyboardKey;
    char unk11, unk12, unk13;
    hkArray<void*> m_kListeners;
    FUN_00e46660();
    virtual ~FUN_00e46660();
};
// @fnv 0x00e46660
FUN_00e46660::FUN_00e46660() : m_type(0), m_name(""), m_uiKeyboardKey(0x71)
{}

namespace fnv_00e466a0 {
struct FUN_00cb0a70
{
    char* m_kStringBuffer;
    FUN_00cb0a70(FinishingFlag flag) throw();
};

class FUN_00e466a0 : public hkReferencedObject
{
  public:
    unsigned char m_type;
    char unk09;
    char unk0A;
    char unk0B;
    FUN_00cb0a70 m_name;
    unsigned char m_uiKeyboardKey;
    char unk11;
    char unk12;
    char unk13;
    hkArray<void*> m_kListeners;

    FUN_00e466a0(FinishingFlag flag);
    virtual ~FUN_00e466a0();
};

// @fnv 0x00e466a0
FUN_00e466a0::FUN_00e466a0(FinishingFlag flag) : hkReferencedObject(flag), m_name(flag)
{
    if (flag.m_bFinishing)
        m_type = 0;
}
}  // namespace fnv_00e466a0

namespace fnv_00e466e0 {
class FUN_00cb0c00_class
{
  public:
    const char* m_pcText;

    void Object_UpdateFields_00cb0c00() throw();
    ~FUN_00cb0c00_class()
    {
        Object_UpdateFields_00cb0c00();
    }
};

class FUN_00e466e0_class : public hkReferencedObject
{
  public:
    int m_08;
    FUN_00cb0c00_class m_name;
    int m_10;
    hkArray<hkReferencedObject*> m_children;

    virtual ~FUN_00e466e0_class() throw();
};

// Destructor releases every child in m_children by calling removeReference on each element.
// @fnv 0x00e466e0
FUN_00e466e0_class::~FUN_00e466e0_class() throw()
{
    for (int i = 0; i < m_children.m_iElementCount; i++)
        m_children.m_data[i]->removeReference();
}
}  // namespace fnv_00e466e0

struct FUN_00e466e0_Obj
{
    void FUN_00e466e0();
};

class FUN_00e46750_Obj;

class FUN_00e46750_Obj : public hkpFirstPersonGun
{
  public:
    void FUN_00e466e0();
    int FUN_00e46750(unsigned char flag);
};

// @fnv 0x00e46750
int FUN_00e46750_Obj::FUN_00e46750(unsigned char flag)
{
    FUN_00e466e0();

    if (flag & 1)
    {
        hkMemoryRouter* router = &hkMemoryRouter::getInstance();
        router->m_heap->blockFree(this, m_usMemSizeAndFlags);
    }

    return (int)this;
}


namespace fnv_00e464e0 {
using ::__m128;
using ::LocalM128;
// Exe 0x00e464e0 FUN_00e464e0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).

extern "C" LocalM128 _mm_setzero_ps(void);
extern "C" LocalM128 _mm_unpackhi_ps(LocalM128 a, LocalM128 b);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128 a, LocalM128 b, unsigned int imm);

}  // namespace fnv_00e464e0

// Use the original intrinsic view so SIMD stores retain their original aliasing.
__forceinline void hkVector4q::operator=(const hkVector4q& v)
{
    typedef fnv_00e464e0::LocalM128 Quad;
    *reinterpret_cast<Quad*>(this) = *reinterpret_cast<const Quad*>(&v);
}

__forceinline void hkVector4q::setZero4()
{
    typedef fnv_00e464e0::LocalM128 Quad;
    *reinterpret_cast<Quad*>(this) = fnv_00e464e0::_mm_setzero_ps();
}

__forceinline void hkVector4q::setXYZ(const hkVector4q& v)
{
    typedef fnv_00e464e0::LocalM128 Quad;
    Quad& dest = *reinterpret_cast<Quad*>(this);
    const Quad& src = *reinterpret_cast<const Quad*>(&v);
    dest = fnv_00e464e0::_mm_shuffle_ps(src, fnv_00e464e0::_mm_unpackhi_ps(src, dest), 0xc4);
}

namespace fnv_00e464e0 {
extern hkVector4q DAT_01267e30;
extern float DAT_0104da48;
extern float DAT_0104da4c;

struct hkTransformq
{
    hkVector4q m_kColumn0;
    hkVector4q m_kColumn1;
    hkVector4q m_kColumn2;
    hkVector4q m_vTranslation;

    void setIdentityRotation()
    {
        m_kColumn0.setZero4();
        m_kColumn0(0) = 1.0f;
        m_kColumn1.setZero4();
        m_kColumn1(1) = 1.0f;
        m_kColumn2.setZero4();
        m_kColumn2(2) = 1.0f;
    }
};

struct hkpSphereShapeq
{
    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;

    static void* operator new(unsigned int nbytes)
    {
        hkpSphereShapeq* p = (hkpSphereShapeq*)hkMemoryRouter::getInstance().heap().blockAlloc(nbytes);
        p->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return p;
    }
    static void operator delete(void* p, unsigned int nbytes);

    hkpSphereShapeq(float radius) throw();
    void FUN_00c905b0();
};

struct hkpCollidableq
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    char m_iOwnerOffset;
    char unk11;
    char unk12;
    char unk13;
    int unk14;
    char m_type;
    char unk19;
    char unk1A;
    char unk1B;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;

    hkpCollidableq(const hkpSphereShapeq* shape, const hkTransformq* transform, int type) throw();
    void* getOwner() const
    {
        return (char*)this + m_iOwnerOffset;
    }
};

struct hkpLinearCastInputq
{
    hkVector4q m_vTo;
    float m_fMaxExtraPenetration;
    float m_fMaxExtraPenetrationAgainstFixed;
    int unk18;
    int unk1C;
};

struct hkContactPointq
{
    hkVector4q m_vContactPosition;
    hkVector4q m_vSeparatingNormal;
    void setDistance(float d)
    {
        m_vSeparatingNormal(3) = d;
    }
};

struct hkpClosestCdPointCollectorq
{
    void* m_ppVirtualMethodTable;
    float m_fEarlyOutDistance;
    int unk08;
    int unk0C;
    hkContactPointq m_kPoint;
    const hkpCollidableq* m_pRootCollidableA;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    const hkpCollidableq* m_pRootCollidableB;
    unsigned int m_uiShapeKeyB;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;

    hkpClosestCdPointCollectorq()
    {
        m_ppVirtualMethodTable = &DAT_010c476c;
        reset();
    }
    void reset()
    {
        m_kPoint.setDistance(DAT_0104da48);
        m_fEarlyOutDistance = DAT_0104da48;
        m_pRootCollidableA = 0;
    }
    bool DidHit() const
    {
        return m_pRootCollidableA != 0;
    }

    static int DAT_010c476c;
};

struct hkpWorldq
{
    void hkpWorld_linearCast(const hkpCollidableq* collA, const hkpLinearCastInputq& input,
                      hkpClosestCdPointCollectorq& castCollector, void* startCollector);
};

struct LinearCastResult
{
    hkVector4q m_vContactPosition;
    hkVector4q m_vHitNormal;
    unsigned int m_uiCollisionShapeKey;
    void* m_pRigidBody;
};


// Performs a sphere linear cast in the physics world and stores the hit point, normal, rigid body, and shape key in the result.
// @fnv 0x00e464e0
// src: GUESS 0x00e464e0 (confidence: medium)
hkResult hkpWorldq_CastSphereAndStoreHit(hkpWorldq* world, const hkVector4q& from, float radius, const hkVector4q& to,
                      LinearCastResult* result)
{
    hkpSphereShapeq* sphere = new hkpSphereShapeq(radius);

    hkTransformq transform;
    transform.setIdentityRotation();
    transform.m_vTranslation = from;

    hkpCollidableq collidable(sphere, &transform, 0);

    hkpClosestCdPointCollectorq collector;

    hkpLinearCastInputq input;
    input.m_vTo = to;
    input.m_fMaxExtraPenetration = DAT_0104da4c;
    input.m_fMaxExtraPenetrationAgainstFixed = DAT_0104da4c;

    world->hkpWorld_linearCast(&collidable, input, collector, 0);

    sphere->FUN_00c905b0();

    if (collector.DidHit())
    {
        result->m_vContactPosition = collector.m_kPoint.m_vContactPosition;
        result->m_vHitNormal = collector.m_kPoint.m_vSeparatingNormal;
        const hkpCollidableq* pHitCollidable = collector.m_pRootCollidableB;
        result->m_pRigidBody = (pHitCollidable->m_type == 1) ? pHitCollidable->getOwner() : 0;
        result->m_uiCollisionShapeKey = collector.m_uiShapeKeyB;
        return HK_SUCCESS;
    }

    result->m_pRigidBody = 0;
    result->m_vContactPosition = to;
    result->m_vHitNormal.setXYZ(DAT_01267e30);
    result->m_uiCollisionShapeKey = 0xffffffff;
    return HK_FAILURE;
}
}  // namespace fnv_00e464e0
