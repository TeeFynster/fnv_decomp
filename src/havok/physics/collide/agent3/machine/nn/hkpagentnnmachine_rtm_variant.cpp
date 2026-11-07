// Keep this unit's compiler intrinsic representation: the SDK's additional byte
// arrays in __m128 introduce /GS cookies that the original RTM functions lack.
// Exe 0x00cfe370 _FUN_00cfe370: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
#define _INCLUDED_MM2
extern "C"
{
    LocalM128 _mm_setzero_ps(void);
    LocalM128 _mm_load_ps(const float*);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, int);
    LocalM128 _mm_load_ss(const float*);
    void _mm_store_ss(float*, LocalM128);
    void _mm_prefetch(const char*, int);
}

#include "../../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../../include/hkMemoryRouter.h"
#include "../../../../../../../include/hkSimdReal.h"
#include "../../../../../../../include/hkVector4.h"
#include "../../../../../../../include/hkTransform.h"
#include "../../../../../../../include/hkSweptTransform.h"
#include "../../../../../../../include/hkMotionState.h"

#include <new>
#include "../../../../../../../include/hkpCdBody.h"
#include "../../../../../../../include/hkpAgent3Input.h"
#include "../../../../../../../include/hkpCollisionDispatcher.h"
#include "../../../../../../../include/hkpContactMgr.h"
#include "../../../../../../../include/hkpCollisionAgent.h"
#include "../../../../../../../include/hkpAgentNnTrack.h"
#include "../../../../../../../include/hkpAgentNnEntry.h"

// The approved headers do not yet define the process agent input, machine
// entries, or process input/output.
// Keep one real-name definition of each required record below until they do.
__forceinline hkpCdBody::hkpCdBody() {}
__forceinline hkpCdBody::hkpCdBody(const hkpCdBody* parent, const hkTransform* t)
{
    m_parent = parent;
    m_pMotionState = t;
}
__forceinline const hkMotionState* hkpCdBody::GetMotionState() const
{
    return reinterpret_cast<const hkMotionState*>(m_pMotionState);
}
__forceinline const hkpShape* hkpCdBody::getShape() const { return m_pCollisionShape; }
__forceinline unsigned int hkpCdBody::getShapeKey() const { return m_uiCollisionShapeKey; }
__forceinline void hkpCdBody::SetCollisionShapeAndKey(const hkpShape* shape, unsigned int key)
{
    m_pCollisionShape = shape;
    m_uiCollisionShapeKey = key;
}
__forceinline hkAgent3::CleanupFunc hkpCollisionDispatcher::getAgent3CleanupFunc(int type)
{
    return m_kAgent3FunctionTable[type].m_pAgentFunction3;
}
__forceinline hkAgent3::ProcessFunc hkpCollisionDispatcher::getAgent3ProcessFunc(int type)
{
    return m_kAgent3FunctionTable[type].m_pAgentFunction8;
}
__forceinline hkAgent3::SepNormalFunc hkpCollisionDispatcher::getAgent3SepNormalFunc(int type)
{
    return m_kAgent3FunctionTable[type].m_pAgentFunction7;
}

// hkMemoryRouter is include/'s shared hkMemoryRouter (allocator at +0x10).

// These unit-local inline bodies retain the Havok operations used by the RTM code.
__forceinline hkSimdReal::hkSimdReal(float x)
{
    m_vValue = _mm_load_ss(&x);
}
__forceinline hkSimdReal::hkSimdReal(const LocalM128& x) : m_vValue(x) {}
__forceinline hkSimdReal::operator float() const
{
    float s;
    _mm_store_ss(&s, m_vValue);
    return s;
}
__forceinline LocalM128 hkSimdReal::broadcast() const
{
    return _mm_shuffle_ps(m_vValue, m_vValue, 0);
}
__forceinline void hkVector4::setZero4() { m_vComponents = _mm_setzero_ps(); }
__forceinline void hkVector4::setMul4(const hkSimdReal& r, const hkVector4& v1)
{
    m_vComponents = _mm_mul_ps(r.broadcast(), v1.m_vComponents);
}
__forceinline void hkVector4::setMul4(float r, const hkVector4& v1)
{
    setMul4(hkSimdReal(r), v1);
}
__forceinline void hkVector4::addMul4(const hkSimdReal& r, const hkVector4& v1)
{
    m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(r.broadcast(), v1.m_vComponents));
}
inline hkSimdReal hkVector4::dot4xyz1(const hkVector4& a) const
{
    LocalM128 linear = _mm_load_ps(reinterpret_cast<const float*>(&m_vComponents));
    LocalM128 sep = _mm_load_ps(reinterpret_cast<const float*>(&a));
    LocalM128 x2 = _mm_mul_ps(sep, linear);
    LocalM128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 85), x2);
    LocalM128 zwSum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 170), _mm_shuffle_ps(linear, linear, 255));
    return _mm_add_ps(xySum, zwSum);
}
__forceinline float& hkVector4::operator()(int a) { return reinterpret_cast<float*>(&m_vComponents)[a]; }
__forceinline const float& hkVector4::operator()(int a) const { return reinterpret_cast<const float*>(&m_vComponents)[a]; }
__forceinline LocalM128& hkVector4::getQuad() { return m_vComponents; }
__forceinline const LocalM128& hkVector4::getQuad() const { return m_vComponents; }
__forceinline hkTransform::hkTransform() {}
__forceinline const hkTransform& hkMotionState::getTransform() const { return m_kMotionTransform; }
__forceinline const hkSweptTransform& hkMotionState::getSweptTransform() const { return m_kSweptTransform; }
__forceinline float hkSweptTransform::getInvDeltaTime() const { return m_vCenterOfMass1(3); }

