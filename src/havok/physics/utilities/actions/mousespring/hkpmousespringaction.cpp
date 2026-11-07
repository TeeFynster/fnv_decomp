
// src/havok/physics/utilities/actions/mousespring/hkpmousespringaction.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/actions/mousespring/hkpmousespringaction.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/hkArray.h"
#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/hkpUnaryAction.h"
#include "../../../../../../include/hkpCdBody.h"
#include "../../../../../../include/hkpBroadPhaseHandle.h"
#include "../../../../../../include/hkpTypedBroadPhaseHandle.h"

typedef float hkReal;
typedef unsigned int hkUint32;
typedef unsigned short hkUint16;

struct FUN_00d2b1f0
{
    void __thiscall EntityRemovedCallback(int);
};

struct FUN_00cbb1c0 : FUN_00d2b1f0
{
    void __thiscall Method(int);
};

// @fnv 0x00cbb1c0
void __thiscall FUN_00cbb1c0::Method(int aiValue)
{
    EntityRemovedCallback(aiValue);
    *(int*)((char*)this + 0x18) = 0;
}

struct FUN_00cbb1b0_Class
{
    char pad0[0x48];
    hkReal m_fMaxRelativeForce;
    void __thiscall hkpMouseSpringAction_setMaxRelativeForce(hkReal a);
};

// @fnv 0x00cbb1b0
// src: XBOX_PDB 0x00cbb1b0
void FUN_00cbb1b0_Class::hkpMouseSpringAction_setMaxRelativeForce(hkReal a)
{
    m_fMaxRelativeForce = a;
}

extern "C" int DAT_01268a14;

// @fnv 0x00cbb8a0
// src: COMMUNITY 0x00cbb8a0
int __cdecl hkpUnaryAction_getClassType()
{
    return (int)&DAT_01268a14;
}

// Exe 0x00cbb560 FUN_00cbb560: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;

#include "../../../../../../include/hkVector4.h"

extern int DAT_010c8e94;
extern int DAT_010c476c;
extern float DAT_0101b2d0;
extern float DAT_0104da48;
extern const char str_011b1f3c[];

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();

struct Ms_Sphere
{
    int v0;
    int v1;
    int v2;
    int type;
    float radius;
    int u5;
    int u6;
    int u7;
    void __thiscall FUN_00cd8160(float r);
};
struct Ms_Xf
{
    LocalM128 c0;
    LocalM128 c1;
    LocalM128 c2;
    LocalM128 t;
};
struct Ms_Body
{
    int u0;
    int u1;
    int u2;
    int u3;
    int u4;
    int u5;
    int u6;
    int u7;
    int u8;
    int u9;
    int u10;
    int u11;
    int u12;
    int u13;
    int u14;
    int u15;
    int u16;
    int u17;
    int u18;
    int u19;
    void __thiscall FUN_00cd2d80(Ms_Sphere* s, Ms_Xf* x, int parent);
};
Ms_Xf* __cdecl FUN_00cd4b50();

struct Ms_Input
{
    int i0;
    int i1;
    int i2;
    int i3;
    int i4;
    int i5;
    int i6;
    int i7;
    LocalM128 q0;
    LocalM128 q1;
    LocalM128 q2;
};
struct Ms_Coll
{
    int* vptr;
    float early;
    int u2;
    int u3;
    int u4;
    int u5;
    int u6;
    int u7;
    int u8;
    int u9;
    int u10;
    float dist;
    int hit;
    int u13;
    int u14;
    int u15;
    int u16;
    int u17;
    int u18;
    int u19;
    int u20;
    int u21;
    int u22;
    int key;
    int u24;
    int u25;
    int u26;
    int u27;
    int u28;
    int u29;
    int u30;
    int u31;
};

struct Ms_Shape
{
    int u0;
    int u1;
    int u2;
    int type;
};
struct Ms_Disp
{
    int unk00;
};
struct Ms_World
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    Ms_Input* input;
    int unk7c;
    Ms_Disp* disp;
};
struct Ms_Ent
{
    int u0;
    int u1;
    Ms_World* world;
    int u3;
    Ms_Shape* shape;
};
typedef void(__cdecl* Ms_Fn)(Ms_Body*, void*, Ms_Input*, Ms_Coll*);
struct Ms_B
{
    void __thiscall FUN_00d2b260(void* e, int z);
};
struct Ms_N
{
    void __thiscall UpdateState_00cb0c10(const char* s);
};
extern "C"
{
    void _mm_store_ps(float*, LocalM128);
    LocalM128 _mm_load_ps(const float*);
}
struct Fv
{
    float x;
    float y;
    float z;
    float w;
};
struct Ms_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Fv pos;
    Fv mouse;
    float damping;
    float elasticity;
    float maxRel;
    float objDamping;
    int shapeKey;
    hkArrayBase<int> cb;
    Ms_cls* hkpMouseSpringAction_hkpMouseSpringAction(LocalM128* a0, LocalM128* a1, float a2, float a3, float a4, Ms_Ent* a5, hkArray<int>* a6);
};

