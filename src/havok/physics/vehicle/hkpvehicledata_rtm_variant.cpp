typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
#define _INCLUDED_MM2
#include "../../../../include/hkArrayBase.h"

// src/havok/physics/vehicle/hkpvehicledata_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/vehicle/hkpvehicledata.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/vehicle/hkpvehicledata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/hkpvehicledata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpVehicleData.h"
#include "../../../../include/hkMemoryRouter.h"
// Exe 0x00e39ab0 FUN_00e39ab0: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).

#define FNV_FOURFLOATVECTOR_NO_SSE
// local form of hkVector4: 0x00e39ab0 needs the packed SimdReal packet alongside the reflection hkBase scalar hkVector4.


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

class VehiclePacketLocal_00e2
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

    VehiclePacketLocal_00e2();
    VehiclePacketLocal_00e2(float x, float y, float z, float w);
    VehiclePacketLocal_00e2(const __m128& vector);

    VehiclePacketLocal_00e2* hkVector4_hkVector4(float x, float y, float z, float w);
    void SetValue(VehiclePacketLocal_00e2* vector);
    void __thiscall SetQuaternionComponentsFromVector(const VehiclePacketLocal_00e2* vector);
    VehiclePacketLocal_00e2& ComputeValue_00e531a0(int parameter);
    VehiclePacketLocal_00e2 ProcessAndReturnValue_00e53260(int parameter);
    void normalize_005611c0();

    void operator=(const VehiclePacketLocal_00e2& vector);
    float& operator()(int index);
    const float& operator()(int index) const;
    float& component(int index);
    float& At(int index);
    const float& At(int index) const;

    __m128 length3() const;
    float getW() const;
    ScalarValue Dot(const VehiclePacketLocal_00e2& vector) const;
    ScalarValue LengthSq() const;
    ScalarValue Length() const;
    ScalarValue InverseLength() const;
    void Normalize();
    bool NormalizeNonzero();
    void Mul(const ScalarValue& scalar);
    void Add(const VehiclePacketLocal_00e2& vector);
    void Sub(const VehiclePacketLocal_00e2& vector);
    void Cross(const VehiclePacketLocal_00e2& a, const VehiclePacketLocal_00e2& b);

    void setAbs4(const VehiclePacketLocal_00e2& vector);
    void setMul4(const SimdReal& scalar, const VehiclePacketLocal_00e2& vector);
    void addMul4(const SimdReal& scalar, const VehiclePacketLocal_00e2& vector);
    void setAddMul4(const VehiclePacketLocal_00e2& a, const VehiclePacketLocal_00e2& b, const SimdReal& scalar);
    SimdReal getSimdAt3() const;
    SimdReal lengthSquared3() const;
    void setXYZ_W(__m128 xyz, __m128 w);
    void setSqrtInverse4(const VehiclePacketLocal_00e2& vector);
    void setAddMul(const VehiclePacketLocal_00e2& a, const VehiclePacketLocal_00e2& b, const SimdScalar& scalar);
    void addMul(const float& scalar, const VehiclePacketLocal_00e2& vector);
    void transformed(const Transform& transform, const VehiclePacketLocal_00e2& vector);
    void addScaled(const VehiclePacketLocal_00e2& base, const VehiclePacketLocal_00e2& direction, float amount);
    void* AddVector(void*, NiPoint3*, void*, float);
    void* AddVector(void*, void*);
    void* ScaleSwizzled();
};

#pragma pack(pop)

#undef FNV_FOURFLOATVECTOR_NO_SSE
extern "C"
{
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_and_ps(LocalM128, LocalM128);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
    LocalM128 _mm_set_ps1(float);
    LocalM128 _mm_load_ss(const float*);
    LocalM128 _mm_load_ps1(const float*);
    void _mm_store_ss(float*, LocalM128);
}
extern "C" void _ReadWriteBarrier();

extern LocalM128 DAT_01017d10;

__forceinline hkMemoryAllocator& heapOf(hkMemoryRouter* record)
{
    return *record->m_heap;
}
hkMemoryRouter* hkMemoryRouter_getInstance();
void __cdecl hkArrayUtil__reserve(hkMemoryAllocator& alloc, void* array, int numElements, int sizeElem);

