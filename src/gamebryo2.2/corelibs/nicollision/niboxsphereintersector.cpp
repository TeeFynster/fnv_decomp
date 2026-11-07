
// src/gamebryo2.2/corelibs/nicollision/niboxsphereintersector.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nicollision/niboxsphereintersector.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../include/NiPoint3.h"

inline NiPoint3::NiPoint3(float fX, float fY, float fZ)
{
    x = fX;
    y = fY;
    z = fZ;
}
inline NiPoint3 NiPoint3::operator-(const NiPoint3& kRhs) const
{
    return NiPoint3(x - kRhs.x, y - kRhs.y, z - kRhs.z);
}
inline NiPoint3 NiPoint3::operator+(const NiPoint3& kRhs) const
{
    return NiPoint3(x + kRhs.x, y + kRhs.y, z + kRhs.z);
}
inline NiPoint3 operator*(float fScalar, const NiPoint3& pt)
{
    return NiPoint3(fScalar * pt.x, fScalar * pt.y, fScalar * pt.z);
}
inline NiPoint3 NiPoint3::operator*(float fScalar) const
{
    return fScalar * *this;
}
inline NiPoint3 NiPoint3::operator-() const
{
    return NiPoint3(-x, -y, -z);
}
inline float NiPoint3::SqrLength() const
{
    return x * x + y * y + z * z;
}
inline void NiPoint3::Sub(const NiPoint3& a, const NiPoint3& b)
{
    x = a.x - b.x;
    y = a.y - b.y;
    z = a.z - b.z;
}
inline void NiPoint3::Accumulate(NiPoint3 pt)
{
    NiPoint3& dest = *this;
    dest.x += pt.x;
    dest.y += pt.y;
    dest.z += pt.z;
}

struct Blk15
{
    float f00;
    float f01;
    float f02;
    float f03;
    float f04;
    float f05;
    float f06;
    float f07;
    float f08;
    float f09;
    float f0a;
    float f0b;
    float f0c;
    float f0d;
    float f0e;
};

struct FUN_00eb3ca0_cls
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
    Blk15* m_pBlk;
    NiPoint3* m_pVec;
    float m_40;
    float m_44;
    float m_48;
    float m_4c;
    float AccumulateAndEvaluate(const float* a, const float* b, float s);
};

extern float __cdecl GetSqrDistanceToOrientedBox(float* a, float* b, float* c, float* d, float* e);
extern const double DAT_01012070;

// Scales a and b by s, adds them into the block and vector offsets, then evaluates GetSqrDistanceToOrientedBox and returns the result times m_40 minus DAT_01012070.
// @fnv 0x00eb3ca0
float FUN_00eb3ca0_cls::AccumulateAndEvaluate(const float* a, const float* b, float afScale)
{
    float fScaledX = a[0] * afScale;
    Blk15 blkAccum = *(Blk15*)((char*)m_pBlk + 4);
    NiPoint3 vecSum;
    vecSum.x = fScaledX;
    vecSum.y = a[1] * afScale;
    vecSum.z = a[2] * afScale;
    blkAccum.f00 = *(volatile float*)&vecSum.x + blkAccum.f00;
    blkAccum.f01 += vecSum.y;
    blkAccum.f02 += vecSum.z;

    vecSum.x = b[0] * afScale;
    vecSum.y = b[1] * afScale;
    vecSum.z = b[2] * afScale;

    NiPoint3* c = (NiPoint3*)((char*)m_pVec + 4);
    float fSumY = c->y + vecSum.y;
    float fSumZ = c->z + vecSum.z;
    vecSum.x = c->x + vecSum.x;
    vecSum.y = fSumY;
    vecSum.z = fSumZ;

    return (float)(GetSqrDistanceToOrientedBox(&vecSum.x, &blkAccum.f00, &m_44, &m_48, &m_4c) * m_40 - DAT_01012070);
}

static __forceinline NiPoint3 AddInitial(const NiPoint3* aPtr, const NiPoint3* bPtr)
{
    const NiPoint3& a = *aPtr;
    const NiPoint3& b = *bPtr;
    return NiPoint3(a.x + b.x, a.y + b.y, a.z + b.z);
}
struct S_00eb3d90_Box
{
    NiPoint3 m_kCenter;
    NiPoint3 m_akAxes[3];
};
struct S_00eb3d90_Frame
{
    int unk00;
    S_00eb3d90_Box m_kBoundsBox;
};
struct S_00eb3d90_Sphere
{
    int unk00;
    NiPoint3 m_kCenterPosition;
    float m_fSphereRadius;
};
struct S_00eb3d90
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int m_type;
    float m_vScale;
    NiPoint3 m_pos;
    NiPoint3 m_dir;
    S_00eb3d90_Frame* m_frame;
    S_00eb3d90_Sphere* m_pSphere;
    int unk40;
    float m_afOffset[3];
    __forceinline void SetPosition(const NiPoint3& kBase)
    {
        NiPoint3& pos = m_pos;
        pos = kBase;
        for (int i = 0; i < 3; i++)
            pos += m_afOffset[i] * m_frame->m_kBoundsBox.m_akAxes[i];
    }
    __forceinline void SetFromSphere(const NiPoint3& start)
    {
        NiPoint3 kWorldPosition;
        kWorldPosition = start;
        kWorldPosition.Unitize();
        S_00eb3d90_Sphere* pSphere = m_pSphere;
        NiPoint3 kTmp;
        kTmp = m_frame->m_kBoundsBox.m_kCenter - kWorldPosition * (pSphere->m_fSphereRadius * 2.0f);
        kWorldPosition.Sub(kTmp, pSphere->m_kCenterPosition);
        kWorldPosition.Unitize();
        m_pos = pSphere->m_kCenterPosition + kWorldPosition * pSphere->m_fSphereRadius;
        m_dir = -kWorldPosition;
    }
    void NiBoxSphereIntersector_ComputeContactInformation(const NiPoint3& start, const NiPoint3& end);
};
// Computes m_pos and m_dir from start and end based on m_type, using SetFromSphere, SetPosition, or a midpoint of the sphere and box centers.
// @fnv 0x00eb3d90
// src: GAMEBRYO_SRC 0x00eb3d90
void S_00eb3d90::NiBoxSphereIntersector_ComputeContactInformation(const NiPoint3& start, const NiPoint3& end)
{
    if (m_type == 2)
    {
        NiPoint3 kScaledStart = start * m_vScale;
        m_pos = AddInitial(&kScaledStart, &m_frame->m_kBoundsBox.m_kCenter);
        for (int i = 0; i < 3; i++)
            m_pos.Accumulate(m_afOffset[i] * m_frame->m_kBoundsBox.m_akAxes[i]);
        m_dir = m_pSphere->m_kCenterPosition + end * m_vScale - m_pos;
        m_dir.Unitize();
        return;
    }
    float fEndSqrLength = end.SqrLength();
    float fStartSqrLength = start.SqrLength();
    float fDiff = fEndSqrLength - fStartSqrLength;
    if (fDiff < -1e-05f)
    {
        SetFromSphere(start);
        return;
    }
    if (fDiff > 1e-05f)
    {
        SetPosition(m_frame->m_kBoundsBox.m_kCenter);
    }
    else
    {
        const NiPoint3& kBoxCenter = m_frame->m_kBoundsBox.m_kCenter;
        const NiPoint3& kSphereCenter = m_pSphere->m_kCenterPosition;
        m_pos = (kSphereCenter + kBoxCenter) * 0.5f;
    }
    m_dir = m_pSphere->m_kCenterPosition - m_pos;
    m_dir.Unitize();
}