// src/havok/physics/collide/agent3/machine/nn/hkpagentnnmachine_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/agent3/machine/nn/hkpagentnnmachine.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/collide/agent3/machine/nn/hkpagentnnmachine.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent3/machine/nn/hkpagentnnmachine.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
typedef float hkReal;
typedef unsigned char hkUchar;
typedef LocalM128 hkQuadReal;

void __cdecl hkSweptTransformUtil_lerp2(const hkSweptTransform& st, hkReal t, hkTransform& out);

struct hkpProcessCollisionInput;
struct hkpProcessCollisionOutput;
struct hkpAgentNnEntry;
class hkpConstraintOwner;
extern float DAT_0104da48;
struct TrackContact
{
    hkVector4 position, normal;
    int id, unk24, unk28, unk2c;
};
struct TrackProperties
{
    float appliedImpulse, internalSolver;
    int material, internalData;
    unsigned int extendedData[7];
    int unk2c;
    TrackProperties() : appliedImpulse(0.0f), internalSolver(0.0f)
    {}
};
struct TrackToi
{
    hkVector4 position, normal;
    hkPadSpu<float> time;
    float separationVelocity;
    int unk28, unk2c;
    int cache0, cache1, cache2, cache3;
    TrackProperties properties;
    TrackToi() : time(DAT_0104da48)
    {}
};
struct hkpProcessCollisionOutput
{
    hkPadSpu<TrackContact*> m_pAlignedPairData;
    hkPadSpu<hkpConstraintOwner*> m_pConstraintOwner;
    int unk08, unk0c;
    TrackContact m_akContactPoints[256];
    TrackToi m_fTimeOfImpact;
    hkPadSpu<void*> m_akContactRecords;
    int unk3074, unk3078, unk307c;
    hkpProcessCollisionOutput(hkpConstraintOwner* owner)
    {
        m_pConstraintOwner = owner;
    }
    __forceinline void reset()
    {
        m_pAlignedPairData = &m_akContactPoints[0];
        m_fTimeOfImpact.time = DAT_0104da48;
        m_akContactRecords = 0;
    }
    __forceinline bool isEmpty() const
    {
        return (TrackContact*)m_pAlignedPairData == &m_akContactPoints[0];
    }
};



// The shared agent does not yet declare ProcessAgent. Dispatch its existing
// virtual slot without duplicating the class definition.
typedef void (__thiscall* ProcessCollisionAgentFunc)(hkpCollisionAgent*,
    const hkpCdBody&, const hkpCdBody&, const hkpProcessCollisionInput&,
    hkpProcessCollisionOutput&);

struct hkpAgent3ProcessInput : public hkpAgent3Input
{
    hkPadSpu<hkReal> m_fSubtypeValue;
    hkVector4 m_vSubtypePosition;
};

typedef void*(__cdecl* hkAgent3CleanupFunc)(hkpAgentNnEntry* entry, void* agentData, hkpContactMgr* mgr,
                                                hkpConstraintOwner& owner);
typedef void(__cdecl* hkAgent3SepNormalFunc)(const hkpAgent3Input& input, hkpAgentNnEntry* entry,
                                                 void* agentData, hkVector4& sepNormalOut);
typedef void*(__cdecl* hkAgent3ProcessFunc)(const hkpAgent3ProcessInput& input, hkpAgentNnEntry* entry,
                                                void* agentData, hkVector4* separatingNormalOut,
                                                hkpProcessCollisionOutput& result);

#include "../../../../../../../include/hkStepInfo.h"


struct hkpProcessCollisionInput
{
    hkPadSpu<hkpCollisionDispatcher*> m_pCollisionDispatcher;
    hkPadSpu<int> m_collisionQuality;
    hkPadSpu<hkReal> m_fScalar;
    int unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
    hkStepInfo m_pStepInfo;
    hkPadSpu<hkpCollisionQualityInfo*> m_pCollisionQualityInfo;

    inline hkReal getTolerance() const
    {
        return m_fScalar;
    }
};


struct hkpAgentNnMachinePaddedEntry : public hkpAgentNnEntry
{
    int m_uiRollingFrictionData;
    int m_padding3;
};

struct hkpAgentNnMachineTimEntry : public hkpAgentNnEntry
{
    hkReal m_fFloatValue;
    int unk1c;
    hkVector4 m_vSeparatingNormal;
};

