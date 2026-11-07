#include "../../../../include/hkArray.h"

// src/havok/physics/vehicle/hkpvehicleinstance.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/hkpvehicleinstance.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// Exe-matched intrinsic packet; __m128 remains an ABI compatibility alias.
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;

// Keep the unit's intrinsic declarations and explicitly aligned vector storage.
#define FNV_FOURFLOATVECTOR_NO_SSE
// local form of hkVector4: 0x00e38140 needs its original packet form (compiled function extent differs: 353 vs 455).


#if !defined(FNV_FOURFLOATVECTOR_NO_SSE)
#include <xmmintrin.h>
#else
#endif

class SimdReal;
class SimdScalar;
class ScalarValue;
class Transform;
class NiPoint3;

#pragma pack(push, 4)

class PacketCallLocal_00e38140
{
public:
#if defined(FNV_FOURFLOATVECTOR_NO_SSE)
    union Components
    {
        float m128_f32[4];
        unsigned __int64 m128_u64[2];
        signed char m128_i8[16];
        short m128_i16[8];
        int m128_i32[4];
        __int64 m128_i64[2];
        unsigned char m128_u8[16];
        unsigned short m128_u16[8];
        unsigned int m128_u32[4];
    };
#else
    typedef __declspec(align(4)) __m128 Components;
#endif

    union
    {
        struct
        {
            float x;
            float y;
            float z;
            float w;
        };
        Components m_vComponents;
        Components m;
        float f[4];
        Components values;
        Components q;
        Components value;
        Components quad;
        float elements[4];
        float m_fComponents[4];
    };

    PacketCallLocal_00e38140();
    PacketCallLocal_00e38140(float x, float y, float z, float w);
    PacketCallLocal_00e38140(const __m128& vector);

    PacketCallLocal_00e38140* hkVector4_hkVector4(float x, float y, float z, float w);
    void SetValue(PacketCallLocal_00e38140* vector);
    void __thiscall SetQuaternionComponentsFromVector(const PacketCallLocal_00e38140* vector);
    PacketCallLocal_00e38140& ComputeValue_00e531a0(int parameter);
    PacketCallLocal_00e38140 ProcessAndReturnValue_00e53260(int parameter);
    void normalize_005611c0();

    void operator=(const PacketCallLocal_00e38140& vector);
    float& operator()(int index);
    const float& operator()(int index) const;
    float& component(int index);
    float& At(int index);
    const float& At(int index) const;

    __m128 length3() const;
    float getW() const;
    ScalarValue Dot(const PacketCallLocal_00e38140& vector) const;
    ScalarValue LengthSq() const;
    ScalarValue Length() const;
    ScalarValue InverseLength() const;
    void Normalize();
    bool NormalizeNonzero();
    void Mul(const ScalarValue& scalar);
    void Add(const PacketCallLocal_00e38140& vector);
    void Sub(const PacketCallLocal_00e38140& vector);
    void Cross(const PacketCallLocal_00e38140& a, const PacketCallLocal_00e38140& b);

    void setAbs4(const PacketCallLocal_00e38140& vector);
    void setMul4(const SimdReal& scalar, const PacketCallLocal_00e38140& vector);
    void addMul4(const SimdReal& scalar, const PacketCallLocal_00e38140& vector);
    void setAddMul4(const PacketCallLocal_00e38140& a, const PacketCallLocal_00e38140& b, const SimdReal& scalar);
    SimdReal getSimdAt3() const;
    SimdReal lengthSquared3() const;
    void setXYZ_W(__m128 xyz, __m128 w);
    void setSqrtInverse4(const PacketCallLocal_00e38140& vector);
    void setAddMul(const PacketCallLocal_00e38140& a, const PacketCallLocal_00e38140& b, const SimdScalar& scalar);
    void addMul(const float& scalar, const PacketCallLocal_00e38140& vector);
    void transformed(const Transform& transform, const PacketCallLocal_00e38140& vector);
    void addScaled(const PacketCallLocal_00e38140& base, const PacketCallLocal_00e38140& direction, float amount);
    void* AddVector(void*, NiPoint3*, void*, float);
    void* AddVector(void*, void*);
    void* ScaleSwizzled();
};

#pragma pack(pop)

#undef FNV_FOURFLOATVECTOR_NO_SSE

#include "../../../../include/hkpVehicleInstance.h"

#include "../../../../include/hkBool.h"
#include "../../../../include/hkMemoryAllocator.h"
#include "../../../../include/hkReferencedObject.h"
#include "../../../../include/hkStringPtr.h"
#include "../../../../include/hkpEntity.h"
#include "../../../../include/hkpWorld.h"
#include "../../../../include/hkBoolResult.h"
// FUN_00c85750 returns the Havok router; hkMemoryRouter shares its heap pointer at +0x10.
#include "../../../../include/hkMemoryRouter.h"
#include "../../../../include/hkpVehicleInstanceWheelInfo.h"
#include "../../../../include/hkpVehicleSteering.h"
#include "../../../../include/Pair.h"

extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_sqrt_ss(__m128);
extern "C" void _mm_store_ss(float*, __m128);

// Preserve the original vectors' no-op initialization and inline operations.
__forceinline PacketCallLocal_00e38140::PacketCallLocal_00e38140()
{
}

__forceinline __m128 PacketCallLocal_00e38140::length3() const
{
    __m128 v2 = _mm_mul_ps(reinterpret_cast<const __m128&>(m_vComponents),
                             reinterpret_cast<const __m128&>(m_vComponents));
    __m128 v1 = _mm_shuffle_ps(v2, v2, 0x55);
    __m128 v0 = _mm_shuffle_ps(v2, v2, 0xaa);
    v1 = _mm_add_ss(v1, v2);
    v0 = _mm_add_ss(v0, v1);
    return _mm_sqrt_ss(v0);
}

__forceinline float PacketCallLocal_00e38140::getW() const
{
    float w;
    _mm_store_ss(&w, _mm_shuffle_ps(reinterpret_cast<const __m128&>(m_vComponents),
                                  reinterpret_cast<const __m128&>(m_vComponents), 0xff));
    return w;
}

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern unsigned long DAT_0126835c;
void* hkMemoryRouter_getInstance() throw();


struct VUC_Mon
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_cap;
    char* m_capMinus16;
};
struct VUC_Timer
{
    const char* m_name;
    unsigned int m_ticks;
    unsigned int m_auiShapeKeys;
};
struct VUC_StepInfo
{
    float m_uiStartTime;
    float m_fEndTime;
    float m_fTimeStep;
    float m_fInverseDeltaTime;
};
// local form of hkArrayBase: 0x00e39030 needs the local member-array construction timing; shared initialization changes extent from 345 to 385 bytes.
struct VUC_RealArray
{
    float* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct VUC_WheelParams
{
    float m_fSphereRadius;
    float m_fViscosityFriction;
    float m_fMaxFriction;
    float m_fSlipAngle;
    float m_fSlipVelocity;
    float m_fMaxContactBodyAcceleration;
    float m_fForceFeedbackMultiplier;
    float m_fMaxFrictionForce;
    float m_fFrictionEqualizer;
    signed char m_iAxle;
};
struct VUC_Data
{
    void* m_vtbl;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    __declspec(align(16)) PacketCallLocal_00e38140 m_kGravity;
    signed char m_iWheelCount;
    __declspec(align(16)) PacketCallLocal_00e38140 m_kChassisOrientation[3];
    float m_fChassisMass;
    float m_fTorqueMax;
    float m_fTorqueMin;
    float m_fTorqueFactor;
    float m_fTorquePitchFactor;
    float m_fTorqueRollFactor;
    float m_fTorqueYawFactor;
    float m_fExtraTorqueFactor;
    float m_fChassisUnitInertiaRoll;
    float m_fChassisUnitInertiaPitch;
    float m_fChassisUnitInertiaYaw;
    hkArrayBase<VUC_WheelParams> m_kWheelParams;
};
struct VUC_Filtered
{
    float m_kPointA;
    float m_kPointB;
    float m_iThirdValue;
    float m_iFourthElementInteger;
};
struct VUC_Transmission
{
    float m_engineRpm;
    float m_fCurrentGearRatio;
    float* m_pGearRatios;
    int m_iGearCount;
    int m_iGearCapacity;
};
struct FUN_00e39400
{
    VUC_RealArray m_kFirstRealArray;
    VUC_RealArray m_kSecondRealArray;
    float m_unk18;
    FUN_00e39400()
    {
        m_kFirstRealArray.m_data = 0;
        m_kFirstRealArray.m_iElementCount = 0;
        m_kFirstRealArray.m_iCapacityState = 0x80000000;
        m_kSecondRealArray.m_data = 0;
        m_kSecondRealArray.m_iElementCount = 0;
        m_kSecondRealArray.m_iCapacityState = 0x80000000;
    }
    ~FUN_00e39400() throw();
};

struct VUC_Instance
{
    void* m_vtbl;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_pOwningWorld;
    void* m_pCurrentSimulationIsland;
    unsigned int m_ulUserData;
    const char* m_name;
    void* m_pEntity;
    VUC_Data* m_data;
    void FUN_00e37aa0(float dt, void* det) throw();
    void hkpVehicleInstance_updateDriverInput(float dt, VUC_Filtered& f) throw();
    void UpdateSteering(float dt, const VUC_Filtered& f) throw();
    void hkpVehicleInstance_updateTransmission(float dt, VUC_Transmission& t) throw();
    void hkpVehicleInstance_updateEngine(float dt, const VUC_Filtered& f, VUC_Transmission& t) throw();
    void UpdateVehicleState(float dt, const VUC_Filtered& f, FUN_00e39400& b) throw();
    void NotifyListener(float dt, void* det, VUC_RealArray& s) throw();
    void hkpVehicleInstance_updateAerodynamics(float dt, void* aero) throw();
    void UpdateVehicleComponents(const VUC_StepInfo& stepInfo, void* det, void* aero,
                                 VUC_RealArray& suspensionForceAtWheel, VUC_RealArray& totalLinearForceAtWheel);
};

// @fnv 0x00e38e60
void VUC_Instance::UpdateVehicleComponents(const VUC_StepInfo& stepInfo, void* det, void* aero,
                                           VUC_RealArray& suspensionForceAtWheel,
                                           VUC_RealArray& totalLinearForceAtWheel)
{
    {
        VUC_Mon* m = (VUC_Mon*)TlsGetValue(DAT_0126835c);
        if (m->m_kRayEnd < m->m_capMinus16)
        {
            VUC_Timer* pTimer = (VUC_Timer*)m->m_kRayEnd;
            pTimer->m_name = "TtUpdateComponents";
            _ReadWriteBarrier();
            volatile unsigned int ticks = (unsigned int)__rdtsc();
            pTimer->m_ticks = ticks;
            m->m_kRayEnd = (char*)(pTimer + 1);
        }
    }

    VUC_Filtered filteredInput;
    VUC_Transmission transmission;
    FUN_00e39400 breakingInfo;
    {
        int n = m_data->m_iWheelCount;
        char** cur = (char**)hkMemoryRouter_getInstance();
        char* p = *cur;
        *cur = p + ((n * 4 + 0x7f) & ~0x7f);
        transmission.m_pGearRatios = (float*)p;
    }

    const float deltaTime = stepInfo.m_fTimeStep;

    FUN_00e37aa0(deltaTime, det);
    hkpVehicleInstance_updateDriverInput(deltaTime, filteredInput);
    UpdateSteering(deltaTime, filteredInput);
    hkpVehicleInstance_updateTransmission(deltaTime, transmission);
    hkpVehicleInstance_updateEngine(deltaTime, filteredInput, transmission);
    UpdateVehicleState(deltaTime, filteredInput, breakingInfo);
    NotifyListener(deltaTime, det, suspensionForceAtWheel);
    hkpVehicleInstance_updateAerodynamics(deltaTime, aero);

    for (int w = 0; w < m_data->m_iWheelCount; w++)
    {
        const float total_torque = breakingInfo.m_kFirstRealArray.m_data[w] + transmission.m_pGearRatios[w];
        totalLinearForceAtWheel.m_data[w] = total_torque / m_data->m_kWheelParams[w].m_fSphereRadius;
    }

    {
        char* p = (char*)transmission.m_pGearRatios;
        *(char**)hkMemoryRouter_getInstance() = p;
    }

    {
        VUC_Mon* m = (VUC_Mon*)TlsGetValue(DAT_0126835c);
        if (m->m_kRayEnd < m->m_capMinus16)
        {
            VUC_Timer* pTimer = (VUC_Timer*)m->m_kRayEnd;
            pTimer->m_name = "Et";
            _ReadWriteBarrier();
            volatile unsigned int ticks = (unsigned int)__rdtsc();
            pTimer->m_ticks = ticks;
            m->m_kRayEnd = (char*)(pTimer + 1);
        }
    }
}

struct VUC_VehicleTarget
{
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void f4() = 0;
    virtual void f5() = 0;
    virtual void f6() = 0;
    virtual void f7() = 0;
    virtual void f8() = 0;
    virtual void hkpVehicleInstance_addToWorld(void* world) = 0;
};

struct VUC_VehicleInstance
{
    void* m_vtbl;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_pOwningWorld;
    void* m_pCurrentSimulationIsland;
    unsigned int m_ulUserData;
    const char* m_name;
    void* m_pEntity;
    void* m_data;
    unsigned char m_auiShapeKeys[0x1c];
    VUC_VehicleTarget* m_target;

