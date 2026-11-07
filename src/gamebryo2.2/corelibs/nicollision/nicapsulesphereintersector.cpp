
// src/gamebryo2.2/corelibs/nicollision/nicapsulesphereintersector.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nicollision/nicapsulesphereintersector.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiPoint3.h"

inline NiPoint3::NiPoint3(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ)
{}

inline NiPoint3 NiPoint3::operator+(const NiPoint3& kPt) const
{
    return NiPoint3(x + kPt.x, y + kPt.y, z + kPt.z);
}

inline NiPoint3 NiPoint3::operator*(float fScalar) const
{
    return NiPoint3(x * fScalar, y * fScalar, z * fScalar);
}

struct OriginDirectionPair
{
    NiPoint3 m_kStartPoint;
    NiPoint3 m_kLightVector;
};

struct S_00eaea50_Capsule
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    OriginDirectionPair m_kOriginDirectionPair;
};

struct S_00eaea50_Sphere
{
    int unk00;
    NiPoint3 m_kCenter;
};

float __cdecl DistanceSquaredToSegment(const NiPoint3& kPt, const OriginDirectionPair& kSeg, float& fParam);

struct S_00eaea50
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
    S_00eaea50_Capsule* m_pkCapsule;
    S_00eaea50_Sphere* m_pkSphere;
    float m_fValue;
    float m_fParam;

    float NiCapsuleSphereIntersector_Pseudodistance(const NiPoint3& kV0, const NiPoint3& kV1, float fTime);
};

// @fnv 0x00eaea50
// src: GAMEBRYO_LIB 0x00eaea50
float S_00eaea50::NiCapsuleSphereIntersector_Pseudodistance(const NiPoint3& kV0, const NiPoint3& kV1, float fTime)
{
    OriginDirectionPair kSeg = m_pkCapsule->m_kOriginDirectionPair;
    kSeg.m_kStartPoint += kV0 * fTime;
    NiPoint3 kSphereCenter = m_pkSphere->m_kCenter + kV1 * fTime;
    float fDist = DistanceSquaredToSegment(kSphereCenter, kSeg, m_fParam) * m_fValue - 1.0;
    return fDist;
}

struct SegmentMethods : OriginDirectionPair
{
    NiPoint3 NiSegment_GetPoint(float parameter) const;
};
struct CapsuleGeometry : S_00eaea50_Capsule
{
    float m_fBoundRadius;
};
extern const NiPoint3 DAT_011a9484;
inline NiPoint3 Difference(const NiPoint3& a, const NiPoint3& b)
{
    return NiPoint3(a.x - b.x, a.y - b.y, a.z - b.z);
}
struct ContactGeometry
{
    int unk00, unk04, unk08, unk0C, unk10, unk14;
    int m_eRequestType;
    float m_fTime;
    NiPoint3 m_kPoint;
    NiPoint3 m_kPlaneNormal;
    CapsuleGeometry* m_pkCapsule;
    S_00eaea50_Sphere* m_pkSphere;
    float m_fValue;
    float m_fParam;
    void ComputeContactPoint(const NiPoint3& velocity0, const NiPoint3& velocity1);
};
// @fnv 0x00eaeb50
void ContactGeometry::ComputeContactPoint(const NiPoint3& velocity0, const NiPoint3& velocity1)
{
    NiPoint3 kCapsulePoint =
        static_cast<const SegmentMethods&>(m_pkCapsule->m_kOriginDirectionPair).NiSegment_GetPoint(m_fParam);
    const NiPoint3* __restrict pkSphereCenter = &m_pkSphere->m_kCenter;
    NiPoint3 kSpherePoint = *pkSphereCenter;
    if (m_eRequestType == 2)
    {
        kCapsulePoint += velocity0 * m_fTime;
        kSpherePoint += velocity1 * m_fTime;
        m_kPlaneNormal = Difference(kSpherePoint, kCapsulePoint);
        m_kPlaneNormal.Unitize_004a0c10();
        m_kPoint = kCapsulePoint + m_kPlaneNormal * m_pkCapsule->m_fBoundRadius;
    }
    else
    {
        m_kPoint = (kCapsulePoint + kSpherePoint) * 0.5f;
        if (kCapsulePoint != kSpherePoint)
        {
            m_kPlaneNormal = Difference(kSpherePoint, kCapsulePoint);
            m_kPlaneNormal.Unitize_004a0c10();
        }
        else
            m_kPlaneNormal = DAT_011a9484;
    }
}
