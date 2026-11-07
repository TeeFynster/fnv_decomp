#define FNV64_HKVECTOR4_OWN_ADD4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_ADDMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkSimdReal   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_MUL4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETADD4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETMUL4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SETSUB4_consthkVector4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
#define FNV64_HKVECTOR4_OWN_SUB4_consthkVector4   // this unit keeps the out-of-line hkVector4 form
// src/havok/physics/vehicle/hkpvehicleinstance_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/vehicle/hkpvehicleinstance.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/vehicle/hkpvehicleinstance.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/hkpvehicleinstance.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
// Keep the RTM intrinsic representation: the CRT union adds byte arrays that
// enable /GS buffer instrumentation for local SIMD vectors.
#define _INCLUDED_MM2
// Exe 0x00e371d0 FUN_00e371d0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) { float m128_f32[4]; unsigned __int64 m128_u64[2]; } __m128, LocalM128;
#include "../../../../include/Vec4.h"
#include "../../../../include/hkArray.h"
#include "../../../../include/hkpVehicleInstance.h"
#include "../../../../include/hkpVehicleInstanceWheelInfo.h"
#include "../../../../include/hkpVehicleData.h"
#include "../../../../include/hkBool.h"
#include "../../../../include/hkMemoryAllocator.h"
#include "../../../../include/hkReferencedObject.h"
#include "../../../../include/hkStringPtr.h"
#include "../../../../include/hkpEntity.h"
#include "../../../../include/hkpRigidBody.h"
#include "../../../../include/hkpWorld.h"
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_0126835c;
struct VUC_Mon { char* m_kRayStart; char* m_kRayEnd; char* m_cap; char* m_capMinus16; };
struct VUC_Timer { const char* m_name; unsigned int m_ticks; unsigned int m_auiShapeKeys; };
// The other declarations copied from hkpvehicleinstance.cpp belonged to functions
// outside this RTM variant; the five functions below use the shared class layouts.
struct __declspec(align(16)) VehicleVector4 { float x, y, z, w; };
extern const float DAT_01011d78;
extern "C" LocalM128 _mm_add_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_mul_ps(LocalM128, LocalM128);
extern "C" LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);

extern "C" LocalM128 _mm_load_ss(const float*);
extern "C" LocalM128 _mm_set_ps1(float);
inline LocalM128 splat(float f) { LocalM128 v = _mm_load_ss(&f); return _mm_shuffle_ps(v, v, 0); }
extern "C" LocalM128 _mm_add_ss(LocalM128, LocalM128);
extern "C" void _mm_store_ss(float*, LocalM128);



struct SimdScalar { LocalM128 q; SimdScalar(float f) : q(_mm_load_ss(&f)) {} LocalM128 broadcast() const { return _mm_shuffle_ps(q,q,0); } };
extern "C" double __cdecl sqrt(double);

// hkpVehicleInstance.h does not declare this unit's wheel-impulse helper.
struct WheelImpulseVehicle : hkpVehicleInstance {
    void ComputeValues_00e371d0(float deltaTime, int wheelNum, float force);
};

// @fnv 0x00e371d0
// src: GUESS 0x00e371d0 (confidence: low)
void WheelImpulseVehicle::ComputeValues_00e371d0(float deltaTime, int wheelNum, float force) {
    float impulseScalar = force * deltaTime;
    hkpVehicleInstanceWheelInfo& wheelInfo = this->m_kWheelInfoArray.m_data[wheelNum];
    VehicleVector4 impulse;

    SimdScalar scalar(impulseScalar);
    *(LocalM128*)&impulse = _mm_mul_ps(scalar.broadcast(), *(LocalM128*)&wheelInfo.unk10);

    if (force > 0.0f) {
        hkpEntity* entity = this->m_pEntity;
        entity->activate_00c9c1d0();
        entity->m_pMotionState.ApplyImpulseAtPoint(reinterpret_cast<const hkVector4&>(impulse), reinterpret_cast<const hkVector4&>(wheelInfo.unk50));
    }

    hkpRigidBody* contactBody = wheelInfo.m_pUserData;
    if (contactBody) {
        float negMult = -this->m_data->m_kWheelParams.m_data[wheelNum].m_fMaxFrictionForce;
        *(LocalM128*)&impulse = _mm_mul_ps(splat(negMult), *(LocalM128*)&impulse);

        float mass = contactBody->m_pMotionState.GetMassValue();
        float maxImpulse = (this->m_data->m_kWheelParams.m_data[wheelNum].m_fFrictionEqualizer * mass) * deltaTime;

        LocalM128 m2 = _mm_mul_ps(*(LocalM128*)&impulse, *(LocalM128*)&impulse);
        LocalM128 sum = _mm_add_ss(_mm_shuffle_ps(m2, m2, 0xaa), _mm_add_ss(_mm_shuffle_ps(m2, m2, 0x55), m2));
        float lenSq;
        _mm_store_ss(&lenSq, sum);

        if (maxImpulse * maxImpulse < lenSq) {
            float invLen = 1.0f / (float)sqrt(lenSq);
            float scale = invLen * maxImpulse;
            *(LocalM128*)&impulse = _mm_mul_ps(splat(scale), *(LocalM128*)&impulse);
        }

        contactBody->m_pMotionState.ApplyImpulseAtPoint(reinterpret_cast<const hkVector4&>(impulse), reinterpret_cast<const hkVector4&>(wheelInfo.unk50));
    }
}

