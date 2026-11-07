#include "../../../../../../include/hkArray.h"

// src/havok/physics/dynamics/constraint/setup/hkpconstraintsolversetup.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/setup/hkpconstraintsolversetup.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Exe 0x00d883c0 FUN_00d883c0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;

extern "C" LocalM128 _mm_setzero_ps();

#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkpEntity.h"
#include "../../../../../../include/hkStepInfo.h"
#include "../../../../../../include/hkpVelocityAccumulator.h"
#include "../../../../../../include/hkpConstraintSolverResources.h"

inline void hkVector4::setZero4()
{
    m_vComponents = _mm_setzero_ps();
}

void __cdecl Object_UpdateFields_00d8aac0(void* owner, void* current, int eventCode, int flags);
// Optionally resets currentA/currentB to their reset values, zeroes the float range up to end, and notifies callbacks when current differs from desired.
// @fnv 0x00d88340
// src: HAVOK_LIB 0x00d88340
void __cdecl hkpConstraintSolverSetup_subSolve(hkpConstraintSolverResources* state, int reset)
{
    if (reset == 0)
    {
        state->m_akBufferStates[0].m_pValues = state->m_akBufferStates[0].m_pRayStart;
        state->m_akBufferStates[1].m_pValues = state->m_akBufferStates[1].m_pRayStart;
    }
    volatile float* p = reinterpret_cast<volatile float*>(state->m_akBufferStates[2].m_pValues);
    while (p < reinterpret_cast<volatile float*>(state->m_akBufferStates[2].m_pTileTemplate))
    {
        *p = 0.0f;
        ++p;
    }
    state->m_akBufferStates[2].m_pValues = state->m_akBufferStates[2].m_pTileTemplate;
    if (state->m_akBufferStates[0].m_pValues != state->m_akBufferStates[0].m_pTileTemplate)
        Object_UpdateFields_00d8aac0(state->m_pSolverInfo, state->m_akBufferStates[0].m_pValues, reinterpret_cast<int>(state->m_pVelocityAccumulatorA), reinterpret_cast<int>(state->m_akBufferStates[2].m_pRayStart));
    if (state->m_akBufferStates[1].m_pValues != state->m_akBufferStates[1].m_pTileTemplate)
        Object_UpdateFields_00d8aac0(state->m_pSolverInfo, state->m_akBufferStates[1].m_pValues, reinterpret_cast<int>(state->m_pVelocityAccumulatorA), reinterpret_cast<int>(state->m_akBufferStates[2].m_pRayStart));
    state->m_akBufferStates[0].m_pValues = state->m_akBufferStates[0].m_pTileTemplate;
    state->m_akBufferStates[1].m_pValues = state->m_akBufferStates[1].m_pTileTemplate;
}

struct D88310Bool
{
    char m_cBooleanValue;

    D88310Bool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

// @fnv 0x00d88310
// src: HAVOK_LIB 0x00d88310
D88310Bool __cdecl hkpConstraintSolverSetup_internalIsMemoryOkForNewAccumulators(const hkpConstraintSolverResources* stream, const void* unused, int numBlocks)
{
    int available = (int)(reinterpret_cast<char*>(stream->m_pVelocityAccumulatorB) - reinterpret_cast<char*>(stream->m_pVelocityAccumulatorC));
    if (stream->m_pVelocityAccumulatorC == stream->m_pVelocityAccumulatorA)
        numBlocks++;
    if (numBlocks * 128 > available - 16)
        return false;
    return true;
}

// @fnv 0x00d88300
// src: XBOX_PDB 0x00d88300
void __cdecl hkpConstraintSolverSetup_shutdownSolver()
{}

struct D88470Sub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    unsigned short amountA;
    unsigned short unk16;
    unsigned short amountB;
    unsigned short unk1a;
};

struct D88470Elem
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    unsigned char type;
    unsigned char unk1d;
    unsigned char unk1e;
    unsigned char unk1f;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    D88470Sub* sub;
};

// Accumulates amountA per element type and amountB*4 into totals, then returns true if the sums stay within obj's limitSum, limitA and limitB.
// @fnv 0x00d88470
D88310Bool __cdecl CheckTotalsWithinLimits(hkpConstraintSolverResources* obj, D88470Elem** begin, int count)
{
    unsigned int totals[2];
    totals[0] = reinterpret_cast<unsigned int>(obj->m_akBufferStates[0].m_pTileTemplate);
    totals[1] = reinterpret_cast<unsigned int>(obj->m_akBufferStates[1].m_pTileTemplate);
    unsigned int sum = reinterpret_cast<unsigned int>(obj->m_akBufferStates[2].m_pTileTemplate);
    unsigned int uiSum1 = 0;
    unsigned int uiSum2 = 0;
    D88470Elem** end = begin + count;
    int iCount = ((char*)end - (char*)begin + 3) / 4;
    D88470Elem** p = begin;
    if (iCount >= 2)
    {
        do
        {
            D88470Elem* pElem = p[0];
            unsigned int uiTypeIndex = pElem->type >= 5 ? 1 : 0;
            D88470Sub* s = pElem->sub;
            uiSum1 += s->amountB * 4;
            totals[uiTypeIndex] += s->amountA;
            pElem = p[1];
            uiTypeIndex = pElem->type >= 5 ? 1 : 0;
            s = pElem->sub;
            uiSum2 += s->amountB * 4;
            totals[uiTypeIndex] += s->amountA;
            p += 2;
        } while ((int)p < (int)(end - 1));
    }
    if (p < end)
    {
        D88470Elem* pElem = *p;
        unsigned int uiTypeIndex = pElem->type >= 5 ? 1 : 0;
        D88470Sub* s = pElem->sub;
        sum += s->amountB * 4;
        totals[uiTypeIndex] += s->amountA;
    }
    sum += uiSum1 + uiSum2;
    if (sum <= reinterpret_cast<unsigned int>(obj->m_akBufferStates[2].m_kRayEnd) && totals[0] + 4 <= reinterpret_cast<unsigned int>(obj->m_akBufferStates[0].m_kRayEnd) && totals[1] + 4 <= reinterpret_cast<unsigned int>(obj->m_akBufferStates[1].m_kRayEnd))
        return true;
    else
        return false;
}

