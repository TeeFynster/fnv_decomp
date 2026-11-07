#include "../../../../../../include/hkArrayBase.h"
#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ASSIGN   // this unit defines its own hkVector4 assign form

// src/havok/physics/dynamics/world/simulation/hkpsimulation.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/simulation/hkpsimulation.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Preserve the original intrinsic lanes when the shared headers include xmmintrin.h.
#define _INCLUDED_MM2
// Exe 0x00cf8da0 FUN_00cf8da0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) { float m128_f32[4]; unsigned __int64 m128_u64[2]; } __m128, LocalM128;

#include "../../../../../../include/hkMonitorStream.h"
#include "../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../include/MemoryManager.h"
#include "../../../../../../include/hkpWorld.h"
#include "../../../../../../include/hkMonitorStream.h"
#include "../../../../../../include/hkMonitorStream.h"
#include "../../../../../../include/Transform.h"
#include "../../../../../../include/hkMotionState.h"
#include "../../../../../../include/hkpEntity.h"
#include "../../../../../../include/hkpSimulation.h"
#include "../../../../../../include/hkRotation.h"
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkpRootCdPoint.h"
#include "../../../../../../include/hkStepInfo.h"

// Step info (0x1D0) and solver info (0x1E0) occupy the world's reserved region.

inline void hkVector4::operator=(const hkVector4& value) {
    unsigned int* dest = reinterpret_cast<unsigned int*>(this);
    const unsigned int* src = reinterpret_cast<const unsigned int*>(&value);
    dest[0] = src[0]; dest[1] = src[1]; dest[2] = src[2]; dest[3] = src[3];
}

extern "C" void __cdecl hkAgentNnMachine_InvalidateTimInAgent(int, int);

struct FUN_00cf87a0_Class {
    void __thiscall ForwardToGlobal(int a, int b, int c);
};

// @fnv 0x00cf87a0
void __thiscall FUN_00cf87a0_Class::ForwardToGlobal(int aiArg1, int aiArg2, int aiUnused)
{
    hkAgentNnMachine_InvalidateTimInAgent(aiArg1, aiArg2);
}

extern "C" void __cdecl ProcessChildLoop(hkpWorld*);

class SimulationDerived : public hkpSimulation {
public:
    hkUint32 __thiscall hkpSimulation_stepDeltaTime(hkReal dt);
};

// @fnv 0x00cf8730
// src: HAVOK_LIB 0x00cf8730
hkUint32 SimulationDerived::hkpSimulation_stepDeltaTime(hkReal afDeltaTime) {
    if (!m_uiSimulationType || m_uiSimulationType == 1) {
        reinterpret_cast<void (__thiscall **)(hkpSimulation*, hkReal)>(*reinterpret_cast<void***>(this))[4](this, afDeltaTime);
    }
    if (!m_uiSimulationType || m_uiSimulationType == 2) {
        vf05();
    }
    if (!m_uiSimulationType || m_uiSimulationType == 3) {
        vf06();
    }
    if (m_uiSimulationType != 0) {
        if (m_pOwningWorld->hkpWorld_getMemoryWatchDog()) {
            ProcessChildLoop(m_pOwningWorld);
        }
    }
    return m_uiSimulationType;
}

extern "C" {
    __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
    unsigned __int64 __rdtsc(void);
    void _ReadWriteBarrier(void);
    extern int DAT_01269200;
    extern unsigned long DAT_0126835c;
    extern const char str_010c41f8[];
    extern const char str_010cc530[];
    void __cdecl hkpWorldCallbackUtil_firePostCollideCallback(void*, void*);
}

// The original's timer helpers (expansions of Havok's timer macros), kept as members of a unit-local view so the
// inlined code keeps its shape.
struct StringCursor_hkpsimulation : hkMonitorStream
{
    void record(const char* tag, volatile unsigned int& t);
};
__forceinline void StringCursor_hkpsimulation::record(const char* tag, volatile unsigned int& t) {
    char* pos = m_end.m_storage;
    if (pos < m_capacityMinus16.m_storage) {
        *(const char**)pos = tag;
        _ReadWriteBarrier();
        t = (hkUint32)__rdtsc();
        *(hkUint32*)(pos + 4) = t;
        pos += 12;
        m_end.m_storage = pos;
    }
}

static __forceinline void recordTimer(const char* tag, volatile hkUint32& t) {
    hkMonitorStream* stream = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    static_cast<StringCursor_hkpsimulation*>(stream)->record(tag, t);
}

class hkpSimulation_Derived : public hkpSimulation {
public:
    __forceinline void step(hkStepInfo* info) {
        reinterpret_cast<void (__thiscall **)(hkpSimulation*, hkStepInfo*)>(*reinterpret_cast<void***>(this))[13](this, info);
    }

    hkUint32 hkpSimulation_reCollideAfterStepFailure();
};

// @fnv 0x00cf8820
// src: HAVOK_LIB 0x00cf8820
hkUint32 hkpSimulation_Derived::hkpSimulation_reCollideAfterStepFailure()
{
    volatile hkUint32 t;
    m_pOwningWorld->hkpWorld_updateCollisionFilterOnWorld(0, 1);

    hkStepInfo stepInfo;
    if (m_uiSimulationType == 3) {
        stepInfo.set(m_fElapsedSimulationTime, m_fSimulationTime);
    } else {
        stepInfo.set(m_fSimulationTime, m_fSimulationTime + m_fStepDeltaTime);
    }

    step(&stepInfo);

    if (DAT_01269200 == 1) {
        recordTimer(str_010c41f8, t);
        return m_uiSimulationType;
    }

    if (m_uiSimulationType == 2) {
        m_fSimulationTime += m_fStepDeltaTime;
        if (m_pOwningWorld->m_kWorldPostCollideListeners.m_iElementCount != 0) {
            recordTimer(str_010cc530, t);
            hkpWorldCallbackUtil_firePostCollideCallback(m_pOwningWorld, &stepInfo);
            recordTimer(str_010c41f8, t);
        }
        m_bHasStepped = 1;
    }

    m_uiSimulationType = 0;
    return 0;
}

extern "C" void CollectLinearCast();

struct FUN_00cfa400_Obj {
    void __thiscall hkpSimulation_processAgentsOfEntities(int a1, int a2, int a3, void (*callback)(), int a5);
    void __thiscall hkpSimulation_collideEntitiesNarrowPhaseDiscrete(int a1, int a2, int a3, int a4);
};

// Forwards the four arguments to FUN_00cf9480, passing CollectLinearCast as the callback.
// @fnv 0x00cfa400
// src: HAVOK_LIB 0x00cfa400
void __thiscall FUN_00cfa400_Obj::hkpSimulation_collideEntitiesNarrowPhaseDiscrete(int a1, int a2, int a3, int a4) {
    hkpSimulation_processAgentsOfEntities(a1, a2, a3, CollectLinearCast, a4);
}

namespace fnv_00cfa470 {
// Process-input view: the inline step is at +0x50, beyond the 0x50-byte hkpCollisionInput base.
struct CollisionStepContext {
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
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    hkStepInfo m_pStepInfo;
};

void __cdecl hkSweptTransformUtil_backStepMotionState(float time, hkMotionState* ms);
void __cdecl hkRigidMotionUtilStep(const hkStepInfo* stepInfo, hkpEntity** entities, int numEntities, int offset);
void __cdecl hkpEntityAabbUtil_entityBatchRecalcAabb(CollisionStepContext* input, hkpEntity** entities, int numEntities);
void __cdecl hkpSimulation_collideEntitiesBroadPhaseDiscrete(hkpEntity** entities, int numEntities, hkpWorld* world);

class hkpSimulationV : public hkpSimulation {
public:
    __forceinline void collideEntities(hkpEntity** entities, int numEntities, hkpWorld* world, int findExtraContacts) {
        reinterpret_cast<void (__thiscall **)(hkpSimulation*, hkpEntity**, int, hkpWorld*, int)>(*reinterpret_cast<void***>(this))[8](this, entities, numEntities, world, findExtraContacts);
    }

    void hkpSimulation_collideEntitiesNarrowPhaseDiscrete(hkpEntity** entities, int numEntities, CollisionStepContext* input, int flag);
    void ResetSimulationState(hkpEntity** entities, int numEntities, hkpWorld* world, int resetInfo);
};

// @fnv 0x00cfa470
void hkpSimulationV::ResetSimulationState(hkpEntity** entities, int numEntities, hkpWorld* world, int auiResetFlags)
{
    world->m_iCriticalOperationsLockCount++;

    hkStepInfo stepInfo;
    float startTime = world->hkpWorld_getCurrentTime();
    float endTime = world->hkpWorld_getCurrentPsiTime();
    stepInfo.m_uiStartTime = startTime;
    stepInfo.m_fEndTime = endTime;
    stepInfo.m_fTimeStep = endTime - startTime;
    stepInfo.m_fInverseDeltaTime = (stepInfo.m_fTimeStep == 0.0f) ? 0.0f : 1.0f / stepInfo.m_fTimeStep;
    ((CollisionStepContext*)world->m_pCollisionInput)->m_pStepInfo = stepInfo;

    if (auiResetFlags & RESET_TOI)
    {
        for (int i = 0; i < numEntities; i++)
        {
            hkpEntity* entity = entities[i];
            if (*reinterpret_cast<const hkUint8*>(&entity->m_pMotionState.m_type) != 5)
            {
                hkSweptTransformUtil_backStepMotionState(world->hkpWorld_getCurrentTime(), &entity->m_pMotionState.m_kMotionState);
            }
        }
        hkRigidMotionUtilStep(&stepInfo, entities, numEntities, 0xe0);
        hkpEntityAabbUtil_entityBatchRecalcAabb(((CollisionStepContext*)world->m_pCollisionInput), entities, numEntities);
    }

    if (auiResetFlags & RESET_TIM)
    {
        hkpSimulation_collideEntitiesBroadPhaseDiscrete(entities, numEntities, world);
    }

    if (auiResetFlags & RESET_AABB)
    {
        hkpSimulation_collideEntitiesNarrowPhaseDiscrete(entities, numEntities, ((CollisionStepContext*)world->m_pCollisionInput), 0);
    }
    else if (auiResetFlags & RESET_TOI)
    {
        collideEntities(entities, numEntities, world, 2);
    }

    if (--world->m_iCriticalOperationsLockCount == 0 && !world->m_bBlockExecutingPendingOperations)
    {
        if (world->m_iPendingOperationCount)
        {
            world->FUN_00c91120();
        }
        if (world->m_iPendingOperationQueueCount == 1 && world->m_iQueuedOperationCount)
        {
            world->UpdateFields_00c91140();
        }
    }
}
}  // namespace fnv_00cfa470

struct FnvCpu_FUN_00cfa7a0_CpuAllocator {
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();
struct FnvCpu_FUN_00cfa7a0_CpuObject {
    unsigned int unk00;
    unsigned short size;
    void SetVtableAndProcessState_00cf86d0();
    FnvCpu_FUN_00cfa7a0_CpuObject* FUN_00cfa7a0(unsigned int flags);
};
// @fnv 0x00cfa7a0
FnvCpu_FUN_00cfa7a0_CpuObject* FnvCpu_FUN_00cfa7a0_CpuObject::FUN_00cfa7a0(unsigned int flags)
{
    SetVtableAndProcessState_00cf86d0();
    if (flags & 1) {
        hkMemoryRouter* holder = hkMemoryRouter_getInstance();
        ((FnvCpu_FUN_00cfa7a0_CpuAllocator*)holder->m_heap)->Invoke(this, size);
    }
    return this;
}

extern "C" void __cdecl hkpWorldCallbackUtil_firePostSimulationCallback(int);
extern unsigned long DAT_0126835c;
extern void* DAT_00fdf044;
extern const char str_010cc540[];
extern const char str_010c41f8[];
typedef void* (__stdcall *S00cf8a40_TlsFn)(unsigned long);

static __forceinline void timer(hkMonitorStream* stream, const char* name)
{
    if (stream->m_end.m_storage < stream->m_capacityMinus16.m_storage) {
        hkMonitorStream::TimerCommand* c = reinterpret_cast<hkMonitorStream::TimerCommand*>(stream->m_end.m_storage);
        c->m_commandAndMonitor = name;
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        c->m_time0 = t;
        stream->m_end.m_storage = reinterpret_cast<char*>(c + 1);
    }
}

struct S00cf8a40_Obj {
    int unk00;
    int unk04;
    int unk08;
    hkpWorld* m_node;
    int unk10;
    float m_uiCommandId;
    int unk18;
    int unk1c;
    float m_pFreeList;
    int unk24;
    int m_uiContentCount;