// Initializes the Ms_cls object with position, mouse, and damping parameters, copies an array, and computes a shape key via a collision test against the world.
// @fnv 0x00cbb560
// src: EXE 0x00cbb560
Ms_cls* Ms_cls::hkpMouseSpringAction_hkpMouseSpringAction(LocalM128* apPos, LocalM128* apMouse, float afDamping, float afElasticity, float afObjDamping,
                             Ms_Ent* apEnt, hkArray<int>* apArr)
{
    ((Ms_B*)this)->FUN_00d2b260(apEnt, 0);
    *(int**)this = &DAT_010c8e94;
    _mm_store_ps(&pos.x, *apPos);
    _mm_store_ps(&mouse.x, *apMouse);
    damping = afDamping;
    elasticity = afElasticity;
    objDamping = afObjDamping;
    cb.setOwnedData(0, 0, 0x80000000);
    maxRel = 250.0f;
    if (apArr)
    {
        hkMemoryAllocator& h = *(hkMemoryAllocator*)hkMemoryRouter_getInstance()->m_heap;
        int cap = cb.m_iCapacityState & 0x3fffffff;
        if (cap < apArr->m_iElementCount)
        {
            if ((cb.m_iCapacityState & 0x80000000) == 0)
                h.bufFree(cb.m_data, cap * 4);
            int n = apArr->m_iElementCount * 4;
            cb.m_data = (int*)h.bufAlloc(n);
            cb.m_iCapacityState = n / 4;
        }
        int cnt = apArr->m_iElementCount;
        cb.m_iElementCount = cnt;
        int* dst = cb.m_data;
        int* src = apArr->m_data;
        for (int i = 0; i < cnt; i++)
            dst[i] = src[i];
    }
    Ms_World* w = apEnt->world;
    shapeKey = -1;
    if (w)
    {
        Ms_Sphere sph;
        sph.FUN_00cd8160(1.0f);
        Ms_Xf* ident = FUN_00cd4b50();
        Ms_Xf xf;
        xf.c0 = ident->c0;
        xf.c1 = ident->c1;
        xf.c2 = ident->c2;
        xf.t = *apMouse;
        Ms_Body body;
        body.FUN_00cd2d80(&sph, &xf, 0);
        Ms_Disp* d = w->disp;
        unsigned char t = *((unsigned char*)d + (((sph.type + 13) << 5) + apEnt->shape->type));
        Ms_Fn fn = *(Ms_Fn*)((char*)d + t * 20 + 0x9a8);
        Ms_Input in;
        Ms_Input* src = w->input;
        in.i0 = src->i0;
        in.i1 = src->i1;
        in.i2 = src->i2;
        in.i3 = src->i3;
        in.i4 = src->i4;
        in.i5 = src->i5;
        in.q0 = src->q0;
        in.q1 = src->q1;
        in.q2 = src->q2;
        Ms_Coll coll;
        coll.dist = DAT_0104da48;
        coll.early = DAT_0104da48;
        coll.vptr = &DAT_010c476c;
        coll.hit = 0;
        fn(&body, &apEnt->shape, &in, &coll);
        if (coll.hit)
            shapeKey = coll.key;
    }
    ((Ms_N*)&unk14)->UpdateState_00cb0c10(str_011b1f3c);
    return this;
}

namespace fnv_00cbb790 {
void* __cdecl hkMemoryRouter_getInstance();
// 0x00c85750 returns the shared hkMemoryRouter; its heap pointer is at +0x10.
inline hkMemoryAllocator& heapCBB7()
{
    return *(hkMemoryAllocator*)((hkMemoryRouter*)hkMemoryRouter_getInstance())->m_heap;
}

template <typename T> inline void copyCBB7(T* pDst, const T* pSrc, int n)
{
    for (int i = 0; i < n; i++)
        pDst[i] = pSrc[i];
}

}  // namespace fnv_00cbb790

template <typename T, typename Allocator>
__forceinline hkArray<T, Allocator>& hkArray<T, Allocator>::operator=(const hkArray& kOther)
{
    hkMemoryAllocator& kAlloc = fnv_00cbb790::heapCBB7();
    if (getCapacity() < kOther.m_iElementCount)
    {
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.bufFree(m_data, getCapacity() * sizeof(T));
        int iNumBytes = kOther.m_iElementCount * sizeof(T);
        m_data = (T*)kAlloc.bufAlloc(iNumBytes);
        m_iCapacityState = iNumBytes / (int)sizeof(T);
    }
    m_iElementCount = kOther.m_iElementCount;
    fnv_00cbb790::copyCBB7(m_data, kOther.m_data, m_iElementCount);
    return *this;
}

