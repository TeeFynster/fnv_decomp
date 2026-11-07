
// src/havok/physics/collide/query/multithreaded/raycastquery/cpu/hkpcpuworldraycastjob.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/query/multithreaded/raycastquery/cpu/hkpcpuworldraycastjob.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../../include/hkBool.h"
#include "../../../../../../../../include/hkRotation.h"
#include "../../../../../../../../include/hkTransform.h"
#include "../../../../../../../../include/hkVector4.h"
#include "../../../../../../../../include/hkpCdBody.h"
#include "../../../../../../../../include/hkpCollisionFilter.h"
#include "../../../../../../../../include/hkpRayCollidableFilter.h"
#include "../../../../../../../../include/hkpRayHitCollector.h"
#include "../../../../../../../../include/hkpShape.h"
#include "../../../../../../../../include/hkpFixedBufferRayHitCollector.h"



struct ValueHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    unsigned char value;
    unsigned char* CopyValue(unsigned char* output);
};

// @fnv 0x00df8910
unsigned char* ValueHolder::CopyValue(unsigned char* output)
{
    *output = value;
    return output;
}

struct S_00df8990_Obj;

extern void(__cdecl* DAT_0126ec04)(void* a, void* b, S_00df8990_Obj* obj);

struct S_00df8990_Obj
{
    void InvokeCallback(void* a, void* b);
};

// @fnv 0x00df8990
void S_00df8990_Obj::InvokeCallback(void* a, void* b)
{
    DAT_0126ec04(a, b, this);
}

struct S_00df8d60_Data
{
    char unk0;
    char unk1;
    char unk2;
    char unk3;
    char unk4;
    signed char unk5;
};
struct S_00df8d60
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    float unk14;
    hkBool CastBody_Thunk(const void* data);
    float hkCpuWorldRayCastCollector_addBroadPhaseHandle(const S_00df8d60_Data* data, int unused);
};
// @fnv 0x00df8d60
// src: HAVOK_LIB 0x00df8d60
float S_00df8d60::hkCpuWorldRayCastCollector_addBroadPhaseHandle(const S_00df8d60_Data* data, int unused)
{
    CastBody_Thunk((const char*)data + data->unk5);
    return unk14;
}

struct ParamBlock
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int m_iValue;
};

struct Container
{
    void CastBody_Thunk(int* apOut, int aiValue);
};

struct FUN_00df8db0_cls
{
    int unk00;
    int unk04;
    int unk08;
    float m_fResult;

    float GetResult(ParamBlock* apParam);
};

// @fnv 0x00df8db0
float FUN_00df8db0_cls::GetResult(ParamBlock* apParam)
{
    int iOut;
    Container* pContainer = (Container*)((char*)this - 8);
    pContainer->CastBody_Thunk(&iOut, apParam->m_iValue);
    return m_fResult;
}

extern int DAT_0101e594;

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

struct FUN_00df8960_cls
{
    int m_vptr;

    FUN_00df8960_cls* FUN_00df8960(unsigned char acFlags);
};

// Sets the vtable pointer and, when bit 0 of acFlags is set, frees this 0x1c-byte object through the allocator from FUN_00c85750.
// @fnv 0x00df8960
FUN_00df8960_cls* FUN_00df8960_cls::FUN_00df8960(unsigned char acFlags)
{
    m_vptr = (int)&DAT_0101e594;
    if (acFlags & 1)
    {
        hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
        pAllocator->blockFree(this, 0x1c);
    }
    return this;
}

struct AdjustedBase
{
    void CastBody_Thunk(void* apFirst, int aiSecond);
};

struct AdjustOwner
{
    void* hkCpuWorldRayCastCollector_addMidPhaseHit(void* apFirst, int aiSecond);
};

// @fnv 0x00df8d90
// src: HAVOK_LIB 0x00df8d90
void* AdjustOwner::hkCpuWorldRayCastCollector_addMidPhaseHit(void* apFirst, int aiSecond)
{
    ((AdjustedBase*)((char*)this - 4))->CastBody_Thunk(apFirst, aiSecond);
    return apFirst;
}

struct FUN_00df8dd0_Param
{
    int unk00;
    int unk04;
    int unk08;
    unsigned int m_i0c;
};

struct FUN_00df8dd0_helper
{
    void CastBody_Thunk(FUN_00df8dd0_Param** pp, unsigned int value);
};