class SimdReal
{
public:
    LocalM128 m_vValue;
    SimdReal()
    {}
    __forceinline SimdReal(float value)
    {
        m_vValue = _mm_load_ss(&value);
    }
    __forceinline operator float() const
    {
        float f;
        _mm_store_ss(&f, m_vValue);
        return f;
    }
};

__forceinline VehiclePacketLocal_00e2::VehiclePacketLocal_00e2()
{}

__forceinline void VehiclePacketLocal_00e2::operator=(const VehiclePacketLocal_00e2& v)
{
    reinterpret_cast<LocalM128&>(m_vComponents) = reinterpret_cast<const LocalM128&>(v.m_vComponents);
}
__forceinline float& VehiclePacketLocal_00e2::operator()(int i)
{
    return f[i];
}
__forceinline const float& VehiclePacketLocal_00e2::operator()(int i) const
{
    return f[i];
}
__forceinline void VehiclePacketLocal_00e2::setAbs4(const VehiclePacketLocal_00e2& v)
{
    reinterpret_cast<LocalM128&>(m_vComponents) = _mm_and_ps(reinterpret_cast<const LocalM128&>(v.m_vComponents), DAT_01017d10);
}
__forceinline void VehiclePacketLocal_00e2::setMul4(const SimdReal& r, const VehiclePacketLocal_00e2& v)
{
    reinterpret_cast<LocalM128&>(m_vComponents) = _mm_mul_ps(_mm_shuffle_ps(r.m_vValue, r.m_vValue, 0), reinterpret_cast<const LocalM128&>(v.m_vComponents));
}
__forceinline void VehiclePacketLocal_00e2::addMul4(const SimdReal& r, const VehiclePacketLocal_00e2& v)
{
    reinterpret_cast<LocalM128&>(m_vComponents) = _mm_add_ps(reinterpret_cast<const LocalM128&>(m_vComponents), _mm_mul_ps(_mm_shuffle_ps(r.m_vValue, r.m_vValue, 0), reinterpret_cast<const LocalM128&>(v.m_vComponents)));
}
__forceinline void VehiclePacketLocal_00e2::setAddMul4(const VehiclePacketLocal_00e2& a, const VehiclePacketLocal_00e2& b, const SimdReal& r)
{
    reinterpret_cast<LocalM128&>(m_vComponents) = _mm_add_ps(reinterpret_cast<const LocalM128&>(a.m_vComponents), _mm_mul_ps(_mm_shuffle_ps(r.m_vValue, r.m_vValue, 0), reinterpret_cast<const LocalM128&>(b.m_vComponents)));
}
__forceinline SimdReal VehiclePacketLocal_00e2::getSimdAt3() const
{
    SimdReal s;
    s.m_vValue = _mm_shuffle_ps(reinterpret_cast<const LocalM128&>(m_vComponents), reinterpret_cast<const LocalM128&>(m_vComponents), 0xff);
    return s;
}

struct __declspec(align(16)) FloatMatrix3
{
    VehiclePacketLocal_00e2 m_kColumn0;
    VehiclePacketLocal_00e2 m_kColumn1;
    VehiclePacketLocal_00e2 m_kColumn2;
    __forceinline VehiclePacketLocal_00e2& getColumn(int i)
    {
        return (&m_kColumn0)[i];
    }
    __forceinline const VehiclePacketLocal_00e2& getColumn(int i) const
    {
        return (&m_kColumn0)[i];
    }
    void FUN_00cd5610(const FloatMatrix3& a, const FloatMatrix3& b);
};

template <class T>
static __forceinline void Array_GrowArrayCapacity(hkArrayBase<T>& self, hkMemoryAllocator& alloc, int n)
{
        const int capacity = self.getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            hkArrayUtil__reserve(alloc, (&self), newSize, sizeof(T));
        }
    }

template <class T>
static __forceinline void Array__setSize(hkArrayBase<T>& self, hkMemoryAllocator& alloc, int n)
{
        Array_GrowArrayCapacity(self, alloc, n);
        self.m_iElementCount = n;
    }