// Local until include/ supplies hkpVelocityAccumulator (128-byte solver body).

struct hkpSolverSumVelocities
{
    hkVector4 m_vLinearVelocity;
    hkVector4 m_vAngularVelocity;
};

hkpVelocityAccumulator* __cdecl hkRigidMotionUtilApplyForcesAndBuildAccumulators(const hkStepInfo* pkInfo, hkpEntity* const* ppkEntities,
                                                 unsigned int uiNumEntities, int iMotionOffset,
                                                 hkpVelocityAccumulator* pkAccumulatorsOut);

// @fnv 0x00d88670
// src: GUESS 0x00d88670 (confidence: low)
void __cdecl hkpConstraintSolverResources_ProcessEntries_00d88670(hkpConstraintSolverResources& kResources, hkpEntity* const* ppkEntities,
                          unsigned int uiNumEntities)
{
    if (!uiNumEntities)
    {
        return;
    }

    if (kResources.m_pVelocityAccumulatorC == kResources.m_pVelocityAccumulatorA)
    {
        hkpVelocityAccumulator* pkFixed = kResources.m_pVelocityAccumulatorC;
        pkFixed->setFixed();
        kResources.m_pVelocityAccumulatorC = pkFixed + 1;
        hkpSolverSumVelocities* pkFixedSumVel = kResources.m_sumVelocities;
        pkFixedSumVel->m_vAngularVelocity.setZero4();
        pkFixedSumVel->m_vLinearVelocity.setZero4();
    }

    for (unsigned int i = 0; i < uiNumEntities; i++)
    {
        ppkEntities[i]->m_uiFilterInfo = reinterpret_cast<unsigned int>(kResources.m_pVelocityAccumulatorC + i) -
                                         reinterpret_cast<unsigned int>(kResources.m_pVelocityAccumulatorA);
    }

    hkpVelocityAccumulator* pkAccumulator = kResources.m_pVelocityAccumulatorC;
    hkpSolverSumVelocities* pkSumVel =
        kResources.m_sumVelocities + ppkEntities[0]->m_uiFilterInfo / sizeof(hkpVelocityAccumulator);
    kResources.m_pVelocityAccumulatorC =
        hkRigidMotionUtilApplyForcesAndBuildAccumulators(kResources.m_pStepInfo, ppkEntities, uiNumEntities, 0xe0, pkAccumulator);

    for (unsigned int i = 0; i < uiNumEntities; i++)
    {
        pkSumVel->m_vLinearVelocity = pkAccumulator->m_vCenterOfMass;
        pkSumVel->m_vAngularVelocity = pkAccumulator->m_scratch1;
        pkAccumulator->m_vCenterOfMass.setZero4();
        pkAccumulator->m_scratch1.setZero4();
        pkAccumulator++;
        pkSumVel++;
    }

    kResources.m_pVelocityAccumulatorC->m_type = 3;
}

struct S88_Allocator;

struct S88_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S88_Allocator* m_pStreamAllocator;
    S88_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

S88_Router* __cdecl hkMemoryRouter_getInstance();
void __cdecl ResizeAudioStream(S88_Allocator& a, void* array, int sizeElem);

template <typename T> struct S88_PadSpu
{
    T m_kStorage;
    void operator=(T v)
    {
        m_kStorage = v;
    }
    operator T() const
    {
        return m_kStorage;
    }
    T val() const
    {
        return m_kStorage;
    }
};

struct S88_Atom
{
    short m_type;
};

struct S88_QueryIn;

struct S88_ConstraintData
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual int getType() const;
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void BuildJacobianCallback(const S88_QueryIn& in);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    S88_Atom* m_pAtom;
};

struct S88_Internal
{
    int unk00;
    hkpEntity* m_kActorEntries[2];
    S88_Atom* m_kBridgeAtoms;
    unsigned short m_iAtomsSize;
    unsigned char m_ucCallbackRequest;
    unsigned char unk13;
    int unk14;
    unsigned short m_iSolverElementTemporaryCount;
    short unk1A;
    void* m_pRuntime;
    S88_Atom* getAtoms() const
    {
        return m_kBridgeAtoms;
    }
    unsigned short getAtomsSize() const
    {
        return m_iAtomsSize;
    }
};

struct S88_Instance
{
    int unk00;
    int unk04;
    int unk08;
    S88_ConstraintData* m_data;
    int unk10;
    int unk14;
    int unk18;
    unsigned char m_priority;
    unsigned char unk1D;
    unsigned char unk1E;
    unsigned char unk1F;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    S88_Internal* m_pConstraintInternal;
    int getPriority() const
    {
        return m_priority;
    }
    S88_Internal* getInternal()
    {
        return m_pConstraintInternal;
    }
    const S88_ConstraintData* getData() const
    {
        return m_data;
    }
    S88_ConstraintData* getDataRw() const
    {
        return m_data;
    }
    void* getRuntime() const
    {
        return m_pConstraintInternal->m_pRuntime;
    }
};