struct FUN_00df8dd0_cls
{
    int unk00;
    int unk04;
    float m_f08;

    float hkCpuWorldRayCastCollector_addLeaf(FUN_00df8dd0_Param* p);
};

// @fnv 0x00df8dd0
// src: HAVOK_LIB 0x00df8dd0
float FUN_00df8dd0_cls::hkCpuWorldRayCastCollector_addLeaf(FUN_00df8dd0_Param* pParam)
{
    ((FUN_00df8dd0_helper*)((char*)this - 12))->CastBody_Thunk(&pParam, pParam->m_i0c);
    return m_f08;
}

namespace fnv_00df9470 {
hkMemoryRouter* __cdecl hkMemoryRouter_getInstance() throw();

struct BaseA
{
    virtual ~BaseA()
    {}
};

struct BaseB
{
    virtual ~BaseB()
    {}
};

struct BaseC
{
    virtual ~BaseC()
    {}
};

struct BaseD
{
    virtual ~BaseD()
    {}
};

class MultiBaseOwner : public BaseA, public BaseB, public BaseC, public BaseD
{
  public:
    MultiBaseOwner* FUN_00df9470(unsigned char acFlags);
};

// Destructs the object, then, if bit 0 of acFlags is set, frees it through the allocator obtained from FUN_00c85750, and returns this.
// @fnv 0x00df9470
MultiBaseOwner* MultiBaseOwner::FUN_00df9470(unsigned char acFlags)
{
    this->MultiBaseOwner::~MultiBaseOwner();
    if (acFlags & 1)
    {
        hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
        hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
        pAllocator->blockFree(this, 0x80);
    }
    return this;
}
}  // namespace fnv_00df9470

struct DF8930Primary
{
    virtual void vfunc00();
    virtual void FUN_00df8930();

    int unk04;
    int unk08;
};

struct DF8930Secondary
{
    virtual void FUN_00df8930();
};

struct DF8930Object : DF8930Primary, DF8930Secondary
{
    DF8930Object();

// @fnv 0x00df8930
    virtual void FUN_00df8930();
};

DF8930Object::DF8930Object()
{}

// Adjustor thunk for a secondary base of a multiply-inherited class.
//
// The original bytes at 0x00df8950 are
//     sub ecx, 8
//     jmp 0xdf9470
// i.e. the compiler-generated "[thunk]: Derived::FUN_00df8950`adjustor{8}'"
// that MSVC emits for the per-base vftable of the SECONDARY base: the
// secondary base subobject lives 8 bytes into the most-derived object, so
// the thunk has to move "this" back by 8 before tail-jumping into the
// most-derived implementation.
//
// The most-derived implementation of FUN_00df8950 is only DECLARED here (it
// lives in another translation unit of the game), so the tail jump stays an
// undefined external and the linker/checker resolves it from the original.

struct NiObjectBase
{
    NiObjectBase();
    virtual void FUN_00df8950(int flag);
    int unk04;
};

struct NiExtraDataBase
{
    NiExtraDataBase();
    virtual void FUN_00df8950(int flag);
};

class Derived : public NiObjectBase, public NiExtraDataBase
{
  public:
    Derived();
// @fnv 0x00df8950
    virtual void FUN_00df8950(int flag);
};

NiObjectBase::NiObjectBase()
{}
NiExtraDataBase::NiExtraDataBase()
{}
Derived::Derived()
{}

#include <xmmintrin.h>
extern char DAT_010dbb04[];
extern void(__cdecl* DAT_0126ec04)(void* a, void* b, struct S_00df8990_Obj* obj);
struct S_00df8990_Obj;
void __cdecl Runtime_ProcessEntries_00e2b9b0(void* a, void* b, S_00df8990_Obj* obj);

struct Source
{
    __m128 m_v00;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1c;
    unsigned char m_20;
    unsigned char unk21;
    unsigned char unk22;
    unsigned char unk23;
    unsigned int m_24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int m_30;
    unsigned int m_34;
    unsigned int unk38;
    unsigned char m_3c;
};

struct Spawned
{
    unsigned int m_00;
    float m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    static void* operator new(unsigned int, void* p)
    {
        return p;
    }
    Spawned(unsigned int first, unsigned int last)
        : m_00((unsigned int)DAT_010dbb04), m_04(1.0f), m_08(first), m_0c(first), m_10(last), m_14(0), m_18(0)
    {}
};