extern "C" {
LocalM128 _mm_load_ps(const float*);
void _mm_store_ps(float*, LocalM128);
LocalM128 _mm_load_ss(const float*);
void _mm_store_ss(float*, LocalM128);
LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
LocalM128 _mm_add_ps(LocalM128, LocalM128);
LocalM128 _mm_sub_ps(LocalM128, LocalM128);
LocalM128 _mm_mul_ps(LocalM128, LocalM128);
LocalM128 _mm_add_ss(LocalM128, LocalM128);
LocalM128 _mm_sub_ss(LocalM128, LocalM128);
LocalM128 _mm_mul_ss(LocalM128, LocalM128);
LocalM128 _mm_cmpeq_ss(LocalM128, LocalM128);
LocalM128 _mm_andnot_ps(LocalM128, LocalM128);
LocalM128 _mm_rsqrt_ss(LocalM128);
LocalM128 _mm_set_ss(float);
}



extern const float DAT_0104da4c = 1.1920928955078125e-7f;

struct __declspec(align(16)) FnvVec {
    float x;
    float y;
    float z;
    float w;
};



struct FnvAxleParams {
    FnvVec m_kFirstVector;
    FnvVec m_kSecondAxleVector;
    FnvVec m_kThirdVector;
    void* m_pFirstPointer;
    void* m_pSecondPointer;
    float m_fFirstScalar;
    float m_fSecondScalar;
    float m_fThirdValue;
    float m_fFourthValue;
    float m_fFifthScalar;
    float m_fSixthValue;
    unsigned char m_ucValue;
};

static __forceinline LocalM128 fnv_load(const FnvVec& v)
{
    return _mm_load_ps(&v.x);
}

static __forceinline void fnv_store(FnvVec& v, LocalM128 m)
{
    _mm_store_ps(&v.x, m);
}


static __forceinline float fnv_len2(LocalM128 v)
{
    LocalM128 sq = _mm_mul_ps(v, v);
    LocalM128 y = _mm_shuffle_ps(sq, sq, 0x55);
    LocalM128 sum = _mm_add_ss(y, sq);
    LocalM128 z = _mm_shuffle_ps(sq, sq, 0xaa);
    sum = _mm_add_ss(z, sum);
    float out;
    _mm_store_ss(&out, sum);
    return out;
}

static __forceinline LocalM128 fnv_normalize3(LocalM128 v)
{
    LocalM128 sq = _mm_mul_ps(v, v);
    LocalM128 y = _mm_shuffle_ps(sq, sq, 0x55);
    LocalM128 sum = _mm_add_ss(y, sq);
    LocalM128 z = _mm_shuffle_ps(sq, sq, 0xaa);
    LocalM128 len2 = _mm_add_ss(z, sum);
    LocalM128 r = _mm_rsqrt_ss(len2);
    LocalM128 eq = _mm_cmpeq_ss(len2, _mm_set_ss(DAT_01011d78));
    LocalM128 xy = _mm_mul_ss(_mm_mul_ss(len2, r), r);
    LocalM128 t = _mm_sub_ss(_mm_set_ss(3.0f), xy);
    LocalM128 inv = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), r), t);
    inv = _mm_andnot_ps(eq, inv);
    inv = _mm_shuffle_ps(inv, inv, 0);
    return _mm_mul_ps(v, inv);
}

struct FnvVehicle : hkpVehicleInstance {
    void ComputeValues_00e37350(int w_it, float linearForceAtWheel, float suspensionForceAtWheel, float estimatedCarSpeed, FnvAxleParams& axle_params);
};

