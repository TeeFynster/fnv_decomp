// src/havok/physics/vehicle/hkpvehicleinstance_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/vehicle/hkpvehicleinstance_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/vehicle/hkpvehicleinstance_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/vehicle/hkpvehicleinstance.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/vehicle/hkpvehicleinstance.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/hkpvehicleinstance.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "../../../../include/hkArray.h"
#include "../../../../include/hkBool.h"
#include "../../../../include/hkMemoryAllocator.h"
#include "../../../../include/hkReferencedObject.h"
#include "../../../../include/hkStringPtr.h"
#include "../../../../include/hkpEntity.h"
#include "../../../../include/hkpVehicleInstance.h"
#include "../../../../include/hkpWorld.h"

extern "C" __m128 _mm_add_ss(__m128 _A, __m128 _B);
extern "C" __m128 _mm_load_ss(float const* _A);
extern "C" __m128 _mm_rcp_ps(__m128 _A);
extern "C" __m128 _mm_set_ps1(float _A);
extern "C" __m128 _mm_sub_ps(__m128 _A, __m128 _B);
extern "C" __m128 _mm_unpackhi_ps(__m128 _A, __m128 _B);
extern "C" __m128 _mm_xor_ps(__m128 _A, __m128 _B);
#include <math.h>
extern __m128 DAT_010c71e0;
extern __m128 DAT_010c7170;
extern __m128 DAT_010c44d0;
extern __m128 DAT_010c4c00;
extern __m128 DAT_010c4c10;

class S00e384e0_hkQuaternionE38;

class S00e384e0_hkVector4E38
{
  public:
    __m128 m_vComponents;

    __forceinline S00e384e0_hkVector4E38& operator=(const S00e384e0_hkVector4E38& v)
    {
        m_vComponents = v.m_vComponents;
        return *this;
    }

    __forceinline void setAdd4(const S00e384e0_hkVector4E38& a, const S00e384e0_hkVector4E38& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void add4(const S00e384e0_hkVector4E38& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    __forceinline void setMul4(const S00e384e0_hkVector4E38& a, const S00e384e0_hkVector4E38& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void addMul4(const S00e384e0_hkVector4E38& a, const S00e384e0_hkVector4E38& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.m_vComponents, b.m_vComponents));
    }
    __forceinline void addMul4(__m128 s, const S00e384e0_hkVector4E38& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(_mm_shuffle_ps(s, s, 0), b.m_vComponents));
    }
    __forceinline void setNeg4(const S00e384e0_hkVector4E38& a)
    {
        m_vComponents = _mm_xor_ps(a.m_vComponents, DAT_010c44d0);
    }
    __forceinline void setCross(const S00e384e0_hkVector4E38& v1, const S00e384e0_hkVector4E38& v2)
    {
        __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
        __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    __forceinline __m128 dot3(const S00e384e0_hkVector4E38& v) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, v.m_vComponents);
        __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), sum);
    }
    __forceinline void setReciprocal4(const S00e384e0_hkVector4E38& v)
    {
        __m128 r = _mm_rcp_ps(v.m_vComponents);
        __m128 rr = _mm_mul_ps(_mm_mul_ps(r, v.m_vComponents), r);
        m_vComponents = _mm_sub_ps(_mm_add_ps(r, r), rr);
    }
    void SetRotatedDirection(const S00e384e0_hkQuaternionE38& q, const S00e384e0_hkVector4E38& dir);
    void setRotatedInverseDir(const S00e384e0_hkQuaternionE38& q, const S00e384e0_hkVector4E38& dir);
};

class S00e384e0_hkQuaternionE38
{
  public:
    S00e384e0_hkVector4E38 m_vec;

    __declspec(noinline) void SetAxisAngle(const S00e384e0_hkVector4E38& kAxis, float fAngleDifference)
    {
        float fHalf = (float)(fAngleDifference * 0.5);
        float fSin = (float)sin(fHalf);
        m_vec.m_vComponents = _mm_mul_ps(_mm_set_ps1(fSin), kAxis.m_vComponents);
        m_vec.m_vComponents.m128_f32[3] = (float)cos(fHalf);
    }

