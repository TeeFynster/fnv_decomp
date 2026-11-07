// src/havok/physics/vehicle/wheelcollide/raycast/hkpvehicleraycastwheelcollide_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/vehicle/wheelcollide/raycast/hkpvehicleraycastwheelcollide.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/vehicle/wheelcollide/raycast/hkpvehicleraycastwheelcollide.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/wheelcollide/raycast/hkpvehicleraycastwheelcollide.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
// Preserve the unit's original SIMD value type: the SDK union's additional
// integer lanes change VC9 RTM alias analysis and instruction scheduling.
#define _INCLUDED_MM2
// Exe 0x00e42190 FUN_00e42190: retain this LocalM128 view; the CRT type does not preserve this unit.
// VC9 requires the __m128 compatibility typedef for its native SIMD ABI (renamed tags fail C2719).
typedef union __declspec(intrin_type) __declspec(align(16)) {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
} __m128, LocalM128;
extern "C"
{
    LocalM128 _mm_xor_ps(LocalM128, LocalM128);
    LocalM128 _mm_unpackhi_ps(LocalM128, LocalM128);
    LocalM128 _mm_shuffle_ps(LocalM128, LocalM128, unsigned int);
    LocalM128 _mm_min_ps(LocalM128, LocalM128);
    LocalM128 _mm_max_ps(LocalM128, LocalM128);
    LocalM128 _mm_load_ps(const float*);
    void _mm_store_ps(float*, LocalM128);
    LocalM128 _mm_add_ps(LocalM128, LocalM128);
    LocalM128 _mm_add_ss(LocalM128, LocalM128);
    float _mm_cvtss_f32(LocalM128);
    void _mm_store_ss(float*, LocalM128);
    LocalM128 _mm_load_ss(const float*);
    LocalM128 _mm_mul_ps(LocalM128, LocalM128);
    LocalM128 _mm_sub_ps(LocalM128, LocalM128);
}

// This RTM variant owns only the ray-hit processing function below; the main
// unit owns the other wheel-collide functions and their declarations.
#include "../../../../../../include/hkVector4.h"
#include "../../../../../../include/hkContactPoint.h"
#include "../../../../../../include/hkReferencedObject.h"
#include "../../../../../../include/hkpPhantomOverlapListener.h"
#include "../../../../../../include/hkpRejectChassisListener.h"
#include "../../../../../../include/hkpVehicleData.h"
#include "../../../../../../include/hkpVehicleInstance.h"
#include "../../../../../../include/hkpVehicleSuspension.h"
#include "../../../../../../include/hkpVehicleWheelCollide.h"
#include "../../../../../../include/hkpVehicleRayCastWheelCollide.h"
#include "../../../../../../include/hkpWorldRayCastOutput.h"

// The shared suspension header forward-declares its wheel-parameter type.
// Retain this unit's checked 0x30-byte element layout (rest length at +0x20).
class hkpVehicleSuspensionSuspensionWheelParameters
{
public:
    hkVector4 m_vHardPointCs;
    hkVector4 m_vDirectionCs;
    float m_fRestLength;
    unsigned int unk24, unk28, unk2C;
};

__forceinline void hkVector4::setCross(const hkVector4& a, const hkVector4& b)
{
    m_vComponents = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xc9),
                                          _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xd2)),
                               _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xd2),
                                          _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xc9)));
}