namespace fnv_00cbb790 {

class FUN_00cbb4e0 : public hkpUnaryAction
{
  public:
    hkUint32 m_1c;
    hkVector4 m_kMousePositionInWorld;
    hkVector4 m_kGrabPointInBodySpace;
    hkReal m_fSpringDamping;
    hkReal m_fSpringElasticity;
    hkReal m_fMaxRelativeForce;
    hkReal m_fTau;
    hkUint32 m_uiCollisionShapeKey;
    hkArray<void*> m_kAppliedCallbacks;

    FUN_00cbb4e0(hkpEntity* pkEntity) throw();

    void* operator new(unsigned int uiSize)
    {
        hkMemoryRouter* pkRouter = (hkMemoryRouter*)hkMemoryRouter_getInstance();
        hkReferencedObject* pkObj = (hkReferencedObject*)((hkMemoryAllocator*)pkRouter->m_heap)->blockAlloc(uiSize);
        pkObj->m_usMemSizeAndFlags = (hkUint16)uiSize;
        return pkObj;
    }

    FUN_00cbb4e0* CloneForEntity(const hkArray<hkpEntity*>& kNewEntities,
                                 const hkArray<void*>& kNewPhantoms) const throw();
};

// Creates a copy of this action for a single entity, returning null if the entity count is not one or any phantoms are present.
// @fnv 0x00cbb790
FUN_00cbb4e0* FUN_00cbb4e0::CloneForEntity(const hkArray<hkpEntity*>& kNewEntities,
                                           const hkArray<void*>& kNewPhantoms) const throw()
{
    if (kNewEntities.GetLogicalSize() != 1)
        return 0;
    if (kNewPhantoms.GetLogicalSize() != 0)
        return 0;

    FUN_00cbb4e0* pkAction = new FUN_00cbb4e0(kNewEntities[0]);
    pkAction->m_kMousePositionInWorld = m_kMousePositionInWorld;
    pkAction->m_kGrabPointInBodySpace = m_kGrabPointInBodySpace;
    pkAction->m_fSpringDamping = m_fSpringDamping;
    pkAction->m_fSpringElasticity = m_fSpringElasticity;
    pkAction->m_fMaxRelativeForce = m_fMaxRelativeForce;
    pkAction->m_fTau = m_fTau;
    pkAction->m_ulUserData = m_ulUserData;
    pkAction->m_uiCollisionShapeKey = m_uiCollisionShapeKey;
    pkAction->m_kAppliedCallbacks = m_kAppliedCallbacks;
    return pkAction;
}
}  // namespace fnv_00cbb790

class FUN_00d01a60
{
  public:
    FUN_00d01a60();
    int unk00[11];
};

extern const float DAT_01012054;

inline void hkpTypedBroadPhaseHandle::SetOwnerPointer(void* owner)
{
    int offset = (int)((char*)owner - (char*)this);
    m_iOwnerOffset = (signed char)offset;
}

class FUN_00cd2d80 : public hkpCdBody
{
  public:
    FUN_00cd2d80(const void* shape, const void* motionState, int type);

    signed char m_iOwnerOffset;
    signed char m_uiForceCollideOntoPpu;
    unsigned short m_uiShapeSizeOnSpu;
    hkpTypedBroadPhaseHandle m_kBroadPhaseHandle;
    FUN_00d01a60 m_kBoundingVolumeData;
    float m_fAllowedPenetrationDepth;
};

// Constructs the body from shape and motionState, builds the broad phase handle with type, sets its owner pointer, and sets a default allowed penetration depth.
// @fnv 0x00cd2d80
FUN_00cd2d80::FUN_00cd2d80(const void* apCollisionShape, const void* motionState, int aiBroadPhaseType)
    : hkpCdBody(apCollisionShape, motionState), m_iOwnerOffset(0), m_kBroadPhaseHandle(aiBroadPhaseType),
      m_fAllowedPenetrationDepth(DAT_01012054)
{
    m_kBroadPhaseHandle.SetOwnerPointer(this);
    m_uiForceCollideOntoPpu = 0;
    m_uiShapeSizeOnSpu = 0;
}

struct Cls
{
    void* m_vt;          // 0x00
    int m_04;            // 0x04 (word)
    char m_pad08[0x4c];  // to 0x54
    int m_54;
    int m_58;
    int m_5c;
    Cls* FUN_00cbb8b0(int flags);
    void ReleaseReference_00d2b2b0();
};

