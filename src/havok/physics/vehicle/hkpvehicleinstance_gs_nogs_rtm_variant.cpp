// Vehicle wheel update and ground-body preparation, VC9 RTM /O2 /GS- variant.
#include "../../../../include/hkpVehicleInstance.h"
#include "../../../../include/hkpVehicleInstanceWheelInfo.h"
#include "../../../../include/hkRotation.h"

extern "C" void _ReadWriteBarrier(void);
extern const float DAT_01011d78;

struct __declspec(align(16)) VUC_Vector4
{
    float x, y, z, w;
};
// Vehicle-data prefix used by this unit; the chassis orientation starts at 0x30.
struct VUC_Data
{
    void* m_vtbl;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    VUC_Vector4 m_kGravity;
    signed char m_iWheelCount;
    VUC_Vector4 m_kChassisOrientation[3];
#include "../../../../include/hkRotation.h"
};

namespace WheelUpdateBuild {
typedef ::__m128 WheelUpdateSimd;
using ::VUC_Vector4;
using ::VUC_Data;
using ::hkpVehicleInstance;
using ::DAT_01011d78;




struct __declspec(align(16)) WheelUpdateVector
{
    float x, y, z, w;
    void hkVector4_setRotatedDir(hkRotation* rot, WheelUpdateVector* dir) throw();
};

class WheelUpdateEntity
{
  public:
    void* m_vtbl;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_pOwningWorld;
    unsigned int m_ulUserData;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
    int unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c;
    int unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c;
    int unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac;
    int unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc;
    int unkd0, unkd4, unkd8, unkdc;
    int unke0, unke4, unke8, unkec;
    hkRotation m_rotation;
};

struct __declspec(align(16)) WheelUpdateSuspWheel
{
    VUC_Vector4 m_vHardpointChassisSpace;
    VUC_Vector4 m_vDirectionChassisSpace;
    float m_fRestLength;
};

class WheelUpdateSuspension
{
  public:
    void* m_vtbl;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    WheelUpdateSuspWheel* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

struct __declspec(align(16)) WheelUpdateContactPair
{
    VUC_Vector4 m_contactPos;
    VUC_Vector4 m_contactNormal;
    void operator=(const WheelUpdateContactPair& rhs)
    {
        *(WheelUpdateSimd*)&m_contactPos = *(WheelUpdateSimd*)&rhs.m_contactPos;
        *(WheelUpdateSimd*)&m_contactNormal = *(WheelUpdateSimd*)&rhs.m_contactNormal;
    }
};

struct __declspec(align(16)) WheelUpdateCdWheel
{
    WheelUpdateContactPair m_kPoint;
    float m_fSuspensionLength;
    void* m_pUserData;
    unsigned int m_uiContactShapeKeys[8];
    float m_fContactFriction;
    float m_fValueAtOffset4C;
    float m_fValueAtOffset50;
};


extern float DAT_01017718;
extern float DAT_01016248;
extern VUC_Vector4 DAT_010c71e0;

}

// @fnv 0x00e37aa0
void hkpVehicleInstance::UpdateVehicle(hkReal dt, const hkpVehicleWheelCollide::WheelCollideResult* det)
{
    using namespace WheelUpdateBuild;
    hkpVehicleInstance* self = (hkpVehicleInstance*)this;
    hkRotation* chassisRot = &((WheelUpdateEntity*)self->m_pEntity)->m_rotation;
    int i = 0;
    if (i < ((VUC_Data*)self->m_data)->m_iWheelCount)
    {
        WheelUpdateSimd zero128 = _mm_set_ss(DAT_01011d78);
        WheelUpdateSimd three128 = _mm_set_ss(DAT_01017718);
        WheelUpdateSimd half128 = _mm_set_ss(DAT_01016248);
        const WheelUpdateCdWheel* cdInfo = (const WheelUpdateCdWheel*)det;
        int ci = 0;
        do
        {
            int fi = i;
            const WheelUpdateCdWheel* cd = &cdInfo[i];
            hkpVehicleInstanceWheelInfo* wheel = &self->m_kWheelInfoArray.m_data[i];
            *(float*)&self->m_kWheelInfoArray.m_data[i].unk70 = cd->m_fContactFriction;
            *(WheelUpdateContactPair*)&self->m_kWheelInfoArray.m_data[i].unk00 = cd->m_kPoint;
            *(float*)&self->m_kWheelInfoArray.m_data[fi].unk20 = cd->m_fSuspensionLength;
            self->m_kWheelInfoArray.m_data[fi].m_pUserData = (hkpRigidBody*)cd->m_pUserData;
            for (int j = -1; j < 7; ++j)
                ((unsigned int*)&self->m_kWheelInfoArray.m_data[i].unk28)[j + 1] =
                    cdInfo[ci].m_uiContactShapeKeys[j + 1];

            float half = self->m_kWheelSteeringAngles.m_data[i] * 0.5;
            WheelUpdateSimd h = _mm_load_ss(&half);
            WheelUpdateSimd hb = ::_mm_shuffle_ps(h, h, 0);
            WheelUpdateSimd axis =
                *(WheelUpdateSimd*)&((WheelUpdateSuspension*)self->m_pSuspension)->m_data[i].m_vDirectionChassisSpace;
            VUC_Vector4 qv;
            *(WheelUpdateSimd*)&qv = ::_mm_mul_ps(hb, axis);
            qv.w = 1.0f;
            WheelUpdateSimd q = *(WheelUpdateSimd*)&qv;
            WheelUpdateSimd sq = ::_mm_mul_ps(q, q);
            WheelUpdateSimd sum = ::_mm_add_ps(::_mm_shuffle_ps(sq, sq, 0x4e), sq);
            WheelUpdateSimd lenSq = ::_mm_add_ps(::_mm_shuffle_ps(sum, sum, 0xb1), sum);
            WheelUpdateSimd r = _mm_rsqrt_ss(lenSq);
            WheelUpdateSimd mask = _mm_cmpeq_ss(lenSq, zero128);
            WheelUpdateSimd newton = _mm_mul_ss(lenSq, r);
            newton = _mm_mul_ss(newton, r);
            newton = _mm_sub_ss(three128, newton);
            WheelUpdateSimd inv = _mm_mul_ss(half128, r);
            inv = _mm_mul_ss(inv, newton);
            inv = _mm_andnot_ps(mask, inv);
            q = ::_mm_mul_ps(q, ::_mm_shuffle_ps(inv, inv, 0));
            *(WheelUpdateSimd*)&wheel->unkb0 = q;
            *(WheelUpdateSimd*)&wheel->unk90 =
                *(WheelUpdateSimd*)&((VUC_Data*)self->m_data)->m_kChassisOrientation[2];
            ::_ReadWriteBarrier();
            WheelUpdateSimd qq = *(WheelUpdateSimd*)&wheel->unkb0;
            WheelUpdateSimd v = *(WheelUpdateSimd*)&wheel->unk90;
            WheelUpdateSimd w = ::_mm_shuffle_ps(qq, qq, 0xff);
            WheelUpdateSimd prod = ::_mm_mul_ps(v, qq);
            WheelUpdateSimd y = ::_mm_shuffle_ps(prod, prod, 0x55);
            WheelUpdateSimd xy = ::_mm_add_ss(y, prod);
            WheelUpdateSimd z = ::_mm_shuffle_ps(prod, prod, 0xaa);
            WheelUpdateSimd dot = ::_mm_add_ss(z, xy);
            WheelUpdateSimd cross =
                ::_mm_sub_ps(::_mm_mul_ps(::_mm_shuffle_ps(v, v, 0xd2), ::_mm_shuffle_ps(qq, qq, 0xc9)),
                             ::_mm_mul_ps(::_mm_shuffle_ps(v, v, 0xc9), ::_mm_shuffle_ps(qq, qq, 0xd2)));
            cross = ::_mm_mul_ps(cross, w);
            WheelUpdateSimd ww = ::_mm_mul_ps(w, w);
            ww = ::_mm_add_ps(ww, *(WheelUpdateSimd*)&DAT_010c71e0);
            ww = ::_mm_mul_ps(ww, v);
            WheelUpdateSimd term = ::_mm_add_ps(ww, ::_mm_mul_ps(::_mm_shuffle_ps(dot, dot, 0), qq));
            WheelUpdateSimd result = ::_mm_add_ps(cross, term);
            result = ::_mm_add_ps(result, result);
            WheelUpdateVector spin;
            *(WheelUpdateSimd*)&spin = result;
            ((WheelUpdateVector*)&wheel->unka0)->hkVector4_setRotatedDir(chassisRot, &spin);
            ++ci;
            ++i;
        } while (i < ((VUC_Data*)self->m_data)->m_iWheelCount);
    }
}

namespace AxleGroundBuild {
typedef ::__m128 AxleQuad;
using ::hkVector4;
using ::hkRotation;
using ::hkpVehicleInstance;
using ::_mm_add_ps;
using ::_mm_mul_ps;
using ::_mm_shuffle_ps;
using ::_mm_setzero_ps;
using ::_mm_add_ss;
using ::_mm_sub_ps;
using ::_mm_store_ss;



struct Accumulator
{
    char m_noHit;
    char unk01;
    char unk02;
    char unk03;
    int unk04;
    float m_fHitFraction;
    int unk0C;
    hkVector4 m_vContactPoint;
    hkVector4 m_contactNormal;
    hkVector4 m_vec30;
    hkVector4 m_vec40;
    hkRotation m_rotation;