    __forceinline void SetConjugate(const S00e384e0_hkQuaternionE38& q)
    {
        m_vec.m_vComponents = _mm_xor_ps(DAT_010c4c00, q.m_vec.m_vComponents);
    }
    __declspec(noinline) void SetProduct(const S00e384e0_hkQuaternionE38& q0, const S00e384e0_hkQuaternionE38& q1)
    {
        __m128 a = q0.m_vec.m_vComponents;
        __m128 b = q1.m_vec.m_vComponents;
        __m128 cross = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(b, b, 0xd2), _mm_shuffle_ps(a, a, 0xc9)),
                                  _mm_mul_ps(_mm_shuffle_ps(b, b, 0xc9), _mm_shuffle_ps(a, a, 0xd2)));
        __m128 aw = _mm_shuffle_ps(a, a, 0xff);
        __m128 bw = _mm_shuffle_ps(b, b, 0xff);
        __m128 imag = _mm_add_ps(_mm_mul_ps(bw, a), _mm_add_ps(_mm_mul_ps(aw, b), cross));
        __m128 prod = _mm_mul_ps(b, a);
        __m128 dot = _mm_add_ss(_mm_shuffle_ps(prod, prod, 0xaa), _mm_add_ss(_mm_shuffle_ps(prod, prod, 0x55), prod));
        __m128 real = _mm_sub_ps(prod, _mm_shuffle_ps(dot, dot, 0));
        m_vec.m_vComponents = _mm_shuffle_ps(imag, _mm_unpackhi_ps(imag, real), 0xc4);
    }
};

__forceinline void S00e384e0_hkVector4E38::SetRotatedDirection(const S00e384e0_hkQuaternionE38& quat,
                                                               const S00e384e0_hkVector4E38& direction)
{
    S00e384e0_hkVector4E38 qreal;
    qreal.m_vComponents = _mm_shuffle_ps(quat.m_vec.m_vComponents, quat.m_vec.m_vComponents, 0xff);
    S00e384e0_hkVector4E38 q2minus1;
    q2minus1.setMul4(qreal, qreal);
    q2minus1.m_vComponents = _mm_add_ps(q2minus1.m_vComponents, DAT_010c71e0);
    S00e384e0_hkVector4E38 ret;
    ret.setMul4(direction, q2minus1);
    __m128 imagDotDir = quat.m_vec.dot3(direction);
    ret.addMul4(imagDotDir, quat.m_vec);
    S00e384e0_hkVector4E38 imagCrossDir;
    imagCrossDir.setCross(quat.m_vec, direction);
    ret.addMul4(imagCrossDir, qreal);
    setAdd4(ret, ret);
}

__forceinline void S00e384e0_hkVector4E38::setRotatedInverseDir(const S00e384e0_hkQuaternionE38& quat,
                                                                const S00e384e0_hkVector4E38& direction)
{
    S00e384e0_hkVector4E38 qreal;
    qreal.m_vComponents = _mm_shuffle_ps(quat.m_vec.m_vComponents, quat.m_vec.m_vComponents, 0xff);
    S00e384e0_hkVector4E38 q2minus1;
    q2minus1.setMul4(qreal, qreal);
    q2minus1.m_vComponents = _mm_add_ps(q2minus1.m_vComponents, DAT_010c71e0);
    S00e384e0_hkVector4E38 ret;
    ret.setMul4(direction, q2minus1);
    __m128 imagDotDir = quat.m_vec.dot3(direction);
    ret.addMul4(imagDotDir, quat.m_vec);
    S00e384e0_hkVector4E38 imagCrossDir;
    imagCrossDir.setCross(direction, quat.m_vec);
    ret.addMul4(imagCrossDir, qreal);
    setAdd4(ret, ret);
}

extern const double DAT_01012060;

struct S00e384e0_hkTransformE38
{
    S00e384e0_hkVector4E38 m_kColumn0;
    S00e384e0_hkVector4E38 m_kColumn1;
    S00e384e0_hkVector4E38 m_kColumn2;
    S00e384e0_hkVector4E38 m_vTranslation;
};