    void hkpVehicleInstance_addToWorld(void* world);
};

// @fnv 0x00e378e0
// src: HAVOK_LIB 0x00e378e0
void VUC_VehicleInstance::hkpVehicleInstance_addToWorld(void* world)
{
    reinterpret_cast<hkpWorld*>(world)->hkpWorld_addEntity(reinterpret_cast<hkpRigidBody*>(m_pEntity), 1);
    m_target->hkpVehicleInstance_addToWorld(world);
}

struct VUC_DeltaTime
{
    float m_fTimeStep;
    float m_fInverseDeltaTime;
};

void __cdecl hkpVehicleFrictionDescription_ProcessEntries_00e59a40(void* a, void* b, void* c, void* d);

struct FUN_00e38080StandIn
{
    unsigned char m_unknown00[0x1c];
    unsigned char* m_data;
    unsigned char m_unknown20[0x34];
    void* m_object54;

    void hkpVehicleInstance_applyFrictionSolver(const VUC_StepInfo& stepInfo, void* arg2);
};

// @fnv 0x00e38080
// src: HAVOK_LIB 0x00e38080
void FUN_00e38080StandIn::hkpVehicleInstance_applyFrictionSolver(const VUC_StepInfo& stepInfo, void* apArg)
{
    VUC_DeltaTime deltaTime;
    deltaTime.m_fTimeStep = stepInfo.m_fTimeStep;
    deltaTime.m_fInverseDeltaTime = stepInfo.m_fInverseDeltaTime;

    hkpVehicleFrictionDescription_ProcessEntries_00e59a40(&deltaTime, m_data + 0xa4, apArg, &m_object54);
}

extern int DAT_010df34c;
hkMemoryRouter* _D1A0E0GetMemoryRouter();
void __fastcall ReleaseReference_00d2b2b0(void*);

struct FUN_00e38bf0
{
    void* m_vtbl;
    char m_uiStandInValue[0x18];

    hkReferencedObject* m_ref1c;
    hkReferencedObject* m_ref20;
    hkReferencedObject* m_ref24;
    hkReferencedObject* m_ref28;
    hkReferencedObject* m_ref2c;
    hkReferencedObject* m_ref30;
    hkReferencedObject* m_ref34;
    hkReferencedObject* m_ref38;
    hkReferencedObject* m_ref3c;
    hkReferencedObject* m_ref40;
    hkReferencedObject* m_ref44;

    void* m_data48;
    int m_size4c;
    int m_capacity50;

    char m_iValueAfterStandIn[0x48];

    hkReferencedObject* m_ref9c;
    void* m_dataa0;
    int m_sizea4;
    int m_capacitya8;

    char m_pAuxiliaryObject[0x14];

    void* m_datac0;
    int m_sizec4;
    int m_capacityc8;

    FUN_00e38bf0();
    ~FUN_00e38bf0();
};

// Resets the vtable, releases the twelve referenced objects, frees the three dynamic arrays through the memory router allocator, and calls FUN_00d2b2b0.
// @fnv 0x00e38bf0
FUN_00e38bf0::~FUN_00e38bf0()
{
    m_vtbl = &DAT_010df34c;

    if (m_ref1c)
        m_ref1c->removeReference();
    if (m_ref20)
        m_ref20->removeReference();
    if (m_ref24)
        m_ref24->removeReference();
    if (m_ref28)
        m_ref28->removeReference();
    if (m_ref2c)
        m_ref2c->removeReference();
    if (m_ref30)
        m_ref30->removeReference();
    if (m_ref34)
        m_ref34->removeReference();
    if (m_ref38)
        m_ref38->removeReference();
    if (m_ref3c)
        m_ref3c->removeReference();
    if (m_ref44)
        m_ref44->removeReference();
    if (m_ref9c)
        m_ref9c->removeReference();
    if (m_ref40)
        m_ref40->removeReference();

    hkMemoryRouter* router = _D1A0E0GetMemoryRouter();
    hkMemoryAllocator* allocator = router->m_heap;

    m_sizec4 = 0;
    if ((m_capacityc8 & 0x80000000) == 0)
    {
        unsigned int size = (m_capacityc8 & 0x3fffffff) * 4;
        allocator->bufFree(m_datac0, size);
    }
    m_datac0 = 0;
    m_capacityc8 = 0x80000000;

    router = _D1A0E0GetMemoryRouter();
    allocator = router->m_heap;

    m_sizea4 = 0;
    if ((m_capacitya8 & 0x80000000) == 0)
    {
        unsigned int size = m_capacitya8 & 0x3fffffff;
        allocator->bufFree(m_dataa0, size);
    }
    m_dataa0 = 0;
    m_capacitya8 = 0x80000000;

    router = _D1A0E0GetMemoryRouter();
    allocator = router->m_heap;

    m_size4c = 0;
    if ((m_capacity50 & 0x80000000) == 0)
    {
        unsigned int size = (m_capacity50 & 0x3fffffff) * 0xe0;
        allocator->bufFree(m_data48, size);
    }
    m_data48 = 0;
    m_capacity50 = 0x80000000;

    ReleaseReference_00d2b2b0(this);
}

struct FnvCpu_FUN_00e36f50_CpuInterface
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void Invoke(int arg0);
};
struct FnvCpu_FUN_00e36f50_CpuOwner
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
    FnvCpu_FUN_00e36f50_CpuInterface* target;
    void hkpVehicleInstance_getPhantoms(int arg0);
};
// @fnv 0x00e36f50
// src: HAVOK_LIB 0x00e36f50
void FnvCpu_FUN_00e36f50_CpuOwner::hkpVehicleInstance_getPhantoms(int arg0)
{
    target->Invoke(arg0);
}

struct CpuObject
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
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    float value;
    float hkpVehicleInstance_calcRPM();
};
// @fnv 0x00e370a0
// src: HAVOK_SRC 0x00e370a0
float CpuObject::hkpVehicleInstance_calcRPM()
{
    return value;
}

struct Filtered
{
    float a, b, c, d;
};
struct Transmission
{
    float engineRpm;
    float mainTorque;
    float* wheels;
    int reversing;
    int gear;
};
struct Instance;
struct Target
{
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3(float dt, Instance* inst, const Filtered* f, Transmission* t, Pair* out);
};
struct Instance
{
    void* m_vtbl;
    char m_auiShapeKeys[0x24];
    Target* m_target;
    char m_pAuxiliaryObject[0xb4 - 0x2c];
    float m_b4;
    float m_b8;
    void hkpVehicleInstance_updateEngine(float dt, const Filtered& f, Transmission& t) throw();
};
// Passes dt, this, f, t and a Pair built from m_b4/m_b8 to m_target->s3, then stores the returned Pair back into m_b4/m_b8.
// @fnv 0x00e37020
// src: HAVOK_LIB 0x00e37020
void Instance::hkpVehicleInstance_updateEngine(float afDeltaTime, const Filtered& f, Transmission& t) throw()
{
    // This callback uses the Pair slots as float bits, with no constructor call.
    float storage[sizeof(Pair) / sizeof(float)];
    Pair& p = *reinterpret_cast<Pair*>(storage);
    reinterpret_cast<float&>(p.b) = m_b8;
    reinterpret_cast<float&>(p.a) = m_b4;
    m_target->s3(afDeltaTime, this, &f, &t, &p);
    m_b8 = reinterpret_cast<float&>(p.b);
    m_b4 = reinterpret_cast<float&>(p.a);
}

class hkListenerE371
{
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void notify(float f, void* pvSource, void* a, void* b);
};

class hkObjE371
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
    hkListenerE371* m_kListener;

    void NotifyListener(float f, void* a, void** pb);
};

// Forwards the float and the two pointers to the listener stored in the object, passing this as the source.
// @fnv 0x00e371a0
void hkObjE371::NotifyListener(float f, void* a, void** pb)
{
    m_kListener->notify(f, this, a, *pb);
}

class hkActionE379
{
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
};

class FUN_00e37910_cls
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    hkpEntity* m_pEntity;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    hkActionE379* m_pAction;

    void hkpVehicleInstance_removeFromWorld();
};

// Calls V9 on the stored action, then calls ProcessTarget on the entity's world with the stored entity.
// @fnv 0x00e37910
// src: HAVOK_LIB 0x00e37910
void FUN_00e37910_cls::hkpVehicleInstance_removeFromWorld()
{
    m_pAction->V9();
    reinterpret_cast<hkpWorld*>(m_pEntity->m_pOwningWorld)->ProcessTarget(reinterpret_cast<hkpRigidBody*>(m_pEntity));
}