    void InitializeFields_00d72030(const Accumulator& other);
};

class AxleParams
{
  public:
    hkVector4 unk00;
    hkVector4 m_rayDirWs;
    hkVector4 m_wheelDirWs;
    Accumulator* m_contactBody1;
    Accumulator* m_contactBody2;
    int unk38;
    int unk3C;
    hkVector4 unk40;
    hkVector4 unk50;
};

struct VelocityVector
{
    AxleQuad q;
    void setSub4(const AxleQuad& a, const AxleQuad& b)
    {
        q = _mm_sub_ps(a, b);
    }
    void mul4(float s)
    {
        AxleQuad t = _mm_load_ss(&s);
        t = _mm_shuffle_ps(t, t, 0);
        q = _mm_mul_ps(q, t);
    }
    void setMul4(float r, const AxleQuad& a)
    {
        AxleQuad t = _mm_load_ss(&r);
        t = _mm_shuffle_ps(t, t, 0);
        q = _mm_mul_ps(t, a);
    }
};

struct GroundMotion
{
    float getInvDeltaTime() const
    {
        return m_float6C;
    }
    int unk00;
    int unk04;
    unsigned char m_bFlag;
    char unk09;
    char unk0A;
    char unk0B;
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
    AxleQuad unk50;
    union
    {
        AxleQuad unk60;
        struct
        {
            float unk60_x, unk60_y, unk60_z;
            float m_float6C;
        };
    };
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
    AxleQuad unkA0;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    AxleQuad unkC0;
};

struct GroundBody
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
    GroundMotion m_pMotionState;
};

class AxleDataView
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
    float m_fChassisUnitInertiaYaw;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int m_iWheelCount;
};