struct hkAgentNnMachineBodyTemp
{
    hkpCdBody m_pBodyA;
    hkpCdBody m_pBodyB;
    hkTransform m_kTransformA;
    hkTransform m_kTransformB;
};

void* __cdecl hkAgentMachine_processTransformedShapes(void* h, void* a, void* b, unsigned int n, void* c);

enum
{
    STREAM_CALL_CFE3 = 2,
    STREAM_CALL_WITH_TIM_CFE3 = 4,
    STREAM_CALL_AGENT_CFE3 = 6,
    TRANSFORM_FLAG_CFE3 = 8,
    STREAM_CALL_WITH_TRANSFORM_CFE3 = 10,
    STREAM_CALL_WITH_TIM_WITH_TRANSFORM_CFE3 = 12,
    STREAM_CALL_AGENT_WITH_TRANSFORM_CFE3 = 14
};

static __forceinline void calcTimInfoCFE3(const hkMotionState& ms0, const hkMotionState& ms1, hkReal deltaTime,
                                          hkVector4& timOut)
{
    const hkSweptTransform& st0 = ms0.getSweptTransform();
    const hkSweptTransform& st1 = ms1.getSweptTransform();

    hkVector4 diff0;
    diff0.setSub4(st0.m_vCenterOfMass0, st0.m_vCenterOfMass1);
    hkVector4 diff1;
    diff1.setSub4(st1.m_vCenterOfMass1, st1.m_vCenterOfMass0);

    hkReal f0 = deltaTime * st0.getInvDeltaTime();
    hkReal f1 = deltaTime * st1.getInvDeltaTime();

    timOut.setMul4(f0, diff0);
    timOut.addMul4(f1, diff1);
    timOut(3) = f0 * ms0.m_kDeltaAngle(3) * ms0.m_fObjectRadius + f1 * ms1.m_kDeltaAngle(3) * ms1.m_fObjectRadius;
}

static __forceinline void initInputAtTimeCFE3(hkpAgent3Input& in, hkAgentNnMachineBodyTemp& bodyTemp,
                                              hkpAgent3Input& out)
{
    hkSweptTransformUtil_lerp2(in.m_pBodyA->GetMotionState()->getSweptTransform(), in.m_pRayCastInput->m_pStepInfo.m_uiStartTime,
                 bodyTemp.m_kTransformA);
    hkSweptTransformUtil_lerp2(in.m_pBodyB->GetMotionState()->getSweptTransform(), in.m_pRayCastInput->m_pStepInfo.m_uiStartTime,
                 bodyTemp.m_kTransformB);

    out.m_pBodyA = &bodyTemp.m_pBodyA;
    out.m_pBodyB = &bodyTemp.m_pBodyB;
    out.m_pContactManager = in.m_pContactManager;
    out.m_pRayCastInput = in.m_pRayCastInput;

    bodyTemp.m_pBodyA.SetCollisionShapeAndKey(in.m_pBodyA->getShape(), in.m_pBodyA->getShapeKey());
    bodyTemp.m_pBodyB.SetCollisionShapeAndKey(in.m_pBodyB->getShape(), in.m_pBodyB->getShapeKey());
    ::new (&bodyTemp.m_pBodyA) hkpCdBody(in.m_pBodyA, &bodyTemp.m_kTransformA);
    ::new (&bodyTemp.m_pBodyB) hkpCdBody(in.m_pBodyB, &bodyTemp.m_kTransformB);

    out.m_kTransform.hkTransform_setMulInverseMul(bodyTemp.m_kTransformA, bodyTemp.m_kTransformB);
}