void __cdecl hkArrayUtil__reserve(hkMemoryAllocator* allocator, VUC_RealArray* array, int capacity, int stride);
struct VUC_BrakingStrategy
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void calculate(float dt, VUC_Instance* vehicle, const VUC_Filtered& input, FUN_00e39400& output);
};
// @fnv 0x00e38a30
void VUC_Instance::UpdateVehicleState(float afDeltaTime, const VUC_Filtered& input, FUN_00e39400& output) throw()
{
    hkpVehicleInstance* vehicle = reinterpret_cast<hkpVehicleInstance*>(this);
    VUC_RealArray& rFixedArray = output.m_kSecondRealArray;
    int count = vehicle->m_kSecondRealArray.m_iElementCount;
    hkMemoryRouter* router = reinterpret_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance());
    hkMemoryAllocator* alloc = router->m_heap;
    int capacity = rFixedArray.m_iCapacityState & 0x3fffffff;
    if (capacity < count)
    {
        capacity *= 2;
        if (count >= capacity)
            capacity = count;
        hkArrayUtil__reserve(alloc, &rFixedArray, capacity, 1);
    }
    rFixedArray.m_iElementCount = count;
    count = vehicle->m_kSecondRealArray.m_iElementCount;
    router = reinterpret_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance());
    alloc = router->m_heap;
    capacity = output.m_kFirstRealArray.m_iCapacityState & 0x3fffffff;
    if (capacity < count)
    {
        capacity *= 2;
        if (count >= capacity)
            capacity = count;
        hkArrayUtil__reserve(alloc, &output.m_kFirstRealArray, capacity, 4);
    }
    output.m_kFirstRealArray.m_iElementCount = count;
    for (int i = 0; i < vehicle->m_kSecondRealArray.m_iElementCount; ++i)
        reinterpret_cast<char*>(rFixedArray.m_data)[i] = vehicle->m_kSecondRealArray.m_data[i].m_cBooleanValue;
    output.m_unk18 = vehicle->m_fBrakeState;
    reinterpret_cast<VUC_BrakingStrategy*>(vehicle->m_pBrake)->calculate(afDeltaTime, this, input, output);
    for (int i = 0; i < output.m_kSecondRealArray.m_iElementCount; ++i)
        vehicle->m_kSecondRealArray.m_data[i].m_cBooleanValue = reinterpret_cast<char*>(output.m_kSecondRealArray.m_data)[i];
    vehicle->m_fBrakeState = output.m_unk18;
}

void __cdecl hkArrayUtil__reserve(hkMemoryAllocator& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();

template <typename T> void hkMemoryAllocator::_bufFree(void* p, int aiNumElements)
{
    bufFree(p, aiNumElements * sizeof(T));
}

template <typename T, typename A> __forceinline hkArray<T, A>::~hkArray()
{ __if_exists(A::destroy) { A::destroy(*this); } __if_not_exists(A::destroy) {
    hkMemoryAllocator& kAlloc = ((hkMemoryRouter*)hkMemoryRouter_getInstance())->heap();
    m_iElementCount = 0;
    if ((m_iCapacityState & 0x80000000) == 0)
        kAlloc._bufFree<T>(m_data, m_iCapacityState & 0x3fffffff);
    m_data = 0;
    m_iCapacityState = 0x80000000;
} }

template <typename T> __forceinline void hkArrayBase<T>::GrowArrayCapacity(hkMemoryAllocator& kAlloc, int n)
{
    const int iCapacity = getCapacity();
    if (iCapacity < n)
    {
        int iCap2 = 2 * iCapacity;
        int iNewSize = (n < iCap2) ? iCap2 : n;
        hkArrayUtil__reserve(kAlloc, this, iNewSize, sizeof(T));
    }
}

hkMemoryAllocator& hkContainerHeapAllocator::get(const void*)
{
    return ((hkMemoryRouter*)hkMemoryRouter_getInstance())->heap();
}

template <typename T> __forceinline void hkArrayBase<T>::_setSize(hkMemoryAllocator& alloc, int n)
{
    GrowArrayCapacity(alloc, n);
    m_iElementCount = n;
}

struct hkpVehicleSteeringAnglesOutputE38D
{
    hkReal m_fMainSteeringAngle;
    hkArray<hkReal> m_kWheelSteeringAngles;
};

// Copies the steering angles into a temporary output, runs the steering component's update, then writes the resulting angle and array back.
// @fnv 0x00e38d50
void VUC_Instance::UpdateSteering(hkReal fMoveElapsedTime, const VUC_Filtered& filteredInfo) throw()
{
    hkpVehicleInstance* vehicle = reinterpret_cast<hkpVehicleInstance*>(this);
    const hkpFilteredDriverInputOutputE38D& kFilteredInfo = reinterpret_cast<const hkpFilteredDriverInputOutputE38D&>(filteredInfo);
    hkpVehicleSteeringAnglesOutputE38D kSteeringOutput;
    kSteeringOutput.m_fMainSteeringAngle = vehicle->m_fMainSteeringAngle;
    kSteeringOutput.m_kWheelSteeringAngles.setSize(vehicle->m_kWheelSteeringAngles.m_iElementCount);
    for (int i = 0; i < vehicle->m_kWheelSteeringAngles.m_iElementCount; i++)
        kSteeringOutput.m_kWheelSteeringAngles.m_data[i] = vehicle->m_kWheelSteeringAngles.m_data[i];
    // The shared header omits virtual dispatch; CalcSteering occupies vtable slot 3.
    typedef void (__thiscall* CalcSteeringVirtual)(hkpVehicleSteering*, hkReal, const hkpVehicleInstance*,
                                                 const hkpFilteredDriverInputOutputE38D&,
                                                 hkpVehicleSteeringAnglesOutputE38D&);
    ((CalcSteeringVirtual)(*(void***)vehicle->m_pSteering)[3])(vehicle->m_pSteering, fMoveElapsedTime, vehicle,
                                                   kFilteredInfo, kSteeringOutput);
    vehicle->m_fMainSteeringAngle = kSteeringOutput.m_fMainSteeringAngle;
    for (int i = 0; i < vehicle->m_kWheelSteeringAngles.m_iElementCount; i++)
        vehicle->m_kWheelSteeringAngles.m_data[i] = kSteeringOutput.m_kWheelSteeringAngles.m_data[i];
}

struct VUC_InplaceRealArray16 : VUC_RealArray
{
    float m_kStorage[16];
};

struct VUC_AeroOutput
{
    __declspec(align(16)) PacketCallLocal_00e38140 m_kForce;
    __declspec(align(16)) PacketCallLocal_00e38140 m_kTorque;
};

static inline void VUC_ReleaseArray(VUC_RealArray& a)
{
    hkMemoryRouter* router = (hkMemoryRouter*)hkMemoryRouter_getInstance();
    hkMemoryAllocator* allocator = router->m_heap;
    a.m_iElementCount = 0;
    if ((a.m_iCapacityState & 0x80000000) == 0)
        allocator->bufFree(a.m_data, (a.m_iCapacityState & 0x3fffffff) * sizeof(float));
    a.m_data = 0;
    a.m_iCapacityState = 0x80000000;
}

struct VUC_StepLocals
{
    VUC_AeroOutput aerodynamicsInfo;
    VUC_InplaceRealArray16 suspensionForceAtWheel;
};

struct VUC_StepInstance : VUC_Instance
{
    void hkpVehicleInstance_simulateVehicle(const VUC_StepInfo& stepInfo, const VUC_AeroOutput& aero,
                      const VUC_RealArray& suspensionForceAtWheel,
                      const VUC_RealArray& totalLinearForceAtWheel) throw();
    void hkpVehicleInstance_stepVehicleUsingWheelCollideOutput(const VUC_StepInfo& stepInfo, void* det);
};

// Times a vehicle step: starts a "TtDoVehicle" timer, runs UpdateVehicleComponents and FUN_00e385e0 with in-place force arrays, stops the "Et" timer and releases the arrays.
// @fnv 0x00e39030
// src: HAVOK_LIB 0x00e39030
void VUC_StepInstance::hkpVehicleInstance_stepVehicleUsingWheelCollideOutput(const VUC_StepInfo& stepInfo, void* det)
{
    VUC_Mon* mon = (VUC_Mon*)TlsGetValue(DAT_0126835c);
    if (mon->m_kRayEnd < mon->m_capMinus16)
    {
        VUC_Timer* t = (VUC_Timer*)mon->m_kRayEnd;
        t->m_name = "TtDoVehicle";
        _ReadWriteBarrier();
        volatile unsigned int ticks = (unsigned int)__rdtsc();
        t->m_ticks = ticks;
        mon->m_kRayEnd = (char*)(t + 1);
    }

    VUC_StepLocals stepLocals;
    stepLocals.suspensionForceAtWheel.m_iElementCount = m_data->m_iWheelCount;
    stepLocals.suspensionForceAtWheel.m_data = stepLocals.suspensionForceAtWheel.m_kStorage;
    stepLocals.suspensionForceAtWheel.m_iCapacityState = 0x80000010;
    VUC_InplaceRealArray16 totalLinearForceAtWheel;
    totalLinearForceAtWheel.m_iElementCount = m_data->m_iWheelCount;
    totalLinearForceAtWheel.m_data = totalLinearForceAtWheel.m_kStorage;
    totalLinearForceAtWheel.m_iCapacityState = 0x80000010;

    UpdateVehicleComponents(stepInfo, det, &stepLocals.aerodynamicsInfo, stepLocals.suspensionForceAtWheel,
                            totalLinearForceAtWheel);
    hkpVehicleInstance_simulateVehicle(stepInfo, stepLocals.aerodynamicsInfo, stepLocals.suspensionForceAtWheel, totalLinearForceAtWheel);

    mon = (VUC_Mon*)TlsGetValue(DAT_0126835c);
    if (mon->m_kRayEnd < mon->m_capMinus16)
    {
        VUC_Timer* t = (VUC_Timer*)mon->m_kRayEnd;
        t->m_name = "Et";
        _ReadWriteBarrier();
        volatile unsigned int ticks = (unsigned int)__rdtsc();
        t->m_ticks = ticks;
        mon->m_kRayEnd = (char*)(t + 1);
    }

    VUC_ReleaseArray(totalLinearForceAtWheel);
    VUC_ReleaseArray(stepLocals.suspensionForceAtWheel);
}

void* hkMemoryRouter_getInstance() throw();

struct VehicleStepInfo
{
    float m_uiStartTime;
    float m_fEndTime;
    float m_fTimeStep;
    float m_fInverseDeltaTime;
};

struct VehicleData
{
    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    __declspec(align(16)) PacketCallLocal_00e38140 m_kGravity;
    signed char m_iWheelCount;
};

struct VehicleWheelCollide
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void CollideWheels(float deltaTime, void* vehicle, void* scratch);
};
struct VehicleInstance
{
    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_pOwningWorld;
    void* m_pCurrentSimulationIsland;
    unsigned int m_ulUserData;
    const char* m_name;
    void* m_pEntity;
    VehicleData* m_data;
    void* m_pDriverInput;
    void* m_pSteering;
    void* m_pVehicleEngine;
    void* m_pTransmission;
    void* m_pBrake;
    void* m_pSuspension;
    void* m_pAerodynamics;
    VehicleWheelCollide* m_pWheelCollide;
    void hkpVehicleInstance_updateBeforeCollisionDetection();
    void hkpVehicleInstance_stepVehicleUsingWheelCollideOutput(const VehicleStepInfo* stepInfo, void* scratch);
    void hkpVehicleInstance_stepVehicle(const VehicleStepInfo* stepInfo);
};

