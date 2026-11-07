// src/havok/physics/dynamics/constraint/breakable/hkpbreakableconstraintdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/breakable/hkpbreakableconstraintdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

typedef float hkReal;
typedef unsigned short hkUint16;
#include "../../../../../../include/hkBaseObject.h"
#include "../../../../../../include/hkBool.h"

// Retain this unit's intrinsic storage without the SDK's character aliases.
#ifndef _INCLUDED_MM2
#define _INCLUDED_MM2
// Exe 0x00d4e1e0 FUN_00d4e1e0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C"
{
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
    LocalM128 _mm_unpacklo_ps(LocalM128, LocalM128);
    LocalM128 _mm_load_ss(float const*);
    LocalM128 _mm_setr_ps(float, float, float, float);
    LocalM128 _mm_set_ps1(float);
}
#endif
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkVector4q.h"
#include "../../../../../../include/hkpVelocityAccumulator.h"
#include "../../../../../../include/FinishingFlag.h"
#include "../../../../../../include/hkReferencedObject.h"
#include "../../../../../../include/hkpConstraintData.h"
#include "../../../../../../include/hkpMalleableConstraintData.h"
#include "../../../../../../include/hkpConstraintAtom.h"
#include "../../../../../../include/hkpBridgeConstraintAtom.h"
#include "../../../../../../include/hkpConstraintInstance.h"
#include "../../../../../../include/hkpEntity.h"
#include "../../../../../../include/hkpWorld.h"
__forceinline hkpConstraintAtom::hkpConstraintAtom(AtomType type) : m_type((hkUint16)type) {}
__forceinline hkpConstraintAtom::hkpConstraintAtom(FinishingFlag) {}

__forceinline hkpBridgeConstraintAtom::hkpBridgeConstraintAtom() : hkpConstraintAtom(TYPE_BRIDGE) {}
__forceinline hkpBridgeConstraintAtom::hkpBridgeConstraintAtom(FinishingFlag flag) : hkpConstraintAtom(flag)
{
    if (flag.m_bFinishing)
        hkpBridgeConstraintAtom_init(m_pConstraintData);
}

#include "../../../../../../include/hkpBridgeAtoms.h"

__forceinline hkpConstraintData::hkpConstraintData() throw() : m_ulUserData(0) {}
__forceinline hkpConstraintData::hkpConstraintData(FinishingFlag flag) : hkReferencedObject(flag) {}

// include/hkpConstraintData.h only forward-declares this atom/schema info layout.
struct hkpConstraintDataInfo
{
    int m_iMaxSchemaSize;
    int m_iSchemaByteSize;
    int m_iSolverResultCount;
    int m_iSolverElementTemporaryCount;
    hkpConstraintAtom* m_kBridgeAtoms;
    int m_usSizeOfAllAtoms;
};

struct hkpConstraintQueryIn;

// No approved include/ hkpBreakableConstraintData header exists yet.
class hkpBreakableConstraintData : public hkpConstraintData
{
public:
    hkpBridgeAtoms m_kBridgeAtoms;
    hkpConstraintData* m_pConstraintData;
    hkUint16 m_usRuntimeOffset;
    hkUint16 m_usNumSolverResults;
    hkReal m_fBreakingStrength;
    hkBool m_bRemoveWhenBroken;
    hkBool m_bRevertBackVelocityOnBreak;
    char pad26[2];

    hkpBreakableConstraintData(FinishingFlag flag);
    hkpBreakableConstraintData(hkpConstraintData* constraintData) throw();
    void SetConstraintData(hkpConstraintData* data);
    virtual ~hkpBreakableConstraintData() throw();
    // The deleting wrapper at 0x00cc48b0 calls this destructor body out of line.
    __declspec(noinline) void UpdateFields_00d4e000();
    hkpBreakableConstraintData* Destroy(unsigned int flags);
    void getRuntimeInfo(int, void* out);
    void PopulateInfo(hkpConstraintDataInfo& info) const;
    void* isValid_00d4dea0(void* value);
    void buildJacobian(const hkpConstraintQueryIn& in, int out);
    void buildJacobianCallback(const hkpConstraintQueryIn* in);
    void setBroken(hkpConstraintInstance* instance, hkBool broken, hkReal currentForce);
};