struct S88_QueryIn
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
    S88_PadSpu<const hkpVelocityAccumulator*> m_pBodyA;
    S88_PadSpu<const hkpVelocityAccumulator*> m_pBodyB;
    S88_PadSpu<const hkTransform*> m_kBodyALocalFrame;
    S88_PadSpu<const hkTransform*> m_kBodyBLocalFrame;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    S88_PadSpu<S88_Instance*> m_pConstraintChainInstance;
    S88_PadSpu<void*> m_pByteBuffer;
    int unk68;
    S88_PadSpu<unsigned int> m_uiParameterA;
    S88_PadSpu<unsigned int> m_uiParameterB;
    S88_PadSpu<void*> m_pUserData;
};

struct S88_Schema;

struct S88_QueryOut
{
    S88_PadSpu<S88_Schema*> m_pQueryResultSchema;
};

struct S88_Backup
{
    hkVector4 m_kTranslationalVelocity;
    hkVector4 m_kAngularVelocity;
};

struct S88_SchemaInfo
{
    S88_Instance* m_pHavokConstraint;
    S88_Schema* m_pConstraintSchema;
    float m_fAllowedPenetrationDepth;
};

static __forceinline S88_SchemaInfo& S88_Array_AllocatePair(hkArrayBase<S88_SchemaInfo>& self)
{
        S88_Allocator& alloc = hkMemoryRouter_getInstance()->heap();
        if (self.m_iElementCount == self.getCapacity())
        {
            ResizeAudioStream(alloc, (&self), sizeof(S88_SchemaInfo));
        }
        return self.m_data[self.m_iElementCount++];
    }

template <typename T> inline T* S88_addByteOffset(T* base, long offset)
{
    return reinterpret_cast<T*>(reinterpret_cast<char*>(base) + offset);
}

template <typename T> inline T S88_min2(T x, T y)
{
    return x < y ? x : y;
}

void __cdecl hkSimpleContactConstraintData_fireCallbacks(S88_ConstraintData* data, const S88_QueryIn* in, S88_Atom* atom, int type);
void __cdecl hkSimpleContactConstraintDataBuildJacobian(S88_Atom* atom, const S88_QueryIn& in, D88310Bool writeHeader, S88_QueryOut& out);
void __cdecl hkSolverBuildJacobianFromAtomsNotContact(const S88_Atom* atoms, int atomsSize, const S88_QueryIn& in, S88_QueryOut& out);

inline void S88_buildJacobianFromAtoms(S88_Atom* atoms, int atomsSize, const S88_QueryIn& in, S88_QueryOut& out)
{
    if (atoms->m_type == 0x16)
    {
        hkSimpleContactConstraintDataBuildJacobian(atoms, in, D88310Bool(true), out);
    }
    else
    {
        hkSolverBuildJacobianFromAtomsNotContact(atoms, atomsSize, in, out);
    }
}

// @fnv 0x00d88760
// src: XBOX_PDB 0x00d88760
void __cdecl hkpConstraintSolverSetup_internalAddJacobianSchemas(hkpConstraintSolverResources& s, S88_Instance** constraints, int numConstraints, hkArrayBase<S88_SchemaInfo>& constraintStatus)
{
    S88_QueryIn& in = *reinterpret_cast<S88_QueryIn*>(s.m_pConstraintQueryIn);
    S88_QueryOut out;

    for (S88_Instance **cp = constraints, **end = constraints + numConstraints; cp < end; cp++)
    {
        S88_Instance* instance = *cp;
        int prio = (instance->getPriority() == 5);
        hkpEntity** entities = &instance->getInternal()->m_kActorEntries[0];
        hkpMotion* motionA = &entities[0]->m_pMotionState;
        hkpMotion* motionB = &entities[1]->m_pMotionState;

        hkpVelocityAccumulator* pAccumulatorA =
            S88_addByteOffset(s.m_pVelocityAccumulatorA, entities[0]->m_uiFilterInfo);
        hkpVelocityAccumulator* pAccumulatorB =
            S88_addByteOffset(s.m_pVelocityAccumulatorA, entities[1]->m_uiFilterInfo);
        in.m_pBodyA = pAccumulatorA;
        in.m_pBodyB = pAccumulatorB;

        S88_Backup* backupA = &reinterpret_cast<S88_Backup*>(s.m_sumVelocities)[entities[0]->m_uiFilterInfo >> 7];
        S88_Backup* backupB = &reinterpret_cast<S88_Backup*>(s.m_sumVelocities)[entities[1]->m_uiFilterInfo >> 7];
        pAccumulatorA->m_vCenterOfMass = backupA->m_kTranslationalVelocity;
        pAccumulatorA->m_scratch1 = backupA->m_kAngularVelocity;
        pAccumulatorB->m_vCenterOfMass = backupB->m_kTranslationalVelocity;
        pAccumulatorB->m_scratch1 = backupB->m_kAngularVelocity;

        const hkMotionState* pMotionStateA = &motionA->m_kMotionState;
        const hkMotionState* pMotionStateB = &motionB->m_kMotionState;
        in.m_kBodyALocalFrame = &pMotionStateA->m_kMotionTransform;
        in.m_kBodyBLocalFrame = &pMotionStateB->m_kMotionTransform;
        in.m_pConstraintChainInstance = instance;
        in.m_pByteBuffer = instance->getRuntime();
        in.m_uiParameterA = (unsigned short)(entities[0]->m_uiFilterInfo >> 7);
        in.m_uiParameterB = (unsigned short)(entities[1]->m_uiFilterInfo >> 7);
        in.m_pUserData = instance->getRuntime();

        S88_SchemaInfo& info = S88_Array_AllocatePair(constraintStatus);
        info.m_pHavokConstraint = instance;
        info.m_pConstraintSchema = reinterpret_cast<S88_Schema*>(s.m_akBufferStates[prio].m_pTileTemplate);
        info.m_fAllowedPenetrationDepth = S88_min2(entities[0]->m_kCollidable.m_fAllowedPenetrationDepth,
                                                   entities[1]->m_kCollidable.m_fAllowedPenetrationDepth);

        out.m_pQueryResultSchema = reinterpret_cast<S88_Schema*>(s.m_akBufferStates[prio].m_pTileTemplate);

        if (instance->getData()->getType() == 11)
        {
            S88_ConstraintData* data = instance->getDataRw();
            hkSimpleContactConstraintData_fireCallbacks(data, &in, data->m_pAtom, 1);
        }

        if (instance->m_pConstraintInternal->m_ucCallbackRequest & 4)
        {
            instance->getDataRw()->BuildJacobianCallback(in);
        }

        S88_buildJacobianFromAtoms(instance->m_pConstraintInternal->getAtoms(),
                                   instance->m_pConstraintInternal->getAtomsSize(), in, out);

        s.m_akBufferStates[prio].m_pTileTemplate = reinterpret_cast<char*>(out.m_pQueryResultSchema.val());
        s.m_akBufferStates[2].m_pTileTemplate += instance->m_pConstraintInternal->m_iSolverElementTemporaryCount * 4;

        pAccumulatorA->m_vCenterOfMass.setZero4();
        pAccumulatorA->m_scratch1.setZero4();
        pAccumulatorB->m_vCenterOfMass.setZero4();
        pAccumulatorB->m_scratch1.setZero4();
    }

    *(int*)s.m_akBufferStates[0].m_pTileTemplate = 0;
    *(int*)s.m_akBufferStates[1].m_pTileTemplate = 0;
}