// @fnv 0x00e39190
// src: HAVOK_LIB 0x00e39190
void VehicleInstance::hkpVehicleInstance_stepVehicle(const VehicleStepInfo* stepInfo)
{
    hkpVehicleInstance_updateBeforeCollisionDetection();
    int wheelCount = m_data->m_iWheelCount;
    hkMemoryRouter* router = (hkMemoryRouter*)hkMemoryRouter_getInstance();
    char* originalTop = static_cast<char*>(router->m_stack.m_next.m_storage);
    float deltaTime = stepInfo->m_fTimeStep;
    router->m_stack.m_next.m_storage = originalTop + (((wheelCount * 3 << 5) + 127) & ~127);
    int capacityAndFlags = wheelCount | 0x80000000;

    m_pWheelCollide->CollideWheels(deltaTime, this, originalTop);
    hkpVehicleInstance_stepVehicleUsingWheelCollideOutput(stepInfo, originalTop);
    ((hkMemoryRouter*)hkMemoryRouter_getInstance())->m_stack.m_next.m_storage = originalTop;
    hkMemoryAllocator* allocator = ((hkMemoryRouter*)hkMemoryRouter_getInstance())->m_heap;
    if (!(capacityAndFlags & 0x80000000))
    {
        allocator->bufFree(originalTop, (capacityAndFlags & 0x3fffffff) * 3 << 5);
    }
}

class hkShapeE392;

struct hkInputInfoE392
{
    const hkShapeE392* m_pCollisionShape;
};

struct hkInputE392
{
    const hkInputInfoE392* m_info;
};

struct hkAgentDataE392
{
    int unk00;
    int unk04;
    unsigned char m_sState;
};

class hkAgentFactoryE392
{
  public:
    virtual void V00() throw();
    virtual void V04() throw();
    virtual void V08() throw();
    virtual void V0C() throw();
    virtual void V10() throw();
    virtual void V14() throw();
    virtual void V18() throw();
    virtual hkAgentDataE392* createAgent(const hkShapeE392* pkShape, int iFlags) throw();
};

class hkClonableE392
{
  public:
    virtual void V00() throw();
    virtual void V04() throw();
    virtual void V08() throw();
    virtual hkClonableE392* clone() throw();
};

class hkSourceE392;

class FUN_00e38b20
{
  public:
    virtual ~FUN_00e38b20() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int m_08;
    int m_0c;
    int unk10;
    int unk14;
    const hkShapeE392* m_pCollisionShape;
    hkReferencedObject* m_1c;
    hkReferencedObject* m_20;
    hkReferencedObject* m_24;
    hkReferencedObject* m_28;
    hkReferencedObject* m_2c;
    hkReferencedObject* m_30;
    hkReferencedObject* m_34;
    hkReferencedObject* m_38;
    hkAgentDataE392* m_pCollisionAgent;
    hkReferencedObject* m_40;
    hkReferencedObject* m_44;
    char unk48[0x54];
    hkClonableE392* m_9c;
    char unkA0[0x34];

    void* operator new(unsigned int nbytes)
    {
        FUN_00e38b20* b = static_cast<FUN_00e38b20*>(
            static_cast<hkMemoryRouter*>(hkMemoryRouter_getInstance())->heap().blockAlloc(nbytes));
        b->m_usMemSizeAndFlags = static_cast<unsigned short>(nbytes);
        return b;
    }

    FUN_00e38b20(const hkShapeE392* pkShape) throw();
    void CopyVehicleFields(const hkSourceE392* pkOther) throw();
};

typedef char fnv_check_e39210[(sizeof(FUN_00e38b20) == 0xd4) ? 1 : -1];

class hkSourceE392
{
  public:
    char unk00[0x3c];
    hkAgentFactoryE392* m_factory;
    hkReferencedObject* m_40;
    char unk44[0x58];
    hkClonableE392* m_9c;

    FUN_00e38b20* hkpVehicleInstance_clone(const hkInputE392* pkInput, int iFlags) throw();
};

// Allocates a clone of this source for the given input, copies the shape, creates an agent, clones m_9c and calls FUN_00c90510 on the clone's reference objects.
// @fnv 0x00e39210
// src: HAVOK_LIB 0x00e39210
FUN_00e38b20* hkSourceE392::hkpVehicleInstance_clone(const hkInputE392* pkInput, int iFlags) throw()
{
    const hkShapeE392* pkShape = pkInput->m_info->m_pCollisionShape;
    FUN_00e38b20* pkClone = new FUN_00e38b20(pkShape);
    pkClone->CopyVehicleFields(this);
    pkClone->m_08 = 0;
    pkClone->m_0c = 0;
    pkClone->m_pCollisionShape = pkShape;
    pkClone->m_pCollisionAgent = m_factory->createAgent(pkShape, iFlags);
    pkClone->m_pCollisionAgent->m_sState = 1;
    pkClone->m_9c = m_9c->clone();
    pkClone->m_1c->addReference();
    pkClone->m_20->addReference();
    pkClone->m_24->addReference();
    pkClone->m_28->addReference();
    pkClone->m_2c->addReference();
    pkClone->m_30->addReference();
    pkClone->m_34->addReference();
    pkClone->m_38->addReference();
    pkClone->m_44->addReference();
    if (m_40)
        pkClone->m_40->addReference();
    return pkClone;
}

void __cdecl hkpVehicleInstance_stepVehicle();

// @fnv 0x00e392f0
// src: HAVOK_SRC 0x00e392f0
void __cdecl hkpVehicleInstance_applyAction()
{
    hkpVehicleInstance_stepVehicle();
}

struct VUC_TransmissionTarget10
{
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void hkpVehicleInstance_addToWorld(float dt, void* instance, void* transmission) = 0;
};

struct VUC_Transmission8
{
    float m_engineRpm;
    float m_fCurrentGearRatio;
    float* m_pGearRatios;
    signed char m_iGearCount;
    signed char m_iGearCapacity;
    signed char m_gear2;
    signed char m_gear3;
    float m_extra;
};

// Copies gear fields into the transmission, calls the target's FUN_00e378e0 with dt, this and the transmission, then copies four fields back.
// @fnv 0x00e36fa0
// src: HAVOK_LIB 0x00e36fa0
void VUC_Instance::hkpVehicleInstance_updateTransmission(float dt, VUC_Transmission& t) throw()
{
    unsigned char* base = reinterpret_cast<unsigned char*>(this);
    VUC_Transmission8& s = reinterpret_cast<VUC_Transmission8&>(t);

    unsigned char* data = *reinterpret_cast<unsigned char**>(base + 0x1c);
    s.m_iGearCount = static_cast<signed char>(data[0x20]);
    s.m_iGearCapacity = *reinterpret_cast<signed char*>(base + 0xcc);
    s.m_gear2 = *reinterpret_cast<signed char*>(base + 0xcd);
    s.m_gear3 = *reinterpret_cast<signed char*>(base + 0xce);
    s.m_extra = *reinterpret_cast<float*>(base + 0xd0);

    VUC_TransmissionTarget10* target = *reinterpret_cast<VUC_TransmissionTarget10**>(base + 0x2c);
    target->hkpVehicleInstance_addToWorld(dt, this, &t);

    *reinterpret_cast<signed char*>(base + 0xcc) = s.m_iGearCapacity;
    *reinterpret_cast<signed char*>(base + 0xcd) = s.m_gear2;
    *reinterpret_cast<signed char*>(base + 0xce) = s.m_gear3;
    *reinterpret_cast<float*>(base + 0xd0) = s.m_extra;
}

extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);

struct Q_e380c0_Sub
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
    virtual void v40(const PacketCallLocal_00e38140* p);
    virtual void v44(const PacketCallLocal_00e38140* p);
    __m128 c0;
    __m128 c1;
    __m128 c2;
};
struct Q_e380c0_A
{
    int u00;
    int u04;
    int u08;
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
    int u54;
    int u58;
    int u5c;
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
    Q_e380c0_Sub sub;
};
struct Q_e380c0_cls
{
    int u00, u04, u08, u0c, u10, u14;
    Q_e380c0_A* a;
    void UpdateFields_00e380c0(const PacketCallLocal_00e38140* in);
};
// Combines the components of in[2] with the sub object's c0, c1, c2 columns, passes the result to v44, then passes in+1 to v40.
// @fnv 0x00e380c0
// src: GUESS 0x00e380c0 (confidence: low)
void Q_e380c0_cls::UpdateFields_00e380c0(const PacketCallLocal_00e38140* in)
{
    Q_e380c0_Sub& s = a->sub;
    __m128 v = reinterpret_cast<const __m128&>(in[2].q);
    __m128 vResult =
        _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), s.c1), _mm_mul_ps(_mm_shuffle_ps(v, v, 0), s.c0)),
                   _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), s.c2));
    PacketCallLocal_00e38140 t;
    reinterpret_cast<__m128&>(t.q) = vResult;
    s.v44(&t);
    s.v40(in + 1);
}

namespace fnv_00e385e0 {
extern "C" __m128 _mm_setzero_ps(void);

extern const char str_010eb844[];
extern const char str_010c41f8[];


struct VehStep_Output
{
    __declspec(align(16)) PacketCallLocal_00e38140 m_transform0;
    __declspec(align(16)) PacketCallLocal_00e38140 m_transform1;
};

struct VehStep_Motion
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c(float dt, PacketCallLocal_00e38140* out);
    virtual void slot60(float dt, PacketCallLocal_00e38140* out);
};

struct VehStep_Entity
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
    int unk34;
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
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    VehStep_Motion m_pMotionState;
    void activate_00c9c1d0();
    VehStep_Motion* getMotion()
    {
        activate_00c9c1d0();
        return &m_pMotionState;
    }
};

struct VehStep_AxleParams
{
    __declspec(align(16)) PacketCallLocal_00e38140 m_kFirstVector;
    __declspec(align(16)) PacketCallLocal_00e38140 m_kSecondAxleVector;
    __declspec(align(16)) PacketCallLocal_00e38140 m_kThirdVector;
    void* m_pFirstPointer;
    void* m_pSecondPointer;
    float m_fFirstScalar;
    float m_fSecondScalar;
    float m_fThirdValue;
    float m_fFourthValue;
    float m_fFifthScalar;
    float m_fSixthValue;
    unsigned char m_ucValue;