// @fnv 0x00e37350
// src: GUESS 0x00e37350 (confidence: low)
void FnvVehicle::ComputeValues_00e37350(int w_it, float linearForceAtWheel, float suspensionForceAtWheel, float estimatedCarSpeed, FnvAxleParams& axle_params)
{
    float threshold = DAT_0104da4c;
    float forwardLen2;
    int wi = w_it;
    int axle = m_data->m_kWheelParams.m_data[wi].m_iAxle;

    LocalM128 spin = fnv_load(reinterpret_cast<const FnvVec&>(m_kWheelInfoArray.m_data[wi].unka0));
    LocalM128 normal = fnv_load(reinterpret_cast<const FnvVec&>(m_kWheelInfoArray.m_data[wi].unk10));
    LocalM128 spinY = _mm_shuffle_ps(spin, spin, 0xc9);
    LocalM128 spinZ = _mm_shuffle_ps(spin, spin, 0xd2);
    LocalM128 normalZ = _mm_shuffle_ps(normal, normal, 0xd2);
    LocalM128 normalY = _mm_shuffle_ps(normal, normal, 0xc9);
    LocalM128 forward = _mm_sub_ps(_mm_mul_ps(normalY, spinZ), _mm_mul_ps(normalZ, spinY));
    forwardLen2 = fnv_len2(forward);
    if (forwardLen2 < threshold) {
        LocalM128 susp = fnv_load(reinterpret_cast<const FnvVec&>(m_kWheelInfoArray.m_data[wi].unk80));
        LocalM128 suspY = _mm_shuffle_ps(susp, susp, 0xc9);
        LocalM128 suspZ = _mm_shuffle_ps(susp, susp, 0xd2);
        forward = _mm_sub_ps(_mm_mul_ps(suspZ, spinY), _mm_mul_ps(suspY, spinZ));
    }
    forward = fnv_normalize3(forward);
    float inv = 1.0f / (float)m_data->m_kNumWheelsPerAxle.m_data[axle];

    float scale = reinterpret_cast<const float&>(m_kWheelInfoArray.m_data[wi].unk20) * inv;
    LocalM128 invss = _mm_load_ss(&inv);
    LocalM128 inv4 = _mm_shuffle_ps(invss, invss, 0);
    LocalM128 summed = _mm_add_ps(fnv_load(axle_params.m_kFirstVector), _mm_mul_ps(fnv_load(reinterpret_cast<const FnvVec&>(m_kWheelInfoArray.m_data[wi].unk00)), inv4));
    fnv_store(axle_params.m_kFirstVector, summed);
    LocalM128 cn = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(forward, forward, 0xc9), normalZ), _mm_mul_ps(_mm_shuffle_ps(forward, forward, 0xd2), normalY));
    fnv_store(axle_params.m_kSecondAxleVector, _mm_add_ps(fnv_load(axle_params.m_kSecondAxleVector), cn));
    fnv_store(axle_params.m_kThirdVector, _mm_add_ps(fnv_load(axle_params.m_kThirdVector), forward));

    axle_params.m_fFirstScalar += m_data->m_kWheelParams.m_data[wi].m_fSlipAngle * scale;
    axle_params.m_fSecondScalar += m_data->m_kWheelParams.m_data[wi].m_fSlipVelocity * scale;
    // Cache the maximum coefficient before weighting its contribution.
    float coefficient2 = m_data->m_kWheelParams.m_data[wi].m_fMaxContactBodyAcceleration;
    axle_params.m_fThirdValue += coefficient2 * scale;
    axle_params.m_fFourthValue = suspensionForceAtWheel + axle_params.m_fFourthValue;
    float fwd = axle_params.m_fFifthScalar;
    fwd += linearForceAtWheel;
    axle_params.m_fFifthScalar = fwd;
    axle_params.m_ucValue = axle_params.m_ucValue || m_kSecondRealArray.m_data[wi].m_cBooleanValue;
    axle_params.m_fSixthValue += (inv * m_data->m_kWheelParams.m_data[wi].m_fForceFeedbackMultiplier) * estimatedCarSpeed;
}