extern "C" void __cdecl hkRigidMotionUtilApplyForcesAndBuildAccumulators(void* arg1, GroundMotion** motions, int numMotions, int offset,
                                     Accumulator* accumOut);

class Vehicle : public hkpVehicleInstance
{
  public:
    // The shared vf15 declaration lacks the ground-body/accumulator parameters.
    // Dispatch through its original vtable slot until that signature is available.
    __forceinline void prepareFixedGroundBody(GroundBody* body, Accumulator* contact)
    {
        typedef void (__thiscall *Prepare)(hkpVehicleInstance*, GroundBody*, Accumulator*);
        reinterpret_cast<Prepare>((*reinterpret_cast<void***>(this))[15])(this, body, contact);
    }

    void ProcessEntries_00e37d60(void* arg1, GroundBody** arg2, Accumulator* arg3, Accumulator* arg4, AxleParams* arg5);
};

__forceinline void normalizeDirection(hkVector4& v)
{
    AxleQuad v_in = *(AxleQuad*)&v;
    AxleQuad sq = _mm_mul_ps(v_in, v_in);
    AxleQuad y2 = _mm_shuffle_ps(sq, sq, 0x55);
    AxleQuad xy2 = _mm_add_ss(y2, sq);
    AxleQuad z2 = _mm_shuffle_ps(sq, sq, 0xaa);
    AxleQuad lenSq = _mm_add_ss(z2, xy2);
    AxleQuad approx = _mm_rsqrt_ss(lenSq);
    AxleQuad muls = _mm_mul_ss(_mm_mul_ss(lenSq, approx), approx);
    AxleQuad isZero = _mm_cmpeq_ss(lenSq, _mm_set_ss(0.0f));
    AxleQuad factor = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), approx), _mm_sub_ss(_mm_set_ss(3.0f), muls));
    AxleQuad invLen = _mm_andnot_ps(isZero, factor);
    AxleQuad invLen4 = _mm_shuffle_ps(invLen, invLen, 0);
    *(AxleQuad*)&v = _mm_mul_ps(v_in, invLen4);
}