    void initialize()
    {
        reinterpret_cast<__m128&>(m_kFirstVector.m_vComponents) = _mm_setzero_ps();
        reinterpret_cast<__m128&>(m_kSecondAxleVector.m_vComponents) = _mm_setzero_ps();
        reinterpret_cast<__m128&>(m_kThirdVector.m_vComponents) = _mm_setzero_ps();
        m_fFirstScalar = 0.0f;
        m_fSecondScalar = 0.0f;
        m_fThirdValue = 0.0f;
        m_fFourthValue = 0.0f;
        m_fFifthScalar = 0.0f;
        m_fSixthValue = 0.0f;
        m_ucValue = 0;
        m_pFirstPointer = 0;
        m_pSecondPointer = 0;
    }
};

struct VehStep_Accumulator
{
    __declspec(align(16)) PacketCallLocal_00e38140 m_vLinearVelocity;
    __declspec(align(16)) PacketCallLocal_00e38140 m_vAngularVelocity;
    __declspec(align(16)) PacketCallLocal_00e38140 m_vInverseInertiaAndMass;
    __declspec(align(16)) PacketCallLocal_00e38140 m_vCenterOfMass;
    __declspec(align(16)) PacketCallLocal_00e38140 m_scratch1;
    __declspec(align(16)) PacketCallLocal_00e38140 m_scratch2;
    __declspec(align(16)) PacketCallLocal_00e38140 m_scratch3;
    __declspec(align(16)) PacketCallLocal_00e38140 m_coreFromWorld0;
    __declspec(align(16)) PacketCallLocal_00e38140 m_coreFromWorld1;
    __declspec(align(16)) PacketCallLocal_00e38140 m_coreFromWorld2;
    __declspec(align(16)) PacketCallLocal_00e38140 m_centerOfMassInWorld;
    __declspec(align(16)) PacketCallLocal_00e38140 m_unkB0;
    __declspec(align(16)) PacketCallLocal_00e38140 m_unkC0;
    __declspec(align(16)) PacketCallLocal_00e38140 m_unkD0;
    __declspec(align(16)) PacketCallLocal_00e38140 m_unkE0;
    __declspec(align(16)) PacketCallLocal_00e38140 m_unkF0;
};

struct VehStep_FrictionParams
{
    VehStep_AxleParams m_akAxleParams[2];
    float m_fTorquePitchFactor;
    VehStep_Accumulator m_pChassisCollidable;
    VehStep_Accumulator m_kSecondAccumulator;
};

struct VehStep_Ground
{
    void* m_kPointA;
    void* m_kPointB;
};

struct VehStep_Accumulators
{
    VehStep_Accumulator m_ground0;
};

struct VehStep_Damper
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void ApplyVelocityDamping(float dt, struct VehStep_Vehicle& vehicle);
};

void __stdcall hkpVehicleInstance_applyFrictionSolver(const VUC_StepInfo& stepInfo, VehStep_FrictionParams& params);

struct VehStep_Vehicle
{
    void* m_vtbl;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_pOwningWorld;
    void* m_pCurrentSimulationIsland;
    unsigned int m_ulUserData;
    const char* m_name;
    VehStep_Entity* m_pEntity;
    VUC_Data* m_data;
    void* m_pDriverInput;
    void* m_pSteering;
    void* m_pVehicleEngine;
    void* m_pTransmission;
    void* m_pBrake;
    void* m_pSuspension;
    void* m_pAerodynamics;
    void* m_pWheelCollide;
    void* m_pTyremarksInfo;
    VehStep_Damper* m_pVelocityDamper;

    void UpdateWheelContactsAndAxleBodies(float dt, void* a2, void* a3, VehStep_Ground& ground, VehStep_FrictionParams& params);
    void ProcessEntries_00e37d60(const VUC_StepInfo& stepInfo, VehStep_Ground& ground, VehStep_Accumulator& atLast,
                      VehStep_Accumulators& accs, VehStep_FrictionParams& params);
    void UpdateFields_00e37740(const VUC_StepInfo& stepInfo, VehStep_FrictionParams& params);
    void UpdateFields_00e376e0(float dt, VehStep_Accumulator& chassis);
    void UpdateFields_00e380c0(VehStep_Accumulator& chassis);
    void UpdateGroundBodyVelocities(float dt, VehStep_FrictionParams& params, VehStep_Ground& ground);
    void ProcessEntries_00e38310(float dt, VehStep_Ground& ground, VehStep_FrictionParams& params);
    void hkpVehicleInstance_simulateVehicle(const VUC_StepInfo& stepInfo, VehStep_Output* out, void* a2, void* a3);
};

// Calls motion slots 5c and 60 with out's transforms, applies velocity damping, then runs the axle and friction helpers between two timer samples.
// @fnv 0x00e385e0
// src: XBOX_PDB 0x00e385e0
void VehStep_Vehicle::hkpVehicleInstance_simulateVehicle(const VUC_StepInfo& stepInfo, VehStep_Output* out, void* a2, void* a3)
{
    volatile unsigned int ticks;
    {
        VUC_Mon* mon = (VUC_Mon*)TlsGetValue(DAT_0126835c);
        char* pos = mon->m_kRayEnd;
        if (pos < mon->m_capMinus16)
        {
            VUC_Timer* t = (VUC_Timer*)pos;
            t->m_name = str_010eb844;
            _ReadWriteBarrier();
            ticks = (unsigned int)__rdtsc();
            t->m_ticks = ticks;
            mon->m_kRayEnd = pos + sizeof(VUC_Timer);
        }
    }

    float dt = stepInfo.m_fTimeStep;
    m_pEntity->getMotion()->slot5c(dt, &out->m_transform0);
    m_pEntity->getMotion()->slot60(dt, &out->m_transform1);

    if (m_pVelocityDamper)
        m_pVelocityDamper->ApplyVelocityDamping(dt, *this);

    VehStep_FrictionParams frictionParams;
    for (int i = 0; i < 2; i++)
        frictionParams.m_akAxleParams[i].initialize();
    VehStep_Ground ground;
    VehStep_Accumulators accumulators;
    ground.m_kPointA = 0;
    ground.m_kPointB = 0;

    UpdateWheelContactsAndAxleBodies(dt, a2, a3, ground, frictionParams);
    frictionParams.m_fTorquePitchFactor = m_data->m_fTorquePitchFactor;
    ProcessEntries_00e37d60(stepInfo, ground, frictionParams.m_kSecondAccumulator, accumulators, frictionParams);
    UpdateFields_00e37740(stepInfo, frictionParams);
    UpdateFields_00e376e0(dt, frictionParams.m_pChassisCollidable);
    hkpVehicleInstance_applyFrictionSolver(stepInfo, frictionParams);
    UpdateFields_00e380c0(frictionParams.m_pChassisCollidable);
    UpdateGroundBodyVelocities(dt, frictionParams, ground);
    ProcessEntries_00e38310(dt, ground, frictionParams);

    {
        VUC_Mon* mon = (VUC_Mon*)TlsGetValue(DAT_0126835c);
        char* pos = mon->m_kRayEnd;
        if (pos < mon->m_capMinus16)
        {
            VUC_Timer* t = (VUC_Timer*)pos;
            t->m_name = str_010c41f8;
            _ReadWriteBarrier();
            ticks = (unsigned int)__rdtsc();
            t->m_ticks = ticks;
            mon->m_kRayEnd = pos + sizeof(VUC_Timer);
        }
    }
}
}  // namespace fnv_00e385e0

struct FUN_00e39300_class
{
    __m128 unk00;
    __m128 unk10;
    float unk20;
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
    __m128 unk50;
    __m128 unk60;
    float unk70;
    __m128 unk80;
    __m128 unk90;
    __m128 unka0;
    __m128 unkb0;
    float unkc0;
    float unkc4;
    float unkc8;
    float unkcc;
    float unkd0;
    float unkd4;
    FUN_00e39300_class& CopyFieldsExcept48And4C(const FUN_00e39300_class* src);
};

// Copies most fields from src into this, skipping unk48 and unk4c, and returns *this.
// @fnv 0x00e39300
// src: GUESS 0x00e39300 (confidence: medium)
FUN_00e39300_class& FUN_00e39300_class::CopyFieldsExcept48And4C(const FUN_00e39300_class* src)
{
    unk00 = src->unk00;
    unk10 = src->unk10;
    unk20 = src->unk20;
    unk24 = src->unk24;
    unk28 = src->unk28;
    unk2c = src->unk2c;
    unk30 = src->unk30;
    unk34 = src->unk34;
    unk38 = src->unk38;
    unk3c = src->unk3c;
    unk40 = src->unk40;
    unk44 = src->unk44;
    unk50 = src->unk50;
    unk60 = src->unk60;
    unk70 = src->unk70;
    unk80 = src->unk80;
    unk90 = src->unk90;
    unka0 = src->unka0;
    unkb0 = src->unkb0;
    unkc0 = src->unkc0;
    unkc4 = src->unkc4;
    unkc8 = src->unkc8;
    unkcc = src->unkcc;
    unkd0 = src->unkd0;
    unkd4 = src->unkd4;
    return *this;
}

inline void* operator new(unsigned int, void* pvWhere)
{
    return pvWhere;
}

hkMemoryRouter& __cdecl GetMemoryRouterE39() throw();
void __cdecl hkArrayUtil__reserve(hkMemoryAllocator& kAlloc, void* pArray, int iNumElements, int iSizeElem);

template <class T> __forceinline void destructE39(T* pArr, int n)
{
    for (int i = 0; i < n; i++)
        pArr[i].~T();
}
template <class T> __forceinline void copyE39(T* pDst, const T* pSrc, int n)
{
    for (int i = 0; i < n; i++)
        pDst[i] = pSrc[i];
}
template <class T> __forceinline void constructWithArrayE39(T* pDst, int n, const T* pSrc)
{
    for (int i = 0; i < n; i++)
        ::new (static_cast<void*>(pDst + i)) T(pSrc[i]);
}
template <class T>
static __forceinline void hkClassArrayE39_reserve(hkArrayBase<T>& self, hkMemoryAllocator& kAlloc, int n);

template <class T>
static __forceinline hkArrayBase<T>& hkClassArrayE39_assign(hkArrayBase<T>& self, const hkArrayBase<T>& a);

template <class T>
static __forceinline void hkClassArrayE39_reserve(hkArrayBase<T>& self, hkMemoryAllocator& kAlloc, int n)
{
        if (self.getCapacity() < n)
        {
            int iCap2 = 2 * self.getCapacity();
            int iNewSize = (n < iCap2) ? iCap2 : n;
            hkArrayUtil__reserve(kAlloc, (&self), iNewSize, sizeof(T));
        }
    }