struct SubBase
{
    unsigned value;
};
struct Leading
{
    unsigned a, b, c, d;
};
struct WithSub : Leading, SubBase
{
};

struct Output
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    WithSub* m_10;
    unsigned int unk14;
    unsigned int unk18;
    Source* m_1c;
    Source* m_20;
    unsigned int m_24;
    unsigned int m_28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int m_50;
    SubBase* m_54;
    unsigned int unk58;
    unsigned int unk5c;
    Spawned* m_60;
};

struct Local
{
    union
    {
        __m128 m_vector;
        float elements[4];
    };
    unsigned int m_10;
    unsigned int* m_pSub;
    unsigned int m_18;
    unsigned int m_1c;
};

// Exe 0x00df89b0: unit-local Interface view; declarations and layout are preserved.
struct HkpcpuworldraycastjobInterfaceView
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
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c(void* a, Output* b, unsigned int c);
};

// Fills out from src, builds a Local, constructs a Spawned in spawned if src->m_3c is set, writes fields of src->m_30's block, then calls iface->v5c.
// @fnv 0x00df89b0
// src: XBOX_PDB 0x00df89b0
void __cdecl castRayBroadPhase(HkpcpuworldraycastjobInterfaceView* apInterface, Source* apSource, Output* apOutput, Spawned* spawned)
{
    Local local;

    local.m_pSub = &apSource->m_10;
    local.m_18 = 0x10;
    local.m_1c = 0;
    local.m_10 = 1;
    local.m_vector = apSource->m_v00;

    apOutput->m_20 = apSource;
    apOutput->m_50 = apSource->m_24;
    apOutput->m_24 = apSource->m_30;
    apOutput->m_28 = apSource->m_30;
    apOutput->m_1c = apSource;

    if (apSource->m_20)
        apOutput->m_54 = static_cast<SubBase*>(apOutput->m_10);
    else
        apOutput->m_54 = 0;

    float one = 1.0f;

    if (apSource->m_3c != 0)
    {
        apOutput->m_60 = new (spawned) Spawned(apSource->m_30, apSource->m_34);
        DAT_0126ec04 = Runtime_ProcessEntries_00e2b9b0;
    }
    else
        apOutput->m_60 = 0;

    unsigned int* target = (unsigned int*)apSource->m_30;
    *(float*)&target[4] = one;
    target[5] = 0xffffffffu;
    target[8] = 0xffffffffu;
    target[0x14] = 0;
    target[0x10] = 0;

    apInterface->v5c(&local, apOutput, 0);
}


// The compiler's intrinsic view omits byte arrays so that inlined SIMD temporaries
// retain the original compiler's stack-buffer classification.
namespace SimdN {
// Exe 0x00df8aa0 FUN_00df8aa0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C"
{
    LocalM128 _mm_load_ps(const float*);
    LocalM128 _mm_set_ps1(float);
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
    LocalM128 _mm_unpacklo_ps(LocalM128, LocalM128);
    LocalM128 _mm_unpackhi_ps(LocalM128, LocalM128);
    LocalM128 _mm_movelh_ps(LocalM128, LocalM128);
    LocalM128 _mm_movehl_ps(LocalM128, LocalM128);
}
}

__forceinline SimdN::LocalM128& simd(hkVector4& vector)
{
    return reinterpret_cast<SimdN::LocalM128&>(vector.m_vComponents);
}

__forceinline const SimdN::LocalM128& simd(const hkVector4& vector)
{
    return reinterpret_cast<const SimdN::LocalM128&>(vector.m_vComponents);
}

__forceinline void hkVector4::_setRotatedDir(const hkRotation& r, const hkVector4& b)
{
    const SimdN::LocalM128 c1 = SimdN::_mm_load_ps(&r.m_kColumn1.m_f[0]);
    const SimdN::LocalM128 b1 = SimdN::_mm_shuffle_ps(simd(b), simd(b), 0x55);
    const SimdN::LocalM128 r1 = SimdN::_mm_mul_ps(c1, b1);
    const SimdN::LocalM128 b0 = SimdN::_mm_shuffle_ps(simd(b), simd(b), 0x00);
    const SimdN::LocalM128 r0 = SimdN::_mm_mul_ps(simd(r.m_kColumn0), b0);
    const SimdN::LocalM128 b2 = SimdN::_mm_shuffle_ps(simd(b), simd(b), 0xaa);
    const SimdN::LocalM128 r2 = SimdN::_mm_mul_ps(simd(r.m_kColumn2), b2);
    simd(*this) = SimdN::_mm_add_ps(SimdN::_mm_add_ps(r1, r0), r2);
}