    float GetClampedSimulationTime();
    int hkpSimulation_advanceTime();
};

// @fnv 0x00cf8a40
// src: HAVOK_LIB 0x00cf8a40
int S00cf8a40_Obj::hkpSimulation_advanceTime()
{
    m_uiCommandId = GetClampedSimulationTime();
    if (m_uiCommandId >= m_pFreeList && m_node->m_kWorldPostSimulationListeners.m_iElementCount) {
        S00cf8a40_TlsFn pTlsFn = (S00cf8a40_TlsFn)DAT_00fdf044;
        hkMonitorStream* s = (hkMonitorStream*)pTlsFn(DAT_0126835c);
        timer(s, str_010cc540);
        hkpWorldCallbackUtil_firePostSimulationCallback((int)m_node);
        s = (hkMonitorStream*)pTlsFn(DAT_0126835c);
        timer(s, str_010c41f8);
    }
    m_uiContentCount = 0;
    return 0;
}

// Contact-output view: 256 records at +0x10 and a cursor at +0x00; hkpCdPointCollector is a virtual 8-byte base.
struct ContactBufferState {
    hkpRootCdPoint* m_data;
    int unk0004;
    int unk0008;
    int unk000C;
    hkpRootCdPoint m_kStorage[256];
    int unk3010, unk3014, unk3018, unk301C, unk3020, unk3024, unk3028, unk302C;
    float m_fEarlyOutDistance;
    int unk3034, unk3038, unk303C, unk3040, unk3044, unk3048, unk304C, unk3050, unk3054, unk3058, unk305C, unk3060;
    int unk3064, unk3068, unk306C, unk3070, unk3074, unk3078, unk307C;
    int m_hitCount;
};

// Dispatcher table record: 0x40-byte stride in CollectLinearCast, versus the 4-byte hkpAgentEntry header.
struct DispatcherFunctionRecord {
    void* m_pCreateFunc;
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    int m_aiContactPointIds[4];
};

// Dispatcher view: CollectLinearCast indexes its 0x40-byte function records at +0x1C30.
struct CollisionDispatchRegistry {
    int unk0000, unk0004, unk0008, unk000C, unk0010, unk0014, unk0018, unk001C, unk0020, unk0024, unk0028, unk002C;
    int unk0030, unk0034, unk0038, unk003C, unk0040, unk0044, unk0048, unk004C, unk0050, unk0054, unk0058, unk005C;
    int unk0060, unk0064, unk0068, unk006C, unk0070, unk0074, unk0078, unk007C, unk0080, unk0084, unk0088, unk008C;
    int unk0090, unk0094, unk0098, unk009C, unk00A0, unk00A4, unk00A8, unk00AC, unk00B0, unk00B4, unk00B8, unk00BC;
    int unk00C0, unk00C4, unk00C8, unk00CC, unk00D0, unk00D4, unk00D8, unk00DC, unk00E0, unk00E4, unk00E8, unk00EC;
    int unk00F0, unk00F4, unk00F8, unk00FC, unk0100, unk0104, unk0108, unk010C, unk0110, unk0114, unk0118, unk011C;
    int unk0120, unk0124, unk0128, unk012C, unk0130, unk0134, unk0138, unk013C, unk0140, unk0144, unk0148, unk014C;
    int unk0150, unk0154, unk0158, unk015C, unk0160, unk0164, unk0168, unk016C, unk0170, unk0174, unk0178, unk017C;
    int unk0180, unk0184, unk0188, unk018C, unk0190, unk0194, unk0198, unk019C, unk01A0, unk01A4, unk01A8, unk01AC;
    int unk01B0, unk01B4, unk01B8, unk01BC, unk01C0, unk01C4, unk01C8, unk01CC, unk01D0, unk01D4, unk01D8, unk01DC;
    int unk01E0, unk01E4, unk01E8, unk01EC, unk01F0, unk01F4, unk01F8, unk01FC, unk0200, unk0204, unk0208, unk020C;
    int unk0210, unk0214, unk0218, unk021C, unk0220, unk0224, unk0228, unk022C, unk0230, unk0234, unk0238, unk023C;
    int unk0240, unk0244, unk0248, unk024C, unk0250, unk0254, unk0258, unk025C, unk0260, unk0264, unk0268, unk026C;
    int unk0270, unk0274, unk0278, unk027C, unk0280, unk0284, unk0288, unk028C, unk0290, unk0294, unk0298, unk029C;
    int unk02A0, unk02A4, unk02A8, unk02AC, unk02B0, unk02B4, unk02B8, unk02BC, unk02C0, unk02C4, unk02C8, unk02CC;
    int unk02D0, unk02D4, unk02D8, unk02DC, unk02E0, unk02E4, unk02E8, unk02EC, unk02F0, unk02F4, unk02F8, unk02FC;
    int unk0300, unk0304, unk0308, unk030C, unk0310, unk0314, unk0318, unk031C, unk0320, unk0324, unk0328, unk032C;
    int unk0330, unk0334, unk0338, unk033C, unk0340, unk0344, unk0348, unk034C, unk0350, unk0354, unk0358, unk035C;
    int unk0360, unk0364, unk0368, unk036C, unk0370, unk0374, unk0378, unk037C, unk0380, unk0384, unk0388, unk038C;
    int unk0390, unk0394, unk0398, unk039C, unk03A0, unk03A4, unk03A8, unk03AC, unk03B0, unk03B4, unk03B8, unk03BC;
    int unk03C0, unk03C4, unk03C8, unk03CC, unk03D0, unk03D4, unk03D8, unk03DC, unk03E0, unk03E4, unk03E8, unk03EC;
    int unk03F0, unk03F4, unk03F8, unk03FC, unk0400, unk0404, unk0408, unk040C, unk0410, unk0414, unk0418, unk041C;
    int unk0420, unk0424, unk0428, unk042C, unk0430, unk0434, unk0438, unk043C, unk0440, unk0444, unk0448, unk044C;
    int unk0450, unk0454, unk0458, unk045C, unk0460, unk0464, unk0468, unk046C, unk0470, unk0474, unk0478, unk047C;
    int unk0480, unk0484, unk0488, unk048C, unk0490, unk0494, unk0498, unk049C, unk04A0, unk04A4, unk04A8, unk04AC;
    int unk04B0, unk04B4, unk04B8, unk04BC, unk04C0, unk04C4, unk04C8, unk04CC, unk04D0, unk04D4, unk04D8, unk04DC;
    int unk04E0, unk04E4, unk04E8, unk04EC, unk04F0, unk04F4, unk04F8, unk04FC, unk0500, unk0504, unk0508, unk050C;
    int unk0510, unk0514, unk0518, unk051C, unk0520, unk0524, unk0528, unk052C, unk0530, unk0534, unk0538, unk053C;
    int unk0540, unk0544, unk0548, unk054C, unk0550, unk0554, unk0558, unk055C, unk0560, unk0564, unk0568, unk056C;
    int unk0570, unk0574, unk0578, unk057C, unk0580, unk0584, unk0588, unk058C, unk0590, unk0594, unk0598, unk059C;
    int unk05A0, unk05A4, unk05A8, unk05AC, unk05B0, unk05B4, unk05B8, unk05BC, unk05C0, unk05C4, unk05C8, unk05CC;
    int unk05D0, unk05D4, unk05D8, unk05DC, unk05E0, unk05E4, unk05E8, unk05EC, unk05F0, unk05F4, unk05F8, unk05FC;
    int unk0600, unk0604, unk0608, unk060C, unk0610, unk0614, unk0618, unk061C, unk0620, unk0624, unk0628, unk062C;
    int unk0630, unk0634, unk0638, unk063C, unk0640, unk0644, unk0648, unk064C, unk0650, unk0654, unk0658, unk065C;
    int unk0660, unk0664, unk0668, unk066C, unk0670, unk0674, unk0678, unk067C, unk0680, unk0684, unk0688, unk068C;
    int unk0690, unk0694, unk0698, unk069C, unk06A0, unk06A4, unk06A8, unk06AC, unk06B0, unk06B4, unk06B8, unk06BC;
    int unk06C0, unk06C4, unk06C8, unk06CC, unk06D0, unk06D4, unk06D8, unk06DC, unk06E0, unk06E4, unk06E8, unk06EC;
    int unk06F0, unk06F4, unk06F8, unk06FC, unk0700, unk0704, unk0708, unk070C, unk0710, unk0714, unk0718, unk071C;
    int unk0720, unk0724, unk0728, unk072C, unk0730, unk0734, unk0738, unk073C, unk0740, unk0744, unk0748, unk074C;
    int unk0750, unk0754, unk0758, unk075C, unk0760, unk0764, unk0768, unk076C, unk0770, unk0774, unk0778, unk077C;
    int unk0780, unk0784, unk0788, unk078C, unk0790, unk0794, unk0798, unk079C, unk07A0, unk07A4, unk07A8, unk07AC;
    int unk07B0, unk07B4, unk07B8, unk07BC, unk07C0, unk07C4, unk07C8, unk07CC, unk07D0, unk07D4, unk07D8, unk07DC;
    int unk07E0, unk07E4, unk07E8, unk07EC, unk07F0, unk07F4, unk07F8, unk07FC, unk0800, unk0804, unk0808, unk080C;
    int unk0810, unk0814, unk0818, unk081C, unk0820, unk0824, unk0828, unk082C, unk0830, unk0834, unk0838, unk083C;
    int unk0840, unk0844, unk0848, unk084C, unk0850, unk0854, unk0858, unk085C, unk0860, unk0864, unk0868, unk086C;
    int unk0870, unk0874, unk0878, unk087C, unk0880, unk0884, unk0888, unk088C, unk0890, unk0894, unk0898, unk089C;
    int unk08A0, unk08A4, unk08A8, unk08AC, unk08B0, unk08B4, unk08B8, unk08BC, unk08C0, unk08C4, unk08C8, unk08CC;
    int unk08D0, unk08D4, unk08D8, unk08DC, unk08E0, unk08E4, unk08E8, unk08EC, unk08F0, unk08F4, unk08F8, unk08FC;
    int unk0900, unk0904, unk0908, unk090C, unk0910, unk0914, unk0918, unk091C, unk0920, unk0924, unk0928, unk092C;
    int unk0930, unk0934, unk0938, unk093C, unk0940, unk0944, unk0948, unk094C, unk0950, unk0954, unk0958, unk095C;
    int unk0960, unk0964, unk0968, unk096C, unk0970, unk0974, unk0978, unk097C, unk0980, unk0984, unk0988, unk098C;
    int unk0990, unk0994, unk0998, unk099C, unk09A0, unk09A4, unk09A8, unk09AC, unk09B0, unk09B4, unk09B8, unk09BC;
    int unk09C0, unk09C4, unk09C8, unk09CC, unk09D0, unk09D4, unk09D8, unk09DC, unk09E0, unk09E4, unk09E8, unk09EC;
    int unk09F0, unk09F4, unk09F8, unk09FC, unk0A00, unk0A04, unk0A08, unk0A0C, unk0A10, unk0A14, unk0A18, unk0A1C;
    int unk0A20, unk0A24, unk0A28, unk0A2C, unk0A30, unk0A34, unk0A38, unk0A3C, unk0A40, unk0A44, unk0A48, unk0A4C;
    int unk0A50, unk0A54, unk0A58, unk0A5C, unk0A60, unk0A64, unk0A68, unk0A6C, unk0A70, unk0A74, unk0A78, unk0A7C;
    int unk0A80, unk0A84, unk0A88, unk0A8C, unk0A90, unk0A94, unk0A98, unk0A9C, unk0AA0, unk0AA4, unk0AA8, unk0AAC;
    int unk0AB0, unk0AB4, unk0AB8, unk0ABC, unk0AC0, unk0AC4, unk0AC8, unk0ACC, unk0AD0, unk0AD4, unk0AD8, unk0ADC;
    int unk0AE0, unk0AE4, unk0AE8, unk0AEC, unk0AF0, unk0AF4, unk0AF8, unk0AFC, unk0B00, unk0B04, unk0B08, unk0B0C;
    int unk0B10, unk0B14, unk0B18, unk0B1C, unk0B20, unk0B24, unk0B28, unk0B2C, unk0B30, unk0B34, unk0B38, unk0B3C;
    int unk0B40, unk0B44, unk0B48, unk0B4C, unk0B50, unk0B54, unk0B58, unk0B5C, unk0B60, unk0B64, unk0B68, unk0B6C;
    int unk0B70, unk0B74, unk0B78, unk0B7C, unk0B80, unk0B84, unk0B88, unk0B8C, unk0B90, unk0B94, unk0B98, unk0B9C;
    int unk0BA0, unk0BA4, unk0BA8, unk0BAC, unk0BB0, unk0BB4, unk0BB8, unk0BBC, unk0BC0, unk0BC4, unk0BC8, unk0BCC;
    int unk0BD0, unk0BD4, unk0BD8, unk0BDC, unk0BE0, unk0BE4, unk0BE8, unk0BEC, unk0BF0, unk0BF4, unk0BF8, unk0BFC;
    int unk0C00, unk0C04, unk0C08, unk0C0C, unk0C10, unk0C14, unk0C18, unk0C1C, unk0C20, unk0C24, unk0C28, unk0C2C;
    int unk0C30, unk0C34, unk0C38, unk0C3C, unk0C40, unk0C44, unk0C48, unk0C4C, unk0C50, unk0C54, unk0C58, unk0C5C;
    int unk0C60, unk0C64, unk0C68, unk0C6C, unk0C70, unk0C74, unk0C78, unk0C7C, unk0C80, unk0C84, unk0C88, unk0C8C;
    int unk0C90, unk0C94, unk0C98, unk0C9C, unk0CA0, unk0CA4, unk0CA8, unk0CAC, unk0CB0, unk0CB4, unk0CB8, unk0CBC;
    int unk0CC0, unk0CC4, unk0CC8, unk0CCC, unk0CD0, unk0CD4, unk0CD8, unk0CDC, unk0CE0, unk0CE4, unk0CE8, unk0CEC;
    int unk0CF0, unk0CF4, unk0CF8, unk0CFC, unk0D00, unk0D04, unk0D08, unk0D0C, unk0D10, unk0D14, unk0D18, unk0D1C;
    int unk0D20, unk0D24, unk0D28, unk0D2C, unk0D30, unk0D34, unk0D38, unk0D3C, unk0D40, unk0D44, unk0D48, unk0D4C;
    int unk0D50, unk0D54, unk0D58, unk0D5C, unk0D60, unk0D64, unk0D68, unk0D6C, unk0D70, unk0D74, unk0D78, unk0D7C;
    int unk0D80, unk0D84, unk0D88, unk0D8C, unk0D90, unk0D94, unk0D98, unk0D9C, unk0DA0, unk0DA4, unk0DA8, unk0DAC;
    int unk0DB0, unk0DB4, unk0DB8, unk0DBC, unk0DC0, unk0DC4, unk0DC8, unk0DCC, unk0DD0, unk0DD4, unk0DD8, unk0DDC;
    int unk0DE0, unk0DE4, unk0DE8, unk0DEC, unk0DF0, unk0DF4, unk0DF8, unk0DFC, unk0E00, unk0E04, unk0E08, unk0E0C;
    int unk0E10, unk0E14, unk0E18, unk0E1C, unk0E20, unk0E24, unk0E28, unk0E2C, unk0E30, unk0E34, unk0E38, unk0E3C;
    int unk0E40, unk0E44, unk0E48, unk0E4C, unk0E50, unk0E54, unk0E58, unk0E5C, unk0E60, unk0E64, unk0E68, unk0E6C;
    int unk0E70, unk0E74, unk0E78, unk0E7C, unk0E80, unk0E84, unk0E88, unk0E8C, unk0E90, unk0E94, unk0E98, unk0E9C;
    int unk0EA0, unk0EA4, unk0EA8, unk0EAC, unk0EB0, unk0EB4, unk0EB8, unk0EBC, unk0EC0, unk0EC4, unk0EC8, unk0ECC;
    int unk0ED0, unk0ED4, unk0ED8, unk0EDC, unk0EE0, unk0EE4, unk0EE8, unk0EEC, unk0EF0, unk0EF4, unk0EF8, unk0EFC;
    int unk0F00, unk0F04, unk0F08, unk0F0C, unk0F10, unk0F14, unk0F18, unk0F1C, unk0F20, unk0F24, unk0F28, unk0F2C;
    int unk0F30, unk0F34, unk0F38, unk0F3C, unk0F40, unk0F44, unk0F48, unk0F4C, unk0F50, unk0F54, unk0F58, unk0F5C;
    int unk0F60, unk0F64, unk0F68, unk0F6C, unk0F70, unk0F74, unk0F78, unk0F7C, unk0F80, unk0F84, unk0F88, unk0F8C;
    int unk0F90, unk0F94, unk0F98, unk0F9C, unk0FA0, unk0FA4, unk0FA8, unk0FAC, unk0FB0, unk0FB4, unk0FB8, unk0FBC;
    int unk0FC0, unk0FC4, unk0FC8, unk0FCC, unk0FD0, unk0FD4, unk0FD8, unk0FDC, unk0FE0, unk0FE4, unk0FE8, unk0FEC;
    int unk0FF0, unk0FF4, unk0FF8, unk0FFC, unk1000, unk1004, unk1008, unk100C, unk1010, unk1014, unk1018, unk101C;
    int unk1020, unk1024, unk1028, unk102C, unk1030, unk1034, unk1038, unk103C, unk1040, unk1044, unk1048, unk104C;
    int unk1050, unk1054, unk1058, unk105C, unk1060, unk1064, unk1068, unk106C, unk1070, unk1074, unk1078, unk107C;
    int unk1080, unk1084, unk1088, unk108C, unk1090, unk1094, unk1098, unk109C, unk10A0, unk10A4, unk10A8, unk10AC;
    int unk10B0, unk10B4, unk10B8, unk10BC, unk10C0, unk10C4, unk10C8, unk10CC, unk10D0, unk10D4, unk10D8, unk10DC;
    int unk10E0, unk10E4, unk10E8, unk10EC, unk10F0, unk10F4, unk10F8, unk10FC, unk1100, unk1104, unk1108, unk110C;
    int unk1110, unk1114, unk1118, unk111C, unk1120, unk1124, unk1128, unk112C, unk1130, unk1134, unk1138, unk113C;
    int unk1140, unk1144, unk1148, unk114C, unk1150, unk1154, unk1158, unk115C, unk1160, unk1164, unk1168, unk116C;
    int unk1170, unk1174, unk1178, unk117C, unk1180, unk1184, unk1188, unk118C, unk1190, unk1194, unk1198, unk119C;
    int unk11A0, unk11A4, unk11A8, unk11AC, unk11B0, unk11B4, unk11B8, unk11BC, unk11C0, unk11C4, unk11C8, unk11CC;
    int unk11D0, unk11D4, unk11D8, unk11DC, unk11E0, unk11E4, unk11E8, unk11EC, unk11F0, unk11F4, unk11F8, unk11FC;
    int unk1200, unk1204, unk1208, unk120C, unk1210, unk1214, unk1218, unk121C, unk1220, unk1224, unk1228, unk122C;
    int unk1230, unk1234, unk1238, unk123C, unk1240, unk1244, unk1248, unk124C, unk1250, unk1254, unk1258, unk125C;
    int unk1260, unk1264, unk1268, unk126C, unk1270, unk1274, unk1278, unk127C, unk1280, unk1284, unk1288, unk128C;
    int unk1290, unk1294, unk1298, unk129C, unk12A0, unk12A4, unk12A8, unk12AC, unk12B0, unk12B4, unk12B8, unk12BC;
    int unk12C0, unk12C4, unk12C8, unk12CC, unk12D0, unk12D4, unk12D8, unk12DC, unk12E0, unk12E4, unk12E8, unk12EC;
    int unk12F0, unk12F4, unk12F8, unk12FC, unk1300, unk1304, unk1308, unk130C, unk1310, unk1314, unk1318, unk131C;
    int unk1320, unk1324, unk1328, unk132C, unk1330, unk1334, unk1338, unk133C, unk1340, unk1344, unk1348, unk134C;
    int unk1350, unk1354, unk1358, unk135C, unk1360, unk1364, unk1368, unk136C, unk1370, unk1374, unk1378, unk137C;
    int unk1380, unk1384, unk1388, unk138C, unk1390, unk1394, unk1398, unk139C, unk13A0, unk13A4, unk13A8, unk13AC;
    int unk13B0, unk13B4, unk13B8, unk13BC, unk13C0, unk13C4, unk13C8, unk13CC, unk13D0, unk13D4, unk13D8, unk13DC;
    int unk13E0, unk13E4, unk13E8, unk13EC, unk13F0, unk13F4, unk13F8, unk13FC, unk1400, unk1404, unk1408, unk140C;
    int unk1410, unk1414, unk1418, unk141C, unk1420, unk1424, unk1428, unk142C, unk1430, unk1434, unk1438, unk143C;
    int unk1440, unk1444, unk1448, unk144C, unk1450, unk1454, unk1458, unk145C, unk1460, unk1464, unk1468, unk146C;
    int unk1470, unk1474, unk1478, unk147C, unk1480, unk1484, unk1488, unk148C, unk1490, unk1494, unk1498, unk149C;
    int unk14A0, unk14A4, unk14A8, unk14AC, unk14B0, unk14B4, unk14B8, unk14BC, unk14C0, unk14C4, unk14C8, unk14CC;
    int unk14D0, unk14D4, unk14D8, unk14DC, unk14E0, unk14E4, unk14E8, unk14EC, unk14F0, unk14F4, unk14F8, unk14FC;
    int unk1500, unk1504, unk1508, unk150C, unk1510, unk1514, unk1518, unk151C, unk1520, unk1524, unk1528, unk152C;
    int unk1530, unk1534, unk1538, unk153C, unk1540, unk1544, unk1548, unk154C, unk1550, unk1554, unk1558, unk155C;
    int unk1560, unk1564, unk1568, unk156C, unk1570, unk1574, unk1578, unk157C, unk1580, unk1584, unk1588, unk158C;
    int unk1590, unk1594, unk1598, unk159C, unk15A0, unk15A4, unk15A8, unk15AC, unk15B0, unk15B4, unk15B8, unk15BC;
    int unk15C0, unk15C4, unk15C8, unk15CC, unk15D0, unk15D4, unk15D8, unk15DC, unk15E0, unk15E4, unk15E8, unk15EC;
    int unk15F0, unk15F4, unk15F8, unk15FC, unk1600, unk1604, unk1608, unk160C, unk1610, unk1614, unk1618, unk161C;
    int unk1620, unk1624, unk1628, unk162C, unk1630, unk1634, unk1638, unk163C, unk1640, unk1644, unk1648, unk164C;
    int unk1650, unk1654, unk1658, unk165C, unk1660, unk1664, unk1668, unk166C, unk1670, unk1674, unk1678, unk167C;
    int unk1680, unk1684, unk1688, unk168C, unk1690, unk1694, unk1698, unk169C, unk16A0, unk16A4, unk16A8, unk16AC;
    int unk16B0, unk16B4, unk16B8, unk16BC, unk16C0, unk16C4, unk16C8, unk16CC, unk16D0, unk16D4, unk16D8, unk16DC;
    int unk16E0, unk16E4, unk16E8, unk16EC, unk16F0, unk16F4, unk16F8, unk16FC, unk1700, unk1704, unk1708, unk170C;
    int unk1710, unk1714, unk1718, unk171C, unk1720, unk1724, unk1728, unk172C, unk1730, unk1734, unk1738, unk173C;
    int unk1740, unk1744, unk1748, unk174C, unk1750, unk1754, unk1758, unk175C, unk1760, unk1764, unk1768, unk176C;
    int unk1770, unk1774, unk1778, unk177C, unk1780, unk1784, unk1788, unk178C, unk1790, unk1794, unk1798, unk179C;
    int unk17A0, unk17A4, unk17A8, unk17AC, unk17B0, unk17B4, unk17B8, unk17BC, unk17C0, unk17C4, unk17C8, unk17CC;
    int unk17D0, unk17D4, unk17D8, unk17DC, unk17E0, unk17E4, unk17E8, unk17EC, unk17F0, unk17F4, unk17F8, unk17FC;
    int unk1800, unk1804, unk1808, unk180C, unk1810, unk1814, unk1818, unk181C, unk1820, unk1824, unk1828, unk182C;
    int unk1830, unk1834, unk1838, unk183C, unk1840, unk1844, unk1848, unk184C, unk1850, unk1854, unk1858, unk185C;
    int unk1860, unk1864, unk1868, unk186C, unk1870, unk1874, unk1878, unk187C, unk1880, unk1884, unk1888, unk188C;
    int unk1890, unk1894, unk1898, unk189C, unk18A0, unk18A4, unk18A8, unk18AC, unk18B0, unk18B4, unk18B8, unk18BC;
    int unk18C0, unk18C4, unk18C8, unk18CC, unk18D0, unk18D4, unk18D8, unk18DC, unk18E0, unk18E4, unk18E8, unk18EC;
    int unk18F0, unk18F4, unk18F8, unk18FC, unk1900, unk1904, unk1908, unk190C, unk1910, unk1914, unk1918, unk191C;
    int unk1920, unk1924, unk1928, unk192C, unk1930, unk1934, unk1938, unk193C, unk1940, unk1944, unk1948, unk194C;
    int unk1950, unk1954, unk1958, unk195C, unk1960, unk1964, unk1968, unk196C, unk1970, unk1974, unk1978, unk197C;
    int unk1980, unk1984, unk1988, unk198C, unk1990, unk1994, unk1998, unk199C, unk19A0, unk19A4, unk19A8, unk19AC;
    int unk19B0, unk19B4, unk19B8, unk19BC, unk19C0, unk19C4, unk19C8, unk19CC, unk19D0, unk19D4, unk19D8, unk19DC;
    int unk19E0, unk19E4, unk19E8, unk19EC, unk19F0, unk19F4, unk19F8, unk19FC, unk1A00, unk1A04, unk1A08, unk1A0C;
    int unk1A10, unk1A14, unk1A18, unk1A1C, unk1A20, unk1A24, unk1A28, unk1A2C, unk1A30, unk1A34, unk1A38, unk1A3C;
    int unk1A40, unk1A44, unk1A48, unk1A4C, unk1A50, unk1A54, unk1A58, unk1A5C, unk1A60, unk1A64, unk1A68, unk1A6C;
    int unk1A70, unk1A74, unk1A78, unk1A7C, unk1A80, unk1A84, unk1A88, unk1A8C, unk1A90, unk1A94, unk1A98, unk1A9C;
    int unk1AA0, unk1AA4, unk1AA8, unk1AAC, unk1AB0, unk1AB4, unk1AB8, unk1ABC, unk1AC0, unk1AC4, unk1AC8, unk1ACC;
    int unk1AD0, unk1AD4, unk1AD8, unk1ADC, unk1AE0, unk1AE4, unk1AE8, unk1AEC, unk1AF0, unk1AF4, unk1AF8, unk1AFC;
    int unk1B00, unk1B04, unk1B08, unk1B0C, unk1B10, unk1B14, unk1B18, unk1B1C, unk1B20, unk1B24, unk1B28, unk1B2C;
    int unk1B30, unk1B34, unk1B38, unk1B3C, unk1B40, unk1B44, unk1B48, unk1B4C, unk1B50, unk1B54, unk1B58, unk1B5C;
    int unk1B60, unk1B64, unk1B68, unk1B6C, unk1B70, unk1B74, unk1B78, unk1B7C, unk1B80, unk1B84, unk1B88, unk1B8C;
    int unk1B90, unk1B94, unk1B98, unk1B9C, unk1BA0, unk1BA4, unk1BA8, unk1BAC, unk1BB0, unk1BB4, unk1BB8, unk1BBC;
    int unk1BC0, unk1BC4, unk1BC8, unk1BCC, unk1BD0, unk1BD4, unk1BD8, unk1BDC, unk1BE0, unk1BE4, unk1BE8, unk1BEC;
    int unk1BF0, unk1BF4, unk1BF8, unk1BFC, unk1C00, unk1C04, unk1C08, unk1C0C, unk1C10, unk1C14, unk1C18, unk1C1C;
    int unk1C20, unk1C24, unk1C28, unk1C2C;
    DispatcherFunctionRecord m_pAgents[1];
};

// Process-input view: CollectLinearCast writes +0x60, beyond the 0x50-byte hkpCollisionInput base.
struct ContactProcessingContext {
    CollisionDispatchRegistry* m_pCollisionDispatcher;
    int unk04, unk08, unk0C, unk10;
    void* m_pCreateFunc;
    int unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int* m_aiContactPointIds;
};

// Contact-manager dispatch from pair +0x08: virtual slot +0x18 takes both bodies, process input and output.
class ContactManagerDispatch {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void getPenetrations(void* bodyA, void* bodyB, ContactProcessingContext* input, ContactBufferState* collector);
};

// Pair-entry view: manager +0x08, agent type +0x0C and bodies +0x10/+0x14 match the 24-byte hkpAgentNnEntry, not the 32-byte cast input.
struct CollisionPairEntry {
    int unk00;
    int unk04;
    ContactManagerDispatch* m_pCollisionAgent;
    signed char m_iType;
    void* m_pBodyA;
    void* m_pBodyB;
};

extern float DAT_0104da48;
extern int DAT_01269200;

void __cdecl hkAgentNnMachine_ProcessAgent(CollisionPairEntry* in, ContactProcessingContext* input, ContactBufferState* collector, ContactManagerDispatch* agent);

// @fnv 0x00cf92c0
void __stdcall CollectLinearCast(CollisionPairEntry* apLinearCastInput, ContactProcessingContext* input, ContactBufferState* collector)
{
    collector->m_fEarlyOutDistance = DAT_0104da48;
    collector->m_hitCount = 0;
    collector->m_data = collector->m_kStorage;
    CollisionDispatchRegistry* dispatcher = input->m_pCollisionDispatcher;
    input->m_aiContactPointIds = dispatcher->m_pAgents[0].m_aiContactPointIds;
    input->m_pCreateFunc = dispatcher->m_pAgents[apLinearCastInput->m_iType].m_pCreateFunc;
    hkAgentNnMachine_ProcessAgent(apLinearCastInput, input, collector, apLinearCastInput->m_pCollisionAgent);
    if (DAT_01269200 != 1 && collector->m_data != collector->m_kStorage) {
        apLinearCastInput->m_pCollisionAgent->getPenetrations(apLinearCastInput->m_pBodyA, apLinearCastInput->m_pBodyB, input, collector);
    }
}

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_0126835c;

struct SimCollisionInput {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c;
    hkStepInfo m_pStepInfo;
};

struct SimMaintenanceMgr {
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void PerformMaintenance(hkpWorld* world, hkStepInfo& stepInfo);
};

static inline hkMonitorStream& GetMonStream() {
    return *(hkMonitorStream*)TlsGetValue(DAT_0126835c);
}

struct SimLocal : hkpSimulation {
    int hkpSimulation_integrateInternal(const hkStepInfo& stepInfo);
    int hkpSimulation_integrate(float physicsDeltaTime);
};

// @fnv 0x00cf9340
// src: HAVOK_LIB 0x00cf9340
int SimLocal::hkpSimulation_integrate(float physicsDeltaTime)
{
    volatile unsigned int t;
    hkMonitorStream& monStream = GetMonStream();
    hkMonitorStream::TimerCommand* h = (hkMonitorStream::TimerCommand*)monStream.m_end.m_storage;
    if ((char*)h < monStream.m_capacityMinus16.m_storage) {
        h->m_commandAndMonitor = "TtPhysics";
        _ReadWriteBarrier();
        t = (unsigned int)__rdtsc();
        h->m_time0 = t;
        monStream.m_end.m_storage = (char*)(h + 1);
    }

    m_fStepDeltaTime = physicsDeltaTime;
    hkStepInfo physicsStepInfo(m_fSimulationTime, m_fSimulationTime + m_fStepDeltaTime);

    *(hkStepInfo*)(m_pOwningWorld->pad1C8 + 0x8) = physicsStepInfo;
    ((SimCollisionInput*)m_pOwningWorld->m_pCollisionInput)->m_pStepInfo = physicsStepInfo;
    ((SimMaintenanceMgr*)m_pOwningWorld->m_pMaintenanceManager)->PerformMaintenance(m_pOwningWorld, physicsStepInfo);

    int result = hkpSimulation_integrateInternal(physicsStepInfo);
    m_uiSimulationType = result;
    if (result == 0) {
        m_bHasStepped = (hkUint8)result;
    }

    hkMonitorStream& monStream2 = GetMonStream();
    hkMonitorStream::TimerCommand* pTimerCmd2 = (hkMonitorStream::TimerCommand*)monStream2.m_end.m_storage;
    if ((char*)pTimerCmd2 < monStream2.m_capacityMinus16.m_storage) {
        pTimerCmd2->m_commandAndMonitor = "Et";
        _ReadWriteBarrier();
        t = (unsigned int)__rdtsc();
        pTimerCmd2->m_time0 = t;
        monStream2.m_end.m_storage = (char*)(pTimerCmd2 + 1);
    }

    return result;
}

extern "C" void ForwardToGlobal();
extern "C" void __cdecl InitArrayEntries(void* a, void* b);

struct MyObj : FUN_00cfa400_Obj {
    void hkpSimulation_resetCollisionInformationForEntities(void* first, void* second, hkpWorld* data, unsigned char flags);
};

// If flags & 2, forwards the world collision input; if flags & 4, calls InitArrayEntries(first, second).
// @fnv 0x00cfa430
// src: HAVOK_LIB 0x00cfa430
void MyObj::hkpSimulation_resetCollisionInformationForEntities(void* first, void* second, hkpWorld* data, unsigned char flags) {
    if (flags & 2) {
        hkpSimulation_processAgentsOfEntities((int)first, (int)second, (int)data->m_pCollisionInput, ForwardToGlobal, 0);
    }
    if (flags & 4) {
        InitArrayEntries(first, second);
    }
}


extern "C" LocalM128 _mm_load_ss(const float* p);

struct S00cfa6e0_Src {
    int u00;
    float f04;
    float f08;
    int u0c;
    int u10;
    int u14;
    int u18;
    int u1c;
    int u20;
    int u24;
    int u28;
    int u2c;
    int u30;
    int u34;
    int u38;
    int u3c;
    int u40;
    int u44;
    int u48;
    int u4c;
    int u50;
    float f54;
    int u58;
    float f5c;
    int u60;
    int u64;
    int u68;
    int u6c;
    int u70;
    int u74;
    int u78;
    int u7c;
    int u80;
    int u84;
    int u88;
    int u8c;
    int u90;
    int u94;
    int u98;
    int u9c;
    int ua0;
    int ua4;
    int ua8;
    int uac;
    int ub0;
    int ub4;
    int ub8;
    int ubc;
    int uc0;
    int uc4;
    int uc8;
    int ucc;
    int ud0;
    int ud4;
    int ud8;
    int udc;
    int ue0;
    int ue4;
    int ue8;
    int uec;
    int uf0;
    int uf4;
    int uf8;
    int ufc;
    int u100;
    int u104;
    int u108;
    float f10c;
    float f110;
    int u114;
    int u118;
    float f11c;
    float f120;
    int u124;
    float f128;
    int u12c;
};

struct S00cfa6e0_Pair {
    int u00; int u04; int i08; int i0c;
};

struct S00cfa6e0_Dst {
    float f00;
    float f04;
    float f08;
    int i0c;
    int i10;
    float f14;
    float f18;
    int u1c;
    float f20;
    float f24;
    float f28;
    int u2c;
    int u30;
    int u34;
    int u38;
    int u3c;
    float f40;
    float f44;
    int u48;
    int u4c;
    int i50;
    int i54;
    int i58;
    int i5c;
    int u60;
    int u64;
    int i68;
    int u6c;
    void hkpConstraintQueryIn_set(S00cfa6e0_Src* s, S00cfa6e0_Pair* p, int v);
};

// Copies float and int fields from s and p into this object, computing several products of source floats.
// @fnv 0x00cfa6e0
// src: XBOX_PDB 0x00cfa6e0
void S00cfa6e0_Dst::hkpConstraintQueryIn_set(S00cfa6e0_Src* apSource, S00cfa6e0_Pair* apPair, int aiValue)
{
    f00 = apSource->f10c;
    f04 = apSource->f11c * apSource->f10c;
    f08 = apSource->f110;
    f14 = apSource->f120;
    f18 = apSource->f120 * apSource->f11c;
    f40 = apSource->f04;
    f44 = apSource->f08;
    i68 = aiValue;
    f20 = apSource->f54 * apSource->f110;
    f24 = apSource->f08;
    f28 = apSource->f5c * apSource->f110;
    i0c = apPair->i08;
    i10 = apPair->i0c;
    LocalM128 t = _mm_load_ss(&apSource->f128);
    int* ti = (int*)&t;
    i50 = ti[0];
    i54 = ti[1];
    i58 = ti[2];
    i5c = ti[3];
}

struct FUN_00cfa7d0
{
    int m_0000;
    volatile int m_0004;
    int m_0008;
    int m_000C;
    int m_0010;
    int m_0014;
    unsigned char m_0018[8];
    LocalM128 m_0020;
    LocalM128 m_0030;
    LocalM128 m_0040;
    int m_0050;
    int m_0054;
    int m_0058;
    int m_005C;
    int m_0060;
    unsigned char m_0064[4];
    int m_0068;
    unsigned char m_006C;
    unsigned char m_006D;
    unsigned char m_006E[2];
    int m_0070;