template <class T>
static __forceinline hkArrayBase<T>& hkClassArrayE39_assign(hkArrayBase<T>& self, const hkArrayBase<T>& a)
{
        hkMemoryAllocator& kAlloc = GetMemoryRouterE39().heap();
        const int iOldSize = self.m_iElementCount;
        const int iNewSize = a.m_iElementCount;
        int iCopiedSize = (iNewSize > iOldSize) ? iOldSize : iNewSize;
        hkClassArrayE39_reserve(self, kAlloc, iNewSize);
        destructE39(self.m_data + iNewSize, iOldSize - iNewSize);
        copyE39(self.m_data, a.m_data, iCopiedSize);
        constructWithArrayE39(self.m_data + iCopiedSize, iNewSize - iCopiedSize, a.m_data + iCopiedSize);
        self.m_iElementCount = iNewSize;
        return *(&self);
    }

struct hkClassArrayE39Policy
{
    template <class T>
    static __forceinline void destroy(hkArrayBase<T>& self) { }
    template <class T>
    static __forceinline void assign(hkArrayBase<T>& self, const hkArrayBase<T>& other) { hkClassArrayE39_assign(self, other); }
};
template <class T>
static __forceinline hkArrayBase<T>& hkPodArrayE39_assign(hkArrayBase<T>& self, const hkArrayBase<T>& a);

template <class T>
static __forceinline hkArrayBase<T>& hkPodArrayE39_assign(hkArrayBase<T>& self, const hkArrayBase<T>& a)
{
        hkMemoryAllocator& kAlloc = GetMemoryRouterE39().heap();
        if (self.getCapacity() < a.m_iElementCount)
        {
            if ((self.m_iCapacityState & 0x80000000) == 0)
                kAlloc.bufFree(self.m_data, self.getCapacity() * sizeof(T));
            int iNumBytes = a.m_iElementCount * sizeof(T);
            self.m_data = static_cast<T*>(kAlloc.bufAlloc(iNumBytes));
            self.m_iCapacityState = iNumBytes / (int)sizeof(T);
        }
        self.m_iElementCount = a.m_iElementCount;
        copyE39(self.m_data, a.m_data, self.m_iElementCount);
        return *(&self);
    }

struct hkPodArrayE39Policy
{
    template <class T>
    static __forceinline void destroy(hkArrayBase<T>& self) { }
    template <class T>
    static __forceinline void assign(hkArrayBase<T>& self, const hkArrayBase<T>& other) { hkPodArrayE39_assign(self, other); }
};

struct WheelE39
{
    WheelE39& operator=(const WheelE39& kOther);
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0C;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1C;
    int m_i20;
    int m_i24;
    int m_i28;
    int m_i2C;
    int m_i30;
    int m_i34;
    int m_i38;
    int m_i3C;
    int m_i40;
    int m_i44;
    int m_i48;
    int m_i4C;
    int m_i50;
    int m_i54;
    int m_i58;
    int m_i5C;
    int m_i60;
    int m_i64;
    int m_i68;
    int m_i6C;
    int m_i70;
    int m_i74;
    int m_i78;
    int m_i7C;
    int m_i80;
    int m_i84;
    int m_i88;
    int m_i8C;
    int m_i90;
    int m_i94;
    int m_i98;
    int m_i9C;
    int m_iA0;
    int m_iA4;
    int m_iA8;
    int m_iAC;
    int m_iB0;
    int m_iB4;
    int m_iB8;
    int m_iBC;
    int m_iC0;
    int m_iC4;
    int m_iC8;
    int m_iCC;
    int m_iD0;
    int m_iD4;
    int m_iD8;
    int m_iDC;
};
struct Block48E39
{
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0C;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1C;
    int m_i20;
    int m_i24;
    int m_i28;
    int m_i2C;
    int m_i30;
    int m_i34;
    int m_i38;
    int m_i3C;
    int m_i40;
    int m_i44;
};

class VehicleDataE39 : public hkReferencedObject
{
  public:
    VehicleDataE39& CopyVehicleFields(const VehicleDataE39& kOther);
    int m_i08;
    int m_i0C;
    int m_i10;
    hkStringPtr m_kName;
    int m_i18;
    int m_i1C;
    int m_i20;
    int m_i24;
    int m_i28;
    int m_i2C;
    int m_i30;
    int m_i34;
    int m_i38;
    int m_i3C;
    int m_i40;
    int m_i44;
    hkArray<WheelE39, hkClassArrayE39Policy> m_akWheels;
    Block48E39 m_kBlock54;
    int m_i9C;
    hkArray<char, hkPodArrayE39Policy> m_acFlags;
    float m_fAC;
    bool m_bB0;
    float m_fB4;
    float m_fB8;
    float m_fBC;
    hkArray<float, hkPodArrayE39Policy> m_afValues;
    bool m_bCC;
    bool m_bCD;
    bool m_bCE;
    float m_fD0;
};

// Copies all fields from kOther into this VehicleDataE39 instance and returns a reference to this.
// @fnv 0x00e39480
// src: GUESS 0x00e39480 (confidence: medium)
VehicleDataE39& VehicleDataE39::CopyVehicleFields(const VehicleDataE39& kOther)
{
    m_usMemSizeAndFlags = kOther.m_usMemSizeAndFlags;
    m_sReferenceCount = kOther.m_sReferenceCount;
    m_i08 = kOther.m_i08;
    m_i0C = kOther.m_i0C;
    m_i10 = kOther.m_i10;
    m_kName.CopyFrom(&kOther.m_kName);
    m_i18 = kOther.m_i18;
    m_i1C = kOther.m_i1C;
    m_i20 = kOther.m_i20;
    m_i24 = kOther.m_i24;
    m_i28 = kOther.m_i28;
    m_i2C = kOther.m_i2C;
    m_i30 = kOther.m_i30;
    m_i34 = kOther.m_i34;
    m_i38 = kOther.m_i38;
    m_i3C = kOther.m_i3C;
    m_i40 = kOther.m_i40;
    m_i44 = kOther.m_i44;
    m_akWheels = kOther.m_akWheels;
    m_kBlock54 = kOther.m_kBlock54;
    m_i9C = kOther.m_i9C;
    m_acFlags = kOther.m_acFlags;
    m_fAC = kOther.m_fAC;
    m_bB0 = kOther.m_bB0;
    m_fB4 = kOther.m_fB4;
    m_fB8 = kOther.m_fB8;
    m_fBC = kOther.m_fBC;
    m_afValues = kOther.m_afValues;
    m_bCC = kOther.m_bCC;
    m_bCD = kOther.m_bCD;
    m_bCE = kOther.m_bCE;
    m_fD0 = kOther.m_fD0;
    return *this;
}

extern "C" void _mm_store_ps(float*, __m128);
extern const __m128 DAT_01267e30;
extern const __m128 DAT_010c7190;
extern const __m128 DAT_010c71b0;
extern const float DAT_01012068;
extern const float DAT_01011d78;
extern "C" __m128 _mm_setr_ps(float, float, float, float);
extern "C" __m128 _mm_setzero_ps();
struct WheelInit
{
    __declspec(align(16)) PacketCallLocal_00e38140 m00;
    __declspec(align(16)) PacketCallLocal_00e38140 m10;
    float m20;
    int m24;
    int m28;
    float m2c, m30, m34, m38, m3c, m40, m44, m48, m4c;
    __declspec(align(16)) PacketCallLocal_00e38140 m50;
    __declspec(align(16)) PacketCallLocal_00e38140 m60;
    float m70, m74, m78, m7c;
    __declspec(align(16)) PacketCallLocal_00e38140 m80;
    __declspec(align(16)) PacketCallLocal_00e38140 m90;
    __declspec(align(16)) PacketCallLocal_00e38140 ma0;
    __declspec(align(16)) PacketCallLocal_00e38140 mb0;
    float mc0, mc4, mc8, mcc, md0, md4;
    void hkpVehicleInstance_WheelInfo_init();
};
// Loads preset vectors into m00, m10 and mb0, sets m90 to (1,0,0,0), m28 to -1 and m10.w to 1, and zeroes the other fields it touches.
// @fnv 0x00e370b0
// src: XBOX_PDB 0x00e370b0
void WheelInit::hkpVehicleInstance_WheelInfo_init()
{
    __m128 normal = DAT_010c7190;
    reinterpret_cast<__m128&>(m00.m_vComponents) = DAT_01267e30;
    reinterpret_cast<__m128&>(m10.m_vComponents) = normal;
    float* d = &m10.w;
    *d = 1.0f;
    reinterpret_cast<__m128&>(m50.m_vComponents) = _mm_setzero_ps();
    m20 = 0.0f;
    reinterpret_cast<__m128&>(m60.m_vComponents) = _mm_setzero_ps();
    m70 = 0.0f;
    reinterpret_cast<__m128&>(m80.m_vComponents) = _mm_setzero_ps();
    reinterpret_cast<__m128&>(ma0.m_vComponents) = _mm_setzero_ps();
    reinterpret_cast<__m128&>(m90.m_vComponents) = _mm_setr_ps(1.0f, 0.0f, 0.0f, 0.0f);
    m24 = 0;
    m28 = -1;
    reinterpret_cast<__m128&>(mb0.m_vComponents) = DAT_010c71b0;
    mc0 = 0.0f;
    mc4 = 0.0f;
    mc8 = 0.0f;
    mcc = 0.0f;
    md0 = 0.0f;
    md4 = 0.0f;
}

struct FnvVehicleState
{
    unsigned char active;
    unsigned int flags04;
    float scalar08;
    float scalar0c;
    __m128 vectors10;
    __m128 vectors20;
    __m128 vectors30;
    __m128 vectors40;
    __m128 vectors50;
    __m128 vectors60;
    __m128 vectors70;
};

// Sets active to 1, scalar08 to 0.0f, and zeroes all vectors in the FnvVehicleState.
// @fnv 0x00e37160
// src: HAVOK_SRC 0x00e37160
void __stdcall hkpVehicleInstance_handleFixedGroundAccum(int, FnvVehicleState* state)
{
    state->scalar08 = 0.0f;
    state->active = 1;
    __m128 zero = _mm_setzero_ps();
    state->vectors30 = zero;
    state->vectors10 = zero;
    state->vectors20 = zero;
    state->vectors40 = zero;
    state->vectors50 = zero;
    state->vectors60 = zero;
    state->vectors70 = zero;
}

// Frees the backing buffers of m_kSecondRealArray and m_kFirstRealArray via the thread allocator and resets their state to empty.
// @fnv 0x00e39400
FUN_00e39400::~FUN_00e39400() throw()
{
    hkMemoryRouter* m = (hkMemoryRouter*)hkMemoryRouter_getInstance();
    hkMemoryAllocator* alloc = m->m_heap;
    int c = m_kSecondRealArray.m_iCapacityState;
    m_kSecondRealArray.m_iElementCount = 0;
    if (!(c & 0x80000000))
        alloc->bufFree(m_kSecondRealArray.m_data, c & 0x3fffffff);
    m_kSecondRealArray.m_data = 0;
    m_kSecondRealArray.m_iCapacityState = 0x80000000;
    m = (hkMemoryRouter*)hkMemoryRouter_getInstance();
    alloc = m->m_heap;
    c = m_kFirstRealArray.m_iCapacityState;
    m_kFirstRealArray.m_iElementCount = 0;
    if (!(c & 0x80000000))
        alloc->bufFree(m_kFirstRealArray.m_data, (c & 0x3fffffff) * 4);
    m_kFirstRealArray.m_data = 0;
    m_kFirstRealArray.m_iCapacityState = 0x80000000;
}