// @fnv 0x00d4de80
// src: HAVOK_LIB 0x00d4de80
void hkpBreakableConstraintData::getRuntimeInfo(int, void* out)
{
    ((int*)out)[1] = m_usNumSolverResults;
    ((int*)out)[0] = m_usRuntimeOffset + 0x34;
}

// @fnv 0x00d4de50
void hkpBreakableConstraintData::PopulateInfo(hkpConstraintDataInfo& info) const
{
    m_pConstraintData->PopulateInfo(info);
    info.m_kBridgeAtoms = const_cast<hkpBridgeConstraintAtom*>(&m_kBridgeAtoms.m_kBridgeAtom);
    info.m_usSizeOfAllAtoms = 0xc;
}

// @fnv 0x00d4dea0
// src: HAVOK_LIB 0x00d4dea0
void* hkpBreakableConstraintData::isValid_00d4dea0(void* value)
{
    // The shared v07 declaration omits this slot's output parameter.
    reinterpret_cast<void (__thiscall*)(hkpConstraintData*, void*)>(
        (*reinterpret_cast<void***>(m_pConstraintData))[0x1c / 4])(m_pConstraintData, value);
    return value;
}

extern void* DAT_010d0a1c;
extern void* _DAT_0102e388;

// @fnv 0x00d4e000
// src: GUESS 0x00d4e000 (confidence: low)
void hkpBreakableConstraintData::UpdateFields_00d4e000()
{
    hkpConstraintData* oldData = m_pConstraintData;
    *reinterpret_cast<void**>(this) = &DAT_010d0a1c;
    oldData->removeReference();
    *reinterpret_cast<void**>(this) = &_DAT_0102e388;
}

// @fnv 0x00d4dec0
// src: GUESS 0x00d4dec0 (confidence: high)
int __cdecl Object_Return0xc()
{
    return 0xc;
}

struct FnvCpu_FUN_00cc48b0_CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct FnvCpu_FUN_00cc48b0_CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00cc48b0_CpuAllocator* allocator;
};
FnvCpu_FUN_00cc48b0_CpuAllocatorHolder* __cdecl hkMemoryRouter_getInstance();

// Calls FUN_00d4e000, then if flags has bit 0 set, frees this object through the allocator from FUN_00c85750, and returns this.
// @fnv 0x00cc48b0
hkpBreakableConstraintData* hkpBreakableConstraintData::Destroy(unsigned int flags)
{
    UpdateFields_00d4e000();
    if (flags & 1)
    {
        FnvCpu_FUN_00cc48b0_CpuAllocatorHolder* holder = hkMemoryRouter_getInstance();
        holder->allocator->Invoke(this, m_usMemSizeAndFlags);
    }
    return this;
}

// Constructs the constraint data and bridge atoms, then, when the finish-loaded flag is set, calls the bridge atoms' finish routine on this object.
// @fnv 0x00d4dfc0
hkpBreakableConstraintData::hkpBreakableConstraintData(FinishingFlag flag) : hkpConstraintData(flag), m_kBridgeAtoms(flag)
{
    if (flag.m_bFinishing)
        m_kBridgeAtoms.m_kBridgeAtom.hkpBridgeConstraintAtom_init(this);
}

// Stores ref, calls FUN_00c90510 on it if non-null, sets m_fSpringStrength to 0.01, and calls FUN_00d21ce0(this) on m_kBridgeAtoms.m_kBridgeAtom.
// @fnv 0x00cdf710
hkpMalleableConstraintData::hkpMalleableConstraintData(hkpConstraintData* ref) throw() : m_pConstraintData(ref), m_fSpringStrength(0.01f)
{
    if (m_pConstraintData)
        m_pConstraintData->FUN_00c90510();
    m_kBridgeAtoms.m_kBridgeAtom.hkpBridgeConstraintAtom_init(this);
}

// No approved include/ constraint query definition exists yet.
struct hkpConstraintQueryIn
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
    hkpVelocityAccumulator* m_pBodyA;
    hkpVelocityAccumulator* m_pBodyB;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    struct InstanceSlot
    {
        void* m_val;
        __forceinline void* val() const { return m_val; }
    } m_pConstraintChainInstance;
    char* m_pByteBuffer;
};

// Shared hkpWorld lacks removeConstraint (0x00c97e80); keep its call declaration here.
extern void removeWorldConstraint();