extern "C" LocalM128 _mm_load_ss(float const*);
struct TorqueOutput {
    LocalM128 unk00;
    LocalM128 unk10;
    LocalM128 angularVelocity;
};
struct TorqueOutputRef {
    TorqueOutput* p;
    TorqueOutputRef(TorqueOutput* q) : p(q) {}
};
struct TorqueVehicle : hkpVehicleInstance {
    void UpdateFields_00e376e0(float dt, TorqueOutputRef output) const;
};
// @fnv 0x00e376e0
// src: GUESS 0x00e376e0 (confidence: low)
void TorqueVehicle::UpdateFields_00e376e0(float dt, TorqueOutputRef output) const
{
    const hkpVehicleData* d = (const hkpVehicleData*)m_data;
    if (d->m_fTorqueFactor != 0.0f) {
        float t = m_fMainSteeringAngle * d->m_fTorqueFactor * dt;
        LocalM128 scalar = _mm_load_ss(&t);
        LocalM128 factor = _mm_shuffle_ps(scalar, scalar, 0);
        LocalM128 impulse = _mm_mul_ps(d->m_kChassisOrientation.m_kColumn0.m_vComponents, factor);
        impulse = _mm_mul_ps(impulse, d->m_vChassisUnitInertiaAndMassInv.m_vComponents);
        output.p->angularVelocity = _mm_add_ps(impulse, output.p->angularVelocity);
    }
}

extern "C" LocalM128 _mm_sub_ps(LocalM128,LocalM128);
extern "C" LocalM128 _mm_load_ss(const float*);

inline Vec4::Vec4(const LocalM128& q) { *reinterpret_cast<LocalM128*>(this) = q; }
inline LocalM128& Vec4::getQuad() { return *reinterpret_cast<LocalM128*>(this); }
inline const LocalM128& Vec4::getQuad() const { return *reinterpret_cast<const LocalM128*>(this); }
inline void Vec4::mul4(float r) { float t = r; LocalM128 s = _mm_load_ss(&t); getQuad() = _mm_mul_ps(getQuad(), _mm_shuffle_ps(s, s, 0)); }

struct TimeInterval;

struct Sub150 { void InitializeFields_00d72030(void* p); };

struct Out37
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5C;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6C;
    void* unk70;
    void* unk74;
    void* unk78;
    void* unk7C;
    void* unk80;
    void* unk84;
    void* unk88;
    void* unk8C;
    void* unk90;
    void* unk94;
    void* unk98;
    void* unk9C;
    void* unkA0;
    void* unkA4;
    void* unkA8;
    void* unkAC;
    void* unkB0;
    void* unkB4;
    void* unkB8;
    void* unkBC;
    void* unkC0;
    void* unkC4;
    void* unkC8;
    void* unkCC;
    int unkd0;
    void* unkD4;
    void* unkD8;
    void* unkDC;
    void* unkE0;
    void* unkE4;
    void* unkE8;
    void* unkEC;
    void* unkF0;
    void* unkF4;
    void* unkF8;
    void* unkFC;
    Vec4 m_kGravity;
    void* unk110;
    void* unk114;
    void* unk118;
    void* unk11C;
    int unk120;
    void* unk124;
    void* unk128;
    void* unk12C;
    void* unk130;
    void* unk134;
    void* unk138;
    void* unk13C;
    void* unk140;
    void* unk144;
    void* unk148;
    void* unk14C;
    Sub150 m_sub150;
    unsigned char unk151;
    unsigned char unk152;
    unsigned char unk153;
    void* unk154;
    void* unk158;
    void* unk15C;
    Vec4 m_kTranslationalVelocity;
    Vec4 m_sub170;
};

void hkRigidMotionUtilApplyForcesAndBuildAccumulators(const TimeInterval& info, hkpMotion** motions, int n, int z, void* out);

// The shared vehicle has no declaration for this velocity-output helper.
struct VehicleVelocityVehicle : hkpVehicleInstance
{
    void UpdateFields_00e37740(const TimeInterval& info, Out37& out);
};

// @fnv 0x00e37740
// src: GUESS 0x00e37740 (confidence: low)
void VehicleVelocityVehicle::UpdateFields_00e37740(const TimeInterval& info, Out37& out)
{
    hkpMotion* motions[1];
    motions[0] = &m_pEntity->m_pMotionState;
    hkRigidMotionUtilApplyForcesAndBuildAccumulators(info, motions, 1, 0, &out.unkd0);

    hkMotionState* ms = &m_pEntity->m_pMotionState.m_kMotionState;
    __declspec(align(16)) Vec4 linVel(_mm_sub_ps(ms->m_kSweptTransform.m_vCenterOfMass1.m_vComponents, ms->m_kSweptTransform.m_vCenterOfMass0.m_vComponents));
    linVel.mul4(ms->m_kSweptTransform.m_vCenterOfMass1.w);
    float angularScale = ms->m_kSweptTransform.m_vCenterOfMass1.w;
    LocalM128 angularScalar = _mm_load_ss(&angularScale);
    LocalM128 angularFactor = _mm_shuffle_ps(angularScalar, angularScalar, 0);
    __declspec(align(16)) Vec4 angVel(_mm_mul_ps(angularFactor, ms->m_kDeltaAngle.m_vComponents));

    *(LocalM128*)&out.m_kGravity = m_data->m_vChassisUnitInertiaAndMassInv.m_vComponents;
    out.m_sub150.InitializeFields_00d72030(&out.unkd0);
    out.m_sub170.hkVector4_setRotatedDir(&out.unk120, angVel);
    *(LocalM128*)&out.m_kTranslationalVelocity = *(LocalM128*)&linVel;
}