    FUN_00cfa7d0(const FUN_00cfa7d0& rhs);
};

// Copy constructor: copies most members from rhs but not the byte arrays at 0x18, 0x64 and 0x6E, reading m_0004 twice.
// @fnv 0x00cfa7d0
FUN_00cfa7d0::FUN_00cfa7d0(const FUN_00cfa7d0& rhs)
{
    m_0000 = rhs.m_0000;
    m_0004 = rhs.m_0004;
    m_0008 = rhs.m_0008;
    m_000C = rhs.m_000C;
    m_0010 = rhs.m_0010;
    m_0014 = rhs.m_0014;
    m_0020 = rhs.m_0020;
    m_0030 = rhs.m_0030;
    m_0040 = rhs.m_0040;
    m_0050 = rhs.m_0050;
    m_0054 = rhs.m_0054;
    m_0058 = rhs.m_0058;
    m_005C = rhs.m_005C;
    m_0060 = rhs.m_0060;
    m_0068 = rhs.m_0068;
    m_006C = rhs.m_006C;
    m_006D = rhs.m_006D;
    m_0070 = rhs.m_0070;
    m_0004 = rhs.m_0004;
}

#include <math.h>
namespace MathUtilities {
    template <typename T>
    inline T min2(T a, T b) {
        return (a < b) ? a : b;
    }
}

struct Sim : hkpSimulation {
    float GetClampedSimulationTime();
};

// @fnv 0x00cf89c0
float Sim::GetClampedSimulationTime() {
    if (m_fFrameMarkerTime != -1.0f) {
        if (fabsf(m_fFrameMarkerTime - m_fSimulationTime) < m_fFrameMarkerPsiSnap) {
            m_fFrameMarkerTime = m_fSimulationTime;
        }
    }
    float retVal;
    if (m_fFrameMarkerTime == -1.0f) {
        retVal = m_fSimulationTime;
    } else {
        retVal = MathUtilities::min2(m_fSimulationTime, m_fFrameMarkerTime);
    }
    return retVal;
}

class hkRefObjCF87 {
public:
    virtual ~hkRefObjCF87() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkRefObjCF87() { m_sReferenceCount = 1; }
};

class FUN_00cf87c0 : public hkRefObjCF87 {
public:
    int m_08;
    void* m_0c;
    bool m_10;
    char unk11;
    char unk12;
    char unk13;
    float m_14;
    float m_18;
    int unk1C;
    float m_20;
    float m_24;
    int m_28;