// local form of hkMatrix3: 0x00d883c0 needs inline setZero/accessors; shared form emits an out-of-line setZero call absent from exe.
struct S883_Matrix3
{
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
    __forceinline hkVector4& getColumn(int i)
    {
        return (&m_kColumn0)[i];
    }
    __forceinline void setZero()
    {
        hkVector4 zero;
        zero.setZero4();
        getColumn(0) = zero;
        getColumn(1) = zero;
        getColumn(2) = zero;
    }
};

struct S883_Accumulator
{
    unsigned char m_type;
    unsigned char m_iValueAtOffset0C;
    unsigned char unk02;
    unsigned char unk03;
    unsigned int m_uiDeactivationClass;
    float m_fGravityFactor;
    unsigned int unk0c;
    hkVector4 m_vLinearVelocity;
    hkVector4 m_vAngularVelocity;
    hkVector4 m_vInverseInertiaAndMass;
    hkVector4 m_vCenterOfMass;
    S883_Matrix3 m_kCoreFromWorldMatrix;

    __forceinline hkVector4& getCenterOfMassInWorld()
    {
        return m_vCenterOfMass;
    }
    __forceinline S883_Matrix3& getCoreFromWorldMatrix()
    {
        return m_kCoreFromWorldMatrix;
    }
    __forceinline void setFixed()
    {
        m_type = 1;
        m_fGravityFactor = 0.0f;
        m_vInverseInertiaAndMass.setZero4();
        m_vLinearVelocity.setZero4();
        m_vAngularVelocity.setZero4();
        getCenterOfMassInWorld().setZero4();
        getCoreFromWorldMatrix().setZero();
    }
};



struct S883_Island
{
    void* m_ppVirtualMethodTable;
    int unk04;
    int unk08;
    int m_iSchemaByteSize;
    int unk10;
    int m_iSolverElementTemporaryCount;
    int unk18;
    int m_maxConstraintInfoSize;
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
    hkArrayBase<void*> m_kActorEntries;
    __forceinline const hkArrayBase<void*>& GetEntities() const
    {
        return m_kActorEntries;
    }
};

struct S883_TaskHeader
{
    int m_iJobId;
    int m_iValueAt04;
    int m_iValueAt08;
    long m_sReferenceCount;
    int m_iValueAt10;
    void* m_buffer;
    int m_iBufferSize;
    int m_iValueAt1C;
    char m_cValueAt20;
    char m_bSplitCheckRequested;
    void* m_pPointerAt24;
    int unk28;
    int unk2c;
    S883_Accumulator* m_pAccumulatorA;
    void* m_pVelocityAccumulatorB;
    short m_usValueAt38;
    short m_usValueAt3A;
    void* m_pByteArrayAt3C;
    void* m_pIntegerArrayAt40;
};

// Lays out accumulator, schema and solver-element-temporary regions in buffer, sets taskHeader pointers and sizes, and initialises the first accumulator as fixed.
// @fnv 0x00d883c0
// src: GUESS 0x00d883c0 (confidence: low)
int __cdecl Object_ProcessAndReturnValue_00d883c0(const S883_Island& island, char* buffer, int bufferSize, S883_TaskHeader& taskHeader)
{
    taskHeader.m_buffer = buffer;
    int numEntities = island.GetEntities().GetLogicalSize();
    taskHeader.m_pAccumulatorA = reinterpret_cast<S883_Accumulator*>(buffer);
    int sizeForAccumulators = island.GetEntities().GetLogicalSize() * sizeof(S883_Accumulator) + 0x90;
    buffer += sizeForAccumulators;

    int numBlocks = 0;
    {
        int blockSize = 0x90;
        numBlocks = island.m_maxConstraintInfoSize / blockSize + 1;
        numBlocks += 3;
        numBlocks *= 2;
    }

    taskHeader.m_pByteArrayAt3C = buffer;
    int sizeForSchemas = island.m_iSchemaByteSize + 16;
    sizeForSchemas += numBlocks << 4;
    buffer += sizeForSchemas;

    int sizeForElemTemp = island.m_iSolverElementTemporaryCount * 4 + 8;
    sizeForElemTemp += numBlocks * 12;
    sizeForElemTemp = (sizeForElemTemp + 15) & ~15;
    taskHeader.m_pIntegerArrayAt40 = buffer;
    buffer += sizeForElemTemp;

    int size = (int)(buffer - (char*)taskHeader.m_buffer);
    taskHeader.m_iBufferSize = size;

    if (taskHeader.m_buffer)
    {
        S883_Accumulator* accum = taskHeader.m_pAccumulatorA;
        accum->setFixed();
        accum[numEntities + 1].m_type = 3;
    }
    return size;
}