extern "C" LocalM128 _mm_load_ss(const float*);

struct VUBCD_Vec {
    LocalM128 m_vComponents;
    void hkVector4_setRotatedDir(const VUBCD_Vec& rot, const VUBCD_Vec& dir) throw();
    void setTransformedPos_00c7f640(const VUBCD_Vec& trans, const VUBCD_Vec& pos) throw();
    void setAddMul4(const VUBCD_Vec& a, const VUBCD_Vec& b, const float& r)
    {
        LocalM128 s = _mm_load_ss(&r); m_vComponents = _mm_add_ps(a.m_vComponents, _mm_mul_ps(_mm_shuffle_ps(s, s, 0), b.m_vComponents));
    }
};
struct VUBCD_SuspParams {
    VUBCD_Vec m_vHardpointChassisSpace;
    VUBCD_Vec m_vDirectionChassisSpace;
    float m_fRestLength;
};
struct VUBCD_Suspension {
    void* m_vtbl;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    VUBCD_SuspParams* m_kWheelParams;
    int m_wheelParamsSize;
    int m_wheelParamsCap;
};
struct VUBCD_Instance;
struct VUBCD_WheelCollide {
    virtual void s00(); virtual void s04(); virtual void s08(); virtual void s0c(); virtual void s10(); virtual void s14();
    virtual void CollideInstance(VUBCD_Instance* inst);
};
struct VUBCD_Instance : hkpVehicleInstance { void hkpVehicleInstance_updateBeforeCollisionDetection(); };

void VUBCD_WheelCollide::CollideInstance(VUBCD_Instance* inst) {}

// @fnv 0x00e37940
// src: XBOX_PDB 0x00e37940
void VUBCD_Instance::hkpVehicleInstance_updateBeforeCollisionDetection()
{
    VUC_Mon* s = (VUC_Mon*)TlsGetValue(DAT_0126835c);
    VUC_Timer* h = (VUC_Timer*)s->m_kRayEnd;
    if ((char*)h < s->m_capMinus16) {
        h->m_name = "TtUpdateBeforeCD";
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        h->m_ticks = ticks;
        s->m_kRayEnd = (char*)(h + 1);
    }
    const VUBCD_Vec& carTransform = reinterpret_cast<const VUBCD_Vec&>(m_pEntity->m_pMotionState.m_kMotionState.m_kMotionTransform);
    for (int w = 0; w < m_data->m_iWheelCount; w++) {
        hkpVehicleInstanceWheelInfo& wheelInfo = m_kWheelInfoArray.m_data[w];
        reinterpret_cast<VUBCD_Vec&>(wheelInfo.unk80).hkVector4_setRotatedDir(carTransform, static_cast<VUBCD_Suspension*>(static_cast<void*>(m_pSuspension))->m_kWheelParams[w].m_vDirectionChassisSpace);
        reinterpret_cast<VUBCD_Vec&>(wheelInfo.unk50).setTransformedPos_00c7f640(carTransform, static_cast<VUBCD_Suspension*>(static_cast<void*>(m_pSuspension))->m_kWheelParams[w].m_vHardpointChassisSpace);
        const float sum = static_cast<VUBCD_Suspension*>(static_cast<void*>(m_pSuspension))->m_kWheelParams[w].m_fRestLength + m_data->m_kWheelParams.m_data[w].m_fSphereRadius;
                reinterpret_cast<VUBCD_Vec&>(wheelInfo.unk60).setAddMul4(reinterpret_cast<VUBCD_Vec&>(wheelInfo.unk50), reinterpret_cast<VUBCD_Vec&>(wheelInfo.unk80), sum);
    }
    static_cast<VUBCD_WheelCollide*>(static_cast<void*>(m_pWheelCollide))->CollideInstance(this);
    s = (VUC_Mon*)TlsGetValue(DAT_0126835c);
    h = (VUC_Timer*)s->m_kRayEnd;
    if ((char*)h < s->m_capMinus16) {
        h->m_name = "Et";
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        h->m_ticks = ticks;
        s->m_kRayEnd = (char*)(h + 1);
    }
}