    FUN_00cf87c0(void* p) throw();
    virtual ~FUN_00cf87c0() throw();
};

// Initializes a FUN_00cf87c0 object by storing the provided pointer in m_0c and setting default values for its member fields.
// @fnv 0x00cf87c0
FUN_00cf87c0::FUN_00cf87c0(void* p) throw()
    : m_0c(p), m_14(0.0f), m_18(0.0f), m_20(-1.0f), m_24(0.0001f), m_28(0)
{
    m_10 = true;
    m_08 = 0;
}

extern "C" const char str_010cc568[];
static __forceinline void S00cf8bc0_timer(const char* tag, hkReal& slot) {
    hkMonitorStream* s = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
    char* pos = s->m_end.m_storage;
    if (pos < s->m_capacityMinus16.m_storage) {
        *(const char**)pos = tag;
        _ReadWriteBarrier();
        *(volatile hkUint32*)&slot = (hkUint32)__rdtsc();
        *(hkUint32*)(pos + 4) = *(volatile hkUint32*)&slot;
        pos += 12;
        s->m_end.m_storage = pos;
    }
}
struct S00cf8bc0_Sim : hkpSimulation_Derived {
    int hkpSimulation_collide();
};
// If m_uiSimulationType is non-zero, returns FUN_00cf8820(); else calls step by m_fStepDeltaTime, returning 2 if DAT_01269200 is 1, otherwise 0.
// @fnv 0x00cf8bc0
// src: HAVOK_LIB 0x00cf8bc0
int S00cf8bc0_Sim::hkpSimulation_collide() {
    hkReal startTime;
    S00cf8bc0_timer(str_010cc568, startTime);
    if (m_uiSimulationType != 0) {
        int r = hkpSimulation_reCollideAfterStepFailure();
        S00cf8bc0_timer(str_010c41f8, startTime);
        return r;
    }
    startTime = m_fSimulationTime;
    hkStepInfo si;
    si.set(startTime, m_fSimulationTime + m_fStepDeltaTime);
    step(&si);
    if (DAT_01269200 == 1) {
        m_uiSimulationType = 2;
        S00cf8bc0_timer(str_010c41f8, startTime);
        return 2;
    }
    m_fSimulationTime += m_fStepDeltaTime;
    if (m_pOwningWorld->m_kWorldPostCollideListeners.m_iElementCount != 0) {
        S00cf8bc0_timer(str_010cc530, startTime);
        hkpWorldCallbackUtil_firePostCollideCallback(m_pOwningWorld, &si);
        S00cf8bc0_timer(str_010c41f8, startTime);
    }
    m_bHasStepped = 1;
    m_uiSimulationType = 0;
    S00cf8bc0_timer(str_010c41f8, startTime);
    return 0;
}

typedef unsigned int u32;
extern "C" unsigned __int64 __rdtsc();
extern "C" void _ReadWriteBarrier();
extern const char str_010cc624[], str_010cc618[], str_010cc60c[], str_010cc5fc[];
extern const char str_010cc5f0[], str_010cc5e4[], str_010cc5d8[], str_01076f38[];
extern "C" void __cdecl hkSetOutOfMemoryState(int);

extern "C" void __cdecl hkpTypedBroadPhaseDispatcher_removeDuplicates(hkArrayBase<__int64>*, hkArrayBase<__int64>*);
extern "C" void __cdecl hkpEntityAabbUtil_entityBatchRecalcAabb(void*, void*, int);
struct Ctx64 { void __thiscall DispatchPairs(u32, int); void __thiscall hkpTypedBroadPhaseDispatcher_addPairs(u32, int, void*); };
struct MainObj {
 virtual void s00(); virtual void s04(); virtual void s08(); virtual void s0c();
 virtual void s10(); virtual void s14(); virtual void s18(); virtual void s1c();
 virtual void s20(); virtual void s24(); virtual void s28();
 virtual void __thiscall Proc(void*, void*, int, hkArrayBase<__int64>*, hkArrayBase<__int64>*);
};
struct AllocX {
 virtual void a00(); virtual void a04(); virtual void a08(); virtual void a0c();
 virtual void Free(void*, u32);
 virtual void a14(); virtual void a18(); virtual void a1c(); virtual void a20();
 virtual bool Test(u32);
};
typedef void* (__stdcall *TlsFn)(unsigned long);
static __forceinline void record16(TlsFn get,volatile u32& t){
 hkMonitorStream* s=(hkMonitorStream*)get(DAT_0126835c); hkMonitorStream::TimerBeginListCommand* p=(hkMonitorStream::TimerBeginListCommand*)s->m_end.m_storage;
 if((char*)p < s->m_capacityMinus16.m_storage){ p->m_commandAndMonitor=str_010cc624; p->m_nameOfFirstSplit=str_010cc618; _ReadWriteBarrier(); t=(u32)__rdtsc(); p->m_time0=t; s->m_end.m_storage=(char*)p+16; }
}
static __forceinline void record12(const char* tag, TlsFn get=TlsGetValue){
 hkMonitorStream* s=(hkMonitorStream*)get(DAT_0126835c); hkMonitorStream::TimerCommand* p=(hkMonitorStream::TimerCommand*)s->m_end.m_storage;
 if((char*)p < s->m_capacityMinus16.m_storage){ p->m_commandAndMonitor=tag; _ReadWriteBarrier(); volatile u32 t=(u32)__rdtsc(); p->m_time0=t; s->m_end.m_storage=(char*)p+12; }
}
static __forceinline void recordInto(const char* tag, volatile u32& t, TlsFn get=TlsGetValue){
 hkMonitorStream* s=(hkMonitorStream*)get(DAT_0126835c); hkMonitorStream::TimerCommand* p=(hkMonitorStream::TimerCommand*)s->m_end.m_storage;
 if((char*)p < s->m_capacityMinus16.m_storage){ p->m_commandAndMonitor=tag; _ReadWriteBarrier(); t=(u32)__rdtsc(); p->m_time0=t; s->m_end.m_storage=(char*)p+12; }
}

static __forceinline u32 stackAlloc(int size){
 hkMemoryRouter* h=hkMemoryRouter_getInstance();
 u32 base= (int)(h->m_stack.m_next.m_storage); h->m_stack.m_next.m_storage=(void*)(base+((size+127)&~127)); return base;
}
static __forceinline void stackFree(u32 base){ hkMemoryRouter_getInstance()->m_stack.m_next.m_storage=(void*)(base); }
static __forceinline void clear(hkArrayBase<__int64>* a, AllocX* allocator){
 a->m_iElementCount=0;
 if(!(a->m_iCapacityState&0x80000000)) allocator->Free((void*)a->m_data,(a->m_iCapacityState&0x3fffffff)*8);
 a->m_data=0; a->m_iCapacityState=0x80000000;
}
struct LocalArr {
 hkArrayBase<__int64> arr; u32 saved;
 __forceinline void init(int count){
  arr.m_data=0; arr.m_iElementCount=0; arr.m_iCapacityState=0x80000000;
  u32 base=stackAlloc(count*8);
  arr.m_data=(__int64*)base; arr.m_iCapacityState=count|0x80000000; saved=base;
 }
 __forceinline void release(){
  if(saved==(u32)arr.m_data) {arr.m_iElementCount=0;}
  stackFree(saved);
  hkMemoryRouter* holder=hkMemoryRouter_getInstance();
  clear(&arr,(AllocX*)holder->m_heap);
 }
};
struct Block16 { u32 f[4]; };
static __forceinline void copyBounds(void* destination, const void* source, int n){const u32* src=(const u32*)source; u32* dst=(u32*)destination; do{dst[0]=src[0];dst[1]=src[1];dst[2]=src[2];dst[3]=src[3]; src+=4;dst+=4;}while(--n>0);}
struct EntityData {
 u32 unk00; u32 unk04; u32 unk08; u32 unk0c; u32 unk10; u32 unk14; u32 unk18; u32 unk1c;
 Block16 bounds[2];
};
struct Entity { u32 unk00; u32 unk04; u32 unk08; u32 unk0c; EntityData data; };
struct Optional { u32 unk00; u32 unk04; u32 payload; };
// Copies entity bounds to a stack buffer, runs a2->main->Proc to fill two arrays, then dispatches pairs through a2->ctx64 if the allocator check passes.
// @fnv 0x00cf9c60
// src: HAVOK_LIB 0x00cf9c60
void __cdecl hkpSimulation_collideEntitiesBroadPhaseDiscrete(Entity** apEntities, int aiCount, hkpWorld* apContext){
 TlsFn get=TlsGetValue;
 int rem;
 record16(get,reinterpret_cast<volatile u32&>(rem));
 LocalArr arrA; arrA.init(apContext->m_iBroadPhaseNumObjects);
 LocalArr arrB; arrB.init(apContext->m_iBroadPhaseNumObjects);
 u32 pBoundsBuffer=stackAlloc(aiCount*32);
 u32 pPointersBuffer=stackAlloc(aiCount*4);
 recordInto(str_010cc60c,reinterpret_cast<volatile u32&>(rem),get);
 Entity** elems=apEntities;
 Block16* destination=(Block16*)pBoundsBuffer;
 rem=aiCount-1;
 if(rem>=0){
 int pointerDifference=(char*)pPointersBuffer-(char*)elems;
 do {
  Entity* e=*elems;
  EntityData* data=&e->data;
  *(u32**)((char*)elems+pointerDifference)=&data->unk14;
  Block16* src=data->bounds;
  if(src[0].f[0] > src[1].f[0]) hkpEntityAabbUtil_entityBatchRecalcAabb(apContext->m_pCollisionInput, &e, 1);
  copyBounds((void*)destination,data->bounds,2);
  destination=(Block16*)((Block16*)destination+2);
  ++elems;
 } while(--rem>=0);
 }
 record12(str_010cc5fc);
 u32 pointerBase=pPointersBuffer;
 ((MainObj*)apContext->m_pJobSemaphore)->Proc((void*)pointerBase,(void*)pBoundsBuffer,aiCount,&arrA.arr,&arrB.arr);
 stackFree(pointerBase);
 stackFree(pBoundsBuffer);
 if(arrA.arr.m_iElementCount+arrB.arr.m_iElementCount>0){
  record12(str_010cc5f0);
  hkpTypedBroadPhaseDispatcher_removeDuplicates(&arrA.arr,&arrB.arr);
  record12(str_010cc5e4);
  ((Ctx64*)apContext->m_pBroadPhaseDispatcher)->DispatchPairs((u32)arrB.arr.m_data,arrB.arr.m_iElementCount);
  int size=arrA.arr.m_iElementCount;
  hkMemoryRouter* holder=hkMemoryRouter_getInstance();
  AllocX* pAllocator=(AllocX*)holder->m_heap;
  if(!pAllocator->Test((u32)(size*5)<<7)){
   hkSetOutOfMemoryState(1);
   record12(str_01076f38);
   arrB.release(); arrA.release(); return;
  }
  record12(str_010cc5d8);
  ((Ctx64*)apContext->m_pBroadPhaseDispatcher)->hkpTypedBroadPhaseDispatcher_addPairs((u32)arrA.arr.m_data,arrA.arr.m_iElementCount,((Optional*)apContext->m_pCollisionFilter) ? &((Optional*)apContext->m_pCollisionFilter)->payload : 0);
 }
 record12(str_01076f38);
finish:
 arrB.release();
 arrA.release();
}

extern const char DAT_010c41f8[];
extern const char str_01076f38[];
extern const char str_010cc574[];
extern const char str_010cc58c[];
extern const char str_010c41f8[];
extern const char str_010cc55c[];
extern const char str_010cc5a4[];
extern const char str_010cc5b0[];
extern const char str_010cc5bc[];
extern const char str_010cc5c4[];
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, int);
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern unsigned long DAT_0126835c;
inline hkMonitorStream* hkMonitorStream::getInstancePtr() { return (hkMonitorStream*)TlsGetValue(DAT_0126835c); }
// The original's timer helpers (expansions of Havok's timer macros), kept as members of a unit-local view so the
// inlined code keeps its shape.
struct MonitorStream_hkpsimulation : hkMonitorStream
{
    void list(const char* name, const char* first, unsigned int& ticks);
    void timer(const char* name, unsigned int& ticks);
};
inline void MonitorStream_hkpsimulation::timer(const char* name, unsigned int& ticks) {
    if (m_end.m_storage < m_capacityMinus16.m_storage) {
        hkMonitorStream::TimerCommand* cmd = (hkMonitorStream::TimerCommand*)m_end.m_storage;
        cmd->m_commandAndMonitor = name;
        _ReadWriteBarrier();
        (volatile unsigned int&)ticks = (unsigned int)__rdtsc();
        cmd->m_time0 = ticks;
        m_end.m_storage = (char*)(cmd + 1);
    }
}
inline void MonitorStream_hkpsimulation::list(const char* name, const char* first, unsigned int& ticks) {
    if (m_end.m_storage < m_capacityMinus16.m_storage) {
        hkMonitorStream::TimerBeginListCommand* cmd = (hkMonitorStream::TimerBeginListCommand*)m_end.m_storage;
        cmd->m_commandAndMonitor = name;
        cmd->m_nameOfFirstSplit = first;
        _ReadWriteBarrier();
        (volatile unsigned int&)ticks = (unsigned int)__rdtsc();
        cmd->m_time0 = ticks;
        m_end.m_storage = (char*)(cmd + 1);
    }
}
struct TimeInterval { float startTime, endTime, deltaTime, invDeltaTime; };
struct SolverInfo {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    LocalM128 gravityPerStep;
    LocalM128 gravityPerFrame;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    void* collisionInput78;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned char unk0d4;
    unsigned char callbackEnabled;
    unsigned short unk0d6;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    float deltaTime;
    float invDeltaTime;
    int numSteps;
    unsigned int unk118;
    unsigned int unk11c;
    float tau;
    unsigned char flags0;
    unsigned char flags;
    unsigned char bufferIndex;
    unsigned char frameCounter;
    unsigned int unk128;
    unsigned int unk12c;
};
struct MemoryRequirements;
struct Island {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    int numConstraints;
    unsigned int unk010;
    unsigned int unk014;
    hkpWorld* world;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned short flags0;
    unsigned char flags; unsigned char unk027;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    void* entities;
    int numEntities;
};