extern "C" void _mm_prefetch(char const*, int);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_0126835c;
extern const char str_010d3d70[];
extern const char str_010d3d60[];

// hkMemoryAllocator
struct S88b50_Allocator
{
    virtual void v00();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
    virtual void ReturnMemory(void* p, int numBytes);
    template <typename T> T* _bufAlloc(int& reqNumInOut)
    {
        int n = reqNumInOut;
        void* p = AllocateBufferWithSize(n);
        reqNumInOut = n;
        return static_cast<T*>(p);
    }
    template <typename T> void _bufFree(void* p, int numElem)
    {
        ReturnMemory(p, numElem);
    }
};
struct S88b50_Stack
{
    char* m_pTileTemplate;
    int unk04;
    int unk08;
    void* allocateStack(int numBytes)
    {
        char* current = m_pTileTemplate;
        m_pTileTemplate = current + numBytes;
        return current;
    }
};
struct S88b50_Router
{
    S88b50_Stack m_aiEntries;
    S88b50_Allocator* m_pTemp;
    S88b50_Allocator* m_pStreamAllocator;
    S88b50_Allocator* m_pDebugAllocator;
    S88b50_Allocator* m_pSolver;
    S88b50_Stack& stack()
    {
        return m_aiEntries;
    }
    S88b50_Allocator& temp()
    {
        return *m_pTemp;
    }
    S88b50_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
    S88b50_Allocator& solver()
    {
        return *m_pSolver;
    }
    static S88b50_Router& GetMonitorStream()
    {
        return *(S88b50_Router*)hkMemoryRouter_getInstance();
    }
};
static __forceinline char* S88b50_allocateStack(int n)
{
    S88b50_Router& mem = S88b50_Router::GetMonitorStream();
    return static_cast<char*>(mem.stack().allocateStack((n + 127) & ~127));
}

struct S88b50_ConstraintInternal
{
    S88_Instance* m_pHavokConstraint;
    hkpEntity* m_kActorEntries[2];
    S88_Atom* m_kBridgeAtoms;
    unsigned short m_iAtomsSize;
    unsigned char m_ucCallbackRequest;
    unsigned char m_priority;
    int unk14;
    int unk18;
    void* m_pRuntime;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    S88_Atom* getAtoms() const
    {
        return m_kBridgeAtoms;
    }
    unsigned short getAtomsSize() const
    {
        return m_iAtomsSize;
    }
    int getPriority() const
    {
        return m_priority;
    }
};
struct S88b50_SmallArray
{
    S88b50_ConstraintInternal* m_data;
    unsigned short m_iElementCount;
    unsigned short m_iCapacityState;
    const S88b50_ConstraintInternal* begin() const
    {
        return m_data;
    }
    const S88b50_ConstraintInternal* end() const
    {
        return m_data + m_iElementCount;
    }
};
static inline const S88b50_SmallArray& S88b50_getConstraintMasters(const hkpEntity* entity)
{
    return reinterpret_cast<const S88b50_SmallArray&>(entity->m_eSmallArraySerializeOverrideType);
}