struct CenterTrack
{
    hkVector4 center0, center1, orient0, orient1, localCenter;
};
struct MotionStateData
{
    hkVector4 transform0, transform1, transform2, transform3;
    CenterTrack track;
    hkVector4 unk90, unkA0, unkB0;
    __forceinline const CenterTrack& trackData() const
    {
        return track;
    }
};
struct MotionData
{
    hkVector4 unk00;
    MotionStateData state;
    hkVector4 linearVelocity, angularVelocity;
    __forceinline const hkVector4& worldCenter() const
    {
        return state.trackData().center1;
    }
    __forceinline const MotionStateData* stateData() const
    {
        return &state;
    }
};
struct IntegerTriple
{
    LocalM128 unk00, unk10, unk20, unk30, unk40, unk50, unk60, unk70, unk80;
    float friction;
    float unk94, unk98, unk9C;
    LocalM128 unkA0, unkB0, unkC0, unkD0;
    MotionData motion;
};
struct Node50
{
    int p00;
    int p04;
    int p08;
    int p0c;
    signed char c10;
    char p11;
    char p12;
    char p13;
    int p14;
    char c18;
};
__forceinline void CrossP(LocalM128& out, const LocalM128& angular, const LocalM128& offset)
{
    LocalM128 first = _mm_mul_ps(_mm_shuffle_ps(angular, angular, 0xC9), _mm_shuffle_ps(offset, offset, 0xD2));
    LocalM128 second = _mm_mul_ps(_mm_shuffle_ps(angular, angular, 0xD2), _mm_shuffle_ps(offset, offset, 0xC9));
    out = _mm_sub_ps(first, second);
}
__forceinline void PointVelocity(const MotionData& motion, const hkVector4& point, hkVector4& out)
{
    hkVector4 offset;
    offset.setSub4(point, motion.worldCenter());
    const hkVector4& angular = motion.angularVelocity;
    out.setCross(angular, offset);
    out.add4(motion.linearVelocity);
}
// @fnv 0x00e42190
// src: HAVOK_SRC 0x00e42190
void __stdcall hkpVehicleRayCastWheelCollide_getCollisionOutputFromCastResult(hkpVehicleInstance* a, unsigned char idx, hkpWorldRayCastOutput* src, hkpVehicleWheelCollide::WheelCollideResult* dst)
{
    hkpVehicleSuspensionSuspensionWheelParameters* table = a->m_pSuspension->m_kWheelParams.m_data;
    float slotA = table[idx].m_fRestLength;
    hkpVehicleInstance::WheelInfo* E2 = reinterpret_cast<hkpVehicleInstance::WheelInfo*>(a->m_kWheelInfoArray.m_data) + idx;

    LocalM128 srcV = _mm_load_ps((float*)&src->m_vHitNormal.m_vComponents);
    LocalM128 oldV = _mm_load_ps((float*)&dst->m_vContactPoint.m_vSeparatingNormal.m_vComponents);
    LocalM128 t = _mm_unpackhi_ps(srcV, oldV);
    LocalM128 r = _mm_shuffle_ps(srcV, t, 0xC4);
    _mm_store_ps((float*)&dst->m_vContactPoint.m_vSeparatingNormal.m_vComponents, r);
    for (int key = 0; key < 8; ++key)
        (&dst->m_contactShapeKey0)[key] = src->m_uiShapeKeys[key];
    Node50* np = const_cast<Node50*>(static_cast<const Node50*>(src->m_pRootCollidable));
    IntegerTriple* link = (np->c18 == 1) ? (IntegerTriple*)((char*)np + np->c10) : 0;
    dst->m_pUserData = reinterpret_cast<hkpRigidBody*>(link);
    float g = a->m_data->m_kWheelParams.m_data[idx].m_fSphereRadius;
    float slotB = g;
    slotB = (g + slotA) * src->m_fHitFraction;
    float length = slotB - g;
    dst->m_fContactFriction = length;
    LocalM128 bc0 = _mm_load_ss(&slotB);
    LocalM128 bc = _mm_shuffle_ps(bc0, bc0, 0);
    LocalM128 e80 = E2->m_vHardPointWs.m_vComponents;
    LocalM128 p = _mm_mul_ps(bc, e80);
    LocalM128 e50 = E2->m_vContactPointVelocity.m_vComponents;
    p = _mm_add_ps(p, e50);
    _mm_store_ps((float*)&dst->m_vContactPoint.m_vContactPosition.m_vComponents, p);
    dst->m_vContactPoint.m_vSeparatingNormal.w = length;
    LocalM128 v1n = _mm_load_ps((float*)&dst->m_vContactPoint.m_vSeparatingNormal.m_vComponents);
    dst->m_fSuspensionLength = reinterpret_cast<IntegerTriple*>(dst->m_pUserData)->friction;
    LocalM128 e80b = E2->m_vHardPointWs.m_vComponents;
    LocalM128 prod = _mm_mul_ps(v1n, e80b);
    LocalM128 h1 = _mm_shuffle_ps(prod, prod, 0x55);
    h1 = _mm_add_ss(h1, prod);
    LocalM128 h2 = _mm_shuffle_ps(prod, prod, 0xAA);
    h2 = _mm_add_ss(h2, h1);
    float sum;
    _mm_store_ss(&sum, h2);
    if (sum < -a->m_data->m_fChassisUnitInertiaPitch)
    {
        IntegerTriple* W = reinterpret_cast<IntegerTriple*>(a->m_pEntity);
        hkVector4 d0;
        d0.m_vComponents = dst->m_vContactPoint.m_vContactPosition.m_vComponents;
        hkVector4 yVec;
        PointVelocity(W->motion, d0, yVec);
        hkVector4 xVec;
        PointVelocity(link->motion, d0, xVec);
        LocalM128 y0 = yVec.m_vComponents, x6 = xVec.m_vComponents;
        float inv = (float)(-1.0 / sum);
        y0 = _mm_sub_ps(y0, x6);
        y0 = _mm_mul_ps(y0, v1n);
        LocalM128 s1 = _mm_shuffle_ps(y0, y0, 0x55);
        s1 = _mm_add_ss(s1, y0);
        LocalM128 s2 = _mm_shuffle_ps(y0, y0, 0xAA);
        s2 = _mm_add_ss(s2, s1);
        float sum2;
        _mm_store_ss(&sum2, s2);
        dst->m_fValueAtOffset4C = sum2 * inv;
        dst->m_fValueAtOffset50 = inv;
    }
    else
    {
        dst->m_fValueAtOffset4C = 0.0f;
        dst->m_fValueAtOffset50 = 1.0f / a->m_data->m_fChassisUnitInertiaPitch;
    }
}