struct MemoryRequirements { int max, sum; Island* biggest; };
static __forceinline void unlockWorldOperations(hkpWorld* world) {
    if (--world->m_iCriticalOperationsLockCount == 0 && !world->m_bBlockExecutingPendingOperations) {
        if (world->m_iPendingOperationCount) world->FUN_00c91120();
        if (world->m_iPendingOperationQueueCount == 1 && world->m_iQueuedOperationCount) world->UpdateFields_00c91140();
    }
}

// Retain the missing memory-usage method without duplicating the world layout.
class hkpWorldMemoryUsage : public hkpWorld {
public:
    __declspec(noinline) void ComputeMemoryUsage(MemoryRequirements*);
};

__declspec(noinline) void hkpWorldMemoryUsage::ComputeMemoryUsage(MemoryRequirements* memory) {
    memory->max = memory->sum = 0;
    memory->biggest = 0;
    for (int index=m_kActiveSimulationIslands.m_iElementCount-1; index>=0; --index) {
        Island* island=(Island*)m_kActiveSimulationIslands.m_data[index];
        int extra=2*((int)island->unk01c/80)+8;
        int size=((3*extra+(int)island->unk014)*4+23)&-16;
        size+=(extra+8*island->numEntities+10)*16+island->numConstraints;
        memory->sum+=size;
        if (size>memory->max) { memory->max=size; memory->biggest=island; }
    }
}
struct Holder { unsigned int unk00, unk04, unk08, unk0c, unk10, unk14; MemoryManager* memory; };