void __stdcall hkpBreakableConstraintData_buildNopJacobian(const hkpConstraintQueryIn& in, int out);
void __cdecl hkSimpleContactConstraintDataBuildJacobian(hkpConstraintAtom* atoms, const hkpConstraintQueryIn& in, hkBool flag,
                          int out);
void __cdecl hkSolverBuildJacobianFromAtomsNotContact(hkpConstraintAtom* atoms, int sizeOfAllAtoms, const hkpConstraintQueryIn& in, int out);

struct hkpBreakableRuntime
{
    hkBool m_bFlag;
    hkReal m_linearVelA[3];
    hkReal m_linearVelB[3];
    hkReal m_angularVelA[3];
    hkReal m_angularVelB[3];
};

__forceinline void store3(const hkVector4& v, hkReal* p)
{
    p[0] = v.x;
    p[1] = v.y;
    p[2] = v.z;
}

// If the runtime flag is clear, saves body velocities and calls FUN_00d72190 or FUN_00d6f460; else calls FUN_00d4de30 and optionally removes the constraint.
// @fnv 0x00d4e0f0
// src: XBOX_PDB 0x00d4e0f0
void hkpBreakableConstraintData::buildJacobian(const hkpConstraintQueryIn& in, int out)
{
    hkpBreakableRuntime* runtime = reinterpret_cast<hkpBreakableRuntime*>(in.m_pByteBuffer + m_usRuntimeOffset);

    if (!runtime->m_bFlag)
    {
        const hkpVelocityAccumulator* bodyA = in.m_pBodyA;
        const hkpVelocityAccumulator* bodyB = in.m_pBodyB;
        store3(bodyA->m_vLinearVelocity, runtime->m_linearVelA);
        store3(bodyB->m_vLinearVelocity, runtime->m_linearVelB);
        store3(bodyA->m_vAngularVelocity, runtime->m_angularVelA);
        store3(bodyB->m_vAngularVelocity, runtime->m_angularVelB);

        hkpConstraintDataInfo info;
        m_pConstraintData->PopulateInfo(info);

        if (info.m_kBridgeAtoms->m_type == hkpConstraintAtom::TYPE_CONTACT)
        {
            hkBool flag;
            flag.m_cBooleanValue = 1;
            hkSimpleContactConstraintDataBuildJacobian(info.m_kBridgeAtoms, in, flag, out);
        }
        else
        {
            hkSolverBuildJacobianFromAtomsNotContact(info.m_kBridgeAtoms, info.m_usSizeOfAllAtoms, in, out);
        }
    }
    else
    {
        hkpBreakableConstraintData_buildNopJacobian(in, out);

        if (m_bRemoveWhenBroken)
        {
            hkBool result;
            hkpConstraintInstance* instance = static_cast<hkpConstraintInstance*>(in.m_pConstraintChainInstance.val());
            reinterpret_cast<void (__thiscall*)(hkpWorld*, hkBool*, hkpConstraintInstance*)>(
                &removeWorldConstraint)(static_cast<hkpWorld*>(instance->m_kActorEntries[0]->m_pOwningWorld), &result, instance);
        }
    }
}

extern "C" double __cdecl sqrt(double);

extern const LocalM128 DAT_010ec7f0;

__forceinline void hkVector4q::setInterpolate4(const hkVector4q& v0, const hkVector4q& v1, const hkVector4q& t)
{
    LocalM128 s = _mm_sub_ps(DAT_010ec7f0, t.m_vComponents);
    m_vComponents = _mm_add_ps(_mm_mul_ps(v0.m_vComponents, s), _mm_mul_ps(v1.m_vComponents, t.m_vComponents));
}

__forceinline void hkVector4q::blendFrom(const hkVector4q& v0, const hkVector4q& t)
{
    hkVector4q tmp;
    tmp.setInterpolate4(v0, *this, t);
    m_vComponents = tmp.m_vComponents;
}

static __forceinline hkReal hkMath_sqrt(hkReal r)
{
    return (hkReal)sqrt(r);
}

static __forceinline hkReal hkMath_sqrtInverse(hkReal r)
{
    return 1.0f / hkMath_sqrt(r);
}

struct ContactImpulseInfo
{
    hkReal m_fAccumulatedImpulse;
    hkReal m_fImpulseLimit;