extern "C" __m128 _mm_unpacklo_ps(__m128, __m128);

extern "C" __m128 _mm_unpackhi_ps(__m128, __m128);

extern "C" __m128 _mm_movelh_ps(__m128, __m128);

extern "C" __m128 _mm_movehl_ps(__m128, __m128);

extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);

extern "C" __m128 _mm_mul_ps(__m128, __m128);

extern "C" __m128 _mm_add_ps(__m128, __m128);

extern "C" __m128 _mm_sub_ps(__m128, __m128);

extern "C" __m128 _mm_min_ps(__m128, __m128);

extern "C" __m128 _mm_max_ps(__m128, __m128);

extern "C" __m128 _mm_xor_ps(__m128, __m128);

extern "C" __m128 _mm_set_ps1(float);

extern const __m128 DAT_010c44d0;


static inline void SetAllComponents(PacketCallLocal_00e38140& vector, float value)
{
    reinterpret_cast<__m128&>(vector.m_vComponents) = _mm_set_ps1(value);
}

struct VehFr_Accumulator
{

    int m_type;

    int unk04;

    int unk08;

    int unk0C;

    __declspec(align(16)) PacketCallLocal_00e38140 m_vLinearVelocity;

    __declspec(align(16)) PacketCallLocal_00e38140 m_vAngularVelocity;

    __declspec(align(16)) PacketCallLocal_00e38140 m_vInverseInertiaAndMass;

    __declspec(align(16)) PacketCallLocal_00e38140 m_vCenterOfMass;

    __declspec(align(16)) PacketCallLocal_00e38140 m_coreFromWorld0;

    __declspec(align(16)) PacketCallLocal_00e38140 m_coreFromWorld1;

    __declspec(align(16)) PacketCallLocal_00e38140 m_coreFromWorld2;
};

struct VehFr_AxleParams
{

    __declspec(align(16)) PacketCallLocal_00e38140 m_kFirstVector;

    __declspec(align(16)) PacketCallLocal_00e38140 m_kSecondAxleVector;

    __declspec(align(16)) PacketCallLocal_00e38140 m_kThirdVector;

    VehFr_Accumulator* m_pFirstPointer;

    VehFr_Accumulator* m_pSecondPointer;

    float m_fFirstScalar;

    float m_fSecondScalar;

    float m_fThirdValue;

    float m_fFourthValue;

    float m_fFifthScalar;

    float m_fSixthValue;

    unsigned char m_ucValue;
};

struct VehFr_FrictionParams
{

    VehFr_AxleParams m_akAxleParams[2];
};

struct VehFr_Motion
{

    virtual void slot00();

    virtual void slot04();

    virtual void slot08();

    virtual void slot0c();

    virtual void slot10();

    virtual void slot14();

    virtual void slot18();

    virtual void slot1c();

    virtual void slot20();

    virtual void slot24();

    virtual void slot28();

    virtual void slot2c();

    virtual void slot30();

    virtual void slot34();

    virtual void slot38();

    virtual void slot3c();

    virtual void SetTranslationalVelocity(const PacketCallLocal_00e38140& v);

    virtual void SetRotationalVelocity(const PacketCallLocal_00e38140& v);
};

struct VehFr_MotionBody : VehFr_Motion
{

    int unk04;

    unsigned char m_type;
};

struct VehFr_MotionData
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
    int unk34;
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

    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;

    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;

    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;

    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;

    __declspec(align(16)) PacketCallLocal_00e38140 m_kTranslationalVelocity;

    __declspec(align(16)) PacketCallLocal_00e38140 m_kAngularVelocity;
};

struct VehFr_Entity
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
    int unk34;
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

    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;

    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;

    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;

    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;

    VehFr_Motion m_pMotionState;

    int unkE4;

    unsigned char m_bFlag;

    unsigned char unkE9;

    unsigned char unkEA;

    unsigned char unkEB;

    int unkEC;
};

struct VehFr_Ground
{

    VehFr_Entity* m_apEntities[2];
};

struct VehFr_Data
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
    int unk34;
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

    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;

    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;

    int m_iWheelCount;
};

struct VehFr_Vehicle
{

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;

    VehFr_Data* m_data;

    void UpdateGroundBodyVelocities(float dt, VehFr_FrictionParams& params, VehFr_Ground& ground);
};

// For each wheel with a ground body, moves its angular and linear velocity toward the axle accumulator's, changing each by at most dt*10.
// @fnv 0x00e38140
// src: GUESS 0x00e38140 (confidence: medium)
void VehFr_Vehicle::UpdateGroundBodyVelocities(float dt, VehFr_FrictionParams& params, VehFr_Ground& ground)

{

    VehFr_AxleParams* axle = params.m_akAxleParams;
    for (int i = 0; i < m_data->m_iWheelCount; i++)

    {

        VehFr_Entity* groundBody = ground.m_apEntities[i];

        if (!groundBody || groundBody->m_bFlag == 5)

        {
            ++axle;
            continue;
        }

        if (i != 0 && ground.m_apEntities[0] == ground.m_apEntities[1])

        {
            ++axle;
            continue;
        }

        VehFr_Motion* motion = &groundBody->m_pMotionState;

        VehFr_Accumulator* acc = axle->m_pFirstPointer;

        PacketCallLocal_00e38140 angVel;

        {

            __m128 c0 = reinterpret_cast<__m128&>(acc->m_coreFromWorld0.m_vComponents);

            __m128 c1 = reinterpret_cast<__m128&>(acc->m_coreFromWorld1.m_vComponents);

            __m128 c2 = reinterpret_cast<__m128&>(acc->m_coreFromWorld2.m_vComponents);

            __m128 tmp = _mm_unpacklo_ps(c0, c1);

            __m128 ctmp = _mm_unpackhi_ps(c0, c1);

            c0 = _mm_movelh_ps(tmp, c2);

            tmp = _mm_movehl_ps(c0, tmp);

            c1 = _mm_shuffle_ps(tmp, c2, 0xd4);

            c2 = _mm_shuffle_ps(ctmp, c2, 0xe4);

            const __m128 b = reinterpret_cast<__m128&>(acc->m_vAngularVelocity.m_vComponents);

            const __m128 b0 = _mm_shuffle_ps(b, b, 0x00);

            const __m128 r0 = _mm_mul_ps(c0, b0);

            const __m128 b1 = _mm_shuffle_ps(b, b, 0x55);

            const __m128 r1 = _mm_mul_ps(c1, b1);

            const __m128 b2 = _mm_shuffle_ps(b, b, 0xaa);

            const __m128 r2 = _mm_mul_ps(c2, b2);

            reinterpret_cast<__m128&>(angVel.m_vComponents) = _mm_add_ps(_mm_add_ps(r0, r1), r2);
        }

        acc = (VehFr_Accumulator*)&acc->m_vLinearVelocity;

        PacketCallLocal_00e38140 linVel = *(const PacketCallLocal_00e38140*)&acc->m_type;

        {

            PacketCallLocal_00e38140 cur = ((VehFr_MotionData*)motion)->m_kAngularVelocity;

            PacketCallLocal_00e38140 kMaxDelta;
            SetAllComponents(kMaxDelta, dt * 10.0);

            __m128 d = _mm_sub_ps(reinterpret_cast<__m128&>(angVel.m_vComponents), reinterpret_cast<__m128&>(cur.m_vComponents));

            d = _mm_min_ps(d, reinterpret_cast<__m128&>(kMaxDelta.m_vComponents));

            d = _mm_max_ps(d, _mm_xor_ps(reinterpret_cast<__m128&>(kMaxDelta.m_vComponents), DAT_010c44d0));

            reinterpret_cast<__m128&>(angVel.m_vComponents) = _mm_add_ps(d, reinterpret_cast<__m128&>(cur.m_vComponents));
        }

        {

            PacketCallLocal_00e38140 cur = ((VehFr_MotionData*)motion)->m_kTranslationalVelocity;

            PacketCallLocal_00e38140 kMaxDelta;
            SetAllComponents(kMaxDelta, dt * 10.0);

            __m128 d = _mm_sub_ps(reinterpret_cast<__m128&>(linVel.m_vComponents), reinterpret_cast<__m128&>(cur.m_vComponents));

            d = _mm_min_ps(d, reinterpret_cast<__m128&>(kMaxDelta.m_vComponents));

            d = _mm_max_ps(d, _mm_xor_ps(reinterpret_cast<__m128&>(kMaxDelta.m_vComponents), DAT_010c44d0));

            reinterpret_cast<__m128&>(linVel.m_vComponents) = _mm_add_ps(d, reinterpret_cast<__m128&>(cur.m_vComponents));
        }

        motion->SetRotationalVelocity(angVel);

        motion->SetTranslationalVelocity(linVel);
        ++axle;
    }
}

namespace fnv_00e38b20 {
class FUN_00d2b260
{
  public:
    FUN_00d2b260(void* pkEntity, unsigned long ulUserData) throw();
    virtual ~FUN_00d2b260() throw();

    int unk04, unk08, unk0C, unk10, unk14, unk18;
};

struct AxisStatusE38B
{
    float m_fAxisStatusMetric1;
    float m_fAxisStatusMetric2;
    float m_fAxisStatusMetric3;
    float m_fAxisStatusMetric4;
    float m_fAxisStatusMetric5;
    float m_fAxisStatusMetric6;
    float m_fAxisStatusMetric7;
    float m_fAxisStatusMetric8;
    float m_fAxisStatusMetric9;

    AxisStatusE38B()
    {
        m_fAxisStatusMetric1 = 0.0f;
        m_fAxisStatusMetric2 = 0.0f;
        m_fAxisStatusMetric3 = 0.0f;
        m_fAxisStatusMetric4 = 0.0f;
        m_fAxisStatusMetric5 = 0.0f;
        m_fAxisStatusMetric6 = 0.0f;
        m_fAxisStatusMetric7 = 0.0f;
        m_fAxisStatusMetric8 = 0.0f;
        m_fAxisStatusMetric9 = 0.0f;
    }
};

struct FrictionStatusE38B
{
    AxisStatusE38B m_kAxisEndPoints[2];
};

class FUN_00e38b20 : public FUN_00d2b260
{
  public:
    void* m_data;
    void* m_pDriverInput;
    void* m_pSteering;
    void* m_pVehicleEngine;
    void* m_pTransmission;
    void* m_pBrake;
    void* m_pSuspension;
    void* m_pAerodynamics;
    void* m_pWheelCollide;
    void* m_pTyremarksInfo;
    void* m_pVelocityDamper;
    hkArray<hkpVehicleInstanceWheelInfo> m_kWheelInfoArray;
    FrictionStatusE38B m_kFrictionStatus;
    void* m_pDriverInputStatus;
    hkArray<hkBool> m_kSecondRealArray;
    float m_fBrakeState;
    bool m_bIsReversing;
    float m_fFirstValueBeforeSteeringAngle;
    float m_fSecondValueBeforeSteeringAngle;
    float m_fMainSteeringAngle;
    hkArray<float> m_kWheelSteeringAngles;