extern "C" void __cdecl hkSolveUpload();
extern "C" void __cdecl hkpWorldOperationUtil_cleanupDirtyIslands(hkpWorld*);
extern "C" void __cdecl hkpWorldMemoryUtil_checkMemoryForIntegration(hkpWorld*);
struct __declspec(align(16)) IntegrationContext {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    hkVector4 tolerance;
    unsigned int unk060;
    unsigned int unk064;
    void* collisionInput;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    void* collisionInput78;
    unsigned int unk07c;
    void hkpConstraintQueryIn_set(SolverInfo*, const TimeInterval*, void*);
};
extern "C" int __cdecl hkRigidMotionUtilApplyForcesAndStep(SolverInfo*, TimeInterval*, void*, void*, int, int);
extern "C" void __cdecl hkpEntityAabbUtil_entityBatchRecalcAabb(void*, void*, int);
extern "C" int __cdecl hkpConstraintSolverSetup_solve(TimeInterval*, SolverInfo*, IntegrationContext*, Island*, int, int, void*, int);
extern "C" void __cdecl AddItemToContainer(hkpWorld*, Island*);
extern "C" void __cdecl hkpWorldCallbackUtil_fireIslandPostIntegrateCallback(hkpWorld*, Island*, const TimeInterval*);
extern "C" void __cdecl hkpWorldCallbackUtil_firePostIntegrateCallback(hkpWorld*, const TimeInterval*);
struct Simulation {
    unsigned int unk00, unk04, unk08;
    hkpWorld* m_pOwningWorld;
    unsigned int unk10, unk14, unk18, unk1c, unk20, unk24;
    unsigned int m_uiSimulationType;
    void hkpSimulation_applyActions();
    int hkpSimulation_integrateInternal(const TimeInterval* step);
};
// Advances the simulation by one time step, integrating island entities and invoking world and island callbacks.
// @fnv 0x00cf8da0
// src: XBOX_PDB 0x00cf8da0
int Simulation::hkpSimulation_integrateInternal(const TimeInterval* step) {
    struct IslandResources {
        MemoryRequirements memory;
        unsigned int singleEnd;
        unsigned int singleStart;
        hkArray<Island*>* islands;
    } resources;
    struct ScalarScratch { float dt; int i; } scalar;
    static_cast<MonitorStream_hkpsimulation*>(hkMonitorStream::getInstancePtr())->list(str_010cc5c4, str_010cc5bc, (unsigned int&)scalar.i);
    (*(TimeInterval*)(m_pOwningWorld->pad1C8 + 0x8)) = *step;
    SolverInfo* allocator = &(*(SolverInfo*)(m_pOwningWorld->pad1C8 + 0x18));
    allocator->deltaTime = allocator->tau * step->deltaTime;
    allocator->invDeltaTime = allocator->numSteps * step->invDeltaTime;
    LocalM128 scale;
    scale = _mm_load_ss(&allocator->deltaTime);
    LocalM128 frame = _mm_shuffle_ps(scale, scale, 0);
    allocator->gravityPerStep = _mm_mul_ps(frame, m_pOwningWorld->m_kGravity.m_vComponents);
    scalar.dt = step->deltaTime;
    scale = _mm_load_ss(&scalar.dt);
    frame = _mm_shuffle_ps(scale, scale, 0);
    allocator->gravityPerFrame = _mm_mul_ps(frame, m_pOwningWorld->m_kGravity.m_vComponents);
    hkSolveUpload();
    hkpWorldOperationUtil_cleanupDirtyIslands(m_pOwningWorld);

    ((hkpWorldMemoryUsage*)m_pOwningWorld)->ComputeMemoryUsage(&resources.memory);
    Holder* holder;
    MemoryManager* solver;
    holder = (Holder*)hkMemoryRouter_getInstance();
    solver = holder->memory;
    // The solver allocator calls slot 8; the shared available declaration is nonvirtual.
    if (!reinterpret_cast<bool (__thiscall **)(MemoryManager*, int)>(*reinterpret_cast<void***>(solver))[8](solver, resources.memory.max)) {
        if (m_pOwningWorld->hkpWorld_getMemoryWatchDog()) {
            unlockWorldOperations(m_pOwningWorld);
            hkpWorldMemoryUtil_checkMemoryForIntegration(m_pOwningWorld);
            ++m_pOwningWorld->m_iCriticalOperationsLockCount;
        } else {
            m_uiSimulationType = 1;
            return 1;
        }
    }
    m_pOwningWorld->m_iCriticalOperationsLockCount++;
    --m_pOwningWorld->m_iCriticalOperationsLockCountForPhantoms;
    static_cast<MonitorStream_hkpsimulation*>(hkMonitorStream::getInstancePtr())->timer(str_010cc5b0, (unsigned int&)scalar.i);
    hkpSimulation_applyActions();
    ++m_pOwningWorld->m_iCriticalOperationsLockCountForPhantoms;
    unlockWorldOperations(m_pOwningWorld);
    ++m_pOwningWorld->m_iCriticalOperationsLockCount;
    allocator = &(*(SolverInfo*)(m_pOwningWorld->pad1C8 + 0x18));
    unsigned char uiFrameCounter = ++allocator->frameCounter;
    if (((uiFrameCounter - 4) & 7) == 0) allocator->flags ^= 1;
    if ((uiFrameCounter & 7) == 0) allocator->flags ^= 2;
    if ((uiFrameCounter & 15) == 0) {
        allocator->bufferIndex = 1 - allocator->bufferIndex;
        allocator->frameCounter = 0;
    }
    IntegrationContext context;
    context.hkpConstraintQueryIn_set(&(*(SolverInfo*)(m_pOwningWorld->pad1C8 + 0x18)), step, m_pOwningWorld->m_pViolatedConstraintArray);
    static_cast<MonitorStream_hkpsimulation*>(hkMonitorStream::getInstancePtr())->timer(str_010cc5a4, (unsigned int&)scalar.i);
    resources.islands = (hkArray<Island*>*)&m_pOwningWorld->m_kActiveSimulationIslands;
    for (scalar.i = resources.islands->m_iElementCount - 1; scalar.i >= 0; --scalar.i) {
        Island* __restrict island = resources.islands->m_data[scalar.i];
        int result;
        TimeInterval* info = &(*(TimeInterval*)(m_pOwningWorld->pad1C8 + 0x8));
        if (island->numConstraints == 0) {

            static_cast<MonitorStream_hkpsimulation*>(hkMonitorStream::getInstancePtr())->timer(str_010cc55c, resources.singleStart);
            void*& pEntityData = island->entities;
            int iEntityCount = (volatile int&)island->numEntities;
            void* firstData = (void*volatile&)island->entities;
            result = hkRigidMotionUtilApplyForcesAndStep((SolverInfo*)(info + 1), info, &((SolverInfo*)(info + 1))->gravityPerFrame, firstData, iEntityCount, 0xe0);
            hkpEntityAabbUtil_entityBatchRecalcAabb((island->world)->m_pCollisionInput, pEntityData, island->numEntities);
            static_cast<MonitorStream_hkpsimulation*>(hkMonitorStream::getInstancePtr())->timer(DAT_010c41f8, resources.singleEnd);
        } else {
            int count = island->numEntities;
            void* batch = island->entities;
            result = hkpConstraintSolverSetup_solve(info, (SolverInfo*)(info + 1), &context, island, 0, 0, batch, count);
        }
        if (result > 5 && (island->flags & 12) && island->world->m_bWantDeactivation) {
            AddItemToContainer(island->world, island);
        }
        if (m_pOwningWorld->m_kIslandPostIntegrateListeners.m_iElementCount) {
            static_cast<MonitorStream_hkpsimulation*>(hkMonitorStream::getInstancePtr())->timer(str_010cc58c, (unsigned int&)scalar.dt);
            hkpWorldCallbackUtil_fireIslandPostIntegrateCallback(m_pOwningWorld, island, step);
        }
    }
    unlockWorldOperations(m_pOwningWorld);
    if (m_pOwningWorld->m_kWorldPostIntegrateListeners.m_iElementCount) {
        static_cast<MonitorStream_hkpsimulation*>(hkMonitorStream::getInstancePtr())->timer(str_010cc574, (unsigned int&)scalar.dt);
        hkpWorldCallbackUtil_firePostIntegrateCallback(m_pOwningWorld, step);
        static_cast<MonitorStream_hkpsimulation*>(hkMonitorStream::getInstancePtr())->timer(DAT_010c41f8, (unsigned int&)scalar.dt);
    }
    static_cast<MonitorStream_hkpsimulation*>(hkMonitorStream::getInstancePtr())->timer(str_01076f38, (unsigned int&)scalar.dt);
    return 0;
}

#include <string.h>
extern "C" void _ReadWriteBarrier(void);