// Clears the array at m_54 and releases its buffer unless flagged, calls FUN_00d2b2b0, and frees this through the TLS heap when bit 0 of flags is set.
// @fnv 0x00cbb8b0
Cls* Cls::FUN_00cbb8b0(int flags)
{
    hkMemoryRouter* tls = hkMemoryRouter_getInstance();
    hkMemoryAllocator* heap = (hkMemoryAllocator*)tls->m_heap;
    int n = m_5c;
    m_58 = 0;
    if (!((unsigned int)n & 0x80000000u))
        heap->bufFree((void*)m_54, (n & 0x3fffffff) * 4);
    m_54 = 0;
    m_5c = 0x80000000;
    ReleaseReference_00d2b2b0();
    if (flags & 1)
    {
        hkMemoryRouter* tls2 = hkMemoryRouter_getInstance();
        hkMemoryAllocator* heap2 = (hkMemoryAllocator*)tls2->m_heap;
        heap2->blockFree(this, (unsigned short)m_04);
    }
    return this;
}

extern "C"
{
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_and_ps(LocalM128, LocalM128);
    LocalM128 _mm_load_ps1(const float*);
    LocalM128 _mm_cmple_ps(LocalM128, LocalM128);
    int _mm_movemask_ps(LocalM128);
}

extern "C"
{
}

extern const LocalM128 DAT_01017d10;
extern const float DAT_01017d00;

class UnkCall
{
  public:
    int unk00;
    int unk04;
    int m_pOwningWorld;

    void activate_00c9c1d0();
};

class hkpPositionTrackerCBB1
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    UnkCall* m_pOwnerObject;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    hkVector4 m_vContactPosition;

    void hkpMouseSpringAction_setMousePosition(const hkVector4& kPosition);
};

// @fnv 0x00cbb150
// src: COMMUNITY 0x00cbb150
void hkpPositionTrackerCBB1::hkpMouseSpringAction_setMousePosition(const hkVector4& kPosition)
{
    LocalM128 d = _mm_sub_ps(kPosition.m_vComponents, m_vContactPosition.m_vComponents);
    d = _mm_and_ps(d, DAT_01017d10);
    LocalM128 eps = _mm_load_ps1(&DAT_01017d00);
    int iMask = _mm_movemask_ps(_mm_cmple_ps(d, eps));
    if ((iMask & 7) != 7)
    {
        if (m_pOwnerObject && m_pOwnerObject->m_pOwningWorld)
            m_pOwnerObject->activate_00c9c1d0();
    }
    m_vContactPosition = kPosition;
}

extern "C" LocalM128 _mm_setzero_ps(void);
struct FUN_00cbb4e0
{
    void* unk00;
    unsigned short unk04;
    unsigned short unk06;
    void* unk08;
    void* unk0C;
    unsigned int unk10;
    const char* m_name;
    void* m_pEntity;
    unsigned int unk1C;
    hkVector4 m_kMousePositionInWorld;
    hkVector4 m_kGrabPointInBodySpace;
    hkReal m_fSpringDamping;
    hkReal m_fSpringElasticity;
    hkReal m_fMaxRelativeForce;
    hkReal m_fTau;
    unsigned int m_uiCollisionShapeKey;
    hkArrayBase<char> m_kAppliedCallbacks;
    FUN_00cbb4e0(int arg);
};
extern float DAT_01016248, DAT_01017870, DAT_0101ffc0;
// Initializes the hkpMouseSpringAction fields with default spring constants, zeroed vectors, and the action name.
// @fnv 0x00cbb4e0
FUN_00cbb4e0::FUN_00cbb4e0(int arg) : m_kAppliedCallbacks(FinishingFlag())
{
    ((Ms_B*)this)->FUN_00d2b260((void*)arg, 0);
    m_fSpringDamping = DAT_01016248;
    unk00 = (void*)&DAT_010c8e94;
    m_fSpringElasticity = DAT_01017870;
    LocalM128 zero = _mm_setzero_ps();
    m_fMaxRelativeForce = DAT_0101b2d0;
    m_fTau = DAT_0101ffc0;
    *(char* volatile*)&m_kAppliedCallbacks.m_data = 0;
    *(volatile int*)&m_kAppliedCallbacks.m_iElementCount = 0;
    *(volatile int*)&m_kAppliedCallbacks.m_iCapacityState = 0x80000000;
    _mm_store_ps((float*)&m_kMousePositionInWorld, zero);
    _mm_store_ps((float*)&m_kGrabPointInBodySpace, zero);
    m_uiCollisionShapeKey = 0xFFFFFFFF;
    ((Ms_N*)&m_name)->UpdateState_00cb0c10("hkpMouseSpringAction");
}