    __forceinline hkReal getImpulseApplied() const
    {
        return m_fAccumulatedImpulse;
    }
};

// If the squared impulse sum exceeds breaking strength squared, calls FUN_00d4e020 and optionally blends body velocities back; always zeroes the impulses.
// @fnv 0x00d4e1e0
// src: XBOX_PDB 0x00d4e1e0
void hkpBreakableConstraintData::buildJacobianCallback(const hkpConstraintQueryIn* in)
{
    ContactImpulseInfo* pImpulseInfo = reinterpret_cast<ContactImpulseInfo*>(in->m_pByteBuffer);
    hkpBreakableRuntime* runtime =
        reinterpret_cast<hkpBreakableRuntime*>(reinterpret_cast<char*>(pImpulseInfo) + m_usRuntimeOffset);
    int numResults = m_usNumSolverResults;

    if (!runtime->m_bFlag)
    {
        hkReal sumImpulse = 0.0f;
        for (int i = 0; i < numResults; i++)
        {
            hkReal impulse = pImpulseInfo[i].getImpulseApplied();
            sumImpulse += impulse * impulse;
        }

        if (sumImpulse > m_fBreakingStrength * m_fBreakingStrength)
        {

            setBroken(static_cast<hkpConstraintInstance*>(in->m_pConstraintChainInstance.val()), true, hkMath_sqrt(sumImpulse));

            if (m_bRevertBackVelocityOnBreak)
            {
                hkVector4q factor;
                (factor.*static_cast<void (hkVector4q::*)(float)>(&hkVector4q::SetAllComponents))(
                    hkMath_sqrtInverse(sumImpulse) * m_fBreakingStrength);

                hkVector4q linA;
                linA.set(runtime->m_linearVelA[0], runtime->m_linearVelA[1], runtime->m_linearVelA[2]);
                hkVector4q linB;
                linB.set(runtime->m_linearVelB[0], runtime->m_linearVelB[1], runtime->m_linearVelB[2]);
                hkVector4q angA;
                angA.set(runtime->m_angularVelA[0], runtime->m_angularVelA[1], runtime->m_angularVelA[2]);
                hkVector4q angB;
                angB.set(runtime->m_angularVelB[0], runtime->m_angularVelB[1], runtime->m_angularVelB[2]);

                hkpVelocityAccumulator* bodyA = in->m_pBodyA;
                hkpVelocityAccumulator* bodyB = in->m_pBodyB;
                reinterpret_cast<hkVector4q&>(bodyA->m_vLinearVelocity).blendFrom(linA, factor);
                reinterpret_cast<hkVector4q&>(bodyB->m_vLinearVelocity).blendFrom(linB, factor);
                reinterpret_cast<hkVector4q&>(bodyA->m_vAngularVelocity).blendFrom(angA, factor);
                reinterpret_cast<hkVector4q&>(bodyB->m_vAngularVelocity).blendFrom(angB, factor);
            }
        }
    }

    for (int i = 0; i < numResults; i++)
    {
        pImpulseInfo[i].m_fAccumulatedImpulse = 0.0f;
    }
}

struct RuntimeInfoD4D
{
    int m_iSolverIterationCount;
    int m_iSolverResultCount;
};

static __forceinline void getConstraintRuntimeInfo(hkpConstraintData* const& data, RuntimeInfoD4D& info) throw()
{
    data->GetConstraintRuntimeInfo(true, info);
}

// @fnv 0x00d4df30
hkpBreakableConstraintData::hkpBreakableConstraintData(hkpConstraintData* constraintData) throw() : m_pConstraintData(constraintData)
{
    m_fBreakingStrength = 10.0f;
    m_bRemoveWhenBroken = false;
    m_bRevertBackVelocityOnBreak = false;
    if (m_pConstraintData)
    {
        m_pConstraintData->FUN_00c90510();
        RuntimeInfoD4D info;
        getConstraintRuntimeInfo(m_pConstraintData, info);
        m_usRuntimeOffset = (unsigned short)info.m_iSolverIterationCount;
        m_usNumSolverResults = (unsigned short)info.m_iSolverResultCount;
    }
    m_kBridgeAtoms.m_kBridgeAtom.hkpBridgeConstraintAtom_init(this);
}
// Retains the wrapped data, releases the previous data, and caches its runtime-info sizes.
// @fnv 0x00d4ded0
void hkpBreakableConstraintData::SetConstraintData(hkpConstraintData* shape)
{
    if (shape)
        shape->FUN_00c90510();
    if (m_pConstraintData)
        m_pConstraintData->removeReference();
    m_pConstraintData = shape;
    if (shape)
    {
        RuntimeInfoD4D info;
        getConstraintRuntimeInfo(m_pConstraintData, info);
        m_usRuntimeOffset = (hkUint16)info.m_iSolverIterationCount;
        m_usNumSolverResults = (hkUint16)info.m_iSolverResultCount;
    }
}