extern "C" unsigned __int64 __cdecl __rdtsc(void);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned long DAT_0126835c;
extern "C" int DAT_01269200;
extern "C" char str_010cc64c;
extern "C" char str_010cc54c;
extern "C" char str_010cc634;
__forceinline void stamp(const char* name, volatile unsigned int& clockSlot) {
 hkMonitorStream* t = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
 hkMonitorStream::TimerCommand* e = reinterpret_cast<hkMonitorStream::TimerCommand*>(t->m_end.m_storage);
 if (reinterpret_cast<char*>(e) < t->m_capacityMinus16.m_storage) {
  e->m_commandAndMonitor = name;
  unsigned int ticks;
  __asm {
      rdtsc
      mov dword ptr[ticks], eax
  }
  e->m_time0 = ticks;
  t->m_end.m_storage = reinterpret_cast<char*>(e + 1);
 }
}
struct S00cfa080_Info {
 unsigned int unk000;
 unsigned int unk004;
 unsigned int unk008;
 unsigned int unk00c;
 unsigned int unk010;
 unsigned int unk014;
 unsigned int unk018;
 unsigned int unk01c;
 unsigned int unk020;
 unsigned int unk024;
 unsigned int unk028;
 unsigned int unk02c;
 unsigned int unk030;
 unsigned int unk034;
 unsigned int unk038;
 unsigned int unk03c;
 unsigned int unk040;
 unsigned int unk044;
 unsigned int unk048;
 unsigned int unk04c;
 unsigned int unk050;
 unsigned int unk054;
 unsigned int unk058;
 unsigned int unk05c;
 unsigned int unk060;
 unsigned int unk064;
 unsigned int unk068;
 unsigned int unk06c;
 unsigned int unk070;
 unsigned int unk074;
 unsigned int unk078;
 unsigned int unk07c;
 unsigned int unk080;
 unsigned int unk084;
 unsigned int unk088;
 unsigned int unk08c;
 unsigned int unk090;
 unsigned int unk094;
 unsigned int unk098;
 unsigned int unk09c;
 unsigned int unk0a0;
 unsigned int unk0a4;
 unsigned int unk0a8;
 unsigned int unk0ac;
 unsigned int unk0b0;
 unsigned int unk0b4;
 unsigned int unk0b8;
 unsigned int unk0bc;
 unsigned int unk0c0;
 unsigned int unk0c4;
 unsigned int unk0c8;
 unsigned int unk0cc;
 unsigned int unk0d0;
 unsigned int unk0d4;
 unsigned int unk0d8;
 unsigned int unk0dc;
 unsigned int unk0e0;
 unsigned int unk0e4;
 unsigned int unk0e8;
 unsigned int unk0ec;
 unsigned int unk0f0;
 unsigned int unk0f4;
 unsigned int unk0f8;
 unsigned int unk0fc;
 unsigned int unk100;
 unsigned int unk104;
 unsigned int unk108;
 float m_10c;
 float m_110;
 int m_114;
 unsigned int unk118;
 unsigned int unk11c;
 float m_120;
 void setStep(const hkVector4* p) {
  m_10c = p->z * m_120;
  m_110 = (float)m_114 * p->w;
 }
};
struct O;
struct O { unsigned int unk000;
unsigned int unk004;
unsigned int unk008;
unsigned int unk00c;
unsigned int unk010;
unsigned int unk014;
unsigned int unk018;
unsigned int unk01c;
unsigned int unk020;
unsigned int unk024;
unsigned int unk028;
unsigned int unk02c;
unsigned int unk030;
unsigned int unk034;
unsigned int unk038;
unsigned int unk03c;
unsigned int unk040;
unsigned int unk044;
unsigned int unk048;
unsigned int unk04c;
unsigned int unk050;
unsigned int unk054;
unsigned int unk058;
unsigned int unk05c;
unsigned int unk060; };
struct S00cfa080_Obj {
 unsigned int unk00, unk04, unk08; hkpWorld* m_pOwningWorld;
 void __thiscall hkpSimulation_collideInternal(hkVector4* p);
};
extern "C" void __cdecl hkpSimulation_collideEntitiesBroadPhaseDiscrete(unsigned int, unsigned int, hkpWorld*);
extern "C" void __cdecl hkpConstraintOwner_ProcessEntries_00cff3c0(O*, void*, O*);
extern "C" void __cdecl hkpWorldCallbackUtil_fireIslandPostCollideCallback(hkpWorld*,O*,hkVector4*);
__forceinline void stampN(const char* name) {
 hkMonitorStream* t = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
 hkMonitorStream::TimerCommand* e = reinterpret_cast<hkMonitorStream::TimerCommand*>(t->m_end.m_storage);
 if (reinterpret_cast<char*>(e) < t->m_capacityMinus16.m_storage) {
  e->m_commandAndMonitor = name;
  unsigned int ticks;
  __asm {
      rdtsc
      mov dword ptr[ticks], eax
  }
  e->m_time0 = ticks;
  t->m_end.m_storage = reinterpret_cast<char*>(e + 1);
 }
}
__forceinline void stampEnd() {
 hkMonitorStream* t = (hkMonitorStream*)TlsGetValue(DAT_0126835c);
 hkMonitorStream::TimerCommand* e = reinterpret_cast<hkMonitorStream::TimerCommand*>(t->m_end.m_storage);
 if (reinterpret_cast<char*>(e) < t->m_capacityMinus16.m_storage) {
  e->m_commandAndMonitor = str_010c41f8;
  unsigned int ticks;
  __asm {
      rdtsc
      mov dword ptr[ticks], eax
  }
  e->m_time0 = ticks;
  t->m_end.m_storage = reinterpret_cast<char*>(e + 1);
 }
}
__forceinline void done(hkpWorld* w) {
 if (--w->m_iCriticalOperationsLockCount == 0 && w->m_bBlockExecutingPendingOperations.m_cBooleanValue == 0) {
  if(w->m_iPendingOperationCount != 0) w->FUN_00c91120();
  if(w->m_iPendingOperationQueueCount == 1 && w->m_iQueuedOperationCount != 0) w->UpdateFields_00c91140();
 }
}
// @fnv 0x00cfa080
// src: HAVOK_LIB 0x00cfa080
void S00cfa080_Obj::hkpSimulation_collideInternal(hkVector4* p) {
 volatile unsigned int tb, t1, t2, t3;
 stamp(&str_010cc64c, tb);
 memcpy(m_pOwningWorld->pad1C8 + 0x8, p, sizeof(hkVector4));
 O* o = (O*)m_pOwningWorld->m_pCollisionInput;
 *(hkVector4*)&o->unk050 = *p;
 hkpWorld* physics = m_pOwningWorld;
 ((S00cfa080_Info*)(physics->pad1C8 + 0x18))->setStep(p);
 ++m_pOwningWorld->m_iCriticalOperationsLockCount;
 hkArray<O*>* a = (hkArray<O*>*)&m_pOwningWorld->m_kActiveSimulationIslands;
 for (int i = 0; i < a->m_iElementCount; ++i) {
  O* e = a->m_data[i];
  hkpSimulation_collideEntitiesBroadPhaseDiscrete(e->unk048,e->unk04c,m_pOwningWorld);
  if (DAT_01269200 == 1) {
   done(m_pOwningWorld);
   stampEnd();
   return;
  }
 }
 done(m_pOwningWorld);
 ++m_pOwningWorld->m_iCriticalOperationsLockCount;
 const hkArray<O*>* list = (hkArray<O*>*)&m_pOwningWorld->m_kActiveSimulationIslands; O* entry;
 for(int j=0; j<list->m_iElementCount; ++j) {
  entry = list->m_data[j];
  O* obj = (O*)m_pOwningWorld->m_pCollisionInput;
  stamp(&str_010cc54c, tb);
  obj->unk060 = obj->unk000 + 0x1c60;
  obj->unk014 = 0;
  hkpConstraintOwner_ProcessEntries_00cff3c0(entry, &entry->unk058, obj);
  stamp(str_010c41f8, t1);
  if(DAT_01269200 == 1) break;
  if(m_pOwningWorld->m_kIslandPostCollideListeners.m_iElementCount != 0) {
   stamp(&str_010cc634, t2);
   hkpWorldCallbackUtil_fireIslandPostCollideCallback(m_pOwningWorld,entry,p);
   stamp(str_010c41f8, t3);
  }
 }
 done(m_pOwningWorld);
 stampEnd();
}

namespace fnv_00cf8b00 {
struct Entity {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void Process(void* info);
};

struct EntityArray {
    Entity** m_data;
    int m_iElementCount;
};

struct Island {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34;
    EntityArray m_kActorEntries;
};

struct IslandArray {
    Island** m_data;
    int m_iElementCount;
};

struct Sim {
    int unk00;
    int unk04;
    int unk08;
    hkpWorld* m_pOwningWorld;
    void hkpSimulation_applyActions();
};

// Iterates the active islands and passes the world step info to each actor entry.
// @fnv 0x00cf8b00
// src: HAVOK_LIB 0x00cf8b00
void Sim::hkpSimulation_applyActions()
{
    IslandArray& islands = *(IslandArray*)&m_pOwningWorld->m_kActiveSimulationIslands;
    for (int i = 0; i < islands.m_iElementCount; i++) {
        EntityArray& ents = islands.m_data[i]->m_kActorEntries;
        for (int j = 0; j < ents.m_iElementCount; j++) {
            ents.m_data[j]->Process(m_pOwningWorld->pad1C8 + 0x8);
        }
    }
}
}  // namespace fnv_00cf8b00

extern "C" {
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_sub_ss(LocalM128, LocalM128);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_mul_ss(LocalM128, LocalM128);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_andnot_ps(LocalM128, LocalM128);
    LocalM128 _mm_xor_ps(LocalM128, LocalM128);
    LocalM128 _mm_cmpeq_ss(LocalM128, LocalM128);
    LocalM128 _mm_sqrt_ss(LocalM128);
    LocalM128 _mm_rsqrt_ss(LocalM128);
    float _mm_cvtss_f32(LocalM128);
    LocalM128 _mm_set_ss(float);
    LocalM128 _mm_set_ps1(float);
    LocalM128 _mm_setzero_ps();
    LocalM128 _mm_load_ps(const float*);
    LocalM128 _mm_load_ss(const float*);
    void _mm_store_ps(float*, LocalM128);
    void _mm_store_ss(float*, LocalM128);
}
struct Allocator {
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void freeBlock(void*, int);
};

struct AgentNnEntry;
struct PairEntry { AgentNnEntry* pair; int key; };
struct PairArray { PairEntry* data; int size, capacity; };
struct PairMap {
    int* data; int size, mask;
    void __thiscall EnsureCapacity(Allocator*, int);
    void __thiscall hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(Allocator*, void*, int);
    int __thiscall FindSlot(int);
    void __thiscall ProcessArgument(Allocator*);
    void __thiscall Object_DoNothing();
};
struct RootBody {
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
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int owner;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    unsigned char type; unsigned char flags, quality, state;
};
struct Collidable {
    void* shape; int shapeKey; void* motion; void* parent;
    signed char ownerOffset; unsigned char force, shapeSize, flags;
    RootBody* root() { return reinterpret_cast<RootBody*>(reinterpret_cast<char*>(this) + ownerOffset); }
    void __thiscall CopyAndSortGeometryList(PairArray*);
};
// hkpAgentNnEntry (Havok hkpAgentNnTrack.h): hkpAgentEntry header, agent indices, contactMgr +0x8, collidable[2] +0x10/+0x14.
struct AgentNnEntry {
    int unk00, unk04, unk08, unk0c;
    Collidable* bodyA; Collidable* bodyB;
};
struct Quaternion {
    LocalM128 value;
    void __thiscall hkQuaternion_setAxisAngle(const LocalM128*, float);
    void __thiscall setMul(const Quaternion*, const Quaternion*);
    void __thiscall hkQuaternion_setInverseMul(const Quaternion*, const Quaternion*);
};