extern "C"
{
// @fnv 0x00cfe370
// src: XBOX_PDB 0x00cfe370
    static __declspec(noinline) void __cdecl hkAgentNnMachine_InlineProcessAgent(hkpAgentNnEntry* entry,
                                                          const hkpProcessCollisionInput& input, int& numTim,
                                                          hkpProcessCollisionOutput& output, hkpContactMgr* mgr)
    {
        const hkpCdBody* cdBodyA = entry->getCollidableA();
        const hkpCdBody* cdBodyB = entry->getCollidableB();

        // Raw SIMD storage keeps these uninitialized arrays free of added /GS checks.
        LocalM128 motionStatesAStorage[sizeof(hkMotionState) * 4 / sizeof(LocalM128)];

        hkMotionState* motionStatesA = reinterpret_cast<hkMotionState*>(motionStatesAStorage);
        LocalM128 motionStatesBStorage[sizeof(hkMotionState) * 4 / sizeof(LocalM128)];
        hkMotionState* motionStatesB = reinterpret_cast<hkMotionState*>(motionStatesBStorage);
        hkpCdBody cdBodiesA[4];
        hkpCdBody cdBodiesB[4];

        int command = entry->m_ucAgentType;
    commandSwitch:
        switch (command)
        {
        case STREAM_CALL_WITH_TRANSFORM_CFE3:
        case STREAM_CALL_WITH_TIM_WITH_TRANSFORM_CFE3:
        case STREAM_CALL_AGENT_WITH_TRANSFORM_CFE3: {
            hkUchar dummy;
            cdBodyA = (const hkpCdBody*)hkAgentMachine_processTransformedShapes((void*)cdBodyA, cdBodiesA, motionStatesA, 4, &dummy);
            cdBodyB = (const hkpCdBody*)hkAgentMachine_processTransformedShapes((void*)cdBodyB, cdBodiesB, motionStatesB, 4, &dummy);
            command = hkUchar(command) & hkUchar(~TRANSFORM_FLAG_CFE3);
            goto commandSwitch;
        }

        case STREAM_CALL_AGENT_CFE3: {
            hkpCollisionAgent* agent =
                *reinterpret_cast<hkpCollisionAgent**>(static_cast<hkpAgentNnMachinePaddedEntry*>(entry) + 1);
            (*reinterpret_cast<ProcessCollisionAgentFunc**>(agent))[6](agent, *cdBodyA, *cdBodyB, input, output);
            break;
        }

        case STREAM_CALL_CFE3: {
            hkpAgentNnMachinePaddedEntry* e = static_cast<hkpAgentNnMachinePaddedEntry*>(entry);
            hkpAgent3ProcessInput in3;
            in3.m_pBodyA = cdBodyA;
            in3.m_pBodyB = cdBodyB;
            in3.m_pContactManager = entry->m_pContactManager;
            in3.m_pRayCastInput = &input;

            const hkMotionState* msA = in3.m_pBodyA->GetMotionState();
            const hkMotionState* msB = in3.m_pBodyB->GetMotionState();
            calcTimInfoCFE3(*msA, *msB, in3.m_pRayCastInput->m_pStepInfo.m_fTimeStep, in3.m_vSubtypePosition);
            in3.m_kTransform.hkTransform_setMulInverseMul(msA->getTransform(), msB->getTransform());

            void* agentData = e + 1;
            (reinterpret_cast<hkAgent3ProcessFunc>(input.m_pCollisionDispatcher->getAgent3ProcessFunc(entry->m_ucNnTrackType)))(in3, entry, agentData, 0,
                                                                                       output);
            break;
        }

        case STREAM_CALL_WITH_TIM_CFE3: {
            hkpAgentNnMachineTimEntry* e = static_cast<hkpAgentNnMachineTimEntry*>(entry);
            hkpAgent3ProcessInput in3;
            in3.m_pBodyA = cdBodyA;
            in3.m_pBodyB = cdBodyB;
            in3.m_pContactManager = entry->m_pContactManager;
            in3.m_pRayCastInput = &input;

            const hkMotionState* msA = in3.m_pBodyA->GetMotionState();
            const hkMotionState* msB = in3.m_pBodyB->GetMotionState();
            calcTimInfoCFE3(*msA, *msB, in3.m_pRayCastInput->m_pStepInfo.m_fTimeStep, in3.m_vSubtypePosition);

            void* agentData = e + 1;
            hkReal dist;
            if (e->m_fFloatValue != input.m_pStepInfo.m_uiStartTime)
            {
                if (!input.m_pCollisionQualityInfo->m_iQualityInfoValue10)
                {
                    e->m_fFloatValue = input.m_pStepInfo.m_fEndTime;
                    dist = -3.40282e+38f;
                    e->m_vSeparatingNormal.setZero4();
                    e->m_vSeparatingNormal(3) = dist;
                    goto PROCESS_AT_T1;
                }
                hkAgentNnMachineBodyTemp bodyTemp;
                hkpAgent3Input in3b;
                initInputAtTimeCFE3(in3, bodyTemp, in3b);
                (reinterpret_cast<hkAgent3SepNormalFunc>(input.m_pCollisionDispatcher->getAgent3SepNormalFunc(entry->m_ucNnTrackType)))(in3b, entry, agentData,
                                                                                             e->m_vSeparatingNormal);
            }

            hkVector4& vSeparatingNormal = e->m_vSeparatingNormal;
            const hkReal worst = in3.m_vSubtypePosition.dot4xyz1(vSeparatingNormal);
            e->m_fFloatValue = input.m_pStepInfo.m_fEndTime;
            dist = vSeparatingNormal(3) - worst;
            if (dist >= input.getTolerance())
            {
                e->m_vSeparatingNormal(3) = dist;
                if (entry->m_usNumContactPoints)
                {
                    (reinterpret_cast<hkAgent3CleanupFunc>(input.m_pCollisionDispatcher->getAgent3CleanupFunc(entry->m_ucNnTrackType)))(
                        entry, agentData, in3.m_pContactManager, *output.m_pConstraintOwner);
                }
                numTim++;
                break;
            }
        PROCESS_AT_T1:
            in3.m_fSubtypeValue = dist;
            in3.m_kTransform.hkTransform_setMulInverseMul(msA->getTransform(), msB->getTransform());
            (reinterpret_cast<hkAgent3ProcessFunc>(input.m_pCollisionDispatcher->getAgent3ProcessFunc(entry->m_ucNnTrackType)))(in3, entry, agentData,
                                                                                       &e->m_vSeparatingNormal, output);
            break;
        }

        default:
            break;
        }
    }
}
void hkAgentNnMachine_ProcessAgentCFE3(hkpAgentNnEntry* entry, const hkpProcessCollisionInput& input,
                                       hkpProcessCollisionOutput& output, hkpContactMgr* mgr)
{
    int numTim = 0;
    hkAgentNnMachine_InlineProcessAgent(entry, input, numTim, output, mgr);
}