    FUN_00e38b20(void* pkChassis) throw();
    virtual ~FUN_00e38b20() throw();
};

// Passes pkChassis and 0 to the base constructor and zeroes m_data and the subsystem pointer members.
// @fnv 0x00e38b20
FUN_00e38b20::FUN_00e38b20(void* pkChassis) throw() : FUN_00d2b260(pkChassis, 0)
{
    m_data = 0;
    m_pDriverInput = 0;
    m_pSteering = 0;
    m_pVehicleEngine = 0;
    m_pTransmission = 0;
    m_pBrake = 0;
    m_pSuspension = 0;
    m_pAerodynamics = 0;
    m_pWheelCollide = 0;
    m_pTyremarksInfo = 0;
    m_pVelocityDamper = 0;
    m_pDriverInputStatus = 0;
}
}  // namespace fnv_00e38b20

extern "C" __m128 _mm_add_ss(__m128 _A, __m128 _B);
extern "C" float _mm_cvtss_f32(__m128 _A);
extern "C" __m128 _mm_sqrt_ss(__m128 _A);


static inline __m128 SquareVector(const PacketCallLocal_00e38140& vector)
{
    const __m128& components = reinterpret_cast<const __m128&>(vector.m_vComponents);
    return _mm_mul_ps(components, components);
}

struct S00e37880_Data
{
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000c;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001c;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002c;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003c;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004c;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005c;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006c;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007c;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008c;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009c;
    int unk00a0;
    int unk00a4;
    int unk00a8;
    int unk00ac;
    int unk00b0;
    int unk00b4;
    int unk00b8;
    int unk00bc;
    int unk00c0;
    int unk00c4;
    int unk00c8;
    int unk00cc;
    int unk00d0;
    int unk00d4;
    int unk00d8;
    int unk00dc;
    int unk00e0;
    int unk00e4;
    int unk00e8;
    int unk00ec;
    int unk00f0;
    int unk00f4;
    int unk00f8;
    int unk00fc;
    int unk0100;
    int unk0104;
    int unk0108;
    int unk010c;
    int unk0110;
    int unk0114;
    int unk0118;
    int unk011c;
    int unk0120;
    int unk0124;
    int unk0128;
    int unk012c;
    int unk0130;
    int unk0134;
    int unk0138;
    int unk013c;
    int unk0140;
    int unk0144;
    int unk0148;
    int unk014c;
    int unk0150;
    int unk0154;
    int unk0158;
    int unk015c;
    int unk0160;
    int unk0164;
    int unk0168;
    int unk016c;
    int unk0170;
    int unk0174;
    int unk0178;
    int unk017c;
    int unk0180;
    int unk0184;
    int unk0188;
    int unk018c;
    int unk0190;
    int unk0194;
    int unk0198;
    int unk019c;
    int unk01a0;
    int unk01a4;
    int unk01a8;
    int unk01ac;
    __declspec(align(16)) PacketCallLocal_00e38140 m_vec;
};

struct S00e37880_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    S00e37880_Data* m_data;

    float hkpVehicleInstance_calcMPH();
};

// Returns the length of m_data->m_vec scaled by 3600 / 1609.3, a metres-per-second to miles-per-hour conversion.
// @fnv 0x00e37880
// src: HAVOK_SRC 0x00e37880
float S00e37880_Obj::hkpVehicleInstance_calcMPH()
{
    __m128 v = SquareVector(m_data->m_vec);
    __m128 a = _mm_shuffle_ps(v, v, 0x55);
    __m128 b = _mm_shuffle_ps(v, v, 0xaa);
    a = _mm_add_ss(a, v);
    b = _mm_add_ss(b, a);
    return (float)(_mm_cvtss_f32(_mm_sqrt_ss(b)) / 1609.300048828125 * 3600.0);
}

extern double DAT_01017b70;
extern double DAT_01012640;
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_sqrt_ss(__m128);
extern "C" float _mm_cvtss_f32(__m128);


struct SpeedBodyE378
{
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
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    __declspec(align(16)) PacketCallLocal_00e38140 m_kTranslationalVelocity;
    const PacketCallLocal_00e38140& linearVelocity() const
    {
        return m_kTranslationalVelocity;
    }
};
struct VehicleSpeedE378 : hkpVehicleInstance
{
    float hkpVehicleInstance_calcKMPH();
};
// Returns the length of the entity's linear velocity divided by DAT_01017b70 and multiplied by DAT_01012640.
// @fnv 0x00e37820
// src: HAVOK_SRC 0x00e37820
float VehicleSpeedE378::hkpVehicleInstance_calcKMPH()
{
    return float(
        (double(_mm_cvtss_f32(reinterpret_cast<const SpeedBodyE378*>(m_pEntity)->linearVelocity().length3())) / DAT_01017b70) *
        DAT_01012640);
}

extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_sqrt_ss(__m128);
extern "C" void _mm_store_ss(float*, __m128);
extern "C" float _mm_cvtss_f32(__m128);

struct S00e375a0_AxleData
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
};


class S00e375a0_hkpRigidBody
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    __declspec(align(16)) PacketCallLocal_00e38140 m_kInertiaAndMassInv;
    __declspec(align(16)) PacketCallLocal_00e38140 m_kTranslationalVelocity;
};

class S00e375a0_VehicleInstance : public VUC_Instance
{
  public:
    int unk_veh20;
    int unk_veh24;
    int unk_veh28;
    int unk_veh2c;
    int unk_veh30;
    int unk_veh34;
    int unk_veh38;
    int unk_veh3c;
    int unk_veh40;
    int unk_veh44;
    hkArray<hkpVehicleInstanceWheelInfo> m_kWheelInfoArray;

    void ComputeValues_00e371d0(float deltaTime, int wheelIndex, float suspensionForce) throw();
    void ComputeValues_00e37350(int wheelIndex, float totalLinearForce, float suspensionForce, float linearVelocity,
                      S00e375a0_AxleData* axleData) throw();
    void UpdateWheelContactsAndAxleBodies(float deltaTime, VUC_RealArray& suspensionForceAtWheel, VUC_RealArray& totalLinearForceAtWheel,
                      S00e375a0_hkpRigidBody* maxMassBodyPerAxle[2], S00e375a0_AxleData* axleData);
};

// Iterates wheels, calls FUN_00e371d0 and FUN_00e37350, and tracks the max-mass contact body per axle in maxMassBodyPerAxle.
// @fnv 0x00e375a0
// src: GUESS 0x00e375a0 (confidence: medium)
void S00e375a0_VehicleInstance::UpdateWheelContactsAndAxleBodies(float deltaTime, VUC_RealArray& suspensionForceAtWheel,
                                             VUC_RealArray& totalLinearForceAtWheel,
                                             S00e375a0_hkpRigidBody* maxMassBodyPerAxle[2],
                                             S00e375a0_AxleData* axleData)
{
    S00e375a0_hkpRigidBody* chassis = (S00e375a0_hkpRigidBody*)m_pEntity;
    float linearVelocity;
    _mm_store_ss(&linearVelocity, chassis->m_kTranslationalVelocity.length3());

    for (int i = 0; i < (int)m_data->m_iWheelCount; ++i)
    {
        int axle = m_data->m_kWheelParams[i].m_iAxle;
        hkpVehicleInstanceWheelInfo* wheelInfo = &m_kWheelInfoArray.m_data[i];

        ComputeValues_00e371d0(deltaTime, i, suspensionForceAtWheel.m_data[i]);

        S00e375a0_hkpRigidBody* contactBody = reinterpret_cast<S00e375a0_hkpRigidBody*>(wheelInfo->m_pUserData);
        if (contactBody)
        {
            S00e375a0_hkpRigidBody* curMaxBody = maxMassBodyPerAxle[axle];
            if (!curMaxBody || contactBody->m_kInertiaAndMassInv.getW() < curMaxBody->m_kInertiaAndMassInv.getW())
            {
                maxMassBodyPerAxle[axle] = contactBody;
            }
        }

        ComputeValues_00e37350(i, totalLinearForceAtWheel.m_data[i], suspensionForceAtWheel.m_data[i], linearVelocity,
                     &axleData[axle]);
    }
}

struct VUC_DriverInputStandIn
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void UpdateDriverInput(float dt, VUC_Instance* instance, unsigned int deviceStatus, VUC_Filtered& f);
};

// Reads a byte from the instance, copies it into the filtered data, then calls the driver input update and writes the filtered byte back.
// @fnv 0x00e36f60
// src: HAVOK_LIB 0x00e36f60
__declspec(noinline) void VUC_Instance::hkpVehicleInstance_updateDriverInput(float dt, VUC_Filtered& f) throw()
{
    unsigned char* instanceByte = reinterpret_cast<unsigned char*>(this) + 0xb0;
    unsigned char* filteredByte = reinterpret_cast<unsigned char*>(&f) + 0x0d;

    unsigned int value = *instanceByte;
    *filteredByte = static_cast<unsigned char>(value);

    unsigned int deviceStatus = *reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(this) + 0x9c);

    VUC_DriverInputStandIn* driverInput =
        *reinterpret_cast<VUC_DriverInputStandIn**>(reinterpret_cast<unsigned char*>(this) + 0x20);

    driverInput->UpdateDriverInput(dt, this, deviceStatus, f);

    *instanceByte = *filteredByte;
}

struct VehicleAeroDispatch
{
    virtual void slot00() throw() = 0;
    virtual void slot04() throw() = 0;
    virtual void slot08() throw() = 0;
    virtual void calculate(float deltaTime, const hkpVehicleInstance* vehicle, void* output) throw() = 0;
};

class VehicleAeroInstance : public hkpVehicleInstance
{
  public:
    void hkpVehicleInstance_updateAerodynamics(float deltaTime, void* output) throw();
};

// @fnv 0x00e37080
// src: HAVOK_LIB 0x00e37080
void VehicleAeroInstance::hkpVehicleInstance_updateAerodynamics(float deltaTime, void* output) throw()
{
    VehicleAeroDispatch* aerodynamics = reinterpret_cast<VehicleAeroDispatch*>(m_pAerodynamics);
    aerodynamics->calculate(deltaTime, this, output);
}

template <class T, class A> __forceinline hkArray<T, A>& hkArray<T, A>::operator=(const hkArray<T, A>& other)
{
    A::assign(*this, other);
    return *this;
}