struct MotionHeader {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void restore(const hkTransform*);
    int unk04, unk08, unk0c;
};
struct Motion : MotionHeader {
    Transform transform;
    hkVector4 centerOfMass0, centerOfMass1;
    Quaternion rotation0, rotation1;
    hkVector4 localCenter;
};
struct Body {
    int unk00, unk04, unk08, unk0c;
    Collidable collidable;
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
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    Motion motion;
};
struct CollisionInput {
    int unk00, unk04; float tolerance;
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
    hkStepInfo* step;
};
struct AlignedPairData { LocalM128 position, normal; int id; void* properties; int userData, flags; };
struct CollisionOutput {
    AlignedPairData* firstFree;
    int owner, unk08, unk0c;
    AlignedPairData contacts[256];
    LocalM128 toiPosition, toiNormal;
    float toiTime;
    void* toiProperties; int toiId, toiFlags, toiUserData, toiMaterial, toiShapeKey, toiState;
    float separatingVelocity, rotateNormal;
    int tail00, tail04, tail08, tail0c, tail10, tail14, tail18, tail1c, tail20, tail24, tail28, tail2c;
};
typedef void (__thiscall *ProcessCallback)(void*, AgentNnEntry*, CollisionInput*, CollisionOutput*);
float __cdecl ClampAsin(float);
extern int DAT_01269200;
extern const LocalM128 DAT_010c44d0;
extern const double DAT_010cc5d0;
extern const double DAT_01082cb0;
inline LocalM128 loadVector(const hkVector4& v) { return _mm_load_ps(&v.x); }
inline LocalM128 dotVector(LocalM128 a, LocalM128 b) {
    LocalM128 p=_mm_mul_ps(a,b);
    return _mm_add_ss(_mm_shuffle_ps(p,p,0xaa),_mm_add_ss(_mm_shuffle_ps(p,p,0x55),p));
}
__forceinline void updateTranslation(Body* body) {
    Transform& t=body->motion.transform;
    LocalM128 v=loadVector(body->motion.localCenter);
    LocalM128 transformed=_mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v,v,0x55),t.r[1]),
                                            _mm_mul_ps(_mm_shuffle_ps(v,v,0),t.r[0])),
                                  _mm_mul_ps(_mm_shuffle_ps(v,v,0xaa),t.r[2]));
    _mm_store_ps(&t.m_f30,_mm_sub_ps(loadVector(body->motion.centerOfMass1),transformed));
}
struct SavedTransform {
    LocalM128 col0, col1, col2, translation;
};
struct Vec4f { int x, y, z, w; };
__forceinline void copySnapshot(Vec4f& dest,const void* value) { const Vec4f& src=*reinterpret_cast<const Vec4f*>(value); dest.x=src.x; dest.y=src.y; dest.z=src.z; dest.w=src.w; }
inline void releaseAll(PairArray& pairs, PairMap& visited) {
    hkMemoryRouter* router=(hkMemoryRouter*)hkMemoryRouter_getInstance();
    Allocator* heap=reinterpret_cast<Allocator*>(router->m_heap);
    pairs.size=0;
    if((pairs.capacity&0x80000000)==0) heap->freeBlock(pairs.data,(pairs.capacity&0x3fffffff)*8);
    pairs.data=0; pairs.capacity=0x80000000;
    Allocator* finalHeap=reinterpret_cast<Allocator*>(((hkMemoryRouter*)hkMemoryRouter_getInstance())->m_heap);
    visited.ProcessArgument(finalHeap);
    visited.Object_DoNothing();
}
inline float hkMaxF(float a,float b){return a>b?a:b;}
struct SimulationContext {
    void __thiscall hkpSimulation_processAgentsOfEntities(Body**, int, CollisionInput*, ProcessCallback, int);
};
// Iterates over bodies, collects collision pairs, invokes callback for each, and applies corrective rotations when mode is 1 and a contact is found.
// @fnv 0x00cf9480
// src: XBOX_PDB 0x00cf9480
void __thiscall SimulationContext::hkpSimulation_processAgentsOfEntities(Body** bodies, int count, CollisionInput* input, ProcessCallback callback, int mode) {
    PairMap visited;
    visited.data=0; visited.size=0; visited.mask=-1;
    hkMemoryRouter* router=(hkMemoryRouter*)hkMemoryRouter_getInstance(); Allocator* initialHeap=reinterpret_cast<Allocator*>(router->m_heap);
    visited.EnsureCapacity(initialHeap,count);
    __declspec(align(16)) CollisionOutput collisionOutput;
    collisionOutput.toiTime=3.402820018375656e38f;
    collisionOutput.owner=0;
    collisionOutput.rotateNormal=collisionOutput.separatingVelocity=0.0f;
    PairArray pairs;
    pairs.data=0; pairs.size=0; pairs.capacity=0x80000000;
    for(int i=0;i<count;++i) {
        Body* body=bodies[i];
        Collidable* root=&body->collidable;
        router=(hkMemoryRouter*)hkMemoryRouter_getInstance(); Allocator* currentHeap=reinterpret_cast<Allocator*>(router->m_heap);
        visited.hkMapBase_unsigned_long_unsigned_long_hkMapOperations_unsigned_long_insert(currentHeap,root,0);
        root->CopyAndSortGeometryList(&pairs);
        for(int j=0;j<pairs.size;++j) {
            PairEntry* finalHeap=&pairs.data[j]; int key=finalHeap->key;
            if(visited.FindSlot(key)>visited.mask) {
                AgentNnEntry* pair=finalHeap->pair;
                RootBody* collidable=pair->bodyA->root();
                Collidable* otherBody=pair->bodyB;
                int owner;
                if(collidable->type==5) owner=otherBody->root()->owner; else owner=collidable->owner;
                collisionOutput.owner=owner;
                hkAgentNnMachine_InvalidateTimInAgent((int)pair,(int)input);
                callback(this,pair,input,&collisionOutput);
                if(mode==1 && collisionOutput.firstFree!=collisionOutput.contacts) {
                    Vec4f angle; copySnapshot(angle,&body->motion.rotation1);
                    Transform& transform=body->motion.transform;
                    Vec4f sCol2, sTrans, sCol1, sCol0;
                    copySnapshot(sCol0,&transform.r[0]);
                    const LocalM128& copy_col0=*(const LocalM128*)&sCol0.x;
                    copySnapshot(sCol1,&transform.r[1]);
                    const LocalM128& copy_col1=*(const LocalM128*)&sCol1.x;
                    copySnapshot(sCol2,&transform.r[2]);
                    const LocalM128& copy_col2=*(const LocalM128*)&sCol2.x;
                    copySnapshot(sTrans,&transform.r[3]);
                    const LocalM128& copy_translation=*(const LocalM128*)&sTrans.x;
                    SavedTransform savedTransform;
                    savedTransform.col0=copy_col0;
                    savedTransform.col1=copy_col1;
                    savedTransform.col2=copy_col2;
                    savedTransform.translation=copy_translation;
                    Vec4f normalCopy; copySnapshot(normalCopy,&collisionOutput.contacts[0].normal);
                    if(finalHeap->pair->bodyA!=root) _mm_store_ps(reinterpret_cast<float*>(&normalCopy.x),_mm_xor_ps(collisionOutput.contacts[0].normal,DAT_010c44d0));
                    LocalM128 normal=_mm_load_ps(reinterpret_cast<float*>(&normalCopy.x));
                    LocalM128 delta=_mm_sub_ps(*(const LocalM128*)&body->motion.centerOfMass1,collisionOutput.contacts[0].position);
                    LocalM128 normalZXY=_mm_shuffle_ps(normal,normal,0xd2);
                    LocalM128 normalYZX=_mm_shuffle_ps(normal,normal,0xc9);
                    LocalM128 axis=_mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(delta,delta,0xd2),normalYZX),
                                          _mm_mul_ps(_mm_shuffle_ps(delta,delta,0xc9),normalZXY));
                    float axisLength; _mm_store_ss(&axisLength,_mm_sqrt_ss(dotVector(axis,axis)));
                    float projection; _mm_store_ss(&projection,dotVector(delta,normal));
                    float distance; _mm_store_ss(&distance,_mm_sqrt_ss(dotVector(delta,delta)));
                    float cosine=projection/distance;
                    if(axisLength>0.00001f && cosine<DAT_010cc5d0) {
                        float savedTolerance=input->tolerance;
                        float tolerance=input->tolerance*20.0;
                        input->tolerance=tolerance;
                        float savedStart=input->step->m_fEndTime;
                        float savedEnd=input->step->m_fTimeStep;
                        input->step->m_fEndTime=tolerance;
                        input->step->m_fTimeStep=tolerance;
                        float newCosine=hkMaxF((projection-tolerance*DAT_01082cb0)/distance,0.0f);
                        volatile float oldAngle=ClampAsin(cosine); double newAngle=ClampAsin(newCosine); float savedRotation=oldAngle-newAngle;
                        float inverseLength=1.0f/axisLength;
                        LocalM128 inverseScalar=_mm_load_ss(&inverseLength);
                        axis=_mm_mul_ps(_mm_shuffle_ps(inverseScalar,inverseScalar,0),axis);
                        Quaternion turn, rotated;
                        turn.hkQuaternion_setAxisAngle(&axis,savedRotation);
                        rotated.setMul(&turn,&body->motion.rotation1);
                        transform.hkRotation_set(&rotated);
                        updateTranslation(body);
                        hkAgentNnMachine_InvalidateTimInAgent((int)pair,(int)input);
                        callback(this,pair,input,&collisionOutput);
                        LocalM128 perpendicular=_mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(axis,axis,0xc9),normalZXY),
                                                       _mm_mul_ps(_mm_shuffle_ps(axis,axis,0xd2),normalYZX));
                        LocalM128 length=dotVector(perpendicular,perpendicular);
                        LocalM128 reciprocal=_mm_rsqrt_ss(length);
                        LocalM128 refined=_mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f),reciprocal),
                            _mm_sub_ss(_mm_set_ss(3.0f),_mm_mul_ss(_mm_mul_ss(length,reciprocal),reciprocal)));
                        refined=_mm_andnot_ps(_mm_cmpeq_ss(length,_mm_set_ss(0.0f)),refined);
                        perpendicular=_mm_mul_ps(_mm_shuffle_ps(refined,refined,0),perpendicular);
                        Quaternion sideways, oriented;
                        sideways.hkQuaternion_setAxisAngle(&perpendicular,savedRotation);
                        oriented.setMul(&sideways,(Quaternion*)&angle);
                        transform.hkRotation_set(&oriented);
                        updateTranslation(body);
                        hkAgentNnMachine_InvalidateTimInAgent((int)pair,(int)input);
                        callback(this,pair,input,&collisionOutput);
                        oriented.hkQuaternion_setInverseMul(&sideways,(Quaternion*)&angle);
                        transform.hkRotation_set(&oriented);
                        updateTranslation(body);
                        hkAgentNnMachine_InvalidateTimInAgent((int)pair,(int)input);
                        callback(this,pair,input,&collisionOutput);
                        input->tolerance=savedTolerance;
                        input->step->m_fEndTime=savedStart;
                        input->step->m_fTimeStep=savedEnd;
                        body->motion.restore((const hkTransform*)&savedTransform);
                        hkAgentNnMachine_InvalidateTimInAgent((int)pair,(int)input);
                        callback(this,pair,input,&collisionOutput);
                    }
                }
                if(DAT_01269200==1) { releaseAll(pairs,visited); return; }
            }
        }
    }
    releaseAll(pairs,visited);
}

namespace fnv_00cfa5f0 {
#include <string.h>

struct __declspec(align(16)) FNVState_CFA5F0 {
    int data00;
    int data04;
    int data08;
    int data0c;
    int data10;
    int data14;
    int data18;
    int data1c;
    int data20;
    int data24;
    int data28;
    int data2c;
    int data30;
    int data34;
    int data38;
    int data3c;
    int data40;
    int data44;
    int data48;
    int data4c;
    int input50;
    int input54;
    int input58;
    int input5c;
    int reserved60;
    int result64;
    float contactNormalX;
    float contactNormalY;
    float contactNormalZ;
    float contactDistance;
    void __thiscall FUN_00cfa7d0(const int* source);
};
struct FNVAudio_CFA5F0 {
    virtual void v0();
    virtual void v1();
    virtual void v2(int id, int flags);
};
struct FNVAudioHolder_CFA5F0 {
    int unk00, unk04, unk08, unk0c;
    FNVAudio_CFA5F0* audio10;
};
extern "C" void __cdecl hkpSimulation_collideEntitiesBroadPhaseDiscrete(int arg1,int arg2,hkpWorld* simulation);
FNVAudioHolder_CFA5F0* __cdecl hkMemoryRouter_getInstance();
struct FNVOwner_CFA5F0 {
    void __thiscall hkpSimulation_collideEntitiesNarrowPhaseDiscrete(int arg1, int arg2, FNVState_CFA5F0* state, int arg5);
    void __thiscall hkpSimulation_collideEntitiesDiscrete(int arg1,int arg2,hkpWorld* sim, const int* values,int arg5);
};
// @fnv 0x00cfa5f0
// src: HAVOK_SRC 0x00cfa5f0
void __thiscall FNVOwner_CFA5F0::hkpSimulation_collideEntitiesDiscrete(int arg1,int arg2,hkpWorld* sim,const int* values,int arg5) {
    FNVState_CFA5F0 state;
    int* source = (int*)sim->m_pCollisionInput;
    memcpy(&state, source, 0x50);
    state.result64 = 0;
    state.FUN_00cfa7d0(source);
    state.input50 = values[0];
    state.input54 = values[1];
    state.input58 = values[2];
    state.input5c = values[3];
    ++sim->m_iCriticalOperationsLockCount;
    hkpSimulation_collideEntitiesBroadPhaseDiscrete(arg1,arg2,sim);
    hkpSimulation_collideEntitiesNarrowPhaseDiscrete(arg1,arg2,&state,arg5);
    if (--sim->m_iCriticalOperationsLockCount == 0 && !sim->m_bBlockExecutingPendingOperations.m_cBooleanValue) {
        if (sim->m_iPendingOperationCount) sim->FUN_00c91120();
        if (sim->m_iPendingOperationQueueCount == 1 && sim->m_iQueuedOperationCount) sim->UpdateFields_00c91140();
    }
    if (state.result64) {
        FNVAudioHolder_CFA5F0* holder = hkMemoryRouter_getInstance();
        holder->audio10->v2(state.result64, 0x200);
    }
}
}  // namespace fnv_00cfa5f0