extern "C"
{

    void _ReadBarrier();
    void _ReadWriteBarrier();
    void _WriteBarrier();
    void _ReadWriteBarrier();

}

struct hkpAgentNnSector
{
    unsigned char data[512];
    hkpAgentNnEntry* getBegin()
    {
        return reinterpret_cast<hkpAgentNnEntry*>(&data[0]);
    }
    hkpAgentNnEntry* GetStreamEnd()
    {
        return reinterpret_cast<hkpAgentNnEntry*>(&data[512]);
    }
};
struct TrackMonitor
{
    char* start;
    char* end;
    char* capacity;
    char* limit;
};
extern unsigned int DAT_0126835c;
extern unsigned int DAT_01269200;
extern const float DAT_0104e148 = -3.40282e+38f;
extern const char DAT_010cc9d0[];
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned int);
struct PreviousBodies
{
    hkpCdBody a, b;
    hkTransform ta, tb;
};
static __forceinline void fillPrevious(const hkpAgent3Input& current, PreviousBodies& b, hkpAgent3Input& previous)
{
    hkSweptTransformUtil_lerp2(current.m_pBodyA->GetMotionState()->getSweptTransform(),
                 current.m_pRayCastInput->m_pStepInfo.m_uiStartTime, b.ta);
    hkSweptTransformUtil_lerp2(current.m_pBodyB->GetMotionState()->getSweptTransform(),
                 current.m_pRayCastInput->m_pStepInfo.m_uiStartTime, b.tb);
    previous.m_pBodyA = &b.a;
    previous.m_pBodyB = &b.b;
    previous.m_pContactManager = current.m_pContactManager;
    previous.m_pRayCastInput = current.m_pRayCastInput;
    b.a.SetCollisionShapeAndKey(current.m_pBodyA->getShape(), current.m_pBodyA->getShapeKey());
    b.b.SetCollisionShapeAndKey(current.m_pBodyB->getShape(), current.m_pBodyB->getShapeKey());
    ::new (&b.a) hkpCdBody(current.m_pBodyA, &b.ta);
    ::new (&b.b) hkpCdBody(current.m_pBodyB, &b.tb);
    previous.m_kTransform.hkTransform_setMulInverseMul(b.ta, b.tb);
}
static __forceinline void motionDelta(const hkMotionState& a, const hkMotionState& b, hkReal dt,
                                      hkVector4& out)
{
    hkVector4 da, db;
    da.setSub4(a.getSweptTransform().m_vCenterOfMass0, a.getSweptTransform().m_vCenterOfMass1);
    db.setSub4(b.getSweptTransform().m_vCenterOfMass1, b.getSweptTransform().m_vCenterOfMass0);
    hkReal fa = dt * a.getSweptTransform().getInvDeltaTime();
    hkReal fb = dt * b.getSweptTransform().getInvDeltaTime();
    out.setMul4(fa, da);
    out.addMul4(fb, db);
    out(3) = fa * a.m_kDeltaAngle(3) * a.m_fObjectRadius + fb * b.m_kDeltaAngle(3) * b.m_fObjectRadius;
}
static __forceinline void processEntry(hkpAgentNnEntry* e, const hkpProcessCollisionInput& context, int& skipped,
                                       hkpProcessCollisionOutput& out)
{
    const hkpCdBody* a = e->getCollidableA();
    const hkpCdBody* b = e->getCollidableB();
    // Raw SIMD storage keeps these uninitialized arrays free of added /GS checks.
    LocalM128 maStorage[sizeof(hkMotionState) * 4 / sizeof(LocalM128)];
    hkMotionState* ma = reinterpret_cast<hkMotionState*>(maStorage);
    LocalM128 mbStorage[sizeof(hkMotionState) * 4 / sizeof(LocalM128)];
    hkMotionState* mb = reinterpret_cast<hkMotionState*>(mbStorage);
    hkpCdBody ba[4], bb[4];
    int cmd = e->m_ucAgentType;
again:
    switch (cmd)
    {
    case 10:
    case 12:
    case 14: {
        hkPadSpu<hkUchar> transformed;
        a = (const hkpCdBody*)hkAgentMachine_processTransformedShapes((void*)a, ba, ma, 4, &transformed);
        b = (const hkpCdBody*)hkAgentMachine_processTransformedShapes((void*)b, bb, mb, 4, &transformed);
        cmd = hkUchar(cmd) & hkUchar(~8);
        goto again;
    }
    case 6: {
        hkpCollisionAgent* agent =
            *reinterpret_cast<hkpCollisionAgent**>(static_cast<hkpAgentNnMachinePaddedEntry*>(e) + 1);
        (*reinterpret_cast<ProcessCollisionAgentFunc**>(agent))[6](agent, *a, *b, context, out);
        break;
    }
    case 2: {
        hkpAgent3ProcessInput query;
        query.m_pBodyA = a;
        query.m_pBodyB = b;
        query.m_pContactManager = e->m_pContactManager;
        query.m_pRayCastInput = &context;
        const hkMotionState* am = query.m_pBodyA->GetMotionState();
        const hkMotionState* bm = query.m_pBodyB->GetMotionState();
        motionDelta(*am, *bm, query.m_pRayCastInput->m_pStepInfo.m_fTimeStep, query.m_vSubtypePosition);
        query.m_kTransform.hkTransform_setMulInverseMul(am->getTransform(), bm->getTransform());
        (reinterpret_cast<hkAgent3ProcessFunc>(context.m_pCollisionDispatcher->getAgent3ProcessFunc(e->m_ucNnTrackType)))(
            query, e, static_cast<hkpAgentNnMachinePaddedEntry*>(e) + 1, 0, out);
        break;
    }
    case 4: {
        hkpAgentNnMachineTimEntry* timed = static_cast<hkpAgentNnMachineTimEntry*>(e);
        hkpAgent3ProcessInput query;
        query.m_pBodyA = a;
        query.m_pBodyB = b;
        query.m_pContactManager = e->m_pContactManager;
        query.m_pRayCastInput = &context;
        const hkMotionState* am = query.m_pBodyA->GetMotionState();
        const hkMotionState* bm = query.m_pBodyB->GetMotionState();
        motionDelta(*am, *bm, query.m_pRayCastInput->m_pStepInfo.m_fTimeStep, query.m_vSubtypePosition);
        void* data = timed + 1;
        hkReal distance;
        if (timed->m_fFloatValue != context.m_pStepInfo.m_uiStartTime)
        {
            if (!context.m_pCollisionQualityInfo->m_iQualityInfoValue10)
            {
                timed->m_fFloatValue = context.m_pStepInfo.m_fEndTime;
                distance = -3.40282e+38f;
                timed->m_vSeparatingNormal.setZero4();
                timed->m_vSeparatingNormal(3) = distance;
                goto collide;
            }
            PreviousBodies bodies;
            hkpAgent3Input previous;
            fillPrevious(query, bodies, previous);
            (reinterpret_cast<hkAgent3SepNormalFunc>(context.m_pCollisionDispatcher->getAgent3SepNormalFunc(e->m_ucNnTrackType)))(previous, e, data,
                                                                                       timed->m_vSeparatingNormal);
        }
        {
            hkVector4& normal = timed->m_vSeparatingNormal;
            LocalM128 velocity = _mm_load_ps(&query.m_vSubtypePosition(0));
            LocalM128 product = _mm_mul_ps(normal.getQuad(), velocity);
            LocalM128 z = _mm_shuffle_ps(product, product, 170);
            LocalM128 w = _mm_shuffle_ps(velocity, velocity, 255);
            LocalM128 y = _mm_shuffle_ps(product, product, 85);
            LocalM128 zw = _mm_add_ss(z, w);
            LocalM128 xy = _mm_add_ss(y, product);
            LocalM128 total = _mm_add_ps(zw, xy);
            hkReal movement;
            _mm_store_ss(&movement, total);
            timed->m_fFloatValue = context.m_pStepInfo.m_fEndTime;
            distance = normal(3) - movement;
            if (distance >= context.getTolerance())
            {
                timed->m_vSeparatingNormal(3) = distance;
                if (e->m_usNumContactPoints)
                    (reinterpret_cast<hkAgent3CleanupFunc>(context.m_pCollisionDispatcher->getAgent3CleanupFunc(e->m_ucNnTrackType)))(
                        e, data, query.m_pContactManager, *out.m_pConstraintOwner);
                ++skipped;
                break;
            }
        }
    collide:
        query.m_fSubtypeValue = distance;
        query.m_kTransform.hkTransform_setMulInverseMul(am->getTransform(), bm->getTransform());
        (reinterpret_cast<hkAgent3ProcessFunc>(context.m_pCollisionDispatcher->getAgent3ProcessFunc(e->m_ucNnTrackType)))(query, e, data,
                                                                                 &timed->m_vSeparatingNormal, out);
        break;
    }
    }
}
// @fnv 0x00cff3c0
// src: GUESS 0x00cff3c0 (confidence: low)
void __cdecl hkpConstraintOwner_ProcessEntries_00cff3c0(hkpConstraintOwner* owner, hkpAgentNnTrack& track, const hkpProcessCollisionInput& context)
{
    int skipped = 0;
    hkpProcessCollisionOutput result(owner);
    for (int index = 0; index < track.m_kSectors.GetLogicalSize();)
    {
        hkpAgentNnSector* sector = track.m_kSectors[index];
        hkpAgentNnEntry* entry = sector->getBegin();
        ++index;
        hkpAgentNnEntry* end = (index == track.m_kSectors.GetLogicalSize())
                                      ? (hkpAgentNnEntry*)((char*)entry + track.m_iBytesUsedInLastSector)
                                      : sector->GetStreamEnd();
        for (; entry < end; entry = (hkpAgentNnEntry*)((char*)entry + entry->m_iElementCount))
        {
            hkpCdBody* a = entry->getCollidableA();
            hkpCdBody* b = entry->getCollidableB();
            result.reset();
            _mm_prefetch((const char*)entry + 128, 0);
            _mm_prefetch((const char*)entry->m_pContactManager, 0);
            processEntry(entry, context, skipped, result);
            if (DAT_01269200 == 1)
                return;
            if (!result.isEmpty())
                entry->m_pContactManager->processContact(*a, *b, context, result);
        }
    }
    TrackMonitor& stream = *(TrackMonitor*)TlsGetValue(DAT_0126835c);
    char* cur = stream.end;
    if (cur < stream.limit)
    {
        *(const char**)cur = DAT_010cc9d0;
        *(float*)(cur + 4) = float(skipped);
        stream.end = cur + 8;
    }
}