__forceinline void setTransformedPosE38(S00e384e0_hkVector4E38& kOut, const S00e384e0_hkTransformE38& kTransform,
                                        const S00e384e0_hkVector4E38& kPos)
{
    __m128 x = _mm_shuffle_ps(kPos.m_vComponents, kPos.m_vComponents, 0x00);
    __m128 y = _mm_shuffle_ps(kPos.m_vComponents, kPos.m_vComponents, 0x55);
    __m128 z = _mm_shuffle_ps(kPos.m_vComponents, kPos.m_vComponents, 0xaa);
    __m128 xy = _mm_add_ps(_mm_mul_ps(y, kTransform.m_kColumn1.m_vComponents),
                           _mm_mul_ps(x, kTransform.m_kColumn0.m_vComponents));
    __m128 zt = _mm_add_ps(_mm_mul_ps(z, kTransform.m_kColumn2.m_vComponents), kTransform.m_vTranslation.m_vComponents);
    kOut.m_vComponents = _mm_add_ps(xy, zt);
}

struct S00e384e0_ChassisE38
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
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    S00e384e0_hkTransformE38 m_kMotionTransform;
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
    S00e384e0_hkQuaternionE38 m_rotation;
};

struct S00e384e0_HardPointE38
{
    S00e384e0_hkVector4E38 m_vContactPosition;
    S00e384e0_hkVector4E38 unk10;
    S00e384e0_hkVector4E38 unk20;
};

struct S00e384e0_VehicleDataE38
{
    int unk00;
    int unk04;
    S00e384e0_HardPointE38* m_kWheelParams;
};

struct S00e384e0_WheelInfoE38
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
    float m_fContactFriction;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    S00e384e0_hkVector4E38 m_suspensionDirection;
    S00e384e0_hkVector4E38 m_spinAxis;
    S00e384e0_hkVector4E38 unka0;
    S00e384e0_hkQuaternionE38 m_steeringOrientation;
    unsigned int unkc0;
    float m_fSpinAngle;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
};

class S00e384e0_WheelCollectorE38
{
  public:
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
    S00e384e0_WheelInfoE38* m_kWheelInfoArray;

    void hkpVehicleInstance_calcCurrentPositionAndRotation(const S00e384e0_ChassisE38* pkChassis, const S00e384e0_VehicleDataE38* pkData, int iWheel,
                      S00e384e0_hkVector4E38& kPosOut, S00e384e0_hkQuaternionE38& kRotOut);
};

// @fnv 0x00e384e0
// src: HAVOK_SRC 0x00e384e0
void S00e384e0_WheelCollectorE38::hkpVehicleInstance_calcCurrentPositionAndRotation(const S00e384e0_ChassisE38* pkChassis,
                                               const S00e384e0_VehicleDataE38* pkData, int iWheel,
                                               S00e384e0_hkVector4E38& kPosOut, S00e384e0_hkQuaternionE38& kRotOut)
{
    const S00e384e0_WheelInfoE38& kWheel = m_kWheelInfoArray[iWheel];

    S00e384e0_hkQuaternionE38 kSpin;
    kSpin.SetAxisAngle(kWheel.m_spinAxis, -kWheel.m_fSpinAngle);
    S00e384e0_hkQuaternionE38 kSteer;
    kSteer.SetProduct(pkChassis->m_rotation, kWheel.m_steeringOrientation);
    kRotOut.SetProduct(kSteer, kSpin);

    float fLen = kWheel.m_fContactFriction;
    float fSuspension = (fLen < DAT_01012060) ? 0.0f : fLen;

    setTransformedPosE38(kPosOut, pkChassis->m_kMotionTransform, pkData->m_kWheelParams[iWheel].m_vContactPosition);
    __m128 s = _mm_load_ss(&fSuspension);
    kPosOut.m_vComponents = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(s, s, 0), kWheel.m_suspensionDirection.m_vComponents),
                                       kPosOut.m_vComponents);
}