__forceinline void hkVector4::_setRotatedInverseDir(const hkRotation& r, const hkVector4& vector)
{
    const SimdN::LocalM128& b = simd(vector);
    SimdN::LocalM128 c0 = simd(r.m_kColumn0);
    SimdN::LocalM128 c1 = simd(r.m_kColumn1);
    SimdN::LocalM128 c2 = simd(r.m_kColumn2);
    SimdN::LocalM128 tmp = SimdN::_mm_unpacklo_ps(c0, c1);
    SimdN::LocalM128 ctmp = SimdN::_mm_unpackhi_ps(c0, c1);
    c0 = SimdN::_mm_movelh_ps(tmp, c2);
    tmp = SimdN::_mm_movehl_ps(c0, tmp);
    c1 = SimdN::_mm_shuffle_ps(tmp, c2, 0xd4);
    SimdN::LocalM128 t2 = SimdN::_mm_shuffle_ps(ctmp, c2, 0xe4);
    const SimdN::LocalM128 b0 = SimdN::_mm_shuffle_ps(b, b, 0x00);
    const SimdN::LocalM128 r0 = SimdN::_mm_mul_ps(c0, b0);
    const SimdN::LocalM128 b1 = SimdN::_mm_shuffle_ps(b, b, 0x55);
    const SimdN::LocalM128 r1 = SimdN::_mm_mul_ps(c1, b1);
    const SimdN::LocalM128 b2 = SimdN::_mm_shuffle_ps(b, b, 0xaa);
    const SimdN::LocalM128 r2 = SimdN::_mm_mul_ps(t2, b2);
    simd(*this) = SimdN::_mm_add_ps(SimdN::_mm_add_ps(r0, r1), r2);
}

__forceinline void hkVector4::_setTransformedInversePos(const hkTransform& t, const hkVector4& b)
{
    hkVector4 d;
    simd(d) = SimdN::_mm_sub_ps(simd(b), reinterpret_cast<const SimdN::LocalM128&>(t.m_row3));
    _setRotatedInverseDir(reinterpret_cast<const hkRotation&>(t), d);
}

struct WorldRayCastInput
{
    hkVector4 m_vFrom;
    hkVector4 m_vTo;
};

struct ShapeRayCastQuery
{
    hkVector4 m_vFrom;
    hkVector4 m_vTo;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
};

struct __declspec(align(16)) ShapeRayCastOutput
{
    hkVector4 m_vHitNormal;
    float m_fHitFraction;
    int m_iExtraInfo;
    int unk18;
    int unk1C;
    int m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;
    int unk44;
    int unk48;
    int unk4C;
};

struct WorldRayCastOutput : ShapeRayCastOutput
{
    const hkpCdBody* m_pRootCollidable;
    int unk54;
    int unk58;
    int unk5C;
};

struct HitList
{
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
    int m_pRayCursor;
    int m_iElementCount;
    char unk3C;
    char m_earlyOutOnFirstHit;
    char unk3E;
    char unk3F;
};

__forceinline void memCpy16NonEmpty(void*, const void*, int);
struct RayCaster_00df8aa0 : S_00df8d60
{
    hkBool CastBody_Thunk(const void* data);
    hkBool m_bHit;
    char unk19;
    char unk1A;
    char unk1B;
    HitList* m_kHits;
    const WorldRayCastInput* m_pRayCastInput;
    WorldRayCastOutput* m_akRayOutputs;
    WorldRayCastOutput* m_pHitBufferEnd;
    int unk2C;
    ShapeRayCastQuery m_kShapeRayInput;
    hkpFixedBufferRayHitCollector* m_kCollector;
    int unk64;
    int unk68;
    int unk6C;
    hkVector4 m_earlyOutHitFractionVec;