namespace ProcessAgentCFEDD0 {

typedef ::LocalM128 hkQuadReal;

static __forceinline void timedEstimateProcessAgentCFEDD0(const hkMotionState& a,
                                                          const hkMotionState& b, float dt,
                                                          hkVector4& out, float& sb)
{
    hkVector4 da, db;
    da.setSub4(a.m_kSweptTransform.m_vCenterOfMass0, a.m_kSweptTransform.m_vCenterOfMass1);
    db.setSub4(b.m_kSweptTransform.m_vCenterOfMass1, b.m_kSweptTransform.m_vCenterOfMass0);
    float sa = dt * a.m_kSweptTransform.getInvDeltaTime();
    sb = dt * b.m_kSweptTransform.getInvDeltaTime();
    out.setMul4(sa, da);
    out.addMul4(sb, db);
    out(3) = sa * a.m_kDeltaAngle(3) * a.m_fObjectRadius + sb * b.m_kDeltaAngle(3) * b.m_fObjectRadius;
}
static __forceinline void motionEstimateProcessAgentCFEDD0(const hkMotionState& a,
                                                           const hkMotionState& b, float dt,
                                                           hkVector4& out)
{
    hkVector4 da, db;
    da.setSub4(a.m_kSweptTransform.m_vCenterOfMass0, a.m_kSweptTransform.m_vCenterOfMass1);
    db.setSub4(b.m_kSweptTransform.m_vCenterOfMass1, b.m_kSweptTransform.m_vCenterOfMass0);
    float sa = dt * a.m_kSweptTransform.getInvDeltaTime();
    float sb = dt * b.m_kSweptTransform.getInvDeltaTime();
    out.setMul4(sa, da);
    out.addMul4(sb, db);
    out(3) = sa * a.m_kDeltaAngle(3) * a.m_fObjectRadius + sb * b.m_kDeltaAngle(3) * b.m_fObjectRadius;
}
static __forceinline void previousInputProcessAgentCFEDD0(hkpAgent3Input& current,
                                                          hkAgentNnMachineBodyTemp& state,
                                                          hkpAgent3Input& previous)
{
    ::hkSweptTransformUtil_lerp2(current.m_pBodyA->GetMotionState()->getSweptTransform(),
                 current.m_pRayCastInput->m_pStepInfo.m_uiStartTime, state.m_kTransformA);
    ::hkSweptTransformUtil_lerp2(current.m_pBodyB->GetMotionState()->getSweptTransform(),
                 current.m_pRayCastInput->m_pStepInfo.m_uiStartTime, state.m_kTransformB);
    previous.m_pBodyA = &state.m_pBodyA;
    previous.m_pBodyB = &state.m_pBodyB;
    previous.m_pContactManager = current.m_pContactManager;
    previous.m_pRayCastInput = current.m_pRayCastInput;
    state.m_pBodyA.SetCollisionShapeAndKey(current.m_pBodyA->getShape(), current.m_pBodyA->getShapeKey());
    state.m_pBodyB.SetCollisionShapeAndKey(current.m_pBodyB->getShape(), current.m_pBodyB->getShapeKey());
    ::new (&state.m_pBodyA) hkpCdBody(current.m_pBodyA, &state.m_kTransformA);
    ::new (&state.m_pBodyB) hkpCdBody(current.m_pBodyB, &state.m_kTransformB);
    previous.m_kTransform.hkTransform_setMulInverseMul(state.m_kTransformA, state.m_kTransformB);
}
extern float DAT_0104e148;
// @fnv 0x00cfedd0
// src: XBOX_PDB 0x00cfedd0
extern "C" void __cdecl hkAgentNnMachine_ProcessAgent(hkpAgentNnEntry* entry,
                                     const hkpProcessCollisionInput& input,
                                     hkpProcessCollisionOutput& output)
{
    const hkpCdBody* a = entry->getCollidableA();
    const hkpCdBody* b = entry->getCollidableB();
    // Raw SIMD storage keeps these uninitialized arrays free of added /GS checks.
    LocalM128 motionsAStorage[sizeof(hkMotionState) * 4 / sizeof(LocalM128)];
    hkMotionState* motionsA = reinterpret_cast<hkMotionState*>(motionsAStorage);
    LocalM128 motionsBStorage[sizeof(hkMotionState) * 4 / sizeof(LocalM128)];
    hkMotionState* motionsB = reinterpret_cast<hkMotionState*>(motionsBStorage);
    hkpCdBody bodiesA[4], bodiesB[4];
    int command = entry->m_ucAgentType;
again:
    switch (command)
    {
    case 10:
    case 12:
    case 14: {
        hkUchar transformed;
        a = (const hkpCdBody*)::hkAgentMachine_processTransformedShapes((void*)a, bodiesA, motionsA, 4,
                                                                                 &transformed);
        b = (const hkpCdBody*)::hkAgentMachine_processTransformedShapes((void*)b, bodiesB, motionsB, 4,
                                                                                 &transformed);
        command = (hkUchar)command & 0xf7;
        goto again;
    }
    case 6: {
        hkpAgentNnMachinePaddedEntry* padded = (hkpAgentNnMachinePaddedEntry*)entry;
        hkpCollisionAgent* agent = *(hkpCollisionAgent**)(padded + 1);
        (*reinterpret_cast<ProcessCollisionAgentFunc**>(agent))[6](agent, *a, *b, input, output);
        break;
    }
    case 2: {
        hkpAgent3ProcessInput process;
        process.m_pBodyA = a;
        process.m_pBodyB = b;
        process.m_pContactManager = entry->m_pContactManager;
        process.m_pRayCastInput = &input;
        const hkMotionState* ma = process.m_pBodyA->GetMotionState();
        const hkMotionState* mb = process.m_pBodyB->GetMotionState();
        motionEstimateProcessAgentCFEDD0(*ma, *mb, process.m_pRayCastInput->m_pStepInfo.m_fTimeStep,
                                         process.m_vSubtypePosition);
        process.m_kTransform.hkTransform_setMulInverseMul(ma->getTransform(), mb->getTransform());
        void* data = (hkpAgentNnMachinePaddedEntry*)entry + 1;
        (reinterpret_cast<hkAgent3ProcessFunc>(input.m_pCollisionDispatcher->getAgent3ProcessFunc(entry->m_ucNnTrackType)))(process, entry, data, 0, output);
        break;
    }
    case 4: {
        hkpAgentNnMachineTimEntry* timed = (hkpAgentNnMachineTimEntry*)entry;
        hkpAgent3ProcessInput process;
        process.m_pBodyA = a;
        process.m_pBodyB = b;
        process.m_pContactManager = entry->m_pContactManager;
        process.m_pRayCastInput = &input;
        const hkMotionState* ma = process.m_pBodyA->GetMotionState();
        const hkMotionState* mb = process.m_pBodyB->GetMotionState();
        float distance;
        timedEstimateProcessAgentCFEDD0(*ma, *mb, process.m_pRayCastInput->m_pStepInfo.m_fTimeStep,
                                        process.m_vSubtypePosition, distance);
        void* data = timed + 1;
        if (timed->m_fFloatValue != input.m_pStepInfo.m_uiStartTime)
        {
            if (!input.m_pCollisionQualityInfo->m_iQualityInfoValue10)
            {
                timed->m_fFloatValue = input.m_pStepInfo.m_fEndTime;
                distance = -3.40282e+38f;
                timed->m_vSeparatingNormal.setZero4();
                timed->m_vSeparatingNormal(3) = distance;
                goto processAtEnd;
            }
            hkAgentNnMachineBodyTemp state;
            hkpAgent3Input previous;
            previousInputProcessAgentCFEDD0(process, state, previous);
            (reinterpret_cast<hkAgent3SepNormalFunc>(input.m_pCollisionDispatcher->getAgent3SepNormalFunc(entry->m_ucNnTrackType)))(previous, entry, data,
                                                                                         timed->m_vSeparatingNormal);
        }
        {
            hkVector4& plane = timed->m_vSeparatingNormal;
            float projected = process.m_vSubtypePosition.dot4xyz1(plane);
            timed->m_fFloatValue = input.m_pStepInfo.m_fEndTime;
            distance = plane(3) - projected;
            if (distance >= input.getTolerance())
            {
                timed->m_vSeparatingNormal(3) = distance;
                if (entry->m_usNumContactPoints)
                    (reinterpret_cast<hkAgent3CleanupFunc>(input.m_pCollisionDispatcher->getAgent3CleanupFunc(entry->m_ucNnTrackType)))(
                        entry, data, process.m_pContactManager, *output.m_pConstraintOwner);
                break;
            }
        }
    processAtEnd:
        process.m_fSubtypeValue = distance;
        process.m_kTransform.hkTransform_setMulInverseMul(ma->getTransform(), mb->getTransform());
        (reinterpret_cast<hkAgent3ProcessFunc>(input.m_pCollisionDispatcher->getAgent3ProcessFunc(entry->m_ucNnTrackType)))(process, entry, data,
                                                                                   &timed->m_vSeparatingNormal, output);
        break;
    }
    default:
        break;
    }
}

}