struct S88b50_PtrArray
{
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
// hkpWorld
struct S88b50_World
{
    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_pSimulation;
    int unk0C;
    hkVector4 m_kGravity;
    void* m_pFixedIsland;
    void* m_pFixedRigidBody;
    S88b50_PtrArray m_kActiveSimulationIslands;
    S88b50_PtrArray m_kInactiveSimulationIslands;
    S88b50_PtrArray m_kDirtySimulationIslands;
    void* m_pMaintenanceManager;
    void* m_pMemoryWatchDog;
    char m_bAssertOnRunningOutOfSolverMemory;
    void* m_pJobSemaphore;
    void* m_pKdTreeManager;
    char m_bUseKdTree;
    void* m_pBroadPhaseDispatcher;
    void* m_pPhantomBroadPhaseListener;
    void* m_pEntityEntityBroadPhaseListener;
    void* m_pBroadPhaseBorderListener;
    void* m_pMultithreadedSimulationJobData;
    void* m_pCollisionInput;
    void* getCollisionInput() const
    {
        return m_pCollisionInput;
    }
};
static __forceinline hkpEntity* S88b50_getEntityA(const S88_Instance* i)
{
    return (hkpEntity*)i->unk14;
}
static __forceinline hkpEntity* S88b50_getEntityB(const S88_Instance* i)
{
    return (hkpEntity*)i->unk18;
}

// hkpSimulationIsland
struct S88b50_Island
{
    int unk00;
    int unk04;
    int m_iMaxSchemaSize;
    int m_iSchemaByteSize;
    int m_iSolverResultCount;
    int m_iSolverElementTemporaryCount;
    void* m_pOwningWorld;
};
struct S88b50_InplaceArray
{
    const S88b50_ConstraintInternal** m_data;
    int m_iElementCount;
    int m_iCapacityState;
    const S88b50_ConstraintInternal* m_kStorage[256];
    void init()
    {
        m_data = m_kStorage;
        m_iElementCount = 0;
        m_iCapacityState = 256 | 0x80000000;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    const S88b50_ConstraintInternal*& operator[](int i)
    {
        return m_data[i];
    }
    void AddBack(const S88b50_ConstraintInternal* const& t)
    {
        S88b50_Allocator& alloc = S88b50_Router::GetMonitorStream().heap();
        if (m_iElementCount == getCapacity())
        {
            ResizeAudioStream(*(S88_Allocator*)&alloc, this, sizeof(t));
        }
        m_data[m_iElementCount] = t;
        m_iElementCount++;
    }
    void destroy()
    {
        S88b50_Allocator& alloc = S88b50_Router::GetMonitorStream().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc._bufFree<const S88b50_ConstraintInternal*>(m_data, getCapacity() * 4);
        }
    }
};

struct S88b50_GotoSchema
{
    float m_kHeader;
    long m_offset;
    static void setType(S88b50_GotoSchema* schema, signed char type)
    {
        schema->m_kHeader = (float)(schema->m_kHeader + 1.1920928955078125e-07);
        *(signed char*)S88_addByteOffset(schema, 0) = type;
    }
    void initGoto(S88_Schema* destination)
    {
        m_offset = (char*)destination - (char*)this;
        setType(this, 2);
    }
};

struct S88b50_MonitorStream
{
    int unk00;
    char* m_kRayEnd;
    int unk08;
    char* m_pCurrentCommand;
    static S88b50_MonitorStream& GetMonitorStream()
    {
        return *(S88b50_MonitorStream*)TlsGetValue(DAT_0126835c);
    }
    bool memoryAvailable() const
    {
        return m_kRayEnd < m_pCurrentCommand;
    }
    char* GetStreamEnd()
    {
        return m_kRayEnd;
    }
    void setEnd(char* e)
    {
        m_kRayEnd = e;
    }
};
struct S88b50_AddValueCommand
{
    const char* m_pCommandName;
    float m_uiFilterValue;
};

struct S88b50_BreachedHeader
{
    int m_iBreachCount;
    int unk04;
    int unk08;
    int unk0C;
    void* getElem(int index)
    {
        return (char*)this + 16 + index * 32;
    }
};

template <typename T> inline T S88b50_max2(T x, T y)
{
    return x > y ? x : y;
}

int __cdecl hkSolveConstraints(const void* solverInfo, char* schemas, hkpVelocityAccumulator* accum, char* elemTemps);
void __cdecl hkExportImpulsesAndRhs(const void* solverInfo, char* elemTemps, char* schemas, hkpVelocityAccumulator* accum);
int __cdecl hkRigidMotionUtilApplyAccumulators(const void* solverInfo, const hkStepInfo* stepInfo,
                         const hkpVelocityAccumulator* accums, hkpEntity* const* bodies, int numBodies,
                         int offset);
void __cdecl hkpEntityAabbUtil_entityBatchRecalcAabb(const void* input, hkpEntity* const* bodies, int numBodies);
void __cdecl hkpWorldCallbackUtil_fireContactImpulseLimitBreached(void* world, void* elems, int n);

// hkMatrix3
struct S88b50_Matrix3
{
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
    hkVector4& getColumn(int i)
    {
        return (&m_kColumn0)[i];
    }
    void setZero()
    {
        hkVector4 zero;
        zero.setZero4();
        getColumn(0) = zero;
        getColumn(1) = zero;
        getColumn(2) = zero;
    }
};
static __forceinline void S88b50_setFixed(hkpVelocityAccumulator& a)
{
    a.m_type = 1;
    a.m_fGravityFactor = 0.0f;
    a.m_vInverseInertiaAndMass.setZero4();
    a.m_vLinearVelocity.setZero4();
    a.m_vAngularVelocity.setZero4();
    a.m_vCenterOfMass.setZero4();
    reinterpret_cast<S88b50_Matrix3&>(a.m_scratch1).setZero();
}

static __forceinline void S88b50_buildAccumulators(const hkStepInfo& info, hkpEntity* const* bodies,
                                                   int numBodies, hkpVelocityAccumulator* accumulators)
{
    S88b50_setFixed(*accumulators);
    for (int i = 0; i < numBodies; i++)
    {
        unsigned int newVal = (i + 1) * 128;
        if (newVal != bodies[i]->m_uiFilterInfo)
        {
            bodies[i]->m_uiFilterInfo = newVal;
        }
    }
    hkpVelocityAccumulator* accumEnd =
        hkRigidMotionUtilApplyForcesAndBuildAccumulators(&info, bodies, numBodies, 0xe0, accumulators + 1);
    accumEnd->m_type = 3;
}

template <int SIZE> inline void S88b50_forcePrefetch(const void* p)
{
    const char* q = (const char*)p;
    _mm_prefetch(q, 0);
    if (SIZE > 64)
    {
        _mm_prefetch(q + 64, 0);
    }
    if (SIZE > 128)
    {
        _mm_prefetch(q + 128, 0);
    }
    if (SIZE > 192)
    {
        _mm_prefetch(q + 192, 0);
    }
}

static __forceinline void S88b50_buildJacobianElement(const S88b50_ConstraintInternal* c, S88_QueryIn& in,
                                                      hkpVelocityAccumulator* accusIn, S88_QueryOut& out)
{
    S88b50_forcePrefetch<256>(c->getAtoms());
    if (c->getAtomsSize() > 256)
    {
        S88b50_forcePrefetch<256>(S88_addByteOffset(c->getAtoms(), 256));
        if (c->getAtomsSize() > 512)
        {
            S88b50_forcePrefetch<256>(S88_addByteOffset(c->getAtoms(), 512));
        }
    }
    hkpEntity* rA = c->m_kActorEntries[0];
    hkpEntity* rB = c->m_kActorEntries[1];
    hkpMotion* mA = &rA->m_pMotionState;
    hkpMotion* mB = &rB->m_pMotionState;
    in.m_pBodyA = S88_addByteOffset(accusIn, rA->m_uiFilterInfo);
    in.m_pBodyB = S88_addByteOffset(accusIn, rB->m_uiFilterInfo);
    in.m_kBodyALocalFrame = &mA->m_kMotionState.m_kMotionTransform;
    in.m_kBodyBLocalFrame = &mB->m_kMotionState.m_kMotionTransform;
    in.m_pConstraintChainInstance = c->m_pHavokConstraint;
    in.m_pByteBuffer = c->m_pRuntime;
    in.m_uiParameterA = (unsigned short)(rA->m_uiFilterInfo >> 7);
    in.m_uiParameterB = (unsigned short)(rB->m_uiFilterInfo >> 7);
    in.m_pUserData = in.m_pByteBuffer;
    S88_buildJacobianFromAtoms(c->getAtoms(), c->getAtomsSize(), in, out);
}

static __forceinline void S88b50_buildJacobianElements(S88_QueryIn& in, hkpEntity* const* bodies, int numBodies,
                                                       hkpVelocityAccumulator* accusIn, S88_Schema* schemaOut,
                                                       S88_Schema* schemaOutEnd, S88_Schema* schemaOutB)
{
    S88_QueryOut out;
    out.m_pQueryResultSchema = schemaOut;
    hkpEntity* const* e = bodies;
    hkpEntity* const* eEnd = bodies + numBodies;
    S88b50_InplaceArray criticalConstraints;
    criticalConstraints.init();
    for (; e < eEnd; e++)
    {
        const S88b50_ConstraintInternal* c = S88b50_getConstraintMasters(*e).begin();
        const S88b50_ConstraintInternal* cEnd = S88b50_getConstraintMasters(*e).end();
        for (; c < cEnd; c++)
        {
            if (c->m_ucCallbackRequest & 0xd)
            {
                in.m_pConstraintChainInstance = c->m_pHavokConstraint;
                in.m_pByteBuffer = c->m_pRuntime;
                hkpEntity* rA = S88b50_getEntityA(c->m_pHavokConstraint);
                hkpEntity* rB = S88b50_getEntityB(c->m_pHavokConstraint);
                in.m_pBodyA = S88_addByteOffset(accusIn, rA->m_uiFilterInfo);
                in.m_pBodyB = S88_addByteOffset(accusIn, rB->m_uiFilterInfo);
                in.m_kBodyALocalFrame = &*(const hkTransform*)rA->m_kCollidable.m_pMotionState;
                in.m_kBodyBLocalFrame = &*(const hkTransform*)rB->m_kCollidable.m_pMotionState;
                if (c->m_ucCallbackRequest & 9)
                {
                    S88_ConstraintData* data = c->m_pHavokConstraint->getDataRw();
                    S88_Atom* atom = data->m_pAtom;
                    hkSimpleContactConstraintData_fireCallbacks(data, &in, atom, 2);
                }
                if (c->m_ucCallbackRequest & 4)
                {
                    S88_ConstraintData* data = c->m_pHavokConstraint->getDataRw();
                    data->BuildJacobianCallback(in);
                }
            }
            if (c->getPriority() >= 4)
            {
                criticalConstraints.AddBack(c);
                continue;
            }
            if (out.m_pQueryResultSchema >= schemaOutEnd)
            {
                S88b50_GotoSchema* s = (S88b50_GotoSchema*)out.m_pQueryResultSchema.val();
                s->initGoto(schemaOutB);
                out.m_pQueryResultSchema = schemaOutB;
                schemaOutEnd = (S88_Schema*)-1;
            }
            S88b50_buildJacobianElement(c, in, accusIn, out);
        }
    }
    for (int i = 0; i < criticalConstraints.GetLogicalSize(); i++)
    {
        const S88b50_ConstraintInternal* c = criticalConstraints[i];
        if (out.m_pQueryResultSchema >= schemaOutEnd)
        {
            S88b50_GotoSchema* s = (S88b50_GotoSchema*)out.m_pQueryResultSchema.val();
            s->initGoto(schemaOutB);
            out.m_pQueryResultSchema = schemaOutB;
            schemaOutEnd = (S88_Schema*)-1;
        }
        S88b50_buildJacobianElement(c, in, accusIn, out);
    }
    *(int*)out.m_pQueryResultSchema.val() = 0;
    criticalConstraints.destroy();
}

static __forceinline int S88b50_integrate2(const void* solverInfo, const hkStepInfo& stepInfo,
                                           const hkpVelocityAccumulator* accumulators, hkpEntity* const* bodies,
                                           int numBodies)
{
    int numInactiveFrames = hkRigidMotionUtilApplyAccumulators(solverInfo, &stepInfo, accumulators + 1, bodies, numBodies, 0xe0);
    hkpEntityAabbUtil_entityBatchRecalcAabb(((S88b50_World*)bodies[0]->m_pOwningWorld)->getCollisionInput(), bodies, numBodies);
    return numInactiveFrames;
}

// Allocates solver buffers, builds velocity accumulators and Jacobian schemas, solves the constraint system, and integrates the island bodies.
// @fnv 0x00d88b50
// src: XBOX_PDB 0x00d88b50
int __cdecl hkpConstraintSolverSetup_solve(const hkStepInfo& stepInfo, const void* solverInfo, S88_QueryIn& constraintQueryIn,
                         S88b50_Island& island, void* preallocatedBuffer, int preallocatedBufferSize,
                         hkpEntity* const* bodies, int numBodies)
{
    int result = 0;
    char* scratch2 = 0;
    int scratch2Size = 0;

    int accumulatorSize = numBodies * 128 + 0x90;
    int schemaSize = island.m_iSchemaByteSize + 16;
    int elemTempSize = island.m_iSolverElementTemporaryCount * 4 + 8;
    elemTempSize = (elemTempSize + 15) & ~15;
    char* schemasB = 0;

    int totalSize = accumulatorSize + schemaSize + elemTempSize;
    char* scratch;
    char* buffer;
    char* bufferEnd;
    if (preallocatedBuffer == 0)
    {
        scratch = S88b50_Router::GetMonitorStream().solver()._bufAlloc<char>(totalSize);
        buffer = scratch;
        bufferEnd = buffer + totalSize;
    }
    else
    {
        scratch = 0;
        buffer = (char*)preallocatedBuffer;
        bufferEnd = buffer + preallocatedBufferSize;
    }

    hkpVelocityAccumulator* accumulators;
    char* schemas;
    char* schemasEnd;
    char* elemTemp;
redoAll:
    accumulators = (hkpVelocityAccumulator*)buffer;
    buffer += accumulatorSize;
    schemas = buffer;
    buffer += schemaSize;
    schemasEnd = buffer;
redoElemTemp:
    elemTemp = buffer;
    buffer += elemTempSize;
    if (buffer <= bufferEnd)
    {
        S88b50_buildAccumulators(stepInfo, bodies, numBodies, accumulators);
        for (int i = 0; i < island.m_iSolverElementTemporaryCount; i++)
        {
            ((float*)elemTemp)[i] = 0.0f;
        }
        S88b50_buildJacobianElements(constraintQueryIn, bodies, numBodies, accumulators, (S88_Schema*)schemas,
                                     (S88_Schema*)schemasEnd, (S88_Schema*)schemasB);

        int solveResult = hkSolveConstraints(solverInfo, schemas, accumulators, elemTemp);
        {
            S88b50_MonitorStream& mStream = S88b50_MonitorStream::GetMonitorStream();
            if (mStream.memoryAvailable())
            {
                S88b50_AddValueCommand* h = (S88b50_AddValueCommand*)mStream.GetStreamEnd();
                h->m_pCommandName = str_010d3d70;
                h->m_uiFilterValue = (float)island.m_iSolverResultCount;
                mStream.setEnd((char*)(h + 1));
            }
        }
        {
            S88b50_MonitorStream& mStream = S88b50_MonitorStream::GetMonitorStream();
            if (mStream.memoryAvailable())
            {
                S88b50_AddValueCommand* h = (S88b50_AddValueCommand*)mStream.GetStreamEnd();
                h->m_pCommandName = str_010d3d60;
                h->m_uiFilterValue = (float)numBodies;
                mStream.setEnd((char*)(h + 1));
            }
        }
        if (solveResult == 1)
        {
            hkExportImpulsesAndRhs(solverInfo, elemTemp, schemas, accumulators);
            result = S88b50_integrate2(solverInfo, stepInfo, accumulators, bodies, numBodies);
            S88b50_BreachedHeader* h = (S88b50_BreachedHeader*)schemas;
            if (h->m_iBreachCount != 0)
            {
                hkpWorldCallbackUtil_fireContactImpulseLimitBreached(island.m_pOwningWorld, h->getElem(0), h->m_iBreachCount);
            }
        }
        if (scratch2 != 0)
        {
            S88b50_Router::GetMonitorStream().temp().ReleaseBlock(scratch2, scratch2Size);
        }
        if (scratch != 0)
        {
            S88b50_Router::GetMonitorStream().solver()._bufFree<char>(scratch, totalSize);
        }
        return result;
    }
    else
    {
        if (schemas >= bufferEnd)
        {
            scratch2Size = (int)(buffer - scratch);
            scratch2 = (char*)S88b50_Router::GetMonitorStream().temp().AllocateMemoryBlock(scratch2Size);
            buffer = scratch2;
            bufferEnd = buffer + scratch2Size;
            goto redoAll;
        }
        int minSchemaSize = island.m_iMaxSchemaSize + 16;
        if (schemasEnd >= bufferEnd)
        {
            int freeSchemaSpace = (int)(bufferEnd - schemas - minSchemaSize);
            int maxFree = S88b50_max2(freeSchemaSpace, 0);
            int schemaBSize = island.m_iSchemaByteSize + minSchemaSize - maxFree;
            scratch2Size = elemTempSize + schemaBSize;
            scratch2 = (char*)S88b50_Router::GetMonitorStream().temp().AllocateMemoryBlock(scratch2Size);
            if (freeSchemaSpace < 0)
            {
                buffer = scratch2;
                bufferEnd = buffer + scratch2Size;
                schemas = buffer;
                buffer = buffer + island.m_iSchemaByteSize + 16;
                schemasEnd = buffer;
                schemasB = 0;
            }
            else
            {
                schemasEnd = bufferEnd - minSchemaSize;
                buffer = scratch2;
                bufferEnd = buffer + scratch2Size;
                schemasB = buffer;
                buffer += schemaBSize;
            }
        }
        else
        {
            int size = elemTempSize;
            scratch2 = S88b50_allocateStack(size);
            buffer = scratch2;
            bufferEnd = buffer + size;
        }
        goto redoElemTemp;
    }
}