template <class T>
static __forceinline void Array_SetSizeAndGrow(hkArrayBase<T>& self, int n)
{
        Array__setSize(self, heapOf(hkMemoryRouter_getInstance()), n);
    }

struct Motion
{
    void* vtable;
    int unk04;
    int unk08;
    int unk0C;
    FloatMatrix3 m_rotation;
    VehiclePacketLocal_00e2 m_vTranslation;
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
    VehiclePacketLocal_00e2 m_vCenterOfMassLocal;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    VehiclePacketLocal_00e2 m_kInertiaAndMassInv;

    float FUN_00c86430() const;
    __forceinline SimdReal getMassInv() const
    {
        return m_kInertiaAndMassInv.getSimdAt3();
    }
};

struct RigidBody
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
    Motion m_pMotionState;

    __forceinline float GetMassValue() const
    {
        return m_pMotionState.FUN_00c86430();
    }
    __forceinline SimdReal getMassInv() const
    {
        return m_pMotionState.getMassInv();
    }
    __forceinline const FloatMatrix3& getRotation() const
    {
        return m_pMotionState.m_rotation;
    }
    __forceinline const VehiclePacketLocal_00e2& getCenterOfMassLocal() const
    {
        return m_pMotionState.m_vCenterOfMassLocal;
    }
};

struct SuspensionWheelParameters
{
    VehiclePacketLocal_00e2 m_vHardpointChassisSpace;
    VehiclePacketLocal_00e2 m_vDirectionChassisSpace;
    float m_fRestLength;
    int unk24;
    int unk28;
    int unk2C;
};

struct WheelComponentParams
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
    char unk25;
    char unk26;
    char unk27;
};

struct __declspec(align(16)) FrictionCinfo
{
    VehiclePacketLocal_00e2 m_akFrictionVectors[2];
    VehiclePacketLocal_00e2 m_kVectorA;
    VehiclePacketLocal_00e2 m_kVectorB;
    VehiclePacketLocal_00e2 m_kVectorC;
    VehiclePacketLocal_00e2 m_kVectorD;
    FloatMatrix3 m_kFrictionMatrix;
    float m_fMaxVelocityForPositionalFriction;
    float m_fAxisFrictionTuning4[2];
    float m_fAxisFrictionTuning6[2];
    float m_fChassisUnitInertiaRoll;
};

void __cdecl hkVehicleFrictionDescriptionInitValues(const FrictionCinfo& ci, hkpVehicleFrictionDescription& out);

__forceinline hkArrayBase<WheelComponentParams>& wheelParamsOf(hkpVehicleData& d)
{
    return reinterpret_cast<hkArrayBase<WheelComponentParams>&>(d.m_kWheelParams);
}
__forceinline hkArrayBase<signed char>& wheelsPerAxleOf(hkpVehicleData& d)
{
    return reinterpret_cast<hkArrayBase<signed char>&>(d.m_kNumWheelsPerAxle);
}
__forceinline const FloatMatrix3& orientationOf(const hkpVehicleData& d)
{
    return reinterpret_cast<const FloatMatrix3&>(d.m_kChassisOrientation);
}
__forceinline VehiclePacketLocal_00e2& inertiaInvDiagOf(hkpVehicleData& d)
{
    return reinterpret_cast<VehiclePacketLocal_00e2&>(d.m_vChassisUnitInertiaAndMassInv);
}