class GlobalObjectO2_00d472a0;

struct ConstraintRuntimeInfo
{
    int unk00, unk04, unk08, unk0c;
    unsigned short unk10;
    unsigned char m_flags;
    unsigned char unk13;
    int unk14, unk18;
    char* m_pRuntime;
};

class hkpSimulationIsland;

// 0x00d4e020 reads an event context pointer at owner+0x18; the approved owner
// and island headers do not expose that pointer layout.
struct ConstraintOwnerEventContext
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    hkpSimulationIsland* m_pSimulationIsland;
};

struct BrkInfo
{
    hkpSimulationIsland* m_pCurrentSimulationIsland;
    hkpConstraintInstance* m_pHavokConstraint;
    const GlobalObjectO2_00d472a0* m_type;
    int m_0c;
    float m_uiFilterValue;
    float m_threshold;

    BrkInfo(hkpSimulationIsland* island, hkpConstraintInstance* constraint, const GlobalObjectO2_00d472a0* type)
        : m_pCurrentSimulationIsland(island), m_pHavokConstraint(constraint), m_type(type), m_0c(0)
    {}
};

void __cdecl hkpConstraintCallbackUtil_fireConstraintBroken(BrkInfo* pkInfo);
void __cdecl hkpConstraintCallbackUtil_fireConstraintRepaired(BrkInfo* pkInfo);
void __cdecl hkpWorldCallbackUtil_fireConstraintBroken(hkpSimulationIsland* pkIsland, BrkInfo* pkInfo);
void __cdecl hkpWorldCallbackUtil_fireConstraintRepaired(hkpSimulationIsland* pkIsland, BrkInfo* pkInfo);

extern char DAT_01269c44;

// Sets the broken flag on the breakable runtime, updates the constraint flags, and dispatches a BrkInfo event to listeners and the simulation island.
// @fnv 0x00d4e020
// src: HAVOK_LIB 0x00d4e020
void hkpBreakableConstraintData::setBroken(hkpConstraintInstance* apInstance, hkBool broken, float currentForce)
{
    hkpConstraintInstance* instance = reinterpret_cast<hkpConstraintInstance*>(*(volatile int*)&apInstance);
    hkpBreakableRuntime* runtime =
        reinterpret_cast<hkpBreakableRuntime*>(m_usRuntimeOffset + instance->m_pConstraintInternal->m_pRuntime);
    bool wasBroken = runtime->m_bFlag;
    if (broken.m_cBooleanValue == wasBroken)
    {
        return;
    }
    runtime->m_bFlag = broken;
    if (!broken)
    {
        instance->m_pConstraintInternal->m_flags |= 4;
    }
    else
    {
        instance->m_pConstraintInternal->m_flags &= ~4;
    }

    hkpSimulationIsland* world = reinterpret_cast<ConstraintOwnerEventContext*>(instance->m_pOwnerObject)->m_pSimulationIsland;
    BrkInfo event(world, instance, reinterpret_cast<const GlobalObjectO2_00d472a0*>(&DAT_01269c44));
    if (broken)
    {
        event.m_0c = 0;
        event.m_uiFilterValue = currentForce;
        event.m_threshold = m_fBreakingStrength;
        if (event.m_pHavokConstraint->m_kListeners.m_iElementCount)
        {
            hkpConstraintCallbackUtil_fireConstraintBroken(&event);
        }
        hkpWorldCallbackUtil_fireConstraintBroken(world, &event);
    }
    else
    {
        event.m_0c = 0;
        if (event.m_pHavokConstraint->m_kListeners.m_iElementCount)
        {
            hkpConstraintCallbackUtil_fireConstraintRepaired(&event);
        }
        hkpWorldCallbackUtil_fireConstraintRepaired(world, &event);
    }
}