__forceinline float inverseMass(const AxleQuad& v)
{
    float res;
    AxleQuad w = _mm_shuffle_ps(v, v, 0xff);
    _mm_store_ss(&res, w);
    return res;
}

__forceinline void rotateDirection(hkVector4& out, const hkRotation& a, const AxleQuad& b)
{
    AxleQuad v1 = _mm_mul_ps(_mm_shuffle_ps(b, b, 0x55), *(AxleQuad*)&a.m_kColumn1);
    AxleQuad v0 = _mm_mul_ps(_mm_shuffle_ps(b, b, 0), *(AxleQuad*)&a.m_kColumn0);
    v1 = _mm_add_ps(v1, v0);
    AxleQuad v2 = _mm_mul_ps(_mm_shuffle_ps(b, b, 0xaa), *(AxleQuad*)&a.m_kColumn2);
    v1 = _mm_add_ps(v1, v2);
    *(AxleQuad*)&out = v1;
}

// @fnv 0x00e37d60
// src: GUESS 0x00e37d60 (confidence: low)
void Vehicle::ProcessEntries_00e37d60(void* arg1, GroundBody** arg2, Accumulator* arg3, Accumulator* arg4, AxleParams* arg5)
{
    int i = 0;
    if (reinterpret_cast<AxleDataView*>(m_data)->m_iWheelCount <= 0)
        return;

    Accumulator* out2 = arg4;
    Accumulator* out1 = arg3;
    AxleParams* wheelInfo = arg5;

    do
    {
        normalizeDirection(wheelInfo->m_rayDirWs);
        normalizeDirection(wheelInfo->m_wheelDirWs);

        GroundBody* body = arg2[i];
        wheelInfo->m_contactBody1 = out1;
        wheelInfo->m_contactBody2 = out1;
        if (!body)
        {
            out1->m_fHitFraction = 0.0f;
            out1->m_noHit = 1;
            AxleQuad zero = _mm_setzero_ps();
            *(AxleQuad*)&out1->m_vec30 = zero;
            *(AxleQuad*)&out1->m_vContactPoint = zero;
            *(AxleQuad*)&out1->m_contactNormal = zero;
            *(AxleQuad*)&out1->m_vec40 = zero;
            *(AxleQuad*)&out1->m_rotation.m_kColumn0 = zero;
            *(AxleQuad*)&out1->m_rotation.m_kColumn1 = zero;
            *(AxleQuad*)&out1->m_rotation.m_kColumn2 = zero;
        }
        else if (body->m_pMotionState.m_bFlag == 5)
        {
            prepareFixedGroundBody(body, out1);
        }
        else if (i > 0 && body == arg2[0])
        {
            wheelInfo->m_contactBody1 = arg5[0].m_contactBody1;
            wheelInfo->m_contactBody2 = arg5[0].m_contactBody2;
        }
        else
        {
            GroundMotion* motion = &body->m_pMotionState;
            hkRigidMotionUtilApplyForcesAndBuildAccumulators(arg1, &motion, 1, 0, out1);

            float invMass1 = inverseMass(reinterpret_cast<GroundBody*>(m_pEntity)->m_pMotionState.unkC0);
            float invMass2 = inverseMass(motion->unkC0);
            float maxRatio = reinterpret_cast<AxleDataView*>(m_data)->m_fChassisUnitInertiaYaw;

            if (invMass1 * maxRatio < invMass2)
            {
                float ratio = invMass1 / invMass2;
                ratio *= maxRatio;
                ((VelocityVector*)&out1->m_vec30)->mul4(ratio);
            }

            VelocityVector linVel;
            linVel.setSub4(motion->unk60, motion->unk50);
            linVel.mul4(motion->getInvDeltaTime());
            VelocityVector angVel;
            angVel.setMul4(motion->getInvDeltaTime(), motion->unkA0);

            out2->InitializeFields_00d72030(*out1);
            wheelInfo->m_contactBody2 = out2;

            rotateDirection(out2->m_contactNormal, out1->m_rotation, angVel.q);
            *(AxleQuad*)&out2->m_vContactPoint = linVel.q;
        }

        ++i;
        ++wheelInfo;
        ++out1;
        ++out2;
    } while (i < reinterpret_cast<AxleDataView*>(m_data)->m_iWheelCount);
}

}