__forceinline void initVehicleComponents(hkpVehicleData& self,
                                         const hkArrayBase<SuspensionWheelParameters>& suspensionWheelParams,
                                         const RigidBody* chassis)
{
    self.m_bWheelsUseChassisForGround = true;
    _ReadWriteBarrier();

    int axle = 0;
    if (self.m_iWheelCount > 0)
    {
        _ReadWriteBarrier();
        hkArrayBase<WheelComponentParams>& wheels = wheelParamsOf(self);
        int remaining = self.m_iWheelCount;
        int i = 0;
        do
        {
            if (wheels[i].m_iAxle + 1 > axle)
            {
                axle = wheels[i].m_iAxle + 1;
            }
            ++i;
        } while (--remaining);
    }

    if (axle > wheelsPerAxleOf(self).GetLogicalSize())
    {
        Array_SetSizeAndGrow(wheelsPerAxleOf(self), axle);
    }
    {
        for (int i = 0; i < wheelsPerAxleOf(self).GetLogicalSize(); i++)
        {
            wheelsPerAxleOf(self)[i] = 0;
        }
    }
    {
        hkArrayBase<WheelComponentParams>& params = wheelParamsOf(self);
        int i = 0;
        if (i < self.m_iWheelCount)
        {
            for (int offset = 0; i < self.m_iWheelCount; ++i, offset += sizeof(WheelComponentParams))
            {
                int axleIdx = reinterpret_cast<const WheelComponentParams*>(
                    reinterpret_cast<const char*>(params.m_data) + offset)->m_iAxle;
                wheelsPerAxleOf(self)[axleIdx]++;
            }
        }
    }

    {
        VehiclePacketLocal_00e2 absUp;
        absUp.setAbs4(orientationOf(self).getColumn(0));
        VehiclePacketLocal_00e2 absForward;
        absForward.setAbs4(orientationOf(self).getColumn(1));
        VehiclePacketLocal_00e2 absRight;
        absRight.setAbs4(orientationOf(self).getColumn(2));

        VehiclePacketLocal_00e2 ptr;
        ptr.setMul4(self.m_fTorqueMin / self.m_fTorqueRollFactor, absUp);
        ptr.addMul4(self.m_fChassisMass / self.m_fTorqueYawFactor, absForward);
        ptr.addMul4(self.m_fTorqueMax / self.m_fExtraTorqueFactor, absRight);
        ptr(3) = 1.0f;

        float idx = 1.0f / chassis->GetMassValue();
        inertiaInvDiagOf(self).setMul4(idx, ptr);
    }

    {
        FrictionCinfo ci;
        ci.m_kVectorA = chassis->getCenterOfMassLocal();
        {
            const FloatMatrix3& r = chassis->getRotation();
            FloatMatrix3 tmp;
            tmp.m_kColumn0.setMul4(inertiaInvDiagOf(self)(0), r.m_kColumn0);
            tmp.m_kColumn1.setMul4(inertiaInvDiagOf(self)(1), r.m_kColumn1);
            tmp.m_kColumn2.setMul4(inertiaInvDiagOf(self)(2), r.m_kColumn2);
            ci.m_kFrictionMatrix.FUN_00cd5610(tmp, r);
        }
        ci.m_fMaxVelocityForPositionalFriction = chassis->getMassInv();
        ci.m_kVectorD.setAbs4(orientationOf(self).getColumn(0));
        ci.m_fChassisUnitInertiaRoll = self.m_fChassisUnitInertiaRoll;
        ci.m_kVectorC.setAbs4(orientationOf(self).getColumn(1));
        ci.m_fAxisFrictionTuning4[0] = 0.0f;
        ci.m_fAxisFrictionTuning4[1] = 0.0f;
        ci.m_kVectorB.setAbs4(orientationOf(self).getColumn(2));

        for (int i = 0; i < self.m_iWheelCount; i++)
        {
            const SuspensionWheelParameters& sp = suspensionWheelParams[i];
            const WheelComponentParams& wp = wheelParamsOf(self)[i];
            int numAxles = wp.m_iAxle;
            ci.m_fAxisFrictionTuning6[numAxles] = wp.m_fSphereRadius;
            ci.m_akFrictionVectors[numAxles].setAddMul4(sp.m_vHardpointChassisSpace, sp.m_vDirectionChassisSpace,
                                                    sp.m_fRestLength);
            ci.m_fAxisFrictionTuning4[numAxles] += wp.m_fViscosityFriction * wp.m_fSphereRadius;
        }

        hkVehicleFrictionDescriptionInitValues(ci, self.m_kFrictionDescription);
    }
}

// @fnv 0x00e39ab0
// src: HAVOK_SRC 0x00e39ab0
void __fastcall hkpVehicleData_init(hkpVehicleData* self, int, const hkArrayBase<SuspensionWheelParameters>& suspensionWheelParams,
                             const RigidBody* chassis)
{
    initVehicleComponents(*self, suspensionWheelParams, chassis);
}