    __forceinline hkBool castBody(const void* data)
    {

        RayCaster_00df8aa0* self = this;
        const hkpCdBody* body = (const hkpCdBody*)data;
        const hkpShape* shape = body->m_pCollisionShape;

        hkBool result;
        result.m_cBooleanValue = 0;
        if (!shape || !self->filter()->IsCollisionEnabled(*self->m_pRayCastInput, reinterpret_cast<const hkpCollidable&>(*body)))
        {
            return result;
        }

        const hkTransform& t = *static_cast<const hkTransform*>(body->m_pMotionState);
        self->m_kShapeRayInput.m_vFrom._setTransformedInversePos(t, self->m_pRayCastInput->m_vFrom);
        self->m_kShapeRayInput.m_vTo._setTransformedInversePos(t, self->m_pRayCastInput->m_vTo);

        ShapeRayCastOutput output;
        output.m_fHitFraction = self->unk14;
        output.m_iExtraInfo = -1;
        output.m_uiShapeKeys[0] = -1;
        output.m_uiShapeKeyIndex = 0;

        if (!self->m_kCollector)
        {
            hkBool hit = shape->IntersectRayWithShape(self->m_kShapeRayInput, output);
            result.m_cBooleanValue = hit.m_cBooleanValue;
            if (!hit)
            {
                return result;
            }
            {
                float fraction;
                WorldRayCastOutput* slot = self->getOutputSlot(output.m_fHitFraction, fraction);
                if (slot)
                {
                    output.m_vHitNormal._setRotatedDir(reinterpret_cast<const hkRotation&>(t), output.m_vHitNormal);
                    memCpy16NonEmpty(slot, &output, sizeof(WorldRayCastOutput) / 16);
                    slot->m_pRootCollidable = body;
                    if (self->m_kHits->m_earlyOutOnFirstHit)
                    {
                        output.m_fHitFraction = 0.0f;
                    }
                    self->unk14 = (self->m_kHits->m_pRayCursor == 1) ? output.m_fHitFraction : fraction;
                    self->m_bHit = true;
                    simd(self->m_earlyOutHitFractionVec) = SimdN::_mm_set_ps1(self->unk14);
                }
            }
            return result;
        }
        shape->CastRayWithCollector(self->m_kShapeRayInput, *body, *self->m_kCollector);
        self->m_kHits->m_iElementCount = self->m_kCollector->m_iHitCount.m_storage;
        simd(self->m_earlyOutHitFractionVec) = SimdN::_mm_set_ps1(self->m_kCollector->m_fEarlyOutHitFraction);
        return result;
    }

    const hkpRayCollidableFilter* filter() const
    {
        const hkpCollisionFilter* collisionFilter = (const hkpCollisionFilter*)unk10;
        // The query requires a filter; preserve the original unconditional base adjustment.
        __assume(collisionFilter != 0);
        return static_cast<const hkpRayCollidableFilter*>(collisionFilter);
    }

    __forceinline WorldRayCastOutput* getOutputSlot(float hitFraction, float& oldFraction)
    {
        int size = m_kHits->m_iElementCount;
        WorldRayCastOutput* entry = m_akRayOutputs;
        if (size < m_kHits->m_pRayCursor)
        {
            WorldRayCastOutput* slot = m_pHitBufferEnd;
            oldFraction = 1.0f;
            m_kHits->m_iElementCount = size + 1;
            m_pHitBufferEnd++;
            return slot;
        }
        WorldRayCastOutput* slot = entry;
        entry++;
        if (1 < size)
        {
            size--;
            do
            {
                if (entry->m_fHitFraction > slot->m_fHitFraction)
                {
                    slot = entry;
                }
                entry++;
            } while (--size);
        }
        if (hitFraction < slot->m_fHitFraction)
        {
            oldFraction = slot->m_fHitFraction;
            return slot;
        }
        return 0;
    }
};

__forceinline void memCpy16NonEmpty(void* dst, const void* src, int numQuads)
{
    const unsigned int* src32 = (const unsigned int*)src;
    unsigned int* dst32 = (unsigned int*)dst;
    do
    {
        dst32[0] = src32[0];
        dst32[1] = src32[1];
        dst32[2] = src32[2];
        dst32[3] = src32[3];
        dst32 += 4;
        src32 += 4;
    } while (--numQuads > 0);
}

// Delegates to castBody to test a collision body against the ray and record any hit in the output buffer.
// @fnv 0x00df8aa0
// src: GUESS 0x00df8aa0 (confidence: medium)
hkBool RayCaster_00df8aa0::CastBody_Thunk(const void* apBody)
{
    return castBody(apBody);
}
